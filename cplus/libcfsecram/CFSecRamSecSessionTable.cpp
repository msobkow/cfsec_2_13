
// Description: C++18 Implementation for an in-memory RAM DbIO for SecSession.

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

	const std::string CFSecRamSecSessionTable::CLASS_NAME( "CFSecRamSecSessionTable" );

	CFSecRamSecSessionTable::CFSecRamSecSessionTable( ICFSecSchema* argSchema )
	: cfsec::ICFSecSecSessionTable()
	{
		schema = argSchema;
		dictByPKey = new std::map<cfsec::CFSecSecSessionPKey, cfsec::CFSecSecSessionBuff*>();
		dictBySecUserIdx = new std::map<cfsec::CFSecSecSessionBySecUserIdxKey,
			std::map<cfsec::CFSecSecSessionPKey,
				cfsec::CFSecSecSessionBuff*>*>();
		dictBySecDevIdx = new std::map<cfsec::CFSecSecSessionBySecDevIdxKey,
			std::map<cfsec::CFSecSecSessionPKey,
				cfsec::CFSecSecSessionBuff*>*>();
		dictByStartIdx = new std::map<cfsec::CFSecSecSessionByStartIdxKey, cfsec::CFSecSecSessionBuff*>();
		dictByFinishIdx = new std::map<cfsec::CFSecSecSessionByFinishIdxKey,
			std::map<cfsec::CFSecSecSessionPKey,
				cfsec::CFSecSecSessionBuff*>*>();
		dictBySecProxyIdx = new std::map<cfsec::CFSecSecSessionBySecProxyIdxKey,
			std::map<cfsec::CFSecSecSessionPKey,
				cfsec::CFSecSecSessionBuff*>*>();
	}

	CFSecRamSecSessionTable::~CFSecRamSecSessionTable() {
		if( dictBySecUserIdx != NULL ) {
			for( auto iterDict = dictBySecUserIdx->begin(); iterDict != dictBySecUserIdx->end(); iterDict ++ ) {
				delete iterDict->second;
				iterDict->second = NULL;
			}
			delete dictBySecUserIdx;
			dictBySecUserIdx = NULL;
		}
		if( dictBySecDevIdx != NULL ) {
			for( auto iterDict = dictBySecDevIdx->begin(); iterDict != dictBySecDevIdx->end(); iterDict ++ ) {
				delete iterDict->second;
				iterDict->second = NULL;
			}
			delete dictBySecDevIdx;
			dictBySecDevIdx = NULL;
		}
		if( dictByStartIdx != NULL ) {
			delete dictByStartIdx;
			dictByStartIdx = NULL;
		}
		if( dictByFinishIdx != NULL ) {
			for( auto iterDict = dictByFinishIdx->begin(); iterDict != dictByFinishIdx->end(); iterDict ++ ) {
				delete iterDict->second;
				iterDict->second = NULL;
			}
			delete dictByFinishIdx;
			dictByFinishIdx = NULL;
		}
		if( dictBySecProxyIdx != NULL ) {
			for( auto iterDict = dictBySecProxyIdx->begin(); iterDict != dictBySecProxyIdx->end(); iterDict ++ ) {
				delete iterDict->second;
				iterDict->second = NULL;
			}
			delete dictBySecProxyIdx;
			dictBySecProxyIdx = NULL;
		}
		if( dictByPKey != NULL ) {
			cfsec::CFSecSecSessionBuff* elt;
			std::map<cfsec::CFSecSecSessionPKey,
				cfsec::CFSecSecSessionBuff*>::iterator end = dictByPKey->end();
			for( std::map<cfsec::CFSecSecSessionPKey,
					cfsec::CFSecSecSessionBuff*>::iterator cur = dictByPKey->begin();
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

	cfsec::CFSecSecSessionBuff* CFSecRamSecSessionTable::createSecSession( const cfsec::CFSecAuthorization* Authorization,
		cfsec::CFSecSecSessionBuff* Buff )
	{
		static const std::string S_ProcName( "createSecSession" );
		cfsec::CFSecSecSessionPKey pkey;
		pkey.generateRequiredSecSessionId();
		Buff->setRequiredSecSessionId( pkey.getRequiredSecSessionId() );
		cfsec::CFSecSecSessionBySecUserIdxKey keySecUserIdx;
		keySecUserIdx.setRequiredSecUserId( Buff->getRequiredSecUserId() );
		cfsec::CFSecSecSessionBySecDevIdxKey keySecDevIdx;
		keySecDevIdx.setRequiredSecUserId( Buff->getRequiredSecUserId() );
		if( Buff->isOptionalSecDevNameNull() ) {
			keySecDevIdx.setOptionalSecDevNameNull();
		}
		else {
			keySecDevIdx.setOptionalSecDevNameValue( Buff->getOptionalSecDevNameValue() );
		}
		cfsec::CFSecSecSessionByStartIdxKey keyStartIdx;
		keyStartIdx.setRequiredSecUserId( Buff->getRequiredSecUserId() );
		keyStartIdx.setRequiredStart( Buff->getRequiredStart() );
		cfsec::CFSecSecSessionByFinishIdxKey keyFinishIdx;
		keyFinishIdx.setRequiredSecUserId( Buff->getRequiredSecUserId() );
		if( Buff->isOptionalFinishNull() ) {
			keyFinishIdx.setOptionalFinishNull();
		}
		else {
			keyFinishIdx.setOptionalFinishValue( Buff->getOptionalFinishValue() );
		}
		cfsec::CFSecSecSessionBySecProxyIdxKey keySecProxyIdx;
		if( Buff->isOptionalSecProxyIdNull() ) {
			keySecProxyIdx.setOptionalSecProxyIdNull();
		}
		else {
			keySecProxyIdx.setOptionalSecProxyIdValue( Buff->getOptionalSecProxyIdValue() );
		}
		// Validate unique indexes
		auto searchDictByPKey = dictByPKey->find( pkey );
		if( searchDictByPKey != dictByPKey->end() ) {
			delete Buff;
			std::string Msg( "Duplicate primary key detected " + pkey.toString() );
			throw cflib::CFLibPrimaryKeyNotNewException( CLASS_NAME, S_ProcName, Msg );
		}

		auto searchDictByStartIdx = dictByStartIdx->find( keyStartIdx );
		if( searchDictByStartIdx != dictByStartIdx->end() ) {
			std::string Msg( "Duplicate key detected for index SessionStartIdx " + keyStartIdx.toString() );
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
					std::string Msg( "Could not resolve Container relationship SecSessionUser to table SecUser" );
					throw cflib::CFLibUnresolvedRelationException( CLASS_NAME,
						S_ProcName,
						Msg );
				}
				delete chk;
				chk = NULL;
			}
		}

		// Proceed with adding the new record
		cfsec::CFSecSecSessionBuff* buff = Buff;
		buff->setRequiredRevision( 1 );
		dictByPKey->insert( std::map<cfsec::CFSecSecSessionPKey, cfsec::CFSecSecSessionBuff*>::value_type( pkey, buff ) );

		std::map<cfsec::CFSecSecSessionPKey, cfsec::CFSecSecSessionBuff*>* subdictSecUserIdx;
		auto searchDictBySecUserIdx = dictBySecUserIdx->find( keySecUserIdx );
		if( searchDictBySecUserIdx != dictBySecUserIdx->end() ) {
			subdictSecUserIdx = searchDictBySecUserIdx->second;
		}
		else {
			subdictSecUserIdx = new std::map<cfsec::CFSecSecSessionPKey, cfsec::CFSecSecSessionBuff*>();
			dictBySecUserIdx->insert( std::map<cfsec::CFSecSecSessionBySecUserIdxKey,
				std::map<cfsec::CFSecSecSessionPKey,
					cfsec::CFSecSecSessionBuff*>*>::value_type( keySecUserIdx, subdictSecUserIdx ) );
		}
		subdictSecUserIdx->insert( std::map<cfsec::CFSecSecSessionPKey, cfsec::CFSecSecSessionBuff*>::value_type( pkey, buff ) );

		std::map<cfsec::CFSecSecSessionPKey, cfsec::CFSecSecSessionBuff*>* subdictSecDevIdx;
		auto searchDictBySecDevIdx = dictBySecDevIdx->find( keySecDevIdx );
		if( searchDictBySecDevIdx != dictBySecDevIdx->end() ) {
			subdictSecDevIdx = searchDictBySecDevIdx->second;
		}
		else {
			subdictSecDevIdx = new std::map<cfsec::CFSecSecSessionPKey, cfsec::CFSecSecSessionBuff*>();
			dictBySecDevIdx->insert( std::map<cfsec::CFSecSecSessionBySecDevIdxKey,
				std::map<cfsec::CFSecSecSessionPKey,
					cfsec::CFSecSecSessionBuff*>*>::value_type( keySecDevIdx, subdictSecDevIdx ) );
		}
		subdictSecDevIdx->insert( std::map<cfsec::CFSecSecSessionPKey, cfsec::CFSecSecSessionBuff*>::value_type( pkey, buff ) );

		dictByStartIdx->insert( std::map<cfsec::CFSecSecSessionByStartIdxKey, cfsec::CFSecSecSessionBuff*>::value_type( keyStartIdx, buff ) );

		std::map<cfsec::CFSecSecSessionPKey, cfsec::CFSecSecSessionBuff*>* subdictFinishIdx;
		auto searchDictByFinishIdx = dictByFinishIdx->find( keyFinishIdx );
		if( searchDictByFinishIdx != dictByFinishIdx->end() ) {
			subdictFinishIdx = searchDictByFinishIdx->second;
		}
		else {
			subdictFinishIdx = new std::map<cfsec::CFSecSecSessionPKey, cfsec::CFSecSecSessionBuff*>();
			dictByFinishIdx->insert( std::map<cfsec::CFSecSecSessionByFinishIdxKey,
				std::map<cfsec::CFSecSecSessionPKey,
					cfsec::CFSecSecSessionBuff*>*>::value_type( keyFinishIdx, subdictFinishIdx ) );
		}
		subdictFinishIdx->insert( std::map<cfsec::CFSecSecSessionPKey, cfsec::CFSecSecSessionBuff*>::value_type( pkey, buff ) );

		std::map<cfsec::CFSecSecSessionPKey, cfsec::CFSecSecSessionBuff*>* subdictSecProxyIdx;
		auto searchDictBySecProxyIdx = dictBySecProxyIdx->find( keySecProxyIdx );
		if( searchDictBySecProxyIdx != dictBySecProxyIdx->end() ) {
			subdictSecProxyIdx = searchDictBySecProxyIdx->second;
		}
		else {
			subdictSecProxyIdx = new std::map<cfsec::CFSecSecSessionPKey, cfsec::CFSecSecSessionBuff*>();
			dictBySecProxyIdx->insert( std::map<cfsec::CFSecSecSessionBySecProxyIdxKey,
				std::map<cfsec::CFSecSecSessionPKey,
					cfsec::CFSecSecSessionBuff*>*>::value_type( keySecProxyIdx, subdictSecProxyIdx ) );
		}
		subdictSecProxyIdx->insert( std::map<cfsec::CFSecSecSessionPKey, cfsec::CFSecSecSessionBuff*>::value_type( pkey, buff ) );

		// The top level code has to clone the final buffer. The one passed in is now part of the persistent storage.
		if( buff->getClassCode() == cfsec::CFSecSecSessionBuff::CLASS_CODE ) {
			buff = dynamic_cast<cfsec::CFSecSecSessionBuff*>( buff->clone() );
		}
		return( buff );
	}

	cfsec::CFSecSecSessionBuff* CFSecRamSecSessionTable::readDerived( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecSessionPKey* PKey )
	{
		static const std::string S_ProcName( "readDerived" );
		cfsec::CFSecSecSessionBuff* buff;
		auto searchDictByPKey = dictByPKey->find( *PKey );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfsec::CFSecSecSessionBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecSecSessionBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfsec::CFSecSecSessionBuff* CFSecRamSecSessionTable::lockDerived( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecSessionPKey* PKey )
	{
		static const std::string S_ProcName( "lockDerived" );
		cfsec::CFSecSecSessionBuff* buff;
		auto searchDictByPKey = dictByPKey->find( *PKey );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfsec::CFSecSecSessionBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecSecSessionBuff*>( buff->clone() );
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

	std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> CFSecRamSecSessionTable::readAllDerived( const cfsec::CFSecAuthorization* Authorization ) {
		static const std::string S_ProcName( "readAllDerived" );
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> retVec;
		std::map<cfsec::CFSecSecSessionPKey,
			cfsec::CFSecSecSessionBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecSecSessionPKey,
			cfsec::CFSecSecSessionBuff*>::iterator end = dictByPKey->end();
		cfsec::CFSecSecSessionBuff* clone;
		while( iter != end ) {
			clone = dynamic_cast<cfsec::CFSecSecSessionBuff*>( iter->second->clone() );
			retVec.push_back( clone );
			iter ++;
		}
		return( retVec );
	}

	std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> CFSecRamSecSessionTable::readDerivedBySecUserIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId )
	{
		static const std::string S_ProcName( "readDerivedBySecUserIdx" );
		cfsec::CFSecSecSessionBySecUserIdxKey key;
		key.setRequiredSecUserId( SecUserId );
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> recVec;
		cfsec::CFSecSecSessionBuff* clone;
		auto searchDictBySecUserIdx = dictBySecUserIdx->find( key );
		if( searchDictBySecUserIdx != dictBySecUserIdx->end() ) {
			std::map<cfsec::CFSecSecSessionPKey,
				 cfsec::CFSecSecSessionBuff*>* subdictSecUserIdx = searchDictBySecUserIdx->second;
			std::map<cfsec::CFSecSecSessionPKey,
				cfsec::CFSecSecSessionBuff*>::iterator iter = subdictSecUserIdx->begin();
			std::map<cfsec::CFSecSecSessionPKey,
				cfsec::CFSecSecSessionBuff*>::iterator end = subdictSecUserIdx->end();
			while( iter != end ) {
				clone = dynamic_cast<cfsec::CFSecSecSessionBuff*>( iter->second->clone() );
				recVec.push_back( clone );
				iter ++;
			}
		}
		return( recVec );
	}

	std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> CFSecRamSecSessionTable::readDerivedBySecDevIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId,
			const std::string* SecDevName )
	{
		static const std::string S_ProcName( "readDerivedBySecDevIdx" );
		cfsec::CFSecSecSessionBySecDevIdxKey key;
		key.setRequiredSecUserId( SecUserId );
		if( SecDevName == NULL ) {
			key.setOptionalSecDevNameNull();
		}
		else {
			key.setOptionalSecDevNameValue( *SecDevName );
		}
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> recVec;
		cfsec::CFSecSecSessionBuff* clone;
		auto searchDictBySecDevIdx = dictBySecDevIdx->find( key );
		if( searchDictBySecDevIdx != dictBySecDevIdx->end() ) {
			std::map<cfsec::CFSecSecSessionPKey,
				 cfsec::CFSecSecSessionBuff*>* subdictSecDevIdx = searchDictBySecDevIdx->second;
			std::map<cfsec::CFSecSecSessionPKey,
				cfsec::CFSecSecSessionBuff*>::iterator iter = subdictSecDevIdx->begin();
			std::map<cfsec::CFSecSecSessionPKey,
				cfsec::CFSecSecSessionBuff*>::iterator end = subdictSecDevIdx->end();
			while( iter != end ) {
				clone = dynamic_cast<cfsec::CFSecSecSessionBuff*>( iter->second->clone() );
				recVec.push_back( clone );
				iter ++;
			}
		}
		return( recVec );
	}

	cfsec::CFSecSecSessionBuff* CFSecRamSecSessionTable::readDerivedByStartIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId,
			const std::chrono::system_clock::time_point& Start )
	{
		static const std::string S_ProcName( "readDerivedByStartIdx" );
		cfsec::CFSecSecSessionByStartIdxKey key;
		key.setRequiredSecUserId( SecUserId );
		key.setRequiredStart( Start );
		cfsec::CFSecSecSessionBuff* buff;
		auto searchDictByStartIdx = dictByStartIdx->find( key );
		if( searchDictByStartIdx != dictByStartIdx->end() ) {
			buff = dynamic_cast<cfsec::CFSecSecSessionBuff*>( searchDictByStartIdx->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecSecSessionBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> CFSecRamSecSessionTable::readDerivedByFinishIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId,
			const std::chrono::system_clock::time_point* Finish )
	{
		static const std::string S_ProcName( "readDerivedByFinishIdx" );
		cfsec::CFSecSecSessionByFinishIdxKey key;
		key.setRequiredSecUserId( SecUserId );
		if( Finish == NULL ) {
			key.setOptionalFinishNull();
		}
		else {
			key.setOptionalFinishValue( *Finish );
		}
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> recVec;
		cfsec::CFSecSecSessionBuff* clone;
		auto searchDictByFinishIdx = dictByFinishIdx->find( key );
		if( searchDictByFinishIdx != dictByFinishIdx->end() ) {
			std::map<cfsec::CFSecSecSessionPKey,
				 cfsec::CFSecSecSessionBuff*>* subdictFinishIdx = searchDictByFinishIdx->second;
			std::map<cfsec::CFSecSecSessionPKey,
				cfsec::CFSecSecSessionBuff*>::iterator iter = subdictFinishIdx->begin();
			std::map<cfsec::CFSecSecSessionPKey,
				cfsec::CFSecSecSessionBuff*>::iterator end = subdictFinishIdx->end();
			while( iter != end ) {
				clone = dynamic_cast<cfsec::CFSecSecSessionBuff*>( iter->second->clone() );
				recVec.push_back( clone );
				iter ++;
			}
		}
		return( recVec );
	}

	std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> CFSecRamSecSessionTable::readDerivedBySecProxyIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecProxyId )
	{
		static const std::string S_ProcName( "readDerivedBySecProxyIdx" );
		cfsec::CFSecSecSessionBySecProxyIdxKey key;
		if( SecProxyId == NULL ) {
			key.setOptionalSecProxyIdNull();
		}
		else {
			key.setOptionalSecProxyIdValue( SecProxyId );
		}
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> recVec;
		cfsec::CFSecSecSessionBuff* clone;
		auto searchDictBySecProxyIdx = dictBySecProxyIdx->find( key );
		if( searchDictBySecProxyIdx != dictBySecProxyIdx->end() ) {
			std::map<cfsec::CFSecSecSessionPKey,
				 cfsec::CFSecSecSessionBuff*>* subdictSecProxyIdx = searchDictBySecProxyIdx->second;
			std::map<cfsec::CFSecSecSessionPKey,
				cfsec::CFSecSecSessionBuff*>::iterator iter = subdictSecProxyIdx->begin();
			std::map<cfsec::CFSecSecSessionPKey,
				cfsec::CFSecSecSessionBuff*>::iterator end = subdictSecProxyIdx->end();
			while( iter != end ) {
				clone = dynamic_cast<cfsec::CFSecSecSessionBuff*>( iter->second->clone() );
				recVec.push_back( clone );
				iter ++;
			}
		}
		return( recVec );
	}

	cfsec::CFSecSecSessionBuff* CFSecRamSecSessionTable::readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecSessionId )
	{
		static const std::string S_ProcName( "readDerivedByIdIdx" );
		cfsec::CFSecSecSessionPKey key;
		key.setRequiredSecSessionId( SecSessionId );
		cfsec::CFSecSecSessionBuff* buff;
		auto searchDictByPKey = dictByPKey->find( key );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfsec::CFSecSecSessionBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecSecSessionBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfsec::CFSecSecSessionBuff* CFSecRamSecSessionTable::readBuff( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecSessionPKey* PKey )
	{
		static const std::string S_ProcName( "readBuff" );
		cfsec::CFSecSecSessionBuff* buff = readDerived( Authorization, PKey );
		if( buff != NULL ) {
			if( buff->getClassCode() != cfsec::CFSecSecSessionBuff::CLASS_CODE ) {
				delete buff;
				buff = NULL;
			}
		}
		return( dynamic_cast<cfsec::CFSecSecSessionBuff*>( buff ) );
	}

	cfsec::CFSecSecSessionBuff* CFSecRamSecSessionTable::lockBuff( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecSessionPKey* PKey )
	{
		static const std::string S_ProcName( "lockBuff" );
		cfsec::CFSecSecSessionBuff* buff = lockDerived( Authorization, PKey );
		return( dynamic_cast<cfsec::CFSecSecSessionBuff*>( buff ) );
	}

	std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> CFSecRamSecSessionTable::readAllBuff( const cfsec::CFSecAuthorization* Authorization )
	{
		static const std::string S_ProcName( "readAllBuff" );
		cfsec::CFSecSecSessionBuff* buff;
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> filteredList;
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> buffList = readAllDerived( Authorization );
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfsec::CFSecSecSessionBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfsec::CFSecSecSessionBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> CFSecRamSecSessionTable::pageAllBuff( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t priorSecSessionId )
	{
		static const std::string S_ProcName( "pageAllBuff" );
		// MSS TODO WORKING
		throw cflib::CFLibNotImplementedYetException( CLASS_NAME, S_ProcName );
	}

	cfsec::CFSecSecSessionBuff* CFSecRamSecSessionTable::readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecSessionId )
	{
		static const std::string S_ProcName( "readBuffByIdIdx" );
		cfsec::CFSecSecSessionBuff* buff = readDerivedByIdIdx( Authorization,
			SecSessionId );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfsec::CFSecSecSessionBuff::CLASS_CODE ) {
			return( dynamic_cast<cfsec::CFSecSecSessionBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> CFSecRamSecSessionTable::readBuffBySecUserIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId )
	{
		static const std::string S_ProcName( "readBuffBySecUserIdx" );
		cfsec::CFSecSecSessionBuff* buff;
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> filteredList;
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> buffList = readDerivedBySecUserIdx( Authorization,
			SecUserId );
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfsec::CFSecSecSessionBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfsec::CFSecSecSessionBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> CFSecRamSecSessionTable::readBuffBySecDevIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId,
			const std::string* SecDevName )
	{
		static const std::string S_ProcName( "readBuffBySecDevIdx" );
		cfsec::CFSecSecSessionBuff* buff;
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> filteredList;
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> buffList = readDerivedBySecDevIdx( Authorization,
			SecUserId,
			SecDevName );
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfsec::CFSecSecSessionBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfsec::CFSecSecSessionBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	cfsec::CFSecSecSessionBuff* CFSecRamSecSessionTable::readBuffByStartIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId,
			const std::chrono::system_clock::time_point& Start )
	{
		static const std::string S_ProcName( "readBuffByStartIdx" );
		cfsec::CFSecSecSessionBuff* buff = readDerivedByStartIdx( Authorization,
			SecUserId,
			Start );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfsec::CFSecSecSessionBuff::CLASS_CODE ) {
			return( dynamic_cast<cfsec::CFSecSecSessionBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> CFSecRamSecSessionTable::readBuffByFinishIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId,
			const std::chrono::system_clock::time_point* Finish )
	{
		static const std::string S_ProcName( "readBuffByFinishIdx" );
		cfsec::CFSecSecSessionBuff* buff;
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> filteredList;
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> buffList = readDerivedByFinishIdx( Authorization,
			SecUserId,
			Finish );
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfsec::CFSecSecSessionBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfsec::CFSecSecSessionBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> CFSecRamSecSessionTable::readBuffBySecProxyIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecProxyId )
	{
		static const std::string S_ProcName( "readBuffBySecProxyIdx" );
		cfsec::CFSecSecSessionBuff* buff;
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> filteredList;
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> buffList = readDerivedBySecProxyIdx( Authorization,
			SecProxyId );
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfsec::CFSecSecSessionBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfsec::CFSecSecSessionBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> CFSecRamSecSessionTable::pageBuffBySecUserIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId,
			const uuid_ptr_t priorSecSessionId )
	{
		static const std::string S_ProcName( "pageBuffBySecUserIdx" );
		// MSS TODO WORKING
		throw cflib::CFLibNotImplementedYetException( CLASS_NAME, S_ProcName );
	}

	std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> CFSecRamSecSessionTable::pageBuffBySecDevIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId,
			const std::string* SecDevName,
			const uuid_ptr_t priorSecSessionId )
	{
		static const std::string S_ProcName( "pageBuffBySecDevIdx" );
		// MSS TODO WORKING
		throw cflib::CFLibNotImplementedYetException( CLASS_NAME, S_ProcName );
	}

	std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> CFSecRamSecSessionTable::pageBuffByFinishIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId,
			const std::chrono::system_clock::time_point* Finish,
			const uuid_ptr_t priorSecSessionId )
	{
		static const std::string S_ProcName( "pageBuffByFinishIdx" );
		// MSS TODO WORKING
		throw cflib::CFLibNotImplementedYetException( CLASS_NAME, S_ProcName );
	}

	std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> CFSecRamSecSessionTable::pageBuffBySecProxyIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecProxyId,
			const uuid_ptr_t priorSecSessionId )
	{
		static const std::string S_ProcName( "pageBuffBySecProxyIdx" );
		// MSS TODO WORKING
		throw cflib::CFLibNotImplementedYetException( CLASS_NAME, S_ProcName );
	}

	cfsec::CFSecSecSessionBuff* CFSecRamSecSessionTable::updateSecSession( const cfsec::CFSecAuthorization* Authorization,
		cfsec::CFSecSecSessionBuff* Buff )
	{
		static const std::string S_ProcName( "updateSecSession" );
		cfsec::CFSecSecSessionPKey pkey;
		pkey.setRequiredSecSessionId( Buff->getRequiredSecSessionId() );

		// Search for existing buffer

		auto searchExisting = dictByPKey->find( pkey );
		if( searchExisting == dictByPKey->end() ) {
			delete Buff;
			std::string Msg( "Existing record not found in SecSession for key " + pkey.toString() );
			throw cflib::CFLibStaleCacheDetectedException( CLASS_NAME,
				S_ProcName,
				Msg );
		}

		cfsec::CFSecSecSessionBuff* existing = searchExisting->second;

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
			std::string Msg( "Collision detected for SecSession primary key " );
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
		cfsec::CFSecSecSessionBySecUserIdxKey existingKeySecUserIdx;
		existingKeySecUserIdx.setRequiredSecUserId( existing->getRequiredSecUserId() );
		cfsec::CFSecSecSessionBySecUserIdxKey newKeySecUserIdx;
		newKeySecUserIdx.setRequiredSecUserId( Buff->getRequiredSecUserId() );
		cfsec::CFSecSecSessionBySecDevIdxKey existingKeySecDevIdx;
		existingKeySecDevIdx.setRequiredSecUserId( existing->getRequiredSecUserId() );
		if( existing->isOptionalSecDevNameNull() ) {
			existingKeySecDevIdx.setOptionalSecDevNameNull();
		}
		else {
			existingKeySecDevIdx.setOptionalSecDevNameValue( existing->getOptionalSecDevNameValue() );
		}
		cfsec::CFSecSecSessionBySecDevIdxKey newKeySecDevIdx;
		newKeySecDevIdx.setRequiredSecUserId( Buff->getRequiredSecUserId() );
		if( Buff->isOptionalSecDevNameNull() ) {
			newKeySecDevIdx.setOptionalSecDevNameNull();
		}
		else {
			newKeySecDevIdx.setOptionalSecDevNameValue( Buff->getOptionalSecDevNameValue() );
		}
		cfsec::CFSecSecSessionByStartIdxKey existingKeyStartIdx;
		existingKeyStartIdx.setRequiredSecUserId( existing->getRequiredSecUserId() );
		existingKeyStartIdx.setRequiredStart( existing->getRequiredStart() );
		cfsec::CFSecSecSessionByStartIdxKey newKeyStartIdx;
		newKeyStartIdx.setRequiredSecUserId( Buff->getRequiredSecUserId() );
		newKeyStartIdx.setRequiredStart( Buff->getRequiredStart() );
		cfsec::CFSecSecSessionByFinishIdxKey existingKeyFinishIdx;
		existingKeyFinishIdx.setRequiredSecUserId( existing->getRequiredSecUserId() );
		if( existing->isOptionalFinishNull() ) {
			existingKeyFinishIdx.setOptionalFinishNull();
		}
		else {
			existingKeyFinishIdx.setOptionalFinishValue( existing->getOptionalFinishValue() );
		}
		cfsec::CFSecSecSessionByFinishIdxKey newKeyFinishIdx;
		newKeyFinishIdx.setRequiredSecUserId( Buff->getRequiredSecUserId() );
		if( Buff->isOptionalFinishNull() ) {
			newKeyFinishIdx.setOptionalFinishNull();
		}
		else {
			newKeyFinishIdx.setOptionalFinishValue( Buff->getOptionalFinishValue() );
		}
		cfsec::CFSecSecSessionBySecProxyIdxKey existingKeySecProxyIdx;
		if( existing->isOptionalSecProxyIdNull() ) {
			existingKeySecProxyIdx.setOptionalSecProxyIdNull();
		}
		else {
			existingKeySecProxyIdx.setOptionalSecProxyIdValue( existing->getOptionalSecProxyIdValue() );
		}
		cfsec::CFSecSecSessionBySecProxyIdxKey newKeySecProxyIdx;
		if( Buff->isOptionalSecProxyIdNull() ) {
			newKeySecProxyIdx.setOptionalSecProxyIdNull();
		}
		else {
			newKeySecProxyIdx.setOptionalSecProxyIdValue( Buff->getOptionalSecProxyIdValue() );
		}
		// Check unique indexes

		if( existingKeyStartIdx != newKeyStartIdx ) {
			auto searchDictByStartIdx = dictByStartIdx->find( newKeyStartIdx );
			if( searchDictByStartIdx != dictByStartIdx->end() ) {
				std::string Msg( "Duplicate key detected for index SessionStartIdx " + newKeyStartIdx.toString() );
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
					std::string Msg( "Could not resolve Container relationship SecSessionUser to table SecUser" );
					throw cflib::CFLibUnresolvedRelationException( CLASS_NAME,
						S_ProcName,
						Msg );
				}
				delete chk;
				chk = NULL;
			}
		}

		// Update is valid
		std::map<cfsec::CFSecSecSessionPKey, cfsec::CFSecSecSessionBuff*>* subdict;
		auto removalDictByPKey = dictByPKey->find( pkey );
		if( removalDictByPKey != dictByPKey->end() ) {
			dictByPKey->erase( removalDictByPKey );
		}
		// Copy edited buffer to existing persistent buffer

		if( Buff->getClassCode() != cfsec::CFSecSecSessionBuff::CLASS_CODE ) {
			const static std::string S_IsNotA( " is not a cfsec::CFSecSecSessionBuff" );
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

		dictByPKey->insert( std::map<cfsec::CFSecSecSessionPKey, cfsec::CFSecSecSessionBuff*>::value_type( pkey, existing ) );

		std::map<cfsec::CFSecSecSessionPKey,
			 cfsec::CFSecSecSessionBuff*>* subdictSecUserIdx;
		auto searchDictBySecUserIdx = dictBySecUserIdx->find( existingKeySecUserIdx );
		if( searchDictBySecUserIdx != dictBySecUserIdx->end() ) {
			subdictSecUserIdx = searchDictBySecUserIdx->second;
			auto searchSubDict = subdictSecUserIdx->find( pkey );
			if( searchSubDict != subdictSecUserIdx->end() ) {
				subdictSecUserIdx->erase( searchSubDict );
			}
			if( subdictSecUserIdx->size() <= 0 ) {
				delete subdictSecUserIdx;
				dictBySecUserIdx->erase( searchDictBySecUserIdx );
			}
			subdictSecUserIdx = NULL;
		}
		auto searchNewKeyDictBySecUserIdx = dictBySecUserIdx->find( newKeySecUserIdx );
		if( searchNewKeyDictBySecUserIdx != dictBySecUserIdx->end() ) {
			subdictSecUserIdx = searchNewKeyDictBySecUserIdx->second;
		}
		else {
			subdictSecUserIdx = new std::map<cfsec::CFSecSecSessionPKey, cfsec::CFSecSecSessionBuff*>();
			dictBySecUserIdx->insert( std::map<cfsec::CFSecSecSessionBySecUserIdxKey,
				std::map<cfsec::CFSecSecSessionPKey,
					cfsec::CFSecSecSessionBuff*>*>::value_type( newKeySecUserIdx, subdictSecUserIdx ) );
		}
		subdictSecUserIdx->insert( std::map<cfsec::CFSecSecSessionPKey, cfsec::CFSecSecSessionBuff*>::value_type( pkey, existing ) );

		std::map<cfsec::CFSecSecSessionPKey,
			 cfsec::CFSecSecSessionBuff*>* subdictSecDevIdx;
		auto searchDictBySecDevIdx = dictBySecDevIdx->find( existingKeySecDevIdx );
		if( searchDictBySecDevIdx != dictBySecDevIdx->end() ) {
			subdictSecDevIdx = searchDictBySecDevIdx->second;
			auto searchSubDict = subdictSecDevIdx->find( pkey );
			if( searchSubDict != subdictSecDevIdx->end() ) {
				subdictSecDevIdx->erase( searchSubDict );
			}
			if( subdictSecDevIdx->size() <= 0 ) {
				delete subdictSecDevIdx;
				dictBySecDevIdx->erase( searchDictBySecDevIdx );
			}
			subdictSecDevIdx = NULL;
		}
		auto searchNewKeyDictBySecDevIdx = dictBySecDevIdx->find( newKeySecDevIdx );
		if( searchNewKeyDictBySecDevIdx != dictBySecDevIdx->end() ) {
			subdictSecDevIdx = searchNewKeyDictBySecDevIdx->second;
		}
		else {
			subdictSecDevIdx = new std::map<cfsec::CFSecSecSessionPKey, cfsec::CFSecSecSessionBuff*>();
			dictBySecDevIdx->insert( std::map<cfsec::CFSecSecSessionBySecDevIdxKey,
				std::map<cfsec::CFSecSecSessionPKey,
					cfsec::CFSecSecSessionBuff*>*>::value_type( newKeySecDevIdx, subdictSecDevIdx ) );
		}
		subdictSecDevIdx->insert( std::map<cfsec::CFSecSecSessionPKey, cfsec::CFSecSecSessionBuff*>::value_type( pkey, existing ) );

		auto removalDictByStartIdx = dictByStartIdx->find( existingKeyStartIdx );
		if( removalDictByStartIdx != dictByStartIdx->end() ) {
			dictByStartIdx->erase( removalDictByStartIdx );
		}
		dictByStartIdx->insert( std::map<cfsec::CFSecSecSessionByStartIdxKey, cfsec::CFSecSecSessionBuff*>::value_type( newKeyStartIdx, existing ) );

		std::map<cfsec::CFSecSecSessionPKey,
			 cfsec::CFSecSecSessionBuff*>* subdictFinishIdx;
		auto searchDictByFinishIdx = dictByFinishIdx->find( existingKeyFinishIdx );
		if( searchDictByFinishIdx != dictByFinishIdx->end() ) {
			subdictFinishIdx = searchDictByFinishIdx->second;
			auto searchSubDict = subdictFinishIdx->find( pkey );
			if( searchSubDict != subdictFinishIdx->end() ) {
				subdictFinishIdx->erase( searchSubDict );
			}
			if( subdictFinishIdx->size() <= 0 ) {
				delete subdictFinishIdx;
				dictByFinishIdx->erase( searchDictByFinishIdx );
			}
			subdictFinishIdx = NULL;
		}
		auto searchNewKeyDictByFinishIdx = dictByFinishIdx->find( newKeyFinishIdx );
		if( searchNewKeyDictByFinishIdx != dictByFinishIdx->end() ) {
			subdictFinishIdx = searchNewKeyDictByFinishIdx->second;
		}
		else {
			subdictFinishIdx = new std::map<cfsec::CFSecSecSessionPKey, cfsec::CFSecSecSessionBuff*>();
			dictByFinishIdx->insert( std::map<cfsec::CFSecSecSessionByFinishIdxKey,
				std::map<cfsec::CFSecSecSessionPKey,
					cfsec::CFSecSecSessionBuff*>*>::value_type( newKeyFinishIdx, subdictFinishIdx ) );
		}
		subdictFinishIdx->insert( std::map<cfsec::CFSecSecSessionPKey, cfsec::CFSecSecSessionBuff*>::value_type( pkey, existing ) );

		std::map<cfsec::CFSecSecSessionPKey,
			 cfsec::CFSecSecSessionBuff*>* subdictSecProxyIdx;
		auto searchDictBySecProxyIdx = dictBySecProxyIdx->find( existingKeySecProxyIdx );
		if( searchDictBySecProxyIdx != dictBySecProxyIdx->end() ) {
			subdictSecProxyIdx = searchDictBySecProxyIdx->second;
			auto searchSubDict = subdictSecProxyIdx->find( pkey );
			if( searchSubDict != subdictSecProxyIdx->end() ) {
				subdictSecProxyIdx->erase( searchSubDict );
			}
			if( subdictSecProxyIdx->size() <= 0 ) {
				delete subdictSecProxyIdx;
				dictBySecProxyIdx->erase( searchDictBySecProxyIdx );
			}
			subdictSecProxyIdx = NULL;
		}
		auto searchNewKeyDictBySecProxyIdx = dictBySecProxyIdx->find( newKeySecProxyIdx );
		if( searchNewKeyDictBySecProxyIdx != dictBySecProxyIdx->end() ) {
			subdictSecProxyIdx = searchNewKeyDictBySecProxyIdx->second;
		}
		else {
			subdictSecProxyIdx = new std::map<cfsec::CFSecSecSessionPKey, cfsec::CFSecSecSessionBuff*>();
			dictBySecProxyIdx->insert( std::map<cfsec::CFSecSecSessionBySecProxyIdxKey,
				std::map<cfsec::CFSecSecSessionPKey,
					cfsec::CFSecSecSessionBuff*>*>::value_type( newKeySecProxyIdx, subdictSecProxyIdx ) );
		}
		subdictSecProxyIdx->insert( std::map<cfsec::CFSecSecSessionPKey, cfsec::CFSecSecSessionBuff*>::value_type( pkey, existing ) );


		// The top level code has to clean up the memory buffer that was passed in, and return a clone
		// of the copy that existing buffer that is attached to the RAM storage.  All other cases
		// return the existing buffer.

		cfsec::CFSecSecSessionBuff* buff;
		if( existing->getClassCode() == cfsec::CFSecSecSessionBuff::CLASS_CODE ) {
			delete Buff;
			Buff = NULL;
			buff = dynamic_cast<cfsec::CFSecSecSessionBuff*>( existing->clone() );
		}
		else {
			buff = existing;
		}
		return( buff );
	}

	void CFSecRamSecSessionTable::deleteSecSession( const cfsec::CFSecAuthorization* Authorization,
		cfsec::CFSecSecSessionBuff* Buff )
	{
		static const std::string S_ProcName( "deleteSecSession" );
		static const std::string S_Prev( "prev" );
		classcode_t classCode;
		cfsec::CFSecSecSessionPKey pkey;
		pkey.setRequiredSecSessionId( Buff->getRequiredSecSessionId() );
		auto searchExisting = dictByPKey->find( pkey );
		if( searchExisting == dictByPKey->end() ) {
			return;
		}
		cfsec::CFSecSecSessionBuff* existing = searchExisting->second;
		cfsec::CFSecSecSessionBySecUserIdxKey keySecUserIdx;
		keySecUserIdx.setRequiredSecUserId( existing->getRequiredSecUserId() );
		cfsec::CFSecSecSessionBySecDevIdxKey keySecDevIdx;
		keySecDevIdx.setRequiredSecUserId( existing->getRequiredSecUserId() );
		if( existing->isOptionalSecDevNameNull() ) {
			keySecDevIdx.setOptionalSecDevNameNull();
		}
		else {
			keySecDevIdx.setOptionalSecDevNameValue( existing->getOptionalSecDevNameValue() );
		}
		cfsec::CFSecSecSessionByStartIdxKey keyStartIdx;
		keyStartIdx.setRequiredSecUserId( existing->getRequiredSecUserId() );
		keyStartIdx.setRequiredStart( existing->getRequiredStart() );
		cfsec::CFSecSecSessionByFinishIdxKey keyFinishIdx;
		keyFinishIdx.setRequiredSecUserId( existing->getRequiredSecUserId() );
		if( existing->isOptionalFinishNull() ) {
			keyFinishIdx.setOptionalFinishNull();
		}
		else {
			keyFinishIdx.setOptionalFinishValue( existing->getOptionalFinishValue() );
		}
		cfsec::CFSecSecSessionBySecProxyIdxKey keySecProxyIdx;
		if( existing->isOptionalSecProxyIdNull() ) {
			keySecProxyIdx.setOptionalSecProxyIdNull();
		}
		else {
			keySecProxyIdx.setOptionalSecProxyIdValue( existing->getOptionalSecProxyIdValue() );
		}
		// Validate reverse foreign keys

		// Delete is valid
		std::map<cfsec::CFSecSecSessionPKey, cfsec::CFSecSecSessionBuff*>* subdict;

		auto searchDictByPKey = dictByPKey->find( pkey );
		if( searchDictByPKey != dictByPKey->end() ) {
			dictByPKey->erase( searchDictByPKey );
		}

		auto searchDictBySecUserIdx = dictBySecUserIdx->find( keySecUserIdx );
		if( searchDictBySecUserIdx != dictBySecUserIdx->end() ) {
			std::map<cfsec::CFSecSecSessionPKey,
				 cfsec::CFSecSecSessionBuff*>* subdictSecUserIdx = searchDictBySecUserIdx->second;
			auto searchSubDict = subdictSecUserIdx->find( pkey );
			if( searchSubDict != subdictSecUserIdx->end() ) {
				subdictSecUserIdx->erase( searchSubDict );
			}
			subdictSecUserIdx = NULL;
		}

		auto searchDictBySecDevIdx = dictBySecDevIdx->find( keySecDevIdx );
		if( searchDictBySecDevIdx != dictBySecDevIdx->end() ) {
			std::map<cfsec::CFSecSecSessionPKey,
				 cfsec::CFSecSecSessionBuff*>* subdictSecDevIdx = searchDictBySecDevIdx->second;
			auto searchSubDict = subdictSecDevIdx->find( pkey );
			if( searchSubDict != subdictSecDevIdx->end() ) {
				subdictSecDevIdx->erase( searchSubDict );
			}
			subdictSecDevIdx = NULL;
		}

		auto searchDictByStartIdx = dictByStartIdx->find( keyStartIdx );
		if( searchDictByStartIdx != dictByStartIdx->end() ) {
			dictByStartIdx->erase( searchDictByStartIdx );
		}

		auto searchDictByFinishIdx = dictByFinishIdx->find( keyFinishIdx );
		if( searchDictByFinishIdx != dictByFinishIdx->end() ) {
			std::map<cfsec::CFSecSecSessionPKey,
				 cfsec::CFSecSecSessionBuff*>* subdictFinishIdx = searchDictByFinishIdx->second;
			auto searchSubDict = subdictFinishIdx->find( pkey );
			if( searchSubDict != subdictFinishIdx->end() ) {
				subdictFinishIdx->erase( searchSubDict );
			}
			subdictFinishIdx = NULL;
		}

		auto searchDictBySecProxyIdx = dictBySecProxyIdx->find( keySecProxyIdx );
		if( searchDictBySecProxyIdx != dictBySecProxyIdx->end() ) {
			std::map<cfsec::CFSecSecSessionPKey,
				 cfsec::CFSecSecSessionBuff*>* subdictSecProxyIdx = searchDictBySecProxyIdx->second;
			auto searchSubDict = subdictSecProxyIdx->find( pkey );
			if( searchSubDict != subdictSecProxyIdx->end() ) {
				subdictSecProxyIdx->erase( searchSubDict );
			}
			subdictSecProxyIdx = NULL;
		}

		if( existing != NULL ) {
			delete existing;
			existing = NULL;
		}
	}

	void CFSecRamSecSessionTable::deleteSecSessionByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t argSecSessionId )
	{
		cfsec::CFSecSecSessionPKey key;
		key.setRequiredSecSessionId( argSecSessionId );
		deleteSecSessionByIdIdx( Authorization, &key );
	}

	void CFSecRamSecSessionTable::deleteSecSessionByIdIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecSessionPKey* argKey )
	{
		bool anyNotNull = false;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		cfsec::CFSecSecSessionBuff* cur = NULL;
		cfsec::CFSecSecSessionBuff* rereadCur = NULL;
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> matchSet;
		std::map<cfsec::CFSecSecSessionPKey,
			cfsec::CFSecSecSessionBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecSecSessionPKey,
			cfsec::CFSecSecSessionBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecSecSessionBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecSecSessionBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableSecSession()->readDerivedByIdIdx( Authorization,
				cur->getRequiredSecSessionId() );
			rereadCur = cur;
			deleteSecSession( Authorization, cur );
			if( rereadCur != NULL ) {
				delete rereadCur;
				rereadCur = NULL;
			}
		}
	}

	void CFSecRamSecSessionTable::deleteSecSessionBySecUserIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t argSecUserId )
	{
		cfsec::CFSecSecSessionBySecUserIdxKey key;
		key.setRequiredSecUserId( argSecUserId );
		deleteSecSessionBySecUserIdx( Authorization, &key );
	}

	void CFSecRamSecSessionTable::deleteSecSessionBySecUserIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecSessionBySecUserIdxKey* argKey )
	{
		cfsec::CFSecSecSessionBuff* cur = NULL;
		cfsec::CFSecSecSessionBuff* rereadCur = NULL;
		bool anyNotNull = false;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> matchSet;
		std::map<cfsec::CFSecSecSessionPKey,
			cfsec::CFSecSecSessionBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecSecSessionPKey,
			cfsec::CFSecSecSessionBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecSecSessionBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecSecSessionBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableSecSession()->readDerivedByIdIdx( Authorization,
				cur->getRequiredSecSessionId() );
			rereadCur = cur;
			deleteSecSession( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFSecRamSecSessionTable::deleteSecSessionBySecDevIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t argSecUserId,
			const std::string* argSecDevName )
	{
		cfsec::CFSecSecSessionBySecDevIdxKey key;
		key.setRequiredSecUserId( argSecUserId );
		if( argSecDevName == NULL ) {
			key.setOptionalSecDevNameNull();
		}
		else {
			key.setOptionalSecDevNameValue( *argSecDevName );
		}
		deleteSecSessionBySecDevIdx( Authorization, &key );
	}

	void CFSecRamSecSessionTable::deleteSecSessionBySecDevIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecSessionBySecDevIdxKey* argKey )
	{
		cfsec::CFSecSecSessionBuff* cur = NULL;
		cfsec::CFSecSecSessionBuff* rereadCur = NULL;
		bool anyNotNull = false;
		anyNotNull = true;
		if( argKey->isOptionalSecDevNameNull() ) {
			anyNotNull = true;
		}
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> matchSet;
		std::map<cfsec::CFSecSecSessionPKey,
			cfsec::CFSecSecSessionBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecSecSessionPKey,
			cfsec::CFSecSecSessionBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecSecSessionBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecSecSessionBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableSecSession()->readDerivedByIdIdx( Authorization,
				cur->getRequiredSecSessionId() );
			rereadCur = cur;
			deleteSecSession( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFSecRamSecSessionTable::deleteSecSessionByStartIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t argSecUserId,
			const std::chrono::system_clock::time_point& argStart )
	{
		cfsec::CFSecSecSessionByStartIdxKey key;
		key.setRequiredSecUserId( argSecUserId );
		key.setRequiredStart( argStart );
		deleteSecSessionByStartIdx( Authorization, &key );
	}

	void CFSecRamSecSessionTable::deleteSecSessionByStartIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecSessionByStartIdxKey* argKey )
	{
		cfsec::CFSecSecSessionBuff* cur = NULL;
		cfsec::CFSecSecSessionBuff* rereadCur = NULL;
		bool anyNotNull = false;
		anyNotNull = true;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> matchSet;
		std::map<cfsec::CFSecSecSessionPKey,
			cfsec::CFSecSecSessionBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecSecSessionPKey,
			cfsec::CFSecSecSessionBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecSecSessionBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecSecSessionBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableSecSession()->readDerivedByIdIdx( Authorization,
				cur->getRequiredSecSessionId() );
			rereadCur = cur;
			deleteSecSession( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFSecRamSecSessionTable::deleteSecSessionByFinishIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t argSecUserId,
			const std::chrono::system_clock::time_point* argFinish )
	{
		cfsec::CFSecSecSessionByFinishIdxKey key;
		key.setRequiredSecUserId( argSecUserId );
		if( argFinish == NULL ) {
			key.setOptionalFinishNull();
		}
		else {
			key.setOptionalFinishValue( *argFinish );
		}
		deleteSecSessionByFinishIdx( Authorization, &key );
	}

	void CFSecRamSecSessionTable::deleteSecSessionByFinishIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecSessionByFinishIdxKey* argKey )
	{
		cfsec::CFSecSecSessionBuff* cur = NULL;
		cfsec::CFSecSecSessionBuff* rereadCur = NULL;
		bool anyNotNull = false;
		anyNotNull = true;
		if( argKey->isOptionalFinishNull() ) {
			anyNotNull = true;
		}
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> matchSet;
		std::map<cfsec::CFSecSecSessionPKey,
			cfsec::CFSecSecSessionBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecSecSessionPKey,
			cfsec::CFSecSecSessionBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecSecSessionBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecSecSessionBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableSecSession()->readDerivedByIdIdx( Authorization,
				cur->getRequiredSecSessionId() );
			rereadCur = cur;
			deleteSecSession( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFSecRamSecSessionTable::deleteSecSessionBySecProxyIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t argSecProxyId )
	{
		cfsec::CFSecSecSessionBySecProxyIdxKey key;
		if( argSecProxyId == NULL ) {
			key.setOptionalSecProxyIdNull();
		}
		else {
			key.setOptionalSecProxyIdValue( argSecProxyId );
		}
		deleteSecSessionBySecProxyIdx( Authorization, &key );
	}

	void CFSecRamSecSessionTable::deleteSecSessionBySecProxyIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecSessionBySecProxyIdxKey* argKey )
	{
		cfsec::CFSecSecSessionBuff* cur = NULL;
		cfsec::CFSecSecSessionBuff* rereadCur = NULL;
		bool anyNotNull = false;
		if( argKey->isOptionalSecProxyIdNull() ) {
			anyNotNull = true;
		}
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> matchSet;
		std::map<cfsec::CFSecSecSessionPKey,
			cfsec::CFSecSecSessionBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecSecSessionPKey,
			cfsec::CFSecSecSessionBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecSecSessionBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecSecSessionBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableSecSession()->readDerivedByIdIdx( Authorization,
				cur->getRequiredSecSessionId() );
			rereadCur = cur;
			deleteSecSession( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFSecRamSecSessionTable::releasePreparedStatements() {
	}

}
