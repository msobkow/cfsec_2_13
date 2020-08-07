// Description: Java 11 JavaFX Picker of Obj Pane implementation for SecGrpInc.

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
 *	CFSecJavaFXSecGrpIncPickerPane JavaFX Pick Obj Pane implementation
 *	for SecGrpInc.
 */
public class CFSecJavaFXSecGrpIncPickerPane
extends CFBorderPane
implements ICFSecJavaFXSecGrpIncPaneList
{
	public static String S_FormName = "Choose Security Group Include";
	protected ICFSecJavaFXSchema javafxSchema = null;
	protected ICFSecJavaFXSecGrpIncPageCallback pageCallback;
	protected CFButton buttonRefresh = null;
	protected CFButton buttonMoreData = null;
	protected boolean endOfData = true;
	protected ObservableList<ICFSecSecGrpIncObj> observableListOfSecGrpInc = null;
	protected TableColumn<ICFSecSecGrpIncObj, Long> tableColumnSecGrpIncId = null;
	protected TableColumn<ICFSecSecGrpIncObj, ICFSecSecGroupObj> tableColumnParentSubGroup = null;
	protected TableView<ICFSecSecGrpIncObj> dataTable = null;
	protected CFHBox hboxMenu = null;
	public final String S_ColumnNames[] = { "Name" };
	protected ICFFormManager cfFormManager = null;
	protected ICFSecJavaFXSecGrpIncChosen invokeWhenChosen = null;
	protected ICFSecSecGroupObj javafxContainer = null;
	protected CFButton buttonCancel = null;
	protected CFButton buttonChooseNone = null;
	protected CFButton buttonChooseSelected = null;
	protected ScrollPane scrollMenu = null;
	public CFSecJavaFXSecGrpIncPickerPane( ICFFormManager formManager,
		ICFSecJavaFXSchema argSchema,
		ICFSecSecGrpIncObj argFocus,
		ICFSecSecGroupObj argContainer,
		ICFSecJavaFXSecGrpIncPageCallback argPageCallback,
		ICFSecJavaFXSecGrpIncChosen whenChosen )
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
		dataTable = new TableView<ICFSecSecGrpIncObj>();
		tableColumnSecGrpIncId = new TableColumn<ICFSecSecGrpIncObj,Long>( "Security Group Include Id" );
		tableColumnSecGrpIncId.setCellValueFactory( new Callback<CellDataFeatures<ICFSecSecGrpIncObj,Long>,ObservableValue<Long> >() {
			public ObservableValue<Long> call( CellDataFeatures<ICFSecSecGrpIncObj, Long> p ) {
				ICFSecSecGrpIncObj obj = p.getValue();
				if( obj == null ) {
					return( null );
				}
				else {
					long value = obj.getRequiredSecGrpIncId();
					Long wrapped = Long.valueOf( value );
					ReadOnlyObjectWrapper<Long> observable = new ReadOnlyObjectWrapper<Long>();
					observable.setValue( wrapped );
					return( observable );
				}
			}
		});
		tableColumnSecGrpIncId.setCellFactory( new Callback<TableColumn<ICFSecSecGrpIncObj,Long>,TableCell<ICFSecSecGrpIncObj,Long>>() {
			@Override public TableCell<ICFSecSecGrpIncObj,Long> call(
				TableColumn<ICFSecSecGrpIncObj,Long> arg)
			{
				return new CFInt64TableCell<ICFSecSecGrpIncObj>();
			}
		});
		dataTable.getColumns().add( tableColumnSecGrpIncId );
		tableColumnParentSubGroup = new TableColumn<ICFSecSecGrpIncObj, ICFSecSecGroupObj>( "SubGroup" );
		tableColumnParentSubGroup.setCellValueFactory( new Callback<CellDataFeatures<ICFSecSecGrpIncObj,ICFSecSecGroupObj>,ObservableValue<ICFSecSecGroupObj> >() {
			public ObservableValue<ICFSecSecGroupObj> call( CellDataFeatures<ICFSecSecGrpIncObj, ICFSecSecGroupObj> p ) {
				ICFSecSecGrpIncObj obj = p.getValue();
				if( obj == null ) {
					return( null );
				}
				else {
					ICFSecSecGroupObj ref = obj.getRequiredParentSubGroup();
					ReadOnlyObjectWrapper<ICFSecSecGroupObj> observable = new ReadOnlyObjectWrapper<ICFSecSecGroupObj>();
					observable.setValue( ref );
					return( observable );
				}
			}
		});
		tableColumnParentSubGroup.setCellFactory( new Callback<TableColumn<ICFSecSecGrpIncObj,ICFSecSecGroupObj>,TableCell<ICFSecSecGrpIncObj,ICFSecSecGroupObj>>() {
			@Override public TableCell<ICFSecSecGrpIncObj,ICFSecSecGroupObj> call(
				TableColumn<ICFSecSecGrpIncObj,ICFSecSecGroupObj> arg)
			{
				return new CFReferenceTableCell<ICFSecSecGrpIncObj,ICFSecSecGroupObj>();
			}
		});
		dataTable.getColumns().add( tableColumnParentSubGroup );
		dataTable.getSelectionModel().selectedItemProperty().addListener(
			new ChangeListener<ICFSecSecGrpIncObj>() {
				@Override public void changed( ObservableValue<? extends ICFSecSecGrpIncObj> observable,
					ICFSecSecGrpIncObj oldValue,
					ICFSecSecGrpIncObj newValue )
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
						observableListOfSecGrpInc = FXCollections.observableArrayList();
						List<ICFSecSecGrpIncObj> page = pageCallback.pageData( null,
							null );
						Iterator<ICFSecSecGrpIncObj> iter = page.iterator();
						while( iter.hasNext() ) {
							observableListOfSecGrpInc.add( iter.next() );
						}
						if( page.size() < 25 ) {
							observableListOfSecGrpInc.sort( compareSecGrpIncByQualName );
							endOfData = true;
						}
						else {
							endOfData = false;
						}
						if( dataTable != null ) {
							dataTable.setItems( observableListOfSecGrpInc );
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
						ICFSecSecGrpIncObj lastObj = null;
						if( ( observableListOfSecGrpInc != null ) && ( observableListOfSecGrpInc.size() > 0 ) ) {
							lastObj = observableListOfSecGrpInc.get( observableListOfSecGrpInc.size() - 1 );
						}
						List<ICFSecSecGrpIncObj> page;
						if( lastObj != null ) {
							page = pageCallback.pageData( lastObj.getRequiredClusterId(),
							lastObj.getRequiredSecGrpIncId() );
						}
						else {
							page = pageCallback.pageData( null,
							null );
						}
						Iterator<ICFSecSecGrpIncObj> iter = page.iterator();
						while( iter.hasNext() ) {
							observableListOfSecGrpInc.add( iter.next() );
						}
						if( page.size() < 25 ) {
							observableListOfSecGrpInc.sort( compareSecGrpIncByQualName );
							endOfData = true;
						}
						else {
							endOfData = false;
						}
						if( dataTable != null ) {
							dataTable.setItems( observableListOfSecGrpInc );
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
					invokeWhenChosen.choseSecGrpInc( null );
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
					ICFSecSecGrpIncObj selectedInstance = getJavaFXFocusAsSecGrpInc();
					invokeWhenChosen.choseSecGrpInc( selectedInstance );
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
		if( ( value == null ) || ( value instanceof ICFSecSecGrpIncObj ) ) {
			super.setJavaFXFocus( value );
		}
		else {
			throw new CFLibUnsupportedClassException( getClass(),
				S_ProcName,
				"value",
				value,
				"ICFSecSecGrpIncObj" );
		}
		if( dataTable == null ) {
			return;
		}
	}

	public ICFSecSecGrpIncObj getJavaFXFocusAsSecGrpInc() {
		return( (ICFSecSecGrpIncObj)getJavaFXFocus() );
	}

	public void setJavaFXFocusAsSecGrpInc( ICFSecSecGrpIncObj value ) {
		setJavaFXFocus( value );
	}

	public class SecGrpIncByQualNameComparator
	implements Comparator<ICFSecSecGrpIncObj>
	{
		public SecGrpIncByQualNameComparator() {
		}

		public int compare( ICFSecSecGrpIncObj lhs, ICFSecSecGrpIncObj rhs ) {
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

	protected SecGrpIncByQualNameComparator compareSecGrpIncByQualName = new SecGrpIncByQualNameComparator();

	public Collection<ICFSecSecGrpIncObj> getJavaFXDataCollection() {
		return( null );
	}

	public void setJavaFXDataCollection( Collection<ICFSecSecGrpIncObj> value ) {
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
		ICFSecSecGrpIncObj selectedObj = getJavaFXFocusAsSecGrpInc();
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

