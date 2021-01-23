// Description: Java 11 Instance Edit Object interface for CFSec Service.

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

public interface ICFSecServiceEditObj
	extends ICFSecServiceObj
{
	/*
	 *	Get the original for this edition as the base type for the class hierarchy.
	 *
	 *	@return The original, non-modifiable instance as a base ICFSecServiceObj.
	 */
	ICFSecServiceObj getOrig();

	/*
	 *	Get the original for this edition cast as the specified type.
	 *
	 *	@return The original, non-modifiable instance cast to a ICFSecServiceObj.
	 */
	ICFSecServiceObj getOrigAsService();

	/*
	 *	create() may return a different instance than the
	 *	one used to invoke the operation.  All future references
	 *	should be to the returned instance, not the original
	 *	invoker.  You should lose all references to the original
	 *	invoker.
	 *
	 *	@return The created instance.
	 */
	ICFSecServiceObj create();

	/*
	 *	Update the instance.
	 */
	CFSecServiceEditObj update();

	/*
	 *	Delete the instance.
	 */
	CFSecServiceEditObj deleteInstance();

	/**
	 *	Get the required short attribute HostPort.
	 *
	 *	@return	The short value of the attribute HostPort.
	 */
	short getRequiredHostPort();

	/**
	 *	Set the required short attribute HostPort.
	 *
	 *	@param	value	the short value of the attribute HostPort.
	 */
	void setRequiredHostPort( short value );

	/**
	 *	Get the ICFSecClusterObj instance referenced by the Cluster key.
	 *
	 *	@return	The ICFSecClusterObj instance referenced by the Cluster key.
	 */
	ICFSecClusterObj getRequiredOwnerCluster();

	/**
	 *	Set the ICFSecClusterObj instance referenced by the Cluster key.
	 *
	 *	@param	value	the ICFSecClusterObj instance to be referenced by the Cluster key.
	 */
	void setRequiredOwnerCluster( ICFSecClusterObj value );

	/**
	 *	Get the ICFSecHostNodeObj instance referenced by the Host key.
	 *
	 *	@return	The ICFSecHostNodeObj instance referenced by the Host key.
	 */
	ICFSecHostNodeObj getOptionalContainerHost();

	/**
	 *	Set the ICFSecHostNodeObj instance referenced by the Host key.
	 *
	 *	@param	value	the ICFSecHostNodeObj instance to be referenced by the Host key.
	 */
	void setOptionalContainerHost( ICFSecHostNodeObj value );

	/**
	 *	Get the ICFSecServiceTypeObj instance referenced by the ServiceType key.
	 *
	 *	@return	The ICFSecServiceTypeObj instance referenced by the ServiceType key.
	 */
	ICFSecServiceTypeObj getOptionalParentServiceType();

	/**
	 *	Set the ICFSecServiceTypeObj instance referenced by the ServiceType key.
	 *
	 *	@param	value	the ICFSecServiceTypeObj instance to be referenced by the ServiceType key.
	 */
	void setOptionalParentServiceType( ICFSecServiceTypeObj value );

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
