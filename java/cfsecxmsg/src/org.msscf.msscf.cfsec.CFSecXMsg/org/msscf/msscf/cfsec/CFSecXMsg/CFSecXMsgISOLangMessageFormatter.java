
// Description: Java 11 XML Message message formatter for CFSec.ISOLang

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
 *	CFSecXMsgISOLangMessageFormatter XML message formatter
 *	for CFSec.ISOLang.
 */
public class CFSecXMsgISOLangMessageFormatter
{
	public CFSecXMsgISOLangMessageFormatter() {
	}

	public static String formatISOLangPKeyAttributes( String separator, CFSecISOLangPKey pkey ) {
		String retval = CFLibXmlUtil.formatRequiredInt16( null,
				"ISOLangId",
				pkey.getRequiredISOLangId() );
		return( retval );
	}

	public static String formatISOLangPKeyAttributes( String separator, CFSecISOLangBuff buff ) {
		String retval = CFLibXmlUtil.formatRequiredInt16( separator,
					"ISOLangId",
					buff.getRequiredISOLangId() );
		return( retval );
	}

	public static String formatISOLangBuffAttributes( String separator, CFSecISOLangBuff buff ) {
		String retval = CFSecXMsgISOLangMessageFormatter.formatISOLangPKeyAttributes( separator, buff )
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
					"ISO6392Code",
					buff.getRequiredISO6392Code() )
			+	CFLibXmlUtil.formatOptionalXmlString( separator,
					"ISO6391Code",
					buff.getOptionalISO6391Code() )
			+	CFLibXmlUtil.formatRequiredXmlString( separator,
					"EnglishName",
					buff.getRequiredEnglishName() );
		return( retval );
	}

	public static String formatISOLangRqstCreate( String separator, CFSecISOLangBuff buff ) {
		String retval = "<RqstISOLangCreate "
			+	formatISOLangBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatISOLangRqstRead( String separator, CFSecISOLangPKey pkey ) {
		String retval = "<RqstISOLangRead "
			+	formatISOLangPKeyAttributes( separator, pkey )
			+	" />";
		return( retval );
	}

	public static String formatISOLangRqstRead( String separator, CFSecISOLangBuff buff ) {
		String retval = "<RqstISOLangRead "
			+	formatISOLangPKeyAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatISOLangRqstRead( String separator,
		short argISOLangId )
	{
		String retval = "<RqstISOLangRead "
			+	CFLibXmlUtil.formatRequiredInt16( null,
					"ISOLangId",
					argISOLangId )
			+	" />";
		return( retval );
	}

	public static String formatISOLangRqstReadAll( String separator ) {
		String retval = "<RqstISOLangReadAll />";
		return( retval );
	}

	public static String formatISOLangRqstRdByIdIdx( String separator,
		short argISOLangId )
	{
		String retval = "<RqstISOLangRead "
			+	CFLibXmlUtil.formatRequiredInt16( null,
					"ISOLangId",
					argISOLangId )
			+	" />";
		return( retval );
	}

	public static String formatISOLangRqstRdByCode3Idx( String separator,
		String argISO6392Code )
	{
		String retval = "<RqstISOLangRdByCode3Idx "
			+	CFLibXmlUtil.formatRequiredXmlString( null,
					"ISO6392Code",
					argISO6392Code )
			+	" />";
		return( retval );
	}

	public static String formatISOLangRqstRdByCode2Idx( String separator,
		String argISO6391Code )
	{
		String retval = "<RqstISOLangRdByCode2Idx "
			+	CFLibXmlUtil.formatOptionalXmlString( null,
					"ISO6391Code",
					argISO6391Code )
			+	" />";
		return( retval );
	}

	public static String formatISOLangRqstLock( String separator, CFSecISOLangPKey pkey ) {
		String retval = "<RqstISOLangLock "
			+	formatISOLangPKeyAttributes( separator, pkey )
			+	" />";
		return( retval );
	}

	public static String formatISOLangRqstLock( String separator, CFSecISOLangBuff buff ) {
		String retval = "<RqstISOLangLock "
			+	formatISOLangPKeyAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatISOLangRqstLock( String separator,
		short argISOLangId )
	{
		String retval = "<RqstISOLangLock "
			+	CFLibXmlUtil.formatRequiredInt16( null,
					"ISOLangId",
					argISOLangId )
			+	" />";
		return( retval );
	}

	public static String formatISOLangRqstUpdate( String separator, CFSecISOLangBuff buff ) {
		String retval = "<RqstISOLangUpdate "
			+	formatISOLangBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatISOLangRqstDelete( String separator, CFSecISOLangBuff buff ) {
		String retval = "<RqstISOLangDelete "
				+	formatISOLangPKeyAttributes( separator, buff )
				+	CFLibXmlUtil.formatRequiredInt32( separator,
						"Revision",
						buff.getRequiredRevision() )
				+	" />";
		return( retval );
	}

	public static String formatISOLangRqstDelByIdIdx( String separator,
		short argISOLangId )
	{
		String retval = "<RqstISOLangDelete "
			+	CFLibXmlUtil.formatRequiredInt16( null,
					"ISOLangId",
					argISOLangId )
			+	" />";
		return( retval );
	}

	public static String formatISOLangRqstDelByCode3Idx( String separator,
		String argISO6392Code )
	{
		String retval = "<RqstISOLangDelByCode3Idx "
			+	CFLibXmlUtil.formatRequiredXmlString( null,
					"ISO6392Code",
					argISO6392Code )
			+	" />";
		return( retval );
	}

	public static String formatISOLangRqstDelByCode2Idx( String separator,
		String argISO6391Code )
	{
		String retval = "<RqstISOLangDelByCode2Idx "
			+	CFLibXmlUtil.formatOptionalXmlString( null,
					"ISO6391Code",
					argISO6391Code )
			+	" />";
		return( retval );
	}

	public static String formatISOLangRspnSingleOpenTag() {
		String retval = "<RspnISOLangReadSingle>";
		return( retval );
	}

	public static String formatISOLangRspnSingleCloseTag() {
		String retval = "</RspnISOLangReadSingle>";
		return( retval );
	}

	public static String formatISOLangRspnListOpenTag() {
		String retval = "<RspnISOLangReadList>";
		return( retval );
	}

	public static String formatISOLangRspnListCloseTag() {
		String retval = "</RspnISOLangReadList>";
		return( retval );
	}

	public static String formatISOLangRspnRec( String separator, CFSecISOLangBuff buff ) {
		String retval = "<ISOLang "
			+	formatISOLangBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatISOLangRspnDerivedRec( String separator, CFSecISOLangBuff buff ) {
		String retval;
		retval = formatISOLangRspnRec( separator, buff );
		return( retval );
	}

	public static String formatISOLangRspnCreated( String separator, CFSecISOLangBuff buff ) {
		String retval = "<RspnISOLangCreated "
			+	formatISOLangBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatISOLangRspnLocked( String separator, CFSecISOLangBuff buff ) {
		String retval = "<RspnISOLangLocked "
			+	formatISOLangBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatISOLangRspnUpdated( String separator, CFSecISOLangBuff buff ) {
		String retval = "<RspnISOLangUpdated "
			+	formatISOLangBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatISOLangRspnDeleted() {
		String retval = "<RspnISOLangDeleted />";
		return( retval );
	}
}
