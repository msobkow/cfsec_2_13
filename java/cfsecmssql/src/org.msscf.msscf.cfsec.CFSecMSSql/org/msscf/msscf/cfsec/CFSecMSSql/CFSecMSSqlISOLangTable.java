// Description: Java 11 MS SQL Server Developer Edition Jdbc DbIO implementation for ISOLang.

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

package org.msscf.msscf.cfsec.CFSecMSSql;

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.apache.commons.codec.binary.Base64;
import org.msscf.msscf.cflib.CFLib.*;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfsec.CFSecObj.*;

/*
 *	CFSecMSSqlISOLangTable PostgreSQL Jdbc DbIO implementation
 *	for ISOLang.
 */
public class CFSecMSSqlISOLangTable
	implements ICFSecISOLangTable
{
	private CFSecMSSqlSchema schema;
	protected PreparedStatement stmtReadBuffByPKey = null;
	protected PreparedStatement stmtLockBuffByPKey = null;
	protected PreparedStatement stmtCreateByPKey = null;
	protected PreparedStatement stmtUpdateByPKey = null;
	protected PreparedStatement stmtDeleteByPKey = null;
	protected PreparedStatement stmtReadAllBuff = null;
	protected PreparedStatement stmtReadBuffByIdIdx = null;
	protected PreparedStatement stmtReadBuffByCode3Idx = null;
	protected PreparedStatement stmtReadBuffByCode2Idx = null;
	protected PreparedStatement stmtDeleteByIdIdx = null;
	protected PreparedStatement stmtDeleteByCode3Idx = null;
	protected PreparedStatement stmtDeleteByCode2Idx = null;

	public CFSecMSSqlISOLangTable( CFSecMSSqlSchema argSchema ) {
		schema = argSchema;
	}

	public void createISOLang( CFSecAuthorization Authorization,
		CFSecISOLangBuff Buff )
	{
		final String S_ProcName = "createISOLang";
		if( ! schema.isTransactionOpen() ) {
			throw new CFLibUsageException( getClass(),
				S_ProcName,
				"Transaction not open" );
		}
		ResultSet resultSet = null;
		try {
			String ISO6392Code = Buff.getRequiredISO6392Code();
			String ISO6391Code = Buff.getOptionalISO6391Code();
			String EnglishName = Buff.getRequiredEnglishName();
			Connection cnx = schema.getCnx();
			String sql =
				"exec sp_create_iso_lang ?, ?, ?, ?, ?, ?" + ", "
				+		"?" + ", "
				+		"?" + ", "
				+		"?";
			if( stmtCreateByPKey == null ) {
				stmtCreateByPKey = cnx.prepareStatement( sql );
			}
			int argIdx = 1;
			stmtCreateByPKey.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtCreateByPKey.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecUserId().toString() );
			stmtCreateByPKey.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecSessionId().toString() );
			stmtCreateByPKey.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtCreateByPKey.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecTenantId() );
			stmtCreateByPKey.setString( argIdx++, "a007" );
			stmtCreateByPKey.setString( argIdx++, ISO6392Code );
			if( ISO6391Code != null ) {
				stmtCreateByPKey.setString( argIdx++, ISO6391Code );
			}
			else {
				stmtCreateByPKey.setNull( argIdx++, java.sql.Types.VARCHAR );
			}
			stmtCreateByPKey.setString( argIdx++, EnglishName );
			stmtCreateByPKey.execute();
			boolean moreResults = true;
			resultSet = null;
			while( resultSet == null ) {
				try {
					moreResults = stmtCreateByPKey.getMoreResults();
				}
				catch( SQLException e ) {
					throw new CFLibDbException( getClass(),
						S_ProcName,
						e );
				}
				if( moreResults ) {
					try {
						resultSet = stmtCreateByPKey.getResultSet();
					}
					catch( SQLException e ) {
					}
				}
				else if( -1 == stmtCreateByPKey.getUpdateCount() ) {
					break;
				}
			}
			if( resultSet == null ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"resultSet" );
			}
			if( resultSet.next() ) {
				CFSecISOLangBuff createdBuff = unpackISOLangResultSetToBuff( resultSet );
				if( resultSet.next() ) {
					resultSet.last();
					throw new CFLibRuntimeException( getClass(),
						S_ProcName,
						"Did not expect multi-record response, " + resultSet.getRow() + " rows selected" );
				}
				Buff.setRequiredISOLangId( createdBuff.getRequiredISOLangId() );
				Buff.setRequiredISO6392Code( createdBuff.getRequiredISO6392Code() );
				Buff.setOptionalISO6391Code( createdBuff.getOptionalISO6391Code() );
				Buff.setRequiredEnglishName( createdBuff.getRequiredEnglishName() );
				Buff.setRequiredRevision( createdBuff.getRequiredRevision() );
				Buff.setCreatedByUserId( createdBuff.getCreatedByUserId() );
				Buff.setCreatedAt( createdBuff.getCreatedAt() );
				Buff.setUpdatedByUserId( createdBuff.getUpdatedByUserId() );
				Buff.setUpdatedAt( createdBuff.getUpdatedAt() );
			}
			else {
				throw new CFLibRuntimeException( getClass(),
					S_ProcName,
					"Expected a single-record response, " + resultSet.getRow() + " rows selected" );
			}
		}
		catch( SQLException e ) {
			throw new CFLibDbException( getClass(),
				S_ProcName,
				e );
		}
		finally {
			if( resultSet != null ) {
				try {
					resultSet.close();
				}
				catch( SQLException e ) {
				}
				resultSet = null;
			}
		}
	}

	protected static String S_sqlSelectISOLangDistinctClassCode = null;

	public String getSqlSelectISOLangDistinctClassCode() {
		if( S_sqlSelectISOLangDistinctClassCode == null ) {
			S_sqlSelectISOLangDistinctClassCode =
					"SELECT "
				+		"DISTINCT a007.ClassCode "
				+	"FROM " + schema.getLowerDbSchemaName() + "..iso_lang AS a007 ";
		}
		return( S_sqlSelectISOLangDistinctClassCode );
	}

	protected static String S_sqlSelectISOLangBuff = null;

	public String getSqlSelectISOLangBuff() {
		if( S_sqlSelectISOLangBuff == null ) {
			S_sqlSelectISOLangBuff =
					"SELECT "
				+		"a007.isolangid, "
				+		"a007.iso_code3, "
				+		"a007.iso_code2, "
				+		"a007.eng_name, "
				+		"a007.revision "
				+	"FROM " + schema.getLowerDbSchemaName() + "..iso_lang AS a007 ";
		}
		return( S_sqlSelectISOLangBuff );
	}

	protected CFSecISOLangBuff unpackISOLangResultSetToBuff( ResultSet resultSet )
	throws SQLException
	{
		final String S_ProcName = "unpackISOLangResultSetToBuff";
		int idxcol = 1;
		CFSecISOLangBuff buff = schema.getFactoryISOLang().newBuff();
		{
			String colString = resultSet.getString( idxcol );
			if( resultSet.wasNull() ) {
				buff.setCreatedByUserId( null );
			}
			else if( ( colString == null ) || ( colString.length() <= 0 ) ) {
				buff.setCreatedByUserId( null );
			}
			else {
				buff.setCreatedByUserId( UUID.fromString( colString ) );
			}
			idxcol ++;

			colString = resultSet.getString( idxcol );
			if( resultSet.wasNull() ) {
				buff.setCreatedAt( null );
			}
			else if( ( colString == null ) || ( colString.length() <= 0 ) ) {
				buff.setCreatedAt( null );
			}
			else {
				buff.setCreatedAt( CFSecMSSqlSchema.convertTimestampString( colString ) );
			}
			idxcol++;
			colString = resultSet.getString( idxcol );
			if( resultSet.wasNull() ) {
				buff.setUpdatedByUserId( null );
			}
			else if( ( colString == null ) || ( colString.length() <= 0 ) ) {
				buff.setUpdatedByUserId( null );
			}
			else {
				buff.setUpdatedByUserId( UUID.fromString( colString ) );
			}
			idxcol ++;

			colString = resultSet.getString( idxcol );
			if( resultSet.wasNull() ) {
				buff.setUpdatedAt( null );
			}
			else if( ( colString == null ) || ( colString.length() <= 0 ) ) {
				buff.setUpdatedAt( null );
			}
			else {
				buff.setUpdatedAt( CFSecMSSqlSchema.convertTimestampString( colString ) );
			}
			idxcol++;
		}
		buff.setRequiredISOLangId( resultSet.getShort( idxcol ) );
		idxcol++;
		buff.setRequiredISO6392Code( resultSet.getString( idxcol ) );
		idxcol++;
		{
			String colVal = resultSet.getString( idxcol );
			if( resultSet.wasNull() ) {
				buff.setOptionalISO6391Code( null );
			}
			else {
				buff.setOptionalISO6391Code( colVal );
			}
		}
		idxcol++;
		buff.setRequiredEnglishName( resultSet.getString( idxcol ) );
		idxcol++;
		buff.setRequiredRevision( resultSet.getInt( idxcol ) );
		return( buff );
	}

	public CFSecISOLangBuff readDerived( CFSecAuthorization Authorization,
		CFSecISOLangPKey PKey )
	{
		final String S_ProcName = "readDerived";
		if( ! schema.isTransactionOpen() ) {
			throw new CFLibUsageException( getClass(),
				S_ProcName,
				"Transaction not open" );
		}
		CFSecISOLangBuff buff;
		buff = readBuff( Authorization, PKey );
		return( buff );
	}

	public CFSecISOLangBuff lockDerived( CFSecAuthorization Authorization,
		CFSecISOLangPKey PKey )
	{
		final String S_ProcName = "lockDerived";
		if( ! schema.isTransactionOpen() ) {
			throw new CFLibUsageException( getClass(),
				S_ProcName,
				"Transaction not open" );
		}
		CFSecISOLangBuff buff;
		buff = lockBuff( Authorization, PKey );
		return( buff );
	}

	public CFSecISOLangBuff[] readAllDerived( CFSecAuthorization Authorization ) {
		final String S_ProcName = "readAllDerived";
		CFSecISOLangBuff[] buffArray;
		if( ! schema.isTransactionOpen() ) {
			throw new CFLibUsageException( getClass(),
				S_ProcName,
				"Transaction not open" );
		}
		buffArray = readAllBuff( Authorization );
		return( buffArray );
	}

	public CFSecISOLangBuff readDerivedByIdIdx( CFSecAuthorization Authorization,
		short ISOLangId )
	{
		final String S_ProcName = "CFSecMSSqlISOLangTable.readDerivedByIdIdx() ";
		CFSecISOLangBuff buff;
		if( ! schema.isTransactionOpen() ) {
			throw new CFLibUsageException( getClass(),
				S_ProcName,
				"Transaction not open" );
		}
		buff = readBuffByIdIdx( Authorization,
				ISOLangId );
		return( buff );
	}

	public CFSecISOLangBuff readDerivedByCode3Idx( CFSecAuthorization Authorization,
		String ISO6392Code )
	{
		final String S_ProcName = "CFSecMSSqlISOLangTable.readDerivedByCode3Idx() ";
		CFSecISOLangBuff buff;
		if( ! schema.isTransactionOpen() ) {
			throw new CFLibUsageException( getClass(),
				S_ProcName,
				"Transaction not open" );
		}
		buff = readBuffByCode3Idx( Authorization,
				ISO6392Code );
		return( buff );
	}

	public CFSecISOLangBuff[] readDerivedByCode2Idx( CFSecAuthorization Authorization,
		String ISO6391Code )
	{
		final String S_ProcName = "readDerivedByCode2Idx";
		if( ! schema.isTransactionOpen() ) {
			throw new CFLibUsageException( getClass(),
				S_ProcName,
				"Transaction not open" );
		}
		CFSecISOLangBuff[] buffList = readBuffByCode2Idx( Authorization,
				ISO6391Code );
		return( buffList );

	}

	public CFSecISOLangBuff readBuff( CFSecAuthorization Authorization,
		CFSecISOLangPKey PKey )
	{
		final String S_ProcName = "readBuff";
		if( ! schema.isTransactionOpen() ) {
			throw new CFLibUsageException( getClass(),
				S_ProcName,
				"Transaction not open" );
		}
		ResultSet resultSet = null;
		try {
			Connection cnx = schema.getCnx();
			short ISOLangId = PKey.getRequiredISOLangId();
			String sql = "{ call sp_read_iso_lang( ?, ?, ?, ?, ?" + ", "
				+		"?" + " ) }";
			if( stmtReadBuffByPKey == null ) {
				stmtReadBuffByPKey = cnx.prepareStatement( sql );
			}
			int argIdx = 1;
			stmtReadBuffByPKey.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtReadBuffByPKey.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecUserId().toString() );
			stmtReadBuffByPKey.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecSessionId().toString() );
			stmtReadBuffByPKey.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtReadBuffByPKey.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecTenantId() );
			stmtReadBuffByPKey.setShort( argIdx++, ISOLangId );
			resultSet = stmtReadBuffByPKey.executeQuery();
			if( ( resultSet != null ) && resultSet.next() ) {
				CFSecISOLangBuff buff = unpackISOLangResultSetToBuff( resultSet );
				if( resultSet.next() ) {
					resultSet.last();
					throw new CFLibRuntimeException( getClass(),
						S_ProcName,
						"Did not expect multi-record response, " + resultSet.getRow() + " rows selected" );
				}
				return( buff );
			}
			else {
				return( null );
			}
		}
		catch( SQLException e ) {
			throw new CFLibDbException( getClass(),
				S_ProcName,
				e );
		}
		finally {
			if( resultSet != null ) {
				try {
					resultSet.close();
				}
				catch( SQLException e ) {
				}
				resultSet = null;
			}
		}
	}

	public CFSecISOLangBuff lockBuff( CFSecAuthorization Authorization,
		CFSecISOLangPKey PKey )
	{
		final String S_ProcName = "lockBuff";
		if( ! schema.isTransactionOpen() ) {
			throw new CFLibUsageException( getClass(),
				S_ProcName,
				"Transaction not open" );
		}
		ResultSet resultSet = null;
		try {
			Connection cnx = schema.getCnx();
			short ISOLangId = PKey.getRequiredISOLangId();
			String sql = "{ call sp_lock_iso_lang( ?, ?, ?, ?, ?" + ", "
				+		"?" + " ) }";
			if( stmtLockBuffByPKey == null ) {
				stmtLockBuffByPKey = cnx.prepareStatement( sql );
			}
			int argIdx = 1;
			stmtLockBuffByPKey.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtLockBuffByPKey.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecUserId().toString() );
			stmtLockBuffByPKey.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecSessionId().toString() );
			stmtLockBuffByPKey.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtLockBuffByPKey.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecTenantId() );
			stmtLockBuffByPKey.setShort( argIdx++, ISOLangId );
			stmtLockBuffByPKey.execute();
			boolean moreResults = true;
			resultSet = null;
			while( resultSet == null ) {
				try {
					moreResults = stmtLockBuffByPKey.getMoreResults();
				}
				catch( SQLException e ) {
					throw new CFLibDbException( getClass(),
						S_ProcName,
						e );
				}
				if( moreResults ) {
					try {
						resultSet = stmtLockBuffByPKey.getResultSet();
					}
					catch( SQLException e ) {
					}
				}
				else if( -1 == stmtLockBuffByPKey.getUpdateCount() ) {
					break;
				}
			}
			if( ( resultSet != null ) && resultSet.next() ) {
				CFSecISOLangBuff buff = unpackISOLangResultSetToBuff( resultSet );
				if( resultSet.next() ) {
					resultSet.last();
					throw new CFLibRuntimeException( getClass(),
						S_ProcName,
						"Did not expect multi-record response, " + resultSet.getRow() + " rows selected" );
				}
				return( buff );
			}
			else {
				return( null );
			}
		}
		catch( SQLException e ) {
			throw new CFLibDbException( getClass(),
				S_ProcName,
				e );
		}
		finally {
			if( resultSet != null ) {
				try {
					resultSet.close();
				}
				catch( SQLException e ) {
				}
				resultSet = null;
			}
		}
	}

	public CFSecISOLangBuff[] readAllBuff( CFSecAuthorization Authorization ) {
		final String S_ProcName = "readAllBuff";
		if( ! schema.isTransactionOpen() ) {
			throw new CFLibUsageException( getClass(),
				S_ProcName,
				"Transaction not open" );
		}
		ResultSet resultSet = null;
		try {
			Connection cnx = schema.getCnx();
			String sql = "{ call sp_read_iso_lang_all( ?, ?, ?, ?, ? ) }";
			if( stmtReadAllBuff == null ) {
				stmtReadAllBuff = cnx.prepareStatement( sql );
			}
			int argIdx = 1;
			stmtReadAllBuff.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtReadAllBuff.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecUserId().toString() );
			stmtReadAllBuff.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecSessionId().toString() );
			stmtReadAllBuff.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtReadAllBuff.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecTenantId() );
			resultSet = stmtReadAllBuff.executeQuery();
			List<CFSecISOLangBuff> buffList = new LinkedList<CFSecISOLangBuff>();
			if( resultSet != null ) {
				while( resultSet.next() ) {
					CFSecISOLangBuff buff = unpackISOLangResultSetToBuff( resultSet );
					buffList.add( buff );
				}
			}
			int idx = 0;
			CFSecISOLangBuff[] retBuff = new CFSecISOLangBuff[ buffList.size() ];
			Iterator<CFSecISOLangBuff> iter = buffList.iterator();
			while( iter.hasNext() ) {
				retBuff[idx++] = iter.next();
			}
			return( retBuff );
		}
		catch( SQLException e ) {
			throw new CFLibDbException( getClass(),
				S_ProcName,
				e );
		}
		finally {
			if( resultSet != null ) {
				try {
					resultSet.close();
				}
				catch( SQLException e ) {
				}
				resultSet = null;
			}
		}
	}

	public CFSecISOLangBuff readBuffByIdIdx( CFSecAuthorization Authorization,
		short ISOLangId )
	{
		final String S_ProcName = "readBuffByIdIdx";
		ResultSet resultSet = null;
		try {
			Connection cnx = schema.getCnx();
			String sql = "{ call sp_read_iso_lang_by_ididx( ?, ?, ?, ?, ?" + ", "
				+		"?" + " ) }";
			if( stmtReadBuffByIdIdx == null ) {
				stmtReadBuffByIdIdx = cnx.prepareStatement( sql );
			}
			int argIdx = 1;
			stmtReadBuffByIdIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtReadBuffByIdIdx.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecUserId().toString() );
			stmtReadBuffByIdIdx.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecSessionId().toString() );
			stmtReadBuffByIdIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtReadBuffByIdIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecTenantId() );
			stmtReadBuffByIdIdx.setShort( argIdx++, ISOLangId );
			resultSet = stmtReadBuffByIdIdx.executeQuery();
			if( ( resultSet != null ) && resultSet.next() ) {
				CFSecISOLangBuff buff = unpackISOLangResultSetToBuff( resultSet );
				if( resultSet.next() ) {
					resultSet.last();
					throw new CFLibRuntimeException( getClass(),
						S_ProcName,
						"Did not expect multi-record response, " + resultSet.getRow() + " rows selected" );
				}
				return( buff );
			}
			else {
				return( null );
			}
		}
		catch( SQLException e ) {
			throw new CFLibDbException( getClass(),
				S_ProcName,
				e );
		}
		finally {
			if( resultSet != null ) {
				try {
					resultSet.close();
				}
				catch( SQLException e ) {
				}
				resultSet = null;
			}
		}
	}

	public CFSecISOLangBuff readBuffByCode3Idx( CFSecAuthorization Authorization,
		String ISO6392Code )
	{
		final String S_ProcName = "readBuffByCode3Idx";
		ResultSet resultSet = null;
		try {
			Connection cnx = schema.getCnx();
			String sql = "{ call sp_read_iso_lang_by_code3idx( ?, ?, ?, ?, ?" + ", "
				+		"?" + " ) }";
			if( stmtReadBuffByCode3Idx == null ) {
				stmtReadBuffByCode3Idx = cnx.prepareStatement( sql );
			}
			int argIdx = 1;
			stmtReadBuffByCode3Idx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtReadBuffByCode3Idx.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecUserId().toString() );
			stmtReadBuffByCode3Idx.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecSessionId().toString() );
			stmtReadBuffByCode3Idx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtReadBuffByCode3Idx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecTenantId() );
			stmtReadBuffByCode3Idx.setString( argIdx++, ISO6392Code );
			resultSet = stmtReadBuffByCode3Idx.executeQuery();
			if( ( resultSet != null ) && resultSet.next() ) {
				CFSecISOLangBuff buff = unpackISOLangResultSetToBuff( resultSet );
				if( resultSet.next() ) {
					resultSet.last();
					throw new CFLibRuntimeException( getClass(),
						S_ProcName,
						"Did not expect multi-record response, " + resultSet.getRow() + " rows selected" );
				}
				return( buff );
			}
			else {
				return( null );
			}
		}
		catch( SQLException e ) {
			throw new CFLibDbException( getClass(),
				S_ProcName,
				e );
		}
		finally {
			if( resultSet != null ) {
				try {
					resultSet.close();
				}
				catch( SQLException e ) {
				}
				resultSet = null;
			}
		}
	}

	public CFSecISOLangBuff[] readBuffByCode2Idx( CFSecAuthorization Authorization,
		String ISO6391Code )
	{
		final String S_ProcName = "readBuffByCode2Idx";
		ResultSet resultSet = null;
		try {
			Connection cnx = schema.getCnx();
			String sql = "{ call sp_read_iso_lang_by_code2idx( ?, ?, ?, ?, ?" + ", "
				+		"?" + " ) }";
			if( stmtReadBuffByCode2Idx == null ) {
				stmtReadBuffByCode2Idx = cnx.prepareStatement( sql );
			}
			int argIdx = 1;
			stmtReadBuffByCode2Idx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtReadBuffByCode2Idx.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecUserId().toString() );
			stmtReadBuffByCode2Idx.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecSessionId().toString() );
			stmtReadBuffByCode2Idx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtReadBuffByCode2Idx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecTenantId() );
			if( ISO6391Code != null ) {
				stmtReadBuffByCode2Idx.setString( argIdx++, ISO6391Code );
			}
			else {
				stmtReadBuffByCode2Idx.setNull( argIdx++, java.sql.Types.VARCHAR );
			}
			resultSet = stmtReadBuffByCode2Idx.executeQuery();
			List<CFSecISOLangBuff> buffList = new LinkedList<CFSecISOLangBuff>();
			if( resultSet != null ) {
				while( resultSet.next() ) {
					CFSecISOLangBuff buff = unpackISOLangResultSetToBuff( resultSet );
					buffList.add( buff );
				}
			}
			int idx = 0;
			CFSecISOLangBuff[] retBuff = new CFSecISOLangBuff[ buffList.size() ];
			Iterator<CFSecISOLangBuff> iter = buffList.iterator();
			while( iter.hasNext() ) {
				retBuff[idx++] = iter.next();
			}
			return( retBuff );
		}
		catch( SQLException e ) {
			throw new CFLibDbException( getClass(),
				S_ProcName,
				e );
		}
		finally {
			if( resultSet != null ) {
				try {
					resultSet.close();
				}
				catch( SQLException e ) {
				}
				resultSet = null;
			}
		}
	}

	public void updateISOLang( CFSecAuthorization Authorization,
		CFSecISOLangBuff Buff )
	{
		final String S_ProcName = "updateISOLang";
		ResultSet resultSet = null;
		try {
			short ISOLangId = Buff.getRequiredISOLangId();
			String ISO6392Code = Buff.getRequiredISO6392Code();
			String ISO6391Code = Buff.getOptionalISO6391Code();
			String EnglishName = Buff.getRequiredEnglishName();
			int Revision = Buff.getRequiredRevision();
			Connection cnx = schema.getCnx();
			String sql =
				"exec sp_update_iso_lang ?, ?, ?, ?, ?, ?" + ", "
					+	"?" + ", "
					+	"?" + ", "
					+	"?" + ", "
					+	"?" + ", "
					+ "?";
			if( stmtUpdateByPKey == null ) {
				stmtUpdateByPKey = cnx.prepareStatement( sql );
			}
			int argIdx = 1;
			stmtUpdateByPKey.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtUpdateByPKey.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecUserId().toString() );
			stmtUpdateByPKey.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecSessionId().toString() );
			stmtUpdateByPKey.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtUpdateByPKey.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecTenantId() );
			stmtUpdateByPKey.setString( argIdx++, "a007" );
			stmtUpdateByPKey.setShort( argIdx++, ISOLangId );
			stmtUpdateByPKey.setString( argIdx++, ISO6392Code );
			if( ISO6391Code != null ) {
				stmtUpdateByPKey.setString( argIdx++, ISO6391Code );
			}
			else {
				stmtUpdateByPKey.setNull( argIdx++, java.sql.Types.VARCHAR );
			}
			stmtUpdateByPKey.setString( argIdx++, EnglishName );
			stmtUpdateByPKey.setInt( argIdx++, Revision );
			stmtUpdateByPKey.execute();
			boolean moreResults = true;
			resultSet = null;
			while( resultSet == null ) {
				try {
					moreResults = stmtUpdateByPKey.getMoreResults();
				}
				catch( SQLException e ) {
					throw new CFLibDbException( getClass(),
						S_ProcName,
						e );
				}
				if( moreResults ) {
					try {
						resultSet = stmtUpdateByPKey.getResultSet();
					}
					catch( SQLException e ) {
					}
				}
				else if( -1 == stmtUpdateByPKey.getUpdateCount() ) {
					break;
				}
			}
			if( resultSet == null ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"resultSet" );
			}
			if( resultSet.next() ) {
				CFSecISOLangBuff updatedBuff = unpackISOLangResultSetToBuff( resultSet );
				if( resultSet.next() ) {
					resultSet.last();
					throw new CFLibRuntimeException( getClass(),
						S_ProcName,
						"Did not expect multi-record response, " + resultSet.getRow() + " rows selected" );
				}
				Buff.setRequiredISO6392Code( updatedBuff.getRequiredISO6392Code() );
				Buff.setOptionalISO6391Code( updatedBuff.getOptionalISO6391Code() );
				Buff.setRequiredEnglishName( updatedBuff.getRequiredEnglishName() );
				Buff.setRequiredRevision( updatedBuff.getRequiredRevision() );
			}
			else {
				throw new CFLibRuntimeException( getClass(),
					S_ProcName,
					"Expected a single-record response, " + resultSet.getRow() + " rows selected" );
			}
		}
		catch( SQLException e ) {
			throw new CFLibDbException( getClass(),
				S_ProcName,
				e );
		}
		finally {
			if( resultSet != null ) {
				try {
					resultSet.close();
				}
				catch( SQLException e ) {
				}
				resultSet = null;
			}
		}
	}

	public void deleteISOLang( CFSecAuthorization Authorization,
		CFSecISOLangBuff Buff )
	{
		final String S_ProcName = "deleteISOLang";
		try {
			Connection cnx = schema.getCnx();
			short ISOLangId = Buff.getRequiredISOLangId();

			String sql = "exec sp_delete_iso_lang ?, ?, ?, ?, ?" + ", "
				+		"?" + ", "
				+		"?";
			if( stmtDeleteByPKey == null ) {
				stmtDeleteByPKey = cnx.prepareStatement( sql );
			}
			int argIdx = 1;
			stmtDeleteByPKey.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtDeleteByPKey.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecUserId().toString() );
			stmtDeleteByPKey.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecSessionId().toString() );
			stmtDeleteByPKey.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtDeleteByPKey.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecTenantId() );
			stmtDeleteByPKey.setShort( argIdx++, ISOLangId );
			stmtDeleteByPKey.setInt( argIdx++, Buff.getRequiredRevision() );;
			Object stuff = null;
			boolean moreResults = stmtDeleteByPKey.execute();
			while( stuff == null ) {
				try {
					moreResults = stmtDeleteByPKey.getMoreResults();
				}
				catch( SQLException e ) {
					throw new CFLibDbException( getClass(),
						S_ProcName,
						e );
				}
				if( moreResults ) {
					try {
						stuff = stmtDeleteByPKey.getResultSet();
					}
					catch( SQLException e ) {
					}
				}
				else if( -1 == stmtDeleteByPKey.getUpdateCount() ) {
					break;
				}
			}
		}
		catch( SQLException e ) {
			throw new CFLibDbException( getClass(),
				S_ProcName,
				e );
		}
	}

	public void deleteISOLangByIdIdx( CFSecAuthorization Authorization,
		short argISOLangId )
	{
		final String S_ProcName = "deleteISOLangByIdIdx";
		if( ! schema.isTransactionOpen() ) {
			throw new CFLibUsageException( getClass(),
				S_ProcName,
				"Transaction not open" );
		}
		ResultSet resultSet = null;
		try {
			Connection cnx = schema.getCnx();
			String sql = "exec sp_delete_iso_lang_by_ididx ?, ?, ?, ?, ?" + ", "
				+		"?";
			if( stmtDeleteByIdIdx== null ) {
				stmtDeleteByIdIdx = cnx.prepareStatement( sql );
			}
			int argIdx = 1;
			stmtDeleteByIdIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtDeleteByIdIdx.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecUserId().toString() );
			stmtDeleteByIdIdx.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecSessionId().toString() );
			stmtDeleteByIdIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtDeleteByIdIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecTenantId() );
			stmtDeleteByIdIdx.setShort( argIdx++, argISOLangId );
			Object stuff = null;
			boolean moreResults = stmtDeleteByIdIdx.execute();
			while( stuff == null ) {
				try {
					moreResults = stmtDeleteByIdIdx.getMoreResults();
				}
				catch( SQLException e ) {
					throw new CFLibDbException( getClass(),
						S_ProcName,
						e );
				}
				if( moreResults ) {
					try {
						stuff = stmtDeleteByIdIdx.getResultSet();
					}
					catch( SQLException e ) {
					}
				}
				else if( -1 == stmtDeleteByIdIdx.getUpdateCount() ) {
					break;
				}
			}
		}
		catch( SQLException e ) {
			throw new CFLibDbException( getClass(),
				S_ProcName,
				e );
		}
		finally {
			if( resultSet != null ) {
				try {
					resultSet.close();
				}
				catch( SQLException e ) {
				}
				resultSet = null;
			}
		}
	}

	public void deleteISOLangByIdIdx( CFSecAuthorization Authorization,
		CFSecISOLangPKey argKey )
	{
		deleteISOLangByIdIdx( Authorization,
			argKey.getRequiredISOLangId() );
	}

	public void deleteISOLangByCode3Idx( CFSecAuthorization Authorization,
		String argISO6392Code )
	{
		final String S_ProcName = "deleteISOLangByCode3Idx";
		if( ! schema.isTransactionOpen() ) {
			throw new CFLibUsageException( getClass(),
				S_ProcName,
				"Transaction not open" );
		}
		ResultSet resultSet = null;
		try {
			Connection cnx = schema.getCnx();
			String sql = "exec sp_delete_iso_lang_by_code3idx ?, ?, ?, ?, ?" + ", "
				+		"?";
			if( stmtDeleteByCode3Idx== null ) {
				stmtDeleteByCode3Idx = cnx.prepareStatement( sql );
			}
			int argIdx = 1;
			stmtDeleteByCode3Idx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtDeleteByCode3Idx.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecUserId().toString() );
			stmtDeleteByCode3Idx.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecSessionId().toString() );
			stmtDeleteByCode3Idx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtDeleteByCode3Idx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecTenantId() );
			stmtDeleteByCode3Idx.setString( argIdx++, argISO6392Code );
			Object stuff = null;
			boolean moreResults = stmtDeleteByCode3Idx.execute();
			while( stuff == null ) {
				try {
					moreResults = stmtDeleteByCode3Idx.getMoreResults();
				}
				catch( SQLException e ) {
					throw new CFLibDbException( getClass(),
						S_ProcName,
						e );
				}
				if( moreResults ) {
					try {
						stuff = stmtDeleteByCode3Idx.getResultSet();
					}
					catch( SQLException e ) {
					}
				}
				else if( -1 == stmtDeleteByCode3Idx.getUpdateCount() ) {
					break;
				}
			}
		}
		catch( SQLException e ) {
			throw new CFLibDbException( getClass(),
				S_ProcName,
				e );
		}
		finally {
			if( resultSet != null ) {
				try {
					resultSet.close();
				}
				catch( SQLException e ) {
				}
				resultSet = null;
			}
		}
	}

	public void deleteISOLangByCode3Idx( CFSecAuthorization Authorization,
		CFSecISOLangByCode3IdxKey argKey )
	{
		deleteISOLangByCode3Idx( Authorization,
			argKey.getRequiredISO6392Code() );
	}

	public void deleteISOLangByCode2Idx( CFSecAuthorization Authorization,
		String argISO6391Code )
	{
		final String S_ProcName = "deleteISOLangByCode2Idx";
		if( ! schema.isTransactionOpen() ) {
			throw new CFLibUsageException( getClass(),
				S_ProcName,
				"Transaction not open" );
		}
		ResultSet resultSet = null;
		try {
			Connection cnx = schema.getCnx();
			String sql = "exec sp_delete_iso_lang_by_code2idx ?, ?, ?, ?, ?" + ", "
				+		"?";
			if( stmtDeleteByCode2Idx== null ) {
				stmtDeleteByCode2Idx = cnx.prepareStatement( sql );
			}
			int argIdx = 1;
			stmtDeleteByCode2Idx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtDeleteByCode2Idx.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecUserId().toString() );
			stmtDeleteByCode2Idx.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecSessionId().toString() );
			stmtDeleteByCode2Idx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtDeleteByCode2Idx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecTenantId() );
			if( argISO6391Code != null ) {
				stmtDeleteByCode2Idx.setString( argIdx++, argISO6391Code );
			}
			else {
				stmtDeleteByCode2Idx.setNull( argIdx++, java.sql.Types.VARCHAR );
			}
			Object stuff = null;
			boolean moreResults = stmtDeleteByCode2Idx.execute();
			while( stuff == null ) {
				try {
					moreResults = stmtDeleteByCode2Idx.getMoreResults();
				}
				catch( SQLException e ) {
					throw new CFLibDbException( getClass(),
						S_ProcName,
						e );
				}
				if( moreResults ) {
					try {
						stuff = stmtDeleteByCode2Idx.getResultSet();
					}
					catch( SQLException e ) {
					}
				}
				else if( -1 == stmtDeleteByCode2Idx.getUpdateCount() ) {
					break;
				}
			}
		}
		catch( SQLException e ) {
			throw new CFLibDbException( getClass(),
				S_ProcName,
				e );
		}
		finally {
			if( resultSet != null ) {
				try {
					resultSet.close();
				}
				catch( SQLException e ) {
				}
				resultSet = null;
			}
		}
	}

	public void deleteISOLangByCode2Idx( CFSecAuthorization Authorization,
		CFSecISOLangByCode2IdxKey argKey )
	{
		deleteISOLangByCode2Idx( Authorization,
			argKey.getOptionalISO6391Code() );
	}

	/**
	 *	Release the prepared statements.
	 *	<p>
	 *	When the schema changes connections, the prepared statements
	 *	have to be released because they contain connection-specific
	 *	information for most databases.
	 */
	public void releasePreparedStatements() {
		final String S_ProcName = "releasePreparedStatements";
		S_sqlSelectISOLangDistinctClassCode = null;
		S_sqlSelectISOLangBuff = null;
		if( stmtReadBuffByPKey != null ) {
			try {
				stmtReadBuffByPKey.close();
			}
			catch( SQLException e ) {
			}
			stmtReadBuffByPKey = null;
		}
		if( stmtLockBuffByPKey != null ) {
			try {
				stmtLockBuffByPKey.close();
			}
			catch( SQLException e ) {
			}
			stmtLockBuffByPKey = null;
		}
		if( stmtCreateByPKey != null ) {
			try {
				stmtCreateByPKey.close();
			}
			catch( SQLException e ) {
			}
			stmtCreateByPKey = null;
		}
		if( stmtUpdateByPKey != null ) {
			try {
				stmtUpdateByPKey.close();
			}
			catch( SQLException e ) {
			}
			stmtUpdateByPKey = null;
		}
		if( stmtDeleteByPKey != null ) {
			try {
				stmtDeleteByPKey.close();
			}
			catch( SQLException e ) {
			}
			stmtDeleteByPKey = null;
		}
		if( stmtDeleteByCode3Idx != null ) {
			try {
				stmtDeleteByCode3Idx.close();
			}
			catch( SQLException e ) {
//				throw new CFLibDbException( getClass(),
//					S_ProcName,
//					e );
			}
			finally {
				stmtDeleteByCode3Idx = null;
			}
		}
		if( stmtDeleteByCode2Idx != null ) {
			try {
				stmtDeleteByCode2Idx.close();
			}
			catch( SQLException e ) {
//				throw new CFLibDbException( getClass(),
//					S_ProcName,
//					e );
			}
			finally {
				stmtDeleteByCode2Idx = null;
			}
		}
		if( stmtReadAllBuff != null ) {
			try {
				stmtReadAllBuff.close();
			}
			catch( SQLException e ) {
			}
			stmtReadAllBuff = null;
		}
		if( stmtReadBuffByIdIdx != null ) {
			try {
				stmtReadBuffByIdIdx.close();
			}
			catch( SQLException e ) {
			}
			stmtReadBuffByIdIdx = null;
		}
		if( stmtReadBuffByCode3Idx != null ) {
			try {
				stmtReadBuffByCode3Idx.close();
			}
			catch( SQLException e ) {
			}
			stmtReadBuffByCode3Idx = null;
		}
		if( stmtReadBuffByCode2Idx != null ) {
			try {
				stmtReadBuffByCode2Idx.close();
			}
			catch( SQLException e ) {
			}
			stmtReadBuffByCode2Idx = null;
		}
	}
}