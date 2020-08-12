// Description: Java 11 JavaFX List of Obj Pane implementation for ISOTZone.

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

package org.msscf.msscf.cfsec.v2_13.cfsec.CFSecJavaFX;

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
import org.msscf.msscf.cflib.v2_13.CFLib.*;
import org.msscf.msscf.cflib.v2_13.CFLib.JavaFX.*;
import org.apache.commons.codec.binary.Base64;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfsec.CFSecObj.*;

/**
 *	CFSecJavaFXISOTZoneListPane JavaFX List of Obj Pane implementation
 *	for ISOTZone.
 */
public class CFSecJavaFXISOTZoneListPane
extends CFBorderPane
implements ICFSecJavaFXISOTZonePaneList
{
	public static String S_FormName = "List ISO Timezone";
	protected ICFSecJavaFXSchema javafxSchema = null;
	protected Collection<ICFSecISOTZoneObj> javafxDataCollection = null;
	protected ObservableList<ICFSecISOTZoneObj> observableListOfISOTZone = null;
	protected ScrollPane scrollMenu = null;
	protected CFHBox hboxMenu = null;
	protected CFButton buttonAddISOTZone = null;
	protected CFButton buttonViewSelected = null;
	protected CFButton buttonEditSelected = null;
	protected CFButton buttonDeleteSelected = null;
	protected TableView<ICFSecISOTZoneObj> dataTable = null;
	protected TableColumn<ICFSecISOTZoneObj, Short> tableColumnISOTZoneId = null;
	protected TableColumn<ICFSecISOTZoneObj, String> tableColumnIso8601 = null;
	protected TableColumn<ICFSecISOTZoneObj, String> tableColumnTZName = null;
	protected TableColumn<ICFSecISOTZoneObj, Short> tableColumnTZHourOffset = null;
	protected TableColumn<ICFSecISOTZoneObj, Short> tableColumnTZMinOffset = null;
	protected TableColumn<ICFSecISOTZoneObj, String> tableColumnDescription = null;
	protected TableColumn<ICFSecISOTZoneObj, Boolean> tableColumnVisible = null;

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


	public CFSecJavaFXISOTZoneListPane( ICFFormManager formManager,
		ICFSecJavaFXSchema argSchema,
		ICFLibAnyObj argContainer,
		ICFSecISOTZoneObj argFocus,
		Collection<ICFSecISOTZoneObj> argDataCollection,
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
		dataTable = new TableView<ICFSecISOTZoneObj>();
		tableColumnISOTZoneId = new TableColumn<ICFSecISOTZoneObj,Short>( "ISO Timezone Id" );
		tableColumnISOTZoneId.setCellValueFactory( new Callback<CellDataFeatures<ICFSecISOTZoneObj,Short>,ObservableValue<Short> >() {
			public ObservableValue<Short> call( CellDataFeatures<ICFSecISOTZoneObj, Short> p ) {
				ICFSecISOTZoneObj obj = p.getValue();
				if( obj == null ) {
					return( null );
				}
				else {
					short value = obj.getRequiredISOTZoneId();
					Short wrapped = Short.valueOf( value );
					ReadOnlyObjectWrapper<Short> observable = new ReadOnlyObjectWrapper<Short>();
					observable.setValue( wrapped );
					return( observable );
				}
			}
		});
		tableColumnISOTZoneId.setCellFactory( new Callback<TableColumn<ICFSecISOTZoneObj,Short>,TableCell<ICFSecISOTZoneObj,Short>>() {
			@Override public TableCell<ICFSecISOTZoneObj,Short> call(
				TableColumn<ICFSecISOTZoneObj,Short> arg)
			{
				return new CFInt16TableCell<ICFSecISOTZoneObj>();
			}
		});
		dataTable.getColumns().add( tableColumnISOTZoneId );
		tableColumnIso8601 = new TableColumn<ICFSecISOTZoneObj,String>( "ISO8601" );
		tableColumnIso8601.setCellValueFactory( new Callback<CellDataFeatures<ICFSecISOTZoneObj,String>,ObservableValue<String> >() {
			public ObservableValue<String> call( CellDataFeatures<ICFSecISOTZoneObj, String> p ) {
				ICFSecISOTZoneObj obj = p.getValue();
				if( obj == null ) {
					return( null );
				}
				else {
					String value = obj.getRequiredIso8601();
					ReadOnlyObjectWrapper<String> observable = new ReadOnlyObjectWrapper<String>();
					observable.setValue( value );
					return( observable );
				}
			}
		});
		tableColumnIso8601.setCellFactory( new Callback<TableColumn<ICFSecISOTZoneObj,String>,TableCell<ICFSecISOTZoneObj,String>>() {
			@Override public TableCell<ICFSecISOTZoneObj,String> call(
				TableColumn<ICFSecISOTZoneObj,String> arg)
			{
				return new CFStringTableCell<ICFSecISOTZoneObj>();
			}
		});
		dataTable.getColumns().add( tableColumnIso8601 );
		tableColumnTZName = new TableColumn<ICFSecISOTZoneObj,String>( "Timezone Name" );
		tableColumnTZName.setCellValueFactory( new Callback<CellDataFeatures<ICFSecISOTZoneObj,String>,ObservableValue<String> >() {
			public ObservableValue<String> call( CellDataFeatures<ICFSecISOTZoneObj, String> p ) {
				ICFSecISOTZoneObj obj = p.getValue();
				if( obj == null ) {
					return( null );
				}
				else {
					String value = obj.getRequiredTZName();
					ReadOnlyObjectWrapper<String> observable = new ReadOnlyObjectWrapper<String>();
					observable.setValue( value );
					return( observable );
				}
			}
		});
		tableColumnTZName.setCellFactory( new Callback<TableColumn<ICFSecISOTZoneObj,String>,TableCell<ICFSecISOTZoneObj,String>>() {
			@Override public TableCell<ICFSecISOTZoneObj,String> call(
				TableColumn<ICFSecISOTZoneObj,String> arg)
			{
				return new CFStringTableCell<ICFSecISOTZoneObj>();
			}
		});
		dataTable.getColumns().add( tableColumnTZName );
		tableColumnTZHourOffset = new TableColumn<ICFSecISOTZoneObj,Short>( "Timezone Hour Offset" );
		tableColumnTZHourOffset.setCellValueFactory( new Callback<CellDataFeatures<ICFSecISOTZoneObj,Short>,ObservableValue<Short> >() {
			public ObservableValue<Short> call( CellDataFeatures<ICFSecISOTZoneObj, Short> p ) {
				ICFSecISOTZoneObj obj = p.getValue();
				if( obj == null ) {
					return( null );
				}
				else {
					short value = obj.getRequiredTZHourOffset();
					Short wrapped = Short.valueOf( value );
					ReadOnlyObjectWrapper<Short> observable = new ReadOnlyObjectWrapper<Short>();
					observable.setValue( wrapped );
					return( observable );
				}
			}
		});
		tableColumnTZHourOffset.setCellFactory( new Callback<TableColumn<ICFSecISOTZoneObj,Short>,TableCell<ICFSecISOTZoneObj,Short>>() {
			@Override public TableCell<ICFSecISOTZoneObj,Short> call(
				TableColumn<ICFSecISOTZoneObj,Short> arg)
			{
				return new CFInt16TableCell<ICFSecISOTZoneObj>();
			}
		});
		dataTable.getColumns().add( tableColumnTZHourOffset );
		tableColumnTZMinOffset = new TableColumn<ICFSecISOTZoneObj,Short>( "Timezone Minute Offset" );
		tableColumnTZMinOffset.setCellValueFactory( new Callback<CellDataFeatures<ICFSecISOTZoneObj,Short>,ObservableValue<Short> >() {
			public ObservableValue<Short> call( CellDataFeatures<ICFSecISOTZoneObj, Short> p ) {
				ICFSecISOTZoneObj obj = p.getValue();
				if( obj == null ) {
					return( null );
				}
				else {
					short value = obj.getRequiredTZMinOffset();
					Short wrapped = Short.valueOf( value );
					ReadOnlyObjectWrapper<Short> observable = new ReadOnlyObjectWrapper<Short>();
					observable.setValue( wrapped );
					return( observable );
				}
			}
		});
		tableColumnTZMinOffset.setCellFactory( new Callback<TableColumn<ICFSecISOTZoneObj,Short>,TableCell<ICFSecISOTZoneObj,Short>>() {
			@Override public TableCell<ICFSecISOTZoneObj,Short> call(
				TableColumn<ICFSecISOTZoneObj,Short> arg)
			{
				return new CFInt16TableCell<ICFSecISOTZoneObj>();
			}
		});
		dataTable.getColumns().add( tableColumnTZMinOffset );
		tableColumnDescription = new TableColumn<ICFSecISOTZoneObj,String>( "Description" );
		tableColumnDescription.setCellValueFactory( new Callback<CellDataFeatures<ICFSecISOTZoneObj,String>,ObservableValue<String> >() {
			public ObservableValue<String> call( CellDataFeatures<ICFSecISOTZoneObj, String> p ) {
				ICFSecISOTZoneObj obj = p.getValue();
				if( obj == null ) {
					return( null );
				}
				else {
					String value = obj.getRequiredDescription();
					ReadOnlyObjectWrapper<String> observable = new ReadOnlyObjectWrapper<String>();
					observable.setValue( value );
					return( observable );
				}
			}
		});
		tableColumnDescription.setCellFactory( new Callback<TableColumn<ICFSecISOTZoneObj,String>,TableCell<ICFSecISOTZoneObj,String>>() {
			@Override public TableCell<ICFSecISOTZoneObj,String> call(
				TableColumn<ICFSecISOTZoneObj,String> arg)
			{
				return new CFStringTableCell<ICFSecISOTZoneObj>();
			}
		});
		dataTable.getColumns().add( tableColumnDescription );
		tableColumnVisible = new TableColumn<ICFSecISOTZoneObj,Boolean>( "Visible" );
		tableColumnVisible.setCellValueFactory( new Callback<CellDataFeatures<ICFSecISOTZoneObj,Boolean>,ObservableValue<Boolean> >() {
			public ObservableValue<Boolean> call( CellDataFeatures<ICFSecISOTZoneObj, Boolean> p ) {
				ICFSecISOTZoneObj obj = p.getValue();
				if( obj == null ) {
					return( null );
				}
				else {
					boolean value = obj.getRequiredVisible();
					Boolean wrapped = Boolean.valueOf( value );
					ReadOnlyObjectWrapper<Boolean> observable = new ReadOnlyObjectWrapper<Boolean>();
					observable.setValue( wrapped );
					return( observable );
				}
			}
		});
		tableColumnVisible.setCellFactory( new Callback<TableColumn<ICFSecISOTZoneObj,Boolean>,TableCell<ICFSecISOTZoneObj,Boolean>>() {
			@Override public TableCell<ICFSecISOTZoneObj,Boolean> call(
				TableColumn<ICFSecISOTZoneObj,Boolean> arg)
			{
				return new CFBoolTableCell<ICFSecISOTZoneObj>();
			}
		});
		dataTable.getColumns().add( tableColumnVisible );
		dataTable.getSelectionModel().selectedItemProperty().addListener(
			new ChangeListener<ICFSecISOTZoneObj>() {
				@Override public void changed( ObservableValue<? extends ICFSecISOTZoneObj> observable,
					ICFSecISOTZoneObj oldValue,
					ICFSecISOTZoneObj newValue )
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
		if( observableListOfISOTZone != null ) {
			dataTable.setItems( observableListOfISOTZone );
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
		if( ( value == null ) || ( value instanceof ICFSecISOTZoneObj ) ) {
			super.setJavaFXFocus( value );
		}
		else {
			throw new CFLibUnsupportedClassException( getClass(),
				S_ProcName,
				"value",
				value,
				"ICFSecISOTZoneObj" );
		}
		adjustListButtons();
	}

	public ICFSecISOTZoneObj getJavaFXFocusAsISOTZone() {
		return( (ICFSecISOTZoneObj)getJavaFXFocus() );
	}

	public void setJavaFXFocusAsISOTZone( ICFSecISOTZoneObj value ) {
		setJavaFXFocus( value );
	}

	public class ISOTZoneByQualNameComparator
	implements Comparator<ICFSecISOTZoneObj>
	{
		public ISOTZoneByQualNameComparator() {
		}

		public int compare( ICFSecISOTZoneObj lhs, ICFSecISOTZoneObj rhs ) {
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

	protected ISOTZoneByQualNameComparator compareISOTZoneByQualName = new ISOTZoneByQualNameComparator();

	public Collection<ICFSecISOTZoneObj> getJavaFXDataCollection() {
		return( javafxDataCollection );
	}

	public void setJavaFXDataCollection( Collection<ICFSecISOTZoneObj> value ) {
		final String S_ProcName = "setJavaFXDataCollection";
		javafxDataCollection = value;
		observableListOfISOTZone = FXCollections.observableArrayList();
		if( javafxDataCollection != null ) {
				Iterator<ICFSecISOTZoneObj> iter = javafxDataCollection.iterator();
				while( iter.hasNext() ) {
					observableListOfISOTZone.add( iter.next() );
				}
				observableListOfISOTZone.sort( compareISOTZoneByQualName );
		}
		if( dataTable != null ) {
			dataTable.setItems( observableListOfISOTZone );
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
			buttonAddISOTZone = new CFButton();
			buttonAddISOTZone.setMinWidth( 200 );
			buttonAddISOTZone.setText( "Add ISO Timezone" );
			buttonAddISOTZone.setOnAction( new EventHandler<ActionEvent>() {
				@Override public void handle( ActionEvent e ) {
					final String S_ProcName = "handle";
					try {
						ICFSecSchemaObj schemaObj = (ICFSecSchemaObj)javafxSchema.getSchema();
						ICFSecISOTZoneObj obj = (ICFSecISOTZoneObj)schemaObj.getISOTZoneTableObj().newInstance();
						ICFSecISOTZoneEditObj edit = (ICFSecISOTZoneEditObj)( obj.beginEdit() );
						if( edit == null ) {
							throw new CFLibNullArgumentException( getClass(),
								S_ProcName,
								0,
								"edit" );
						}
						CFBorderPane frame = javafxSchema.getISOTZoneFactory().newAddForm( cfFormManager, obj, getViewEditClosedCallback(), true );
						ICFSecJavaFXISOTZonePaneCommon jpanelCommon = (ICFSecJavaFXISOTZonePaneCommon)frame;
						jpanelCommon.setJavaFXFocus( obj );
						jpanelCommon.setPaneMode( CFPane.PaneMode.Add );
						cfFormManager.pushForm( frame );
					}
					catch( Throwable t ) {
						CFConsole.formException( S_FormName, ((CFButton)e.getSource()).getText(), t );
					}
				}
			});
			hboxMenu.getChildren().add( buttonAddISOTZone );
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
						ICFSecISOTZoneObj selectedInstance = getJavaFXFocusAsISOTZone();
						if( selectedInstance != null ) {
							String classCode = selectedInstance.getClassCode();
							if( "a008".equals( classCode ) ) {
								CFBorderPane frame = javafxSchema.getISOTZoneFactory().newViewEditForm( cfFormManager, selectedInstance, getViewEditClosedCallback(), false );
								((ICFSecJavaFXISOTZonePaneCommon)frame).setPaneMode( CFPane.PaneMode.View );
								cfFormManager.pushForm( frame );
							}
							else {
								throw new CFLibUnsupportedClassException( getClass(),
									S_ProcName,
									"selectedInstance",
									selectedInstance,
									"ICFSecISOTZoneObj" );
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
						ICFSecISOTZoneObj selectedInstance = getJavaFXFocusAsISOTZone();
						if( selectedInstance != null ) {
							String classCode = selectedInstance.getClassCode();
							if( "a008".equals( classCode ) ) {
								CFBorderPane frame = javafxSchema.getISOTZoneFactory().newViewEditForm( cfFormManager, selectedInstance, getViewEditClosedCallback(), false );
								((ICFSecJavaFXISOTZonePaneCommon)frame).setPaneMode( CFPane.PaneMode.Edit );
								cfFormManager.pushForm( frame );
							}
							else {
								throw new CFLibUnsupportedClassException( getClass(),
									S_ProcName,
									"selectedInstance",
									selectedInstance,
									"ICFSecISOTZoneObj" );
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
						ICFSecISOTZoneObj selectedInstance = getJavaFXFocusAsISOTZone();
						if( selectedInstance != null ) {
							String classCode = selectedInstance.getClassCode();
							if( "a008".equals( classCode ) ) {
								CFBorderPane frame = javafxSchema.getISOTZoneFactory().newAskDeleteForm( cfFormManager, selectedInstance, getDeleteCallback() );
								((ICFSecJavaFXISOTZonePaneCommon)frame).setPaneMode( CFPane.PaneMode.View );
								cfFormManager.pushForm( frame );
							}
							else {
								throw new CFLibUnsupportedClassException( getClass(),
									S_ProcName,
									"selectedInstance",
									selectedInstance,
									"ICFSecISOTZoneObj" );
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
		ICFSecISOTZoneObj selectedObj = getJavaFXFocusAsISOTZone();
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
		if( buttonAddISOTZone != null ) {
			buttonAddISOTZone.setDisable( ! allowAdds );
		}

	}
}
