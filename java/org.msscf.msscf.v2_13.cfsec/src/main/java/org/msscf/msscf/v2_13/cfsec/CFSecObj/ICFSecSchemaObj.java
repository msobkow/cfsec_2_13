// Description: Java 11 Schema Object interface for CFSec.

/*
 *	org.msscf.msscf.CFSec
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFSec 2.13 Security Essentials
 *	
 *	Copyright 2020-2021 Mark Stephen Sobkow mark.sobkow@gmail.com
 *	
 *	Licensed under the Apache License, Version 2.0 (the "License");
 *	you may not use this file except in compliance with the License.
 *	You may obtain a copy of the License at
 *	
 *	http://www.apache.org/licenses/LICENSE-2.0
 *	
 *	Unless required by applicable law or agreed to in writing, software
 *	distributed under the License is distributed on an "AS IS" BASIS,
 *	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *	See the License for the specific language governing permissions and
 *	limitations under the License.
 *
 *	Manufactured by MSS Code Factory 2.12
 */

package org.msscf.msscf.v2_13.cfsec.CFSecObj;

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.msscf.msscf.v2_13.cflib.CFLib.*;
import org.msscf.msscf.v2_13.cfsec.CFSec.*;

public interface ICFSecSchemaObj
{
	CFSecAuthorization getAuthorization();
	void setAuthorization( CFSecAuthorization value );

	ICFSecSchema getBackingStore();
	void setBackingStore( ICFSecSchema value );

	String getSchemaName();

	void setSecClusterName( String value );
	ICFSecClusterObj getSecCluster();
	void setSecCluster( ICFSecClusterObj value );

	void setSecTenantName( String value );
	ICFSecTenantObj getSecTenant();
	void setSecTenant( ICFSecTenantObj value );

	void setSecUserName( String value );
	ICFSecSecUserObj getSecUser();
	void setSecUser( ICFSecSecUserObj value );

	void setSecSessionId( UUID value );
	ICFSecSecSessionObj getSecSession();
	void setSecSession( ICFSecSecSessionObj value );

	boolean isConnected();
	boolean connect();
	boolean connect( String username, String password );
	boolean connect( String clusterName, String tenantName, String secUserName, String password );
	void disconnect( boolean doCommit );
	void logout();

	void minimizeMemory();

	String fileImport( String fileName, String fileContent );

	/**
	 *	When you first connect to a database, you can opt to specify a database
	 *	name to be used by the session.
	 */
	String getDbSchemaName();

	/**
	 *	PostgreSQL coerces database schema names to lowercase for consistency.
	 */
	String getLowerDbSchemaName();

	/**
	 *	When you set the database name, the database-specific implementation
	 *	of this method does a "commit; use database"-type sequence to change
	 *	to the target database.  This should be specified globally for all
	 *	database connections in a given cluster, so that all of
	 *	the application implementation clients are using the same database instance
	 *	regardless of what's been provided by the cust client implementation,
	 *	be it as a Java application or a web interface written using JEE.
	 */
	void setDbSchemaName( String argDbSchemaName );

	/**
	 *	If a transaction is already opened for the schema connection,
	 *	return false.  If a new transaction is successfully opened,
	 *	return true.  Otherwise throw a RuntimeException detailing
	 *	why a transaction could not be initiated.
	 *
	 *	This permits the database persistence implementations to
	 *	switch between participating in an existing transaction
	 *	or implementing an implicit atomic transaction that is
	 *	committed or rolled back before the method returns:
	 *
	 *		boolean txnInitiated = false;
	 *		try {
	 *			txnInitiated = schema.beginTransaction();
	 *			... business logic and presentation code ...
	 *			if( txnInitiated ) {
	 *				schema.commit();
	 *			}
	 *		}
	 *		catch( RuntimeException e ) {
	 *			if( txnInitiated ) {
	 *				try {
	 *					schema.rollback();
	 *				}
	 *				catch( RuntimeException e ) {
	 *				}
	 *			}
	 *			... report exception or throw exception with cause ...
	 *		}
	 *
	 *	As the current web-form focused implementation will be managing
	 *	the transactions in the Servlet page response, I don't need to
	 *	implement the atomic transaction wrappers yet.
	 */
	boolean isTransactionOpen();
	boolean beginTransaction();
	void commit();
	void rollback();

	/**
	 *	Release any prepared statements acquired by this connection.
	 *	<p>
	 *	Resets the prepared statements so they can acquire the new value of
	 *	<tt>setDbSchemaName()</tt>.
	 */
	void releasePreparedStatements();
	/**
	 *	Get the Cluster interface for the schema.
	 *
	 *	@return	The ICFSecClusterTableObj interface implementation for the schema.
	 */
	ICFSecClusterTableObj getClusterTableObj();

	/**
	 *	Get the HostNode interface for the schema.
	 *
	 *	@return	The ICFSecHostNodeTableObj interface implementation for the schema.
	 */
	ICFSecHostNodeTableObj getHostNodeTableObj();

	/**
	 *	Get the ISOCcy interface for the schema.
	 *
	 *	@return	The ICFSecISOCcyTableObj interface implementation for the schema.
	 */
	ICFSecISOCcyTableObj getISOCcyTableObj();

	/**
	 *	Get the ISOCtry interface for the schema.
	 *
	 *	@return	The ICFSecISOCtryTableObj interface implementation for the schema.
	 */
	ICFSecISOCtryTableObj getISOCtryTableObj();

	/**
	 *	Get the ISOCtryCcy interface for the schema.
	 *
	 *	@return	The ICFSecISOCtryCcyTableObj interface implementation for the schema.
	 */
	ICFSecISOCtryCcyTableObj getISOCtryCcyTableObj();

	/**
	 *	Get the ISOCtryLang interface for the schema.
	 *
	 *	@return	The ICFSecISOCtryLangTableObj interface implementation for the schema.
	 */
	ICFSecISOCtryLangTableObj getISOCtryLangTableObj();

	/**
	 *	Get the ISOLang interface for the schema.
	 *
	 *	@return	The ICFSecISOLangTableObj interface implementation for the schema.
	 */
	ICFSecISOLangTableObj getISOLangTableObj();

	/**
	 *	Get the ISOTZone interface for the schema.
	 *
	 *	@return	The ICFSecISOTZoneTableObj interface implementation for the schema.
	 */
	ICFSecISOTZoneTableObj getISOTZoneTableObj();

	/**
	 *	Get the SecApp interface for the schema.
	 *
	 *	@return	The ICFSecSecAppTableObj interface implementation for the schema.
	 */
	ICFSecSecAppTableObj getSecAppTableObj();

	/**
	 *	Get the SecDevice interface for the schema.
	 *
	 *	@return	The ICFSecSecDeviceTableObj interface implementation for the schema.
	 */
	ICFSecSecDeviceTableObj getSecDeviceTableObj();

	/**
	 *	Get the SecForm interface for the schema.
	 *
	 *	@return	The ICFSecSecFormTableObj interface implementation for the schema.
	 */
	ICFSecSecFormTableObj getSecFormTableObj();

	/**
	 *	Get the SecGroup interface for the schema.
	 *
	 *	@return	The ICFSecSecGroupTableObj interface implementation for the schema.
	 */
	ICFSecSecGroupTableObj getSecGroupTableObj();

	/**
	 *	Get the SecGroupForm interface for the schema.
	 *
	 *	@return	The ICFSecSecGroupFormTableObj interface implementation for the schema.
	 */
	ICFSecSecGroupFormTableObj getSecGroupFormTableObj();

	/**
	 *	Get the SecGrpInc interface for the schema.
	 *
	 *	@return	The ICFSecSecGrpIncTableObj interface implementation for the schema.
	 */
	ICFSecSecGrpIncTableObj getSecGrpIncTableObj();

	/**
	 *	Get the SecGrpMemb interface for the schema.
	 *
	 *	@return	The ICFSecSecGrpMembTableObj interface implementation for the schema.
	 */
	ICFSecSecGrpMembTableObj getSecGrpMembTableObj();

	/**
	 *	Get the SecSession interface for the schema.
	 *
	 *	@return	The ICFSecSecSessionTableObj interface implementation for the schema.
	 */
	ICFSecSecSessionTableObj getSecSessionTableObj();

	/**
	 *	Get the SecUser interface for the schema.
	 *
	 *	@return	The ICFSecSecUserTableObj interface implementation for the schema.
	 */
	ICFSecSecUserTableObj getSecUserTableObj();

	/**
	 *	Get the Service interface for the schema.
	 *
	 *	@return	The ICFSecServiceTableObj interface implementation for the schema.
	 */
	ICFSecServiceTableObj getServiceTableObj();

	/**
	 *	Get the ServiceType interface for the schema.
	 *
	 *	@return	The ICFSecServiceTypeTableObj interface implementation for the schema.
	 */
	ICFSecServiceTypeTableObj getServiceTypeTableObj();

	/**
	 *	Get the SysCluster interface for the schema.
	 *
	 *	@return	The ICFSecSysClusterTableObj interface implementation for the schema.
	 */
	ICFSecSysClusterTableObj getSysClusterTableObj();

	/**
	 *	Get the TSecGroup interface for the schema.
	 *
	 *	@return	The ICFSecTSecGroupTableObj interface implementation for the schema.
	 */
	ICFSecTSecGroupTableObj getTSecGroupTableObj();

	/**
	 *	Get the TSecGrpInc interface for the schema.
	 *
	 *	@return	The ICFSecTSecGrpIncTableObj interface implementation for the schema.
	 */
	ICFSecTSecGrpIncTableObj getTSecGrpIncTableObj();

	/**
	 *	Get the TSecGrpMemb interface for the schema.
	 *
	 *	@return	The ICFSecTSecGrpMembTableObj interface implementation for the schema.
	 */
	ICFSecTSecGrpMembTableObj getTSecGrpMembTableObj();

	/**
	 *	Get the Tenant interface for the schema.
	 *
	 *	@return	The ICFSecTenantTableObj interface implementation for the schema.
	 */
	ICFSecTenantTableObj getTenantTableObj();
}
