// Description: Java 11 Table Object interface for CFSec.

/*
 *	org.msscf.msscf.CFSec
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

package org.msscf.msscf.cfsec.CFSecObj;

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import com.github.msobkow.cflib.CFLib.*;
import org.msscf.msscf.cfsec.CFSec.*;

public interface ICFSecServiceTypeTableObj
{
	ICFSecSchemaObj getSchema();
	void setSchema( ICFSecSchemaObj value );

	void minimizeMemory();

	String getTableName();
	String getTableDbName();

	Class getObjQualifyingClass();

	/**
	 *	Instantiate a new ServiceType instance.
	 *
	 *	@return	A new instance.
	 */
	ICFSecServiceTypeObj newInstance();

	/**
	 *	Instantiate a new ServiceType edition of the specified ServiceType instance.
	 *
	 *	@return	A new edition.
	 */
	ICFSecServiceTypeEditObj newEditInstance( ICFSecServiceTypeObj orig );

	/**
	 *	Internal use only.
	 */
	ICFSecServiceTypeObj realiseServiceType( ICFSecServiceTypeObj Obj );

	/**
	 *	Internal use only.
	 */
	ICFSecServiceTypeObj createServiceType( ICFSecServiceTypeObj Obj );

	/**
	 *	Read a ServiceType-derived instance by it's primary key.
	 *
	 *	@param	pkey	The primary key identifying the instance to read.
	 *
	 *	@return	The ServiceType-derived instance identified by the primary key,
	 *		or null if no such key value exists.
	 */
	ICFSecServiceTypeObj readServiceType( CFSecServiceTypePKey pkey );

	/**
	 *	Read a ServiceType-derived instance by it's primary key.
	 *
	 *	@param	pkey	The primary key identifying the instance to read.
	 *
	 *	@return	The ServiceType-derived instance identified by the primary key,
	 *		or null if no such key value exists.
	 */
	ICFSecServiceTypeObj readServiceType( CFSecServiceTypePKey pkey,
		boolean forceRead );

	ICFSecServiceTypeObj readCachedServiceType( CFSecServiceTypePKey pkey );

	public void reallyDeepDisposeServiceType( ICFSecServiceTypeObj obj );

	void deepDisposeServiceType( CFSecServiceTypePKey pkey );

	/**
	 *	Internal use only.
	 */
	ICFSecServiceTypeObj lockServiceType( CFSecServiceTypePKey pkey );

	/**
	 *	Return a sorted list of all the ServiceType-derived instances in the database.
	 *
	 *	@return	List of ICFSecServiceTypeObj instance, sorted by their primary keys, which
	 *		may include an empty set.
	 */
	List<ICFSecServiceTypeObj> readAllServiceType();

	/**
	 *	Return a sorted map of all the ServiceType-derived instances in the database.
	 *
	 *	@return	List of ICFSecServiceTypeObj instance, sorted by their primary keys, which
	 *		may include an empty set.
	 */
	List<ICFSecServiceTypeObj> readAllServiceType( boolean forceRead );

	List<ICFSecServiceTypeObj> readCachedAllServiceType();

	/**
	 *	Get the CFSecServiceTypeObj instance for the primary key attributes.
	 *
	 *	@param	argServiceTypeId	The ServiceType key attribute of the instance generating the id.
	 *
	 *	@return	CFSecServiceTypeObj cached instance for the primary key, or
	 *		null if no such instance exists.
	 */
	ICFSecServiceTypeObj readServiceTypeByIdIdx( int ServiceTypeId );

	/**
	 *	Get the CFSecServiceTypeObj instance for the primary key attributes.
	 *
	 *	@param	argServiceTypeId	The ServiceType key attribute of the instance generating the id.
	 *
	 *	@return	CFSecServiceTypeObj refreshed instance for the primary key, or
	 *		null if no such instance exists.
	 */
	ICFSecServiceTypeObj readServiceTypeByIdIdx( int ServiceTypeId,
		boolean forceRead );

	/**
	 *	Get the CFSecServiceTypeObj instance for the unique UDescrIdx key.
	 *
	 *	@param	argDescription	The ServiceType key attribute of the instance generating the id.
	 *
	 *	@return	CFSecServiceTypeObj cached instance for the unique UDescrIdx key, or
	 *		null if no such instance exists.
	 */
	ICFSecServiceTypeObj readServiceTypeByUDescrIdx(String Description );

	/**
	 *	Get the CFSecServiceTypeObj instance for the unique UDescrIdx key.
	 *
	 *	@param	argDescription	The ServiceType key attribute of the instance generating the id.
	 *
	 *	@return	CFSecServiceTypeObj refreshed instance for the unique UDescrIdx key, or
	 *		null if no such instance exists.
	 */
	ICFSecServiceTypeObj readServiceTypeByUDescrIdx(String Description,
		boolean forceRead );

	ICFSecServiceTypeObj readCachedServiceTypeByIdIdx( int ServiceTypeId );

	ICFSecServiceTypeObj readCachedServiceTypeByUDescrIdx( String Description );

	void deepDisposeServiceTypeByIdIdx( int ServiceTypeId );

	void deepDisposeServiceTypeByUDescrIdx( String Description );

	/**
	 *	Internal use only.
	 */
	ICFSecServiceTypeObj updateServiceType( ICFSecServiceTypeObj Obj );

	/**
	 *	Internal use only.
	 */
	void deleteServiceType( ICFSecServiceTypeObj Obj );

	/**
	 *	Internal use only.
	 *
	 *	@param	argServiceTypeId	The ServiceType key attribute of the instance generating the id.
	 */
	void deleteServiceTypeByIdIdx( int ServiceTypeId );

	/**
	 *	Internal use only.
	 *
	 *	@param	argDescription	The ServiceType key attribute of the instance generating the id.
	 */
	void deleteServiceTypeByUDescrIdx(String Description );
}
