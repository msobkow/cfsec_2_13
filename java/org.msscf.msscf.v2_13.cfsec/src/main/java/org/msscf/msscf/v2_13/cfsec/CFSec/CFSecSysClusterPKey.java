// Description: Java 11 implementation of a SysCluster primary key object.

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
 *	CFSecSysClusterPKey Primary Key for SysCluster

 *		requiredSingletonId	Required object attribute SingletonId. */
public class CFSecSysClusterPKey
	implements Comparable<Object>,
		Serializable
{

	protected int requiredSingletonId;
	public CFSecSysClusterPKey() {
		requiredSingletonId = CFSecSysClusterBuff.SINGLETONID_INIT_VALUE;
	}

	public int getRequiredSingletonId() {
		return( requiredSingletonId );
	}

	public void setRequiredSingletonId( int value ) {
		if( value < CFSecSysClusterBuff.SINGLETONID_MIN_VALUE ) {
			throw new CFLibArgumentUnderflowException( getClass(),
				"setRequiredSingletonId",
				1,
				"value",
				value,
				CFSecSysClusterBuff.SINGLETONID_MIN_VALUE );
		}
		if( value > CFSecSysClusterBuff.SINGLETONID_MAX_VALUE ) {
			throw new CFLibArgumentOverflowException( getClass(),
				"setRequiredSingletonId",
				1,
				"value",
				value,
				CFSecSysClusterBuff.SINGLETONID_MAX_VALUE );
		}
		requiredSingletonId = value;
	}

	public boolean equals( Object obj ) {
		if( obj == null ) {
			return( false );
		}
		else if( obj instanceof CFSecSysClusterHPKey ) {
			CFSecSysClusterHPKey rhs = (CFSecSysClusterHPKey)obj;
			if( getRequiredSingletonId() != rhs.getRequiredSingletonId() ) {
				return( false );
			}
			return( true );
		}
		else if( obj instanceof CFSecSysClusterPKey ) {
			CFSecSysClusterPKey rhs = (CFSecSysClusterPKey)obj;
			if( getRequiredSingletonId() != rhs.getRequiredSingletonId() ) {
				return( false );
			}
			return( true );
		}
		else if( obj instanceof CFSecSysClusterHBuff ) {
			CFSecSysClusterHBuff rhs = (CFSecSysClusterHBuff)obj;
			if( getRequiredSingletonId() != rhs.getRequiredSingletonId() ) {
				return( false );
			}
			return( true );
		}
		else if( obj instanceof CFSecSysClusterBuff ) {
			CFSecSysClusterBuff rhs = (CFSecSysClusterBuff)obj;
			if( getRequiredSingletonId() != rhs.getRequiredSingletonId() ) {
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
		hashCode = hashCode + getRequiredSingletonId();
		return( hashCode & 0x7fffffff );
	}

	public int compareTo( Object obj ) {
		if( obj == null ) {
			return( -1 );
		}
		else if( obj instanceof CFSecSysClusterHPKey ) {
			CFSecSysClusterHPKey rhs = (CFSecSysClusterHPKey)obj;
			if( getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
				return( -1 );
			}
			else if( getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
				return( 1 );
			}
			return( 0 );
		}
		else if( obj instanceof CFSecSysClusterPKey ) {
			CFSecSysClusterPKey rhs = (CFSecSysClusterPKey)obj;
			if( getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
				return( -1 );
			}
			else if( getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
				return( 1 );
			}
			return( 0 );
		}
		else if( obj instanceof CFSecSysClusterBuff ) {
			CFSecSysClusterBuff rhs = (CFSecSysClusterBuff)obj;
			if( getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
				return( -1 );
			}
			else if( getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
				return( 1 );
			}
			return( 0 );
		}
		else if( obj instanceof CFSecSysClusterHBuff ) {
			CFSecSysClusterHBuff rhs = (CFSecSysClusterHBuff)obj;
			if( getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
				return( -1 );
			}
			else if( getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
				return( 1 );
			}
			return( 0 );
		}
		else {
			throw new CFLibUnsupportedClassException( getClass(),
				"compareTo",
				"obj",
				obj,
				"CFSecSysClusterPKey, CFSecSysClusterBuff" );
		}
	}

	public String toString() {
		String ret = "<CFSecSysClusterPKey"
			+ " RequiredSingletonId=" + "\"" + Integer.toString( getRequiredSingletonId() ) + "\""
			+ "/>";
		return( ret );
	}
}
