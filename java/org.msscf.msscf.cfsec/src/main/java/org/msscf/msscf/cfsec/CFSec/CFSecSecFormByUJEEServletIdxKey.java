// Description: Java 11 implementation of a SecForm by UJEEServletIdx index key object.

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

public class CFSecSecFormByUJEEServletIdxKey
	implements Comparable<Object>,
		Serializable
{
	protected long requiredClusterId;
	protected int requiredSecAppId;
	protected String requiredJEEServletMapName;
	public CFSecSecFormByUJEEServletIdxKey() {
		requiredClusterId = CFSecSecFormBuff.CLUSTERID_INIT_VALUE;
		requiredSecAppId = CFSecSecFormBuff.SECAPPID_INIT_VALUE;
		requiredJEEServletMapName = new String( CFSecSecFormBuff.JEESERVLETMAPNAME_INIT_VALUE );
	}

	public long getRequiredClusterId() {
		return( requiredClusterId );
	}

	public void setRequiredClusterId( long value ) {
		if( value < CFSecSecFormBuff.CLUSTERID_MIN_VALUE ) {
			throw new CFLibArgumentUnderflowException( getClass(),
				"setRequiredClusterId",
				1,
				"value",
				value,
				CFSecSecFormBuff.CLUSTERID_MIN_VALUE );
		}
		requiredClusterId = value;
	}

	public int getRequiredSecAppId() {
		return( requiredSecAppId );
	}

	public void setRequiredSecAppId( int value ) {
		if( value < CFSecSecFormBuff.SECAPPID_MIN_VALUE ) {
			throw new CFLibArgumentUnderflowException( getClass(),
				"setRequiredSecAppId",
				1,
				"value",
				value,
				CFSecSecFormBuff.SECAPPID_MIN_VALUE );
		}
		requiredSecAppId = value;
	}

	public String getRequiredJEEServletMapName() {
		return( requiredJEEServletMapName );
	}

	public void setRequiredJEEServletMapName( String value ) {
		if( value == null ) {
			throw new CFLibNullArgumentException( getClass(),
				"setRequiredJEEServletMapName",
				1,
				"value" );
		}
		if( value.length() > 192 ) {
			throw new CFLibArgumentOverflowException( getClass(),
				"setRequiredJEEServletMapName",
				1,
				"value.length()",
				value.length(),
				192 );
		}
		requiredJEEServletMapName = value;
	}

	public boolean equals( Object obj ) {
		if( obj == null ) {
			return( false );
		}
		else if( obj instanceof CFSecSecFormByUJEEServletIdxKey ) {
			CFSecSecFormByUJEEServletIdxKey rhs = (CFSecSecFormByUJEEServletIdxKey)obj;
			if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
				return( false );
			}
			if( getRequiredSecAppId() != rhs.getRequiredSecAppId() ) {
				return( false );
			}
			if( ! getRequiredJEEServletMapName().equals( rhs.getRequiredJEEServletMapName() ) ) {
				return( false );
			}
			return( true );
		}
		else if( obj instanceof CFSecSecFormBuff ) {
			CFSecSecFormBuff rhs = (CFSecSecFormBuff)obj;
			if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
				return( false );
			}
			if( getRequiredSecAppId() != rhs.getRequiredSecAppId() ) {
				return( false );
			}
			if( ! getRequiredJEEServletMapName().equals( rhs.getRequiredJEEServletMapName() ) ) {
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
		hashCode = hashCode + getRequiredSecAppId();
		if( getRequiredJEEServletMapName() != null ) {
			hashCode = hashCode + getRequiredJEEServletMapName().hashCode();
		}
		return( hashCode & 0x7fffffff );
	}

	public int compareTo( Object obj ) {
		if( obj == null ) {
			return( 1 );
		}
		else if( obj instanceof CFSecSecFormByUJEEServletIdxKey ) {
			CFSecSecFormByUJEEServletIdxKey rhs = (CFSecSecFormByUJEEServletIdxKey)obj;
			if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
				return( -1 );
			}
			else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
				return( 1 );
			}
			if( getRequiredSecAppId() < rhs.getRequiredSecAppId() ) {
				return( -1 );
			}
			else if( getRequiredSecAppId() > rhs.getRequiredSecAppId() ) {
				return( 1 );
			}
			{
				int cmp = getRequiredJEEServletMapName().compareTo( rhs.getRequiredJEEServletMapName() );
				if( cmp != 0 ) {
					return( cmp );
				}
			}
			return( 0 );
		}
		else if( obj instanceof CFSecSecFormBuff ) {
			CFSecSecFormBuff rhs = (CFSecSecFormBuff)obj;
			if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
				return( -1 );
			}
			else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
				return( 1 );
			}
			if( getRequiredSecAppId() < rhs.getRequiredSecAppId() ) {
				return( -1 );
			}
			else if( getRequiredSecAppId() > rhs.getRequiredSecAppId() ) {
				return( 1 );
			}
			{
				int cmp = getRequiredJEEServletMapName().compareTo( rhs.getRequiredJEEServletMapName() );
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
		String ret = "<CFSecSecFormByUJEEServletIdx"
			+ " RequiredClusterId=" + "\"" + Long.toString( getRequiredClusterId() ) + "\""
			+ " RequiredSecAppId=" + "\"" + Integer.toString( getRequiredSecAppId() ) + "\""
			+ " RequiredJEEServletMapName=" + "\"" + CFSecSchema.xmlEncodeString( getRequiredJEEServletMapName() ) + "\""
			+ "/>";
		return( ret );
	}
}
