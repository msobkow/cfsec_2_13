// Description: Java 11 JavaFX Picker of Obj Pane implementation for ISOCtryCcy.

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
 *	CFSecJavaFXISOCtryCcyPickerPane JavaFX Pick Obj Pane implementation
 *	for ISOCtryCcy.
 */
public class CFSecJavaFXISOCtryCcyPickerPane
extends CFBorderPane
implements ICFSecJavaFXISOCtryCcyPaneList
{
	public static String S_FormName = "Choose ISOCtryCcy";
	protected ICFSecJavaFXSchema javafxSchema = null;
	protected Collection<ICFSecISOCtryCcyObj> javafxDataCollection = null;
	protected ObservableList<ICFSecISOCtryCcyObj> observableListOfISOCtryCcy = null;
	protected TableColumn<ICFSecISOCtryCcyObj, ICFSecISOCcyObj> tableColumnParentCcy = null;
	protected TableView<ICFSecISOCtryCcyObj> dataTable = null;
	protected CFHBox hboxMenu = null;
	public final String S_ColumnNames[] = { "Name" };
	protected ICFFormManager cfFormManager = null;
	protected ICFSecJavaFXISOCtryCcyChosen invokeWhenChosen = null;
	protected ICFSecISOCtryObj javafxContainer = null;
	protected CFButton buttonCancel = null;
	protected CFButton buttonChooseNone = null;
	protected CFButton buttonChooseSelected = null;
	protected ScrollPane scrollMenu = null;
	public CFSecJavaFXISOCtryCcyPickerPane( ICFFormManager formManager,
		ICFSecJavaFXSchema argSchema,
		ICFSecISOCtryCcyObj argFocus,
		ICFSecISOCtryObj argContainer,
		Collection<ICFSecISOCtryCcyObj> argDataCollection,
		ICFSecJavaFXISOCtryCcyChosen whenChosen )
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
		dataTable = new TableView<ICFSecISOCtryCcyObj>();
		tableColumnParentCcy = new TableColumn<ICFSecISOCtryCcyObj, ICFSecISOCcyObj>( "Ccy" );
		tableColumnParentCcy.setCellValueFactory( new Callback<CellDataFeatures<ICFSecISOCtryCcyObj,ICFSecISOCcyObj>,ObservableValue<ICFSecISOCcyObj> >() {
			public ObservableValue<ICFSecISOCcyObj> call( CellDataFeatures<ICFSecISOCtryCcyObj, ICFSecISOCcyObj> p ) {
				ICFSecISOCtryCcyObj obj = p.getValue();
				if( obj == null ) {
					return( null );
				}
				else {
					ICFSecISOCcyObj ref = obj.getRequiredParentCcy();
					ReadOnlyObjectWrapper<ICFSecISOCcyObj> observable = new ReadOnlyObjectWrapper<ICFSecISOCcyObj>();
					observable.setValue( ref );
					return( observable );
				}
			}
		});
		tableColumnParentCcy.setCellFactory( new Callback<TableColumn<ICFSecISOCtryCcyObj,ICFSecISOCcyObj>,TableCell<ICFSecISOCtryCcyObj,ICFSecISOCcyObj>>() {
			@Override public TableCell<ICFSecISOCtryCcyObj,ICFSecISOCcyObj> call(
				TableColumn<ICFSecISOCtryCcyObj,ICFSecISOCcyObj> arg)
			{
				return new CFReferenceTableCell<ICFSecISOCtryCcyObj,ICFSecISOCcyObj>();
			}
		});
		dataTable.getColumns().add( tableColumnParentCcy );
		dataTable.getSelectionModel().selectedItemProperty().addListener(
			new ChangeListener<ICFSecISOCtryCcyObj>() {
				@Override public void changed( ObservableValue<? extends ICFSecISOCtryCcyObj> observable,
					ICFSecISOCtryCcyObj oldValue,
					ICFSecISOCtryCcyObj newValue )
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
					invokeWhenChosen.choseISOCtryCcy( null );
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
					ICFSecISOCtryCcyObj selectedInstance = getJavaFXFocusAsISOCtryCcy();
					invokeWhenChosen.choseISOCtryCcy( selectedInstance );
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
		if( ( value == null ) || ( value instanceof ICFSecISOCtryCcyObj ) ) {
			super.setJavaFXFocus( value );
		}
		else {
			throw new CFLibUnsupportedClassException( getClass(),
				S_ProcName,
				"value",
				value,
				"ICFSecISOCtryCcyObj" );
		}
		if( dataTable == null ) {
			return;
		}
	}

	public ICFSecISOCtryCcyObj getJavaFXFocusAsISOCtryCcy() {
		return( (ICFSecISOCtryCcyObj)getJavaFXFocus() );
	}

	public void setJavaFXFocusAsISOCtryCcy( ICFSecISOCtryCcyObj value ) {
		setJavaFXFocus( value );
	}

	public class ISOCtryCcyByQualNameComparator
	implements Comparator<ICFSecISOCtryCcyObj>
	{
		public ISOCtryCcyByQualNameComparator() {
		}

		public int compare( ICFSecISOCtryCcyObj lhs, ICFSecISOCtryCcyObj rhs ) {
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

	protected ISOCtryCcyByQualNameComparator compareISOCtryCcyByQualName = new ISOCtryCcyByQualNameComparator();

	public Collection<ICFSecISOCtryCcyObj> getJavaFXDataCollection() {
		return( javafxDataCollection );
	}

	public void setJavaFXDataCollection( Collection<ICFSecISOCtryCcyObj> value ) {
		final String S_ProcName = "setJavaFXDataCollection";
		javafxDataCollection = value;
		observableListOfISOCtryCcy = FXCollections.observableArrayList();
		if( javafxDataCollection != null ) {
				Iterator<ICFSecISOCtryCcyObj> iter = javafxDataCollection.iterator();
				while( iter.hasNext() ) {
					observableListOfISOCtryCcy.add( iter.next() );
				}
				observableListOfISOCtryCcy.sort( compareISOCtryCcyByQualName );
		}
		if( dataTable != null ) {
			dataTable.setItems( observableListOfISOCtryCcy );
			// Hack from stackoverflow to fix JavaFX TableView refresh issue
			((TableColumn)dataTable.getColumns().get(0)).setVisible( false );
			((TableColumn)dataTable.getColumns().get(0)).setVisible( true );
		}
	}

	public ICFSecISOCtryObj getJavaFXContainer() {
		return( javafxContainer );
	}

	public void setJavaFXContainer( ICFSecISOCtryObj value ) {
		javafxContainer = value;
	}

	public void adjustListButtons() {
		boolean enableState;
		ICFSecISOCtryCcyObj selectedObj = getJavaFXFocusAsISOCtryCcy();
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

