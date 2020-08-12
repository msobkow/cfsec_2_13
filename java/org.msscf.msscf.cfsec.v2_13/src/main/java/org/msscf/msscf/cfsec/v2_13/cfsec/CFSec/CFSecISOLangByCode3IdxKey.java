// Description: Java 11 implementation of a ISOLang by Code3Idx index key object.

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

package org.msscf.msscf.cfsec.v2_13.cfsec.CFSec;

import java.lang.reflect.*;
import java.io.*;
import java.math.*;
import java.net.*;
import java.rmi.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.msscf.msscf.cflib.v2_13.CFLib.*;

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
