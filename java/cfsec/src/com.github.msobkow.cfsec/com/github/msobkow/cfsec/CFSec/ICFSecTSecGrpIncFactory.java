
// Description: Java 11 Factory interface for TSecGrpInc.

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
 *	CFSecTSecGrpIncFactory interface for TSecGrpInc
 */
public interface ICFSecTSecGrpIncFactory
{

	/**
	 *	Allocate a primary key for TSecGrpInc instances.
	 *
	 *	@return	The new instance.
	 */
	CFSecTSecGrpIncPKey newPKey();

	/**
	 *	Allocate a primary history key for TSecGrpInc instances.
	 *
	 *	@return	The new instance.
	 */
	CFSecTSecGrpIncHPKey newHPKey();

	/**
	 *	Allocate a TenantIdx key over TSecGrpInc instances.
	 *
	 *	@return	The new instance.
	 */
	CFSecTSecGrpIncByTenantIdxKey newTenantIdxKey();

	/**
	 *	Allocate a GroupIdx key over TSecGrpInc instances.
	 *
	 *	@return	The new instance.
	 */
	CFSecTSecGrpIncByGroupIdxKey newGroupIdxKey();

	/**
	 *	Allocate a IncludeIdx key over TSecGrpInc instances.
	 *
	 *	@return	The new instance.
	 */
	CFSecTSecGrpIncByIncludeIdxKey newIncludeIdxKey();

	/**
	 *	Allocate a UIncludeIdx key over TSecGrpInc instances.
	 *
	 *	@return	The new instance.
	 */
	CFSecTSecGrpIncByUIncludeIdxKey newUIncludeIdxKey();

	/**
	 *	Allocate a TSecGrpInc instance buffer.
	 *
	 *	@return	The new instance.
	 */
	CFSecTSecGrpIncBuff newBuff();

	/**
	 *	Allocate a TSecGrpInc history instance buffer.
	 *
	 *	@return	The new instance.
	 */
	CFSecTSecGrpIncHBuff newHBuff();

}
