#pragma once

// Description: C++18 Interface for an in-memory RAM DbIO declementation for ISOCtry.

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

	class CFSecRamISOCtryTable
	: public virtual cfsec::ICFSecISOCtryTable
	{
	protected:
		cfsec::ICFSecSchema* schema;
		std::map<cfsec::CFSecISOCtryPKey,
			cfsec::CFSecISOCtryBuff*>* dictByPKey;
		std::map<cfsec::CFSecISOCtryByISOCodeIdxKey,
			cfsec::CFSecISOCtryBuff*>* dictByISOCodeIdx;
		std::map<cfsec::CFSecISOCtryByNameIdxKey,
			cfsec::CFSecISOCtryBuff*>* dictByNameIdx;
	public:
		static const std::string CLASS_NAME;
		CFSecRamISOCtryTable( cfsec::ICFSecSchema* argSchema );

		virtual ~CFSecRamISOCtryTable();

		virtual cfsec::CFSecISOCtryBuff* createISOCtry( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecISOCtryBuff* Buff );

		virtual cfsec::CFSecISOCtryBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCtryPKey* PKey );

		virtual cfsec::CFSecISOCtryBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCtryPKey* PKey );

		virtual std::TCFLibOwningVector<cfsec::CFSecISOCtryBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization );

		virtual cfsec::CFSecISOCtryBuff* readDerivedByISOCodeIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& ISOCode );

		virtual cfsec::CFSecISOCtryBuff* readDerivedByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& Name );

		virtual cfsec::CFSecISOCtryBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t ISOCtryId );

		virtual cfsec::CFSecISOCtryBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCtryPKey* PKey );

		virtual cfsec::CFSecISOCtryBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCtryPKey* PKey );

		virtual std::TCFLibOwningVector<cfsec::CFSecISOCtryBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization );

		virtual cfsec::CFSecISOCtryBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t ISOCtryId );

		virtual cfsec::CFSecISOCtryBuff* readBuffByISOCodeIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& ISOCode );

		virtual cfsec::CFSecISOCtryBuff* readBuffByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& Name );

		virtual cfsec::CFSecISOCtryBuff* readBuffByLookupISOCodeIdx( const cfsec::CFSecAuthorization* Authorization, const std::string& ISOCode,
			bool forceRead = false );

		virtual cfsec::CFSecISOCtryBuff* readDerivedByLookupISOCodeIdx( const cfsec::CFSecAuthorization* Authorization, const std::string& ISOCode,
			bool forceRead = false );

		virtual cfsec::CFSecISOCtryBuff* updateISOCtry( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecISOCtryBuff* Buff );

		virtual void deleteISOCtry( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecISOCtryBuff* Buff );
		virtual void deleteISOCtryByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t argISOCtryId );

		virtual void deleteISOCtryByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCtryPKey* argKey );

		virtual void deleteISOCtryByISOCodeIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& argISOCode );

		virtual void deleteISOCtryByISOCodeIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCtryByISOCodeIdxKey* argKey );

		virtual void deleteISOCtryByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& argName );

		virtual void deleteISOCtryByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCtryByNameIdxKey* argKey );


		virtual void releasePreparedStatements();

	};
}
