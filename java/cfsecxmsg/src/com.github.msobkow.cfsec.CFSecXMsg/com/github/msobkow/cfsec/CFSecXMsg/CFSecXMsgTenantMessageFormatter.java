
// Description: Java 11 XML Message message formatter for CFSec.Tenant

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
 *	CFSecXMsgTenantMessageFormatter XML message formatter
 *	for CFSec.Tenant.
 */
public class CFSecXMsgTenantMessageFormatter
{
	public CFSecXMsgTenantMessageFormatter() {
	}

	public static String formatTenantPKeyAttributes( String separator, CFSecTenantPKey pkey ) {
		String retval = CFLibXmlUtil.formatRequiredInt64( null,
				"Id",
				pkey.getRequiredId() );
		return( retval );
	}

	public static String formatTenantPKeyAttributes( String separator, CFSecTenantBuff buff ) {
		String retval = CFLibXmlUtil.formatRequiredInt64( separator,
					"Id",
					buff.getRequiredId() );
		return( retval );
	}

	public static String formatTenantBuffAttributes( String separator, CFSecTenantBuff buff ) {
		String retval = CFSecXMsgTenantMessageFormatter.formatTenantPKeyAttributes( separator, buff )
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
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"ClusterId",
					buff.getRequiredClusterId() )
			+	CFLibXmlUtil.formatRequiredXmlString( separator,
					"TenantName",
					buff.getRequiredTenantName() );
		return( retval );
	}

	public static String formatTenantRqstCreate( String separator, CFSecTenantBuff buff ) {
		String retval = "<RqstTenantCreate "
			+	formatTenantBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatTenantRqstRead( String separator, CFSecTenantPKey pkey ) {
		String retval = "<RqstTenantRead "
			+	formatTenantPKeyAttributes( separator, pkey )
			+	" />";
		return( retval );
	}

	public static String formatTenantRqstRead( String separator, CFSecTenantBuff buff ) {
		String retval = "<RqstTenantRead "
			+	formatTenantPKeyAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatTenantRqstRead( String separator,
		long argId )
	{
		String retval = "<RqstTenantRead "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"Id",
					argId )
			+	" />";
		return( retval );
	}

	public static String formatTenantRqstReadAll( String separator ) {
		String retval = "<RqstTenantReadAll />";
		return( retval );
	}

	public static String formatTenantRqstPageAll( String separator,
		Long priorId ) {
		String retval = "<RqstTenantPageAll "
			+	CFLibXmlUtil.formatOptionalInt64( null,
					"PriorId",
					priorId )
			+	" />";
		return( retval );
	}

	public static String formatTenantRqstRdByIdIdx( String separator,
		long argId )
	{
		String retval = "<RqstTenantRead "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"Id",
					argId )
			+	" />";
		return( retval );
	}

	public static String formatTenantRqstRdByClusterIdx( String separator,
		long argClusterId )
	{
		String retval = "<RqstTenantRdByClusterIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	" />";
		return( retval );
	}

	public static String formatTenantRqstRdByUNameIdx( String separator,
		long argClusterId,
		String argTenantName )
	{
		String retval = "<RqstTenantRdByUNameIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredXmlString( separator,
					"TenantName",
					argTenantName )
			+	" />";
		return( retval );
	}

	public static String formatTenantRqstPageByClusterIdx( String separator,
		long argClusterId,
		Long priorId )
	{
		String retval = "<RqstTenantPageByClusterIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatOptionalInt64( separator,
					"PriorId",
					priorId )
			+	" />";
		return( retval );
	}

	public static String formatTenantRqstLock( String separator, CFSecTenantPKey pkey ) {
		String retval = "<RqstTenantLock "
			+	formatTenantPKeyAttributes( separator, pkey )
			+	" />";
		return( retval );
	}

	public static String formatTenantRqstLock( String separator, CFSecTenantBuff buff ) {
		String retval = "<RqstTenantLock "
			+	formatTenantPKeyAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatTenantRqstLock( String separator,
		long argId )
	{
		String retval = "<RqstTenantLock "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"Id",
					argId )
			+	" />";
		return( retval );
	}

	public static String formatTenantRqstUpdate( String separator, CFSecTenantBuff buff ) {
		String retval = "<RqstTenantUpdate "
			+	formatTenantBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatTenantRqstDelete( String separator, CFSecTenantBuff buff ) {
		String retval = "<RqstTenantDelete "
				+	formatTenantPKeyAttributes( separator, buff )
				+	CFLibXmlUtil.formatRequiredInt32( separator,
						"Revision",
						buff.getRequiredRevision() )
				+	" />";
		return( retval );
	}

	public static String formatTenantRqstDelByIdIdx( String separator,
		long argId )
	{
		String retval = "<RqstTenantDelete "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"Id",
					argId )
			+	" />";
		return( retval );
	}

	public static String formatTenantRqstDelByClusterIdx( String separator,
		long argClusterId )
	{
		String retval = "<RqstTenantDelByClusterIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	" />";
		return( retval );
	}

	public static String formatTenantRqstDelByUNameIdx( String separator,
		long argClusterId,
		String argTenantName )
	{
		String retval = "<RqstTenantDelByUNameIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredXmlString( separator,
					"TenantName",
					argTenantName )
			+	" />";
		return( retval );
	}

	public static String formatTenantRspnSingleOpenTag() {
		String retval = "<RspnTenantReadSingle>";
		return( retval );
	}

	public static String formatTenantRspnSingleCloseTag() {
		String retval = "</RspnTenantReadSingle>";
		return( retval );
	}

	public static String formatTenantRspnListOpenTag() {
		String retval = "<RspnTenantReadList>";
		return( retval );
	}

	public static String formatTenantRspnListCloseTag() {
		String retval = "</RspnTenantReadList>";
		return( retval );
	}

	public static String formatTenantRspnRec( String separator, CFSecTenantBuff buff ) {
		String retval = "<Tenant "
			+	formatTenantBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatTenantRspnDerivedRec( String separator, CFSecTenantBuff buff ) {
		String retval;
		retval = formatTenantRspnRec( separator, buff );
		return( retval );
	}

	public static String formatTenantRspnCreated( String separator, CFSecTenantBuff buff ) {
		String retval = "<RspnTenantCreated "
			+	formatTenantBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatTenantRspnLocked( String separator, CFSecTenantBuff buff ) {
		String retval = "<RspnTenantLocked "
			+	formatTenantBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatTenantRspnUpdated( String separator, CFSecTenantBuff buff ) {
		String retval = "<RspnTenantUpdated "
			+	formatTenantBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatTenantRspnDeleted() {
		String retval = "<RspnTenantDeleted />";
		return( retval );
	}
}
