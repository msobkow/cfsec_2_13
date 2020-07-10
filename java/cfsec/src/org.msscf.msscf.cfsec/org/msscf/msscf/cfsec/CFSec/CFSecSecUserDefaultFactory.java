
// Description: Java 11 Default Factory implementation for SecUser.

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
import org.msscf.msscf.cflib.CFLib.*;

	/*
	 *	CFSecSecUserFactory implementation for SecUser
	 */
public class CFSecSecUserDefaultFactory
	implements ICFSecSecUserFactory
{
	public CFSecSecUserDefaultFactory() {
	}

	public CFSecSecUserPKey newPKey() {
		CFSecSecUserPKey pkey =
			new CFSecSecUserPKey();
		return( pkey );
	}

	public CFSecSecUserHPKey newHPKey() {
		CFSecSecUserHPKey hpkey =
			new CFSecSecUserHPKey();
		return( hpkey );
	}

	public CFSecSecUserByULoginIdxKey newULoginIdxKey() {
		CFSecSecUserByULoginIdxKey key =
			new CFSecSecUserByULoginIdxKey();
		return( key );
	}

	public CFSecSecUserByEMConfIdxKey newEMConfIdxKey() {
		CFSecSecUserByEMConfIdxKey key =
			new CFSecSecUserByEMConfIdxKey();
		return( key );
	}

	public CFSecSecUserByPwdResetIdxKey newPwdResetIdxKey() {
		CFSecSecUserByPwdResetIdxKey key =
			new CFSecSecUserByPwdResetIdxKey();
		return( key );
	}

	public CFSecSecUserByDefDevIdxKey newDefDevIdxKey() {
		CFSecSecUserByDefDevIdxKey key =
			new CFSecSecUserByDefDevIdxKey();
		return( key );
	}

	public CFSecSecUserBuff newBuff() {
		CFSecSecUserBuff buff =
			new CFSecSecUserBuff();
		return( buff );
	}

	public CFSecSecUserHBuff newHBuff() {
		CFSecSecUserHBuff hbuff =
			new CFSecSecUserHBuff();
		return( hbuff );
	}
}
