
// Description: Java 11 Default Factory implementation for SecGrpMemb.

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

package com.github.msobkow.cfsec.CFSec;

import java.lang.reflect.*;
import java.net.*;
import java.rmi.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import com.github.msobkow.cflib.CFLib.*;

	/*
	 *	CFSecSecGrpMembFactory implementation for SecGrpMemb
	 */
public class CFSecSecGrpMembDefaultFactory
	implements ICFSecSecGrpMembFactory
{
	public CFSecSecGrpMembDefaultFactory() {
	}

	public CFSecSecGrpMembPKey newPKey() {
		CFSecSecGrpMembPKey pkey =
			new CFSecSecGrpMembPKey();
		return( pkey );
	}

	public CFSecSecGrpMembHPKey newHPKey() {
		CFSecSecGrpMembHPKey hpkey =
			new CFSecSecGrpMembHPKey();
		return( hpkey );
	}

	public CFSecSecGrpMembByClusterIdxKey newClusterIdxKey() {
		CFSecSecGrpMembByClusterIdxKey key =
			new CFSecSecGrpMembByClusterIdxKey();
		return( key );
	}

	public CFSecSecGrpMembByGroupIdxKey newGroupIdxKey() {
		CFSecSecGrpMembByGroupIdxKey key =
			new CFSecSecGrpMembByGroupIdxKey();
		return( key );
	}

	public CFSecSecGrpMembByUserIdxKey newUserIdxKey() {
		CFSecSecGrpMembByUserIdxKey key =
			new CFSecSecGrpMembByUserIdxKey();
		return( key );
	}

	public CFSecSecGrpMembByUUserIdxKey newUUserIdxKey() {
		CFSecSecGrpMembByUUserIdxKey key =
			new CFSecSecGrpMembByUUserIdxKey();
		return( key );
	}

	public CFSecSecGrpMembBuff newBuff() {
		CFSecSecGrpMembBuff buff =
			new CFSecSecGrpMembBuff();
		return( buff );
	}

	public CFSecSecGrpMembHBuff newHBuff() {
		CFSecSecGrpMembHBuff hbuff =
			new CFSecSecGrpMembHBuff();
		return( hbuff );
	}
}