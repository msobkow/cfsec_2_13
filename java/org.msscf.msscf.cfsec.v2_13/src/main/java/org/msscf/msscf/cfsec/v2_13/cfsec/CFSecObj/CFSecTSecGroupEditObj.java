// Description: Java 11 edit object instance implementation for CFSec TSecGroup.

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

public class CFSecTSecGroupEditObj
	implements ICFSecTSecGroupEditObj
{
	protected ICFSecTSecGroupObj orig;
	protected CFSecTSecGroupBuff buff;
	protected ICFSecSecUserObj createdBy = null;
	protected ICFSecSecUserObj updatedBy = null;
	protected ICFSecTenantObj requiredContainerTenant;

	public CFSecTSecGroupEditObj( ICFSecTSecGroupObj argOrig ) {
		orig = argOrig;
		getBuff();
		CFSecTSecGroupBuff origBuff = orig.getBuff();
		buff.set( origBuff );
		requiredContainerTenant = null;
	}

	public ICFSecSecUserObj getCreatedBy() {
		if( createdBy == null ) {
			CFSecTSecGroupBuff buff = getBuff();
			createdBy = ((ICFSecSchemaObj)getSchema()).getSecUserTableObj().readSecUserByIdIdx( buff.getCreatedByUserId() );
		}
		return( createdBy );
	}

	public Calendar getCreatedAt() {
		return( getBuff().getCreatedAt() );
	}

	public ICFSecSecUserObj getUpdatedBy() {
		if( updatedBy == null ) {
			CFSecTSecGroupBuff buff = getBuff();
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
		return( CFSecTSecGroupObj.CLASS_CODE );
	}

	public String getGenDefName() {
		return( "TSecGroup" );
	}

	public ICFLibAnyObj getScope() {
		ICFSecTenantObj scope = getRequiredContainerTenant();
		return( scope );
	}

	public ICFLibAnyObj getObjScope() {
		ICFSecTenantObj scope = getRequiredContainerTenant();
		return( scope );
	}

	public String getObjName() {
		String objName;
		objName = getRequiredName();
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

	public ICFSecTSecGroupObj realise() {
		// We realise this so that it's buffer will get copied to orig during realization
		ICFSecTSecGroupObj retobj = getSchema().getTSecGroupTableObj().realiseTSecGroup( (ICFSecTSecGroupObj)this );
		return( retobj );
	}

	public void forget() {
		getOrigAsTSecGroup().forget();
	}

	public ICFSecTSecGroupObj read() {
		ICFSecTSecGroupObj retval = getOrigAsTSecGroup().read();
		if( retval != orig ) {
			throw new CFLibUsageException( getClass(),
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	public ICFSecTSecGroupObj read( boolean forceRead ) {
		ICFSecTSecGroupObj retval = getOrigAsTSecGroup().read( forceRead );
		if( retval != orig ) {
			throw new CFLibUsageException( getClass(),
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	public ICFSecTSecGroupObj create() {
		copyBuffToOrig();
		ICFSecTSecGroupObj retobj = ((ICFSecSchemaObj)getOrigAsTSecGroup().getSchema()).getTSecGroupTableObj().createTSecGroup( getOrigAsTSecGroup() );
		if( retobj == getOrigAsTSecGroup() ) {
			copyOrigToBuff();
		}
		return( retobj );
	}

	public CFSecTSecGroupEditObj update() {
		getSchema().getTSecGroupTableObj().updateTSecGroup( (ICFSecTSecGroupObj)this );
		return( null );
	}

	public CFSecTSecGroupEditObj deleteInstance() {
		if( getIsNew() ) {
			throw new CFLibUsageException( getClass(), "delete", "Cannot delete a new instance" );
		}
		getSchema().getTSecGroupTableObj().deleteTSecGroup( getOrigAsTSecGroup() );
		return( null );
	}

	public ICFSecTSecGroupTableObj getTSecGroupTable() {
		return( orig.getSchema().getTSecGroupTableObj() );
	}

	public ICFSecTSecGroupEditObj getEdit() {
		return( (ICFSecTSecGroupEditObj)this );
	}

	public ICFSecTSecGroupEditObj getEditAsTSecGroup() {
		return( (ICFSecTSecGroupEditObj)this );
	}

	public ICFSecTSecGroupEditObj beginEdit() {
		throw new CFLibUsageException( getClass(), "beginEdit", "Cannot edit an edition" );
	}

	public void endEdit() {
		orig.endEdit();
	}

	public ICFSecTSecGroupObj getOrig() {
		return( orig );
	}

	public ICFSecTSecGroupObj getOrigAsTSecGroup() {
		return( (ICFSecTSecGroupObj)orig );
	}

	public ICFSecSchemaObj getSchema() {
		return( orig.getSchema() );
	}

	public CFSecTSecGroupBuff getBuff() {
		if( buff == null ) {
			buff = ((ICFSecSchema)getOrigAsTSecGroup().getSchema().getBackingStore()).getFactoryTSecGroup().newBuff();
			buff.set( orig.getBuff() );
		}
		return( buff );
	}

	public void setBuff( CFSecTSecGroupBuff value ) {
		if( buff != value ) {
			buff = value;
			requiredContainerTenant = null;
		}
	}

	public CFSecTSecGroupBuff getTSecGroupBuff() {
		return( (CFSecTSecGroupBuff)getBuff() );
	}

	public CFSecTSecGroupPKey getPKey() {
		return( orig.getPKey() );
	}

	public void setPKey( CFSecTSecGroupPKey value ) {
		orig.setPKey( value );
		copyPKeyToBuff();
	}

	public boolean getIsNew() {
		return( orig.getIsNew() );
	}

	public void setIsNew( boolean value ) {
		orig.setIsNew( value );
	}

	public long getRequiredTenantId() {
		return( getPKey().getRequiredTenantId() );
	}

	public int getRequiredTSecGroupId() {
		return( getPKey().getRequiredTSecGroupId() );
	}

	public String getRequiredName() {
		return( getTSecGroupBuff().getRequiredName() );
	}

	public void setRequiredName( String value ) {
		if( getTSecGroupBuff().getRequiredName() != value ) {
			getTSecGroupBuff().setRequiredName( value );
		}
	}

	public boolean getRequiredIsVisible() {
		return( getTSecGroupBuff().getRequiredIsVisible() );
	}

	public void setRequiredIsVisible( boolean value ) {
		if( getTSecGroupBuff().getRequiredIsVisible() != value ) {
			getTSecGroupBuff().setRequiredIsVisible( value );
		}
	}

	public ICFSecTenantObj getRequiredContainerTenant() {
		return( getRequiredContainerTenant( false ) );
	}

	public ICFSecTenantObj getRequiredContainerTenant( boolean forceRead ) {
		if( forceRead || ( requiredContainerTenant == null ) ) {
			boolean anyMissing = false;
			if( ! anyMissing ) {
				ICFSecTenantObj obj = ((ICFSecSchemaObj)getOrigAsTSecGroup().getSchema()).getTenantTableObj().readTenantByIdIdx( getPKey().getRequiredTenantId() );
				requiredContainerTenant = obj;
				if( obj != null ) {
					getTSecGroupBuff().setRequiredTenantId( obj.getRequiredId() );
					requiredContainerTenant = obj;
				}
			}
		}
		return( requiredContainerTenant );
	}

	public void setRequiredContainerTenant( ICFSecTenantObj value ) {
			if( buff == null ) {
				getTSecGroupBuff();
			}
			if( value != null ) {
				getPKey().setRequiredTenantId( value.getRequiredId() );
				getTSecGroupBuff().setRequiredTenantId( value.getRequiredId() );
			}
			requiredContainerTenant = value;
	}

	public List<ICFSecTSecGrpIncObj> getOptionalComponentsInclude() {
		List<ICFSecTSecGrpIncObj> retval;
		retval = ((ICFSecSchemaObj)getOrigAsTSecGroup().getSchema()).getTSecGrpIncTableObj().readTSecGrpIncByGroupIdx( getPKey().getRequiredTenantId(),
					getPKey().getRequiredTSecGroupId(),
			false );
		return( retval );
	}

	public List<ICFSecTSecGrpIncObj> getOptionalComponentsInclude( boolean forceRead ) {
		List<ICFSecTSecGrpIncObj> retval;
		retval = ((ICFSecSchemaObj)getOrigAsTSecGroup().getSchema()).getTSecGrpIncTableObj().readTSecGrpIncByGroupIdx( getPKey().getRequiredTenantId(),
					getPKey().getRequiredTSecGroupId(),
			forceRead );
		return( retval );
	}

	public List<ICFSecTSecGrpMembObj> getOptionalComponentsMember() {
		List<ICFSecTSecGrpMembObj> retval;
		retval = ((ICFSecSchemaObj)getOrigAsTSecGroup().getSchema()).getTSecGrpMembTableObj().readTSecGrpMembByGroupIdx( getPKey().getRequiredTenantId(),
					getPKey().getRequiredTSecGroupId(),
			false );
		return( retval );
	}

	public List<ICFSecTSecGrpMembObj> getOptionalComponentsMember( boolean forceRead ) {
		List<ICFSecTSecGrpMembObj> retval;
		retval = ((ICFSecSchemaObj)getOrigAsTSecGroup().getSchema()).getTSecGrpMembTableObj().readTSecGrpMembByGroupIdx( getPKey().getRequiredTenantId(),
					getPKey().getRequiredTSecGroupId(),
			forceRead );
		return( retval );
	}

	public List<ICFSecTSecGrpIncObj> getRequiredChildrenIncByGroup() {
		List<ICFSecTSecGrpIncObj> retval;
		retval = ((ICFSecSchemaObj)getOrigAsTSecGroup().getSchema()).getTSecGrpIncTableObj().readTSecGrpIncByIncludeIdx( getPKey().getRequiredTenantId(),
					getPKey().getRequiredTSecGroupId(),
			false );
		return( retval );
	}

	public List<ICFSecTSecGrpIncObj> getRequiredChildrenIncByGroup( boolean forceRead ) {
		List<ICFSecTSecGrpIncObj> retval;
		retval = ((ICFSecSchemaObj)getOrigAsTSecGroup().getSchema()).getTSecGrpIncTableObj().readTSecGrpIncByIncludeIdx( getPKey().getRequiredTenantId(),
					getPKey().getRequiredTSecGroupId(),
			forceRead );
		return( retval );
	}

	public void copyPKeyToBuff() {
		buff.setRequiredTenantId( getPKey().getRequiredTenantId() );
		buff.setRequiredTSecGroupId( getPKey().getRequiredTSecGroupId() );
	}

	public void copyBuffToPKey() {
		getPKey().setRequiredTenantId( buff.getRequiredTenantId() );
		getPKey().setRequiredTSecGroupId( buff.getRequiredTSecGroupId() );
	}

	public void copyBuffToOrig() {
		CFSecTSecGroupBuff origBuff = getOrigAsTSecGroup().getTSecGroupBuff();
		CFSecTSecGroupBuff myBuff = getTSecGroupBuff();
		origBuff.set( myBuff );
	}

	public void copyOrigToBuff() {
		CFSecTSecGroupBuff origBuff = getOrigAsTSecGroup().getTSecGroupBuff();
		CFSecTSecGroupBuff myBuff = getTSecGroupBuff();
		myBuff.set( origBuff );
	}
}
