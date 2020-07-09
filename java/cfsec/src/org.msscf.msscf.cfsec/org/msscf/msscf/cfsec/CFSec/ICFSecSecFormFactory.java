
// Description: Java 11 Factory interface for SecForm.

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
import com.github.msobkow.cflib.CFLib.*;

/*
 *	CFSecSecFormFactory interface for SecForm
 */
public interface ICFSecSecFormFactory
{

	/**
	 *	Allocate a primary key for SecForm instances.
	 *
	 *	@return	The new instance.
	 */
	CFSecSecFormPKey newPKey();

	/**
	 *	Allocate a primary history key for SecForm instances.
	 *
	 *	@return	The new instance.
	 */
	CFSecSecFormHPKey newHPKey();

	/**
	 *	Allocate a ClusterIdx key over SecForm instances.
	 *
	 *	@return	The new instance.
	 */
	CFSecSecFormByClusterIdxKey newClusterIdxKey();

	/**
	 *	Allocate a SecAppIdx key over SecForm instances.
	 *
	 *	@return	The new instance.
	 */
	CFSecSecFormBySecAppIdxKey newSecAppIdxKey();

	/**
	 *	Allocate a UJEEServletIdx key over SecForm instances.
	 *
	 *	@return	The new instance.
	 */
	CFSecSecFormByUJEEServletIdxKey newUJEEServletIdxKey();

	/**
	 *	Allocate a SecForm instance buffer.
	 *
	 *	@return	The new instance.
	 */
	CFSecSecFormBuff newBuff();

	/**
	 *	Allocate a SecForm history instance buffer.
	 *
	 *	@return	The new instance.
	 */
	CFSecSecFormHBuff newHBuff();

}
