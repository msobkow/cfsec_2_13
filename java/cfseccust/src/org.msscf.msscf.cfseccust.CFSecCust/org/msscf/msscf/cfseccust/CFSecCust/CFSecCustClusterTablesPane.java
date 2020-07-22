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
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.HPos;
import javafx.geometry.Insets;
import javafx.geometry.Orientation;
import javafx.geometry.Pos;
import javafx.scene.*;
import javafx.scene.control.Button;
import javafx.scene.control.ButtonType;
import javafx.scene.control.Label;
import javafx.scene.control.PasswordField;
import javafx.scene.control.ScrollPane;
import javafx.scene.control.ScrollPane.ScrollBarPolicy;
import javafx.scene.control.SplitPane;
import javafx.scene.control.Tab;
import javafx.scene.control.TabPane;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import javafx.scene.control.TitledPane;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.ColumnConstraints;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.Pane;
import javafx.scene.layout.Priority;
import javafx.scene.layout.VBox;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import javafx.stage.*;

import org.apache.commons.codec.binary.Base64;

import org.msscf.msscf.cflib.CFLib.*;
import org.msscf.msscf.cflib.CFLib.JavaFX.*;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfsec.CFSecJavaFX.*;
import org.msscf.msscf.cfsec.CFSecObj.*;

public class CFSecCustClusterTablesPane
extends CFBorderPane
implements ICFForm
{
	protected final String S_FormName = "Cluster";
	protected ICFFormManager cfFormManager = null;
	protected ICFSecCustSchema custSchema = null;
	protected CFSecCustFacetPane facetPane = null;
	protected CFLabel labelTitle = null;
	protected ScrollPane scrollButtons = null;
	protected CFVBox vboxButtons = null;
	protected CFButton buttonHostNode = null;
	protected CFButton buttonManageSecGroup = null;
	protected CFButton buttonSecApp = null;
	protected CFButton buttonSecDevice = null;
	protected CFButton buttonSecUser = null;
	protected CFButton buttonTenant = null;
	protected CFButton buttonBack = null;

	public CFSecCustClusterTablesPane(
		ICFFormManager formManager, 
		ICFSecCustSchema argSchema,
		CFSecCustFacetPane argFacet )
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
		facetPane = argFacet;

		labelTitle = new CFLabel();
		labelTitle.setText( "Maintain Cluster Tables" );
		Font f = labelTitle.getFont();
		Font largeBold = Font.font( f.getFamily(), FontWeight.BOLD, 20 );
		labelTitle.setFont( largeBold );
		labelTitle.setMinHeight( 35 );
		labelTitle.setMaxHeight( 35 );
		labelTitle.setMinWidth( 200 );
		labelTitle.setAlignment( Pos.CENTER );

		vboxButtons = new CFVBox( 10 );
		vboxButtons.setMinWidth( 220 );
		vboxButtons.setAlignment( Pos.TOP_CENTER );

		buttonHostNode = new CFButton();
		buttonHostNode.setVisible( true );
		buttonHostNode.setMinWidth( 200 );
		buttonHostNode.setMaxWidth( 200 );
		buttonHostNode.setPrefWidth( 200 );
		buttonHostNode.setMinHeight( 25 );
		buttonHostNode.setMaxHeight( 25 );
		buttonHostNode.setPrefHeight( 25 );
		vboxButtons.getChildren().add( buttonHostNode );
		buttonHostNode.setText( "Host Node..." );
		buttonHostNode.setOnAction( new EventHandler<ActionEvent>() {
			@Override public void handle( ActionEvent e ) {
				try {
					CFBorderPane finderForm = custSchema.getJavaFXSchema().getHostNodeFactory().newFinderForm( cfFormManager );
					cfFormManager.pushForm( finderForm );
				}
				catch( Throwable t ) {
					CFConsole.formException( S_FormName, ((CFButton)e.getSource()).getText(), t );
				}
			}
		});

		buttonManageSecGroup = new CFButton();
		buttonManageSecGroup.setVisible( true );
		buttonManageSecGroup.setMinWidth( 200 );
		buttonManageSecGroup.setMaxWidth( 200 );
		buttonManageSecGroup.setPrefWidth( 200 );
		buttonManageSecGroup.setMinHeight( 25 );
		buttonManageSecGroup.setMaxHeight( 25 );
		buttonManageSecGroup.setPrefHeight( 25 );
		vboxButtons.getChildren().add( buttonManageSecGroup );
		buttonManageSecGroup.setText( "Manage Sec Group..." );
		buttonManageSecGroup.setOnAction( new EventHandler<ActionEvent>() {
			@Override public void handle( ActionEvent e ) {
				try {
					CFBorderPane manageSecGroupForm = custSchema.newManageClusterSecGroupForm( cfFormManager );
					cfFormManager.pushForm( manageSecGroupForm );
				}
				catch( Throwable t ) {
					CFConsole.formException( S_FormName, ((CFButton)e.getSource()).getText(), t );
				}
			}
		});

		buttonSecApp = new CFButton();
		buttonSecApp.setVisible( true );
		buttonSecApp.setMinWidth( 200 );
		buttonSecApp.setMaxWidth( 200 );
		buttonSecApp.setPrefWidth( 200 );
		buttonSecApp.setMinHeight( 25 );
		buttonSecApp.setMaxHeight( 25 );
		buttonSecApp.setPrefHeight( 25 );
		vboxButtons.getChildren().add( buttonSecApp );
		buttonSecApp.setText( "Sec App..." );
		buttonSecApp.setOnAction( new EventHandler<ActionEvent>() {
			@Override public void handle( ActionEvent e ) {
				try {
					CFBorderPane finderForm = custSchema.getJavaFXSchema().getSecAppFactory().newFinderForm( cfFormManager );
					cfFormManager.pushForm( finderForm );
				}
				catch( Throwable t ) {
					CFConsole.formException( S_FormName, ((CFButton)e.getSource()).getText(), t );
				}
			}
		});

		buttonSecUser = new CFButton();
		buttonSecUser.setVisible( true );
		buttonSecUser.setMinWidth( 200 );
		buttonSecUser.setMaxWidth( 200 );
		buttonSecUser.setPrefWidth( 200 );
		buttonSecUser.setMinHeight( 25 );
		buttonSecUser.setMaxHeight( 25 );
		buttonSecUser.setPrefHeight( 25 );
		vboxButtons.getChildren().add( buttonSecUser );
		buttonSecUser.setText( "Sec User..." );
		buttonSecUser.setOnAction( new EventHandler<ActionEvent>() {
			@Override public void handle( ActionEvent e ) {
				try {
					CFBorderPane finderForm = custSchema.getJavaFXSchema().getSecUserFactory().newFinderForm( cfFormManager );
					cfFormManager.pushForm( finderForm );
				}
				catch( Throwable t ) {
					CFConsole.formException( S_FormName, ((CFButton)e.getSource()).getText(), t );
				}
			}
		});

		buttonTenant = new CFButton();
		buttonTenant.setVisible( true );
		buttonTenant.setMinWidth( 200 );
		buttonTenant.setMaxWidth( 200 );
		buttonTenant.setPrefWidth( 200 );
		buttonTenant.setMinHeight( 25 );
		buttonTenant.setMaxHeight( 25 );
		buttonTenant.setPrefHeight( 25 );
		vboxButtons.getChildren().add( buttonTenant );
		buttonTenant.setText( "Tenant..." );
		buttonTenant.setOnAction( new EventHandler<ActionEvent>() {
			@Override public void handle( ActionEvent e ) {
				try {
					CFBorderPane finderForm = custSchema.getJavaFXSchema().getTenantFactory().newFinderForm( cfFormManager );
					cfFormManager.pushForm( finderForm );
				}
				catch( Throwable t ) {
					CFConsole.formException( S_FormName, ((CFButton)e.getSource()).getText(), t );
				}
			}
		});

		buttonBack = new CFButton();
		buttonBack.setVisible( true );
		buttonBack.setMinWidth( 200 );
		buttonBack.setMaxWidth( 200 );
		buttonBack.setPrefWidth( 200 );
		buttonBack.setMinHeight( 25 );
		buttonBack.setMaxHeight( 25 );
		buttonBack.setPrefHeight( 25 );
		vboxButtons.getChildren().add( buttonBack );
		buttonBack.setText( "Back" );
		buttonBack.setOnAction( new EventHandler<ActionEvent>() {
			@Override public void handle( ActionEvent e ) {
				try {
					if( facetPane != null ) {
						cfFormManager.closeCurrentForm();
					}
				}
				catch( Throwable t ) {
					CFConsole.formException( S_FormName, ((CFButton)e.getSource()).getText(), t );
				}
			}
		});

		scrollButtons = new ScrollPane();
		scrollButtons.setMinWidth( 240 );
		scrollButtons.setMaxWidth( 240 );
		scrollButtons.setHbarPolicy( ScrollBarPolicy.NEVER );
		scrollButtons.setVbarPolicy( ScrollBarPolicy.AS_NEEDED );
		scrollButtons.setFitToWidth( true );
		scrollButtons.setContent( vboxButtons );

		setTop( labelTitle );
		setCenter( scrollButtons );
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
	}
}