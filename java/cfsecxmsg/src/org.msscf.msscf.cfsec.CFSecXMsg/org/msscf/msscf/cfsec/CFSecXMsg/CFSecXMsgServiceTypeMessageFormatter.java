
// Description: Java 11 XML Message message formatter for CFSec.ServiceType

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
