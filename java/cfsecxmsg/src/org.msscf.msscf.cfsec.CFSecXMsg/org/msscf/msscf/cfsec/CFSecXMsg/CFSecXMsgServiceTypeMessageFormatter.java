
// Description: Java 11 XML Message message formatter for CFSec.ServiceType

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
 *	CFSecXMsgServiceTypeMessageFormatter XML message formatter
 *	for CFSec.ServiceType.
 */
public class CFSecXMsgServiceTypeMessageFormatter
{
	public CFSecXMsgServiceTypeMessageFormatter() {
	}

	public static String formatServiceTypePKeyAttributes( String separator, CFSecServiceTypePKey pkey ) {
		String retval = CFLibXmlUtil.formatRequiredInt32( null,
				"ServiceTypeId",
				pkey.getRequiredServiceTypeId() );
		return( retval );
	}

	public static String formatServiceTypePKeyAttributes( String separator, CFSecServiceTypeBuff buff ) {
		String retval = CFLibXmlUtil.formatRequiredInt32( separator,
					"ServiceTypeId",
					buff.getRequiredServiceTypeId() );
		return( retval );
	}

	public static String formatServiceTypeBuffAttributes( String separator, CFSecServiceTypeBuff buff ) {
		String retval = CFSecXMsgServiceTypeMessageFormatter.formatServiceTypePKeyAttributes( separator, buff )
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
					"Description",
					buff.getRequiredDescription() );
		return( retval );
	}

	public static String formatServiceTypeRqstCreate( String separator, CFSecServiceTypeBuff buff ) {
		String retval = "<RqstServiceTypeCreate "
			+	formatServiceTypeBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatServiceTypeRqstRead( String separator, CFSecServiceTypePKey pkey ) {
		String retval = "<RqstServiceTypeRead "
			+	formatServiceTypePKeyAttributes( separator, pkey )
			+	" />";
		return( retval );
	}

	public static String formatServiceTypeRqstRead( String separator, CFSecServiceTypeBuff buff ) {
		String retval = "<RqstServiceTypeRead "
			+	formatServiceTypePKeyAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatServiceTypeRqstRead( String separator,
		int argServiceTypeId )
	{
		String retval = "<RqstServiceTypeRead "
			+	CFLibXmlUtil.formatRequiredInt32( null,
					"ServiceTypeId",
					argServiceTypeId )
			+	" />";
		return( retval );
	}

	public static String formatServiceTypeRqstReadAll( String separator ) {
		String retval = "<RqstServiceTypeReadAll />";
		return( retval );
	}

	public static String formatServiceTypeRqstRdByIdIdx( String separator,
		int argServiceTypeId )
	{
		String retval = "<RqstServiceTypeRead "
			+	CFLibXmlUtil.formatRequiredInt32( null,
					"ServiceTypeId",
					argServiceTypeId )
			+	" />";
		return( retval );
	}

	public static String formatServiceTypeRqstRdByUDescrIdx( String separator,
		String argDescription )
	{
		String retval = "<RqstServiceTypeRdByUDescrIdx "
			+	CFLibXmlUtil.formatRequiredXmlString( null,
					"Description",
					argDescription )
			+	" />";
		return( retval );
	}

	public static String formatServiceTypeRqstLock( String separator, CFSecServiceTypePKey pkey ) {
		String retval = "<RqstServiceTypeLock "
			+	formatServiceTypePKeyAttributes( separator, pkey )
			+	" />";
		return( retval );
	}

	public static String formatServiceTypeRqstLock( String separator, CFSecServiceTypeBuff buff ) {
		String retval = "<RqstServiceTypeLock "
			+	formatServiceTypePKeyAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatServiceTypeRqstLock( String separator,
		int argServiceTypeId )
	{
		String retval = "<RqstServiceTypeLock "
			+	CFLibXmlUtil.formatRequiredInt32( null,
					"ServiceTypeId",
					argServiceTypeId )
			+	" />";
		return( retval );
	}

	public static String formatServiceTypeRqstUpdate( String separator, CFSecServiceTypeBuff buff ) {
		String retval = "<RqstServiceTypeUpdate "
			+	formatServiceTypeBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatServiceTypeRqstDelete( String separator, CFSecServiceTypeBuff buff ) {
		String retval = "<RqstServiceTypeDelete "
				+	formatServiceTypePKeyAttributes( separator, buff )
				+	CFLibXmlUtil.formatRequiredInt32( separator,
						"Revision",
						buff.getRequiredRevision() )
				+	" />";
		return( retval );
	}

	public static String formatServiceTypeRqstDelByIdIdx( String separator,
		int argServiceTypeId )
	{
		String retval = "<RqstServiceTypeDelete "
			+	CFLibXmlUtil.formatRequiredInt32( null,
					"ServiceTypeId",
					argServiceTypeId )
			+	" />";
		return( retval );
	}

	public static String formatServiceTypeRqstDelByUDescrIdx( String separator,
		String argDescription )
	{
		String retval = "<RqstServiceTypeDelByUDescrIdx "
			+	CFLibXmlUtil.formatRequiredXmlString( null,
					"Description",
					argDescription )
			+	" />";
		return( retval );
	}

	public static String formatServiceTypeRspnSingleOpenTag() {
		String retval = "<RspnServiceTypeReadSingle>";
		return( retval );
	}

	public static String formatServiceTypeRspnSingleCloseTag() {
		String retval = "</RspnServiceTypeReadSingle>";
		return( retval );
	}

	public static String formatServiceTypeRspnListOpenTag() {
		String retval = "<RspnServiceTypeReadList>";
		return( retval );
	}

	public static String formatServiceTypeRspnListCloseTag() {
		String retval = "</RspnServiceTypeReadList>";
		return( retval );
	}

	public static String formatServiceTypeRspnRec( String separator, CFSecServiceTypeBuff buff ) {
		String retval = "<ServiceType "
			+	formatServiceTypeBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatServiceTypeRspnDerivedRec( String separator, CFSecServiceTypeBuff buff ) {
		String retval;
		retval = formatServiceTypeRspnRec( separator, buff );
		return( retval );
	}

	public static String formatServiceTypeRspnCreated( String separator, CFSecServiceTypeBuff buff ) {
		String retval = "<RspnServiceTypeCreated "
			+	formatServiceTypeBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatServiceTypeRspnLocked( String separator, CFSecServiceTypeBuff buff ) {
		String retval = "<RspnServiceTypeLocked "
			+	formatServiceTypeBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatServiceTypeRspnUpdated( String separator, CFSecServiceTypeBuff buff ) {
		String retval = "<RspnServiceTypeUpdated "
			+	formatServiceTypeBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatServiceTypeRspnDeleted() {
		String retval = "<RspnServiceTypeDeleted />";
		return( retval );
	}
}
