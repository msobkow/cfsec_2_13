// Description: Java 11 Table Object interface for CFSec.

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

package org.msscf.msscf.cfsec.CFSecObj;

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.msscf.msscf.cflib.CFLib.*;
import org.msscf.msscf.cfsec.CFSec.*;

public interface ICFSecSecGroupTableObj
{
	ICFSecSchemaObj getSchema();
	void setSchema( ICFSecSchemaObj value );

	void minimizeMemory();

	String getTableName();
	String getTableDbName();

	Class getObjQualifyingClass();

	/**
	 *	Instantiate a new SecGroup instance.
	 *
	 *	@return	A new instance.
	 */
	ICFSecSecGroupObj newInstance();

	/**
	 *	Instantiate a new SecGroup edition of the specified SecGroup instance.
	 *
	 *	@return	A new edition.
	 */
	ICFSecSecGroupEditObj newEditInstance( ICFSecSecGroupObj orig );

	/**
	 *	Internal use only.
	 */
	ICFSecSecGroupObj realiseSecGroup( ICFSecSecGroupObj Obj );

	/**
	 *	Internal use only.
	 */
	ICFSecSecGroupObj createSecGroup( ICFSecSecGroupObj Obj );

	/**
	 *	Read a SecGroup-derived instance by it's primary key.
	 *
	 *	@param	pkey	The primary key identifying the instance to read.
	 *
	 *	@return	The SecGroup-derived instance identified by the primary key,
	 *		or null if no such key value exists.
	 */
	ICFSecSecGroupObj readSecGroup( CFSecSecGroupPKey pkey );

	/**
	 *	Read a SecGroup-derived instance by it's primary key.
	 *
	 *	@param	pkey	The primary key identifying the instance to read.
	 *
	 *	@return	The SecGroup-derived instance identified by the primary key,
	 *		or null if no such key value exists.
	 */
	ICFSecSecGroupObj readSecGroup( CFSecSecGroupPKey pkey,
		boolean forceRead );

	ICFSecSecGroupObj readCachedSecGroup( CFSecSecGroupPKey pkey );

	public void reallyDeepDisposeSecGroup( ICFSecSecGroupObj obj );

	void deepDisposeSecGroup( CFSecSecGroupPKey pkey );

	/**
	 *	Internal use only.
	 */
	ICFSecSecGroupObj lockSecGroup( CFSecSecGroupPKey pkey );

	/**
	 *	Return a sorted list of all the SecGroup-derived instances in the database.
	 *
	 *	@return	List of ICFSecSecGroupObj instance, sorted by their primary keys, which
	 *		may include an empty set.
	 */
	List<ICFSecSecGroupObj> readAllSecGroup();

	/**
	 *	Return a sorted map of all the SecGroup-derived instances in the database.
	 *
	 *	@return	List of ICFSecSecGroupObj instance, sorted by their primary keys, which
	 *		may include an empty set.
	 */
	List<ICFSecSecGroupObj> readAllSecGroup( boolean forceRead );

	List<ICFSecSecGroupObj> readCachedAllSecGroup();

	/**
	 *	Get the CFSecSecGroupObj instance for the primary key attributes.
	 *
	 *	@param	argClusterId	The SecGroup key attribute of the instance generating the id.
	 *
	 *	@param	argSecGroupId	The SecGroup key attribute of the instance generating the id.
	 *
	 *	@return	CFSecSecGroupObj cached instance for the primary key, or
	 *		null if no such instance exists.
	 */
	ICFSecSecGroupObj readSecGroupByIdIdx( long ClusterId,
		int SecGroupId );

	/**
	 *	Get the CFSecSecGroupObj instance for the primary key attributes.
	 *
	 *	@param	argClusterId	The SecGroup key attribute of the instance generating the id.
	 *
	 *	@param	argSecGroupId	The SecGroup key attribute of the instance generating the id.
	 *
	 *	@return	CFSecSecGroupObj refreshed instance for the primary key, or
	 *		null if no such instance exists.
	 */
	ICFSecSecGroupObj readSecGroupByIdIdx( long ClusterId,
		int SecGroupId,
		boolean forceRead );

	/**
	 *	Get the map of CFSecSecGroupObj instances sorted by their primary keys for the duplicate ClusterIdx key.
	 *
	 *	@param	argClusterId	The SecGroup key attribute of the instance generating the id.
	 *
	 *	@return	List of CFSecSecGroupObj cached instances sorted by their primary keys for the duplicate ClusterIdx key,
	 *		which may be an empty set.
	 */
	List<ICFSecSecGroupObj> readSecGroupByClusterIdx( long ClusterId );

	/**
	 *	Get the map of CFSecSecGroupObj instances sorted by their primary keys for the duplicate ClusterIdx key.
	 *
	 *	@param	argClusterId	The SecGroup key attribute of the instance generating the id.
	 *
	 *	@return	List of CFSecSecGroupObj cached instances sorted by their primary keys for the duplicate ClusterIdx key,
	 *		which may be an empty set.
	 */
	List<ICFSecSecGroupObj> readSecGroupByClusterIdx( long ClusterId,
		boolean forceRead );

	/**
	 *	Get the map of CFSecSecGroupObj instances sorted by their primary keys for the duplicate ClusterVisIdx key.
	 *
	 *	@param	argClusterId	The SecGroup key attribute of the instance generating the id.
	 *
	 *	@param	argIsVisible	The SecGroup key attribute of the instance generating the id.
	 *
	 *	@return	List of CFSecSecGroupObj cached instances sorted by their primary keys for the duplicate ClusterVisIdx key,
	 *		which may be an empty set.
	 */
	List<ICFSecSecGroupObj> readSecGroupByClusterVisIdx( long ClusterId,
		boolean IsVisible );

	/**
	 *	Get the map of CFSecSecGroupObj instances sorted by their primary keys for the duplicate ClusterVisIdx key.
	 *
	 *	@param	argClusterId	The SecGroup key attribute of the instance generating the id.
	 *
	 *	@param	argIsVisible	The SecGroup key attribute of the instance generating the id.
	 *
	 *	@return	List of CFSecSecGroupObj cached instances sorted by their primary keys for the duplicate ClusterVisIdx key,
	 *		which may be an empty set.
	 */
	List<ICFSecSecGroupObj> readSecGroupByClusterVisIdx( long ClusterId,
		boolean IsVisible,
		boolean forceRead );

	/**
	 *	Get the CFSecSecGroupObj instance for the unique UNameIdx key.
	 *
	 *	@param	argClusterId	The SecGroup key attribute of the instance generating the id.
	 *
	 *	@param	argName	The SecGroup key attribute of the instance generating the id.
	 *
	 *	@return	CFSecSecGroupObj cached instance for the unique UNameIdx key, or
	 *		null if no such instance exists.
	 */
	ICFSecSecGroupObj readSecGroupByUNameIdx(long ClusterId,
		String Name );

	/**
	 *	Get the CFSecSecGroupObj instance for the unique UNameIdx key.
	 *
	 *	@param	argClusterId	The SecGroup key attribute of the instance generating the id.
	 *
	 *	@param	argName	The SecGroup key attribute of the instance generating the id.
	 *
	 *	@return	CFSecSecGroupObj refreshed instance for the unique UNameIdx key, or
	 *		null if no such instance exists.
	 */
	ICFSecSecGroupObj readSecGroupByUNameIdx(long ClusterId,
		String Name,
		boolean forceRead );

	ICFSecSecGroupObj readCachedSecGroupByIdIdx( long ClusterId,
		int SecGroupId );

	List<ICFSecSecGroupObj> readCachedSecGroupByClusterIdx( long ClusterId );

	List<ICFSecSecGroupObj> readCachedSecGroupByClusterVisIdx( long ClusterId,
		boolean IsVisible );

	ICFSecSecGroupObj readCachedSecGroupByUNameIdx( long ClusterId,
		String Name );

	void deepDisposeSecGroupByIdIdx( long ClusterId,
		int SecGroupId );

	void deepDisposeSecGroupByClusterIdx( long ClusterId );

	void deepDisposeSecGroupByClusterVisIdx( long ClusterId,
		boolean IsVisible );

	void deepDisposeSecGroupByUNameIdx( long ClusterId,
		String Name );

	/**
	 *	Internal use only.
	 */
	ICFSecSecGroupObj updateSecGroup( ICFSecSecGroupObj Obj );

	/**
	 *	Internal use only.
	 */
	void deleteSecGroup( ICFSecSecGroupObj Obj );

	/**
	 *	Internal use only.
	 *
	 *	@param	argClusterId	The SecGroup key attribute of the instance generating the id.
	 *
	 *	@param	argSecGroupId	The SecGroup key attribute of the instance generating the id.
	 */
	void deleteSecGroupByIdIdx( long ClusterId,
		int SecGroupId );

	/**
	 *	Internal use only.
	 *
	 *	@param	argClusterId	The SecGroup key attribute of the instance generating the id.
	 */
	void deleteSecGroupByClusterIdx( long ClusterId );

	/**
	 *	Internal use only.
	 *
	 *	@param	argClusterId	The SecGroup key attribute of the instance generating the id.
	 *
	 *	@param	argIsVisible	The SecGroup key attribute of the instance generating the id.
	 */
	void deleteSecGroupByClusterVisIdx( long ClusterId,
		boolean IsVisible );

	/**
	 *	Internal use only.
	 *
	 *	@param	argClusterId	The SecGroup key attribute of the instance generating the id.
	 *
	 *	@param	argName	The SecGroup key attribute of the instance generating the id.
	 */
	void deleteSecGroupByUNameIdx(long ClusterId,
		String Name );
}
