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

import java.awt.Dimension;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import java.security.KeyStore;
import java.security.KeyStoreException;
import java.security.NoSuchAlgorithmException;
import java.security.cert.CertificateException;

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
import javafx.scene.control.ChoiceDialog;
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
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.ColumnConstraints;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.Pane;
import javafx.scene.layout.Priority;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import javafx.stage.*;

import org.apache.commons.codec.binary.Base64;

import org.msscf.msscf.cflib.CFLib.*;
import org.msscf.msscf.cflib.CFLib.JavaFX.*;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfsec.CFSecJavaFX.*;
import org.msscf.msscf.cfsec.CFSecObj.*;

public class CFSecCustOpenKeystorePane
extends CFBorderPane
implements ICFForm
{
	protected final String S_FormName = "Open Keystore";
	protected ICFFormManager cfFormManager = null;
	protected ICFSecCustSchema custSchema = null;
	protected CFSecCustFacetPane facetPane = null;
	protected CFLabel labelTitle = null;
	protected CFGridPane fieldGridPane = null;
	protected CFLabel labelKeystoreName = null;
	protected CFTextField textKeystoreName = null;
	protected CFLabel labelKeystorePassword = null;
	protected CFPasswordField passwordKeystorePassword = null;
	protected CFHBox hboxButtons = null;
	protected CFButton buttonOk = null;
	protected CFButton buttonCancel = null;

	public CFSecCustOpenKeystorePane(
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
		labelTitle.setText( "Open Keystore" );
		Font f = labelTitle.getFont();
		Font largeBold = Font.font( f.getFamily(), FontWeight.BOLD, 20 );
		labelTitle.setFont( largeBold );
		labelTitle.setMinHeight( 35 );
		labelTitle.setMaxHeight( 35 );
		labelTitle.setMinWidth( 200 );
		labelTitle.setAlignment( Pos.CENTER );

		fieldGridPane = new CFGridPane();
		fieldGridPane.setPadding( new Insets(5) );
		fieldGridPane.setHgap( 5 );
		fieldGridPane.setVgap( 5 );
		fieldGridPane.setAlignment( Pos.CENTER );
		ColumnConstraints column1 = new ColumnConstraints( 125 );
		ColumnConstraints column2 = new ColumnConstraints( 125, 300, 500 );
		column2.setHgrow( Priority.ALWAYS );
		fieldGridPane.getColumnConstraints().addAll( column1, column2 );

		labelKeystoreName = new CFLabel();
		labelKeystoreName.setVisible( true );
		fieldGridPane.setHalignment( labelKeystoreName, HPos.LEFT );
		fieldGridPane.add( labelKeystoreName,  0,  0 );
		labelKeystoreName.setText( "Keystore File" );

		textKeystoreName = new CFTextField();
		textKeystoreName.setVisible( true );
		fieldGridPane.setHalignment( textKeystoreName, HPos.LEFT );
		fieldGridPane.add( textKeystoreName,  1,  0 );
		textKeystoreName.setEditable( false );
		if( custSchema != null ) {
			CFSecClientConfigurationFile configFile = custSchema.getClientConfigurationFile();
			if( configFile != null ) {
				String keystoreFileName = configFile.getKeyStore();
				if( keystoreFileName != null ) {
					textKeystoreName.setText( keystoreFileName );
				}
			}
		}

		labelKeystorePassword = new CFLabel();
		labelKeystorePassword.setVisible( true );
		fieldGridPane.setHalignment( labelKeystorePassword, HPos.LEFT );
		fieldGridPane.add( labelKeystorePassword,  0,  1 );
		labelKeystorePassword.setText( "Keystore Password" );

		passwordKeystorePassword = new CFPasswordField();
		passwordKeystorePassword.setVisible( true );
		passwordKeystorePassword.setMinWidth( 200 );
		passwordKeystorePassword.setMaxWidth( 200 );
		passwordKeystorePassword.setPrefWidth( 200 );
		fieldGridPane.setHalignment( passwordKeystorePassword, HPos.LEFT );
		fieldGridPane.add( passwordKeystorePassword,  1,  1 );

		hboxButtons = new CFHBox( 10 );
		hboxButtons.setMinHeight( 35 );
		hboxButtons.setMaxHeight( 35 );
		hboxButtons.setPrefHeight( 35 );
		hboxButtons.setAlignment( Pos.CENTER );

		buttonOk = new CFButton();
		buttonOk.setVisible( true );
		buttonOk.setMinWidth( 200 );
		buttonOk.setMaxWidth( 200 );
		buttonOk.setPrefWidth( 200 );
		buttonOk.setMinHeight( 25 );
		buttonOk.setMaxHeight( 25 );
		buttonOk.setPrefHeight( 25 );
		buttonOk.setDefaultButton( true );
		hboxButtons.getChildren().add( buttonOk );
		buttonOk.setText( "Ok" );
		buttonOk.setOnAction( new EventHandler<ActionEvent>() {
			@Override public void handle( ActionEvent e ) {
				try {
					String keystorePassword = passwordKeystorePassword.getText();
					if( keystorePassword != null ) {
						boolean exitApp = false;
						boolean creatingKeystore = false;
						boolean exitForm = false;
						if( custSchema != null ) {
							CFSecClientConfigurationFile conf = custSchema.getClientConfigurationFile();
							if( conf != null ) {
								String keystoreFileName = conf.getKeyStore();

								KeyStore keyStore = null;
								File keystoreFile = new File( keystoreFileName );
								if( ! keystoreFile.exists() ) {
									ArrayList<String> choices = new ArrayList<String>();
									choices.add( "Yes" );
									choices.add( "No" );
									ChoiceDialog<String> choiceDialog = new ChoiceDialog<String>( "Yes", choices );
									choiceDialog.setTitle(
										"Would you like to create the keystore \"" + keystoreFileName + "\"?" );
									Optional<String> result = choiceDialog.showAndWait();
									if( ( result.isPresent() && result.get().equals( "Yes" ) ) ) {
										facetPane.showCreateKeystore();
										creatingKeystore = true;
									}
									else {
										exitApp = true;
									}
								}
								else if( ! keystoreFile.isFile() ) {
									CFConsole.message( "The referenced JCEKS keystore \"" + keystoreFileName + "\" is not a file." );
									exitApp = true;
								}
								else if( ! keystoreFile.canRead() ) {
									CFConsole.message( "Permission denied attempting to access JCEKS keystore \"" + keystoreFileName + "\"." );
									exitApp = true;
								}
								if( ( ! exitApp ) && ( ! creatingKeystore ) ) {
									try {
										keyStore = KeyStore.getInstance( "jceks" );
										char[] caPassword = keystorePassword.toCharArray();
										FileInputStream input = new FileInputStream( keystoreFileName );
										keyStore.load( input, caPassword );
										input.close();
										custSchema.setKeyStore( keyStore );
										exitForm = true;
									}
									catch( CertificateException x ) {
										keyStore = null;
										CFConsole.message( "Could not open keystore due to CertificateException -- " + x.getMessage() );
										exitApp = true;
									}
									catch( IOException x ) {
										keyStore = null;
										CFConsole.message( "Could not open keystore due to IOException -- " + x.getMessage() );
										exitApp = true;
									}
									catch( KeyStoreException x ) {
										keyStore = null;
										CFConsole.message( "Could not open keystore due to KeyStoreException -- " + x.getMessage() );
										exitApp = true;
									}
									catch( NoSuchAlgorithmException x ) {
										keyStore = null;
										CFConsole.message( "Could not open keystore due to NoSuchAlgorithmException -- " + x.getMessage() );
										exitApp = true;
									}
								}
								if( exitApp ) {
									custSchema.setKeyStore( null );
									facetPane.exitApplication();
								}
								else if( exitForm ) {
									facetPane.showOpenDeviceKey();
								}
							}
						}
					}
				}
				catch( Throwable t ) {
					CFConsole.formException( S_FormName, ((CFButton)e.getSource()).getText(), t );
				}
			}
		});

		buttonCancel = new CFButton();
		buttonCancel.setVisible( true );
		buttonCancel.setMinWidth( 200 );
		buttonCancel.setMaxWidth( 200 );
		buttonCancel.setPrefWidth( 200 );
		buttonCancel.setMinHeight( 25 );
		buttonCancel.setMaxHeight( 25 );
		buttonCancel.setPrefHeight( 25 );
		hboxButtons.getChildren().add( buttonCancel );
		buttonCancel.setText( "Cancel" );
		buttonCancel.setOnAction( new EventHandler<ActionEvent>() {
			@Override public void handle( ActionEvent e ) {
				try {
					if( facetPane != null ) {
						facetPane.showConfirmExitApp();
					}
				}
				catch( Throwable t ) {
					CFConsole.formException( S_FormName, ((CFButton)e.getSource()).getText(), t );
				}
			}
		});

		this.setOnMouseMoved( new EventHandler<MouseEvent>() {
			@Override public void handle( MouseEvent event ) {
				if( custSchema != null ) {
					ICFSecSchemaObj schemaObj = custSchema.getSchema();
					if( schemaObj != null ) {
						if( schemaObj.isConnected() ) {
							facetPane.getAuthorizationCallbacks().loggedIn();
							facetPane.showSession();
						}
					}
				}
			}
		} );

		setTop( labelTitle );
		setCenter( fieldGridPane );
		setBottom( hboxButtons );
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
		CFSecClientConfigurationFile configFile = custSchema.getClientConfigurationFile();
		if( configFile != null ) {
			String keystoreFileName = configFile.getKeyStore();
			if( keystoreFileName != null ) {
				textKeystoreName.setText( keystoreFileName );
			}
		}
	}
}
