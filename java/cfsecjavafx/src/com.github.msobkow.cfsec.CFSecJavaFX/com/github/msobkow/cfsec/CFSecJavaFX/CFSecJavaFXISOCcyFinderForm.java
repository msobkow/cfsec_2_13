// Description: Java 11 JavaFX Finder Form implementation for ISOCcy.

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
import java.util.*;
import javafx.beans.property.ReadOnlyObjectWrapper;
import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Pos;
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
import com.github.msobkow.cfsec.CFSec.*;
import com.github.msobkow.cfsec.CFSecObj.*;

/**
 *	CFSecJavaFXISOCcyFinderForm JavaFX Finder Form implementation
 *	for ISOCcy.
 */
public class CFSecJavaFXISOCcyFinderForm
extends CFBorderPane
implements ICFSecJavaFXISOCcyPaneCommon,
	ICFForm
{
	public static String S_FormName = "Find ISO Ccy";
	protected ICFFormManager cfFormManager = null;
	protected ICFSecJavaFXSchema javafxSchema = null;
	protected boolean javafxIsInitializing = true;
	protected ScrollPane scrollMenu = null;
	protected CFHBox hboxMenu = null;
	protected CFVBox vboxMenuAdd = null;
	protected ScrollPane scrollMenuAdd = null;
	protected CFButton buttonAdd = null;
	protected CFButton buttonCancelAdd = null;
	protected CFButton buttonAddISOCcy = null;
	protected CFButton buttonViewSelected = null;
	protected CFButton buttonEditSelected = null;
	protected CFButton buttonClose = null;
	protected CFButton buttonDeleteSelected = null;
	protected List<ICFSecISOCcyObj> listOfISOCcy = null;
	protected ObservableList<ICFSecISOCcyObj> observableListOfISOCcy = null;
	protected TableColumn<ICFSecISOCcyObj, Short> tableColumnISOCcyId = null;
	protected TableColumn<ICFSecISOCcyObj, String> tableColumnISOCode = null;
	protected TableColumn<ICFSecISOCcyObj, String> tableColumnName = null;
	protected TableColumn<ICFSecISOCcyObj, String> tableColumnUnitSymbol = null;
	protected TableColumn<ICFSecISOCcyObj, Short> tableColumnPrecis = null;
	protected TableView<ICFSecISOCcyObj> dataTable = null;

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

	public CFSecJavaFXISOCcyFinderForm( ICFFormManager formManager, ICFSecJavaFXSchema argSchema ) {
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
		javafxSchema = argSchema;
		dataTable = new TableView<ICFSecISOCcyObj>();
		tableColumnISOCcyId = new TableColumn<ICFSecISOCcyObj,Short>( "ISOCcyId" );
		tableColumnISOCcyId.setCellValueFactory( new Callback<CellDataFeatures<ICFSecISOCcyObj,Short>,ObservableValue<Short> >() {
			public ObservableValue<Short> call( CellDataFeatures<ICFSecISOCcyObj, Short> p ) {
				ICFSecISOCcyObj obj = p.getValue();
				if( obj == null ) {
					return( null );
				}
				else {
					short value = obj.getRequiredISOCcyId();
					Short wrapped = Short.valueOf( value );
					ReadOnlyObjectWrapper<Short> observable = new ReadOnlyObjectWrapper<Short>();
					observable.setValue( wrapped );
					return( observable );
				}
			}
		});
		tableColumnISOCcyId.setCellFactory( new Callback<TableColumn<ICFSecISOCcyObj,Short>,TableCell<ICFSecISOCcyObj,Short>>() {
			@Override public TableCell<ICFSecISOCcyObj,Short> call(
				TableColumn<ICFSecISOCcyObj,Short> arg)
			{
				return new CFInt16TableCell<ICFSecISOCcyObj>();
			}
		});
		dataTable.getColumns().add( tableColumnISOCcyId );
		tableColumnISOCode = new TableColumn<ICFSecISOCcyObj,String>( "ISOCode" );
		tableColumnISOCode.setCellValueFactory( new Callback<CellDataFeatures<ICFSecISOCcyObj,String>,ObservableValue<String> >() {
			public ObservableValue<String> call( CellDataFeatures<ICFSecISOCcyObj, String> p ) {
				ICFSecISOCcyObj obj = p.getValue();
				if( obj == null ) {
					return( null );
				}
				else {
					String value = obj.getRequiredISOCode();
					ReadOnlyObjectWrapper<String> observable = new ReadOnlyObjectWrapper<String>();
					observable.setValue( value );
					return( observable );
				}
			}
		});
		tableColumnISOCode.setCellFactory( new Callback<TableColumn<ICFSecISOCcyObj,String>,TableCell<ICFSecISOCcyObj,String>>() {
			@Override public TableCell<ICFSecISOCcyObj,String> call(
				TableColumn<ICFSecISOCcyObj,String> arg)
			{
				return new CFStringTableCell<ICFSecISOCcyObj>();
			}
		});
		dataTable.getColumns().add( tableColumnISOCode );
		tableColumnName = new TableColumn<ICFSecISOCcyObj,String>( "Name" );
		tableColumnName.setCellValueFactory( new Callback<CellDataFeatures<ICFSecISOCcyObj,String>,ObservableValue<String> >() {
			public ObservableValue<String> call( CellDataFeatures<ICFSecISOCcyObj, String> p ) {
				ICFSecISOCcyObj obj = p.getValue();
				if( obj == null ) {
					return( null );
				}
				else {
					String value = obj.getRequiredName();
					ReadOnlyObjectWrapper<String> observable = new ReadOnlyObjectWrapper<String>();
					observable.setValue( value );
					return( observable );
				}
			}
		});
		tableColumnName.setCellFactory( new Callback<TableColumn<ICFSecISOCcyObj,String>,TableCell<ICFSecISOCcyObj,String>>() {
			@Override public TableCell<ICFSecISOCcyObj,String> call(
				TableColumn<ICFSecISOCcyObj,String> arg)
			{
				return new CFStringTableCell<ICFSecISOCcyObj>();
			}
		});
		dataTable.getColumns().add( tableColumnName );
		tableColumnUnitSymbol = new TableColumn<ICFSecISOCcyObj,String>( "UnitSymbol" );
		tableColumnUnitSymbol.setCellValueFactory( new Callback<CellDataFeatures<ICFSecISOCcyObj,String>,ObservableValue<String> >() {
			public ObservableValue<String> call( CellDataFeatures<ICFSecISOCcyObj, String> p ) {
				ICFSecISOCcyObj obj = p.getValue();
				if( obj == null ) {
					return( null );
				}
				else {
					String value = obj.getOptionalUnitSymbol();
					ReadOnlyObjectWrapper<String> observable = new ReadOnlyObjectWrapper<String>();
					observable.setValue( value );
					return( observable );
				}
			}
		});
		tableColumnUnitSymbol.setCellFactory( new Callback<TableColumn<ICFSecISOCcyObj,String>,TableCell<ICFSecISOCcyObj,String>>() {
			@Override public TableCell<ICFSecISOCcyObj,String> call(
				TableColumn<ICFSecISOCcyObj,String> arg)
			{
				return new CFStringTableCell<ICFSecISOCcyObj>();
			}
		});
		dataTable.getColumns().add( tableColumnUnitSymbol );
		tableColumnPrecis = new TableColumn<ICFSecISOCcyObj,Short>( "Precis" );
		tableColumnPrecis.setCellValueFactory( new Callback<CellDataFeatures<ICFSecISOCcyObj,Short>,ObservableValue<Short> >() {
			public ObservableValue<Short> call( CellDataFeatures<ICFSecISOCcyObj, Short> p ) {
				ICFSecISOCcyObj obj = p.getValue();
				if( obj == null ) {
					return( null );
				}
				else {
					short value = obj.getRequiredPrecis();
					Short wrapped = Short.valueOf( value );
					ReadOnlyObjectWrapper<Short> observable = new ReadOnlyObjectWrapper<Short>();
					observable.setValue( wrapped );
					return( observable );
				}
			}
		});
		tableColumnPrecis.setCellFactory( new Callback<TableColumn<ICFSecISOCcyObj,Short>,TableCell<ICFSecISOCcyObj,Short>>() {
			@Override public TableCell<ICFSecISOCcyObj,Short> call(
				TableColumn<ICFSecISOCcyObj,Short> arg)
			{
				return new CFInt16TableCell<ICFSecISOCcyObj>();
			}
		});
		dataTable.getColumns().add( tableColumnPrecis );
		dataTable.getSelectionModel().selectedItemProperty().addListener(
			new ChangeListener<ICFSecISOCcyObj>() {
				@Override public void changed( ObservableValue<? extends ICFSecISOCcyObj> observable,
					ICFSecISOCcyObj oldValue,
					ICFSecISOCcyObj newValue )
				{
					setJavaFXFocus( newValue );
				}
			});

		scrollMenu = new ScrollPane();
		scrollMenu.setVbarPolicy( ScrollBarPolicy.NEVER );
		scrollMenu.setHbarPolicy( ScrollBarPolicy.AS_NEEDED );
		scrollMenu.setFitToHeight( true );
		scrollMenu.setContent( getHBoxMenu() );

		setTop( scrollMenu );
		setCenter( dataTable );

		refreshMe();
		javafxIsInitializing = false;
		adjustFinderButtons();
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
		if( cfFormManager != null ) {
			if( cfFormManager.getCurrentForm() == this ) {
				cfFormManager.closeCurrentForm();
			}
		}
	}

	public ICFSecJavaFXSchema getJavaFXSchema() {
		return( javafxSchema );
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

	public CFHBox getHBoxMenu() {
		if( hboxMenu == null ) {
			hboxMenu = new CFHBox( 10 );

			buttonAddISOCcy = new CFButton();
			buttonAddISOCcy.setMinWidth( 200 );
			buttonAddISOCcy.setText( "Add ISO Ccy..." );
			buttonAddISOCcy.setOnAction( new EventHandler<ActionEvent>() {
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
						ICFSecISOCcyObj obj = (ICFSecISOCcyObj)schemaObj.getISOCcyTableObj().newInstance();
						ICFSecISOCcyEditObj edit = (ICFSecISOCcyEditObj)( obj.beginEdit() );
						if( edit == null ) {
							throw new CFLibNullArgumentException( getClass(),
								S_ProcName,
								0,
								"edit" );
						}
						CFBorderPane frame = javafxSchema.getISOCcyFactory().newAddForm( cfFormManager, obj, getViewEditClosedCallback(), true );
						ICFSecJavaFXISOCcyPaneCommon jpanelCommon = (ICFSecJavaFXISOCcyPaneCommon)frame;
						jpanelCommon.setPaneMode( CFPane.PaneMode.Add );
						cfFormManager.pushForm( frame );
					}
					catch( Throwable t ) {
						CFConsole.formException( S_FormName, ((CFButton)e.getSource()).getText(), t );
					}
				}
			});
			hboxMenu.getChildren().add( buttonAddISOCcy );

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
						ICFSecISOCcyObj selectedInstance = getJavaFXFocusAsISOCcy();
						if( selectedInstance != null ) {
							String classCode = selectedInstance.getClassCode();
							if( "a003".equals( classCode ) ) {
								CFBorderPane frame = javafxSchema.getISOCcyFactory().newViewEditForm( cfFormManager, selectedInstance, getViewEditClosedCallback(), false );
								((ICFSecJavaFXISOCcyPaneCommon)frame).setPaneMode( CFPane.PaneMode.View );
								cfFormManager.pushForm( frame );
							}
							else {
								throw new CFLibUnsupportedClassException( getClass(),
									S_ProcName,
									"selectedInstance",
									selectedInstance,
									"ICFSecISOCcyObj" );
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
						ICFSecISOCcyObj selectedInstance = getJavaFXFocusAsISOCcy();
						if( selectedInstance != null ) {
							String classCode = selectedInstance.getClassCode();
							if( "a003".equals( classCode ) ) {
								CFBorderPane frame = javafxSchema.getISOCcyFactory().newViewEditForm( cfFormManager, selectedInstance, getViewEditClosedCallback(), false );
								((ICFSecJavaFXISOCcyPaneCommon)frame).setPaneMode( CFPane.PaneMode.Edit );
								cfFormManager.pushForm( frame );
							}
							else {
								throw new CFLibUnsupportedClassException( getClass(),
									S_ProcName,
									"selectedInstance",
									selectedInstance,
									"ICFSecISOCcyObj" );
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
						ICFSecISOCcyObj selectedInstance = getJavaFXFocusAsISOCcy();
						if( selectedInstance != null ) {
							String classCode = selectedInstance.getClassCode();
							if( "a003".equals( classCode ) ) {
								CFBorderPane frame = javafxSchema.getISOCcyFactory().newAskDeleteForm( cfFormManager, selectedInstance, getDeleteCallback() );
								((ICFSecJavaFXISOCcyPaneCommon)frame).setPaneMode( CFPane.PaneMode.View );
								cfFormManager.pushForm( frame );
							}
							else {
								throw new CFLibUnsupportedClassException( getClass(),
									S_ProcName,
									"selectedInstance",
									selectedInstance,
									"ICFSecISOCcyObj" );
							}
						}
					}
					catch( Throwable t ) {
						CFConsole.formException( S_FormName, ((CFButton)e.getSource()).getText(), t );
					}
				}
			});
			hboxMenu.getChildren().add( buttonDeleteSelected );

			buttonClose = new CFButton();
			buttonClose.setMinWidth( 200 );
			buttonClose.setText( "Close" );
			buttonClose.setOnAction( new EventHandler<ActionEvent>() {
				@Override public void handle( ActionEvent e ) {
					final String S_ProcName = "handle";
					try {
						cfFormManager.closeCurrentForm();
					}
					catch( Throwable t ) {
						CFConsole.formException( S_FormName, ((CFButton)e.getSource()).getText(), t );
					}
				}
			});
			hboxMenu.getChildren().add( buttonClose );
		}
		return( hboxMenu );
	}

	public void setJavaFXFocus( ICFLibAnyObj value ) {
		final String S_ProcName = "setJavaFXFocus";
		if( ( value == null ) || ( value instanceof ICFSecISOCcyObj ) ) {
			super.setJavaFXFocus( value );
		}
		else {
			throw new CFLibUnsupportedClassException( getClass(),
				S_ProcName,
				"value",
				value,
				"ICFSecISOCcyObj" );
		}
		adjustFinderButtons();
	}

	public ICFSecISOCcyObj getJavaFXFocusAsISOCcy() {
		return( (ICFSecISOCcyObj)getJavaFXFocus() );
	}

	public void setJavaFXFocusAsISOCcy( ICFSecISOCcyObj value ) {
		setJavaFXFocus( value );
	}

	public void adjustFinderButtons() {
		ICFSecISOCcyObj selectedObj = getJavaFXFocusAsISOCcy();
		boolean disableState;
		if( selectedObj == null ) {
			disableState = true;
		}
		else {
			disableState = false;
		}
		boolean inAddMode;
		if( getLeft() == null ) {
			inAddMode = false;
		}
		else {
			inAddMode = true;
			disableState = true;
		}

		if( buttonViewSelected != null ) {
			buttonViewSelected.setDisable( disableState );
		}
		if( buttonEditSelected != null ) {
			buttonEditSelected.setDisable( disableState );
		}
		if( buttonDeleteSelected != null ) {
			buttonDeleteSelected.setDisable( disableState );
		}
		if( buttonAddISOCcy != null ) {
			buttonAddISOCcy.setDisable( false );
		}

	}

	public class ISOCcyByQualNameComparator
	implements Comparator<ICFSecISOCcyObj>
	{
		public ISOCcyByQualNameComparator() {
		}

		public int compare( ICFSecISOCcyObj lhs, ICFSecISOCcyObj rhs ) {
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

	protected ISOCcyByQualNameComparator compareISOCcyByQualName = new ISOCcyByQualNameComparator();

	public void loadData( boolean forceReload ) {
		ICFSecSchemaObj schemaObj = (ICFSecSchemaObj)javafxSchema.getSchema();
		if( ( listOfISOCcy == null ) || forceReload ) {
			observableListOfISOCcy = null;
			listOfISOCcy = schemaObj.getISOCcyTableObj().readAllISOCcy( javafxIsInitializing );
			if( listOfISOCcy != null ) {
				observableListOfISOCcy = FXCollections.observableArrayList( listOfISOCcy );
				observableListOfISOCcy.sort( compareISOCcyByQualName );
			}
			else {
				observableListOfISOCcy = FXCollections.observableArrayList();
			}
			dataTable.setItems( observableListOfISOCcy );
			// Hack from stackoverflow to fix JavaFX TableView refresh issue
			((TableColumn)dataTable.getColumns().get(0)).setVisible( false );
			((TableColumn)dataTable.getColumns().get(0)).setVisible( true );
		}
	}

	public void refreshMe() {
		loadData( true );
	}
}
