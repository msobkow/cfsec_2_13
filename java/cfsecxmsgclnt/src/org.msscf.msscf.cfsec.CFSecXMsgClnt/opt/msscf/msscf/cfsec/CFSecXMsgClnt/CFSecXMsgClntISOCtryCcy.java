// Description: Java 11 XMsg Client DbIO implementation for ISOCtryCcy.

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

package com.github.msobkow.cfsec.CFSecXMsgClnt;

import java.lang.reflect.*;
import java.math.*;
import java.security.InvalidAlgorithmParameterException;
import java.security.InvalidKeyException;
import java.security.NoSuchAlgorithmException;
import java.sql.*;
import java.text.*;
import java.util.*;
import javax.crypto.BadPaddingException;
import javax.crypto.IllegalBlockSizeException;
import javax.crypto.NoSuchPaddingException;
import javax.naming.*;
import javax.sql.*;
import com.github.msobkow.cflib.CFLib.*;
import com.github.msobkow.cflib.CFLib.Tip.*;
import org.apache.commons.codec.binary.Base64;

import com.github.msobkow.cfsec.CFSec.*;
import com.github.msobkow.cfsec.CFSecObj.*;
import com.github.msobkow.cfsec.CFSecXMsg.*;
import com.github.msobkow.cfsec.CFSecXMsgRspn.*;

/*
 *	CFSecXMsgClntISOCtryCcy XMsg Client DbIO implementation
 *	for ISOCtryCcy.
 */
public class CFSecXMsgClntISOCtryCcy
	implements ICFSecISOCtryCcyTable
{
	private CFSecXMsgClntSchema schema;

	public CFSecXMsgClntISOCtryCcy( CFSecXMsgClntSchema argSchema ) {
		schema = argSchema;
	}

	public void createISOCtryCcy( CFSecAuthorization Authorization,
		CFSecISOCtryCcyBuff Buff )
	{
		final String S_ProcName = "createISOCtryCcy";
		String rqst = CFSecXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFSecXMsgISOCtryCcyMessageFormatter.formatISOCtryCcyRqstCreate( "\n\t\t\t", Buff )
			+	"\n"
			+	CFSecXMsgSchemaMessageFormatter.formatRqstXmlPostamble();
		try {
			schema.getCFTipClientHandler().issueAppRequest( rqst );
		}
		catch( BadPaddingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught BadPaddingException - " + e.getMessage(),
				e );
		}
		catch( IllegalBlockSizeException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught IllegalBlockSizeException - " + e.getMessage(),
				e );
		}
		catch( InvalidKeyException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidKeyException - " + e.getMessage(),
				e );
		}
		catch( NoSuchAlgorithmException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchAlgorithmException - " + e.getMessage(),
				e );
		}
		catch( InvalidAlgorithmParameterException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidAlgorithmParameterException - " + e.getMessage(),
				e );
		}
		catch( NoSuchPaddingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchPaddingException - " + e.getMessage(),
				e );
		}
		ICFTipResponseHandler responseHandler = schema.getCFTipClientHandler().getResponseHandler();
		RuntimeException exceptionRaised = responseHandler.getExceptionRaised();
		if( exceptionRaised != null ) {
			throw exceptionRaised;
		}
		Object lastObjectProcessed = responseHandler.getLastObjectProcessed();
		if( lastObjectProcessed != null ) {
			ICFSecISOCtryCcyObj realised = null;
			if( lastObjectProcessed instanceof ICFSecISOCtryCcyObj ) {
				realised = (ICFSecISOCtryCcyObj)lastObjectProcessed;
			}
			else {
				throw new CFLibUnsupportedClassException( getClass(),
					S_ProcName,
					"lastObjectProcessed",
					lastObjectProcessed,
					"ICFSecISOCtryCcyObj" );
			}
			if( realised != null ) {
				Buff.set( realised.getISOCtryCcyBuff() );
			}
		}
		else {
			throw new CFLibNullArgumentException( getClass(),
				S_ProcName,
				0,
				"responseHandler.getLastObjectProcessed()" );
		}
	}

	public CFSecISOCtryCcyBuff readDerived( CFSecAuthorization Authorization,
		CFSecISOCtryCcyPKey PKey )
	{
		final String S_ProcName = "readDerived";
		String rqst = CFSecXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFSecXMsgISOCtryCcyMessageFormatter.formatISOCtryCcyRqstRead( "\n\t\t\t", PKey )
			+	"\n"
			+	CFSecXMsgSchemaMessageFormatter.formatRqstXmlPostamble();
		try {
			schema.getCFTipClientHandler().issueAppRequest( rqst );
		}
		catch( BadPaddingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught BadPaddingException - " + e.getMessage(),
				e );
		}
		catch( IllegalBlockSizeException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught IllegalBlockSizeException - " + e.getMessage(),
				e );
		}
		catch( InvalidKeyException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidKeyException - " + e.getMessage(),
				e );
		}
		catch( NoSuchAlgorithmException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchAlgorithmException - " + e.getMessage(),
				e );
		}
		catch( InvalidAlgorithmParameterException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidAlgorithmParameterException - " + e.getMessage(),
				e );
		}
		catch( NoSuchPaddingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchPaddingException - " + e.getMessage(),
				e );
		}
		ICFTipResponseHandler responseHandler = schema.getCFTipClientHandler().getResponseHandler();
		RuntimeException exceptionRaised = responseHandler.getExceptionRaised();
		if( exceptionRaised != null ) {
			throw exceptionRaised;
		}
		CFSecISOCtryCcyBuff buff = null;
		Object lastObjectProcessed = responseHandler.getLastObjectProcessed();
		if( lastObjectProcessed != null ) {
			ICFSecISOCtryCcyObj realised = null;
			if( lastObjectProcessed instanceof ICFSecISOCtryCcyObj ) {
				realised = (ICFSecISOCtryCcyObj)lastObjectProcessed;
			}
			else {
				throw new CFLibUnsupportedClassException( getClass(),
					S_ProcName,
					"lastObjectProcessed",
					lastObjectProcessed,
					"ICFSecISOCtryCcyObj" );
			}
			if( realised != null ) {
				buff = realised.getISOCtryCcyBuff();
			}
		}
		return( buff );
	}

	public CFSecISOCtryCcyBuff lockDerived( CFSecAuthorization Authorization,
		CFSecISOCtryCcyPKey PKey )
	{
		final String S_ProcName = "lockDerived";
		String rqst = CFSecXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFSecXMsgISOCtryCcyMessageFormatter.formatISOCtryCcyRqstLock( "\n\t\t\t", PKey )
			+	"\n"
			+	CFSecXMsgSchemaMessageFormatter.formatRqstXmlPostamble();
		try {
			schema.getCFTipClientHandler().issueAppRequest( rqst );
		}
		catch( BadPaddingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught BadPaddingException - " + e.getMessage(),
				e );
		}
		catch( IllegalBlockSizeException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught IllegalBlockSizeException - " + e.getMessage(),
				e );
		}
		catch( InvalidKeyException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidKeyException - " + e.getMessage(),
				e );
		}
		catch( NoSuchAlgorithmException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchAlgorithmException - " + e.getMessage(),
				e );
		}
		catch( InvalidAlgorithmParameterException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidAlgorithmParameterException - " + e.getMessage(),
				e );
		}
		catch( NoSuchPaddingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchPaddingException - " + e.getMessage(),
				e );
		}
		ICFTipResponseHandler responseHandler = schema.getCFTipClientHandler().getResponseHandler();
		RuntimeException exceptionRaised = responseHandler.getExceptionRaised();
		if( exceptionRaised != null ) {
			throw exceptionRaised;
		}
		CFSecISOCtryCcyBuff buff = null;
		Object lastObjectProcessed = responseHandler.getLastObjectProcessed();
		if( lastObjectProcessed != null ) {
			ICFSecISOCtryCcyObj realised = null;
			if( lastObjectProcessed instanceof ICFSecISOCtryCcyObj ) {
				realised = (ICFSecISOCtryCcyObj)lastObjectProcessed;
			}
			else {
				throw new CFLibUnsupportedClassException( getClass(),
					S_ProcName,
					"lastObjectProcessed",
					lastObjectProcessed,
					"ICFSecISOCtryCcyObj" );
			}
			if( realised != null ) {
				buff = realised.getISOCtryCcyBuff();
			}
		}
		return( buff );
	}

	public CFSecISOCtryCcyBuff[] readAllDerived( CFSecAuthorization Authorization ) {
		final String S_ProcName = "readAllDerived";
		String rqst = CFSecXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFSecXMsgISOCtryCcyMessageFormatter.formatISOCtryCcyRqstReadAll( "\n\t\t\t" )
			+	"\n"
			+	CFSecXMsgSchemaMessageFormatter.formatRqstXmlPostamble();
		try {
			schema.getCFTipClientHandler().issueAppRequest( rqst );
		}
		catch( BadPaddingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught BadPaddingException - " + e.getMessage(),
				e );
		}
		catch( IllegalBlockSizeException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught IllegalBlockSizeException - " + e.getMessage(),
				e );
		}
		catch( InvalidKeyException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidKeyException - " + e.getMessage(),
				e );
		}
		catch( NoSuchAlgorithmException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchAlgorithmException - " + e.getMessage(),
				e );
		}
		catch( InvalidAlgorithmParameterException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidAlgorithmParameterException - " + e.getMessage(),
				e );
		}
		catch( NoSuchPaddingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchPaddingException - " + e.getMessage(),
				e );
		}
		ICFTipResponseHandler responseHandler = schema.getCFTipClientHandler().getResponseHandler();
		RuntimeException exceptionRaised = responseHandler.getExceptionRaised();
		if( exceptionRaised != null ) {
			throw exceptionRaised;
		}
		Object sortedListObj = responseHandler.getListOfObjects();
		@SuppressWarnings("unchecked")
		List<ICFSecISOCtryCcyObj> sortedList =
			(List<ICFSecISOCtryCcyObj>)sortedListObj;
		CFSecISOCtryCcyBuff arr[];
		if( sortedList != null ) {
			int sz = sortedList.size();
			arr = new CFSecISOCtryCcyBuff[ sz ];
			Iterator<ICFSecISOCtryCcyObj> iter = sortedList.iterator();
			ICFSecISOCtryCcyObj cur;
			for( int idx = 0; idx < sz; idx ++ ) {
				cur = (ICFSecISOCtryCcyObj)iter.next();
				arr[idx] = cur.getISOCtryCcyBuff();
			}
		}
		else {
			arr = new CFSecISOCtryCcyBuff[ 0 ];
		}
		return( arr );
	}

	public CFSecISOCtryCcyBuff readDerivedByIdIdx( CFSecAuthorization Authorization,
		short argISOCtryId,
		short argISOCcyId )
	{
		final String S_ProcName = "readDerivedByIdIdx";
		String rqst = CFSecXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFSecXMsgISOCtryCcyMessageFormatter.formatISOCtryCcyRqstRdByIdIdx( "\n\t\t\t",
							argISOCtryId,
							argISOCcyId )
			+	"\n"
			+	CFSecXMsgSchemaMessageFormatter.formatRqstXmlPostamble();
		try {
			schema.getCFTipClientHandler().issueAppRequest( rqst );
		}
		catch( BadPaddingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught BadPaddingException - " + e.getMessage(),
				e );
		}
		catch( IllegalBlockSizeException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught IllegalBlockSizeException - " + e.getMessage(),
				e );
		}
		catch( InvalidKeyException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidKeyException - " + e.getMessage(),
				e );
		}
		catch( NoSuchAlgorithmException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchAlgorithmException - " + e.getMessage(),
				e );
		}
		catch( InvalidAlgorithmParameterException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidAlgorithmParameterException - " + e.getMessage(),
				e );
		}
		catch( NoSuchPaddingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchPaddingException - " + e.getMessage(),
				e );
		}
		ICFTipResponseHandler responseHandler = schema.getCFTipClientHandler().getResponseHandler();
		RuntimeException exceptionRaised = responseHandler.getExceptionRaised();
		if( exceptionRaised != null ) {
			throw exceptionRaised;
		}
		CFSecISOCtryCcyBuff buff = null;
		Object lastObjectProcessed = responseHandler.getLastObjectProcessed();
		if( lastObjectProcessed != null ) {
			ICFSecISOCtryCcyObj realised = null;
			if( lastObjectProcessed instanceof ICFSecISOCtryCcyObj ) {
				realised = (ICFSecISOCtryCcyObj)lastObjectProcessed;
			}
			else {
				throw new CFLibUnsupportedClassException( getClass(),
					S_ProcName,
					"lastObjectProcessed",
					lastObjectProcessed,
					"ICFSecISOCtryCcyObj" );
			}
			if( realised != null ) {
				buff = realised.getISOCtryCcyBuff();
			}
		}
		return( buff );
	}

	public CFSecISOCtryCcyBuff[] readDerivedByCtryIdx( CFSecAuthorization Authorization,
		short argISOCtryId )
	{
		final String S_ProcName = "readDerivedByCtryIdx";
		String rqst = CFSecXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFSecXMsgISOCtryCcyMessageFormatter.formatISOCtryCcyRqstRdByCtryIdx( "\n\t\t\t",
							argISOCtryId )
			+	"\n"
			+	CFSecXMsgSchemaMessageFormatter.formatRqstXmlPostamble();
		try {
			schema.getCFTipClientHandler().issueAppRequest( rqst );
		}
		catch( BadPaddingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught BadPaddingException - " + e.getMessage(),
				e );
		}
		catch( IllegalBlockSizeException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught IllegalBlockSizeException - " + e.getMessage(),
				e );
		}
		catch( InvalidKeyException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidKeyException - " + e.getMessage(),
				e );
		}
		catch( NoSuchAlgorithmException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchAlgorithmException - " + e.getMessage(),
				e );
		}
		catch( InvalidAlgorithmParameterException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidAlgorithmParameterException - " + e.getMessage(),
				e );
		}
		catch( NoSuchPaddingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchPaddingException - " + e.getMessage(),
				e );
		}
		ICFTipResponseHandler responseHandler = schema.getCFTipClientHandler().getResponseHandler();
		RuntimeException exceptionRaised = responseHandler.getExceptionRaised();
		if( exceptionRaised != null ) {
			throw exceptionRaised;
		}
		Object sortedListObj = responseHandler.getListOfObjects();
		@SuppressWarnings("unchecked")
		List<ICFSecISOCtryCcyObj> sortedList =
			(List<ICFSecISOCtryCcyObj>)sortedListObj;
		CFSecISOCtryCcyBuff arr[];
		if( sortedList != null ) {
			int sz = sortedList.size();
			arr = new CFSecISOCtryCcyBuff[ sz ];
			Iterator<ICFSecISOCtryCcyObj> iter = sortedList.iterator();
			ICFSecISOCtryCcyObj cur;
			for( int idx = 0; idx < sz; idx ++ ) {
				cur = (ICFSecISOCtryCcyObj)iter.next();
				arr[idx] = cur.getISOCtryCcyBuff();
			}
		}
		else {
			arr = new CFSecISOCtryCcyBuff[ 0 ];
		}
		return( arr );
	}

	public CFSecISOCtryCcyBuff[] readDerivedByCcyIdx( CFSecAuthorization Authorization,
		short argISOCcyId )
	{
		final String S_ProcName = "readDerivedByCcyIdx";
		String rqst = CFSecXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFSecXMsgISOCtryCcyMessageFormatter.formatISOCtryCcyRqstRdByCcyIdx( "\n\t\t\t",
							argISOCcyId )
			+	"\n"
			+	CFSecXMsgSchemaMessageFormatter.formatRqstXmlPostamble();
		try {
			schema.getCFTipClientHandler().issueAppRequest( rqst );
		}
		catch( BadPaddingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught BadPaddingException - " + e.getMessage(),
				e );
		}
		catch( IllegalBlockSizeException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught IllegalBlockSizeException - " + e.getMessage(),
				e );
		}
		catch( InvalidKeyException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidKeyException - " + e.getMessage(),
				e );
		}
		catch( NoSuchAlgorithmException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchAlgorithmException - " + e.getMessage(),
				e );
		}
		catch( InvalidAlgorithmParameterException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidAlgorithmParameterException - " + e.getMessage(),
				e );
		}
		catch( NoSuchPaddingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchPaddingException - " + e.getMessage(),
				e );
		}
		ICFTipResponseHandler responseHandler = schema.getCFTipClientHandler().getResponseHandler();
		RuntimeException exceptionRaised = responseHandler.getExceptionRaised();
		if( exceptionRaised != null ) {
			throw exceptionRaised;
		}
		Object sortedListObj = responseHandler.getListOfObjects();
		@SuppressWarnings("unchecked")
		List<ICFSecISOCtryCcyObj> sortedList =
			(List<ICFSecISOCtryCcyObj>)sortedListObj;
		CFSecISOCtryCcyBuff arr[];
		if( sortedList != null ) {
			int sz = sortedList.size();
			arr = new CFSecISOCtryCcyBuff[ sz ];
			Iterator<ICFSecISOCtryCcyObj> iter = sortedList.iterator();
			ICFSecISOCtryCcyObj cur;
			for( int idx = 0; idx < sz; idx ++ ) {
				cur = (ICFSecISOCtryCcyObj)iter.next();
				arr[idx] = cur.getISOCtryCcyBuff();
			}
		}
		else {
			arr = new CFSecISOCtryCcyBuff[ 0 ];
		}
		return( arr );
	}

	public CFSecISOCtryCcyBuff readBuff( CFSecAuthorization Authorization,
		CFSecISOCtryCcyPKey PKey )
	{
		throw new CFLibNotSupportedException( getClass(),
			"readBuff" );
	}

	public CFSecISOCtryCcyBuff lockBuff( CFSecAuthorization Authorization,
		CFSecISOCtryCcyPKey PKey )
	{
		throw new CFLibNotSupportedException( getClass(),
			"lockBuff" );
	}

	public CFSecISOCtryCcyBuff[] readAllBuff( CFSecAuthorization Authorization ) {
		final String S_ProcName = "readAllBuff";
		String rqst = CFSecXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFSecXMsgISOCtryCcyMessageFormatter.formatISOCtryCcyRqstReadAll( "\n\t\t\t" )
			+	"\n"
			+	CFSecXMsgSchemaMessageFormatter.formatRqstXmlPostamble();
		try {
			schema.getCFTipClientHandler().issueAppRequest( rqst );
		}
		catch( BadPaddingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught BadPaddingException - " + e.getMessage(),
				e );
		}
		catch( IllegalBlockSizeException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught IllegalBlockSizeException - " + e.getMessage(),
				e );
		}
		catch( InvalidKeyException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidKeyException - " + e.getMessage(),
				e );
		}
		catch( NoSuchAlgorithmException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchAlgorithmException - " + e.getMessage(),
				e );
		}
		catch( InvalidAlgorithmParameterException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidAlgorithmParameterException - " + e.getMessage(),
				e );
		}
		catch( NoSuchPaddingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchPaddingException - " + e.getMessage(),
				e );
		}
		ICFTipResponseHandler responseHandler = schema.getCFTipClientHandler().getResponseHandler();
		RuntimeException exceptionRaised = responseHandler.getExceptionRaised();
		if( exceptionRaised != null ) {
			throw exceptionRaised;
		}
		Object sortedListObj = responseHandler.getListOfObjects();
		@SuppressWarnings("unchecked")
		List<ICFSecISOCtryCcyObj> sortedList =
			(List<ICFSecISOCtryCcyObj>)sortedListObj;
		CFSecISOCtryCcyBuff arr[];
		if( sortedList != null ) {
			int sz = sortedList.size();
			arr = new CFSecISOCtryCcyBuff[ sz ];
			Iterator<ICFSecISOCtryCcyObj> iter = sortedList.iterator();
			ICFSecISOCtryCcyObj cur;
			for( int idx = 0; idx < sz; idx ++ ) {
				cur = (ICFSecISOCtryCcyObj)iter.next();
				arr[idx] = cur.getISOCtryCcyBuff();
			}
		}
		else {
			arr = new CFSecISOCtryCcyBuff[ 0 ];
		}
		return( arr );
	}

	public CFSecISOCtryCcyBuff readBuffByIdIdx( CFSecAuthorization Authorization,
		short argISOCtryId,
		short argISOCcyId )
	{
		throw new CFLibNotSupportedException( getClass(),
			"readBuffByIdIdx" );
	}

	public CFSecISOCtryCcyBuff[] readBuffByCtryIdx( CFSecAuthorization Authorization,
		short argISOCtryId )
	{
		throw new CFLibNotSupportedException( getClass(),
			"readBuffByCtryIdx" );
	}

	public CFSecISOCtryCcyBuff[] readBuffByCcyIdx( CFSecAuthorization Authorization,
		short argISOCcyId )
	{
		throw new CFLibNotSupportedException( getClass(),
			"readBuffByCcyIdx" );
	}

	public void updateISOCtryCcy( CFSecAuthorization Authorization,
		CFSecISOCtryCcyBuff Buff )
	{
		final String S_ProcName = "updateISOCtryCcy";
		String rqst = CFSecXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFSecXMsgISOCtryCcyMessageFormatter.formatISOCtryCcyRqstUpdate( "\n\t\t\t", Buff )
			+	"\n"
			+	CFSecXMsgSchemaMessageFormatter.formatRqstXmlPostamble();
		try {
			schema.getCFTipClientHandler().issueAppRequest( rqst );
		}
		catch( BadPaddingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught BadPaddingException - " + e.getMessage(),
				e );
		}
		catch( IllegalBlockSizeException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught IllegalBlockSizeException - " + e.getMessage(),
				e );
		}
		catch( InvalidKeyException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidKeyException - " + e.getMessage(),
				e );
		}
		catch( NoSuchAlgorithmException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchAlgorithmException - " + e.getMessage(),
				e );
		}
		catch( InvalidAlgorithmParameterException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidAlgorithmParameterException - " + e.getMessage(),
				e );
		}
		catch( NoSuchPaddingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchPaddingException - " + e.getMessage(),
				e );
		}
		ICFTipResponseHandler responseHandler = schema.getCFTipClientHandler().getResponseHandler();
		RuntimeException exceptionRaised = responseHandler.getExceptionRaised();
		if( exceptionRaised != null ) {
			throw exceptionRaised;
		}
		CFSecISOCtryCcyBuff buff = null;
		Object lastObjectProcessed = responseHandler.getLastObjectProcessed();
		if( lastObjectProcessed != null ) {
			ICFSecISOCtryCcyObj realised = null;
			if( lastObjectProcessed instanceof ICFSecISOCtryCcyObj ) {
				realised = (ICFSecISOCtryCcyObj)lastObjectProcessed;
			}
			else {
				throw new CFLibUnsupportedClassException( getClass(),
					S_ProcName,
					"lastObjectProcessed",
					lastObjectProcessed,
					"ICFSecISOCtryCcyObj" );
			}
			if( realised != null ) {
				buff = realised.getISOCtryCcyBuff();
			}
		}
		if( buff != null ) {
			Buff.set( buff );
		}
	}

	public void deleteISOCtryCcy( CFSecAuthorization Authorization,
		CFSecISOCtryCcyBuff Buff )
	{
		final String S_ProcName = "deleteISOCtryCcy";
		String rqst = CFSecXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFSecXMsgISOCtryCcyMessageFormatter.formatISOCtryCcyRqstDelete( "\n\t\t\t", Buff )
			+	"\n"
			+	CFSecXMsgSchemaMessageFormatter.formatRqstXmlPostamble();
		try {
			schema.getCFTipClientHandler().issueAppRequest( rqst );
		}
		catch( BadPaddingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught BadPaddingException - " + e.getMessage(),
				e );
		}
		catch( IllegalBlockSizeException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught IllegalBlockSizeException - " + e.getMessage(),
				e );
		}
		catch( InvalidKeyException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidKeyException - " + e.getMessage(),
				e );
		}
		catch( NoSuchAlgorithmException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchAlgorithmException - " + e.getMessage(),
				e );
		}
		catch( InvalidAlgorithmParameterException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidAlgorithmParameterException - " + e.getMessage(),
				e );
		}
		catch( NoSuchPaddingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchPaddingException - " + e.getMessage(),
				e );
		}
		ICFTipResponseHandler responseHandler = schema.getCFTipClientHandler().getResponseHandler();
		RuntimeException exceptionRaised = responseHandler.getExceptionRaised();
		if( exceptionRaised != null ) {
			throw exceptionRaised;
		}
		boolean deleted = responseHandler.getDeleted();
		if( ! deleted ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Server did not respond with a Deleted message" );
		}
	}

	public void deleteISOCtryCcyByIdIdx( CFSecAuthorization Authorization,
		short argISOCtryId,
		short argISOCcyId )
	{
		final String S_ProcName = "deleteISOCtryCcyByIdIdx";
		String rqst = CFSecXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFSecXMsgISOCtryCcyMessageFormatter.formatISOCtryCcyRqstDelByIdIdx( "\n\t\t\t",
							argISOCtryId,
							argISOCcyId )
			+	"\n"
			+	CFSecXMsgSchemaMessageFormatter.formatRqstXmlPostamble();
		try {
			schema.getCFTipClientHandler().issueAppRequest( rqst );
		}
		catch( BadPaddingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught BadPaddingException - " + e.getMessage(),
				e );
		}
		catch( IllegalBlockSizeException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught IllegalBlockSizeException - " + e.getMessage(),
				e );
		}
		catch( InvalidKeyException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidKeyException - " + e.getMessage(),
				e );
		}
		catch( NoSuchAlgorithmException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchAlgorithmException - " + e.getMessage(),
				e );
		}
		catch( InvalidAlgorithmParameterException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidAlgorithmParameterException - " + e.getMessage(),
				e );
		}
		catch( NoSuchPaddingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchPaddingException - " + e.getMessage(),
				e );
		}
		ICFTipResponseHandler responseHandler = schema.getCFTipClientHandler().getResponseHandler();
		RuntimeException exceptionRaised = responseHandler.getExceptionRaised();
		if( exceptionRaised != null ) {
			throw exceptionRaised;
		}
		boolean deleted = responseHandler.getDeleted();
		if( ! deleted ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Server did not respond with a Deleted message" );
		}
	}

	public void deleteISOCtryCcyByIdIdx( CFSecAuthorization Authorization,
		CFSecISOCtryCcyPKey argKey )
	{
		deleteISOCtryCcyByIdIdx( Authorization,
			argKey.getRequiredISOCtryId(),
			argKey.getRequiredISOCcyId() );
	}
	public void deleteISOCtryCcyByCtryIdx( CFSecAuthorization Authorization,
		short argISOCtryId )
	{
		final String S_ProcName = "deleteISOCtryCcyByCtryIdx";
		String rqst = CFSecXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFSecXMsgISOCtryCcyMessageFormatter.formatISOCtryCcyRqstDelByCtryIdx( "\n\t\t\t",
							argISOCtryId )
			+	"\n"
			+	CFSecXMsgSchemaMessageFormatter.formatRqstXmlPostamble();
		try {
			schema.getCFTipClientHandler().issueAppRequest( rqst );
		}
		catch( BadPaddingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught BadPaddingException - " + e.getMessage(),
				e );
		}
		catch( IllegalBlockSizeException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught IllegalBlockSizeException - " + e.getMessage(),
				e );
		}
		catch( InvalidKeyException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidKeyException - " + e.getMessage(),
				e );
		}
		catch( NoSuchAlgorithmException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchAlgorithmException - " + e.getMessage(),
				e );
		}
		catch( InvalidAlgorithmParameterException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidAlgorithmParameterException - " + e.getMessage(),
				e );
		}
		catch( NoSuchPaddingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchPaddingException - " + e.getMessage(),
				e );
		}
		ICFTipResponseHandler responseHandler = schema.getCFTipClientHandler().getResponseHandler();
		RuntimeException exceptionRaised = responseHandler.getExceptionRaised();
		if( exceptionRaised != null ) {
			throw exceptionRaised;
		}
		boolean deleted = responseHandler.getDeleted();
		if( ! deleted ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Server did not respond with a Deleted message" );
		}
	}

	public void deleteISOCtryCcyByCtryIdx( CFSecAuthorization Authorization,
		CFSecISOCtryCcyByCtryIdxKey argKey )
	{
		deleteISOCtryCcyByCtryIdx( Authorization,
			argKey.getRequiredISOCtryId() );
	}
	public void deleteISOCtryCcyByCcyIdx( CFSecAuthorization Authorization,
		short argISOCcyId )
	{
		final String S_ProcName = "deleteISOCtryCcyByCcyIdx";
		String rqst = CFSecXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFSecXMsgISOCtryCcyMessageFormatter.formatISOCtryCcyRqstDelByCcyIdx( "\n\t\t\t",
							argISOCcyId )
			+	"\n"
			+	CFSecXMsgSchemaMessageFormatter.formatRqstXmlPostamble();
		try {
			schema.getCFTipClientHandler().issueAppRequest( rqst );
		}
		catch( BadPaddingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught BadPaddingException - " + e.getMessage(),
				e );
		}
		catch( IllegalBlockSizeException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught IllegalBlockSizeException - " + e.getMessage(),
				e );
		}
		catch( InvalidKeyException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidKeyException - " + e.getMessage(),
				e );
		}
		catch( NoSuchAlgorithmException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchAlgorithmException - " + e.getMessage(),
				e );
		}
		catch( InvalidAlgorithmParameterException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidAlgorithmParameterException - " + e.getMessage(),
				e );
		}
		catch( NoSuchPaddingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchPaddingException - " + e.getMessage(),
				e );
		}
		ICFTipResponseHandler responseHandler = schema.getCFTipClientHandler().getResponseHandler();
		RuntimeException exceptionRaised = responseHandler.getExceptionRaised();
		if( exceptionRaised != null ) {
			throw exceptionRaised;
		}
		boolean deleted = responseHandler.getDeleted();
		if( ! deleted ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Server did not respond with a Deleted message" );
		}
	}

	public void deleteISOCtryCcyByCcyIdx( CFSecAuthorization Authorization,
		CFSecISOCtryCcyByCcyIdxKey argKey )
	{
		deleteISOCtryCcyByCcyIdx( Authorization,
			argKey.getRequiredISOCcyId() );
	}
	/**
	 *	Release the prepared statements.
	 *	<p>
	 *	When the schema changes connections, the prepared statements
	 *	have to be released because they contain connection-specific
	 *	information for most databases.
	 */
	public void releasePreparedStatements() {
		throw new CFLibNotSupportedException( getClass(),
			"releasePreparedStatements" );
	}
}
