// Description: Java 11 Object interface for CFSec SecApp.

/*
 *	com.github.msobkow.CFSec
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

package com.github.msobkow.cfsec.CFSecObj;

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import com.github.msobkow.cfsec.CFSec.*;
import com.github.msobkow.cflib.CFLib.*;
import com.github.msobkow.cfsec.CFSec.*;

public interface ICFSecSecAppObj
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
	 *	Realise this instance of a SecApp.
	 *
	 *	@return	CFSecSecAppObj instance which should be subsequently referenced.
	 */
	ICFSecSecAppObj realise();

	/**
	 *	Forget this instance from the cache.
	 *	<p>
	 *	This method should only be invoked by implementation internals.
	 */
	void forget();

	/**
	 *	Re-read this instance by it's primary key.
	 *
	 *	@return	ICFSecSecAppObj the reference to the cached or read (realised) instance.
	 */
	ICFSecSecAppObj read();

	/**
	 *	Re-read this instance by it's primary key.
	 *
	 *	@return	ICFSecSecAppObj the reference to the cached or read (realised) instance.
	 */
	ICFSecSecAppObj read( boolean forceRead );

	/**
	 *	Initialize and return a locked edition of this SecApp instance.
	 *
	 *	@return	The newly locked ICFSecSecAppEditObj edition of this instance.
	 */
	ICFSecSecAppEditObj beginEdit();

	/**
	 *	End this edition of this SecApp instance.
	 *
	 *	@throws	CFLibNotSupportedException if you try to end a read-only view.
	 */
	void endEdit();

	/**
	 *	Get the current edition of this SecApp instance.
	 *
	 *	@return	The ICFSecSecAppEditObj edition of this instance.
	 */
	ICFSecSecAppEditObj getEdit();

	/**
	 *	Get the current edition of this SecApp instance as a ICFSecSecAppEditObj.
	 *
	 *	@return	The ICFSecSecAppEditObj edition of this instance.
	 */
	ICFSecSecAppEditObj getEditAsSecApp();

	/**
	 *	Get the ICFSecSecAppTableObj table cache which manages this instance.
	 *
	 *	@return	ICFSecSecAppTableObj table cache which manages this instance.
	 */
	ICFSecSecAppTableObj getSecAppTable();

	/**
	 *	Get the ICFSecSchemaObj schema cache which manages this instance.
	 *
	 *	@return	ICFSecSchemaObj schema cache which manages this instance.
	 */
	ICFSecSchemaObj getSchema();

	/**
	 *	Get the CFSecSecAppBuff instance which currently backs this instance.
	 *	<p>
	 *	This value <i>will</i> change for read-only instances, so you should
	 *	not hold on to the value as a reference anywhere outside the current call stack.
	 *
	 *	@return	CFSecSecAppBuff instance which currently backs this object.
	 */
	CFSecSecAppBuff getBuff();

	/**
	 *	Internal use only.
	 */
	void setBuff( CFSecSecAppBuff value );

	/**
	 *	Get the CFSecSecAppBuff instance which currently backs this instance.
	 *	<p>
	 *	This value <i>will</i> change for read-only instances, so you should
	 *	not hold on to the value as a reference anywhere outside the current call stack.
	 *
	 *	@return	CFSecSecAppBuff instance which currently backs this object.
	 */
	CFSecSecAppBuff getSecAppBuff();

	/**
	 *	Get the primary key of this instance.
	 *
	 *	@return	CFSecSecAppPKey primary key for this instance.
	 */
	CFSecSecAppPKey getPKey();

	/**
	 *	Set the primary key of this instance.
	 *	<p>
	 *	This method should only be invoked by implementation internals.
	 *
	 *	@param CFSecSecAppPKey primary key value for this instance.
	 */
	void setPKey( CFSecSecAppPKey value );

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
	 *	Get the required int attribute SecAppId.
	 *
	 *	@return	The required int attribute SecAppId.
	 */
	int getRequiredSecAppId();

	/**
	 *	Get the required String attribute JEEMountName.
	 *
	 *	@return	The required String attribute JEEMountName.
	 */
	String getRequiredJEEMountName();

	/**
	 *	Get the required ICFSecClusterObj instance referenced by the Cluster key.
	 *
	 *	@return	The required ICFSecClusterObj instance referenced by the Cluster key.
	 */
	ICFSecClusterObj getRequiredContainerCluster();

	/**
	 *	Get the required ICFSecClusterObj instance referenced by the Cluster key.
	 *
	 *	@return	The required ICFSecClusterObj instance referenced by the Cluster key.
	 */
	ICFSecClusterObj getRequiredContainerCluster( boolean forceRead );

	/**
	 *	Get the array of optional ICFSecSecFormObj array of instances referenced by the Form key.
	 *
	 *	@return	The optional ICFSecSecFormObj[] array of instances referenced by the Form key.
	 */
	List<ICFSecSecFormObj> getOptionalComponentsForm();

	/**
	 *	Get the array of optional ICFSecSecFormObj array of instances referenced by the Form key.
	 *
	 *	@return	The optional ICFSecSecFormObj[] array of instances referenced by the Form key.
	 */
	List<ICFSecSecFormObj> getOptionalComponentsForm( boolean forceRead );

	/**
	 *	Internal use only.
	 */
	void copyPKeyToBuff();

	/**
	 *	Internal use only.
	 */
	void copyBuffToPKey();

}
