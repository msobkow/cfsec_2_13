#pragma once

// Description: C++18 DbIO interface for ISOLang.

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
#include <cfsec/CFSecISOLangBuff.hpp>
#include <cfsec/CFSecISOLangPKey.hpp>
#include <cfsec/CFSecISOLangHBuff.hpp>
#include <cfsec/CFSecISOLangHPKey.hpp>
#include <cfsec/CFSecISOLangByCode3IdxKey.hpp>
#include <cfsec/CFSecISOLangByCode2IdxKey.hpp>

namespace cfsec {
	class ICFSecSchemaObj;
}

namespace cfsec {
	class ICFSecISOLangObj;

	class ICFSecISOLangTable
	{
	public:
		ICFSecISOLangTable();
		virtual ~ICFSecISOLangTable();

		virtual cfsec::CFSecISOLangBuff* createISOLang( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecISOLangBuff* Buff ) = 0;

		virtual cfsec::CFSecISOLangBuff* updateISOLang( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecISOLangBuff* Buff ) = 0;

		virtual void deleteISOLang( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecISOLangBuff* Buff ) = 0;
		virtual void deleteISOLangByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t argISOLangId ) = 0;

		virtual void deleteISOLangByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOLangPKey* argKey ) = 0;
		virtual void deleteISOLangByCode3Idx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& argISO6392Code ) = 0;

		virtual void deleteISOLangByCode3Idx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOLangByCode3IdxKey* argKey ) = 0;
		virtual void deleteISOLangByCode2Idx( const cfsec::CFSecAuthorization* Authorization,
			const std::string* argISO6391Code ) = 0;

		virtual void deleteISOLangByCode2Idx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOLangByCode2IdxKey* argKey ) = 0;

		virtual cfsec::CFSecISOLangBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOLangPKey* PKey ) = 0;

		virtual cfsec::CFSecISOLangBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOLangPKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecISOLangBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual cfsec::CFSecISOLangBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t ISOLangId ) = 0;

		virtual cfsec::CFSecISOLangBuff* readDerivedByCode3Idx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& ISO6392Code ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecISOLangBuff*> readDerivedByCode2Idx( const cfsec::CFSecAuthorization* Authorization,
			const std::string* ISO6391Code ) = 0;

		virtual cfsec::CFSecISOLangBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOLangPKey* PKey ) = 0;

		virtual cfsec::CFSecISOLangBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOLangPKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecISOLangBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual cfsec::CFSecISOLangBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t ISOLangId ) = 0;

		virtual cfsec::CFSecISOLangBuff* readBuffByCode3Idx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& ISO6392Code ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecISOLangBuff*> readBuffByCode2Idx( const cfsec::CFSecAuthorization* Authorization,
			const std::string* ISO6391Code ) = 0;

		virtual cfsec::CFSecISOLangBuff* readBuffByLookupCode3Idx( const cfsec::CFSecAuthorization* Authorization, const std::string& ISO6392Code,
			bool forceRead = false ) = 0;

		virtual cfsec::CFSecISOLangBuff* readDerivedByLookupCode3Idx( const cfsec::CFSecAuthorization* Authorization, const std::string& ISO6392Code,
			bool forceRead = false ) = 0;

		virtual void releasePreparedStatements() = 0;
	};
}
