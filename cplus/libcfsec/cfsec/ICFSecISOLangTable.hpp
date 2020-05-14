#pragma once

// Description: C++18 DbIO interface for ISOLang.

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
