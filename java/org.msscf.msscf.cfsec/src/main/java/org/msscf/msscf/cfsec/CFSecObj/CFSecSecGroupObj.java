// Description: Java 11 base object instance implementation for CFSec SecGroup.

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

package org.msscf.msscf.cfsec.CFSecObj;

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.msscf.msscf.cflib.CFLib.*;
import org.msscf.msscf.cfsec.CFSec.*;

public class CFSecSecGroupObj
	implements ICFSecSecGroupObj
{
	public final static String CLASS_CODE = "a00c";
	protected ICFSecSecUserObj createdBy = null;
	protected ICFSecSecUserObj updatedBy = null;
	protected boolean isNew;
	protected ICFSecSecGroupEditObj edit;
	protected ICFSecSchemaObj schema;
	protected CFSecSecGroupPKey pKey;
	protected CFSecSecGroupBuff buff;
	protected ICFSecClusterObj requiredContainerCluster;

	public CFSecSecGroupObj() {
		isNew = true;
		requiredContainerCluster = null;
	}

	public CFSecSecGroupObj( ICFSecSchemaObj argSchema ) {
		schema = argSchema;
		isNew = true;
		edit = null;
		requiredContainerCluster = null;
	}

	public String getClassCode() {
		return( CLASS_CODE );
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
		ICFSecSecGroupObj retobj = ((ICFSecSchemaObj)schema).getSecGroupTableObj().realiseSecGroup(
			(ICFSecSecGroupObj)this );
		return( (ICFSecSecGroupObj)retobj );
	}

	public void forget() {
		((ICFSecSchemaObj)schema).getSecGroupTableObj().reallyDeepDisposeSecGroup( (ICFSecSecGroupObj)this );
	}

	public ICFSecSecGroupObj read() {
		ICFSecSecGroupObj retobj = ((ICFSecSchemaObj)schema).getSecGroupTableObj().readSecGroupByIdIdx( getPKey().getRequiredClusterId(),
			getPKey().getRequiredSecGroupId(), false );
		return( (ICFSecSecGroupObj)retobj );
	}

	public ICFSecSecGroupObj read( boolean forceRead ) {
		ICFSecSecGroupObj retobj = ((ICFSecSchemaObj)schema).getSecGroupTableObj().readSecGroupByIdIdx( getPKey().getRequiredClusterId(),
			getPKey().getRequiredSecGroupId(), forceRead );
		return( (ICFSecSecGroupObj)retobj );
	}

	public ICFSecSecGroupTableObj getSecGroupTable() {
		return( ((ICFSecSchemaObj)schema).getSecGroupTableObj() );
	}

	public ICFSecSchemaObj getSchema() {
		return( schema );
	}

	public void setSchema( ICFSecSchemaObj value ) {
		schema = value;
	}

	public CFSecSecGroupBuff getBuff() {
		if( buff == null ) {
			if( isNew ) {
				buff = ((ICFSecSchema)schema.getBackingStore()).getFactorySecGroup().newBuff();
			}
			else {
				// Read the data buff via the backing store
				buff = ((ICFSecSchema)schema.getBackingStore()).getTableSecGroup().readDerivedByIdIdx( ((ICFSecSchemaObj)schema).getAuthorization(),
						getPKey().getRequiredClusterId(),
						getPKey().getRequiredSecGroupId() );
				if( buff != null ) {
					copyBuffToPKey();
				}
			}
		}
		return( buff );
	}

	public void setBuff( CFSecSecGroupBuff value ) {
		if( ! ( ( value == null ) || ( value instanceof CFSecSecGroupBuff ) ) ) {
			throw new CFLibUnsupportedClassException( getClass(),
				"setBuff",
				"value",
				value,
				"CFSecSecGroupBuff" );
		}
		buff = value;
		copyBuffToPKey();
		requiredContainerCluster = null;
	}

	public CFSecSecGroupBuff getSecGroupBuff() {
		return( (CFSecSecGroupBuff)getBuff() );
	}

	public CFSecSecGroupPKey getPKey() {
		if( pKey == null ) {
			pKey = ((ICFSecSchema)schema.getBackingStore()).getFactorySecGroup().newPKey();
		}
		return( pKey );
	}

	public void setPKey( CFSecSecGroupPKey value ) {
		if( pKey != value ) {
			pKey = value;
			copyPKeyToBuff();
		}
	}

	public boolean getIsNew() {
		return( isNew );
	}

	public void setIsNew( boolean value ) {
		isNew = value;
	}

	public ICFSecSecGroupEditObj beginEdit() {
		if( edit != null ) {
			throw new CFLibUsageException( getClass(), "beginEdit", "An edit is already open" );
		}
		ICFSecSecGroupObj lockobj;
		if( getIsNew() ) {
			lockobj = (ICFSecSecGroupObj)this;
		}
		else {
			lockobj = ((ICFSecSchemaObj)schema).getSecGroupTableObj().lockSecGroup( getPKey() );
		}
		edit = ((ICFSecSchemaObj)schema).getSecGroupTableObj().newEditInstance( lockobj );
		return( (ICFSecSecGroupEditObj)edit );
	}

	public void endEdit() {
		edit = null;
	}

	public ICFSecSecGroupEditObj getEdit() {
		return( edit );
	}

	public ICFSecSecGroupEditObj getEditAsSecGroup() {
		return( (ICFSecSecGroupEditObj)edit );
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

	public long getRequiredClusterId() {
		return( getPKey().getRequiredClusterId() );
	}

	public int getRequiredSecGroupId() {
		return( getPKey().getRequiredSecGroupId() );
	}

	public String getRequiredName() {
		return( getSecGroupBuff().getRequiredName() );
	}

	public boolean getRequiredIsVisible() {
		return( getSecGroupBuff().getRequiredIsVisible() );
	}

	public ICFSecClusterObj getRequiredContainerCluster() {
		return( getRequiredContainerCluster( false ) );
	}

	public ICFSecClusterObj getRequiredContainerCluster( boolean forceRead ) {
		if( ( requiredContainerCluster == null ) || forceRead ) {
			boolean anyMissing = false;
			if( ! anyMissing ) {
				requiredContainerCluster = ((ICFSecSchemaObj)schema).getClusterTableObj().readClusterByIdIdx( getPKey().getRequiredClusterId(), forceRead );
			}
		}
		return( requiredContainerCluster );
	}

	public List<ICFSecSecGrpIncObj> getOptionalComponentsInclude() {
		List<ICFSecSecGrpIncObj> retval;
		retval = ((ICFSecSchemaObj)schema).getSecGrpIncTableObj().readSecGrpIncByGroupIdx( getPKey().getRequiredClusterId(),
					getPKey().getRequiredSecGroupId(),
			false );
		return( retval );
	}

	public List<ICFSecSecGrpIncObj> getOptionalComponentsInclude( boolean forceRead ) {
		List<ICFSecSecGrpIncObj> retval;
		retval = ((ICFSecSchemaObj)schema).getSecGrpIncTableObj().readSecGrpIncByGroupIdx( getPKey().getRequiredClusterId(),
					getPKey().getRequiredSecGroupId(),
			forceRead );
		return( retval );
	}

	public List<ICFSecSecGrpMembObj> getOptionalComponentsMember() {
		List<ICFSecSecGrpMembObj> retval;
		retval = ((ICFSecSchemaObj)schema).getSecGrpMembTableObj().readSecGrpMembByGroupIdx( getPKey().getRequiredClusterId(),
					getPKey().getRequiredSecGroupId(),
			false );
		return( retval );
	}

	public List<ICFSecSecGrpMembObj> getOptionalComponentsMember( boolean forceRead ) {
		List<ICFSecSecGrpMembObj> retval;
		retval = ((ICFSecSchemaObj)schema).getSecGrpMembTableObj().readSecGrpMembByGroupIdx( getPKey().getRequiredClusterId(),
					getPKey().getRequiredSecGroupId(),
			forceRead );
		return( retval );
	}

	public List<ICFSecSecGrpIncObj> getRequiredChildrenIncByGroup() {
		List<ICFSecSecGrpIncObj> retval;
		retval = ((ICFSecSchemaObj)schema).getSecGrpIncTableObj().readSecGrpIncByIncludeIdx( getPKey().getRequiredClusterId(),
					getPKey().getRequiredSecGroupId(),
			false );
		return( retval );
	}

	public List<ICFSecSecGrpIncObj> getRequiredChildrenIncByGroup( boolean forceRead ) {
		List<ICFSecSecGrpIncObj> retval;
		retval = ((ICFSecSchemaObj)schema).getSecGrpIncTableObj().readSecGrpIncByIncludeIdx( getPKey().getRequiredClusterId(),
					getPKey().getRequiredSecGroupId(),
			forceRead );
		return( retval );
	}

	public List<ICFSecSecGroupFormObj> getOptionalComponentsForm() {
		List<ICFSecSecGroupFormObj> retval;
		retval = ((ICFSecSchemaObj)schema).getSecGroupFormTableObj().readSecGroupFormByGroupIdx( getPKey().getRequiredClusterId(),
					getPKey().getRequiredSecGroupId(),
			false );
		return( retval );
	}

	public List<ICFSecSecGroupFormObj> getOptionalComponentsForm( boolean forceRead ) {
		List<ICFSecSecGroupFormObj> retval;
		retval = ((ICFSecSchemaObj)schema).getSecGroupFormTableObj().readSecGroupFormByGroupIdx( getPKey().getRequiredClusterId(),
					getPKey().getRequiredSecGroupId(),
			forceRead );
		return( retval );
	}

	public void copyPKeyToBuff() {
		if( buff != null ) {
			buff.setRequiredClusterId( getPKey().getRequiredClusterId() );
			buff.setRequiredSecGroupId( getPKey().getRequiredSecGroupId() );
		}
		if( edit != null ) {
			edit.copyPKeyToBuff();
		}
	}

	public void copyBuffToPKey() {
		getPKey().setRequiredClusterId( buff.getRequiredClusterId() );
		getPKey().setRequiredSecGroupId( buff.getRequiredSecGroupId() );
	}
}
