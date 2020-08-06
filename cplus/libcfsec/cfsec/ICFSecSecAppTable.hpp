#pragma once

// Description: C++18 DbIO interface for SecApp.

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
#include <cfsec/CFSecAuthorization.hpp>
#include <cfsec/CFSecHPKey.hpp>
#include <cfsec/CFSecSecAppBuff.hpp>
#include <cfsec/CFSecSecAppPKey.hpp>
#include <cfsec/CFSecSecAppHBuff.hpp>
#include <cfsec/CFSecSecAppHPKey.hpp>
#include <cfsec/CFSecSecAppByClusterIdxKey.hpp>
#include <cfsec/CFSecSecAppByUJEEMountIdxKey.hpp>

namespace cfsec {
	class ICFSecSchemaObj;
}

namespace cfsec {
	class ICFSecSecAppObj;

	class ICFSecSecAppTable
	{
	public:
		ICFSecSecAppTable();
		virtual ~ICFSecSecAppTable();

		virtual cfsec::CFSecSecAppBuff* createSecApp( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecSecAppBuff* Buff ) = 0;

		virtual cfsec::CFSecSecAppBuff* updateSecApp( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecSecAppBuff* Buff ) = 0;

		virtual void deleteSecApp( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecSecAppBuff* Buff ) = 0;
		virtual void deleteSecAppByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const int32_t argSecAppId ) = 0;

		virtual void deleteSecAppByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecAppPKey* argKey ) = 0;
		virtual void deleteSecAppByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId ) = 0;

		virtual void deleteSecAppByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecAppByClusterIdxKey* argKey ) = 0;
		virtual void deleteSecAppByUJEEMountIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const std::string& argJEEMountName ) = 0;

		virtual void deleteSecAppByUJEEMountIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecAppByUJEEMountIdxKey* argKey ) = 0;

		virtual cfsec::CFSecSecAppBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecAppPKey* PKey ) = 0;

		virtual cfsec::CFSecSecAppBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecAppPKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecAppBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual cfsec::CFSecSecAppBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecAppId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecAppBuff*> readDerivedByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId ) = 0;

		virtual cfsec::CFSecSecAppBuff* readDerivedByUJEEMountIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const std::string& JEEMountName ) = 0;

		virtual cfsec::CFSecSecAppBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecAppPKey* PKey ) = 0;

		virtual cfsec::CFSecSecAppBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecAppPKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecAppBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecAppBuff*> pageAllBuff( const cfsec::CFSecAuthorization* Authorization,
			const int64_t* priorClusterId,
			const int32_t* priorSecAppId ) = 0;

		virtual cfsec::CFSecSecAppBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecAppId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecAppBuff*> readBuffByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId ) = 0;

		virtual cfsec::CFSecSecAppBuff* readBuffByUJEEMountIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const std::string& JEEMountName ) = 0;

		virtual cfsec::CFSecSecAppBuff* readBuffByLookupUJEEMountIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId, const std::string& JEEMountName,
			bool forceRead = false ) = 0;

		virtual cfsec::CFSecSecAppBuff* readDerivedByLookupUJEEMountIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId, const std::string& JEEMountName,
			bool forceRead = false ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecAppBuff*> pageBuffByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t* priorClusterId,
			const int32_t* priorSecAppId ) = 0;

		virtual void releasePreparedStatements() = 0;
	};
}
