
// Description: Java 11 Default Factory implementation for Cluster.

/*
 *	org.msscf.msscf.CFSec
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFSec 2.13 Security Essentials
 *	
 *	Copyright 2020 Mark Stephen Sobkow
 *	
 *		This file is part of MSS Code Factory.
 *	
 *		MSS Code Factory is available under dual commercial license from Mark Stephen
 *		Sobkow, or under the terms of the GNU General Public License, Version 3
 *		or later.
 *	
 *	    MSS Code Factory is free software: you can redistribute it and/or modify
 *	    it under the terms of the GNU General Public License as published by
 *	    the Free Software Foundation, either version 3 of the License, or
 *	    (at your option) any later version.
 *	
 *	    MSS Code Factory is distributed in the hope that it will be useful,
 *	    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	    GNU General Public License for more details.
 *	
 *	    You should have received a copy of the GNU General Public License
 *	    along with MSS Code Factory.  If not, see <https://www.gnu.org/licenses/>.
 *	
 *	Donations to support MSS Code Factory can be made at
 *	https://www.paypal.com/paypalme2/MarkSobkow
 *	
 *	Please contact Mark Stephen Sobkow at msobkow@sasktel.net for commercial licensing.
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
