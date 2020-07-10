// Description: Java 11 edit object instance implementation for CFSec ISOCtryLang.

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

public class CFSecISOCtryLangEditObj
	implements ICFSecISOCtryLangEditObj
{
	protected ICFSecISOCtryLangObj orig;
	protected CFSecISOCtryLangBuff buff;
	protected ICFSecSecUserObj createdBy = null;
	protected ICFSecSecUserObj updatedBy = null;
	protected ICFSecISOCtryObj requiredContainerCtry;
	protected ICFSecISOLangObj requiredParentLang;

	public CFSecISOCtryLangEditObj( ICFSecISOCtryLangObj argOrig ) {
		orig = argOrig;
		getBuff();
		CFSecISOCtryLangBuff origBuff = orig.getBuff();
		buff.set( origBuff );
		requiredContainerCtry = null;
		requiredParentLang = null;
	}

	public ICFSecSecUserObj getCreatedBy() {
		if( createdBy == null ) {
			CFSecISOCtryLangBuff buff = getBuff();
			createdBy = ((ICFSecSchemaObj)getSchema()).getSecUserTableObj().readSecUserByIdIdx( buff.getCreatedByUserId() );
		}
		return( createdBy );
	}

	public Calendar getCreatedAt() {
		return( getBuff().getCreatedAt() );
	}

	public ICFSecSecUserObj getUpdatedBy() {
		if( updatedBy == null ) {
			CFSecISOCtryLangBuff buff = getBuff();
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
		return( CFSecISOCtryLangObj.CLASS_CODE );
	}

	public String getGenDefName() {
		return( "ISOCtryLang" );
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
		short val = getRequiredISOLangId();
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

	public ICFSecISOCtryLangObj realise() {
		// We realise this so that it's buffer will get copied to orig during realization
		ICFSecISOCtryLangObj retobj = getSchema().getISOCtryLangTableObj().realiseISOCtryLang( (ICFSecISOCtryLangObj)this );
		return( retobj );
	}

	public void forget() {
		getOrigAsISOCtryLang().forget();
	}

	public ICFSecISOCtryLangObj read() {
		ICFSecISOCtryLangObj retval = getOrigAsISOCtryLang().read();
		if( retval != orig ) {
			throw new CFLibUsageException( getClass(),
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	public ICFSecISOCtryLangObj read( boolean forceRead ) {
		ICFSecISOCtryLangObj retval = getOrigAsISOCtryLang().read( forceRead );
		if( retval != orig ) {
			throw new CFLibUsageException( getClass(),
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	public ICFSecISOCtryLangObj create() {
		copyBuffToOrig();
		ICFSecISOCtryLangObj retobj = ((ICFSecSchemaObj)getOrigAsISOCtryLang().getSchema()).getISOCtryLangTableObj().createISOCtryLang( getOrigAsISOCtryLang() );
		if( retobj == getOrigAsISOCtryLang() ) {
			copyOrigToBuff();
		}
		return( retobj );
	}

	public CFSecISOCtryLangEditObj update() {
		getSchema().getISOCtryLangTableObj().updateISOCtryLang( (ICFSecISOCtryLangObj)this );
		return( null );
	}

	public CFSecISOCtryLangEditObj deleteInstance() {
		if( getIsNew() ) {
			throw new CFLibUsageException( getClass(), "delete", "Cannot delete a new instance" );
		}
		getSchema().getISOCtryLangTableObj().deleteISOCtryLang( getOrigAsISOCtryLang() );
		return( null );
	}

	public ICFSecISOCtryLangTableObj getISOCtryLangTable() {
		return( orig.getSchema().getISOCtryLangTableObj() );
	}

	public ICFSecISOCtryLangEditObj getEdit() {
		return( (ICFSecISOCtryLangEditObj)this );
	}

	public ICFSecISOCtryLangEditObj getEditAsISOCtryLang() {
		return( (ICFSecISOCtryLangEditObj)this );
	}

	public ICFSecISOCtryLangEditObj beginEdit() {
		throw new CFLibUsageException( getClass(), "beginEdit", "Cannot edit an edition" );
	}

	public void endEdit() {
		orig.endEdit();
	}

	public ICFSecISOCtryLangObj getOrig() {
		return( orig );
	}

	public ICFSecISOCtryLangObj getOrigAsISOCtryLang() {
		return( (ICFSecISOCtryLangObj)orig );
	}

	public ICFSecSchemaObj getSchema() {
		return( orig.getSchema() );
	}

	public CFSecISOCtryLangBuff getBuff() {
		if( buff == null ) {
			buff = ((ICFSecSchema)getOrigAsISOCtryLang().getSchema().getBackingStore()).getFactoryISOCtryLang().newBuff();
			buff.set( orig.getBuff() );
		}
		return( buff );
	}

	public void setBuff( CFSecISOCtryLangBuff value ) {
		if( buff != value ) {
			buff = value;
			requiredContainerCtry = null;
			requiredParentLang = null;
		}
	}

	public CFSecISOCtryLangBuff getISOCtryLangBuff() {
		return( (CFSecISOCtryLangBuff)getBuff() );
	}

	public CFSecISOCtryLangPKey getPKey() {
		return( orig.getPKey() );
	}

	public void setPKey( CFSecISOCtryLangPKey value ) {
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

	public short getRequiredISOLangId() {
		return( getPKey().getRequiredISOLangId() );
	}

	public ICFSecISOCtryObj getRequiredContainerCtry() {
		return( getRequiredContainerCtry( false ) );
	}

	public ICFSecISOCtryObj getRequiredContainerCtry( boolean forceRead ) {
		if( forceRead || ( requiredContainerCtry == null ) ) {
			boolean anyMissing = false;
			if( ! anyMissing ) {
				ICFSecISOCtryObj obj = ((ICFSecSchemaObj)getOrigAsISOCtryLang().getSchema()).getISOCtryTableObj().readISOCtryByIdIdx( getPKey().getRequiredISOCtryId() );
				requiredContainerCtry = obj;
				if( obj != null ) {
					getISOCtryLangBuff().setRequiredISOCtryId( obj.getRequiredISOCtryId() );
					requiredContainerCtry = obj;
				}
			}
		}
		return( requiredContainerCtry );
	}

	public void setRequiredContainerCtry( ICFSecISOCtryObj value ) {
			if( buff == null ) {
				getISOCtryLangBuff();
			}
			if( value != null ) {
				getPKey().setRequiredISOCtryId( value.getRequiredISOCtryId() );
				getISOCtryLangBuff().setRequiredISOCtryId( value.getRequiredISOCtryId() );
			}
			requiredContainerCtry = value;
	}

	public ICFSecISOLangObj getRequiredParentLang() {
		return( getRequiredParentLang( false ) );
	}

	public ICFSecISOLangObj getRequiredParentLang( boolean forceRead ) {
		if( forceRead || ( requiredParentLang == null ) ) {
			boolean anyMissing = false;
			if( ! anyMissing ) {
				ICFSecISOLangObj obj = ((ICFSecSchemaObj)getOrigAsISOCtryLang().getSchema()).getISOLangTableObj().readISOLangByIdIdx( getPKey().getRequiredISOLangId() );
				requiredParentLang = obj;
			}
		}
		return( requiredParentLang );
	}

	public void setRequiredParentLang( ICFSecISOLangObj value ) {
			if( buff == null ) {
				getISOCtryLangBuff();
			}
			if( value != null ) {
				getPKey().setRequiredISOLangId( value.getRequiredISOLangId() );
				getISOCtryLangBuff().setRequiredISOLangId( value.getRequiredISOLangId() );
			}
			else {
			}
			requiredParentLang = value;
	}

	public void copyPKeyToBuff() {
		buff.setRequiredISOCtryId( getPKey().getRequiredISOCtryId() );
		buff.setRequiredISOLangId( getPKey().getRequiredISOLangId() );
	}

	public void copyBuffToPKey() {
		getPKey().setRequiredISOCtryId( buff.getRequiredISOCtryId() );
		getPKey().setRequiredISOLangId( buff.getRequiredISOLangId() );
	}

	public void copyBuffToOrig() {
		CFSecISOCtryLangBuff origBuff = getOrigAsISOCtryLang().getISOCtryLangBuff();
		CFSecISOCtryLangBuff myBuff = getISOCtryLangBuff();
		origBuff.set( myBuff );
	}

	public void copyOrigToBuff() {
		CFSecISOCtryLangBuff origBuff = getOrigAsISOCtryLang().getISOCtryLangBuff();
		CFSecISOCtryLangBuff myBuff = getISOCtryLangBuff();
		myBuff.set( origBuff );
	}
}
