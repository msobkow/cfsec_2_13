// Description: Java 11 JavaFX Attribute Pane implementation for ISOCcy.

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
 *	CFSecJavaFXISOCcyAttrPane JavaFX Attribute Pane implementation
 *	for ISOCcy.
 */
public class CFSecJavaFXISOCcyAttrPane
extends CFGridPane
implements ICFSecJavaFXISOCcyPaneCommon
{
	protected ICFFormManager cfFormManager = null;
	protected ICFSecJavaFXSchema javafxSchema = null;
	boolean javafxIsInitializing = true;

	protected class ISOCcyIdCFLabel
		extends CFLabel
	{
		public ISOCcyIdCFLabel() {
			super();
			setText( "ISOCcyId" );
		}
	}

	protected class ISOCcyIdEditor
		extends CFInt16Editor
	{
		public ISOCcyIdEditor() {
			super();
			setMinValue( CFSecISOCcyBuff.ISOCCYID_MIN_VALUE );
			setFieldName( "ISOCcyId" );
		}
	}

	protected class ISOCodeCFLabel
		extends CFLabel
	{
		public ISOCodeCFLabel() {
			super();
			setText( "ISOCode" );
		}
	}

	protected class ISOCodeEditor
		extends CFStringEditor
	{
		public ISOCodeEditor() {
			super();
			setMaxLen( 3 );
			setFieldName( "ISOCode" );
		}
	}

	protected class NameCFLabel
		extends CFLabel
	{
		public NameCFLabel() {
			super();
			setText( "Name" );
		}
	}

	protected class NameEditor
		extends CFStringEditor
	{
		public NameEditor() {
			super();
			setMaxLen( 64 );
			setFieldName( "Name" );
		}
	}

	protected class UnitSymbolCFLabel
		extends CFLabel
	{
		public UnitSymbolCFLabel() {
			super();
			setText( "UnitSymbol" );
		}
	}

	protected class UnitSymbolEditor
		extends CFStringEditor
	{
		public UnitSymbolEditor() {
			super();
			setMaxLen( 4 );
			setFieldName( "UnitSymbol" );
		}
	}

	protected class PrecisCFLabel
		extends CFLabel
	{
		public PrecisCFLabel() {
			super();
			setText( "Precis" );
		}
	}

	protected class PrecisEditor
		extends CFInt16Editor
	{
		public PrecisEditor() {
			super();
			setMinValue( CFSecISOCcyBuff.PRECIS_MIN_VALUE );
			setMaxValue( CFSecISOCcyBuff.PRECIS_MAX_VALUE );
			setFieldName( "Precis" );
		}
	}

	protected ISOCcyIdCFLabel javafxLabelISOCcyId = null;
	protected ISOCcyIdEditor javafxEditorISOCcyId = null;
	protected ISOCodeCFLabel javafxLabelISOCode = null;
	protected ISOCodeEditor javafxEditorISOCode = null;
	protected NameCFLabel javafxLabelName = null;
	protected NameEditor javafxEditorName = null;
	protected UnitSymbolCFLabel javafxLabelUnitSymbol = null;
	protected UnitSymbolEditor javafxEditorUnitSymbol = null;
	protected PrecisCFLabel javafxLabelPrecis = null;
	protected PrecisEditor javafxEditorPrecis = null;

	public CFSecJavaFXISOCcyAttrPane( ICFFormManager formManager, ICFSecJavaFXSchema argSchema, ICFSecISOCcyObj argFocus ) {
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
		setJavaFXFocusAsISOCcy( argFocus );
		setPadding( new Insets(5) );
		setHgap( 5 );
		setVgap( 5 );
		setAlignment( Pos.CENTER );
		ColumnConstraints column1 = new ColumnConstraints();
		column1.setPercentWidth( 100 );
		getColumnConstraints().addAll( column1 );
		int gridRow = 0;
		label = getJavaFXLabelISOCcyId();
		setHalignment( label, HPos.LEFT );
		setValignment( label, VPos.BOTTOM );
		add( label, 0, gridRow );
		gridRow ++;

		ctrl = getJavaFXEditorISOCcyId();
		setHalignment( ctrl, HPos.LEFT );
		add( ctrl, 0, gridRow );
		gridRow ++;

		label = getJavaFXLabelISOCode();
		setHalignment( label, HPos.LEFT );
		setValignment( label, VPos.BOTTOM );
		add( label, 0, gridRow );
		gridRow ++;

		ctrl = getJavaFXEditorISOCode();
		setHalignment( ctrl, HPos.LEFT );
		add( ctrl, 0, gridRow );
		gridRow ++;

		label = getJavaFXLabelName();
		setHalignment( label, HPos.LEFT );
		setValignment( label, VPos.BOTTOM );
		add( label, 0, gridRow );
		gridRow ++;

		ctrl = getJavaFXEditorName();
		setHalignment( ctrl, HPos.LEFT );
		add( ctrl, 0, gridRow );
		gridRow ++;

		label = getJavaFXLabelUnitSymbol();
		setHalignment( label, HPos.LEFT );
		setValignment( label, VPos.BOTTOM );
		add( label, 0, gridRow );
		gridRow ++;

		ctrl = getJavaFXEditorUnitSymbol();
		setHalignment( ctrl, HPos.LEFT );
		add( ctrl, 0, gridRow );
		gridRow ++;

		label = getJavaFXLabelPrecis();
		setHalignment( label, HPos.LEFT );
		setValignment( label, VPos.BOTTOM );
		add( label, 0, gridRow );
		gridRow ++;

		ctrl = getJavaFXEditorPrecis();
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
		populateFields();
		adjustComponentEnableStates();
	}

	public ICFSecISOCcyObj getJavaFXFocusAsISOCcy() {
		return( (ICFSecISOCcyObj)getJavaFXFocus() );
	}

	public void setJavaFXFocusAsISOCcy( ICFSecISOCcyObj value ) {
		setJavaFXFocus( value );
	}

	public ICFSecISOCcyObj getEffJavaFXFocus() {
		ICFSecISOCcyObj eff = (ICFSecISOCcyObj)getJavaFXFocus();
		if( eff != null ) {
			if( null != eff.getEdit() ) {
				eff = (ICFSecISOCcyObj)eff.getEdit();
			}
		}
		return( eff );
	}

	public ISOCcyIdCFLabel getJavaFXLabelISOCcyId() {
		if( javafxLabelISOCcyId == null ) {
			javafxLabelISOCcyId = new ISOCcyIdCFLabel();
		}
		return( javafxLabelISOCcyId );
	}

	public void setJavaFXLabelISOCcyId( ISOCcyIdCFLabel value ) {
		javafxLabelISOCcyId = value;
	}

	public ISOCcyIdEditor getJavaFXEditorISOCcyId() {
		if( javafxEditorISOCcyId == null ) {
			javafxEditorISOCcyId = new ISOCcyIdEditor();
		}
		return( javafxEditorISOCcyId );
	}

	public void setJavaFXEditorISOCcyId( ISOCcyIdEditor value ) {
		javafxEditorISOCcyId = value;
	}

	public ISOCodeCFLabel getJavaFXLabelISOCode() {
		if( javafxLabelISOCode == null ) {
			javafxLabelISOCode = new ISOCodeCFLabel();
		}
		return( javafxLabelISOCode );
	}

	public void setJavaFXLabelISOCode( ISOCodeCFLabel value ) {
		javafxLabelISOCode = value;
	}

	public ISOCodeEditor getJavaFXEditorISOCode() {
		if( javafxEditorISOCode == null ) {
			javafxEditorISOCode = new ISOCodeEditor();
		}
		return( javafxEditorISOCode );
	}

	public void setJavaFXEditorISOCode( ISOCodeEditor value ) {
		javafxEditorISOCode = value;
	}

	public NameCFLabel getJavaFXLabelName() {
		if( javafxLabelName == null ) {
			javafxLabelName = new NameCFLabel();
		}
		return( javafxLabelName );
	}

	public void setJavaFXLabelName( NameCFLabel value ) {
		javafxLabelName = value;
	}

	public NameEditor getJavaFXEditorName() {
		if( javafxEditorName == null ) {
			javafxEditorName = new NameEditor();
		}
		return( javafxEditorName );
	}

	public void setJavaFXEditorName( NameEditor value ) {
		javafxEditorName = value;
	}

	public UnitSymbolCFLabel getJavaFXLabelUnitSymbol() {
		if( javafxLabelUnitSymbol == null ) {
			javafxLabelUnitSymbol = new UnitSymbolCFLabel();
		}
		return( javafxLabelUnitSymbol );
	}

	public void setJavaFXLabelUnitSymbol( UnitSymbolCFLabel value ) {
		javafxLabelUnitSymbol = value;
	}

	public UnitSymbolEditor getJavaFXEditorUnitSymbol() {
		if( javafxEditorUnitSymbol == null ) {
			javafxEditorUnitSymbol = new UnitSymbolEditor();
		}
		return( javafxEditorUnitSymbol );
	}

	public void setJavaFXEditorUnitSymbol( UnitSymbolEditor value ) {
		javafxEditorUnitSymbol = value;
	}

	public PrecisCFLabel getJavaFXLabelPrecis() {
		if( javafxLabelPrecis == null ) {
			javafxLabelPrecis = new PrecisCFLabel();
		}
		return( javafxLabelPrecis );
	}

	public void setJavaFXLabelPrecis( PrecisCFLabel value ) {
		javafxLabelPrecis = value;
	}

	public PrecisEditor getJavaFXEditorPrecis() {
		if( javafxEditorPrecis == null ) {
			javafxEditorPrecis = new PrecisEditor();
		}
		return( javafxEditorPrecis );
	}

	public void setJavaFXEditorPrecis( PrecisEditor value ) {
		javafxEditorPrecis = value;
	}

	public void populateFields()
	{
		ICFSecISOCcyObj popObj = getEffJavaFXFocus();
		if( getPaneMode() == CFPane.PaneMode.Unknown ) {
			popObj = null;
		}
		if( popObj == null ) {
			getJavaFXEditorISOCcyId().setInt16Value( null );
		}
		else {
			getJavaFXEditorISOCcyId().setInt16Value( popObj.getRequiredISOCcyId() );
		}

		if( popObj == null ) {
			getJavaFXEditorISOCode().setStringValue( null );
		}
		else {
			getJavaFXEditorISOCode().setStringValue( popObj.getRequiredISOCode() );
		}

		if( popObj == null ) {
			getJavaFXEditorName().setStringValue( null );
		}
		else {
			getJavaFXEditorName().setStringValue( popObj.getRequiredName() );
		}

		if( popObj == null ) {
			getJavaFXEditorUnitSymbol().setStringValue( null );
		}
		else {
			getJavaFXEditorUnitSymbol().setStringValue( popObj.getOptionalUnitSymbol() );
		}

		if( popObj == null ) {
			getJavaFXEditorPrecis().setInt16Value( null );
		}
		else {
			getJavaFXEditorPrecis().setInt16Value( popObj.getRequiredPrecis() );
		}
	}

	public void postFields()
	{
		final String S_ProcName = "postFields";
		ICFSecISOCcyObj focus = getJavaFXFocusAsISOCcy();
		ICFSecISOCcyEditObj editObj;
		if( focus != null ) {
			editObj = (ICFSecISOCcyEditObj)(focus.getEdit());
		}
		else {
			editObj = null;
		}
		if( editObj == null ) {
			throw new CFLibUsageException( getClass(),
				S_ProcName,
				"Pane is unfocused or is not editing the focus object" );
		}

		if( getJavaFXEditorISOCode().getStringValue() == null ) {
			editObj.setRequiredISOCode( "" );
		}
		else {
			editObj.setRequiredISOCode( getJavaFXEditorISOCode().getStringValue() );
		}

		if( getJavaFXEditorName().getStringValue() == null ) {
			editObj.setRequiredName( "" );
		}
		else {
			editObj.setRequiredName( getJavaFXEditorName().getStringValue() );
		}

		if( ( getJavaFXEditorUnitSymbol().getStringValue() != null ) && ( getJavaFXEditorUnitSymbol().getStringValue().length() <= 0 ) ) {
			editObj.setOptionalUnitSymbol( null );
		}
		else {
			editObj.setOptionalUnitSymbol( getJavaFXEditorUnitSymbol().getStringValue() );
		}

		editObj.setRequiredPrecis( getJavaFXEditorPrecis().getInt16Value() );
	}

	public void setPaneMode( CFPane.PaneMode value ) {
		final String S_ProcName = "setPaneMode";
		CFPane.PaneMode oldValue = getPaneMode();
		if( oldValue == value ) {
			return;
		}
		ICFSecISOCcyObj focus = getJavaFXFocusAsISOCcy();
		if( ( value != CFPane.PaneMode.Unknown ) && ( value != CFPane.PaneMode.View ) ) {
			if( focus == null ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"javaFXFocus" );
			}
		}
		ICFSecISOCcyEditObj editObj;
		if( focus != null ) {
			editObj  = (ICFSecISOCcyEditObj)focus.getEdit();
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
								editObj = (ICFSecISOCcyEditObj)focus.beginEdit();
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
							editObj = (ICFSecISOCcyEditObj)focus.beginEdit();
							if( editObj == null ) {
								throw new CFLibUsageException( getClass(),
									S_ProcName,
									"Expected beginEdit() to return a new edition of the focus object" );
							}
						}
						break;
					case View:
						if( editObj == null ) {
							editObj = (ICFSecISOCcyEditObj)focus.beginEdit();
							if( editObj == null ) {
								throw new CFLibUsageException( getClass(),
									S_ProcName,
									"Expected beginEdit() to return a new edition of the focus object" );
							}
						}
						break;
					case Edit:
						if( editObj == null ) {
							editObj = (ICFSecISOCcyEditObj)focus.beginEdit();
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
						focus = (ICFSecISOCcyObj)editObj.create();
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
								editObj = (ICFSecISOCcyEditObj)focus.beginEdit();
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
								editObj = (ICFSecISOCcyEditObj)focus.beginEdit();
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
							editObj = (ICFSecISOCcyEditObj)focus.beginEdit();
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
			ICFSecISOCcyObj focus = getJavaFXFocusAsISOCcy();
			if( focus == null ) {
				isEditing = false;
			}
			else if( null == focus.getEdit() ) {
				isEditing = false;
			}
		}
		if( javafxEditorISOCcyId != null ) {
			javafxEditorISOCcyId.setDisable( true );
		}
		if( javafxEditorISOCode != null ) {
			javafxEditorISOCode.setDisable( ! isEditing );
		}
		if( javafxEditorName != null ) {
			javafxEditorName.setDisable( ! isEditing );
		}
		if( javafxEditorUnitSymbol != null ) {
			javafxEditorUnitSymbol.setDisable( ! isEditing );
		}
		if( javafxEditorPrecis != null ) {
			javafxEditorPrecis.setDisable( ! isEditing );
		}
	}
}
