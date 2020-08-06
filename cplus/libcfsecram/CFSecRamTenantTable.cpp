
// Description: C++18 Implementation for an in-memory RAM DbIO for Tenant.

/*
 *	org.msscf.msscf.CFSec
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFSec 2.13 Security Essentials
 *	
 *	Copyright 2020 Mark Stephen Sobkow
 *	
 *		This file is part of MSS Code Factory.
 *	
 *		MSS Code Factory is available under dual commercial license from Mark Stephen
 *		Sobkow, or under the terms of the GNU General Public License, Version 3
 *		or later.
 *	
 *	    MSS Code Factory is free software: you can redistribute it and/or modify
 *	    it under the terms of the GNU General Public License as published by
 *	    the Free Software Foundation, either version 3 of the License, or
 *	    (at your option) any later version.
 *	
 *	    MSS Code Factory is distributed in the hope that it will be useful,
 *	    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	    GNU General Public License for more details.
 *	
 *	    You should have received a copy of the GNU General Public License
 *	    along with MSS Code Factory.  If not, see <https://www.gnu.org/licenses/>.
 *	
 *	Donations to support MSS Code Factory can be made at
 *	https://www.paypal.com/paypalme2/MarkSobkow
 *	
 *	Please contact Mark Stephen Sobkow at msobkow@sasktel.net for commercial licensing.
 *
 *	Manufactured by MSS Code Factory 2.12
 */

#include <cflib/ICFLibPublic.hpp>
#include <cfsec/ICFSecPublic.hpp>
#include <cfsecram/CFSecRamClusterTable.hpp>
#include <cfsecram/CFSecRamHostNodeTable.hpp>
#include <cfsecram/CFSecRamISOCcyTable.hpp>
#include <cfsecram/CFSecRamISOCtryTable.hpp>
#include <cfsecram/CFSecRamISOCtryCcyTable.hpp>
#include <cfsecram/CFSecRamISOCtryLangTable.hpp>
#include <cfsecram/CFSecRamISOLangTable.hpp>
#include <cfsecram/CFSecRamISOTZoneTable.hpp>
#include <cfsecram/CFSecRamSecAppTable.hpp>
#include <cfsecram/CFSecRamSecDeviceTable.hpp>
#include <cfsecram/CFSecRamSecFormTable.hpp>
#include <cfsecram/CFSecRamSecGroupTable.hpp>
#include <cfsecram/CFSecRamSecGroupFormTable.hpp>
#include <cfsecram/CFSecRamSecGrpIncTable.hpp>
#include <cfsecram/CFSecRamSecGrpMembTable.hpp>
#include <cfsecram/CFSecRamSecSessionTable.hpp>
#include <cfsecram/CFSecRamSecUserTable.hpp>
#include <cfsecram/CFSecRamServiceTable.hpp>
#include <cfsecram/CFSecRamServiceTypeTable.hpp>
#include <cfsecram/CFSecRamSysClusterTable.hpp>
#include <cfsecram/CFSecRamTSecGroupTable.hpp>
#include <cfsecram/CFSecRamTSecGrpIncTable.hpp>
#include <cfsecram/CFSecRamTSecGrpMembTable.hpp>
#include <cfsecram/CFSecRamTenantTable.hpp>

using namespace std;

namespace cfsec {

	const std::string CFSecRamTenantTable::CLASS_NAME( "CFSecRamTenantTable" );

	CFSecRamTenantTable::CFSecRamTenantTable( ICFSecSchema* argSchema )
	: cfsec::ICFSecTenantTable()
	{
		schema = argSchema;
		dictByPKey = new std::map<cfsec::CFSecTenantPKey, cfsec::CFSecTenantBuff*>();
		id32Generator = new std::map<CFSecRamTenantId32Gen, CFSecRamTenantId32Gen*>();
		id64Generator = new std::map<CFSecRamTenantId64Gen, CFSecRamTenantId64Gen*>();
		dictByClusterIdx = new std::map<cfsec::CFSecTenantByClusterIdxKey,
			std::map<cfsec::CFSecTenantPKey,
				cfsec::CFSecTenantBuff*>*>();
		dictByUNameIdx = new std::map<cfsec::CFSecTenantByUNameIdxKey, cfsec::CFSecTenantBuff*>();
	}

	CFSecRamTenantTable::~CFSecRamTenantTable() {
		if( dictByClusterIdx != NULL ) {
			for( auto iterDict = dictByClusterIdx->begin(); iterDict != dictByClusterIdx->end(); iterDict ++ ) {
				delete iterDict->second;
				iterDict->second = NULL;
			}
			delete dictByClusterIdx;
			dictByClusterIdx = NULL;
		}
		if( dictByUNameIdx != NULL ) {
			delete dictByUNameIdx;
			dictByUNameIdx = NULL;
		}
		if( id32Generator != NULL ) {
			cfsec::CFSecRamTenantId32Gen* elt;
			std::map<CFSecRamTenantId32Gen,
				CFSecRamTenantId32Gen*>::iterator end = id32Generator->end();
			for( std::map<CFSecRamTenantId32Gen,
					CFSecRamTenantId32Gen*>::iterator cur = id32Generator->begin();
				cur != end;
				cur ++ )
			{
				if( cur->second != NULL ) {
					delete cur->second;
					cur->second = NULL;
				}
			}
			delete id32Generator;
			id32Generator = NULL;
		}
		if( id64Generator != NULL ) {
			cfsec::CFSecRamTenantId64Gen* elt;
			std::map<CFSecRamTenantId64Gen,
				CFSecRamTenantId64Gen*>::iterator end = id64Generator->end();
			for( std::map<CFSecRamTenantId64Gen,
					CFSecRamTenantId64Gen*>::iterator cur = id64Generator->begin();
				cur != end;
				cur ++ )
			{
				if( cur->second != NULL ) {
					delete cur->second;
					cur->second = NULL;
				}
			}
			delete id64Generator;
			id64Generator = NULL;
		}
		if( dictByPKey != NULL ) {
			cfsec::CFSecTenantBuff* elt;
			std::map<cfsec::CFSecTenantPKey,
				cfsec::CFSecTenantBuff*>::iterator end = dictByPKey->end();
			for( std::map<cfsec::CFSecTenantPKey,
					cfsec::CFSecTenantBuff*>::iterator cur = dictByPKey->begin();
				cur != end;
				cur ++ )
			{
				elt = cur->second;
				if( elt != NULL ) {
					delete elt;
					elt = NULL;
					cur->second = NULL;
				}
			}
			delete dictByPKey;
			dictByPKey = NULL;
		}
		schema = NULL;
	}

	int32_t CFSecRamTenantTable::generateNextId32( int64_t argId,
		int16_t argSliceId )
	{
		cfsec::CFSecRamTenantId32Gen* key = new cfsec::CFSecRamTenantId32Gen();
		key->setRequiredId( argId );
		key->setRequiredSliceId( argSliceId );

		cfsec::CFSecRamTenantId32Gen* useGen;
		auto genSearch = id32Generator->find( *key );
		if( genSearch != id32Generator->end() ) {
			useGen = genSearch->second;
			delete key;
			key = NULL;
		}
		else {
			id32Generator->insert( std::map<CFSecRamTenantId32Gen, CFSecRamTenantId32Gen*>::value_type( *key, key ) );
			useGen = key;
			key = NULL;
		}

		int32_t retNext = useGen->getNextId();

		return( retNext );
	}

	int64_t CFSecRamTenantTable::generateNextId64( int64_t argId,
		int16_t argSliceId )
	{
		cfsec::CFSecRamTenantId64Gen* key = new cfsec::CFSecRamTenantId64Gen();
		key->setRequiredId( argId );
		key->setRequiredSliceId( argSliceId );

		cfsec::CFSecRamTenantId64Gen* useGen;
		auto genSearch = id64Generator->find( *key );
		if( genSearch != id64Generator->end() ) {
			useGen = genSearch->second;
			delete key;
			key = NULL;
		}
		else {
			id64Generator->insert( std::map<CFSecRamTenantId64Gen, CFSecRamTenantId64Gen*>::value_type( *key, key ) );
			useGen = key;
			key = NULL;
		}

		int64_t retNext = useGen->getNextId();

		return( retNext );
	}

	int32_t CFSecRamTenantTable::nextTSecGroupIdGen( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecTenantPKey* pkey )
	{
		int32_t retval = nextTSecGroupIdGen( Authorization,
			pkey->getRequiredId() );
		return( retval );
	}

	int32_t CFSecRamTenantTable::nextTSecGroupIdGen( const cfsec::CFSecAuthorization* Authorization,
		int64_t argId )
	{
		int32_t retNext = generateNextId32( argId,
			(int16_t)117 );
		return( retNext );
	}

	int64_t CFSecRamTenantTable::nextTSecGrpIncIdGen( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecTenantPKey* pkey )
	{
		int64_t retval = nextTSecGrpIncIdGen( Authorization,
			pkey->getRequiredId() );
		return( retval );
	}

	int64_t CFSecRamTenantTable::nextTSecGrpIncIdGen( const cfsec::CFSecAuthorization* Authorization,
		int64_t argId )
	{
		int64_t retNext = generateNextId64( argId,
			(int16_t)119 );
		return( retNext );
	}

	int64_t CFSecRamTenantTable::nextTSecGrpMembIdGen( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecTenantPKey* pkey )
	{
		int64_t retval = nextTSecGrpMembIdGen( Authorization,
			pkey->getRequiredId() );
		return( retval );
	}

	int64_t CFSecRamTenantTable::nextTSecGrpMembIdGen( const cfsec::CFSecAuthorization* Authorization,
		int64_t argId )
	{
		int64_t retNext = generateNextId64( argId,
			(int16_t)118 );
		return( retNext );
	}

	cfsec::CFSecTenantBuff* CFSecRamTenantTable::createTenant( const cfsec::CFSecAuthorization* Authorization,
		cfsec::CFSecTenantBuff* Buff )
	{
		static const std::string S_ProcName( "createTenant" );
		cfsec::CFSecTenantPKey pkey;
		pkey.setRequiredId( schema->nextTenantIdGen() );
		Buff->setRequiredId( pkey.getRequiredId() );
		cfsec::CFSecTenantByClusterIdxKey keyClusterIdx;
		keyClusterIdx.setRequiredClusterId( Buff->getRequiredClusterId() );
		cfsec::CFSecTenantByUNameIdxKey keyUNameIdx;
		keyUNameIdx.setRequiredClusterId( Buff->getRequiredClusterId() );
		keyUNameIdx.setRequiredTenantName( Buff->getRequiredTenantName() );
		// Validate unique indexes
		auto searchDictByPKey = dictByPKey->find( pkey );
		if( searchDictByPKey != dictByPKey->end() ) {
			delete Buff;
			std::string Msg( "Duplicate primary key detected " + pkey.toString() );
			throw cflib::CFLibPrimaryKeyNotNewException( CLASS_NAME, S_ProcName, Msg );
		}

		auto searchDictByUNameIdx = dictByUNameIdx->find( keyUNameIdx );
		if( searchDictByUNameIdx != dictByUNameIdx->end() ) {
			std::string Msg( "Duplicate key detected for index TenantUNameIdx " + keyUNameIdx.toString() );
			delete Buff;
			throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
				S_ProcName,
				Msg );
		}

		// Validate foreign keys

		{
			bool allNull = true;
			allNull = false;
			if( ! allNull ) {
				cfsec::CFSecClusterBuff* chk = dynamic_cast<cfsec::CFSecClusterBuff*>( schema->getTableCluster()->readDerivedByIdIdx( Authorization,
						Buff->getRequiredClusterId() ) );
				if( chk == NULL ) {
					delete Buff;
					std::string Msg( "Could not resolve Container relationship TenantCluster to table Cluster" );
					throw cflib::CFLibUnresolvedRelationException( CLASS_NAME,
						S_ProcName,
						Msg );
				}
				delete chk;
				chk = NULL;
			}
		}

		// Proceed with adding the new record
		cfsec::CFSecTenantBuff* buff = Buff;
		buff->setRequiredRevision( 1 );
		dictByPKey->insert( std::map<cfsec::CFSecTenantPKey, cfsec::CFSecTenantBuff*>::value_type( pkey, buff ) );

		std::map<cfsec::CFSecTenantPKey, cfsec::CFSecTenantBuff*>* subdictClusterIdx;
		auto searchDictByClusterIdx = dictByClusterIdx->find( keyClusterIdx );
		if( searchDictByClusterIdx != dictByClusterIdx->end() ) {
			subdictClusterIdx = searchDictByClusterIdx->second;
		}
		else {
			subdictClusterIdx = new std::map<cfsec::CFSecTenantPKey, cfsec::CFSecTenantBuff*>();
			dictByClusterIdx->insert( std::map<cfsec::CFSecTenantByClusterIdxKey,
				std::map<cfsec::CFSecTenantPKey,
					cfsec::CFSecTenantBuff*>*>::value_type( keyClusterIdx, subdictClusterIdx ) );
		}
		subdictClusterIdx->insert( std::map<cfsec::CFSecTenantPKey, cfsec::CFSecTenantBuff*>::value_type( pkey, buff ) );

		dictByUNameIdx->insert( std::map<cfsec::CFSecTenantByUNameIdxKey, cfsec::CFSecTenantBuff*>::value_type( keyUNameIdx, buff ) );

		// The top level code has to clone the final buffer. The one passed in is now part of the persistent storage.
		if( buff->getClassCode() == cfsec::CFSecTenantBuff::CLASS_CODE ) {
			buff = dynamic_cast<cfsec::CFSecTenantBuff*>( buff->clone() );
		}
		return( buff );
	}

	cfsec::CFSecTenantBuff* CFSecRamTenantTable::readDerived( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecTenantPKey* PKey )
	{
		static const std::string S_ProcName( "readDerived" );
		cfsec::CFSecTenantBuff* buff;
		auto searchDictByPKey = dictByPKey->find( *PKey );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfsec::CFSecTenantBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecTenantBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfsec::CFSecTenantBuff* CFSecRamTenantTable::lockDerived( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecTenantPKey* PKey )
	{
		static const std::string S_ProcName( "lockDerived" );
		cfsec::CFSecTenantBuff* buff;
		auto searchDictByPKey = dictByPKey->find( *PKey );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfsec::CFSecTenantBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecTenantBuff*>( buff->clone() );
			}
			else {
				dictByPKey->erase( searchDictByPKey );
				buff = NULL;
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	std::TCFLibOwningVector<cfsec::CFSecTenantBuff*> CFSecRamTenantTable::readAllDerived( const cfsec::CFSecAuthorization* Authorization ) {
		static const std::string S_ProcName( "readAllDerived" );
		std::TCFLibOwningVector<cfsec::CFSecTenantBuff*> retVec;
		std::map<cfsec::CFSecTenantPKey,
			cfsec::CFSecTenantBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecTenantPKey,
			cfsec::CFSecTenantBuff*>::iterator end = dictByPKey->end();
		cfsec::CFSecTenantBuff* clone;
		while( iter != end ) {
			clone = dynamic_cast<cfsec::CFSecTenantBuff*>( iter->second->clone() );
			retVec.push_back( clone );
			iter ++;
		}
		return( retVec );
	}

	std::TCFLibOwningVector<cfsec::CFSecTenantBuff*> CFSecRamTenantTable::readDerivedByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId )
	{
		static const std::string S_ProcName( "readDerivedByClusterIdx" );
		cfsec::CFSecTenantByClusterIdxKey key;
		key.setRequiredClusterId( ClusterId );
		std::TCFLibOwningVector<cfsec::CFSecTenantBuff*> recVec;
		cfsec::CFSecTenantBuff* clone;
		auto searchDictByClusterIdx = dictByClusterIdx->find( key );
		if( searchDictByClusterIdx != dictByClusterIdx->end() ) {
			std::map<cfsec::CFSecTenantPKey,
				 cfsec::CFSecTenantBuff*>* subdictClusterIdx = searchDictByClusterIdx->second;
			std::map<cfsec::CFSecTenantPKey,
				cfsec::CFSecTenantBuff*>::iterator iter = subdictClusterIdx->begin();
			std::map<cfsec::CFSecTenantPKey,
				cfsec::CFSecTenantBuff*>::iterator end = subdictClusterIdx->end();
			while( iter != end ) {
				clone = dynamic_cast<cfsec::CFSecTenantBuff*>( iter->second->clone() );
				recVec.push_back( clone );
				iter ++;
			}
		}
		return( recVec );
	}

	cfsec::CFSecTenantBuff* CFSecRamTenantTable::readDerivedByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const std::string& TenantName )
	{
		static const std::string S_ProcName( "readDerivedByUNameIdx" );
		cfsec::CFSecTenantByUNameIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredTenantName( TenantName );
		cfsec::CFSecTenantBuff* buff;
		auto searchDictByUNameIdx = dictByUNameIdx->find( key );
		if( searchDictByUNameIdx != dictByUNameIdx->end() ) {
			buff = dynamic_cast<cfsec::CFSecTenantBuff*>( searchDictByUNameIdx->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecTenantBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfsec::CFSecTenantBuff* CFSecRamTenantTable::readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t Id )
	{
		static const std::string S_ProcName( "readDerivedByIdIdx" );
		cfsec::CFSecTenantPKey key;
		key.setRequiredId( Id );
		cfsec::CFSecTenantBuff* buff;
		auto searchDictByPKey = dictByPKey->find( key );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfsec::CFSecTenantBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecTenantBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfsec::CFSecTenantBuff* CFSecRamTenantTable::readBuff( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecTenantPKey* PKey )
	{
		static const std::string S_ProcName( "readBuff" );
		cfsec::CFSecTenantBuff* buff = readDerived( Authorization, PKey );
		if( buff != NULL ) {
			if( buff->getClassCode() != cfsec::CFSecTenantBuff::CLASS_CODE ) {
				delete buff;
				buff = NULL;
			}
		}
		return( dynamic_cast<cfsec::CFSecTenantBuff*>( buff ) );
	}

	cfsec::CFSecTenantBuff* CFSecRamTenantTable::lockBuff( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecTenantPKey* PKey )
	{
		static const std::string S_ProcName( "lockBuff" );
		cfsec::CFSecTenantBuff* buff = lockDerived( Authorization, PKey );
		return( dynamic_cast<cfsec::CFSecTenantBuff*>( buff ) );
	}

	std::TCFLibOwningVector<cfsec::CFSecTenantBuff*> CFSecRamTenantTable::readAllBuff( const cfsec::CFSecAuthorization* Authorization )
	{
		static const std::string S_ProcName( "readAllBuff" );
		cfsec::CFSecTenantBuff* buff;
		std::TCFLibOwningVector<cfsec::CFSecTenantBuff*> filteredList;
		std::TCFLibOwningVector<cfsec::CFSecTenantBuff*> buffList = readAllDerived( Authorization );
		std::TCFLibOwningVector<cfsec::CFSecTenantBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfsec::CFSecTenantBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfsec::CFSecTenantBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfsec::CFSecTenantBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	std::TCFLibOwningVector<cfsec::CFSecTenantBuff*> CFSecRamTenantTable::pageAllBuff( const cfsec::CFSecAuthorization* Authorization,
			const int64_t* priorId )
	{
		static const std::string S_ProcName( "pageAllBuff" );
		// MSS TODO WORKING
		throw cflib::CFLibNotImplementedYetException( CLASS_NAME, S_ProcName );
	}

	cfsec::CFSecTenantBuff* CFSecRamTenantTable::readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t Id )
	{
		static const std::string S_ProcName( "readBuffByIdIdx" );
		cfsec::CFSecTenantBuff* buff = readDerivedByIdIdx( Authorization,
			Id );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfsec::CFSecTenantBuff::CLASS_CODE ) {
			return( dynamic_cast<cfsec::CFSecTenantBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	std::TCFLibOwningVector<cfsec::CFSecTenantBuff*> CFSecRamTenantTable::readBuffByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId )
	{
		static const std::string S_ProcName( "readBuffByClusterIdx" );
		cfsec::CFSecTenantBuff* buff;
		std::TCFLibOwningVector<cfsec::CFSecTenantBuff*> filteredList;
		std::TCFLibOwningVector<cfsec::CFSecTenantBuff*> buffList = readDerivedByClusterIdx( Authorization,
			ClusterId );
		std::TCFLibOwningVector<cfsec::CFSecTenantBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfsec::CFSecTenantBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfsec::CFSecTenantBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfsec::CFSecTenantBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	cfsec::CFSecTenantBuff* CFSecRamTenantTable::readBuffByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const std::string& TenantName )
	{
		static const std::string S_ProcName( "readBuffByUNameIdx" );
		cfsec::CFSecTenantBuff* buff = readDerivedByUNameIdx( Authorization,
			ClusterId,
			TenantName );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfsec::CFSecTenantBuff::CLASS_CODE ) {
			return( dynamic_cast<cfsec::CFSecTenantBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	cfsec::CFSecTenantBuff* CFSecRamTenantTable::readBuffByLookupUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId, const std::string& TenantName,
		bool forceRead )
	{
		static const std::string S_ProcName( "readBuffByLookupUNameIdx" );
		cfsec::CFSecTenantBuff* buff = readBuffByUNameIdx( Authorization,
			ClusterId,
			TenantName );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfsec::CFSecTenantBuff::CLASS_CODE ) {
			return( dynamic_cast<cfsec::CFSecTenantBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	cfsec::CFSecTenantBuff* CFSecRamTenantTable::readDerivedByLookupUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId, const std::string& TenantName,
		bool forceRead )
	{
		static const std::string S_ProcName( "readDerivedByLookupUNameIdx" );
		cfsec::CFSecTenantBuff* buff = readDerivedByUNameIdx( Authorization,
			ClusterId,
			TenantName );
		if( buff != NULL ) {
			return( dynamic_cast<cfsec::CFSecTenantBuff*>( buff->clone() ) );
		}
		else {
			return( NULL );
		}
	}

	std::TCFLibOwningVector<cfsec::CFSecTenantBuff*> CFSecRamTenantTable::pageBuffByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t* priorId )
	{
		static const std::string S_ProcName( "pageBuffByClusterIdx" );
		// MSS TODO WORKING
		throw cflib::CFLibNotImplementedYetException( CLASS_NAME, S_ProcName );
	}

	cfsec::CFSecTenantBuff* CFSecRamTenantTable::updateTenant( const cfsec::CFSecAuthorization* Authorization,
		cfsec::CFSecTenantBuff* Buff )
	{
		static const std::string S_ProcName( "updateTenant" );
		cfsec::CFSecTenantPKey pkey;
		pkey.setRequiredId( Buff->getRequiredId() );

		// Search for existing buffer

		auto searchExisting = dictByPKey->find( pkey );
		if( searchExisting == dictByPKey->end() ) {
			delete Buff;
			std::string Msg( "Existing record not found in Tenant for key " + pkey.toString() );
			throw cflib::CFLibStaleCacheDetectedException( CLASS_NAME,
				S_ProcName,
				Msg );
		}

		cfsec::CFSecTenantBuff* existing = searchExisting->second;

		if( existing == NULL ) {
			delete Buff;
			static const std::string S_Existing( "existing" );
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_Existing );
		}

		// Make sure the buffer classes match

		if( existing->getClassCode() != Buff->getClassCode() ) {
			static const std::string S_DoesNotMatchExisting( " does not match existing " );
			std::string Msg( "Buffer class " );
			Msg.append( cflib::CFLib::formatClassCode( Buff->getClassCode() ) );
			Msg.append( S_DoesNotMatchExisting );
			Msg.append( cflib::CFLib::formatClassCode( existing->getClassCode() ) );
			delete Buff;
			throw cflib::CFLibUnsupportedClassException( CLASS_NAME,
				S_ProcName,
				Msg );
		}
		if( existing->getRequiredRevision() != Buff->getRequiredRevision() ) {
			std::string Msg( "Collision detected for Tenant primary key " );
			Msg.append( pkey.toString() );
			Msg.append( " existing revision " );
			Msg.append( std::to_string( existing->getRequiredRevision() ) );
			Msg.append( " argument buffer revision " );
			Msg.append( std::to_string( Buff->getRequiredRevision() ) );
			delete Buff;
			throw cflib::CFLibCollisionDetectedException( CLASS_NAME,
				S_ProcName,
				Msg );
		}
		cfsec::CFSecTenantByClusterIdxKey existingKeyClusterIdx;
		existingKeyClusterIdx.setRequiredClusterId( existing->getRequiredClusterId() );
		cfsec::CFSecTenantByClusterIdxKey newKeyClusterIdx;
		newKeyClusterIdx.setRequiredClusterId( Buff->getRequiredClusterId() );
		cfsec::CFSecTenantByUNameIdxKey existingKeyUNameIdx;
		existingKeyUNameIdx.setRequiredClusterId( existing->getRequiredClusterId() );
		existingKeyUNameIdx.setRequiredTenantName( existing->getRequiredTenantName() );
		cfsec::CFSecTenantByUNameIdxKey newKeyUNameIdx;
		newKeyUNameIdx.setRequiredClusterId( Buff->getRequiredClusterId() );
		newKeyUNameIdx.setRequiredTenantName( Buff->getRequiredTenantName() );
		// Check unique indexes

		if( existingKeyUNameIdx != newKeyUNameIdx ) {
			auto searchDictByUNameIdx = dictByUNameIdx->find( newKeyUNameIdx );
			if( searchDictByUNameIdx != dictByUNameIdx->end() ) {
				std::string Msg( "Duplicate key detected for index TenantUNameIdx " + newKeyUNameIdx.toString() );
				delete Buff;
				throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
					S_ProcName,
					Msg );
			}
		}

		// Validate foreign keys

		{
			bool allNull = true;

			if( allNull ) {
				cfsec::CFSecClusterBuff* chk = dynamic_cast<cfsec::CFSecClusterBuff*>( schema->getTableCluster()->readDerivedByIdIdx( Authorization,
						Buff->getRequiredClusterId() ) );
				if( chk == NULL ) {
					delete Buff;
					std::string Msg( "Could not resolve Container relationship TenantCluster to table Cluster" );
					throw cflib::CFLibUnresolvedRelationException( CLASS_NAME,
						S_ProcName,
						Msg );
				}
				delete chk;
				chk = NULL;
			}
		}

		// Update is valid
		std::map<cfsec::CFSecTenantPKey, cfsec::CFSecTenantBuff*>* subdict;
		auto removalDictByPKey = dictByPKey->find( pkey );
		if( removalDictByPKey != dictByPKey->end() ) {
			dictByPKey->erase( removalDictByPKey );
		}
		// Copy edited buffer to existing persistent buffer

		if( Buff->getClassCode() != cfsec::CFSecTenantBuff::CLASS_CODE ) {
			const static std::string S_IsNotA( " is not a cfsec::CFSecTenantBuff" );
			std::string Msg( "Unsupported buffer class " );
			Msg.append( cflib::CFLib::formatClassCode( Buff->getClassCode() ) );
			Msg.append( S_IsNotA );
			delete Buff;
			throw cflib::CFLibUnsupportedClassException( CLASS_NAME,
				S_ProcName,
				Msg );
		}
		*existing = *Buff;
		existing->setRequiredRevision( existing->getRequiredRevision() + 1 );

		dictByPKey->insert( std::map<cfsec::CFSecTenantPKey, cfsec::CFSecTenantBuff*>::value_type( pkey, existing ) );

		std::map<cfsec::CFSecTenantPKey,
			 cfsec::CFSecTenantBuff*>* subdictClusterIdx;
		auto searchDictByClusterIdx = dictByClusterIdx->find( existingKeyClusterIdx );
		if( searchDictByClusterIdx != dictByClusterIdx->end() ) {
			subdictClusterIdx = searchDictByClusterIdx->second;
			auto searchSubDict = subdictClusterIdx->find( pkey );
			if( searchSubDict != subdictClusterIdx->end() ) {
				subdictClusterIdx->erase( searchSubDict );
			}
			if( subdictClusterIdx->size() <= 0 ) {
				delete subdictClusterIdx;
				dictByClusterIdx->erase( searchDictByClusterIdx );
			}
			subdictClusterIdx = NULL;
		}
		auto searchNewKeyDictByClusterIdx = dictByClusterIdx->find( newKeyClusterIdx );
		if( searchNewKeyDictByClusterIdx != dictByClusterIdx->end() ) {
			subdictClusterIdx = searchNewKeyDictByClusterIdx->second;
		}
		else {
			subdictClusterIdx = new std::map<cfsec::CFSecTenantPKey, cfsec::CFSecTenantBuff*>();
			dictByClusterIdx->insert( std::map<cfsec::CFSecTenantByClusterIdxKey,
				std::map<cfsec::CFSecTenantPKey,
					cfsec::CFSecTenantBuff*>*>::value_type( newKeyClusterIdx, subdictClusterIdx ) );
		}
		subdictClusterIdx->insert( std::map<cfsec::CFSecTenantPKey, cfsec::CFSecTenantBuff*>::value_type( pkey, existing ) );

		auto removalDictByUNameIdx = dictByUNameIdx->find( existingKeyUNameIdx );
		if( removalDictByUNameIdx != dictByUNameIdx->end() ) {
			dictByUNameIdx->erase( removalDictByUNameIdx );
		}
		dictByUNameIdx->insert( std::map<cfsec::CFSecTenantByUNameIdxKey, cfsec::CFSecTenantBuff*>::value_type( newKeyUNameIdx, existing ) );


		// The top level code has to clean up the memory buffer that was passed in, and return a clone
		// of the copy that existing buffer that is attached to the RAM storage.  All other cases
		// return the existing buffer.

		cfsec::CFSecTenantBuff* buff;
		if( existing->getClassCode() == cfsec::CFSecTenantBuff::CLASS_CODE ) {
			delete Buff;
			Buff = NULL;
			buff = dynamic_cast<cfsec::CFSecTenantBuff*>( existing->clone() );
		}
		else {
			buff = existing;
		}
		return( buff );
	}

	void CFSecRamTenantTable::deleteTenant( const cfsec::CFSecAuthorization* Authorization,
		cfsec::CFSecTenantBuff* Buff )
	{
		static const std::string S_ProcName( "deleteTenant" );
		static const std::string S_Prev( "prev" );
		classcode_t classCode;
		cfsec::CFSecTenantPKey pkey;
		pkey.setRequiredId( Buff->getRequiredId() );
		auto searchExisting = dictByPKey->find( pkey );
		if( searchExisting == dictByPKey->end() ) {
			return;
		}
		cfsec::CFSecTenantBuff* existing = searchExisting->second;
		cfsec::CFSecTSecGroupBuff* buffDelIncludedByGroup;
		std::TCFLibOwningVector<cfsec::CFSecTSecGroupBuff*> arrDelIncludedByGroup = schema->getTableTSecGroup()->readDerivedByTenantIdx( Authorization,
			existing->getRequiredId() );
		std::TCFLibOwningVector<cfsec::CFSecTSecGroupBuff*>::iterator iterArrDelIncludedByGroup = arrDelIncludedByGroup.begin();
		std::TCFLibOwningVector<cfsec::CFSecTSecGroupBuff*>::iterator endArrDelIncludedByGroup = arrDelIncludedByGroup.end();
		while( iterArrDelIncludedByGroup != endArrDelIncludedByGroup ) {
			buffDelIncludedByGroup = *iterArrDelIncludedByGroup;
			iterArrDelIncludedByGroup ++;
			schema->getTableTSecGrpInc()->deleteTSecGrpIncByIncludeIdx( Authorization,
				buffDelIncludedByGroup->getRequiredTenantId(),
				buffDelIncludedByGroup->getRequiredTSecGroupId() );
		}
		cfsec::CFSecTSecGroupBuff* buffDelGrpMembs;
		std::TCFLibOwningVector<cfsec::CFSecTSecGroupBuff*> arrDelGrpMembs = schema->getTableTSecGroup()->readDerivedByTenantIdx( Authorization,
			existing->getRequiredId() );
		std::TCFLibOwningVector<cfsec::CFSecTSecGroupBuff*>::iterator iterArrDelGrpMembs = arrDelGrpMembs.begin();
		std::TCFLibOwningVector<cfsec::CFSecTSecGroupBuff*>::iterator endArrDelGrpMembs = arrDelGrpMembs.end();
		while( iterArrDelGrpMembs != endArrDelGrpMembs ) {
			buffDelGrpMembs = *iterArrDelGrpMembs;
			iterArrDelGrpMembs ++;
			schema->getTableTSecGrpMemb()->deleteTSecGrpMembByGroupIdx( Authorization,
				buffDelGrpMembs->getRequiredTenantId(),
				buffDelGrpMembs->getRequiredTSecGroupId() );
		}
		cfsec::CFSecTSecGroupBuff* buffDelGrpIncs;
		std::TCFLibOwningVector<cfsec::CFSecTSecGroupBuff*> arrDelGrpIncs = schema->getTableTSecGroup()->readDerivedByTenantIdx( Authorization,
			existing->getRequiredId() );
		std::TCFLibOwningVector<cfsec::CFSecTSecGroupBuff*>::iterator iterArrDelGrpIncs = arrDelGrpIncs.begin();
		std::TCFLibOwningVector<cfsec::CFSecTSecGroupBuff*>::iterator endArrDelGrpIncs = arrDelGrpIncs.end();
		while( iterArrDelGrpIncs != endArrDelGrpIncs ) {
			buffDelGrpIncs = *iterArrDelGrpIncs;
			iterArrDelGrpIncs ++;
			schema->getTableTSecGrpInc()->deleteTSecGrpIncByGroupIdx( Authorization,
				buffDelGrpIncs->getRequiredTenantId(),
				buffDelGrpIncs->getRequiredTSecGroupId() );
		}
		schema->getTableTSecGroup()->deleteTSecGroupByTenantIdx( Authorization,
			existing->getRequiredId() );
		cfsec::CFSecTenantByClusterIdxKey keyClusterIdx;
		keyClusterIdx.setRequiredClusterId( existing->getRequiredClusterId() );
		cfsec::CFSecTenantByUNameIdxKey keyUNameIdx;
		keyUNameIdx.setRequiredClusterId( existing->getRequiredClusterId() );
		keyUNameIdx.setRequiredTenantName( existing->getRequiredTenantName() );
		// Validate reverse foreign keys

		// Delete is valid
		std::map<cfsec::CFSecTenantPKey, cfsec::CFSecTenantBuff*>* subdict;

		auto searchDictByPKey = dictByPKey->find( pkey );
		if( searchDictByPKey != dictByPKey->end() ) {
			dictByPKey->erase( searchDictByPKey );
		}

		auto searchDictByClusterIdx = dictByClusterIdx->find( keyClusterIdx );
		if( searchDictByClusterIdx != dictByClusterIdx->end() ) {
			std::map<cfsec::CFSecTenantPKey,
				 cfsec::CFSecTenantBuff*>* subdictClusterIdx = searchDictByClusterIdx->second;
			auto searchSubDict = subdictClusterIdx->find( pkey );
			if( searchSubDict != subdictClusterIdx->end() ) {
				subdictClusterIdx->erase( searchSubDict );
			}
			subdictClusterIdx = NULL;
		}

		auto searchDictByUNameIdx = dictByUNameIdx->find( keyUNameIdx );
		if( searchDictByUNameIdx != dictByUNameIdx->end() ) {
			dictByUNameIdx->erase( searchDictByUNameIdx );
		}

		if( existing != NULL ) {
			delete existing;
			existing = NULL;
		}
	}

	void CFSecRamTenantTable::deleteTenantByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argId )
	{
		cfsec::CFSecTenantPKey key;
		key.setRequiredId( argId );
		deleteTenantByIdIdx( Authorization, &key );
	}

	void CFSecRamTenantTable::deleteTenantByIdIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecTenantPKey* argKey )
	{
		bool anyNotNull = false;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		cfsec::CFSecTenantBuff* cur = NULL;
		cfsec::CFSecTenantBuff* rereadCur = NULL;
		std::TCFLibOwningVector<cfsec::CFSecTenantBuff*> matchSet;
		std::map<cfsec::CFSecTenantPKey,
			cfsec::CFSecTenantBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecTenantPKey,
			cfsec::CFSecTenantBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecTenantBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecTenantBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecTenantBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecTenantBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableTenant()->readDerivedByIdIdx( Authorization,
				cur->getRequiredId() );
			rereadCur = cur;
			deleteTenant( Authorization, cur );
			if( rereadCur != NULL ) {
				delete rereadCur;
				rereadCur = NULL;
			}
		}
	}

	void CFSecRamTenantTable::deleteTenantByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId )
	{
		cfsec::CFSecTenantByClusterIdxKey key;
		key.setRequiredClusterId( argClusterId );
		deleteTenantByClusterIdx( Authorization, &key );
	}

	void CFSecRamTenantTable::deleteTenantByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecTenantByClusterIdxKey* argKey )
	{
		cfsec::CFSecTenantBuff* cur = NULL;
		cfsec::CFSecTenantBuff* rereadCur = NULL;
		bool anyNotNull = false;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfsec::CFSecTenantBuff*> matchSet;
		std::map<cfsec::CFSecTenantPKey,
			cfsec::CFSecTenantBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecTenantPKey,
			cfsec::CFSecTenantBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecTenantBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecTenantBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecTenantBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecTenantBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableTenant()->readDerivedByIdIdx( Authorization,
				cur->getRequiredId() );
			rereadCur = cur;
			deleteTenant( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFSecRamTenantTable::deleteTenantByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const std::string& argTenantName )
	{
		cfsec::CFSecTenantByUNameIdxKey key;
		key.setRequiredClusterId( argClusterId );
		key.setRequiredTenantName( argTenantName );
		deleteTenantByUNameIdx( Authorization, &key );
	}

	void CFSecRamTenantTable::deleteTenantByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecTenantByUNameIdxKey* argKey )
	{
		cfsec::CFSecTenantBuff* cur = NULL;
		cfsec::CFSecTenantBuff* rereadCur = NULL;
		bool anyNotNull = false;
		anyNotNull = true;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfsec::CFSecTenantBuff*> matchSet;
		std::map<cfsec::CFSecTenantPKey,
			cfsec::CFSecTenantBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecTenantPKey,
			cfsec::CFSecTenantBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecTenantBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecTenantBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecTenantBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecTenantBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableTenant()->readDerivedByIdIdx( Authorization,
				cur->getRequiredId() );
			rereadCur = cur;
			deleteTenant( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFSecRamTenantTable::releasePreparedStatements() {
	}

}
