// Description: Java 11 implementation of a SecUser by PwdResetIdx index key object.

/*
 *	org.msscf.msscf.CFSec
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

package org.msscf.msscf.cfsec.CFSec;

import java.lang.reflect.*;
import java.io.*;
import java.math.*;
import java.net.*;
import java.rmi.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import com.github.msobkow.cflib.CFLib.*;

public class CFSecSecUserByPwdResetIdxKey
	implements Comparable<Object>,
		Serializable
{
	protected UUID optionalPasswordResetUuid;
	public CFSecSecUserByPwdResetIdxKey() {
		optionalPasswordResetUuid = null;
	}

	public UUID getOptionalPasswordResetUuid() {
		return( optionalPasswordResetUuid );
	}

	public void setOptionalPasswordResetUuid( UUID value ) {
		if( value == null ) {
			optionalPasswordResetUuid = null;
		}
		else {
			optionalPasswordResetUuid = value;
		}
	}

	public boolean equals( Object obj ) {
		if( obj == null ) {
			return( false );
		}
		else if( obj instanceof CFSecSecUserByPwdResetIdxKey ) {
			CFSecSecUserByPwdResetIdxKey rhs = (CFSecSecUserByPwdResetIdxKey)obj;
			if( getOptionalPasswordResetUuid() != null ) {
				if( rhs.getOptionalPasswordResetUuid() != null ) {
					if( ! getOptionalPasswordResetUuid().equals( rhs.getOptionalPasswordResetUuid() ) ) {
						return( false );
					}
				}
			}
			else {
				if( rhs.getOptionalPasswordResetUuid() != null ) {
					return( false );
				}
			}
			return( true );
		}
		else if( obj instanceof CFSecSecUserBuff ) {
			CFSecSecUserBuff rhs = (CFSecSecUserBuff)obj;
			if( getOptionalPasswordResetUuid() != null ) {
				if( rhs.getOptionalPasswordResetUuid() != null ) {
					if( ! getOptionalPasswordResetUuid().equals( rhs.getOptionalPasswordResetUuid() ) ) {
						return( false );
					}
				}
			}
			else {
				if( rhs.getOptionalPasswordResetUuid() != null ) {
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
		if( getOptionalPasswordResetUuid() != null ) {
			hashCode = hashCode + getOptionalPasswordResetUuid().hashCode();
		}
		return( hashCode & 0x7fffffff );
	}

	public int compareTo( Object obj ) {
		if( obj == null ) {
			return( 1 );
		}
		else if( obj instanceof CFSecSecUserByPwdResetIdxKey ) {
			CFSecSecUserByPwdResetIdxKey rhs = (CFSecSecUserByPwdResetIdxKey)obj;
			if( getOptionalPasswordResetUuid() != null ) {
				if( rhs.getOptionalPasswordResetUuid() != null ) {
					int cmp = getOptionalPasswordResetUuid().compareTo( rhs.getOptionalPasswordResetUuid() );
					if( cmp != 0 ) {
						return( cmp );
					}
				}
				else {
					return( 1 );
				}
			}
			else {
				if( rhs.getOptionalPasswordResetUuid() != null ) {
					return( -1 );
				}
			}
			return( 0 );
		}
		else if( obj instanceof CFSecSecUserBuff ) {
			CFSecSecUserBuff rhs = (CFSecSecUserBuff)obj;
			if( getOptionalPasswordResetUuid() != null ) {
				if( rhs.getOptionalPasswordResetUuid() != null ) {
					int cmp = getOptionalPasswordResetUuid().compareTo( rhs.getOptionalPasswordResetUuid() );
					if( cmp != 0 ) {
						return( cmp );
					}
				}
				else {
					return( 1 );
				}
			}
			else {
				if( rhs.getOptionalPasswordResetUuid() != null ) {
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
		String ret = "<CFSecSecUserByPwdResetIdx"
			+ " OptionalPasswordResetUuid=" + ( ( getOptionalPasswordResetUuid() == null ) ? "null" : "\"" + getOptionalPasswordResetUuid().toString() + "\"" )
			+ "/>";
		return( ret );
	}
}
