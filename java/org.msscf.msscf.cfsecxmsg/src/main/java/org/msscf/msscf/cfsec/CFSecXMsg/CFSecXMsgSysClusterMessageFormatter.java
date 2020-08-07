
// Description: Java 11 XML Message message formatter for CFSec.SysCluster

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
 *	CFSecXMsgSysClusterMessageFormatter XML message formatter
 *	for CFSec.SysCluster.
 */
public class CFSecXMsgSysClusterMessageFormatter
{
	public CFSecXMsgSysClusterMessageFormatter() {
	}

	public static String formatSysClusterPKeyAttributes( String separator, CFSecSysClusterPKey pkey ) {
		String retval = CFLibXmlUtil.formatRequiredInt32( null,
				"SingletonId",
				pkey.getRequiredSingletonId() );
		return( retval );
	}

	public static String formatSysClusterPKeyAttributes( String separator, CFSecSysClusterBuff buff ) {
		String retval = CFLibXmlUtil.formatRequiredInt32( separator,
					"SingletonId",
					buff.getRequiredSingletonId() );
		return( retval );
	}

	public static String formatSysClusterBuffAttributes( String separator, CFSecSysClusterBuff buff ) {
		String retval = CFSecXMsgSysClusterMessageFormatter.formatSysClusterPKeyAttributes( separator, buff )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"Revision",
					buff.getRequiredRevision() )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"ClusterId",
					buff.getRequiredClusterId() );
		return( retval );
	}

	public static String formatSysClusterRqstCreate( String separator, CFSecSysClusterBuff buff ) {
		String retval = "<RqstSysClusterCreate "
			+	formatSysClusterBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSysClusterRqstRead( String separator, CFSecSysClusterPKey pkey ) {
		String retval = "<RqstSysClusterRead "
			+	formatSysClusterPKeyAttributes( separator, pkey )
			+	" />";
		return( retval );
	}

	public static String formatSysClusterRqstRead( String separator, CFSecSysClusterBuff buff ) {
		String retval = "<RqstSysClusterRead "
			+	formatSysClusterPKeyAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSysClusterRqstRead( String separator,
		int argSingletonId )
	{
		String retval = "<RqstSysClusterRead "
			+	CFLibXmlUtil.formatRequiredInt32( null,
					"SingletonId",
					argSingletonId )
			+	" />";
		return( retval );
	}

	public static String formatSysClusterRqstReadAll( String separator ) {
		String retval = "<RqstSysClusterReadAll />";
		return( retval );
	}

	public static String formatSysClusterRqstRdByIdIdx( String separator,
		int argSingletonId )
	{
		String retval = "<RqstSysClusterRead "
			+	CFLibXmlUtil.formatRequiredInt32( null,
					"SingletonId",
					argSingletonId )
			+	" />";
		return( retval );
	}

	public static String formatSysClusterRqstRdByClusterIdx( String separator,
		long argClusterId )
	{
		String retval = "<RqstSysClusterRdByClusterIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	" />";
		return( retval );
	}

	public static String formatSysClusterRqstLock( String separator, CFSecSysClusterPKey pkey ) {
		String retval = "<RqstSysClusterLock "
			+	formatSysClusterPKeyAttributes( separator, pkey )
			+	" />";
		return( retval );
	}

	public static String formatSysClusterRqstLock( String separator, CFSecSysClusterBuff buff ) {
		String retval = "<RqstSysClusterLock "
			+	formatSysClusterPKeyAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSysClusterRqstLock( String separator,
		int argSingletonId )
	{
		String retval = "<RqstSysClusterLock "
			+	CFLibXmlUtil.formatRequiredInt32( null,
					"SingletonId",
					argSingletonId )
			+	" />";
		return( retval );
	}

	public static String formatSysClusterRqstUpdate( String separator, CFSecSysClusterBuff buff ) {
		String retval = "<RqstSysClusterUpdate "
			+	formatSysClusterBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSysClusterRqstDelete( String separator, CFSecSysClusterBuff buff ) {
		String retval = "<RqstSysClusterDelete "
				+	formatSysClusterPKeyAttributes( separator, buff )
				+	CFLibXmlUtil.formatRequiredInt32( separator,
						"Revision",
						buff.getRequiredRevision() )
				+	" />";
		return( retval );
	}

	public static String formatSysClusterRqstDelByIdIdx( String separator,
		int argSingletonId )
	{
		String retval = "<RqstSysClusterDelete "
			+	CFLibXmlUtil.formatRequiredInt32( null,
					"SingletonId",
					argSingletonId )
			+	" />";
		return( retval );
	}

	public static String formatSysClusterRqstDelByClusterIdx( String separator,
		long argClusterId )
	{
		String retval = "<RqstSysClusterDelByClusterIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"ClusterId",
					argClusterId )
			+	" />";
		return( retval );
	}

	public static String formatSysClusterRspnSingleOpenTag() {
		String retval = "<RspnSysClusterReadSingle>";
		return( retval );
	}

	public static String formatSysClusterRspnSingleCloseTag() {
		String retval = "</RspnSysClusterReadSingle>";
		return( retval );
	}

	public static String formatSysClusterRspnListOpenTag() {
		String retval = "<RspnSysClusterReadList>";
		return( retval );
	}

	public static String formatSysClusterRspnListCloseTag() {
		String retval = "</RspnSysClusterReadList>";
		return( retval );
	}

	public static String formatSysClusterRspnRec( String separator, CFSecSysClusterBuff buff ) {
		String retval = "<SysCluster "
			+	formatSysClusterBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSysClusterRspnDerivedRec( String separator, CFSecSysClusterBuff buff ) {
		String retval;
		retval = formatSysClusterRspnRec( separator, buff );
		return( retval );
	}

	public static String formatSysClusterRspnCreated( String separator, CFSecSysClusterBuff buff ) {
		String retval = "<RspnSysClusterCreated "
			+	formatSysClusterBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSysClusterRspnLocked( String separator, CFSecSysClusterBuff buff ) {
		String retval = "<RspnSysClusterLocked "
			+	formatSysClusterBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSysClusterRspnUpdated( String separator, CFSecSysClusterBuff buff ) {
		String retval = "<RspnSysClusterUpdated "
			+	formatSysClusterBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSysClusterRspnDeleted() {
		String retval = "<RspnSysClusterDeleted />";
		return( retval );
	}
}
