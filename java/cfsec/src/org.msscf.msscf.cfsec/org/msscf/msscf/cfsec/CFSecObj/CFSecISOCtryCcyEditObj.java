// Description: Java 11 edit object instance implementation for CFSec ISOCtryCcy.

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
import org.msscf.msscf.cflib.CFLib.*;
import org.msscf.msscf.cfsec.CFSec.*;

public class CFSecISOCtryCcyEditObj
	implements ICFSecISOCtryCcyEditObj
{
	protected ICFSecISOCtryCcyObj orig;
	protected CFSecISOCtryCcyBuff buff;
	protected ICFSecSecUserObj createdBy = null;
	protected ICFSecSecUserObj updatedBy = null;
	protected ICFSecISOCtryObj requiredContainerCtry;
	protected ICFSecISOCcyObj requiredParentCcy;

	public CFSecISOCtryCcyEditObj( ICFSecISOCtryCcyObj argOrig ) {
		orig = argOrig;
		getBuff();
		CFSecISOCtryCcyBuff origBuff = orig.getBuff();
		buff.set( origBuff );
		requiredContainerCtry = null;
		requiredParentCcy = null;
	}

	public ICFSecSecUserObj getCreatedBy() {
		if( createdBy == null ) {
			CFSecISOCtryCcyBuff buff = getBuff();
			createdBy = ((ICFSecSchemaObj)getSchema()).getSecUserTableObj().readSecUserByIdIdx( buff.getCreatedByUserId() );
		}
		return( createdBy );
	}

	public Calendar getCreatedAt() {
		return( getBuff().getCreatedAt() );
	}

	public ICFSecSecUserObj getUpdatedBy() {
		if( updatedBy == null ) {
			CFSecISOCtryCcyBuff buff = getBuff();
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
		return( CFSecISOCtryCcyObj.CLASS_CODE );
	}

	public String getGenDefName() {
		return( "ISOCtryCcy" );
	}

	public ICFLibAnyObj getScope() {
		ICFSecISOCtryObj scope = getRequiredContainerCtry();
		return( scope );
	}

	public ICFLibAnyObj getObjScope() {
		ICFSecISOCtryObj scope = getRequiredContainerCtry();
		return( scope );
	}

	public String getObjName() {
		String objName;
		short val = getRequiredISOCcyId();
		objName = Short.toString( val );
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

	public ICFSecISOCtryCcyObj realise() {
		// We realise this so that it's buffer will get copied to orig during realization
		ICFSecISOCtryCcyObj retobj = getSchema().getISOCtryCcyTableObj().realiseISOCtryCcy( (ICFSecISOCtryCcyObj)this );
		return( retobj );
	}

	public void forget() {
		getOrigAsISOCtryCcy().forget();
	}

	public ICFSecISOCtryCcyObj read() {
		ICFSecISOCtryCcyObj retval = getOrigAsISOCtryCcy().read();
		if( retval != orig ) {
			throw new CFLibUsageException( getClass(),
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	public ICFSecISOCtryCcyObj read( boolean forceRead ) {
		ICFSecISOCtryCcyObj retval = getOrigAsISOCtryCcy().read( forceRead );
		if( retval != orig ) {
			throw new CFLibUsageException( getClass(),
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	public ICFSecISOCtryCcyObj create() {
		copyBuffToOrig();
		ICFSecISOCtryCcyObj retobj = ((ICFSecSchemaObj)getOrigAsISOCtryCcy().getSchema()).getISOCtryCcyTableObj().createISOCtryCcy( getOrigAsISOCtryCcy() );
		if( retobj == getOrigAsISOCtryCcy() ) {
			copyOrigToBuff();
		}
		return( retobj );
	}

	public CFSecISOCtryCcyEditObj update() {
		getSchema().getISOCtryCcyTableObj().updateISOCtryCcy( (ICFSecISOCtryCcyObj)this );
		return( null );
	}

	public CFSecISOCtryCcyEditObj deleteInstance() {
		if( getIsNew() ) {
			throw new CFLibUsageException( getClass(), "delete", "Cannot delete a new instance" );
		}
		getSchema().getISOCtryCcyTableObj().deleteISOCtryCcy( getOrigAsISOCtryCcy() );
		return( null );
	}

	public ICFSecISOCtryCcyTableObj getISOCtryCcyTable() {
		return( orig.getSchema().getISOCtryCcyTableObj() );
	}

	public ICFSecISOCtryCcyEditObj getEdit() {
		return( (ICFSecISOCtryCcyEditObj)this );
	}

	public ICFSecISOCtryCcyEditObj getEditAsISOCtryCcy() {
		return( (ICFSecISOCtryCcyEditObj)this );
	}

	public ICFSecISOCtryCcyEditObj beginEdit() {
		throw new CFLibUsageException( getClass(), "beginEdit", "Cannot edit an edition" );
	}

	public void endEdit() {
		orig.endEdit();
	}

	public ICFSecISOCtryCcyObj getOrig() {
		return( orig );
	}

	public ICFSecISOCtryCcyObj getOrigAsISOCtryCcy() {
		return( (ICFSecISOCtryCcyObj)orig );
	}

	public ICFSecSchemaObj getSchema() {
		return( orig.getSchema() );
	}

	public CFSecISOCtryCcyBuff getBuff() {
		if( buff == null ) {
			buff = ((ICFSecSchema)getOrigAsISOCtryCcy().getSchema().getBackingStore()).getFactoryISOCtryCcy().newBuff();
			buff.set( orig.getBuff() );
		}
		return( buff );
	}

	public void setBuff( CFSecISOCtryCcyBuff value ) {
		if( buff != value ) {
			buff = value;
			requiredContainerCtry = null;
			requiredParentCcy = null;
		}
	}

	public CFSecISOCtryCcyBuff getISOCtryCcyBuff() {
		return( (CFSecISOCtryCcyBuff)getBuff() );
	}

	public CFSecISOCtryCcyPKey getPKey() {
		return( orig.getPKey() );
	}

	public void setPKey( CFSecISOCtryCcyPKey value ) {
		orig.setPKey( value );
		copyPKeyToBuff();
	}

	public boolean getIsNew() {
		return( orig.getIsNew() );
	}

	public void setIsNew( boolean value ) {
		orig.setIsNew( value );
	}

	public short getRequiredISOCtryId() {
		return( getPKey().getRequiredISOCtryId() );
	}

	public short getRequiredISOCcyId() {
		return( getPKey().getRequiredISOCcyId() );
	}

	public ICFSecISOCtryObj getRequiredContainerCtry() {
		return( getRequiredContainerCtry( false ) );
	}

	public ICFSecISOCtryObj getRequiredContainerCtry( boolean forceRead ) {
		if( forceRead || ( requiredContainerCtry == null ) ) {
			boolean anyMissing = false;
			if( ! anyMissing ) {
				ICFSecISOCtryObj obj = ((ICFSecSchemaObj)getOrigAsISOCtryCcy().getSchema()).getISOCtryTableObj().readISOCtryByIdIdx( getPKey().getRequiredISOCtryId() );
				requiredContainerCtry = obj;
				if( obj != null ) {
					getISOCtryCcyBuff().setRequiredISOCtryId( obj.getRequiredISOCtryId() );
					requiredContainerCtry = obj;
				}
			}
		}
		return( requiredContainerCtry );
	}

	public void setRequiredContainerCtry( ICFSecISOCtryObj value ) {
			if( buff == null ) {
				getISOCtryCcyBuff();
			}
			if( value != null ) {
				getPKey().setRequiredISOCtryId( value.getRequiredISOCtryId() );
				getISOCtryCcyBuff().setRequiredISOCtryId( value.getRequiredISOCtryId() );
			}
			requiredContainerCtry = value;
	}

	public ICFSecISOCcyObj getRequiredParentCcy() {
		return( getRequiredParentCcy( false ) );
	}

	public ICFSecISOCcyObj getRequiredParentCcy( boolean forceRead ) {
		if( forceRead || ( requiredParentCcy == null ) ) {
			boolean anyMissing = false;
			if( ! anyMissing ) {
				ICFSecISOCcyObj obj = ((ICFSecSchemaObj)getOrigAsISOCtryCcy().getSchema()).getISOCcyTableObj().readISOCcyByIdIdx( getPKey().getRequiredISOCcyId() );
				requiredParentCcy = obj;
			}
		}
		return( requiredParentCcy );
	}

	public void setRequiredParentCcy( ICFSecISOCcyObj value ) {
			if( buff == null ) {
				getISOCtryCcyBuff();
			}
			if( value != null ) {
				getPKey().setRequiredISOCcyId( value.getRequiredISOCcyId() );
				getISOCtryCcyBuff().setRequiredISOCcyId( value.getRequiredISOCcyId() );
			}
			else {
			}
			requiredParentCcy = value;
	}

	public void copyPKeyToBuff() {
		buff.setRequiredISOCtryId( getPKey().getRequiredISOCtryId() );
		buff.setRequiredISOCcyId( getPKey().getRequiredISOCcyId() );
	}

	public void copyBuffToPKey() {
		getPKey().setRequiredISOCtryId( buff.getRequiredISOCtryId() );
		getPKey().setRequiredISOCcyId( buff.getRequiredISOCcyId() );
	}

	public void copyBuffToOrig() {
		CFSecISOCtryCcyBuff origBuff = getOrigAsISOCtryCcy().getISOCtryCcyBuff();
		CFSecISOCtryCcyBuff myBuff = getISOCtryCcyBuff();
		origBuff.set( myBuff );
	}

	public void copyOrigToBuff() {
		CFSecISOCtryCcyBuff origBuff = getOrigAsISOCtryCcy().getISOCtryCcyBuff();
		CFSecISOCtryCcyBuff myBuff = getISOCtryCcyBuff();
		myBuff.set( origBuff );
	}
}
