
// Description: Java 11 XML Message message formatter for CFSec.SecForm

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
 *	CFSecXMsgSecFormMessageFormatter XML message formatter
 *	for CFSec.SecForm.
 */
public class CFSecXMsgSecFormMessageFormatter
{
	public CFSecXMsgSecFormMessageFormatter() {
	}

	public static String formatSecFormPKeyAttributes( String separator, CFSecSecFormPKey pkey ) {
		String retval = CFLibXmlUtil.formatRequiredInt64( null,
				"ClusterId",
				pkey.getRequiredClusterId() )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
				"SecFormId",
				pkey.getRequiredSecFormId() );
		return( retval );
	}

	public static String formatSecFormPKeyAttributes( String separator, CFSecSecFormBuff buff ) {
		String retval = CFLibXmlUtil.formatRequiredInt64( separator,
					"ClusterId",
					buff.getRequiredClusterId() )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"SecFormId",
					buff.getRequiredSecFormId() );
		return( retval );
	}

	public static String formatSecFormBuffAttributes( String separator, CFSecSecFormBuff buff ) {
		String retval = CFSecXMsgSecFormMessageFormatter.formatSecFormPKeyAttributes( separator, buff )
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
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"SecAppId",
					buff.getRequiredSecAppId() )
			+	CFLibXmlUtil.formatRequiredXmlString( separator,
					"JEEServletMapName",
					buff.getRequiredJEEServletMapName() );
		return( retval );
	}

	public static String formatSecFormRqstCreate( String separator, CFSecSecFormBuff buff ) {
		String retval = "<RqstSecFormCreate "
			+	formatSecFormBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecFormRqstRead( String separator, CFSecSecFormPKey pkey ) {
		String retval = "<RqstSecFormRead "
			+	formatSecFormPKeyAttributes( separator, pkey )
			+	" />";
		return( retval );
	}

	public static String formatSecFormRqstRead( String separator, CFSecSecFormBuff buff ) {
		String retval = "<RqstSecFormRead "
			+	formatSecFormPKeyAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecFormRqstRead( String separator,
		long argClusterId,
		int argSecFormId )
	{
		String retval = "<RqstSecFormRead "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"SecFormId",
					argSecFormId )
			+	" />";
		return( retval );
	}

	public static String formatSecFormRqstReadAll( String separator ) {
		String retval = "<RqstSecFormReadAll />";
		return( retval );
	}

	public static String formatSecFormRqstPageAll( String separator,
		Long priorClusterId,
		Integer priorSecFormId ) {
		String retval = "<RqstSecFormPageAll "
			+	CFLibXmlUtil.formatOptionalInt64( null,
					"PriorClusterId",
					priorClusterId )
			+	CFLibXmlUtil.formatOptionalInt32( separator,
					"PriorSecFormId",
					priorSecFormId )
			+	" />";
		return( retval );
	}

	public static String formatSecFormRqstRdByIdIdx( String separator,
		long argClusterId,
		int argSecFormId )
	{
		String retval = "<RqstSecFormRead "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"SecFormId",
					argSecFormId )
			+	" />";
		return( retval );
	}

	public static String formatSecFormRqstRdByClusterIdx( String separator,
		long argClusterId )
	{
		String retval = "<RqstSecFormRdByClusterIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	" />";
		return( retval );
	}

	public static String formatSecFormRqstRdBySecAppIdx( String separator,
		long argClusterId,
		int argSecAppId )
	{
		String retval = "<RqstSecFormRdBySecAppIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"SecAppId",
					argSecAppId )
			+	" />";
		return( retval );
	}

	public static String formatSecFormRqstRdByUJEEServletIdx( String separator,
		long argClusterId,
		int argSecAppId,
		String argJEEServletMapName )
	{
		String retval = "<RqstSecFormRdByUJEEServletIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"SecAppId",
					argSecAppId )
			+	CFLibXmlUtil.formatRequiredXmlString( separator,
					"JEEServletMapName",
					argJEEServletMapName )
			+	" />";
		return( retval );
	}

	public static String formatSecFormRqstPageByClusterIdx( String separator,
		long argClusterId,
		Long priorClusterId,
		Integer priorSecFormId )
	{
		String retval = "<RqstSecFormPageByClusterIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatOptionalInt64( separator,
					"PriorClusterId",
					priorClusterId )
			+	CFLibXmlUtil.formatOptionalInt32( separator,
					"PriorSecFormId",
					priorSecFormId )
			+	" />";
		return( retval );
	}

	public static String formatSecFormRqstPageBySecAppIdx( String separator,
		long argClusterId,
		int argSecAppId,
		Long priorClusterId,
		Integer priorSecFormId )
	{
		String retval = "<RqstSecFormPageBySecAppIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"SecAppId",
					argSecAppId )
			+	CFLibXmlUtil.formatOptionalInt64( separator,
					"PriorClusterId",
					priorClusterId )
			+	CFLibXmlUtil.formatOptionalInt32( separator,
					"PriorSecFormId",
					priorSecFormId )
			+	" />";
		return( retval );
	}

	public static String formatSecFormRqstLock( String separator, CFSecSecFormPKey pkey ) {
		String retval = "<RqstSecFormLock "
			+	formatSecFormPKeyAttributes( separator, pkey )
			+	" />";
		return( retval );
	}

	public static String formatSecFormRqstLock( String separator, CFSecSecFormBuff buff ) {
		String retval = "<RqstSecFormLock "
			+	formatSecFormPKeyAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecFormRqstLock( String separator,
		long argClusterId,
		int argSecFormId )
	{
		String retval = "<RqstSecFormLock "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"SecFormId",
					argSecFormId )
			+	" />";
		return( retval );
	}

	public static String formatSecFormRqstUpdate( String separator, CFSecSecFormBuff buff ) {
		String retval = "<RqstSecFormUpdate "
			+	formatSecFormBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecFormRqstDelete( String separator, CFSecSecFormBuff buff ) {
		String retval = "<RqstSecFormDelete "
				+	formatSecFormPKeyAttributes( separator, buff )
				+	CFLibXmlUtil.formatRequiredInt32( separator,
						"Revision",
						buff.getRequiredRevision() )
				+	" />";
		return( retval );
	}

	public static String formatSecFormRqstDelByIdIdx( String separator,
		long argClusterId,
		int argSecFormId )
	{
		String retval = "<RqstSecFormDelete "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"SecFormId",
					argSecFormId )
			+	" />";
		return( retval );
	}

	public static String formatSecFormRqstDelByClusterIdx( String separator,
		long argClusterId )
	{
		String retval = "<RqstSecFormDelByClusterIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	" />";
		return( retval );
	}

	public static String formatSecFormRqstDelBySecAppIdx( String separator,
		long argClusterId,
		int argSecAppId )
	{
		String retval = "<RqstSecFormDelBySecAppIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"SecAppId",
					argSecAppId )
			+	" />";
		return( retval );
	}

	public static String formatSecFormRqstDelByUJEEServletIdx( String separator,
		long argClusterId,
		int argSecAppId,
		String argJEEServletMapName )
	{
		String retval = "<RqstSecFormDelByUJEEServletIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"SecAppId",
					argSecAppId )
			+	CFLibXmlUtil.formatRequiredXmlString( separator,
					"JEEServletMapName",
					argJEEServletMapName )
			+	" />";
		return( retval );
	}

	public static String formatSecFormRspnSingleOpenTag() {
		String retval = "<RspnSecFormReadSingle>";
		return( retval );
	}

	public static String formatSecFormRspnSingleCloseTag() {
		String retval = "</RspnSecFormReadSingle>";
		return( retval );
	}

	public static String formatSecFormRspnListOpenTag() {
		String retval = "<RspnSecFormReadList>";
		return( retval );
	}

	public static String formatSecFormRspnListCloseTag() {
		String retval = "</RspnSecFormReadList>";
		return( retval );
	}

	public static String formatSecFormRspnRec( String separator, CFSecSecFormBuff buff ) {
		String retval = "<SecForm "
			+	formatSecFormBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecFormRspnDerivedRec( String separator, CFSecSecFormBuff buff ) {
		String retval;
		retval = formatSecFormRspnRec( separator, buff );
		return( retval );
	}

	public static String formatSecFormRspnCreated( String separator, CFSecSecFormBuff buff ) {
		String retval = "<RspnSecFormCreated "
			+	formatSecFormBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecFormRspnLocked( String separator, CFSecSecFormBuff buff ) {
		String retval = "<RspnSecFormLocked "
			+	formatSecFormBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecFormRspnUpdated( String separator, CFSecSecFormBuff buff ) {
		String retval = "<RspnSecFormUpdated "
			+	formatSecFormBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecFormRspnDeleted() {
		String retval = "<RspnSecFormDeleted />";
		return( retval );
	}
}
