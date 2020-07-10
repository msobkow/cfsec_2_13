// Description: Java 13 Cust JavaFX Client-Server GUI persisting via HTTP.

/*
 *	MSS Code Factory Sec Cust JavaFX GUI HTTP Client
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
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
 */

package org.msscf.msscf.cfseccust.CFSecCustHttp;

import org.apache.log4j.*;

import java.io.File;
import java.net.InetAddress;
import java.net.UnknownHostException;
import java.util.Properties;

import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.control.Control;
import javafx.scene.layout.Pane;
import javafx.stage.Stage;
import org.msscf.msscf.cflib.CFLib.*;
import org.msscf.msscf.cflib.CFLib.JavaFX.CFConsole;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfsec.CFSecJavaFX.CFSecJavaFXSchema;
import org.msscf.msscf.cfsec.CFSecJavaFX.ICFSecJavaFXSchema;
import org.msscf.msscf.cfsec.CFSecObj.*;
import org.msscf.msscf.cfsec.CFSecXMsgClnt.*;
import org.msscf.msscf.cfseccust.CFSecCust.CFSecCustMainPane;
import org.msscf.msscf.cfseccust.CFSecCust.CFSecCustSchema;
import org.msscf.msscf.cfseccust.CFSecCust.ICFSecCustSchema;

public class CFSecCustHttp
extends Application
{
	private static ICFLibMessageLog log = new CFLibConsoleMessageLog();
	protected static ICFSecSchemaObj schema = null;
	protected static ICFSecCustSchema custSchema = null;

	protected static CFSecXMsgClntHttpSchema httpClientSchema = null;

	// Constructors

	public CFSecCustHttp() {
	}

	@Override public void start( Stage stage ) {

		//CFSecCustMainWindow mainWindow = new CFSecCustMainWindow( custSchema );

		//mainWindow.requestFocus();

		CFSecCustMainPane mainPane = new CFSecCustMainPane( custSchema );
		mainPane.setCustSchema( custSchema );
		Scene scene = new Scene( mainPane );

		stage.setTitle( "Code Factory Sec Cust JavaFX HTTP Client" );
		stage.setMinHeight( 900.0 );
		stage.setMinWidth( 700.0 );
		stage.setScene( scene );
		stage.sizeToScene();
		stage.show();
		stage.requestFocus();
	}

	// Accessors

	public static ICFSecCustSchema getCustSchema() {
		return( custSchema );
	}

	public static void setCustSchema( ICFSecCustSchema argSchema ) {
		custSchema = argSchema;
	}

	// CFSecXMsgClntHttpSchema accessors are needed to complete the wiring of the direct request invoker instance
	// that has been bound by the main() to a PostgreSQL persistance implementation.

	public static CFSecXMsgClntHttpSchema getXMsgClntHttpSchema() {
		return( httpClientSchema );
	}

	public static void setXMsgClntHttpSchema( CFSecXMsgClntHttpSchema invoker ) {
		httpClientSchema = invoker;
	}

	public static ICFSecSchemaObj getSchema() {
		return( schema );
	}

	public static void setSchema( ICFSecSchemaObj argSchema ) {
		schema = argSchema;
	}

	// main() entry point

	public static void main( String args[] ) {
		final String S_ProcName = "CFSecCustHttp.main() ";
		initConsoleLog();

		if( args.length >= 1 ) {
			if( args[0].equals( "trace" ) ) {
				CFConsole.setLogExceptionsToSystem( true );
			}
			else if( args[0].equals( "notrace" ) ) {
				CFConsole.setLogExceptionsToSystem( false );
			}
			else {
				log.message( S_ProcName + "ERROR: Argument if specified must be either \"trace\" or \"notrace\"" );
				return;
			}
		}
		else {
			CFConsole.setLogExceptionsToSystem( false );
		}

		boolean fastExit = false;

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

		CFSecClientConfigurationFile cFAccClientConfig = new CFSecClientConfigurationFile();
		String cFAccClientConfigFileName = homeDir.getPath() + File.separator + ".cfsecclientrc";
		cFAccClientConfig.setFileName( cFAccClientConfigFileName );
		File cFAccClientConfigFile = new File( cFAccClientConfigFileName );
		if( ! cFAccClientConfigFile.exists() ) {
			String cFAccKeyStoreFileName = homeDir.getPath() + File.separator + ".msscfjceks";
			cFAccClientConfig.setKeyStore( cFAccKeyStoreFileName );
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
				log.message( "ERROR: user.name is null or empty" );
				return;
			}
			String deviceName = hostName.replaceAll( "[^\\w]", "_" ).toLowerCase()
				+ "-"
				+ userName.replaceAll( "[^\\w]", "_" ).toLowerCase();
			cFAccClientConfig.setDeviceName( deviceName );
			cFAccClientConfig.save();
			log.message( S_ProcName + "INFO: Created CFSec client configuration file " + cFAccClientConfigFileName );
			fastExit = true;
		}
		if( ! cFAccClientConfigFile.isFile() ) {
			log.message( S_ProcName + "ERROR: Proposed client configuration file " + cFAccClientConfigFileName + " is not a file." );
			fastExit = true;
		}
		if( ! cFAccClientConfigFile.canRead() ) {
			log.message( S_ProcName + "ERROR: Permission denied attempting to read client configuration file " + cFAccClientConfigFileName );
			fastExit = true;
		}
		cFAccClientConfig.load();

		if( fastExit ) {
			return;
		}

		// Configure logging
		Properties sysProps = System.getProperties();
		sysProps.setProperty( "log4j.rootCategory", "WARN" );
		sysProps.setProperty( "org.apache.commons.logging.Log", "org.apache.commons.logging.impl.Log4JLogger" );

		Logger httpLogger = Logger.getLogger( CFSecCustHttp.class );
		httpLogger.setLevel( Level.WARN );

		// The Invoker and it's implementation
		CFSecXMsgClntHttpSchema invoker = new CFSecXMsgClntHttpSchema();

		// And now for the client side cache implementation that invokes it
		ICFSecSchemaObj clientSchemaObj = new CFSecSchemaObj() {
			public void logout() {
				CFSecXMsgClntHttpSchema invoker = (CFSecXMsgClntHttpSchema)getBackingStore();
				try {
					invoker.logout( getAuthorization() );
				}
				catch( RuntimeException e ) {
				}
				setAuthorization( null );
			}
		};
		clientSchemaObj.setBackingStore( invoker );
		// And stitch the response handler to reference our client instance
		invoker.setResponseHandlerSchemaObj( clientSchemaObj );
		// And now we can stitch together the CLI to the SAX loader code
		CFSecCustHttp cli = new CFSecCustHttp();
		cli.setXMsgClntHttpSchema( invoker );
		cli.setSchema( clientSchemaObj );

		ICFSecCustSchema myCustSchema = new CFSecCustSchema();
		myCustSchema.setClientConfigurationFile( cFAccClientConfig );
		myCustSchema.setSchema( clientSchemaObj );
		myCustSchema.setClusterName( "system" );
		myCustSchema.setTenantName( "system" );
		myCustSchema.setSecUserName( "system" );
		cli.setCustSchema( myCustSchema );

		ICFSecJavaFXSchema javafxSchema = new CFSecJavaFXSchema();
		javafxSchema.setSchema( clientSchemaObj );
		myCustSchema.setJavaFXSchema( javafxSchema );

		Application.launch( args );
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

}
