
// Description: Java 11 XML Message message formatter for CFSec

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

package com.github.msobkow.cfsec.CFSecXMsg;

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.apache.commons.codec.binary.Base64;
import org.xml.sax.*;
import com.github.msobkow.cflib.CFLib.*;
import com.github.msobkow.cfsec.CFSec.*;
import com.github.msobkow.cfsec.CFSecObj.*;

/*
 *	CFSecXMsgSchemaMessageFormatter XML message formatter
 *	for CFSec.
 */
public class CFSecXMsgSchemaMessageFormatter
{
	private String messageNamespace = "CFSec";

	public String getMessageNamespace() {
		return( messageNamespace );
	}

	public void setMessageNamespace( String value ) {
		final String S_ProcName = "setMessageNamespace";
		if( ( value == null ) || ( value.length() <= 0 ) ) {
			throw new CFLibNullArgumentException( getClass(),
				S_ProcName,
				1,
				"value" );
		}
		messageNamespace = new String( value );
	}

	public CFSecXMsgSchemaMessageFormatter() {
	}

	public static String formatRqstXmlPreamble() {
		String retval =
				"<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
			+	"<CFSecRqst\n"
			+	"\t\txmlns=\"uri://cfsec/cfsecrqst\"\n"
			+	"\t\txmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"\n"
			+	"\t\txmlns:xs=\"http://www.w3.org/2001/XMLSchema\"\n"
			+	"\t\txsi:schemaLocation=\"uri://cfsec/cfsecrqst file:../bin/xsd/cfsec-rqst.xsd\" >";
		return( retval );
	}

	public static String formatRqstXmlPostamble() {
		String retval =
				"</CFSecRqst>\n";
		return( retval );
	}

	public String formatRspnXmlPreamble() {
		String lowerNamespace = messageNamespace.toLowerCase();
		String retval =
				"<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
			+	"<" + messageNamespace + "Rspn\n"
			+	"\t\txmlns=\"uri://" + lowerNamespace + "/" + lowerNamespace + "rspn\"\n"
			+	"\t\txmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"\n"
			+	"\t\txmlns:xs=\"http://www.w3.org/2001/XMLSchema\"\n"
			+	"\t\txsi:schemaLocation=\"uri://" + lowerNamespace + "/" + lowerNamespace + "rspn file:../bin/xsd/" + lowerNamespace + "-rspn.xsd\" >";
		return( retval );
	}

	public String formatRspnXmlPostamble() {
		String retval =
				"</" + messageNamespace + "Rspn>\n";
		return( retval );
	}

	public static String formatRspnNoDataFound() {
		String retval = "<RspnNoDataFound />";
		return( retval );
	}

	public static String formatRspnException( String separator, Throwable t ) {
		String msg = t.getMessage();
		if( msg == null ) {
			msg = "";
		}
		String retval = "<RspnException "
			+	CFLibXmlUtil.formatRequiredXmlString( null,
					"Name",
					t.getClass().getName() )
			+	CFLibXmlUtil.formatRequiredXmlString( separator,
					"Message",
					msg )
			+	" />";
		return( retval );
	}

	public static String formatRqstFileImport( String separator, String fileName, String fileContent ) {
		String retval = "<RqstFileImport "
			+	CFLibXmlUtil.formatRequiredXmlString( null,
					"FileName",
					fileName )
			+	CFLibXmlUtil.formatRequiredXmlString( separator,
					"FileContent",
					fileContent )
			+	" />";
		return( retval );
	}

	public static String formatRqstLogIn( String separator, String loginId, String deviceName, byte devEncPWHash[], String clusterName, String tenantName ) {
		String retval = "<RqstLogIn "
			+	CFLibXmlUtil.formatRequiredXmlString( null,
					"LoginId",
					loginId )
			+	CFLibXmlUtil.formatRequiredXmlString( separator,
					"DeviceName",
					deviceName )
			+	CFLibXmlUtil.formatRequiredBlob( separator,
					"DevEncPWHash",
					devEncPWHash )
			+	CFLibXmlUtil.formatRequiredXmlString( separator,
					"ClusterName",
					clusterName )
			+	CFLibXmlUtil.formatRequiredXmlString( separator,
					"TenantName",
					tenantName )
			+	" />";
		return( retval );
	}

	public static String formatRqstLogOut( String separator, UUID secSessionId ) {
		String retval = "<RqstLogOut "
			+	CFLibXmlUtil.formatRequiredXmlString( null,
					"SecSessionId",
					secSessionId.toString() )
			+	" />";
		return( retval );
	}

	public static String formatRspnFileLoaded( String separator, String logContent ) {
		String retval = "<RspnFileLoaded "
			+	CFLibXmlUtil.formatRequiredXmlString( null,
					"LogContent",
					logContent )
			+	" />";
		return( retval );
	}

	public static String formatRspnServerProcExecuted( String separator, boolean dataChanged ) {
		String retval = "<RspnServerProcExecuted "
			+	CFLibXmlUtil.formatRequiredBoolean( null,
					"DataChanged",
					dataChanged )
			+	" />";
		return( retval );
	}

	public static String formatRspnLoggedIn( String separator, long clusterId, String clusterName, long tenantId, String tenantName, UUID secUserId, String secUserName, UUID secSessionId ) {
		String retval = "<RspnLoggedIn "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					clusterId )
			+	CFLibXmlUtil.formatRequiredXmlString( separator,
					"ClusterName",
					clusterName )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"TenantId",
					tenantId )
			+	CFLibXmlUtil.formatRequiredXmlString( separator,
					"TenantName",
					tenantName )
			+	CFLibXmlUtil.formatRequiredXmlString( separator,
					"SecUserId",
					secUserId.toString() )
			+	CFLibXmlUtil.formatRequiredXmlString( separator,
					"SecUserName",
					secUserName )
			+	CFLibXmlUtil.formatRequiredXmlString( separator,
					"SecSessionId",
					secSessionId.toString() )
			+	" />";
		return( retval );
	}

	public static String formatRspnLoggedOut( String separator, UUID secSessionId ) {
		String retval = "<RspnLoggedOut "
			+	CFLibXmlUtil.formatRequiredXmlString( null,
					"SecSessionId",
					secSessionId.toString() )
			+	" />";
		return( retval );
	}
}
