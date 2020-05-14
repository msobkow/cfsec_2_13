// Description: Java 11 implementation of a CFSec schema.

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

package com.github.msobkow.cfsec.CFSec;

import java.lang.reflect.*;
import java.net.*;
import java.rmi.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import com.github.msobkow.cflib.CFLib.*;
import com.github.msobkow.cflib.CFLib.Tip.CFTipClientHandler;

public class CFSecSchema
	implements ICFSecSchema
{
	protected CFSecAuthorization authorization;
	protected ICFSecTablePerms tablePerms;
	protected CFSecConfigurationFile configuration;
	protected String jndiName;
	protected String schemaDbName = "CFSec213";
	protected String lowerDbSchemaName = schemaDbName.toLowerCase();

	static HashMap<String,AuditActionEnum> lookupAuditActionEnum = null;

	public static AuditActionEnum parseAuditActionEnum( String value ) {
		AuditActionEnum retval = parseAuditActionEnum( CFSecSchema.class.getName(), value );
		return( retval );
	}

	public static AuditActionEnum parseAuditActionEnum( String fieldOrClassName, String value ) {
		final String S_ProcName = "parseAuditActionEnum";
		if( lookupAuditActionEnum == null ) {
			HashMap<String,AuditActionEnum> newMap = new HashMap<String,AuditActionEnum>();
			newMap.put( "Create", AuditActionEnum.Create );
			newMap.put( "Update", AuditActionEnum.Update );
			newMap.put( "Delete", AuditActionEnum.Delete );
			lookupAuditActionEnum = newMap;
		}
		AuditActionEnum retval;
		if( ( value == null ) || ( value.length() <= 0 ) ) {
			retval = null;
		}
		else {
			retval = lookupAuditActionEnum.get( value );
			if( retval == null ) {
				throw new CFLibInvalidArgumentException( fieldOrClassName,
					S_ProcName,
					1,
					"value",
					"Invalid enum limb argument " + value );
			}
		}
		return( retval );
	}

	static HashMap<Integer,AuditActionEnum> lookupOrdinalAuditActionEnum = null;

	public static AuditActionEnum ordinalToAuditActionEnum( String fieldOrClassName, Short value ) {
		AuditActionEnum retval;
		if( value == null ) {
			retval = null;
		}
		else {
			retval = ordinalToAuditActionEnum( fieldOrClassName, Integer.valueOf( value.shortValue() ) );
		}
		return( retval );
	}

	public static AuditActionEnum ordinalToAuditActionEnum( Short value ) {
		AuditActionEnum retval;
		if( value == null ) {
			retval = null;
		}
		else {
			retval = ordinalToAuditActionEnum( Integer.valueOf( value.shortValue() ) );
		}
		return( retval );
	}

	public static AuditActionEnum ordinalToAuditActionEnum( Integer value ) {
		AuditActionEnum retval;
		if( value == null ) {
			retval = null;
		}
		else {
			retval = ordinalToAuditActionEnum( CFSecSchema.class.getName(), Integer.valueOf( value.shortValue() ) );
		}
		return( retval );
	}

	public static AuditActionEnum ordinalToAuditActionEnum( String fieldOrClassName, Integer value ) {
		final String S_ProcName = "ordinalToAuditActionEnum";
		if( lookupOrdinalAuditActionEnum == null ) {
			HashMap<Integer,AuditActionEnum> newMap = new HashMap<Integer,AuditActionEnum>();
			newMap.put( Integer.valueOf( AuditActionEnum.Create.ordinal() ), AuditActionEnum.Create );
			newMap.put( Integer.valueOf( AuditActionEnum.Update.ordinal() ), AuditActionEnum.Update );
			newMap.put( Integer.valueOf( AuditActionEnum.Delete.ordinal() ), AuditActionEnum.Delete );
			lookupOrdinalAuditActionEnum = newMap;
		}
		AuditActionEnum retval;
		if( value == null ) {
			retval = null;
		}
		else {
			retval = lookupOrdinalAuditActionEnum.get( value );
			if( retval == null ) {
				throw new CFLibInvalidArgumentException( fieldOrClassName,
					S_ProcName,
					1,
					"value",
					"Invalid enum ordinal argument " + value.toString() );
			}
		}
		return( retval );
	}

	protected ICFSecClusterTable tableCluster;
	protected ICFSecHostNodeTable tableHostNode;
	protected ICFSecISOCcyTable tableISOCcy;
	protected ICFSecISOCtryTable tableISOCtry;
	protected ICFSecISOCtryCcyTable tableISOCtryCcy;
	protected ICFSecISOCtryLangTable tableISOCtryLang;
	protected ICFSecISOLangTable tableISOLang;
	protected ICFSecISOTZoneTable tableISOTZone;
	protected ICFSecSecAppTable tableSecApp;
	protected ICFSecSecDeviceTable tableSecDevice;
	protected ICFSecSecFormTable tableSecForm;
	protected ICFSecSecGroupTable tableSecGroup;
	protected ICFSecSecGroupFormTable tableSecGroupForm;
	protected ICFSecSecGrpIncTable tableSecGrpInc;
	protected ICFSecSecGrpMembTable tableSecGrpMemb;
	protected ICFSecSecSessionTable tableSecSession;
	protected ICFSecSecUserTable tableSecUser;
	protected ICFSecServiceTable tableService;
	protected ICFSecServiceTypeTable tableServiceType;
	protected ICFSecSysClusterTable tableSysCluster;
	protected ICFSecTSecGroupTable tableTSecGroup;
	protected ICFSecTSecGrpIncTable tableTSecGrpInc;
	protected ICFSecTSecGrpMembTable tableTSecGrpMemb;
	protected ICFSecTenantTable tableTenant;

	protected ICFSecClusterFactory factoryCluster;
	protected ICFSecHostNodeFactory factoryHostNode;
	protected ICFSecISOCcyFactory factoryISOCcy;
	protected ICFSecISOCtryFactory factoryISOCtry;
	protected ICFSecISOCtryCcyFactory factoryISOCtryCcy;
	protected ICFSecISOCtryLangFactory factoryISOCtryLang;
	protected ICFSecISOLangFactory factoryISOLang;
	protected ICFSecISOTZoneFactory factoryISOTZone;
	protected ICFSecSecAppFactory factorySecApp;
	protected ICFSecSecDeviceFactory factorySecDevice;
	protected ICFSecSecFormFactory factorySecForm;
	protected ICFSecSecGroupFactory factorySecGroup;
	protected ICFSecSecGroupFormFactory factorySecGroupForm;
	protected ICFSecSecGrpIncFactory factorySecGrpInc;
	protected ICFSecSecGrpMembFactory factorySecGrpMemb;
	protected ICFSecSecSessionFactory factorySecSession;
	protected ICFSecSecUserFactory factorySecUser;
	protected ICFSecServiceFactory factoryService;
	protected ICFSecServiceTypeFactory factoryServiceType;
	protected ICFSecSysClusterFactory factorySysCluster;
	protected ICFSecTSecGroupFactory factoryTSecGroup;
	protected ICFSecTSecGrpIncFactory factoryTSecGrpInc;
	protected ICFSecTSecGrpMembFactory factoryTSecGrpMemb;
	protected ICFSecTenantFactory factoryTenant;


	public CFSecSchema() {
		configuration = null;
		jndiName = null;

		tableCluster = null;
		tableHostNode = null;
		tableISOCcy = null;
		tableISOCtry = null;
		tableISOCtryCcy = null;
		tableISOCtryLang = null;
		tableISOLang = null;
		tableISOTZone = null;
		tableSecApp = null;
		tableSecDevice = null;
		tableSecForm = null;
		tableSecGroup = null;
		tableSecGroupForm = null;
		tableSecGrpInc = null;
		tableSecGrpMemb = null;
		tableSecSession = null;
		tableSecUser = null;
		tableService = null;
		tableServiceType = null;
		tableSysCluster = null;
		tableTSecGroup = null;
		tableTSecGrpInc = null;
		tableTSecGrpMemb = null;
		tableTenant = null;

		factoryCluster = new CFSecClusterDefaultFactory();
		factoryHostNode = new CFSecHostNodeDefaultFactory();
		factoryISOCcy = new CFSecISOCcyDefaultFactory();
		factoryISOCtry = new CFSecISOCtryDefaultFactory();
		factoryISOCtryCcy = new CFSecISOCtryCcyDefaultFactory();
		factoryISOCtryLang = new CFSecISOCtryLangDefaultFactory();
		factoryISOLang = new CFSecISOLangDefaultFactory();
		factoryISOTZone = new CFSecISOTZoneDefaultFactory();
		factorySecApp = new CFSecSecAppDefaultFactory();
		factorySecDevice = new CFSecSecDeviceDefaultFactory();
		factorySecForm = new CFSecSecFormDefaultFactory();
		factorySecGroup = new CFSecSecGroupDefaultFactory();
		factorySecGroupForm = new CFSecSecGroupFormDefaultFactory();
		factorySecGrpInc = new CFSecSecGrpIncDefaultFactory();
		factorySecGrpMemb = new CFSecSecGrpMembDefaultFactory();
		factorySecSession = new CFSecSecSessionDefaultFactory();
		factorySecUser = new CFSecSecUserDefaultFactory();
		factoryService = new CFSecServiceDefaultFactory();
		factoryServiceType = new CFSecServiceTypeDefaultFactory();
		factorySysCluster = new CFSecSysClusterDefaultFactory();
		factoryTSecGroup = new CFSecTSecGroupDefaultFactory();
		factoryTSecGrpInc = new CFSecTSecGrpIncDefaultFactory();
		factoryTSecGrpMemb = new CFSecTSecGrpMembDefaultFactory();
		factoryTenant = new CFSecTenantDefaultFactory();	}

	public CFSecSchema( CFSecConfigurationFile conf ) {
		if( conf == null ) {
			throw new CFLibNullArgumentException( getClass(),
				"CFSecSchema-constructor",
				1,
				"conf" );
		}
		configuration = conf;
		jndiName = null;

		tableCluster = null;
		tableHostNode = null;
		tableISOCcy = null;
		tableISOCtry = null;
		tableISOCtryCcy = null;
		tableISOCtryLang = null;
		tableISOLang = null;
		tableISOTZone = null;
		tableSecApp = null;
		tableSecDevice = null;
		tableSecForm = null;
		tableSecGroup = null;
		tableSecGroupForm = null;
		tableSecGrpInc = null;
		tableSecGrpMemb = null;
		tableSecSession = null;
		tableSecUser = null;
		tableService = null;
		tableServiceType = null;
		tableSysCluster = null;
		tableTSecGroup = null;
		tableTSecGrpInc = null;
		tableTSecGrpMemb = null;
		tableTenant = null;

		factoryCluster = new CFSecClusterDefaultFactory();
		factoryHostNode = new CFSecHostNodeDefaultFactory();
		factoryISOCcy = new CFSecISOCcyDefaultFactory();
		factoryISOCtry = new CFSecISOCtryDefaultFactory();
		factoryISOCtryCcy = new CFSecISOCtryCcyDefaultFactory();
		factoryISOCtryLang = new CFSecISOCtryLangDefaultFactory();
		factoryISOLang = new CFSecISOLangDefaultFactory();
		factoryISOTZone = new CFSecISOTZoneDefaultFactory();
		factorySecApp = new CFSecSecAppDefaultFactory();
		factorySecDevice = new CFSecSecDeviceDefaultFactory();
		factorySecForm = new CFSecSecFormDefaultFactory();
		factorySecGroup = new CFSecSecGroupDefaultFactory();
		factorySecGroupForm = new CFSecSecGroupFormDefaultFactory();
		factorySecGrpInc = new CFSecSecGrpIncDefaultFactory();
		factorySecGrpMemb = new CFSecSecGrpMembDefaultFactory();
		factorySecSession = new CFSecSecSessionDefaultFactory();
		factorySecUser = new CFSecSecUserDefaultFactory();
		factoryService = new CFSecServiceDefaultFactory();
		factoryServiceType = new CFSecServiceTypeDefaultFactory();
		factorySysCluster = new CFSecSysClusterDefaultFactory();
		factoryTSecGroup = new CFSecTSecGroupDefaultFactory();
		factoryTSecGrpInc = new CFSecTSecGrpIncDefaultFactory();
		factoryTSecGrpMemb = new CFSecTSecGrpMembDefaultFactory();
		factoryTenant = new CFSecTenantDefaultFactory();	}

	public CFSecSchema( String argJndiName ) {
		if( ( argJndiName == null ) || ( argJndiName.length() <= 0 ) ) {
			throw new CFLibEmptyArgumentException( getClass(),
				"CFSecSchema-constructor",
				1,
				"argJndiName" );
		}
		configuration = null;
		jndiName = argJndiName;

		tableCluster = null;
		tableHostNode = null;
		tableISOCcy = null;
		tableISOCtry = null;
		tableISOCtryCcy = null;
		tableISOCtryLang = null;
		tableISOLang = null;
		tableISOTZone = null;
		tableSecApp = null;
		tableSecDevice = null;
		tableSecForm = null;
		tableSecGroup = null;
		tableSecGroupForm = null;
		tableSecGrpInc = null;
		tableSecGrpMemb = null;
		tableSecSession = null;
		tableSecUser = null;
		tableService = null;
		tableServiceType = null;
		tableSysCluster = null;
		tableTSecGroup = null;
		tableTSecGrpInc = null;
		tableTSecGrpMemb = null;
		tableTenant = null;

		factoryCluster = new CFSecClusterDefaultFactory();
		factoryHostNode = new CFSecHostNodeDefaultFactory();
		factoryISOCcy = new CFSecISOCcyDefaultFactory();
		factoryISOCtry = new CFSecISOCtryDefaultFactory();
		factoryISOCtryCcy = new CFSecISOCtryCcyDefaultFactory();
		factoryISOCtryLang = new CFSecISOCtryLangDefaultFactory();
		factoryISOLang = new CFSecISOLangDefaultFactory();
		factoryISOTZone = new CFSecISOTZoneDefaultFactory();
		factorySecApp = new CFSecSecAppDefaultFactory();
		factorySecDevice = new CFSecSecDeviceDefaultFactory();
		factorySecForm = new CFSecSecFormDefaultFactory();
		factorySecGroup = new CFSecSecGroupDefaultFactory();
		factorySecGroupForm = new CFSecSecGroupFormDefaultFactory();
		factorySecGrpInc = new CFSecSecGrpIncDefaultFactory();
		factorySecGrpMemb = new CFSecSecGrpMembDefaultFactory();
		factorySecSession = new CFSecSecSessionDefaultFactory();
		factorySecUser = new CFSecSecUserDefaultFactory();
		factoryService = new CFSecServiceDefaultFactory();
		factoryServiceType = new CFSecServiceTypeDefaultFactory();
		factorySysCluster = new CFSecSysClusterDefaultFactory();
		factoryTSecGroup = new CFSecTSecGroupDefaultFactory();
		factoryTSecGrpInc = new CFSecTSecGrpIncDefaultFactory();
		factoryTSecGrpMemb = new CFSecTSecGrpMembDefaultFactory();
		factoryTenant = new CFSecTenantDefaultFactory();	}

	/**
	 *	The majority of cases do not have a CFTipClientHandler
	 *	associated with it's persistence implementation.
	 *	Only the XMsg client implementations overload this
	 *	to return the actual CFTipClientHandler associated
	 *	with the connection instance.
	 */
	public CFTipClientHandler getCFTipClientHandler() {
		return( null );
	}

	public String getServerURL() {
		return( null );
	}

	public void setServerURL( String value ) {
	}

	public CFSecConfigurationFile getConfigurationFile() {
		return( configuration );
	}

	public void setConfigurationFile( CFSecConfigurationFile value ) {
		if( value == null ) {
			configuration = null;
		}
		else {
			configuration = value;
			jndiName = null;
		}
	}

	public CFSecAuthorization getAuthorization() {
		return( authorization );
	}

	public void setAuthorization( CFSecAuthorization value ) {
		authorization = value;
	}

	public String getJndiName() {
		return( jndiName );
	}

	public void setJndiName( String value ) {
		if( ( value == null ) || ( value.length() <= 0 ) ) {
			jndiName = null;
		}
		else {
			configuration = null;
			jndiName = value;
		}
	}

	public boolean isConnected() {
		throw new CFLibMustOverrideException( getClass(), "isConnected" );
	}

	public boolean connect() {
		throw new CFLibMustOverrideException( getClass(), "connect" );
	}

	public boolean connect( String username, String password ) {
		throw new CFLibMustOverrideException( getClass(), "connect-userpw" );
	}

	public boolean connect( String loginId, String password, String clusterName, String tenantName ) {
		throw new CFLibMustOverrideException( getClass(), "connect-full" );
	}

	public void disconnect( boolean doCommit ) {
		throw new CFLibMustOverrideException( getClass(), "disconnect" );
	}

	public void logout( CFSecAuthorization auth ) {
		throw new CFLibMustOverrideException( getClass(), "logout" );
	}

	public ICFSecSchema newSchema() {
		throw new CFLibMustOverrideException( getClass(), "newSchema" );
	}

	/**
	 *	Import the contents of the specified file name
	 *	and file contents by applying a SAX Loader parse.
	 */
	public String fileImport( CFSecAuthorization auth, String fileName, String fileContent ) {
		final String S_ProcName = "fileImport";
		throw new CFLibNotImplementedYetException( getClass(),
			S_ProcName,
			"You must overload this method to apply a SAX Parser to the file contents" );
	}

	public short nextISOCcyIdGen() {
		throw new CFLibNotImplementedYetException( getClass(), "nextISOCcyIdGen" );
	}

	public short nextISOCtryIdGen() {
		throw new CFLibNotImplementedYetException( getClass(), "nextISOCtryIdGen" );
	}

	public short nextISOLangIdGen() {
		throw new CFLibNotImplementedYetException( getClass(), "nextISOLangIdGen" );
	}

	public short nextISOTZoneIdGen() {
		throw new CFLibNotImplementedYetException( getClass(), "nextISOTZoneIdGen" );
	}

	public int nextServiceTypeIdGen() {
		throw new CFLibNotImplementedYetException( getClass(), "nextServiceTypeIdGen" );
	}

	public long nextClusterIdGen() {
		throw new CFLibNotImplementedYetException( getClass(), "nextClusterIdGen" );
	}

	public long nextTenantIdGen() {
		throw new CFLibNotImplementedYetException( getClass(), "nextTenantIdGen" );
	}

	public UUID nextSecSessionIdGen() {
		UUID retval = UUID.randomUUID();
		return( retval );
	}

	public UUID nextSecUserIdGen() {
		UUID retval = UUID.randomUUID();
		return( retval );
	}

	public ICFSecClusterTable getTableCluster() {
		return( tableCluster );
	}

	public void setTableCluster( ICFSecClusterTable value ) {
		tableCluster = value;
	}

	public ICFSecClusterFactory getFactoryCluster() {
		return( factoryCluster );
	}

	public void setFactoryCluster( ICFSecClusterFactory value ) {
		factoryCluster = value;
	}

	public ICFSecHostNodeTable getTableHostNode() {
		return( tableHostNode );
	}

	public void setTableHostNode( ICFSecHostNodeTable value ) {
		tableHostNode = value;
	}

	public ICFSecHostNodeFactory getFactoryHostNode() {
		return( factoryHostNode );
	}

	public void setFactoryHostNode( ICFSecHostNodeFactory value ) {
		factoryHostNode = value;
	}

	public ICFSecISOCcyTable getTableISOCcy() {
		return( tableISOCcy );
	}

	public void setTableISOCcy( ICFSecISOCcyTable value ) {
		tableISOCcy = value;
	}

	public ICFSecISOCcyFactory getFactoryISOCcy() {
		return( factoryISOCcy );
	}

	public void setFactoryISOCcy( ICFSecISOCcyFactory value ) {
		factoryISOCcy = value;
	}

	public ICFSecISOCtryTable getTableISOCtry() {
		return( tableISOCtry );
	}

	public void setTableISOCtry( ICFSecISOCtryTable value ) {
		tableISOCtry = value;
	}

	public ICFSecISOCtryFactory getFactoryISOCtry() {
		return( factoryISOCtry );
	}

	public void setFactoryISOCtry( ICFSecISOCtryFactory value ) {
		factoryISOCtry = value;
	}

	public ICFSecISOCtryCcyTable getTableISOCtryCcy() {
		return( tableISOCtryCcy );
	}

	public void setTableISOCtryCcy( ICFSecISOCtryCcyTable value ) {
		tableISOCtryCcy = value;
	}

	public ICFSecISOCtryCcyFactory getFactoryISOCtryCcy() {
		return( factoryISOCtryCcy );
	}

	public void setFactoryISOCtryCcy( ICFSecISOCtryCcyFactory value ) {
		factoryISOCtryCcy = value;
	}

	public ICFSecISOCtryLangTable getTableISOCtryLang() {
		return( tableISOCtryLang );
	}

	public void setTableISOCtryLang( ICFSecISOCtryLangTable value ) {
		tableISOCtryLang = value;
	}

	public ICFSecISOCtryLangFactory getFactoryISOCtryLang() {
		return( factoryISOCtryLang );
	}

	public void setFactoryISOCtryLang( ICFSecISOCtryLangFactory value ) {
		factoryISOCtryLang = value;
	}

	public ICFSecISOLangTable getTableISOLang() {
		return( tableISOLang );
	}

	public void setTableISOLang( ICFSecISOLangTable value ) {
		tableISOLang = value;
	}

	public ICFSecISOLangFactory getFactoryISOLang() {
		return( factoryISOLang );
	}

	public void setFactoryISOLang( ICFSecISOLangFactory value ) {
		factoryISOLang = value;
	}

	public ICFSecISOTZoneTable getTableISOTZone() {
		return( tableISOTZone );
	}

	public void setTableISOTZone( ICFSecISOTZoneTable value ) {
		tableISOTZone = value;
	}

	public ICFSecISOTZoneFactory getFactoryISOTZone() {
		return( factoryISOTZone );
	}

	public void setFactoryISOTZone( ICFSecISOTZoneFactory value ) {
		factoryISOTZone = value;
	}

	public ICFSecSecAppTable getTableSecApp() {
		return( tableSecApp );
	}

	public void setTableSecApp( ICFSecSecAppTable value ) {
		tableSecApp = value;
	}

	public ICFSecSecAppFactory getFactorySecApp() {
		return( factorySecApp );
	}

	public void setFactorySecApp( ICFSecSecAppFactory value ) {
		factorySecApp = value;
	}

	public ICFSecSecDeviceTable getTableSecDevice() {
		return( tableSecDevice );
	}

	public void setTableSecDevice( ICFSecSecDeviceTable value ) {
		tableSecDevice = value;
	}

	public ICFSecSecDeviceFactory getFactorySecDevice() {
		return( factorySecDevice );
	}

	public void setFactorySecDevice( ICFSecSecDeviceFactory value ) {
		factorySecDevice = value;
	}

	public ICFSecSecFormTable getTableSecForm() {
		return( tableSecForm );
	}

	public void setTableSecForm( ICFSecSecFormTable value ) {
		tableSecForm = value;
	}

	public ICFSecSecFormFactory getFactorySecForm() {
		return( factorySecForm );
	}

	public void setFactorySecForm( ICFSecSecFormFactory value ) {
		factorySecForm = value;
	}

	public ICFSecSecGroupTable getTableSecGroup() {
		return( tableSecGroup );
	}

	public void setTableSecGroup( ICFSecSecGroupTable value ) {
		tableSecGroup = value;
	}

	public ICFSecSecGroupFactory getFactorySecGroup() {
		return( factorySecGroup );
	}

	public void setFactorySecGroup( ICFSecSecGroupFactory value ) {
		factorySecGroup = value;
	}

	public ICFSecSecGroupFormTable getTableSecGroupForm() {
		return( tableSecGroupForm );
	}

	public void setTableSecGroupForm( ICFSecSecGroupFormTable value ) {
		tableSecGroupForm = value;
	}

	public ICFSecSecGroupFormFactory getFactorySecGroupForm() {
		return( factorySecGroupForm );
	}

	public void setFactorySecGroupForm( ICFSecSecGroupFormFactory value ) {
		factorySecGroupForm = value;
	}

	public ICFSecSecGrpIncTable getTableSecGrpInc() {
		return( tableSecGrpInc );
	}

	public void setTableSecGrpInc( ICFSecSecGrpIncTable value ) {
		tableSecGrpInc = value;
	}

	public ICFSecSecGrpIncFactory getFactorySecGrpInc() {
		return( factorySecGrpInc );
	}

	public void setFactorySecGrpInc( ICFSecSecGrpIncFactory value ) {
		factorySecGrpInc = value;
	}

	public ICFSecSecGrpMembTable getTableSecGrpMemb() {
		return( tableSecGrpMemb );
	}

	public void setTableSecGrpMemb( ICFSecSecGrpMembTable value ) {
		tableSecGrpMemb = value;
	}

	public ICFSecSecGrpMembFactory getFactorySecGrpMemb() {
		return( factorySecGrpMemb );
	}

	public void setFactorySecGrpMemb( ICFSecSecGrpMembFactory value ) {
		factorySecGrpMemb = value;
	}

	public ICFSecSecSessionTable getTableSecSession() {
		return( tableSecSession );
	}

	public void setTableSecSession( ICFSecSecSessionTable value ) {
		tableSecSession = value;
	}

	public ICFSecSecSessionFactory getFactorySecSession() {
		return( factorySecSession );
	}

	public void setFactorySecSession( ICFSecSecSessionFactory value ) {
		factorySecSession = value;
	}

	public ICFSecSecUserTable getTableSecUser() {
		return( tableSecUser );
	}

	public void setTableSecUser( ICFSecSecUserTable value ) {
		tableSecUser = value;
	}

	public ICFSecSecUserFactory getFactorySecUser() {
		return( factorySecUser );
	}

	public void setFactorySecUser( ICFSecSecUserFactory value ) {
		factorySecUser = value;
	}

	public ICFSecServiceTable getTableService() {
		return( tableService );
	}

	public void setTableService( ICFSecServiceTable value ) {
		tableService = value;
	}

	public ICFSecServiceFactory getFactoryService() {
		return( factoryService );
	}

	public void setFactoryService( ICFSecServiceFactory value ) {
		factoryService = value;
	}

	public ICFSecServiceTypeTable getTableServiceType() {
		return( tableServiceType );
	}

	public void setTableServiceType( ICFSecServiceTypeTable value ) {
		tableServiceType = value;
	}

	public ICFSecServiceTypeFactory getFactoryServiceType() {
		return( factoryServiceType );
	}

	public void setFactoryServiceType( ICFSecServiceTypeFactory value ) {
		factoryServiceType = value;
	}

	public ICFSecSysClusterTable getTableSysCluster() {
		return( tableSysCluster );
	}

	public void setTableSysCluster( ICFSecSysClusterTable value ) {
		tableSysCluster = value;
	}

	public ICFSecSysClusterFactory getFactorySysCluster() {
		return( factorySysCluster );
	}

	public void setFactorySysCluster( ICFSecSysClusterFactory value ) {
		factorySysCluster = value;
	}

	public ICFSecTSecGroupTable getTableTSecGroup() {
		return( tableTSecGroup );
	}

	public void setTableTSecGroup( ICFSecTSecGroupTable value ) {
		tableTSecGroup = value;
	}

	public ICFSecTSecGroupFactory getFactoryTSecGroup() {
		return( factoryTSecGroup );
	}

	public void setFactoryTSecGroup( ICFSecTSecGroupFactory value ) {
		factoryTSecGroup = value;
	}

	public ICFSecTSecGrpIncTable getTableTSecGrpInc() {
		return( tableTSecGrpInc );
	}

	public void setTableTSecGrpInc( ICFSecTSecGrpIncTable value ) {
		tableTSecGrpInc = value;
	}

	public ICFSecTSecGrpIncFactory getFactoryTSecGrpInc() {
		return( factoryTSecGrpInc );
	}

	public void setFactoryTSecGrpInc( ICFSecTSecGrpIncFactory value ) {
		factoryTSecGrpInc = value;
	}

	public ICFSecTSecGrpMembTable getTableTSecGrpMemb() {
		return( tableTSecGrpMemb );
	}

	public void setTableTSecGrpMemb( ICFSecTSecGrpMembTable value ) {
		tableTSecGrpMemb = value;
	}

	public ICFSecTSecGrpMembFactory getFactoryTSecGrpMemb() {
		return( factoryTSecGrpMemb );
	}

	public void setFactoryTSecGrpMemb( ICFSecTSecGrpMembFactory value ) {
		factoryTSecGrpMemb = value;
	}

	public ICFSecTenantTable getTableTenant() {
		return( tableTenant );
	}

	public void setTableTenant( ICFSecTenantTable value ) {
		tableTenant = value;
	}

	public ICFSecTenantFactory getFactoryTenant() {
		return( factoryTenant );
	}

	public void setFactoryTenant( ICFSecTenantFactory value ) {
		factoryTenant = value;
	}

	public boolean isTransactionOpen() {
		throw new CFLibMustOverrideException( getClass(), "isTransactionOpen" );
	}

	public boolean beginTransaction() {
		throw new CFLibMustOverrideException( getClass(), "beginTransaction" );
	}

	public void commit() {
		throw new CFLibMustOverrideException( getClass(), "commit" );
	}

	public void rollback() {
		throw new CFLibMustOverrideException( getClass(), "rollback" );
	}

	public ICFSecTablePerms getTablePerms() {
		return( tablePerms );
	}

	public void setTablePerms( ICFSecTablePerms value ) {
		tablePerms = value;
	}

	public static String xmlEncodeString( String val ) {
		StringBuffer buff = new StringBuffer();
		int len = val.length();
		for( int idx = 0; idx < len; idx ++ ) {
			char c = val.charAt( idx );
			switch( c ) {
				case '&':
					buff.append( "&amp;" );
					break;
				case '<':
					buff.append( "&lt;" );
					break;
				case '>':
					buff.append( "&gt;" );
					break;
				case '"':
					buff.append( "&quot;" );
					break;
				case '\'':
					buff.append( "&apos;" );
					break;
				default:
					buff.append( c );
					break;
			}
		}
		return( buff.toString() );
	}

	/**
	 *	Release any prepared statements bound to this database instance, such
	 *	that the value of schemaDbName has to be re-evaluated for all future
	 *	invocations.
	 */
	public void releasePreparedStatements() {
	}

	/**
	 *	When you first connect to a database, you can opt to specify a database
	 *	schema name to be used by the session.  The implementation code must always
	 *	be dynamically based on the invocation of <tt>String getDbSchemaName()</tt>
	 *	at runtime.
	 *	<p>
	 *	The initial value is defined by the implementing schema model which has inherited
	 *	the expression of the current schema model being expanded.  That is, it is specified
	 *	in the DbSchemaName attribute of a SchemaDef instance.
	 */
	public String getDbSchemaName() {
		return( schemaDbName );
	}

	public String getLowerDbSchemaName() {
		return( lowerDbSchemaName );
	}

	/**
	 *	The database is expected to override this implementation and invoke the
	 *	<tt>super.setDbSchemaName( String argDbSchemaName )</tt> early
	 *	on in the implementation of the cust body.  You should let the exceptions
	 *	which can be thrown by this implementation pass unimpeded.
	 *	<pg>
	 *	When you set the database schema name, the database-specific implementation
	 *	of this method does a "commit; use database"-type sequence to change
	 *	to the target database.  This should be specified globally for all
	 *	database connections in a given cluster, so that all of
	 *	the application implementation clients are using the same database instance
	 *	regardless of what's been provided by the cust client implementation,
	 *	be it as a Java application or a web interface written using JEE.
	 */
	public void setDbSchemaName( String argDbSchemaName ) {
		final String S_ProcName = "setDbSchemaName";
		if( ( argDbSchemaName == null ) || ( argDbSchemaName.length() <= 0 ) ) {
			throw new CFLibNullArgumentException( getClass(),
				S_ProcName,
				1,
				"argDbSchemaName" );
		}
		schemaDbName = argDbSchemaName;
		lowerDbSchemaName = schemaDbName.toLowerCase();
	}
}
