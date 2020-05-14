#pragma once

// Description: C++18 Schema Object specification for CFSec.

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

#include <cfsecobj/ICFSecSchemaObj.hpp>

namespace cfsec {

	class CFSecSchemaObj
	: public virtual ICFSecSchemaObj
	{
	public:
		static const std::string CLASS_NAME;
		static const std::string SCHEMA_NAME;
		static const std::string SCHEMA_DBNAME;
		static const std::string S_System;
	protected:
		cfsec::CFSecAuthorization* authorization;
		cfsec::ICFSecSchema* backingStore;
		std::string* secClusterName;
		std::string* secTenantName;
		std::string* secUserName;
		cfsec::ICFSecClusterObj* secCluster;
		long secClusterId;
		cfsec::ICFSecTenantObj* secTenant;
		long secTenantId;
		cfsec::ICFSecSecUserObj* secUser;
		uuid_t secSessionUserId;
		cfsec::ICFSecSecSessionObj* secSession;
		uuid_t secSessionSessionId;
		std::string* schemaDbName;
		std::string* lowerDbSchemaName;
		ICFSecClusterTableObj* clusterTableObj;
		ICFSecHostNodeTableObj* hostNodeTableObj;
		ICFSecISOCcyTableObj* iSOCcyTableObj;
		ICFSecISOCtryTableObj* iSOCtryTableObj;
		ICFSecISOCtryCcyTableObj* iSOCtryCcyTableObj;
		ICFSecISOCtryLangTableObj* iSOCtryLangTableObj;
		ICFSecISOLangTableObj* iSOLangTableObj;
		ICFSecISOTZoneTableObj* iSOTZoneTableObj;
		ICFSecSecAppTableObj* secAppTableObj;
		ICFSecSecDeviceTableObj* secDeviceTableObj;
		ICFSecSecFormTableObj* secFormTableObj;
		ICFSecSecGroupTableObj* secGroupTableObj;
		ICFSecSecGroupFormTableObj* secGroupFormTableObj;
		ICFSecSecGrpIncTableObj* secGrpIncTableObj;
		ICFSecSecGrpMembTableObj* secGrpMembTableObj;
		ICFSecSecSessionTableObj* secSessionTableObj;
		ICFSecSecUserTableObj* secUserTableObj;
		ICFSecServiceTableObj* serviceTableObj;
		ICFSecServiceTypeTableObj* serviceTypeTableObj;
		ICFSecSysClusterTableObj* sysClusterTableObj;
		ICFSecTSecGroupTableObj* tSecGroupTableObj;
		ICFSecTSecGrpIncTableObj* tSecGrpIncTableObj;
		ICFSecTSecGrpMembTableObj* tSecGrpMembTableObj;
		ICFSecTenantTableObj* tenantTableObj;
	public:
		CFSecSchemaObj();

		virtual ~CFSecSchemaObj();

		virtual void setSecClusterName( const std::string& value );
		virtual std::string getSecClusterName();
		virtual cfsec::ICFSecClusterObj* getSecCluster();
		virtual void setSecCluster( cfsec::ICFSecClusterObj* value );
		virtual long getSecClusterId();

		virtual void setSecTenantName( const std::string& value );
		virtual std::string getSecTenantName();
		virtual cfsec::ICFSecTenantObj* getSecTenant();
		virtual void setSecTenant( cfsec::ICFSecTenantObj* value );
		virtual long getSecTenantId();

		virtual void setSecUserName( const std::string& value );
		virtual std::string getSecUserName();
		virtual cfsec::ICFSecSecUserObj* getSecUser();
		virtual void setSecUser( cfsec::ICFSecSecUserObj* value );

		virtual cfsec::ICFSecSecSessionObj* getSecSession();
		virtual void setSecSession( cfsec::ICFSecSecSessionObj* value );
		virtual void setSecSessionId( const uuid_ptr_t value );
		virtual uuid_ptr_t getSecSessionSessionId();
		virtual uuid_ptr_t getSecSessionUserId();

		virtual std::string getDbSchemaName();
		virtual std::string getLowerDbSchemaName();

		virtual void setDbSchemaName( const std::string& argDbSchemaName );

		virtual std::string fileImport( const std::string& fileName, const std::string& fileContent );

		/**
		 *	Release any prepared statements acquired by this connection.
		 *	<p>
		 *	Resets the prepared statements so they can acquire the new value of
		 *	<tt>setDbSchemaName()</tt>.
		 */
		virtual void releasePreparedStatements();

		virtual cfsec::CFSecAuthorization* getAuthorization() const;
		virtual void setAuthorization( cfsec::CFSecAuthorization* value );
		virtual cfsec::ICFSecSchema* getBackingStore();
		virtual void setBackingStore( cfsec::ICFSecSchema* value );
		virtual std::string getSchemaName();
		virtual bool isConnected();
		virtual bool connect();
		virtual bool connect( const std::string& username, const std::string& password );
		virtual bool connect( const std::string& clusterName, const std::string& tenantName, const std::string& secUserName, const std::string& password );
		virtual void disconnect( bool doCommit );
		virtual void logout();
		virtual void minimizeMemory();
		virtual bool isTransactionOpen();
		virtual bool beginTransaction();
		virtual void commit();
		virtual void rollback();

		virtual cfsec::ICFSecClusterTableObj* getClusterTableObj();

		virtual cfsec::ICFSecHostNodeTableObj* getHostNodeTableObj();

		virtual cfsec::ICFSecISOCcyTableObj* getISOCcyTableObj();

		virtual cfsec::ICFSecISOCtryTableObj* getISOCtryTableObj();

		virtual cfsec::ICFSecISOCtryCcyTableObj* getISOCtryCcyTableObj();

		virtual cfsec::ICFSecISOCtryLangTableObj* getISOCtryLangTableObj();

		virtual cfsec::ICFSecISOLangTableObj* getISOLangTableObj();

		virtual cfsec::ICFSecISOTZoneTableObj* getISOTZoneTableObj();

		virtual cfsec::ICFSecSecAppTableObj* getSecAppTableObj();

		virtual cfsec::ICFSecSecDeviceTableObj* getSecDeviceTableObj();

		virtual cfsec::ICFSecSecFormTableObj* getSecFormTableObj();

		virtual cfsec::ICFSecSecGroupTableObj* getSecGroupTableObj();

		virtual cfsec::ICFSecSecGroupFormTableObj* getSecGroupFormTableObj();

		virtual cfsec::ICFSecSecGrpIncTableObj* getSecGrpIncTableObj();

		virtual cfsec::ICFSecSecGrpMembTableObj* getSecGrpMembTableObj();

		virtual cfsec::ICFSecSecSessionTableObj* getSecSessionTableObj();

		virtual cfsec::ICFSecSecUserTableObj* getSecUserTableObj();

		virtual cfsec::ICFSecServiceTableObj* getServiceTableObj();

		virtual cfsec::ICFSecServiceTypeTableObj* getServiceTypeTableObj();

		virtual cfsec::ICFSecSysClusterTableObj* getSysClusterTableObj();

		virtual cfsec::ICFSecTSecGroupTableObj* getTSecGroupTableObj();

		virtual cfsec::ICFSecTSecGrpIncTableObj* getTSecGrpIncTableObj();

		virtual cfsec::ICFSecTSecGrpMembTableObj* getTSecGrpMembTableObj();

		virtual cfsec::ICFSecTenantTableObj* getTenantTableObj();

	};

}
