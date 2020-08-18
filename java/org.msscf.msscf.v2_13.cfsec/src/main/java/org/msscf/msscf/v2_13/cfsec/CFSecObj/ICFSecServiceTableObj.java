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

package org.msscf.msscf.v2_13.cfsec.CFSecObj;

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.msscf.msscf.v2_13.cflib.CFLib.*;
import org.msscf.msscf.v2_13.cfsec.CFSec.*;

public interface ICFSecServiceTableObj
{
	ICFSecSchemaObj getSchema();
	void setSchema( ICFSecSchemaObj value );

	void minimizeMemory();

	String getTableName();
	String getTableDbName();

	Class getObjQualifyingClass();

	/**
	 *	Instantiate a new Service instance.
	 *
	 *	@return	A new instance.
	 */
	ICFSecServiceObj newInstance();

	/**
	 *	Instantiate a new Service edition of the specified Service instance.
	 *
	 *	@return	A new edition.
	 */
	ICFSecServiceEditObj newEditInstance( ICFSecServiceObj orig );

	/**
	 *	Internal use only.
	 */
	ICFSecServiceObj realiseService( ICFSecServiceObj Obj );

	/**
	 *	Internal use only.
	 */
	ICFSecServiceObj createService( ICFSecServiceObj Obj );

	/**
	 *	Read a Service-derived instance by it's primary key.
	 *
	 *	@param	pkey	The primary key identifying the instance to read.
	 *
	 *	@return	The Service-derived instance identified by the primary key,
	 *		or null if no such key value exists.
	 */
	ICFSecServiceObj readService( CFSecServicePKey pkey );

	/**
	 *	Read a Service-derived instance by it's primary key.
	 *
	 *	@param	pkey	The primary key identifying the instance to read.
	 *
	 *	@return	The Service-derived instance identified by the primary key,
	 *		or null if no such key value exists.
	 */
	ICFSecServiceObj readService( CFSecServicePKey pkey,
		boolean forceRead );

	ICFSecServiceObj readCachedService( CFSecServicePKey pkey );

	public void reallyDeepDisposeService( ICFSecServiceObj obj );

	void deepDisposeService( CFSecServicePKey pkey );

	/**
	 *	Internal use only.
	 */
	ICFSecServiceObj lockService( CFSecServicePKey pkey );

	/**
	 *	Return a sorted list of all the Service-derived instances in the database.
	 *
	 *	@return	List of ICFSecServiceObj instance, sorted by their primary keys, which
	 *		may include an empty set.
	 */
	List<ICFSecServiceObj> readAllService();

	/**
	 *	Return a sorted map of all the Service-derived instances in the database.
	 *
	 *	@return	List of ICFSecServiceObj instance, sorted by their primary keys, which
	 *		may include an empty set.
	 */
	List<ICFSecServiceObj> readAllService( boolean forceRead );

	List<ICFSecServiceObj> readCachedAllService();

	/**
	 *	Return a sorted map of a page of the Service-derived instances in the database.
	 *
	 *	@return	List of ICFSecServiceObj instance, sorted by their primary keys, which
	 *		may include an empty set.
	 */
	List<ICFSecServiceObj> pageAllService(Long priorClusterId,
		Long priorServiceId );

	/**
	 *	Get the CFSecServiceObj instance for the primary key attributes.
	 *
	 *	@param	argClusterId	The Service key attribute of the instance generating the id.
	 *
	 *	@param	argServiceId	The Service key attribute of the instance generating the id.
	 *
	 *	@return	CFSecServiceObj cached instance for the primary key, or
	 *		null if no such instance exists.
	 */
	ICFSecServiceObj readServiceByIdIdx( long ClusterId,
		long ServiceId );

	/**
	 *	Get the CFSecServiceObj instance for the primary key attributes.
	 *
	 *	@param	argClusterId	The Service key attribute of the instance generating the id.
	 *
	 *	@param	argServiceId	The Service key attribute of the instance generating the id.
	 *
	 *	@return	CFSecServiceObj refreshed instance for the primary key, or
	 *		null if no such instance exists.
	 */
	ICFSecServiceObj readServiceByIdIdx( long ClusterId,
		long ServiceId,
		boolean forceRead );

	/**
	 *	Get the map of CFSecServiceObj instances sorted by their primary keys for the duplicate ClusterIdx key.
	 *
	 *	@param	argClusterId	The Service key attribute of the instance generating the id.
	 *
	 *	@return	List of CFSecServiceObj cached instances sorted by their primary keys for the duplicate ClusterIdx key,
	 *		which may be an empty set.
	 */
	List<ICFSecServiceObj> readServiceByClusterIdx( long ClusterId );

	/**
	 *	Get the map of CFSecServiceObj instances sorted by their primary keys for the duplicate ClusterIdx key.
	 *
	 *	@param	argClusterId	The Service key attribute of the instance generating the id.
	 *
	 *	@return	List of CFSecServiceObj cached instances sorted by their primary keys for the duplicate ClusterIdx key,
	 *		which may be an empty set.
	 */
	List<ICFSecServiceObj> readServiceByClusterIdx( long ClusterId,
		boolean forceRead );

	/**
	 *	Get the map of CFSecServiceObj instances sorted by their primary keys for the duplicate HostIdx key.
	 *
	 *	@param	argClusterId	The Service key attribute of the instance generating the id.
	 *
	 *	@param	argHostNodeId	The Service key attribute of the instance generating the id.
	 *
	 *	@return	List of CFSecServiceObj cached instances sorted by their primary keys for the duplicate HostIdx key,
	 *		which may be an empty set.
	 */
	List<ICFSecServiceObj> readServiceByHostIdx( long ClusterId,
		long HostNodeId );

	/**
	 *	Get the map of CFSecServiceObj instances sorted by their primary keys for the duplicate HostIdx key.
	 *
	 *	@param	argClusterId	The Service key attribute of the instance generating the id.
	 *
	 *	@param	argHostNodeId	The Service key attribute of the instance generating the id.
	 *
	 *	@return	List of CFSecServiceObj cached instances sorted by their primary keys for the duplicate HostIdx key,
	 *		which may be an empty set.
	 */
	List<ICFSecServiceObj> readServiceByHostIdx( long ClusterId,
		long HostNodeId,
		boolean forceRead );

	/**
	 *	Get the map of CFSecServiceObj instances sorted by their primary keys for the duplicate TypeIdx key.
	 *
	 *	@param	argServiceTypeId	The Service key attribute of the instance generating the id.
	 *
	 *	@return	List of CFSecServiceObj cached instances sorted by their primary keys for the duplicate TypeIdx key,
	 *		which may be an empty set.
	 */
	List<ICFSecServiceObj> readServiceByTypeIdx( int ServiceTypeId );

	/**
	 *	Get the map of CFSecServiceObj instances sorted by their primary keys for the duplicate TypeIdx key.
	 *
	 *	@param	argServiceTypeId	The Service key attribute of the instance generating the id.
	 *
	 *	@return	List of CFSecServiceObj cached instances sorted by their primary keys for the duplicate TypeIdx key,
	 *		which may be an empty set.
	 */
	List<ICFSecServiceObj> readServiceByTypeIdx( int ServiceTypeId,
		boolean forceRead );

	/**
	 *	Get the CFSecServiceObj instance for the unique UTypeIdx key.
	 *
	 *	@param	argClusterId	The Service key attribute of the instance generating the id.
	 *
	 *	@param	argHostNodeId	The Service key attribute of the instance generating the id.
	 *
	 *	@param	argServiceTypeId	The Service key attribute of the instance generating the id.
	 *
	 *	@return	CFSecServiceObj cached instance for the unique UTypeIdx key, or
	 *		null if no such instance exists.
	 */
	ICFSecServiceObj readServiceByUTypeIdx(long ClusterId,
		long HostNodeId,
		int ServiceTypeId );

	/**
	 *	Get the CFSecServiceObj instance for the unique UTypeIdx key.
	 *
	 *	@param	argClusterId	The Service key attribute of the instance generating the id.
	 *
	 *	@param	argHostNodeId	The Service key attribute of the instance generating the id.
	 *
	 *	@param	argServiceTypeId	The Service key attribute of the instance generating the id.
	 *
	 *	@return	CFSecServiceObj refreshed instance for the unique UTypeIdx key, or
	 *		null if no such instance exists.
	 */
	ICFSecServiceObj readServiceByUTypeIdx(long ClusterId,
		long HostNodeId,
		int ServiceTypeId,
		boolean forceRead );

	/**
	 *	Get the CFSecServiceObj instance for the unique UHostPortIdx key.
	 *
	 *	@param	argClusterId	The Service key attribute of the instance generating the id.
	 *
	 *	@param	argHostNodeId	The Service key attribute of the instance generating the id.
	 *
	 *	@param	argHostPort	The Service key attribute of the instance generating the id.
	 *
	 *	@return	CFSecServiceObj cached instance for the unique UHostPortIdx key, or
	 *		null if no such instance exists.
	 */
	ICFSecServiceObj readServiceByUHostPortIdx(long ClusterId,
		long HostNodeId,
		short HostPort );

	/**
	 *	Get the CFSecServiceObj instance for the unique UHostPortIdx key.
	 *
	 *	@param	argClusterId	The Service key attribute of the instance generating the id.
	 *
	 *	@param	argHostNodeId	The Service key attribute of the instance generating the id.
	 *
	 *	@param	argHostPort	The Service key attribute of the instance generating the id.
	 *
	 *	@return	CFSecServiceObj refreshed instance for the unique UHostPortIdx key, or
	 *		null if no such instance exists.
	 */
	ICFSecServiceObj readServiceByUHostPortIdx(long ClusterId,
		long HostNodeId,
		short HostPort,
		boolean forceRead );

	ICFSecServiceObj readCachedServiceByIdIdx( long ClusterId,
		long ServiceId );

	List<ICFSecServiceObj> readCachedServiceByClusterIdx( long ClusterId );

	List<ICFSecServiceObj> readCachedServiceByHostIdx( long ClusterId,
		long HostNodeId );

	List<ICFSecServiceObj> readCachedServiceByTypeIdx( int ServiceTypeId );

	ICFSecServiceObj readCachedServiceByUTypeIdx( long ClusterId,
		long HostNodeId,
		int ServiceTypeId );

	ICFSecServiceObj readCachedServiceByUHostPortIdx( long ClusterId,
		long HostNodeId,
		short HostPort );

	void deepDisposeServiceByIdIdx( long ClusterId,
		long ServiceId );

	void deepDisposeServiceByClusterIdx( long ClusterId );

	void deepDisposeServiceByHostIdx( long ClusterId,
		long HostNodeId );

	void deepDisposeServiceByTypeIdx( int ServiceTypeId );

	void deepDisposeServiceByUTypeIdx( long ClusterId,
		long HostNodeId,
		int ServiceTypeId );

	void deepDisposeServiceByUHostPortIdx( long ClusterId,
		long HostNodeId,
		short HostPort );

	/**
	 *	Read a page of data as a List of Service-derived instances sorted by their primary keys,
	 *	as identified by the duplicate ClusterIdx key attributes.
	 *
	 *	@param	argClusterId	The Service key attribute of the instance generating the id.
	 *
	 *	@return	A List of Service-derived instances sorted by their primary keys,
	 *		as identified by the key attributes, which may be an empty set.
	 */
	List<ICFSecServiceObj> pageServiceByClusterIdx( long ClusterId,
		Long priorClusterId,
		Long priorServiceId );

	/**
	 *	Read a page of data as a List of Service-derived instances sorted by their primary keys,
	 *	as identified by the duplicate HostIdx key attributes.
	 *
	 *	@param	argClusterId	The Service key attribute of the instance generating the id.
	 *
	 *	@param	argHostNodeId	The Service key attribute of the instance generating the id.
	 *
	 *	@return	A List of Service-derived instances sorted by their primary keys,
	 *		as identified by the key attributes, which may be an empty set.
	 */
	List<ICFSecServiceObj> pageServiceByHostIdx( long ClusterId,
		long HostNodeId,
		Long priorClusterId,
		Long priorServiceId );

	/**
	 *	Read a page of data as a List of Service-derived instances sorted by their primary keys,
	 *	as identified by the duplicate TypeIdx key attributes.
	 *
	 *	@param	argServiceTypeId	The Service key attribute of the instance generating the id.
	 *
	 *	@return	A List of Service-derived instances sorted by their primary keys,
	 *		as identified by the key attributes, which may be an empty set.
	 */
	List<ICFSecServiceObj> pageServiceByTypeIdx( int ServiceTypeId,
		Long priorClusterId,
		Long priorServiceId );

	/**
	 *	Internal use only.
	 */
	ICFSecServiceObj updateService( ICFSecServiceObj Obj );

	/**
	 *	Internal use only.
	 */
	void deleteService( ICFSecServiceObj Obj );

	/**
	 *	Internal use only.
	 *
	 *	@param	argClusterId	The Service key attribute of the instance generating the id.
	 *
	 *	@param	argServiceId	The Service key attribute of the instance generating the id.
	 */
	void deleteServiceByIdIdx( long ClusterId,
		long ServiceId );

	/**
	 *	Internal use only.
	 *
	 *	@param	argClusterId	The Service key attribute of the instance generating the id.
	 */
	void deleteServiceByClusterIdx( long ClusterId );

	/**
	 *	Internal use only.
	 *
	 *	@param	argClusterId	The Service key attribute of the instance generating the id.
	 *
	 *	@param	argHostNodeId	The Service key attribute of the instance generating the id.
	 */
	void deleteServiceByHostIdx( long ClusterId,
		long HostNodeId );

	/**
	 *	Internal use only.
	 *
	 *	@param	argServiceTypeId	The Service key attribute of the instance generating the id.
	 */
	void deleteServiceByTypeIdx( int ServiceTypeId );

	/**
	 *	Internal use only.
	 *
	 *	@param	argClusterId	The Service key attribute of the instance generating the id.
	 *
	 *	@param	argHostNodeId	The Service key attribute of the instance generating the id.
	 *
	 *	@param	argServiceTypeId	The Service key attribute of the instance generating the id.
	 */
	void deleteServiceByUTypeIdx(long ClusterId,
		long HostNodeId,
		int ServiceTypeId );

	/**
	 *	Internal use only.
	 *
	 *	@param	argClusterId	The Service key attribute of the instance generating the id.
	 *
	 *	@param	argHostNodeId	The Service key attribute of the instance generating the id.
	 *
	 *	@param	argHostPort	The Service key attribute of the instance generating the id.
	 */
	void deleteServiceByUHostPortIdx(long ClusterId,
		long HostNodeId,
		short HostPort );
}
