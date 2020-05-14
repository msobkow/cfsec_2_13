// Description: Java 11 JavaFX Element TabPane implementation for ISOCcy.

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
import java.util.List;
import javafx.scene.Parent;
import javafx.scene.control.ScrollPane;
import javafx.scene.control.ScrollPane.ScrollBarPolicy;
import com.github.msobkow.cflib.CFLib.*;
import com.github.msobkow.cflib.CFLib.JavaFX.*;
import org.apache.commons.codec.binary.Base64;
import com.github.msobkow.cfsec.CFSec.*;
import com.github.msobkow.cfsec.CFSecObj.*;

/**
 *	CFSecJavaFXISOCcyEltTabPane JavaFX Element TabPane implementation
 *	for ISOCcy.
 */
public class CFSecJavaFXISOCcyEltTabPane
extends CFTabPane
implements ICFSecJavaFXISOCcyPaneCommon
{
	protected ICFFormManager cfFormManager = null;
	protected ICFSecJavaFXSchema javafxSchema = null;
	protected boolean javafxIsInitializing = true;
	public final String LABEL_TabChildrenCtryList = "Optional Children Ctry";
	protected CFTab tabChildrenCtry = null;
	protected CFBorderPane tabViewChildrenCtryListPane = null;

	public CFSecJavaFXISOCcyEltTabPane( ICFFormManager formManager, ICFSecJavaFXSchema argSchema, ICFSecISOCcyObj argFocus ) {
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
		setJavaFXFocusAsISOCcy( argFocus );
		// Wire the newly constructed Panes/Tabs to this TabPane
		tabChildrenCtry = new CFTab();
		tabChildrenCtry.setText( LABEL_TabChildrenCtryList );
		tabChildrenCtry.setContent( getTabViewChildrenCtryListPane() );
		getTabs().add( tabChildrenCtry );
		javafxIsInitializing = false;
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
		if( ( value == null ) || ( value instanceof ICFSecISOCcyObj ) ) {
			super.setJavaFXFocus( value );
		}
		else {
			throw new CFLibUnsupportedClassException( getClass(),
				S_ProcName,
				"value",
				value,
				"ICFSecISOCcyObj" );
		}
	}

	public void setJavaFXFocusAsISOCcy( ICFSecISOCcyObj value ) {
		setJavaFXFocus( value );
	}

	public ICFSecISOCcyObj getJavaFXFocusAsISOCcy() {
		return( (ICFSecISOCcyObj)getJavaFXFocus() );
	}

	protected class RefreshChildrenCtryList
	implements ICFRefreshCallback
	{
		public RefreshChildrenCtryList() {
		}

		public void refreshMe() {
			Collection<ICFSecISOCtryCcyObj> dataCollection;
			ICFSecISOCcyObj focus = (ICFSecISOCcyObj)getJavaFXFocusAsISOCcy();
			if( focus != null ) {
				dataCollection = focus.getOptionalChildrenCtry( javafxIsInitializing );
			}
			else {
				dataCollection = null;
			}
			CFBorderPane pane = getTabViewChildrenCtryListPane();
			ICFSecJavaFXISOCtryCcyPaneList jpList = (ICFSecJavaFXISOCtryCcyPaneList)pane;
			jpList.setJavaFXDataCollection( dataCollection );
		}
	}

	public CFBorderPane getTabViewChildrenCtryListPane() {
		if( tabViewChildrenCtryListPane == null ) {
			ICFSecISOCcyObj focus = (ICFSecISOCcyObj)getJavaFXFocusAsISOCcy();
			Collection<ICFSecISOCtryCcyObj> dataCollection;
			if( focus != null ) {
				dataCollection = focus.getOptionalChildrenCtry( javafxIsInitializing );
			}
			else {
				dataCollection = null;
			}
			ICFSecISOCtryObj javafxContainer;
			if( ( focus != null ) && ( focus instanceof ICFSecISOCtryObj ) ) {
				javafxContainer = (ICFSecISOCtryObj)focus;
			}
			else {
				javafxContainer = null;
			}
			tabViewChildrenCtryListPane = javafxSchema.getISOCtryCcyFactory().newListPane( cfFormManager, javafxContainer, null, dataCollection, new RefreshChildrenCtryList(), false );
		}
		return( tabViewChildrenCtryListPane );
	}

	public void setPaneMode( CFPane.PaneMode value ) {
		CFPane.PaneMode oldMode = getPaneMode();
		super.setPaneMode( value );
		if( tabViewChildrenCtryListPane != null ) {
			((ICFSecJavaFXISOCtryCcyPaneCommon)tabViewChildrenCtryListPane).setPaneMode( value );
		}
	}
}
