// Description: Java 11 JavaFX Element TabPane implementation for ISOCcy.

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

package org.msscf.msscf.cfsec.v2_13.cfsec.CFSecJavaFX;

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import java.util.List;
import javafx.scene.Parent;
import javafx.scene.control.ScrollPane;
import javafx.scene.control.ScrollPane.ScrollBarPolicy;
import org.msscf.msscf.cflib.v2_13.CFLib.*;
import org.msscf.msscf.cflib.v2_13.CFLib.JavaFX.*;
import org.apache.commons.codec.binary.Base64;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfsec.CFSecObj.*;

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
