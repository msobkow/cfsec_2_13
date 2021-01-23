// Description: Java 11 edit object instance implementation for CFSec SecGroup.

/*
 *	org.msscf.msscf.CFSec
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFSec 2.13 Security Essentials
 *	
 *	Copyright 2020-2021 Mark Stephen Sobkow mark.sobkow@gmail.com
 *	
 *	Licensed under the Apache License, Version 2.0 (the "License");
 *	you may not use this file except in compliance with the License.
 *	You may obtain a copy of the License at
 *	
 *	http://www.apache.org/licenses/LICENSE-2.0
 *	
 *	Unless required by applicable law or agreed to in writing, software
 *	distributed under the License is distributed on an "AS IS" BASIS,
 *	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *	See the License for the specific language governing permissions and
 *	limitations under the License.
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

public class CFSecSecGroupEditObj
	implements ICFSecSecGroupEditObj
{
	protected ICFSecSecGroupObj orig;
	protected CFSecSecGroupBuff buff;
	protected ICFSecSecUserObj createdBy = null;
	protected ICFSecSecUserObj updatedBy = null;
	protected ICFSecClusterObj requiredContainerCluster;

	public CFSecSecGroupEditObj( ICFSecSecGroupObj argOrig ) {
		orig = argOrig;
		getBuff();
		CFSecSecGroupBuff origBuff = orig.getBuff();
		buff.set( origBuff );
		requiredContainerCluster = null;
	}

	public ICFSecSecUserObj getCreatedBy() {
		if( createdBy == null ) {
			CFSecSecGroupBuff buff = getBuff();
			createdBy = ((ICFSecSchemaObj)getSchema()).getSecUserTableObj().readSecUserByIdIdx( buff.getCreatedByUserId() );
		}
		return( createdBy );
	}

	public Calendar getCreatedAt() {
		return( getBuff().getCreatedAt() );
	}

	public ICFSecSecUserObj getUpdatedBy() {
		if( updatedBy == null ) {
			CFSecSecGroupBuff buff = getBuff();
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
		return( CFSecSecGroupObj.CLASS_CODE );
	}

	public String getGenDefName() {
		return( "SecGroup" );
	}

	public ICFLibAnyObj getScope() {
		ICFSecClusterObj scope = getRequiredContainerCluster();
		return( scope );
	}

	public ICFLibAnyObj getObjScope() {
		ICFSecClusterObj scope = getRequiredContainerCluster();
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

	public ICFSecSecGroupObj realise() {
		// We realise this so that it's buffer will get copied to orig during realization
		ICFSecSecGroupObj retobj = getSchema().getSecGroupTableObj().realiseSecGroup( (ICFSecSecGroupObj)this );
		return( retobj );
	}

	public void forget() {
		getOrigAsSecGroup().forget();
	}

	public ICFSecSecGroupObj read() {
		ICFSecSecGroupObj retval = getOrigAsSecGroup().read();
		if( retval != orig ) {
			throw new CFLibUsageException( getClass(),
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	public ICFSecSecGroupObj read( boolean forceRead ) {
		ICFSecSecGroupObj retval = getOrigAsSecGroup().read( forceRead );
		if( retval != orig ) {
			throw new CFLibUsageException( getClass(),
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	public ICFSecSecGroupObj create() {
		copyBuffToOrig();
		ICFSecSecGroupObj retobj = ((ICFSecSchemaObj)getOrigAsSecGroup().getSchema()).getSecGroupTableObj().createSecGroup( getOrigAsSecGroup() );
		if( retobj == getOrigAsSecGroup() ) {
			copyOrigToBuff();
		}
		return( retobj );
	}

	public CFSecSecGroupEditObj update() {
		getSchema().getSecGroupTableObj().updateSecGroup( (ICFSecSecGroupObj)this );
		return( null );
	}

	public CFSecSecGroupEditObj deleteInstance() {
		if( getIsNew() ) {
			throw new CFLibUsageException( getClass(), "delete", "Cannot delete a new instance" );
		}
		getSchema().getSecGroupTableObj().deleteSecGroup( getOrigAsSecGroup() );
		return( null );
	}

	public ICFSecSecGroupTableObj getSecGroupTable() {
		return( orig.getSchema().getSecGroupTableObj() );
	}

	public ICFSecSecGroupEditObj getEdit() {
		return( (ICFSecSecGroupEditObj)this );
	}

	public ICFSecSecGroupEditObj getEditAsSecGroup() {
		return( (ICFSecSecGroupEditObj)this );
	}

	public ICFSecSecGroupEditObj beginEdit() {
		throw new CFLibUsageException( getClass(), "beginEdit", "Cannot edit an edition" );
	}

	public void endEdit() {
		orig.endEdit();
	}

	public ICFSecSecGroupObj getOrig() {
		return( orig );
	}

	public ICFSecSecGroupObj getOrigAsSecGroup() {
		return( (ICFSecSecGroupObj)orig );
	}

	public ICFSecSchemaObj getSchema() {
		return( orig.getSchema() );
	}

	public CFSecSecGroupBuff getBuff() {
		if( buff == null ) {
			buff = ((ICFSecSchema)getOrigAsSecGroup().getSchema().getBackingStore()).getFactorySecGroup().newBuff();
			buff.set( orig.getBuff() );
		}
		return( buff );
	}

	public void setBuff( CFSecSecGroupBuff value ) {
		if( buff != value ) {
			buff = value;
			requiredContainerCluster = null;
		}
	}

	public CFSecSecGroupBuff getSecGroupBuff() {
		return( (CFSecSecGroupBuff)getBuff() );
	}

	public CFSecSecGroupPKey getPKey() {
		return( orig.getPKey() );
	}

	public void setPKey( CFSecSecGroupPKey value ) {
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

	public int getRequiredSecGroupId() {
		return( getPKey().getRequiredSecGroupId() );
	}

	public String getRequiredName() {
		return( getSecGroupBuff().getRequiredName() );
	}

	public void setRequiredName( String value ) {
		if( getSecGroupBuff().getRequiredName() != value ) {
			getSecGroupBuff().setRequiredName( value );
		}
	}

	public boolean getRequiredIsVisible() {
		return( getSecGroupBuff().getRequiredIsVisible() );
	}

	public void setRequiredIsVisible( boolean value ) {
		if( getSecGroupBuff().getRequiredIsVisible() != value ) {
			getSecGroupBuff().setRequiredIsVisible( value );
		}
	}

	public ICFSecClusterObj getRequiredContainerCluster() {
		return( getRequiredContainerCluster( false ) );
	}

	public ICFSecClusterObj getRequiredContainerCluster( boolean forceRead ) {
		if( forceRead || ( requiredContainerCluster == null ) ) {
			boolean anyMissing = false;
			if( ! anyMissing ) {
				ICFSecClusterObj obj = ((ICFSecSchemaObj)getOrigAsSecGroup().getSchema()).getClusterTableObj().readClusterByIdIdx( getPKey().getRequiredClusterId() );
				requiredContainerCluster = obj;
				if( obj != null ) {
					getSecGroupBuff().setRequiredClusterId( obj.getRequiredId() );
					requiredContainerCluster = obj;
				}
			}
		}
		return( requiredContainerCluster );
	}

	public void setRequiredContainerCluster( ICFSecClusterObj value ) {
			if( buff == null ) {
				getSecGroupBuff();
			}
			if( value != null ) {
				getPKey().setRequiredClusterId( value.getRequiredId() );
				getSecGroupBuff().setRequiredClusterId( value.getRequiredId() );
			}
			requiredContainerCluster = value;
	}

	public List<ICFSecSecGrpIncObj> getOptionalComponentsInclude() {
		List<ICFSecSecGrpIncObj> retval;
		retval = ((ICFSecSchemaObj)getOrigAsSecGroup().getSchema()).getSecGrpIncTableObj().readSecGrpIncByGroupIdx( getPKey().getRequiredClusterId(),
					getPKey().getRequiredSecGroupId(),
			false );
		return( retval );
	}

	public List<ICFSecSecGrpIncObj> getOptionalComponentsInclude( boolean forceRead ) {
		List<ICFSecSecGrpIncObj> retval;
		retval = ((ICFSecSchemaObj)getOrigAsSecGroup().getSchema()).getSecGrpIncTableObj().readSecGrpIncByGroupIdx( getPKey().getRequiredClusterId(),
					getPKey().getRequiredSecGroupId(),
			forceRead );
		return( retval );
	}

	public List<ICFSecSecGrpMembObj> getOptionalComponentsMember() {
		List<ICFSecSecGrpMembObj> retval;
		retval = ((ICFSecSchemaObj)getOrigAsSecGroup().getSchema()).getSecGrpMembTableObj().readSecGrpMembByGroupIdx( getPKey().getRequiredClusterId(),
					getPKey().getRequiredSecGroupId(),
			false );
		return( retval );
	}

	public List<ICFSecSecGrpMembObj> getOptionalComponentsMember( boolean forceRead ) {
		List<ICFSecSecGrpMembObj> retval;
		retval = ((ICFSecSchemaObj)getOrigAsSecGroup().getSchema()).getSecGrpMembTableObj().readSecGrpMembByGroupIdx( getPKey().getRequiredClusterId(),
					getPKey().getRequiredSecGroupId(),
			forceRead );
		return( retval );
	}

	public List<ICFSecSecGrpIncObj> getRequiredChildrenIncByGroup() {
		List<ICFSecSecGrpIncObj> retval;
		retval = ((ICFSecSchemaObj)getOrigAsSecGroup().getSchema()).getSecGrpIncTableObj().readSecGrpIncByIncludeIdx( getPKey().getRequiredClusterId(),
					getPKey().getRequiredSecGroupId(),
			false );
		return( retval );
	}

	public List<ICFSecSecGrpIncObj> getRequiredChildrenIncByGroup( boolean forceRead ) {
		List<ICFSecSecGrpIncObj> retval;
		retval = ((ICFSecSchemaObj)getOrigAsSecGroup().getSchema()).getSecGrpIncTableObj().readSecGrpIncByIncludeIdx( getPKey().getRequiredClusterId(),
					getPKey().getRequiredSecGroupId(),
			forceRead );
		return( retval );
	}

	public List<ICFSecSecGroupFormObj> getOptionalComponentsForm() {
		List<ICFSecSecGroupFormObj> retval;
		retval = ((ICFSecSchemaObj)getOrigAsSecGroup().getSchema()).getSecGroupFormTableObj().readSecGroupFormByGroupIdx( getPKey().getRequiredClusterId(),
					getPKey().getRequiredSecGroupId(),
			false );
		return( retval );
	}

	public List<ICFSecSecGroupFormObj> getOptionalComponentsForm( boolean forceRead ) {
		List<ICFSecSecGroupFormObj> retval;
		retval = ((ICFSecSchemaObj)getOrigAsSecGroup().getSchema()).getSecGroupFormTableObj().readSecGroupFormByGroupIdx( getPKey().getRequiredClusterId(),
					getPKey().getRequiredSecGroupId(),
			forceRead );
		return( retval );
	}

	public void copyPKeyToBuff() {
		buff.setRequiredClusterId( getPKey().getRequiredClusterId() );
		buff.setRequiredSecGroupId( getPKey().getRequiredSecGroupId() );
	}

	public void copyBuffToPKey() {
		getPKey().setRequiredClusterId( buff.getRequiredClusterId() );
		getPKey().setRequiredSecGroupId( buff.getRequiredSecGroupId() );
	}

	public void copyBuffToOrig() {
		CFSecSecGroupBuff origBuff = getOrigAsSecGroup().getSecGroupBuff();
		CFSecSecGroupBuff myBuff = getSecGroupBuff();
		origBuff.set( myBuff );
	}

	public void copyOrigToBuff() {
		CFSecSecGroupBuff origBuff = getOrigAsSecGroup().getSecGroupBuff();
		CFSecSecGroupBuff myBuff = getSecGroupBuff();
		myBuff.set( origBuff );
	}
}
