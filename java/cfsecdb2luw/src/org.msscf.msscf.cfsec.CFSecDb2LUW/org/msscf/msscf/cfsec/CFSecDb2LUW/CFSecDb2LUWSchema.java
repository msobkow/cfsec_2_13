// Description: Java 11 DB/2 LUW Jdbc DbIO implementation for CFSec.

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

package org.msscf.msscf.cfsec.CFSecDb2LUW;

import java.lang.reflect.*;
import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import javax.naming.*;
import javax.sql.*;
import org.apache.commons.codec.binary.Base64;
import org.msscf.msscf.cflib.CFLib.*;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfsec.CFSecSaxLoader.CFSecSaxLoader;

public class CFSecDb2LUWSchema
	extends CFSecSchema
	implements ICFSecSchema
{
	protected Connection cnx;
	protected boolean inTransaction;
	protected PreparedStatement stmtSelectNextISOCcyIdGen = null;
	protected PreparedStatement stmtSelectNextISOCtryIdGen = null;
	protected PreparedStatement stmtSelectNextISOLangIdGen = null;
	protected PreparedStatement stmtSelectNextISOTZoneIdGen = null;
	protected PreparedStatement stmtSelectNextServiceTypeIdGen = null;
	protected PreparedStatement stmtSelectNextClusterIdGen = null;
	protected PreparedStatement stmtSelectNextTenantIdGen = null;
	protected PreparedStatement stmtSelectIsSystemUser = null;
	protected PreparedStatement stmtSelectIsClusterUser = null;
	protected PreparedStatement stmtSelectIsTenantUser = null;

	public CFSecDb2LUWSchema() {
		super();
		cnx = null;
		inTransaction = false;
		tableCluster = new CFSecDb2LUWClusterTable( this );
		tableHostNode = new CFSecDb2LUWHostNodeTable( this );
		tableISOCcy = new CFSecDb2LUWISOCcyTable( this );
		tableISOCtry = new CFSecDb2LUWISOCtryTable( this );
		tableISOCtryCcy = new CFSecDb2LUWISOCtryCcyTable( this );
		tableISOCtryLang = new CFSecDb2LUWISOCtryLangTable( this );
		tableISOLang = new CFSecDb2LUWISOLangTable( this );
		tableISOTZone = new CFSecDb2LUWISOTZoneTable( this );
		tableSecApp = new CFSecDb2LUWSecAppTable( this );
		tableSecDevice = new CFSecDb2LUWSecDeviceTable( this );
		tableSecForm = new CFSecDb2LUWSecFormTable( this );
		tableSecGroup = new CFSecDb2LUWSecGroupTable( this );
		tableSecGroupForm = new CFSecDb2LUWSecGroupFormTable( this );
		tableSecGrpInc = new CFSecDb2LUWSecGrpIncTable( this );
		tableSecGrpMemb = new CFSecDb2LUWSecGrpMembTable( this );
		tableSecSession = new CFSecDb2LUWSecSessionTable( this );
		tableSecUser = new CFSecDb2LUWSecUserTable( this );
		tableService = new CFSecDb2LUWServiceTable( this );
		tableServiceType = new CFSecDb2LUWServiceTypeTable( this );
		tableSysCluster = new CFSecDb2LUWSysClusterTable( this );
		tableTSecGroup = new CFSecDb2LUWTSecGroupTable( this );
		tableTSecGrpInc = new CFSecDb2LUWTSecGrpIncTable( this );
		tableTSecGrpMemb = new CFSecDb2LUWTSecGrpMembTable( this );
		tableTenant = new CFSecDb2LUWTenantTable( this );
	}

	public CFSecDb2LUWSchema( CFSecConfigurationFile conf ) {
		super( conf );
		cnx = null;
		inTransaction = false;
		tableCluster = new CFSecDb2LUWClusterTable( this );
		tableHostNode = new CFSecDb2LUWHostNodeTable( this );
		tableISOCcy = new CFSecDb2LUWISOCcyTable( this );
		tableISOCtry = new CFSecDb2LUWISOCtryTable( this );
		tableISOCtryCcy = new CFSecDb2LUWISOCtryCcyTable( this );
		tableISOCtryLang = new CFSecDb2LUWISOCtryLangTable( this );
		tableISOLang = new CFSecDb2LUWISOLangTable( this );
		tableISOTZone = new CFSecDb2LUWISOTZoneTable( this );
		tableSecApp = new CFSecDb2LUWSecAppTable( this );
		tableSecDevice = new CFSecDb2LUWSecDeviceTable( this );
		tableSecForm = new CFSecDb2LUWSecFormTable( this );
		tableSecGroup = new CFSecDb2LUWSecGroupTable( this );
		tableSecGroupForm = new CFSecDb2LUWSecGroupFormTable( this );
		tableSecGrpInc = new CFSecDb2LUWSecGrpIncTable( this );
		tableSecGrpMemb = new CFSecDb2LUWSecGrpMembTable( this );
		tableSecSession = new CFSecDb2LUWSecSessionTable( this );
		tableSecUser = new CFSecDb2LUWSecUserTable( this );
		tableService = new CFSecDb2LUWServiceTable( this );
		tableServiceType = new CFSecDb2LUWServiceTypeTable( this );
		tableSysCluster = new CFSecDb2LUWSysClusterTable( this );
		tableTSecGroup = new CFSecDb2LUWTSecGroupTable( this );
		tableTSecGrpInc = new CFSecDb2LUWTSecGrpIncTable( this );
		tableTSecGrpMemb = new CFSecDb2LUWTSecGrpMembTable( this );
		tableTenant = new CFSecDb2LUWTenantTable( this );
		setDbSchemaName( conf.getDbDatabase() );
	}

	public CFSecDb2LUWSchema( String argJndiName ) {
		super( argJndiName );
		cnx = null;
		inTransaction = false;
		tableCluster = new CFSecDb2LUWClusterTable( this );
		tableHostNode = new CFSecDb2LUWHostNodeTable( this );
		tableISOCcy = new CFSecDb2LUWISOCcyTable( this );
		tableISOCtry = new CFSecDb2LUWISOCtryTable( this );
		tableISOCtryCcy = new CFSecDb2LUWISOCtryCcyTable( this );
		tableISOCtryLang = new CFSecDb2LUWISOCtryLangTable( this );
		tableISOLang = new CFSecDb2LUWISOLangTable( this );
		tableISOTZone = new CFSecDb2LUWISOTZoneTable( this );
		tableSecApp = new CFSecDb2LUWSecAppTable( this );
		tableSecDevice = new CFSecDb2LUWSecDeviceTable( this );
		tableSecForm = new CFSecDb2LUWSecFormTable( this );
		tableSecGroup = new CFSecDb2LUWSecGroupTable( this );
		tableSecGroupForm = new CFSecDb2LUWSecGroupFormTable( this );
		tableSecGrpInc = new CFSecDb2LUWSecGrpIncTable( this );
		tableSecGrpMemb = new CFSecDb2LUWSecGrpMembTable( this );
		tableSecSession = new CFSecDb2LUWSecSessionTable( this );
		tableSecUser = new CFSecDb2LUWSecUserTable( this );
		tableService = new CFSecDb2LUWServiceTable( this );
		tableServiceType = new CFSecDb2LUWServiceTypeTable( this );
		tableSysCluster = new CFSecDb2LUWSysClusterTable( this );
		tableTSecGroup = new CFSecDb2LUWTSecGroupTable( this );
		tableTSecGrpInc = new CFSecDb2LUWTSecGrpIncTable( this );
		tableTSecGrpMemb = new CFSecDb2LUWTSecGrpMembTable( this );
		tableTenant = new CFSecDb2LUWTenantTable( this );
	}

	public CFSecDb2LUWSchema( Connection argCnx ) {
		super();
		cnx = argCnx;
		inTransaction = false;
		tableCluster = new CFSecDb2LUWClusterTable( this );
		tableHostNode = new CFSecDb2LUWHostNodeTable( this );
		tableISOCcy = new CFSecDb2LUWISOCcyTable( this );
		tableISOCtry = new CFSecDb2LUWISOCtryTable( this );
		tableISOCtryCcy = new CFSecDb2LUWISOCtryCcyTable( this );
		tableISOCtryLang = new CFSecDb2LUWISOCtryLangTable( this );
		tableISOLang = new CFSecDb2LUWISOLangTable( this );
		tableISOTZone = new CFSecDb2LUWISOTZoneTable( this );
		tableSecApp = new CFSecDb2LUWSecAppTable( this );
		tableSecDevice = new CFSecDb2LUWSecDeviceTable( this );
		tableSecForm = new CFSecDb2LUWSecFormTable( this );
		tableSecGroup = new CFSecDb2LUWSecGroupTable( this );
		tableSecGroupForm = new CFSecDb2LUWSecGroupFormTable( this );
		tableSecGrpInc = new CFSecDb2LUWSecGrpIncTable( this );
		tableSecGrpMemb = new CFSecDb2LUWSecGrpMembTable( this );
		tableSecSession = new CFSecDb2LUWSecSessionTable( this );
		tableSecUser = new CFSecDb2LUWSecUserTable( this );
		tableService = new CFSecDb2LUWServiceTable( this );
		tableServiceType = new CFSecDb2LUWServiceTypeTable( this );
		tableSysCluster = new CFSecDb2LUWSysClusterTable( this );
		tableTSecGroup = new CFSecDb2LUWTSecGroupTable( this );
		tableTSecGrpInc = new CFSecDb2LUWTSecGrpIncTable( this );
		tableTSecGrpMemb = new CFSecDb2LUWTSecGrpMembTable( this );
		tableTenant = new CFSecDb2LUWTenantTable( this );
		try {
			cnx.setAutoCommit( false );
			cnx.setTransactionIsolation( Connection.TRANSACTION_REPEATABLE_READ );
			cnx.rollback();
		}
		catch( SQLException e ) {
			throw new CFLibDbException( getClass(),
				"CFSecDb2LUWSchema-constructor",
				e );
		}
	}

	public Connection getCnx() {
		return( cnx );
	}

	public boolean isConnected() {
		final String S_ProcName = "isConnected";
		boolean retval;
		if( cnx == null ) {
			retval = false;
		}
		else {
			try {
				if( cnx.isClosed() ) {
					retval = false;
					cnx = null;
					releasePreparedStatements();
				}
				else {
					retval = true;
				}
			}
			catch( SQLException e ) {
				throw new CFLibDbException( getClass(),
					S_ProcName,
					e );
			}
		}
		return( retval );
	}

	public boolean connect() {
		final String S_ProcName = "connect";
		if( cnx != null ) {
			return( false );
		}

		if( configuration != null ) {
			try {
				Class.forName( "com.ibm.db2.jcc.DB2Driver" );
			}
			catch( ClassNotFoundException e ) {
				throw new CFLibRuntimeException( getClass(),
					"connect",
					"Could not load IBM DB/2 LUW driver",
					e );
			}
			String dbServer = configuration.getDbServer();
			int dbPort = configuration.getDbPort();
			String dbDatabase = configuration.getDbDatabase();
			String dbUserName = configuration.getDbUserName();
			String dbPassword = configuration.getDbPassword();
			String url =
					"jdbc:db2://" + dbServer
				+	":" + Integer.toString( dbPort )
				+	"/" + dbDatabase;
			Properties props = new Properties();
			props.setProperty( "user", dbUserName );
			props.setProperty( "password", dbPassword );
			try {
				cnx = DriverManager.getConnection( url, props );
				cnx.setAutoCommit( false );
				cnx.setTransactionIsolation( Connection.TRANSACTION_REPEATABLE_READ );
				cnx.rollback();
				setDbSchemaName( dbDatabase );
			}
			catch( SQLException e ) {
				throw new CFLibDbException( getClass(),
					S_ProcName,
					e );
			}
			return( true );
		}
		if( jndiName != null ) {
			try {
				Context ctx = new InitialContext();
				DataSource ds = (DataSource)ctx.lookup( jndiName );
				if( ds == null ) {
					throw new CFLibRuntimeException( getClass(),
						S_ProcName,
						"Could not get resolve DataSource \"" + jndiName + "\"" );
				}
				cnx = ds.getConnection();
				if( cnx == null ) {
					throw new CFLibRuntimeException( getClass(),
						S_ProcName,
						"Could not get Connection from PooledConnection for ConnectionPoolDataSource \"" + jndiName + "\"" );
				}
				cnx.setAutoCommit( false );
				cnx.setTransactionIsolation( Connection.TRANSACTION_REPEATABLE_READ );
				cnx.rollback();
			}
			catch( NamingException e ) {
				cnx = null;
				throw new CFLibRuntimeException( getClass(),
					S_ProcName,
					"NamingException " + e.getMessage(),
					e );
			}
			catch( SQLException e ) {
				cnx = null;
				inTransaction = false;
				throw new CFLibDbException( getClass(),
					S_ProcName,
					e );
			}
			return( true );
		}
		throw new CFLibUsageException( getClass(),
			S_ProcName,
			"Neither configurationFile nor jndiName found, do not know how to connect to database" );
	}

	public boolean connect( String username, String password ) {
		final String S_ProcName = "connect-userpw";
		if( cnx != null ) {
			return( false );
		}
		if( ( username == null ) || ( username.length() <= 0 ) ) {
			throw new CFLibNullArgumentException( getClass(),
				S_ProcName,
				1,
				"username" );
		}
		if( password == null ) {
			throw new CFLibNullArgumentException( getClass(),
				S_ProcName,
				1,
				"password" );
		}

		if( configuration != null ) {
			try {
				Class.forName( "com.ibm.db2.jcc.DB2Driver" );
			}
			catch( ClassNotFoundException e ) {
				throw new CFLibRuntimeException( getClass(),
					"connect",
					"Could not load IBM DB/2 LUW driver",
					e );
			}
			String dbServer = configuration.getDbServer();
			int dbPort = configuration.getDbPort();
			String dbDatabase = configuration.getDbDatabase();
			String dbUserName = username;
			String dbPassword = password;
			String url =
					"jdbc:db2://" + dbServer
				+	":" + Integer.toString( dbPort )
				+	"/" + dbDatabase;
			Properties props = new Properties();
			props.setProperty( "user", dbUserName );
			props.setProperty( "password", dbPassword );
			try {
				cnx = DriverManager.getConnection( url, props );
				cnx.setAutoCommit( false );
				cnx.setTransactionIsolation( Connection.TRANSACTION_REPEATABLE_READ );
				cnx.rollback();
				setDbSchemaName( dbDatabase );
			}
			catch( SQLException e ) {
				throw new CFLibDbException( getClass(),
					S_ProcName,
					e );
			}
			return( true );
		}
		throw new CFLibUsageException( getClass(),
			S_ProcName,
			"configurationFile not found, do not know how to connect to database" );
	}

	public void disconnect( boolean doCommit ) {
		final String S_ProcName = "disconnect";
		if( cnx != null ) {
			try {
				if( ! cnx.isClosed() ) {
					if( doCommit ) {
						cnx.commit();
					}
					else {
						cnx.rollback();
					}
					releasePreparedStatements();
					cnx.close();
				}
			}
			catch( SQLException e ) {
				throw new CFLibDbException( getClass(),
					S_ProcName,
					e );
			}
			finally {
				cnx = null;
			}
		}
		releasePreparedStatements();
	}

	public boolean isTransactionOpen() {
		return( inTransaction );
	}

	public boolean beginTransaction() {
		if( inTransaction ) {
			return( false );
		}
//		try {
//			String sql =
//					"begin transaction";
//			Statement stmt = cnx.createStatement( ResultSet.TYPE_FORWARD_ONLY, ResultSet.CONCUR_READ_ONLY );
//			stmt.execute( sql );
			inTransaction = true;
//		}
//		catch( SQLException e ) {
//			throw new CFLibDbException( getClass(),
//				"beginTransaction",
//				e );
//		}
		return( inTransaction );
	}

	public void commit() {
		try {
			cnx.commit();
			inTransaction = false;
		}
		catch( SQLException e ) {
			throw new CFLibDbException( getClass(),
				"commit",
				e );
		}
	}

	public void rollback() {
		try {
			if( cnx != null ) {
				cnx.rollback();
			}
			inTransaction = false;
		}
		catch( SQLException e ) {
			throw new CFLibDbException( getClass(),
				"rollback",
				e );
		}
	}

	public boolean isSystemUser( CFSecAuthorization Authorization) {
		if( ! inTransaction ) {
			throw new CFLibUsageException( getClass(),
				"isSystemUser",
				"Not in a transaction" );
		}
		ResultSet resultSet = null;
		try {
			final String sql = "SELECT sp_is_system_user( ? ) as IsSystemUser FROM sysibm.sysdummy1";
			if( stmtSelectIsSystemUser == null ) {
				stmtSelectIsSystemUser = cnx.prepareStatement( sql );
			}
			stmtSelectIsSystemUser.setString( 1, Authorization.getSecUserId().toString() );
			resultSet = stmtSelectIsSystemUser.executeQuery();
			int resultFlag;
			if( resultSet.next() ) {
				resultFlag = resultSet.getInt( 1 );
			}
			else {
				throw new CFLibRuntimeException( getClass(),
					"isSystemUser",
					"Query of sp_is_system_user() did not return a result row" );
			}
			resultSet.close();
			if( resultFlag == 0 ) {
				return( false );
			}
			else {
				return( true );
			}
		}
		catch( SQLException e ) {
			throw new CFLibDbException( getClass(),
				"isSystemUser",
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

	public boolean isClusterUser( CFSecAuthorization Authorization,
		long clusterId,
		String groupName )
	{
		if( ! inTransaction ) {
			throw new CFLibUsageException( getClass(),
				"isClusterUser",
				"Not in a transaction" );
		}
		ResultSet resultSet = null;
		try {
			final String sql = "SELECT sp_is_cluster_user( ?, ?, ? ) as IsClusterUser FROM sysibm.sysdummy1";
			if( stmtSelectIsClusterUser == null ) {
				stmtSelectIsClusterUser = cnx.prepareStatement( sql );
			}
			stmtSelectIsClusterUser.setLong( 1, clusterId );
			stmtSelectIsClusterUser.setString( 2, groupName );
			stmtSelectIsClusterUser.setString( 3, Authorization.getSecUserId().toString() );
			resultSet = stmtSelectIsClusterUser.executeQuery();
			int resultFlag;
			if( resultSet.next() ) {
				resultFlag = resultSet.getInt( 1 );
			}
			else {
				throw new CFLibRuntimeException( getClass(),
					"isClusterUser",
					"Query of sp_is_cluster_user() did not return a result row" );
			}
			resultSet.close();
			if( resultFlag == 0 ) {
				return( false );
			}
			else {
				return( true );
			}
		}
		catch( SQLException e ) {
			throw new CFLibDbException( getClass(),
				"isClusterUser",
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

	public boolean isTenantUser( CFSecAuthorization Authorization,
		long tenantId,
		String groupName )
	{
		if( ! inTransaction ) {
			throw new CFLibUsageException( getClass(),
				"isTenantUser",
				"Not in a transaction" );
		}
		ResultSet resultSet = null;
		try {
			final String sql = "SELECT sp_is_tenant_user( ?, ?, ? ) as IsTenantUser FROM sysibm.sysdummy1";
			if( stmtSelectIsTenantUser == null ) {
				stmtSelectIsTenantUser = cnx.prepareStatement( sql );
			}
			stmtSelectIsTenantUser.setLong( 1, tenantId );
			stmtSelectIsTenantUser.setString( 2, groupName );
			stmtSelectIsTenantUser.setString( 3, Authorization.getSecUserId().toString() );
			resultSet = stmtSelectIsTenantUser.executeQuery();
			int resultFlag;
			if( resultSet.next() ) {
				resultFlag = resultSet.getInt( 1 );
			}
			else {
				throw new CFLibRuntimeException( getClass(),
					"isTenantUser",
					"Query of sp_is_tenant_user() did not return a result row" );
			}
			resultSet.close();
			if( resultFlag == 0 ) {
				return( false );
			}
			else {
				return( true );
			}
		}
		catch( SQLException e ) {
			throw new CFLibDbException( getClass(),
				"isTenantUser",
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

	public short nextISOCcyIdGen() {
		ResultSet resultSet = null;
		if( ! inTransaction ) {
			throw new CFLibUsageException( getClass(),
				"nextISOCcyIdGen",
				"Not in a transaction" );
		}
		try {
			final String sql = "call sf_next_isoccyidgen()";
			if( stmtSelectNextISOCcyIdGen == null ) {
				stmtSelectNextISOCcyIdGen = cnx.prepareStatement( sql );
			}
			resultSet = stmtSelectNextISOCcyIdGen.executeQuery();
			short nextId;
			if( resultSet.next() ) {
				nextId = resultSet.getShort( 1 );
			}
			else {
				throw new CFLibRuntimeException( getClass(),
					"nextISOCcyIdGen",
					"Query of sf_next_isoccyidgen() did not return a result row" );
			}
			resultSet.close();
			return( nextId );
		}
		catch( SQLException e ) {
			throw new CFLibDbException( getClass(),
				"nextISOCcyIdGen",
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

	public short nextISOCtryIdGen() {
		ResultSet resultSet = null;
		if( ! inTransaction ) {
			throw new CFLibUsageException( getClass(),
				"nextISOCtryIdGen",
				"Not in a transaction" );
		}
		try {
			final String sql = "call sf_next_isoctryidgen()";
			if( stmtSelectNextISOCtryIdGen == null ) {
				stmtSelectNextISOCtryIdGen = cnx.prepareStatement( sql );
			}
			resultSet = stmtSelectNextISOCtryIdGen.executeQuery();
			short nextId;
			if( resultSet.next() ) {
				nextId = resultSet.getShort( 1 );
			}
			else {
				throw new CFLibRuntimeException( getClass(),
					"nextISOCtryIdGen",
					"Query of sf_next_isoctryidgen() did not return a result row" );
			}
			resultSet.close();
			return( nextId );
		}
		catch( SQLException e ) {
			throw new CFLibDbException( getClass(),
				"nextISOCtryIdGen",
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

	public short nextISOLangIdGen() {
		ResultSet resultSet = null;
		if( ! inTransaction ) {
			throw new CFLibUsageException( getClass(),
				"nextISOLangIdGen",
				"Not in a transaction" );
		}
		try {
			final String sql = "call sf_next_isolangidgen()";
			if( stmtSelectNextISOLangIdGen == null ) {
				stmtSelectNextISOLangIdGen = cnx.prepareStatement( sql );
			}
			resultSet = stmtSelectNextISOLangIdGen.executeQuery();
			short nextId;
			if( resultSet.next() ) {
				nextId = resultSet.getShort( 1 );
			}
			else {
				throw new CFLibRuntimeException( getClass(),
					"nextISOLangIdGen",
					"Query of sf_next_isolangidgen() did not return a result row" );
			}
			resultSet.close();
			return( nextId );
		}
		catch( SQLException e ) {
			throw new CFLibDbException( getClass(),
				"nextISOLangIdGen",
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

	public short nextISOTZoneIdGen() {
		ResultSet resultSet = null;
		if( ! inTransaction ) {
			throw new CFLibUsageException( getClass(),
				"nextISOTZoneIdGen",
				"Not in a transaction" );
		}
		try {
			final String sql = "call sf_next_isotzoneidgen()";
			if( stmtSelectNextISOTZoneIdGen == null ) {
				stmtSelectNextISOTZoneIdGen = cnx.prepareStatement( sql );
			}
			resultSet = stmtSelectNextISOTZoneIdGen.executeQuery();
			short nextId;
			if( resultSet.next() ) {
				nextId = resultSet.getShort( 1 );
			}
			else {
				throw new CFLibRuntimeException( getClass(),
					"nextISOTZoneIdGen",
					"Query of sf_next_isotzoneidgen() did not return a result row" );
			}
			resultSet.close();
			return( nextId );
		}
		catch( SQLException e ) {
			throw new CFLibDbException( getClass(),
				"nextISOTZoneIdGen",
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

	public int nextServiceTypeIdGen() {
		if( ! inTransaction ) {
			throw new CFLibUsageException( getClass(),
				"nextServiceTypeIdGen",
				"Not in a transaction" );
		}
		ResultSet resultSet = null;
		try {
			final String sql = "call sf_next_servicetypeidgen()";
			if( stmtSelectNextServiceTypeIdGen == null ) {
				stmtSelectNextServiceTypeIdGen = cnx.prepareStatement( sql );
			}
			resultSet = stmtSelectNextServiceTypeIdGen.executeQuery();
			int nextId;
			if( resultSet.next() ) {
				nextId = resultSet.getInt( 1 );
			}
			else {
				throw new CFLibRuntimeException( getClass(),
					"nextServiceTypeIdGen",
					"Query of sf_next_servicetypeidgen() did not return a result row" );
			}
			resultSet.close();
			return( nextId );
		}
		catch( SQLException e ) {
			throw new CFLibDbException( getClass(),
				"nextServiceTypeIdGen",
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

	public long nextClusterIdGen() {
		if( ! inTransaction ) {
			throw new CFLibUsageException( getClass(),
				"nextClusterIdGen",
				"Not in a transaction" );
		}
		ResultSet resultSet = null;
		try {
			final String sql = "call sf_next_clusteridgen()";
			if( stmtSelectNextClusterIdGen == null ) {
				stmtSelectNextClusterIdGen = cnx.prepareStatement( sql );
			}
			resultSet = stmtSelectNextClusterIdGen.executeQuery();
			long nextId;
			if( resultSet.next() ) {
				nextId = resultSet.getLong( 1 );
			}
			else {
				throw new CFLibRuntimeException( getClass(),
					"nextClusterIdGen",
					"Query of sf_next_clusteridgen() did not return a result row" );
			}
			resultSet.close();
			return( nextId );
		}
		catch( SQLException e ) {
			throw new CFLibDbException( getClass(),
				"nextClusterIdGen",
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

	public long nextTenantIdGen() {
		if( ! inTransaction ) {
			throw new CFLibUsageException( getClass(),
				"nextTenantIdGen",
				"Not in a transaction" );
		}
		ResultSet resultSet = null;
		try {
			final String sql = "call sf_next_tenantidgen()";
			if( stmtSelectNextTenantIdGen == null ) {
				stmtSelectNextTenantIdGen = cnx.prepareStatement( sql );
			}
			resultSet = stmtSelectNextTenantIdGen.executeQuery();
			long nextId;
			if( resultSet.next() ) {
				nextId = resultSet.getLong( 1 );
			}
			else {
				throw new CFLibRuntimeException( getClass(),
					"nextTenantIdGen",
					"Query of sf_next_tenantidgen() did not return a result row" );
			}
			resultSet.close();
			return( nextId );
		}
		catch( SQLException e ) {
			throw new CFLibDbException( getClass(),
				"nextTenantIdGen",
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

	public UUID nextSecSessionIdGen() {
		UUID retval = UUID.randomUUID();
		return( retval );
	}

	public UUID nextSecUserIdGen() {
		UUID retval = UUID.randomUUID();
		return( retval );
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

		if( stmtSelectNextISOCcyIdGen != null ) {
			try {
				stmtSelectNextISOCcyIdGen.close();
			}
			catch( SQLException e ) {
				throw new CFLibDbException( getClass(),
					S_ProcName,
					e );
			}
			stmtSelectNextISOCcyIdGen = null;
		}
		if( stmtSelectNextISOCtryIdGen != null ) {
			try {
				stmtSelectNextISOCtryIdGen.close();
			}
			catch( SQLException e ) {
				throw new CFLibDbException( getClass(),
					S_ProcName,
					e );
			}
			stmtSelectNextISOCtryIdGen = null;
		}
		if( stmtSelectNextISOLangIdGen != null ) {
			try {
				stmtSelectNextISOLangIdGen.close();
			}
			catch( SQLException e ) {
				throw new CFLibDbException( getClass(),
					S_ProcName,
					e );
			}
			stmtSelectNextISOLangIdGen = null;
		}
		if( stmtSelectNextISOTZoneIdGen != null ) {
			try {
				stmtSelectNextISOTZoneIdGen.close();
			}
			catch( SQLException e ) {
				throw new CFLibDbException( getClass(),
					S_ProcName,
					e );
			}
			stmtSelectNextISOTZoneIdGen = null;
		}
		if( stmtSelectNextServiceTypeIdGen != null ) {
			try {
				stmtSelectNextServiceTypeIdGen.close();
			}
			catch( SQLException e ) {
				throw new CFLibDbException( getClass(),
					S_ProcName,
					e );
			}
			stmtSelectNextServiceTypeIdGen = null;
		}
		if( stmtSelectNextClusterIdGen != null ) {
			try {
				stmtSelectNextClusterIdGen.close();
			}
			catch( SQLException e ) {
				throw new CFLibDbException( getClass(),
					S_ProcName,
					e );
			}
			stmtSelectNextClusterIdGen = null;
		}
		if( stmtSelectNextTenantIdGen != null ) {
			try {
				stmtSelectNextTenantIdGen.close();
			}
			catch( SQLException e ) {
				throw new CFLibDbException( getClass(),
					S_ProcName,
					e );
			}
			stmtSelectNextTenantIdGen = null;
		}

		if( ( tableCluster != null ) && ( tableCluster instanceof CFSecDb2LUWClusterTable ) ) {
			CFSecDb2LUWClusterTable table = (CFSecDb2LUWClusterTable)tableCluster;
			table.releasePreparedStatements();
		}
		if( ( tableHostNode != null ) && ( tableHostNode instanceof CFSecDb2LUWHostNodeTable ) ) {
			CFSecDb2LUWHostNodeTable table = (CFSecDb2LUWHostNodeTable)tableHostNode;
			table.releasePreparedStatements();
		}
		if( ( tableISOCcy != null ) && ( tableISOCcy instanceof CFSecDb2LUWISOCcyTable ) ) {
			CFSecDb2LUWISOCcyTable table = (CFSecDb2LUWISOCcyTable)tableISOCcy;
			table.releasePreparedStatements();
		}
		if( ( tableISOCtry != null ) && ( tableISOCtry instanceof CFSecDb2LUWISOCtryTable ) ) {
			CFSecDb2LUWISOCtryTable table = (CFSecDb2LUWISOCtryTable)tableISOCtry;
			table.releasePreparedStatements();
		}
		if( ( tableISOCtryCcy != null ) && ( tableISOCtryCcy instanceof CFSecDb2LUWISOCtryCcyTable ) ) {
			CFSecDb2LUWISOCtryCcyTable table = (CFSecDb2LUWISOCtryCcyTable)tableISOCtryCcy;
			table.releasePreparedStatements();
		}
		if( ( tableISOCtryLang != null ) && ( tableISOCtryLang instanceof CFSecDb2LUWISOCtryLangTable ) ) {
			CFSecDb2LUWISOCtryLangTable table = (CFSecDb2LUWISOCtryLangTable)tableISOCtryLang;
			table.releasePreparedStatements();
		}
		if( ( tableISOLang != null ) && ( tableISOLang instanceof CFSecDb2LUWISOLangTable ) ) {
			CFSecDb2LUWISOLangTable table = (CFSecDb2LUWISOLangTable)tableISOLang;
			table.releasePreparedStatements();
		}
		if( ( tableISOTZone != null ) && ( tableISOTZone instanceof CFSecDb2LUWISOTZoneTable ) ) {
			CFSecDb2LUWISOTZoneTable table = (CFSecDb2LUWISOTZoneTable)tableISOTZone;
			table.releasePreparedStatements();
		}
		if( ( tableSecApp != null ) && ( tableSecApp instanceof CFSecDb2LUWSecAppTable ) ) {
			CFSecDb2LUWSecAppTable table = (CFSecDb2LUWSecAppTable)tableSecApp;
			table.releasePreparedStatements();
		}
		if( ( tableSecDevice != null ) && ( tableSecDevice instanceof CFSecDb2LUWSecDeviceTable ) ) {
			CFSecDb2LUWSecDeviceTable table = (CFSecDb2LUWSecDeviceTable)tableSecDevice;
			table.releasePreparedStatements();
		}
		if( ( tableSecForm != null ) && ( tableSecForm instanceof CFSecDb2LUWSecFormTable ) ) {
			CFSecDb2LUWSecFormTable table = (CFSecDb2LUWSecFormTable)tableSecForm;
			table.releasePreparedStatements();
		}
		if( ( tableSecGroup != null ) && ( tableSecGroup instanceof CFSecDb2LUWSecGroupTable ) ) {
			CFSecDb2LUWSecGroupTable table = (CFSecDb2LUWSecGroupTable)tableSecGroup;
			table.releasePreparedStatements();
		}
		if( ( tableSecGroupForm != null ) && ( tableSecGroupForm instanceof CFSecDb2LUWSecGroupFormTable ) ) {
			CFSecDb2LUWSecGroupFormTable table = (CFSecDb2LUWSecGroupFormTable)tableSecGroupForm;
			table.releasePreparedStatements();
		}
		if( ( tableSecGrpInc != null ) && ( tableSecGrpInc instanceof CFSecDb2LUWSecGrpIncTable ) ) {
			CFSecDb2LUWSecGrpIncTable table = (CFSecDb2LUWSecGrpIncTable)tableSecGrpInc;
			table.releasePreparedStatements();
		}
		if( ( tableSecGrpMemb != null ) && ( tableSecGrpMemb instanceof CFSecDb2LUWSecGrpMembTable ) ) {
			CFSecDb2LUWSecGrpMembTable table = (CFSecDb2LUWSecGrpMembTable)tableSecGrpMemb;
			table.releasePreparedStatements();
		}
		if( ( tableSecSession != null ) && ( tableSecSession instanceof CFSecDb2LUWSecSessionTable ) ) {
			CFSecDb2LUWSecSessionTable table = (CFSecDb2LUWSecSessionTable)tableSecSession;
			table.releasePreparedStatements();
		}
		if( ( tableSecUser != null ) && ( tableSecUser instanceof CFSecDb2LUWSecUserTable ) ) {
			CFSecDb2LUWSecUserTable table = (CFSecDb2LUWSecUserTable)tableSecUser;
			table.releasePreparedStatements();
		}
		if( ( tableService != null ) && ( tableService instanceof CFSecDb2LUWServiceTable ) ) {
			CFSecDb2LUWServiceTable table = (CFSecDb2LUWServiceTable)tableService;
			table.releasePreparedStatements();
		}
		if( ( tableServiceType != null ) && ( tableServiceType instanceof CFSecDb2LUWServiceTypeTable ) ) {
			CFSecDb2LUWServiceTypeTable table = (CFSecDb2LUWServiceTypeTable)tableServiceType;
			table.releasePreparedStatements();
		}
		if( ( tableSysCluster != null ) && ( tableSysCluster instanceof CFSecDb2LUWSysClusterTable ) ) {
			CFSecDb2LUWSysClusterTable table = (CFSecDb2LUWSysClusterTable)tableSysCluster;
			table.releasePreparedStatements();
		}
		if( ( tableTSecGroup != null ) && ( tableTSecGroup instanceof CFSecDb2LUWTSecGroupTable ) ) {
			CFSecDb2LUWTSecGroupTable table = (CFSecDb2LUWTSecGroupTable)tableTSecGroup;
			table.releasePreparedStatements();
		}
		if( ( tableTSecGrpInc != null ) && ( tableTSecGrpInc instanceof CFSecDb2LUWTSecGrpIncTable ) ) {
			CFSecDb2LUWTSecGrpIncTable table = (CFSecDb2LUWTSecGrpIncTable)tableTSecGrpInc;
			table.releasePreparedStatements();
		}
		if( ( tableTSecGrpMemb != null ) && ( tableTSecGrpMemb instanceof CFSecDb2LUWTSecGrpMembTable ) ) {
			CFSecDb2LUWTSecGrpMembTable table = (CFSecDb2LUWTSecGrpMembTable)tableTSecGrpMemb;
			table.releasePreparedStatements();
		}
		if( ( tableTenant != null ) && ( tableTenant instanceof CFSecDb2LUWTenantTable ) ) {
			CFSecDb2LUWTenantTable table = (CFSecDb2LUWTenantTable)tableTenant;
			table.releasePreparedStatements();
		}
	}

	public static String getQuotedString(String val) {
		if (val == null) {
			return ("null");
		}
		else {
			char c;
			StringBuilder quoted = new StringBuilder();
			quoted.append( "'" );
			int len = val.length();
			for (int i = 0; i < len; i++)
			{
				if (val.charAt( i ) == '\'')
				{
					quoted.append("''");
				}
				else if (val.charAt( i ) == '\\') {
					quoted.append("'||E'\\\\'||'");
				}
				else {
					c = val.charAt( i );
					if (   ( c == '0' )
						|| ( c == '1' )
						|| ( c == '2' )
						|| ( c == '3' )
						|| ( c == '4' )
						|| ( c == '5' )
						|| ( c == '6' )
						|| ( c == '7' )
						|| ( c == '8' )
						|| ( c == '9' )
						|| ( c == 'a' )
						|| ( c == 'b' )
						|| ( c == 'c' )
						|| ( c == 'd' )
						|| ( c == 'e' )
						|| ( c == 'f' )
						|| ( c == 'g' )
						|| ( c == 'h' )
						|| ( c == 'i' )
						|| ( c == 'j' )
						|| ( c == 'k' )
						|| ( c == 'l' )
						|| ( c == 'm' )
						|| ( c == 'n' )
						|| ( c == 'o' )
						|| ( c == 'p' )
						|| ( c == 'q' )
						|| ( c == 'r' )
						|| ( c == 's' )
						|| ( c == 't' )
						|| ( c == 'u' )
						|| ( c == 'v' )
						|| ( c == 'w' )
						|| ( c == 'x' )
						|| ( c == 'y' )
						|| ( c == 'z' )
						|| ( c == 'A' )
						|| ( c == 'B' )
						|| ( c == 'C' )
						|| ( c == 'D' )
						|| ( c == 'E' )
						|| ( c == 'F' )
						|| ( c == 'G' )
						|| ( c == 'H' )
						|| ( c == 'I' )
						|| ( c == 'J' )
						|| ( c == 'K' )
						|| ( c == 'L' )
						|| ( c == 'M' )
						|| ( c == 'N' )
						|| ( c == 'O' )
						|| ( c == 'P' )
						|| ( c == 'Q' )
						|| ( c == 'R' )
						|| ( c == 'S' )
						|| ( c == 'T' )
						|| ( c == 'U' )
						|| ( c == 'V' )
						|| ( c == 'W' )
						|| ( c == 'X' )
						|| ( c == 'Y' )
						|| ( c == 'Z' )
						|| ( c == ' ' )
						|| ( c == '\t' )
						|| ( c == '\r' )
						|| ( c == '\n' )
						|| ( c == '`' )
						|| ( c == '~' )
						|| ( c == '!' )
						|| ( c == '@' )
						|| ( c == '#' )
						|| ( c == '$' )
						|| ( c == '%' )
						|| ( c == '^' )
						|| ( c == '&' )
						|| ( c == '*' )
						|| ( c == '(' )
						|| ( c == ')' )
						|| ( c == '-' )
						|| ( c == '_' )
						|| ( c == '=' )
						|| ( c == '+' )
						|| ( c == '[' )
						|| ( c == ']' )
						|| ( c == '{' )
						|| ( c == '}' )
						|| ( c == '|' )
						|| ( c == ';' )
						|| ( c == ':' )
						|| ( c == '"' )
						|| ( c == '<' )
						|| ( c == '>' )
						|| ( c == ',' )
						|| ( c == '.' )
						|| ( c == '/' )
						|| ( c == '?' ))
					{
						quoted.append(c);
					}
					else {
//						Syslog.warn("\t\t\tReplacing invalid character '" + c + "' with space");
						quoted.append( ' ' );
					}
				}
			}
			quoted.append( "'" );
			return (quoted.toString());
			}
		}

	public static String getNullableString(ResultSet reader, int colidx) {
		try {
			String val = reader.getString( colidx );
			if( reader.wasNull() ) {
				return(null);
			}
			else {
				return( val );
			}
		}
		catch( SQLException e ) {
			throw new CFLibDbException( CFSecDb2LUWSchema.class,
				"getNullableString",
				e );
		}
	}

	public static String getBlobString(byte[] val) {
		if( val == null ) {
			return( "null" );
		}
		else {
			return( "'" + new String( Base64.encodeBase64( val ) ) + "'" );
		}
	}

	public static String getBoolString(Boolean val) {
		if( val == null ) {
			return( "null" );
		}
		else {
			if( val ) {
				return( "'Y'" );
			}
			else {
				return( "'N'" );
			}
		}
	}

	public static String getBoolString(boolean val) {
		if( val ) {
			return( "'Y'" );
		}
		else {
			return( "'N'" );
		}
	}

	public static String getInt16String(Short val) {
		if( val == null ) {
			return( "null" );
		}
		else {
			return( val.toString() );
		}
	}

	public static String getInt16String(short val) {
		return( Short.toString( val ) );
	}

	public static String getInt32String(Integer val) {
		if( val == null ) {
			return( "null" );
		}
		else {
			return( val.toString() );
		}
	}

	public static String getInt32String(int val) {
		return( Integer.toString( val ) );
	}

	public static String getInt64String(Long val) {
		if( val == null ) {
			return( "null" );
		}
		else {
			return( val.toString() );
		}
	}

	public static String getInt64String(long val) {
		return( Long.toString( val ) );
	}

	public static String getUInt16String(Integer val) {
		if( val == null ) {
			return( "null" );
		}
		else {
			return( val.toString() );
		}
	}

	public static String getUInt16String(int val) {
		return( Integer.toString( val ) );
	}

	public static String getUInt32String(Long val) {
		if( val == null ) {
			return( "null" );
		}
		else {
			return( val.toString() );
		}
	}

	public static String getUInt32String(long val) {
		return( Long.toString( val ) );
	}

	public static String getUInt64String(BigDecimal val) {
		if( val == null ) {
			return( "null" );
		}
		else {
			return( val.toString() );
		}
	}

	public static String getFloatString(Float val) {
		if( val == null ) {
			return( "null" );
		}
		else {
			return( val.toString() );
		}
	}

	public static String getFloatString(float val) {
		return( Float.toString( val ) );
	}

	public static String getDoubleString(Double val) {
		if( val == null ) {
			return( "null" );
		}
		else {
			return( val.toString() );
		}
	}

	public static String getDoubleString(double val) {
		return( Double.toString( val ) );
	}

	public static String getNumberString(BigDecimal val) {
		if( val == null ) {
			return( "null" );
		}
		else {
			return( val.toString() );
		}
	}

	public static Integer getNullableInt32(ResultSet reader, int colidx) {
		try {
			int val = reader.getInt( colidx );
			if( reader.wasNull() ) {
				return(null);
			}
			else {
				return( Integer.valueOf( val ) );
			}
		}
		catch( SQLException e ) {
			throw new CFLibDbException( CFSecDb2LUWSchema.class,
				"getNullableInt32",
				e );
		}
	}

	public static Short getNullableInt16(ResultSet reader, int colidx) {
		try {
			short val = reader.getShort( colidx );
			if( reader.wasNull() ) {
				return(null);
			}
			else {
				return( Short.valueOf( val ) );
			}
		}
		catch( SQLException e ) {
			throw new CFLibDbException( CFSecDb2LUWSchema.class,
				"getNullableInt64",
				e );
		}
	}

	public static Integer getNullableUInt16(ResultSet reader, int colidx) {
		try {
			int val = reader.getInt( colidx );
			if( reader.wasNull() ) {
				return(null);
			}
			else {
				return( Integer.valueOf( val ) );
			}
		}
		catch( SQLException e ) {
			throw new CFLibDbException( CFSecDb2LUWSchema.class,
				"getNullableUInt16",
				e );
		}
	}

	public static Long getNullableUInt32(ResultSet reader, int colidx) {
		try {
			long val = reader.getLong( colidx );
			if( reader.wasNull() ) {
				return(null);
			}
			else {
				return( Long.valueOf( val ) );
			}
		}
		catch( SQLException e ) {
			throw new CFLibDbException( CFSecDb2LUWSchema.class,
				"getNullableUInt32",
				e );
		}
	}

	public static BigDecimal getNullableUInt64(ResultSet reader, int colidx) {
		try {
			String strval = reader.getString( colidx );
			if( reader.wasNull() || ( strval == null ) || ( strval.length() <=0 ) ) {
				return(null);
			}
			else {
				BigDecimal retval = new BigDecimal( strval );
				return( retval );
			}
		}
		catch( SQLException e ) {
			throw new CFLibDbException( CFSecDb2LUWSchema.class,
				"getNullableUInt64",
				e );
		}
	}

	public static Byte getNullableByte(ResultSet reader, int colidx) {
		try {
			byte val = reader.getByte( colidx );
			if( reader.wasNull() ) {
				return(null);
			}
			else {
				return( Byte.valueOf( val ) );
			}
		}
		catch( SQLException e ) {
			throw new CFLibDbException( CFSecDb2LUWSchema.class,
				"getNullableByte",
				e );
		}
	}

	public static String getQuotedDateString(Calendar val) {
		if ( val == null ) {
			return ("null");
		}
		else {
			StringBuffer buff = new StringBuffer( "'" );
			Formatter fmt = new Formatter( buff );
			Calendar db = CFLibDbUtil.getDbServerCalendar( val );
			fmt.format( "%1$04d", db.get( Calendar.YEAR ) );
			buff.append( "-" );
			fmt.format( "%1$02d", db.get( Calendar.MONTH ) + 1 );
			buff.append( "-" );
			fmt.format( "%1$02d", db.get( Calendar.DAY_OF_MONTH ) );
			buff.append( "'" );
			fmt.close();
			return( buff.toString() );
		}
	}

	public static String getQuotedTimeString(Calendar val) {
		if ( val == null ) {
			return ("null");
		}
		else {
			StringBuffer buff = new StringBuffer( "'" );
			Formatter fmt = new Formatter( buff );
			Calendar db = CFLibDbUtil.getDbServerCalendar( val );
			fmt.format( "%1$02d", db.get( Calendar.HOUR_OF_DAY ) );
			buff.append( "." );
			fmt.format( "%1$02d", db.get( Calendar.MINUTE ) );
			buff.append( "." );
			fmt.format( "%1$02d", db.get( Calendar.SECOND ) );
			buff.append( "'" );
			fmt.close();
			return( buff.toString() );
		}
	}

	public static String getQuotedTimestampString(Calendar val) {
		if ( val == null ) {
			return ("null");
		}
		else {
			StringBuffer buff = new StringBuffer( "'" );
			Formatter fmt = new Formatter( buff );
			Calendar db = CFLibDbUtil.getDbServerCalendar( val );
			fmt.format( "%1$04d", db.get( Calendar.YEAR ) );
			buff.append( "-" );
			fmt.format( "%1$02d", db.get( Calendar.MONTH ) + 1 );
			buff.append( "-" );
			fmt.format( "%1$02d", db.get( Calendar.DAY_OF_MONTH ) );
			buff.append( "-" );
			fmt.format( "%1$02d", db.get( Calendar.HOUR_OF_DAY ) );
			buff.append( "." );
			fmt.format( "%1$02d", db.get( Calendar.MINUTE ) );
			buff.append( "." );
			fmt.format( "%1$02d", db.get( Calendar.SECOND ) );
			buff.append( "'" );
			fmt.close();
			return( buff.toString() );
		}
	}

	public static String getQuotedTZDateString(Calendar val) {
		if ( val == null ) {
			return ("null");
		}
		else {
			Calendar db = CFLibDbUtil.getDbServerCalendar( val );
			StringBuffer buff = new StringBuffer( "'" );
			Formatter fmt = new Formatter( buff );
			fmt.format( "%1$04d", db.get( Calendar.YEAR ) );
			buff.append( "-" );
			fmt.format( "%1$02d", db.get( Calendar.MONTH ) + 1 );
			buff.append( "-" );
			fmt.format( "%1$02d", db.get( Calendar.DAY_OF_MONTH ) );
			buff.append( "-" );
			fmt.format( "%1$02d", db.get( Calendar.HOUR_OF_DAY ) );
			buff.append( "." );
			fmt.format( "%1$02d", db.get( Calendar.MINUTE ) );
			buff.append( "." );
			fmt.format( "%1$02d", db.get( Calendar.SECOND ) );
			buff.append( "'" );
			fmt.close();
			return( buff.toString() );
		}
	}

	public static String getQuotedTZTimeString(Calendar val) {
		if ( val == null ) {
			return ("null");
		}
		else {
			Calendar db = CFLibDbUtil.getDbServerCalendar( val );
			StringBuffer buff = new StringBuffer( "'" );
			Formatter fmt = new Formatter( buff );
			fmt.format( "%1$04d", db.get( Calendar.YEAR ) );
			buff.append( "-" );
			fmt.format( "%1$02d", db.get( Calendar.MONTH ) + 1 );
			buff.append( "-" );
			fmt.format( "%1$02d", db.get( Calendar.DAY_OF_MONTH ) );
			buff.append( "-" );
			fmt.format( "%1$02d", db.get( Calendar.HOUR_OF_DAY ) );
			buff.append( "." );
			fmt.format( "%1$02d", db.get( Calendar.MINUTE ) );
			buff.append( "." );
			fmt.format( "%1$02d", db.get( Calendar.SECOND ) );
			buff.append( "'" );
			fmt.close();
			return( buff.toString() );
		}
	}

	public static String getQuotedTZTimestampString(Calendar val) {
		if ( val == null ) {
			return ("null");
		}
		else {
			Calendar db = CFLibDbUtil.getDbServerCalendar( val );
			StringBuffer buff = new StringBuffer( "'" );
			Formatter fmt = new Formatter( buff );
			fmt.format( "%1$04d", db.get( Calendar.YEAR ) );
			buff.append( "-" );
			fmt.format( "%1$02d", db.get( Calendar.MONTH ) + 1 );
			buff.append( "-" );
			fmt.format( "%1$02d", db.get( Calendar.DAY_OF_MONTH ) );
			buff.append( "-" );
			fmt.format( "%1$02d", db.get( Calendar.HOUR_OF_DAY ) );
			buff.append( "." );
			fmt.format( "%1$02d", db.get( Calendar.MINUTE ) );
			buff.append( "." );
			fmt.format( "%1$02d", db.get( Calendar.SECOND ) );
			buff.append( "'" );
			fmt.close();
			return( buff.toString() );
		}
	}

	public static String getDateString(Calendar val) {
		if ( val == null ) {
			return ("null");
		}
		else {
			StringBuffer buff = new StringBuffer();
			Formatter fmt = new Formatter( buff );
			Calendar db = CFLibDbUtil.getDbServerCalendar( val );
			fmt.format( "%1$04d", db.get( Calendar.YEAR ) );
			buff.append( "-" );
			fmt.format( "%1$02d", db.get( Calendar.MONTH ) + 1 );
			buff.append( "-" );
			fmt.format( "%1$02d", db.get( Calendar.DAY_OF_MONTH ) );
			fmt.close();
			return( buff.toString() );
		}
	}

	public static String getTimeString(Calendar val) {
		if ( val == null ) {
			return ("null");
		}
		else {
			StringBuffer buff = new StringBuffer();
			Formatter fmt = new Formatter( buff );
			Calendar db = CFLibDbUtil.getDbServerCalendar( val );
			fmt.format( "%1$02d", db.get( Calendar.HOUR_OF_DAY ) );
			buff.append( "." );
			fmt.format( "%1$02d", db.get( Calendar.MINUTE ) );
			buff.append( "." );
			fmt.format( "%1$02d", db.get( Calendar.SECOND ) );
			fmt.close();
			return( buff.toString() );
		}
	}

	public static String getTimestampString(Calendar val) {
		if ( val == null ) {
			return ("null");
		}
		else {
			StringBuffer buff = new StringBuffer();
			Formatter fmt = new Formatter( buff );
			Calendar db = CFLibDbUtil.getDbServerCalendar( val );
			fmt.format( "%1$04d", db.get( Calendar.YEAR ) );
			buff.append( "-" );
			fmt.format( "%1$02d", db.get( Calendar.MONTH ) + 1 );
			buff.append( "-" );
			fmt.format( "%1$02d", db.get( Calendar.DAY_OF_MONTH ) );
			buff.append( "-" );
			fmt.format( "%1$02d", db.get( Calendar.HOUR_OF_DAY ) );
			buff.append( "." );
			fmt.format( "%1$02d", db.get( Calendar.MINUTE ) );
			buff.append( "." );
			fmt.format( "%1$02d", db.get( Calendar.SECOND ) );
			fmt.close();
			return( buff.toString() );
		}
	}

	public static String getTZDateString(Calendar val) {
		if ( val == null ) {
			return ("null");
		}
		else {
			Calendar db = CFLibDbUtil.getDbServerCalendar( val );
			StringBuffer buff = new StringBuffer();
			Formatter fmt = new Formatter( buff );
			fmt.format( "%1$04d", db.get( Calendar.YEAR ) );
			buff.append( "-" );
			fmt.format( "%1$02d", db.get( Calendar.MONTH ) + 1 );
			buff.append( "-" );
			fmt.format( "%1$02d", db.get( Calendar.DAY_OF_MONTH ) );
			buff.append( "-" );
			fmt.format( "%1$02d", db.get( Calendar.HOUR_OF_DAY ) );
			buff.append( "." );
			fmt.format( "%1$02d", db.get( Calendar.MINUTE ) );
			buff.append( "." );
			fmt.format( "%1$02d", db.get( Calendar.SECOND ) );
			fmt.close();
			return( buff.toString() );
		}
	}

	public static String getTZTimeString(Calendar val) {
		if ( val == null ) {
			return ("null");
		}
		else {
			Calendar db = CFLibDbUtil.getDbServerCalendar( val );
			StringBuffer buff = new StringBuffer();
			Formatter fmt = new Formatter( buff );
			fmt.format( "%1$04d", db.get( Calendar.YEAR ) );
			buff.append( "-" );
			fmt.format( "%1$02d", db.get( Calendar.MONTH ) + 1 );
			buff.append( "-" );
			fmt.format( "%1$02d", db.get( Calendar.DAY_OF_MONTH ) );
			buff.append( "-" );
			fmt.format( "%1$02d", db.get( Calendar.HOUR_OF_DAY ) );
			buff.append( "." );
			fmt.format( "%1$02d", db.get( Calendar.MINUTE ) );
			buff.append( "." );
			fmt.format( "%1$02d", db.get( Calendar.SECOND ) );
			fmt.close();
			return( buff.toString() );
		}
	}

	public static String getTZTimestampString(Calendar val) {
		if ( val == null ) {
			return ("null");
		}
		else {
			Calendar db = CFLibDbUtil.getDbServerCalendar( val );
			StringBuffer buff = new StringBuffer();
			Formatter fmt = new Formatter( buff );
			fmt.format( "%1$04d", db.get( Calendar.YEAR ) );
			buff.append( "-" );
			fmt.format( "%1$02d", db.get( Calendar.MONTH ) + 1 );
			buff.append( "-" );
			fmt.format( "%1$02d", db.get( Calendar.DAY_OF_MONTH ) );
			buff.append( "-" );
			fmt.format( "%1$02d", db.get( Calendar.HOUR_OF_DAY ) );
			buff.append( "." );
			fmt.format( "%1$02d", db.get( Calendar.MINUTE ) );
			buff.append( "." );
			fmt.format( "%1$02d", db.get( Calendar.SECOND ) );
			fmt.close();
			return( buff.toString() );
		}
	}

	public static String getUuidString(UUID val) {
		if ( val == null ) {
			return ("null");
		}
		else {
			return( "'" + val.toString() + "'" );
		}
	}

	public static Calendar convertDateString(String val) {
		if( ( val == null ) || ( val.length() == 0 ) ) {
			return( null );
		}
		else if ( val.length() != 10 ) {
			throw new CFLibUsageException( CFSecDb2LUWSchema.class,
				"convertDateString",
				"Value must be in YYYY-MM-DD format, \"" + val + "\" is invalid" );
		}
		else if (((val.charAt( 0 ) >= '0') && (val.charAt( 0 ) <= '9'))
			 && ((val.charAt( 1 ) >= '0') && (val.charAt( 1 ) <= '9'))
			 && ((val.charAt( 2 ) >= '0') && (val.charAt( 2 ) <= '9'))
			 && ((val.charAt( 3 ) >= '0') && (val.charAt( 3 ) <= '9'))
			 && (val.charAt( 4 ) == '-')
			 && ((val.charAt( 5 ) >= '0') && (val.charAt( 5 ) <= '1'))
			 && ((val.charAt( 6 ) >= '0') && (val.charAt( 6 ) <= '9'))
			 && (val.charAt( 7 ) == '-' )
			 && ((val.charAt( 8 ) >= '0') && (val.charAt( 8 ) <= '3'))
			 && ((val.charAt( 9 ) >= '0') && (val.charAt( 9 ) <= '9')) )
		{
			/*
			 *	NOTE:
			 *		.Net uses substring( startcol, lengthOfSubstring )
			 *		Java uses substring( startcol, endcol ) and does not
			 *			include charAt( endcol );
			 */
			int year = Integer.parseInt( val.substring( 0, 4 ) );
			int month = Integer.parseInt( val.substring( 5, 7 ) );
			int day = Integer.parseInt( val.substring( 8, 10 ) );
			Calendar retval = new GregorianCalendar( CFLibDbUtil.getDbServerTimeZone() );
			retval.set( Calendar.YEAR, year );
			retval.set( Calendar.MONTH, month - 1 );
			retval.set( Calendar.DAY_OF_MONTH, day );
			retval.set( Calendar.HOUR_OF_DAY, 0 );
			retval.set( Calendar.MINUTE, 0 );
			retval.set( Calendar.SECOND, 0 );
			Calendar local = new GregorianCalendar();
			local.setTimeInMillis( retval.getTimeInMillis() );
			return( local );
		}
		else {
			throw new CFLibUsageException( CFSecDb2LUWSchema.class,
				"convertDateString",
				"Value must be in YYYY-MM-DD format, \"" + val + "\" is invalid" );
		}
	}
	public static Calendar convertTimeString(String val) {
		if( ( val == null ) || ( val.length() == 0 ) ) {
			return( null );
		}
		else if ( val.length() != 8 ) {
			throw new CFLibUsageException( CFSecDb2LUWSchema.class,
				"convertTimeString",
				"Value must be in HH24.MI.SS format, \"" + val + "\" is invalid" );
		}
		else if (((val.charAt( 0 ) >= '0') && (val.charAt( 0 ) <= '2'))
			 && ((val.charAt( 1 ) >= '0') && (val.charAt( 1 ) <= '9'))
			 && (val.charAt( 2 ) == '.')
			 && ((val.charAt( 3 ) >= '0') && (val.charAt( 3 ) <= '5'))
			 && ((val.charAt( 4 ) >= '0') && (val.charAt( 4 ) <= '9'))
			 && (val.charAt( 5 ) == '.')
			 && ((val.charAt( 6 ) >= '0') && (val.charAt( 6 ) <= '5'))
			 && ((val.charAt( 7 ) >= '0') && (val.charAt( 7 ) <= '9')) )
		{
			/*
			 *	NOTE:
			 *		.Net uses substring( startcol, lengthOfSubstring )
			 *		Java uses substring( startcol, endcol ) and does not
			 *			include charAt( endcol );
			 */
			int hour = Integer.parseInt( val.substring( 0, 2 ) );
			int minute = Integer.parseInt( val.substring( 3, 5 ) );
			int second = Integer.parseInt( val.substring( 6, 8 ) );
			Calendar retval = new GregorianCalendar( CFLibDbUtil.getDbServerTimeZone() );
			retval.set( Calendar.YEAR, 2000 );
			retval.set( Calendar.MONTH, 0 );
			retval.set( Calendar.DAY_OF_MONTH, 1 );
			retval.set( Calendar.HOUR_OF_DAY, hour );
			retval.set( Calendar.MINUTE, minute );
			retval.set( Calendar.SECOND, second );
			Calendar local = new GregorianCalendar();
			local.setTimeInMillis( retval.getTimeInMillis() );
			return( local );
		}
		else {
			throw new CFLibUsageException( CFSecDb2LUWSchema.class,
				"convertTimeString",
				"Value must be in HH24.MI.SS format \"" + val + "\" is invalid" );
		}
	}
	public static Calendar convertTimestampString(String val) {
		if( ( val == null ) || ( val.length() == 0 ) ) {
			return( null );
		}
		else if ( val.length() != 19 ) {
			throw new CFLibUsageException( CFSecDb2LUWSchema.class,
				"convertTimestampString",
				"Value must be in YYYY-MM-DD-HH24.MI.SS format \"" + val + "\" is invalid" );
		}
		else if (((val.charAt( 0 ) >= '0') && (val.charAt( 0 ) <= '9'))
			 && ((val.charAt( 1 ) >= '0') && (val.charAt( 1 ) <= '9'))
			 && ((val.charAt( 2 ) >= '0') && (val.charAt( 2 ) <= '9'))
			 && ((val.charAt( 3 ) >= '0') && (val.charAt( 3 ) <= '9'))
			 && (val.charAt( 4 ) == '-')
			 && ((val.charAt( 5 ) >= '0') && (val.charAt( 5 ) <= '1'))
			 && ((val.charAt( 6 ) >= '0') && (val.charAt( 6 ) <= '9'))
			 && (val.charAt( 7 ) == '-' )
			 && ((val.charAt( 8 ) >= '0') && (val.charAt( 8 ) <= '3'))
			 && ((val.charAt( 9 ) >= '0') && (val.charAt( 9 ) <= '9'))
			 && (val.charAt( 10 ) == '-' )
			 && ((val.charAt( 11 ) >= '0') && (val.charAt( 11 ) <= '2'))
			 && ((val.charAt( 12 ) >= '0') && (val.charAt( 12 ) <= '9'))
			 && (val.charAt( 13 ) == '.' )
			 && ((val.charAt( 14 ) >= '0') && (val.charAt( 14 ) <= '5'))
			 && ((val.charAt( 15 ) >= '0') && (val.charAt( 15 ) <= '9'))
			 && (val.charAt( 16 ) == '.' )
			 && ((val.charAt( 17 ) >= '0') && (val.charAt( 17 ) <= '5'))
			 && ((val.charAt( 18 ) >= '0') && (val.charAt( 18 ) <= '9')) )
		{
			/*
			 *	NOTE:
			 *		.Net uses substring( startcol, lengthOfSubstring )
			 *		Java uses substring( startcol, endcol ) and does not
			 *			include charAt( endcol );
			 */
			int year = Integer.parseInt( val.substring( 0, 4 ) );
			int month = Integer.parseInt( val.substring( 5, 7 ) );
			int day = Integer.parseInt( val.substring( 8, 10 ) );
			int hour = Integer.parseInt( val.substring( 11, 13 ) );
			int minute = Integer.parseInt( val.substring( 14, 16 ) );
			int second = Integer.parseInt( val.substring( 17, 19 ) );
			Calendar retval = new GregorianCalendar( CFLibDbUtil.getDbServerTimeZone() );
			retval.set( Calendar.YEAR, year );
			retval.set( Calendar.MONTH, month - 1 );
			retval.set( Calendar.DAY_OF_MONTH, day );
			retval.set( Calendar.HOUR_OF_DAY, hour );
			retval.set( Calendar.MINUTE, minute );
			retval.set( Calendar.SECOND, second );
			Calendar local = new GregorianCalendar();
			local.setTimeInMillis( retval.getTimeInMillis() );
			return( local );
		}
		else {
			throw new CFLibUsageException( CFSecDb2LUWSchema.class,
				"convertTimestampString",
				"Value must be in YYYY-MM-DD-HH24.MI.SS format \"" + val + "\" is invalid" );
		}
	}

	public static Calendar convertTZDateString(String val) {
		if( ( val == null ) || ( val.length() == 0 ) ) {
			return( null );
		}
		else if ( val.length() != 19 ) {
			throw new CFLibUsageException( CFSecDb2LUWSchema.class,
				"convertTZDateString",
				"Value must be in YYYY-MM-DD-HH24.MI.SS format \"" + val + "\" is invalid" );
		}
		else if (((val.charAt( 0 ) >= '0') && (val.charAt( 0 ) <= '9'))
			 && ((val.charAt( 1 ) >= '0') && (val.charAt( 1 ) <= '9'))
			 && ((val.charAt( 2 ) >= '0') && (val.charAt( 2 ) <= '9'))
			 && ((val.charAt( 3 ) >= '0') && (val.charAt( 3 ) <= '9'))
			 && (val.charAt( 4 ) == '-')
			 && ((val.charAt( 5 ) >= '0') && (val.charAt( 5 ) <= '1'))
			 && ((val.charAt( 6 ) >= '0') && (val.charAt( 6 ) <= '9'))
			 && (val.charAt( 7 ) == '-' )
			 && ((val.charAt( 8 ) >= '0') && (val.charAt( 8 ) <= '3'))
			 && ((val.charAt( 9 ) >= '0') && (val.charAt( 9 ) <= '9'))
			 && (val.charAt( 10 ) == '-' )
			 && ((val.charAt( 11 ) >= '0') && (val.charAt( 11 ) <= '2'))
			 && ((val.charAt( 12 ) >= '0') && (val.charAt( 12 ) <= '9'))
			 && (val.charAt( 13 ) == '.' )
			 && ((val.charAt( 14 ) >= '0') && (val.charAt( 14 ) <= '5'))
			 && ((val.charAt( 15 ) >= '0') && (val.charAt( 15 ) <= '9'))
			 && (val.charAt( 16 ) == '.' )
			 && ((val.charAt( 17 ) >= '0') && (val.charAt( 17 ) <= '5'))
			 && ((val.charAt( 18 ) >= '0') && (val.charAt( 18 ) <= '9')) )
		{
			/*
			 *	NOTE:
			 *		.Net uses substring( startcol, lengthOfSubstring )
			 *		Java uses substring( startcol, endcol ) and does not
			 *			include charAt( endcol );
			 */
			int year = Integer.parseInt( val.substring( 0, 4 ) );
			int month = Integer.parseInt( val.substring( 5, 7 ) );
			int day = Integer.parseInt( val.substring( 8, 10 ) );
			int hour = Integer.parseInt( val.substring( 11, 13 ) );
			int minute = Integer.parseInt( val.substring( 14, 16 ) );
			int second = Integer.parseInt( val.substring( 17, 19 ) );
			Calendar retval = new GregorianCalendar( CFLibDbUtil.getDbServerTimeZone() );
			retval.set( Calendar.YEAR, year );
			retval.set( Calendar.MONTH, month - 1 );
			retval.set( Calendar.DAY_OF_MONTH, day );
			retval.set( Calendar.HOUR_OF_DAY, hour );
			retval.set( Calendar.MINUTE, minute );
			retval.set( Calendar.SECOND, second );
			Calendar utc = CFLibDbUtil.getUTCCalendar( retval );
			return( utc );
		}
		else {
			throw new CFLibUsageException( CFSecDb2LUWSchema.class,
				"convertTZDateString",
				"Value must be in YYYY-MM-DD-HH24.MI.SS format \"" + val + "\" is invalid" );
		}
	}

	public static Calendar convertTZTimeString(String val) {
		if( ( val == null ) || ( val.length() == 0 ) ) {
			return( null );
		}
		else if ( val.length() != 19 ) {
			throw new CFLibUsageException( CFSecDb2LUWSchema.class,
				"convertTZTimeString",
				"Value must be in YYYY-MM-DD HH24.MI.SS format \"" + val + "\" is invalid" );
		}
		else if (((val.charAt( 0 ) >= '0') && (val.charAt( 0 ) <= '9'))
			 && ((val.charAt( 1 ) >= '0') && (val.charAt( 1 ) <= '9'))
			 && ((val.charAt( 2 ) >= '0') && (val.charAt( 2 ) <= '9'))
			 && ((val.charAt( 3 ) >= '0') && (val.charAt( 3 ) <= '9'))
			 && (val.charAt( 4 ) == '-')
			 && ((val.charAt( 5 ) >= '0') && (val.charAt( 5 ) <= '1'))
			 && ((val.charAt( 6 ) >= '0') && (val.charAt( 6 ) <= '9'))
			 && (val.charAt( 7 ) == '-' )
			 && ((val.charAt( 8 ) >= '0') && (val.charAt( 8 ) <= '3'))
			 && ((val.charAt( 9 ) >= '0') && (val.charAt( 9 ) <= '9'))
			 && (val.charAt( 10 ) == '-' )
			 && ((val.charAt( 11 ) >= '0') && (val.charAt( 11 ) <= '2'))
			 && ((val.charAt( 12 ) >= '0') && (val.charAt( 12 ) <= '9'))
			 && (val.charAt( 13 ) == '.' )
			 && ((val.charAt( 14 ) >= '0') && (val.charAt( 14 ) <= '5'))
			 && ((val.charAt( 15 ) >= '0') && (val.charAt( 15 ) <= '9'))
			 && (val.charAt( 16 ) == '.' )
			 && ((val.charAt( 17 ) >= '0') && (val.charAt( 17 ) <= '5'))
			 && ((val.charAt( 18 ) >= '0') && (val.charAt( 18 ) <= '9')) )
		{
			/*
			 *	NOTE:
			 *		.Net uses substring( startcol, lengthOfSubstring )
			 *		Java uses substring( startcol, endcol ) and does not
			 *			include charAt( endcol );
			 */
			int year = Integer.parseInt( val.substring( 0, 4 ) );
			int month = Integer.parseInt( val.substring( 5, 7 ) );
			int day = Integer.parseInt( val.substring( 8, 10 ) );
			int hour = Integer.parseInt( val.substring( 11, 13 ) );
			int minute = Integer.parseInt( val.substring( 14, 16 ) );
			int second = Integer.parseInt( val.substring( 17, 19 ) );
			Calendar retval = new GregorianCalendar( CFLibDbUtil.getDbServerTimeZone() );
			retval.set( Calendar.YEAR, year );
			retval.set( Calendar.MONTH, month - 1 );
			retval.set( Calendar.DAY_OF_MONTH, day );
			retval.set( Calendar.HOUR_OF_DAY, hour );
			retval.set( Calendar.MINUTE, minute );
			retval.set( Calendar.SECOND, second );
			Calendar utc = CFLibDbUtil.getUTCCalendar( retval );
			return( utc );
		}
		else {
			throw new CFLibUsageException( CFSecDb2LUWSchema.class,
				"convertTZTimeString",
				"Value must be in YYYY-MM-DD-HH24.MI.SS format \"" + val + "\" is invalid" );
		}
	}

	public static Calendar convertTZTimestampString(String val) {
		if( ( val == null ) || ( val.length() == 0 ) ) {
			return( null );
		}
		else if ( val.length() != 19 ) {
			throw new CFLibUsageException( CFSecDb2LUWSchema.class,
				"convertTZTimestampString",
				"Value must be in YYYY-MM-DD-HH24.MI.SS format \"" + val + "\" is invalid" );
		}
		else if (((val.charAt( 0 ) >= '0') && (val.charAt( 0 ) <= '9'))
			 && ((val.charAt( 1 ) >= '0') && (val.charAt( 1 ) <= '9'))
			 && ((val.charAt( 2 ) >= '0') && (val.charAt( 2 ) <= '9'))
			 && ((val.charAt( 3 ) >= '0') && (val.charAt( 3 ) <= '9'))
			 && (val.charAt( 4 ) == '-')
			 && ((val.charAt( 5 ) >= '0') && (val.charAt( 5 ) <= '1'))
			 && ((val.charAt( 6 ) >= '0') && (val.charAt( 6 ) <= '9'))
			 && (val.charAt( 7 ) == '-' )
			 && ((val.charAt( 8 ) >= '0') && (val.charAt( 8 ) <= '3'))
			 && ((val.charAt( 9 ) >= '0') && (val.charAt( 9 ) <= '9'))
			 && (val.charAt( 10 ) == '-' )
			 && ((val.charAt( 11 ) >= '0') && (val.charAt( 11 ) <= '2'))
			 && ((val.charAt( 12 ) >= '0') && (val.charAt( 12 ) <= '9'))
			 && (val.charAt( 13 ) == '.' )
			 && ((val.charAt( 14 ) >= '0') && (val.charAt( 14 ) <= '5'))
			 && ((val.charAt( 15 ) >= '0') && (val.charAt( 15 ) <= '9'))
			 && (val.charAt( 16 ) == '.' )
			 && ((val.charAt( 17 ) >= '0') && (val.charAt( 17 ) <= '5'))
			 && ((val.charAt( 18 ) >= '0') && (val.charAt( 18 ) <= '9')) )
		{
			/*
			 *	NOTE:
			 *		.Net uses substring( startcol, lengthOfSubstring )
			 *		Java uses substring( startcol, endcol ) and does not
			 *			include charAt( endcol );
			 */
			int year = Integer.parseInt( val.substring( 0, 4 ) );
			int month = Integer.parseInt( val.substring( 5, 7 ) );
			int day = Integer.parseInt( val.substring( 8, 10 ) );
			int hour = Integer.parseInt( val.substring( 11, 13 ) );
			int minute = Integer.parseInt( val.substring( 14, 16 ) );
			int second = Integer.parseInt( val.substring( 17, 19 ) );
			Calendar retval = new GregorianCalendar( CFLibDbUtil.getDbServerTimeZone() );
			retval.set( Calendar.YEAR, year );
			retval.set( Calendar.MONTH, month - 1 );
			retval.set( Calendar.DAY_OF_MONTH, day );
			retval.set( Calendar.HOUR_OF_DAY, hour );
			retval.set( Calendar.MINUTE, minute );
			retval.set( Calendar.SECOND, second );
			Calendar utc = CFLibDbUtil.getUTCCalendar( retval );
			return( utc );
		}
		else {
			throw new CFLibUsageException( CFSecDb2LUWSchema.class,
				"convertTZTimestampString",
				"Value must be in YYYY-MM-DD-HH24.MI.SS format \"" + val + "\" is invalid" );
		}
	}

	public static UUID convertUuidString(String val) {
		if( ( val == null ) || ( val.length() == 0 ) ) {
			return( null );
		}
		else {
			return( UUID.fromString( val ) );
		}
	}
}
