// Description: Java 11 Instance Edit Object interface for CFSec ISOTZone.

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

public interface ICFSecISOTZoneEditObj
	extends ICFSecISOTZoneObj
{
	/*
	 *	Get the original for this edition as the base type for the class hierarchy.
	 *
	 *	@return The original, non-modifiable instance as a base ICFSecISOTZoneObj.
	 */
	ICFSecISOTZoneObj getOrig();

	/*
	 *	Get the original for this edition cast as the specified type.
	 *
	 *	@return The original, non-modifiable instance cast to a ICFSecISOTZoneObj.
	 */
	ICFSecISOTZoneObj getOrigAsISOTZone();

	/*
	 *	create() may return a different instance than the
	 *	one used to invoke the operation.  All future references
	 *	should be to the returned instance, not the original
	 *	invoker.  You should lose all references to the original
	 *	invoker.
	 *
	 *	@return The created instance.
	 */
	ICFSecISOTZoneObj create();

	/*
	 *	Update the instance.
	 */
	CFSecISOTZoneEditObj update();

	/*
	 *	Delete the instance.
	 */
	CFSecISOTZoneEditObj deleteInstance();

	/**
	 *	Get the required String attribute Iso8601.
	 *
	 *	@return	The String value of the attribute Iso8601.
	 */
	String getRequiredIso8601();

	/**
	 *	Set the required String attribute Iso8601.
	 *
	 *	@param	value	the String value of the attribute Iso8601.
	 */
	void setRequiredIso8601( String value );

	/**
	 *	Get the required String attribute TZName.
	 *
	 *	@return	The String value of the attribute TZName.
	 */
	String getRequiredTZName();

	/**
	 *	Set the required String attribute TZName.
	 *
	 *	@param	value	the String value of the attribute TZName.
	 */
	void setRequiredTZName( String value );

	/**
	 *	Get the required short attribute TZHourOffset.
	 *
	 *	@return	The short value of the attribute TZHourOffset.
	 */
	short getRequiredTZHourOffset();

	/**
	 *	Set the required short attribute TZHourOffset.
	 *
	 *	@param	value	the short value of the attribute TZHourOffset.
	 */
	void setRequiredTZHourOffset( short value );

	/**
	 *	Get the required short attribute TZMinOffset.
	 *
	 *	@return	The short value of the attribute TZMinOffset.
	 */
	short getRequiredTZMinOffset();

	/**
	 *	Set the required short attribute TZMinOffset.
	 *
	 *	@param	value	the short value of the attribute TZMinOffset.
	 */
	void setRequiredTZMinOffset( short value );

	/**
	 *	Get the required String attribute Description.
	 *
	 *	@return	The String value of the attribute Description.
	 */
	String getRequiredDescription();

	/**
	 *	Set the required String attribute Description.
	 *
	 *	@param	value	the String value of the attribute Description.
	 */
	void setRequiredDescription( String value );

	/**
	 *	Get the required boolean attribute Visible.
	 *
	 *	@return	The boolean value of the attribute Visible.
	 */
	boolean getRequiredVisible();

	/**
	 *	Set the required boolean attribute Visible.
	 *
	 *	@param	value	the boolean value of the attribute Visible.
	 */
	void setRequiredVisible( boolean value );

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
