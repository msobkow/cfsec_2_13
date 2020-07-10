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

public interface ICFSecISOCtryTableObj
{
	ICFSecSchemaObj getSchema();
	void setSchema( ICFSecSchemaObj value );

	void minimizeMemory();

	String getTableName();
	String getTableDbName();

	Class getObjQualifyingClass();

	/**
	 *	Instantiate a new ISOCtry instance.
	 *
	 *	@return	A new instance.
	 */
	ICFSecISOCtryObj newInstance();

	/**
	 *	Instantiate a new ISOCtry edition of the specified ISOCtry instance.
	 *
	 *	@return	A new edition.
	 */
	ICFSecISOCtryEditObj newEditInstance( ICFSecISOCtryObj orig );

	/**
	 *	Internal use only.
	 */
	ICFSecISOCtryObj realiseISOCtry( ICFSecISOCtryObj Obj );

	/**
	 *	Internal use only.
	 */
	ICFSecISOCtryObj createISOCtry( ICFSecISOCtryObj Obj );

	/**
	 *	Read a ISOCtry-derived instance by it's primary key.
	 *
	 *	@param	pkey	The primary key identifying the instance to read.
	 *
	 *	@return	The ISOCtry-derived instance identified by the primary key,
	 *		or null if no such key value exists.
	 */
	ICFSecISOCtryObj readISOCtry( CFSecISOCtryPKey pkey );

	/**
	 *	Read a ISOCtry-derived instance by it's primary key.
	 *
	 *	@param	pkey	The primary key identifying the instance to read.
	 *
	 *	@return	The ISOCtry-derived instance identified by the primary key,
	 *		or null if no such key value exists.
	 */
	ICFSecISOCtryObj readISOCtry( CFSecISOCtryPKey pkey,
		boolean forceRead );

	ICFSecISOCtryObj readCachedISOCtry( CFSecISOCtryPKey pkey );

	public void reallyDeepDisposeISOCtry( ICFSecISOCtryObj obj );

	void deepDisposeISOCtry( CFSecISOCtryPKey pkey );

	/**
	 *	Internal use only.
	 */
	ICFSecISOCtryObj lockISOCtry( CFSecISOCtryPKey pkey );

	/**
	 *	Return a sorted list of all the ISOCtry-derived instances in the database.
	 *
	 *	@return	List of ICFSecISOCtryObj instance, sorted by their primary keys, which
	 *		may include an empty set.
	 */
	List<ICFSecISOCtryObj> readAllISOCtry();

	/**
	 *	Return a sorted map of all the ISOCtry-derived instances in the database.
	 *
	 *	@return	List of ICFSecISOCtryObj instance, sorted by their primary keys, which
	 *		may include an empty set.
	 */
	List<ICFSecISOCtryObj> readAllISOCtry( boolean forceRead );

	List<ICFSecISOCtryObj> readCachedAllISOCtry();

	/**
	 *	Get the CFSecISOCtryObj instance for the primary key attributes.
	 *
	 *	@param	argISOCtryId	The ISOCtry key attribute of the instance generating the id.
	 *
	 *	@return	CFSecISOCtryObj cached instance for the primary key, or
	 *		null if no such instance exists.
	 */
	ICFSecISOCtryObj readISOCtryByIdIdx( short ISOCtryId );

	/**
	 *	Get the CFSecISOCtryObj instance for the primary key attributes.
	 *
	 *	@param	argISOCtryId	The ISOCtry key attribute of the instance generating the id.
	 *
	 *	@return	CFSecISOCtryObj refreshed instance for the primary key, or
	 *		null if no such instance exists.
	 */
	ICFSecISOCtryObj readISOCtryByIdIdx( short ISOCtryId,
		boolean forceRead );

	/**
	 *	Get the CFSecISOCtryObj instance for the unique ISOCodeIdx key.
	 *
	 *	@param	argISOCode	The ISOCtry key attribute of the instance generating the id.
	 *
	 *	@return	CFSecISOCtryObj cached instance for the unique ISOCodeIdx key, or
	 *		null if no such instance exists.
	 */
	ICFSecISOCtryObj readISOCtryByISOCodeIdx(String ISOCode );

	/**
	 *	Get the CFSecISOCtryObj instance for the unique ISOCodeIdx key.
	 *
	 *	@param	argISOCode	The ISOCtry key attribute of the instance generating the id.
	 *
	 *	@return	CFSecISOCtryObj refreshed instance for the unique ISOCodeIdx key, or
	 *		null if no such instance exists.
	 */
	ICFSecISOCtryObj readISOCtryByISOCodeIdx(String ISOCode,
		boolean forceRead );

	/**
	 *	Get the CFSecISOCtryObj instance for the unique NameIdx key.
	 *
	 *	@param	argName	The ISOCtry key attribute of the instance generating the id.
	 *
	 *	@return	CFSecISOCtryObj cached instance for the unique NameIdx key, or
	 *		null if no such instance exists.
	 */
	ICFSecISOCtryObj readISOCtryByNameIdx(String Name );

	/**
	 *	Get the CFSecISOCtryObj instance for the unique NameIdx key.
	 *
	 *	@param	argName	The ISOCtry key attribute of the instance generating the id.
	 *
	 *	@return	CFSecISOCtryObj refreshed instance for the unique NameIdx key, or
	 *		null if no such instance exists.
	 */
	ICFSecISOCtryObj readISOCtryByNameIdx(String Name,
		boolean forceRead );

	ICFSecISOCtryObj readCachedISOCtryByIdIdx( short ISOCtryId );

	ICFSecISOCtryObj readCachedISOCtryByISOCodeIdx( String ISOCode );

	ICFSecISOCtryObj readCachedISOCtryByNameIdx( String Name );

	void deepDisposeISOCtryByIdIdx( short ISOCtryId );

	void deepDisposeISOCtryByISOCodeIdx( String ISOCode );

	void deepDisposeISOCtryByNameIdx( String Name );

	/**
	 *	Internal use only.
	 */
	ICFSecISOCtryObj updateISOCtry( ICFSecISOCtryObj Obj );

	/**
	 *	Internal use only.
	 */
	void deleteISOCtry( ICFSecISOCtryObj Obj );

	/**
	 *	Internal use only.
	 *
	 *	@param	argISOCtryId	The ISOCtry key attribute of the instance generating the id.
	 */
	void deleteISOCtryByIdIdx( short ISOCtryId );

	/**
	 *	Internal use only.
	 *
	 *	@param	argISOCode	The ISOCtry key attribute of the instance generating the id.
	 */
	void deleteISOCtryByISOCodeIdx(String ISOCode );

	/**
	 *	Internal use only.
	 *
	 *	@param	argName	The ISOCtry key attribute of the instance generating the id.
	 */
	void deleteISOCtryByNameIdx(String Name );
}
