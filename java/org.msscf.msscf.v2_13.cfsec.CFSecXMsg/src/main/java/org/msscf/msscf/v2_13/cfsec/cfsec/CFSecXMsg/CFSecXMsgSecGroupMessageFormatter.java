
// Description: Java 11 XML Message message formatter for CFSec.SecGroup

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
 *	CFSecXMsgSecGroupMessageFormatter XML message formatter
 *	for CFSec.SecGroup.
 */
public class CFSecXMsgSecGroupMessageFormatter
{
	public CFSecXMsgSecGroupMessageFormatter() {
	}

	public static String formatSecGroupPKeyAttributes( String separator, CFSecSecGroupPKey pkey ) {
		String retval = CFLibXmlUtil.formatRequiredInt64( null,
				"ClusterId",
				pkey.getRequiredClusterId() )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
				"SecGroupId",
				pkey.getRequiredSecGroupId() );
		return( retval );
	}

	public static String formatSecGroupPKeyAttributes( String separator, CFSecSecGroupBuff buff ) {
		String retval = CFLibXmlUtil.formatRequiredInt64( separator,
					"ClusterId",
					buff.getRequiredClusterId() )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"SecGroupId",
					buff.getRequiredSecGroupId() );
		return( retval );
	}

	public static String formatSecGroupBuffAttributes( String separator, CFSecSecGroupBuff buff ) {
		String retval = CFSecXMsgSecGroupMessageFormatter.formatSecGroupPKeyAttributes( separator, buff )
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
					"Name",
					buff.getRequiredName() )
			+	CFLibXmlUtil.formatRequiredBoolean( separator,
					"IsVisible",
					buff.getRequiredIsVisible() );
		return( retval );
	}

	public static String formatSecGroupRqstCreate( String separator, CFSecSecGroupBuff buff ) {
		String retval = "<RqstSecGroupCreate "
			+	formatSecGroupBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecGroupRqstRead( String separator, CFSecSecGroupPKey pkey ) {
		String retval = "<RqstSecGroupRead "
			+	formatSecGroupPKeyAttributes( separator, pkey )
			+	" />";
		return( retval );
	}

	public static String formatSecGroupRqstRead( String separator, CFSecSecGroupBuff buff ) {
		String retval = "<RqstSecGroupRead "
			+	formatSecGroupPKeyAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecGroupRqstRead( String separator,
		long argClusterId,
		int argSecGroupId )
	{
		String retval = "<RqstSecGroupRead "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"SecGroupId",
					argSecGroupId )
			+	" />";
		return( retval );
	}

	public static String formatSecGroupRqstReadAll( String separator ) {
		String retval = "<RqstSecGroupReadAll />";
		return( retval );
	}

	public static String formatSecGroupRqstRdByIdIdx( String separator,
		long argClusterId,
		int argSecGroupId )
	{
		String retval = "<RqstSecGroupRead "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"SecGroupId",
					argSecGroupId )
			+	" />";
		return( retval );
	}

	public static String formatSecGroupRqstRdByClusterIdx( String separator,
		long argClusterId )
	{
		String retval = "<RqstSecGroupRdByClusterIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	" />";
		return( retval );
	}

	public static String formatSecGroupRqstRdByClusterVisIdx( String separator,
		long argClusterId,
		boolean argIsVisible )
	{
		String retval = "<RqstSecGroupRdByClusterVisIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredBoolean( separator,
					"IsVisible",
					argIsVisible )
			+	" />";
		return( retval );
	}

	public static String formatSecGroupRqstRdByUNameIdx( String separator,
		long argClusterId,
		String argName )
	{
		String retval = "<RqstSecGroupRdByUNameIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredXmlString( separator,
					"Name",
					argName )
			+	" />";
		return( retval );
	}

	public static String formatSecGroupRqstLock( String separator, CFSecSecGroupPKey pkey ) {
		String retval = "<RqstSecGroupLock "
			+	formatSecGroupPKeyAttributes( separator, pkey )
			+	" />";
		return( retval );
	}

	public static String formatSecGroupRqstLock( String separator, CFSecSecGroupBuff buff ) {
		String retval = "<RqstSecGroupLock "
			+	formatSecGroupPKeyAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecGroupRqstLock( String separator,
		long argClusterId,
		int argSecGroupId )
	{
		String retval = "<RqstSecGroupLock "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"SecGroupId",
					argSecGroupId )
			+	" />";
		return( retval );
	}

	public static String formatSecGroupRqstUpdate( String separator, CFSecSecGroupBuff buff ) {
		String retval = "<RqstSecGroupUpdate "
			+	formatSecGroupBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecGroupRqstDelete( String separator, CFSecSecGroupBuff buff ) {
		String retval = "<RqstSecGroupDelete "
				+	formatSecGroupPKeyAttributes( separator, buff )
				+	CFLibXmlUtil.formatRequiredInt32( separator,
						"Revision",
						buff.getRequiredRevision() )
				+	" />";
		return( retval );
	}

	public static String formatSecGroupRqstDelByIdIdx( String separator,
		long argClusterId,
		int argSecGroupId )
	{
		String retval = "<RqstSecGroupDelete "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"SecGroupId",
					argSecGroupId )
			+	" />";
		return( retval );
	}

	public static String formatSecGroupRqstDelByClusterIdx( String separator,
		long argClusterId )
	{
		String retval = "<RqstSecGroupDelByClusterIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	" />";
		return( retval );
	}

	public static String formatSecGroupRqstDelByClusterVisIdx( String separator,
		long argClusterId,
		boolean argIsVisible )
	{
		String retval = "<RqstSecGroupDelByClusterVisIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredBoolean( separator,
					"IsVisible",
					argIsVisible )
			+	" />";
		return( retval );
	}

	public static String formatSecGroupRqstDelByUNameIdx( String separator,
		long argClusterId,
		String argName )
	{
		String retval = "<RqstSecGroupDelByUNameIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredXmlString( separator,
					"Name",
					argName )
			+	" />";
		return( retval );
	}

	public static String formatSecGroupRspnSingleOpenTag() {
		String retval = "<RspnSecGroupReadSingle>";
		return( retval );
	}

	public static String formatSecGroupRspnSingleCloseTag() {
		String retval = "</RspnSecGroupReadSingle>";
		return( retval );
	}

	public static String formatSecGroupRspnListOpenTag() {
		String retval = "<RspnSecGroupReadList>";
		return( retval );
	}

	public static String formatSecGroupRspnListCloseTag() {
		String retval = "</RspnSecGroupReadList>";
		return( retval );
	}

	public static String formatSecGroupRspnRec( String separator, CFSecSecGroupBuff buff ) {
		String retval = "<SecGroup "
			+	formatSecGroupBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecGroupRspnDerivedRec( String separator, CFSecSecGroupBuff buff ) {
		String retval;
		retval = formatSecGroupRspnRec( separator, buff );
		return( retval );
	}

	public static String formatSecGroupRspnCreated( String separator, CFSecSecGroupBuff buff ) {
		String retval = "<RspnSecGroupCreated "
			+	formatSecGroupBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecGroupRspnLocked( String separator, CFSecSecGroupBuff buff ) {
		String retval = "<RspnSecGroupLocked "
			+	formatSecGroupBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecGroupRspnUpdated( String separator, CFSecSecGroupBuff buff ) {
		String retval = "<RspnSecGroupUpdated "
			+	formatSecGroupBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecGroupRspnDeleted() {
		String retval = "<RspnSecGroupDeleted />";
		return( retval );
	}
}
