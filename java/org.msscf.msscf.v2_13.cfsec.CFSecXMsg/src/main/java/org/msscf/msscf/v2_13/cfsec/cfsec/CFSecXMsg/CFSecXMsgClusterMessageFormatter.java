
// Description: Java 11 XML Message message formatter for CFSec.Cluster

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

package org.msscf.msscf.v2_13.cfsec.cfsec.CFSecXMsg;

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.apache.commons.codec.binary.Base64;
import org.xml.sax.*;
import org.msscf.msscf.v2_13.cflib.CFLib.*;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfsec.CFSecObj.*;

/*
 *	CFSecXMsgClusterMessageFormatter XML message formatter
 *	for CFSec.Cluster.
 */
public class CFSecXMsgClusterMessageFormatter
{
	public CFSecXMsgClusterMessageFormatter() {
	}

	public static String formatClusterPKeyAttributes( String separator, CFSecClusterPKey pkey ) {
		String retval = CFLibXmlUtil.formatRequiredInt64( null,
				"Id",
				pkey.getRequiredId() );
		return( retval );
	}

	public static String formatClusterPKeyAttributes( String separator, CFSecClusterBuff buff ) {
		String retval = CFLibXmlUtil.formatRequiredInt64( separator,
					"Id",
					buff.getRequiredId() );
		return( retval );
	}

	public static String formatClusterBuffAttributes( String separator, CFSecClusterBuff buff ) {
		String retval = CFSecXMsgClusterMessageFormatter.formatClusterPKeyAttributes( separator, buff )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"Revision",
					buff.getRequiredRevision() )
			+	CFLibXmlUtil.formatOptionalUuid( separator,
					"CreatedBy",
					buff.getCreatedByUserId() )
			+	CFLibXmlUtil.formatOptionalTimestamp( separator,
					"CreatedAt",
					buff.getCreatedAt() )
			+	CFLibXmlUtil.formatOptionalUuid( separator,
					"UpdatedBy",
					buff.getUpdatedByUserId() )
			+	CFLibXmlUtil.formatOptionalTimestamp( separator,
					"UpdatedAt",
					buff.getUpdatedAt() )
			+	CFLibXmlUtil.formatRequiredXmlString( separator,
					"FullDomName",
					buff.getRequiredFullDomName() )
			+	CFLibXmlUtil.formatRequiredXmlString( separator,
					"Description",
					buff.getRequiredDescription() );
		return( retval );
	}

	public static String formatClusterRqstCreate( String separator, CFSecClusterBuff buff ) {
		String retval = "<RqstClusterCreate "
			+	formatClusterBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatClusterRqstRead( String separator, CFSecClusterPKey pkey ) {
		String retval = "<RqstClusterRead "
			+	formatClusterPKeyAttributes( separator, pkey )
			+	" />";
		return( retval );
	}

	public static String formatClusterRqstRead( String separator, CFSecClusterBuff buff ) {
		String retval = "<RqstClusterRead "
			+	formatClusterPKeyAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatClusterRqstRead( String separator,
		long argId )
	{
		String retval = "<RqstClusterRead "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"Id",
					argId )
			+	" />";
		return( retval );
	}

	public static String formatClusterRqstReadAll( String separator ) {
		String retval = "<RqstClusterReadAll />";
		return( retval );
	}

	public static String formatClusterRqstPageAll( String separator,
		Long priorId ) {
		String retval = "<RqstClusterPageAll "
			+	CFLibXmlUtil.formatOptionalInt64( null,
					"PriorId",
					priorId )
			+	" />";
		return( retval );
	}

	public static String formatClusterRqstRdByIdIdx( String separator,
		long argId )
	{
		String retval = "<RqstClusterRead "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"Id",
					argId )
			+	" />";
		return( retval );
	}

	public static String formatClusterRqstRdByUDomNameIdx( String separator,
		String argFullDomName )
	{
		String retval = "<RqstClusterRdByUDomNameIdx "
			+	CFLibXmlUtil.formatRequiredXmlString( null,
					"FullDomName",
					argFullDomName )
			+	" />";
		return( retval );
	}

	public static String formatClusterRqstRdByUDescrIdx( String separator,
		String argDescription )
	{
		String retval = "<RqstClusterRdByUDescrIdx "
			+	CFLibXmlUtil.formatRequiredXmlString( null,
					"Description",
					argDescription )
			+	" />";
		return( retval );
	}

	public static String formatClusterRqstLock( String separator, CFSecClusterPKey pkey ) {
		String retval = "<RqstClusterLock "
			+	formatClusterPKeyAttributes( separator, pkey )
			+	" />";
		return( retval );
	}

	public static String formatClusterRqstLock( String separator, CFSecClusterBuff buff ) {
		String retval = "<RqstClusterLock "
			+	formatClusterPKeyAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatClusterRqstLock( String separator,
		long argId )
	{
		String retval = "<RqstClusterLock "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"Id",
					argId )
			+	" />";
		return( retval );
	}

	public static String formatClusterRqstUpdate( String separator, CFSecClusterBuff buff ) {
		String retval = "<RqstClusterUpdate "
			+	formatClusterBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatClusterRqstDelete( String separator, CFSecClusterBuff buff ) {
		String retval = "<RqstClusterDelete "
				+	formatClusterPKeyAttributes( separator, buff )
				+	CFLibXmlUtil.formatRequiredInt32( separator,
						"Revision",
						buff.getRequiredRevision() )
				+	" />";
		return( retval );
	}

	public static String formatClusterRqstDelByIdIdx( String separator,
		long argId )
	{
		String retval = "<RqstClusterDelete "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"Id",
					argId )
			+	" />";
		return( retval );
	}

	public static String formatClusterRqstDelByUDomNameIdx( String separator,
		String argFullDomName )
	{
		String retval = "<RqstClusterDelByUDomNameIdx "
			+	CFLibXmlUtil.formatRequiredXmlString( null,
					"FullDomName",
					argFullDomName )
			+	" />";
		return( retval );
	}

	public static String formatClusterRqstDelByUDescrIdx( String separator,
		String argDescription )
	{
		String retval = "<RqstClusterDelByUDescrIdx "
			+	CFLibXmlUtil.formatRequiredXmlString( null,
					"Description",
					argDescription )
			+	" />";
		return( retval );
	}

	public static String formatClusterRspnSingleOpenTag() {
		String retval = "<RspnClusterReadSingle>";
		return( retval );
	}

	public static String formatClusterRspnSingleCloseTag() {
		String retval = "</RspnClusterReadSingle>";
		return( retval );
	}

	public static String formatClusterRspnListOpenTag() {
		String retval = "<RspnClusterReadList>";
		return( retval );
	}

	public static String formatClusterRspnListCloseTag() {
		String retval = "</RspnClusterReadList>";
		return( retval );
	}

	public static String formatClusterRspnRec( String separator, CFSecClusterBuff buff ) {
		String retval = "<Cluster "
			+	formatClusterBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatClusterRspnDerivedRec( String separator, CFSecClusterBuff buff ) {
		String retval;
		retval = formatClusterRspnRec( separator, buff );
		return( retval );
	}

	public static String formatClusterRspnCreated( String separator, CFSecClusterBuff buff ) {
		String retval = "<RspnClusterCreated "
			+	formatClusterBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatClusterRspnLocked( String separator, CFSecClusterBuff buff ) {
		String retval = "<RspnClusterLocked "
			+	formatClusterBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatClusterRspnUpdated( String separator, CFSecClusterBuff buff ) {
		String retval = "<RspnClusterUpdated "
			+	formatClusterBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatClusterRspnDeleted() {
		String retval = "<RspnClusterDeleted />";
		return( retval );
	}
}
