
// Description: C++18 Implementation for an in-memory RAM DbIO for ISOCcy.

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

	const std::string CFSecRamISOCcyTable::CLASS_NAME( "CFSecRamISOCcyTable" );

	CFSecRamISOCcyTable::CFSecRamISOCcyTable( ICFSecSchema* argSchema )
	: cfsec::ICFSecISOCcyTable()
	{
		schema = argSchema;
		dictByPKey = new std::map<cfsec::CFSecISOCcyPKey, cfsec::CFSecISOCcyBuff*>();
		dictByCcyCdIdx = new std::map<cfsec::CFSecISOCcyByCcyCdIdxKey, cfsec::CFSecISOCcyBuff*>();
		dictByCcyNmIdx = new std::map<cfsec::CFSecISOCcyByCcyNmIdxKey, cfsec::CFSecISOCcyBuff*>();
	}

	CFSecRamISOCcyTable::~CFSecRamISOCcyTable() {
		if( dictByCcyCdIdx != NULL ) {
			delete dictByCcyCdIdx;
			dictByCcyCdIdx = NULL;
		}
		if( dictByCcyNmIdx != NULL ) {
			delete dictByCcyNmIdx;
			dictByCcyNmIdx = NULL;
		}
		if( dictByPKey != NULL ) {
			cfsec::CFSecISOCcyBuff* elt;
			std::map<cfsec::CFSecISOCcyPKey,
				cfsec::CFSecISOCcyBuff*>::iterator end = dictByPKey->end();
			for( std::map<cfsec::CFSecISOCcyPKey,
					cfsec::CFSecISOCcyBuff*>::iterator cur = dictByPKey->begin();
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

	cfsec::CFSecISOCcyBuff* CFSecRamISOCcyTable::createISOCcy( const cfsec::CFSecAuthorization* Authorization,
		cfsec::CFSecISOCcyBuff* Buff )
	{
		static const std::string S_ProcName( "createISOCcy" );
		cfsec::CFSecISOCcyPKey pkey;
		pkey.setRequiredISOCcyId( schema->nextISOCcyIdGen() );
		Buff->setRequiredISOCcyId( pkey.getRequiredISOCcyId() );
		cfsec::CFSecISOCcyByCcyCdIdxKey keyCcyCdIdx;
		keyCcyCdIdx.setRequiredISOCode( Buff->getRequiredISOCode() );
		cfsec::CFSecISOCcyByCcyNmIdxKey keyCcyNmIdx;
		keyCcyNmIdx.setRequiredName( Buff->getRequiredName() );
		// Validate unique indexes
		auto searchDictByPKey = dictByPKey->find( pkey );
		if( searchDictByPKey != dictByPKey->end() ) {
			delete Buff;
			std::string Msg( "Duplicate primary key detected " + pkey.toString() );
			throw cflib::CFLibPrimaryKeyNotNewException( CLASS_NAME, S_ProcName, Msg );
		}

		auto searchDictByCcyCdIdx = dictByCcyCdIdx->find( keyCcyCdIdx );
		if( searchDictByCcyCdIdx != dictByCcyCdIdx->end() ) {
			std::string Msg( "Duplicate key detected for index ISOCcyCodeIdx " + keyCcyCdIdx.toString() );
			delete Buff;
			throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
				S_ProcName,
				Msg );
		}

		auto searchDictByCcyNmIdx = dictByCcyNmIdx->find( keyCcyNmIdx );
		if( searchDictByCcyNmIdx != dictByCcyNmIdx->end() ) {
			std::string Msg( "Duplicate key detected for index ISOCcyNameIdx " + keyCcyNmIdx.toString() );
			delete Buff;
			throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
				S_ProcName,
				Msg );
		}

		// Validate foreign keys

		// Proceed with adding the new record
		cfsec::CFSecISOCcyBuff* buff = Buff;
		buff->setRequiredRevision( 1 );
		dictByPKey->insert( std::map<cfsec::CFSecISOCcyPKey, cfsec::CFSecISOCcyBuff*>::value_type( pkey, buff ) );

		dictByCcyCdIdx->insert( std::map<cfsec::CFSecISOCcyByCcyCdIdxKey, cfsec::CFSecISOCcyBuff*>::value_type( keyCcyCdIdx, buff ) );

		dictByCcyNmIdx->insert( std::map<cfsec::CFSecISOCcyByCcyNmIdxKey, cfsec::CFSecISOCcyBuff*>::value_type( keyCcyNmIdx, buff ) );

		// The top level code has to clone the final buffer. The one passed in is now part of the persistent storage.
		if( buff->getClassCode() == cfsec::CFSecISOCcyBuff::CLASS_CODE ) {
			buff = dynamic_cast<cfsec::CFSecISOCcyBuff*>( buff->clone() );
		}
		return( buff );
	}

	cfsec::CFSecISOCcyBuff* CFSecRamISOCcyTable::readDerived( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecISOCcyPKey* PKey )
	{
		static const std::string S_ProcName( "readDerived" );
		cfsec::CFSecISOCcyBuff* buff;
		auto searchDictByPKey = dictByPKey->find( *PKey );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfsec::CFSecISOCcyBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecISOCcyBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfsec::CFSecISOCcyBuff* CFSecRamISOCcyTable::lockDerived( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecISOCcyPKey* PKey )
	{
		static const std::string S_ProcName( "lockDerived" );
		cfsec::CFSecISOCcyBuff* buff;
		auto searchDictByPKey = dictByPKey->find( *PKey );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfsec::CFSecISOCcyBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecISOCcyBuff*>( buff->clone() );
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

	std::TCFLibOwningVector<cfsec::CFSecISOCcyBuff*> CFSecRamISOCcyTable::readAllDerived( const cfsec::CFSecAuthorization* Authorization ) {
		static const std::string S_ProcName( "readAllDerived" );
		std::TCFLibOwningVector<cfsec::CFSecISOCcyBuff*> retVec;
		std::map<cfsec::CFSecISOCcyPKey,
			cfsec::CFSecISOCcyBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecISOCcyPKey,
			cfsec::CFSecISOCcyBuff*>::iterator end = dictByPKey->end();
		cfsec::CFSecISOCcyBuff* clone;
		while( iter != end ) {
			clone = dynamic_cast<cfsec::CFSecISOCcyBuff*>( iter->second->clone() );
			retVec.push_back( clone );
			iter ++;
		}
		return( retVec );
	}

	cfsec::CFSecISOCcyBuff* CFSecRamISOCcyTable::readDerivedByCcyCdIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& ISOCode )
	{
		static const std::string S_ProcName( "readDerivedByCcyCdIdx" );
		cfsec::CFSecISOCcyByCcyCdIdxKey key;
		key.setRequiredISOCode( ISOCode );
		cfsec::CFSecISOCcyBuff* buff;
		auto searchDictByCcyCdIdx = dictByCcyCdIdx->find( key );
		if( searchDictByCcyCdIdx != dictByCcyCdIdx->end() ) {
			buff = dynamic_cast<cfsec::CFSecISOCcyBuff*>( searchDictByCcyCdIdx->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecISOCcyBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfsec::CFSecISOCcyBuff* CFSecRamISOCcyTable::readDerivedByCcyNmIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& Name )
	{
		static const std::string S_ProcName( "readDerivedByCcyNmIdx" );
		cfsec::CFSecISOCcyByCcyNmIdxKey key;
		key.setRequiredName( Name );
		cfsec::CFSecISOCcyBuff* buff;
		auto searchDictByCcyNmIdx = dictByCcyNmIdx->find( key );
		if( searchDictByCcyNmIdx != dictByCcyNmIdx->end() ) {
			buff = dynamic_cast<cfsec::CFSecISOCcyBuff*>( searchDictByCcyNmIdx->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecISOCcyBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfsec::CFSecISOCcyBuff* CFSecRamISOCcyTable::readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t ISOCcyId )
	{
		static const std::string S_ProcName( "readDerivedByIdIdx" );
		cfsec::CFSecISOCcyPKey key;
		key.setRequiredISOCcyId( ISOCcyId );
		cfsec::CFSecISOCcyBuff* buff;
		auto searchDictByPKey = dictByPKey->find( key );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfsec::CFSecISOCcyBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecISOCcyBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfsec::CFSecISOCcyBuff* CFSecRamISOCcyTable::readBuff( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecISOCcyPKey* PKey )
	{
		static const std::string S_ProcName( "readBuff" );
		cfsec::CFSecISOCcyBuff* buff = readDerived( Authorization, PKey );
		if( buff != NULL ) {
			if( buff->getClassCode() != cfsec::CFSecISOCcyBuff::CLASS_CODE ) {
				delete buff;
				buff = NULL;
			}
		}
		return( dynamic_cast<cfsec::CFSecISOCcyBuff*>( buff ) );
	}

	cfsec::CFSecISOCcyBuff* CFSecRamISOCcyTable::lockBuff( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecISOCcyPKey* PKey )
	{
		static const std::string S_ProcName( "lockBuff" );
		cfsec::CFSecISOCcyBuff* buff = lockDerived( Authorization, PKey );
		return( dynamic_cast<cfsec::CFSecISOCcyBuff*>( buff ) );
	}

	std::TCFLibOwningVector<cfsec::CFSecISOCcyBuff*> CFSecRamISOCcyTable::readAllBuff( const cfsec::CFSecAuthorization* Authorization )
	{
		static const std::string S_ProcName( "readAllBuff" );
		cfsec::CFSecISOCcyBuff* buff;
		std::TCFLibOwningVector<cfsec::CFSecISOCcyBuff*> filteredList;
		std::TCFLibOwningVector<cfsec::CFSecISOCcyBuff*> buffList = readAllDerived( Authorization );
		std::TCFLibOwningVector<cfsec::CFSecISOCcyBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfsec::CFSecISOCcyBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfsec::CFSecISOCcyBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfsec::CFSecISOCcyBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	cfsec::CFSecISOCcyBuff* CFSecRamISOCcyTable::readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t ISOCcyId )
	{
		static const std::string S_ProcName( "readBuffByIdIdx" );
		cfsec::CFSecISOCcyBuff* buff = readDerivedByIdIdx( Authorization,
			ISOCcyId );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfsec::CFSecISOCcyBuff::CLASS_CODE ) {
			return( dynamic_cast<cfsec::CFSecISOCcyBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	cfsec::CFSecISOCcyBuff* CFSecRamISOCcyTable::readBuffByCcyCdIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& ISOCode )
	{
		static const std::string S_ProcName( "readBuffByCcyCdIdx" );
		cfsec::CFSecISOCcyBuff* buff = readDerivedByCcyCdIdx( Authorization,
			ISOCode );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfsec::CFSecISOCcyBuff::CLASS_CODE ) {
			return( dynamic_cast<cfsec::CFSecISOCcyBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	cfsec::CFSecISOCcyBuff* CFSecRamISOCcyTable::readBuffByCcyNmIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& Name )
	{
		static const std::string S_ProcName( "readBuffByCcyNmIdx" );
		cfsec::CFSecISOCcyBuff* buff = readDerivedByCcyNmIdx( Authorization,
			Name );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfsec::CFSecISOCcyBuff::CLASS_CODE ) {
			return( dynamic_cast<cfsec::CFSecISOCcyBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	cfsec::CFSecISOCcyBuff* CFSecRamISOCcyTable::readBuffByLookupCcyCdIdx( const cfsec::CFSecAuthorization* Authorization, const std::string& ISOCode,
		bool forceRead )
	{
		static const std::string S_ProcName( "readBuffByLookupCcyCdIdx" );
		cfsec::CFSecISOCcyBuff* buff = readBuffByCcyCdIdx( Authorization,
			ISOCode );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfsec::CFSecISOCcyBuff::CLASS_CODE ) {
			return( dynamic_cast<cfsec::CFSecISOCcyBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	cfsec::CFSecISOCcyBuff* CFSecRamISOCcyTable::readDerivedByLookupCcyCdIdx( const cfsec::CFSecAuthorization* Authorization, const std::string& ISOCode,
		bool forceRead )
	{
		static const std::string S_ProcName( "readDerivedByLookupCcyCdIdx" );
		cfsec::CFSecISOCcyBuff* buff = readDerivedByCcyCdIdx( Authorization,
			ISOCode );
		if( buff != NULL ) {
			return( dynamic_cast<cfsec::CFSecISOCcyBuff*>( buff->clone() ) );
		}
		else {
			return( NULL );
		}
	}

	cfsec::CFSecISOCcyBuff* CFSecRamISOCcyTable::updateISOCcy( const cfsec::CFSecAuthorization* Authorization,
		cfsec::CFSecISOCcyBuff* Buff )
	{
		static const std::string S_ProcName( "updateISOCcy" );
		cfsec::CFSecISOCcyPKey pkey;
		pkey.setRequiredISOCcyId( Buff->getRequiredISOCcyId() );

		// Search for existing buffer

		auto searchExisting = dictByPKey->find( pkey );
		if( searchExisting == dictByPKey->end() ) {
			delete Buff;
			std::string Msg( "Existing record not found in ISOCcy for key " + pkey.toString() );
			throw cflib::CFLibStaleCacheDetectedException( CLASS_NAME,
				S_ProcName,
				Msg );
		}

		cfsec::CFSecISOCcyBuff* existing = searchExisting->second;

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
			std::string Msg( "Collision detected for ISOCcy primary key " );
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
		cfsec::CFSecISOCcyByCcyCdIdxKey existingKeyCcyCdIdx;
		existingKeyCcyCdIdx.setRequiredISOCode( existing->getRequiredISOCode() );
		cfsec::CFSecISOCcyByCcyCdIdxKey newKeyCcyCdIdx;
		newKeyCcyCdIdx.setRequiredISOCode( Buff->getRequiredISOCode() );
		cfsec::CFSecISOCcyByCcyNmIdxKey existingKeyCcyNmIdx;
		existingKeyCcyNmIdx.setRequiredName( existing->getRequiredName() );
		cfsec::CFSecISOCcyByCcyNmIdxKey newKeyCcyNmIdx;
		newKeyCcyNmIdx.setRequiredName( Buff->getRequiredName() );
		// Check unique indexes

		if( existingKeyCcyCdIdx != newKeyCcyCdIdx ) {
			auto searchDictByCcyCdIdx = dictByCcyCdIdx->find( newKeyCcyCdIdx );
			if( searchDictByCcyCdIdx != dictByCcyCdIdx->end() ) {
				std::string Msg( "Duplicate key detected for index ISOCcyCodeIdx " + newKeyCcyCdIdx.toString() );
				delete Buff;
				throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
					S_ProcName,
					Msg );
			}
		}

		if( existingKeyCcyNmIdx != newKeyCcyNmIdx ) {
			auto searchDictByCcyNmIdx = dictByCcyNmIdx->find( newKeyCcyNmIdx );
			if( searchDictByCcyNmIdx != dictByCcyNmIdx->end() ) {
				std::string Msg( "Duplicate key detected for index ISOCcyNameIdx " + newKeyCcyNmIdx.toString() );
				delete Buff;
				throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
					S_ProcName,
					Msg );
			}
		}

		// Validate foreign keys

		// Update is valid
		std::map<cfsec::CFSecISOCcyPKey, cfsec::CFSecISOCcyBuff*>* subdict;
		auto removalDictByPKey = dictByPKey->find( pkey );
		if( removalDictByPKey != dictByPKey->end() ) {
			dictByPKey->erase( removalDictByPKey );
		}
		// Copy edited buffer to existing persistent buffer

		if( Buff->getClassCode() != cfsec::CFSecISOCcyBuff::CLASS_CODE ) {
			const static std::string S_IsNotA( " is not a cfsec::CFSecISOCcyBuff" );
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

		dictByPKey->insert( std::map<cfsec::CFSecISOCcyPKey, cfsec::CFSecISOCcyBuff*>::value_type( pkey, existing ) );

		auto removalDictByCcyCdIdx = dictByCcyCdIdx->find( existingKeyCcyCdIdx );
		if( removalDictByCcyCdIdx != dictByCcyCdIdx->end() ) {
			dictByCcyCdIdx->erase( removalDictByCcyCdIdx );
		}
		dictByCcyCdIdx->insert( std::map<cfsec::CFSecISOCcyByCcyCdIdxKey, cfsec::CFSecISOCcyBuff*>::value_type( newKeyCcyCdIdx, existing ) );

		auto removalDictByCcyNmIdx = dictByCcyNmIdx->find( existingKeyCcyNmIdx );
		if( removalDictByCcyNmIdx != dictByCcyNmIdx->end() ) {
			dictByCcyNmIdx->erase( removalDictByCcyNmIdx );
		}
		dictByCcyNmIdx->insert( std::map<cfsec::CFSecISOCcyByCcyNmIdxKey, cfsec::CFSecISOCcyBuff*>::value_type( newKeyCcyNmIdx, existing ) );


		// The top level code has to clean up the memory buffer that was passed in, and return a clone
		// of the copy that existing buffer that is attached to the RAM storage.  All other cases
		// return the existing buffer.

		cfsec::CFSecISOCcyBuff* buff;
		if( existing->getClassCode() == cfsec::CFSecISOCcyBuff::CLASS_CODE ) {
			delete Buff;
			Buff = NULL;
			buff = dynamic_cast<cfsec::CFSecISOCcyBuff*>( existing->clone() );
		}
		else {
			buff = existing;
		}
		return( buff );
	}

	void CFSecRamISOCcyTable::deleteISOCcy( const cfsec::CFSecAuthorization* Authorization,
		cfsec::CFSecISOCcyBuff* Buff )
	{
		static const std::string S_ProcName( "deleteISOCcy" );
		static const std::string S_Prev( "prev" );
		classcode_t classCode;
		cfsec::CFSecISOCcyPKey pkey;
		pkey.setRequiredISOCcyId( Buff->getRequiredISOCcyId() );
		auto searchExisting = dictByPKey->find( pkey );
		if( searchExisting == dictByPKey->end() ) {
			return;
		}
		cfsec::CFSecISOCcyBuff* existing = searchExisting->second;
		std::TCFLibOwningVector<cfsec::CFSecISOCtryCcyBuff*> arrCheckISOCcyCountries = schema->getTableISOCtryCcy()->readDerivedByCcyIdx( Authorization,
			existing->getRequiredISOCcyId() );
		if( arrCheckISOCcyCountries.size() > 0 ) {
			schema->getTableISOCtryCcy()->deleteISOCtryCcyByCcyIdx( Authorization,
			existing->getRequiredISOCcyId() );
		}
		cfsec::CFSecISOCcyByCcyCdIdxKey keyCcyCdIdx;
		keyCcyCdIdx.setRequiredISOCode( existing->getRequiredISOCode() );
		cfsec::CFSecISOCcyByCcyNmIdxKey keyCcyNmIdx;
		keyCcyNmIdx.setRequiredName( existing->getRequiredName() );
		// Validate reverse foreign keys

		// Delete is valid
		std::map<cfsec::CFSecISOCcyPKey, cfsec::CFSecISOCcyBuff*>* subdict;

		auto searchDictByPKey = dictByPKey->find( pkey );
		if( searchDictByPKey != dictByPKey->end() ) {
			dictByPKey->erase( searchDictByPKey );
		}

		auto searchDictByCcyCdIdx = dictByCcyCdIdx->find( keyCcyCdIdx );
		if( searchDictByCcyCdIdx != dictByCcyCdIdx->end() ) {
			dictByCcyCdIdx->erase( searchDictByCcyCdIdx );
		}

		auto searchDictByCcyNmIdx = dictByCcyNmIdx->find( keyCcyNmIdx );
		if( searchDictByCcyNmIdx != dictByCcyNmIdx->end() ) {
			dictByCcyNmIdx->erase( searchDictByCcyNmIdx );
		}

		if( existing != NULL ) {
			delete existing;
			existing = NULL;
		}
	}

	void CFSecRamISOCcyTable::deleteISOCcyByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t argISOCcyId )
	{
		cfsec::CFSecISOCcyPKey key;
		key.setRequiredISOCcyId( argISOCcyId );
		deleteISOCcyByIdIdx( Authorization, &key );
	}

	void CFSecRamISOCcyTable::deleteISOCcyByIdIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecISOCcyPKey* argKey )
	{
		bool anyNotNull = false;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		cfsec::CFSecISOCcyBuff* cur = NULL;
		cfsec::CFSecISOCcyBuff* rereadCur = NULL;
		std::TCFLibOwningVector<cfsec::CFSecISOCcyBuff*> matchSet;
		std::map<cfsec::CFSecISOCcyPKey,
			cfsec::CFSecISOCcyBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecISOCcyPKey,
			cfsec::CFSecISOCcyBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecISOCcyBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecISOCcyBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecISOCcyBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecISOCcyBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableISOCcy()->readDerivedByIdIdx( Authorization,
				cur->getRequiredISOCcyId() );
			rereadCur = cur;
			deleteISOCcy( Authorization, cur );
			if( rereadCur != NULL ) {
				delete rereadCur;
				rereadCur = NULL;
			}
		}
	}

	void CFSecRamISOCcyTable::deleteISOCcyByCcyCdIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& argISOCode )
	{
		cfsec::CFSecISOCcyByCcyCdIdxKey key;
		key.setRequiredISOCode( argISOCode );
		deleteISOCcyByCcyCdIdx( Authorization, &key );
	}

	void CFSecRamISOCcyTable::deleteISOCcyByCcyCdIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecISOCcyByCcyCdIdxKey* argKey )
	{
		cfsec::CFSecISOCcyBuff* cur = NULL;
		cfsec::CFSecISOCcyBuff* rereadCur = NULL;
		bool anyNotNull = false;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfsec::CFSecISOCcyBuff*> matchSet;
		std::map<cfsec::CFSecISOCcyPKey,
			cfsec::CFSecISOCcyBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecISOCcyPKey,
			cfsec::CFSecISOCcyBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecISOCcyBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecISOCcyBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecISOCcyBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecISOCcyBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableISOCcy()->readDerivedByIdIdx( Authorization,
				cur->getRequiredISOCcyId() );
			rereadCur = cur;
			deleteISOCcy( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFSecRamISOCcyTable::deleteISOCcyByCcyNmIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& argName )
	{
		cfsec::CFSecISOCcyByCcyNmIdxKey key;
		key.setRequiredName( argName );
		deleteISOCcyByCcyNmIdx( Authorization, &key );
	}

	void CFSecRamISOCcyTable::deleteISOCcyByCcyNmIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecISOCcyByCcyNmIdxKey* argKey )
	{
		cfsec::CFSecISOCcyBuff* cur = NULL;
		cfsec::CFSecISOCcyBuff* rereadCur = NULL;
		bool anyNotNull = false;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfsec::CFSecISOCcyBuff*> matchSet;
		std::map<cfsec::CFSecISOCcyPKey,
			cfsec::CFSecISOCcyBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecISOCcyPKey,
			cfsec::CFSecISOCcyBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecISOCcyBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecISOCcyBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecISOCcyBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecISOCcyBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableISOCcy()->readDerivedByIdIdx( Authorization,
				cur->getRequiredISOCcyId() );
			rereadCur = cur;
			deleteISOCcy( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFSecRamISOCcyTable::releasePreparedStatements() {
	}

}
