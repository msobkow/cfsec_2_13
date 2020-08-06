// Description: Java 11 implementation of a Service history buffer object.

/*
 *	org.msscf.msscf.CFSec
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFSec 2.13 Security Essentials
 *	
 *	Copyright 2020 Mark Stephen Sobkow
 *	
 *		This file is part of MSS Code Factory.
 *	
 *		MSS Code Factory is available under dual commercial license from Mark Stephen
 *		Sobkow, or under the terms of the GNU General Public License, Version 3
 *		or later.
 *	
 *	    MSS Code Factory is free software: you can redistribute it and/or modify
 *	    it under the terms of the GNU General Public License as published by
 *	    the Free Software Foundation, either version 3 of the License, or
 *	    (at your option) any later version.
 *	
 *	    MSS Code Factory is distributed in the hope that it will be useful,
 *	    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	    GNU General Public License for more details.
 *	
 *	    You should have received a copy of the GNU General Public License
 *	    along with MSS Code Factory.  If not, see <https://www.gnu.org/licenses/>.
 *	
 *	Donations to support MSS Code Factory can be made at
 *	https://www.paypal.com/paypalme2/MarkSobkow
 *	
 *	Please contact Mark Stephen Sobkow at msobkow@sasktel.net for commercial licensing.
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

public class CFSecServiceHBuff

	extends CFSecHPKey	implements Comparable<Object>,
		Serializable
{
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

	protected long requiredClusterId;
	protected long requiredServiceId;
	protected long requiredHostNodeId;
	protected int requiredServiceTypeId;
	protected short requiredHostPort;
	public CFSecServiceHBuff() {
		super();
		requiredClusterId = CFSecServiceBuff.CLUSTERID_INIT_VALUE;
		requiredServiceId = CFSecServiceBuff.SERVICEID_INIT_VALUE;
		requiredHostNodeId = CFSecServiceBuff.HOSTNODEID_INIT_VALUE;
		requiredServiceTypeId = CFSecServiceBuff.SERVICETYPEID_INIT_VALUE;
		requiredHostPort = CFSecServiceBuff.HOSTPORT_INIT_VALUE;
	}

	public String getClassCode() {
		return( CFSecServiceBuff.CLASS_CODE );
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

	public boolean equals( Object obj ) {
		if( obj == null ) {
			return( false );
		}
		else if( obj instanceof CFSecServiceHBuff ) {
			CFSecServiceHBuff rhs = (CFSecServiceHBuff)obj;
			if( ! super.equals( obj ) ) {
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
		else if( obj instanceof CFSecServiceBuff ) {
			CFSecServiceBuff rhs = (CFSecServiceBuff)obj;
			if( ! super.equals( obj ) ) {
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
		else if( obj instanceof CFSecServiceHPKey ) {
			CFSecServiceHPKey rhs = (CFSecServiceHPKey)obj;
			{
				long lhsClusterId = getAuditClusterId();
				long rhsClusterId = rhs.getAuditClusterId();
				if( lhsClusterId != rhsClusterId ) {
					return( false );
				}
			}
			{
				Calendar lhsAuditStamp = getAuditStamp();
				Calendar rhsAuditStamp = rhs.getAuditStamp();
				if( lhsAuditStamp != null ) {
					if( rhsAuditStamp != null ) {
						if( ! lhsAuditStamp.equals( rhsAuditStamp ) ) {
							return( false );
						}
					}
					else {
						return( false );
					}
				}
				else {
					return( false );
				}
			}
			{
				short lhsActionId = getAuditActionId();
				short rhsActionId = rhs.getAuditActionId();
				if( lhsActionId != rhsActionId ) {
					return( false );
				}
			}
			{
				int lhsRevision = getRequiredRevision();
				int rhsRevision = rhs.getRequiredRevision();
				if( lhsRevision != rhsRevision ) {
					return( false );
				}
			}
			{
				UUID lhsAuditSessionId = getAuditSessionId();
				UUID rhsAuditSessionId = rhs.getAuditSessionId();
				if( lhsAuditSessionId != null ) {
					if( rhsAuditSessionId != null ) {
						if( ! lhsAuditSessionId.equals( rhsAuditSessionId ) ) {
							return( false );
						}
					}
					else {
						return( false );
					}
				}
				else {
					return( false );
				}
			}
			if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
				return( false );
			}
			if( getRequiredServiceId() != rhs.getRequiredServiceId() ) {
				return( false );
			}
			return( true );
		}
		else if( obj instanceof CFSecHPKey ) {
			CFSecHPKey rhs = (CFSecHPKey)obj;
			{
				long lhsClusterId = getAuditClusterId();
				long rhsClusterId = rhs.getAuditClusterId();
				if( lhsClusterId != rhsClusterId ) {
					return( false );
				}
			}
			{
				Calendar lhsAuditStamp = getAuditStamp();
				Calendar rhsAuditStamp = rhs.getAuditStamp();
				if( lhsAuditStamp != null ) {
					if( rhsAuditStamp != null ) {
						if( ! lhsAuditStamp.equals( rhsAuditStamp ) ) {
							return( false );
						}
					}
					else {
						return( false );
					}
				}
				else {
					return( false );
				}
			}
			{
				short lhsActionId = getAuditActionId();
				short rhsActionId = rhs.getAuditActionId();
				if( lhsActionId != rhsActionId ) {
					return( false );
				}
			}
			{
				int lhsRevision = getRequiredRevision();
				int rhsRevision = rhs.getRequiredRevision();
				if( lhsRevision != rhsRevision ) {
					return( false );
				}
			}
			{
				UUID lhsAuditSessionId = getAuditSessionId();
				UUID rhsAuditSessionId = rhs.getAuditSessionId();
				if( lhsAuditSessionId != null ) {
					if( rhsAuditSessionId != null ) {
						if( ! lhsAuditSessionId.equals( rhsAuditSessionId ) ) {
							return( false );
						}
					}
					else {
						return( false );
					}
				}
				else {
					return( false );
				}
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
		else {
			return( super.equals( obj ) );
		}
	}

	public int hashCode() {
		int hashCode = super.hashCode();
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
			int retval = super.compareTo( rhs );
			if( retval != 0 ) {
				return( retval );
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
		else if( obj instanceof CFSecServiceHBuff ) {
			CFSecServiceHBuff rhs = (CFSecServiceHBuff)obj;

			int retval = 0;
			{
				long lhsAuditClusterId = getAuditClusterId();
				long rhsAuditClusterId = rhs.getAuditClusterId();
				if( lhsAuditClusterId < rhsAuditClusterId ) {
					return( -1 );
				}
				else if( lhsAuditClusterId > rhsAuditClusterId ) {
					return( 1 );
				}
			}
			{
				Calendar lhsAuditStamp = getAuditStamp();
				Calendar rhsAuditStamp = rhs.getAuditStamp();
				if( lhsAuditStamp == null ) {
					if( rhsAuditStamp != null ) {
						return( -1 );
					}
				}
				else if( rhsAuditStamp == null ) {
					return( 1 );
				}
				else {
					int cmpstat = lhsAuditStamp.compareTo( rhsAuditStamp );
					if( cmpstat != 0 ) {
						return( cmpstat );
					}
				}
			}
			{
				short lhsAuditActionId = getAuditActionId();
				short rhsAuditActionId = rhs.getAuditActionId();
				if( lhsAuditActionId < rhsAuditActionId ) {
					return( -1 );
				}
				else if( lhsAuditActionId > rhsAuditActionId ) {
					return( 1 );
				}
			}
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
			{
				UUID lhsAuditSessionId = getAuditSessionId();
				UUID rhsAuditSessionId = rhs.getAuditSessionId();
				if( lhsAuditSessionId == null ) {
					if( rhsAuditSessionId != null ) {
						return( -1 );
					}
				}
				else if( rhsAuditSessionId == null ) {
					return( 1 );
				}
				else {
					int cmpstat = lhsAuditSessionId.compareTo( rhsAuditSessionId );
					if( cmpstat != 0 ) {
						return( cmpstat );
					}
				}
			}
			{
				long lhsAuditClusterId = getAuditClusterId();
				long rhsAuditClusterId = rhs.getAuditClusterId();
				if( lhsAuditClusterId < rhsAuditClusterId ) {
					return( -1 );
				}
				else if( lhsAuditClusterId > rhsAuditClusterId ) {
					return( 1 );
				}
			}
			{
				Calendar lhsAuditStamp = getAuditStamp();
				Calendar rhsAuditStamp = rhs.getAuditStamp();
				if( lhsAuditStamp == null ) {
					if( rhsAuditStamp != null ) {
						return( -1 );
					}
				}
				else if( rhsAuditStamp == null ) {
					return( 1 );
				}
				else {
					int cmpstat = lhsAuditStamp.compareTo( rhsAuditStamp );
					if( cmpstat != 0 ) {
						return( cmpstat );
					}
				}
			}
			{
				short lhsAuditActionId = getAuditActionId();
				short rhsAuditActionId = rhs.getAuditActionId();
				if( lhsAuditActionId < rhsAuditActionId ) {
					return( -1 );
				}
				else if( lhsAuditActionId > rhsAuditActionId ) {
					return( 1 );
				}
			}
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
			{
				UUID lhsAuditSessionId = getAuditSessionId();
				UUID rhsAuditSessionId = rhs.getAuditSessionId();
				if( lhsAuditSessionId == null ) {
					if( rhsAuditSessionId != null ) {
						return( -1 );
					}
				}
				else if( rhsAuditSessionId == null ) {
					return( 1 );
				}
				else {
					int cmpstat = lhsAuditSessionId.compareTo( rhsAuditSessionId );
					if( cmpstat != 0 ) {
						return( cmpstat );
					}
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
		else if( obj instanceof CFSecServiceHPKey ) {
			CFSecServiceHPKey rhs = (CFSecServiceHPKey)obj;
			{
				long lhsAuditClusterId = getAuditClusterId();
				long rhsAuditClusterId = rhs.getAuditClusterId();
				if( lhsAuditClusterId < rhsAuditClusterId ) {
					return( -1 );
				}
				else if( lhsAuditClusterId > rhsAuditClusterId ) {
					return( 1 );
				}
			}
			{
				Calendar lhsAuditStamp = getAuditStamp();
				Calendar rhsAuditStamp = rhs.getAuditStamp();
				if( lhsAuditStamp == null ) {
					if( rhsAuditStamp != null ) {
						return( -1 );
					}
				}
				else if( rhsAuditStamp == null ) {
					return( 1 );
				}
				else {
					int cmpstat = lhsAuditStamp.compareTo( rhsAuditStamp );
					if( cmpstat != 0 ) {
						return( cmpstat );
					}
				}
			}
			{
				short lhsAuditActionId = getAuditActionId();
				short rhsAuditActionId = rhs.getAuditActionId();
				if( lhsAuditActionId < rhsAuditActionId ) {
					return( -1 );
				}
				else if( lhsAuditActionId > rhsAuditActionId ) {
					return( 1 );
				}
			}
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
			{
				UUID lhsAuditSessionId = getAuditSessionId();
				UUID rhsAuditSessionId = rhs.getAuditSessionId();
				if( lhsAuditSessionId == null ) {
					if( rhsAuditSessionId != null ) {
						return( -1 );
					}
				}
				else if( rhsAuditSessionId == null ) {
					return( 1 );
				}
				else {
					int cmpstat = lhsAuditSessionId.compareTo( rhsAuditSessionId );
					if( cmpstat != 0 ) {
						return( cmpstat );
					}
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
		else if( obj instanceof CFSecHPKey ) {
			CFSecHPKey rhs = (CFSecHPKey)obj;
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
			return( 0 );
		}
		else {
			return( super.compareTo( obj ) );
		}
	}

	public void set( CFSecServiceBuff src ) {
		setServiceBuff( src );
	}

	public void setServiceBuff( CFSecServiceBuff src ) {
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredServiceId( src.getRequiredServiceId() );
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
		setRequiredRevision( src.getRequiredRevision() );
	}
}
