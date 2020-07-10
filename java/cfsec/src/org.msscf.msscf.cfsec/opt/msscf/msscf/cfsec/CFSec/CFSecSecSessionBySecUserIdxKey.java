// Description: Java 11 implementation of a SecSession by SecUserIdx index key object.

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

public class CFSecSecSessionBySecUserIdxKey
	implements Comparable<Object>,
		Serializable
{
	protected UUID requiredSecUserId;
	public CFSecSecSessionBySecUserIdxKey() {
		requiredSecUserId = UUID.fromString( CFSecSecSessionBuff.SECUSERID_INIT_VALUE.toString() );
	}

	public UUID getRequiredSecUserId() {
		return( requiredSecUserId );
	}

	public void setRequiredSecUserId( UUID value ) {
		if( value == null ) {
			throw new CFLibNullArgumentException( getClass(),
				"setRequiredSecUserId",
				1,
				"value" );
		}
		requiredSecUserId = value;
	}

	public boolean equals( Object obj ) {
		if( obj == null ) {
			return( false );
		}
		else if( obj instanceof CFSecSecSessionBySecUserIdxKey ) {
			CFSecSecSessionBySecUserIdxKey rhs = (CFSecSecSessionBySecUserIdxKey)obj;
			if( ! getRequiredSecUserId().equals( rhs.getRequiredSecUserId() ) ) {
				return( false );
			}
			return( true );
		}
		else if( obj instanceof CFSecSecSessionBuff ) {
			CFSecSecSessionBuff rhs = (CFSecSecSessionBuff)obj;
			if( ! getRequiredSecUserId().equals( rhs.getRequiredSecUserId() ) ) {
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
		hashCode = hashCode + getRequiredSecUserId().hashCode();
		return( hashCode & 0x7fffffff );
	}

	public int compareTo( Object obj ) {
		if( obj == null ) {
			return( 1 );
		}
		else if( obj instanceof CFSecSecSessionBySecUserIdxKey ) {
			CFSecSecSessionBySecUserIdxKey rhs = (CFSecSecSessionBySecUserIdxKey)obj;
			{
				int cmp = getRequiredSecUserId().compareTo( rhs.getRequiredSecUserId() );
				if( cmp != 0 ) {
					return( cmp );
				}
			}
			return( 0 );
		}
		else if( obj instanceof CFSecSecSessionBuff ) {
			CFSecSecSessionBuff rhs = (CFSecSecSessionBuff)obj;
			{
				int cmp = getRequiredSecUserId().compareTo( rhs.getRequiredSecUserId() );
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
		String ret = "<CFSecSecSessionBySecUserIdx"
			+ " RequiredSecUserId=" + "\"" + getRequiredSecUserId().toString() + "\""
			+ "/>";
		return( ret );
	}
}
