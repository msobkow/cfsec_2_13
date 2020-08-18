// Description: Java 11 implementation of a ISOLang buffer object.

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

public class CFSecISOLangBuff
{
	public final static String CLASS_CODE = "a007";
	public final static String S_INIT_CREATEDBY = "654dbba0-eda7-11e1-aff1-0800200c9a66";
	public final static UUID INIT_CREATEDBY = UUID.fromString( S_INIT_CREATEDBY );
	public final static String S_INIT_UPDATEDBY = "654dbba0-eda7-11e1-aff1-0800200c9a66";
	public final static UUID INIT_UPDATEDBY = UUID.fromString( S_INIT_UPDATEDBY );
	public static final short ISOLANGID_INIT_VALUE = (short)0;
	public static final String ISO6392CODE_INIT_VALUE = new String( "" );
	public static final String ISO6391CODE_INIT_VALUE = new String( "" );
	public static final String ENGLISHNAME_INIT_VALUE = new String( "" );
	public static final short ISOLANGID_MIN_VALUE = (short)0;
	protected UUID createdByUserId = CFSecISOLangBuff.INIT_CREATEDBY;
	protected Calendar createdAt = Calendar.getInstance();
	protected UUID updatedByUserId = CFSecISOLangBuff.INIT_UPDATEDBY;
	protected Calendar updatedAt = Calendar.getInstance();
	protected short requiredISOLangId;
	protected String requiredISO6392Code;
	protected String optionalISO6391Code;
	protected String requiredEnglishName;
	protected int requiredRevision;
	public CFSecISOLangBuff() {
		requiredISOLangId = CFSecISOLangBuff.ISOLANGID_INIT_VALUE;
		requiredISO6392Code = new String( CFSecISOLangBuff.ISO6392CODE_INIT_VALUE );
		optionalISO6391Code = null;
		requiredEnglishName = new String( CFSecISOLangBuff.ENGLISHNAME_INIT_VALUE );
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
	public short getRequiredISOLangId() {
		return( requiredISOLangId );
	}

	public void setRequiredISOLangId( short value ) {
		if( value < CFSecISOLangBuff.ISOLANGID_MIN_VALUE ) {
			throw new CFLibArgumentUnderflowException( getClass(),
				"setRequiredISOLangId",
				1,
				"value",
				value,
				CFSecISOLangBuff.ISOLANGID_MIN_VALUE );
		}
		requiredISOLangId = value;
	}

	public String getRequiredISO6392Code() {
		return( requiredISO6392Code );
	}

	public void setRequiredISO6392Code( String value ) {
		if( value == null ) {
			throw new CFLibNullArgumentException( getClass(),
				"setRequiredISO6392Code",
				1,
				"value" );
		}
		if( value.length() > 3 ) {
			throw new CFLibArgumentOverflowException( getClass(),
				"setRequiredISO6392Code",
				1,
				"value.length()",
				value.length(),
				3 );
		}
		requiredISO6392Code = value;
	}

	public String getOptionalISO6391Code() {
		return( optionalISO6391Code );
	}

	public void setOptionalISO6391Code( String value ) {
		if( value == null ) {
			optionalISO6391Code = null;
		}
		else if( value.length() > 2 ) {
			throw new CFLibArgumentOverflowException( getClass(),
				"setOptionalISO6391Code",
				1,
				"value.length()",
				value.length(),
				2 );
		}
		else {
			optionalISO6391Code = value;
		}
	}

	public String getRequiredEnglishName() {
		return( requiredEnglishName );
	}

	public void setRequiredEnglishName( String value ) {
		if( value == null ) {
			throw new CFLibNullArgumentException( getClass(),
				"setRequiredEnglishName",
				1,
				"value" );
		}
		if( value.length() > 64 ) {
			throw new CFLibArgumentOverflowException( getClass(),
				"setRequiredEnglishName",
				1,
				"value.length()",
				value.length(),
				64 );
		}
		requiredEnglishName = value;
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
		else if( obj instanceof CFSecISOLangBuff ) {
			CFSecISOLangBuff rhs = (CFSecISOLangBuff)obj;
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
			if( getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
				return( false );
			}
			if( ! getRequiredISO6392Code().equals( rhs.getRequiredISO6392Code() ) ) {
				return( false );
			}
			if( getOptionalISO6391Code() != null ) {
				if( rhs.getOptionalISO6391Code() != null ) {
					if( ! getOptionalISO6391Code().equals( rhs.getOptionalISO6391Code() ) ) {
						return( false );
					}
				}
			}
			else {
				if( rhs.getOptionalISO6391Code() != null ) {
					return( false );
				}
			}
			if( ! getRequiredEnglishName().equals( rhs.getRequiredEnglishName() ) ) {
				return( false );
			}
			return( true );
		}
		else if( obj instanceof CFSecISOLangPKey ) {
			CFSecISOLangPKey rhs = (CFSecISOLangPKey)obj;
			if( getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
				return( false );
			}
			return( true );
		}
		else if( obj instanceof CFSecISOLangHBuff ) {
			CFSecISOLangHBuff rhs = (CFSecISOLangHBuff)obj;
			if( getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
				return( false );
			}
			if( ! getRequiredISO6392Code().equals( rhs.getRequiredISO6392Code() ) ) {
				return( false );
			}
			if( getOptionalISO6391Code() != null ) {
				if( rhs.getOptionalISO6391Code() != null ) {
					if( ! getOptionalISO6391Code().equals( rhs.getOptionalISO6391Code() ) ) {
						return( false );
					}
				}
			}
			else {
				if( rhs.getOptionalISO6391Code() != null ) {
					return( false );
				}
			}
			if( ! getRequiredEnglishName().equals( rhs.getRequiredEnglishName() ) ) {
				return( false );
			}
			return( true );
		}
		else if( obj instanceof CFSecISOLangHPKey ) {
			CFSecISOLangHPKey rhs = (CFSecISOLangHPKey)obj;
			if( getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
				return( false );
			}
			return( true );
		}
		else if( obj instanceof CFSecISOLangByCode3IdxKey ) {
			CFSecISOLangByCode3IdxKey rhs = (CFSecISOLangByCode3IdxKey)obj;
			if( ! getRequiredISO6392Code().equals( rhs.getRequiredISO6392Code() ) ) {
				return( false );
			}
			return( true );
		}
		else if( obj instanceof CFSecISOLangByCode2IdxKey ) {
			CFSecISOLangByCode2IdxKey rhs = (CFSecISOLangByCode2IdxKey)obj;
			if( getOptionalISO6391Code() != null ) {
				if( rhs.getOptionalISO6391Code() != null ) {
					if( ! getOptionalISO6391Code().equals( rhs.getOptionalISO6391Code() ) ) {
						return( false );
					}
				}
			}
			else {
				if( rhs.getOptionalISO6391Code() != null ) {
					return( false );
				}
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
		hashCode = ( hashCode * 0x10000 ) + getRequiredISOLangId();
		if( getRequiredISO6392Code() != null ) {
			hashCode = hashCode + getRequiredISO6392Code().hashCode();
		}
		if( getOptionalISO6391Code() != null ) {
			hashCode = hashCode + getOptionalISO6391Code().hashCode();
		}
		if( getRequiredEnglishName() != null ) {
			hashCode = hashCode + getRequiredEnglishName().hashCode();
		}
		return( hashCode & 0x7fffffff );
	}

	public int compareTo( Object obj ) {
		if( obj == null ) {
			return( -1 );
		}
		else if( obj instanceof CFSecISOLangBuff ) {
			CFSecISOLangBuff rhs = (CFSecISOLangBuff)obj;
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
			if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
				return( -1 );
			}
			else if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
				return( 1 );
			}
			{
				int cmp = getRequiredISO6392Code().compareTo( rhs.getRequiredISO6392Code() );
				if( cmp != 0 ) {
					return( cmp );
				}
			}
			if( getOptionalISO6391Code() != null ) {
				if( rhs.getOptionalISO6391Code() != null ) {
					int cmp = getOptionalISO6391Code().compareTo( rhs.getOptionalISO6391Code() );
					if( cmp != 0 ) {
						return( cmp );
					}
				}
				else {
					return( 1 );
				}
			}
			else {
				if( rhs.getOptionalISO6391Code() != null ) {
					return( -1 );
				}
			}
			{
				int cmp = getRequiredEnglishName().compareTo( rhs.getRequiredEnglishName() );
				if( cmp != 0 ) {
					return( cmp );
				}
			}
			return( 0 );
		}
		else if( obj instanceof CFSecISOLangPKey ) {
			CFSecISOLangPKey rhs = (CFSecISOLangPKey)obj;
			if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
				return( -1 );
			}
			else if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
				return( 1 );
			}
			return( 0 );
		}
		else if( obj instanceof CFSecISOLangHPKey ) {
			CFSecISOLangHPKey rhs = (CFSecISOLangHPKey)obj;
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
			if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
				return( -1 );
			}
			else if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
				return( 1 );
			}
			return( 0 );
		}
		else if( obj instanceof CFSecISOLangHBuff ) {
			CFSecISOLangHBuff rhs = (CFSecISOLangHBuff)obj;
			int retval = 0;
			if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
				return( -1 );
			}
			else if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
				return( 1 );
			}
			{
				int cmp = getRequiredISO6392Code().compareTo( rhs.getRequiredISO6392Code() );
				if( cmp != 0 ) {
					return( cmp );
				}
			}
			if( getOptionalISO6391Code() != null ) {
				if( rhs.getOptionalISO6391Code() != null ) {
					int cmp = getOptionalISO6391Code().compareTo( rhs.getOptionalISO6391Code() );
					if( cmp != 0 ) {
						return( cmp );
					}
				}
				else {
					return( 1 );
				}
			}
			else {
				if( rhs.getOptionalISO6391Code() != null ) {
					return( -1 );
				}
			}
			{
				int cmp = getRequiredEnglishName().compareTo( rhs.getRequiredEnglishName() );
				if( cmp != 0 ) {
					return( cmp );
				}
			}
			return( 0 );
		}
		else if( obj instanceof CFSecISOLangByCode3IdxKey ) {
			CFSecISOLangByCode3IdxKey rhs = (CFSecISOLangByCode3IdxKey)obj;

			{
				int cmp = getRequiredISO6392Code().compareTo( rhs.getRequiredISO6392Code() );
				if( cmp != 0 ) {
					return( cmp );
				}
			}			return( 0 );
		}
		else if( obj instanceof CFSecISOLangByCode2IdxKey ) {
			CFSecISOLangByCode2IdxKey rhs = (CFSecISOLangByCode2IdxKey)obj;

			if( getOptionalISO6391Code() != null ) {
				if( rhs.getOptionalISO6391Code() != null ) {
					int cmp = getOptionalISO6391Code().compareTo( rhs.getOptionalISO6391Code() );
					if( cmp != 0 ) {
						return( cmp );
					}
				}
				else {
					return( 1 );
				}
			}
			else {
				if( rhs.getOptionalISO6391Code() != null ) {
					return( -1 );
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

	public void set( CFSecISOLangBuff src ) {
		setISOLangBuff( src );
	}

	public void setISOLangBuff( CFSecISOLangBuff src ) {
		setRequiredISOLangId( src.getRequiredISOLangId() );
		setCreatedByUserId( src.getCreatedByUserId() );
		setCreatedAt( src.getCreatedAt() );
		setUpdatedByUserId( src.getUpdatedByUserId() );
		setUpdatedAt( src.getUpdatedAt() );
		setRequiredISO6392Code( src.getRequiredISO6392Code() );
		setOptionalISO6391Code( src.getOptionalISO6391Code() );
		setRequiredEnglishName( src.getRequiredEnglishName() );
		setRequiredRevision( src.getRequiredRevision() );
	}

	public void set( CFSecISOLangHBuff src ) {
		setISOLangBuff( src );
	}

	public void setISOLangBuff( CFSecISOLangHBuff src ) {
		setRequiredISOLangId( src.getRequiredISOLangId() );
		setRequiredISO6392Code( src.getRequiredISO6392Code() );
		setOptionalISO6391Code( src.getOptionalISO6391Code() );
		setRequiredEnglishName( src.getRequiredEnglishName() );
	}
}
