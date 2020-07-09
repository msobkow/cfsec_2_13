#pragma once

// Description: C++18 DbIO interface for ISOCtryCcy.

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
#include <cfsec/CFSecISOCtryCcyBuff.hpp>
#include <cfsec/CFSecISOCtryCcyPKey.hpp>
#include <cfsec/CFSecISOCtryCcyHBuff.hpp>
#include <cfsec/CFSecISOCtryCcyHPKey.hpp>
#include <cfsec/CFSecISOCtryCcyByCtryIdxKey.hpp>
#include <cfsec/CFSecISOCtryCcyByCcyIdxKey.hpp>

namespace cfsec {
	class ICFSecSchemaObj;
}

namespace cfsec {
	class ICFSecISOCtryCcyObj;

	class ICFSecISOCtryCcyTable
	{
	public:
		ICFSecISOCtryCcyTable();
		virtual ~ICFSecISOCtryCcyTable();

		virtual cfsec::CFSecISOCtryCcyBuff* createISOCtryCcy( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecISOCtryCcyBuff* Buff ) = 0;

		virtual cfsec::CFSecISOCtryCcyBuff* updateISOCtryCcy( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecISOCtryCcyBuff* Buff ) = 0;

		virtual void deleteISOCtryCcy( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecISOCtryCcyBuff* Buff ) = 0;
		virtual void deleteISOCtryCcyByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t argISOCtryId,
			const int16_t argISOCcyId ) = 0;

		virtual void deleteISOCtryCcyByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCtryCcyPKey* argKey ) = 0;
		virtual void deleteISOCtryCcyByCtryIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t argISOCtryId ) = 0;

		virtual void deleteISOCtryCcyByCtryIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCtryCcyByCtryIdxKey* argKey ) = 0;
		virtual void deleteISOCtryCcyByCcyIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t argISOCcyId ) = 0;

		virtual void deleteISOCtryCcyByCcyIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCtryCcyByCcyIdxKey* argKey ) = 0;

		virtual cfsec::CFSecISOCtryCcyBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCtryCcyPKey* PKey ) = 0;

		virtual cfsec::CFSecISOCtryCcyBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCtryCcyPKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecISOCtryCcyBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual cfsec::CFSecISOCtryCcyBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t ISOCtryId,
			const int16_t ISOCcyId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecISOCtryCcyBuff*> readDerivedByCtryIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t ISOCtryId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecISOCtryCcyBuff*> readDerivedByCcyIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t ISOCcyId ) = 0;

		virtual cfsec::CFSecISOCtryCcyBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCtryCcyPKey* PKey ) = 0;

		virtual cfsec::CFSecISOCtryCcyBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCtryCcyPKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecISOCtryCcyBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual cfsec::CFSecISOCtryCcyBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t ISOCtryId,
			const int16_t ISOCcyId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecISOCtryCcyBuff*> readBuffByCtryIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t ISOCtryId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecISOCtryCcyBuff*> readBuffByCcyIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t ISOCcyId ) = 0;

		virtual void releasePreparedStatements() = 0;
	};
}
