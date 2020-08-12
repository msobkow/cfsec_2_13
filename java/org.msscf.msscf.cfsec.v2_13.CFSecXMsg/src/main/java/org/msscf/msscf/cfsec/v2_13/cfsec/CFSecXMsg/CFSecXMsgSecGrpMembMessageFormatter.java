
// Description: Java 11 XML Message message formatter for CFSec.SecGrpMemb

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
 *	CFSecXMsgSecGrpMembMessageFormatter XML message formatter
 *	for CFSec.SecGrpMemb.
 */
public class CFSecXMsgSecGrpMembMessageFormatter
{
	public CFSecXMsgSecGrpMembMessageFormatter() {
	}

	public static String formatSecGrpMembPKeyAttributes( String separator, CFSecSecGrpMembPKey pkey ) {
		String retval = CFLibXmlUtil.formatRequiredInt64( null,
				"ClusterId",
				pkey.getRequiredClusterId() )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
				"SecGrpMembId",
				pkey.getRequiredSecGrpMembId() );
		return( retval );
	}

	public static String formatSecGrpMembPKeyAttributes( String separator, CFSecSecGrpMembBuff buff ) {
		String retval = CFLibXmlUtil.formatRequiredInt64( separator,
					"ClusterId",
					buff.getRequiredClusterId() )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"SecGrpMembId",
					buff.getRequiredSecGrpMembId() );
		return( retval );
	}

	public static String formatSecGrpMembBuffAttributes( String separator, CFSecSecGrpMembBuff buff ) {
		String retval = CFSecXMsgSecGrpMembMessageFormatter.formatSecGrpMembPKeyAttributes( separator, buff )
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
			+	CFLibXmlUtil.formatRequiredUuid( separator,
					"SecUserId",
					buff.getRequiredSecUserId() );
		return( retval );
	}

	public static String formatSecGrpMembRqstCreate( String separator, CFSecSecGrpMembBuff buff ) {
		String retval = "<RqstSecGrpMembCreate "
			+	formatSecGrpMembBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecGrpMembRqstRead( String separator, CFSecSecGrpMembPKey pkey ) {
		String retval = "<RqstSecGrpMembRead "
			+	formatSecGrpMembPKeyAttributes( separator, pkey )
			+	" />";
		return( retval );
	}

	public static String formatSecGrpMembRqstRead( String separator, CFSecSecGrpMembBuff buff ) {
		String retval = "<RqstSecGrpMembRead "
			+	formatSecGrpMembPKeyAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecGrpMembRqstRead( String separator,
		long argClusterId,
		long argSecGrpMembId )
	{
		String retval = "<RqstSecGrpMembRead "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"SecGrpMembId",
					argSecGrpMembId )
			+	" />";
		return( retval );
	}

	public static String formatSecGrpMembRqstReadAll( String separator ) {
		String retval = "<RqstSecGrpMembReadAll />";
		return( retval );
	}

	public static String formatSecGrpMembRqstPageAll( String separator,
		Long priorClusterId,
		Long priorSecGrpMembId ) {
		String retval = "<RqstSecGrpMembPageAll "
			+	CFLibXmlUtil.formatOptionalInt64( null,
					"PriorClusterId",
					priorClusterId )
			+	CFLibXmlUtil.formatOptionalInt64( separator,
					"PriorSecGrpMembId",
					priorSecGrpMembId )
			+	" />";
		return( retval );
	}

	public static String formatSecGrpMembRqstRdByIdIdx( String separator,
		long argClusterId,
		long argSecGrpMembId )
	{
		String retval = "<RqstSecGrpMembRead "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"SecGrpMembId",
					argSecGrpMembId )
			+	" />";
		return( retval );
	}

	public static String formatSecGrpMembRqstRdByClusterIdx( String separator,
		long argClusterId )
	{
		String retval = "<RqstSecGrpMembRdByClusterIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	" />";
		return( retval );
	}

	public static String formatSecGrpMembRqstRdByGroupIdx( String separator,
		long argClusterId,
		int argSecGroupId )
	{
		String retval = "<RqstSecGrpMembRdByGroupIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"SecGroupId",
					argSecGroupId )
			+	" />";
		return( retval );
	}

	public static String formatSecGrpMembRqstRdByUserIdx( String separator,
		UUID argSecUserId )
	{
		String retval = "<RqstSecGrpMembRdByUserIdx "
			+	CFLibXmlUtil.formatRequiredUuid( null,
					"SecUserId",
					argSecUserId )
			+	" />";
		return( retval );
	}

	public static String formatSecGrpMembRqstRdByUUserIdx( String separator,
		long argClusterId,
		int argSecGroupId,
		UUID argSecUserId )
	{
		String retval = "<RqstSecGrpMembRdByUUserIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"SecGroupId",
					argSecGroupId )
			+	CFLibXmlUtil.formatRequiredUuid( separator,
					"SecUserId",
					argSecUserId )
			+	" />";
		return( retval );
	}

	public static String formatSecGrpMembRqstPageByClusterIdx( String separator,
		long argClusterId,
		Long priorClusterId,
		Long priorSecGrpMembId )
	{
		String retval = "<RqstSecGrpMembPageByClusterIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatOptionalInt64( separator,
					"PriorClusterId",
					priorClusterId )
			+	CFLibXmlUtil.formatOptionalInt64( separator,
					"PriorSecGrpMembId",
					priorSecGrpMembId )
			+	" />";
		return( retval );
	}

	public static String formatSecGrpMembRqstPageByGroupIdx( String separator,
		long argClusterId,
		int argSecGroupId,
		Long priorClusterId,
		Long priorSecGrpMembId )
	{
		String retval = "<RqstSecGrpMembPageByGroupIdx "
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
					"PriorSecGrpMembId",
					priorSecGrpMembId )
			+	" />";
		return( retval );
	}

	public static String formatSecGrpMembRqstPageByUserIdx( String separator,
		UUID argSecUserId,
		Long priorClusterId,
		Long priorSecGrpMembId )
	{
		String retval = "<RqstSecGrpMembPageByUserIdx "
			+	CFLibXmlUtil.formatRequiredUuid( null,
					"SecUserId",
					argSecUserId )
			+	CFLibXmlUtil.formatOptionalInt64( separator,
					"PriorClusterId",
					priorClusterId )
			+	CFLibXmlUtil.formatOptionalInt64( separator,
					"PriorSecGrpMembId",
					priorSecGrpMembId )
			+	" />";
		return( retval );
	}

	public static String formatSecGrpMembRqstLock( String separator, CFSecSecGrpMembPKey pkey ) {
		String retval = "<RqstSecGrpMembLock "
			+	formatSecGrpMembPKeyAttributes( separator, pkey )
			+	" />";
		return( retval );
	}

	public static String formatSecGrpMembRqstLock( String separator, CFSecSecGrpMembBuff buff ) {
		String retval = "<RqstSecGrpMembLock "
			+	formatSecGrpMembPKeyAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecGrpMembRqstLock( String separator,
		long argClusterId,
		long argSecGrpMembId )
	{
		String retval = "<RqstSecGrpMembLock "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"SecGrpMembId",
					argSecGrpMembId )
			+	" />";
		return( retval );
	}

	public static String formatSecGrpMembRqstUpdate( String separator, CFSecSecGrpMembBuff buff ) {
		String retval = "<RqstSecGrpMembUpdate "
			+	formatSecGrpMembBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecGrpMembRqstDelete( String separator, CFSecSecGrpMembBuff buff ) {
		String retval = "<RqstSecGrpMembDelete "
				+	formatSecGrpMembPKeyAttributes( separator, buff )
				+	CFLibXmlUtil.formatRequiredInt32( separator,
						"Revision",
						buff.getRequiredRevision() )
				+	" />";
		return( retval );
	}

	public static String formatSecGrpMembRqstDelByIdIdx( String separator,
		long argClusterId,
		long argSecGrpMembId )
	{
		String retval = "<RqstSecGrpMembDelete "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"SecGrpMembId",
					argSecGrpMembId )
			+	" />";
		return( retval );
	}

	public static String formatSecGrpMembRqstDelByClusterIdx( String separator,
		long argClusterId )
	{
		String retval = "<RqstSecGrpMembDelByClusterIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	" />";
		return( retval );
	}

	public static String formatSecGrpMembRqstDelByGroupIdx( String separator,
		long argClusterId,
		int argSecGroupId )
	{
		String retval = "<RqstSecGrpMembDelByGroupIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"SecGroupId",
					argSecGroupId )
			+	" />";
		return( retval );
	}

	public static String formatSecGrpMembRqstDelByUserIdx( String separator,
		UUID argSecUserId )
	{
		String retval = "<RqstSecGrpMembDelByUserIdx "
			+	CFLibXmlUtil.formatRequiredUuid( null,
					"SecUserId",
					argSecUserId )
			+	" />";
		return( retval );
	}

	public static String formatSecGrpMembRqstDelByUUserIdx( String separator,
		long argClusterId,
		int argSecGroupId,
		UUID argSecUserId )
	{
		String retval = "<RqstSecGrpMembDelByUUserIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"SecGroupId",
					argSecGroupId )
			+	CFLibXmlUtil.formatRequiredUuid( separator,
					"SecUserId",
					argSecUserId )
			+	" />";
		return( retval );
	}

	public static String formatSecGrpMembRspnSingleOpenTag() {
		String retval = "<RspnSecGrpMembReadSingle>";
		return( retval );
	}

	public static String formatSecGrpMembRspnSingleCloseTag() {
		String retval = "</RspnSecGrpMembReadSingle>";
		return( retval );
	}

	public static String formatSecGrpMembRspnListOpenTag() {
		String retval = "<RspnSecGrpMembReadList>";
		return( retval );
	}

	public static String formatSecGrpMembRspnListCloseTag() {
		String retval = "</RspnSecGrpMembReadList>";
		return( retval );
	}

	public static String formatSecGrpMembRspnRec( String separator, CFSecSecGrpMembBuff buff ) {
		String retval = "<SecGrpMemb "
			+	formatSecGrpMembBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecGrpMembRspnDerivedRec( String separator, CFSecSecGrpMembBuff buff ) {
		String retval;
		retval = formatSecGrpMembRspnRec( separator, buff );
		return( retval );
	}

	public static String formatSecGrpMembRspnCreated( String separator, CFSecSecGrpMembBuff buff ) {
		String retval = "<RspnSecGrpMembCreated "
			+	formatSecGrpMembBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecGrpMembRspnLocked( String separator, CFSecSecGrpMembBuff buff ) {
		String retval = "<RspnSecGrpMembLocked "
			+	formatSecGrpMembBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecGrpMembRspnUpdated( String separator, CFSecSecGrpMembBuff buff ) {
		String retval = "<RspnSecGrpMembUpdated "
			+	formatSecGrpMembBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecGrpMembRspnDeleted() {
		String retval = "<RspnSecGrpMembDeleted />";
		return( retval );
	}
}
