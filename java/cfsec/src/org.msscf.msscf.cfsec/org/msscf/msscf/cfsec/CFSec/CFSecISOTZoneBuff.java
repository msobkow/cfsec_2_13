// Description: Java 11 implementation of a ISOTZone buffer object.

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

public class CFSecISOTZoneBuff
{
	public final static String CLASS_CODE = "a008";
	public final static String S_INIT_CREATEDBY = "654dbba0-eda7-11e1-aff1-0800200c9a66";
	public final static UUID INIT_CREATEDBY = UUID.fromString( S_INIT_CREATEDBY );
	public final static String S_INIT_UPDATEDBY = "654dbba0-eda7-11e1-aff1-0800200c9a66";
	public final static UUID INIT_UPDATEDBY = UUID.fromString( S_INIT_UPDATEDBY );
	public static final short ISOTZONEID_INIT_VALUE = (short)0;
	public static final String ISO8601_INIT_VALUE = new String( "" );
	public static final String TZNAME_INIT_VALUE = new String( "" );
	public static final short TZHOUROFFSET_INIT_VALUE = (short)0;
	public static final short TZMINOFFSET_INIT_VALUE = (short)0;
	public static final String DESCRIPTION_INIT_VALUE = new String( "" );
	public final static boolean VISIBLE_INIT_VALUE = true;
	public static final short ISOTZONEID_MIN_VALUE = (short)0;
	public static final short TZHOUROFFSET_MIN_VALUE = (short)-12;
	public static final short TZMINOFFSET_MIN_VALUE = (short)-59;
	public static final short TZHOUROFFSET_MAX_VALUE = (short)12;
	public static final short TZMINOFFSET_MAX_VALUE = (short)59;
	protected UUID createdByUserId = CFSecISOTZoneBuff.INIT_CREATEDBY;
	protected Calendar createdAt = Calendar.getInstance();
	protected UUID updatedByUserId = CFSecISOTZoneBuff.INIT_UPDATEDBY;
	protected Calendar updatedAt = Calendar.getInstance();
	protected short requiredISOTZoneId;
	protected String requiredIso8601;
	protected String requiredTZName;
	protected short requiredTZHourOffset;
	protected short requiredTZMinOffset;
	protected String requiredDescription;
	protected boolean requiredVisible;
	protected int requiredRevision;
	public CFSecISOTZoneBuff() {
		requiredISOTZoneId = CFSecISOTZoneBuff.ISOTZONEID_INIT_VALUE;
		requiredIso8601 = new String( CFSecISOTZoneBuff.ISO8601_INIT_VALUE );
		requiredTZName = new String( CFSecISOTZoneBuff.TZNAME_INIT_VALUE );
		requiredTZHourOffset = CFSecISOTZoneBuff.TZHOUROFFSET_INIT_VALUE;
		requiredTZMinOffset = CFSecISOTZoneBuff.TZMINOFFSET_INIT_VALUE;
		requiredDescription = new String( CFSecISOTZoneBuff.DESCRIPTION_INIT_VALUE );
		requiredVisible = CFSecISOTZoneBuff.VISIBLE_INIT_VALUE;
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
	public short getRequiredISOTZoneId() {
		return( requiredISOTZoneId );
	}

	public void setRequiredISOTZoneId( short value ) {
		if( value < CFSecISOTZoneBuff.ISOTZONEID_MIN_VALUE ) {
			throw new CFLibArgumentUnderflowException( getClass(),
				"setRequiredISOTZoneId",
				1,
				"value",
				value,
				CFSecISOTZoneBuff.ISOTZONEID_MIN_VALUE );
		}
		requiredISOTZoneId = value;
	}

	public String getRequiredIso8601() {
		return( requiredIso8601 );
	}

	public void setRequiredIso8601( String value ) {
		if( value == null ) {
			throw new CFLibNullArgumentException( getClass(),
				"setRequiredIso8601",
				1,
				"value" );
		}
		if( value.length() > 6 ) {
			throw new CFLibArgumentOverflowException( getClass(),
				"setRequiredIso8601",
				1,
				"value.length()",
				value.length(),
				6 );
		}
		requiredIso8601 = value;
	}

	public String getRequiredTZName() {
		return( requiredTZName );
	}

	public void setRequiredTZName( String value ) {
		if( value == null ) {
			throw new CFLibNullArgumentException( getClass(),
				"setRequiredTZName",
				1,
				"value" );
		}
		if( value.length() > 64 ) {
			throw new CFLibArgumentOverflowException( getClass(),
				"setRequiredTZName",
				1,
				"value.length()",
				value.length(),
				64 );
		}
		requiredTZName = value;
	}

	public short getRequiredTZHourOffset() {
		return( requiredTZHourOffset );
	}

	public void setRequiredTZHourOffset( short value ) {
		if( value < CFSecISOTZoneBuff.TZHOUROFFSET_MIN_VALUE ) {
			throw new CFLibArgumentUnderflowException( getClass(),
				"setRequiredTZHourOffset",
				1,
				"value",
				value,
				CFSecISOTZoneBuff.TZHOUROFFSET_MIN_VALUE );
		}
		if( value > CFSecISOTZoneBuff.TZHOUROFFSET_MAX_VALUE ) {
			throw new CFLibArgumentOverflowException( getClass(),
				"setRequiredTZHourOffset",
				1,
				"value",
				value,
				CFSecISOTZoneBuff.TZHOUROFFSET_MAX_VALUE );
		}
		requiredTZHourOffset = value;
	}

	public short getRequiredTZMinOffset() {
		return( requiredTZMinOffset );
	}

	public void setRequiredTZMinOffset( short value ) {
		if( value < CFSecISOTZoneBuff.TZMINOFFSET_MIN_VALUE ) {
			throw new CFLibArgumentUnderflowException( getClass(),
				"setRequiredTZMinOffset",
				1,
				"value",
				value,
				CFSecISOTZoneBuff.TZMINOFFSET_MIN_VALUE );
		}
		if( value > CFSecISOTZoneBuff.TZMINOFFSET_MAX_VALUE ) {
			throw new CFLibArgumentOverflowException( getClass(),
				"setRequiredTZMinOffset",
				1,
				"value",
				value,
				CFSecISOTZoneBuff.TZMINOFFSET_MAX_VALUE );
		}
		requiredTZMinOffset = value;
	}

	public String getRequiredDescription() {
		return( requiredDescription );
	}

	public void setRequiredDescription( String value ) {
		if( value == null ) {
			throw new CFLibNullArgumentException( getClass(),
				"setRequiredDescription",
				1,
				"value" );
		}
		if( value.length() > 128 ) {
			throw new CFLibArgumentOverflowException( getClass(),
				"setRequiredDescription",
				1,
				"value.length()",
				value.length(),
				128 );
		}
		requiredDescription = value;
	}

	public boolean getRequiredVisible() {
		return( requiredVisible );
	}

	public void setRequiredVisible( boolean value ) {
		requiredVisible = value;
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
		else if( obj instanceof CFSecISOTZoneBuff ) {
			CFSecISOTZoneBuff rhs = (CFSecISOTZoneBuff)obj;
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
			if( getRequiredISOTZoneId() != rhs.getRequiredISOTZoneId() ) {
				return( false );
			}
			if( ! getRequiredIso8601().equals( rhs.getRequiredIso8601() ) ) {
				return( false );
			}
			if( ! getRequiredTZName().equals( rhs.getRequiredTZName() ) ) {
				return( false );
			}
			if( getRequiredTZHourOffset() != rhs.getRequiredTZHourOffset() ) {
				return( false );
			}
			if( getRequiredTZMinOffset() != rhs.getRequiredTZMinOffset() ) {
				return( false );
			}
			if( ! getRequiredDescription().equals( rhs.getRequiredDescription() ) ) {
				return( false );
			}
			if( getRequiredVisible() != rhs.getRequiredVisible() ) {
				return( false );
			}
			return( true );
		}
		else if( obj instanceof CFSecISOTZonePKey ) {
			CFSecISOTZonePKey rhs = (CFSecISOTZonePKey)obj;
			if( getRequiredISOTZoneId() != rhs.getRequiredISOTZoneId() ) {
				return( false );
			}
			return( true );
		}
		else if( obj instanceof CFSecISOTZoneHBuff ) {
			CFSecISOTZoneHBuff rhs = (CFSecISOTZoneHBuff)obj;
			if( getRequiredISOTZoneId() != rhs.getRequiredISOTZoneId() ) {
				return( false );
			}
			if( ! getRequiredIso8601().equals( rhs.getRequiredIso8601() ) ) {
				return( false );
			}
			if( ! getRequiredTZName().equals( rhs.getRequiredTZName() ) ) {
				return( false );
			}
			if( getRequiredTZHourOffset() != rhs.getRequiredTZHourOffset() ) {
				return( false );
			}
			if( getRequiredTZMinOffset() != rhs.getRequiredTZMinOffset() ) {
				return( false );
			}
			if( ! getRequiredDescription().equals( rhs.getRequiredDescription() ) ) {
				return( false );
			}
			if( getRequiredVisible() != rhs.getRequiredVisible() ) {
				return( false );
			}
			return( true );
		}
		else if( obj instanceof CFSecISOTZoneHPKey ) {
			CFSecISOTZoneHPKey rhs = (CFSecISOTZoneHPKey)obj;
			if( getRequiredISOTZoneId() != rhs.getRequiredISOTZoneId() ) {
				return( false );
			}
			return( true );
		}
		else if( obj instanceof CFSecISOTZoneByOffsetIdxKey ) {
			CFSecISOTZoneByOffsetIdxKey rhs = (CFSecISOTZoneByOffsetIdxKey)obj;
			if( getRequiredTZHourOffset() != rhs.getRequiredTZHourOffset() ) {
				return( false );
			}
			if( getRequiredTZMinOffset() != rhs.getRequiredTZMinOffset() ) {
				return( false );
			}
			return( true );
		}
		else if( obj instanceof CFSecISOTZoneByUTZNameIdxKey ) {
			CFSecISOTZoneByUTZNameIdxKey rhs = (CFSecISOTZoneByUTZNameIdxKey)obj;
			if( ! getRequiredTZName().equals( rhs.getRequiredTZName() ) ) {
				return( false );
			}
			return( true );
		}
		else if( obj instanceof CFSecISOTZoneByIso8601IdxKey ) {
			CFSecISOTZoneByIso8601IdxKey rhs = (CFSecISOTZoneByIso8601IdxKey)obj;
			if( ! getRequiredIso8601().equals( rhs.getRequiredIso8601() ) ) {
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
		hashCode = ( hashCode * 0x10000 ) + getRequiredISOTZoneId();
		if( getRequiredIso8601() != null ) {
			hashCode = hashCode + getRequiredIso8601().hashCode();
		}
		if( getRequiredTZName() != null ) {
			hashCode = hashCode + getRequiredTZName().hashCode();
		}
		hashCode = ( hashCode * 0x10000 ) + getRequiredTZHourOffset();
		hashCode = ( hashCode * 0x10000 ) + getRequiredTZMinOffset();
		if( getRequiredDescription() != null ) {
			hashCode = hashCode + getRequiredDescription().hashCode();
		}
		if( getRequiredVisible() ) {
			hashCode = ( hashCode * 2 ) + 1;
		}
		else {
			hashCode = hashCode * 2;
		}
		return( hashCode & 0x7fffffff );
	}

	public int compareTo( Object obj ) {
		if( obj == null ) {
			return( -1 );
		}
		else if( obj instanceof CFSecISOTZoneBuff ) {
			CFSecISOTZoneBuff rhs = (CFSecISOTZoneBuff)obj;
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
			if( getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
				return( -1 );
			}
			else if( getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
				return( 1 );
			}
			{
				int cmp = getRequiredIso8601().compareTo( rhs.getRequiredIso8601() );
				if( cmp != 0 ) {
					return( cmp );
				}
			}
			{
				int cmp = getRequiredTZName().compareTo( rhs.getRequiredTZName() );
				if( cmp != 0 ) {
					return( cmp );
				}
			}
			if( getRequiredTZHourOffset() < rhs.getRequiredTZHourOffset() ) {
				return( -1 );
			}
			else if( getRequiredTZHourOffset() > rhs.getRequiredTZHourOffset() ) {
				return( 1 );
			}
			if( getRequiredTZMinOffset() < rhs.getRequiredTZMinOffset() ) {
				return( -1 );
			}
			else if( getRequiredTZMinOffset() > rhs.getRequiredTZMinOffset() ) {
				return( 1 );
			}
			{
				int cmp = getRequiredDescription().compareTo( rhs.getRequiredDescription() );
				if( cmp != 0 ) {
					return( cmp );
				}
			}
			if( getRequiredVisible() ) {
				if( ! rhs.getRequiredVisible() ) {
					return( 1 );
				}
			}
			else {
				if( rhs.getRequiredVisible() ) {
					return( -1 );
				}
			}
			return( 0 );
		}
		else if( obj instanceof CFSecISOTZonePKey ) {
			CFSecISOTZonePKey rhs = (CFSecISOTZonePKey)obj;
			if( getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
				return( -1 );
			}
			else if( getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
				return( 1 );
			}
			return( 0 );
		}
		else if( obj instanceof CFSecISOTZoneHPKey ) {
			CFSecISOTZoneHPKey rhs = (CFSecISOTZoneHPKey)obj;
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
			if( getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
				return( -1 );
			}
			else if( getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
				return( 1 );
			}
			return( 0 );
		}
		else if( obj instanceof CFSecISOTZoneHBuff ) {
			CFSecISOTZoneHBuff rhs = (CFSecISOTZoneHBuff)obj;
			int retval = 0;
			if( getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
				return( -1 );
			}
			else if( getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
				return( 1 );
			}
			{
				int cmp = getRequiredIso8601().compareTo( rhs.getRequiredIso8601() );
				if( cmp != 0 ) {
					return( cmp );
				}
			}
			{
				int cmp = getRequiredTZName().compareTo( rhs.getRequiredTZName() );
				if( cmp != 0 ) {
					return( cmp );
				}
			}
			if( getRequiredTZHourOffset() < rhs.getRequiredTZHourOffset() ) {
				return( -1 );
			}
			else if( getRequiredTZHourOffset() > rhs.getRequiredTZHourOffset() ) {
				return( 1 );
			}
			if( getRequiredTZMinOffset() < rhs.getRequiredTZMinOffset() ) {
				return( -1 );
			}
			else if( getRequiredTZMinOffset() > rhs.getRequiredTZMinOffset() ) {
				return( 1 );
			}
			{
				int cmp = getRequiredDescription().compareTo( rhs.getRequiredDescription() );
				if( cmp != 0 ) {
					return( cmp );
				}
			}
			if( getRequiredVisible() ) {
				if( ! rhs.getRequiredVisible() ) {
					return( 1 );
				}
			}
			else {
				if( rhs.getRequiredVisible() ) {
					return( -1 );
				}
			}
			return( 0 );
		}
		else if( obj instanceof CFSecISOTZoneByOffsetIdxKey ) {
			CFSecISOTZoneByOffsetIdxKey rhs = (CFSecISOTZoneByOffsetIdxKey)obj;

			if( getRequiredTZHourOffset() < rhs.getRequiredTZHourOffset() ) {
				return( -1 );
			}
			else if( getRequiredTZHourOffset() > rhs.getRequiredTZHourOffset() ) {
				return( 1 );
			}
			if( getRequiredTZMinOffset() < rhs.getRequiredTZMinOffset() ) {
				return( -1 );
			}
			else if( getRequiredTZMinOffset() > rhs.getRequiredTZMinOffset() ) {
				return( 1 );
			}			return( 0 );
		}
		else if( obj instanceof CFSecISOTZoneByUTZNameIdxKey ) {
			CFSecISOTZoneByUTZNameIdxKey rhs = (CFSecISOTZoneByUTZNameIdxKey)obj;

			{
				int cmp = getRequiredTZName().compareTo( rhs.getRequiredTZName() );
				if( cmp != 0 ) {
					return( cmp );
				}
			}			return( 0 );
		}
		else if( obj instanceof CFSecISOTZoneByIso8601IdxKey ) {
			CFSecISOTZoneByIso8601IdxKey rhs = (CFSecISOTZoneByIso8601IdxKey)obj;

			{
				int cmp = getRequiredIso8601().compareTo( rhs.getRequiredIso8601() );
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

	public void set( CFSecISOTZoneBuff src ) {
		setISOTZoneBuff( src );
	}

	public void setISOTZoneBuff( CFSecISOTZoneBuff src ) {
		setRequiredISOTZoneId( src.getRequiredISOTZoneId() );
		setCreatedByUserId( src.getCreatedByUserId() );
		setCreatedAt( src.getCreatedAt() );
		setUpdatedByUserId( src.getUpdatedByUserId() );
		setUpdatedAt( src.getUpdatedAt() );
		setRequiredIso8601( src.getRequiredIso8601() );
		setRequiredTZName( src.getRequiredTZName() );
		setRequiredTZHourOffset( src.getRequiredTZHourOffset() );
		setRequiredTZMinOffset( src.getRequiredTZMinOffset() );
		setRequiredDescription( src.getRequiredDescription() );
		setRequiredVisible( src.getRequiredVisible() );
		setRequiredRevision( src.getRequiredRevision() );
	}

	public void set( CFSecISOTZoneHBuff src ) {
		setISOTZoneBuff( src );
	}

	public void setISOTZoneBuff( CFSecISOTZoneHBuff src ) {
		setRequiredISOTZoneId( src.getRequiredISOTZoneId() );
		setRequiredIso8601( src.getRequiredIso8601() );
		setRequiredTZName( src.getRequiredTZName() );
		setRequiredTZHourOffset( src.getRequiredTZHourOffset() );
		setRequiredTZMinOffset( src.getRequiredTZMinOffset() );
		setRequiredDescription( src.getRequiredDescription() );
		setRequiredVisible( src.getRequiredVisible() );
	}
}
