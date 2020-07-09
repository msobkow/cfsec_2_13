// Description: Java 11 JavaFX Picker of Obj Pane implementation for ISOCcy.

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
import java.util.List;
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
 *	CFSecJavaFXISOCcyPickerPane JavaFX Pick Obj Pane implementation
 *	for ISOCcy.
 */
public class CFSecJavaFXISOCcyPickerPane
extends CFBorderPane
implements ICFSecJavaFXISOCcyPaneList
{
	public static String S_FormName = "Choose ISO Ccy";
	protected ICFSecJavaFXSchema javafxSchema = null;
	protected Collection<ICFSecISOCcyObj> javafxDataCollection = null;
	protected ObservableList<ICFSecISOCcyObj> observableListOfISOCcy = null;
	protected TableColumn<ICFSecISOCcyObj, Short> tableColumnISOCcyId = null;
	protected TableColumn<ICFSecISOCcyObj, String> tableColumnISOCode = null;
	protected TableColumn<ICFSecISOCcyObj, String> tableColumnName = null;
	protected TableColumn<ICFSecISOCcyObj, String> tableColumnUnitSymbol = null;
	protected TableColumn<ICFSecISOCcyObj, Short> tableColumnPrecis = null;
	protected TableView<ICFSecISOCcyObj> dataTable = null;
	protected CFHBox hboxMenu = null;
	public final String S_ColumnNames[] = { "Name" };
	protected ICFFormManager cfFormManager = null;
	protected ICFSecJavaFXISOCcyChosen invokeWhenChosen = null;
	protected ICFLibAnyObj javafxContainer = null;
	protected CFButton buttonCancel = null;
	protected CFButton buttonChooseNone = null;
	protected CFButton buttonChooseSelected = null;
	protected ScrollPane scrollMenu = null;
	public CFSecJavaFXISOCcyPickerPane( ICFFormManager formManager,
		ICFSecJavaFXSchema argSchema,
		ICFSecISOCcyObj argFocus,
		ICFLibAnyObj argContainer,
		Collection<ICFSecISOCcyObj> argDataCollection,
		ICFSecJavaFXISOCcyChosen whenChosen )
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
		if( whenChosen == null ) {
			throw new CFLibNullArgumentException( getClass(),
				S_ProcName,
				6,
				"whenChosen" );
		}
		invokeWhenChosen = whenChosen;
		// argFocus is optional; focus may be set later during execution as
		// conditions of the runtime change.
		javafxSchema = argSchema;
		javaFXFocus = argFocus;
		javafxContainer = argContainer;
		setJavaFXDataCollection( argDataCollection );
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
					if( buttonChooseSelected != null ) {
						if( newValue != null ) {
							buttonChooseSelected.setDisable( false );
						}
						else {
							buttonChooseSelected.setDisable( true );
						}
					}
				}
			});
		hboxMenu = new CFHBox( 10 );
		buttonCancel = new CFButton();
		buttonCancel.setMinWidth( 200 );
		buttonCancel.setText( "Cancel" );
		buttonCancel.setOnAction( new EventHandler<ActionEvent>() {
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
		hboxMenu.getChildren().add( buttonCancel );
		buttonChooseNone = new CFButton();
		buttonChooseNone.setMinWidth( 200 );
		buttonChooseNone.setText( "ChooseNone" );
		buttonChooseNone.setOnAction( new EventHandler<ActionEvent>() {
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
					invokeWhenChosen.choseISOCcy( null );
					cfFormManager.closeCurrentForm();
				}
				catch( Throwable t ) {
					CFConsole.formException( S_FormName, ((CFButton)e.getSource()).getText(), t );
				}
			}
		});
		hboxMenu.getChildren().add( buttonChooseNone );
		buttonChooseSelected = new CFButton();
		buttonChooseSelected.setMinWidth( 200 );
		buttonChooseSelected.setText( "ChooseSelected" );
		buttonChooseSelected.setOnAction( new EventHandler<ActionEvent>() {
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
					invokeWhenChosen.choseISOCcy( selectedInstance );
					cfFormManager.closeCurrentForm();
				}
				catch( Throwable t ) {
					CFConsole.formException( S_FormName, ((CFButton)e.getSource()).getText(), t );
				}
			}
		});
		hboxMenu.getChildren().add( buttonChooseSelected );
		if( argFocus != null ) {
			dataTable.getSelectionModel().select( argFocus );
		}

		scrollMenu = new ScrollPane();
		scrollMenu.setVbarPolicy( ScrollBarPolicy.NEVER );
		scrollMenu.setHbarPolicy( ScrollBarPolicy.AS_NEEDED );
		scrollMenu.setFitToHeight( true );
		scrollMenu.setContent( hboxMenu );

		setTop( scrollMenu );
		setCenter( dataTable );
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
		if( dataTable == null ) {
			return;
		}
	}

	public ICFSecISOCcyObj getJavaFXFocusAsISOCcy() {
		return( (ICFSecISOCcyObj)getJavaFXFocus() );
	}

	public void setJavaFXFocusAsISOCcy( ICFSecISOCcyObj value ) {
		setJavaFXFocus( value );
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

	public Collection<ICFSecISOCcyObj> getJavaFXDataCollection() {
		return( javafxDataCollection );
	}

	public void setJavaFXDataCollection( Collection<ICFSecISOCcyObj> value ) {
		final String S_ProcName = "setJavaFXDataCollection";
		javafxDataCollection = value;
		observableListOfISOCcy = FXCollections.observableArrayList();
		if( javafxDataCollection != null ) {
				Iterator<ICFSecISOCcyObj> iter = javafxDataCollection.iterator();
				while( iter.hasNext() ) {
					observableListOfISOCcy.add( iter.next() );
				}
				observableListOfISOCcy.sort( compareISOCcyByQualName );
		}
		if( dataTable != null ) {
			dataTable.setItems( observableListOfISOCcy );
			// Hack from stackoverflow to fix JavaFX TableView refresh issue
			((TableColumn)dataTable.getColumns().get(0)).setVisible( false );
			((TableColumn)dataTable.getColumns().get(0)).setVisible( true );
		}
	}

	public ICFLibAnyObj getJavaFXContainer() {
		return( javafxContainer );
	}

	public void setJavaFXContainer( ICFLibAnyObj value ) {
		javafxContainer = value;
	}

	public void adjustListButtons() {
		boolean enableState;
		ICFSecISOCcyObj selectedObj = getJavaFXFocusAsISOCcy();
		if( selectedObj == null ) {
			enableState = false;
		}
		else {
			enableState = true;
		}

		if( buttonChooseSelected != null ) {
			buttonChooseSelected.setDisable( ! enableState );
		}
		if( buttonChooseNone != null ) {
			buttonChooseNone.setDisable( false );
		}
		if( buttonCancel != null ) {
			buttonCancel.setDisable( false );
		}

	}
}

