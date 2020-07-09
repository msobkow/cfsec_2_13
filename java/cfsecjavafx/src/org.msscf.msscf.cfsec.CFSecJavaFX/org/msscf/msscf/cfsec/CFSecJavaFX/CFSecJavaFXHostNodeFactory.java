// Description: Java 11 JavaFX Display Element Factory for HostNode.

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
import com.github.msobkow.cflib.CFLib.*;
import com.github.msobkow.cflib.CFLib.JavaFX.*;
import org.apache.commons.codec.binary.Base64;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfsec.CFSecObj.*;

/**
 *	CFSecJavaFXHostNodeFactory JavaFX Display Element Factory
 *	for HostNode.
 */
public class CFSecJavaFXHostNodeFactory
implements ICFSecJavaFXHostNodeFactory
{
	protected ICFSecJavaFXSchema javafxSchema = null;

	public CFSecJavaFXHostNodeFactory( ICFSecJavaFXSchema argSchema ) {
		final String S_ProcName = "construct-schema";
		if( argSchema == null ) {
			throw new CFLibNullArgumentException( this.getClass(),
				S_ProcName,
				1,
				"argSchema" );
		}
		javafxSchema = argSchema;
	}

	public CFGridPane newAttrPane( ICFFormManager formManager, ICFSecHostNodeObj argFocus ) {
		CFSecJavaFXHostNodeAttrPane retnew = new CFSecJavaFXHostNodeAttrPane( formManager, javafxSchema, argFocus );
		return( retnew );
	}

	public CFBorderPane newListPane( ICFFormManager formManager,
		ICFSecClusterObj argContainer,
		ICFSecHostNodeObj argFocus,
		ICFSecJavaFXHostNodePageCallback argPageCallback,
		ICFRefreshCallback refreshCallback,
		boolean sortByChain )
	{
		CFSecJavaFXHostNodeListPane retnew = new CFSecJavaFXHostNodeListPane( formManager,
			javafxSchema,
			argContainer,
			argFocus,
			argPageCallback,
			refreshCallback,
			sortByChain );
		return( retnew );
	}

	public CFBorderPane newPickerPane( ICFFormManager formManager,
		ICFSecHostNodeObj argFocus,
		ICFSecClusterObj argContainer,
		ICFSecJavaFXHostNodePageCallback argPageCallback,
		ICFSecJavaFXHostNodeChosen whenChosen )
	{
		CFSecJavaFXHostNodePickerPane retnew = new CFSecJavaFXHostNodePickerPane( formManager,
			javafxSchema,
			argFocus,
			argContainer,
			argPageCallback,
			whenChosen );
		return( retnew );
	}

	public CFTabPane newEltTabPane( ICFFormManager formManager, ICFSecHostNodeObj argFocus ) {
		CFSecJavaFXHostNodeEltTabPane retnew = new CFSecJavaFXHostNodeEltTabPane( formManager, javafxSchema, argFocus );
		return( retnew );
	}

	public CFSplitPane newAddPane( ICFFormManager formManager, ICFSecHostNodeObj argFocus ) {
		CFSecJavaFXHostNodeAddPane retnew = new CFSecJavaFXHostNodeAddPane( formManager, javafxSchema, argFocus );
		return( retnew );
	}

	public CFSplitPane newViewEditPane( ICFFormManager formManager, ICFSecHostNodeObj argFocus ) {
		CFSecJavaFXHostNodeViewEditPane retnew = new CFSecJavaFXHostNodeViewEditPane( formManager, javafxSchema, argFocus );
		return( retnew );
	}

	public CFBorderPane newAskDeleteForm( ICFFormManager formManager, ICFSecHostNodeObj argFocus, ICFDeleteCallback callback ) {
		CFSecJavaFXHostNodeAskDeleteForm retnew = new CFSecJavaFXHostNodeAskDeleteForm( formManager, javafxSchema, argFocus, callback );
		return( retnew );
	}

	public CFBorderPane newFinderForm( ICFFormManager formManager ) {
		CFSecJavaFXHostNodeFinderForm retnew = new CFSecJavaFXHostNodeFinderForm( formManager, javafxSchema );
		return( retnew );
	}

	public CFBorderPane newPickerForm( ICFFormManager formManager,
		ICFSecHostNodeObj argFocus,
		ICFSecClusterObj argContainer,
		ICFSecJavaFXHostNodePageCallback argPageCallback,
		ICFSecJavaFXHostNodeChosen whenChosen )
	{
		CFSecJavaFXHostNodePickerForm retnew = new CFSecJavaFXHostNodePickerForm( formManager,
			javafxSchema,
			argFocus,
			argContainer,
			argPageCallback,
			whenChosen );
		return( retnew );
	}

	public CFBorderPane newAddForm( ICFFormManager formManager, ICFSecHostNodeObj argFocus, ICFFormClosedCallback closeCallback, boolean allowSave ) {
		CFSecJavaFXHostNodeAddForm retnew = new CFSecJavaFXHostNodeAddForm( formManager, javafxSchema, argFocus, closeCallback, allowSave );
		return( retnew );
	}

	public CFBorderPane newViewEditForm( ICFFormManager formManager, ICFSecHostNodeObj argFocus, ICFFormClosedCallback closeCallback, boolean cameFromAdd ) {
		CFSecJavaFXHostNodeViewEditForm retnew = new CFSecJavaFXHostNodeViewEditForm( formManager, javafxSchema, argFocus, closeCallback, cameFromAdd );
		return( retnew );
	}
}
