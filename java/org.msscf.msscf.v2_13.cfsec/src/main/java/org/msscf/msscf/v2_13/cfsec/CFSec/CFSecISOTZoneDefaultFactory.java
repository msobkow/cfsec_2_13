
// Description: Java 11 Default Factory implementation for ISOTZone.

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
	 *	CFSecISOTZoneFactory implementation for ISOTZone
	 */
public class CFSecISOTZoneDefaultFactory
	implements ICFSecISOTZoneFactory
{
	public CFSecISOTZoneDefaultFactory() {
	}

	public CFSecISOTZonePKey newPKey() {
		CFSecISOTZonePKey pkey =
			new CFSecISOTZonePKey();
		return( pkey );
	}

	public CFSecISOTZoneHPKey newHPKey() {
		CFSecISOTZoneHPKey hpkey =
			new CFSecISOTZoneHPKey();
		return( hpkey );
	}

	public CFSecISOTZoneByOffsetIdxKey newOffsetIdxKey() {
		CFSecISOTZoneByOffsetIdxKey key =
			new CFSecISOTZoneByOffsetIdxKey();
		return( key );
	}

	public CFSecISOTZoneByUTZNameIdxKey newUTZNameIdxKey() {
		CFSecISOTZoneByUTZNameIdxKey key =
			new CFSecISOTZoneByUTZNameIdxKey();
		return( key );
	}

	public CFSecISOTZoneByIso8601IdxKey newIso8601IdxKey() {
		CFSecISOTZoneByIso8601IdxKey key =
			new CFSecISOTZoneByIso8601IdxKey();
		return( key );
	}

	public CFSecISOTZoneBuff newBuff() {
		CFSecISOTZoneBuff buff =
			new CFSecISOTZoneBuff();
		return( buff );
	}

	public CFSecISOTZoneHBuff newHBuff() {
		CFSecISOTZoneHBuff hbuff =
			new CFSecISOTZoneHBuff();
		return( hbuff );
	}
}
