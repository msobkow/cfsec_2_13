#pragma once

// Description: C++18 DbIO interface for ISOTZone.

/*
 *	com.github.msobkow.CFSec
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
#include <cfsec/CFSecAuthorization.hpp>
#include <cfsec/CFSecHPKey.hpp>
#include <cfsec/CFSecISOTZoneBuff.hpp>
#include <cfsec/CFSecISOTZonePKey.hpp>
#include <cfsec/CFSecISOTZoneHBuff.hpp>
#include <cfsec/CFSecISOTZoneHPKey.hpp>
#include <cfsec/CFSecISOTZoneByOffsetIdxKey.hpp>
#include <cfsec/CFSecISOTZoneByUTZNameIdxKey.hpp>
#include <cfsec/CFSecISOTZoneByIso8601IdxKey.hpp>

namespace cfsec {
	class ICFSecSchemaObj;
}

namespace cfsec {
	class ICFSecISOTZoneObj;

	class ICFSecISOTZoneTable
	{
	public:
		ICFSecISOTZoneTable();
		virtual ~ICFSecISOTZoneTable();

		virtual cfsec::CFSecISOTZoneBuff* createISOTZone( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecISOTZoneBuff* Buff ) = 0;

		virtual cfsec::CFSecISOTZoneBuff* updateISOTZone( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecISOTZoneBuff* Buff ) = 0;

		virtual void deleteISOTZone( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecISOTZoneBuff* Buff ) = 0;
		virtual void deleteISOTZoneByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t argISOTZoneId ) = 0;

		virtual void deleteISOTZoneByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOTZonePKey* argKey ) = 0;
		virtual void deleteISOTZoneByOffsetIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t argTZHourOffset,
			const int16_t argTZMinOffset ) = 0;

		virtual void deleteISOTZoneByOffsetIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOTZoneByOffsetIdxKey* argKey ) = 0;
		virtual void deleteISOTZoneByUTZNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& argTZName ) = 0;

		virtual void deleteISOTZoneByUTZNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOTZoneByUTZNameIdxKey* argKey ) = 0;
		virtual void deleteISOTZoneByIso8601Idx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& argIso8601 ) = 0;

		virtual void deleteISOTZoneByIso8601Idx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOTZoneByIso8601IdxKey* argKey ) = 0;

		virtual cfsec::CFSecISOTZoneBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOTZonePKey* PKey ) = 0;

		virtual cfsec::CFSecISOTZoneBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOTZonePKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecISOTZoneBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual cfsec::CFSecISOTZoneBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t ISOTZoneId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecISOTZoneBuff*> readDerivedByOffsetIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t TZHourOffset,
			const int16_t TZMinOffset ) = 0;

		virtual cfsec::CFSecISOTZoneBuff* readDerivedByUTZNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& TZName ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecISOTZoneBuff*> readDerivedByIso8601Idx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& Iso8601 ) = 0;

		virtual cfsec::CFSecISOTZoneBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOTZonePKey* PKey ) = 0;

		virtual cfsec::CFSecISOTZoneBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOTZonePKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecISOTZoneBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual cfsec::CFSecISOTZoneBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t ISOTZoneId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecISOTZoneBuff*> readBuffByOffsetIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t TZHourOffset,
			const int16_t TZMinOffset ) = 0;

		virtual cfsec::CFSecISOTZoneBuff* readBuffByUTZNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& TZName ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecISOTZoneBuff*> readBuffByIso8601Idx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& Iso8601 ) = 0;

		virtual cfsec::CFSecISOTZoneBuff* readBuffByLookupUTZNameIdx( const cfsec::CFSecAuthorization* Authorization, const std::string& TZName,
			bool forceRead = false ) = 0;

		virtual cfsec::CFSecISOTZoneBuff* readDerivedByLookupUTZNameIdx( const cfsec::CFSecAuthorization* Authorization, const std::string& TZName,
			bool forceRead = false ) = 0;

		virtual void releasePreparedStatements() = 0;
	};
}
