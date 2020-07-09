// Description: Java 11 implementation of a SecDevice buffer object.

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

public class CFSecSecDeviceBuff
{
	public final static String CLASS_CODE = "a00a";
	public final static String S_INIT_CREATEDBY = "654dbba0-eda7-11e1-aff1-0800200c9a66";
	public final static UUID INIT_CREATEDBY = UUID.fromString( S_INIT_CREATEDBY );
	public final static String S_INIT_UPDATEDBY = "654dbba0-eda7-11e1-aff1-0800200c9a66";
	public final static UUID INIT_UPDATEDBY = UUID.fromString( S_INIT_UPDATEDBY );
	public static final UUID SECUSERID_INIT_VALUE = UUID.fromString( "654dbba0-eda7-11e1-aff1-0800200c9a66" );
	public static final String DEVNAME_INIT_VALUE = new String( "" );
	protected UUID createdByUserId = CFSecSecDeviceBuff.INIT_CREATEDBY;
	protected Calendar createdAt = Calendar.getInstance();
	protected UUID updatedByUserId = CFSecSecDeviceBuff.INIT_UPDATEDBY;
	protected Calendar updatedAt = Calendar.getInstance();
	protected UUID requiredSecUserId;
	protected String requiredDevName;
	protected String optionalPubKey;
	protected int requiredRevision;
	public CFSecSecDeviceBuff() {
		requiredSecUserId = UUID.fromString( CFSecSecDeviceBuff.SECUSERID_INIT_VALUE.toString() );
		requiredDevName = new String( CFSecSecDeviceBuff.DEVNAME_INIT_VALUE );
		optionalPubKey = null;
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

	public String getRequiredDevName() {
		return( requiredDevName );
	}

	public void setRequiredDevName( String value ) {
		if( value == null ) {
			throw new CFLibNullArgumentException( getClass(),
				"setRequiredDevName",
				1,
				"value" );
		}
		if( value.length() > 127 ) {
			throw new CFLibArgumentOverflowException( getClass(),
				"setRequiredDevName",
				1,
				"value.length()",
				value.length(),
				127 );
		}
		requiredDevName = value;
	}

	public String getOptionalPubKey() {
		return( optionalPubKey );
	}

	public void setOptionalPubKey( String value ) {
		if( value == null ) {
			optionalPubKey = null;
		}
		else if( value.length() > 10000 ) {
			throw new CFLibArgumentOverflowException( getClass(),
				"setOptionalPubKey",
				1,
				"value.length()",
				value.length(),
				10000 );
		}
		else {
			optionalPubKey = value;
		}
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
		else if( obj instanceof CFSecSecDeviceBuff ) {
			CFSecSecDeviceBuff rhs = (CFSecSecDeviceBuff)obj;
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
			if( ! getRequiredSecUserId().equals( rhs.getRequiredSecUserId() ) ) {
				return( false );
			}
			if( ! getRequiredDevName().equals( rhs.getRequiredDevName() ) ) {
				return( false );
			}
			if( getOptionalPubKey() != null ) {
				if( rhs.getOptionalPubKey() != null ) {
					if( ! getOptionalPubKey().equals( rhs.getOptionalPubKey() ) ) {
						return( false );
					}
				}
			}
			else {
				if( rhs.getOptionalPubKey() != null ) {
					return( false );
				}
			}
			return( true );
		}
		else if( obj instanceof CFSecSecDevicePKey ) {
			CFSecSecDevicePKey rhs = (CFSecSecDevicePKey)obj;
			if( ! getRequiredSecUserId().equals( rhs.getRequiredSecUserId() ) ) {
				return( false );
			}
			if( ! getRequiredDevName().equals( rhs.getRequiredDevName() ) ) {
				return( false );
			}
			return( true );
		}
		else if( obj instanceof CFSecSecDeviceHBuff ) {
			CFSecSecDeviceHBuff rhs = (CFSecSecDeviceHBuff)obj;
			if( ! getRequiredSecUserId().equals( rhs.getRequiredSecUserId() ) ) {
				return( false );
			}
			if( ! getRequiredDevName().equals( rhs.getRequiredDevName() ) ) {
				return( false );
			}
			if( getOptionalPubKey() != null ) {
				if( rhs.getOptionalPubKey() != null ) {
					if( ! getOptionalPubKey().equals( rhs.getOptionalPubKey() ) ) {
						return( false );
					}
				}
			}
			else {
				if( rhs.getOptionalPubKey() != null ) {
					return( false );
				}
			}
			return( true );
		}
		else if( obj instanceof CFSecSecDeviceHPKey ) {
			CFSecSecDeviceHPKey rhs = (CFSecSecDeviceHPKey)obj;
			if( ! getRequiredSecUserId().equals( rhs.getRequiredSecUserId() ) ) {
				return( false );
			}
			if( ! getRequiredDevName().equals( rhs.getRequiredDevName() ) ) {
				return( false );
			}
			return( true );
		}
		else if( obj instanceof CFSecSecDeviceByNameIdxKey ) {
			CFSecSecDeviceByNameIdxKey rhs = (CFSecSecDeviceByNameIdxKey)obj;
			if( ! getRequiredSecUserId().equals( rhs.getRequiredSecUserId() ) ) {
				return( false );
			}
			if( ! getRequiredDevName().equals( rhs.getRequiredDevName() ) ) {
				return( false );
			}
			return( true );
		}
		else if( obj instanceof CFSecSecDeviceByUserIdxKey ) {
			CFSecSecDeviceByUserIdxKey rhs = (CFSecSecDeviceByUserIdxKey)obj;
			if( ! getRequiredSecUserId().equals( rhs.getRequiredSecUserId() ) ) {
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
		hashCode = hashCode + getRequiredSecUserId().hashCode();
		if( getRequiredDevName() != null ) {
			hashCode = hashCode + getRequiredDevName().hashCode();
		}
		if( getOptionalPubKey() != null ) {
			hashCode = hashCode + getOptionalPubKey().hashCode();
		}
		return( hashCode & 0x7fffffff );
	}

	public int compareTo( Object obj ) {
		if( obj == null ) {
			return( -1 );
		}
		else if( obj instanceof CFSecSecDeviceBuff ) {
			CFSecSecDeviceBuff rhs = (CFSecSecDeviceBuff)obj;
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
			{
				int cmp = getRequiredSecUserId().compareTo( rhs.getRequiredSecUserId() );
				if( cmp != 0 ) {
					return( cmp );
				}
			}
			{
				int cmp = getRequiredDevName().compareTo( rhs.getRequiredDevName() );
				if( cmp != 0 ) {
					return( cmp );
				}
			}
			if( getOptionalPubKey() != null ) {
				if( rhs.getOptionalPubKey() != null ) {
					int cmp = getOptionalPubKey().compareTo( rhs.getOptionalPubKey() );
					if( cmp != 0 ) {
						return( cmp );
					}
				}
				else {
					return( 1 );
				}
			}
			else {
				if( rhs.getOptionalPubKey() != null ) {
					return( -1 );
				}
			}
			return( 0 );
		}
		else if( obj instanceof CFSecSecDevicePKey ) {
			CFSecSecDevicePKey rhs = (CFSecSecDevicePKey)obj;
			{
				int cmp = getRequiredSecUserId().compareTo( rhs.getRequiredSecUserId() );
				if( cmp != 0 ) {
					return( cmp );
				}
			}
			{
				int cmp = getRequiredDevName().compareTo( rhs.getRequiredDevName() );
				if( cmp != 0 ) {
					return( cmp );
				}
			}
			return( 0 );
		}
		else if( obj instanceof CFSecSecDeviceHPKey ) {
			CFSecSecDeviceHPKey rhs = (CFSecSecDeviceHPKey)obj;
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
				int cmp = getRequiredSecUserId().compareTo( rhs.getRequiredSecUserId() );
				if( cmp != 0 ) {
					return( cmp );
				}
			}
			{
				int cmp = getRequiredDevName().compareTo( rhs.getRequiredDevName() );
				if( cmp != 0 ) {
					return( cmp );
				}
			}
			return( 0 );
		}
		else if( obj instanceof CFSecSecDeviceHBuff ) {
			CFSecSecDeviceHBuff rhs = (CFSecSecDeviceHBuff)obj;
			int retval = 0;
			{
				int cmp = getRequiredSecUserId().compareTo( rhs.getRequiredSecUserId() );
				if( cmp != 0 ) {
					return( cmp );
				}
			}
			{
				int cmp = getRequiredDevName().compareTo( rhs.getRequiredDevName() );
				if( cmp != 0 ) {
					return( cmp );
				}
			}
			if( getOptionalPubKey() != null ) {
				if( rhs.getOptionalPubKey() != null ) {
					int cmp = getOptionalPubKey().compareTo( rhs.getOptionalPubKey() );
					if( cmp != 0 ) {
						return( cmp );
					}
				}
				else {
					return( 1 );
				}
			}
			else {
				if( rhs.getOptionalPubKey() != null ) {
					return( -1 );
				}
			}
			return( 0 );
		}
		else if( obj instanceof CFSecSecDeviceByNameIdxKey ) {
			CFSecSecDeviceByNameIdxKey rhs = (CFSecSecDeviceByNameIdxKey)obj;

			{
				int cmp = getRequiredSecUserId().compareTo( rhs.getRequiredSecUserId() );
				if( cmp != 0 ) {
					return( cmp );
				}
			}
			{
				int cmp = getRequiredDevName().compareTo( rhs.getRequiredDevName() );
				if( cmp != 0 ) {
					return( cmp );
				}
			}			return( 0 );
		}
		else if( obj instanceof CFSecSecDeviceByUserIdxKey ) {
			CFSecSecDeviceByUserIdxKey rhs = (CFSecSecDeviceByUserIdxKey)obj;

			{
				int cmp = getRequiredSecUserId().compareTo( rhs.getRequiredSecUserId() );
				if( cmp != 0 ) {
					return( cmp );
				}
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

	public void set( CFSecSecDeviceBuff src ) {
		setSecDeviceBuff( src );
	}

	public void setSecDeviceBuff( CFSecSecDeviceBuff src ) {
		setRequiredSecUserId( src.getRequiredSecUserId() );
		setRequiredDevName( src.getRequiredDevName() );
		setCreatedByUserId( src.getCreatedByUserId() );
		setCreatedAt( src.getCreatedAt() );
		setUpdatedByUserId( src.getUpdatedByUserId() );
		setUpdatedAt( src.getUpdatedAt() );
		setOptionalPubKey( src.getOptionalPubKey() );
		setRequiredRevision( src.getRequiredRevision() );
	}

	public void set( CFSecSecDeviceHBuff src ) {
		setSecDeviceBuff( src );
	}

	public void setSecDeviceBuff( CFSecSecDeviceHBuff src ) {
		setRequiredSecUserId( src.getRequiredSecUserId() );
		setRequiredDevName( src.getRequiredDevName() );
		setOptionalPubKey( src.getOptionalPubKey() );
	}
}
