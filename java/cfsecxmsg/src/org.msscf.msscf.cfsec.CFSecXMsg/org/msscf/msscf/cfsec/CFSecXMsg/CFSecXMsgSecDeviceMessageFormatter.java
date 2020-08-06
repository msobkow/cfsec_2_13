
// Description: Java 11 XML Message message formatter for CFSec.SecDevice

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
 *	CFSecXMsgSecDeviceMessageFormatter XML message formatter
 *	for CFSec.SecDevice.
 */
public class CFSecXMsgSecDeviceMessageFormatter
{
	public CFSecXMsgSecDeviceMessageFormatter() {
	}

	public static String formatSecDevicePKeyAttributes( String separator, CFSecSecDevicePKey pkey ) {
		String retval = CFLibXmlUtil.formatRequiredUuid( null,
				"SecUserId",
				pkey.getRequiredSecUserId() )
			+	CFLibXmlUtil.formatRequiredXmlString( separator,
				"DevName",
				pkey.getRequiredDevName() );
		return( retval );
	}

	public static String formatSecDevicePKeyAttributes( String separator, CFSecSecDeviceBuff buff ) {
		String retval = CFLibXmlUtil.formatRequiredUuid( separator,
					"SecUserId",
					buff.getRequiredSecUserId() )
			+	CFLibXmlUtil.formatRequiredXmlString( separator,
					"DevName",
					buff.getRequiredDevName() );
		return( retval );
	}

	public static String formatSecDeviceBuffAttributes( String separator, CFSecSecDeviceBuff buff ) {
		String retval = CFSecXMsgSecDeviceMessageFormatter.formatSecDevicePKeyAttributes( separator, buff )
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
			+	CFLibXmlUtil.formatOptionalXmlString( separator,
					"PubKey",
					buff.getOptionalPubKey() );
		return( retval );
	}

	public static String formatSecDeviceRqstCreate( String separator, CFSecSecDeviceBuff buff ) {
		String retval = "<RqstSecDeviceCreate "
			+	formatSecDeviceBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecDeviceRqstRead( String separator, CFSecSecDevicePKey pkey ) {
		String retval = "<RqstSecDeviceRead "
			+	formatSecDevicePKeyAttributes( separator, pkey )
			+	" />";
		return( retval );
	}

	public static String formatSecDeviceRqstRead( String separator, CFSecSecDeviceBuff buff ) {
		String retval = "<RqstSecDeviceRead "
			+	formatSecDevicePKeyAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecDeviceRqstRead( String separator,
		UUID argSecUserId,
		String argDevName )
	{
		String retval = "<RqstSecDeviceRead "
			+	CFLibXmlUtil.formatRequiredUuid( null,
					"SecUserId",
					argSecUserId )
			+	CFLibXmlUtil.formatRequiredXmlString( separator,
					"DevName",
					argDevName )
			+	" />";
		return( retval );
	}

	public static String formatSecDeviceRqstReadAll( String separator ) {
		String retval = "<RqstSecDeviceReadAll />";
		return( retval );
	}

	public static String formatSecDeviceRqstPageAll( String separator,
		UUID priorSecUserId,
		String priorDevName ) {
		String retval = "<RqstSecDevicePageAll "
			+	CFLibXmlUtil.formatOptionalUuid( null,
					"PriorSecUserId",
					priorSecUserId )
			+	CFLibXmlUtil.formatOptionalXmlString( separator,
					"PriorDevName",
					priorDevName )
			+	" />";
		return( retval );
	}

	public static String formatSecDeviceRqstRdByIdIdx( String separator,
		UUID argSecUserId,
		String argDevName )
	{
		String retval = "<RqstSecDeviceRead "
			+	CFLibXmlUtil.formatRequiredUuid( null,
					"SecUserId",
					argSecUserId )
			+	CFLibXmlUtil.formatRequiredXmlString( separator,
					"DevName",
					argDevName )
			+	" />";
		return( retval );
	}

	public static String formatSecDeviceRqstRdByNameIdx( String separator,
		UUID argSecUserId,
		String argDevName )
	{
		String retval = "<RqstSecDeviceRdByNameIdx "
			+	CFLibXmlUtil.formatRequiredUuid( null,
					"SecUserId",
					argSecUserId )
			+	CFLibXmlUtil.formatRequiredXmlString( separator,
					"DevName",
					argDevName )
			+	" />";
		return( retval );
	}

	public static String formatSecDeviceRqstRdByUserIdx( String separator,
		UUID argSecUserId )
	{
		String retval = "<RqstSecDeviceRdByUserIdx "
			+	CFLibXmlUtil.formatRequiredUuid( null,
					"SecUserId",
					argSecUserId )
			+	" />";
		return( retval );
	}

	public static String formatSecDeviceRqstPageByUserIdx( String separator,
		UUID argSecUserId,
		UUID priorSecUserId,
		String priorDevName )
	{
		String retval = "<RqstSecDevicePageByUserIdx "
			+	CFLibXmlUtil.formatRequiredUuid( null,
					"SecUserId",
					argSecUserId )
			+	CFLibXmlUtil.formatOptionalUuid( separator,
					"PriorSecUserId",
					priorSecUserId )
			+	CFLibXmlUtil.formatOptionalXmlString( separator,
					"PriorDevName",
					priorDevName )
			+	" />";
		return( retval );
	}

	public static String formatSecDeviceRqstLock( String separator, CFSecSecDevicePKey pkey ) {
		String retval = "<RqstSecDeviceLock "
			+	formatSecDevicePKeyAttributes( separator, pkey )
			+	" />";
		return( retval );
	}

	public static String formatSecDeviceRqstLock( String separator, CFSecSecDeviceBuff buff ) {
		String retval = "<RqstSecDeviceLock "
			+	formatSecDevicePKeyAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecDeviceRqstLock( String separator,
		UUID argSecUserId,
		String argDevName )
	{
		String retval = "<RqstSecDeviceLock "
			+	CFLibXmlUtil.formatRequiredUuid( null,
					"SecUserId",
					argSecUserId )
			+	CFLibXmlUtil.formatRequiredXmlString( separator,
					"DevName",
					argDevName )
			+	" />";
		return( retval );
	}

	public static String formatSecDeviceRqstUpdate( String separator, CFSecSecDeviceBuff buff ) {
		String retval = "<RqstSecDeviceUpdate "
			+	formatSecDeviceBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecDeviceRqstDelete( String separator, CFSecSecDeviceBuff buff ) {
		String retval = "<RqstSecDeviceDelete "
				+	formatSecDevicePKeyAttributes( separator, buff )
				+	CFLibXmlUtil.formatRequiredInt32( separator,
						"Revision",
						buff.getRequiredRevision() )
				+	" />";
		return( retval );
	}

	public static String formatSecDeviceRqstDelByIdIdx( String separator,
		UUID argSecUserId,
		String argDevName )
	{
		String retval = "<RqstSecDeviceDelete "
			+	CFLibXmlUtil.formatRequiredUuid( null,
					"SecUserId",
					argSecUserId )
			+	CFLibXmlUtil.formatRequiredXmlString( separator,
					"DevName",
					argDevName )
			+	" />";
		return( retval );
	}

	public static String formatSecDeviceRqstDelByNameIdx( String separator,
		UUID argSecUserId,
		String argDevName )
	{
		String retval = "<RqstSecDeviceDelByNameIdx "
			+	CFLibXmlUtil.formatRequiredUuid( null,
					"SecUserId",
					argSecUserId )
			+	CFLibXmlUtil.formatRequiredXmlString( separator,
					"DevName",
					argDevName )
			+	" />";
		return( retval );
	}

	public static String formatSecDeviceRqstDelByUserIdx( String separator,
		UUID argSecUserId )
	{
		String retval = "<RqstSecDeviceDelByUserIdx "
			+	CFLibXmlUtil.formatRequiredUuid( null,
					"SecUserId",
					argSecUserId )
			+	" />";
		return( retval );
	}

	public static String formatSecDeviceRspnSingleOpenTag() {
		String retval = "<RspnSecDeviceReadSingle>";
		return( retval );
	}

	public static String formatSecDeviceRspnSingleCloseTag() {
		String retval = "</RspnSecDeviceReadSingle>";
		return( retval );
	}

	public static String formatSecDeviceRspnListOpenTag() {
		String retval = "<RspnSecDeviceReadList>";
		return( retval );
	}

	public static String formatSecDeviceRspnListCloseTag() {
		String retval = "</RspnSecDeviceReadList>";
		return( retval );
	}

	public static String formatSecDeviceRspnRec( String separator, CFSecSecDeviceBuff buff ) {
		String retval = "<SecDevice "
			+	formatSecDeviceBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecDeviceRspnDerivedRec( String separator, CFSecSecDeviceBuff buff ) {
		String retval;
		retval = formatSecDeviceRspnRec( separator, buff );
		return( retval );
	}

	public static String formatSecDeviceRspnCreated( String separator, CFSecSecDeviceBuff buff ) {
		String retval = "<RspnSecDeviceCreated "
			+	formatSecDeviceBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecDeviceRspnLocked( String separator, CFSecSecDeviceBuff buff ) {
		String retval = "<RspnSecDeviceLocked "
			+	formatSecDeviceBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecDeviceRspnUpdated( String separator, CFSecSecDeviceBuff buff ) {
		String retval = "<RspnSecDeviceUpdated "
			+	formatSecDeviceBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecDeviceRspnDeleted() {
		String retval = "<RspnSecDeviceDeleted />";
		return( retval );
	}
}
