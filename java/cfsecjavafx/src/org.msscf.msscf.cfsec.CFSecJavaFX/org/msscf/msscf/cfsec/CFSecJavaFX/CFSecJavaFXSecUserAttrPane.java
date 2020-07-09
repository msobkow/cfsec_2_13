// Description: Java 11 JavaFX Attribute Pane implementation for SecUser.

/*
 *	org.msscf.msscf.CFSec
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
import com.github.msobkow.cflib.CFLib.*;
import com.github.msobkow.cflib.CFLib.JavaFX.*;
import com.github.msobkow.cflib.CFLib.JavaFX.CFReferenceEditor.ICFReferenceCallback;
import org.apache.commons.codec.binary.Base64;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfsec.CFSecObj.*;

/**
 *	CFSecJavaFXSecUserAttrPane JavaFX Attribute Pane implementation
 *	for SecUser.
 */
public class CFSecJavaFXSecUserAttrPane
extends CFGridPane
implements ICFSecJavaFXSecUserPaneCommon
{
	protected ICFFormManager cfFormManager = null;
	protected ICFSecJavaFXSchema javafxSchema = null;
	boolean javafxIsInitializing = true;

	protected class SecUserDefDevCFLabel
		extends CFLabel
	{
		public SecUserDefDevCFLabel() {
			super();
			setText( "Default Security Device" );
		}
	}

	protected class CallbackSecUserDefDevChosen
	implements ICFSecJavaFXSecDeviceChosen
	{
		public CallbackSecUserDefDevChosen() {
		}

		public void choseSecDevice( ICFSecSecDeviceObj value ) {
			if( javafxReferenceLookupDefDev != null ) {
				ICFSecSecUserObj cur = getJavaFXFocusAsSecUser();
				if( cur != null ) {
					ICFSecSecUserEditObj editObj = (ICFSecSecUserEditObj)cur.getEdit();
					if( null != editObj ) {
						CFPane.PaneMode curMode = getPaneMode();
						if( ( curMode == CFPane.PaneMode.Add ) || ( curMode == CFPane.PaneMode.Edit ) ) {
							javafxReferenceLookupDefDev.setReferencedObject( value );
							editObj.setOptionalLookupDefDev( value );
						}
					}
				}
			}
		}
	}

	protected class PageDataLookupDefDevList
	implements ICFSecJavaFXSecDevicePageCallback
	{
		public PageDataLookupDefDevList() {
		}

		public List<ICFSecSecDeviceObj> pageData( UUID priorSecUserId,
		String priorDevName )
		{
			java.util.List<ICFSecSecDeviceObj> listOfSecDevice = null;
			ICFSecSecUserObj focus = (ICFSecSecUserObj)getEffJavaFXFocus();
			if( focus != null ) {
				ICFSecSchemaObj schemaObj = (ICFSecSchemaObj)javafxSchema.getSchema();
			Collection<ICFSecSecDeviceObj> cltn = null;
			}
			else {
				listOfSecDevice = new ArrayList<ICFSecSecDeviceObj>();
			}
			return( listOfSecDevice  );
		}
	}

	protected class SecUserDefDevReferenceCallback
	implements ICFReferenceCallback
	{
		public void chose( ICFLibAnyObj value ) {
			final String S_ProcName = "chose";
			Node cont;
			ICFSecSchemaObj schemaObj = (ICFSecSchemaObj)javafxSchema.getSchema();
			ICFSecSecUserObj focus = getEffJavaFXFocus();
			ICFSecSecDeviceObj referencedObj = (ICFSecSecDeviceObj)javafxReferenceLookupDefDev.getReferencedObject();
			CFBorderPane form = javafxSchema.getSecDeviceFactory().newPickerForm( cfFormManager, referencedObj, null, new PageDataLookupDefDevList(), new CallbackSecUserDefDevChosen() );
			((ICFSecJavaFXSecDevicePaneCommon)form).setPaneMode( CFPane.PaneMode.View );
			cfFormManager.pushForm( form );
		}

		public void view( ICFLibAnyObj value ) {
			final String S_ProcName = "actionPerformed";
			ICFSecSecUserObj focus = getEffJavaFXFocus();
			if( focus != null ) {
				ICFSecSecDeviceObj referencedObj = (ICFSecSecDeviceObj)javafxReferenceLookupDefDev.getReferencedObject();
				CFBorderPane form = null;
				if( referencedObj != null ) {
					String classCode = referencedObj.getClassCode();
					if( "a00a".equals( classCode ) ) {
						form = javafxSchema.getSecDeviceFactory().newAddForm( cfFormManager, referencedObj, null, true );
						ICFSecJavaFXSecDevicePaneCommon spec = (ICFSecJavaFXSecDevicePaneCommon)form;
						spec.setJavaFXFocus( referencedObj );
						spec.setPaneMode( CFPane.PaneMode.View );
					}
					else {
						throw new CFLibUnsupportedClassException( getClass(),
							S_ProcName,
							"javaFXFocus",
							focus,
							"ICFSecSecDeviceObj" );
					}
					cfFormManager.pushForm( form );
				}
			}
		}
	}

	protected class SecUserDefDevCFReferenceEditor
		extends CFReferenceEditor
	{
		public SecUserDefDevCFReferenceEditor() {
			super( new SecUserDefDevReferenceCallback() );
			setFieldName( "Default Security Device" );
		}
	}

	protected class SecUserIdCFLabel
		extends CFLabel
	{
		public SecUserIdCFLabel() {
			super();
			setText( "Security User Id" );
		}
	}

	protected class SecUserIdEditor
		extends CFUuidEditor
	{
		public SecUserIdEditor() {
			super();
			setFieldName( "Security User Id" );
		}
	}

	protected class LoginIdCFLabel
		extends CFLabel
	{
		public LoginIdCFLabel() {
			super();
			setText( "Login Id" );
		}
	}

	protected class LoginIdEditor
		extends CFStringEditor
	{
		public LoginIdEditor() {
			super();
			setMaxLen( 32 );
			setFieldName( "Login Id" );
		}
	}

	protected class EMailAddressCFLabel
		extends CFLabel
	{
		public EMailAddressCFLabel() {
			super();
			setText( "EMail Address" );
		}
	}

	protected class EMailAddressEditor
		extends CFStringEditor
	{
		public EMailAddressEditor() {
			super();
			setMaxLen( 192 );
			setFieldName( "EMail Address" );
		}
	}

	protected class EMailConfirmUuidCFLabel
		extends CFLabel
	{
		public EMailConfirmUuidCFLabel() {
			super();
			setText( "EMail Confirm UUID" );
		}
	}

	protected class EMailConfirmUuidEditor
		extends CFUuidEditor
	{
		public EMailConfirmUuidEditor() {
			super();
			setFieldName( "EMail Confirm UUID" );
		}
	}

	protected class PasswordHashCFLabel
		extends CFLabel
	{
		public PasswordHashCFLabel() {
			super();
			setText( "Password Hash" );
		}
	}

	protected class PasswordHashEditor
		extends CFStringEditor
	{
		public PasswordHashEditor() {
			super();
			setMaxLen( 256 );
			setFieldName( "Password Hash" );
		}
	}

	protected class PasswordResetUuidCFLabel
		extends CFLabel
	{
		public PasswordResetUuidCFLabel() {
			super();
			setText( "Password Reset UUID" );
		}
	}

	protected class PasswordResetUuidEditor
		extends CFUuidEditor
	{
		public PasswordResetUuidEditor() {
			super();
			setFieldName( "Password Reset UUID" );
		}
	}

	protected ICFSecSecDeviceObj javafxLookupDefDevObj = null;
	protected SecUserDefDevCFLabel javafxLabelLookupDefDev = null;
	protected SecUserDefDevCFReferenceEditor javafxReferenceLookupDefDev = null;
	protected SecUserIdCFLabel javafxLabelSecUserId = null;
	protected SecUserIdEditor javafxEditorSecUserId = null;
	protected LoginIdCFLabel javafxLabelLoginId = null;
	protected LoginIdEditor javafxEditorLoginId = null;
	protected EMailAddressCFLabel javafxLabelEMailAddress = null;
	protected EMailAddressEditor javafxEditorEMailAddress = null;
	protected EMailConfirmUuidCFLabel javafxLabelEMailConfirmUuid = null;
	protected EMailConfirmUuidEditor javafxEditorEMailConfirmUuid = null;
	protected PasswordHashCFLabel javafxLabelPasswordHash = null;
	protected PasswordHashEditor javafxEditorPasswordHash = null;
	protected PasswordResetUuidCFLabel javafxLabelPasswordResetUuid = null;
	protected PasswordResetUuidEditor javafxEditorPasswordResetUuid = null;

	public CFSecJavaFXSecUserAttrPane( ICFFormManager formManager, ICFSecJavaFXSchema argSchema, ICFSecSecUserObj argFocus ) {
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
		setJavaFXFocusAsSecUser( argFocus );
		setPadding( new Insets(5) );
		setHgap( 5 );
		setVgap( 5 );
		setAlignment( Pos.CENTER );
		ColumnConstraints column1 = new ColumnConstraints();
		column1.setPercentWidth( 100 );
		getColumnConstraints().addAll( column1 );
		int gridRow = 0;
		label = getJavaFXLabelLookupDefDev();
		setHalignment( label, HPos.LEFT );
		setValignment( label, VPos.BOTTOM );
		add( label, 0, gridRow );
		gridRow ++;

		reference = getJavaFXReferenceLookupDefDev();
		setHalignment( reference, HPos.LEFT );
		add( reference, 0, gridRow );
		gridRow ++;

		label = getJavaFXLabelSecUserId();
		setHalignment( label, HPos.LEFT );
		setValignment( label, VPos.BOTTOM );
		add( label, 0, gridRow );
		gridRow ++;

		ctrl = getJavaFXEditorSecUserId();
		setHalignment( ctrl, HPos.LEFT );
		add( ctrl, 0, gridRow );
		gridRow ++;

		label = getJavaFXLabelLoginId();
		setHalignment( label, HPos.LEFT );
		setValignment( label, VPos.BOTTOM );
		add( label, 0, gridRow );
		gridRow ++;

		ctrl = getJavaFXEditorLoginId();
		setHalignment( ctrl, HPos.LEFT );
		add( ctrl, 0, gridRow );
		gridRow ++;

		label = getJavaFXLabelEMailAddress();
		setHalignment( label, HPos.LEFT );
		setValignment( label, VPos.BOTTOM );
		add( label, 0, gridRow );
		gridRow ++;

		ctrl = getJavaFXEditorEMailAddress();
		setHalignment( ctrl, HPos.LEFT );
		add( ctrl, 0, gridRow );
		gridRow ++;

		label = getJavaFXLabelEMailConfirmUuid();
		setHalignment( label, HPos.LEFT );
		setValignment( label, VPos.BOTTOM );
		add( label, 0, gridRow );
		gridRow ++;

		ctrl = getJavaFXEditorEMailConfirmUuid();
		setHalignment( ctrl, HPos.LEFT );
		add( ctrl, 0, gridRow );
		gridRow ++;

		label = getJavaFXLabelPasswordHash();
		setHalignment( label, HPos.LEFT );
		setValignment( label, VPos.BOTTOM );
		add( label, 0, gridRow );
		gridRow ++;

		ctrl = getJavaFXEditorPasswordHash();
		setHalignment( ctrl, HPos.LEFT );
		add( ctrl, 0, gridRow );
		gridRow ++;

		label = getJavaFXLabelPasswordResetUuid();
		setHalignment( label, HPos.LEFT );
		setValignment( label, VPos.BOTTOM );
		add( label, 0, gridRow );
		gridRow ++;

		ctrl = getJavaFXEditorPasswordResetUuid();
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
		if( ( value == null ) || ( value instanceof ICFSecSecUserObj ) ) {
			super.setJavaFXFocus( value );
		}
		else {
			throw new CFLibUnsupportedClassException( getClass(),
				S_ProcName,
				"value",
				value,
				"ICFSecSecUserObj" );
		}
		populateFields();
		adjustComponentEnableStates();
	}

	public ICFSecSecUserObj getJavaFXFocusAsSecUser() {
		return( (ICFSecSecUserObj)getJavaFXFocus() );
	}

	public void setJavaFXFocusAsSecUser( ICFSecSecUserObj value ) {
		setJavaFXFocus( value );
	}

	public ICFSecSecUserObj getEffJavaFXFocus() {
		ICFSecSecUserObj eff = (ICFSecSecUserObj)getJavaFXFocus();
		if( eff != null ) {
			if( null != eff.getEdit() ) {
				eff = (ICFSecSecUserObj)eff.getEdit();
			}
		}
		return( eff );
	}

	public ICFSecSecDeviceObj getJavaFXLookupDefDevObj() {
		return( javafxLookupDefDevObj );
	}

	public void setJavaFXLookupDefDevObj( ICFSecSecDeviceObj value ) {
		javafxLookupDefDevObj = value;
	}

	public CFLabel getJavaFXLabelLookupDefDev() {
		if( javafxLabelLookupDefDev == null ) {
			javafxLabelLookupDefDev = new SecUserDefDevCFLabel();
		}
		return( javafxLabelLookupDefDev );
	}

	public CFReferenceEditor getJavaFXReferenceLookupDefDev() {
		if( javafxReferenceLookupDefDev == null ) {
			javafxReferenceLookupDefDev = new SecUserDefDevCFReferenceEditor();
		}
		return( javafxReferenceLookupDefDev );
	}

	public void setJavaFXReferenceLookupDefDev( SecUserDefDevCFReferenceEditor value ) {
		javafxReferenceLookupDefDev = value;
	}

	public SecUserIdCFLabel getJavaFXLabelSecUserId() {
		if( javafxLabelSecUserId == null ) {
			javafxLabelSecUserId = new SecUserIdCFLabel();
		}
		return( javafxLabelSecUserId );
	}

	public void setJavaFXLabelSecUserId( SecUserIdCFLabel value ) {
		javafxLabelSecUserId = value;
	}

	public SecUserIdEditor getJavaFXEditorSecUserId() {
		if( javafxEditorSecUserId == null ) {
			javafxEditorSecUserId = new SecUserIdEditor();
		}
		return( javafxEditorSecUserId );
	}

	public void setJavaFXEditorSecUserId( SecUserIdEditor value ) {
		javafxEditorSecUserId = value;
	}

	public LoginIdCFLabel getJavaFXLabelLoginId() {
		if( javafxLabelLoginId == null ) {
			javafxLabelLoginId = new LoginIdCFLabel();
		}
		return( javafxLabelLoginId );
	}

	public void setJavaFXLabelLoginId( LoginIdCFLabel value ) {
		javafxLabelLoginId = value;
	}

	public LoginIdEditor getJavaFXEditorLoginId() {
		if( javafxEditorLoginId == null ) {
			javafxEditorLoginId = new LoginIdEditor();
		}
		return( javafxEditorLoginId );
	}

	public void setJavaFXEditorLoginId( LoginIdEditor value ) {
		javafxEditorLoginId = value;
	}

	public EMailAddressCFLabel getJavaFXLabelEMailAddress() {
		if( javafxLabelEMailAddress == null ) {
			javafxLabelEMailAddress = new EMailAddressCFLabel();
		}
		return( javafxLabelEMailAddress );
	}

	public void setJavaFXLabelEMailAddress( EMailAddressCFLabel value ) {
		javafxLabelEMailAddress = value;
	}

	public EMailAddressEditor getJavaFXEditorEMailAddress() {
		if( javafxEditorEMailAddress == null ) {
			javafxEditorEMailAddress = new EMailAddressEditor();
		}
		return( javafxEditorEMailAddress );
	}

	public void setJavaFXEditorEMailAddress( EMailAddressEditor value ) {
		javafxEditorEMailAddress = value;
	}

	public EMailConfirmUuidCFLabel getJavaFXLabelEMailConfirmUuid() {
		if( javafxLabelEMailConfirmUuid == null ) {
			javafxLabelEMailConfirmUuid = new EMailConfirmUuidCFLabel();
		}
		return( javafxLabelEMailConfirmUuid );
	}

	public void setJavaFXLabelEMailConfirmUuid( EMailConfirmUuidCFLabel value ) {
		javafxLabelEMailConfirmUuid = value;
	}

	public EMailConfirmUuidEditor getJavaFXEditorEMailConfirmUuid() {
		if( javafxEditorEMailConfirmUuid == null ) {
			javafxEditorEMailConfirmUuid = new EMailConfirmUuidEditor();
		}
		return( javafxEditorEMailConfirmUuid );
	}

	public void setJavaFXEditorEMailConfirmUuid( EMailConfirmUuidEditor value ) {
		javafxEditorEMailConfirmUuid = value;
	}

	public PasswordHashCFLabel getJavaFXLabelPasswordHash() {
		if( javafxLabelPasswordHash == null ) {
			javafxLabelPasswordHash = new PasswordHashCFLabel();
		}
		return( javafxLabelPasswordHash );
	}

	public void setJavaFXLabelPasswordHash( PasswordHashCFLabel value ) {
		javafxLabelPasswordHash = value;
	}

	public PasswordHashEditor getJavaFXEditorPasswordHash() {
		if( javafxEditorPasswordHash == null ) {
			javafxEditorPasswordHash = new PasswordHashEditor();
		}
		return( javafxEditorPasswordHash );
	}

	public void setJavaFXEditorPasswordHash( PasswordHashEditor value ) {
		javafxEditorPasswordHash = value;
	}

	public PasswordResetUuidCFLabel getJavaFXLabelPasswordResetUuid() {
		if( javafxLabelPasswordResetUuid == null ) {
			javafxLabelPasswordResetUuid = new PasswordResetUuidCFLabel();
		}
		return( javafxLabelPasswordResetUuid );
	}

	public void setJavaFXLabelPasswordResetUuid( PasswordResetUuidCFLabel value ) {
		javafxLabelPasswordResetUuid = value;
	}

	public PasswordResetUuidEditor getJavaFXEditorPasswordResetUuid() {
		if( javafxEditorPasswordResetUuid == null ) {
			javafxEditorPasswordResetUuid = new PasswordResetUuidEditor();
		}
		return( javafxEditorPasswordResetUuid );
	}

	public void setJavaFXEditorPasswordResetUuid( PasswordResetUuidEditor value ) {
		javafxEditorPasswordResetUuid = value;
	}

	public void populateFields()
	{
		ICFSecSecUserObj popObj = getEffJavaFXFocus();
		if( getPaneMode() == CFPane.PaneMode.Unknown ) {
			popObj = null;
		}
		if( popObj == null ) {
			javafxLookupDefDevObj = null;
		}
		else {
			javafxLookupDefDevObj = (ICFSecSecDeviceObj)popObj.getOptionalLookupDefDev( javafxIsInitializing );
		}
		if( javafxReferenceLookupDefDev != null ) {
			javafxReferenceLookupDefDev.setReferencedObject( javafxLookupDefDevObj );
		}

		if( popObj == null ) {
			getJavaFXEditorSecUserId().setUuidValue( null );
		}
		else {
			getJavaFXEditorSecUserId().setUuidValue( popObj.getRequiredSecUserId() );
		}

		if( popObj == null ) {
			getJavaFXEditorLoginId().setStringValue( null );
		}
		else {
			getJavaFXEditorLoginId().setStringValue( popObj.getRequiredLoginId() );
		}

		if( popObj == null ) {
			getJavaFXEditorEMailAddress().setStringValue( null );
		}
		else {
			getJavaFXEditorEMailAddress().setStringValue( popObj.getRequiredEMailAddress() );
		}

		if( popObj == null ) {
			getJavaFXEditorEMailConfirmUuid().setUuidValue( null );
		}
		else {
			getJavaFXEditorEMailConfirmUuid().setUuidValue( popObj.getOptionalEMailConfirmUuid() );
		}

		if( popObj == null ) {
			getJavaFXEditorPasswordHash().setStringValue( null );
		}
		else {
			getJavaFXEditorPasswordHash().setStringValue( popObj.getRequiredPasswordHash() );
		}

		if( popObj == null ) {
			getJavaFXEditorPasswordResetUuid().setUuidValue( null );
		}
		else {
			getJavaFXEditorPasswordResetUuid().setUuidValue( popObj.getOptionalPasswordResetUuid() );
		}
	}

	public void postFields()
	{
		final String S_ProcName = "postFields";
		ICFSecSecUserObj focus = getJavaFXFocusAsSecUser();
		ICFSecSecUserEditObj editObj;
		if( focus != null ) {
			editObj = (ICFSecSecUserEditObj)(focus.getEdit());
		}
		else {
			editObj = null;
		}
		if( editObj == null ) {
			throw new CFLibUsageException( getClass(),
				S_ProcName,
				"Pane is unfocused or is not editing the focus object" );
		}

		javafxLookupDefDevObj = (ICFSecSecDeviceObj)( javafxReferenceLookupDefDev.getReferencedObject() );
		editObj.setOptionalLookupDefDev( javafxLookupDefDevObj );

		if( getJavaFXEditorLoginId().getStringValue() == null ) {
			editObj.setRequiredLoginId( "" );
		}
		else {
			editObj.setRequiredLoginId( getJavaFXEditorLoginId().getStringValue() );
		}

		if( getJavaFXEditorEMailAddress().getStringValue() == null ) {
			editObj.setRequiredEMailAddress( "" );
		}
		else {
			editObj.setRequiredEMailAddress( getJavaFXEditorEMailAddress().getStringValue() );
		}

		editObj.setOptionalEMailConfirmUuid( getJavaFXEditorEMailConfirmUuid().getUuidValue() );

		if( getJavaFXEditorPasswordHash().getStringValue() == null ) {
			editObj.setRequiredPasswordHash( "" );
		}
		else {
			editObj.setRequiredPasswordHash( getJavaFXEditorPasswordHash().getStringValue() );
		}

		editObj.setOptionalPasswordResetUuid( getJavaFXEditorPasswordResetUuid().getUuidValue() );
	}

	public void setPaneMode( CFPane.PaneMode value ) {
		final String S_ProcName = "setPaneMode";
		CFPane.PaneMode oldValue = getPaneMode();
		if( oldValue == value ) {
			return;
		}
		ICFSecSecUserObj focus = getJavaFXFocusAsSecUser();
		if( ( value != CFPane.PaneMode.Unknown ) && ( value != CFPane.PaneMode.View ) ) {
			if( focus == null ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"javaFXFocus" );
			}
		}
		ICFSecSecUserEditObj editObj;
		if( focus != null ) {
			editObj  = (ICFSecSecUserEditObj)focus.getEdit();
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
								editObj = (ICFSecSecUserEditObj)focus.beginEdit();
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
							editObj = (ICFSecSecUserEditObj)focus.beginEdit();
							if( editObj == null ) {
								throw new CFLibUsageException( getClass(),
									S_ProcName,
									"Expected beginEdit() to return a new edition of the focus object" );
							}
						}
						break;
					case View:
						if( editObj == null ) {
							editObj = (ICFSecSecUserEditObj)focus.beginEdit();
							if( editObj == null ) {
								throw new CFLibUsageException( getClass(),
									S_ProcName,
									"Expected beginEdit() to return a new edition of the focus object" );
							}
						}
						break;
					case Edit:
						if( editObj == null ) {
							editObj = (ICFSecSecUserEditObj)focus.beginEdit();
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
						focus = (ICFSecSecUserObj)editObj.create();
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
								editObj = (ICFSecSecUserEditObj)focus.beginEdit();
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
								editObj = (ICFSecSecUserEditObj)focus.beginEdit();
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
							editObj = (ICFSecSecUserEditObj)focus.beginEdit();
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
			ICFSecSecUserObj focus = getJavaFXFocusAsSecUser();
			if( focus == null ) {
				isEditing = false;
			}
			else if( null == focus.getEdit() ) {
				isEditing = false;
			}
		}
		if( javafxReferenceLookupDefDev != null ) {
			javafxReferenceLookupDefDev.setCustomDisable( ! isEditing );
		}
		if( javafxEditorSecUserId != null ) {
			javafxEditorSecUserId.setDisable( true );
		}
		if( javafxEditorLoginId != null ) {
			javafxEditorLoginId.setDisable( ! isEditing );
		}
		if( javafxEditorEMailAddress != null ) {
			javafxEditorEMailAddress.setDisable( ! isEditing );
		}
		if( javafxEditorEMailConfirmUuid != null ) {
			javafxEditorEMailConfirmUuid.setDisable( ! isEditing );
		}
		if( javafxEditorPasswordHash != null ) {
			javafxEditorPasswordHash.setDisable( ! isEditing );
		}
		if( javafxEditorPasswordResetUuid != null ) {
			javafxEditorPasswordResetUuid.setDisable( ! isEditing );
		}
	}
}
