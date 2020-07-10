// Description: Java 11 JavaFX Attribute Pane implementation for SecSession.

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
 *	CFSecJavaFXSecSessionAttrPane JavaFX Attribute Pane implementation
 *	for SecSession.
 */
public class CFSecJavaFXSecSessionAttrPane
extends CFGridPane
implements ICFSecJavaFXSecSessionPaneCommon
{
	protected ICFFormManager cfFormManager = null;
	protected ICFSecJavaFXSchema javafxSchema = null;
	boolean javafxIsInitializing = true;

	protected class SecSessionProxyCFLabel
		extends CFLabel
	{
		public SecSessionProxyCFLabel() {
			super();
			setText( "Security Proxy User" );
		}
	}

	protected class CallbackSecSessionProxyChosen
	implements ICFSecJavaFXSecUserChosen
	{
		public CallbackSecSessionProxyChosen() {
		}

		public void choseSecUser( ICFSecSecUserObj value ) {
			if( javafxReferenceParentSecProxy != null ) {
				ICFSecSecSessionObj cur = getJavaFXFocusAsSecSession();
				if( cur != null ) {
					ICFSecSecSessionEditObj editObj = (ICFSecSecSessionEditObj)cur.getEdit();
					if( null != editObj ) {
						CFPane.PaneMode curMode = getPaneMode();
						if( ( curMode == CFPane.PaneMode.Add ) || ( curMode == CFPane.PaneMode.Edit ) ) {
							javafxReferenceParentSecProxy.setReferencedObject( value );
							editObj.setRequiredParentSecProxy( value );
						}
					}
				}
			}
		}
	}

	protected class PageDataParentSecProxyList
	implements ICFSecJavaFXSecUserPageCallback
	{
		public PageDataParentSecProxyList() {
		}

		public List<ICFSecSecUserObj> pageData( UUID priorSecUserId )
		{
			java.util.List<ICFSecSecUserObj> listOfSecUser = null;
			ICFSecSecSessionObj focus = (ICFSecSecSessionObj)getEffJavaFXFocus();
			if( focus != null ) {
				ICFSecSchemaObj schemaObj = (ICFSecSchemaObj)javafxSchema.getSchema();
			listOfSecUser = schemaObj.getSecUserTableObj().pageAllSecUser( priorSecUserId );
			}
			else {
				listOfSecUser = new ArrayList<ICFSecSecUserObj>();
			}
			return( listOfSecUser  );
		}
	}

	protected class SecSessionProxyReferenceCallback
	implements ICFReferenceCallback
	{
		public void chose( ICFLibAnyObj value ) {
			final String S_ProcName = "chose";
			Node cont;
			ICFSecSchemaObj schemaObj = (ICFSecSchemaObj)javafxSchema.getSchema();
			ICFSecSecSessionObj focus = getEffJavaFXFocus();
			ICFSecSecUserObj referencedObj = (ICFSecSecUserObj)javafxReferenceParentSecProxy.getReferencedObject();
			CFBorderPane form = javafxSchema.getSecUserFactory().newPickerForm( cfFormManager, referencedObj, null, new PageDataParentSecProxyList(), new CallbackSecSessionProxyChosen() );
			((ICFSecJavaFXSecUserPaneCommon)form).setPaneMode( CFPane.PaneMode.View );
			cfFormManager.pushForm( form );
		}

		public void view( ICFLibAnyObj value ) {
			final String S_ProcName = "actionPerformed";
			ICFSecSecSessionObj focus = getEffJavaFXFocus();
			if( focus != null ) {
				ICFSecSecUserObj referencedObj = (ICFSecSecUserObj)javafxReferenceParentSecProxy.getReferencedObject();
				CFBorderPane form = null;
				if( referencedObj != null ) {
					String classCode = referencedObj.getClassCode();
					if( "a011".equals( classCode ) ) {
						form = javafxSchema.getSecUserFactory().newAddForm( cfFormManager, referencedObj, null, true );
						ICFSecJavaFXSecUserPaneCommon spec = (ICFSecJavaFXSecUserPaneCommon)form;
						spec.setJavaFXFocus( referencedObj );
						spec.setPaneMode( CFPane.PaneMode.View );
					}
					else {
						throw new CFLibUnsupportedClassException( getClass(),
							S_ProcName,
							"javaFXFocus",
							focus,
							"ICFSecSecUserObj" );
					}
					cfFormManager.pushForm( form );
				}
			}
		}
	}

	protected class SecSessionProxyCFReferenceEditor
		extends CFReferenceEditor
	{
		public SecSessionProxyCFReferenceEditor() {
			super( new SecSessionProxyReferenceCallback() );
			setFieldName( "Security Proxy User" );
		}
	}

	protected class SecSessionIdCFLabel
		extends CFLabel
	{
		public SecSessionIdCFLabel() {
			super();
			setText( "Security Session Id" );
		}
	}

	protected class SecSessionIdEditor
		extends CFUuidEditor
	{
		public SecSessionIdEditor() {
			super();
			setFieldName( "Security Session Id" );
		}
	}

	protected class SecDevNameCFLabel
		extends CFLabel
	{
		public SecDevNameCFLabel() {
			super();
			setText( "Sesion Device Name" );
		}
	}

	protected class SecDevNameEditor
		extends CFStringEditor
	{
		public SecDevNameEditor() {
			super();
			setMaxLen( 127 );
			setFieldName( "Sesion Device Name" );
		}
	}

	protected class StartCFLabel
		extends CFLabel
	{
		public StartCFLabel() {
			super();
			setText( "Start" );
		}
	}

	protected class StartEditor
		extends CFTimestampEditor
	{
		public StartEditor() {
			super();
			setFieldName( "Start" );
		}
	}

	protected class FinishCFLabel
		extends CFLabel
	{
		public FinishCFLabel() {
			super();
			setText( "Finish" );
		}
	}

	protected class FinishEditor
		extends CFTimestampEditor
	{
		public FinishEditor() {
			super();
			setFieldName( "Finish" );
		}
	}

	protected ICFSecSecUserObj javafxParentSecProxyObj = null;
	protected SecSessionProxyCFLabel javafxLabelParentSecProxy = null;
	protected SecSessionProxyCFReferenceEditor javafxReferenceParentSecProxy = null;
	protected SecSessionIdCFLabel javafxLabelSecSessionId = null;
	protected SecSessionIdEditor javafxEditorSecSessionId = null;
	protected SecDevNameCFLabel javafxLabelSecDevName = null;
	protected SecDevNameEditor javafxEditorSecDevName = null;
	protected StartCFLabel javafxLabelStart = null;
	protected StartEditor javafxEditorStart = null;
	protected FinishCFLabel javafxLabelFinish = null;
	protected FinishEditor javafxEditorFinish = null;

	public CFSecJavaFXSecSessionAttrPane( ICFFormManager formManager, ICFSecJavaFXSchema argSchema, ICFSecSecSessionObj argFocus ) {
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
		setJavaFXFocusAsSecSession( argFocus );
		setPadding( new Insets(5) );
		setHgap( 5 );
		setVgap( 5 );
		setAlignment( Pos.CENTER );
		ColumnConstraints column1 = new ColumnConstraints();
		column1.setPercentWidth( 100 );
		getColumnConstraints().addAll( column1 );
		int gridRow = 0;
		label = getJavaFXLabelParentSecProxy();
		setHalignment( label, HPos.LEFT );
		setValignment( label, VPos.BOTTOM );
		add( label, 0, gridRow );
		gridRow ++;

		reference = getJavaFXReferenceParentSecProxy();
		setHalignment( reference, HPos.LEFT );
		add( reference, 0, gridRow );
		gridRow ++;

		label = getJavaFXLabelSecSessionId();
		setHalignment( label, HPos.LEFT );
		setValignment( label, VPos.BOTTOM );
		add( label, 0, gridRow );
		gridRow ++;

		ctrl = getJavaFXEditorSecSessionId();
		setHalignment( ctrl, HPos.LEFT );
		add( ctrl, 0, gridRow );
		gridRow ++;

		label = getJavaFXLabelSecDevName();
		setHalignment( label, HPos.LEFT );
		setValignment( label, VPos.BOTTOM );
		add( label, 0, gridRow );
		gridRow ++;

		ctrl = getJavaFXEditorSecDevName();
		setHalignment( ctrl, HPos.LEFT );
		add( ctrl, 0, gridRow );
		gridRow ++;

		label = getJavaFXLabelStart();
		setHalignment( label, HPos.LEFT );
		setValignment( label, VPos.BOTTOM );
		add( label, 0, gridRow );
		gridRow ++;

		ctrl = getJavaFXEditorStart();
		setHalignment( ctrl, HPos.LEFT );
		add( ctrl, 0, gridRow );
		gridRow ++;

		label = getJavaFXLabelFinish();
		setHalignment( label, HPos.LEFT );
		setValignment( label, VPos.BOTTOM );
		add( label, 0, gridRow );
		gridRow ++;

		ctrl = getJavaFXEditorFinish();
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
		if( ( value == null ) || ( value instanceof ICFSecSecSessionObj ) ) {
			super.setJavaFXFocus( value );
		}
		else {
			throw new CFLibUnsupportedClassException( getClass(),
				S_ProcName,
				"value",
				value,
				"ICFSecSecSessionObj" );
		}
		populateFields();
		adjustComponentEnableStates();
	}

	public ICFSecSecSessionObj getJavaFXFocusAsSecSession() {
		return( (ICFSecSecSessionObj)getJavaFXFocus() );
	}

	public void setJavaFXFocusAsSecSession( ICFSecSecSessionObj value ) {
		setJavaFXFocus( value );
	}

	public ICFSecSecSessionObj getEffJavaFXFocus() {
		ICFSecSecSessionObj eff = (ICFSecSecSessionObj)getJavaFXFocus();
		if( eff != null ) {
			if( null != eff.getEdit() ) {
				eff = (ICFSecSecSessionObj)eff.getEdit();
			}
		}
		return( eff );
	}

	public ICFSecSecUserObj getJavaFXParentSecProxyObj() {
		return( javafxParentSecProxyObj );
	}

	public void setJavaFXParentSecProxyObj( ICFSecSecUserObj value ) {
		javafxParentSecProxyObj = value;
	}

	public CFLabel getJavaFXLabelParentSecProxy() {
		if( javafxLabelParentSecProxy == null ) {
			javafxLabelParentSecProxy = new SecSessionProxyCFLabel();
		}
		return( javafxLabelParentSecProxy );
	}

	public CFReferenceEditor getJavaFXReferenceParentSecProxy() {
		if( javafxReferenceParentSecProxy == null ) {
			javafxReferenceParentSecProxy = new SecSessionProxyCFReferenceEditor();
		}
		return( javafxReferenceParentSecProxy );
	}

	public void setJavaFXReferenceParentSecProxy( SecSessionProxyCFReferenceEditor value ) {
		javafxReferenceParentSecProxy = value;
	}

	public SecSessionIdCFLabel getJavaFXLabelSecSessionId() {
		if( javafxLabelSecSessionId == null ) {
			javafxLabelSecSessionId = new SecSessionIdCFLabel();
		}
		return( javafxLabelSecSessionId );
	}

	public void setJavaFXLabelSecSessionId( SecSessionIdCFLabel value ) {
		javafxLabelSecSessionId = value;
	}

	public SecSessionIdEditor getJavaFXEditorSecSessionId() {
		if( javafxEditorSecSessionId == null ) {
			javafxEditorSecSessionId = new SecSessionIdEditor();
		}
		return( javafxEditorSecSessionId );
	}

	public void setJavaFXEditorSecSessionId( SecSessionIdEditor value ) {
		javafxEditorSecSessionId = value;
	}

	public SecDevNameCFLabel getJavaFXLabelSecDevName() {
		if( javafxLabelSecDevName == null ) {
			javafxLabelSecDevName = new SecDevNameCFLabel();
		}
		return( javafxLabelSecDevName );
	}

	public void setJavaFXLabelSecDevName( SecDevNameCFLabel value ) {
		javafxLabelSecDevName = value;
	}

	public SecDevNameEditor getJavaFXEditorSecDevName() {
		if( javafxEditorSecDevName == null ) {
			javafxEditorSecDevName = new SecDevNameEditor();
		}
		return( javafxEditorSecDevName );
	}

	public void setJavaFXEditorSecDevName( SecDevNameEditor value ) {
		javafxEditorSecDevName = value;
	}

	public StartCFLabel getJavaFXLabelStart() {
		if( javafxLabelStart == null ) {
			javafxLabelStart = new StartCFLabel();
		}
		return( javafxLabelStart );
	}

	public void setJavaFXLabelStart( StartCFLabel value ) {
		javafxLabelStart = value;
	}

	public StartEditor getJavaFXEditorStart() {
		if( javafxEditorStart == null ) {
			javafxEditorStart = new StartEditor();
		}
		return( javafxEditorStart );
	}

	public void setJavaFXEditorStart( StartEditor value ) {
		javafxEditorStart = value;
	}

	public FinishCFLabel getJavaFXLabelFinish() {
		if( javafxLabelFinish == null ) {
			javafxLabelFinish = new FinishCFLabel();
		}
		return( javafxLabelFinish );
	}

	public void setJavaFXLabelFinish( FinishCFLabel value ) {
		javafxLabelFinish = value;
	}

	public FinishEditor getJavaFXEditorFinish() {
		if( javafxEditorFinish == null ) {
			javafxEditorFinish = new FinishEditor();
		}
		return( javafxEditorFinish );
	}

	public void setJavaFXEditorFinish( FinishEditor value ) {
		javafxEditorFinish = value;
	}

	public void populateFields()
	{
		ICFSecSecSessionObj popObj = getEffJavaFXFocus();
		if( getPaneMode() == CFPane.PaneMode.Unknown ) {
			popObj = null;
		}
		if( popObj == null ) {
			javafxParentSecProxyObj = null;
		}
		else {
			javafxParentSecProxyObj = (ICFSecSecUserObj)popObj.getRequiredParentSecProxy( javafxIsInitializing );
		}
		if( javafxReferenceParentSecProxy != null ) {
			javafxReferenceParentSecProxy.setReferencedObject( javafxParentSecProxyObj );
		}

		if( popObj == null ) {
			getJavaFXEditorSecSessionId().setUuidValue( null );
		}
		else {
			getJavaFXEditorSecSessionId().setUuidValue( popObj.getRequiredSecSessionId() );
		}

		if( popObj == null ) {
			getJavaFXEditorSecDevName().setStringValue( null );
		}
		else {
			getJavaFXEditorSecDevName().setStringValue( popObj.getOptionalSecDevName() );
		}

		if( popObj == null ) {
			getJavaFXEditorStart().setTimestampValue( null );
		}
		else {
			getJavaFXEditorStart().setTimestampValue( popObj.getRequiredStart() );
		}

		if( popObj == null ) {
			getJavaFXEditorFinish().setTimestampValue( null );
		}
		else {
			getJavaFXEditorFinish().setTimestampValue( popObj.getOptionalFinish() );
		}
	}

	public void postFields()
	{
		final String S_ProcName = "postFields";
		ICFSecSecSessionObj focus = getJavaFXFocusAsSecSession();
		ICFSecSecSessionEditObj editObj;
		if( focus != null ) {
			editObj = (ICFSecSecSessionEditObj)(focus.getEdit());
		}
		else {
			editObj = null;
		}
		if( editObj == null ) {
			throw new CFLibUsageException( getClass(),
				S_ProcName,
				"Pane is unfocused or is not editing the focus object" );
		}

		javafxParentSecProxyObj = (ICFSecSecUserObj)( javafxReferenceParentSecProxy.getReferencedObject() );
		editObj.setRequiredParentSecProxy( javafxParentSecProxyObj );

		if( ( getJavaFXEditorSecDevName().getStringValue() != null ) && ( getJavaFXEditorSecDevName().getStringValue().length() <= 0 ) ) {
			editObj.setOptionalSecDevName( null );
		}
		else {
			editObj.setOptionalSecDevName( getJavaFXEditorSecDevName().getStringValue() );
		}

		editObj.setRequiredStart( getJavaFXEditorStart().getTimestampValue() );

		editObj.setOptionalFinish( getJavaFXEditorFinish().getTimestampValue() );
	}

	public void setPaneMode( CFPane.PaneMode value ) {
		final String S_ProcName = "setPaneMode";
		CFPane.PaneMode oldValue = getPaneMode();
		if( oldValue == value ) {
			return;
		}
		ICFSecSecSessionObj focus = getJavaFXFocusAsSecSession();
		if( ( value != CFPane.PaneMode.Unknown ) && ( value != CFPane.PaneMode.View ) ) {
			if( focus == null ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"javaFXFocus" );
			}
		}
		ICFSecSecSessionEditObj editObj;
		if( focus != null ) {
			editObj  = (ICFSecSecSessionEditObj)focus.getEdit();
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
								editObj = (ICFSecSecSessionEditObj)focus.beginEdit();
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
							editObj = (ICFSecSecSessionEditObj)focus.beginEdit();
							if( editObj == null ) {
								throw new CFLibUsageException( getClass(),
									S_ProcName,
									"Expected beginEdit() to return a new edition of the focus object" );
							}
						}
						break;
					case View:
						if( editObj == null ) {
							editObj = (ICFSecSecSessionEditObj)focus.beginEdit();
							if( editObj == null ) {
								throw new CFLibUsageException( getClass(),
									S_ProcName,
									"Expected beginEdit() to return a new edition of the focus object" );
							}
						}
						break;
					case Edit:
						if( editObj == null ) {
							editObj = (ICFSecSecSessionEditObj)focus.beginEdit();
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
						focus = (ICFSecSecSessionObj)editObj.create();
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
								editObj = (ICFSecSecSessionEditObj)focus.beginEdit();
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
								editObj = (ICFSecSecSessionEditObj)focus.beginEdit();
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
							editObj = (ICFSecSecSessionEditObj)focus.beginEdit();
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
			ICFSecSecSessionObj focus = getJavaFXFocusAsSecSession();
			if( focus == null ) {
				isEditing = false;
			}
			else if( null == focus.getEdit() ) {
				isEditing = false;
			}
		}
		if( javafxReferenceParentSecProxy != null ) {
			javafxReferenceParentSecProxy.setCustomDisable( ! isEditing );
		}
		if( javafxEditorSecSessionId != null ) {
			javafxEditorSecSessionId.setDisable( true );
		}
		if( javafxEditorSecDevName != null ) {
			javafxEditorSecDevName.setDisable( ! isEditing );
		}
		if( javafxEditorStart != null ) {
			javafxEditorStart.setDisable( ! isEditing );
		}
		if( javafxEditorFinish != null ) {
			javafxEditorFinish.setDisable( ! isEditing );
		}
	}
}
