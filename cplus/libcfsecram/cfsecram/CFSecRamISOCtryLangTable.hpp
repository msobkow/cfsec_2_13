#pragma once

// Description: C++18 Interface for an in-memory RAM DbIO declementation for ISOCtryLang.

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
#include <cfsec/ICFSecPublic.hpp>
#include <cfsecobj/ICFSecObjPublic.hpp>
#include <cfsecsaxloader/CFSecSaxLoader.hpp>

namespace cfsec {

	class CFSecRamISOCtryLangTable
	: public virtual cfsec::ICFSecISOCtryLangTable
	{
	protected:
		cfsec::ICFSecSchema* schema;
		std::map<cfsec::CFSecISOCtryLangPKey,
			cfsec::CFSecISOCtryLangBuff*>* dictByPKey;
		std::map<cfsec::CFSecISOCtryLangByCtryIdxKey,
			std::map<cfsec::CFSecISOCtryLangPKey,
				cfsec::CFSecISOCtryLangBuff*>*>* dictByCtryIdx;
		std::map<cfsec::CFSecISOCtryLangByLangIdxKey,
			std::map<cfsec::CFSecISOCtryLangPKey,
				cfsec::CFSecISOCtryLangBuff*>*>* dictByLangIdx;
	public:
		static const std::string CLASS_NAME;
		CFSecRamISOCtryLangTable( cfsec::ICFSecSchema* argSchema );

		virtual ~CFSecRamISOCtryLangTable();

		virtual cfsec::CFSecISOCtryLangBuff* createISOCtryLang( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecISOCtryLangBuff* Buff );

		virtual cfsec::CFSecISOCtryLangBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCtryLangPKey* PKey );

		virtual cfsec::CFSecISOCtryLangBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCtryLangPKey* PKey );

		virtual std::TCFLibOwningVector<cfsec::CFSecISOCtryLangBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization );

		virtual std::TCFLibOwningVector<cfsec::CFSecISOCtryLangBuff*> readDerivedByCtryIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t ISOCtryId );

		virtual std::TCFLibOwningVector<cfsec::CFSecISOCtryLangBuff*> readDerivedByLangIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t ISOLangId );

		virtual cfsec::CFSecISOCtryLangBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t ISOCtryId,
			const int16_t ISOLangId );

		virtual cfsec::CFSecISOCtryLangBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCtryLangPKey* PKey );

		virtual cfsec::CFSecISOCtryLangBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCtryLangPKey* PKey );

		virtual std::TCFLibOwningVector<cfsec::CFSecISOCtryLangBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization );

		virtual cfsec::CFSecISOCtryLangBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t ISOCtryId,
			const int16_t ISOLangId );

		virtual std::TCFLibOwningVector<cfsec::CFSecISOCtryLangBuff*> readBuffByCtryIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t ISOCtryId );

		virtual std::TCFLibOwningVector<cfsec::CFSecISOCtryLangBuff*> readBuffByLangIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t ISOLangId );

		virtual cfsec::CFSecISOCtryLangBuff* updateISOCtryLang( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecISOCtryLangBuff* Buff );

		virtual void deleteISOCtryLang( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecISOCtryLangBuff* Buff );
		virtual void deleteISOCtryLangByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t argISOCtryId,
			const int16_t argISOLangId );

		virtual void deleteISOCtryLangByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCtryLangPKey* argKey );

		virtual void deleteISOCtryLangByCtryIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t argISOCtryId );

		virtual void deleteISOCtryLangByCtryIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCtryLangByCtryIdxKey* argKey );

		virtual void deleteISOCtryLangByLangIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t argISOLangId );

		virtual void deleteISOCtryLangByLangIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCtryLangByLangIdxKey* argKey );


		virtual void releasePreparedStatements();

	};
}
