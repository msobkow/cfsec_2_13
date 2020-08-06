// Description: C++18 implementation of a CFSec schema.

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

#include <cfsec/CFSecSchema.hpp>
#include <cfsec/ICFSecPublic.hpp>

namespace cfsec {

	const std::string CFSecSchema::CLASS_NAME( "CFSecSchema" );

	CFSecSchema::CFSecSchema()
	: ICFSecSchema()
 	{
		authorization = NULL;
		tablePerms = NULL;
		configuration = NULL;
		jndiName = NULL;
		schemaDbName = new std::string( "CFSec213" );
		lowerDbSchemaName = new std::string( "CFSec213" );
		std::transform( lowerDbSchemaName->begin(), lowerDbSchemaName->end(), lowerDbSchemaName->begin(), ::tolower );

		tableCluster = NULL;
		tableHostNode = NULL;
		tableISOCcy = NULL;
		tableISOCtry = NULL;
		tableISOCtryCcy = NULL;
		tableISOCtryLang = NULL;
		tableISOLang = NULL;
		tableISOTZone = NULL;
		tableSecApp = NULL;
		tableSecDevice = NULL;
		tableSecForm = NULL;
		tableSecGroup = NULL;
		tableSecGroupForm = NULL;
		tableSecGrpInc = NULL;
		tableSecGrpMemb = NULL;
		tableSecSession = NULL;
		tableSecUser = NULL;
		tableService = NULL;
		tableServiceType = NULL;
		tableSysCluster = NULL;
		tableTSecGroup = NULL;
		tableTSecGrpInc = NULL;
		tableTSecGrpMemb = NULL;
		tableTenant = NULL;
	}

	CFSecSchema::CFSecSchema( cfsec::CFSecConfigurationFile* conf )
	: ICFSecSchema()
 	{
		static const std::string S_ProcName( "CFSecSchema-constructor" );
		static const std::string S_Conf( "conf" );
		if( conf == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				1,
				S_Conf );
		}
		authorization = NULL;
		tablePerms = NULL;
		configuration = conf;
		jndiName = NULL;
		schemaDbName = new std::string( "CFSec213" );
		lowerDbSchemaName = new std::string( "CFSec213" );
		std::transform( lowerDbSchemaName->begin(), lowerDbSchemaName->end(), lowerDbSchemaName->begin(), ::tolower );
		jndiName = NULL;

		tableCluster = NULL;
		tableHostNode = NULL;
		tableISOCcy = NULL;
		tableISOCtry = NULL;
		tableISOCtryCcy = NULL;
		tableISOCtryLang = NULL;
		tableISOLang = NULL;
		tableISOTZone = NULL;
		tableSecApp = NULL;
		tableSecDevice = NULL;
		tableSecForm = NULL;
		tableSecGroup = NULL;
		tableSecGroupForm = NULL;
		tableSecGrpInc = NULL;
		tableSecGrpMemb = NULL;
		tableSecSession = NULL;
		tableSecUser = NULL;
		tableService = NULL;
		tableServiceType = NULL;
		tableSysCluster = NULL;
		tableTSecGroup = NULL;
		tableTSecGrpInc = NULL;
		tableTSecGrpMemb = NULL;
		tableTenant = NULL;
	}

	CFSecSchema::CFSecSchema( const std::string& argJndiName )
	: ICFSecSchema()
	{
		static const std::string S_ProcName( "CFSecSchema-constructor" );
		static const std::string S_ArgJndiName( "argJndiName" );
		if( argJndiName.length() <= 0 ) {
			throw cflib::CFLibEmptyArgumentException( CLASS_NAME,
				S_ProcName,
				1,
				S_ArgJndiName );
		}
		authorization = NULL;
		tablePerms = NULL;
		configuration = NULL;
		jndiName = new std::string( argJndiName );
		schemaDbName = new std::string( "CFSec213" );
		lowerDbSchemaName = new std::string( "CFSec213" );
		std::transform( lowerDbSchemaName->begin(), lowerDbSchemaName->end(), lowerDbSchemaName->begin(), ::tolower );

		tableCluster = NULL;
		tableHostNode = NULL;
		tableISOCcy = NULL;
		tableISOCtry = NULL;
		tableISOCtryCcy = NULL;
		tableISOCtryLang = NULL;
		tableISOLang = NULL;
		tableISOTZone = NULL;
		tableSecApp = NULL;
		tableSecDevice = NULL;
		tableSecForm = NULL;
		tableSecGroup = NULL;
		tableSecGroupForm = NULL;
		tableSecGrpInc = NULL;
		tableSecGrpMemb = NULL;
		tableSecSession = NULL;
		tableSecUser = NULL;
		tableService = NULL;
		tableServiceType = NULL;
		tableSysCluster = NULL;
		tableTSecGroup = NULL;
		tableTSecGrpInc = NULL;
		tableTSecGrpMemb = NULL;
		tableTenant = NULL;
	}

	CFSecSchema::~CFSecSchema() {
		authorization = NULL;
		if( tablePerms != NULL ) {
			delete tablePerms;
			tablePerms = NULL;
		}
		configuration = NULL;
		if( jndiName != NULL ) {
			delete jndiName;
			jndiName = NULL;
		}
		if( schemaDbName != NULL ) {
			delete schemaDbName;
			schemaDbName = NULL;
		}
		if( lowerDbSchemaName != NULL ) {
			delete lowerDbSchemaName;
			lowerDbSchemaName = NULL;
		}

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

	cfsec::CFSecConfigurationFile* CFSecSchema::getConfigurationFile() const {
		return( configuration );
	}

	void CFSecSchema::setConfigurationFile( cfsec::CFSecConfigurationFile* value ) {
		configuration = NULL;
		if( value != NULL ) {
			configuration = value;
			if( jndiName != NULL ) {
				delete jndiName;
				jndiName = NULL;
			}
		}
	}

	cfsec::CFSecAuthorization* CFSecSchema::getAuthorization() const {
		return( authorization );
	}

	void CFSecSchema::setAuthorization( cfsec::CFSecAuthorization* value ) {
		authorization = value;
	}

	const std::string* CFSecSchema::getJndiName() const {
		return( jndiName );
	}

	void CFSecSchema::setJndiName( const std::string& value ) {
		if( jndiName != NULL ) {
			delete jndiName;
			jndiName = NULL;
		}
		if( value.length() > 0 ) {
			jndiName = new std::string( value );
			configuration = NULL;
		}
	}

	bool CFSecSchema::isConnected() {
		static const std::string S_ProcName( "isConnected" );
		throw cflib::CFLibMustOverrideException( CLASS_NAME, S_ProcName );
	}

	bool CFSecSchema::connect() {
		static const std::string S_ProcName( "connect" );
		throw cflib::CFLibMustOverrideException( CLASS_NAME, S_ProcName );
	}

	bool CFSecSchema::connect( const std::string& username, const std::string& password ) {
		static const std::string S_ProcName( "connect-userpw" );
		throw cflib::CFLibMustOverrideException( CLASS_NAME, S_ProcName );
	}

	bool CFSecSchema::connect( const std::string& loginId, const std::string& password, const std::string& clusterName, const std::string& tenantName ) {
		static const std::string S_ProcName( "connect-full" );
		throw cflib::CFLibMustOverrideException( CLASS_NAME, S_ProcName );
	}

	void CFSecSchema::disconnect( bool doCommit ) {
		static const std::string S_ProcName( "disconnect" );
		throw cflib::CFLibMustOverrideException( CLASS_NAME, S_ProcName );
	}

	void CFSecSchema::logout( cfsec::CFSecAuthorization* auth ) {
		static const std::string S_ProcName( "logout" );
		throw cflib::CFLibMustOverrideException( CLASS_NAME, S_ProcName );
	}

	ICFSecSchema* CFSecSchema::newSchema() {
		static const std::string S_ProcName( "newSchema" );
		throw cflib::CFLibMustOverrideException( CLASS_NAME, S_ProcName );
	}

	std::string CFSecSchema::fileImport( const cfsec::CFSecAuthorization* auth, const std::string& fileName, const std::string& fileContent ) {
		static const std::string S_ProcName( "fileImport" );
		static const std::string S_Msg( "You must overload this method to apply a SAX Parser to the file contents" );
		throw cflib::CFLibNotImplementedYetException( CLASS_NAME,
			S_ProcName,
			S_Msg );
	}

	int16_t CFSecSchema::nextISOCcyIdGen() {
		static const std::string S_ProcName( "nextISOCcyIdGen" );
		// MSS TODO WORKING
		throw cflib::CFLibNotImplementedYetException( CLASS_NAME, S_ProcName );
	}

	int16_t CFSecSchema::nextISOCtryIdGen() {
		static const std::string S_ProcName( "nextISOCtryIdGen" );
		// MSS TODO WORKING
		throw cflib::CFLibNotImplementedYetException( CLASS_NAME, S_ProcName );
	}

	int16_t CFSecSchema::nextISOLangIdGen() {
		static const std::string S_ProcName( "nextISOLangIdGen" );
		// MSS TODO WORKING
		throw cflib::CFLibNotImplementedYetException( CLASS_NAME, S_ProcName );
	}

	int16_t CFSecSchema::nextISOTZoneIdGen() {
		static const std::string S_ProcName( "nextISOTZoneIdGen" );
		// MSS TODO WORKING
		throw cflib::CFLibNotImplementedYetException( CLASS_NAME, S_ProcName );
	}

	int32_t CFSecSchema::nextServiceTypeIdGen() {
		static const std::string S_ProcName( "nextServiceTypeIdGen" );
		// MSS TODO WORKING
		throw cflib::CFLibNotImplementedYetException( CLASS_NAME, S_ProcName );
	}

	int64_t CFSecSchema::nextClusterIdGen() {
		static const std::string S_ProcName( "nextClusterIdGen" );
		// MSS TODO WORKING
		throw cflib::CFLibNotImplementedYetException( CLASS_NAME, S_ProcName );
	}

	int64_t CFSecSchema::nextTenantIdGen() {
		static const std::string S_ProcName( "nextTenantIdGen" );
		// MSS TODO WORKING
		throw cflib::CFLibNotImplementedYetException( CLASS_NAME, S_ProcName );
	}

	cfsec::ICFSecClusterTable* CFSecSchema::getTableCluster() {
		return( tableCluster );
	}

	void CFSecSchema::setTableCluster( cfsec::ICFSecClusterTable* value ) {
		if( tableCluster != NULL ) {
			delete tableCluster;
			tableCluster = NULL;
		}
		tableCluster = value;
	}

	cfsec::ICFSecHostNodeTable* CFSecSchema::getTableHostNode() {
		return( tableHostNode );
	}

	void CFSecSchema::setTableHostNode( cfsec::ICFSecHostNodeTable* value ) {
		if( tableHostNode != NULL ) {
			delete tableHostNode;
			tableHostNode = NULL;
		}
		tableHostNode = value;
	}

	cfsec::ICFSecISOCcyTable* CFSecSchema::getTableISOCcy() {
		return( tableISOCcy );
	}

	void CFSecSchema::setTableISOCcy( cfsec::ICFSecISOCcyTable* value ) {
		if( tableISOCcy != NULL ) {
			delete tableISOCcy;
			tableISOCcy = NULL;
		}
		tableISOCcy = value;
	}

	cfsec::ICFSecISOCtryTable* CFSecSchema::getTableISOCtry() {
		return( tableISOCtry );
	}

	void CFSecSchema::setTableISOCtry( cfsec::ICFSecISOCtryTable* value ) {
		if( tableISOCtry != NULL ) {
			delete tableISOCtry;
			tableISOCtry = NULL;
		}
		tableISOCtry = value;
	}

	cfsec::ICFSecISOCtryCcyTable* CFSecSchema::getTableISOCtryCcy() {
		return( tableISOCtryCcy );
	}

	void CFSecSchema::setTableISOCtryCcy( cfsec::ICFSecISOCtryCcyTable* value ) {
		if( tableISOCtryCcy != NULL ) {
			delete tableISOCtryCcy;
			tableISOCtryCcy = NULL;
		}
		tableISOCtryCcy = value;
	}

	cfsec::ICFSecISOCtryLangTable* CFSecSchema::getTableISOCtryLang() {
		return( tableISOCtryLang );
	}

	void CFSecSchema::setTableISOCtryLang( cfsec::ICFSecISOCtryLangTable* value ) {
		if( tableISOCtryLang != NULL ) {
			delete tableISOCtryLang;
			tableISOCtryLang = NULL;
		}
		tableISOCtryLang = value;
	}

	cfsec::ICFSecISOLangTable* CFSecSchema::getTableISOLang() {
		return( tableISOLang );
	}

	void CFSecSchema::setTableISOLang( cfsec::ICFSecISOLangTable* value ) {
		if( tableISOLang != NULL ) {
			delete tableISOLang;
			tableISOLang = NULL;
		}
		tableISOLang = value;
	}

	cfsec::ICFSecISOTZoneTable* CFSecSchema::getTableISOTZone() {
		return( tableISOTZone );
	}

	void CFSecSchema::setTableISOTZone( cfsec::ICFSecISOTZoneTable* value ) {
		if( tableISOTZone != NULL ) {
			delete tableISOTZone;
			tableISOTZone = NULL;
		}
		tableISOTZone = value;
	}

	cfsec::ICFSecSecAppTable* CFSecSchema::getTableSecApp() {
		return( tableSecApp );
	}

	void CFSecSchema::setTableSecApp( cfsec::ICFSecSecAppTable* value ) {
		if( tableSecApp != NULL ) {
			delete tableSecApp;
			tableSecApp = NULL;
		}
		tableSecApp = value;
	}

	cfsec::ICFSecSecDeviceTable* CFSecSchema::getTableSecDevice() {
		return( tableSecDevice );
	}

	void CFSecSchema::setTableSecDevice( cfsec::ICFSecSecDeviceTable* value ) {
		if( tableSecDevice != NULL ) {
			delete tableSecDevice;
			tableSecDevice = NULL;
		}
		tableSecDevice = value;
	}

	cfsec::ICFSecSecFormTable* CFSecSchema::getTableSecForm() {
		return( tableSecForm );
	}

	void CFSecSchema::setTableSecForm( cfsec::ICFSecSecFormTable* value ) {
		if( tableSecForm != NULL ) {
			delete tableSecForm;
			tableSecForm = NULL;
		}
		tableSecForm = value;
	}

	cfsec::ICFSecSecGroupTable* CFSecSchema::getTableSecGroup() {
		return( tableSecGroup );
	}

	void CFSecSchema::setTableSecGroup( cfsec::ICFSecSecGroupTable* value ) {
		if( tableSecGroup != NULL ) {
			delete tableSecGroup;
			tableSecGroup = NULL;
		}
		tableSecGroup = value;
	}

	cfsec::ICFSecSecGroupFormTable* CFSecSchema::getTableSecGroupForm() {
		return( tableSecGroupForm );
	}

	void CFSecSchema::setTableSecGroupForm( cfsec::ICFSecSecGroupFormTable* value ) {
		if( tableSecGroupForm != NULL ) {
			delete tableSecGroupForm;
			tableSecGroupForm = NULL;
		}
		tableSecGroupForm = value;
	}

	cfsec::ICFSecSecGrpIncTable* CFSecSchema::getTableSecGrpInc() {
		return( tableSecGrpInc );
	}

	void CFSecSchema::setTableSecGrpInc( cfsec::ICFSecSecGrpIncTable* value ) {
		if( tableSecGrpInc != NULL ) {
			delete tableSecGrpInc;
			tableSecGrpInc = NULL;
		}
		tableSecGrpInc = value;
	}

	cfsec::ICFSecSecGrpMembTable* CFSecSchema::getTableSecGrpMemb() {
		return( tableSecGrpMemb );
	}

	void CFSecSchema::setTableSecGrpMemb( cfsec::ICFSecSecGrpMembTable* value ) {
		if( tableSecGrpMemb != NULL ) {
			delete tableSecGrpMemb;
			tableSecGrpMemb = NULL;
		}
		tableSecGrpMemb = value;
	}

	cfsec::ICFSecSecSessionTable* CFSecSchema::getTableSecSession() {
		return( tableSecSession );
	}

	void CFSecSchema::setTableSecSession( cfsec::ICFSecSecSessionTable* value ) {
		if( tableSecSession != NULL ) {
			delete tableSecSession;
			tableSecSession = NULL;
		}
		tableSecSession = value;
	}

	cfsec::ICFSecSecUserTable* CFSecSchema::getTableSecUser() {
		return( tableSecUser );
	}

	void CFSecSchema::setTableSecUser( cfsec::ICFSecSecUserTable* value ) {
		if( tableSecUser != NULL ) {
			delete tableSecUser;
			tableSecUser = NULL;
		}
		tableSecUser = value;
	}

	cfsec::ICFSecServiceTable* CFSecSchema::getTableService() {
		return( tableService );
	}

	void CFSecSchema::setTableService( cfsec::ICFSecServiceTable* value ) {
		if( tableService != NULL ) {
			delete tableService;
			tableService = NULL;
		}
		tableService = value;
	}

	cfsec::ICFSecServiceTypeTable* CFSecSchema::getTableServiceType() {
		return( tableServiceType );
	}

	void CFSecSchema::setTableServiceType( cfsec::ICFSecServiceTypeTable* value ) {
		if( tableServiceType != NULL ) {
			delete tableServiceType;
			tableServiceType = NULL;
		}
		tableServiceType = value;
	}

	cfsec::ICFSecSysClusterTable* CFSecSchema::getTableSysCluster() {
		return( tableSysCluster );
	}

	void CFSecSchema::setTableSysCluster( cfsec::ICFSecSysClusterTable* value ) {
		if( tableSysCluster != NULL ) {
			delete tableSysCluster;
			tableSysCluster = NULL;
		}
		tableSysCluster = value;
	}

	cfsec::ICFSecTSecGroupTable* CFSecSchema::getTableTSecGroup() {
		return( tableTSecGroup );
	}

	void CFSecSchema::setTableTSecGroup( cfsec::ICFSecTSecGroupTable* value ) {
		if( tableTSecGroup != NULL ) {
			delete tableTSecGroup;
			tableTSecGroup = NULL;
		}
		tableTSecGroup = value;
	}

	cfsec::ICFSecTSecGrpIncTable* CFSecSchema::getTableTSecGrpInc() {
		return( tableTSecGrpInc );
	}

	void CFSecSchema::setTableTSecGrpInc( cfsec::ICFSecTSecGrpIncTable* value ) {
		if( tableTSecGrpInc != NULL ) {
			delete tableTSecGrpInc;
			tableTSecGrpInc = NULL;
		}
		tableTSecGrpInc = value;
	}

	cfsec::ICFSecTSecGrpMembTable* CFSecSchema::getTableTSecGrpMemb() {
		return( tableTSecGrpMemb );
	}

	void CFSecSchema::setTableTSecGrpMemb( cfsec::ICFSecTSecGrpMembTable* value ) {
		if( tableTSecGrpMemb != NULL ) {
			delete tableTSecGrpMemb;
			tableTSecGrpMemb = NULL;
		}
		tableTSecGrpMemb = value;
	}

	cfsec::ICFSecTenantTable* CFSecSchema::getTableTenant() {
		return( tableTenant );
	}

	void CFSecSchema::setTableTenant( cfsec::ICFSecTenantTable* value ) {
		if( tableTenant != NULL ) {
			delete tableTenant;
			tableTenant = NULL;
		}
		tableTenant = value;
	}

	bool CFSecSchema::isTransactionOpen() const {
		static const std::string S_ProcName( "isTransactionOpen" );
		throw cflib::CFLibMustOverrideException( CLASS_NAME, S_ProcName );
	}

	bool CFSecSchema::beginTransaction() {
		static const std::string S_ProcName( "beginTransaction" );
		throw cflib::CFLibMustOverrideException( CLASS_NAME, S_ProcName );
	}

	void CFSecSchema::commit() {
		static const std::string S_ProcName( "commit" );
		throw cflib::CFLibMustOverrideException( CLASS_NAME, S_ProcName );
	}

	void CFSecSchema::rollback() {
		static const std::string S_ProcName( "rollback" );
		throw cflib::CFLibMustOverrideException( CLASS_NAME, S_ProcName );
	}

	cfsec::ICFSecTablePerms* CFSecSchema::getTablePerms() {
		return( tablePerms );
	}

	void CFSecSchema::setTablePerms( cfsec::ICFSecTablePerms* value ) {
		if( tablePerms != NULL ) {
			delete tablePerms;
			tablePerms = NULL;
		}
		tablePerms = value;
	}

	void CFSecSchema::releasePreparedStatements() {
	}

	const std::string* CFSecSchema::getDbSchemaName() const {
		return( schemaDbName );
	}

	const std::string* CFSecSchema::getLowerDbSchemaName() const {
		return( lowerDbSchemaName );
	}

	void CFSecSchema::setDbSchemaName( const std::string& argDbSchemaName ) {
		static const std::string S_ProcName( "setDbSchemaName" );
		static const std::string S_ArgDbSchemaName( "argDbSchemaName" );
		if( argDbSchemaName.length() <= 0 ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				1,
				S_ArgDbSchemaName );
		}
		if( schemaDbName != NULL ) {
			delete schemaDbName;
			schemaDbName = NULL;
		}
		if( lowerDbSchemaName != NULL ) {
			delete lowerDbSchemaName;
			lowerDbSchemaName = NULL;
		}
		schemaDbName = new std::string( argDbSchemaName );
		lowerDbSchemaName = new std::string( argDbSchemaName );
		std::transform( lowerDbSchemaName->begin(), lowerDbSchemaName->end(), lowerDbSchemaName->begin(), ::tolower );
	}

}
