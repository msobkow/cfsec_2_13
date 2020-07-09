
// Description: C++18 Implementation for an in-memory RAM DbIO for SecDevice.

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

	const std::string CFSecRamSecDeviceTable::CLASS_NAME( "CFSecRamSecDeviceTable" );

	CFSecRamSecDeviceTable::CFSecRamSecDeviceTable( ICFSecSchema* argSchema )
	: cfsec::ICFSecSecDeviceTable()
	{
		schema = argSchema;
		dictByPKey = new std::map<cfsec::CFSecSecDevicePKey, cfsec::CFSecSecDeviceBuff*>();
		dictByNameIdx = new std::map<cfsec::CFSecSecDeviceByNameIdxKey, cfsec::CFSecSecDeviceBuff*>();
		dictByUserIdx = new std::map<cfsec::CFSecSecDeviceByUserIdxKey,
			std::map<cfsec::CFSecSecDevicePKey,
				cfsec::CFSecSecDeviceBuff*>*>();
	}

	CFSecRamSecDeviceTable::~CFSecRamSecDeviceTable() {
		if( dictByNameIdx != NULL ) {
			delete dictByNameIdx;
			dictByNameIdx = NULL;
		}
		if( dictByUserIdx != NULL ) {
			for( auto iterDict = dictByUserIdx->begin(); iterDict != dictByUserIdx->end(); iterDict ++ ) {
				delete iterDict->second;
				iterDict->second = NULL;
			}
			delete dictByUserIdx;
			dictByUserIdx = NULL;
		}
		if( dictByPKey != NULL ) {
			cfsec::CFSecSecDeviceBuff* elt;
			std::map<cfsec::CFSecSecDevicePKey,
				cfsec::CFSecSecDeviceBuff*>::iterator end = dictByPKey->end();
			for( std::map<cfsec::CFSecSecDevicePKey,
					cfsec::CFSecSecDeviceBuff*>::iterator cur = dictByPKey->begin();
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

	cfsec::CFSecSecDeviceBuff* CFSecRamSecDeviceTable::createSecDevice( const cfsec::CFSecAuthorization* Authorization,
		cfsec::CFSecSecDeviceBuff* Buff )
	{
		static const std::string S_ProcName( "createSecDevice" );
		cfsec::CFSecSecDevicePKey pkey;
		pkey.setRequiredSecUserId( Buff->getRequiredSecUserId() );
		pkey.setRequiredDevName( Buff->getRequiredDevName() );
		Buff->setRequiredSecUserId( pkey.getRequiredSecUserId() );
		Buff->setRequiredDevName( pkey.getRequiredDevName() );
		cfsec::CFSecSecDeviceByNameIdxKey keyNameIdx;
		keyNameIdx.setRequiredSecUserId( Buff->getRequiredSecUserId() );
		keyNameIdx.setRequiredDevName( Buff->getRequiredDevName() );
		cfsec::CFSecSecDeviceByUserIdxKey keyUserIdx;
		keyUserIdx.setRequiredSecUserId( Buff->getRequiredSecUserId() );
		// Validate unique indexes
		auto searchDictByPKey = dictByPKey->find( pkey );
		if( searchDictByPKey != dictByPKey->end() ) {
			delete Buff;
			std::string Msg( "Duplicate primary key detected " + pkey.toString() );
			throw cflib::CFLibPrimaryKeyNotNewException( CLASS_NAME, S_ProcName, Msg );
		}

		auto searchDictByNameIdx = dictByNameIdx->find( keyNameIdx );
		if( searchDictByNameIdx != dictByNameIdx->end() ) {
			std::string Msg( "Duplicate key detected for index SecDeviceNameIdx " + keyNameIdx.toString() );
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
				cfsec::CFSecSecUserBuff* chk = dynamic_cast<cfsec::CFSecSecUserBuff*>( schema->getTableSecUser()->readDerivedByIdIdx( Authorization,
						Buff->getRequiredSecUserId() ) );
				if( chk == NULL ) {
					delete Buff;
					std::string Msg( "Could not resolve Container relationship SecDeviceSecUser to table SecUser" );
					throw cflib::CFLibUnresolvedRelationException( CLASS_NAME,
						S_ProcName,
						Msg );
				}
				delete chk;
				chk = NULL;
			}
		}

		// Proceed with adding the new record
		cfsec::CFSecSecDeviceBuff* buff = Buff;
		buff->setRequiredRevision( 1 );
		dictByPKey->insert( std::map<cfsec::CFSecSecDevicePKey, cfsec::CFSecSecDeviceBuff*>::value_type( pkey, buff ) );

		dictByNameIdx->insert( std::map<cfsec::CFSecSecDeviceByNameIdxKey, cfsec::CFSecSecDeviceBuff*>::value_type( keyNameIdx, buff ) );

		std::map<cfsec::CFSecSecDevicePKey, cfsec::CFSecSecDeviceBuff*>* subdictUserIdx;
		auto searchDictByUserIdx = dictByUserIdx->find( keyUserIdx );
		if( searchDictByUserIdx != dictByUserIdx->end() ) {
			subdictUserIdx = searchDictByUserIdx->second;
		}
		else {
			subdictUserIdx = new std::map<cfsec::CFSecSecDevicePKey, cfsec::CFSecSecDeviceBuff*>();
			dictByUserIdx->insert( std::map<cfsec::CFSecSecDeviceByUserIdxKey,
				std::map<cfsec::CFSecSecDevicePKey,
					cfsec::CFSecSecDeviceBuff*>*>::value_type( keyUserIdx, subdictUserIdx ) );
		}
		subdictUserIdx->insert( std::map<cfsec::CFSecSecDevicePKey, cfsec::CFSecSecDeviceBuff*>::value_type( pkey, buff ) );

		// The top level code has to clone the final buffer. The one passed in is now part of the persistent storage.
		if( buff->getClassCode() == cfsec::CFSecSecDeviceBuff::CLASS_CODE ) {
			buff = dynamic_cast<cfsec::CFSecSecDeviceBuff*>( buff->clone() );
		}
		return( buff );
	}

	cfsec::CFSecSecDeviceBuff* CFSecRamSecDeviceTable::readDerived( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecDevicePKey* PKey )
	{
		static const std::string S_ProcName( "readDerived" );
		cfsec::CFSecSecDeviceBuff* buff;
		auto searchDictByPKey = dictByPKey->find( *PKey );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfsec::CFSecSecDeviceBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecSecDeviceBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfsec::CFSecSecDeviceBuff* CFSecRamSecDeviceTable::lockDerived( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecDevicePKey* PKey )
	{
		static const std::string S_ProcName( "lockDerived" );
		cfsec::CFSecSecDeviceBuff* buff;
		auto searchDictByPKey = dictByPKey->find( *PKey );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfsec::CFSecSecDeviceBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecSecDeviceBuff*>( buff->clone() );
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

	std::TCFLibOwningVector<cfsec::CFSecSecDeviceBuff*> CFSecRamSecDeviceTable::readAllDerived( const cfsec::CFSecAuthorization* Authorization ) {
		static const std::string S_ProcName( "readAllDerived" );
		std::TCFLibOwningVector<cfsec::CFSecSecDeviceBuff*> retVec;
		std::map<cfsec::CFSecSecDevicePKey,
			cfsec::CFSecSecDeviceBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecSecDevicePKey,
			cfsec::CFSecSecDeviceBuff*>::iterator end = dictByPKey->end();
		cfsec::CFSecSecDeviceBuff* clone;
		while( iter != end ) {
			clone = dynamic_cast<cfsec::CFSecSecDeviceBuff*>( iter->second->clone() );
			retVec.push_back( clone );
			iter ++;
		}
		return( retVec );
	}

	cfsec::CFSecSecDeviceBuff* CFSecRamSecDeviceTable::readDerivedByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId,
			const std::string& DevName )
	{
		static const std::string S_ProcName( "readDerivedByNameIdx" );
		cfsec::CFSecSecDeviceByNameIdxKey key;
		key.setRequiredSecUserId( SecUserId );
		key.setRequiredDevName( DevName );
		cfsec::CFSecSecDeviceBuff* buff;
		auto searchDictByNameIdx = dictByNameIdx->find( key );
		if( searchDictByNameIdx != dictByNameIdx->end() ) {
			buff = dynamic_cast<cfsec::CFSecSecDeviceBuff*>( searchDictByNameIdx->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecSecDeviceBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	std::TCFLibOwningVector<cfsec::CFSecSecDeviceBuff*> CFSecRamSecDeviceTable::readDerivedByUserIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId )
	{
		static const std::string S_ProcName( "readDerivedByUserIdx" );
		cfsec::CFSecSecDeviceByUserIdxKey key;
		key.setRequiredSecUserId( SecUserId );
		std::TCFLibOwningVector<cfsec::CFSecSecDeviceBuff*> recVec;
		cfsec::CFSecSecDeviceBuff* clone;
		auto searchDictByUserIdx = dictByUserIdx->find( key );
		if( searchDictByUserIdx != dictByUserIdx->end() ) {
			std::map<cfsec::CFSecSecDevicePKey,
				 cfsec::CFSecSecDeviceBuff*>* subdictUserIdx = searchDictByUserIdx->second;
			std::map<cfsec::CFSecSecDevicePKey,
				cfsec::CFSecSecDeviceBuff*>::iterator iter = subdictUserIdx->begin();
			std::map<cfsec::CFSecSecDevicePKey,
				cfsec::CFSecSecDeviceBuff*>::iterator end = subdictUserIdx->end();
			while( iter != end ) {
				clone = dynamic_cast<cfsec::CFSecSecDeviceBuff*>( iter->second->clone() );
				recVec.push_back( clone );
				iter ++;
			}
		}
		return( recVec );
	}

	cfsec::CFSecSecDeviceBuff* CFSecRamSecDeviceTable::readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId,
			const std::string& DevName )
	{
		static const std::string S_ProcName( "readDerivedByIdIdx" );
		cfsec::CFSecSecDevicePKey key;
		key.setRequiredSecUserId( SecUserId );
		key.setRequiredDevName( DevName );
		cfsec::CFSecSecDeviceBuff* buff;
		auto searchDictByPKey = dictByPKey->find( key );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfsec::CFSecSecDeviceBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecSecDeviceBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfsec::CFSecSecDeviceBuff* CFSecRamSecDeviceTable::readBuff( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecDevicePKey* PKey )
	{
		static const std::string S_ProcName( "readBuff" );
		cfsec::CFSecSecDeviceBuff* buff = readDerived( Authorization, PKey );
		if( buff != NULL ) {
			if( buff->getClassCode() != cfsec::CFSecSecDeviceBuff::CLASS_CODE ) {
				delete buff;
				buff = NULL;
			}
		}
		return( dynamic_cast<cfsec::CFSecSecDeviceBuff*>( buff ) );
	}

	cfsec::CFSecSecDeviceBuff* CFSecRamSecDeviceTable::lockBuff( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecDevicePKey* PKey )
	{
		static const std::string S_ProcName( "lockBuff" );
		cfsec::CFSecSecDeviceBuff* buff = lockDerived( Authorization, PKey );
		return( dynamic_cast<cfsec::CFSecSecDeviceBuff*>( buff ) );
	}

	std::TCFLibOwningVector<cfsec::CFSecSecDeviceBuff*> CFSecRamSecDeviceTable::readAllBuff( const cfsec::CFSecAuthorization* Authorization )
	{
		static const std::string S_ProcName( "readAllBuff" );
		cfsec::CFSecSecDeviceBuff* buff;
		std::TCFLibOwningVector<cfsec::CFSecSecDeviceBuff*> filteredList;
		std::TCFLibOwningVector<cfsec::CFSecSecDeviceBuff*> buffList = readAllDerived( Authorization );
		std::TCFLibOwningVector<cfsec::CFSecSecDeviceBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecDeviceBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfsec::CFSecSecDeviceBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfsec::CFSecSecDeviceBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	std::TCFLibOwningVector<cfsec::CFSecSecDeviceBuff*> CFSecRamSecDeviceTable::pageAllBuff( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t priorSecUserId,
			const std::string* priorDevName )
	{
		static const std::string S_ProcName( "pageAllBuff" );
		// MSS TODO WORKING
		throw cflib::CFLibNotImplementedYetException( CLASS_NAME, S_ProcName );
	}

	cfsec::CFSecSecDeviceBuff* CFSecRamSecDeviceTable::readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId,
			const std::string& DevName )
	{
		static const std::string S_ProcName( "readBuffByIdIdx" );
		cfsec::CFSecSecDeviceBuff* buff = readDerivedByIdIdx( Authorization,
			SecUserId,
			DevName );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfsec::CFSecSecDeviceBuff::CLASS_CODE ) {
			return( dynamic_cast<cfsec::CFSecSecDeviceBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	cfsec::CFSecSecDeviceBuff* CFSecRamSecDeviceTable::readBuffByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId,
			const std::string& DevName )
	{
		static const std::string S_ProcName( "readBuffByNameIdx" );
		cfsec::CFSecSecDeviceBuff* buff = readDerivedByNameIdx( Authorization,
			SecUserId,
			DevName );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfsec::CFSecSecDeviceBuff::CLASS_CODE ) {
			return( dynamic_cast<cfsec::CFSecSecDeviceBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	std::TCFLibOwningVector<cfsec::CFSecSecDeviceBuff*> CFSecRamSecDeviceTable::readBuffByUserIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId )
	{
		static const std::string S_ProcName( "readBuffByUserIdx" );
		cfsec::CFSecSecDeviceBuff* buff;
		std::TCFLibOwningVector<cfsec::CFSecSecDeviceBuff*> filteredList;
		std::TCFLibOwningVector<cfsec::CFSecSecDeviceBuff*> buffList = readDerivedByUserIdx( Authorization,
			SecUserId );
		std::TCFLibOwningVector<cfsec::CFSecSecDeviceBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecDeviceBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfsec::CFSecSecDeviceBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfsec::CFSecSecDeviceBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	cfsec::CFSecSecDeviceBuff* CFSecRamSecDeviceTable::readBuffByLookupNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId, const std::string& DevName,
		bool forceRead )
	{
		static const std::string S_ProcName( "readBuffByLookupNameIdx" );
		cfsec::CFSecSecDeviceBuff* buff = readBuffByNameIdx( Authorization,
			SecUserId,
			DevName );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfsec::CFSecSecDeviceBuff::CLASS_CODE ) {
			return( dynamic_cast<cfsec::CFSecSecDeviceBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	cfsec::CFSecSecDeviceBuff* CFSecRamSecDeviceTable::readDerivedByLookupNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId, const std::string& DevName,
		bool forceRead )
	{
		static const std::string S_ProcName( "readDerivedByLookupNameIdx" );
		cfsec::CFSecSecDeviceBuff* buff = readDerivedByNameIdx( Authorization,
			SecUserId,
			DevName );
		if( buff != NULL ) {
			return( dynamic_cast<cfsec::CFSecSecDeviceBuff*>( buff->clone() ) );
		}
		else {
			return( NULL );
		}
	}

	std::TCFLibOwningVector<cfsec::CFSecSecDeviceBuff*> CFSecRamSecDeviceTable::pageBuffByUserIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId,
			const uuid_ptr_t priorSecUserId,
			const std::string* priorDevName )
	{
		static const std::string S_ProcName( "pageBuffByUserIdx" );
		// MSS TODO WORKING
		throw cflib::CFLibNotImplementedYetException( CLASS_NAME, S_ProcName );
	}

	cfsec::CFSecSecDeviceBuff* CFSecRamSecDeviceTable::updateSecDevice( const cfsec::CFSecAuthorization* Authorization,
		cfsec::CFSecSecDeviceBuff* Buff )
	{
		static const std::string S_ProcName( "updateSecDevice" );
		cfsec::CFSecSecDevicePKey pkey;
		pkey.setRequiredSecUserId( Buff->getRequiredSecUserId() );
		pkey.setRequiredDevName( Buff->getRequiredDevName() );

		// Search for existing buffer

		auto searchExisting = dictByPKey->find( pkey );
		if( searchExisting == dictByPKey->end() ) {
			delete Buff;
			std::string Msg( "Existing record not found in SecDevice for key " + pkey.toString() );
			throw cflib::CFLibStaleCacheDetectedException( CLASS_NAME,
				S_ProcName,
				Msg );
		}

		cfsec::CFSecSecDeviceBuff* existing = searchExisting->second;

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
			std::string Msg( "Collision detected for SecDevice primary key " );
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
		cfsec::CFSecSecDeviceByNameIdxKey existingKeyNameIdx;
		existingKeyNameIdx.setRequiredSecUserId( existing->getRequiredSecUserId() );
		existingKeyNameIdx.setRequiredDevName( existing->getRequiredDevName() );
		cfsec::CFSecSecDeviceByNameIdxKey newKeyNameIdx;
		newKeyNameIdx.setRequiredSecUserId( Buff->getRequiredSecUserId() );
		newKeyNameIdx.setRequiredDevName( Buff->getRequiredDevName() );
		cfsec::CFSecSecDeviceByUserIdxKey existingKeyUserIdx;
		existingKeyUserIdx.setRequiredSecUserId( existing->getRequiredSecUserId() );
		cfsec::CFSecSecDeviceByUserIdxKey newKeyUserIdx;
		newKeyUserIdx.setRequiredSecUserId( Buff->getRequiredSecUserId() );
		// Check unique indexes

		if( existingKeyNameIdx != newKeyNameIdx ) {
			auto searchDictByNameIdx = dictByNameIdx->find( newKeyNameIdx );
			if( searchDictByNameIdx != dictByNameIdx->end() ) {
				std::string Msg( "Duplicate key detected for index SecDeviceNameIdx " + newKeyNameIdx.toString() );
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
				cfsec::CFSecSecUserBuff* chk = dynamic_cast<cfsec::CFSecSecUserBuff*>( schema->getTableSecUser()->readDerivedByIdIdx( Authorization,
						Buff->getRequiredSecUserId() ) );
				if( chk == NULL ) {
					delete Buff;
					std::string Msg( "Could not resolve Container relationship SecDeviceSecUser to table SecUser" );
					throw cflib::CFLibUnresolvedRelationException( CLASS_NAME,
						S_ProcName,
						Msg );
				}
				delete chk;
				chk = NULL;
			}
		}

		// Update is valid
		std::map<cfsec::CFSecSecDevicePKey, cfsec::CFSecSecDeviceBuff*>* subdict;
		auto removalDictByPKey = dictByPKey->find( pkey );
		if( removalDictByPKey != dictByPKey->end() ) {
			dictByPKey->erase( removalDictByPKey );
		}
		// Copy edited buffer to existing persistent buffer

		if( Buff->getClassCode() != cfsec::CFSecSecDeviceBuff::CLASS_CODE ) {
			const static std::string S_IsNotA( " is not a cfsec::CFSecSecDeviceBuff" );
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

		dictByPKey->insert( std::map<cfsec::CFSecSecDevicePKey, cfsec::CFSecSecDeviceBuff*>::value_type( pkey, existing ) );

		auto removalDictByNameIdx = dictByNameIdx->find( existingKeyNameIdx );
		if( removalDictByNameIdx != dictByNameIdx->end() ) {
			dictByNameIdx->erase( removalDictByNameIdx );
		}
		dictByNameIdx->insert( std::map<cfsec::CFSecSecDeviceByNameIdxKey, cfsec::CFSecSecDeviceBuff*>::value_type( newKeyNameIdx, existing ) );

		std::map<cfsec::CFSecSecDevicePKey,
			 cfsec::CFSecSecDeviceBuff*>* subdictUserIdx;
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
			subdictUserIdx = new std::map<cfsec::CFSecSecDevicePKey, cfsec::CFSecSecDeviceBuff*>();
			dictByUserIdx->insert( std::map<cfsec::CFSecSecDeviceByUserIdxKey,
				std::map<cfsec::CFSecSecDevicePKey,
					cfsec::CFSecSecDeviceBuff*>*>::value_type( newKeyUserIdx, subdictUserIdx ) );
		}
		subdictUserIdx->insert( std::map<cfsec::CFSecSecDevicePKey, cfsec::CFSecSecDeviceBuff*>::value_type( pkey, existing ) );


		// The top level code has to clean up the memory buffer that was passed in, and return a clone
		// of the copy that existing buffer that is attached to the RAM storage.  All other cases
		// return the existing buffer.

		cfsec::CFSecSecDeviceBuff* buff;
		if( existing->getClassCode() == cfsec::CFSecSecDeviceBuff::CLASS_CODE ) {
			delete Buff;
			Buff = NULL;
			buff = dynamic_cast<cfsec::CFSecSecDeviceBuff*>( existing->clone() );
		}
		else {
			buff = existing;
		}
		return( buff );
	}

	void CFSecRamSecDeviceTable::deleteSecDevice( const cfsec::CFSecAuthorization* Authorization,
		cfsec::CFSecSecDeviceBuff* Buff )
	{
		static const std::string S_ProcName( "deleteSecDevice" );
		static const std::string S_Prev( "prev" );
		classcode_t classCode;
		cfsec::CFSecSecDevicePKey pkey;
		pkey.setRequiredSecUserId( Buff->getRequiredSecUserId() );
		pkey.setRequiredDevName( Buff->getRequiredDevName() );
		auto searchExisting = dictByPKey->find( pkey );
		if( searchExisting == dictByPKey->end() ) {
			return;
		}
		cfsec::CFSecSecDeviceBuff* existing = searchExisting->second;
		cfsec::CFSecSecDeviceByNameIdxKey keyNameIdx;
		keyNameIdx.setRequiredSecUserId( existing->getRequiredSecUserId() );
		keyNameIdx.setRequiredDevName( existing->getRequiredDevName() );
		cfsec::CFSecSecDeviceByUserIdxKey keyUserIdx;
		keyUserIdx.setRequiredSecUserId( existing->getRequiredSecUserId() );
		// Validate reverse foreign keys

		// Delete is valid
		std::map<cfsec::CFSecSecDevicePKey, cfsec::CFSecSecDeviceBuff*>* subdict;

		auto searchDictByPKey = dictByPKey->find( pkey );
		if( searchDictByPKey != dictByPKey->end() ) {
			dictByPKey->erase( searchDictByPKey );
		}

		auto searchDictByNameIdx = dictByNameIdx->find( keyNameIdx );
		if( searchDictByNameIdx != dictByNameIdx->end() ) {
			dictByNameIdx->erase( searchDictByNameIdx );
		}

		auto searchDictByUserIdx = dictByUserIdx->find( keyUserIdx );
		if( searchDictByUserIdx != dictByUserIdx->end() ) {
			std::map<cfsec::CFSecSecDevicePKey,
				 cfsec::CFSecSecDeviceBuff*>* subdictUserIdx = searchDictByUserIdx->second;
			auto searchSubDict = subdictUserIdx->find( pkey );
			if( searchSubDict != subdictUserIdx->end() ) {
				subdictUserIdx->erase( searchSubDict );
			}
			subdictUserIdx = NULL;
		}

		if( existing != NULL ) {
			delete existing;
			existing = NULL;
		}
	}

	void CFSecRamSecDeviceTable::deleteSecDeviceByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t argSecUserId,
			const std::string& argDevName )
	{
		cfsec::CFSecSecDevicePKey key;
		key.setRequiredSecUserId( argSecUserId );
		key.setRequiredDevName( argDevName );
		deleteSecDeviceByIdIdx( Authorization, &key );
	}

	void CFSecRamSecDeviceTable::deleteSecDeviceByIdIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecDevicePKey* argKey )
	{
		bool anyNotNull = false;
		anyNotNull = true;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		cfsec::CFSecSecDeviceBuff* cur = NULL;
		cfsec::CFSecSecDeviceBuff* rereadCur = NULL;
		std::TCFLibOwningVector<cfsec::CFSecSecDeviceBuff*> matchSet;
		std::map<cfsec::CFSecSecDevicePKey,
			cfsec::CFSecSecDeviceBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecSecDevicePKey,
			cfsec::CFSecSecDeviceBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecSecDeviceBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecSecDeviceBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecSecDeviceBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecDeviceBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableSecDevice()->readDerivedByIdIdx( Authorization,
				cur->getRequiredSecUserId(),
				cur->getRequiredDevName() );
			rereadCur = cur;
			deleteSecDevice( Authorization, cur );
			if( rereadCur != NULL ) {
				delete rereadCur;
				rereadCur = NULL;
			}
		}
	}

	void CFSecRamSecDeviceTable::deleteSecDeviceByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t argSecUserId,
			const std::string& argDevName )
	{
		cfsec::CFSecSecDeviceByNameIdxKey key;
		key.setRequiredSecUserId( argSecUserId );
		key.setRequiredDevName( argDevName );
		deleteSecDeviceByNameIdx( Authorization, &key );
	}

	void CFSecRamSecDeviceTable::deleteSecDeviceByNameIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecDeviceByNameIdxKey* argKey )
	{
		cfsec::CFSecSecDeviceBuff* cur = NULL;
		cfsec::CFSecSecDeviceBuff* rereadCur = NULL;
		bool anyNotNull = false;
		anyNotNull = true;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfsec::CFSecSecDeviceBuff*> matchSet;
		std::map<cfsec::CFSecSecDevicePKey,
			cfsec::CFSecSecDeviceBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecSecDevicePKey,
			cfsec::CFSecSecDeviceBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecSecDeviceBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecSecDeviceBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecSecDeviceBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecDeviceBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableSecDevice()->readDerivedByIdIdx( Authorization,
				cur->getRequiredSecUserId(),
				cur->getRequiredDevName() );
			rereadCur = cur;
			deleteSecDevice( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFSecRamSecDeviceTable::deleteSecDeviceByUserIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t argSecUserId )
	{
		cfsec::CFSecSecDeviceByUserIdxKey key;
		key.setRequiredSecUserId( argSecUserId );
		deleteSecDeviceByUserIdx( Authorization, &key );
	}

	void CFSecRamSecDeviceTable::deleteSecDeviceByUserIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecDeviceByUserIdxKey* argKey )
	{
		cfsec::CFSecSecDeviceBuff* cur = NULL;
		cfsec::CFSecSecDeviceBuff* rereadCur = NULL;
		bool anyNotNull = false;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfsec::CFSecSecDeviceBuff*> matchSet;
		std::map<cfsec::CFSecSecDevicePKey,
			cfsec::CFSecSecDeviceBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecSecDevicePKey,
			cfsec::CFSecSecDeviceBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecSecDeviceBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecSecDeviceBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecSecDeviceBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecDeviceBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableSecDevice()->readDerivedByIdIdx( Authorization,
				cur->getRequiredSecUserId(),
				cur->getRequiredDevName() );
			rereadCur = cur;
			deleteSecDevice( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFSecRamSecDeviceTable::releasePreparedStatements() {
	}

}
