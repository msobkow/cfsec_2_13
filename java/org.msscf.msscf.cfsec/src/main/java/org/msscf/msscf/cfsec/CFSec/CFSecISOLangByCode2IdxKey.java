// Description: Java 11 implementation of a ISOLang by Code2Idx index key object.

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

package org.msscf.msscf.cfsec.CFSec;

import java.lang.reflect.*;
import java.io.*;
import java.math.*;
import java.net.*;
import java.rmi.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.msscf.msscf.cflib.CFLib.*;

public class CFSecISOLangByCode2IdxKey
	implements Comparable<Object>,
		Serializable
{
	protected String optionalISO6391Code;
	public CFSecISOLangByCode2IdxKey() {
		optionalISO6391Code = null;
	}

	public String getOptionalISO6391Code() {
		return( optionalISO6391Code );
	}

	public void setOptionalISO6391Code( String value ) {
		if( value == null ) {
			optionalISO6391Code = null;
		}
		else if( value.length() > 2 ) {
			throw new CFLibArgumentOverflowException( getClass(),
				"setOptionalISO6391Code",
				1,
				"value.length()",
				value.length(),
				2 );
		}
		else {
			optionalISO6391Code = value;
		}
	}

	public boolean equals( Object obj ) {
		if( obj == null ) {
			return( false );
		}
		else if( obj instanceof CFSecISOLangByCode2IdxKey ) {
			CFSecISOLangByCode2IdxKey rhs = (CFSecISOLangByCode2IdxKey)obj;
			if( getOptionalISO6391Code() != null ) {
				if( rhs.getOptionalISO6391Code() != null ) {
					if( ! getOptionalISO6391Code().equals( rhs.getOptionalISO6391Code() ) ) {
						return( false );
					}
				}
			}
			else {
				if( rhs.getOptionalISO6391Code() != null ) {
					return( false );
				}
			}
			return( true );
		}
		else if( obj instanceof CFSecISOLangBuff ) {
			CFSecISOLangBuff rhs = (CFSecISOLangBuff)obj;
			if( getOptionalISO6391Code() != null ) {
				if( rhs.getOptionalISO6391Code() != null ) {
					if( ! getOptionalISO6391Code().equals( rhs.getOptionalISO6391Code() ) ) {
						return( false );
					}
				}
			}
			else {
				if( rhs.getOptionalISO6391Code() != null ) {
					return( false );
				}
			}
			return( true );
		}
		else {
			return( false );
		}
	}

	public int hashCode() {
		int hashCode = 0;
		if( getOptionalISO6391Code() != null ) {
			hashCode = hashCode + getOptionalISO6391Code().hashCode();
		}
		return( hashCode & 0x7fffffff );
	}

	public int compareTo( Object obj ) {
		if( obj == null ) {
			return( 1 );
		}
		else if( obj instanceof CFSecISOLangByCode2IdxKey ) {
			CFSecISOLangByCode2IdxKey rhs = (CFSecISOLangByCode2IdxKey)obj;
			if( getOptionalISO6391Code() != null ) {
				if( rhs.getOptionalISO6391Code() != null ) {
					int cmp = getOptionalISO6391Code().compareTo( rhs.getOptionalISO6391Code() );
					if( cmp != 0 ) {
						return( cmp );
					}
				}
				else {
					return( 1 );
				}
			}
			else {
				if( rhs.getOptionalISO6391Code() != null ) {
					return( -1 );
				}
			}
			return( 0 );
		}
		else if( obj instanceof CFSecISOLangBuff ) {
			CFSecISOLangBuff rhs = (CFSecISOLangBuff)obj;
			if( getOptionalISO6391Code() != null ) {
				if( rhs.getOptionalISO6391Code() != null ) {
					int cmp = getOptionalISO6391Code().compareTo( rhs.getOptionalISO6391Code() );
					if( cmp != 0 ) {
						return( cmp );
					}
				}
				else {
					return( 1 );
				}
			}
			else {
				if( rhs.getOptionalISO6391Code() != null ) {
					return( -1 );
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
		String ret = "<CFSecISOLangByCode2Idx"
			+ " OptionalISO6391Code=" + ( ( getOptionalISO6391Code() == null ) ? "null" : "\"" + CFSecSchema.xmlEncodeString( getOptionalISO6391Code() ) + "\"" )
			+ "/>";
		return( ret );
	}
}
