
// Description: Java 11 Factory interface for Service.

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
 *	CFSecServiceFactory interface for Service
 */
public interface ICFSecServiceFactory
{

	/**
	 *	Allocate a primary key for Service instances.
	 *
	 *	@return	The new instance.
	 */
	CFSecServicePKey newPKey();

	/**
	 *	Allocate a primary history key for Service instances.
	 *
	 *	@return	The new instance.
	 */
	CFSecServiceHPKey newHPKey();

	/**
	 *	Allocate a ClusterIdx key over Service instances.
	 *
	 *	@return	The new instance.
	 */
	CFSecServiceByClusterIdxKey newClusterIdxKey();

	/**
	 *	Allocate a HostIdx key over Service instances.
	 *
	 *	@return	The new instance.
	 */
	CFSecServiceByHostIdxKey newHostIdxKey();

	/**
	 *	Allocate a TypeIdx key over Service instances.
	 *
	 *	@return	The new instance.
	 */
	CFSecServiceByTypeIdxKey newTypeIdxKey();

	/**
	 *	Allocate a UTypeIdx key over Service instances.
	 *
	 *	@return	The new instance.
	 */
	CFSecServiceByUTypeIdxKey newUTypeIdxKey();

	/**
	 *	Allocate a UHostPortIdx key over Service instances.
	 *
	 *	@return	The new instance.
	 */
	CFSecServiceByUHostPortIdxKey newUHostPortIdxKey();

	/**
	 *	Allocate a Service instance buffer.
	 *
	 *	@return	The new instance.
	 */
	CFSecServiceBuff newBuff();

	/**
	 *	Allocate a Service history instance buffer.
	 *
	 *	@return	The new instance.
	 */
	CFSecServiceHBuff newHBuff();

}
