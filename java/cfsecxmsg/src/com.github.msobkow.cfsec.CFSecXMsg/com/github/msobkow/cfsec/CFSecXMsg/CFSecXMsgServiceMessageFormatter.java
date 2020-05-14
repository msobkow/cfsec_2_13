
// Description: Java 11 XML Message message formatter for CFSec.Service

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
 *	CFSecXMsgServiceMessageFormatter XML message formatter
 *	for CFSec.Service.
 */
public class CFSecXMsgServiceMessageFormatter
{
	public CFSecXMsgServiceMessageFormatter() {
	}

	public static String formatServicePKeyAttributes( String separator, CFSecServicePKey pkey ) {
		String retval = CFLibXmlUtil.formatRequiredInt64( null,
				"ClusterId",
				pkey.getRequiredClusterId() )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
				"ServiceId",
				pkey.getRequiredServiceId() );
		return( retval );
	}

	public static String formatServicePKeyAttributes( String separator, CFSecServiceBuff buff ) {
		String retval = CFLibXmlUtil.formatRequiredInt64( separator,
					"ClusterId",
					buff.getRequiredClusterId() )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"ServiceId",
					buff.getRequiredServiceId() );
		return( retval );
	}

	public static String formatServiceBuffAttributes( String separator, CFSecServiceBuff buff ) {
		String retval = CFSecXMsgServiceMessageFormatter.formatServicePKeyAttributes( separator, buff )
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
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"HostNodeId",
					buff.getRequiredHostNodeId() )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"ServiceTypeId",
					buff.getRequiredServiceTypeId() )
			+	CFLibXmlUtil.formatRequiredInt16( separator,
					"HostPort",
					buff.getRequiredHostPort() );
		return( retval );
	}

	public static String formatServiceRqstCreate( String separator, CFSecServiceBuff buff ) {
		String retval = "<RqstServiceCreate "
			+	formatServiceBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatServiceRqstRead( String separator, CFSecServicePKey pkey ) {
		String retval = "<RqstServiceRead "
			+	formatServicePKeyAttributes( separator, pkey )
			+	" />";
		return( retval );
	}

	public static String formatServiceRqstRead( String separator, CFSecServiceBuff buff ) {
		String retval = "<RqstServiceRead "
			+	formatServicePKeyAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatServiceRqstRead( String separator,
		long argClusterId,
		long argServiceId )
	{
		String retval = "<RqstServiceRead "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"ServiceId",
					argServiceId )
			+	" />";
		return( retval );
	}

	public static String formatServiceRqstReadAll( String separator ) {
		String retval = "<RqstServiceReadAll />";
		return( retval );
	}

	public static String formatServiceRqstPageAll( String separator,
		Long priorClusterId,
		Long priorServiceId ) {
		String retval = "<RqstServicePageAll "
			+	CFLibXmlUtil.formatOptionalInt64( null,
					"PriorClusterId",
					priorClusterId )
			+	CFLibXmlUtil.formatOptionalInt64( separator,
					"PriorServiceId",
					priorServiceId )
			+	" />";
		return( retval );
	}

	public static String formatServiceRqstRdByIdIdx( String separator,
		long argClusterId,
		long argServiceId )
	{
		String retval = "<RqstServiceRead "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"ServiceId",
					argServiceId )
			+	" />";
		return( retval );
	}

	public static String formatServiceRqstRdByClusterIdx( String separator,
		long argClusterId )
	{
		String retval = "<RqstServiceRdByClusterIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	" />";
		return( retval );
	}

	public static String formatServiceRqstRdByHostIdx( String separator,
		long argClusterId,
		long argHostNodeId )
	{
		String retval = "<RqstServiceRdByHostIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"HostNodeId",
					argHostNodeId )
			+	" />";
		return( retval );
	}

	public static String formatServiceRqstRdByTypeIdx( String separator,
		int argServiceTypeId )
	{
		String retval = "<RqstServiceRdByTypeIdx "
			+	CFLibXmlUtil.formatRequiredInt32( null,
					"ServiceTypeId",
					argServiceTypeId )
			+	" />";
		return( retval );
	}

	public static String formatServiceRqstRdByUTypeIdx( String separator,
		long argClusterId,
		long argHostNodeId,
		int argServiceTypeId )
	{
		String retval = "<RqstServiceRdByUTypeIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"HostNodeId",
					argHostNodeId )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"ServiceTypeId",
					argServiceTypeId )
			+	" />";
		return( retval );
	}

	public static String formatServiceRqstRdByUHostPortIdx( String separator,
		long argClusterId,
		long argHostNodeId,
		short argHostPort )
	{
		String retval = "<RqstServiceRdByUHostPortIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"HostNodeId",
					argHostNodeId )
			+	CFLibXmlUtil.formatRequiredInt16( separator,
					"HostPort",
					argHostPort )
			+	" />";
		return( retval );
	}

	public static String formatServiceRqstPageByClusterIdx( String separator,
		long argClusterId,
		Long priorClusterId,
		Long priorServiceId )
	{
		String retval = "<RqstServicePageByClusterIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatOptionalInt64( separator,
					"PriorClusterId",
					priorClusterId )
			+	CFLibXmlUtil.formatOptionalInt64( separator,
					"PriorServiceId",
					priorServiceId )
			+	" />";
		return( retval );
	}

	public static String formatServiceRqstPageByHostIdx( String separator,
		long argClusterId,
		long argHostNodeId,
		Long priorClusterId,
		Long priorServiceId )
	{
		String retval = "<RqstServicePageByHostIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"HostNodeId",
					argHostNodeId )
			+	CFLibXmlUtil.formatOptionalInt64( separator,
					"PriorClusterId",
					priorClusterId )
			+	CFLibXmlUtil.formatOptionalInt64( separator,
					"PriorServiceId",
					priorServiceId )
			+	" />";
		return( retval );
	}

	public static String formatServiceRqstPageByTypeIdx( String separator,
		int argServiceTypeId,
		Long priorClusterId,
		Long priorServiceId )
	{
		String retval = "<RqstServicePageByTypeIdx "
			+	CFLibXmlUtil.formatRequiredInt32( null,
					"ServiceTypeId",
					argServiceTypeId )
			+	CFLibXmlUtil.formatOptionalInt64( separator,
					"PriorClusterId",
					priorClusterId )
			+	CFLibXmlUtil.formatOptionalInt64( separator,
					"PriorServiceId",
					priorServiceId )
			+	" />";
		return( retval );
	}

	public static String formatServiceRqstLock( String separator, CFSecServicePKey pkey ) {
		String retval = "<RqstServiceLock "
			+	formatServicePKeyAttributes( separator, pkey )
			+	" />";
		return( retval );
	}

	public static String formatServiceRqstLock( String separator, CFSecServiceBuff buff ) {
		String retval = "<RqstServiceLock "
			+	formatServicePKeyAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatServiceRqstLock( String separator,
		long argClusterId,
		long argServiceId )
	{
		String retval = "<RqstServiceLock "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"ServiceId",
					argServiceId )
			+	" />";
		return( retval );
	}

	public static String formatServiceRqstUpdate( String separator, CFSecServiceBuff buff ) {
		String retval = "<RqstServiceUpdate "
			+	formatServiceBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatServiceRqstDelete( String separator, CFSecServiceBuff buff ) {
		String retval = "<RqstServiceDelete "
				+	formatServicePKeyAttributes( separator, buff )
				+	CFLibXmlUtil.formatRequiredInt32( separator,
						"Revision",
						buff.getRequiredRevision() )
				+	" />";
		return( retval );
	}

	public static String formatServiceRqstDelByIdIdx( String separator,
		long argClusterId,
		long argServiceId )
	{
		String retval = "<RqstServiceDelete "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"ServiceId",
					argServiceId )
			+	" />";
		return( retval );
	}

	public static String formatServiceRqstDelByClusterIdx( String separator,
		long argClusterId )
	{
		String retval = "<RqstServiceDelByClusterIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	" />";
		return( retval );
	}

	public static String formatServiceRqstDelByHostIdx( String separator,
		long argClusterId,
		long argHostNodeId )
	{
		String retval = "<RqstServiceDelByHostIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"HostNodeId",
					argHostNodeId )
			+	" />";
		return( retval );
	}

	public static String formatServiceRqstDelByTypeIdx( String separator,
		int argServiceTypeId )
	{
		String retval = "<RqstServiceDelByTypeIdx "
			+	CFLibXmlUtil.formatRequiredInt32( null,
					"ServiceTypeId",
					argServiceTypeId )
			+	" />";
		return( retval );
	}

	public static String formatServiceRqstDelByUTypeIdx( String separator,
		long argClusterId,
		long argHostNodeId,
		int argServiceTypeId )
	{
		String retval = "<RqstServiceDelByUTypeIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"HostNodeId",
					argHostNodeId )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"ServiceTypeId",
					argServiceTypeId )
			+	" />";
		return( retval );
	}

	public static String formatServiceRqstDelByUHostPortIdx( String separator,
		long argClusterId,
		long argHostNodeId,
		short argHostPort )
	{
		String retval = "<RqstServiceDelByUHostPortIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"HostNodeId",
					argHostNodeId )
			+	CFLibXmlUtil.formatRequiredInt16( separator,
					"HostPort",
					argHostPort )
			+	" />";
		return( retval );
	}

	public static String formatServiceRspnSingleOpenTag() {
		String retval = "<RspnServiceReadSingle>";
		return( retval );
	}

	public static String formatServiceRspnSingleCloseTag() {
		String retval = "</RspnServiceReadSingle>";
		return( retval );
	}

	public static String formatServiceRspnListOpenTag() {
		String retval = "<RspnServiceReadList>";
		return( retval );
	}

	public static String formatServiceRspnListCloseTag() {
		String retval = "</RspnServiceReadList>";
		return( retval );
	}

	public static String formatServiceRspnRec( String separator, CFSecServiceBuff buff ) {
		String retval = "<Service "
			+	formatServiceBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatServiceRspnDerivedRec( String separator, CFSecServiceBuff buff ) {
		String retval;
		retval = formatServiceRspnRec( separator, buff );
		return( retval );
	}

	public static String formatServiceRspnCreated( String separator, CFSecServiceBuff buff ) {
		String retval = "<RspnServiceCreated "
			+	formatServiceBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatServiceRspnLocked( String separator, CFSecServiceBuff buff ) {
		String retval = "<RspnServiceLocked "
			+	formatServiceBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatServiceRspnUpdated( String separator, CFSecServiceBuff buff ) {
		String retval = "<RspnServiceUpdated "
			+	formatServiceBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatServiceRspnDeleted() {
		String retval = "<RspnServiceDeleted />";
		return( retval );
	}
}
