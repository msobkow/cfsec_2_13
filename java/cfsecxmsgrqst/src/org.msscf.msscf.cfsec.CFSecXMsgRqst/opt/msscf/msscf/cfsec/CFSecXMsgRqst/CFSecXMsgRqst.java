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

package com.github.msobkow.cfsec.CFSecXMsgRqst;

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
import com.github.msobkow.cfsec.CFSecXMsg.CFSecXMsgSchemaMessageFormatter;

public class CFSecXMsgRqst
	extends CFLibXmlCoreSaxParser
	implements ContentHandler,
		ICFTipRequestHandler,
		ICFTipThrowableFormatter
{

	// The namespace URI of the supported schema
	public final static String	SCHEMA_XMLNS = "uri://xsd/cfsecrqst";

	// The source for loading the supported schema
	public final static String	SCHEMA_URI = "../bin/xsd/cfsec-rqst.xsd";
	public final static String	SCHEMA_ROOT_URI = "/xsd/cfsec-rqst.xsd";
	protected static Grammar myGrammar = null;

	private CFSecXMsgSchemaMessageFormatter schemaMessageFormatter = new CFSecXMsgSchemaMessageFormatter();
	private ICFSecSchemaObj schemaObj = null;
	private CFTipEnvelopeHandler envelope = null;
	private StringBuffer response = new StringBuffer();
	private boolean caughtException = false;
	// Constructors

	public CFSecXMsgRqst() {
		super();
		setRootElementHandler( getSaxRqstRoot() );
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

	public CFSecXMsgRqst( ICFSecSchemaObj schemaObj ) {
		super();
		setRootElementHandler( getSaxRqstRoot() );
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

	public CFSecXMsgRqst( ICFLibMessageLog logger ) {
		super( logger );
		setRootElementHandler( getSaxRqstRoot() );
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

	public CFSecXMsgRqst( ICFSecSchemaObj schemaObj, ICFLibMessageLog logger ) {
		super( logger );
		setRootElementHandler( getSaxRqstRoot() );
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

	// Accessors for formatter

	public CFSecXMsgSchemaMessageFormatter getSchemaMessageFormatter() {
		return( schemaMessageFormatter );
	}

	// Accessors for envelope handler

	public CFTipEnvelopeHandler getEnvelope() {
		return( envelope );
	}

	public void setEnvelope( CFTipEnvelopeHandler value ) {
		envelope = value;
		if( envelope != null ) {
			envelope.setThrowableFormatter( this );
		}
	}


	// Satisfy ICFLibThrowableFormatter

	public String formatResponseThrowable( Throwable t ) {
		String response = schemaMessageFormatter.formatRspnXmlPreamble() + "\n"
				+	"\t" + CFSecXMsgSchemaMessageFormatter.formatRspnException( "\n\t\t\t\t", t )
				+	"\n"
				+	schemaMessageFormatter.formatRspnXmlPostamble();
		return( response );
	}

	// Accessors for invoker

	public String getResponse() {
		String retval = response.toString();
		return( retval );
	}

	public void resetResponse() {
		response = new StringBuffer();
		caughtException = false;
	}

	public void appendResponse( String str ) {
		response.append( str );
	}

	public boolean getCaughtException() {
		return( caughtException );
	}

	public void setCaughtException( boolean value ) {
		caughtException = value;
	}

	// Element  instances

	// Cluster Request s

	private CFSecXMsgRqstClusterCreate rqstClusterCreate = null;
	private CFSecXMsgRqstClusterRead rqstClusterRead = null;
	private CFSecXMsgRqstClusterLock rqstClusterLock = null;
	private CFSecXMsgRqstClusterUpdate rqstClusterUpdate = null;
	private CFSecXMsgRqstClusterDelete rqstClusterDelete = null;
	private CFSecXMsgRqstClusterReadAll rqstClusterReadAll = null;
	private CFSecXMsgRqstClusterPageAll rqstClusterPageAll = null;
	private CFSecXMsgRqstClusterRdByUDomNameIdx rqstClusterRdByUDomNameIdx = null;
	private CFSecXMsgRqstClusterRdByUDescrIdx rqstClusterRdByUDescrIdx = null;
	private CFSecXMsgRqstClusterDelByIdIdx rqstClusterDelByIdIdx = null;
	private CFSecXMsgRqstClusterDelByUDomNameIdx rqstClusterDelByUDomNameIdx = null;
	private CFSecXMsgRqstClusterDelByUDescrIdx rqstClusterDelByUDescrIdx = null;
	// HostNode Request s

	private CFSecXMsgRqstHostNodeCreate rqstHostNodeCreate = null;
	private CFSecXMsgRqstHostNodeRead rqstHostNodeRead = null;
	private CFSecXMsgRqstHostNodeLock rqstHostNodeLock = null;
	private CFSecXMsgRqstHostNodeUpdate rqstHostNodeUpdate = null;
	private CFSecXMsgRqstHostNodeDelete rqstHostNodeDelete = null;
	private CFSecXMsgRqstHostNodeReadAll rqstHostNodeReadAll = null;
	private CFSecXMsgRqstHostNodePageAll rqstHostNodePageAll = null;
	private CFSecXMsgRqstHostNodeRdByClusterIdx rqstHostNodeRdByClusterIdx = null;
	private CFSecXMsgRqstHostNodeRdByUDescrIdx rqstHostNodeRdByUDescrIdx = null;
	private CFSecXMsgRqstHostNodeRdByHostNameIdx rqstHostNodeRdByHostNameIdx = null;
	private CFSecXMsgRqstHostNodePageByClusterIdx rqstHostNodePageByClusterIdx = null;
	private CFSecXMsgRqstHostNodeDelByIdIdx rqstHostNodeDelByIdIdx = null;
	private CFSecXMsgRqstHostNodeDelByClusterIdx rqstHostNodeDelByClusterIdx = null;
	private CFSecXMsgRqstHostNodeDelByUDescrIdx rqstHostNodeDelByUDescrIdx = null;
	private CFSecXMsgRqstHostNodeDelByHostNameIdx rqstHostNodeDelByHostNameIdx = null;
	// ISOCcy Request s

	private CFSecXMsgRqstISOCcyCreate rqstISOCcyCreate = null;
	private CFSecXMsgRqstISOCcyRead rqstISOCcyRead = null;
	private CFSecXMsgRqstISOCcyLock rqstISOCcyLock = null;
	private CFSecXMsgRqstISOCcyUpdate rqstISOCcyUpdate = null;
	private CFSecXMsgRqstISOCcyDelete rqstISOCcyDelete = null;
	private CFSecXMsgRqstISOCcyReadAll rqstISOCcyReadAll = null;
	private CFSecXMsgRqstISOCcyRdByCcyCdIdx rqstISOCcyRdByCcyCdIdx = null;
	private CFSecXMsgRqstISOCcyRdByCcyNmIdx rqstISOCcyRdByCcyNmIdx = null;
	private CFSecXMsgRqstISOCcyDelByIdIdx rqstISOCcyDelByIdIdx = null;
	private CFSecXMsgRqstISOCcyDelByCcyCdIdx rqstISOCcyDelByCcyCdIdx = null;
	private CFSecXMsgRqstISOCcyDelByCcyNmIdx rqstISOCcyDelByCcyNmIdx = null;
	// ISOCtry Request s

	private CFSecXMsgRqstISOCtryCreate rqstISOCtryCreate = null;
	private CFSecXMsgRqstISOCtryRead rqstISOCtryRead = null;
	private CFSecXMsgRqstISOCtryLock rqstISOCtryLock = null;
	private CFSecXMsgRqstISOCtryUpdate rqstISOCtryUpdate = null;
	private CFSecXMsgRqstISOCtryDelete rqstISOCtryDelete = null;
	private CFSecXMsgRqstISOCtryReadAll rqstISOCtryReadAll = null;
	private CFSecXMsgRqstISOCtryRdByISOCodeIdx rqstISOCtryRdByISOCodeIdx = null;
	private CFSecXMsgRqstISOCtryRdByNameIdx rqstISOCtryRdByNameIdx = null;
	private CFSecXMsgRqstISOCtryDelByIdIdx rqstISOCtryDelByIdIdx = null;
	private CFSecXMsgRqstISOCtryDelByISOCodeIdx rqstISOCtryDelByISOCodeIdx = null;
	private CFSecXMsgRqstISOCtryDelByNameIdx rqstISOCtryDelByNameIdx = null;
	// ISOCtryCcy Request s

	private CFSecXMsgRqstISOCtryCcyCreate rqstISOCtryCcyCreate = null;
	private CFSecXMsgRqstISOCtryCcyRead rqstISOCtryCcyRead = null;
	private CFSecXMsgRqstISOCtryCcyLock rqstISOCtryCcyLock = null;
	private CFSecXMsgRqstISOCtryCcyUpdate rqstISOCtryCcyUpdate = null;
	private CFSecXMsgRqstISOCtryCcyDelete rqstISOCtryCcyDelete = null;
	private CFSecXMsgRqstISOCtryCcyReadAll rqstISOCtryCcyReadAll = null;
	private CFSecXMsgRqstISOCtryCcyRdByCtryIdx rqstISOCtryCcyRdByCtryIdx = null;
	private CFSecXMsgRqstISOCtryCcyRdByCcyIdx rqstISOCtryCcyRdByCcyIdx = null;
	private CFSecXMsgRqstISOCtryCcyDelByIdIdx rqstISOCtryCcyDelByIdIdx = null;
	private CFSecXMsgRqstISOCtryCcyDelByCtryIdx rqstISOCtryCcyDelByCtryIdx = null;
	private CFSecXMsgRqstISOCtryCcyDelByCcyIdx rqstISOCtryCcyDelByCcyIdx = null;
	// ISOCtryLang Request s

	private CFSecXMsgRqstISOCtryLangCreate rqstISOCtryLangCreate = null;
	private CFSecXMsgRqstISOCtryLangRead rqstISOCtryLangRead = null;
	private CFSecXMsgRqstISOCtryLangLock rqstISOCtryLangLock = null;
	private CFSecXMsgRqstISOCtryLangUpdate rqstISOCtryLangUpdate = null;
	private CFSecXMsgRqstISOCtryLangDelete rqstISOCtryLangDelete = null;
	private CFSecXMsgRqstISOCtryLangReadAll rqstISOCtryLangReadAll = null;
	private CFSecXMsgRqstISOCtryLangRdByCtryIdx rqstISOCtryLangRdByCtryIdx = null;
	private CFSecXMsgRqstISOCtryLangRdByLangIdx rqstISOCtryLangRdByLangIdx = null;
	private CFSecXMsgRqstISOCtryLangDelByIdIdx rqstISOCtryLangDelByIdIdx = null;
	private CFSecXMsgRqstISOCtryLangDelByCtryIdx rqstISOCtryLangDelByCtryIdx = null;
	private CFSecXMsgRqstISOCtryLangDelByLangIdx rqstISOCtryLangDelByLangIdx = null;
	// ISOLang Request s

	private CFSecXMsgRqstISOLangCreate rqstISOLangCreate = null;
	private CFSecXMsgRqstISOLangRead rqstISOLangRead = null;
	private CFSecXMsgRqstISOLangLock rqstISOLangLock = null;
	private CFSecXMsgRqstISOLangUpdate rqstISOLangUpdate = null;
	private CFSecXMsgRqstISOLangDelete rqstISOLangDelete = null;
	private CFSecXMsgRqstISOLangReadAll rqstISOLangReadAll = null;
	private CFSecXMsgRqstISOLangRdByCode3Idx rqstISOLangRdByCode3Idx = null;
	private CFSecXMsgRqstISOLangRdByCode2Idx rqstISOLangRdByCode2Idx = null;
	private CFSecXMsgRqstISOLangDelByIdIdx rqstISOLangDelByIdIdx = null;
	private CFSecXMsgRqstISOLangDelByCode3Idx rqstISOLangDelByCode3Idx = null;
	private CFSecXMsgRqstISOLangDelByCode2Idx rqstISOLangDelByCode2Idx = null;
	// ISOTZone Request s

	private CFSecXMsgRqstISOTZoneCreate rqstISOTZoneCreate = null;
	private CFSecXMsgRqstISOTZoneRead rqstISOTZoneRead = null;
	private CFSecXMsgRqstISOTZoneLock rqstISOTZoneLock = null;
	private CFSecXMsgRqstISOTZoneUpdate rqstISOTZoneUpdate = null;
	private CFSecXMsgRqstISOTZoneDelete rqstISOTZoneDelete = null;
	private CFSecXMsgRqstISOTZoneReadAll rqstISOTZoneReadAll = null;
	private CFSecXMsgRqstISOTZoneRdByOffsetIdx rqstISOTZoneRdByOffsetIdx = null;
	private CFSecXMsgRqstISOTZoneRdByUTZNameIdx rqstISOTZoneRdByUTZNameIdx = null;
	private CFSecXMsgRqstISOTZoneRdByIso8601Idx rqstISOTZoneRdByIso8601Idx = null;
	private CFSecXMsgRqstISOTZoneDelByIdIdx rqstISOTZoneDelByIdIdx = null;
	private CFSecXMsgRqstISOTZoneDelByOffsetIdx rqstISOTZoneDelByOffsetIdx = null;
	private CFSecXMsgRqstISOTZoneDelByUTZNameIdx rqstISOTZoneDelByUTZNameIdx = null;
	private CFSecXMsgRqstISOTZoneDelByIso8601Idx rqstISOTZoneDelByIso8601Idx = null;
	// SecApp Request s

	private CFSecXMsgRqstSecAppCreate rqstSecAppCreate = null;
	private CFSecXMsgRqstSecAppRead rqstSecAppRead = null;
	private CFSecXMsgRqstSecAppLock rqstSecAppLock = null;
	private CFSecXMsgRqstSecAppUpdate rqstSecAppUpdate = null;
	private CFSecXMsgRqstSecAppDelete rqstSecAppDelete = null;
	private CFSecXMsgRqstSecAppReadAll rqstSecAppReadAll = null;
	private CFSecXMsgRqstSecAppPageAll rqstSecAppPageAll = null;
	private CFSecXMsgRqstSecAppRdByClusterIdx rqstSecAppRdByClusterIdx = null;
	private CFSecXMsgRqstSecAppRdByUJEEMountIdx rqstSecAppRdByUJEEMountIdx = null;
	private CFSecXMsgRqstSecAppPageByClusterIdx rqstSecAppPageByClusterIdx = null;
	private CFSecXMsgRqstSecAppDelByIdIdx rqstSecAppDelByIdIdx = null;
	private CFSecXMsgRqstSecAppDelByClusterIdx rqstSecAppDelByClusterIdx = null;
	private CFSecXMsgRqstSecAppDelByUJEEMountIdx rqstSecAppDelByUJEEMountIdx = null;
	// SecDevice Request s

	private CFSecXMsgRqstSecDeviceCreate rqstSecDeviceCreate = null;
	private CFSecXMsgRqstSecDeviceRead rqstSecDeviceRead = null;
	private CFSecXMsgRqstSecDeviceLock rqstSecDeviceLock = null;
	private CFSecXMsgRqstSecDeviceUpdate rqstSecDeviceUpdate = null;
	private CFSecXMsgRqstSecDeviceDelete rqstSecDeviceDelete = null;
	private CFSecXMsgRqstSecDeviceReadAll rqstSecDeviceReadAll = null;
	private CFSecXMsgRqstSecDevicePageAll rqstSecDevicePageAll = null;
	private CFSecXMsgRqstSecDeviceRdByNameIdx rqstSecDeviceRdByNameIdx = null;
	private CFSecXMsgRqstSecDeviceRdByUserIdx rqstSecDeviceRdByUserIdx = null;
	private CFSecXMsgRqstSecDevicePageByUserIdx rqstSecDevicePageByUserIdx = null;
	private CFSecXMsgRqstSecDeviceDelByIdIdx rqstSecDeviceDelByIdIdx = null;
	private CFSecXMsgRqstSecDeviceDelByNameIdx rqstSecDeviceDelByNameIdx = null;
	private CFSecXMsgRqstSecDeviceDelByUserIdx rqstSecDeviceDelByUserIdx = null;
	// SecForm Request s

	private CFSecXMsgRqstSecFormCreate rqstSecFormCreate = null;
	private CFSecXMsgRqstSecFormRead rqstSecFormRead = null;
	private CFSecXMsgRqstSecFormLock rqstSecFormLock = null;
	private CFSecXMsgRqstSecFormUpdate rqstSecFormUpdate = null;
	private CFSecXMsgRqstSecFormDelete rqstSecFormDelete = null;
	private CFSecXMsgRqstSecFormReadAll rqstSecFormReadAll = null;
	private CFSecXMsgRqstSecFormPageAll rqstSecFormPageAll = null;
	private CFSecXMsgRqstSecFormRdByClusterIdx rqstSecFormRdByClusterIdx = null;
	private CFSecXMsgRqstSecFormRdBySecAppIdx rqstSecFormRdBySecAppIdx = null;
	private CFSecXMsgRqstSecFormRdByUJEEServletIdx rqstSecFormRdByUJEEServletIdx = null;
	private CFSecXMsgRqstSecFormPageByClusterIdx rqstSecFormPageByClusterIdx = null;
	private CFSecXMsgRqstSecFormPageBySecAppIdx rqstSecFormPageBySecAppIdx = null;
	private CFSecXMsgRqstSecFormDelByIdIdx rqstSecFormDelByIdIdx = null;
	private CFSecXMsgRqstSecFormDelByClusterIdx rqstSecFormDelByClusterIdx = null;
	private CFSecXMsgRqstSecFormDelBySecAppIdx rqstSecFormDelBySecAppIdx = null;
	private CFSecXMsgRqstSecFormDelByUJEEServletIdx rqstSecFormDelByUJEEServletIdx = null;
	// SecGroup Request s

	private CFSecXMsgRqstSecGroupCreate rqstSecGroupCreate = null;
	private CFSecXMsgRqstSecGroupRead rqstSecGroupRead = null;
	private CFSecXMsgRqstSecGroupLock rqstSecGroupLock = null;
	private CFSecXMsgRqstSecGroupUpdate rqstSecGroupUpdate = null;
	private CFSecXMsgRqstSecGroupDelete rqstSecGroupDelete = null;
	private CFSecXMsgRqstSecGroupReadAll rqstSecGroupReadAll = null;
	private CFSecXMsgRqstSecGroupRdByClusterIdx rqstSecGroupRdByClusterIdx = null;
	private CFSecXMsgRqstSecGroupRdByClusterVisIdx rqstSecGroupRdByClusterVisIdx = null;
	private CFSecXMsgRqstSecGroupRdByUNameIdx rqstSecGroupRdByUNameIdx = null;
	private CFSecXMsgRqstSecGroupDelByIdIdx rqstSecGroupDelByIdIdx = null;
	private CFSecXMsgRqstSecGroupDelByClusterIdx rqstSecGroupDelByClusterIdx = null;
	private CFSecXMsgRqstSecGroupDelByClusterVisIdx rqstSecGroupDelByClusterVisIdx = null;
	private CFSecXMsgRqstSecGroupDelByUNameIdx rqstSecGroupDelByUNameIdx = null;
	// SecGroupForm Request s

	private CFSecXMsgRqstSecGroupFormCreate rqstSecGroupFormCreate = null;
	private CFSecXMsgRqstSecGroupFormRead rqstSecGroupFormRead = null;
	private CFSecXMsgRqstSecGroupFormLock rqstSecGroupFormLock = null;
	private CFSecXMsgRqstSecGroupFormUpdate rqstSecGroupFormUpdate = null;
	private CFSecXMsgRqstSecGroupFormDelete rqstSecGroupFormDelete = null;
	private CFSecXMsgRqstSecGroupFormReadAll rqstSecGroupFormReadAll = null;
	private CFSecXMsgRqstSecGroupFormPageAll rqstSecGroupFormPageAll = null;
	private CFSecXMsgRqstSecGroupFormRdByClusterIdx rqstSecGroupFormRdByClusterIdx = null;
	private CFSecXMsgRqstSecGroupFormRdByGroupIdx rqstSecGroupFormRdByGroupIdx = null;
	private CFSecXMsgRqstSecGroupFormRdByAppIdx rqstSecGroupFormRdByAppIdx = null;
	private CFSecXMsgRqstSecGroupFormRdByFormIdx rqstSecGroupFormRdByFormIdx = null;
	private CFSecXMsgRqstSecGroupFormRdByUFormIdx rqstSecGroupFormRdByUFormIdx = null;
	private CFSecXMsgRqstSecGroupFormPageByClusterIdx rqstSecGroupFormPageByClusterIdx = null;
	private CFSecXMsgRqstSecGroupFormPageByGroupIdx rqstSecGroupFormPageByGroupIdx = null;
	private CFSecXMsgRqstSecGroupFormPageByAppIdx rqstSecGroupFormPageByAppIdx = null;
	private CFSecXMsgRqstSecGroupFormPageByFormIdx rqstSecGroupFormPageByFormIdx = null;
	private CFSecXMsgRqstSecGroupFormDelByIdIdx rqstSecGroupFormDelByIdIdx = null;
	private CFSecXMsgRqstSecGroupFormDelByClusterIdx rqstSecGroupFormDelByClusterIdx = null;
	private CFSecXMsgRqstSecGroupFormDelByGroupIdx rqstSecGroupFormDelByGroupIdx = null;
	private CFSecXMsgRqstSecGroupFormDelByAppIdx rqstSecGroupFormDelByAppIdx = null;
	private CFSecXMsgRqstSecGroupFormDelByFormIdx rqstSecGroupFormDelByFormIdx = null;
	private CFSecXMsgRqstSecGroupFormDelByUFormIdx rqstSecGroupFormDelByUFormIdx = null;
	// SecGrpInc Request s

	private CFSecXMsgRqstSecGrpIncCreate rqstSecGrpIncCreate = null;
	private CFSecXMsgRqstSecGrpIncRead rqstSecGrpIncRead = null;
	private CFSecXMsgRqstSecGrpIncLock rqstSecGrpIncLock = null;
	private CFSecXMsgRqstSecGrpIncUpdate rqstSecGrpIncUpdate = null;
	private CFSecXMsgRqstSecGrpIncDelete rqstSecGrpIncDelete = null;
	private CFSecXMsgRqstSecGrpIncReadAll rqstSecGrpIncReadAll = null;
	private CFSecXMsgRqstSecGrpIncPageAll rqstSecGrpIncPageAll = null;
	private CFSecXMsgRqstSecGrpIncRdByClusterIdx rqstSecGrpIncRdByClusterIdx = null;
	private CFSecXMsgRqstSecGrpIncRdByGroupIdx rqstSecGrpIncRdByGroupIdx = null;
	private CFSecXMsgRqstSecGrpIncRdByIncludeIdx rqstSecGrpIncRdByIncludeIdx = null;
	private CFSecXMsgRqstSecGrpIncRdByUIncludeIdx rqstSecGrpIncRdByUIncludeIdx = null;
	private CFSecXMsgRqstSecGrpIncPageByClusterIdx rqstSecGrpIncPageByClusterIdx = null;
	private CFSecXMsgRqstSecGrpIncPageByGroupIdx rqstSecGrpIncPageByGroupIdx = null;
	private CFSecXMsgRqstSecGrpIncPageByIncludeIdx rqstSecGrpIncPageByIncludeIdx = null;
	private CFSecXMsgRqstSecGrpIncDelByIdIdx rqstSecGrpIncDelByIdIdx = null;
	private CFSecXMsgRqstSecGrpIncDelByClusterIdx rqstSecGrpIncDelByClusterIdx = null;
	private CFSecXMsgRqstSecGrpIncDelByGroupIdx rqstSecGrpIncDelByGroupIdx = null;
	private CFSecXMsgRqstSecGrpIncDelByIncludeIdx rqstSecGrpIncDelByIncludeIdx = null;
	private CFSecXMsgRqstSecGrpIncDelByUIncludeIdx rqstSecGrpIncDelByUIncludeIdx = null;
	// SecGrpMemb Request s

	private CFSecXMsgRqstSecGrpMembCreate rqstSecGrpMembCreate = null;
	private CFSecXMsgRqstSecGrpMembRead rqstSecGrpMembRead = null;
	private CFSecXMsgRqstSecGrpMembLock rqstSecGrpMembLock = null;
	private CFSecXMsgRqstSecGrpMembUpdate rqstSecGrpMembUpdate = null;
	private CFSecXMsgRqstSecGrpMembDelete rqstSecGrpMembDelete = null;
	private CFSecXMsgRqstSecGrpMembReadAll rqstSecGrpMembReadAll = null;
	private CFSecXMsgRqstSecGrpMembPageAll rqstSecGrpMembPageAll = null;
	private CFSecXMsgRqstSecGrpMembRdByClusterIdx rqstSecGrpMembRdByClusterIdx = null;
	private CFSecXMsgRqstSecGrpMembRdByGroupIdx rqstSecGrpMembRdByGroupIdx = null;
	private CFSecXMsgRqstSecGrpMembRdByUserIdx rqstSecGrpMembRdByUserIdx = null;
	private CFSecXMsgRqstSecGrpMembRdByUUserIdx rqstSecGrpMembRdByUUserIdx = null;
	private CFSecXMsgRqstSecGrpMembPageByClusterIdx rqstSecGrpMembPageByClusterIdx = null;
	private CFSecXMsgRqstSecGrpMembPageByGroupIdx rqstSecGrpMembPageByGroupIdx = null;
	private CFSecXMsgRqstSecGrpMembPageByUserIdx rqstSecGrpMembPageByUserIdx = null;
	private CFSecXMsgRqstSecGrpMembDelByIdIdx rqstSecGrpMembDelByIdIdx = null;
	private CFSecXMsgRqstSecGrpMembDelByClusterIdx rqstSecGrpMembDelByClusterIdx = null;
	private CFSecXMsgRqstSecGrpMembDelByGroupIdx rqstSecGrpMembDelByGroupIdx = null;
	private CFSecXMsgRqstSecGrpMembDelByUserIdx rqstSecGrpMembDelByUserIdx = null;
	private CFSecXMsgRqstSecGrpMembDelByUUserIdx rqstSecGrpMembDelByUUserIdx = null;
	// SecSession Request s

	private CFSecXMsgRqstSecSessionCreate rqstSecSessionCreate = null;
	private CFSecXMsgRqstSecSessionRead rqstSecSessionRead = null;
	private CFSecXMsgRqstSecSessionLock rqstSecSessionLock = null;
	private CFSecXMsgRqstSecSessionUpdate rqstSecSessionUpdate = null;
	private CFSecXMsgRqstSecSessionDelete rqstSecSessionDelete = null;
	private CFSecXMsgRqstSecSessionReadAll rqstSecSessionReadAll = null;
	private CFSecXMsgRqstSecSessionPageAll rqstSecSessionPageAll = null;
	private CFSecXMsgRqstSecSessionRdBySecUserIdx rqstSecSessionRdBySecUserIdx = null;
	private CFSecXMsgRqstSecSessionRdBySecDevIdx rqstSecSessionRdBySecDevIdx = null;
	private CFSecXMsgRqstSecSessionRdByStartIdx rqstSecSessionRdByStartIdx = null;
	private CFSecXMsgRqstSecSessionRdByFinishIdx rqstSecSessionRdByFinishIdx = null;
	private CFSecXMsgRqstSecSessionRdBySecProxyIdx rqstSecSessionRdBySecProxyIdx = null;
	private CFSecXMsgRqstSecSessionPageBySecUserIdx rqstSecSessionPageBySecUserIdx = null;
	private CFSecXMsgRqstSecSessionPageBySecDevIdx rqstSecSessionPageBySecDevIdx = null;
	private CFSecXMsgRqstSecSessionPageByFinishIdx rqstSecSessionPageByFinishIdx = null;
	private CFSecXMsgRqstSecSessionPageBySecProxyIdx rqstSecSessionPageBySecProxyIdx = null;
	private CFSecXMsgRqstSecSessionDelByIdIdx rqstSecSessionDelByIdIdx = null;
	private CFSecXMsgRqstSecSessionDelBySecUserIdx rqstSecSessionDelBySecUserIdx = null;
	private CFSecXMsgRqstSecSessionDelBySecDevIdx rqstSecSessionDelBySecDevIdx = null;
	private CFSecXMsgRqstSecSessionDelByStartIdx rqstSecSessionDelByStartIdx = null;
	private CFSecXMsgRqstSecSessionDelByFinishIdx rqstSecSessionDelByFinishIdx = null;
	private CFSecXMsgRqstSecSessionDelBySecProxyIdx rqstSecSessionDelBySecProxyIdx = null;
	// SecUser Request s

	private CFSecXMsgRqstSecUserCreate rqstSecUserCreate = null;
	private CFSecXMsgRqstSecUserRead rqstSecUserRead = null;
	private CFSecXMsgRqstSecUserLock rqstSecUserLock = null;
	private CFSecXMsgRqstSecUserUpdate rqstSecUserUpdate = null;
	private CFSecXMsgRqstSecUserDelete rqstSecUserDelete = null;
	private CFSecXMsgRqstSecUserReadAll rqstSecUserReadAll = null;
	private CFSecXMsgRqstSecUserPageAll rqstSecUserPageAll = null;
	private CFSecXMsgRqstSecUserRdByULoginIdx rqstSecUserRdByULoginIdx = null;
	private CFSecXMsgRqstSecUserRdByEMConfIdx rqstSecUserRdByEMConfIdx = null;
	private CFSecXMsgRqstSecUserRdByPwdResetIdx rqstSecUserRdByPwdResetIdx = null;
	private CFSecXMsgRqstSecUserRdByDefDevIdx rqstSecUserRdByDefDevIdx = null;
	private CFSecXMsgRqstSecUserPageByEMConfIdx rqstSecUserPageByEMConfIdx = null;
	private CFSecXMsgRqstSecUserPageByPwdResetIdx rqstSecUserPageByPwdResetIdx = null;
	private CFSecXMsgRqstSecUserPageByDefDevIdx rqstSecUserPageByDefDevIdx = null;
	private CFSecXMsgRqstSecUserDelByIdIdx rqstSecUserDelByIdIdx = null;
	private CFSecXMsgRqstSecUserDelByULoginIdx rqstSecUserDelByULoginIdx = null;
	private CFSecXMsgRqstSecUserDelByEMConfIdx rqstSecUserDelByEMConfIdx = null;
	private CFSecXMsgRqstSecUserDelByPwdResetIdx rqstSecUserDelByPwdResetIdx = null;
	private CFSecXMsgRqstSecUserDelByDefDevIdx rqstSecUserDelByDefDevIdx = null;
	// Service Request s

	private CFSecXMsgRqstServiceCreate rqstServiceCreate = null;
	private CFSecXMsgRqstServiceRead rqstServiceRead = null;
	private CFSecXMsgRqstServiceLock rqstServiceLock = null;
	private CFSecXMsgRqstServiceUpdate rqstServiceUpdate = null;
	private CFSecXMsgRqstServiceDelete rqstServiceDelete = null;
	private CFSecXMsgRqstServiceReadAll rqstServiceReadAll = null;
	private CFSecXMsgRqstServicePageAll rqstServicePageAll = null;
	private CFSecXMsgRqstServiceRdByClusterIdx rqstServiceRdByClusterIdx = null;
	private CFSecXMsgRqstServiceRdByHostIdx rqstServiceRdByHostIdx = null;
	private CFSecXMsgRqstServiceRdByTypeIdx rqstServiceRdByTypeIdx = null;
	private CFSecXMsgRqstServiceRdByUTypeIdx rqstServiceRdByUTypeIdx = null;
	private CFSecXMsgRqstServiceRdByUHostPortIdx rqstServiceRdByUHostPortIdx = null;
	private CFSecXMsgRqstServicePageByClusterIdx rqstServicePageByClusterIdx = null;
	private CFSecXMsgRqstServicePageByHostIdx rqstServicePageByHostIdx = null;
	private CFSecXMsgRqstServicePageByTypeIdx rqstServicePageByTypeIdx = null;
	private CFSecXMsgRqstServiceDelByIdIdx rqstServiceDelByIdIdx = null;
	private CFSecXMsgRqstServiceDelByClusterIdx rqstServiceDelByClusterIdx = null;
	private CFSecXMsgRqstServiceDelByHostIdx rqstServiceDelByHostIdx = null;
	private CFSecXMsgRqstServiceDelByTypeIdx rqstServiceDelByTypeIdx = null;
	private CFSecXMsgRqstServiceDelByUTypeIdx rqstServiceDelByUTypeIdx = null;
	private CFSecXMsgRqstServiceDelByUHostPortIdx rqstServiceDelByUHostPortIdx = null;
	// ServiceType Request s

	private CFSecXMsgRqstServiceTypeCreate rqstServiceTypeCreate = null;
	private CFSecXMsgRqstServiceTypeRead rqstServiceTypeRead = null;
	private CFSecXMsgRqstServiceTypeLock rqstServiceTypeLock = null;
	private CFSecXMsgRqstServiceTypeUpdate rqstServiceTypeUpdate = null;
	private CFSecXMsgRqstServiceTypeDelete rqstServiceTypeDelete = null;
	private CFSecXMsgRqstServiceTypeReadAll rqstServiceTypeReadAll = null;
	private CFSecXMsgRqstServiceTypeRdByUDescrIdx rqstServiceTypeRdByUDescrIdx = null;
	private CFSecXMsgRqstServiceTypeDelByIdIdx rqstServiceTypeDelByIdIdx = null;
	private CFSecXMsgRqstServiceTypeDelByUDescrIdx rqstServiceTypeDelByUDescrIdx = null;
	// SysCluster Request s

	private CFSecXMsgRqstSysClusterCreate rqstSysClusterCreate = null;
	private CFSecXMsgRqstSysClusterRead rqstSysClusterRead = null;
	private CFSecXMsgRqstSysClusterLock rqstSysClusterLock = null;
	private CFSecXMsgRqstSysClusterUpdate rqstSysClusterUpdate = null;
	private CFSecXMsgRqstSysClusterDelete rqstSysClusterDelete = null;
	private CFSecXMsgRqstSysClusterReadAll rqstSysClusterReadAll = null;
	private CFSecXMsgRqstSysClusterRdByClusterIdx rqstSysClusterRdByClusterIdx = null;
	private CFSecXMsgRqstSysClusterDelByIdIdx rqstSysClusterDelByIdIdx = null;
	private CFSecXMsgRqstSysClusterDelByClusterIdx rqstSysClusterDelByClusterIdx = null;
	// TSecGroup Request s

	private CFSecXMsgRqstTSecGroupCreate rqstTSecGroupCreate = null;
	private CFSecXMsgRqstTSecGroupRead rqstTSecGroupRead = null;
	private CFSecXMsgRqstTSecGroupLock rqstTSecGroupLock = null;
	private CFSecXMsgRqstTSecGroupUpdate rqstTSecGroupUpdate = null;
	private CFSecXMsgRqstTSecGroupDelete rqstTSecGroupDelete = null;
	private CFSecXMsgRqstTSecGroupReadAll rqstTSecGroupReadAll = null;
	private CFSecXMsgRqstTSecGroupRdByTenantIdx rqstTSecGroupRdByTenantIdx = null;
	private CFSecXMsgRqstTSecGroupRdByTenantVisIdx rqstTSecGroupRdByTenantVisIdx = null;
	private CFSecXMsgRqstTSecGroupRdByUNameIdx rqstTSecGroupRdByUNameIdx = null;
	private CFSecXMsgRqstTSecGroupDelByIdIdx rqstTSecGroupDelByIdIdx = null;
	private CFSecXMsgRqstTSecGroupDelByTenantIdx rqstTSecGroupDelByTenantIdx = null;
	private CFSecXMsgRqstTSecGroupDelByTenantVisIdx rqstTSecGroupDelByTenantVisIdx = null;
	private CFSecXMsgRqstTSecGroupDelByUNameIdx rqstTSecGroupDelByUNameIdx = null;
	// TSecGrpInc Request s

	private CFSecXMsgRqstTSecGrpIncCreate rqstTSecGrpIncCreate = null;
	private CFSecXMsgRqstTSecGrpIncRead rqstTSecGrpIncRead = null;
	private CFSecXMsgRqstTSecGrpIncLock rqstTSecGrpIncLock = null;
	private CFSecXMsgRqstTSecGrpIncUpdate rqstTSecGrpIncUpdate = null;
	private CFSecXMsgRqstTSecGrpIncDelete rqstTSecGrpIncDelete = null;
	private CFSecXMsgRqstTSecGrpIncReadAll rqstTSecGrpIncReadAll = null;
	private CFSecXMsgRqstTSecGrpIncPageAll rqstTSecGrpIncPageAll = null;
	private CFSecXMsgRqstTSecGrpIncRdByTenantIdx rqstTSecGrpIncRdByTenantIdx = null;
	private CFSecXMsgRqstTSecGrpIncRdByGroupIdx rqstTSecGrpIncRdByGroupIdx = null;
	private CFSecXMsgRqstTSecGrpIncRdByIncludeIdx rqstTSecGrpIncRdByIncludeIdx = null;
	private CFSecXMsgRqstTSecGrpIncRdByUIncludeIdx rqstTSecGrpIncRdByUIncludeIdx = null;
	private CFSecXMsgRqstTSecGrpIncPageByTenantIdx rqstTSecGrpIncPageByTenantIdx = null;
	private CFSecXMsgRqstTSecGrpIncPageByGroupIdx rqstTSecGrpIncPageByGroupIdx = null;
	private CFSecXMsgRqstTSecGrpIncPageByIncludeIdx rqstTSecGrpIncPageByIncludeIdx = null;
	private CFSecXMsgRqstTSecGrpIncDelByIdIdx rqstTSecGrpIncDelByIdIdx = null;
	private CFSecXMsgRqstTSecGrpIncDelByTenantIdx rqstTSecGrpIncDelByTenantIdx = null;
	private CFSecXMsgRqstTSecGrpIncDelByGroupIdx rqstTSecGrpIncDelByGroupIdx = null;
	private CFSecXMsgRqstTSecGrpIncDelByIncludeIdx rqstTSecGrpIncDelByIncludeIdx = null;
	private CFSecXMsgRqstTSecGrpIncDelByUIncludeIdx rqstTSecGrpIncDelByUIncludeIdx = null;
	// TSecGrpMemb Request s

	private CFSecXMsgRqstTSecGrpMembCreate rqstTSecGrpMembCreate = null;
	private CFSecXMsgRqstTSecGrpMembRead rqstTSecGrpMembRead = null;
	private CFSecXMsgRqstTSecGrpMembLock rqstTSecGrpMembLock = null;
	private CFSecXMsgRqstTSecGrpMembUpdate rqstTSecGrpMembUpdate = null;
	private CFSecXMsgRqstTSecGrpMembDelete rqstTSecGrpMembDelete = null;
	private CFSecXMsgRqstTSecGrpMembReadAll rqstTSecGrpMembReadAll = null;
	private CFSecXMsgRqstTSecGrpMembPageAll rqstTSecGrpMembPageAll = null;
	private CFSecXMsgRqstTSecGrpMembRdByTenantIdx rqstTSecGrpMembRdByTenantIdx = null;
	private CFSecXMsgRqstTSecGrpMembRdByGroupIdx rqstTSecGrpMembRdByGroupIdx = null;
	private CFSecXMsgRqstTSecGrpMembRdByUserIdx rqstTSecGrpMembRdByUserIdx = null;
	private CFSecXMsgRqstTSecGrpMembRdByUUserIdx rqstTSecGrpMembRdByUUserIdx = null;
	private CFSecXMsgRqstTSecGrpMembPageByTenantIdx rqstTSecGrpMembPageByTenantIdx = null;
	private CFSecXMsgRqstTSecGrpMembPageByGroupIdx rqstTSecGrpMembPageByGroupIdx = null;
	private CFSecXMsgRqstTSecGrpMembPageByUserIdx rqstTSecGrpMembPageByUserIdx = null;
	private CFSecXMsgRqstTSecGrpMembDelByIdIdx rqstTSecGrpMembDelByIdIdx = null;
	private CFSecXMsgRqstTSecGrpMembDelByTenantIdx rqstTSecGrpMembDelByTenantIdx = null;
	private CFSecXMsgRqstTSecGrpMembDelByGroupIdx rqstTSecGrpMembDelByGroupIdx = null;
	private CFSecXMsgRqstTSecGrpMembDelByUserIdx rqstTSecGrpMembDelByUserIdx = null;
	private CFSecXMsgRqstTSecGrpMembDelByUUserIdx rqstTSecGrpMembDelByUUserIdx = null;
	// Tenant Request s

	private CFSecXMsgRqstTenantCreate rqstTenantCreate = null;
	private CFSecXMsgRqstTenantRead rqstTenantRead = null;
	private CFSecXMsgRqstTenantLock rqstTenantLock = null;
	private CFSecXMsgRqstTenantUpdate rqstTenantUpdate = null;
	private CFSecXMsgRqstTenantDelete rqstTenantDelete = null;
	private CFSecXMsgRqstTenantReadAll rqstTenantReadAll = null;
	private CFSecXMsgRqstTenantPageAll rqstTenantPageAll = null;
	private CFSecXMsgRqstTenantRdByClusterIdx rqstTenantRdByClusterIdx = null;
	private CFSecXMsgRqstTenantRdByUNameIdx rqstTenantRdByUNameIdx = null;
	private CFSecXMsgRqstTenantPageByClusterIdx rqstTenantPageByClusterIdx = null;
	private CFSecXMsgRqstTenantDelByIdIdx rqstTenantDelByIdIdx = null;
	private CFSecXMsgRqstTenantDelByClusterIdx rqstTenantDelByClusterIdx = null;
	private CFSecXMsgRqstTenantDelByUNameIdx rqstTenantDelByUNameIdx = null;
	private CFSecSaxRqstRoot saxRoot = null;

	private CFSecSaxRqstDoc saxDoc = null;

	private CFSecXMsgRqstFileImport rqstFileImport = null;
	private CFSecXMsgRqstLogIn rqstLogIn = null;
	private CFSecXMsgRqstLogOut rqstLogOut = null;
	// Schema object accessors

	// SchemaObj accessors

	public ICFSecSchemaObj getSchemaObj() {
		return( schemaObj );
	}

	public void setSchemaObj( ICFSecSchemaObj value ) {
		schemaObj = value;
	}

	// Element  Resolver Factories

	// Cluster Request  Factories

	protected CFSecXMsgRqstClusterCreate getRqstClusterCreate() {
		if( rqstClusterCreate == null ) {
			rqstClusterCreate = new CFSecXMsgRqstClusterCreate( this );
		}
		return( rqstClusterCreate );
	}

	protected CFSecXMsgRqstClusterRead getRqstClusterRead() {
		if( rqstClusterRead == null ) {
			rqstClusterRead = new CFSecXMsgRqstClusterRead( this );
		}
		return( rqstClusterRead );
	}

	protected CFSecXMsgRqstClusterLock getRqstClusterLock() {
		if( rqstClusterLock == null ) {
			rqstClusterLock = new CFSecXMsgRqstClusterLock( this );
		}
		return( rqstClusterLock );
	}

	protected CFSecXMsgRqstClusterUpdate getRqstClusterUpdate() {
		if( rqstClusterUpdate == null ) {
			rqstClusterUpdate = new CFSecXMsgRqstClusterUpdate( this );
		}
		return( rqstClusterUpdate );
	}

	protected CFSecXMsgRqstClusterDelete getRqstClusterDelete() {
		if( rqstClusterDelete == null ) {
			rqstClusterDelete = new CFSecXMsgRqstClusterDelete( this );
		}
		return( rqstClusterDelete );
	}

	protected CFSecXMsgRqstClusterReadAll getRqstClusterReadAll() {
		if( rqstClusterReadAll == null ) {
			rqstClusterReadAll = new CFSecXMsgRqstClusterReadAll( this );
		}
		return( rqstClusterReadAll );
	}

	protected CFSecXMsgRqstClusterPageAll getRqstClusterPageAll() {
		if( rqstClusterPageAll == null ) {
			rqstClusterPageAll = new CFSecXMsgRqstClusterPageAll( this );
		}
		return( rqstClusterPageAll );
	}

	protected CFSecXMsgRqstClusterRdByUDomNameIdx getRqstClusterRdByUDomNameIdx() {
		if( rqstClusterRdByUDomNameIdx == null ) {
			rqstClusterRdByUDomNameIdx = new CFSecXMsgRqstClusterRdByUDomNameIdx( this );
		}
		return( rqstClusterRdByUDomNameIdx );
	}

	protected CFSecXMsgRqstClusterRdByUDescrIdx getRqstClusterRdByUDescrIdx() {
		if( rqstClusterRdByUDescrIdx == null ) {
			rqstClusterRdByUDescrIdx = new CFSecXMsgRqstClusterRdByUDescrIdx( this );
		}
		return( rqstClusterRdByUDescrIdx );
	}

	protected CFSecXMsgRqstClusterDelByUDomNameIdx getRqstClusterDelByUDomNameIdx() {
		if( rqstClusterDelByUDomNameIdx == null ) {
			rqstClusterDelByUDomNameIdx = new CFSecXMsgRqstClusterDelByUDomNameIdx( this );
		}
		return( rqstClusterDelByUDomNameIdx );
	}

	protected CFSecXMsgRqstClusterDelByUDescrIdx getRqstClusterDelByUDescrIdx() {
		if( rqstClusterDelByUDescrIdx == null ) {
			rqstClusterDelByUDescrIdx = new CFSecXMsgRqstClusterDelByUDescrIdx( this );
		}
		return( rqstClusterDelByUDescrIdx );
	}

	// HostNode Request  Factories

	protected CFSecXMsgRqstHostNodeCreate getRqstHostNodeCreate() {
		if( rqstHostNodeCreate == null ) {
			rqstHostNodeCreate = new CFSecXMsgRqstHostNodeCreate( this );
		}
		return( rqstHostNodeCreate );
	}

	protected CFSecXMsgRqstHostNodeRead getRqstHostNodeRead() {
		if( rqstHostNodeRead == null ) {
			rqstHostNodeRead = new CFSecXMsgRqstHostNodeRead( this );
		}
		return( rqstHostNodeRead );
	}

	protected CFSecXMsgRqstHostNodeLock getRqstHostNodeLock() {
		if( rqstHostNodeLock == null ) {
			rqstHostNodeLock = new CFSecXMsgRqstHostNodeLock( this );
		}
		return( rqstHostNodeLock );
	}

	protected CFSecXMsgRqstHostNodeUpdate getRqstHostNodeUpdate() {
		if( rqstHostNodeUpdate == null ) {
			rqstHostNodeUpdate = new CFSecXMsgRqstHostNodeUpdate( this );
		}
		return( rqstHostNodeUpdate );
	}

	protected CFSecXMsgRqstHostNodeDelete getRqstHostNodeDelete() {
		if( rqstHostNodeDelete == null ) {
			rqstHostNodeDelete = new CFSecXMsgRqstHostNodeDelete( this );
		}
		return( rqstHostNodeDelete );
	}

	protected CFSecXMsgRqstHostNodeReadAll getRqstHostNodeReadAll() {
		if( rqstHostNodeReadAll == null ) {
			rqstHostNodeReadAll = new CFSecXMsgRqstHostNodeReadAll( this );
		}
		return( rqstHostNodeReadAll );
	}

	protected CFSecXMsgRqstHostNodePageAll getRqstHostNodePageAll() {
		if( rqstHostNodePageAll == null ) {
			rqstHostNodePageAll = new CFSecXMsgRqstHostNodePageAll( this );
		}
		return( rqstHostNodePageAll );
	}

	protected CFSecXMsgRqstHostNodeRdByClusterIdx getRqstHostNodeRdByClusterIdx() {
		if( rqstHostNodeRdByClusterIdx == null ) {
			rqstHostNodeRdByClusterIdx = new CFSecXMsgRqstHostNodeRdByClusterIdx( this );
		}
		return( rqstHostNodeRdByClusterIdx );
	}

	protected CFSecXMsgRqstHostNodeRdByUDescrIdx getRqstHostNodeRdByUDescrIdx() {
		if( rqstHostNodeRdByUDescrIdx == null ) {
			rqstHostNodeRdByUDescrIdx = new CFSecXMsgRqstHostNodeRdByUDescrIdx( this );
		}
		return( rqstHostNodeRdByUDescrIdx );
	}

	protected CFSecXMsgRqstHostNodeRdByHostNameIdx getRqstHostNodeRdByHostNameIdx() {
		if( rqstHostNodeRdByHostNameIdx == null ) {
			rqstHostNodeRdByHostNameIdx = new CFSecXMsgRqstHostNodeRdByHostNameIdx( this );
		}
		return( rqstHostNodeRdByHostNameIdx );
	}

	protected CFSecXMsgRqstHostNodePageByClusterIdx getRqstHostNodePageByClusterIdx() {
		if( rqstHostNodePageByClusterIdx == null ) {
			rqstHostNodePageByClusterIdx = new CFSecXMsgRqstHostNodePageByClusterIdx( this );
		}
		return( rqstHostNodePageByClusterIdx );
	}

	protected CFSecXMsgRqstHostNodeDelByClusterIdx getRqstHostNodeDelByClusterIdx() {
		if( rqstHostNodeDelByClusterIdx == null ) {
			rqstHostNodeDelByClusterIdx = new CFSecXMsgRqstHostNodeDelByClusterIdx( this );
		}
		return( rqstHostNodeDelByClusterIdx );
	}

	protected CFSecXMsgRqstHostNodeDelByUDescrIdx getRqstHostNodeDelByUDescrIdx() {
		if( rqstHostNodeDelByUDescrIdx == null ) {
			rqstHostNodeDelByUDescrIdx = new CFSecXMsgRqstHostNodeDelByUDescrIdx( this );
		}
		return( rqstHostNodeDelByUDescrIdx );
	}

	protected CFSecXMsgRqstHostNodeDelByHostNameIdx getRqstHostNodeDelByHostNameIdx() {
		if( rqstHostNodeDelByHostNameIdx == null ) {
			rqstHostNodeDelByHostNameIdx = new CFSecXMsgRqstHostNodeDelByHostNameIdx( this );
		}
		return( rqstHostNodeDelByHostNameIdx );
	}

	// ISOCcy Request  Factories

	protected CFSecXMsgRqstISOCcyCreate getRqstISOCcyCreate() {
		if( rqstISOCcyCreate == null ) {
			rqstISOCcyCreate = new CFSecXMsgRqstISOCcyCreate( this );
		}
		return( rqstISOCcyCreate );
	}

	protected CFSecXMsgRqstISOCcyRead getRqstISOCcyRead() {
		if( rqstISOCcyRead == null ) {
			rqstISOCcyRead = new CFSecXMsgRqstISOCcyRead( this );
		}
		return( rqstISOCcyRead );
	}

	protected CFSecXMsgRqstISOCcyLock getRqstISOCcyLock() {
		if( rqstISOCcyLock == null ) {
			rqstISOCcyLock = new CFSecXMsgRqstISOCcyLock( this );
		}
		return( rqstISOCcyLock );
	}

	protected CFSecXMsgRqstISOCcyUpdate getRqstISOCcyUpdate() {
		if( rqstISOCcyUpdate == null ) {
			rqstISOCcyUpdate = new CFSecXMsgRqstISOCcyUpdate( this );
		}
		return( rqstISOCcyUpdate );
	}

	protected CFSecXMsgRqstISOCcyDelete getRqstISOCcyDelete() {
		if( rqstISOCcyDelete == null ) {
			rqstISOCcyDelete = new CFSecXMsgRqstISOCcyDelete( this );
		}
		return( rqstISOCcyDelete );
	}

	protected CFSecXMsgRqstISOCcyReadAll getRqstISOCcyReadAll() {
		if( rqstISOCcyReadAll == null ) {
			rqstISOCcyReadAll = new CFSecXMsgRqstISOCcyReadAll( this );
		}
		return( rqstISOCcyReadAll );
	}

	protected CFSecXMsgRqstISOCcyRdByCcyCdIdx getRqstISOCcyRdByCcyCdIdx() {
		if( rqstISOCcyRdByCcyCdIdx == null ) {
			rqstISOCcyRdByCcyCdIdx = new CFSecXMsgRqstISOCcyRdByCcyCdIdx( this );
		}
		return( rqstISOCcyRdByCcyCdIdx );
	}

	protected CFSecXMsgRqstISOCcyRdByCcyNmIdx getRqstISOCcyRdByCcyNmIdx() {
		if( rqstISOCcyRdByCcyNmIdx == null ) {
			rqstISOCcyRdByCcyNmIdx = new CFSecXMsgRqstISOCcyRdByCcyNmIdx( this );
		}
		return( rqstISOCcyRdByCcyNmIdx );
	}

	protected CFSecXMsgRqstISOCcyDelByCcyCdIdx getRqstISOCcyDelByCcyCdIdx() {
		if( rqstISOCcyDelByCcyCdIdx == null ) {
			rqstISOCcyDelByCcyCdIdx = new CFSecXMsgRqstISOCcyDelByCcyCdIdx( this );
		}
		return( rqstISOCcyDelByCcyCdIdx );
	}

	protected CFSecXMsgRqstISOCcyDelByCcyNmIdx getRqstISOCcyDelByCcyNmIdx() {
		if( rqstISOCcyDelByCcyNmIdx == null ) {
			rqstISOCcyDelByCcyNmIdx = new CFSecXMsgRqstISOCcyDelByCcyNmIdx( this );
		}
		return( rqstISOCcyDelByCcyNmIdx );
	}

	// ISOCtry Request  Factories

	protected CFSecXMsgRqstISOCtryCreate getRqstISOCtryCreate() {
		if( rqstISOCtryCreate == null ) {
			rqstISOCtryCreate = new CFSecXMsgRqstISOCtryCreate( this );
		}
		return( rqstISOCtryCreate );
	}

	protected CFSecXMsgRqstISOCtryRead getRqstISOCtryRead() {
		if( rqstISOCtryRead == null ) {
			rqstISOCtryRead = new CFSecXMsgRqstISOCtryRead( this );
		}
		return( rqstISOCtryRead );
	}

	protected CFSecXMsgRqstISOCtryLock getRqstISOCtryLock() {
		if( rqstISOCtryLock == null ) {
			rqstISOCtryLock = new CFSecXMsgRqstISOCtryLock( this );
		}
		return( rqstISOCtryLock );
	}

	protected CFSecXMsgRqstISOCtryUpdate getRqstISOCtryUpdate() {
		if( rqstISOCtryUpdate == null ) {
			rqstISOCtryUpdate = new CFSecXMsgRqstISOCtryUpdate( this );
		}
		return( rqstISOCtryUpdate );
	}

	protected CFSecXMsgRqstISOCtryDelete getRqstISOCtryDelete() {
		if( rqstISOCtryDelete == null ) {
			rqstISOCtryDelete = new CFSecXMsgRqstISOCtryDelete( this );
		}
		return( rqstISOCtryDelete );
	}

	protected CFSecXMsgRqstISOCtryReadAll getRqstISOCtryReadAll() {
		if( rqstISOCtryReadAll == null ) {
			rqstISOCtryReadAll = new CFSecXMsgRqstISOCtryReadAll( this );
		}
		return( rqstISOCtryReadAll );
	}

	protected CFSecXMsgRqstISOCtryRdByISOCodeIdx getRqstISOCtryRdByISOCodeIdx() {
		if( rqstISOCtryRdByISOCodeIdx == null ) {
			rqstISOCtryRdByISOCodeIdx = new CFSecXMsgRqstISOCtryRdByISOCodeIdx( this );
		}
		return( rqstISOCtryRdByISOCodeIdx );
	}

	protected CFSecXMsgRqstISOCtryRdByNameIdx getRqstISOCtryRdByNameIdx() {
		if( rqstISOCtryRdByNameIdx == null ) {
			rqstISOCtryRdByNameIdx = new CFSecXMsgRqstISOCtryRdByNameIdx( this );
		}
		return( rqstISOCtryRdByNameIdx );
	}

	protected CFSecXMsgRqstISOCtryDelByISOCodeIdx getRqstISOCtryDelByISOCodeIdx() {
		if( rqstISOCtryDelByISOCodeIdx == null ) {
			rqstISOCtryDelByISOCodeIdx = new CFSecXMsgRqstISOCtryDelByISOCodeIdx( this );
		}
		return( rqstISOCtryDelByISOCodeIdx );
	}

	protected CFSecXMsgRqstISOCtryDelByNameIdx getRqstISOCtryDelByNameIdx() {
		if( rqstISOCtryDelByNameIdx == null ) {
			rqstISOCtryDelByNameIdx = new CFSecXMsgRqstISOCtryDelByNameIdx( this );
		}
		return( rqstISOCtryDelByNameIdx );
	}

	// ISOCtryCcy Request  Factories

	protected CFSecXMsgRqstISOCtryCcyCreate getRqstISOCtryCcyCreate() {
		if( rqstISOCtryCcyCreate == null ) {
			rqstISOCtryCcyCreate = new CFSecXMsgRqstISOCtryCcyCreate( this );
		}
		return( rqstISOCtryCcyCreate );
	}

	protected CFSecXMsgRqstISOCtryCcyRead getRqstISOCtryCcyRead() {
		if( rqstISOCtryCcyRead == null ) {
			rqstISOCtryCcyRead = new CFSecXMsgRqstISOCtryCcyRead( this );
		}
		return( rqstISOCtryCcyRead );
	}

	protected CFSecXMsgRqstISOCtryCcyLock getRqstISOCtryCcyLock() {
		if( rqstISOCtryCcyLock == null ) {
			rqstISOCtryCcyLock = new CFSecXMsgRqstISOCtryCcyLock( this );
		}
		return( rqstISOCtryCcyLock );
	}

	protected CFSecXMsgRqstISOCtryCcyUpdate getRqstISOCtryCcyUpdate() {
		if( rqstISOCtryCcyUpdate == null ) {
			rqstISOCtryCcyUpdate = new CFSecXMsgRqstISOCtryCcyUpdate( this );
		}
		return( rqstISOCtryCcyUpdate );
	}

	protected CFSecXMsgRqstISOCtryCcyDelete getRqstISOCtryCcyDelete() {
		if( rqstISOCtryCcyDelete == null ) {
			rqstISOCtryCcyDelete = new CFSecXMsgRqstISOCtryCcyDelete( this );
		}
		return( rqstISOCtryCcyDelete );
	}

	protected CFSecXMsgRqstISOCtryCcyReadAll getRqstISOCtryCcyReadAll() {
		if( rqstISOCtryCcyReadAll == null ) {
			rqstISOCtryCcyReadAll = new CFSecXMsgRqstISOCtryCcyReadAll( this );
		}
		return( rqstISOCtryCcyReadAll );
	}

	protected CFSecXMsgRqstISOCtryCcyRdByCtryIdx getRqstISOCtryCcyRdByCtryIdx() {
		if( rqstISOCtryCcyRdByCtryIdx == null ) {
			rqstISOCtryCcyRdByCtryIdx = new CFSecXMsgRqstISOCtryCcyRdByCtryIdx( this );
		}
		return( rqstISOCtryCcyRdByCtryIdx );
	}

	protected CFSecXMsgRqstISOCtryCcyRdByCcyIdx getRqstISOCtryCcyRdByCcyIdx() {
		if( rqstISOCtryCcyRdByCcyIdx == null ) {
			rqstISOCtryCcyRdByCcyIdx = new CFSecXMsgRqstISOCtryCcyRdByCcyIdx( this );
		}
		return( rqstISOCtryCcyRdByCcyIdx );
	}

	protected CFSecXMsgRqstISOCtryCcyDelByCtryIdx getRqstISOCtryCcyDelByCtryIdx() {
		if( rqstISOCtryCcyDelByCtryIdx == null ) {
			rqstISOCtryCcyDelByCtryIdx = new CFSecXMsgRqstISOCtryCcyDelByCtryIdx( this );
		}
		return( rqstISOCtryCcyDelByCtryIdx );
	}

	protected CFSecXMsgRqstISOCtryCcyDelByCcyIdx getRqstISOCtryCcyDelByCcyIdx() {
		if( rqstISOCtryCcyDelByCcyIdx == null ) {
			rqstISOCtryCcyDelByCcyIdx = new CFSecXMsgRqstISOCtryCcyDelByCcyIdx( this );
		}
		return( rqstISOCtryCcyDelByCcyIdx );
	}

	// ISOCtryLang Request  Factories

	protected CFSecXMsgRqstISOCtryLangCreate getRqstISOCtryLangCreate() {
		if( rqstISOCtryLangCreate == null ) {
			rqstISOCtryLangCreate = new CFSecXMsgRqstISOCtryLangCreate( this );
		}
		return( rqstISOCtryLangCreate );
	}

	protected CFSecXMsgRqstISOCtryLangRead getRqstISOCtryLangRead() {
		if( rqstISOCtryLangRead == null ) {
			rqstISOCtryLangRead = new CFSecXMsgRqstISOCtryLangRead( this );
		}
		return( rqstISOCtryLangRead );
	}

	protected CFSecXMsgRqstISOCtryLangLock getRqstISOCtryLangLock() {
		if( rqstISOCtryLangLock == null ) {
			rqstISOCtryLangLock = new CFSecXMsgRqstISOCtryLangLock( this );
		}
		return( rqstISOCtryLangLock );
	}

	protected CFSecXMsgRqstISOCtryLangUpdate getRqstISOCtryLangUpdate() {
		if( rqstISOCtryLangUpdate == null ) {
			rqstISOCtryLangUpdate = new CFSecXMsgRqstISOCtryLangUpdate( this );
		}
		return( rqstISOCtryLangUpdate );
	}

	protected CFSecXMsgRqstISOCtryLangDelete getRqstISOCtryLangDelete() {
		if( rqstISOCtryLangDelete == null ) {
			rqstISOCtryLangDelete = new CFSecXMsgRqstISOCtryLangDelete( this );
		}
		return( rqstISOCtryLangDelete );
	}

	protected CFSecXMsgRqstISOCtryLangReadAll getRqstISOCtryLangReadAll() {
		if( rqstISOCtryLangReadAll == null ) {
			rqstISOCtryLangReadAll = new CFSecXMsgRqstISOCtryLangReadAll( this );
		}
		return( rqstISOCtryLangReadAll );
	}

	protected CFSecXMsgRqstISOCtryLangRdByCtryIdx getRqstISOCtryLangRdByCtryIdx() {
		if( rqstISOCtryLangRdByCtryIdx == null ) {
			rqstISOCtryLangRdByCtryIdx = new CFSecXMsgRqstISOCtryLangRdByCtryIdx( this );
		}
		return( rqstISOCtryLangRdByCtryIdx );
	}

	protected CFSecXMsgRqstISOCtryLangRdByLangIdx getRqstISOCtryLangRdByLangIdx() {
		if( rqstISOCtryLangRdByLangIdx == null ) {
			rqstISOCtryLangRdByLangIdx = new CFSecXMsgRqstISOCtryLangRdByLangIdx( this );
		}
		return( rqstISOCtryLangRdByLangIdx );
	}

	protected CFSecXMsgRqstISOCtryLangDelByCtryIdx getRqstISOCtryLangDelByCtryIdx() {
		if( rqstISOCtryLangDelByCtryIdx == null ) {
			rqstISOCtryLangDelByCtryIdx = new CFSecXMsgRqstISOCtryLangDelByCtryIdx( this );
		}
		return( rqstISOCtryLangDelByCtryIdx );
	}

	protected CFSecXMsgRqstISOCtryLangDelByLangIdx getRqstISOCtryLangDelByLangIdx() {
		if( rqstISOCtryLangDelByLangIdx == null ) {
			rqstISOCtryLangDelByLangIdx = new CFSecXMsgRqstISOCtryLangDelByLangIdx( this );
		}
		return( rqstISOCtryLangDelByLangIdx );
	}

	// ISOLang Request  Factories

	protected CFSecXMsgRqstISOLangCreate getRqstISOLangCreate() {
		if( rqstISOLangCreate == null ) {
			rqstISOLangCreate = new CFSecXMsgRqstISOLangCreate( this );
		}
		return( rqstISOLangCreate );
	}

	protected CFSecXMsgRqstISOLangRead getRqstISOLangRead() {
		if( rqstISOLangRead == null ) {
			rqstISOLangRead = new CFSecXMsgRqstISOLangRead( this );
		}
		return( rqstISOLangRead );
	}

	protected CFSecXMsgRqstISOLangLock getRqstISOLangLock() {
		if( rqstISOLangLock == null ) {
			rqstISOLangLock = new CFSecXMsgRqstISOLangLock( this );
		}
		return( rqstISOLangLock );
	}

	protected CFSecXMsgRqstISOLangUpdate getRqstISOLangUpdate() {
		if( rqstISOLangUpdate == null ) {
			rqstISOLangUpdate = new CFSecXMsgRqstISOLangUpdate( this );
		}
		return( rqstISOLangUpdate );
	}

	protected CFSecXMsgRqstISOLangDelete getRqstISOLangDelete() {
		if( rqstISOLangDelete == null ) {
			rqstISOLangDelete = new CFSecXMsgRqstISOLangDelete( this );
		}
		return( rqstISOLangDelete );
	}

	protected CFSecXMsgRqstISOLangReadAll getRqstISOLangReadAll() {
		if( rqstISOLangReadAll == null ) {
			rqstISOLangReadAll = new CFSecXMsgRqstISOLangReadAll( this );
		}
		return( rqstISOLangReadAll );
	}

	protected CFSecXMsgRqstISOLangRdByCode3Idx getRqstISOLangRdByCode3Idx() {
		if( rqstISOLangRdByCode3Idx == null ) {
			rqstISOLangRdByCode3Idx = new CFSecXMsgRqstISOLangRdByCode3Idx( this );
		}
		return( rqstISOLangRdByCode3Idx );
	}

	protected CFSecXMsgRqstISOLangRdByCode2Idx getRqstISOLangRdByCode2Idx() {
		if( rqstISOLangRdByCode2Idx == null ) {
			rqstISOLangRdByCode2Idx = new CFSecXMsgRqstISOLangRdByCode2Idx( this );
		}
		return( rqstISOLangRdByCode2Idx );
	}

	protected CFSecXMsgRqstISOLangDelByCode3Idx getRqstISOLangDelByCode3Idx() {
		if( rqstISOLangDelByCode3Idx == null ) {
			rqstISOLangDelByCode3Idx = new CFSecXMsgRqstISOLangDelByCode3Idx( this );
		}
		return( rqstISOLangDelByCode3Idx );
	}

	protected CFSecXMsgRqstISOLangDelByCode2Idx getRqstISOLangDelByCode2Idx() {
		if( rqstISOLangDelByCode2Idx == null ) {
			rqstISOLangDelByCode2Idx = new CFSecXMsgRqstISOLangDelByCode2Idx( this );
		}
		return( rqstISOLangDelByCode2Idx );
	}

	// ISOTZone Request  Factories

	protected CFSecXMsgRqstISOTZoneCreate getRqstISOTZoneCreate() {
		if( rqstISOTZoneCreate == null ) {
			rqstISOTZoneCreate = new CFSecXMsgRqstISOTZoneCreate( this );
		}
		return( rqstISOTZoneCreate );
	}

	protected CFSecXMsgRqstISOTZoneRead getRqstISOTZoneRead() {
		if( rqstISOTZoneRead == null ) {
			rqstISOTZoneRead = new CFSecXMsgRqstISOTZoneRead( this );
		}
		return( rqstISOTZoneRead );
	}

	protected CFSecXMsgRqstISOTZoneLock getRqstISOTZoneLock() {
		if( rqstISOTZoneLock == null ) {
			rqstISOTZoneLock = new CFSecXMsgRqstISOTZoneLock( this );
		}
		return( rqstISOTZoneLock );
	}

	protected CFSecXMsgRqstISOTZoneUpdate getRqstISOTZoneUpdate() {
		if( rqstISOTZoneUpdate == null ) {
			rqstISOTZoneUpdate = new CFSecXMsgRqstISOTZoneUpdate( this );
		}
		return( rqstISOTZoneUpdate );
	}

	protected CFSecXMsgRqstISOTZoneDelete getRqstISOTZoneDelete() {
		if( rqstISOTZoneDelete == null ) {
			rqstISOTZoneDelete = new CFSecXMsgRqstISOTZoneDelete( this );
		}
		return( rqstISOTZoneDelete );
	}

	protected CFSecXMsgRqstISOTZoneReadAll getRqstISOTZoneReadAll() {
		if( rqstISOTZoneReadAll == null ) {
			rqstISOTZoneReadAll = new CFSecXMsgRqstISOTZoneReadAll( this );
		}
		return( rqstISOTZoneReadAll );
	}

	protected CFSecXMsgRqstISOTZoneRdByOffsetIdx getRqstISOTZoneRdByOffsetIdx() {
		if( rqstISOTZoneRdByOffsetIdx == null ) {
			rqstISOTZoneRdByOffsetIdx = new CFSecXMsgRqstISOTZoneRdByOffsetIdx( this );
		}
		return( rqstISOTZoneRdByOffsetIdx );
	}

	protected CFSecXMsgRqstISOTZoneRdByUTZNameIdx getRqstISOTZoneRdByUTZNameIdx() {
		if( rqstISOTZoneRdByUTZNameIdx == null ) {
			rqstISOTZoneRdByUTZNameIdx = new CFSecXMsgRqstISOTZoneRdByUTZNameIdx( this );
		}
		return( rqstISOTZoneRdByUTZNameIdx );
	}

	protected CFSecXMsgRqstISOTZoneRdByIso8601Idx getRqstISOTZoneRdByIso8601Idx() {
		if( rqstISOTZoneRdByIso8601Idx == null ) {
			rqstISOTZoneRdByIso8601Idx = new CFSecXMsgRqstISOTZoneRdByIso8601Idx( this );
		}
		return( rqstISOTZoneRdByIso8601Idx );
	}

	protected CFSecXMsgRqstISOTZoneDelByOffsetIdx getRqstISOTZoneDelByOffsetIdx() {
		if( rqstISOTZoneDelByOffsetIdx == null ) {
			rqstISOTZoneDelByOffsetIdx = new CFSecXMsgRqstISOTZoneDelByOffsetIdx( this );
		}
		return( rqstISOTZoneDelByOffsetIdx );
	}

	protected CFSecXMsgRqstISOTZoneDelByUTZNameIdx getRqstISOTZoneDelByUTZNameIdx() {
		if( rqstISOTZoneDelByUTZNameIdx == null ) {
			rqstISOTZoneDelByUTZNameIdx = new CFSecXMsgRqstISOTZoneDelByUTZNameIdx( this );
		}
		return( rqstISOTZoneDelByUTZNameIdx );
	}

	protected CFSecXMsgRqstISOTZoneDelByIso8601Idx getRqstISOTZoneDelByIso8601Idx() {
		if( rqstISOTZoneDelByIso8601Idx == null ) {
			rqstISOTZoneDelByIso8601Idx = new CFSecXMsgRqstISOTZoneDelByIso8601Idx( this );
		}
		return( rqstISOTZoneDelByIso8601Idx );
	}

	// SecApp Request  Factories

	protected CFSecXMsgRqstSecAppCreate getRqstSecAppCreate() {
		if( rqstSecAppCreate == null ) {
			rqstSecAppCreate = new CFSecXMsgRqstSecAppCreate( this );
		}
		return( rqstSecAppCreate );
	}

	protected CFSecXMsgRqstSecAppRead getRqstSecAppRead() {
		if( rqstSecAppRead == null ) {
			rqstSecAppRead = new CFSecXMsgRqstSecAppRead( this );
		}
		return( rqstSecAppRead );
	}

	protected CFSecXMsgRqstSecAppLock getRqstSecAppLock() {
		if( rqstSecAppLock == null ) {
			rqstSecAppLock = new CFSecXMsgRqstSecAppLock( this );
		}
		return( rqstSecAppLock );
	}

	protected CFSecXMsgRqstSecAppUpdate getRqstSecAppUpdate() {
		if( rqstSecAppUpdate == null ) {
			rqstSecAppUpdate = new CFSecXMsgRqstSecAppUpdate( this );
		}
		return( rqstSecAppUpdate );
	}

	protected CFSecXMsgRqstSecAppDelete getRqstSecAppDelete() {
		if( rqstSecAppDelete == null ) {
			rqstSecAppDelete = new CFSecXMsgRqstSecAppDelete( this );
		}
		return( rqstSecAppDelete );
	}

	protected CFSecXMsgRqstSecAppReadAll getRqstSecAppReadAll() {
		if( rqstSecAppReadAll == null ) {
			rqstSecAppReadAll = new CFSecXMsgRqstSecAppReadAll( this );
		}
		return( rqstSecAppReadAll );
	}

	protected CFSecXMsgRqstSecAppPageAll getRqstSecAppPageAll() {
		if( rqstSecAppPageAll == null ) {
			rqstSecAppPageAll = new CFSecXMsgRqstSecAppPageAll( this );
		}
		return( rqstSecAppPageAll );
	}

	protected CFSecXMsgRqstSecAppRdByClusterIdx getRqstSecAppRdByClusterIdx() {
		if( rqstSecAppRdByClusterIdx == null ) {
			rqstSecAppRdByClusterIdx = new CFSecXMsgRqstSecAppRdByClusterIdx( this );
		}
		return( rqstSecAppRdByClusterIdx );
	}

	protected CFSecXMsgRqstSecAppRdByUJEEMountIdx getRqstSecAppRdByUJEEMountIdx() {
		if( rqstSecAppRdByUJEEMountIdx == null ) {
			rqstSecAppRdByUJEEMountIdx = new CFSecXMsgRqstSecAppRdByUJEEMountIdx( this );
		}
		return( rqstSecAppRdByUJEEMountIdx );
	}

	protected CFSecXMsgRqstSecAppPageByClusterIdx getRqstSecAppPageByClusterIdx() {
		if( rqstSecAppPageByClusterIdx == null ) {
			rqstSecAppPageByClusterIdx = new CFSecXMsgRqstSecAppPageByClusterIdx( this );
		}
		return( rqstSecAppPageByClusterIdx );
	}

	protected CFSecXMsgRqstSecAppDelByClusterIdx getRqstSecAppDelByClusterIdx() {
		if( rqstSecAppDelByClusterIdx == null ) {
			rqstSecAppDelByClusterIdx = new CFSecXMsgRqstSecAppDelByClusterIdx( this );
		}
		return( rqstSecAppDelByClusterIdx );
	}

	protected CFSecXMsgRqstSecAppDelByUJEEMountIdx getRqstSecAppDelByUJEEMountIdx() {
		if( rqstSecAppDelByUJEEMountIdx == null ) {
			rqstSecAppDelByUJEEMountIdx = new CFSecXMsgRqstSecAppDelByUJEEMountIdx( this );
		}
		return( rqstSecAppDelByUJEEMountIdx );
	}

	// SecDevice Request  Factories

	protected CFSecXMsgRqstSecDeviceCreate getRqstSecDeviceCreate() {
		if( rqstSecDeviceCreate == null ) {
			rqstSecDeviceCreate = new CFSecXMsgRqstSecDeviceCreate( this );
		}
		return( rqstSecDeviceCreate );
	}

	protected CFSecXMsgRqstSecDeviceRead getRqstSecDeviceRead() {
		if( rqstSecDeviceRead == null ) {
			rqstSecDeviceRead = new CFSecXMsgRqstSecDeviceRead( this );
		}
		return( rqstSecDeviceRead );
	}

	protected CFSecXMsgRqstSecDeviceLock getRqstSecDeviceLock() {
		if( rqstSecDeviceLock == null ) {
			rqstSecDeviceLock = new CFSecXMsgRqstSecDeviceLock( this );
		}
		return( rqstSecDeviceLock );
	}

	protected CFSecXMsgRqstSecDeviceUpdate getRqstSecDeviceUpdate() {
		if( rqstSecDeviceUpdate == null ) {
			rqstSecDeviceUpdate = new CFSecXMsgRqstSecDeviceUpdate( this );
		}
		return( rqstSecDeviceUpdate );
	}

	protected CFSecXMsgRqstSecDeviceDelete getRqstSecDeviceDelete() {
		if( rqstSecDeviceDelete == null ) {
			rqstSecDeviceDelete = new CFSecXMsgRqstSecDeviceDelete( this );
		}
		return( rqstSecDeviceDelete );
	}

	protected CFSecXMsgRqstSecDeviceReadAll getRqstSecDeviceReadAll() {
		if( rqstSecDeviceReadAll == null ) {
			rqstSecDeviceReadAll = new CFSecXMsgRqstSecDeviceReadAll( this );
		}
		return( rqstSecDeviceReadAll );
	}

	protected CFSecXMsgRqstSecDevicePageAll getRqstSecDevicePageAll() {
		if( rqstSecDevicePageAll == null ) {
			rqstSecDevicePageAll = new CFSecXMsgRqstSecDevicePageAll( this );
		}
		return( rqstSecDevicePageAll );
	}

	protected CFSecXMsgRqstSecDeviceRdByNameIdx getRqstSecDeviceRdByNameIdx() {
		if( rqstSecDeviceRdByNameIdx == null ) {
			rqstSecDeviceRdByNameIdx = new CFSecXMsgRqstSecDeviceRdByNameIdx( this );
		}
		return( rqstSecDeviceRdByNameIdx );
	}

	protected CFSecXMsgRqstSecDeviceRdByUserIdx getRqstSecDeviceRdByUserIdx() {
		if( rqstSecDeviceRdByUserIdx == null ) {
			rqstSecDeviceRdByUserIdx = new CFSecXMsgRqstSecDeviceRdByUserIdx( this );
		}
		return( rqstSecDeviceRdByUserIdx );
	}

	protected CFSecXMsgRqstSecDevicePageByUserIdx getRqstSecDevicePageByUserIdx() {
		if( rqstSecDevicePageByUserIdx == null ) {
			rqstSecDevicePageByUserIdx = new CFSecXMsgRqstSecDevicePageByUserIdx( this );
		}
		return( rqstSecDevicePageByUserIdx );
	}

	protected CFSecXMsgRqstSecDeviceDelByNameIdx getRqstSecDeviceDelByNameIdx() {
		if( rqstSecDeviceDelByNameIdx == null ) {
			rqstSecDeviceDelByNameIdx = new CFSecXMsgRqstSecDeviceDelByNameIdx( this );
		}
		return( rqstSecDeviceDelByNameIdx );
	}

	protected CFSecXMsgRqstSecDeviceDelByUserIdx getRqstSecDeviceDelByUserIdx() {
		if( rqstSecDeviceDelByUserIdx == null ) {
			rqstSecDeviceDelByUserIdx = new CFSecXMsgRqstSecDeviceDelByUserIdx( this );
		}
		return( rqstSecDeviceDelByUserIdx );
	}

	// SecForm Request  Factories

	protected CFSecXMsgRqstSecFormCreate getRqstSecFormCreate() {
		if( rqstSecFormCreate == null ) {
			rqstSecFormCreate = new CFSecXMsgRqstSecFormCreate( this );
		}
		return( rqstSecFormCreate );
	}

	protected CFSecXMsgRqstSecFormRead getRqstSecFormRead() {
		if( rqstSecFormRead == null ) {
			rqstSecFormRead = new CFSecXMsgRqstSecFormRead( this );
		}
		return( rqstSecFormRead );
	}

	protected CFSecXMsgRqstSecFormLock getRqstSecFormLock() {
		if( rqstSecFormLock == null ) {
			rqstSecFormLock = new CFSecXMsgRqstSecFormLock( this );
		}
		return( rqstSecFormLock );
	}

	protected CFSecXMsgRqstSecFormUpdate getRqstSecFormUpdate() {
		if( rqstSecFormUpdate == null ) {
			rqstSecFormUpdate = new CFSecXMsgRqstSecFormUpdate( this );
		}
		return( rqstSecFormUpdate );
	}

	protected CFSecXMsgRqstSecFormDelete getRqstSecFormDelete() {
		if( rqstSecFormDelete == null ) {
			rqstSecFormDelete = new CFSecXMsgRqstSecFormDelete( this );
		}
		return( rqstSecFormDelete );
	}

	protected CFSecXMsgRqstSecFormReadAll getRqstSecFormReadAll() {
		if( rqstSecFormReadAll == null ) {
			rqstSecFormReadAll = new CFSecXMsgRqstSecFormReadAll( this );
		}
		return( rqstSecFormReadAll );
	}

	protected CFSecXMsgRqstSecFormPageAll getRqstSecFormPageAll() {
		if( rqstSecFormPageAll == null ) {
			rqstSecFormPageAll = new CFSecXMsgRqstSecFormPageAll( this );
		}
		return( rqstSecFormPageAll );
	}

	protected CFSecXMsgRqstSecFormRdByClusterIdx getRqstSecFormRdByClusterIdx() {
		if( rqstSecFormRdByClusterIdx == null ) {
			rqstSecFormRdByClusterIdx = new CFSecXMsgRqstSecFormRdByClusterIdx( this );
		}
		return( rqstSecFormRdByClusterIdx );
	}

	protected CFSecXMsgRqstSecFormRdBySecAppIdx getRqstSecFormRdBySecAppIdx() {
		if( rqstSecFormRdBySecAppIdx == null ) {
			rqstSecFormRdBySecAppIdx = new CFSecXMsgRqstSecFormRdBySecAppIdx( this );
		}
		return( rqstSecFormRdBySecAppIdx );
	}

	protected CFSecXMsgRqstSecFormRdByUJEEServletIdx getRqstSecFormRdByUJEEServletIdx() {
		if( rqstSecFormRdByUJEEServletIdx == null ) {
			rqstSecFormRdByUJEEServletIdx = new CFSecXMsgRqstSecFormRdByUJEEServletIdx( this );
		}
		return( rqstSecFormRdByUJEEServletIdx );
	}

	protected CFSecXMsgRqstSecFormPageByClusterIdx getRqstSecFormPageByClusterIdx() {
		if( rqstSecFormPageByClusterIdx == null ) {
			rqstSecFormPageByClusterIdx = new CFSecXMsgRqstSecFormPageByClusterIdx( this );
		}
		return( rqstSecFormPageByClusterIdx );
	}

	protected CFSecXMsgRqstSecFormPageBySecAppIdx getRqstSecFormPageBySecAppIdx() {
		if( rqstSecFormPageBySecAppIdx == null ) {
			rqstSecFormPageBySecAppIdx = new CFSecXMsgRqstSecFormPageBySecAppIdx( this );
		}
		return( rqstSecFormPageBySecAppIdx );
	}

	protected CFSecXMsgRqstSecFormDelByClusterIdx getRqstSecFormDelByClusterIdx() {
		if( rqstSecFormDelByClusterIdx == null ) {
			rqstSecFormDelByClusterIdx = new CFSecXMsgRqstSecFormDelByClusterIdx( this );
		}
		return( rqstSecFormDelByClusterIdx );
	}

	protected CFSecXMsgRqstSecFormDelBySecAppIdx getRqstSecFormDelBySecAppIdx() {
		if( rqstSecFormDelBySecAppIdx == null ) {
			rqstSecFormDelBySecAppIdx = new CFSecXMsgRqstSecFormDelBySecAppIdx( this );
		}
		return( rqstSecFormDelBySecAppIdx );
	}

	protected CFSecXMsgRqstSecFormDelByUJEEServletIdx getRqstSecFormDelByUJEEServletIdx() {
		if( rqstSecFormDelByUJEEServletIdx == null ) {
			rqstSecFormDelByUJEEServletIdx = new CFSecXMsgRqstSecFormDelByUJEEServletIdx( this );
		}
		return( rqstSecFormDelByUJEEServletIdx );
	}

	// SecGroup Request  Factories

	protected CFSecXMsgRqstSecGroupCreate getRqstSecGroupCreate() {
		if( rqstSecGroupCreate == null ) {
			rqstSecGroupCreate = new CFSecXMsgRqstSecGroupCreate( this );
		}
		return( rqstSecGroupCreate );
	}

	protected CFSecXMsgRqstSecGroupRead getRqstSecGroupRead() {
		if( rqstSecGroupRead == null ) {
			rqstSecGroupRead = new CFSecXMsgRqstSecGroupRead( this );
		}
		return( rqstSecGroupRead );
	}

	protected CFSecXMsgRqstSecGroupLock getRqstSecGroupLock() {
		if( rqstSecGroupLock == null ) {
			rqstSecGroupLock = new CFSecXMsgRqstSecGroupLock( this );
		}
		return( rqstSecGroupLock );
	}

	protected CFSecXMsgRqstSecGroupUpdate getRqstSecGroupUpdate() {
		if( rqstSecGroupUpdate == null ) {
			rqstSecGroupUpdate = new CFSecXMsgRqstSecGroupUpdate( this );
		}
		return( rqstSecGroupUpdate );
	}

	protected CFSecXMsgRqstSecGroupDelete getRqstSecGroupDelete() {
		if( rqstSecGroupDelete == null ) {
			rqstSecGroupDelete = new CFSecXMsgRqstSecGroupDelete( this );
		}
		return( rqstSecGroupDelete );
	}

	protected CFSecXMsgRqstSecGroupReadAll getRqstSecGroupReadAll() {
		if( rqstSecGroupReadAll == null ) {
			rqstSecGroupReadAll = new CFSecXMsgRqstSecGroupReadAll( this );
		}
		return( rqstSecGroupReadAll );
	}

	protected CFSecXMsgRqstSecGroupRdByClusterIdx getRqstSecGroupRdByClusterIdx() {
		if( rqstSecGroupRdByClusterIdx == null ) {
			rqstSecGroupRdByClusterIdx = new CFSecXMsgRqstSecGroupRdByClusterIdx( this );
		}
		return( rqstSecGroupRdByClusterIdx );
	}

	protected CFSecXMsgRqstSecGroupRdByClusterVisIdx getRqstSecGroupRdByClusterVisIdx() {
		if( rqstSecGroupRdByClusterVisIdx == null ) {
			rqstSecGroupRdByClusterVisIdx = new CFSecXMsgRqstSecGroupRdByClusterVisIdx( this );
		}
		return( rqstSecGroupRdByClusterVisIdx );
	}

	protected CFSecXMsgRqstSecGroupRdByUNameIdx getRqstSecGroupRdByUNameIdx() {
		if( rqstSecGroupRdByUNameIdx == null ) {
			rqstSecGroupRdByUNameIdx = new CFSecXMsgRqstSecGroupRdByUNameIdx( this );
		}
		return( rqstSecGroupRdByUNameIdx );
	}

	protected CFSecXMsgRqstSecGroupDelByClusterIdx getRqstSecGroupDelByClusterIdx() {
		if( rqstSecGroupDelByClusterIdx == null ) {
			rqstSecGroupDelByClusterIdx = new CFSecXMsgRqstSecGroupDelByClusterIdx( this );
		}
		return( rqstSecGroupDelByClusterIdx );
	}

	protected CFSecXMsgRqstSecGroupDelByClusterVisIdx getRqstSecGroupDelByClusterVisIdx() {
		if( rqstSecGroupDelByClusterVisIdx == null ) {
			rqstSecGroupDelByClusterVisIdx = new CFSecXMsgRqstSecGroupDelByClusterVisIdx( this );
		}
		return( rqstSecGroupDelByClusterVisIdx );
	}

	protected CFSecXMsgRqstSecGroupDelByUNameIdx getRqstSecGroupDelByUNameIdx() {
		if( rqstSecGroupDelByUNameIdx == null ) {
			rqstSecGroupDelByUNameIdx = new CFSecXMsgRqstSecGroupDelByUNameIdx( this );
		}
		return( rqstSecGroupDelByUNameIdx );
	}

	// SecGroupForm Request  Factories

	protected CFSecXMsgRqstSecGroupFormCreate getRqstSecGroupFormCreate() {
		if( rqstSecGroupFormCreate == null ) {
			rqstSecGroupFormCreate = new CFSecXMsgRqstSecGroupFormCreate( this );
		}
		return( rqstSecGroupFormCreate );
	}

	protected CFSecXMsgRqstSecGroupFormRead getRqstSecGroupFormRead() {
		if( rqstSecGroupFormRead == null ) {
			rqstSecGroupFormRead = new CFSecXMsgRqstSecGroupFormRead( this );
		}
		return( rqstSecGroupFormRead );
	}

	protected CFSecXMsgRqstSecGroupFormLock getRqstSecGroupFormLock() {
		if( rqstSecGroupFormLock == null ) {
			rqstSecGroupFormLock = new CFSecXMsgRqstSecGroupFormLock( this );
		}
		return( rqstSecGroupFormLock );
	}

	protected CFSecXMsgRqstSecGroupFormUpdate getRqstSecGroupFormUpdate() {
		if( rqstSecGroupFormUpdate == null ) {
			rqstSecGroupFormUpdate = new CFSecXMsgRqstSecGroupFormUpdate( this );
		}
		return( rqstSecGroupFormUpdate );
	}

	protected CFSecXMsgRqstSecGroupFormDelete getRqstSecGroupFormDelete() {
		if( rqstSecGroupFormDelete == null ) {
			rqstSecGroupFormDelete = new CFSecXMsgRqstSecGroupFormDelete( this );
		}
		return( rqstSecGroupFormDelete );
	}

	protected CFSecXMsgRqstSecGroupFormReadAll getRqstSecGroupFormReadAll() {
		if( rqstSecGroupFormReadAll == null ) {
			rqstSecGroupFormReadAll = new CFSecXMsgRqstSecGroupFormReadAll( this );
		}
		return( rqstSecGroupFormReadAll );
	}

	protected CFSecXMsgRqstSecGroupFormPageAll getRqstSecGroupFormPageAll() {
		if( rqstSecGroupFormPageAll == null ) {
			rqstSecGroupFormPageAll = new CFSecXMsgRqstSecGroupFormPageAll( this );
		}
		return( rqstSecGroupFormPageAll );
	}

	protected CFSecXMsgRqstSecGroupFormRdByClusterIdx getRqstSecGroupFormRdByClusterIdx() {
		if( rqstSecGroupFormRdByClusterIdx == null ) {
			rqstSecGroupFormRdByClusterIdx = new CFSecXMsgRqstSecGroupFormRdByClusterIdx( this );
		}
		return( rqstSecGroupFormRdByClusterIdx );
	}

	protected CFSecXMsgRqstSecGroupFormRdByGroupIdx getRqstSecGroupFormRdByGroupIdx() {
		if( rqstSecGroupFormRdByGroupIdx == null ) {
			rqstSecGroupFormRdByGroupIdx = new CFSecXMsgRqstSecGroupFormRdByGroupIdx( this );
		}
		return( rqstSecGroupFormRdByGroupIdx );
	}

	protected CFSecXMsgRqstSecGroupFormRdByAppIdx getRqstSecGroupFormRdByAppIdx() {
		if( rqstSecGroupFormRdByAppIdx == null ) {
			rqstSecGroupFormRdByAppIdx = new CFSecXMsgRqstSecGroupFormRdByAppIdx( this );
		}
		return( rqstSecGroupFormRdByAppIdx );
	}

	protected CFSecXMsgRqstSecGroupFormRdByFormIdx getRqstSecGroupFormRdByFormIdx() {
		if( rqstSecGroupFormRdByFormIdx == null ) {
			rqstSecGroupFormRdByFormIdx = new CFSecXMsgRqstSecGroupFormRdByFormIdx( this );
		}
		return( rqstSecGroupFormRdByFormIdx );
	}

	protected CFSecXMsgRqstSecGroupFormRdByUFormIdx getRqstSecGroupFormRdByUFormIdx() {
		if( rqstSecGroupFormRdByUFormIdx == null ) {
			rqstSecGroupFormRdByUFormIdx = new CFSecXMsgRqstSecGroupFormRdByUFormIdx( this );
		}
		return( rqstSecGroupFormRdByUFormIdx );
	}

	protected CFSecXMsgRqstSecGroupFormPageByClusterIdx getRqstSecGroupFormPageByClusterIdx() {
		if( rqstSecGroupFormPageByClusterIdx == null ) {
			rqstSecGroupFormPageByClusterIdx = new CFSecXMsgRqstSecGroupFormPageByClusterIdx( this );
		}
		return( rqstSecGroupFormPageByClusterIdx );
	}

	protected CFSecXMsgRqstSecGroupFormPageByGroupIdx getRqstSecGroupFormPageByGroupIdx() {
		if( rqstSecGroupFormPageByGroupIdx == null ) {
			rqstSecGroupFormPageByGroupIdx = new CFSecXMsgRqstSecGroupFormPageByGroupIdx( this );
		}
		return( rqstSecGroupFormPageByGroupIdx );
	}

	protected CFSecXMsgRqstSecGroupFormPageByAppIdx getRqstSecGroupFormPageByAppIdx() {
		if( rqstSecGroupFormPageByAppIdx == null ) {
			rqstSecGroupFormPageByAppIdx = new CFSecXMsgRqstSecGroupFormPageByAppIdx( this );
		}
		return( rqstSecGroupFormPageByAppIdx );
	}

	protected CFSecXMsgRqstSecGroupFormPageByFormIdx getRqstSecGroupFormPageByFormIdx() {
		if( rqstSecGroupFormPageByFormIdx == null ) {
			rqstSecGroupFormPageByFormIdx = new CFSecXMsgRqstSecGroupFormPageByFormIdx( this );
		}
		return( rqstSecGroupFormPageByFormIdx );
	}

	protected CFSecXMsgRqstSecGroupFormDelByClusterIdx getRqstSecGroupFormDelByClusterIdx() {
		if( rqstSecGroupFormDelByClusterIdx == null ) {
			rqstSecGroupFormDelByClusterIdx = new CFSecXMsgRqstSecGroupFormDelByClusterIdx( this );
		}
		return( rqstSecGroupFormDelByClusterIdx );
	}

	protected CFSecXMsgRqstSecGroupFormDelByGroupIdx getRqstSecGroupFormDelByGroupIdx() {
		if( rqstSecGroupFormDelByGroupIdx == null ) {
			rqstSecGroupFormDelByGroupIdx = new CFSecXMsgRqstSecGroupFormDelByGroupIdx( this );
		}
		return( rqstSecGroupFormDelByGroupIdx );
	}

	protected CFSecXMsgRqstSecGroupFormDelByAppIdx getRqstSecGroupFormDelByAppIdx() {
		if( rqstSecGroupFormDelByAppIdx == null ) {
			rqstSecGroupFormDelByAppIdx = new CFSecXMsgRqstSecGroupFormDelByAppIdx( this );
		}
		return( rqstSecGroupFormDelByAppIdx );
	}

	protected CFSecXMsgRqstSecGroupFormDelByFormIdx getRqstSecGroupFormDelByFormIdx() {
		if( rqstSecGroupFormDelByFormIdx == null ) {
			rqstSecGroupFormDelByFormIdx = new CFSecXMsgRqstSecGroupFormDelByFormIdx( this );
		}
		return( rqstSecGroupFormDelByFormIdx );
	}

	protected CFSecXMsgRqstSecGroupFormDelByUFormIdx getRqstSecGroupFormDelByUFormIdx() {
		if( rqstSecGroupFormDelByUFormIdx == null ) {
			rqstSecGroupFormDelByUFormIdx = new CFSecXMsgRqstSecGroupFormDelByUFormIdx( this );
		}
		return( rqstSecGroupFormDelByUFormIdx );
	}

	// SecGrpInc Request  Factories

	protected CFSecXMsgRqstSecGrpIncCreate getRqstSecGrpIncCreate() {
		if( rqstSecGrpIncCreate == null ) {
			rqstSecGrpIncCreate = new CFSecXMsgRqstSecGrpIncCreate( this );
		}
		return( rqstSecGrpIncCreate );
	}

	protected CFSecXMsgRqstSecGrpIncRead getRqstSecGrpIncRead() {
		if( rqstSecGrpIncRead == null ) {
			rqstSecGrpIncRead = new CFSecXMsgRqstSecGrpIncRead( this );
		}
		return( rqstSecGrpIncRead );
	}

	protected CFSecXMsgRqstSecGrpIncLock getRqstSecGrpIncLock() {
		if( rqstSecGrpIncLock == null ) {
			rqstSecGrpIncLock = new CFSecXMsgRqstSecGrpIncLock( this );
		}
		return( rqstSecGrpIncLock );
	}

	protected CFSecXMsgRqstSecGrpIncUpdate getRqstSecGrpIncUpdate() {
		if( rqstSecGrpIncUpdate == null ) {
			rqstSecGrpIncUpdate = new CFSecXMsgRqstSecGrpIncUpdate( this );
		}
		return( rqstSecGrpIncUpdate );
	}

	protected CFSecXMsgRqstSecGrpIncDelete getRqstSecGrpIncDelete() {
		if( rqstSecGrpIncDelete == null ) {
			rqstSecGrpIncDelete = new CFSecXMsgRqstSecGrpIncDelete( this );
		}
		return( rqstSecGrpIncDelete );
	}

	protected CFSecXMsgRqstSecGrpIncReadAll getRqstSecGrpIncReadAll() {
		if( rqstSecGrpIncReadAll == null ) {
			rqstSecGrpIncReadAll = new CFSecXMsgRqstSecGrpIncReadAll( this );
		}
		return( rqstSecGrpIncReadAll );
	}

	protected CFSecXMsgRqstSecGrpIncPageAll getRqstSecGrpIncPageAll() {
		if( rqstSecGrpIncPageAll == null ) {
			rqstSecGrpIncPageAll = new CFSecXMsgRqstSecGrpIncPageAll( this );
		}
		return( rqstSecGrpIncPageAll );
	}

	protected CFSecXMsgRqstSecGrpIncRdByClusterIdx getRqstSecGrpIncRdByClusterIdx() {
		if( rqstSecGrpIncRdByClusterIdx == null ) {
			rqstSecGrpIncRdByClusterIdx = new CFSecXMsgRqstSecGrpIncRdByClusterIdx( this );
		}
		return( rqstSecGrpIncRdByClusterIdx );
	}

	protected CFSecXMsgRqstSecGrpIncRdByGroupIdx getRqstSecGrpIncRdByGroupIdx() {
		if( rqstSecGrpIncRdByGroupIdx == null ) {
			rqstSecGrpIncRdByGroupIdx = new CFSecXMsgRqstSecGrpIncRdByGroupIdx( this );
		}
		return( rqstSecGrpIncRdByGroupIdx );
	}

	protected CFSecXMsgRqstSecGrpIncRdByIncludeIdx getRqstSecGrpIncRdByIncludeIdx() {
		if( rqstSecGrpIncRdByIncludeIdx == null ) {
			rqstSecGrpIncRdByIncludeIdx = new CFSecXMsgRqstSecGrpIncRdByIncludeIdx( this );
		}
		return( rqstSecGrpIncRdByIncludeIdx );
	}

	protected CFSecXMsgRqstSecGrpIncRdByUIncludeIdx getRqstSecGrpIncRdByUIncludeIdx() {
		if( rqstSecGrpIncRdByUIncludeIdx == null ) {
			rqstSecGrpIncRdByUIncludeIdx = new CFSecXMsgRqstSecGrpIncRdByUIncludeIdx( this );
		}
		return( rqstSecGrpIncRdByUIncludeIdx );
	}

	protected CFSecXMsgRqstSecGrpIncPageByClusterIdx getRqstSecGrpIncPageByClusterIdx() {
		if( rqstSecGrpIncPageByClusterIdx == null ) {
			rqstSecGrpIncPageByClusterIdx = new CFSecXMsgRqstSecGrpIncPageByClusterIdx( this );
		}
		return( rqstSecGrpIncPageByClusterIdx );
	}

	protected CFSecXMsgRqstSecGrpIncPageByGroupIdx getRqstSecGrpIncPageByGroupIdx() {
		if( rqstSecGrpIncPageByGroupIdx == null ) {
			rqstSecGrpIncPageByGroupIdx = new CFSecXMsgRqstSecGrpIncPageByGroupIdx( this );
		}
		return( rqstSecGrpIncPageByGroupIdx );
	}

	protected CFSecXMsgRqstSecGrpIncPageByIncludeIdx getRqstSecGrpIncPageByIncludeIdx() {
		if( rqstSecGrpIncPageByIncludeIdx == null ) {
			rqstSecGrpIncPageByIncludeIdx = new CFSecXMsgRqstSecGrpIncPageByIncludeIdx( this );
		}
		return( rqstSecGrpIncPageByIncludeIdx );
	}

	protected CFSecXMsgRqstSecGrpIncDelByClusterIdx getRqstSecGrpIncDelByClusterIdx() {
		if( rqstSecGrpIncDelByClusterIdx == null ) {
			rqstSecGrpIncDelByClusterIdx = new CFSecXMsgRqstSecGrpIncDelByClusterIdx( this );
		}
		return( rqstSecGrpIncDelByClusterIdx );
	}

	protected CFSecXMsgRqstSecGrpIncDelByGroupIdx getRqstSecGrpIncDelByGroupIdx() {
		if( rqstSecGrpIncDelByGroupIdx == null ) {
			rqstSecGrpIncDelByGroupIdx = new CFSecXMsgRqstSecGrpIncDelByGroupIdx( this );
		}
		return( rqstSecGrpIncDelByGroupIdx );
	}

	protected CFSecXMsgRqstSecGrpIncDelByIncludeIdx getRqstSecGrpIncDelByIncludeIdx() {
		if( rqstSecGrpIncDelByIncludeIdx == null ) {
			rqstSecGrpIncDelByIncludeIdx = new CFSecXMsgRqstSecGrpIncDelByIncludeIdx( this );
		}
		return( rqstSecGrpIncDelByIncludeIdx );
	}

	protected CFSecXMsgRqstSecGrpIncDelByUIncludeIdx getRqstSecGrpIncDelByUIncludeIdx() {
		if( rqstSecGrpIncDelByUIncludeIdx == null ) {
			rqstSecGrpIncDelByUIncludeIdx = new CFSecXMsgRqstSecGrpIncDelByUIncludeIdx( this );
		}
		return( rqstSecGrpIncDelByUIncludeIdx );
	}

	// SecGrpMemb Request  Factories

	protected CFSecXMsgRqstSecGrpMembCreate getRqstSecGrpMembCreate() {
		if( rqstSecGrpMembCreate == null ) {
			rqstSecGrpMembCreate = new CFSecXMsgRqstSecGrpMembCreate( this );
		}
		return( rqstSecGrpMembCreate );
	}

	protected CFSecXMsgRqstSecGrpMembRead getRqstSecGrpMembRead() {
		if( rqstSecGrpMembRead == null ) {
			rqstSecGrpMembRead = new CFSecXMsgRqstSecGrpMembRead( this );
		}
		return( rqstSecGrpMembRead );
	}

	protected CFSecXMsgRqstSecGrpMembLock getRqstSecGrpMembLock() {
		if( rqstSecGrpMembLock == null ) {
			rqstSecGrpMembLock = new CFSecXMsgRqstSecGrpMembLock( this );
		}
		return( rqstSecGrpMembLock );
	}

	protected CFSecXMsgRqstSecGrpMembUpdate getRqstSecGrpMembUpdate() {
		if( rqstSecGrpMembUpdate == null ) {
			rqstSecGrpMembUpdate = new CFSecXMsgRqstSecGrpMembUpdate( this );
		}
		return( rqstSecGrpMembUpdate );
	}

	protected CFSecXMsgRqstSecGrpMembDelete getRqstSecGrpMembDelete() {
		if( rqstSecGrpMembDelete == null ) {
			rqstSecGrpMembDelete = new CFSecXMsgRqstSecGrpMembDelete( this );
		}
		return( rqstSecGrpMembDelete );
	}

	protected CFSecXMsgRqstSecGrpMembReadAll getRqstSecGrpMembReadAll() {
		if( rqstSecGrpMembReadAll == null ) {
			rqstSecGrpMembReadAll = new CFSecXMsgRqstSecGrpMembReadAll( this );
		}
		return( rqstSecGrpMembReadAll );
	}

	protected CFSecXMsgRqstSecGrpMembPageAll getRqstSecGrpMembPageAll() {
		if( rqstSecGrpMembPageAll == null ) {
			rqstSecGrpMembPageAll = new CFSecXMsgRqstSecGrpMembPageAll( this );
		}
		return( rqstSecGrpMembPageAll );
	}

	protected CFSecXMsgRqstSecGrpMembRdByClusterIdx getRqstSecGrpMembRdByClusterIdx() {
		if( rqstSecGrpMembRdByClusterIdx == null ) {
			rqstSecGrpMembRdByClusterIdx = new CFSecXMsgRqstSecGrpMembRdByClusterIdx( this );
		}
		return( rqstSecGrpMembRdByClusterIdx );
	}

	protected CFSecXMsgRqstSecGrpMembRdByGroupIdx getRqstSecGrpMembRdByGroupIdx() {
		if( rqstSecGrpMembRdByGroupIdx == null ) {
			rqstSecGrpMembRdByGroupIdx = new CFSecXMsgRqstSecGrpMembRdByGroupIdx( this );
		}
		return( rqstSecGrpMembRdByGroupIdx );
	}

	protected CFSecXMsgRqstSecGrpMembRdByUserIdx getRqstSecGrpMembRdByUserIdx() {
		if( rqstSecGrpMembRdByUserIdx == null ) {
			rqstSecGrpMembRdByUserIdx = new CFSecXMsgRqstSecGrpMembRdByUserIdx( this );
		}
		return( rqstSecGrpMembRdByUserIdx );
	}

	protected CFSecXMsgRqstSecGrpMembRdByUUserIdx getRqstSecGrpMembRdByUUserIdx() {
		if( rqstSecGrpMembRdByUUserIdx == null ) {
			rqstSecGrpMembRdByUUserIdx = new CFSecXMsgRqstSecGrpMembRdByUUserIdx( this );
		}
		return( rqstSecGrpMembRdByUUserIdx );
	}

	protected CFSecXMsgRqstSecGrpMembPageByClusterIdx getRqstSecGrpMembPageByClusterIdx() {
		if( rqstSecGrpMembPageByClusterIdx == null ) {
			rqstSecGrpMembPageByClusterIdx = new CFSecXMsgRqstSecGrpMembPageByClusterIdx( this );
		}
		return( rqstSecGrpMembPageByClusterIdx );
	}

	protected CFSecXMsgRqstSecGrpMembPageByGroupIdx getRqstSecGrpMembPageByGroupIdx() {
		if( rqstSecGrpMembPageByGroupIdx == null ) {
			rqstSecGrpMembPageByGroupIdx = new CFSecXMsgRqstSecGrpMembPageByGroupIdx( this );
		}
		return( rqstSecGrpMembPageByGroupIdx );
	}

	protected CFSecXMsgRqstSecGrpMembPageByUserIdx getRqstSecGrpMembPageByUserIdx() {
		if( rqstSecGrpMembPageByUserIdx == null ) {
			rqstSecGrpMembPageByUserIdx = new CFSecXMsgRqstSecGrpMembPageByUserIdx( this );
		}
		return( rqstSecGrpMembPageByUserIdx );
	}

	protected CFSecXMsgRqstSecGrpMembDelByClusterIdx getRqstSecGrpMembDelByClusterIdx() {
		if( rqstSecGrpMembDelByClusterIdx == null ) {
			rqstSecGrpMembDelByClusterIdx = new CFSecXMsgRqstSecGrpMembDelByClusterIdx( this );
		}
		return( rqstSecGrpMembDelByClusterIdx );
	}

	protected CFSecXMsgRqstSecGrpMembDelByGroupIdx getRqstSecGrpMembDelByGroupIdx() {
		if( rqstSecGrpMembDelByGroupIdx == null ) {
			rqstSecGrpMembDelByGroupIdx = new CFSecXMsgRqstSecGrpMembDelByGroupIdx( this );
		}
		return( rqstSecGrpMembDelByGroupIdx );
	}

	protected CFSecXMsgRqstSecGrpMembDelByUserIdx getRqstSecGrpMembDelByUserIdx() {
		if( rqstSecGrpMembDelByUserIdx == null ) {
			rqstSecGrpMembDelByUserIdx = new CFSecXMsgRqstSecGrpMembDelByUserIdx( this );
		}
		return( rqstSecGrpMembDelByUserIdx );
	}

	protected CFSecXMsgRqstSecGrpMembDelByUUserIdx getRqstSecGrpMembDelByUUserIdx() {
		if( rqstSecGrpMembDelByUUserIdx == null ) {
			rqstSecGrpMembDelByUUserIdx = new CFSecXMsgRqstSecGrpMembDelByUUserIdx( this );
		}
		return( rqstSecGrpMembDelByUUserIdx );
	}

	// SecSession Request  Factories

	protected CFSecXMsgRqstSecSessionCreate getRqstSecSessionCreate() {
		if( rqstSecSessionCreate == null ) {
			rqstSecSessionCreate = new CFSecXMsgRqstSecSessionCreate( this );
		}
		return( rqstSecSessionCreate );
	}

	protected CFSecXMsgRqstSecSessionRead getRqstSecSessionRead() {
		if( rqstSecSessionRead == null ) {
			rqstSecSessionRead = new CFSecXMsgRqstSecSessionRead( this );
		}
		return( rqstSecSessionRead );
	}

	protected CFSecXMsgRqstSecSessionLock getRqstSecSessionLock() {
		if( rqstSecSessionLock == null ) {
			rqstSecSessionLock = new CFSecXMsgRqstSecSessionLock( this );
		}
		return( rqstSecSessionLock );
	}

	protected CFSecXMsgRqstSecSessionUpdate getRqstSecSessionUpdate() {
		if( rqstSecSessionUpdate == null ) {
			rqstSecSessionUpdate = new CFSecXMsgRqstSecSessionUpdate( this );
		}
		return( rqstSecSessionUpdate );
	}

	protected CFSecXMsgRqstSecSessionDelete getRqstSecSessionDelete() {
		if( rqstSecSessionDelete == null ) {
			rqstSecSessionDelete = new CFSecXMsgRqstSecSessionDelete( this );
		}
		return( rqstSecSessionDelete );
	}

	protected CFSecXMsgRqstSecSessionReadAll getRqstSecSessionReadAll() {
		if( rqstSecSessionReadAll == null ) {
			rqstSecSessionReadAll = new CFSecXMsgRqstSecSessionReadAll( this );
		}
		return( rqstSecSessionReadAll );
	}

	protected CFSecXMsgRqstSecSessionPageAll getRqstSecSessionPageAll() {
		if( rqstSecSessionPageAll == null ) {
			rqstSecSessionPageAll = new CFSecXMsgRqstSecSessionPageAll( this );
		}
		return( rqstSecSessionPageAll );
	}

	protected CFSecXMsgRqstSecSessionRdBySecUserIdx getRqstSecSessionRdBySecUserIdx() {
		if( rqstSecSessionRdBySecUserIdx == null ) {
			rqstSecSessionRdBySecUserIdx = new CFSecXMsgRqstSecSessionRdBySecUserIdx( this );
		}
		return( rqstSecSessionRdBySecUserIdx );
	}

	protected CFSecXMsgRqstSecSessionRdBySecDevIdx getRqstSecSessionRdBySecDevIdx() {
		if( rqstSecSessionRdBySecDevIdx == null ) {
			rqstSecSessionRdBySecDevIdx = new CFSecXMsgRqstSecSessionRdBySecDevIdx( this );
		}
		return( rqstSecSessionRdBySecDevIdx );
	}

	protected CFSecXMsgRqstSecSessionRdByStartIdx getRqstSecSessionRdByStartIdx() {
		if( rqstSecSessionRdByStartIdx == null ) {
			rqstSecSessionRdByStartIdx = new CFSecXMsgRqstSecSessionRdByStartIdx( this );
		}
		return( rqstSecSessionRdByStartIdx );
	}

	protected CFSecXMsgRqstSecSessionRdByFinishIdx getRqstSecSessionRdByFinishIdx() {
		if( rqstSecSessionRdByFinishIdx == null ) {
			rqstSecSessionRdByFinishIdx = new CFSecXMsgRqstSecSessionRdByFinishIdx( this );
		}
		return( rqstSecSessionRdByFinishIdx );
	}

	protected CFSecXMsgRqstSecSessionRdBySecProxyIdx getRqstSecSessionRdBySecProxyIdx() {
		if( rqstSecSessionRdBySecProxyIdx == null ) {
			rqstSecSessionRdBySecProxyIdx = new CFSecXMsgRqstSecSessionRdBySecProxyIdx( this );
		}
		return( rqstSecSessionRdBySecProxyIdx );
	}

	protected CFSecXMsgRqstSecSessionPageBySecUserIdx getRqstSecSessionPageBySecUserIdx() {
		if( rqstSecSessionPageBySecUserIdx == null ) {
			rqstSecSessionPageBySecUserIdx = new CFSecXMsgRqstSecSessionPageBySecUserIdx( this );
		}
		return( rqstSecSessionPageBySecUserIdx );
	}

	protected CFSecXMsgRqstSecSessionPageBySecDevIdx getRqstSecSessionPageBySecDevIdx() {
		if( rqstSecSessionPageBySecDevIdx == null ) {
			rqstSecSessionPageBySecDevIdx = new CFSecXMsgRqstSecSessionPageBySecDevIdx( this );
		}
		return( rqstSecSessionPageBySecDevIdx );
	}

	protected CFSecXMsgRqstSecSessionPageByFinishIdx getRqstSecSessionPageByFinishIdx() {
		if( rqstSecSessionPageByFinishIdx == null ) {
			rqstSecSessionPageByFinishIdx = new CFSecXMsgRqstSecSessionPageByFinishIdx( this );
		}
		return( rqstSecSessionPageByFinishIdx );
	}

	protected CFSecXMsgRqstSecSessionPageBySecProxyIdx getRqstSecSessionPageBySecProxyIdx() {
		if( rqstSecSessionPageBySecProxyIdx == null ) {
			rqstSecSessionPageBySecProxyIdx = new CFSecXMsgRqstSecSessionPageBySecProxyIdx( this );
		}
		return( rqstSecSessionPageBySecProxyIdx );
	}

	protected CFSecXMsgRqstSecSessionDelBySecUserIdx getRqstSecSessionDelBySecUserIdx() {
		if( rqstSecSessionDelBySecUserIdx == null ) {
			rqstSecSessionDelBySecUserIdx = new CFSecXMsgRqstSecSessionDelBySecUserIdx( this );
		}
		return( rqstSecSessionDelBySecUserIdx );
	}

	protected CFSecXMsgRqstSecSessionDelBySecDevIdx getRqstSecSessionDelBySecDevIdx() {
		if( rqstSecSessionDelBySecDevIdx == null ) {
			rqstSecSessionDelBySecDevIdx = new CFSecXMsgRqstSecSessionDelBySecDevIdx( this );
		}
		return( rqstSecSessionDelBySecDevIdx );
	}

	protected CFSecXMsgRqstSecSessionDelByStartIdx getRqstSecSessionDelByStartIdx() {
		if( rqstSecSessionDelByStartIdx == null ) {
			rqstSecSessionDelByStartIdx = new CFSecXMsgRqstSecSessionDelByStartIdx( this );
		}
		return( rqstSecSessionDelByStartIdx );
	}

	protected CFSecXMsgRqstSecSessionDelByFinishIdx getRqstSecSessionDelByFinishIdx() {
		if( rqstSecSessionDelByFinishIdx == null ) {
			rqstSecSessionDelByFinishIdx = new CFSecXMsgRqstSecSessionDelByFinishIdx( this );
		}
		return( rqstSecSessionDelByFinishIdx );
	}

	protected CFSecXMsgRqstSecSessionDelBySecProxyIdx getRqstSecSessionDelBySecProxyIdx() {
		if( rqstSecSessionDelBySecProxyIdx == null ) {
			rqstSecSessionDelBySecProxyIdx = new CFSecXMsgRqstSecSessionDelBySecProxyIdx( this );
		}
		return( rqstSecSessionDelBySecProxyIdx );
	}

	// SecUser Request  Factories

	protected CFSecXMsgRqstSecUserCreate getRqstSecUserCreate() {
		if( rqstSecUserCreate == null ) {
			rqstSecUserCreate = new CFSecXMsgRqstSecUserCreate( this );
		}
		return( rqstSecUserCreate );
	}

	protected CFSecXMsgRqstSecUserRead getRqstSecUserRead() {
		if( rqstSecUserRead == null ) {
			rqstSecUserRead = new CFSecXMsgRqstSecUserRead( this );
		}
		return( rqstSecUserRead );
	}

	protected CFSecXMsgRqstSecUserLock getRqstSecUserLock() {
		if( rqstSecUserLock == null ) {
			rqstSecUserLock = new CFSecXMsgRqstSecUserLock( this );
		}
		return( rqstSecUserLock );
	}

	protected CFSecXMsgRqstSecUserUpdate getRqstSecUserUpdate() {
		if( rqstSecUserUpdate == null ) {
			rqstSecUserUpdate = new CFSecXMsgRqstSecUserUpdate( this );
		}
		return( rqstSecUserUpdate );
	}

	protected CFSecXMsgRqstSecUserDelete getRqstSecUserDelete() {
		if( rqstSecUserDelete == null ) {
			rqstSecUserDelete = new CFSecXMsgRqstSecUserDelete( this );
		}
		return( rqstSecUserDelete );
	}

	protected CFSecXMsgRqstSecUserReadAll getRqstSecUserReadAll() {
		if( rqstSecUserReadAll == null ) {
			rqstSecUserReadAll = new CFSecXMsgRqstSecUserReadAll( this );
		}
		return( rqstSecUserReadAll );
	}

	protected CFSecXMsgRqstSecUserPageAll getRqstSecUserPageAll() {
		if( rqstSecUserPageAll == null ) {
			rqstSecUserPageAll = new CFSecXMsgRqstSecUserPageAll( this );
		}
		return( rqstSecUserPageAll );
	}

	protected CFSecXMsgRqstSecUserRdByULoginIdx getRqstSecUserRdByULoginIdx() {
		if( rqstSecUserRdByULoginIdx == null ) {
			rqstSecUserRdByULoginIdx = new CFSecXMsgRqstSecUserRdByULoginIdx( this );
		}
		return( rqstSecUserRdByULoginIdx );
	}

	protected CFSecXMsgRqstSecUserRdByEMConfIdx getRqstSecUserRdByEMConfIdx() {
		if( rqstSecUserRdByEMConfIdx == null ) {
			rqstSecUserRdByEMConfIdx = new CFSecXMsgRqstSecUserRdByEMConfIdx( this );
		}
		return( rqstSecUserRdByEMConfIdx );
	}

	protected CFSecXMsgRqstSecUserRdByPwdResetIdx getRqstSecUserRdByPwdResetIdx() {
		if( rqstSecUserRdByPwdResetIdx == null ) {
			rqstSecUserRdByPwdResetIdx = new CFSecXMsgRqstSecUserRdByPwdResetIdx( this );
		}
		return( rqstSecUserRdByPwdResetIdx );
	}

	protected CFSecXMsgRqstSecUserRdByDefDevIdx getRqstSecUserRdByDefDevIdx() {
		if( rqstSecUserRdByDefDevIdx == null ) {
			rqstSecUserRdByDefDevIdx = new CFSecXMsgRqstSecUserRdByDefDevIdx( this );
		}
		return( rqstSecUserRdByDefDevIdx );
	}

	protected CFSecXMsgRqstSecUserPageByEMConfIdx getRqstSecUserPageByEMConfIdx() {
		if( rqstSecUserPageByEMConfIdx == null ) {
			rqstSecUserPageByEMConfIdx = new CFSecXMsgRqstSecUserPageByEMConfIdx( this );
		}
		return( rqstSecUserPageByEMConfIdx );
	}

	protected CFSecXMsgRqstSecUserPageByPwdResetIdx getRqstSecUserPageByPwdResetIdx() {
		if( rqstSecUserPageByPwdResetIdx == null ) {
			rqstSecUserPageByPwdResetIdx = new CFSecXMsgRqstSecUserPageByPwdResetIdx( this );
		}
		return( rqstSecUserPageByPwdResetIdx );
	}

	protected CFSecXMsgRqstSecUserPageByDefDevIdx getRqstSecUserPageByDefDevIdx() {
		if( rqstSecUserPageByDefDevIdx == null ) {
			rqstSecUserPageByDefDevIdx = new CFSecXMsgRqstSecUserPageByDefDevIdx( this );
		}
		return( rqstSecUserPageByDefDevIdx );
	}

	protected CFSecXMsgRqstSecUserDelByULoginIdx getRqstSecUserDelByULoginIdx() {
		if( rqstSecUserDelByULoginIdx == null ) {
			rqstSecUserDelByULoginIdx = new CFSecXMsgRqstSecUserDelByULoginIdx( this );
		}
		return( rqstSecUserDelByULoginIdx );
	}

	protected CFSecXMsgRqstSecUserDelByEMConfIdx getRqstSecUserDelByEMConfIdx() {
		if( rqstSecUserDelByEMConfIdx == null ) {
			rqstSecUserDelByEMConfIdx = new CFSecXMsgRqstSecUserDelByEMConfIdx( this );
		}
		return( rqstSecUserDelByEMConfIdx );
	}

	protected CFSecXMsgRqstSecUserDelByPwdResetIdx getRqstSecUserDelByPwdResetIdx() {
		if( rqstSecUserDelByPwdResetIdx == null ) {
			rqstSecUserDelByPwdResetIdx = new CFSecXMsgRqstSecUserDelByPwdResetIdx( this );
		}
		return( rqstSecUserDelByPwdResetIdx );
	}

	protected CFSecXMsgRqstSecUserDelByDefDevIdx getRqstSecUserDelByDefDevIdx() {
		if( rqstSecUserDelByDefDevIdx == null ) {
			rqstSecUserDelByDefDevIdx = new CFSecXMsgRqstSecUserDelByDefDevIdx( this );
		}
		return( rqstSecUserDelByDefDevIdx );
	}

	// Service Request  Factories

	protected CFSecXMsgRqstServiceCreate getRqstServiceCreate() {
		if( rqstServiceCreate == null ) {
			rqstServiceCreate = new CFSecXMsgRqstServiceCreate( this );
		}
		return( rqstServiceCreate );
	}

	protected CFSecXMsgRqstServiceRead getRqstServiceRead() {
		if( rqstServiceRead == null ) {
			rqstServiceRead = new CFSecXMsgRqstServiceRead( this );
		}
		return( rqstServiceRead );
	}

	protected CFSecXMsgRqstServiceLock getRqstServiceLock() {
		if( rqstServiceLock == null ) {
			rqstServiceLock = new CFSecXMsgRqstServiceLock( this );
		}
		return( rqstServiceLock );
	}

	protected CFSecXMsgRqstServiceUpdate getRqstServiceUpdate() {
		if( rqstServiceUpdate == null ) {
			rqstServiceUpdate = new CFSecXMsgRqstServiceUpdate( this );
		}
		return( rqstServiceUpdate );
	}

	protected CFSecXMsgRqstServiceDelete getRqstServiceDelete() {
		if( rqstServiceDelete == null ) {
			rqstServiceDelete = new CFSecXMsgRqstServiceDelete( this );
		}
		return( rqstServiceDelete );
	}

	protected CFSecXMsgRqstServiceReadAll getRqstServiceReadAll() {
		if( rqstServiceReadAll == null ) {
			rqstServiceReadAll = new CFSecXMsgRqstServiceReadAll( this );
		}
		return( rqstServiceReadAll );
	}

	protected CFSecXMsgRqstServicePageAll getRqstServicePageAll() {
		if( rqstServicePageAll == null ) {
			rqstServicePageAll = new CFSecXMsgRqstServicePageAll( this );
		}
		return( rqstServicePageAll );
	}

	protected CFSecXMsgRqstServiceRdByClusterIdx getRqstServiceRdByClusterIdx() {
		if( rqstServiceRdByClusterIdx == null ) {
			rqstServiceRdByClusterIdx = new CFSecXMsgRqstServiceRdByClusterIdx( this );
		}
		return( rqstServiceRdByClusterIdx );
	}

	protected CFSecXMsgRqstServiceRdByHostIdx getRqstServiceRdByHostIdx() {
		if( rqstServiceRdByHostIdx == null ) {
			rqstServiceRdByHostIdx = new CFSecXMsgRqstServiceRdByHostIdx( this );
		}
		return( rqstServiceRdByHostIdx );
	}

	protected CFSecXMsgRqstServiceRdByTypeIdx getRqstServiceRdByTypeIdx() {
		if( rqstServiceRdByTypeIdx == null ) {
			rqstServiceRdByTypeIdx = new CFSecXMsgRqstServiceRdByTypeIdx( this );
		}
		return( rqstServiceRdByTypeIdx );
	}

	protected CFSecXMsgRqstServiceRdByUTypeIdx getRqstServiceRdByUTypeIdx() {
		if( rqstServiceRdByUTypeIdx == null ) {
			rqstServiceRdByUTypeIdx = new CFSecXMsgRqstServiceRdByUTypeIdx( this );
		}
		return( rqstServiceRdByUTypeIdx );
	}

	protected CFSecXMsgRqstServiceRdByUHostPortIdx getRqstServiceRdByUHostPortIdx() {
		if( rqstServiceRdByUHostPortIdx == null ) {
			rqstServiceRdByUHostPortIdx = new CFSecXMsgRqstServiceRdByUHostPortIdx( this );
		}
		return( rqstServiceRdByUHostPortIdx );
	}

	protected CFSecXMsgRqstServicePageByClusterIdx getRqstServicePageByClusterIdx() {
		if( rqstServicePageByClusterIdx == null ) {
			rqstServicePageByClusterIdx = new CFSecXMsgRqstServicePageByClusterIdx( this );
		}
		return( rqstServicePageByClusterIdx );
	}

	protected CFSecXMsgRqstServicePageByHostIdx getRqstServicePageByHostIdx() {
		if( rqstServicePageByHostIdx == null ) {
			rqstServicePageByHostIdx = new CFSecXMsgRqstServicePageByHostIdx( this );
		}
		return( rqstServicePageByHostIdx );
	}

	protected CFSecXMsgRqstServicePageByTypeIdx getRqstServicePageByTypeIdx() {
		if( rqstServicePageByTypeIdx == null ) {
			rqstServicePageByTypeIdx = new CFSecXMsgRqstServicePageByTypeIdx( this );
		}
		return( rqstServicePageByTypeIdx );
	}

	protected CFSecXMsgRqstServiceDelByClusterIdx getRqstServiceDelByClusterIdx() {
		if( rqstServiceDelByClusterIdx == null ) {
			rqstServiceDelByClusterIdx = new CFSecXMsgRqstServiceDelByClusterIdx( this );
		}
		return( rqstServiceDelByClusterIdx );
	}

	protected CFSecXMsgRqstServiceDelByHostIdx getRqstServiceDelByHostIdx() {
		if( rqstServiceDelByHostIdx == null ) {
			rqstServiceDelByHostIdx = new CFSecXMsgRqstServiceDelByHostIdx( this );
		}
		return( rqstServiceDelByHostIdx );
	}

	protected CFSecXMsgRqstServiceDelByTypeIdx getRqstServiceDelByTypeIdx() {
		if( rqstServiceDelByTypeIdx == null ) {
			rqstServiceDelByTypeIdx = new CFSecXMsgRqstServiceDelByTypeIdx( this );
		}
		return( rqstServiceDelByTypeIdx );
	}

	protected CFSecXMsgRqstServiceDelByUTypeIdx getRqstServiceDelByUTypeIdx() {
		if( rqstServiceDelByUTypeIdx == null ) {
			rqstServiceDelByUTypeIdx = new CFSecXMsgRqstServiceDelByUTypeIdx( this );
		}
		return( rqstServiceDelByUTypeIdx );
	}

	protected CFSecXMsgRqstServiceDelByUHostPortIdx getRqstServiceDelByUHostPortIdx() {
		if( rqstServiceDelByUHostPortIdx == null ) {
			rqstServiceDelByUHostPortIdx = new CFSecXMsgRqstServiceDelByUHostPortIdx( this );
		}
		return( rqstServiceDelByUHostPortIdx );
	}

	// ServiceType Request  Factories

	protected CFSecXMsgRqstServiceTypeCreate getRqstServiceTypeCreate() {
		if( rqstServiceTypeCreate == null ) {
			rqstServiceTypeCreate = new CFSecXMsgRqstServiceTypeCreate( this );
		}
		return( rqstServiceTypeCreate );
	}

	protected CFSecXMsgRqstServiceTypeRead getRqstServiceTypeRead() {
		if( rqstServiceTypeRead == null ) {
			rqstServiceTypeRead = new CFSecXMsgRqstServiceTypeRead( this );
		}
		return( rqstServiceTypeRead );
	}

	protected CFSecXMsgRqstServiceTypeLock getRqstServiceTypeLock() {
		if( rqstServiceTypeLock == null ) {
			rqstServiceTypeLock = new CFSecXMsgRqstServiceTypeLock( this );
		}
		return( rqstServiceTypeLock );
	}

	protected CFSecXMsgRqstServiceTypeUpdate getRqstServiceTypeUpdate() {
		if( rqstServiceTypeUpdate == null ) {
			rqstServiceTypeUpdate = new CFSecXMsgRqstServiceTypeUpdate( this );
		}
		return( rqstServiceTypeUpdate );
	}

	protected CFSecXMsgRqstServiceTypeDelete getRqstServiceTypeDelete() {
		if( rqstServiceTypeDelete == null ) {
			rqstServiceTypeDelete = new CFSecXMsgRqstServiceTypeDelete( this );
		}
		return( rqstServiceTypeDelete );
	}

	protected CFSecXMsgRqstServiceTypeReadAll getRqstServiceTypeReadAll() {
		if( rqstServiceTypeReadAll == null ) {
			rqstServiceTypeReadAll = new CFSecXMsgRqstServiceTypeReadAll( this );
		}
		return( rqstServiceTypeReadAll );
	}

	protected CFSecXMsgRqstServiceTypeRdByUDescrIdx getRqstServiceTypeRdByUDescrIdx() {
		if( rqstServiceTypeRdByUDescrIdx == null ) {
			rqstServiceTypeRdByUDescrIdx = new CFSecXMsgRqstServiceTypeRdByUDescrIdx( this );
		}
		return( rqstServiceTypeRdByUDescrIdx );
	}

	protected CFSecXMsgRqstServiceTypeDelByUDescrIdx getRqstServiceTypeDelByUDescrIdx() {
		if( rqstServiceTypeDelByUDescrIdx == null ) {
			rqstServiceTypeDelByUDescrIdx = new CFSecXMsgRqstServiceTypeDelByUDescrIdx( this );
		}
		return( rqstServiceTypeDelByUDescrIdx );
	}

	// SysCluster Request  Factories

	protected CFSecXMsgRqstSysClusterCreate getRqstSysClusterCreate() {
		if( rqstSysClusterCreate == null ) {
			rqstSysClusterCreate = new CFSecXMsgRqstSysClusterCreate( this );
		}
		return( rqstSysClusterCreate );
	}

	protected CFSecXMsgRqstSysClusterRead getRqstSysClusterRead() {
		if( rqstSysClusterRead == null ) {
			rqstSysClusterRead = new CFSecXMsgRqstSysClusterRead( this );
		}
		return( rqstSysClusterRead );
	}

	protected CFSecXMsgRqstSysClusterLock getRqstSysClusterLock() {
		if( rqstSysClusterLock == null ) {
			rqstSysClusterLock = new CFSecXMsgRqstSysClusterLock( this );
		}
		return( rqstSysClusterLock );
	}

	protected CFSecXMsgRqstSysClusterUpdate getRqstSysClusterUpdate() {
		if( rqstSysClusterUpdate == null ) {
			rqstSysClusterUpdate = new CFSecXMsgRqstSysClusterUpdate( this );
		}
		return( rqstSysClusterUpdate );
	}

	protected CFSecXMsgRqstSysClusterDelete getRqstSysClusterDelete() {
		if( rqstSysClusterDelete == null ) {
			rqstSysClusterDelete = new CFSecXMsgRqstSysClusterDelete( this );
		}
		return( rqstSysClusterDelete );
	}

	protected CFSecXMsgRqstSysClusterReadAll getRqstSysClusterReadAll() {
		if( rqstSysClusterReadAll == null ) {
			rqstSysClusterReadAll = new CFSecXMsgRqstSysClusterReadAll( this );
		}
		return( rqstSysClusterReadAll );
	}

	protected CFSecXMsgRqstSysClusterRdByClusterIdx getRqstSysClusterRdByClusterIdx() {
		if( rqstSysClusterRdByClusterIdx == null ) {
			rqstSysClusterRdByClusterIdx = new CFSecXMsgRqstSysClusterRdByClusterIdx( this );
		}
		return( rqstSysClusterRdByClusterIdx );
	}

	protected CFSecXMsgRqstSysClusterDelByClusterIdx getRqstSysClusterDelByClusterIdx() {
		if( rqstSysClusterDelByClusterIdx == null ) {
			rqstSysClusterDelByClusterIdx = new CFSecXMsgRqstSysClusterDelByClusterIdx( this );
		}
		return( rqstSysClusterDelByClusterIdx );
	}

	// TSecGroup Request  Factories

	protected CFSecXMsgRqstTSecGroupCreate getRqstTSecGroupCreate() {
		if( rqstTSecGroupCreate == null ) {
			rqstTSecGroupCreate = new CFSecXMsgRqstTSecGroupCreate( this );
		}
		return( rqstTSecGroupCreate );
	}

	protected CFSecXMsgRqstTSecGroupRead getRqstTSecGroupRead() {
		if( rqstTSecGroupRead == null ) {
			rqstTSecGroupRead = new CFSecXMsgRqstTSecGroupRead( this );
		}
		return( rqstTSecGroupRead );
	}

	protected CFSecXMsgRqstTSecGroupLock getRqstTSecGroupLock() {
		if( rqstTSecGroupLock == null ) {
			rqstTSecGroupLock = new CFSecXMsgRqstTSecGroupLock( this );
		}
		return( rqstTSecGroupLock );
	}

	protected CFSecXMsgRqstTSecGroupUpdate getRqstTSecGroupUpdate() {
		if( rqstTSecGroupUpdate == null ) {
			rqstTSecGroupUpdate = new CFSecXMsgRqstTSecGroupUpdate( this );
		}
		return( rqstTSecGroupUpdate );
	}

	protected CFSecXMsgRqstTSecGroupDelete getRqstTSecGroupDelete() {
		if( rqstTSecGroupDelete == null ) {
			rqstTSecGroupDelete = new CFSecXMsgRqstTSecGroupDelete( this );
		}
		return( rqstTSecGroupDelete );
	}

	protected CFSecXMsgRqstTSecGroupReadAll getRqstTSecGroupReadAll() {
		if( rqstTSecGroupReadAll == null ) {
			rqstTSecGroupReadAll = new CFSecXMsgRqstTSecGroupReadAll( this );
		}
		return( rqstTSecGroupReadAll );
	}

	protected CFSecXMsgRqstTSecGroupRdByTenantIdx getRqstTSecGroupRdByTenantIdx() {
		if( rqstTSecGroupRdByTenantIdx == null ) {
			rqstTSecGroupRdByTenantIdx = new CFSecXMsgRqstTSecGroupRdByTenantIdx( this );
		}
		return( rqstTSecGroupRdByTenantIdx );
	}

	protected CFSecXMsgRqstTSecGroupRdByTenantVisIdx getRqstTSecGroupRdByTenantVisIdx() {
		if( rqstTSecGroupRdByTenantVisIdx == null ) {
			rqstTSecGroupRdByTenantVisIdx = new CFSecXMsgRqstTSecGroupRdByTenantVisIdx( this );
		}
		return( rqstTSecGroupRdByTenantVisIdx );
	}

	protected CFSecXMsgRqstTSecGroupRdByUNameIdx getRqstTSecGroupRdByUNameIdx() {
		if( rqstTSecGroupRdByUNameIdx == null ) {
			rqstTSecGroupRdByUNameIdx = new CFSecXMsgRqstTSecGroupRdByUNameIdx( this );
		}
		return( rqstTSecGroupRdByUNameIdx );
	}

	protected CFSecXMsgRqstTSecGroupDelByTenantIdx getRqstTSecGroupDelByTenantIdx() {
		if( rqstTSecGroupDelByTenantIdx == null ) {
			rqstTSecGroupDelByTenantIdx = new CFSecXMsgRqstTSecGroupDelByTenantIdx( this );
		}
		return( rqstTSecGroupDelByTenantIdx );
	}

	protected CFSecXMsgRqstTSecGroupDelByTenantVisIdx getRqstTSecGroupDelByTenantVisIdx() {
		if( rqstTSecGroupDelByTenantVisIdx == null ) {
			rqstTSecGroupDelByTenantVisIdx = new CFSecXMsgRqstTSecGroupDelByTenantVisIdx( this );
		}
		return( rqstTSecGroupDelByTenantVisIdx );
	}

	protected CFSecXMsgRqstTSecGroupDelByUNameIdx getRqstTSecGroupDelByUNameIdx() {
		if( rqstTSecGroupDelByUNameIdx == null ) {
			rqstTSecGroupDelByUNameIdx = new CFSecXMsgRqstTSecGroupDelByUNameIdx( this );
		}
		return( rqstTSecGroupDelByUNameIdx );
	}

	// TSecGrpInc Request  Factories

	protected CFSecXMsgRqstTSecGrpIncCreate getRqstTSecGrpIncCreate() {
		if( rqstTSecGrpIncCreate == null ) {
			rqstTSecGrpIncCreate = new CFSecXMsgRqstTSecGrpIncCreate( this );
		}
		return( rqstTSecGrpIncCreate );
	}

	protected CFSecXMsgRqstTSecGrpIncRead getRqstTSecGrpIncRead() {
		if( rqstTSecGrpIncRead == null ) {
			rqstTSecGrpIncRead = new CFSecXMsgRqstTSecGrpIncRead( this );
		}
		return( rqstTSecGrpIncRead );
	}

	protected CFSecXMsgRqstTSecGrpIncLock getRqstTSecGrpIncLock() {
		if( rqstTSecGrpIncLock == null ) {
			rqstTSecGrpIncLock = new CFSecXMsgRqstTSecGrpIncLock( this );
		}
		return( rqstTSecGrpIncLock );
	}

	protected CFSecXMsgRqstTSecGrpIncUpdate getRqstTSecGrpIncUpdate() {
		if( rqstTSecGrpIncUpdate == null ) {
			rqstTSecGrpIncUpdate = new CFSecXMsgRqstTSecGrpIncUpdate( this );
		}
		return( rqstTSecGrpIncUpdate );
	}

	protected CFSecXMsgRqstTSecGrpIncDelete getRqstTSecGrpIncDelete() {
		if( rqstTSecGrpIncDelete == null ) {
			rqstTSecGrpIncDelete = new CFSecXMsgRqstTSecGrpIncDelete( this );
		}
		return( rqstTSecGrpIncDelete );
	}

	protected CFSecXMsgRqstTSecGrpIncReadAll getRqstTSecGrpIncReadAll() {
		if( rqstTSecGrpIncReadAll == null ) {
			rqstTSecGrpIncReadAll = new CFSecXMsgRqstTSecGrpIncReadAll( this );
		}
		return( rqstTSecGrpIncReadAll );
	}

	protected CFSecXMsgRqstTSecGrpIncPageAll getRqstTSecGrpIncPageAll() {
		if( rqstTSecGrpIncPageAll == null ) {
			rqstTSecGrpIncPageAll = new CFSecXMsgRqstTSecGrpIncPageAll( this );
		}
		return( rqstTSecGrpIncPageAll );
	}

	protected CFSecXMsgRqstTSecGrpIncRdByTenantIdx getRqstTSecGrpIncRdByTenantIdx() {
		if( rqstTSecGrpIncRdByTenantIdx == null ) {
			rqstTSecGrpIncRdByTenantIdx = new CFSecXMsgRqstTSecGrpIncRdByTenantIdx( this );
		}
		return( rqstTSecGrpIncRdByTenantIdx );
	}

	protected CFSecXMsgRqstTSecGrpIncRdByGroupIdx getRqstTSecGrpIncRdByGroupIdx() {
		if( rqstTSecGrpIncRdByGroupIdx == null ) {
			rqstTSecGrpIncRdByGroupIdx = new CFSecXMsgRqstTSecGrpIncRdByGroupIdx( this );
		}
		return( rqstTSecGrpIncRdByGroupIdx );
	}

	protected CFSecXMsgRqstTSecGrpIncRdByIncludeIdx getRqstTSecGrpIncRdByIncludeIdx() {
		if( rqstTSecGrpIncRdByIncludeIdx == null ) {
			rqstTSecGrpIncRdByIncludeIdx = new CFSecXMsgRqstTSecGrpIncRdByIncludeIdx( this );
		}
		return( rqstTSecGrpIncRdByIncludeIdx );
	}

	protected CFSecXMsgRqstTSecGrpIncRdByUIncludeIdx getRqstTSecGrpIncRdByUIncludeIdx() {
		if( rqstTSecGrpIncRdByUIncludeIdx == null ) {
			rqstTSecGrpIncRdByUIncludeIdx = new CFSecXMsgRqstTSecGrpIncRdByUIncludeIdx( this );
		}
		return( rqstTSecGrpIncRdByUIncludeIdx );
	}

	protected CFSecXMsgRqstTSecGrpIncPageByTenantIdx getRqstTSecGrpIncPageByTenantIdx() {
		if( rqstTSecGrpIncPageByTenantIdx == null ) {
			rqstTSecGrpIncPageByTenantIdx = new CFSecXMsgRqstTSecGrpIncPageByTenantIdx( this );
		}
		return( rqstTSecGrpIncPageByTenantIdx );
	}

	protected CFSecXMsgRqstTSecGrpIncPageByGroupIdx getRqstTSecGrpIncPageByGroupIdx() {
		if( rqstTSecGrpIncPageByGroupIdx == null ) {
			rqstTSecGrpIncPageByGroupIdx = new CFSecXMsgRqstTSecGrpIncPageByGroupIdx( this );
		}
		return( rqstTSecGrpIncPageByGroupIdx );
	}

	protected CFSecXMsgRqstTSecGrpIncPageByIncludeIdx getRqstTSecGrpIncPageByIncludeIdx() {
		if( rqstTSecGrpIncPageByIncludeIdx == null ) {
			rqstTSecGrpIncPageByIncludeIdx = new CFSecXMsgRqstTSecGrpIncPageByIncludeIdx( this );
		}
		return( rqstTSecGrpIncPageByIncludeIdx );
	}

	protected CFSecXMsgRqstTSecGrpIncDelByTenantIdx getRqstTSecGrpIncDelByTenantIdx() {
		if( rqstTSecGrpIncDelByTenantIdx == null ) {
			rqstTSecGrpIncDelByTenantIdx = new CFSecXMsgRqstTSecGrpIncDelByTenantIdx( this );
		}
		return( rqstTSecGrpIncDelByTenantIdx );
	}

	protected CFSecXMsgRqstTSecGrpIncDelByGroupIdx getRqstTSecGrpIncDelByGroupIdx() {
		if( rqstTSecGrpIncDelByGroupIdx == null ) {
			rqstTSecGrpIncDelByGroupIdx = new CFSecXMsgRqstTSecGrpIncDelByGroupIdx( this );
		}
		return( rqstTSecGrpIncDelByGroupIdx );
	}

	protected CFSecXMsgRqstTSecGrpIncDelByIncludeIdx getRqstTSecGrpIncDelByIncludeIdx() {
		if( rqstTSecGrpIncDelByIncludeIdx == null ) {
			rqstTSecGrpIncDelByIncludeIdx = new CFSecXMsgRqstTSecGrpIncDelByIncludeIdx( this );
		}
		return( rqstTSecGrpIncDelByIncludeIdx );
	}

	protected CFSecXMsgRqstTSecGrpIncDelByUIncludeIdx getRqstTSecGrpIncDelByUIncludeIdx() {
		if( rqstTSecGrpIncDelByUIncludeIdx == null ) {
			rqstTSecGrpIncDelByUIncludeIdx = new CFSecXMsgRqstTSecGrpIncDelByUIncludeIdx( this );
		}
		return( rqstTSecGrpIncDelByUIncludeIdx );
	}

	// TSecGrpMemb Request  Factories

	protected CFSecXMsgRqstTSecGrpMembCreate getRqstTSecGrpMembCreate() {
		if( rqstTSecGrpMembCreate == null ) {
			rqstTSecGrpMembCreate = new CFSecXMsgRqstTSecGrpMembCreate( this );
		}
		return( rqstTSecGrpMembCreate );
	}

	protected CFSecXMsgRqstTSecGrpMembRead getRqstTSecGrpMembRead() {
		if( rqstTSecGrpMembRead == null ) {
			rqstTSecGrpMembRead = new CFSecXMsgRqstTSecGrpMembRead( this );
		}
		return( rqstTSecGrpMembRead );
	}

	protected CFSecXMsgRqstTSecGrpMembLock getRqstTSecGrpMembLock() {
		if( rqstTSecGrpMembLock == null ) {
			rqstTSecGrpMembLock = new CFSecXMsgRqstTSecGrpMembLock( this );
		}
		return( rqstTSecGrpMembLock );
	}

	protected CFSecXMsgRqstTSecGrpMembUpdate getRqstTSecGrpMembUpdate() {
		if( rqstTSecGrpMembUpdate == null ) {
			rqstTSecGrpMembUpdate = new CFSecXMsgRqstTSecGrpMembUpdate( this );
		}
		return( rqstTSecGrpMembUpdate );
	}

	protected CFSecXMsgRqstTSecGrpMembDelete getRqstTSecGrpMembDelete() {
		if( rqstTSecGrpMembDelete == null ) {
			rqstTSecGrpMembDelete = new CFSecXMsgRqstTSecGrpMembDelete( this );
		}
		return( rqstTSecGrpMembDelete );
	}

	protected CFSecXMsgRqstTSecGrpMembReadAll getRqstTSecGrpMembReadAll() {
		if( rqstTSecGrpMembReadAll == null ) {
			rqstTSecGrpMembReadAll = new CFSecXMsgRqstTSecGrpMembReadAll( this );
		}
		return( rqstTSecGrpMembReadAll );
	}

	protected CFSecXMsgRqstTSecGrpMembPageAll getRqstTSecGrpMembPageAll() {
		if( rqstTSecGrpMembPageAll == null ) {
			rqstTSecGrpMembPageAll = new CFSecXMsgRqstTSecGrpMembPageAll( this );
		}
		return( rqstTSecGrpMembPageAll );
	}

	protected CFSecXMsgRqstTSecGrpMembRdByTenantIdx getRqstTSecGrpMembRdByTenantIdx() {
		if( rqstTSecGrpMembRdByTenantIdx == null ) {
			rqstTSecGrpMembRdByTenantIdx = new CFSecXMsgRqstTSecGrpMembRdByTenantIdx( this );
		}
		return( rqstTSecGrpMembRdByTenantIdx );
	}

	protected CFSecXMsgRqstTSecGrpMembRdByGroupIdx getRqstTSecGrpMembRdByGroupIdx() {
		if( rqstTSecGrpMembRdByGroupIdx == null ) {
			rqstTSecGrpMembRdByGroupIdx = new CFSecXMsgRqstTSecGrpMembRdByGroupIdx( this );
		}
		return( rqstTSecGrpMembRdByGroupIdx );
	}

	protected CFSecXMsgRqstTSecGrpMembRdByUserIdx getRqstTSecGrpMembRdByUserIdx() {
		if( rqstTSecGrpMembRdByUserIdx == null ) {
			rqstTSecGrpMembRdByUserIdx = new CFSecXMsgRqstTSecGrpMembRdByUserIdx( this );
		}
		return( rqstTSecGrpMembRdByUserIdx );
	}

	protected CFSecXMsgRqstTSecGrpMembRdByUUserIdx getRqstTSecGrpMembRdByUUserIdx() {
		if( rqstTSecGrpMembRdByUUserIdx == null ) {
			rqstTSecGrpMembRdByUUserIdx = new CFSecXMsgRqstTSecGrpMembRdByUUserIdx( this );
		}
		return( rqstTSecGrpMembRdByUUserIdx );
	}

	protected CFSecXMsgRqstTSecGrpMembPageByTenantIdx getRqstTSecGrpMembPageByTenantIdx() {
		if( rqstTSecGrpMembPageByTenantIdx == null ) {
			rqstTSecGrpMembPageByTenantIdx = new CFSecXMsgRqstTSecGrpMembPageByTenantIdx( this );
		}
		return( rqstTSecGrpMembPageByTenantIdx );
	}

	protected CFSecXMsgRqstTSecGrpMembPageByGroupIdx getRqstTSecGrpMembPageByGroupIdx() {
		if( rqstTSecGrpMembPageByGroupIdx == null ) {
			rqstTSecGrpMembPageByGroupIdx = new CFSecXMsgRqstTSecGrpMembPageByGroupIdx( this );
		}
		return( rqstTSecGrpMembPageByGroupIdx );
	}

	protected CFSecXMsgRqstTSecGrpMembPageByUserIdx getRqstTSecGrpMembPageByUserIdx() {
		if( rqstTSecGrpMembPageByUserIdx == null ) {
			rqstTSecGrpMembPageByUserIdx = new CFSecXMsgRqstTSecGrpMembPageByUserIdx( this );
		}
		return( rqstTSecGrpMembPageByUserIdx );
	}

	protected CFSecXMsgRqstTSecGrpMembDelByTenantIdx getRqstTSecGrpMembDelByTenantIdx() {
		if( rqstTSecGrpMembDelByTenantIdx == null ) {
			rqstTSecGrpMembDelByTenantIdx = new CFSecXMsgRqstTSecGrpMembDelByTenantIdx( this );
		}
		return( rqstTSecGrpMembDelByTenantIdx );
	}

	protected CFSecXMsgRqstTSecGrpMembDelByGroupIdx getRqstTSecGrpMembDelByGroupIdx() {
		if( rqstTSecGrpMembDelByGroupIdx == null ) {
			rqstTSecGrpMembDelByGroupIdx = new CFSecXMsgRqstTSecGrpMembDelByGroupIdx( this );
		}
		return( rqstTSecGrpMembDelByGroupIdx );
	}

	protected CFSecXMsgRqstTSecGrpMembDelByUserIdx getRqstTSecGrpMembDelByUserIdx() {
		if( rqstTSecGrpMembDelByUserIdx == null ) {
			rqstTSecGrpMembDelByUserIdx = new CFSecXMsgRqstTSecGrpMembDelByUserIdx( this );
		}
		return( rqstTSecGrpMembDelByUserIdx );
	}

	protected CFSecXMsgRqstTSecGrpMembDelByUUserIdx getRqstTSecGrpMembDelByUUserIdx() {
		if( rqstTSecGrpMembDelByUUserIdx == null ) {
			rqstTSecGrpMembDelByUUserIdx = new CFSecXMsgRqstTSecGrpMembDelByUUserIdx( this );
		}
		return( rqstTSecGrpMembDelByUUserIdx );
	}

	// Tenant Request  Factories

	protected CFSecXMsgRqstTenantCreate getRqstTenantCreate() {
		if( rqstTenantCreate == null ) {
			rqstTenantCreate = new CFSecXMsgRqstTenantCreate( this );
		}
		return( rqstTenantCreate );
	}

	protected CFSecXMsgRqstTenantRead getRqstTenantRead() {
		if( rqstTenantRead == null ) {
			rqstTenantRead = new CFSecXMsgRqstTenantRead( this );
		}
		return( rqstTenantRead );
	}

	protected CFSecXMsgRqstTenantLock getRqstTenantLock() {
		if( rqstTenantLock == null ) {
			rqstTenantLock = new CFSecXMsgRqstTenantLock( this );
		}
		return( rqstTenantLock );
	}

	protected CFSecXMsgRqstTenantUpdate getRqstTenantUpdate() {
		if( rqstTenantUpdate == null ) {
			rqstTenantUpdate = new CFSecXMsgRqstTenantUpdate( this );
		}
		return( rqstTenantUpdate );
	}

	protected CFSecXMsgRqstTenantDelete getRqstTenantDelete() {
		if( rqstTenantDelete == null ) {
			rqstTenantDelete = new CFSecXMsgRqstTenantDelete( this );
		}
		return( rqstTenantDelete );
	}

	protected CFSecXMsgRqstTenantReadAll getRqstTenantReadAll() {
		if( rqstTenantReadAll == null ) {
			rqstTenantReadAll = new CFSecXMsgRqstTenantReadAll( this );
		}
		return( rqstTenantReadAll );
	}

	protected CFSecXMsgRqstTenantPageAll getRqstTenantPageAll() {
		if( rqstTenantPageAll == null ) {
			rqstTenantPageAll = new CFSecXMsgRqstTenantPageAll( this );
		}
		return( rqstTenantPageAll );
	}

	protected CFSecXMsgRqstTenantRdByClusterIdx getRqstTenantRdByClusterIdx() {
		if( rqstTenantRdByClusterIdx == null ) {
			rqstTenantRdByClusterIdx = new CFSecXMsgRqstTenantRdByClusterIdx( this );
		}
		return( rqstTenantRdByClusterIdx );
	}

	protected CFSecXMsgRqstTenantRdByUNameIdx getRqstTenantRdByUNameIdx() {
		if( rqstTenantRdByUNameIdx == null ) {
			rqstTenantRdByUNameIdx = new CFSecXMsgRqstTenantRdByUNameIdx( this );
		}
		return( rqstTenantRdByUNameIdx );
	}

	protected CFSecXMsgRqstTenantPageByClusterIdx getRqstTenantPageByClusterIdx() {
		if( rqstTenantPageByClusterIdx == null ) {
			rqstTenantPageByClusterIdx = new CFSecXMsgRqstTenantPageByClusterIdx( this );
		}
		return( rqstTenantPageByClusterIdx );
	}

	protected CFSecXMsgRqstTenantDelByClusterIdx getRqstTenantDelByClusterIdx() {
		if( rqstTenantDelByClusterIdx == null ) {
			rqstTenantDelByClusterIdx = new CFSecXMsgRqstTenantDelByClusterIdx( this );
		}
		return( rqstTenantDelByClusterIdx );
	}

	protected CFSecXMsgRqstTenantDelByUNameIdx getRqstTenantDelByUNameIdx() {
		if( rqstTenantDelByUNameIdx == null ) {
			rqstTenantDelByUNameIdx = new CFSecXMsgRqstTenantDelByUNameIdx( this );
		}
		return( rqstTenantDelByUNameIdx );
	}

	protected CFSecXMsgRqstFileImport getRqstFileImport() {
		if( rqstFileImport == null ) {
			rqstFileImport = new CFSecXMsgRqstFileImport( this );
		}
		return( rqstFileImport );
	}

	protected CFSecXMsgRqstLogIn getRqstLogIn() {
		if( rqstLogIn == null ) {
			rqstLogIn = new CFSecXMsgRqstLogIn( this );
		}
		return( rqstLogIn );
	}

	protected CFSecXMsgRqstLogOut getRqstLogOut() {
		if( rqstLogOut == null ) {
			rqstLogOut = new CFSecXMsgRqstLogOut( this );
		}
		return( rqstLogOut );
	}

	// Root Element  Resolver Factory

	protected CFSecSaxRqstRoot getSaxRqstRoot() {
		if( saxRoot == null ) {
			saxRoot = new CFSecSaxRqstRoot( this );
			saxRoot.addElementHandler( "CFSecRqst", getSaxRqstDoc() );
		}
		return( saxRoot );
	}

	// Root Element 

	/*
	 *	CFSecSaxRqstRoot XML SAX Root Element  implementation
	 */
	public class CFSecSaxRqstRoot
		extends CFLibXmlCoreElementHandler
	{
		public CFSecSaxRqstRoot( CFSecXMsgRqst xmsgRqst ) {
			super( xmsgRqst );
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

	protected void addClusterToSaxRqstDoc( CFSecSaxRqstDoc saxDoc ) {

			saxDoc.addElementHandler( "RqstClusterCreate", getRqstClusterCreate() );
			saxDoc.addElementHandler( "RqstClusterRead", getRqstClusterRead() );
			saxDoc.addElementHandler( "RqstClusterLock", getRqstClusterLock() );
			saxDoc.addElementHandler( "RqstClusterUpdate", getRqstClusterUpdate() );
			saxDoc.addElementHandler( "RqstClusterDelete", getRqstClusterDelete() );
			saxDoc.addElementHandler( "RqstClusterReadAll", getRqstClusterReadAll() );
			saxDoc.addElementHandler( "RqstClusterPageAll", getRqstClusterPageAll() );
			saxDoc.addElementHandler( "RqstClusterRdByUDomNameIdx", getRqstClusterRdByUDomNameIdx() );
			saxDoc.addElementHandler( "RqstClusterRdByUDescrIdx", getRqstClusterRdByUDescrIdx() );
			saxDoc.addElementHandler( "RqstClusterDelByUDomNameIdx", getRqstClusterDelByUDomNameIdx() );
			saxDoc.addElementHandler( "RqstClusterDelByUDescrIdx", getRqstClusterDelByUDescrIdx() );
	}

	protected void addHostNodeToSaxRqstDoc( CFSecSaxRqstDoc saxDoc ) {

			saxDoc.addElementHandler( "RqstHostNodeCreate", getRqstHostNodeCreate() );
			saxDoc.addElementHandler( "RqstHostNodeRead", getRqstHostNodeRead() );
			saxDoc.addElementHandler( "RqstHostNodeLock", getRqstHostNodeLock() );
			saxDoc.addElementHandler( "RqstHostNodeUpdate", getRqstHostNodeUpdate() );
			saxDoc.addElementHandler( "RqstHostNodeDelete", getRqstHostNodeDelete() );
			saxDoc.addElementHandler( "RqstHostNodeReadAll", getRqstHostNodeReadAll() );
			saxDoc.addElementHandler( "RqstHostNodePageAll", getRqstHostNodePageAll() );
			saxDoc.addElementHandler( "RqstHostNodeRdByClusterIdx", getRqstHostNodeRdByClusterIdx() );
			saxDoc.addElementHandler( "RqstHostNodeRdByUDescrIdx", getRqstHostNodeRdByUDescrIdx() );
			saxDoc.addElementHandler( "RqstHostNodeRdByHostNameIdx", getRqstHostNodeRdByHostNameIdx() );
			saxDoc.addElementHandler( "RqstHostNodePageByClusterIdx", getRqstHostNodePageByClusterIdx() );
			saxDoc.addElementHandler( "RqstHostNodeDelByClusterIdx", getRqstHostNodeDelByClusterIdx() );
			saxDoc.addElementHandler( "RqstHostNodeDelByUDescrIdx", getRqstHostNodeDelByUDescrIdx() );
			saxDoc.addElementHandler( "RqstHostNodeDelByHostNameIdx", getRqstHostNodeDelByHostNameIdx() );
	}

	protected void addISOCcyToSaxRqstDoc( CFSecSaxRqstDoc saxDoc ) {

			saxDoc.addElementHandler( "RqstISOCcyCreate", getRqstISOCcyCreate() );
			saxDoc.addElementHandler( "RqstISOCcyRead", getRqstISOCcyRead() );
			saxDoc.addElementHandler( "RqstISOCcyLock", getRqstISOCcyLock() );
			saxDoc.addElementHandler( "RqstISOCcyUpdate", getRqstISOCcyUpdate() );
			saxDoc.addElementHandler( "RqstISOCcyDelete", getRqstISOCcyDelete() );
			saxDoc.addElementHandler( "RqstISOCcyReadAll", getRqstISOCcyReadAll() );
			saxDoc.addElementHandler( "RqstISOCcyRdByCcyCdIdx", getRqstISOCcyRdByCcyCdIdx() );
			saxDoc.addElementHandler( "RqstISOCcyRdByCcyNmIdx", getRqstISOCcyRdByCcyNmIdx() );
			saxDoc.addElementHandler( "RqstISOCcyDelByCcyCdIdx", getRqstISOCcyDelByCcyCdIdx() );
			saxDoc.addElementHandler( "RqstISOCcyDelByCcyNmIdx", getRqstISOCcyDelByCcyNmIdx() );
	}

	protected void addISOCtryToSaxRqstDoc( CFSecSaxRqstDoc saxDoc ) {

			saxDoc.addElementHandler( "RqstISOCtryCreate", getRqstISOCtryCreate() );
			saxDoc.addElementHandler( "RqstISOCtryRead", getRqstISOCtryRead() );
			saxDoc.addElementHandler( "RqstISOCtryLock", getRqstISOCtryLock() );
			saxDoc.addElementHandler( "RqstISOCtryUpdate", getRqstISOCtryUpdate() );
			saxDoc.addElementHandler( "RqstISOCtryDelete", getRqstISOCtryDelete() );
			saxDoc.addElementHandler( "RqstISOCtryReadAll", getRqstISOCtryReadAll() );
			saxDoc.addElementHandler( "RqstISOCtryRdByISOCodeIdx", getRqstISOCtryRdByISOCodeIdx() );
			saxDoc.addElementHandler( "RqstISOCtryRdByNameIdx", getRqstISOCtryRdByNameIdx() );
			saxDoc.addElementHandler( "RqstISOCtryDelByISOCodeIdx", getRqstISOCtryDelByISOCodeIdx() );
			saxDoc.addElementHandler( "RqstISOCtryDelByNameIdx", getRqstISOCtryDelByNameIdx() );
	}

	protected void addISOCtryCcyToSaxRqstDoc( CFSecSaxRqstDoc saxDoc ) {

			saxDoc.addElementHandler( "RqstISOCtryCcyCreate", getRqstISOCtryCcyCreate() );
			saxDoc.addElementHandler( "RqstISOCtryCcyRead", getRqstISOCtryCcyRead() );
			saxDoc.addElementHandler( "RqstISOCtryCcyLock", getRqstISOCtryCcyLock() );
			saxDoc.addElementHandler( "RqstISOCtryCcyUpdate", getRqstISOCtryCcyUpdate() );
			saxDoc.addElementHandler( "RqstISOCtryCcyDelete", getRqstISOCtryCcyDelete() );
			saxDoc.addElementHandler( "RqstISOCtryCcyReadAll", getRqstISOCtryCcyReadAll() );
			saxDoc.addElementHandler( "RqstISOCtryCcyRdByCtryIdx", getRqstISOCtryCcyRdByCtryIdx() );
			saxDoc.addElementHandler( "RqstISOCtryCcyRdByCcyIdx", getRqstISOCtryCcyRdByCcyIdx() );
			saxDoc.addElementHandler( "RqstISOCtryCcyDelByCtryIdx", getRqstISOCtryCcyDelByCtryIdx() );
			saxDoc.addElementHandler( "RqstISOCtryCcyDelByCcyIdx", getRqstISOCtryCcyDelByCcyIdx() );
	}

	protected void addISOCtryLangToSaxRqstDoc( CFSecSaxRqstDoc saxDoc ) {

			saxDoc.addElementHandler( "RqstISOCtryLangCreate", getRqstISOCtryLangCreate() );
			saxDoc.addElementHandler( "RqstISOCtryLangRead", getRqstISOCtryLangRead() );
			saxDoc.addElementHandler( "RqstISOCtryLangLock", getRqstISOCtryLangLock() );
			saxDoc.addElementHandler( "RqstISOCtryLangUpdate", getRqstISOCtryLangUpdate() );
			saxDoc.addElementHandler( "RqstISOCtryLangDelete", getRqstISOCtryLangDelete() );
			saxDoc.addElementHandler( "RqstISOCtryLangReadAll", getRqstISOCtryLangReadAll() );
			saxDoc.addElementHandler( "RqstISOCtryLangRdByCtryIdx", getRqstISOCtryLangRdByCtryIdx() );
			saxDoc.addElementHandler( "RqstISOCtryLangRdByLangIdx", getRqstISOCtryLangRdByLangIdx() );
			saxDoc.addElementHandler( "RqstISOCtryLangDelByCtryIdx", getRqstISOCtryLangDelByCtryIdx() );
			saxDoc.addElementHandler( "RqstISOCtryLangDelByLangIdx", getRqstISOCtryLangDelByLangIdx() );
	}

	protected void addISOLangToSaxRqstDoc( CFSecSaxRqstDoc saxDoc ) {

			saxDoc.addElementHandler( "RqstISOLangCreate", getRqstISOLangCreate() );
			saxDoc.addElementHandler( "RqstISOLangRead", getRqstISOLangRead() );
			saxDoc.addElementHandler( "RqstISOLangLock", getRqstISOLangLock() );
			saxDoc.addElementHandler( "RqstISOLangUpdate", getRqstISOLangUpdate() );
			saxDoc.addElementHandler( "RqstISOLangDelete", getRqstISOLangDelete() );
			saxDoc.addElementHandler( "RqstISOLangReadAll", getRqstISOLangReadAll() );
			saxDoc.addElementHandler( "RqstISOLangRdByCode3Idx", getRqstISOLangRdByCode3Idx() );
			saxDoc.addElementHandler( "RqstISOLangRdByCode2Idx", getRqstISOLangRdByCode2Idx() );
			saxDoc.addElementHandler( "RqstISOLangDelByCode3Idx", getRqstISOLangDelByCode3Idx() );
			saxDoc.addElementHandler( "RqstISOLangDelByCode2Idx", getRqstISOLangDelByCode2Idx() );
	}

	protected void addISOTZoneToSaxRqstDoc( CFSecSaxRqstDoc saxDoc ) {

			saxDoc.addElementHandler( "RqstISOTZoneCreate", getRqstISOTZoneCreate() );
			saxDoc.addElementHandler( "RqstISOTZoneRead", getRqstISOTZoneRead() );
			saxDoc.addElementHandler( "RqstISOTZoneLock", getRqstISOTZoneLock() );
			saxDoc.addElementHandler( "RqstISOTZoneUpdate", getRqstISOTZoneUpdate() );
			saxDoc.addElementHandler( "RqstISOTZoneDelete", getRqstISOTZoneDelete() );
			saxDoc.addElementHandler( "RqstISOTZoneReadAll", getRqstISOTZoneReadAll() );
			saxDoc.addElementHandler( "RqstISOTZoneRdByOffsetIdx", getRqstISOTZoneRdByOffsetIdx() );
			saxDoc.addElementHandler( "RqstISOTZoneRdByUTZNameIdx", getRqstISOTZoneRdByUTZNameIdx() );
			saxDoc.addElementHandler( "RqstISOTZoneRdByIso8601Idx", getRqstISOTZoneRdByIso8601Idx() );
			saxDoc.addElementHandler( "RqstISOTZoneDelByOffsetIdx", getRqstISOTZoneDelByOffsetIdx() );
			saxDoc.addElementHandler( "RqstISOTZoneDelByUTZNameIdx", getRqstISOTZoneDelByUTZNameIdx() );
			saxDoc.addElementHandler( "RqstISOTZoneDelByIso8601Idx", getRqstISOTZoneDelByIso8601Idx() );
	}

	protected void addSecAppToSaxRqstDoc( CFSecSaxRqstDoc saxDoc ) {

			saxDoc.addElementHandler( "RqstSecAppCreate", getRqstSecAppCreate() );
			saxDoc.addElementHandler( "RqstSecAppRead", getRqstSecAppRead() );
			saxDoc.addElementHandler( "RqstSecAppLock", getRqstSecAppLock() );
			saxDoc.addElementHandler( "RqstSecAppUpdate", getRqstSecAppUpdate() );
			saxDoc.addElementHandler( "RqstSecAppDelete", getRqstSecAppDelete() );
			saxDoc.addElementHandler( "RqstSecAppReadAll", getRqstSecAppReadAll() );
			saxDoc.addElementHandler( "RqstSecAppPageAll", getRqstSecAppPageAll() );
			saxDoc.addElementHandler( "RqstSecAppRdByClusterIdx", getRqstSecAppRdByClusterIdx() );
			saxDoc.addElementHandler( "RqstSecAppRdByUJEEMountIdx", getRqstSecAppRdByUJEEMountIdx() );
			saxDoc.addElementHandler( "RqstSecAppPageByClusterIdx", getRqstSecAppPageByClusterIdx() );
			saxDoc.addElementHandler( "RqstSecAppDelByClusterIdx", getRqstSecAppDelByClusterIdx() );
			saxDoc.addElementHandler( "RqstSecAppDelByUJEEMountIdx", getRqstSecAppDelByUJEEMountIdx() );
	}

	protected void addSecDeviceToSaxRqstDoc( CFSecSaxRqstDoc saxDoc ) {

			saxDoc.addElementHandler( "RqstSecDeviceCreate", getRqstSecDeviceCreate() );
			saxDoc.addElementHandler( "RqstSecDeviceRead", getRqstSecDeviceRead() );
			saxDoc.addElementHandler( "RqstSecDeviceLock", getRqstSecDeviceLock() );
			saxDoc.addElementHandler( "RqstSecDeviceUpdate", getRqstSecDeviceUpdate() );
			saxDoc.addElementHandler( "RqstSecDeviceDelete", getRqstSecDeviceDelete() );
			saxDoc.addElementHandler( "RqstSecDeviceReadAll", getRqstSecDeviceReadAll() );
			saxDoc.addElementHandler( "RqstSecDevicePageAll", getRqstSecDevicePageAll() );
			saxDoc.addElementHandler( "RqstSecDeviceRdByNameIdx", getRqstSecDeviceRdByNameIdx() );
			saxDoc.addElementHandler( "RqstSecDeviceRdByUserIdx", getRqstSecDeviceRdByUserIdx() );
			saxDoc.addElementHandler( "RqstSecDevicePageByUserIdx", getRqstSecDevicePageByUserIdx() );
			saxDoc.addElementHandler( "RqstSecDeviceDelByNameIdx", getRqstSecDeviceDelByNameIdx() );
			saxDoc.addElementHandler( "RqstSecDeviceDelByUserIdx", getRqstSecDeviceDelByUserIdx() );
	}

	protected void addSecFormToSaxRqstDoc( CFSecSaxRqstDoc saxDoc ) {

			saxDoc.addElementHandler( "RqstSecFormCreate", getRqstSecFormCreate() );
			saxDoc.addElementHandler( "RqstSecFormRead", getRqstSecFormRead() );
			saxDoc.addElementHandler( "RqstSecFormLock", getRqstSecFormLock() );
			saxDoc.addElementHandler( "RqstSecFormUpdate", getRqstSecFormUpdate() );
			saxDoc.addElementHandler( "RqstSecFormDelete", getRqstSecFormDelete() );
			saxDoc.addElementHandler( "RqstSecFormReadAll", getRqstSecFormReadAll() );
			saxDoc.addElementHandler( "RqstSecFormPageAll", getRqstSecFormPageAll() );
			saxDoc.addElementHandler( "RqstSecFormRdByClusterIdx", getRqstSecFormRdByClusterIdx() );
			saxDoc.addElementHandler( "RqstSecFormRdBySecAppIdx", getRqstSecFormRdBySecAppIdx() );
			saxDoc.addElementHandler( "RqstSecFormRdByUJEEServletIdx", getRqstSecFormRdByUJEEServletIdx() );
			saxDoc.addElementHandler( "RqstSecFormPageByClusterIdx", getRqstSecFormPageByClusterIdx() );
			saxDoc.addElementHandler( "RqstSecFormPageBySecAppIdx", getRqstSecFormPageBySecAppIdx() );
			saxDoc.addElementHandler( "RqstSecFormDelByClusterIdx", getRqstSecFormDelByClusterIdx() );
			saxDoc.addElementHandler( "RqstSecFormDelBySecAppIdx", getRqstSecFormDelBySecAppIdx() );
			saxDoc.addElementHandler( "RqstSecFormDelByUJEEServletIdx", getRqstSecFormDelByUJEEServletIdx() );
	}

	protected void addSecGroupToSaxRqstDoc( CFSecSaxRqstDoc saxDoc ) {

			saxDoc.addElementHandler( "RqstSecGroupCreate", getRqstSecGroupCreate() );
			saxDoc.addElementHandler( "RqstSecGroupRead", getRqstSecGroupRead() );
			saxDoc.addElementHandler( "RqstSecGroupLock", getRqstSecGroupLock() );
			saxDoc.addElementHandler( "RqstSecGroupUpdate", getRqstSecGroupUpdate() );
			saxDoc.addElementHandler( "RqstSecGroupDelete", getRqstSecGroupDelete() );
			saxDoc.addElementHandler( "RqstSecGroupReadAll", getRqstSecGroupReadAll() );
			saxDoc.addElementHandler( "RqstSecGroupRdByClusterIdx", getRqstSecGroupRdByClusterIdx() );
			saxDoc.addElementHandler( "RqstSecGroupRdByClusterVisIdx", getRqstSecGroupRdByClusterVisIdx() );
			saxDoc.addElementHandler( "RqstSecGroupRdByUNameIdx", getRqstSecGroupRdByUNameIdx() );
			saxDoc.addElementHandler( "RqstSecGroupDelByClusterIdx", getRqstSecGroupDelByClusterIdx() );
			saxDoc.addElementHandler( "RqstSecGroupDelByClusterVisIdx", getRqstSecGroupDelByClusterVisIdx() );
			saxDoc.addElementHandler( "RqstSecGroupDelByUNameIdx", getRqstSecGroupDelByUNameIdx() );
	}

	protected void addSecGroupFormToSaxRqstDoc( CFSecSaxRqstDoc saxDoc ) {

			saxDoc.addElementHandler( "RqstSecGroupFormCreate", getRqstSecGroupFormCreate() );
			saxDoc.addElementHandler( "RqstSecGroupFormRead", getRqstSecGroupFormRead() );
			saxDoc.addElementHandler( "RqstSecGroupFormLock", getRqstSecGroupFormLock() );
			saxDoc.addElementHandler( "RqstSecGroupFormUpdate", getRqstSecGroupFormUpdate() );
			saxDoc.addElementHandler( "RqstSecGroupFormDelete", getRqstSecGroupFormDelete() );
			saxDoc.addElementHandler( "RqstSecGroupFormReadAll", getRqstSecGroupFormReadAll() );
			saxDoc.addElementHandler( "RqstSecGroupFormPageAll", getRqstSecGroupFormPageAll() );
			saxDoc.addElementHandler( "RqstSecGroupFormRdByClusterIdx", getRqstSecGroupFormRdByClusterIdx() );
			saxDoc.addElementHandler( "RqstSecGroupFormRdByGroupIdx", getRqstSecGroupFormRdByGroupIdx() );
			saxDoc.addElementHandler( "RqstSecGroupFormRdByAppIdx", getRqstSecGroupFormRdByAppIdx() );
			saxDoc.addElementHandler( "RqstSecGroupFormRdByFormIdx", getRqstSecGroupFormRdByFormIdx() );
			saxDoc.addElementHandler( "RqstSecGroupFormRdByUFormIdx", getRqstSecGroupFormRdByUFormIdx() );
			saxDoc.addElementHandler( "RqstSecGroupFormPageByClusterIdx", getRqstSecGroupFormPageByClusterIdx() );
			saxDoc.addElementHandler( "RqstSecGroupFormPageByGroupIdx", getRqstSecGroupFormPageByGroupIdx() );
			saxDoc.addElementHandler( "RqstSecGroupFormPageByAppIdx", getRqstSecGroupFormPageByAppIdx() );
			saxDoc.addElementHandler( "RqstSecGroupFormPageByFormIdx", getRqstSecGroupFormPageByFormIdx() );
			saxDoc.addElementHandler( "RqstSecGroupFormDelByClusterIdx", getRqstSecGroupFormDelByClusterIdx() );
			saxDoc.addElementHandler( "RqstSecGroupFormDelByGroupIdx", getRqstSecGroupFormDelByGroupIdx() );
			saxDoc.addElementHandler( "RqstSecGroupFormDelByAppIdx", getRqstSecGroupFormDelByAppIdx() );
			saxDoc.addElementHandler( "RqstSecGroupFormDelByFormIdx", getRqstSecGroupFormDelByFormIdx() );
			saxDoc.addElementHandler( "RqstSecGroupFormDelByUFormIdx", getRqstSecGroupFormDelByUFormIdx() );
	}

	protected void addSecGrpIncToSaxRqstDoc( CFSecSaxRqstDoc saxDoc ) {

			saxDoc.addElementHandler( "RqstSecGrpIncCreate", getRqstSecGrpIncCreate() );
			saxDoc.addElementHandler( "RqstSecGrpIncRead", getRqstSecGrpIncRead() );
			saxDoc.addElementHandler( "RqstSecGrpIncLock", getRqstSecGrpIncLock() );
			saxDoc.addElementHandler( "RqstSecGrpIncUpdate", getRqstSecGrpIncUpdate() );
			saxDoc.addElementHandler( "RqstSecGrpIncDelete", getRqstSecGrpIncDelete() );
			saxDoc.addElementHandler( "RqstSecGrpIncReadAll", getRqstSecGrpIncReadAll() );
			saxDoc.addElementHandler( "RqstSecGrpIncPageAll", getRqstSecGrpIncPageAll() );
			saxDoc.addElementHandler( "RqstSecGrpIncRdByClusterIdx", getRqstSecGrpIncRdByClusterIdx() );
			saxDoc.addElementHandler( "RqstSecGrpIncRdByGroupIdx", getRqstSecGrpIncRdByGroupIdx() );
			saxDoc.addElementHandler( "RqstSecGrpIncRdByIncludeIdx", getRqstSecGrpIncRdByIncludeIdx() );
			saxDoc.addElementHandler( "RqstSecGrpIncRdByUIncludeIdx", getRqstSecGrpIncRdByUIncludeIdx() );
			saxDoc.addElementHandler( "RqstSecGrpIncPageByClusterIdx", getRqstSecGrpIncPageByClusterIdx() );
			saxDoc.addElementHandler( "RqstSecGrpIncPageByGroupIdx", getRqstSecGrpIncPageByGroupIdx() );
			saxDoc.addElementHandler( "RqstSecGrpIncPageByIncludeIdx", getRqstSecGrpIncPageByIncludeIdx() );
			saxDoc.addElementHandler( "RqstSecGrpIncDelByClusterIdx", getRqstSecGrpIncDelByClusterIdx() );
			saxDoc.addElementHandler( "RqstSecGrpIncDelByGroupIdx", getRqstSecGrpIncDelByGroupIdx() );
			saxDoc.addElementHandler( "RqstSecGrpIncDelByIncludeIdx", getRqstSecGrpIncDelByIncludeIdx() );
			saxDoc.addElementHandler( "RqstSecGrpIncDelByUIncludeIdx", getRqstSecGrpIncDelByUIncludeIdx() );
	}

	protected void addSecGrpMembToSaxRqstDoc( CFSecSaxRqstDoc saxDoc ) {

			saxDoc.addElementHandler( "RqstSecGrpMembCreate", getRqstSecGrpMembCreate() );
			saxDoc.addElementHandler( "RqstSecGrpMembRead", getRqstSecGrpMembRead() );
			saxDoc.addElementHandler( "RqstSecGrpMembLock", getRqstSecGrpMembLock() );
			saxDoc.addElementHandler( "RqstSecGrpMembUpdate", getRqstSecGrpMembUpdate() );
			saxDoc.addElementHandler( "RqstSecGrpMembDelete", getRqstSecGrpMembDelete() );
			saxDoc.addElementHandler( "RqstSecGrpMembReadAll", getRqstSecGrpMembReadAll() );
			saxDoc.addElementHandler( "RqstSecGrpMembPageAll", getRqstSecGrpMembPageAll() );
			saxDoc.addElementHandler( "RqstSecGrpMembRdByClusterIdx", getRqstSecGrpMembRdByClusterIdx() );
			saxDoc.addElementHandler( "RqstSecGrpMembRdByGroupIdx", getRqstSecGrpMembRdByGroupIdx() );
			saxDoc.addElementHandler( "RqstSecGrpMembRdByUserIdx", getRqstSecGrpMembRdByUserIdx() );
			saxDoc.addElementHandler( "RqstSecGrpMembRdByUUserIdx", getRqstSecGrpMembRdByUUserIdx() );
			saxDoc.addElementHandler( "RqstSecGrpMembPageByClusterIdx", getRqstSecGrpMembPageByClusterIdx() );
			saxDoc.addElementHandler( "RqstSecGrpMembPageByGroupIdx", getRqstSecGrpMembPageByGroupIdx() );
			saxDoc.addElementHandler( "RqstSecGrpMembPageByUserIdx", getRqstSecGrpMembPageByUserIdx() );
			saxDoc.addElementHandler( "RqstSecGrpMembDelByClusterIdx", getRqstSecGrpMembDelByClusterIdx() );
			saxDoc.addElementHandler( "RqstSecGrpMembDelByGroupIdx", getRqstSecGrpMembDelByGroupIdx() );
			saxDoc.addElementHandler( "RqstSecGrpMembDelByUserIdx", getRqstSecGrpMembDelByUserIdx() );
			saxDoc.addElementHandler( "RqstSecGrpMembDelByUUserIdx", getRqstSecGrpMembDelByUUserIdx() );
	}

	protected void addSecSessionToSaxRqstDoc( CFSecSaxRqstDoc saxDoc ) {

			saxDoc.addElementHandler( "RqstSecSessionCreate", getRqstSecSessionCreate() );
			saxDoc.addElementHandler( "RqstSecSessionRead", getRqstSecSessionRead() );
			saxDoc.addElementHandler( "RqstSecSessionLock", getRqstSecSessionLock() );
			saxDoc.addElementHandler( "RqstSecSessionUpdate", getRqstSecSessionUpdate() );
			saxDoc.addElementHandler( "RqstSecSessionDelete", getRqstSecSessionDelete() );
			saxDoc.addElementHandler( "RqstSecSessionReadAll", getRqstSecSessionReadAll() );
			saxDoc.addElementHandler( "RqstSecSessionPageAll", getRqstSecSessionPageAll() );
			saxDoc.addElementHandler( "RqstSecSessionRdBySecUserIdx", getRqstSecSessionRdBySecUserIdx() );
			saxDoc.addElementHandler( "RqstSecSessionRdBySecDevIdx", getRqstSecSessionRdBySecDevIdx() );
			saxDoc.addElementHandler( "RqstSecSessionRdByStartIdx", getRqstSecSessionRdByStartIdx() );
			saxDoc.addElementHandler( "RqstSecSessionRdByFinishIdx", getRqstSecSessionRdByFinishIdx() );
			saxDoc.addElementHandler( "RqstSecSessionRdBySecProxyIdx", getRqstSecSessionRdBySecProxyIdx() );
			saxDoc.addElementHandler( "RqstSecSessionPageBySecUserIdx", getRqstSecSessionPageBySecUserIdx() );
			saxDoc.addElementHandler( "RqstSecSessionPageBySecDevIdx", getRqstSecSessionPageBySecDevIdx() );
			saxDoc.addElementHandler( "RqstSecSessionPageByFinishIdx", getRqstSecSessionPageByFinishIdx() );
			saxDoc.addElementHandler( "RqstSecSessionPageBySecProxyIdx", getRqstSecSessionPageBySecProxyIdx() );
			saxDoc.addElementHandler( "RqstSecSessionDelBySecUserIdx", getRqstSecSessionDelBySecUserIdx() );
			saxDoc.addElementHandler( "RqstSecSessionDelBySecDevIdx", getRqstSecSessionDelBySecDevIdx() );
			saxDoc.addElementHandler( "RqstSecSessionDelByStartIdx", getRqstSecSessionDelByStartIdx() );
			saxDoc.addElementHandler( "RqstSecSessionDelByFinishIdx", getRqstSecSessionDelByFinishIdx() );
			saxDoc.addElementHandler( "RqstSecSessionDelBySecProxyIdx", getRqstSecSessionDelBySecProxyIdx() );
	}

	protected void addSecUserToSaxRqstDoc( CFSecSaxRqstDoc saxDoc ) {

			saxDoc.addElementHandler( "RqstSecUserCreate", getRqstSecUserCreate() );
			saxDoc.addElementHandler( "RqstSecUserRead", getRqstSecUserRead() );
			saxDoc.addElementHandler( "RqstSecUserLock", getRqstSecUserLock() );
			saxDoc.addElementHandler( "RqstSecUserUpdate", getRqstSecUserUpdate() );
			saxDoc.addElementHandler( "RqstSecUserDelete", getRqstSecUserDelete() );
			saxDoc.addElementHandler( "RqstSecUserReadAll", getRqstSecUserReadAll() );
			saxDoc.addElementHandler( "RqstSecUserPageAll", getRqstSecUserPageAll() );
			saxDoc.addElementHandler( "RqstSecUserRdByULoginIdx", getRqstSecUserRdByULoginIdx() );
			saxDoc.addElementHandler( "RqstSecUserRdByEMConfIdx", getRqstSecUserRdByEMConfIdx() );
			saxDoc.addElementHandler( "RqstSecUserRdByPwdResetIdx", getRqstSecUserRdByPwdResetIdx() );
			saxDoc.addElementHandler( "RqstSecUserRdByDefDevIdx", getRqstSecUserRdByDefDevIdx() );
			saxDoc.addElementHandler( "RqstSecUserPageByEMConfIdx", getRqstSecUserPageByEMConfIdx() );
			saxDoc.addElementHandler( "RqstSecUserPageByPwdResetIdx", getRqstSecUserPageByPwdResetIdx() );
			saxDoc.addElementHandler( "RqstSecUserPageByDefDevIdx", getRqstSecUserPageByDefDevIdx() );
			saxDoc.addElementHandler( "RqstSecUserDelByULoginIdx", getRqstSecUserDelByULoginIdx() );
			saxDoc.addElementHandler( "RqstSecUserDelByEMConfIdx", getRqstSecUserDelByEMConfIdx() );
			saxDoc.addElementHandler( "RqstSecUserDelByPwdResetIdx", getRqstSecUserDelByPwdResetIdx() );
			saxDoc.addElementHandler( "RqstSecUserDelByDefDevIdx", getRqstSecUserDelByDefDevIdx() );
	}

	protected void addServiceToSaxRqstDoc( CFSecSaxRqstDoc saxDoc ) {

			saxDoc.addElementHandler( "RqstServiceCreate", getRqstServiceCreate() );
			saxDoc.addElementHandler( "RqstServiceRead", getRqstServiceRead() );
			saxDoc.addElementHandler( "RqstServiceLock", getRqstServiceLock() );
			saxDoc.addElementHandler( "RqstServiceUpdate", getRqstServiceUpdate() );
			saxDoc.addElementHandler( "RqstServiceDelete", getRqstServiceDelete() );
			saxDoc.addElementHandler( "RqstServiceReadAll", getRqstServiceReadAll() );
			saxDoc.addElementHandler( "RqstServicePageAll", getRqstServicePageAll() );
			saxDoc.addElementHandler( "RqstServiceRdByClusterIdx", getRqstServiceRdByClusterIdx() );
			saxDoc.addElementHandler( "RqstServiceRdByHostIdx", getRqstServiceRdByHostIdx() );
			saxDoc.addElementHandler( "RqstServiceRdByTypeIdx", getRqstServiceRdByTypeIdx() );
			saxDoc.addElementHandler( "RqstServiceRdByUTypeIdx", getRqstServiceRdByUTypeIdx() );
			saxDoc.addElementHandler( "RqstServiceRdByUHostPortIdx", getRqstServiceRdByUHostPortIdx() );
			saxDoc.addElementHandler( "RqstServicePageByClusterIdx", getRqstServicePageByClusterIdx() );
			saxDoc.addElementHandler( "RqstServicePageByHostIdx", getRqstServicePageByHostIdx() );
			saxDoc.addElementHandler( "RqstServicePageByTypeIdx", getRqstServicePageByTypeIdx() );
			saxDoc.addElementHandler( "RqstServiceDelByClusterIdx", getRqstServiceDelByClusterIdx() );
			saxDoc.addElementHandler( "RqstServiceDelByHostIdx", getRqstServiceDelByHostIdx() );
			saxDoc.addElementHandler( "RqstServiceDelByTypeIdx", getRqstServiceDelByTypeIdx() );
			saxDoc.addElementHandler( "RqstServiceDelByUTypeIdx", getRqstServiceDelByUTypeIdx() );
			saxDoc.addElementHandler( "RqstServiceDelByUHostPortIdx", getRqstServiceDelByUHostPortIdx() );
	}

	protected void addServiceTypeToSaxRqstDoc( CFSecSaxRqstDoc saxDoc ) {

			saxDoc.addElementHandler( "RqstServiceTypeCreate", getRqstServiceTypeCreate() );
			saxDoc.addElementHandler( "RqstServiceTypeRead", getRqstServiceTypeRead() );
			saxDoc.addElementHandler( "RqstServiceTypeLock", getRqstServiceTypeLock() );
			saxDoc.addElementHandler( "RqstServiceTypeUpdate", getRqstServiceTypeUpdate() );
			saxDoc.addElementHandler( "RqstServiceTypeDelete", getRqstServiceTypeDelete() );
			saxDoc.addElementHandler( "RqstServiceTypeReadAll", getRqstServiceTypeReadAll() );
			saxDoc.addElementHandler( "RqstServiceTypeRdByUDescrIdx", getRqstServiceTypeRdByUDescrIdx() );
			saxDoc.addElementHandler( "RqstServiceTypeDelByUDescrIdx", getRqstServiceTypeDelByUDescrIdx() );
	}

	protected void addSysClusterToSaxRqstDoc( CFSecSaxRqstDoc saxDoc ) {

			saxDoc.addElementHandler( "RqstSysClusterCreate", getRqstSysClusterCreate() );
			saxDoc.addElementHandler( "RqstSysClusterRead", getRqstSysClusterRead() );
			saxDoc.addElementHandler( "RqstSysClusterLock", getRqstSysClusterLock() );
			saxDoc.addElementHandler( "RqstSysClusterUpdate", getRqstSysClusterUpdate() );
			saxDoc.addElementHandler( "RqstSysClusterDelete", getRqstSysClusterDelete() );
			saxDoc.addElementHandler( "RqstSysClusterReadAll", getRqstSysClusterReadAll() );
			saxDoc.addElementHandler( "RqstSysClusterRdByClusterIdx", getRqstSysClusterRdByClusterIdx() );
			saxDoc.addElementHandler( "RqstSysClusterDelByClusterIdx", getRqstSysClusterDelByClusterIdx() );
	}

	protected void addTSecGroupToSaxRqstDoc( CFSecSaxRqstDoc saxDoc ) {

			saxDoc.addElementHandler( "RqstTSecGroupCreate", getRqstTSecGroupCreate() );
			saxDoc.addElementHandler( "RqstTSecGroupRead", getRqstTSecGroupRead() );
			saxDoc.addElementHandler( "RqstTSecGroupLock", getRqstTSecGroupLock() );
			saxDoc.addElementHandler( "RqstTSecGroupUpdate", getRqstTSecGroupUpdate() );
			saxDoc.addElementHandler( "RqstTSecGroupDelete", getRqstTSecGroupDelete() );
			saxDoc.addElementHandler( "RqstTSecGroupReadAll", getRqstTSecGroupReadAll() );
			saxDoc.addElementHandler( "RqstTSecGroupRdByTenantIdx", getRqstTSecGroupRdByTenantIdx() );
			saxDoc.addElementHandler( "RqstTSecGroupRdByTenantVisIdx", getRqstTSecGroupRdByTenantVisIdx() );
			saxDoc.addElementHandler( "RqstTSecGroupRdByUNameIdx", getRqstTSecGroupRdByUNameIdx() );
			saxDoc.addElementHandler( "RqstTSecGroupDelByTenantIdx", getRqstTSecGroupDelByTenantIdx() );
			saxDoc.addElementHandler( "RqstTSecGroupDelByTenantVisIdx", getRqstTSecGroupDelByTenantVisIdx() );
			saxDoc.addElementHandler( "RqstTSecGroupDelByUNameIdx", getRqstTSecGroupDelByUNameIdx() );
	}

	protected void addTSecGrpIncToSaxRqstDoc( CFSecSaxRqstDoc saxDoc ) {

			saxDoc.addElementHandler( "RqstTSecGrpIncCreate", getRqstTSecGrpIncCreate() );
			saxDoc.addElementHandler( "RqstTSecGrpIncRead", getRqstTSecGrpIncRead() );
			saxDoc.addElementHandler( "RqstTSecGrpIncLock", getRqstTSecGrpIncLock() );
			saxDoc.addElementHandler( "RqstTSecGrpIncUpdate", getRqstTSecGrpIncUpdate() );
			saxDoc.addElementHandler( "RqstTSecGrpIncDelete", getRqstTSecGrpIncDelete() );
			saxDoc.addElementHandler( "RqstTSecGrpIncReadAll", getRqstTSecGrpIncReadAll() );
			saxDoc.addElementHandler( "RqstTSecGrpIncPageAll", getRqstTSecGrpIncPageAll() );
			saxDoc.addElementHandler( "RqstTSecGrpIncRdByTenantIdx", getRqstTSecGrpIncRdByTenantIdx() );
			saxDoc.addElementHandler( "RqstTSecGrpIncRdByGroupIdx", getRqstTSecGrpIncRdByGroupIdx() );
			saxDoc.addElementHandler( "RqstTSecGrpIncRdByIncludeIdx", getRqstTSecGrpIncRdByIncludeIdx() );
			saxDoc.addElementHandler( "RqstTSecGrpIncRdByUIncludeIdx", getRqstTSecGrpIncRdByUIncludeIdx() );
			saxDoc.addElementHandler( "RqstTSecGrpIncPageByTenantIdx", getRqstTSecGrpIncPageByTenantIdx() );
			saxDoc.addElementHandler( "RqstTSecGrpIncPageByGroupIdx", getRqstTSecGrpIncPageByGroupIdx() );
			saxDoc.addElementHandler( "RqstTSecGrpIncPageByIncludeIdx", getRqstTSecGrpIncPageByIncludeIdx() );
			saxDoc.addElementHandler( "RqstTSecGrpIncDelByTenantIdx", getRqstTSecGrpIncDelByTenantIdx() );
			saxDoc.addElementHandler( "RqstTSecGrpIncDelByGroupIdx", getRqstTSecGrpIncDelByGroupIdx() );
			saxDoc.addElementHandler( "RqstTSecGrpIncDelByIncludeIdx", getRqstTSecGrpIncDelByIncludeIdx() );
			saxDoc.addElementHandler( "RqstTSecGrpIncDelByUIncludeIdx", getRqstTSecGrpIncDelByUIncludeIdx() );
	}

	protected void addTSecGrpMembToSaxRqstDoc( CFSecSaxRqstDoc saxDoc ) {

			saxDoc.addElementHandler( "RqstTSecGrpMembCreate", getRqstTSecGrpMembCreate() );
			saxDoc.addElementHandler( "RqstTSecGrpMembRead", getRqstTSecGrpMembRead() );
			saxDoc.addElementHandler( "RqstTSecGrpMembLock", getRqstTSecGrpMembLock() );
			saxDoc.addElementHandler( "RqstTSecGrpMembUpdate", getRqstTSecGrpMembUpdate() );
			saxDoc.addElementHandler( "RqstTSecGrpMembDelete", getRqstTSecGrpMembDelete() );
			saxDoc.addElementHandler( "RqstTSecGrpMembReadAll", getRqstTSecGrpMembReadAll() );
			saxDoc.addElementHandler( "RqstTSecGrpMembPageAll", getRqstTSecGrpMembPageAll() );
			saxDoc.addElementHandler( "RqstTSecGrpMembRdByTenantIdx", getRqstTSecGrpMembRdByTenantIdx() );
			saxDoc.addElementHandler( "RqstTSecGrpMembRdByGroupIdx", getRqstTSecGrpMembRdByGroupIdx() );
			saxDoc.addElementHandler( "RqstTSecGrpMembRdByUserIdx", getRqstTSecGrpMembRdByUserIdx() );
			saxDoc.addElementHandler( "RqstTSecGrpMembRdByUUserIdx", getRqstTSecGrpMembRdByUUserIdx() );
			saxDoc.addElementHandler( "RqstTSecGrpMembPageByTenantIdx", getRqstTSecGrpMembPageByTenantIdx() );
			saxDoc.addElementHandler( "RqstTSecGrpMembPageByGroupIdx", getRqstTSecGrpMembPageByGroupIdx() );
			saxDoc.addElementHandler( "RqstTSecGrpMembPageByUserIdx", getRqstTSecGrpMembPageByUserIdx() );
			saxDoc.addElementHandler( "RqstTSecGrpMembDelByTenantIdx", getRqstTSecGrpMembDelByTenantIdx() );
			saxDoc.addElementHandler( "RqstTSecGrpMembDelByGroupIdx", getRqstTSecGrpMembDelByGroupIdx() );
			saxDoc.addElementHandler( "RqstTSecGrpMembDelByUserIdx", getRqstTSecGrpMembDelByUserIdx() );
			saxDoc.addElementHandler( "RqstTSecGrpMembDelByUUserIdx", getRqstTSecGrpMembDelByUUserIdx() );
	}

	protected void addTenantToSaxRqstDoc( CFSecSaxRqstDoc saxDoc ) {

			saxDoc.addElementHandler( "RqstTenantCreate", getRqstTenantCreate() );
			saxDoc.addElementHandler( "RqstTenantRead", getRqstTenantRead() );
			saxDoc.addElementHandler( "RqstTenantLock", getRqstTenantLock() );
			saxDoc.addElementHandler( "RqstTenantUpdate", getRqstTenantUpdate() );
			saxDoc.addElementHandler( "RqstTenantDelete", getRqstTenantDelete() );
			saxDoc.addElementHandler( "RqstTenantReadAll", getRqstTenantReadAll() );
			saxDoc.addElementHandler( "RqstTenantPageAll", getRqstTenantPageAll() );
			saxDoc.addElementHandler( "RqstTenantRdByClusterIdx", getRqstTenantRdByClusterIdx() );
			saxDoc.addElementHandler( "RqstTenantRdByUNameIdx", getRqstTenantRdByUNameIdx() );
			saxDoc.addElementHandler( "RqstTenantPageByClusterIdx", getRqstTenantPageByClusterIdx() );
			saxDoc.addElementHandler( "RqstTenantDelByClusterIdx", getRqstTenantDelByClusterIdx() );
			saxDoc.addElementHandler( "RqstTenantDelByUNameIdx", getRqstTenantDelByUNameIdx() );
	}

	protected CFSecSaxRqstDoc getSaxRqstDoc() {
		if( saxDoc == null ) {
			saxDoc = new CFSecSaxRqstDoc( this );

			addClusterToSaxRqstDoc( saxDoc );
			addHostNodeToSaxRqstDoc( saxDoc );
			addISOCcyToSaxRqstDoc( saxDoc );
			addISOCtryToSaxRqstDoc( saxDoc );
			addISOCtryCcyToSaxRqstDoc( saxDoc );
			addISOCtryLangToSaxRqstDoc( saxDoc );
			addISOLangToSaxRqstDoc( saxDoc );
			addISOTZoneToSaxRqstDoc( saxDoc );
			addSecAppToSaxRqstDoc( saxDoc );
			addSecDeviceToSaxRqstDoc( saxDoc );
			addSecFormToSaxRqstDoc( saxDoc );
			addSecGroupToSaxRqstDoc( saxDoc );
			addSecGroupFormToSaxRqstDoc( saxDoc );
			addSecGrpIncToSaxRqstDoc( saxDoc );
			addSecGrpMembToSaxRqstDoc( saxDoc );
			addSecSessionToSaxRqstDoc( saxDoc );
			addSecUserToSaxRqstDoc( saxDoc );
			addServiceToSaxRqstDoc( saxDoc );
			addServiceTypeToSaxRqstDoc( saxDoc );
			addSysClusterToSaxRqstDoc( saxDoc );
			addTSecGroupToSaxRqstDoc( saxDoc );
			addTSecGrpIncToSaxRqstDoc( saxDoc );
			addTSecGrpMembToSaxRqstDoc( saxDoc );
			addTenantToSaxRqstDoc( saxDoc );
			saxDoc.addElementHandler( "RqstFileImport", getRqstFileImport() );
			saxDoc.addElementHandler( "RqstLogIn", getRqstLogIn() );
			saxDoc.addElementHandler( "RqstLogOut", getRqstLogOut() );		}
		return( saxDoc );
	}

	// Document Element 

	/*
	 *	CFSecSaxRqstDoc XML SAX Doc Element  implementation
	 */
	public class CFSecSaxRqstDoc
		extends CFLibXmlCoreElementHandler
	{
		public CFSecSaxRqstDoc( CFSecXMsgRqst xmsgRqst ) {
			super( xmsgRqst );
		}

		public void startElement(
			String		uri,
			String		localName,
			String		qName,
			Attributes	attrs )
		throws SAXException
		{
			String effSchemaName;
			if( qName.endsWith( "Rqst" ) ) {
				effSchemaName = qName.substring( 0, qName.length() - 4 );
			}
			else {
				effSchemaName = "CFSec";
			}
			CFSecXMsgRqst xmsgRqst = ((CFSecXMsgRqst)getParser());
			CFSecXMsgSchemaMessageFormatter schemaFormatter = xmsgRqst.getSchemaMessageFormatter();
			schemaFormatter.setMessageNamespace( effSchemaName );
		}

		public void endElement(
			String		uri,
			String		localName,
			String		qName )
		throws SAXException
		{
		}
	}

	// Parse XML string contents

	public void parseStringContents( String str ) {
		final String S_ProcName = "parseStringContents";
		resetResponse();
		CFSecAuthorization auth = schemaObj.getAuthorization();
		if( ( auth != null ) && schemaObj.isTransactionOpen() ) {
			try {
				schemaObj.rollback();
			}
			catch( RuntimeException x ) {
			}
		}
		boolean transactionOpened = false;
		try {
			if( auth != null ) {
				transactionOpened = schemaObj.beginTransaction();
			}
			else {
				transactionOpened = false;
			}

			super.parseStringContents( str );

			// If the request was a logout or login the authorization will have changed
			auth = schemaObj.getAuthorization();
			if( auth != null ) {
				try {
					if( caughtException ) {
						schemaObj.rollback();
					}
					else {
						schemaObj.commit();
					}
				}
				catch( RuntimeException e ) {
				}
			}

			transactionOpened = false;
		}
		catch( CFLibArgumentOverflowException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibArgumentRangeException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibArgumentUnderflowException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibCollisionDetectedException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibDbException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibDependentsDetectedException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibEmptyArgumentException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibInvalidArgumentException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibMustOverrideException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibNotImplementedYetException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibNotSupportedException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibNullArgumentException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibPrimaryKeyNotNewException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibStaleCacheDetectedException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibUniqueIndexViolationException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibUnrecognizedAttributeException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibUnresolvedRelationException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibUnsupportedClassException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibUsageException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibArgumentException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibRuntimeException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( RuntimeException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				e.getMessage(),
				e );
		}
		catch( Exception e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				e.getMessage(),
				e );
		}
	}

	// Parse a URL

	public void parse( String url ) {
		final String S_ProcName = "parse";
		resetResponse();
		if( schemaObj.isTransactionOpen() ) {
			try {
				schemaObj.rollback();
			}
			catch( RuntimeException x ) {
			}
		}
		boolean transactionOpened = false;
		try {
			transactionOpened = schemaObj.beginTransaction();

			super.parse( url );

			if( caughtException ) {
				schemaObj.rollback();
			}
			else {
				schemaObj.commit();
			}

			transactionOpened = false;
		}
		catch( CFLibArgumentOverflowException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibArgumentRangeException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibArgumentUnderflowException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibCollisionDetectedException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibDbException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibDependentsDetectedException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibEmptyArgumentException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibInvalidArgumentException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibMustOverrideException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibNotImplementedYetException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibNotSupportedException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibNullArgumentException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibPrimaryKeyNotNewException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibStaleCacheDetectedException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibUniqueIndexViolationException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibUnrecognizedAttributeException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibUnresolvedRelationException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibUnsupportedClassException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibUsageException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibArgumentException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibRuntimeException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( RuntimeException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				e.getMessage(),
				e );
		}
		catch( Exception e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				e.getMessage(),
				e );
		}
	}

	// Parse a file

	public void parseFile( String url ) {
		final String S_ProcName = "parseFile";
		resetResponse();
		if( schemaObj.isTransactionOpen() ) {
			try {
				schemaObj.rollback();
			}
			catch( RuntimeException x ) {
			}
		}
		boolean transactionOpened = false;
		try {
			transactionOpened = schemaObj.beginTransaction();

			super.parse( url );

			if( caughtException ) {
				schemaObj.rollback();
			}
			else {
				schemaObj.commit();
			}

			transactionOpened = false;
		}
		catch( CFLibArgumentOverflowException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibArgumentRangeException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibArgumentUnderflowException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibCollisionDetectedException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibDbException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibDependentsDetectedException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibEmptyArgumentException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibInvalidArgumentException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibMustOverrideException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibNotImplementedYetException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibNotSupportedException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibNullArgumentException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibPrimaryKeyNotNewException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibStaleCacheDetectedException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibUniqueIndexViolationException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibUnrecognizedAttributeException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibUnresolvedRelationException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibUnsupportedClassException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibUsageException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibArgumentException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibRuntimeException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( RuntimeException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				e.getMessage(),
				e );
		}
		catch( Exception e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				e.getMessage(),
				e );
		}
	}
}
