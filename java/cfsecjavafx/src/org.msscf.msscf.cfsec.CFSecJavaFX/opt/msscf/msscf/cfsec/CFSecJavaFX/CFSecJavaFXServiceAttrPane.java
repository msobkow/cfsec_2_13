// Description: Java 11 JavaFX Attribute Pane implementation for Service.

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
 *	CFSecJavaFXServiceAttrPane JavaFX Attribute Pane implementation
 *	for Service.
 */
public class CFSecJavaFXServiceAttrPane
extends CFGridPane
implements ICFSecJavaFXServicePaneCommon
{
	protected ICFFormManager cfFormManager = null;
	protected ICFSecJavaFXSchema javafxSchema = null;
	boolean javafxIsInitializing = true;

	protected class ServiceSvcTypeCFLabel
		extends CFLabel
	{
		public ServiceSvcTypeCFLabel() {
			super();
			setText( "Service Type" );
		}
	}

	protected class CallbackServiceSvcTypeChosen
	implements ICFSecJavaFXServiceTypeChosen
	{
		public CallbackServiceSvcTypeChosen() {
		}

		public void choseServiceType( ICFSecServiceTypeObj value ) {
			if( javafxReferenceParentServiceType != null ) {
				ICFSecServiceObj cur = getJavaFXFocusAsService();
				if( cur != null ) {
					ICFSecServiceEditObj editObj = (ICFSecServiceEditObj)cur.getEdit();
					if( null != editObj ) {
						CFPane.PaneMode curMode = getPaneMode();
						if( ( curMode == CFPane.PaneMode.Add ) || ( curMode == CFPane.PaneMode.Edit ) ) {
							javafxReferenceParentServiceType.setReferencedObject( value );
							editObj.setOptionalParentServiceType( value );
						}
					}
				}
			}
		}
	}

	protected class ServiceSvcTypeReferenceCallback
	implements ICFReferenceCallback
	{
		public void chose( ICFLibAnyObj value ) {
			final String S_ProcName = "chose";
			Node cont;
			ICFSecSchemaObj schemaObj = (ICFSecSchemaObj)javafxSchema.getSchema();
			ICFSecServiceObj focus = getEffJavaFXFocus();
			ICFSecServiceTypeObj referencedObj = (ICFSecServiceTypeObj)javafxReferenceParentServiceType.getReferencedObject();
			java.util.List<ICFSecServiceTypeObj> listOfServiceType = null;
			listOfServiceType = schemaObj.getServiceTypeTableObj().readAllServiceType();
			if( listOfServiceType == null ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"listOfServiceType" );
			}
			Collection<ICFSecServiceTypeObj> cltn = listOfServiceType;
			CFBorderPane form = javafxSchema.getServiceTypeFactory().newPickerForm( cfFormManager, referencedObj, null, cltn, new CallbackServiceSvcTypeChosen() );
			((ICFSecJavaFXServiceTypePaneCommon)form).setPaneMode( CFPane.PaneMode.View );
			cfFormManager.pushForm( form );
		}

		public void view( ICFLibAnyObj value ) {
			final String S_ProcName = "actionPerformed";
			ICFSecServiceObj focus = getEffJavaFXFocus();
			if( focus != null ) {
				ICFSecServiceTypeObj referencedObj = (ICFSecServiceTypeObj)javafxReferenceParentServiceType.getReferencedObject();
				CFBorderPane form = null;
				if( referencedObj != null ) {
					String classCode = referencedObj.getClassCode();
					if( "a013".equals( classCode ) ) {
						form = javafxSchema.getServiceTypeFactory().newAddForm( cfFormManager, referencedObj, null, true );
						ICFSecJavaFXServiceTypePaneCommon spec = (ICFSecJavaFXServiceTypePaneCommon)form;
						spec.setJavaFXFocus( referencedObj );
						spec.setPaneMode( CFPane.PaneMode.View );
					}
					else {
						throw new CFLibUnsupportedClassException( getClass(),
							S_ProcName,
							"javaFXFocus",
							focus,
							"ICFSecServiceTypeObj" );
					}
					cfFormManager.pushForm( form );
				}
			}
		}
	}

	protected class ServiceSvcTypeCFReferenceEditor
		extends CFReferenceEditor
	{
		public ServiceSvcTypeCFReferenceEditor() {
			super( new ServiceSvcTypeReferenceCallback() );
			setFieldName( "Service Type" );
		}
	}

	protected class ServiceIdCFLabel
		extends CFLabel
	{
		public ServiceIdCFLabel() {
			super();
			setText( "Service Id" );
		}
	}

	protected class ServiceIdEditor
		extends CFInt64Editor
	{
		public ServiceIdEditor() {
			super();
			setMinValue( CFSecServiceBuff.SERVICEID_MIN_VALUE );
			setFieldName( "Service Id" );
		}
	}

	protected class HostPortCFLabel
		extends CFLabel
	{
		public HostPortCFLabel() {
			super();
			setText( "Host Port" );
		}
	}

	protected class HostPortEditor
		extends CFInt16Editor
	{
		public HostPortEditor() {
			super();
			setMinValue( CFSecServiceBuff.HOSTPORT_MIN_VALUE );
			setFieldName( "Host Port" );
		}
	}

	protected ICFSecServiceTypeObj javafxParentServiceTypeObj = null;
	protected ServiceSvcTypeCFLabel javafxLabelParentServiceType = null;
	protected ServiceSvcTypeCFReferenceEditor javafxReferenceParentServiceType = null;
	protected ServiceIdCFLabel javafxLabelServiceId = null;
	protected ServiceIdEditor javafxEditorServiceId = null;
	protected HostPortCFLabel javafxLabelHostPort = null;
	protected HostPortEditor javafxEditorHostPort = null;

	public CFSecJavaFXServiceAttrPane( ICFFormManager formManager, ICFSecJavaFXSchema argSchema, ICFSecServiceObj argFocus ) {
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
		setJavaFXFocusAsService( argFocus );
		setPadding( new Insets(5) );
		setHgap( 5 );
		setVgap( 5 );
		setAlignment( Pos.CENTER );
		ColumnConstraints column1 = new ColumnConstraints();
		column1.setPercentWidth( 100 );
		getColumnConstraints().addAll( column1 );
		int gridRow = 0;
		label = getJavaFXLabelParentServiceType();
		setHalignment( label, HPos.LEFT );
		setValignment( label, VPos.BOTTOM );
		add( label, 0, gridRow );
		gridRow ++;

		reference = getJavaFXReferenceParentServiceType();
		setHalignment( reference, HPos.LEFT );
		add( reference, 0, gridRow );
		gridRow ++;

		label = getJavaFXLabelServiceId();
		setHalignment( label, HPos.LEFT );
		setValignment( label, VPos.BOTTOM );
		add( label, 0, gridRow );
		gridRow ++;

		ctrl = getJavaFXEditorServiceId();
		setHalignment( ctrl, HPos.LEFT );
		add( ctrl, 0, gridRow );
		gridRow ++;

		label = getJavaFXLabelHostPort();
		setHalignment( label, HPos.LEFT );
		setValignment( label, VPos.BOTTOM );
		add( label, 0, gridRow );
		gridRow ++;

		ctrl = getJavaFXEditorHostPort();
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
		if( ( value == null ) || ( value instanceof ICFSecServiceObj ) ) {
			super.setJavaFXFocus( value );
		}
		else {
			throw new CFLibUnsupportedClassException( getClass(),
				S_ProcName,
				"value",
				value,
				"ICFSecServiceObj" );
		}
		populateFields();
		adjustComponentEnableStates();
	}

	public ICFSecServiceObj getJavaFXFocusAsService() {
		return( (ICFSecServiceObj)getJavaFXFocus() );
	}

	public void setJavaFXFocusAsService( ICFSecServiceObj value ) {
		setJavaFXFocus( value );
	}

	public ICFSecServiceObj getEffJavaFXFocus() {
		ICFSecServiceObj eff = (ICFSecServiceObj)getJavaFXFocus();
		if( eff != null ) {
			if( null != eff.getEdit() ) {
				eff = (ICFSecServiceObj)eff.getEdit();
			}
		}
		return( eff );
	}

	public ICFSecServiceTypeObj getJavaFXParentServiceTypeObj() {
		return( javafxParentServiceTypeObj );
	}

	public void setJavaFXParentServiceTypeObj( ICFSecServiceTypeObj value ) {
		javafxParentServiceTypeObj = value;
	}

	public CFLabel getJavaFXLabelParentServiceType() {
		if( javafxLabelParentServiceType == null ) {
			javafxLabelParentServiceType = new ServiceSvcTypeCFLabel();
		}
		return( javafxLabelParentServiceType );
	}

	public CFReferenceEditor getJavaFXReferenceParentServiceType() {
		if( javafxReferenceParentServiceType == null ) {
			javafxReferenceParentServiceType = new ServiceSvcTypeCFReferenceEditor();
		}
		return( javafxReferenceParentServiceType );
	}

	public void setJavaFXReferenceParentServiceType( ServiceSvcTypeCFReferenceEditor value ) {
		javafxReferenceParentServiceType = value;
	}

	public ServiceIdCFLabel getJavaFXLabelServiceId() {
		if( javafxLabelServiceId == null ) {
			javafxLabelServiceId = new ServiceIdCFLabel();
		}
		return( javafxLabelServiceId );
	}

	public void setJavaFXLabelServiceId( ServiceIdCFLabel value ) {
		javafxLabelServiceId = value;
	}

	public ServiceIdEditor getJavaFXEditorServiceId() {
		if( javafxEditorServiceId == null ) {
			javafxEditorServiceId = new ServiceIdEditor();
		}
		return( javafxEditorServiceId );
	}

	public void setJavaFXEditorServiceId( ServiceIdEditor value ) {
		javafxEditorServiceId = value;
	}

	public HostPortCFLabel getJavaFXLabelHostPort() {
		if( javafxLabelHostPort == null ) {
			javafxLabelHostPort = new HostPortCFLabel();
		}
		return( javafxLabelHostPort );
	}

	public void setJavaFXLabelHostPort( HostPortCFLabel value ) {
		javafxLabelHostPort = value;
	}

	public HostPortEditor getJavaFXEditorHostPort() {
		if( javafxEditorHostPort == null ) {
			javafxEditorHostPort = new HostPortEditor();
		}
		return( javafxEditorHostPort );
	}

	public void setJavaFXEditorHostPort( HostPortEditor value ) {
		javafxEditorHostPort = value;
	}

	public void populateFields()
	{
		ICFSecServiceObj popObj = getEffJavaFXFocus();
		if( getPaneMode() == CFPane.PaneMode.Unknown ) {
			popObj = null;
		}
		if( popObj == null ) {
			javafxParentServiceTypeObj = null;
		}
		else {
			javafxParentServiceTypeObj = (ICFSecServiceTypeObj)popObj.getOptionalParentServiceType( javafxIsInitializing );
		}
		if( javafxReferenceParentServiceType != null ) {
			javafxReferenceParentServiceType.setReferencedObject( javafxParentServiceTypeObj );
		}

		if( popObj == null ) {
			getJavaFXEditorServiceId().setInt64Value( null );
		}
		else {
			getJavaFXEditorServiceId().setInt64Value( popObj.getRequiredServiceId() );
		}

		if( popObj == null ) {
			getJavaFXEditorHostPort().setInt16Value( null );
		}
		else {
			getJavaFXEditorHostPort().setInt16Value( popObj.getRequiredHostPort() );
		}
	}

	public void postFields()
	{
		final String S_ProcName = "postFields";
		ICFSecServiceObj focus = getJavaFXFocusAsService();
		ICFSecServiceEditObj editObj;
		if( focus != null ) {
			editObj = (ICFSecServiceEditObj)(focus.getEdit());
		}
		else {
			editObj = null;
		}
		if( editObj == null ) {
			throw new CFLibUsageException( getClass(),
				S_ProcName,
				"Pane is unfocused or is not editing the focus object" );
		}

		javafxParentServiceTypeObj = (ICFSecServiceTypeObj)( javafxReferenceParentServiceType.getReferencedObject() );
		editObj.setOptionalParentServiceType( javafxParentServiceTypeObj );

		editObj.setRequiredHostPort( getJavaFXEditorHostPort().getInt16Value() );
	}

	public void setPaneMode( CFPane.PaneMode value ) {
		final String S_ProcName = "setPaneMode";
		CFPane.PaneMode oldValue = getPaneMode();
		if( oldValue == value ) {
			return;
		}
		ICFSecServiceObj focus = getJavaFXFocusAsService();
		if( ( value != CFPane.PaneMode.Unknown ) && ( value != CFPane.PaneMode.View ) ) {
			if( focus == null ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"javaFXFocus" );
			}
		}
		ICFSecServiceEditObj editObj;
		if( focus != null ) {
			editObj  = (ICFSecServiceEditObj)focus.getEdit();
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
								editObj = (ICFSecServiceEditObj)focus.beginEdit();
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
							editObj = (ICFSecServiceEditObj)focus.beginEdit();
							if( editObj == null ) {
								throw new CFLibUsageException( getClass(),
									S_ProcName,
									"Expected beginEdit() to return a new edition of the focus object" );
							}
						}
						break;
					case View:
						if( editObj == null ) {
							editObj = (ICFSecServiceEditObj)focus.beginEdit();
							if( editObj == null ) {
								throw new CFLibUsageException( getClass(),
									S_ProcName,
									"Expected beginEdit() to return a new edition of the focus object" );
							}
						}
						break;
					case Edit:
						if( editObj == null ) {
							editObj = (ICFSecServiceEditObj)focus.beginEdit();
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
						focus = (ICFSecServiceObj)editObj.create();
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
								editObj = (ICFSecServiceEditObj)focus.beginEdit();
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
								editObj = (ICFSecServiceEditObj)focus.beginEdit();
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
							editObj = (ICFSecServiceEditObj)focus.beginEdit();
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
			ICFSecServiceObj focus = getJavaFXFocusAsService();
			if( focus == null ) {
				isEditing = false;
			}
			else if( null == focus.getEdit() ) {
				isEditing = false;
			}
		}
		if( javafxReferenceParentServiceType != null ) {
			javafxReferenceParentServiceType.setCustomDisable( ! isEditing );
		}
		if( javafxEditorServiceId != null ) {
			javafxEditorServiceId.setDisable( true );
		}
		if( javafxEditorHostPort != null ) {
			javafxEditorHostPort.setDisable( ! isEditing );
		}
	}
}
