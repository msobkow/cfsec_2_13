#pragma once

// Description: C++18 DbIO interface for ISOCtry.

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
#include <cfsec/CFSecAuthorization.hpp>
#include <cfsec/CFSecHPKey.hpp>
#include <cfsec/CFSecISOCtryBuff.hpp>
#include <cfsec/CFSecISOCtryPKey.hpp>
#include <cfsec/CFSecISOCtryHBuff.hpp>
#include <cfsec/CFSecISOCtryHPKey.hpp>
#include <cfsec/CFSecISOCtryByISOCodeIdxKey.hpp>
#include <cfsec/CFSecISOCtryByNameIdxKey.hpp>

namespace cfsec {
	class ICFSecSchemaObj;
}

namespace cfsec {
	class ICFSecISOCtryObj;

	class ICFSecISOCtryTable
	{
	public:
		ICFSecISOCtryTable();
		virtual ~ICFSecISOCtryTable();

		virtual cfsec::CFSecISOCtryBuff* createISOCtry( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecISOCtryBuff* Buff ) = 0;

		virtual cfsec::CFSecISOCtryBuff* updateISOCtry( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecISOCtryBuff* Buff ) = 0;

		virtual void deleteISOCtry( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecISOCtryBuff* Buff ) = 0;
		virtual void deleteISOCtryByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t argISOCtryId ) = 0;

		virtual void deleteISOCtryByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCtryPKey* argKey ) = 0;
		virtual void deleteISOCtryByISOCodeIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& argISOCode ) = 0;

		virtual void deleteISOCtryByISOCodeIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCtryByISOCodeIdxKey* argKey ) = 0;
		virtual void deleteISOCtryByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& argName ) = 0;

		virtual void deleteISOCtryByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCtryByNameIdxKey* argKey ) = 0;

		virtual cfsec::CFSecISOCtryBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCtryPKey* PKey ) = 0;

		virtual cfsec::CFSecISOCtryBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCtryPKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecISOCtryBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual cfsec::CFSecISOCtryBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t ISOCtryId ) = 0;

		virtual cfsec::CFSecISOCtryBuff* readDerivedByISOCodeIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& ISOCode ) = 0;

		virtual cfsec::CFSecISOCtryBuff* readDerivedByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& Name ) = 0;

		virtual cfsec::CFSecISOCtryBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCtryPKey* PKey ) = 0;

		virtual cfsec::CFSecISOCtryBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCtryPKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecISOCtryBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual cfsec::CFSecISOCtryBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t ISOCtryId ) = 0;

		virtual cfsec::CFSecISOCtryBuff* readBuffByISOCodeIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& ISOCode ) = 0;

		virtual cfsec::CFSecISOCtryBuff* readBuffByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& Name ) = 0;

		virtual cfsec::CFSecISOCtryBuff* readBuffByLookupISOCodeIdx( const cfsec::CFSecAuthorization* Authorization, const std::string& ISOCode,
			bool forceRead = false ) = 0;

		virtual cfsec::CFSecISOCtryBuff* readDerivedByLookupISOCodeIdx( const cfsec::CFSecAuthorization* Authorization, const std::string& ISOCode,
			bool forceRead = false ) = 0;

		virtual void releasePreparedStatements() = 0;
	};
}
