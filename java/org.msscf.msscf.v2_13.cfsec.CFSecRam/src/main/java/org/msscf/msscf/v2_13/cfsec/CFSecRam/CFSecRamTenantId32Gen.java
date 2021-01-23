// Description: Java 11 implementation of a Tenant 32-bit RAM Id Generator object.

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

package org.msscf.msscf.v2_13.cfsec.CFSecRam;

import java.lang.reflect.*;
import java.io.*;
import java.math.*;
import java.net.*;
import java.rmi.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.apache.commons.codec.binary.Base64;
import org.msscf.msscf.v2_13.cflib.CFLib.*;
import org.msscf.msscf.v2_13.cfsec.CFSec.*;

/*
 *	CFSecRamTenantId32Gen RAM 32-bit Id Generator for Tenant
 */
public class CFSecRamTenantId32Gen
	implements Comparable<Object>,
		Serializable
{

	protected long requiredId;
	protected short sliceId = 0;
	protected int nextId = 1;

	public CFSecRamTenantId32Gen() {
		requiredId = CFSecTenantBuff.ID_INIT_VALUE;
		sliceId = 0;
		nextId = 1;
	}

	public int getNextId() {
		int retNext = nextId ++;
		return( retNext );
	}

	public long getRequiredId() {
		return( requiredId );
	}

	public void setRequiredId( long value ) {
		if( value < CFSecTenantBuff.ID_MIN_VALUE ) {
			throw new CFLibArgumentUnderflowException( getClass(),
				"setRequiredId",
				1,
				"value",
				value,
				CFSecTenantBuff.ID_MIN_VALUE );
		}
		requiredId = value;
	}

	public short getRequiredSliceId() {
		return( sliceId );
	}

	public void setRequiredSliceId( short value ) {
		sliceId = value;
	}

	public boolean equals( Object obj ) {
		if( obj == null ) {
			return( false );
		}
		else if( obj instanceof CFSecRamTenantId32Gen ) {
			CFSecRamTenantId32Gen rhs = (CFSecRamTenantId32Gen)obj;
			if( getRequiredId() != rhs.getRequiredId() ) {
				return( false );
			}
			if( getRequiredSliceId() != rhs.getRequiredSliceId() ) {
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
		hashCode = hashCode + (int)( getRequiredId() );
		hashCode = ( hashCode * 0x10000 ) + getRequiredSliceId();
		return( hashCode & 0x7fffffff );
	}

	public int compareTo( Object obj ) {
		if( obj == null ) {
			return( -1 );
		}
		else if( obj instanceof CFSecRamTenantId32Gen ) {
			CFSecRamTenantId32Gen rhs = (CFSecRamTenantId32Gen)obj;
			if( getRequiredId() < rhs.getRequiredId() ) {
				return( -1 );
			}
			else if( getRequiredId() > rhs.getRequiredId() ) {
				return( 1 );
			}
			{
				short lhsSliceId = getRequiredSliceId();
				short rhsSliceId = rhs.getRequiredSliceId();
				if( lhsSliceId < rhsSliceId ) {
					return( -1 );
				}
				else if( lhsSliceId > rhsSliceId ) {
					return( 1 );
				}
			}
			return( 0 );
		}
		else {
			throw new CFLibUnsupportedClassException( getClass(),
				"compareTo",
				"obj",
				obj,
				"CFSecTenantId32Gen" );
		}
	}

	public String toString() {
		String ret = "<CFSecTenantId32Gen"
			+ " RequiredId=" + "\"" + Long.toString( getRequiredId() ) + "\""
			+ ", SliceId=\"" + Short.toString( getRequiredSliceId() ) + "\""
			+ ", NextId=\"" + Integer.toString( nextId ) + "\"/>";
		return( ret );
	}
}
