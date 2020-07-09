#pragma once

// Description: C++18 Interface for an in-memory RAM DbIO declementation for ISOCtryCcy.

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

	class CFSecRamISOCtryCcyTable
	: public virtual cfsec::ICFSecISOCtryCcyTable
	{
	protected:
		cfsec::ICFSecSchema* schema;
		std::map<cfsec::CFSecISOCtryCcyPKey,
			cfsec::CFSecISOCtryCcyBuff*>* dictByPKey;
		std::map<cfsec::CFSecISOCtryCcyByCtryIdxKey,
			std::map<cfsec::CFSecISOCtryCcyPKey,
				cfsec::CFSecISOCtryCcyBuff*>*>* dictByCtryIdx;
		std::map<cfsec::CFSecISOCtryCcyByCcyIdxKey,
			std::map<cfsec::CFSecISOCtryCcyPKey,
				cfsec::CFSecISOCtryCcyBuff*>*>* dictByCcyIdx;
	public:
		static const std::string CLASS_NAME;
		CFSecRamISOCtryCcyTable( cfsec::ICFSecSchema* argSchema );

		virtual ~CFSecRamISOCtryCcyTable();

		virtual cfsec::CFSecISOCtryCcyBuff* createISOCtryCcy( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecISOCtryCcyBuff* Buff );

		virtual cfsec::CFSecISOCtryCcyBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCtryCcyPKey* PKey );

		virtual cfsec::CFSecISOCtryCcyBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCtryCcyPKey* PKey );

		virtual std::TCFLibOwningVector<cfsec::CFSecISOCtryCcyBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization );

		virtual std::TCFLibOwningVector<cfsec::CFSecISOCtryCcyBuff*> readDerivedByCtryIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t ISOCtryId );

		virtual std::TCFLibOwningVector<cfsec::CFSecISOCtryCcyBuff*> readDerivedByCcyIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t ISOCcyId );

		virtual cfsec::CFSecISOCtryCcyBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t ISOCtryId,
			const int16_t ISOCcyId );

		virtual cfsec::CFSecISOCtryCcyBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCtryCcyPKey* PKey );

		virtual cfsec::CFSecISOCtryCcyBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCtryCcyPKey* PKey );

		virtual std::TCFLibOwningVector<cfsec::CFSecISOCtryCcyBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization );

		virtual cfsec::CFSecISOCtryCcyBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t ISOCtryId,
			const int16_t ISOCcyId );

		virtual std::TCFLibOwningVector<cfsec::CFSecISOCtryCcyBuff*> readBuffByCtryIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t ISOCtryId );

		virtual std::TCFLibOwningVector<cfsec::CFSecISOCtryCcyBuff*> readBuffByCcyIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t ISOCcyId );

		virtual cfsec::CFSecISOCtryCcyBuff* updateISOCtryCcy( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecISOCtryCcyBuff* Buff );

		virtual void deleteISOCtryCcy( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecISOCtryCcyBuff* Buff );
		virtual void deleteISOCtryCcyByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t argISOCtryId,
			const int16_t argISOCcyId );

		virtual void deleteISOCtryCcyByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCtryCcyPKey* argKey );

		virtual void deleteISOCtryCcyByCtryIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t argISOCtryId );

		virtual void deleteISOCtryCcyByCtryIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCtryCcyByCtryIdxKey* argKey );

		virtual void deleteISOCtryCcyByCcyIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t argISOCcyId );

		virtual void deleteISOCtryCcyByCcyIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCtryCcyByCcyIdxKey* argKey );


		virtual void releasePreparedStatements();

	};
}
