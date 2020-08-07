// Description: Java 11 JavaFX Element TabPane implementation for Cluster.

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
 *	CFSecJavaFXClusterEltTabPane JavaFX Element TabPane implementation
 *	for Cluster.
 */
public class CFSecJavaFXClusterEltTabPane
extends CFTabPane
implements ICFSecJavaFXClusterPaneCommon
{
	protected ICFFormManager cfFormManager = null;
	protected ICFSecJavaFXSchema javafxSchema = null;
	protected boolean javafxIsInitializing = true;
	public final String LABEL_TabComponentsHostNodeList = "Optional Components Host Node";
	protected CFTab tabComponentsHostNode = null;
	public final String LABEL_TabComponentsTenantList = "Optional Components Tenant";
	protected CFTab tabComponentsTenant = null;
	public final String LABEL_TabComponentsSecAppList = "Optional Components Security Application";
	protected CFTab tabComponentsSecApp = null;
	public final String LABEL_TabComponentsSecGroupList = "Optional Components Security Group";
	protected CFTab tabComponentsSecGroup = null;
	public final String LABEL_TabComponentsSysClusterList = "Optional Components System Cluster";
	protected CFTab tabComponentsSysCluster = null;
	protected CFBorderPane tabViewComponentsHostNodeListPane = null;
	protected CFBorderPane tabViewComponentsTenantListPane = null;
	protected CFBorderPane tabViewComponentsSecAppListPane = null;
	protected CFBorderPane tabViewComponentsSecGroupListPane = null;
	protected CFBorderPane tabViewComponentsSysClusterListPane = null;

	public CFSecJavaFXClusterEltTabPane( ICFFormManager formManager, ICFSecJavaFXSchema argSchema, ICFSecClusterObj argFocus ) {
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
		setJavaFXFocusAsCluster( argFocus );
		// Wire the newly constructed Panes/Tabs to this TabPane
		tabComponentsHostNode = new CFTab();
		tabComponentsHostNode.setText( LABEL_TabComponentsHostNodeList );
		tabComponentsHostNode.setContent( getTabViewComponentsHostNodeListPane() );
		getTabs().add( tabComponentsHostNode );
		tabComponentsTenant = new CFTab();
		tabComponentsTenant.setText( LABEL_TabComponentsTenantList );
		tabComponentsTenant.setContent( getTabViewComponentsTenantListPane() );
		getTabs().add( tabComponentsTenant );
		tabComponentsSecApp = new CFTab();
		tabComponentsSecApp.setText( LABEL_TabComponentsSecAppList );
		tabComponentsSecApp.setContent( getTabViewComponentsSecAppListPane() );
		getTabs().add( tabComponentsSecApp );
		tabComponentsSecGroup = new CFTab();
		tabComponentsSecGroup.setText( LABEL_TabComponentsSecGroupList );
		tabComponentsSecGroup.setContent( getTabViewComponentsSecGroupListPane() );
		getTabs().add( tabComponentsSecGroup );
		tabComponentsSysCluster = new CFTab();
		tabComponentsSysCluster.setText( LABEL_TabComponentsSysClusterList );
		tabComponentsSysCluster.setContent( getTabViewComponentsSysClusterListPane() );
		getTabs().add( tabComponentsSysCluster );
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
		if( ( value == null ) || ( value instanceof ICFSecClusterObj ) ) {
			super.setJavaFXFocus( value );
		}
		else {
			throw new CFLibUnsupportedClassException( getClass(),
				S_ProcName,
				"value",
				value,
				"ICFSecClusterObj" );
		}
	}

	public void setJavaFXFocusAsCluster( ICFSecClusterObj value ) {
		setJavaFXFocus( value );
	}

	public ICFSecClusterObj getJavaFXFocusAsCluster() {
		return( (ICFSecClusterObj)getJavaFXFocus() );
	}

	protected class RefreshComponentsHostNodeList
	implements ICFRefreshCallback
	{
		public RefreshComponentsHostNodeList() {
		}

		public void refreshMe() {
			// Use page data instead
		}
	}

	protected class PageDataComponentsHostNodeList
	implements ICFSecJavaFXHostNodePageCallback
	{
		public PageDataComponentsHostNodeList() {
		}

		public List<ICFSecHostNodeObj> pageData( Long priorClusterId,
		Long priorHostNodeId )
		{
			List<ICFSecHostNodeObj> dataList;
			ICFSecClusterObj focus = (ICFSecClusterObj)getJavaFXFocusAsCluster();
			if( focus != null ) {
				ICFSecSchemaObj schemaObj = (ICFSecSchemaObj)javafxSchema.getSchema();
				dataList = schemaObj.getHostNodeTableObj().pageHostNodeByClusterIdx( focus.getRequiredId(),
					priorClusterId,
					priorHostNodeId );
			}
			else {
				dataList = new ArrayList<ICFSecHostNodeObj>();
			}
			return( dataList );
		}
	}

	public CFBorderPane getTabViewComponentsHostNodeListPane() {
		if( tabViewComponentsHostNodeListPane == null ) {
			ICFSecClusterObj focus = (ICFSecClusterObj)getJavaFXFocusAsCluster();
			ICFSecClusterObj javafxContainer;
			if( ( focus != null ) && ( focus instanceof ICFSecClusterObj ) ) {
				javafxContainer = (ICFSecClusterObj)focus;
			}
			else {
				javafxContainer = null;
			}
			tabViewComponentsHostNodeListPane = javafxSchema.getHostNodeFactory().newListPane( cfFormManager, javafxContainer, null, new PageDataComponentsHostNodeList(), new RefreshComponentsHostNodeList(), false );
		}
		return( tabViewComponentsHostNodeListPane );
	}

	protected class RefreshComponentsTenantList
	implements ICFRefreshCallback
	{
		public RefreshComponentsTenantList() {
		}

		public void refreshMe() {
			// Use page data instead
		}
	}

	protected class PageDataComponentsTenantList
	implements ICFSecJavaFXTenantPageCallback
	{
		public PageDataComponentsTenantList() {
		}

		public List<ICFSecTenantObj> pageData( Long priorId )
		{
			List<ICFSecTenantObj> dataList;
			ICFSecClusterObj focus = (ICFSecClusterObj)getJavaFXFocusAsCluster();
			if( focus != null ) {
				ICFSecSchemaObj schemaObj = (ICFSecSchemaObj)javafxSchema.getSchema();
				dataList = schemaObj.getTenantTableObj().pageTenantByClusterIdx( focus.getRequiredId(),
					priorId );
			}
			else {
				dataList = new ArrayList<ICFSecTenantObj>();
			}
			return( dataList );
		}
	}

	public CFBorderPane getTabViewComponentsTenantListPane() {
		if( tabViewComponentsTenantListPane == null ) {
			ICFSecClusterObj focus = (ICFSecClusterObj)getJavaFXFocusAsCluster();
			ICFSecClusterObj javafxContainer;
			if( ( focus != null ) && ( focus instanceof ICFSecClusterObj ) ) {
				javafxContainer = (ICFSecClusterObj)focus;
			}
			else {
				javafxContainer = null;
			}
			tabViewComponentsTenantListPane = javafxSchema.getTenantFactory().newListPane( cfFormManager, javafxContainer, null, new PageDataComponentsTenantList(), new RefreshComponentsTenantList(), false );
		}
		return( tabViewComponentsTenantListPane );
	}

	protected class RefreshComponentsSecAppList
	implements ICFRefreshCallback
	{
		public RefreshComponentsSecAppList() {
		}

		public void refreshMe() {
			// Use page data instead
		}
	}

	protected class PageDataComponentsSecAppList
	implements ICFSecJavaFXSecAppPageCallback
	{
		public PageDataComponentsSecAppList() {
		}

		public List<ICFSecSecAppObj> pageData( Long priorClusterId,
		Integer priorSecAppId )
		{
			List<ICFSecSecAppObj> dataList;
			ICFSecClusterObj focus = (ICFSecClusterObj)getJavaFXFocusAsCluster();
			if( focus != null ) {
				ICFSecSchemaObj schemaObj = (ICFSecSchemaObj)javafxSchema.getSchema();
				dataList = schemaObj.getSecAppTableObj().pageSecAppByClusterIdx( focus.getRequiredId(),
					priorClusterId,
					priorSecAppId );
			}
			else {
				dataList = new ArrayList<ICFSecSecAppObj>();
			}
			return( dataList );
		}
	}

	public CFBorderPane getTabViewComponentsSecAppListPane() {
		if( tabViewComponentsSecAppListPane == null ) {
			ICFSecClusterObj focus = (ICFSecClusterObj)getJavaFXFocusAsCluster();
			ICFSecClusterObj javafxContainer;
			if( ( focus != null ) && ( focus instanceof ICFSecClusterObj ) ) {
				javafxContainer = (ICFSecClusterObj)focus;
			}
			else {
				javafxContainer = null;
			}
			tabViewComponentsSecAppListPane = javafxSchema.getSecAppFactory().newListPane( cfFormManager, javafxContainer, null, new PageDataComponentsSecAppList(), new RefreshComponentsSecAppList(), false );
		}
		return( tabViewComponentsSecAppListPane );
	}

	protected class RefreshComponentsSecGroupList
	implements ICFRefreshCallback
	{
		public RefreshComponentsSecGroupList() {
		}

		public void refreshMe() {
			Collection<ICFSecSecGroupObj> dataCollection;
			ICFSecClusterObj focus = (ICFSecClusterObj)getJavaFXFocusAsCluster();
			if( focus != null ) {
				dataCollection = focus.getOptionalComponentsSecGroup( javafxIsInitializing );
			}
			else {
				dataCollection = null;
			}
			CFBorderPane pane = getTabViewComponentsSecGroupListPane();
			ICFSecJavaFXSecGroupPaneList jpList = (ICFSecJavaFXSecGroupPaneList)pane;
			jpList.setJavaFXDataCollection( dataCollection );
		}
	}

	public CFBorderPane getTabViewComponentsSecGroupListPane() {
		if( tabViewComponentsSecGroupListPane == null ) {
			ICFSecClusterObj focus = (ICFSecClusterObj)getJavaFXFocusAsCluster();
			Collection<ICFSecSecGroupObj> dataCollection;
			if( focus != null ) {
				dataCollection = focus.getOptionalComponentsSecGroup( javafxIsInitializing );
			}
			else {
				dataCollection = null;
			}
			ICFSecClusterObj javafxContainer;
			if( ( focus != null ) && ( focus instanceof ICFSecClusterObj ) ) {
				javafxContainer = (ICFSecClusterObj)focus;
			}
			else {
				javafxContainer = null;
			}
			tabViewComponentsSecGroupListPane = javafxSchema.getSecGroupFactory().newListPane( cfFormManager, javafxContainer, null, dataCollection, new RefreshComponentsSecGroupList(), false );
		}
		return( tabViewComponentsSecGroupListPane );
	}

	protected class RefreshComponentsSysClusterList
	implements ICFRefreshCallback
	{
		public RefreshComponentsSysClusterList() {
		}

		public void refreshMe() {
			Collection<ICFSecSysClusterObj> dataCollection;
			ICFSecClusterObj focus = (ICFSecClusterObj)getJavaFXFocusAsCluster();
			if( focus != null ) {
				dataCollection = focus.getOptionalComponentsSysCluster( javafxIsInitializing );
			}
			else {
				dataCollection = null;
			}
			CFBorderPane pane = getTabViewComponentsSysClusterListPane();
			ICFSecJavaFXSysClusterPaneList jpList = (ICFSecJavaFXSysClusterPaneList)pane;
			jpList.setJavaFXDataCollection( dataCollection );
		}
	}

	public CFBorderPane getTabViewComponentsSysClusterListPane() {
		if( tabViewComponentsSysClusterListPane == null ) {
			ICFSecClusterObj focus = (ICFSecClusterObj)getJavaFXFocusAsCluster();
			Collection<ICFSecSysClusterObj> dataCollection;
			if( focus != null ) {
				dataCollection = focus.getOptionalComponentsSysCluster( javafxIsInitializing );
			}
			else {
				dataCollection = null;
			}
			ICFSecClusterObj javafxContainer;
			if( ( focus != null ) && ( focus instanceof ICFSecClusterObj ) ) {
				javafxContainer = (ICFSecClusterObj)focus;
			}
			else {
				javafxContainer = null;
			}
			tabViewComponentsSysClusterListPane = javafxSchema.getSysClusterFactory().newListPane( cfFormManager, javafxContainer, null, dataCollection, new RefreshComponentsSysClusterList(), false );
		}
		return( tabViewComponentsSysClusterListPane );
	}

	public void setPaneMode( CFPane.PaneMode value ) {
		CFPane.PaneMode oldMode = getPaneMode();
		super.setPaneMode( value );
		if( tabViewComponentsHostNodeListPane != null ) {
			((ICFSecJavaFXHostNodePaneCommon)tabViewComponentsHostNodeListPane).setPaneMode( value );
		}
		if( tabViewComponentsTenantListPane != null ) {
			((ICFSecJavaFXTenantPaneCommon)tabViewComponentsTenantListPane).setPaneMode( value );
		}
		if( tabViewComponentsSecAppListPane != null ) {
			((ICFSecJavaFXSecAppPaneCommon)tabViewComponentsSecAppListPane).setPaneMode( value );
		}
		if( tabViewComponentsSecGroupListPane != null ) {
			((ICFSecJavaFXSecGroupPaneCommon)tabViewComponentsSecGroupListPane).setPaneMode( value );
		}
		if( tabViewComponentsSysClusterListPane != null ) {
			((ICFSecJavaFXSysClusterPaneCommon)tabViewComponentsSysClusterListPane).setPaneMode( value );
		}
	}
}
