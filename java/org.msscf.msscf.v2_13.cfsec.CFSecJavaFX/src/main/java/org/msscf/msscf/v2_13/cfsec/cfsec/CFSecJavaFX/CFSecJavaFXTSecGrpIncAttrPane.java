// Description: Java 11 JavaFX Attribute Pane implementation for TSecGrpInc.

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
 *	CFSecJavaFXTSecGrpIncAttrPane JavaFX Attribute Pane implementation
 *	for TSecGrpInc.
 */
public class CFSecJavaFXTSecGrpIncAttrPane
extends CFGridPane
implements ICFSecJavaFXTSecGrpIncPaneCommon
{
	protected ICFFormManager cfFormManager = null;
	protected ICFSecJavaFXSchema javafxSchema = null;
	boolean javafxIsInitializing = true;

	protected class TSecGrpIncSubGroupCFLabel
		extends CFLabel
	{
		public TSecGrpIncSubGroupCFLabel() {
			super();
			setText( "SubGroup" );
		}
	}

	protected class CallbackTSecGrpIncSubGroupChosen
	implements ICFSecJavaFXTSecGroupChosen
	{
		public CallbackTSecGrpIncSubGroupChosen() {
		}

		public void choseTSecGroup( ICFSecTSecGroupObj value ) {
			if( javafxReferenceParentSubGroup != null ) {
				ICFSecTSecGrpIncObj cur = getJavaFXFocusAsTSecGrpInc();
				if( cur != null ) {
					ICFSecTSecGrpIncEditObj editObj = (ICFSecTSecGrpIncEditObj)cur.getEdit();
					if( null != editObj ) {
						CFPane.PaneMode curMode = getPaneMode();
						if( ( curMode == CFPane.PaneMode.Add ) || ( curMode == CFPane.PaneMode.Edit ) ) {
							javafxReferenceParentSubGroup.setReferencedObject( value );
							editObj.setRequiredParentSubGroup( value );
						}
					}
				}
			}
		}
	}

	protected class TSecGrpIncSubGroupReferenceCallback
	implements ICFReferenceCallback
	{
		public void chose( ICFLibAnyObj value ) {
			final String S_ProcName = "chose";
			Node cont;
			ICFSecSchemaObj schemaObj = (ICFSecSchemaObj)javafxSchema.getSchema();
			ICFSecTSecGrpIncObj focus = getEffJavaFXFocus();
			ICFSecTSecGroupObj referencedObj = (ICFSecTSecGroupObj)javafxReferenceParentSubGroup.getReferencedObject();
			java.util.List<ICFSecTSecGroupObj> listOfTSecGroup = null;
			CFSecAuthorization auth = schemaObj.getAuthorization();
			long containingTenantId = auth.getSecTenantId();
			listOfTSecGroup = schemaObj.getTSecGroupTableObj().readTSecGroupByTenantIdx( containingTenantId );
			if( listOfTSecGroup == null ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"listOfTSecGroup" );
			}
			Collection<ICFSecTSecGroupObj> cltn = listOfTSecGroup;
			CFBorderPane form = javafxSchema.getTSecGroupFactory().newPickerForm( cfFormManager, referencedObj, null, cltn, new CallbackTSecGrpIncSubGroupChosen() );
			((ICFSecJavaFXTSecGroupPaneCommon)form).setPaneMode( CFPane.PaneMode.View );
			cfFormManager.pushForm( form );
		}

		public void view( ICFLibAnyObj value ) {
			final String S_ProcName = "actionPerformed";
			ICFSecTSecGrpIncObj focus = getEffJavaFXFocus();
			if( focus != null ) {
				ICFSecTSecGroupObj referencedObj = (ICFSecTSecGroupObj)javafxReferenceParentSubGroup.getReferencedObject();
				CFBorderPane form = null;
				if( referencedObj != null ) {
					String classCode = referencedObj.getClassCode();
					if( "a016".equals( classCode ) ) {
						form = javafxSchema.getTSecGroupFactory().newAddForm( cfFormManager, referencedObj, null, true );
						ICFSecJavaFXTSecGroupPaneCommon spec = (ICFSecJavaFXTSecGroupPaneCommon)form;
						spec.setJavaFXFocus( referencedObj );
						spec.setPaneMode( CFPane.PaneMode.View );
					}
					else {
						throw new CFLibUnsupportedClassException( getClass(),
							S_ProcName,
							"javaFXFocus",
							focus,
							"ICFSecTSecGroupObj" );
					}
					cfFormManager.pushForm( form );
				}
			}
		}
	}

	protected class TSecGrpIncSubGroupCFReferenceEditor
		extends CFReferenceEditor
	{
		public TSecGrpIncSubGroupCFReferenceEditor() {
			super( new TSecGrpIncSubGroupReferenceCallback() );
			setFieldName( "SubGroup" );
		}
	}

	protected class TSecGrpIncIdCFLabel
		extends CFLabel
	{
		public TSecGrpIncIdCFLabel() {
			super();
			setText( "TSecurity Group Include Id" );
		}
	}

	protected class TSecGrpIncIdEditor
		extends CFInt64Editor
	{
		public TSecGrpIncIdEditor() {
			super();
			setMinValue( CFSecTSecGrpIncBuff.TSECGRPINCID_MIN_VALUE );
			setFieldName( "TSecurity Group Include Id" );
		}
	}

	protected ICFSecTSecGroupObj javafxParentSubGroupObj = null;
	protected TSecGrpIncSubGroupCFLabel javafxLabelParentSubGroup = null;
	protected TSecGrpIncSubGroupCFReferenceEditor javafxReferenceParentSubGroup = null;
	protected TSecGrpIncIdCFLabel javafxLabelTSecGrpIncId = null;
	protected TSecGrpIncIdEditor javafxEditorTSecGrpIncId = null;

	public CFSecJavaFXTSecGrpIncAttrPane( ICFFormManager formManager, ICFSecJavaFXSchema argSchema, ICFSecTSecGrpIncObj argFocus ) {
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
		setJavaFXFocusAsTSecGrpInc( argFocus );
		setPadding( new Insets(5) );
		setHgap( 5 );
		setVgap( 5 );
		setAlignment( Pos.CENTER );
		ColumnConstraints column1 = new ColumnConstraints();
		column1.setPercentWidth( 100 );
		getColumnConstraints().addAll( column1 );
		int gridRow = 0;
		label = getJavaFXLabelParentSubGroup();
		setHalignment( label, HPos.LEFT );
		setValignment( label, VPos.BOTTOM );
		add( label, 0, gridRow );
		gridRow ++;

		reference = getJavaFXReferenceParentSubGroup();
		setHalignment( reference, HPos.LEFT );
		add( reference, 0, gridRow );
		gridRow ++;

		label = getJavaFXLabelTSecGrpIncId();
		setHalignment( label, HPos.LEFT );
		setValignment( label, VPos.BOTTOM );
		add( label, 0, gridRow );
		gridRow ++;

		ctrl = getJavaFXEditorTSecGrpIncId();
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
		if( ( value == null ) || ( value instanceof ICFSecTSecGrpIncObj ) ) {
			super.setJavaFXFocus( value );
		}
		else {
			throw new CFLibUnsupportedClassException( getClass(),
				S_ProcName,
				"value",
				value,
				"ICFSecTSecGrpIncObj" );
		}
		populateFields();
		adjustComponentEnableStates();
	}

	public ICFSecTSecGrpIncObj getJavaFXFocusAsTSecGrpInc() {
		return( (ICFSecTSecGrpIncObj)getJavaFXFocus() );
	}

	public void setJavaFXFocusAsTSecGrpInc( ICFSecTSecGrpIncObj value ) {
		setJavaFXFocus( value );
	}

	public ICFSecTSecGrpIncObj getEffJavaFXFocus() {
		ICFSecTSecGrpIncObj eff = (ICFSecTSecGrpIncObj)getJavaFXFocus();
		if( eff != null ) {
			if( null != eff.getEdit() ) {
				eff = (ICFSecTSecGrpIncObj)eff.getEdit();
			}
		}
		return( eff );
	}

	public ICFSecTSecGroupObj getJavaFXParentSubGroupObj() {
		return( javafxParentSubGroupObj );
	}

	public void setJavaFXParentSubGroupObj( ICFSecTSecGroupObj value ) {
		javafxParentSubGroupObj = value;
	}

	public CFLabel getJavaFXLabelParentSubGroup() {
		if( javafxLabelParentSubGroup == null ) {
			javafxLabelParentSubGroup = new TSecGrpIncSubGroupCFLabel();
		}
		return( javafxLabelParentSubGroup );
	}

	public CFReferenceEditor getJavaFXReferenceParentSubGroup() {
		if( javafxReferenceParentSubGroup == null ) {
			javafxReferenceParentSubGroup = new TSecGrpIncSubGroupCFReferenceEditor();
		}
		return( javafxReferenceParentSubGroup );
	}

	public void setJavaFXReferenceParentSubGroup( TSecGrpIncSubGroupCFReferenceEditor value ) {
		javafxReferenceParentSubGroup = value;
	}

	public TSecGrpIncIdCFLabel getJavaFXLabelTSecGrpIncId() {
		if( javafxLabelTSecGrpIncId == null ) {
			javafxLabelTSecGrpIncId = new TSecGrpIncIdCFLabel();
		}
		return( javafxLabelTSecGrpIncId );
	}

	public void setJavaFXLabelTSecGrpIncId( TSecGrpIncIdCFLabel value ) {
		javafxLabelTSecGrpIncId = value;
	}

	public TSecGrpIncIdEditor getJavaFXEditorTSecGrpIncId() {
		if( javafxEditorTSecGrpIncId == null ) {
			javafxEditorTSecGrpIncId = new TSecGrpIncIdEditor();
		}
		return( javafxEditorTSecGrpIncId );
	}

	public void setJavaFXEditorTSecGrpIncId( TSecGrpIncIdEditor value ) {
		javafxEditorTSecGrpIncId = value;
	}

	public void populateFields()
	{
		ICFSecTSecGrpIncObj popObj = getEffJavaFXFocus();
		if( getPaneMode() == CFPane.PaneMode.Unknown ) {
			popObj = null;
		}
		if( popObj == null ) {
			javafxParentSubGroupObj = null;
		}
		else {
			javafxParentSubGroupObj = (ICFSecTSecGroupObj)popObj.getRequiredParentSubGroup( javafxIsInitializing );
		}
		if( javafxReferenceParentSubGroup != null ) {
			javafxReferenceParentSubGroup.setReferencedObject( javafxParentSubGroupObj );
		}

		if( popObj == null ) {
			getJavaFXEditorTSecGrpIncId().setInt64Value( null );
		}
		else {
			getJavaFXEditorTSecGrpIncId().setInt64Value( popObj.getRequiredTSecGrpIncId() );
		}
	}

	public void postFields()
	{
		final String S_ProcName = "postFields";
		ICFSecTSecGrpIncObj focus = getJavaFXFocusAsTSecGrpInc();
		ICFSecTSecGrpIncEditObj editObj;
		if( focus != null ) {
			editObj = (ICFSecTSecGrpIncEditObj)(focus.getEdit());
		}
		else {
			editObj = null;
		}
		if( editObj == null ) {
			throw new CFLibUsageException( getClass(),
				S_ProcName,
				"Pane is unfocused or is not editing the focus object" );
		}

		javafxParentSubGroupObj = (ICFSecTSecGroupObj)( javafxReferenceParentSubGroup.getReferencedObject() );
		editObj.setRequiredParentSubGroup( javafxParentSubGroupObj );
	}

	public void setPaneMode( CFPane.PaneMode value ) {
		final String S_ProcName = "setPaneMode";
		CFPane.PaneMode oldValue = getPaneMode();
		if( oldValue == value ) {
			return;
		}
		ICFSecTSecGrpIncObj focus = getJavaFXFocusAsTSecGrpInc();
		if( ( value != CFPane.PaneMode.Unknown ) && ( value != CFPane.PaneMode.View ) ) {
			if( focus == null ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"javaFXFocus" );
			}
		}
		ICFSecTSecGrpIncEditObj editObj;
		if( focus != null ) {
			editObj  = (ICFSecTSecGrpIncEditObj)focus.getEdit();
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
								editObj = (ICFSecTSecGrpIncEditObj)focus.beginEdit();
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
							editObj = (ICFSecTSecGrpIncEditObj)focus.beginEdit();
							if( editObj == null ) {
								throw new CFLibUsageException( getClass(),
									S_ProcName,
									"Expected beginEdit() to return a new edition of the focus object" );
							}
						}
						break;
					case View:
						if( editObj == null ) {
							editObj = (ICFSecTSecGrpIncEditObj)focus.beginEdit();
							if( editObj == null ) {
								throw new CFLibUsageException( getClass(),
									S_ProcName,
									"Expected beginEdit() to return a new edition of the focus object" );
							}
						}
						break;
					case Edit:
						if( editObj == null ) {
							editObj = (ICFSecTSecGrpIncEditObj)focus.beginEdit();
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
						focus = (ICFSecTSecGrpIncObj)editObj.create();
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
								editObj = (ICFSecTSecGrpIncEditObj)focus.beginEdit();
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
								editObj = (ICFSecTSecGrpIncEditObj)focus.beginEdit();
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
							editObj = (ICFSecTSecGrpIncEditObj)focus.beginEdit();
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
			ICFSecTSecGrpIncObj focus = getJavaFXFocusAsTSecGrpInc();
			if( focus == null ) {
				isEditing = false;
			}
			else if( null == focus.getEdit() ) {
				isEditing = false;
			}
		}
		if( javafxReferenceParentSubGroup != null ) {
			javafxReferenceParentSubGroup.setCustomDisable( ! isEditing );
		}
		if( javafxEditorTSecGrpIncId != null ) {
			javafxEditorTSecGrpIncId.setDisable( true );
		}
	}
}
