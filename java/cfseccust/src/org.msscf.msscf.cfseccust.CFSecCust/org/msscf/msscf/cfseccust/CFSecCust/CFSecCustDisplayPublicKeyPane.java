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
import java.security.InvalidKeyException;
import java.security.KeyStore;
import java.security.NoSuchAlgorithmException;

import javax.crypto.IllegalBlockSizeException;
import javax.crypto.NoSuchPaddingException;

import javafx.application.*;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.HPos;
import javafx.geometry.Insets;
import javafx.geometry.Orientation;
import javafx.geometry.Pos;
import javafx.scene.*;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.PasswordField;
import javafx.scene.control.ScrollPane;
import javafx.scene.control.ScrollPane.ScrollBarPolicy;
import javafx.scene.input.MouseEvent;
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

public class CFSecCustDisplayPublicKeyPane
extends CFBorderPane
implements ICFForm
{
	protected final String S_FormName = "Public Key";
	protected ICFFormManager cfFormManager = null;
	protected ICFSecCustSchema custSchema = null;
	protected CFSecCustFacetPane facetPane = null;
	protected CFLabel labelTitle = null;
	protected CFGridPane fieldGridPane = null;
	protected CFLabel labelDeviceName = null;
	protected CFTextField textDeviceName = null;
	protected CFLabel labelDeviceKey = null;
	protected CFTextArea areaDeviceKey = null;
	protected CFHBox hboxButtons = null;
	protected CFButton buttonOk = null;

	public CFSecCustDisplayPublicKeyPane(
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
		labelTitle.setText( "Device Public Key Information" );
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

		labelDeviceName = new CFLabel();
		labelDeviceName.setVisible( true );
		fieldGridPane.setHalignment( labelDeviceName, HPos.LEFT );
		fieldGridPane.add( labelDeviceName,  0,  0 );
		labelDeviceName.setText( "Device Name" );

		textDeviceName = new CFTextField();
		textDeviceName.setVisible( true );
		fieldGridPane.setHalignment( textDeviceName, HPos.LEFT );
		fieldGridPane.add( textDeviceName,  1,  0 );
		textDeviceName.setEditable( false );

		labelDeviceKey = new CFLabel();
		labelDeviceKey.setVisible( true );
		fieldGridPane.setHalignment( labelDeviceKey, HPos.LEFT );
		fieldGridPane.add( labelDeviceKey,  0,  1 );
		labelDeviceKey.setText( "Public Key" );

		areaDeviceKey = new CFTextArea();
		areaDeviceKey.setVisible( true );
		areaDeviceKey.setMinHeight( 80 );
		areaDeviceKey.setPrefHeight( 80 );
		fieldGridPane.setHalignment( areaDeviceKey, HPos.LEFT );
		fieldGridPane.add( areaDeviceKey,  1,  1 );

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
					if( facetPane != null ) {
						facetPane.showLogin();
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
			String deviceName = configFile.getDeviceName();
			textDeviceName.setText( deviceName );
			CFTipClientHandler clientHandler = custSchema.getSchema().getBackingStore().getCFTipClientHandler();
			if( clientHandler != null ) {
				byte[] encodedPublicKey;
				try {
					if( null != clientHandler.getDevicePublicKey() ) {
						encodedPublicKey = clientHandler.getEncodedDevicePublicKey();
					}
					else {
						encodedPublicKey = new byte[0];
					}
				}
				catch ( InvalidKeyException
					| NoSuchAlgorithmException
					| NoSuchPaddingException
					| IllegalBlockSizeException e )
				{
					throw new CFLibRuntimeException( getClass(),
						S_ProcName,
						"Caught " + e.getClass().getName() + " -- " + e.getMessage(),
						e );
				}
				byte[] base64 = Base64.encodeBase64( encodedPublicKey );
				String base64Encoded = new String( base64 );
				areaDeviceKey.setText( base64Encoded );

			}
			else {
				areaDeviceKey.setText( "" );
			}
		}
	}
}
