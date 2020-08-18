// Description: Java 11 JavaFX Attribute Pane implementation for SecGrpInc.

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
 *	CFSecJavaFXSecGrpIncAttrPane JavaFX Attribute Pane implementation
 *	for SecGrpInc.
 */
public class CFSecJavaFXSecGrpIncAttrPane
extends CFGridPane
implements ICFSecJavaFXSecGrpIncPaneCommon
{
	protected ICFFormManager cfFormManager = null;
	protected ICFSecJavaFXSchema javafxSchema = null;
	boolean javafxIsInitializing = true;

	protected class SecGrpIncSubGroupCFLabel
		extends CFLabel
	{
		public SecGrpIncSubGroupCFLabel() {
			super();
			setText( "SubGroup" );
		}
	}

	protected class CallbackSecGrpIncSubGroupChosen
	implements ICFSecJavaFXSecGroupChosen
	{
		public CallbackSecGrpIncSubGroupChosen() {
		}

		public void choseSecGroup( ICFSecSecGroupObj value ) {
			if( javafxReferenceParentSubGroup != null ) {
				ICFSecSecGrpIncObj cur = getJavaFXFocusAsSecGrpInc();
				if( cur != null ) {
					ICFSecSecGrpIncEditObj editObj = (ICFSecSecGrpIncEditObj)cur.getEdit();
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

	protected class SecGrpIncSubGroupReferenceCallback
	implements ICFReferenceCallback
	{
		public void chose( ICFLibAnyObj value ) {
			final String S_ProcName = "chose";
			Node cont;
			ICFSecSchemaObj schemaObj = (ICFSecSchemaObj)javafxSchema.getSchema();
			ICFSecSecGrpIncObj focus = getEffJavaFXFocus();
			ICFSecSecGroupObj referencedObj = (ICFSecSecGroupObj)javafxReferenceParentSubGroup.getReferencedObject();
			java.util.List<ICFSecSecGroupObj> listOfSecGroup = null;
			CFSecAuthorization auth = schemaObj.getAuthorization();
			long containingClusterId = auth.getSecClusterId();
			listOfSecGroup = schemaObj.getSecGroupTableObj().readSecGroupByClusterIdx( containingClusterId );
			if( listOfSecGroup == null ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"listOfSecGroup" );
			}
			Collection<ICFSecSecGroupObj> cltn = listOfSecGroup;
			CFBorderPane form = javafxSchema.getSecGroupFactory().newPickerForm( cfFormManager, referencedObj, null, cltn, new CallbackSecGrpIncSubGroupChosen() );
			((ICFSecJavaFXSecGroupPaneCommon)form).setPaneMode( CFPane.PaneMode.View );
			cfFormManager.pushForm( form );
		}

		public void view( ICFLibAnyObj value ) {
			final String S_ProcName = "actionPerformed";
			ICFSecSecGrpIncObj focus = getEffJavaFXFocus();
			if( focus != null ) {
				ICFSecSecGroupObj referencedObj = (ICFSecSecGroupObj)javafxReferenceParentSubGroup.getReferencedObject();
				CFBorderPane form = null;
				if( referencedObj != null ) {
					String classCode = referencedObj.getClassCode();
					if( "a00c".equals( classCode ) ) {
						form = javafxSchema.getSecGroupFactory().newAddForm( cfFormManager, referencedObj, null, true );
						ICFSecJavaFXSecGroupPaneCommon spec = (ICFSecJavaFXSecGroupPaneCommon)form;
						spec.setJavaFXFocus( referencedObj );
						spec.setPaneMode( CFPane.PaneMode.View );
					}
					else {
						throw new CFLibUnsupportedClassException( getClass(),
							S_ProcName,
							"javaFXFocus",
							focus,
							"ICFSecSecGroupObj" );
					}
					cfFormManager.pushForm( form );
				}
			}
		}
	}

	protected class SecGrpIncSubGroupCFReferenceEditor
		extends CFReferenceEditor
	{
		public SecGrpIncSubGroupCFReferenceEditor() {
			super( new SecGrpIncSubGroupReferenceCallback() );
			setFieldName( "SubGroup" );
		}
	}

	protected class SecGrpIncIdCFLabel
		extends CFLabel
	{
		public SecGrpIncIdCFLabel() {
			super();
			setText( "Security Group Include Id" );
		}
	}

	protected class SecGrpIncIdEditor
		extends CFInt64Editor
	{
		public SecGrpIncIdEditor() {
			super();
			setMinValue( CFSecSecGrpIncBuff.SECGRPINCID_MIN_VALUE );
			setFieldName( "Security Group Include Id" );
		}
	}

	protected ICFSecSecGroupObj javafxParentSubGroupObj = null;
	protected SecGrpIncSubGroupCFLabel javafxLabelParentSubGroup = null;
	protected SecGrpIncSubGroupCFReferenceEditor javafxReferenceParentSubGroup = null;
	protected SecGrpIncIdCFLabel javafxLabelSecGrpIncId = null;
	protected SecGrpIncIdEditor javafxEditorSecGrpIncId = null;

	public CFSecJavaFXSecGrpIncAttrPane( ICFFormManager formManager, ICFSecJavaFXSchema argSchema, ICFSecSecGrpIncObj argFocus ) {
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
		setJavaFXFocusAsSecGrpInc( argFocus );
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

		label = getJavaFXLabelSecGrpIncId();
		setHalignment( label, HPos.LEFT );
		setValignment( label, VPos.BOTTOM );
		add( label, 0, gridRow );
		gridRow ++;

		ctrl = getJavaFXEditorSecGrpIncId();
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
		if( ( value == null ) || ( value instanceof ICFSecSecGrpIncObj ) ) {
			super.setJavaFXFocus( value );
		}
		else {
			throw new CFLibUnsupportedClassException( getClass(),
				S_ProcName,
				"value",
				value,
				"ICFSecSecGrpIncObj" );
		}
		populateFields();
		adjustComponentEnableStates();
	}

	public ICFSecSecGrpIncObj getJavaFXFocusAsSecGrpInc() {
		return( (ICFSecSecGrpIncObj)getJavaFXFocus() );
	}

	public void setJavaFXFocusAsSecGrpInc( ICFSecSecGrpIncObj value ) {
		setJavaFXFocus( value );
	}

	public ICFSecSecGrpIncObj getEffJavaFXFocus() {
		ICFSecSecGrpIncObj eff = (ICFSecSecGrpIncObj)getJavaFXFocus();
		if( eff != null ) {
			if( null != eff.getEdit() ) {
				eff = (ICFSecSecGrpIncObj)eff.getEdit();
			}
		}
		return( eff );
	}

	public ICFSecSecGroupObj getJavaFXParentSubGroupObj() {
		return( javafxParentSubGroupObj );
	}

	public void setJavaFXParentSubGroupObj( ICFSecSecGroupObj value ) {
		javafxParentSubGroupObj = value;
	}

	public CFLabel getJavaFXLabelParentSubGroup() {
		if( javafxLabelParentSubGroup == null ) {
			javafxLabelParentSubGroup = new SecGrpIncSubGroupCFLabel();
		}
		return( javafxLabelParentSubGroup );
	}

	public CFReferenceEditor getJavaFXReferenceParentSubGroup() {
		if( javafxReferenceParentSubGroup == null ) {
			javafxReferenceParentSubGroup = new SecGrpIncSubGroupCFReferenceEditor();
		}
		return( javafxReferenceParentSubGroup );
	}

	public void setJavaFXReferenceParentSubGroup( SecGrpIncSubGroupCFReferenceEditor value ) {
		javafxReferenceParentSubGroup = value;
	}

	public SecGrpIncIdCFLabel getJavaFXLabelSecGrpIncId() {
		if( javafxLabelSecGrpIncId == null ) {
			javafxLabelSecGrpIncId = new SecGrpIncIdCFLabel();
		}
		return( javafxLabelSecGrpIncId );
	}

	public void setJavaFXLabelSecGrpIncId( SecGrpIncIdCFLabel value ) {
		javafxLabelSecGrpIncId = value;
	}

	public SecGrpIncIdEditor getJavaFXEditorSecGrpIncId() {
		if( javafxEditorSecGrpIncId == null ) {
			javafxEditorSecGrpIncId = new SecGrpIncIdEditor();
		}
		return( javafxEditorSecGrpIncId );
	}

	public void setJavaFXEditorSecGrpIncId( SecGrpIncIdEditor value ) {
		javafxEditorSecGrpIncId = value;
	}

	public void populateFields()
	{
		ICFSecSecGrpIncObj popObj = getEffJavaFXFocus();
		if( getPaneMode() == CFPane.PaneMode.Unknown ) {
			popObj = null;
		}
		if( popObj == null ) {
			javafxParentSubGroupObj = null;
		}
		else {
			javafxParentSubGroupObj = (ICFSecSecGroupObj)popObj.getRequiredParentSubGroup( javafxIsInitializing );
		}
		if( javafxReferenceParentSubGroup != null ) {
			javafxReferenceParentSubGroup.setReferencedObject( javafxParentSubGroupObj );
		}

		if( popObj == null ) {
			getJavaFXEditorSecGrpIncId().setInt64Value( null );
		}
		else {
			getJavaFXEditorSecGrpIncId().setInt64Value( popObj.getRequiredSecGrpIncId() );
		}
	}

	public void postFields()
	{
		final String S_ProcName = "postFields";
		ICFSecSecGrpIncObj focus = getJavaFXFocusAsSecGrpInc();
		ICFSecSecGrpIncEditObj editObj;
		if( focus != null ) {
			editObj = (ICFSecSecGrpIncEditObj)(focus.getEdit());
		}
		else {
			editObj = null;
		}
		if( editObj == null ) {
			throw new CFLibUsageException( getClass(),
				S_ProcName,
				"Pane is unfocused or is not editing the focus object" );
		}

		javafxParentSubGroupObj = (ICFSecSecGroupObj)( javafxReferenceParentSubGroup.getReferencedObject() );
		editObj.setRequiredParentSubGroup( javafxParentSubGroupObj );
	}

	public void setPaneMode( CFPane.PaneMode value ) {
		final String S_ProcName = "setPaneMode";
		CFPane.PaneMode oldValue = getPaneMode();
		if( oldValue == value ) {
			return;
		}
		ICFSecSecGrpIncObj focus = getJavaFXFocusAsSecGrpInc();
		if( ( value != CFPane.PaneMode.Unknown ) && ( value != CFPane.PaneMode.View ) ) {
			if( focus == null ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"javaFXFocus" );
			}
		}
		ICFSecSecGrpIncEditObj editObj;
		if( focus != null ) {
			editObj  = (ICFSecSecGrpIncEditObj)focus.getEdit();
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
								editObj = (ICFSecSecGrpIncEditObj)focus.beginEdit();
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
							editObj = (ICFSecSecGrpIncEditObj)focus.beginEdit();
							if( editObj == null ) {
								throw new CFLibUsageException( getClass(),
									S_ProcName,
									"Expected beginEdit() to return a new edition of the focus object" );
							}
						}
						break;
					case View:
						if( editObj == null ) {
							editObj = (ICFSecSecGrpIncEditObj)focus.beginEdit();
							if( editObj == null ) {
								throw new CFLibUsageException( getClass(),
									S_ProcName,
									"Expected beginEdit() to return a new edition of the focus object" );
							}
						}
						break;
					case Edit:
						if( editObj == null ) {
							editObj = (ICFSecSecGrpIncEditObj)focus.beginEdit();
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
						focus = (ICFSecSecGrpIncObj)editObj.create();
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
								editObj = (ICFSecSecGrpIncEditObj)focus.beginEdit();
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
								editObj = (ICFSecSecGrpIncEditObj)focus.beginEdit();
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
							editObj = (ICFSecSecGrpIncEditObj)focus.beginEdit();
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
			ICFSecSecGrpIncObj focus = getJavaFXFocusAsSecGrpInc();
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
		if( javafxEditorSecGrpIncId != null ) {
			javafxEditorSecGrpIncId.setDisable( true );
		}
	}
}
