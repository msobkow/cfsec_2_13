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

public interface ICFSecSysClusterTableObj
{
	ICFSecSchemaObj getSchema();
	void setSchema( ICFSecSchemaObj value );

	void minimizeMemory();

	String getTableName();
	String getTableDbName();

	Class getObjQualifyingClass();

	/**
	 *	Instantiate a new SysCluster instance.
	 *
	 *	@return	A new instance.
	 */
	ICFSecSysClusterObj newInstance();

	/**
	 *	Instantiate a new SysCluster edition of the specified SysCluster instance.
	 *
	 *	@return	A new edition.
	 */
	ICFSecSysClusterEditObj newEditInstance( ICFSecSysClusterObj orig );

	/**
	 *	Internal use only.
	 */
	ICFSecSysClusterObj realiseSysCluster( ICFSecSysClusterObj Obj );

	/**
	 *	Internal use only.
	 */
	ICFSecSysClusterObj createSysCluster( ICFSecSysClusterObj Obj );

	/**
	 *	Read a SysCluster-derived instance by it's primary key.
	 *
	 *	@param	pkey	The primary key identifying the instance to read.
	 *
	 *	@return	The SysCluster-derived instance identified by the primary key,
	 *		or null if no such key value exists.
	 */
	ICFSecSysClusterObj readSysCluster( CFSecSysClusterPKey pkey );

	/**
	 *	Read a SysCluster-derived instance by it's primary key.
	 *
	 *	@param	pkey	The primary key identifying the instance to read.
	 *
	 *	@return	The SysCluster-derived instance identified by the primary key,
	 *		or null if no such key value exists.
	 */
	ICFSecSysClusterObj readSysCluster( CFSecSysClusterPKey pkey,
		boolean forceRead );

	ICFSecSysClusterObj readCachedSysCluster( CFSecSysClusterPKey pkey );

	public void reallyDeepDisposeSysCluster( ICFSecSysClusterObj obj );

	void deepDisposeSysCluster( CFSecSysClusterPKey pkey );

	/**
	 *	Internal use only.
	 */
	ICFSecSysClusterObj lockSysCluster( CFSecSysClusterPKey pkey );

	/**
	 *	Return a sorted list of all the SysCluster-derived instances in the database.
	 *
	 *	@return	List of ICFSecSysClusterObj instance, sorted by their primary keys, which
	 *		may include an empty set.
	 */
	List<ICFSecSysClusterObj> readAllSysCluster();

	/**
	 *	Return a sorted map of all the SysCluster-derived instances in the database.
	 *
	 *	@return	List of ICFSecSysClusterObj instance, sorted by their primary keys, which
	 *		may include an empty set.
	 */
	List<ICFSecSysClusterObj> readAllSysCluster( boolean forceRead );

	List<ICFSecSysClusterObj> readCachedAllSysCluster();

	/**
	 *	Get the CFSecSysClusterObj instance for the primary key attributes.
	 *
	 *	@param	argSingletonId	The SysCluster key attribute of the instance generating the id.
	 *
	 *	@return	CFSecSysClusterObj cached instance for the primary key, or
	 *		null if no such instance exists.
	 */
	ICFSecSysClusterObj readSysClusterByIdIdx( int SingletonId );

	/**
	 *	Get the CFSecSysClusterObj instance for the primary key attributes.
	 *
	 *	@param	argSingletonId	The SysCluster key attribute of the instance generating the id.
	 *
	 *	@return	CFSecSysClusterObj refreshed instance for the primary key, or
	 *		null if no such instance exists.
	 */
	ICFSecSysClusterObj readSysClusterByIdIdx( int SingletonId,
		boolean forceRead );

	/**
	 *	Get the map of CFSecSysClusterObj instances sorted by their primary keys for the duplicate ClusterIdx key.
	 *
	 *	@param	argClusterId	The SysCluster key attribute of the instance generating the id.
	 *
	 *	@return	List of CFSecSysClusterObj cached instances sorted by their primary keys for the duplicate ClusterIdx key,
	 *		which may be an empty set.
	 */
	List<ICFSecSysClusterObj> readSysClusterByClusterIdx( long ClusterId );

	/**
	 *	Get the map of CFSecSysClusterObj instances sorted by their primary keys for the duplicate ClusterIdx key.
	 *
	 *	@param	argClusterId	The SysCluster key attribute of the instance generating the id.
	 *
	 *	@return	List of CFSecSysClusterObj cached instances sorted by their primary keys for the duplicate ClusterIdx key,
	 *		which may be an empty set.
	 */
	List<ICFSecSysClusterObj> readSysClusterByClusterIdx( long ClusterId,
		boolean forceRead );

	ICFSecSysClusterObj readCachedSysClusterByIdIdx( int SingletonId );

	List<ICFSecSysClusterObj> readCachedSysClusterByClusterIdx( long ClusterId );

	void deepDisposeSysClusterByIdIdx( int SingletonId );

	void deepDisposeSysClusterByClusterIdx( long ClusterId );

	/**
	 *	Internal use only.
	 */
	ICFSecSysClusterObj updateSysCluster( ICFSecSysClusterObj Obj );

	/**
	 *	Internal use only.
	 */
	void deleteSysCluster( ICFSecSysClusterObj Obj );

	/**
	 *	Internal use only.
	 *
	 *	@param	argSingletonId	The SysCluster key attribute of the instance generating the id.
	 */
	void deleteSysClusterByIdIdx( int SingletonId );

	/**
	 *	Internal use only.
	 *
	 *	@param	argClusterId	The SysCluster key attribute of the instance generating the id.
	 */
	void deleteSysClusterByClusterIdx( long ClusterId );
}
