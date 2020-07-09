
// Description: Java 11 XML Message message formatter for CFSec.HostNode

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
