
// Description: Java 11 Factory interface for ISOTZone.

/*
 *	org.msscf.msscf.CFSec
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFSec 2.13 Security Essentials
 *	
 *	Copyright 2020 Mark Stephen Sobkow msobkow@sasktel.net
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

package org.msscf.msscf.v2_13.cfsec.CFSec;

import java.lang.reflect.*;
import java.net.*;
import java.rmi.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.msscf.msscf.v2_13.cflib.CFLib.*;

/*
 *	CFSecISOTZoneFactory interface for ISOTZone
 */
public interface ICFSecISOTZoneFactory
{

	/**
	 *	Allocate a primary key for ISOTZone instances.
	 *
	 *	@return	The new instance.
	 */
	CFSecISOTZonePKey newPKey();

	/**
	 *	Allocate a primary history key for ISOTZone instances.
	 *
	 *	@return	The new instance.
	 */
	CFSecISOTZoneHPKey newHPKey();

	/**
	 *	Allocate a OffsetIdx key over ISOTZone instances.
	 *
	 *	@return	The new instance.
	 */
	CFSecISOTZoneByOffsetIdxKey newOffsetIdxKey();

	/**
	 *	Allocate a UTZNameIdx key over ISOTZone instances.
	 *
	 *	@return	The new instance.
	 */
	CFSecISOTZoneByUTZNameIdxKey newUTZNameIdxKey();

	/**
	 *	Allocate a Iso8601Idx key over ISOTZone instances.
	 *
	 *	@return	The new instance.
	 */
	CFSecISOTZoneByIso8601IdxKey newIso8601IdxKey();

	/**
	 *	Allocate a ISOTZone instance buffer.
	 *
	 *	@return	The new instance.
	 */
	CFSecISOTZoneBuff newBuff();

	/**
	 *	Allocate a ISOTZone history instance buffer.
	 *
	 *	@return	The new instance.
	 */
	CFSecISOTZoneHBuff newHBuff();

}
