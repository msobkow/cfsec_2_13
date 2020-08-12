// Description: Java 11 XML SAX Loader CLI persisting as MS SQL Server Developer Edition for CFSec.

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

package org.msscf.msscf.cfsec.v2_13.cfsec.CFSecSaxMSSqlLdr;

import org.apache.log4j.*;
import java.io.File;
import java.net.InetAddress;
import java.net.UnknownHostException;
import java.util.*;

import org.msscf.msscf.cflib.v2_13.CFLib.*;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfsec.CFSecObj.*;
import org.msscf.msscf.cfsec.v2_13.cfsec.CFSecMSSql.*;
import org.msscf.msscf.cfsec.v2_13.cfsec.CFSecSaxLoader.*;

public class CFSecSaxMSSqlLdr
	extends CFSecSaxLdr
{
	private static ICFLibMessageLog log = new CFLibConsoleMessageLog();

	// Constructors

	public CFSecSaxMSSqlLdr() {
		super( log );
	}

	// main() entry point

	public static void main( String args[] ) {
		final String S_ProcName = "CFSecSaxMSSqlLdr.main() ";
		initConsoleLog();
		int numArgs = args.length;
		if( numArgs >= 2 ) {
			String homeDirName = System.getProperty( "HOME" );
			if( homeDirName == null ) {
				homeDirName = System.getProperty( "user.home" );
				if( homeDirName == null ) {
					log.message( S_ProcName + "ERROR: Home directory not set" );
					return;
				}
			}
			File homeDir = new File( homeDirName );
			if( ! homeDir.exists() ) {
				log.message( S_ProcName + "ERROR: Home directory \"" + homeDirName + "\" does not exist" );
				return;
			}
			if( ! homeDir.isDirectory() ) {
				log.message( S_ProcName + "ERROR: Home directory \"" + homeDirName + "\" is not a directory" );
				return;
			}

			InetAddress localHost;
			try {
				localHost = InetAddress.getLocalHost();
			}
			catch( UnknownHostException e ) {
				localHost = null;
			}
			if( localHost == null ) {
				log.message( S_ProcName + "ERROR: LocalHost is null" );
				return;
			}

			String hostName = localHost.getHostName();
			if( ( hostName == null ) || ( hostName.length() <= 0 ) ) {
				log.message( "ERROR: LocalHost.HostName is null or empty" );
				return;
			}

			String userName = System.getProperty( "user.name" );
			if( ( userName == null ) || ( userName.length() <= 0 ) ) {
				log.message( "ERROR: System property \"user.name\" returned a null or empty string" );
				return;
			}

			boolean fastExit = false;

			// Load or create the client configuration file for resolving device keys
			CFSecClientConfigurationFile cFSecClientConfig = new CFSecClientConfigurationFile();
			String cFSecClientConfigFileName = homeDir.getPath() + File.separator + ".cfdbtestclientrc";
			cFSecClientConfig.setFileName( cFSecClientConfigFileName );
			File cFSecClientConfigFile = new File( cFSecClientConfigFileName );
			if( ! cFSecClientConfigFile.exists() ) {
				String cFSecKeyStoreFileName = homeDir.getPath() + File.separator + ".msscfjceks";
				cFSecClientConfig.setKeyStore( cFSecKeyStoreFileName );
				String deviceName = hostName.replaceAll( "[^\\w]", "_" ).toLowerCase()
				 	+ "-"
				 	+ userName.replaceAll( "[^\\w]", "_" ).toLowerCase();
				cFSecClientConfig.setDeviceName( deviceName );
				cFSecClientConfig.save();
				log.message( S_ProcName + "INFO: Created CFSec client configuration file " + cFSecClientConfigFileName );
				fastExit = true;
			}
			if( ! cFSecClientConfigFile.isFile() ) {
				log.message( S_ProcName + "ERROR: Proposed client configuration file " + cFSecClientConfigFileName + " is not a file." );
				fastExit = true;
			}
			if( ! cFSecClientConfigFile.canRead() ) {
				log.message( S_ProcName + "ERROR: Permission denied attempting to read client configuration file " + cFSecClientConfigFileName );
				fastExit = true;
			}
			cFSecClientConfig.load();

			// Load MSSql-specific configuration file for connecting to database
			CFSecConfigurationFile cFSecConfig = new CFSecConfigurationFile();
			String cFSecConfigFileName = homeDir.getPath() + File.separator + ".cFSecmssqlrc";
			cFSecConfig.setFileName( cFSecConfigFileName );
			File cFSecConfigFile = new File( cFSecConfigFileName );
			if( ! cFSecConfigFile.exists() ) {
				cFSecConfig.setDbServer( hostName );
				cFSecConfig.setNetServerPort( 1433 );
				cFSecConfig.setDbDatabase( "cfsec213" );
				cFSecConfig.setDbUserName( userName );
				cFSecConfig.setDbPassword( "ChangeMe!" );
				cFSecConfig.save();
				log.message( S_ProcName + "INFO: Created CFSec mssql configuration file " + cFSecConfigFileName );
				fastExit = true;
			}

			if( ! cFSecConfigFile.isFile() ) {
				log.message( S_ProcName + "ERROR: Proposed mssql configuration file " + cFSecConfigFileName + " is not a file." );
				fastExit = true;
			}
			if( ! cFSecConfigFile.canRead() ) {
				log.message( S_ProcName + "ERROR: Permission denied attempting to read mssql configuration file " + cFSecConfigFileName );
				fastExit = true;
			}
			cFSecConfig.load();

			// If either configuration file was created, return
			if( fastExit ) {
				return;
			}

			// Configure logging
			Properties sysProps = System.getProperties();
			sysProps.setProperty( "log4j.rootCategory", "WARN" );
			sysProps.setProperty( "org.apache.commons.logging.Log", "org.apache.commons.logging.impl.Log4JLogger" );

			Logger httpLogger = Logger.getLogger( CFSecSaxMSSqlLdr.class );
			httpLogger.setLevel( Level.WARN );

			CFSecSaxLdr cli = new CFSecSaxMSSqlLdr();
			CFSecSaxLoader loader = cli.getSaxLoader();

			applyLoaderOptions( loader, args[0] );
			if( numArgs >= 5 ) {
				cli.evaluateRemainingArgs( args, 5 );
			}
			else {
				cli.evaluateRemainingArgs( args, 2 );
			}

			String useClusterName;
			String useTenantName;
			String useSecUserName;
			if( numArgs >= 5 ) {
				useClusterName = new String( args[2] );
				useTenantName = new String( args[3] );
				useSecUserName = new String( args[4] );
			}
			else {
				useClusterName = new String( "default" );
				useTenantName = new String( "system" );
				useSecUserName = new String( "system" );
			}

			ICFSecSchema cFSecSchema = new CFSecMSSqlSchema();
			cFSecSchema.setConfigurationFile( cFSecConfig );
			cFSecSchema.connect( "system", "system", cFSecConfig.getDbUserName(), cFSecConfig.getDbPassword() );
			cFSecSchema.rollback();
			cFSecSchema.beginTransaction();

			ICFSecSchemaObj cFSecSchemaObj = new CFSecSchemaObj();
			cFSecSchemaObj.setBackingStore( cFSecSchema );
			String url = args[1];

			loader.setSchemaObj( cFSecSchemaObj );

			ICFSecClusterObj cFSecUseCluster = null;
			if( useClusterName.equals( "default" ) ) {
				List<ICFSecSysClusterObj> cFSecSysClusterList = cFSecSchemaObj.getSysClusterTableObj().readAllSysCluster();
				Iterator<ICFSecSysClusterObj> cFSecSysClusterIter = cFSecSysClusterList.iterator();
				ICFSecSysClusterObj cFSecSysClusterObj = null;
				while( cFSecSysClusterIter.hasNext() ) {
					cFSecSysClusterObj = cFSecSysClusterIter.next();
					break;
				}
				if( cFSecSysClusterObj == null ) {
					log.message( S_ProcName + "WARN: Could not find a SysCluster instance in the database, defaulting to system cluster" );
					useClusterName = new String( "system" );
					cFSecUseCluster = cFSecSchemaObj.getClusterTableObj().readClusterByUDomNameIdx( useClusterName );
					if( cFSecUseCluster == null ) {
						log.message( S_ProcName + "ERROR: Could not resolve system cluster" );
						fastExit = true;
					}
				}
				else {
					cFSecUseCluster = cFSecSysClusterObj.getRequiredContainerCluster();
					if( cFSecUseCluster == null ) {
						log.message( S_ProcName + "ERROR: Could not resolve SysCluster.RequiredContainerCluster" );
						fastExit = true;
					}
					else {
						useClusterName = cFSecUseCluster.getRequiredFullDomName();
					}
				}
			}
			else {
				cFSecUseCluster = cFSecSchemaObj.getClusterTableObj().readClusterByUDomNameIdx( useClusterName );
				if( cFSecUseCluster == null ) {
					log.message( S_ProcName + "ERROR: Could not resolve Cluster \"" + useClusterName + "\"" );
					fastExit = true;
				}
			}

			ICFSecTenantObj cFSecUseTenant = null;
			if( cFSecUseCluster != null ) {
				cFSecUseTenant = cFSecSchemaObj.getTenantTableObj().readTenantByUNameIdx( cFSecUseCluster.getRequiredId(), useTenantName );
				if( cFSecUseTenant == null ) {
					log.message( S_ProcName + "ERROR: Could not resolve Tenant \"" + cFSecUseCluster.getRequiredFullDomName() + "." + useTenantName + "\"" );
					fastExit = true;
				}
			}
			else {
				log.message( S_ProcName + "WARN: Cannot resolve Tenant \"" + useTenantName + "\" without a cluster" );
				fastExit = true;
			}

			ICFSecSecUserObj cFSecSecUserSystem = cFSecSchemaObj.getSecUserTableObj().readSecUserByULoginIdx( "system" );
			if( cFSecSecUserSystem == null ) {
				log.message( S_ProcName + "ERROR: Could not resolve SecUser login \"system\"" );
				fastExit = true;
			}

			ICFSecSecUserObj cFSecUseSecUser = null;
			cFSecUseSecUser = cFSecSchemaObj.getSecUserTableObj().readSecUserByULoginIdx( useSecUserName );
			if( cFSecUseSecUser == null ) {
				log.message( S_ProcName + "ERROR: Could not resolve SecUser login \"" + useSecUserName + "\"" );
				fastExit = true;
			}

			cFSecSchema.commit();
			cFSecSchema.disconnect( false );

			// If any required data could not be resolved, return
			if( fastExit ) {
				return;
			}

			cFSecSchema.connect( useClusterName, useTenantName, cFSecConfig.getDbUserName(), cFSecConfig.getDbPassword() );

			cFSecUseCluster = cFSecSchemaObj.getClusterTableObj().readClusterByUDomNameIdx( useClusterName );
			if( cFSecUseCluster == null ) {
				log.message( S_ProcName + "ERROR: Could not resolve Cluster \"" + useClusterName + "\"" );
				fastExit = true;
			}

			if( cFSecUseCluster != null ) {
				cFSecUseTenant = cFSecSchemaObj.getTenantTableObj().readTenantByUNameIdx( cFSecUseCluster.getRequiredId(), useTenantName );
				if( cFSecUseTenant == null ) {
					log.message( S_ProcName + "ERROR: Could not resolve Tenant \"" + cFSecUseCluster.getRequiredFullDomName() + "." + useTenantName + "\"" );
					fastExit = true;
				}
			}
			else {
				log.message( S_ProcName + "WARN: Cannot resolve Tenant \"" + useTenantName + "\" without a Cluster" );
				cFSecUseTenant = null;
			}

			cFSecUseSecUser = cFSecSchemaObj.getSecUserTableObj().readSecUserByULoginIdx( useSecUserName );
			if( cFSecUseSecUser == null ) {
				log.message( S_ProcName + "ERROR: Could not resolve SecUser login \"" + useSecUserName + "\"" );
				fastExit = true;
			}

			// If any data could not be resolved, rollback, disconnect, and return
			if( fastExit ) {
				cFSecSchema.rollback();
				cFSecSchema.disconnect( false );
				return;
			}

			cFSecSchema.commit();

			cFSecSchema.beginTransaction();

			cFSecSchemaObj.setSecCluster( cFSecUseCluster );
			cFSecSchemaObj.setSecTenant( cFSecUseTenant );
			cFSecSchemaObj.setSecUser( cFSecUseSecUser );


			CFSecAuthorization auth = new CFSecAuthorization();
			auth.setSecCluster( cFSecUseCluster );
			auth.setSecTenant( cFSecUseTenant );
			cFSecSchemaObj.setAuthorization( auth );

			cli.setClusterName( useClusterName );
			cli.setTenantName( useTenantName );
			cli.setSecUserName( useSecUserName );

			ICFSecSecSessionObj cFSecSecSession = cli.getSecSessionObj();
			cFSecSchemaObj.setSecSession( cFSecSecSession );
			auth.setSecSession( cFSecSecSession );

			loader.setUseCluster( cFSecUseCluster );
			loader.setUseTenant( cFSecUseTenant );

			cFSecSchema.commit();

			try {
				cFSecSchema.beginTransaction();
				loader.parseFile( url );
				cFSecSchema.commit();
				cFSecSchemaObj.logout();
				cFSecSchema.disconnect( false );
			}
			catch( Exception e ) {
				log.message( S_ProcName + "EXCEPTION: Could not parse XML file \"" + url + "\": " + e.getMessage() );
				e.printStackTrace( System.out );
			}
			catch( Error e ) {
				log.message( S_ProcName + "ERROR: Could not parse XML file \"" + url + "\": " + e.getMessage() );
				e.printStackTrace( System.out );
			}
			finally {
				if( cFSecSchema.isConnected() ) {
					try {
						cFSecSchema.rollback();
					}
					catch( Exception e ) {
					}
					catch( Error e ) {
					}
					try {
						cFSecSchemaObj.logout();
					}
					catch( Exception e ) {
					}
					catch( Error e ) {
					}
					try {
						cFSecSchema.disconnect( false );
					}
					catch( Exception e ) {
					}
					catch( Error e ) {
					}
				}
			}
		}
		else {
			log.message( S_ProcName + "ERROR: Expected at least two argument specifying the loader options and the name of the XML file to parse.  The first argument may be empty." );
		}
	}

	// Initialize the console log

	protected static void initConsoleLog() {
//		Layout layout = new PatternLayout(
//				"%d{ISO8601}"		// Start with a timestamp
//			+	" %-5p"				// Include the severity
//			+	" %C.%M"			// pkg.class.method()
//			+	" %F[%L]"			// File[lineNumber]
//			+	": %m\n" );			// Message text
//		BasicConfigurator.configure( new ConsoleAppender( layout, "System.out" ) );
	}

	// Evaluate remaining arguments

	public void evaluateRemainingArgs( String[] args, int consumed ) {
		// There are no extra arguments for a database instance
		if( args.length > consumed ) {
			log.message( "CFSecSaxMSSqlLdr.evaluateRemainingArgs() WARNING No extra arguments are expected for a RAM database instance, but "
				+ Integer.toString( args.length - consumed )
				+ " extra arguments were specified.  Extra arguments ignored." );
		}
	}

}
