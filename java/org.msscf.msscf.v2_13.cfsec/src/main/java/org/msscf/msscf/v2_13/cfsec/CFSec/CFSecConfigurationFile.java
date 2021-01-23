// Description: Java 11 configuration file for a CFSec schema.

/*
 *	org.msscf.msscf.CFSec
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFSec 2.13 Security Essentials
 *	
 *	Copyright 2020-2021 Mark Stephen Sobkow mark.sobkow@gmail.com
 *	
 *	Licensed under the Apache License, Version 2.0 (the "License");
 *	you may not use this file except in compliance with the License.
 *	You may obtain a copy of the License at
 *	
 *	http://www.apache.org/licenses/LICENSE-2.0
 *	
 *	Unless required by applicable law or agreed to in writing, software
 *	distributed under the License is distributed on an "AS IS" BASIS,
 *	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *	See the License for the specific language governing permissions and
 *	limitations under the License.
 *
 *	Manufactured by MSS Code Factory 2.12
 */

package org.msscf.msscf.v2_13.cfsec.CFSec;

import java.io.*;
import java.lang.reflect.*;
import java.net.*;
import java.rmi.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.msscf.msscf.v2_13.cflib.CFLib.*;

public class CFSecConfigurationFile
{
	protected String fileName = null;
	protected Properties props = new Properties();

	protected int netServerPort = -1;	protected String dbServerClassName = null;
	protected String dbServer = null;
	protected int dbPort = -1;

	protected String dbDatabase = null;	protected String dbUserName = null;
	protected String dbPassword = null;

	public CFSecConfigurationFile() {
	}
	public String getFileName() {
		return( fileName );
	}

	public void setFileName( String value ) {
		fileName = value;
	}

	public String get( String theKey ) {
		return( props.getProperty( theKey ) );
	}

	public void set( String theKey, String theValue ) {
		set( theKey, theValue, false );
	}

	public void set(String theKey, String theValue, boolean doSave ) {
		props.put( theKey, theValue );
		if( doSave ) {
			save();
		}
	}

	public void load() {
		load( fileName );
	}

	public void load( String configFileName ) {
		boolean doSave = false;
		try {
			FileReader reader = new FileReader( configFileName );
			props.load( reader );
			reader.close();
		}
		catch( FileNotFoundException e ) {
			doSave = true;
		}
		catch( IOException e ) {
			throw new CFLibRuntimeException( getClass(),
				"load",
				"IOException " + e.getMessage(),
				e );
		}
		if( doSave ) {
			save();
		}
	}

	public void save() {
		try {
			FileWriter writer = new FileWriter( fileName );
			props.store( writer, "CFSecConfigurationFile" );
			writer.close();
		}
		catch( IOException e ) {
			throw new CFLibRuntimeException( getClass(),
				"save",
				"IOException " + e.getMessage(),
				e );
		}
	}

	public int getNetServerPort() {
		if( netServerPort < 0 ) {
			String strValue = get( "NetServerPort" );
			netServerPort = Integer.parseInt( strValue );
		}
		return( netServerPort );
	}

	public void setNetServerPort( int value ) {
		netServerPort = value;
		String strValue = Integer.toString( netServerPort );
		set( "NetServerPort", strValue );
	}

	public String getDbServerClassName() {
		if( dbServerClassName == null ) {
			dbServerClassName = get( "DbServerClassName" );
		}
		return( dbServerClassName );
	}

	public void setDbServerClassName( String value ) {
		dbServerClassName = value;
		set( "DbServerClassName", dbServerClassName );
	}

	public String getDbServer() {
		if( dbServer == null ) {
			dbServer = get( "DbServer" );
		}
		return( dbServer );
	}

	public void setDbServer( String value ) {
		dbServer = value;
		set( "DbServer", dbServer );
	}

	public int getDbPort() {
		if( dbPort < 0 ) {
			String strValue = get( "DbPort" );
			dbPort = Integer.parseInt( strValue );
		}
		return( dbPort );
	}

	public void setDbPort( int value ) {
		dbPort = value;
		String strValue = Integer.toString( dbPort );
		set( "DbPort", strValue );
	}

	public String getDbDatabase() {
		if( dbDatabase == null ) {
			dbDatabase = get( "DbDatabase" );
		}
		return( dbDatabase );
	}

	public void setDbDatabase( String value ) {
		dbDatabase = value;
		set( "DbDatabase", dbDatabase );
	}

	public String getDbUserName() {
		if( dbUserName == null ) {
			dbUserName = get( "DbUserName" );
		}
		return( dbUserName );
	}

	public void setDbUserName( String value ) {
		dbUserName = value;
		set( "DbUserName", dbUserName );
	}

	public String getDbPassword() {
		if( dbPassword == null ) {
			dbPassword = get( "DbPassword" );
		}
		return( dbPassword );
	}

	public void setDbPassword( String value ) {
		dbPassword = value;
		set( "DbPassword", dbPassword );
	}

}
