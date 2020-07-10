// Description: Java 13 Cust JavaFX Schema.

/*
 *	CF Sec Cust JavaFX Implementation
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
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
 */

package org.msscf.msscf.cfseccust.CFSecCust;

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import java.security.KeyStore;

import javafx.application.*;
import javafx.scene.*;
import javafx.stage.*;

import org.apache.commons.codec.binary.Base64;

import org.msscf.msscf.cflib.CFLib.*;
import org.msscf.msscf.cflib.CFLib.JavaFX.*;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfsec.CFSecJavaFX.*;
import org.msscf.msscf.cfsec.CFSecObj.*;

/**
 *	The CFSecCustSchema defines the interface object that is
 *	provided by the cust interface for manipulating the CFSec
 *	facet in the user interface.
 */
public class CFSecCustSchema
extends CFSecJavaFXSchema
implements ICFSecCustSchema
{
	protected ICFSecJavaFXSchema javafxSchema = null;

	public CFSecCustSchema() {
	}

	public ICFSecJavaFXSchema getJavaFXSchema() {
		if( javafxSchema == null ) {
			javafxSchema = this;
		}
		return( javafxSchema );
	}

	public void setJavaFXSchema( ICFSecJavaFXSchema value ) {
		final String S_ProcName = "setJavaFXSchema";
		if( value == null ) {
			throw new CFLibNullArgumentException( getClass(),
				S_ProcName,
				1,
				"value" );
		}
		javafxSchema = value;
	}

	@Override public ICFSecJavaFXSecGroupFactory getSecGroupFactory() {
		if( factorySecGroup == null ) {
			factorySecGroup = new CFSecCustSecGroupFactory( this );
		}
		return( factorySecGroup );
	}

	@Override public ICFSecJavaFXTSecGroupFactory getTSecGroupFactory() {
		if( factoryTSecGroup == null ) {
			factoryTSecGroup = new CFSecCustTSecGroupFactory( this );
		}
		return( factoryTSecGroup );
	}

	protected volatile static CFSecCustFacetPane S_singletonSecFacetPane = null;

	public CFSecCustFacetPane getSingletonSecFacetPane( ICFFormManager formManager ) {
		CFSecCustFacetPane pane = getSingletonSecFacetPane( formManager, this );
		return( pane );
	}

	public CFSecCustFacetPane getSingletonSecFacetPane( ICFFormManager formManager, ICFSecCustSchema argSchema ) {
		if( S_singletonSecFacetPane == null ) {
			S_singletonSecFacetPane = newSecFacetPane( formManager, argSchema );
		}
		return( S_singletonSecFacetPane );
	}

	public CFSecCustFacetPane newSecFacetPane( ICFFormManager formManager ) {
		CFSecCustFacetPane pane = newSecFacetPane( formManager, this );
		return( pane );
	}

	public CFSecCustFacetPane newSecFacetPane( ICFFormManager formManager, ICFSecCustSchema argSchema ) {
		CFSecCustFacetPane pane = new CFSecCustFacetPane( formManager, argSchema );
		return( pane );
	}

	public CFBorderPane newManageClusterSecGroupForm( ICFFormManager formManager ) {
		CFBorderPane pane = new CFSecCustManageClusterSecGroupForm( formManager, this );
		return( pane );
	}

	public CFBorderPane newManageClusterSecGroupForm( ICFFormManager formManager, ICFSecCustSchema argSchema ) {
		CFBorderPane pane = new CFSecCustManageClusterSecGroupForm( formManager, argSchema );
		return( pane );
	}

	public CFBorderPane newManageClusterSecGroupPane( ICFFormManager formManager ) {
		CFBorderPane pane = new CFSecCustManageClusterSecGroupPane( formManager, this );
		return( pane );
	}

	public CFBorderPane newManageClusterSecGroupPane( ICFFormManager formManager, ICFSecCustSchema argSchema ) {
		CFBorderPane pane = new CFSecCustManageClusterSecGroupPane( formManager, argSchema );
		return( pane );
	}

	public CFBorderPane newManageTenantTSecGroupForm( ICFFormManager formManager ) {
		CFBorderPane pane = new CFSecCustManageTenantTSecGroupForm( formManager, this );
		return( pane );
	}

	public CFBorderPane newManageTenantTSecGroupForm( ICFFormManager formManager, ICFSecCustSchema argSchema ) {
		CFBorderPane pane = new CFSecCustManageTenantTSecGroupForm( formManager, argSchema );
		return( pane );
	}

	public CFBorderPane newManageTenantTSecGroupPane( ICFFormManager formManager ) {
		CFBorderPane pane = new CFSecCustManageTenantTSecGroupPane( formManager, this );
		return( pane );
	}

	public CFBorderPane newManageTenantTSecGroupPane( ICFFormManager formManager, ICFSecCustSchema argSchema ) {
		CFBorderPane pane = new CFSecCustManageTenantTSecGroupPane( formManager, argSchema );
		return( pane );
	}
}
