
// Description: Java 11 Default Factory implementation for SecDevice.

/*
 *	org.msscf.msscf.CFSec
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

package org.msscf.msscf.cfsec.CFSec;

import java.lang.reflect.*;
import java.net.*;
import java.rmi.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import com.github.msobkow.cflib.CFLib.*;

	/*
	 *	CFSecSecDeviceFactory implementation for SecDevice
	 */
public class CFSecSecDeviceDefaultFactory
	implements ICFSecSecDeviceFactory
{
	public CFSecSecDeviceDefaultFactory() {
	}

	public CFSecSecDevicePKey newPKey() {
		CFSecSecDevicePKey pkey =
			new CFSecSecDevicePKey();
		return( pkey );
	}

	public CFSecSecDeviceHPKey newHPKey() {
		CFSecSecDeviceHPKey hpkey =
			new CFSecSecDeviceHPKey();
		return( hpkey );
	}

	public CFSecSecDeviceByNameIdxKey newNameIdxKey() {
		CFSecSecDeviceByNameIdxKey key =
			new CFSecSecDeviceByNameIdxKey();
		return( key );
	}

	public CFSecSecDeviceByUserIdxKey newUserIdxKey() {
		CFSecSecDeviceByUserIdxKey key =
			new CFSecSecDeviceByUserIdxKey();
		return( key );
	}

	public CFSecSecDeviceBuff newBuff() {
		CFSecSecDeviceBuff buff =
			new CFSecSecDeviceBuff();
		return( buff );
	}

	public CFSecSecDeviceHBuff newHBuff() {
		CFSecSecDeviceHBuff hbuff =
			new CFSecSecDeviceHBuff();
		return( hbuff );
	}
}
