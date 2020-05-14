// Description: Java 11 JavaFX Display Element Factory for SecGrpMemb.

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
 *	CFSecJavaFXSecGrpMembFactory JavaFX Display Element Factory
 *	for SecGrpMemb.
 */
public class CFSecJavaFXSecGrpMembFactory
implements ICFSecJavaFXSecGrpMembFactory
{
	protected ICFSecJavaFXSchema javafxSchema = null;

	public CFSecJavaFXSecGrpMembFactory( ICFSecJavaFXSchema argSchema ) {
		final String S_ProcName = "construct-schema";
		if( argSchema == null ) {
			throw new CFLibNullArgumentException( this.getClass(),
				S_ProcName,
				1,
				"argSchema" );
		}
		javafxSchema = argSchema;
	}

	public CFGridPane newAttrPane( ICFFormManager formManager, ICFSecSecGrpMembObj argFocus ) {
		CFSecJavaFXSecGrpMembAttrPane retnew = new CFSecJavaFXSecGrpMembAttrPane( formManager, javafxSchema, argFocus );
		return( retnew );
	}

	public CFBorderPane newListPane( ICFFormManager formManager,
		ICFSecSecGroupObj argContainer,
		ICFSecSecGrpMembObj argFocus,
		ICFSecJavaFXSecGrpMembPageCallback argPageCallback,
		ICFRefreshCallback refreshCallback,
		boolean sortByChain )
	{
		CFSecJavaFXSecGrpMembListPane retnew = new CFSecJavaFXSecGrpMembListPane( formManager,
			javafxSchema,
			argContainer,
			argFocus,
			argPageCallback,
			refreshCallback,
			sortByChain );
		return( retnew );
	}

	public CFBorderPane newPickerPane( ICFFormManager formManager,
		ICFSecSecGrpMembObj argFocus,
		ICFSecSecGroupObj argContainer,
		ICFSecJavaFXSecGrpMembPageCallback argPageCallback,
		ICFSecJavaFXSecGrpMembChosen whenChosen )
	{
		CFSecJavaFXSecGrpMembPickerPane retnew = new CFSecJavaFXSecGrpMembPickerPane( formManager,
			javafxSchema,
			argFocus,
			argContainer,
			argPageCallback,
			whenChosen );
		return( retnew );
	}

	public CFTabPane newEltTabPane( ICFFormManager formManager, ICFSecSecGrpMembObj argFocus ) {
		CFSecJavaFXSecGrpMembEltTabPane retnew = new CFSecJavaFXSecGrpMembEltTabPane( formManager, javafxSchema, argFocus );
		return( retnew );
	}

	public CFSplitPane newAddPane( ICFFormManager formManager, ICFSecSecGrpMembObj argFocus ) {
		CFSecJavaFXSecGrpMembAddPane retnew = new CFSecJavaFXSecGrpMembAddPane( formManager, javafxSchema, argFocus );
		return( retnew );
	}

	public CFSplitPane newViewEditPane( ICFFormManager formManager, ICFSecSecGrpMembObj argFocus ) {
		CFSecJavaFXSecGrpMembViewEditPane retnew = new CFSecJavaFXSecGrpMembViewEditPane( formManager, javafxSchema, argFocus );
		return( retnew );
	}

	public CFBorderPane newAskDeleteForm( ICFFormManager formManager, ICFSecSecGrpMembObj argFocus, ICFDeleteCallback callback ) {
		CFSecJavaFXSecGrpMembAskDeleteForm retnew = new CFSecJavaFXSecGrpMembAskDeleteForm( formManager, javafxSchema, argFocus, callback );
		return( retnew );
	}

	public CFBorderPane newPickerForm( ICFFormManager formManager,
		ICFSecSecGrpMembObj argFocus,
		ICFSecSecGroupObj argContainer,
		ICFSecJavaFXSecGrpMembPageCallback argPageCallback,
		ICFSecJavaFXSecGrpMembChosen whenChosen )
	{
		CFSecJavaFXSecGrpMembPickerForm retnew = new CFSecJavaFXSecGrpMembPickerForm( formManager,
			javafxSchema,
			argFocus,
			argContainer,
			argPageCallback,
			whenChosen );
		return( retnew );
	}

	public CFBorderPane newAddForm( ICFFormManager formManager, ICFSecSecGrpMembObj argFocus, ICFFormClosedCallback closeCallback, boolean allowSave ) {
		CFSecJavaFXSecGrpMembAddForm retnew = new CFSecJavaFXSecGrpMembAddForm( formManager, javafxSchema, argFocus, closeCallback, allowSave );
		return( retnew );
	}

	public CFBorderPane newViewEditForm( ICFFormManager formManager, ICFSecSecGrpMembObj argFocus, ICFFormClosedCallback closeCallback, boolean cameFromAdd ) {
		CFSecJavaFXSecGrpMembViewEditForm retnew = new CFSecJavaFXSecGrpMembViewEditForm( formManager, javafxSchema, argFocus, closeCallback, cameFromAdd );
		return( retnew );
	}
}
