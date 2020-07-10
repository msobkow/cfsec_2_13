// Description: Java 11 JavaFX Display Element Factory for SecGroup.

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
 *	CFSecJavaFXSecGroupFactory JavaFX Display Element Factory
 *	for SecGroup.
 */
public class CFSecJavaFXSecGroupFactory
implements ICFSecJavaFXSecGroupFactory
{
	protected ICFSecJavaFXSchema javafxSchema = null;

	public CFSecJavaFXSecGroupFactory( ICFSecJavaFXSchema argSchema ) {
		final String S_ProcName = "construct-schema";
		if( argSchema == null ) {
			throw new CFLibNullArgumentException( this.getClass(),
				S_ProcName,
				1,
				"argSchema" );
		}
		javafxSchema = argSchema;
	}

	public CFGridPane newAttrPane( ICFFormManager formManager, ICFSecSecGroupObj argFocus ) {
		CFSecJavaFXSecGroupAttrPane retnew = new CFSecJavaFXSecGroupAttrPane( formManager, javafxSchema, argFocus );
		return( retnew );
	}

	public CFBorderPane newListPane( ICFFormManager formManager,
		ICFSecClusterObj argContainer,
		ICFSecSecGroupObj argFocus,
		Collection<ICFSecSecGroupObj> argDataCollection,
		ICFRefreshCallback refreshCallback,
		boolean sortByChain )
	{
		CFSecJavaFXSecGroupListPane retnew = new CFSecJavaFXSecGroupListPane( formManager,
			javafxSchema,
			argContainer,
			argFocus,
			argDataCollection,
			refreshCallback,
			sortByChain );
		return( retnew );
	}

	public CFBorderPane newPickerPane( ICFFormManager formManager,
		ICFSecSecGroupObj argFocus,
		ICFSecClusterObj argContainer,
		Collection<ICFSecSecGroupObj> argDataCollection,
		ICFSecJavaFXSecGroupChosen whenChosen )
	{
		CFSecJavaFXSecGroupPickerPane retnew = new CFSecJavaFXSecGroupPickerPane( formManager,
			javafxSchema,
			argFocus,
			argContainer,
			argDataCollection,
			whenChosen );
		return( retnew );
	}

	public CFTabPane newEltTabPane( ICFFormManager formManager, ICFSecSecGroupObj argFocus ) {
		CFSecJavaFXSecGroupEltTabPane retnew = new CFSecJavaFXSecGroupEltTabPane( formManager, javafxSchema, argFocus );
		return( retnew );
	}

	public CFSplitPane newAddPane( ICFFormManager formManager, ICFSecSecGroupObj argFocus ) {
		CFSecJavaFXSecGroupAddPane retnew = new CFSecJavaFXSecGroupAddPane( formManager, javafxSchema, argFocus );
		return( retnew );
	}

	public CFSplitPane newViewEditPane( ICFFormManager formManager, ICFSecSecGroupObj argFocus ) {
		CFSecJavaFXSecGroupViewEditPane retnew = new CFSecJavaFXSecGroupViewEditPane( formManager, javafxSchema, argFocus );
		return( retnew );
	}

	public CFBorderPane newAskDeleteForm( ICFFormManager formManager, ICFSecSecGroupObj argFocus, ICFDeleteCallback callback ) {
		CFSecJavaFXSecGroupAskDeleteForm retnew = new CFSecJavaFXSecGroupAskDeleteForm( formManager, javafxSchema, argFocus, callback );
		return( retnew );
	}

	public CFBorderPane newFinderForm( ICFFormManager formManager ) {
		CFSecJavaFXSecGroupFinderForm retnew = new CFSecJavaFXSecGroupFinderForm( formManager, javafxSchema );
		return( retnew );
	}

	public CFBorderPane newPickerForm( ICFFormManager formManager,
		ICFSecSecGroupObj argFocus,
		ICFSecClusterObj argContainer,
		Collection<ICFSecSecGroupObj> argDataCollection,
		ICFSecJavaFXSecGroupChosen whenChosen )
	{
		CFSecJavaFXSecGroupPickerForm retnew = new CFSecJavaFXSecGroupPickerForm( formManager,
			javafxSchema,
			argFocus,
			argContainer,
			argDataCollection,
			whenChosen );
		return( retnew );
	}

	public CFBorderPane newAddForm( ICFFormManager formManager, ICFSecSecGroupObj argFocus, ICFFormClosedCallback closeCallback, boolean allowSave ) {
		CFSecJavaFXSecGroupAddForm retnew = new CFSecJavaFXSecGroupAddForm( formManager, javafxSchema, argFocus, closeCallback, allowSave );
		return( retnew );
	}

	public CFBorderPane newViewEditForm( ICFFormManager formManager, ICFSecSecGroupObj argFocus, ICFFormClosedCallback closeCallback, boolean cameFromAdd ) {
		CFSecJavaFXSecGroupViewEditForm retnew = new CFSecJavaFXSecGroupViewEditForm( formManager, javafxSchema, argFocus, closeCallback, cameFromAdd );
		return( retnew );
	}
}
