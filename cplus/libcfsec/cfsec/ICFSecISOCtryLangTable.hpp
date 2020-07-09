#pragma once

// Description: C++18 DbIO interface for ISOCtryLang.

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
