// Description: Java 11 edit object instance implementation for CFSec ServiceType.

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

package org.msscf.msscf.cfsec.v2_13.cfsec.CFSecObj;

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.msscf.msscf.cflib.v2_13.CFLib.*;
import org.msscf.msscf.cfsec.CFSec.*;

public class CFSecServiceTypeEditObj
	implements ICFSecServiceTypeEditObj
{
	protected ICFSecServiceTypeObj orig;
	protected CFSecServiceTypeBuff buff;
	protected ICFSecSecUserObj createdBy = null;
	protected ICFSecSecUserObj updatedBy = null;

	public CFSecServiceTypeEditObj( ICFSecServiceTypeObj argOrig ) {
		orig = argOrig;
		getBuff();
		CFSecServiceTypeBuff origBuff = orig.getBuff();
		buff.set( origBuff );
	}

	public ICFSecSecUserObj getCreatedBy() {
		if( createdBy == null ) {
			CFSecServiceTypeBuff buff = getBuff();
			createdBy = ((ICFSecSchemaObj)getSchema()).getSecUserTableObj().readSecUserByIdIdx( buff.getCreatedByUserId() );
		}
		return( createdBy );
	}

	public Calendar getCreatedAt() {
		return( getBuff().getCreatedAt() );
	}

	public ICFSecSecUserObj getUpdatedBy() {
		if( updatedBy == null ) {
			CFSecServiceTypeBuff buff = getBuff();
			updatedBy = ((ICFSecSchemaObj)getSchema()).getSecUserTableObj().readSecUserByIdIdx( buff.getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	public Calendar getUpdatedAt() {
		return( getBuff().getUpdatedAt() );
	}

	public void setCreatedBy( ICFSecSecUserObj value ) {
		createdBy = value;
		if( value != null ) {
			getBuff().setCreatedByUserId( value.getRequiredSecUserId() );
		}
	}

	public void setCreatedAt( Calendar value ) {
		getBuff().setCreatedAt( value );
	}

	public void setUpdatedBy( ICFSecSecUserObj value ) {
		updatedBy = value;
		if( value != null ) {
			getBuff().setUpdatedByUserId( value.getRequiredSecUserId() );
		}
	}

	public void setUpdatedAt( Calendar value ) {
		getBuff().setUpdatedAt( value );
	}

	public String getClassCode() {
		return( CFSecServiceTypeObj.CLASS_CODE );
	}

	public String getGenDefName() {
		return( "ServiceType" );
	}

	public ICFLibAnyObj getScope() {
		return( null );
	}

	public ICFLibAnyObj getObjScope() {
		return( null );
	}

	public String getObjName() {
		String objName;
		objName = getRequiredDescription();
		return( objName );
	}

	public ICFLibAnyObj getObjQualifier( Class qualifyingClass ) {
		ICFLibAnyObj container = this;
		if( qualifyingClass != null ) {
			while( container != null ) {
				if( container instanceof ICFSecClusterObj ) {
					break;
				}
				else if( container instanceof ICFSecTenantObj ) {
					break;
				}
				else if( qualifyingClass.isInstance( container ) ) {
					break;
				}
				container = container.getObjScope();
			}
		}
		else {
			while( container != null ) {
				if( container instanceof ICFSecClusterObj ) {
					break;
				}
				else if( container instanceof ICFSecTenantObj ) {
					break;
				}
				container = container.getObjScope();
			}
		}
		return( container );
	}

	public ICFLibAnyObj getNamedObject( Class qualifyingClass, String objName ) {
		ICFLibAnyObj topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == null ) {
			return( null );
		}
		ICFLibAnyObj namedObject = topContainer.getNamedObject( objName );
		return( namedObject );
	}

	public ICFLibAnyObj getNamedObject( String objName ) {
		String nextName;
		String remainingName;
		ICFLibAnyObj subObj = null;
		ICFLibAnyObj retObj;
		int nextDot = objName.indexOf( '.' );
		if( nextDot >= 0 ) {
			nextName = objName.substring( 0, nextDot );
			remainingName = objName.substring( nextDot + 1 );
		}
		else {
			nextName = objName;
			remainingName = null;
		}
		if( remainingName == null ) {
			retObj = subObj;
		}
		else if( subObj == null ) {
			retObj = null;
		}
		else {
			retObj = subObj.getNamedObject( remainingName );
		}
		return( retObj );
	}

	public String getObjQualifiedName() {
		String qualName = getObjName();
		ICFLibAnyObj container = getObjScope();
		String containerName;
		while( container != null ) {
			if( container instanceof ICFSecClusterObj ) {
				container = null;
			}
			else if( container instanceof ICFSecTenantObj ) {
				container = null;
			}
			else {
				containerName = container.getObjName();
				qualName = containerName + "." + qualName;
				container = container.getObjScope();
			}
		}
		return( qualName );
	}

	public String getObjFullName() {
		String fullName = getObjName();
		ICFLibAnyObj container = getObjScope();
		String containerName;
		while( container != null ) {
			if( container instanceof ICFSecClusterObj ) {
				container = null;
			}
			else if( container instanceof ICFSecTenantObj ) {
				container = null;
			}
			else {
				containerName = container.getObjName();
				fullName = containerName + "." + fullName;
				container = container.getObjScope();
			}
		}
		return( fullName );
	}

	public ICFSecServiceTypeObj realise() {
		// We realise this so that it's buffer will get copied to orig during realization
		ICFSecServiceTypeObj retobj = getSchema().getServiceTypeTableObj().realiseServiceType( (ICFSecServiceTypeObj)this );
		return( retobj );
	}

	public void forget() {
		getOrigAsServiceType().forget();
	}

	public ICFSecServiceTypeObj read() {
		ICFSecServiceTypeObj retval = getOrigAsServiceType().read();
		if( retval != orig ) {
			throw new CFLibUsageException( getClass(),
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	public ICFSecServiceTypeObj read( boolean forceRead ) {
		ICFSecServiceTypeObj retval = getOrigAsServiceType().read( forceRead );
		if( retval != orig ) {
			throw new CFLibUsageException( getClass(),
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	public ICFSecServiceTypeObj create() {
		copyBuffToOrig();
		ICFSecServiceTypeObj retobj = ((ICFSecSchemaObj)getOrigAsServiceType().getSchema()).getServiceTypeTableObj().createServiceType( getOrigAsServiceType() );
		if( retobj == getOrigAsServiceType() ) {
			copyOrigToBuff();
		}
		return( retobj );
	}

	public CFSecServiceTypeEditObj update() {
		getSchema().getServiceTypeTableObj().updateServiceType( (ICFSecServiceTypeObj)this );
		return( null );
	}

	public CFSecServiceTypeEditObj deleteInstance() {
		if( getIsNew() ) {
			throw new CFLibUsageException( getClass(), "delete", "Cannot delete a new instance" );
		}
		getSchema().getServiceTypeTableObj().deleteServiceType( getOrigAsServiceType() );
		return( null );
	}

	public ICFSecServiceTypeTableObj getServiceTypeTable() {
		return( orig.getSchema().getServiceTypeTableObj() );
	}

	public ICFSecServiceTypeEditObj getEdit() {
		return( (ICFSecServiceTypeEditObj)this );
	}

	public ICFSecServiceTypeEditObj getEditAsServiceType() {
		return( (ICFSecServiceTypeEditObj)this );
	}

	public ICFSecServiceTypeEditObj beginEdit() {
		throw new CFLibUsageException( getClass(), "beginEdit", "Cannot edit an edition" );
	}

	public void endEdit() {
		orig.endEdit();
	}

	public ICFSecServiceTypeObj getOrig() {
		return( orig );
	}

	public ICFSecServiceTypeObj getOrigAsServiceType() {
		return( (ICFSecServiceTypeObj)orig );
	}

	public ICFSecSchemaObj getSchema() {
		return( orig.getSchema() );
	}

	public CFSecServiceTypeBuff getBuff() {
		if( buff == null ) {
			buff = ((ICFSecSchema)getOrigAsServiceType().getSchema().getBackingStore()).getFactoryServiceType().newBuff();
			buff.set( orig.getBuff() );
		}
		return( buff );
	}

	public void setBuff( CFSecServiceTypeBuff value ) {
		if( buff != value ) {
			buff = value;
		}
	}

	public CFSecServiceTypeBuff getServiceTypeBuff() {
		return( (CFSecServiceTypeBuff)getBuff() );
	}

	public CFSecServiceTypePKey getPKey() {
		return( orig.getPKey() );
	}

	public void setPKey( CFSecServiceTypePKey value ) {
		orig.setPKey( value );
		copyPKeyToBuff();
	}

	public boolean getIsNew() {
		return( orig.getIsNew() );
	}

	public void setIsNew( boolean value ) {
		orig.setIsNew( value );
	}

	public int getRequiredServiceTypeId() {
		return( getPKey().getRequiredServiceTypeId() );
	}

	public String getRequiredDescription() {
		return( getServiceTypeBuff().getRequiredDescription() );
	}

	public void setRequiredDescription( String value ) {
		if( getServiceTypeBuff().getRequiredDescription() != value ) {
			getServiceTypeBuff().setRequiredDescription( value );
		}
	}

	public List<ICFSecServiceObj> getOptionalChildrenDeployed() {
		List<ICFSecServiceObj> retval;
		retval = ((ICFSecSchemaObj)getOrigAsServiceType().getSchema()).getServiceTableObj().readServiceByTypeIdx( getPKey().getRequiredServiceTypeId(),
			false );
		return( retval );
	}

	public List<ICFSecServiceObj> getOptionalChildrenDeployed( boolean forceRead ) {
		List<ICFSecServiceObj> retval;
		retval = ((ICFSecSchemaObj)getOrigAsServiceType().getSchema()).getServiceTableObj().readServiceByTypeIdx( getPKey().getRequiredServiceTypeId(),
			forceRead );
		return( retval );
	}

	public void copyPKeyToBuff() {
		buff.setRequiredServiceTypeId( getPKey().getRequiredServiceTypeId() );
	}

	public void copyBuffToPKey() {
		getPKey().setRequiredServiceTypeId( buff.getRequiredServiceTypeId() );
	}

	public void copyBuffToOrig() {
		CFSecServiceTypeBuff origBuff = getOrigAsServiceType().getServiceTypeBuff();
		CFSecServiceTypeBuff myBuff = getServiceTypeBuff();
		origBuff.set( myBuff );
	}

	public void copyOrigToBuff() {
		CFSecServiceTypeBuff origBuff = getOrigAsServiceType().getServiceTypeBuff();
		CFSecServiceTypeBuff myBuff = getServiceTypeBuff();
		myBuff.set( origBuff );
	}
}
