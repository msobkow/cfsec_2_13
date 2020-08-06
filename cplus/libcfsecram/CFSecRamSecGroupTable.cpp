
// Description: C++18 Implementation for an in-memory RAM DbIO for SecGroup.

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

	const std::string CFSecRamSecGroupTable::CLASS_NAME( "CFSecRamSecGroupTable" );

	CFSecRamSecGroupTable::CFSecRamSecGroupTable( ICFSecSchema* argSchema )
	: cfsec::ICFSecSecGroupTable()
	{
		schema = argSchema;
		dictByPKey = new std::map<cfsec::CFSecSecGroupPKey, cfsec::CFSecSecGroupBuff*>();
		dictByClusterIdx = new std::map<cfsec::CFSecSecGroupByClusterIdxKey,
			std::map<cfsec::CFSecSecGroupPKey,
				cfsec::CFSecSecGroupBuff*>*>();
		dictByClusterVisIdx = new std::map<cfsec::CFSecSecGroupByClusterVisIdxKey,
			std::map<cfsec::CFSecSecGroupPKey,
				cfsec::CFSecSecGroupBuff*>*>();
		dictByUNameIdx = new std::map<cfsec::CFSecSecGroupByUNameIdxKey, cfsec::CFSecSecGroupBuff*>();
	}

	CFSecRamSecGroupTable::~CFSecRamSecGroupTable() {
		if( dictByClusterIdx != NULL ) {
			for( auto iterDict = dictByClusterIdx->begin(); iterDict != dictByClusterIdx->end(); iterDict ++ ) {
				delete iterDict->second;
				iterDict->second = NULL;
			}
			delete dictByClusterIdx;
			dictByClusterIdx = NULL;
		}
		if( dictByClusterVisIdx != NULL ) {
			for( auto iterDict = dictByClusterVisIdx->begin(); iterDict != dictByClusterVisIdx->end(); iterDict ++ ) {
				delete iterDict->second;
				iterDict->second = NULL;
			}
			delete dictByClusterVisIdx;
			dictByClusterVisIdx = NULL;
		}
		if( dictByUNameIdx != NULL ) {
			delete dictByUNameIdx;
			dictByUNameIdx = NULL;
		}
		if( dictByPKey != NULL ) {
			cfsec::CFSecSecGroupBuff* elt;
			std::map<cfsec::CFSecSecGroupPKey,
				cfsec::CFSecSecGroupBuff*>::iterator end = dictByPKey->end();
			for( std::map<cfsec::CFSecSecGroupPKey,
					cfsec::CFSecSecGroupBuff*>::iterator cur = dictByPKey->begin();
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

	cfsec::CFSecSecGroupBuff* CFSecRamSecGroupTable::createSecGroup( const cfsec::CFSecAuthorization* Authorization,
		cfsec::CFSecSecGroupBuff* Buff )
	{
		static const std::string S_ProcName( "createSecGroup" );
		cfsec::CFSecSecGroupPKey pkey;
		pkey.setRequiredClusterId( Buff->getRequiredClusterId() );
		pkey.setRequiredSecGroupId( dynamic_cast<CFSecRamClusterTable*>( schema->getTableCluster() )->nextSecGroupIdGen( Authorization,
			Buff->getRequiredClusterId() ) );
		Buff->setRequiredClusterId( pkey.getRequiredClusterId() );
		Buff->setRequiredSecGroupId( pkey.getRequiredSecGroupId() );
		cfsec::CFSecSecGroupByClusterIdxKey keyClusterIdx;
		keyClusterIdx.setRequiredClusterId( Buff->getRequiredClusterId() );
		cfsec::CFSecSecGroupByClusterVisIdxKey keyClusterVisIdx;
		keyClusterVisIdx.setRequiredClusterId( Buff->getRequiredClusterId() );
		keyClusterVisIdx.setRequiredIsVisible( Buff->getRequiredIsVisible() );
		cfsec::CFSecSecGroupByUNameIdxKey keyUNameIdx;
		keyUNameIdx.setRequiredClusterId( Buff->getRequiredClusterId() );
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
			std::string Msg( "Duplicate key detected for index SecGroupUNameIdx " + keyUNameIdx.toString() );
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
					std::string Msg( "Could not resolve Container relationship SecGroupCluster to table Cluster" );
					throw cflib::CFLibUnresolvedRelationException( CLASS_NAME,
						S_ProcName,
						Msg );
				}
				delete chk;
				chk = NULL;
			}
		}

		// Proceed with adding the new record
		cfsec::CFSecSecGroupBuff* buff = Buff;
		buff->setRequiredRevision( 1 );
		dictByPKey->insert( std::map<cfsec::CFSecSecGroupPKey, cfsec::CFSecSecGroupBuff*>::value_type( pkey, buff ) );

		std::map<cfsec::CFSecSecGroupPKey, cfsec::CFSecSecGroupBuff*>* subdictClusterIdx;
		auto searchDictByClusterIdx = dictByClusterIdx->find( keyClusterIdx );
		if( searchDictByClusterIdx != dictByClusterIdx->end() ) {
			subdictClusterIdx = searchDictByClusterIdx->second;
		}
		else {
			subdictClusterIdx = new std::map<cfsec::CFSecSecGroupPKey, cfsec::CFSecSecGroupBuff*>();
			dictByClusterIdx->insert( std::map<cfsec::CFSecSecGroupByClusterIdxKey,
				std::map<cfsec::CFSecSecGroupPKey,
					cfsec::CFSecSecGroupBuff*>*>::value_type( keyClusterIdx, subdictClusterIdx ) );
		}
		subdictClusterIdx->insert( std::map<cfsec::CFSecSecGroupPKey, cfsec::CFSecSecGroupBuff*>::value_type( pkey, buff ) );

		std::map<cfsec::CFSecSecGroupPKey, cfsec::CFSecSecGroupBuff*>* subdictClusterVisIdx;
		auto searchDictByClusterVisIdx = dictByClusterVisIdx->find( keyClusterVisIdx );
		if( searchDictByClusterVisIdx != dictByClusterVisIdx->end() ) {
			subdictClusterVisIdx = searchDictByClusterVisIdx->second;
		}
		else {
			subdictClusterVisIdx = new std::map<cfsec::CFSecSecGroupPKey, cfsec::CFSecSecGroupBuff*>();
			dictByClusterVisIdx->insert( std::map<cfsec::CFSecSecGroupByClusterVisIdxKey,
				std::map<cfsec::CFSecSecGroupPKey,
					cfsec::CFSecSecGroupBuff*>*>::value_type( keyClusterVisIdx, subdictClusterVisIdx ) );
		}
		subdictClusterVisIdx->insert( std::map<cfsec::CFSecSecGroupPKey, cfsec::CFSecSecGroupBuff*>::value_type( pkey, buff ) );

		dictByUNameIdx->insert( std::map<cfsec::CFSecSecGroupByUNameIdxKey, cfsec::CFSecSecGroupBuff*>::value_type( keyUNameIdx, buff ) );

		// The top level code has to clone the final buffer. The one passed in is now part of the persistent storage.
		if( buff->getClassCode() == cfsec::CFSecSecGroupBuff::CLASS_CODE ) {
			buff = dynamic_cast<cfsec::CFSecSecGroupBuff*>( buff->clone() );
		}
		return( buff );
	}

	cfsec::CFSecSecGroupBuff* CFSecRamSecGroupTable::readDerived( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecGroupPKey* PKey )
	{
		static const std::string S_ProcName( "readDerived" );
		cfsec::CFSecSecGroupBuff* buff;
		auto searchDictByPKey = dictByPKey->find( *PKey );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfsec::CFSecSecGroupBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecSecGroupBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfsec::CFSecSecGroupBuff* CFSecRamSecGroupTable::lockDerived( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecGroupPKey* PKey )
	{
		static const std::string S_ProcName( "lockDerived" );
		cfsec::CFSecSecGroupBuff* buff;
		auto searchDictByPKey = dictByPKey->find( *PKey );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfsec::CFSecSecGroupBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecSecGroupBuff*>( buff->clone() );
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

	std::TCFLibOwningVector<cfsec::CFSecSecGroupBuff*> CFSecRamSecGroupTable::readAllDerived( const cfsec::CFSecAuthorization* Authorization ) {
		static const std::string S_ProcName( "readAllDerived" );
		std::TCFLibOwningVector<cfsec::CFSecSecGroupBuff*> retVec;
		std::map<cfsec::CFSecSecGroupPKey,
			cfsec::CFSecSecGroupBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecSecGroupPKey,
			cfsec::CFSecSecGroupBuff*>::iterator end = dictByPKey->end();
		cfsec::CFSecSecGroupBuff* clone;
		while( iter != end ) {
			clone = dynamic_cast<cfsec::CFSecSecGroupBuff*>( iter->second->clone() );
			retVec.push_back( clone );
			iter ++;
		}
		return( retVec );
	}

	std::TCFLibOwningVector<cfsec::CFSecSecGroupBuff*> CFSecRamSecGroupTable::readDerivedByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId )
	{
		static const std::string S_ProcName( "readDerivedByClusterIdx" );
		cfsec::CFSecSecGroupByClusterIdxKey key;
		key.setRequiredClusterId( ClusterId );
		std::TCFLibOwningVector<cfsec::CFSecSecGroupBuff*> recVec;
		cfsec::CFSecSecGroupBuff* clone;
		auto searchDictByClusterIdx = dictByClusterIdx->find( key );
		if( searchDictByClusterIdx != dictByClusterIdx->end() ) {
			std::map<cfsec::CFSecSecGroupPKey,
				 cfsec::CFSecSecGroupBuff*>* subdictClusterIdx = searchDictByClusterIdx->second;
			std::map<cfsec::CFSecSecGroupPKey,
				cfsec::CFSecSecGroupBuff*>::iterator iter = subdictClusterIdx->begin();
			std::map<cfsec::CFSecSecGroupPKey,
				cfsec::CFSecSecGroupBuff*>::iterator end = subdictClusterIdx->end();
			while( iter != end ) {
				clone = dynamic_cast<cfsec::CFSecSecGroupBuff*>( iter->second->clone() );
				recVec.push_back( clone );
				iter ++;
			}
		}
		return( recVec );
	}

	std::TCFLibOwningVector<cfsec::CFSecSecGroupBuff*> CFSecRamSecGroupTable::readDerivedByClusterVisIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const bool IsVisible )
	{
		static const std::string S_ProcName( "readDerivedByClusterVisIdx" );
		cfsec::CFSecSecGroupByClusterVisIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredIsVisible( IsVisible );
		std::TCFLibOwningVector<cfsec::CFSecSecGroupBuff*> recVec;
		cfsec::CFSecSecGroupBuff* clone;
		auto searchDictByClusterVisIdx = dictByClusterVisIdx->find( key );
		if( searchDictByClusterVisIdx != dictByClusterVisIdx->end() ) {
			std::map<cfsec::CFSecSecGroupPKey,
				 cfsec::CFSecSecGroupBuff*>* subdictClusterVisIdx = searchDictByClusterVisIdx->second;
			std::map<cfsec::CFSecSecGroupPKey,
				cfsec::CFSecSecGroupBuff*>::iterator iter = subdictClusterVisIdx->begin();
			std::map<cfsec::CFSecSecGroupPKey,
				cfsec::CFSecSecGroupBuff*>::iterator end = subdictClusterVisIdx->end();
			while( iter != end ) {
				clone = dynamic_cast<cfsec::CFSecSecGroupBuff*>( iter->second->clone() );
				recVec.push_back( clone );
				iter ++;
			}
		}
		return( recVec );
	}

	cfsec::CFSecSecGroupBuff* CFSecRamSecGroupTable::readDerivedByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const std::string& Name )
	{
		static const std::string S_ProcName( "readDerivedByUNameIdx" );
		cfsec::CFSecSecGroupByUNameIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredName( Name );
		cfsec::CFSecSecGroupBuff* buff;
		auto searchDictByUNameIdx = dictByUNameIdx->find( key );
		if( searchDictByUNameIdx != dictByUNameIdx->end() ) {
			buff = dynamic_cast<cfsec::CFSecSecGroupBuff*>( searchDictByUNameIdx->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecSecGroupBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfsec::CFSecSecGroupBuff* CFSecRamSecGroupTable::readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecGroupId )
	{
		static const std::string S_ProcName( "readDerivedByIdIdx" );
		cfsec::CFSecSecGroupPKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredSecGroupId( SecGroupId );
		cfsec::CFSecSecGroupBuff* buff;
		auto searchDictByPKey = dictByPKey->find( key );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfsec::CFSecSecGroupBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecSecGroupBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfsec::CFSecSecGroupBuff* CFSecRamSecGroupTable::readBuff( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecGroupPKey* PKey )
	{
		static const std::string S_ProcName( "readBuff" );
		cfsec::CFSecSecGroupBuff* buff = readDerived( Authorization, PKey );
		if( buff != NULL ) {
			if( buff->getClassCode() != cfsec::CFSecSecGroupBuff::CLASS_CODE ) {
				delete buff;
				buff = NULL;
			}
		}
		return( dynamic_cast<cfsec::CFSecSecGroupBuff*>( buff ) );
	}

	cfsec::CFSecSecGroupBuff* CFSecRamSecGroupTable::lockBuff( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecGroupPKey* PKey )
	{
		static const std::string S_ProcName( "lockBuff" );
		cfsec::CFSecSecGroupBuff* buff = lockDerived( Authorization, PKey );
		return( dynamic_cast<cfsec::CFSecSecGroupBuff*>( buff ) );
	}

	std::TCFLibOwningVector<cfsec::CFSecSecGroupBuff*> CFSecRamSecGroupTable::readAllBuff( const cfsec::CFSecAuthorization* Authorization )
	{
		static const std::string S_ProcName( "readAllBuff" );
		cfsec::CFSecSecGroupBuff* buff;
		std::TCFLibOwningVector<cfsec::CFSecSecGroupBuff*> filteredList;
		std::TCFLibOwningVector<cfsec::CFSecSecGroupBuff*> buffList = readAllDerived( Authorization );
		std::TCFLibOwningVector<cfsec::CFSecSecGroupBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecGroupBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfsec::CFSecSecGroupBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfsec::CFSecSecGroupBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	cfsec::CFSecSecGroupBuff* CFSecRamSecGroupTable::readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecGroupId )
	{
		static const std::string S_ProcName( "readBuffByIdIdx" );
		cfsec::CFSecSecGroupBuff* buff = readDerivedByIdIdx( Authorization,
			ClusterId,
			SecGroupId );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfsec::CFSecSecGroupBuff::CLASS_CODE ) {
			return( dynamic_cast<cfsec::CFSecSecGroupBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	std::TCFLibOwningVector<cfsec::CFSecSecGroupBuff*> CFSecRamSecGroupTable::readBuffByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId )
	{
		static const std::string S_ProcName( "readBuffByClusterIdx" );
		cfsec::CFSecSecGroupBuff* buff;
		std::TCFLibOwningVector<cfsec::CFSecSecGroupBuff*> filteredList;
		std::TCFLibOwningVector<cfsec::CFSecSecGroupBuff*> buffList = readDerivedByClusterIdx( Authorization,
			ClusterId );
		std::TCFLibOwningVector<cfsec::CFSecSecGroupBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecGroupBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfsec::CFSecSecGroupBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfsec::CFSecSecGroupBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	std::TCFLibOwningVector<cfsec::CFSecSecGroupBuff*> CFSecRamSecGroupTable::readBuffByClusterVisIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const bool IsVisible )
	{
		static const std::string S_ProcName( "readBuffByClusterVisIdx" );
		cfsec::CFSecSecGroupBuff* buff;
		std::TCFLibOwningVector<cfsec::CFSecSecGroupBuff*> filteredList;
		std::TCFLibOwningVector<cfsec::CFSecSecGroupBuff*> buffList = readDerivedByClusterVisIdx( Authorization,
			ClusterId,
			IsVisible );
		std::TCFLibOwningVector<cfsec::CFSecSecGroupBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecGroupBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfsec::CFSecSecGroupBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfsec::CFSecSecGroupBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	cfsec::CFSecSecGroupBuff* CFSecRamSecGroupTable::readBuffByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const std::string& Name )
	{
		static const std::string S_ProcName( "readBuffByUNameIdx" );
		cfsec::CFSecSecGroupBuff* buff = readDerivedByUNameIdx( Authorization,
			ClusterId,
			Name );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfsec::CFSecSecGroupBuff::CLASS_CODE ) {
			return( dynamic_cast<cfsec::CFSecSecGroupBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	cfsec::CFSecSecGroupBuff* CFSecRamSecGroupTable::readBuffByLookupUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId, const std::string& Name,
		bool forceRead )
	{
		static const std::string S_ProcName( "readBuffByLookupUNameIdx" );
		cfsec::CFSecSecGroupBuff* buff = readBuffByUNameIdx( Authorization,
			ClusterId,
			Name );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfsec::CFSecSecGroupBuff::CLASS_CODE ) {
			return( dynamic_cast<cfsec::CFSecSecGroupBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	cfsec::CFSecSecGroupBuff* CFSecRamSecGroupTable::readDerivedByLookupUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId, const std::string& Name,
		bool forceRead )
	{
		static const std::string S_ProcName( "readDerivedByLookupUNameIdx" );
		cfsec::CFSecSecGroupBuff* buff = readDerivedByUNameIdx( Authorization,
			ClusterId,
			Name );
		if( buff != NULL ) {
			return( dynamic_cast<cfsec::CFSecSecGroupBuff*>( buff->clone() ) );
		}
		else {
			return( NULL );
		}
	}

	cfsec::CFSecSecGroupBuff* CFSecRamSecGroupTable::updateSecGroup( const cfsec::CFSecAuthorization* Authorization,
		cfsec::CFSecSecGroupBuff* Buff )
	{
		static const std::string S_ProcName( "updateSecGroup" );
		cfsec::CFSecSecGroupPKey pkey;
		pkey.setRequiredClusterId( Buff->getRequiredClusterId() );
		pkey.setRequiredSecGroupId( Buff->getRequiredSecGroupId() );

		// Search for existing buffer

		auto searchExisting = dictByPKey->find( pkey );
		if( searchExisting == dictByPKey->end() ) {
			delete Buff;
			std::string Msg( "Existing record not found in SecGroup for key " + pkey.toString() );
			throw cflib::CFLibStaleCacheDetectedException( CLASS_NAME,
				S_ProcName,
				Msg );
		}

		cfsec::CFSecSecGroupBuff* existing = searchExisting->second;

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
			std::string Msg( "Collision detected for SecGroup primary key " );
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
		cfsec::CFSecSecGroupByClusterIdxKey existingKeyClusterIdx;
		existingKeyClusterIdx.setRequiredClusterId( existing->getRequiredClusterId() );
		cfsec::CFSecSecGroupByClusterIdxKey newKeyClusterIdx;
		newKeyClusterIdx.setRequiredClusterId( Buff->getRequiredClusterId() );
		cfsec::CFSecSecGroupByClusterVisIdxKey existingKeyClusterVisIdx;
		existingKeyClusterVisIdx.setRequiredClusterId( existing->getRequiredClusterId() );
		existingKeyClusterVisIdx.setRequiredIsVisible( existing->getRequiredIsVisible() );
		cfsec::CFSecSecGroupByClusterVisIdxKey newKeyClusterVisIdx;
		newKeyClusterVisIdx.setRequiredClusterId( Buff->getRequiredClusterId() );
		newKeyClusterVisIdx.setRequiredIsVisible( Buff->getRequiredIsVisible() );
		cfsec::CFSecSecGroupByUNameIdxKey existingKeyUNameIdx;
		existingKeyUNameIdx.setRequiredClusterId( existing->getRequiredClusterId() );
		existingKeyUNameIdx.setRequiredName( existing->getRequiredName() );
		cfsec::CFSecSecGroupByUNameIdxKey newKeyUNameIdx;
		newKeyUNameIdx.setRequiredClusterId( Buff->getRequiredClusterId() );
		newKeyUNameIdx.setRequiredName( Buff->getRequiredName() );
		// Check unique indexes

		if( existingKeyUNameIdx != newKeyUNameIdx ) {
			auto searchDictByUNameIdx = dictByUNameIdx->find( newKeyUNameIdx );
			if( searchDictByUNameIdx != dictByUNameIdx->end() ) {
				std::string Msg( "Duplicate key detected for index SecGroupUNameIdx " + newKeyUNameIdx.toString() );
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
					std::string Msg( "Could not resolve Container relationship SecGroupCluster to table Cluster" );
					throw cflib::CFLibUnresolvedRelationException( CLASS_NAME,
						S_ProcName,
						Msg );
				}
				delete chk;
				chk = NULL;
			}
		}

		// Update is valid
		std::map<cfsec::CFSecSecGroupPKey, cfsec::CFSecSecGroupBuff*>* subdict;
		auto removalDictByPKey = dictByPKey->find( pkey );
		if( removalDictByPKey != dictByPKey->end() ) {
			dictByPKey->erase( removalDictByPKey );
		}
		// Copy edited buffer to existing persistent buffer

		if( Buff->getClassCode() != cfsec::CFSecSecGroupBuff::CLASS_CODE ) {
			const static std::string S_IsNotA( " is not a cfsec::CFSecSecGroupBuff" );
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

		dictByPKey->insert( std::map<cfsec::CFSecSecGroupPKey, cfsec::CFSecSecGroupBuff*>::value_type( pkey, existing ) );

		std::map<cfsec::CFSecSecGroupPKey,
			 cfsec::CFSecSecGroupBuff*>* subdictClusterIdx;
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
			subdictClusterIdx = new std::map<cfsec::CFSecSecGroupPKey, cfsec::CFSecSecGroupBuff*>();
			dictByClusterIdx->insert( std::map<cfsec::CFSecSecGroupByClusterIdxKey,
				std::map<cfsec::CFSecSecGroupPKey,
					cfsec::CFSecSecGroupBuff*>*>::value_type( newKeyClusterIdx, subdictClusterIdx ) );
		}
		subdictClusterIdx->insert( std::map<cfsec::CFSecSecGroupPKey, cfsec::CFSecSecGroupBuff*>::value_type( pkey, existing ) );

		std::map<cfsec::CFSecSecGroupPKey,
			 cfsec::CFSecSecGroupBuff*>* subdictClusterVisIdx;
		auto searchDictByClusterVisIdx = dictByClusterVisIdx->find( existingKeyClusterVisIdx );
		if( searchDictByClusterVisIdx != dictByClusterVisIdx->end() ) {
			subdictClusterVisIdx = searchDictByClusterVisIdx->second;
			auto searchSubDict = subdictClusterVisIdx->find( pkey );
			if( searchSubDict != subdictClusterVisIdx->end() ) {
				subdictClusterVisIdx->erase( searchSubDict );
			}
			if( subdictClusterVisIdx->size() <= 0 ) {
				delete subdictClusterVisIdx;
				dictByClusterVisIdx->erase( searchDictByClusterVisIdx );
			}
			subdictClusterVisIdx = NULL;
		}
		auto searchNewKeyDictByClusterVisIdx = dictByClusterVisIdx->find( newKeyClusterVisIdx );
		if( searchNewKeyDictByClusterVisIdx != dictByClusterVisIdx->end() ) {
			subdictClusterVisIdx = searchNewKeyDictByClusterVisIdx->second;
		}
		else {
			subdictClusterVisIdx = new std::map<cfsec::CFSecSecGroupPKey, cfsec::CFSecSecGroupBuff*>();
			dictByClusterVisIdx->insert( std::map<cfsec::CFSecSecGroupByClusterVisIdxKey,
				std::map<cfsec::CFSecSecGroupPKey,
					cfsec::CFSecSecGroupBuff*>*>::value_type( newKeyClusterVisIdx, subdictClusterVisIdx ) );
		}
		subdictClusterVisIdx->insert( std::map<cfsec::CFSecSecGroupPKey, cfsec::CFSecSecGroupBuff*>::value_type( pkey, existing ) );

		auto removalDictByUNameIdx = dictByUNameIdx->find( existingKeyUNameIdx );
		if( removalDictByUNameIdx != dictByUNameIdx->end() ) {
			dictByUNameIdx->erase( removalDictByUNameIdx );
		}
		dictByUNameIdx->insert( std::map<cfsec::CFSecSecGroupByUNameIdxKey, cfsec::CFSecSecGroupBuff*>::value_type( newKeyUNameIdx, existing ) );


		// The top level code has to clean up the memory buffer that was passed in, and return a clone
		// of the copy that existing buffer that is attached to the RAM storage.  All other cases
		// return the existing buffer.

		cfsec::CFSecSecGroupBuff* buff;
		if( existing->getClassCode() == cfsec::CFSecSecGroupBuff::CLASS_CODE ) {
			delete Buff;
			Buff = NULL;
			buff = dynamic_cast<cfsec::CFSecSecGroupBuff*>( existing->clone() );
		}
		else {
			buff = existing;
		}
		return( buff );
	}

	void CFSecRamSecGroupTable::deleteSecGroup( const cfsec::CFSecAuthorization* Authorization,
		cfsec::CFSecSecGroupBuff* Buff )
	{
		static const std::string S_ProcName( "deleteSecGroup" );
		static const std::string S_Prev( "prev" );
		classcode_t classCode;
		cfsec::CFSecSecGroupPKey pkey;
		pkey.setRequiredClusterId( Buff->getRequiredClusterId() );
		pkey.setRequiredSecGroupId( Buff->getRequiredSecGroupId() );
		auto searchExisting = dictByPKey->find( pkey );
		if( searchExisting == dictByPKey->end() ) {
			return;
		}
		cfsec::CFSecSecGroupBuff* existing = searchExisting->second;
		schema->getTableSecGroupForm()->deleteSecGroupFormByGroupIdx( Authorization,
			existing->getRequiredClusterId(),
			existing->getRequiredSecGroupId() );
		schema->getTableSecGrpInc()->deleteSecGrpIncByIncludeIdx( Authorization,
			existing->getRequiredClusterId(),
			existing->getRequiredSecGroupId() );
		schema->getTableSecGrpMemb()->deleteSecGrpMembByGroupIdx( Authorization,
			existing->getRequiredClusterId(),
			existing->getRequiredSecGroupId() );
		schema->getTableSecGrpInc()->deleteSecGrpIncByGroupIdx( Authorization,
			existing->getRequiredClusterId(),
			existing->getRequiredSecGroupId() );
		cfsec::CFSecSecGroupByClusterIdxKey keyClusterIdx;
		keyClusterIdx.setRequiredClusterId( existing->getRequiredClusterId() );
		cfsec::CFSecSecGroupByClusterVisIdxKey keyClusterVisIdx;
		keyClusterVisIdx.setRequiredClusterId( existing->getRequiredClusterId() );
		keyClusterVisIdx.setRequiredIsVisible( existing->getRequiredIsVisible() );
		cfsec::CFSecSecGroupByUNameIdxKey keyUNameIdx;
		keyUNameIdx.setRequiredClusterId( existing->getRequiredClusterId() );
		keyUNameIdx.setRequiredName( existing->getRequiredName() );
		// Validate reverse foreign keys

		// Delete is valid
		std::map<cfsec::CFSecSecGroupPKey, cfsec::CFSecSecGroupBuff*>* subdict;

		auto searchDictByPKey = dictByPKey->find( pkey );
		if( searchDictByPKey != dictByPKey->end() ) {
			dictByPKey->erase( searchDictByPKey );
		}

		auto searchDictByClusterIdx = dictByClusterIdx->find( keyClusterIdx );
		if( searchDictByClusterIdx != dictByClusterIdx->end() ) {
			std::map<cfsec::CFSecSecGroupPKey,
				 cfsec::CFSecSecGroupBuff*>* subdictClusterIdx = searchDictByClusterIdx->second;
			auto searchSubDict = subdictClusterIdx->find( pkey );
			if( searchSubDict != subdictClusterIdx->end() ) {
				subdictClusterIdx->erase( searchSubDict );
			}
			subdictClusterIdx = NULL;
		}

		auto searchDictByClusterVisIdx = dictByClusterVisIdx->find( keyClusterVisIdx );
		if( searchDictByClusterVisIdx != dictByClusterVisIdx->end() ) {
			std::map<cfsec::CFSecSecGroupPKey,
				 cfsec::CFSecSecGroupBuff*>* subdictClusterVisIdx = searchDictByClusterVisIdx->second;
			auto searchSubDict = subdictClusterVisIdx->find( pkey );
			if( searchSubDict != subdictClusterVisIdx->end() ) {
				subdictClusterVisIdx->erase( searchSubDict );
			}
			subdictClusterVisIdx = NULL;
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

	void CFSecRamSecGroupTable::deleteSecGroupByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const int32_t argSecGroupId )
	{
		cfsec::CFSecSecGroupPKey key;
		key.setRequiredClusterId( argClusterId );
		key.setRequiredSecGroupId( argSecGroupId );
		deleteSecGroupByIdIdx( Authorization, &key );
	}

	void CFSecRamSecGroupTable::deleteSecGroupByIdIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecGroupPKey* argKey )
	{
		bool anyNotNull = false;
		anyNotNull = true;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		cfsec::CFSecSecGroupBuff* cur = NULL;
		cfsec::CFSecSecGroupBuff* rereadCur = NULL;
		std::TCFLibOwningVector<cfsec::CFSecSecGroupBuff*> matchSet;
		std::map<cfsec::CFSecSecGroupPKey,
			cfsec::CFSecSecGroupBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecSecGroupPKey,
			cfsec::CFSecSecGroupBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecSecGroupBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecSecGroupBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecSecGroupBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecGroupBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableSecGroup()->readDerivedByIdIdx( Authorization,
				cur->getRequiredClusterId(),
				cur->getRequiredSecGroupId() );
			rereadCur = cur;
			deleteSecGroup( Authorization, cur );
			if( rereadCur != NULL ) {
				delete rereadCur;
				rereadCur = NULL;
			}
		}
	}

	void CFSecRamSecGroupTable::deleteSecGroupByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId )
	{
		cfsec::CFSecSecGroupByClusterIdxKey key;
		key.setRequiredClusterId( argClusterId );
		deleteSecGroupByClusterIdx( Authorization, &key );
	}

	void CFSecRamSecGroupTable::deleteSecGroupByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecGroupByClusterIdxKey* argKey )
	{
		cfsec::CFSecSecGroupBuff* cur = NULL;
		cfsec::CFSecSecGroupBuff* rereadCur = NULL;
		bool anyNotNull = false;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfsec::CFSecSecGroupBuff*> matchSet;
		std::map<cfsec::CFSecSecGroupPKey,
			cfsec::CFSecSecGroupBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecSecGroupPKey,
			cfsec::CFSecSecGroupBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecSecGroupBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecSecGroupBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecSecGroupBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecGroupBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableSecGroup()->readDerivedByIdIdx( Authorization,
				cur->getRequiredClusterId(),
				cur->getRequiredSecGroupId() );
			rereadCur = cur;
			deleteSecGroup( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFSecRamSecGroupTable::deleteSecGroupByClusterVisIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const bool argIsVisible )
	{
		cfsec::CFSecSecGroupByClusterVisIdxKey key;
		key.setRequiredClusterId( argClusterId );
		key.setRequiredIsVisible( argIsVisible );
		deleteSecGroupByClusterVisIdx( Authorization, &key );
	}

	void CFSecRamSecGroupTable::deleteSecGroupByClusterVisIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecGroupByClusterVisIdxKey* argKey )
	{
		cfsec::CFSecSecGroupBuff* cur = NULL;
		cfsec::CFSecSecGroupBuff* rereadCur = NULL;
		bool anyNotNull = false;
		anyNotNull = true;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfsec::CFSecSecGroupBuff*> matchSet;
		std::map<cfsec::CFSecSecGroupPKey,
			cfsec::CFSecSecGroupBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecSecGroupPKey,
			cfsec::CFSecSecGroupBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecSecGroupBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecSecGroupBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecSecGroupBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecGroupBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableSecGroup()->readDerivedByIdIdx( Authorization,
				cur->getRequiredClusterId(),
				cur->getRequiredSecGroupId() );
			rereadCur = cur;
			deleteSecGroup( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFSecRamSecGroupTable::deleteSecGroupByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const std::string& argName )
	{
		cfsec::CFSecSecGroupByUNameIdxKey key;
		key.setRequiredClusterId( argClusterId );
		key.setRequiredName( argName );
		deleteSecGroupByUNameIdx( Authorization, &key );
	}

	void CFSecRamSecGroupTable::deleteSecGroupByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecGroupByUNameIdxKey* argKey )
	{
		cfsec::CFSecSecGroupBuff* cur = NULL;
		cfsec::CFSecSecGroupBuff* rereadCur = NULL;
		bool anyNotNull = false;
		anyNotNull = true;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfsec::CFSecSecGroupBuff*> matchSet;
		std::map<cfsec::CFSecSecGroupPKey,
			cfsec::CFSecSecGroupBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecSecGroupPKey,
			cfsec::CFSecSecGroupBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecSecGroupBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecSecGroupBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecSecGroupBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecGroupBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableSecGroup()->readDerivedByIdIdx( Authorization,
				cur->getRequiredClusterId(),
				cur->getRequiredSecGroupId() );
			rereadCur = cur;
			deleteSecGroup( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFSecRamSecGroupTable::releasePreparedStatements() {
	}

}
