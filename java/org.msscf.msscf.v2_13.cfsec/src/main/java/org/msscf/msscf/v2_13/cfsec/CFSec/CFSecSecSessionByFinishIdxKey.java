// Description: Java 11 implementation of a SecSession by FinishIdx index key object.

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

public class CFSecSecSessionByFinishIdxKey
	implements Comparable<Object>,
		Serializable
{
	protected UUID requiredSecUserId;
	protected Calendar optionalFinish;
	public CFSecSecSessionByFinishIdxKey() {
		requiredSecUserId = UUID.fromString( CFSecSecSessionBuff.SECUSERID_INIT_VALUE.toString() );
		optionalFinish = null;
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

	public Calendar getOptionalFinish() {
		return( optionalFinish );
	}

	public void setOptionalFinish( Calendar value ) {
		if( value == null ) {
			optionalFinish = null;
		}
		else {
			optionalFinish = value;
		}
	}

	public boolean equals( Object obj ) {
		if( obj == null ) {
			return( false );
		}
		else if( obj instanceof CFSecSecSessionByFinishIdxKey ) {
			CFSecSecSessionByFinishIdxKey rhs = (CFSecSecSessionByFinishIdxKey)obj;
			if( ! getRequiredSecUserId().equals( rhs.getRequiredSecUserId() ) ) {
				return( false );
			}
			if( getOptionalFinish() != null ) {
				if( rhs.getOptionalFinish() != null ) {
					if( ! getOptionalFinish().equals( rhs.getOptionalFinish() ) ) {
						return( false );
					}
				}
			}
			else {
				if( rhs.getOptionalFinish() != null ) {
					return( false );
				}
			}
			return( true );
		}
		else if( obj instanceof CFSecSecSessionBuff ) {
			CFSecSecSessionBuff rhs = (CFSecSecSessionBuff)obj;
			if( ! getRequiredSecUserId().equals( rhs.getRequiredSecUserId() ) ) {
				return( false );
			}
			if( getOptionalFinish() != null ) {
				if( rhs.getOptionalFinish() != null ) {
					if( ! getOptionalFinish().equals( rhs.getOptionalFinish() ) ) {
						return( false );
					}
				}
			}
			else {
				if( rhs.getOptionalFinish() != null ) {
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
		hashCode = hashCode + getRequiredSecUserId().hashCode();
		if( getOptionalFinish() != null ) {
			hashCode = hashCode + getOptionalFinish().hashCode();
		}
		return( hashCode & 0x7fffffff );
	}

	public int compareTo( Object obj ) {
		if( obj == null ) {
			return( 1 );
		}
		else if( obj instanceof CFSecSecSessionByFinishIdxKey ) {
			CFSecSecSessionByFinishIdxKey rhs = (CFSecSecSessionByFinishIdxKey)obj;
			{
				int cmp = getRequiredSecUserId().compareTo( rhs.getRequiredSecUserId() );
				if( cmp != 0 ) {
					return( cmp );
				}
			}
			if( getOptionalFinish() != null ) {
				if( rhs.getOptionalFinish() != null ) {
					int cmp = getOptionalFinish().compareTo( rhs.getOptionalFinish() );
					if( cmp != 0 ) {
						return( cmp );
					}
				}
				else {
					return( 1 );
				}
			}
			else {
				if( rhs.getOptionalFinish() != null ) {
					return( -1 );
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
			if( getOptionalFinish() != null ) {
				if( rhs.getOptionalFinish() != null ) {
					int cmp = getOptionalFinish().compareTo( rhs.getOptionalFinish() );
					if( cmp != 0 ) {
						return( cmp );
					}
				}
				else {
					return( 1 );
				}
			}
			else {
				if( rhs.getOptionalFinish() != null ) {
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
		String ret = "<CFSecSecSessionByFinishIdx"
			+ " RequiredSecUserId=" + "\"" + getRequiredSecUserId().toString() + "\""
			+ " OptionalFinish=" + ( ( getOptionalFinish() == null ) ? "null" : "\"" + getOptionalFinish().toString() + "\"" )
			+ "/>";
		return( ret );
	}
}
