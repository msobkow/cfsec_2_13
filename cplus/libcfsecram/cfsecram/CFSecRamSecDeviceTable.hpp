#pragma once

// Description: C++18 Interface for an in-memory RAM DbIO declementation for SecDevice.

/*
 *	org.msscf.msscf.CFSec
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFSec 2.13 Security Essentials
 *	
 *	Copyright 2020 Mark Stephen Sobkow
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
 *	Please contact Mark Stephen Sobkow at msobkow@sasktel.net for commercial licensing.
 *
 *	Manufactured by MSS Code Factory 2.12
 */

#include <cflib/ICFLibPublic.hpp>
#include <cfsec/ICFSecPublic.hpp>
#include <cfsecobj/ICFSecObjPublic.hpp>
#include <cfsecsaxloader/CFSecSaxLoader.hpp>

namespace cfsec {

	class CFSecRamSecDeviceTable
	: public virtual cfsec::ICFSecSecDeviceTable
	{
	protected:
		cfsec::ICFSecSchema* schema;
		std::map<cfsec::CFSecSecDevicePKey,
			cfsec::CFSecSecDeviceBuff*>* dictByPKey;
		std::map<cfsec::CFSecSecDeviceByNameIdxKey,
			cfsec::CFSecSecDeviceBuff*>* dictByNameIdx;
		std::map<cfsec::CFSecSecDeviceByUserIdxKey,
			std::map<cfsec::CFSecSecDevicePKey,
				cfsec::CFSecSecDeviceBuff*>*>* dictByUserIdx;
	public:
		static const std::string CLASS_NAME;
		CFSecRamSecDeviceTable( cfsec::ICFSecSchema* argSchema );

		virtual ~CFSecRamSecDeviceTable();

		virtual cfsec::CFSecSecDeviceBuff* createSecDevice( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecSecDeviceBuff* Buff );

		virtual cfsec::CFSecSecDeviceBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecDevicePKey* PKey );

		virtual cfsec::CFSecSecDeviceBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecDevicePKey* PKey );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecDeviceBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization );

		virtual cfsec::CFSecSecDeviceBuff* readDerivedByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId,
			const std::string& DevName );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecDeviceBuff*> readDerivedByUserIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId );

		virtual cfsec::CFSecSecDeviceBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId,
			const std::string& DevName );

		virtual cfsec::CFSecSecDeviceBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecDevicePKey* PKey );

		virtual cfsec::CFSecSecDeviceBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecDevicePKey* PKey );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecDeviceBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecDeviceBuff*> pageAllBuff( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t priorSecUserId,
			const std::string* priorDevName );

		virtual cfsec::CFSecSecDeviceBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId,
			const std::string& DevName );

		virtual cfsec::CFSecSecDeviceBuff* readBuffByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId,
			const std::string& DevName );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecDeviceBuff*> readBuffByUserIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId );

		virtual cfsec::CFSecSecDeviceBuff* readBuffByLookupNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId, const std::string& DevName,
			bool forceRead = false );

		virtual cfsec::CFSecSecDeviceBuff* readDerivedByLookupNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId, const std::string& DevName,
			bool forceRead = false );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecDeviceBuff*> pageBuffByUserIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId,
			const uuid_ptr_t priorSecUserId,
			const std::string* priorDevName );

		virtual cfsec::CFSecSecDeviceBuff* updateSecDevice( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecSecDeviceBuff* Buff );

		virtual void deleteSecDevice( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecSecDeviceBuff* Buff );
		virtual void deleteSecDeviceByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t argSecUserId,
			const std::string& argDevName );

		virtual void deleteSecDeviceByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecDevicePKey* argKey );

		virtual void deleteSecDeviceByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t argSecUserId,
			const std::string& argDevName );

		virtual void deleteSecDeviceByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecDeviceByNameIdxKey* argKey );

		virtual void deleteSecDeviceByUserIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t argSecUserId );

		virtual void deleteSecDeviceByUserIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecDeviceByUserIdxKey* argKey );


		virtual void releasePreparedStatements();

	};
}
