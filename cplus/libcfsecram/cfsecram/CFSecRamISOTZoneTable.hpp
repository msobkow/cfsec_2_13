#pragma once

// Description: C++18 Interface for an in-memory RAM DbIO declementation for ISOTZone.

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
#include <cfsecobj/ICFSecObjPublic.hpp>
#include <cfsecsaxloader/CFSecSaxLoader.hpp>

namespace cfsec {

	class CFSecRamISOTZoneTable
	: public virtual cfsec::ICFSecISOTZoneTable
	{
	protected:
		cfsec::ICFSecSchema* schema;
		std::map<cfsec::CFSecISOTZonePKey,
			cfsec::CFSecISOTZoneBuff*>* dictByPKey;
		std::map<cfsec::CFSecISOTZoneByOffsetIdxKey,
			std::map<cfsec::CFSecISOTZonePKey,
				cfsec::CFSecISOTZoneBuff*>*>* dictByOffsetIdx;
		std::map<cfsec::CFSecISOTZoneByUTZNameIdxKey,
			cfsec::CFSecISOTZoneBuff*>* dictByUTZNameIdx;
		std::map<cfsec::CFSecISOTZoneByIso8601IdxKey,
			std::map<cfsec::CFSecISOTZonePKey,
				cfsec::CFSecISOTZoneBuff*>*>* dictByIso8601Idx;
	public:
		static const std::string CLASS_NAME;
		CFSecRamISOTZoneTable( cfsec::ICFSecSchema* argSchema );

		virtual ~CFSecRamISOTZoneTable();

		virtual cfsec::CFSecISOTZoneBuff* createISOTZone( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecISOTZoneBuff* Buff );

		virtual cfsec::CFSecISOTZoneBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOTZonePKey* PKey );

		virtual cfsec::CFSecISOTZoneBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOTZonePKey* PKey );

		virtual std::TCFLibOwningVector<cfsec::CFSecISOTZoneBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization );

		virtual std::TCFLibOwningVector<cfsec::CFSecISOTZoneBuff*> readDerivedByOffsetIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t TZHourOffset,
			const int16_t TZMinOffset );

		virtual cfsec::CFSecISOTZoneBuff* readDerivedByUTZNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& TZName );

		virtual std::TCFLibOwningVector<cfsec::CFSecISOTZoneBuff*> readDerivedByIso8601Idx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& Iso8601 );

		virtual cfsec::CFSecISOTZoneBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t ISOTZoneId );

		virtual cfsec::CFSecISOTZoneBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOTZonePKey* PKey );

		virtual cfsec::CFSecISOTZoneBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOTZonePKey* PKey );

		virtual std::TCFLibOwningVector<cfsec::CFSecISOTZoneBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization );

		virtual cfsec::CFSecISOTZoneBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t ISOTZoneId );

		virtual std::TCFLibOwningVector<cfsec::CFSecISOTZoneBuff*> readBuffByOffsetIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t TZHourOffset,
			const int16_t TZMinOffset );

		virtual cfsec::CFSecISOTZoneBuff* readBuffByUTZNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& TZName );

		virtual std::TCFLibOwningVector<cfsec::CFSecISOTZoneBuff*> readBuffByIso8601Idx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& Iso8601 );

		virtual cfsec::CFSecISOTZoneBuff* readBuffByLookupUTZNameIdx( const cfsec::CFSecAuthorization* Authorization, const std::string& TZName,
			bool forceRead = false );

		virtual cfsec::CFSecISOTZoneBuff* readDerivedByLookupUTZNameIdx( const cfsec::CFSecAuthorization* Authorization, const std::string& TZName,
			bool forceRead = false );

		virtual cfsec::CFSecISOTZoneBuff* updateISOTZone( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecISOTZoneBuff* Buff );

		virtual void deleteISOTZone( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecISOTZoneBuff* Buff );
		virtual void deleteISOTZoneByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t argISOTZoneId );

		virtual void deleteISOTZoneByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOTZonePKey* argKey );

		virtual void deleteISOTZoneByOffsetIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t argTZHourOffset,
			const int16_t argTZMinOffset );

		virtual void deleteISOTZoneByOffsetIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOTZoneByOffsetIdxKey* argKey );

		virtual void deleteISOTZoneByUTZNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& argTZName );

		virtual void deleteISOTZoneByUTZNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOTZoneByUTZNameIdxKey* argKey );

		virtual void deleteISOTZoneByIso8601Idx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& argIso8601 );

		virtual void deleteISOTZoneByIso8601Idx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOTZoneByIso8601IdxKey* argKey );


		virtual void releasePreparedStatements();

	};
}
