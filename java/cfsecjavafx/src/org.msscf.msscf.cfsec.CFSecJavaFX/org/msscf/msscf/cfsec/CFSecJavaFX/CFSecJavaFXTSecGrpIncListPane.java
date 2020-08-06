// Description: Java 11 JavaFX List of Obj Pane implementation for TSecGrpInc.

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
import org.msscf.msscf.cflib.CFLib.*;
import org.msscf.msscf.cflib.CFLib.JavaFX.*;
import org.apache.commons.codec.binary.Base64;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfsec.CFSecObj.*;

/**
 *	CFSecJavaFXTSecGrpIncListPane JavaFX List of Obj Pane implementation
 *	for TSecGrpInc.
 */
public class CFSecJavaFXTSecGrpIncListPane
extends CFBorderPane
implements ICFSecJavaFXTSecGrpIncPaneList
{
	public static String S_FormName = "List Tenant Security Group Include";
	protected ICFSecJavaFXSchema javafxSchema = null;
	protected ICFSecJavaFXTSecGrpIncPageCallback pageCallback;
	protected CFButton buttonRefresh = null;
	protected CFButton buttonMoreData = null;
	protected boolean endOfData = true;
	protected ObservableList<ICFSecTSecGrpIncObj> observableListOfTSecGrpInc = null;
	protected ScrollPane scrollMenu = null;
	protected CFHBox hboxMenu = null;
	protected CFButton buttonAddTSecGrpInc = null;
	protected CFButton buttonViewSelected = null;
	protected CFButton buttonEditSelected = null;
	protected CFButton buttonDeleteSelected = null;
	protected TableView<ICFSecTSecGrpIncObj> dataTable = null;
	protected TableColumn<ICFSecTSecGrpIncObj, Long> tableColumnTSecGrpIncId = null;
	protected TableColumn<ICFSecTSecGrpIncObj, ICFSecTSecGroupObj> tableColumnParentSubGroup = null;

	public final String S_ColumnNames[] = { "Name" };
	protected ICFFormManager cfFormManager = null;
	protected boolean javafxIsInitializing = true;
	protected boolean javafxSortByChain = false;
	protected ICFSecTSecGroupObj javafxContainer = null;
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


	public CFSecJavaFXTSecGrpIncListPane( ICFFormManager formManager,
		ICFSecJavaFXSchema argSchema,
		ICFSecTSecGroupObj argContainer,
		ICFSecTSecGrpIncObj argFocus,
		ICFSecJavaFXTSecGrpIncPageCallback argPageCallback,
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
		if( observableListOfTSecGrpInc != null ) {
			dataTable.setItems( observableListOfTSecGrpInc );
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
		adjustListButtons();
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
			buttonRefresh = new CFButton();
			buttonRefresh.setMinWidth( 200 );
			buttonRefresh.setText( "Refresh" );
			buttonRefresh.setOnAction( new EventHandler<ActionEvent>() {
				@Override public void handle( ActionEvent e ) {
					final String S_ProcName = "handle";
					try {
						refreshMe();
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

			buttonAddTSecGrpInc = new CFButton();
			buttonAddTSecGrpInc.setMinWidth( 200 );
			buttonAddTSecGrpInc.setText( "Add Tenant Security Group Include" );
			buttonAddTSecGrpInc.setOnAction( new EventHandler<ActionEvent>() {
				@Override public void handle( ActionEvent e ) {
					final String S_ProcName = "handle";
					try {
						ICFSecSchemaObj schemaObj = (ICFSecSchemaObj)javafxSchema.getSchema();
						ICFSecTSecGrpIncObj obj = (ICFSecTSecGrpIncObj)schemaObj.getTSecGrpIncTableObj().newInstance();
						ICFSecTSecGrpIncEditObj edit = (ICFSecTSecGrpIncEditObj)( obj.beginEdit() );
						if( edit == null ) {
							throw new CFLibNullArgumentException( getClass(),
								S_ProcName,
								0,
								"edit" );
						}
								ICFSecTenantObj secTenant = schemaObj.getSecTenant();
								edit.setRequiredOwnerTenant( secTenant );
								ICFSecTSecGroupObj container = (ICFSecTSecGroupObj)( getJavaFXContainer() );
								if( container == null ) {
									throw new CFLibNullArgumentException( getClass(),
										S_ProcName,
										0,
										"JavaFXContainer" );
								}
								edit.setRequiredContainerGroup( container );
						CFBorderPane frame = javafxSchema.getTSecGrpIncFactory().newAddForm( cfFormManager, obj, getViewEditClosedCallback(), true );
						ICFSecJavaFXTSecGrpIncPaneCommon jpanelCommon = (ICFSecJavaFXTSecGrpIncPaneCommon)frame;
						jpanelCommon.setJavaFXFocus( obj );
						jpanelCommon.setPaneMode( CFPane.PaneMode.Add );
						cfFormManager.pushForm( frame );
					}
					catch( Throwable t ) {
						CFConsole.formException( S_FormName, ((CFButton)e.getSource()).getText(), t );
					}
				}
			});
			hboxMenu.getChildren().add( buttonAddTSecGrpInc );
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
						ICFSecTSecGrpIncObj selectedInstance = getJavaFXFocusAsTSecGrpInc();
						if( selectedInstance != null ) {
							String classCode = selectedInstance.getClassCode();
							if( "a017".equals( classCode ) ) {
								CFBorderPane frame = javafxSchema.getTSecGrpIncFactory().newViewEditForm( cfFormManager, selectedInstance, getViewEditClosedCallback(), false );
								((ICFSecJavaFXTSecGrpIncPaneCommon)frame).setPaneMode( CFPane.PaneMode.View );
								cfFormManager.pushForm( frame );
							}
							else {
								throw new CFLibUnsupportedClassException( getClass(),
									S_ProcName,
									"selectedInstance",
									selectedInstance,
									"ICFSecTSecGrpIncObj" );
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
						ICFSecTSecGrpIncObj selectedInstance = getJavaFXFocusAsTSecGrpInc();
						if( selectedInstance != null ) {
							String classCode = selectedInstance.getClassCode();
							if( "a017".equals( classCode ) ) {
								CFBorderPane frame = javafxSchema.getTSecGrpIncFactory().newViewEditForm( cfFormManager, selectedInstance, getViewEditClosedCallback(), false );
								((ICFSecJavaFXTSecGrpIncPaneCommon)frame).setPaneMode( CFPane.PaneMode.Edit );
								cfFormManager.pushForm( frame );
							}
							else {
								throw new CFLibUnsupportedClassException( getClass(),
									S_ProcName,
									"selectedInstance",
									selectedInstance,
									"ICFSecTSecGrpIncObj" );
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
						ICFSecTSecGrpIncObj selectedInstance = getJavaFXFocusAsTSecGrpInc();
						if( selectedInstance != null ) {
							String classCode = selectedInstance.getClassCode();
							if( "a017".equals( classCode ) ) {
								CFBorderPane frame = javafxSchema.getTSecGrpIncFactory().newAskDeleteForm( cfFormManager, selectedInstance, getDeleteCallback() );
								((ICFSecJavaFXTSecGrpIncPaneCommon)frame).setPaneMode( CFPane.PaneMode.View );
								cfFormManager.pushForm( frame );
							}
							else {
								throw new CFLibUnsupportedClassException( getClass(),
									S_ProcName,
									"selectedInstance",
									selectedInstance,
									"ICFSecTSecGrpIncObj" );
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

	public ICFSecTSecGroupObj getJavaFXContainer() {
		return( javafxContainer );
	}

	public void setJavaFXContainer( ICFSecTSecGroupObj value ) {
		javafxContainer = value;
	}

	public void refreshMe() {
		final String S_ProcName = "refreshMe";
		observableListOfTSecGrpInc = FXCollections.observableArrayList();
		if( javafxContainer != null ) {
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
		}
		else {
			endOfData = true;
		}
		if( dataTable != null ) {
			dataTable.setItems( observableListOfTSecGrpInc );
			// Hack from stackoverflow to fix JavaFX TableView refresh issue
			((TableColumn)dataTable.getColumns().get(0)).setVisible( false );
			((TableColumn)dataTable.getColumns().get(0)).setVisible( true );
		}
		adjustListButtons();
	}

	public void adjustListButtons() {
		boolean enableState;
		boolean inEditState;
		boolean allowAdds;
		boolean inAddMode = false;
		ICFSecTSecGrpIncObj selectedObj = getJavaFXFocusAsTSecGrpInc();
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

		if( buttonRefresh != null ) {
			buttonRefresh.setDisable( false );
		}
		if( buttonMoreData != null ) {
			buttonMoreData.setDisable( endOfData );
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
		if( buttonAddTSecGrpInc != null ) {
			buttonAddTSecGrpInc.setDisable( ! allowAdds );
		}

	}
}
