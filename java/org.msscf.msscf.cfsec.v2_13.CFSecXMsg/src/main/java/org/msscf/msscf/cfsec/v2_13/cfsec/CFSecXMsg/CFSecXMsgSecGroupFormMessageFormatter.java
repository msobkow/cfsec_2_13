
// Description: Java 11 XML Message message formatter for CFSec.SecGroupForm

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
 *	CFSecXMsgSecGroupFormMessageFormatter XML message formatter
 *	for CFSec.SecGroupForm.
 */
public class CFSecXMsgSecGroupFormMessageFormatter
{
	public CFSecXMsgSecGroupFormMessageFormatter() {
	}

	public static String formatSecGroupFormPKeyAttributes( String separator, CFSecSecGroupFormPKey pkey ) {
		String retval = CFLibXmlUtil.formatRequiredInt64( null,
				"ClusterId",
				pkey.getRequiredClusterId() )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
				"SecGroupFormId",
				pkey.getRequiredSecGroupFormId() );
		return( retval );
	}

	public static String formatSecGroupFormPKeyAttributes( String separator, CFSecSecGroupFormBuff buff ) {
		String retval = CFLibXmlUtil.formatRequiredInt64( separator,
					"ClusterId",
					buff.getRequiredClusterId() )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"SecGroupFormId",
					buff.getRequiredSecGroupFormId() );
		return( retval );
	}

	public static String formatSecGroupFormBuffAttributes( String separator, CFSecSecGroupFormBuff buff ) {
		String retval = CFSecXMsgSecGroupFormMessageFormatter.formatSecGroupFormPKeyAttributes( separator, buff )
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
					"SecGroupId",
					buff.getRequiredSecGroupId() )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"SecAppId",
					buff.getRequiredSecAppId() )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"SecFormId",
					buff.getRequiredSecFormId() );
		return( retval );
	}

	public static String formatSecGroupFormRqstCreate( String separator, CFSecSecGroupFormBuff buff ) {
		String retval = "<RqstSecGroupFormCreate "
			+	formatSecGroupFormBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecGroupFormRqstRead( String separator, CFSecSecGroupFormPKey pkey ) {
		String retval = "<RqstSecGroupFormRead "
			+	formatSecGroupFormPKeyAttributes( separator, pkey )
			+	" />";
		return( retval );
	}

	public static String formatSecGroupFormRqstRead( String separator, CFSecSecGroupFormBuff buff ) {
		String retval = "<RqstSecGroupFormRead "
			+	formatSecGroupFormPKeyAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecGroupFormRqstRead( String separator,
		long argClusterId,
		long argSecGroupFormId )
	{
		String retval = "<RqstSecGroupFormRead "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"SecGroupFormId",
					argSecGroupFormId )
			+	" />";
		return( retval );
	}

	public static String formatSecGroupFormRqstReadAll( String separator ) {
		String retval = "<RqstSecGroupFormReadAll />";
		return( retval );
	}

	public static String formatSecGroupFormRqstPageAll( String separator,
		Long priorClusterId,
		Long priorSecGroupFormId ) {
		String retval = "<RqstSecGroupFormPageAll "
			+	CFLibXmlUtil.formatOptionalInt64( null,
					"PriorClusterId",
					priorClusterId )
			+	CFLibXmlUtil.formatOptionalInt64( separator,
					"PriorSecGroupFormId",
					priorSecGroupFormId )
			+	" />";
		return( retval );
	}

	public static String formatSecGroupFormRqstRdByIdIdx( String separator,
		long argClusterId,
		long argSecGroupFormId )
	{
		String retval = "<RqstSecGroupFormRead "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"SecGroupFormId",
					argSecGroupFormId )
			+	" />";
		return( retval );
	}

	public static String formatSecGroupFormRqstRdByClusterIdx( String separator,
		long argClusterId )
	{
		String retval = "<RqstSecGroupFormRdByClusterIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	" />";
		return( retval );
	}

	public static String formatSecGroupFormRqstRdByGroupIdx( String separator,
		long argClusterId,
		int argSecGroupId )
	{
		String retval = "<RqstSecGroupFormRdByGroupIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"SecGroupId",
					argSecGroupId )
			+	" />";
		return( retval );
	}

	public static String formatSecGroupFormRqstRdByAppIdx( String separator,
		long argClusterId,
		int argSecAppId )
	{
		String retval = "<RqstSecGroupFormRdByAppIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"SecAppId",
					argSecAppId )
			+	" />";
		return( retval );
	}

	public static String formatSecGroupFormRqstRdByFormIdx( String separator,
		long argClusterId,
		int argSecFormId )
	{
		String retval = "<RqstSecGroupFormRdByFormIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"SecFormId",
					argSecFormId )
			+	" />";
		return( retval );
	}

	public static String formatSecGroupFormRqstRdByUFormIdx( String separator,
		long argClusterId,
		int argSecGroupId,
		int argSecFormId )
	{
		String retval = "<RqstSecGroupFormRdByUFormIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"SecGroupId",
					argSecGroupId )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"SecFormId",
					argSecFormId )
			+	" />";
		return( retval );
	}

	public static String formatSecGroupFormRqstPageByClusterIdx( String separator,
		long argClusterId,
		Long priorClusterId,
		Long priorSecGroupFormId )
	{
		String retval = "<RqstSecGroupFormPageByClusterIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatOptionalInt64( separator,
					"PriorClusterId",
					priorClusterId )
			+	CFLibXmlUtil.formatOptionalInt64( separator,
					"PriorSecGroupFormId",
					priorSecGroupFormId )
			+	" />";
		return( retval );
	}

	public static String formatSecGroupFormRqstPageByGroupIdx( String separator,
		long argClusterId,
		int argSecGroupId,
		Long priorClusterId,
		Long priorSecGroupFormId )
	{
		String retval = "<RqstSecGroupFormPageByGroupIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"SecGroupId",
					argSecGroupId )
			+	CFLibXmlUtil.formatOptionalInt64( separator,
					"PriorClusterId",
					priorClusterId )
			+	CFLibXmlUtil.formatOptionalInt64( separator,
					"PriorSecGroupFormId",
					priorSecGroupFormId )
			+	" />";
		return( retval );
	}

	public static String formatSecGroupFormRqstPageByAppIdx( String separator,
		long argClusterId,
		int argSecAppId,
		Long priorClusterId,
		Long priorSecGroupFormId )
	{
		String retval = "<RqstSecGroupFormPageByAppIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"SecAppId",
					argSecAppId )
			+	CFLibXmlUtil.formatOptionalInt64( separator,
					"PriorClusterId",
					priorClusterId )
			+	CFLibXmlUtil.formatOptionalInt64( separator,
					"PriorSecGroupFormId",
					priorSecGroupFormId )
			+	" />";
		return( retval );
	}

	public static String formatSecGroupFormRqstPageByFormIdx( String separator,
		long argClusterId,
		int argSecFormId,
		Long priorClusterId,
		Long priorSecGroupFormId )
	{
		String retval = "<RqstSecGroupFormPageByFormIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"SecFormId",
					argSecFormId )
			+	CFLibXmlUtil.formatOptionalInt64( separator,
					"PriorClusterId",
					priorClusterId )
			+	CFLibXmlUtil.formatOptionalInt64( separator,
					"PriorSecGroupFormId",
					priorSecGroupFormId )
			+	" />";
		return( retval );
	}

	public static String formatSecGroupFormRqstLock( String separator, CFSecSecGroupFormPKey pkey ) {
		String retval = "<RqstSecGroupFormLock "
			+	formatSecGroupFormPKeyAttributes( separator, pkey )
			+	" />";
		return( retval );
	}

	public static String formatSecGroupFormRqstLock( String separator, CFSecSecGroupFormBuff buff ) {
		String retval = "<RqstSecGroupFormLock "
			+	formatSecGroupFormPKeyAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecGroupFormRqstLock( String separator,
		long argClusterId,
		long argSecGroupFormId )
	{
		String retval = "<RqstSecGroupFormLock "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"SecGroupFormId",
					argSecGroupFormId )
			+	" />";
		return( retval );
	}

	public static String formatSecGroupFormRqstUpdate( String separator, CFSecSecGroupFormBuff buff ) {
		String retval = "<RqstSecGroupFormUpdate "
			+	formatSecGroupFormBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecGroupFormRqstDelete( String separator, CFSecSecGroupFormBuff buff ) {
		String retval = "<RqstSecGroupFormDelete "
				+	formatSecGroupFormPKeyAttributes( separator, buff )
				+	CFLibXmlUtil.formatRequiredInt32( separator,
						"Revision",
						buff.getRequiredRevision() )
				+	" />";
		return( retval );
	}

	public static String formatSecGroupFormRqstDelByIdIdx( String separator,
		long argClusterId,
		long argSecGroupFormId )
	{
		String retval = "<RqstSecGroupFormDelete "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"SecGroupFormId",
					argSecGroupFormId )
			+	" />";
		return( retval );
	}

	public static String formatSecGroupFormRqstDelByClusterIdx( String separator,
		long argClusterId )
	{
		String retval = "<RqstSecGroupFormDelByClusterIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	" />";
		return( retval );
	}

	public static String formatSecGroupFormRqstDelByGroupIdx( String separator,
		long argClusterId,
		int argSecGroupId )
	{
		String retval = "<RqstSecGroupFormDelByGroupIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"SecGroupId",
					argSecGroupId )
			+	" />";
		return( retval );
	}

	public static String formatSecGroupFormRqstDelByAppIdx( String separator,
		long argClusterId,
		int argSecAppId )
	{
		String retval = "<RqstSecGroupFormDelByAppIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"SecAppId",
					argSecAppId )
			+	" />";
		return( retval );
	}

	public static String formatSecGroupFormRqstDelByFormIdx( String separator,
		long argClusterId,
		int argSecFormId )
	{
		String retval = "<RqstSecGroupFormDelByFormIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"SecFormId",
					argSecFormId )
			+	" />";
		return( retval );
	}

	public static String formatSecGroupFormRqstDelByUFormIdx( String separator,
		long argClusterId,
		int argSecGroupId,
		int argSecFormId )
	{
		String retval = "<RqstSecGroupFormDelByUFormIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"SecGroupId",
					argSecGroupId )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"SecFormId",
					argSecFormId )
			+	" />";
		return( retval );
	}

	public static String formatSecGroupFormRspnSingleOpenTag() {
		String retval = "<RspnSecGroupFormReadSingle>";
		return( retval );
	}

	public static String formatSecGroupFormRspnSingleCloseTag() {
		String retval = "</RspnSecGroupFormReadSingle>";
		return( retval );
	}

	public static String formatSecGroupFormRspnListOpenTag() {
		String retval = "<RspnSecGroupFormReadList>";
		return( retval );
	}

	public static String formatSecGroupFormRspnListCloseTag() {
		String retval = "</RspnSecGroupFormReadList>";
		return( retval );
	}

	public static String formatSecGroupFormRspnRec( String separator, CFSecSecGroupFormBuff buff ) {
		String retval = "<SecGroupForm "
			+	formatSecGroupFormBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecGroupFormRspnDerivedRec( String separator, CFSecSecGroupFormBuff buff ) {
		String retval;
		retval = formatSecGroupFormRspnRec( separator, buff );
		return( retval );
	}

	public static String formatSecGroupFormRspnCreated( String separator, CFSecSecGroupFormBuff buff ) {
		String retval = "<RspnSecGroupFormCreated "
			+	formatSecGroupFormBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecGroupFormRspnLocked( String separator, CFSecSecGroupFormBuff buff ) {
		String retval = "<RspnSecGroupFormLocked "
			+	formatSecGroupFormBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecGroupFormRspnUpdated( String separator, CFSecSecGroupFormBuff buff ) {
		String retval = "<RspnSecGroupFormUpdated "
			+	formatSecGroupFormBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecGroupFormRspnDeleted() {
		String retval = "<RspnSecGroupFormDeleted />";
		return( retval );
	}
}
