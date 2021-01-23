
// Description: C++18 Implementation for an in-memory RAM DbIO for ISOCtryLang.

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

	const std::string CFSecRamISOCtryLangTable::CLASS_NAME( "CFSecRamISOCtryLangTable" );

	CFSecRamISOCtryLangTable::CFSecRamISOCtryLangTable( ICFSecSchema* argSchema )
	: cfsec::ICFSecISOCtryLangTable()
	{
		schema = argSchema;
		dictByPKey = new std::map<cfsec::CFSecISOCtryLangPKey, cfsec::CFSecISOCtryLangBuff*>();
		dictByCtryIdx = new std::map<cfsec::CFSecISOCtryLangByCtryIdxKey,
			std::map<cfsec::CFSecISOCtryLangPKey,
				cfsec::CFSecISOCtryLangBuff*>*>();
		dictByLangIdx = new std::map<cfsec::CFSecISOCtryLangByLangIdxKey,
			std::map<cfsec::CFSecISOCtryLangPKey,
				cfsec::CFSecISOCtryLangBuff*>*>();
	}

	CFSecRamISOCtryLangTable::~CFSecRamISOCtryLangTable() {
		if( dictByCtryIdx != NULL ) {
			for( auto iterDict = dictByCtryIdx->begin(); iterDict != dictByCtryIdx->end(); iterDict ++ ) {
				delete iterDict->second;
				iterDict->second = NULL;
			}
			delete dictByCtryIdx;
			dictByCtryIdx = NULL;
		}
		if( dictByLangIdx != NULL ) {
			for( auto iterDict = dictByLangIdx->begin(); iterDict != dictByLangIdx->end(); iterDict ++ ) {
				delete iterDict->second;
				iterDict->second = NULL;
			}
			delete dictByLangIdx;
			dictByLangIdx = NULL;
		}
		if( dictByPKey != NULL ) {
			cfsec::CFSecISOCtryLangBuff* elt;
			std::map<cfsec::CFSecISOCtryLangPKey,
				cfsec::CFSecISOCtryLangBuff*>::iterator end = dictByPKey->end();
			for( std::map<cfsec::CFSecISOCtryLangPKey,
					cfsec::CFSecISOCtryLangBuff*>::iterator cur = dictByPKey->begin();
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

	cfsec::CFSecISOCtryLangBuff* CFSecRamISOCtryLangTable::createISOCtryLang( const cfsec::CFSecAuthorization* Authorization,
		cfsec::CFSecISOCtryLangBuff* Buff )
	{
		static const std::string S_ProcName( "createISOCtryLang" );
		cfsec::CFSecISOCtryLangPKey pkey;
		pkey.setRequiredISOCtryId( Buff->getRequiredISOCtryId() );
		pkey.setRequiredISOLangId( Buff->getRequiredISOLangId() );
		Buff->setRequiredISOCtryId( pkey.getRequiredISOCtryId() );
		Buff->setRequiredISOLangId( pkey.getRequiredISOLangId() );
		cfsec::CFSecISOCtryLangByCtryIdxKey keyCtryIdx;
		keyCtryIdx.setRequiredISOCtryId( Buff->getRequiredISOCtryId() );
		cfsec::CFSecISOCtryLangByLangIdxKey keyLangIdx;
		keyLangIdx.setRequiredISOLangId( Buff->getRequiredISOLangId() );
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
				cfsec::CFSecISOCtryBuff* chk = dynamic_cast<cfsec::CFSecISOCtryBuff*>( schema->getTableISOCtry()->readDerivedByIdIdx( Authorization,
						Buff->getRequiredISOCtryId() ) );
				if( chk == NULL ) {
					delete Buff;
					std::string Msg( "Could not resolve Container relationship ISOCtryLangCtry to table ISOCtry" );
					throw cflib::CFLibUnresolvedRelationException( CLASS_NAME,
						S_ProcName,
						Msg );
				}
				delete chk;
				chk = NULL;
			}
		}

		// Proceed with adding the new record
		cfsec::CFSecISOCtryLangBuff* buff = Buff;
		buff->setRequiredRevision( 1 );
		dictByPKey->insert( std::map<cfsec::CFSecISOCtryLangPKey, cfsec::CFSecISOCtryLangBuff*>::value_type( pkey, buff ) );

		std::map<cfsec::CFSecISOCtryLangPKey, cfsec::CFSecISOCtryLangBuff*>* subdictCtryIdx;
		auto searchDictByCtryIdx = dictByCtryIdx->find( keyCtryIdx );
		if( searchDictByCtryIdx != dictByCtryIdx->end() ) {
			subdictCtryIdx = searchDictByCtryIdx->second;
		}
		else {
			subdictCtryIdx = new std::map<cfsec::CFSecISOCtryLangPKey, cfsec::CFSecISOCtryLangBuff*>();
			dictByCtryIdx->insert( std::map<cfsec::CFSecISOCtryLangByCtryIdxKey,
				std::map<cfsec::CFSecISOCtryLangPKey,
					cfsec::CFSecISOCtryLangBuff*>*>::value_type( keyCtryIdx, subdictCtryIdx ) );
		}
		subdictCtryIdx->insert( std::map<cfsec::CFSecISOCtryLangPKey, cfsec::CFSecISOCtryLangBuff*>::value_type( pkey, buff ) );

		std::map<cfsec::CFSecISOCtryLangPKey, cfsec::CFSecISOCtryLangBuff*>* subdictLangIdx;
		auto searchDictByLangIdx = dictByLangIdx->find( keyLangIdx );
		if( searchDictByLangIdx != dictByLangIdx->end() ) {
			subdictLangIdx = searchDictByLangIdx->second;
		}
		else {
			subdictLangIdx = new std::map<cfsec::CFSecISOCtryLangPKey, cfsec::CFSecISOCtryLangBuff*>();
			dictByLangIdx->insert( std::map<cfsec::CFSecISOCtryLangByLangIdxKey,
				std::map<cfsec::CFSecISOCtryLangPKey,
					cfsec::CFSecISOCtryLangBuff*>*>::value_type( keyLangIdx, subdictLangIdx ) );
		}
		subdictLangIdx->insert( std::map<cfsec::CFSecISOCtryLangPKey, cfsec::CFSecISOCtryLangBuff*>::value_type( pkey, buff ) );

		// The top level code has to clone the final buffer. The one passed in is now part of the persistent storage.
		if( buff->getClassCode() == cfsec::CFSecISOCtryLangBuff::CLASS_CODE ) {
			buff = dynamic_cast<cfsec::CFSecISOCtryLangBuff*>( buff->clone() );
		}
		return( buff );
	}

	cfsec::CFSecISOCtryLangBuff* CFSecRamISOCtryLangTable::readDerived( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecISOCtryLangPKey* PKey )
	{
		static const std::string S_ProcName( "readDerived" );
		cfsec::CFSecISOCtryLangBuff* buff;
		auto searchDictByPKey = dictByPKey->find( *PKey );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfsec::CFSecISOCtryLangBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecISOCtryLangBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfsec::CFSecISOCtryLangBuff* CFSecRamISOCtryLangTable::lockDerived( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecISOCtryLangPKey* PKey )
	{
		static const std::string S_ProcName( "lockDerived" );
		cfsec::CFSecISOCtryLangBuff* buff;
		auto searchDictByPKey = dictByPKey->find( *PKey );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfsec::CFSecISOCtryLangBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecISOCtryLangBuff*>( buff->clone() );
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

	std::TCFLibOwningVector<cfsec::CFSecISOCtryLangBuff*> CFSecRamISOCtryLangTable::readAllDerived( const cfsec::CFSecAuthorization* Authorization ) {
		static const std::string S_ProcName( "readAllDerived" );
		std::TCFLibOwningVector<cfsec::CFSecISOCtryLangBuff*> retVec;
		std::map<cfsec::CFSecISOCtryLangPKey,
			cfsec::CFSecISOCtryLangBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecISOCtryLangPKey,
			cfsec::CFSecISOCtryLangBuff*>::iterator end = dictByPKey->end();
		cfsec::CFSecISOCtryLangBuff* clone;
		while( iter != end ) {
			clone = dynamic_cast<cfsec::CFSecISOCtryLangBuff*>( iter->second->clone() );
			retVec.push_back( clone );
			iter ++;
		}
		return( retVec );
	}

	std::TCFLibOwningVector<cfsec::CFSecISOCtryLangBuff*> CFSecRamISOCtryLangTable::readDerivedByCtryIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t ISOCtryId )
	{
		static const std::string S_ProcName( "readDerivedByCtryIdx" );
		cfsec::CFSecISOCtryLangByCtryIdxKey key;
		key.setRequiredISOCtryId( ISOCtryId );
		std::TCFLibOwningVector<cfsec::CFSecISOCtryLangBuff*> recVec;
		cfsec::CFSecISOCtryLangBuff* clone;
		auto searchDictByCtryIdx = dictByCtryIdx->find( key );
		if( searchDictByCtryIdx != dictByCtryIdx->end() ) {
			std::map<cfsec::CFSecISOCtryLangPKey,
				 cfsec::CFSecISOCtryLangBuff*>* subdictCtryIdx = searchDictByCtryIdx->second;
			std::map<cfsec::CFSecISOCtryLangPKey,
				cfsec::CFSecISOCtryLangBuff*>::iterator iter = subdictCtryIdx->begin();
			std::map<cfsec::CFSecISOCtryLangPKey,
				cfsec::CFSecISOCtryLangBuff*>::iterator end = subdictCtryIdx->end();
			while( iter != end ) {
				clone = dynamic_cast<cfsec::CFSecISOCtryLangBuff*>( iter->second->clone() );
				recVec.push_back( clone );
				iter ++;
			}
		}
		return( recVec );
	}

	std::TCFLibOwningVector<cfsec::CFSecISOCtryLangBuff*> CFSecRamISOCtryLangTable::readDerivedByLangIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t ISOLangId )
	{
		static const std::string S_ProcName( "readDerivedByLangIdx" );
		cfsec::CFSecISOCtryLangByLangIdxKey key;
		key.setRequiredISOLangId( ISOLangId );
		std::TCFLibOwningVector<cfsec::CFSecISOCtryLangBuff*> recVec;
		cfsec::CFSecISOCtryLangBuff* clone;
		auto searchDictByLangIdx = dictByLangIdx->find( key );
		if( searchDictByLangIdx != dictByLangIdx->end() ) {
			std::map<cfsec::CFSecISOCtryLangPKey,
				 cfsec::CFSecISOCtryLangBuff*>* subdictLangIdx = searchDictByLangIdx->second;
			std::map<cfsec::CFSecISOCtryLangPKey,
				cfsec::CFSecISOCtryLangBuff*>::iterator iter = subdictLangIdx->begin();
			std::map<cfsec::CFSecISOCtryLangPKey,
				cfsec::CFSecISOCtryLangBuff*>::iterator end = subdictLangIdx->end();
			while( iter != end ) {
				clone = dynamic_cast<cfsec::CFSecISOCtryLangBuff*>( iter->second->clone() );
				recVec.push_back( clone );
				iter ++;
			}
		}
		return( recVec );
	}

	cfsec::CFSecISOCtryLangBuff* CFSecRamISOCtryLangTable::readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t ISOCtryId,
			const int16_t ISOLangId )
	{
		static const std::string S_ProcName( "readDerivedByIdIdx" );
		cfsec::CFSecISOCtryLangPKey key;
		key.setRequiredISOCtryId( ISOCtryId );
		key.setRequiredISOLangId( ISOLangId );
		cfsec::CFSecISOCtryLangBuff* buff;
		auto searchDictByPKey = dictByPKey->find( key );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfsec::CFSecISOCtryLangBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecISOCtryLangBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfsec::CFSecISOCtryLangBuff* CFSecRamISOCtryLangTable::readBuff( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecISOCtryLangPKey* PKey )
	{
		static const std::string S_ProcName( "readBuff" );
		cfsec::CFSecISOCtryLangBuff* buff = readDerived( Authorization, PKey );
		if( buff != NULL ) {
			if( buff->getClassCode() != cfsec::CFSecISOCtryLangBuff::CLASS_CODE ) {
				delete buff;
				buff = NULL;
			}
		}
		return( dynamic_cast<cfsec::CFSecISOCtryLangBuff*>( buff ) );
	}

	cfsec::CFSecISOCtryLangBuff* CFSecRamISOCtryLangTable::lockBuff( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecISOCtryLangPKey* PKey )
	{
		static const std::string S_ProcName( "lockBuff" );
		cfsec::CFSecISOCtryLangBuff* buff = lockDerived( Authorization, PKey );
		return( dynamic_cast<cfsec::CFSecISOCtryLangBuff*>( buff ) );
	}

	std::TCFLibOwningVector<cfsec::CFSecISOCtryLangBuff*> CFSecRamISOCtryLangTable::readAllBuff( const cfsec::CFSecAuthorization* Authorization )
	{
		static const std::string S_ProcName( "readAllBuff" );
		cfsec::CFSecISOCtryLangBuff* buff;
		std::TCFLibOwningVector<cfsec::CFSecISOCtryLangBuff*> filteredList;
		std::TCFLibOwningVector<cfsec::CFSecISOCtryLangBuff*> buffList = readAllDerived( Authorization );
		std::TCFLibOwningVector<cfsec::CFSecISOCtryLangBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfsec::CFSecISOCtryLangBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfsec::CFSecISOCtryLangBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfsec::CFSecISOCtryLangBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	cfsec::CFSecISOCtryLangBuff* CFSecRamISOCtryLangTable::readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t ISOCtryId,
			const int16_t ISOLangId )
	{
		static const std::string S_ProcName( "readBuffByIdIdx" );
		cfsec::CFSecISOCtryLangBuff* buff = readDerivedByIdIdx( Authorization,
			ISOCtryId,
			ISOLangId );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfsec::CFSecISOCtryLangBuff::CLASS_CODE ) {
			return( dynamic_cast<cfsec::CFSecISOCtryLangBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	std::TCFLibOwningVector<cfsec::CFSecISOCtryLangBuff*> CFSecRamISOCtryLangTable::readBuffByCtryIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t ISOCtryId )
	{
		static const std::string S_ProcName( "readBuffByCtryIdx" );
		cfsec::CFSecISOCtryLangBuff* buff;
		std::TCFLibOwningVector<cfsec::CFSecISOCtryLangBuff*> filteredList;
		std::TCFLibOwningVector<cfsec::CFSecISOCtryLangBuff*> buffList = readDerivedByCtryIdx( Authorization,
			ISOCtryId );
		std::TCFLibOwningVector<cfsec::CFSecISOCtryLangBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfsec::CFSecISOCtryLangBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfsec::CFSecISOCtryLangBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfsec::CFSecISOCtryLangBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	std::TCFLibOwningVector<cfsec::CFSecISOCtryLangBuff*> CFSecRamISOCtryLangTable::readBuffByLangIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t ISOLangId )
	{
		static const std::string S_ProcName( "readBuffByLangIdx" );
		cfsec::CFSecISOCtryLangBuff* buff;
		std::TCFLibOwningVector<cfsec::CFSecISOCtryLangBuff*> filteredList;
		std::TCFLibOwningVector<cfsec::CFSecISOCtryLangBuff*> buffList = readDerivedByLangIdx( Authorization,
			ISOLangId );
		std::TCFLibOwningVector<cfsec::CFSecISOCtryLangBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfsec::CFSecISOCtryLangBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfsec::CFSecISOCtryLangBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfsec::CFSecISOCtryLangBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	cfsec::CFSecISOCtryLangBuff* CFSecRamISOCtryLangTable::updateISOCtryLang( const cfsec::CFSecAuthorization* Authorization,
		cfsec::CFSecISOCtryLangBuff* Buff )
	{
		static const std::string S_ProcName( "updateISOCtryLang" );
		cfsec::CFSecISOCtryLangPKey pkey;
		pkey.setRequiredISOCtryId( Buff->getRequiredISOCtryId() );
		pkey.setRequiredISOLangId( Buff->getRequiredISOLangId() );

		// Search for existing buffer

		auto searchExisting = dictByPKey->find( pkey );
		if( searchExisting == dictByPKey->end() ) {
			delete Buff;
			std::string Msg( "Existing record not found in ISOCtryLang for key " + pkey.toString() );
			throw cflib::CFLibStaleCacheDetectedException( CLASS_NAME,
				S_ProcName,
				Msg );
		}

		cfsec::CFSecISOCtryLangBuff* existing = searchExisting->second;

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
			std::string Msg( "Collision detected for ISOCtryLang primary key " );
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
		cfsec::CFSecISOCtryLangByCtryIdxKey existingKeyCtryIdx;
		existingKeyCtryIdx.setRequiredISOCtryId( existing->getRequiredISOCtryId() );
		cfsec::CFSecISOCtryLangByCtryIdxKey newKeyCtryIdx;
		newKeyCtryIdx.setRequiredISOCtryId( Buff->getRequiredISOCtryId() );
		cfsec::CFSecISOCtryLangByLangIdxKey existingKeyLangIdx;
		existingKeyLangIdx.setRequiredISOLangId( existing->getRequiredISOLangId() );
		cfsec::CFSecISOCtryLangByLangIdxKey newKeyLangIdx;
		newKeyLangIdx.setRequiredISOLangId( Buff->getRequiredISOLangId() );
		// Check unique indexes

		// Validate foreign keys

		{
			bool allNull = true;

			if( allNull ) {
				cfsec::CFSecISOCtryBuff* chk = dynamic_cast<cfsec::CFSecISOCtryBuff*>( schema->getTableISOCtry()->readDerivedByIdIdx( Authorization,
						Buff->getRequiredISOCtryId() ) );
				if( chk == NULL ) {
					delete Buff;
					std::string Msg( "Could not resolve Container relationship ISOCtryLangCtry to table ISOCtry" );
					throw cflib::CFLibUnresolvedRelationException( CLASS_NAME,
						S_ProcName,
						Msg );
				}
				delete chk;
				chk = NULL;
			}
		}

		// Update is valid
		std::map<cfsec::CFSecISOCtryLangPKey, cfsec::CFSecISOCtryLangBuff*>* subdict;
		auto removalDictByPKey = dictByPKey->find( pkey );
		if( removalDictByPKey != dictByPKey->end() ) {
			dictByPKey->erase( removalDictByPKey );
		}
		// Copy edited buffer to existing persistent buffer

		if( Buff->getClassCode() != cfsec::CFSecISOCtryLangBuff::CLASS_CODE ) {
			const static std::string S_IsNotA( " is not a cfsec::CFSecISOCtryLangBuff" );
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

		dictByPKey->insert( std::map<cfsec::CFSecISOCtryLangPKey, cfsec::CFSecISOCtryLangBuff*>::value_type( pkey, existing ) );

		std::map<cfsec::CFSecISOCtryLangPKey,
			 cfsec::CFSecISOCtryLangBuff*>* subdictCtryIdx;
		auto searchDictByCtryIdx = dictByCtryIdx->find( existingKeyCtryIdx );
		if( searchDictByCtryIdx != dictByCtryIdx->end() ) {
			subdictCtryIdx = searchDictByCtryIdx->second;
			auto searchSubDict = subdictCtryIdx->find( pkey );
			if( searchSubDict != subdictCtryIdx->end() ) {
				subdictCtryIdx->erase( searchSubDict );
			}
			if( subdictCtryIdx->size() <= 0 ) {
				delete subdictCtryIdx;
				dictByCtryIdx->erase( searchDictByCtryIdx );
			}
			subdictCtryIdx = NULL;
		}
		auto searchNewKeyDictByCtryIdx = dictByCtryIdx->find( newKeyCtryIdx );
		if( searchNewKeyDictByCtryIdx != dictByCtryIdx->end() ) {
			subdictCtryIdx = searchNewKeyDictByCtryIdx->second;
		}
		else {
			subdictCtryIdx = new std::map<cfsec::CFSecISOCtryLangPKey, cfsec::CFSecISOCtryLangBuff*>();
			dictByCtryIdx->insert( std::map<cfsec::CFSecISOCtryLangByCtryIdxKey,
				std::map<cfsec::CFSecISOCtryLangPKey,
					cfsec::CFSecISOCtryLangBuff*>*>::value_type( newKeyCtryIdx, subdictCtryIdx ) );
		}
		subdictCtryIdx->insert( std::map<cfsec::CFSecISOCtryLangPKey, cfsec::CFSecISOCtryLangBuff*>::value_type( pkey, existing ) );

		std::map<cfsec::CFSecISOCtryLangPKey,
			 cfsec::CFSecISOCtryLangBuff*>* subdictLangIdx;
		auto searchDictByLangIdx = dictByLangIdx->find( existingKeyLangIdx );
		if( searchDictByLangIdx != dictByLangIdx->end() ) {
			subdictLangIdx = searchDictByLangIdx->second;
			auto searchSubDict = subdictLangIdx->find( pkey );
			if( searchSubDict != subdictLangIdx->end() ) {
				subdictLangIdx->erase( searchSubDict );
			}
			if( subdictLangIdx->size() <= 0 ) {
				delete subdictLangIdx;
				dictByLangIdx->erase( searchDictByLangIdx );
			}
			subdictLangIdx = NULL;
		}
		auto searchNewKeyDictByLangIdx = dictByLangIdx->find( newKeyLangIdx );
		if( searchNewKeyDictByLangIdx != dictByLangIdx->end() ) {
			subdictLangIdx = searchNewKeyDictByLangIdx->second;
		}
		else {
			subdictLangIdx = new std::map<cfsec::CFSecISOCtryLangPKey, cfsec::CFSecISOCtryLangBuff*>();
			dictByLangIdx->insert( std::map<cfsec::CFSecISOCtryLangByLangIdxKey,
				std::map<cfsec::CFSecISOCtryLangPKey,
					cfsec::CFSecISOCtryLangBuff*>*>::value_type( newKeyLangIdx, subdictLangIdx ) );
		}
		subdictLangIdx->insert( std::map<cfsec::CFSecISOCtryLangPKey, cfsec::CFSecISOCtryLangBuff*>::value_type( pkey, existing ) );


		// The top level code has to clean up the memory buffer that was passed in, and return a clone
		// of the copy that existing buffer that is attached to the RAM storage.  All other cases
		// return the existing buffer.

		cfsec::CFSecISOCtryLangBuff* buff;
		if( existing->getClassCode() == cfsec::CFSecISOCtryLangBuff::CLASS_CODE ) {
			delete Buff;
			Buff = NULL;
			buff = dynamic_cast<cfsec::CFSecISOCtryLangBuff*>( existing->clone() );
		}
		else {
			buff = existing;
		}
		return( buff );
	}

	void CFSecRamISOCtryLangTable::deleteISOCtryLang( const cfsec::CFSecAuthorization* Authorization,
		cfsec::CFSecISOCtryLangBuff* Buff )
	{
		static const std::string S_ProcName( "deleteISOCtryLang" );
		static const std::string S_Prev( "prev" );
		classcode_t classCode;
		cfsec::CFSecISOCtryLangPKey pkey;
		pkey.setRequiredISOCtryId( Buff->getRequiredISOCtryId() );
		pkey.setRequiredISOLangId( Buff->getRequiredISOLangId() );
		auto searchExisting = dictByPKey->find( pkey );
		if( searchExisting == dictByPKey->end() ) {
			return;
		}
		cfsec::CFSecISOCtryLangBuff* existing = searchExisting->second;
		cfsec::CFSecISOCtryLangByCtryIdxKey keyCtryIdx;
		keyCtryIdx.setRequiredISOCtryId( existing->getRequiredISOCtryId() );
		cfsec::CFSecISOCtryLangByLangIdxKey keyLangIdx;
		keyLangIdx.setRequiredISOLangId( existing->getRequiredISOLangId() );
		// Validate reverse foreign keys

		// Delete is valid
		std::map<cfsec::CFSecISOCtryLangPKey, cfsec::CFSecISOCtryLangBuff*>* subdict;

		auto searchDictByPKey = dictByPKey->find( pkey );
		if( searchDictByPKey != dictByPKey->end() ) {
			dictByPKey->erase( searchDictByPKey );
		}

		auto searchDictByCtryIdx = dictByCtryIdx->find( keyCtryIdx );
		if( searchDictByCtryIdx != dictByCtryIdx->end() ) {
			std::map<cfsec::CFSecISOCtryLangPKey,
				 cfsec::CFSecISOCtryLangBuff*>* subdictCtryIdx = searchDictByCtryIdx->second;
			auto searchSubDict = subdictCtryIdx->find( pkey );
			if( searchSubDict != subdictCtryIdx->end() ) {
				subdictCtryIdx->erase( searchSubDict );
			}
			subdictCtryIdx = NULL;
		}

		auto searchDictByLangIdx = dictByLangIdx->find( keyLangIdx );
		if( searchDictByLangIdx != dictByLangIdx->end() ) {
			std::map<cfsec::CFSecISOCtryLangPKey,
				 cfsec::CFSecISOCtryLangBuff*>* subdictLangIdx = searchDictByLangIdx->second;
			auto searchSubDict = subdictLangIdx->find( pkey );
			if( searchSubDict != subdictLangIdx->end() ) {
				subdictLangIdx->erase( searchSubDict );
			}
			subdictLangIdx = NULL;
		}

		if( existing != NULL ) {
			delete existing;
			existing = NULL;
		}
	}

	void CFSecRamISOCtryLangTable::deleteISOCtryLangByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t argISOCtryId,
			const int16_t argISOLangId )
	{
		cfsec::CFSecISOCtryLangPKey key;
		key.setRequiredISOCtryId( argISOCtryId );
		key.setRequiredISOLangId( argISOLangId );
		deleteISOCtryLangByIdIdx( Authorization, &key );
	}

	void CFSecRamISOCtryLangTable::deleteISOCtryLangByIdIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecISOCtryLangPKey* argKey )
	{
		bool anyNotNull = false;
		anyNotNull = true;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		cfsec::CFSecISOCtryLangBuff* cur = NULL;
		cfsec::CFSecISOCtryLangBuff* rereadCur = NULL;
		std::TCFLibOwningVector<cfsec::CFSecISOCtryLangBuff*> matchSet;
		std::map<cfsec::CFSecISOCtryLangPKey,
			cfsec::CFSecISOCtryLangBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecISOCtryLangPKey,
			cfsec::CFSecISOCtryLangBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecISOCtryLangBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecISOCtryLangBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecISOCtryLangBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecISOCtryLangBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableISOCtryLang()->readDerivedByIdIdx( Authorization,
				cur->getRequiredISOCtryId(),
				cur->getRequiredISOLangId() );
			rereadCur = cur;
			deleteISOCtryLang( Authorization, cur );
			if( rereadCur != NULL ) {
				delete rereadCur;
				rereadCur = NULL;
			}
		}
	}

	void CFSecRamISOCtryLangTable::deleteISOCtryLangByCtryIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t argISOCtryId )
	{
		cfsec::CFSecISOCtryLangByCtryIdxKey key;
		key.setRequiredISOCtryId( argISOCtryId );
		deleteISOCtryLangByCtryIdx( Authorization, &key );
	}

	void CFSecRamISOCtryLangTable::deleteISOCtryLangByCtryIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecISOCtryLangByCtryIdxKey* argKey )
	{
		cfsec::CFSecISOCtryLangBuff* cur = NULL;
		cfsec::CFSecISOCtryLangBuff* rereadCur = NULL;
		bool anyNotNull = false;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfsec::CFSecISOCtryLangBuff*> matchSet;
		std::map<cfsec::CFSecISOCtryLangPKey,
			cfsec::CFSecISOCtryLangBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecISOCtryLangPKey,
			cfsec::CFSecISOCtryLangBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecISOCtryLangBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecISOCtryLangBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecISOCtryLangBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecISOCtryLangBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableISOCtryLang()->readDerivedByIdIdx( Authorization,
				cur->getRequiredISOCtryId(),
				cur->getRequiredISOLangId() );
			rereadCur = cur;
			deleteISOCtryLang( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFSecRamISOCtryLangTable::deleteISOCtryLangByLangIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t argISOLangId )
	{
		cfsec::CFSecISOCtryLangByLangIdxKey key;
		key.setRequiredISOLangId( argISOLangId );
		deleteISOCtryLangByLangIdx( Authorization, &key );
	}

	void CFSecRamISOCtryLangTable::deleteISOCtryLangByLangIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecISOCtryLangByLangIdxKey* argKey )
	{
		cfsec::CFSecISOCtryLangBuff* cur = NULL;
		cfsec::CFSecISOCtryLangBuff* rereadCur = NULL;
		bool anyNotNull = false;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfsec::CFSecISOCtryLangBuff*> matchSet;
		std::map<cfsec::CFSecISOCtryLangPKey,
			cfsec::CFSecISOCtryLangBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecISOCtryLangPKey,
			cfsec::CFSecISOCtryLangBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecISOCtryLangBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecISOCtryLangBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecISOCtryLangBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecISOCtryLangBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableISOCtryLang()->readDerivedByIdIdx( Authorization,
				cur->getRequiredISOCtryId(),
				cur->getRequiredISOLangId() );
			rereadCur = cur;
			deleteISOCtryLang( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFSecRamISOCtryLangTable::releasePreparedStatements() {
	}

}
