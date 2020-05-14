// Description: Java 11 JavaFX Display Element Factory for ISOCtry.

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
 *	CFSecJavaFXISOCtryFactory JavaFX Display Element Factory
 *	for ISOCtry.
 */
public class CFSecJavaFXISOCtryFactory
implements ICFSecJavaFXISOCtryFactory
{
	protected ICFSecJavaFXSchema javafxSchema = null;

	public CFSecJavaFXISOCtryFactory( ICFSecJavaFXSchema argSchema ) {
		final String S_ProcName = "construct-schema";
		if( argSchema == null ) {
			throw new CFLibNullArgumentException( this.getClass(),
				S_ProcName,
				1,
				"argSchema" );
		}
		javafxSchema = argSchema;
	}

	public CFGridPane newAttrPane( ICFFormManager formManager, ICFSecISOCtryObj argFocus ) {
		CFSecJavaFXISOCtryAttrPane retnew = new CFSecJavaFXISOCtryAttrPane( formManager, javafxSchema, argFocus );
		return( retnew );
	}

	public CFBorderPane newListPane( ICFFormManager formManager,
		ICFLibAnyObj argContainer,
		ICFSecISOCtryObj argFocus,
		Collection<ICFSecISOCtryObj> argDataCollection,
		ICFRefreshCallback refreshCallback,
		boolean sortByChain )
	{
		CFSecJavaFXISOCtryListPane retnew = new CFSecJavaFXISOCtryListPane( formManager,
			javafxSchema,
			argContainer,
			argFocus,
			argDataCollection,
			refreshCallback,
			sortByChain );
		return( retnew );
	}

	public CFBorderPane newPickerPane( ICFFormManager formManager,
		ICFSecISOCtryObj argFocus,
		ICFLibAnyObj argContainer,
		Collection<ICFSecISOCtryObj> argDataCollection,
		ICFSecJavaFXISOCtryChosen whenChosen )
	{
		CFSecJavaFXISOCtryPickerPane retnew = new CFSecJavaFXISOCtryPickerPane( formManager,
			javafxSchema,
			argFocus,
			argContainer,
			argDataCollection,
			whenChosen );
		return( retnew );
	}

	public CFTabPane newEltTabPane( ICFFormManager formManager, ICFSecISOCtryObj argFocus ) {
		CFSecJavaFXISOCtryEltTabPane retnew = new CFSecJavaFXISOCtryEltTabPane( formManager, javafxSchema, argFocus );
		return( retnew );
	}

	public CFSplitPane newAddPane( ICFFormManager formManager, ICFSecISOCtryObj argFocus ) {
		CFSecJavaFXISOCtryAddPane retnew = new CFSecJavaFXISOCtryAddPane( formManager, javafxSchema, argFocus );
		return( retnew );
	}

	public CFSplitPane newViewEditPane( ICFFormManager formManager, ICFSecISOCtryObj argFocus ) {
		CFSecJavaFXISOCtryViewEditPane retnew = new CFSecJavaFXISOCtryViewEditPane( formManager, javafxSchema, argFocus );
		return( retnew );
	}

	public CFBorderPane newAskDeleteForm( ICFFormManager formManager, ICFSecISOCtryObj argFocus, ICFDeleteCallback callback ) {
		CFSecJavaFXISOCtryAskDeleteForm retnew = new CFSecJavaFXISOCtryAskDeleteForm( formManager, javafxSchema, argFocus, callback );
		return( retnew );
	}

	public CFBorderPane newFinderForm( ICFFormManager formManager ) {
		CFSecJavaFXISOCtryFinderForm retnew = new CFSecJavaFXISOCtryFinderForm( formManager, javafxSchema );
		return( retnew );
	}

	public CFBorderPane newPickerForm( ICFFormManager formManager,
		ICFSecISOCtryObj argFocus,
		ICFLibAnyObj argContainer,
		Collection<ICFSecISOCtryObj> argDataCollection,
		ICFSecJavaFXISOCtryChosen whenChosen )
	{
		CFSecJavaFXISOCtryPickerForm retnew = new CFSecJavaFXISOCtryPickerForm( formManager,
			javafxSchema,
			argFocus,
			argContainer,
			argDataCollection,
			whenChosen );
		return( retnew );
	}

	public CFBorderPane newAddForm( ICFFormManager formManager, ICFSecISOCtryObj argFocus, ICFFormClosedCallback closeCallback, boolean allowSave ) {
		CFSecJavaFXISOCtryAddForm retnew = new CFSecJavaFXISOCtryAddForm( formManager, javafxSchema, argFocus, closeCallback, allowSave );
		return( retnew );
	}

	public CFBorderPane newViewEditForm( ICFFormManager formManager, ICFSecISOCtryObj argFocus, ICFFormClosedCallback closeCallback, boolean cameFromAdd ) {
		CFSecJavaFXISOCtryViewEditForm retnew = new CFSecJavaFXISOCtryViewEditForm( formManager, javafxSchema, argFocus, closeCallback, cameFromAdd );
		return( retnew );
	}
}
