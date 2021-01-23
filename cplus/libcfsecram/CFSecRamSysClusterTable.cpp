
// Description: C++18 Implementation for an in-memory RAM DbIO for SysCluster.

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

	const std::string CFSecRamSysClusterTable::CLASS_NAME( "CFSecRamSysClusterTable" );

	CFSecRamSysClusterTable::CFSecRamSysClusterTable( ICFSecSchema* argSchema )
	: cfsec::ICFSecSysClusterTable()
	{
		schema = argSchema;
		dictByPKey = new std::map<cfsec::CFSecSysClusterPKey, cfsec::CFSecSysClusterBuff*>();
		dictByClusterIdx = new std::map<cfsec::CFSecSysClusterByClusterIdxKey,
			std::map<cfsec::CFSecSysClusterPKey,
				cfsec::CFSecSysClusterBuff*>*>();
	}

	CFSecRamSysClusterTable::~CFSecRamSysClusterTable() {
		if( dictByClusterIdx != NULL ) {
			for( auto iterDict = dictByClusterIdx->begin(); iterDict != dictByClusterIdx->end(); iterDict ++ ) {
				delete iterDict->second;
				iterDict->second = NULL;
			}
			delete dictByClusterIdx;
			dictByClusterIdx = NULL;
		}
		if( dictByPKey != NULL ) {
			cfsec::CFSecSysClusterBuff* elt;
			std::map<cfsec::CFSecSysClusterPKey,
				cfsec::CFSecSysClusterBuff*>::iterator end = dictByPKey->end();
			for( std::map<cfsec::CFSecSysClusterPKey,
					cfsec::CFSecSysClusterBuff*>::iterator cur = dictByPKey->begin();
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

	cfsec::CFSecSysClusterBuff* CFSecRamSysClusterTable::createSysCluster( const cfsec::CFSecAuthorization* Authorization,
		cfsec::CFSecSysClusterBuff* Buff )
	{
		static const std::string S_ProcName( "createSysCluster" );
		cfsec::CFSecSysClusterPKey pkey;
		pkey.setRequiredSingletonId( Buff->getRequiredSingletonId() );
		Buff->setRequiredSingletonId( pkey.getRequiredSingletonId() );
		cfsec::CFSecSysClusterByClusterIdxKey keyClusterIdx;
		keyClusterIdx.setRequiredClusterId( Buff->getRequiredClusterId() );
		// Validate unique indexes
		auto searchDictByPKey = dictByPKey->find( pkey );
		if( searchDictByPKey != dictByPKey->end() ) {
			delete Buff;
			std::string Msg( "Duplicate primary key detected " + pkey.toString() );
			throw cflib::CFLibPrimaryKeyNotNewException( CLASS_NAME, S_ProcName, Msg );
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
					std::string Msg( "Could not resolve Container relationship SysClusterCluster to table Cluster" );
					throw cflib::CFLibUnresolvedRelationException( CLASS_NAME,
						S_ProcName,
						Msg );
				}
				delete chk;
				chk = NULL;
			}
		}

		// Proceed with adding the new record
		cfsec::CFSecSysClusterBuff* buff = Buff;
		buff->setRequiredRevision( 1 );
		dictByPKey->insert( std::map<cfsec::CFSecSysClusterPKey, cfsec::CFSecSysClusterBuff*>::value_type( pkey, buff ) );

		std::map<cfsec::CFSecSysClusterPKey, cfsec::CFSecSysClusterBuff*>* subdictClusterIdx;
		auto searchDictByClusterIdx = dictByClusterIdx->find( keyClusterIdx );
		if( searchDictByClusterIdx != dictByClusterIdx->end() ) {
			subdictClusterIdx = searchDictByClusterIdx->second;
		}
		else {
			subdictClusterIdx = new std::map<cfsec::CFSecSysClusterPKey, cfsec::CFSecSysClusterBuff*>();
			dictByClusterIdx->insert( std::map<cfsec::CFSecSysClusterByClusterIdxKey,
				std::map<cfsec::CFSecSysClusterPKey,
					cfsec::CFSecSysClusterBuff*>*>::value_type( keyClusterIdx, subdictClusterIdx ) );
		}
		subdictClusterIdx->insert( std::map<cfsec::CFSecSysClusterPKey, cfsec::CFSecSysClusterBuff*>::value_type( pkey, buff ) );

		// The top level code has to clone the final buffer. The one passed in is now part of the persistent storage.
		if( buff->getClassCode() == cfsec::CFSecSysClusterBuff::CLASS_CODE ) {
			buff = dynamic_cast<cfsec::CFSecSysClusterBuff*>( buff->clone() );
		}
		return( buff );
	}

	cfsec::CFSecSysClusterBuff* CFSecRamSysClusterTable::readDerived( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSysClusterPKey* PKey )
	{
		static const std::string S_ProcName( "readDerived" );
		cfsec::CFSecSysClusterBuff* buff;
		auto searchDictByPKey = dictByPKey->find( *PKey );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfsec::CFSecSysClusterBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecSysClusterBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfsec::CFSecSysClusterBuff* CFSecRamSysClusterTable::lockDerived( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSysClusterPKey* PKey )
	{
		static const std::string S_ProcName( "lockDerived" );
		cfsec::CFSecSysClusterBuff* buff;
		auto searchDictByPKey = dictByPKey->find( *PKey );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfsec::CFSecSysClusterBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecSysClusterBuff*>( buff->clone() );
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

	std::TCFLibOwningVector<cfsec::CFSecSysClusterBuff*> CFSecRamSysClusterTable::readAllDerived( const cfsec::CFSecAuthorization* Authorization ) {
		static const std::string S_ProcName( "readAllDerived" );
		std::TCFLibOwningVector<cfsec::CFSecSysClusterBuff*> retVec;
		std::map<cfsec::CFSecSysClusterPKey,
			cfsec::CFSecSysClusterBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecSysClusterPKey,
			cfsec::CFSecSysClusterBuff*>::iterator end = dictByPKey->end();
		cfsec::CFSecSysClusterBuff* clone;
		while( iter != end ) {
			clone = dynamic_cast<cfsec::CFSecSysClusterBuff*>( iter->second->clone() );
			retVec.push_back( clone );
			iter ++;
		}
		return( retVec );
	}

	std::TCFLibOwningVector<cfsec::CFSecSysClusterBuff*> CFSecRamSysClusterTable::readDerivedByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId )
	{
		static const std::string S_ProcName( "readDerivedByClusterIdx" );
		cfsec::CFSecSysClusterByClusterIdxKey key;
		key.setRequiredClusterId( ClusterId );
		std::TCFLibOwningVector<cfsec::CFSecSysClusterBuff*> recVec;
		cfsec::CFSecSysClusterBuff* clone;
		auto searchDictByClusterIdx = dictByClusterIdx->find( key );
		if( searchDictByClusterIdx != dictByClusterIdx->end() ) {
			std::map<cfsec::CFSecSysClusterPKey,
				 cfsec::CFSecSysClusterBuff*>* subdictClusterIdx = searchDictByClusterIdx->second;
			std::map<cfsec::CFSecSysClusterPKey,
				cfsec::CFSecSysClusterBuff*>::iterator iter = subdictClusterIdx->begin();
			std::map<cfsec::CFSecSysClusterPKey,
				cfsec::CFSecSysClusterBuff*>::iterator end = subdictClusterIdx->end();
			while( iter != end ) {
				clone = dynamic_cast<cfsec::CFSecSysClusterBuff*>( iter->second->clone() );
				recVec.push_back( clone );
				iter ++;
			}
		}
		return( recVec );
	}

	cfsec::CFSecSysClusterBuff* CFSecRamSysClusterTable::readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int32_t SingletonId )
	{
		static const std::string S_ProcName( "readDerivedByIdIdx" );
		cfsec::CFSecSysClusterPKey key;
		key.setRequiredSingletonId( SingletonId );
		cfsec::CFSecSysClusterBuff* buff;
		auto searchDictByPKey = dictByPKey->find( key );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfsec::CFSecSysClusterBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecSysClusterBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfsec::CFSecSysClusterBuff* CFSecRamSysClusterTable::readBuff( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSysClusterPKey* PKey )
	{
		static const std::string S_ProcName( "readBuff" );
		cfsec::CFSecSysClusterBuff* buff = readDerived( Authorization, PKey );
		if( buff != NULL ) {
			if( buff->getClassCode() != cfsec::CFSecSysClusterBuff::CLASS_CODE ) {
				delete buff;
				buff = NULL;
			}
		}
		return( dynamic_cast<cfsec::CFSecSysClusterBuff*>( buff ) );
	}

	cfsec::CFSecSysClusterBuff* CFSecRamSysClusterTable::lockBuff( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSysClusterPKey* PKey )
	{
		static const std::string S_ProcName( "lockBuff" );
		cfsec::CFSecSysClusterBuff* buff = lockDerived( Authorization, PKey );
		return( dynamic_cast<cfsec::CFSecSysClusterBuff*>( buff ) );
	}

	std::TCFLibOwningVector<cfsec::CFSecSysClusterBuff*> CFSecRamSysClusterTable::readAllBuff( const cfsec::CFSecAuthorization* Authorization )
	{
		static const std::string S_ProcName( "readAllBuff" );
		cfsec::CFSecSysClusterBuff* buff;
		std::TCFLibOwningVector<cfsec::CFSecSysClusterBuff*> filteredList;
		std::TCFLibOwningVector<cfsec::CFSecSysClusterBuff*> buffList = readAllDerived( Authorization );
		std::TCFLibOwningVector<cfsec::CFSecSysClusterBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfsec::CFSecSysClusterBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfsec::CFSecSysClusterBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfsec::CFSecSysClusterBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	cfsec::CFSecSysClusterBuff* CFSecRamSysClusterTable::readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int32_t SingletonId )
	{
		static const std::string S_ProcName( "readBuffByIdIdx" );
		cfsec::CFSecSysClusterBuff* buff = readDerivedByIdIdx( Authorization,
			SingletonId );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfsec::CFSecSysClusterBuff::CLASS_CODE ) {
			return( dynamic_cast<cfsec::CFSecSysClusterBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	std::TCFLibOwningVector<cfsec::CFSecSysClusterBuff*> CFSecRamSysClusterTable::readBuffByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId )
	{
		static const std::string S_ProcName( "readBuffByClusterIdx" );
		cfsec::CFSecSysClusterBuff* buff;
		std::TCFLibOwningVector<cfsec::CFSecSysClusterBuff*> filteredList;
		std::TCFLibOwningVector<cfsec::CFSecSysClusterBuff*> buffList = readDerivedByClusterIdx( Authorization,
			ClusterId );
		std::TCFLibOwningVector<cfsec::CFSecSysClusterBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfsec::CFSecSysClusterBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfsec::CFSecSysClusterBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfsec::CFSecSysClusterBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	cfsec::CFSecSysClusterBuff* CFSecRamSysClusterTable::updateSysCluster( const cfsec::CFSecAuthorization* Authorization,
		cfsec::CFSecSysClusterBuff* Buff )
	{
		static const std::string S_ProcName( "updateSysCluster" );
		cfsec::CFSecSysClusterPKey pkey;
		pkey.setRequiredSingletonId( Buff->getRequiredSingletonId() );

		// Search for existing buffer

		auto searchExisting = dictByPKey->find( pkey );
		if( searchExisting == dictByPKey->end() ) {
			delete Buff;
			std::string Msg( "Existing record not found in SysCluster for key " + pkey.toString() );
			throw cflib::CFLibStaleCacheDetectedException( CLASS_NAME,
				S_ProcName,
				Msg );
		}

		cfsec::CFSecSysClusterBuff* existing = searchExisting->second;

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
			std::string Msg( "Collision detected for SysCluster primary key " );
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
		cfsec::CFSecSysClusterByClusterIdxKey existingKeyClusterIdx;
		existingKeyClusterIdx.setRequiredClusterId( existing->getRequiredClusterId() );
		cfsec::CFSecSysClusterByClusterIdxKey newKeyClusterIdx;
		newKeyClusterIdx.setRequiredClusterId( Buff->getRequiredClusterId() );
		// Check unique indexes

		// Validate foreign keys

		{
			bool allNull = true;

			if( allNull ) {
				cfsec::CFSecClusterBuff* chk = dynamic_cast<cfsec::CFSecClusterBuff*>( schema->getTableCluster()->readDerivedByIdIdx( Authorization,
						Buff->getRequiredClusterId() ) );
				if( chk == NULL ) {
					delete Buff;
					std::string Msg( "Could not resolve Container relationship SysClusterCluster to table Cluster" );
					throw cflib::CFLibUnresolvedRelationException( CLASS_NAME,
						S_ProcName,
						Msg );
				}
				delete chk;
				chk = NULL;
			}
		}

		// Update is valid
		std::map<cfsec::CFSecSysClusterPKey, cfsec::CFSecSysClusterBuff*>* subdict;
		auto removalDictByPKey = dictByPKey->find( pkey );
		if( removalDictByPKey != dictByPKey->end() ) {
			dictByPKey->erase( removalDictByPKey );
		}
		// Copy edited buffer to existing persistent buffer

		if( Buff->getClassCode() != cfsec::CFSecSysClusterBuff::CLASS_CODE ) {
			const static std::string S_IsNotA( " is not a cfsec::CFSecSysClusterBuff" );
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

		dictByPKey->insert( std::map<cfsec::CFSecSysClusterPKey, cfsec::CFSecSysClusterBuff*>::value_type( pkey, existing ) );

		std::map<cfsec::CFSecSysClusterPKey,
			 cfsec::CFSecSysClusterBuff*>* subdictClusterIdx;
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
			subdictClusterIdx = new std::map<cfsec::CFSecSysClusterPKey, cfsec::CFSecSysClusterBuff*>();
			dictByClusterIdx->insert( std::map<cfsec::CFSecSysClusterByClusterIdxKey,
				std::map<cfsec::CFSecSysClusterPKey,
					cfsec::CFSecSysClusterBuff*>*>::value_type( newKeyClusterIdx, subdictClusterIdx ) );
		}
		subdictClusterIdx->insert( std::map<cfsec::CFSecSysClusterPKey, cfsec::CFSecSysClusterBuff*>::value_type( pkey, existing ) );


		// The top level code has to clean up the memory buffer that was passed in, and return a clone
		// of the copy that existing buffer that is attached to the RAM storage.  All other cases
		// return the existing buffer.

		cfsec::CFSecSysClusterBuff* buff;
		if( existing->getClassCode() == cfsec::CFSecSysClusterBuff::CLASS_CODE ) {
			delete Buff;
			Buff = NULL;
			buff = dynamic_cast<cfsec::CFSecSysClusterBuff*>( existing->clone() );
		}
		else {
			buff = existing;
		}
		return( buff );
	}

	void CFSecRamSysClusterTable::deleteSysCluster( const cfsec::CFSecAuthorization* Authorization,
		cfsec::CFSecSysClusterBuff* Buff )
	{
		static const std::string S_ProcName( "deleteSysCluster" );
		static const std::string S_Prev( "prev" );
		classcode_t classCode;
		cfsec::CFSecSysClusterPKey pkey;
		pkey.setRequiredSingletonId( Buff->getRequiredSingletonId() );
		auto searchExisting = dictByPKey->find( pkey );
		if( searchExisting == dictByPKey->end() ) {
			return;
		}
		cfsec::CFSecSysClusterBuff* existing = searchExisting->second;
		cfsec::CFSecSysClusterByClusterIdxKey keyClusterIdx;
		keyClusterIdx.setRequiredClusterId( existing->getRequiredClusterId() );
		// Validate reverse foreign keys

		// Delete is valid
		std::map<cfsec::CFSecSysClusterPKey, cfsec::CFSecSysClusterBuff*>* subdict;

		auto searchDictByPKey = dictByPKey->find( pkey );
		if( searchDictByPKey != dictByPKey->end() ) {
			dictByPKey->erase( searchDictByPKey );
		}

		auto searchDictByClusterIdx = dictByClusterIdx->find( keyClusterIdx );
		if( searchDictByClusterIdx != dictByClusterIdx->end() ) {
			std::map<cfsec::CFSecSysClusterPKey,
				 cfsec::CFSecSysClusterBuff*>* subdictClusterIdx = searchDictByClusterIdx->second;
			auto searchSubDict = subdictClusterIdx->find( pkey );
			if( searchSubDict != subdictClusterIdx->end() ) {
				subdictClusterIdx->erase( searchSubDict );
			}
			subdictClusterIdx = NULL;
		}

		if( existing != NULL ) {
			delete existing;
			existing = NULL;
		}
	}

	void CFSecRamSysClusterTable::deleteSysClusterByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int32_t argSingletonId )
	{
		cfsec::CFSecSysClusterPKey key;
		key.setRequiredSingletonId( argSingletonId );
		deleteSysClusterByIdIdx( Authorization, &key );
	}

	void CFSecRamSysClusterTable::deleteSysClusterByIdIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSysClusterPKey* argKey )
	{
		bool anyNotNull = false;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		cfsec::CFSecSysClusterBuff* cur = NULL;
		cfsec::CFSecSysClusterBuff* rereadCur = NULL;
		std::TCFLibOwningVector<cfsec::CFSecSysClusterBuff*> matchSet;
		std::map<cfsec::CFSecSysClusterPKey,
			cfsec::CFSecSysClusterBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecSysClusterPKey,
			cfsec::CFSecSysClusterBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecSysClusterBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecSysClusterBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecSysClusterBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecSysClusterBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableSysCluster()->readDerivedByIdIdx( Authorization,
				cur->getRequiredSingletonId() );
			rereadCur = cur;
			deleteSysCluster( Authorization, cur );
			if( rereadCur != NULL ) {
				delete rereadCur;
				rereadCur = NULL;
			}
		}
	}

	void CFSecRamSysClusterTable::deleteSysClusterByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId )
	{
		cfsec::CFSecSysClusterByClusterIdxKey key;
		key.setRequiredClusterId( argClusterId );
		deleteSysClusterByClusterIdx( Authorization, &key );
	}

	void CFSecRamSysClusterTable::deleteSysClusterByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSysClusterByClusterIdxKey* argKey )
	{
		cfsec::CFSecSysClusterBuff* cur = NULL;
		cfsec::CFSecSysClusterBuff* rereadCur = NULL;
		bool anyNotNull = false;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfsec::CFSecSysClusterBuff*> matchSet;
		std::map<cfsec::CFSecSysClusterPKey,
			cfsec::CFSecSysClusterBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecSysClusterPKey,
			cfsec::CFSecSysClusterBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecSysClusterBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecSysClusterBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecSysClusterBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecSysClusterBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableSysCluster()->readDerivedByIdIdx( Authorization,
				cur->getRequiredSingletonId() );
			rereadCur = cur;
			deleteSysCluster( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFSecRamSysClusterTable::releasePreparedStatements() {
	}

}
