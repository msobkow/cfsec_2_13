#pragma once

// Description: C++18 Interface for an in-memory RAM DbIO declementation for ISOCtry.

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

	class CFSecRamISOCtryTable
	: public virtual cfsec::ICFSecISOCtryTable
	{
	protected:
		cfsec::ICFSecSchema* schema;
		std::map<cfsec::CFSecISOCtryPKey,
			cfsec::CFSecISOCtryBuff*>* dictByPKey;
		std::map<cfsec::CFSecISOCtryByISOCodeIdxKey,
			cfsec::CFSecISOCtryBuff*>* dictByISOCodeIdx;
		std::map<cfsec::CFSecISOCtryByNameIdxKey,
			cfsec::CFSecISOCtryBuff*>* dictByNameIdx;
	public:
		static const std::string CLASS_NAME;
		CFSecRamISOCtryTable( cfsec::ICFSecSchema* argSchema );

		virtual ~CFSecRamISOCtryTable();

		virtual cfsec::CFSecISOCtryBuff* createISOCtry( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecISOCtryBuff* Buff );

		virtual cfsec::CFSecISOCtryBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCtryPKey* PKey );

		virtual cfsec::CFSecISOCtryBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCtryPKey* PKey );

		virtual std::TCFLibOwningVector<cfsec::CFSecISOCtryBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization );

		virtual cfsec::CFSecISOCtryBuff* readDerivedByISOCodeIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& ISOCode );

		virtual cfsec::CFSecISOCtryBuff* readDerivedByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& Name );

		virtual cfsec::CFSecISOCtryBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t ISOCtryId );

		virtual cfsec::CFSecISOCtryBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCtryPKey* PKey );

		virtual cfsec::CFSecISOCtryBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCtryPKey* PKey );

		virtual std::TCFLibOwningVector<cfsec::CFSecISOCtryBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization );

		virtual cfsec::CFSecISOCtryBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t ISOCtryId );

		virtual cfsec::CFSecISOCtryBuff* readBuffByISOCodeIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& ISOCode );

		virtual cfsec::CFSecISOCtryBuff* readBuffByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& Name );

		virtual cfsec::CFSecISOCtryBuff* readBuffByLookupISOCodeIdx( const cfsec::CFSecAuthorization* Authorization, const std::string& ISOCode,
			bool forceRead = false );

		virtual cfsec::CFSecISOCtryBuff* readDerivedByLookupISOCodeIdx( const cfsec::CFSecAuthorization* Authorization, const std::string& ISOCode,
			bool forceRead = false );

		virtual cfsec::CFSecISOCtryBuff* updateISOCtry( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecISOCtryBuff* Buff );

		virtual void deleteISOCtry( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecISOCtryBuff* Buff );
		virtual void deleteISOCtryByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t argISOCtryId );

		virtual void deleteISOCtryByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCtryPKey* argKey );

		virtual void deleteISOCtryByISOCodeIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& argISOCode );

		virtual void deleteISOCtryByISOCodeIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCtryByISOCodeIdxKey* argKey );

		virtual void deleteISOCtryByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& argName );

		virtual void deleteISOCtryByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCtryByNameIdxKey* argKey );


		virtual void releasePreparedStatements();

	};
}
