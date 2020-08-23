// Description: Java 11 implementation of a SecGroup by ClusterVisIdx index key object.

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

public class CFSecSecGroupByClusterVisIdxKey
	implements Comparable<Object>,
		Serializable
{
	protected long requiredClusterId;
	protected boolean requiredIsVisible;
	public CFSecSecGroupByClusterVisIdxKey() {
		requiredClusterId = CFSecSecGroupBuff.CLUSTERID_INIT_VALUE;
		requiredIsVisible = CFSecSecGroupBuff.ISVISIBLE_INIT_VALUE;
	}

	public long getRequiredClusterId() {
		return( requiredClusterId );
	}

	public void setRequiredClusterId( long value ) {
		if( value < CFSecSecGroupBuff.CLUSTERID_MIN_VALUE ) {
			throw new CFLibArgumentUnderflowException( getClass(),
				"setRequiredClusterId",
				1,
				"value",
				value,
				CFSecSecGroupBuff.CLUSTERID_MIN_VALUE );
		}
		requiredClusterId = value;
	}

	public boolean getRequiredIsVisible() {
		return( requiredIsVisible );
	}

	public void setRequiredIsVisible( boolean value ) {
		requiredIsVisible = value;
	}

	public boolean equals( Object obj ) {
		if( obj == null ) {
			return( false );
		}
		else if( obj instanceof CFSecSecGroupByClusterVisIdxKey ) {
			CFSecSecGroupByClusterVisIdxKey rhs = (CFSecSecGroupByClusterVisIdxKey)obj;
			if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
				return( false );
			}
			if( getRequiredIsVisible() != rhs.getRequiredIsVisible() ) {
				return( false );
			}
			return( true );
		}
		else if( obj instanceof CFSecSecGroupBuff ) {
			CFSecSecGroupBuff rhs = (CFSecSecGroupBuff)obj;
			if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
				return( false );
			}
			if( getRequiredIsVisible() != rhs.getRequiredIsVisible() ) {
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
		if( getRequiredIsVisible() ) {
			hashCode = ( hashCode * 2 ) + 1;
		}
		else {
			hashCode = hashCode * 2;
		}
		return( hashCode & 0x7fffffff );
	}

	public int compareTo( Object obj ) {
		if( obj == null ) {
			return( 1 );
		}
		else if( obj instanceof CFSecSecGroupByClusterVisIdxKey ) {
			CFSecSecGroupByClusterVisIdxKey rhs = (CFSecSecGroupByClusterVisIdxKey)obj;
			if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
				return( -1 );
			}
			else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
				return( 1 );
			}
			if( getRequiredIsVisible() ) {
				if( ! rhs.getRequiredIsVisible() ) {
					return( 1 );
				}
			}
			else {
				if( rhs.getRequiredIsVisible() ) {
					return( -1 );
				}
			}
			return( 0 );
		}
		else if( obj instanceof CFSecSecGroupBuff ) {
			CFSecSecGroupBuff rhs = (CFSecSecGroupBuff)obj;
			if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
				return( -1 );
			}
			else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
				return( 1 );
			}
			if( getRequiredIsVisible() ) {
				if( ! rhs.getRequiredIsVisible() ) {
					return( 1 );
				}
			}
			else {
				if( rhs.getRequiredIsVisible() ) {
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
		String ret = "<CFSecSecGroupByClusterVisIdx"
			+ " RequiredClusterId=" + "\"" + Long.toString( getRequiredClusterId() ) + "\""
			+ " RequiredIsVisible=" + (( getRequiredIsVisible() ) ? "\"true\"" : "\"false\"" )
			+ "/>";
		return( ret );
	}
}
