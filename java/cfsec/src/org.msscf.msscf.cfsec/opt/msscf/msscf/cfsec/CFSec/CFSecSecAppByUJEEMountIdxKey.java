// Description: Java 11 implementation of a SecApp by UJEEMountIdx index key object.

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

public class CFSecSecAppByUJEEMountIdxKey
	implements Comparable<Object>,
		Serializable
{
	protected long requiredClusterId;
	protected String requiredJEEMountName;
	public CFSecSecAppByUJEEMountIdxKey() {
		requiredClusterId = CFSecSecAppBuff.CLUSTERID_INIT_VALUE;
		requiredJEEMountName = new String( CFSecSecAppBuff.JEEMOUNTNAME_INIT_VALUE );
	}

	public long getRequiredClusterId() {
		return( requiredClusterId );
	}

	public void setRequiredClusterId( long value ) {
		if( value < CFSecSecAppBuff.CLUSTERID_MIN_VALUE ) {
			throw new CFLibArgumentUnderflowException( getClass(),
				"setRequiredClusterId",
				1,
				"value",
				value,
				CFSecSecAppBuff.CLUSTERID_MIN_VALUE );
		}
		requiredClusterId = value;
	}

	public String getRequiredJEEMountName() {
		return( requiredJEEMountName );
	}

	public void setRequiredJEEMountName( String value ) {
		if( value == null ) {
			throw new CFLibNullArgumentException( getClass(),
				"setRequiredJEEMountName",
				1,
				"value" );
		}
		if( value.length() > 192 ) {
			throw new CFLibArgumentOverflowException( getClass(),
				"setRequiredJEEMountName",
				1,
				"value.length()",
				value.length(),
				192 );
		}
		requiredJEEMountName = value;
	}

	public boolean equals( Object obj ) {
		if( obj == null ) {
			return( false );
		}
		else if( obj instanceof CFSecSecAppByUJEEMountIdxKey ) {
			CFSecSecAppByUJEEMountIdxKey rhs = (CFSecSecAppByUJEEMountIdxKey)obj;
			if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
				return( false );
			}
			if( ! getRequiredJEEMountName().equals( rhs.getRequiredJEEMountName() ) ) {
				return( false );
			}
			return( true );
		}
		else if( obj instanceof CFSecSecAppBuff ) {
			CFSecSecAppBuff rhs = (CFSecSecAppBuff)obj;
			if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
				return( false );
			}
			if( ! getRequiredJEEMountName().equals( rhs.getRequiredJEEMountName() ) ) {
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
		hashCode = hashCode + (int)( getRequiredClusterId() );
		if( getRequiredJEEMountName() != null ) {
			hashCode = hashCode + getRequiredJEEMountName().hashCode();
		}
		return( hashCode & 0x7fffffff );
	}

	public int compareTo( Object obj ) {
		if( obj == null ) {
			return( 1 );
		}
		else if( obj instanceof CFSecSecAppByUJEEMountIdxKey ) {
			CFSecSecAppByUJEEMountIdxKey rhs = (CFSecSecAppByUJEEMountIdxKey)obj;
			if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
				return( -1 );
			}
			else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
				return( 1 );
			}
			{
				int cmp = getRequiredJEEMountName().compareTo( rhs.getRequiredJEEMountName() );
				if( cmp != 0 ) {
					return( cmp );
				}
			}
			return( 0 );
		}
		else if( obj instanceof CFSecSecAppBuff ) {
			CFSecSecAppBuff rhs = (CFSecSecAppBuff)obj;
			if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
				return( -1 );
			}
			else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
				return( 1 );
			}
			{
				int cmp = getRequiredJEEMountName().compareTo( rhs.getRequiredJEEMountName() );
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
		String ret = "<CFSecSecAppByUJEEMountIdx"
			+ " RequiredClusterId=" + "\"" + Long.toString( getRequiredClusterId() ) + "\""
			+ " RequiredJEEMountName=" + "\"" + CFSecSchema.xmlEncodeString( getRequiredJEEMountName() ) + "\""
			+ "/>";
		return( ret );
	}
}
