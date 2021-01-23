
// Description: C++18 Implementation for an in-memory RAM DbIO for TSecGroup.

/*
 *	org.msscf.msscf.CFSec
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFSec 2.13 Security Essentials
 *	
 *	Copyright 2020-2021 Mark Stephen Sobkow
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
 *	Please contact Mark Stephen Sobkow at mark.sobkow@gmail.com for commercial licensing.
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

	const std::string CFSecRamTSecGroupTable::CLASS_NAME( "CFSecRamTSecGroupTable" );

	CFSecRamTSecGroupTable::CFSecRamTSecGroupTable( ICFSecSchema* argSchema )
	: cfsec::ICFSecTSecGroupTable()
	{
		schema = argSchema;
		dictByPKey = new std::map<cfsec::CFSecTSecGroupPKey, cfsec::CFSecTSecGroupBuff*>();
		dictByTenantIdx = new std::map<cfsec::CFSecTSecGroupByTenantIdxKey,
			std::map<cfsec::CFSecTSecGroupPKey,
				cfsec::CFSecTSecGroupBuff*>*>();
		dictByTenantVisIdx = new std::map<cfsec::CFSecTSecGroupByTenantVisIdxKey,
			std::map<cfsec::CFSecTSecGroupPKey,
				cfsec::CFSecTSecGroupBuff*>*>();
		dictByUNameIdx = new std::map<cfsec::CFSecTSecGroupByUNameIdxKey, cfsec::CFSecTSecGroupBuff*>();
	}

	CFSecRamTSecGroupTable::~CFSecRamTSecGroupTable() {
		if( dictByTenantIdx != NULL ) {
			for( auto iterDict = dictByTenantIdx->begin(); iterDict != dictByTenantIdx->end(); iterDict ++ ) {
				delete iterDict->second;
				iterDict->second = NULL;
			}
			delete dictByTenantIdx;
			dictByTenantIdx = NULL;
		}
		if( dictByTenantVisIdx != NULL ) {
			for( auto iterDict = dictByTenantVisIdx->begin(); iterDict != dictByTenantVisIdx->end(); iterDict ++ ) {
				delete iterDict->second;
				iterDict->second = NULL;
			}
			delete dictByTenantVisIdx;
			dictByTenantVisIdx = NULL;
		}
		if( dictByUNameIdx != NULL ) {
			delete dictByUNameIdx;
			dictByUNameIdx = NULL;
		}
		if( dictByPKey != NULL ) {
			cfsec::CFSecTSecGroupBuff* elt;
			std::map<cfsec::CFSecTSecGroupPKey,
				cfsec::CFSecTSecGroupBuff*>::iterator end = dictByPKey->end();
			for( std::map<cfsec::CFSecTSecGroupPKey,
					cfsec::CFSecTSecGroupBuff*>::iterator cur = dictByPKey->begin();
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

	cfsec::CFSecTSecGroupBuff* CFSecRamTSecGroupTable::createTSecGroup( const cfsec::CFSecAuthorization* Authorization,
		cfsec::CFSecTSecGroupBuff* Buff )
	{
		static const std::string S_ProcName( "createTSecGroup" );
		cfsec::CFSecTSecGroupPKey pkey;
		pkey.setRequiredTenantId( Buff->getRequiredTenantId() );
		pkey.setRequiredTSecGroupId( dynamic_cast<CFSecRamTenantTable*>( schema->getTableTenant() )->nextTSecGroupIdGen( Authorization,
			Buff->getRequiredTenantId() ) );
		Buff->setRequiredTenantId( pkey.getRequiredTenantId() );
		Buff->setRequiredTSecGroupId( pkey.getRequiredTSecGroupId() );
		cfsec::CFSecTSecGroupByTenantIdxKey keyTenantIdx;
		keyTenantIdx.setRequiredTenantId( Buff->getRequiredTenantId() );
		cfsec::CFSecTSecGroupByTenantVisIdxKey keyTenantVisIdx;
		keyTenantVisIdx.setRequiredTenantId( Buff->getRequiredTenantId() );
		keyTenantVisIdx.setRequiredIsVisible( Buff->getRequiredIsVisible() );
		cfsec::CFSecTSecGroupByUNameIdxKey keyUNameIdx;
		keyUNameIdx.setRequiredTenantId( Buff->getRequiredTenantId() );
		keyUNameIdx.setRequiredName( Buff->getRequiredName() );
		// Validate unique indexes
		auto searchDictByPKey = dictByPKey->find( pkey );
		if( searchDictByPKey != dictByPKey->end() ) {
			delete Buff;
			std::string Msg( "Duplicate primary key detected " + pkey.toString() );
			throw cflib::CFLibPrimaryKeyNotNewException( CLASS_NAME, S_ProcName, Msg );
		}

		auto searchDictByUNameIdx = dictByUNameIdx->find( keyUNameIdx );
		if( searchDictByUNameIdx != dictByUNameIdx->end() ) {
			std::string Msg( "Duplicate key detected for index TSecGroupUNameIdx " + keyUNameIdx.toString() );
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
				cfsec::CFSecTenantBuff* chk = dynamic_cast<cfsec::CFSecTenantBuff*>( schema->getTableTenant()->readDerivedByIdIdx( Authorization,
						Buff->getRequiredTenantId() ) );
				if( chk == NULL ) {
					delete Buff;
					std::string Msg( "Could not resolve Container relationship TSecGroupTenant to table Tenant" );
					throw cflib::CFLibUnresolvedRelationException( CLASS_NAME,
						S_ProcName,
						Msg );
				}
				delete chk;
				chk = NULL;
			}
		}

		// Proceed with adding the new record
		cfsec::CFSecTSecGroupBuff* buff = Buff;
		buff->setRequiredRevision( 1 );
		dictByPKey->insert( std::map<cfsec::CFSecTSecGroupPKey, cfsec::CFSecTSecGroupBuff*>::value_type( pkey, buff ) );

		std::map<cfsec::CFSecTSecGroupPKey, cfsec::CFSecTSecGroupBuff*>* subdictTenantIdx;
		auto searchDictByTenantIdx = dictByTenantIdx->find( keyTenantIdx );
		if( searchDictByTenantIdx != dictByTenantIdx->end() ) {
			subdictTenantIdx = searchDictByTenantIdx->second;
		}
		else {
			subdictTenantIdx = new std::map<cfsec::CFSecTSecGroupPKey, cfsec::CFSecTSecGroupBuff*>();
			dictByTenantIdx->insert( std::map<cfsec::CFSecTSecGroupByTenantIdxKey,
				std::map<cfsec::CFSecTSecGroupPKey,
					cfsec::CFSecTSecGroupBuff*>*>::value_type( keyTenantIdx, subdictTenantIdx ) );
		}
		subdictTenantIdx->insert( std::map<cfsec::CFSecTSecGroupPKey, cfsec::CFSecTSecGroupBuff*>::value_type( pkey, buff ) );

		std::map<cfsec::CFSecTSecGroupPKey, cfsec::CFSecTSecGroupBuff*>* subdictTenantVisIdx;
		auto searchDictByTenantVisIdx = dictByTenantVisIdx->find( keyTenantVisIdx );
		if( searchDictByTenantVisIdx != dictByTenantVisIdx->end() ) {
			subdictTenantVisIdx = searchDictByTenantVisIdx->second;
		}
		else {
			subdictTenantVisIdx = new std::map<cfsec::CFSecTSecGroupPKey, cfsec::CFSecTSecGroupBuff*>();
			dictByTenantVisIdx->insert( std::map<cfsec::CFSecTSecGroupByTenantVisIdxKey,
				std::map<cfsec::CFSecTSecGroupPKey,
					cfsec::CFSecTSecGroupBuff*>*>::value_type( keyTenantVisIdx, subdictTenantVisIdx ) );
		}
		subdictTenantVisIdx->insert( std::map<cfsec::CFSecTSecGroupPKey, cfsec::CFSecTSecGroupBuff*>::value_type( pkey, buff ) );

		dictByUNameIdx->insert( std::map<cfsec::CFSecTSecGroupByUNameIdxKey, cfsec::CFSecTSecGroupBuff*>::value_type( keyUNameIdx, buff ) );

		// The top level code has to clone the final buffer. The one passed in is now part of the persistent storage.
		if( buff->getClassCode() == cfsec::CFSecTSecGroupBuff::CLASS_CODE ) {
			buff = dynamic_cast<cfsec::CFSecTSecGroupBuff*>( buff->clone() );
		}
		return( buff );
	}

	cfsec::CFSecTSecGroupBuff* CFSecRamTSecGroupTable::readDerived( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecTSecGroupPKey* PKey )
	{
		static const std::string S_ProcName( "readDerived" );
		cfsec::CFSecTSecGroupBuff* buff;
		auto searchDictByPKey = dictByPKey->find( *PKey );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfsec::CFSecTSecGroupBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecTSecGroupBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfsec::CFSecTSecGroupBuff* CFSecRamTSecGroupTable::lockDerived( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecTSecGroupPKey* PKey )
	{
		static const std::string S_ProcName( "lockDerived" );
		cfsec::CFSecTSecGroupBuff* buff;
		auto searchDictByPKey = dictByPKey->find( *PKey );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfsec::CFSecTSecGroupBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecTSecGroupBuff*>( buff->clone() );
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

	std::TCFLibOwningVector<cfsec::CFSecTSecGroupBuff*> CFSecRamTSecGroupTable::readAllDerived( const cfsec::CFSecAuthorization* Authorization ) {
		static const std::string S_ProcName( "readAllDerived" );
		std::TCFLibOwningVector<cfsec::CFSecTSecGroupBuff*> retVec;
		std::map<cfsec::CFSecTSecGroupPKey,
			cfsec::CFSecTSecGroupBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecTSecGroupPKey,
			cfsec::CFSecTSecGroupBuff*>::iterator end = dictByPKey->end();
		cfsec::CFSecTSecGroupBuff* clone;
		while( iter != end ) {
			clone = dynamic_cast<cfsec::CFSecTSecGroupBuff*>( iter->second->clone() );
			retVec.push_back( clone );
			iter ++;
		}
		return( retVec );
	}

	std::TCFLibOwningVector<cfsec::CFSecTSecGroupBuff*> CFSecRamTSecGroupTable::readDerivedByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId )
	{
		static const std::string S_ProcName( "readDerivedByTenantIdx" );
		cfsec::CFSecTSecGroupByTenantIdxKey key;
		key.setRequiredTenantId( TenantId );
		std::TCFLibOwningVector<cfsec::CFSecTSecGroupBuff*> recVec;
		cfsec::CFSecTSecGroupBuff* clone;
		auto searchDictByTenantIdx = dictByTenantIdx->find( key );
		if( searchDictByTenantIdx != dictByTenantIdx->end() ) {
			std::map<cfsec::CFSecTSecGroupPKey,
				 cfsec::CFSecTSecGroupBuff*>* subdictTenantIdx = searchDictByTenantIdx->second;
			std::map<cfsec::CFSecTSecGroupPKey,
				cfsec::CFSecTSecGroupBuff*>::iterator iter = subdictTenantIdx->begin();
			std::map<cfsec::CFSecTSecGroupPKey,
				cfsec::CFSecTSecGroupBuff*>::iterator end = subdictTenantIdx->end();
			while( iter != end ) {
				clone = dynamic_cast<cfsec::CFSecTSecGroupBuff*>( iter->second->clone() );
				recVec.push_back( clone );
				iter ++;
			}
		}
		return( recVec );
	}

	std::TCFLibOwningVector<cfsec::CFSecTSecGroupBuff*> CFSecRamTSecGroupTable::readDerivedByTenantVisIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const bool IsVisible )
	{
		static const std::string S_ProcName( "readDerivedByTenantVisIdx" );
		cfsec::CFSecTSecGroupByTenantVisIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredIsVisible( IsVisible );
		std::TCFLibOwningVector<cfsec::CFSecTSecGroupBuff*> recVec;
		cfsec::CFSecTSecGroupBuff* clone;
		auto searchDictByTenantVisIdx = dictByTenantVisIdx->find( key );
		if( searchDictByTenantVisIdx != dictByTenantVisIdx->end() ) {
			std::map<cfsec::CFSecTSecGroupPKey,
				 cfsec::CFSecTSecGroupBuff*>* subdictTenantVisIdx = searchDictByTenantVisIdx->second;
			std::map<cfsec::CFSecTSecGroupPKey,
				cfsec::CFSecTSecGroupBuff*>::iterator iter = subdictTenantVisIdx->begin();
			std::map<cfsec::CFSecTSecGroupPKey,
				cfsec::CFSecTSecGroupBuff*>::iterator end = subdictTenantVisIdx->end();
			while( iter != end ) {
				clone = dynamic_cast<cfsec::CFSecTSecGroupBuff*>( iter->second->clone() );
				recVec.push_back( clone );
				iter ++;
			}
		}
		return( recVec );
	}

	cfsec::CFSecTSecGroupBuff* CFSecRamTSecGroupTable::readDerivedByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const std::string& Name )
	{
		static const std::string S_ProcName( "readDerivedByUNameIdx" );
		cfsec::CFSecTSecGroupByUNameIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredName( Name );
		cfsec::CFSecTSecGroupBuff* buff;
		auto searchDictByUNameIdx = dictByUNameIdx->find( key );
		if( searchDictByUNameIdx != dictByUNameIdx->end() ) {
			buff = dynamic_cast<cfsec::CFSecTSecGroupBuff*>( searchDictByUNameIdx->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecTSecGroupBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfsec::CFSecTSecGroupBuff* CFSecRamTSecGroupTable::readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int32_t TSecGroupId )
	{
		static const std::string S_ProcName( "readDerivedByIdIdx" );
		cfsec::CFSecTSecGroupPKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredTSecGroupId( TSecGroupId );
		cfsec::CFSecTSecGroupBuff* buff;
		auto searchDictByPKey = dictByPKey->find( key );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfsec::CFSecTSecGroupBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecTSecGroupBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfsec::CFSecTSecGroupBuff* CFSecRamTSecGroupTable::readBuff( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecTSecGroupPKey* PKey )
	{
		static const std::string S_ProcName( "readBuff" );
		cfsec::CFSecTSecGroupBuff* buff = readDerived( Authorization, PKey );
		if( buff != NULL ) {
			if( buff->getClassCode() != cfsec::CFSecTSecGroupBuff::CLASS_CODE ) {
				delete buff;
				buff = NULL;
			}
		}
		return( dynamic_cast<cfsec::CFSecTSecGroupBuff*>( buff ) );
	}

	cfsec::CFSecTSecGroupBuff* CFSecRamTSecGroupTable::lockBuff( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecTSecGroupPKey* PKey )
	{
		static const std::string S_ProcName( "lockBuff" );
		cfsec::CFSecTSecGroupBuff* buff = lockDerived( Authorization, PKey );
		return( dynamic_cast<cfsec::CFSecTSecGroupBuff*>( buff ) );
	}

	std::TCFLibOwningVector<cfsec::CFSecTSecGroupBuff*> CFSecRamTSecGroupTable::readAllBuff( const cfsec::CFSecAuthorization* Authorization )
	{
		static const std::string S_ProcName( "readAllBuff" );
		cfsec::CFSecTSecGroupBuff* buff;
		std::TCFLibOwningVector<cfsec::CFSecTSecGroupBuff*> filteredList;
		std::TCFLibOwningVector<cfsec::CFSecTSecGroupBuff*> buffList = readAllDerived( Authorization );
		std::TCFLibOwningVector<cfsec::CFSecTSecGroupBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfsec::CFSecTSecGroupBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfsec::CFSecTSecGroupBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfsec::CFSecTSecGroupBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	cfsec::CFSecTSecGroupBuff* CFSecRamTSecGroupTable::readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int32_t TSecGroupId )
	{
		static const std::string S_ProcName( "readBuffByIdIdx" );
		cfsec::CFSecTSecGroupBuff* buff = readDerivedByIdIdx( Authorization,
			TenantId,
			TSecGroupId );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfsec::CFSecTSecGroupBuff::CLASS_CODE ) {
			return( dynamic_cast<cfsec::CFSecTSecGroupBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	std::TCFLibOwningVector<cfsec::CFSecTSecGroupBuff*> CFSecRamTSecGroupTable::readBuffByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId )
	{
		static const std::string S_ProcName( "readBuffByTenantIdx" );
		cfsec::CFSecTSecGroupBuff* buff;
		std::TCFLibOwningVector<cfsec::CFSecTSecGroupBuff*> filteredList;
		std::TCFLibOwningVector<cfsec::CFSecTSecGroupBuff*> buffList = readDerivedByTenantIdx( Authorization,
			TenantId );
		std::TCFLibOwningVector<cfsec::CFSecTSecGroupBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfsec::CFSecTSecGroupBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfsec::CFSecTSecGroupBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfsec::CFSecTSecGroupBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	std::TCFLibOwningVector<cfsec::CFSecTSecGroupBuff*> CFSecRamTSecGroupTable::readBuffByTenantVisIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const bool IsVisible )
	{
		static const std::string S_ProcName( "readBuffByTenantVisIdx" );
		cfsec::CFSecTSecGroupBuff* buff;
		std::TCFLibOwningVector<cfsec::CFSecTSecGroupBuff*> filteredList;
		std::TCFLibOwningVector<cfsec::CFSecTSecGroupBuff*> buffList = readDerivedByTenantVisIdx( Authorization,
			TenantId,
			IsVisible );
		std::TCFLibOwningVector<cfsec::CFSecTSecGroupBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfsec::CFSecTSecGroupBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfsec::CFSecTSecGroupBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfsec::CFSecTSecGroupBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	cfsec::CFSecTSecGroupBuff* CFSecRamTSecGroupTable::readBuffByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const std::string& Name )
	{
		static const std::string S_ProcName( "readBuffByUNameIdx" );
		cfsec::CFSecTSecGroupBuff* buff = readDerivedByUNameIdx( Authorization,
			TenantId,
			Name );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfsec::CFSecTSecGroupBuff::CLASS_CODE ) {
			return( dynamic_cast<cfsec::CFSecTSecGroupBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	cfsec::CFSecTSecGroupBuff* CFSecRamTSecGroupTable::readBuffByLookupUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId, const std::string& Name,
		bool forceRead )
	{
		static const std::string S_ProcName( "readBuffByLookupUNameIdx" );
		cfsec::CFSecTSecGroupBuff* buff = readBuffByUNameIdx( Authorization,
			TenantId,
			Name );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfsec::CFSecTSecGroupBuff::CLASS_CODE ) {
			return( dynamic_cast<cfsec::CFSecTSecGroupBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	cfsec::CFSecTSecGroupBuff* CFSecRamTSecGroupTable::readDerivedByLookupUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId, const std::string& Name,
		bool forceRead )
	{
		static const std::string S_ProcName( "readDerivedByLookupUNameIdx" );
		cfsec::CFSecTSecGroupBuff* buff = readDerivedByUNameIdx( Authorization,
			TenantId,
			Name );
		if( buff != NULL ) {
			return( dynamic_cast<cfsec::CFSecTSecGroupBuff*>( buff->clone() ) );
		}
		else {
			return( NULL );
		}
	}

	cfsec::CFSecTSecGroupBuff* CFSecRamTSecGroupTable::updateTSecGroup( const cfsec::CFSecAuthorization* Authorization,
		cfsec::CFSecTSecGroupBuff* Buff )
	{
		static const std::string S_ProcName( "updateTSecGroup" );
		cfsec::CFSecTSecGroupPKey pkey;
		pkey.setRequiredTenantId( Buff->getRequiredTenantId() );
		pkey.setRequiredTSecGroupId( Buff->getRequiredTSecGroupId() );

		// Search for existing buffer

		auto searchExisting = dictByPKey->find( pkey );
		if( searchExisting == dictByPKey->end() ) {
			delete Buff;
			std::string Msg( "Existing record not found in TSecGroup for key " + pkey.toString() );
			throw cflib::CFLibStaleCacheDetectedException( CLASS_NAME,
				S_ProcName,
				Msg );
		}

		cfsec::CFSecTSecGroupBuff* existing = searchExisting->second;

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
			std::string Msg( "Collision detected for TSecGroup primary key " );
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
		cfsec::CFSecTSecGroupByTenantIdxKey existingKeyTenantIdx;
		existingKeyTenantIdx.setRequiredTenantId( existing->getRequiredTenantId() );
		cfsec::CFSecTSecGroupByTenantIdxKey newKeyTenantIdx;
		newKeyTenantIdx.setRequiredTenantId( Buff->getRequiredTenantId() );
		cfsec::CFSecTSecGroupByTenantVisIdxKey existingKeyTenantVisIdx;
		existingKeyTenantVisIdx.setRequiredTenantId( existing->getRequiredTenantId() );
		existingKeyTenantVisIdx.setRequiredIsVisible( existing->getRequiredIsVisible() );
		cfsec::CFSecTSecGroupByTenantVisIdxKey newKeyTenantVisIdx;
		newKeyTenantVisIdx.setRequiredTenantId( Buff->getRequiredTenantId() );
		newKeyTenantVisIdx.setRequiredIsVisible( Buff->getRequiredIsVisible() );
		cfsec::CFSecTSecGroupByUNameIdxKey existingKeyUNameIdx;
		existingKeyUNameIdx.setRequiredTenantId( existing->getRequiredTenantId() );
		existingKeyUNameIdx.setRequiredName( existing->getRequiredName() );
		cfsec::CFSecTSecGroupByUNameIdxKey newKeyUNameIdx;
		newKeyUNameIdx.setRequiredTenantId( Buff->getRequiredTenantId() );
		newKeyUNameIdx.setRequiredName( Buff->getRequiredName() );
		// Check unique indexes

		if( existingKeyUNameIdx != newKeyUNameIdx ) {
			auto searchDictByUNameIdx = dictByUNameIdx->find( newKeyUNameIdx );
			if( searchDictByUNameIdx != dictByUNameIdx->end() ) {
				std::string Msg( "Duplicate key detected for index TSecGroupUNameIdx " + newKeyUNameIdx.toString() );
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
				cfsec::CFSecTenantBuff* chk = dynamic_cast<cfsec::CFSecTenantBuff*>( schema->getTableTenant()->readDerivedByIdIdx( Authorization,
						Buff->getRequiredTenantId() ) );
				if( chk == NULL ) {
					delete Buff;
					std::string Msg( "Could not resolve Container relationship TSecGroupTenant to table Tenant" );
					throw cflib::CFLibUnresolvedRelationException( CLASS_NAME,
						S_ProcName,
						Msg );
				}
				delete chk;
				chk = NULL;
			}
		}

		// Update is valid
		std::map<cfsec::CFSecTSecGroupPKey, cfsec::CFSecTSecGroupBuff*>* subdict;
		auto removalDictByPKey = dictByPKey->find( pkey );
		if( removalDictByPKey != dictByPKey->end() ) {
			dictByPKey->erase( removalDictByPKey );
		}
		// Copy edited buffer to existing persistent buffer

		if( Buff->getClassCode() != cfsec::CFSecTSecGroupBuff::CLASS_CODE ) {
			const static std::string S_IsNotA( " is not a cfsec::CFSecTSecGroupBuff" );
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

		dictByPKey->insert( std::map<cfsec::CFSecTSecGroupPKey, cfsec::CFSecTSecGroupBuff*>::value_type( pkey, existing ) );

		std::map<cfsec::CFSecTSecGroupPKey,
			 cfsec::CFSecTSecGroupBuff*>* subdictTenantIdx;
		auto searchDictByTenantIdx = dictByTenantIdx->find( existingKeyTenantIdx );
		if( searchDictByTenantIdx != dictByTenantIdx->end() ) {
			subdictTenantIdx = searchDictByTenantIdx->second;
			auto searchSubDict = subdictTenantIdx->find( pkey );
			if( searchSubDict != subdictTenantIdx->end() ) {
				subdictTenantIdx->erase( searchSubDict );
			}
			if( subdictTenantIdx->size() <= 0 ) {
				delete subdictTenantIdx;
				dictByTenantIdx->erase( searchDictByTenantIdx );
			}
			subdictTenantIdx = NULL;
		}
		auto searchNewKeyDictByTenantIdx = dictByTenantIdx->find( newKeyTenantIdx );
		if( searchNewKeyDictByTenantIdx != dictByTenantIdx->end() ) {
			subdictTenantIdx = searchNewKeyDictByTenantIdx->second;
		}
		else {
			subdictTenantIdx = new std::map<cfsec::CFSecTSecGroupPKey, cfsec::CFSecTSecGroupBuff*>();
			dictByTenantIdx->insert( std::map<cfsec::CFSecTSecGroupByTenantIdxKey,
				std::map<cfsec::CFSecTSecGroupPKey,
					cfsec::CFSecTSecGroupBuff*>*>::value_type( newKeyTenantIdx, subdictTenantIdx ) );
		}
		subdictTenantIdx->insert( std::map<cfsec::CFSecTSecGroupPKey, cfsec::CFSecTSecGroupBuff*>::value_type( pkey, existing ) );

		std::map<cfsec::CFSecTSecGroupPKey,
			 cfsec::CFSecTSecGroupBuff*>* subdictTenantVisIdx;
		auto searchDictByTenantVisIdx = dictByTenantVisIdx->find( existingKeyTenantVisIdx );
		if( searchDictByTenantVisIdx != dictByTenantVisIdx->end() ) {
			subdictTenantVisIdx = searchDictByTenantVisIdx->second;
			auto searchSubDict = subdictTenantVisIdx->find( pkey );
			if( searchSubDict != subdictTenantVisIdx->end() ) {
				subdictTenantVisIdx->erase( searchSubDict );
			}
			if( subdictTenantVisIdx->size() <= 0 ) {
				delete subdictTenantVisIdx;
				dictByTenantVisIdx->erase( searchDictByTenantVisIdx );
			}
			subdictTenantVisIdx = NULL;
		}
		auto searchNewKeyDictByTenantVisIdx = dictByTenantVisIdx->find( newKeyTenantVisIdx );
		if( searchNewKeyDictByTenantVisIdx != dictByTenantVisIdx->end() ) {
			subdictTenantVisIdx = searchNewKeyDictByTenantVisIdx->second;
		}
		else {
			subdictTenantVisIdx = new std::map<cfsec::CFSecTSecGroupPKey, cfsec::CFSecTSecGroupBuff*>();
			dictByTenantVisIdx->insert( std::map<cfsec::CFSecTSecGroupByTenantVisIdxKey,
				std::map<cfsec::CFSecTSecGroupPKey,
					cfsec::CFSecTSecGroupBuff*>*>::value_type( newKeyTenantVisIdx, subdictTenantVisIdx ) );
		}
		subdictTenantVisIdx->insert( std::map<cfsec::CFSecTSecGroupPKey, cfsec::CFSecTSecGroupBuff*>::value_type( pkey, existing ) );

		auto removalDictByUNameIdx = dictByUNameIdx->find( existingKeyUNameIdx );
		if( removalDictByUNameIdx != dictByUNameIdx->end() ) {
			dictByUNameIdx->erase( removalDictByUNameIdx );
		}
		dictByUNameIdx->insert( std::map<cfsec::CFSecTSecGroupByUNameIdxKey, cfsec::CFSecTSecGroupBuff*>::value_type( newKeyUNameIdx, existing ) );


		// The top level code has to clean up the memory buffer that was passed in, and return a clone
		// of the copy that existing buffer that is attached to the RAM storage.  All other cases
		// return the existing buffer.

		cfsec::CFSecTSecGroupBuff* buff;
		if( existing->getClassCode() == cfsec::CFSecTSecGroupBuff::CLASS_CODE ) {
			delete Buff;
			Buff = NULL;
			buff = dynamic_cast<cfsec::CFSecTSecGroupBuff*>( existing->clone() );
		}
		else {
			buff = existing;
		}
		return( buff );
	}

	void CFSecRamTSecGroupTable::deleteTSecGroup( const cfsec::CFSecAuthorization* Authorization,
		cfsec::CFSecTSecGroupBuff* Buff )
	{
		static const std::string S_ProcName( "deleteTSecGroup" );
		static const std::string S_Prev( "prev" );
		classcode_t classCode;
		cfsec::CFSecTSecGroupPKey pkey;
		pkey.setRequiredTenantId( Buff->getRequiredTenantId() );
		pkey.setRequiredTSecGroupId( Buff->getRequiredTSecGroupId() );
		auto searchExisting = dictByPKey->find( pkey );
		if( searchExisting == dictByPKey->end() ) {
			return;
		}
		cfsec::CFSecTSecGroupBuff* existing = searchExisting->second;
		schema->getTableTSecGrpInc()->deleteTSecGrpIncByIncludeIdx( Authorization,
			existing->getRequiredTenantId(),
			existing->getRequiredTSecGroupId() );
		schema->getTableTSecGrpMemb()->deleteTSecGrpMembByGroupIdx( Authorization,
			existing->getRequiredTenantId(),
			existing->getRequiredTSecGroupId() );
		schema->getTableTSecGrpInc()->deleteTSecGrpIncByGroupIdx( Authorization,
			existing->getRequiredTenantId(),
			existing->getRequiredTSecGroupId() );
		cfsec::CFSecTSecGroupByTenantIdxKey keyTenantIdx;
		keyTenantIdx.setRequiredTenantId( existing->getRequiredTenantId() );
		cfsec::CFSecTSecGroupByTenantVisIdxKey keyTenantVisIdx;
		keyTenantVisIdx.setRequiredTenantId( existing->getRequiredTenantId() );
		keyTenantVisIdx.setRequiredIsVisible( existing->getRequiredIsVisible() );
		cfsec::CFSecTSecGroupByUNameIdxKey keyUNameIdx;
		keyUNameIdx.setRequiredTenantId( existing->getRequiredTenantId() );
		keyUNameIdx.setRequiredName( existing->getRequiredName() );
		// Validate reverse foreign keys

		// Delete is valid
		std::map<cfsec::CFSecTSecGroupPKey, cfsec::CFSecTSecGroupBuff*>* subdict;

		auto searchDictByPKey = dictByPKey->find( pkey );
		if( searchDictByPKey != dictByPKey->end() ) {
			dictByPKey->erase( searchDictByPKey );
		}

		auto searchDictByTenantIdx = dictByTenantIdx->find( keyTenantIdx );
		if( searchDictByTenantIdx != dictByTenantIdx->end() ) {
			std::map<cfsec::CFSecTSecGroupPKey,
				 cfsec::CFSecTSecGroupBuff*>* subdictTenantIdx = searchDictByTenantIdx->second;
			auto searchSubDict = subdictTenantIdx->find( pkey );
			if( searchSubDict != subdictTenantIdx->end() ) {
				subdictTenantIdx->erase( searchSubDict );
			}
			subdictTenantIdx = NULL;
		}

		auto searchDictByTenantVisIdx = dictByTenantVisIdx->find( keyTenantVisIdx );
		if( searchDictByTenantVisIdx != dictByTenantVisIdx->end() ) {
			std::map<cfsec::CFSecTSecGroupPKey,
				 cfsec::CFSecTSecGroupBuff*>* subdictTenantVisIdx = searchDictByTenantVisIdx->second;
			auto searchSubDict = subdictTenantVisIdx->find( pkey );
			if( searchSubDict != subdictTenantVisIdx->end() ) {
				subdictTenantVisIdx->erase( searchSubDict );
			}
			subdictTenantVisIdx = NULL;
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

	void CFSecRamTSecGroupTable::deleteTSecGroupByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const int32_t argTSecGroupId )
	{
		cfsec::CFSecTSecGroupPKey key;
		key.setRequiredTenantId( argTenantId );
		key.setRequiredTSecGroupId( argTSecGroupId );
		deleteTSecGroupByIdIdx( Authorization, &key );
	}

	void CFSecRamTSecGroupTable::deleteTSecGroupByIdIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecTSecGroupPKey* argKey )
	{
		bool anyNotNull = false;
		anyNotNull = true;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		cfsec::CFSecTSecGroupBuff* cur = NULL;
		cfsec::CFSecTSecGroupBuff* rereadCur = NULL;
		std::TCFLibOwningVector<cfsec::CFSecTSecGroupBuff*> matchSet;
		std::map<cfsec::CFSecTSecGroupPKey,
			cfsec::CFSecTSecGroupBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecTSecGroupPKey,
			cfsec::CFSecTSecGroupBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecTSecGroupBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecTSecGroupBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecTSecGroupBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecTSecGroupBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableTSecGroup()->readDerivedByIdIdx( Authorization,
				cur->getRequiredTenantId(),
				cur->getRequiredTSecGroupId() );
			rereadCur = cur;
			deleteTSecGroup( Authorization, cur );
			if( rereadCur != NULL ) {
				delete rereadCur;
				rereadCur = NULL;
			}
		}
	}

	void CFSecRamTSecGroupTable::deleteTSecGroupByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId )
	{
		cfsec::CFSecTSecGroupByTenantIdxKey key;
		key.setRequiredTenantId( argTenantId );
		deleteTSecGroupByTenantIdx( Authorization, &key );
	}

	void CFSecRamTSecGroupTable::deleteTSecGroupByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecTSecGroupByTenantIdxKey* argKey )
	{
		cfsec::CFSecTSecGroupBuff* cur = NULL;
		cfsec::CFSecTSecGroupBuff* rereadCur = NULL;
		bool anyNotNull = false;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfsec::CFSecTSecGroupBuff*> matchSet;
		std::map<cfsec::CFSecTSecGroupPKey,
			cfsec::CFSecTSecGroupBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecTSecGroupPKey,
			cfsec::CFSecTSecGroupBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecTSecGroupBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecTSecGroupBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecTSecGroupBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecTSecGroupBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableTSecGroup()->readDerivedByIdIdx( Authorization,
				cur->getRequiredTenantId(),
				cur->getRequiredTSecGroupId() );
			rereadCur = cur;
			deleteTSecGroup( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFSecRamTSecGroupTable::deleteTSecGroupByTenantVisIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const bool argIsVisible )
	{
		cfsec::CFSecTSecGroupByTenantVisIdxKey key;
		key.setRequiredTenantId( argTenantId );
		key.setRequiredIsVisible( argIsVisible );
		deleteTSecGroupByTenantVisIdx( Authorization, &key );
	}

	void CFSecRamTSecGroupTable::deleteTSecGroupByTenantVisIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecTSecGroupByTenantVisIdxKey* argKey )
	{
		cfsec::CFSecTSecGroupBuff* cur = NULL;
		cfsec::CFSecTSecGroupBuff* rereadCur = NULL;
		bool anyNotNull = false;
		anyNotNull = true;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfsec::CFSecTSecGroupBuff*> matchSet;
		std::map<cfsec::CFSecTSecGroupPKey,
			cfsec::CFSecTSecGroupBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecTSecGroupPKey,
			cfsec::CFSecTSecGroupBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecTSecGroupBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecTSecGroupBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecTSecGroupBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecTSecGroupBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableTSecGroup()->readDerivedByIdIdx( Authorization,
				cur->getRequiredTenantId(),
				cur->getRequiredTSecGroupId() );
			rereadCur = cur;
			deleteTSecGroup( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFSecRamTSecGroupTable::deleteTSecGroupByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const std::string& argName )
	{
		cfsec::CFSecTSecGroupByUNameIdxKey key;
		key.setRequiredTenantId( argTenantId );
		key.setRequiredName( argName );
		deleteTSecGroupByUNameIdx( Authorization, &key );
	}

	void CFSecRamTSecGroupTable::deleteTSecGroupByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecTSecGroupByUNameIdxKey* argKey )
	{
		cfsec::CFSecTSecGroupBuff* cur = NULL;
		cfsec::CFSecTSecGroupBuff* rereadCur = NULL;
		bool anyNotNull = false;
		anyNotNull = true;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfsec::CFSecTSecGroupBuff*> matchSet;
		std::map<cfsec::CFSecTSecGroupPKey,
			cfsec::CFSecTSecGroupBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecTSecGroupPKey,
			cfsec::CFSecTSecGroupBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecTSecGroupBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecTSecGroupBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecTSecGroupBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecTSecGroupBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableTSecGroup()->readDerivedByIdIdx( Authorization,
				cur->getRequiredTenantId(),
				cur->getRequiredTSecGroupId() );
			rereadCur = cur;
			deleteTSecGroup( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFSecRamTSecGroupTable::releasePreparedStatements() {
	}

}
