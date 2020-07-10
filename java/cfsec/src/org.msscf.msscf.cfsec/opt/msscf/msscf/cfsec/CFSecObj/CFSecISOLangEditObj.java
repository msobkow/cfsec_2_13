// Description: Java 11 edit object instance implementation for CFSec ISOLang.

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

public class CFSecISOLangEditObj
	implements ICFSecISOLangEditObj
{
	protected ICFSecISOLangObj orig;
	protected CFSecISOLangBuff buff;
	protected ICFSecSecUserObj createdBy = null;
	protected ICFSecSecUserObj updatedBy = null;

	public CFSecISOLangEditObj( ICFSecISOLangObj argOrig ) {
		orig = argOrig;
		getBuff();
		CFSecISOLangBuff origBuff = orig.getBuff();
		buff.set( origBuff );
	}

	public ICFSecSecUserObj getCreatedBy() {
		if( createdBy == null ) {
			CFSecISOLangBuff buff = getBuff();
			createdBy = ((ICFSecSchemaObj)getSchema()).getSecUserTableObj().readSecUserByIdIdx( buff.getCreatedByUserId() );
		}
		return( createdBy );
	}

	public Calendar getCreatedAt() {
		return( getBuff().getCreatedAt() );
	}

	public ICFSecSecUserObj getUpdatedBy() {
		if( updatedBy == null ) {
			CFSecISOLangBuff buff = getBuff();
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
		return( CFSecISOLangObj.CLASS_CODE );
	}

	public String getGenDefName() {
		return( "ISOLang" );
	}

	public ICFLibAnyObj getScope() {
		return( null );
	}

	public ICFLibAnyObj getObjScope() {
		return( null );
	}

	public String getObjName() {
		String objName;
		objName = getRequiredISO6392Code();
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

	public ICFSecISOLangObj realise() {
		// We realise this so that it's buffer will get copied to orig during realization
		ICFSecISOLangObj retobj = getSchema().getISOLangTableObj().realiseISOLang( (ICFSecISOLangObj)this );
		return( retobj );
	}

	public void forget() {
		getOrigAsISOLang().forget();
	}

	public ICFSecISOLangObj read() {
		ICFSecISOLangObj retval = getOrigAsISOLang().read();
		if( retval != orig ) {
			throw new CFLibUsageException( getClass(),
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	public ICFSecISOLangObj read( boolean forceRead ) {
		ICFSecISOLangObj retval = getOrigAsISOLang().read( forceRead );
		if( retval != orig ) {
			throw new CFLibUsageException( getClass(),
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	public ICFSecISOLangObj create() {
		copyBuffToOrig();
		ICFSecISOLangObj retobj = ((ICFSecSchemaObj)getOrigAsISOLang().getSchema()).getISOLangTableObj().createISOLang( getOrigAsISOLang() );
		if( retobj == getOrigAsISOLang() ) {
			copyOrigToBuff();
		}
		return( retobj );
	}

	public CFSecISOLangEditObj update() {
		getSchema().getISOLangTableObj().updateISOLang( (ICFSecISOLangObj)this );
		return( null );
	}

	public CFSecISOLangEditObj deleteInstance() {
		if( getIsNew() ) {
			throw new CFLibUsageException( getClass(), "delete", "Cannot delete a new instance" );
		}
		getSchema().getISOLangTableObj().deleteISOLang( getOrigAsISOLang() );
		return( null );
	}

	public ICFSecISOLangTableObj getISOLangTable() {
		return( orig.getSchema().getISOLangTableObj() );
	}

	public ICFSecISOLangEditObj getEdit() {
		return( (ICFSecISOLangEditObj)this );
	}

	public ICFSecISOLangEditObj getEditAsISOLang() {
		return( (ICFSecISOLangEditObj)this );
	}

	public ICFSecISOLangEditObj beginEdit() {
		throw new CFLibUsageException( getClass(), "beginEdit", "Cannot edit an edition" );
	}

	public void endEdit() {
		orig.endEdit();
	}

	public ICFSecISOLangObj getOrig() {
		return( orig );
	}

	public ICFSecISOLangObj getOrigAsISOLang() {
		return( (ICFSecISOLangObj)orig );
	}

	public ICFSecSchemaObj getSchema() {
		return( orig.getSchema() );
	}

	public CFSecISOLangBuff getBuff() {
		if( buff == null ) {
			buff = ((ICFSecSchema)getOrigAsISOLang().getSchema().getBackingStore()).getFactoryISOLang().newBuff();
			buff.set( orig.getBuff() );
		}
		return( buff );
	}

	public void setBuff( CFSecISOLangBuff value ) {
		if( buff != value ) {
			buff = value;
		}
	}

	public CFSecISOLangBuff getISOLangBuff() {
		return( (CFSecISOLangBuff)getBuff() );
	}

	public CFSecISOLangPKey getPKey() {
		return( orig.getPKey() );
	}

	public void setPKey( CFSecISOLangPKey value ) {
		orig.setPKey( value );
		copyPKeyToBuff();
	}

	public boolean getIsNew() {
		return( orig.getIsNew() );
	}

	public void setIsNew( boolean value ) {
		orig.setIsNew( value );
	}

	public short getRequiredISOLangId() {
		return( getPKey().getRequiredISOLangId() );
	}

	public String getRequiredISO6392Code() {
		return( getISOLangBuff().getRequiredISO6392Code() );
	}

	public void setRequiredISO6392Code( String value ) {
		if( getISOLangBuff().getRequiredISO6392Code() != value ) {
			getISOLangBuff().setRequiredISO6392Code( value );
		}
	}

	public String getOptionalISO6391Code() {
		return( getISOLangBuff().getOptionalISO6391Code() );
	}

	public void setOptionalISO6391Code( String value ) {
		if( getISOLangBuff().getOptionalISO6391Code() != value ) {
			getISOLangBuff().setOptionalISO6391Code( value );
		}
	}

	public String getRequiredEnglishName() {
		return( getISOLangBuff().getRequiredEnglishName() );
	}

	public void setRequiredEnglishName( String value ) {
		if( getISOLangBuff().getRequiredEnglishName() != value ) {
			getISOLangBuff().setRequiredEnglishName( value );
		}
	}

	public List<ICFSecISOCtryLangObj> getOptionalChildrenCtry() {
		List<ICFSecISOCtryLangObj> retval;
		retval = ((ICFSecSchemaObj)getOrigAsISOLang().getSchema()).getISOCtryLangTableObj().readISOCtryLangByLangIdx( getPKey().getRequiredISOLangId(),
			false );
		return( retval );
	}

	public List<ICFSecISOCtryLangObj> getOptionalChildrenCtry( boolean forceRead ) {
		List<ICFSecISOCtryLangObj> retval;
		retval = ((ICFSecSchemaObj)getOrigAsISOLang().getSchema()).getISOCtryLangTableObj().readISOCtryLangByLangIdx( getPKey().getRequiredISOLangId(),
			forceRead );
		return( retval );
	}

	public void copyPKeyToBuff() {
		buff.setRequiredISOLangId( getPKey().getRequiredISOLangId() );
	}

	public void copyBuffToPKey() {
		getPKey().setRequiredISOLangId( buff.getRequiredISOLangId() );
	}

	public void copyBuffToOrig() {
		CFSecISOLangBuff origBuff = getOrigAsISOLang().getISOLangBuff();
		CFSecISOLangBuff myBuff = getISOLangBuff();
		origBuff.set( myBuff );
	}

	public void copyOrigToBuff() {
		CFSecISOLangBuff origBuff = getOrigAsISOLang().getISOLangBuff();
		CFSecISOLangBuff myBuff = getISOLangBuff();
		myBuff.set( origBuff );
	}
}
