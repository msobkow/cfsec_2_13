#pragma once

// Description: C++18 Schema Object interface for CFSec.

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
#include <cfsec/ICFSecSchema.hpp>

namespace cfsec {
	class ICFSecSchemaObj;
	class ICFSecClusterObj;
	class ICFSecClusterEditObj;
	class ICFSecClusterTableObj;
	class ICFSecHostNodeObj;
	class ICFSecHostNodeEditObj;
	class ICFSecHostNodeTableObj;
	class ICFSecISOCcyObj;
	class ICFSecISOCcyEditObj;
	class ICFSecISOCcyTableObj;
	class ICFSecISOCtryObj;
	class ICFSecISOCtryEditObj;
	class ICFSecISOCtryTableObj;
	class ICFSecISOCtryCcyObj;
	class ICFSecISOCtryCcyEditObj;
	class ICFSecISOCtryCcyTableObj;
	class ICFSecISOCtryLangObj;
	class ICFSecISOCtryLangEditObj;
	class ICFSecISOCtryLangTableObj;
	class ICFSecISOLangObj;
	class ICFSecISOLangEditObj;
	class ICFSecISOLangTableObj;
	class ICFSecISOTZoneObj;
	class ICFSecISOTZoneEditObj;
	class ICFSecISOTZoneTableObj;
	class ICFSecSecAppObj;
	class ICFSecSecAppEditObj;
	class ICFSecSecAppTableObj;
	class ICFSecSecDeviceObj;
	class ICFSecSecDeviceEditObj;
	class ICFSecSecDeviceTableObj;
	class ICFSecSecFormObj;
	class ICFSecSecFormEditObj;
	class ICFSecSecFormTableObj;
	class ICFSecSecGroupObj;
	class ICFSecSecGroupEditObj;
	class ICFSecSecGroupTableObj;
	class ICFSecSecGroupFormObj;
	class ICFSecSecGroupFormEditObj;
	class ICFSecSecGroupFormTableObj;
	class ICFSecSecGrpIncObj;
	class ICFSecSecGrpIncEditObj;
	class ICFSecSecGrpIncTableObj;
	class ICFSecSecGrpMembObj;
	class ICFSecSecGrpMembEditObj;
	class ICFSecSecGrpMembTableObj;
	class ICFSecSecSessionObj;
	class ICFSecSecSessionEditObj;
	class ICFSecSecSessionTableObj;
	class ICFSecSecUserObj;
	class ICFSecSecUserEditObj;
	class ICFSecSecUserTableObj;
	class ICFSecServiceObj;
	class ICFSecServiceEditObj;
	class ICFSecServiceTableObj;
	class ICFSecServiceTypeObj;
	class ICFSecServiceTypeEditObj;
	class ICFSecServiceTypeTableObj;
	class ICFSecSysClusterObj;
	class ICFSecSysClusterEditObj;
	class ICFSecSysClusterTableObj;
	class ICFSecTSecGroupObj;
	class ICFSecTSecGroupEditObj;
	class ICFSecTSecGroupTableObj;
	class ICFSecTSecGrpIncObj;
	class ICFSecTSecGrpIncEditObj;
	class ICFSecTSecGrpIncTableObj;
	class ICFSecTSecGrpMembObj;
	class ICFSecTSecGrpMembEditObj;
	class ICFSecTSecGrpMembTableObj;
	class ICFSecTenantObj;
	class ICFSecTenantEditObj;
	class ICFSecTenantTableObj;
}

namespace cfsec {
	class ICFSecSchemaObj
	{
	public:
		ICFSecSchemaObj();
		virtual ~ICFSecSchemaObj();

		virtual cfsec::CFSecAuthorization* getAuthorization() const = 0;
		virtual void setAuthorization( cfsec::CFSecAuthorization* value ) = 0;

		virtual cfsec::ICFSecSchema* getBackingStore() = 0;
		virtual void setBackingStore( cfsec::ICFSecSchema* value ) = 0;

		virtual std::string getSchemaName() = 0;

		virtual void setSecClusterName( const std::string& value ) = 0;
		virtual cfsec::ICFSecClusterObj* getSecCluster() = 0;
		virtual void setSecCluster( cfsec::ICFSecClusterObj* value ) = 0;

		virtual void setSecTenantName( const std::string& value ) = 0;
		virtual cfsec::ICFSecTenantObj* getSecTenant() = 0;
		virtual void setSecTenant( cfsec::ICFSecTenantObj* value ) = 0;

		virtual void setSecUserName( const std::string& value ) = 0;
		virtual cfsec::ICFSecSecUserObj* getSecUser() = 0;
		virtual void setSecUser( cfsec::ICFSecSecUserObj* value ) = 0;

		virtual void setSecSessionId( const uuid_ptr_t value ) = 0;
		virtual cfsec::ICFSecSecSessionObj* getSecSession() = 0;
		virtual void setSecSession( cfsec::ICFSecSecSessionObj* value ) = 0;

		virtual bool isConnected() = 0;
		virtual bool connect() = 0;
		virtual bool connect( const std::string& username, const std::string& password ) = 0;
		virtual bool connect( const std::string& clusterName, const std::string& tenantName, const std::string& secUserName, const std::string& password ) = 0;
		virtual void disconnect( bool doCommit ) = 0;
		virtual void logout() = 0;

		virtual void minimizeMemory() = 0;

		virtual std::string fileImport( const std::string& fileName, const std::string& fileContent ) = 0;

		virtual std::string getDbSchemaName() = 0;
		virtual std::string getLowerDbSchemaName() = 0;
		virtual void setDbSchemaName( const std::string& argDbSchemaName ) = 0;

		virtual bool isTransactionOpen() = 0;
		virtual bool beginTransaction() = 0;
		virtual void commit() = 0;
		virtual void rollback() = 0;

		virtual void releasePreparedStatements() = 0;

		virtual cfsec::ICFSecClusterTableObj* getClusterTableObj() = 0;
		virtual cfsec::ICFSecHostNodeTableObj* getHostNodeTableObj() = 0;
		virtual cfsec::ICFSecISOCcyTableObj* getISOCcyTableObj() = 0;
		virtual cfsec::ICFSecISOCtryTableObj* getISOCtryTableObj() = 0;
		virtual cfsec::ICFSecISOCtryCcyTableObj* getISOCtryCcyTableObj() = 0;
		virtual cfsec::ICFSecISOCtryLangTableObj* getISOCtryLangTableObj() = 0;
		virtual cfsec::ICFSecISOLangTableObj* getISOLangTableObj() = 0;
		virtual cfsec::ICFSecISOTZoneTableObj* getISOTZoneTableObj() = 0;
		virtual cfsec::ICFSecSecAppTableObj* getSecAppTableObj() = 0;
		virtual cfsec::ICFSecSecDeviceTableObj* getSecDeviceTableObj() = 0;
		virtual cfsec::ICFSecSecFormTableObj* getSecFormTableObj() = 0;
		virtual cfsec::ICFSecSecGroupTableObj* getSecGroupTableObj() = 0;
		virtual cfsec::ICFSecSecGroupFormTableObj* getSecGroupFormTableObj() = 0;
		virtual cfsec::ICFSecSecGrpIncTableObj* getSecGrpIncTableObj() = 0;
		virtual cfsec::ICFSecSecGrpMembTableObj* getSecGrpMembTableObj() = 0;
		virtual cfsec::ICFSecSecSessionTableObj* getSecSessionTableObj() = 0;
		virtual cfsec::ICFSecSecUserTableObj* getSecUserTableObj() = 0;
		virtual cfsec::ICFSecServiceTableObj* getServiceTableObj() = 0;
		virtual cfsec::ICFSecServiceTypeTableObj* getServiceTypeTableObj() = 0;
		virtual cfsec::ICFSecSysClusterTableObj* getSysClusterTableObj() = 0;
		virtual cfsec::ICFSecTSecGroupTableObj* getTSecGroupTableObj() = 0;
		virtual cfsec::ICFSecTSecGrpIncTableObj* getTSecGrpIncTableObj() = 0;
		virtual cfsec::ICFSecTSecGrpMembTableObj* getTSecGrpMembTableObj() = 0;
		virtual cfsec::ICFSecTenantTableObj* getTenantTableObj() = 0;
	};
}
