
// Description: Java 11 Default Factory implementation for Cluster.

/*
 *	org.msscf.msscf.CFSec
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFSec 2.13 Security Essentials
 *	
 *	Copyright 2020-2021 Mark Stephen Sobkow mark.sobkow@gmail.com
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
	 *	CFSecClusterFactory implementation for Cluster
	 */
public class CFSecClusterDefaultFactory
	implements ICFSecClusterFactory
{
	public CFSecClusterDefaultFactory() {
	}

	public CFSecClusterPKey newPKey() {
		CFSecClusterPKey pkey =
			new CFSecClusterPKey();
		return( pkey );
	}

	public CFSecClusterHPKey newHPKey() {
		CFSecClusterHPKey hpkey =
			new CFSecClusterHPKey();
		return( hpkey );
	}

	public CFSecClusterByUDomNameIdxKey newUDomNameIdxKey() {
		CFSecClusterByUDomNameIdxKey key =
			new CFSecClusterByUDomNameIdxKey();
		return( key );
	}

	public CFSecClusterByUDescrIdxKey newUDescrIdxKey() {
		CFSecClusterByUDescrIdxKey key =
			new CFSecClusterByUDescrIdxKey();
		return( key );
	}

	public CFSecClusterBuff newBuff() {
		CFSecClusterBuff buff =
			new CFSecClusterBuff();
		return( buff );
	}

	public CFSecClusterHBuff newHBuff() {
		CFSecClusterHBuff hbuff =
			new CFSecClusterHBuff();
		return( hbuff );
	}
}
