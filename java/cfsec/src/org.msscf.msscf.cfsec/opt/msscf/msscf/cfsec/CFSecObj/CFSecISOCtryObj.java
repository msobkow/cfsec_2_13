// Description: Java 11 base object instance implementation for CFSec ISOCtry.

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

public class CFSecISOCtryObj
	implements ICFSecISOCtryObj
{
	public final static String CLASS_CODE = "a004";
	protected ICFSecSecUserObj createdBy = null;
	protected ICFSecSecUserObj updatedBy = null;
	protected boolean isNew;
	protected ICFSecISOCtryEditObj edit;
	protected ICFSecSchemaObj schema;
	protected CFSecISOCtryPKey pKey;
	protected CFSecISOCtryBuff buff;

	public CFSecISOCtryObj() {
		isNew = true;
	}

	public CFSecISOCtryObj( ICFSecSchemaObj argSchema ) {
		schema = argSchema;
		isNew = true;
		edit = null;
	}

	public String getClassCode() {
		return( CLASS_CODE );
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
		ICFSecISOCtryObj retobj = ((ICFSecSchemaObj)schema).getISOCtryTableObj().realiseISOCtry(
			(ICFSecISOCtryObj)this );
		return( (ICFSecISOCtryObj)retobj );
	}

	public void forget() {
		((ICFSecSchemaObj)schema).getISOCtryTableObj().reallyDeepDisposeISOCtry( (ICFSecISOCtryObj)this );
	}

	public ICFSecISOCtryObj read() {
		ICFSecISOCtryObj retobj = ((ICFSecSchemaObj)schema).getISOCtryTableObj().readISOCtryByIdIdx( getPKey().getRequiredISOCtryId(), false );
		return( (ICFSecISOCtryObj)retobj );
	}

	public ICFSecISOCtryObj read( boolean forceRead ) {
		ICFSecISOCtryObj retobj = ((ICFSecSchemaObj)schema).getISOCtryTableObj().readISOCtryByIdIdx( getPKey().getRequiredISOCtryId(), forceRead );
		return( (ICFSecISOCtryObj)retobj );
	}

	public ICFSecISOCtryTableObj getISOCtryTable() {
		return( ((ICFSecSchemaObj)schema).getISOCtryTableObj() );
	}

	public ICFSecSchemaObj getSchema() {
		return( schema );
	}

	public void setSchema( ICFSecSchemaObj value ) {
		schema = value;
	}

	public CFSecISOCtryBuff getBuff() {
		if( buff == null ) {
			if( isNew ) {
				buff = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOCtry().newBuff();
			}
			else {
				// Read the data buff via the backing store
				buff = ((ICFSecSchema)schema.getBackingStore()).getTableISOCtry().readDerivedByIdIdx( ((ICFSecSchemaObj)schema).getAuthorization(),
						getPKey().getRequiredISOCtryId() );
				if( buff != null ) {
					copyBuffToPKey();
				}
			}
		}
		return( buff );
	}

	public void setBuff( CFSecISOCtryBuff value ) {
		if( ! ( ( value == null ) || ( value instanceof CFSecISOCtryBuff ) ) ) {
			throw new CFLibUnsupportedClassException( getClass(),
				"setBuff",
				"value",
				value,
				"CFSecISOCtryBuff" );
		}
		buff = value;
		copyBuffToPKey();
	}

	public CFSecISOCtryBuff getISOCtryBuff() {
		return( (CFSecISOCtryBuff)getBuff() );
	}

	public CFSecISOCtryPKey getPKey() {
		if( pKey == null ) {
			pKey = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOCtry().newPKey();
		}
		return( pKey );
	}

	public void setPKey( CFSecISOCtryPKey value ) {
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

	public ICFSecISOCtryEditObj beginEdit() {
		if( edit != null ) {
			throw new CFLibUsageException( getClass(), "beginEdit", "An edit is already open" );
		}
		ICFSecISOCtryObj lockobj;
		if( getIsNew() ) {
			lockobj = (ICFSecISOCtryObj)this;
		}
		else {
			lockobj = ((ICFSecSchemaObj)schema).getISOCtryTableObj().lockISOCtry( getPKey() );
		}
		edit = ((ICFSecSchemaObj)schema).getISOCtryTableObj().newEditInstance( lockobj );
		return( (ICFSecISOCtryEditObj)edit );
	}

	public void endEdit() {
		edit = null;
	}

	public ICFSecISOCtryEditObj getEdit() {
		return( edit );
	}

	public ICFSecISOCtryEditObj getEditAsISOCtry() {
		return( (ICFSecISOCtryEditObj)edit );
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

	public short getRequiredISOCtryId() {
		return( getPKey().getRequiredISOCtryId() );
	}

	public String getRequiredISOCode() {
		return( getISOCtryBuff().getRequiredISOCode() );
	}

	public String getRequiredName() {
		return( getISOCtryBuff().getRequiredName() );
	}

	public List<ICFSecISOCtryCcyObj> getOptionalComponentsCcy() {
		List<ICFSecISOCtryCcyObj> retval;
		retval = ((ICFSecSchemaObj)schema).getISOCtryCcyTableObj().readISOCtryCcyByCtryIdx( getPKey().getRequiredISOCtryId(),
			false );
		return( retval );
	}

	public List<ICFSecISOCtryCcyObj> getOptionalComponentsCcy( boolean forceRead ) {
		List<ICFSecISOCtryCcyObj> retval;
		retval = ((ICFSecSchemaObj)schema).getISOCtryCcyTableObj().readISOCtryCcyByCtryIdx( getPKey().getRequiredISOCtryId(),
			forceRead );
		return( retval );
	}

	public List<ICFSecISOCtryLangObj> getOptionalComponentsLang() {
		List<ICFSecISOCtryLangObj> retval;
		retval = ((ICFSecSchemaObj)schema).getISOCtryLangTableObj().readISOCtryLangByCtryIdx( getPKey().getRequiredISOCtryId(),
			false );
		return( retval );
	}

	public List<ICFSecISOCtryLangObj> getOptionalComponentsLang( boolean forceRead ) {
		List<ICFSecISOCtryLangObj> retval;
		retval = ((ICFSecSchemaObj)schema).getISOCtryLangTableObj().readISOCtryLangByCtryIdx( getPKey().getRequiredISOCtryId(),
			forceRead );
		return( retval );
	}

	public void copyPKeyToBuff() {
		if( buff != null ) {
			buff.setRequiredISOCtryId( getPKey().getRequiredISOCtryId() );
		}
		if( edit != null ) {
			edit.copyPKeyToBuff();
		}
	}

	public void copyBuffToPKey() {
		getPKey().setRequiredISOCtryId( buff.getRequiredISOCtryId() );
	}
}
