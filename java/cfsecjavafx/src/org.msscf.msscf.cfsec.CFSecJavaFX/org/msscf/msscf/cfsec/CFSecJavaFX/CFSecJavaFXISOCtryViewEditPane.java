// Description: Java 11 JavaFX View/Edit Pane implementation for ISOCtry.

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
import javafx.geometry.Orientation;
import javafx.scene.control.ScrollPane;
import javafx.scene.control.ScrollPane.ScrollBarPolicy;
import org.msscf.msscf.cflib.CFLib.*;
import org.msscf.msscf.cflib.CFLib.JavaFX.*;
import org.apache.commons.codec.binary.Base64;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfsec.CFSecObj.*;

/**
 *	CFSecJavaFXISOCtryViewEditPane JavaFX View/Edit Pane implementation
 *	for ISOCtry.
 */
public class CFSecJavaFXISOCtryViewEditPane
extends CFSplitPane
implements ICFSecJavaFXISOCtryPaneCommon
{
	protected ICFFormManager cfFormManager = null;
	protected ICFSecJavaFXSchema javafxSchema = null;
	protected ScrollPane attrScrollPane = null;
	protected CFGridPane attrPane = null;
	protected CFTabPane eltTabPane = null;

	public CFSecJavaFXISOCtryViewEditPane( ICFFormManager formManager, ICFSecJavaFXSchema argSchema, ICFSecISOCtryObj argFocus ) {
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
		// argFocus is optional; focus may be set later during execution as
		// conditions of the runtime change.
		javafxSchema = argSchema;
		setJavaFXFocus( argFocus );
		attrPane = argSchema.getISOCtryFactory().newAttrPane( cfFormManager, argFocus );
		attrScrollPane = new ScrollPane();
		attrScrollPane.setFitToWidth( true );
		attrScrollPane.setHbarPolicy( ScrollBarPolicy.NEVER );
		attrScrollPane.setVbarPolicy( ScrollBarPolicy.AS_NEEDED );
		attrScrollPane.setContent( attrPane );
		eltTabPane = argSchema.getISOCtryFactory().newEltTabPane( cfFormManager, argFocus );
		setOrientation( Orientation.VERTICAL );
		getItems().add( attrScrollPane );
		getItems().add( eltTabPane );
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
		if( attrPane != null ) {
			attrPane.setJavaFXFocus( value );
		}
		if( eltTabPane != null ) {
			eltTabPane.setJavaFXFocus( value );
		}
	}

	public void setJavaFXFocusAsISOCtry( ICFSecISOCtryObj value ) {
		setJavaFXFocus( value );
	}

	public ICFSecISOCtryObj getJavaFXFocusAsISOCtry() {
		return( (ICFSecISOCtryObj)getJavaFXFocus() );
	}

	public void setPaneMode( CFPane.PaneMode value ) {
		CFPane.PaneMode oldMode = getPaneMode();
		if( oldMode == value ) {
			return;
		}
		try {
			super.setPaneMode( value );
			((ICFSecJavaFXISOCtryPaneCommon)attrPane).setPaneMode( value );
			((ICFSecJavaFXISOCtryPaneCommon)eltTabPane).setPaneMode( value );
		}
		catch( Throwable t ) {
			super.setPaneMode( oldMode );
			((ICFSecJavaFXISOCtryPaneCommon)attrPane).setPaneMode( oldMode );
			((ICFSecJavaFXISOCtryPaneCommon)eltTabPane).setPaneMode( oldMode );
			throw t;
		}
	}
}