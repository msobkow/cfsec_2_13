
// Description: Java 11 Factory interface for SecGrpInc.

/*
 *	org.msscf.msscf.CFSec
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFSec 2.13 Security Essentials
 *	
 *	Copyright 2020-2021 Mark Stephen Sobkow mark.sobkow@gmail.com
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
 *	CFSecSecGrpIncFactory interface for SecGrpInc
 */
public interface ICFSecSecGrpIncFactory
{

	/**
	 *	Allocate a primary key for SecGrpInc instances.
	 *
	 *	@return	The new instance.
	 */
	CFSecSecGrpIncPKey newPKey();

	/**
	 *	Allocate a primary history key for SecGrpInc instances.
	 *
	 *	@return	The new instance.
	 */
	CFSecSecGrpIncHPKey newHPKey();

	/**
	 *	Allocate a ClusterIdx key over SecGrpInc instances.
	 *
	 *	@return	The new instance.
	 */
	CFSecSecGrpIncByClusterIdxKey newClusterIdxKey();

	/**
	 *	Allocate a GroupIdx key over SecGrpInc instances.
	 *
	 *	@return	The new instance.
	 */
	CFSecSecGrpIncByGroupIdxKey newGroupIdxKey();

	/**
	 *	Allocate a IncludeIdx key over SecGrpInc instances.
	 *
	 *	@return	The new instance.
	 */
	CFSecSecGrpIncByIncludeIdxKey newIncludeIdxKey();

	/**
	 *	Allocate a UIncludeIdx key over SecGrpInc instances.
	 *
	 *	@return	The new instance.
	 */
	CFSecSecGrpIncByUIncludeIdxKey newUIncludeIdxKey();

	/**
	 *	Allocate a SecGrpInc instance buffer.
	 *
	 *	@return	The new instance.
	 */
	CFSecSecGrpIncBuff newBuff();

	/**
	 *	Allocate a SecGrpInc history instance buffer.
	 *
	 *	@return	The new instance.
	 */
	CFSecSecGrpIncHBuff newHBuff();

}
