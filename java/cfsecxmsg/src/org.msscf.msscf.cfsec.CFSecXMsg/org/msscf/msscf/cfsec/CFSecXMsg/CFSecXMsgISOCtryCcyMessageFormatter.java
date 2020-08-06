
// Description: Java 11 XML Message message formatter for CFSec.ISOCtryCcy

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
