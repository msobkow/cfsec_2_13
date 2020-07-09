
// Description: Java 11 XML Message message formatter for CFSec.ISOCtryLang

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
 *	CFSecXMsgISOCtryLangMessageFormatter XML message formatter
 *	for CFSec.ISOCtryLang.
 */
public class CFSecXMsgISOCtryLangMessageFormatter
{
	public CFSecXMsgISOCtryLangMessageFormatter() {
	}

	public static String formatISOCtryLangPKeyAttributes( String separator, CFSecISOCtryLangPKey pkey ) {
		String retval = CFLibXmlUtil.formatRequiredInt16( null,
				"ISOCtryId",
				pkey.getRequiredISOCtryId() )
			+	CFLibXmlUtil.formatRequiredInt16( separator,
				"ISOLangId",
				pkey.getRequiredISOLangId() );
		return( retval );
	}

	public static String formatISOCtryLangPKeyAttributes( String separator, CFSecISOCtryLangBuff buff ) {
		String retval = CFLibXmlUtil.formatRequiredInt16( separator,
					"ISOCtryId",
					buff.getRequiredISOCtryId() )
			+	CFLibXmlUtil.formatRequiredInt16( separator,
					"ISOLangId",
					buff.getRequiredISOLangId() );
		return( retval );
	}

	public static String formatISOCtryLangBuffAttributes( String separator, CFSecISOCtryLangBuff buff ) {
		String retval = CFSecXMsgISOCtryLangMessageFormatter.formatISOCtryLangPKeyAttributes( separator, buff )
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

	public static String formatISOCtryLangRqstCreate( String separator, CFSecISOCtryLangBuff buff ) {
		String retval = "<RqstISOCtryLangCreate "
			+	formatISOCtryLangBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatISOCtryLangRqstRead( String separator, CFSecISOCtryLangPKey pkey ) {
		String retval = "<RqstISOCtryLangRead "
			+	formatISOCtryLangPKeyAttributes( separator, pkey )
			+	" />";
		return( retval );
	}

	public static String formatISOCtryLangRqstRead( String separator, CFSecISOCtryLangBuff buff ) {
		String retval = "<RqstISOCtryLangRead "
			+	formatISOCtryLangPKeyAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatISOCtryLangRqstRead( String separator,
		short argISOCtryId,
		short argISOLangId )
	{
		String retval = "<RqstISOCtryLangRead "
			+	CFLibXmlUtil.formatRequiredInt16( null,
					"ISOCtryId",
					argISOCtryId )
			+	CFLibXmlUtil.formatRequiredInt16( separator,
					"ISOLangId",
					argISOLangId )
			+	" />";
		return( retval );
	}

	public static String formatISOCtryLangRqstReadAll( String separator ) {
		String retval = "<RqstISOCtryLangReadAll />";
		return( retval );
	}

	public static String formatISOCtryLangRqstRdByIdIdx( String separator,
		short argISOCtryId,
		short argISOLangId )
	{
		String retval = "<RqstISOCtryLangRead "
			+	CFLibXmlUtil.formatRequiredInt16( null,
					"ISOCtryId",
					argISOCtryId )
			+	CFLibXmlUtil.formatRequiredInt16( separator,
					"ISOLangId",
					argISOLangId )
			+	" />";
		return( retval );
	}

	public static String formatISOCtryLangRqstRdByCtryIdx( String separator,
		short argISOCtryId )
	{
		String retval = "<RqstISOCtryLangRdByCtryIdx "
			+	CFLibXmlUtil.formatRequiredInt16( null,
					"ISOCtryId",
					argISOCtryId )
			+	" />";
		return( retval );
	}

	public static String formatISOCtryLangRqstRdByLangIdx( String separator,
		short argISOLangId )
	{
		String retval = "<RqstISOCtryLangRdByLangIdx "
			+	CFLibXmlUtil.formatRequiredInt16( null,
					"ISOLangId",
					argISOLangId )
			+	" />";
		return( retval );
	}

	public static String formatISOCtryLangRqstLock( String separator, CFSecISOCtryLangPKey pkey ) {
		String retval = "<RqstISOCtryLangLock "
			+	formatISOCtryLangPKeyAttributes( separator, pkey )
			+	" />";
		return( retval );
	}

	public static String formatISOCtryLangRqstLock( String separator, CFSecISOCtryLangBuff buff ) {
		String retval = "<RqstISOCtryLangLock "
			+	formatISOCtryLangPKeyAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatISOCtryLangRqstLock( String separator,
		short argISOCtryId,
		short argISOLangId )
	{
		String retval = "<RqstISOCtryLangLock "
			+	CFLibXmlUtil.formatRequiredInt16( null,
					"ISOCtryId",
					argISOCtryId )
			+	CFLibXmlUtil.formatRequiredInt16( separator,
					"ISOLangId",
					argISOLangId )
			+	" />";
		return( retval );
	}

	public static String formatISOCtryLangRqstUpdate( String separator, CFSecISOCtryLangBuff buff ) {
		String retval = "<RqstISOCtryLangUpdate "
			+	formatISOCtryLangBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatISOCtryLangRqstDelete( String separator, CFSecISOCtryLangBuff buff ) {
		String retval = "<RqstISOCtryLangDelete "
				+	formatISOCtryLangPKeyAttributes( separator, buff )
				+	CFLibXmlUtil.formatRequiredInt32( separator,
						"Revision",
						buff.getRequiredRevision() )
				+	" />";
		return( retval );
	}

	public static String formatISOCtryLangRqstDelByIdIdx( String separator,
		short argISOCtryId,
		short argISOLangId )
	{
		String retval = "<RqstISOCtryLangDelete "
			+	CFLibXmlUtil.formatRequiredInt16( null,
					"ISOCtryId",
					argISOCtryId )
			+	CFLibXmlUtil.formatRequiredInt16( separator,
					"ISOLangId",
					argISOLangId )
			+	" />";
		return( retval );
	}

	public static String formatISOCtryLangRqstDelByCtryIdx( String separator,
		short argISOCtryId )
	{
		String retval = "<RqstISOCtryLangDelByCtryIdx "
			+	CFLibXmlUtil.formatRequiredInt16( null,
					"ISOCtryId",
					argISOCtryId )
			+	" />";
		return( retval );
	}

	public static String formatISOCtryLangRqstDelByLangIdx( String separator,
		short argISOLangId )
	{
		String retval = "<RqstISOCtryLangDelByLangIdx "
			+	CFLibXmlUtil.formatRequiredInt16( null,
					"ISOLangId",
					argISOLangId )
			+	" />";
		return( retval );
	}

	public static String formatISOCtryLangRspnSingleOpenTag() {
		String retval = "<RspnISOCtryLangReadSingle>";
		return( retval );
	}

	public static String formatISOCtryLangRspnSingleCloseTag() {
		String retval = "</RspnISOCtryLangReadSingle>";
		return( retval );
	}

	public static String formatISOCtryLangRspnListOpenTag() {
		String retval = "<RspnISOCtryLangReadList>";
		return( retval );
	}

	public static String formatISOCtryLangRspnListCloseTag() {
		String retval = "</RspnISOCtryLangReadList>";
		return( retval );
	}

	public static String formatISOCtryLangRspnRec( String separator, CFSecISOCtryLangBuff buff ) {
		String retval = "<ISOCtryLang "
			+	formatISOCtryLangBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatISOCtryLangRspnDerivedRec( String separator, CFSecISOCtryLangBuff buff ) {
		String retval;
		retval = formatISOCtryLangRspnRec( separator, buff );
		return( retval );
	}

	public static String formatISOCtryLangRspnCreated( String separator, CFSecISOCtryLangBuff buff ) {
		String retval = "<RspnISOCtryLangCreated "
			+	formatISOCtryLangBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatISOCtryLangRspnLocked( String separator, CFSecISOCtryLangBuff buff ) {
		String retval = "<RspnISOCtryLangLocked "
			+	formatISOCtryLangBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatISOCtryLangRspnUpdated( String separator, CFSecISOCtryLangBuff buff ) {
		String retval = "<RspnISOCtryLangUpdated "
			+	formatISOCtryLangBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatISOCtryLangRspnDeleted() {
		String retval = "<RspnISOCtryLangDeleted />";
		return( retval );
	}
}
