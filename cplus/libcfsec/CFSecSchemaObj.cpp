// Description: C++18 Schema Object implementation for CFSec.

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

using namespace std;

#include <cfsec/ICFSecPublic.hpp>
#include <cfsecobj/ICFSecObjPublic.hpp>
#include <cfsecobj/CFSecSchemaObj.hpp>

#include <cfsecobj/CFSecClusterTableObj.hpp>
#include <cfsecobj/CFSecHostNodeTableObj.hpp>
#include <cfsecobj/CFSecISOCcyTableObj.hpp>
#include <cfsecobj/CFSecISOCtryTableObj.hpp>
#include <cfsecobj/CFSecISOCtryCcyTableObj.hpp>
#include <cfsecobj/CFSecISOCtryLangTableObj.hpp>
#include <cfsecobj/CFSecISOLangTableObj.hpp>
#include <cfsecobj/CFSecISOTZoneTableObj.hpp>
#include <cfsecobj/CFSecSecAppTableObj.hpp>
#include <cfsecobj/CFSecSecDeviceTableObj.hpp>
#include <cfsecobj/CFSecSecFormTableObj.hpp>
#include <cfsecobj/CFSecSecGroupTableObj.hpp>
#include <cfsecobj/CFSecSecGroupFormTableObj.hpp>
#include <cfsecobj/CFSecSecGrpIncTableObj.hpp>
#include <cfsecobj/CFSecSecGrpMembTableObj.hpp>
#include <cfsecobj/CFSecSecSessionTableObj.hpp>
#include <cfsecobj/CFSecSecUserTableObj.hpp>
#include <cfsecobj/CFSecServiceTableObj.hpp>
#include <cfsecobj/CFSecServiceTypeTableObj.hpp>
#include <cfsecobj/CFSecSysClusterTableObj.hpp>
#include <cfsecobj/CFSecTSecGroupTableObj.hpp>
#include <cfsecobj/CFSecTSecGrpIncTableObj.hpp>
#include <cfsecobj/CFSecTSecGrpMembTableObj.hpp>
#include <cfsecobj/CFSecTenantTableObj.hpp>

namespace cfsec {
	const std::string CFSecSchemaObj::CLASS_NAME( "CFSecSchemaObj" );
	const std::string CFSecSchemaObj::SCHEMA_NAME( "CFSec" );
	const std::string CFSecSchemaObj::SCHEMA_DBNAME( "cfsec213" );
	const std::string CFSecSchemaObj::S_System( "system" );

	CFSecSchemaObj::CFSecSchemaObj() {
		authorization = NULL;
		backingStore = NULL;
		secClusterName = new std::string( S_System );
		secTenantName = new std::string( S_System );
		secUserName = new std::string( S_System );
		secCluster = NULL;
		secClusterId = 0L;
		secTenant = NULL;
		secTenantId = 0L;
		secUser = NULL;
		for( int i = 0; i < 16; i++ ) {
			secSessionUserId[i] = 0;
		}
		secSession = NULL;
		for( int i = 0; i < 16; i++ ) {
			secSessionSessionId[i] = 0;
		}
		schemaDbName = new std::string( SCHEMA_DBNAME );
		lowerDbSchemaName = new std::string( SCHEMA_DBNAME );
		std::transform( lowerDbSchemaName->begin(), lowerDbSchemaName->end(), lowerDbSchemaName->begin(), ::tolower );
		clusterTableObj = new CFSecClusterTableObj( this );
		hostNodeTableObj = new CFSecHostNodeTableObj( this );
		iSOCcyTableObj = new CFSecISOCcyTableObj( this );
		iSOCtryTableObj = new CFSecISOCtryTableObj( this );
		iSOCtryCcyTableObj = new CFSecISOCtryCcyTableObj( this );
		iSOCtryLangTableObj = new CFSecISOCtryLangTableObj( this );
		iSOLangTableObj = new CFSecISOLangTableObj( this );
		iSOTZoneTableObj = new CFSecISOTZoneTableObj( this );
		secAppTableObj = new CFSecSecAppTableObj( this );
		secDeviceTableObj = new CFSecSecDeviceTableObj( this );
		secFormTableObj = new CFSecSecFormTableObj( this );
		secGroupTableObj = new CFSecSecGroupTableObj( this );
		secGroupFormTableObj = new CFSecSecGroupFormTableObj( this );
		secGrpIncTableObj = new CFSecSecGrpIncTableObj( this );
		secGrpMembTableObj = new CFSecSecGrpMembTableObj( this );
		secSessionTableObj = new CFSecSecSessionTableObj( this );
		secUserTableObj = new CFSecSecUserTableObj( this );
		serviceTableObj = new CFSecServiceTableObj( this );
		serviceTypeTableObj = new CFSecServiceTypeTableObj( this );
		sysClusterTableObj = new CFSecSysClusterTableObj( this );
		tSecGroupTableObj = new CFSecTSecGroupTableObj( this );
		tSecGrpIncTableObj = new CFSecTSecGrpIncTableObj( this );
		tSecGrpMembTableObj = new CFSecTSecGrpMembTableObj( this );
		tenantTableObj = new CFSecTenantTableObj( this );
	}

	CFSecSchemaObj::~CFSecSchemaObj() {
		authorization = NULL;
		backingStore = NULL;
		if( secClusterName != NULL ) {
			delete secClusterName;
			secClusterName = NULL;
		}
		if( secTenantName != NULL ) {
			delete secTenantName;
			secTenantName = NULL;
		}
		if( secUserName != NULL ) {
			delete secUserName;
			secUserName = NULL;
		}
		secCluster = NULL;
		secClusterId = 0L;
		secTenant = NULL;
		secTenantId = 0L;
		secUser = NULL;
		for( int i = 0; i < 16; i++ ) {
			secSessionUserId[i] = 0;
		}
		for( int i = 0; i < 16; i++ ) {
			secSessionSessionId[i] = 0;
		}
		if( schemaDbName != NULL ) {
			delete schemaDbName;
			schemaDbName = NULL;
		}
		if( lowerDbSchemaName != NULL ) {
			delete lowerDbSchemaName;
			lowerDbSchemaName = NULL;
		}

		if( clusterTableObj != NULL ) {
			clusterTableObj->minimizeMemory();
		}

		if( clusterTableObj != NULL ) {
			delete clusterTableObj;
			clusterTableObj = NULL;
		}

		if( hostNodeTableObj != NULL ) {
			hostNodeTableObj->minimizeMemory();
		}

		if( hostNodeTableObj != NULL ) {
			delete hostNodeTableObj;
			hostNodeTableObj = NULL;
		}

		if( iSOCcyTableObj != NULL ) {
			iSOCcyTableObj->minimizeMemory();
		}

		if( iSOCcyTableObj != NULL ) {
			delete iSOCcyTableObj;
			iSOCcyTableObj = NULL;
		}

		if( iSOCtryTableObj != NULL ) {
			iSOCtryTableObj->minimizeMemory();
		}

		if( iSOCtryTableObj != NULL ) {
			delete iSOCtryTableObj;
			iSOCtryTableObj = NULL;
		}

		if( iSOCtryCcyTableObj != NULL ) {
			iSOCtryCcyTableObj->minimizeMemory();
		}

		if( iSOCtryCcyTableObj != NULL ) {
			delete iSOCtryCcyTableObj;
			iSOCtryCcyTableObj = NULL;
		}

		if( iSOCtryLangTableObj != NULL ) {
			iSOCtryLangTableObj->minimizeMemory();
		}

		if( iSOCtryLangTableObj != NULL ) {
			delete iSOCtryLangTableObj;
			iSOCtryLangTableObj = NULL;
		}

		if( iSOLangTableObj != NULL ) {
			iSOLangTableObj->minimizeMemory();
		}

		if( iSOLangTableObj != NULL ) {
			delete iSOLangTableObj;
			iSOLangTableObj = NULL;
		}

		if( iSOTZoneTableObj != NULL ) {
			iSOTZoneTableObj->minimizeMemory();
		}

		if( iSOTZoneTableObj != NULL ) {
			delete iSOTZoneTableObj;
			iSOTZoneTableObj = NULL;
		}

		if( secAppTableObj != NULL ) {
			secAppTableObj->minimizeMemory();
		}

		if( secAppTableObj != NULL ) {
			delete secAppTableObj;
			secAppTableObj = NULL;
		}

		if( secDeviceTableObj != NULL ) {
			secDeviceTableObj->minimizeMemory();
		}

		if( secDeviceTableObj != NULL ) {
			delete secDeviceTableObj;
			secDeviceTableObj = NULL;
		}

		if( secFormTableObj != NULL ) {
			secFormTableObj->minimizeMemory();
		}

		if( secFormTableObj != NULL ) {
			delete secFormTableObj;
			secFormTableObj = NULL;
		}

		if( secGroupTableObj != NULL ) {
			secGroupTableObj->minimizeMemory();
		}

		if( secGroupTableObj != NULL ) {
			delete secGroupTableObj;
			secGroupTableObj = NULL;
		}

		if( secGroupFormTableObj != NULL ) {
			secGroupFormTableObj->minimizeMemory();
		}

		if( secGroupFormTableObj != NULL ) {
			delete secGroupFormTableObj;
			secGroupFormTableObj = NULL;
		}

		if( secGrpIncTableObj != NULL ) {
			secGrpIncTableObj->minimizeMemory();
		}

		if( secGrpIncTableObj != NULL ) {
			delete secGrpIncTableObj;
			secGrpIncTableObj = NULL;
		}

		if( secGrpMembTableObj != NULL ) {
			secGrpMembTableObj->minimizeMemory();
		}

		if( secGrpMembTableObj != NULL ) {
			delete secGrpMembTableObj;
			secGrpMembTableObj = NULL;
		}

		if( secSessionTableObj != NULL ) {
			secSessionTableObj->minimizeMemory();
		}

		if( secSessionTableObj != NULL ) {
			delete secSessionTableObj;
			secSessionTableObj = NULL;
		}

		if( secUserTableObj != NULL ) {
			secUserTableObj->minimizeMemory();
		}

		if( secUserTableObj != NULL ) {
			delete secUserTableObj;
			secUserTableObj = NULL;
		}

		if( serviceTableObj != NULL ) {
			serviceTableObj->minimizeMemory();
		}

		if( serviceTableObj != NULL ) {
			delete serviceTableObj;
			serviceTableObj = NULL;
		}

		if( serviceTypeTableObj != NULL ) {
			serviceTypeTableObj->minimizeMemory();
		}

		if( serviceTypeTableObj != NULL ) {
			delete serviceTypeTableObj;
			serviceTypeTableObj = NULL;
		}

		if( sysClusterTableObj != NULL ) {
			sysClusterTableObj->minimizeMemory();
		}

		if( sysClusterTableObj != NULL ) {
			delete sysClusterTableObj;
			sysClusterTableObj = NULL;
		}

		if( tSecGroupTableObj != NULL ) {
			tSecGroupTableObj->minimizeMemory();
		}

		if( tSecGroupTableObj != NULL ) {
			delete tSecGroupTableObj;
			tSecGroupTableObj = NULL;
		}

		if( tSecGrpIncTableObj != NULL ) {
			tSecGrpIncTableObj->minimizeMemory();
		}

		if( tSecGrpIncTableObj != NULL ) {
			delete tSecGrpIncTableObj;
			tSecGrpIncTableObj = NULL;
		}

		if( tSecGrpMembTableObj != NULL ) {
			tSecGrpMembTableObj->minimizeMemory();
		}

		if( tSecGrpMembTableObj != NULL ) {
			delete tSecGrpMembTableObj;
			tSecGrpMembTableObj = NULL;
		}

		if( tenantTableObj != NULL ) {
			tenantTableObj->minimizeMemory();
		}

		if( tenantTableObj != NULL ) {
			delete tenantTableObj;
			tenantTableObj = NULL;
		}
	}

	void CFSecSchemaObj::setSecClusterName( const std::string& value ) {
		if( value.length() <= 0 ) {
			throw cflib::CFLibEmptyArgumentException( CLASS_NAME,
				"setClusterName",
				1,
				"value" );
		}
		if( secClusterName != NULL ) {
			delete secClusterName;
			secClusterName = NULL;
		}
		secClusterName = new std::string( value );
		secCluster = NULL;
	}

	std::string CFSecSchemaObj::getSecClusterName() {
		std::string retval( *secClusterName );
		return( retval );
	}

	cfsec::ICFSecClusterObj* CFSecSchemaObj::getSecCluster() {
		if( secCluster == NULL ) {
			if( authorization != NULL ) {
				secCluster = getClusterTableObj()->readClusterByIdIdx( authorization->getSecClusterId() );
			}
			else {
				secCluster = getClusterTableObj()->readClusterByUDomNameIdx( *secClusterName );
				if( ( secCluster == NULL ) && ( secClusterId > 0 ) ) {
					secCluster = getClusterTableObj()->readClusterByIdIdx( secClusterId );
				}
			}
			if( secCluster != NULL ) {
				if( secClusterName != NULL ) {
					delete secClusterName;
					secClusterName = NULL;
				}
				secClusterName = new std::string( secCluster->getRequiredFullDomName() );
				secClusterId = secCluster->getRequiredId();
				if( authorization != NULL ) {
					authorization->setSecCluster( *secCluster );
				}
			}
		}
		return( secCluster );
	}

	void CFSecSchemaObj::setSecCluster( cfsec::ICFSecClusterObj* value ) {
		secCluster = value;
		if( secCluster == NULL ) {
			return;
		}
		secClusterId = secCluster->getRequiredId();
		if( secClusterName != NULL ) {
			delete secClusterName;
			secClusterName = NULL;
		}
		secClusterName = new std::string( secCluster->getRequiredFullDomName() );
		if( authorization != NULL ) {
			authorization->setSecCluster( *secCluster );
		}
	}

	long CFSecSchemaObj::getSecClusterId() {
		return( secClusterId );
	}

	void CFSecSchemaObj::setSecTenantName( const std::string& value ) {
		if( value.length() <= 0 ) {
			throw cflib::CFLibEmptyArgumentException( CLASS_NAME,
				"setTenantName",
				1,
				"value" );
		}
		if( secTenantName != NULL ) {
			delete secTenantName;
			secTenantName = NULL;
		}
		secTenantName = new std::string( value );
		secTenant = NULL;
	}

	std::string CFSecSchemaObj::getSecTenantName() {
		std::string retval( *secTenantName );
		return( retval );
	}

	cfsec::ICFSecTenantObj* CFSecSchemaObj::getSecTenant() {
		if( secTenant == NULL ) {
			if( authorization != NULL ) {
				secTenant = getTenantTableObj()->readTenantByIdIdx( authorization->getSecTenantId() );
			}
			else {
				secTenant = getTenantTableObj()->readTenantByUNameIdx( getSecCluster()->getRequiredId(), *secTenantName );
				if( ( secTenant == NULL ) && ( secTenantId > 0 ) ) {
					secTenant = getTenantTableObj()->readTenantByIdIdx( secTenantId );
				}
			}
			if( secTenant != NULL ) {
				if( secTenantName != NULL ) {
					delete secTenantName;
					secTenantName = NULL;
				}
				secTenantName = new std::string( secTenant->getRequiredTenantName() );
				secTenantId = secTenant->getRequiredId();
				if( authorization != NULL ) {
					authorization->setSecTenant( *secTenant );
				}
			}
		}
		return( secTenant );
	}

	void CFSecSchemaObj::setSecTenant( cfsec::ICFSecTenantObj* value ) {
		secTenant = value;
		if( secTenant == NULL ) {
			return;
		}
		secTenantId = secTenant->getRequiredId();
		if( secTenantName != NULL ) {
			delete secTenantName;
			secTenantName = NULL;
		}
		secTenantName = new std::string( secTenant->getRequiredTenantName() );
		if( authorization != NULL ) {
			authorization->setSecTenant( *secTenant );
		}
	}

	long CFSecSchemaObj::getSecTenantId() {
		return( secTenantId );
	}

	void CFSecSchemaObj::setSecUserName( const std::string& value ) {
		if( value.length() <= 0 ) {
			throw cflib::CFLibEmptyArgumentException( CLASS_NAME,
				"setUserName",
				1,
				"value" );
		}
		if( secUserName != NULL ) {
			delete secUserName;
			secUserName = NULL;
		}
		secUserName = new std::string( value );
		secUser = NULL;
	}

	std::string CFSecSchemaObj::getSecUserName() {
		std::string retval( *secUserName );
		return( retval );
	}

	cfsec::ICFSecSecUserObj* CFSecSchemaObj::getSecUser() {
		if( secUser == NULL ) {
			if( authorization != NULL ) {
				secUser = getSecUserTableObj()->readSecUserByIdIdx( authorization->getSecUserId() );
			}
			else {
				secUser = getSecUserTableObj()->readSecUserByULoginIdx( *secUserName );
				if( ( secUser == NULL ) &&
					( ( secSessionUserId[0] != 0 ) || ( secSessionUserId[1] != 0 )
						|| ( secSessionUserId[2] != 0 ) || ( secSessionUserId[3] != 0 )
						|| ( secSessionUserId[4] != 0 ) || ( secSessionUserId[5] != 0 )
						|| ( secSessionUserId[6] != 0 ) || ( secSessionUserId[7] != 0 )
						|| ( secSessionUserId[8] != 0 ) || ( secSessionUserId[9] != 0 )
						|| ( secSessionUserId[10] != 0 ) || ( secSessionUserId[11] != 0 )
						|| ( secSessionUserId[12] != 0 ) || ( secSessionUserId[13] != 0 )
						|| ( secSessionUserId[14] != 0 ) || ( secSessionUserId[15] != 0 ) ) )
				{
					secUser = getSecUserTableObj()->readSecUserByIdIdx( secSessionUserId );
				}
			}
			if( secUser != NULL ) {
				if( secUserName != NULL ) {
					delete secUserName;
					secUserName = NULL;
				}
				secUserName = new std::string( secUser->getRequiredLoginId() );
				uuid_copy( secSessionUserId, secUser->getRequiredSecUserId() );
			}
		}
		return( secUser );
	}

	void CFSecSchemaObj::setSecUser( cfsec::ICFSecSecUserObj* value ) {
		secUser = value;
		if( secUser != NULL ) {
			if( secUserName != NULL ) {
				delete secUserName;
				secUserName = NULL;
			}
			secUserName = new std::string( secUser->getRequiredLoginId() );
			uuid_copy( secSessionUserId, secUser->getRequiredSecUserId() );
		}
	}
	cfsec::ICFSecSecSessionObj* CFSecSchemaObj::getSecSession() {
		if( secSession == NULL ) {
			if( authorization != NULL ) {
				secSession = getSecSessionTableObj()->readSecSessionByIdIdx( authorization->getSecSessionId() );
			}
			else if( ( secSessionSessionId[0] != 0 )
				|| ( secSessionSessionId[1] != 0 )
				|| ( secSessionSessionId[2] != 0 )
				|| ( secSessionSessionId[3] != 0 )
				|| ( secSessionSessionId[4] != 0 )
				|| ( secSessionSessionId[5] != 0 )
				|| ( secSessionSessionId[6] != 0 )
				|| ( secSessionSessionId[7] != 0 )
				|| ( secSessionSessionId[8] != 0 )
				|| ( secSessionSessionId[9] != 0 )
				|| ( secSessionSessionId[10] != 0 )
				|| ( secSessionSessionId[11] != 0 )
				|| ( secSessionSessionId[12] != 0 )
				|| ( secSessionSessionId[13] != 0 )
				|| ( secSessionSessionId[14] != 0 )
				|| ( secSessionSessionId[15] != 0 ) )
			{
				secSession = getSecSessionTableObj()->readSecSessionByIdIdx( secSessionSessionId );
			}
			if( secSession != NULL ) {
				uuid_copy( secSessionSessionId, secSession->getRequiredSecSessionId() );
				uuid_copy( secSessionUserId, secSession->getRequiredSecUserId() );
			}
		}
		return( secSession );
	}

	void CFSecSchemaObj::setSecSession( cfsec::ICFSecSecSessionObj* value ) {
		secSession = value;
		if( secSession == NULL ) {
			return;
		}
		uuid_copy( secSessionSessionId, secSession->getRequiredSecSessionId() );
		uuid_copy( secSessionUserId, secSession->getRequiredSecUserId() );
		if( authorization != NULL ) {
			authorization->setSecSession( secSession );
		}
	}

	void CFSecSchemaObj::setSecSessionId( const uuid_ptr_t value ) {
		uuid_copy( secSessionSessionId, value );
	}

	uuid_ptr_t CFSecSchemaObj::getSecSessionSessionId() {
		return( secSessionSessionId );
	}

	uuid_ptr_t CFSecSchemaObj::getSecSessionUserId() {
		return( secSessionUserId );
	}

	std::string CFSecSchemaObj::getDbSchemaName() {
		std::string retval( *schemaDbName );
		return( retval );
	}

	std::string CFSecSchemaObj::getLowerDbSchemaName() {
		std::string retval( *lowerDbSchemaName );
		return( retval );
	}

	void CFSecSchemaObj::setDbSchemaName( const std::string& argDbSchemaName ) {
		static const std::string S_ProcName = "setDbSchemaName";

		rollback();

		if( argDbSchemaName.length() <= 0 ) {
			throw cflib::CFLibEmptyArgumentException( CLASS_NAME,
				S_ProcName,
				1,
				"argDbSchemaName" );
		}

		if( backingStore != NULL ) {
			backingStore->setDbSchemaName( argDbSchemaName );
		}

		if( schemaDbName != NULL ) {
			delete schemaDbName;
			schemaDbName = NULL;
		}
		schemaDbName = new std::string( argDbSchemaName );
		lowerDbSchemaName = new std::string( argDbSchemaName );
		std::transform( lowerDbSchemaName->begin(), lowerDbSchemaName->end(), lowerDbSchemaName->begin(), ::tolower );

		releasePreparedStatements();
	}

	std::string CFSecSchemaObj::fileImport( const std::string& fileName, const std::string& fileContent ) {
		std::string logContent = backingStore->fileImport( getAuthorization(), fileName, fileContent );
		return( logContent );
	}

	/**
	 *	Release any prepared statements acquired by this connection.
	 *	<p>
	 *	Resets the prepared statements so they can acquire the new value of
	 *	<tt>setDbSchemaName()</tt>.
	 */
	void CFSecSchemaObj::releasePreparedStatements() {
	}
	cfsec::CFSecAuthorization* CFSecSchemaObj::getAuthorization() const {
		return( authorization );
	}

	void CFSecSchemaObj::setAuthorization( cfsec::CFSecAuthorization* value ) {
		authorization = value;
	}

	cfsec::ICFSecSchema* CFSecSchemaObj::getBackingStore() {
		return( backingStore );
	}

	void CFSecSchemaObj::setBackingStore( cfsec::ICFSecSchema* value ) {
		backingStore = value;
	}

	std::string CFSecSchemaObj::getSchemaName() {
		return( SCHEMA_NAME );
	}

	bool CFSecSchemaObj::isConnected() {
		if( backingStore == NULL ) {
			return( false );
		}
		else {
			return( backingStore->isConnected() );
		}
	}

	bool CFSecSchemaObj::connect() {
		return( backingStore->connect() );
	}

	bool CFSecSchemaObj::connect( const std::string& username, const std::string& password ) {
		return( backingStore->connect( username, password ) );
	}

	bool CFSecSchemaObj::connect( const std::string& clusterName, const std::string& tenantName, const std::string& secUserName, const std::string& password ) {
		static const std::string S_ProcName = "connect-full";
		if( clusterName.length() <= 0 ) {
			throw cflib::CFLibEmptyArgumentException( CLASS_NAME,
				S_ProcName,
				1,
				"clusterName" );
		}
		if( tenantName.length() <= 0 ) {
			throw cflib::CFLibEmptyArgumentException( CLASS_NAME,
				S_ProcName,
				2,
				"tenantName" );
		}
		if( secUserName.length() <= 0 ) {
			throw cflib::CFLibEmptyArgumentException( CLASS_NAME,
				S_ProcName,
				3,
				"secUserName" );
		}
		if( password.length() <= 0 ) {
			throw cflib::CFLibEmptyArgumentException( CLASS_NAME,
				S_ProcName,
				5,
				"password" );
		}
		if( ! backingStore->connect( secUserName, password, clusterName, tenantName ) ) {
			authorization = NULL;
			return( false );
		}
		if( authorization != NULL ) {
			// The login was established as an XMsg client, which automatically sets the Authorization
			// information based on the return message.  You only need to do the remaining SecSession
			// and authorization creation if you're using a direct client-server model instead of
			// an XMsg client-server model.
			setSecClusterName( clusterName );
			setSecTenantName( tenantName );
			setSecUserName( secUserName );
			return( true );
		}

		if( ( clusterName == S_System )
		 && ( tenantName == S_System )
		 && ( secUserName == S_System ) )
		{
			if( secCluster == NULL ) {
				secCluster = getClusterTableObj()->newInstance();
				cfsec::ICFSecClusterEditObj* editCluster = secCluster->getEdit();
				if( editCluster == NULL ) {
					editCluster = secCluster->beginEdit();
					editCluster->setRequiredDescription( S_System );
					editCluster->setRequiredFullDomName( S_System );
					secCluster = editCluster->create();
					editCluster = NULL;
				}
			}
			if( secTenant == NULL ) {
				secTenant = getTenantTableObj()->newInstance();
				cfsec::ICFSecTenantEditObj* editTenant = secTenant->getEdit();
				if( editTenant == NULL ) {
					editTenant = secTenant->beginEdit();
					editTenant->setRequiredContainerCluster( secCluster);
					editTenant->setRequiredTenantName( S_System );
					secTenant = editTenant->create();
					editTenant = NULL;
				}
			}
			if( secUser == NULL ) {
				secUser = getSecUserTableObj()->newInstance();
				cfsec::ICFSecSecUserEditObj* editSecUser = secUser->getEdit();
				if( editSecUser == NULL ) {
					editSecUser = secUser->beginEdit();
					editSecUser->setRequiredEMailAddress( S_System );
					editSecUser->setRequiredLoginId( S_System );
					secUser = editSecUser->create();
					editSecUser = NULL;
				}
			}
			setSecClusterName( clusterName );
			setSecTenantName( tenantName );
			setSecUserName( secUserName );
			secCluster = NULL;
			secTenant = NULL;
			secUser = NULL;
			secSession = NULL;
			cfsec::ICFSecClusterObj* cluster = getSecCluster();
			cfsec::ICFSecTenantObj* tenant = getSecTenant();
			cfsec::ICFSecSecUserObj* user = getSecUser();
			cfsec::ICFSecSecSessionObj* session;
			if( ( cluster != NULL ) && ( tenant != NULL ) && ( user != NULL ) ) {
				session = getSecSessionTableObj()->newInstance();
				cfsec::ICFSecSecSessionEditObj* sessionEdit = session->beginEdit();
				sessionEdit->setRequiredContainerSecUser( user );
				std::chrono::system_clock::time_point timestamp = cflib::CFLib::getUTCTimestampInstance();
				sessionEdit->setRequiredStart( timestamp );
				sessionEdit->setOptionalFinishNull();
				session = sessionEdit->create();
				setSecSession( session );
			}
			else {
				session = NULL;
			}
			if( ( cluster == NULL ) || ( tenant == NULL ) || ( user == NULL ) || ( session == NULL ) ) {
				disconnect( false );
				authorization = NULL;
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					"Could not resolve cluster name, tenant name, user name, or session.  Login cancelled" );
			}
			if( authorization == NULL ) {
				authorization = new cfsec::CFSecAuthorization();
			}
			authorization->setSecCluster( *cluster );
			authorization->setSecTenant( *tenant );
			authorization->setSecSession( session );
			return( true );
		}
		setSecClusterName( clusterName );
		setSecTenantName( tenantName );
		setSecUserName( secUserName );
		bool transactionStarted = beginTransaction();
		secCluster = NULL;
		secTenant = NULL;
		secUser = NULL;
		secSession = NULL;
		cfsec::ICFSecClusterObj* cluster = getSecCluster();
		cfsec::ICFSecTenantObj* tenant = getSecTenant();
		cfsec::ICFSecSecUserObj* user = getSecUser();
		cfsec::ICFSecSecSessionObj* session;
		if( ( cluster != NULL ) && ( tenant != NULL ) && ( user != NULL ) ) {
			session = getSecSessionTableObj()->newInstance();
			cfsec::ICFSecSecSessionEditObj* sessionEdit = session->beginEdit();
			sessionEdit->setRequiredContainerSecUser( user );
			std::chrono::system_clock::time_point timestamp = cflib::CFLib::getUTCTimestampInstance();
			sessionEdit->setRequiredStart( timestamp );
			sessionEdit->setOptionalFinishNull();
			session = sessionEdit->create();
			setSecSession( session );
		}
		else {
			session = NULL;
		}
		if( transactionStarted ) {
			commit();
		}
		if( ( cluster == NULL ) || ( tenant == NULL ) || ( user == NULL ) || ( session == NULL ) ) {
			disconnect( false );
			authorization = NULL;
			throw cflib::CFLibRuntimeException( CLASS_NAME,
				S_ProcName,
				"Could not resolve cluster name, tenant name, user name, or session.  Login cancelled" );
		}
		if( authorization == NULL ) {
			authorization = new cfsec::CFSecAuthorization();
		}
		authorization->setSecCluster( *cluster );
		authorization->setSecTenant( *tenant );
		authorization->setSecSession( session );
		return( true );
	}

	void CFSecSchemaObj::disconnect( bool doCommit ) {
		backingStore->disconnect( doCommit );
	}

	void CFSecSchemaObj::logout() {
		if( authorization == NULL ) {
			if( isConnected() ) {
				disconnect( false );
			}
			return;
		}
		if( isConnected() ) {
			try {
				bool transactionStarted = beginTransaction();
				if( ! transactionStarted ) {
					rollback();
					transactionStarted = beginTransaction();
					if( ! transactionStarted ) {
						setAuthorization( NULL );
						return;
					}
				}
				const uuid_ptr_t secSessionId = authorization->getSecSessionId();
				if( ( secSessionId[0] != 0 )
					|| ( secSessionId[1] != 0 )
					|| ( secSessionId[2] != 0 )
					|| ( secSessionId[3] != 0 )
					|| ( secSessionId[4] != 0 )
					|| ( secSessionId[5] != 0 )
					|| ( secSessionId[6] != 0 )
					|| ( secSessionId[7] != 0 )
					|| ( secSessionId[8] != 0 )
					|| ( secSessionId[9] != 0 )
					|| ( secSessionId[10] != 0 )
					|| ( secSessionId[11] != 0 )
					|| ( secSessionId[12] != 0 )
					|| ( secSessionId[13] != 0 )
					|| ( secSessionId[14] != 0 )
					|| ( secSessionId[15] != 0 ) )
				{
					cfsec::ICFSecSecSessionObj* secSession = getSecSessionTableObj()->readSecSessionByIdIdx( secSessionId );
					if( secSession != NULL ) {
						if( secSession->isOptionalFinishNull() ) {
							cfsec::ICFSecSecSessionEditObj* editSecSession = secSession->beginEdit();
							std::chrono::system_clock::time_point timestamp = cflib::CFLib::getUTCTimestampInstance();
							editSecSession->setOptionalFinishValue( timestamp );
							editSecSession->update();
							editSecSession = NULL;
						}
					}
				}
				commit();
			}
			catch( std::exception x ) {
				setAuthorization( NULL );
				try {
					disconnect( false );
				}
				catch( std::exception e ) {
				}
			}
			setAuthorization( NULL );
			try {
				disconnect( false );
			}
			catch( std::exception e ) {
			}
		}
	}

	void CFSecSchemaObj::minimizeMemory() {
		if( clusterTableObj != NULL ) {
			clusterTableObj->minimizeMemory();
		}
		if( hostNodeTableObj != NULL ) {
			hostNodeTableObj->minimizeMemory();
		}
		if( iSOCcyTableObj != NULL ) {
			iSOCcyTableObj->minimizeMemory();
		}
		if( iSOCtryTableObj != NULL ) {
			iSOCtryTableObj->minimizeMemory();
		}
		if( iSOCtryCcyTableObj != NULL ) {
			iSOCtryCcyTableObj->minimizeMemory();
		}
		if( iSOCtryLangTableObj != NULL ) {
			iSOCtryLangTableObj->minimizeMemory();
		}
		if( iSOLangTableObj != NULL ) {
			iSOLangTableObj->minimizeMemory();
		}
		if( iSOTZoneTableObj != NULL ) {
			iSOTZoneTableObj->minimizeMemory();
		}
		if( secAppTableObj != NULL ) {
			secAppTableObj->minimizeMemory();
		}
		if( secDeviceTableObj != NULL ) {
			secDeviceTableObj->minimizeMemory();
		}
		if( secFormTableObj != NULL ) {
			secFormTableObj->minimizeMemory();
		}
		if( secGroupTableObj != NULL ) {
			secGroupTableObj->minimizeMemory();
		}
		if( secGroupFormTableObj != NULL ) {
			secGroupFormTableObj->minimizeMemory();
		}
		if( secGrpIncTableObj != NULL ) {
			secGrpIncTableObj->minimizeMemory();
		}
		if( secGrpMembTableObj != NULL ) {
			secGrpMembTableObj->minimizeMemory();
		}
		if( secSessionTableObj != NULL ) {
			secSessionTableObj->minimizeMemory();
		}
		if( secUserTableObj != NULL ) {
			secUserTableObj->minimizeMemory();
		}
		if( serviceTableObj != NULL ) {
			serviceTableObj->minimizeMemory();
		}
		if( serviceTypeTableObj != NULL ) {
			serviceTypeTableObj->minimizeMemory();
		}
		if( sysClusterTableObj != NULL ) {
			sysClusterTableObj->minimizeMemory();
		}
		if( tSecGroupTableObj != NULL ) {
			tSecGroupTableObj->minimizeMemory();
		}
		if( tSecGrpIncTableObj != NULL ) {
			tSecGrpIncTableObj->minimizeMemory();
		}
		if( tSecGrpMembTableObj != NULL ) {
			tSecGrpMembTableObj->minimizeMemory();
		}
		if( tenantTableObj != NULL ) {
			tenantTableObj->minimizeMemory();
		}
	}

	bool CFSecSchemaObj::isTransactionOpen() {
		bool txnOpen = backingStore->isTransactionOpen();
		return( txnOpen );
	}

	bool CFSecSchemaObj::beginTransaction() {
		bool txnInitiated = backingStore->beginTransaction();
		return( txnInitiated );
	}

	void CFSecSchemaObj::commit() {
		backingStore->commit();
	}

	void CFSecSchemaObj::rollback() {
		backingStore->rollback();
	}
	cfsec::ICFSecClusterTableObj* CFSecSchemaObj::getClusterTableObj() {
		return( clusterTableObj );
	}

	cfsec::ICFSecHostNodeTableObj* CFSecSchemaObj::getHostNodeTableObj() {
		return( hostNodeTableObj );
	}

	cfsec::ICFSecISOCcyTableObj* CFSecSchemaObj::getISOCcyTableObj() {
		return( iSOCcyTableObj );
	}

	cfsec::ICFSecISOCtryTableObj* CFSecSchemaObj::getISOCtryTableObj() {
		return( iSOCtryTableObj );
	}

	cfsec::ICFSecISOCtryCcyTableObj* CFSecSchemaObj::getISOCtryCcyTableObj() {
		return( iSOCtryCcyTableObj );
	}

	cfsec::ICFSecISOCtryLangTableObj* CFSecSchemaObj::getISOCtryLangTableObj() {
		return( iSOCtryLangTableObj );
	}

	cfsec::ICFSecISOLangTableObj* CFSecSchemaObj::getISOLangTableObj() {
		return( iSOLangTableObj );
	}

	cfsec::ICFSecISOTZoneTableObj* CFSecSchemaObj::getISOTZoneTableObj() {
		return( iSOTZoneTableObj );
	}

	cfsec::ICFSecSecAppTableObj* CFSecSchemaObj::getSecAppTableObj() {
		return( secAppTableObj );
	}

	cfsec::ICFSecSecDeviceTableObj* CFSecSchemaObj::getSecDeviceTableObj() {
		return( secDeviceTableObj );
	}

	cfsec::ICFSecSecFormTableObj* CFSecSchemaObj::getSecFormTableObj() {
		return( secFormTableObj );
	}

	cfsec::ICFSecSecGroupTableObj* CFSecSchemaObj::getSecGroupTableObj() {
		return( secGroupTableObj );
	}

	cfsec::ICFSecSecGroupFormTableObj* CFSecSchemaObj::getSecGroupFormTableObj() {
		return( secGroupFormTableObj );
	}

	cfsec::ICFSecSecGrpIncTableObj* CFSecSchemaObj::getSecGrpIncTableObj() {
		return( secGrpIncTableObj );
	}

	cfsec::ICFSecSecGrpMembTableObj* CFSecSchemaObj::getSecGrpMembTableObj() {
		return( secGrpMembTableObj );
	}

	cfsec::ICFSecSecSessionTableObj* CFSecSchemaObj::getSecSessionTableObj() {
		return( secSessionTableObj );
	}

	cfsec::ICFSecSecUserTableObj* CFSecSchemaObj::getSecUserTableObj() {
		return( secUserTableObj );
	}

	cfsec::ICFSecServiceTableObj* CFSecSchemaObj::getServiceTableObj() {
		return( serviceTableObj );
	}

	cfsec::ICFSecServiceTypeTableObj* CFSecSchemaObj::getServiceTypeTableObj() {
		return( serviceTypeTableObj );
	}

	cfsec::ICFSecSysClusterTableObj* CFSecSchemaObj::getSysClusterTableObj() {
		return( sysClusterTableObj );
	}

	cfsec::ICFSecTSecGroupTableObj* CFSecSchemaObj::getTSecGroupTableObj() {
		return( tSecGroupTableObj );
	}

	cfsec::ICFSecTSecGrpIncTableObj* CFSecSchemaObj::getTSecGrpIncTableObj() {
		return( tSecGrpIncTableObj );
	}

	cfsec::ICFSecTSecGrpMembTableObj* CFSecSchemaObj::getTSecGrpMembTableObj() {
		return( tSecGrpMembTableObj );
	}

	cfsec::ICFSecTenantTableObj* CFSecSchemaObj::getTenantTableObj() {
		return( tenantTableObj );
	}
}
