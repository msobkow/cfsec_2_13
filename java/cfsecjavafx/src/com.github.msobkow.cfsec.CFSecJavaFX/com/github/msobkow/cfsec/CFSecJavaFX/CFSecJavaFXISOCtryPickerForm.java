// Description: Java 11 JavaFX Picker Form implementation for ISOCtry.

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
 *	CFSecJavaFXISOCtryPickerForm JavaFX Picker Form implementation
 *	for ISOCtry.
 */
public class CFSecJavaFXISOCtryPickerForm
extends CFBorderPane
implements ICFSecJavaFXISOCtryPaneList,
	ICFForm
{
	protected ICFFormManager cfFormManager = null;
	protected CFBorderPane javafxPickerPane = null;
	protected ICFSecJavaFXSchema javafxSchema = null;
	protected Collection<ICFSecISOCtryObj> javafxDataCollection = null;

	public CFSecJavaFXISOCtryPickerForm( ICFFormManager formManager,
		ICFSecJavaFXSchema argSchema,
		ICFSecISOCtryObj argFocus,
		ICFLibAnyObj argContainer,
		Collection<ICFSecISOCtryObj> argDataCollection,
		ICFSecJavaFXISOCtryChosen whenChosen )
	{
		super();
		final String S_ProcName = "construct-schema-focus";
		if( formManager == null ) {
			throw new CFLibNullArgumentException( getClass(),
				S_ProcName,
				1,
				"formManager" );
		}
		cfFormManager = formManager;
		if( argSchema == null ) {
			throw new CFLibNullArgumentException( getClass(),
				S_ProcName,
				2,
				"argSchema" );
		}
		if( whenChosen == null ) {
			throw new CFLibNullArgumentException( getClass(),
				S_ProcName,
				6,
				"whenChosen" );
		}
		// argFocus is optional; focus may be set later during execution as
		// conditions of the runtime change.
		javafxSchema = argSchema;
		javafxPickerPane = argSchema.getISOCtryFactory().newPickerPane( cfFormManager, argFocus, argContainer, argDataCollection, whenChosen );
		setJavaFXFocusAsISOCtry( argFocus );
		setJavaFXDataCollection( argDataCollection );
		setJavaFXContainer( argContainer );
		setCenter( javafxPickerPane );
		setPaneMode( CFPane.PaneMode.View );
	}

	public ICFFormManager getCFFormManager() {
		return( cfFormManager );
	}

	public void setCFFormManager( ICFFormManager value ) {
		final String S_ProcName = "setCFFormManager";
		if( value == null ) {
			throw new CFLibNullArgumentException( getClass(),
				S_ProcName,
				1,
				"value" );
		}
		cfFormManager = value;
	}

	public void forceCancelAndClose() {
		if( cfFormManager != null ) {
			if( cfFormManager.getCurrentForm() == this ) {
				cfFormManager.closeCurrentForm();
			}
		}
	}

	public ICFSecJavaFXSchema getJavaFXSchema() {
		return( javafxSchema );
	}

	public void setJavaFXFocus( ICFLibAnyObj value ) {
		final String S_ProcName = "setJavaFXFocus";
		if( ( value == null ) || ( value instanceof ICFSecISOCtryObj ) ) {
			super.setJavaFXFocus( value );
		}
		else {
			throw new CFLibUnsupportedClassException( getClass(),
				S_ProcName,
				"value",
				value,
				"ICFSecISOCtryObj" );
		}
		((ICFSecJavaFXISOCtryPaneCommon)javafxPickerPane).setJavaFXFocus( (ICFSecISOCtryObj)value );
	}

	public ICFSecISOCtryObj getJavaFXFocusAsISOCtry() {
		return( (ICFSecISOCtryObj)getJavaFXFocus() );
	}

	public void setJavaFXFocusAsISOCtry( ICFSecISOCtryObj value ) {
		setJavaFXFocus( value );
	}

	public Collection<ICFSecISOCtryObj> getJavaFXDataCollection() {
		ICFSecJavaFXISOCtryPaneList jplPicker = (ICFSecJavaFXISOCtryPaneList)javafxPickerPane;
		Collection<ICFSecISOCtryObj> cltn = jplPicker.getJavaFXDataCollection();
		return( cltn );
	}

	public void setJavaFXDataCollection( Collection<ICFSecISOCtryObj> value ) {
		ICFSecJavaFXISOCtryPaneList jplPicker = (ICFSecJavaFXISOCtryPaneList)javafxPickerPane;
		jplPicker.setJavaFXDataCollection( value );
	}

	public void setPaneMode( CFPane.PaneMode value ) {
		final String S_ProcName = "setPaneMode";
		CFPane.PaneMode oldValue = getPaneMode();
		if( oldValue == value ) {
			return;
		}
		if( value != CFPane.PaneMode.View ) {
			throw new CFLibUsageException( getClass(),
				S_ProcName,
				"PickerForms only support PaneMode View" );
		}
		super.setPaneMode( value );
		if( javafxPickerPane != null ) {
			ICFSecJavaFXISOCtryPaneCommon jpanelCommon = (ICFSecJavaFXISOCtryPaneCommon)javafxPickerPane;
			jpanelCommon.setPaneMode( value );
		}
	}

	public ICFLibAnyObj getJavaFXContainer() {
		ICFSecJavaFXISOCtryPaneList jplPicker = (ICFSecJavaFXISOCtryPaneList)javafxPickerPane;
		ICFLibAnyObj cnt = jplPicker.getJavaFXContainer();
		return( cnt );
	}

	public void setJavaFXContainer( ICFLibAnyObj value ) {
		ICFSecJavaFXISOCtryPaneList jplPicker = (ICFSecJavaFXISOCtryPaneList)javafxPickerPane;
		jplPicker.setJavaFXContainer( value );
	}
}
