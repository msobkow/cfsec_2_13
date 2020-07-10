
// Description: Java 11 XML Message message formatter for CFSec.ISOCcy

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
 *	CFSecXMsgISOCcyMessageFormatter XML message formatter
 *	for CFSec.ISOCcy.
 */
public class CFSecXMsgISOCcyMessageFormatter
{
	public CFSecXMsgISOCcyMessageFormatter() {
	}

	public static String formatISOCcyPKeyAttributes( String separator, CFSecISOCcyPKey pkey ) {
		String retval = CFLibXmlUtil.formatRequiredInt16( null,
				"ISOCcyId",
				pkey.getRequiredISOCcyId() );
		return( retval );
	}

	public static String formatISOCcyPKeyAttributes( String separator, CFSecISOCcyBuff buff ) {
		String retval = CFLibXmlUtil.formatRequiredInt16( separator,
					"ISOCcyId",
					buff.getRequiredISOCcyId() );
		return( retval );
	}

	public static String formatISOCcyBuffAttributes( String separator, CFSecISOCcyBuff buff ) {
		String retval = CFSecXMsgISOCcyMessageFormatter.formatISOCcyPKeyAttributes( separator, buff )
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
					buff.getRequiredName() )
			+	CFLibXmlUtil.formatOptionalXmlString( separator,
					"UnitSymbol",
					buff.getOptionalUnitSymbol() )
			+	CFLibXmlUtil.formatRequiredInt16( separator,
					"Precis",
					buff.getRequiredPrecis() );
		return( retval );
	}

	public static String formatISOCcyRqstCreate( String separator, CFSecISOCcyBuff buff ) {
		String retval = "<RqstISOCcyCreate "
			+	formatISOCcyBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatISOCcyRqstRead( String separator, CFSecISOCcyPKey pkey ) {
		String retval = "<RqstISOCcyRead "
			+	formatISOCcyPKeyAttributes( separator, pkey )
			+	" />";
		return( retval );
	}

	public static String formatISOCcyRqstRead( String separator, CFSecISOCcyBuff buff ) {
		String retval = "<RqstISOCcyRead "
			+	formatISOCcyPKeyAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatISOCcyRqstRead( String separator,
		short argISOCcyId )
	{
		String retval = "<RqstISOCcyRead "
			+	CFLibXmlUtil.formatRequiredInt16( null,
					"ISOCcyId",
					argISOCcyId )
			+	" />";
		return( retval );
	}

	public static String formatISOCcyRqstReadAll( String separator ) {
		String retval = "<RqstISOCcyReadAll />";
		return( retval );
	}

	public static String formatISOCcyRqstRdByIdIdx( String separator,
		short argISOCcyId )
	{
		String retval = "<RqstISOCcyRead "
			+	CFLibXmlUtil.formatRequiredInt16( null,
					"ISOCcyId",
					argISOCcyId )
			+	" />";
		return( retval );
	}

	public static String formatISOCcyRqstRdByCcyCdIdx( String separator,
		String argISOCode )
	{
		String retval = "<RqstISOCcyRdByCcyCdIdx "
			+	CFLibXmlUtil.formatRequiredXmlString( null,
					"ISOCode",
					argISOCode )
			+	" />";
		return( retval );
	}

	public static String formatISOCcyRqstRdByCcyNmIdx( String separator,
		String argName )
	{
		String retval = "<RqstISOCcyRdByCcyNmIdx "
			+	CFLibXmlUtil.formatRequiredXmlString( null,
					"Name",
					argName )
			+	" />";
		return( retval );
	}

	public static String formatISOCcyRqstLock( String separator, CFSecISOCcyPKey pkey ) {
		String retval = "<RqstISOCcyLock "
			+	formatISOCcyPKeyAttributes( separator, pkey )
			+	" />";
		return( retval );
	}

	public static String formatISOCcyRqstLock( String separator, CFSecISOCcyBuff buff ) {
		String retval = "<RqstISOCcyLock "
			+	formatISOCcyPKeyAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatISOCcyRqstLock( String separator,
		short argISOCcyId )
	{
		String retval = "<RqstISOCcyLock "
			+	CFLibXmlUtil.formatRequiredInt16( null,
					"ISOCcyId",
					argISOCcyId )
			+	" />";
		return( retval );
	}

	public static String formatISOCcyRqstUpdate( String separator, CFSecISOCcyBuff buff ) {
		String retval = "<RqstISOCcyUpdate "
			+	formatISOCcyBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatISOCcyRqstDelete( String separator, CFSecISOCcyBuff buff ) {
		String retval = "<RqstISOCcyDelete "
				+	formatISOCcyPKeyAttributes( separator, buff )
				+	CFLibXmlUtil.formatRequiredInt32( separator,
						"Revision",
						buff.getRequiredRevision() )
				+	" />";
		return( retval );
	}

	public static String formatISOCcyRqstDelByIdIdx( String separator,
		short argISOCcyId )
	{
		String retval = "<RqstISOCcyDelete "
			+	CFLibXmlUtil.formatRequiredInt16( null,
					"ISOCcyId",
					argISOCcyId )
			+	" />";
		return( retval );
	}

	public static String formatISOCcyRqstDelByCcyCdIdx( String separator,
		String argISOCode )
	{
		String retval = "<RqstISOCcyDelByCcyCdIdx "
			+	CFLibXmlUtil.formatRequiredXmlString( null,
					"ISOCode",
					argISOCode )
			+	" />";
		return( retval );
	}

	public static String formatISOCcyRqstDelByCcyNmIdx( String separator,
		String argName )
	{
		String retval = "<RqstISOCcyDelByCcyNmIdx "
			+	CFLibXmlUtil.formatRequiredXmlString( null,
					"Name",
					argName )
			+	" />";
		return( retval );
	}

	public static String formatISOCcyRspnSingleOpenTag() {
		String retval = "<RspnISOCcyReadSingle>";
		return( retval );
	}

	public static String formatISOCcyRspnSingleCloseTag() {
		String retval = "</RspnISOCcyReadSingle>";
		return( retval );
	}

	public static String formatISOCcyRspnListOpenTag() {
		String retval = "<RspnISOCcyReadList>";
		return( retval );
	}

	public static String formatISOCcyRspnListCloseTag() {
		String retval = "</RspnISOCcyReadList>";
		return( retval );
	}

	public static String formatISOCcyRspnRec( String separator, CFSecISOCcyBuff buff ) {
		String retval = "<ISOCcy "
			+	formatISOCcyBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatISOCcyRspnDerivedRec( String separator, CFSecISOCcyBuff buff ) {
		String retval;
		retval = formatISOCcyRspnRec( separator, buff );
		return( retval );
	}

	public static String formatISOCcyRspnCreated( String separator, CFSecISOCcyBuff buff ) {
		String retval = "<RspnISOCcyCreated "
			+	formatISOCcyBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatISOCcyRspnLocked( String separator, CFSecISOCcyBuff buff ) {
		String retval = "<RspnISOCcyLocked "
			+	formatISOCcyBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatISOCcyRspnUpdated( String separator, CFSecISOCcyBuff buff ) {
		String retval = "<RspnISOCcyUpdated "
			+	formatISOCcyBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatISOCcyRspnDeleted() {
		String retval = "<RspnISOCcyDeleted />";
		return( retval );
	}
}
