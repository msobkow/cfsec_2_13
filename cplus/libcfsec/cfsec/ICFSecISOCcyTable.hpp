#pragma once

// Description: C++18 DbIO interface for ISOCcy.

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
