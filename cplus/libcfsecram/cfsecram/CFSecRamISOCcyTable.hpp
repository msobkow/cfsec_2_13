#pragma once

// Description: C++18 Interface for an in-memory RAM DbIO declementation for ISOCcy.

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

	class CFSecRamISOCcyTable
	: public virtual cfsec::ICFSecISOCcyTable
	{
	protected:
		cfsec::ICFSecSchema* schema;
		std::map<cfsec::CFSecISOCcyPKey,
			cfsec::CFSecISOCcyBuff*>* dictByPKey;
		std::map<cfsec::CFSecISOCcyByCcyCdIdxKey,
			cfsec::CFSecISOCcyBuff*>* dictByCcyCdIdx;
		std::map<cfsec::CFSecISOCcyByCcyNmIdxKey,
			cfsec::CFSecISOCcyBuff*>* dictByCcyNmIdx;
	public:
		static const std::string CLASS_NAME;
		CFSecRamISOCcyTable( cfsec::ICFSecSchema* argSchema );

		virtual ~CFSecRamISOCcyTable();

		virtual cfsec::CFSecISOCcyBuff* createISOCcy( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecISOCcyBuff* Buff );

		virtual cfsec::CFSecISOCcyBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCcyPKey* PKey );

		virtual cfsec::CFSecISOCcyBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCcyPKey* PKey );

		virtual std::TCFLibOwningVector<cfsec::CFSecISOCcyBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization );

		virtual cfsec::CFSecISOCcyBuff* readDerivedByCcyCdIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& ISOCode );

		virtual cfsec::CFSecISOCcyBuff* readDerivedByCcyNmIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& Name );

		virtual cfsec::CFSecISOCcyBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t ISOCcyId );

		virtual cfsec::CFSecISOCcyBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCcyPKey* PKey );

		virtual cfsec::CFSecISOCcyBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCcyPKey* PKey );

		virtual std::TCFLibOwningVector<cfsec::CFSecISOCcyBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization );

		virtual cfsec::CFSecISOCcyBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t ISOCcyId );

		virtual cfsec::CFSecISOCcyBuff* readBuffByCcyCdIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& ISOCode );

		virtual cfsec::CFSecISOCcyBuff* readBuffByCcyNmIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& Name );

		virtual cfsec::CFSecISOCcyBuff* readBuffByLookupCcyCdIdx( const cfsec::CFSecAuthorization* Authorization, const std::string& ISOCode,
			bool forceRead = false );

		virtual cfsec::CFSecISOCcyBuff* readDerivedByLookupCcyCdIdx( const cfsec::CFSecAuthorization* Authorization, const std::string& ISOCode,
			bool forceRead = false );

		virtual cfsec::CFSecISOCcyBuff* updateISOCcy( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecISOCcyBuff* Buff );

		virtual void deleteISOCcy( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecISOCcyBuff* Buff );
		virtual void deleteISOCcyByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t argISOCcyId );

		virtual void deleteISOCcyByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCcyPKey* argKey );

		virtual void deleteISOCcyByCcyCdIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& argISOCode );

		virtual void deleteISOCcyByCcyCdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCcyByCcyCdIdxKey* argKey );

		virtual void deleteISOCcyByCcyNmIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& argName );

		virtual void deleteISOCcyByCcyNmIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCcyByCcyNmIdxKey* argKey );


		virtual void releasePreparedStatements();

	};
}
