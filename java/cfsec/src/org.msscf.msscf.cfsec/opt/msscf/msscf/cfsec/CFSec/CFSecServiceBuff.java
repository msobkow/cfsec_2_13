// Description: Java 11 implementation of a Service buffer object.

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

public class CFSecServiceBuff
{
	public final static String CLASS_CODE = "a012";
	public final static String S_INIT_CREATEDBY = "654dbba0-eda7-11e1-aff1-0800200c9a66";
	public final static UUID INIT_CREATEDBY = UUID.fromString( S_INIT_CREATEDBY );
	public final static String S_INIT_UPDATEDBY = "654dbba0-eda7-11e1-aff1-0800200c9a66";
	public final static UUID INIT_UPDATEDBY = UUID.fromString( S_INIT_UPDATEDBY );
	public static final long CLUSTERID_INIT_VALUE = 0L;
	public static final long SERVICEID_INIT_VALUE = 0L;
	public static final long HOSTNODEID_INIT_VALUE = 0L;
	public static final int SERVICETYPEID_INIT_VALUE = 0;
	public static final short HOSTPORT_INIT_VALUE = (short)0;
	public static final long CLUSTERID_MIN_VALUE = 0L;
	public static final long SERVICEID_MIN_VALUE = 0L;
	public static final long HOSTNODEID_MIN_VALUE = 0L;
	public static final int SERVICETYPEID_MIN_VALUE = 0;
	public static final short HOSTPORT_MIN_VALUE = (short)0;
	protected UUID createdByUserId = CFSecServiceBuff.INIT_CREATEDBY;
	protected Calendar createdAt = Calendar.getInstance();
	protected UUID updatedByUserId = CFSecServiceBuff.INIT_UPDATEDBY;
	protected Calendar updatedAt = Calendar.getInstance();
	protected long requiredClusterId;
	protected long requiredServiceId;
	protected long requiredHostNodeId;
	protected int requiredServiceTypeId;
	protected short requiredHostPort;
	protected int requiredRevision;
	public CFSecServiceBuff() {
		requiredClusterId = CFSecServiceBuff.CLUSTERID_INIT_VALUE;
		requiredServiceId = CFSecServiceBuff.SERVICEID_INIT_VALUE;
		requiredHostNodeId = CFSecServiceBuff.HOSTNODEID_INIT_VALUE;
		requiredServiceTypeId = CFSecServiceBuff.SERVICETYPEID_INIT_VALUE;
		requiredHostPort = CFSecServiceBuff.HOSTPORT_INIT_VALUE;
	}

	public String getClassCode() {
		return( CLASS_CODE );
	}

	public UUID getCreatedByUserId() {
		return( createdByUserId );
	}

	public void setCreatedByUserId( UUID value ) {
		createdByUserId = value;
	}

	public Calendar getCreatedAt() {
		return( createdAt );
	}

	public void setCreatedAt( Calendar value ) {
		createdAt = value;
	}

	public UUID getUpdatedByUserId() {
		return( updatedByUserId );
	}

	public void setUpdatedByUserId( UUID value ) {
		updatedByUserId = value;
	}

	public Calendar getUpdatedAt() {
		return( updatedAt );
	}

	public void setUpdatedAt( Calendar value ) {
		updatedAt = value;
	}
	public long getRequiredClusterId() {
		return( requiredClusterId );
	}

	public void setRequiredClusterId( long value ) {
		if( value < CFSecServiceBuff.CLUSTERID_MIN_VALUE ) {
			throw new CFLibArgumentUnderflowException( getClass(),
				"setRequiredClusterId",
				1,
				"value",
				value,
				CFSecServiceBuff.CLUSTERID_MIN_VALUE );
		}
		requiredClusterId = value;
	}

	public long getRequiredServiceId() {
		return( requiredServiceId );
	}

	public void setRequiredServiceId( long value ) {
		if( value < CFSecServiceBuff.SERVICEID_MIN_VALUE ) {
			throw new CFLibArgumentUnderflowException( getClass(),
				"setRequiredServiceId",
				1,
				"value",
				value,
				CFSecServiceBuff.SERVICEID_MIN_VALUE );
		}
		requiredServiceId = value;
	}

	public long getRequiredHostNodeId() {
		return( requiredHostNodeId );
	}

	public void setRequiredHostNodeId( long value ) {
		if( value < CFSecServiceBuff.HOSTNODEID_MIN_VALUE ) {
			throw new CFLibArgumentUnderflowException( getClass(),
				"setRequiredHostNodeId",
				1,
				"value",
				value,
				CFSecServiceBuff.HOSTNODEID_MIN_VALUE );
		}
		requiredHostNodeId = value;
	}

	public int getRequiredServiceTypeId() {
		return( requiredServiceTypeId );
	}

	public void setRequiredServiceTypeId( int value ) {
		if( value < CFSecServiceBuff.SERVICETYPEID_MIN_VALUE ) {
			throw new CFLibArgumentUnderflowException( getClass(),
				"setRequiredServiceTypeId",
				1,
				"value",
				value,
				CFSecServiceBuff.SERVICETYPEID_MIN_VALUE );
		}
		requiredServiceTypeId = value;
	}

	public short getRequiredHostPort() {
		return( requiredHostPort );
	}

	public void setRequiredHostPort( short value ) {
		if( value < CFSecServiceBuff.HOSTPORT_MIN_VALUE ) {
			throw new CFLibArgumentUnderflowException( getClass(),
				"setRequiredHostPort",
				1,
				"value",
				value,
				CFSecServiceBuff.HOSTPORT_MIN_VALUE );
		}
		requiredHostPort = value;
	}

	public int getRequiredRevision() {
		return( requiredRevision );
	}

	public void setRequiredRevision( int value ) {
		requiredRevision = value;
	}

	public boolean equals( Object obj ) {
		if( obj == null ) {
			return( false );
		}
		else if( obj instanceof CFSecServiceBuff ) {
			CFSecServiceBuff rhs = (CFSecServiceBuff)obj;
			if( ! getCreatedByUserId().equals( rhs.getCreatedByUserId() ) ) {
				return( false );
			}
			if( ! getCreatedAt().equals( rhs.getCreatedAt() ) ) {
				return( false );
			}
			if( ! getUpdatedByUserId().equals( rhs.getUpdatedByUserId() ) ) {
				return( false );
			}
			if( ! getUpdatedAt().equals( rhs.getUpdatedAt() ) ) {
				return( false );
			}
			if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
				return( false );
			}
			if( getRequiredServiceId() != rhs.getRequiredServiceId() ) {
				return( false );
			}
			if( getRequiredHostNodeId() != rhs.getRequiredHostNodeId() ) {
				return( false );
			}
			if( getRequiredServiceTypeId() != rhs.getRequiredServiceTypeId() ) {
				return( false );
			}
			if( getRequiredHostPort() != rhs.getRequiredHostPort() ) {
				return( false );
			}
			return( true );
		}
		else if( obj instanceof CFSecServicePKey ) {
			CFSecServicePKey rhs = (CFSecServicePKey)obj;
			if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
				return( false );
			}
			if( getRequiredServiceId() != rhs.getRequiredServiceId() ) {
				return( false );
			}
			return( true );
		}
		else if( obj instanceof CFSecServiceHBuff ) {
			CFSecServiceHBuff rhs = (CFSecServiceHBuff)obj;
			if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
				return( false );
			}
			if( getRequiredServiceId() != rhs.getRequiredServiceId() ) {
				return( false );
			}
			if( getRequiredHostNodeId() != rhs.getRequiredHostNodeId() ) {
				return( false );
			}
			if( getRequiredServiceTypeId() != rhs.getRequiredServiceTypeId() ) {
				return( false );
			}
			if( getRequiredHostPort() != rhs.getRequiredHostPort() ) {
				return( false );
			}
			return( true );
		}
		else if( obj instanceof CFSecServiceHPKey ) {
			CFSecServiceHPKey rhs = (CFSecServiceHPKey)obj;
			if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
				return( false );
			}
			if( getRequiredServiceId() != rhs.getRequiredServiceId() ) {
				return( false );
			}
			return( true );
		}
		else if( obj instanceof CFSecServiceByClusterIdxKey ) {
			CFSecServiceByClusterIdxKey rhs = (CFSecServiceByClusterIdxKey)obj;
			if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
				return( false );
			}
			return( true );
		}
		else if( obj instanceof CFSecServiceByHostIdxKey ) {
			CFSecServiceByHostIdxKey rhs = (CFSecServiceByHostIdxKey)obj;
			if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
				return( false );
			}
			if( getRequiredHostNodeId() != rhs.getRequiredHostNodeId() ) {
				return( false );
			}
			return( true );
		}
		else if( obj instanceof CFSecServiceByTypeIdxKey ) {
			CFSecServiceByTypeIdxKey rhs = (CFSecServiceByTypeIdxKey)obj;
			if( getRequiredServiceTypeId() != rhs.getRequiredServiceTypeId() ) {
				return( false );
			}
			return( true );
		}
		else if( obj instanceof CFSecServiceByUTypeIdxKey ) {
			CFSecServiceByUTypeIdxKey rhs = (CFSecServiceByUTypeIdxKey)obj;
			if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
				return( false );
			}
			if( getRequiredHostNodeId() != rhs.getRequiredHostNodeId() ) {
				return( false );
			}
			if( getRequiredServiceTypeId() != rhs.getRequiredServiceTypeId() ) {
				return( false );
			}
			return( true );
		}
		else if( obj instanceof CFSecServiceByUHostPortIdxKey ) {
			CFSecServiceByUHostPortIdxKey rhs = (CFSecServiceByUHostPortIdxKey)obj;
			if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
				return( false );
			}
			if( getRequiredHostNodeId() != rhs.getRequiredHostNodeId() ) {
				return( false );
			}
			if( getRequiredHostPort() != rhs.getRequiredHostPort() ) {
				return( false );
			}
			return( true );
		}
		else {
			boolean retval = super.equals( obj );
			return( retval );
		}
	}

	public int hashCode() {
		int hashCode = 0;
		hashCode = hashCode + getCreatedByUserId().hashCode();
		hashCode = hashCode + getCreatedAt().hashCode();
		hashCode = hashCode + getUpdatedByUserId().hashCode();
		hashCode = hashCode + getUpdatedAt().hashCode();
		hashCode = hashCode + (int)( getRequiredClusterId() );
		hashCode = hashCode + (int)( getRequiredServiceId() );
		hashCode = hashCode + (int)( getRequiredHostNodeId() );
		hashCode = hashCode + getRequiredServiceTypeId();
		hashCode = ( hashCode * 0x10000 ) + getRequiredHostPort();
		return( hashCode & 0x7fffffff );
	}

	public int compareTo( Object obj ) {
		if( obj == null ) {
			return( -1 );
		}
		else if( obj instanceof CFSecServiceBuff ) {
			CFSecServiceBuff rhs = (CFSecServiceBuff)obj;
			int retval = 0;
			{
				int cmp = getCreatedByUserId().compareTo( rhs.getCreatedByUserId() );
				if( cmp != 0 ) {
					return( cmp );
				}

				cmp = getCreatedAt().compareTo( rhs.getCreatedAt() );
				if( cmp != 0 ) {
					return( cmp );
				}

				cmp = getUpdatedByUserId().compareTo( rhs.getUpdatedByUserId() );
				if( cmp != 0 ) {
					return( cmp );
				}

				cmp = getUpdatedAt().compareTo( rhs.getUpdatedAt() );
				if( cmp != 0 ) {
					return( cmp );
				}
			}
			if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
				return( -1 );
			}
			else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
				return( 1 );
			}
			if( getRequiredServiceId() < rhs.getRequiredServiceId() ) {
				return( -1 );
			}
			else if( getRequiredServiceId() > rhs.getRequiredServiceId() ) {
				return( 1 );
			}
			if( getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
				return( -1 );
			}
			else if( getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
				return( 1 );
			}
			if( getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
				return( -1 );
			}
			else if( getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
				return( 1 );
			}
			if( getRequiredHostPort() < rhs.getRequiredHostPort() ) {
				return( -1 );
			}
			else if( getRequiredHostPort() > rhs.getRequiredHostPort() ) {
				return( 1 );
			}
			return( 0 );
		}
		else if( obj instanceof CFSecServicePKey ) {
			CFSecServicePKey rhs = (CFSecServicePKey)obj;
			if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
				return( -1 );
			}
			else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
				return( 1 );
			}
			if( getRequiredServiceId() < rhs.getRequiredServiceId() ) {
				return( -1 );
			}
			else if( getRequiredServiceId() > rhs.getRequiredServiceId() ) {
				return( 1 );
			}
			return( 0 );
		}
		else if( obj instanceof CFSecServiceHPKey ) {
			CFSecServiceHPKey rhs = (CFSecServiceHPKey)obj;
			{
				int lhsRequiredRevision = getRequiredRevision();
				int rhsRequiredRevision = rhs.getRequiredRevision();
				if( lhsRequiredRevision < rhsRequiredRevision ) {
					return( -1 );
				}
				else if( lhsRequiredRevision > rhsRequiredRevision ) {
					return( 1 );
				}
			}
			if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
				return( -1 );
			}
			else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
				return( 1 );
			}
			if( getRequiredServiceId() < rhs.getRequiredServiceId() ) {
				return( -1 );
			}
			else if( getRequiredServiceId() > rhs.getRequiredServiceId() ) {
				return( 1 );
			}
			return( 0 );
		}
		else if( obj instanceof CFSecServiceHBuff ) {
			CFSecServiceHBuff rhs = (CFSecServiceHBuff)obj;
			int retval = 0;
			if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
				return( -1 );
			}
			else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
				return( 1 );
			}
			if( getRequiredServiceId() < rhs.getRequiredServiceId() ) {
				return( -1 );
			}
			else if( getRequiredServiceId() > rhs.getRequiredServiceId() ) {
				return( 1 );
			}
			if( getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
				return( -1 );
			}
			else if( getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
				return( 1 );
			}
			if( getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
				return( -1 );
			}
			else if( getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
				return( 1 );
			}
			if( getRequiredHostPort() < rhs.getRequiredHostPort() ) {
				return( -1 );
			}
			else if( getRequiredHostPort() > rhs.getRequiredHostPort() ) {
				return( 1 );
			}
			return( 0 );
		}
		else if( obj instanceof CFSecServiceByClusterIdxKey ) {
			CFSecServiceByClusterIdxKey rhs = (CFSecServiceByClusterIdxKey)obj;

			if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
				return( -1 );
			}
			else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
				return( 1 );
			}			return( 0 );
		}
		else if( obj instanceof CFSecServiceByHostIdxKey ) {
			CFSecServiceByHostIdxKey rhs = (CFSecServiceByHostIdxKey)obj;

			if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
				return( -1 );
			}
			else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
				return( 1 );
			}
			if( getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
				return( -1 );
			}
			else if( getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
				return( 1 );
			}			return( 0 );
		}
		else if( obj instanceof CFSecServiceByTypeIdxKey ) {
			CFSecServiceByTypeIdxKey rhs = (CFSecServiceByTypeIdxKey)obj;

			if( getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
				return( -1 );
			}
			else if( getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
				return( 1 );
			}			return( 0 );
		}
		else if( obj instanceof CFSecServiceByUTypeIdxKey ) {
			CFSecServiceByUTypeIdxKey rhs = (CFSecServiceByUTypeIdxKey)obj;

			if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
				return( -1 );
			}
			else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
				return( 1 );
			}
			if( getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
				return( -1 );
			}
			else if( getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
				return( 1 );
			}
			if( getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
				return( -1 );
			}
			else if( getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
				return( 1 );
			}			return( 0 );
		}
		else if( obj instanceof CFSecServiceByUHostPortIdxKey ) {
			CFSecServiceByUHostPortIdxKey rhs = (CFSecServiceByUHostPortIdxKey)obj;

			if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
				return( -1 );
			}
			else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
				return( 1 );
			}
			if( getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
				return( -1 );
			}
			else if( getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
				return( 1 );
			}
			if( getRequiredHostPort() < rhs.getRequiredHostPort() ) {
				return( -1 );
			}
			else if( getRequiredHostPort() > rhs.getRequiredHostPort() ) {
				return( 1 );
			}			return( 0 );
		}
		else {
			throw new CFLibUnsupportedClassException( getClass(),
				"compareTo",
				"obj",
				obj,
				null );
		}
	}

	public void set( CFSecServiceBuff src ) {
		setServiceBuff( src );
	}

	public void setServiceBuff( CFSecServiceBuff src ) {
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredServiceId( src.getRequiredServiceId() );
		setCreatedByUserId( src.getCreatedByUserId() );
		setCreatedAt( src.getCreatedAt() );
		setUpdatedByUserId( src.getUpdatedByUserId() );
		setUpdatedAt( src.getUpdatedAt() );
		setRequiredHostNodeId( src.getRequiredHostNodeId() );
		setRequiredServiceTypeId( src.getRequiredServiceTypeId() );
		setRequiredHostPort( src.getRequiredHostPort() );
		setRequiredRevision( src.getRequiredRevision() );
	}

	public void set( CFSecServiceHBuff src ) {
		setServiceBuff( src );
	}

	public void setServiceBuff( CFSecServiceHBuff src ) {
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredServiceId( src.getRequiredServiceId() );
		setRequiredHostNodeId( src.getRequiredHostNodeId() );
		setRequiredServiceTypeId( src.getRequiredServiceTypeId() );
		setRequiredHostPort( src.getRequiredHostPort() );
	}
}
