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
