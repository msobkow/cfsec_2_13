// Description: Java 11 implementation of a SecSession primary key object.

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
import org.apache.commons.codec.binary.Base64;

/*
 *	CFSecSecSessionPKey Primary Key for SecSession

 *		requiredSecSessionId	Required object attribute SecSessionId. */
public class CFSecSecSessionPKey
	implements Comparable<Object>,
		Serializable
{

	protected UUID requiredSecSessionId;
	public CFSecSecSessionPKey() {
		requiredSecSessionId = UUID.fromString( CFSecSecSessionBuff.SECSESSIONID_INIT_VALUE.toString() );
	}

	public UUID getRequiredSecSessionId() {
		return( requiredSecSessionId );
	}

	public void setRequiredSecSessionId( UUID value ) {
		if( value == null ) {
			throw new CFLibNullArgumentException( getClass(),
				"setRequiredSecSessionId",
				1,
				"value" );
		}
		requiredSecSessionId = value;
	}

	public boolean equals( Object obj ) {
		if( obj == null ) {
			return( false );
		}
		else if( obj instanceof CFSecSecSessionHPKey ) {
			CFSecSecSessionHPKey rhs = (CFSecSecSessionHPKey)obj;
			if( ! getRequiredSecSessionId().equals( rhs.getRequiredSecSessionId() ) ) {
				return( false );
			}
			return( true );
		}
		else if( obj instanceof CFSecSecSessionPKey ) {
			CFSecSecSessionPKey rhs = (CFSecSecSessionPKey)obj;
			if( ! getRequiredSecSessionId().equals( rhs.getRequiredSecSessionId() ) ) {
				return( false );
			}
			return( true );
		}
		else if( obj instanceof CFSecSecSessionHBuff ) {
			CFSecSecSessionHBuff rhs = (CFSecSecSessionHBuff)obj;
			if( ! getRequiredSecSessionId().equals( rhs.getRequiredSecSessionId() ) ) {
				return( false );
			}
			return( true );
		}
		else if( obj instanceof CFSecSecSessionBuff ) {
			CFSecSecSessionBuff rhs = (CFSecSecSessionBuff)obj;
			if( ! getRequiredSecSessionId().equals( rhs.getRequiredSecSessionId() ) ) {
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
		hashCode = hashCode + getRequiredSecSessionId().hashCode();
		return( hashCode & 0x7fffffff );
	}

	public int compareTo( Object obj ) {
		if( obj == null ) {
			return( -1 );
		}
		else if( obj instanceof CFSecSecSessionHPKey ) {
			CFSecSecSessionHPKey rhs = (CFSecSecSessionHPKey)obj;
			{
				int cmp = getRequiredSecSessionId().compareTo( rhs.getRequiredSecSessionId() );
				if( cmp != 0 ) {
					return( cmp );
				}
			}
			return( 0 );
		}
		else if( obj instanceof CFSecSecSessionPKey ) {
			CFSecSecSessionPKey rhs = (CFSecSecSessionPKey)obj;
			{
				int cmp = getRequiredSecSessionId().compareTo( rhs.getRequiredSecSessionId() );
				if( cmp != 0 ) {
					return( cmp );
				}
			}
			return( 0 );
		}
		else if( obj instanceof CFSecSecSessionBuff ) {
			CFSecSecSessionBuff rhs = (CFSecSecSessionBuff)obj;
			{
				int cmp = getRequiredSecSessionId().compareTo( rhs.getRequiredSecSessionId() );
				if( cmp != 0 ) {
					return( cmp );
				}
			}
			return( 0 );
		}
		else if( obj instanceof CFSecSecSessionHBuff ) {
			CFSecSecSessionHBuff rhs = (CFSecSecSessionHBuff)obj;
			{
				int cmp = getRequiredSecSessionId().compareTo( rhs.getRequiredSecSessionId() );
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
				"CFSecSecSessionPKey, CFSecSecSessionBuff" );
		}
	}

	public String toString() {
		String ret = "<CFSecSecSessionPKey"
			+ " RequiredSecSessionId=" + "\"" + getRequiredSecSessionId().toString() + "\""
			+ "/>";
		return( ret );
	}
}
