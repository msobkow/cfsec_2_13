#pragma once

// Description: C++18 specification of a CFSec schema.

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

	class CFSecClusterByUDomNameIdxKey;
	class CFSecClusterByUDescrIdxKey;
	class CFSecHostNodeByClusterIdxKey;
	class CFSecHostNodeByUDescrIdxKey;
	class CFSecHostNodeByHostNameIdxKey;
	class CFSecISOCcyByCcyCdIdxKey;
	class CFSecISOCcyByCcyNmIdxKey;
	class CFSecISOCtryByISOCodeIdxKey;
	class CFSecISOCtryByNameIdxKey;
	class CFSecISOCtryCcyByCtryIdxKey;
	class CFSecISOCtryCcyByCcyIdxKey;
	class CFSecISOCtryLangByCtryIdxKey;
	class CFSecISOCtryLangByLangIdxKey;
	class CFSecISOLangByCode3IdxKey;
	class CFSecISOLangByCode2IdxKey;
	class CFSecISOTZoneByOffsetIdxKey;
	class CFSecISOTZoneByUTZNameIdxKey;
	class CFSecISOTZoneByIso8601IdxKey;
	class CFSecSecAppByClusterIdxKey;
	class CFSecSecAppByUJEEMountIdxKey;
	class CFSecSecDeviceByNameIdxKey;
	class CFSecSecDeviceByUserIdxKey;
	class CFSecSecFormByClusterIdxKey;
	class CFSecSecFormBySecAppIdxKey;
	class CFSecSecFormByUJEEServletIdxKey;
	class CFSecSecGroupByClusterIdxKey;
	class CFSecSecGroupByClusterVisIdxKey;
	class CFSecSecGroupByUNameIdxKey;
	class CFSecSecGroupFormByClusterIdxKey;
	class CFSecSecGroupFormByGroupIdxKey;
	class CFSecSecGroupFormByAppIdxKey;
	class CFSecSecGroupFormByFormIdxKey;
	class CFSecSecGroupFormByUFormIdxKey;
	class CFSecSecGrpIncByClusterIdxKey;
	class CFSecSecGrpIncByGroupIdxKey;
	class CFSecSecGrpIncByIncludeIdxKey;
	class CFSecSecGrpIncByUIncludeIdxKey;
	class CFSecSecGrpMembByClusterIdxKey;
	class CFSecSecGrpMembByGroupIdxKey;
	class CFSecSecGrpMembByUserIdxKey;
	class CFSecSecGrpMembByUUserIdxKey;
	class CFSecSecSessionBySecUserIdxKey;
	class CFSecSecSessionBySecDevIdxKey;
	class CFSecSecSessionByStartIdxKey;
	class CFSecSecSessionByFinishIdxKey;
	class CFSecSecSessionBySecProxyIdxKey;
	class CFSecSecUserByULoginIdxKey;
	class CFSecSecUserByEMConfIdxKey;
	class CFSecSecUserByPwdResetIdxKey;
	class CFSecSecUserByDefDevIdxKey;
	class CFSecServiceByClusterIdxKey;
	class CFSecServiceByHostIdxKey;
	class CFSecServiceByTypeIdxKey;
	class CFSecServiceByUTypeIdxKey;
	class CFSecServiceByUHostPortIdxKey;
	class CFSecServiceTypeByUDescrIdxKey;
	class CFSecSysClusterByClusterIdxKey;
	class CFSecTSecGroupByTenantIdxKey;
	class CFSecTSecGroupByTenantVisIdxKey;
	class CFSecTSecGroupByUNameIdxKey;
	class CFSecTSecGrpIncByTenantIdxKey;
	class CFSecTSecGrpIncByGroupIdxKey;
	class CFSecTSecGrpIncByIncludeIdxKey;
	class CFSecTSecGrpIncByUIncludeIdxKey;
	class CFSecTSecGrpMembByTenantIdxKey;
	class CFSecTSecGrpMembByGroupIdxKey;
	class CFSecTSecGrpMembByUserIdxKey;
	class CFSecTSecGrpMembByUUserIdxKey;
	class CFSecTenantByClusterIdxKey;
	class CFSecTenantByUNameIdxKey;

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

#include <cfsec/ICFSecSchema.hpp>

#include <cfsec/CFSecAuthorization.hpp>
#include <cfsec/CFSecConfigurationFile.hpp>
#include <cfsec/ICFSecTablePerms.hpp>

namespace cfsec {

	class CFSecSchema
	: public virtual cfsec::ICFSecSchema
	{
	protected:
		cfsec::CFSecAuthorization* authorization;
cfsec::ICFSecTablePerms* tablePerms;
cfsec::CFSecConfigurationFile* configuration;
		std::string* jndiName;
		std::string* schemaDbName;
		std::string* lowerDbSchemaName;
		cfsec::ICFSecClusterTable* tableCluster;
		cfsec::ICFSecHostNodeTable* tableHostNode;
		cfsec::ICFSecISOCcyTable* tableISOCcy;
		cfsec::ICFSecISOCtryTable* tableISOCtry;
		cfsec::ICFSecISOCtryCcyTable* tableISOCtryCcy;
		cfsec::ICFSecISOCtryLangTable* tableISOCtryLang;
		cfsec::ICFSecISOLangTable* tableISOLang;
		cfsec::ICFSecISOTZoneTable* tableISOTZone;
		cfsec::ICFSecSecAppTable* tableSecApp;
		cfsec::ICFSecSecDeviceTable* tableSecDevice;
		cfsec::ICFSecSecFormTable* tableSecForm;
		cfsec::ICFSecSecGroupTable* tableSecGroup;
		cfsec::ICFSecSecGroupFormTable* tableSecGroupForm;
		cfsec::ICFSecSecGrpIncTable* tableSecGrpInc;
		cfsec::ICFSecSecGrpMembTable* tableSecGrpMemb;
		cfsec::ICFSecSecSessionTable* tableSecSession;
		cfsec::ICFSecSecUserTable* tableSecUser;
		cfsec::ICFSecServiceTable* tableService;
		cfsec::ICFSecServiceTypeTable* tableServiceType;
		cfsec::ICFSecSysClusterTable* tableSysCluster;
		cfsec::ICFSecTSecGroupTable* tableTSecGroup;
		cfsec::ICFSecTSecGrpIncTable* tableTSecGrpInc;
		cfsec::ICFSecTSecGrpMembTable* tableTSecGrpMemb;
		cfsec::ICFSecTenantTable* tableTenant;

	public:
		static const std::string CLASS_NAME;

		CFSecSchema();
		CFSecSchema( cfsec::CFSecConfigurationFile* conf );
		CFSecSchema( const std::string& argJndiName );
		virtual ~CFSecSchema();

		virtual cfsec::CFSecConfigurationFile* getConfigurationFile() const;
		virtual void setConfigurationFile( cfsec::CFSecConfigurationFile* value );

		virtual cfsec::CFSecAuthorization* getAuthorization() const;
		virtual void setAuthorization( cfsec::CFSecAuthorization* value );

		virtual const std::string* getJndiName() const;
		virtual void setJndiName( const std::string& value );

		virtual bool isConnected();
		virtual bool connect();
		virtual bool connect( const std::string& username, const std::string& password );
		virtual bool connect( const std::string& loginId, const std::string& password, const std::string& clusterName, const std::string& tenantName );
		virtual void disconnect( bool doCommit );
		virtual void logout( cfsec::CFSecAuthorization* auth );

		virtual cfsec::ICFSecSchema* newSchema();

		virtual std::string fileImport( const cfsec::CFSecAuthorization* auth, const std::string& fileName, const std::string& fileContent );

		virtual int16_t nextISOCcyIdGen();

		virtual int16_t nextISOCtryIdGen();

		virtual int16_t nextISOLangIdGen();

		virtual int16_t nextISOTZoneIdGen();

		virtual int32_t nextServiceTypeIdGen();

		virtual int64_t nextClusterIdGen();

		virtual int64_t nextTenantIdGen();

		virtual cfsec::ICFSecClusterTable* getTableCluster();
		virtual void setTableCluster( cfsec::ICFSecClusterTable* value );

		virtual cfsec::ICFSecHostNodeTable* getTableHostNode();
		virtual void setTableHostNode( cfsec::ICFSecHostNodeTable* value );

		virtual cfsec::ICFSecISOCcyTable* getTableISOCcy();
		virtual void setTableISOCcy( cfsec::ICFSecISOCcyTable* value );

		virtual cfsec::ICFSecISOCtryTable* getTableISOCtry();
		virtual void setTableISOCtry( cfsec::ICFSecISOCtryTable* value );

		virtual cfsec::ICFSecISOCtryCcyTable* getTableISOCtryCcy();
		virtual void setTableISOCtryCcy( cfsec::ICFSecISOCtryCcyTable* value );

		virtual cfsec::ICFSecISOCtryLangTable* getTableISOCtryLang();
		virtual void setTableISOCtryLang( cfsec::ICFSecISOCtryLangTable* value );

		virtual cfsec::ICFSecISOLangTable* getTableISOLang();
		virtual void setTableISOLang( cfsec::ICFSecISOLangTable* value );

		virtual cfsec::ICFSecISOTZoneTable* getTableISOTZone();
		virtual void setTableISOTZone( cfsec::ICFSecISOTZoneTable* value );

		virtual cfsec::ICFSecSecAppTable* getTableSecApp();
		virtual void setTableSecApp( cfsec::ICFSecSecAppTable* value );

		virtual cfsec::ICFSecSecDeviceTable* getTableSecDevice();
		virtual void setTableSecDevice( cfsec::ICFSecSecDeviceTable* value );

		virtual cfsec::ICFSecSecFormTable* getTableSecForm();
		virtual void setTableSecForm( cfsec::ICFSecSecFormTable* value );

		virtual cfsec::ICFSecSecGroupTable* getTableSecGroup();
		virtual void setTableSecGroup( cfsec::ICFSecSecGroupTable* value );

		virtual cfsec::ICFSecSecGroupFormTable* getTableSecGroupForm();
		virtual void setTableSecGroupForm( cfsec::ICFSecSecGroupFormTable* value );

		virtual cfsec::ICFSecSecGrpIncTable* getTableSecGrpInc();
		virtual void setTableSecGrpInc( cfsec::ICFSecSecGrpIncTable* value );

		virtual cfsec::ICFSecSecGrpMembTable* getTableSecGrpMemb();
		virtual void setTableSecGrpMemb( cfsec::ICFSecSecGrpMembTable* value );

		virtual cfsec::ICFSecSecSessionTable* getTableSecSession();
		virtual void setTableSecSession( cfsec::ICFSecSecSessionTable* value );

		virtual cfsec::ICFSecSecUserTable* getTableSecUser();
		virtual void setTableSecUser( cfsec::ICFSecSecUserTable* value );

		virtual cfsec::ICFSecServiceTable* getTableService();
		virtual void setTableService( cfsec::ICFSecServiceTable* value );

		virtual cfsec::ICFSecServiceTypeTable* getTableServiceType();
		virtual void setTableServiceType( cfsec::ICFSecServiceTypeTable* value );

		virtual cfsec::ICFSecSysClusterTable* getTableSysCluster();
		virtual void setTableSysCluster( cfsec::ICFSecSysClusterTable* value );

		virtual cfsec::ICFSecTSecGroupTable* getTableTSecGroup();
		virtual void setTableTSecGroup( cfsec::ICFSecTSecGroupTable* value );

		virtual cfsec::ICFSecTSecGrpIncTable* getTableTSecGrpInc();
		virtual void setTableTSecGrpInc( cfsec::ICFSecTSecGrpIncTable* value );

		virtual cfsec::ICFSecTSecGrpMembTable* getTableTSecGrpMemb();
		virtual void setTableTSecGrpMemb( cfsec::ICFSecTSecGrpMembTable* value );

		virtual cfsec::ICFSecTenantTable* getTableTenant();
		virtual void setTableTenant( cfsec::ICFSecTenantTable* value );

		virtual bool isTransactionOpen() const;
		virtual bool beginTransaction();
		virtual void commit();
		virtual void rollback();

		virtual cfsec::ICFSecTablePerms* getTablePerms();
		virtual void setTablePerms( cfsec::ICFSecTablePerms* value );

		virtual void releasePreparedStatements();

		virtual const std::string* getDbSchemaName() const;
		virtual const std::string* getLowerDbSchemaName() const;
		virtual void setDbSchemaName( const std::string& argDbSchemaName );
	};
}
