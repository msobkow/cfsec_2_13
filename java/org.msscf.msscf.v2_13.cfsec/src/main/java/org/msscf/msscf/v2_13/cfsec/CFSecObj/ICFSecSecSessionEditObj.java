// Description: Java 11 Instance Edit Object interface for CFSec SecSession.

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

public interface ICFSecSecSessionEditObj
	extends ICFSecSecSessionObj
{
	/*
	 *	Get the original for this edition as the base type for the class hierarchy.
	 *
	 *	@return The original, non-modifiable instance as a base ICFSecSecSessionObj.
	 */
	ICFSecSecSessionObj getOrig();

	/*
	 *	Get the original for this edition cast as the specified type.
	 *
	 *	@return The original, non-modifiable instance cast to a ICFSecSecSessionObj.
	 */
	ICFSecSecSessionObj getOrigAsSecSession();

	/*
	 *	create() may return a different instance than the
	 *	one used to invoke the operation.  All future references
	 *	should be to the returned instance, not the original
	 *	invoker.  You should lose all references to the original
	 *	invoker.
	 *
	 *	@return The created instance.
	 */
	ICFSecSecSessionObj create();

	/*
	 *	Update the instance.
	 */
	CFSecSecSessionEditObj update();

	/*
	 *	Delete the instance.
	 */
	CFSecSecSessionEditObj deleteInstance();

	/**
	 *	Get the optional String attribute SecDevName.
	 *
	 *	@return	The String value of the attribute SecDevName.
	 */
	String getOptionalSecDevName();

	/**
	 *	Set the optional String attribute SecDevName.
	 *
	 *	@param	value	the String value of the attribute SecDevName.
	 */
	void setOptionalSecDevName( String value );

	/**
	 *	Get the required Calendar attribute Start.
	 *
	 *	@return	The Calendar value of the attribute Start.
	 */
	Calendar getRequiredStart();

	/**
	 *	Set the required Calendar attribute Start.
	 *
	 *	@param	value	the Calendar value of the attribute Start.
	 */
	void setRequiredStart( Calendar value );

	/**
	 *	Get the optional Calendar attribute Finish.
	 *
	 *	@return	The Calendar value of the attribute Finish.
	 */
	Calendar getOptionalFinish();

	/**
	 *	Set the optional Calendar attribute Finish.
	 *
	 *	@param	value	the Calendar value of the attribute Finish.
	 */
	void setOptionalFinish( Calendar value );

	/**
	 *	Get the ICFSecSecUserObj instance referenced by the SecUser key.
	 *
	 *	@return	The ICFSecSecUserObj instance referenced by the SecUser key.
	 */
	ICFSecSecUserObj getRequiredContainerSecUser();

	/**
	 *	Set the ICFSecSecUserObj instance referenced by the SecUser key.
	 *
	 *	@param	value	the ICFSecSecUserObj instance to be referenced by the SecUser key.
	 */
	void setRequiredContainerSecUser( ICFSecSecUserObj value );

	/**
	 *	Get the ICFSecSecUserObj instance referenced by the SecProxy key.
	 *
	 *	@return	The ICFSecSecUserObj instance referenced by the SecProxy key.
	 */
	ICFSecSecUserObj getRequiredParentSecProxy();

	/**
	 *	Set the ICFSecSecUserObj instance referenced by the SecProxy key.
	 *
	 *	@param	value	the ICFSecSecUserObj instance to be referenced by the SecProxy key.
	 */
	void setRequiredParentSecProxy( ICFSecSecUserObj value );
}
