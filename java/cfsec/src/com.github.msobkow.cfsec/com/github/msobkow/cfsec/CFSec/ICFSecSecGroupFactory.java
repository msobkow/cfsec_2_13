
// Description: Java 11 Factory interface for SecGroup.

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
 *	CFSecSecGroupFactory interface for SecGroup
 */
public interface ICFSecSecGroupFactory
{

	/**
	 *	Allocate a primary key for SecGroup instances.
	 *
	 *	@return	The new instance.
	 */
	CFSecSecGroupPKey newPKey();

	/**
	 *	Allocate a primary history key for SecGroup instances.
	 *
	 *	@return	The new instance.
	 */
	CFSecSecGroupHPKey newHPKey();

	/**
	 *	Allocate a ClusterIdx key over SecGroup instances.
	 *
	 *	@return	The new instance.
	 */
	CFSecSecGroupByClusterIdxKey newClusterIdxKey();

	/**
	 *	Allocate a ClusterVisIdx key over SecGroup instances.
	 *
	 *	@return	The new instance.
	 */
	CFSecSecGroupByClusterVisIdxKey newClusterVisIdxKey();

	/**
	 *	Allocate a UNameIdx key over SecGroup instances.
	 *
	 *	@return	The new instance.
	 */
	CFSecSecGroupByUNameIdxKey newUNameIdxKey();

	/**
	 *	Allocate a SecGroup instance buffer.
	 *
	 *	@return	The new instance.
	 */
	CFSecSecGroupBuff newBuff();

	/**
	 *	Allocate a SecGroup history instance buffer.
	 *
	 *	@return	The new instance.
	 */
	CFSecSecGroupHBuff newHBuff();

}