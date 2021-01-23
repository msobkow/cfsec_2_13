#pragma once

// Description: C++18 DbIO interface for Service.

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
#include <cfsec/CFSecServiceBuff.hpp>
#include <cfsec/CFSecServicePKey.hpp>
#include <cfsec/CFSecServiceHBuff.hpp>
#include <cfsec/CFSecServiceHPKey.hpp>
#include <cfsec/CFSecServiceByClusterIdxKey.hpp>
#include <cfsec/CFSecServiceByHostIdxKey.hpp>
#include <cfsec/CFSecServiceByTypeIdxKey.hpp>
#include <cfsec/CFSecServiceByUTypeIdxKey.hpp>
#include <cfsec/CFSecServiceByUHostPortIdxKey.hpp>

namespace cfsec {
	class ICFSecSchemaObj;
}

namespace cfsec {
	class ICFSecServiceObj;

	class ICFSecServiceTable
	{
	public:
		ICFSecServiceTable();
		virtual ~ICFSecServiceTable();

		virtual cfsec::CFSecServiceBuff* createService( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecServiceBuff* Buff ) = 0;

		virtual cfsec::CFSecServiceBuff* updateService( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecServiceBuff* Buff ) = 0;

		virtual void deleteService( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecServiceBuff* Buff ) = 0;
		virtual void deleteServiceByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const int64_t argServiceId ) = 0;

		virtual void deleteServiceByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecServicePKey* argKey ) = 0;
		virtual void deleteServiceByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId ) = 0;

		virtual void deleteServiceByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecServiceByClusterIdxKey* argKey ) = 0;
		virtual void deleteServiceByHostIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const int64_t argHostNodeId ) = 0;

		virtual void deleteServiceByHostIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecServiceByHostIdxKey* argKey ) = 0;
		virtual void deleteServiceByTypeIdx( const cfsec::CFSecAuthorization* Authorization,
			const int32_t argServiceTypeId ) = 0;

		virtual void deleteServiceByTypeIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecServiceByTypeIdxKey* argKey ) = 0;
		virtual void deleteServiceByUTypeIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const int64_t argHostNodeId,
			const int32_t argServiceTypeId ) = 0;

		virtual void deleteServiceByUTypeIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecServiceByUTypeIdxKey* argKey ) = 0;
		virtual void deleteServiceByUHostPortIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const int64_t argHostNodeId,
			const int16_t argHostPort ) = 0;

		virtual void deleteServiceByUHostPortIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecServiceByUHostPortIdxKey* argKey ) = 0;

		virtual cfsec::CFSecServiceBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecServicePKey* PKey ) = 0;

		virtual cfsec::CFSecServiceBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecServicePKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecServiceBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual cfsec::CFSecServiceBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t ServiceId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecServiceBuff*> readDerivedByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecServiceBuff*> readDerivedByHostIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t HostNodeId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecServiceBuff*> readDerivedByTypeIdx( const cfsec::CFSecAuthorization* Authorization,
			const int32_t ServiceTypeId ) = 0;

		virtual cfsec::CFSecServiceBuff* readDerivedByUTypeIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t HostNodeId,
			const int32_t ServiceTypeId ) = 0;

		virtual cfsec::CFSecServiceBuff* readDerivedByUHostPortIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t HostNodeId,
			const int16_t HostPort ) = 0;

		virtual cfsec::CFSecServiceBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecServicePKey* PKey ) = 0;

		virtual cfsec::CFSecServiceBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecServicePKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecServiceBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecServiceBuff*> pageAllBuff( const cfsec::CFSecAuthorization* Authorization,
			const int64_t* priorClusterId,
			const int64_t* priorServiceId ) = 0;

		virtual cfsec::CFSecServiceBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t ServiceId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecServiceBuff*> readBuffByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecServiceBuff*> readBuffByHostIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t HostNodeId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecServiceBuff*> readBuffByTypeIdx( const cfsec::CFSecAuthorization* Authorization,
			const int32_t ServiceTypeId ) = 0;

		virtual cfsec::CFSecServiceBuff* readBuffByUTypeIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t HostNodeId,
			const int32_t ServiceTypeId ) = 0;

		virtual cfsec::CFSecServiceBuff* readBuffByUHostPortIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t HostNodeId,
			const int16_t HostPort ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecServiceBuff*> pageBuffByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t* priorClusterId,
			const int64_t* priorServiceId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecServiceBuff*> pageBuffByHostIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t HostNodeId,
			const int64_t* priorClusterId,
			const int64_t* priorServiceId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecServiceBuff*> pageBuffByTypeIdx( const cfsec::CFSecAuthorization* Authorization,
			const int32_t ServiceTypeId,
			const int64_t* priorClusterId,
			const int64_t* priorServiceId ) = 0;

		virtual void releasePreparedStatements() = 0;
	};
}
