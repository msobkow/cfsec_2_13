
// Description: Java 11 DbIO interface for ISOCtryCcy.

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

package org.msscf.msscf.cfsec.CFSec;

import java.lang.reflect.*;
import java.net.*;
import java.rmi.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.msscf.msscf.cflib.CFLib.*;
import org.msscf.msscf.cfsec.CFSecObj.*;

/*
 *	CFSecISOCtryCcyTable database interface for ISOCtryCcy
 */
public interface ICFSecISOCtryCcyTable
{

	/**
	 *	Create the instance in the database, and update the specified buffer
	 *	with the assigned primary key.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	Buff	The buffer to be created.
	 */
	void createISOCtryCcy( CFSecAuthorization Authorization,
		CFSecISOCtryCcyBuff Buff );


	/**
	 *	Update the instance in the database, and update the specified buffer
	 *	with any calculated changes imposed by the associated stored procedure.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	Buff	The buffer to be updated.
	 */
	void updateISOCtryCcy( CFSecAuthorization Authorization,
		CFSecISOCtryCcyBuff Buff );


	/**
	 *	Delete the instance from the database.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	Buff	The buffer to be deleted.
	 */
	void deleteISOCtryCcy( CFSecAuthorization Authorization,
		CFSecISOCtryCcyBuff Buff );
	/**
	 *	Delete the ISOCtryCcy instance identified by the primary key attributes.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argISOCtryId	The ISOCtryCcy key attribute of the instance generating the id.
	 *
	 *	@param	argISOCcyId	The ISOCtryCcy key attribute of the instance generating the id.
	 */
	void deleteISOCtryCcyByIdIdx( CFSecAuthorization Authorization,
		short argISOCtryId,
		short argISOCcyId );

	/**
	 *	Delete the ISOCtryCcy instance identified by the primary key.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argKey	The primary key identifying the instance to be deleted.
	 */
	void deleteISOCtryCcyByIdIdx( CFSecAuthorization Authorization,
		CFSecISOCtryCcyPKey argKey );
	/**
	 *	Delete the ISOCtryCcy instances identified by the key CtryIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argISOCtryId	The ISOCtryCcy key attribute of the instance generating the id.
	 */
	void deleteISOCtryCcyByCtryIdx( CFSecAuthorization Authorization,
		short argISOCtryId );

	/**
	 *	Delete the ISOCtryCcy instances identified by the key CtryIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argKey	The key identifying the instances to be deleted.
	 */
	void deleteISOCtryCcyByCtryIdx( CFSecAuthorization Authorization,
		CFSecISOCtryCcyByCtryIdxKey argKey );
	/**
	 *	Delete the ISOCtryCcy instances identified by the key CcyIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argISOCcyId	The ISOCtryCcy key attribute of the instance generating the id.
	 */
	void deleteISOCtryCcyByCcyIdx( CFSecAuthorization Authorization,
		short argISOCcyId );

	/**
	 *	Delete the ISOCtryCcy instances identified by the key CcyIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argKey	The key identifying the instances to be deleted.
	 */
	void deleteISOCtryCcyByCcyIdx( CFSecAuthorization Authorization,
		CFSecISOCtryCcyByCcyIdxKey argKey );


	/**
	 *	Read the derived ISOCtryCcy buffer instance by primary key.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	PKey	The primary key of the ISOCtryCcy instance to be read.
	 *
	 *	@return The buffer instance for the specified primary key, or null if there is
	 *		no such existing key value.
	 */
	CFSecISOCtryCcyBuff readDerived( CFSecAuthorization Authorization,
		CFSecISOCtryCcyPKey PKey );

	/**
	 *	Lock the derived ISOCtryCcy buffer instance by primary key.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	PKey	The primary key of the ISOCtryCcy instance to be locked.
	 *
	 *	@return The buffer instance for the specified primary key, or null if there is
	 *		no such existing key value.
	 */
	CFSecISOCtryCcyBuff lockDerived( CFSecAuthorization Authorization,
		CFSecISOCtryCcyPKey PKey );

	/**
	 *	Read all ISOCtryCcy instances.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@return An array of derived buffer instances, potentially with 0 elements in the set.
	 */
	CFSecISOCtryCcyBuff[] readAllDerived( CFSecAuthorization Authorization );

	/**
	 *	Read the derived ISOCtryCcy buffer instance identified by the unique key IdIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argISOCtryId	The ISOCtryCcy key attribute of the instance generating the id.
	 *
	 *	@param	argISOCcyId	The ISOCtryCcy key attribute of the instance generating the id.
	 *
	 *	@return The buffer instance for the specified key, or null if there is
	 *		no such existing key value.
	 */
	CFSecISOCtryCcyBuff readDerivedByIdIdx( CFSecAuthorization Authorization,
		short ISOCtryId,
		short ISOCcyId );

	/**
	 *	Read an array of the derived ISOCtryCcy buffer instances identified by the duplicate key CtryIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argISOCtryId	The ISOCtryCcy key attribute of the instance generating the id.
	 *
	 *	@return An array of derived buffer instances for the specified key, potentially with 0 elements in the set.
	 */
	CFSecISOCtryCcyBuff[] readDerivedByCtryIdx( CFSecAuthorization Authorization,
		short ISOCtryId );

	/**
	 *	Read an array of the derived ISOCtryCcy buffer instances identified by the duplicate key CcyIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argISOCcyId	The ISOCtryCcy key attribute of the instance generating the id.
	 *
	 *	@return An array of derived buffer instances for the specified key, potentially with 0 elements in the set.
	 */
	CFSecISOCtryCcyBuff[] readDerivedByCcyIdx( CFSecAuthorization Authorization,
		short ISOCcyId );

	/**
	 *	Read the specific ISOCtryCcy buffer instance identified by the primary key.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	PKey	The primary key of the ISOCtryCcy instance to be locked.
	 *
	 *	@return The buffer instance for the specified primary key, or null if there is
	 *		no such existing key value.
	 *
	 *	@throws	CFLibNotSupportedException thrown by client-side implementations.
	 */
	CFSecISOCtryCcyBuff readBuff( CFSecAuthorization Authorization,
		CFSecISOCtryCcyPKey PKey );

	/**
	 *	Lock the specific ISOCtryCcy buffer instance identified by the primary key.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	PKey	The primary key of the ISOCtryCcy instance to be locked.
	 *
	 *	@return The buffer instance for the specified primary key, or null if there is
	 *		no such existing key value.
	 *
	 *	@throws	CFLibNotSupportedException thrown by client-side implementations.
	 */
	CFSecISOCtryCcyBuff lockBuff( CFSecAuthorization Authorization,
		CFSecISOCtryCcyPKey PKey );

	/**
	 *	Read all the specific ISOCtryCcy buffer instances.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@return All the specific ISOCtryCcy instances in the database accessible for the Authorization.
	 */
	CFSecISOCtryCcyBuff[] readAllBuff( CFSecAuthorization Authorization );

	/**
	 *	Read the specific ISOCtryCcy buffer instance identified by the unique key IdIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argISOCtryId	The ISOCtryCcy key attribute of the instance generating the id.
	 *
	 *	@param	argISOCcyId	The ISOCtryCcy key attribute of the instance generating the id.
	 *
	 *	@return The buffer instance for the specified key, or null if there is
	 *		no such existing key value.
	 *
	 *	@throws	CFLibNotSupportedException thrown by client-side implementations.
	 */
	CFSecISOCtryCcyBuff readBuffByIdIdx( CFSecAuthorization Authorization,
		short ISOCtryId,
		short ISOCcyId );

	/**
	 *	Read an array of the specific ISOCtryCcy buffer instances identified by the duplicate key CtryIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argISOCtryId	The ISOCtryCcy key attribute of the instance generating the id.
	 *
	 *	@return An array of derived buffer instances for the specified key, potentially with 0 elements in the set.
	 *
	 *	@throws	CFLibNotSupportedException thrown by client-side implementations.
	 */
	CFSecISOCtryCcyBuff[] readBuffByCtryIdx( CFSecAuthorization Authorization,
		short ISOCtryId );

	/**
	 *	Read an array of the specific ISOCtryCcy buffer instances identified by the duplicate key CcyIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argISOCcyId	The ISOCtryCcy key attribute of the instance generating the id.
	 *
	 *	@return An array of derived buffer instances for the specified key, potentially with 0 elements in the set.
	 *
	 *	@throws	CFLibNotSupportedException thrown by client-side implementations.
	 */
	CFSecISOCtryCcyBuff[] readBuffByCcyIdx( CFSecAuthorization Authorization,
		short ISOCcyId );

	/**
	 *	Release any prepared statements allocated by this instance.
	 *
	 *	@throws CFLibNotSupportedException thrown by client-side implementations.
	 */
	void releasePreparedStatements();
}
