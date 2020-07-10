// Description: Java 13 Cust JavaFX Schema.

/*
 *	CF Sec Cust JavaFX Implementation
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
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
 */

package org.msscf.msscf.cfseccust.CFSecCust;

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import java.security.KeyStore;

import javafx.application.*;
import javafx.geometry.Orientation;
import javafx.scene.*;
import javafx.scene.control.ScrollPane;
import javafx.scene.control.SplitPane;
import javafx.scene.control.Tab;
import javafx.scene.control.TabPane;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import javafx.scene.control.TitledPane;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.Pane;
import javafx.stage.*;

import org.apache.commons.codec.binary.Base64;

import org.msscf.msscf.cflib.CFLib.*;
import org.msscf.msscf.cflib.CFLib.JavaFX.*;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfsec.CFSecJavaFX.*;
import org.msscf.msscf.cfsec.CFSecObj.*;

public class CFSecCustFacetPane
extends CFBorderPane
implements ICFForm,
	ICFSecAuthorizationCallbacks
{
	protected ICFFormManager cfFormManager = null;
	protected ICFSecCustSchema custSchema = null;
	protected ICFSecAuthorizationCallbacks authorizationCallbacks = null;
	protected CFSecCustOpenKeystorePane paneOpenKeystore = null;
	protected CFSecCustCreateKeystorePane paneCreateKeystore = null;
	protected CFSecCustOpenDeviceKeyPane paneOpenDeviceKey = null;
	protected CFSecCustDisplayPublicKeyPane paneDisplayPublicKey = null;
	protected CFSecCustLoginPane paneLogin = null;
	protected CFSecCustSessionPane paneSession = null;
	protected CFSecCustSystemTablesPane paneSystemTables = null;
	protected CFSecCustClusterTablesPane paneClusterTables = null;
	protected CFSecCustTenantTablesPane paneTenantTables = null;
	protected CFSecCustFileImportPane paneFileImport = null;
	protected CFSecCustConfirmLogoutPane paneConfirmLogout = null;
	protected CFSecCustConfirmExitAppPane paneConfirmExitApp = null;

	public CFSecCustFacetPane(
		ICFFormManager formManager, 
		ICFSecCustSchema argSchema )
	{
		super();
		final String S_ProcName = "construct";
		if( formManager == null ) {
			throw new CFLibNullArgumentException( getClass(),
				S_ProcName,
				1,
				"formManager" );
		}
		cfFormManager = formManager;
		custSchema = argSchema;
		paneLogin = new CFSecCustLoginPane( cfFormManager, argSchema, this );
		paneSession = new CFSecCustSessionPane( cfFormManager, argSchema, this );
		paneOpenKeystore = new CFSecCustOpenKeystorePane( cfFormManager, argSchema, this );
		paneCreateKeystore = new CFSecCustCreateKeystorePane( cfFormManager, argSchema, this );
		paneOpenDeviceKey = new CFSecCustOpenDeviceKeyPane( cfFormManager, argSchema, this );
		paneDisplayPublicKey = new CFSecCustDisplayPublicKeyPane( cfFormManager, argSchema, this );
		paneSystemTables = new CFSecCustSystemTablesPane( cfFormManager, argSchema, this );
		paneClusterTables = new CFSecCustClusterTablesPane( cfFormManager, argSchema, this );
		paneTenantTables = new CFSecCustTenantTablesPane( cfFormManager, argSchema, this );
		paneFileImport = new CFSecCustFileImportPane( cfFormManager, argSchema, this );
		paneConfirmLogout = new CFSecCustConfirmLogoutPane( cfFormManager, argSchema, this );
		paneConfirmExitApp = new CFSecCustConfirmExitAppPane( cfFormManager, argSchema, this );
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

	public void forceCancelAndClose() {
		if( cfFormManager != null ) {
			if( cfFormManager.getCurrentForm() == this ) {
				cfFormManager.closeCurrentForm();
			}
		}
	}

	public void exitApplication() {
		Platform.exit();
		System.exit( 0 );
	}

	public void showOpenKeystore() {
		if( custSchema != null ) {
			paneOpenKeystore.setCustSchema( custSchema );
		}
		cfFormManager.setRootForm( paneOpenKeystore );
	}

	public void showCreateKeystore() {
		if( custSchema != null ) {
			paneCreateKeystore.setCustSchema( custSchema );
		}
		cfFormManager.setRootForm( paneCreateKeystore );
	}

	public void showOpenDeviceKey() {
		if( custSchema != null ) {
			paneOpenDeviceKey.setCustSchema( custSchema );
		}
		cfFormManager.setRootForm( paneOpenDeviceKey );
	}

	public void showDisplayPublicKey() {
		if( custSchema != null ) {
			paneDisplayPublicKey.setCustSchema( custSchema );
		}
		cfFormManager.setRootForm( paneDisplayPublicKey );
	}

	public void showLogin() {
		if( custSchema != null ) {
			paneLogin.setCustSchema( custSchema );
		}
		cfFormManager.setRootForm( paneLogin );
	}

	public void showSession() {
		if( custSchema != null ) {
			paneSession.setCustSchema( custSchema );
		}
		cfFormManager.setRootForm( paneSession );
	}

	public void showSystemTables() {
		if( custSchema != null ) {
			paneSystemTables.setCustSchema( custSchema );
		}
		cfFormManager.pushForm( paneSystemTables );
	}

	public void showClusterTables() {
		if( custSchema != null ) {
			paneClusterTables.setCustSchema( custSchema );
		}
		cfFormManager.pushForm( paneClusterTables );
	}

	public void showTenantTables() {
		if( custSchema != null ) {
			paneTenantTables.setCustSchema( custSchema );
		}
		cfFormManager.pushForm( paneTenantTables );
	}

	public void showFileImport() {
		if( custSchema != null ) {
			paneFileImport.setCustSchema( custSchema );
		}
		cfFormManager.pushForm( paneFileImport );
	}

	public void showConfirmLogout() {
		if( custSchema != null ) {
			paneConfirmLogout.setCustSchema( custSchema );
		}
		cfFormManager.pushForm( paneConfirmLogout );
	}

	public void showConfirmExitApp() {
		if( custSchema != null ) {
			paneConfirmExitApp.setCustSchema( custSchema );
		}
		cfFormManager.pushForm( paneConfirmExitApp );
	}

	public ICFSecCustSchema getCustSchema() {
		return( custSchema );
	}

	public void setCustSchema( ICFSecCustSchema argSchema ) {
		final String S_ProcName = "setCustSchema";
		final String S_ArgNameSchema = "argSchema";
		if( argSchema == null ) {
			throw new CFLibNullArgumentException( getClass(),
				S_ProcName,
				1,
				S_ArgNameSchema );
		}
		custSchema = argSchema;
		paneOpenKeystore.setCustSchema( custSchema );
		paneCreateKeystore.setCustSchema( custSchema );
		paneOpenDeviceKey.setCustSchema( custSchema );
		paneDisplayPublicKey.setCustSchema( custSchema );
		paneLogin.setCustSchema( custSchema );
		paneSession.setCustSchema( custSchema );
		paneFileImport.setCustSchema( custSchema );
		paneConfirmLogout.setCustSchema( custSchema );
		paneConfirmExitApp.setCustSchema( custSchema );
	}

	public ICFSecAuthorizationCallbacks getAuthorizationCallbacks() {
		return( authorizationCallbacks );
	}

	public void setAuthorizationCallbacks( ICFSecAuthorizationCallbacks callbacks ) {
		final String S_ProcName = "setAuthorizationCallbacks";
		if( callbacks == null ) {
			throw new CFLibNullArgumentException( getClass(),
				S_ProcName,
				1,
				"callbacks" );
		}
		authorizationCallbacks = callbacks;
	}

	public void loggedIn() {
		if( authorizationCallbacks != null ) {
			authorizationCallbacks.loggedIn();
		}
	}

	public void preLogout() {
		if( authorizationCallbacks != null ) {
			authorizationCallbacks.preLogout();
		}
	}
}
