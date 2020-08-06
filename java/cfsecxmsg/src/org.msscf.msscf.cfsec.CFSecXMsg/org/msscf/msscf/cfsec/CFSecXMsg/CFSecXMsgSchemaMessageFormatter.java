
// Description: Java 11 XML Message message formatter for CFSec

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

package org.msscf.msscf.cfsec.CFSecXMsg;

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.apache.commons.codec.binary.Base64;
import org.xml.sax.*;
import org.msscf.msscf.cflib.CFLib.*;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfsec.CFSecObj.*;

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
			+	"\t\txmlns=\"uri://org.msscf/msscf/2.0.13/cfsecrqst\"\n"
			+	"\t\txmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"\n"
			+	"\t\txmlns:xs=\"http://www.w3.org/2001/XMLSchema\"\n"
			+	"\t\txsi:schemaLocation=\"uri://org.msscf/msscf/2.0.13/cfsecrqst file:../bin/xsd/cfsec-rqst.xsd\" >";
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
