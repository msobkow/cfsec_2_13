
// Description: Java 11 XML Message message formatter for CFSec.SecUser

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
 *	CFSecXMsgSecUserMessageFormatter XML message formatter
 *	for CFSec.SecUser.
 */
public class CFSecXMsgSecUserMessageFormatter
{
	public CFSecXMsgSecUserMessageFormatter() {
	}

	public static String formatSecUserPKeyAttributes( String separator, CFSecSecUserPKey pkey ) {
		String retval = CFLibXmlUtil.formatRequiredUuid( null,
				"SecUserId",
				pkey.getRequiredSecUserId() );
		return( retval );
	}

	public static String formatSecUserPKeyAttributes( String separator, CFSecSecUserBuff buff ) {
		String retval = CFLibXmlUtil.formatRequiredUuid( separator,
					"SecUserId",
					buff.getRequiredSecUserId() );
		return( retval );
	}

	public static String formatSecUserBuffAttributes( String separator, CFSecSecUserBuff buff ) {
		String retval = CFSecXMsgSecUserMessageFormatter.formatSecUserPKeyAttributes( separator, buff )
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
					"LoginId",
					buff.getRequiredLoginId() )
			+	CFLibXmlUtil.formatRequiredXmlString( separator,
					"EMailAddress",
					buff.getRequiredEMailAddress() )
			+	CFLibXmlUtil.formatOptionalUuid( separator,
					"EMailConfirmUuid",
					buff.getOptionalEMailConfirmUuid() )
			+	CFLibXmlUtil.formatOptionalUuid( separator,
					"DfltDevUserId",
					buff.getOptionalDfltDevUserId() )
			+	CFLibXmlUtil.formatOptionalXmlString( separator,
					"DfltDevName",
					buff.getOptionalDfltDevName() )
			+	CFLibXmlUtil.formatRequiredXmlString( separator,
					"PasswordHash",
					buff.getRequiredPasswordHash() )
			+	CFLibXmlUtil.formatOptionalUuid( separator,
					"PasswordResetUuid",
					buff.getOptionalPasswordResetUuid() );
		return( retval );
	}

	public static String formatSecUserRqstCreate( String separator, CFSecSecUserBuff buff ) {
		String retval = "<RqstSecUserCreate "
			+	formatSecUserBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecUserRqstRead( String separator, CFSecSecUserPKey pkey ) {
		String retval = "<RqstSecUserRead "
			+	formatSecUserPKeyAttributes( separator, pkey )
			+	" />";
		return( retval );
	}

	public static String formatSecUserRqstRead( String separator, CFSecSecUserBuff buff ) {
		String retval = "<RqstSecUserRead "
			+	formatSecUserPKeyAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecUserRqstRead( String separator,
		UUID argSecUserId )
	{
		String retval = "<RqstSecUserRead "
			+	CFLibXmlUtil.formatRequiredUuid( null,
					"SecUserId",
					argSecUserId )
			+	" />";
		return( retval );
	}

	public static String formatSecUserRqstReadAll( String separator ) {
		String retval = "<RqstSecUserReadAll />";
		return( retval );
	}

	public static String formatSecUserRqstPageAll( String separator,
		UUID priorSecUserId ) {
		String retval = "<RqstSecUserPageAll "
			+	CFLibXmlUtil.formatOptionalUuid( null,
					"PriorSecUserId",
					priorSecUserId )
			+	" />";
		return( retval );
	}

	public static String formatSecUserRqstRdByIdIdx( String separator,
		UUID argSecUserId )
	{
		String retval = "<RqstSecUserRead "
			+	CFLibXmlUtil.formatRequiredUuid( null,
					"SecUserId",
					argSecUserId )
			+	" />";
		return( retval );
	}

	public static String formatSecUserRqstRdByULoginIdx( String separator,
		String argLoginId )
	{
		String retval = "<RqstSecUserRdByULoginIdx "
			+	CFLibXmlUtil.formatRequiredXmlString( null,
					"LoginId",
					argLoginId )
			+	" />";
		return( retval );
	}

	public static String formatSecUserRqstRdByEMConfIdx( String separator,
		UUID argEMailConfirmUuid )
	{
		String retval = "<RqstSecUserRdByEMConfIdx "
			+	CFLibXmlUtil.formatOptionalUuid( null,
					"EMailConfirmUuid",
					argEMailConfirmUuid )
			+	" />";
		return( retval );
	}

	public static String formatSecUserRqstRdByPwdResetIdx( String separator,
		UUID argPasswordResetUuid )
	{
		String retval = "<RqstSecUserRdByPwdResetIdx "
			+	CFLibXmlUtil.formatOptionalUuid( null,
					"PasswordResetUuid",
					argPasswordResetUuid )
			+	" />";
		return( retval );
	}

	public static String formatSecUserRqstRdByDefDevIdx( String separator,
		UUID argDfltDevUserId,
		String argDfltDevName )
	{
		String retval = "<RqstSecUserRdByDefDevIdx "
			+	CFLibXmlUtil.formatOptionalUuid( null,
					"DfltDevUserId",
					argDfltDevUserId )
			+	CFLibXmlUtil.formatOptionalXmlString( separator,
					"DfltDevName",
					argDfltDevName )
			+	" />";
		return( retval );
	}

	public static String formatSecUserRqstPageByEMConfIdx( String separator,
		UUID argEMailConfirmUuid,
		UUID priorSecUserId )
	{
		String retval = "<RqstSecUserPageByEMConfIdx "
			+	CFLibXmlUtil.formatOptionalUuid( null,
					"EMailConfirmUuid",
					argEMailConfirmUuid )
			+	CFLibXmlUtil.formatOptionalUuid( separator,
					"PriorSecUserId",
					priorSecUserId )
			+	" />";
		return( retval );
	}

	public static String formatSecUserRqstPageByPwdResetIdx( String separator,
		UUID argPasswordResetUuid,
		UUID priorSecUserId )
	{
		String retval = "<RqstSecUserPageByPwdResetIdx "
			+	CFLibXmlUtil.formatOptionalUuid( null,
					"PasswordResetUuid",
					argPasswordResetUuid )
			+	CFLibXmlUtil.formatOptionalUuid( separator,
					"PriorSecUserId",
					priorSecUserId )
			+	" />";
		return( retval );
	}

	public static String formatSecUserRqstPageByDefDevIdx( String separator,
		UUID argDfltDevUserId,
		String argDfltDevName,
		UUID priorSecUserId )
	{
		String retval = "<RqstSecUserPageByDefDevIdx "
			+	CFLibXmlUtil.formatOptionalUuid( null,
					"DfltDevUserId",
					argDfltDevUserId )
			+	CFLibXmlUtil.formatOptionalXmlString( separator,
					"DfltDevName",
					argDfltDevName )
			+	CFLibXmlUtil.formatOptionalUuid( separator,
					"PriorSecUserId",
					priorSecUserId )
			+	" />";
		return( retval );
	}

	public static String formatSecUserRqstLock( String separator, CFSecSecUserPKey pkey ) {
		String retval = "<RqstSecUserLock "
			+	formatSecUserPKeyAttributes( separator, pkey )
			+	" />";
		return( retval );
	}

	public static String formatSecUserRqstLock( String separator, CFSecSecUserBuff buff ) {
		String retval = "<RqstSecUserLock "
			+	formatSecUserPKeyAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecUserRqstLock( String separator,
		UUID argSecUserId )
	{
		String retval = "<RqstSecUserLock "
			+	CFLibXmlUtil.formatRequiredUuid( null,
					"SecUserId",
					argSecUserId )
			+	" />";
		return( retval );
	}

	public static String formatSecUserRqstUpdate( String separator, CFSecSecUserBuff buff ) {
		String retval = "<RqstSecUserUpdate "
			+	formatSecUserBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecUserRqstDelete( String separator, CFSecSecUserBuff buff ) {
		String retval = "<RqstSecUserDelete "
				+	formatSecUserPKeyAttributes( separator, buff )
				+	CFLibXmlUtil.formatRequiredInt32( separator,
						"Revision",
						buff.getRequiredRevision() )
				+	" />";
		return( retval );
	}

	public static String formatSecUserRqstDelByIdIdx( String separator,
		UUID argSecUserId )
	{
		String retval = "<RqstSecUserDelete "
			+	CFLibXmlUtil.formatRequiredUuid( null,
					"SecUserId",
					argSecUserId )
			+	" />";
		return( retval );
	}

	public static String formatSecUserRqstDelByULoginIdx( String separator,
		String argLoginId )
	{
		String retval = "<RqstSecUserDelByULoginIdx "
			+	CFLibXmlUtil.formatRequiredXmlString( null,
					"LoginId",
					argLoginId )
			+	" />";
		return( retval );
	}

	public static String formatSecUserRqstDelByEMConfIdx( String separator,
		UUID argEMailConfirmUuid )
	{
		String retval = "<RqstSecUserDelByEMConfIdx "
			+	CFLibXmlUtil.formatOptionalUuid( null,
					"EMailConfirmUuid",
					argEMailConfirmUuid )
			+	" />";
		return( retval );
	}

	public static String formatSecUserRqstDelByPwdResetIdx( String separator,
		UUID argPasswordResetUuid )
	{
		String retval = "<RqstSecUserDelByPwdResetIdx "
			+	CFLibXmlUtil.formatOptionalUuid( null,
					"PasswordResetUuid",
					argPasswordResetUuid )
			+	" />";
		return( retval );
	}

	public static String formatSecUserRqstDelByDefDevIdx( String separator,
		UUID argDfltDevUserId,
		String argDfltDevName )
	{
		String retval = "<RqstSecUserDelByDefDevIdx "
			+	CFLibXmlUtil.formatOptionalUuid( null,
					"DfltDevUserId",
					argDfltDevUserId )
			+	CFLibXmlUtil.formatOptionalXmlString( separator,
					"DfltDevName",
					argDfltDevName )
			+	" />";
		return( retval );
	}

	public static String formatSecUserRspnSingleOpenTag() {
		String retval = "<RspnSecUserReadSingle>";
		return( retval );
	}

	public static String formatSecUserRspnSingleCloseTag() {
		String retval = "</RspnSecUserReadSingle>";
		return( retval );
	}

	public static String formatSecUserRspnListOpenTag() {
		String retval = "<RspnSecUserReadList>";
		return( retval );
	}

	public static String formatSecUserRspnListCloseTag() {
		String retval = "</RspnSecUserReadList>";
		return( retval );
	}

	public static String formatSecUserRspnRec( String separator, CFSecSecUserBuff buff ) {
		String retval = "<SecUser "
			+	formatSecUserBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecUserRspnDerivedRec( String separator, CFSecSecUserBuff buff ) {
		String retval;
		retval = formatSecUserRspnRec( separator, buff );
		return( retval );
	}

	public static String formatSecUserRspnCreated( String separator, CFSecSecUserBuff buff ) {
		String retval = "<RspnSecUserCreated "
			+	formatSecUserBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecUserRspnLocked( String separator, CFSecSecUserBuff buff ) {
		String retval = "<RspnSecUserLocked "
			+	formatSecUserBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecUserRspnUpdated( String separator, CFSecSecUserBuff buff ) {
		String retval = "<RspnSecUserUpdated "
			+	formatSecUserBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecUserRspnDeleted() {
		String retval = "<RspnSecUserDeleted />";
		return( retval );
	}
}
