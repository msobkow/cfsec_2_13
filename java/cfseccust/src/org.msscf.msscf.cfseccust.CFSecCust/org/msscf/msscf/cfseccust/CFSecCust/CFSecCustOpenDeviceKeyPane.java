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
import java.security.Key;
import java.security.KeyStore;
import java.security.KeyStoreException;
import java.security.NoSuchAlgorithmException;
import java.security.PrivateKey;
import java.security.PublicKey;
import java.security.UnrecoverableKeyException;
import java.security.cert.Certificate;

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
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import javafx.stage.*;

import org.apache.commons.codec.binary.Base64;

import org.msscf.msscf.cflib.CFLib.*;
import org.msscf.msscf.cflib.CFLib.JavaFX.*;
import org.msscf.msscf.cflib.CFLib.Tip.CFTipClientHandler;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfsec.CFSecJavaFX.*;
import org.msscf.msscf.cfsec.CFSecObj.*;

public class CFSecCustOpenDeviceKeyPane
extends CFBorderPane
implements ICFForm
{
	protected final String S_FormName = "Open Device Key";
	protected ICFFormManager cfFormManager = null;
	protected ICFSecCustSchema custSchema = null;
	protected CFSecCustFacetPane facetPane = null;
	protected CFLabel labelTitle = null;
	protected CFGridPane fieldGridPane = null;
	protected CFLabel labelKeyName = null;
	protected CFTextField textKeyName = null;
	protected CFLabel labelKeyPassword = null;
	protected CFPasswordField passwordKeyPassword = null;
	protected CFHBox hboxButtons = null;
	protected CFButton buttonOk = null;
	protected CFButton buttonCancel = null;

	public CFSecCustOpenDeviceKeyPane(
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
		labelTitle.setText( "Open Device Key" );
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

		labelKeyName = new CFLabel();
		labelKeyName.setVisible( true );
		fieldGridPane.setHalignment( labelKeyName, HPos.LEFT );
		fieldGridPane.add( labelKeyName,  0,  0 );
		labelKeyName.setText( "Key File" );

		textKeyName = new CFTextField();
		textKeyName.setVisible( true );
		fieldGridPane.setHalignment( textKeyName, HPos.LEFT );
		fieldGridPane.add( textKeyName,  1,  0 );
		textKeyName.setEditable( false );
		if( custSchema != null ) {
			CFSecClientConfigurationFile configFile = custSchema.getClientConfigurationFile();
			if( configFile != null ) {
				String keystoreFileName = configFile.getKeyStore();
				if( keystoreFileName != null ) {
					textKeyName.setText( keystoreFileName );
				}
			}
		}

		labelKeyPassword = new CFLabel();
		labelKeyPassword.setVisible( true );
		fieldGridPane.setHalignment( labelKeyPassword, HPos.LEFT );
		fieldGridPane.add( labelKeyPassword,  0,  1 );
		labelKeyPassword.setText( "Key Password" );

		passwordKeyPassword = new CFPasswordField();
		passwordKeyPassword.setVisible( true );
		passwordKeyPassword.setMinWidth( 200 );
		passwordKeyPassword.setMaxWidth( 200 );
		passwordKeyPassword.setPrefWidth( 200 );
		fieldGridPane.setHalignment( passwordKeyPassword, HPos.LEFT );
		fieldGridPane.add( passwordKeyPassword,  1,  1 );

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
				final String S_ProcName = "handle";
				try {
					String pw = passwordKeyPassword.getText();
					KeyStore keyStore = custSchema.getKeyStore();
					if( keyStore == null ) {
						throw new CFLibNullArgumentException( getClass(),
							S_ProcName,
							0,
							"custSchema.KeyStore" );
					}
					String deviceName = custSchema.getClientConfigurationFile().getDeviceName();
					Certificate publicKeyCertificate;
					PublicKey publicDeviceKey;
					try {
						publicKeyCertificate = keyStore.getCertificate( deviceName );
					}
					catch( KeyStoreException x ) {
						publicKeyCertificate = null;
					}
					if( publicKeyCertificate == null ) {
						ICFSecSchema bs = custSchema.getSchema().getBackingStore();
						CFTipClientHandler clientHandler = bs.getCFTipClientHandler();
						if( clientHandler != null ) {
							clientHandler.setDeviceName( null );
							clientHandler.setDevicePrivateKey( null );
							clientHandler.setDevicePublicKey( null );
						}
						CFSecClientConfigurationFile configFile = custSchema.getClientConfigurationFile();
						String keystoreFileName = configFile.getKeyStore();
						System.out.println(
							"You need to use the Java keytool to create an RSA 2048 bit key pair for the device \"" + deviceName + "\".\n"
								+ "For example, to create a self-signed certificate:\n\n"
								+ "    keytool -genkeypair -keystore " + keystoreFileName + " -storepass pw -keyalg RSA -keysize 2048 -alias " + deviceName + " -validity 2000 -storetype jceks\n\n"
								+ "The application will now exit." );
						custSchema.setKeyStore( null );
						facetPane.exitApplication();
					}
					else {
						publicDeviceKey = publicKeyCertificate.getPublicKey();
						PrivateKey privateDeviceKey;
						try {
							char[] capw = pw.toCharArray();
							Key key = keyStore.getKey( deviceName, capw );
							if( key instanceof PrivateKey ) {
								privateDeviceKey = (PrivateKey)key;
							}
							else {
								throw new CFLibUnsupportedClassException( getClass(),
									S_ProcName,
									"key",
									key,
									"PrivateKey" );
							}
						}
						catch( KeyStoreException x ) {
							privateDeviceKey = null;
							CFConsole.message( "Could not open private device key due to KeyStoreException -- " + x.getMessage() );
						}
						catch(UnrecoverableKeyException x ) {
							throw new CFLibRuntimeException( getClass(),
								S_ProcName,
								"Caught UnrecoverableKeyException -- " + x.getMessage(),
								x );
						}
						catch(NoSuchAlgorithmException x ) {
							throw new CFLibRuntimeException( getClass(),
								S_ProcName,
								"Caught NoSuchAlgorithmException -- " + x.getMessage(),
								x );
						}
						if( privateDeviceKey != null ) {
							ICFSecSchema bs = custSchema.getSchema().getBackingStore();
							CFTipClientHandler clientHandler = bs.getCFTipClientHandler();
							if( clientHandler != null ) {
								clientHandler.setDeviceName( deviceName );
								clientHandler.setDevicePrivateKey( privateDeviceKey );
								clientHandler.setDevicePublicKey( publicDeviceKey );
							}
							facetPane.showDisplayPublicKey();
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
	}
}
