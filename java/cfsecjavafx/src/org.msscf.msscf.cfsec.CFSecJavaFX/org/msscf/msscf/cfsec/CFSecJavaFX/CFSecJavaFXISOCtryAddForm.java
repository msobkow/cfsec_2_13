// Description: Java 11 JavaFX Add Form implementation for ISOCtry.

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

import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.control.ScrollPane;
import javafx.scene.control.ScrollPane.ScrollBarPolicy;
import com.github.msobkow.cflib.CFLib.*;
import com.github.msobkow.cflib.CFLib.JavaFX.*;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfsec.CFSecObj.*;

/**
 *	CFSecJavaFXISOCtryAddForm JavaFX Add Form implementation
 *	for ISOCtry.
 */
public class CFSecJavaFXISOCtryAddForm
extends CFBorderPane
implements ICFSecJavaFXISOCtryPaneCommon,
	ICFForm
{
	public static String S_FormName = "Add ISO Ctry";
	protected ICFFormManager cfFormManager = null;
	protected ICFSecJavaFXSchema javafxSchema = null;
	protected ICFFormClosedCallback formClosedCallback = null;
	protected boolean allowSave = true;
	protected CFSplitPane javafxAddPane = null;
	protected CFButton buttonSave = null;
	protected CFButton buttonCancel = null;
	protected CFButton buttonClose = null;
	protected ScrollPane scrollMenu = null;
	protected CFHBox hboxMenu = null;

	public CFSecJavaFXISOCtryAddForm( ICFFormManager formManager, ICFSecJavaFXSchema argSchema, ICFSecISOCtryObj argFocus, ICFFormClosedCallback closeCallback, boolean argAllowSave ) {
		super();
		final String S_ProcName = "construct-schema-focus";
		allowSave = argAllowSave;
		if( formManager == null ) {
			throw new CFLibNullArgumentException( getClass(),
				S_ProcName,
				1,
				"formManager" );
		}
		cfFormManager = formManager;
		formClosedCallback = closeCallback;
		if( argSchema == null ) {
			throw new CFLibNullArgumentException( getClass(),
				S_ProcName,
				2,
				"argSchema" );
		}
		// argFocus is optional; focus may be set later during execution as
		// conditions of the runtime change.
		javafxSchema = argSchema;
		javaFXFocus = argFocus;
		if( ( argFocus != null ) && ( ! argFocus.getIsNew() ) ) {
			argFocus = (ICFSecISOCtryObj)argFocus.read( true );
			javaFXFocus = argFocus;
		}
		javafxAddPane = argSchema.getISOCtryFactory().newAddPane( cfFormManager, argFocus );

		scrollMenu = new ScrollPane();
		scrollMenu.setVbarPolicy( ScrollBarPolicy.NEVER );
		scrollMenu.setHbarPolicy( ScrollBarPolicy.AS_NEEDED );
		scrollMenu.setFitToHeight( true );
		scrollMenu.setContent( getHBoxMenu() );

		setTop( scrollMenu );
		setCenter( javafxAddPane );
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

	public void forceCancelAndClose() {
		ICFSecISOCtryObj focus = getJavaFXFocusAsISOCtry();
		if( focus != null ) {
			ICFSecISOCtryEditObj editObj = (ICFSecISOCtryEditObj)focus.getEdit();
			if( editObj != null ) {
				if( editObj.getIsNew() ) {
					editObj.endEdit();
					editObj = null;
					setJavaFXFocus( null );
					setPaneMode( CFPane.PaneMode.Unknown );
				}
				else {
					editObj.endEdit();
					editObj = null;
					setPaneMode( CFPane.PaneMode.View );
				}
			}
		}
		if( cfFormManager != null ) {
			if( cfFormManager.getCurrentForm() == this ) {
				cfFormManager.closeCurrentForm();
			}
		}
		if( formClosedCallback != null ) {
			formClosedCallback.formClosed( null );
		}
	}

	public ICFSecJavaFXSchema getJavaFXSchema() {
		return( javafxSchema );
	}

	public ICFLibAnyObj getJavaFXFocus() {
		ICFLibAnyObj obj;
		if( javafxAddPane != null ) {
			obj = javafxAddPane.getJavaFXFocus();
		}
		else {
			obj = null;
		}
		return( obj );
	}

	public void setJavaFXFocus( ICFLibAnyObj value ) {
		final String S_ProcName = "setJavaFXFocus";
		if( ( value == null ) || ( value instanceof ICFSecISOCtryObj ) ) {
			super.setJavaFXFocus( value );
		}
		else {
			throw new CFLibUnsupportedClassException( getClass(),
				S_ProcName,
				"value",
				value,
				"ICFSecISOCtryObj" );
		}
		((ICFSecJavaFXISOCtryPaneCommon)javafxAddPane).setJavaFXFocus( value );
		ICFSecISOCtryObj argFocus = (ICFSecISOCtryObj)value;
		if( ( argFocus != null ) && ( ! argFocus.getIsNew() ) ) {
			argFocus = (ICFSecISOCtryObj)argFocus.read( true );
			super.setJavaFXFocus( argFocus );
		}
	}

	public ICFSecISOCtryObj getJavaFXFocusAsISOCtry() {
		return( (ICFSecISOCtryObj)getJavaFXFocus() );
	}

	public void setJavaFXFocusAsISOCtry( ICFSecISOCtryObj value ) {
		setJavaFXFocus( value );
	}

	public CFHBox getHBoxMenu() {
		if( hboxMenu == null ) {
			hboxMenu = new CFHBox( 10 );
			buttonSave = new CFButton();
			buttonSave.setMinWidth( 200 );
			buttonSave.setText( "Save" );
			buttonSave.setOnAction( new EventHandler<ActionEvent>() {
				@Override public void handle( ActionEvent e ) {
					final String S_ProcName = "handle";
					try {
						ICFSecISOCtryObj focus = getJavaFXFocusAsISOCtry();
						if( focus != null ) {
							ICFSecISOCtryEditObj editObj = (ICFSecISOCtryEditObj)( focus.getEdit() );
							if( editObj != null ) {
								setPaneMode( CFPane.PaneMode.Update );
							}
							else {
								throw new CFLibUsageException( getClass(),
									S_ProcName,
									"Cannot save an object that isn't being edited" );
							}
						}
						// If an object was added, the focus will change to the persisted instance
						focus = getJavaFXFocusAsISOCtry();
						CFBorderPane frame = javafxSchema.getISOCtryFactory().newViewEditForm( cfFormManager, focus, formClosedCallback, true );
						((ICFSecJavaFXISOCtryPaneCommon)frame).setPaneMode( CFPane.PaneMode.View );
						cfFormManager.closeCurrentForm();
						cfFormManager.pushForm( frame );
					}
					catch( Throwable t ) {
						CFConsole.formException( S_FormName, ((CFButton)e.getSource()).getText(), t );
					}
				}
			});
			if( allowSave ) {
				hboxMenu.getChildren().add( buttonSave );
			}

			buttonClose = new CFButton();
			buttonClose.setMinWidth( 200 );
			buttonClose.setText( "Close" );
			buttonClose.setOnAction( new EventHandler<ActionEvent>() {
				@Override public void handle( ActionEvent e ) {
					final String S_ProcName = "handle";
					try {
						ICFSecISOCtryObj focus = getJavaFXFocusAsISOCtry();
						if( focus != null ) {
							ICFSecISOCtryEditObj editObj = (ICFSecISOCtryEditObj)( focus.getEdit() );
							if( editObj != null ) {
								setPaneMode( CFPane.PaneMode.Update );
							}
							else {
								throw new CFLibUsageException( getClass(),
									S_ProcName,
									"Cannot save an object that isn't being edited" );
							}
						}
						// If an object was added, the focus will change to the persisted instance
						focus = getJavaFXFocusAsISOCtry();
						cfFormManager.closeCurrentForm();
						if( formClosedCallback != null ) {
							formClosedCallback.formClosed( focus );
						}
					}
					catch( Throwable t ) {
						CFConsole.formException( S_FormName, ((CFButton)e.getSource()).getText(), t );
					}
				}
			});
			hboxMenu.getChildren().add( buttonClose );

			buttonCancel = new CFButton();
			buttonCancel.setMinWidth( 200 );
			buttonCancel.setText( "Cancel" );
			buttonCancel.setOnAction( new EventHandler<ActionEvent>() {
				@Override public void handle( ActionEvent e ) {
					final String S_ProcName = "handle";
					try {
						ICFSecISOCtryObj focus = getJavaFXFocusAsISOCtry();
						if( focus != null ) {
							ICFSecISOCtryEditObj editObj = (ICFSecISOCtryEditObj)focus.getEdit();
							if( editObj != null ) {
								if( editObj.getIsNew() ) {
									editObj.endEdit();
									editObj = null;
									setJavaFXFocus( null );
									setPaneMode( CFPane.PaneMode.Unknown );
								}
								else {
									editObj.endEdit();
									editObj = null;
									setPaneMode( CFPane.PaneMode.View );
								}
							}
						}
						cfFormManager.closeCurrentForm();
						if( formClosedCallback != null ) {
							formClosedCallback.formClosed( null );
						}
					}
					catch( Throwable t ) {
						CFConsole.formException( S_FormName, ((CFButton)e.getSource()).getText(), t );
					}
				}
			});
			hboxMenu.getChildren().add( buttonCancel );

		}
		return( hboxMenu );
	}

	public void setPaneMode( CFPane.PaneMode value ) {
		CFPane.PaneMode oldMode = getPaneMode();
		if( oldMode == value ) {
			return;
		}
		try {
			super.setPaneMode( value );
			((ICFSecJavaFXISOCtryPaneCommon)javafxAddPane).setPaneMode( value );
		}
		catch( Throwable t ) {
			super.setPaneMode( oldMode );
			((ICFSecJavaFXISOCtryPaneCommon)javafxAddPane).setPaneMode( oldMode );
			throw t;
		}
		if( value == CFPane.PaneMode.View ) {
			if( buttonSave != null ) {
				buttonSave.setDisable( true );
			}
			if( buttonCancel != null ) {
				buttonCancel.setDisable( false );
			}
			if( buttonClose != null ) {
				buttonClose.setDisable( true );
			}
		}
		else if( value == CFPane.PaneMode.Edit ) {
			if( buttonSave != null ) {
				buttonSave.setDisable( false );
			}
			if( buttonCancel != null ) {
				buttonCancel.setDisable( false );
			}
			if( buttonClose != null ) {
				buttonClose.setDisable( false );
			}
		}
		else if( value == CFPane.PaneMode.Add ) {
			if( buttonSave != null ) {
				buttonSave.setDisable( false );
			}
			if( buttonCancel != null ) {
				buttonCancel.setDisable( false );
			}
			if( buttonClose != null ) {
				buttonClose.setDisable( false );
			}
		}
		else {
			if( buttonSave != null ) {
				buttonSave.setDisable( true );
			}
			if( buttonCancel != null ) {
				buttonCancel.setDisable( false );
			}
			if( buttonClose != null ) {
				buttonClose.setDisable( true );
			}
		}
	}
}
