// Description: Java 11 JavaFX Picker of Obj Pane implementation for TSecGrpInc.

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
 *	CFSecJavaFXTSecGrpIncPickerPane JavaFX Pick Obj Pane implementation
 *	for TSecGrpInc.
 */
public class CFSecJavaFXTSecGrpIncPickerPane
extends CFBorderPane
implements ICFSecJavaFXTSecGrpIncPaneList
{
	public static String S_FormName = "Choose Tenant Security Group Include";
	protected ICFSecJavaFXSchema javafxSchema = null;
	protected ICFSecJavaFXTSecGrpIncPageCallback pageCallback;
	protected CFButton buttonRefresh = null;
	protected CFButton buttonMoreData = null;
	protected boolean endOfData = true;
	protected ObservableList<ICFSecTSecGrpIncObj> observableListOfTSecGrpInc = null;
	protected TableColumn<ICFSecTSecGrpIncObj, Long> tableColumnTSecGrpIncId = null;
	protected TableColumn<ICFSecTSecGrpIncObj, ICFSecTSecGroupObj> tableColumnParentSubGroup = null;
	protected TableView<ICFSecTSecGrpIncObj> dataTable = null;
	protected CFHBox hboxMenu = null;
	public final String S_ColumnNames[] = { "Name" };
	protected ICFFormManager cfFormManager = null;
	protected ICFSecJavaFXTSecGrpIncChosen invokeWhenChosen = null;
	protected ICFSecTSecGroupObj javafxContainer = null;
	protected CFButton buttonCancel = null;
	protected CFButton buttonChooseNone = null;
	protected CFButton buttonChooseSelected = null;
	protected ScrollPane scrollMenu = null;
	public CFSecJavaFXTSecGrpIncPickerPane( ICFFormManager formManager,
		ICFSecJavaFXSchema argSchema,
		ICFSecTSecGrpIncObj argFocus,
		ICFSecTSecGroupObj argContainer,
		ICFSecJavaFXTSecGrpIncPageCallback argPageCallback,
		ICFSecJavaFXTSecGrpIncChosen whenChosen )
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
		dataTable = new TableView<ICFSecTSecGrpIncObj>();
		tableColumnTSecGrpIncId = new TableColumn<ICFSecTSecGrpIncObj,Long>( "TSecurity Group Include Id" );
		tableColumnTSecGrpIncId.setCellValueFactory( new Callback<CellDataFeatures<ICFSecTSecGrpIncObj,Long>,ObservableValue<Long> >() {
			public ObservableValue<Long> call( CellDataFeatures<ICFSecTSecGrpIncObj, Long> p ) {
				ICFSecTSecGrpIncObj obj = p.getValue();
				if( obj == null ) {
					return( null );
				}
				else {
					long value = obj.getRequiredTSecGrpIncId();
					Long wrapped = Long.valueOf( value );
					ReadOnlyObjectWrapper<Long> observable = new ReadOnlyObjectWrapper<Long>();
					observable.setValue( wrapped );
					return( observable );
				}
			}
		});
		tableColumnTSecGrpIncId.setCellFactory( new Callback<TableColumn<ICFSecTSecGrpIncObj,Long>,TableCell<ICFSecTSecGrpIncObj,Long>>() {
			@Override public TableCell<ICFSecTSecGrpIncObj,Long> call(
				TableColumn<ICFSecTSecGrpIncObj,Long> arg)
			{
				return new CFInt64TableCell<ICFSecTSecGrpIncObj>();
			}
		});
		dataTable.getColumns().add( tableColumnTSecGrpIncId );
		tableColumnParentSubGroup = new TableColumn<ICFSecTSecGrpIncObj, ICFSecTSecGroupObj>( "SubGroup" );
		tableColumnParentSubGroup.setCellValueFactory( new Callback<CellDataFeatures<ICFSecTSecGrpIncObj,ICFSecTSecGroupObj>,ObservableValue<ICFSecTSecGroupObj> >() {
			public ObservableValue<ICFSecTSecGroupObj> call( CellDataFeatures<ICFSecTSecGrpIncObj, ICFSecTSecGroupObj> p ) {
				ICFSecTSecGrpIncObj obj = p.getValue();
				if( obj == null ) {
					return( null );
				}
				else {
					ICFSecTSecGroupObj ref = obj.getRequiredParentSubGroup();
					ReadOnlyObjectWrapper<ICFSecTSecGroupObj> observable = new ReadOnlyObjectWrapper<ICFSecTSecGroupObj>();
					observable.setValue( ref );
					return( observable );
				}
			}
		});
		tableColumnParentSubGroup.setCellFactory( new Callback<TableColumn<ICFSecTSecGrpIncObj,ICFSecTSecGroupObj>,TableCell<ICFSecTSecGrpIncObj,ICFSecTSecGroupObj>>() {
			@Override public TableCell<ICFSecTSecGrpIncObj,ICFSecTSecGroupObj> call(
				TableColumn<ICFSecTSecGrpIncObj,ICFSecTSecGroupObj> arg)
			{
				return new CFReferenceTableCell<ICFSecTSecGrpIncObj,ICFSecTSecGroupObj>();
			}
		});
		dataTable.getColumns().add( tableColumnParentSubGroup );
		dataTable.getSelectionModel().selectedItemProperty().addListener(
			new ChangeListener<ICFSecTSecGrpIncObj>() {
				@Override public void changed( ObservableValue<? extends ICFSecTSecGrpIncObj> observable,
					ICFSecTSecGrpIncObj oldValue,
					ICFSecTSecGrpIncObj newValue )
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
						observableListOfTSecGrpInc = FXCollections.observableArrayList();
						List<ICFSecTSecGrpIncObj> page = pageCallback.pageData( null,
							null );
						Iterator<ICFSecTSecGrpIncObj> iter = page.iterator();
						while( iter.hasNext() ) {
							observableListOfTSecGrpInc.add( iter.next() );
						}
						if( page.size() < 25 ) {
							observableListOfTSecGrpInc.sort( compareTSecGrpIncByQualName );
							endOfData = true;
						}
						else {
							endOfData = false;
						}
						if( dataTable != null ) {
							dataTable.setItems( observableListOfTSecGrpInc );
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
						ICFSecTSecGrpIncObj lastObj = null;
						if( ( observableListOfTSecGrpInc != null ) && ( observableListOfTSecGrpInc.size() > 0 ) ) {
							lastObj = observableListOfTSecGrpInc.get( observableListOfTSecGrpInc.size() - 1 );
						}
						List<ICFSecTSecGrpIncObj> page;
						if( lastObj != null ) {
							page = pageCallback.pageData( lastObj.getRequiredTenantId(),
							lastObj.getRequiredTSecGrpIncId() );
						}
						else {
							page = pageCallback.pageData( null,
							null );
						}
						Iterator<ICFSecTSecGrpIncObj> iter = page.iterator();
						while( iter.hasNext() ) {
							observableListOfTSecGrpInc.add( iter.next() );
						}
						if( page.size() < 25 ) {
							observableListOfTSecGrpInc.sort( compareTSecGrpIncByQualName );
							endOfData = true;
						}
						else {
							endOfData = false;
						}
						if( dataTable != null ) {
							dataTable.setItems( observableListOfTSecGrpInc );
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
					invokeWhenChosen.choseTSecGrpInc( null );
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
					ICFSecTSecGrpIncObj selectedInstance = getJavaFXFocusAsTSecGrpInc();
					invokeWhenChosen.choseTSecGrpInc( selectedInstance );
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
		if( ( value == null ) || ( value instanceof ICFSecTSecGrpIncObj ) ) {
			super.setJavaFXFocus( value );
		}
		else {
			throw new CFLibUnsupportedClassException( getClass(),
				S_ProcName,
				"value",
				value,
				"ICFSecTSecGrpIncObj" );
		}
		if( dataTable == null ) {
			return;
		}
	}

	public ICFSecTSecGrpIncObj getJavaFXFocusAsTSecGrpInc() {
		return( (ICFSecTSecGrpIncObj)getJavaFXFocus() );
	}

	public void setJavaFXFocusAsTSecGrpInc( ICFSecTSecGrpIncObj value ) {
		setJavaFXFocus( value );
	}

	public class TSecGrpIncByQualNameComparator
	implements Comparator<ICFSecTSecGrpIncObj>
	{
		public TSecGrpIncByQualNameComparator() {
		}

		public int compare( ICFSecTSecGrpIncObj lhs, ICFSecTSecGrpIncObj rhs ) {
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

	protected TSecGrpIncByQualNameComparator compareTSecGrpIncByQualName = new TSecGrpIncByQualNameComparator();

	public Collection<ICFSecTSecGrpIncObj> getJavaFXDataCollection() {
		return( null );
	}

	public void setJavaFXDataCollection( Collection<ICFSecTSecGrpIncObj> value ) {
		// Use page data instead
	}

	public ICFSecTSecGroupObj getJavaFXContainer() {
		return( javafxContainer );
	}

	public void setJavaFXContainer( ICFSecTSecGroupObj value ) {
		javafxContainer = value;
	}

	public void adjustListButtons() {
		boolean enableState;
		ICFSecTSecGrpIncObj selectedObj = getJavaFXFocusAsTSecGrpInc();
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

