// Description: Java 11 JavaFX Element TabPane implementation for ServiceType.

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

package org.msscf.msscf.v2_13.cfsec.cfsec.CFSecJavaFX;

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import java.util.List;
import javafx.scene.Parent;
import javafx.scene.control.ScrollPane;
import javafx.scene.control.ScrollPane.ScrollBarPolicy;
import org.msscf.msscf.v2_13.cflib.CFLib.*;
import org.msscf.msscf.v2_13.cflib.CFLib.JavaFX.*;
import org.apache.commons.codec.binary.Base64;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfsec.CFSecObj.*;

/**
 *	CFSecJavaFXServiceTypeEltTabPane JavaFX Element TabPane implementation
 *	for ServiceType.
 */
public class CFSecJavaFXServiceTypeEltTabPane
extends CFTabPane
implements ICFSecJavaFXServiceTypePaneCommon
{
	protected ICFFormManager cfFormManager = null;
	protected ICFSecJavaFXSchema javafxSchema = null;
	protected boolean javafxIsInitializing = true;
	public final String LABEL_TabChildrenDeployedList = "Optional Children Deployed";
	protected CFTab tabChildrenDeployed = null;
	protected CFBorderPane tabViewChildrenDeployedListPane = null;

	public CFSecJavaFXServiceTypeEltTabPane( ICFFormManager formManager, ICFSecJavaFXSchema argSchema, ICFSecServiceTypeObj argFocus ) {
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
		setJavaFXFocusAsServiceType( argFocus );
		// Wire the newly constructed Panes/Tabs to this TabPane
		tabChildrenDeployed = new CFTab();
		tabChildrenDeployed.setText( LABEL_TabChildrenDeployedList );
		tabChildrenDeployed.setContent( getTabViewChildrenDeployedListPane() );
		getTabs().add( tabChildrenDeployed );
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
		if( ( value == null ) || ( value instanceof ICFSecServiceTypeObj ) ) {
			super.setJavaFXFocus( value );
		}
		else {
			throw new CFLibUnsupportedClassException( getClass(),
				S_ProcName,
				"value",
				value,
				"ICFSecServiceTypeObj" );
		}
	}

	public void setJavaFXFocusAsServiceType( ICFSecServiceTypeObj value ) {
		setJavaFXFocus( value );
	}

	public ICFSecServiceTypeObj getJavaFXFocusAsServiceType() {
		return( (ICFSecServiceTypeObj)getJavaFXFocus() );
	}

	protected class RefreshChildrenDeployedList
	implements ICFRefreshCallback
	{
		public RefreshChildrenDeployedList() {
		}

		public void refreshMe() {
			// Use page data instead
		}
	}

	protected class PageDataChildrenDeployedList
	implements ICFSecJavaFXServicePageCallback
	{
		public PageDataChildrenDeployedList() {
		}

		public List<ICFSecServiceObj> pageData( Long priorClusterId,
		Long priorServiceId )
		{
			List<ICFSecServiceObj> dataList;
			ICFSecServiceTypeObj focus = (ICFSecServiceTypeObj)getJavaFXFocusAsServiceType();
			if( focus != null ) {
				ICFSecSchemaObj schemaObj = (ICFSecSchemaObj)javafxSchema.getSchema();
				dataList = schemaObj.getServiceTableObj().pageServiceByTypeIdx( focus.getRequiredServiceTypeId(),
					priorClusterId,
					priorServiceId );
			}
			else {
				dataList = new ArrayList<ICFSecServiceObj>();
			}
			return( dataList );
		}
	}

	public CFBorderPane getTabViewChildrenDeployedListPane() {
		if( tabViewChildrenDeployedListPane == null ) {
			ICFSecServiceTypeObj focus = (ICFSecServiceTypeObj)getJavaFXFocusAsServiceType();
			ICFSecHostNodeObj javafxContainer;
			if( ( focus != null ) && ( focus instanceof ICFSecHostNodeObj ) ) {
				javafxContainer = (ICFSecHostNodeObj)focus;
			}
			else {
				javafxContainer = null;
			}
			tabViewChildrenDeployedListPane = javafxSchema.getServiceFactory().newListPane( cfFormManager, javafxContainer, null, new PageDataChildrenDeployedList(), new RefreshChildrenDeployedList(), false );
		}
		return( tabViewChildrenDeployedListPane );
	}

	public void setPaneMode( CFPane.PaneMode value ) {
		CFPane.PaneMode oldMode = getPaneMode();
		super.setPaneMode( value );
		if( tabViewChildrenDeployedListPane != null ) {
			((ICFSecJavaFXServicePaneCommon)tabViewChildrenDeployedListPane).setPaneMode( value );
		}
	}
}
