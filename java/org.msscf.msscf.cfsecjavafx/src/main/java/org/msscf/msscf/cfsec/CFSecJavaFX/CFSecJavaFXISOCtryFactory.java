// Description: Java 11 JavaFX Display Element Factory for ISOCtry.

/*
 *	org.msscf.msscf.CFSec
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFSec 2.13 Security Essentials
 *	
 *	Copyright 2020 Mark Stephen Sobkow
 *	
 *		This file is part of MSS Code Factory.
 *	
 *		MSS Code Factory is available under dual commercial license from Mark Stephen
 *		Sobkow, or under the terms of the GNU General Public License, Version 3
 *		or later.
 *	
 *	    MSS Code Factory is free software: you can redistribute it and/or modify
 *	    it under the terms of the GNU General Public License as published by
 *	    the Free Software Foundation, either version 3 of the License, or
 *	    (at your option) any later version.
 *	
 *	    MSS Code Factory is distributed in the hope that it will be useful,
 *	    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	    GNU General Public License for more details.
 *	
 *	    You should have received a copy of the GNU General Public License
 *	    along with MSS Code Factory.  If not, see <https://www.gnu.org/licenses/>.
 *	
 *	Donations to support MSS Code Factory can be made at
 *	https://www.paypal.com/paypalme2/MarkSobkow
 *	
 *	Please contact Mark Stephen Sobkow at msobkow@sasktel.net for commercial licensing.
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
