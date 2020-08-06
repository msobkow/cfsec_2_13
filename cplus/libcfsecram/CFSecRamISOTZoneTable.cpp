
// Description: C++18 Implementation for an in-memory RAM DbIO for ISOTZone.

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

	const std::string CFSecRamISOTZoneTable::CLASS_NAME( "CFSecRamISOTZoneTable" );

	CFSecRamISOTZoneTable::CFSecRamISOTZoneTable( ICFSecSchema* argSchema )
	: cfsec::ICFSecISOTZoneTable()
	{
		schema = argSchema;
		dictByPKey = new std::map<cfsec::CFSecISOTZonePKey, cfsec::CFSecISOTZoneBuff*>();
		dictByOffsetIdx = new std::map<cfsec::CFSecISOTZoneByOffsetIdxKey,
			std::map<cfsec::CFSecISOTZonePKey,
				cfsec::CFSecISOTZoneBuff*>*>();
		dictByUTZNameIdx = new std::map<cfsec::CFSecISOTZoneByUTZNameIdxKey, cfsec::CFSecISOTZoneBuff*>();
		dictByIso8601Idx = new std::map<cfsec::CFSecISOTZoneByIso8601IdxKey,
			std::map<cfsec::CFSecISOTZonePKey,
				cfsec::CFSecISOTZoneBuff*>*>();
	}

	CFSecRamISOTZoneTable::~CFSecRamISOTZoneTable() {
		if( dictByOffsetIdx != NULL ) {
			for( auto iterDict = dictByOffsetIdx->begin(); iterDict != dictByOffsetIdx->end(); iterDict ++ ) {
				delete iterDict->second;
				iterDict->second = NULL;
			}
			delete dictByOffsetIdx;
			dictByOffsetIdx = NULL;
		}
		if( dictByUTZNameIdx != NULL ) {
			delete dictByUTZNameIdx;
			dictByUTZNameIdx = NULL;
		}
		if( dictByIso8601Idx != NULL ) {
			for( auto iterDict = dictByIso8601Idx->begin(); iterDict != dictByIso8601Idx->end(); iterDict ++ ) {
				delete iterDict->second;
				iterDict->second = NULL;
			}
			delete dictByIso8601Idx;
			dictByIso8601Idx = NULL;
		}
		if( dictByPKey != NULL ) {
			cfsec::CFSecISOTZoneBuff* elt;
			std::map<cfsec::CFSecISOTZonePKey,
				cfsec::CFSecISOTZoneBuff*>::iterator end = dictByPKey->end();
			for( std::map<cfsec::CFSecISOTZonePKey,
					cfsec::CFSecISOTZoneBuff*>::iterator cur = dictByPKey->begin();
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

	cfsec::CFSecISOTZoneBuff* CFSecRamISOTZoneTable::createISOTZone( const cfsec::CFSecAuthorization* Authorization,
		cfsec::CFSecISOTZoneBuff* Buff )
	{
		static const std::string S_ProcName( "createISOTZone" );
		cfsec::CFSecISOTZonePKey pkey;
		pkey.setRequiredISOTZoneId( schema->nextISOTZoneIdGen() );
		Buff->setRequiredISOTZoneId( pkey.getRequiredISOTZoneId() );
		cfsec::CFSecISOTZoneByOffsetIdxKey keyOffsetIdx;
		keyOffsetIdx.setRequiredTZHourOffset( Buff->getRequiredTZHourOffset() );
		keyOffsetIdx.setRequiredTZMinOffset( Buff->getRequiredTZMinOffset() );
		cfsec::CFSecISOTZoneByUTZNameIdxKey keyUTZNameIdx;
		keyUTZNameIdx.setRequiredTZName( Buff->getRequiredTZName() );
		cfsec::CFSecISOTZoneByIso8601IdxKey keyIso8601Idx;
		keyIso8601Idx.setRequiredIso8601( Buff->getRequiredIso8601() );
		// Validate unique indexes
		auto searchDictByPKey = dictByPKey->find( pkey );
		if( searchDictByPKey != dictByPKey->end() ) {
			delete Buff;
			std::string Msg( "Duplicate primary key detected " + pkey.toString() );
			throw cflib::CFLibPrimaryKeyNotNewException( CLASS_NAME, S_ProcName, Msg );
		}

		auto searchDictByUTZNameIdx = dictByUTZNameIdx->find( keyUTZNameIdx );
		if( searchDictByUTZNameIdx != dictByUTZNameIdx->end() ) {
			std::string Msg( "Duplicate key detected for index ISOTZoneUTZNameIdx " + keyUTZNameIdx.toString() );
			delete Buff;
			throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
				S_ProcName,
				Msg );
		}

		// Validate foreign keys

		// Proceed with adding the new record
		cfsec::CFSecISOTZoneBuff* buff = Buff;
		buff->setRequiredRevision( 1 );
		dictByPKey->insert( std::map<cfsec::CFSecISOTZonePKey, cfsec::CFSecISOTZoneBuff*>::value_type( pkey, buff ) );

		std::map<cfsec::CFSecISOTZonePKey, cfsec::CFSecISOTZoneBuff*>* subdictOffsetIdx;
		auto searchDictByOffsetIdx = dictByOffsetIdx->find( keyOffsetIdx );
		if( searchDictByOffsetIdx != dictByOffsetIdx->end() ) {
			subdictOffsetIdx = searchDictByOffsetIdx->second;
		}
		else {
			subdictOffsetIdx = new std::map<cfsec::CFSecISOTZonePKey, cfsec::CFSecISOTZoneBuff*>();
			dictByOffsetIdx->insert( std::map<cfsec::CFSecISOTZoneByOffsetIdxKey,
				std::map<cfsec::CFSecISOTZonePKey,
					cfsec::CFSecISOTZoneBuff*>*>::value_type( keyOffsetIdx, subdictOffsetIdx ) );
		}
		subdictOffsetIdx->insert( std::map<cfsec::CFSecISOTZonePKey, cfsec::CFSecISOTZoneBuff*>::value_type( pkey, buff ) );

		dictByUTZNameIdx->insert( std::map<cfsec::CFSecISOTZoneByUTZNameIdxKey, cfsec::CFSecISOTZoneBuff*>::value_type( keyUTZNameIdx, buff ) );

		std::map<cfsec::CFSecISOTZonePKey, cfsec::CFSecISOTZoneBuff*>* subdictIso8601Idx;
		auto searchDictByIso8601Idx = dictByIso8601Idx->find( keyIso8601Idx );
		if( searchDictByIso8601Idx != dictByIso8601Idx->end() ) {
			subdictIso8601Idx = searchDictByIso8601Idx->second;
		}
		else {
			subdictIso8601Idx = new std::map<cfsec::CFSecISOTZonePKey, cfsec::CFSecISOTZoneBuff*>();
			dictByIso8601Idx->insert( std::map<cfsec::CFSecISOTZoneByIso8601IdxKey,
				std::map<cfsec::CFSecISOTZonePKey,
					cfsec::CFSecISOTZoneBuff*>*>::value_type( keyIso8601Idx, subdictIso8601Idx ) );
		}
		subdictIso8601Idx->insert( std::map<cfsec::CFSecISOTZonePKey, cfsec::CFSecISOTZoneBuff*>::value_type( pkey, buff ) );

		// The top level code has to clone the final buffer. The one passed in is now part of the persistent storage.
		if( buff->getClassCode() == cfsec::CFSecISOTZoneBuff::CLASS_CODE ) {
			buff = dynamic_cast<cfsec::CFSecISOTZoneBuff*>( buff->clone() );
		}
		return( buff );
	}

	cfsec::CFSecISOTZoneBuff* CFSecRamISOTZoneTable::readDerived( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecISOTZonePKey* PKey )
	{
		static const std::string S_ProcName( "readDerived" );
		cfsec::CFSecISOTZoneBuff* buff;
		auto searchDictByPKey = dictByPKey->find( *PKey );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfsec::CFSecISOTZoneBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecISOTZoneBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfsec::CFSecISOTZoneBuff* CFSecRamISOTZoneTable::lockDerived( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecISOTZonePKey* PKey )
	{
		static const std::string S_ProcName( "lockDerived" );
		cfsec::CFSecISOTZoneBuff* buff;
		auto searchDictByPKey = dictByPKey->find( *PKey );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfsec::CFSecISOTZoneBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecISOTZoneBuff*>( buff->clone() );
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

	std::TCFLibOwningVector<cfsec::CFSecISOTZoneBuff*> CFSecRamISOTZoneTable::readAllDerived( const cfsec::CFSecAuthorization* Authorization ) {
		static const std::string S_ProcName( "readAllDerived" );
		std::TCFLibOwningVector<cfsec::CFSecISOTZoneBuff*> retVec;
		std::map<cfsec::CFSecISOTZonePKey,
			cfsec::CFSecISOTZoneBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecISOTZonePKey,
			cfsec::CFSecISOTZoneBuff*>::iterator end = dictByPKey->end();
		cfsec::CFSecISOTZoneBuff* clone;
		while( iter != end ) {
			clone = dynamic_cast<cfsec::CFSecISOTZoneBuff*>( iter->second->clone() );
			retVec.push_back( clone );
			iter ++;
		}
		return( retVec );
	}

	std::TCFLibOwningVector<cfsec::CFSecISOTZoneBuff*> CFSecRamISOTZoneTable::readDerivedByOffsetIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t TZHourOffset,
			const int16_t TZMinOffset )
	{
		static const std::string S_ProcName( "readDerivedByOffsetIdx" );
		cfsec::CFSecISOTZoneByOffsetIdxKey key;
		key.setRequiredTZHourOffset( TZHourOffset );
		key.setRequiredTZMinOffset( TZMinOffset );
		std::TCFLibOwningVector<cfsec::CFSecISOTZoneBuff*> recVec;
		cfsec::CFSecISOTZoneBuff* clone;
		auto searchDictByOffsetIdx = dictByOffsetIdx->find( key );
		if( searchDictByOffsetIdx != dictByOffsetIdx->end() ) {
			std::map<cfsec::CFSecISOTZonePKey,
				 cfsec::CFSecISOTZoneBuff*>* subdictOffsetIdx = searchDictByOffsetIdx->second;
			std::map<cfsec::CFSecISOTZonePKey,
				cfsec::CFSecISOTZoneBuff*>::iterator iter = subdictOffsetIdx->begin();
			std::map<cfsec::CFSecISOTZonePKey,
				cfsec::CFSecISOTZoneBuff*>::iterator end = subdictOffsetIdx->end();
			while( iter != end ) {
				clone = dynamic_cast<cfsec::CFSecISOTZoneBuff*>( iter->second->clone() );
				recVec.push_back( clone );
				iter ++;
			}
		}
		return( recVec );
	}

	cfsec::CFSecISOTZoneBuff* CFSecRamISOTZoneTable::readDerivedByUTZNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& TZName )
	{
		static const std::string S_ProcName( "readDerivedByUTZNameIdx" );
		cfsec::CFSecISOTZoneByUTZNameIdxKey key;
		key.setRequiredTZName( TZName );
		cfsec::CFSecISOTZoneBuff* buff;
		auto searchDictByUTZNameIdx = dictByUTZNameIdx->find( key );
		if( searchDictByUTZNameIdx != dictByUTZNameIdx->end() ) {
			buff = dynamic_cast<cfsec::CFSecISOTZoneBuff*>( searchDictByUTZNameIdx->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecISOTZoneBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	std::TCFLibOwningVector<cfsec::CFSecISOTZoneBuff*> CFSecRamISOTZoneTable::readDerivedByIso8601Idx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& Iso8601 )
	{
		static const std::string S_ProcName( "readDerivedByIso8601Idx" );
		cfsec::CFSecISOTZoneByIso8601IdxKey key;
		key.setRequiredIso8601( Iso8601 );
		std::TCFLibOwningVector<cfsec::CFSecISOTZoneBuff*> recVec;
		cfsec::CFSecISOTZoneBuff* clone;
		auto searchDictByIso8601Idx = dictByIso8601Idx->find( key );
		if( searchDictByIso8601Idx != dictByIso8601Idx->end() ) {
			std::map<cfsec::CFSecISOTZonePKey,
				 cfsec::CFSecISOTZoneBuff*>* subdictIso8601Idx = searchDictByIso8601Idx->second;
			std::map<cfsec::CFSecISOTZonePKey,
				cfsec::CFSecISOTZoneBuff*>::iterator iter = subdictIso8601Idx->begin();
			std::map<cfsec::CFSecISOTZonePKey,
				cfsec::CFSecISOTZoneBuff*>::iterator end = subdictIso8601Idx->end();
			while( iter != end ) {
				clone = dynamic_cast<cfsec::CFSecISOTZoneBuff*>( iter->second->clone() );
				recVec.push_back( clone );
				iter ++;
			}
		}
		return( recVec );
	}

	cfsec::CFSecISOTZoneBuff* CFSecRamISOTZoneTable::readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t ISOTZoneId )
	{
		static const std::string S_ProcName( "readDerivedByIdIdx" );
		cfsec::CFSecISOTZonePKey key;
		key.setRequiredISOTZoneId( ISOTZoneId );
		cfsec::CFSecISOTZoneBuff* buff;
		auto searchDictByPKey = dictByPKey->find( key );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfsec::CFSecISOTZoneBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecISOTZoneBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfsec::CFSecISOTZoneBuff* CFSecRamISOTZoneTable::readBuff( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecISOTZonePKey* PKey )
	{
		static const std::string S_ProcName( "readBuff" );
		cfsec::CFSecISOTZoneBuff* buff = readDerived( Authorization, PKey );
		if( buff != NULL ) {
			if( buff->getClassCode() != cfsec::CFSecISOTZoneBuff::CLASS_CODE ) {
				delete buff;
				buff = NULL;
			}
		}
		return( dynamic_cast<cfsec::CFSecISOTZoneBuff*>( buff ) );
	}

	cfsec::CFSecISOTZoneBuff* CFSecRamISOTZoneTable::lockBuff( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecISOTZonePKey* PKey )
	{
		static const std::string S_ProcName( "lockBuff" );
		cfsec::CFSecISOTZoneBuff* buff = lockDerived( Authorization, PKey );
		return( dynamic_cast<cfsec::CFSecISOTZoneBuff*>( buff ) );
	}

	std::TCFLibOwningVector<cfsec::CFSecISOTZoneBuff*> CFSecRamISOTZoneTable::readAllBuff( const cfsec::CFSecAuthorization* Authorization )
	{
		static const std::string S_ProcName( "readAllBuff" );
		cfsec::CFSecISOTZoneBuff* buff;
		std::TCFLibOwningVector<cfsec::CFSecISOTZoneBuff*> filteredList;
		std::TCFLibOwningVector<cfsec::CFSecISOTZoneBuff*> buffList = readAllDerived( Authorization );
		std::TCFLibOwningVector<cfsec::CFSecISOTZoneBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfsec::CFSecISOTZoneBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfsec::CFSecISOTZoneBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfsec::CFSecISOTZoneBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	cfsec::CFSecISOTZoneBuff* CFSecRamISOTZoneTable::readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t ISOTZoneId )
	{
		static const std::string S_ProcName( "readBuffByIdIdx" );
		cfsec::CFSecISOTZoneBuff* buff = readDerivedByIdIdx( Authorization,
			ISOTZoneId );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfsec::CFSecISOTZoneBuff::CLASS_CODE ) {
			return( dynamic_cast<cfsec::CFSecISOTZoneBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	std::TCFLibOwningVector<cfsec::CFSecISOTZoneBuff*> CFSecRamISOTZoneTable::readBuffByOffsetIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t TZHourOffset,
			const int16_t TZMinOffset )
	{
		static const std::string S_ProcName( "readBuffByOffsetIdx" );
		cfsec::CFSecISOTZoneBuff* buff;
		std::TCFLibOwningVector<cfsec::CFSecISOTZoneBuff*> filteredList;
		std::TCFLibOwningVector<cfsec::CFSecISOTZoneBuff*> buffList = readDerivedByOffsetIdx( Authorization,
			TZHourOffset,
			TZMinOffset );
		std::TCFLibOwningVector<cfsec::CFSecISOTZoneBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfsec::CFSecISOTZoneBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfsec::CFSecISOTZoneBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfsec::CFSecISOTZoneBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	cfsec::CFSecISOTZoneBuff* CFSecRamISOTZoneTable::readBuffByUTZNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& TZName )
	{
		static const std::string S_ProcName( "readBuffByUTZNameIdx" );
		cfsec::CFSecISOTZoneBuff* buff = readDerivedByUTZNameIdx( Authorization,
			TZName );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfsec::CFSecISOTZoneBuff::CLASS_CODE ) {
			return( dynamic_cast<cfsec::CFSecISOTZoneBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	std::TCFLibOwningVector<cfsec::CFSecISOTZoneBuff*> CFSecRamISOTZoneTable::readBuffByIso8601Idx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& Iso8601 )
	{
		static const std::string S_ProcName( "readBuffByIso8601Idx" );
		cfsec::CFSecISOTZoneBuff* buff;
		std::TCFLibOwningVector<cfsec::CFSecISOTZoneBuff*> filteredList;
		std::TCFLibOwningVector<cfsec::CFSecISOTZoneBuff*> buffList = readDerivedByIso8601Idx( Authorization,
			Iso8601 );
		std::TCFLibOwningVector<cfsec::CFSecISOTZoneBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfsec::CFSecISOTZoneBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfsec::CFSecISOTZoneBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfsec::CFSecISOTZoneBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	cfsec::CFSecISOTZoneBuff* CFSecRamISOTZoneTable::readBuffByLookupUTZNameIdx( const cfsec::CFSecAuthorization* Authorization, const std::string& TZName,
		bool forceRead )
	{
		static const std::string S_ProcName( "readBuffByLookupUTZNameIdx" );
		cfsec::CFSecISOTZoneBuff* buff = readBuffByUTZNameIdx( Authorization,
			TZName );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfsec::CFSecISOTZoneBuff::CLASS_CODE ) {
			return( dynamic_cast<cfsec::CFSecISOTZoneBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	cfsec::CFSecISOTZoneBuff* CFSecRamISOTZoneTable::readDerivedByLookupUTZNameIdx( const cfsec::CFSecAuthorization* Authorization, const std::string& TZName,
		bool forceRead )
	{
		static const std::string S_ProcName( "readDerivedByLookupUTZNameIdx" );
		cfsec::CFSecISOTZoneBuff* buff = readDerivedByUTZNameIdx( Authorization,
			TZName );
		if( buff != NULL ) {
			return( dynamic_cast<cfsec::CFSecISOTZoneBuff*>( buff->clone() ) );
		}
		else {
			return( NULL );
		}
	}

	cfsec::CFSecISOTZoneBuff* CFSecRamISOTZoneTable::updateISOTZone( const cfsec::CFSecAuthorization* Authorization,
		cfsec::CFSecISOTZoneBuff* Buff )
	{
		static const std::string S_ProcName( "updateISOTZone" );
		cfsec::CFSecISOTZonePKey pkey;
		pkey.setRequiredISOTZoneId( Buff->getRequiredISOTZoneId() );

		// Search for existing buffer

		auto searchExisting = dictByPKey->find( pkey );
		if( searchExisting == dictByPKey->end() ) {
			delete Buff;
			std::string Msg( "Existing record not found in ISOTZone for key " + pkey.toString() );
			throw cflib::CFLibStaleCacheDetectedException( CLASS_NAME,
				S_ProcName,
				Msg );
		}

		cfsec::CFSecISOTZoneBuff* existing = searchExisting->second;

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
			std::string Msg( "Collision detected for ISOTZone primary key " );
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
		cfsec::CFSecISOTZoneByOffsetIdxKey existingKeyOffsetIdx;
		existingKeyOffsetIdx.setRequiredTZHourOffset( existing->getRequiredTZHourOffset() );
		existingKeyOffsetIdx.setRequiredTZMinOffset( existing->getRequiredTZMinOffset() );
		cfsec::CFSecISOTZoneByOffsetIdxKey newKeyOffsetIdx;
		newKeyOffsetIdx.setRequiredTZHourOffset( Buff->getRequiredTZHourOffset() );
		newKeyOffsetIdx.setRequiredTZMinOffset( Buff->getRequiredTZMinOffset() );
		cfsec::CFSecISOTZoneByUTZNameIdxKey existingKeyUTZNameIdx;
		existingKeyUTZNameIdx.setRequiredTZName( existing->getRequiredTZName() );
		cfsec::CFSecISOTZoneByUTZNameIdxKey newKeyUTZNameIdx;
		newKeyUTZNameIdx.setRequiredTZName( Buff->getRequiredTZName() );
		cfsec::CFSecISOTZoneByIso8601IdxKey existingKeyIso8601Idx;
		existingKeyIso8601Idx.setRequiredIso8601( existing->getRequiredIso8601() );
		cfsec::CFSecISOTZoneByIso8601IdxKey newKeyIso8601Idx;
		newKeyIso8601Idx.setRequiredIso8601( Buff->getRequiredIso8601() );
		// Check unique indexes

		if( existingKeyUTZNameIdx != newKeyUTZNameIdx ) {
			auto searchDictByUTZNameIdx = dictByUTZNameIdx->find( newKeyUTZNameIdx );
			if( searchDictByUTZNameIdx != dictByUTZNameIdx->end() ) {
				std::string Msg( "Duplicate key detected for index ISOTZoneUTZNameIdx " + newKeyUTZNameIdx.toString() );
				delete Buff;
				throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
					S_ProcName,
					Msg );
			}
		}

		// Validate foreign keys

		// Update is valid
		std::map<cfsec::CFSecISOTZonePKey, cfsec::CFSecISOTZoneBuff*>* subdict;
		auto removalDictByPKey = dictByPKey->find( pkey );
		if( removalDictByPKey != dictByPKey->end() ) {
			dictByPKey->erase( removalDictByPKey );
		}
		// Copy edited buffer to existing persistent buffer

		if( Buff->getClassCode() != cfsec::CFSecISOTZoneBuff::CLASS_CODE ) {
			const static std::string S_IsNotA( " is not a cfsec::CFSecISOTZoneBuff" );
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

		dictByPKey->insert( std::map<cfsec::CFSecISOTZonePKey, cfsec::CFSecISOTZoneBuff*>::value_type( pkey, existing ) );

		std::map<cfsec::CFSecISOTZonePKey,
			 cfsec::CFSecISOTZoneBuff*>* subdictOffsetIdx;
		auto searchDictByOffsetIdx = dictByOffsetIdx->find( existingKeyOffsetIdx );
		if( searchDictByOffsetIdx != dictByOffsetIdx->end() ) {
			subdictOffsetIdx = searchDictByOffsetIdx->second;
			auto searchSubDict = subdictOffsetIdx->find( pkey );
			if( searchSubDict != subdictOffsetIdx->end() ) {
				subdictOffsetIdx->erase( searchSubDict );
			}
			if( subdictOffsetIdx->size() <= 0 ) {
				delete subdictOffsetIdx;
				dictByOffsetIdx->erase( searchDictByOffsetIdx );
			}
			subdictOffsetIdx = NULL;
		}
		auto searchNewKeyDictByOffsetIdx = dictByOffsetIdx->find( newKeyOffsetIdx );
		if( searchNewKeyDictByOffsetIdx != dictByOffsetIdx->end() ) {
			subdictOffsetIdx = searchNewKeyDictByOffsetIdx->second;
		}
		else {
			subdictOffsetIdx = new std::map<cfsec::CFSecISOTZonePKey, cfsec::CFSecISOTZoneBuff*>();
			dictByOffsetIdx->insert( std::map<cfsec::CFSecISOTZoneByOffsetIdxKey,
				std::map<cfsec::CFSecISOTZonePKey,
					cfsec::CFSecISOTZoneBuff*>*>::value_type( newKeyOffsetIdx, subdictOffsetIdx ) );
		}
		subdictOffsetIdx->insert( std::map<cfsec::CFSecISOTZonePKey, cfsec::CFSecISOTZoneBuff*>::value_type( pkey, existing ) );

		auto removalDictByUTZNameIdx = dictByUTZNameIdx->find( existingKeyUTZNameIdx );
		if( removalDictByUTZNameIdx != dictByUTZNameIdx->end() ) {
			dictByUTZNameIdx->erase( removalDictByUTZNameIdx );
		}
		dictByUTZNameIdx->insert( std::map<cfsec::CFSecISOTZoneByUTZNameIdxKey, cfsec::CFSecISOTZoneBuff*>::value_type( newKeyUTZNameIdx, existing ) );

		std::map<cfsec::CFSecISOTZonePKey,
			 cfsec::CFSecISOTZoneBuff*>* subdictIso8601Idx;
		auto searchDictByIso8601Idx = dictByIso8601Idx->find( existingKeyIso8601Idx );
		if( searchDictByIso8601Idx != dictByIso8601Idx->end() ) {
			subdictIso8601Idx = searchDictByIso8601Idx->second;
			auto searchSubDict = subdictIso8601Idx->find( pkey );
			if( searchSubDict != subdictIso8601Idx->end() ) {
				subdictIso8601Idx->erase( searchSubDict );
			}
			if( subdictIso8601Idx->size() <= 0 ) {
				delete subdictIso8601Idx;
				dictByIso8601Idx->erase( searchDictByIso8601Idx );
			}
			subdictIso8601Idx = NULL;
		}
		auto searchNewKeyDictByIso8601Idx = dictByIso8601Idx->find( newKeyIso8601Idx );
		if( searchNewKeyDictByIso8601Idx != dictByIso8601Idx->end() ) {
			subdictIso8601Idx = searchNewKeyDictByIso8601Idx->second;
		}
		else {
			subdictIso8601Idx = new std::map<cfsec::CFSecISOTZonePKey, cfsec::CFSecISOTZoneBuff*>();
			dictByIso8601Idx->insert( std::map<cfsec::CFSecISOTZoneByIso8601IdxKey,
				std::map<cfsec::CFSecISOTZonePKey,
					cfsec::CFSecISOTZoneBuff*>*>::value_type( newKeyIso8601Idx, subdictIso8601Idx ) );
		}
		subdictIso8601Idx->insert( std::map<cfsec::CFSecISOTZonePKey, cfsec::CFSecISOTZoneBuff*>::value_type( pkey, existing ) );


		// The top level code has to clean up the memory buffer that was passed in, and return a clone
		// of the copy that existing buffer that is attached to the RAM storage.  All other cases
		// return the existing buffer.

		cfsec::CFSecISOTZoneBuff* buff;
		if( existing->getClassCode() == cfsec::CFSecISOTZoneBuff::CLASS_CODE ) {
			delete Buff;
			Buff = NULL;
			buff = dynamic_cast<cfsec::CFSecISOTZoneBuff*>( existing->clone() );
		}
		else {
			buff = existing;
		}
		return( buff );
	}

	void CFSecRamISOTZoneTable::deleteISOTZone( const cfsec::CFSecAuthorization* Authorization,
		cfsec::CFSecISOTZoneBuff* Buff )
	{
		static const std::string S_ProcName( "deleteISOTZone" );
		static const std::string S_Prev( "prev" );
		classcode_t classCode;
		cfsec::CFSecISOTZonePKey pkey;
		pkey.setRequiredISOTZoneId( Buff->getRequiredISOTZoneId() );
		auto searchExisting = dictByPKey->find( pkey );
		if( searchExisting == dictByPKey->end() ) {
			return;
		}
		cfsec::CFSecISOTZoneBuff* existing = searchExisting->second;
		cfsec::CFSecISOTZoneByOffsetIdxKey keyOffsetIdx;
		keyOffsetIdx.setRequiredTZHourOffset( existing->getRequiredTZHourOffset() );
		keyOffsetIdx.setRequiredTZMinOffset( existing->getRequiredTZMinOffset() );
		cfsec::CFSecISOTZoneByUTZNameIdxKey keyUTZNameIdx;
		keyUTZNameIdx.setRequiredTZName( existing->getRequiredTZName() );
		cfsec::CFSecISOTZoneByIso8601IdxKey keyIso8601Idx;
		keyIso8601Idx.setRequiredIso8601( existing->getRequiredIso8601() );
		// Validate reverse foreign keys

		// Delete is valid
		std::map<cfsec::CFSecISOTZonePKey, cfsec::CFSecISOTZoneBuff*>* subdict;

		auto searchDictByPKey = dictByPKey->find( pkey );
		if( searchDictByPKey != dictByPKey->end() ) {
			dictByPKey->erase( searchDictByPKey );
		}

		auto searchDictByOffsetIdx = dictByOffsetIdx->find( keyOffsetIdx );
		if( searchDictByOffsetIdx != dictByOffsetIdx->end() ) {
			std::map<cfsec::CFSecISOTZonePKey,
				 cfsec::CFSecISOTZoneBuff*>* subdictOffsetIdx = searchDictByOffsetIdx->second;
			auto searchSubDict = subdictOffsetIdx->find( pkey );
			if( searchSubDict != subdictOffsetIdx->end() ) {
				subdictOffsetIdx->erase( searchSubDict );
			}
			subdictOffsetIdx = NULL;
		}

		auto searchDictByUTZNameIdx = dictByUTZNameIdx->find( keyUTZNameIdx );
		if( searchDictByUTZNameIdx != dictByUTZNameIdx->end() ) {
			dictByUTZNameIdx->erase( searchDictByUTZNameIdx );
		}

		auto searchDictByIso8601Idx = dictByIso8601Idx->find( keyIso8601Idx );
		if( searchDictByIso8601Idx != dictByIso8601Idx->end() ) {
			std::map<cfsec::CFSecISOTZonePKey,
				 cfsec::CFSecISOTZoneBuff*>* subdictIso8601Idx = searchDictByIso8601Idx->second;
			auto searchSubDict = subdictIso8601Idx->find( pkey );
			if( searchSubDict != subdictIso8601Idx->end() ) {
				subdictIso8601Idx->erase( searchSubDict );
			}
			subdictIso8601Idx = NULL;
		}

		if( existing != NULL ) {
			delete existing;
			existing = NULL;
		}
	}

	void CFSecRamISOTZoneTable::deleteISOTZoneByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t argISOTZoneId )
	{
		cfsec::CFSecISOTZonePKey key;
		key.setRequiredISOTZoneId( argISOTZoneId );
		deleteISOTZoneByIdIdx( Authorization, &key );
	}

	void CFSecRamISOTZoneTable::deleteISOTZoneByIdIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecISOTZonePKey* argKey )
	{
		bool anyNotNull = false;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		cfsec::CFSecISOTZoneBuff* cur = NULL;
		cfsec::CFSecISOTZoneBuff* rereadCur = NULL;
		std::TCFLibOwningVector<cfsec::CFSecISOTZoneBuff*> matchSet;
		std::map<cfsec::CFSecISOTZonePKey,
			cfsec::CFSecISOTZoneBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecISOTZonePKey,
			cfsec::CFSecISOTZoneBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecISOTZoneBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecISOTZoneBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecISOTZoneBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecISOTZoneBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableISOTZone()->readDerivedByIdIdx( Authorization,
				cur->getRequiredISOTZoneId() );
			rereadCur = cur;
			deleteISOTZone( Authorization, cur );
			if( rereadCur != NULL ) {
				delete rereadCur;
				rereadCur = NULL;
			}
		}
	}

	void CFSecRamISOTZoneTable::deleteISOTZoneByOffsetIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t argTZHourOffset,
			const int16_t argTZMinOffset )
	{
		cfsec::CFSecISOTZoneByOffsetIdxKey key;
		key.setRequiredTZHourOffset( argTZHourOffset );
		key.setRequiredTZMinOffset( argTZMinOffset );
		deleteISOTZoneByOffsetIdx( Authorization, &key );
	}

	void CFSecRamISOTZoneTable::deleteISOTZoneByOffsetIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecISOTZoneByOffsetIdxKey* argKey )
	{
		cfsec::CFSecISOTZoneBuff* cur = NULL;
		cfsec::CFSecISOTZoneBuff* rereadCur = NULL;
		bool anyNotNull = false;
		anyNotNull = true;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfsec::CFSecISOTZoneBuff*> matchSet;
		std::map<cfsec::CFSecISOTZonePKey,
			cfsec::CFSecISOTZoneBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecISOTZonePKey,
			cfsec::CFSecISOTZoneBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecISOTZoneBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecISOTZoneBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecISOTZoneBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecISOTZoneBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableISOTZone()->readDerivedByIdIdx( Authorization,
				cur->getRequiredISOTZoneId() );
			rereadCur = cur;
			deleteISOTZone( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFSecRamISOTZoneTable::deleteISOTZoneByUTZNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& argTZName )
	{
		cfsec::CFSecISOTZoneByUTZNameIdxKey key;
		key.setRequiredTZName( argTZName );
		deleteISOTZoneByUTZNameIdx( Authorization, &key );
	}

	void CFSecRamISOTZoneTable::deleteISOTZoneByUTZNameIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecISOTZoneByUTZNameIdxKey* argKey )
	{
		cfsec::CFSecISOTZoneBuff* cur = NULL;
		cfsec::CFSecISOTZoneBuff* rereadCur = NULL;
		bool anyNotNull = false;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfsec::CFSecISOTZoneBuff*> matchSet;
		std::map<cfsec::CFSecISOTZonePKey,
			cfsec::CFSecISOTZoneBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecISOTZonePKey,
			cfsec::CFSecISOTZoneBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecISOTZoneBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecISOTZoneBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecISOTZoneBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecISOTZoneBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableISOTZone()->readDerivedByIdIdx( Authorization,
				cur->getRequiredISOTZoneId() );
			rereadCur = cur;
			deleteISOTZone( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFSecRamISOTZoneTable::deleteISOTZoneByIso8601Idx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& argIso8601 )
	{
		cfsec::CFSecISOTZoneByIso8601IdxKey key;
		key.setRequiredIso8601( argIso8601 );
		deleteISOTZoneByIso8601Idx( Authorization, &key );
	}

	void CFSecRamISOTZoneTable::deleteISOTZoneByIso8601Idx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecISOTZoneByIso8601IdxKey* argKey )
	{
		cfsec::CFSecISOTZoneBuff* cur = NULL;
		cfsec::CFSecISOTZoneBuff* rereadCur = NULL;
		bool anyNotNull = false;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfsec::CFSecISOTZoneBuff*> matchSet;
		std::map<cfsec::CFSecISOTZonePKey,
			cfsec::CFSecISOTZoneBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecISOTZonePKey,
			cfsec::CFSecISOTZoneBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecISOTZoneBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecISOTZoneBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecISOTZoneBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecISOTZoneBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableISOTZone()->readDerivedByIdIdx( Authorization,
				cur->getRequiredISOTZoneId() );
			rereadCur = cur;
			deleteISOTZone( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFSecRamISOTZoneTable::releasePreparedStatements() {
	}

}
