// Description: Java 11 JavaFX Attribute Pane implementation for ISOTZone.

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
import org.msscf.msscf.v2_13.cflib.CFLib.*;
import org.msscf.msscf.v2_13.cflib.CFLib.JavaFX.*;
import org.msscf.msscf.v2_13.cflib.CFLib.JavaFX.CFReferenceEditor.ICFReferenceCallback;
import org.apache.commons.codec.binary.Base64;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfsec.CFSecObj.*;

/**
 *	CFSecJavaFXISOTZoneAttrPane JavaFX Attribute Pane implementation
 *	for ISOTZone.
 */
public class CFSecJavaFXISOTZoneAttrPane
extends CFGridPane
implements ICFSecJavaFXISOTZonePaneCommon
{
	protected ICFFormManager cfFormManager = null;
	protected ICFSecJavaFXSchema javafxSchema = null;
	boolean javafxIsInitializing = true;

	protected class ISOTZoneIdCFLabel
		extends CFLabel
	{
		public ISOTZoneIdCFLabel() {
			super();
			setText( "ISO Timezone Id" );
		}
	}

	protected class ISOTZoneIdEditor
		extends CFInt16Editor
	{
		public ISOTZoneIdEditor() {
			super();
			setMinValue( CFSecISOTZoneBuff.ISOTZONEID_MIN_VALUE );
			setFieldName( "ISO Timezone Id" );
		}
	}

	protected class Iso8601CFLabel
		extends CFLabel
	{
		public Iso8601CFLabel() {
			super();
			setText( "ISO8601" );
		}
	}

	protected class Iso8601Editor
		extends CFStringEditor
	{
		public Iso8601Editor() {
			super();
			setMaxLen( 6 );
			setFieldName( "ISO8601" );
		}
	}

	protected class TZNameCFLabel
		extends CFLabel
	{
		public TZNameCFLabel() {
			super();
			setText( "Timezone Name" );
		}
	}

	protected class TZNameEditor
		extends CFStringEditor
	{
		public TZNameEditor() {
			super();
			setMaxLen( 64 );
			setFieldName( "Timezone Name" );
		}
	}

	protected class TZHourOffsetCFLabel
		extends CFLabel
	{
		public TZHourOffsetCFLabel() {
			super();
			setText( "Timezone Hour Offset" );
		}
	}

	protected class TZHourOffsetEditor
		extends CFInt16Editor
	{
		public TZHourOffsetEditor() {
			super();
			setMinValue( CFSecISOTZoneBuff.TZHOUROFFSET_MIN_VALUE );
			setMaxValue( CFSecISOTZoneBuff.TZHOUROFFSET_MAX_VALUE );
			setFieldName( "Timezone Hour Offset" );
		}
	}

	protected class TZMinOffsetCFLabel
		extends CFLabel
	{
		public TZMinOffsetCFLabel() {
			super();
			setText( "Timezone Minute Offset" );
		}
	}

	protected class TZMinOffsetEditor
		extends CFInt16Editor
	{
		public TZMinOffsetEditor() {
			super();
			setMinValue( CFSecISOTZoneBuff.TZMINOFFSET_MIN_VALUE );
			setMaxValue( CFSecISOTZoneBuff.TZMINOFFSET_MAX_VALUE );
			setFieldName( "Timezone Minute Offset" );
		}
	}

	protected class DescriptionCFLabel
		extends CFLabel
	{
		public DescriptionCFLabel() {
			super();
			setText( "Description" );
		}
	}

	protected class DescriptionEditor
		extends CFStringEditor
	{
		public DescriptionEditor() {
			super();
			setMaxLen( 128 );
			setFieldName( "Description" );
		}
	}

	protected class VisibleCFLabel
		extends CFLabel
	{
		public VisibleCFLabel() {
			super();
			setText( "Visible" );
		}
	}

	protected class VisibleEditor
		extends CFBoolEditor
	{
		public VisibleEditor() {
			super();
			setIsNullable( false );
			setFieldName( "Visible" );
		}
	}

	protected ISOTZoneIdCFLabel javafxLabelISOTZoneId = null;
	protected ISOTZoneIdEditor javafxEditorISOTZoneId = null;
	protected Iso8601CFLabel javafxLabelIso8601 = null;
	protected Iso8601Editor javafxEditorIso8601 = null;
	protected TZNameCFLabel javafxLabelTZName = null;
	protected TZNameEditor javafxEditorTZName = null;
	protected TZHourOffsetCFLabel javafxLabelTZHourOffset = null;
	protected TZHourOffsetEditor javafxEditorTZHourOffset = null;
	protected TZMinOffsetCFLabel javafxLabelTZMinOffset = null;
	protected TZMinOffsetEditor javafxEditorTZMinOffset = null;
	protected DescriptionCFLabel javafxLabelDescription = null;
	protected DescriptionEditor javafxEditorDescription = null;
	protected VisibleCFLabel javafxLabelVisible = null;
	protected VisibleEditor javafxEditorVisible = null;

	public CFSecJavaFXISOTZoneAttrPane( ICFFormManager formManager, ICFSecJavaFXSchema argSchema, ICFSecISOTZoneObj argFocus ) {
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
		setJavaFXFocusAsISOTZone( argFocus );
		setPadding( new Insets(5) );
		setHgap( 5 );
		setVgap( 5 );
		setAlignment( Pos.CENTER );
		ColumnConstraints column1 = new ColumnConstraints();
		column1.setPercentWidth( 100 );
		getColumnConstraints().addAll( column1 );
		int gridRow = 0;
		label = getJavaFXLabelISOTZoneId();
		setHalignment( label, HPos.LEFT );
		setValignment( label, VPos.BOTTOM );
		add( label, 0, gridRow );
		gridRow ++;

		ctrl = getJavaFXEditorISOTZoneId();
		setHalignment( ctrl, HPos.LEFT );
		add( ctrl, 0, gridRow );
		gridRow ++;

		label = getJavaFXLabelIso8601();
		setHalignment( label, HPos.LEFT );
		setValignment( label, VPos.BOTTOM );
		add( label, 0, gridRow );
		gridRow ++;

		ctrl = getJavaFXEditorIso8601();
		setHalignment( ctrl, HPos.LEFT );
		add( ctrl, 0, gridRow );
		gridRow ++;

		label = getJavaFXLabelTZName();
		setHalignment( label, HPos.LEFT );
		setValignment( label, VPos.BOTTOM );
		add( label, 0, gridRow );
		gridRow ++;

		ctrl = getJavaFXEditorTZName();
		setHalignment( ctrl, HPos.LEFT );
		add( ctrl, 0, gridRow );
		gridRow ++;

		label = getJavaFXLabelTZHourOffset();
		setHalignment( label, HPos.LEFT );
		setValignment( label, VPos.BOTTOM );
		add( label, 0, gridRow );
		gridRow ++;

		ctrl = getJavaFXEditorTZHourOffset();
		setHalignment( ctrl, HPos.LEFT );
		add( ctrl, 0, gridRow );
		gridRow ++;

		label = getJavaFXLabelTZMinOffset();
		setHalignment( label, HPos.LEFT );
		setValignment( label, VPos.BOTTOM );
		add( label, 0, gridRow );
		gridRow ++;

		ctrl = getJavaFXEditorTZMinOffset();
		setHalignment( ctrl, HPos.LEFT );
		add( ctrl, 0, gridRow );
		gridRow ++;

		label = getJavaFXLabelDescription();
		setHalignment( label, HPos.LEFT );
		setValignment( label, VPos.BOTTOM );
		add( label, 0, gridRow );
		gridRow ++;

		ctrl = getJavaFXEditorDescription();
		setHalignment( ctrl, HPos.LEFT );
		add( ctrl, 0, gridRow );
		gridRow ++;

		label = getJavaFXLabelVisible();
		setHalignment( label, HPos.LEFT );
		setValignment( label, VPos.BOTTOM );
		add( label, 0, gridRow );
		gridRow ++;

		ctrl = getJavaFXEditorVisible();
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
		if( ( value == null ) || ( value instanceof ICFSecISOTZoneObj ) ) {
			super.setJavaFXFocus( value );
		}
		else {
			throw new CFLibUnsupportedClassException( getClass(),
				S_ProcName,
				"value",
				value,
				"ICFSecISOTZoneObj" );
		}
		populateFields();
		adjustComponentEnableStates();
	}

	public ICFSecISOTZoneObj getJavaFXFocusAsISOTZone() {
		return( (ICFSecISOTZoneObj)getJavaFXFocus() );
	}

	public void setJavaFXFocusAsISOTZone( ICFSecISOTZoneObj value ) {
		setJavaFXFocus( value );
	}

	public ICFSecISOTZoneObj getEffJavaFXFocus() {
		ICFSecISOTZoneObj eff = (ICFSecISOTZoneObj)getJavaFXFocus();
		if( eff != null ) {
			if( null != eff.getEdit() ) {
				eff = (ICFSecISOTZoneObj)eff.getEdit();
			}
		}
		return( eff );
	}

	public ISOTZoneIdCFLabel getJavaFXLabelISOTZoneId() {
		if( javafxLabelISOTZoneId == null ) {
			javafxLabelISOTZoneId = new ISOTZoneIdCFLabel();
		}
		return( javafxLabelISOTZoneId );
	}

	public void setJavaFXLabelISOTZoneId( ISOTZoneIdCFLabel value ) {
		javafxLabelISOTZoneId = value;
	}

	public ISOTZoneIdEditor getJavaFXEditorISOTZoneId() {
		if( javafxEditorISOTZoneId == null ) {
			javafxEditorISOTZoneId = new ISOTZoneIdEditor();
		}
		return( javafxEditorISOTZoneId );
	}

	public void setJavaFXEditorISOTZoneId( ISOTZoneIdEditor value ) {
		javafxEditorISOTZoneId = value;
	}

	public Iso8601CFLabel getJavaFXLabelIso8601() {
		if( javafxLabelIso8601 == null ) {
			javafxLabelIso8601 = new Iso8601CFLabel();
		}
		return( javafxLabelIso8601 );
	}

	public void setJavaFXLabelIso8601( Iso8601CFLabel value ) {
		javafxLabelIso8601 = value;
	}

	public Iso8601Editor getJavaFXEditorIso8601() {
		if( javafxEditorIso8601 == null ) {
			javafxEditorIso8601 = new Iso8601Editor();
		}
		return( javafxEditorIso8601 );
	}

	public void setJavaFXEditorIso8601( Iso8601Editor value ) {
		javafxEditorIso8601 = value;
	}

	public TZNameCFLabel getJavaFXLabelTZName() {
		if( javafxLabelTZName == null ) {
			javafxLabelTZName = new TZNameCFLabel();
		}
		return( javafxLabelTZName );
	}

	public void setJavaFXLabelTZName( TZNameCFLabel value ) {
		javafxLabelTZName = value;
	}

	public TZNameEditor getJavaFXEditorTZName() {
		if( javafxEditorTZName == null ) {
			javafxEditorTZName = new TZNameEditor();
		}
		return( javafxEditorTZName );
	}

	public void setJavaFXEditorTZName( TZNameEditor value ) {
		javafxEditorTZName = value;
	}

	public TZHourOffsetCFLabel getJavaFXLabelTZHourOffset() {
		if( javafxLabelTZHourOffset == null ) {
			javafxLabelTZHourOffset = new TZHourOffsetCFLabel();
		}
		return( javafxLabelTZHourOffset );
	}

	public void setJavaFXLabelTZHourOffset( TZHourOffsetCFLabel value ) {
		javafxLabelTZHourOffset = value;
	}

	public TZHourOffsetEditor getJavaFXEditorTZHourOffset() {
		if( javafxEditorTZHourOffset == null ) {
			javafxEditorTZHourOffset = new TZHourOffsetEditor();
		}
		return( javafxEditorTZHourOffset );
	}

	public void setJavaFXEditorTZHourOffset( TZHourOffsetEditor value ) {
		javafxEditorTZHourOffset = value;
	}

	public TZMinOffsetCFLabel getJavaFXLabelTZMinOffset() {
		if( javafxLabelTZMinOffset == null ) {
			javafxLabelTZMinOffset = new TZMinOffsetCFLabel();
		}
		return( javafxLabelTZMinOffset );
	}

	public void setJavaFXLabelTZMinOffset( TZMinOffsetCFLabel value ) {
		javafxLabelTZMinOffset = value;
	}

	public TZMinOffsetEditor getJavaFXEditorTZMinOffset() {
		if( javafxEditorTZMinOffset == null ) {
			javafxEditorTZMinOffset = new TZMinOffsetEditor();
		}
		return( javafxEditorTZMinOffset );
	}

	public void setJavaFXEditorTZMinOffset( TZMinOffsetEditor value ) {
		javafxEditorTZMinOffset = value;
	}

	public DescriptionCFLabel getJavaFXLabelDescription() {
		if( javafxLabelDescription == null ) {
			javafxLabelDescription = new DescriptionCFLabel();
		}
		return( javafxLabelDescription );
	}

	public void setJavaFXLabelDescription( DescriptionCFLabel value ) {
		javafxLabelDescription = value;
	}

	public DescriptionEditor getJavaFXEditorDescription() {
		if( javafxEditorDescription == null ) {
			javafxEditorDescription = new DescriptionEditor();
		}
		return( javafxEditorDescription );
	}

	public void setJavaFXEditorDescription( DescriptionEditor value ) {
		javafxEditorDescription = value;
	}

	public VisibleCFLabel getJavaFXLabelVisible() {
		if( javafxLabelVisible == null ) {
			javafxLabelVisible = new VisibleCFLabel();
		}
		return( javafxLabelVisible );
	}

	public void setJavaFXLabelVisible( VisibleCFLabel value ) {
		javafxLabelVisible = value;
	}

	public VisibleEditor getJavaFXEditorVisible() {
		if( javafxEditorVisible == null ) {
			javafxEditorVisible = new VisibleEditor();
		}
		return( javafxEditorVisible );
	}

	public void setJavaFXEditorVisible( VisibleEditor value ) {
		javafxEditorVisible = value;
	}

	public void populateFields()
	{
		ICFSecISOTZoneObj popObj = getEffJavaFXFocus();
		if( getPaneMode() == CFPane.PaneMode.Unknown ) {
			popObj = null;
		}
		if( popObj == null ) {
			getJavaFXEditorISOTZoneId().setInt16Value( null );
		}
		else {
			getJavaFXEditorISOTZoneId().setInt16Value( popObj.getRequiredISOTZoneId() );
		}

		if( popObj == null ) {
			getJavaFXEditorIso8601().setStringValue( null );
		}
		else {
			getJavaFXEditorIso8601().setStringValue( popObj.getRequiredIso8601() );
		}

		if( popObj == null ) {
			getJavaFXEditorTZName().setStringValue( null );
		}
		else {
			getJavaFXEditorTZName().setStringValue( popObj.getRequiredTZName() );
		}

		if( popObj == null ) {
			getJavaFXEditorTZHourOffset().setInt16Value( null );
		}
		else {
			getJavaFXEditorTZHourOffset().setInt16Value( popObj.getRequiredTZHourOffset() );
		}

		if( popObj == null ) {
			getJavaFXEditorTZMinOffset().setInt16Value( null );
		}
		else {
			getJavaFXEditorTZMinOffset().setInt16Value( popObj.getRequiredTZMinOffset() );
		}

		if( popObj == null ) {
			getJavaFXEditorDescription().setStringValue( null );
		}
		else {
			getJavaFXEditorDescription().setStringValue( popObj.getRequiredDescription() );
		}

		if( popObj == null ) {
			getJavaFXEditorVisible().setBooleanValue( null );
		}
		else {
			getJavaFXEditorVisible().setBooleanValue( popObj.getRequiredVisible() );
		}
	}

	public void postFields()
	{
		final String S_ProcName = "postFields";
		ICFSecISOTZoneObj focus = getJavaFXFocusAsISOTZone();
		ICFSecISOTZoneEditObj editObj;
		if( focus != null ) {
			editObj = (ICFSecISOTZoneEditObj)(focus.getEdit());
		}
		else {
			editObj = null;
		}
		if( editObj == null ) {
			throw new CFLibUsageException( getClass(),
				S_ProcName,
				"Pane is unfocused or is not editing the focus object" );
		}

		if( getJavaFXEditorIso8601().getStringValue() == null ) {
			editObj.setRequiredIso8601( "" );
		}
		else {
			editObj.setRequiredIso8601( getJavaFXEditorIso8601().getStringValue() );
		}

		if( getJavaFXEditorTZName().getStringValue() == null ) {
			editObj.setRequiredTZName( "" );
		}
		else {
			editObj.setRequiredTZName( getJavaFXEditorTZName().getStringValue() );
		}

		editObj.setRequiredTZHourOffset( getJavaFXEditorTZHourOffset().getInt16Value() );

		editObj.setRequiredTZMinOffset( getJavaFXEditorTZMinOffset().getInt16Value() );

		if( getJavaFXEditorDescription().getStringValue() == null ) {
			editObj.setRequiredDescription( "" );
		}
		else {
			editObj.setRequiredDescription( getJavaFXEditorDescription().getStringValue() );
		}

		editObj.setRequiredVisible( getJavaFXEditorVisible().getBooleanValue() );
	}

	public void setPaneMode( CFPane.PaneMode value ) {
		final String S_ProcName = "setPaneMode";
		CFPane.PaneMode oldValue = getPaneMode();
		if( oldValue == value ) {
			return;
		}
		ICFSecISOTZoneObj focus = getJavaFXFocusAsISOTZone();
		if( ( value != CFPane.PaneMode.Unknown ) && ( value != CFPane.PaneMode.View ) ) {
			if( focus == null ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"javaFXFocus" );
			}
		}
		ICFSecISOTZoneEditObj editObj;
		if( focus != null ) {
			editObj  = (ICFSecISOTZoneEditObj)focus.getEdit();
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
								editObj = (ICFSecISOTZoneEditObj)focus.beginEdit();
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
							editObj = (ICFSecISOTZoneEditObj)focus.beginEdit();
							if( editObj == null ) {
								throw new CFLibUsageException( getClass(),
									S_ProcName,
									"Expected beginEdit() to return a new edition of the focus object" );
							}
						}
						break;
					case View:
						if( editObj == null ) {
							editObj = (ICFSecISOTZoneEditObj)focus.beginEdit();
							if( editObj == null ) {
								throw new CFLibUsageException( getClass(),
									S_ProcName,
									"Expected beginEdit() to return a new edition of the focus object" );
							}
						}
						break;
					case Edit:
						if( editObj == null ) {
							editObj = (ICFSecISOTZoneEditObj)focus.beginEdit();
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
						focus = (ICFSecISOTZoneObj)editObj.create();
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
								editObj = (ICFSecISOTZoneEditObj)focus.beginEdit();
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
								editObj = (ICFSecISOTZoneEditObj)focus.beginEdit();
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
							editObj = (ICFSecISOTZoneEditObj)focus.beginEdit();
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
			ICFSecISOTZoneObj focus = getJavaFXFocusAsISOTZone();
			if( focus == null ) {
				isEditing = false;
			}
			else if( null == focus.getEdit() ) {
				isEditing = false;
			}
		}
		if( javafxEditorISOTZoneId != null ) {
			javafxEditorISOTZoneId.setDisable( true );
		}
		if( javafxEditorIso8601 != null ) {
			javafxEditorIso8601.setDisable( ! isEditing );
		}
		if( javafxEditorTZName != null ) {
			javafxEditorTZName.setDisable( ! isEditing );
		}
		if( javafxEditorTZHourOffset != null ) {
			javafxEditorTZHourOffset.setDisable( ! isEditing );
		}
		if( javafxEditorTZMinOffset != null ) {
			javafxEditorTZMinOffset.setDisable( ! isEditing );
		}
		if( javafxEditorDescription != null ) {
			javafxEditorDescription.setDisable( ! isEditing );
		}
		if( javafxEditorVisible != null ) {
			javafxEditorVisible.setDisable( ! isEditing );
		}
	}
}
