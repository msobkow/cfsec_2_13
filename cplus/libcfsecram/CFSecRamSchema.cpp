// Description: C++18 Implementation of an in-memory RAM CFSec schema.

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
#include <cfsecobj/CFSecSchemaObj.hpp>
#include <cfsecsaxloader/CFSecSaxLoader.hpp>
#include <cfsecram/CFSecRamSchema.hpp>
#include <cfsecram/CFSecRamClusterTable.hpp>
#include <cfsecram/CFSecRamHostNodeTable.hpp>
#include <cfsecram/CFSecRamISOCcyTable.hpp>
#include <cfsecram/CFSecRamISOCtryTable.hpp>
#include <cfsecram/CFSecRamISOCtryCcyTable.hpp>
#include <cfsecram/CFSecRamISOCtryLangTable.hpp>
#include <cfsecram/CFSecRamISOLangTable.hpp>
#include <cfsecram/CFSecRamISOTZoneTable.hpp>
#include <cfsecram/CFSecRamSecAppTable.hpp>
#include <cfsecram/CFSecRamSecDeviceTable.hpp>
#include <cfsecram/CFSecRamSecFormTable.hpp>
#include <cfsecram/CFSecRamSecGroupTable.hpp>
#include <cfsecram/CFSecRamSecGroupFormTable.hpp>
#include <cfsecram/CFSecRamSecGrpIncTable.hpp>
#include <cfsecram/CFSecRamSecGrpMembTable.hpp>
#include <cfsecram/CFSecRamSecSessionTable.hpp>
#include <cfsecram/CFSecRamSecUserTable.hpp>
#include <cfsecram/CFSecRamServiceTable.hpp>
#include <cfsecram/CFSecRamServiceTypeTable.hpp>
#include <cfsecram/CFSecRamSysClusterTable.hpp>
#include <cfsecram/CFSecRamTSecGroupTable.hpp>
#include <cfsecram/CFSecRamTSecGrpIncTable.hpp>
#include <cfsecram/CFSecRamTSecGrpMembTable.hpp>
#include <cfsecram/CFSecRamTenantTable.hpp>

using namespace std;

namespace cfsec {

	const std::string CFSecRamSchema::CLASS_NAME( "CFSecRamSchema" );

	CFSecRamSchema::CFSecRamSchema()
	: cfsec::CFSecSchema(),
	  cfsec::ICFSecSchema()
	{
		sessConnected = false;
		tranOpen = false;
		nextISOCcyIdGenValue = 1;
		nextISOCtryIdGenValue = 1;
		nextISOLangIdGenValue = 1;
		nextISOTZoneIdGenValue = 1;
		nextServiceTypeIdGenValue = 1;
		nextClusterIdGenValue = 1L;
		nextTenantIdGenValue = 1L;
		tableCluster = new CFSecRamClusterTable( this );
		tableHostNode = new CFSecRamHostNodeTable( this );
		tableISOCcy = new CFSecRamISOCcyTable( this );
		tableISOCtry = new CFSecRamISOCtryTable( this );
		tableISOCtryCcy = new CFSecRamISOCtryCcyTable( this );
		tableISOCtryLang = new CFSecRamISOCtryLangTable( this );
		tableISOLang = new CFSecRamISOLangTable( this );
		tableISOTZone = new CFSecRamISOTZoneTable( this );
		tableSecApp = new CFSecRamSecAppTable( this );
		tableSecDevice = new CFSecRamSecDeviceTable( this );
		tableSecForm = new CFSecRamSecFormTable( this );
		tableSecGroup = new CFSecRamSecGroupTable( this );
		tableSecGroupForm = new CFSecRamSecGroupFormTable( this );
		tableSecGrpInc = new CFSecRamSecGrpIncTable( this );
		tableSecGrpMemb = new CFSecRamSecGrpMembTable( this );
		tableSecSession = new CFSecRamSecSessionTable( this );
		tableSecUser = new CFSecRamSecUserTable( this );
		tableService = new CFSecRamServiceTable( this );
		tableServiceType = new CFSecRamServiceTypeTable( this );
		tableSysCluster = new CFSecRamSysClusterTable( this );
		tableTSecGroup = new CFSecRamTSecGroupTable( this );
		tableTSecGrpInc = new CFSecRamTSecGrpIncTable( this );
		tableTSecGrpMemb = new CFSecRamTSecGrpMembTable( this );
		tableTenant = new CFSecRamTenantTable( this );
	}

	CFSecRamSchema::~CFSecRamSchema() {
		tranOpen = false;
		sessConnected = false;
		if( tableCluster != NULL ) {
			delete tableCluster;
			tableCluster = NULL;
		}
		if( tableHostNode != NULL ) {
			delete tableHostNode;
			tableHostNode = NULL;
		}
		if( tableISOCcy != NULL ) {
			delete tableISOCcy;
			tableISOCcy = NULL;
		}
		if( tableISOCtry != NULL ) {
			delete tableISOCtry;
			tableISOCtry = NULL;
		}
		if( tableISOCtryCcy != NULL ) {
			delete tableISOCtryCcy;
			tableISOCtryCcy = NULL;
		}
		if( tableISOCtryLang != NULL ) {
			delete tableISOCtryLang;
			tableISOCtryLang = NULL;
		}
		if( tableISOLang != NULL ) {
			delete tableISOLang;
			tableISOLang = NULL;
		}
		if( tableISOTZone != NULL ) {
			delete tableISOTZone;
			tableISOTZone = NULL;
		}
		if( tableSecApp != NULL ) {
			delete tableSecApp;
			tableSecApp = NULL;
		}
		if( tableSecDevice != NULL ) {
			delete tableSecDevice;
			tableSecDevice = NULL;
		}
		if( tableSecForm != NULL ) {
			delete tableSecForm;
			tableSecForm = NULL;
		}
		if( tableSecGroup != NULL ) {
			delete tableSecGroup;
			tableSecGroup = NULL;
		}
		if( tableSecGroupForm != NULL ) {
			delete tableSecGroupForm;
			tableSecGroupForm = NULL;
		}
		if( tableSecGrpInc != NULL ) {
			delete tableSecGrpInc;
			tableSecGrpInc = NULL;
		}
		if( tableSecGrpMemb != NULL ) {
			delete tableSecGrpMemb;
			tableSecGrpMemb = NULL;
		}
		if( tableSecSession != NULL ) {
			delete tableSecSession;
			tableSecSession = NULL;
		}
		if( tableSecUser != NULL ) {
			delete tableSecUser;
			tableSecUser = NULL;
		}
		if( tableService != NULL ) {
			delete tableService;
			tableService = NULL;
		}
		if( tableServiceType != NULL ) {
			delete tableServiceType;
			tableServiceType = NULL;
		}
		if( tableSysCluster != NULL ) {
			delete tableSysCluster;
			tableSysCluster = NULL;
		}
		if( tableTSecGroup != NULL ) {
			delete tableTSecGroup;
			tableTSecGroup = NULL;
		}
		if( tableTSecGrpInc != NULL ) {
			delete tableTSecGrpInc;
			tableTSecGrpInc = NULL;
		}
		if( tableTSecGrpMemb != NULL ) {
			delete tableTSecGrpMemb;
			tableTSecGrpMemb = NULL;
		}
		if( tableTenant != NULL ) {
			delete tableTenant;
			tableTenant = NULL;
		}
	}

	bool CFSecRamSchema::isConnected() {
		return( sessConnected );
	}

	bool CFSecRamSchema::connect() {
		if( sessConnected ) {
			return( false );
		}
		else {
			sessConnected = true;
			tranOpen = false;
			return( true );
		}
	}

	bool CFSecRamSchema::connect( const std::string& username, const std::string& password ) {
		static const std::string S_ProcName( "connect" );
		static const std::string S_UserName( "username" );
		static const std::string S_System( "system" );
		static const std::string S_MsgOnlySystem( "Only 'system' is authorized to use a RAM database" );
		if( username.length() <= 0 ) {
			throw cflib::CFLibEmptyArgumentException( CLASS_NAME,
				S_ProcName,
				1,
				S_UserName );
		}
		if( username != S_System ) {
			throw cflib::CFLibRuntimeException( CLASS_NAME,
				S_ProcName,
				S_MsgOnlySystem );
		}
		if( sessConnected ) {
			return( false );
		}
		else {
			sessConnected = true;
			tranOpen = false;
			return( true );
		}
	}

	bool CFSecRamSchema::connect( const std::string& loginId, const std::string& password, const std::string& clusterName, const std::string& tenantName ) {
		static const std::string S_ProcName( "connect" );
		static const std::string S_LoginId( "loginId" );
		static const std::string S_ClusterName( "clusterName" );
		static const std::string S_TenantName( "tenantName" );
		static const std::string S_System( "system" );
		static const std::string S_MsgOnlySystemAuthorized( "Only 'system' is authorized to use a RAM database" );
		static const std::string S_MsgOnlySystemClusterAuthorized( "Only the 'system' Cluster is authorized to use a RAM database" );
		static const std::string S_MsgOnlySystemTenantAuthorized( "Only the 'system' Tenant is authorized to use a RAM database" );
		if( loginId.length() <= 0 ) {
			throw cflib::CFLibEmptyArgumentException( CLASS_NAME,
				S_ProcName,
				1,
				S_LoginId );
		}
		if( clusterName.length() <= 0 ) {
			throw cflib::CFLibEmptyArgumentException( CLASS_NAME,
				S_ProcName,
				3,
				S_ClusterName );
		}
		if( tenantName.length() <= 0 ) {
			throw cflib::CFLibEmptyArgumentException( CLASS_NAME,
				S_ProcName,
				4,
				S_TenantName );
		}
		if( loginId != S_System ) {
			throw cflib::CFLibRuntimeException( CLASS_NAME,
				S_ProcName,
				S_MsgOnlySystemAuthorized );
		}
		if( clusterName != S_System ) {
			throw cflib::CFLibRuntimeException( CLASS_NAME,
				S_ProcName,
				S_MsgOnlySystemClusterAuthorized );
		}
		if( tenantName != S_System ) {
			throw cflib::CFLibRuntimeException( CLASS_NAME,
				S_ProcName,
				S_MsgOnlySystemTenantAuthorized );
		}
		if( sessConnected ) {
			return( false );
		}
		else {
			sessConnected = true;
			tranOpen = false;
			return( true );
		}
	}

	void CFSecRamSchema::disconnect( bool doCommit ) {
		tranOpen = false;
		sessConnected = false;
	}

	//	Transactions are not supported, so pretend there is always one open

	bool CFSecRamSchema::isTransactionOpen() {
		return( tranOpen );
	}

	bool CFSecRamSchema::beginTransaction() {
		if( tranOpen ) {
			return( false );
		}
		tranOpen = true;
		return( true );
	}

	void CFSecRamSchema::commit() {
		tranOpen = false;
	}

	void CFSecRamSchema::rollback() {
		tranOpen = false;
	}

	cfsec::ICFSecSchema* CFSecRamSchema::newSchema() {
		static const std::string S_ProcName( "newSchema" );
		throw cflib::CFLibMustOverrideException( CLASS_NAME, S_ProcName );
	}

	int16_t CFSecRamSchema::nextISOCcyIdGen() {
		int16_t next = nextISOCcyIdGenValue++;
		return( next );
	}

	int16_t CFSecRamSchema::nextISOCtryIdGen() {
		int16_t next = nextISOCtryIdGenValue++;
		return( next );
	}

	int16_t CFSecRamSchema::nextISOLangIdGen() {
		int16_t next = nextISOLangIdGenValue++;
		return( next );
	}

	int16_t CFSecRamSchema::nextISOTZoneIdGen() {
		int16_t next = nextISOTZoneIdGenValue++;
		return( next );
	}

	int32_t CFSecRamSchema::nextServiceTypeIdGen() {
		int32_t next = nextServiceTypeIdGenValue++;
		return( next );
	}

	int64_t CFSecRamSchema::nextClusterIdGen() {
		int64_t next = nextClusterIdGenValue++;
		return( next );
	}

	int64_t CFSecRamSchema::nextTenantIdGen() {
		int64_t next = nextTenantIdGenValue++;
		return( next );
	}

	void CFSecRamSchema::releasePreparedStatements() {
	}

	std::string CFSecRamSchema::fileImport( cfsec::CFSecAuthorization* Authorization,
		const std::string& fileName,
		const std::string& fileContent )
	{
		const static std::string S_ProcName( "fileImport" );
		const static std::string S_FileName( "fileName" );
		const static std::string S_FileContent( "fileContent" );
		if( fileName.length() <= 0 ) {
			throw cflib::CFLibEmptyArgumentException( CLASS_NAME,
				S_ProcName,
				1,
				S_FileName );
		}
		if( fileContent.length() <= 0 ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				2,
				S_FileContent );
		}
		cfsec::CFSecSaxLoader* saxLoader = new cfsec::CFSecSaxLoader();
		cfsec::ICFSecSchemaObj* schemaObj = new cfsec::CFSecSchemaObj();
		schemaObj->setBackingStore( this );
		saxLoader->setSchemaObj( schemaObj );
		cfsec::ICFSecClusterObj* useCluster = schemaObj->getClusterTableObj()->readClusterByIdIdx( Authorization->getSecClusterId() );
		cfsec::ICFSecTenantObj* useTenant = schemaObj->getTenantTableObj()->readTenantByIdIdx( Authorization->getSecTenantId() );
		cflib::CFLibCachedMessageLog runlog;
		saxLoader->setLog( &runlog );
		saxLoader->setUseCluster( useCluster );
		saxLoader->setUseTenant( useTenant );
		// MSS TODO WORKING - Need to wrap parseStringContents() with try-catch so it can never crash out
		saxLoader->parseStringContents( fileName, fileContent );
		return( runlog.getCacheContents() );
	}

}
