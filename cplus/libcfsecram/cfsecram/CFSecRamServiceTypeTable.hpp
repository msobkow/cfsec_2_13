#pragma once

// Description: C++18 Interface for an in-memory RAM DbIO declementation for ServiceType.

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

	class CFSecRamServiceTypeTable
	: public virtual cfsec::ICFSecServiceTypeTable
	{
	protected:
		cfsec::ICFSecSchema* schema;
		std::map<cfsec::CFSecServiceTypePKey,
			cfsec::CFSecServiceTypeBuff*>* dictByPKey;
		std::map<cfsec::CFSecServiceTypeByUDescrIdxKey,
			cfsec::CFSecServiceTypeBuff*>* dictByUDescrIdx;
	public:
		static const std::string CLASS_NAME;
		CFSecRamServiceTypeTable( cfsec::ICFSecSchema* argSchema );

		virtual ~CFSecRamServiceTypeTable();

		virtual cfsec::CFSecServiceTypeBuff* createServiceType( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecServiceTypeBuff* Buff );

		virtual cfsec::CFSecServiceTypeBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecServiceTypePKey* PKey );

		virtual cfsec::CFSecServiceTypeBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecServiceTypePKey* PKey );

		virtual std::TCFLibOwningVector<cfsec::CFSecServiceTypeBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization );

		virtual cfsec::CFSecServiceTypeBuff* readDerivedByUDescrIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& Description );

		virtual cfsec::CFSecServiceTypeBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int32_t ServiceTypeId );

		virtual cfsec::CFSecServiceTypeBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecServiceTypePKey* PKey );

		virtual cfsec::CFSecServiceTypeBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecServiceTypePKey* PKey );

		virtual std::TCFLibOwningVector<cfsec::CFSecServiceTypeBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization );

		virtual cfsec::CFSecServiceTypeBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int32_t ServiceTypeId );

		virtual cfsec::CFSecServiceTypeBuff* readBuffByUDescrIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& Description );

		virtual cfsec::CFSecServiceTypeBuff* readBuffByLookupUDescrIdx( const cfsec::CFSecAuthorization* Authorization, const std::string& Description,
			bool forceRead = false );

		virtual cfsec::CFSecServiceTypeBuff* readDerivedByLookupUDescrIdx( const cfsec::CFSecAuthorization* Authorization, const std::string& Description,
			bool forceRead = false );

		virtual cfsec::CFSecServiceTypeBuff* updateServiceType( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecServiceTypeBuff* Buff );

		virtual void deleteServiceType( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecServiceTypeBuff* Buff );
		virtual void deleteServiceTypeByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int32_t argServiceTypeId );

		virtual void deleteServiceTypeByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecServiceTypePKey* argKey );

		virtual void deleteServiceTypeByUDescrIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& argDescription );

		virtual void deleteServiceTypeByUDescrIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecServiceTypeByUDescrIdxKey* argKey );


		virtual void releasePreparedStatements();

	};
}
