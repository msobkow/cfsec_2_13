
// Description: Java 11 DbIO interface for ServiceType.

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
 *	CFSecServiceTypeTable database interface for ServiceType
 */
public interface ICFSecServiceTypeTable
{

	/**
	 *	Create the instance in the database, and update the specified buffer
	 *	with the assigned primary key.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	Buff	The buffer to be created.
	 */
	void createServiceType( CFSecAuthorization Authorization,
		CFSecServiceTypeBuff Buff );


	/**
	 *	Update the instance in the database, and update the specified buffer
	 *	with any calculated changes imposed by the associated stored procedure.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	Buff	The buffer to be updated.
	 */
	void updateServiceType( CFSecAuthorization Authorization,
		CFSecServiceTypeBuff Buff );


	/**
	 *	Delete the instance from the database.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	Buff	The buffer to be deleted.
	 */
	void deleteServiceType( CFSecAuthorization Authorization,
		CFSecServiceTypeBuff Buff );
	/**
	 *	Delete the ServiceType instance identified by the primary key attributes.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argServiceTypeId	The ServiceType key attribute of the instance generating the id.
	 */
	void deleteServiceTypeByIdIdx( CFSecAuthorization Authorization,
		int argServiceTypeId );

	/**
	 *	Delete the ServiceType instance identified by the primary key.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argKey	The primary key identifying the instance to be deleted.
	 */
	void deleteServiceTypeByIdIdx( CFSecAuthorization Authorization,
		CFSecServiceTypePKey argKey );
	/**
	 *	Delete the ServiceType instances identified by the key UDescrIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argDescription	The ServiceType key attribute of the instance generating the id.
	 */
	void deleteServiceTypeByUDescrIdx( CFSecAuthorization Authorization,
		String argDescription );

	/**
	 *	Delete the ServiceType instances identified by the key UDescrIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argKey	The key identifying the instances to be deleted.
	 */
	void deleteServiceTypeByUDescrIdx( CFSecAuthorization Authorization,
		CFSecServiceTypeByUDescrIdxKey argKey );


	/**
	 *	Read the derived ServiceType buffer instance by primary key.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	PKey	The primary key of the ServiceType instance to be read.
	 *
	 *	@return The buffer instance for the specified primary key, or null if there is
	 *		no such existing key value.
	 */
	CFSecServiceTypeBuff readDerived( CFSecAuthorization Authorization,
		CFSecServiceTypePKey PKey );

	/**
	 *	Lock the derived ServiceType buffer instance by primary key.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	PKey	The primary key of the ServiceType instance to be locked.
	 *
	 *	@return The buffer instance for the specified primary key, or null if there is
	 *		no such existing key value.
	 */
	CFSecServiceTypeBuff lockDerived( CFSecAuthorization Authorization,
		CFSecServiceTypePKey PKey );

	/**
	 *	Read all ServiceType instances.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@return An array of derived buffer instances, potentially with 0 elements in the set.
	 */
	CFSecServiceTypeBuff[] readAllDerived( CFSecAuthorization Authorization );

	/**
	 *	Read the derived ServiceType buffer instance identified by the unique key IdIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argServiceTypeId	The ServiceType key attribute of the instance generating the id.
	 *
	 *	@return The buffer instance for the specified key, or null if there is
	 *		no such existing key value.
	 */
	CFSecServiceTypeBuff readDerivedByIdIdx( CFSecAuthorization Authorization,
		int ServiceTypeId );

	/**
	 *	Read the derived ServiceType buffer instance identified by the unique key UDescrIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argDescription	The ServiceType key attribute of the instance generating the id.
	 *
	 *	@return The buffer instance for the specified key, or null if there is
	 *		no such existing key value.
	 */
	CFSecServiceTypeBuff readDerivedByUDescrIdx( CFSecAuthorization Authorization,
		String Description );

	/**
	 *	Read the specific ServiceType buffer instance identified by the primary key.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	PKey	The primary key of the ServiceType instance to be locked.
	 *
	 *	@return The buffer instance for the specified primary key, or null if there is
	 *		no such existing key value.
	 *
	 *	@throws	CFLibNotSupportedException thrown by client-side implementations.
	 */
	CFSecServiceTypeBuff readBuff( CFSecAuthorization Authorization,
		CFSecServiceTypePKey PKey );

	/**
	 *	Lock the specific ServiceType buffer instance identified by the primary key.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	PKey	The primary key of the ServiceType instance to be locked.
	 *
	 *	@return The buffer instance for the specified primary key, or null if there is
	 *		no such existing key value.
	 *
	 *	@throws	CFLibNotSupportedException thrown by client-side implementations.
	 */
	CFSecServiceTypeBuff lockBuff( CFSecAuthorization Authorization,
		CFSecServiceTypePKey PKey );

	/**
	 *	Read all the specific ServiceType buffer instances.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@return All the specific ServiceType instances in the database accessible for the Authorization.
	 */
	CFSecServiceTypeBuff[] readAllBuff( CFSecAuthorization Authorization );

	/**
	 *	Read the specific ServiceType buffer instance identified by the unique key IdIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argServiceTypeId	The ServiceType key attribute of the instance generating the id.
	 *
	 *	@return The buffer instance for the specified key, or null if there is
	 *		no such existing key value.
	 *
	 *	@throws	CFLibNotSupportedException thrown by client-side implementations.
	 */
	CFSecServiceTypeBuff readBuffByIdIdx( CFSecAuthorization Authorization,
		int ServiceTypeId );

	/**
	 *	Read the specific ServiceType buffer instance identified by the unique key UDescrIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argDescription	The ServiceType key attribute of the instance generating the id.
	 *
	 *	@return The buffer instance for the specified key, or null if there is
	 *		no such existing key value.
	 *
	 *	@throws	CFLibNotSupportedException thrown by client-side implementations.
	 */
	CFSecServiceTypeBuff readBuffByUDescrIdx( CFSecAuthorization Authorization,
		String Description );

	/**
	 *	Release any prepared statements allocated by this instance.
	 *
	 *	@throws CFLibNotSupportedException thrown by client-side implementations.
	 */
	void releasePreparedStatements();
}
