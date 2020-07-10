// Description: Java 11 JavaFX Element TabPane implementation for ISOCtry.

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
import java.util.List;
import javafx.scene.Parent;
import javafx.scene.control.ScrollPane;
import javafx.scene.control.ScrollPane.ScrollBarPolicy;
import org.msscf.msscf.cflib.CFLib.*;
import org.msscf.msscf.cflib.CFLib.JavaFX.*;
import org.apache.commons.codec.binary.Base64;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfsec.CFSecObj.*;

/**
 *	CFSecJavaFXISOCtryEltTabPane JavaFX Element TabPane implementation
 *	for ISOCtry.
 */
public class CFSecJavaFXISOCtryEltTabPane
extends CFTabPane
implements ICFSecJavaFXISOCtryPaneCommon
{
	protected ICFFormManager cfFormManager = null;
	protected ICFSecJavaFXSchema javafxSchema = null;
	protected boolean javafxIsInitializing = true;
	public final String LABEL_TabComponentsCcyList = "Optional Components Ccy";
	protected CFTab tabComponentsCcy = null;
	public final String LABEL_TabComponentsLangList = "Optional Components Lang";
	protected CFTab tabComponentsLang = null;
	protected CFBorderPane tabViewComponentsCcyListPane = null;
	protected CFBorderPane tabViewComponentsLangListPane = null;

	public CFSecJavaFXISOCtryEltTabPane( ICFFormManager formManager, ICFSecJavaFXSchema argSchema, ICFSecISOCtryObj argFocus ) {
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
		setJavaFXFocusAsISOCtry( argFocus );
		// Wire the newly constructed Panes/Tabs to this TabPane
		tabComponentsCcy = new CFTab();
		tabComponentsCcy.setText( LABEL_TabComponentsCcyList );
		tabComponentsCcy.setContent( getTabViewComponentsCcyListPane() );
		getTabs().add( tabComponentsCcy );
		tabComponentsLang = new CFTab();
		tabComponentsLang.setText( LABEL_TabComponentsLangList );
		tabComponentsLang.setContent( getTabViewComponentsLangListPane() );
		getTabs().add( tabComponentsLang );
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
	}

	public void setJavaFXFocusAsISOCtry( ICFSecISOCtryObj value ) {
		setJavaFXFocus( value );
	}

	public ICFSecISOCtryObj getJavaFXFocusAsISOCtry() {
		return( (ICFSecISOCtryObj)getJavaFXFocus() );
	}

	protected class RefreshComponentsCcyList
	implements ICFRefreshCallback
	{
		public RefreshComponentsCcyList() {
		}

		public void refreshMe() {
			Collection<ICFSecISOCtryCcyObj> dataCollection;
			ICFSecISOCtryObj focus = (ICFSecISOCtryObj)getJavaFXFocusAsISOCtry();
			if( focus != null ) {
				dataCollection = focus.getOptionalComponentsCcy( javafxIsInitializing );
			}
			else {
				dataCollection = null;
			}
			CFBorderPane pane = getTabViewComponentsCcyListPane();
			ICFSecJavaFXISOCtryCcyPaneList jpList = (ICFSecJavaFXISOCtryCcyPaneList)pane;
			jpList.setJavaFXDataCollection( dataCollection );
		}
	}

	public CFBorderPane getTabViewComponentsCcyListPane() {
		if( tabViewComponentsCcyListPane == null ) {
			ICFSecISOCtryObj focus = (ICFSecISOCtryObj)getJavaFXFocusAsISOCtry();
			Collection<ICFSecISOCtryCcyObj> dataCollection;
			if( focus != null ) {
				dataCollection = focus.getOptionalComponentsCcy( javafxIsInitializing );
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
			tabViewComponentsCcyListPane = javafxSchema.getISOCtryCcyFactory().newListPane( cfFormManager, javafxContainer, null, dataCollection, new RefreshComponentsCcyList(), false );
		}
		return( tabViewComponentsCcyListPane );
	}

	protected class RefreshComponentsLangList
	implements ICFRefreshCallback
	{
		public RefreshComponentsLangList() {
		}

		public void refreshMe() {
			Collection<ICFSecISOCtryLangObj> dataCollection;
			ICFSecISOCtryObj focus = (ICFSecISOCtryObj)getJavaFXFocusAsISOCtry();
			if( focus != null ) {
				dataCollection = focus.getOptionalComponentsLang( javafxIsInitializing );
			}
			else {
				dataCollection = null;
			}
			CFBorderPane pane = getTabViewComponentsLangListPane();
			ICFSecJavaFXISOCtryLangPaneList jpList = (ICFSecJavaFXISOCtryLangPaneList)pane;
			jpList.setJavaFXDataCollection( dataCollection );
		}
	}

	public CFBorderPane getTabViewComponentsLangListPane() {
		if( tabViewComponentsLangListPane == null ) {
			ICFSecISOCtryObj focus = (ICFSecISOCtryObj)getJavaFXFocusAsISOCtry();
			Collection<ICFSecISOCtryLangObj> dataCollection;
			if( focus != null ) {
				dataCollection = focus.getOptionalComponentsLang( javafxIsInitializing );
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
			tabViewComponentsLangListPane = javafxSchema.getISOCtryLangFactory().newListPane( cfFormManager, javafxContainer, null, dataCollection, new RefreshComponentsLangList(), false );
		}
		return( tabViewComponentsLangListPane );
	}

	public void setPaneMode( CFPane.PaneMode value ) {
		CFPane.PaneMode oldMode = getPaneMode();
		super.setPaneMode( value );
		if( tabViewComponentsCcyListPane != null ) {
			((ICFSecJavaFXISOCtryCcyPaneCommon)tabViewComponentsCcyListPane).setPaneMode( value );
		}
		if( tabViewComponentsLangListPane != null ) {
			((ICFSecJavaFXISOCtryLangPaneCommon)tabViewComponentsLangListPane).setPaneMode( value );
		}
	}
}
