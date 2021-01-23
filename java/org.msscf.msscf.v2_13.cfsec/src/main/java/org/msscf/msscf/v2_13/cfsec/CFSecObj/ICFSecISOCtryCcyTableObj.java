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

public interface ICFSecISOCtryCcyTableObj
{
	ICFSecSchemaObj getSchema();
	void setSchema( ICFSecSchemaObj value );

	void minimizeMemory();

	String getTableName();
	String getTableDbName();

	Class getObjQualifyingClass();

	/**
	 *	Instantiate a new ISOCtryCcy instance.
	 *
	 *	@return	A new instance.
	 */
	ICFSecISOCtryCcyObj newInstance();

	/**
	 *	Instantiate a new ISOCtryCcy edition of the specified ISOCtryCcy instance.
	 *
	 *	@return	A new edition.
	 */
	ICFSecISOCtryCcyEditObj newEditInstance( ICFSecISOCtryCcyObj orig );

	/**
	 *	Internal use only.
	 */
	ICFSecISOCtryCcyObj realiseISOCtryCcy( ICFSecISOCtryCcyObj Obj );

	/**
	 *	Internal use only.
	 */
	ICFSecISOCtryCcyObj createISOCtryCcy( ICFSecISOCtryCcyObj Obj );

	/**
	 *	Read a ISOCtryCcy-derived instance by it's primary key.
	 *
	 *	@param	pkey	The primary key identifying the instance to read.
	 *
	 *	@return	The ISOCtryCcy-derived instance identified by the primary key,
	 *		or null if no such key value exists.
	 */
	ICFSecISOCtryCcyObj readISOCtryCcy( CFSecISOCtryCcyPKey pkey );

	/**
	 *	Read a ISOCtryCcy-derived instance by it's primary key.
	 *
	 *	@param	pkey	The primary key identifying the instance to read.
	 *
	 *	@return	The ISOCtryCcy-derived instance identified by the primary key,
	 *		or null if no such key value exists.
	 */
	ICFSecISOCtryCcyObj readISOCtryCcy( CFSecISOCtryCcyPKey pkey,
		boolean forceRead );

	ICFSecISOCtryCcyObj readCachedISOCtryCcy( CFSecISOCtryCcyPKey pkey );

	public void reallyDeepDisposeISOCtryCcy( ICFSecISOCtryCcyObj obj );

	void deepDisposeISOCtryCcy( CFSecISOCtryCcyPKey pkey );

	/**
	 *	Internal use only.
	 */
	ICFSecISOCtryCcyObj lockISOCtryCcy( CFSecISOCtryCcyPKey pkey );

	/**
	 *	Return a sorted list of all the ISOCtryCcy-derived instances in the database.
	 *
	 *	@return	List of ICFSecISOCtryCcyObj instance, sorted by their primary keys, which
	 *		may include an empty set.
	 */
	List<ICFSecISOCtryCcyObj> readAllISOCtryCcy();

	/**
	 *	Return a sorted map of all the ISOCtryCcy-derived instances in the database.
	 *
	 *	@return	List of ICFSecISOCtryCcyObj instance, sorted by their primary keys, which
	 *		may include an empty set.
	 */
	List<ICFSecISOCtryCcyObj> readAllISOCtryCcy( boolean forceRead );

	List<ICFSecISOCtryCcyObj> readCachedAllISOCtryCcy();

	/**
	 *	Get the CFSecISOCtryCcyObj instance for the primary key attributes.
	 *
	 *	@param	argISOCtryId	The ISOCtryCcy key attribute of the instance generating the id.
	 *
	 *	@param	argISOCcyId	The ISOCtryCcy key attribute of the instance generating the id.
	 *
	 *	@return	CFSecISOCtryCcyObj cached instance for the primary key, or
	 *		null if no such instance exists.
	 */
	ICFSecISOCtryCcyObj readISOCtryCcyByIdIdx( short ISOCtryId,
		short ISOCcyId );

	/**
	 *	Get the CFSecISOCtryCcyObj instance for the primary key attributes.
	 *
	 *	@param	argISOCtryId	The ISOCtryCcy key attribute of the instance generating the id.
	 *
	 *	@param	argISOCcyId	The ISOCtryCcy key attribute of the instance generating the id.
	 *
	 *	@return	CFSecISOCtryCcyObj refreshed instance for the primary key, or
	 *		null if no such instance exists.
	 */
	ICFSecISOCtryCcyObj readISOCtryCcyByIdIdx( short ISOCtryId,
		short ISOCcyId,
		boolean forceRead );

	/**
	 *	Get the map of CFSecISOCtryCcyObj instances sorted by their primary keys for the duplicate CtryIdx key.
	 *
	 *	@param	argISOCtryId	The ISOCtryCcy key attribute of the instance generating the id.
	 *
	 *	@return	List of CFSecISOCtryCcyObj cached instances sorted by their primary keys for the duplicate CtryIdx key,
	 *		which may be an empty set.
	 */
	List<ICFSecISOCtryCcyObj> readISOCtryCcyByCtryIdx( short ISOCtryId );

	/**
	 *	Get the map of CFSecISOCtryCcyObj instances sorted by their primary keys for the duplicate CtryIdx key.
	 *
	 *	@param	argISOCtryId	The ISOCtryCcy key attribute of the instance generating the id.
	 *
	 *	@return	List of CFSecISOCtryCcyObj cached instances sorted by their primary keys for the duplicate CtryIdx key,
	 *		which may be an empty set.
	 */
	List<ICFSecISOCtryCcyObj> readISOCtryCcyByCtryIdx( short ISOCtryId,
		boolean forceRead );

	/**
	 *	Get the map of CFSecISOCtryCcyObj instances sorted by their primary keys for the duplicate CcyIdx key.
	 *
	 *	@param	argISOCcyId	The ISOCtryCcy key attribute of the instance generating the id.
	 *
	 *	@return	List of CFSecISOCtryCcyObj cached instances sorted by their primary keys for the duplicate CcyIdx key,
	 *		which may be an empty set.
	 */
	List<ICFSecISOCtryCcyObj> readISOCtryCcyByCcyIdx( short ISOCcyId );

	/**
	 *	Get the map of CFSecISOCtryCcyObj instances sorted by their primary keys for the duplicate CcyIdx key.
	 *
	 *	@param	argISOCcyId	The ISOCtryCcy key attribute of the instance generating the id.
	 *
	 *	@return	List of CFSecISOCtryCcyObj cached instances sorted by their primary keys for the duplicate CcyIdx key,
	 *		which may be an empty set.
	 */
	List<ICFSecISOCtryCcyObj> readISOCtryCcyByCcyIdx( short ISOCcyId,
		boolean forceRead );

	ICFSecISOCtryCcyObj readCachedISOCtryCcyByIdIdx( short ISOCtryId,
		short ISOCcyId );

	List<ICFSecISOCtryCcyObj> readCachedISOCtryCcyByCtryIdx( short ISOCtryId );

	List<ICFSecISOCtryCcyObj> readCachedISOCtryCcyByCcyIdx( short ISOCcyId );

	void deepDisposeISOCtryCcyByIdIdx( short ISOCtryId,
		short ISOCcyId );

	void deepDisposeISOCtryCcyByCtryIdx( short ISOCtryId );

	void deepDisposeISOCtryCcyByCcyIdx( short ISOCcyId );

	/**
	 *	Internal use only.
	 */
	ICFSecISOCtryCcyObj updateISOCtryCcy( ICFSecISOCtryCcyObj Obj );

	/**
	 *	Internal use only.
	 */
	void deleteISOCtryCcy( ICFSecISOCtryCcyObj Obj );

	/**
	 *	Internal use only.
	 *
	 *	@param	argISOCtryId	The ISOCtryCcy key attribute of the instance generating the id.
	 *
	 *	@param	argISOCcyId	The ISOCtryCcy key attribute of the instance generating the id.
	 */
	void deleteISOCtryCcyByIdIdx( short ISOCtryId,
		short ISOCcyId );

	/**
	 *	Internal use only.
	 *
	 *	@param	argISOCtryId	The ISOCtryCcy key attribute of the instance generating the id.
	 */
	void deleteISOCtryCcyByCtryIdx( short ISOCtryId );

	/**
	 *	Internal use only.
	 *
	 *	@param	argISOCcyId	The ISOCtryCcy key attribute of the instance generating the id.
	 */
	void deleteISOCtryCcyByCcyIdx( short ISOCcyId );
}
