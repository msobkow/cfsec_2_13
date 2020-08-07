
// Description: Java 11 DbIO interface for SecForm.

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
import java.net.*;
import java.rmi.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.msscf.msscf.cflib.CFLib.*;
import org.msscf.msscf.cfsec.CFSecObj.*;

/*
 *	CFSecSecFormTable database interface for SecForm
 */
public interface ICFSecSecFormTable
{

	/**
	 *	Create the instance in the database, and update the specified buffer
	 *	with the assigned primary key.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	Buff	The buffer to be created.
	 */
	void createSecForm( CFSecAuthorization Authorization,
		CFSecSecFormBuff Buff );


	/**
	 *	Update the instance in the database, and update the specified buffer
	 *	with any calculated changes imposed by the associated stored procedure.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	Buff	The buffer to be updated.
	 */
	void updateSecForm( CFSecAuthorization Authorization,
		CFSecSecFormBuff Buff );


	/**
	 *	Delete the instance from the database.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	Buff	The buffer to be deleted.
	 */
	void deleteSecForm( CFSecAuthorization Authorization,
		CFSecSecFormBuff Buff );
	/**
	 *	Delete the SecForm instance identified by the primary key attributes.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argClusterId	The SecForm key attribute of the instance generating the id.
	 *
	 *	@param	argSecFormId	The SecForm key attribute of the instance generating the id.
	 */
	void deleteSecFormByIdIdx( CFSecAuthorization Authorization,
		long argClusterId,
		int argSecFormId );

	/**
	 *	Delete the SecForm instance identified by the primary key.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argKey	The primary key identifying the instance to be deleted.
	 */
	void deleteSecFormByIdIdx( CFSecAuthorization Authorization,
		CFSecSecFormPKey argKey );
	/**
	 *	Delete the SecForm instances identified by the key ClusterIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argClusterId	The SecForm key attribute of the instance generating the id.
	 */
	void deleteSecFormByClusterIdx( CFSecAuthorization Authorization,
		long argClusterId );

	/**
	 *	Delete the SecForm instances identified by the key ClusterIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argKey	The key identifying the instances to be deleted.
	 */
	void deleteSecFormByClusterIdx( CFSecAuthorization Authorization,
		CFSecSecFormByClusterIdxKey argKey );
	/**
	 *	Delete the SecForm instances identified by the key SecAppIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argClusterId	The SecForm key attribute of the instance generating the id.
	 *
	 *	@param	argSecAppId	The SecForm key attribute of the instance generating the id.
	 */
	void deleteSecFormBySecAppIdx( CFSecAuthorization Authorization,
		long argClusterId,
		int argSecAppId );

	/**
	 *	Delete the SecForm instances identified by the key SecAppIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argKey	The key identifying the instances to be deleted.
	 */
	void deleteSecFormBySecAppIdx( CFSecAuthorization Authorization,
		CFSecSecFormBySecAppIdxKey argKey );
	/**
	 *	Delete the SecForm instances identified by the key UJEEServletIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argClusterId	The SecForm key attribute of the instance generating the id.
	 *
	 *	@param	argSecAppId	The SecForm key attribute of the instance generating the id.
	 *
	 *	@param	argJEEServletMapName	The SecForm key attribute of the instance generating the id.
	 */
	void deleteSecFormByUJEEServletIdx( CFSecAuthorization Authorization,
		long argClusterId,
		int argSecAppId,
		String argJEEServletMapName );

	/**
	 *	Delete the SecForm instances identified by the key UJEEServletIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argKey	The key identifying the instances to be deleted.
	 */
	void deleteSecFormByUJEEServletIdx( CFSecAuthorization Authorization,
		CFSecSecFormByUJEEServletIdxKey argKey );


	/**
	 *	Read the derived SecForm buffer instance by primary key.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	PKey	The primary key of the SecForm instance to be read.
	 *
	 *	@return The buffer instance for the specified primary key, or null if there is
	 *		no such existing key value.
	 */
	CFSecSecFormBuff readDerived( CFSecAuthorization Authorization,
		CFSecSecFormPKey PKey );

	/**
	 *	Lock the derived SecForm buffer instance by primary key.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	PKey	The primary key of the SecForm instance to be locked.
	 *
	 *	@return The buffer instance for the specified primary key, or null if there is
	 *		no such existing key value.
	 */
	CFSecSecFormBuff lockDerived( CFSecAuthorization Authorization,
		CFSecSecFormPKey PKey );

	/**
	 *	Read all SecForm instances.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@return An array of derived buffer instances, potentially with 0 elements in the set.
	 */
	CFSecSecFormBuff[] readAllDerived( CFSecAuthorization Authorization );

	/**
	 *	Read the derived SecForm buffer instance identified by the unique key IdIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argClusterId	The SecForm key attribute of the instance generating the id.
	 *
	 *	@param	argSecFormId	The SecForm key attribute of the instance generating the id.
	 *
	 *	@return The buffer instance for the specified key, or null if there is
	 *		no such existing key value.
	 */
	CFSecSecFormBuff readDerivedByIdIdx( CFSecAuthorization Authorization,
		long ClusterId,
		int SecFormId );

	/**
	 *	Read an array of the derived SecForm buffer instances identified by the duplicate key ClusterIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argClusterId	The SecForm key attribute of the instance generating the id.
	 *
	 *	@return An array of derived buffer instances for the specified key, potentially with 0 elements in the set.
	 */
	CFSecSecFormBuff[] readDerivedByClusterIdx( CFSecAuthorization Authorization,
		long ClusterId );

	/**
	 *	Read an array of the derived SecForm buffer instances identified by the duplicate key SecAppIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argClusterId	The SecForm key attribute of the instance generating the id.
	 *
	 *	@param	argSecAppId	The SecForm key attribute of the instance generating the id.
	 *
	 *	@return An array of derived buffer instances for the specified key, potentially with 0 elements in the set.
	 */
	CFSecSecFormBuff[] readDerivedBySecAppIdx( CFSecAuthorization Authorization,
		long ClusterId,
		int SecAppId );

	/**
	 *	Read the derived SecForm buffer instance identified by the unique key UJEEServletIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argClusterId	The SecForm key attribute of the instance generating the id.
	 *
	 *	@param	argSecAppId	The SecForm key attribute of the instance generating the id.
	 *
	 *	@param	argJEEServletMapName	The SecForm key attribute of the instance generating the id.
	 *
	 *	@return The buffer instance for the specified key, or null if there is
	 *		no such existing key value.
	 */
	CFSecSecFormBuff readDerivedByUJEEServletIdx( CFSecAuthorization Authorization,
		long ClusterId,
		int SecAppId,
		String JEEServletMapName );

	/**
	 *	Read the specific SecForm buffer instance identified by the primary key.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	PKey	The primary key of the SecForm instance to be locked.
	 *
	 *	@return The buffer instance for the specified primary key, or null if there is
	 *		no such existing key value.
	 *
	 *	@throws	CFLibNotSupportedException thrown by client-side implementations.
	 */
	CFSecSecFormBuff readBuff( CFSecAuthorization Authorization,
		CFSecSecFormPKey PKey );

	/**
	 *	Lock the specific SecForm buffer instance identified by the primary key.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	PKey	The primary key of the SecForm instance to be locked.
	 *
	 *	@return The buffer instance for the specified primary key, or null if there is
	 *		no such existing key value.
	 *
	 *	@throws	CFLibNotSupportedException thrown by client-side implementations.
	 */
	CFSecSecFormBuff lockBuff( CFSecAuthorization Authorization,
		CFSecSecFormPKey PKey );

	/**
	 *	Read all the specific SecForm buffer instances.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@return All the specific SecForm instances in the database accessible for the Authorization.
	 */
	CFSecSecFormBuff[] readAllBuff( CFSecAuthorization Authorization );

	/**
	 *	Read a page of all the specific SecForm buffer instances.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@return All the specific SecForm instances in the database accessible for the Authorization.
	 */
	CFSecSecFormBuff[] pageAllBuff( CFSecAuthorization Authorization,
		Long priorClusterId,
		Integer priorSecFormId );

	/**
	 *	Read the specific SecForm buffer instance identified by the unique key IdIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argClusterId	The SecForm key attribute of the instance generating the id.
	 *
	 *	@param	argSecFormId	The SecForm key attribute of the instance generating the id.
	 *
	 *	@return The buffer instance for the specified key, or null if there is
	 *		no such existing key value.
	 *
	 *	@throws	CFLibNotSupportedException thrown by client-side implementations.
	 */
	CFSecSecFormBuff readBuffByIdIdx( CFSecAuthorization Authorization,
		long ClusterId,
		int SecFormId );

	/**
	 *	Read an array of the specific SecForm buffer instances identified by the duplicate key ClusterIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argClusterId	The SecForm key attribute of the instance generating the id.
	 *
	 *	@return An array of derived buffer instances for the specified key, potentially with 0 elements in the set.
	 *
	 *	@throws	CFLibNotSupportedException thrown by client-side implementations.
	 */
	CFSecSecFormBuff[] readBuffByClusterIdx( CFSecAuthorization Authorization,
		long ClusterId );

	/**
	 *	Read an array of the specific SecForm buffer instances identified by the duplicate key SecAppIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argClusterId	The SecForm key attribute of the instance generating the id.
	 *
	 *	@param	argSecAppId	The SecForm key attribute of the instance generating the id.
	 *
	 *	@return An array of derived buffer instances for the specified key, potentially with 0 elements in the set.
	 *
	 *	@throws	CFLibNotSupportedException thrown by client-side implementations.
	 */
	CFSecSecFormBuff[] readBuffBySecAppIdx( CFSecAuthorization Authorization,
		long ClusterId,
		int SecAppId );

	/**
	 *	Read the specific SecForm buffer instance identified by the unique key UJEEServletIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argClusterId	The SecForm key attribute of the instance generating the id.
	 *
	 *	@param	argSecAppId	The SecForm key attribute of the instance generating the id.
	 *
	 *	@param	argJEEServletMapName	The SecForm key attribute of the instance generating the id.
	 *
	 *	@return The buffer instance for the specified key, or null if there is
	 *		no such existing key value.
	 *
	 *	@throws	CFLibNotSupportedException thrown by client-side implementations.
	 */
	CFSecSecFormBuff readBuffByUJEEServletIdx( CFSecAuthorization Authorization,
		long ClusterId,
		int SecAppId,
		String JEEServletMapName );

	/**
	 *	Read a page array of the specific SecForm buffer instances identified by the duplicate key ClusterIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argClusterId	The SecForm key attribute of the instance generating the id.
	 *
	 *	@return An array of derived buffer instances for the specified key, potentially with 0 elements in the set.
	 *
	 *	@throws	CFLibNotSupportedException thrown by client-side implementations.
	 */
	CFSecSecFormBuff[] pageBuffByClusterIdx( CFSecAuthorization Authorization,
		long ClusterId,
		Long priorClusterId,
		Integer priorSecFormId );

	/**
	 *	Read a page array of the specific SecForm buffer instances identified by the duplicate key SecAppIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argClusterId	The SecForm key attribute of the instance generating the id.
	 *
	 *	@param	argSecAppId	The SecForm key attribute of the instance generating the id.
	 *
	 *	@return An array of derived buffer instances for the specified key, potentially with 0 elements in the set.
	 *
	 *	@throws	CFLibNotSupportedException thrown by client-side implementations.
	 */
	CFSecSecFormBuff[] pageBuffBySecAppIdx( CFSecAuthorization Authorization,
		long ClusterId,
		int SecAppId,
		Long priorClusterId,
		Integer priorSecFormId );

	/**
	 *	Release any prepared statements allocated by this instance.
	 *
	 *	@throws CFLibNotSupportedException thrown by client-side implementations.
	 */
	void releasePreparedStatements();
}
