
// Description: Java 11 XML Message message formatter for CFSec.Cluster

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
