// Description: Java 11 edit object instance implementation for CFSec Service.

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

public class CFSecServiceEditObj
	implements ICFSecServiceEditObj
{
	protected ICFSecServiceObj orig;
	protected CFSecServiceBuff buff;
	protected ICFSecSecUserObj createdBy = null;
	protected ICFSecSecUserObj updatedBy = null;
	protected ICFSecClusterObj requiredOwnerCluster;
	protected ICFSecHostNodeObj optionalContainerHost;
	protected ICFSecServiceTypeObj optionalParentServiceType;

	public CFSecServiceEditObj( ICFSecServiceObj argOrig ) {
		orig = argOrig;
		getBuff();
		CFSecServiceBuff origBuff = orig.getBuff();
		buff.set( origBuff );
		requiredOwnerCluster = null;
		optionalContainerHost = null;
		optionalParentServiceType = null;
	}

	public ICFSecSecUserObj getCreatedBy() {
		if( createdBy == null ) {
			CFSecServiceBuff buff = getBuff();
			createdBy = ((ICFSecSchemaObj)getSchema()).getSecUserTableObj().readSecUserByIdIdx( buff.getCreatedByUserId() );
		}
		return( createdBy );
	}

	public Calendar getCreatedAt() {
		return( getBuff().getCreatedAt() );
	}

	public ICFSecSecUserObj getUpdatedBy() {
		if( updatedBy == null ) {
			CFSecServiceBuff buff = getBuff();
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
		return( CFSecServiceObj.CLASS_CODE );
	}

	public String getGenDefName() {
		return( "Service" );
	}

	public ICFLibAnyObj getScope() {
		ICFSecHostNodeObj scope = getOptionalContainerHost();
		return( scope );
	}

	public ICFLibAnyObj getObjScope() {
		ICFSecHostNodeObj scope = getOptionalContainerHost();
		return( scope );
	}

	public String getObjName() {
		String objName;
		long val = getRequiredServiceId();
		objName = Long.toString( val );
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

	public ICFSecServiceObj realise() {
		// We realise this so that it's buffer will get copied to orig during realization
		ICFSecServiceObj retobj = getSchema().getServiceTableObj().realiseService( (ICFSecServiceObj)this );
		return( retobj );
	}

	public void forget() {
		getOrigAsService().forget();
	}

	public ICFSecServiceObj read() {
		ICFSecServiceObj retval = getOrigAsService().read();
		if( retval != orig ) {
			throw new CFLibUsageException( getClass(),
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	public ICFSecServiceObj read( boolean forceRead ) {
		ICFSecServiceObj retval = getOrigAsService().read( forceRead );
		if( retval != orig ) {
			throw new CFLibUsageException( getClass(),
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	public ICFSecServiceObj create() {
		copyBuffToOrig();
		ICFSecServiceObj retobj = ((ICFSecSchemaObj)getOrigAsService().getSchema()).getServiceTableObj().createService( getOrigAsService() );
		if( retobj == getOrigAsService() ) {
			copyOrigToBuff();
		}
		return( retobj );
	}

	public CFSecServiceEditObj update() {
		getSchema().getServiceTableObj().updateService( (ICFSecServiceObj)this );
		return( null );
	}

	public CFSecServiceEditObj deleteInstance() {
		if( getIsNew() ) {
			throw new CFLibUsageException( getClass(), "delete", "Cannot delete a new instance" );
		}
		getSchema().getServiceTableObj().deleteService( getOrigAsService() );
		return( null );
	}

	public ICFSecServiceTableObj getServiceTable() {
		return( orig.getSchema().getServiceTableObj() );
	}

	public ICFSecServiceEditObj getEdit() {
		return( (ICFSecServiceEditObj)this );
	}

	public ICFSecServiceEditObj getEditAsService() {
		return( (ICFSecServiceEditObj)this );
	}

	public ICFSecServiceEditObj beginEdit() {
		throw new CFLibUsageException( getClass(), "beginEdit", "Cannot edit an edition" );
	}

	public void endEdit() {
		orig.endEdit();
	}

	public ICFSecServiceObj getOrig() {
		return( orig );
	}

	public ICFSecServiceObj getOrigAsService() {
		return( (ICFSecServiceObj)orig );
	}

	public ICFSecSchemaObj getSchema() {
		return( orig.getSchema() );
	}

	public CFSecServiceBuff getBuff() {
		if( buff == null ) {
			buff = ((ICFSecSchema)getOrigAsService().getSchema().getBackingStore()).getFactoryService().newBuff();
			buff.set( orig.getBuff() );
		}
		return( buff );
	}

	public void setBuff( CFSecServiceBuff value ) {
		if( buff != value ) {
			buff = value;
			requiredOwnerCluster = null;
			optionalContainerHost = null;
			optionalParentServiceType = null;
		}
	}

	public CFSecServiceBuff getServiceBuff() {
		return( (CFSecServiceBuff)getBuff() );
	}

	public CFSecServicePKey getPKey() {
		return( orig.getPKey() );
	}

	public void setPKey( CFSecServicePKey value ) {
		orig.setPKey( value );
		copyPKeyToBuff();
	}

	public boolean getIsNew() {
		return( orig.getIsNew() );
	}

	public void setIsNew( boolean value ) {
		orig.setIsNew( value );
	}

	public long getRequiredClusterId() {
		return( getPKey().getRequiredClusterId() );
	}

	public long getRequiredServiceId() {
		return( getPKey().getRequiredServiceId() );
	}

	public long getRequiredHostNodeId() {
		return( getServiceBuff().getRequiredHostNodeId() );
	}

	public int getRequiredServiceTypeId() {
		return( getServiceBuff().getRequiredServiceTypeId() );
	}

	public short getRequiredHostPort() {
		return( getServiceBuff().getRequiredHostPort() );
	}

	public void setRequiredHostPort( short value ) {
		if( getServiceBuff().getRequiredHostPort() != value ) {
			getServiceBuff().setRequiredHostPort( value );
		}
	}

	public ICFSecClusterObj getRequiredOwnerCluster() {
		return( getRequiredOwnerCluster( false ) );
	}

	public ICFSecClusterObj getRequiredOwnerCluster( boolean forceRead ) {
		if( forceRead || ( requiredOwnerCluster == null ) ) {
			boolean anyMissing = false;
			if( ! anyMissing ) {
				ICFSecClusterObj obj = ((ICFSecSchemaObj)getOrigAsService().getSchema()).getClusterTableObj().readClusterByIdIdx( getPKey().getRequiredClusterId() );
				requiredOwnerCluster = obj;
			}
		}
		return( requiredOwnerCluster );
	}

	public void setRequiredOwnerCluster( ICFSecClusterObj value ) {
			if( buff == null ) {
				getServiceBuff();
			}
			if( value != null ) {
				getPKey().setRequiredClusterId( value.getRequiredId() );
				getServiceBuff().setRequiredClusterId( value.getRequiredId() );
			}
			requiredOwnerCluster = value;
	}

	public ICFSecHostNodeObj getOptionalContainerHost() {
		return( getOptionalContainerHost( false ) );
	}

	public ICFSecHostNodeObj getOptionalContainerHost( boolean forceRead ) {
		if( forceRead || ( optionalContainerHost == null ) ) {
			boolean anyMissing = false;
			if( ! anyMissing ) {
				ICFSecHostNodeObj obj = ((ICFSecSchemaObj)getOrigAsService().getSchema()).getHostNodeTableObj().readHostNodeByIdIdx( getPKey().getRequiredClusterId(),
					getServiceBuff().getRequiredHostNodeId() );
				optionalContainerHost = obj;
				if( obj != null ) {
					getServiceBuff().setRequiredClusterId( obj.getRequiredClusterId() );
					getServiceBuff().setRequiredHostNodeId( obj.getRequiredHostNodeId() );
					optionalContainerHost = obj;
				}
			}
		}
		return( optionalContainerHost );
	}

	public void setOptionalContainerHost( ICFSecHostNodeObj value ) {
			if( buff == null ) {
				getServiceBuff();
			}
			if( value != null ) {
				getPKey().setRequiredClusterId( value.getRequiredClusterId() );
				getServiceBuff().setRequiredClusterId( value.getRequiredClusterId() );
				getServiceBuff().setRequiredHostNodeId( value.getRequiredHostNodeId() );
			}
			optionalContainerHost = value;
	}

	public ICFSecServiceTypeObj getOptionalParentServiceType() {
		return( getOptionalParentServiceType( false ) );
	}

	public ICFSecServiceTypeObj getOptionalParentServiceType( boolean forceRead ) {
		if( forceRead || ( optionalParentServiceType == null ) ) {
			boolean anyMissing = false;
			if( ! anyMissing ) {
				ICFSecServiceTypeObj obj = ((ICFSecSchemaObj)getOrigAsService().getSchema()).getServiceTypeTableObj().readServiceTypeByIdIdx( getServiceBuff().getRequiredServiceTypeId() );
				optionalParentServiceType = obj;
			}
		}
		return( optionalParentServiceType );
	}

	public void setOptionalParentServiceType( ICFSecServiceTypeObj value ) {
			if( buff == null ) {
				getServiceBuff();
			}
			if( value != null ) {
				getServiceBuff().setRequiredServiceTypeId( value.getRequiredServiceTypeId() );
			}
			else {
			}
			optionalParentServiceType = value;
	}

	public void copyPKeyToBuff() {
		buff.setRequiredClusterId( getPKey().getRequiredClusterId() );
		buff.setRequiredServiceId( getPKey().getRequiredServiceId() );
	}

	public void copyBuffToPKey() {
		getPKey().setRequiredClusterId( buff.getRequiredClusterId() );
		getPKey().setRequiredServiceId( buff.getRequiredServiceId() );
	}

	public void copyBuffToOrig() {
		CFSecServiceBuff origBuff = getOrigAsService().getServiceBuff();
		CFSecServiceBuff myBuff = getServiceBuff();
		origBuff.set( myBuff );
	}

	public void copyOrigToBuff() {
		CFSecServiceBuff origBuff = getOrigAsService().getServiceBuff();
		CFSecServiceBuff myBuff = getServiceBuff();
		myBuff.set( origBuff );
	}
}
