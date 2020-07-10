// Description: Java 11 JavaFX Element TabPane implementation for HostNode.

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
 *	CFSecJavaFXHostNodeEltTabPane JavaFX Element TabPane implementation
 *	for HostNode.
 */
public class CFSecJavaFXHostNodeEltTabPane
extends CFTabPane
implements ICFSecJavaFXHostNodePaneCommon
{
	protected ICFFormManager cfFormManager = null;
	protected ICFSecJavaFXSchema javafxSchema = null;
	protected boolean javafxIsInitializing = true;
	public final String LABEL_TabComponentsServiceList = "Optional Components Service";
	protected CFTab tabComponentsService = null;
	protected CFBorderPane tabViewComponentsServiceListPane = null;

	public CFSecJavaFXHostNodeEltTabPane( ICFFormManager formManager, ICFSecJavaFXSchema argSchema, ICFSecHostNodeObj argFocus ) {
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
		setJavaFXFocusAsHostNode( argFocus );
		// Wire the newly constructed Panes/Tabs to this TabPane
		tabComponentsService = new CFTab();
		tabComponentsService.setText( LABEL_TabComponentsServiceList );
		tabComponentsService.setContent( getTabViewComponentsServiceListPane() );
		getTabs().add( tabComponentsService );
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
		if( ( value == null ) || ( value instanceof ICFSecHostNodeObj ) ) {
			super.setJavaFXFocus( value );
		}
		else {
			throw new CFLibUnsupportedClassException( getClass(),
				S_ProcName,
				"value",
				value,
				"ICFSecHostNodeObj" );
		}
	}

	public void setJavaFXFocusAsHostNode( ICFSecHostNodeObj value ) {
		setJavaFXFocus( value );
	}

	public ICFSecHostNodeObj getJavaFXFocusAsHostNode() {
		return( (ICFSecHostNodeObj)getJavaFXFocus() );
	}

	protected class RefreshComponentsServiceList
	implements ICFRefreshCallback
	{
		public RefreshComponentsServiceList() {
		}

		public void refreshMe() {
			// Use page data instead
		}
	}

	protected class PageDataComponentsServiceList
	implements ICFSecJavaFXServicePageCallback
	{
		public PageDataComponentsServiceList() {
		}

		public List<ICFSecServiceObj> pageData( Long priorClusterId,
		Long priorServiceId )
		{
			List<ICFSecServiceObj> dataList;
			ICFSecHostNodeObj focus = (ICFSecHostNodeObj)getJavaFXFocusAsHostNode();
			if( focus != null ) {
				ICFSecSchemaObj schemaObj = (ICFSecSchemaObj)javafxSchema.getSchema();
				dataList = schemaObj.getServiceTableObj().pageServiceByHostIdx( focus.getRequiredClusterId(),
					focus.getRequiredHostNodeId(),
					priorClusterId,
					priorServiceId );
			}
			else {
				dataList = new ArrayList<ICFSecServiceObj>();
			}
			return( dataList );
		}
	}

	public CFBorderPane getTabViewComponentsServiceListPane() {
		if( tabViewComponentsServiceListPane == null ) {
			ICFSecHostNodeObj focus = (ICFSecHostNodeObj)getJavaFXFocusAsHostNode();
			ICFSecHostNodeObj javafxContainer;
			if( ( focus != null ) && ( focus instanceof ICFSecHostNodeObj ) ) {
				javafxContainer = (ICFSecHostNodeObj)focus;
			}
			else {
				javafxContainer = null;
			}
			tabViewComponentsServiceListPane = javafxSchema.getServiceFactory().newListPane( cfFormManager, javafxContainer, null, new PageDataComponentsServiceList(), new RefreshComponentsServiceList(), false );
		}
		return( tabViewComponentsServiceListPane );
	}

	public void setPaneMode( CFPane.PaneMode value ) {
		CFPane.PaneMode oldMode = getPaneMode();
		super.setPaneMode( value );
		if( tabViewComponentsServiceListPane != null ) {
			((ICFSecJavaFXServicePaneCommon)tabViewComponentsServiceListPane).setPaneMode( value );
		}
	}
}
