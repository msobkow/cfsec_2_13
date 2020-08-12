// Description: Java 11 Object interface for CFSec ISOCtryCcy.

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

public interface ICFSecISOCtryCcyObj
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
	 *	Realise this instance of a ISOCtryCcy.
	 *
	 *	@return	CFSecISOCtryCcyObj instance which should be subsequently referenced.
	 */
	ICFSecISOCtryCcyObj realise();

	/**
	 *	Forget this instance from the cache.
	 *	<p>
	 *	This method should only be invoked by implementation internals.
	 */
	void forget();

	/**
	 *	Re-read this instance by it's primary key.
	 *
	 *	@return	ICFSecISOCtryCcyObj the reference to the cached or read (realised) instance.
	 */
	ICFSecISOCtryCcyObj read();

	/**
	 *	Re-read this instance by it's primary key.
	 *
	 *	@return	ICFSecISOCtryCcyObj the reference to the cached or read (realised) instance.
	 */
	ICFSecISOCtryCcyObj read( boolean forceRead );

	/**
	 *	Initialize and return a locked edition of this ISOCtryCcy instance.
	 *
	 *	@return	The newly locked ICFSecISOCtryCcyEditObj edition of this instance.
	 */
	ICFSecISOCtryCcyEditObj beginEdit();

	/**
	 *	End this edition of this ISOCtryCcy instance.
	 *
	 *	@throws	CFLibNotSupportedException if you try to end a read-only view.
	 */
	void endEdit();

	/**
	 *	Get the current edition of this ISOCtryCcy instance.
	 *
	 *	@return	The ICFSecISOCtryCcyEditObj edition of this instance.
	 */
	ICFSecISOCtryCcyEditObj getEdit();

	/**
	 *	Get the current edition of this ISOCtryCcy instance as a ICFSecISOCtryCcyEditObj.
	 *
	 *	@return	The ICFSecISOCtryCcyEditObj edition of this instance.
	 */
	ICFSecISOCtryCcyEditObj getEditAsISOCtryCcy();

	/**
	 *	Get the ICFSecISOCtryCcyTableObj table cache which manages this instance.
	 *
	 *	@return	ICFSecISOCtryCcyTableObj table cache which manages this instance.
	 */
	ICFSecISOCtryCcyTableObj getISOCtryCcyTable();

	/**
	 *	Get the ICFSecSchemaObj schema cache which manages this instance.
	 *
	 *	@return	ICFSecSchemaObj schema cache which manages this instance.
	 */
	ICFSecSchemaObj getSchema();

	/**
	 *	Get the CFSecISOCtryCcyBuff instance which currently backs this instance.
	 *	<p>
	 *	This value <i>will</i> change for read-only instances, so you should
	 *	not hold on to the value as a reference anywhere outside the current call stack.
	 *
	 *	@return	CFSecISOCtryCcyBuff instance which currently backs this object.
	 */
	CFSecISOCtryCcyBuff getBuff();

	/**
	 *	Internal use only.
	 */
	void setBuff( CFSecISOCtryCcyBuff value );

	/**
	 *	Get the CFSecISOCtryCcyBuff instance which currently backs this instance.
	 *	<p>
	 *	This value <i>will</i> change for read-only instances, so you should
	 *	not hold on to the value as a reference anywhere outside the current call stack.
	 *
	 *	@return	CFSecISOCtryCcyBuff instance which currently backs this object.
	 */
	CFSecISOCtryCcyBuff getISOCtryCcyBuff();

	/**
	 *	Get the primary key of this instance.
	 *
	 *	@return	CFSecISOCtryCcyPKey primary key for this instance.
	 */
	CFSecISOCtryCcyPKey getPKey();

	/**
	 *	Set the primary key of this instance.
	 *	<p>
	 *	This method should only be invoked by implementation internals.
	 *
	 *	@param CFSecISOCtryCcyPKey primary key value for this instance.
	 */
	void setPKey( CFSecISOCtryCcyPKey value );

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
	 *	Get the required short attribute ISOCtryId.
	 *
	 *	@return	The required short attribute ISOCtryId.
	 */
	short getRequiredISOCtryId();

	/**
	 *	Get the required short attribute ISOCcyId.
	 *
	 *	@return	The required short attribute ISOCcyId.
	 */
	short getRequiredISOCcyId();

	/**
	 *	Get the required ICFSecISOCtryObj instance referenced by the Ctry key.
	 *
	 *	@return	The required ICFSecISOCtryObj instance referenced by the Ctry key.
	 */
	ICFSecISOCtryObj getRequiredContainerCtry();

	/**
	 *	Get the required ICFSecISOCtryObj instance referenced by the Ctry key.
	 *
	 *	@return	The required ICFSecISOCtryObj instance referenced by the Ctry key.
	 */
	ICFSecISOCtryObj getRequiredContainerCtry( boolean forceRead );

	/**
	 *	Get the required ICFSecISOCcyObj instance referenced by the Ccy key.
	 *
	 *	@return	The required ICFSecISOCcyObj instance referenced by the Ccy key.
	 */
	ICFSecISOCcyObj getRequiredParentCcy();

	/**
	 *	Get the required ICFSecISOCcyObj instance referenced by the Ccy key.
	 *
	 *	@return	The required ICFSecISOCcyObj instance referenced by the Ccy key.
	 */
	ICFSecISOCcyObj getRequiredParentCcy( boolean forceRead );

	/**
	 *	Internal use only.
	 */
	void copyPKeyToBuff();

	/**
	 *	Internal use only.
	 */
	void copyBuffToPKey();

}
