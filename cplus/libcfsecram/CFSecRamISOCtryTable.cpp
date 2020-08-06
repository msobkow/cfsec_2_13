
// Description: C++18 Implementation for an in-memory RAM DbIO for ISOCtry.

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

	const std::string CFSecRamISOCtryTable::CLASS_NAME( "CFSecRamISOCtryTable" );

	CFSecRamISOCtryTable::CFSecRamISOCtryTable( ICFSecSchema* argSchema )
	: cfsec::ICFSecISOCtryTable()
	{
		schema = argSchema;
		dictByPKey = new std::map<cfsec::CFSecISOCtryPKey, cfsec::CFSecISOCtryBuff*>();
		dictByISOCodeIdx = new std::map<cfsec::CFSecISOCtryByISOCodeIdxKey, cfsec::CFSecISOCtryBuff*>();
		dictByNameIdx = new std::map<cfsec::CFSecISOCtryByNameIdxKey, cfsec::CFSecISOCtryBuff*>();
	}

	CFSecRamISOCtryTable::~CFSecRamISOCtryTable() {
		if( dictByISOCodeIdx != NULL ) {
			delete dictByISOCodeIdx;
			dictByISOCodeIdx = NULL;
		}
		if( dictByNameIdx != NULL ) {
			delete dictByNameIdx;
			dictByNameIdx = NULL;
		}
		if( dictByPKey != NULL ) {
			cfsec::CFSecISOCtryBuff* elt;
			std::map<cfsec::CFSecISOCtryPKey,
				cfsec::CFSecISOCtryBuff*>::iterator end = dictByPKey->end();
			for( std::map<cfsec::CFSecISOCtryPKey,
					cfsec::CFSecISOCtryBuff*>::iterator cur = dictByPKey->begin();
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

	cfsec::CFSecISOCtryBuff* CFSecRamISOCtryTable::createISOCtry( const cfsec::CFSecAuthorization* Authorization,
		cfsec::CFSecISOCtryBuff* Buff )
	{
		static const std::string S_ProcName( "createISOCtry" );
		cfsec::CFSecISOCtryPKey pkey;
		pkey.setRequiredISOCtryId( schema->nextISOCtryIdGen() );
		Buff->setRequiredISOCtryId( pkey.getRequiredISOCtryId() );
		cfsec::CFSecISOCtryByISOCodeIdxKey keyISOCodeIdx;
		keyISOCodeIdx.setRequiredISOCode( Buff->getRequiredISOCode() );
		cfsec::CFSecISOCtryByNameIdxKey keyNameIdx;
		keyNameIdx.setRequiredName( Buff->getRequiredName() );
		// Validate unique indexes
		auto searchDictByPKey = dictByPKey->find( pkey );
		if( searchDictByPKey != dictByPKey->end() ) {
			delete Buff;
			std::string Msg( "Duplicate primary key detected " + pkey.toString() );
			throw cflib::CFLibPrimaryKeyNotNewException( CLASS_NAME, S_ProcName, Msg );
		}

		auto searchDictByISOCodeIdx = dictByISOCodeIdx->find( keyISOCodeIdx );
		if( searchDictByISOCodeIdx != dictByISOCodeIdx->end() ) {
			std::string Msg( "Duplicate key detected for index ISOCtryCodeIdx " + keyISOCodeIdx.toString() );
			delete Buff;
			throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
				S_ProcName,
				Msg );
		}

		auto searchDictByNameIdx = dictByNameIdx->find( keyNameIdx );
		if( searchDictByNameIdx != dictByNameIdx->end() ) {
			std::string Msg( "Duplicate key detected for index ISOCtryNameIdx " + keyNameIdx.toString() );
			delete Buff;
			throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
				S_ProcName,
				Msg );
		}

		// Validate foreign keys

		// Proceed with adding the new record
		cfsec::CFSecISOCtryBuff* buff = Buff;
		buff->setRequiredRevision( 1 );
		dictByPKey->insert( std::map<cfsec::CFSecISOCtryPKey, cfsec::CFSecISOCtryBuff*>::value_type( pkey, buff ) );

		dictByISOCodeIdx->insert( std::map<cfsec::CFSecISOCtryByISOCodeIdxKey, cfsec::CFSecISOCtryBuff*>::value_type( keyISOCodeIdx, buff ) );

		dictByNameIdx->insert( std::map<cfsec::CFSecISOCtryByNameIdxKey, cfsec::CFSecISOCtryBuff*>::value_type( keyNameIdx, buff ) );

		// The top level code has to clone the final buffer. The one passed in is now part of the persistent storage.
		if( buff->getClassCode() == cfsec::CFSecISOCtryBuff::CLASS_CODE ) {
			buff = dynamic_cast<cfsec::CFSecISOCtryBuff*>( buff->clone() );
		}
		return( buff );
	}

	cfsec::CFSecISOCtryBuff* CFSecRamISOCtryTable::readDerived( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecISOCtryPKey* PKey )
	{
		static const std::string S_ProcName( "readDerived" );
		cfsec::CFSecISOCtryBuff* buff;
		auto searchDictByPKey = dictByPKey->find( *PKey );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfsec::CFSecISOCtryBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecISOCtryBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfsec::CFSecISOCtryBuff* CFSecRamISOCtryTable::lockDerived( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecISOCtryPKey* PKey )
	{
		static const std::string S_ProcName( "lockDerived" );
		cfsec::CFSecISOCtryBuff* buff;
		auto searchDictByPKey = dictByPKey->find( *PKey );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfsec::CFSecISOCtryBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecISOCtryBuff*>( buff->clone() );
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

	std::TCFLibOwningVector<cfsec::CFSecISOCtryBuff*> CFSecRamISOCtryTable::readAllDerived( const cfsec::CFSecAuthorization* Authorization ) {
		static const std::string S_ProcName( "readAllDerived" );
		std::TCFLibOwningVector<cfsec::CFSecISOCtryBuff*> retVec;
		std::map<cfsec::CFSecISOCtryPKey,
			cfsec::CFSecISOCtryBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecISOCtryPKey,
			cfsec::CFSecISOCtryBuff*>::iterator end = dictByPKey->end();
		cfsec::CFSecISOCtryBuff* clone;
		while( iter != end ) {
			clone = dynamic_cast<cfsec::CFSecISOCtryBuff*>( iter->second->clone() );
			retVec.push_back( clone );
			iter ++;
		}
		return( retVec );
	}

	cfsec::CFSecISOCtryBuff* CFSecRamISOCtryTable::readDerivedByISOCodeIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& ISOCode )
	{
		static const std::string S_ProcName( "readDerivedByISOCodeIdx" );
		cfsec::CFSecISOCtryByISOCodeIdxKey key;
		key.setRequiredISOCode( ISOCode );
		cfsec::CFSecISOCtryBuff* buff;
		auto searchDictByISOCodeIdx = dictByISOCodeIdx->find( key );
		if( searchDictByISOCodeIdx != dictByISOCodeIdx->end() ) {
			buff = dynamic_cast<cfsec::CFSecISOCtryBuff*>( searchDictByISOCodeIdx->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecISOCtryBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfsec::CFSecISOCtryBuff* CFSecRamISOCtryTable::readDerivedByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& Name )
	{
		static const std::string S_ProcName( "readDerivedByNameIdx" );
		cfsec::CFSecISOCtryByNameIdxKey key;
		key.setRequiredName( Name );
		cfsec::CFSecISOCtryBuff* buff;
		auto searchDictByNameIdx = dictByNameIdx->find( key );
		if( searchDictByNameIdx != dictByNameIdx->end() ) {
			buff = dynamic_cast<cfsec::CFSecISOCtryBuff*>( searchDictByNameIdx->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecISOCtryBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfsec::CFSecISOCtryBuff* CFSecRamISOCtryTable::readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t ISOCtryId )
	{
		static const std::string S_ProcName( "readDerivedByIdIdx" );
		cfsec::CFSecISOCtryPKey key;
		key.setRequiredISOCtryId( ISOCtryId );
		cfsec::CFSecISOCtryBuff* buff;
		auto searchDictByPKey = dictByPKey->find( key );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfsec::CFSecISOCtryBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecISOCtryBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfsec::CFSecISOCtryBuff* CFSecRamISOCtryTable::readBuff( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecISOCtryPKey* PKey )
	{
		static const std::string S_ProcName( "readBuff" );
		cfsec::CFSecISOCtryBuff* buff = readDerived( Authorization, PKey );
		if( buff != NULL ) {
			if( buff->getClassCode() != cfsec::CFSecISOCtryBuff::CLASS_CODE ) {
				delete buff;
				buff = NULL;
			}
		}
		return( dynamic_cast<cfsec::CFSecISOCtryBuff*>( buff ) );
	}

	cfsec::CFSecISOCtryBuff* CFSecRamISOCtryTable::lockBuff( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecISOCtryPKey* PKey )
	{
		static const std::string S_ProcName( "lockBuff" );
		cfsec::CFSecISOCtryBuff* buff = lockDerived( Authorization, PKey );
		return( dynamic_cast<cfsec::CFSecISOCtryBuff*>( buff ) );
	}

	std::TCFLibOwningVector<cfsec::CFSecISOCtryBuff*> CFSecRamISOCtryTable::readAllBuff( const cfsec::CFSecAuthorization* Authorization )
	{
		static const std::string S_ProcName( "readAllBuff" );
		cfsec::CFSecISOCtryBuff* buff;
		std::TCFLibOwningVector<cfsec::CFSecISOCtryBuff*> filteredList;
		std::TCFLibOwningVector<cfsec::CFSecISOCtryBuff*> buffList = readAllDerived( Authorization );
		std::TCFLibOwningVector<cfsec::CFSecISOCtryBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfsec::CFSecISOCtryBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfsec::CFSecISOCtryBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfsec::CFSecISOCtryBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	cfsec::CFSecISOCtryBuff* CFSecRamISOCtryTable::readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t ISOCtryId )
	{
		static const std::string S_ProcName( "readBuffByIdIdx" );
		cfsec::CFSecISOCtryBuff* buff = readDerivedByIdIdx( Authorization,
			ISOCtryId );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfsec::CFSecISOCtryBuff::CLASS_CODE ) {
			return( dynamic_cast<cfsec::CFSecISOCtryBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	cfsec::CFSecISOCtryBuff* CFSecRamISOCtryTable::readBuffByISOCodeIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& ISOCode )
	{
		static const std::string S_ProcName( "readBuffByISOCodeIdx" );
		cfsec::CFSecISOCtryBuff* buff = readDerivedByISOCodeIdx( Authorization,
			ISOCode );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfsec::CFSecISOCtryBuff::CLASS_CODE ) {
			return( dynamic_cast<cfsec::CFSecISOCtryBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	cfsec::CFSecISOCtryBuff* CFSecRamISOCtryTable::readBuffByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& Name )
	{
		static const std::string S_ProcName( "readBuffByNameIdx" );
		cfsec::CFSecISOCtryBuff* buff = readDerivedByNameIdx( Authorization,
			Name );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfsec::CFSecISOCtryBuff::CLASS_CODE ) {
			return( dynamic_cast<cfsec::CFSecISOCtryBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	cfsec::CFSecISOCtryBuff* CFSecRamISOCtryTable::readBuffByLookupISOCodeIdx( const cfsec::CFSecAuthorization* Authorization, const std::string& ISOCode,
		bool forceRead )
	{
		static const std::string S_ProcName( "readBuffByLookupISOCodeIdx" );
		cfsec::CFSecISOCtryBuff* buff = readBuffByISOCodeIdx( Authorization,
			ISOCode );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfsec::CFSecISOCtryBuff::CLASS_CODE ) {
			return( dynamic_cast<cfsec::CFSecISOCtryBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	cfsec::CFSecISOCtryBuff* CFSecRamISOCtryTable::readDerivedByLookupISOCodeIdx( const cfsec::CFSecAuthorization* Authorization, const std::string& ISOCode,
		bool forceRead )
	{
		static const std::string S_ProcName( "readDerivedByLookupISOCodeIdx" );
		cfsec::CFSecISOCtryBuff* buff = readDerivedByISOCodeIdx( Authorization,
			ISOCode );
		if( buff != NULL ) {
			return( dynamic_cast<cfsec::CFSecISOCtryBuff*>( buff->clone() ) );
		}
		else {
			return( NULL );
		}
	}

	cfsec::CFSecISOCtryBuff* CFSecRamISOCtryTable::updateISOCtry( const cfsec::CFSecAuthorization* Authorization,
		cfsec::CFSecISOCtryBuff* Buff )
	{
		static const std::string S_ProcName( "updateISOCtry" );
		cfsec::CFSecISOCtryPKey pkey;
		pkey.setRequiredISOCtryId( Buff->getRequiredISOCtryId() );

		// Search for existing buffer

		auto searchExisting = dictByPKey->find( pkey );
		if( searchExisting == dictByPKey->end() ) {
			delete Buff;
			std::string Msg( "Existing record not found in ISOCtry for key " + pkey.toString() );
			throw cflib::CFLibStaleCacheDetectedException( CLASS_NAME,
				S_ProcName,
				Msg );
		}

		cfsec::CFSecISOCtryBuff* existing = searchExisting->second;

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
			std::string Msg( "Collision detected for ISOCtry primary key " );
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
		cfsec::CFSecISOCtryByISOCodeIdxKey existingKeyISOCodeIdx;
		existingKeyISOCodeIdx.setRequiredISOCode( existing->getRequiredISOCode() );
		cfsec::CFSecISOCtryByISOCodeIdxKey newKeyISOCodeIdx;
		newKeyISOCodeIdx.setRequiredISOCode( Buff->getRequiredISOCode() );
		cfsec::CFSecISOCtryByNameIdxKey existingKeyNameIdx;
		existingKeyNameIdx.setRequiredName( existing->getRequiredName() );
		cfsec::CFSecISOCtryByNameIdxKey newKeyNameIdx;
		newKeyNameIdx.setRequiredName( Buff->getRequiredName() );
		// Check unique indexes

		if( existingKeyISOCodeIdx != newKeyISOCodeIdx ) {
			auto searchDictByISOCodeIdx = dictByISOCodeIdx->find( newKeyISOCodeIdx );
			if( searchDictByISOCodeIdx != dictByISOCodeIdx->end() ) {
				std::string Msg( "Duplicate key detected for index ISOCtryCodeIdx " + newKeyISOCodeIdx.toString() );
				delete Buff;
				throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
					S_ProcName,
					Msg );
			}
		}

		if( existingKeyNameIdx != newKeyNameIdx ) {
			auto searchDictByNameIdx = dictByNameIdx->find( newKeyNameIdx );
			if( searchDictByNameIdx != dictByNameIdx->end() ) {
				std::string Msg( "Duplicate key detected for index ISOCtryNameIdx " + newKeyNameIdx.toString() );
				delete Buff;
				throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
					S_ProcName,
					Msg );
			}
		}

		// Validate foreign keys

		// Update is valid
		std::map<cfsec::CFSecISOCtryPKey, cfsec::CFSecISOCtryBuff*>* subdict;
		auto removalDictByPKey = dictByPKey->find( pkey );
		if( removalDictByPKey != dictByPKey->end() ) {
			dictByPKey->erase( removalDictByPKey );
		}
		// Copy edited buffer to existing persistent buffer

		if( Buff->getClassCode() != cfsec::CFSecISOCtryBuff::CLASS_CODE ) {
			const static std::string S_IsNotA( " is not a cfsec::CFSecISOCtryBuff" );
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

		dictByPKey->insert( std::map<cfsec::CFSecISOCtryPKey, cfsec::CFSecISOCtryBuff*>::value_type( pkey, existing ) );

		auto removalDictByISOCodeIdx = dictByISOCodeIdx->find( existingKeyISOCodeIdx );
		if( removalDictByISOCodeIdx != dictByISOCodeIdx->end() ) {
			dictByISOCodeIdx->erase( removalDictByISOCodeIdx );
		}
		dictByISOCodeIdx->insert( std::map<cfsec::CFSecISOCtryByISOCodeIdxKey, cfsec::CFSecISOCtryBuff*>::value_type( newKeyISOCodeIdx, existing ) );

		auto removalDictByNameIdx = dictByNameIdx->find( existingKeyNameIdx );
		if( removalDictByNameIdx != dictByNameIdx->end() ) {
			dictByNameIdx->erase( removalDictByNameIdx );
		}
		dictByNameIdx->insert( std::map<cfsec::CFSecISOCtryByNameIdxKey, cfsec::CFSecISOCtryBuff*>::value_type( newKeyNameIdx, existing ) );


		// The top level code has to clean up the memory buffer that was passed in, and return a clone
		// of the copy that existing buffer that is attached to the RAM storage.  All other cases
		// return the existing buffer.

		cfsec::CFSecISOCtryBuff* buff;
		if( existing->getClassCode() == cfsec::CFSecISOCtryBuff::CLASS_CODE ) {
			delete Buff;
			Buff = NULL;
			buff = dynamic_cast<cfsec::CFSecISOCtryBuff*>( existing->clone() );
		}
		else {
			buff = existing;
		}
		return( buff );
	}

	void CFSecRamISOCtryTable::deleteISOCtry( const cfsec::CFSecAuthorization* Authorization,
		cfsec::CFSecISOCtryBuff* Buff )
	{
		static const std::string S_ProcName( "deleteISOCtry" );
		static const std::string S_Prev( "prev" );
		classcode_t classCode;
		cfsec::CFSecISOCtryPKey pkey;
		pkey.setRequiredISOCtryId( Buff->getRequiredISOCtryId() );
		auto searchExisting = dictByPKey->find( pkey );
		if( searchExisting == dictByPKey->end() ) {
			return;
		}
		cfsec::CFSecISOCtryBuff* existing = searchExisting->second;
		schema->getTableISOCtryLang()->deleteISOCtryLangByCtryIdx( Authorization,
			existing->getRequiredISOCtryId() );
		schema->getTableISOCtryCcy()->deleteISOCtryCcyByCtryIdx( Authorization,
			existing->getRequiredISOCtryId() );
		cfsec::CFSecISOCtryByISOCodeIdxKey keyISOCodeIdx;
		keyISOCodeIdx.setRequiredISOCode( existing->getRequiredISOCode() );
		cfsec::CFSecISOCtryByNameIdxKey keyNameIdx;
		keyNameIdx.setRequiredName( existing->getRequiredName() );
		// Validate reverse foreign keys

		// Delete is valid
		std::map<cfsec::CFSecISOCtryPKey, cfsec::CFSecISOCtryBuff*>* subdict;

		auto searchDictByPKey = dictByPKey->find( pkey );
		if( searchDictByPKey != dictByPKey->end() ) {
			dictByPKey->erase( searchDictByPKey );
		}

		auto searchDictByISOCodeIdx = dictByISOCodeIdx->find( keyISOCodeIdx );
		if( searchDictByISOCodeIdx != dictByISOCodeIdx->end() ) {
			dictByISOCodeIdx->erase( searchDictByISOCodeIdx );
		}

		auto searchDictByNameIdx = dictByNameIdx->find( keyNameIdx );
		if( searchDictByNameIdx != dictByNameIdx->end() ) {
			dictByNameIdx->erase( searchDictByNameIdx );
		}

		if( existing != NULL ) {
			delete existing;
			existing = NULL;
		}
	}

	void CFSecRamISOCtryTable::deleteISOCtryByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t argISOCtryId )
	{
		cfsec::CFSecISOCtryPKey key;
		key.setRequiredISOCtryId( argISOCtryId );
		deleteISOCtryByIdIdx( Authorization, &key );
	}

	void CFSecRamISOCtryTable::deleteISOCtryByIdIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecISOCtryPKey* argKey )
	{
		bool anyNotNull = false;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		cfsec::CFSecISOCtryBuff* cur = NULL;
		cfsec::CFSecISOCtryBuff* rereadCur = NULL;
		std::TCFLibOwningVector<cfsec::CFSecISOCtryBuff*> matchSet;
		std::map<cfsec::CFSecISOCtryPKey,
			cfsec::CFSecISOCtryBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecISOCtryPKey,
			cfsec::CFSecISOCtryBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecISOCtryBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecISOCtryBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecISOCtryBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecISOCtryBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableISOCtry()->readDerivedByIdIdx( Authorization,
				cur->getRequiredISOCtryId() );
			rereadCur = cur;
			deleteISOCtry( Authorization, cur );
			if( rereadCur != NULL ) {
				delete rereadCur;
				rereadCur = NULL;
			}
		}
	}

	void CFSecRamISOCtryTable::deleteISOCtryByISOCodeIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& argISOCode )
	{
		cfsec::CFSecISOCtryByISOCodeIdxKey key;
		key.setRequiredISOCode( argISOCode );
		deleteISOCtryByISOCodeIdx( Authorization, &key );
	}

	void CFSecRamISOCtryTable::deleteISOCtryByISOCodeIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecISOCtryByISOCodeIdxKey* argKey )
	{
		cfsec::CFSecISOCtryBuff* cur = NULL;
		cfsec::CFSecISOCtryBuff* rereadCur = NULL;
		bool anyNotNull = false;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfsec::CFSecISOCtryBuff*> matchSet;
		std::map<cfsec::CFSecISOCtryPKey,
			cfsec::CFSecISOCtryBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecISOCtryPKey,
			cfsec::CFSecISOCtryBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecISOCtryBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecISOCtryBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecISOCtryBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecISOCtryBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableISOCtry()->readDerivedByIdIdx( Authorization,
				cur->getRequiredISOCtryId() );
			rereadCur = cur;
			deleteISOCtry( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFSecRamISOCtryTable::deleteISOCtryByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& argName )
	{
		cfsec::CFSecISOCtryByNameIdxKey key;
		key.setRequiredName( argName );
		deleteISOCtryByNameIdx( Authorization, &key );
	}

	void CFSecRamISOCtryTable::deleteISOCtryByNameIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecISOCtryByNameIdxKey* argKey )
	{
		cfsec::CFSecISOCtryBuff* cur = NULL;
		cfsec::CFSecISOCtryBuff* rereadCur = NULL;
		bool anyNotNull = false;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfsec::CFSecISOCtryBuff*> matchSet;
		std::map<cfsec::CFSecISOCtryPKey,
			cfsec::CFSecISOCtryBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecISOCtryPKey,
			cfsec::CFSecISOCtryBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecISOCtryBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecISOCtryBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecISOCtryBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecISOCtryBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableISOCtry()->readDerivedByIdIdx( Authorization,
				cur->getRequiredISOCtryId() );
			rereadCur = cur;
			deleteISOCtry( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFSecRamISOCtryTable::releasePreparedStatements() {
	}

}
