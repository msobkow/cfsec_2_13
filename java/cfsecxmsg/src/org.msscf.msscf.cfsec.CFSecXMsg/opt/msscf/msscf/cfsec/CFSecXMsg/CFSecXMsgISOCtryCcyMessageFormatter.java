
// Description: Java 11 XML Message message formatter for CFSec.ISOCtryCcy

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
 *	CFSecXMsgISOCtryCcyMessageFormatter XML message formatter
 *	for CFSec.ISOCtryCcy.
 */
public class CFSecXMsgISOCtryCcyMessageFormatter
{
	public CFSecXMsgISOCtryCcyMessageFormatter() {
	}

	public static String formatISOCtryCcyPKeyAttributes( String separator, CFSecISOCtryCcyPKey pkey ) {
		String retval = CFLibXmlUtil.formatRequiredInt16( null,
				"ISOCtryId",
				pkey.getRequiredISOCtryId() )
			+	CFLibXmlUtil.formatRequiredInt16( separator,
				"ISOCcyId",
				pkey.getRequiredISOCcyId() );
		return( retval );
	}

	public static String formatISOCtryCcyPKeyAttributes( String separator, CFSecISOCtryCcyBuff buff ) {
		String retval = CFLibXmlUtil.formatRequiredInt16( separator,
					"ISOCtryId",
					buff.getRequiredISOCtryId() )
			+	CFLibXmlUtil.formatRequiredInt16( separator,
					"ISOCcyId",
					buff.getRequiredISOCcyId() );
		return( retval );
	}

	public static String formatISOCtryCcyBuffAttributes( String separator, CFSecISOCtryCcyBuff buff ) {
		String retval = CFSecXMsgISOCtryCcyMessageFormatter.formatISOCtryCcyPKeyAttributes( separator, buff )
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
					buff.getUpdatedAt() );
		return( retval );
	}

	public static String formatISOCtryCcyRqstCreate( String separator, CFSecISOCtryCcyBuff buff ) {
		String retval = "<RqstISOCtryCcyCreate "
			+	formatISOCtryCcyBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatISOCtryCcyRqstRead( String separator, CFSecISOCtryCcyPKey pkey ) {
		String retval = "<RqstISOCtryCcyRead "
			+	formatISOCtryCcyPKeyAttributes( separator, pkey )
			+	" />";
		return( retval );
	}

	public static String formatISOCtryCcyRqstRead( String separator, CFSecISOCtryCcyBuff buff ) {
		String retval = "<RqstISOCtryCcyRead "
			+	formatISOCtryCcyPKeyAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatISOCtryCcyRqstRead( String separator,
		short argISOCtryId,
		short argISOCcyId )
	{
		String retval = "<RqstISOCtryCcyRead "
			+	CFLibXmlUtil.formatRequiredInt16( null,
					"ISOCtryId",
					argISOCtryId )
			+	CFLibXmlUtil.formatRequiredInt16( separator,
					"ISOCcyId",
					argISOCcyId )
			+	" />";
		return( retval );
	}

	public static String formatISOCtryCcyRqstReadAll( String separator ) {
		String retval = "<RqstISOCtryCcyReadAll />";
		return( retval );
	}

	public static String formatISOCtryCcyRqstRdByIdIdx( String separator,
		short argISOCtryId,
		short argISOCcyId )
	{
		String retval = "<RqstISOCtryCcyRead "
			+	CFLibXmlUtil.formatRequiredInt16( null,
					"ISOCtryId",
					argISOCtryId )
			+	CFLibXmlUtil.formatRequiredInt16( separator,
					"ISOCcyId",
					argISOCcyId )
			+	" />";
		return( retval );
	}

	public static String formatISOCtryCcyRqstRdByCtryIdx( String separator,
		short argISOCtryId )
	{
		String retval = "<RqstISOCtryCcyRdByCtryIdx "
			+	CFLibXmlUtil.formatRequiredInt16( null,
					"ISOCtryId",
					argISOCtryId )
			+	" />";
		return( retval );
	}

	public static String formatISOCtryCcyRqstRdByCcyIdx( String separator,
		short argISOCcyId )
	{
		String retval = "<RqstISOCtryCcyRdByCcyIdx "
			+	CFLibXmlUtil.formatRequiredInt16( null,
					"ISOCcyId",
					argISOCcyId )
			+	" />";
		return( retval );
	}

	public static String formatISOCtryCcyRqstLock( String separator, CFSecISOCtryCcyPKey pkey ) {
		String retval = "<RqstISOCtryCcyLock "
			+	formatISOCtryCcyPKeyAttributes( separator, pkey )
			+	" />";
		return( retval );
	}

	public static String formatISOCtryCcyRqstLock( String separator, CFSecISOCtryCcyBuff buff ) {
		String retval = "<RqstISOCtryCcyLock "
			+	formatISOCtryCcyPKeyAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatISOCtryCcyRqstLock( String separator,
		short argISOCtryId,
		short argISOCcyId )
	{
		String retval = "<RqstISOCtryCcyLock "
			+	CFLibXmlUtil.formatRequiredInt16( null,
					"ISOCtryId",
					argISOCtryId )
			+	CFLibXmlUtil.formatRequiredInt16( separator,
					"ISOCcyId",
					argISOCcyId )
			+	" />";
		return( retval );
	}

	public static String formatISOCtryCcyRqstUpdate( String separator, CFSecISOCtryCcyBuff buff ) {
		String retval = "<RqstISOCtryCcyUpdate "
			+	formatISOCtryCcyBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatISOCtryCcyRqstDelete( String separator, CFSecISOCtryCcyBuff buff ) {
		String retval = "<RqstISOCtryCcyDelete "
				+	formatISOCtryCcyPKeyAttributes( separator, buff )
				+	CFLibXmlUtil.formatRequiredInt32( separator,
						"Revision",
						buff.getRequiredRevision() )
				+	" />";
		return( retval );
	}

	public static String formatISOCtryCcyRqstDelByIdIdx( String separator,
		short argISOCtryId,
		short argISOCcyId )
	{
		String retval = "<RqstISOCtryCcyDelete "
			+	CFLibXmlUtil.formatRequiredInt16( null,
					"ISOCtryId",
					argISOCtryId )
			+	CFLibXmlUtil.formatRequiredInt16( separator,
					"ISOCcyId",
					argISOCcyId )
			+	" />";
		return( retval );
	}

	public static String formatISOCtryCcyRqstDelByCtryIdx( String separator,
		short argISOCtryId )
	{
		String retval = "<RqstISOCtryCcyDelByCtryIdx "
			+	CFLibXmlUtil.formatRequiredInt16( null,
					"ISOCtryId",
					argISOCtryId )
			+	" />";
		return( retval );
	}

	public static String formatISOCtryCcyRqstDelByCcyIdx( String separator,
		short argISOCcyId )
	{
		String retval = "<RqstISOCtryCcyDelByCcyIdx "
			+	CFLibXmlUtil.formatRequiredInt16( null,
					"ISOCcyId",
					argISOCcyId )
			+	" />";
		return( retval );
	}

	public static String formatISOCtryCcyRspnSingleOpenTag() {
		String retval = "<RspnISOCtryCcyReadSingle>";
		return( retval );
	}

	public static String formatISOCtryCcyRspnSingleCloseTag() {
		String retval = "</RspnISOCtryCcyReadSingle>";
		return( retval );
	}

	public static String formatISOCtryCcyRspnListOpenTag() {
		String retval = "<RspnISOCtryCcyReadList>";
		return( retval );
	}

	public static String formatISOCtryCcyRspnListCloseTag() {
		String retval = "</RspnISOCtryCcyReadList>";
		return( retval );
	}

	public static String formatISOCtryCcyRspnRec( String separator, CFSecISOCtryCcyBuff buff ) {
		String retval = "<ISOCtryCcy "
			+	formatISOCtryCcyBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatISOCtryCcyRspnDerivedRec( String separator, CFSecISOCtryCcyBuff buff ) {
		String retval;
		retval = formatISOCtryCcyRspnRec( separator, buff );
		return( retval );
	}

	public static String formatISOCtryCcyRspnCreated( String separator, CFSecISOCtryCcyBuff buff ) {
		String retval = "<RspnISOCtryCcyCreated "
			+	formatISOCtryCcyBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatISOCtryCcyRspnLocked( String separator, CFSecISOCtryCcyBuff buff ) {
		String retval = "<RspnISOCtryCcyLocked "
			+	formatISOCtryCcyBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatISOCtryCcyRspnUpdated( String separator, CFSecISOCtryCcyBuff buff ) {
		String retval = "<RspnISOCtryCcyUpdated "
			+	formatISOCtryCcyBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatISOCtryCcyRspnDeleted() {
		String retval = "<RspnISOCtryCcyDeleted />";
		return( retval );
	}
}
