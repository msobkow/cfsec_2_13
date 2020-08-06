// Description: Java 11 JavaFX Picker of Obj Pane implementation for SecGroupForm.

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
 *	CFSecJavaFXSecGroupFormPickerPane JavaFX Pick Obj Pane implementation
 *	for SecGroupForm.
 */
public class CFSecJavaFXSecGroupFormPickerPane
extends CFBorderPane
implements ICFSecJavaFXSecGroupFormPaneList
{
	public static String S_FormName = "Choose Security Group Form";
	protected ICFSecJavaFXSchema javafxSchema = null;
	protected ICFSecJavaFXSecGroupFormPageCallback pageCallback;
	protected CFButton buttonRefresh = null;
	protected CFButton buttonMoreData = null;
	protected boolean endOfData = true;
	protected ObservableList<ICFSecSecGroupFormObj> observableListOfSecGroupForm = null;
	protected TableColumn<ICFSecSecGroupFormObj, Long> tableColumnSecGroupFormId = null;
	protected TableColumn<ICFSecSecGroupFormObj, ICFSecSecAppObj> tableColumnParentApp = null;
	protected TableColumn<ICFSecSecGroupFormObj, ICFSecSecFormObj> tableColumnParentForm = null;
	protected TableView<ICFSecSecGroupFormObj> dataTable = null;
	protected CFHBox hboxMenu = null;
	public final String S_ColumnNames[] = { "Name" };
	protected ICFFormManager cfFormManager = null;
	protected ICFSecJavaFXSecGroupFormChosen invokeWhenChosen = null;
	protected ICFSecSecGroupObj javafxContainer = null;
	protected CFButton buttonCancel = null;
	protected CFButton buttonChooseNone = null;
	protected CFButton buttonChooseSelected = null;
	protected ScrollPane scrollMenu = null;
	public CFSecJavaFXSecGroupFormPickerPane( ICFFormManager formManager,
		ICFSecJavaFXSchema argSchema,
		ICFSecSecGroupFormObj argFocus,
		ICFSecSecGroupObj argContainer,
		ICFSecJavaFXSecGroupFormPageCallback argPageCallback,
		ICFSecJavaFXSecGroupFormChosen whenChosen )
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
		pageCallback = argPageCallback;
		dataTable = new TableView<ICFSecSecGroupFormObj>();
		tableColumnSecGroupFormId = new TableColumn<ICFSecSecGroupFormObj,Long>( "Security Group Form Id" );
		tableColumnSecGroupFormId.setCellValueFactory( new Callback<CellDataFeatures<ICFSecSecGroupFormObj,Long>,ObservableValue<Long> >() {
			public ObservableValue<Long> call( CellDataFeatures<ICFSecSecGroupFormObj, Long> p ) {
				ICFSecSecGroupFormObj obj = p.getValue();
				if( obj == null ) {
					return( null );
				}
				else {
					long value = obj.getRequiredSecGroupFormId();
					Long wrapped = Long.valueOf( value );
					ReadOnlyObjectWrapper<Long> observable = new ReadOnlyObjectWrapper<Long>();
					observable.setValue( wrapped );
					return( observable );
				}
			}
		});
		tableColumnSecGroupFormId.setCellFactory( new Callback<TableColumn<ICFSecSecGroupFormObj,Long>,TableCell<ICFSecSecGroupFormObj,Long>>() {
			@Override public TableCell<ICFSecSecGroupFormObj,Long> call(
				TableColumn<ICFSecSecGroupFormObj,Long> arg)
			{
				return new CFInt64TableCell<ICFSecSecGroupFormObj>();
			}
		});
		dataTable.getColumns().add( tableColumnSecGroupFormId );
		tableColumnParentApp = new TableColumn<ICFSecSecGroupFormObj, ICFSecSecAppObj>( "App" );
		tableColumnParentApp.setCellValueFactory( new Callback<CellDataFeatures<ICFSecSecGroupFormObj,ICFSecSecAppObj>,ObservableValue<ICFSecSecAppObj> >() {
			public ObservableValue<ICFSecSecAppObj> call( CellDataFeatures<ICFSecSecGroupFormObj, ICFSecSecAppObj> p ) {
				ICFSecSecGroupFormObj obj = p.getValue();
				if( obj == null ) {
					return( null );
				}
				else {
					ICFSecSecAppObj ref = obj.getRequiredParentApp();
					ReadOnlyObjectWrapper<ICFSecSecAppObj> observable = new ReadOnlyObjectWrapper<ICFSecSecAppObj>();
					observable.setValue( ref );
					return( observable );
				}
			}
		});
		tableColumnParentApp.setCellFactory( new Callback<TableColumn<ICFSecSecGroupFormObj,ICFSecSecAppObj>,TableCell<ICFSecSecGroupFormObj,ICFSecSecAppObj>>() {
			@Override public TableCell<ICFSecSecGroupFormObj,ICFSecSecAppObj> call(
				TableColumn<ICFSecSecGroupFormObj,ICFSecSecAppObj> arg)
			{
				return new CFReferenceTableCell<ICFSecSecGroupFormObj,ICFSecSecAppObj>();
			}
		});
		dataTable.getColumns().add( tableColumnParentApp );
		tableColumnParentForm = new TableColumn<ICFSecSecGroupFormObj, ICFSecSecFormObj>( "Form" );
		tableColumnParentForm.setCellValueFactory( new Callback<CellDataFeatures<ICFSecSecGroupFormObj,ICFSecSecFormObj>,ObservableValue<ICFSecSecFormObj> >() {
			public ObservableValue<ICFSecSecFormObj> call( CellDataFeatures<ICFSecSecGroupFormObj, ICFSecSecFormObj> p ) {
				ICFSecSecGroupFormObj obj = p.getValue();
				if( obj == null ) {
					return( null );
				}
				else {
					ICFSecSecFormObj ref = obj.getRequiredParentForm();
					ReadOnlyObjectWrapper<ICFSecSecFormObj> observable = new ReadOnlyObjectWrapper<ICFSecSecFormObj>();
					observable.setValue( ref );
					return( observable );
				}
			}
		});
		tableColumnParentForm.setCellFactory( new Callback<TableColumn<ICFSecSecGroupFormObj,ICFSecSecFormObj>,TableCell<ICFSecSecGroupFormObj,ICFSecSecFormObj>>() {
			@Override public TableCell<ICFSecSecGroupFormObj,ICFSecSecFormObj> call(
				TableColumn<ICFSecSecGroupFormObj,ICFSecSecFormObj> arg)
			{
				return new CFReferenceTableCell<ICFSecSecGroupFormObj,ICFSecSecFormObj>();
			}
		});
		dataTable.getColumns().add( tableColumnParentForm );
		dataTable.getSelectionModel().selectedItemProperty().addListener(
			new ChangeListener<ICFSecSecGroupFormObj>() {
				@Override public void changed( ObservableValue<? extends ICFSecSecGroupFormObj> observable,
					ICFSecSecGroupFormObj oldValue,
					ICFSecSecGroupFormObj newValue )
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
			buttonRefresh = new CFButton();
			buttonRefresh.setMinWidth( 200 );
			buttonRefresh.setText( "Refresh" );
			buttonRefresh.setOnAction( new EventHandler<ActionEvent>() {
				@Override public void handle( ActionEvent e ) {
					final String S_ProcName = "handle";
					try {
						observableListOfSecGroupForm = FXCollections.observableArrayList();
						List<ICFSecSecGroupFormObj> page = pageCallback.pageData( null,
							null );
						Iterator<ICFSecSecGroupFormObj> iter = page.iterator();
						while( iter.hasNext() ) {
							observableListOfSecGroupForm.add( iter.next() );
						}
						if( page.size() < 25 ) {
							observableListOfSecGroupForm.sort( compareSecGroupFormByQualName );
							endOfData = true;
						}
						else {
							endOfData = false;
						}
						if( dataTable != null ) {
							dataTable.setItems( observableListOfSecGroupForm );
							// Hack from stackoverflow to fix JavaFX TableView refresh issue
							((TableColumn)dataTable.getColumns().get(0)).setVisible( false );
							((TableColumn)dataTable.getColumns().get(0)).setVisible( true );
						}
						adjustListButtons();
					}
					catch( Throwable t ) {
						CFConsole.formException( S_FormName, ((CFButton)e.getSource()).getText(), t );
					}
				}
			});
			hboxMenu.getChildren().add( buttonRefresh );

			buttonMoreData = new CFButton();
			buttonMoreData.setMinWidth( 200 );
			buttonMoreData.setText( "MoreData" );
			buttonMoreData.setOnAction( new EventHandler<ActionEvent>() {
				@Override public void handle( ActionEvent e ) {
					final String S_ProcName = "handle";
					try {
						ICFSecSecGroupFormObj lastObj = null;
						if( ( observableListOfSecGroupForm != null ) && ( observableListOfSecGroupForm.size() > 0 ) ) {
							lastObj = observableListOfSecGroupForm.get( observableListOfSecGroupForm.size() - 1 );
						}
						List<ICFSecSecGroupFormObj> page;
						if( lastObj != null ) {
							page = pageCallback.pageData( lastObj.getRequiredClusterId(),
							lastObj.getRequiredSecGroupFormId() );
						}
						else {
							page = pageCallback.pageData( null,
							null );
						}
						Iterator<ICFSecSecGroupFormObj> iter = page.iterator();
						while( iter.hasNext() ) {
							observableListOfSecGroupForm.add( iter.next() );
						}
						if( page.size() < 25 ) {
							observableListOfSecGroupForm.sort( compareSecGroupFormByQualName );
							endOfData = true;
						}
						else {
							endOfData = false;
						}
						if( dataTable != null ) {
							dataTable.setItems( observableListOfSecGroupForm );
							// Hack from stackoverflow to fix JavaFX TableView refresh issue
							((TableColumn)dataTable.getColumns().get(0)).setVisible( false );
							((TableColumn)dataTable.getColumns().get(0)).setVisible( true );
						}
						adjustListButtons();
					}
					catch( Throwable t ) {
						CFConsole.formException( S_FormName, ((CFButton)e.getSource()).getText(), t );
					}
				}
			});
			hboxMenu.getChildren().add( buttonMoreData );

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
					invokeWhenChosen.choseSecGroupForm( null );
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
					ICFSecSecGroupFormObj selectedInstance = getJavaFXFocusAsSecGroupForm();
					invokeWhenChosen.choseSecGroupForm( selectedInstance );
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
		if( dataTable == null ) {
			return;
		}
	}

	public ICFSecSecGroupFormObj getJavaFXFocusAsSecGroupForm() {
		return( (ICFSecSecGroupFormObj)getJavaFXFocus() );
	}

	public void setJavaFXFocusAsSecGroupForm( ICFSecSecGroupFormObj value ) {
		setJavaFXFocus( value );
	}

	public class SecGroupFormByQualNameComparator
	implements Comparator<ICFSecSecGroupFormObj>
	{
		public SecGroupFormByQualNameComparator() {
		}

		public int compare( ICFSecSecGroupFormObj lhs, ICFSecSecGroupFormObj rhs ) {
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

	protected SecGroupFormByQualNameComparator compareSecGroupFormByQualName = new SecGroupFormByQualNameComparator();

	public Collection<ICFSecSecGroupFormObj> getJavaFXDataCollection() {
		return( null );
	}

	public void setJavaFXDataCollection( Collection<ICFSecSecGroupFormObj> value ) {
		// Use page data instead
	}

	public ICFSecSecGroupObj getJavaFXContainer() {
		return( javafxContainer );
	}

	public void setJavaFXContainer( ICFSecSecGroupObj value ) {
		javafxContainer = value;
	}

	public void adjustListButtons() {
		boolean enableState;
		ICFSecSecGroupFormObj selectedObj = getJavaFXFocusAsSecGroupForm();
		if( selectedObj == null ) {
			enableState = false;
		}
		else {
			enableState = true;
		}

		if( buttonRefresh != null ) {
			buttonRefresh.setDisable( false );
		}
		if( buttonMoreData != null ) {
			buttonMoreData.setDisable( endOfData );
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

