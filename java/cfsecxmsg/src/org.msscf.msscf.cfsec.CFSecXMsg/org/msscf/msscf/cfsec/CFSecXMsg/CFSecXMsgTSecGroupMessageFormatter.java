
// Description: Java 11 XML Message message formatter for CFSec.TSecGroup

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
 *	CFSecXMsgTSecGroupMessageFormatter XML message formatter
 *	for CFSec.TSecGroup.
 */
public class CFSecXMsgTSecGroupMessageFormatter
{
	public CFSecXMsgTSecGroupMessageFormatter() {
	}

	public static String formatTSecGroupPKeyAttributes( String separator, CFSecTSecGroupPKey pkey ) {
		String retval = CFLibXmlUtil.formatRequiredInt64( null,
				"TenantId",
				pkey.getRequiredTenantId() )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
				"TSecGroupId",
				pkey.getRequiredTSecGroupId() );
		return( retval );
	}

	public static String formatTSecGroupPKeyAttributes( String separator, CFSecTSecGroupBuff buff ) {
		String retval = CFLibXmlUtil.formatRequiredInt64( separator,
					"TenantId",
					buff.getRequiredTenantId() )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"TSecGroupId",
					buff.getRequiredTSecGroupId() );
		return( retval );
	}

	public static String formatTSecGroupBuffAttributes( String separator, CFSecTSecGroupBuff buff ) {
		String retval = CFSecXMsgTSecGroupMessageFormatter.formatTSecGroupPKeyAttributes( separator, buff )
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

	public static String formatTSecGroupRqstCreate( String separator, CFSecTSecGroupBuff buff ) {
		String retval = "<RqstTSecGroupCreate "
			+	formatTSecGroupBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatTSecGroupRqstRead( String separator, CFSecTSecGroupPKey pkey ) {
		String retval = "<RqstTSecGroupRead "
			+	formatTSecGroupPKeyAttributes( separator, pkey )
			+	" />";
		return( retval );
	}

	public static String formatTSecGroupRqstRead( String separator, CFSecTSecGroupBuff buff ) {
		String retval = "<RqstTSecGroupRead "
			+	formatTSecGroupPKeyAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatTSecGroupRqstRead( String separator,
		long argTenantId,
		int argTSecGroupId )
	{
		String retval = "<RqstTSecGroupRead "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"TSecGroupId",
					argTSecGroupId )
			+	" />";
		return( retval );
	}

	public static String formatTSecGroupRqstReadAll( String separator ) {
		String retval = "<RqstTSecGroupReadAll />";
		return( retval );
	}

	public static String formatTSecGroupRqstRdByIdIdx( String separator,
		long argTenantId,
		int argTSecGroupId )
	{
		String retval = "<RqstTSecGroupRead "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"TSecGroupId",
					argTSecGroupId )
			+	" />";
		return( retval );
	}

	public static String formatTSecGroupRqstRdByTenantIdx( String separator,
		long argTenantId )
	{
		String retval = "<RqstTSecGroupRdByTenantIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	" />";
		return( retval );
	}

	public static String formatTSecGroupRqstRdByTenantVisIdx( String separator,
		long argTenantId,
		boolean argIsVisible )
	{
		String retval = "<RqstTSecGroupRdByTenantVisIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredBoolean( separator,
					"IsVisible",
					argIsVisible )
			+	" />";
		return( retval );
	}

	public static String formatTSecGroupRqstRdByUNameIdx( String separator,
		long argTenantId,
		String argName )
	{
		String retval = "<RqstTSecGroupRdByUNameIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredXmlString( separator,
					"Name",
					argName )
			+	" />";
		return( retval );
	}

	public static String formatTSecGroupRqstLock( String separator, CFSecTSecGroupPKey pkey ) {
		String retval = "<RqstTSecGroupLock "
			+	formatTSecGroupPKeyAttributes( separator, pkey )
			+	" />";
		return( retval );
	}

	public static String formatTSecGroupRqstLock( String separator, CFSecTSecGroupBuff buff ) {
		String retval = "<RqstTSecGroupLock "
			+	formatTSecGroupPKeyAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatTSecGroupRqstLock( String separator,
		long argTenantId,
		int argTSecGroupId )
	{
		String retval = "<RqstTSecGroupLock "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"TSecGroupId",
					argTSecGroupId )
			+	" />";
		return( retval );
	}

	public static String formatTSecGroupRqstUpdate( String separator, CFSecTSecGroupBuff buff ) {
		String retval = "<RqstTSecGroupUpdate "
			+	formatTSecGroupBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatTSecGroupRqstDelete( String separator, CFSecTSecGroupBuff buff ) {
		String retval = "<RqstTSecGroupDelete "
				+	formatTSecGroupPKeyAttributes( separator, buff )
				+	CFLibXmlUtil.formatRequiredInt32( separator,
						"Revision",
						buff.getRequiredRevision() )
				+	" />";
		return( retval );
	}

	public static String formatTSecGroupRqstDelByIdIdx( String separator,
		long argTenantId,
		int argTSecGroupId )
	{
		String retval = "<RqstTSecGroupDelete "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"TSecGroupId",
					argTSecGroupId )
			+	" />";
		return( retval );
	}

	public static String formatTSecGroupRqstDelByTenantIdx( String separator,
		long argTenantId )
	{
		String retval = "<RqstTSecGroupDelByTenantIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	" />";
		return( retval );
	}

	public static String formatTSecGroupRqstDelByTenantVisIdx( String separator,
		long argTenantId,
		boolean argIsVisible )
	{
		String retval = "<RqstTSecGroupDelByTenantVisIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredBoolean( separator,
					"IsVisible",
					argIsVisible )
			+	" />";
		return( retval );
	}

	public static String formatTSecGroupRqstDelByUNameIdx( String separator,
		long argTenantId,
		String argName )
	{
		String retval = "<RqstTSecGroupDelByUNameIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredXmlString( separator,
					"Name",
					argName )
			+	" />";
		return( retval );
	}

	public static String formatTSecGroupRspnSingleOpenTag() {
		String retval = "<RspnTSecGroupReadSingle>";
		return( retval );
	}

	public static String formatTSecGroupRspnSingleCloseTag() {
		String retval = "</RspnTSecGroupReadSingle>";
		return( retval );
	}

	public static String formatTSecGroupRspnListOpenTag() {
		String retval = "<RspnTSecGroupReadList>";
		return( retval );
	}

	public static String formatTSecGroupRspnListCloseTag() {
		String retval = "</RspnTSecGroupReadList>";
		return( retval );
	}

	public static String formatTSecGroupRspnRec( String separator, CFSecTSecGroupBuff buff ) {
		String retval = "<TSecGroup "
			+	formatTSecGroupBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatTSecGroupRspnDerivedRec( String separator, CFSecTSecGroupBuff buff ) {
		String retval;
		retval = formatTSecGroupRspnRec( separator, buff );
		return( retval );
	}

	public static String formatTSecGroupRspnCreated( String separator, CFSecTSecGroupBuff buff ) {
		String retval = "<RspnTSecGroupCreated "
			+	formatTSecGroupBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatTSecGroupRspnLocked( String separator, CFSecTSecGroupBuff buff ) {
		String retval = "<RspnTSecGroupLocked "
			+	formatTSecGroupBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatTSecGroupRspnUpdated( String separator, CFSecTSecGroupBuff buff ) {
		String retval = "<RspnTSecGroupUpdated "
			+	formatTSecGroupBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatTSecGroupRspnDeleted() {
		String retval = "<RspnTSecGroupDeleted />";
		return( retval );
	}
}
