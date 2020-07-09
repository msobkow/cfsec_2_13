
// Description: Java 11 XML Message message formatter for CFSec.TSecGroup

/*
 *	org.msscf.msscf.CFSec
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

package org.msscf.msscf.cfsec.CFSecXMsg;

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.apache.commons.codec.binary.Base64;
import org.xml.sax.*;
import com.github.msobkow.cflib.CFLib.*;
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
