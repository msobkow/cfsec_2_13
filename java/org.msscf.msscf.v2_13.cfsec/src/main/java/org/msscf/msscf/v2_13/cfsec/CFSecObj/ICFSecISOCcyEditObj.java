// Description: Java 11 Instance Edit Object interface for CFSec ISOCcy.

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

package org.msscf.msscf.v2_13.cfsec.CFSecObj;

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.msscf.msscf.v2_13.cflib.CFLib.*;
import org.msscf.msscf.v2_13.cfsec.CFSec.*;

public interface ICFSecISOCcyEditObj
	extends ICFSecISOCcyObj
{
	/*
	 *	Get the original for this edition as the base type for the class hierarchy.
	 *
	 *	@return The original, non-modifiable instance as a base ICFSecISOCcyObj.
	 */
	ICFSecISOCcyObj getOrig();

	/*
	 *	Get the original for this edition cast as the specified type.
	 *
	 *	@return The original, non-modifiable instance cast to a ICFSecISOCcyObj.
	 */
	ICFSecISOCcyObj getOrigAsISOCcy();

	/*
	 *	create() may return a different instance than the
	 *	one used to invoke the operation.  All future references
	 *	should be to the returned instance, not the original
	 *	invoker.  You should lose all references to the original
	 *	invoker.
	 *
	 *	@return The created instance.
	 */
	ICFSecISOCcyObj create();

	/*
	 *	Update the instance.
	 */
	CFSecISOCcyEditObj update();

	/*
	 *	Delete the instance.
	 */
	CFSecISOCcyEditObj deleteInstance();

	/**
	 *	Get the required String attribute ISOCode.
	 *
	 *	@return	The String value of the attribute ISOCode.
	 */
	String getRequiredISOCode();

	/**
	 *	Set the required String attribute ISOCode.
	 *
	 *	@param	value	the String value of the attribute ISOCode.
	 */
	void setRequiredISOCode( String value );

	/**
	 *	Get the required String attribute Name.
	 *
	 *	@return	The String value of the attribute Name.
	 */
	String getRequiredName();

	/**
	 *	Set the required String attribute Name.
	 *
	 *	@param	value	the String value of the attribute Name.
	 */
	void setRequiredName( String value );

	/**
	 *	Get the optional String attribute UnitSymbol.
	 *
	 *	@return	The String value of the attribute UnitSymbol.
	 */
	String getOptionalUnitSymbol();

	/**
	 *	Set the optional String attribute UnitSymbol.
	 *
	 *	@param	value	the String value of the attribute UnitSymbol.
	 */
	void setOptionalUnitSymbol( String value );

	/**
	 *	Get the required short attribute Precis.
	 *
	 *	@return	The short value of the attribute Precis.
	 */
	short getRequiredPrecis();

	/**
	 *	Set the required short attribute Precis.
	 *
	 *	@param	value	the short value of the attribute Precis.
	 */
	void setRequiredPrecis( short value );

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
