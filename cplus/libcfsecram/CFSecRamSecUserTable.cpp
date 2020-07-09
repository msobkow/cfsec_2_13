
// Description: C++18 Implementation for an in-memory RAM DbIO for SecUser.

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

	const std::string CFSecRamSecUserTable::CLASS_NAME( "CFSecRamSecUserTable" );

	CFSecRamSecUserTable::CFSecRamSecUserTable( ICFSecSchema* argSchema )
	: cfsec::ICFSecSecUserTable()
	{
		schema = argSchema;
		dictByPKey = new std::map<cfsec::CFSecSecUserPKey, cfsec::CFSecSecUserBuff*>();
		dictByULoginIdx = new std::map<cfsec::CFSecSecUserByULoginIdxKey, cfsec::CFSecSecUserBuff*>();
		dictByEMConfIdx = new std::map<cfsec::CFSecSecUserByEMConfIdxKey,
			std::map<cfsec::CFSecSecUserPKey,
				cfsec::CFSecSecUserBuff*>*>();
		dictByPwdResetIdx = new std::map<cfsec::CFSecSecUserByPwdResetIdxKey,
			std::map<cfsec::CFSecSecUserPKey,
				cfsec::CFSecSecUserBuff*>*>();
		dictByDefDevIdx = new std::map<cfsec::CFSecSecUserByDefDevIdxKey,
			std::map<cfsec::CFSecSecUserPKey,
				cfsec::CFSecSecUserBuff*>*>();
	}

	CFSecRamSecUserTable::~CFSecRamSecUserTable() {
		if( dictByULoginIdx != NULL ) {
			delete dictByULoginIdx;
			dictByULoginIdx = NULL;
		}
		if( dictByEMConfIdx != NULL ) {
			for( auto iterDict = dictByEMConfIdx->begin(); iterDict != dictByEMConfIdx->end(); iterDict ++ ) {
				delete iterDict->second;
				iterDict->second = NULL;
			}
			delete dictByEMConfIdx;
			dictByEMConfIdx = NULL;
		}
		if( dictByPwdResetIdx != NULL ) {
			for( auto iterDict = dictByPwdResetIdx->begin(); iterDict != dictByPwdResetIdx->end(); iterDict ++ ) {
				delete iterDict->second;
				iterDict->second = NULL;
			}
			delete dictByPwdResetIdx;
			dictByPwdResetIdx = NULL;
		}
		if( dictByDefDevIdx != NULL ) {
			for( auto iterDict = dictByDefDevIdx->begin(); iterDict != dictByDefDevIdx->end(); iterDict ++ ) {
				delete iterDict->second;
				iterDict->second = NULL;
			}
			delete dictByDefDevIdx;
			dictByDefDevIdx = NULL;
		}
		if( dictByPKey != NULL ) {
			cfsec::CFSecSecUserBuff* elt;
			std::map<cfsec::CFSecSecUserPKey,
				cfsec::CFSecSecUserBuff*>::iterator end = dictByPKey->end();
			for( std::map<cfsec::CFSecSecUserPKey,
					cfsec::CFSecSecUserBuff*>::iterator cur = dictByPKey->begin();
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

	cfsec::CFSecSecUserBuff* CFSecRamSecUserTable::createSecUser( const cfsec::CFSecAuthorization* Authorization,
		cfsec::CFSecSecUserBuff* Buff )
	{
		static const std::string S_ProcName( "createSecUser" );
		cfsec::CFSecSecUserPKey pkey;
		pkey.generateRequiredSecUserId();
		Buff->setRequiredSecUserId( pkey.getRequiredSecUserId() );
		cfsec::CFSecSecUserByULoginIdxKey keyULoginIdx;
		keyULoginIdx.setRequiredLoginId( Buff->getRequiredLoginId() );
		cfsec::CFSecSecUserByEMConfIdxKey keyEMConfIdx;
		if( Buff->isOptionalEMailConfirmUuidNull() ) {
			keyEMConfIdx.setOptionalEMailConfirmUuidNull();
		}
		else {
			keyEMConfIdx.setOptionalEMailConfirmUuidValue( Buff->getOptionalEMailConfirmUuidValue() );
		}
		cfsec::CFSecSecUserByPwdResetIdxKey keyPwdResetIdx;
		if( Buff->isOptionalPasswordResetUuidNull() ) {
			keyPwdResetIdx.setOptionalPasswordResetUuidNull();
		}
		else {
			keyPwdResetIdx.setOptionalPasswordResetUuidValue( Buff->getOptionalPasswordResetUuidValue() );
		}
		cfsec::CFSecSecUserByDefDevIdxKey keyDefDevIdx;
		if( Buff->isOptionalDfltDevUserIdNull() ) {
			keyDefDevIdx.setOptionalDfltDevUserIdNull();
		}
		else {
			keyDefDevIdx.setOptionalDfltDevUserIdValue( Buff->getOptionalDfltDevUserIdValue() );
		}
		if( Buff->isOptionalDfltDevNameNull() ) {
			keyDefDevIdx.setOptionalDfltDevNameNull();
		}
		else {
			keyDefDevIdx.setOptionalDfltDevNameValue( Buff->getOptionalDfltDevNameValue() );
		}
		// Validate unique indexes
		auto searchDictByPKey = dictByPKey->find( pkey );
		if( searchDictByPKey != dictByPKey->end() ) {
			delete Buff;
			std::string Msg( "Duplicate primary key detected " + pkey.toString() );
			throw cflib::CFLibPrimaryKeyNotNewException( CLASS_NAME, S_ProcName, Msg );
		}

		auto searchDictByULoginIdx = dictByULoginIdx->find( keyULoginIdx );
		if( searchDictByULoginIdx != dictByULoginIdx->end() ) {
			std::string Msg( "Duplicate key detected for index SecUserLoginIdx " + keyULoginIdx.toString() );
			delete Buff;
			throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
				S_ProcName,
				Msg );
		}

		// Validate foreign keys

		// Proceed with adding the new record
		cfsec::CFSecSecUserBuff* buff = Buff;
		buff->setRequiredRevision( 1 );
		dictByPKey->insert( std::map<cfsec::CFSecSecUserPKey, cfsec::CFSecSecUserBuff*>::value_type( pkey, buff ) );

		dictByULoginIdx->insert( std::map<cfsec::CFSecSecUserByULoginIdxKey, cfsec::CFSecSecUserBuff*>::value_type( keyULoginIdx, buff ) );

		std::map<cfsec::CFSecSecUserPKey, cfsec::CFSecSecUserBuff*>* subdictEMConfIdx;
		auto searchDictByEMConfIdx = dictByEMConfIdx->find( keyEMConfIdx );
		if( searchDictByEMConfIdx != dictByEMConfIdx->end() ) {
			subdictEMConfIdx = searchDictByEMConfIdx->second;
		}
		else {
			subdictEMConfIdx = new std::map<cfsec::CFSecSecUserPKey, cfsec::CFSecSecUserBuff*>();
			dictByEMConfIdx->insert( std::map<cfsec::CFSecSecUserByEMConfIdxKey,
				std::map<cfsec::CFSecSecUserPKey,
					cfsec::CFSecSecUserBuff*>*>::value_type( keyEMConfIdx, subdictEMConfIdx ) );
		}
		subdictEMConfIdx->insert( std::map<cfsec::CFSecSecUserPKey, cfsec::CFSecSecUserBuff*>::value_type( pkey, buff ) );

		std::map<cfsec::CFSecSecUserPKey, cfsec::CFSecSecUserBuff*>* subdictPwdResetIdx;
		auto searchDictByPwdResetIdx = dictByPwdResetIdx->find( keyPwdResetIdx );
		if( searchDictByPwdResetIdx != dictByPwdResetIdx->end() ) {
			subdictPwdResetIdx = searchDictByPwdResetIdx->second;
		}
		else {
			subdictPwdResetIdx = new std::map<cfsec::CFSecSecUserPKey, cfsec::CFSecSecUserBuff*>();
			dictByPwdResetIdx->insert( std::map<cfsec::CFSecSecUserByPwdResetIdxKey,
				std::map<cfsec::CFSecSecUserPKey,
					cfsec::CFSecSecUserBuff*>*>::value_type( keyPwdResetIdx, subdictPwdResetIdx ) );
		}
		subdictPwdResetIdx->insert( std::map<cfsec::CFSecSecUserPKey, cfsec::CFSecSecUserBuff*>::value_type( pkey, buff ) );

		std::map<cfsec::CFSecSecUserPKey, cfsec::CFSecSecUserBuff*>* subdictDefDevIdx;
		auto searchDictByDefDevIdx = dictByDefDevIdx->find( keyDefDevIdx );
		if( searchDictByDefDevIdx != dictByDefDevIdx->end() ) {
			subdictDefDevIdx = searchDictByDefDevIdx->second;
		}
		else {
			subdictDefDevIdx = new std::map<cfsec::CFSecSecUserPKey, cfsec::CFSecSecUserBuff*>();
			dictByDefDevIdx->insert( std::map<cfsec::CFSecSecUserByDefDevIdxKey,
				std::map<cfsec::CFSecSecUserPKey,
					cfsec::CFSecSecUserBuff*>*>::value_type( keyDefDevIdx, subdictDefDevIdx ) );
		}
		subdictDefDevIdx->insert( std::map<cfsec::CFSecSecUserPKey, cfsec::CFSecSecUserBuff*>::value_type( pkey, buff ) );

		// The top level code has to clone the final buffer. The one passed in is now part of the persistent storage.
		if( buff->getClassCode() == cfsec::CFSecSecUserBuff::CLASS_CODE ) {
			buff = dynamic_cast<cfsec::CFSecSecUserBuff*>( buff->clone() );
		}
		return( buff );
	}

	cfsec::CFSecSecUserBuff* CFSecRamSecUserTable::readDerived( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecUserPKey* PKey )
	{
		static const std::string S_ProcName( "readDerived" );
		cfsec::CFSecSecUserBuff* buff;
		auto searchDictByPKey = dictByPKey->find( *PKey );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfsec::CFSecSecUserBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecSecUserBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfsec::CFSecSecUserBuff* CFSecRamSecUserTable::lockDerived( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecUserPKey* PKey )
	{
		static const std::string S_ProcName( "lockDerived" );
		cfsec::CFSecSecUserBuff* buff;
		auto searchDictByPKey = dictByPKey->find( *PKey );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfsec::CFSecSecUserBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecSecUserBuff*>( buff->clone() );
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

	std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*> CFSecRamSecUserTable::readAllDerived( const cfsec::CFSecAuthorization* Authorization ) {
		static const std::string S_ProcName( "readAllDerived" );
		std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*> retVec;
		std::map<cfsec::CFSecSecUserPKey,
			cfsec::CFSecSecUserBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecSecUserPKey,
			cfsec::CFSecSecUserBuff*>::iterator end = dictByPKey->end();
		cfsec::CFSecSecUserBuff* clone;
		while( iter != end ) {
			clone = dynamic_cast<cfsec::CFSecSecUserBuff*>( iter->second->clone() );
			retVec.push_back( clone );
			iter ++;
		}
		return( retVec );
	}

	cfsec::CFSecSecUserBuff* CFSecRamSecUserTable::readDerivedByULoginIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& LoginId )
	{
		static const std::string S_ProcName( "readDerivedByULoginIdx" );
		cfsec::CFSecSecUserByULoginIdxKey key;
		key.setRequiredLoginId( LoginId );
		cfsec::CFSecSecUserBuff* buff;
		auto searchDictByULoginIdx = dictByULoginIdx->find( key );
		if( searchDictByULoginIdx != dictByULoginIdx->end() ) {
			buff = dynamic_cast<cfsec::CFSecSecUserBuff*>( searchDictByULoginIdx->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecSecUserBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*> CFSecRamSecUserTable::readDerivedByEMConfIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t EMailConfirmUuid )
	{
		static const std::string S_ProcName( "readDerivedByEMConfIdx" );
		cfsec::CFSecSecUserByEMConfIdxKey key;
		if( EMailConfirmUuid == NULL ) {
			key.setOptionalEMailConfirmUuidNull();
		}
		else {
			key.setOptionalEMailConfirmUuidValue( EMailConfirmUuid );
		}
		std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*> recVec;
		cfsec::CFSecSecUserBuff* clone;
		auto searchDictByEMConfIdx = dictByEMConfIdx->find( key );
		if( searchDictByEMConfIdx != dictByEMConfIdx->end() ) {
			std::map<cfsec::CFSecSecUserPKey,
				 cfsec::CFSecSecUserBuff*>* subdictEMConfIdx = searchDictByEMConfIdx->second;
			std::map<cfsec::CFSecSecUserPKey,
				cfsec::CFSecSecUserBuff*>::iterator iter = subdictEMConfIdx->begin();
			std::map<cfsec::CFSecSecUserPKey,
				cfsec::CFSecSecUserBuff*>::iterator end = subdictEMConfIdx->end();
			while( iter != end ) {
				clone = dynamic_cast<cfsec::CFSecSecUserBuff*>( iter->second->clone() );
				recVec.push_back( clone );
				iter ++;
			}
		}
		return( recVec );
	}

	std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*> CFSecRamSecUserTable::readDerivedByPwdResetIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t PasswordResetUuid )
	{
		static const std::string S_ProcName( "readDerivedByPwdResetIdx" );
		cfsec::CFSecSecUserByPwdResetIdxKey key;
		if( PasswordResetUuid == NULL ) {
			key.setOptionalPasswordResetUuidNull();
		}
		else {
			key.setOptionalPasswordResetUuidValue( PasswordResetUuid );
		}
		std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*> recVec;
		cfsec::CFSecSecUserBuff* clone;
		auto searchDictByPwdResetIdx = dictByPwdResetIdx->find( key );
		if( searchDictByPwdResetIdx != dictByPwdResetIdx->end() ) {
			std::map<cfsec::CFSecSecUserPKey,
				 cfsec::CFSecSecUserBuff*>* subdictPwdResetIdx = searchDictByPwdResetIdx->second;
			std::map<cfsec::CFSecSecUserPKey,
				cfsec::CFSecSecUserBuff*>::iterator iter = subdictPwdResetIdx->begin();
			std::map<cfsec::CFSecSecUserPKey,
				cfsec::CFSecSecUserBuff*>::iterator end = subdictPwdResetIdx->end();
			while( iter != end ) {
				clone = dynamic_cast<cfsec::CFSecSecUserBuff*>( iter->second->clone() );
				recVec.push_back( clone );
				iter ++;
			}
		}
		return( recVec );
	}

	std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*> CFSecRamSecUserTable::readDerivedByDefDevIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t DfltDevUserId,
			const std::string* DfltDevName )
	{
		static const std::string S_ProcName( "readDerivedByDefDevIdx" );
		cfsec::CFSecSecUserByDefDevIdxKey key;
		if( DfltDevUserId == NULL ) {
			key.setOptionalDfltDevUserIdNull();
		}
		else {
			key.setOptionalDfltDevUserIdValue( DfltDevUserId );
		}
		if( DfltDevName == NULL ) {
			key.setOptionalDfltDevNameNull();
		}
		else {
			key.setOptionalDfltDevNameValue( *DfltDevName );
		}
		std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*> recVec;
		cfsec::CFSecSecUserBuff* clone;
		auto searchDictByDefDevIdx = dictByDefDevIdx->find( key );
		if( searchDictByDefDevIdx != dictByDefDevIdx->end() ) {
			std::map<cfsec::CFSecSecUserPKey,
				 cfsec::CFSecSecUserBuff*>* subdictDefDevIdx = searchDictByDefDevIdx->second;
			std::map<cfsec::CFSecSecUserPKey,
				cfsec::CFSecSecUserBuff*>::iterator iter = subdictDefDevIdx->begin();
			std::map<cfsec::CFSecSecUserPKey,
				cfsec::CFSecSecUserBuff*>::iterator end = subdictDefDevIdx->end();
			while( iter != end ) {
				clone = dynamic_cast<cfsec::CFSecSecUserBuff*>( iter->second->clone() );
				recVec.push_back( clone );
				iter ++;
			}
		}
		return( recVec );
	}

	cfsec::CFSecSecUserBuff* CFSecRamSecUserTable::readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId )
	{
		static const std::string S_ProcName( "readDerivedByIdIdx" );
		cfsec::CFSecSecUserPKey key;
		key.setRequiredSecUserId( SecUserId );
		cfsec::CFSecSecUserBuff* buff;
		auto searchDictByPKey = dictByPKey->find( key );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfsec::CFSecSecUserBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecSecUserBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfsec::CFSecSecUserBuff* CFSecRamSecUserTable::readBuff( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecUserPKey* PKey )
	{
		static const std::string S_ProcName( "readBuff" );
		cfsec::CFSecSecUserBuff* buff = readDerived( Authorization, PKey );
		if( buff != NULL ) {
			if( buff->getClassCode() != cfsec::CFSecSecUserBuff::CLASS_CODE ) {
				delete buff;
				buff = NULL;
			}
		}
		return( dynamic_cast<cfsec::CFSecSecUserBuff*>( buff ) );
	}

	cfsec::CFSecSecUserBuff* CFSecRamSecUserTable::lockBuff( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecUserPKey* PKey )
	{
		static const std::string S_ProcName( "lockBuff" );
		cfsec::CFSecSecUserBuff* buff = lockDerived( Authorization, PKey );
		return( dynamic_cast<cfsec::CFSecSecUserBuff*>( buff ) );
	}

	std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*> CFSecRamSecUserTable::readAllBuff( const cfsec::CFSecAuthorization* Authorization )
	{
		static const std::string S_ProcName( "readAllBuff" );
		cfsec::CFSecSecUserBuff* buff;
		std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*> filteredList;
		std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*> buffList = readAllDerived( Authorization );
		std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfsec::CFSecSecUserBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfsec::CFSecSecUserBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*> CFSecRamSecUserTable::pageAllBuff( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t priorSecUserId )
	{
		static const std::string S_ProcName( "pageAllBuff" );
		// MSS TODO WORKING
		throw cflib::CFLibNotImplementedYetException( CLASS_NAME, S_ProcName );
	}

	cfsec::CFSecSecUserBuff* CFSecRamSecUserTable::readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId )
	{
		static const std::string S_ProcName( "readBuffByIdIdx" );
		cfsec::CFSecSecUserBuff* buff = readDerivedByIdIdx( Authorization,
			SecUserId );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfsec::CFSecSecUserBuff::CLASS_CODE ) {
			return( dynamic_cast<cfsec::CFSecSecUserBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	cfsec::CFSecSecUserBuff* CFSecRamSecUserTable::readBuffByULoginIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& LoginId )
	{
		static const std::string S_ProcName( "readBuffByULoginIdx" );
		cfsec::CFSecSecUserBuff* buff = readDerivedByULoginIdx( Authorization,
			LoginId );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfsec::CFSecSecUserBuff::CLASS_CODE ) {
			return( dynamic_cast<cfsec::CFSecSecUserBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*> CFSecRamSecUserTable::readBuffByEMConfIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t EMailConfirmUuid )
	{
		static const std::string S_ProcName( "readBuffByEMConfIdx" );
		cfsec::CFSecSecUserBuff* buff;
		std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*> filteredList;
		std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*> buffList = readDerivedByEMConfIdx( Authorization,
			EMailConfirmUuid );
		std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfsec::CFSecSecUserBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfsec::CFSecSecUserBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*> CFSecRamSecUserTable::readBuffByPwdResetIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t PasswordResetUuid )
	{
		static const std::string S_ProcName( "readBuffByPwdResetIdx" );
		cfsec::CFSecSecUserBuff* buff;
		std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*> filteredList;
		std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*> buffList = readDerivedByPwdResetIdx( Authorization,
			PasswordResetUuid );
		std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfsec::CFSecSecUserBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfsec::CFSecSecUserBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*> CFSecRamSecUserTable::readBuffByDefDevIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t DfltDevUserId,
			const std::string* DfltDevName )
	{
		static const std::string S_ProcName( "readBuffByDefDevIdx" );
		cfsec::CFSecSecUserBuff* buff;
		std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*> filteredList;
		std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*> buffList = readDerivedByDefDevIdx( Authorization,
			DfltDevUserId,
			DfltDevName );
		std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfsec::CFSecSecUserBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfsec::CFSecSecUserBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	cfsec::CFSecSecUserBuff* CFSecRamSecUserTable::readBuffByLookupULoginIdx( const cfsec::CFSecAuthorization* Authorization, const std::string& LoginId,
		bool forceRead )
	{
		static const std::string S_ProcName( "readBuffByLookupULoginIdx" );
		cfsec::CFSecSecUserBuff* buff = readBuffByULoginIdx( Authorization,
			LoginId );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfsec::CFSecSecUserBuff::CLASS_CODE ) {
			return( dynamic_cast<cfsec::CFSecSecUserBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	cfsec::CFSecSecUserBuff* CFSecRamSecUserTable::readDerivedByLookupULoginIdx( const cfsec::CFSecAuthorization* Authorization, const std::string& LoginId,
		bool forceRead )
	{
		static const std::string S_ProcName( "readDerivedByLookupULoginIdx" );
		cfsec::CFSecSecUserBuff* buff = readDerivedByULoginIdx( Authorization,
			LoginId );
		if( buff != NULL ) {
			return( dynamic_cast<cfsec::CFSecSecUserBuff*>( buff->clone() ) );
		}
		else {
			return( NULL );
		}
	}

	std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*> CFSecRamSecUserTable::pageBuffByEMConfIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t EMailConfirmUuid,
			const uuid_ptr_t priorSecUserId )
	{
		static const std::string S_ProcName( "pageBuffByEMConfIdx" );
		// MSS TODO WORKING
		throw cflib::CFLibNotImplementedYetException( CLASS_NAME, S_ProcName );
	}

	std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*> CFSecRamSecUserTable::pageBuffByPwdResetIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t PasswordResetUuid,
			const uuid_ptr_t priorSecUserId )
	{
		static const std::string S_ProcName( "pageBuffByPwdResetIdx" );
		// MSS TODO WORKING
		throw cflib::CFLibNotImplementedYetException( CLASS_NAME, S_ProcName );
	}

	std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*> CFSecRamSecUserTable::pageBuffByDefDevIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t DfltDevUserId,
			const std::string* DfltDevName,
			const uuid_ptr_t priorSecUserId )
	{
		static const std::string S_ProcName( "pageBuffByDefDevIdx" );
		// MSS TODO WORKING
		throw cflib::CFLibNotImplementedYetException( CLASS_NAME, S_ProcName );
	}

	cfsec::CFSecSecUserBuff* CFSecRamSecUserTable::updateSecUser( const cfsec::CFSecAuthorization* Authorization,
		cfsec::CFSecSecUserBuff* Buff )
	{
		static const std::string S_ProcName( "updateSecUser" );
		cfsec::CFSecSecUserPKey pkey;
		pkey.setRequiredSecUserId( Buff->getRequiredSecUserId() );

		// Search for existing buffer

		auto searchExisting = dictByPKey->find( pkey );
		if( searchExisting == dictByPKey->end() ) {
			delete Buff;
			std::string Msg( "Existing record not found in SecUser for key " + pkey.toString() );
			throw cflib::CFLibStaleCacheDetectedException( CLASS_NAME,
				S_ProcName,
				Msg );
		}

		cfsec::CFSecSecUserBuff* existing = searchExisting->second;

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
			std::string Msg( "Collision detected for SecUser primary key " );
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
		cfsec::CFSecSecUserByULoginIdxKey existingKeyULoginIdx;
		existingKeyULoginIdx.setRequiredLoginId( existing->getRequiredLoginId() );
		cfsec::CFSecSecUserByULoginIdxKey newKeyULoginIdx;
		newKeyULoginIdx.setRequiredLoginId( Buff->getRequiredLoginId() );
		cfsec::CFSecSecUserByEMConfIdxKey existingKeyEMConfIdx;
		if( existing->isOptionalEMailConfirmUuidNull() ) {
			existingKeyEMConfIdx.setOptionalEMailConfirmUuidNull();
		}
		else {
			existingKeyEMConfIdx.setOptionalEMailConfirmUuidValue( existing->getOptionalEMailConfirmUuidValue() );
		}
		cfsec::CFSecSecUserByEMConfIdxKey newKeyEMConfIdx;
		if( Buff->isOptionalEMailConfirmUuidNull() ) {
			newKeyEMConfIdx.setOptionalEMailConfirmUuidNull();
		}
		else {
			newKeyEMConfIdx.setOptionalEMailConfirmUuidValue( Buff->getOptionalEMailConfirmUuidValue() );
		}
		cfsec::CFSecSecUserByPwdResetIdxKey existingKeyPwdResetIdx;
		if( existing->isOptionalPasswordResetUuidNull() ) {
			existingKeyPwdResetIdx.setOptionalPasswordResetUuidNull();
		}
		else {
			existingKeyPwdResetIdx.setOptionalPasswordResetUuidValue( existing->getOptionalPasswordResetUuidValue() );
		}
		cfsec::CFSecSecUserByPwdResetIdxKey newKeyPwdResetIdx;
		if( Buff->isOptionalPasswordResetUuidNull() ) {
			newKeyPwdResetIdx.setOptionalPasswordResetUuidNull();
		}
		else {
			newKeyPwdResetIdx.setOptionalPasswordResetUuidValue( Buff->getOptionalPasswordResetUuidValue() );
		}
		cfsec::CFSecSecUserByDefDevIdxKey existingKeyDefDevIdx;
		if( existing->isOptionalDfltDevUserIdNull() ) {
			existingKeyDefDevIdx.setOptionalDfltDevUserIdNull();
		}
		else {
			existingKeyDefDevIdx.setOptionalDfltDevUserIdValue( existing->getOptionalDfltDevUserIdValue() );
		}
		if( existing->isOptionalDfltDevNameNull() ) {
			existingKeyDefDevIdx.setOptionalDfltDevNameNull();
		}
		else {
			existingKeyDefDevIdx.setOptionalDfltDevNameValue( existing->getOptionalDfltDevNameValue() );
		}
		cfsec::CFSecSecUserByDefDevIdxKey newKeyDefDevIdx;
		if( Buff->isOptionalDfltDevUserIdNull() ) {
			newKeyDefDevIdx.setOptionalDfltDevUserIdNull();
		}
		else {
			newKeyDefDevIdx.setOptionalDfltDevUserIdValue( Buff->getOptionalDfltDevUserIdValue() );
		}
		if( Buff->isOptionalDfltDevNameNull() ) {
			newKeyDefDevIdx.setOptionalDfltDevNameNull();
		}
		else {
			newKeyDefDevIdx.setOptionalDfltDevNameValue( Buff->getOptionalDfltDevNameValue() );
		}
		// Check unique indexes

		if( existingKeyULoginIdx != newKeyULoginIdx ) {
			auto searchDictByULoginIdx = dictByULoginIdx->find( newKeyULoginIdx );
			if( searchDictByULoginIdx != dictByULoginIdx->end() ) {
				std::string Msg( "Duplicate key detected for index SecUserLoginIdx " + newKeyULoginIdx.toString() );
				delete Buff;
				throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
					S_ProcName,
					Msg );
			}
		}

		// Validate foreign keys

		// Update is valid
		std::map<cfsec::CFSecSecUserPKey, cfsec::CFSecSecUserBuff*>* subdict;
		auto removalDictByPKey = dictByPKey->find( pkey );
		if( removalDictByPKey != dictByPKey->end() ) {
			dictByPKey->erase( removalDictByPKey );
		}
		// Copy edited buffer to existing persistent buffer

		if( Buff->getClassCode() != cfsec::CFSecSecUserBuff::CLASS_CODE ) {
			const static std::string S_IsNotA( " is not a cfsec::CFSecSecUserBuff" );
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

		dictByPKey->insert( std::map<cfsec::CFSecSecUserPKey, cfsec::CFSecSecUserBuff*>::value_type( pkey, existing ) );

		auto removalDictByULoginIdx = dictByULoginIdx->find( existingKeyULoginIdx );
		if( removalDictByULoginIdx != dictByULoginIdx->end() ) {
			dictByULoginIdx->erase( removalDictByULoginIdx );
		}
		dictByULoginIdx->insert( std::map<cfsec::CFSecSecUserByULoginIdxKey, cfsec::CFSecSecUserBuff*>::value_type( newKeyULoginIdx, existing ) );

		std::map<cfsec::CFSecSecUserPKey,
			 cfsec::CFSecSecUserBuff*>* subdictEMConfIdx;
		auto searchDictByEMConfIdx = dictByEMConfIdx->find( existingKeyEMConfIdx );
		if( searchDictByEMConfIdx != dictByEMConfIdx->end() ) {
			subdictEMConfIdx = searchDictByEMConfIdx->second;
			auto searchSubDict = subdictEMConfIdx->find( pkey );
			if( searchSubDict != subdictEMConfIdx->end() ) {
				subdictEMConfIdx->erase( searchSubDict );
			}
			if( subdictEMConfIdx->size() <= 0 ) {
				delete subdictEMConfIdx;
				dictByEMConfIdx->erase( searchDictByEMConfIdx );
			}
			subdictEMConfIdx = NULL;
		}
		auto searchNewKeyDictByEMConfIdx = dictByEMConfIdx->find( newKeyEMConfIdx );
		if( searchNewKeyDictByEMConfIdx != dictByEMConfIdx->end() ) {
			subdictEMConfIdx = searchNewKeyDictByEMConfIdx->second;
		}
		else {
			subdictEMConfIdx = new std::map<cfsec::CFSecSecUserPKey, cfsec::CFSecSecUserBuff*>();
			dictByEMConfIdx->insert( std::map<cfsec::CFSecSecUserByEMConfIdxKey,
				std::map<cfsec::CFSecSecUserPKey,
					cfsec::CFSecSecUserBuff*>*>::value_type( newKeyEMConfIdx, subdictEMConfIdx ) );
		}
		subdictEMConfIdx->insert( std::map<cfsec::CFSecSecUserPKey, cfsec::CFSecSecUserBuff*>::value_type( pkey, existing ) );

		std::map<cfsec::CFSecSecUserPKey,
			 cfsec::CFSecSecUserBuff*>* subdictPwdResetIdx;
		auto searchDictByPwdResetIdx = dictByPwdResetIdx->find( existingKeyPwdResetIdx );
		if( searchDictByPwdResetIdx != dictByPwdResetIdx->end() ) {
			subdictPwdResetIdx = searchDictByPwdResetIdx->second;
			auto searchSubDict = subdictPwdResetIdx->find( pkey );
			if( searchSubDict != subdictPwdResetIdx->end() ) {
				subdictPwdResetIdx->erase( searchSubDict );
			}
			if( subdictPwdResetIdx->size() <= 0 ) {
				delete subdictPwdResetIdx;
				dictByPwdResetIdx->erase( searchDictByPwdResetIdx );
			}
			subdictPwdResetIdx = NULL;
		}
		auto searchNewKeyDictByPwdResetIdx = dictByPwdResetIdx->find( newKeyPwdResetIdx );
		if( searchNewKeyDictByPwdResetIdx != dictByPwdResetIdx->end() ) {
			subdictPwdResetIdx = searchNewKeyDictByPwdResetIdx->second;
		}
		else {
			subdictPwdResetIdx = new std::map<cfsec::CFSecSecUserPKey, cfsec::CFSecSecUserBuff*>();
			dictByPwdResetIdx->insert( std::map<cfsec::CFSecSecUserByPwdResetIdxKey,
				std::map<cfsec::CFSecSecUserPKey,
					cfsec::CFSecSecUserBuff*>*>::value_type( newKeyPwdResetIdx, subdictPwdResetIdx ) );
		}
		subdictPwdResetIdx->insert( std::map<cfsec::CFSecSecUserPKey, cfsec::CFSecSecUserBuff*>::value_type( pkey, existing ) );

		std::map<cfsec::CFSecSecUserPKey,
			 cfsec::CFSecSecUserBuff*>* subdictDefDevIdx;
		auto searchDictByDefDevIdx = dictByDefDevIdx->find( existingKeyDefDevIdx );
		if( searchDictByDefDevIdx != dictByDefDevIdx->end() ) {
			subdictDefDevIdx = searchDictByDefDevIdx->second;
			auto searchSubDict = subdictDefDevIdx->find( pkey );
			if( searchSubDict != subdictDefDevIdx->end() ) {
				subdictDefDevIdx->erase( searchSubDict );
			}
			if( subdictDefDevIdx->size() <= 0 ) {
				delete subdictDefDevIdx;
				dictByDefDevIdx->erase( searchDictByDefDevIdx );
			}
			subdictDefDevIdx = NULL;
		}
		auto searchNewKeyDictByDefDevIdx = dictByDefDevIdx->find( newKeyDefDevIdx );
		if( searchNewKeyDictByDefDevIdx != dictByDefDevIdx->end() ) {
			subdictDefDevIdx = searchNewKeyDictByDefDevIdx->second;
		}
		else {
			subdictDefDevIdx = new std::map<cfsec::CFSecSecUserPKey, cfsec::CFSecSecUserBuff*>();
			dictByDefDevIdx->insert( std::map<cfsec::CFSecSecUserByDefDevIdxKey,
				std::map<cfsec::CFSecSecUserPKey,
					cfsec::CFSecSecUserBuff*>*>::value_type( newKeyDefDevIdx, subdictDefDevIdx ) );
		}
		subdictDefDevIdx->insert( std::map<cfsec::CFSecSecUserPKey, cfsec::CFSecSecUserBuff*>::value_type( pkey, existing ) );


		// The top level code has to clean up the memory buffer that was passed in, and return a clone
		// of the copy that existing buffer that is attached to the RAM storage.  All other cases
		// return the existing buffer.

		cfsec::CFSecSecUserBuff* buff;
		if( existing->getClassCode() == cfsec::CFSecSecUserBuff::CLASS_CODE ) {
			delete Buff;
			Buff = NULL;
			buff = dynamic_cast<cfsec::CFSecSecUserBuff*>( existing->clone() );
		}
		else {
			buff = existing;
		}
		return( buff );
	}

	void CFSecRamSecUserTable::deleteSecUser( const cfsec::CFSecAuthorization* Authorization,
		cfsec::CFSecSecUserBuff* Buff )
	{
		static const std::string S_ProcName( "deleteSecUser" );
		static const std::string S_Prev( "prev" );
		classcode_t classCode;
		cfsec::CFSecSecUserPKey pkey;
		pkey.setRequiredSecUserId( Buff->getRequiredSecUserId() );
		auto searchExisting = dictByPKey->find( pkey );
		if( searchExisting == dictByPKey->end() ) {
			return;
		}
		cfsec::CFSecSecUserBuff* existing = searchExisting->second;
					{
						cfsec::CFSecSecUserBuff* buff = schema->getTableSecUser()->readDerivedByIdIdx( Authorization,
						existing->getRequiredSecUserId() );
						buff->setOptionalDfltDevUserIdNull();
						buff->setOptionalDfltDevNameNull();
						cfsec::CFSecSecUserBuff* editBuff = NULL;
						classCode = buff->getClassCode();
						if( classCode == cfsec::CFSecSecUserBuff::CLASS_CODE ) {
							editBuff = dynamic_cast<cfsec::CFSecSecUserBuff*>( schema->getTableSecUser()->updateSecUser( Authorization, buff ) );
						}
						else {
							if( buff != NULL ) {
								delete buff;
								buff = NULL;
							}
							std::string S_Msg( "Unrecognized ClassCode \"" + cflib::CFLib::formatClassCode( classCode ) + "\"" );
							throw cflib::CFLibUnsupportedClassException( CLASS_NAME,
								S_ProcName,
								S_Msg );
						}
						if( editBuff != NULL ) {
							delete editBuff;
							editBuff = NULL;
						}
					}
		cfsec::CFSecSecUserBuff* editSubobj = NULL;
		cfsec::CFSecSecUserBuff* subobj = schema->getTableSecUser()->readDerivedByIdIdx( Authorization,
			existing->getRequiredSecUserId() );
			subobj->setOptionalDfltDevUserIdNull();
			subobj->setOptionalDfltDevNameNull();
		classCode = subobj->getClassCode();
		if( classCode == cfsec::CFSecSecUserBuff::CLASS_CODE ) {
			editSubobj = dynamic_cast<cfsec::CFSecSecUserBuff*>( schema->getTableSecUser()->updateSecUser( Authorization, subobj ) );
		}
		else {
			delete subobj;
			subobj = NULL;
			std::string S_Msg( "Unrecognized ClassCode \"" + cflib::CFLib::formatClassCode( classCode ) + "\"" );
			throw cflib::CFLibUnsupportedClassException( CLASS_NAME,
				S_ProcName,
				S_Msg );
		}
		// existing was not deleted by the update, so we won't be deleting that
		// unless we're in the base class.  But we may as well delete editSubobj
		// now because we always have to get rid of it.
		delete editSubobj;
		editSubobj = NULL;
		schema->getTableTSecGrpMemb()->deleteTSecGrpMembByUserIdx( Authorization,
			existing->getRequiredSecUserId() );
		schema->getTableSecGrpMemb()->deleteSecGrpMembByUserIdx( Authorization,
			existing->getRequiredSecUserId() );
		schema->getTableSecSession()->deleteSecSessionBySecUserIdx( Authorization,
			existing->getRequiredSecUserId() );
		schema->getTableSecSession()->deleteSecSessionBySecProxyIdx( Authorization,
			existing->getRequiredSecUserIdReference() );
		schema->getTableSecDevice()->deleteSecDeviceByUserIdx( Authorization,
			existing->getRequiredSecUserId() );
		cfsec::CFSecSecUserByULoginIdxKey keyULoginIdx;
		keyULoginIdx.setRequiredLoginId( existing->getRequiredLoginId() );
		cfsec::CFSecSecUserByEMConfIdxKey keyEMConfIdx;
		if( existing->isOptionalEMailConfirmUuidNull() ) {
			keyEMConfIdx.setOptionalEMailConfirmUuidNull();
		}
		else {
			keyEMConfIdx.setOptionalEMailConfirmUuidValue( existing->getOptionalEMailConfirmUuidValue() );
		}
		cfsec::CFSecSecUserByPwdResetIdxKey keyPwdResetIdx;
		if( existing->isOptionalPasswordResetUuidNull() ) {
			keyPwdResetIdx.setOptionalPasswordResetUuidNull();
		}
		else {
			keyPwdResetIdx.setOptionalPasswordResetUuidValue( existing->getOptionalPasswordResetUuidValue() );
		}
		cfsec::CFSecSecUserByDefDevIdxKey keyDefDevIdx;
		if( existing->isOptionalDfltDevUserIdNull() ) {
			keyDefDevIdx.setOptionalDfltDevUserIdNull();
		}
		else {
			keyDefDevIdx.setOptionalDfltDevUserIdValue( existing->getOptionalDfltDevUserIdValue() );
		}
		if( existing->isOptionalDfltDevNameNull() ) {
			keyDefDevIdx.setOptionalDfltDevNameNull();
		}
		else {
			keyDefDevIdx.setOptionalDfltDevNameValue( existing->getOptionalDfltDevNameValue() );
		}
		// Validate reverse foreign keys

		// Delete is valid
		std::map<cfsec::CFSecSecUserPKey, cfsec::CFSecSecUserBuff*>* subdict;

		auto searchDictByPKey = dictByPKey->find( pkey );
		if( searchDictByPKey != dictByPKey->end() ) {
			dictByPKey->erase( searchDictByPKey );
		}

		auto searchDictByULoginIdx = dictByULoginIdx->find( keyULoginIdx );
		if( searchDictByULoginIdx != dictByULoginIdx->end() ) {
			dictByULoginIdx->erase( searchDictByULoginIdx );
		}

		auto searchDictByEMConfIdx = dictByEMConfIdx->find( keyEMConfIdx );
		if( searchDictByEMConfIdx != dictByEMConfIdx->end() ) {
			std::map<cfsec::CFSecSecUserPKey,
				 cfsec::CFSecSecUserBuff*>* subdictEMConfIdx = searchDictByEMConfIdx->second;
			auto searchSubDict = subdictEMConfIdx->find( pkey );
			if( searchSubDict != subdictEMConfIdx->end() ) {
				subdictEMConfIdx->erase( searchSubDict );
			}
			subdictEMConfIdx = NULL;
		}

		auto searchDictByPwdResetIdx = dictByPwdResetIdx->find( keyPwdResetIdx );
		if( searchDictByPwdResetIdx != dictByPwdResetIdx->end() ) {
			std::map<cfsec::CFSecSecUserPKey,
				 cfsec::CFSecSecUserBuff*>* subdictPwdResetIdx = searchDictByPwdResetIdx->second;
			auto searchSubDict = subdictPwdResetIdx->find( pkey );
			if( searchSubDict != subdictPwdResetIdx->end() ) {
				subdictPwdResetIdx->erase( searchSubDict );
			}
			subdictPwdResetIdx = NULL;
		}

		auto searchDictByDefDevIdx = dictByDefDevIdx->find( keyDefDevIdx );
		if( searchDictByDefDevIdx != dictByDefDevIdx->end() ) {
			std::map<cfsec::CFSecSecUserPKey,
				 cfsec::CFSecSecUserBuff*>* subdictDefDevIdx = searchDictByDefDevIdx->second;
			auto searchSubDict = subdictDefDevIdx->find( pkey );
			if( searchSubDict != subdictDefDevIdx->end() ) {
				subdictDefDevIdx->erase( searchSubDict );
			}
			subdictDefDevIdx = NULL;
		}

		if( existing != NULL ) {
			delete existing;
			existing = NULL;
		}
	}

	void CFSecRamSecUserTable::deleteSecUserByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t argSecUserId )
	{
		cfsec::CFSecSecUserPKey key;
		key.setRequiredSecUserId( argSecUserId );
		deleteSecUserByIdIdx( Authorization, &key );
	}

	void CFSecRamSecUserTable::deleteSecUserByIdIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecUserPKey* argKey )
	{
		bool anyNotNull = false;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		cfsec::CFSecSecUserBuff* cur = NULL;
		cfsec::CFSecSecUserBuff* rereadCur = NULL;
		std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*> matchSet;
		std::map<cfsec::CFSecSecUserPKey,
			cfsec::CFSecSecUserBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecSecUserPKey,
			cfsec::CFSecSecUserBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecSecUserBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecSecUserBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableSecUser()->readDerivedByIdIdx( Authorization,
				cur->getRequiredSecUserId() );
			rereadCur = cur;
			deleteSecUser( Authorization, cur );
			if( rereadCur != NULL ) {
				delete rereadCur;
				rereadCur = NULL;
			}
		}
	}

	void CFSecRamSecUserTable::deleteSecUserByULoginIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& argLoginId )
	{
		cfsec::CFSecSecUserByULoginIdxKey key;
		key.setRequiredLoginId( argLoginId );
		deleteSecUserByULoginIdx( Authorization, &key );
	}

	void CFSecRamSecUserTable::deleteSecUserByULoginIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecUserByULoginIdxKey* argKey )
	{
		cfsec::CFSecSecUserBuff* cur = NULL;
		cfsec::CFSecSecUserBuff* rereadCur = NULL;
		bool anyNotNull = false;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*> matchSet;
		std::map<cfsec::CFSecSecUserPKey,
			cfsec::CFSecSecUserBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecSecUserPKey,
			cfsec::CFSecSecUserBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecSecUserBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecSecUserBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableSecUser()->readDerivedByIdIdx( Authorization,
				cur->getRequiredSecUserId() );
			rereadCur = cur;
			deleteSecUser( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFSecRamSecUserTable::deleteSecUserByEMConfIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t argEMailConfirmUuid )
	{
		cfsec::CFSecSecUserByEMConfIdxKey key;
		if( argEMailConfirmUuid == NULL ) {
			key.setOptionalEMailConfirmUuidNull();
		}
		else {
			key.setOptionalEMailConfirmUuidValue( argEMailConfirmUuid );
		}
		deleteSecUserByEMConfIdx( Authorization, &key );
	}

	void CFSecRamSecUserTable::deleteSecUserByEMConfIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecUserByEMConfIdxKey* argKey )
	{
		cfsec::CFSecSecUserBuff* cur = NULL;
		cfsec::CFSecSecUserBuff* rereadCur = NULL;
		bool anyNotNull = false;
		if( argKey->isOptionalEMailConfirmUuidNull() ) {
			anyNotNull = true;
		}
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*> matchSet;
		std::map<cfsec::CFSecSecUserPKey,
			cfsec::CFSecSecUserBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecSecUserPKey,
			cfsec::CFSecSecUserBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecSecUserBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecSecUserBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableSecUser()->readDerivedByIdIdx( Authorization,
				cur->getRequiredSecUserId() );
			rereadCur = cur;
			deleteSecUser( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFSecRamSecUserTable::deleteSecUserByPwdResetIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t argPasswordResetUuid )
	{
		cfsec::CFSecSecUserByPwdResetIdxKey key;
		if( argPasswordResetUuid == NULL ) {
			key.setOptionalPasswordResetUuidNull();
		}
		else {
			key.setOptionalPasswordResetUuidValue( argPasswordResetUuid );
		}
		deleteSecUserByPwdResetIdx( Authorization, &key );
	}

	void CFSecRamSecUserTable::deleteSecUserByPwdResetIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecUserByPwdResetIdxKey* argKey )
	{
		cfsec::CFSecSecUserBuff* cur = NULL;
		cfsec::CFSecSecUserBuff* rereadCur = NULL;
		bool anyNotNull = false;
		if( argKey->isOptionalPasswordResetUuidNull() ) {
			anyNotNull = true;
		}
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*> matchSet;
		std::map<cfsec::CFSecSecUserPKey,
			cfsec::CFSecSecUserBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecSecUserPKey,
			cfsec::CFSecSecUserBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecSecUserBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecSecUserBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableSecUser()->readDerivedByIdIdx( Authorization,
				cur->getRequiredSecUserId() );
			rereadCur = cur;
			deleteSecUser( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFSecRamSecUserTable::deleteSecUserByDefDevIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t argDfltDevUserId,
			const std::string* argDfltDevName )
	{
		cfsec::CFSecSecUserByDefDevIdxKey key;
		if( argDfltDevUserId == NULL ) {
			key.setOptionalDfltDevUserIdNull();
		}
		else {
			key.setOptionalDfltDevUserIdValue( argDfltDevUserId );
		}
		if( argDfltDevName == NULL ) {
			key.setOptionalDfltDevNameNull();
		}
		else {
			key.setOptionalDfltDevNameValue( *argDfltDevName );
		}
		deleteSecUserByDefDevIdx( Authorization, &key );
	}

	void CFSecRamSecUserTable::deleteSecUserByDefDevIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecUserByDefDevIdxKey* argKey )
	{
		cfsec::CFSecSecUserBuff* cur = NULL;
		cfsec::CFSecSecUserBuff* rereadCur = NULL;
		bool anyNotNull = false;
		if( argKey->isOptionalDfltDevUserIdNull() ) {
			anyNotNull = true;
		}
		if( argKey->isOptionalDfltDevNameNull() ) {
			anyNotNull = true;
		}
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*> matchSet;
		std::map<cfsec::CFSecSecUserPKey,
			cfsec::CFSecSecUserBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecSecUserPKey,
			cfsec::CFSecSecUserBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecSecUserBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecSecUserBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableSecUser()->readDerivedByIdIdx( Authorization,
				cur->getRequiredSecUserId() );
			rereadCur = cur;
			deleteSecUser( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFSecRamSecUserTable::releasePreparedStatements() {
	}

}
