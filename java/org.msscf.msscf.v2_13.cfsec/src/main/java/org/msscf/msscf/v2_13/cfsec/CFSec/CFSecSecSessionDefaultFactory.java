
// Description: Java 11 Default Factory implementation for SecSession.

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
	 *	CFSecSecSessionFactory implementation for SecSession
	 */
public class CFSecSecSessionDefaultFactory
	implements ICFSecSecSessionFactory
{
	public CFSecSecSessionDefaultFactory() {
	}

	public CFSecSecSessionPKey newPKey() {
		CFSecSecSessionPKey pkey =
			new CFSecSecSessionPKey();
		return( pkey );
	}

	public CFSecSecSessionHPKey newHPKey() {
		CFSecSecSessionHPKey hpkey =
			new CFSecSecSessionHPKey();
		return( hpkey );
	}

	public CFSecSecSessionBySecUserIdxKey newSecUserIdxKey() {
		CFSecSecSessionBySecUserIdxKey key =
			new CFSecSecSessionBySecUserIdxKey();
		return( key );
	}

	public CFSecSecSessionBySecDevIdxKey newSecDevIdxKey() {
		CFSecSecSessionBySecDevIdxKey key =
			new CFSecSecSessionBySecDevIdxKey();
		return( key );
	}

	public CFSecSecSessionByStartIdxKey newStartIdxKey() {
		CFSecSecSessionByStartIdxKey key =
			new CFSecSecSessionByStartIdxKey();
		return( key );
	}

	public CFSecSecSessionByFinishIdxKey newFinishIdxKey() {
		CFSecSecSessionByFinishIdxKey key =
			new CFSecSecSessionByFinishIdxKey();
		return( key );
	}

	public CFSecSecSessionBySecProxyIdxKey newSecProxyIdxKey() {
		CFSecSecSessionBySecProxyIdxKey key =
			new CFSecSecSessionBySecProxyIdxKey();
		return( key );
	}

	public CFSecSecSessionBuff newBuff() {
		CFSecSecSessionBuff buff =
			new CFSecSecSessionBuff();
		return( buff );
	}

	public CFSecSecSessionHBuff newHBuff() {
		CFSecSecSessionHBuff hbuff =
			new CFSecSecSessionHBuff();
		return( hbuff );
	}
}
