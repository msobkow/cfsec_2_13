
// Description: Java 11 Factory interface for SysCluster.

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
 *	CFSecSysClusterFactory interface for SysCluster
 */
public interface ICFSecSysClusterFactory
{

	/**
	 *	Allocate a primary key for SysCluster instances.
	 *
	 *	@return	The new instance.
	 */
	CFSecSysClusterPKey newPKey();

	/**
	 *	Allocate a primary history key for SysCluster instances.
	 *
	 *	@return	The new instance.
	 */
	CFSecSysClusterHPKey newHPKey();

	/**
	 *	Allocate a ClusterIdx key over SysCluster instances.
	 *
	 *	@return	The new instance.
	 */
	CFSecSysClusterByClusterIdxKey newClusterIdxKey();

	/**
	 *	Allocate a SysCluster instance buffer.
	 *
	 *	@return	The new instance.
	 */
	CFSecSysClusterBuff newBuff();

	/**
	 *	Allocate a SysCluster history instance buffer.
	 *
	 *	@return	The new instance.
	 */
	CFSecSysClusterHBuff newHBuff();

}
