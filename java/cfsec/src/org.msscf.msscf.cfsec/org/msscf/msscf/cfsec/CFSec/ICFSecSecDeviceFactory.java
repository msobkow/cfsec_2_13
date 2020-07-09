
// Description: Java 11 Factory interface for SecDevice.

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
 *	CFSecSecDeviceFactory interface for SecDevice
 */
public interface ICFSecSecDeviceFactory
{

	/**
	 *	Allocate a primary key for SecDevice instances.
	 *
	 *	@return	The new instance.
	 */
	CFSecSecDevicePKey newPKey();

	/**
	 *	Allocate a primary history key for SecDevice instances.
	 *
	 *	@return	The new instance.
	 */
	CFSecSecDeviceHPKey newHPKey();

	/**
	 *	Allocate a NameIdx key over SecDevice instances.
	 *
	 *	@return	The new instance.
	 */
	CFSecSecDeviceByNameIdxKey newNameIdxKey();

	/**
	 *	Allocate a UserIdx key over SecDevice instances.
	 *
	 *	@return	The new instance.
	 */
	CFSecSecDeviceByUserIdxKey newUserIdxKey();

	/**
	 *	Allocate a SecDevice instance buffer.
	 *
	 *	@return	The new instance.
	 */
	CFSecSecDeviceBuff newBuff();

	/**
	 *	Allocate a SecDevice history instance buffer.
	 *
	 *	@return	The new instance.
	 */
	CFSecSecDeviceHBuff newHBuff();

}
