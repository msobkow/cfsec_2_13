// Description: Java 11 edit object instance implementation for CFSec SecDevice.

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

package org.msscf.msscf.v2_13.cfsec.CFSecObj;

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.msscf.msscf.v2_13.cflib.CFLib.*;
import org.msscf.msscf.v2_13.cfsec.CFSec.*;

public class CFSecSecDeviceEditObj
	implements ICFSecSecDeviceEditObj
{
	protected ICFSecSecDeviceObj orig;
	protected CFSecSecDeviceBuff buff;
	protected ICFSecSecUserObj createdBy = null;
	protected ICFSecSecUserObj updatedBy = null;
	protected ICFSecSecUserObj requiredContainerSecUser;

	public CFSecSecDeviceEditObj( ICFSecSecDeviceObj argOrig ) {
		orig = argOrig;
		getBuff();
		CFSecSecDeviceBuff origBuff = orig.getBuff();
		buff.set( origBuff );
		requiredContainerSecUser = null;
	}

	public ICFSecSecUserObj getCreatedBy() {
		if( createdBy == null ) {
			CFSecSecDeviceBuff buff = getBuff();
			createdBy = ((ICFSecSchemaObj)getSchema()).getSecUserTableObj().readSecUserByIdIdx( buff.getCreatedByUserId() );
		}
		return( createdBy );
	}

	public Calendar getCreatedAt() {
		return( getBuff().getCreatedAt() );
	}

	public ICFSecSecUserObj getUpdatedBy() {
		if( updatedBy == null ) {
			CFSecSecDeviceBuff buff = getBuff();
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
		return( CFSecSecDeviceObj.CLASS_CODE );
	}

	public String getGenDefName() {
		return( "SecDevice" );
	}

	public ICFLibAnyObj getScope() {
		ICFSecSecUserObj scope = getRequiredContainerSecUser();
		return( scope );
	}

	public ICFLibAnyObj getObjScope() {
		ICFSecSecUserObj scope = getRequiredContainerSecUser();
		return( scope );
	}

	public String getObjName() {
		String objName;
		objName = getRequiredDevName();
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

	public ICFSecSecDeviceObj realise() {
		// We realise this so that it's buffer will get copied to orig during realization
		ICFSecSecDeviceObj retobj = getSchema().getSecDeviceTableObj().realiseSecDevice( (ICFSecSecDeviceObj)this );
		return( retobj );
	}

	public void forget() {
		getOrigAsSecDevice().forget();
	}

	public ICFSecSecDeviceObj read() {
		ICFSecSecDeviceObj retval = getOrigAsSecDevice().read();
		if( retval != orig ) {
			throw new CFLibUsageException( getClass(),
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	public ICFSecSecDeviceObj read( boolean forceRead ) {
		ICFSecSecDeviceObj retval = getOrigAsSecDevice().read( forceRead );
		if( retval != orig ) {
			throw new CFLibUsageException( getClass(),
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	public ICFSecSecDeviceObj create() {
		copyBuffToOrig();
		ICFSecSecDeviceObj retobj = ((ICFSecSchemaObj)getOrigAsSecDevice().getSchema()).getSecDeviceTableObj().createSecDevice( getOrigAsSecDevice() );
		if( retobj == getOrigAsSecDevice() ) {
			copyOrigToBuff();
		}
		return( retobj );
	}

	public CFSecSecDeviceEditObj update() {
		getSchema().getSecDeviceTableObj().updateSecDevice( (ICFSecSecDeviceObj)this );
		return( null );
	}

	public CFSecSecDeviceEditObj deleteInstance() {
		if( getIsNew() ) {
			throw new CFLibUsageException( getClass(), "delete", "Cannot delete a new instance" );
		}
		getSchema().getSecDeviceTableObj().deleteSecDevice( getOrigAsSecDevice() );
		return( null );
	}

	public ICFSecSecDeviceTableObj getSecDeviceTable() {
		return( orig.getSchema().getSecDeviceTableObj() );
	}

	public ICFSecSecDeviceEditObj getEdit() {
		return( (ICFSecSecDeviceEditObj)this );
	}

	public ICFSecSecDeviceEditObj getEditAsSecDevice() {
		return( (ICFSecSecDeviceEditObj)this );
	}

	public ICFSecSecDeviceEditObj beginEdit() {
		throw new CFLibUsageException( getClass(), "beginEdit", "Cannot edit an edition" );
	}

	public void endEdit() {
		orig.endEdit();
	}

	public ICFSecSecDeviceObj getOrig() {
		return( orig );
	}

	public ICFSecSecDeviceObj getOrigAsSecDevice() {
		return( (ICFSecSecDeviceObj)orig );
	}

	public ICFSecSchemaObj getSchema() {
		return( orig.getSchema() );
	}

	public CFSecSecDeviceBuff getBuff() {
		if( buff == null ) {
			buff = ((ICFSecSchema)getOrigAsSecDevice().getSchema().getBackingStore()).getFactorySecDevice().newBuff();
			buff.set( orig.getBuff() );
		}
		return( buff );
	}

	public void setBuff( CFSecSecDeviceBuff value ) {
		if( buff != value ) {
			buff = value;
			requiredContainerSecUser = null;
		}
	}

	public CFSecSecDeviceBuff getSecDeviceBuff() {
		return( (CFSecSecDeviceBuff)getBuff() );
	}

	public CFSecSecDevicePKey getPKey() {
		return( orig.getPKey() );
	}

	public void setPKey( CFSecSecDevicePKey value ) {
		orig.setPKey( value );
		copyPKeyToBuff();
	}

	public boolean getIsNew() {
		return( orig.getIsNew() );
	}

	public void setIsNew( boolean value ) {
		orig.setIsNew( value );
	}

	public UUID getRequiredSecUserId() {
		return( getPKey().getRequiredSecUserId() );
	}

	public String getRequiredDevName() {
		return( getPKey().getRequiredDevName() );
	}

	public void setRequiredDevName( String value ) {
		if( getPKey().getRequiredDevName() != value ) {
			getPKey().setRequiredDevName( value );
		}
		if( getSecDeviceBuff().getRequiredDevName() != value ) {
			getSecDeviceBuff().setRequiredDevName( value );
		}
	}

	public String getOptionalPubKey() {
		return( getSecDeviceBuff().getOptionalPubKey() );
	}

	public void setOptionalPubKey( String value ) {
		if( getSecDeviceBuff().getOptionalPubKey() != value ) {
			getSecDeviceBuff().setOptionalPubKey( value );
		}
	}

	public ICFSecSecUserObj getRequiredContainerSecUser() {
		return( getRequiredContainerSecUser( false ) );
	}

	public ICFSecSecUserObj getRequiredContainerSecUser( boolean forceRead ) {
		if( forceRead || ( requiredContainerSecUser == null ) ) {
			boolean anyMissing = false;
			if( ! anyMissing ) {
				ICFSecSecUserObj obj = ((ICFSecSchemaObj)getOrigAsSecDevice().getSchema()).getSecUserTableObj().readSecUserByIdIdx( getPKey().getRequiredSecUserId() );
				requiredContainerSecUser = obj;
				if( obj != null ) {
					getSecDeviceBuff().setRequiredSecUserId( obj.getRequiredSecUserId() );
					requiredContainerSecUser = obj;
				}
			}
		}
		return( requiredContainerSecUser );
	}

	public void setRequiredContainerSecUser( ICFSecSecUserObj value ) {
			if( buff == null ) {
				getSecDeviceBuff();
			}
			if( value != null ) {
				getPKey().setRequiredSecUserId( value.getRequiredSecUserId() );
				getSecDeviceBuff().setRequiredSecUserId( value.getRequiredSecUserId() );
			}
			requiredContainerSecUser = value;
	}

	public void copyPKeyToBuff() {
		buff.setRequiredSecUserId( getPKey().getRequiredSecUserId() );
		buff.setRequiredDevName( getPKey().getRequiredDevName() );
	}

	public void copyBuffToPKey() {
		getPKey().setRequiredSecUserId( buff.getRequiredSecUserId() );
		getPKey().setRequiredDevName( buff.getRequiredDevName() );
	}

	public void copyBuffToOrig() {
		CFSecSecDeviceBuff origBuff = getOrigAsSecDevice().getSecDeviceBuff();
		CFSecSecDeviceBuff myBuff = getSecDeviceBuff();
		origBuff.set( myBuff );
	}

	public void copyOrigToBuff() {
		CFSecSecDeviceBuff origBuff = getOrigAsSecDevice().getSecDeviceBuff();
		CFSecSecDeviceBuff myBuff = getSecDeviceBuff();
		myBuff.set( origBuff );
	}
}
