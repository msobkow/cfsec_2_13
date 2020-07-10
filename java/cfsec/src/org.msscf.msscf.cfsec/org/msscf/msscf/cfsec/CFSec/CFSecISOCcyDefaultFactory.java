
// Description: Java 11 Default Factory implementation for ISOCcy.

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
	 *	CFSecISOCcyFactory implementation for ISOCcy
	 */
public class CFSecISOCcyDefaultFactory
	implements ICFSecISOCcyFactory
{
	public CFSecISOCcyDefaultFactory() {
	}

	public CFSecISOCcyPKey newPKey() {
		CFSecISOCcyPKey pkey =
			new CFSecISOCcyPKey();
		return( pkey );
	}

	public CFSecISOCcyHPKey newHPKey() {
		CFSecISOCcyHPKey hpkey =
			new CFSecISOCcyHPKey();
		return( hpkey );
	}

	public CFSecISOCcyByCcyCdIdxKey newCcyCdIdxKey() {
		CFSecISOCcyByCcyCdIdxKey key =
			new CFSecISOCcyByCcyCdIdxKey();
		return( key );
	}

	public CFSecISOCcyByCcyNmIdxKey newCcyNmIdxKey() {
		CFSecISOCcyByCcyNmIdxKey key =
			new CFSecISOCcyByCcyNmIdxKey();
		return( key );
	}

	public CFSecISOCcyBuff newBuff() {
		CFSecISOCcyBuff buff =
			new CFSecISOCcyBuff();
		return( buff );
	}

	public CFSecISOCcyHBuff newHBuff() {
		CFSecISOCcyHBuff hbuff =
			new CFSecISOCcyHBuff();
		return( hbuff );
	}
}
