// Description: Java 11 JavaFX Element TabPane implementation for SecApp.

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
 *	CFSecJavaFXSecAppEltTabPane JavaFX Element TabPane implementation
 *	for SecApp.
 */
public class CFSecJavaFXSecAppEltTabPane
extends CFTabPane
implements ICFSecJavaFXSecAppPaneCommon
{
	protected ICFFormManager cfFormManager = null;
	protected ICFSecJavaFXSchema javafxSchema = null;
	protected boolean javafxIsInitializing = true;
	public final String LABEL_TabComponentsFormList = "Optional Components Security Form";
	protected CFTab tabComponentsForm = null;
	protected CFBorderPane tabViewComponentsFormListPane = null;

	public CFSecJavaFXSecAppEltTabPane( ICFFormManager formManager, ICFSecJavaFXSchema argSchema, ICFSecSecAppObj argFocus ) {
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
		setJavaFXFocusAsSecApp( argFocus );
		// Wire the newly constructed Panes/Tabs to this TabPane
		tabComponentsForm = new CFTab();
		tabComponentsForm.setText( LABEL_TabComponentsFormList );
		tabComponentsForm.setContent( getTabViewComponentsFormListPane() );
		getTabs().add( tabComponentsForm );
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
		if( ( value == null ) || ( value instanceof ICFSecSecAppObj ) ) {
			super.setJavaFXFocus( value );
		}
		else {
			throw new CFLibUnsupportedClassException( getClass(),
				S_ProcName,
				"value",
				value,
				"ICFSecSecAppObj" );
		}
	}

	public void setJavaFXFocusAsSecApp( ICFSecSecAppObj value ) {
		setJavaFXFocus( value );
	}

	public ICFSecSecAppObj getJavaFXFocusAsSecApp() {
		return( (ICFSecSecAppObj)getJavaFXFocus() );
	}

	protected class RefreshComponentsFormList
	implements ICFRefreshCallback
	{
		public RefreshComponentsFormList() {
		}

		public void refreshMe() {
			// Use page data instead
		}
	}

	protected class PageDataComponentsFormList
	implements ICFSecJavaFXSecFormPageCallback
	{
		public PageDataComponentsFormList() {
		}

		public List<ICFSecSecFormObj> pageData( Long priorClusterId,
		Integer priorSecFormId )
		{
			List<ICFSecSecFormObj> dataList;
			ICFSecSecAppObj focus = (ICFSecSecAppObj)getJavaFXFocusAsSecApp();
			if( focus != null ) {
				ICFSecSchemaObj schemaObj = (ICFSecSchemaObj)javafxSchema.getSchema();
				dataList = schemaObj.getSecFormTableObj().pageSecFormBySecAppIdx( focus.getRequiredClusterId(),
					focus.getRequiredSecAppId(),
					priorClusterId,
					priorSecFormId );
			}
			else {
				dataList = new ArrayList<ICFSecSecFormObj>();
			}
			return( dataList );
		}
	}

	public CFBorderPane getTabViewComponentsFormListPane() {
		if( tabViewComponentsFormListPane == null ) {
			ICFSecSecAppObj focus = (ICFSecSecAppObj)getJavaFXFocusAsSecApp();
			ICFSecSecAppObj javafxContainer;
			if( ( focus != null ) && ( focus instanceof ICFSecSecAppObj ) ) {
				javafxContainer = (ICFSecSecAppObj)focus;
			}
			else {
				javafxContainer = null;
			}
			tabViewComponentsFormListPane = javafxSchema.getSecFormFactory().newListPane( cfFormManager, javafxContainer, null, new PageDataComponentsFormList(), new RefreshComponentsFormList(), false );
		}
		return( tabViewComponentsFormListPane );
	}

	public void setPaneMode( CFPane.PaneMode value ) {
		CFPane.PaneMode oldMode = getPaneMode();
		super.setPaneMode( value );
		if( tabViewComponentsFormListPane != null ) {
			((ICFSecJavaFXSecFormPaneCommon)tabViewComponentsFormListPane).setPaneMode( value );
		}
	}
}