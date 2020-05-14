// Description: Java 11 Table Object interface for CFSec.

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

package com.github.msobkow.cfsec.CFSecObj;

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import com.github.msobkow.cflib.CFLib.*;
import com.github.msobkow.cfsec.CFSec.*;

public interface ICFSecTenantTableObj
{
	ICFSecSchemaObj getSchema();
	void setSchema( ICFSecSchemaObj value );

	void minimizeMemory();

	String getTableName();
	String getTableDbName();

	Class getObjQualifyingClass();

	/**
	 *	Instantiate a new Tenant instance.
	 *
	 *	@return	A new instance.
	 */
	ICFSecTenantObj newInstance();

	/**
	 *	Instantiate a new Tenant edition of the specified Tenant instance.
	 *
	 *	@return	A new edition.
	 */
	ICFSecTenantEditObj newEditInstance( ICFSecTenantObj orig );

	/**
	 *	Internal use only.
	 */
	ICFSecTenantObj realiseTenant( ICFSecTenantObj Obj );

	/**
	 *	Internal use only.
	 */
	ICFSecTenantObj createTenant( ICFSecTenantObj Obj );

	/**
	 *	Read a Tenant-derived instance by it's primary key.
	 *
	 *	@param	pkey	The primary key identifying the instance to read.
	 *
	 *	@return	The Tenant-derived instance identified by the primary key,
	 *		or null if no such key value exists.
	 */
	ICFSecTenantObj readTenant( CFSecTenantPKey pkey );

	/**
	 *	Read a Tenant-derived instance by it's primary key.
	 *
	 *	@param	pkey	The primary key identifying the instance to read.
	 *
	 *	@return	The Tenant-derived instance identified by the primary key,
	 *		or null if no such key value exists.
	 */
	ICFSecTenantObj readTenant( CFSecTenantPKey pkey,
		boolean forceRead );

	ICFSecTenantObj readCachedTenant( CFSecTenantPKey pkey );

	public void reallyDeepDisposeTenant( ICFSecTenantObj obj );

	void deepDisposeTenant( CFSecTenantPKey pkey );

	/**
	 *	Internal use only.
	 */
	ICFSecTenantObj lockTenant( CFSecTenantPKey pkey );

	/**
	 *	Return a sorted list of all the Tenant-derived instances in the database.
	 *
	 *	@return	List of ICFSecTenantObj instance, sorted by their primary keys, which
	 *		may include an empty set.
	 */
	List<ICFSecTenantObj> readAllTenant();

	/**
	 *	Return a sorted map of all the Tenant-derived instances in the database.
	 *
	 *	@return	List of ICFSecTenantObj instance, sorted by their primary keys, which
	 *		may include an empty set.
	 */
	List<ICFSecTenantObj> readAllTenant( boolean forceRead );

	List<ICFSecTenantObj> readCachedAllTenant();

	/**
	 *	Return a sorted map of a page of the Tenant-derived instances in the database.
	 *
	 *	@return	List of ICFSecTenantObj instance, sorted by their primary keys, which
	 *		may include an empty set.
	 */
	List<ICFSecTenantObj> pageAllTenant(Long priorId );

	/**
	 *	Get the CFSecTenantObj instance for the primary key attributes.
	 *
	 *	@param	argId	The Tenant key attribute of the instance generating the id.
	 *
	 *	@return	CFSecTenantObj cached instance for the primary key, or
	 *		null if no such instance exists.
	 */
	ICFSecTenantObj readTenantByIdIdx( long Id );

	/**
	 *	Get the CFSecTenantObj instance for the primary key attributes.
	 *
	 *	@param	argId	The Tenant key attribute of the instance generating the id.
	 *
	 *	@return	CFSecTenantObj refreshed instance for the primary key, or
	 *		null if no such instance exists.
	 */
	ICFSecTenantObj readTenantByIdIdx( long Id,
		boolean forceRead );

	/**
	 *	Get the map of CFSecTenantObj instances sorted by their primary keys for the duplicate ClusterIdx key.
	 *
	 *	@param	argClusterId	The Tenant key attribute of the instance generating the id.
	 *
	 *	@return	List of CFSecTenantObj cached instances sorted by their primary keys for the duplicate ClusterIdx key,
	 *		which may be an empty set.
	 */
	List<ICFSecTenantObj> readTenantByClusterIdx( long ClusterId );

	/**
	 *	Get the map of CFSecTenantObj instances sorted by their primary keys for the duplicate ClusterIdx key.
	 *
	 *	@param	argClusterId	The Tenant key attribute of the instance generating the id.
	 *
	 *	@return	List of CFSecTenantObj cached instances sorted by their primary keys for the duplicate ClusterIdx key,
	 *		which may be an empty set.
	 */
	List<ICFSecTenantObj> readTenantByClusterIdx( long ClusterId,
		boolean forceRead );

	/**
	 *	Get the CFSecTenantObj instance for the unique UNameIdx key.
	 *
	 *	@param	argClusterId	The Tenant key attribute of the instance generating the id.
	 *
	 *	@param	argTenantName	The Tenant key attribute of the instance generating the id.
	 *
	 *	@return	CFSecTenantObj cached instance for the unique UNameIdx key, or
	 *		null if no such instance exists.
	 */
	ICFSecTenantObj readTenantByUNameIdx(long ClusterId,
		String TenantName );

	/**
	 *	Get the CFSecTenantObj instance for the unique UNameIdx key.
	 *
	 *	@param	argClusterId	The Tenant key attribute of the instance generating the id.
	 *
	 *	@param	argTenantName	The Tenant key attribute of the instance generating the id.
	 *
	 *	@return	CFSecTenantObj refreshed instance for the unique UNameIdx key, or
	 *		null if no such instance exists.
	 */
	ICFSecTenantObj readTenantByUNameIdx(long ClusterId,
		String TenantName,
		boolean forceRead );

	ICFSecTenantObj readCachedTenantByIdIdx( long Id );

	List<ICFSecTenantObj> readCachedTenantByClusterIdx( long ClusterId );

	ICFSecTenantObj readCachedTenantByUNameIdx( long ClusterId,
		String TenantName );

	void deepDisposeTenantByIdIdx( long Id );

	void deepDisposeTenantByClusterIdx( long ClusterId );

	void deepDisposeTenantByUNameIdx( long ClusterId,
		String TenantName );

	/**
	 *	Read a page of data as a List of Tenant-derived instances sorted by their primary keys,
	 *	as identified by the duplicate ClusterIdx key attributes.
	 *
	 *	@param	argClusterId	The Tenant key attribute of the instance generating the id.
	 *
	 *	@return	A List of Tenant-derived instances sorted by their primary keys,
	 *		as identified by the key attributes, which may be an empty set.
	 */
	List<ICFSecTenantObj> pageTenantByClusterIdx( long ClusterId,
		Long priorId );

	/**
	 *	Internal use only.
	 */
	ICFSecTenantObj updateTenant( ICFSecTenantObj Obj );

	/**
	 *	Internal use only.
	 */
	void deleteTenant( ICFSecTenantObj Obj );

	/**
	 *	Internal use only.
	 *
	 *	@param	argId	The Tenant key attribute of the instance generating the id.
	 */
	void deleteTenantByIdIdx( long Id );

	/**
	 *	Internal use only.
	 *
	 *	@param	argClusterId	The Tenant key attribute of the instance generating the id.
	 */
	void deleteTenantByClusterIdx( long ClusterId );

	/**
	 *	Internal use only.
	 *
	 *	@param	argClusterId	The Tenant key attribute of the instance generating the id.
	 *
	 *	@param	argTenantName	The Tenant key attribute of the instance generating the id.
	 */
	void deleteTenantByUNameIdx(long ClusterId,
		String TenantName );

	ICFSecTenantObj getSystemTenant();
}
