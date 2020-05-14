// Description: Java 11 JavaFX Display Element Factory for SecGroupForm.

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
 *	CFSecJavaFXSecGroupFormFactory JavaFX Display Element Factory
 *	for SecGroupForm.
 */
public class CFSecJavaFXSecGroupFormFactory
implements ICFSecJavaFXSecGroupFormFactory
{
	protected ICFSecJavaFXSchema javafxSchema = null;

	public CFSecJavaFXSecGroupFormFactory( ICFSecJavaFXSchema argSchema ) {
		final String S_ProcName = "construct-schema";
		if( argSchema == null ) {
			throw new CFLibNullArgumentException( this.getClass(),
				S_ProcName,
				1,
				"argSchema" );
		}
		javafxSchema = argSchema;
	}

	public CFGridPane newAttrPane( ICFFormManager formManager, ICFSecSecGroupFormObj argFocus ) {
		CFSecJavaFXSecGroupFormAttrPane retnew = new CFSecJavaFXSecGroupFormAttrPane( formManager, javafxSchema, argFocus );
		return( retnew );
	}

	public CFBorderPane newListPane( ICFFormManager formManager,
		ICFSecSecGroupObj argContainer,
		ICFSecSecGroupFormObj argFocus,
		ICFSecJavaFXSecGroupFormPageCallback argPageCallback,
		ICFRefreshCallback refreshCallback,
		boolean sortByChain )
	{
		CFSecJavaFXSecGroupFormListPane retnew = new CFSecJavaFXSecGroupFormListPane( formManager,
			javafxSchema,
			argContainer,
			argFocus,
			argPageCallback,
			refreshCallback,
			sortByChain );
		return( retnew );
	}

	public CFBorderPane newPickerPane( ICFFormManager formManager,
		ICFSecSecGroupFormObj argFocus,
		ICFSecSecGroupObj argContainer,
		ICFSecJavaFXSecGroupFormPageCallback argPageCallback,
		ICFSecJavaFXSecGroupFormChosen whenChosen )
	{
		CFSecJavaFXSecGroupFormPickerPane retnew = new CFSecJavaFXSecGroupFormPickerPane( formManager,
			javafxSchema,
			argFocus,
			argContainer,
			argPageCallback,
			whenChosen );
		return( retnew );
	}

	public CFTabPane newEltTabPane( ICFFormManager formManager, ICFSecSecGroupFormObj argFocus ) {
		CFSecJavaFXSecGroupFormEltTabPane retnew = new CFSecJavaFXSecGroupFormEltTabPane( formManager, javafxSchema, argFocus );
		return( retnew );
	}

	public CFSplitPane newAddPane( ICFFormManager formManager, ICFSecSecGroupFormObj argFocus ) {
		CFSecJavaFXSecGroupFormAddPane retnew = new CFSecJavaFXSecGroupFormAddPane( formManager, javafxSchema, argFocus );
		return( retnew );
	}

	public CFSplitPane newViewEditPane( ICFFormManager formManager, ICFSecSecGroupFormObj argFocus ) {
		CFSecJavaFXSecGroupFormViewEditPane retnew = new CFSecJavaFXSecGroupFormViewEditPane( formManager, javafxSchema, argFocus );
		return( retnew );
	}

	public CFBorderPane newAskDeleteForm( ICFFormManager formManager, ICFSecSecGroupFormObj argFocus, ICFDeleteCallback callback ) {
		CFSecJavaFXSecGroupFormAskDeleteForm retnew = new CFSecJavaFXSecGroupFormAskDeleteForm( formManager, javafxSchema, argFocus, callback );
		return( retnew );
	}

	public CFBorderPane newPickerForm( ICFFormManager formManager,
		ICFSecSecGroupFormObj argFocus,
		ICFSecSecGroupObj argContainer,
		ICFSecJavaFXSecGroupFormPageCallback argPageCallback,
		ICFSecJavaFXSecGroupFormChosen whenChosen )
	{
		CFSecJavaFXSecGroupFormPickerForm retnew = new CFSecJavaFXSecGroupFormPickerForm( formManager,
			javafxSchema,
			argFocus,
			argContainer,
			argPageCallback,
			whenChosen );
		return( retnew );
	}

	public CFBorderPane newAddForm( ICFFormManager formManager, ICFSecSecGroupFormObj argFocus, ICFFormClosedCallback closeCallback, boolean allowSave ) {
		CFSecJavaFXSecGroupFormAddForm retnew = new CFSecJavaFXSecGroupFormAddForm( formManager, javafxSchema, argFocus, closeCallback, allowSave );
		return( retnew );
	}

	public CFBorderPane newViewEditForm( ICFFormManager formManager, ICFSecSecGroupFormObj argFocus, ICFFormClosedCallback closeCallback, boolean cameFromAdd ) {
		CFSecJavaFXSecGroupFormViewEditForm retnew = new CFSecJavaFXSecGroupFormViewEditForm( formManager, javafxSchema, argFocus, closeCallback, cameFromAdd );
		return( retnew );
	}
}
