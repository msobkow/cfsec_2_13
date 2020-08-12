
// Description: Java 11 XML Message message formatter for CFSec.SecForm

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

package org.msscf.msscf.cfsec.v2_13.cfsec.CFSecXMsg;

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.apache.commons.codec.binary.Base64;
import org.xml.sax.*;
import org.msscf.msscf.cflib.v2_13.CFLib.*;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfsec.CFSecObj.*;

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
