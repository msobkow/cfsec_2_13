
// Description: C++18 Implementation for an in-memory RAM DbIO for SecApp.

/*
 *	com.github.msobkow.CFSec
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

	const std::string CFSecRamSecAppTable::CLASS_NAME( "CFSecRamSecAppTable" );

	CFSecRamSecAppTable::CFSecRamSecAppTable( ICFSecSchema* argSchema )
	: cfsec::ICFSecSecAppTable()
	{
		schema = argSchema;
		dictByPKey = new std::map<cfsec::CFSecSecAppPKey, cfsec::CFSecSecAppBuff*>();
		dictByClusterIdx = new std::map<cfsec::CFSecSecAppByClusterIdxKey,
			std::map<cfsec::CFSecSecAppPKey,
				cfsec::CFSecSecAppBuff*>*>();
		dictByUJEEMountIdx = new std::map<cfsec::CFSecSecAppByUJEEMountIdxKey, cfsec::CFSecSecAppBuff*>();
	}

	CFSecRamSecAppTable::~CFSecRamSecAppTable() {
		if( dictByClusterIdx != NULL ) {
			for( auto iterDict = dictByClusterIdx->begin(); iterDict != dictByClusterIdx->end(); iterDict ++ ) {
				delete iterDict->second;
				iterDict->second = NULL;
			}
			delete dictByClusterIdx;
			dictByClusterIdx = NULL;
		}
		if( dictByUJEEMountIdx != NULL ) {
			delete dictByUJEEMountIdx;
			dictByUJEEMountIdx = NULL;
		}
		if( dictByPKey != NULL ) {
			cfsec::CFSecSecAppBuff* elt;
			std::map<cfsec::CFSecSecAppPKey,
				cfsec::CFSecSecAppBuff*>::iterator end = dictByPKey->end();
			for( std::map<cfsec::CFSecSecAppPKey,
					cfsec::CFSecSecAppBuff*>::iterator cur = dictByPKey->begin();
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

	cfsec::CFSecSecAppBuff* CFSecRamSecAppTable::createSecApp( const cfsec::CFSecAuthorization* Authorization,
		cfsec::CFSecSecAppBuff* Buff )
	{
		static const std::string S_ProcName( "createSecApp" );
		cfsec::CFSecSecAppPKey pkey;
		pkey.setRequiredClusterId( Buff->getRequiredClusterId() );
		pkey.setRequiredSecAppId( dynamic_cast<CFSecRamClusterTable*>( schema->getTableCluster() )->nextSecAppIdGen( Authorization,
			Buff->getRequiredClusterId() ) );
		Buff->setRequiredClusterId( pkey.getRequiredClusterId() );
		Buff->setRequiredSecAppId( pkey.getRequiredSecAppId() );
		cfsec::CFSecSecAppByClusterIdxKey keyClusterIdx;
		keyClusterIdx.setRequiredClusterId( Buff->getRequiredClusterId() );
		cfsec::CFSecSecAppByUJEEMountIdxKey keyUJEEMountIdx;
		keyUJEEMountIdx.setRequiredClusterId( Buff->getRequiredClusterId() );
		keyUJEEMountIdx.setRequiredJEEMountName( Buff->getRequiredJEEMountName() );
		// Validate unique indexes
		auto searchDictByPKey = dictByPKey->find( pkey );
		if( searchDictByPKey != dictByPKey->end() ) {
			delete Buff;
			std::string Msg( "Duplicate primary key detected " + pkey.toString() );
			throw cflib::CFLibPrimaryKeyNotNewException( CLASS_NAME, S_ProcName, Msg );
		}

		auto searchDictByUJEEMountIdx = dictByUJEEMountIdx->find( keyUJEEMountIdx );
		if( searchDictByUJEEMountIdx != dictByUJEEMountIdx->end() ) {
			std::string Msg( "Duplicate key detected for index SecAppUJEEMountIdx " + keyUJEEMountIdx.toString() );
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
					std::string Msg( "Could not resolve Container relationship SecAppCluster to table Cluster" );
					throw cflib::CFLibUnresolvedRelationException( CLASS_NAME,
						S_ProcName,
						Msg );
				}
				delete chk;
				chk = NULL;
			}
		}

		// Proceed with adding the new record
		cfsec::CFSecSecAppBuff* buff = Buff;
		buff->setRequiredRevision( 1 );
		dictByPKey->insert( std::map<cfsec::CFSecSecAppPKey, cfsec::CFSecSecAppBuff*>::value_type( pkey, buff ) );

		std::map<cfsec::CFSecSecAppPKey, cfsec::CFSecSecAppBuff*>* subdictClusterIdx;
		auto searchDictByClusterIdx = dictByClusterIdx->find( keyClusterIdx );
		if( searchDictByClusterIdx != dictByClusterIdx->end() ) {
			subdictClusterIdx = searchDictByClusterIdx->second;
		}
		else {
			subdictClusterIdx = new std::map<cfsec::CFSecSecAppPKey, cfsec::CFSecSecAppBuff*>();
			dictByClusterIdx->insert( std::map<cfsec::CFSecSecAppByClusterIdxKey,
				std::map<cfsec::CFSecSecAppPKey,
					cfsec::CFSecSecAppBuff*>*>::value_type( keyClusterIdx, subdictClusterIdx ) );
		}
		subdictClusterIdx->insert( std::map<cfsec::CFSecSecAppPKey, cfsec::CFSecSecAppBuff*>::value_type( pkey, buff ) );

		dictByUJEEMountIdx->insert( std::map<cfsec::CFSecSecAppByUJEEMountIdxKey, cfsec::CFSecSecAppBuff*>::value_type( keyUJEEMountIdx, buff ) );

		// The top level code has to clone the final buffer. The one passed in is now part of the persistent storage.
		if( buff->getClassCode() == cfsec::CFSecSecAppBuff::CLASS_CODE ) {
			buff = dynamic_cast<cfsec::CFSecSecAppBuff*>( buff->clone() );
		}
		return( buff );
	}

	cfsec::CFSecSecAppBuff* CFSecRamSecAppTable::readDerived( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecAppPKey* PKey )
	{
		static const std::string S_ProcName( "readDerived" );
		cfsec::CFSecSecAppBuff* buff;
		auto searchDictByPKey = dictByPKey->find( *PKey );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfsec::CFSecSecAppBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecSecAppBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfsec::CFSecSecAppBuff* CFSecRamSecAppTable::lockDerived( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecAppPKey* PKey )
	{
		static const std::string S_ProcName( "lockDerived" );
		cfsec::CFSecSecAppBuff* buff;
		auto searchDictByPKey = dictByPKey->find( *PKey );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfsec::CFSecSecAppBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecSecAppBuff*>( buff->clone() );
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

	std::TCFLibOwningVector<cfsec::CFSecSecAppBuff*> CFSecRamSecAppTable::readAllDerived( const cfsec::CFSecAuthorization* Authorization ) {
		static const std::string S_ProcName( "readAllDerived" );
		std::TCFLibOwningVector<cfsec::CFSecSecAppBuff*> retVec;
		std::map<cfsec::CFSecSecAppPKey,
			cfsec::CFSecSecAppBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecSecAppPKey,
			cfsec::CFSecSecAppBuff*>::iterator end = dictByPKey->end();
		cfsec::CFSecSecAppBuff* clone;
		while( iter != end ) {
			clone = dynamic_cast<cfsec::CFSecSecAppBuff*>( iter->second->clone() );
			retVec.push_back( clone );
			iter ++;
		}
		return( retVec );
	}

	std::TCFLibOwningVector<cfsec::CFSecSecAppBuff*> CFSecRamSecAppTable::readDerivedByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId )
	{
		static const std::string S_ProcName( "readDerivedByClusterIdx" );
		cfsec::CFSecSecAppByClusterIdxKey key;
		key.setRequiredClusterId( ClusterId );
		std::TCFLibOwningVector<cfsec::CFSecSecAppBuff*> recVec;
		cfsec::CFSecSecAppBuff* clone;
		auto searchDictByClusterIdx = dictByClusterIdx->find( key );
		if( searchDictByClusterIdx != dictByClusterIdx->end() ) {
			std::map<cfsec::CFSecSecAppPKey,
				 cfsec::CFSecSecAppBuff*>* subdictClusterIdx = searchDictByClusterIdx->second;
			std::map<cfsec::CFSecSecAppPKey,
				cfsec::CFSecSecAppBuff*>::iterator iter = subdictClusterIdx->begin();
			std::map<cfsec::CFSecSecAppPKey,
				cfsec::CFSecSecAppBuff*>::iterator end = subdictClusterIdx->end();
			while( iter != end ) {
				clone = dynamic_cast<cfsec::CFSecSecAppBuff*>( iter->second->clone() );
				recVec.push_back( clone );
				iter ++;
			}
		}
		return( recVec );
	}

	cfsec::CFSecSecAppBuff* CFSecRamSecAppTable::readDerivedByUJEEMountIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const std::string& JEEMountName )
	{
		static const std::string S_ProcName( "readDerivedByUJEEMountIdx" );
		cfsec::CFSecSecAppByUJEEMountIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredJEEMountName( JEEMountName );
		cfsec::CFSecSecAppBuff* buff;
		auto searchDictByUJEEMountIdx = dictByUJEEMountIdx->find( key );
		if( searchDictByUJEEMountIdx != dictByUJEEMountIdx->end() ) {
			buff = dynamic_cast<cfsec::CFSecSecAppBuff*>( searchDictByUJEEMountIdx->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecSecAppBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfsec::CFSecSecAppBuff* CFSecRamSecAppTable::readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecAppId )
	{
		static const std::string S_ProcName( "readDerivedByIdIdx" );
		cfsec::CFSecSecAppPKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredSecAppId( SecAppId );
		cfsec::CFSecSecAppBuff* buff;
		auto searchDictByPKey = dictByPKey->find( key );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfsec::CFSecSecAppBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecSecAppBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfsec::CFSecSecAppBuff* CFSecRamSecAppTable::readBuff( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecAppPKey* PKey )
	{
		static const std::string S_ProcName( "readBuff" );
		cfsec::CFSecSecAppBuff* buff = readDerived( Authorization, PKey );
		if( buff != NULL ) {
			if( buff->getClassCode() != cfsec::CFSecSecAppBuff::CLASS_CODE ) {
				delete buff;
				buff = NULL;
			}
		}
		return( dynamic_cast<cfsec::CFSecSecAppBuff*>( buff ) );
	}

	cfsec::CFSecSecAppBuff* CFSecRamSecAppTable::lockBuff( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecAppPKey* PKey )
	{
		static const std::string S_ProcName( "lockBuff" );
		cfsec::CFSecSecAppBuff* buff = lockDerived( Authorization, PKey );
		return( dynamic_cast<cfsec::CFSecSecAppBuff*>( buff ) );
	}

	std::TCFLibOwningVector<cfsec::CFSecSecAppBuff*> CFSecRamSecAppTable::readAllBuff( const cfsec::CFSecAuthorization* Authorization )
	{
		static const std::string S_ProcName( "readAllBuff" );
		cfsec::CFSecSecAppBuff* buff;
		std::TCFLibOwningVector<cfsec::CFSecSecAppBuff*> filteredList;
		std::TCFLibOwningVector<cfsec::CFSecSecAppBuff*> buffList = readAllDerived( Authorization );
		std::TCFLibOwningVector<cfsec::CFSecSecAppBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecAppBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfsec::CFSecSecAppBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfsec::CFSecSecAppBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	std::TCFLibOwningVector<cfsec::CFSecSecAppBuff*> CFSecRamSecAppTable::pageAllBuff( const cfsec::CFSecAuthorization* Authorization,
			const int64_t* priorClusterId,
			const int32_t* priorSecAppId )
	{
		static const std::string S_ProcName( "pageAllBuff" );
		// MSS TODO WORKING
		throw cflib::CFLibNotImplementedYetException( CLASS_NAME, S_ProcName );
	}

	cfsec::CFSecSecAppBuff* CFSecRamSecAppTable::readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecAppId )
	{
		static const std::string S_ProcName( "readBuffByIdIdx" );
		cfsec::CFSecSecAppBuff* buff = readDerivedByIdIdx( Authorization,
			ClusterId,
			SecAppId );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfsec::CFSecSecAppBuff::CLASS_CODE ) {
			return( dynamic_cast<cfsec::CFSecSecAppBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	std::TCFLibOwningVector<cfsec::CFSecSecAppBuff*> CFSecRamSecAppTable::readBuffByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId )
	{
		static const std::string S_ProcName( "readBuffByClusterIdx" );
		cfsec::CFSecSecAppBuff* buff;
		std::TCFLibOwningVector<cfsec::CFSecSecAppBuff*> filteredList;
		std::TCFLibOwningVector<cfsec::CFSecSecAppBuff*> buffList = readDerivedByClusterIdx( Authorization,
			ClusterId );
		std::TCFLibOwningVector<cfsec::CFSecSecAppBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecAppBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfsec::CFSecSecAppBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfsec::CFSecSecAppBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	cfsec::CFSecSecAppBuff* CFSecRamSecAppTable::readBuffByUJEEMountIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const std::string& JEEMountName )
	{
		static const std::string S_ProcName( "readBuffByUJEEMountIdx" );
		cfsec::CFSecSecAppBuff* buff = readDerivedByUJEEMountIdx( Authorization,
			ClusterId,
			JEEMountName );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfsec::CFSecSecAppBuff::CLASS_CODE ) {
			return( dynamic_cast<cfsec::CFSecSecAppBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	cfsec::CFSecSecAppBuff* CFSecRamSecAppTable::readBuffByLookupUJEEMountIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId, const std::string& JEEMountName,
		bool forceRead )
	{
		static const std::string S_ProcName( "readBuffByLookupUJEEMountIdx" );
		cfsec::CFSecSecAppBuff* buff = readBuffByUJEEMountIdx( Authorization,
			ClusterId,
			JEEMountName );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfsec::CFSecSecAppBuff::CLASS_CODE ) {
			return( dynamic_cast<cfsec::CFSecSecAppBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	cfsec::CFSecSecAppBuff* CFSecRamSecAppTable::readDerivedByLookupUJEEMountIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId, const std::string& JEEMountName,
		bool forceRead )
	{
		static const std::string S_ProcName( "readDerivedByLookupUJEEMountIdx" );
		cfsec::CFSecSecAppBuff* buff = readDerivedByUJEEMountIdx( Authorization,
			ClusterId,
			JEEMountName );
		if( buff != NULL ) {
			return( dynamic_cast<cfsec::CFSecSecAppBuff*>( buff->clone() ) );
		}
		else {
			return( NULL );
		}
	}

	std::TCFLibOwningVector<cfsec::CFSecSecAppBuff*> CFSecRamSecAppTable::pageBuffByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t* priorClusterId,
			const int32_t* priorSecAppId )
	{
		static const std::string S_ProcName( "pageBuffByClusterIdx" );
		// MSS TODO WORKING
		throw cflib::CFLibNotImplementedYetException( CLASS_NAME, S_ProcName );
	}

	cfsec::CFSecSecAppBuff* CFSecRamSecAppTable::updateSecApp( const cfsec::CFSecAuthorization* Authorization,
		cfsec::CFSecSecAppBuff* Buff )
	{
		static const std::string S_ProcName( "updateSecApp" );
		cfsec::CFSecSecAppPKey pkey;
		pkey.setRequiredClusterId( Buff->getRequiredClusterId() );
		pkey.setRequiredSecAppId( Buff->getRequiredSecAppId() );

		// Search for existing buffer

		auto searchExisting = dictByPKey->find( pkey );
		if( searchExisting == dictByPKey->end() ) {
			delete Buff;
			std::string Msg( "Existing record not found in SecApp for key " + pkey.toString() );
			throw cflib::CFLibStaleCacheDetectedException( CLASS_NAME,
				S_ProcName,
				Msg );
		}

		cfsec::CFSecSecAppBuff* existing = searchExisting->second;

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
			std::string Msg( "Collision detected for SecApp primary key " );
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
		cfsec::CFSecSecAppByClusterIdxKey existingKeyClusterIdx;
		existingKeyClusterIdx.setRequiredClusterId( existing->getRequiredClusterId() );
		cfsec::CFSecSecAppByClusterIdxKey newKeyClusterIdx;
		newKeyClusterIdx.setRequiredClusterId( Buff->getRequiredClusterId() );
		cfsec::CFSecSecAppByUJEEMountIdxKey existingKeyUJEEMountIdx;
		existingKeyUJEEMountIdx.setRequiredClusterId( existing->getRequiredClusterId() );
		existingKeyUJEEMountIdx.setRequiredJEEMountName( existing->getRequiredJEEMountName() );
		cfsec::CFSecSecAppByUJEEMountIdxKey newKeyUJEEMountIdx;
		newKeyUJEEMountIdx.setRequiredClusterId( Buff->getRequiredClusterId() );
		newKeyUJEEMountIdx.setRequiredJEEMountName( Buff->getRequiredJEEMountName() );
		// Check unique indexes

		if( existingKeyUJEEMountIdx != newKeyUJEEMountIdx ) {
			auto searchDictByUJEEMountIdx = dictByUJEEMountIdx->find( newKeyUJEEMountIdx );
			if( searchDictByUJEEMountIdx != dictByUJEEMountIdx->end() ) {
				std::string Msg( "Duplicate key detected for index SecAppUJEEMountIdx " + newKeyUJEEMountIdx.toString() );
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
					std::string Msg( "Could not resolve Container relationship SecAppCluster to table Cluster" );
					throw cflib::CFLibUnresolvedRelationException( CLASS_NAME,
						S_ProcName,
						Msg );
				}
				delete chk;
				chk = NULL;
			}
		}

		// Update is valid
		std::map<cfsec::CFSecSecAppPKey, cfsec::CFSecSecAppBuff*>* subdict;
		auto removalDictByPKey = dictByPKey->find( pkey );
		if( removalDictByPKey != dictByPKey->end() ) {
			dictByPKey->erase( removalDictByPKey );
		}
		// Copy edited buffer to existing persistent buffer

		if( Buff->getClassCode() != cfsec::CFSecSecAppBuff::CLASS_CODE ) {
			const static std::string S_IsNotA( " is not a cfsec::CFSecSecAppBuff" );
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

		dictByPKey->insert( std::map<cfsec::CFSecSecAppPKey, cfsec::CFSecSecAppBuff*>::value_type( pkey, existing ) );

		std::map<cfsec::CFSecSecAppPKey,
			 cfsec::CFSecSecAppBuff*>* subdictClusterIdx;
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
			subdictClusterIdx = new std::map<cfsec::CFSecSecAppPKey, cfsec::CFSecSecAppBuff*>();
			dictByClusterIdx->insert( std::map<cfsec::CFSecSecAppByClusterIdxKey,
				std::map<cfsec::CFSecSecAppPKey,
					cfsec::CFSecSecAppBuff*>*>::value_type( newKeyClusterIdx, subdictClusterIdx ) );
		}
		subdictClusterIdx->insert( std::map<cfsec::CFSecSecAppPKey, cfsec::CFSecSecAppBuff*>::value_type( pkey, existing ) );

		auto removalDictByUJEEMountIdx = dictByUJEEMountIdx->find( existingKeyUJEEMountIdx );
		if( removalDictByUJEEMountIdx != dictByUJEEMountIdx->end() ) {
			dictByUJEEMountIdx->erase( removalDictByUJEEMountIdx );
		}
		dictByUJEEMountIdx->insert( std::map<cfsec::CFSecSecAppByUJEEMountIdxKey, cfsec::CFSecSecAppBuff*>::value_type( newKeyUJEEMountIdx, existing ) );


		// The top level code has to clean up the memory buffer that was passed in, and return a clone
		// of the copy that existing buffer that is attached to the RAM storage.  All other cases
		// return the existing buffer.

		cfsec::CFSecSecAppBuff* buff;
		if( existing->getClassCode() == cfsec::CFSecSecAppBuff::CLASS_CODE ) {
			delete Buff;
			Buff = NULL;
			buff = dynamic_cast<cfsec::CFSecSecAppBuff*>( existing->clone() );
		}
		else {
			buff = existing;
		}
		return( buff );
	}

	void CFSecRamSecAppTable::deleteSecApp( const cfsec::CFSecAuthorization* Authorization,
		cfsec::CFSecSecAppBuff* Buff )
	{
		static const std::string S_ProcName( "deleteSecApp" );
		static const std::string S_Prev( "prev" );
		classcode_t classCode;
		cfsec::CFSecSecAppPKey pkey;
		pkey.setRequiredClusterId( Buff->getRequiredClusterId() );
		pkey.setRequiredSecAppId( Buff->getRequiredSecAppId() );
		auto searchExisting = dictByPKey->find( pkey );
		if( searchExisting == dictByPKey->end() ) {
			return;
		}
		cfsec::CFSecSecAppBuff* existing = searchExisting->second;
		schema->getTableSecForm()->deleteSecFormBySecAppIdx( Authorization,
			existing->getRequiredClusterId(),
			existing->getRequiredSecAppId() );
		cfsec::CFSecSecAppByClusterIdxKey keyClusterIdx;
		keyClusterIdx.setRequiredClusterId( existing->getRequiredClusterId() );
		cfsec::CFSecSecAppByUJEEMountIdxKey keyUJEEMountIdx;
		keyUJEEMountIdx.setRequiredClusterId( existing->getRequiredClusterId() );
		keyUJEEMountIdx.setRequiredJEEMountName( existing->getRequiredJEEMountName() );
		// Validate reverse foreign keys

		// Delete is valid
		std::map<cfsec::CFSecSecAppPKey, cfsec::CFSecSecAppBuff*>* subdict;

		auto searchDictByPKey = dictByPKey->find( pkey );
		if( searchDictByPKey != dictByPKey->end() ) {
			dictByPKey->erase( searchDictByPKey );
		}

		auto searchDictByClusterIdx = dictByClusterIdx->find( keyClusterIdx );
		if( searchDictByClusterIdx != dictByClusterIdx->end() ) {
			std::map<cfsec::CFSecSecAppPKey,
				 cfsec::CFSecSecAppBuff*>* subdictClusterIdx = searchDictByClusterIdx->second;
			auto searchSubDict = subdictClusterIdx->find( pkey );
			if( searchSubDict != subdictClusterIdx->end() ) {
				subdictClusterIdx->erase( searchSubDict );
			}
			subdictClusterIdx = NULL;
		}

		auto searchDictByUJEEMountIdx = dictByUJEEMountIdx->find( keyUJEEMountIdx );
		if( searchDictByUJEEMountIdx != dictByUJEEMountIdx->end() ) {
			dictByUJEEMountIdx->erase( searchDictByUJEEMountIdx );
		}

		if( existing != NULL ) {
			delete existing;
			existing = NULL;
		}
	}

	void CFSecRamSecAppTable::deleteSecAppByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const int32_t argSecAppId )
	{
		cfsec::CFSecSecAppPKey key;
		key.setRequiredClusterId( argClusterId );
		key.setRequiredSecAppId( argSecAppId );
		deleteSecAppByIdIdx( Authorization, &key );
	}

	void CFSecRamSecAppTable::deleteSecAppByIdIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecAppPKey* argKey )
	{
		bool anyNotNull = false;
		anyNotNull = true;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		cfsec::CFSecSecAppBuff* cur = NULL;
		cfsec::CFSecSecAppBuff* rereadCur = NULL;
		std::TCFLibOwningVector<cfsec::CFSecSecAppBuff*> matchSet;
		std::map<cfsec::CFSecSecAppPKey,
			cfsec::CFSecSecAppBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecSecAppPKey,
			cfsec::CFSecSecAppBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecSecAppBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecSecAppBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecSecAppBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecAppBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableSecApp()->readDerivedByIdIdx( Authorization,
				cur->getRequiredClusterId(),
				cur->getRequiredSecAppId() );
			rereadCur = cur;
			deleteSecApp( Authorization, cur );
			if( rereadCur != NULL ) {
				delete rereadCur;
				rereadCur = NULL;
			}
		}
	}

	void CFSecRamSecAppTable::deleteSecAppByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId )
	{
		cfsec::CFSecSecAppByClusterIdxKey key;
		key.setRequiredClusterId( argClusterId );
		deleteSecAppByClusterIdx( Authorization, &key );
	}

	void CFSecRamSecAppTable::deleteSecAppByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecAppByClusterIdxKey* argKey )
	{
		cfsec::CFSecSecAppBuff* cur = NULL;
		cfsec::CFSecSecAppBuff* rereadCur = NULL;
		bool anyNotNull = false;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfsec::CFSecSecAppBuff*> matchSet;
		std::map<cfsec::CFSecSecAppPKey,
			cfsec::CFSecSecAppBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecSecAppPKey,
			cfsec::CFSecSecAppBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecSecAppBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecSecAppBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecSecAppBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecAppBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableSecApp()->readDerivedByIdIdx( Authorization,
				cur->getRequiredClusterId(),
				cur->getRequiredSecAppId() );
			rereadCur = cur;
			deleteSecApp( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFSecRamSecAppTable::deleteSecAppByUJEEMountIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const std::string& argJEEMountName )
	{
		cfsec::CFSecSecAppByUJEEMountIdxKey key;
		key.setRequiredClusterId( argClusterId );
		key.setRequiredJEEMountName( argJEEMountName );
		deleteSecAppByUJEEMountIdx( Authorization, &key );
	}

	void CFSecRamSecAppTable::deleteSecAppByUJEEMountIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecAppByUJEEMountIdxKey* argKey )
	{
		cfsec::CFSecSecAppBuff* cur = NULL;
		cfsec::CFSecSecAppBuff* rereadCur = NULL;
		bool anyNotNull = false;
		anyNotNull = true;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfsec::CFSecSecAppBuff*> matchSet;
		std::map<cfsec::CFSecSecAppPKey,
			cfsec::CFSecSecAppBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecSecAppPKey,
			cfsec::CFSecSecAppBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecSecAppBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecSecAppBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecSecAppBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecAppBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableSecApp()->readDerivedByIdIdx( Authorization,
				cur->getRequiredClusterId(),
				cur->getRequiredSecAppId() );
			rereadCur = cur;
			deleteSecApp( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFSecRamSecAppTable::releasePreparedStatements() {
	}

}
