#pragma once

// Description: C++18 Interface for an in-memory RAM DbIO declementation for ISOLang.

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
#include <cfsec/ICFSecPublic.hpp>
#include <cfsecobj/ICFSecObjPublic.hpp>
#include <cfsecsaxloader/CFSecSaxLoader.hpp>

namespace cfsec {

	class CFSecRamISOLangTable
	: public virtual cfsec::ICFSecISOLangTable
	{
	protected:
		cfsec::ICFSecSchema* schema;
		std::map<cfsec::CFSecISOLangPKey,
			cfsec::CFSecISOLangBuff*>* dictByPKey;
		std::map<cfsec::CFSecISOLangByCode3IdxKey,
			cfsec::CFSecISOLangBuff*>* dictByCode3Idx;
		std::map<cfsec::CFSecISOLangByCode2IdxKey,
			std::map<cfsec::CFSecISOLangPKey,
				cfsec::CFSecISOLangBuff*>*>* dictByCode2Idx;
	public:
		static const std::string CLASS_NAME;
		CFSecRamISOLangTable( cfsec::ICFSecSchema* argSchema );

		virtual ~CFSecRamISOLangTable();

		virtual cfsec::CFSecISOLangBuff* createISOLang( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecISOLangBuff* Buff );

		virtual cfsec::CFSecISOLangBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOLangPKey* PKey );

		virtual cfsec::CFSecISOLangBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOLangPKey* PKey );

		virtual std::TCFLibOwningVector<cfsec::CFSecISOLangBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization );

		virtual cfsec::CFSecISOLangBuff* readDerivedByCode3Idx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& ISO6392Code );

		virtual std::TCFLibOwningVector<cfsec::CFSecISOLangBuff*> readDerivedByCode2Idx( const cfsec::CFSecAuthorization* Authorization,
			const std::string* ISO6391Code );

		virtual cfsec::CFSecISOLangBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t ISOLangId );

		virtual cfsec::CFSecISOLangBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOLangPKey* PKey );

		virtual cfsec::CFSecISOLangBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOLangPKey* PKey );

		virtual std::TCFLibOwningVector<cfsec::CFSecISOLangBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization );

		virtual cfsec::CFSecISOLangBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t ISOLangId );

		virtual cfsec::CFSecISOLangBuff* readBuffByCode3Idx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& ISO6392Code );

		virtual std::TCFLibOwningVector<cfsec::CFSecISOLangBuff*> readBuffByCode2Idx( const cfsec::CFSecAuthorization* Authorization,
			const std::string* ISO6391Code );

		virtual cfsec::CFSecISOLangBuff* readBuffByLookupCode3Idx( const cfsec::CFSecAuthorization* Authorization, const std::string& ISO6392Code,
			bool forceRead = false );

		virtual cfsec::CFSecISOLangBuff* readDerivedByLookupCode3Idx( const cfsec::CFSecAuthorization* Authorization, const std::string& ISO6392Code,
			bool forceRead = false );

		virtual cfsec::CFSecISOLangBuff* updateISOLang( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecISOLangBuff* Buff );

		virtual void deleteISOLang( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecISOLangBuff* Buff );
		virtual void deleteISOLangByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t argISOLangId );

		virtual void deleteISOLangByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOLangPKey* argKey );

		virtual void deleteISOLangByCode3Idx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& argISO6392Code );

		virtual void deleteISOLangByCode3Idx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOLangByCode3IdxKey* argKey );

		virtual void deleteISOLangByCode2Idx( const cfsec::CFSecAuthorization* Authorization,
			const std::string* argISO6391Code );

		virtual void deleteISOLangByCode2Idx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOLangByCode2IdxKey* argKey );


		virtual void releasePreparedStatements();

	};
}
