// Description: Java 11 JavaFX Attribute Pane implementation for ISOCtryCcy.

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
 *	CFSecJavaFXISOCtryCcyAttrPane JavaFX Attribute Pane implementation
 *	for ISOCtryCcy.
 */
public class CFSecJavaFXISOCtryCcyAttrPane
extends CFGridPane
implements ICFSecJavaFXISOCtryCcyPaneCommon
{
	protected ICFFormManager cfFormManager = null;
	protected ICFSecJavaFXSchema javafxSchema = null;
	boolean javafxIsInitializing = true;

	protected class ISOCtryCcyCcyCFLabel
		extends CFLabel
	{
		public ISOCtryCcyCcyCFLabel() {
			super();
			setText( "Ccy" );
		}
	}

	protected class CallbackISOCtryCcyCcyChosen
	implements ICFSecJavaFXISOCcyChosen
	{
		public CallbackISOCtryCcyCcyChosen() {
		}

		public void choseISOCcy( ICFSecISOCcyObj value ) {
			if( javafxReferenceParentCcy != null ) {
				ICFSecISOCtryCcyObj cur = getJavaFXFocusAsISOCtryCcy();
				if( cur != null ) {
					ICFSecISOCtryCcyEditObj editObj = (ICFSecISOCtryCcyEditObj)cur.getEdit();
					if( null != editObj ) {
						CFPane.PaneMode curMode = getPaneMode();
						if( ( curMode == CFPane.PaneMode.Add ) || ( curMode == CFPane.PaneMode.Edit ) ) {
							javafxReferenceParentCcy.setReferencedObject( value );
							editObj.setRequiredParentCcy( value );
						}
					}
				}
			}
		}
	}

	protected class ISOCtryCcyCcyReferenceCallback
	implements ICFReferenceCallback
	{
		public void chose( ICFLibAnyObj value ) {
			final String S_ProcName = "chose";
			Node cont;
			ICFSecSchemaObj schemaObj = (ICFSecSchemaObj)javafxSchema.getSchema();
			ICFSecISOCtryCcyObj focus = getEffJavaFXFocus();
			ICFSecISOCcyObj referencedObj = (ICFSecISOCcyObj)javafxReferenceParentCcy.getReferencedObject();
			java.util.List<ICFSecISOCcyObj> listOfISOCcy = null;
			listOfISOCcy = schemaObj.getISOCcyTableObj().readAllISOCcy();
			if( listOfISOCcy == null ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"listOfISOCcy" );
			}
			Collection<ICFSecISOCcyObj> cltn = listOfISOCcy;
			CFBorderPane form = javafxSchema.getISOCcyFactory().newPickerForm( cfFormManager, referencedObj, null, cltn, new CallbackISOCtryCcyCcyChosen() );
			((ICFSecJavaFXISOCcyPaneCommon)form).setPaneMode( CFPane.PaneMode.View );
			cfFormManager.pushForm( form );
		}

		public void view( ICFLibAnyObj value ) {
			final String S_ProcName = "actionPerformed";
			ICFSecISOCtryCcyObj focus = getEffJavaFXFocus();
			if( focus != null ) {
				ICFSecISOCcyObj referencedObj = (ICFSecISOCcyObj)javafxReferenceParentCcy.getReferencedObject();
				CFBorderPane form = null;
				if( referencedObj != null ) {
					String classCode = referencedObj.getClassCode();
					if( "a003".equals( classCode ) ) {
						form = javafxSchema.getISOCcyFactory().newAddForm( cfFormManager, referencedObj, null, true );
						ICFSecJavaFXISOCcyPaneCommon spec = (ICFSecJavaFXISOCcyPaneCommon)form;
						spec.setJavaFXFocus( referencedObj );
						spec.setPaneMode( CFPane.PaneMode.View );
					}
					else {
						throw new CFLibUnsupportedClassException( getClass(),
							S_ProcName,
							"javaFXFocus",
							focus,
							"ICFSecISOCcyObj" );
					}
					cfFormManager.pushForm( form );
				}
			}
		}
	}

	protected class ISOCtryCcyCcyCFReferenceEditor
		extends CFReferenceEditor
	{
		public ISOCtryCcyCcyCFReferenceEditor() {
			super( new ISOCtryCcyCcyReferenceCallback() );
			setFieldName( "Ccy" );
		}
	}

	protected ICFSecISOCcyObj javafxParentCcyObj = null;
	protected ISOCtryCcyCcyCFLabel javafxLabelParentCcy = null;
	protected ISOCtryCcyCcyCFReferenceEditor javafxReferenceParentCcy = null;

	public CFSecJavaFXISOCtryCcyAttrPane( ICFFormManager formManager, ICFSecJavaFXSchema argSchema, ICFSecISOCtryCcyObj argFocus ) {
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
		setJavaFXFocusAsISOCtryCcy( argFocus );
		setPadding( new Insets(5) );
		setHgap( 5 );
		setVgap( 5 );
		setAlignment( Pos.CENTER );
		ColumnConstraints column1 = new ColumnConstraints();
		column1.setPercentWidth( 100 );
		getColumnConstraints().addAll( column1 );
		int gridRow = 0;
		label = getJavaFXLabelParentCcy();
		setHalignment( label, HPos.LEFT );
		setValignment( label, VPos.BOTTOM );
		add( label, 0, gridRow );
		gridRow ++;

		reference = getJavaFXReferenceParentCcy();
		setHalignment( reference, HPos.LEFT );
		add( reference, 0, gridRow );
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
		if( ( value == null ) || ( value instanceof ICFSecISOCtryCcyObj ) ) {
			super.setJavaFXFocus( value );
		}
		else {
			throw new CFLibUnsupportedClassException( getClass(),
				S_ProcName,
				"value",
				value,
				"ICFSecISOCtryCcyObj" );
		}
		populateFields();
		adjustComponentEnableStates();
	}

	public ICFSecISOCtryCcyObj getJavaFXFocusAsISOCtryCcy() {
		return( (ICFSecISOCtryCcyObj)getJavaFXFocus() );
	}

	public void setJavaFXFocusAsISOCtryCcy( ICFSecISOCtryCcyObj value ) {
		setJavaFXFocus( value );
	}

	public ICFSecISOCtryCcyObj getEffJavaFXFocus() {
		ICFSecISOCtryCcyObj eff = (ICFSecISOCtryCcyObj)getJavaFXFocus();
		if( eff != null ) {
			if( null != eff.getEdit() ) {
				eff = (ICFSecISOCtryCcyObj)eff.getEdit();
			}
		}
		return( eff );
	}

	public ICFSecISOCcyObj getJavaFXParentCcyObj() {
		return( javafxParentCcyObj );
	}

	public void setJavaFXParentCcyObj( ICFSecISOCcyObj value ) {
		javafxParentCcyObj = value;
	}

	public CFLabel getJavaFXLabelParentCcy() {
		if( javafxLabelParentCcy == null ) {
			javafxLabelParentCcy = new ISOCtryCcyCcyCFLabel();
		}
		return( javafxLabelParentCcy );
	}

	public CFReferenceEditor getJavaFXReferenceParentCcy() {
		if( javafxReferenceParentCcy == null ) {
			javafxReferenceParentCcy = new ISOCtryCcyCcyCFReferenceEditor();
		}
		return( javafxReferenceParentCcy );
	}

	public void setJavaFXReferenceParentCcy( ISOCtryCcyCcyCFReferenceEditor value ) {
		javafxReferenceParentCcy = value;
	}

	public void populateFields()
	{
		ICFSecISOCtryCcyObj popObj = getEffJavaFXFocus();
		if( getPaneMode() == CFPane.PaneMode.Unknown ) {
			popObj = null;
		}
		if( popObj == null ) {
			javafxParentCcyObj = null;
		}
		else {
			javafxParentCcyObj = (ICFSecISOCcyObj)popObj.getRequiredParentCcy( javafxIsInitializing );
		}
		if( javafxReferenceParentCcy != null ) {
			javafxReferenceParentCcy.setReferencedObject( javafxParentCcyObj );
		}
	}

	public void postFields()
	{
		final String S_ProcName = "postFields";
		ICFSecISOCtryCcyObj focus = getJavaFXFocusAsISOCtryCcy();
		ICFSecISOCtryCcyEditObj editObj;
		if( focus != null ) {
			editObj = (ICFSecISOCtryCcyEditObj)(focus.getEdit());
		}
		else {
			editObj = null;
		}
		if( editObj == null ) {
			throw new CFLibUsageException( getClass(),
				S_ProcName,
				"Pane is unfocused or is not editing the focus object" );
		}

		javafxParentCcyObj = (ICFSecISOCcyObj)( javafxReferenceParentCcy.getReferencedObject() );
		editObj.setRequiredParentCcy( javafxParentCcyObj );
	}

	public void setPaneMode( CFPane.PaneMode value ) {
		final String S_ProcName = "setPaneMode";
		CFPane.PaneMode oldValue = getPaneMode();
		if( oldValue == value ) {
			return;
		}
		ICFSecISOCtryCcyObj focus = getJavaFXFocusAsISOCtryCcy();
		if( ( value != CFPane.PaneMode.Unknown ) && ( value != CFPane.PaneMode.View ) ) {
			if( focus == null ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"javaFXFocus" );
			}
		}
		ICFSecISOCtryCcyEditObj editObj;
		if( focus != null ) {
			editObj  = (ICFSecISOCtryCcyEditObj)focus.getEdit();
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
								editObj = (ICFSecISOCtryCcyEditObj)focus.beginEdit();
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
							editObj = (ICFSecISOCtryCcyEditObj)focus.beginEdit();
							if( editObj == null ) {
								throw new CFLibUsageException( getClass(),
									S_ProcName,
									"Expected beginEdit() to return a new edition of the focus object" );
							}
						}
						break;
					case View:
						if( editObj == null ) {
							editObj = (ICFSecISOCtryCcyEditObj)focus.beginEdit();
							if( editObj == null ) {
								throw new CFLibUsageException( getClass(),
									S_ProcName,
									"Expected beginEdit() to return a new edition of the focus object" );
							}
						}
						break;
					case Edit:
						if( editObj == null ) {
							editObj = (ICFSecISOCtryCcyEditObj)focus.beginEdit();
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
						focus = (ICFSecISOCtryCcyObj)editObj.create();
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
								editObj = (ICFSecISOCtryCcyEditObj)focus.beginEdit();
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
								editObj = (ICFSecISOCtryCcyEditObj)focus.beginEdit();
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
							editObj = (ICFSecISOCtryCcyEditObj)focus.beginEdit();
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
			ICFSecISOCtryCcyObj focus = getJavaFXFocusAsISOCtryCcy();
			if( focus == null ) {
				isEditing = false;
			}
			else if( null == focus.getEdit() ) {
				isEditing = false;
			}
		}
		if( javafxReferenceParentCcy != null ) {
			javafxReferenceParentCcy.setCustomDisable( ! isEditing );
		}
	}
}
