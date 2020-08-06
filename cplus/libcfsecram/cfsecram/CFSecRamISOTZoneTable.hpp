#pragma once

// Description: C++18 Interface for an in-memory RAM DbIO declementation for ISOTZone.

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
