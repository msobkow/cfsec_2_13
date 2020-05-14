#pragma once

// Description: C++18 DbIO interface for SecDevice.

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
#include <cfsec/CFSecSecDeviceBuff.hpp>
#include <cfsec/CFSecSecDevicePKey.hpp>
#include <cfsec/CFSecSecDeviceHBuff.hpp>
#include <cfsec/CFSecSecDeviceHPKey.hpp>
#include <cfsec/CFSecSecDeviceByNameIdxKey.hpp>
#include <cfsec/CFSecSecDeviceByUserIdxKey.hpp>

namespace cfsec {
	class ICFSecSchemaObj;
}

namespace cfsec {
	class ICFSecSecDeviceObj;

	class ICFSecSecDeviceTable
	{
	public:
		ICFSecSecDeviceTable();
		virtual ~ICFSecSecDeviceTable();

		virtual cfsec::CFSecSecDeviceBuff* createSecDevice( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecSecDeviceBuff* Buff ) = 0;

		virtual cfsec::CFSecSecDeviceBuff* updateSecDevice( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecSecDeviceBuff* Buff ) = 0;

		virtual void deleteSecDevice( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecSecDeviceBuff* Buff ) = 0;
		virtual void deleteSecDeviceByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t argSecUserId,
			const std::string& argDevName ) = 0;

		virtual void deleteSecDeviceByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecDevicePKey* argKey ) = 0;
		virtual void deleteSecDeviceByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t argSecUserId,
			const std::string& argDevName ) = 0;

		virtual void deleteSecDeviceByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecDeviceByNameIdxKey* argKey ) = 0;
		virtual void deleteSecDeviceByUserIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t argSecUserId ) = 0;

		virtual void deleteSecDeviceByUserIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecDeviceByUserIdxKey* argKey ) = 0;

		virtual cfsec::CFSecSecDeviceBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecDevicePKey* PKey ) = 0;

		virtual cfsec::CFSecSecDeviceBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecDevicePKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecDeviceBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual cfsec::CFSecSecDeviceBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId,
			const std::string& DevName ) = 0;

		virtual cfsec::CFSecSecDeviceBuff* readDerivedByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId,
			const std::string& DevName ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecDeviceBuff*> readDerivedByUserIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId ) = 0;

		virtual cfsec::CFSecSecDeviceBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecDevicePKey* PKey ) = 0;

		virtual cfsec::CFSecSecDeviceBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecDevicePKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecDeviceBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecDeviceBuff*> pageAllBuff( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t priorSecUserId,
			const std::string* priorDevName ) = 0;

		virtual cfsec::CFSecSecDeviceBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId,
			const std::string& DevName ) = 0;

		virtual cfsec::CFSecSecDeviceBuff* readBuffByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId,
			const std::string& DevName ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecDeviceBuff*> readBuffByUserIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId ) = 0;

		virtual cfsec::CFSecSecDeviceBuff* readBuffByLookupNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId, const std::string& DevName,
			bool forceRead = false ) = 0;

		virtual cfsec::CFSecSecDeviceBuff* readDerivedByLookupNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId, const std::string& DevName,
			bool forceRead = false ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecDeviceBuff*> pageBuffByUserIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId,
			const uuid_ptr_t priorSecUserId,
			const std::string* priorDevName ) = 0;

		virtual void releasePreparedStatements() = 0;
	};
}
