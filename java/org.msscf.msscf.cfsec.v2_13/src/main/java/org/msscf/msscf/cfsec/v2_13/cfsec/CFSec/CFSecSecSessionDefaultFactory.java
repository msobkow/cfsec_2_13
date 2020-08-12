
// Description: Java 11 Default Factory implementation for SecSession.

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

package org.msscf.msscf.cfsec.v2_13.cfsec.CFSec;

import java.lang.reflect.*;
import java.net.*;
import java.rmi.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.msscf.msscf.cflib.v2_13.CFLib.*;

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
