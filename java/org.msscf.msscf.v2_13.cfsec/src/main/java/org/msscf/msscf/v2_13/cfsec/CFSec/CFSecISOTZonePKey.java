// Description: Java 11 implementation of a ISOTZone primary key object.

/*
 *	org.msscf.msscf.CFSec
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFSec 2.13 Security Essentials
 *	
 *	Copyright 2020 Mark Stephen Sobkow msobkow@sasktel.net
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
import org.apache.commons.codec.binary.Base64;

/*
 *	CFSecISOTZonePKey Primary Key for ISOTZone

 *		requiredISOTZoneId	Required object attribute ISOTZoneId. */
public class CFSecISOTZonePKey
	implements Comparable<Object>,
		Serializable
{

	protected short requiredISOTZoneId;
	public CFSecISOTZonePKey() {
		requiredISOTZoneId = CFSecISOTZoneBuff.ISOTZONEID_INIT_VALUE;
	}

	public short getRequiredISOTZoneId() {
		return( requiredISOTZoneId );
	}

	public void setRequiredISOTZoneId( short value ) {
		if( value < CFSecISOTZoneBuff.ISOTZONEID_MIN_VALUE ) {
			throw new CFLibArgumentUnderflowException( getClass(),
				"setRequiredISOTZoneId",
				1,
				"value",
				value,
				CFSecISOTZoneBuff.ISOTZONEID_MIN_VALUE );
		}
		requiredISOTZoneId = value;
	}

	public boolean equals( Object obj ) {
		if( obj == null ) {
			return( false );
		}
		else if( obj instanceof CFSecISOTZoneHPKey ) {
			CFSecISOTZoneHPKey rhs = (CFSecISOTZoneHPKey)obj;
			if( getRequiredISOTZoneId() != rhs.getRequiredISOTZoneId() ) {
				return( false );
			}
			return( true );
		}
		else if( obj instanceof CFSecISOTZonePKey ) {
			CFSecISOTZonePKey rhs = (CFSecISOTZonePKey)obj;
			if( getRequiredISOTZoneId() != rhs.getRequiredISOTZoneId() ) {
				return( false );
			}
			return( true );
		}
		else if( obj instanceof CFSecISOTZoneHBuff ) {
			CFSecISOTZoneHBuff rhs = (CFSecISOTZoneHBuff)obj;
			if( getRequiredISOTZoneId() != rhs.getRequiredISOTZoneId() ) {
				return( false );
			}
			return( true );
		}
		else if( obj instanceof CFSecISOTZoneBuff ) {
			CFSecISOTZoneBuff rhs = (CFSecISOTZoneBuff)obj;
			if( getRequiredISOTZoneId() != rhs.getRequiredISOTZoneId() ) {
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
		hashCode = ( hashCode * 0x10000 ) + getRequiredISOTZoneId();
		return( hashCode & 0x7fffffff );
	}

	public int compareTo( Object obj ) {
		if( obj == null ) {
			return( -1 );
		}
		else if( obj instanceof CFSecISOTZoneHPKey ) {
			CFSecISOTZoneHPKey rhs = (CFSecISOTZoneHPKey)obj;
			if( getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
				return( -1 );
			}
			else if( getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
				return( 1 );
			}
			return( 0 );
		}
		else if( obj instanceof CFSecISOTZonePKey ) {
			CFSecISOTZonePKey rhs = (CFSecISOTZonePKey)obj;
			if( getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
				return( -1 );
			}
			else if( getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
				return( 1 );
			}
			return( 0 );
		}
		else if( obj instanceof CFSecISOTZoneBuff ) {
			CFSecISOTZoneBuff rhs = (CFSecISOTZoneBuff)obj;
			if( getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
				return( -1 );
			}
			else if( getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
				return( 1 );
			}
			return( 0 );
		}
		else if( obj instanceof CFSecISOTZoneHBuff ) {
			CFSecISOTZoneHBuff rhs = (CFSecISOTZoneHBuff)obj;
			if( getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
				return( -1 );
			}
			else if( getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
				return( 1 );
			}
			return( 0 );
		}
		else {
			throw new CFLibUnsupportedClassException( getClass(),
				"compareTo",
				"obj",
				obj,
				"CFSecISOTZonePKey, CFSecISOTZoneBuff" );
		}
	}

	public String toString() {
		String ret = "<CFSecISOTZonePKey"
			+ " RequiredISOTZoneId=" + "\"" + Short.toString( getRequiredISOTZoneId() ) + "\""
			+ "/>";
		return( ret );
	}
}
