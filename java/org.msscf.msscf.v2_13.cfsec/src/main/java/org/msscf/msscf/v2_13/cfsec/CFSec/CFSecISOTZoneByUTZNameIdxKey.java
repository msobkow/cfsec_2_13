// Description: Java 11 implementation of a ISOTZone by UTZNameIdx index key object.

/*
 *	org.msscf.msscf.CFSec
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFSec 2.13 Security Essentials
 *	
 *	Copyright 2020-2021 Mark Stephen Sobkow mark.sobkow@gmail.com
 *	
 *	Licensed under the Apache License, Version 2.0 (the "License");
 *	you may not use this file except in compliance with the License.
 *	You may obtain a copy of the License at
 *	
 *	http://www.apache.org/licenses/LICENSE-2.0
 *	
 *	Unless required by applicable law or agreed to in writing, software
 *	distributed under the License is distributed on an "AS IS" BASIS,
 *	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *	See the License for the specific language governing permissions and
 *	limitations under the License.
 *
 *	Manufactured by MSS Code Factory 2.12
 */

package org.msscf.msscf.v2_13.cfsec.CFSec;

import java.lang.reflect.*;
import java.io.*;
import java.math.*;
import java.net.*;
import java.rmi.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.msscf.msscf.v2_13.cflib.CFLib.*;

public class CFSecISOTZoneByUTZNameIdxKey
	implements Comparable<Object>,
		Serializable
{
	protected String requiredTZName;
	public CFSecISOTZoneByUTZNameIdxKey() {
		requiredTZName = new String( CFSecISOTZoneBuff.TZNAME_INIT_VALUE );
	}

	public String getRequiredTZName() {
		return( requiredTZName );
	}

	public void setRequiredTZName( String value ) {
		if( value == null ) {
			throw new CFLibNullArgumentException( getClass(),
				"setRequiredTZName",
				1,
				"value" );
		}
		if( value.length() > 64 ) {
			throw new CFLibArgumentOverflowException( getClass(),
				"setRequiredTZName",
				1,
				"value.length()",
				value.length(),
				64 );
		}
		requiredTZName = value;
	}

	public boolean equals( Object obj ) {
		if( obj == null ) {
			return( false );
		}
		else if( obj instanceof CFSecISOTZoneByUTZNameIdxKey ) {
			CFSecISOTZoneByUTZNameIdxKey rhs = (CFSecISOTZoneByUTZNameIdxKey)obj;
			if( ! getRequiredTZName().equals( rhs.getRequiredTZName() ) ) {
				return( false );
			}
			return( true );
		}
		else if( obj instanceof CFSecISOTZoneBuff ) {
			CFSecISOTZoneBuff rhs = (CFSecISOTZoneBuff)obj;
			if( ! getRequiredTZName().equals( rhs.getRequiredTZName() ) ) {
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
		if( getRequiredTZName() != null ) {
			hashCode = hashCode + getRequiredTZName().hashCode();
		}
		return( hashCode & 0x7fffffff );
	}

	public int compareTo( Object obj ) {
		if( obj == null ) {
			return( 1 );
		}
		else if( obj instanceof CFSecISOTZoneByUTZNameIdxKey ) {
			CFSecISOTZoneByUTZNameIdxKey rhs = (CFSecISOTZoneByUTZNameIdxKey)obj;
			{
				int cmp = getRequiredTZName().compareTo( rhs.getRequiredTZName() );
				if( cmp != 0 ) {
					return( cmp );
				}
			}
			return( 0 );
		}
		else if( obj instanceof CFSecISOTZoneBuff ) {
			CFSecISOTZoneBuff rhs = (CFSecISOTZoneBuff)obj;
			{
				int cmp = getRequiredTZName().compareTo( rhs.getRequiredTZName() );
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
		String ret = "<CFSecISOTZoneByUTZNameIdx"
			+ " RequiredTZName=" + "\"" + CFSecSchema.xmlEncodeString( getRequiredTZName() ) + "\""
			+ "/>";
		return( ret );
	}
}
