// Description: Java 11 Object interface for CFSec Service.

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

package org.msscf.msscf.cfsec.v2_13.cfsec.CFSecObj;

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.msscf.msscf.cfsec.v2_13.cfsec.CFSec.*;
import org.msscf.msscf.cflib.v2_13.CFLib.*;
import org.msscf.msscf.cfsec.CFSec.*;

public interface ICFSecServiceObj
	extends ICFLibAnyObj
{
	String getClassCode();
	/**
	 *	Get the user who created this instance.
	 *
	 *	@return	The ICFSecSecUserObj instance who created this instance.
	 */
	ICFSecSecUserObj getCreatedBy();

	/**
	 *	Get the Calendar date-time this instance was created.
	 *
	 *	@return	The Calendar value for the create time of the instance.
	 */
	Calendar getCreatedAt();

	/**
	 *	Get the user who updated this instance.
	 *
	 *	@return	The ICFSecSecUserObj instance who updated this instance.
	 */
	ICFSecSecUserObj getUpdatedBy();

	/**
	 *	Get the Calendar date-time this instance was updated.
	 *
	 *	@return	The Calendar value for the create time of the instance.
	 */
	Calendar getUpdatedAt();
	/**
	 *	Realise this instance of a Service.
	 *
	 *	@return	CFSecServiceObj instance which should be subsequently referenced.
	 */
	ICFSecServiceObj realise();

	/**
	 *	Forget this instance from the cache.
	 *	<p>
	 *	This method should only be invoked by implementation internals.
	 */
	void forget();

	/**
	 *	Re-read this instance by it's primary key.
	 *
	 *	@return	ICFSecServiceObj the reference to the cached or read (realised) instance.
	 */
	ICFSecServiceObj read();

	/**
	 *	Re-read this instance by it's primary key.
	 *
	 *	@return	ICFSecServiceObj the reference to the cached or read (realised) instance.
	 */
	ICFSecServiceObj read( boolean forceRead );

	/**
	 *	Initialize and return a locked edition of this Service instance.
	 *
	 *	@return	The newly locked ICFSecServiceEditObj edition of this instance.
	 */
	ICFSecServiceEditObj beginEdit();

	/**
	 *	End this edition of this Service instance.
	 *
	 *	@throws	CFLibNotSupportedException if you try to end a read-only view.
	 */
	void endEdit();

	/**
	 *	Get the current edition of this Service instance.
	 *
	 *	@return	The ICFSecServiceEditObj edition of this instance.
	 */
	ICFSecServiceEditObj getEdit();

	/**
	 *	Get the current edition of this Service instance as a ICFSecServiceEditObj.
	 *
	 *	@return	The ICFSecServiceEditObj edition of this instance.
	 */
	ICFSecServiceEditObj getEditAsService();

	/**
	 *	Get the ICFSecServiceTableObj table cache which manages this instance.
	 *
	 *	@return	ICFSecServiceTableObj table cache which manages this instance.
	 */
	ICFSecServiceTableObj getServiceTable();

	/**
	 *	Get the ICFSecSchemaObj schema cache which manages this instance.
	 *
	 *	@return	ICFSecSchemaObj schema cache which manages this instance.
	 */
	ICFSecSchemaObj getSchema();

	/**
	 *	Get the CFSecServiceBuff instance which currently backs this instance.
	 *	<p>
	 *	This value <i>will</i> change for read-only instances, so you should
	 *	not hold on to the value as a reference anywhere outside the current call stack.
	 *
	 *	@return	CFSecServiceBuff instance which currently backs this object.
	 */
	CFSecServiceBuff getBuff();

	/**
	 *	Internal use only.
	 */
	void setBuff( CFSecServiceBuff value );

	/**
	 *	Get the CFSecServiceBuff instance which currently backs this instance.
	 *	<p>
	 *	This value <i>will</i> change for read-only instances, so you should
	 *	not hold on to the value as a reference anywhere outside the current call stack.
	 *
	 *	@return	CFSecServiceBuff instance which currently backs this object.
	 */
	CFSecServiceBuff getServiceBuff();

	/**
	 *	Get the primary key of this instance.
	 *
	 *	@return	CFSecServicePKey primary key for this instance.
	 */
	CFSecServicePKey getPKey();

	/**
	 *	Set the primary key of this instance.
	 *	<p>
	 *	This method should only be invoked by implementation internals.
	 *
	 *	@param CFSecServicePKey primary key value for this instance.
	 */
	void setPKey( CFSecServicePKey value );

	/**
	 *	Is this a new instance?
	 *
	 *	@return	True if this is a new instance, otherwise false if it has
	 *		been read, locked, or created.
	 */
	boolean getIsNew();

	/**
	 *	Indicate whether this is a new instance.
	 *	<p>
	 *	This method should only be used by implementation internals.
	 *
	 *	@param	True if this is a new instance, otherwise false.
	 */
	void setIsNew( boolean value );

	/**
	 *	Get the required long attribute ClusterId.
	 *
	 *	@return	The required long attribute ClusterId.
	 */
	long getRequiredClusterId();

	/**
	 *	Get the required long attribute ServiceId.
	 *
	 *	@return	The required long attribute ServiceId.
	 */
	long getRequiredServiceId();

	/**
	 *	Get the required long attribute HostNodeId.
	 *
	 *	@return	The required long attribute HostNodeId.
	 */
	long getRequiredHostNodeId();

	/**
	 *	Get the required int attribute ServiceTypeId.
	 *
	 *	@return	The required int attribute ServiceTypeId.
	 */
	int getRequiredServiceTypeId();

	/**
	 *	Get the required short attribute HostPort.
	 *
	 *	@return	The required short attribute HostPort.
	 */
	short getRequiredHostPort();

	/**
	 *	Get the required ICFSecClusterObj instance referenced by the Cluster key.
	 *
	 *	@return	The required ICFSecClusterObj instance referenced by the Cluster key.
	 */
	ICFSecClusterObj getRequiredOwnerCluster();

	/**
	 *	Get the required ICFSecClusterObj instance referenced by the Cluster key.
	 *
	 *	@return	The required ICFSecClusterObj instance referenced by the Cluster key.
	 */
	ICFSecClusterObj getRequiredOwnerCluster( boolean forceRead );

	/**
	 *	Get the optional ICFSecHostNodeObj instance referenced by the Host key.
	 *
	 *	@return	The optional ICFSecHostNodeObj instance referenced by the Host key.
	 */
	ICFSecHostNodeObj getOptionalContainerHost();

	/**
	 *	Get the optional ICFSecHostNodeObj instance referenced by the Host key.
	 *
	 *	@return	The optional ICFSecHostNodeObj instance referenced by the Host key.
	 */
	ICFSecHostNodeObj getOptionalContainerHost( boolean forceRead );

	/**
	 *	Get the optional ICFSecServiceTypeObj instance referenced by the ServiceType key.
	 *
	 *	@return	The optional ICFSecServiceTypeObj instance referenced by the ServiceType key.
	 */
	ICFSecServiceTypeObj getOptionalParentServiceType();

	/**
	 *	Get the optional ICFSecServiceTypeObj instance referenced by the ServiceType key.
	 *
	 *	@return	The optional ICFSecServiceTypeObj instance referenced by the ServiceType key.
	 */
	ICFSecServiceTypeObj getOptionalParentServiceType( boolean forceRead );

	/**
	 *	Internal use only.
	 */
	void copyPKeyToBuff();

	/**
	 *	Internal use only.
	 */
	void copyBuffToPKey();

}
