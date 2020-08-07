// Description: Java 11 JavaFX Finder Form implementation for Tenant.

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
import javafx.geometry.Pos;
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
 *	CFSecJavaFXTenantFinderForm JavaFX Finder Form implementation
 *	for Tenant.
 */
public class CFSecJavaFXTenantFinderForm
extends CFBorderPane
implements ICFSecJavaFXTenantPaneCommon,
	ICFForm
{
	public static String S_FormName = "Find Tenant";
	protected ICFFormManager cfFormManager = null;
	protected ICFSecJavaFXSchema javafxSchema = null;
	protected boolean javafxIsInitializing = true;
	protected ICFSecClusterObj containingCluster = null;
	protected ScrollPane scrollMenu = null;
	protected CFHBox hboxMenu = null;
	protected CFVBox vboxMenuAdd = null;
	protected ScrollPane scrollMenuAdd = null;
	protected CFButton buttonAdd = null;
	protected CFButton buttonCancelAdd = null;
	protected CFButton buttonAddTenant = null;
	protected CFButton buttonViewSelected = null;
	protected CFButton buttonEditSelected = null;
	protected CFButton buttonClose = null;
	protected CFButton buttonDeleteSelected = null;
	protected ICFSecJavaFXTenantPageCallback pageCallback = null;
	protected CFButton buttonRefresh = null;
	protected CFButton buttonMoreData = null;
	protected boolean endOfData = true;
	protected ObservableList<ICFSecTenantObj> observableListOfTenant = null;
	protected TableColumn<ICFSecTenantObj, Long> tableColumnId = null;
	protected TableColumn<ICFSecTenantObj, String> tableColumnTenantName = null;
	protected TableView<ICFSecTenantObj> dataTable = null;

	protected class PageDataTenantList
	implements ICFSecJavaFXTenantPageCallback
	{
		public PageDataTenantList() {
		}

		public List<ICFSecTenantObj> pageData( Long priorId )
		{
			List<ICFSecTenantObj> dataList;
			ICFSecSchemaObj schemaObj = (ICFSecSchemaObj)javafxSchema.getSchema();
			if( containingCluster == null ) {
				CFSecAuthorization auth = schemaObj.getAuthorization();
				long containingClusterId = auth.getSecClusterId();
				containingCluster = schemaObj.getClusterTableObj().readClusterByIdIdx( containingClusterId );
			}
			dataList = schemaObj.getTenantTableObj().pageTenantByClusterIdx( containingCluster.getRequiredId(),
					priorId );
			return( dataList );
		}
	}

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

	public CFSecJavaFXTenantFinderForm( ICFFormManager formManager, ICFSecJavaFXSchema argSchema ) {
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
		pageCallback = new PageDataTenantList();
		dataTable = new TableView<ICFSecTenantObj>();
		tableColumnId = new TableColumn<ICFSecTenantObj,Long>( "Id" );
		tableColumnId.setCellValueFactory( new Callback<CellDataFeatures<ICFSecTenantObj,Long>,ObservableValue<Long> >() {
			public ObservableValue<Long> call( CellDataFeatures<ICFSecTenantObj, Long> p ) {
				ICFSecTenantObj obj = p.getValue();
				if( obj == null ) {
					return( null );
				}
				else {
					long value = obj.getRequiredId();
					Long wrapped = Long.valueOf( value );
					ReadOnlyObjectWrapper<Long> observable = new ReadOnlyObjectWrapper<Long>();
					observable.setValue( wrapped );
					return( observable );
				}
			}
		});
		tableColumnId.setCellFactory( new Callback<TableColumn<ICFSecTenantObj,Long>,TableCell<ICFSecTenantObj,Long>>() {
			@Override public TableCell<ICFSecTenantObj,Long> call(
				TableColumn<ICFSecTenantObj,Long> arg)
			{
				return new CFInt64TableCell<ICFSecTenantObj>();
			}
		});
		dataTable.getColumns().add( tableColumnId );
		tableColumnTenantName = new TableColumn<ICFSecTenantObj,String>( "TenantName" );
		tableColumnTenantName.setCellValueFactory( new Callback<CellDataFeatures<ICFSecTenantObj,String>,ObservableValue<String> >() {
			public ObservableValue<String> call( CellDataFeatures<ICFSecTenantObj, String> p ) {
				ICFSecTenantObj obj = p.getValue();
				if( obj == null ) {
					return( null );
				}
				else {
					String value = obj.getRequiredTenantName();
					ReadOnlyObjectWrapper<String> observable = new ReadOnlyObjectWrapper<String>();
					observable.setValue( value );
					return( observable );
				}
			}
		});
		tableColumnTenantName.setCellFactory( new Callback<TableColumn<ICFSecTenantObj,String>,TableCell<ICFSecTenantObj,String>>() {
			@Override public TableCell<ICFSecTenantObj,String> call(
				TableColumn<ICFSecTenantObj,String> arg)
			{
				return new CFStringTableCell<ICFSecTenantObj>();
			}
		});
		dataTable.getColumns().add( tableColumnTenantName );
		dataTable.getSelectionModel().selectedItemProperty().addListener(
			new ChangeListener<ICFSecTenantObj>() {
				@Override public void changed( ObservableValue<? extends ICFSecTenantObj> observable,
					ICFSecTenantObj oldValue,
					ICFSecTenantObj newValue )
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
						ICFSecTenantObj lastObj = null;
						if( ( observableListOfTenant != null ) && ( observableListOfTenant.size() > 0 ) ) {
							lastObj = observableListOfTenant.get( observableListOfTenant.size() - 1 );
						}
						List<ICFSecTenantObj> page;
						if( lastObj != null ) {
							page = pageCallback.pageData( lastObj.getRequiredId() );
						}
						else {
							page = pageCallback.pageData( null );
						}
						Iterator<ICFSecTenantObj> iter = page.iterator();
						while( iter.hasNext() ) {
							observableListOfTenant.add( iter.next() );
						}
						if( page.size() < 25 ) {
							observableListOfTenant.sort( compareTenantByQualName );
							endOfData = true;
						}
						else {
							endOfData = false;
						}
						if( dataTable != null ) {
							dataTable.setItems( observableListOfTenant );
							// Hack from stackoverflow to fix JavaFX TableView refresh issue
							((TableColumn)dataTable.getColumns().get(0)).setVisible( false );
							((TableColumn)dataTable.getColumns().get(0)).setVisible( true );
						}
						adjustFinderButtons();
					}
					catch( Throwable t ) {
						CFConsole.formException( S_FormName, ((CFButton)e.getSource()).getText(), t );
					}
				}
			});
			hboxMenu.getChildren().add( buttonMoreData );

			buttonAddTenant = new CFButton();
			buttonAddTenant.setMinWidth( 200 );
			buttonAddTenant.setText( "Add Tenant..." );
			buttonAddTenant.setOnAction( new EventHandler<ActionEvent>() {
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
						ICFSecTenantObj obj = (ICFSecTenantObj)schemaObj.getTenantTableObj().newInstance();
						ICFSecTenantEditObj edit = (ICFSecTenantEditObj)( obj.beginEdit() );
						if( edit == null ) {
							throw new CFLibNullArgumentException( getClass(),
								S_ProcName,
								0,
								"edit" );
						}
								ICFSecClusterObj secCluster = schemaObj.getSecCluster();
								edit.setRequiredContainerCluster( secCluster );
						CFBorderPane frame = javafxSchema.getTenantFactory().newAddForm( cfFormManager, obj, getViewEditClosedCallback(), true );
						ICFSecJavaFXTenantPaneCommon jpanelCommon = (ICFSecJavaFXTenantPaneCommon)frame;
						jpanelCommon.setPaneMode( CFPane.PaneMode.Add );
						cfFormManager.pushForm( frame );
					}
					catch( Throwable t ) {
						CFConsole.formException( S_FormName, ((CFButton)e.getSource()).getText(), t );
					}
				}
			});
			hboxMenu.getChildren().add( buttonAddTenant );

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
						ICFSecTenantObj selectedInstance = getJavaFXFocusAsTenant();
						if( selectedInstance != null ) {
							String classCode = selectedInstance.getClassCode();
							if( "a015".equals( classCode ) ) {
								CFBorderPane frame = javafxSchema.getTenantFactory().newViewEditForm( cfFormManager, selectedInstance, getViewEditClosedCallback(), false );
								((ICFSecJavaFXTenantPaneCommon)frame).setPaneMode( CFPane.PaneMode.View );
								cfFormManager.pushForm( frame );
							}
							else {
								throw new CFLibUnsupportedClassException( getClass(),
									S_ProcName,
									"selectedInstance",
									selectedInstance,
									"ICFSecTenantObj" );
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
						ICFSecTenantObj selectedInstance = getJavaFXFocusAsTenant();
						if( selectedInstance != null ) {
							String classCode = selectedInstance.getClassCode();
							if( "a015".equals( classCode ) ) {
								CFBorderPane frame = javafxSchema.getTenantFactory().newViewEditForm( cfFormManager, selectedInstance, getViewEditClosedCallback(), false );
								((ICFSecJavaFXTenantPaneCommon)frame).setPaneMode( CFPane.PaneMode.Edit );
								cfFormManager.pushForm( frame );
							}
							else {
								throw new CFLibUnsupportedClassException( getClass(),
									S_ProcName,
									"selectedInstance",
									selectedInstance,
									"ICFSecTenantObj" );
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
						ICFSecTenantObj selectedInstance = getJavaFXFocusAsTenant();
						if( selectedInstance != null ) {
							String classCode = selectedInstance.getClassCode();
							if( "a015".equals( classCode ) ) {
								CFBorderPane frame = javafxSchema.getTenantFactory().newAskDeleteForm( cfFormManager, selectedInstance, getDeleteCallback() );
								((ICFSecJavaFXTenantPaneCommon)frame).setPaneMode( CFPane.PaneMode.View );
								cfFormManager.pushForm( frame );
							}
							else {
								throw new CFLibUnsupportedClassException( getClass(),
									S_ProcName,
									"selectedInstance",
									selectedInstance,
									"ICFSecTenantObj" );
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
		if( ( value == null ) || ( value instanceof ICFSecTenantObj ) ) {
			super.setJavaFXFocus( value );
		}
		else {
			throw new CFLibUnsupportedClassException( getClass(),
				S_ProcName,
				"value",
				value,
				"ICFSecTenantObj" );
		}
		adjustFinderButtons();
	}

	public ICFSecTenantObj getJavaFXFocusAsTenant() {
		return( (ICFSecTenantObj)getJavaFXFocus() );
	}

	public void setJavaFXFocusAsTenant( ICFSecTenantObj value ) {
		setJavaFXFocus( value );
	}

	public void adjustFinderButtons() {
		ICFSecTenantObj selectedObj = getJavaFXFocusAsTenant();
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

		if( buttonRefresh != null ) {
			buttonRefresh.setDisable( false );
		}
		if( buttonMoreData != null ) {
			buttonMoreData.setDisable( endOfData );
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
		if( buttonAddTenant != null ) {
			buttonAddTenant.setDisable( false );
		}

	}

	public class TenantByQualNameComparator
	implements Comparator<ICFSecTenantObj>
	{
		public TenantByQualNameComparator() {
		}

		public int compare( ICFSecTenantObj lhs, ICFSecTenantObj rhs ) {
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

	protected TenantByQualNameComparator compareTenantByQualName = new TenantByQualNameComparator();

	public void refreshMe() {
		final String S_ProcName = "refreshMe";
		observableListOfTenant = FXCollections.observableArrayList();
		List<ICFSecTenantObj> page = pageCallback.pageData( null );
		Iterator<ICFSecTenantObj> iter = page.iterator();
		while( iter.hasNext() ) {
			observableListOfTenant.add( iter.next() );
		}
		if( page.size() < 25 ) {
				observableListOfTenant.sort( compareTenantByQualName );
			endOfData = true;
		}
		else {
			endOfData = false;
		}
		if( dataTable != null ) {
			dataTable.setItems( observableListOfTenant );
			// Hack from stackoverflow to fix JavaFX TableView refresh issue
			((TableColumn)dataTable.getColumns().get(0)).setVisible( false );
			((TableColumn)dataTable.getColumns().get(0)).setVisible( true );
		}
		adjustFinderButtons();
	}
}
