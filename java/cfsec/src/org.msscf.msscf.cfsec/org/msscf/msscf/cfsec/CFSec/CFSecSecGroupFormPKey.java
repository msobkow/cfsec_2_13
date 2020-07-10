// Description: Java 11 implementation of a SecGroupForm primary key object.

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
import org.apache.commons.codec.binary.Base64;

/*
 *	CFSecSecGroupFormPKey Primary Key for SecGroupForm

 *		requiredClusterId	Required object attribute ClusterId.
 *		requiredSecGroupFormId	Required object attribute SecGroupFormId. */
public class CFSecSecGroupFormPKey
	implements Comparable<Object>,
		Serializable
{

	protected long requiredClusterId;
	protected long requiredSecGroupFormId;
	public CFSecSecGroupFormPKey() {
		requiredClusterId = CFSecSecGroupFormBuff.CLUSTERID_INIT_VALUE;
		requiredSecGroupFormId = CFSecSecGroupFormBuff.SECGROUPFORMID_INIT_VALUE;
	}

	public long getRequiredClusterId() {
		return( requiredClusterId );
	}

	public void setRequiredClusterId( long value ) {
		if( value < CFSecSecGroupFormBuff.CLUSTERID_MIN_VALUE ) {
			throw new CFLibArgumentUnderflowException( getClass(),
				"setRequiredClusterId",
				1,
				"value",
				value,
				CFSecSecGroupFormBuff.CLUSTERID_MIN_VALUE );
		}
		requiredClusterId = value;
	}

	public long getRequiredSecGroupFormId() {
		return( requiredSecGroupFormId );
	}

	public void setRequiredSecGroupFormId( long value ) {
		if( value < CFSecSecGroupFormBuff.SECGROUPFORMID_MIN_VALUE ) {
			throw new CFLibArgumentUnderflowException( getClass(),
				"setRequiredSecGroupFormId",
				1,
				"value",
				value,
				CFSecSecGroupFormBuff.SECGROUPFORMID_MIN_VALUE );
		}
		requiredSecGroupFormId = value;
	}

	public boolean equals( Object obj ) {
		if( obj == null ) {
			return( false );
		}
		else if( obj instanceof CFSecSecGroupFormHPKey ) {
			CFSecSecGroupFormHPKey rhs = (CFSecSecGroupFormHPKey)obj;
			if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
				return( false );
			}
			if( getRequiredSecGroupFormId() != rhs.getRequiredSecGroupFormId() ) {
				return( false );
			}
			return( true );
		}
		else if( obj instanceof CFSecSecGroupFormPKey ) {
			CFSecSecGroupFormPKey rhs = (CFSecSecGroupFormPKey)obj;
			if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
				return( false );
			}
			if( getRequiredSecGroupFormId() != rhs.getRequiredSecGroupFormId() ) {
				return( false );
			}
			return( true );
		}
		else if( obj instanceof CFSecSecGroupFormHBuff ) {
			CFSecSecGroupFormHBuff rhs = (CFSecSecGroupFormHBuff)obj;
			if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
				return( false );
			}
			if( getRequiredSecGroupFormId() != rhs.getRequiredSecGroupFormId() ) {
				return( false );
			}
			return( true );
		}
		else if( obj instanceof CFSecSecGroupFormBuff ) {
			CFSecSecGroupFormBuff rhs = (CFSecSecGroupFormBuff)obj;
			if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
				return( false );
			}
			if( getRequiredSecGroupFormId() != rhs.getRequiredSecGroupFormId() ) {
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
		hashCode = hashCode + (int)( getRequiredSecGroupFormId() );
		return( hashCode & 0x7fffffff );
	}

	public int compareTo( Object obj ) {
		if( obj == null ) {
			return( -1 );
		}
		else if( obj instanceof CFSecSecGroupFormHPKey ) {
			CFSecSecGroupFormHPKey rhs = (CFSecSecGroupFormHPKey)obj;
			if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
				return( -1 );
			}
			else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
				return( 1 );
			}
			if( getRequiredSecGroupFormId() < rhs.getRequiredSecGroupFormId() ) {
				return( -1 );
			}
			else if( getRequiredSecGroupFormId() > rhs.getRequiredSecGroupFormId() ) {
				return( 1 );
			}
			return( 0 );
		}
		else if( obj instanceof CFSecSecGroupFormPKey ) {
			CFSecSecGroupFormPKey rhs = (CFSecSecGroupFormPKey)obj;
			if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
				return( -1 );
			}
			else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
				return( 1 );
			}
			if( getRequiredSecGroupFormId() < rhs.getRequiredSecGroupFormId() ) {
				return( -1 );
			}
			else if( getRequiredSecGroupFormId() > rhs.getRequiredSecGroupFormId() ) {
				return( 1 );
			}
			return( 0 );
		}
		else if( obj instanceof CFSecSecGroupFormBuff ) {
			CFSecSecGroupFormBuff rhs = (CFSecSecGroupFormBuff)obj;
			if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
				return( -1 );
			}
			else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
				return( 1 );
			}
			if( getRequiredSecGroupFormId() < rhs.getRequiredSecGroupFormId() ) {
				return( -1 );
			}
			else if( getRequiredSecGroupFormId() > rhs.getRequiredSecGroupFormId() ) {
				return( 1 );
			}
			return( 0 );
		}
		else if( obj instanceof CFSecSecGroupFormHBuff ) {
			CFSecSecGroupFormHBuff rhs = (CFSecSecGroupFormHBuff)obj;
			if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
				return( -1 );
			}
			else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
				return( 1 );
			}
			if( getRequiredSecGroupFormId() < rhs.getRequiredSecGroupFormId() ) {
				return( -1 );
			}
			else if( getRequiredSecGroupFormId() > rhs.getRequiredSecGroupFormId() ) {
				return( 1 );
			}
			return( 0 );
		}
		else {
			throw new CFLibUnsupportedClassException( getClass(),
				"compareTo",
				"obj",
				obj,
				"CFSecSecGroupFormPKey, CFSecSecGroupFormBuff" );
		}
	}

	public String toString() {
		String ret = "<CFSecSecGroupFormPKey"
			+ " RequiredClusterId=" + "\"" + Long.toString( getRequiredClusterId() ) + "\""
			+ " RequiredSecGroupFormId=" + "\"" + Long.toString( getRequiredSecGroupFormId() ) + "\""
			+ "/>";
		return( ret );
	}
}
