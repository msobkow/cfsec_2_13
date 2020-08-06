// Description: Java 11 JavaFX Element TabPane implementation for SecGroup.

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
 *	CFSecJavaFXSecGroupEltTabPane JavaFX Element TabPane implementation
 *	for SecGroup.
 */
public class CFSecJavaFXSecGroupEltTabPane
extends CFTabPane
implements ICFSecJavaFXSecGroupPaneCommon
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
	public final String LABEL_TabComponentsFormList = "Optional Components Group Form Permission";
	protected CFTab tabComponentsForm = null;
	protected CFBorderPane tabViewComponentsIncludeListPane = null;
	protected CFBorderPane tabViewComponentsMemberListPane = null;
	protected CFBorderPane tabViewChildrenIncByGroupListPane = null;
	protected CFBorderPane tabViewComponentsFormListPane = null;

	public CFSecJavaFXSecGroupEltTabPane( ICFFormManager formManager, ICFSecJavaFXSchema argSchema, ICFSecSecGroupObj argFocus ) {
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
		setJavaFXFocusAsSecGroup( argFocus );
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
		if( ( value == null ) || ( value instanceof ICFSecSecGroupObj ) ) {
			super.setJavaFXFocus( value );
		}
		else {
			throw new CFLibUnsupportedClassException( getClass(),
				S_ProcName,
				"value",
				value,
				"ICFSecSecGroupObj" );
		}
	}

	public void setJavaFXFocusAsSecGroup( ICFSecSecGroupObj value ) {
		setJavaFXFocus( value );
	}

	public ICFSecSecGroupObj getJavaFXFocusAsSecGroup() {
		return( (ICFSecSecGroupObj)getJavaFXFocus() );
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
	implements ICFSecJavaFXSecGrpIncPageCallback
	{
		public PageDataComponentsIncludeList() {
		}

		public List<ICFSecSecGrpIncObj> pageData( Long priorClusterId,
		Long priorSecGrpIncId )
		{
			List<ICFSecSecGrpIncObj> dataList;
			ICFSecSecGroupObj focus = (ICFSecSecGroupObj)getJavaFXFocusAsSecGroup();
			if( focus != null ) {
				ICFSecSchemaObj schemaObj = (ICFSecSchemaObj)javafxSchema.getSchema();
				dataList = schemaObj.getSecGrpIncTableObj().pageSecGrpIncByGroupIdx( focus.getRequiredClusterId(),
					focus.getRequiredSecGroupId(),
					priorClusterId,
					priorSecGrpIncId );
			}
			else {
				dataList = new ArrayList<ICFSecSecGrpIncObj>();
			}
			return( dataList );
		}
	}

	public CFBorderPane getTabViewComponentsIncludeListPane() {
		if( tabViewComponentsIncludeListPane == null ) {
			ICFSecSecGroupObj focus = (ICFSecSecGroupObj)getJavaFXFocusAsSecGroup();
			ICFSecSecGroupObj javafxContainer;
			if( ( focus != null ) && ( focus instanceof ICFSecSecGroupObj ) ) {
				javafxContainer = (ICFSecSecGroupObj)focus;
			}
			else {
				javafxContainer = null;
			}
			tabViewComponentsIncludeListPane = javafxSchema.getSecGrpIncFactory().newListPane( cfFormManager, javafxContainer, null, new PageDataComponentsIncludeList(), new RefreshComponentsIncludeList(), false );
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
	implements ICFSecJavaFXSecGrpMembPageCallback
	{
		public PageDataComponentsMemberList() {
		}

		public List<ICFSecSecGrpMembObj> pageData( Long priorClusterId,
		Long priorSecGrpMembId )
		{
			List<ICFSecSecGrpMembObj> dataList;
			ICFSecSecGroupObj focus = (ICFSecSecGroupObj)getJavaFXFocusAsSecGroup();
			if( focus != null ) {
				ICFSecSchemaObj schemaObj = (ICFSecSchemaObj)javafxSchema.getSchema();
				dataList = schemaObj.getSecGrpMembTableObj().pageSecGrpMembByGroupIdx( focus.getRequiredClusterId(),
					focus.getRequiredSecGroupId(),
					priorClusterId,
					priorSecGrpMembId );
			}
			else {
				dataList = new ArrayList<ICFSecSecGrpMembObj>();
			}
			return( dataList );
		}
	}

	public CFBorderPane getTabViewComponentsMemberListPane() {
		if( tabViewComponentsMemberListPane == null ) {
			ICFSecSecGroupObj focus = (ICFSecSecGroupObj)getJavaFXFocusAsSecGroup();
			ICFSecSecGroupObj javafxContainer;
			if( ( focus != null ) && ( focus instanceof ICFSecSecGroupObj ) ) {
				javafxContainer = (ICFSecSecGroupObj)focus;
			}
			else {
				javafxContainer = null;
			}
			tabViewComponentsMemberListPane = javafxSchema.getSecGrpMembFactory().newListPane( cfFormManager, javafxContainer, null, new PageDataComponentsMemberList(), new RefreshComponentsMemberList(), false );
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
	implements ICFSecJavaFXSecGrpIncPageCallback
	{
		public PageDataChildrenIncByGroupList() {
		}

		public List<ICFSecSecGrpIncObj> pageData( Long priorClusterId,
		Long priorSecGrpIncId )
		{
			List<ICFSecSecGrpIncObj> dataList;
			ICFSecSecGroupObj focus = (ICFSecSecGroupObj)getJavaFXFocusAsSecGroup();
			if( focus != null ) {
				ICFSecSchemaObj schemaObj = (ICFSecSchemaObj)javafxSchema.getSchema();
				dataList = schemaObj.getSecGrpIncTableObj().pageSecGrpIncByIncludeIdx( focus.getRequiredClusterId(),
					focus.getRequiredSecGroupId(),
					priorClusterId,
					priorSecGrpIncId );
			}
			else {
				dataList = new ArrayList<ICFSecSecGrpIncObj>();
			}
			return( dataList );
		}
	}

	public CFBorderPane getTabViewChildrenIncByGroupListPane() {
		if( tabViewChildrenIncByGroupListPane == null ) {
			ICFSecSecGroupObj focus = (ICFSecSecGroupObj)getJavaFXFocusAsSecGroup();
			ICFSecSecGroupObj javafxContainer;
			if( ( focus != null ) && ( focus instanceof ICFSecSecGroupObj ) ) {
				javafxContainer = (ICFSecSecGroupObj)focus;
			}
			else {
				javafxContainer = null;
			}
			tabViewChildrenIncByGroupListPane = javafxSchema.getSecGrpIncFactory().newListPane( cfFormManager, javafxContainer, null, new PageDataChildrenIncByGroupList(), new RefreshChildrenIncByGroupList(), false );
		}
		return( tabViewChildrenIncByGroupListPane );
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
	implements ICFSecJavaFXSecGroupFormPageCallback
	{
		public PageDataComponentsFormList() {
		}

		public List<ICFSecSecGroupFormObj> pageData( Long priorClusterId,
		Long priorSecGroupFormId )
		{
			List<ICFSecSecGroupFormObj> dataList;
			ICFSecSecGroupObj focus = (ICFSecSecGroupObj)getJavaFXFocusAsSecGroup();
			if( focus != null ) {
				ICFSecSchemaObj schemaObj = (ICFSecSchemaObj)javafxSchema.getSchema();
				dataList = schemaObj.getSecGroupFormTableObj().pageSecGroupFormByGroupIdx( focus.getRequiredClusterId(),
					focus.getRequiredSecGroupId(),
					priorClusterId,
					priorSecGroupFormId );
			}
			else {
				dataList = new ArrayList<ICFSecSecGroupFormObj>();
			}
			return( dataList );
		}
	}

	public CFBorderPane getTabViewComponentsFormListPane() {
		if( tabViewComponentsFormListPane == null ) {
			ICFSecSecGroupObj focus = (ICFSecSecGroupObj)getJavaFXFocusAsSecGroup();
			ICFSecSecGroupObj javafxContainer;
			if( ( focus != null ) && ( focus instanceof ICFSecSecGroupObj ) ) {
				javafxContainer = (ICFSecSecGroupObj)focus;
			}
			else {
				javafxContainer = null;
			}
			tabViewComponentsFormListPane = javafxSchema.getSecGroupFormFactory().newListPane( cfFormManager, javafxContainer, null, new PageDataComponentsFormList(), new RefreshComponentsFormList(), false );
		}
		return( tabViewComponentsFormListPane );
	}

	public void setPaneMode( CFPane.PaneMode value ) {
		CFPane.PaneMode oldMode = getPaneMode();
		super.setPaneMode( value );
		if( tabViewComponentsIncludeListPane != null ) {
			((ICFSecJavaFXSecGrpIncPaneCommon)tabViewComponentsIncludeListPane).setPaneMode( value );
		}
		if( tabViewComponentsMemberListPane != null ) {
			((ICFSecJavaFXSecGrpMembPaneCommon)tabViewComponentsMemberListPane).setPaneMode( value );
		}
		if( tabViewChildrenIncByGroupListPane != null ) {
			((ICFSecJavaFXSecGrpIncPaneCommon)tabViewChildrenIncByGroupListPane).setPaneMode( value );
		}
		if( tabViewComponentsFormListPane != null ) {
			((ICFSecJavaFXSecGroupFormPaneCommon)tabViewComponentsFormListPane).setPaneMode( value );
		}
	}
}
