
// Description: C++18 Implementation for an in-memory RAM DbIO for HostNode.

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

	const std::string CFSecRamHostNodeTable::CLASS_NAME( "CFSecRamHostNodeTable" );

	CFSecRamHostNodeTable::CFSecRamHostNodeTable( ICFSecSchema* argSchema )
	: cfsec::ICFSecHostNodeTable()
	{
		schema = argSchema;
		dictByPKey = new std::map<cfsec::CFSecHostNodePKey, cfsec::CFSecHostNodeBuff*>();
		dictByClusterIdx = new std::map<cfsec::CFSecHostNodeByClusterIdxKey,
			std::map<cfsec::CFSecHostNodePKey,
				cfsec::CFSecHostNodeBuff*>*>();
		dictByUDescrIdx = new std::map<cfsec::CFSecHostNodeByUDescrIdxKey, cfsec::CFSecHostNodeBuff*>();
		dictByHostNameIdx = new std::map<cfsec::CFSecHostNodeByHostNameIdxKey, cfsec::CFSecHostNodeBuff*>();
	}

	CFSecRamHostNodeTable::~CFSecRamHostNodeTable() {
		if( dictByClusterIdx != NULL ) {
			for( auto iterDict = dictByClusterIdx->begin(); iterDict != dictByClusterIdx->end(); iterDict ++ ) {
				delete iterDict->second;
				iterDict->second = NULL;
			}
			delete dictByClusterIdx;
			dictByClusterIdx = NULL;
		}
		if( dictByUDescrIdx != NULL ) {
			delete dictByUDescrIdx;
			dictByUDescrIdx = NULL;
		}
		if( dictByHostNameIdx != NULL ) {
			delete dictByHostNameIdx;
			dictByHostNameIdx = NULL;
		}
		if( dictByPKey != NULL ) {
			cfsec::CFSecHostNodeBuff* elt;
			std::map<cfsec::CFSecHostNodePKey,
				cfsec::CFSecHostNodeBuff*>::iterator end = dictByPKey->end();
			for( std::map<cfsec::CFSecHostNodePKey,
					cfsec::CFSecHostNodeBuff*>::iterator cur = dictByPKey->begin();
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

	cfsec::CFSecHostNodeBuff* CFSecRamHostNodeTable::createHostNode( const cfsec::CFSecAuthorization* Authorization,
		cfsec::CFSecHostNodeBuff* Buff )
	{
		static const std::string S_ProcName( "createHostNode" );
		cfsec::CFSecHostNodePKey pkey;
		pkey.setRequiredClusterId( Buff->getRequiredClusterId() );
		pkey.setRequiredHostNodeId( dynamic_cast<CFSecRamClusterTable*>( schema->getTableCluster() )->nextHostNodeIdGen( Authorization,
			Buff->getRequiredClusterId() ) );
		Buff->setRequiredClusterId( pkey.getRequiredClusterId() );
		Buff->setRequiredHostNodeId( pkey.getRequiredHostNodeId() );
		cfsec::CFSecHostNodeByClusterIdxKey keyClusterIdx;
		keyClusterIdx.setRequiredClusterId( Buff->getRequiredClusterId() );
		cfsec::CFSecHostNodeByUDescrIdxKey keyUDescrIdx;
		keyUDescrIdx.setRequiredClusterId( Buff->getRequiredClusterId() );
		keyUDescrIdx.setRequiredDescription( Buff->getRequiredDescription() );
		cfsec::CFSecHostNodeByHostNameIdxKey keyHostNameIdx;
		keyHostNameIdx.setRequiredClusterId( Buff->getRequiredClusterId() );
		keyHostNameIdx.setRequiredHostName( Buff->getRequiredHostName() );
		// Validate unique indexes
		auto searchDictByPKey = dictByPKey->find( pkey );
		if( searchDictByPKey != dictByPKey->end() ) {
			delete Buff;
			std::string Msg( "Duplicate primary key detected " + pkey.toString() );
			throw cflib::CFLibPrimaryKeyNotNewException( CLASS_NAME, S_ProcName, Msg );
		}

		auto searchDictByUDescrIdx = dictByUDescrIdx->find( keyUDescrIdx );
		if( searchDictByUDescrIdx != dictByUDescrIdx->end() ) {
			std::string Msg( "Duplicate key detected for index HostNodeUDescrIdx " + keyUDescrIdx.toString() );
			delete Buff;
			throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
				S_ProcName,
				Msg );
		}

		auto searchDictByHostNameIdx = dictByHostNameIdx->find( keyHostNameIdx );
		if( searchDictByHostNameIdx != dictByHostNameIdx->end() ) {
			std::string Msg( "Duplicate key detected for index HostNodeUHostNameIdx " + keyHostNameIdx.toString() );
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
					std::string Msg( "Could not resolve Container relationship HostNodeCluster to table Cluster" );
					throw cflib::CFLibUnresolvedRelationException( CLASS_NAME,
						S_ProcName,
						Msg );
				}
				delete chk;
				chk = NULL;
			}
		}

		// Proceed with adding the new record
		cfsec::CFSecHostNodeBuff* buff = Buff;
		buff->setRequiredRevision( 1 );
		dictByPKey->insert( std::map<cfsec::CFSecHostNodePKey, cfsec::CFSecHostNodeBuff*>::value_type( pkey, buff ) );

		std::map<cfsec::CFSecHostNodePKey, cfsec::CFSecHostNodeBuff*>* subdictClusterIdx;
		auto searchDictByClusterIdx = dictByClusterIdx->find( keyClusterIdx );
		if( searchDictByClusterIdx != dictByClusterIdx->end() ) {
			subdictClusterIdx = searchDictByClusterIdx->second;
		}
		else {
			subdictClusterIdx = new std::map<cfsec::CFSecHostNodePKey, cfsec::CFSecHostNodeBuff*>();
			dictByClusterIdx->insert( std::map<cfsec::CFSecHostNodeByClusterIdxKey,
				std::map<cfsec::CFSecHostNodePKey,
					cfsec::CFSecHostNodeBuff*>*>::value_type( keyClusterIdx, subdictClusterIdx ) );
		}
		subdictClusterIdx->insert( std::map<cfsec::CFSecHostNodePKey, cfsec::CFSecHostNodeBuff*>::value_type( pkey, buff ) );

		dictByUDescrIdx->insert( std::map<cfsec::CFSecHostNodeByUDescrIdxKey, cfsec::CFSecHostNodeBuff*>::value_type( keyUDescrIdx, buff ) );

		dictByHostNameIdx->insert( std::map<cfsec::CFSecHostNodeByHostNameIdxKey, cfsec::CFSecHostNodeBuff*>::value_type( keyHostNameIdx, buff ) );

		// The top level code has to clone the final buffer. The one passed in is now part of the persistent storage.
		if( buff->getClassCode() == cfsec::CFSecHostNodeBuff::CLASS_CODE ) {
			buff = dynamic_cast<cfsec::CFSecHostNodeBuff*>( buff->clone() );
		}
		return( buff );
	}

	cfsec::CFSecHostNodeBuff* CFSecRamHostNodeTable::readDerived( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecHostNodePKey* PKey )
	{
		static const std::string S_ProcName( "readDerived" );
		cfsec::CFSecHostNodeBuff* buff;
		auto searchDictByPKey = dictByPKey->find( *PKey );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfsec::CFSecHostNodeBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecHostNodeBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfsec::CFSecHostNodeBuff* CFSecRamHostNodeTable::lockDerived( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecHostNodePKey* PKey )
	{
		static const std::string S_ProcName( "lockDerived" );
		cfsec::CFSecHostNodeBuff* buff;
		auto searchDictByPKey = dictByPKey->find( *PKey );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfsec::CFSecHostNodeBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecHostNodeBuff*>( buff->clone() );
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

	std::TCFLibOwningVector<cfsec::CFSecHostNodeBuff*> CFSecRamHostNodeTable::readAllDerived( const cfsec::CFSecAuthorization* Authorization ) {
		static const std::string S_ProcName( "readAllDerived" );
		std::TCFLibOwningVector<cfsec::CFSecHostNodeBuff*> retVec;
		std::map<cfsec::CFSecHostNodePKey,
			cfsec::CFSecHostNodeBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecHostNodePKey,
			cfsec::CFSecHostNodeBuff*>::iterator end = dictByPKey->end();
		cfsec::CFSecHostNodeBuff* clone;
		while( iter != end ) {
			clone = dynamic_cast<cfsec::CFSecHostNodeBuff*>( iter->second->clone() );
			retVec.push_back( clone );
			iter ++;
		}
		return( retVec );
	}

	std::TCFLibOwningVector<cfsec::CFSecHostNodeBuff*> CFSecRamHostNodeTable::readDerivedByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId )
	{
		static const std::string S_ProcName( "readDerivedByClusterIdx" );
		cfsec::CFSecHostNodeByClusterIdxKey key;
		key.setRequiredClusterId( ClusterId );
		std::TCFLibOwningVector<cfsec::CFSecHostNodeBuff*> recVec;
		cfsec::CFSecHostNodeBuff* clone;
		auto searchDictByClusterIdx = dictByClusterIdx->find( key );
		if( searchDictByClusterIdx != dictByClusterIdx->end() ) {
			std::map<cfsec::CFSecHostNodePKey,
				 cfsec::CFSecHostNodeBuff*>* subdictClusterIdx = searchDictByClusterIdx->second;
			std::map<cfsec::CFSecHostNodePKey,
				cfsec::CFSecHostNodeBuff*>::iterator iter = subdictClusterIdx->begin();
			std::map<cfsec::CFSecHostNodePKey,
				cfsec::CFSecHostNodeBuff*>::iterator end = subdictClusterIdx->end();
			while( iter != end ) {
				clone = dynamic_cast<cfsec::CFSecHostNodeBuff*>( iter->second->clone() );
				recVec.push_back( clone );
				iter ++;
			}
		}
		return( recVec );
	}

	cfsec::CFSecHostNodeBuff* CFSecRamHostNodeTable::readDerivedByUDescrIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const std::string& Description )
	{
		static const std::string S_ProcName( "readDerivedByUDescrIdx" );
		cfsec::CFSecHostNodeByUDescrIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredDescription( Description );
		cfsec::CFSecHostNodeBuff* buff;
		auto searchDictByUDescrIdx = dictByUDescrIdx->find( key );
		if( searchDictByUDescrIdx != dictByUDescrIdx->end() ) {
			buff = dynamic_cast<cfsec::CFSecHostNodeBuff*>( searchDictByUDescrIdx->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecHostNodeBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfsec::CFSecHostNodeBuff* CFSecRamHostNodeTable::readDerivedByHostNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const std::string& HostName )
	{
		static const std::string S_ProcName( "readDerivedByHostNameIdx" );
		cfsec::CFSecHostNodeByHostNameIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredHostName( HostName );
		cfsec::CFSecHostNodeBuff* buff;
		auto searchDictByHostNameIdx = dictByHostNameIdx->find( key );
		if( searchDictByHostNameIdx != dictByHostNameIdx->end() ) {
			buff = dynamic_cast<cfsec::CFSecHostNodeBuff*>( searchDictByHostNameIdx->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecHostNodeBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfsec::CFSecHostNodeBuff* CFSecRamHostNodeTable::readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t HostNodeId )
	{
		static const std::string S_ProcName( "readDerivedByIdIdx" );
		cfsec::CFSecHostNodePKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredHostNodeId( HostNodeId );
		cfsec::CFSecHostNodeBuff* buff;
		auto searchDictByPKey = dictByPKey->find( key );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfsec::CFSecHostNodeBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecHostNodeBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfsec::CFSecHostNodeBuff* CFSecRamHostNodeTable::readBuff( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecHostNodePKey* PKey )
	{
		static const std::string S_ProcName( "readBuff" );
		cfsec::CFSecHostNodeBuff* buff = readDerived( Authorization, PKey );
		if( buff != NULL ) {
			if( buff->getClassCode() != cfsec::CFSecHostNodeBuff::CLASS_CODE ) {
				delete buff;
				buff = NULL;
			}
		}
		return( dynamic_cast<cfsec::CFSecHostNodeBuff*>( buff ) );
	}

	cfsec::CFSecHostNodeBuff* CFSecRamHostNodeTable::lockBuff( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecHostNodePKey* PKey )
	{
		static const std::string S_ProcName( "lockBuff" );
		cfsec::CFSecHostNodeBuff* buff = lockDerived( Authorization, PKey );
		return( dynamic_cast<cfsec::CFSecHostNodeBuff*>( buff ) );
	}

	std::TCFLibOwningVector<cfsec::CFSecHostNodeBuff*> CFSecRamHostNodeTable::readAllBuff( const cfsec::CFSecAuthorization* Authorization )
	{
		static const std::string S_ProcName( "readAllBuff" );
		cfsec::CFSecHostNodeBuff* buff;
		std::TCFLibOwningVector<cfsec::CFSecHostNodeBuff*> filteredList;
		std::TCFLibOwningVector<cfsec::CFSecHostNodeBuff*> buffList = readAllDerived( Authorization );
		std::TCFLibOwningVector<cfsec::CFSecHostNodeBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfsec::CFSecHostNodeBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfsec::CFSecHostNodeBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfsec::CFSecHostNodeBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	std::TCFLibOwningVector<cfsec::CFSecHostNodeBuff*> CFSecRamHostNodeTable::pageAllBuff( const cfsec::CFSecAuthorization* Authorization,
			const int64_t* priorClusterId,
			const int64_t* priorHostNodeId )
	{
		static const std::string S_ProcName( "pageAllBuff" );
		// MSS TODO WORKING
		throw cflib::CFLibNotImplementedYetException( CLASS_NAME, S_ProcName );
	}

	cfsec::CFSecHostNodeBuff* CFSecRamHostNodeTable::readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t HostNodeId )
	{
		static const std::string S_ProcName( "readBuffByIdIdx" );
		cfsec::CFSecHostNodeBuff* buff = readDerivedByIdIdx( Authorization,
			ClusterId,
			HostNodeId );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfsec::CFSecHostNodeBuff::CLASS_CODE ) {
			return( dynamic_cast<cfsec::CFSecHostNodeBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	std::TCFLibOwningVector<cfsec::CFSecHostNodeBuff*> CFSecRamHostNodeTable::readBuffByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId )
	{
		static const std::string S_ProcName( "readBuffByClusterIdx" );
		cfsec::CFSecHostNodeBuff* buff;
		std::TCFLibOwningVector<cfsec::CFSecHostNodeBuff*> filteredList;
		std::TCFLibOwningVector<cfsec::CFSecHostNodeBuff*> buffList = readDerivedByClusterIdx( Authorization,
			ClusterId );
		std::TCFLibOwningVector<cfsec::CFSecHostNodeBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfsec::CFSecHostNodeBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfsec::CFSecHostNodeBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfsec::CFSecHostNodeBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	cfsec::CFSecHostNodeBuff* CFSecRamHostNodeTable::readBuffByUDescrIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const std::string& Description )
	{
		static const std::string S_ProcName( "readBuffByUDescrIdx" );
		cfsec::CFSecHostNodeBuff* buff = readDerivedByUDescrIdx( Authorization,
			ClusterId,
			Description );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfsec::CFSecHostNodeBuff::CLASS_CODE ) {
			return( dynamic_cast<cfsec::CFSecHostNodeBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	cfsec::CFSecHostNodeBuff* CFSecRamHostNodeTable::readBuffByHostNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const std::string& HostName )
	{
		static const std::string S_ProcName( "readBuffByHostNameIdx" );
		cfsec::CFSecHostNodeBuff* buff = readDerivedByHostNameIdx( Authorization,
			ClusterId,
			HostName );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfsec::CFSecHostNodeBuff::CLASS_CODE ) {
			return( dynamic_cast<cfsec::CFSecHostNodeBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	cfsec::CFSecHostNodeBuff* CFSecRamHostNodeTable::readBuffByLookupHostNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId, const std::string& HostName,
		bool forceRead )
	{
		static const std::string S_ProcName( "readBuffByLookupHostNameIdx" );
		cfsec::CFSecHostNodeBuff* buff = readBuffByHostNameIdx( Authorization,
			ClusterId,
			HostName );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfsec::CFSecHostNodeBuff::CLASS_CODE ) {
			return( dynamic_cast<cfsec::CFSecHostNodeBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	cfsec::CFSecHostNodeBuff* CFSecRamHostNodeTable::readDerivedByLookupHostNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId, const std::string& HostName,
		bool forceRead )
	{
		static const std::string S_ProcName( "readDerivedByLookupHostNameIdx" );
		cfsec::CFSecHostNodeBuff* buff = readDerivedByHostNameIdx( Authorization,
			ClusterId,
			HostName );
		if( buff != NULL ) {
			return( dynamic_cast<cfsec::CFSecHostNodeBuff*>( buff->clone() ) );
		}
		else {
			return( NULL );
		}
	}

	std::TCFLibOwningVector<cfsec::CFSecHostNodeBuff*> CFSecRamHostNodeTable::pageBuffByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t* priorClusterId,
			const int64_t* priorHostNodeId )
	{
		static const std::string S_ProcName( "pageBuffByClusterIdx" );
		// MSS TODO WORKING
		throw cflib::CFLibNotImplementedYetException( CLASS_NAME, S_ProcName );
	}

	cfsec::CFSecHostNodeBuff* CFSecRamHostNodeTable::updateHostNode( const cfsec::CFSecAuthorization* Authorization,
		cfsec::CFSecHostNodeBuff* Buff )
	{
		static const std::string S_ProcName( "updateHostNode" );
		cfsec::CFSecHostNodePKey pkey;
		pkey.setRequiredClusterId( Buff->getRequiredClusterId() );
		pkey.setRequiredHostNodeId( Buff->getRequiredHostNodeId() );

		// Search for existing buffer

		auto searchExisting = dictByPKey->find( pkey );
		if( searchExisting == dictByPKey->end() ) {
			delete Buff;
			std::string Msg( "Existing record not found in HostNode for key " + pkey.toString() );
			throw cflib::CFLibStaleCacheDetectedException( CLASS_NAME,
				S_ProcName,
				Msg );
		}

		cfsec::CFSecHostNodeBuff* existing = searchExisting->second;

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
			std::string Msg( "Collision detected for HostNode primary key " );
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
		cfsec::CFSecHostNodeByClusterIdxKey existingKeyClusterIdx;
		existingKeyClusterIdx.setRequiredClusterId( existing->getRequiredClusterId() );
		cfsec::CFSecHostNodeByClusterIdxKey newKeyClusterIdx;
		newKeyClusterIdx.setRequiredClusterId( Buff->getRequiredClusterId() );
		cfsec::CFSecHostNodeByUDescrIdxKey existingKeyUDescrIdx;
		existingKeyUDescrIdx.setRequiredClusterId( existing->getRequiredClusterId() );
		existingKeyUDescrIdx.setRequiredDescription( existing->getRequiredDescription() );
		cfsec::CFSecHostNodeByUDescrIdxKey newKeyUDescrIdx;
		newKeyUDescrIdx.setRequiredClusterId( Buff->getRequiredClusterId() );
		newKeyUDescrIdx.setRequiredDescription( Buff->getRequiredDescription() );
		cfsec::CFSecHostNodeByHostNameIdxKey existingKeyHostNameIdx;
		existingKeyHostNameIdx.setRequiredClusterId( existing->getRequiredClusterId() );
		existingKeyHostNameIdx.setRequiredHostName( existing->getRequiredHostName() );
		cfsec::CFSecHostNodeByHostNameIdxKey newKeyHostNameIdx;
		newKeyHostNameIdx.setRequiredClusterId( Buff->getRequiredClusterId() );
		newKeyHostNameIdx.setRequiredHostName( Buff->getRequiredHostName() );
		// Check unique indexes

		if( existingKeyUDescrIdx != newKeyUDescrIdx ) {
			auto searchDictByUDescrIdx = dictByUDescrIdx->find( newKeyUDescrIdx );
			if( searchDictByUDescrIdx != dictByUDescrIdx->end() ) {
				std::string Msg( "Duplicate key detected for index HostNodeUDescrIdx " + newKeyUDescrIdx.toString() );
				delete Buff;
				throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
					S_ProcName,
					Msg );
			}
		}

		if( existingKeyHostNameIdx != newKeyHostNameIdx ) {
			auto searchDictByHostNameIdx = dictByHostNameIdx->find( newKeyHostNameIdx );
			if( searchDictByHostNameIdx != dictByHostNameIdx->end() ) {
				std::string Msg( "Duplicate key detected for index HostNodeUHostNameIdx " + newKeyHostNameIdx.toString() );
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
					std::string Msg( "Could not resolve Container relationship HostNodeCluster to table Cluster" );
					throw cflib::CFLibUnresolvedRelationException( CLASS_NAME,
						S_ProcName,
						Msg );
				}
				delete chk;
				chk = NULL;
			}
		}

		// Update is valid
		std::map<cfsec::CFSecHostNodePKey, cfsec::CFSecHostNodeBuff*>* subdict;
		auto removalDictByPKey = dictByPKey->find( pkey );
		if( removalDictByPKey != dictByPKey->end() ) {
			dictByPKey->erase( removalDictByPKey );
		}
		// Copy edited buffer to existing persistent buffer

		if( Buff->getClassCode() != cfsec::CFSecHostNodeBuff::CLASS_CODE ) {
			const static std::string S_IsNotA( " is not a cfsec::CFSecHostNodeBuff" );
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

		dictByPKey->insert( std::map<cfsec::CFSecHostNodePKey, cfsec::CFSecHostNodeBuff*>::value_type( pkey, existing ) );

		std::map<cfsec::CFSecHostNodePKey,
			 cfsec::CFSecHostNodeBuff*>* subdictClusterIdx;
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
			subdictClusterIdx = new std::map<cfsec::CFSecHostNodePKey, cfsec::CFSecHostNodeBuff*>();
			dictByClusterIdx->insert( std::map<cfsec::CFSecHostNodeByClusterIdxKey,
				std::map<cfsec::CFSecHostNodePKey,
					cfsec::CFSecHostNodeBuff*>*>::value_type( newKeyClusterIdx, subdictClusterIdx ) );
		}
		subdictClusterIdx->insert( std::map<cfsec::CFSecHostNodePKey, cfsec::CFSecHostNodeBuff*>::value_type( pkey, existing ) );

		auto removalDictByUDescrIdx = dictByUDescrIdx->find( existingKeyUDescrIdx );
		if( removalDictByUDescrIdx != dictByUDescrIdx->end() ) {
			dictByUDescrIdx->erase( removalDictByUDescrIdx );
		}
		dictByUDescrIdx->insert( std::map<cfsec::CFSecHostNodeByUDescrIdxKey, cfsec::CFSecHostNodeBuff*>::value_type( newKeyUDescrIdx, existing ) );

		auto removalDictByHostNameIdx = dictByHostNameIdx->find( existingKeyHostNameIdx );
		if( removalDictByHostNameIdx != dictByHostNameIdx->end() ) {
			dictByHostNameIdx->erase( removalDictByHostNameIdx );
		}
		dictByHostNameIdx->insert( std::map<cfsec::CFSecHostNodeByHostNameIdxKey, cfsec::CFSecHostNodeBuff*>::value_type( newKeyHostNameIdx, existing ) );


		// The top level code has to clean up the memory buffer that was passed in, and return a clone
		// of the copy that existing buffer that is attached to the RAM storage.  All other cases
		// return the existing buffer.

		cfsec::CFSecHostNodeBuff* buff;
		if( existing->getClassCode() == cfsec::CFSecHostNodeBuff::CLASS_CODE ) {
			delete Buff;
			Buff = NULL;
			buff = dynamic_cast<cfsec::CFSecHostNodeBuff*>( existing->clone() );
		}
		else {
			buff = existing;
		}
		return( buff );
	}

	void CFSecRamHostNodeTable::deleteHostNode( const cfsec::CFSecAuthorization* Authorization,
		cfsec::CFSecHostNodeBuff* Buff )
	{
		static const std::string S_ProcName( "deleteHostNode" );
		static const std::string S_Prev( "prev" );
		classcode_t classCode;
		cfsec::CFSecHostNodePKey pkey;
		pkey.setRequiredClusterId( Buff->getRequiredClusterId() );
		pkey.setRequiredHostNodeId( Buff->getRequiredHostNodeId() );
		auto searchExisting = dictByPKey->find( pkey );
		if( searchExisting == dictByPKey->end() ) {
			return;
		}
		cfsec::CFSecHostNodeBuff* existing = searchExisting->second;
		schema->getTableService()->deleteServiceByHostIdx( Authorization,
			existing->getRequiredClusterId(),
			existing->getRequiredHostNodeId() );
		cfsec::CFSecHostNodeByClusterIdxKey keyClusterIdx;
		keyClusterIdx.setRequiredClusterId( existing->getRequiredClusterId() );
		cfsec::CFSecHostNodeByUDescrIdxKey keyUDescrIdx;
		keyUDescrIdx.setRequiredClusterId( existing->getRequiredClusterId() );
		keyUDescrIdx.setRequiredDescription( existing->getRequiredDescription() );
		cfsec::CFSecHostNodeByHostNameIdxKey keyHostNameIdx;
		keyHostNameIdx.setRequiredClusterId( existing->getRequiredClusterId() );
		keyHostNameIdx.setRequiredHostName( existing->getRequiredHostName() );
		// Validate reverse foreign keys

		// Delete is valid
		std::map<cfsec::CFSecHostNodePKey, cfsec::CFSecHostNodeBuff*>* subdict;

		auto searchDictByPKey = dictByPKey->find( pkey );
		if( searchDictByPKey != dictByPKey->end() ) {
			dictByPKey->erase( searchDictByPKey );
		}

		auto searchDictByClusterIdx = dictByClusterIdx->find( keyClusterIdx );
		if( searchDictByClusterIdx != dictByClusterIdx->end() ) {
			std::map<cfsec::CFSecHostNodePKey,
				 cfsec::CFSecHostNodeBuff*>* subdictClusterIdx = searchDictByClusterIdx->second;
			auto searchSubDict = subdictClusterIdx->find( pkey );
			if( searchSubDict != subdictClusterIdx->end() ) {
				subdictClusterIdx->erase( searchSubDict );
			}
			subdictClusterIdx = NULL;
		}

		auto searchDictByUDescrIdx = dictByUDescrIdx->find( keyUDescrIdx );
		if( searchDictByUDescrIdx != dictByUDescrIdx->end() ) {
			dictByUDescrIdx->erase( searchDictByUDescrIdx );
		}

		auto searchDictByHostNameIdx = dictByHostNameIdx->find( keyHostNameIdx );
		if( searchDictByHostNameIdx != dictByHostNameIdx->end() ) {
			dictByHostNameIdx->erase( searchDictByHostNameIdx );
		}

		if( existing != NULL ) {
			delete existing;
			existing = NULL;
		}
	}

	void CFSecRamHostNodeTable::deleteHostNodeByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const int64_t argHostNodeId )
	{
		cfsec::CFSecHostNodePKey key;
		key.setRequiredClusterId( argClusterId );
		key.setRequiredHostNodeId( argHostNodeId );
		deleteHostNodeByIdIdx( Authorization, &key );
	}

	void CFSecRamHostNodeTable::deleteHostNodeByIdIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecHostNodePKey* argKey )
	{
		bool anyNotNull = false;
		anyNotNull = true;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		cfsec::CFSecHostNodeBuff* cur = NULL;
		cfsec::CFSecHostNodeBuff* rereadCur = NULL;
		std::TCFLibOwningVector<cfsec::CFSecHostNodeBuff*> matchSet;
		std::map<cfsec::CFSecHostNodePKey,
			cfsec::CFSecHostNodeBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecHostNodePKey,
			cfsec::CFSecHostNodeBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecHostNodeBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecHostNodeBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecHostNodeBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecHostNodeBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableHostNode()->readDerivedByIdIdx( Authorization,
				cur->getRequiredClusterId(),
				cur->getRequiredHostNodeId() );
			rereadCur = cur;
			deleteHostNode( Authorization, cur );
			if( rereadCur != NULL ) {
				delete rereadCur;
				rereadCur = NULL;
			}
		}
	}

	void CFSecRamHostNodeTable::deleteHostNodeByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId )
	{
		cfsec::CFSecHostNodeByClusterIdxKey key;
		key.setRequiredClusterId( argClusterId );
		deleteHostNodeByClusterIdx( Authorization, &key );
	}

	void CFSecRamHostNodeTable::deleteHostNodeByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecHostNodeByClusterIdxKey* argKey )
	{
		cfsec::CFSecHostNodeBuff* cur = NULL;
		cfsec::CFSecHostNodeBuff* rereadCur = NULL;
		bool anyNotNull = false;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfsec::CFSecHostNodeBuff*> matchSet;
		std::map<cfsec::CFSecHostNodePKey,
			cfsec::CFSecHostNodeBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecHostNodePKey,
			cfsec::CFSecHostNodeBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecHostNodeBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecHostNodeBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecHostNodeBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecHostNodeBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableHostNode()->readDerivedByIdIdx( Authorization,
				cur->getRequiredClusterId(),
				cur->getRequiredHostNodeId() );
			rereadCur = cur;
			deleteHostNode( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFSecRamHostNodeTable::deleteHostNodeByUDescrIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const std::string& argDescription )
	{
		cfsec::CFSecHostNodeByUDescrIdxKey key;
		key.setRequiredClusterId( argClusterId );
		key.setRequiredDescription( argDescription );
		deleteHostNodeByUDescrIdx( Authorization, &key );
	}

	void CFSecRamHostNodeTable::deleteHostNodeByUDescrIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecHostNodeByUDescrIdxKey* argKey )
	{
		cfsec::CFSecHostNodeBuff* cur = NULL;
		cfsec::CFSecHostNodeBuff* rereadCur = NULL;
		bool anyNotNull = false;
		anyNotNull = true;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfsec::CFSecHostNodeBuff*> matchSet;
		std::map<cfsec::CFSecHostNodePKey,
			cfsec::CFSecHostNodeBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecHostNodePKey,
			cfsec::CFSecHostNodeBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecHostNodeBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecHostNodeBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecHostNodeBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecHostNodeBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableHostNode()->readDerivedByIdIdx( Authorization,
				cur->getRequiredClusterId(),
				cur->getRequiredHostNodeId() );
			rereadCur = cur;
			deleteHostNode( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFSecRamHostNodeTable::deleteHostNodeByHostNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const std::string& argHostName )
	{
		cfsec::CFSecHostNodeByHostNameIdxKey key;
		key.setRequiredClusterId( argClusterId );
		key.setRequiredHostName( argHostName );
		deleteHostNodeByHostNameIdx( Authorization, &key );
	}

	void CFSecRamHostNodeTable::deleteHostNodeByHostNameIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecHostNodeByHostNameIdxKey* argKey )
	{
		cfsec::CFSecHostNodeBuff* cur = NULL;
		cfsec::CFSecHostNodeBuff* rereadCur = NULL;
		bool anyNotNull = false;
		anyNotNull = true;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfsec::CFSecHostNodeBuff*> matchSet;
		std::map<cfsec::CFSecHostNodePKey,
			cfsec::CFSecHostNodeBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecHostNodePKey,
			cfsec::CFSecHostNodeBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecHostNodeBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecHostNodeBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecHostNodeBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecHostNodeBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableHostNode()->readDerivedByIdIdx( Authorization,
				cur->getRequiredClusterId(),
				cur->getRequiredHostNodeId() );
			rereadCur = cur;
			deleteHostNode( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFSecRamHostNodeTable::releasePreparedStatements() {
	}

}
