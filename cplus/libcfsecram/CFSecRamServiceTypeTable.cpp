
// Description: C++18 Implementation for an in-memory RAM DbIO for ServiceType.

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

	const std::string CFSecRamServiceTypeTable::CLASS_NAME( "CFSecRamServiceTypeTable" );

	CFSecRamServiceTypeTable::CFSecRamServiceTypeTable( ICFSecSchema* argSchema )
	: cfsec::ICFSecServiceTypeTable()
	{
		schema = argSchema;
		dictByPKey = new std::map<cfsec::CFSecServiceTypePKey, cfsec::CFSecServiceTypeBuff*>();
		dictByUDescrIdx = new std::map<cfsec::CFSecServiceTypeByUDescrIdxKey, cfsec::CFSecServiceTypeBuff*>();
	}

	CFSecRamServiceTypeTable::~CFSecRamServiceTypeTable() {
		if( dictByUDescrIdx != NULL ) {
			delete dictByUDescrIdx;
			dictByUDescrIdx = NULL;
		}
		if( dictByPKey != NULL ) {
			cfsec::CFSecServiceTypeBuff* elt;
			std::map<cfsec::CFSecServiceTypePKey,
				cfsec::CFSecServiceTypeBuff*>::iterator end = dictByPKey->end();
			for( std::map<cfsec::CFSecServiceTypePKey,
					cfsec::CFSecServiceTypeBuff*>::iterator cur = dictByPKey->begin();
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

	cfsec::CFSecServiceTypeBuff* CFSecRamServiceTypeTable::createServiceType( const cfsec::CFSecAuthorization* Authorization,
		cfsec::CFSecServiceTypeBuff* Buff )
	{
		static const std::string S_ProcName( "createServiceType" );
		cfsec::CFSecServiceTypePKey pkey;
		pkey.setRequiredServiceTypeId( schema->nextServiceTypeIdGen() );
		Buff->setRequiredServiceTypeId( pkey.getRequiredServiceTypeId() );
		cfsec::CFSecServiceTypeByUDescrIdxKey keyUDescrIdx;
		keyUDescrIdx.setRequiredDescription( Buff->getRequiredDescription() );
		// Validate unique indexes
		auto searchDictByPKey = dictByPKey->find( pkey );
		if( searchDictByPKey != dictByPKey->end() ) {
			delete Buff;
			std::string Msg( "Duplicate primary key detected " + pkey.toString() );
			throw cflib::CFLibPrimaryKeyNotNewException( CLASS_NAME, S_ProcName, Msg );
		}

		auto searchDictByUDescrIdx = dictByUDescrIdx->find( keyUDescrIdx );
		if( searchDictByUDescrIdx != dictByUDescrIdx->end() ) {
			std::string Msg( "Duplicate key detected for index ServiceTypeUDescrIdx " + keyUDescrIdx.toString() );
			delete Buff;
			throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
				S_ProcName,
				Msg );
		}

		// Validate foreign keys

		// Proceed with adding the new record
		cfsec::CFSecServiceTypeBuff* buff = Buff;
		buff->setRequiredRevision( 1 );
		dictByPKey->insert( std::map<cfsec::CFSecServiceTypePKey, cfsec::CFSecServiceTypeBuff*>::value_type( pkey, buff ) );

		dictByUDescrIdx->insert( std::map<cfsec::CFSecServiceTypeByUDescrIdxKey, cfsec::CFSecServiceTypeBuff*>::value_type( keyUDescrIdx, buff ) );

		// The top level code has to clone the final buffer. The one passed in is now part of the persistent storage.
		if( buff->getClassCode() == cfsec::CFSecServiceTypeBuff::CLASS_CODE ) {
			buff = dynamic_cast<cfsec::CFSecServiceTypeBuff*>( buff->clone() );
		}
		return( buff );
	}

	cfsec::CFSecServiceTypeBuff* CFSecRamServiceTypeTable::readDerived( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecServiceTypePKey* PKey )
	{
		static const std::string S_ProcName( "readDerived" );
		cfsec::CFSecServiceTypeBuff* buff;
		auto searchDictByPKey = dictByPKey->find( *PKey );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfsec::CFSecServiceTypeBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecServiceTypeBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfsec::CFSecServiceTypeBuff* CFSecRamServiceTypeTable::lockDerived( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecServiceTypePKey* PKey )
	{
		static const std::string S_ProcName( "lockDerived" );
		cfsec::CFSecServiceTypeBuff* buff;
		auto searchDictByPKey = dictByPKey->find( *PKey );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfsec::CFSecServiceTypeBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecServiceTypeBuff*>( buff->clone() );
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

	std::TCFLibOwningVector<cfsec::CFSecServiceTypeBuff*> CFSecRamServiceTypeTable::readAllDerived( const cfsec::CFSecAuthorization* Authorization ) {
		static const std::string S_ProcName( "readAllDerived" );
		std::TCFLibOwningVector<cfsec::CFSecServiceTypeBuff*> retVec;
		std::map<cfsec::CFSecServiceTypePKey,
			cfsec::CFSecServiceTypeBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecServiceTypePKey,
			cfsec::CFSecServiceTypeBuff*>::iterator end = dictByPKey->end();
		cfsec::CFSecServiceTypeBuff* clone;
		while( iter != end ) {
			clone = dynamic_cast<cfsec::CFSecServiceTypeBuff*>( iter->second->clone() );
			retVec.push_back( clone );
			iter ++;
		}
		return( retVec );
	}

	cfsec::CFSecServiceTypeBuff* CFSecRamServiceTypeTable::readDerivedByUDescrIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& Description )
	{
		static const std::string S_ProcName( "readDerivedByUDescrIdx" );
		cfsec::CFSecServiceTypeByUDescrIdxKey key;
		key.setRequiredDescription( Description );
		cfsec::CFSecServiceTypeBuff* buff;
		auto searchDictByUDescrIdx = dictByUDescrIdx->find( key );
		if( searchDictByUDescrIdx != dictByUDescrIdx->end() ) {
			buff = dynamic_cast<cfsec::CFSecServiceTypeBuff*>( searchDictByUDescrIdx->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecServiceTypeBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfsec::CFSecServiceTypeBuff* CFSecRamServiceTypeTable::readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int32_t ServiceTypeId )
	{
		static const std::string S_ProcName( "readDerivedByIdIdx" );
		cfsec::CFSecServiceTypePKey key;
		key.setRequiredServiceTypeId( ServiceTypeId );
		cfsec::CFSecServiceTypeBuff* buff;
		auto searchDictByPKey = dictByPKey->find( key );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfsec::CFSecServiceTypeBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecServiceTypeBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfsec::CFSecServiceTypeBuff* CFSecRamServiceTypeTable::readBuff( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecServiceTypePKey* PKey )
	{
		static const std::string S_ProcName( "readBuff" );
		cfsec::CFSecServiceTypeBuff* buff = readDerived( Authorization, PKey );
		if( buff != NULL ) {
			if( buff->getClassCode() != cfsec::CFSecServiceTypeBuff::CLASS_CODE ) {
				delete buff;
				buff = NULL;
			}
		}
		return( dynamic_cast<cfsec::CFSecServiceTypeBuff*>( buff ) );
	}

	cfsec::CFSecServiceTypeBuff* CFSecRamServiceTypeTable::lockBuff( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecServiceTypePKey* PKey )
	{
		static const std::string S_ProcName( "lockBuff" );
		cfsec::CFSecServiceTypeBuff* buff = lockDerived( Authorization, PKey );
		return( dynamic_cast<cfsec::CFSecServiceTypeBuff*>( buff ) );
	}

	std::TCFLibOwningVector<cfsec::CFSecServiceTypeBuff*> CFSecRamServiceTypeTable::readAllBuff( const cfsec::CFSecAuthorization* Authorization )
	{
		static const std::string S_ProcName( "readAllBuff" );
		cfsec::CFSecServiceTypeBuff* buff;
		std::TCFLibOwningVector<cfsec::CFSecServiceTypeBuff*> filteredList;
		std::TCFLibOwningVector<cfsec::CFSecServiceTypeBuff*> buffList = readAllDerived( Authorization );
		std::TCFLibOwningVector<cfsec::CFSecServiceTypeBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfsec::CFSecServiceTypeBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfsec::CFSecServiceTypeBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfsec::CFSecServiceTypeBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	cfsec::CFSecServiceTypeBuff* CFSecRamServiceTypeTable::readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int32_t ServiceTypeId )
	{
		static const std::string S_ProcName( "readBuffByIdIdx" );
		cfsec::CFSecServiceTypeBuff* buff = readDerivedByIdIdx( Authorization,
			ServiceTypeId );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfsec::CFSecServiceTypeBuff::CLASS_CODE ) {
			return( dynamic_cast<cfsec::CFSecServiceTypeBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	cfsec::CFSecServiceTypeBuff* CFSecRamServiceTypeTable::readBuffByUDescrIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& Description )
	{
		static const std::string S_ProcName( "readBuffByUDescrIdx" );
		cfsec::CFSecServiceTypeBuff* buff = readDerivedByUDescrIdx( Authorization,
			Description );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfsec::CFSecServiceTypeBuff::CLASS_CODE ) {
			return( dynamic_cast<cfsec::CFSecServiceTypeBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	cfsec::CFSecServiceTypeBuff* CFSecRamServiceTypeTable::readBuffByLookupUDescrIdx( const cfsec::CFSecAuthorization* Authorization, const std::string& Description,
		bool forceRead )
	{
		static const std::string S_ProcName( "readBuffByLookupUDescrIdx" );
		cfsec::CFSecServiceTypeBuff* buff = readBuffByUDescrIdx( Authorization,
			Description );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfsec::CFSecServiceTypeBuff::CLASS_CODE ) {
			return( dynamic_cast<cfsec::CFSecServiceTypeBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	cfsec::CFSecServiceTypeBuff* CFSecRamServiceTypeTable::readDerivedByLookupUDescrIdx( const cfsec::CFSecAuthorization* Authorization, const std::string& Description,
		bool forceRead )
	{
		static const std::string S_ProcName( "readDerivedByLookupUDescrIdx" );
		cfsec::CFSecServiceTypeBuff* buff = readDerivedByUDescrIdx( Authorization,
			Description );
		if( buff != NULL ) {
			return( dynamic_cast<cfsec::CFSecServiceTypeBuff*>( buff->clone() ) );
		}
		else {
			return( NULL );
		}
	}

	cfsec::CFSecServiceTypeBuff* CFSecRamServiceTypeTable::updateServiceType( const cfsec::CFSecAuthorization* Authorization,
		cfsec::CFSecServiceTypeBuff* Buff )
	{
		static const std::string S_ProcName( "updateServiceType" );
		cfsec::CFSecServiceTypePKey pkey;
		pkey.setRequiredServiceTypeId( Buff->getRequiredServiceTypeId() );

		// Search for existing buffer

		auto searchExisting = dictByPKey->find( pkey );
		if( searchExisting == dictByPKey->end() ) {
			delete Buff;
			std::string Msg( "Existing record not found in ServiceType for key " + pkey.toString() );
			throw cflib::CFLibStaleCacheDetectedException( CLASS_NAME,
				S_ProcName,
				Msg );
		}

		cfsec::CFSecServiceTypeBuff* existing = searchExisting->second;

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
			std::string Msg( "Collision detected for ServiceType primary key " );
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
		cfsec::CFSecServiceTypeByUDescrIdxKey existingKeyUDescrIdx;
		existingKeyUDescrIdx.setRequiredDescription( existing->getRequiredDescription() );
		cfsec::CFSecServiceTypeByUDescrIdxKey newKeyUDescrIdx;
		newKeyUDescrIdx.setRequiredDescription( Buff->getRequiredDescription() );
		// Check unique indexes

		if( existingKeyUDescrIdx != newKeyUDescrIdx ) {
			auto searchDictByUDescrIdx = dictByUDescrIdx->find( newKeyUDescrIdx );
			if( searchDictByUDescrIdx != dictByUDescrIdx->end() ) {
				std::string Msg( "Duplicate key detected for index ServiceTypeUDescrIdx " + newKeyUDescrIdx.toString() );
				delete Buff;
				throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
					S_ProcName,
					Msg );
			}
		}

		// Validate foreign keys

		// Update is valid
		std::map<cfsec::CFSecServiceTypePKey, cfsec::CFSecServiceTypeBuff*>* subdict;
		auto removalDictByPKey = dictByPKey->find( pkey );
		if( removalDictByPKey != dictByPKey->end() ) {
			dictByPKey->erase( removalDictByPKey );
		}
		// Copy edited buffer to existing persistent buffer

		if( Buff->getClassCode() != cfsec::CFSecServiceTypeBuff::CLASS_CODE ) {
			const static std::string S_IsNotA( " is not a cfsec::CFSecServiceTypeBuff" );
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

		dictByPKey->insert( std::map<cfsec::CFSecServiceTypePKey, cfsec::CFSecServiceTypeBuff*>::value_type( pkey, existing ) );

		auto removalDictByUDescrIdx = dictByUDescrIdx->find( existingKeyUDescrIdx );
		if( removalDictByUDescrIdx != dictByUDescrIdx->end() ) {
			dictByUDescrIdx->erase( removalDictByUDescrIdx );
		}
		dictByUDescrIdx->insert( std::map<cfsec::CFSecServiceTypeByUDescrIdxKey, cfsec::CFSecServiceTypeBuff*>::value_type( newKeyUDescrIdx, existing ) );


		// The top level code has to clean up the memory buffer that was passed in, and return a clone
		// of the copy that existing buffer that is attached to the RAM storage.  All other cases
		// return the existing buffer.

		cfsec::CFSecServiceTypeBuff* buff;
		if( existing->getClassCode() == cfsec::CFSecServiceTypeBuff::CLASS_CODE ) {
			delete Buff;
			Buff = NULL;
			buff = dynamic_cast<cfsec::CFSecServiceTypeBuff*>( existing->clone() );
		}
		else {
			buff = existing;
		}
		return( buff );
	}

	void CFSecRamServiceTypeTable::deleteServiceType( const cfsec::CFSecAuthorization* Authorization,
		cfsec::CFSecServiceTypeBuff* Buff )
	{
		static const std::string S_ProcName( "deleteServiceType" );
		static const std::string S_Prev( "prev" );
		classcode_t classCode;
		cfsec::CFSecServiceTypePKey pkey;
		pkey.setRequiredServiceTypeId( Buff->getRequiredServiceTypeId() );
		auto searchExisting = dictByPKey->find( pkey );
		if( searchExisting == dictByPKey->end() ) {
			return;
		}
		cfsec::CFSecServiceTypeBuff* existing = searchExisting->second;
		std::TCFLibOwningVector<cfsec::CFSecServiceBuff*> arrCheckServiceTypeDeployed = schema->getTableService()->readDerivedByTypeIdx( Authorization,
			existing->getRequiredServiceTypeId() );
		if( arrCheckServiceTypeDeployed.size() > 0 ) {
			schema->getTableService()->deleteServiceByTypeIdx( Authorization,
			existing->getRequiredServiceTypeId() );
		}
		cfsec::CFSecServiceTypeByUDescrIdxKey keyUDescrIdx;
		keyUDescrIdx.setRequiredDescription( existing->getRequiredDescription() );
		// Validate reverse foreign keys

		// Delete is valid
		std::map<cfsec::CFSecServiceTypePKey, cfsec::CFSecServiceTypeBuff*>* subdict;

		auto searchDictByPKey = dictByPKey->find( pkey );
		if( searchDictByPKey != dictByPKey->end() ) {
			dictByPKey->erase( searchDictByPKey );
		}

		auto searchDictByUDescrIdx = dictByUDescrIdx->find( keyUDescrIdx );
		if( searchDictByUDescrIdx != dictByUDescrIdx->end() ) {
			dictByUDescrIdx->erase( searchDictByUDescrIdx );
		}

		if( existing != NULL ) {
			delete existing;
			existing = NULL;
		}
	}

	void CFSecRamServiceTypeTable::deleteServiceTypeByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int32_t argServiceTypeId )
	{
		cfsec::CFSecServiceTypePKey key;
		key.setRequiredServiceTypeId( argServiceTypeId );
		deleteServiceTypeByIdIdx( Authorization, &key );
	}

	void CFSecRamServiceTypeTable::deleteServiceTypeByIdIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecServiceTypePKey* argKey )
	{
		bool anyNotNull = false;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		cfsec::CFSecServiceTypeBuff* cur = NULL;
		cfsec::CFSecServiceTypeBuff* rereadCur = NULL;
		std::TCFLibOwningVector<cfsec::CFSecServiceTypeBuff*> matchSet;
		std::map<cfsec::CFSecServiceTypePKey,
			cfsec::CFSecServiceTypeBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecServiceTypePKey,
			cfsec::CFSecServiceTypeBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecServiceTypeBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecServiceTypeBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecServiceTypeBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecServiceTypeBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableServiceType()->readDerivedByIdIdx( Authorization,
				cur->getRequiredServiceTypeId() );
			rereadCur = cur;
			deleteServiceType( Authorization, cur );
			if( rereadCur != NULL ) {
				delete rereadCur;
				rereadCur = NULL;
			}
		}
	}

	void CFSecRamServiceTypeTable::deleteServiceTypeByUDescrIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& argDescription )
	{
		cfsec::CFSecServiceTypeByUDescrIdxKey key;
		key.setRequiredDescription( argDescription );
		deleteServiceTypeByUDescrIdx( Authorization, &key );
	}

	void CFSecRamServiceTypeTable::deleteServiceTypeByUDescrIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecServiceTypeByUDescrIdxKey* argKey )
	{
		cfsec::CFSecServiceTypeBuff* cur = NULL;
		cfsec::CFSecServiceTypeBuff* rereadCur = NULL;
		bool anyNotNull = false;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfsec::CFSecServiceTypeBuff*> matchSet;
		std::map<cfsec::CFSecServiceTypePKey,
			cfsec::CFSecServiceTypeBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecServiceTypePKey,
			cfsec::CFSecServiceTypeBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecServiceTypeBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecServiceTypeBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecServiceTypeBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecServiceTypeBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableServiceType()->readDerivedByIdIdx( Authorization,
				cur->getRequiredServiceTypeId() );
			rereadCur = cur;
			deleteServiceType( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFSecRamServiceTypeTable::releasePreparedStatements() {
	}

}
