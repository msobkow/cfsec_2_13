// Description: Java 11 JavaFX Finder Form implementation for Cluster.

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
 *	CFSecJavaFXClusterFinderForm JavaFX Finder Form implementation
 *	for Cluster.
 */
public class CFSecJavaFXClusterFinderForm
extends CFBorderPane
implements ICFSecJavaFXClusterPaneCommon,
	ICFForm
{
	public static String S_FormName = "Find Cluster";
	protected ICFFormManager cfFormManager = null;
	protected ICFSecJavaFXSchema javafxSchema = null;
	protected boolean javafxIsInitializing = true;
	protected ScrollPane scrollMenu = null;
	protected CFHBox hboxMenu = null;
	protected CFButton buttonViewSelected = null;
	protected CFButton buttonEditSelected = null;
	protected CFButton buttonClose = null;
	protected CFButton buttonDeleteSelected = null;
	protected ICFSecJavaFXClusterPageCallback pageCallback = null;
	protected CFButton buttonRefresh = null;
	protected CFButton buttonMoreData = null;
	protected boolean endOfData = true;
	protected ObservableList<ICFSecClusterObj> observableListOfCluster = null;
	protected TableColumn<ICFSecClusterObj, Long> tableColumnId = null;
	protected TableColumn<ICFSecClusterObj, String> tableColumnFullDomName = null;
	protected TableColumn<ICFSecClusterObj, String> tableColumnDescription = null;
	protected TableView<ICFSecClusterObj> dataTable = null;

	protected class PageDataClusterList
	implements ICFSecJavaFXClusterPageCallback
	{
		public PageDataClusterList() {
		}

		public List<ICFSecClusterObj> pageData( Long priorId )
		{
			List<ICFSecClusterObj> dataList;
			ICFSecSchemaObj schemaObj = (ICFSecSchemaObj)javafxSchema.getSchema();
			dataList = schemaObj.getClusterTableObj().pageAllCluster(priorId );
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

	public CFSecJavaFXClusterFinderForm( ICFFormManager formManager, ICFSecJavaFXSchema argSchema ) {
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
		pageCallback = new PageDataClusterList();
		dataTable = new TableView<ICFSecClusterObj>();
		tableColumnId = new TableColumn<ICFSecClusterObj,Long>( "Id" );
		tableColumnId.setCellValueFactory( new Callback<CellDataFeatures<ICFSecClusterObj,Long>,ObservableValue<Long> >() {
			public ObservableValue<Long> call( CellDataFeatures<ICFSecClusterObj, Long> p ) {
				ICFSecClusterObj obj = p.getValue();
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
		tableColumnId.setCellFactory( new Callback<TableColumn<ICFSecClusterObj,Long>,TableCell<ICFSecClusterObj,Long>>() {
			@Override public TableCell<ICFSecClusterObj,Long> call(
				TableColumn<ICFSecClusterObj,Long> arg)
			{
				return new CFInt64TableCell<ICFSecClusterObj>();
			}
		});
		dataTable.getColumns().add( tableColumnId );
		tableColumnFullDomName = new TableColumn<ICFSecClusterObj,String>( "Full Domain Name" );
		tableColumnFullDomName.setCellValueFactory( new Callback<CellDataFeatures<ICFSecClusterObj,String>,ObservableValue<String> >() {
			public ObservableValue<String> call( CellDataFeatures<ICFSecClusterObj, String> p ) {
				ICFSecClusterObj obj = p.getValue();
				if( obj == null ) {
					return( null );
				}
				else {
					String value = obj.getRequiredFullDomName();
					ReadOnlyObjectWrapper<String> observable = new ReadOnlyObjectWrapper<String>();
					observable.setValue( value );
					return( observable );
				}
			}
		});
		tableColumnFullDomName.setCellFactory( new Callback<TableColumn<ICFSecClusterObj,String>,TableCell<ICFSecClusterObj,String>>() {
			@Override public TableCell<ICFSecClusterObj,String> call(
				TableColumn<ICFSecClusterObj,String> arg)
			{
				return new CFStringTableCell<ICFSecClusterObj>();
			}
		});
		dataTable.getColumns().add( tableColumnFullDomName );
		tableColumnDescription = new TableColumn<ICFSecClusterObj,String>( "Cluster Description" );
		tableColumnDescription.setCellValueFactory( new Callback<CellDataFeatures<ICFSecClusterObj,String>,ObservableValue<String> >() {
			public ObservableValue<String> call( CellDataFeatures<ICFSecClusterObj, String> p ) {
				ICFSecClusterObj obj = p.getValue();
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
		tableColumnDescription.setCellFactory( new Callback<TableColumn<ICFSecClusterObj,String>,TableCell<ICFSecClusterObj,String>>() {
			@Override public TableCell<ICFSecClusterObj,String> call(
				TableColumn<ICFSecClusterObj,String> arg)
			{
				return new CFStringTableCell<ICFSecClusterObj>();
			}
		});
		dataTable.getColumns().add( tableColumnDescription );
		dataTable.getSelectionModel().selectedItemProperty().addListener(
			new ChangeListener<ICFSecClusterObj>() {
				@Override public void changed( ObservableValue<? extends ICFSecClusterObj> observable,
					ICFSecClusterObj oldValue,
					ICFSecClusterObj newValue )
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
						ICFSecClusterObj lastObj = null;
						if( ( observableListOfCluster != null ) && ( observableListOfCluster.size() > 0 ) ) {
							lastObj = observableListOfCluster.get( observableListOfCluster.size() - 1 );
						}
						List<ICFSecClusterObj> page;
						if( lastObj != null ) {
							page = pageCallback.pageData( lastObj.getRequiredId() );
						}
						else {
							page = pageCallback.pageData( null );
						}
						Iterator<ICFSecClusterObj> iter = page.iterator();
						while( iter.hasNext() ) {
							observableListOfCluster.add( iter.next() );
						}
						if( page.size() < 25 ) {
							observableListOfCluster.sort( compareClusterByQualName );
							endOfData = true;
						}
						else {
							endOfData = false;
						}
						if( dataTable != null ) {
							dataTable.setItems( observableListOfCluster );
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
						ICFSecClusterObj selectedInstance = getJavaFXFocusAsCluster();
						if( selectedInstance != null ) {
							String classCode = selectedInstance.getClassCode();
							if( "a001".equals( classCode ) ) {
								CFBorderPane frame = javafxSchema.getClusterFactory().newViewEditForm( cfFormManager, selectedInstance, getViewEditClosedCallback(), false );
								((ICFSecJavaFXClusterPaneCommon)frame).setPaneMode( CFPane.PaneMode.View );
								cfFormManager.pushForm( frame );
							}
							else {
								throw new CFLibUnsupportedClassException( getClass(),
									S_ProcName,
									"selectedInstance",
									selectedInstance,
									"ICFSecClusterObj" );
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
						ICFSecClusterObj selectedInstance = getJavaFXFocusAsCluster();
						if( selectedInstance != null ) {
							String classCode = selectedInstance.getClassCode();
							if( "a001".equals( classCode ) ) {
								CFBorderPane frame = javafxSchema.getClusterFactory().newViewEditForm( cfFormManager, selectedInstance, getViewEditClosedCallback(), false );
								((ICFSecJavaFXClusterPaneCommon)frame).setPaneMode( CFPane.PaneMode.Edit );
								cfFormManager.pushForm( frame );
							}
							else {
								throw new CFLibUnsupportedClassException( getClass(),
									S_ProcName,
									"selectedInstance",
									selectedInstance,
									"ICFSecClusterObj" );
							}
						}
					}
					catch( Throwable t ) {
						CFConsole.formException( S_FormName, ((CFButton)e.getSource()).getText(), t );
					}
				}
			});
			hboxMenu.getChildren().add( buttonEditSelected );

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
		if( ( value == null ) || ( value instanceof ICFSecClusterObj ) ) {
			super.setJavaFXFocus( value );
		}
		else {
			throw new CFLibUnsupportedClassException( getClass(),
				S_ProcName,
				"value",
				value,
				"ICFSecClusterObj" );
		}
		adjustFinderButtons();
	}

	public ICFSecClusterObj getJavaFXFocusAsCluster() {
		return( (ICFSecClusterObj)getJavaFXFocus() );
	}

	public void setJavaFXFocusAsCluster( ICFSecClusterObj value ) {
		setJavaFXFocus( value );
	}

	public void adjustFinderButtons() {
		ICFSecClusterObj selectedObj = getJavaFXFocusAsCluster();
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

	}

	public class ClusterByQualNameComparator
	implements Comparator<ICFSecClusterObj>
	{
		public ClusterByQualNameComparator() {
		}

		public int compare( ICFSecClusterObj lhs, ICFSecClusterObj rhs ) {
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

	protected ClusterByQualNameComparator compareClusterByQualName = new ClusterByQualNameComparator();

	public void refreshMe() {
		final String S_ProcName = "refreshMe";
		observableListOfCluster = FXCollections.observableArrayList();
		List<ICFSecClusterObj> page = pageCallback.pageData( null );
		Iterator<ICFSecClusterObj> iter = page.iterator();
		while( iter.hasNext() ) {
			observableListOfCluster.add( iter.next() );
		}
		if( page.size() < 25 ) {
				observableListOfCluster.sort( compareClusterByQualName );
			endOfData = true;
		}
		else {
			endOfData = false;
		}
		if( dataTable != null ) {
			dataTable.setItems( observableListOfCluster );
			// Hack from stackoverflow to fix JavaFX TableView refresh issue
			((TableColumn)dataTable.getColumns().get(0)).setVisible( false );
			((TableColumn)dataTable.getColumns().get(0)).setVisible( true );
		}
		adjustFinderButtons();
	}
}