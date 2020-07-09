
// Description: Java 11 XML Message message formatter for CFSec.SecGrpInc

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
 *	CFSecXMsgSecGrpIncMessageFormatter XML message formatter
 *	for CFSec.SecGrpInc.
 */
public class CFSecXMsgSecGrpIncMessageFormatter
{
	public CFSecXMsgSecGrpIncMessageFormatter() {
	}

	public static String formatSecGrpIncPKeyAttributes( String separator, CFSecSecGrpIncPKey pkey ) {
		String retval = CFLibXmlUtil.formatRequiredInt64( null,
				"ClusterId",
				pkey.getRequiredClusterId() )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
				"SecGrpIncId",
				pkey.getRequiredSecGrpIncId() );
		return( retval );
	}

	public static String formatSecGrpIncPKeyAttributes( String separator, CFSecSecGrpIncBuff buff ) {
		String retval = CFLibXmlUtil.formatRequiredInt64( separator,
					"ClusterId",
					buff.getRequiredClusterId() )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"SecGrpIncId",
					buff.getRequiredSecGrpIncId() );
		return( retval );
	}

	public static String formatSecGrpIncBuffAttributes( String separator, CFSecSecGrpIncBuff buff ) {
		String retval = CFSecXMsgSecGrpIncMessageFormatter.formatSecGrpIncPKeyAttributes( separator, buff )
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
					"IncludeGroupId",
					buff.getRequiredIncludeGroupId() );
		return( retval );
	}

	public static String formatSecGrpIncRqstCreate( String separator, CFSecSecGrpIncBuff buff ) {
		String retval = "<RqstSecGrpIncCreate "
			+	formatSecGrpIncBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecGrpIncRqstRead( String separator, CFSecSecGrpIncPKey pkey ) {
		String retval = "<RqstSecGrpIncRead "
			+	formatSecGrpIncPKeyAttributes( separator, pkey )
			+	" />";
		return( retval );
	}

	public static String formatSecGrpIncRqstRead( String separator, CFSecSecGrpIncBuff buff ) {
		String retval = "<RqstSecGrpIncRead "
			+	formatSecGrpIncPKeyAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecGrpIncRqstRead( String separator,
		long argClusterId,
		long argSecGrpIncId )
	{
		String retval = "<RqstSecGrpIncRead "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"SecGrpIncId",
					argSecGrpIncId )
			+	" />";
		return( retval );
	}

	public static String formatSecGrpIncRqstReadAll( String separator ) {
		String retval = "<RqstSecGrpIncReadAll />";
		return( retval );
	}

	public static String formatSecGrpIncRqstPageAll( String separator,
		Long priorClusterId,
		Long priorSecGrpIncId ) {
		String retval = "<RqstSecGrpIncPageAll "
			+	CFLibXmlUtil.formatOptionalInt64( null,
					"PriorClusterId",
					priorClusterId )
			+	CFLibXmlUtil.formatOptionalInt64( separator,
					"PriorSecGrpIncId",
					priorSecGrpIncId )
			+	" />";
		return( retval );
	}

	public static String formatSecGrpIncRqstRdByIdIdx( String separator,
		long argClusterId,
		long argSecGrpIncId )
	{
		String retval = "<RqstSecGrpIncRead "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"SecGrpIncId",
					argSecGrpIncId )
			+	" />";
		return( retval );
	}

	public static String formatSecGrpIncRqstRdByClusterIdx( String separator,
		long argClusterId )
	{
		String retval = "<RqstSecGrpIncRdByClusterIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	" />";
		return( retval );
	}

	public static String formatSecGrpIncRqstRdByGroupIdx( String separator,
		long argClusterId,
		int argSecGroupId )
	{
		String retval = "<RqstSecGrpIncRdByGroupIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"SecGroupId",
					argSecGroupId )
			+	" />";
		return( retval );
	}

	public static String formatSecGrpIncRqstRdByIncludeIdx( String separator,
		long argClusterId,
		int argIncludeGroupId )
	{
		String retval = "<RqstSecGrpIncRdByIncludeIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"IncludeGroupId",
					argIncludeGroupId )
			+	" />";
		return( retval );
	}

	public static String formatSecGrpIncRqstRdByUIncludeIdx( String separator,
		long argClusterId,
		int argSecGroupId,
		int argIncludeGroupId )
	{
		String retval = "<RqstSecGrpIncRdByUIncludeIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"SecGroupId",
					argSecGroupId )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"IncludeGroupId",
					argIncludeGroupId )
			+	" />";
		return( retval );
	}

	public static String formatSecGrpIncRqstPageByClusterIdx( String separator,
		long argClusterId,
		Long priorClusterId,
		Long priorSecGrpIncId )
	{
		String retval = "<RqstSecGrpIncPageByClusterIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatOptionalInt64( separator,
					"PriorClusterId",
					priorClusterId )
			+	CFLibXmlUtil.formatOptionalInt64( separator,
					"PriorSecGrpIncId",
					priorSecGrpIncId )
			+	" />";
		return( retval );
	}

	public static String formatSecGrpIncRqstPageByGroupIdx( String separator,
		long argClusterId,
		int argSecGroupId,
		Long priorClusterId,
		Long priorSecGrpIncId )
	{
		String retval = "<RqstSecGrpIncPageByGroupIdx "
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
					"PriorSecGrpIncId",
					priorSecGrpIncId )
			+	" />";
		return( retval );
	}

	public static String formatSecGrpIncRqstPageByIncludeIdx( String separator,
		long argClusterId,
		int argIncludeGroupId,
		Long priorClusterId,
		Long priorSecGrpIncId )
	{
		String retval = "<RqstSecGrpIncPageByIncludeIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"IncludeGroupId",
					argIncludeGroupId )
			+	CFLibXmlUtil.formatOptionalInt64( separator,
					"PriorClusterId",
					priorClusterId )
			+	CFLibXmlUtil.formatOptionalInt64( separator,
					"PriorSecGrpIncId",
					priorSecGrpIncId )
			+	" />";
		return( retval );
	}

	public static String formatSecGrpIncRqstLock( String separator, CFSecSecGrpIncPKey pkey ) {
		String retval = "<RqstSecGrpIncLock "
			+	formatSecGrpIncPKeyAttributes( separator, pkey )
			+	" />";
		return( retval );
	}

	public static String formatSecGrpIncRqstLock( String separator, CFSecSecGrpIncBuff buff ) {
		String retval = "<RqstSecGrpIncLock "
			+	formatSecGrpIncPKeyAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecGrpIncRqstLock( String separator,
		long argClusterId,
		long argSecGrpIncId )
	{
		String retval = "<RqstSecGrpIncLock "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"SecGrpIncId",
					argSecGrpIncId )
			+	" />";
		return( retval );
	}

	public static String formatSecGrpIncRqstUpdate( String separator, CFSecSecGrpIncBuff buff ) {
		String retval = "<RqstSecGrpIncUpdate "
			+	formatSecGrpIncBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecGrpIncRqstDelete( String separator, CFSecSecGrpIncBuff buff ) {
		String retval = "<RqstSecGrpIncDelete "
				+	formatSecGrpIncPKeyAttributes( separator, buff )
				+	CFLibXmlUtil.formatRequiredInt32( separator,
						"Revision",
						buff.getRequiredRevision() )
				+	" />";
		return( retval );
	}

	public static String formatSecGrpIncRqstDelByIdIdx( String separator,
		long argClusterId,
		long argSecGrpIncId )
	{
		String retval = "<RqstSecGrpIncDelete "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"SecGrpIncId",
					argSecGrpIncId )
			+	" />";
		return( retval );
	}

	public static String formatSecGrpIncRqstDelByClusterIdx( String separator,
		long argClusterId )
	{
		String retval = "<RqstSecGrpIncDelByClusterIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	" />";
		return( retval );
	}

	public static String formatSecGrpIncRqstDelByGroupIdx( String separator,
		long argClusterId,
		int argSecGroupId )
	{
		String retval = "<RqstSecGrpIncDelByGroupIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"SecGroupId",
					argSecGroupId )
			+	" />";
		return( retval );
	}

	public static String formatSecGrpIncRqstDelByIncludeIdx( String separator,
		long argClusterId,
		int argIncludeGroupId )
	{
		String retval = "<RqstSecGrpIncDelByIncludeIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"IncludeGroupId",
					argIncludeGroupId )
			+	" />";
		return( retval );
	}

	public static String formatSecGrpIncRqstDelByUIncludeIdx( String separator,
		long argClusterId,
		int argSecGroupId,
		int argIncludeGroupId )
	{
		String retval = "<RqstSecGrpIncDelByUIncludeIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"SecGroupId",
					argSecGroupId )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"IncludeGroupId",
					argIncludeGroupId )
			+	" />";
		return( retval );
	}

	public static String formatSecGrpIncRspnSingleOpenTag() {
		String retval = "<RspnSecGrpIncReadSingle>";
		return( retval );
	}

	public static String formatSecGrpIncRspnSingleCloseTag() {
		String retval = "</RspnSecGrpIncReadSingle>";
		return( retval );
	}

	public static String formatSecGrpIncRspnListOpenTag() {
		String retval = "<RspnSecGrpIncReadList>";
		return( retval );
	}

	public static String formatSecGrpIncRspnListCloseTag() {
		String retval = "</RspnSecGrpIncReadList>";
		return( retval );
	}

	public static String formatSecGrpIncRspnRec( String separator, CFSecSecGrpIncBuff buff ) {
		String retval = "<SecGrpInc "
			+	formatSecGrpIncBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecGrpIncRspnDerivedRec( String separator, CFSecSecGrpIncBuff buff ) {
		String retval;
		retval = formatSecGrpIncRspnRec( separator, buff );
		return( retval );
	}

	public static String formatSecGrpIncRspnCreated( String separator, CFSecSecGrpIncBuff buff ) {
		String retval = "<RspnSecGrpIncCreated "
			+	formatSecGrpIncBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecGrpIncRspnLocked( String separator, CFSecSecGrpIncBuff buff ) {
		String retval = "<RspnSecGrpIncLocked "
			+	formatSecGrpIncBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecGrpIncRspnUpdated( String separator, CFSecSecGrpIncBuff buff ) {
		String retval = "<RspnSecGrpIncUpdated "
			+	formatSecGrpIncBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecGrpIncRspnDeleted() {
		String retval = "<RspnSecGrpIncDeleted />";
		return( retval );
	}
}
