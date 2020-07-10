
// Description: Java 11 Factory interface for TSecGroup.

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
 *	CFSecTSecGroupFactory interface for TSecGroup
 */
public interface ICFSecTSecGroupFactory
{

	/**
	 *	Allocate a primary key for TSecGroup instances.
	 *
	 *	@return	The new instance.
	 */
	CFSecTSecGroupPKey newPKey();

	/**
	 *	Allocate a primary history key for TSecGroup instances.
	 *
	 *	@return	The new instance.
	 */
	CFSecTSecGroupHPKey newHPKey();

	/**
	 *	Allocate a TenantIdx key over TSecGroup instances.
	 *
	 *	@return	The new instance.
	 */
	CFSecTSecGroupByTenantIdxKey newTenantIdxKey();

	/**
	 *	Allocate a TenantVisIdx key over TSecGroup instances.
	 *
	 *	@return	The new instance.
	 */
	CFSecTSecGroupByTenantVisIdxKey newTenantVisIdxKey();

	/**
	 *	Allocate a UNameIdx key over TSecGroup instances.
	 *
	 *	@return	The new instance.
	 */
	CFSecTSecGroupByUNameIdxKey newUNameIdxKey();

	/**
	 *	Allocate a TSecGroup instance buffer.
	 *
	 *	@return	The new instance.
	 */
	CFSecTSecGroupBuff newBuff();

	/**
	 *	Allocate a TSecGroup history instance buffer.
	 *
	 *	@return	The new instance.
	 */
	CFSecTSecGroupHBuff newHBuff();

}
