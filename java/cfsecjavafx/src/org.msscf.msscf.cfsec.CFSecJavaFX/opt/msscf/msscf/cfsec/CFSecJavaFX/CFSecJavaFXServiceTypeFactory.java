// Description: Java 11 JavaFX Display Element Factory for ServiceType.

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
 *	CFSecJavaFXServiceTypeFactory JavaFX Display Element Factory
 *	for ServiceType.
 */
public class CFSecJavaFXServiceTypeFactory
implements ICFSecJavaFXServiceTypeFactory
{
	protected ICFSecJavaFXSchema javafxSchema = null;

	public CFSecJavaFXServiceTypeFactory( ICFSecJavaFXSchema argSchema ) {
		final String S_ProcName = "construct-schema";
		if( argSchema == null ) {
			throw new CFLibNullArgumentException( this.getClass(),
				S_ProcName,
				1,
				"argSchema" );
		}
		javafxSchema = argSchema;
	}

	public CFGridPane newAttrPane( ICFFormManager formManager, ICFSecServiceTypeObj argFocus ) {
		CFSecJavaFXServiceTypeAttrPane retnew = new CFSecJavaFXServiceTypeAttrPane( formManager, javafxSchema, argFocus );
		return( retnew );
	}

	public CFBorderPane newListPane( ICFFormManager formManager,
		ICFLibAnyObj argContainer,
		ICFSecServiceTypeObj argFocus,
		Collection<ICFSecServiceTypeObj> argDataCollection,
		ICFRefreshCallback refreshCallback,
		boolean sortByChain )
	{
		CFSecJavaFXServiceTypeListPane retnew = new CFSecJavaFXServiceTypeListPane( formManager,
			javafxSchema,
			argContainer,
			argFocus,
			argDataCollection,
			refreshCallback,
			sortByChain );
		return( retnew );
	}

	public CFBorderPane newPickerPane( ICFFormManager formManager,
		ICFSecServiceTypeObj argFocus,
		ICFLibAnyObj argContainer,
		Collection<ICFSecServiceTypeObj> argDataCollection,
		ICFSecJavaFXServiceTypeChosen whenChosen )
	{
		CFSecJavaFXServiceTypePickerPane retnew = new CFSecJavaFXServiceTypePickerPane( formManager,
			javafxSchema,
			argFocus,
			argContainer,
			argDataCollection,
			whenChosen );
		return( retnew );
	}

	public CFTabPane newEltTabPane( ICFFormManager formManager, ICFSecServiceTypeObj argFocus ) {
		CFSecJavaFXServiceTypeEltTabPane retnew = new CFSecJavaFXServiceTypeEltTabPane( formManager, javafxSchema, argFocus );
		return( retnew );
	}

	public CFSplitPane newAddPane( ICFFormManager formManager, ICFSecServiceTypeObj argFocus ) {
		CFSecJavaFXServiceTypeAddPane retnew = new CFSecJavaFXServiceTypeAddPane( formManager, javafxSchema, argFocus );
		return( retnew );
	}

	public CFSplitPane newViewEditPane( ICFFormManager formManager, ICFSecServiceTypeObj argFocus ) {
		CFSecJavaFXServiceTypeViewEditPane retnew = new CFSecJavaFXServiceTypeViewEditPane( formManager, javafxSchema, argFocus );
		return( retnew );
	}

	public CFBorderPane newAskDeleteForm( ICFFormManager formManager, ICFSecServiceTypeObj argFocus, ICFDeleteCallback callback ) {
		CFSecJavaFXServiceTypeAskDeleteForm retnew = new CFSecJavaFXServiceTypeAskDeleteForm( formManager, javafxSchema, argFocus, callback );
		return( retnew );
	}

	public CFBorderPane newFinderForm( ICFFormManager formManager ) {
		CFSecJavaFXServiceTypeFinderForm retnew = new CFSecJavaFXServiceTypeFinderForm( formManager, javafxSchema );
		return( retnew );
	}

	public CFBorderPane newPickerForm( ICFFormManager formManager,
		ICFSecServiceTypeObj argFocus,
		ICFLibAnyObj argContainer,
		Collection<ICFSecServiceTypeObj> argDataCollection,
		ICFSecJavaFXServiceTypeChosen whenChosen )
	{
		CFSecJavaFXServiceTypePickerForm retnew = new CFSecJavaFXServiceTypePickerForm( formManager,
			javafxSchema,
			argFocus,
			argContainer,
			argDataCollection,
			whenChosen );
		return( retnew );
	}

	public CFBorderPane newAddForm( ICFFormManager formManager, ICFSecServiceTypeObj argFocus, ICFFormClosedCallback closeCallback, boolean allowSave ) {
		CFSecJavaFXServiceTypeAddForm retnew = new CFSecJavaFXServiceTypeAddForm( formManager, javafxSchema, argFocus, closeCallback, allowSave );
		return( retnew );
	}

	public CFBorderPane newViewEditForm( ICFFormManager formManager, ICFSecServiceTypeObj argFocus, ICFFormClosedCallback closeCallback, boolean cameFromAdd ) {
		CFSecJavaFXServiceTypeViewEditForm retnew = new CFSecJavaFXServiceTypeViewEditForm( formManager, javafxSchema, argFocus, closeCallback, cameFromAdd );
		return( retnew );
	}
}
