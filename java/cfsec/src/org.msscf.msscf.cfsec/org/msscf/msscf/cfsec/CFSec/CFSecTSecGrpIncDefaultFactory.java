
// Description: Java 11 Default Factory implementation for TSecGrpInc.

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
	 *	CFSecTSecGrpIncFactory implementation for TSecGrpInc
	 */
public class CFSecTSecGrpIncDefaultFactory
	implements ICFSecTSecGrpIncFactory
{
	public CFSecTSecGrpIncDefaultFactory() {
	}

	public CFSecTSecGrpIncPKey newPKey() {
		CFSecTSecGrpIncPKey pkey =
			new CFSecTSecGrpIncPKey();
		return( pkey );
	}

	public CFSecTSecGrpIncHPKey newHPKey() {
		CFSecTSecGrpIncHPKey hpkey =
			new CFSecTSecGrpIncHPKey();
		return( hpkey );
	}

	public CFSecTSecGrpIncByTenantIdxKey newTenantIdxKey() {
		CFSecTSecGrpIncByTenantIdxKey key =
			new CFSecTSecGrpIncByTenantIdxKey();
		return( key );
	}

	public CFSecTSecGrpIncByGroupIdxKey newGroupIdxKey() {
		CFSecTSecGrpIncByGroupIdxKey key =
			new CFSecTSecGrpIncByGroupIdxKey();
		return( key );
	}

	public CFSecTSecGrpIncByIncludeIdxKey newIncludeIdxKey() {
		CFSecTSecGrpIncByIncludeIdxKey key =
			new CFSecTSecGrpIncByIncludeIdxKey();
		return( key );
	}

	public CFSecTSecGrpIncByUIncludeIdxKey newUIncludeIdxKey() {
		CFSecTSecGrpIncByUIncludeIdxKey key =
			new CFSecTSecGrpIncByUIncludeIdxKey();
		return( key );
	}

	public CFSecTSecGrpIncBuff newBuff() {
		CFSecTSecGrpIncBuff buff =
			new CFSecTSecGrpIncBuff();
		return( buff );
	}

	public CFSecTSecGrpIncHBuff newHBuff() {
		CFSecTSecGrpIncHBuff hbuff =
			new CFSecTSecGrpIncHBuff();
		return( hbuff );
	}
}
