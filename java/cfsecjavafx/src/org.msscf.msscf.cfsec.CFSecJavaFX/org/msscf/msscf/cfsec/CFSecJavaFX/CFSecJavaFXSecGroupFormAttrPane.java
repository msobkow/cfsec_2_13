// Description: Java 11 JavaFX Attribute Pane implementation for SecGroupForm.

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

package org.msscf.msscf.cfsec.CFSecJavaFX;

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
import org.msscf.msscf.cflib.CFLib.*;
import org.msscf.msscf.cflib.CFLib.JavaFX.*;
import org.msscf.msscf.cflib.CFLib.JavaFX.CFReferenceEditor.ICFReferenceCallback;
import org.apache.commons.codec.binary.Base64;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfsec.CFSecObj.*;

/**
 *	CFSecJavaFXSecGroupFormAttrPane JavaFX Attribute Pane implementation
 *	for SecGroupForm.
 */
public class CFSecJavaFXSecGroupFormAttrPane
extends CFGridPane
implements ICFSecJavaFXSecGroupFormPaneCommon
{
	protected ICFFormManager cfFormManager = null;
	protected ICFSecJavaFXSchema javafxSchema = null;
	boolean javafxIsInitializing = true;

	protected class SecGroupFormAppCFLabel
		extends CFLabel
	{
		public SecGroupFormAppCFLabel() {
			super();
			setText( "App" );
		}
	}

	protected class CallbackSecGroupFormAppChosen
	implements ICFSecJavaFXSecAppChosen
	{
		public CallbackSecGroupFormAppChosen() {
		}

		public void choseSecApp( ICFSecSecAppObj value ) {
			if( javafxReferenceParentApp != null ) {
				ICFSecSecGroupFormObj cur = getJavaFXFocusAsSecGroupForm();
				if( cur != null ) {
					ICFSecSecGroupFormEditObj editObj = (ICFSecSecGroupFormEditObj)cur.getEdit();
					if( null != editObj ) {
						CFPane.PaneMode curMode = getPaneMode();
						if( ( curMode == CFPane.PaneMode.Add ) || ( curMode == CFPane.PaneMode.Edit ) ) {
							javafxReferenceParentApp.setReferencedObject( value );
							editObj.setRequiredParentApp( value );
						}
					}
				}
			}
		}
	}

	protected class PageDataParentAppList
	implements ICFSecJavaFXSecAppPageCallback
	{
		public PageDataParentAppList() {
		}

		public List<ICFSecSecAppObj> pageData( Long priorClusterId,
		Integer priorSecAppId )
		{
			java.util.List<ICFSecSecAppObj> listOfSecApp = null;
			ICFSecSecGroupFormObj focus = (ICFSecSecGroupFormObj)getEffJavaFXFocus();
			if( focus != null ) {
				ICFSecSchemaObj schemaObj = (ICFSecSchemaObj)javafxSchema.getSchema();
			CFSecAuthorization auth = schemaObj.getAuthorization();
			long containingClusterId = auth.getSecClusterId();
			listOfSecApp = schemaObj.getSecAppTableObj().pageSecAppByClusterIdx( containingClusterId,
					priorClusterId,
					priorSecAppId );
			}
			else {
				listOfSecApp = new ArrayList<ICFSecSecAppObj>();
			}
			return( listOfSecApp  );
		}
	}

	protected class SecGroupFormAppReferenceCallback
	implements ICFReferenceCallback
	{
		public void chose( ICFLibAnyObj value ) {
			final String S_ProcName = "chose";
			Node cont;
			ICFSecSchemaObj schemaObj = (ICFSecSchemaObj)javafxSchema.getSchema();
			ICFSecSecGroupFormObj focus = getEffJavaFXFocus();
			ICFSecSecAppObj referencedObj = (ICFSecSecAppObj)javafxReferenceParentApp.getReferencedObject();
			CFBorderPane form = javafxSchema.getSecAppFactory().newPickerForm( cfFormManager, referencedObj, null, new PageDataParentAppList(), new CallbackSecGroupFormAppChosen() );
			((ICFSecJavaFXSecAppPaneCommon)form).setPaneMode( CFPane.PaneMode.View );
			cfFormManager.pushForm( form );
		}

		public void view( ICFLibAnyObj value ) {
			final String S_ProcName = "actionPerformed";
			ICFSecSecGroupFormObj focus = getEffJavaFXFocus();
			if( focus != null ) {
				ICFSecSecAppObj referencedObj = (ICFSecSecAppObj)javafxReferenceParentApp.getReferencedObject();
				CFBorderPane form = null;
				if( referencedObj != null ) {
					String classCode = referencedObj.getClassCode();
					if( "a009".equals( classCode ) ) {
						form = javafxSchema.getSecAppFactory().newAddForm( cfFormManager, referencedObj, null, true );
						ICFSecJavaFXSecAppPaneCommon spec = (ICFSecJavaFXSecAppPaneCommon)form;
						spec.setJavaFXFocus( referencedObj );
						spec.setPaneMode( CFPane.PaneMode.View );
					}
					else {
						throw new CFLibUnsupportedClassException( getClass(),
							S_ProcName,
							"javaFXFocus",
							focus,
							"ICFSecSecAppObj" );
					}
					cfFormManager.pushForm( form );
				}
			}
		}
	}

	protected class SecGroupFormAppCFReferenceEditor
		extends CFReferenceEditor
	{
		public SecGroupFormAppCFReferenceEditor() {
			super( new SecGroupFormAppReferenceCallback() );
			setFieldName( "App" );
		}
	}

	protected class SecGroupFormFormCFLabel
		extends CFLabel
	{
		public SecGroupFormFormCFLabel() {
			super();
			setText( "Form" );
		}
	}

	protected class CallbackSecGroupFormFormChosen
	implements ICFSecJavaFXSecFormChosen
	{
		public CallbackSecGroupFormFormChosen() {
		}

		public void choseSecForm( ICFSecSecFormObj value ) {
			if( javafxReferenceParentForm != null ) {
				ICFSecSecGroupFormObj cur = getJavaFXFocusAsSecGroupForm();
				if( cur != null ) {
					ICFSecSecGroupFormEditObj editObj = (ICFSecSecGroupFormEditObj)cur.getEdit();
					if( null != editObj ) {
						CFPane.PaneMode curMode = getPaneMode();
						if( ( curMode == CFPane.PaneMode.Add ) || ( curMode == CFPane.PaneMode.Edit ) ) {
							javafxReferenceParentForm.setReferencedObject( value );
							editObj.setRequiredParentForm( value );
						}
					}
				}
			}
		}
	}

	protected class PageDataParentFormList
	implements ICFSecJavaFXSecFormPageCallback
	{
		public PageDataParentFormList() {
		}

		public List<ICFSecSecFormObj> pageData( Long priorClusterId,
		Integer priorSecFormId )
		{
			java.util.List<ICFSecSecFormObj> listOfSecForm = null;
			ICFSecSecGroupFormObj focus = (ICFSecSecGroupFormObj)getEffJavaFXFocus();
			if( focus != null ) {
				ICFSecSchemaObj schemaObj = (ICFSecSchemaObj)javafxSchema.getSchema();
			Collection<ICFSecSecFormObj> cltn = null;
			}
			else {
				listOfSecForm = new ArrayList<ICFSecSecFormObj>();
			}
			return( listOfSecForm  );
		}
	}

	protected class SecGroupFormFormReferenceCallback
	implements ICFReferenceCallback
	{
		public void chose( ICFLibAnyObj value ) {
			final String S_ProcName = "chose";
			Node cont;
			ICFSecSchemaObj schemaObj = (ICFSecSchemaObj)javafxSchema.getSchema();
			ICFSecSecGroupFormObj focus = getEffJavaFXFocus();
			ICFSecSecFormObj referencedObj = (ICFSecSecFormObj)javafxReferenceParentForm.getReferencedObject();
			CFBorderPane form = javafxSchema.getSecFormFactory().newPickerForm( cfFormManager, referencedObj, null, new PageDataParentFormList(), new CallbackSecGroupFormFormChosen() );
			((ICFSecJavaFXSecFormPaneCommon)form).setPaneMode( CFPane.PaneMode.View );
			cfFormManager.pushForm( form );
		}

		public void view( ICFLibAnyObj value ) {
			final String S_ProcName = "actionPerformed";
			ICFSecSecGroupFormObj focus = getEffJavaFXFocus();
			if( focus != null ) {
				ICFSecSecFormObj referencedObj = (ICFSecSecFormObj)javafxReferenceParentForm.getReferencedObject();
				CFBorderPane form = null;
				if( referencedObj != null ) {
					String classCode = referencedObj.getClassCode();
					if( "a00b".equals( classCode ) ) {
						form = javafxSchema.getSecFormFactory().newAddForm( cfFormManager, referencedObj, null, true );
						ICFSecJavaFXSecFormPaneCommon spec = (ICFSecJavaFXSecFormPaneCommon)form;
						spec.setJavaFXFocus( referencedObj );
						spec.setPaneMode( CFPane.PaneMode.View );
					}
					else {
						throw new CFLibUnsupportedClassException( getClass(),
							S_ProcName,
							"javaFXFocus",
							focus,
							"ICFSecSecFormObj" );
					}
					cfFormManager.pushForm( form );
				}
			}
		}
	}

	protected class SecGroupFormFormCFReferenceEditor
		extends CFReferenceEditor
	{
		public SecGroupFormFormCFReferenceEditor() {
			super( new SecGroupFormFormReferenceCallback() );
			setFieldName( "Form" );
		}
	}

	protected class SecGroupFormIdCFLabel
		extends CFLabel
	{
		public SecGroupFormIdCFLabel() {
			super();
			setText( "Security Group Form Id" );
		}
	}

	protected class SecGroupFormIdEditor
		extends CFInt64Editor
	{
		public SecGroupFormIdEditor() {
			super();
			setMinValue( CFSecSecGroupFormBuff.SECGROUPFORMID_MIN_VALUE );
			setFieldName( "Security Group Form Id" );
		}
	}

	protected ICFSecSecAppObj javafxParentAppObj = null;
	protected SecGroupFormAppCFLabel javafxLabelParentApp = null;
	protected SecGroupFormAppCFReferenceEditor javafxReferenceParentApp = null;
	protected ICFSecSecFormObj javafxParentFormObj = null;
	protected SecGroupFormFormCFLabel javafxLabelParentForm = null;
	protected SecGroupFormFormCFReferenceEditor javafxReferenceParentForm = null;
	protected SecGroupFormIdCFLabel javafxLabelSecGroupFormId = null;
	protected SecGroupFormIdEditor javafxEditorSecGroupFormId = null;

	public CFSecJavaFXSecGroupFormAttrPane( ICFFormManager formManager, ICFSecJavaFXSchema argSchema, ICFSecSecGroupFormObj argFocus ) {
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
		setJavaFXFocusAsSecGroupForm( argFocus );
		setPadding( new Insets(5) );
		setHgap( 5 );
		setVgap( 5 );
		setAlignment( Pos.CENTER );
		ColumnConstraints column1 = new ColumnConstraints();
		column1.setPercentWidth( 100 );
		getColumnConstraints().addAll( column1 );
		int gridRow = 0;
		label = getJavaFXLabelParentApp();
		setHalignment( label, HPos.LEFT );
		setValignment( label, VPos.BOTTOM );
		add( label, 0, gridRow );
		gridRow ++;

		reference = getJavaFXReferenceParentApp();
		setHalignment( reference, HPos.LEFT );
		add( reference, 0, gridRow );
		gridRow ++;

		label = getJavaFXLabelParentForm();
		setHalignment( label, HPos.LEFT );
		setValignment( label, VPos.BOTTOM );
		add( label, 0, gridRow );
		gridRow ++;

		reference = getJavaFXReferenceParentForm();
		setHalignment( reference, HPos.LEFT );
		add( reference, 0, gridRow );
		gridRow ++;

		label = getJavaFXLabelSecGroupFormId();
		setHalignment( label, HPos.LEFT );
		setValignment( label, VPos.BOTTOM );
		add( label, 0, gridRow );
		gridRow ++;

		ctrl = getJavaFXEditorSecGroupFormId();
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
		if( ( value == null ) || ( value instanceof ICFSecSecGroupFormObj ) ) {
			super.setJavaFXFocus( value );
		}
		else {
			throw new CFLibUnsupportedClassException( getClass(),
				S_ProcName,
				"value",
				value,
				"ICFSecSecGroupFormObj" );
		}
		populateFields();
		adjustComponentEnableStates();
	}

	public ICFSecSecGroupFormObj getJavaFXFocusAsSecGroupForm() {
		return( (ICFSecSecGroupFormObj)getJavaFXFocus() );
	}

	public void setJavaFXFocusAsSecGroupForm( ICFSecSecGroupFormObj value ) {
		setJavaFXFocus( value );
	}

	public ICFSecSecGroupFormObj getEffJavaFXFocus() {
		ICFSecSecGroupFormObj eff = (ICFSecSecGroupFormObj)getJavaFXFocus();
		if( eff != null ) {
			if( null != eff.getEdit() ) {
				eff = (ICFSecSecGroupFormObj)eff.getEdit();
			}
		}
		return( eff );
	}

	public ICFSecSecAppObj getJavaFXParentAppObj() {
		return( javafxParentAppObj );
	}

	public void setJavaFXParentAppObj( ICFSecSecAppObj value ) {
		javafxParentAppObj = value;
	}

	public CFLabel getJavaFXLabelParentApp() {
		if( javafxLabelParentApp == null ) {
			javafxLabelParentApp = new SecGroupFormAppCFLabel();
		}
		return( javafxLabelParentApp );
	}

	public CFReferenceEditor getJavaFXReferenceParentApp() {
		if( javafxReferenceParentApp == null ) {
			javafxReferenceParentApp = new SecGroupFormAppCFReferenceEditor();
		}
		return( javafxReferenceParentApp );
	}

	public void setJavaFXReferenceParentApp( SecGroupFormAppCFReferenceEditor value ) {
		javafxReferenceParentApp = value;
	}

	public ICFSecSecFormObj getJavaFXParentFormObj() {
		return( javafxParentFormObj );
	}

	public void setJavaFXParentFormObj( ICFSecSecFormObj value ) {
		javafxParentFormObj = value;
	}

	public CFLabel getJavaFXLabelParentForm() {
		if( javafxLabelParentForm == null ) {
			javafxLabelParentForm = new SecGroupFormFormCFLabel();
		}
		return( javafxLabelParentForm );
	}

	public CFReferenceEditor getJavaFXReferenceParentForm() {
		if( javafxReferenceParentForm == null ) {
			javafxReferenceParentForm = new SecGroupFormFormCFReferenceEditor();
		}
		return( javafxReferenceParentForm );
	}

	public void setJavaFXReferenceParentForm( SecGroupFormFormCFReferenceEditor value ) {
		javafxReferenceParentForm = value;
	}

	public SecGroupFormIdCFLabel getJavaFXLabelSecGroupFormId() {
		if( javafxLabelSecGroupFormId == null ) {
			javafxLabelSecGroupFormId = new SecGroupFormIdCFLabel();
		}
		return( javafxLabelSecGroupFormId );
	}

	public void setJavaFXLabelSecGroupFormId( SecGroupFormIdCFLabel value ) {
		javafxLabelSecGroupFormId = value;
	}

	public SecGroupFormIdEditor getJavaFXEditorSecGroupFormId() {
		if( javafxEditorSecGroupFormId == null ) {
			javafxEditorSecGroupFormId = new SecGroupFormIdEditor();
		}
		return( javafxEditorSecGroupFormId );
	}

	public void setJavaFXEditorSecGroupFormId( SecGroupFormIdEditor value ) {
		javafxEditorSecGroupFormId = value;
	}

	public void populateFields()
	{
		ICFSecSecGroupFormObj popObj = getEffJavaFXFocus();
		if( getPaneMode() == CFPane.PaneMode.Unknown ) {
			popObj = null;
		}
		if( popObj == null ) {
			javafxParentAppObj = null;
		}
		else {
			javafxParentAppObj = (ICFSecSecAppObj)popObj.getRequiredParentApp( javafxIsInitializing );
		}
		if( javafxReferenceParentApp != null ) {
			javafxReferenceParentApp.setReferencedObject( javafxParentAppObj );
		}

		if( popObj == null ) {
			javafxParentFormObj = null;
		}
		else {
			javafxParentFormObj = (ICFSecSecFormObj)popObj.getRequiredParentForm( javafxIsInitializing );
		}
		if( javafxReferenceParentForm != null ) {
			javafxReferenceParentForm.setReferencedObject( javafxParentFormObj );
		}

		if( popObj == null ) {
			getJavaFXEditorSecGroupFormId().setInt64Value( null );
		}
		else {
			getJavaFXEditorSecGroupFormId().setInt64Value( popObj.getRequiredSecGroupFormId() );
		}
	}

	public void postFields()
	{
		final String S_ProcName = "postFields";
		ICFSecSecGroupFormObj focus = getJavaFXFocusAsSecGroupForm();
		ICFSecSecGroupFormEditObj editObj;
		if( focus != null ) {
			editObj = (ICFSecSecGroupFormEditObj)(focus.getEdit());
		}
		else {
			editObj = null;
		}
		if( editObj == null ) {
			throw new CFLibUsageException( getClass(),
				S_ProcName,
				"Pane is unfocused or is not editing the focus object" );
		}

		javafxParentAppObj = (ICFSecSecAppObj)( javafxReferenceParentApp.getReferencedObject() );
		editObj.setRequiredParentApp( javafxParentAppObj );

		javafxParentFormObj = (ICFSecSecFormObj)( javafxReferenceParentForm.getReferencedObject() );
		editObj.setRequiredParentForm( javafxParentFormObj );
	}

	public void setPaneMode( CFPane.PaneMode value ) {
		final String S_ProcName = "setPaneMode";
		CFPane.PaneMode oldValue = getPaneMode();
		if( oldValue == value ) {
			return;
		}
		ICFSecSecGroupFormObj focus = getJavaFXFocusAsSecGroupForm();
		if( ( value != CFPane.PaneMode.Unknown ) && ( value != CFPane.PaneMode.View ) ) {
			if( focus == null ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"javaFXFocus" );
			}
		}
		ICFSecSecGroupFormEditObj editObj;
		if( focus != null ) {
			editObj  = (ICFSecSecGroupFormEditObj)focus.getEdit();
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
								editObj = (ICFSecSecGroupFormEditObj)focus.beginEdit();
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
							editObj = (ICFSecSecGroupFormEditObj)focus.beginEdit();
							if( editObj == null ) {
								throw new CFLibUsageException( getClass(),
									S_ProcName,
									"Expected beginEdit() to return a new edition of the focus object" );
							}
						}
						break;
					case View:
						if( editObj == null ) {
							editObj = (ICFSecSecGroupFormEditObj)focus.beginEdit();
							if( editObj == null ) {
								throw new CFLibUsageException( getClass(),
									S_ProcName,
									"Expected beginEdit() to return a new edition of the focus object" );
							}
						}
						break;
					case Edit:
						if( editObj == null ) {
							editObj = (ICFSecSecGroupFormEditObj)focus.beginEdit();
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
						focus = (ICFSecSecGroupFormObj)editObj.create();
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
								editObj = (ICFSecSecGroupFormEditObj)focus.beginEdit();
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
								editObj = (ICFSecSecGroupFormEditObj)focus.beginEdit();
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
							editObj = (ICFSecSecGroupFormEditObj)focus.beginEdit();
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
			ICFSecSecGroupFormObj focus = getJavaFXFocusAsSecGroupForm();
			if( focus == null ) {
				isEditing = false;
			}
			else if( null == focus.getEdit() ) {
				isEditing = false;
			}
		}
		if( javafxReferenceParentApp != null ) {
			javafxReferenceParentApp.setCustomDisable( ! isEditing );
		}
		if( javafxReferenceParentForm != null ) {
			javafxReferenceParentForm.setCustomDisable( ! isEditing );
		}
		if( javafxEditorSecGroupFormId != null ) {
			javafxEditorSecGroupFormId.setDisable( true );
		}
	}
}
