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

public interface ICFSecISOLangTableObj
{
	ICFSecSchemaObj getSchema();
	void setSchema( ICFSecSchemaObj value );

	void minimizeMemory();

	String getTableName();
	String getTableDbName();

	Class getObjQualifyingClass();

	/**
	 *	Instantiate a new ISOLang instance.
	 *
	 *	@return	A new instance.
	 */
	ICFSecISOLangObj newInstance();

	/**
	 *	Instantiate a new ISOLang edition of the specified ISOLang instance.
	 *
	 *	@return	A new edition.
	 */
	ICFSecISOLangEditObj newEditInstance( ICFSecISOLangObj orig );

	/**
	 *	Internal use only.
	 */
	ICFSecISOLangObj realiseISOLang( ICFSecISOLangObj Obj );

	/**
	 *	Internal use only.
	 */
	ICFSecISOLangObj createISOLang( ICFSecISOLangObj Obj );

	/**
	 *	Read a ISOLang-derived instance by it's primary key.
	 *
	 *	@param	pkey	The primary key identifying the instance to read.
	 *
	 *	@return	The ISOLang-derived instance identified by the primary key,
	 *		or null if no such key value exists.
	 */
	ICFSecISOLangObj readISOLang( CFSecISOLangPKey pkey );

	/**
	 *	Read a ISOLang-derived instance by it's primary key.
	 *
	 *	@param	pkey	The primary key identifying the instance to read.
	 *
	 *	@return	The ISOLang-derived instance identified by the primary key,
	 *		or null if no such key value exists.
	 */
	ICFSecISOLangObj readISOLang( CFSecISOLangPKey pkey,
		boolean forceRead );

	ICFSecISOLangObj readCachedISOLang( CFSecISOLangPKey pkey );

	public void reallyDeepDisposeISOLang( ICFSecISOLangObj obj );

	void deepDisposeISOLang( CFSecISOLangPKey pkey );

	/**
	 *	Internal use only.
	 */
	ICFSecISOLangObj lockISOLang( CFSecISOLangPKey pkey );

	/**
	 *	Return a sorted list of all the ISOLang-derived instances in the database.
	 *
	 *	@return	List of ICFSecISOLangObj instance, sorted by their primary keys, which
	 *		may include an empty set.
	 */
	List<ICFSecISOLangObj> readAllISOLang();

	/**
	 *	Return a sorted map of all the ISOLang-derived instances in the database.
	 *
	 *	@return	List of ICFSecISOLangObj instance, sorted by their primary keys, which
	 *		may include an empty set.
	 */
	List<ICFSecISOLangObj> readAllISOLang( boolean forceRead );

	List<ICFSecISOLangObj> readCachedAllISOLang();

	/**
	 *	Get the CFSecISOLangObj instance for the primary key attributes.
	 *
	 *	@param	argISOLangId	The ISOLang key attribute of the instance generating the id.
	 *
	 *	@return	CFSecISOLangObj cached instance for the primary key, or
	 *		null if no such instance exists.
	 */
	ICFSecISOLangObj readISOLangByIdIdx( short ISOLangId );

	/**
	 *	Get the CFSecISOLangObj instance for the primary key attributes.
	 *
	 *	@param	argISOLangId	The ISOLang key attribute of the instance generating the id.
	 *
	 *	@return	CFSecISOLangObj refreshed instance for the primary key, or
	 *		null if no such instance exists.
	 */
	ICFSecISOLangObj readISOLangByIdIdx( short ISOLangId,
		boolean forceRead );

	/**
	 *	Get the CFSecISOLangObj instance for the unique Code3Idx key.
	 *
	 *	@param	argISO6392Code	The ISOLang key attribute of the instance generating the id.
	 *
	 *	@return	CFSecISOLangObj cached instance for the unique Code3Idx key, or
	 *		null if no such instance exists.
	 */
	ICFSecISOLangObj readISOLangByCode3Idx(String ISO6392Code );

	/**
	 *	Get the CFSecISOLangObj instance for the unique Code3Idx key.
	 *
	 *	@param	argISO6392Code	The ISOLang key attribute of the instance generating the id.
	 *
	 *	@return	CFSecISOLangObj refreshed instance for the unique Code3Idx key, or
	 *		null if no such instance exists.
	 */
	ICFSecISOLangObj readISOLangByCode3Idx(String ISO6392Code,
		boolean forceRead );

	/**
	 *	Get the map of CFSecISOLangObj instances sorted by their primary keys for the duplicate Code2Idx key.
	 *
	 *	@param	argISO6391Code	The ISOLang key attribute of the instance generating the id.
	 *
	 *	@return	List of CFSecISOLangObj cached instances sorted by their primary keys for the duplicate Code2Idx key,
	 *		which may be an empty set.
	 */
	List<ICFSecISOLangObj> readISOLangByCode2Idx( String ISO6391Code );

	/**
	 *	Get the map of CFSecISOLangObj instances sorted by their primary keys for the duplicate Code2Idx key.
	 *
	 *	@param	argISO6391Code	The ISOLang key attribute of the instance generating the id.
	 *
	 *	@return	List of CFSecISOLangObj cached instances sorted by their primary keys for the duplicate Code2Idx key,
	 *		which may be an empty set.
	 */
	List<ICFSecISOLangObj> readISOLangByCode2Idx( String ISO6391Code,
		boolean forceRead );

	ICFSecISOLangObj readCachedISOLangByIdIdx( short ISOLangId );

	ICFSecISOLangObj readCachedISOLangByCode3Idx( String ISO6392Code );

	List<ICFSecISOLangObj> readCachedISOLangByCode2Idx( String ISO6391Code );

	void deepDisposeISOLangByIdIdx( short ISOLangId );

	void deepDisposeISOLangByCode3Idx( String ISO6392Code );

	void deepDisposeISOLangByCode2Idx( String ISO6391Code );

	/**
	 *	Internal use only.
	 */
	ICFSecISOLangObj updateISOLang( ICFSecISOLangObj Obj );

	/**
	 *	Internal use only.
	 */
	void deleteISOLang( ICFSecISOLangObj Obj );

	/**
	 *	Internal use only.
	 *
	 *	@param	argISOLangId	The ISOLang key attribute of the instance generating the id.
	 */
	void deleteISOLangByIdIdx( short ISOLangId );

	/**
	 *	Internal use only.
	 *
	 *	@param	argISO6392Code	The ISOLang key attribute of the instance generating the id.
	 */
	void deleteISOLangByCode3Idx(String ISO6392Code );

	/**
	 *	Internal use only.
	 *
	 *	@param	argISO6391Code	The ISOLang key attribute of the instance generating the id.
	 */
	void deleteISOLangByCode2Idx( String ISO6391Code );
}
