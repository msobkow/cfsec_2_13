// Description: Java 11 edit object instance implementation for CFSec SecGroupForm.

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

public class CFSecSecGroupFormEditObj
	implements ICFSecSecGroupFormEditObj
{
	protected ICFSecSecGroupFormObj orig;
	protected CFSecSecGroupFormBuff buff;
	protected ICFSecSecUserObj createdBy = null;
	protected ICFSecSecUserObj updatedBy = null;
	protected ICFSecClusterObj requiredOwnerCluster;
	protected ICFSecSecGroupObj requiredContainerGroup;
	protected ICFSecSecAppObj requiredParentApp;
	protected ICFSecSecFormObj requiredParentForm;

	public CFSecSecGroupFormEditObj( ICFSecSecGroupFormObj argOrig ) {
		orig = argOrig;
		getBuff();
		CFSecSecGroupFormBuff origBuff = orig.getBuff();
		buff.set( origBuff );
		requiredOwnerCluster = null;
		requiredContainerGroup = null;
		requiredParentApp = null;
		requiredParentForm = null;
	}

	public ICFSecSecUserObj getCreatedBy() {
		if( createdBy == null ) {
			CFSecSecGroupFormBuff buff = getBuff();
			createdBy = ((ICFSecSchemaObj)getSchema()).getSecUserTableObj().readSecUserByIdIdx( buff.getCreatedByUserId() );
		}
		return( createdBy );
	}

	public Calendar getCreatedAt() {
		return( getBuff().getCreatedAt() );
	}

	public ICFSecSecUserObj getUpdatedBy() {
		if( updatedBy == null ) {
			CFSecSecGroupFormBuff buff = getBuff();
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
		return( CFSecSecGroupFormObj.CLASS_CODE );
	}

	public String getGenDefName() {
		return( "SecGroupForm" );
	}

	public ICFLibAnyObj getScope() {
		ICFSecSecGroupObj scope = getRequiredContainerGroup();
		return( scope );
	}

	public ICFLibAnyObj getObjScope() {
		ICFSecSecGroupObj scope = getRequiredContainerGroup();
		return( scope );
	}

	public String getObjName() {
		String objName;
		long val = getRequiredSecGroupFormId();
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

	public ICFSecSecGroupFormObj realise() {
		// We realise this so that it's buffer will get copied to orig during realization
		ICFSecSecGroupFormObj retobj = getSchema().getSecGroupFormTableObj().realiseSecGroupForm( (ICFSecSecGroupFormObj)this );
		return( retobj );
	}

	public void forget() {
		getOrigAsSecGroupForm().forget();
	}

	public ICFSecSecGroupFormObj read() {
		ICFSecSecGroupFormObj retval = getOrigAsSecGroupForm().read();
		if( retval != orig ) {
			throw new CFLibUsageException( getClass(),
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	public ICFSecSecGroupFormObj read( boolean forceRead ) {
		ICFSecSecGroupFormObj retval = getOrigAsSecGroupForm().read( forceRead );
		if( retval != orig ) {
			throw new CFLibUsageException( getClass(),
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	public ICFSecSecGroupFormObj create() {
		copyBuffToOrig();
		ICFSecSecGroupFormObj retobj = ((ICFSecSchemaObj)getOrigAsSecGroupForm().getSchema()).getSecGroupFormTableObj().createSecGroupForm( getOrigAsSecGroupForm() );
		if( retobj == getOrigAsSecGroupForm() ) {
			copyOrigToBuff();
		}
		return( retobj );
	}

	public CFSecSecGroupFormEditObj update() {
		getSchema().getSecGroupFormTableObj().updateSecGroupForm( (ICFSecSecGroupFormObj)this );
		return( null );
	}

	public CFSecSecGroupFormEditObj deleteInstance() {
		if( getIsNew() ) {
			throw new CFLibUsageException( getClass(), "delete", "Cannot delete a new instance" );
		}
		getSchema().getSecGroupFormTableObj().deleteSecGroupForm( getOrigAsSecGroupForm() );
		return( null );
	}

	public ICFSecSecGroupFormTableObj getSecGroupFormTable() {
		return( orig.getSchema().getSecGroupFormTableObj() );
	}

	public ICFSecSecGroupFormEditObj getEdit() {
		return( (ICFSecSecGroupFormEditObj)this );
	}

	public ICFSecSecGroupFormEditObj getEditAsSecGroupForm() {
		return( (ICFSecSecGroupFormEditObj)this );
	}

	public ICFSecSecGroupFormEditObj beginEdit() {
		throw new CFLibUsageException( getClass(), "beginEdit", "Cannot edit an edition" );
	}

	public void endEdit() {
		orig.endEdit();
	}

	public ICFSecSecGroupFormObj getOrig() {
		return( orig );
	}

	public ICFSecSecGroupFormObj getOrigAsSecGroupForm() {
		return( (ICFSecSecGroupFormObj)orig );
	}

	public ICFSecSchemaObj getSchema() {
		return( orig.getSchema() );
	}

	public CFSecSecGroupFormBuff getBuff() {
		if( buff == null ) {
			buff = ((ICFSecSchema)getOrigAsSecGroupForm().getSchema().getBackingStore()).getFactorySecGroupForm().newBuff();
			buff.set( orig.getBuff() );
		}
		return( buff );
	}

	public void setBuff( CFSecSecGroupFormBuff value ) {
		if( buff != value ) {
			buff = value;
			requiredOwnerCluster = null;
			requiredContainerGroup = null;
			requiredParentApp = null;
			requiredParentForm = null;
		}
	}

	public CFSecSecGroupFormBuff getSecGroupFormBuff() {
		return( (CFSecSecGroupFormBuff)getBuff() );
	}

	public CFSecSecGroupFormPKey getPKey() {
		return( orig.getPKey() );
	}

	public void setPKey( CFSecSecGroupFormPKey value ) {
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

	public long getRequiredSecGroupFormId() {
		return( getPKey().getRequiredSecGroupFormId() );
	}

	public int getRequiredSecGroupId() {
		return( getSecGroupFormBuff().getRequiredSecGroupId() );
	}

	public int getRequiredSecAppId() {
		return( getSecGroupFormBuff().getRequiredSecAppId() );
	}

	public int getRequiredSecFormId() {
		return( getSecGroupFormBuff().getRequiredSecFormId() );
	}

	public ICFSecClusterObj getRequiredOwnerCluster() {
		return( getRequiredOwnerCluster( false ) );
	}

	public ICFSecClusterObj getRequiredOwnerCluster( boolean forceRead ) {
		if( forceRead || ( requiredOwnerCluster == null ) ) {
			boolean anyMissing = false;
			if( ! anyMissing ) {
				ICFSecClusterObj obj = ((ICFSecSchemaObj)getOrigAsSecGroupForm().getSchema()).getClusterTableObj().readClusterByIdIdx( getPKey().getRequiredClusterId() );
				requiredOwnerCluster = obj;
			}
		}
		return( requiredOwnerCluster );
	}

	public void setRequiredOwnerCluster( ICFSecClusterObj value ) {
			if( buff == null ) {
				getSecGroupFormBuff();
			}
			if( value != null ) {
				getPKey().setRequiredClusterId( value.getRequiredId() );
				getSecGroupFormBuff().setRequiredClusterId( value.getRequiredId() );
			}
			requiredOwnerCluster = value;
	}

	public ICFSecSecGroupObj getRequiredContainerGroup() {
		return( getRequiredContainerGroup( false ) );
	}

	public ICFSecSecGroupObj getRequiredContainerGroup( boolean forceRead ) {
		if( forceRead || ( requiredContainerGroup == null ) ) {
			boolean anyMissing = false;
			if( ! anyMissing ) {
				ICFSecSecGroupObj obj = ((ICFSecSchemaObj)getOrigAsSecGroupForm().getSchema()).getSecGroupTableObj().readSecGroupByIdIdx( getPKey().getRequiredClusterId(),
					getSecGroupFormBuff().getRequiredSecGroupId() );
				requiredContainerGroup = obj;
				if( obj != null ) {
					getSecGroupFormBuff().setRequiredClusterId( obj.getRequiredClusterId() );
					getSecGroupFormBuff().setRequiredSecGroupId( obj.getRequiredSecGroupId() );
					requiredContainerGroup = obj;
				}
			}
		}
		return( requiredContainerGroup );
	}

	public void setRequiredContainerGroup( ICFSecSecGroupObj value ) {
			if( buff == null ) {
				getSecGroupFormBuff();
			}
			if( value != null ) {
				getPKey().setRequiredClusterId( value.getRequiredClusterId() );
				getSecGroupFormBuff().setRequiredClusterId( value.getRequiredClusterId() );
				getSecGroupFormBuff().setRequiredSecGroupId( value.getRequiredSecGroupId() );
			}
			requiredContainerGroup = value;
	}

	public ICFSecSecAppObj getRequiredParentApp() {
		return( getRequiredParentApp( false ) );
	}

	public ICFSecSecAppObj getRequiredParentApp( boolean forceRead ) {
		if( forceRead || ( requiredParentApp == null ) ) {
			boolean anyMissing = false;
			if( ! anyMissing ) {
				ICFSecSecAppObj obj = ((ICFSecSchemaObj)getOrigAsSecGroupForm().getSchema()).getSecAppTableObj().readSecAppByIdIdx( getPKey().getRequiredClusterId(),
					getSecGroupFormBuff().getRequiredSecAppId() );
				requiredParentApp = obj;
			}
		}
		return( requiredParentApp );
	}

	public void setRequiredParentApp( ICFSecSecAppObj value ) {
			if( buff == null ) {
				getSecGroupFormBuff();
			}
			if( value != null ) {
				getPKey().setRequiredClusterId( value.getRequiredClusterId() );
				getSecGroupFormBuff().setRequiredClusterId( value.getRequiredClusterId() );
				getSecGroupFormBuff().setRequiredSecAppId( value.getRequiredSecAppId() );
			}
			else {
			}
			requiredParentApp = value;
	}

	public ICFSecSecFormObj getRequiredParentForm() {
		return( getRequiredParentForm( false ) );
	}

	public ICFSecSecFormObj getRequiredParentForm( boolean forceRead ) {
		if( forceRead || ( requiredParentForm == null ) ) {
			boolean anyMissing = false;
			if( ! anyMissing ) {
				ICFSecSecFormObj obj = ((ICFSecSchemaObj)getOrigAsSecGroupForm().getSchema()).getSecFormTableObj().readSecFormByIdIdx( getPKey().getRequiredClusterId(),
					getSecGroupFormBuff().getRequiredSecFormId() );
				requiredParentForm = obj;
			}
		}
		return( requiredParentForm );
	}

	public void setRequiredParentForm( ICFSecSecFormObj value ) {
			if( buff == null ) {
				getSecGroupFormBuff();
			}
			if( value != null ) {
				getPKey().setRequiredClusterId( value.getRequiredClusterId() );
				getSecGroupFormBuff().setRequiredClusterId( value.getRequiredClusterId() );
				getSecGroupFormBuff().setRequiredSecFormId( value.getRequiredSecFormId() );
			}
			else {
			}
			requiredParentForm = value;
	}

	public void copyPKeyToBuff() {
		buff.setRequiredClusterId( getPKey().getRequiredClusterId() );
		buff.setRequiredSecGroupFormId( getPKey().getRequiredSecGroupFormId() );
	}

	public void copyBuffToPKey() {
		getPKey().setRequiredClusterId( buff.getRequiredClusterId() );
		getPKey().setRequiredSecGroupFormId( buff.getRequiredSecGroupFormId() );
	}

	public void copyBuffToOrig() {
		CFSecSecGroupFormBuff origBuff = getOrigAsSecGroupForm().getSecGroupFormBuff();
		CFSecSecGroupFormBuff myBuff = getSecGroupFormBuff();
		origBuff.set( myBuff );
	}

	public void copyOrigToBuff() {
		CFSecSecGroupFormBuff origBuff = getOrigAsSecGroupForm().getSecGroupFormBuff();
		CFSecSecGroupFormBuff myBuff = getSecGroupFormBuff();
		myBuff.set( origBuff );
	}
}
