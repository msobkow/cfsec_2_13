
// Description: Java 11 XML Message message formatter for CFSec.ISOCcy

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

package org.msscf.msscf.cfsec.v2_13.cfsec.CFSecXMsg;

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.apache.commons.codec.binary.Base64;
import org.xml.sax.*;
import org.msscf.msscf.cflib.v2_13.CFLib.*;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfsec.CFSecObj.*;

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
