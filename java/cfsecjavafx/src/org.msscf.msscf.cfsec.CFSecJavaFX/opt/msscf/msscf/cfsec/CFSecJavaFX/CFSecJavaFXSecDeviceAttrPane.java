// Description: Java 11 JavaFX Attribute Pane implementation for SecDevice.

/*
 *	com.github.msobkow.CFSec
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

package com.github.msobkow.cfsec.CFSecJavaFX;

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.geometry.HPos;
import javafx.geometry.VPos;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Node;
import javafx.scene.control.ButtonType;
import javafx.scene.control.ComboBox;
import javafx.scene.control.Control;
import javafx.scene.layout.ColumnConstraints;
import javafx.scene.layout.Priority;
import com.github.msobkow.cflib.CFLib.*;
import com.github.msobkow.cflib.CFLib.JavaFX.*;
import com.github.msobkow.cflib.CFLib.JavaFX.CFReferenceEditor.ICFReferenceCallback;
import org.apache.commons.codec.binary.Base64;
import com.github.msobkow.cfsec.CFSec.*;
import com.github.msobkow.cfsec.CFSecObj.*;

/**
 *	CFSecJavaFXSecDeviceAttrPane JavaFX Attribute Pane implementation
 *	for SecDevice.
 */
public class CFSecJavaFXSecDeviceAttrPane
extends CFGridPane
implements ICFSecJavaFXSecDevicePaneCommon
{
	protected ICFFormManager cfFormManager = null;
	protected ICFSecJavaFXSchema javafxSchema = null;
	boolean javafxIsInitializing = true;

	protected class DevNameCFLabel
		extends CFLabel
	{
		public DevNameCFLabel() {
			super();
			setText( "Device Name" );
		}
	}

	protected class DevNameEditor
		extends CFStringEditor
	{
		public DevNameEditor() {
			super();
			setMaxLen( 127 );
			setFieldName( "Device Name" );
		}
	}

	protected class PubKeyCFLabel
		extends CFLabel
	{
		public PubKeyCFLabel() {
			super();
			setText( "Device Public Key" );
		}
	}

	protected class PubKeyEditor
		extends CFTextEditor
	{
		public PubKeyEditor() {
			super();
			setMaxLen( 10000 );
			setFieldName( "Device Public Key" );
			setPrefHeight( 10 * 20 );
			setMinHeight( 10 * 20 );
		}
	}

	protected DevNameCFLabel javafxLabelDevName = null;
	protected DevNameEditor javafxEditorDevName = null;
	protected PubKeyCFLabel javafxLabelPubKey = null;
	protected PubKeyEditor javafxEditorPubKey = null;

	public CFSecJavaFXSecDeviceAttrPane( ICFFormManager formManager, ICFSecJavaFXSchema argSchema, ICFSecSecDeviceObj argFocus ) {
		super();
		Control ctrl;
		CFLabel label;
		CFReferenceEditor reference;
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
		setJavaFXFocusAsSecDevice( argFocus );
		setPadding( new Insets(5) );
		setHgap( 5 );
		setVgap( 5 );
		setAlignment( Pos.CENTER );
		ColumnConstraints column1 = new ColumnConstraints();
		column1.setPercentWidth( 100 );
		getColumnConstraints().addAll( column1 );
		int gridRow = 0;
		label = getJavaFXLabelDevName();
		setHalignment( label, HPos.LEFT );
		setValignment( label, VPos.BOTTOM );
		add( label, 0, gridRow );
		gridRow ++;

		ctrl = getJavaFXEditorDevName();
		setHalignment( ctrl, HPos.LEFT );
		add( ctrl, 0, gridRow );
		gridRow ++;

		label = getJavaFXLabelPubKey();
		setHalignment( label, HPos.LEFT );
		setValignment( label, VPos.BOTTOM );
		add( label, 0, gridRow );
		gridRow ++;

		ctrl = getJavaFXEditorPubKey();
		setHalignment( ctrl, HPos.LEFT );
		add( ctrl, 0, gridRow );
		gridRow ++;

		populateFields();
		adjustComponentEnableStates();
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
		if( ( value == null ) || ( value instanceof ICFSecSecDeviceObj ) ) {
			super.setJavaFXFocus( value );
		}
		else {
			throw new CFLibUnsupportedClassException( getClass(),
				S_ProcName,
				"value",
				value,
				"ICFSecSecDeviceObj" );
		}
		populateFields();
		adjustComponentEnableStates();
	}

	public ICFSecSecDeviceObj getJavaFXFocusAsSecDevice() {
		return( (ICFSecSecDeviceObj)getJavaFXFocus() );
	}

	public void setJavaFXFocusAsSecDevice( ICFSecSecDeviceObj value ) {
		setJavaFXFocus( value );
	}

	public ICFSecSecDeviceObj getEffJavaFXFocus() {
		ICFSecSecDeviceObj eff = (ICFSecSecDeviceObj)getJavaFXFocus();
		if( eff != null ) {
			if( null != eff.getEdit() ) {
				eff = (ICFSecSecDeviceObj)eff.getEdit();
			}
		}
		return( eff );
	}

	public DevNameCFLabel getJavaFXLabelDevName() {
		if( javafxLabelDevName == null ) {
			javafxLabelDevName = new DevNameCFLabel();
		}
		return( javafxLabelDevName );
	}

	public void setJavaFXLabelDevName( DevNameCFLabel value ) {
		javafxLabelDevName = value;
	}

	public DevNameEditor getJavaFXEditorDevName() {
		if( javafxEditorDevName == null ) {
			javafxEditorDevName = new DevNameEditor();
		}
		return( javafxEditorDevName );
	}

	public void setJavaFXEditorDevName( DevNameEditor value ) {
		javafxEditorDevName = value;
	}

	public PubKeyCFLabel getJavaFXLabelPubKey() {
		if( javafxLabelPubKey == null ) {
			javafxLabelPubKey = new PubKeyCFLabel();
		}
		return( javafxLabelPubKey );
	}

	public void setJavaFXLabelPubKey( PubKeyCFLabel value ) {
		javafxLabelPubKey = value;
	}

	public PubKeyEditor getJavaFXEditorPubKey() {
		if( javafxEditorPubKey == null ) {
			javafxEditorPubKey = new PubKeyEditor();
		}
		return( javafxEditorPubKey );
	}

	public void setJavaFXEditorPubKey( PubKeyEditor value ) {
		javafxEditorPubKey = value;
	}

	public void populateFields()
	{
		ICFSecSecDeviceObj popObj = getEffJavaFXFocus();
		if( getPaneMode() == CFPane.PaneMode.Unknown ) {
			popObj = null;
		}
		if( popObj == null ) {
			getJavaFXEditorDevName().setStringValue( null );
		}
		else {
			getJavaFXEditorDevName().setStringValue( popObj.getRequiredDevName() );
		}

		if( popObj == null ) {
			getJavaFXEditorPubKey().setTextValue( null );
		}
		else {
			getJavaFXEditorPubKey().setTextValue( popObj.getOptionalPubKey() );
		}
	}

	public void postFields()
	{
		final String S_ProcName = "postFields";
		ICFSecSecDeviceObj focus = getJavaFXFocusAsSecDevice();
		ICFSecSecDeviceEditObj editObj;
		if( focus != null ) {
			editObj = (ICFSecSecDeviceEditObj)(focus.getEdit());
		}
		else {
			editObj = null;
		}
		if( editObj == null ) {
			throw new CFLibUsageException( getClass(),
				S_ProcName,
				"Pane is unfocused or is not editing the focus object" );
		}

		if( ( getJavaFXEditorPubKey().getTextValue() != null ) && ( getJavaFXEditorPubKey().getTextValue().length() <= 0 ) ) {
			editObj.setOptionalPubKey( null );
		}
		else {
			editObj.setOptionalPubKey( getJavaFXEditorPubKey().getTextValue() );
		}
	}

	public void setPaneMode( CFPane.PaneMode value ) {
		final String S_ProcName = "setPaneMode";
		CFPane.PaneMode oldValue = getPaneMode();
		if( oldValue == value ) {
			return;
		}
		ICFSecSecDeviceObj focus = getJavaFXFocusAsSecDevice();
		if( ( value != CFPane.PaneMode.Unknown ) && ( value != CFPane.PaneMode.View ) ) {
			if( focus == null ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"javaFXFocus" );
			}
		}
		ICFSecSecDeviceEditObj editObj;
		if( focus != null ) {
			editObj  = (ICFSecSecDeviceEditObj)focus.getEdit();
		}
		else {
			editObj = null;
		}
		switch( value ) {
			case Unknown:
				switch( oldValue ) {
					case Unknown:
						break;
					default:
						if( editObj != null ) {
							editObj.endEdit();
							editObj = null;
						}
						break;
				}
				break;
			case Add:
				switch( oldValue ) {
					case Unknown:
					case Add:
					case View:
						if( editObj == null ) {
							if( focus != null ) {
								if( ! focus.getIsNew() ) {
									throw new CFLibUsageException( getClass(),
										S_ProcName,
										"Transitioning to PaneMode Add requires Focus.getIsNew() to be true" );
								}
								editObj = (ICFSecSecDeviceEditObj)focus.beginEdit();
								if( editObj == null ) {
									throw new CFLibUsageException( getClass(),
										S_ProcName,
										"Expected beginEdit() to return a new edition of the focus object" );
								}
							}
							else {
								throw new CFLibNullArgumentException( getClass(),
									S_ProcName,
									0,
									"focus" );
							}
						}
						break;
					case Edit:
						throw new CFLibUsageException( getClass(),
							S_ProcName,
							"Cannot transition PaneMode Edit to Add" );
					case Update:
						if( ( editObj == null ) || ( ! editObj.getIsNew() ) ) {
							throw new CFLibUsageException( getClass(),
								S_ProcName,
								"Cannot transition PaneMode Update to Add" );
						}
						break;
					case Delete:
						throw new CFLibUsageException( getClass(),
							S_ProcName,
							"Cannot transition PaneMode Delete to Add" );
					default:
						throw new CFLibUsageException( getClass(),
							S_ProcName,
							"Cannot transition PaneMode default to Add" );
				}
				break;
			case View:
				switch( oldValue ) {
					case Unknown:
						break;
					case View:
						break;
					case Edit:
						break;
					case Update:
						break;
					case Delete:
						break;
					default:
						throw new CFLibUsageException( getClass(),
							S_ProcName,
							"Cannot transition PaneMode " + oldValue + " to View" );
				}
				if( editObj != null ) {
					editObj.endEdit();
					editObj = null;
				}
				break;
			case Edit:
				switch( oldValue ) {
					case Unknown:
						if( editObj == null ) {
							editObj = (ICFSecSecDeviceEditObj)focus.beginEdit();
							if( editObj == null ) {
								throw new CFLibUsageException( getClass(),
									S_ProcName,
									"Expected beginEdit() to return a new edition of the focus object" );
							}
						}
						break;
					case View:
						if( editObj == null ) {
							editObj = (ICFSecSecDeviceEditObj)focus.beginEdit();
							if( editObj == null ) {
								throw new CFLibUsageException( getClass(),
									S_ProcName,
									"Expected beginEdit() to return a new edition of the focus object" );
							}
						}
						break;
					case Edit:
						if( editObj == null ) {
							editObj = (ICFSecSecDeviceEditObj)focus.beginEdit();
							if( editObj == null ) {
								throw new CFLibUsageException( getClass(),
									S_ProcName,
									"Expected beginEdit() to return a new edition of the focus object" );
							}
						}
						break;
					case Update:
						if( editObj == null ) {
							throw new CFLibUsageException( getClass(),
								S_ProcName,
								"Cannot transition PaneMode " + oldValue + " to Edit" ); 
						}
						break;
					default:
						throw new CFLibUsageException( getClass(),
							S_ProcName,
							"Cannot transition PaneMode " + oldValue + " to Edit" ); 
				}
				break;
			case Update:
				if( ( oldValue != CFPane.PaneMode.Edit ) && ( oldValue != CFPane.PaneMode.Add ) ) {
					throw new CFLibUsageException( getClass(),
						S_ProcName,
						"Cannot transition from mode " + oldValue + " to Update" );
				}
				super.setPaneMode( value );
				if( editObj != null ) {
					postFields();
					if( editObj.getIsNew() ) {
						focus = (ICFSecSecDeviceObj)editObj.create();
						setJavaFXFocus( focus );
					}
					else {
						editObj.update();
					}
					editObj = null;
				}
				setPaneMode( CFPane.PaneMode.View );
				break;
			case Delete:
				switch( oldValue ) {
					case View:
						if( focus != null ) {
							if( editObj == null ) {
								editObj = (ICFSecSecDeviceEditObj)focus.beginEdit();
								if( editObj == null ) {
									throw new CFLibUsageException( getClass(),
										S_ProcName,
										"Expected beginEdit() to return a new edition of the focus object" );
								}
							}
						}
						break;
					case Edit:
						if( focus != null ) {
							if( editObj == null ) {
								editObj = (ICFSecSecDeviceEditObj)focus.beginEdit();
								if( editObj == null ) {
									throw new CFLibUsageException( getClass(),
										S_ProcName,
										"Expected beginEdit() to return a new edition of the focus object" );
								}
							}
						}
						break;
					case Update:
						throw new CFLibUsageException( getClass(),
							S_ProcName,
							"Cannot transition PaneMode Update to Delete" ); 
					case Delete:
						if( editObj == null ) {
							editObj = (ICFSecSecDeviceEditObj)focus.beginEdit();
							if( editObj == null ) {
								throw new CFLibUsageException( getClass(),
									S_ProcName,
									"Expected beginEdit() to return a new edition of the focus object" );
							}
						}
						break;
					default:
						throw new CFLibUsageException( getClass(),
							S_ProcName,
							"Cannot transition PaneMode " + oldValue + " to Delete" ); 
				}
				editObj.deleteInstance();
				editObj = null;
				setJavaFXFocus( null );
				setPaneMode( CFPane.PaneMode.Unknown );
				break;
			default:
				switch( oldValue ) {
					case Unknown:
						break;
					default:
						if( editObj != null ) {
							editObj.endEdit();
							editObj = null;
						}
						break;
				}
				break;
		}
		super.setPaneMode( value );
		populateFields();
		adjustComponentEnableStates();
	}

	public void adjustComponentEnableStates() {
		CFPane.PaneMode mode = getPaneMode();
		boolean isEditing;
		switch( mode ) {
			case Unknown:
			case View:
			case Delete:
				isEditing = false;
				break;
			case Add:
			case Edit:
			case Update:
				isEditing = true;
				break;
			default:
				isEditing = false;
				break;
		}
		if( isEditing ) {
			ICFSecSecDeviceObj focus = getJavaFXFocusAsSecDevice();
			if( focus == null ) {
				isEditing = false;
			}
			else if( null == focus.getEdit() ) {
				isEditing = false;
			}
		}
		if( javafxEditorDevName != null ) {
			javafxEditorDevName.setDisable( true );
		}
		if( javafxEditorPubKey != null ) {
			javafxEditorPubKey.setDisable( ! isEditing );
		}
	}
}
