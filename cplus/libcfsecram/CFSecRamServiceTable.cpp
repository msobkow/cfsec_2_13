
// Description: C++18 Implementation for an in-memory RAM DbIO for Service.

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

	const std::string CFSecRamServiceTable::CLASS_NAME( "CFSecRamServiceTable" );

	CFSecRamServiceTable::CFSecRamServiceTable( ICFSecSchema* argSchema )
	: cfsec::ICFSecServiceTable()
	{
		schema = argSchema;
		dictByPKey = new std::map<cfsec::CFSecServicePKey, cfsec::CFSecServiceBuff*>();
		dictByClusterIdx = new std::map<cfsec::CFSecServiceByClusterIdxKey,
			std::map<cfsec::CFSecServicePKey,
				cfsec::CFSecServiceBuff*>*>();
		dictByHostIdx = new std::map<cfsec::CFSecServiceByHostIdxKey,
			std::map<cfsec::CFSecServicePKey,
				cfsec::CFSecServiceBuff*>*>();
		dictByTypeIdx = new std::map<cfsec::CFSecServiceByTypeIdxKey,
			std::map<cfsec::CFSecServicePKey,
				cfsec::CFSecServiceBuff*>*>();
		dictByUTypeIdx = new std::map<cfsec::CFSecServiceByUTypeIdxKey, cfsec::CFSecServiceBuff*>();
		dictByUHostPortIdx = new std::map<cfsec::CFSecServiceByUHostPortIdxKey, cfsec::CFSecServiceBuff*>();
	}

	CFSecRamServiceTable::~CFSecRamServiceTable() {
		if( dictByClusterIdx != NULL ) {
			for( auto iterDict = dictByClusterIdx->begin(); iterDict != dictByClusterIdx->end(); iterDict ++ ) {
				delete iterDict->second;
				iterDict->second = NULL;
			}
			delete dictByClusterIdx;
			dictByClusterIdx = NULL;
		}
		if( dictByHostIdx != NULL ) {
			for( auto iterDict = dictByHostIdx->begin(); iterDict != dictByHostIdx->end(); iterDict ++ ) {
				delete iterDict->second;
				iterDict->second = NULL;
			}
			delete dictByHostIdx;
			dictByHostIdx = NULL;
		}
		if( dictByTypeIdx != NULL ) {
			for( auto iterDict = dictByTypeIdx->begin(); iterDict != dictByTypeIdx->end(); iterDict ++ ) {
				delete iterDict->second;
				iterDict->second = NULL;
			}
			delete dictByTypeIdx;
			dictByTypeIdx = NULL;
		}
		if( dictByUTypeIdx != NULL ) {
			delete dictByUTypeIdx;
			dictByUTypeIdx = NULL;
		}
		if( dictByUHostPortIdx != NULL ) {
			delete dictByUHostPortIdx;
			dictByUHostPortIdx = NULL;
		}
		if( dictByPKey != NULL ) {
			cfsec::CFSecServiceBuff* elt;
			std::map<cfsec::CFSecServicePKey,
				cfsec::CFSecServiceBuff*>::iterator end = dictByPKey->end();
			for( std::map<cfsec::CFSecServicePKey,
					cfsec::CFSecServiceBuff*>::iterator cur = dictByPKey->begin();
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

	cfsec::CFSecServiceBuff* CFSecRamServiceTable::createService( const cfsec::CFSecAuthorization* Authorization,
		cfsec::CFSecServiceBuff* Buff )
	{
		static const std::string S_ProcName( "createService" );
		cfsec::CFSecServicePKey pkey;
		pkey.setRequiredClusterId( Buff->getRequiredClusterId() );
		pkey.setRequiredServiceId( dynamic_cast<CFSecRamClusterTable*>( schema->getTableCluster() )->nextServiceIdGen( Authorization,
			Buff->getRequiredClusterId() ) );
		Buff->setRequiredClusterId( pkey.getRequiredClusterId() );
		Buff->setRequiredServiceId( pkey.getRequiredServiceId() );
		cfsec::CFSecServiceByClusterIdxKey keyClusterIdx;
		keyClusterIdx.setRequiredClusterId( Buff->getRequiredClusterId() );
		cfsec::CFSecServiceByHostIdxKey keyHostIdx;
		keyHostIdx.setRequiredClusterId( Buff->getRequiredClusterId() );
		keyHostIdx.setRequiredHostNodeId( Buff->getRequiredHostNodeId() );
		cfsec::CFSecServiceByTypeIdxKey keyTypeIdx;
		keyTypeIdx.setRequiredServiceTypeId( Buff->getRequiredServiceTypeId() );
		cfsec::CFSecServiceByUTypeIdxKey keyUTypeIdx;
		keyUTypeIdx.setRequiredClusterId( Buff->getRequiredClusterId() );
		keyUTypeIdx.setRequiredHostNodeId( Buff->getRequiredHostNodeId() );
		keyUTypeIdx.setRequiredServiceTypeId( Buff->getRequiredServiceTypeId() );
		cfsec::CFSecServiceByUHostPortIdxKey keyUHostPortIdx;
		keyUHostPortIdx.setRequiredClusterId( Buff->getRequiredClusterId() );
		keyUHostPortIdx.setRequiredHostNodeId( Buff->getRequiredHostNodeId() );
		keyUHostPortIdx.setRequiredHostPort( Buff->getRequiredHostPort() );
		// Validate unique indexes
		auto searchDictByPKey = dictByPKey->find( pkey );
		if( searchDictByPKey != dictByPKey->end() ) {
			delete Buff;
			std::string Msg( "Duplicate primary key detected " + pkey.toString() );
			throw cflib::CFLibPrimaryKeyNotNewException( CLASS_NAME, S_ProcName, Msg );
		}

		auto searchDictByUTypeIdx = dictByUTypeIdx->find( keyUTypeIdx );
		if( searchDictByUTypeIdx != dictByUTypeIdx->end() ) {
			std::string Msg( "Duplicate key detected for index ServiceUTypeIdx " + keyUTypeIdx.toString() );
			delete Buff;
			throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
				S_ProcName,
				Msg );
		}

		auto searchDictByUHostPortIdx = dictByUHostPortIdx->find( keyUHostPortIdx );
		if( searchDictByUHostPortIdx != dictByUHostPortIdx->end() ) {
			std::string Msg( "Duplicate key detected for index ServiceUHostPort " + keyUHostPortIdx.toString() );
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
					std::string Msg( "Could not resolve Owner relationship ServiceCluster to table Cluster" );
					throw cflib::CFLibUnresolvedRelationException( CLASS_NAME,
						S_ProcName,
						Msg );
				}
				delete chk;
				chk = NULL;
			}
		}

		// Proceed with adding the new record
		cfsec::CFSecServiceBuff* buff = Buff;
		buff->setRequiredRevision( 1 );
		dictByPKey->insert( std::map<cfsec::CFSecServicePKey, cfsec::CFSecServiceBuff*>::value_type( pkey, buff ) );

		std::map<cfsec::CFSecServicePKey, cfsec::CFSecServiceBuff*>* subdictClusterIdx;
		auto searchDictByClusterIdx = dictByClusterIdx->find( keyClusterIdx );
		if( searchDictByClusterIdx != dictByClusterIdx->end() ) {
			subdictClusterIdx = searchDictByClusterIdx->second;
		}
		else {
			subdictClusterIdx = new std::map<cfsec::CFSecServicePKey, cfsec::CFSecServiceBuff*>();
			dictByClusterIdx->insert( std::map<cfsec::CFSecServiceByClusterIdxKey,
				std::map<cfsec::CFSecServicePKey,
					cfsec::CFSecServiceBuff*>*>::value_type( keyClusterIdx, subdictClusterIdx ) );
		}
		subdictClusterIdx->insert( std::map<cfsec::CFSecServicePKey, cfsec::CFSecServiceBuff*>::value_type( pkey, buff ) );

		std::map<cfsec::CFSecServicePKey, cfsec::CFSecServiceBuff*>* subdictHostIdx;
		auto searchDictByHostIdx = dictByHostIdx->find( keyHostIdx );
		if( searchDictByHostIdx != dictByHostIdx->end() ) {
			subdictHostIdx = searchDictByHostIdx->second;
		}
		else {
			subdictHostIdx = new std::map<cfsec::CFSecServicePKey, cfsec::CFSecServiceBuff*>();
			dictByHostIdx->insert( std::map<cfsec::CFSecServiceByHostIdxKey,
				std::map<cfsec::CFSecServicePKey,
					cfsec::CFSecServiceBuff*>*>::value_type( keyHostIdx, subdictHostIdx ) );
		}
		subdictHostIdx->insert( std::map<cfsec::CFSecServicePKey, cfsec::CFSecServiceBuff*>::value_type( pkey, buff ) );

		std::map<cfsec::CFSecServicePKey, cfsec::CFSecServiceBuff*>* subdictTypeIdx;
		auto searchDictByTypeIdx = dictByTypeIdx->find( keyTypeIdx );
		if( searchDictByTypeIdx != dictByTypeIdx->end() ) {
			subdictTypeIdx = searchDictByTypeIdx->second;
		}
		else {
			subdictTypeIdx = new std::map<cfsec::CFSecServicePKey, cfsec::CFSecServiceBuff*>();
			dictByTypeIdx->insert( std::map<cfsec::CFSecServiceByTypeIdxKey,
				std::map<cfsec::CFSecServicePKey,
					cfsec::CFSecServiceBuff*>*>::value_type( keyTypeIdx, subdictTypeIdx ) );
		}
		subdictTypeIdx->insert( std::map<cfsec::CFSecServicePKey, cfsec::CFSecServiceBuff*>::value_type( pkey, buff ) );

		dictByUTypeIdx->insert( std::map<cfsec::CFSecServiceByUTypeIdxKey, cfsec::CFSecServiceBuff*>::value_type( keyUTypeIdx, buff ) );

		dictByUHostPortIdx->insert( std::map<cfsec::CFSecServiceByUHostPortIdxKey, cfsec::CFSecServiceBuff*>::value_type( keyUHostPortIdx, buff ) );

		// The top level code has to clone the final buffer. The one passed in is now part of the persistent storage.
		if( buff->getClassCode() == cfsec::CFSecServiceBuff::CLASS_CODE ) {
			buff = dynamic_cast<cfsec::CFSecServiceBuff*>( buff->clone() );
		}
		return( buff );
	}

	cfsec::CFSecServiceBuff* CFSecRamServiceTable::readDerived( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecServicePKey* PKey )
	{
		static const std::string S_ProcName( "readDerived" );
		cfsec::CFSecServiceBuff* buff;
		auto searchDictByPKey = dictByPKey->find( *PKey );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfsec::CFSecServiceBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecServiceBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfsec::CFSecServiceBuff* CFSecRamServiceTable::lockDerived( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecServicePKey* PKey )
	{
		static const std::string S_ProcName( "lockDerived" );
		cfsec::CFSecServiceBuff* buff;
		auto searchDictByPKey = dictByPKey->find( *PKey );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfsec::CFSecServiceBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecServiceBuff*>( buff->clone() );
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

	std::TCFLibOwningVector<cfsec::CFSecServiceBuff*> CFSecRamServiceTable::readAllDerived( const cfsec::CFSecAuthorization* Authorization ) {
		static const std::string S_ProcName( "readAllDerived" );
		std::TCFLibOwningVector<cfsec::CFSecServiceBuff*> retVec;
		std::map<cfsec::CFSecServicePKey,
			cfsec::CFSecServiceBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecServicePKey,
			cfsec::CFSecServiceBuff*>::iterator end = dictByPKey->end();
		cfsec::CFSecServiceBuff* clone;
		while( iter != end ) {
			clone = dynamic_cast<cfsec::CFSecServiceBuff*>( iter->second->clone() );
			retVec.push_back( clone );
			iter ++;
		}
		return( retVec );
	}

	std::TCFLibOwningVector<cfsec::CFSecServiceBuff*> CFSecRamServiceTable::readDerivedByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId )
	{
		static const std::string S_ProcName( "readDerivedByClusterIdx" );
		cfsec::CFSecServiceByClusterIdxKey key;
		key.setRequiredClusterId( ClusterId );
		std::TCFLibOwningVector<cfsec::CFSecServiceBuff*> recVec;
		cfsec::CFSecServiceBuff* clone;
		auto searchDictByClusterIdx = dictByClusterIdx->find( key );
		if( searchDictByClusterIdx != dictByClusterIdx->end() ) {
			std::map<cfsec::CFSecServicePKey,
				 cfsec::CFSecServiceBuff*>* subdictClusterIdx = searchDictByClusterIdx->second;
			std::map<cfsec::CFSecServicePKey,
				cfsec::CFSecServiceBuff*>::iterator iter = subdictClusterIdx->begin();
			std::map<cfsec::CFSecServicePKey,
				cfsec::CFSecServiceBuff*>::iterator end = subdictClusterIdx->end();
			while( iter != end ) {
				clone = dynamic_cast<cfsec::CFSecServiceBuff*>( iter->second->clone() );
				recVec.push_back( clone );
				iter ++;
			}
		}
		return( recVec );
	}

	std::TCFLibOwningVector<cfsec::CFSecServiceBuff*> CFSecRamServiceTable::readDerivedByHostIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t HostNodeId )
	{
		static const std::string S_ProcName( "readDerivedByHostIdx" );
		cfsec::CFSecServiceByHostIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredHostNodeId( HostNodeId );
		std::TCFLibOwningVector<cfsec::CFSecServiceBuff*> recVec;
		cfsec::CFSecServiceBuff* clone;
		auto searchDictByHostIdx = dictByHostIdx->find( key );
		if( searchDictByHostIdx != dictByHostIdx->end() ) {
			std::map<cfsec::CFSecServicePKey,
				 cfsec::CFSecServiceBuff*>* subdictHostIdx = searchDictByHostIdx->second;
			std::map<cfsec::CFSecServicePKey,
				cfsec::CFSecServiceBuff*>::iterator iter = subdictHostIdx->begin();
			std::map<cfsec::CFSecServicePKey,
				cfsec::CFSecServiceBuff*>::iterator end = subdictHostIdx->end();
			while( iter != end ) {
				clone = dynamic_cast<cfsec::CFSecServiceBuff*>( iter->second->clone() );
				recVec.push_back( clone );
				iter ++;
			}
		}
		return( recVec );
	}

	std::TCFLibOwningVector<cfsec::CFSecServiceBuff*> CFSecRamServiceTable::readDerivedByTypeIdx( const cfsec::CFSecAuthorization* Authorization,
			const int32_t ServiceTypeId )
	{
		static const std::string S_ProcName( "readDerivedByTypeIdx" );
		cfsec::CFSecServiceByTypeIdxKey key;
		key.setRequiredServiceTypeId( ServiceTypeId );
		std::TCFLibOwningVector<cfsec::CFSecServiceBuff*> recVec;
		cfsec::CFSecServiceBuff* clone;
		auto searchDictByTypeIdx = dictByTypeIdx->find( key );
		if( searchDictByTypeIdx != dictByTypeIdx->end() ) {
			std::map<cfsec::CFSecServicePKey,
				 cfsec::CFSecServiceBuff*>* subdictTypeIdx = searchDictByTypeIdx->second;
			std::map<cfsec::CFSecServicePKey,
				cfsec::CFSecServiceBuff*>::iterator iter = subdictTypeIdx->begin();
			std::map<cfsec::CFSecServicePKey,
				cfsec::CFSecServiceBuff*>::iterator end = subdictTypeIdx->end();
			while( iter != end ) {
				clone = dynamic_cast<cfsec::CFSecServiceBuff*>( iter->second->clone() );
				recVec.push_back( clone );
				iter ++;
			}
		}
		return( recVec );
	}

	cfsec::CFSecServiceBuff* CFSecRamServiceTable::readDerivedByUTypeIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t HostNodeId,
			const int32_t ServiceTypeId )
	{
		static const std::string S_ProcName( "readDerivedByUTypeIdx" );
		cfsec::CFSecServiceByUTypeIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredHostNodeId( HostNodeId );
		key.setRequiredServiceTypeId( ServiceTypeId );
		cfsec::CFSecServiceBuff* buff;
		auto searchDictByUTypeIdx = dictByUTypeIdx->find( key );
		if( searchDictByUTypeIdx != dictByUTypeIdx->end() ) {
			buff = dynamic_cast<cfsec::CFSecServiceBuff*>( searchDictByUTypeIdx->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecServiceBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfsec::CFSecServiceBuff* CFSecRamServiceTable::readDerivedByUHostPortIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t HostNodeId,
			const int16_t HostPort )
	{
		static const std::string S_ProcName( "readDerivedByUHostPortIdx" );
		cfsec::CFSecServiceByUHostPortIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredHostNodeId( HostNodeId );
		key.setRequiredHostPort( HostPort );
		cfsec::CFSecServiceBuff* buff;
		auto searchDictByUHostPortIdx = dictByUHostPortIdx->find( key );
		if( searchDictByUHostPortIdx != dictByUHostPortIdx->end() ) {
			buff = dynamic_cast<cfsec::CFSecServiceBuff*>( searchDictByUHostPortIdx->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecServiceBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfsec::CFSecServiceBuff* CFSecRamServiceTable::readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t ServiceId )
	{
		static const std::string S_ProcName( "readDerivedByIdIdx" );
		cfsec::CFSecServicePKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredServiceId( ServiceId );
		cfsec::CFSecServiceBuff* buff;
		auto searchDictByPKey = dictByPKey->find( key );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfsec::CFSecServiceBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecServiceBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfsec::CFSecServiceBuff* CFSecRamServiceTable::readBuff( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecServicePKey* PKey )
	{
		static const std::string S_ProcName( "readBuff" );
		cfsec::CFSecServiceBuff* buff = readDerived( Authorization, PKey );
		if( buff != NULL ) {
			if( buff->getClassCode() != cfsec::CFSecServiceBuff::CLASS_CODE ) {
				delete buff;
				buff = NULL;
			}
		}
		return( dynamic_cast<cfsec::CFSecServiceBuff*>( buff ) );
	}

	cfsec::CFSecServiceBuff* CFSecRamServiceTable::lockBuff( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecServicePKey* PKey )
	{
		static const std::string S_ProcName( "lockBuff" );
		cfsec::CFSecServiceBuff* buff = lockDerived( Authorization, PKey );
		return( dynamic_cast<cfsec::CFSecServiceBuff*>( buff ) );
	}

	std::TCFLibOwningVector<cfsec::CFSecServiceBuff*> CFSecRamServiceTable::readAllBuff( const cfsec::CFSecAuthorization* Authorization )
	{
		static const std::string S_ProcName( "readAllBuff" );
		cfsec::CFSecServiceBuff* buff;
		std::TCFLibOwningVector<cfsec::CFSecServiceBuff*> filteredList;
		std::TCFLibOwningVector<cfsec::CFSecServiceBuff*> buffList = readAllDerived( Authorization );
		std::TCFLibOwningVector<cfsec::CFSecServiceBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfsec::CFSecServiceBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfsec::CFSecServiceBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfsec::CFSecServiceBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	std::TCFLibOwningVector<cfsec::CFSecServiceBuff*> CFSecRamServiceTable::pageAllBuff( const cfsec::CFSecAuthorization* Authorization,
			const int64_t* priorClusterId,
			const int64_t* priorServiceId )
	{
		static const std::string S_ProcName( "pageAllBuff" );
		// MSS TODO WORKING
		throw cflib::CFLibNotImplementedYetException( CLASS_NAME, S_ProcName );
	}

	cfsec::CFSecServiceBuff* CFSecRamServiceTable::readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t ServiceId )
	{
		static const std::string S_ProcName( "readBuffByIdIdx" );
		cfsec::CFSecServiceBuff* buff = readDerivedByIdIdx( Authorization,
			ClusterId,
			ServiceId );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfsec::CFSecServiceBuff::CLASS_CODE ) {
			return( dynamic_cast<cfsec::CFSecServiceBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	std::TCFLibOwningVector<cfsec::CFSecServiceBuff*> CFSecRamServiceTable::readBuffByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId )
	{
		static const std::string S_ProcName( "readBuffByClusterIdx" );
		cfsec::CFSecServiceBuff* buff;
		std::TCFLibOwningVector<cfsec::CFSecServiceBuff*> filteredList;
		std::TCFLibOwningVector<cfsec::CFSecServiceBuff*> buffList = readDerivedByClusterIdx( Authorization,
			ClusterId );
		std::TCFLibOwningVector<cfsec::CFSecServiceBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfsec::CFSecServiceBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfsec::CFSecServiceBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfsec::CFSecServiceBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	std::TCFLibOwningVector<cfsec::CFSecServiceBuff*> CFSecRamServiceTable::readBuffByHostIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t HostNodeId )
	{
		static const std::string S_ProcName( "readBuffByHostIdx" );
		cfsec::CFSecServiceBuff* buff;
		std::TCFLibOwningVector<cfsec::CFSecServiceBuff*> filteredList;
		std::TCFLibOwningVector<cfsec::CFSecServiceBuff*> buffList = readDerivedByHostIdx( Authorization,
			ClusterId,
			HostNodeId );
		std::TCFLibOwningVector<cfsec::CFSecServiceBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfsec::CFSecServiceBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfsec::CFSecServiceBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfsec::CFSecServiceBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	std::TCFLibOwningVector<cfsec::CFSecServiceBuff*> CFSecRamServiceTable::readBuffByTypeIdx( const cfsec::CFSecAuthorization* Authorization,
			const int32_t ServiceTypeId )
	{
		static const std::string S_ProcName( "readBuffByTypeIdx" );
		cfsec::CFSecServiceBuff* buff;
		std::TCFLibOwningVector<cfsec::CFSecServiceBuff*> filteredList;
		std::TCFLibOwningVector<cfsec::CFSecServiceBuff*> buffList = readDerivedByTypeIdx( Authorization,
			ServiceTypeId );
		std::TCFLibOwningVector<cfsec::CFSecServiceBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfsec::CFSecServiceBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfsec::CFSecServiceBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfsec::CFSecServiceBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	cfsec::CFSecServiceBuff* CFSecRamServiceTable::readBuffByUTypeIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t HostNodeId,
			const int32_t ServiceTypeId )
	{
		static const std::string S_ProcName( "readBuffByUTypeIdx" );
		cfsec::CFSecServiceBuff* buff = readDerivedByUTypeIdx( Authorization,
			ClusterId,
			HostNodeId,
			ServiceTypeId );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfsec::CFSecServiceBuff::CLASS_CODE ) {
			return( dynamic_cast<cfsec::CFSecServiceBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	cfsec::CFSecServiceBuff* CFSecRamServiceTable::readBuffByUHostPortIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t HostNodeId,
			const int16_t HostPort )
	{
		static const std::string S_ProcName( "readBuffByUHostPortIdx" );
		cfsec::CFSecServiceBuff* buff = readDerivedByUHostPortIdx( Authorization,
			ClusterId,
			HostNodeId,
			HostPort );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfsec::CFSecServiceBuff::CLASS_CODE ) {
			return( dynamic_cast<cfsec::CFSecServiceBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	std::TCFLibOwningVector<cfsec::CFSecServiceBuff*> CFSecRamServiceTable::pageBuffByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t* priorClusterId,
			const int64_t* priorServiceId )
	{
		static const std::string S_ProcName( "pageBuffByClusterIdx" );
		// MSS TODO WORKING
		throw cflib::CFLibNotImplementedYetException( CLASS_NAME, S_ProcName );
	}

	std::TCFLibOwningVector<cfsec::CFSecServiceBuff*> CFSecRamServiceTable::pageBuffByHostIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t HostNodeId,
			const int64_t* priorClusterId,
			const int64_t* priorServiceId )
	{
		static const std::string S_ProcName( "pageBuffByHostIdx" );
		// MSS TODO WORKING
		throw cflib::CFLibNotImplementedYetException( CLASS_NAME, S_ProcName );
	}

	std::TCFLibOwningVector<cfsec::CFSecServiceBuff*> CFSecRamServiceTable::pageBuffByTypeIdx( const cfsec::CFSecAuthorization* Authorization,
			const int32_t ServiceTypeId,
			const int64_t* priorClusterId,
			const int64_t* priorServiceId )
	{
		static const std::string S_ProcName( "pageBuffByTypeIdx" );
		// MSS TODO WORKING
		throw cflib::CFLibNotImplementedYetException( CLASS_NAME, S_ProcName );
	}

	cfsec::CFSecServiceBuff* CFSecRamServiceTable::updateService( const cfsec::CFSecAuthorization* Authorization,
		cfsec::CFSecServiceBuff* Buff )
	{
		static const std::string S_ProcName( "updateService" );
		cfsec::CFSecServicePKey pkey;
		pkey.setRequiredClusterId( Buff->getRequiredClusterId() );
		pkey.setRequiredServiceId( Buff->getRequiredServiceId() );

		// Search for existing buffer

		auto searchExisting = dictByPKey->find( pkey );
		if( searchExisting == dictByPKey->end() ) {
			delete Buff;
			std::string Msg( "Existing record not found in Service for key " + pkey.toString() );
			throw cflib::CFLibStaleCacheDetectedException( CLASS_NAME,
				S_ProcName,
				Msg );
		}

		cfsec::CFSecServiceBuff* existing = searchExisting->second;

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
			std::string Msg( "Collision detected for Service primary key " );
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
		cfsec::CFSecServiceByClusterIdxKey existingKeyClusterIdx;
		existingKeyClusterIdx.setRequiredClusterId( existing->getRequiredClusterId() );
		cfsec::CFSecServiceByClusterIdxKey newKeyClusterIdx;
		newKeyClusterIdx.setRequiredClusterId( Buff->getRequiredClusterId() );
		cfsec::CFSecServiceByHostIdxKey existingKeyHostIdx;
		existingKeyHostIdx.setRequiredClusterId( existing->getRequiredClusterId() );
		existingKeyHostIdx.setRequiredHostNodeId( existing->getRequiredHostNodeId() );
		cfsec::CFSecServiceByHostIdxKey newKeyHostIdx;
		newKeyHostIdx.setRequiredClusterId( Buff->getRequiredClusterId() );
		newKeyHostIdx.setRequiredHostNodeId( Buff->getRequiredHostNodeId() );
		cfsec::CFSecServiceByTypeIdxKey existingKeyTypeIdx;
		existingKeyTypeIdx.setRequiredServiceTypeId( existing->getRequiredServiceTypeId() );
		cfsec::CFSecServiceByTypeIdxKey newKeyTypeIdx;
		newKeyTypeIdx.setRequiredServiceTypeId( Buff->getRequiredServiceTypeId() );
		cfsec::CFSecServiceByUTypeIdxKey existingKeyUTypeIdx;
		existingKeyUTypeIdx.setRequiredClusterId( existing->getRequiredClusterId() );
		existingKeyUTypeIdx.setRequiredHostNodeId( existing->getRequiredHostNodeId() );
		existingKeyUTypeIdx.setRequiredServiceTypeId( existing->getRequiredServiceTypeId() );
		cfsec::CFSecServiceByUTypeIdxKey newKeyUTypeIdx;
		newKeyUTypeIdx.setRequiredClusterId( Buff->getRequiredClusterId() );
		newKeyUTypeIdx.setRequiredHostNodeId( Buff->getRequiredHostNodeId() );
		newKeyUTypeIdx.setRequiredServiceTypeId( Buff->getRequiredServiceTypeId() );
		cfsec::CFSecServiceByUHostPortIdxKey existingKeyUHostPortIdx;
		existingKeyUHostPortIdx.setRequiredClusterId( existing->getRequiredClusterId() );
		existingKeyUHostPortIdx.setRequiredHostNodeId( existing->getRequiredHostNodeId() );
		existingKeyUHostPortIdx.setRequiredHostPort( existing->getRequiredHostPort() );
		cfsec::CFSecServiceByUHostPortIdxKey newKeyUHostPortIdx;
		newKeyUHostPortIdx.setRequiredClusterId( Buff->getRequiredClusterId() );
		newKeyUHostPortIdx.setRequiredHostNodeId( Buff->getRequiredHostNodeId() );
		newKeyUHostPortIdx.setRequiredHostPort( Buff->getRequiredHostPort() );
		// Check unique indexes

		if( existingKeyUTypeIdx != newKeyUTypeIdx ) {
			auto searchDictByUTypeIdx = dictByUTypeIdx->find( newKeyUTypeIdx );
			if( searchDictByUTypeIdx != dictByUTypeIdx->end() ) {
				std::string Msg( "Duplicate key detected for index ServiceUTypeIdx " + newKeyUTypeIdx.toString() );
				delete Buff;
				throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
					S_ProcName,
					Msg );
			}
		}

		if( existingKeyUHostPortIdx != newKeyUHostPortIdx ) {
			auto searchDictByUHostPortIdx = dictByUHostPortIdx->find( newKeyUHostPortIdx );
			if( searchDictByUHostPortIdx != dictByUHostPortIdx->end() ) {
				std::string Msg( "Duplicate key detected for index ServiceUHostPort " + newKeyUHostPortIdx.toString() );
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
					std::string Msg( "Could not resolve Owner relationship ServiceCluster to table Cluster" );
					throw cflib::CFLibUnresolvedRelationException( CLASS_NAME,
						S_ProcName,
						Msg );
				}
				delete chk;
				chk = NULL;
			}
		}

		// Update is valid
		std::map<cfsec::CFSecServicePKey, cfsec::CFSecServiceBuff*>* subdict;
		auto removalDictByPKey = dictByPKey->find( pkey );
		if( removalDictByPKey != dictByPKey->end() ) {
			dictByPKey->erase( removalDictByPKey );
		}
		// Copy edited buffer to existing persistent buffer

		if( Buff->getClassCode() != cfsec::CFSecServiceBuff::CLASS_CODE ) {
			const static std::string S_IsNotA( " is not a cfsec::CFSecServiceBuff" );
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

		dictByPKey->insert( std::map<cfsec::CFSecServicePKey, cfsec::CFSecServiceBuff*>::value_type( pkey, existing ) );

		std::map<cfsec::CFSecServicePKey,
			 cfsec::CFSecServiceBuff*>* subdictClusterIdx;
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
			subdictClusterIdx = new std::map<cfsec::CFSecServicePKey, cfsec::CFSecServiceBuff*>();
			dictByClusterIdx->insert( std::map<cfsec::CFSecServiceByClusterIdxKey,
				std::map<cfsec::CFSecServicePKey,
					cfsec::CFSecServiceBuff*>*>::value_type( newKeyClusterIdx, subdictClusterIdx ) );
		}
		subdictClusterIdx->insert( std::map<cfsec::CFSecServicePKey, cfsec::CFSecServiceBuff*>::value_type( pkey, existing ) );

		std::map<cfsec::CFSecServicePKey,
			 cfsec::CFSecServiceBuff*>* subdictHostIdx;
		auto searchDictByHostIdx = dictByHostIdx->find( existingKeyHostIdx );
		if( searchDictByHostIdx != dictByHostIdx->end() ) {
			subdictHostIdx = searchDictByHostIdx->second;
			auto searchSubDict = subdictHostIdx->find( pkey );
			if( searchSubDict != subdictHostIdx->end() ) {
				subdictHostIdx->erase( searchSubDict );
			}
			if( subdictHostIdx->size() <= 0 ) {
				delete subdictHostIdx;
				dictByHostIdx->erase( searchDictByHostIdx );
			}
			subdictHostIdx = NULL;
		}
		auto searchNewKeyDictByHostIdx = dictByHostIdx->find( newKeyHostIdx );
		if( searchNewKeyDictByHostIdx != dictByHostIdx->end() ) {
			subdictHostIdx = searchNewKeyDictByHostIdx->second;
		}
		else {
			subdictHostIdx = new std::map<cfsec::CFSecServicePKey, cfsec::CFSecServiceBuff*>();
			dictByHostIdx->insert( std::map<cfsec::CFSecServiceByHostIdxKey,
				std::map<cfsec::CFSecServicePKey,
					cfsec::CFSecServiceBuff*>*>::value_type( newKeyHostIdx, subdictHostIdx ) );
		}
		subdictHostIdx->insert( std::map<cfsec::CFSecServicePKey, cfsec::CFSecServiceBuff*>::value_type( pkey, existing ) );

		std::map<cfsec::CFSecServicePKey,
			 cfsec::CFSecServiceBuff*>* subdictTypeIdx;
		auto searchDictByTypeIdx = dictByTypeIdx->find( existingKeyTypeIdx );
		if( searchDictByTypeIdx != dictByTypeIdx->end() ) {
			subdictTypeIdx = searchDictByTypeIdx->second;
			auto searchSubDict = subdictTypeIdx->find( pkey );
			if( searchSubDict != subdictTypeIdx->end() ) {
				subdictTypeIdx->erase( searchSubDict );
			}
			if( subdictTypeIdx->size() <= 0 ) {
				delete subdictTypeIdx;
				dictByTypeIdx->erase( searchDictByTypeIdx );
			}
			subdictTypeIdx = NULL;
		}
		auto searchNewKeyDictByTypeIdx = dictByTypeIdx->find( newKeyTypeIdx );
		if( searchNewKeyDictByTypeIdx != dictByTypeIdx->end() ) {
			subdictTypeIdx = searchNewKeyDictByTypeIdx->second;
		}
		else {
			subdictTypeIdx = new std::map<cfsec::CFSecServicePKey, cfsec::CFSecServiceBuff*>();
			dictByTypeIdx->insert( std::map<cfsec::CFSecServiceByTypeIdxKey,
				std::map<cfsec::CFSecServicePKey,
					cfsec::CFSecServiceBuff*>*>::value_type( newKeyTypeIdx, subdictTypeIdx ) );
		}
		subdictTypeIdx->insert( std::map<cfsec::CFSecServicePKey, cfsec::CFSecServiceBuff*>::value_type( pkey, existing ) );

		auto removalDictByUTypeIdx = dictByUTypeIdx->find( existingKeyUTypeIdx );
		if( removalDictByUTypeIdx != dictByUTypeIdx->end() ) {
			dictByUTypeIdx->erase( removalDictByUTypeIdx );
		}
		dictByUTypeIdx->insert( std::map<cfsec::CFSecServiceByUTypeIdxKey, cfsec::CFSecServiceBuff*>::value_type( newKeyUTypeIdx, existing ) );

		auto removalDictByUHostPortIdx = dictByUHostPortIdx->find( existingKeyUHostPortIdx );
		if( removalDictByUHostPortIdx != dictByUHostPortIdx->end() ) {
			dictByUHostPortIdx->erase( removalDictByUHostPortIdx );
		}
		dictByUHostPortIdx->insert( std::map<cfsec::CFSecServiceByUHostPortIdxKey, cfsec::CFSecServiceBuff*>::value_type( newKeyUHostPortIdx, existing ) );


		// The top level code has to clean up the memory buffer that was passed in, and return a clone
		// of the copy that existing buffer that is attached to the RAM storage.  All other cases
		// return the existing buffer.

		cfsec::CFSecServiceBuff* buff;
		if( existing->getClassCode() == cfsec::CFSecServiceBuff::CLASS_CODE ) {
			delete Buff;
			Buff = NULL;
			buff = dynamic_cast<cfsec::CFSecServiceBuff*>( existing->clone() );
		}
		else {
			buff = existing;
		}
		return( buff );
	}

	void CFSecRamServiceTable::deleteService( const cfsec::CFSecAuthorization* Authorization,
		cfsec::CFSecServiceBuff* Buff )
	{
		static const std::string S_ProcName( "deleteService" );
		static const std::string S_Prev( "prev" );
		classcode_t classCode;
		cfsec::CFSecServicePKey pkey;
		pkey.setRequiredClusterId( Buff->getRequiredClusterId() );
		pkey.setRequiredServiceId( Buff->getRequiredServiceId() );
		auto searchExisting = dictByPKey->find( pkey );
		if( searchExisting == dictByPKey->end() ) {
			return;
		}
		cfsec::CFSecServiceBuff* existing = searchExisting->second;
		cfsec::CFSecServiceByClusterIdxKey keyClusterIdx;
		keyClusterIdx.setRequiredClusterId( existing->getRequiredClusterId() );
		cfsec::CFSecServiceByHostIdxKey keyHostIdx;
		keyHostIdx.setRequiredClusterId( existing->getRequiredClusterId() );
		keyHostIdx.setRequiredHostNodeId( existing->getRequiredHostNodeId() );
		cfsec::CFSecServiceByTypeIdxKey keyTypeIdx;
		keyTypeIdx.setRequiredServiceTypeId( existing->getRequiredServiceTypeId() );
		cfsec::CFSecServiceByUTypeIdxKey keyUTypeIdx;
		keyUTypeIdx.setRequiredClusterId( existing->getRequiredClusterId() );
		keyUTypeIdx.setRequiredHostNodeId( existing->getRequiredHostNodeId() );
		keyUTypeIdx.setRequiredServiceTypeId( existing->getRequiredServiceTypeId() );
		cfsec::CFSecServiceByUHostPortIdxKey keyUHostPortIdx;
		keyUHostPortIdx.setRequiredClusterId( existing->getRequiredClusterId() );
		keyUHostPortIdx.setRequiredHostNodeId( existing->getRequiredHostNodeId() );
		keyUHostPortIdx.setRequiredHostPort( existing->getRequiredHostPort() );
		// Validate reverse foreign keys

		// Delete is valid
		std::map<cfsec::CFSecServicePKey, cfsec::CFSecServiceBuff*>* subdict;

		auto searchDictByPKey = dictByPKey->find( pkey );
		if( searchDictByPKey != dictByPKey->end() ) {
			dictByPKey->erase( searchDictByPKey );
		}

		auto searchDictByClusterIdx = dictByClusterIdx->find( keyClusterIdx );
		if( searchDictByClusterIdx != dictByClusterIdx->end() ) {
			std::map<cfsec::CFSecServicePKey,
				 cfsec::CFSecServiceBuff*>* subdictClusterIdx = searchDictByClusterIdx->second;
			auto searchSubDict = subdictClusterIdx->find( pkey );
			if( searchSubDict != subdictClusterIdx->end() ) {
				subdictClusterIdx->erase( searchSubDict );
			}
			subdictClusterIdx = NULL;
		}

		auto searchDictByHostIdx = dictByHostIdx->find( keyHostIdx );
		if( searchDictByHostIdx != dictByHostIdx->end() ) {
			std::map<cfsec::CFSecServicePKey,
				 cfsec::CFSecServiceBuff*>* subdictHostIdx = searchDictByHostIdx->second;
			auto searchSubDict = subdictHostIdx->find( pkey );
			if( searchSubDict != subdictHostIdx->end() ) {
				subdictHostIdx->erase( searchSubDict );
			}
			subdictHostIdx = NULL;
		}

		auto searchDictByTypeIdx = dictByTypeIdx->find( keyTypeIdx );
		if( searchDictByTypeIdx != dictByTypeIdx->end() ) {
			std::map<cfsec::CFSecServicePKey,
				 cfsec::CFSecServiceBuff*>* subdictTypeIdx = searchDictByTypeIdx->second;
			auto searchSubDict = subdictTypeIdx->find( pkey );
			if( searchSubDict != subdictTypeIdx->end() ) {
				subdictTypeIdx->erase( searchSubDict );
			}
			subdictTypeIdx = NULL;
		}

		auto searchDictByUTypeIdx = dictByUTypeIdx->find( keyUTypeIdx );
		if( searchDictByUTypeIdx != dictByUTypeIdx->end() ) {
			dictByUTypeIdx->erase( searchDictByUTypeIdx );
		}

		auto searchDictByUHostPortIdx = dictByUHostPortIdx->find( keyUHostPortIdx );
		if( searchDictByUHostPortIdx != dictByUHostPortIdx->end() ) {
			dictByUHostPortIdx->erase( searchDictByUHostPortIdx );
		}

		if( existing != NULL ) {
			delete existing;
			existing = NULL;
		}
	}

	void CFSecRamServiceTable::deleteServiceByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const int64_t argServiceId )
	{
		cfsec::CFSecServicePKey key;
		key.setRequiredClusterId( argClusterId );
		key.setRequiredServiceId( argServiceId );
		deleteServiceByIdIdx( Authorization, &key );
	}

	void CFSecRamServiceTable::deleteServiceByIdIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecServicePKey* argKey )
	{
		bool anyNotNull = false;
		anyNotNull = true;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		cfsec::CFSecServiceBuff* cur = NULL;
		cfsec::CFSecServiceBuff* rereadCur = NULL;
		std::TCFLibOwningVector<cfsec::CFSecServiceBuff*> matchSet;
		std::map<cfsec::CFSecServicePKey,
			cfsec::CFSecServiceBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecServicePKey,
			cfsec::CFSecServiceBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecServiceBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecServiceBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecServiceBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecServiceBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableService()->readDerivedByIdIdx( Authorization,
				cur->getRequiredClusterId(),
				cur->getRequiredServiceId() );
			rereadCur = cur;
			deleteService( Authorization, cur );
			if( rereadCur != NULL ) {
				delete rereadCur;
				rereadCur = NULL;
			}
		}
	}

	void CFSecRamServiceTable::deleteServiceByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId )
	{
		cfsec::CFSecServiceByClusterIdxKey key;
		key.setRequiredClusterId( argClusterId );
		deleteServiceByClusterIdx( Authorization, &key );
	}

	void CFSecRamServiceTable::deleteServiceByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecServiceByClusterIdxKey* argKey )
	{
		cfsec::CFSecServiceBuff* cur = NULL;
		cfsec::CFSecServiceBuff* rereadCur = NULL;
		bool anyNotNull = false;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfsec::CFSecServiceBuff*> matchSet;
		std::map<cfsec::CFSecServicePKey,
			cfsec::CFSecServiceBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecServicePKey,
			cfsec::CFSecServiceBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecServiceBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecServiceBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecServiceBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecServiceBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableService()->readDerivedByIdIdx( Authorization,
				cur->getRequiredClusterId(),
				cur->getRequiredServiceId() );
			rereadCur = cur;
			deleteService( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFSecRamServiceTable::deleteServiceByHostIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const int64_t argHostNodeId )
	{
		cfsec::CFSecServiceByHostIdxKey key;
		key.setRequiredClusterId( argClusterId );
		key.setRequiredHostNodeId( argHostNodeId );
		deleteServiceByHostIdx( Authorization, &key );
	}

	void CFSecRamServiceTable::deleteServiceByHostIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecServiceByHostIdxKey* argKey )
	{
		cfsec::CFSecServiceBuff* cur = NULL;
		cfsec::CFSecServiceBuff* rereadCur = NULL;
		bool anyNotNull = false;
		anyNotNull = true;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfsec::CFSecServiceBuff*> matchSet;
		std::map<cfsec::CFSecServicePKey,
			cfsec::CFSecServiceBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecServicePKey,
			cfsec::CFSecServiceBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecServiceBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecServiceBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecServiceBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecServiceBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableService()->readDerivedByIdIdx( Authorization,
				cur->getRequiredClusterId(),
				cur->getRequiredServiceId() );
			rereadCur = cur;
			deleteService( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFSecRamServiceTable::deleteServiceByTypeIdx( const cfsec::CFSecAuthorization* Authorization,
			const int32_t argServiceTypeId )
	{
		cfsec::CFSecServiceByTypeIdxKey key;
		key.setRequiredServiceTypeId( argServiceTypeId );
		deleteServiceByTypeIdx( Authorization, &key );
	}

	void CFSecRamServiceTable::deleteServiceByTypeIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecServiceByTypeIdxKey* argKey )
	{
		cfsec::CFSecServiceBuff* cur = NULL;
		cfsec::CFSecServiceBuff* rereadCur = NULL;
		bool anyNotNull = false;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfsec::CFSecServiceBuff*> matchSet;
		std::map<cfsec::CFSecServicePKey,
			cfsec::CFSecServiceBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecServicePKey,
			cfsec::CFSecServiceBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecServiceBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecServiceBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecServiceBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecServiceBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableService()->readDerivedByIdIdx( Authorization,
				cur->getRequiredClusterId(),
				cur->getRequiredServiceId() );
			rereadCur = cur;
			deleteService( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFSecRamServiceTable::deleteServiceByUTypeIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const int64_t argHostNodeId,
			const int32_t argServiceTypeId )
	{
		cfsec::CFSecServiceByUTypeIdxKey key;
		key.setRequiredClusterId( argClusterId );
		key.setRequiredHostNodeId( argHostNodeId );
		key.setRequiredServiceTypeId( argServiceTypeId );
		deleteServiceByUTypeIdx( Authorization, &key );
	}

	void CFSecRamServiceTable::deleteServiceByUTypeIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecServiceByUTypeIdxKey* argKey )
	{
		cfsec::CFSecServiceBuff* cur = NULL;
		cfsec::CFSecServiceBuff* rereadCur = NULL;
		bool anyNotNull = false;
		anyNotNull = true;
		anyNotNull = true;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfsec::CFSecServiceBuff*> matchSet;
		std::map<cfsec::CFSecServicePKey,
			cfsec::CFSecServiceBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecServicePKey,
			cfsec::CFSecServiceBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecServiceBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecServiceBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecServiceBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecServiceBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableService()->readDerivedByIdIdx( Authorization,
				cur->getRequiredClusterId(),
				cur->getRequiredServiceId() );
			rereadCur = cur;
			deleteService( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFSecRamServiceTable::deleteServiceByUHostPortIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const int64_t argHostNodeId,
			const int16_t argHostPort )
	{
		cfsec::CFSecServiceByUHostPortIdxKey key;
		key.setRequiredClusterId( argClusterId );
		key.setRequiredHostNodeId( argHostNodeId );
		key.setRequiredHostPort( argHostPort );
		deleteServiceByUHostPortIdx( Authorization, &key );
	}

	void CFSecRamServiceTable::deleteServiceByUHostPortIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecServiceByUHostPortIdxKey* argKey )
	{
		cfsec::CFSecServiceBuff* cur = NULL;
		cfsec::CFSecServiceBuff* rereadCur = NULL;
		bool anyNotNull = false;
		anyNotNull = true;
		anyNotNull = true;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfsec::CFSecServiceBuff*> matchSet;
		std::map<cfsec::CFSecServicePKey,
			cfsec::CFSecServiceBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecServicePKey,
			cfsec::CFSecServiceBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecServiceBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecServiceBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecServiceBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecServiceBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableService()->readDerivedByIdIdx( Authorization,
				cur->getRequiredClusterId(),
				cur->getRequiredServiceId() );
			rereadCur = cur;
			deleteService( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFSecRamServiceTable::releasePreparedStatements() {
	}

}
