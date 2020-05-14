#pragma once

// Description: C++18 DbIO interface for ISOCtry.

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
