
// Description: Java 11 Default Factory implementation for SecForm.

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
	 *	CFSecSecFormFactory implementation for SecForm
	 */
public class CFSecSecFormDefaultFactory
	implements ICFSecSecFormFactory
{
	public CFSecSecFormDefaultFactory() {
	}

	public CFSecSecFormPKey newPKey() {
		CFSecSecFormPKey pkey =
			new CFSecSecFormPKey();
		return( pkey );
	}

	public CFSecSecFormHPKey newHPKey() {
		CFSecSecFormHPKey hpkey =
			new CFSecSecFormHPKey();
		return( hpkey );
	}

	public CFSecSecFormByClusterIdxKey newClusterIdxKey() {
		CFSecSecFormByClusterIdxKey key =
			new CFSecSecFormByClusterIdxKey();
		return( key );
	}

	public CFSecSecFormBySecAppIdxKey newSecAppIdxKey() {
		CFSecSecFormBySecAppIdxKey key =
			new CFSecSecFormBySecAppIdxKey();
		return( key );
	}

	public CFSecSecFormByUJEEServletIdxKey newUJEEServletIdxKey() {
		CFSecSecFormByUJEEServletIdxKey key =
			new CFSecSecFormByUJEEServletIdxKey();
		return( key );
	}

	public CFSecSecFormBuff newBuff() {
		CFSecSecFormBuff buff =
			new CFSecSecFormBuff();
		return( buff );
	}

	public CFSecSecFormHBuff newHBuff() {
		CFSecSecFormHBuff hbuff =
			new CFSecSecFormHBuff();
		return( hbuff );
	}
}
