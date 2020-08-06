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
