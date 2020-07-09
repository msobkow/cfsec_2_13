// Description: Java 11 edit object instance implementation for CFSec SecUser.

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

package org.msscf.msscf.cfsec.CFSecObj;

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import com.github.msobkow.cflib.CFLib.*;
import org.msscf.msscf.cfsec.CFSec.*;

public class CFSecSecUserEditObj
	implements ICFSecSecUserEditObj
{
	protected ICFSecSecUserObj orig;
	protected CFSecSecUserBuff buff;
	protected ICFSecSecUserObj createdBy = null;
	protected ICFSecSecUserObj updatedBy = null;
	protected ICFSecSecDeviceObj optionalLookupDefDev;

	public CFSecSecUserEditObj( ICFSecSecUserObj argOrig ) {
		orig = argOrig;
		getBuff();
		CFSecSecUserBuff origBuff = orig.getBuff();
		buff.set( origBuff );
		optionalLookupDefDev = null;
	}

	public ICFSecSecUserObj getCreatedBy() {
		if( createdBy == null ) {
			CFSecSecUserBuff buff = getBuff();
			createdBy = ((ICFSecSchemaObj)getSchema()).getSecUserTableObj().readSecUserByIdIdx( buff.getCreatedByUserId() );
		}
		return( createdBy );
	}

	public Calendar getCreatedAt() {
		return( getBuff().getCreatedAt() );
	}

	public ICFSecSecUserObj getUpdatedBy() {
		if( updatedBy == null ) {
			CFSecSecUserBuff buff = getBuff();
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
		return( CFSecSecUserObj.CLASS_CODE );
	}

	public String getGenDefName() {
		return( "SecUser" );
	}

	public ICFLibAnyObj getScope() {
		return( null );
	}

	public ICFLibAnyObj getObjScope() {
		return( null );
	}

	public String getObjName() {
		String objName;
		objName = getRequiredLoginId();
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
		if( subObj == null ) {
			subObj = ((ICFSecSchemaObj)getSchema()).getSecDeviceTableObj().readSecDeviceByNameIdx( getRequiredSecUserId(),
				nextName, false );
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

	public ICFSecSecUserObj realise() {
		// We realise this so that it's buffer will get copied to orig during realization
		ICFSecSecUserObj retobj = getSchema().getSecUserTableObj().realiseSecUser( (ICFSecSecUserObj)this );
		return( retobj );
	}

	public void forget() {
		getOrigAsSecUser().forget();
	}

	public ICFSecSecUserObj read() {
		ICFSecSecUserObj retval = getOrigAsSecUser().read();
		if( retval != orig ) {
			throw new CFLibUsageException( getClass(),
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	public ICFSecSecUserObj read( boolean forceRead ) {
		ICFSecSecUserObj retval = getOrigAsSecUser().read( forceRead );
		if( retval != orig ) {
			throw new CFLibUsageException( getClass(),
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	public ICFSecSecUserObj create() {
		copyBuffToOrig();
		ICFSecSecUserObj retobj = ((ICFSecSchemaObj)getOrigAsSecUser().getSchema()).getSecUserTableObj().createSecUser( getOrigAsSecUser() );
		if( retobj == getOrigAsSecUser() ) {
			copyOrigToBuff();
		}
		return( retobj );
	}

	public CFSecSecUserEditObj update() {
		getSchema().getSecUserTableObj().updateSecUser( (ICFSecSecUserObj)this );
		return( null );
	}

	public CFSecSecUserEditObj deleteInstance() {
		if( getIsNew() ) {
			throw new CFLibUsageException( getClass(), "delete", "Cannot delete a new instance" );
		}
		getSchema().getSecUserTableObj().deleteSecUser( getOrigAsSecUser() );
		return( null );
	}

	public ICFSecSecUserTableObj getSecUserTable() {
		return( orig.getSchema().getSecUserTableObj() );
	}

	public ICFSecSecUserEditObj getEdit() {
		return( (ICFSecSecUserEditObj)this );
	}

	public ICFSecSecUserEditObj getEditAsSecUser() {
		return( (ICFSecSecUserEditObj)this );
	}

	public ICFSecSecUserEditObj beginEdit() {
		throw new CFLibUsageException( getClass(), "beginEdit", "Cannot edit an edition" );
	}

	public void endEdit() {
		orig.endEdit();
	}

	public ICFSecSecUserObj getOrig() {
		return( orig );
	}

	public ICFSecSecUserObj getOrigAsSecUser() {
		return( (ICFSecSecUserObj)orig );
	}

	public ICFSecSchemaObj getSchema() {
		return( orig.getSchema() );
	}

	public CFSecSecUserBuff getBuff() {
		if( buff == null ) {
			buff = ((ICFSecSchema)getOrigAsSecUser().getSchema().getBackingStore()).getFactorySecUser().newBuff();
			buff.set( orig.getBuff() );
		}
		return( buff );
	}

	public void setBuff( CFSecSecUserBuff value ) {
		if( buff != value ) {
			buff = value;
			optionalLookupDefDev = null;
		}
	}

	public CFSecSecUserBuff getSecUserBuff() {
		return( (CFSecSecUserBuff)getBuff() );
	}

	public CFSecSecUserPKey getPKey() {
		return( orig.getPKey() );
	}

	public void setPKey( CFSecSecUserPKey value ) {
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

	public String getRequiredLoginId() {
		return( getSecUserBuff().getRequiredLoginId() );
	}

	public void setRequiredLoginId( String value ) {
		if( getSecUserBuff().getRequiredLoginId() != value ) {
			getSecUserBuff().setRequiredLoginId( value );
		}
	}

	public String getRequiredEMailAddress() {
		return( getSecUserBuff().getRequiredEMailAddress() );
	}

	public void setRequiredEMailAddress( String value ) {
		if( getSecUserBuff().getRequiredEMailAddress() != value ) {
			getSecUserBuff().setRequiredEMailAddress( value );
		}
	}

	public UUID getOptionalEMailConfirmUuid() {
		return( getSecUserBuff().getOptionalEMailConfirmUuid() );
	}

	public void setOptionalEMailConfirmUuid( UUID value ) {
		if( getSecUserBuff().getOptionalEMailConfirmUuid() != value ) {
			getSecUserBuff().setOptionalEMailConfirmUuid( value );
		}
	}

	public UUID getOptionalDfltDevUserId() {
		return( getSecUserBuff().getOptionalDfltDevUserId() );
	}

	public String getOptionalDfltDevName() {
		return( getSecUserBuff().getOptionalDfltDevName() );
	}

	public String getRequiredPasswordHash() {
		return( getSecUserBuff().getRequiredPasswordHash() );
	}

	public void setRequiredPasswordHash( String value ) {
		if( getSecUserBuff().getRequiredPasswordHash() != value ) {
			getSecUserBuff().setRequiredPasswordHash( value );
		}
	}

	public UUID getOptionalPasswordResetUuid() {
		return( getSecUserBuff().getOptionalPasswordResetUuid() );
	}

	public void setOptionalPasswordResetUuid( UUID value ) {
		if( getSecUserBuff().getOptionalPasswordResetUuid() != value ) {
			getSecUserBuff().setOptionalPasswordResetUuid( value );
		}
	}

	public List<ICFSecSecDeviceObj> getOptionalComponentsSecDev() {
		List<ICFSecSecDeviceObj> retval;
		retval = ((ICFSecSchemaObj)getOrigAsSecUser().getSchema()).getSecDeviceTableObj().readSecDeviceByUserIdx( getPKey().getRequiredSecUserId(),
			false );
		return( retval );
	}

	public List<ICFSecSecDeviceObj> getOptionalComponentsSecDev( boolean forceRead ) {
		List<ICFSecSecDeviceObj> retval;
		retval = ((ICFSecSchemaObj)getOrigAsSecUser().getSchema()).getSecDeviceTableObj().readSecDeviceByUserIdx( getPKey().getRequiredSecUserId(),
			forceRead );
		return( retval );
	}

	public ICFSecSecDeviceObj getOptionalLookupDefDev() {
		return( getOptionalLookupDefDev( false ) );
	}

	public ICFSecSecDeviceObj getOptionalLookupDefDev( boolean forceRead ) {
		if( forceRead || ( optionalLookupDefDev == null ) ) {
			boolean anyMissing = false;
			if( getSecUserBuff().getOptionalDfltDevUserId() == null ) {
				anyMissing = true;
			}
			if( getSecUserBuff().getOptionalDfltDevName() == null ) {
				anyMissing = true;
			}
			if( ! anyMissing ) {
				ICFSecSecDeviceObj obj = ((ICFSecSchemaObj)getOrigAsSecUser().getSchema()).getSecDeviceTableObj().readSecDeviceByIdIdx( getSecUserBuff().getOptionalDfltDevUserId(),
					getSecUserBuff().getOptionalDfltDevName() );
				optionalLookupDefDev = obj;
			}
		}
		return( optionalLookupDefDev );
	}

	public void setOptionalLookupDefDev( ICFSecSecDeviceObj value ) {
			if( buff == null ) {
				getSecUserBuff();
			}
			if( value != null ) {
				getSecUserBuff().setOptionalDfltDevUserId( value.getRequiredSecUserId() );
				getSecUserBuff().setOptionalDfltDevName( value.getRequiredDevName() );
			}
			else {
				getSecUserBuff().setOptionalDfltDevUserId( null );
				getSecUserBuff().setOptionalDfltDevName( null );
			}
			optionalLookupDefDev = value;
	}

	public List<ICFSecSecSessionObj> getOptionalComponentsSecSess() {
		List<ICFSecSecSessionObj> retval;
		retval = ((ICFSecSchemaObj)getOrigAsSecUser().getSchema()).getSecSessionTableObj().readSecSessionBySecUserIdx( getPKey().getRequiredSecUserId(),
			false );
		return( retval );
	}

	public List<ICFSecSecSessionObj> getOptionalComponentsSecSess( boolean forceRead ) {
		List<ICFSecSecSessionObj> retval;
		retval = ((ICFSecSchemaObj)getOrigAsSecUser().getSchema()).getSecSessionTableObj().readSecSessionBySecUserIdx( getPKey().getRequiredSecUserId(),
			forceRead );
		return( retval );
	}

	public List<ICFSecSecSessionObj> getOptionalChildrenSecProxy() {
		List<ICFSecSecSessionObj> retval;
		retval = ((ICFSecSchemaObj)getOrigAsSecUser().getSchema()).getSecSessionTableObj().readSecSessionBySecProxyIdx( getPKey().getRequiredSecUserId(),
			false );
		return( retval );
	}

	public List<ICFSecSecSessionObj> getOptionalChildrenSecProxy( boolean forceRead ) {
		List<ICFSecSecSessionObj> retval;
		retval = ((ICFSecSchemaObj)getOrigAsSecUser().getSchema()).getSecSessionTableObj().readSecSessionBySecProxyIdx( getPKey().getRequiredSecUserId(),
			forceRead );
		return( retval );
	}

	public List<ICFSecSecGrpMembObj> getOptionalChildrenSecGrpMemb() {
		List<ICFSecSecGrpMembObj> retval;
		retval = ((ICFSecSchemaObj)getOrigAsSecUser().getSchema()).getSecGrpMembTableObj().readSecGrpMembByUserIdx( getPKey().getRequiredSecUserId(),
			false );
		return( retval );
	}

	public List<ICFSecSecGrpMembObj> getOptionalChildrenSecGrpMemb( boolean forceRead ) {
		List<ICFSecSecGrpMembObj> retval;
		retval = ((ICFSecSchemaObj)getOrigAsSecUser().getSchema()).getSecGrpMembTableObj().readSecGrpMembByUserIdx( getPKey().getRequiredSecUserId(),
			forceRead );
		return( retval );
	}

	public List<ICFSecTSecGrpMembObj> getOptionalChildrenTSecGrpMemb() {
		List<ICFSecTSecGrpMembObj> retval;
		retval = ((ICFSecSchemaObj)getOrigAsSecUser().getSchema()).getTSecGrpMembTableObj().readTSecGrpMembByUserIdx( getPKey().getRequiredSecUserId(),
			false );
		return( retval );
	}

	public List<ICFSecTSecGrpMembObj> getOptionalChildrenTSecGrpMemb( boolean forceRead ) {
		List<ICFSecTSecGrpMembObj> retval;
		retval = ((ICFSecSchemaObj)getOrigAsSecUser().getSchema()).getTSecGrpMembTableObj().readTSecGrpMembByUserIdx( getPKey().getRequiredSecUserId(),
			forceRead );
		return( retval );
	}

	public void copyPKeyToBuff() {
		buff.setRequiredSecUserId( getPKey().getRequiredSecUserId() );
	}

	public void copyBuffToPKey() {
		getPKey().setRequiredSecUserId( buff.getRequiredSecUserId() );
	}

	public void copyBuffToOrig() {
		CFSecSecUserBuff origBuff = getOrigAsSecUser().getSecUserBuff();
		CFSecSecUserBuff myBuff = getSecUserBuff();
		origBuff.set( myBuff );
	}

	public void copyOrigToBuff() {
		CFSecSecUserBuff origBuff = getOrigAsSecUser().getSecUserBuff();
		CFSecSecUserBuff myBuff = getSecUserBuff();
		myBuff.set( origBuff );
	}
}
