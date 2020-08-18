// Description: Java 11 Instance Edit Object interface for CFSec SecUser.

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

package org.msscf.msscf.v2_13.cfsec.CFSecObj;

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.msscf.msscf.v2_13.cflib.CFLib.*;
import org.msscf.msscf.v2_13.cfsec.CFSec.*;

public interface ICFSecSecUserEditObj
	extends ICFSecSecUserObj
{
	/*
	 *	Get the original for this edition as the base type for the class hierarchy.
	 *
	 *	@return The original, non-modifiable instance as a base ICFSecSecUserObj.
	 */
	ICFSecSecUserObj getOrig();

	/*
	 *	Get the original for this edition cast as the specified type.
	 *
	 *	@return The original, non-modifiable instance cast to a ICFSecSecUserObj.
	 */
	ICFSecSecUserObj getOrigAsSecUser();

	/*
	 *	create() may return a different instance than the
	 *	one used to invoke the operation.  All future references
	 *	should be to the returned instance, not the original
	 *	invoker.  You should lose all references to the original
	 *	invoker.
	 *
	 *	@return The created instance.
	 */
	ICFSecSecUserObj create();

	/*
	 *	Update the instance.
	 */
	CFSecSecUserEditObj update();

	/*
	 *	Delete the instance.
	 */
	CFSecSecUserEditObj deleteInstance();

	/**
	 *	Get the required String attribute LoginId.
	 *
	 *	@return	The String value of the attribute LoginId.
	 */
	String getRequiredLoginId();

	/**
	 *	Set the required String attribute LoginId.
	 *
	 *	@param	value	the String value of the attribute LoginId.
	 */
	void setRequiredLoginId( String value );

	/**
	 *	Get the required String attribute EMailAddress.
	 *
	 *	@return	The String value of the attribute EMailAddress.
	 */
	String getRequiredEMailAddress();

	/**
	 *	Set the required String attribute EMailAddress.
	 *
	 *	@param	value	the String value of the attribute EMailAddress.
	 */
	void setRequiredEMailAddress( String value );

	/**
	 *	Get the optional UUID attribute EMailConfirmUuid.
	 *
	 *	@return	The UUID value of the attribute EMailConfirmUuid.
	 */
	UUID getOptionalEMailConfirmUuid();

	/**
	 *	Set the optional UUID attribute EMailConfirmUuid.
	 *
	 *	@param	value	the UUID value of the attribute EMailConfirmUuid.
	 */
	void setOptionalEMailConfirmUuid( UUID value );

	/**
	 *	Get the required String attribute PasswordHash.
	 *
	 *	@return	The String value of the attribute PasswordHash.
	 */
	String getRequiredPasswordHash();

	/**
	 *	Set the required String attribute PasswordHash.
	 *
	 *	@param	value	the String value of the attribute PasswordHash.
	 */
	void setRequiredPasswordHash( String value );

	/**
	 *	Get the optional UUID attribute PasswordResetUuid.
	 *
	 *	@return	The UUID value of the attribute PasswordResetUuid.
	 */
	UUID getOptionalPasswordResetUuid();

	/**
	 *	Set the optional UUID attribute PasswordResetUuid.
	 *
	 *	@param	value	the UUID value of the attribute PasswordResetUuid.
	 */
	void setOptionalPasswordResetUuid( UUID value );

	/**
	 *	Get the ICFSecSecDeviceObj instance referenced by the DefDev key.
	 *
	 *	@return	The ICFSecSecDeviceObj instance referenced by the DefDev key.
	 */
	ICFSecSecDeviceObj getOptionalLookupDefDev();

	/**
	 *	Set the ICFSecSecDeviceObj instance referenced by the DefDev key.
	 *
	 *	@param	value	the ICFSecSecDeviceObj instance to be referenced by the DefDev key.
	 */
	void setOptionalLookupDefDev( ICFSecSecDeviceObj value );

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
