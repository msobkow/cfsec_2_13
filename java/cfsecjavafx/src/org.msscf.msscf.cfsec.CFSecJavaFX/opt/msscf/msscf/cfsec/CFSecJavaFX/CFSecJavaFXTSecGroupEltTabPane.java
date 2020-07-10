// Description: Java 11 JavaFX Element TabPane implementation for TSecGroup.

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
 *	CFSecJavaFXTSecGroupEltTabPane JavaFX Element TabPane implementation
 *	for TSecGroup.
 */
public class CFSecJavaFXTSecGroupEltTabPane
extends CFTabPane
implements ICFSecJavaFXTSecGroupPaneCommon
{
	protected ICFFormManager cfFormManager = null;
	protected ICFSecJavaFXSchema javafxSchema = null;
	protected boolean javafxIsInitializing = true;
	public final String LABEL_TabComponentsIncludeList = "Optional Components Sub Group";
	protected CFTab tabComponentsInclude = null;
	public final String LABEL_TabComponentsMemberList = "Optional Components Group Member";
	protected CFTab tabComponentsMember = null;
	public final String LABEL_TabChildrenIncByGroupList = "Required Children Included By Group";
	protected CFTab tabChildrenIncByGroup = null;
	protected CFBorderPane tabViewComponentsIncludeListPane = null;
	protected CFBorderPane tabViewComponentsMemberListPane = null;
	protected CFBorderPane tabViewChildrenIncByGroupListPane = null;

	public CFSecJavaFXTSecGroupEltTabPane( ICFFormManager formManager, ICFSecJavaFXSchema argSchema, ICFSecTSecGroupObj argFocus ) {
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
		setJavaFXFocusAsTSecGroup( argFocus );
		// Wire the newly constructed Panes/Tabs to this TabPane
		tabComponentsInclude = new CFTab();
		tabComponentsInclude.setText( LABEL_TabComponentsIncludeList );
		tabComponentsInclude.setContent( getTabViewComponentsIncludeListPane() );
		getTabs().add( tabComponentsInclude );
		tabComponentsMember = new CFTab();
		tabComponentsMember.setText( LABEL_TabComponentsMemberList );
		tabComponentsMember.setContent( getTabViewComponentsMemberListPane() );
		getTabs().add( tabComponentsMember );
		tabChildrenIncByGroup = new CFTab();
		tabChildrenIncByGroup.setText( LABEL_TabChildrenIncByGroupList );
		tabChildrenIncByGroup.setContent( getTabViewChildrenIncByGroupListPane() );
		getTabs().add( tabChildrenIncByGroup );
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
		if( ( value == null ) || ( value instanceof ICFSecTSecGroupObj ) ) {
			super.setJavaFXFocus( value );
		}
		else {
			throw new CFLibUnsupportedClassException( getClass(),
				S_ProcName,
				"value",
				value,
				"ICFSecTSecGroupObj" );
		}
	}

	public void setJavaFXFocusAsTSecGroup( ICFSecTSecGroupObj value ) {
		setJavaFXFocus( value );
	}

	public ICFSecTSecGroupObj getJavaFXFocusAsTSecGroup() {
		return( (ICFSecTSecGroupObj)getJavaFXFocus() );
	}

	protected class RefreshComponentsIncludeList
	implements ICFRefreshCallback
	{
		public RefreshComponentsIncludeList() {
		}

		public void refreshMe() {
			// Use page data instead
		}
	}

	protected class PageDataComponentsIncludeList
	implements ICFSecJavaFXTSecGrpIncPageCallback
	{
		public PageDataComponentsIncludeList() {
		}

		public List<ICFSecTSecGrpIncObj> pageData( Long priorTenantId,
		Long priorTSecGrpIncId )
		{
			List<ICFSecTSecGrpIncObj> dataList;
			ICFSecTSecGroupObj focus = (ICFSecTSecGroupObj)getJavaFXFocusAsTSecGroup();
			if( focus != null ) {
				ICFSecSchemaObj schemaObj = (ICFSecSchemaObj)javafxSchema.getSchema();
				dataList = schemaObj.getTSecGrpIncTableObj().pageTSecGrpIncByGroupIdx( focus.getRequiredTenantId(),
					focus.getRequiredTSecGroupId(),
					priorTenantId,
					priorTSecGrpIncId );
			}
			else {
				dataList = new ArrayList<ICFSecTSecGrpIncObj>();
			}
			return( dataList );
		}
	}

	public CFBorderPane getTabViewComponentsIncludeListPane() {
		if( tabViewComponentsIncludeListPane == null ) {
			ICFSecTSecGroupObj focus = (ICFSecTSecGroupObj)getJavaFXFocusAsTSecGroup();
			ICFSecTSecGroupObj javafxContainer;
			if( ( focus != null ) && ( focus instanceof ICFSecTSecGroupObj ) ) {
				javafxContainer = (ICFSecTSecGroupObj)focus;
			}
			else {
				javafxContainer = null;
			}
			tabViewComponentsIncludeListPane = javafxSchema.getTSecGrpIncFactory().newListPane( cfFormManager, javafxContainer, null, new PageDataComponentsIncludeList(), new RefreshComponentsIncludeList(), false );
		}
		return( tabViewComponentsIncludeListPane );
	}

	protected class RefreshComponentsMemberList
	implements ICFRefreshCallback
	{
		public RefreshComponentsMemberList() {
		}

		public void refreshMe() {
			// Use page data instead
		}
	}

	protected class PageDataComponentsMemberList
	implements ICFSecJavaFXTSecGrpMembPageCallback
	{
		public PageDataComponentsMemberList() {
		}

		public List<ICFSecTSecGrpMembObj> pageData( Long priorTenantId,
		Long priorTSecGrpMembId )
		{
			List<ICFSecTSecGrpMembObj> dataList;
			ICFSecTSecGroupObj focus = (ICFSecTSecGroupObj)getJavaFXFocusAsTSecGroup();
			if( focus != null ) {
				ICFSecSchemaObj schemaObj = (ICFSecSchemaObj)javafxSchema.getSchema();
				dataList = schemaObj.getTSecGrpMembTableObj().pageTSecGrpMembByGroupIdx( focus.getRequiredTenantId(),
					focus.getRequiredTSecGroupId(),
					priorTenantId,
					priorTSecGrpMembId );
			}
			else {
				dataList = new ArrayList<ICFSecTSecGrpMembObj>();
			}
			return( dataList );
		}
	}

	public CFBorderPane getTabViewComponentsMemberListPane() {
		if( tabViewComponentsMemberListPane == null ) {
			ICFSecTSecGroupObj focus = (ICFSecTSecGroupObj)getJavaFXFocusAsTSecGroup();
			ICFSecTSecGroupObj javafxContainer;
			if( ( focus != null ) && ( focus instanceof ICFSecTSecGroupObj ) ) {
				javafxContainer = (ICFSecTSecGroupObj)focus;
			}
			else {
				javafxContainer = null;
			}
			tabViewComponentsMemberListPane = javafxSchema.getTSecGrpMembFactory().newListPane( cfFormManager, javafxContainer, null, new PageDataComponentsMemberList(), new RefreshComponentsMemberList(), false );
		}
		return( tabViewComponentsMemberListPane );
	}

	protected class RefreshChildrenIncByGroupList
	implements ICFRefreshCallback
	{
		public RefreshChildrenIncByGroupList() {
		}

		public void refreshMe() {
			// Use page data instead
		}
	}

	protected class PageDataChildrenIncByGroupList
	implements ICFSecJavaFXTSecGrpIncPageCallback
	{
		public PageDataChildrenIncByGroupList() {
		}

		public List<ICFSecTSecGrpIncObj> pageData( Long priorTenantId,
		Long priorTSecGrpIncId )
		{
			List<ICFSecTSecGrpIncObj> dataList;
			ICFSecTSecGroupObj focus = (ICFSecTSecGroupObj)getJavaFXFocusAsTSecGroup();
			if( focus != null ) {
				ICFSecSchemaObj schemaObj = (ICFSecSchemaObj)javafxSchema.getSchema();
				dataList = schemaObj.getTSecGrpIncTableObj().pageTSecGrpIncByIncludeIdx( focus.getRequiredTenantId(),
					focus.getRequiredTSecGroupId(),
					priorTenantId,
					priorTSecGrpIncId );
			}
			else {
				dataList = new ArrayList<ICFSecTSecGrpIncObj>();
			}
			return( dataList );
		}
	}

	public CFBorderPane getTabViewChildrenIncByGroupListPane() {
		if( tabViewChildrenIncByGroupListPane == null ) {
			ICFSecTSecGroupObj focus = (ICFSecTSecGroupObj)getJavaFXFocusAsTSecGroup();
			ICFSecTSecGroupObj javafxContainer;
			if( ( focus != null ) && ( focus instanceof ICFSecTSecGroupObj ) ) {
				javafxContainer = (ICFSecTSecGroupObj)focus;
			}
			else {
				javafxContainer = null;
			}
			tabViewChildrenIncByGroupListPane = javafxSchema.getTSecGrpIncFactory().newListPane( cfFormManager, javafxContainer, null, new PageDataChildrenIncByGroupList(), new RefreshChildrenIncByGroupList(), false );
		}
		return( tabViewChildrenIncByGroupListPane );
	}

	public void setPaneMode( CFPane.PaneMode value ) {
		CFPane.PaneMode oldMode = getPaneMode();
		super.setPaneMode( value );
		if( tabViewComponentsIncludeListPane != null ) {
			((ICFSecJavaFXTSecGrpIncPaneCommon)tabViewComponentsIncludeListPane).setPaneMode( value );
		}
		if( tabViewComponentsMemberListPane != null ) {
			((ICFSecJavaFXTSecGrpMembPaneCommon)tabViewComponentsMemberListPane).setPaneMode( value );
		}
		if( tabViewChildrenIncByGroupListPane != null ) {
			((ICFSecJavaFXTSecGrpIncPaneCommon)tabViewChildrenIncByGroupListPane).setPaneMode( value );
		}
	}
}
