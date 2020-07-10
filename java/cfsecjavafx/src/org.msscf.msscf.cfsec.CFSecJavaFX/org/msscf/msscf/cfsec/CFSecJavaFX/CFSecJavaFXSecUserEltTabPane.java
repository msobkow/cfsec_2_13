// Description: Java 11 JavaFX Element TabPane implementation for SecUser.

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
 *	CFSecJavaFXSecUserEltTabPane JavaFX Element TabPane implementation
 *	for SecUser.
 */
public class CFSecJavaFXSecUserEltTabPane
extends CFTabPane
implements ICFSecJavaFXSecUserPaneCommon
{
	protected ICFFormManager cfFormManager = null;
	protected ICFSecJavaFXSchema javafxSchema = null;
	protected boolean javafxIsInitializing = true;
	public final String LABEL_TabComponentsSecDevList = "Optional Components Security Device";
	protected CFTab tabComponentsSecDev = null;
	public final String LABEL_TabComponentsSecSessList = "Optional Components Security Session";
	protected CFTab tabComponentsSecSess = null;
	public final String LABEL_TabChildrenSecProxyList = "Optional Children Security Proxy Session";
	protected CFTab tabChildrenSecProxy = null;
	public final String LABEL_TabChildrenSecGrpMembList = "Optional Children Security Group Members";
	protected CFTab tabChildrenSecGrpMemb = null;
	public final String LABEL_TabChildrenTSecGrpMembList = "Optional Children Tenant Security Group Members";
	protected CFTab tabChildrenTSecGrpMemb = null;
	protected CFBorderPane tabViewComponentsSecDevListPane = null;
	protected CFBorderPane tabViewComponentsSecSessListPane = null;
	protected CFBorderPane tabViewChildrenSecProxyListPane = null;
	protected CFBorderPane tabViewChildrenSecGrpMembListPane = null;
	protected CFBorderPane tabViewChildrenTSecGrpMembListPane = null;

	public CFSecJavaFXSecUserEltTabPane( ICFFormManager formManager, ICFSecJavaFXSchema argSchema, ICFSecSecUserObj argFocus ) {
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
		setJavaFXFocusAsSecUser( argFocus );
		// Wire the newly constructed Panes/Tabs to this TabPane
		tabComponentsSecDev = new CFTab();
		tabComponentsSecDev.setText( LABEL_TabComponentsSecDevList );
		tabComponentsSecDev.setContent( getTabViewComponentsSecDevListPane() );
		getTabs().add( tabComponentsSecDev );
		tabComponentsSecSess = new CFTab();
		tabComponentsSecSess.setText( LABEL_TabComponentsSecSessList );
		tabComponentsSecSess.setContent( getTabViewComponentsSecSessListPane() );
		getTabs().add( tabComponentsSecSess );
		tabChildrenSecProxy = new CFTab();
		tabChildrenSecProxy.setText( LABEL_TabChildrenSecProxyList );
		tabChildrenSecProxy.setContent( getTabViewChildrenSecProxyListPane() );
		getTabs().add( tabChildrenSecProxy );
		tabChildrenSecGrpMemb = new CFTab();
		tabChildrenSecGrpMemb.setText( LABEL_TabChildrenSecGrpMembList );
		tabChildrenSecGrpMemb.setContent( getTabViewChildrenSecGrpMembListPane() );
		getTabs().add( tabChildrenSecGrpMemb );
		tabChildrenTSecGrpMemb = new CFTab();
		tabChildrenTSecGrpMemb.setText( LABEL_TabChildrenTSecGrpMembList );
		tabChildrenTSecGrpMemb.setContent( getTabViewChildrenTSecGrpMembListPane() );
		getTabs().add( tabChildrenTSecGrpMemb );
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
		if( ( value == null ) || ( value instanceof ICFSecSecUserObj ) ) {
			super.setJavaFXFocus( value );
		}
		else {
			throw new CFLibUnsupportedClassException( getClass(),
				S_ProcName,
				"value",
				value,
				"ICFSecSecUserObj" );
		}
	}

	public void setJavaFXFocusAsSecUser( ICFSecSecUserObj value ) {
		setJavaFXFocus( value );
	}

	public ICFSecSecUserObj getJavaFXFocusAsSecUser() {
		return( (ICFSecSecUserObj)getJavaFXFocus() );
	}

	protected class RefreshComponentsSecDevList
	implements ICFRefreshCallback
	{
		public RefreshComponentsSecDevList() {
		}

		public void refreshMe() {
			// Use page data instead
		}
	}

	protected class PageDataComponentsSecDevList
	implements ICFSecJavaFXSecDevicePageCallback
	{
		public PageDataComponentsSecDevList() {
		}

		public List<ICFSecSecDeviceObj> pageData( UUID priorSecUserId,
		String priorDevName )
		{
			List<ICFSecSecDeviceObj> dataList;
			ICFSecSecUserObj focus = (ICFSecSecUserObj)getJavaFXFocusAsSecUser();
			if( focus != null ) {
				ICFSecSchemaObj schemaObj = (ICFSecSchemaObj)javafxSchema.getSchema();
				dataList = schemaObj.getSecDeviceTableObj().pageSecDeviceByUserIdx( focus.getRequiredSecUserId(),
					priorSecUserId,
					priorDevName );
			}
			else {
				dataList = new ArrayList<ICFSecSecDeviceObj>();
			}
			return( dataList );
		}
	}

	public CFBorderPane getTabViewComponentsSecDevListPane() {
		if( tabViewComponentsSecDevListPane == null ) {
			ICFSecSecUserObj focus = (ICFSecSecUserObj)getJavaFXFocusAsSecUser();
			ICFSecSecUserObj javafxContainer;
			if( ( focus != null ) && ( focus instanceof ICFSecSecUserObj ) ) {
				javafxContainer = (ICFSecSecUserObj)focus;
			}
			else {
				javafxContainer = null;
			}
			tabViewComponentsSecDevListPane = javafxSchema.getSecDeviceFactory().newListPane( cfFormManager, javafxContainer, null, new PageDataComponentsSecDevList(), new RefreshComponentsSecDevList(), false );
		}
		return( tabViewComponentsSecDevListPane );
	}

	protected class RefreshComponentsSecSessList
	implements ICFRefreshCallback
	{
		public RefreshComponentsSecSessList() {
		}

		public void refreshMe() {
			// Use page data instead
		}
	}

	protected class PageDataComponentsSecSessList
	implements ICFSecJavaFXSecSessionPageCallback
	{
		public PageDataComponentsSecSessList() {
		}

		public List<ICFSecSecSessionObj> pageData( UUID priorSecSessionId )
		{
			List<ICFSecSecSessionObj> dataList;
			ICFSecSecUserObj focus = (ICFSecSecUserObj)getJavaFXFocusAsSecUser();
			if( focus != null ) {
				ICFSecSchemaObj schemaObj = (ICFSecSchemaObj)javafxSchema.getSchema();
				dataList = schemaObj.getSecSessionTableObj().pageSecSessionBySecUserIdx( focus.getRequiredSecUserId(),
					priorSecSessionId );
			}
			else {
				dataList = new ArrayList<ICFSecSecSessionObj>();
			}
			return( dataList );
		}
	}

	public CFBorderPane getTabViewComponentsSecSessListPane() {
		if( tabViewComponentsSecSessListPane == null ) {
			ICFSecSecUserObj focus = (ICFSecSecUserObj)getJavaFXFocusAsSecUser();
			ICFSecSecUserObj javafxContainer;
			if( ( focus != null ) && ( focus instanceof ICFSecSecUserObj ) ) {
				javafxContainer = (ICFSecSecUserObj)focus;
			}
			else {
				javafxContainer = null;
			}
			tabViewComponentsSecSessListPane = javafxSchema.getSecSessionFactory().newListPane( cfFormManager, javafxContainer, null, new PageDataComponentsSecSessList(), new RefreshComponentsSecSessList(), false );
		}
		return( tabViewComponentsSecSessListPane );
	}

	protected class RefreshChildrenSecProxyList
	implements ICFRefreshCallback
	{
		public RefreshChildrenSecProxyList() {
		}

		public void refreshMe() {
			// Use page data instead
		}
	}

	protected class PageDataChildrenSecProxyList
	implements ICFSecJavaFXSecSessionPageCallback
	{
		public PageDataChildrenSecProxyList() {
		}

		public List<ICFSecSecSessionObj> pageData( UUID priorSecSessionId )
		{
			List<ICFSecSecSessionObj> dataList;
			ICFSecSecUserObj focus = (ICFSecSecUserObj)getJavaFXFocusAsSecUser();
			if( focus != null ) {
				ICFSecSchemaObj schemaObj = (ICFSecSchemaObj)javafxSchema.getSchema();
				dataList = schemaObj.getSecSessionTableObj().pageSecSessionBySecProxyIdx( focus.getRequiredSecUserId(),
					priorSecSessionId );
			}
			else {
				dataList = new ArrayList<ICFSecSecSessionObj>();
			}
			return( dataList );
		}
	}

	public CFBorderPane getTabViewChildrenSecProxyListPane() {
		if( tabViewChildrenSecProxyListPane == null ) {
			ICFSecSecUserObj focus = (ICFSecSecUserObj)getJavaFXFocusAsSecUser();
			ICFSecSecUserObj javafxContainer;
			if( ( focus != null ) && ( focus instanceof ICFSecSecUserObj ) ) {
				javafxContainer = (ICFSecSecUserObj)focus;
			}
			else {
				javafxContainer = null;
			}
			tabViewChildrenSecProxyListPane = javafxSchema.getSecSessionFactory().newListPane( cfFormManager, javafxContainer, null, new PageDataChildrenSecProxyList(), new RefreshChildrenSecProxyList(), false );
		}
		return( tabViewChildrenSecProxyListPane );
	}

	protected class RefreshChildrenSecGrpMembList
	implements ICFRefreshCallback
	{
		public RefreshChildrenSecGrpMembList() {
		}

		public void refreshMe() {
			// Use page data instead
		}
	}

	protected class PageDataChildrenSecGrpMembList
	implements ICFSecJavaFXSecGrpMembPageCallback
	{
		public PageDataChildrenSecGrpMembList() {
		}

		public List<ICFSecSecGrpMembObj> pageData( Long priorClusterId,
		Long priorSecGrpMembId )
		{
			List<ICFSecSecGrpMembObj> dataList;
			ICFSecSecUserObj focus = (ICFSecSecUserObj)getJavaFXFocusAsSecUser();
			if( focus != null ) {
				ICFSecSchemaObj schemaObj = (ICFSecSchemaObj)javafxSchema.getSchema();
				dataList = schemaObj.getSecGrpMembTableObj().pageSecGrpMembByUserIdx( focus.getRequiredSecUserId(),
					priorClusterId,
					priorSecGrpMembId );
			}
			else {
				dataList = new ArrayList<ICFSecSecGrpMembObj>();
			}
			return( dataList );
		}
	}

	public CFBorderPane getTabViewChildrenSecGrpMembListPane() {
		if( tabViewChildrenSecGrpMembListPane == null ) {
			ICFSecSecUserObj focus = (ICFSecSecUserObj)getJavaFXFocusAsSecUser();
			ICFSecSecGroupObj javafxContainer;
			if( ( focus != null ) && ( focus instanceof ICFSecSecGroupObj ) ) {
				javafxContainer = (ICFSecSecGroupObj)focus;
			}
			else {
				javafxContainer = null;
			}
			tabViewChildrenSecGrpMembListPane = javafxSchema.getSecGrpMembFactory().newListPane( cfFormManager, javafxContainer, null, new PageDataChildrenSecGrpMembList(), new RefreshChildrenSecGrpMembList(), false );
		}
		return( tabViewChildrenSecGrpMembListPane );
	}

	protected class RefreshChildrenTSecGrpMembList
	implements ICFRefreshCallback
	{
		public RefreshChildrenTSecGrpMembList() {
		}

		public void refreshMe() {
			// Use page data instead
		}
	}

	protected class PageDataChildrenTSecGrpMembList
	implements ICFSecJavaFXTSecGrpMembPageCallback
	{
		public PageDataChildrenTSecGrpMembList() {
		}

		public List<ICFSecTSecGrpMembObj> pageData( Long priorTenantId,
		Long priorTSecGrpMembId )
		{
			List<ICFSecTSecGrpMembObj> dataList;
			ICFSecSecUserObj focus = (ICFSecSecUserObj)getJavaFXFocusAsSecUser();
			if( focus != null ) {
				ICFSecSchemaObj schemaObj = (ICFSecSchemaObj)javafxSchema.getSchema();
				dataList = schemaObj.getTSecGrpMembTableObj().pageTSecGrpMembByUserIdx( focus.getRequiredSecUserId(),
					priorTenantId,
					priorTSecGrpMembId );
			}
			else {
				dataList = new ArrayList<ICFSecTSecGrpMembObj>();
			}
			return( dataList );
		}
	}

	public CFBorderPane getTabViewChildrenTSecGrpMembListPane() {
		if( tabViewChildrenTSecGrpMembListPane == null ) {
			ICFSecSecUserObj focus = (ICFSecSecUserObj)getJavaFXFocusAsSecUser();
			ICFSecTSecGroupObj javafxContainer;
			if( ( focus != null ) && ( focus instanceof ICFSecTSecGroupObj ) ) {
				javafxContainer = (ICFSecTSecGroupObj)focus;
			}
			else {
				javafxContainer = null;
			}
			tabViewChildrenTSecGrpMembListPane = javafxSchema.getTSecGrpMembFactory().newListPane( cfFormManager, javafxContainer, null, new PageDataChildrenTSecGrpMembList(), new RefreshChildrenTSecGrpMembList(), false );
		}
		return( tabViewChildrenTSecGrpMembListPane );
	}

	public void setPaneMode( CFPane.PaneMode value ) {
		CFPane.PaneMode oldMode = getPaneMode();
		super.setPaneMode( value );
		if( tabViewComponentsSecDevListPane != null ) {
			((ICFSecJavaFXSecDevicePaneCommon)tabViewComponentsSecDevListPane).setPaneMode( value );
		}
		if( tabViewComponentsSecSessListPane != null ) {
			((ICFSecJavaFXSecSessionPaneCommon)tabViewComponentsSecSessListPane).setPaneMode( value );
		}
		if( tabViewChildrenSecProxyListPane != null ) {
			((ICFSecJavaFXSecSessionPaneCommon)tabViewChildrenSecProxyListPane).setPaneMode( value );
		}
		if( tabViewChildrenSecGrpMembListPane != null ) {
			((ICFSecJavaFXSecGrpMembPaneCommon)tabViewChildrenSecGrpMembListPane).setPaneMode( value );
		}
		if( tabViewChildrenTSecGrpMembListPane != null ) {
			((ICFSecJavaFXTSecGrpMembPaneCommon)tabViewChildrenTSecGrpMembListPane).setPaneMode( value );
		}
	}
}
