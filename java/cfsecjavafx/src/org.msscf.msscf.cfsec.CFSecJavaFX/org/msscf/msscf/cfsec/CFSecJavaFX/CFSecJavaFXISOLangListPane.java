// Description: Java 11 JavaFX List of Obj Pane implementation for ISOLang.

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
import java.util.*;
import javafx.beans.property.ReadOnlyObjectWrapper;
import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Parent;
import javafx.scene.control.ScrollPane;
import javafx.scene.control.ScrollPane.ScrollBarPolicy;
import javafx.scene.control.TableCell;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableColumn.CellDataFeatures;
import javafx.scene.control.TableView;
import javafx.util.Callback;
import com.github.msobkow.cflib.CFLib.*;
import com.github.msobkow.cflib.CFLib.JavaFX.*;
import org.apache.commons.codec.binary.Base64;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfsec.CFSecObj.*;

/**
 *	CFSecJavaFXISOLangListPane JavaFX List of Obj Pane implementation
 *	for ISOLang.
 */
public class CFSecJavaFXISOLangListPane
extends CFBorderPane
implements ICFSecJavaFXISOLangPaneList
{
	public static String S_FormName = "List ISO Lang";
	protected ICFSecJavaFXSchema javafxSchema = null;
	protected Collection<ICFSecISOLangObj> javafxDataCollection = null;
	protected ObservableList<ICFSecISOLangObj> observableListOfISOLang = null;
	protected ScrollPane scrollMenu = null;
	protected CFHBox hboxMenu = null;
	protected CFButton buttonAddISOLang = null;
	protected CFButton buttonViewSelected = null;
	protected CFButton buttonEditSelected = null;
	protected CFButton buttonDeleteSelected = null;
	protected TableView<ICFSecISOLangObj> dataTable = null;
	protected TableColumn<ICFSecISOLangObj, Short> tableColumnISOLangId = null;
	protected TableColumn<ICFSecISOLangObj, String> tableColumnISO6392Code = null;
	protected TableColumn<ICFSecISOLangObj, String> tableColumnISO6391Code = null;
	protected TableColumn<ICFSecISOLangObj, String> tableColumnEnglishName = null;

	public final String S_ColumnNames[] = { "Name" };
	protected ICFFormManager cfFormManager = null;
	protected boolean javafxIsInitializing = true;
	protected boolean javafxSortByChain = false;
	protected ICFLibAnyObj javafxContainer = null;
	protected ICFRefreshCallback javafxRefreshCallback = null;
	class ViewEditClosedCallback implements ICFFormClosedCallback {
		public ViewEditClosedCallback() {
		}

		@Override
		public void formClosed( ICFLibAnyObj affectedObject ) {
			if( affectedObject != null ) {
				refreshMe();
			}
		}
	}

	protected ViewEditClosedCallback viewEditClosedCallback = null;

	public ICFFormClosedCallback getViewEditClosedCallback() {
		if( viewEditClosedCallback == null ) {
			viewEditClosedCallback = new ViewEditClosedCallback();
		}
		return( viewEditClosedCallback );
	}

	class DeleteCallback implements ICFDeleteCallback {
		public DeleteCallback() {
		}
		@Override
		public void deleted( ICFLibAnyObj deletedObject ) {
			if( deletedObject != null ) {
				refreshMe();
			}
		}

		@Override
		public void formClosed( ICFLibAnyObj affectedObject ) {
			if( affectedObject != null ) {
				refreshMe();
			}
		}
	}

	protected DeleteCallback deleteCallback = null;

	public ICFDeleteCallback getDeleteCallback() {
		if( deleteCallback == null ) {
			deleteCallback = new DeleteCallback();
		}
		return( deleteCallback );
	}


	public CFSecJavaFXISOLangListPane( ICFFormManager formManager,
		ICFSecJavaFXSchema argSchema,
		ICFLibAnyObj argContainer,
		ICFSecISOLangObj argFocus,
		Collection<ICFSecISOLangObj> argDataCollection,
		ICFRefreshCallback refreshCallback,
		boolean sortByChain )
	{
		super();
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
		javaFXFocus = argFocus;
		javafxContainer = argContainer;
		javafxRefreshCallback = refreshCallback;
		javafxSortByChain = sortByChain;
		setJavaFXDataCollection( argDataCollection );
		dataTable = new TableView<ICFSecISOLangObj>();
		tableColumnISOLangId = new TableColumn<ICFSecISOLangObj,Short>( "ISOLangId" );
		tableColumnISOLangId.setCellValueFactory( new Callback<CellDataFeatures<ICFSecISOLangObj,Short>,ObservableValue<Short> >() {
			public ObservableValue<Short> call( CellDataFeatures<ICFSecISOLangObj, Short> p ) {
				ICFSecISOLangObj obj = p.getValue();
				if( obj == null ) {
					return( null );
				}
				else {
					short value = obj.getRequiredISOLangId();
					Short wrapped = Short.valueOf( value );
					ReadOnlyObjectWrapper<Short> observable = new ReadOnlyObjectWrapper<Short>();
					observable.setValue( wrapped );
					return( observable );
				}
			}
		});
		tableColumnISOLangId.setCellFactory( new Callback<TableColumn<ICFSecISOLangObj,Short>,TableCell<ICFSecISOLangObj,Short>>() {
			@Override public TableCell<ICFSecISOLangObj,Short> call(
				TableColumn<ICFSecISOLangObj,Short> arg)
			{
				return new CFInt16TableCell<ICFSecISOLangObj>();
			}
		});
		dataTable.getColumns().add( tableColumnISOLangId );
		tableColumnISO6392Code = new TableColumn<ICFSecISOLangObj,String>( "ISO6392Code" );
		tableColumnISO6392Code.setCellValueFactory( new Callback<CellDataFeatures<ICFSecISOLangObj,String>,ObservableValue<String> >() {
			public ObservableValue<String> call( CellDataFeatures<ICFSecISOLangObj, String> p ) {
				ICFSecISOLangObj obj = p.getValue();
				if( obj == null ) {
					return( null );
				}
				else {
					String value = obj.getRequiredISO6392Code();
					ReadOnlyObjectWrapper<String> observable = new ReadOnlyObjectWrapper<String>();
					observable.setValue( value );
					return( observable );
				}
			}
		});
		tableColumnISO6392Code.setCellFactory( new Callback<TableColumn<ICFSecISOLangObj,String>,TableCell<ICFSecISOLangObj,String>>() {
			@Override public TableCell<ICFSecISOLangObj,String> call(
				TableColumn<ICFSecISOLangObj,String> arg)
			{
				return new CFStringTableCell<ICFSecISOLangObj>();
			}
		});
		dataTable.getColumns().add( tableColumnISO6392Code );
		tableColumnISO6391Code = new TableColumn<ICFSecISOLangObj,String>( "ISO6391Code" );
		tableColumnISO6391Code.setCellValueFactory( new Callback<CellDataFeatures<ICFSecISOLangObj,String>,ObservableValue<String> >() {
			public ObservableValue<String> call( CellDataFeatures<ICFSecISOLangObj, String> p ) {
				ICFSecISOLangObj obj = p.getValue();
				if( obj == null ) {
					return( null );
				}
				else {
					String value = obj.getOptionalISO6391Code();
					ReadOnlyObjectWrapper<String> observable = new ReadOnlyObjectWrapper<String>();
					observable.setValue( value );
					return( observable );
				}
			}
		});
		tableColumnISO6391Code.setCellFactory( new Callback<TableColumn<ICFSecISOLangObj,String>,TableCell<ICFSecISOLangObj,String>>() {
			@Override public TableCell<ICFSecISOLangObj,String> call(
				TableColumn<ICFSecISOLangObj,String> arg)
			{
				return new CFStringTableCell<ICFSecISOLangObj>();
			}
		});
		dataTable.getColumns().add( tableColumnISO6391Code );
		tableColumnEnglishName = new TableColumn<ICFSecISOLangObj,String>( "EnglishName" );
		tableColumnEnglishName.setCellValueFactory( new Callback<CellDataFeatures<ICFSecISOLangObj,String>,ObservableValue<String> >() {
			public ObservableValue<String> call( CellDataFeatures<ICFSecISOLangObj, String> p ) {
				ICFSecISOLangObj obj = p.getValue();
				if( obj == null ) {
					return( null );
				}
				else {
					String value = obj.getRequiredEnglishName();
					ReadOnlyObjectWrapper<String> observable = new ReadOnlyObjectWrapper<String>();
					observable.setValue( value );
					return( observable );
				}
			}
		});
		tableColumnEnglishName.setCellFactory( new Callback<TableColumn<ICFSecISOLangObj,String>,TableCell<ICFSecISOLangObj,String>>() {
			@Override public TableCell<ICFSecISOLangObj,String> call(
				TableColumn<ICFSecISOLangObj,String> arg)
			{
				return new CFStringTableCell<ICFSecISOLangObj>();
			}
		});
		dataTable.getColumns().add( tableColumnEnglishName );
		dataTable.getSelectionModel().selectedItemProperty().addListener(
			new ChangeListener<ICFSecISOLangObj>() {
				@Override public void changed( ObservableValue<? extends ICFSecISOLangObj> observable,
					ICFSecISOLangObj oldValue,
					ICFSecISOLangObj newValue )
				{
					setJavaFXFocus( newValue );
				}
			});

		scrollMenu = new ScrollPane();
		scrollMenu.setVbarPolicy( ScrollBarPolicy.NEVER );
		scrollMenu.setHbarPolicy( ScrollBarPolicy.AS_NEEDED );
		scrollMenu.setFitToHeight( true );
		scrollMenu.setContent( getPanelHBoxMenu() );

		setTop( scrollMenu );
		setCenter( dataTable );
		javafxIsInitializing = false;
		if( observableListOfISOLang != null ) {
			dataTable.setItems( observableListOfISOLang );
		}
		adjustListButtons();
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

	public void setPaneMode( CFPane.PaneMode value ) {
		super.setPaneMode( value );
		adjustListButtons();
	}

	public void setJavaFXFocus( ICFLibAnyObj value ) {
		final String S_ProcName = "setJavaFXFocus";
		if( ( value == null ) || ( value instanceof ICFSecISOLangObj ) ) {
			super.setJavaFXFocus( value );
		}
		else {
			throw new CFLibUnsupportedClassException( getClass(),
				S_ProcName,
				"value",
				value,
				"ICFSecISOLangObj" );
		}
		adjustListButtons();
	}

	public ICFSecISOLangObj getJavaFXFocusAsISOLang() {
		return( (ICFSecISOLangObj)getJavaFXFocus() );
	}

	public void setJavaFXFocusAsISOLang( ICFSecISOLangObj value ) {
		setJavaFXFocus( value );
	}

	public class ISOLangByQualNameComparator
	implements Comparator<ICFSecISOLangObj>
	{
		public ISOLangByQualNameComparator() {
		}

		public int compare( ICFSecISOLangObj lhs, ICFSecISOLangObj rhs ) {
			if( lhs == null ) {
				if( rhs == null ) {
					return( 0 );
				}
				else {
					return( -1 );
				}
			}
			else if( rhs == null ) {
				return( 1 );
			}
			else {
				String lhsValue = lhs.getObjQualifiedName();
				String rhsValue = rhs.getObjQualifiedName();
				if( lhsValue == null ) {
					if( rhsValue == null ) {
						return( 0 );
					}
					else {
						return( -1 );
					}
				}
				else if( rhsValue == null ) {
					return( 1 );
				}
				else {
					return( lhsValue.compareTo( rhsValue ) );
				}
			}
		}
	}

	protected ISOLangByQualNameComparator compareISOLangByQualName = new ISOLangByQualNameComparator();

	public Collection<ICFSecISOLangObj> getJavaFXDataCollection() {
		return( javafxDataCollection );
	}

	public void setJavaFXDataCollection( Collection<ICFSecISOLangObj> value ) {
		final String S_ProcName = "setJavaFXDataCollection";
		javafxDataCollection = value;
		observableListOfISOLang = FXCollections.observableArrayList();
		if( javafxDataCollection != null ) {
				Iterator<ICFSecISOLangObj> iter = javafxDataCollection.iterator();
				while( iter.hasNext() ) {
					observableListOfISOLang.add( iter.next() );
				}
				observableListOfISOLang.sort( compareISOLangByQualName );
		}
		if( dataTable != null ) {
			dataTable.setItems( observableListOfISOLang );
			// Hack from stackoverflow to fix JavaFX TableView refresh issue
			((TableColumn)dataTable.getColumns().get(0)).setVisible( false );
			((TableColumn)dataTable.getColumns().get(0)).setVisible( true );
		}
	}

	protected class CompareCFButtonByText
	implements Comparator<CFButton>
	{
		public CompareCFButtonByText() {
		}

		@Override public int compare( CFButton lhs, CFButton rhs ) {
			if( lhs == null ) {
				if( rhs == null ) {
					return( 0 );
				}
				else {
					return( -1 );
				}
			}
			else if( rhs == null ) {
				return( 1 );
			}
			else {
				int retval = lhs.getText().compareTo( rhs.getText() );
				return( retval );
			}
		}
	}

	public CFHBox getPanelHBoxMenu() {
		if( hboxMenu == null ) {
			hboxMenu = new CFHBox( 10 );
			buttonAddISOLang = new CFButton();
			buttonAddISOLang.setMinWidth( 200 );
			buttonAddISOLang.setText( "Add ISO Lang" );
			buttonAddISOLang.setOnAction( new EventHandler<ActionEvent>() {
				@Override public void handle( ActionEvent e ) {
					final String S_ProcName = "handle";
					try {
						ICFSecSchemaObj schemaObj = (ICFSecSchemaObj)javafxSchema.getSchema();
						ICFSecISOLangObj obj = (ICFSecISOLangObj)schemaObj.getISOLangTableObj().newInstance();
						ICFSecISOLangEditObj edit = (ICFSecISOLangEditObj)( obj.beginEdit() );
						if( edit == null ) {
							throw new CFLibNullArgumentException( getClass(),
								S_ProcName,
								0,
								"edit" );
						}
						CFBorderPane frame = javafxSchema.getISOLangFactory().newAddForm( cfFormManager, obj, getViewEditClosedCallback(), true );
						ICFSecJavaFXISOLangPaneCommon jpanelCommon = (ICFSecJavaFXISOLangPaneCommon)frame;
						jpanelCommon.setJavaFXFocus( obj );
						jpanelCommon.setPaneMode( CFPane.PaneMode.Add );
						cfFormManager.pushForm( frame );
					}
					catch( Throwable t ) {
						CFConsole.formException( S_FormName, ((CFButton)e.getSource()).getText(), t );
					}
				}
			});
			hboxMenu.getChildren().add( buttonAddISOLang );
			buttonViewSelected = new CFButton();
			buttonViewSelected.setMinWidth( 200 );
			buttonViewSelected.setText( "View Selected" );
			buttonViewSelected.setOnAction( new EventHandler<ActionEvent>() {
				@Override public void handle( ActionEvent e ) {
					final String S_ProcName = "handle";
					try {
						ICFSecSchemaObj schemaObj = (ICFSecSchemaObj)javafxSchema.getSchema();
						if( schemaObj == null ) {
							throw new CFLibNullArgumentException( getClass(),
								S_ProcName,
								0,
								"schemaObj" );
						}
						ICFSecISOLangObj selectedInstance = getJavaFXFocusAsISOLang();
						if( selectedInstance != null ) {
							String classCode = selectedInstance.getClassCode();
							if( "a007".equals( classCode ) ) {
								CFBorderPane frame = javafxSchema.getISOLangFactory().newViewEditForm( cfFormManager, selectedInstance, getViewEditClosedCallback(), false );
								((ICFSecJavaFXISOLangPaneCommon)frame).setPaneMode( CFPane.PaneMode.View );
								cfFormManager.pushForm( frame );
							}
							else {
								throw new CFLibUnsupportedClassException( getClass(),
									S_ProcName,
									"selectedInstance",
									selectedInstance,
									"ICFSecISOLangObj" );
							}
						}
					}
					catch( Throwable t ) {
						CFConsole.formException( S_FormName, ((CFButton)e.getSource()).getText(), t );
					}
				}
			});
			hboxMenu.getChildren().add( buttonViewSelected );

			buttonEditSelected = new CFButton();
			buttonEditSelected.setMinWidth( 200 );
			buttonEditSelected.setText( "Edit Selected" );
			buttonEditSelected.setOnAction( new EventHandler<ActionEvent>() {
				@Override public void handle( ActionEvent e ) {
					final String S_ProcName = "handle";
					try {
						ICFSecSchemaObj schemaObj = (ICFSecSchemaObj)javafxSchema.getSchema();
						if( schemaObj == null ) {
							throw new CFLibNullArgumentException( getClass(),
								S_ProcName,
								0,
								"schemaObj" );
						}
						ICFSecISOLangObj selectedInstance = getJavaFXFocusAsISOLang();
						if( selectedInstance != null ) {
							String classCode = selectedInstance.getClassCode();
							if( "a007".equals( classCode ) ) {
								CFBorderPane frame = javafxSchema.getISOLangFactory().newViewEditForm( cfFormManager, selectedInstance, getViewEditClosedCallback(), false );
								((ICFSecJavaFXISOLangPaneCommon)frame).setPaneMode( CFPane.PaneMode.Edit );
								cfFormManager.pushForm( frame );
							}
							else {
								throw new CFLibUnsupportedClassException( getClass(),
									S_ProcName,
									"selectedInstance",
									selectedInstance,
									"ICFSecISOLangObj" );
							}
						}
					}
					catch( Throwable t ) {
						CFConsole.formException( S_FormName, ((CFButton)e.getSource()).getText(), t );
					}
				}
			});
			hboxMenu.getChildren().add( buttonEditSelected );

			buttonDeleteSelected = new CFButton();
			buttonDeleteSelected.setMinWidth( 200 );
			buttonDeleteSelected.setText( "Delete Selected" );
			buttonDeleteSelected.setOnAction( new EventHandler<ActionEvent>() {
				@Override public void handle( ActionEvent e ) {
					final String S_ProcName = "handle";
					try {
						ICFSecSchemaObj schemaObj = (ICFSecSchemaObj)javafxSchema.getSchema();
						if( schemaObj == null ) {
							throw new CFLibNullArgumentException( getClass(),
								S_ProcName,
								0,
								"schemaObj" );
						}
						ICFSecISOLangObj selectedInstance = getJavaFXFocusAsISOLang();
						if( selectedInstance != null ) {
							String classCode = selectedInstance.getClassCode();
							if( "a007".equals( classCode ) ) {
								CFBorderPane frame = javafxSchema.getISOLangFactory().newAskDeleteForm( cfFormManager, selectedInstance, getDeleteCallback() );
								((ICFSecJavaFXISOLangPaneCommon)frame).setPaneMode( CFPane.PaneMode.View );
								cfFormManager.pushForm( frame );
							}
							else {
								throw new CFLibUnsupportedClassException( getClass(),
									S_ProcName,
									"selectedInstance",
									selectedInstance,
									"ICFSecISOLangObj" );
							}
						}
					}
					catch( Throwable t ) {
						CFConsole.formException( S_FormName, ((CFButton)e.getSource()).getText(), t );
					}
				}
			});
			hboxMenu.getChildren().add( buttonDeleteSelected );

		}
		return( hboxMenu );
	}

	public ICFLibAnyObj getJavaFXContainer() {
		return( javafxContainer );
	}

	public void setJavaFXContainer( ICFLibAnyObj value ) {
		javafxContainer = value;
	}

	public void refreshMe() {
		if( javafxRefreshCallback != null ) {
			javafxRefreshCallback.refreshMe();
		}
	}

	public void adjustListButtons() {
		boolean enableState;
		boolean inEditState;
		boolean allowAdds;
		boolean inAddMode = false;
		ICFSecISOLangObj selectedObj = getJavaFXFocusAsISOLang();
		CFPane.PaneMode mode = getPaneMode();
		if( mode == CFPane.PaneMode.Edit ) {
			inEditState = true;
			allowAdds = false;
		}
		else {
			inEditState = false;
			if( getJavaFXContainer() != null ) {
				if( getLeft() != null ) {
					allowAdds = false;
					inAddMode = true;
				}
				else {
					allowAdds = true;
				}
			}
			else {
				allowAdds = false;
			}
		}
		if( selectedObj == null ) {
			enableState = false;
		}
		else {
			if( ( ! inAddMode ) && ( ! inEditState ) ) {
				enableState = true;
			}
			else {
				enableState = false;
			}
		}

		if( buttonViewSelected != null ) {
			buttonViewSelected.setDisable( ! enableState );
		}
		if( buttonEditSelected != null ) {
			if( inEditState ) {
				buttonEditSelected.setDisable( true );
			}
			else {
				buttonEditSelected.setDisable( ! enableState );
			}
		}
		if( buttonDeleteSelected != null ) {
			buttonDeleteSelected.setDisable( ! enableState );
		}
		if( buttonAddISOLang != null ) {
			buttonAddISOLang.setDisable( ! allowAdds );
		}

	}
}
