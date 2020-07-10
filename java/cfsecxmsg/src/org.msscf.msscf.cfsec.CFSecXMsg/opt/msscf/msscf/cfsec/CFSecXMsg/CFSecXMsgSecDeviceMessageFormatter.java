
// Description: Java 11 XML Message message formatter for CFSec.SecDevice

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
