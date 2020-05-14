
// Description: Java 11 XML Message message formatter for CFSec.ISOCtry

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
 *	CFSecXMsgISOCtryMessageFormatter XML message formatter
 *	for CFSec.ISOCtry.
 */
public class CFSecXMsgISOCtryMessageFormatter
{
	public CFSecXMsgISOCtryMessageFormatter() {
	}

	public static String formatISOCtryPKeyAttributes( String separator, CFSecISOCtryPKey pkey ) {
		String retval = CFLibXmlUtil.formatRequiredInt16( null,
				"ISOCtryId",
				pkey.getRequiredISOCtryId() );
		return( retval );
	}

	public static String formatISOCtryPKeyAttributes( String separator, CFSecISOCtryBuff buff ) {
		String retval = CFLibXmlUtil.formatRequiredInt16( separator,
					"ISOCtryId",
					buff.getRequiredISOCtryId() );
		return( retval );
	}

	public static String formatISOCtryBuffAttributes( String separator, CFSecISOCtryBuff buff ) {
		String retval = CFSecXMsgISOCtryMessageFormatter.formatISOCtryPKeyAttributes( separator, buff )
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
					"ISOCode",
					buff.getRequiredISOCode() )
			+	CFLibXmlUtil.formatRequiredXmlString( separator,
					"Name",
					buff.getRequiredName() );
		return( retval );
	}

	public static String formatISOCtryRqstCreate( String separator, CFSecISOCtryBuff buff ) {
		String retval = "<RqstISOCtryCreate "
			+	formatISOCtryBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatISOCtryRqstRead( String separator, CFSecISOCtryPKey pkey ) {
		String retval = "<RqstISOCtryRead "
			+	formatISOCtryPKeyAttributes( separator, pkey )
			+	" />";
		return( retval );
	}

	public static String formatISOCtryRqstRead( String separator, CFSecISOCtryBuff buff ) {
		String retval = "<RqstISOCtryRead "
			+	formatISOCtryPKeyAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatISOCtryRqstRead( String separator,
		short argISOCtryId )
	{
		String retval = "<RqstISOCtryRead "
			+	CFLibXmlUtil.formatRequiredInt16( null,
					"ISOCtryId",
					argISOCtryId )
			+	" />";
		return( retval );
	}

	public static String formatISOCtryRqstReadAll( String separator ) {
		String retval = "<RqstISOCtryReadAll />";
		return( retval );
	}

	public static String formatISOCtryRqstRdByIdIdx( String separator,
		short argISOCtryId )
	{
		String retval = "<RqstISOCtryRead "
			+	CFLibXmlUtil.formatRequiredInt16( null,
					"ISOCtryId",
					argISOCtryId )
			+	" />";
		return( retval );
	}

	public static String formatISOCtryRqstRdByISOCodeIdx( String separator,
		String argISOCode )
	{
		String retval = "<RqstISOCtryRdByISOCodeIdx "
			+	CFLibXmlUtil.formatRequiredXmlString( null,
					"ISOCode",
					argISOCode )
			+	" />";
		return( retval );
	}

	public static String formatISOCtryRqstRdByNameIdx( String separator,
		String argName )
	{
		String retval = "<RqstISOCtryRdByNameIdx "
			+	CFLibXmlUtil.formatRequiredXmlString( null,
					"Name",
					argName )
			+	" />";
		return( retval );
	}

	public static String formatISOCtryRqstLock( String separator, CFSecISOCtryPKey pkey ) {
		String retval = "<RqstISOCtryLock "
			+	formatISOCtryPKeyAttributes( separator, pkey )
			+	" />";
		return( retval );
	}

	public static String formatISOCtryRqstLock( String separator, CFSecISOCtryBuff buff ) {
		String retval = "<RqstISOCtryLock "
			+	formatISOCtryPKeyAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatISOCtryRqstLock( String separator,
		short argISOCtryId )
	{
		String retval = "<RqstISOCtryLock "
			+	CFLibXmlUtil.formatRequiredInt16( null,
					"ISOCtryId",
					argISOCtryId )
			+	" />";
		return( retval );
	}

	public static String formatISOCtryRqstUpdate( String separator, CFSecISOCtryBuff buff ) {
		String retval = "<RqstISOCtryUpdate "
			+	formatISOCtryBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatISOCtryRqstDelete( String separator, CFSecISOCtryBuff buff ) {
		String retval = "<RqstISOCtryDelete "
				+	formatISOCtryPKeyAttributes( separator, buff )
				+	CFLibXmlUtil.formatRequiredInt32( separator,
						"Revision",
						buff.getRequiredRevision() )
				+	" />";
		return( retval );
	}

	public static String formatISOCtryRqstDelByIdIdx( String separator,
		short argISOCtryId )
	{
		String retval = "<RqstISOCtryDelete "
			+	CFLibXmlUtil.formatRequiredInt16( null,
					"ISOCtryId",
					argISOCtryId )
			+	" />";
		return( retval );
	}

	public static String formatISOCtryRqstDelByISOCodeIdx( String separator,
		String argISOCode )
	{
		String retval = "<RqstISOCtryDelByISOCodeIdx "
			+	CFLibXmlUtil.formatRequiredXmlString( null,
					"ISOCode",
					argISOCode )
			+	" />";
		return( retval );
	}

	public static String formatISOCtryRqstDelByNameIdx( String separator,
		String argName )
	{
		String retval = "<RqstISOCtryDelByNameIdx "
			+	CFLibXmlUtil.formatRequiredXmlString( null,
					"Name",
					argName )
			+	" />";
		return( retval );
	}

	public static String formatISOCtryRspnSingleOpenTag() {
		String retval = "<RspnISOCtryReadSingle>";
		return( retval );
	}

	public static String formatISOCtryRspnSingleCloseTag() {
		String retval = "</RspnISOCtryReadSingle>";
		return( retval );
	}

	public static String formatISOCtryRspnListOpenTag() {
		String retval = "<RspnISOCtryReadList>";
		return( retval );
	}

	public static String formatISOCtryRspnListCloseTag() {
		String retval = "</RspnISOCtryReadList>";
		return( retval );
	}

	public static String formatISOCtryRspnRec( String separator, CFSecISOCtryBuff buff ) {
		String retval = "<ISOCtry "
			+	formatISOCtryBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatISOCtryRspnDerivedRec( String separator, CFSecISOCtryBuff buff ) {
		String retval;
		retval = formatISOCtryRspnRec( separator, buff );
		return( retval );
	}

	public static String formatISOCtryRspnCreated( String separator, CFSecISOCtryBuff buff ) {
		String retval = "<RspnISOCtryCreated "
			+	formatISOCtryBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatISOCtryRspnLocked( String separator, CFSecISOCtryBuff buff ) {
		String retval = "<RspnISOCtryLocked "
			+	formatISOCtryBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatISOCtryRspnUpdated( String separator, CFSecISOCtryBuff buff ) {
		String retval = "<RspnISOCtryUpdated "
			+	formatISOCtryBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatISOCtryRspnDeleted() {
		String retval = "<RspnISOCtryDeleted />";
		return( retval );
	}
}
