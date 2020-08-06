
// Description: Java 11 DbIO interface for ISOTZone.

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
 *	CFSecISOTZoneTable database interface for ISOTZone
 */
public interface ICFSecISOTZoneTable
{

	/**
	 *	Create the instance in the database, and update the specified buffer
	 *	with the assigned primary key.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	Buff	The buffer to be created.
	 */
	void createISOTZone( CFSecAuthorization Authorization,
		CFSecISOTZoneBuff Buff );


	/**
	 *	Update the instance in the database, and update the specified buffer
	 *	with any calculated changes imposed by the associated stored procedure.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	Buff	The buffer to be updated.
	 */
	void updateISOTZone( CFSecAuthorization Authorization,
		CFSecISOTZoneBuff Buff );


	/**
	 *	Delete the instance from the database.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	Buff	The buffer to be deleted.
	 */
	void deleteISOTZone( CFSecAuthorization Authorization,
		CFSecISOTZoneBuff Buff );
	/**
	 *	Delete the ISOTZone instance identified by the primary key attributes.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argISOTZoneId	The ISOTZone key attribute of the instance generating the id.
	 */
	void deleteISOTZoneByIdIdx( CFSecAuthorization Authorization,
		short argISOTZoneId );

	/**
	 *	Delete the ISOTZone instance identified by the primary key.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argKey	The primary key identifying the instance to be deleted.
	 */
	void deleteISOTZoneByIdIdx( CFSecAuthorization Authorization,
		CFSecISOTZonePKey argKey );
	/**
	 *	Delete the ISOTZone instances identified by the key OffsetIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argTZHourOffset	The ISOTZone key attribute of the instance generating the id.
	 *
	 *	@param	argTZMinOffset	The ISOTZone key attribute of the instance generating the id.
	 */
	void deleteISOTZoneByOffsetIdx( CFSecAuthorization Authorization,
		short argTZHourOffset,
		short argTZMinOffset );

	/**
	 *	Delete the ISOTZone instances identified by the key OffsetIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argKey	The key identifying the instances to be deleted.
	 */
	void deleteISOTZoneByOffsetIdx( CFSecAuthorization Authorization,
		CFSecISOTZoneByOffsetIdxKey argKey );
	/**
	 *	Delete the ISOTZone instances identified by the key UTZNameIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argTZName	The ISOTZone key attribute of the instance generating the id.
	 */
	void deleteISOTZoneByUTZNameIdx( CFSecAuthorization Authorization,
		String argTZName );

	/**
	 *	Delete the ISOTZone instances identified by the key UTZNameIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argKey	The key identifying the instances to be deleted.
	 */
	void deleteISOTZoneByUTZNameIdx( CFSecAuthorization Authorization,
		CFSecISOTZoneByUTZNameIdxKey argKey );
	/**
	 *	Delete the ISOTZone instances identified by the key Iso8601Idx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argIso8601	The ISOTZone key attribute of the instance generating the id.
	 */
	void deleteISOTZoneByIso8601Idx( CFSecAuthorization Authorization,
		String argIso8601 );

	/**
	 *	Delete the ISOTZone instances identified by the key Iso8601Idx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argKey	The key identifying the instances to be deleted.
	 */
	void deleteISOTZoneByIso8601Idx( CFSecAuthorization Authorization,
		CFSecISOTZoneByIso8601IdxKey argKey );


	/**
	 *	Read the derived ISOTZone buffer instance by primary key.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	PKey	The primary key of the ISOTZone instance to be read.
	 *
	 *	@return The buffer instance for the specified primary key, or null if there is
	 *		no such existing key value.
	 */
	CFSecISOTZoneBuff readDerived( CFSecAuthorization Authorization,
		CFSecISOTZonePKey PKey );

	/**
	 *	Lock the derived ISOTZone buffer instance by primary key.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	PKey	The primary key of the ISOTZone instance to be locked.
	 *
	 *	@return The buffer instance for the specified primary key, or null if there is
	 *		no such existing key value.
	 */
	CFSecISOTZoneBuff lockDerived( CFSecAuthorization Authorization,
		CFSecISOTZonePKey PKey );

	/**
	 *	Read all ISOTZone instances.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@return An array of derived buffer instances, potentially with 0 elements in the set.
	 */
	CFSecISOTZoneBuff[] readAllDerived( CFSecAuthorization Authorization );

	/**
	 *	Read the derived ISOTZone buffer instance identified by the unique key IdIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argISOTZoneId	The ISOTZone key attribute of the instance generating the id.
	 *
	 *	@return The buffer instance for the specified key, or null if there is
	 *		no such existing key value.
	 */
	CFSecISOTZoneBuff readDerivedByIdIdx( CFSecAuthorization Authorization,
		short ISOTZoneId );

	/**
	 *	Read an array of the derived ISOTZone buffer instances identified by the duplicate key OffsetIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argTZHourOffset	The ISOTZone key attribute of the instance generating the id.
	 *
	 *	@param	argTZMinOffset	The ISOTZone key attribute of the instance generating the id.
	 *
	 *	@return An array of derived buffer instances for the specified key, potentially with 0 elements in the set.
	 */
	CFSecISOTZoneBuff[] readDerivedByOffsetIdx( CFSecAuthorization Authorization,
		short TZHourOffset,
		short TZMinOffset );

	/**
	 *	Read the derived ISOTZone buffer instance identified by the unique key UTZNameIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argTZName	The ISOTZone key attribute of the instance generating the id.
	 *
	 *	@return The buffer instance for the specified key, or null if there is
	 *		no such existing key value.
	 */
	CFSecISOTZoneBuff readDerivedByUTZNameIdx( CFSecAuthorization Authorization,
		String TZName );

	/**
	 *	Read an array of the derived ISOTZone buffer instances identified by the duplicate key Iso8601Idx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argIso8601	The ISOTZone key attribute of the instance generating the id.
	 *
	 *	@return An array of derived buffer instances for the specified key, potentially with 0 elements in the set.
	 */
	CFSecISOTZoneBuff[] readDerivedByIso8601Idx( CFSecAuthorization Authorization,
		String Iso8601 );

	/**
	 *	Read the specific ISOTZone buffer instance identified by the primary key.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	PKey	The primary key of the ISOTZone instance to be locked.
	 *
	 *	@return The buffer instance for the specified primary key, or null if there is
	 *		no such existing key value.
	 *
	 *	@throws	CFLibNotSupportedException thrown by client-side implementations.
	 */
	CFSecISOTZoneBuff readBuff( CFSecAuthorization Authorization,
		CFSecISOTZonePKey PKey );

	/**
	 *	Lock the specific ISOTZone buffer instance identified by the primary key.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	PKey	The primary key of the ISOTZone instance to be locked.
	 *
	 *	@return The buffer instance for the specified primary key, or null if there is
	 *		no such existing key value.
	 *
	 *	@throws	CFLibNotSupportedException thrown by client-side implementations.
	 */
	CFSecISOTZoneBuff lockBuff( CFSecAuthorization Authorization,
		CFSecISOTZonePKey PKey );

	/**
	 *	Read all the specific ISOTZone buffer instances.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@return All the specific ISOTZone instances in the database accessible for the Authorization.
	 */
	CFSecISOTZoneBuff[] readAllBuff( CFSecAuthorization Authorization );

	/**
	 *	Read the specific ISOTZone buffer instance identified by the unique key IdIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argISOTZoneId	The ISOTZone key attribute of the instance generating the id.
	 *
	 *	@return The buffer instance for the specified key, or null if there is
	 *		no such existing key value.
	 *
	 *	@throws	CFLibNotSupportedException thrown by client-side implementations.
	 */
	CFSecISOTZoneBuff readBuffByIdIdx( CFSecAuthorization Authorization,
		short ISOTZoneId );

	/**
	 *	Read an array of the specific ISOTZone buffer instances identified by the duplicate key OffsetIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argTZHourOffset	The ISOTZone key attribute of the instance generating the id.
	 *
	 *	@param	argTZMinOffset	The ISOTZone key attribute of the instance generating the id.
	 *
	 *	@return An array of derived buffer instances for the specified key, potentially with 0 elements in the set.
	 *
	 *	@throws	CFLibNotSupportedException thrown by client-side implementations.
	 */
	CFSecISOTZoneBuff[] readBuffByOffsetIdx( CFSecAuthorization Authorization,
		short TZHourOffset,
		short TZMinOffset );

	/**
	 *	Read the specific ISOTZone buffer instance identified by the unique key UTZNameIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argTZName	The ISOTZone key attribute of the instance generating the id.
	 *
	 *	@return The buffer instance for the specified key, or null if there is
	 *		no such existing key value.
	 *
	 *	@throws	CFLibNotSupportedException thrown by client-side implementations.
	 */
	CFSecISOTZoneBuff readBuffByUTZNameIdx( CFSecAuthorization Authorization,
		String TZName );

	/**
	 *	Read an array of the specific ISOTZone buffer instances identified by the duplicate key Iso8601Idx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argIso8601	The ISOTZone key attribute of the instance generating the id.
	 *
	 *	@return An array of derived buffer instances for the specified key, potentially with 0 elements in the set.
	 *
	 *	@throws	CFLibNotSupportedException thrown by client-side implementations.
	 */
	CFSecISOTZoneBuff[] readBuffByIso8601Idx( CFSecAuthorization Authorization,
		String Iso8601 );

	/**
	 *	Release any prepared statements allocated by this instance.
	 *
	 *	@throws CFLibNotSupportedException thrown by client-side implementations.
	 */
	void releasePreparedStatements();
}
