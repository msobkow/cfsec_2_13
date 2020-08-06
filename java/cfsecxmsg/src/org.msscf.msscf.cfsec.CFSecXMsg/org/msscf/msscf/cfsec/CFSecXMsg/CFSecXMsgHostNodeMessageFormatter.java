
// Description: Java 11 XML Message message formatter for CFSec.HostNode

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
 *	CFSecXMsgHostNodeMessageFormatter XML message formatter
 *	for CFSec.HostNode.
 */
public class CFSecXMsgHostNodeMessageFormatter
{
	public CFSecXMsgHostNodeMessageFormatter() {
	}

	public static String formatHostNodePKeyAttributes( String separator, CFSecHostNodePKey pkey ) {
		String retval = CFLibXmlUtil.formatRequiredInt64( null,
				"ClusterId",
				pkey.getRequiredClusterId() )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
				"HostNodeId",
				pkey.getRequiredHostNodeId() );
		return( retval );
	}

	public static String formatHostNodePKeyAttributes( String separator, CFSecHostNodeBuff buff ) {
		String retval = CFLibXmlUtil.formatRequiredInt64( separator,
					"ClusterId",
					buff.getRequiredClusterId() )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"HostNodeId",
					buff.getRequiredHostNodeId() );
		return( retval );
	}

	public static String formatHostNodeBuffAttributes( String separator, CFSecHostNodeBuff buff ) {
		String retval = CFSecXMsgHostNodeMessageFormatter.formatHostNodePKeyAttributes( separator, buff )
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
					buff.getRequiredDescription() )
			+	CFLibXmlUtil.formatRequiredXmlString( separator,
					"HostName",
					buff.getRequiredHostName() );
		return( retval );
	}

	public static String formatHostNodeRqstCreate( String separator, CFSecHostNodeBuff buff ) {
		String retval = "<RqstHostNodeCreate "
			+	formatHostNodeBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatHostNodeRqstRead( String separator, CFSecHostNodePKey pkey ) {
		String retval = "<RqstHostNodeRead "
			+	formatHostNodePKeyAttributes( separator, pkey )
			+	" />";
		return( retval );
	}

	public static String formatHostNodeRqstRead( String separator, CFSecHostNodeBuff buff ) {
		String retval = "<RqstHostNodeRead "
			+	formatHostNodePKeyAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatHostNodeRqstRead( String separator,
		long argClusterId,
		long argHostNodeId )
	{
		String retval = "<RqstHostNodeRead "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"HostNodeId",
					argHostNodeId )
			+	" />";
		return( retval );
	}

	public static String formatHostNodeRqstReadAll( String separator ) {
		String retval = "<RqstHostNodeReadAll />";
		return( retval );
	}

	public static String formatHostNodeRqstPageAll( String separator,
		Long priorClusterId,
		Long priorHostNodeId ) {
		String retval = "<RqstHostNodePageAll "
			+	CFLibXmlUtil.formatOptionalInt64( null,
					"PriorClusterId",
					priorClusterId )
			+	CFLibXmlUtil.formatOptionalInt64( separator,
					"PriorHostNodeId",
					priorHostNodeId )
			+	" />";
		return( retval );
	}

	public static String formatHostNodeRqstRdByIdIdx( String separator,
		long argClusterId,
		long argHostNodeId )
	{
		String retval = "<RqstHostNodeRead "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"HostNodeId",
					argHostNodeId )
			+	" />";
		return( retval );
	}

	public static String formatHostNodeRqstRdByClusterIdx( String separator,
		long argClusterId )
	{
		String retval = "<RqstHostNodeRdByClusterIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	" />";
		return( retval );
	}

	public static String formatHostNodeRqstRdByUDescrIdx( String separator,
		long argClusterId,
		String argDescription )
	{
		String retval = "<RqstHostNodeRdByUDescrIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredXmlString( separator,
					"Description",
					argDescription )
			+	" />";
		return( retval );
	}

	public static String formatHostNodeRqstRdByHostNameIdx( String separator,
		long argClusterId,
		String argHostName )
	{
		String retval = "<RqstHostNodeRdByHostNameIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredXmlString( separator,
					"HostName",
					argHostName )
			+	" />";
		return( retval );
	}

	public static String formatHostNodeRqstPageByClusterIdx( String separator,
		long argClusterId,
		Long priorClusterId,
		Long priorHostNodeId )
	{
		String retval = "<RqstHostNodePageByClusterIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatOptionalInt64( separator,
					"PriorClusterId",
					priorClusterId )
			+	CFLibXmlUtil.formatOptionalInt64( separator,
					"PriorHostNodeId",
					priorHostNodeId )
			+	" />";
		return( retval );
	}

	public static String formatHostNodeRqstLock( String separator, CFSecHostNodePKey pkey ) {
		String retval = "<RqstHostNodeLock "
			+	formatHostNodePKeyAttributes( separator, pkey )
			+	" />";
		return( retval );
	}

	public static String formatHostNodeRqstLock( String separator, CFSecHostNodeBuff buff ) {
		String retval = "<RqstHostNodeLock "
			+	formatHostNodePKeyAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatHostNodeRqstLock( String separator,
		long argClusterId,
		long argHostNodeId )
	{
		String retval = "<RqstHostNodeLock "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"HostNodeId",
					argHostNodeId )
			+	" />";
		return( retval );
	}

	public static String formatHostNodeRqstUpdate( String separator, CFSecHostNodeBuff buff ) {
		String retval = "<RqstHostNodeUpdate "
			+	formatHostNodeBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatHostNodeRqstDelete( String separator, CFSecHostNodeBuff buff ) {
		String retval = "<RqstHostNodeDelete "
				+	formatHostNodePKeyAttributes( separator, buff )
				+	CFLibXmlUtil.formatRequiredInt32( separator,
						"Revision",
						buff.getRequiredRevision() )
				+	" />";
		return( retval );
	}

	public static String formatHostNodeRqstDelByIdIdx( String separator,
		long argClusterId,
		long argHostNodeId )
	{
		String retval = "<RqstHostNodeDelete "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"HostNodeId",
					argHostNodeId )
			+	" />";
		return( retval );
	}

	public static String formatHostNodeRqstDelByClusterIdx( String separator,
		long argClusterId )
	{
		String retval = "<RqstHostNodeDelByClusterIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	" />";
		return( retval );
	}

	public static String formatHostNodeRqstDelByUDescrIdx( String separator,
		long argClusterId,
		String argDescription )
	{
		String retval = "<RqstHostNodeDelByUDescrIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredXmlString( separator,
					"Description",
					argDescription )
			+	" />";
		return( retval );
	}

	public static String formatHostNodeRqstDelByHostNameIdx( String separator,
		long argClusterId,
		String argHostName )
	{
		String retval = "<RqstHostNodeDelByHostNameIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredXmlString( separator,
					"HostName",
					argHostName )
			+	" />";
		return( retval );
	}

	public static String formatHostNodeRspnSingleOpenTag() {
		String retval = "<RspnHostNodeReadSingle>";
		return( retval );
	}

	public static String formatHostNodeRspnSingleCloseTag() {
		String retval = "</RspnHostNodeReadSingle>";
		return( retval );
	}

	public static String formatHostNodeRspnListOpenTag() {
		String retval = "<RspnHostNodeReadList>";
		return( retval );
	}

	public static String formatHostNodeRspnListCloseTag() {
		String retval = "</RspnHostNodeReadList>";
		return( retval );
	}

	public static String formatHostNodeRspnRec( String separator, CFSecHostNodeBuff buff ) {
		String retval = "<HostNode "
			+	formatHostNodeBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatHostNodeRspnDerivedRec( String separator, CFSecHostNodeBuff buff ) {
		String retval;
		retval = formatHostNodeRspnRec( separator, buff );
		return( retval );
	}

	public static String formatHostNodeRspnCreated( String separator, CFSecHostNodeBuff buff ) {
		String retval = "<RspnHostNodeCreated "
			+	formatHostNodeBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatHostNodeRspnLocked( String separator, CFSecHostNodeBuff buff ) {
		String retval = "<RspnHostNodeLocked "
			+	formatHostNodeBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatHostNodeRspnUpdated( String separator, CFSecHostNodeBuff buff ) {
		String retval = "<RspnHostNodeUpdated "
			+	formatHostNodeBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatHostNodeRspnDeleted() {
		String retval = "<RspnHostNodeDeleted />";
		return( retval );
	}
}
