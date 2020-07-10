// Description: Java 11 JavaFX Display Element Factory for Service.

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
 *	CFSecJavaFXServiceFactory JavaFX Display Element Factory
 *	for Service.
 */
public class CFSecJavaFXServiceFactory
implements ICFSecJavaFXServiceFactory
{
	protected ICFSecJavaFXSchema javafxSchema = null;

	public CFSecJavaFXServiceFactory( ICFSecJavaFXSchema argSchema ) {
		final String S_ProcName = "construct-schema";
		if( argSchema == null ) {
			throw new CFLibNullArgumentException( this.getClass(),
				S_ProcName,
				1,
				"argSchema" );
		}
		javafxSchema = argSchema;
	}

	public CFGridPane newAttrPane( ICFFormManager formManager, ICFSecServiceObj argFocus ) {
		CFSecJavaFXServiceAttrPane retnew = new CFSecJavaFXServiceAttrPane( formManager, javafxSchema, argFocus );
		return( retnew );
	}

	public CFBorderPane newListPane( ICFFormManager formManager,
		ICFSecHostNodeObj argContainer,
		ICFSecServiceObj argFocus,
		ICFSecJavaFXServicePageCallback argPageCallback,
		ICFRefreshCallback refreshCallback,
		boolean sortByChain )
	{
		CFSecJavaFXServiceListPane retnew = new CFSecJavaFXServiceListPane( formManager,
			javafxSchema,
			argContainer,
			argFocus,
			argPageCallback,
			refreshCallback,
			sortByChain );
		return( retnew );
	}

	public CFBorderPane newPickerPane( ICFFormManager formManager,
		ICFSecServiceObj argFocus,
		ICFSecHostNodeObj argContainer,
		ICFSecJavaFXServicePageCallback argPageCallback,
		ICFSecJavaFXServiceChosen whenChosen )
	{
		CFSecJavaFXServicePickerPane retnew = new CFSecJavaFXServicePickerPane( formManager,
			javafxSchema,
			argFocus,
			argContainer,
			argPageCallback,
			whenChosen );
		return( retnew );
	}

	public CFTabPane newEltTabPane( ICFFormManager formManager, ICFSecServiceObj argFocus ) {
		CFSecJavaFXServiceEltTabPane retnew = new CFSecJavaFXServiceEltTabPane( formManager, javafxSchema, argFocus );
		return( retnew );
	}

	public CFSplitPane newAddPane( ICFFormManager formManager, ICFSecServiceObj argFocus ) {
		CFSecJavaFXServiceAddPane retnew = new CFSecJavaFXServiceAddPane( formManager, javafxSchema, argFocus );
		return( retnew );
	}

	public CFSplitPane newViewEditPane( ICFFormManager formManager, ICFSecServiceObj argFocus ) {
		CFSecJavaFXServiceViewEditPane retnew = new CFSecJavaFXServiceViewEditPane( formManager, javafxSchema, argFocus );
		return( retnew );
	}

	public CFBorderPane newAskDeleteForm( ICFFormManager formManager, ICFSecServiceObj argFocus, ICFDeleteCallback callback ) {
		CFSecJavaFXServiceAskDeleteForm retnew = new CFSecJavaFXServiceAskDeleteForm( formManager, javafxSchema, argFocus, callback );
		return( retnew );
	}

	public CFBorderPane newPickerForm( ICFFormManager formManager,
		ICFSecServiceObj argFocus,
		ICFSecHostNodeObj argContainer,
		ICFSecJavaFXServicePageCallback argPageCallback,
		ICFSecJavaFXServiceChosen whenChosen )
	{
		CFSecJavaFXServicePickerForm retnew = new CFSecJavaFXServicePickerForm( formManager,
			javafxSchema,
			argFocus,
			argContainer,
			argPageCallback,
			whenChosen );
		return( retnew );
	}

	public CFBorderPane newAddForm( ICFFormManager formManager, ICFSecServiceObj argFocus, ICFFormClosedCallback closeCallback, boolean allowSave ) {
		CFSecJavaFXServiceAddForm retnew = new CFSecJavaFXServiceAddForm( formManager, javafxSchema, argFocus, closeCallback, allowSave );
		return( retnew );
	}

	public CFBorderPane newViewEditForm( ICFFormManager formManager, ICFSecServiceObj argFocus, ICFFormClosedCallback closeCallback, boolean cameFromAdd ) {
		CFSecJavaFXServiceViewEditForm retnew = new CFSecJavaFXServiceViewEditForm( formManager, javafxSchema, argFocus, closeCallback, cameFromAdd );
		return( retnew );
	}
}
