#pragma once

// Description: C++18 DbIO interface for ISOCtryLang.

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
#include <cfsec/CFSecISOCtryLangBuff.hpp>
#include <cfsec/CFSecISOCtryLangPKey.hpp>
#include <cfsec/CFSecISOCtryLangHBuff.hpp>
#include <cfsec/CFSecISOCtryLangHPKey.hpp>
#include <cfsec/CFSecISOCtryLangByCtryIdxKey.hpp>
#include <cfsec/CFSecISOCtryLangByLangIdxKey.hpp>

namespace cfsec {
	class ICFSecSchemaObj;
}

namespace cfsec {
	class ICFSecISOCtryLangObj;

	class ICFSecISOCtryLangTable
	{
	public:
		ICFSecISOCtryLangTable();
		virtual ~ICFSecISOCtryLangTable();

		virtual cfsec::CFSecISOCtryLangBuff* createISOCtryLang( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecISOCtryLangBuff* Buff ) = 0;

		virtual cfsec::CFSecISOCtryLangBuff* updateISOCtryLang( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecISOCtryLangBuff* Buff ) = 0;

		virtual void deleteISOCtryLang( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecISOCtryLangBuff* Buff ) = 0;
		virtual void deleteISOCtryLangByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t argISOCtryId,
			const int16_t argISOLangId ) = 0;

		virtual void deleteISOCtryLangByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCtryLangPKey* argKey ) = 0;
		virtual void deleteISOCtryLangByCtryIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t argISOCtryId ) = 0;

		virtual void deleteISOCtryLangByCtryIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCtryLangByCtryIdxKey* argKey ) = 0;
		virtual void deleteISOCtryLangByLangIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t argISOLangId ) = 0;

		virtual void deleteISOCtryLangByLangIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCtryLangByLangIdxKey* argKey ) = 0;

		virtual cfsec::CFSecISOCtryLangBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCtryLangPKey* PKey ) = 0;

		virtual cfsec::CFSecISOCtryLangBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCtryLangPKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecISOCtryLangBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual cfsec::CFSecISOCtryLangBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t ISOCtryId,
			const int16_t ISOLangId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecISOCtryLangBuff*> readDerivedByCtryIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t ISOCtryId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecISOCtryLangBuff*> readDerivedByLangIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t ISOLangId ) = 0;

		virtual cfsec::CFSecISOCtryLangBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCtryLangPKey* PKey ) = 0;

		virtual cfsec::CFSecISOCtryLangBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCtryLangPKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecISOCtryLangBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual cfsec::CFSecISOCtryLangBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t ISOCtryId,
			const int16_t ISOLangId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecISOCtryLangBuff*> readBuffByCtryIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t ISOCtryId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecISOCtryLangBuff*> readBuffByLangIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t ISOLangId ) = 0;

		virtual void releasePreparedStatements() = 0;
	};
}
