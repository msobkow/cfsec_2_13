// Description: Java 11 JavaFX Picker of Obj Pane implementation for TSecGroup.

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
import org.msscf.msscf.cflib.CFLib.*;
import org.msscf.msscf.cflib.CFLib.JavaFX.*;
import org.apache.commons.codec.binary.Base64;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfsec.CFSecObj.*;

/**
 *	CFSecJavaFXTSecGroupPickerPane JavaFX Pick Obj Pane implementation
 *	for TSecGroup.
 */
public class CFSecJavaFXTSecGroupPickerPane
extends CFBorderPane
implements ICFSecJavaFXTSecGroupPaneList
{
	public static String S_FormName = "Choose Tenant Security Group";
	protected ICFSecJavaFXSchema javafxSchema = null;
	protected Collection<ICFSecTSecGroupObj> javafxDataCollection = null;
	protected ObservableList<ICFSecTSecGroupObj> observableListOfTSecGroup = null;
	protected TableColumn<ICFSecTSecGroupObj, Integer> tableColumnTSecGroupId = null;
	protected TableColumn<ICFSecTSecGroupObj, String> tableColumnName = null;
	protected TableColumn<ICFSecTSecGroupObj, Boolean> tableColumnIsVisible = null;
	protected TableView<ICFSecTSecGroupObj> dataTable = null;
	protected CFHBox hboxMenu = null;
	public final String S_ColumnNames[] = { "Name" };
	protected ICFFormManager cfFormManager = null;
	protected ICFSecJavaFXTSecGroupChosen invokeWhenChosen = null;
	protected ICFSecTenantObj javafxContainer = null;
	protected CFButton buttonCancel = null;
	protected CFButton buttonChooseNone = null;
	protected CFButton buttonChooseSelected = null;
	protected ScrollPane scrollMenu = null;
	public CFSecJavaFXTSecGroupPickerPane( ICFFormManager formManager,
		ICFSecJavaFXSchema argSchema,
		ICFSecTSecGroupObj argFocus,
		ICFSecTenantObj argContainer,
		Collection<ICFSecTSecGroupObj> argDataCollection,
		ICFSecJavaFXTSecGroupChosen whenChosen )
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
		dataTable = new TableView<ICFSecTSecGroupObj>();
		tableColumnTSecGroupId = new TableColumn<ICFSecTSecGroupObj,Integer>( "TSecurity Group Id" );
		tableColumnTSecGroupId.setCellValueFactory( new Callback<CellDataFeatures<ICFSecTSecGroupObj,Integer>,ObservableValue<Integer> >() {
			public ObservableValue<Integer> call( CellDataFeatures<ICFSecTSecGroupObj, Integer> p ) {
				ICFSecTSecGroupObj obj = p.getValue();
				if( obj == null ) {
					return( null );
				}
				else {
					int value = obj.getRequiredTSecGroupId();
					Integer wrapped = Integer.valueOf( value );
					ReadOnlyObjectWrapper<Integer> observable = new ReadOnlyObjectWrapper<Integer>();
					observable.setValue( wrapped );
					return( observable );
				}
			}
		});
		tableColumnTSecGroupId.setCellFactory( new Callback<TableColumn<ICFSecTSecGroupObj,Integer>,TableCell<ICFSecTSecGroupObj,Integer>>() {
			@Override public TableCell<ICFSecTSecGroupObj,Integer> call(
				TableColumn<ICFSecTSecGroupObj,Integer> arg)
			{
				return new CFInt32TableCell<ICFSecTSecGroupObj>();
			}
		});
		dataTable.getColumns().add( tableColumnTSecGroupId );
		tableColumnName = new TableColumn<ICFSecTSecGroupObj,String>( "Name" );
		tableColumnName.setCellValueFactory( new Callback<CellDataFeatures<ICFSecTSecGroupObj,String>,ObservableValue<String> >() {
			public ObservableValue<String> call( CellDataFeatures<ICFSecTSecGroupObj, String> p ) {
				ICFSecTSecGroupObj obj = p.getValue();
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
		tableColumnName.setCellFactory( new Callback<TableColumn<ICFSecTSecGroupObj,String>,TableCell<ICFSecTSecGroupObj,String>>() {
			@Override public TableCell<ICFSecTSecGroupObj,String> call(
				TableColumn<ICFSecTSecGroupObj,String> arg)
			{
				return new CFStringTableCell<ICFSecTSecGroupObj>();
			}
		});
		dataTable.getColumns().add( tableColumnName );
		tableColumnIsVisible = new TableColumn<ICFSecTSecGroupObj,Boolean>( "IsVisible" );
		tableColumnIsVisible.setCellValueFactory( new Callback<CellDataFeatures<ICFSecTSecGroupObj,Boolean>,ObservableValue<Boolean> >() {
			public ObservableValue<Boolean> call( CellDataFeatures<ICFSecTSecGroupObj, Boolean> p ) {
				ICFSecTSecGroupObj obj = p.getValue();
				if( obj == null ) {
					return( null );
				}
				else {
					boolean value = obj.getRequiredIsVisible();
					Boolean wrapped = Boolean.valueOf( value );
					ReadOnlyObjectWrapper<Boolean> observable = new ReadOnlyObjectWrapper<Boolean>();
					observable.setValue( wrapped );
					return( observable );
				}
			}
		});
		tableColumnIsVisible.setCellFactory( new Callback<TableColumn<ICFSecTSecGroupObj,Boolean>,TableCell<ICFSecTSecGroupObj,Boolean>>() {
			@Override public TableCell<ICFSecTSecGroupObj,Boolean> call(
				TableColumn<ICFSecTSecGroupObj,Boolean> arg)
			{
				return new CFBoolTableCell<ICFSecTSecGroupObj>();
			}
		});
		dataTable.getColumns().add( tableColumnIsVisible );
		dataTable.getSelectionModel().selectedItemProperty().addListener(
			new ChangeListener<ICFSecTSecGroupObj>() {
				@Override public void changed( ObservableValue<? extends ICFSecTSecGroupObj> observable,
					ICFSecTSecGroupObj oldValue,
					ICFSecTSecGroupObj newValue )
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
					invokeWhenChosen.choseTSecGroup( null );
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
					ICFSecTSecGroupObj selectedInstance = getJavaFXFocusAsTSecGroup();
					invokeWhenChosen.choseTSecGroup( selectedInstance );
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
		if( ( value == null ) || ( value instanceof ICFSecTSecGroupObj ) ) {
			super.setJavaFXFocus( value );
		}
		else {
			throw new CFLibUnsupportedClassException( getClass(),
				S_ProcName,
				"value",
				value,
				"ICFSecTSecGroupObj" );
		}
		if( dataTable == null ) {
			return;
		}
	}

	public ICFSecTSecGroupObj getJavaFXFocusAsTSecGroup() {
		return( (ICFSecTSecGroupObj)getJavaFXFocus() );
	}

	public void setJavaFXFocusAsTSecGroup( ICFSecTSecGroupObj value ) {
		setJavaFXFocus( value );
	}

	public class TSecGroupByQualNameComparator
	implements Comparator<ICFSecTSecGroupObj>
	{
		public TSecGroupByQualNameComparator() {
		}

		public int compare( ICFSecTSecGroupObj lhs, ICFSecTSecGroupObj rhs ) {
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

	protected TSecGroupByQualNameComparator compareTSecGroupByQualName = new TSecGroupByQualNameComparator();

	public Collection<ICFSecTSecGroupObj> getJavaFXDataCollection() {
		return( javafxDataCollection );
	}

	public void setJavaFXDataCollection( Collection<ICFSecTSecGroupObj> value ) {
		final String S_ProcName = "setJavaFXDataCollection";
		javafxDataCollection = value;
		observableListOfTSecGroup = FXCollections.observableArrayList();
		if( javafxDataCollection != null ) {
				Iterator<ICFSecTSecGroupObj> iter = javafxDataCollection.iterator();
				while( iter.hasNext() ) {
					observableListOfTSecGroup.add( iter.next() );
				}
				observableListOfTSecGroup.sort( compareTSecGroupByQualName );
		}
		if( dataTable != null ) {
			dataTable.setItems( observableListOfTSecGroup );
			// Hack from stackoverflow to fix JavaFX TableView refresh issue
			((TableColumn)dataTable.getColumns().get(0)).setVisible( false );
			((TableColumn)dataTable.getColumns().get(0)).setVisible( true );
		}
	}

	public ICFSecTenantObj getJavaFXContainer() {
		return( javafxContainer );
	}

	public void setJavaFXContainer( ICFSecTenantObj value ) {
		javafxContainer = value;
	}

	public void adjustListButtons() {
		boolean enableState;
		ICFSecTSecGroupObj selectedObj = getJavaFXFocusAsTSecGroup();
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

