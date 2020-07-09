
// Description: Java 11 XML Message message formatter for CFSec.SecSession

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
 *	CFSecXMsgSecSessionMessageFormatter XML message formatter
 *	for CFSec.SecSession.
 */
public class CFSecXMsgSecSessionMessageFormatter
{
	public CFSecXMsgSecSessionMessageFormatter() {
	}

	public static String formatSecSessionPKeyAttributes( String separator, CFSecSecSessionPKey pkey ) {
		String retval = CFLibXmlUtil.formatRequiredUuid( null,
				"SecSessionId",
				pkey.getRequiredSecSessionId() );
		return( retval );
	}

	public static String formatSecSessionPKeyAttributes( String separator, CFSecSecSessionBuff buff ) {
		String retval = CFLibXmlUtil.formatRequiredUuid( separator,
					"SecSessionId",
					buff.getRequiredSecSessionId() );
		return( retval );
	}

	public static String formatSecSessionBuffAttributes( String separator, CFSecSecSessionBuff buff ) {
		String retval = CFSecXMsgSecSessionMessageFormatter.formatSecSessionPKeyAttributes( separator, buff )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"Revision",
					buff.getRequiredRevision() )
			+	CFLibXmlUtil.formatRequiredUuid( separator,
					"SecUserId",
					buff.getRequiredSecUserId() )
			+	CFLibXmlUtil.formatOptionalXmlString( separator,
					"SecDevName",
					buff.getOptionalSecDevName() )
			+	CFLibXmlUtil.formatRequiredTimestamp( separator,
					"Start",
					buff.getRequiredStart() )
			+	CFLibXmlUtil.formatOptionalTimestamp( separator,
					"Finish",
					buff.getOptionalFinish() )
			+	CFLibXmlUtil.formatOptionalUuid( separator,
					"SecProxyId",
					buff.getOptionalSecProxyId() );
		return( retval );
	}

	public static String formatSecSessionRqstCreate( String separator, CFSecSecSessionBuff buff ) {
		String retval = "<RqstSecSessionCreate "
			+	formatSecSessionBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecSessionRqstRead( String separator, CFSecSecSessionPKey pkey ) {
		String retval = "<RqstSecSessionRead "
			+	formatSecSessionPKeyAttributes( separator, pkey )
			+	" />";
		return( retval );
	}

	public static String formatSecSessionRqstRead( String separator, CFSecSecSessionBuff buff ) {
		String retval = "<RqstSecSessionRead "
			+	formatSecSessionPKeyAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecSessionRqstRead( String separator,
		UUID argSecSessionId )
	{
		String retval = "<RqstSecSessionRead "
			+	CFLibXmlUtil.formatRequiredUuid( null,
					"SecSessionId",
					argSecSessionId )
			+	" />";
		return( retval );
	}

	public static String formatSecSessionRqstReadAll( String separator ) {
		String retval = "<RqstSecSessionReadAll />";
		return( retval );
	}

	public static String formatSecSessionRqstPageAll( String separator,
		UUID priorSecSessionId ) {
		String retval = "<RqstSecSessionPageAll "
			+	CFLibXmlUtil.formatOptionalUuid( null,
					"PriorSecSessionId",
					priorSecSessionId )
			+	" />";
		return( retval );
	}

	public static String formatSecSessionRqstRdByIdIdx( String separator,
		UUID argSecSessionId )
	{
		String retval = "<RqstSecSessionRead "
			+	CFLibXmlUtil.formatRequiredUuid( null,
					"SecSessionId",
					argSecSessionId )
			+	" />";
		return( retval );
	}

	public static String formatSecSessionRqstRdBySecUserIdx( String separator,
		UUID argSecUserId )
	{
		String retval = "<RqstSecSessionRdBySecUserIdx "
			+	CFLibXmlUtil.formatRequiredUuid( null,
					"SecUserId",
					argSecUserId )
			+	" />";
		return( retval );
	}

	public static String formatSecSessionRqstRdBySecDevIdx( String separator,
		UUID argSecUserId,
		String argSecDevName )
	{
		String retval = "<RqstSecSessionRdBySecDevIdx "
			+	CFLibXmlUtil.formatRequiredUuid( null,
					"SecUserId",
					argSecUserId )
			+	CFLibXmlUtil.formatOptionalXmlString( separator,
					"SecDevName",
					argSecDevName )
			+	" />";
		return( retval );
	}

	public static String formatSecSessionRqstRdByStartIdx( String separator,
		UUID argSecUserId,
		Calendar argStart )
	{
		String retval = "<RqstSecSessionRdByStartIdx "
			+	CFLibXmlUtil.formatRequiredUuid( null,
					"SecUserId",
					argSecUserId )
			+	CFLibXmlUtil.formatRequiredTimestamp( separator,
					"Start",
					argStart )
			+	" />";
		return( retval );
	}

	public static String formatSecSessionRqstRdByFinishIdx( String separator,
		UUID argSecUserId,
		Calendar argFinish )
	{
		String retval = "<RqstSecSessionRdByFinishIdx "
			+	CFLibXmlUtil.formatRequiredUuid( null,
					"SecUserId",
					argSecUserId )
			+	CFLibXmlUtil.formatOptionalTimestamp( separator,
					"Finish",
					argFinish )
			+	" />";
		return( retval );
	}

	public static String formatSecSessionRqstRdBySecProxyIdx( String separator,
		UUID argSecProxyId )
	{
		String retval = "<RqstSecSessionRdBySecProxyIdx "
			+	CFLibXmlUtil.formatOptionalUuid( null,
					"SecProxyId",
					argSecProxyId )
			+	" />";
		return( retval );
	}

	public static String formatSecSessionRqstPageBySecUserIdx( String separator,
		UUID argSecUserId,
		UUID priorSecSessionId )
	{
		String retval = "<RqstSecSessionPageBySecUserIdx "
			+	CFLibXmlUtil.formatRequiredUuid( null,
					"SecUserId",
					argSecUserId )
			+	CFLibXmlUtil.formatOptionalUuid( separator,
					"PriorSecSessionId",
					priorSecSessionId )
			+	" />";
		return( retval );
	}

	public static String formatSecSessionRqstPageBySecDevIdx( String separator,
		UUID argSecUserId,
		String argSecDevName,
		UUID priorSecSessionId )
	{
		String retval = "<RqstSecSessionPageBySecDevIdx "
			+	CFLibXmlUtil.formatRequiredUuid( null,
					"SecUserId",
					argSecUserId )
			+	CFLibXmlUtil.formatOptionalXmlString( separator,
					"SecDevName",
					argSecDevName )
			+	CFLibXmlUtil.formatOptionalUuid( separator,
					"PriorSecSessionId",
					priorSecSessionId )
			+	" />";
		return( retval );
	}

	public static String formatSecSessionRqstPageByFinishIdx( String separator,
		UUID argSecUserId,
		Calendar argFinish,
		UUID priorSecSessionId )
	{
		String retval = "<RqstSecSessionPageByFinishIdx "
			+	CFLibXmlUtil.formatRequiredUuid( null,
					"SecUserId",
					argSecUserId )
			+	CFLibXmlUtil.formatOptionalTimestamp( separator,
					"Finish",
					argFinish )
			+	CFLibXmlUtil.formatOptionalUuid( separator,
					"PriorSecSessionId",
					priorSecSessionId )
			+	" />";
		return( retval );
	}

	public static String formatSecSessionRqstPageBySecProxyIdx( String separator,
		UUID argSecProxyId,
		UUID priorSecSessionId )
	{
		String retval = "<RqstSecSessionPageBySecProxyIdx "
			+	CFLibXmlUtil.formatOptionalUuid( null,
					"SecProxyId",
					argSecProxyId )
			+	CFLibXmlUtil.formatOptionalUuid( separator,
					"PriorSecSessionId",
					priorSecSessionId )
			+	" />";
		return( retval );
	}

	public static String formatSecSessionRqstLock( String separator, CFSecSecSessionPKey pkey ) {
		String retval = "<RqstSecSessionLock "
			+	formatSecSessionPKeyAttributes( separator, pkey )
			+	" />";
		return( retval );
	}

	public static String formatSecSessionRqstLock( String separator, CFSecSecSessionBuff buff ) {
		String retval = "<RqstSecSessionLock "
			+	formatSecSessionPKeyAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecSessionRqstLock( String separator,
		UUID argSecSessionId )
	{
		String retval = "<RqstSecSessionLock "
			+	CFLibXmlUtil.formatRequiredUuid( null,
					"SecSessionId",
					argSecSessionId )
			+	" />";
		return( retval );
	}

	public static String formatSecSessionRqstUpdate( String separator, CFSecSecSessionBuff buff ) {
		String retval = "<RqstSecSessionUpdate "
			+	formatSecSessionBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecSessionRqstDelete( String separator, CFSecSecSessionBuff buff ) {
		String retval = "<RqstSecSessionDelete "
				+	formatSecSessionPKeyAttributes( separator, buff )
				+	CFLibXmlUtil.formatRequiredInt32( separator,
						"Revision",
						buff.getRequiredRevision() )
				+	" />";
		return( retval );
	}

	public static String formatSecSessionRqstDelByIdIdx( String separator,
		UUID argSecSessionId )
	{
		String retval = "<RqstSecSessionDelete "
			+	CFLibXmlUtil.formatRequiredUuid( null,
					"SecSessionId",
					argSecSessionId )
			+	" />";
		return( retval );
	}

	public static String formatSecSessionRqstDelBySecUserIdx( String separator,
		UUID argSecUserId )
	{
		String retval = "<RqstSecSessionDelBySecUserIdx "
			+	CFLibXmlUtil.formatRequiredUuid( null,
					"SecUserId",
					argSecUserId )
			+	" />";
		return( retval );
	}

	public static String formatSecSessionRqstDelBySecDevIdx( String separator,
		UUID argSecUserId,
		String argSecDevName )
	{
		String retval = "<RqstSecSessionDelBySecDevIdx "
			+	CFLibXmlUtil.formatRequiredUuid( null,
					"SecUserId",
					argSecUserId )
			+	CFLibXmlUtil.formatOptionalXmlString( separator,
					"SecDevName",
					argSecDevName )
			+	" />";
		return( retval );
	}

	public static String formatSecSessionRqstDelByStartIdx( String separator,
		UUID argSecUserId,
		Calendar argStart )
	{
		String retval = "<RqstSecSessionDelByStartIdx "
			+	CFLibXmlUtil.formatRequiredUuid( null,
					"SecUserId",
					argSecUserId )
			+	CFLibXmlUtil.formatRequiredTimestamp( separator,
					"Start",
					argStart )
			+	" />";
		return( retval );
	}

	public static String formatSecSessionRqstDelByFinishIdx( String separator,
		UUID argSecUserId,
		Calendar argFinish )
	{
		String retval = "<RqstSecSessionDelByFinishIdx "
			+	CFLibXmlUtil.formatRequiredUuid( null,
					"SecUserId",
					argSecUserId )
			+	CFLibXmlUtil.formatOptionalTimestamp( separator,
					"Finish",
					argFinish )
			+	" />";
		return( retval );
	}

	public static String formatSecSessionRqstDelBySecProxyIdx( String separator,
		UUID argSecProxyId )
	{
		String retval = "<RqstSecSessionDelBySecProxyIdx "
			+	CFLibXmlUtil.formatOptionalUuid( null,
					"SecProxyId",
					argSecProxyId )
			+	" />";
		return( retval );
	}

	public static String formatSecSessionRspnSingleOpenTag() {
		String retval = "<RspnSecSessionReadSingle>";
		return( retval );
	}

	public static String formatSecSessionRspnSingleCloseTag() {
		String retval = "</RspnSecSessionReadSingle>";
		return( retval );
	}

	public static String formatSecSessionRspnListOpenTag() {
		String retval = "<RspnSecSessionReadList>";
		return( retval );
	}

	public static String formatSecSessionRspnListCloseTag() {
		String retval = "</RspnSecSessionReadList>";
		return( retval );
	}

	public static String formatSecSessionRspnRec( String separator, CFSecSecSessionBuff buff ) {
		String retval = "<SecSession "
			+	formatSecSessionBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecSessionRspnDerivedRec( String separator, CFSecSecSessionBuff buff ) {
		String retval;
		retval = formatSecSessionRspnRec( separator, buff );
		return( retval );
	}

	public static String formatSecSessionRspnCreated( String separator, CFSecSecSessionBuff buff ) {
		String retval = "<RspnSecSessionCreated "
			+	formatSecSessionBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecSessionRspnLocked( String separator, CFSecSecSessionBuff buff ) {
		String retval = "<RspnSecSessionLocked "
			+	formatSecSessionBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecSessionRspnUpdated( String separator, CFSecSecSessionBuff buff ) {
		String retval = "<RspnSecSessionUpdated "
			+	formatSecSessionBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSecSessionRspnDeleted() {
		String retval = "<RspnSecSessionDeleted />";
		return( retval );
	}
}
