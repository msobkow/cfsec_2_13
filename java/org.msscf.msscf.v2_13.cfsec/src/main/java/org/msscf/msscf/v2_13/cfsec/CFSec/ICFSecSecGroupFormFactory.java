
// Description: Java 11 Factory interface for SecGroupForm.

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

package org.msscf.msscf.v2_13.cfsec.CFSec;

import java.lang.reflect.*;
import java.net.*;
import java.rmi.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.msscf.msscf.v2_13.cflib.CFLib.*;

/*
 *	CFSecSecGroupFormFactory interface for SecGroupForm
 */
public interface ICFSecSecGroupFormFactory
{

	/**
	 *	Allocate a primary key for SecGroupForm instances.
	 *
	 *	@return	The new instance.
	 */
	CFSecSecGroupFormPKey newPKey();

	/**
	 *	Allocate a primary history key for SecGroupForm instances.
	 *
	 *	@return	The new instance.
	 */
	CFSecSecGroupFormHPKey newHPKey();

	/**
	 *	Allocate a ClusterIdx key over SecGroupForm instances.
	 *
	 *	@return	The new instance.
	 */
	CFSecSecGroupFormByClusterIdxKey newClusterIdxKey();

	/**
	 *	Allocate a GroupIdx key over SecGroupForm instances.
	 *
	 *	@return	The new instance.
	 */
	CFSecSecGroupFormByGroupIdxKey newGroupIdxKey();

	/**
	 *	Allocate a AppIdx key over SecGroupForm instances.
	 *
	 *	@return	The new instance.
	 */
	CFSecSecGroupFormByAppIdxKey newAppIdxKey();

	/**
	 *	Allocate a FormIdx key over SecGroupForm instances.
	 *
	 *	@return	The new instance.
	 */
	CFSecSecGroupFormByFormIdxKey newFormIdxKey();

	/**
	 *	Allocate a UFormIdx key over SecGroupForm instances.
	 *
	 *	@return	The new instance.
	 */
	CFSecSecGroupFormByUFormIdxKey newUFormIdxKey();

	/**
	 *	Allocate a SecGroupForm instance buffer.
	 *
	 *	@return	The new instance.
	 */
	CFSecSecGroupFormBuff newBuff();

	/**
	 *	Allocate a SecGroupForm history instance buffer.
	 *
	 *	@return	The new instance.
	 */
	CFSecSecGroupFormHBuff newHBuff();

}
