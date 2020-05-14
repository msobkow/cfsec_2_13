// Description: Java 11 JavaFX Display Element Factory for Tenant.

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

package com.github.msobkow.cfsec.CFSecJavaFX;

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import com.github.msobkow.cflib.CFLib.*;
import com.github.msobkow.cflib.CFLib.JavaFX.*;
import org.apache.commons.codec.binary.Base64;
import com.github.msobkow.cfsec.CFSec.*;
import com.github.msobkow.cfsec.CFSecObj.*;

/**
 *	CFSecJavaFXTenantFactory JavaFX Display Element Factory
 *	for Tenant.
 */
public class CFSecJavaFXTenantFactory
implements ICFSecJavaFXTenantFactory
{
	protected ICFSecJavaFXSchema javafxSchema = null;

	public CFSecJavaFXTenantFactory( ICFSecJavaFXSchema argSchema ) {
		final String S_ProcName = "construct-schema";
		if( argSchema == null ) {
			throw new CFLibNullArgumentException( this.getClass(),
				S_ProcName,
				1,
				"argSchema" );
		}
		javafxSchema = argSchema;
	}

	public CFGridPane newAttrPane( ICFFormManager formManager, ICFSecTenantObj argFocus ) {
		CFSecJavaFXTenantAttrPane retnew = new CFSecJavaFXTenantAttrPane( formManager, javafxSchema, argFocus );
		return( retnew );
	}

	public CFBorderPane newListPane( ICFFormManager formManager,
		ICFSecClusterObj argContainer,
		ICFSecTenantObj argFocus,
		ICFSecJavaFXTenantPageCallback argPageCallback,
		ICFRefreshCallback refreshCallback,
		boolean sortByChain )
	{
		CFSecJavaFXTenantListPane retnew = new CFSecJavaFXTenantListPane( formManager,
			javafxSchema,
			argContainer,
			argFocus,
			argPageCallback,
			refreshCallback,
			sortByChain );
		return( retnew );
	}

	public CFBorderPane newPickerPane( ICFFormManager formManager,
		ICFSecTenantObj argFocus,
		ICFSecClusterObj argContainer,
		ICFSecJavaFXTenantPageCallback argPageCallback,
		ICFSecJavaFXTenantChosen whenChosen )
	{
		CFSecJavaFXTenantPickerPane retnew = new CFSecJavaFXTenantPickerPane( formManager,
			javafxSchema,
			argFocus,
			argContainer,
			argPageCallback,
			whenChosen );
		return( retnew );
	}

	public CFTabPane newEltTabPane( ICFFormManager formManager, ICFSecTenantObj argFocus ) {
		CFSecJavaFXTenantEltTabPane retnew = new CFSecJavaFXTenantEltTabPane( formManager, javafxSchema, argFocus );
		return( retnew );
	}

	public CFSplitPane newAddPane( ICFFormManager formManager, ICFSecTenantObj argFocus ) {
		CFSecJavaFXTenantAddPane retnew = new CFSecJavaFXTenantAddPane( formManager, javafxSchema, argFocus );
		return( retnew );
	}

	public CFSplitPane newViewEditPane( ICFFormManager formManager, ICFSecTenantObj argFocus ) {
		CFSecJavaFXTenantViewEditPane retnew = new CFSecJavaFXTenantViewEditPane( formManager, javafxSchema, argFocus );
		return( retnew );
	}

	public CFBorderPane newAskDeleteForm( ICFFormManager formManager, ICFSecTenantObj argFocus, ICFDeleteCallback callback ) {
		CFSecJavaFXTenantAskDeleteForm retnew = new CFSecJavaFXTenantAskDeleteForm( formManager, javafxSchema, argFocus, callback );
		return( retnew );
	}

	public CFBorderPane newFinderForm( ICFFormManager formManager ) {
		CFSecJavaFXTenantFinderForm retnew = new CFSecJavaFXTenantFinderForm( formManager, javafxSchema );
		return( retnew );
	}

	public CFBorderPane newPickerForm( ICFFormManager formManager,
		ICFSecTenantObj argFocus,
		ICFSecClusterObj argContainer,
		ICFSecJavaFXTenantPageCallback argPageCallback,
		ICFSecJavaFXTenantChosen whenChosen )
	{
		CFSecJavaFXTenantPickerForm retnew = new CFSecJavaFXTenantPickerForm( formManager,
			javafxSchema,
			argFocus,
			argContainer,
			argPageCallback,
			whenChosen );
		return( retnew );
	}

	public CFBorderPane newAddForm( ICFFormManager formManager, ICFSecTenantObj argFocus, ICFFormClosedCallback closeCallback, boolean allowSave ) {
		CFSecJavaFXTenantAddForm retnew = new CFSecJavaFXTenantAddForm( formManager, javafxSchema, argFocus, closeCallback, allowSave );
		return( retnew );
	}

	public CFBorderPane newViewEditForm( ICFFormManager formManager, ICFSecTenantObj argFocus, ICFFormClosedCallback closeCallback, boolean cameFromAdd ) {
		CFSecJavaFXTenantViewEditForm retnew = new CFSecJavaFXTenantViewEditForm( formManager, javafxSchema, argFocus, closeCallback, cameFromAdd );
		return( retnew );
	}
}
