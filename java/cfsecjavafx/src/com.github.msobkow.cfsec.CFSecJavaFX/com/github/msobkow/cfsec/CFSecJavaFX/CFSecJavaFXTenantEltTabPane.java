// Description: Java 11 JavaFX Element TabPane implementation for Tenant.

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
 *	CFSecJavaFXTenantEltTabPane JavaFX Element TabPane implementation
 *	for Tenant.
 */
public class CFSecJavaFXTenantEltTabPane
extends CFTabPane
implements ICFSecJavaFXTenantPaneCommon
{
	protected ICFFormManager cfFormManager = null;
	protected ICFSecJavaFXSchema javafxSchema = null;
	protected boolean javafxIsInitializing = true;
	public final String LABEL_TabComponentsTSecGroupList = "Optional Components Tenant Security Group";
	protected CFTab tabComponentsTSecGroup = null;
	protected CFBorderPane tabViewComponentsTSecGroupListPane = null;

	public CFSecJavaFXTenantEltTabPane( ICFFormManager formManager, ICFSecJavaFXSchema argSchema, ICFSecTenantObj argFocus ) {
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
		setJavaFXFocusAsTenant( argFocus );
		// Wire the newly constructed Panes/Tabs to this TabPane
		tabComponentsTSecGroup = new CFTab();
		tabComponentsTSecGroup.setText( LABEL_TabComponentsTSecGroupList );
		tabComponentsTSecGroup.setContent( getTabViewComponentsTSecGroupListPane() );
		getTabs().add( tabComponentsTSecGroup );
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
		if( ( value == null ) || ( value instanceof ICFSecTenantObj ) ) {
			super.setJavaFXFocus( value );
		}
		else {
			throw new CFLibUnsupportedClassException( getClass(),
				S_ProcName,
				"value",
				value,
				"ICFSecTenantObj" );
		}
	}

	public void setJavaFXFocusAsTenant( ICFSecTenantObj value ) {
		setJavaFXFocus( value );
	}

	public ICFSecTenantObj getJavaFXFocusAsTenant() {
		return( (ICFSecTenantObj)getJavaFXFocus() );
	}

	protected class RefreshComponentsTSecGroupList
	implements ICFRefreshCallback
	{
		public RefreshComponentsTSecGroupList() {
		}

		public void refreshMe() {
			Collection<ICFSecTSecGroupObj> dataCollection;
			ICFSecTenantObj focus = (ICFSecTenantObj)getJavaFXFocusAsTenant();
			if( focus != null ) {
				dataCollection = focus.getOptionalComponentsTSecGroup( javafxIsInitializing );
			}
			else {
				dataCollection = null;
			}
			CFBorderPane pane = getTabViewComponentsTSecGroupListPane();
			ICFSecJavaFXTSecGroupPaneList jpList = (ICFSecJavaFXTSecGroupPaneList)pane;
			jpList.setJavaFXDataCollection( dataCollection );
		}
	}

	public CFBorderPane getTabViewComponentsTSecGroupListPane() {
		if( tabViewComponentsTSecGroupListPane == null ) {
			ICFSecTenantObj focus = (ICFSecTenantObj)getJavaFXFocusAsTenant();
			Collection<ICFSecTSecGroupObj> dataCollection;
			if( focus != null ) {
				dataCollection = focus.getOptionalComponentsTSecGroup( javafxIsInitializing );
			}
			else {
				dataCollection = null;
			}
			ICFSecTenantObj javafxContainer;
			if( ( focus != null ) && ( focus instanceof ICFSecTenantObj ) ) {
				javafxContainer = (ICFSecTenantObj)focus;
			}
			else {
				javafxContainer = null;
			}
			tabViewComponentsTSecGroupListPane = javafxSchema.getTSecGroupFactory().newListPane( cfFormManager, javafxContainer, null, dataCollection, new RefreshComponentsTSecGroupList(), false );
		}
		return( tabViewComponentsTSecGroupListPane );
	}

	public void setPaneMode( CFPane.PaneMode value ) {
		CFPane.PaneMode oldMode = getPaneMode();
		super.setPaneMode( value );
		if( tabViewComponentsTSecGroupListPane != null ) {
			((ICFSecJavaFXTSecGroupPaneCommon)tabViewComponentsTSecGroupListPane).setPaneMode( value );
		}
	}
}
