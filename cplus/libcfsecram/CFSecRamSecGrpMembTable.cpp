
// Description: C++18 Implementation for an in-memory RAM DbIO for SecGrpMemb.

/*
 *	org.msscf.msscf.CFSec
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	This file is part of MSS Code Factory.
 *	
 *	Licensed under the Apache License, Version 2.0 (the "License");
 *	you may not use this file except in compliance with the License.
 *	You may obtain a copy of the License at
 *	
 *	    http://www.apache.org/licenses/LICENSE-2.0
 *	
 *	Unless required by applicable law or agreed to in writing, software
 *	distributed under the License is distributed on an "AS IS" BASIS,
 *	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *	See the License for the specific language governing permissions and
 *	limitations under the License.
 *	
 *	Donations to support MSS Code Factory can be made at
 *	https://www.paypal.com/paypalme2/MarkSobkow
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

	const std::string CFSecRamSecGrpMembTable::CLASS_NAME( "CFSecRamSecGrpMembTable" );

	CFSecRamSecGrpMembTable::CFSecRamSecGrpMembTable( ICFSecSchema* argSchema )
	: cfsec::ICFSecSecGrpMembTable()
	{
		schema = argSchema;
		dictByPKey = new std::map<cfsec::CFSecSecGrpMembPKey, cfsec::CFSecSecGrpMembBuff*>();
		dictByClusterIdx = new std::map<cfsec::CFSecSecGrpMembByClusterIdxKey,
			std::map<cfsec::CFSecSecGrpMembPKey,
				cfsec::CFSecSecGrpMembBuff*>*>();
		dictByGroupIdx = new std::map<cfsec::CFSecSecGrpMembByGroupIdxKey,
			std::map<cfsec::CFSecSecGrpMembPKey,
				cfsec::CFSecSecGrpMembBuff*>*>();
		dictByUserIdx = new std::map<cfsec::CFSecSecGrpMembByUserIdxKey,
			std::map<cfsec::CFSecSecGrpMembPKey,
				cfsec::CFSecSecGrpMembBuff*>*>();
		dictByUUserIdx = new std::map<cfsec::CFSecSecGrpMembByUUserIdxKey, cfsec::CFSecSecGrpMembBuff*>();
	}

	CFSecRamSecGrpMembTable::~CFSecRamSecGrpMembTable() {
		if( dictByClusterIdx != NULL ) {
			for( auto iterDict = dictByClusterIdx->begin(); iterDict != dictByClusterIdx->end(); iterDict ++ ) {
				delete iterDict->second;
				iterDict->second = NULL;
			}
			delete dictByClusterIdx;
			dictByClusterIdx = NULL;
		}
		if( dictByGroupIdx != NULL ) {
			for( auto iterDict = dictByGroupIdx->begin(); iterDict != dictByGroupIdx->end(); iterDict ++ ) {
				delete iterDict->second;
				iterDict->second = NULL;
			}
			delete dictByGroupIdx;
			dictByGroupIdx = NULL;
		}
		if( dictByUserIdx != NULL ) {
			for( auto iterDict = dictByUserIdx->begin(); iterDict != dictByUserIdx->end(); iterDict ++ ) {
				delete iterDict->second;
				iterDict->second = NULL;
			}
			delete dictByUserIdx;
			dictByUserIdx = NULL;
		}
		if( dictByUUserIdx != NULL ) {
			delete dictByUUserIdx;
			dictByUUserIdx = NULL;
		}
		if( dictByPKey != NULL ) {
			cfsec::CFSecSecGrpMembBuff* elt;
			std::map<cfsec::CFSecSecGrpMembPKey,
				cfsec::CFSecSecGrpMembBuff*>::iterator end = dictByPKey->end();
			for( std::map<cfsec::CFSecSecGrpMembPKey,
					cfsec::CFSecSecGrpMembBuff*>::iterator cur = dictByPKey->begin();
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

	cfsec::CFSecSecGrpMembBuff* CFSecRamSecGrpMembTable::createSecGrpMemb( const cfsec::CFSecAuthorization* Authorization,
		cfsec::CFSecSecGrpMembBuff* Buff )
	{
		static const std::string S_ProcName( "createSecGrpMemb" );
		cfsec::CFSecSecGrpMembPKey pkey;
		pkey.setRequiredClusterId( Buff->getRequiredClusterId() );
		pkey.setRequiredSecGrpMembId( dynamic_cast<CFSecRamClusterTable*>( schema->getTableCluster() )->nextSecGrpMembIdGen( Authorization,
			Buff->getRequiredClusterId() ) );
		Buff->setRequiredClusterId( pkey.getRequiredClusterId() );
		Buff->setRequiredSecGrpMembId( pkey.getRequiredSecGrpMembId() );
		cfsec::CFSecSecGrpMembByClusterIdxKey keyClusterIdx;
		keyClusterIdx.setRequiredClusterId( Buff->getRequiredClusterId() );
		cfsec::CFSecSecGrpMembByGroupIdxKey keyGroupIdx;
		keyGroupIdx.setRequiredClusterId( Buff->getRequiredClusterId() );
		keyGroupIdx.setRequiredSecGroupId( Buff->getRequiredSecGroupId() );
		cfsec::CFSecSecGrpMembByUserIdxKey keyUserIdx;
		keyUserIdx.setRequiredSecUserId( Buff->getRequiredSecUserId() );
		cfsec::CFSecSecGrpMembByUUserIdxKey keyUUserIdx;
		keyUUserIdx.setRequiredClusterId( Buff->getRequiredClusterId() );
		keyUUserIdx.setRequiredSecGroupId( Buff->getRequiredSecGroupId() );
		keyUUserIdx.setRequiredSecUserId( Buff->getRequiredSecUserId() );
		// Validate unique indexes
		auto searchDictByPKey = dictByPKey->find( pkey );
		if( searchDictByPKey != dictByPKey->end() ) {
			delete Buff;
			std::string Msg( "Duplicate primary key detected " + pkey.toString() );
			throw cflib::CFLibPrimaryKeyNotNewException( CLASS_NAME, S_ProcName, Msg );
		}

		auto searchDictByUUserIdx = dictByUUserIdx->find( keyUUserIdx );
		if( searchDictByUUserIdx != dictByUUserIdx->end() ) {
			std::string Msg( "Duplicate key detected for index SecGrpMembUUserIdx " + keyUUserIdx.toString() );
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
					std::string Msg( "Could not resolve Owner relationship SecGrpMembCluster to table Cluster" );
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
				cfsec::CFSecSecGroupBuff* chk = dynamic_cast<cfsec::CFSecSecGroupBuff*>( schema->getTableSecGroup()->readDerivedByIdIdx( Authorization,
						Buff->getRequiredClusterId(),
						Buff->getRequiredSecGroupId() ) );
				if( chk == NULL ) {
					delete Buff;
					std::string Msg( "Could not resolve Container relationship SecGrpMembGroup to table SecGroup" );
					throw cflib::CFLibUnresolvedRelationException( CLASS_NAME,
						S_ProcName,
						Msg );
				}
				delete chk;
				chk = NULL;
			}
		}

		// Proceed with adding the new record
		cfsec::CFSecSecGrpMembBuff* buff = Buff;
		buff->setRequiredRevision( 1 );
		dictByPKey->insert( std::map<cfsec::CFSecSecGrpMembPKey, cfsec::CFSecSecGrpMembBuff*>::value_type( pkey, buff ) );

		std::map<cfsec::CFSecSecGrpMembPKey, cfsec::CFSecSecGrpMembBuff*>* subdictClusterIdx;
		auto searchDictByClusterIdx = dictByClusterIdx->find( keyClusterIdx );
		if( searchDictByClusterIdx != dictByClusterIdx->end() ) {
			subdictClusterIdx = searchDictByClusterIdx->second;
		}
		else {
			subdictClusterIdx = new std::map<cfsec::CFSecSecGrpMembPKey, cfsec::CFSecSecGrpMembBuff*>();
			dictByClusterIdx->insert( std::map<cfsec::CFSecSecGrpMembByClusterIdxKey,
				std::map<cfsec::CFSecSecGrpMembPKey,
					cfsec::CFSecSecGrpMembBuff*>*>::value_type( keyClusterIdx, subdictClusterIdx ) );
		}
		subdictClusterIdx->insert( std::map<cfsec::CFSecSecGrpMembPKey, cfsec::CFSecSecGrpMembBuff*>::value_type( pkey, buff ) );

		std::map<cfsec::CFSecSecGrpMembPKey, cfsec::CFSecSecGrpMembBuff*>* subdictGroupIdx;
		auto searchDictByGroupIdx = dictByGroupIdx->find( keyGroupIdx );
		if( searchDictByGroupIdx != dictByGroupIdx->end() ) {
			subdictGroupIdx = searchDictByGroupIdx->second;
		}
		else {
			subdictGroupIdx = new std::map<cfsec::CFSecSecGrpMembPKey, cfsec::CFSecSecGrpMembBuff*>();
			dictByGroupIdx->insert( std::map<cfsec::CFSecSecGrpMembByGroupIdxKey,
				std::map<cfsec::CFSecSecGrpMembPKey,
					cfsec::CFSecSecGrpMembBuff*>*>::value_type( keyGroupIdx, subdictGroupIdx ) );
		}
		subdictGroupIdx->insert( std::map<cfsec::CFSecSecGrpMembPKey, cfsec::CFSecSecGrpMembBuff*>::value_type( pkey, buff ) );

		std::map<cfsec::CFSecSecGrpMembPKey, cfsec::CFSecSecGrpMembBuff*>* subdictUserIdx;
		auto searchDictByUserIdx = dictByUserIdx->find( keyUserIdx );
		if( searchDictByUserIdx != dictByUserIdx->end() ) {
			subdictUserIdx = searchDictByUserIdx->second;
		}
		else {
			subdictUserIdx = new std::map<cfsec::CFSecSecGrpMembPKey, cfsec::CFSecSecGrpMembBuff*>();
			dictByUserIdx->insert( std::map<cfsec::CFSecSecGrpMembByUserIdxKey,
				std::map<cfsec::CFSecSecGrpMembPKey,
					cfsec::CFSecSecGrpMembBuff*>*>::value_type( keyUserIdx, subdictUserIdx ) );
		}
		subdictUserIdx->insert( std::map<cfsec::CFSecSecGrpMembPKey, cfsec::CFSecSecGrpMembBuff*>::value_type( pkey, buff ) );

		dictByUUserIdx->insert( std::map<cfsec::CFSecSecGrpMembByUUserIdxKey, cfsec::CFSecSecGrpMembBuff*>::value_type( keyUUserIdx, buff ) );

		// The top level code has to clone the final buffer. The one passed in is now part of the persistent storage.
		if( buff->getClassCode() == cfsec::CFSecSecGrpMembBuff::CLASS_CODE ) {
			buff = dynamic_cast<cfsec::CFSecSecGrpMembBuff*>( buff->clone() );
		}
		return( buff );
	}

	cfsec::CFSecSecGrpMembBuff* CFSecRamSecGrpMembTable::readDerived( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecGrpMembPKey* PKey )
	{
		static const std::string S_ProcName( "readDerived" );
		cfsec::CFSecSecGrpMembBuff* buff;
		auto searchDictByPKey = dictByPKey->find( *PKey );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfsec::CFSecSecGrpMembBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecSecGrpMembBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfsec::CFSecSecGrpMembBuff* CFSecRamSecGrpMembTable::lockDerived( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecGrpMembPKey* PKey )
	{
		static const std::string S_ProcName( "lockDerived" );
		cfsec::CFSecSecGrpMembBuff* buff;
		auto searchDictByPKey = dictByPKey->find( *PKey );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfsec::CFSecSecGrpMembBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecSecGrpMembBuff*>( buff->clone() );
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

	std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*> CFSecRamSecGrpMembTable::readAllDerived( const cfsec::CFSecAuthorization* Authorization ) {
		static const std::string S_ProcName( "readAllDerived" );
		std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*> retVec;
		std::map<cfsec::CFSecSecGrpMembPKey,
			cfsec::CFSecSecGrpMembBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecSecGrpMembPKey,
			cfsec::CFSecSecGrpMembBuff*>::iterator end = dictByPKey->end();
		cfsec::CFSecSecGrpMembBuff* clone;
		while( iter != end ) {
			clone = dynamic_cast<cfsec::CFSecSecGrpMembBuff*>( iter->second->clone() );
			retVec.push_back( clone );
			iter ++;
		}
		return( retVec );
	}

	std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*> CFSecRamSecGrpMembTable::readDerivedByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId )
	{
		static const std::string S_ProcName( "readDerivedByClusterIdx" );
		cfsec::CFSecSecGrpMembByClusterIdxKey key;
		key.setRequiredClusterId( ClusterId );
		std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*> recVec;
		cfsec::CFSecSecGrpMembBuff* clone;
		auto searchDictByClusterIdx = dictByClusterIdx->find( key );
		if( searchDictByClusterIdx != dictByClusterIdx->end() ) {
			std::map<cfsec::CFSecSecGrpMembPKey,
				 cfsec::CFSecSecGrpMembBuff*>* subdictClusterIdx = searchDictByClusterIdx->second;
			std::map<cfsec::CFSecSecGrpMembPKey,
				cfsec::CFSecSecGrpMembBuff*>::iterator iter = subdictClusterIdx->begin();
			std::map<cfsec::CFSecSecGrpMembPKey,
				cfsec::CFSecSecGrpMembBuff*>::iterator end = subdictClusterIdx->end();
			while( iter != end ) {
				clone = dynamic_cast<cfsec::CFSecSecGrpMembBuff*>( iter->second->clone() );
				recVec.push_back( clone );
				iter ++;
			}
		}
		return( recVec );
	}

	std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*> CFSecRamSecGrpMembTable::readDerivedByGroupIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecGroupId )
	{
		static const std::string S_ProcName( "readDerivedByGroupIdx" );
		cfsec::CFSecSecGrpMembByGroupIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredSecGroupId( SecGroupId );
		std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*> recVec;
		cfsec::CFSecSecGrpMembBuff* clone;
		auto searchDictByGroupIdx = dictByGroupIdx->find( key );
		if( searchDictByGroupIdx != dictByGroupIdx->end() ) {
			std::map<cfsec::CFSecSecGrpMembPKey,
				 cfsec::CFSecSecGrpMembBuff*>* subdictGroupIdx = searchDictByGroupIdx->second;
			std::map<cfsec::CFSecSecGrpMembPKey,
				cfsec::CFSecSecGrpMembBuff*>::iterator iter = subdictGroupIdx->begin();
			std::map<cfsec::CFSecSecGrpMembPKey,
				cfsec::CFSecSecGrpMembBuff*>::iterator end = subdictGroupIdx->end();
			while( iter != end ) {
				clone = dynamic_cast<cfsec::CFSecSecGrpMembBuff*>( iter->second->clone() );
				recVec.push_back( clone );
				iter ++;
			}
		}
		return( recVec );
	}

	std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*> CFSecRamSecGrpMembTable::readDerivedByUserIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId )
	{
		static const std::string S_ProcName( "readDerivedByUserIdx" );
		cfsec::CFSecSecGrpMembByUserIdxKey key;
		key.setRequiredSecUserId( SecUserId );
		std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*> recVec;
		cfsec::CFSecSecGrpMembBuff* clone;
		auto searchDictByUserIdx = dictByUserIdx->find( key );
		if( searchDictByUserIdx != dictByUserIdx->end() ) {
			std::map<cfsec::CFSecSecGrpMembPKey,
				 cfsec::CFSecSecGrpMembBuff*>* subdictUserIdx = searchDictByUserIdx->second;
			std::map<cfsec::CFSecSecGrpMembPKey,
				cfsec::CFSecSecGrpMembBuff*>::iterator iter = subdictUserIdx->begin();
			std::map<cfsec::CFSecSecGrpMembPKey,
				cfsec::CFSecSecGrpMembBuff*>::iterator end = subdictUserIdx->end();
			while( iter != end ) {
				clone = dynamic_cast<cfsec::CFSecSecGrpMembBuff*>( iter->second->clone() );
				recVec.push_back( clone );
				iter ++;
			}
		}
		return( recVec );
	}

	cfsec::CFSecSecGrpMembBuff* CFSecRamSecGrpMembTable::readDerivedByUUserIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecGroupId,
			const uuid_ptr_t SecUserId )
	{
		static const std::string S_ProcName( "readDerivedByUUserIdx" );
		cfsec::CFSecSecGrpMembByUUserIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredSecGroupId( SecGroupId );
		key.setRequiredSecUserId( SecUserId );
		cfsec::CFSecSecGrpMembBuff* buff;
		auto searchDictByUUserIdx = dictByUUserIdx->find( key );
		if( searchDictByUUserIdx != dictByUUserIdx->end() ) {
			buff = dynamic_cast<cfsec::CFSecSecGrpMembBuff*>( searchDictByUUserIdx->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecSecGrpMembBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfsec::CFSecSecGrpMembBuff* CFSecRamSecGrpMembTable::readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t SecGrpMembId )
	{
		static const std::string S_ProcName( "readDerivedByIdIdx" );
		cfsec::CFSecSecGrpMembPKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredSecGrpMembId( SecGrpMembId );
		cfsec::CFSecSecGrpMembBuff* buff;
		auto searchDictByPKey = dictByPKey->find( key );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfsec::CFSecSecGrpMembBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecSecGrpMembBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfsec::CFSecSecGrpMembBuff* CFSecRamSecGrpMembTable::readBuff( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecGrpMembPKey* PKey )
	{
		static const std::string S_ProcName( "readBuff" );
		cfsec::CFSecSecGrpMembBuff* buff = readDerived( Authorization, PKey );
		if( buff != NULL ) {
			if( buff->getClassCode() != cfsec::CFSecSecGrpMembBuff::CLASS_CODE ) {
				delete buff;
				buff = NULL;
			}
		}
		return( dynamic_cast<cfsec::CFSecSecGrpMembBuff*>( buff ) );
	}

	cfsec::CFSecSecGrpMembBuff* CFSecRamSecGrpMembTable::lockBuff( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecGrpMembPKey* PKey )
	{
		static const std::string S_ProcName( "lockBuff" );
		cfsec::CFSecSecGrpMembBuff* buff = lockDerived( Authorization, PKey );
		return( dynamic_cast<cfsec::CFSecSecGrpMembBuff*>( buff ) );
	}

	std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*> CFSecRamSecGrpMembTable::readAllBuff( const cfsec::CFSecAuthorization* Authorization )
	{
		static const std::string S_ProcName( "readAllBuff" );
		cfsec::CFSecSecGrpMembBuff* buff;
		std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*> filteredList;
		std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*> buffList = readAllDerived( Authorization );
		std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfsec::CFSecSecGrpMembBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfsec::CFSecSecGrpMembBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*> CFSecRamSecGrpMembTable::pageAllBuff( const cfsec::CFSecAuthorization* Authorization,
			const int64_t* priorClusterId,
			const int64_t* priorSecGrpMembId )
	{
		static const std::string S_ProcName( "pageAllBuff" );
		// MSS TODO WORKING
		throw cflib::CFLibNotImplementedYetException( CLASS_NAME, S_ProcName );
	}

	cfsec::CFSecSecGrpMembBuff* CFSecRamSecGrpMembTable::readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t SecGrpMembId )
	{
		static const std::string S_ProcName( "readBuffByIdIdx" );
		cfsec::CFSecSecGrpMembBuff* buff = readDerivedByIdIdx( Authorization,
			ClusterId,
			SecGrpMembId );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfsec::CFSecSecGrpMembBuff::CLASS_CODE ) {
			return( dynamic_cast<cfsec::CFSecSecGrpMembBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*> CFSecRamSecGrpMembTable::readBuffByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId )
	{
		static const std::string S_ProcName( "readBuffByClusterIdx" );
		cfsec::CFSecSecGrpMembBuff* buff;
		std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*> filteredList;
		std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*> buffList = readDerivedByClusterIdx( Authorization,
			ClusterId );
		std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfsec::CFSecSecGrpMembBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfsec::CFSecSecGrpMembBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*> CFSecRamSecGrpMembTable::readBuffByGroupIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecGroupId )
	{
		static const std::string S_ProcName( "readBuffByGroupIdx" );
		cfsec::CFSecSecGrpMembBuff* buff;
		std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*> filteredList;
		std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*> buffList = readDerivedByGroupIdx( Authorization,
			ClusterId,
			SecGroupId );
		std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfsec::CFSecSecGrpMembBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfsec::CFSecSecGrpMembBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*> CFSecRamSecGrpMembTable::readBuffByUserIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId )
	{
		static const std::string S_ProcName( "readBuffByUserIdx" );
		cfsec::CFSecSecGrpMembBuff* buff;
		std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*> filteredList;
		std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*> buffList = readDerivedByUserIdx( Authorization,
			SecUserId );
		std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfsec::CFSecSecGrpMembBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfsec::CFSecSecGrpMembBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	cfsec::CFSecSecGrpMembBuff* CFSecRamSecGrpMembTable::readBuffByUUserIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecGroupId,
			const uuid_ptr_t SecUserId )
	{
		static const std::string S_ProcName( "readBuffByUUserIdx" );
		cfsec::CFSecSecGrpMembBuff* buff = readDerivedByUUserIdx( Authorization,
			ClusterId,
			SecGroupId,
			SecUserId );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfsec::CFSecSecGrpMembBuff::CLASS_CODE ) {
			return( dynamic_cast<cfsec::CFSecSecGrpMembBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*> CFSecRamSecGrpMembTable::pageBuffByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t* priorClusterId,
			const int64_t* priorSecGrpMembId )
	{
		static const std::string S_ProcName( "pageBuffByClusterIdx" );
		// MSS TODO WORKING
		throw cflib::CFLibNotImplementedYetException( CLASS_NAME, S_ProcName );
	}

	std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*> CFSecRamSecGrpMembTable::pageBuffByGroupIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecGroupId,
			const int64_t* priorClusterId,
			const int64_t* priorSecGrpMembId )
	{
		static const std::string S_ProcName( "pageBuffByGroupIdx" );
		// MSS TODO WORKING
		throw cflib::CFLibNotImplementedYetException( CLASS_NAME, S_ProcName );
	}

	std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*> CFSecRamSecGrpMembTable::pageBuffByUserIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId,
			const int64_t* priorClusterId,
			const int64_t* priorSecGrpMembId )
	{
		static const std::string S_ProcName( "pageBuffByUserIdx" );
		// MSS TODO WORKING
		throw cflib::CFLibNotImplementedYetException( CLASS_NAME, S_ProcName );
	}

	cfsec::CFSecSecGrpMembBuff* CFSecRamSecGrpMembTable::updateSecGrpMemb( const cfsec::CFSecAuthorization* Authorization,
		cfsec::CFSecSecGrpMembBuff* Buff )
	{
		static const std::string S_ProcName( "updateSecGrpMemb" );
		cfsec::CFSecSecGrpMembPKey pkey;
		pkey.setRequiredClusterId( Buff->getRequiredClusterId() );
		pkey.setRequiredSecGrpMembId( Buff->getRequiredSecGrpMembId() );

		// Search for existing buffer

		auto searchExisting = dictByPKey->find( pkey );
		if( searchExisting == dictByPKey->end() ) {
			delete Buff;
			std::string Msg( "Existing record not found in SecGrpMemb for key " + pkey.toString() );
			throw cflib::CFLibStaleCacheDetectedException( CLASS_NAME,
				S_ProcName,
				Msg );
		}

		cfsec::CFSecSecGrpMembBuff* existing = searchExisting->second;

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
			std::string Msg( "Collision detected for SecGrpMemb primary key " );
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
		cfsec::CFSecSecGrpMembByClusterIdxKey existingKeyClusterIdx;
		existingKeyClusterIdx.setRequiredClusterId( existing->getRequiredClusterId() );
		cfsec::CFSecSecGrpMembByClusterIdxKey newKeyClusterIdx;
		newKeyClusterIdx.setRequiredClusterId( Buff->getRequiredClusterId() );
		cfsec::CFSecSecGrpMembByGroupIdxKey existingKeyGroupIdx;
		existingKeyGroupIdx.setRequiredClusterId( existing->getRequiredClusterId() );
		existingKeyGroupIdx.setRequiredSecGroupId( existing->getRequiredSecGroupId() );
		cfsec::CFSecSecGrpMembByGroupIdxKey newKeyGroupIdx;
		newKeyGroupIdx.setRequiredClusterId( Buff->getRequiredClusterId() );
		newKeyGroupIdx.setRequiredSecGroupId( Buff->getRequiredSecGroupId() );
		cfsec::CFSecSecGrpMembByUserIdxKey existingKeyUserIdx;
		existingKeyUserIdx.setRequiredSecUserId( existing->getRequiredSecUserId() );
		cfsec::CFSecSecGrpMembByUserIdxKey newKeyUserIdx;
		newKeyUserIdx.setRequiredSecUserId( Buff->getRequiredSecUserId() );
		cfsec::CFSecSecGrpMembByUUserIdxKey existingKeyUUserIdx;
		existingKeyUUserIdx.setRequiredClusterId( existing->getRequiredClusterId() );
		existingKeyUUserIdx.setRequiredSecGroupId( existing->getRequiredSecGroupId() );
		existingKeyUUserIdx.setRequiredSecUserId( existing->getRequiredSecUserId() );
		cfsec::CFSecSecGrpMembByUUserIdxKey newKeyUUserIdx;
		newKeyUUserIdx.setRequiredClusterId( Buff->getRequiredClusterId() );
		newKeyUUserIdx.setRequiredSecGroupId( Buff->getRequiredSecGroupId() );
		newKeyUUserIdx.setRequiredSecUserId( Buff->getRequiredSecUserId() );
		// Check unique indexes

		if( existingKeyUUserIdx != newKeyUUserIdx ) {
			auto searchDictByUUserIdx = dictByUUserIdx->find( newKeyUUserIdx );
			if( searchDictByUUserIdx != dictByUUserIdx->end() ) {
				std::string Msg( "Duplicate key detected for index SecGrpMembUUserIdx " + newKeyUUserIdx.toString() );
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
					std::string Msg( "Could not resolve Owner relationship SecGrpMembCluster to table Cluster" );
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
				cfsec::CFSecSecGroupBuff* chk = dynamic_cast<cfsec::CFSecSecGroupBuff*>( schema->getTableSecGroup()->readDerivedByIdIdx( Authorization,
						Buff->getRequiredClusterId(),
						Buff->getRequiredSecGroupId() ) );
				if( chk == NULL ) {
					delete Buff;
					std::string Msg( "Could not resolve Container relationship SecGrpMembGroup to table SecGroup" );
					throw cflib::CFLibUnresolvedRelationException( CLASS_NAME,
						S_ProcName,
						Msg );
				}
				delete chk;
				chk = NULL;
			}
		}

		// Update is valid
		std::map<cfsec::CFSecSecGrpMembPKey, cfsec::CFSecSecGrpMembBuff*>* subdict;
		auto removalDictByPKey = dictByPKey->find( pkey );
		if( removalDictByPKey != dictByPKey->end() ) {
			dictByPKey->erase( removalDictByPKey );
		}
		// Copy edited buffer to existing persistent buffer

		if( Buff->getClassCode() != cfsec::CFSecSecGrpMembBuff::CLASS_CODE ) {
			const static std::string S_IsNotA( " is not a cfsec::CFSecSecGrpMembBuff" );
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

		dictByPKey->insert( std::map<cfsec::CFSecSecGrpMembPKey, cfsec::CFSecSecGrpMembBuff*>::value_type( pkey, existing ) );

		std::map<cfsec::CFSecSecGrpMembPKey,
			 cfsec::CFSecSecGrpMembBuff*>* subdictClusterIdx;
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
			subdictClusterIdx = new std::map<cfsec::CFSecSecGrpMembPKey, cfsec::CFSecSecGrpMembBuff*>();
			dictByClusterIdx->insert( std::map<cfsec::CFSecSecGrpMembByClusterIdxKey,
				std::map<cfsec::CFSecSecGrpMembPKey,
					cfsec::CFSecSecGrpMembBuff*>*>::value_type( newKeyClusterIdx, subdictClusterIdx ) );
		}
		subdictClusterIdx->insert( std::map<cfsec::CFSecSecGrpMembPKey, cfsec::CFSecSecGrpMembBuff*>::value_type( pkey, existing ) );

		std::map<cfsec::CFSecSecGrpMembPKey,
			 cfsec::CFSecSecGrpMembBuff*>* subdictGroupIdx;
		auto searchDictByGroupIdx = dictByGroupIdx->find( existingKeyGroupIdx );
		if( searchDictByGroupIdx != dictByGroupIdx->end() ) {
			subdictGroupIdx = searchDictByGroupIdx->second;
			auto searchSubDict = subdictGroupIdx->find( pkey );
			if( searchSubDict != subdictGroupIdx->end() ) {
				subdictGroupIdx->erase( searchSubDict );
			}
			if( subdictGroupIdx->size() <= 0 ) {
				delete subdictGroupIdx;
				dictByGroupIdx->erase( searchDictByGroupIdx );
			}
			subdictGroupIdx = NULL;
		}
		auto searchNewKeyDictByGroupIdx = dictByGroupIdx->find( newKeyGroupIdx );
		if( searchNewKeyDictByGroupIdx != dictByGroupIdx->end() ) {
			subdictGroupIdx = searchNewKeyDictByGroupIdx->second;
		}
		else {
			subdictGroupIdx = new std::map<cfsec::CFSecSecGrpMembPKey, cfsec::CFSecSecGrpMembBuff*>();
			dictByGroupIdx->insert( std::map<cfsec::CFSecSecGrpMembByGroupIdxKey,
				std::map<cfsec::CFSecSecGrpMembPKey,
					cfsec::CFSecSecGrpMembBuff*>*>::value_type( newKeyGroupIdx, subdictGroupIdx ) );
		}
		subdictGroupIdx->insert( std::map<cfsec::CFSecSecGrpMembPKey, cfsec::CFSecSecGrpMembBuff*>::value_type( pkey, existing ) );

		std::map<cfsec::CFSecSecGrpMembPKey,
			 cfsec::CFSecSecGrpMembBuff*>* subdictUserIdx;
		auto searchDictByUserIdx = dictByUserIdx->find( existingKeyUserIdx );
		if( searchDictByUserIdx != dictByUserIdx->end() ) {
			subdictUserIdx = searchDictByUserIdx->second;
			auto searchSubDict = subdictUserIdx->find( pkey );
			if( searchSubDict != subdictUserIdx->end() ) {
				subdictUserIdx->erase( searchSubDict );
			}
			if( subdictUserIdx->size() <= 0 ) {
				delete subdictUserIdx;
				dictByUserIdx->erase( searchDictByUserIdx );
			}
			subdictUserIdx = NULL;
		}
		auto searchNewKeyDictByUserIdx = dictByUserIdx->find( newKeyUserIdx );
		if( searchNewKeyDictByUserIdx != dictByUserIdx->end() ) {
			subdictUserIdx = searchNewKeyDictByUserIdx->second;
		}
		else {
			subdictUserIdx = new std::map<cfsec::CFSecSecGrpMembPKey, cfsec::CFSecSecGrpMembBuff*>();
			dictByUserIdx->insert( std::map<cfsec::CFSecSecGrpMembByUserIdxKey,
				std::map<cfsec::CFSecSecGrpMembPKey,
					cfsec::CFSecSecGrpMembBuff*>*>::value_type( newKeyUserIdx, subdictUserIdx ) );
		}
		subdictUserIdx->insert( std::map<cfsec::CFSecSecGrpMembPKey, cfsec::CFSecSecGrpMembBuff*>::value_type( pkey, existing ) );

		auto removalDictByUUserIdx = dictByUUserIdx->find( existingKeyUUserIdx );
		if( removalDictByUUserIdx != dictByUUserIdx->end() ) {
			dictByUUserIdx->erase( removalDictByUUserIdx );
		}
		dictByUUserIdx->insert( std::map<cfsec::CFSecSecGrpMembByUUserIdxKey, cfsec::CFSecSecGrpMembBuff*>::value_type( newKeyUUserIdx, existing ) );


		// The top level code has to clean up the memory buffer that was passed in, and return a clone
		// of the copy that existing buffer that is attached to the RAM storage.  All other cases
		// return the existing buffer.

		cfsec::CFSecSecGrpMembBuff* buff;
		if( existing->getClassCode() == cfsec::CFSecSecGrpMembBuff::CLASS_CODE ) {
			delete Buff;
			Buff = NULL;
			buff = dynamic_cast<cfsec::CFSecSecGrpMembBuff*>( existing->clone() );
		}
		else {
			buff = existing;
		}
		return( buff );
	}

	void CFSecRamSecGrpMembTable::deleteSecGrpMemb( const cfsec::CFSecAuthorization* Authorization,
		cfsec::CFSecSecGrpMembBuff* Buff )
	{
		static const std::string S_ProcName( "deleteSecGrpMemb" );
		static const std::string S_Prev( "prev" );
		classcode_t classCode;
		cfsec::CFSecSecGrpMembPKey pkey;
		pkey.setRequiredClusterId( Buff->getRequiredClusterId() );
		pkey.setRequiredSecGrpMembId( Buff->getRequiredSecGrpMembId() );
		auto searchExisting = dictByPKey->find( pkey );
		if( searchExisting == dictByPKey->end() ) {
			return;
		}
		cfsec::CFSecSecGrpMembBuff* existing = searchExisting->second;
		cfsec::CFSecSecGrpMembByClusterIdxKey keyClusterIdx;
		keyClusterIdx.setRequiredClusterId( existing->getRequiredClusterId() );
		cfsec::CFSecSecGrpMembByGroupIdxKey keyGroupIdx;
		keyGroupIdx.setRequiredClusterId( existing->getRequiredClusterId() );
		keyGroupIdx.setRequiredSecGroupId( existing->getRequiredSecGroupId() );
		cfsec::CFSecSecGrpMembByUserIdxKey keyUserIdx;
		keyUserIdx.setRequiredSecUserId( existing->getRequiredSecUserId() );
		cfsec::CFSecSecGrpMembByUUserIdxKey keyUUserIdx;
		keyUUserIdx.setRequiredClusterId( existing->getRequiredClusterId() );
		keyUUserIdx.setRequiredSecGroupId( existing->getRequiredSecGroupId() );
		keyUUserIdx.setRequiredSecUserId( existing->getRequiredSecUserId() );
		// Validate reverse foreign keys

		// Delete is valid
		std::map<cfsec::CFSecSecGrpMembPKey, cfsec::CFSecSecGrpMembBuff*>* subdict;

		auto searchDictByPKey = dictByPKey->find( pkey );
		if( searchDictByPKey != dictByPKey->end() ) {
			dictByPKey->erase( searchDictByPKey );
		}

		auto searchDictByClusterIdx = dictByClusterIdx->find( keyClusterIdx );
		if( searchDictByClusterIdx != dictByClusterIdx->end() ) {
			std::map<cfsec::CFSecSecGrpMembPKey,
				 cfsec::CFSecSecGrpMembBuff*>* subdictClusterIdx = searchDictByClusterIdx->second;
			auto searchSubDict = subdictClusterIdx->find( pkey );
			if( searchSubDict != subdictClusterIdx->end() ) {
				subdictClusterIdx->erase( searchSubDict );
			}
			subdictClusterIdx = NULL;
		}

		auto searchDictByGroupIdx = dictByGroupIdx->find( keyGroupIdx );
		if( searchDictByGroupIdx != dictByGroupIdx->end() ) {
			std::map<cfsec::CFSecSecGrpMembPKey,
				 cfsec::CFSecSecGrpMembBuff*>* subdictGroupIdx = searchDictByGroupIdx->second;
			auto searchSubDict = subdictGroupIdx->find( pkey );
			if( searchSubDict != subdictGroupIdx->end() ) {
				subdictGroupIdx->erase( searchSubDict );
			}
			subdictGroupIdx = NULL;
		}

		auto searchDictByUserIdx = dictByUserIdx->find( keyUserIdx );
		if( searchDictByUserIdx != dictByUserIdx->end() ) {
			std::map<cfsec::CFSecSecGrpMembPKey,
				 cfsec::CFSecSecGrpMembBuff*>* subdictUserIdx = searchDictByUserIdx->second;
			auto searchSubDict = subdictUserIdx->find( pkey );
			if( searchSubDict != subdictUserIdx->end() ) {
				subdictUserIdx->erase( searchSubDict );
			}
			subdictUserIdx = NULL;
		}

		auto searchDictByUUserIdx = dictByUUserIdx->find( keyUUserIdx );
		if( searchDictByUUserIdx != dictByUUserIdx->end() ) {
			dictByUUserIdx->erase( searchDictByUUserIdx );
		}

		if( existing != NULL ) {
			delete existing;
			existing = NULL;
		}
	}

	void CFSecRamSecGrpMembTable::deleteSecGrpMembByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const int64_t argSecGrpMembId )
	{
		cfsec::CFSecSecGrpMembPKey key;
		key.setRequiredClusterId( argClusterId );
		key.setRequiredSecGrpMembId( argSecGrpMembId );
		deleteSecGrpMembByIdIdx( Authorization, &key );
	}

	void CFSecRamSecGrpMembTable::deleteSecGrpMembByIdIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecGrpMembPKey* argKey )
	{
		bool anyNotNull = false;
		anyNotNull = true;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		cfsec::CFSecSecGrpMembBuff* cur = NULL;
		cfsec::CFSecSecGrpMembBuff* rereadCur = NULL;
		std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*> matchSet;
		std::map<cfsec::CFSecSecGrpMembPKey,
			cfsec::CFSecSecGrpMembBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecSecGrpMembPKey,
			cfsec::CFSecSecGrpMembBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecSecGrpMembBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecSecGrpMembBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableSecGrpMemb()->readDerivedByIdIdx( Authorization,
				cur->getRequiredClusterId(),
				cur->getRequiredSecGrpMembId() );
			rereadCur = cur;
			deleteSecGrpMemb( Authorization, cur );
			if( rereadCur != NULL ) {
				delete rereadCur;
				rereadCur = NULL;
			}
		}
	}

	void CFSecRamSecGrpMembTable::deleteSecGrpMembByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId )
	{
		cfsec::CFSecSecGrpMembByClusterIdxKey key;
		key.setRequiredClusterId( argClusterId );
		deleteSecGrpMembByClusterIdx( Authorization, &key );
	}

	void CFSecRamSecGrpMembTable::deleteSecGrpMembByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecGrpMembByClusterIdxKey* argKey )
	{
		cfsec::CFSecSecGrpMembBuff* cur = NULL;
		cfsec::CFSecSecGrpMembBuff* rereadCur = NULL;
		bool anyNotNull = false;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*> matchSet;
		std::map<cfsec::CFSecSecGrpMembPKey,
			cfsec::CFSecSecGrpMembBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecSecGrpMembPKey,
			cfsec::CFSecSecGrpMembBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecSecGrpMembBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecSecGrpMembBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableSecGrpMemb()->readDerivedByIdIdx( Authorization,
				cur->getRequiredClusterId(),
				cur->getRequiredSecGrpMembId() );
			rereadCur = cur;
			deleteSecGrpMemb( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFSecRamSecGrpMembTable::deleteSecGrpMembByGroupIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const int32_t argSecGroupId )
	{
		cfsec::CFSecSecGrpMembByGroupIdxKey key;
		key.setRequiredClusterId( argClusterId );
		key.setRequiredSecGroupId( argSecGroupId );
		deleteSecGrpMembByGroupIdx( Authorization, &key );
	}

	void CFSecRamSecGrpMembTable::deleteSecGrpMembByGroupIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecGrpMembByGroupIdxKey* argKey )
	{
		cfsec::CFSecSecGrpMembBuff* cur = NULL;
		cfsec::CFSecSecGrpMembBuff* rereadCur = NULL;
		bool anyNotNull = false;
		anyNotNull = true;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*> matchSet;
		std::map<cfsec::CFSecSecGrpMembPKey,
			cfsec::CFSecSecGrpMembBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecSecGrpMembPKey,
			cfsec::CFSecSecGrpMembBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecSecGrpMembBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecSecGrpMembBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableSecGrpMemb()->readDerivedByIdIdx( Authorization,
				cur->getRequiredClusterId(),
				cur->getRequiredSecGrpMembId() );
			rereadCur = cur;
			deleteSecGrpMemb( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFSecRamSecGrpMembTable::deleteSecGrpMembByUserIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t argSecUserId )
	{
		cfsec::CFSecSecGrpMembByUserIdxKey key;
		key.setRequiredSecUserId( argSecUserId );
		deleteSecGrpMembByUserIdx( Authorization, &key );
	}

	void CFSecRamSecGrpMembTable::deleteSecGrpMembByUserIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecGrpMembByUserIdxKey* argKey )
	{
		cfsec::CFSecSecGrpMembBuff* cur = NULL;
		cfsec::CFSecSecGrpMembBuff* rereadCur = NULL;
		bool anyNotNull = false;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*> matchSet;
		std::map<cfsec::CFSecSecGrpMembPKey,
			cfsec::CFSecSecGrpMembBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecSecGrpMembPKey,
			cfsec::CFSecSecGrpMembBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecSecGrpMembBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecSecGrpMembBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableSecGrpMemb()->readDerivedByIdIdx( Authorization,
				cur->getRequiredClusterId(),
				cur->getRequiredSecGrpMembId() );
			rereadCur = cur;
			deleteSecGrpMemb( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFSecRamSecGrpMembTable::deleteSecGrpMembByUUserIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const int32_t argSecGroupId,
			const uuid_ptr_t argSecUserId )
	{
		cfsec::CFSecSecGrpMembByUUserIdxKey key;
		key.setRequiredClusterId( argClusterId );
		key.setRequiredSecGroupId( argSecGroupId );
		key.setRequiredSecUserId( argSecUserId );
		deleteSecGrpMembByUUserIdx( Authorization, &key );
	}

	void CFSecRamSecGrpMembTable::deleteSecGrpMembByUUserIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecGrpMembByUUserIdxKey* argKey )
	{
		cfsec::CFSecSecGrpMembBuff* cur = NULL;
		cfsec::CFSecSecGrpMembBuff* rereadCur = NULL;
		bool anyNotNull = false;
		anyNotNull = true;
		anyNotNull = true;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*> matchSet;
		std::map<cfsec::CFSecSecGrpMembPKey,
			cfsec::CFSecSecGrpMembBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecSecGrpMembPKey,
			cfsec::CFSecSecGrpMembBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecSecGrpMembBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecSecGrpMembBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableSecGrpMemb()->readDerivedByIdIdx( Authorization,
				cur->getRequiredClusterId(),
				cur->getRequiredSecGrpMembId() );
			rereadCur = cur;
			deleteSecGrpMemb( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFSecRamSecGrpMembTable::releasePreparedStatements() {
	}

}
