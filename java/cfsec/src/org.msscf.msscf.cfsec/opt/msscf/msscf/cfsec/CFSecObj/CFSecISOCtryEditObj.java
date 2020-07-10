// Description: Java 11 edit object instance implementation for CFSec ISOCtry.

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

public class CFSecISOCtryEditObj
	implements ICFSecISOCtryEditObj
{
	protected ICFSecISOCtryObj orig;
	protected CFSecISOCtryBuff buff;
	protected ICFSecSecUserObj createdBy = null;
	protected ICFSecSecUserObj updatedBy = null;

	public CFSecISOCtryEditObj( ICFSecISOCtryObj argOrig ) {
		orig = argOrig;
		getBuff();
		CFSecISOCtryBuff origBuff = orig.getBuff();
		buff.set( origBuff );
	}

	public ICFSecSecUserObj getCreatedBy() {
		if( createdBy == null ) {
			CFSecISOCtryBuff buff = getBuff();
			createdBy = ((ICFSecSchemaObj)getSchema()).getSecUserTableObj().readSecUserByIdIdx( buff.getCreatedByUserId() );
		}
		return( createdBy );
	}

	public Calendar getCreatedAt() {
		return( getBuff().getCreatedAt() );
	}

	public ICFSecSecUserObj getUpdatedBy() {
		if( updatedBy == null ) {
			CFSecISOCtryBuff buff = getBuff();
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
		return( CFSecISOCtryObj.CLASS_CODE );
	}

	public String getGenDefName() {
		return( "ISOCtry" );
	}

	public ICFLibAnyObj getScope() {
		return( null );
	}

	public ICFLibAnyObj getObjScope() {
		return( null );
	}

	public String getObjName() {
		String objName;
		objName = getRequiredISOCode();
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

	public ICFSecISOCtryObj realise() {
		// We realise this so that it's buffer will get copied to orig during realization
		ICFSecISOCtryObj retobj = getSchema().getISOCtryTableObj().realiseISOCtry( (ICFSecISOCtryObj)this );
		return( retobj );
	}

	public void forget() {
		getOrigAsISOCtry().forget();
	}

	public ICFSecISOCtryObj read() {
		ICFSecISOCtryObj retval = getOrigAsISOCtry().read();
		if( retval != orig ) {
			throw new CFLibUsageException( getClass(),
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	public ICFSecISOCtryObj read( boolean forceRead ) {
		ICFSecISOCtryObj retval = getOrigAsISOCtry().read( forceRead );
		if( retval != orig ) {
			throw new CFLibUsageException( getClass(),
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	public ICFSecISOCtryObj create() {
		copyBuffToOrig();
		ICFSecISOCtryObj retobj = ((ICFSecSchemaObj)getOrigAsISOCtry().getSchema()).getISOCtryTableObj().createISOCtry( getOrigAsISOCtry() );
		if( retobj == getOrigAsISOCtry() ) {
			copyOrigToBuff();
		}
		return( retobj );
	}

	public CFSecISOCtryEditObj update() {
		getSchema().getISOCtryTableObj().updateISOCtry( (ICFSecISOCtryObj)this );
		return( null );
	}

	public CFSecISOCtryEditObj deleteInstance() {
		if( getIsNew() ) {
			throw new CFLibUsageException( getClass(), "delete", "Cannot delete a new instance" );
		}
		getSchema().getISOCtryTableObj().deleteISOCtry( getOrigAsISOCtry() );
		return( null );
	}

	public ICFSecISOCtryTableObj getISOCtryTable() {
		return( orig.getSchema().getISOCtryTableObj() );
	}

	public ICFSecISOCtryEditObj getEdit() {
		return( (ICFSecISOCtryEditObj)this );
	}

	public ICFSecISOCtryEditObj getEditAsISOCtry() {
		return( (ICFSecISOCtryEditObj)this );
	}

	public ICFSecISOCtryEditObj beginEdit() {
		throw new CFLibUsageException( getClass(), "beginEdit", "Cannot edit an edition" );
	}

	public void endEdit() {
		orig.endEdit();
	}

	public ICFSecISOCtryObj getOrig() {
		return( orig );
	}

	public ICFSecISOCtryObj getOrigAsISOCtry() {
		return( (ICFSecISOCtryObj)orig );
	}

	public ICFSecSchemaObj getSchema() {
		return( orig.getSchema() );
	}

	public CFSecISOCtryBuff getBuff() {
		if( buff == null ) {
			buff = ((ICFSecSchema)getOrigAsISOCtry().getSchema().getBackingStore()).getFactoryISOCtry().newBuff();
			buff.set( orig.getBuff() );
		}
		return( buff );
	}

	public void setBuff( CFSecISOCtryBuff value ) {
		if( buff != value ) {
			buff = value;
		}
	}

	public CFSecISOCtryBuff getISOCtryBuff() {
		return( (CFSecISOCtryBuff)getBuff() );
	}

	public CFSecISOCtryPKey getPKey() {
		return( orig.getPKey() );
	}

	public void setPKey( CFSecISOCtryPKey value ) {
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

	public String getRequiredISOCode() {
		return( getISOCtryBuff().getRequiredISOCode() );
	}

	public void setRequiredISOCode( String value ) {
		if( getISOCtryBuff().getRequiredISOCode() != value ) {
			getISOCtryBuff().setRequiredISOCode( value );
		}
	}

	public String getRequiredName() {
		return( getISOCtryBuff().getRequiredName() );
	}

	public void setRequiredName( String value ) {
		if( getISOCtryBuff().getRequiredName() != value ) {
			getISOCtryBuff().setRequiredName( value );
		}
	}

	public List<ICFSecISOCtryCcyObj> getOptionalComponentsCcy() {
		List<ICFSecISOCtryCcyObj> retval;
		retval = ((ICFSecSchemaObj)getOrigAsISOCtry().getSchema()).getISOCtryCcyTableObj().readISOCtryCcyByCtryIdx( getPKey().getRequiredISOCtryId(),
			false );
		return( retval );
	}

	public List<ICFSecISOCtryCcyObj> getOptionalComponentsCcy( boolean forceRead ) {
		List<ICFSecISOCtryCcyObj> retval;
		retval = ((ICFSecSchemaObj)getOrigAsISOCtry().getSchema()).getISOCtryCcyTableObj().readISOCtryCcyByCtryIdx( getPKey().getRequiredISOCtryId(),
			forceRead );
		return( retval );
	}

	public List<ICFSecISOCtryLangObj> getOptionalComponentsLang() {
		List<ICFSecISOCtryLangObj> retval;
		retval = ((ICFSecSchemaObj)getOrigAsISOCtry().getSchema()).getISOCtryLangTableObj().readISOCtryLangByCtryIdx( getPKey().getRequiredISOCtryId(),
			false );
		return( retval );
	}

	public List<ICFSecISOCtryLangObj> getOptionalComponentsLang( boolean forceRead ) {
		List<ICFSecISOCtryLangObj> retval;
		retval = ((ICFSecSchemaObj)getOrigAsISOCtry().getSchema()).getISOCtryLangTableObj().readISOCtryLangByCtryIdx( getPKey().getRequiredISOCtryId(),
			forceRead );
		return( retval );
	}

	public void copyPKeyToBuff() {
		buff.setRequiredISOCtryId( getPKey().getRequiredISOCtryId() );
	}

	public void copyBuffToPKey() {
		getPKey().setRequiredISOCtryId( buff.getRequiredISOCtryId() );
	}

	public void copyBuffToOrig() {
		CFSecISOCtryBuff origBuff = getOrigAsISOCtry().getISOCtryBuff();
		CFSecISOCtryBuff myBuff = getISOCtryBuff();
		origBuff.set( myBuff );
	}

	public void copyOrigToBuff() {
		CFSecISOCtryBuff origBuff = getOrigAsISOCtry().getISOCtryBuff();
		CFSecISOCtryBuff myBuff = getISOCtryBuff();
		myBuff.set( origBuff );
	}
}
