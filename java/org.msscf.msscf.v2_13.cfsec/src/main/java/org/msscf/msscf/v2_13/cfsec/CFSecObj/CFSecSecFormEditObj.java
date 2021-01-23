// Description: Java 11 edit object instance implementation for CFSec SecForm.

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

public class CFSecSecFormEditObj
	implements ICFSecSecFormEditObj
{
	protected ICFSecSecFormObj orig;
	protected CFSecSecFormBuff buff;
	protected ICFSecSecUserObj createdBy = null;
	protected ICFSecSecUserObj updatedBy = null;
	protected ICFSecClusterObj requiredOwnerCluster;
	protected ICFSecSecAppObj requiredContainerApplication;

	public CFSecSecFormEditObj( ICFSecSecFormObj argOrig ) {
		orig = argOrig;
		getBuff();
		CFSecSecFormBuff origBuff = orig.getBuff();
		buff.set( origBuff );
		requiredOwnerCluster = null;
		requiredContainerApplication = null;
	}

	public ICFSecSecUserObj getCreatedBy() {
		if( createdBy == null ) {
			CFSecSecFormBuff buff = getBuff();
			createdBy = ((ICFSecSchemaObj)getSchema()).getSecUserTableObj().readSecUserByIdIdx( buff.getCreatedByUserId() );
		}
		return( createdBy );
	}

	public Calendar getCreatedAt() {
		return( getBuff().getCreatedAt() );
	}

	public ICFSecSecUserObj getUpdatedBy() {
		if( updatedBy == null ) {
			CFSecSecFormBuff buff = getBuff();
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
		return( CFSecSecFormObj.CLASS_CODE );
	}

	public String getGenDefName() {
		return( "SecForm" );
	}

	public ICFLibAnyObj getScope() {
		ICFSecSecAppObj scope = getRequiredContainerApplication();
		return( scope );
	}

	public ICFLibAnyObj getObjScope() {
		ICFSecSecAppObj scope = getRequiredContainerApplication();
		return( scope );
	}

	public String getObjName() {
		String objName;
		objName = getRequiredJEEServletMapName();
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

	public ICFSecSecFormObj realise() {
		// We realise this so that it's buffer will get copied to orig during realization
		ICFSecSecFormObj retobj = getSchema().getSecFormTableObj().realiseSecForm( (ICFSecSecFormObj)this );
		return( retobj );
	}

	public void forget() {
		getOrigAsSecForm().forget();
	}

	public ICFSecSecFormObj read() {
		ICFSecSecFormObj retval = getOrigAsSecForm().read();
		if( retval != orig ) {
			throw new CFLibUsageException( getClass(),
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	public ICFSecSecFormObj read( boolean forceRead ) {
		ICFSecSecFormObj retval = getOrigAsSecForm().read( forceRead );
		if( retval != orig ) {
			throw new CFLibUsageException( getClass(),
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	public ICFSecSecFormObj create() {
		copyBuffToOrig();
		ICFSecSecFormObj retobj = ((ICFSecSchemaObj)getOrigAsSecForm().getSchema()).getSecFormTableObj().createSecForm( getOrigAsSecForm() );
		if( retobj == getOrigAsSecForm() ) {
			copyOrigToBuff();
		}
		return( retobj );
	}

	public CFSecSecFormEditObj update() {
		getSchema().getSecFormTableObj().updateSecForm( (ICFSecSecFormObj)this );
		return( null );
	}

	public CFSecSecFormEditObj deleteInstance() {
		if( getIsNew() ) {
			throw new CFLibUsageException( getClass(), "delete", "Cannot delete a new instance" );
		}
		getSchema().getSecFormTableObj().deleteSecForm( getOrigAsSecForm() );
		return( null );
	}

	public ICFSecSecFormTableObj getSecFormTable() {
		return( orig.getSchema().getSecFormTableObj() );
	}

	public ICFSecSecFormEditObj getEdit() {
		return( (ICFSecSecFormEditObj)this );
	}

	public ICFSecSecFormEditObj getEditAsSecForm() {
		return( (ICFSecSecFormEditObj)this );
	}

	public ICFSecSecFormEditObj beginEdit() {
		throw new CFLibUsageException( getClass(), "beginEdit", "Cannot edit an edition" );
	}

	public void endEdit() {
		orig.endEdit();
	}

	public ICFSecSecFormObj getOrig() {
		return( orig );
	}

	public ICFSecSecFormObj getOrigAsSecForm() {
		return( (ICFSecSecFormObj)orig );
	}

	public ICFSecSchemaObj getSchema() {
		return( orig.getSchema() );
	}

	public CFSecSecFormBuff getBuff() {
		if( buff == null ) {
			buff = ((ICFSecSchema)getOrigAsSecForm().getSchema().getBackingStore()).getFactorySecForm().newBuff();
			buff.set( orig.getBuff() );
		}
		return( buff );
	}

	public void setBuff( CFSecSecFormBuff value ) {
		if( buff != value ) {
			buff = value;
			requiredOwnerCluster = null;
			requiredContainerApplication = null;
		}
	}

	public CFSecSecFormBuff getSecFormBuff() {
		return( (CFSecSecFormBuff)getBuff() );
	}

	public CFSecSecFormPKey getPKey() {
		return( orig.getPKey() );
	}

	public void setPKey( CFSecSecFormPKey value ) {
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

	public int getRequiredSecFormId() {
		return( getPKey().getRequiredSecFormId() );
	}

	public int getRequiredSecAppId() {
		return( getSecFormBuff().getRequiredSecAppId() );
	}

	public String getRequiredJEEServletMapName() {
		return( getSecFormBuff().getRequiredJEEServletMapName() );
	}

	public void setRequiredJEEServletMapName( String value ) {
		if( getSecFormBuff().getRequiredJEEServletMapName() != value ) {
			getSecFormBuff().setRequiredJEEServletMapName( value );
		}
	}

	public ICFSecClusterObj getRequiredOwnerCluster() {
		return( getRequiredOwnerCluster( false ) );
	}

	public ICFSecClusterObj getRequiredOwnerCluster( boolean forceRead ) {
		if( forceRead || ( requiredOwnerCluster == null ) ) {
			boolean anyMissing = false;
			if( ! anyMissing ) {
				ICFSecClusterObj obj = ((ICFSecSchemaObj)getOrigAsSecForm().getSchema()).getClusterTableObj().readClusterByIdIdx( getPKey().getRequiredClusterId() );
				requiredOwnerCluster = obj;
			}
		}
		return( requiredOwnerCluster );
	}

	public void setRequiredOwnerCluster( ICFSecClusterObj value ) {
			if( buff == null ) {
				getSecFormBuff();
			}
			if( value != null ) {
				getPKey().setRequiredClusterId( value.getRequiredId() );
				getSecFormBuff().setRequiredClusterId( value.getRequiredId() );
			}
			requiredOwnerCluster = value;
	}

	public ICFSecSecAppObj getRequiredContainerApplication() {
		return( getRequiredContainerApplication( false ) );
	}

	public ICFSecSecAppObj getRequiredContainerApplication( boolean forceRead ) {
		if( forceRead || ( requiredContainerApplication == null ) ) {
			boolean anyMissing = false;
			if( ! anyMissing ) {
				ICFSecSecAppObj obj = ((ICFSecSchemaObj)getOrigAsSecForm().getSchema()).getSecAppTableObj().readSecAppByIdIdx( getPKey().getRequiredClusterId(),
					getSecFormBuff().getRequiredSecAppId() );
				requiredContainerApplication = obj;
				if( obj != null ) {
					getSecFormBuff().setRequiredClusterId( obj.getRequiredClusterId() );
					getSecFormBuff().setRequiredSecAppId( obj.getRequiredSecAppId() );
					requiredContainerApplication = obj;
				}
			}
		}
		return( requiredContainerApplication );
	}

	public void setRequiredContainerApplication( ICFSecSecAppObj value ) {
			if( buff == null ) {
				getSecFormBuff();
			}
			if( value != null ) {
				getPKey().setRequiredClusterId( value.getRequiredClusterId() );
				getSecFormBuff().setRequiredClusterId( value.getRequiredClusterId() );
				getSecFormBuff().setRequiredSecAppId( value.getRequiredSecAppId() );
			}
			requiredContainerApplication = value;
	}

	public void copyPKeyToBuff() {
		buff.setRequiredClusterId( getPKey().getRequiredClusterId() );
		buff.setRequiredSecFormId( getPKey().getRequiredSecFormId() );
	}

	public void copyBuffToPKey() {
		getPKey().setRequiredClusterId( buff.getRequiredClusterId() );
		getPKey().setRequiredSecFormId( buff.getRequiredSecFormId() );
	}

	public void copyBuffToOrig() {
		CFSecSecFormBuff origBuff = getOrigAsSecForm().getSecFormBuff();
		CFSecSecFormBuff myBuff = getSecFormBuff();
		origBuff.set( myBuff );
	}

	public void copyOrigToBuff() {
		CFSecSecFormBuff origBuff = getOrigAsSecForm().getSecFormBuff();
		CFSecSecFormBuff myBuff = getSecFormBuff();
		myBuff.set( origBuff );
	}
}
