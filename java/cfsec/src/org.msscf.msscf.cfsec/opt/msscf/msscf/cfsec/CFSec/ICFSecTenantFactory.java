
// Description: Java 11 Factory interface for Tenant.

/*
 *	com.github.msobkow.CFSec
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

package com.github.msobkow.cfsec.CFSec;

import java.lang.reflect.*;
import java.net.*;
import java.rmi.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import com.github.msobkow.cflib.CFLib.*;

/*
 *	CFSecTenantFactory interface for Tenant
 */
public interface ICFSecTenantFactory
{

	/**
	 *	Allocate a primary key for Tenant instances.
	 *
	 *	@return	The new instance.
	 */
	CFSecTenantPKey newPKey();

	/**
	 *	Allocate a primary history key for Tenant instances.
	 *
	 *	@return	The new instance.
	 */
	CFSecTenantHPKey newHPKey();

	/**
	 *	Allocate a ClusterIdx key over Tenant instances.
	 *
	 *	@return	The new instance.
	 */
	CFSecTenantByClusterIdxKey newClusterIdxKey();

	/**
	 *	Allocate a UNameIdx key over Tenant instances.
	 *
	 *	@return	The new instance.
	 */
	CFSecTenantByUNameIdxKey newUNameIdxKey();

	/**
	 *	Allocate a Tenant instance buffer.
	 *
	 *	@return	The new instance.
	 */
	CFSecTenantBuff newBuff();

	/**
	 *	Allocate a Tenant history instance buffer.
	 *
	 *	@return	The new instance.
	 */
	CFSecTenantHBuff newHBuff();

}
