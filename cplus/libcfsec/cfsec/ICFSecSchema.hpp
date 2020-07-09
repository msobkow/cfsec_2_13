#pragma once

// Description: C++18 interface for a CFSec schema.

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


#include <uuid/uuid.h>

#include <array>
#include <cassert>
#include <cstddef>
#include <chrono>
#include <ctime>
#include <functional>
#include <list>
#include <string>

#include <cflib/ICFLibPublic.hpp>

#include <cfsec/CFSecAuthorization.hpp>
#include <cfsec/CFSecConfigurationFile.hpp>
#include <cfsec/ICFSecTablePerms.hpp>

namespace cfsec {

	class CFSecClusterPKey;
	class CFSecHostNodePKey;
	class CFSecISOCcyPKey;
	class CFSecISOCtryPKey;
	class CFSecISOCtryCcyPKey;
	class CFSecISOCtryLangPKey;
	class CFSecISOLangPKey;
	class CFSecISOTZonePKey;
	class CFSecSecAppPKey;
	class CFSecSecDevicePKey;
	class CFSecSecFormPKey;
	class CFSecSecGroupPKey;
	class CFSecSecGroupFormPKey;
	class CFSecSecGrpIncPKey;
	class CFSecSecGrpMembPKey;
	class CFSecSecSessionPKey;
	class CFSecSecUserPKey;
	class CFSecServicePKey;
	class CFSecServiceTypePKey;
	class CFSecSysClusterPKey;
	class CFSecTSecGroupPKey;
	class CFSecTSecGrpIncPKey;
	class CFSecTSecGrpMembPKey;
	class CFSecTenantPKey;

	class CFSecClusterHPKey;
	class CFSecHostNodeHPKey;
	class CFSecISOCcyHPKey;
	class CFSecISOCtryHPKey;
	class CFSecISOCtryCcyHPKey;
	class CFSecISOCtryLangHPKey;
	class CFSecISOLangHPKey;
	class CFSecISOTZoneHPKey;
	class CFSecSecAppHPKey;
	class CFSecSecDeviceHPKey;
	class CFSecSecFormHPKey;
	class CFSecSecGroupHPKey;
	class CFSecSecGroupFormHPKey;
	class CFSecSecGrpIncHPKey;
	class CFSecSecGrpMembHPKey;
	class CFSecSecUserHPKey;
	class CFSecServiceHPKey;
	class CFSecServiceTypeHPKey;
	class CFSecTSecGroupHPKey;
	class CFSecTSecGrpIncHPKey;
	class CFSecTSecGrpMembHPKey;
	class CFSecTenantHPKey;

	class CFSecClusterBuff;
	class CFSecHostNodeBuff;
	class CFSecISOCcyBuff;
	class CFSecISOCtryBuff;
	class CFSecISOCtryCcyBuff;
	class CFSecISOCtryLangBuff;
	class CFSecISOLangBuff;
	class CFSecISOTZoneBuff;
	class CFSecSecAppBuff;
	class CFSecSecDeviceBuff;
	class CFSecSecFormBuff;
	class CFSecSecGroupBuff;
	class CFSecSecGroupFormBuff;
	class CFSecSecGrpIncBuff;
	class CFSecSecGrpMembBuff;
	class CFSecSecSessionBuff;
	class CFSecSecUserBuff;
	class CFSecServiceBuff;
	class CFSecServiceTypeBuff;
	class CFSecSysClusterBuff;
	class CFSecTSecGroupBuff;
	class CFSecTSecGrpIncBuff;
	class CFSecTSecGrpMembBuff;
	class CFSecTenantBuff;

	class CFSecClusterHBuff;
	class CFSecHostNodeHBuff;
	class CFSecISOCcyHBuff;
	class CFSecISOCtryHBuff;
	class CFSecISOCtryCcyHBuff;
	class CFSecISOCtryLangHBuff;
	class CFSecISOLangHBuff;
	class CFSecISOTZoneHBuff;
	class CFSecSecAppHBuff;
	class CFSecSecDeviceHBuff;
	class CFSecSecFormHBuff;
	class CFSecSecGroupHBuff;
	class CFSecSecGroupFormHBuff;
	class CFSecSecGrpIncHBuff;
	class CFSecSecGrpMembHBuff;
	class CFSecSecUserHBuff;
	class CFSecServiceHBuff;
	class CFSecServiceTypeHBuff;
	class CFSecTSecGroupHBuff;
	class CFSecTSecGrpIncHBuff;
	class CFSecTSecGrpMembHBuff;
	class CFSecTenantHBuff;

	class ICFSecClusterTable;
	class ICFSecHostNodeTable;
	class ICFSecISOCcyTable;
	class ICFSecISOCtryTable;
	class ICFSecISOCtryCcyTable;
	class ICFSecISOCtryLangTable;
	class ICFSecISOLangTable;
	class ICFSecISOTZoneTable;
	class ICFSecSecAppTable;
	class ICFSecSecDeviceTable;
	class ICFSecSecFormTable;
	class ICFSecSecGroupTable;
	class ICFSecSecGroupFormTable;
	class ICFSecSecGrpIncTable;
	class ICFSecSecGrpMembTable;
	class ICFSecSecSessionTable;
	class ICFSecSecUserTable;
	class ICFSecServiceTable;
	class ICFSecServiceTypeTable;
	class ICFSecSysClusterTable;
	class ICFSecTSecGroupTable;
	class ICFSecTSecGrpIncTable;
	class ICFSecTSecGrpMembTable;
	class ICFSecTenantTable;
}


namespace cfsec {

	class ICFSecSchema
	{
	public:
		static const std::string CLASS_NAME;
		enum AuditActionEnum {
			Create,
			Update,
			Delete
		};


	public:
		ICFSecSchema();
		virtual ~ICFSecSchema();

		static AuditActionEnum* parseAuditActionEnum( const std::string* value );
		static AuditActionEnum* parseAuditActionEnum( const std::string& fieldOrClassName, const std::string* value );
		static const std::string* toAuditActionEnumString( const AuditActionEnum value );

		static const AuditActionEnum ordinalToAuditActionEnum( const std::string& fieldOrClassName, const int16_t value );
		static const AuditActionEnum* ordinalToAuditActionEnum( const std::string& fieldOrClassName, const int16_t* value );
		static const AuditActionEnum ordinalToAuditActionEnum( const int16_t value );
		static const AuditActionEnum* ordinalToAuditActionEnum( const int16_t* value );
		static const AuditActionEnum ordinalToAuditActionEnum( const int32_t value );
		static const AuditActionEnum* ordinalToAuditActionEnum( const int32_t* value );
		static const AuditActionEnum ordinalToAuditActionEnum( const std::string& fieldOrClassName, const int32_t value );
		static const AuditActionEnum* ordinalToAuditActionEnum( const std::string& fieldOrClassName, const int32_t* value );

		virtual cfsec::CFSecConfigurationFile* getConfigurationFile() const = 0;
		virtual void setConfigurationFile( cfsec::CFSecConfigurationFile* value ) = 0;

		virtual const std::string* getJndiName() const = 0;
		virtual void setJndiName( const std::string& value ) = 0;

		virtual cfsec::CFSecAuthorization* getAuthorization() const = 0;
		virtual void setAuthorization( cfsec::CFSecAuthorization* value ) = 0;

		virtual bool isConnected() = 0;
		virtual bool connect() = 0;
		virtual bool connect( const std::string& username, const std::string& password ) = 0;
		virtual bool connect( const std::string& loginId, const std::string& password, const std::string& clusterName, const std::string& tenantName ) = 0;
		virtual void disconnect( bool doCommit ) = 0;
		virtual void logout( cfsec::CFSecAuthorization* auth ) = 0;

		virtual std::string fileImport( const cfsec::CFSecAuthorization* auth, const std::string& fileName, const std::string& fileContent ) = 0;

		virtual ICFSecSchema* newSchema() = 0;

		virtual int16_t nextISOCcyIdGen() = 0;

		virtual int16_t nextISOCtryIdGen() = 0;

		virtual int16_t nextISOLangIdGen() = 0;

		virtual int16_t nextISOTZoneIdGen() = 0;

		virtual int32_t nextServiceTypeIdGen() = 0;

		virtual int64_t nextClusterIdGen() = 0;

		virtual int64_t nextTenantIdGen() = 0;

		virtual cfsec::ICFSecClusterTable* getTableCluster() = 0;

		virtual cfsec::ICFSecHostNodeTable* getTableHostNode() = 0;

		virtual cfsec::ICFSecISOCcyTable* getTableISOCcy() = 0;

		virtual cfsec::ICFSecISOCtryTable* getTableISOCtry() = 0;

		virtual cfsec::ICFSecISOCtryCcyTable* getTableISOCtryCcy() = 0;

		virtual cfsec::ICFSecISOCtryLangTable* getTableISOCtryLang() = 0;

		virtual cfsec::ICFSecISOLangTable* getTableISOLang() = 0;

		virtual cfsec::ICFSecISOTZoneTable* getTableISOTZone() = 0;

		virtual cfsec::ICFSecSecAppTable* getTableSecApp() = 0;

		virtual cfsec::ICFSecSecDeviceTable* getTableSecDevice() = 0;

		virtual cfsec::ICFSecSecFormTable* getTableSecForm() = 0;

		virtual cfsec::ICFSecSecGroupTable* getTableSecGroup() = 0;

		virtual cfsec::ICFSecSecGroupFormTable* getTableSecGroupForm() = 0;

		virtual cfsec::ICFSecSecGrpIncTable* getTableSecGrpInc() = 0;

		virtual cfsec::ICFSecSecGrpMembTable* getTableSecGrpMemb() = 0;

		virtual cfsec::ICFSecSecSessionTable* getTableSecSession() = 0;

		virtual cfsec::ICFSecSecUserTable* getTableSecUser() = 0;

		virtual cfsec::ICFSecServiceTable* getTableService() = 0;

		virtual cfsec::ICFSecServiceTypeTable* getTableServiceType() = 0;

		virtual cfsec::ICFSecSysClusterTable* getTableSysCluster() = 0;

		virtual cfsec::ICFSecTSecGroupTable* getTableTSecGroup() = 0;

		virtual cfsec::ICFSecTSecGrpIncTable* getTableTSecGrpInc() = 0;

		virtual cfsec::ICFSecTSecGrpMembTable* getTableTSecGrpMemb() = 0;

		virtual cfsec::ICFSecTenantTable* getTableTenant() = 0;

		virtual bool isTransactionOpen() const = 0;
		virtual bool beginTransaction() = 0;
		virtual void commit() = 0;
		virtual void rollback() = 0;

		virtual cfsec::ICFSecTablePerms* getTablePerms() = 0;
		virtual void setTablePerms( cfsec::ICFSecTablePerms* value ) = 0;

		virtual void releasePreparedStatements() = 0;

		virtual const std::string* getDbSchemaName() const = 0;
		virtual const std::string* getLowerDbSchemaName() const = 0;

		virtual void setDbSchemaName( const std::string& argDbSchemaName ) = 0;
;
	};
}
