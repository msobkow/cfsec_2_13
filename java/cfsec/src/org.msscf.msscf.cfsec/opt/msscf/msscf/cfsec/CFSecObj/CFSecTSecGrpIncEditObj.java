// Description: Java 11 edit object instance implementation for CFSec TSecGrpInc.

/*
 *	com.github.msobkow.CFSec
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

package com.github.msobkow.cfsec.CFSecObj;

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import com.github.msobkow.cflib.CFLib.*;
import com.github.msobkow.cfsec.CFSec.*;

public class CFSecTSecGrpIncEditObj
	implements ICFSecTSecGrpIncEditObj
{
	protected ICFSecTSecGrpIncObj orig;
	protected CFSecTSecGrpIncBuff buff;
	protected ICFSecSecUserObj createdBy = null;
	protected ICFSecSecUserObj updatedBy = null;
	protected ICFSecTenantObj requiredOwnerTenant;
	protected ICFSecTSecGroupObj requiredContainerGroup;
	protected ICFSecTSecGroupObj requiredParentSubGroup;

	public CFSecTSecGrpIncEditObj( ICFSecTSecGrpIncObj argOrig ) {
		orig = argOrig;
		getBuff();
		CFSecTSecGrpIncBuff origBuff = orig.getBuff();
		buff.set( origBuff );
		requiredOwnerTenant = null;
		requiredContainerGroup = null;
		requiredParentSubGroup = null;
	}

	public ICFSecSecUserObj getCreatedBy() {
		if( createdBy == null ) {
			CFSecTSecGrpIncBuff buff = getBuff();
			createdBy = ((ICFSecSchemaObj)getSchema()).getSecUserTableObj().readSecUserByIdIdx( buff.getCreatedByUserId() );
		}
		return( createdBy );
	}

	public Calendar getCreatedAt() {
		return( getBuff().getCreatedAt() );
	}

	public ICFSecSecUserObj getUpdatedBy() {
		if( updatedBy == null ) {
			CFSecTSecGrpIncBuff buff = getBuff();
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
		return( CFSecTSecGrpIncObj.CLASS_CODE );
	}

	public String getGenDefName() {
		return( "TSecGrpInc" );
	}

	public ICFLibAnyObj getScope() {
		ICFSecTSecGroupObj scope = getRequiredContainerGroup();
		return( scope );
	}

	public ICFLibAnyObj getObjScope() {
		ICFSecTSecGroupObj scope = getRequiredContainerGroup();
		return( scope );
	}

	public String getObjName() {
		String objName;
		long val = getRequiredTSecGrpIncId();
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

	public ICFSecTSecGrpIncObj realise() {
		// We realise this so that it's buffer will get copied to orig during realization
		ICFSecTSecGrpIncObj retobj = getSchema().getTSecGrpIncTableObj().realiseTSecGrpInc( (ICFSecTSecGrpIncObj)this );
		return( retobj );
	}

	public void forget() {
		getOrigAsTSecGrpInc().forget();
	}

	public ICFSecTSecGrpIncObj read() {
		ICFSecTSecGrpIncObj retval = getOrigAsTSecGrpInc().read();
		if( retval != orig ) {
			throw new CFLibUsageException( getClass(),
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	public ICFSecTSecGrpIncObj read( boolean forceRead ) {
		ICFSecTSecGrpIncObj retval = getOrigAsTSecGrpInc().read( forceRead );
		if( retval != orig ) {
			throw new CFLibUsageException( getClass(),
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	public ICFSecTSecGrpIncObj create() {
		copyBuffToOrig();
		ICFSecTSecGrpIncObj retobj = ((ICFSecSchemaObj)getOrigAsTSecGrpInc().getSchema()).getTSecGrpIncTableObj().createTSecGrpInc( getOrigAsTSecGrpInc() );
		if( retobj == getOrigAsTSecGrpInc() ) {
			copyOrigToBuff();
		}
		return( retobj );
	}

	public CFSecTSecGrpIncEditObj update() {
		getSchema().getTSecGrpIncTableObj().updateTSecGrpInc( (ICFSecTSecGrpIncObj)this );
		return( null );
	}

	public CFSecTSecGrpIncEditObj deleteInstance() {
		if( getIsNew() ) {
			throw new CFLibUsageException( getClass(), "delete", "Cannot delete a new instance" );
		}
		getSchema().getTSecGrpIncTableObj().deleteTSecGrpInc( getOrigAsTSecGrpInc() );
		return( null );
	}

	public ICFSecTSecGrpIncTableObj getTSecGrpIncTable() {
		return( orig.getSchema().getTSecGrpIncTableObj() );
	}

	public ICFSecTSecGrpIncEditObj getEdit() {
		return( (ICFSecTSecGrpIncEditObj)this );
	}

	public ICFSecTSecGrpIncEditObj getEditAsTSecGrpInc() {
		return( (ICFSecTSecGrpIncEditObj)this );
	}

	public ICFSecTSecGrpIncEditObj beginEdit() {
		throw new CFLibUsageException( getClass(), "beginEdit", "Cannot edit an edition" );
	}

	public void endEdit() {
		orig.endEdit();
	}

	public ICFSecTSecGrpIncObj getOrig() {
		return( orig );
	}

	public ICFSecTSecGrpIncObj getOrigAsTSecGrpInc() {
		return( (ICFSecTSecGrpIncObj)orig );
	}

	public ICFSecSchemaObj getSchema() {
		return( orig.getSchema() );
	}

	public CFSecTSecGrpIncBuff getBuff() {
		if( buff == null ) {
			buff = ((ICFSecSchema)getOrigAsTSecGrpInc().getSchema().getBackingStore()).getFactoryTSecGrpInc().newBuff();
			buff.set( orig.getBuff() );
		}
		return( buff );
	}

	public void setBuff( CFSecTSecGrpIncBuff value ) {
		if( buff != value ) {
			buff = value;
			requiredOwnerTenant = null;
			requiredContainerGroup = null;
			requiredParentSubGroup = null;
		}
	}

	public CFSecTSecGrpIncBuff getTSecGrpIncBuff() {
		return( (CFSecTSecGrpIncBuff)getBuff() );
	}

	public CFSecTSecGrpIncPKey getPKey() {
		return( orig.getPKey() );
	}

	public void setPKey( CFSecTSecGrpIncPKey value ) {
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

	public long getRequiredTSecGrpIncId() {
		return( getPKey().getRequiredTSecGrpIncId() );
	}

	public int getRequiredTSecGroupId() {
		return( getTSecGrpIncBuff().getRequiredTSecGroupId() );
	}

	public int getRequiredIncludeGroupId() {
		return( getTSecGrpIncBuff().getRequiredIncludeGroupId() );
	}

	public ICFSecTenantObj getRequiredOwnerTenant() {
		return( getRequiredOwnerTenant( false ) );
	}

	public ICFSecTenantObj getRequiredOwnerTenant( boolean forceRead ) {
		if( forceRead || ( requiredOwnerTenant == null ) ) {
			boolean anyMissing = false;
			if( ! anyMissing ) {
				ICFSecTenantObj obj = ((ICFSecSchemaObj)getOrigAsTSecGrpInc().getSchema()).getTenantTableObj().readTenantByIdIdx( getPKey().getRequiredTenantId() );
				requiredOwnerTenant = obj;
			}
		}
		return( requiredOwnerTenant );
	}

	public void setRequiredOwnerTenant( ICFSecTenantObj value ) {
			if( buff == null ) {
				getTSecGrpIncBuff();
			}
			if( value != null ) {
				getPKey().setRequiredTenantId( value.getRequiredId() );
				getTSecGrpIncBuff().setRequiredTenantId( value.getRequiredId() );
			}
			requiredOwnerTenant = value;
	}

	public ICFSecTSecGroupObj getRequiredContainerGroup() {
		return( getRequiredContainerGroup( false ) );
	}

	public ICFSecTSecGroupObj getRequiredContainerGroup( boolean forceRead ) {
		if( forceRead || ( requiredContainerGroup == null ) ) {
			boolean anyMissing = false;
			if( ! anyMissing ) {
				ICFSecTSecGroupObj obj = ((ICFSecSchemaObj)getOrigAsTSecGrpInc().getSchema()).getTSecGroupTableObj().readTSecGroupByIdIdx( getPKey().getRequiredTenantId(),
					getTSecGrpIncBuff().getRequiredTSecGroupId() );
				requiredContainerGroup = obj;
				if( obj != null ) {
					getTSecGrpIncBuff().setRequiredTenantId( obj.getRequiredTenantId() );
					getTSecGrpIncBuff().setRequiredTSecGroupId( obj.getRequiredTSecGroupId() );
					requiredContainerGroup = obj;
				}
			}
		}
		return( requiredContainerGroup );
	}

	public void setRequiredContainerGroup( ICFSecTSecGroupObj value ) {
			if( buff == null ) {
				getTSecGrpIncBuff();
			}
			if( value != null ) {
				getPKey().setRequiredTenantId( value.getRequiredTenantId() );
				getTSecGrpIncBuff().setRequiredTenantId( value.getRequiredTenantId() );
				getTSecGrpIncBuff().setRequiredTSecGroupId( value.getRequiredTSecGroupId() );
			}
			requiredContainerGroup = value;
	}

	public ICFSecTSecGroupObj getRequiredParentSubGroup() {
		return( getRequiredParentSubGroup( false ) );
	}

	public ICFSecTSecGroupObj getRequiredParentSubGroup( boolean forceRead ) {
		if( forceRead || ( requiredParentSubGroup == null ) ) {
			boolean anyMissing = false;
			if( ! anyMissing ) {
				ICFSecTSecGroupObj obj = ((ICFSecSchemaObj)getOrigAsTSecGrpInc().getSchema()).getTSecGroupTableObj().readTSecGroupByIdIdx( getPKey().getRequiredTenantId(),
					getTSecGrpIncBuff().getRequiredIncludeGroupId() );
				requiredParentSubGroup = obj;
			}
		}
		return( requiredParentSubGroup );
	}

	public void setRequiredParentSubGroup( ICFSecTSecGroupObj value ) {
			if( buff == null ) {
				getTSecGrpIncBuff();
			}
			if( value != null ) {
				getPKey().setRequiredTenantId( value.getRequiredTenantId() );
				getTSecGrpIncBuff().setRequiredTenantId( value.getRequiredTenantId() );
				getTSecGrpIncBuff().setRequiredIncludeGroupId( value.getRequiredTSecGroupId() );
			}
			else {
			}
			requiredParentSubGroup = value;
	}

	public void copyPKeyToBuff() {
		buff.setRequiredTenantId( getPKey().getRequiredTenantId() );
		buff.setRequiredTSecGrpIncId( getPKey().getRequiredTSecGrpIncId() );
	}

	public void copyBuffToPKey() {
		getPKey().setRequiredTenantId( buff.getRequiredTenantId() );
		getPKey().setRequiredTSecGrpIncId( buff.getRequiredTSecGrpIncId() );
	}

	public void copyBuffToOrig() {
		CFSecTSecGrpIncBuff origBuff = getOrigAsTSecGrpInc().getTSecGrpIncBuff();
		CFSecTSecGrpIncBuff myBuff = getTSecGrpIncBuff();
		origBuff.set( myBuff );
	}

	public void copyOrigToBuff() {
		CFSecTSecGrpIncBuff origBuff = getOrigAsTSecGrpInc().getTSecGrpIncBuff();
		CFSecTSecGrpIncBuff myBuff = getTSecGrpIncBuff();
		myBuff.set( origBuff );
	}
}
