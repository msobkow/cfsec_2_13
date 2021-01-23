
// Description: C++18 Implementation for an in-memory RAM DbIO for SecForm.

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

	const std::string CFSecRamSecFormTable::CLASS_NAME( "CFSecRamSecFormTable" );

	CFSecRamSecFormTable::CFSecRamSecFormTable( ICFSecSchema* argSchema )
	: cfsec::ICFSecSecFormTable()
	{
		schema = argSchema;
		dictByPKey = new std::map<cfsec::CFSecSecFormPKey, cfsec::CFSecSecFormBuff*>();
		dictByClusterIdx = new std::map<cfsec::CFSecSecFormByClusterIdxKey,
			std::map<cfsec::CFSecSecFormPKey,
				cfsec::CFSecSecFormBuff*>*>();
		dictBySecAppIdx = new std::map<cfsec::CFSecSecFormBySecAppIdxKey,
			std::map<cfsec::CFSecSecFormPKey,
				cfsec::CFSecSecFormBuff*>*>();
		dictByUJEEServletIdx = new std::map<cfsec::CFSecSecFormByUJEEServletIdxKey, cfsec::CFSecSecFormBuff*>();
	}

	CFSecRamSecFormTable::~CFSecRamSecFormTable() {
		if( dictByClusterIdx != NULL ) {
			for( auto iterDict = dictByClusterIdx->begin(); iterDict != dictByClusterIdx->end(); iterDict ++ ) {
				delete iterDict->second;
				iterDict->second = NULL;
			}
			delete dictByClusterIdx;
			dictByClusterIdx = NULL;
		}
		if( dictBySecAppIdx != NULL ) {
			for( auto iterDict = dictBySecAppIdx->begin(); iterDict != dictBySecAppIdx->end(); iterDict ++ ) {
				delete iterDict->second;
				iterDict->second = NULL;
			}
			delete dictBySecAppIdx;
			dictBySecAppIdx = NULL;
		}
		if( dictByUJEEServletIdx != NULL ) {
			delete dictByUJEEServletIdx;
			dictByUJEEServletIdx = NULL;
		}
		if( dictByPKey != NULL ) {
			cfsec::CFSecSecFormBuff* elt;
			std::map<cfsec::CFSecSecFormPKey,
				cfsec::CFSecSecFormBuff*>::iterator end = dictByPKey->end();
			for( std::map<cfsec::CFSecSecFormPKey,
					cfsec::CFSecSecFormBuff*>::iterator cur = dictByPKey->begin();
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

	cfsec::CFSecSecFormBuff* CFSecRamSecFormTable::createSecForm( const cfsec::CFSecAuthorization* Authorization,
		cfsec::CFSecSecFormBuff* Buff )
	{
		static const std::string S_ProcName( "createSecForm" );
		cfsec::CFSecSecFormPKey pkey;
		pkey.setRequiredClusterId( Buff->getRequiredClusterId() );
		pkey.setRequiredSecFormId( dynamic_cast<CFSecRamClusterTable*>( schema->getTableCluster() )->nextSecFormIdGen( Authorization,
			Buff->getRequiredClusterId() ) );
		Buff->setRequiredClusterId( pkey.getRequiredClusterId() );
		Buff->setRequiredSecFormId( pkey.getRequiredSecFormId() );
		cfsec::CFSecSecFormByClusterIdxKey keyClusterIdx;
		keyClusterIdx.setRequiredClusterId( Buff->getRequiredClusterId() );
		cfsec::CFSecSecFormBySecAppIdxKey keySecAppIdx;
		keySecAppIdx.setRequiredClusterId( Buff->getRequiredClusterId() );
		keySecAppIdx.setRequiredSecAppId( Buff->getRequiredSecAppId() );
		cfsec::CFSecSecFormByUJEEServletIdxKey keyUJEEServletIdx;
		keyUJEEServletIdx.setRequiredClusterId( Buff->getRequiredClusterId() );
		keyUJEEServletIdx.setRequiredSecAppId( Buff->getRequiredSecAppId() );
		keyUJEEServletIdx.setRequiredJEEServletMapName( Buff->getRequiredJEEServletMapName() );
		// Validate unique indexes
		auto searchDictByPKey = dictByPKey->find( pkey );
		if( searchDictByPKey != dictByPKey->end() ) {
			delete Buff;
			std::string Msg( "Duplicate primary key detected " + pkey.toString() );
			throw cflib::CFLibPrimaryKeyNotNewException( CLASS_NAME, S_ProcName, Msg );
		}

		auto searchDictByUJEEServletIdx = dictByUJEEServletIdx->find( keyUJEEServletIdx );
		if( searchDictByUJEEServletIdx != dictByUJEEServletIdx->end() ) {
			std::string Msg( "Duplicate key detected for index SecFormUJEEServletIdx " + keyUJEEServletIdx.toString() );
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
					std::string Msg( "Could not resolve Owner relationship SecFormCluster to table Cluster" );
					throw cflib::CFLibUnresolvedRelationException( CLASS_NAME,
						S_ProcName,
						Msg );
				}
				delete chk;
				chk = NULL;
			}
		}

		{
			bool allNull = true;
			allNull = false;
			allNull = false;
			if( ! allNull ) {
				cfsec::CFSecSecAppBuff* chk = dynamic_cast<cfsec::CFSecSecAppBuff*>( schema->getTableSecApp()->readDerivedByIdIdx( Authorization,
						Buff->getRequiredClusterId(),
						Buff->getRequiredSecAppId() ) );
				if( chk == NULL ) {
					delete Buff;
					std::string Msg( "Could not resolve Container relationship SecFormApplication to table SecApp" );
					throw cflib::CFLibUnresolvedRelationException( CLASS_NAME,
						S_ProcName,
						Msg );
				}
				delete chk;
				chk = NULL;
			}
		}

		// Proceed with adding the new record
		cfsec::CFSecSecFormBuff* buff = Buff;
		buff->setRequiredRevision( 1 );
		dictByPKey->insert( std::map<cfsec::CFSecSecFormPKey, cfsec::CFSecSecFormBuff*>::value_type( pkey, buff ) );

		std::map<cfsec::CFSecSecFormPKey, cfsec::CFSecSecFormBuff*>* subdictClusterIdx;
		auto searchDictByClusterIdx = dictByClusterIdx->find( keyClusterIdx );
		if( searchDictByClusterIdx != dictByClusterIdx->end() ) {
			subdictClusterIdx = searchDictByClusterIdx->second;
		}
		else {
			subdictClusterIdx = new std::map<cfsec::CFSecSecFormPKey, cfsec::CFSecSecFormBuff*>();
			dictByClusterIdx->insert( std::map<cfsec::CFSecSecFormByClusterIdxKey,
				std::map<cfsec::CFSecSecFormPKey,
					cfsec::CFSecSecFormBuff*>*>::value_type( keyClusterIdx, subdictClusterIdx ) );
		}
		subdictClusterIdx->insert( std::map<cfsec::CFSecSecFormPKey, cfsec::CFSecSecFormBuff*>::value_type( pkey, buff ) );

		std::map<cfsec::CFSecSecFormPKey, cfsec::CFSecSecFormBuff*>* subdictSecAppIdx;
		auto searchDictBySecAppIdx = dictBySecAppIdx->find( keySecAppIdx );
		if( searchDictBySecAppIdx != dictBySecAppIdx->end() ) {
			subdictSecAppIdx = searchDictBySecAppIdx->second;
		}
		else {
			subdictSecAppIdx = new std::map<cfsec::CFSecSecFormPKey, cfsec::CFSecSecFormBuff*>();
			dictBySecAppIdx->insert( std::map<cfsec::CFSecSecFormBySecAppIdxKey,
				std::map<cfsec::CFSecSecFormPKey,
					cfsec::CFSecSecFormBuff*>*>::value_type( keySecAppIdx, subdictSecAppIdx ) );
		}
		subdictSecAppIdx->insert( std::map<cfsec::CFSecSecFormPKey, cfsec::CFSecSecFormBuff*>::value_type( pkey, buff ) );

		dictByUJEEServletIdx->insert( std::map<cfsec::CFSecSecFormByUJEEServletIdxKey, cfsec::CFSecSecFormBuff*>::value_type( keyUJEEServletIdx, buff ) );

		// The top level code has to clone the final buffer. The one passed in is now part of the persistent storage.
		if( buff->getClassCode() == cfsec::CFSecSecFormBuff::CLASS_CODE ) {
			buff = dynamic_cast<cfsec::CFSecSecFormBuff*>( buff->clone() );
		}
		return( buff );
	}

	cfsec::CFSecSecFormBuff* CFSecRamSecFormTable::readDerived( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecFormPKey* PKey )
	{
		static const std::string S_ProcName( "readDerived" );
		cfsec::CFSecSecFormBuff* buff;
		auto searchDictByPKey = dictByPKey->find( *PKey );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfsec::CFSecSecFormBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecSecFormBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfsec::CFSecSecFormBuff* CFSecRamSecFormTable::lockDerived( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecFormPKey* PKey )
	{
		static const std::string S_ProcName( "lockDerived" );
		cfsec::CFSecSecFormBuff* buff;
		auto searchDictByPKey = dictByPKey->find( *PKey );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfsec::CFSecSecFormBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecSecFormBuff*>( buff->clone() );
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

	std::TCFLibOwningVector<cfsec::CFSecSecFormBuff*> CFSecRamSecFormTable::readAllDerived( const cfsec::CFSecAuthorization* Authorization ) {
		static const std::string S_ProcName( "readAllDerived" );
		std::TCFLibOwningVector<cfsec::CFSecSecFormBuff*> retVec;
		std::map<cfsec::CFSecSecFormPKey,
			cfsec::CFSecSecFormBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecSecFormPKey,
			cfsec::CFSecSecFormBuff*>::iterator end = dictByPKey->end();
		cfsec::CFSecSecFormBuff* clone;
		while( iter != end ) {
			clone = dynamic_cast<cfsec::CFSecSecFormBuff*>( iter->second->clone() );
			retVec.push_back( clone );
			iter ++;
		}
		return( retVec );
	}

	std::TCFLibOwningVector<cfsec::CFSecSecFormBuff*> CFSecRamSecFormTable::readDerivedByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId )
	{
		static const std::string S_ProcName( "readDerivedByClusterIdx" );
		cfsec::CFSecSecFormByClusterIdxKey key;
		key.setRequiredClusterId( ClusterId );
		std::TCFLibOwningVector<cfsec::CFSecSecFormBuff*> recVec;
		cfsec::CFSecSecFormBuff* clone;
		auto searchDictByClusterIdx = dictByClusterIdx->find( key );
		if( searchDictByClusterIdx != dictByClusterIdx->end() ) {
			std::map<cfsec::CFSecSecFormPKey,
				 cfsec::CFSecSecFormBuff*>* subdictClusterIdx = searchDictByClusterIdx->second;
			std::map<cfsec::CFSecSecFormPKey,
				cfsec::CFSecSecFormBuff*>::iterator iter = subdictClusterIdx->begin();
			std::map<cfsec::CFSecSecFormPKey,
				cfsec::CFSecSecFormBuff*>::iterator end = subdictClusterIdx->end();
			while( iter != end ) {
				clone = dynamic_cast<cfsec::CFSecSecFormBuff*>( iter->second->clone() );
				recVec.push_back( clone );
				iter ++;
			}
		}
		return( recVec );
	}

	std::TCFLibOwningVector<cfsec::CFSecSecFormBuff*> CFSecRamSecFormTable::readDerivedBySecAppIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecAppId )
	{
		static const std::string S_ProcName( "readDerivedBySecAppIdx" );
		cfsec::CFSecSecFormBySecAppIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredSecAppId( SecAppId );
		std::TCFLibOwningVector<cfsec::CFSecSecFormBuff*> recVec;
		cfsec::CFSecSecFormBuff* clone;
		auto searchDictBySecAppIdx = dictBySecAppIdx->find( key );
		if( searchDictBySecAppIdx != dictBySecAppIdx->end() ) {
			std::map<cfsec::CFSecSecFormPKey,
				 cfsec::CFSecSecFormBuff*>* subdictSecAppIdx = searchDictBySecAppIdx->second;
			std::map<cfsec::CFSecSecFormPKey,
				cfsec::CFSecSecFormBuff*>::iterator iter = subdictSecAppIdx->begin();
			std::map<cfsec::CFSecSecFormPKey,
				cfsec::CFSecSecFormBuff*>::iterator end = subdictSecAppIdx->end();
			while( iter != end ) {
				clone = dynamic_cast<cfsec::CFSecSecFormBuff*>( iter->second->clone() );
				recVec.push_back( clone );
				iter ++;
			}
		}
		return( recVec );
	}

	cfsec::CFSecSecFormBuff* CFSecRamSecFormTable::readDerivedByUJEEServletIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecAppId,
			const std::string& JEEServletMapName )
	{
		static const std::string S_ProcName( "readDerivedByUJEEServletIdx" );
		cfsec::CFSecSecFormByUJEEServletIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredSecAppId( SecAppId );
		key.setRequiredJEEServletMapName( JEEServletMapName );
		cfsec::CFSecSecFormBuff* buff;
		auto searchDictByUJEEServletIdx = dictByUJEEServletIdx->find( key );
		if( searchDictByUJEEServletIdx != dictByUJEEServletIdx->end() ) {
			buff = dynamic_cast<cfsec::CFSecSecFormBuff*>( searchDictByUJEEServletIdx->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecSecFormBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfsec::CFSecSecFormBuff* CFSecRamSecFormTable::readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecFormId )
	{
		static const std::string S_ProcName( "readDerivedByIdIdx" );
		cfsec::CFSecSecFormPKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredSecFormId( SecFormId );
		cfsec::CFSecSecFormBuff* buff;
		auto searchDictByPKey = dictByPKey->find( key );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfsec::CFSecSecFormBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecSecFormBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfsec::CFSecSecFormBuff* CFSecRamSecFormTable::readBuff( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecFormPKey* PKey )
	{
		static const std::string S_ProcName( "readBuff" );
		cfsec::CFSecSecFormBuff* buff = readDerived( Authorization, PKey );
		if( buff != NULL ) {
			if( buff->getClassCode() != cfsec::CFSecSecFormBuff::CLASS_CODE ) {
				delete buff;
				buff = NULL;
			}
		}
		return( dynamic_cast<cfsec::CFSecSecFormBuff*>( buff ) );
	}

	cfsec::CFSecSecFormBuff* CFSecRamSecFormTable::lockBuff( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecFormPKey* PKey )
	{
		static const std::string S_ProcName( "lockBuff" );
		cfsec::CFSecSecFormBuff* buff = lockDerived( Authorization, PKey );
		return( dynamic_cast<cfsec::CFSecSecFormBuff*>( buff ) );
	}

	std::TCFLibOwningVector<cfsec::CFSecSecFormBuff*> CFSecRamSecFormTable::readAllBuff( const cfsec::CFSecAuthorization* Authorization )
	{
		static const std::string S_ProcName( "readAllBuff" );
		cfsec::CFSecSecFormBuff* buff;
		std::TCFLibOwningVector<cfsec::CFSecSecFormBuff*> filteredList;
		std::TCFLibOwningVector<cfsec::CFSecSecFormBuff*> buffList = readAllDerived( Authorization );
		std::TCFLibOwningVector<cfsec::CFSecSecFormBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecFormBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfsec::CFSecSecFormBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfsec::CFSecSecFormBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	std::TCFLibOwningVector<cfsec::CFSecSecFormBuff*> CFSecRamSecFormTable::pageAllBuff( const cfsec::CFSecAuthorization* Authorization,
			const int64_t* priorClusterId,
			const int32_t* priorSecFormId )
	{
		static const std::string S_ProcName( "pageAllBuff" );
		// MSS TODO WORKING
		throw cflib::CFLibNotImplementedYetException( CLASS_NAME, S_ProcName );
	}

	cfsec::CFSecSecFormBuff* CFSecRamSecFormTable::readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecFormId )
	{
		static const std::string S_ProcName( "readBuffByIdIdx" );
		cfsec::CFSecSecFormBuff* buff = readDerivedByIdIdx( Authorization,
			ClusterId,
			SecFormId );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfsec::CFSecSecFormBuff::CLASS_CODE ) {
			return( dynamic_cast<cfsec::CFSecSecFormBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	std::TCFLibOwningVector<cfsec::CFSecSecFormBuff*> CFSecRamSecFormTable::readBuffByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId )
	{
		static const std::string S_ProcName( "readBuffByClusterIdx" );
		cfsec::CFSecSecFormBuff* buff;
		std::TCFLibOwningVector<cfsec::CFSecSecFormBuff*> filteredList;
		std::TCFLibOwningVector<cfsec::CFSecSecFormBuff*> buffList = readDerivedByClusterIdx( Authorization,
			ClusterId );
		std::TCFLibOwningVector<cfsec::CFSecSecFormBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecFormBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfsec::CFSecSecFormBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfsec::CFSecSecFormBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	std::TCFLibOwningVector<cfsec::CFSecSecFormBuff*> CFSecRamSecFormTable::readBuffBySecAppIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecAppId )
	{
		static const std::string S_ProcName( "readBuffBySecAppIdx" );
		cfsec::CFSecSecFormBuff* buff;
		std::TCFLibOwningVector<cfsec::CFSecSecFormBuff*> filteredList;
		std::TCFLibOwningVector<cfsec::CFSecSecFormBuff*> buffList = readDerivedBySecAppIdx( Authorization,
			ClusterId,
			SecAppId );
		std::TCFLibOwningVector<cfsec::CFSecSecFormBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecFormBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfsec::CFSecSecFormBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfsec::CFSecSecFormBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	cfsec::CFSecSecFormBuff* CFSecRamSecFormTable::readBuffByUJEEServletIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecAppId,
			const std::string& JEEServletMapName )
	{
		static const std::string S_ProcName( "readBuffByUJEEServletIdx" );
		cfsec::CFSecSecFormBuff* buff = readDerivedByUJEEServletIdx( Authorization,
			ClusterId,
			SecAppId,
			JEEServletMapName );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfsec::CFSecSecFormBuff::CLASS_CODE ) {
			return( dynamic_cast<cfsec::CFSecSecFormBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	cfsec::CFSecSecFormBuff* CFSecRamSecFormTable::readBuffByLookupUJEEServletIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecAppId, const std::string& JEEServletMapName,
		bool forceRead )
	{
		static const std::string S_ProcName( "readBuffByLookupUJEEServletIdx" );
		cfsec::CFSecSecFormBuff* buff = readBuffByUJEEServletIdx( Authorization,
			ClusterId,
			SecAppId,
			JEEServletMapName );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfsec::CFSecSecFormBuff::CLASS_CODE ) {
			return( dynamic_cast<cfsec::CFSecSecFormBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	cfsec::CFSecSecFormBuff* CFSecRamSecFormTable::readDerivedByLookupUJEEServletIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecAppId, const std::string& JEEServletMapName,
		bool forceRead )
	{
		static const std::string S_ProcName( "readDerivedByLookupUJEEServletIdx" );
		cfsec::CFSecSecFormBuff* buff = readDerivedByUJEEServletIdx( Authorization,
			ClusterId,
			SecAppId,
			JEEServletMapName );
		if( buff != NULL ) {
			return( dynamic_cast<cfsec::CFSecSecFormBuff*>( buff->clone() ) );
		}
		else {
			return( NULL );
		}
	}

	std::TCFLibOwningVector<cfsec::CFSecSecFormBuff*> CFSecRamSecFormTable::pageBuffByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t* priorClusterId,
			const int32_t* priorSecFormId )
	{
		static const std::string S_ProcName( "pageBuffByClusterIdx" );
		// MSS TODO WORKING
		throw cflib::CFLibNotImplementedYetException( CLASS_NAME, S_ProcName );
	}

	std::TCFLibOwningVector<cfsec::CFSecSecFormBuff*> CFSecRamSecFormTable::pageBuffBySecAppIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecAppId,
			const int64_t* priorClusterId,
			const int32_t* priorSecFormId )
	{
		static const std::string S_ProcName( "pageBuffBySecAppIdx" );
		// MSS TODO WORKING
		throw cflib::CFLibNotImplementedYetException( CLASS_NAME, S_ProcName );
	}

	cfsec::CFSecSecFormBuff* CFSecRamSecFormTable::updateSecForm( const cfsec::CFSecAuthorization* Authorization,
		cfsec::CFSecSecFormBuff* Buff )
	{
		static const std::string S_ProcName( "updateSecForm" );
		cfsec::CFSecSecFormPKey pkey;
		pkey.setRequiredClusterId( Buff->getRequiredClusterId() );
		pkey.setRequiredSecFormId( Buff->getRequiredSecFormId() );

		// Search for existing buffer

		auto searchExisting = dictByPKey->find( pkey );
		if( searchExisting == dictByPKey->end() ) {
			delete Buff;
			std::string Msg( "Existing record not found in SecForm for key " + pkey.toString() );
			throw cflib::CFLibStaleCacheDetectedException( CLASS_NAME,
				S_ProcName,
				Msg );
		}

		cfsec::CFSecSecFormBuff* existing = searchExisting->second;

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
			std::string Msg( "Collision detected for SecForm primary key " );
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
		cfsec::CFSecSecFormByClusterIdxKey existingKeyClusterIdx;
		existingKeyClusterIdx.setRequiredClusterId( existing->getRequiredClusterId() );
		cfsec::CFSecSecFormByClusterIdxKey newKeyClusterIdx;
		newKeyClusterIdx.setRequiredClusterId( Buff->getRequiredClusterId() );
		cfsec::CFSecSecFormBySecAppIdxKey existingKeySecAppIdx;
		existingKeySecAppIdx.setRequiredClusterId( existing->getRequiredClusterId() );
		existingKeySecAppIdx.setRequiredSecAppId( existing->getRequiredSecAppId() );
		cfsec::CFSecSecFormBySecAppIdxKey newKeySecAppIdx;
		newKeySecAppIdx.setRequiredClusterId( Buff->getRequiredClusterId() );
		newKeySecAppIdx.setRequiredSecAppId( Buff->getRequiredSecAppId() );
		cfsec::CFSecSecFormByUJEEServletIdxKey existingKeyUJEEServletIdx;
		existingKeyUJEEServletIdx.setRequiredClusterId( existing->getRequiredClusterId() );
		existingKeyUJEEServletIdx.setRequiredSecAppId( existing->getRequiredSecAppId() );
		existingKeyUJEEServletIdx.setRequiredJEEServletMapName( existing->getRequiredJEEServletMapName() );
		cfsec::CFSecSecFormByUJEEServletIdxKey newKeyUJEEServletIdx;
		newKeyUJEEServletIdx.setRequiredClusterId( Buff->getRequiredClusterId() );
		newKeyUJEEServletIdx.setRequiredSecAppId( Buff->getRequiredSecAppId() );
		newKeyUJEEServletIdx.setRequiredJEEServletMapName( Buff->getRequiredJEEServletMapName() );
		// Check unique indexes

		if( existingKeyUJEEServletIdx != newKeyUJEEServletIdx ) {
			auto searchDictByUJEEServletIdx = dictByUJEEServletIdx->find( newKeyUJEEServletIdx );
			if( searchDictByUJEEServletIdx != dictByUJEEServletIdx->end() ) {
				std::string Msg( "Duplicate key detected for index SecFormUJEEServletIdx " + newKeyUJEEServletIdx.toString() );
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
					std::string Msg( "Could not resolve Owner relationship SecFormCluster to table Cluster" );
					throw cflib::CFLibUnresolvedRelationException( CLASS_NAME,
						S_ProcName,
						Msg );
				}
				delete chk;
				chk = NULL;
			}
		}

		{
			bool allNull = true;

			if( allNull ) {
				cfsec::CFSecSecAppBuff* chk = dynamic_cast<cfsec::CFSecSecAppBuff*>( schema->getTableSecApp()->readDerivedByIdIdx( Authorization,
						Buff->getRequiredClusterId(),
						Buff->getRequiredSecAppId() ) );
				if( chk == NULL ) {
					delete Buff;
					std::string Msg( "Could not resolve Container relationship SecFormApplication to table SecApp" );
					throw cflib::CFLibUnresolvedRelationException( CLASS_NAME,
						S_ProcName,
						Msg );
				}
				delete chk;
				chk = NULL;
			}
		}

		// Update is valid
		std::map<cfsec::CFSecSecFormPKey, cfsec::CFSecSecFormBuff*>* subdict;
		auto removalDictByPKey = dictByPKey->find( pkey );
		if( removalDictByPKey != dictByPKey->end() ) {
			dictByPKey->erase( removalDictByPKey );
		}
		// Copy edited buffer to existing persistent buffer

		if( Buff->getClassCode() != cfsec::CFSecSecFormBuff::CLASS_CODE ) {
			const static std::string S_IsNotA( " is not a cfsec::CFSecSecFormBuff" );
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

		dictByPKey->insert( std::map<cfsec::CFSecSecFormPKey, cfsec::CFSecSecFormBuff*>::value_type( pkey, existing ) );

		std::map<cfsec::CFSecSecFormPKey,
			 cfsec::CFSecSecFormBuff*>* subdictClusterIdx;
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
			subdictClusterIdx = new std::map<cfsec::CFSecSecFormPKey, cfsec::CFSecSecFormBuff*>();
			dictByClusterIdx->insert( std::map<cfsec::CFSecSecFormByClusterIdxKey,
				std::map<cfsec::CFSecSecFormPKey,
					cfsec::CFSecSecFormBuff*>*>::value_type( newKeyClusterIdx, subdictClusterIdx ) );
		}
		subdictClusterIdx->insert( std::map<cfsec::CFSecSecFormPKey, cfsec::CFSecSecFormBuff*>::value_type( pkey, existing ) );

		std::map<cfsec::CFSecSecFormPKey,
			 cfsec::CFSecSecFormBuff*>* subdictSecAppIdx;
		auto searchDictBySecAppIdx = dictBySecAppIdx->find( existingKeySecAppIdx );
		if( searchDictBySecAppIdx != dictBySecAppIdx->end() ) {
			subdictSecAppIdx = searchDictBySecAppIdx->second;
			auto searchSubDict = subdictSecAppIdx->find( pkey );
			if( searchSubDict != subdictSecAppIdx->end() ) {
				subdictSecAppIdx->erase( searchSubDict );
			}
			if( subdictSecAppIdx->size() <= 0 ) {
				delete subdictSecAppIdx;
				dictBySecAppIdx->erase( searchDictBySecAppIdx );
			}
			subdictSecAppIdx = NULL;
		}
		auto searchNewKeyDictBySecAppIdx = dictBySecAppIdx->find( newKeySecAppIdx );
		if( searchNewKeyDictBySecAppIdx != dictBySecAppIdx->end() ) {
			subdictSecAppIdx = searchNewKeyDictBySecAppIdx->second;
		}
		else {
			subdictSecAppIdx = new std::map<cfsec::CFSecSecFormPKey, cfsec::CFSecSecFormBuff*>();
			dictBySecAppIdx->insert( std::map<cfsec::CFSecSecFormBySecAppIdxKey,
				std::map<cfsec::CFSecSecFormPKey,
					cfsec::CFSecSecFormBuff*>*>::value_type( newKeySecAppIdx, subdictSecAppIdx ) );
		}
		subdictSecAppIdx->insert( std::map<cfsec::CFSecSecFormPKey, cfsec::CFSecSecFormBuff*>::value_type( pkey, existing ) );

		auto removalDictByUJEEServletIdx = dictByUJEEServletIdx->find( existingKeyUJEEServletIdx );
		if( removalDictByUJEEServletIdx != dictByUJEEServletIdx->end() ) {
			dictByUJEEServletIdx->erase( removalDictByUJEEServletIdx );
		}
		dictByUJEEServletIdx->insert( std::map<cfsec::CFSecSecFormByUJEEServletIdxKey, cfsec::CFSecSecFormBuff*>::value_type( newKeyUJEEServletIdx, existing ) );


		// The top level code has to clean up the memory buffer that was passed in, and return a clone
		// of the copy that existing buffer that is attached to the RAM storage.  All other cases
		// return the existing buffer.

		cfsec::CFSecSecFormBuff* buff;
		if( existing->getClassCode() == cfsec::CFSecSecFormBuff::CLASS_CODE ) {
			delete Buff;
			Buff = NULL;
			buff = dynamic_cast<cfsec::CFSecSecFormBuff*>( existing->clone() );
		}
		else {
			buff = existing;
		}
		return( buff );
	}

	void CFSecRamSecFormTable::deleteSecForm( const cfsec::CFSecAuthorization* Authorization,
		cfsec::CFSecSecFormBuff* Buff )
	{
		static const std::string S_ProcName( "deleteSecForm" );
		static const std::string S_Prev( "prev" );
		classcode_t classCode;
		cfsec::CFSecSecFormPKey pkey;
		pkey.setRequiredClusterId( Buff->getRequiredClusterId() );
		pkey.setRequiredSecFormId( Buff->getRequiredSecFormId() );
		auto searchExisting = dictByPKey->find( pkey );
		if( searchExisting == dictByPKey->end() ) {
			return;
		}
		cfsec::CFSecSecFormBuff* existing = searchExisting->second;
		cfsec::CFSecSecFormByClusterIdxKey keyClusterIdx;
		keyClusterIdx.setRequiredClusterId( existing->getRequiredClusterId() );
		cfsec::CFSecSecFormBySecAppIdxKey keySecAppIdx;
		keySecAppIdx.setRequiredClusterId( existing->getRequiredClusterId() );
		keySecAppIdx.setRequiredSecAppId( existing->getRequiredSecAppId() );
		cfsec::CFSecSecFormByUJEEServletIdxKey keyUJEEServletIdx;
		keyUJEEServletIdx.setRequiredClusterId( existing->getRequiredClusterId() );
		keyUJEEServletIdx.setRequiredSecAppId( existing->getRequiredSecAppId() );
		keyUJEEServletIdx.setRequiredJEEServletMapName( existing->getRequiredJEEServletMapName() );
		// Validate reverse foreign keys

		// Delete is valid
		std::map<cfsec::CFSecSecFormPKey, cfsec::CFSecSecFormBuff*>* subdict;

		auto searchDictByPKey = dictByPKey->find( pkey );
		if( searchDictByPKey != dictByPKey->end() ) {
			dictByPKey->erase( searchDictByPKey );
		}

		auto searchDictByClusterIdx = dictByClusterIdx->find( keyClusterIdx );
		if( searchDictByClusterIdx != dictByClusterIdx->end() ) {
			std::map<cfsec::CFSecSecFormPKey,
				 cfsec::CFSecSecFormBuff*>* subdictClusterIdx = searchDictByClusterIdx->second;
			auto searchSubDict = subdictClusterIdx->find( pkey );
			if( searchSubDict != subdictClusterIdx->end() ) {
				subdictClusterIdx->erase( searchSubDict );
			}
			subdictClusterIdx = NULL;
		}

		auto searchDictBySecAppIdx = dictBySecAppIdx->find( keySecAppIdx );
		if( searchDictBySecAppIdx != dictBySecAppIdx->end() ) {
			std::map<cfsec::CFSecSecFormPKey,
				 cfsec::CFSecSecFormBuff*>* subdictSecAppIdx = searchDictBySecAppIdx->second;
			auto searchSubDict = subdictSecAppIdx->find( pkey );
			if( searchSubDict != subdictSecAppIdx->end() ) {
				subdictSecAppIdx->erase( searchSubDict );
			}
			subdictSecAppIdx = NULL;
		}

		auto searchDictByUJEEServletIdx = dictByUJEEServletIdx->find( keyUJEEServletIdx );
		if( searchDictByUJEEServletIdx != dictByUJEEServletIdx->end() ) {
			dictByUJEEServletIdx->erase( searchDictByUJEEServletIdx );
		}

		if( existing != NULL ) {
			delete existing;
			existing = NULL;
		}
	}

	void CFSecRamSecFormTable::deleteSecFormByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const int32_t argSecFormId )
	{
		cfsec::CFSecSecFormPKey key;
		key.setRequiredClusterId( argClusterId );
		key.setRequiredSecFormId( argSecFormId );
		deleteSecFormByIdIdx( Authorization, &key );
	}

	void CFSecRamSecFormTable::deleteSecFormByIdIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecFormPKey* argKey )
	{
		bool anyNotNull = false;
		anyNotNull = true;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		cfsec::CFSecSecFormBuff* cur = NULL;
		cfsec::CFSecSecFormBuff* rereadCur = NULL;
		std::TCFLibOwningVector<cfsec::CFSecSecFormBuff*> matchSet;
		std::map<cfsec::CFSecSecFormPKey,
			cfsec::CFSecSecFormBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecSecFormPKey,
			cfsec::CFSecSecFormBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecSecFormBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecSecFormBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecSecFormBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecFormBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableSecForm()->readDerivedByIdIdx( Authorization,
				cur->getRequiredClusterId(),
				cur->getRequiredSecFormId() );
			rereadCur = cur;
			deleteSecForm( Authorization, cur );
			if( rereadCur != NULL ) {
				delete rereadCur;
				rereadCur = NULL;
			}
		}
	}

	void CFSecRamSecFormTable::deleteSecFormByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId )
	{
		cfsec::CFSecSecFormByClusterIdxKey key;
		key.setRequiredClusterId( argClusterId );
		deleteSecFormByClusterIdx( Authorization, &key );
	}

	void CFSecRamSecFormTable::deleteSecFormByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecFormByClusterIdxKey* argKey )
	{
		cfsec::CFSecSecFormBuff* cur = NULL;
		cfsec::CFSecSecFormBuff* rereadCur = NULL;
		bool anyNotNull = false;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfsec::CFSecSecFormBuff*> matchSet;
		std::map<cfsec::CFSecSecFormPKey,
			cfsec::CFSecSecFormBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecSecFormPKey,
			cfsec::CFSecSecFormBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecSecFormBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecSecFormBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecSecFormBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecFormBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableSecForm()->readDerivedByIdIdx( Authorization,
				cur->getRequiredClusterId(),
				cur->getRequiredSecFormId() );
			rereadCur = cur;
			deleteSecForm( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFSecRamSecFormTable::deleteSecFormBySecAppIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const int32_t argSecAppId )
	{
		cfsec::CFSecSecFormBySecAppIdxKey key;
		key.setRequiredClusterId( argClusterId );
		key.setRequiredSecAppId( argSecAppId );
		deleteSecFormBySecAppIdx( Authorization, &key );
	}

	void CFSecRamSecFormTable::deleteSecFormBySecAppIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecFormBySecAppIdxKey* argKey )
	{
		cfsec::CFSecSecFormBuff* cur = NULL;
		cfsec::CFSecSecFormBuff* rereadCur = NULL;
		bool anyNotNull = false;
		anyNotNull = true;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfsec::CFSecSecFormBuff*> matchSet;
		std::map<cfsec::CFSecSecFormPKey,
			cfsec::CFSecSecFormBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecSecFormPKey,
			cfsec::CFSecSecFormBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecSecFormBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecSecFormBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecSecFormBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecFormBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableSecForm()->readDerivedByIdIdx( Authorization,
				cur->getRequiredClusterId(),
				cur->getRequiredSecFormId() );
			rereadCur = cur;
			deleteSecForm( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFSecRamSecFormTable::deleteSecFormByUJEEServletIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const int32_t argSecAppId,
			const std::string& argJEEServletMapName )
	{
		cfsec::CFSecSecFormByUJEEServletIdxKey key;
		key.setRequiredClusterId( argClusterId );
		key.setRequiredSecAppId( argSecAppId );
		key.setRequiredJEEServletMapName( argJEEServletMapName );
		deleteSecFormByUJEEServletIdx( Authorization, &key );
	}

	void CFSecRamSecFormTable::deleteSecFormByUJEEServletIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecFormByUJEEServletIdxKey* argKey )
	{
		cfsec::CFSecSecFormBuff* cur = NULL;
		cfsec::CFSecSecFormBuff* rereadCur = NULL;
		bool anyNotNull = false;
		anyNotNull = true;
		anyNotNull = true;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfsec::CFSecSecFormBuff*> matchSet;
		std::map<cfsec::CFSecSecFormPKey,
			cfsec::CFSecSecFormBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecSecFormPKey,
			cfsec::CFSecSecFormBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecSecFormBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecSecFormBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecSecFormBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecFormBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableSecForm()->readDerivedByIdIdx( Authorization,
				cur->getRequiredClusterId(),
				cur->getRequiredSecFormId() );
			rereadCur = cur;
			deleteSecForm( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFSecRamSecFormTable::releasePreparedStatements() {
	}

}
