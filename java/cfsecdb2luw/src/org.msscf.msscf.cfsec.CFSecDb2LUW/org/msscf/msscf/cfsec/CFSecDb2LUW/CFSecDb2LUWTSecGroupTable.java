// Description: Java 11 DB/2 LUW Jdbc DbIO implementation for TSecGroup.

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

package org.msscf.msscf.cfsec.CFSecDb2LUW;

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.apache.commons.codec.binary.Base64;
import org.msscf.msscf.cflib.CFLib.*;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfsec.CFSecObj.*;

/*
 *	CFSecDb2LUWTSecGroupTable DB/2 LUW Jdbc DbIO implementation
 *	for TSecGroup.
 */
public class CFSecDb2LUWTSecGroupTable
	implements ICFSecTSecGroupTable
{
	private CFSecDb2LUWSchema schema;
	protected PreparedStatement stmtReadBuffByPKey = null;
	protected PreparedStatement stmtLockBuffByPKey = null;
	protected PreparedStatement stmtCreateByPKey = null;
	protected PreparedStatement stmtUpdateByPKey = null;
	protected PreparedStatement stmtDeleteByPKey = null;
	protected PreparedStatement stmtReadAllBuff = null;
	protected PreparedStatement stmtReadBuffByIdIdx = null;
	protected PreparedStatement stmtReadBuffByTenantIdx = null;
	protected PreparedStatement stmtReadBuffByTenantVisIdx = null;
	protected PreparedStatement stmtReadBuffByUNameIdx = null;
	protected PreparedStatement stmtDeleteByIdIdx = null;
	protected PreparedStatement stmtDeleteByTenantIdx = null;
	protected PreparedStatement stmtDeleteByTenantVisIdx = null;
	protected PreparedStatement stmtDeleteByUNameIdx = null;

	public CFSecDb2LUWTSecGroupTable( CFSecDb2LUWSchema argSchema ) {
		schema = argSchema;
	}

	public void createTSecGroup( CFSecAuthorization Authorization,
		CFSecTSecGroupBuff Buff )
	{
		final String S_ProcName = "createTSecGroup";
		if( ! schema.isTransactionOpen() ) {
			throw new CFLibUsageException( getClass(),
				S_ProcName,
				"Transaction not open" );
		}
		ResultSet resultSet = null;
		try {
			long TenantId = Buff.getRequiredTenantId();
			String Name = Buff.getRequiredName();
			boolean IsVisible = Buff.getRequiredIsVisible();
			Connection cnx = schema.getCnx();
			final String sql =
				"CALL sp_create_tsecgrp( ?, ?, ?, ?, ?, ?" + ", "
				+		"?" + ", "
				+		"?" + ", "
				+		"?" + " )";
			if( stmtCreateByPKey == null ) {
				stmtCreateByPKey = cnx.prepareStatement( sql );
			}
			int argIdx = 1;
			stmtCreateByPKey.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtCreateByPKey.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecUserId().toString() );
			stmtCreateByPKey.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecSessionId().toString() );
			stmtCreateByPKey.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtCreateByPKey.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecTenantId() );
			stmtCreateByPKey.setString( argIdx++, "a016" );
			stmtCreateByPKey.setLong( argIdx++, TenantId );
			stmtCreateByPKey.setString( argIdx++, Name );
			if( IsVisible ) {
				stmtCreateByPKey.setString( argIdx++, "Y" );
			}
			else {
				stmtCreateByPKey.setString( argIdx++, "N" );
			}
			resultSet = stmtCreateByPKey.executeQuery();
			if( resultSet.next() ) {
				CFSecTSecGroupBuff createdBuff = unpackTSecGroupResultSetToBuff( resultSet );
				if( resultSet.next() ) {
					resultSet.last();
					throw new CFLibRuntimeException( getClass(),
						S_ProcName,
						"Did not expect multi-record response, " + resultSet.getRow() + " rows selected" );
				}
				Buff.setRequiredTenantId( createdBuff.getRequiredTenantId() );
				Buff.setRequiredTSecGroupId( createdBuff.getRequiredTSecGroupId() );
				Buff.setRequiredName( createdBuff.getRequiredName() );
				Buff.setRequiredIsVisible( createdBuff.getRequiredIsVisible() );
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

	protected static String S_sqlSelectTSecGroupDistinctClassCode = null;

	public String getSqlSelectTSecGroupDistinctClassCode() {
		if( S_sqlSelectTSecGroupDistinctClassCode == null ) {
			S_sqlSelectTSecGroupDistinctClassCode =
					"SELECT "
				+		"DISTINCT a016.ClassCode "
				+	"FROM " + schema.getLowerDbSchemaName() + ".TSecGrp AS a016 ";
		}
		return( S_sqlSelectTSecGroupDistinctClassCode );
	}

	protected static String S_sqlSelectTSecGroupBuff = null;

	public String getSqlSelectTSecGroupBuff() {
		if( S_sqlSelectTSecGroupBuff == null ) {
			S_sqlSelectTSecGroupBuff =
					"SELECT "
				+		"a016.TenantId, "
				+		"a016.TSecGroupId, "
				+		"a016.safe_name, "
				+		"a016.IsVisible, "
				+		"a016.Revision "
				+	"FROM " + schema.getLowerDbSchemaName() + ".TSecGrp AS a016 ";
		}
		return( S_sqlSelectTSecGroupBuff );
	}

	protected CFSecTSecGroupBuff unpackTSecGroupResultSetToBuff( ResultSet resultSet )
	throws SQLException
	{
		final String S_ProcName = "unpackTSecGroupResultSetToBuff";
		int idxcol = 1;
		CFSecTSecGroupBuff buff = schema.getFactoryTSecGroup().newBuff();
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
				buff.setCreatedAt( CFSecDb2LUWSchema.convertTimestampString( colString ) );
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
				buff.setUpdatedAt( CFSecDb2LUWSchema.convertTimestampString( colString ) );
			}
			idxcol++;
		}
		buff.setRequiredTenantId( resultSet.getLong( idxcol ) );
		idxcol++;
		buff.setRequiredTSecGroupId( resultSet.getInt( idxcol ) );
		idxcol++;
		buff.setRequiredName( resultSet.getString( idxcol ) );
		idxcol++;
		buff.setRequiredIsVisible( ( "Y".equals( resultSet.getString( idxcol ) ) ? true : false ) );
		idxcol++;

		buff.setRequiredRevision( resultSet.getInt( idxcol ) );
		return( buff );
	}

	public CFSecTSecGroupBuff readDerived( CFSecAuthorization Authorization,
		CFSecTSecGroupPKey PKey )
	{
		final String S_ProcName = "readDerived";
		if( ! schema.isTransactionOpen() ) {
			throw new CFLibUsageException( getClass(),
				S_ProcName,
				"Transaction not open" );
		}
		CFSecTSecGroupBuff buff;
		buff = readBuff( Authorization, PKey );
		return( buff );
	}

	public CFSecTSecGroupBuff lockDerived( CFSecAuthorization Authorization,
		CFSecTSecGroupPKey PKey )
	{
		final String S_ProcName = "lockDerived";
		if( ! schema.isTransactionOpen() ) {
			throw new CFLibUsageException( getClass(),
				S_ProcName,
				"Transaction not open" );
		}
		CFSecTSecGroupBuff buff;
		buff = lockBuff( Authorization, PKey );
		return( buff );
	}

	public CFSecTSecGroupBuff[] readAllDerived( CFSecAuthorization Authorization ) {
		final String S_ProcName = "readAllDerived";
		CFSecTSecGroupBuff[] buffArray;
		if( ! schema.isTransactionOpen() ) {
			throw new CFLibUsageException( getClass(),
				S_ProcName,
				"Transaction not open" );
		}
		buffArray = readAllBuff( Authorization );
		return( buffArray );
	}

	public CFSecTSecGroupBuff readDerivedByIdIdx( CFSecAuthorization Authorization,
		long TenantId,
		int TSecGroupId )
	{
		final String S_ProcName = "CFSecDb2LUWTSecGroupTable.readDerivedByIdIdx() ";
		CFSecTSecGroupBuff buff;
		if( ! schema.isTransactionOpen() ) {
			throw new CFLibUsageException( getClass(),
				S_ProcName,
				"Transaction not open" );
		}
		buff = readBuffByIdIdx( Authorization,
				TenantId,
				TSecGroupId );
		return( buff );
	}

	public CFSecTSecGroupBuff[] readDerivedByTenantIdx( CFSecAuthorization Authorization,
		long TenantId )
	{
		final String S_ProcName = "readDerivedByTenantIdx";
		if( ! schema.isTransactionOpen() ) {
			throw new CFLibUsageException( getClass(),
				S_ProcName,
				"Transaction not open" );
		}
		CFSecTSecGroupBuff[] buffList = readBuffByTenantIdx( Authorization,
				TenantId );
		return( buffList );

	}

	public CFSecTSecGroupBuff[] readDerivedByTenantVisIdx( CFSecAuthorization Authorization,
		long TenantId,
		boolean IsVisible )
	{
		final String S_ProcName = "readDerivedByTenantVisIdx";
		if( ! schema.isTransactionOpen() ) {
			throw new CFLibUsageException( getClass(),
				S_ProcName,
				"Transaction not open" );
		}
		CFSecTSecGroupBuff[] buffList = readBuffByTenantVisIdx( Authorization,
				TenantId,
				IsVisible );
		return( buffList );

	}

	public CFSecTSecGroupBuff readDerivedByUNameIdx( CFSecAuthorization Authorization,
		long TenantId,
		String Name )
	{
		final String S_ProcName = "CFSecDb2LUWTSecGroupTable.readDerivedByUNameIdx() ";
		CFSecTSecGroupBuff buff;
		if( ! schema.isTransactionOpen() ) {
			throw new CFLibUsageException( getClass(),
				S_ProcName,
				"Transaction not open" );
		}
		buff = readBuffByUNameIdx( Authorization,
				TenantId,
				Name );
		return( buff );
	}

	public CFSecTSecGroupBuff readBuff( CFSecAuthorization Authorization,
		CFSecTSecGroupPKey PKey )
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
			long TenantId = PKey.getRequiredTenantId();
			int TSecGroupId = PKey.getRequiredTSecGroupId();
			final String sql = "CALL sp_read_tsecgrp( ?, ?, ?, ?, ?" + ", "
				+		"?" + ", "
				+		"?" + " )";
			if( stmtReadBuffByPKey == null ) {
				stmtReadBuffByPKey = cnx.prepareStatement( sql );
			}
			int argIdx = 1;
			stmtReadBuffByPKey.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtReadBuffByPKey.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecUserId().toString() );
			stmtReadBuffByPKey.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecSessionId().toString() );
			stmtReadBuffByPKey.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtReadBuffByPKey.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecTenantId() );
			stmtReadBuffByPKey.setLong( argIdx++, TenantId );
			stmtReadBuffByPKey.setInt( argIdx++, TSecGroupId );
			resultSet = stmtReadBuffByPKey.executeQuery();
			if( resultSet.next() ) {
				CFSecTSecGroupBuff buff = unpackTSecGroupResultSetToBuff( resultSet );
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

	public CFSecTSecGroupBuff lockBuff( CFSecAuthorization Authorization,
		CFSecTSecGroupPKey PKey )
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
			long TenantId = PKey.getRequiredTenantId();
			int TSecGroupId = PKey.getRequiredTSecGroupId();
			final String sql = "CALL sp_lock_tsecgrp( ?, ?, ?, ?, ?" + ", "
				+		"?" + ", "
				+		"?" + " )";
			if( stmtLockBuffByPKey == null ) {
				stmtLockBuffByPKey = cnx.prepareStatement( sql );
			}
			int argIdx = 1;
			stmtLockBuffByPKey.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtLockBuffByPKey.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecUserId().toString() );
			stmtLockBuffByPKey.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecSessionId().toString() );
			stmtLockBuffByPKey.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtLockBuffByPKey.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecTenantId() );
			stmtLockBuffByPKey.setLong( argIdx++, TenantId );
			stmtLockBuffByPKey.setInt( argIdx++, TSecGroupId );
			resultSet = stmtLockBuffByPKey.executeQuery();
			if( resultSet.next() ) {
				CFSecTSecGroupBuff buff = unpackTSecGroupResultSetToBuff( resultSet );
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

	public CFSecTSecGroupBuff[] readAllBuff( CFSecAuthorization Authorization ) {
		final String S_ProcName = "readAllBuff";
		if( ! schema.isTransactionOpen() ) {
			throw new CFLibUsageException( getClass(),
				S_ProcName,
				"Transaction not open" );
		}
		ResultSet resultSet = null;
		try {
			Connection cnx = schema.getCnx();
			final String sql = "CALL sp_read_tsecgrp_all( ?, ?, ?, ?, ? )";
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
			List<CFSecTSecGroupBuff> buffList = new LinkedList<CFSecTSecGroupBuff>();
			while( resultSet.next() ) {
				CFSecTSecGroupBuff buff = unpackTSecGroupResultSetToBuff( resultSet );
				buffList.add( buff );
			}
			int idx = 0;
			CFSecTSecGroupBuff[] retBuff = new CFSecTSecGroupBuff[ buffList.size() ];
			Iterator<CFSecTSecGroupBuff> iter = buffList.iterator();
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

	public CFSecTSecGroupBuff readBuffByIdIdx( CFSecAuthorization Authorization,
		long TenantId,
		int TSecGroupId )
	{
		final String S_ProcName = "readBuffByIdIdx";
		ResultSet resultSet = null;
		try {
			Connection cnx = schema.getCnx();
			final String sql = "CALL sp_read_tsecgrp_by_ididx( ?, ?, ?, ?, ?" + ", "
				+		"?" + ", "
				+		"?" + " )";
			if( stmtReadBuffByIdIdx == null ) {
				stmtReadBuffByIdIdx = cnx.prepareStatement( sql );
			}
			int argIdx = 1;
			stmtReadBuffByIdIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtReadBuffByIdIdx.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecUserId().toString() );
			stmtReadBuffByIdIdx.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecSessionId().toString() );
			stmtReadBuffByIdIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtReadBuffByIdIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecTenantId() );
			stmtReadBuffByIdIdx.setLong( argIdx++, TenantId );
			stmtReadBuffByIdIdx.setInt( argIdx++, TSecGroupId );
			resultSet = stmtReadBuffByIdIdx.executeQuery();
			if( resultSet.next() ) {
				CFSecTSecGroupBuff buff = unpackTSecGroupResultSetToBuff( resultSet );
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

	public CFSecTSecGroupBuff[] readBuffByTenantIdx( CFSecAuthorization Authorization,
		long TenantId )
	{
		final String S_ProcName = "readBuffByTenantIdx";
		ResultSet resultSet = null;
		try {
			Connection cnx = schema.getCnx();
			final String sql = "CALL sp_read_tsecgrp_by_tenantidx( ?, ?, ?, ?, ?" + ", "
				+		"?" + " )";
			if( stmtReadBuffByTenantIdx == null ) {
				stmtReadBuffByTenantIdx = cnx.prepareStatement( sql );
			}
			int argIdx = 1;
			stmtReadBuffByTenantIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtReadBuffByTenantIdx.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecUserId().toString() );
			stmtReadBuffByTenantIdx.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecSessionId().toString() );
			stmtReadBuffByTenantIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtReadBuffByTenantIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecTenantId() );
			stmtReadBuffByTenantIdx.setLong( argIdx++, TenantId );
			resultSet = stmtReadBuffByTenantIdx.executeQuery();
			List<CFSecTSecGroupBuff> buffList = new LinkedList<CFSecTSecGroupBuff>();
			while( resultSet.next() ) {
				CFSecTSecGroupBuff buff = unpackTSecGroupResultSetToBuff( resultSet );
				buffList.add( buff );
			}
			int idx = 0;
			CFSecTSecGroupBuff[] retBuff = new CFSecTSecGroupBuff[ buffList.size() ];
			Iterator<CFSecTSecGroupBuff> iter = buffList.iterator();
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

	public CFSecTSecGroupBuff[] readBuffByTenantVisIdx( CFSecAuthorization Authorization,
		long TenantId,
		boolean IsVisible )
	{
		final String S_ProcName = "readBuffByTenantVisIdx";
		ResultSet resultSet = null;
		try {
			Connection cnx = schema.getCnx();
			final String sql = "CALL sp_read_tsecgrp_by_tenantvisidx( ?, ?, ?, ?, ?" + ", "
				+		"?" + ", "
				+		"?" + " )";
			if( stmtReadBuffByTenantVisIdx == null ) {
				stmtReadBuffByTenantVisIdx = cnx.prepareStatement( sql );
			}
			int argIdx = 1;
			stmtReadBuffByTenantVisIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtReadBuffByTenantVisIdx.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecUserId().toString() );
			stmtReadBuffByTenantVisIdx.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecSessionId().toString() );
			stmtReadBuffByTenantVisIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtReadBuffByTenantVisIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecTenantId() );
			stmtReadBuffByTenantVisIdx.setLong( argIdx++, TenantId );
			if( IsVisible ) {
				stmtReadBuffByTenantVisIdx.setString( argIdx++, "Y" );
			}
			else {
				stmtReadBuffByTenantVisIdx.setString( argIdx++, "N" );
			}
			resultSet = stmtReadBuffByTenantVisIdx.executeQuery();
			List<CFSecTSecGroupBuff> buffList = new LinkedList<CFSecTSecGroupBuff>();
			while( resultSet.next() ) {
				CFSecTSecGroupBuff buff = unpackTSecGroupResultSetToBuff( resultSet );
				buffList.add( buff );
			}
			int idx = 0;
			CFSecTSecGroupBuff[] retBuff = new CFSecTSecGroupBuff[ buffList.size() ];
			Iterator<CFSecTSecGroupBuff> iter = buffList.iterator();
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

	public CFSecTSecGroupBuff readBuffByUNameIdx( CFSecAuthorization Authorization,
		long TenantId,
		String Name )
	{
		final String S_ProcName = "readBuffByUNameIdx";
		ResultSet resultSet = null;
		try {
			Connection cnx = schema.getCnx();
			final String sql = "CALL sp_read_tsecgrp_by_unameidx( ?, ?, ?, ?, ?" + ", "
				+		"?" + ", "
				+		"?" + " )";
			if( stmtReadBuffByUNameIdx == null ) {
				stmtReadBuffByUNameIdx = cnx.prepareStatement( sql );
			}
			int argIdx = 1;
			stmtReadBuffByUNameIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtReadBuffByUNameIdx.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecUserId().toString() );
			stmtReadBuffByUNameIdx.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecSessionId().toString() );
			stmtReadBuffByUNameIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtReadBuffByUNameIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecTenantId() );
			stmtReadBuffByUNameIdx.setLong( argIdx++, TenantId );
			stmtReadBuffByUNameIdx.setString( argIdx++, Name );
			resultSet = stmtReadBuffByUNameIdx.executeQuery();
			if( resultSet.next() ) {
				CFSecTSecGroupBuff buff = unpackTSecGroupResultSetToBuff( resultSet );
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

	public void updateTSecGroup( CFSecAuthorization Authorization,
		CFSecTSecGroupBuff Buff )
	{
		final String S_ProcName = "updateTSecGroup";
		if( "a016".equals( Buff.getClassCode() )
			&& ( ! schema.isTenantUser( Authorization,
				Buff.getRequiredTenantId(),
				"UpdateTSecGroup" ) ) )
		{
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Permission denied -- User not part of TSecGroup UpdateTSecGroup" );
		}
		ResultSet resultSet = null;
		try {
			long TenantId = Buff.getRequiredTenantId();
			int TSecGroupId = Buff.getRequiredTSecGroupId();
			String Name = Buff.getRequiredName();
			boolean IsVisible = Buff.getRequiredIsVisible();
			int Revision = Buff.getRequiredRevision();
			Connection cnx = schema.getCnx();
			final String sql =
				"CALL sp_update_tsecgrp( ?, ?, ?, ?, ?, ?" + ", "
					+	"?" + ", "
					+	"?" + ", "
					+	"?" + ", "
					+	"?" + ", "
					+ "?" + " )";
			if( stmtUpdateByPKey == null ) {
				stmtUpdateByPKey = cnx.prepareStatement( sql );
			}
			int argIdx = 1;
			stmtUpdateByPKey.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtUpdateByPKey.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecUserId().toString() );
			stmtUpdateByPKey.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecSessionId().toString() );
			stmtUpdateByPKey.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtUpdateByPKey.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecTenantId() );
			stmtUpdateByPKey.setString( argIdx++, "a016" );
			stmtUpdateByPKey.setLong( argIdx++, TenantId );
			stmtUpdateByPKey.setInt( argIdx++, TSecGroupId );
			stmtUpdateByPKey.setString( argIdx++, Name );
			if( IsVisible ) {
				stmtUpdateByPKey.setString( argIdx++, "Y" );
			}
			else {
				stmtUpdateByPKey.setString( argIdx++, "N" );
			}
			stmtUpdateByPKey.setInt( argIdx++, Revision );
			resultSet = stmtUpdateByPKey.executeQuery();
			if( resultSet.next() ) {
				CFSecTSecGroupBuff updatedBuff = unpackTSecGroupResultSetToBuff( resultSet );
				if( resultSet.next() ) {
					resultSet.last();
					throw new CFLibRuntimeException( getClass(),
						S_ProcName,
						"Did not expect multi-record response, " + resultSet.getRow() + " rows selected" );
				}
				Buff.setRequiredName( updatedBuff.getRequiredName() );
				Buff.setRequiredIsVisible( updatedBuff.getRequiredIsVisible() );
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

	public void deleteTSecGroup( CFSecAuthorization Authorization,
		CFSecTSecGroupBuff Buff )
	{
		final String S_ProcName = "deleteTSecGroup";
		ResultSet resultSet = null;
		try {
			Connection cnx = schema.getCnx();
			long TenantId = Buff.getRequiredTenantId();
			int TSecGroupId = Buff.getRequiredTSecGroupId();

			final String sql = "CALL sp_delete_tsecgrp( ?, ?, ?, ?, ?" + ", "
				+		"?" + ", "
				+		"?" + ", "
				+		"?" + " )";
			if( stmtDeleteByPKey == null ) {
				stmtDeleteByPKey = cnx.prepareStatement( sql );
			}
			int argIdx = 1;
			stmtDeleteByPKey.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtDeleteByPKey.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecUserId().toString() );
			stmtDeleteByPKey.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecSessionId().toString() );
			stmtDeleteByPKey.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtDeleteByPKey.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecTenantId() );
			stmtDeleteByPKey.setLong( argIdx++, TenantId );
			stmtDeleteByPKey.setInt( argIdx++, TSecGroupId );
			stmtDeleteByPKey.setInt( argIdx++, Buff.getRequiredRevision() );;
			resultSet = stmtDeleteByPKey.executeQuery();
			if( resultSet.next() ) {
				int deleteFlag = resultSet.getInt( 1 );
				if( resultSet.next() ) {
					resultSet.last();
					throw new CFLibRuntimeException( getClass(),
						S_ProcName,
						"Did not expect multi-record response, " + resultSet.getRow() + " rows selected" );
				}
			}
			else {
				throw new CFLibRuntimeException( getClass(),
					S_ProcName,
					"Expected 1 record result set to be returned by delete, not 0 rows" );
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

	public void deleteTSecGroupByIdIdx( CFSecAuthorization Authorization,
		long argTenantId,
		int argTSecGroupId )
	{
		final String S_ProcName = "deleteTSecGroupByIdIdx";
		ResultSet resultSet = null;
		try {
			Connection cnx = schema.getCnx();
			final String sql = "CALL sp_delete_tsecgrp_by_ididx( ?, ?, ?, ?, ?" + ", "
				+		"?" + ", "
				+		"?" + " )";
			if( stmtDeleteByIdIdx == null ) {
				stmtDeleteByIdIdx = cnx.prepareStatement( sql );
			}
			int argIdx = 1;
			stmtDeleteByIdIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtDeleteByIdIdx.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecUserId().toString() );
			stmtDeleteByIdIdx.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecSessionId().toString() );
			stmtDeleteByIdIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtDeleteByIdIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecTenantId() );
			stmtDeleteByIdIdx.setLong( argIdx++, argTenantId );
			stmtDeleteByIdIdx.setInt( argIdx++, argTSecGroupId );
			resultSet = stmtDeleteByIdIdx.executeQuery();
			if( resultSet.next() ) {
				int deleteFlag = resultSet.getInt( 1 );
				if( resultSet.next() ) {
					resultSet.last();
					throw new CFLibRuntimeException( getClass(),
						S_ProcName,
						"Did not expect multi-record response, " + resultSet.getRow() + " rows selected" );
				}
			}
			else {
				throw new CFLibRuntimeException( getClass(),
					S_ProcName,
					"Expected 1 record result set to be returned by delete, not 0 rows" );
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

	public void deleteTSecGroupByIdIdx( CFSecAuthorization Authorization,
		CFSecTSecGroupPKey argKey )
	{
		deleteTSecGroupByIdIdx( Authorization,
			argKey.getRequiredTenantId(),
			argKey.getRequiredTSecGroupId() );
	}

	public void deleteTSecGroupByTenantIdx( CFSecAuthorization Authorization,
		long argTenantId )
	{
		final String S_ProcName = "deleteTSecGroupByTenantIdx";
		ResultSet resultSet = null;
		try {
			Connection cnx = schema.getCnx();
			final String sql = "CALL sp_delete_tsecgrp_by_tenantidx( ?, ?, ?, ?, ?" + ", "
				+		"?" + " )";
			if( stmtDeleteByTenantIdx == null ) {
				stmtDeleteByTenantIdx = cnx.prepareStatement( sql );
			}
			int argIdx = 1;
			stmtDeleteByTenantIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtDeleteByTenantIdx.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecUserId().toString() );
			stmtDeleteByTenantIdx.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecSessionId().toString() );
			stmtDeleteByTenantIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtDeleteByTenantIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecTenantId() );
			stmtDeleteByTenantIdx.setLong( argIdx++, argTenantId );
			resultSet = stmtDeleteByTenantIdx.executeQuery();
			if( resultSet.next() ) {
				int deleteFlag = resultSet.getInt( 1 );
				if( resultSet.next() ) {
					resultSet.last();
					throw new CFLibRuntimeException( getClass(),
						S_ProcName,
						"Did not expect multi-record response, " + resultSet.getRow() + " rows selected" );
				}
			}
			else {
				throw new CFLibRuntimeException( getClass(),
					S_ProcName,
					"Expected 1 record result set to be returned by delete, not 0 rows" );
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

	public void deleteTSecGroupByTenantIdx( CFSecAuthorization Authorization,
		CFSecTSecGroupByTenantIdxKey argKey )
	{
		deleteTSecGroupByTenantIdx( Authorization,
			argKey.getRequiredTenantId() );
	}

	public void deleteTSecGroupByTenantVisIdx( CFSecAuthorization Authorization,
		long argTenantId,
		boolean argIsVisible )
	{
		final String S_ProcName = "deleteTSecGroupByTenantVisIdx";
		ResultSet resultSet = null;
		try {
			Connection cnx = schema.getCnx();
			final String sql = "CALL sp_delete_tsecgrp_by_tenantvisidx( ?, ?, ?, ?, ?" + ", "
				+		"?" + ", "
				+		"?" + " )";
			if( stmtDeleteByTenantVisIdx == null ) {
				stmtDeleteByTenantVisIdx = cnx.prepareStatement( sql );
			}
			int argIdx = 1;
			stmtDeleteByTenantVisIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtDeleteByTenantVisIdx.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecUserId().toString() );
			stmtDeleteByTenantVisIdx.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecSessionId().toString() );
			stmtDeleteByTenantVisIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtDeleteByTenantVisIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecTenantId() );
			stmtDeleteByTenantVisIdx.setLong( argIdx++, argTenantId );
			if( argIsVisible ) {
				stmtDeleteByTenantVisIdx.setString( argIdx++, "Y" );
			}
			else {
				stmtDeleteByTenantVisIdx.setString( argIdx++, "N" );
			}
			resultSet = stmtDeleteByTenantVisIdx.executeQuery();
			if( resultSet.next() ) {
				int deleteFlag = resultSet.getInt( 1 );
				if( resultSet.next() ) {
					resultSet.last();
					throw new CFLibRuntimeException( getClass(),
						S_ProcName,
						"Did not expect multi-record response, " + resultSet.getRow() + " rows selected" );
				}
			}
			else {
				throw new CFLibRuntimeException( getClass(),
					S_ProcName,
					"Expected 1 record result set to be returned by delete, not 0 rows" );
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

	public void deleteTSecGroupByTenantVisIdx( CFSecAuthorization Authorization,
		CFSecTSecGroupByTenantVisIdxKey argKey )
	{
		deleteTSecGroupByTenantVisIdx( Authorization,
			argKey.getRequiredTenantId(),
			argKey.getRequiredIsVisible() );
	}

	public void deleteTSecGroupByUNameIdx( CFSecAuthorization Authorization,
		long argTenantId,
		String argName )
	{
		final String S_ProcName = "deleteTSecGroupByUNameIdx";
		ResultSet resultSet = null;
		try {
			Connection cnx = schema.getCnx();
			final String sql = "CALL sp_delete_tsecgrp_by_unameidx( ?, ?, ?, ?, ?" + ", "
				+		"?" + ", "
				+		"?" + " )";
			if( stmtDeleteByUNameIdx == null ) {
				stmtDeleteByUNameIdx = cnx.prepareStatement( sql );
			}
			int argIdx = 1;
			stmtDeleteByUNameIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtDeleteByUNameIdx.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecUserId().toString() );
			stmtDeleteByUNameIdx.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecSessionId().toString() );
			stmtDeleteByUNameIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtDeleteByUNameIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecTenantId() );
			stmtDeleteByUNameIdx.setLong( argIdx++, argTenantId );
			stmtDeleteByUNameIdx.setString( argIdx++, argName );
			resultSet = stmtDeleteByUNameIdx.executeQuery();
			if( resultSet.next() ) {
				int deleteFlag = resultSet.getInt( 1 );
				if( resultSet.next() ) {
					resultSet.last();
					throw new CFLibRuntimeException( getClass(),
						S_ProcName,
						"Did not expect multi-record response, " + resultSet.getRow() + " rows selected" );
				}
			}
			else {
				throw new CFLibRuntimeException( getClass(),
					S_ProcName,
					"Expected 1 record result set to be returned by delete, not 0 rows" );
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

	public void deleteTSecGroupByUNameIdx( CFSecAuthorization Authorization,
		CFSecTSecGroupByUNameIdxKey argKey )
	{
		deleteTSecGroupByUNameIdx( Authorization,
			argKey.getRequiredTenantId(),
			argKey.getRequiredName() );
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
		S_sqlSelectTSecGroupDistinctClassCode = null;
		S_sqlSelectTSecGroupBuff = null;

		if( stmtReadBuffByPKey != null ) {
			try {
				stmtReadBuffByPKey.close();
			}
			catch( SQLException e ) {
			}
			stmtReadBuffByPKey = null;
		}
		if( stmtReadAllBuff != null ) {
			try {
				stmtReadAllBuff.close();
			}
			catch( SQLException e ) {
			}
			stmtReadAllBuff = null;
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
		if( stmtDeleteByIdIdx != null ) {
			try {
				stmtDeleteByIdIdx.close();
			}
			catch( SQLException e ) {
			}
			stmtDeleteByIdIdx = null;
		}
		if( stmtDeleteByTenantIdx != null ) {
			try {
				stmtDeleteByTenantIdx.close();
			}
			catch( SQLException e ) {
			}
			stmtDeleteByTenantIdx = null;
		}
		if( stmtDeleteByTenantVisIdx != null ) {
			try {
				stmtDeleteByTenantVisIdx.close();
			}
			catch( SQLException e ) {
			}
			stmtDeleteByTenantVisIdx = null;
		}
		if( stmtDeleteByUNameIdx != null ) {
			try {
				stmtDeleteByUNameIdx.close();
			}
			catch( SQLException e ) {
			}
			stmtDeleteByUNameIdx = null;
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
		if( stmtReadBuffByTenantIdx != null ) {
			try {
				stmtReadBuffByTenantIdx.close();
			}
			catch( SQLException e ) {
			}
			stmtReadBuffByTenantIdx = null;
		}
		if( stmtReadBuffByTenantVisIdx != null ) {
			try {
				stmtReadBuffByTenantVisIdx.close();
			}
			catch( SQLException e ) {
			}
			stmtReadBuffByTenantVisIdx = null;
		}
		if( stmtReadBuffByUNameIdx != null ) {
			try {
				stmtReadBuffByUNameIdx.close();
			}
			catch( SQLException e ) {
			}
			stmtReadBuffByUNameIdx = null;
		}
	}
}