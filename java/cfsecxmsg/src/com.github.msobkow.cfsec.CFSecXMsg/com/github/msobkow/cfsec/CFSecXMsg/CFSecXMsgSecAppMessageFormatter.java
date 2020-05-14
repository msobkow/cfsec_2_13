
// Description: Java 11 XML Message message formatter for CFSec.SecApp

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
 *	CFSecXMsgSecAppMessageFormatter XML message formatter
 *	for CFSec.SecApp.
 */
public class CFSecXMsgSecAppMessageFormatter
{
	public CFSecXMsgSecAppMessageFormatter() {
	}

	public static String formatSecAppPKeyAttributes( String separator, CFSecSecAppPKey pkey ) {
		String retval = CFLibXmlUtil.formatRequiredInt64( null,
				"ClusterId",
				pkey.getRequiredClusterId() )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
				"SecAppId",
				pkey.getRequiredSecAppId() );
		return( retval );
	}

	public static String formatSecAppPKeyAttributes( String separator, CFSecSecAppBuff buff ) {
		String retval = CFLibXmlUtil.formatRequiredInt64( separator,
					"ClusterId",
					buff.getRequiredClusterId() )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"SecAppId",
					buff.getRequiredSecAppId() );
		return( retval );
	}

	public static String formatSecAppBuffAttributes( String separator, CFSecSecAppBuff buff ) {
		String retval = CFSecXMsgSecAppMessageFormatter.formatSecAppPKeyAttributes( separator, buff )
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
					"JEEMountName",
					buff.getRequiredJEEMountName() );
		return( retval );
	}

	public static String formatSecAppRqstCreate( String separator, CFSecSecAppBuff buff ) {
		String retval = "<RqstSecAppCreate "
			+	formatSecAppBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecAppRqstRead( String separator, CFSecSecAppPKey pkey ) {
		String retval = "<RqstSecAppRead "
			+	formatSecAppPKeyAttributes( separator, pkey )
			+	" />";
		return( retval );
	}

	public static String formatSecAppRqstRead( String separator, CFSecSecAppBuff buff ) {
		String retval = "<RqstSecAppRead "
			+	formatSecAppPKeyAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecAppRqstRead( String separator,
		long argClusterId,
		int argSecAppId )
	{
		String retval = "<RqstSecAppRead "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"SecAppId",
					argSecAppId )
			+	" />";
		return( retval );
	}

	public static String formatSecAppRqstReadAll( String separator ) {
		String retval = "<RqstSecAppReadAll />";
		return( retval );
	}

	public static String formatSecAppRqstPageAll( String separator,
		Long priorClusterId,
		Integer priorSecAppId ) {
		String retval = "<RqstSecAppPageAll "
			+	CFLibXmlUtil.formatOptionalInt64( null,
					"PriorClusterId",
					priorClusterId )
			+	CFLibXmlUtil.formatOptionalInt32( separator,
					"PriorSecAppId",
					priorSecAppId )
			+	" />";
		return( retval );
	}

	public static String formatSecAppRqstRdByIdIdx( String separator,
		long argClusterId,
		int argSecAppId )
	{
		String retval = "<RqstSecAppRead "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"SecAppId",
					argSecAppId )
			+	" />";
		return( retval );
	}

	public static String formatSecAppRqstRdByClusterIdx( String separator,
		long argClusterId )
	{
		String retval = "<RqstSecAppRdByClusterIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	" />";
		return( retval );
	}

	public static String formatSecAppRqstRdByUJEEMountIdx( String separator,
		long argClusterId,
		String argJEEMountName )
	{
		String retval = "<RqstSecAppRdByUJEEMountIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredXmlString( separator,
					"JEEMountName",
					argJEEMountName )
			+	" />";
		return( retval );
	}

	public static String formatSecAppRqstPageByClusterIdx( String separator,
		long argClusterId,
		Long priorClusterId,
		Integer priorSecAppId )
	{
		String retval = "<RqstSecAppPageByClusterIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatOptionalInt64( separator,
					"PriorClusterId",
					priorClusterId )
			+	CFLibXmlUtil.formatOptionalInt32( separator,
					"PriorSecAppId",
					priorSecAppId )
			+	" />";
		return( retval );
	}

	public static String formatSecAppRqstLock( String separator, CFSecSecAppPKey pkey ) {
		String retval = "<RqstSecAppLock "
			+	formatSecAppPKeyAttributes( separator, pkey )
			+	" />";
		return( retval );
	}

	public static String formatSecAppRqstLock( String separator, CFSecSecAppBuff buff ) {
		String retval = "<RqstSecAppLock "
			+	formatSecAppPKeyAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecAppRqstLock( String separator,
		long argClusterId,
		int argSecAppId )
	{
		String retval = "<RqstSecAppLock "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"SecAppId",
					argSecAppId )
			+	" />";
		return( retval );
	}

	public static String formatSecAppRqstUpdate( String separator, CFSecSecAppBuff buff ) {
		String retval = "<RqstSecAppUpdate "
			+	formatSecAppBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecAppRqstDelete( String separator, CFSecSecAppBuff buff ) {
		String retval = "<RqstSecAppDelete "
				+	formatSecAppPKeyAttributes( separator, buff )
				+	CFLibXmlUtil.formatRequiredInt32( separator,
						"Revision",
						buff.getRequiredRevision() )
				+	" />";
		return( retval );
	}

	public static String formatSecAppRqstDelByIdIdx( String separator,
		long argClusterId,
		int argSecAppId )
	{
		String retval = "<RqstSecAppDelete "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"SecAppId",
					argSecAppId )
			+	" />";
		return( retval );
	}

	public static String formatSecAppRqstDelByClusterIdx( String separator,
		long argClusterId )
	{
		String retval = "<RqstSecAppDelByClusterIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	" />";
		return( retval );
	}

	public static String formatSecAppRqstDelByUJEEMountIdx( String separator,
		long argClusterId,
		String argJEEMountName )
	{
		String retval = "<RqstSecAppDelByUJEEMountIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredXmlString( separator,
					"JEEMountName",
					argJEEMountName )
			+	" />";
		return( retval );
	}

	public static String formatSecAppRspnSingleOpenTag() {
		String retval = "<RspnSecAppReadSingle>";
		return( retval );
	}

	public static String formatSecAppRspnSingleCloseTag() {
		String retval = "</RspnSecAppReadSingle>";
		return( retval );
	}

	public static String formatSecAppRspnListOpenTag() {
		String retval = "<RspnSecAppReadList>";
		return( retval );
	}

	public static String formatSecAppRspnListCloseTag() {
		String retval = "</RspnSecAppReadList>";
		return( retval );
	}

	public static String formatSecAppRspnRec( String separator, CFSecSecAppBuff buff ) {
		String retval = "<SecApp "
			+	formatSecAppBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecAppRspnDerivedRec( String separator, CFSecSecAppBuff buff ) {
		String retval;
		retval = formatSecAppRspnRec( separator, buff );
		return( retval );
	}

	public static String formatSecAppRspnCreated( String separator, CFSecSecAppBuff buff ) {
		String retval = "<RspnSecAppCreated "
			+	formatSecAppBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecAppRspnLocked( String separator, CFSecSecAppBuff buff ) {
		String retval = "<RspnSecAppLocked "
			+	formatSecAppBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecAppRspnUpdated( String separator, CFSecSecAppBuff buff ) {
		String retval = "<RspnSecAppUpdated "
			+	formatSecAppBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecAppRspnDeleted() {
		String retval = "<RspnSecAppDeleted />";
		return( retval );
	}
}