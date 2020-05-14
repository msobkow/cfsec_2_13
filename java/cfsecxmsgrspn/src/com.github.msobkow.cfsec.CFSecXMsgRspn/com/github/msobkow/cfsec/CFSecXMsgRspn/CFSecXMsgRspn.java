// Description: Java 11 XML SAX Request Message  for CFSec.

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

package com.github.msobkow.cfsec.CFSecXMsgRspn;

import java.io.File;
import java.io.FileInputStream;
import java.io.InputStream;
import java.net.URISyntaxException;
import java.net.URL;

import org.xml.sax.*;
import org.apache.commons.codec.binary.Base64;
import org.apache.xerces.xni.grammars.Grammar;

import com.github.msobkow.cflib.CFLib.*;
import com.github.msobkow.cflib.CFLib.Tip.*;
import com.github.msobkow.cfsec.CFSec.*;
import com.github.msobkow.cfsec.CFSecObj.*;

public class CFSecXMsgRspn
	extends CFLibXmlCoreSaxParser
	implements ContentHandler,
		ICFTipResponseHandler
{

	// The namespace URI of the supported schema
	public final static String	SCHEMA_XMLNS = "uri://xsd/cfsecrspn";

	// The source for loading the supported schema
	public final static String	SCHEMA_URI = "../bin/xsd/cfsec-rspn.xsd";
	public final static String	SCHEMA_ROOT_URI = "/xsd/cfsec-rspn.xsd";
	protected static Grammar myGrammar = null;

	// The schema instance to load in to

	private ICFSecSchemaObj schemaObj = null;
	private boolean deleted = false;
	private RuntimeException exceptionRaised = null;
	private Object lastObjectProcessed = null;
	private Object sortedListOfObjects = null;
	private String logContent = null;
	private boolean dataChanged = false;
	// Constructors

	public CFSecXMsgRspn() {
		super();
		setRootElementHandler( getSaxRspnRoot() );
		if( myGrammar == null ) {
			InputStream input;
			File file = new File( SCHEMA_URI );
			if( file.exists() ) {
				try {
					input = new FileInputStream( file );
				}
				catch( Exception e ) {
					input = null;
				}
				if( input != null ) {
					myGrammar = addToGrammarPool( SCHEMA_URI, input );
				}
			}
			else {
				input = getClass().getResourceAsStream( SCHEMA_ROOT_URI );
				if( input != null ) {
					myGrammar = addToGrammarPool( SCHEMA_ROOT_URI, input );
				}
			}
		}
		initParser();
		setSchemaObj( null );
	}

	public CFSecXMsgRspn( CFSecSchemaObj schemaObj ) {
		super();
		setRootElementHandler( getSaxRspnRoot() );
		if( myGrammar == null ) {
			InputStream input;
			File file = new File( SCHEMA_URI );
			if( file.exists() ) {
				try {
					input = new FileInputStream( file );
				}
				catch( Exception e ) {
					input = null;
				}
				if( input != null ) {
					myGrammar = addToGrammarPool( SCHEMA_URI, input );
				}
			}
			else {
				input = getClass().getResourceAsStream( SCHEMA_ROOT_URI );
				if( input != null ) {
					myGrammar = addToGrammarPool( SCHEMA_ROOT_URI, input );
				}
			}
		}
		initParser();
		setSchemaObj( schemaObj );
	}

	public CFSecXMsgRspn( ICFLibMessageLog logger ) {
		super( logger );
		setRootElementHandler( getSaxRspnRoot() );
		if( myGrammar == null ) {
			InputStream input;
			File file = new File( SCHEMA_URI );
			if( file.exists() ) {
				try {
					input = new FileInputStream( file );
				}
				catch( Exception e ) {
					input = null;
				}
				if( input != null ) {
					myGrammar = addToGrammarPool( SCHEMA_URI, input );
				}
			}
			else {
				input = getClass().getResourceAsStream( SCHEMA_ROOT_URI );
				if( input != null ) {
					myGrammar = addToGrammarPool( SCHEMA_ROOT_URI, input );
				}
			}
		}
		initParser();
		setSchemaObj( null );
	}

	public CFSecXMsgRspn( CFSecSchemaObj schemaObj, ICFLibMessageLog logger ) {
		super( logger );
		setRootElementHandler( getSaxRspnRoot() );
		if( myGrammar == null ) {
			InputStream input;
			File file = new File( SCHEMA_URI );
			if( file.exists() ) {
				try {
					input = new FileInputStream( file );
				}
				catch( Exception e ) {
					input = null;
				}
				if( input != null ) {
					myGrammar = addToGrammarPool( SCHEMA_URI, input );
				}
			}
			else {
				input = getClass().getResourceAsStream( SCHEMA_ROOT_URI );
				if( input != null ) {
					myGrammar = addToGrammarPool( SCHEMA_ROOT_URI, input );
				}
			}
		}
		initParser();
		setSchemaObj( schemaObj );
	}

	// Element  instances

	private CFSecXMsgRspnNoDataFound rspnNoDataFound = null;
	private CFSecXMsgRspnException rspnException = null;
	private CFSecXMsgRspnFileLoaded rspnFileLoaded = null;
	private CFSecXMsgRspnLoggedIn rspnLoggedIn = null;
	private CFSecXMsgRspnLoggedOut rspnLoggedOut = null;
	private CFSecXMsgRspnServerProcExecuted rspnServerProcExecuted = null;

	// Cluster Response s
	private CFSecXMsgRspnClusterRec rspnClusterRec = null;
	private CFSecXMsgRspnClusterCreated rspnClusterCreated = null;
	private CFSecXMsgRspnClusterReadSingle rspnClusterReadSingle = null;
	private CFSecXMsgRspnClusterReadList rspnClusterReadList = null;
	private CFSecXMsgRspnClusterLocked rspnClusterLocked = null;
	private CFSecXMsgRspnClusterUpdated rspnClusterUpdated = null;
	private CFSecXMsgRspnClusterDeleted rspnClusterDeleted = null;

	// HostNode Response s
	private CFSecXMsgRspnHostNodeRec rspnHostNodeRec = null;
	private CFSecXMsgRspnHostNodeCreated rspnHostNodeCreated = null;
	private CFSecXMsgRspnHostNodeReadSingle rspnHostNodeReadSingle = null;
	private CFSecXMsgRspnHostNodeReadList rspnHostNodeReadList = null;
	private CFSecXMsgRspnHostNodeLocked rspnHostNodeLocked = null;
	private CFSecXMsgRspnHostNodeUpdated rspnHostNodeUpdated = null;
	private CFSecXMsgRspnHostNodeDeleted rspnHostNodeDeleted = null;

	// ISOCcy Response s
	private CFSecXMsgRspnISOCcyRec rspnISOCcyRec = null;
	private CFSecXMsgRspnISOCcyCreated rspnISOCcyCreated = null;
	private CFSecXMsgRspnISOCcyReadSingle rspnISOCcyReadSingle = null;
	private CFSecXMsgRspnISOCcyReadList rspnISOCcyReadList = null;
	private CFSecXMsgRspnISOCcyLocked rspnISOCcyLocked = null;
	private CFSecXMsgRspnISOCcyUpdated rspnISOCcyUpdated = null;
	private CFSecXMsgRspnISOCcyDeleted rspnISOCcyDeleted = null;

	// ISOCtry Response s
	private CFSecXMsgRspnISOCtryRec rspnISOCtryRec = null;
	private CFSecXMsgRspnISOCtryCreated rspnISOCtryCreated = null;
	private CFSecXMsgRspnISOCtryReadSingle rspnISOCtryReadSingle = null;
	private CFSecXMsgRspnISOCtryReadList rspnISOCtryReadList = null;
	private CFSecXMsgRspnISOCtryLocked rspnISOCtryLocked = null;
	private CFSecXMsgRspnISOCtryUpdated rspnISOCtryUpdated = null;
	private CFSecXMsgRspnISOCtryDeleted rspnISOCtryDeleted = null;

	// ISOCtryCcy Response s
	private CFSecXMsgRspnISOCtryCcyRec rspnISOCtryCcyRec = null;
	private CFSecXMsgRspnISOCtryCcyCreated rspnISOCtryCcyCreated = null;
	private CFSecXMsgRspnISOCtryCcyReadSingle rspnISOCtryCcyReadSingle = null;
	private CFSecXMsgRspnISOCtryCcyReadList rspnISOCtryCcyReadList = null;
	private CFSecXMsgRspnISOCtryCcyLocked rspnISOCtryCcyLocked = null;
	private CFSecXMsgRspnISOCtryCcyUpdated rspnISOCtryCcyUpdated = null;
	private CFSecXMsgRspnISOCtryCcyDeleted rspnISOCtryCcyDeleted = null;

	// ISOCtryLang Response s
	private CFSecXMsgRspnISOCtryLangRec rspnISOCtryLangRec = null;
	private CFSecXMsgRspnISOCtryLangCreated rspnISOCtryLangCreated = null;
	private CFSecXMsgRspnISOCtryLangReadSingle rspnISOCtryLangReadSingle = null;
	private CFSecXMsgRspnISOCtryLangReadList rspnISOCtryLangReadList = null;
	private CFSecXMsgRspnISOCtryLangLocked rspnISOCtryLangLocked = null;
	private CFSecXMsgRspnISOCtryLangUpdated rspnISOCtryLangUpdated = null;
	private CFSecXMsgRspnISOCtryLangDeleted rspnISOCtryLangDeleted = null;

	// ISOLang Response s
	private CFSecXMsgRspnISOLangRec rspnISOLangRec = null;
	private CFSecXMsgRspnISOLangCreated rspnISOLangCreated = null;
	private CFSecXMsgRspnISOLangReadSingle rspnISOLangReadSingle = null;
	private CFSecXMsgRspnISOLangReadList rspnISOLangReadList = null;
	private CFSecXMsgRspnISOLangLocked rspnISOLangLocked = null;
	private CFSecXMsgRspnISOLangUpdated rspnISOLangUpdated = null;
	private CFSecXMsgRspnISOLangDeleted rspnISOLangDeleted = null;

	// ISOTZone Response s
	private CFSecXMsgRspnISOTZoneRec rspnISOTZoneRec = null;
	private CFSecXMsgRspnISOTZoneCreated rspnISOTZoneCreated = null;
	private CFSecXMsgRspnISOTZoneReadSingle rspnISOTZoneReadSingle = null;
	private CFSecXMsgRspnISOTZoneReadList rspnISOTZoneReadList = null;
	private CFSecXMsgRspnISOTZoneLocked rspnISOTZoneLocked = null;
	private CFSecXMsgRspnISOTZoneUpdated rspnISOTZoneUpdated = null;
	private CFSecXMsgRspnISOTZoneDeleted rspnISOTZoneDeleted = null;

	// SecApp Response s
	private CFSecXMsgRspnSecAppRec rspnSecAppRec = null;
	private CFSecXMsgRspnSecAppCreated rspnSecAppCreated = null;
	private CFSecXMsgRspnSecAppReadSingle rspnSecAppReadSingle = null;
	private CFSecXMsgRspnSecAppReadList rspnSecAppReadList = null;
	private CFSecXMsgRspnSecAppLocked rspnSecAppLocked = null;
	private CFSecXMsgRspnSecAppUpdated rspnSecAppUpdated = null;
	private CFSecXMsgRspnSecAppDeleted rspnSecAppDeleted = null;

	// SecDevice Response s
	private CFSecXMsgRspnSecDeviceRec rspnSecDeviceRec = null;
	private CFSecXMsgRspnSecDeviceCreated rspnSecDeviceCreated = null;
	private CFSecXMsgRspnSecDeviceReadSingle rspnSecDeviceReadSingle = null;
	private CFSecXMsgRspnSecDeviceReadList rspnSecDeviceReadList = null;
	private CFSecXMsgRspnSecDeviceLocked rspnSecDeviceLocked = null;
	private CFSecXMsgRspnSecDeviceUpdated rspnSecDeviceUpdated = null;
	private CFSecXMsgRspnSecDeviceDeleted rspnSecDeviceDeleted = null;

	// SecForm Response s
	private CFSecXMsgRspnSecFormRec rspnSecFormRec = null;
	private CFSecXMsgRspnSecFormCreated rspnSecFormCreated = null;
	private CFSecXMsgRspnSecFormReadSingle rspnSecFormReadSingle = null;
	private CFSecXMsgRspnSecFormReadList rspnSecFormReadList = null;
	private CFSecXMsgRspnSecFormLocked rspnSecFormLocked = null;
	private CFSecXMsgRspnSecFormUpdated rspnSecFormUpdated = null;
	private CFSecXMsgRspnSecFormDeleted rspnSecFormDeleted = null;

	// SecGroup Response s
	private CFSecXMsgRspnSecGroupRec rspnSecGroupRec = null;
	private CFSecXMsgRspnSecGroupCreated rspnSecGroupCreated = null;
	private CFSecXMsgRspnSecGroupReadSingle rspnSecGroupReadSingle = null;
	private CFSecXMsgRspnSecGroupReadList rspnSecGroupReadList = null;
	private CFSecXMsgRspnSecGroupLocked rspnSecGroupLocked = null;
	private CFSecXMsgRspnSecGroupUpdated rspnSecGroupUpdated = null;
	private CFSecXMsgRspnSecGroupDeleted rspnSecGroupDeleted = null;

	// SecGroupForm Response s
	private CFSecXMsgRspnSecGroupFormRec rspnSecGroupFormRec = null;
	private CFSecXMsgRspnSecGroupFormCreated rspnSecGroupFormCreated = null;
	private CFSecXMsgRspnSecGroupFormReadSingle rspnSecGroupFormReadSingle = null;
	private CFSecXMsgRspnSecGroupFormReadList rspnSecGroupFormReadList = null;
	private CFSecXMsgRspnSecGroupFormLocked rspnSecGroupFormLocked = null;
	private CFSecXMsgRspnSecGroupFormUpdated rspnSecGroupFormUpdated = null;
	private CFSecXMsgRspnSecGroupFormDeleted rspnSecGroupFormDeleted = null;

	// SecGrpInc Response s
	private CFSecXMsgRspnSecGrpIncRec rspnSecGrpIncRec = null;
	private CFSecXMsgRspnSecGrpIncCreated rspnSecGrpIncCreated = null;
	private CFSecXMsgRspnSecGrpIncReadSingle rspnSecGrpIncReadSingle = null;
	private CFSecXMsgRspnSecGrpIncReadList rspnSecGrpIncReadList = null;
	private CFSecXMsgRspnSecGrpIncLocked rspnSecGrpIncLocked = null;
	private CFSecXMsgRspnSecGrpIncUpdated rspnSecGrpIncUpdated = null;
	private CFSecXMsgRspnSecGrpIncDeleted rspnSecGrpIncDeleted = null;

	// SecGrpMemb Response s
	private CFSecXMsgRspnSecGrpMembRec rspnSecGrpMembRec = null;
	private CFSecXMsgRspnSecGrpMembCreated rspnSecGrpMembCreated = null;
	private CFSecXMsgRspnSecGrpMembReadSingle rspnSecGrpMembReadSingle = null;
	private CFSecXMsgRspnSecGrpMembReadList rspnSecGrpMembReadList = null;
	private CFSecXMsgRspnSecGrpMembLocked rspnSecGrpMembLocked = null;
	private CFSecXMsgRspnSecGrpMembUpdated rspnSecGrpMembUpdated = null;
	private CFSecXMsgRspnSecGrpMembDeleted rspnSecGrpMembDeleted = null;

	// SecSession Response s
	private CFSecXMsgRspnSecSessionRec rspnSecSessionRec = null;
	private CFSecXMsgRspnSecSessionCreated rspnSecSessionCreated = null;
	private CFSecXMsgRspnSecSessionReadSingle rspnSecSessionReadSingle = null;
	private CFSecXMsgRspnSecSessionReadList rspnSecSessionReadList = null;
	private CFSecXMsgRspnSecSessionLocked rspnSecSessionLocked = null;
	private CFSecXMsgRspnSecSessionUpdated rspnSecSessionUpdated = null;
	private CFSecXMsgRspnSecSessionDeleted rspnSecSessionDeleted = null;

	// SecUser Response s
	private CFSecXMsgRspnSecUserRec rspnSecUserRec = null;
	private CFSecXMsgRspnSecUserCreated rspnSecUserCreated = null;
	private CFSecXMsgRspnSecUserReadSingle rspnSecUserReadSingle = null;
	private CFSecXMsgRspnSecUserReadList rspnSecUserReadList = null;
	private CFSecXMsgRspnSecUserLocked rspnSecUserLocked = null;
	private CFSecXMsgRspnSecUserUpdated rspnSecUserUpdated = null;
	private CFSecXMsgRspnSecUserDeleted rspnSecUserDeleted = null;

	// Service Response s
	private CFSecXMsgRspnServiceRec rspnServiceRec = null;
	private CFSecXMsgRspnServiceCreated rspnServiceCreated = null;
	private CFSecXMsgRspnServiceReadSingle rspnServiceReadSingle = null;
	private CFSecXMsgRspnServiceReadList rspnServiceReadList = null;
	private CFSecXMsgRspnServiceLocked rspnServiceLocked = null;
	private CFSecXMsgRspnServiceUpdated rspnServiceUpdated = null;
	private CFSecXMsgRspnServiceDeleted rspnServiceDeleted = null;

	// ServiceType Response s
	private CFSecXMsgRspnServiceTypeRec rspnServiceTypeRec = null;
	private CFSecXMsgRspnServiceTypeCreated rspnServiceTypeCreated = null;
	private CFSecXMsgRspnServiceTypeReadSingle rspnServiceTypeReadSingle = null;
	private CFSecXMsgRspnServiceTypeReadList rspnServiceTypeReadList = null;
	private CFSecXMsgRspnServiceTypeLocked rspnServiceTypeLocked = null;
	private CFSecXMsgRspnServiceTypeUpdated rspnServiceTypeUpdated = null;
	private CFSecXMsgRspnServiceTypeDeleted rspnServiceTypeDeleted = null;

	// SysCluster Response s
	private CFSecXMsgRspnSysClusterRec rspnSysClusterRec = null;
	private CFSecXMsgRspnSysClusterCreated rspnSysClusterCreated = null;
	private CFSecXMsgRspnSysClusterReadSingle rspnSysClusterReadSingle = null;
	private CFSecXMsgRspnSysClusterReadList rspnSysClusterReadList = null;
	private CFSecXMsgRspnSysClusterLocked rspnSysClusterLocked = null;
	private CFSecXMsgRspnSysClusterUpdated rspnSysClusterUpdated = null;
	private CFSecXMsgRspnSysClusterDeleted rspnSysClusterDeleted = null;

	// TSecGroup Response s
	private CFSecXMsgRspnTSecGroupRec rspnTSecGroupRec = null;
	private CFSecXMsgRspnTSecGroupCreated rspnTSecGroupCreated = null;
	private CFSecXMsgRspnTSecGroupReadSingle rspnTSecGroupReadSingle = null;
	private CFSecXMsgRspnTSecGroupReadList rspnTSecGroupReadList = null;
	private CFSecXMsgRspnTSecGroupLocked rspnTSecGroupLocked = null;
	private CFSecXMsgRspnTSecGroupUpdated rspnTSecGroupUpdated = null;
	private CFSecXMsgRspnTSecGroupDeleted rspnTSecGroupDeleted = null;

	// TSecGrpInc Response s
	private CFSecXMsgRspnTSecGrpIncRec rspnTSecGrpIncRec = null;
	private CFSecXMsgRspnTSecGrpIncCreated rspnTSecGrpIncCreated = null;
	private CFSecXMsgRspnTSecGrpIncReadSingle rspnTSecGrpIncReadSingle = null;
	private CFSecXMsgRspnTSecGrpIncReadList rspnTSecGrpIncReadList = null;
	private CFSecXMsgRspnTSecGrpIncLocked rspnTSecGrpIncLocked = null;
	private CFSecXMsgRspnTSecGrpIncUpdated rspnTSecGrpIncUpdated = null;
	private CFSecXMsgRspnTSecGrpIncDeleted rspnTSecGrpIncDeleted = null;

	// TSecGrpMemb Response s
	private CFSecXMsgRspnTSecGrpMembRec rspnTSecGrpMembRec = null;
	private CFSecXMsgRspnTSecGrpMembCreated rspnTSecGrpMembCreated = null;
	private CFSecXMsgRspnTSecGrpMembReadSingle rspnTSecGrpMembReadSingle = null;
	private CFSecXMsgRspnTSecGrpMembReadList rspnTSecGrpMembReadList = null;
	private CFSecXMsgRspnTSecGrpMembLocked rspnTSecGrpMembLocked = null;
	private CFSecXMsgRspnTSecGrpMembUpdated rspnTSecGrpMembUpdated = null;
	private CFSecXMsgRspnTSecGrpMembDeleted rspnTSecGrpMembDeleted = null;

	// Tenant Response s
	private CFSecXMsgRspnTenantRec rspnTenantRec = null;
	private CFSecXMsgRspnTenantCreated rspnTenantCreated = null;
	private CFSecXMsgRspnTenantReadSingle rspnTenantReadSingle = null;
	private CFSecXMsgRspnTenantReadList rspnTenantReadList = null;
	private CFSecXMsgRspnTenantLocked rspnTenantLocked = null;
	private CFSecXMsgRspnTenantUpdated rspnTenantUpdated = null;
	private CFSecXMsgRspnTenantDeleted rspnTenantDeleted = null;
	private CFSecSaxRspnRoot saxRoot = null;

	private CFSecSaxRspnDoc saxDoc = null;

	// Schema object accessors

	// SchemaObj accessors

	public ICFSecSchemaObj getSchemaObj() {
		return( schemaObj );
	}

	public void setSchemaObj( ICFSecSchemaObj value ) {
		schemaObj = value;
	}

	// Result accessors

	public String getLogContent() {
		return( logContent);
	}

	public void setLogContent( String value ) {
		logContent = value;
	}

	public boolean getDataChanged() {
		return( dataChanged);
	}

	public void setDataChanged( boolean value ) {
		dataChanged = value;
	}

	public boolean getDeleted() {
		return( deleted );
	}

	public void setDeleted( boolean flag ) {
		deleted = flag;
	}

	public RuntimeException getExceptionRaised() {
		return( exceptionRaised );
	}

	public void setExceptionRaised( RuntimeException obj ) {
		exceptionRaised = obj;
	}

	public Object getLastObjectProcessed() {
		return( lastObjectProcessed );
	}

	public void setLastObjectProcessed( Object obj ) {
		lastObjectProcessed = obj;
	}

	public Object getListOfObjects() {
		return( sortedListOfObjects );
	}

	public void setListOfObjects( Object obj ) {
		sortedListOfObjects = obj;
	}

	// Element  Resolver Factories

	protected CFSecXMsgRspnNoDataFound getRspnNoDataFound() {
		if( rspnNoDataFound == null ) {
			rspnNoDataFound = new CFSecXMsgRspnNoDataFound( this );
		}
		return( rspnNoDataFound );
	}

	protected CFSecXMsgRspnException getRspnException() {
		if( rspnException == null ) {
			rspnException = new CFSecXMsgRspnException( this );
		}
		return( rspnException );
	}

	protected CFSecXMsgRspnFileLoaded getRspnFileLoaded() {
		if( rspnFileLoaded == null ) {
			rspnFileLoaded = new CFSecXMsgRspnFileLoaded( this );
		}
		return( rspnFileLoaded );
	}

	protected CFSecXMsgRspnLoggedIn getRspnLoggedIn() {
		if( rspnLoggedIn == null ) {
			rspnLoggedIn = new CFSecXMsgRspnLoggedIn( this );
		}
		return( rspnLoggedIn );
	}

	protected CFSecXMsgRspnLoggedOut getRspnLoggedOut() {
		if( rspnLoggedOut == null ) {
			rspnLoggedOut = new CFSecXMsgRspnLoggedOut( this );
		}
		return( rspnLoggedOut );
	}

	protected CFSecXMsgRspnServerProcExecuted getRspnServerProcExecuted() {
		if( rspnServerProcExecuted == null ) {
			rspnServerProcExecuted = new CFSecXMsgRspnServerProcExecuted( this );
		}
		return( rspnServerProcExecuted );
	}

	// Cluster Response s

	protected CFSecXMsgRspnClusterRec getRspnClusterRec() {
		if( rspnClusterRec == null ) {
			rspnClusterRec = new CFSecXMsgRspnClusterRec( this );
		}
		return( rspnClusterRec );
	}

	protected CFSecXMsgRspnClusterCreated getRspnClusterCreated() {
		if( rspnClusterCreated == null ) {
			rspnClusterCreated = new CFSecXMsgRspnClusterCreated( this );
		}
		return( rspnClusterCreated );
	}

	protected CFSecXMsgRspnClusterReadSingle getRspnClusterReadSingle() {
		if( rspnClusterReadSingle == null ) {
			rspnClusterReadSingle = new CFSecXMsgRspnClusterReadSingle( this );
			rspnClusterReadSingle.addElementHandler( "Cluster", getRspnClusterRec() );
		}
		return( rspnClusterReadSingle );
	}

	protected CFSecXMsgRspnClusterReadList getRspnClusterReadList() {
		if( rspnClusterReadList == null ) {
			rspnClusterReadList = new CFSecXMsgRspnClusterReadList( this );
			rspnClusterReadList.addElementHandler( "Cluster", getRspnClusterRec() );
		}
		return( rspnClusterReadList );
	}

	protected CFSecXMsgRspnClusterLocked getRspnClusterLocked() {
		if( rspnClusterLocked == null ) {
			rspnClusterLocked = new CFSecXMsgRspnClusterLocked( this );
		}
		return( rspnClusterLocked );
	}

	protected CFSecXMsgRspnClusterUpdated getRspnClusterUpdated() {
		if( rspnClusterUpdated == null ) {
			rspnClusterUpdated = new CFSecXMsgRspnClusterUpdated( this );
		}
		return( rspnClusterUpdated );
	}

	protected CFSecXMsgRspnClusterDeleted getRspnClusterDeleted() {
		if( rspnClusterDeleted == null ) {
			rspnClusterDeleted = new CFSecXMsgRspnClusterDeleted( this );
		}
		return( rspnClusterDeleted );
	}

	// HostNode Response s

	protected CFSecXMsgRspnHostNodeRec getRspnHostNodeRec() {
		if( rspnHostNodeRec == null ) {
			rspnHostNodeRec = new CFSecXMsgRspnHostNodeRec( this );
		}
		return( rspnHostNodeRec );
	}

	protected CFSecXMsgRspnHostNodeCreated getRspnHostNodeCreated() {
		if( rspnHostNodeCreated == null ) {
			rspnHostNodeCreated = new CFSecXMsgRspnHostNodeCreated( this );
		}
		return( rspnHostNodeCreated );
	}

	protected CFSecXMsgRspnHostNodeReadSingle getRspnHostNodeReadSingle() {
		if( rspnHostNodeReadSingle == null ) {
			rspnHostNodeReadSingle = new CFSecXMsgRspnHostNodeReadSingle( this );
			rspnHostNodeReadSingle.addElementHandler( "HostNode", getRspnHostNodeRec() );
		}
		return( rspnHostNodeReadSingle );
	}

	protected CFSecXMsgRspnHostNodeReadList getRspnHostNodeReadList() {
		if( rspnHostNodeReadList == null ) {
			rspnHostNodeReadList = new CFSecXMsgRspnHostNodeReadList( this );
			rspnHostNodeReadList.addElementHandler( "HostNode", getRspnHostNodeRec() );
		}
		return( rspnHostNodeReadList );
	}

	protected CFSecXMsgRspnHostNodeLocked getRspnHostNodeLocked() {
		if( rspnHostNodeLocked == null ) {
			rspnHostNodeLocked = new CFSecXMsgRspnHostNodeLocked( this );
		}
		return( rspnHostNodeLocked );
	}

	protected CFSecXMsgRspnHostNodeUpdated getRspnHostNodeUpdated() {
		if( rspnHostNodeUpdated == null ) {
			rspnHostNodeUpdated = new CFSecXMsgRspnHostNodeUpdated( this );
		}
		return( rspnHostNodeUpdated );
	}

	protected CFSecXMsgRspnHostNodeDeleted getRspnHostNodeDeleted() {
		if( rspnHostNodeDeleted == null ) {
			rspnHostNodeDeleted = new CFSecXMsgRspnHostNodeDeleted( this );
		}
		return( rspnHostNodeDeleted );
	}

	// ISOCcy Response s

	protected CFSecXMsgRspnISOCcyRec getRspnISOCcyRec() {
		if( rspnISOCcyRec == null ) {
			rspnISOCcyRec = new CFSecXMsgRspnISOCcyRec( this );
		}
		return( rspnISOCcyRec );
	}

	protected CFSecXMsgRspnISOCcyCreated getRspnISOCcyCreated() {
		if( rspnISOCcyCreated == null ) {
			rspnISOCcyCreated = new CFSecXMsgRspnISOCcyCreated( this );
		}
		return( rspnISOCcyCreated );
	}

	protected CFSecXMsgRspnISOCcyReadSingle getRspnISOCcyReadSingle() {
		if( rspnISOCcyReadSingle == null ) {
			rspnISOCcyReadSingle = new CFSecXMsgRspnISOCcyReadSingle( this );
			rspnISOCcyReadSingle.addElementHandler( "ISOCcy", getRspnISOCcyRec() );
		}
		return( rspnISOCcyReadSingle );
	}

	protected CFSecXMsgRspnISOCcyReadList getRspnISOCcyReadList() {
		if( rspnISOCcyReadList == null ) {
			rspnISOCcyReadList = new CFSecXMsgRspnISOCcyReadList( this );
			rspnISOCcyReadList.addElementHandler( "ISOCcy", getRspnISOCcyRec() );
		}
		return( rspnISOCcyReadList );
	}

	protected CFSecXMsgRspnISOCcyLocked getRspnISOCcyLocked() {
		if( rspnISOCcyLocked == null ) {
			rspnISOCcyLocked = new CFSecXMsgRspnISOCcyLocked( this );
		}
		return( rspnISOCcyLocked );
	}

	protected CFSecXMsgRspnISOCcyUpdated getRspnISOCcyUpdated() {
		if( rspnISOCcyUpdated == null ) {
			rspnISOCcyUpdated = new CFSecXMsgRspnISOCcyUpdated( this );
		}
		return( rspnISOCcyUpdated );
	}

	protected CFSecXMsgRspnISOCcyDeleted getRspnISOCcyDeleted() {
		if( rspnISOCcyDeleted == null ) {
			rspnISOCcyDeleted = new CFSecXMsgRspnISOCcyDeleted( this );
		}
		return( rspnISOCcyDeleted );
	}

	// ISOCtry Response s

	protected CFSecXMsgRspnISOCtryRec getRspnISOCtryRec() {
		if( rspnISOCtryRec == null ) {
			rspnISOCtryRec = new CFSecXMsgRspnISOCtryRec( this );
		}
		return( rspnISOCtryRec );
	}

	protected CFSecXMsgRspnISOCtryCreated getRspnISOCtryCreated() {
		if( rspnISOCtryCreated == null ) {
			rspnISOCtryCreated = new CFSecXMsgRspnISOCtryCreated( this );
		}
		return( rspnISOCtryCreated );
	}

	protected CFSecXMsgRspnISOCtryReadSingle getRspnISOCtryReadSingle() {
		if( rspnISOCtryReadSingle == null ) {
			rspnISOCtryReadSingle = new CFSecXMsgRspnISOCtryReadSingle( this );
			rspnISOCtryReadSingle.addElementHandler( "ISOCtry", getRspnISOCtryRec() );
		}
		return( rspnISOCtryReadSingle );
	}

	protected CFSecXMsgRspnISOCtryReadList getRspnISOCtryReadList() {
		if( rspnISOCtryReadList == null ) {
			rspnISOCtryReadList = new CFSecXMsgRspnISOCtryReadList( this );
			rspnISOCtryReadList.addElementHandler( "ISOCtry", getRspnISOCtryRec() );
		}
		return( rspnISOCtryReadList );
	}

	protected CFSecXMsgRspnISOCtryLocked getRspnISOCtryLocked() {
		if( rspnISOCtryLocked == null ) {
			rspnISOCtryLocked = new CFSecXMsgRspnISOCtryLocked( this );
		}
		return( rspnISOCtryLocked );
	}

	protected CFSecXMsgRspnISOCtryUpdated getRspnISOCtryUpdated() {
		if( rspnISOCtryUpdated == null ) {
			rspnISOCtryUpdated = new CFSecXMsgRspnISOCtryUpdated( this );
		}
		return( rspnISOCtryUpdated );
	}

	protected CFSecXMsgRspnISOCtryDeleted getRspnISOCtryDeleted() {
		if( rspnISOCtryDeleted == null ) {
			rspnISOCtryDeleted = new CFSecXMsgRspnISOCtryDeleted( this );
		}
		return( rspnISOCtryDeleted );
	}

	// ISOCtryCcy Response s

	protected CFSecXMsgRspnISOCtryCcyRec getRspnISOCtryCcyRec() {
		if( rspnISOCtryCcyRec == null ) {
			rspnISOCtryCcyRec = new CFSecXMsgRspnISOCtryCcyRec( this );
		}
		return( rspnISOCtryCcyRec );
	}

	protected CFSecXMsgRspnISOCtryCcyCreated getRspnISOCtryCcyCreated() {
		if( rspnISOCtryCcyCreated == null ) {
			rspnISOCtryCcyCreated = new CFSecXMsgRspnISOCtryCcyCreated( this );
		}
		return( rspnISOCtryCcyCreated );
	}

	protected CFSecXMsgRspnISOCtryCcyReadSingle getRspnISOCtryCcyReadSingle() {
		if( rspnISOCtryCcyReadSingle == null ) {
			rspnISOCtryCcyReadSingle = new CFSecXMsgRspnISOCtryCcyReadSingle( this );
			rspnISOCtryCcyReadSingle.addElementHandler( "ISOCtryCcy", getRspnISOCtryCcyRec() );
		}
		return( rspnISOCtryCcyReadSingle );
	}

	protected CFSecXMsgRspnISOCtryCcyReadList getRspnISOCtryCcyReadList() {
		if( rspnISOCtryCcyReadList == null ) {
			rspnISOCtryCcyReadList = new CFSecXMsgRspnISOCtryCcyReadList( this );
			rspnISOCtryCcyReadList.addElementHandler( "ISOCtryCcy", getRspnISOCtryCcyRec() );
		}
		return( rspnISOCtryCcyReadList );
	}

	protected CFSecXMsgRspnISOCtryCcyLocked getRspnISOCtryCcyLocked() {
		if( rspnISOCtryCcyLocked == null ) {
			rspnISOCtryCcyLocked = new CFSecXMsgRspnISOCtryCcyLocked( this );
		}
		return( rspnISOCtryCcyLocked );
	}

	protected CFSecXMsgRspnISOCtryCcyUpdated getRspnISOCtryCcyUpdated() {
		if( rspnISOCtryCcyUpdated == null ) {
			rspnISOCtryCcyUpdated = new CFSecXMsgRspnISOCtryCcyUpdated( this );
		}
		return( rspnISOCtryCcyUpdated );
	}

	protected CFSecXMsgRspnISOCtryCcyDeleted getRspnISOCtryCcyDeleted() {
		if( rspnISOCtryCcyDeleted == null ) {
			rspnISOCtryCcyDeleted = new CFSecXMsgRspnISOCtryCcyDeleted( this );
		}
		return( rspnISOCtryCcyDeleted );
	}

	// ISOCtryLang Response s

	protected CFSecXMsgRspnISOCtryLangRec getRspnISOCtryLangRec() {
		if( rspnISOCtryLangRec == null ) {
			rspnISOCtryLangRec = new CFSecXMsgRspnISOCtryLangRec( this );
		}
		return( rspnISOCtryLangRec );
	}

	protected CFSecXMsgRspnISOCtryLangCreated getRspnISOCtryLangCreated() {
		if( rspnISOCtryLangCreated == null ) {
			rspnISOCtryLangCreated = new CFSecXMsgRspnISOCtryLangCreated( this );
		}
		return( rspnISOCtryLangCreated );
	}

	protected CFSecXMsgRspnISOCtryLangReadSingle getRspnISOCtryLangReadSingle() {
		if( rspnISOCtryLangReadSingle == null ) {
			rspnISOCtryLangReadSingle = new CFSecXMsgRspnISOCtryLangReadSingle( this );
			rspnISOCtryLangReadSingle.addElementHandler( "ISOCtryLang", getRspnISOCtryLangRec() );
		}
		return( rspnISOCtryLangReadSingle );
	}

	protected CFSecXMsgRspnISOCtryLangReadList getRspnISOCtryLangReadList() {
		if( rspnISOCtryLangReadList == null ) {
			rspnISOCtryLangReadList = new CFSecXMsgRspnISOCtryLangReadList( this );
			rspnISOCtryLangReadList.addElementHandler( "ISOCtryLang", getRspnISOCtryLangRec() );
		}
		return( rspnISOCtryLangReadList );
	}

	protected CFSecXMsgRspnISOCtryLangLocked getRspnISOCtryLangLocked() {
		if( rspnISOCtryLangLocked == null ) {
			rspnISOCtryLangLocked = new CFSecXMsgRspnISOCtryLangLocked( this );
		}
		return( rspnISOCtryLangLocked );
	}

	protected CFSecXMsgRspnISOCtryLangUpdated getRspnISOCtryLangUpdated() {
		if( rspnISOCtryLangUpdated == null ) {
			rspnISOCtryLangUpdated = new CFSecXMsgRspnISOCtryLangUpdated( this );
		}
		return( rspnISOCtryLangUpdated );
	}

	protected CFSecXMsgRspnISOCtryLangDeleted getRspnISOCtryLangDeleted() {
		if( rspnISOCtryLangDeleted == null ) {
			rspnISOCtryLangDeleted = new CFSecXMsgRspnISOCtryLangDeleted( this );
		}
		return( rspnISOCtryLangDeleted );
	}

	// ISOLang Response s

	protected CFSecXMsgRspnISOLangRec getRspnISOLangRec() {
		if( rspnISOLangRec == null ) {
			rspnISOLangRec = new CFSecXMsgRspnISOLangRec( this );
		}
		return( rspnISOLangRec );
	}

	protected CFSecXMsgRspnISOLangCreated getRspnISOLangCreated() {
		if( rspnISOLangCreated == null ) {
			rspnISOLangCreated = new CFSecXMsgRspnISOLangCreated( this );
		}
		return( rspnISOLangCreated );
	}

	protected CFSecXMsgRspnISOLangReadSingle getRspnISOLangReadSingle() {
		if( rspnISOLangReadSingle == null ) {
			rspnISOLangReadSingle = new CFSecXMsgRspnISOLangReadSingle( this );
			rspnISOLangReadSingle.addElementHandler( "ISOLang", getRspnISOLangRec() );
		}
		return( rspnISOLangReadSingle );
	}

	protected CFSecXMsgRspnISOLangReadList getRspnISOLangReadList() {
		if( rspnISOLangReadList == null ) {
			rspnISOLangReadList = new CFSecXMsgRspnISOLangReadList( this );
			rspnISOLangReadList.addElementHandler( "ISOLang", getRspnISOLangRec() );
		}
		return( rspnISOLangReadList );
	}

	protected CFSecXMsgRspnISOLangLocked getRspnISOLangLocked() {
		if( rspnISOLangLocked == null ) {
			rspnISOLangLocked = new CFSecXMsgRspnISOLangLocked( this );
		}
		return( rspnISOLangLocked );
	}

	protected CFSecXMsgRspnISOLangUpdated getRspnISOLangUpdated() {
		if( rspnISOLangUpdated == null ) {
			rspnISOLangUpdated = new CFSecXMsgRspnISOLangUpdated( this );
		}
		return( rspnISOLangUpdated );
	}

	protected CFSecXMsgRspnISOLangDeleted getRspnISOLangDeleted() {
		if( rspnISOLangDeleted == null ) {
			rspnISOLangDeleted = new CFSecXMsgRspnISOLangDeleted( this );
		}
		return( rspnISOLangDeleted );
	}

	// ISOTZone Response s

	protected CFSecXMsgRspnISOTZoneRec getRspnISOTZoneRec() {
		if( rspnISOTZoneRec == null ) {
			rspnISOTZoneRec = new CFSecXMsgRspnISOTZoneRec( this );
		}
		return( rspnISOTZoneRec );
	}

	protected CFSecXMsgRspnISOTZoneCreated getRspnISOTZoneCreated() {
		if( rspnISOTZoneCreated == null ) {
			rspnISOTZoneCreated = new CFSecXMsgRspnISOTZoneCreated( this );
		}
		return( rspnISOTZoneCreated );
	}

	protected CFSecXMsgRspnISOTZoneReadSingle getRspnISOTZoneReadSingle() {
		if( rspnISOTZoneReadSingle == null ) {
			rspnISOTZoneReadSingle = new CFSecXMsgRspnISOTZoneReadSingle( this );
			rspnISOTZoneReadSingle.addElementHandler( "ISOTZone", getRspnISOTZoneRec() );
		}
		return( rspnISOTZoneReadSingle );
	}

	protected CFSecXMsgRspnISOTZoneReadList getRspnISOTZoneReadList() {
		if( rspnISOTZoneReadList == null ) {
			rspnISOTZoneReadList = new CFSecXMsgRspnISOTZoneReadList( this );
			rspnISOTZoneReadList.addElementHandler( "ISOTZone", getRspnISOTZoneRec() );
		}
		return( rspnISOTZoneReadList );
	}

	protected CFSecXMsgRspnISOTZoneLocked getRspnISOTZoneLocked() {
		if( rspnISOTZoneLocked == null ) {
			rspnISOTZoneLocked = new CFSecXMsgRspnISOTZoneLocked( this );
		}
		return( rspnISOTZoneLocked );
	}

	protected CFSecXMsgRspnISOTZoneUpdated getRspnISOTZoneUpdated() {
		if( rspnISOTZoneUpdated == null ) {
			rspnISOTZoneUpdated = new CFSecXMsgRspnISOTZoneUpdated( this );
		}
		return( rspnISOTZoneUpdated );
	}

	protected CFSecXMsgRspnISOTZoneDeleted getRspnISOTZoneDeleted() {
		if( rspnISOTZoneDeleted == null ) {
			rspnISOTZoneDeleted = new CFSecXMsgRspnISOTZoneDeleted( this );
		}
		return( rspnISOTZoneDeleted );
	}

	// SecApp Response s

	protected CFSecXMsgRspnSecAppRec getRspnSecAppRec() {
		if( rspnSecAppRec == null ) {
			rspnSecAppRec = new CFSecXMsgRspnSecAppRec( this );
		}
		return( rspnSecAppRec );
	}

	protected CFSecXMsgRspnSecAppCreated getRspnSecAppCreated() {
		if( rspnSecAppCreated == null ) {
			rspnSecAppCreated = new CFSecXMsgRspnSecAppCreated( this );
		}
		return( rspnSecAppCreated );
	}

	protected CFSecXMsgRspnSecAppReadSingle getRspnSecAppReadSingle() {
		if( rspnSecAppReadSingle == null ) {
			rspnSecAppReadSingle = new CFSecXMsgRspnSecAppReadSingle( this );
			rspnSecAppReadSingle.addElementHandler( "SecApp", getRspnSecAppRec() );
		}
		return( rspnSecAppReadSingle );
	}

	protected CFSecXMsgRspnSecAppReadList getRspnSecAppReadList() {
		if( rspnSecAppReadList == null ) {
			rspnSecAppReadList = new CFSecXMsgRspnSecAppReadList( this );
			rspnSecAppReadList.addElementHandler( "SecApp", getRspnSecAppRec() );
		}
		return( rspnSecAppReadList );
	}

	protected CFSecXMsgRspnSecAppLocked getRspnSecAppLocked() {
		if( rspnSecAppLocked == null ) {
			rspnSecAppLocked = new CFSecXMsgRspnSecAppLocked( this );
		}
		return( rspnSecAppLocked );
	}

	protected CFSecXMsgRspnSecAppUpdated getRspnSecAppUpdated() {
		if( rspnSecAppUpdated == null ) {
			rspnSecAppUpdated = new CFSecXMsgRspnSecAppUpdated( this );
		}
		return( rspnSecAppUpdated );
	}

	protected CFSecXMsgRspnSecAppDeleted getRspnSecAppDeleted() {
		if( rspnSecAppDeleted == null ) {
			rspnSecAppDeleted = new CFSecXMsgRspnSecAppDeleted( this );
		}
		return( rspnSecAppDeleted );
	}

	// SecDevice Response s

	protected CFSecXMsgRspnSecDeviceRec getRspnSecDeviceRec() {
		if( rspnSecDeviceRec == null ) {
			rspnSecDeviceRec = new CFSecXMsgRspnSecDeviceRec( this );
		}
		return( rspnSecDeviceRec );
	}

	protected CFSecXMsgRspnSecDeviceCreated getRspnSecDeviceCreated() {
		if( rspnSecDeviceCreated == null ) {
			rspnSecDeviceCreated = new CFSecXMsgRspnSecDeviceCreated( this );
		}
		return( rspnSecDeviceCreated );
	}

	protected CFSecXMsgRspnSecDeviceReadSingle getRspnSecDeviceReadSingle() {
		if( rspnSecDeviceReadSingle == null ) {
			rspnSecDeviceReadSingle = new CFSecXMsgRspnSecDeviceReadSingle( this );
			rspnSecDeviceReadSingle.addElementHandler( "SecDevice", getRspnSecDeviceRec() );
		}
		return( rspnSecDeviceReadSingle );
	}

	protected CFSecXMsgRspnSecDeviceReadList getRspnSecDeviceReadList() {
		if( rspnSecDeviceReadList == null ) {
			rspnSecDeviceReadList = new CFSecXMsgRspnSecDeviceReadList( this );
			rspnSecDeviceReadList.addElementHandler( "SecDevice", getRspnSecDeviceRec() );
		}
		return( rspnSecDeviceReadList );
	}

	protected CFSecXMsgRspnSecDeviceLocked getRspnSecDeviceLocked() {
		if( rspnSecDeviceLocked == null ) {
			rspnSecDeviceLocked = new CFSecXMsgRspnSecDeviceLocked( this );
		}
		return( rspnSecDeviceLocked );
	}

	protected CFSecXMsgRspnSecDeviceUpdated getRspnSecDeviceUpdated() {
		if( rspnSecDeviceUpdated == null ) {
			rspnSecDeviceUpdated = new CFSecXMsgRspnSecDeviceUpdated( this );
		}
		return( rspnSecDeviceUpdated );
	}

	protected CFSecXMsgRspnSecDeviceDeleted getRspnSecDeviceDeleted() {
		if( rspnSecDeviceDeleted == null ) {
			rspnSecDeviceDeleted = new CFSecXMsgRspnSecDeviceDeleted( this );
		}
		return( rspnSecDeviceDeleted );
	}

	// SecForm Response s

	protected CFSecXMsgRspnSecFormRec getRspnSecFormRec() {
		if( rspnSecFormRec == null ) {
			rspnSecFormRec = new CFSecXMsgRspnSecFormRec( this );
		}
		return( rspnSecFormRec );
	}

	protected CFSecXMsgRspnSecFormCreated getRspnSecFormCreated() {
		if( rspnSecFormCreated == null ) {
			rspnSecFormCreated = new CFSecXMsgRspnSecFormCreated( this );
		}
		return( rspnSecFormCreated );
	}

	protected CFSecXMsgRspnSecFormReadSingle getRspnSecFormReadSingle() {
		if( rspnSecFormReadSingle == null ) {
			rspnSecFormReadSingle = new CFSecXMsgRspnSecFormReadSingle( this );
			rspnSecFormReadSingle.addElementHandler( "SecForm", getRspnSecFormRec() );
		}
		return( rspnSecFormReadSingle );
	}

	protected CFSecXMsgRspnSecFormReadList getRspnSecFormReadList() {
		if( rspnSecFormReadList == null ) {
			rspnSecFormReadList = new CFSecXMsgRspnSecFormReadList( this );
			rspnSecFormReadList.addElementHandler( "SecForm", getRspnSecFormRec() );
		}
		return( rspnSecFormReadList );
	}

	protected CFSecXMsgRspnSecFormLocked getRspnSecFormLocked() {
		if( rspnSecFormLocked == null ) {
			rspnSecFormLocked = new CFSecXMsgRspnSecFormLocked( this );
		}
		return( rspnSecFormLocked );
	}

	protected CFSecXMsgRspnSecFormUpdated getRspnSecFormUpdated() {
		if( rspnSecFormUpdated == null ) {
			rspnSecFormUpdated = new CFSecXMsgRspnSecFormUpdated( this );
		}
		return( rspnSecFormUpdated );
	}

	protected CFSecXMsgRspnSecFormDeleted getRspnSecFormDeleted() {
		if( rspnSecFormDeleted == null ) {
			rspnSecFormDeleted = new CFSecXMsgRspnSecFormDeleted( this );
		}
		return( rspnSecFormDeleted );
	}

	// SecGroup Response s

	protected CFSecXMsgRspnSecGroupRec getRspnSecGroupRec() {
		if( rspnSecGroupRec == null ) {
			rspnSecGroupRec = new CFSecXMsgRspnSecGroupRec( this );
		}
		return( rspnSecGroupRec );
	}

	protected CFSecXMsgRspnSecGroupCreated getRspnSecGroupCreated() {
		if( rspnSecGroupCreated == null ) {
			rspnSecGroupCreated = new CFSecXMsgRspnSecGroupCreated( this );
		}
		return( rspnSecGroupCreated );
	}

	protected CFSecXMsgRspnSecGroupReadSingle getRspnSecGroupReadSingle() {
		if( rspnSecGroupReadSingle == null ) {
			rspnSecGroupReadSingle = new CFSecXMsgRspnSecGroupReadSingle( this );
			rspnSecGroupReadSingle.addElementHandler( "SecGroup", getRspnSecGroupRec() );
		}
		return( rspnSecGroupReadSingle );
	}

	protected CFSecXMsgRspnSecGroupReadList getRspnSecGroupReadList() {
		if( rspnSecGroupReadList == null ) {
			rspnSecGroupReadList = new CFSecXMsgRspnSecGroupReadList( this );
			rspnSecGroupReadList.addElementHandler( "SecGroup", getRspnSecGroupRec() );
		}
		return( rspnSecGroupReadList );
	}

	protected CFSecXMsgRspnSecGroupLocked getRspnSecGroupLocked() {
		if( rspnSecGroupLocked == null ) {
			rspnSecGroupLocked = new CFSecXMsgRspnSecGroupLocked( this );
		}
		return( rspnSecGroupLocked );
	}

	protected CFSecXMsgRspnSecGroupUpdated getRspnSecGroupUpdated() {
		if( rspnSecGroupUpdated == null ) {
			rspnSecGroupUpdated = new CFSecXMsgRspnSecGroupUpdated( this );
		}
		return( rspnSecGroupUpdated );
	}

	protected CFSecXMsgRspnSecGroupDeleted getRspnSecGroupDeleted() {
		if( rspnSecGroupDeleted == null ) {
			rspnSecGroupDeleted = new CFSecXMsgRspnSecGroupDeleted( this );
		}
		return( rspnSecGroupDeleted );
	}

	// SecGroupForm Response s

	protected CFSecXMsgRspnSecGroupFormRec getRspnSecGroupFormRec() {
		if( rspnSecGroupFormRec == null ) {
			rspnSecGroupFormRec = new CFSecXMsgRspnSecGroupFormRec( this );
		}
		return( rspnSecGroupFormRec );
	}

	protected CFSecXMsgRspnSecGroupFormCreated getRspnSecGroupFormCreated() {
		if( rspnSecGroupFormCreated == null ) {
			rspnSecGroupFormCreated = new CFSecXMsgRspnSecGroupFormCreated( this );
		}
		return( rspnSecGroupFormCreated );
	}

	protected CFSecXMsgRspnSecGroupFormReadSingle getRspnSecGroupFormReadSingle() {
		if( rspnSecGroupFormReadSingle == null ) {
			rspnSecGroupFormReadSingle = new CFSecXMsgRspnSecGroupFormReadSingle( this );
			rspnSecGroupFormReadSingle.addElementHandler( "SecGroupForm", getRspnSecGroupFormRec() );
		}
		return( rspnSecGroupFormReadSingle );
	}

	protected CFSecXMsgRspnSecGroupFormReadList getRspnSecGroupFormReadList() {
		if( rspnSecGroupFormReadList == null ) {
			rspnSecGroupFormReadList = new CFSecXMsgRspnSecGroupFormReadList( this );
			rspnSecGroupFormReadList.addElementHandler( "SecGroupForm", getRspnSecGroupFormRec() );
		}
		return( rspnSecGroupFormReadList );
	}

	protected CFSecXMsgRspnSecGroupFormLocked getRspnSecGroupFormLocked() {
		if( rspnSecGroupFormLocked == null ) {
			rspnSecGroupFormLocked = new CFSecXMsgRspnSecGroupFormLocked( this );
		}
		return( rspnSecGroupFormLocked );
	}

	protected CFSecXMsgRspnSecGroupFormUpdated getRspnSecGroupFormUpdated() {
		if( rspnSecGroupFormUpdated == null ) {
			rspnSecGroupFormUpdated = new CFSecXMsgRspnSecGroupFormUpdated( this );
		}
		return( rspnSecGroupFormUpdated );
	}

	protected CFSecXMsgRspnSecGroupFormDeleted getRspnSecGroupFormDeleted() {
		if( rspnSecGroupFormDeleted == null ) {
			rspnSecGroupFormDeleted = new CFSecXMsgRspnSecGroupFormDeleted( this );
		}
		return( rspnSecGroupFormDeleted );
	}

	// SecGrpInc Response s

	protected CFSecXMsgRspnSecGrpIncRec getRspnSecGrpIncRec() {
		if( rspnSecGrpIncRec == null ) {
			rspnSecGrpIncRec = new CFSecXMsgRspnSecGrpIncRec( this );
		}
		return( rspnSecGrpIncRec );
	}

	protected CFSecXMsgRspnSecGrpIncCreated getRspnSecGrpIncCreated() {
		if( rspnSecGrpIncCreated == null ) {
			rspnSecGrpIncCreated = new CFSecXMsgRspnSecGrpIncCreated( this );
		}
		return( rspnSecGrpIncCreated );
	}

	protected CFSecXMsgRspnSecGrpIncReadSingle getRspnSecGrpIncReadSingle() {
		if( rspnSecGrpIncReadSingle == null ) {
			rspnSecGrpIncReadSingle = new CFSecXMsgRspnSecGrpIncReadSingle( this );
			rspnSecGrpIncReadSingle.addElementHandler( "SecGrpInc", getRspnSecGrpIncRec() );
		}
		return( rspnSecGrpIncReadSingle );
	}

	protected CFSecXMsgRspnSecGrpIncReadList getRspnSecGrpIncReadList() {
		if( rspnSecGrpIncReadList == null ) {
			rspnSecGrpIncReadList = new CFSecXMsgRspnSecGrpIncReadList( this );
			rspnSecGrpIncReadList.addElementHandler( "SecGrpInc", getRspnSecGrpIncRec() );
		}
		return( rspnSecGrpIncReadList );
	}

	protected CFSecXMsgRspnSecGrpIncLocked getRspnSecGrpIncLocked() {
		if( rspnSecGrpIncLocked == null ) {
			rspnSecGrpIncLocked = new CFSecXMsgRspnSecGrpIncLocked( this );
		}
		return( rspnSecGrpIncLocked );
	}

	protected CFSecXMsgRspnSecGrpIncUpdated getRspnSecGrpIncUpdated() {
		if( rspnSecGrpIncUpdated == null ) {
			rspnSecGrpIncUpdated = new CFSecXMsgRspnSecGrpIncUpdated( this );
		}
		return( rspnSecGrpIncUpdated );
	}

	protected CFSecXMsgRspnSecGrpIncDeleted getRspnSecGrpIncDeleted() {
		if( rspnSecGrpIncDeleted == null ) {
			rspnSecGrpIncDeleted = new CFSecXMsgRspnSecGrpIncDeleted( this );
		}
		return( rspnSecGrpIncDeleted );
	}

	// SecGrpMemb Response s

	protected CFSecXMsgRspnSecGrpMembRec getRspnSecGrpMembRec() {
		if( rspnSecGrpMembRec == null ) {
			rspnSecGrpMembRec = new CFSecXMsgRspnSecGrpMembRec( this );
		}
		return( rspnSecGrpMembRec );
	}

	protected CFSecXMsgRspnSecGrpMembCreated getRspnSecGrpMembCreated() {
		if( rspnSecGrpMembCreated == null ) {
			rspnSecGrpMembCreated = new CFSecXMsgRspnSecGrpMembCreated( this );
		}
		return( rspnSecGrpMembCreated );
	}

	protected CFSecXMsgRspnSecGrpMembReadSingle getRspnSecGrpMembReadSingle() {
		if( rspnSecGrpMembReadSingle == null ) {
			rspnSecGrpMembReadSingle = new CFSecXMsgRspnSecGrpMembReadSingle( this );
			rspnSecGrpMembReadSingle.addElementHandler( "SecGrpMemb", getRspnSecGrpMembRec() );
		}
		return( rspnSecGrpMembReadSingle );
	}

	protected CFSecXMsgRspnSecGrpMembReadList getRspnSecGrpMembReadList() {
		if( rspnSecGrpMembReadList == null ) {
			rspnSecGrpMembReadList = new CFSecXMsgRspnSecGrpMembReadList( this );
			rspnSecGrpMembReadList.addElementHandler( "SecGrpMemb", getRspnSecGrpMembRec() );
		}
		return( rspnSecGrpMembReadList );
	}

	protected CFSecXMsgRspnSecGrpMembLocked getRspnSecGrpMembLocked() {
		if( rspnSecGrpMembLocked == null ) {
			rspnSecGrpMembLocked = new CFSecXMsgRspnSecGrpMembLocked( this );
		}
		return( rspnSecGrpMembLocked );
	}

	protected CFSecXMsgRspnSecGrpMembUpdated getRspnSecGrpMembUpdated() {
		if( rspnSecGrpMembUpdated == null ) {
			rspnSecGrpMembUpdated = new CFSecXMsgRspnSecGrpMembUpdated( this );
		}
		return( rspnSecGrpMembUpdated );
	}

	protected CFSecXMsgRspnSecGrpMembDeleted getRspnSecGrpMembDeleted() {
		if( rspnSecGrpMembDeleted == null ) {
			rspnSecGrpMembDeleted = new CFSecXMsgRspnSecGrpMembDeleted( this );
		}
		return( rspnSecGrpMembDeleted );
	}

	// SecSession Response s

	protected CFSecXMsgRspnSecSessionRec getRspnSecSessionRec() {
		if( rspnSecSessionRec == null ) {
			rspnSecSessionRec = new CFSecXMsgRspnSecSessionRec( this );
		}
		return( rspnSecSessionRec );
	}

	protected CFSecXMsgRspnSecSessionCreated getRspnSecSessionCreated() {
		if( rspnSecSessionCreated == null ) {
			rspnSecSessionCreated = new CFSecXMsgRspnSecSessionCreated( this );
		}
		return( rspnSecSessionCreated );
	}

	protected CFSecXMsgRspnSecSessionReadSingle getRspnSecSessionReadSingle() {
		if( rspnSecSessionReadSingle == null ) {
			rspnSecSessionReadSingle = new CFSecXMsgRspnSecSessionReadSingle( this );
			rspnSecSessionReadSingle.addElementHandler( "SecSession", getRspnSecSessionRec() );
		}
		return( rspnSecSessionReadSingle );
	}

	protected CFSecXMsgRspnSecSessionReadList getRspnSecSessionReadList() {
		if( rspnSecSessionReadList == null ) {
			rspnSecSessionReadList = new CFSecXMsgRspnSecSessionReadList( this );
			rspnSecSessionReadList.addElementHandler( "SecSession", getRspnSecSessionRec() );
		}
		return( rspnSecSessionReadList );
	}

	protected CFSecXMsgRspnSecSessionLocked getRspnSecSessionLocked() {
		if( rspnSecSessionLocked == null ) {
			rspnSecSessionLocked = new CFSecXMsgRspnSecSessionLocked( this );
		}
		return( rspnSecSessionLocked );
	}

	protected CFSecXMsgRspnSecSessionUpdated getRspnSecSessionUpdated() {
		if( rspnSecSessionUpdated == null ) {
			rspnSecSessionUpdated = new CFSecXMsgRspnSecSessionUpdated( this );
		}
		return( rspnSecSessionUpdated );
	}

	protected CFSecXMsgRspnSecSessionDeleted getRspnSecSessionDeleted() {
		if( rspnSecSessionDeleted == null ) {
			rspnSecSessionDeleted = new CFSecXMsgRspnSecSessionDeleted( this );
		}
		return( rspnSecSessionDeleted );
	}

	// SecUser Response s

	protected CFSecXMsgRspnSecUserRec getRspnSecUserRec() {
		if( rspnSecUserRec == null ) {
			rspnSecUserRec = new CFSecXMsgRspnSecUserRec( this );
		}
		return( rspnSecUserRec );
	}

	protected CFSecXMsgRspnSecUserCreated getRspnSecUserCreated() {
		if( rspnSecUserCreated == null ) {
			rspnSecUserCreated = new CFSecXMsgRspnSecUserCreated( this );
		}
		return( rspnSecUserCreated );
	}

	protected CFSecXMsgRspnSecUserReadSingle getRspnSecUserReadSingle() {
		if( rspnSecUserReadSingle == null ) {
			rspnSecUserReadSingle = new CFSecXMsgRspnSecUserReadSingle( this );
			rspnSecUserReadSingle.addElementHandler( "SecUser", getRspnSecUserRec() );
		}
		return( rspnSecUserReadSingle );
	}

	protected CFSecXMsgRspnSecUserReadList getRspnSecUserReadList() {
		if( rspnSecUserReadList == null ) {
			rspnSecUserReadList = new CFSecXMsgRspnSecUserReadList( this );
			rspnSecUserReadList.addElementHandler( "SecUser", getRspnSecUserRec() );
		}
		return( rspnSecUserReadList );
	}

	protected CFSecXMsgRspnSecUserLocked getRspnSecUserLocked() {
		if( rspnSecUserLocked == null ) {
			rspnSecUserLocked = new CFSecXMsgRspnSecUserLocked( this );
		}
		return( rspnSecUserLocked );
	}

	protected CFSecXMsgRspnSecUserUpdated getRspnSecUserUpdated() {
		if( rspnSecUserUpdated == null ) {
			rspnSecUserUpdated = new CFSecXMsgRspnSecUserUpdated( this );
		}
		return( rspnSecUserUpdated );
	}

	protected CFSecXMsgRspnSecUserDeleted getRspnSecUserDeleted() {
		if( rspnSecUserDeleted == null ) {
			rspnSecUserDeleted = new CFSecXMsgRspnSecUserDeleted( this );
		}
		return( rspnSecUserDeleted );
	}

	// Service Response s

	protected CFSecXMsgRspnServiceRec getRspnServiceRec() {
		if( rspnServiceRec == null ) {
			rspnServiceRec = new CFSecXMsgRspnServiceRec( this );
		}
		return( rspnServiceRec );
	}

	protected CFSecXMsgRspnServiceCreated getRspnServiceCreated() {
		if( rspnServiceCreated == null ) {
			rspnServiceCreated = new CFSecXMsgRspnServiceCreated( this );
		}
		return( rspnServiceCreated );
	}

	protected CFSecXMsgRspnServiceReadSingle getRspnServiceReadSingle() {
		if( rspnServiceReadSingle == null ) {
			rspnServiceReadSingle = new CFSecXMsgRspnServiceReadSingle( this );
			rspnServiceReadSingle.addElementHandler( "Service", getRspnServiceRec() );
		}
		return( rspnServiceReadSingle );
	}

	protected CFSecXMsgRspnServiceReadList getRspnServiceReadList() {
		if( rspnServiceReadList == null ) {
			rspnServiceReadList = new CFSecXMsgRspnServiceReadList( this );
			rspnServiceReadList.addElementHandler( "Service", getRspnServiceRec() );
		}
		return( rspnServiceReadList );
	}

	protected CFSecXMsgRspnServiceLocked getRspnServiceLocked() {
		if( rspnServiceLocked == null ) {
			rspnServiceLocked = new CFSecXMsgRspnServiceLocked( this );
		}
		return( rspnServiceLocked );
	}

	protected CFSecXMsgRspnServiceUpdated getRspnServiceUpdated() {
		if( rspnServiceUpdated == null ) {
			rspnServiceUpdated = new CFSecXMsgRspnServiceUpdated( this );
		}
		return( rspnServiceUpdated );
	}

	protected CFSecXMsgRspnServiceDeleted getRspnServiceDeleted() {
		if( rspnServiceDeleted == null ) {
			rspnServiceDeleted = new CFSecXMsgRspnServiceDeleted( this );
		}
		return( rspnServiceDeleted );
	}

	// ServiceType Response s

	protected CFSecXMsgRspnServiceTypeRec getRspnServiceTypeRec() {
		if( rspnServiceTypeRec == null ) {
			rspnServiceTypeRec = new CFSecXMsgRspnServiceTypeRec( this );
		}
		return( rspnServiceTypeRec );
	}

	protected CFSecXMsgRspnServiceTypeCreated getRspnServiceTypeCreated() {
		if( rspnServiceTypeCreated == null ) {
			rspnServiceTypeCreated = new CFSecXMsgRspnServiceTypeCreated( this );
		}
		return( rspnServiceTypeCreated );
	}

	protected CFSecXMsgRspnServiceTypeReadSingle getRspnServiceTypeReadSingle() {
		if( rspnServiceTypeReadSingle == null ) {
			rspnServiceTypeReadSingle = new CFSecXMsgRspnServiceTypeReadSingle( this );
			rspnServiceTypeReadSingle.addElementHandler( "ServiceType", getRspnServiceTypeRec() );
		}
		return( rspnServiceTypeReadSingle );
	}

	protected CFSecXMsgRspnServiceTypeReadList getRspnServiceTypeReadList() {
		if( rspnServiceTypeReadList == null ) {
			rspnServiceTypeReadList = new CFSecXMsgRspnServiceTypeReadList( this );
			rspnServiceTypeReadList.addElementHandler( "ServiceType", getRspnServiceTypeRec() );
		}
		return( rspnServiceTypeReadList );
	}

	protected CFSecXMsgRspnServiceTypeLocked getRspnServiceTypeLocked() {
		if( rspnServiceTypeLocked == null ) {
			rspnServiceTypeLocked = new CFSecXMsgRspnServiceTypeLocked( this );
		}
		return( rspnServiceTypeLocked );
	}

	protected CFSecXMsgRspnServiceTypeUpdated getRspnServiceTypeUpdated() {
		if( rspnServiceTypeUpdated == null ) {
			rspnServiceTypeUpdated = new CFSecXMsgRspnServiceTypeUpdated( this );
		}
		return( rspnServiceTypeUpdated );
	}

	protected CFSecXMsgRspnServiceTypeDeleted getRspnServiceTypeDeleted() {
		if( rspnServiceTypeDeleted == null ) {
			rspnServiceTypeDeleted = new CFSecXMsgRspnServiceTypeDeleted( this );
		}
		return( rspnServiceTypeDeleted );
	}

	// SysCluster Response s

	protected CFSecXMsgRspnSysClusterRec getRspnSysClusterRec() {
		if( rspnSysClusterRec == null ) {
			rspnSysClusterRec = new CFSecXMsgRspnSysClusterRec( this );
		}
		return( rspnSysClusterRec );
	}

	protected CFSecXMsgRspnSysClusterCreated getRspnSysClusterCreated() {
		if( rspnSysClusterCreated == null ) {
			rspnSysClusterCreated = new CFSecXMsgRspnSysClusterCreated( this );
		}
		return( rspnSysClusterCreated );
	}

	protected CFSecXMsgRspnSysClusterReadSingle getRspnSysClusterReadSingle() {
		if( rspnSysClusterReadSingle == null ) {
			rspnSysClusterReadSingle = new CFSecXMsgRspnSysClusterReadSingle( this );
			rspnSysClusterReadSingle.addElementHandler( "SysCluster", getRspnSysClusterRec() );
		}
		return( rspnSysClusterReadSingle );
	}

	protected CFSecXMsgRspnSysClusterReadList getRspnSysClusterReadList() {
		if( rspnSysClusterReadList == null ) {
			rspnSysClusterReadList = new CFSecXMsgRspnSysClusterReadList( this );
			rspnSysClusterReadList.addElementHandler( "SysCluster", getRspnSysClusterRec() );
		}
		return( rspnSysClusterReadList );
	}

	protected CFSecXMsgRspnSysClusterLocked getRspnSysClusterLocked() {
		if( rspnSysClusterLocked == null ) {
			rspnSysClusterLocked = new CFSecXMsgRspnSysClusterLocked( this );
		}
		return( rspnSysClusterLocked );
	}

	protected CFSecXMsgRspnSysClusterUpdated getRspnSysClusterUpdated() {
		if( rspnSysClusterUpdated == null ) {
			rspnSysClusterUpdated = new CFSecXMsgRspnSysClusterUpdated( this );
		}
		return( rspnSysClusterUpdated );
	}

	protected CFSecXMsgRspnSysClusterDeleted getRspnSysClusterDeleted() {
		if( rspnSysClusterDeleted == null ) {
			rspnSysClusterDeleted = new CFSecXMsgRspnSysClusterDeleted( this );
		}
		return( rspnSysClusterDeleted );
	}

	// TSecGroup Response s

	protected CFSecXMsgRspnTSecGroupRec getRspnTSecGroupRec() {
		if( rspnTSecGroupRec == null ) {
			rspnTSecGroupRec = new CFSecXMsgRspnTSecGroupRec( this );
		}
		return( rspnTSecGroupRec );
	}

	protected CFSecXMsgRspnTSecGroupCreated getRspnTSecGroupCreated() {
		if( rspnTSecGroupCreated == null ) {
			rspnTSecGroupCreated = new CFSecXMsgRspnTSecGroupCreated( this );
		}
		return( rspnTSecGroupCreated );
	}

	protected CFSecXMsgRspnTSecGroupReadSingle getRspnTSecGroupReadSingle() {
		if( rspnTSecGroupReadSingle == null ) {
			rspnTSecGroupReadSingle = new CFSecXMsgRspnTSecGroupReadSingle( this );
			rspnTSecGroupReadSingle.addElementHandler( "TSecGroup", getRspnTSecGroupRec() );
		}
		return( rspnTSecGroupReadSingle );
	}

	protected CFSecXMsgRspnTSecGroupReadList getRspnTSecGroupReadList() {
		if( rspnTSecGroupReadList == null ) {
			rspnTSecGroupReadList = new CFSecXMsgRspnTSecGroupReadList( this );
			rspnTSecGroupReadList.addElementHandler( "TSecGroup", getRspnTSecGroupRec() );
		}
		return( rspnTSecGroupReadList );
	}

	protected CFSecXMsgRspnTSecGroupLocked getRspnTSecGroupLocked() {
		if( rspnTSecGroupLocked == null ) {
			rspnTSecGroupLocked = new CFSecXMsgRspnTSecGroupLocked( this );
		}
		return( rspnTSecGroupLocked );
	}

	protected CFSecXMsgRspnTSecGroupUpdated getRspnTSecGroupUpdated() {
		if( rspnTSecGroupUpdated == null ) {
			rspnTSecGroupUpdated = new CFSecXMsgRspnTSecGroupUpdated( this );
		}
		return( rspnTSecGroupUpdated );
	}

	protected CFSecXMsgRspnTSecGroupDeleted getRspnTSecGroupDeleted() {
		if( rspnTSecGroupDeleted == null ) {
			rspnTSecGroupDeleted = new CFSecXMsgRspnTSecGroupDeleted( this );
		}
		return( rspnTSecGroupDeleted );
	}

	// TSecGrpInc Response s

	protected CFSecXMsgRspnTSecGrpIncRec getRspnTSecGrpIncRec() {
		if( rspnTSecGrpIncRec == null ) {
			rspnTSecGrpIncRec = new CFSecXMsgRspnTSecGrpIncRec( this );
		}
		return( rspnTSecGrpIncRec );
	}

	protected CFSecXMsgRspnTSecGrpIncCreated getRspnTSecGrpIncCreated() {
		if( rspnTSecGrpIncCreated == null ) {
			rspnTSecGrpIncCreated = new CFSecXMsgRspnTSecGrpIncCreated( this );
		}
		return( rspnTSecGrpIncCreated );
	}

	protected CFSecXMsgRspnTSecGrpIncReadSingle getRspnTSecGrpIncReadSingle() {
		if( rspnTSecGrpIncReadSingle == null ) {
			rspnTSecGrpIncReadSingle = new CFSecXMsgRspnTSecGrpIncReadSingle( this );
			rspnTSecGrpIncReadSingle.addElementHandler( "TSecGrpInc", getRspnTSecGrpIncRec() );
		}
		return( rspnTSecGrpIncReadSingle );
	}

	protected CFSecXMsgRspnTSecGrpIncReadList getRspnTSecGrpIncReadList() {
		if( rspnTSecGrpIncReadList == null ) {
			rspnTSecGrpIncReadList = new CFSecXMsgRspnTSecGrpIncReadList( this );
			rspnTSecGrpIncReadList.addElementHandler( "TSecGrpInc", getRspnTSecGrpIncRec() );
		}
		return( rspnTSecGrpIncReadList );
	}

	protected CFSecXMsgRspnTSecGrpIncLocked getRspnTSecGrpIncLocked() {
		if( rspnTSecGrpIncLocked == null ) {
			rspnTSecGrpIncLocked = new CFSecXMsgRspnTSecGrpIncLocked( this );
		}
		return( rspnTSecGrpIncLocked );
	}

	protected CFSecXMsgRspnTSecGrpIncUpdated getRspnTSecGrpIncUpdated() {
		if( rspnTSecGrpIncUpdated == null ) {
			rspnTSecGrpIncUpdated = new CFSecXMsgRspnTSecGrpIncUpdated( this );
		}
		return( rspnTSecGrpIncUpdated );
	}

	protected CFSecXMsgRspnTSecGrpIncDeleted getRspnTSecGrpIncDeleted() {
		if( rspnTSecGrpIncDeleted == null ) {
			rspnTSecGrpIncDeleted = new CFSecXMsgRspnTSecGrpIncDeleted( this );
		}
		return( rspnTSecGrpIncDeleted );
	}

	// TSecGrpMemb Response s

	protected CFSecXMsgRspnTSecGrpMembRec getRspnTSecGrpMembRec() {
		if( rspnTSecGrpMembRec == null ) {
			rspnTSecGrpMembRec = new CFSecXMsgRspnTSecGrpMembRec( this );
		}
		return( rspnTSecGrpMembRec );
	}

	protected CFSecXMsgRspnTSecGrpMembCreated getRspnTSecGrpMembCreated() {
		if( rspnTSecGrpMembCreated == null ) {
			rspnTSecGrpMembCreated = new CFSecXMsgRspnTSecGrpMembCreated( this );
		}
		return( rspnTSecGrpMembCreated );
	}

	protected CFSecXMsgRspnTSecGrpMembReadSingle getRspnTSecGrpMembReadSingle() {
		if( rspnTSecGrpMembReadSingle == null ) {
			rspnTSecGrpMembReadSingle = new CFSecXMsgRspnTSecGrpMembReadSingle( this );
			rspnTSecGrpMembReadSingle.addElementHandler( "TSecGrpMemb", getRspnTSecGrpMembRec() );
		}
		return( rspnTSecGrpMembReadSingle );
	}

	protected CFSecXMsgRspnTSecGrpMembReadList getRspnTSecGrpMembReadList() {
		if( rspnTSecGrpMembReadList == null ) {
			rspnTSecGrpMembReadList = new CFSecXMsgRspnTSecGrpMembReadList( this );
			rspnTSecGrpMembReadList.addElementHandler( "TSecGrpMemb", getRspnTSecGrpMembRec() );
		}
		return( rspnTSecGrpMembReadList );
	}

	protected CFSecXMsgRspnTSecGrpMembLocked getRspnTSecGrpMembLocked() {
		if( rspnTSecGrpMembLocked == null ) {
			rspnTSecGrpMembLocked = new CFSecXMsgRspnTSecGrpMembLocked( this );
		}
		return( rspnTSecGrpMembLocked );
	}

	protected CFSecXMsgRspnTSecGrpMembUpdated getRspnTSecGrpMembUpdated() {
		if( rspnTSecGrpMembUpdated == null ) {
			rspnTSecGrpMembUpdated = new CFSecXMsgRspnTSecGrpMembUpdated( this );
		}
		return( rspnTSecGrpMembUpdated );
	}

	protected CFSecXMsgRspnTSecGrpMembDeleted getRspnTSecGrpMembDeleted() {
		if( rspnTSecGrpMembDeleted == null ) {
			rspnTSecGrpMembDeleted = new CFSecXMsgRspnTSecGrpMembDeleted( this );
		}
		return( rspnTSecGrpMembDeleted );
	}

	// Tenant Response s

	protected CFSecXMsgRspnTenantRec getRspnTenantRec() {
		if( rspnTenantRec == null ) {
			rspnTenantRec = new CFSecXMsgRspnTenantRec( this );
		}
		return( rspnTenantRec );
	}

	protected CFSecXMsgRspnTenantCreated getRspnTenantCreated() {
		if( rspnTenantCreated == null ) {
			rspnTenantCreated = new CFSecXMsgRspnTenantCreated( this );
		}
		return( rspnTenantCreated );
	}

	protected CFSecXMsgRspnTenantReadSingle getRspnTenantReadSingle() {
		if( rspnTenantReadSingle == null ) {
			rspnTenantReadSingle = new CFSecXMsgRspnTenantReadSingle( this );
			rspnTenantReadSingle.addElementHandler( "Tenant", getRspnTenantRec() );
		}
		return( rspnTenantReadSingle );
	}

	protected CFSecXMsgRspnTenantReadList getRspnTenantReadList() {
		if( rspnTenantReadList == null ) {
			rspnTenantReadList = new CFSecXMsgRspnTenantReadList( this );
			rspnTenantReadList.addElementHandler( "Tenant", getRspnTenantRec() );
		}
		return( rspnTenantReadList );
	}

	protected CFSecXMsgRspnTenantLocked getRspnTenantLocked() {
		if( rspnTenantLocked == null ) {
			rspnTenantLocked = new CFSecXMsgRspnTenantLocked( this );
		}
		return( rspnTenantLocked );
	}

	protected CFSecXMsgRspnTenantUpdated getRspnTenantUpdated() {
		if( rspnTenantUpdated == null ) {
			rspnTenantUpdated = new CFSecXMsgRspnTenantUpdated( this );
		}
		return( rspnTenantUpdated );
	}

	protected CFSecXMsgRspnTenantDeleted getRspnTenantDeleted() {
		if( rspnTenantDeleted == null ) {
			rspnTenantDeleted = new CFSecXMsgRspnTenantDeleted( this );
		}
		return( rspnTenantDeleted );
	}

	// Root Element  Resolver Factory

	protected CFSecSaxRspnRoot getSaxRspnRoot() {
		if( saxRoot == null ) {
			saxRoot = new CFSecSaxRspnRoot( this );
			saxRoot.addElementHandler( "CFSecRspn", getSaxRspnDoc() );
		}
		return( saxRoot );
	}

	// Root Element 

	/*
	 *	CFSecSaxRspnRoot XML SAX Root Element  implementation
	 */
	public class CFSecSaxRspnRoot
		extends CFLibXmlCoreElementHandler
	{
		public CFSecSaxRspnRoot( CFSecXMsgRspn xmsgRspn ) {
			super( xmsgRspn );
		}

		public void startElement(
			String		uri,
			String		localName,
			String		qName,
			Attributes	attrs )
		throws SAXException
		{
		}

		public void endElement(
			String		uri,
			String		localName,
			String		qName )
		throws SAXException
		{
		}
	}

	// Document Element  Resolver Factory

	protected CFSecSaxRspnDoc getSaxRspnDoc() {
		if( saxDoc == null ) {
			saxDoc = new CFSecSaxRspnDoc( this );
			saxDoc.addElementHandler( "RspnNoDataFound", getRspnNoDataFound() );
			saxDoc.addElementHandler( "RspnException", getRspnException() );
			saxDoc.addElementHandler( "RspnFileLoaded", getRspnFileLoaded() );
			saxDoc.addElementHandler( "RspnLoggedIn", getRspnLoggedIn() );
			saxDoc.addElementHandler( "RspnLoggedOut", getRspnLoggedOut() );
			saxDoc.addElementHandler( "RspnServerProcExecuted", getRspnServerProcExecuted() );

			// Cluster Response s

			saxDoc.addElementHandler( "RspnClusterCreated", getRspnClusterCreated() );
			saxDoc.addElementHandler( "RspnClusterReadSingle", getRspnClusterReadSingle() );
			saxDoc.addElementHandler( "RspnClusterReadList", getRspnClusterReadList() );
			saxDoc.addElementHandler( "RspnClusterLocked", getRspnClusterLocked() );
			saxDoc.addElementHandler( "RspnClusterUpdated", getRspnClusterUpdated() );
			saxDoc.addElementHandler( "RspnClusterDeleted", getRspnClusterDeleted() );

			// HostNode Response s

			saxDoc.addElementHandler( "RspnHostNodeCreated", getRspnHostNodeCreated() );
			saxDoc.addElementHandler( "RspnHostNodeReadSingle", getRspnHostNodeReadSingle() );
			saxDoc.addElementHandler( "RspnHostNodeReadList", getRspnHostNodeReadList() );
			saxDoc.addElementHandler( "RspnHostNodeLocked", getRspnHostNodeLocked() );
			saxDoc.addElementHandler( "RspnHostNodeUpdated", getRspnHostNodeUpdated() );
			saxDoc.addElementHandler( "RspnHostNodeDeleted", getRspnHostNodeDeleted() );

			// ISOCcy Response s

			saxDoc.addElementHandler( "RspnISOCcyCreated", getRspnISOCcyCreated() );
			saxDoc.addElementHandler( "RspnISOCcyReadSingle", getRspnISOCcyReadSingle() );
			saxDoc.addElementHandler( "RspnISOCcyReadList", getRspnISOCcyReadList() );
			saxDoc.addElementHandler( "RspnISOCcyLocked", getRspnISOCcyLocked() );
			saxDoc.addElementHandler( "RspnISOCcyUpdated", getRspnISOCcyUpdated() );
			saxDoc.addElementHandler( "RspnISOCcyDeleted", getRspnISOCcyDeleted() );

			// ISOCtry Response s

			saxDoc.addElementHandler( "RspnISOCtryCreated", getRspnISOCtryCreated() );
			saxDoc.addElementHandler( "RspnISOCtryReadSingle", getRspnISOCtryReadSingle() );
			saxDoc.addElementHandler( "RspnISOCtryReadList", getRspnISOCtryReadList() );
			saxDoc.addElementHandler( "RspnISOCtryLocked", getRspnISOCtryLocked() );
			saxDoc.addElementHandler( "RspnISOCtryUpdated", getRspnISOCtryUpdated() );
			saxDoc.addElementHandler( "RspnISOCtryDeleted", getRspnISOCtryDeleted() );

			// ISOCtryCcy Response s

			saxDoc.addElementHandler( "RspnISOCtryCcyCreated", getRspnISOCtryCcyCreated() );
			saxDoc.addElementHandler( "RspnISOCtryCcyReadSingle", getRspnISOCtryCcyReadSingle() );
			saxDoc.addElementHandler( "RspnISOCtryCcyReadList", getRspnISOCtryCcyReadList() );
			saxDoc.addElementHandler( "RspnISOCtryCcyLocked", getRspnISOCtryCcyLocked() );
			saxDoc.addElementHandler( "RspnISOCtryCcyUpdated", getRspnISOCtryCcyUpdated() );
			saxDoc.addElementHandler( "RspnISOCtryCcyDeleted", getRspnISOCtryCcyDeleted() );

			// ISOCtryLang Response s

			saxDoc.addElementHandler( "RspnISOCtryLangCreated", getRspnISOCtryLangCreated() );
			saxDoc.addElementHandler( "RspnISOCtryLangReadSingle", getRspnISOCtryLangReadSingle() );
			saxDoc.addElementHandler( "RspnISOCtryLangReadList", getRspnISOCtryLangReadList() );
			saxDoc.addElementHandler( "RspnISOCtryLangLocked", getRspnISOCtryLangLocked() );
			saxDoc.addElementHandler( "RspnISOCtryLangUpdated", getRspnISOCtryLangUpdated() );
			saxDoc.addElementHandler( "RspnISOCtryLangDeleted", getRspnISOCtryLangDeleted() );

			// ISOLang Response s

			saxDoc.addElementHandler( "RspnISOLangCreated", getRspnISOLangCreated() );
			saxDoc.addElementHandler( "RspnISOLangReadSingle", getRspnISOLangReadSingle() );
			saxDoc.addElementHandler( "RspnISOLangReadList", getRspnISOLangReadList() );
			saxDoc.addElementHandler( "RspnISOLangLocked", getRspnISOLangLocked() );
			saxDoc.addElementHandler( "RspnISOLangUpdated", getRspnISOLangUpdated() );
			saxDoc.addElementHandler( "RspnISOLangDeleted", getRspnISOLangDeleted() );

			// ISOTZone Response s

			saxDoc.addElementHandler( "RspnISOTZoneCreated", getRspnISOTZoneCreated() );
			saxDoc.addElementHandler( "RspnISOTZoneReadSingle", getRspnISOTZoneReadSingle() );
			saxDoc.addElementHandler( "RspnISOTZoneReadList", getRspnISOTZoneReadList() );
			saxDoc.addElementHandler( "RspnISOTZoneLocked", getRspnISOTZoneLocked() );
			saxDoc.addElementHandler( "RspnISOTZoneUpdated", getRspnISOTZoneUpdated() );
			saxDoc.addElementHandler( "RspnISOTZoneDeleted", getRspnISOTZoneDeleted() );

			// SecApp Response s

			saxDoc.addElementHandler( "RspnSecAppCreated", getRspnSecAppCreated() );
			saxDoc.addElementHandler( "RspnSecAppReadSingle", getRspnSecAppReadSingle() );
			saxDoc.addElementHandler( "RspnSecAppReadList", getRspnSecAppReadList() );
			saxDoc.addElementHandler( "RspnSecAppLocked", getRspnSecAppLocked() );
			saxDoc.addElementHandler( "RspnSecAppUpdated", getRspnSecAppUpdated() );
			saxDoc.addElementHandler( "RspnSecAppDeleted", getRspnSecAppDeleted() );

			// SecDevice Response s

			saxDoc.addElementHandler( "RspnSecDeviceCreated", getRspnSecDeviceCreated() );
			saxDoc.addElementHandler( "RspnSecDeviceReadSingle", getRspnSecDeviceReadSingle() );
			saxDoc.addElementHandler( "RspnSecDeviceReadList", getRspnSecDeviceReadList() );
			saxDoc.addElementHandler( "RspnSecDeviceLocked", getRspnSecDeviceLocked() );
			saxDoc.addElementHandler( "RspnSecDeviceUpdated", getRspnSecDeviceUpdated() );
			saxDoc.addElementHandler( "RspnSecDeviceDeleted", getRspnSecDeviceDeleted() );

			// SecForm Response s

			saxDoc.addElementHandler( "RspnSecFormCreated", getRspnSecFormCreated() );
			saxDoc.addElementHandler( "RspnSecFormReadSingle", getRspnSecFormReadSingle() );
			saxDoc.addElementHandler( "RspnSecFormReadList", getRspnSecFormReadList() );
			saxDoc.addElementHandler( "RspnSecFormLocked", getRspnSecFormLocked() );
			saxDoc.addElementHandler( "RspnSecFormUpdated", getRspnSecFormUpdated() );
			saxDoc.addElementHandler( "RspnSecFormDeleted", getRspnSecFormDeleted() );

			// SecGroup Response s

			saxDoc.addElementHandler( "RspnSecGroupCreated", getRspnSecGroupCreated() );
			saxDoc.addElementHandler( "RspnSecGroupReadSingle", getRspnSecGroupReadSingle() );
			saxDoc.addElementHandler( "RspnSecGroupReadList", getRspnSecGroupReadList() );
			saxDoc.addElementHandler( "RspnSecGroupLocked", getRspnSecGroupLocked() );
			saxDoc.addElementHandler( "RspnSecGroupUpdated", getRspnSecGroupUpdated() );
			saxDoc.addElementHandler( "RspnSecGroupDeleted", getRspnSecGroupDeleted() );

			// SecGroupForm Response s

			saxDoc.addElementHandler( "RspnSecGroupFormCreated", getRspnSecGroupFormCreated() );
			saxDoc.addElementHandler( "RspnSecGroupFormReadSingle", getRspnSecGroupFormReadSingle() );
			saxDoc.addElementHandler( "RspnSecGroupFormReadList", getRspnSecGroupFormReadList() );
			saxDoc.addElementHandler( "RspnSecGroupFormLocked", getRspnSecGroupFormLocked() );
			saxDoc.addElementHandler( "RspnSecGroupFormUpdated", getRspnSecGroupFormUpdated() );
			saxDoc.addElementHandler( "RspnSecGroupFormDeleted", getRspnSecGroupFormDeleted() );

			// SecGrpInc Response s

			saxDoc.addElementHandler( "RspnSecGrpIncCreated", getRspnSecGrpIncCreated() );
			saxDoc.addElementHandler( "RspnSecGrpIncReadSingle", getRspnSecGrpIncReadSingle() );
			saxDoc.addElementHandler( "RspnSecGrpIncReadList", getRspnSecGrpIncReadList() );
			saxDoc.addElementHandler( "RspnSecGrpIncLocked", getRspnSecGrpIncLocked() );
			saxDoc.addElementHandler( "RspnSecGrpIncUpdated", getRspnSecGrpIncUpdated() );
			saxDoc.addElementHandler( "RspnSecGrpIncDeleted", getRspnSecGrpIncDeleted() );

			// SecGrpMemb Response s

			saxDoc.addElementHandler( "RspnSecGrpMembCreated", getRspnSecGrpMembCreated() );
			saxDoc.addElementHandler( "RspnSecGrpMembReadSingle", getRspnSecGrpMembReadSingle() );
			saxDoc.addElementHandler( "RspnSecGrpMembReadList", getRspnSecGrpMembReadList() );
			saxDoc.addElementHandler( "RspnSecGrpMembLocked", getRspnSecGrpMembLocked() );
			saxDoc.addElementHandler( "RspnSecGrpMembUpdated", getRspnSecGrpMembUpdated() );
			saxDoc.addElementHandler( "RspnSecGrpMembDeleted", getRspnSecGrpMembDeleted() );

			// SecSession Response s

			saxDoc.addElementHandler( "RspnSecSessionCreated", getRspnSecSessionCreated() );
			saxDoc.addElementHandler( "RspnSecSessionReadSingle", getRspnSecSessionReadSingle() );
			saxDoc.addElementHandler( "RspnSecSessionReadList", getRspnSecSessionReadList() );
			saxDoc.addElementHandler( "RspnSecSessionLocked", getRspnSecSessionLocked() );
			saxDoc.addElementHandler( "RspnSecSessionUpdated", getRspnSecSessionUpdated() );
			saxDoc.addElementHandler( "RspnSecSessionDeleted", getRspnSecSessionDeleted() );

			// SecUser Response s

			saxDoc.addElementHandler( "RspnSecUserCreated", getRspnSecUserCreated() );
			saxDoc.addElementHandler( "RspnSecUserReadSingle", getRspnSecUserReadSingle() );
			saxDoc.addElementHandler( "RspnSecUserReadList", getRspnSecUserReadList() );
			saxDoc.addElementHandler( "RspnSecUserLocked", getRspnSecUserLocked() );
			saxDoc.addElementHandler( "RspnSecUserUpdated", getRspnSecUserUpdated() );
			saxDoc.addElementHandler( "RspnSecUserDeleted", getRspnSecUserDeleted() );

			// Service Response s

			saxDoc.addElementHandler( "RspnServiceCreated", getRspnServiceCreated() );
			saxDoc.addElementHandler( "RspnServiceReadSingle", getRspnServiceReadSingle() );
			saxDoc.addElementHandler( "RspnServiceReadList", getRspnServiceReadList() );
			saxDoc.addElementHandler( "RspnServiceLocked", getRspnServiceLocked() );
			saxDoc.addElementHandler( "RspnServiceUpdated", getRspnServiceUpdated() );
			saxDoc.addElementHandler( "RspnServiceDeleted", getRspnServiceDeleted() );

			// ServiceType Response s

			saxDoc.addElementHandler( "RspnServiceTypeCreated", getRspnServiceTypeCreated() );
			saxDoc.addElementHandler( "RspnServiceTypeReadSingle", getRspnServiceTypeReadSingle() );
			saxDoc.addElementHandler( "RspnServiceTypeReadList", getRspnServiceTypeReadList() );
			saxDoc.addElementHandler( "RspnServiceTypeLocked", getRspnServiceTypeLocked() );
			saxDoc.addElementHandler( "RspnServiceTypeUpdated", getRspnServiceTypeUpdated() );
			saxDoc.addElementHandler( "RspnServiceTypeDeleted", getRspnServiceTypeDeleted() );

			// SysCluster Response s

			saxDoc.addElementHandler( "RspnSysClusterCreated", getRspnSysClusterCreated() );
			saxDoc.addElementHandler( "RspnSysClusterReadSingle", getRspnSysClusterReadSingle() );
			saxDoc.addElementHandler( "RspnSysClusterReadList", getRspnSysClusterReadList() );
			saxDoc.addElementHandler( "RspnSysClusterLocked", getRspnSysClusterLocked() );
			saxDoc.addElementHandler( "RspnSysClusterUpdated", getRspnSysClusterUpdated() );
			saxDoc.addElementHandler( "RspnSysClusterDeleted", getRspnSysClusterDeleted() );

			// TSecGroup Response s

			saxDoc.addElementHandler( "RspnTSecGroupCreated", getRspnTSecGroupCreated() );
			saxDoc.addElementHandler( "RspnTSecGroupReadSingle", getRspnTSecGroupReadSingle() );
			saxDoc.addElementHandler( "RspnTSecGroupReadList", getRspnTSecGroupReadList() );
			saxDoc.addElementHandler( "RspnTSecGroupLocked", getRspnTSecGroupLocked() );
			saxDoc.addElementHandler( "RspnTSecGroupUpdated", getRspnTSecGroupUpdated() );
			saxDoc.addElementHandler( "RspnTSecGroupDeleted", getRspnTSecGroupDeleted() );

			// TSecGrpInc Response s

			saxDoc.addElementHandler( "RspnTSecGrpIncCreated", getRspnTSecGrpIncCreated() );
			saxDoc.addElementHandler( "RspnTSecGrpIncReadSingle", getRspnTSecGrpIncReadSingle() );
			saxDoc.addElementHandler( "RspnTSecGrpIncReadList", getRspnTSecGrpIncReadList() );
			saxDoc.addElementHandler( "RspnTSecGrpIncLocked", getRspnTSecGrpIncLocked() );
			saxDoc.addElementHandler( "RspnTSecGrpIncUpdated", getRspnTSecGrpIncUpdated() );
			saxDoc.addElementHandler( "RspnTSecGrpIncDeleted", getRspnTSecGrpIncDeleted() );

			// TSecGrpMemb Response s

			saxDoc.addElementHandler( "RspnTSecGrpMembCreated", getRspnTSecGrpMembCreated() );
			saxDoc.addElementHandler( "RspnTSecGrpMembReadSingle", getRspnTSecGrpMembReadSingle() );
			saxDoc.addElementHandler( "RspnTSecGrpMembReadList", getRspnTSecGrpMembReadList() );
			saxDoc.addElementHandler( "RspnTSecGrpMembLocked", getRspnTSecGrpMembLocked() );
			saxDoc.addElementHandler( "RspnTSecGrpMembUpdated", getRspnTSecGrpMembUpdated() );
			saxDoc.addElementHandler( "RspnTSecGrpMembDeleted", getRspnTSecGrpMembDeleted() );

			// Tenant Response s

			saxDoc.addElementHandler( "RspnTenantCreated", getRspnTenantCreated() );
			saxDoc.addElementHandler( "RspnTenantReadSingle", getRspnTenantReadSingle() );
			saxDoc.addElementHandler( "RspnTenantReadList", getRspnTenantReadList() );
			saxDoc.addElementHandler( "RspnTenantLocked", getRspnTenantLocked() );
			saxDoc.addElementHandler( "RspnTenantUpdated", getRspnTenantUpdated() );
			saxDoc.addElementHandler( "RspnTenantDeleted", getRspnTenantDeleted() );

		}
		return( saxDoc );
	}

	// Document Element 

	/*
	 *	CFSecSaxRspnDoc XML SAX Doc Element  implementation
	 */
	public class CFSecSaxRspnDoc
		extends CFLibXmlCoreElementHandler
	{
		public CFSecSaxRspnDoc( CFSecXMsgRspn xmsgRspn ) {
			super( xmsgRspn );
		}

		public void startElement(
			String		uri,
			String		localName,
			String		qName,
			Attributes	attrs )
		throws SAXException
		{
		}

		public void endElement(
			String		uri,
			String		localName,
			String		qName )
		throws SAXException
		{
		}
	}

	// Parse an XML string's contents

	public void parseStringContents( String str ) {
		deleted = false;
		exceptionRaised = null;
		lastObjectProcessed = null;
		sortedListOfObjects = null;
		logContent = null;
		dataChanged = false;
		super.parseStringContents( str );
	}

	// Parse a file

	public void parse( String url ) {
		deleted = false;
		exceptionRaised = null;
		lastObjectProcessed = null;
		sortedListOfObjects = null;
		logContent = null;
		dataChanged = false;
		super.parse( url );
	}

	public void parseFile( String url ) {
		deleted = false;
		exceptionRaised = null;
		lastObjectProcessed = null;
		sortedListOfObjects = null;
		logContent = null;
		dataChanged = false;
		super.parse( url );
	}
}
