// Description: Java 11 DB/2 LUW Jdbc DbIO implementation for ISOCcy.

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
import com.github.msobkow.cflib.CFLib.*;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfsec.CFSecObj.*;

/*
 *	CFSecDb2LUWISOCcyTable DB/2 LUW Jdbc DbIO implementation
 *	for ISOCcy.
 */
public class CFSecDb2LUWISOCcyTable
	implements ICFSecISOCcyTable
{
	private CFSecDb2LUWSchema schema;
	protected PreparedStatement stmtReadBuffByPKey = null;
	protected PreparedStatement stmtLockBuffByPKey = null;
	protected PreparedStatement stmtCreateByPKey = null;
	protected PreparedStatement stmtUpdateByPKey = null;
	protected PreparedStatement stmtDeleteByPKey = null;
	protected PreparedStatement stmtReadAllBuff = null;
	protected PreparedStatement stmtReadBuffByIdIdx = null;
	protected PreparedStatement stmtReadBuffByCcyCdIdx = null;
	protected PreparedStatement stmtReadBuffByCcyNmIdx = null;
	protected PreparedStatement stmtDeleteByIdIdx = null;
	protected PreparedStatement stmtDeleteByCcyCdIdx = null;
	protected PreparedStatement stmtDeleteByCcyNmIdx = null;

	public CFSecDb2LUWISOCcyTable( CFSecDb2LUWSchema argSchema ) {
		schema = argSchema;
	}

	public void createISOCcy( CFSecAuthorization Authorization,
		CFSecISOCcyBuff Buff )
	{
		final String S_ProcName = "createISOCcy";
		if( ! schema.isTransactionOpen() ) {
			throw new CFLibUsageException( getClass(),
				S_ProcName,
				"Transaction not open" );
		}
		ResultSet resultSet = null;
		try {
			String ISOCode = Buff.getRequiredISOCode();
			String Name = Buff.getRequiredName();
			String UnitSymbol = Buff.getOptionalUnitSymbol();
			short Precis = Buff.getRequiredPrecis();
			Connection cnx = schema.getCnx();
			final String sql =
				"CALL sp_create_iso_ccy( ?, ?, ?, ?, ?, ?" + ", "
				+		"?" + ", "
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
			stmtCreateByPKey.setString( argIdx++, "a003" );
			stmtCreateByPKey.setString( argIdx++, ISOCode );
			stmtCreateByPKey.setString( argIdx++, Name );
			if( UnitSymbol != null ) {
				stmtCreateByPKey.setString( argIdx++, UnitSymbol );
			}
			else {
				stmtCreateByPKey.setNull( argIdx++, java.sql.Types.VARCHAR );
			}
			stmtCreateByPKey.setShort( argIdx++, Precis );
			resultSet = stmtCreateByPKey.executeQuery();
			if( resultSet.next() ) {
				CFSecISOCcyBuff createdBuff = unpackISOCcyResultSetToBuff( resultSet );
				if( resultSet.next() ) {
					resultSet.last();
					throw new CFLibRuntimeException( getClass(),
						S_ProcName,
						"Did not expect multi-record response, " + resultSet.getRow() + " rows selected" );
				}
				Buff.setRequiredISOCcyId( createdBuff.getRequiredISOCcyId() );
				Buff.setRequiredISOCode( createdBuff.getRequiredISOCode() );
				Buff.setRequiredName( createdBuff.getRequiredName() );
				Buff.setOptionalUnitSymbol( createdBuff.getOptionalUnitSymbol() );
				Buff.setRequiredPrecis( createdBuff.getRequiredPrecis() );
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

	protected static String S_sqlSelectISOCcyDistinctClassCode = null;

	public String getSqlSelectISOCcyDistinctClassCode() {
		if( S_sqlSelectISOCcyDistinctClassCode == null ) {
			S_sqlSelectISOCcyDistinctClassCode =
					"SELECT "
				+		"DISTINCT a003.ClassCode "
				+	"FROM " + schema.getLowerDbSchemaName() + ".iso_ccy AS a003 ";
		}
		return( S_sqlSelectISOCcyDistinctClassCode );
	}

	protected static String S_sqlSelectISOCcyBuff = null;

	public String getSqlSelectISOCcyBuff() {
		if( S_sqlSelectISOCcyBuff == null ) {
			S_sqlSelectISOCcyBuff =
					"SELECT "
				+		"a003.ISOCcyId, "
				+		"a003.iso_code, "
				+		"a003.ccy_name, "
				+		"a003.unit_symbol, "
				+		"a003.precis, "
				+		"a003.Revision "
				+	"FROM " + schema.getLowerDbSchemaName() + ".iso_ccy AS a003 ";
		}
		return( S_sqlSelectISOCcyBuff );
	}

	protected CFSecISOCcyBuff unpackISOCcyResultSetToBuff( ResultSet resultSet )
	throws SQLException
	{
		final String S_ProcName = "unpackISOCcyResultSetToBuff";
		int idxcol = 1;
		CFSecISOCcyBuff buff = schema.getFactoryISOCcy().newBuff();
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
		buff.setRequiredISOCcyId( resultSet.getShort( idxcol ) );
		idxcol++;
		buff.setRequiredISOCode( resultSet.getString( idxcol ) );
		idxcol++;
		buff.setRequiredName( resultSet.getString( idxcol ) );
		idxcol++;
		{
			String colVal = resultSet.getString( idxcol );
			if( resultSet.wasNull() ) {
				buff.setOptionalUnitSymbol( null );
			}
			else {
				buff.setOptionalUnitSymbol( colVal );
			}
		}
		idxcol++;
		buff.setRequiredPrecis( resultSet.getShort( idxcol ) );
		idxcol++;

		buff.setRequiredRevision( resultSet.getInt( idxcol ) );
		return( buff );
	}

	public CFSecISOCcyBuff readDerived( CFSecAuthorization Authorization,
		CFSecISOCcyPKey PKey )
	{
		final String S_ProcName = "readDerived";
		if( ! schema.isTransactionOpen() ) {
			throw new CFLibUsageException( getClass(),
				S_ProcName,
				"Transaction not open" );
		}
		CFSecISOCcyBuff buff;
		buff = readBuff( Authorization, PKey );
		return( buff );
	}

	public CFSecISOCcyBuff lockDerived( CFSecAuthorization Authorization,
		CFSecISOCcyPKey PKey )
	{
		final String S_ProcName = "lockDerived";
		if( ! schema.isTransactionOpen() ) {
			throw new CFLibUsageException( getClass(),
				S_ProcName,
				"Transaction not open" );
		}
		CFSecISOCcyBuff buff;
		buff = lockBuff( Authorization, PKey );
		return( buff );
	}

	public CFSecISOCcyBuff[] readAllDerived( CFSecAuthorization Authorization ) {
		final String S_ProcName = "readAllDerived";
		CFSecISOCcyBuff[] buffArray;
		if( ! schema.isTransactionOpen() ) {
			throw new CFLibUsageException( getClass(),
				S_ProcName,
				"Transaction not open" );
		}
		buffArray = readAllBuff( Authorization );
		return( buffArray );
	}

	public CFSecISOCcyBuff readDerivedByIdIdx( CFSecAuthorization Authorization,
		short ISOCcyId )
	{
		final String S_ProcName = "CFSecDb2LUWISOCcyTable.readDerivedByIdIdx() ";
		CFSecISOCcyBuff buff;
		if( ! schema.isTransactionOpen() ) {
			throw new CFLibUsageException( getClass(),
				S_ProcName,
				"Transaction not open" );
		}
		buff = readBuffByIdIdx( Authorization,
				ISOCcyId );
		return( buff );
	}

	public CFSecISOCcyBuff readDerivedByCcyCdIdx( CFSecAuthorization Authorization,
		String ISOCode )
	{
		final String S_ProcName = "CFSecDb2LUWISOCcyTable.readDerivedByCcyCdIdx() ";
		CFSecISOCcyBuff buff;
		if( ! schema.isTransactionOpen() ) {
			throw new CFLibUsageException( getClass(),
				S_ProcName,
				"Transaction not open" );
		}
		buff = readBuffByCcyCdIdx( Authorization,
				ISOCode );
		return( buff );
	}

	public CFSecISOCcyBuff readDerivedByCcyNmIdx( CFSecAuthorization Authorization,
		String Name )
	{
		final String S_ProcName = "CFSecDb2LUWISOCcyTable.readDerivedByCcyNmIdx() ";
		CFSecISOCcyBuff buff;
		if( ! schema.isTransactionOpen() ) {
			throw new CFLibUsageException( getClass(),
				S_ProcName,
				"Transaction not open" );
		}
		buff = readBuffByCcyNmIdx( Authorization,
				Name );
		return( buff );
	}

	public CFSecISOCcyBuff readBuff( CFSecAuthorization Authorization,
		CFSecISOCcyPKey PKey )
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
			short ISOCcyId = PKey.getRequiredISOCcyId();
			final String sql = "CALL sp_read_iso_ccy( ?, ?, ?, ?, ?" + ", "
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
			stmtReadBuffByPKey.setShort( argIdx++, ISOCcyId );
			resultSet = stmtReadBuffByPKey.executeQuery();
			if( resultSet.next() ) {
				CFSecISOCcyBuff buff = unpackISOCcyResultSetToBuff( resultSet );
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

	public CFSecISOCcyBuff lockBuff( CFSecAuthorization Authorization,
		CFSecISOCcyPKey PKey )
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
			short ISOCcyId = PKey.getRequiredISOCcyId();
			final String sql = "CALL sp_lock_iso_ccy( ?, ?, ?, ?, ?" + ", "
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
			stmtLockBuffByPKey.setShort( argIdx++, ISOCcyId );
			resultSet = stmtLockBuffByPKey.executeQuery();
			if( resultSet.next() ) {
				CFSecISOCcyBuff buff = unpackISOCcyResultSetToBuff( resultSet );
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

	public CFSecISOCcyBuff[] readAllBuff( CFSecAuthorization Authorization ) {
		final String S_ProcName = "readAllBuff";
		if( ! schema.isTransactionOpen() ) {
			throw new CFLibUsageException( getClass(),
				S_ProcName,
				"Transaction not open" );
		}
		ResultSet resultSet = null;
		try {
			Connection cnx = schema.getCnx();
			final String sql = "CALL sp_read_iso_ccy_all( ?, ?, ?, ?, ? )";
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
			List<CFSecISOCcyBuff> buffList = new LinkedList<CFSecISOCcyBuff>();
			while( resultSet.next() ) {
				CFSecISOCcyBuff buff = unpackISOCcyResultSetToBuff( resultSet );
				buffList.add( buff );
			}
			int idx = 0;
			CFSecISOCcyBuff[] retBuff = new CFSecISOCcyBuff[ buffList.size() ];
			Iterator<CFSecISOCcyBuff> iter = buffList.iterator();
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

	public CFSecISOCcyBuff readBuffByIdIdx( CFSecAuthorization Authorization,
		short ISOCcyId )
	{
		final String S_ProcName = "readBuffByIdIdx";
		ResultSet resultSet = null;
		try {
			Connection cnx = schema.getCnx();
			final String sql = "CALL sp_read_iso_ccy_by_ididx( ?, ?, ?, ?, ?" + ", "
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
			stmtReadBuffByIdIdx.setShort( argIdx++, ISOCcyId );
			resultSet = stmtReadBuffByIdIdx.executeQuery();
			if( resultSet.next() ) {
				CFSecISOCcyBuff buff = unpackISOCcyResultSetToBuff( resultSet );
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

	public CFSecISOCcyBuff readBuffByCcyCdIdx( CFSecAuthorization Authorization,
		String ISOCode )
	{
		final String S_ProcName = "readBuffByCcyCdIdx";
		ResultSet resultSet = null;
		try {
			Connection cnx = schema.getCnx();
			final String sql = "CALL sp_read_iso_ccy_by_ccycdidx( ?, ?, ?, ?, ?" + ", "
				+		"?" + " )";
			if( stmtReadBuffByCcyCdIdx == null ) {
				stmtReadBuffByCcyCdIdx = cnx.prepareStatement( sql );
			}
			int argIdx = 1;
			stmtReadBuffByCcyCdIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtReadBuffByCcyCdIdx.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecUserId().toString() );
			stmtReadBuffByCcyCdIdx.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecSessionId().toString() );
			stmtReadBuffByCcyCdIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtReadBuffByCcyCdIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecTenantId() );
			stmtReadBuffByCcyCdIdx.setString( argIdx++, ISOCode );
			resultSet = stmtReadBuffByCcyCdIdx.executeQuery();
			if( resultSet.next() ) {
				CFSecISOCcyBuff buff = unpackISOCcyResultSetToBuff( resultSet );
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

	public CFSecISOCcyBuff readBuffByCcyNmIdx( CFSecAuthorization Authorization,
		String Name )
	{
		final String S_ProcName = "readBuffByCcyNmIdx";
		ResultSet resultSet = null;
		try {
			Connection cnx = schema.getCnx();
			final String sql = "CALL sp_read_iso_ccy_by_ccynmidx( ?, ?, ?, ?, ?" + ", "
				+		"?" + " )";
			if( stmtReadBuffByCcyNmIdx == null ) {
				stmtReadBuffByCcyNmIdx = cnx.prepareStatement( sql );
			}
			int argIdx = 1;
			stmtReadBuffByCcyNmIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtReadBuffByCcyNmIdx.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecUserId().toString() );
			stmtReadBuffByCcyNmIdx.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecSessionId().toString() );
			stmtReadBuffByCcyNmIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtReadBuffByCcyNmIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecTenantId() );
			stmtReadBuffByCcyNmIdx.setString( argIdx++, Name );
			resultSet = stmtReadBuffByCcyNmIdx.executeQuery();
			if( resultSet.next() ) {
				CFSecISOCcyBuff buff = unpackISOCcyResultSetToBuff( resultSet );
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

	public void updateISOCcy( CFSecAuthorization Authorization,
		CFSecISOCcyBuff Buff )
	{
		final String S_ProcName = "updateISOCcy";
		if( "a003".equals( Buff.getClassCode() )
			&& ( ! schema.isSystemUser( Authorization ) ) )
		{
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Permission denied -- only system user can modify ISOCcy data" );
		}
		ResultSet resultSet = null;
		try {
			short ISOCcyId = Buff.getRequiredISOCcyId();
			String ISOCode = Buff.getRequiredISOCode();
			String Name = Buff.getRequiredName();
			String UnitSymbol = Buff.getOptionalUnitSymbol();
			short Precis = Buff.getRequiredPrecis();
			int Revision = Buff.getRequiredRevision();
			Connection cnx = schema.getCnx();
			final String sql =
				"CALL sp_update_iso_ccy( ?, ?, ?, ?, ?, ?" + ", "
					+	"?" + ", "
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
			stmtUpdateByPKey.setString( argIdx++, "a003" );
			stmtUpdateByPKey.setShort( argIdx++, ISOCcyId );
			stmtUpdateByPKey.setString( argIdx++, ISOCode );
			stmtUpdateByPKey.setString( argIdx++, Name );
			if( UnitSymbol != null ) {
				stmtUpdateByPKey.setString( argIdx++, UnitSymbol );
			}
			else {
				stmtUpdateByPKey.setNull( argIdx++, java.sql.Types.VARCHAR );
			}
			stmtUpdateByPKey.setShort( argIdx++, Precis );
			stmtUpdateByPKey.setInt( argIdx++, Revision );
			resultSet = stmtUpdateByPKey.executeQuery();
			if( resultSet.next() ) {
				CFSecISOCcyBuff updatedBuff = unpackISOCcyResultSetToBuff( resultSet );
				if( resultSet.next() ) {
					resultSet.last();
					throw new CFLibRuntimeException( getClass(),
						S_ProcName,
						"Did not expect multi-record response, " + resultSet.getRow() + " rows selected" );
				}
				Buff.setRequiredISOCode( updatedBuff.getRequiredISOCode() );
				Buff.setRequiredName( updatedBuff.getRequiredName() );
				Buff.setOptionalUnitSymbol( updatedBuff.getOptionalUnitSymbol() );
				Buff.setRequiredPrecis( updatedBuff.getRequiredPrecis() );
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

	public void deleteISOCcy( CFSecAuthorization Authorization,
		CFSecISOCcyBuff Buff )
	{
		final String S_ProcName = "deleteISOCcy";
		ResultSet resultSet = null;
		try {
			Connection cnx = schema.getCnx();
			short ISOCcyId = Buff.getRequiredISOCcyId();

			final String sql = "CALL sp_delete_iso_ccy( ?, ?, ?, ?, ?" + ", "
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
			stmtDeleteByPKey.setShort( argIdx++, ISOCcyId );
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

	public void deleteISOCcyByIdIdx( CFSecAuthorization Authorization,
		short argISOCcyId )
	{
		final String S_ProcName = "deleteISOCcyByIdIdx";
		ResultSet resultSet = null;
		try {
			Connection cnx = schema.getCnx();
			final String sql = "CALL sp_delete_iso_ccy_by_ididx( ?, ?, ?, ?, ?" + ", "
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
			stmtDeleteByIdIdx.setShort( argIdx++, argISOCcyId );
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

	public void deleteISOCcyByIdIdx( CFSecAuthorization Authorization,
		CFSecISOCcyPKey argKey )
	{
		deleteISOCcyByIdIdx( Authorization,
			argKey.getRequiredISOCcyId() );
	}

	public void deleteISOCcyByCcyCdIdx( CFSecAuthorization Authorization,
		String argISOCode )
	{
		final String S_ProcName = "deleteISOCcyByCcyCdIdx";
		ResultSet resultSet = null;
		try {
			Connection cnx = schema.getCnx();
			final String sql = "CALL sp_delete_iso_ccy_by_ccycdidx( ?, ?, ?, ?, ?" + ", "
				+		"?" + " )";
			if( stmtDeleteByCcyCdIdx == null ) {
				stmtDeleteByCcyCdIdx = cnx.prepareStatement( sql );
			}
			int argIdx = 1;
			stmtDeleteByCcyCdIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtDeleteByCcyCdIdx.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecUserId().toString() );
			stmtDeleteByCcyCdIdx.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecSessionId().toString() );
			stmtDeleteByCcyCdIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtDeleteByCcyCdIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecTenantId() );
			stmtDeleteByCcyCdIdx.setString( argIdx++, argISOCode );
			resultSet = stmtDeleteByCcyCdIdx.executeQuery();
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

	public void deleteISOCcyByCcyCdIdx( CFSecAuthorization Authorization,
		CFSecISOCcyByCcyCdIdxKey argKey )
	{
		deleteISOCcyByCcyCdIdx( Authorization,
			argKey.getRequiredISOCode() );
	}

	public void deleteISOCcyByCcyNmIdx( CFSecAuthorization Authorization,
		String argName )
	{
		final String S_ProcName = "deleteISOCcyByCcyNmIdx";
		ResultSet resultSet = null;
		try {
			Connection cnx = schema.getCnx();
			final String sql = "CALL sp_delete_iso_ccy_by_ccynmidx( ?, ?, ?, ?, ?" + ", "
				+		"?" + " )";
			if( stmtDeleteByCcyNmIdx == null ) {
				stmtDeleteByCcyNmIdx = cnx.prepareStatement( sql );
			}
			int argIdx = 1;
			stmtDeleteByCcyNmIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtDeleteByCcyNmIdx.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecUserId().toString() );
			stmtDeleteByCcyNmIdx.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecSessionId().toString() );
			stmtDeleteByCcyNmIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtDeleteByCcyNmIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecTenantId() );
			stmtDeleteByCcyNmIdx.setString( argIdx++, argName );
			resultSet = stmtDeleteByCcyNmIdx.executeQuery();
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

	public void deleteISOCcyByCcyNmIdx( CFSecAuthorization Authorization,
		CFSecISOCcyByCcyNmIdxKey argKey )
	{
		deleteISOCcyByCcyNmIdx( Authorization,
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
		S_sqlSelectISOCcyDistinctClassCode = null;
		S_sqlSelectISOCcyBuff = null;

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
		if( stmtDeleteByCcyCdIdx != null ) {
			try {
				stmtDeleteByCcyCdIdx.close();
			}
			catch( SQLException e ) {
			}
			stmtDeleteByCcyCdIdx = null;
		}
		if( stmtDeleteByCcyNmIdx != null ) {
			try {
				stmtDeleteByCcyNmIdx.close();
			}
			catch( SQLException e ) {
			}
			stmtDeleteByCcyNmIdx = null;
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
		if( stmtReadBuffByCcyCdIdx != null ) {
			try {
				stmtReadBuffByCcyCdIdx.close();
			}
			catch( SQLException e ) {
			}
			stmtReadBuffByCcyCdIdx = null;
		}
		if( stmtReadBuffByCcyNmIdx != null ) {
			try {
				stmtReadBuffByCcyNmIdx.close();
			}
			catch( SQLException e ) {
			}
			stmtReadBuffByCcyNmIdx = null;
		}
	}
}
