// Description: Java 11 implementation of a SecUser by EMConfIdx index key object.

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
import org.msscf.msscf.cflib.CFLib.*;

public class CFSecSecUserByEMConfIdxKey
	implements Comparable<Object>,
		Serializable
{
	protected UUID optionalEMailConfirmUuid;
	public CFSecSecUserByEMConfIdxKey() {
		optionalEMailConfirmUuid = null;
	}

	public UUID getOptionalEMailConfirmUuid() {
		return( optionalEMailConfirmUuid );
	}

	public void setOptionalEMailConfirmUuid( UUID value ) {
		if( value == null ) {
			optionalEMailConfirmUuid = null;
		}
		else {
			optionalEMailConfirmUuid = value;
		}
	}

	public boolean equals( Object obj ) {
		if( obj == null ) {
			return( false );
		}
		else if( obj instanceof CFSecSecUserByEMConfIdxKey ) {
			CFSecSecUserByEMConfIdxKey rhs = (CFSecSecUserByEMConfIdxKey)obj;
			if( getOptionalEMailConfirmUuid() != null ) {
				if( rhs.getOptionalEMailConfirmUuid() != null ) {
					if( ! getOptionalEMailConfirmUuid().equals( rhs.getOptionalEMailConfirmUuid() ) ) {
						return( false );
					}
				}
			}
			else {
				if( rhs.getOptionalEMailConfirmUuid() != null ) {
					return( false );
				}
			}
			return( true );
		}
		else if( obj instanceof CFSecSecUserBuff ) {
			CFSecSecUserBuff rhs = (CFSecSecUserBuff)obj;
			if( getOptionalEMailConfirmUuid() != null ) {
				if( rhs.getOptionalEMailConfirmUuid() != null ) {
					if( ! getOptionalEMailConfirmUuid().equals( rhs.getOptionalEMailConfirmUuid() ) ) {
						return( false );
					}
				}
			}
			else {
				if( rhs.getOptionalEMailConfirmUuid() != null ) {
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
		if( getOptionalEMailConfirmUuid() != null ) {
			hashCode = hashCode + getOptionalEMailConfirmUuid().hashCode();
		}
		return( hashCode & 0x7fffffff );
	}

	public int compareTo( Object obj ) {
		if( obj == null ) {
			return( 1 );
		}
		else if( obj instanceof CFSecSecUserByEMConfIdxKey ) {
			CFSecSecUserByEMConfIdxKey rhs = (CFSecSecUserByEMConfIdxKey)obj;
			if( getOptionalEMailConfirmUuid() != null ) {
				if( rhs.getOptionalEMailConfirmUuid() != null ) {
					int cmp = getOptionalEMailConfirmUuid().compareTo( rhs.getOptionalEMailConfirmUuid() );
					if( cmp != 0 ) {
						return( cmp );
					}
				}
				else {
					return( 1 );
				}
			}
			else {
				if( rhs.getOptionalEMailConfirmUuid() != null ) {
					return( -1 );
				}
			}
			return( 0 );
		}
		else if( obj instanceof CFSecSecUserBuff ) {
			CFSecSecUserBuff rhs = (CFSecSecUserBuff)obj;
			if( getOptionalEMailConfirmUuid() != null ) {
				if( rhs.getOptionalEMailConfirmUuid() != null ) {
					int cmp = getOptionalEMailConfirmUuid().compareTo( rhs.getOptionalEMailConfirmUuid() );
					if( cmp != 0 ) {
						return( cmp );
					}
				}
				else {
					return( 1 );
				}
			}
			else {
				if( rhs.getOptionalEMailConfirmUuid() != null ) {
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
		String ret = "<CFSecSecUserByEMConfIdx"
			+ " OptionalEMailConfirmUuid=" + ( ( getOptionalEMailConfirmUuid() == null ) ? "null" : "\"" + getOptionalEMailConfirmUuid().toString() + "\"" )
			+ "/>";
		return( ret );
	}
}
