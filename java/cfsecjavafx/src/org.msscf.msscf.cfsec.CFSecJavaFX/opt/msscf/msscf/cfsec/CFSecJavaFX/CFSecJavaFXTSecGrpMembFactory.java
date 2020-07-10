// Description: Java 11 JavaFX Display Element Factory for TSecGrpMemb.

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
 *	CFSecJavaFXTSecGrpMembFactory JavaFX Display Element Factory
 *	for TSecGrpMemb.
 */
public class CFSecJavaFXTSecGrpMembFactory
implements ICFSecJavaFXTSecGrpMembFactory
{
	protected ICFSecJavaFXSchema javafxSchema = null;

	public CFSecJavaFXTSecGrpMembFactory( ICFSecJavaFXSchema argSchema ) {
		final String S_ProcName = "construct-schema";
		if( argSchema == null ) {
			throw new CFLibNullArgumentException( this.getClass(),
				S_ProcName,
				1,
				"argSchema" );
		}
		javafxSchema = argSchema;
	}

	public CFGridPane newAttrPane( ICFFormManager formManager, ICFSecTSecGrpMembObj argFocus ) {
		CFSecJavaFXTSecGrpMembAttrPane retnew = new CFSecJavaFXTSecGrpMembAttrPane( formManager, javafxSchema, argFocus );
		return( retnew );
	}

	public CFBorderPane newListPane( ICFFormManager formManager,
		ICFSecTSecGroupObj argContainer,
		ICFSecTSecGrpMembObj argFocus,
		ICFSecJavaFXTSecGrpMembPageCallback argPageCallback,
		ICFRefreshCallback refreshCallback,
		boolean sortByChain )
	{
		CFSecJavaFXTSecGrpMembListPane retnew = new CFSecJavaFXTSecGrpMembListPane( formManager,
			javafxSchema,
			argContainer,
			argFocus,
			argPageCallback,
			refreshCallback,
			sortByChain );
		return( retnew );
	}

	public CFBorderPane newPickerPane( ICFFormManager formManager,
		ICFSecTSecGrpMembObj argFocus,
		ICFSecTSecGroupObj argContainer,
		ICFSecJavaFXTSecGrpMembPageCallback argPageCallback,
		ICFSecJavaFXTSecGrpMembChosen whenChosen )
	{
		CFSecJavaFXTSecGrpMembPickerPane retnew = new CFSecJavaFXTSecGrpMembPickerPane( formManager,
			javafxSchema,
			argFocus,
			argContainer,
			argPageCallback,
			whenChosen );
		return( retnew );
	}

	public CFTabPane newEltTabPane( ICFFormManager formManager, ICFSecTSecGrpMembObj argFocus ) {
		CFSecJavaFXTSecGrpMembEltTabPane retnew = new CFSecJavaFXTSecGrpMembEltTabPane( formManager, javafxSchema, argFocus );
		return( retnew );
	}

	public CFSplitPane newAddPane( ICFFormManager formManager, ICFSecTSecGrpMembObj argFocus ) {
		CFSecJavaFXTSecGrpMembAddPane retnew = new CFSecJavaFXTSecGrpMembAddPane( formManager, javafxSchema, argFocus );
		return( retnew );
	}

	public CFSplitPane newViewEditPane( ICFFormManager formManager, ICFSecTSecGrpMembObj argFocus ) {
		CFSecJavaFXTSecGrpMembViewEditPane retnew = new CFSecJavaFXTSecGrpMembViewEditPane( formManager, javafxSchema, argFocus );
		return( retnew );
	}

	public CFBorderPane newAskDeleteForm( ICFFormManager formManager, ICFSecTSecGrpMembObj argFocus, ICFDeleteCallback callback ) {
		CFSecJavaFXTSecGrpMembAskDeleteForm retnew = new CFSecJavaFXTSecGrpMembAskDeleteForm( formManager, javafxSchema, argFocus, callback );
		return( retnew );
	}

	public CFBorderPane newPickerForm( ICFFormManager formManager,
		ICFSecTSecGrpMembObj argFocus,
		ICFSecTSecGroupObj argContainer,
		ICFSecJavaFXTSecGrpMembPageCallback argPageCallback,
		ICFSecJavaFXTSecGrpMembChosen whenChosen )
	{
		CFSecJavaFXTSecGrpMembPickerForm retnew = new CFSecJavaFXTSecGrpMembPickerForm( formManager,
			javafxSchema,
			argFocus,
			argContainer,
			argPageCallback,
			whenChosen );
		return( retnew );
	}

	public CFBorderPane newAddForm( ICFFormManager formManager, ICFSecTSecGrpMembObj argFocus, ICFFormClosedCallback closeCallback, boolean allowSave ) {
		CFSecJavaFXTSecGrpMembAddForm retnew = new CFSecJavaFXTSecGrpMembAddForm( formManager, javafxSchema, argFocus, closeCallback, allowSave );
		return( retnew );
	}

	public CFBorderPane newViewEditForm( ICFFormManager formManager, ICFSecTSecGrpMembObj argFocus, ICFFormClosedCallback closeCallback, boolean cameFromAdd ) {
		CFSecJavaFXTSecGrpMembViewEditForm retnew = new CFSecJavaFXTSecGrpMembViewEditForm( formManager, javafxSchema, argFocus, closeCallback, cameFromAdd );
		return( retnew );
	}
}
