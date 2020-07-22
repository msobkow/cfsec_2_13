// Description: Java 11 JavaFX Display Element Factory for TSecGroup.

/*
 *	org.msscf.msscf.CFSec
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

package org.msscf.msscf.cfsec.CFSecJavaFX;

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.msscf.msscf.cflib.CFLib.*;
import org.msscf.msscf.cflib.CFLib.JavaFX.*;
import org.apache.commons.codec.binary.Base64;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfsec.CFSecObj.*;

/**
 *	CFSecJavaFXTSecGroupFactory JavaFX Display Element Factory
 *	for TSecGroup.
 */
public class CFSecJavaFXTSecGroupFactory
implements ICFSecJavaFXTSecGroupFactory
{
	protected ICFSecJavaFXSchema javafxSchema = null;

	public CFSecJavaFXTSecGroupFactory( ICFSecJavaFXSchema argSchema ) {
		final String S_ProcName = "construct-schema";
		if( argSchema == null ) {
			throw new CFLibNullArgumentException( this.getClass(),
				S_ProcName,
				1,
				"argSchema" );
		}
		javafxSchema = argSchema;
	}

	public CFGridPane newAttrPane( ICFFormManager formManager, ICFSecTSecGroupObj argFocus ) {
		CFSecJavaFXTSecGroupAttrPane retnew = new CFSecJavaFXTSecGroupAttrPane( formManager, javafxSchema, argFocus );
		return( retnew );
	}

	public CFBorderPane newListPane( ICFFormManager formManager,
		ICFSecTenantObj argContainer,
		ICFSecTSecGroupObj argFocus,
		Collection<ICFSecTSecGroupObj> argDataCollection,
		ICFRefreshCallback refreshCallback,
		boolean sortByChain )
	{
		CFSecJavaFXTSecGroupListPane retnew = new CFSecJavaFXTSecGroupListPane( formManager,
			javafxSchema,
			argContainer,
			argFocus,
			argDataCollection,
			refreshCallback,
			sortByChain );
		return( retnew );
	}

	public CFBorderPane newPickerPane( ICFFormManager formManager,
		ICFSecTSecGroupObj argFocus,
		ICFSecTenantObj argContainer,
		Collection<ICFSecTSecGroupObj> argDataCollection,
		ICFSecJavaFXTSecGroupChosen whenChosen )
	{
		CFSecJavaFXTSecGroupPickerPane retnew = new CFSecJavaFXTSecGroupPickerPane( formManager,
			javafxSchema,
			argFocus,
			argContainer,
			argDataCollection,
			whenChosen );
		return( retnew );
	}

	public CFTabPane newEltTabPane( ICFFormManager formManager, ICFSecTSecGroupObj argFocus ) {
		CFSecJavaFXTSecGroupEltTabPane retnew = new CFSecJavaFXTSecGroupEltTabPane( formManager, javafxSchema, argFocus );
		return( retnew );
	}

	public CFSplitPane newAddPane( ICFFormManager formManager, ICFSecTSecGroupObj argFocus ) {
		CFSecJavaFXTSecGroupAddPane retnew = new CFSecJavaFXTSecGroupAddPane( formManager, javafxSchema, argFocus );
		return( retnew );
	}

	public CFSplitPane newViewEditPane( ICFFormManager formManager, ICFSecTSecGroupObj argFocus ) {
		CFSecJavaFXTSecGroupViewEditPane retnew = new CFSecJavaFXTSecGroupViewEditPane( formManager, javafxSchema, argFocus );
		return( retnew );
	}

	public CFBorderPane newAskDeleteForm( ICFFormManager formManager, ICFSecTSecGroupObj argFocus, ICFDeleteCallback callback ) {
		CFSecJavaFXTSecGroupAskDeleteForm retnew = new CFSecJavaFXTSecGroupAskDeleteForm( formManager, javafxSchema, argFocus, callback );
		return( retnew );
	}

	public CFBorderPane newFinderForm( ICFFormManager formManager ) {
		CFSecJavaFXTSecGroupFinderForm retnew = new CFSecJavaFXTSecGroupFinderForm( formManager, javafxSchema );
		return( retnew );
	}

	public CFBorderPane newPickerForm( ICFFormManager formManager,
		ICFSecTSecGroupObj argFocus,
		ICFSecTenantObj argContainer,
		Collection<ICFSecTSecGroupObj> argDataCollection,
		ICFSecJavaFXTSecGroupChosen whenChosen )
	{
		CFSecJavaFXTSecGroupPickerForm retnew = new CFSecJavaFXTSecGroupPickerForm( formManager,
			javafxSchema,
			argFocus,
			argContainer,
			argDataCollection,
			whenChosen );
		return( retnew );
	}

	public CFBorderPane newAddForm( ICFFormManager formManager, ICFSecTSecGroupObj argFocus, ICFFormClosedCallback closeCallback, boolean allowSave ) {
		CFSecJavaFXTSecGroupAddForm retnew = new CFSecJavaFXTSecGroupAddForm( formManager, javafxSchema, argFocus, closeCallback, allowSave );
		return( retnew );
	}

	public CFBorderPane newViewEditForm( ICFFormManager formManager, ICFSecTSecGroupObj argFocus, ICFFormClosedCallback closeCallback, boolean cameFromAdd ) {
		CFSecJavaFXTSecGroupViewEditForm retnew = new CFSecJavaFXTSecGroupViewEditForm( formManager, javafxSchema, argFocus, closeCallback, cameFromAdd );
		return( retnew );
	}
}