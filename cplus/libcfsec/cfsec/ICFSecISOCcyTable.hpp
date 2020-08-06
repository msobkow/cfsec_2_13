#pragma once

// Description: C++18 DbIO interface for ISOCcy.

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
#include <cfsec/CFSecAuthorization.hpp>
#include <cfsec/CFSecHPKey.hpp>
#include <cfsec/CFSecISOCcyBuff.hpp>
#include <cfsec/CFSecISOCcyPKey.hpp>
#include <cfsec/CFSecISOCcyHBuff.hpp>
#include <cfsec/CFSecISOCcyHPKey.hpp>
#include <cfsec/CFSecISOCcyByCcyCdIdxKey.hpp>
#include <cfsec/CFSecISOCcyByCcyNmIdxKey.hpp>

namespace cfsec {
	class ICFSecSchemaObj;
}

namespace cfsec {
	class ICFSecISOCcyObj;

	class ICFSecISOCcyTable
	{
	public:
		ICFSecISOCcyTable();
		virtual ~ICFSecISOCcyTable();

		virtual cfsec::CFSecISOCcyBuff* createISOCcy( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecISOCcyBuff* Buff ) = 0;

		virtual cfsec::CFSecISOCcyBuff* updateISOCcy( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecISOCcyBuff* Buff ) = 0;

		virtual void deleteISOCcy( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecISOCcyBuff* Buff ) = 0;
		virtual void deleteISOCcyByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t argISOCcyId ) = 0;

		virtual void deleteISOCcyByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCcyPKey* argKey ) = 0;
		virtual void deleteISOCcyByCcyCdIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& argISOCode ) = 0;

		virtual void deleteISOCcyByCcyCdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCcyByCcyCdIdxKey* argKey ) = 0;
		virtual void deleteISOCcyByCcyNmIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& argName ) = 0;

		virtual void deleteISOCcyByCcyNmIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCcyByCcyNmIdxKey* argKey ) = 0;

		virtual cfsec::CFSecISOCcyBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCcyPKey* PKey ) = 0;

		virtual cfsec::CFSecISOCcyBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCcyPKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecISOCcyBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual cfsec::CFSecISOCcyBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t ISOCcyId ) = 0;

		virtual cfsec::CFSecISOCcyBuff* readDerivedByCcyCdIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& ISOCode ) = 0;

		virtual cfsec::CFSecISOCcyBuff* readDerivedByCcyNmIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& Name ) = 0;

		virtual cfsec::CFSecISOCcyBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCcyPKey* PKey ) = 0;

		virtual cfsec::CFSecISOCcyBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCcyPKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecISOCcyBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual cfsec::CFSecISOCcyBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t ISOCcyId ) = 0;

		virtual cfsec::CFSecISOCcyBuff* readBuffByCcyCdIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& ISOCode ) = 0;

		virtual cfsec::CFSecISOCcyBuff* readBuffByCcyNmIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& Name ) = 0;

		virtual cfsec::CFSecISOCcyBuff* readBuffByLookupCcyCdIdx( const cfsec::CFSecAuthorization* Authorization, const std::string& ISOCode,
			bool forceRead = false ) = 0;

		virtual cfsec::CFSecISOCcyBuff* readDerivedByLookupCcyCdIdx( const cfsec::CFSecAuthorization* Authorization, const std::string& ISOCode,
			bool forceRead = false ) = 0;

		virtual void releasePreparedStatements() = 0;
	};
}
