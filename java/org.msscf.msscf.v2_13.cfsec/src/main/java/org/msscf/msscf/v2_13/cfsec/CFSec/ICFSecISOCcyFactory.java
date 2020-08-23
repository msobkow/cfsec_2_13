
// Description: Java 11 Factory interface for ISOCcy.

/*
 *	org.msscf.msscf.CFSec
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFSec 2.13 Security Essentials
 *	
 *	Copyright 2020 Mark Stephen Sobkow msobkow@sasktel.net
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
 *	CFSecISOCcyFactory interface for ISOCcy
 */
public interface ICFSecISOCcyFactory
{

	/**
	 *	Allocate a primary key for ISOCcy instances.
	 *
	 *	@return	The new instance.
	 */
	CFSecISOCcyPKey newPKey();

	/**
	 *	Allocate a primary history key for ISOCcy instances.
	 *
	 *	@return	The new instance.
	 */
	CFSecISOCcyHPKey newHPKey();

	/**
	 *	Allocate a CcyCdIdx key over ISOCcy instances.
	 *
	 *	@return	The new instance.
	 */
	CFSecISOCcyByCcyCdIdxKey newCcyCdIdxKey();

	/**
	 *	Allocate a CcyNmIdx key over ISOCcy instances.
	 *
	 *	@return	The new instance.
	 */
	CFSecISOCcyByCcyNmIdxKey newCcyNmIdxKey();

	/**
	 *	Allocate a ISOCcy instance buffer.
	 *
	 *	@return	The new instance.
	 */
	CFSecISOCcyBuff newBuff();

	/**
	 *	Allocate a ISOCcy history instance buffer.
	 *
	 *	@return	The new instance.
	 */
	CFSecISOCcyHBuff newHBuff();

}
