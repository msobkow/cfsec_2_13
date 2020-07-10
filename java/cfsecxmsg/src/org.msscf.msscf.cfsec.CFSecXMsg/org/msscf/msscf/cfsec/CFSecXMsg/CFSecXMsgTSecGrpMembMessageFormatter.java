
// Description: Java 11 XML Message message formatter for CFSec.TSecGrpMemb

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
import org.msscf.msscf.cflib.CFLib.*;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfsec.CFSecObj.*;

/*
 *	CFSecXMsgTSecGrpMembMessageFormatter XML message formatter
 *	for CFSec.TSecGrpMemb.
 */
public class CFSecXMsgTSecGrpMembMessageFormatter
{
	public CFSecXMsgTSecGrpMembMessageFormatter() {
	}

	public static String formatTSecGrpMembPKeyAttributes( String separator, CFSecTSecGrpMembPKey pkey ) {
		String retval = CFLibXmlUtil.formatRequiredInt64( null,
				"TenantId",
				pkey.getRequiredTenantId() )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
				"TSecGrpMembId",
				pkey.getRequiredTSecGrpMembId() );
		return( retval );
	}

	public static String formatTSecGrpMembPKeyAttributes( String separator, CFSecTSecGrpMembBuff buff ) {
		String retval = CFLibXmlUtil.formatRequiredInt64( separator,
					"TenantId",
					buff.getRequiredTenantId() )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"TSecGrpMembId",
					buff.getRequiredTSecGrpMembId() );
		return( retval );
	}

	public static String formatTSecGrpMembBuffAttributes( String separator, CFSecTSecGrpMembBuff buff ) {
		String retval = CFSecXMsgTSecGrpMembMessageFormatter.formatTSecGrpMembPKeyAttributes( separator, buff )
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
					"TSecGroupId",
					buff.getRequiredTSecGroupId() )
			+	CFLibXmlUtil.formatRequiredUuid( separator,
					"SecUserId",
					buff.getRequiredSecUserId() );
		return( retval );
	}

	public static String formatTSecGrpMembRqstCreate( String separator, CFSecTSecGrpMembBuff buff ) {
		String retval = "<RqstTSecGrpMembCreate "
			+	formatTSecGrpMembBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatTSecGrpMembRqstRead( String separator, CFSecTSecGrpMembPKey pkey ) {
		String retval = "<RqstTSecGrpMembRead "
			+	formatTSecGrpMembPKeyAttributes( separator, pkey )
			+	" />";
		return( retval );
	}

	public static String formatTSecGrpMembRqstRead( String separator, CFSecTSecGrpMembBuff buff ) {
		String retval = "<RqstTSecGrpMembRead "
			+	formatTSecGrpMembPKeyAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatTSecGrpMembRqstRead( String separator,
		long argTenantId,
		long argTSecGrpMembId )
	{
		String retval = "<RqstTSecGrpMembRead "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"TSecGrpMembId",
					argTSecGrpMembId )
			+	" />";
		return( retval );
	}

	public static String formatTSecGrpMembRqstReadAll( String separator ) {
		String retval = "<RqstTSecGrpMembReadAll />";
		return( retval );
	}

	public static String formatTSecGrpMembRqstPageAll( String separator,
		Long priorTenantId,
		Long priorTSecGrpMembId ) {
		String retval = "<RqstTSecGrpMembPageAll "
			+	CFLibXmlUtil.formatOptionalInt64( null,
					"PriorTenantId",
					priorTenantId )
			+	CFLibXmlUtil.formatOptionalInt64( separator,
					"PriorTSecGrpMembId",
					priorTSecGrpMembId )
			+	" />";
		return( retval );
	}

	public static String formatTSecGrpMembRqstRdByIdIdx( String separator,
		long argTenantId,
		long argTSecGrpMembId )
	{
		String retval = "<RqstTSecGrpMembRead "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"TSecGrpMembId",
					argTSecGrpMembId )
			+	" />";
		return( retval );
	}

	public static String formatTSecGrpMembRqstRdByTenantIdx( String separator,
		long argTenantId )
	{
		String retval = "<RqstTSecGrpMembRdByTenantIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	" />";
		return( retval );
	}

	public static String formatTSecGrpMembRqstRdByGroupIdx( String separator,
		long argTenantId,
		int argTSecGroupId )
	{
		String retval = "<RqstTSecGrpMembRdByGroupIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"TSecGroupId",
					argTSecGroupId )
			+	" />";
		return( retval );
	}

	public static String formatTSecGrpMembRqstRdByUserIdx( String separator,
		UUID argSecUserId )
	{
		String retval = "<RqstTSecGrpMembRdByUserIdx "
			+	CFLibXmlUtil.formatRequiredUuid( null,
					"SecUserId",
					argSecUserId )
			+	" />";
		return( retval );
	}

	public static String formatTSecGrpMembRqstRdByUUserIdx( String separator,
		long argTenantId,
		int argTSecGroupId,
		UUID argSecUserId )
	{
		String retval = "<RqstTSecGrpMembRdByUUserIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"TSecGroupId",
					argTSecGroupId )
			+	CFLibXmlUtil.formatRequiredUuid( separator,
					"SecUserId",
					argSecUserId )
			+	" />";
		return( retval );
	}

	public static String formatTSecGrpMembRqstPageByTenantIdx( String separator,
		long argTenantId,
		Long priorTenantId,
		Long priorTSecGrpMembId )
	{
		String retval = "<RqstTSecGrpMembPageByTenantIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatOptionalInt64( separator,
					"PriorTenantId",
					priorTenantId )
			+	CFLibXmlUtil.formatOptionalInt64( separator,
					"PriorTSecGrpMembId",
					priorTSecGrpMembId )
			+	" />";
		return( retval );
	}

	public static String formatTSecGrpMembRqstPageByGroupIdx( String separator,
		long argTenantId,
		int argTSecGroupId,
		Long priorTenantId,
		Long priorTSecGrpMembId )
	{
		String retval = "<RqstTSecGrpMembPageByGroupIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"TSecGroupId",
					argTSecGroupId )
			+	CFLibXmlUtil.formatOptionalInt64( separator,
					"PriorTenantId",
					priorTenantId )
			+	CFLibXmlUtil.formatOptionalInt64( separator,
					"PriorTSecGrpMembId",
					priorTSecGrpMembId )
			+	" />";
		return( retval );
	}

	public static String formatTSecGrpMembRqstPageByUserIdx( String separator,
		UUID argSecUserId,
		Long priorTenantId,
		Long priorTSecGrpMembId )
	{
		String retval = "<RqstTSecGrpMembPageByUserIdx "
			+	CFLibXmlUtil.formatRequiredUuid( null,
					"SecUserId",
					argSecUserId )
			+	CFLibXmlUtil.formatOptionalInt64( separator,
					"PriorTenantId",
					priorTenantId )
			+	CFLibXmlUtil.formatOptionalInt64( separator,
					"PriorTSecGrpMembId",
					priorTSecGrpMembId )
			+	" />";
		return( retval );
	}

	public static String formatTSecGrpMembRqstLock( String separator, CFSecTSecGrpMembPKey pkey ) {
		String retval = "<RqstTSecGrpMembLock "
			+	formatTSecGrpMembPKeyAttributes( separator, pkey )
			+	" />";
		return( retval );
	}

	public static String formatTSecGrpMembRqstLock( String separator, CFSecTSecGrpMembBuff buff ) {
		String retval = "<RqstTSecGrpMembLock "
			+	formatTSecGrpMembPKeyAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatTSecGrpMembRqstLock( String separator,
		long argTenantId,
		long argTSecGrpMembId )
	{
		String retval = "<RqstTSecGrpMembLock "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"TSecGrpMembId",
					argTSecGrpMembId )
			+	" />";
		return( retval );
	}

	public static String formatTSecGrpMembRqstUpdate( String separator, CFSecTSecGrpMembBuff buff ) {
		String retval = "<RqstTSecGrpMembUpdate "
			+	formatTSecGrpMembBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatTSecGrpMembRqstDelete( String separator, CFSecTSecGrpMembBuff buff ) {
		String retval = "<RqstTSecGrpMembDelete "
				+	formatTSecGrpMembPKeyAttributes( separator, buff )
				+	CFLibXmlUtil.formatRequiredInt32( separator,
						"Revision",
						buff.getRequiredRevision() )
				+	" />";
		return( retval );
	}

	public static String formatTSecGrpMembRqstDelByIdIdx( String separator,
		long argTenantId,
		long argTSecGrpMembId )
	{
		String retval = "<RqstTSecGrpMembDelete "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"TSecGrpMembId",
					argTSecGrpMembId )
			+	" />";
		return( retval );
	}

	public static String formatTSecGrpMembRqstDelByTenantIdx( String separator,
		long argTenantId )
	{
		String retval = "<RqstTSecGrpMembDelByTenantIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	" />";
		return( retval );
	}

	public static String formatTSecGrpMembRqstDelByGroupIdx( String separator,
		long argTenantId,
		int argTSecGroupId )
	{
		String retval = "<RqstTSecGrpMembDelByGroupIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"TSecGroupId",
					argTSecGroupId )
			+	" />";
		return( retval );
	}

	public static String formatTSecGrpMembRqstDelByUserIdx( String separator,
		UUID argSecUserId )
	{
		String retval = "<RqstTSecGrpMembDelByUserIdx "
			+	CFLibXmlUtil.formatRequiredUuid( null,
					"SecUserId",
					argSecUserId )
			+	" />";
		return( retval );
	}

	public static String formatTSecGrpMembRqstDelByUUserIdx( String separator,
		long argTenantId,
		int argTSecGroupId,
		UUID argSecUserId )
	{
		String retval = "<RqstTSecGrpMembDelByUUserIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"TSecGroupId",
					argTSecGroupId )
			+	CFLibXmlUtil.formatRequiredUuid( separator,
					"SecUserId",
					argSecUserId )
			+	" />";
		return( retval );
	}

	public static String formatTSecGrpMembRspnSingleOpenTag() {
		String retval = "<RspnTSecGrpMembReadSingle>";
		return( retval );
	}

	public static String formatTSecGrpMembRspnSingleCloseTag() {
		String retval = "</RspnTSecGrpMembReadSingle>";
		return( retval );
	}

	public static String formatTSecGrpMembRspnListOpenTag() {
		String retval = "<RspnTSecGrpMembReadList>";
		return( retval );
	}

	public static String formatTSecGrpMembRspnListCloseTag() {
		String retval = "</RspnTSecGrpMembReadList>";
		return( retval );
	}

	public static String formatTSecGrpMembRspnRec( String separator, CFSecTSecGrpMembBuff buff ) {
		String retval = "<TSecGrpMemb "
			+	formatTSecGrpMembBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatTSecGrpMembRspnDerivedRec( String separator, CFSecTSecGrpMembBuff buff ) {
		String retval;
		retval = formatTSecGrpMembRspnRec( separator, buff );
		return( retval );
	}

	public static String formatTSecGrpMembRspnCreated( String separator, CFSecTSecGrpMembBuff buff ) {
		String retval = "<RspnTSecGrpMembCreated "
			+	formatTSecGrpMembBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatTSecGrpMembRspnLocked( String separator, CFSecTSecGrpMembBuff buff ) {
		String retval = "<RspnTSecGrpMembLocked "
			+	formatTSecGrpMembBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatTSecGrpMembRspnUpdated( String separator, CFSecTSecGrpMembBuff buff ) {
		String retval = "<RspnTSecGrpMembUpdated "
			+	formatTSecGrpMembBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatTSecGrpMembRspnDeleted() {
		String retval = "<RspnTSecGrpMembDeleted />";
		return( retval );
	}
}
