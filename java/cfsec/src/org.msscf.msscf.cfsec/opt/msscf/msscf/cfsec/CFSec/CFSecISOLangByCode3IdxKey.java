// Description: Java 11 implementation of a ISOLang by Code3Idx index key object.

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

package com.github.msobkow.cfsec.CFSec;

import java.lang.reflect.*;
import java.io.*;
import java.math.*;
import java.net.*;
import java.rmi.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import com.github.msobkow.cflib.CFLib.*;

public class CFSecISOLangByCode3IdxKey
	implements Comparable<Object>,
		Serializable
{
	protected String requiredISO6392Code;
	public CFSecISOLangByCode3IdxKey() {
		requiredISO6392Code = new String( CFSecISOLangBuff.ISO6392CODE_INIT_VALUE );
	}

	public String getRequiredISO6392Code() {
		return( requiredISO6392Code );
	}

	public void setRequiredISO6392Code( String value ) {
		if( value == null ) {
			throw new CFLibNullArgumentException( getClass(),
				"setRequiredISO6392Code",
				1,
				"value" );
		}
		if( value.length() > 3 ) {
			throw new CFLibArgumentOverflowException( getClass(),
				"setRequiredISO6392Code",
				1,
				"value.length()",
				value.length(),
				3 );
		}
		requiredISO6392Code = value;
	}

	public boolean equals( Object obj ) {
		if( obj == null ) {
			return( false );
		}
		else if( obj instanceof CFSecISOLangByCode3IdxKey ) {
			CFSecISOLangByCode3IdxKey rhs = (CFSecISOLangByCode3IdxKey)obj;
			if( ! getRequiredISO6392Code().equals( rhs.getRequiredISO6392Code() ) ) {
				return( false );
			}
			return( true );
		}
		else if( obj instanceof CFSecISOLangBuff ) {
			CFSecISOLangBuff rhs = (CFSecISOLangBuff)obj;
			if( ! getRequiredISO6392Code().equals( rhs.getRequiredISO6392Code() ) ) {
				return( false );
			}
			return( true );
		}
		else {
			return( false );
		}
	}

	public int hashCode() {
		int hashCode = 0;
		if( getRequiredISO6392Code() != null ) {
			hashCode = hashCode + getRequiredISO6392Code().hashCode();
		}
		return( hashCode & 0x7fffffff );
	}

	public int compareTo( Object obj ) {
		if( obj == null ) {
			return( 1 );
		}
		else if( obj instanceof CFSecISOLangByCode3IdxKey ) {
			CFSecISOLangByCode3IdxKey rhs = (CFSecISOLangByCode3IdxKey)obj;
			{
				int cmp = getRequiredISO6392Code().compareTo( rhs.getRequiredISO6392Code() );
				if( cmp != 0 ) {
					return( cmp );
				}
			}
			return( 0 );
		}
		else if( obj instanceof CFSecISOLangBuff ) {
			CFSecISOLangBuff rhs = (CFSecISOLangBuff)obj;
			{
				int cmp = getRequiredISO6392Code().compareTo( rhs.getRequiredISO6392Code() );
				if( cmp != 0 ) {
					return( cmp );
				}
			}
			return( 0 );
		}
		else {
			throw new CFLibUnsupportedClassException( getClass(),
				"compareTo",
				"obj",
				obj,
				null );
		}
	}

	public String toString() {
		String ret = "<CFSecISOLangByCode3Idx"
			+ " RequiredISO6392Code=" + "\"" + CFSecSchema.xmlEncodeString( getRequiredISO6392Code() ) + "\""
			+ "/>";
		return( ret );
	}
}
