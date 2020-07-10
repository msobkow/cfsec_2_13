// Description: Java 11 JavaFX Display Element Factory for SecApp.

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
 *	CFSecJavaFXSecAppFactory JavaFX Display Element Factory
 *	for SecApp.
 */
public class CFSecJavaFXSecAppFactory
implements ICFSecJavaFXSecAppFactory
{
	protected ICFSecJavaFXSchema javafxSchema = null;

	public CFSecJavaFXSecAppFactory( ICFSecJavaFXSchema argSchema ) {
		final String S_ProcName = "construct-schema";
		if( argSchema == null ) {
			throw new CFLibNullArgumentException( this.getClass(),
				S_ProcName,
				1,
				"argSchema" );
		}
		javafxSchema = argSchema;
	}

	public CFGridPane newAttrPane( ICFFormManager formManager, ICFSecSecAppObj argFocus ) {
		CFSecJavaFXSecAppAttrPane retnew = new CFSecJavaFXSecAppAttrPane( formManager, javafxSchema, argFocus );
		return( retnew );
	}

	public CFBorderPane newListPane( ICFFormManager formManager,
		ICFSecClusterObj argContainer,
		ICFSecSecAppObj argFocus,
		ICFSecJavaFXSecAppPageCallback argPageCallback,
		ICFRefreshCallback refreshCallback,
		boolean sortByChain )
	{
		CFSecJavaFXSecAppListPane retnew = new CFSecJavaFXSecAppListPane( formManager,
			javafxSchema,
			argContainer,
			argFocus,
			argPageCallback,
			refreshCallback,
			sortByChain );
		return( retnew );
	}

	public CFBorderPane newPickerPane( ICFFormManager formManager,
		ICFSecSecAppObj argFocus,
		ICFSecClusterObj argContainer,
		ICFSecJavaFXSecAppPageCallback argPageCallback,
		ICFSecJavaFXSecAppChosen whenChosen )
	{
		CFSecJavaFXSecAppPickerPane retnew = new CFSecJavaFXSecAppPickerPane( formManager,
			javafxSchema,
			argFocus,
			argContainer,
			argPageCallback,
			whenChosen );
		return( retnew );
	}

	public CFTabPane newEltTabPane( ICFFormManager formManager, ICFSecSecAppObj argFocus ) {
		CFSecJavaFXSecAppEltTabPane retnew = new CFSecJavaFXSecAppEltTabPane( formManager, javafxSchema, argFocus );
		return( retnew );
	}

	public CFSplitPane newAddPane( ICFFormManager formManager, ICFSecSecAppObj argFocus ) {
		CFSecJavaFXSecAppAddPane retnew = new CFSecJavaFXSecAppAddPane( formManager, javafxSchema, argFocus );
		return( retnew );
	}

	public CFSplitPane newViewEditPane( ICFFormManager formManager, ICFSecSecAppObj argFocus ) {
		CFSecJavaFXSecAppViewEditPane retnew = new CFSecJavaFXSecAppViewEditPane( formManager, javafxSchema, argFocus );
		return( retnew );
	}

	public CFBorderPane newAskDeleteForm( ICFFormManager formManager, ICFSecSecAppObj argFocus, ICFDeleteCallback callback ) {
		CFSecJavaFXSecAppAskDeleteForm retnew = new CFSecJavaFXSecAppAskDeleteForm( formManager, javafxSchema, argFocus, callback );
		return( retnew );
	}

	public CFBorderPane newFinderForm( ICFFormManager formManager ) {
		CFSecJavaFXSecAppFinderForm retnew = new CFSecJavaFXSecAppFinderForm( formManager, javafxSchema );
		return( retnew );
	}

	public CFBorderPane newPickerForm( ICFFormManager formManager,
		ICFSecSecAppObj argFocus,
		ICFSecClusterObj argContainer,
		ICFSecJavaFXSecAppPageCallback argPageCallback,
		ICFSecJavaFXSecAppChosen whenChosen )
	{
		CFSecJavaFXSecAppPickerForm retnew = new CFSecJavaFXSecAppPickerForm( formManager,
			javafxSchema,
			argFocus,
			argContainer,
			argPageCallback,
			whenChosen );
		return( retnew );
	}

	public CFBorderPane newAddForm( ICFFormManager formManager, ICFSecSecAppObj argFocus, ICFFormClosedCallback closeCallback, boolean allowSave ) {
		CFSecJavaFXSecAppAddForm retnew = new CFSecJavaFXSecAppAddForm( formManager, javafxSchema, argFocus, closeCallback, allowSave );
		return( retnew );
	}

	public CFBorderPane newViewEditForm( ICFFormManager formManager, ICFSecSecAppObj argFocus, ICFFormClosedCallback closeCallback, boolean cameFromAdd ) {
		CFSecJavaFXSecAppViewEditForm retnew = new CFSecJavaFXSecAppViewEditForm( formManager, javafxSchema, argFocus, closeCallback, cameFromAdd );
		return( retnew );
	}
}
