// Description: Java 11 Instance Edit Object interface for CFSec ISOCtryLang.

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

package org.msscf.msscf.cfsec.CFSecObj;

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.msscf.msscf.cflib.CFLib.*;
import org.msscf.msscf.cfsec.CFSec.*;

public interface ICFSecISOCtryLangEditObj
	extends ICFSecISOCtryLangObj
{
	/*
	 *	Get the original for this edition as the base type for the class hierarchy.
	 *
	 *	@return The original, non-modifiable instance as a base ICFSecISOCtryLangObj.
	 */
	ICFSecISOCtryLangObj getOrig();

	/*
	 *	Get the original for this edition cast as the specified type.
	 *
	 *	@return The original, non-modifiable instance cast to a ICFSecISOCtryLangObj.
	 */
	ICFSecISOCtryLangObj getOrigAsISOCtryLang();

	/*
	 *	create() may return a different instance than the
	 *	one used to invoke the operation.  All future references
	 *	should be to the returned instance, not the original
	 *	invoker.  You should lose all references to the original
	 *	invoker.
	 *
	 *	@return The created instance.
	 */
	ICFSecISOCtryLangObj create();

	/*
	 *	Update the instance.
	 */
	CFSecISOCtryLangEditObj update();

	/*
	 *	Delete the instance.
	 */
	CFSecISOCtryLangEditObj deleteInstance();

	/**
	 *	Get the ICFSecISOCtryObj instance referenced by the Ctry key.
	 *
	 *	@return	The ICFSecISOCtryObj instance referenced by the Ctry key.
	 */
	ICFSecISOCtryObj getRequiredContainerCtry();

	/**
	 *	Set the ICFSecISOCtryObj instance referenced by the Ctry key.
	 *
	 *	@param	value	the ICFSecISOCtryObj instance to be referenced by the Ctry key.
	 */
	void setRequiredContainerCtry( ICFSecISOCtryObj value );

	/**
	 *	Get the ICFSecISOLangObj instance referenced by the Lang key.
	 *
	 *	@return	The ICFSecISOLangObj instance referenced by the Lang key.
	 */
	ICFSecISOLangObj getRequiredParentLang();

	/**
	 *	Set the ICFSecISOLangObj instance referenced by the Lang key.
	 *
	 *	@param	value	the ICFSecISOLangObj instance to be referenced by the Lang key.
	 */
	void setRequiredParentLang( ICFSecISOLangObj value );

	/**
	 *	Set the user who created this instance.
	 *
	 *	@param	value	The ICFSecSecUserObj instance who created this instance.
	 */
	void setCreatedBy( ICFSecSecUserObj value );

	/**
	 *	Set the Calendar date-time this instance was created.
	 *
	 *	@param	value	The Calendar value for the create time of the instance.
	 */
	void setCreatedAt( Calendar value );

	/**
	 *	Set the user who updated this instance.
	 *
	 *	@param	value	The ICFSecSecUserObj instance who updated this instance.
	 */
	void setUpdatedBy( ICFSecSecUserObj value );

	/**
	 *	Set the Calendar date-time this instance was updated.
	 *
	 *	@param	value	The Calendar value for the create time of the instance.
	 */
	void setUpdatedAt( Calendar value );}