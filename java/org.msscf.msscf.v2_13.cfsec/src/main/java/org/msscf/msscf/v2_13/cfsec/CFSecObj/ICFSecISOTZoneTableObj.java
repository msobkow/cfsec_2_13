// Description: Java 11 Table Object interface for CFSec.

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

public interface ICFSecISOTZoneTableObj
{
	ICFSecSchemaObj getSchema();
	void setSchema( ICFSecSchemaObj value );

	void minimizeMemory();

	String getTableName();
	String getTableDbName();

	Class getObjQualifyingClass();

	/**
	 *	Instantiate a new ISOTZone instance.
	 *
	 *	@return	A new instance.
	 */
	ICFSecISOTZoneObj newInstance();

	/**
	 *	Instantiate a new ISOTZone edition of the specified ISOTZone instance.
	 *
	 *	@return	A new edition.
	 */
	ICFSecISOTZoneEditObj newEditInstance( ICFSecISOTZoneObj orig );

	/**
	 *	Internal use only.
	 */
	ICFSecISOTZoneObj realiseISOTZone( ICFSecISOTZoneObj Obj );

	/**
	 *	Internal use only.
	 */
	ICFSecISOTZoneObj createISOTZone( ICFSecISOTZoneObj Obj );

	/**
	 *	Read a ISOTZone-derived instance by it's primary key.
	 *
	 *	@param	pkey	The primary key identifying the instance to read.
	 *
	 *	@return	The ISOTZone-derived instance identified by the primary key,
	 *		or null if no such key value exists.
	 */
	ICFSecISOTZoneObj readISOTZone( CFSecISOTZonePKey pkey );

	/**
	 *	Read a ISOTZone-derived instance by it's primary key.
	 *
	 *	@param	pkey	The primary key identifying the instance to read.
	 *
	 *	@return	The ISOTZone-derived instance identified by the primary key,
	 *		or null if no such key value exists.
	 */
	ICFSecISOTZoneObj readISOTZone( CFSecISOTZonePKey pkey,
		boolean forceRead );

	ICFSecISOTZoneObj readCachedISOTZone( CFSecISOTZonePKey pkey );

	public void reallyDeepDisposeISOTZone( ICFSecISOTZoneObj obj );

	void deepDisposeISOTZone( CFSecISOTZonePKey pkey );

	/**
	 *	Internal use only.
	 */
	ICFSecISOTZoneObj lockISOTZone( CFSecISOTZonePKey pkey );

	/**
	 *	Return a sorted list of all the ISOTZone-derived instances in the database.
	 *
	 *	@return	List of ICFSecISOTZoneObj instance, sorted by their primary keys, which
	 *		may include an empty set.
	 */
	List<ICFSecISOTZoneObj> readAllISOTZone();

	/**
	 *	Return a sorted map of all the ISOTZone-derived instances in the database.
	 *
	 *	@return	List of ICFSecISOTZoneObj instance, sorted by their primary keys, which
	 *		may include an empty set.
	 */
	List<ICFSecISOTZoneObj> readAllISOTZone( boolean forceRead );

	List<ICFSecISOTZoneObj> readCachedAllISOTZone();

	/**
	 *	Get the CFSecISOTZoneObj instance for the primary key attributes.
	 *
	 *	@param	argISOTZoneId	The ISOTZone key attribute of the instance generating the id.
	 *
	 *	@return	CFSecISOTZoneObj cached instance for the primary key, or
	 *		null if no such instance exists.
	 */
	ICFSecISOTZoneObj readISOTZoneByIdIdx( short ISOTZoneId );

	/**
	 *	Get the CFSecISOTZoneObj instance for the primary key attributes.
	 *
	 *	@param	argISOTZoneId	The ISOTZone key attribute of the instance generating the id.
	 *
	 *	@return	CFSecISOTZoneObj refreshed instance for the primary key, or
	 *		null if no such instance exists.
	 */
	ICFSecISOTZoneObj readISOTZoneByIdIdx( short ISOTZoneId,
		boolean forceRead );

	/**
	 *	Get the map of CFSecISOTZoneObj instances sorted by their primary keys for the duplicate OffsetIdx key.
	 *
	 *	@param	argTZHourOffset	The ISOTZone key attribute of the instance generating the id.
	 *
	 *	@param	argTZMinOffset	The ISOTZone key attribute of the instance generating the id.
	 *
	 *	@return	List of CFSecISOTZoneObj cached instances sorted by their primary keys for the duplicate OffsetIdx key,
	 *		which may be an empty set.
	 */
	List<ICFSecISOTZoneObj> readISOTZoneByOffsetIdx( short TZHourOffset,
		short TZMinOffset );

	/**
	 *	Get the map of CFSecISOTZoneObj instances sorted by their primary keys for the duplicate OffsetIdx key.
	 *
	 *	@param	argTZHourOffset	The ISOTZone key attribute of the instance generating the id.
	 *
	 *	@param	argTZMinOffset	The ISOTZone key attribute of the instance generating the id.
	 *
	 *	@return	List of CFSecISOTZoneObj cached instances sorted by their primary keys for the duplicate OffsetIdx key,
	 *		which may be an empty set.
	 */
	List<ICFSecISOTZoneObj> readISOTZoneByOffsetIdx( short TZHourOffset,
		short TZMinOffset,
		boolean forceRead );

	/**
	 *	Get the CFSecISOTZoneObj instance for the unique UTZNameIdx key.
	 *
	 *	@param	argTZName	The ISOTZone key attribute of the instance generating the id.
	 *
	 *	@return	CFSecISOTZoneObj cached instance for the unique UTZNameIdx key, or
	 *		null if no such instance exists.
	 */
	ICFSecISOTZoneObj readISOTZoneByUTZNameIdx(String TZName );

	/**
	 *	Get the CFSecISOTZoneObj instance for the unique UTZNameIdx key.
	 *
	 *	@param	argTZName	The ISOTZone key attribute of the instance generating the id.
	 *
	 *	@return	CFSecISOTZoneObj refreshed instance for the unique UTZNameIdx key, or
	 *		null if no such instance exists.
	 */
	ICFSecISOTZoneObj readISOTZoneByUTZNameIdx(String TZName,
		boolean forceRead );

	/**
	 *	Get the map of CFSecISOTZoneObj instances sorted by their primary keys for the duplicate Iso8601Idx key.
	 *
	 *	@param	argIso8601	The ISOTZone key attribute of the instance generating the id.
	 *
	 *	@return	List of CFSecISOTZoneObj cached instances sorted by their primary keys for the duplicate Iso8601Idx key,
	 *		which may be an empty set.
	 */
	List<ICFSecISOTZoneObj> readISOTZoneByIso8601Idx( String Iso8601 );

	/**
	 *	Get the map of CFSecISOTZoneObj instances sorted by their primary keys for the duplicate Iso8601Idx key.
	 *
	 *	@param	argIso8601	The ISOTZone key attribute of the instance generating the id.
	 *
	 *	@return	List of CFSecISOTZoneObj cached instances sorted by their primary keys for the duplicate Iso8601Idx key,
	 *		which may be an empty set.
	 */
	List<ICFSecISOTZoneObj> readISOTZoneByIso8601Idx( String Iso8601,
		boolean forceRead );

	ICFSecISOTZoneObj readCachedISOTZoneByIdIdx( short ISOTZoneId );

	List<ICFSecISOTZoneObj> readCachedISOTZoneByOffsetIdx( short TZHourOffset,
		short TZMinOffset );

	ICFSecISOTZoneObj readCachedISOTZoneByUTZNameIdx( String TZName );

	List<ICFSecISOTZoneObj> readCachedISOTZoneByIso8601Idx( String Iso8601 );

	void deepDisposeISOTZoneByIdIdx( short ISOTZoneId );

	void deepDisposeISOTZoneByOffsetIdx( short TZHourOffset,
		short TZMinOffset );

	void deepDisposeISOTZoneByUTZNameIdx( String TZName );

	void deepDisposeISOTZoneByIso8601Idx( String Iso8601 );

	/**
	 *	Internal use only.
	 */
	ICFSecISOTZoneObj updateISOTZone( ICFSecISOTZoneObj Obj );

	/**
	 *	Internal use only.
	 */
	void deleteISOTZone( ICFSecISOTZoneObj Obj );

	/**
	 *	Internal use only.
	 *
	 *	@param	argISOTZoneId	The ISOTZone key attribute of the instance generating the id.
	 */
	void deleteISOTZoneByIdIdx( short ISOTZoneId );

	/**
	 *	Internal use only.
	 *
	 *	@param	argTZHourOffset	The ISOTZone key attribute of the instance generating the id.
	 *
	 *	@param	argTZMinOffset	The ISOTZone key attribute of the instance generating the id.
	 */
	void deleteISOTZoneByOffsetIdx( short TZHourOffset,
		short TZMinOffset );

	/**
	 *	Internal use only.
	 *
	 *	@param	argTZName	The ISOTZone key attribute of the instance generating the id.
	 */
	void deleteISOTZoneByUTZNameIdx(String TZName );

	/**
	 *	Internal use only.
	 *
	 *	@param	argIso8601	The ISOTZone key attribute of the instance generating the id.
	 */
	void deleteISOTZoneByIso8601Idx( String Iso8601 );
}
