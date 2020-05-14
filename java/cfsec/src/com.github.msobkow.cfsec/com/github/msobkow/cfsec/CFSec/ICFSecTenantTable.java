
// Description: Java 11 DbIO interface for Tenant.

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
import java.net.*;
import java.rmi.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import com.github.msobkow.cflib.CFLib.*;
import com.github.msobkow.cfsec.CFSecObj.*;

/*
 *	CFSecTenantTable database interface for Tenant
 */
public interface ICFSecTenantTable
{
	/**
	 *	Get the next TSecGroupIdGen id generator value.
	 *
	 *	@param	PKey	The primary key of the Tenant instance generating the id.
	 *
	 *	@throws CFLibNotSupportedException thrown by client-side implementations.
	 *
	 *	@return The next id value as generated by the cluster database.
	 */
	int nextTSecGroupIdGen( CFSecAuthorization Authorization,
		CFSecTenantPKey PKey );

	/**
	 *	Get the next TSecGroupIdGen id generator value.
	 *
	 *	@param	argId	The Tenant key attribute of the instance generating the id.
	 *
	 *	@throws CFLibNotSupportedException thrown by client-side implementations.
	 *
	 *	@return The next id value as generated by the cluster database.
	 */
	int nextTSecGroupIdGen( CFSecAuthorization Authorization,
		long argId );

	/**
	 *	Get the next TSecGrpIncIdGen id generator value.
	 *
	 *	@param	PKey	The primary key of the Tenant instance generating the id.
	 *
	 *	@throws CFLibNotSupportedException thrown by client-side implementations.
	 *
	 *	@return The next id value as generated by the cluster database.
	 */
	long nextTSecGrpIncIdGen( CFSecAuthorization Authorization,
		CFSecTenantPKey PKey );

	/**
	 *	Get the next TSecGrpIncIdGen id generator value.
	 *
	 *	@param	argId	The Tenant key attribute of the instance generating the id.
	 *
	 *	@throws CFLibNotSupportedException thrown by client-side implementations.
	 *
	 *	@return The next id value as generated by the cluster database.
	 */
	long nextTSecGrpIncIdGen( CFSecAuthorization Authorization,
		long argId );

	/**
	 *	Get the next TSecGrpMembIdGen id generator value.
	 *
	 *	@param	PKey	The primary key of the Tenant instance generating the id.
	 *
	 *	@throws CFLibNotSupportedException thrown by client-side implementations.
	 *
	 *	@return The next id value as generated by the cluster database.
	 */
	long nextTSecGrpMembIdGen( CFSecAuthorization Authorization,
		CFSecTenantPKey PKey );

	/**
	 *	Get the next TSecGrpMembIdGen id generator value.
	 *
	 *	@param	argId	The Tenant key attribute of the instance generating the id.
	 *
	 *	@throws CFLibNotSupportedException thrown by client-side implementations.
	 *
	 *	@return The next id value as generated by the cluster database.
	 */
	long nextTSecGrpMembIdGen( CFSecAuthorization Authorization,
		long argId );


	/**
	 *	Create the instance in the database, and update the specified buffer
	 *	with the assigned primary key.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	Buff	The buffer to be created.
	 */
	void createTenant( CFSecAuthorization Authorization,
		CFSecTenantBuff Buff );


	/**
	 *	Update the instance in the database, and update the specified buffer
	 *	with any calculated changes imposed by the associated stored procedure.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	Buff	The buffer to be updated.
	 */
	void updateTenant( CFSecAuthorization Authorization,
		CFSecTenantBuff Buff );


	/**
	 *	Delete the instance from the database.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	Buff	The buffer to be deleted.
	 */
	void deleteTenant( CFSecAuthorization Authorization,
		CFSecTenantBuff Buff );
	/**
	 *	Delete the Tenant instance identified by the primary key attributes.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argId	The Tenant key attribute of the instance generating the id.
	 */
	void deleteTenantByIdIdx( CFSecAuthorization Authorization,
		long argId );

	/**
	 *	Delete the Tenant instance identified by the primary key.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argKey	The primary key identifying the instance to be deleted.
	 */
	void deleteTenantByIdIdx( CFSecAuthorization Authorization,
		CFSecTenantPKey argKey );
	/**
	 *	Delete the Tenant instances identified by the key ClusterIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argClusterId	The Tenant key attribute of the instance generating the id.
	 */
	void deleteTenantByClusterIdx( CFSecAuthorization Authorization,
		long argClusterId );

	/**
	 *	Delete the Tenant instances identified by the key ClusterIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argKey	The key identifying the instances to be deleted.
	 */
	void deleteTenantByClusterIdx( CFSecAuthorization Authorization,
		CFSecTenantByClusterIdxKey argKey );
	/**
	 *	Delete the Tenant instances identified by the key UNameIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argClusterId	The Tenant key attribute of the instance generating the id.
	 *
	 *	@param	argTenantName	The Tenant key attribute of the instance generating the id.
	 */
	void deleteTenantByUNameIdx( CFSecAuthorization Authorization,
		long argClusterId,
		String argTenantName );

	/**
	 *	Delete the Tenant instances identified by the key UNameIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argKey	The key identifying the instances to be deleted.
	 */
	void deleteTenantByUNameIdx( CFSecAuthorization Authorization,
		CFSecTenantByUNameIdxKey argKey );


	/**
	 *	Read the derived Tenant buffer instance by primary key.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	PKey	The primary key of the Tenant instance to be read.
	 *
	 *	@return The buffer instance for the specified primary key, or null if there is
	 *		no such existing key value.
	 */
	CFSecTenantBuff readDerived( CFSecAuthorization Authorization,
		CFSecTenantPKey PKey );

	/**
	 *	Lock the derived Tenant buffer instance by primary key.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	PKey	The primary key of the Tenant instance to be locked.
	 *
	 *	@return The buffer instance for the specified primary key, or null if there is
	 *		no such existing key value.
	 */
	CFSecTenantBuff lockDerived( CFSecAuthorization Authorization,
		CFSecTenantPKey PKey );

	/**
	 *	Read all Tenant instances.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@return An array of derived buffer instances, potentially with 0 elements in the set.
	 */
	CFSecTenantBuff[] readAllDerived( CFSecAuthorization Authorization );

	/**
	 *	Read the derived Tenant buffer instance identified by the unique key IdIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argId	The Tenant key attribute of the instance generating the id.
	 *
	 *	@return The buffer instance for the specified key, or null if there is
	 *		no such existing key value.
	 */
	CFSecTenantBuff readDerivedByIdIdx( CFSecAuthorization Authorization,
		long Id );

	/**
	 *	Read an array of the derived Tenant buffer instances identified by the duplicate key ClusterIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argClusterId	The Tenant key attribute of the instance generating the id.
	 *
	 *	@return An array of derived buffer instances for the specified key, potentially with 0 elements in the set.
	 */
	CFSecTenantBuff[] readDerivedByClusterIdx( CFSecAuthorization Authorization,
		long ClusterId );

	/**
	 *	Read the derived Tenant buffer instance identified by the unique key UNameIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argClusterId	The Tenant key attribute of the instance generating the id.
	 *
	 *	@param	argTenantName	The Tenant key attribute of the instance generating the id.
	 *
	 *	@return The buffer instance for the specified key, or null if there is
	 *		no such existing key value.
	 */
	CFSecTenantBuff readDerivedByUNameIdx( CFSecAuthorization Authorization,
		long ClusterId,
		String TenantName );

	/**
	 *	Read the specific Tenant buffer instance identified by the primary key.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	PKey	The primary key of the Tenant instance to be locked.
	 *
	 *	@return The buffer instance for the specified primary key, or null if there is
	 *		no such existing key value.
	 *
	 *	@throws	CFLibNotSupportedException thrown by client-side implementations.
	 */
	CFSecTenantBuff readBuff( CFSecAuthorization Authorization,
		CFSecTenantPKey PKey );

	/**
	 *	Lock the specific Tenant buffer instance identified by the primary key.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	PKey	The primary key of the Tenant instance to be locked.
	 *
	 *	@return The buffer instance for the specified primary key, or null if there is
	 *		no such existing key value.
	 *
	 *	@throws	CFLibNotSupportedException thrown by client-side implementations.
	 */
	CFSecTenantBuff lockBuff( CFSecAuthorization Authorization,
		CFSecTenantPKey PKey );

	/**
	 *	Read all the specific Tenant buffer instances.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@return All the specific Tenant instances in the database accessible for the Authorization.
	 */
	CFSecTenantBuff[] readAllBuff( CFSecAuthorization Authorization );

	/**
	 *	Read a page of all the specific Tenant buffer instances.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@return All the specific Tenant instances in the database accessible for the Authorization.
	 */
	CFSecTenantBuff[] pageAllBuff( CFSecAuthorization Authorization,
		Long priorId );

	/**
	 *	Read the specific Tenant buffer instance identified by the unique key IdIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argId	The Tenant key attribute of the instance generating the id.
	 *
	 *	@return The buffer instance for the specified key, or null if there is
	 *		no such existing key value.
	 *
	 *	@throws	CFLibNotSupportedException thrown by client-side implementations.
	 */
	CFSecTenantBuff readBuffByIdIdx( CFSecAuthorization Authorization,
		long Id );

	/**
	 *	Read an array of the specific Tenant buffer instances identified by the duplicate key ClusterIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argClusterId	The Tenant key attribute of the instance generating the id.
	 *
	 *	@return An array of derived buffer instances for the specified key, potentially with 0 elements in the set.
	 *
	 *	@throws	CFLibNotSupportedException thrown by client-side implementations.
	 */
	CFSecTenantBuff[] readBuffByClusterIdx( CFSecAuthorization Authorization,
		long ClusterId );

	/**
	 *	Read the specific Tenant buffer instance identified by the unique key UNameIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argClusterId	The Tenant key attribute of the instance generating the id.
	 *
	 *	@param	argTenantName	The Tenant key attribute of the instance generating the id.
	 *
	 *	@return The buffer instance for the specified key, or null if there is
	 *		no such existing key value.
	 *
	 *	@throws	CFLibNotSupportedException thrown by client-side implementations.
	 */
	CFSecTenantBuff readBuffByUNameIdx( CFSecAuthorization Authorization,
		long ClusterId,
		String TenantName );

	/**
	 *	Read a page array of the specific Tenant buffer instances identified by the duplicate key ClusterIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argClusterId	The Tenant key attribute of the instance generating the id.
	 *
	 *	@return An array of derived buffer instances for the specified key, potentially with 0 elements in the set.
	 *
	 *	@throws	CFLibNotSupportedException thrown by client-side implementations.
	 */
	CFSecTenantBuff[] pageBuffByClusterIdx( CFSecAuthorization Authorization,
		long ClusterId,
		Long priorId );

	/**
	 *	Release any prepared statements allocated by this instance.
	 *
	 *	@throws CFLibNotSupportedException thrown by client-side implementations.
	 */
	void releasePreparedStatements();
}