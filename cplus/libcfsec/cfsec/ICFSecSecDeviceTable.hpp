#pragma once

// Description: C++18 DbIO interface for SecDevice.

/*
 *	org.msscf.msscf.CFSec
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFSec 2.13 Security Essentials
 *	
 *	Copyright 2020-2021 Mark Stephen Sobkow
 *	
 *		This file is part of MSS Code Factory.
 *	
 *		MSS Code Factory is available under dual commercial license from Mark Stephen
 *		Sobkow, or under the terms of the GNU General Public License, Version 3
 *		or later.
 *	
 *	    MSS Code Factory is free software: you can redistribute it and/or modify
 *	    it under the terms of the GNU General Public License as published by
 *	    the Free Software Foundation, either version 3 of the License, or
 *	    (at your option) any later version.
 *	
 *	    MSS Code Factory is distributed in the hope that it will be useful,
 *	    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	    GNU General Public License for more details.
 *	
 *	    You should have received a copy of the GNU General Public License
 *	    along with MSS Code Factory.  If not, see <https://www.gnu.org/licenses/>.
 *	
 *	Donations to support MSS Code Factory can be made at
 *	https://www.paypal.com/paypalme2/MarkSobkow
 *	
 *	Please contact Mark Stephen Sobkow at mark.sobkow@gmail.com for commercial licensing.
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
