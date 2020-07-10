
// Description: Java 11 Default Factory implementation for ServiceType.

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
	 *	CFSecServiceTypeFactory implementation for ServiceType
	 */
public class CFSecServiceTypeDefaultFactory
	implements ICFSecServiceTypeFactory
{
	public CFSecServiceTypeDefaultFactory() {
	}

	public CFSecServiceTypePKey newPKey() {
		CFSecServiceTypePKey pkey =
			new CFSecServiceTypePKey();
		return( pkey );
	}

	public CFSecServiceTypeHPKey newHPKey() {
		CFSecServiceTypeHPKey hpkey =
			new CFSecServiceTypeHPKey();
		return( hpkey );
	}

	public CFSecServiceTypeByUDescrIdxKey newUDescrIdxKey() {
		CFSecServiceTypeByUDescrIdxKey key =
			new CFSecServiceTypeByUDescrIdxKey();
		return( key );
	}

	public CFSecServiceTypeBuff newBuff() {
		CFSecServiceTypeBuff buff =
			new CFSecServiceTypeBuff();
		return( buff );
	}

	public CFSecServiceTypeHBuff newHBuff() {
		CFSecServiceTypeHBuff hbuff =
			new CFSecServiceTypeHBuff();
		return( hbuff );
	}
}
