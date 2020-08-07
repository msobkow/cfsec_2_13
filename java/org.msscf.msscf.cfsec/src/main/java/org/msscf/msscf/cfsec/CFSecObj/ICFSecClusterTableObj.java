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

public interface ICFSecClusterTableObj
{
	ICFSecSchemaObj getSchema();
	void setSchema( ICFSecSchemaObj value );

	void minimizeMemory();

	String getTableName();
	String getTableDbName();

	Class getObjQualifyingClass();

	/**
	 *	Instantiate a new Cluster instance.
	 *
	 *	@return	A new instance.
	 */
	ICFSecClusterObj newInstance();

	/**
	 *	Instantiate a new Cluster edition of the specified Cluster instance.
	 *
	 *	@return	A new edition.
	 */
	ICFSecClusterEditObj newEditInstance( ICFSecClusterObj orig );

	/**
	 *	Internal use only.
	 */
	ICFSecClusterObj realiseCluster( ICFSecClusterObj Obj );

	/**
	 *	Internal use only.
	 */
	ICFSecClusterObj createCluster( ICFSecClusterObj Obj );

	/**
	 *	Read a Cluster-derived instance by it's primary key.
	 *
	 *	@param	pkey	The primary key identifying the instance to read.
	 *
	 *	@return	The Cluster-derived instance identified by the primary key,
	 *		or null if no such key value exists.
	 */
	ICFSecClusterObj readCluster( CFSecClusterPKey pkey );

	/**
	 *	Read a Cluster-derived instance by it's primary key.
	 *
	 *	@param	pkey	The primary key identifying the instance to read.
	 *
	 *	@return	The Cluster-derived instance identified by the primary key,
	 *		or null if no such key value exists.
	 */
	ICFSecClusterObj readCluster( CFSecClusterPKey pkey,
		boolean forceRead );

	ICFSecClusterObj readCachedCluster( CFSecClusterPKey pkey );

	public void reallyDeepDisposeCluster( ICFSecClusterObj obj );

	void deepDisposeCluster( CFSecClusterPKey pkey );

	/**
	 *	Internal use only.
	 */
	ICFSecClusterObj lockCluster( CFSecClusterPKey pkey );

	/**
	 *	Return a sorted list of all the Cluster-derived instances in the database.
	 *
	 *	@return	List of ICFSecClusterObj instance, sorted by their primary keys, which
	 *		may include an empty set.
	 */
	List<ICFSecClusterObj> readAllCluster();

	/**
	 *	Return a sorted map of all the Cluster-derived instances in the database.
	 *
	 *	@return	List of ICFSecClusterObj instance, sorted by their primary keys, which
	 *		may include an empty set.
	 */
	List<ICFSecClusterObj> readAllCluster( boolean forceRead );

	List<ICFSecClusterObj> readCachedAllCluster();

	/**
	 *	Return a sorted map of a page of the Cluster-derived instances in the database.
	 *
	 *	@return	List of ICFSecClusterObj instance, sorted by their primary keys, which
	 *		may include an empty set.
	 */
	List<ICFSecClusterObj> pageAllCluster(Long priorId );

	/**
	 *	Get the CFSecClusterObj instance for the primary key attributes.
	 *
	 *	@param	argId	The Cluster key attribute of the instance generating the id.
	 *
	 *	@return	CFSecClusterObj cached instance for the primary key, or
	 *		null if no such instance exists.
	 */
	ICFSecClusterObj readClusterByIdIdx( long Id );

	/**
	 *	Get the CFSecClusterObj instance for the primary key attributes.
	 *
	 *	@param	argId	The Cluster key attribute of the instance generating the id.
	 *
	 *	@return	CFSecClusterObj refreshed instance for the primary key, or
	 *		null if no such instance exists.
	 */
	ICFSecClusterObj readClusterByIdIdx( long Id,
		boolean forceRead );

	/**
	 *	Get the CFSecClusterObj instance for the unique UDomNameIdx key.
	 *
	 *	@param	argFullDomName	The Cluster key attribute of the instance generating the id.
	 *
	 *	@return	CFSecClusterObj cached instance for the unique UDomNameIdx key, or
	 *		null if no such instance exists.
	 */
	ICFSecClusterObj readClusterByUDomNameIdx(String FullDomName );

	/**
	 *	Get the CFSecClusterObj instance for the unique UDomNameIdx key.
	 *
	 *	@param	argFullDomName	The Cluster key attribute of the instance generating the id.
	 *
	 *	@return	CFSecClusterObj refreshed instance for the unique UDomNameIdx key, or
	 *		null if no such instance exists.
	 */
	ICFSecClusterObj readClusterByUDomNameIdx(String FullDomName,
		boolean forceRead );

	/**
	 *	Get the CFSecClusterObj instance for the unique UDescrIdx key.
	 *
	 *	@param	argDescription	The Cluster key attribute of the instance generating the id.
	 *
	 *	@return	CFSecClusterObj cached instance for the unique UDescrIdx key, or
	 *		null if no such instance exists.
	 */
	ICFSecClusterObj readClusterByUDescrIdx(String Description );

	/**
	 *	Get the CFSecClusterObj instance for the unique UDescrIdx key.
	 *
	 *	@param	argDescription	The Cluster key attribute of the instance generating the id.
	 *
	 *	@return	CFSecClusterObj refreshed instance for the unique UDescrIdx key, or
	 *		null if no such instance exists.
	 */
	ICFSecClusterObj readClusterByUDescrIdx(String Description,
		boolean forceRead );

	ICFSecClusterObj readCachedClusterByIdIdx( long Id );

	ICFSecClusterObj readCachedClusterByUDomNameIdx( String FullDomName );

	ICFSecClusterObj readCachedClusterByUDescrIdx( String Description );

	void deepDisposeClusterByIdIdx( long Id );

	void deepDisposeClusterByUDomNameIdx( String FullDomName );

	void deepDisposeClusterByUDescrIdx( String Description );

	/**
	 *	Internal use only.
	 */
	ICFSecClusterObj updateCluster( ICFSecClusterObj Obj );

	/**
	 *	Internal use only.
	 */
	void deleteCluster( ICFSecClusterObj Obj );

	/**
	 *	Internal use only.
	 *
	 *	@param	argId	The Cluster key attribute of the instance generating the id.
	 */
	void deleteClusterByIdIdx( long Id );

	/**
	 *	Internal use only.
	 *
	 *	@param	argFullDomName	The Cluster key attribute of the instance generating the id.
	 */
	void deleteClusterByUDomNameIdx(String FullDomName );

	/**
	 *	Internal use only.
	 *
	 *	@param	argDescription	The Cluster key attribute of the instance generating the id.
	 */
	void deleteClusterByUDescrIdx(String Description );

	ICFSecClusterObj getSystemCluster();
}
