// Description: Java 11 edit object instance implementation for CFSec ISOTZone.

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

public class CFSecISOTZoneEditObj
	implements ICFSecISOTZoneEditObj
{
	protected ICFSecISOTZoneObj orig;
	protected CFSecISOTZoneBuff buff;
	protected ICFSecSecUserObj createdBy = null;
	protected ICFSecSecUserObj updatedBy = null;

	public CFSecISOTZoneEditObj( ICFSecISOTZoneObj argOrig ) {
		orig = argOrig;
		getBuff();
		CFSecISOTZoneBuff origBuff = orig.getBuff();
		buff.set( origBuff );
	}

	public ICFSecSecUserObj getCreatedBy() {
		if( createdBy == null ) {
			CFSecISOTZoneBuff buff = getBuff();
			createdBy = ((ICFSecSchemaObj)getSchema()).getSecUserTableObj().readSecUserByIdIdx( buff.getCreatedByUserId() );
		}
		return( createdBy );
	}

	public Calendar getCreatedAt() {
		return( getBuff().getCreatedAt() );
	}

	public ICFSecSecUserObj getUpdatedBy() {
		if( updatedBy == null ) {
			CFSecISOTZoneBuff buff = getBuff();
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
		return( CFSecISOTZoneObj.CLASS_CODE );
	}

	public String getGenDefName() {
		return( "ISOTZone" );
	}

	public ICFLibAnyObj getScope() {
		return( null );
	}

	public ICFLibAnyObj getObjScope() {
		return( null );
	}

	public String getObjName() {
		String objName;
		objName = getRequiredTZName();
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

	public ICFSecISOTZoneObj realise() {
		// We realise this so that it's buffer will get copied to orig during realization
		ICFSecISOTZoneObj retobj = getSchema().getISOTZoneTableObj().realiseISOTZone( (ICFSecISOTZoneObj)this );
		return( retobj );
	}

	public void forget() {
		getOrigAsISOTZone().forget();
	}

	public ICFSecISOTZoneObj read() {
		ICFSecISOTZoneObj retval = getOrigAsISOTZone().read();
		if( retval != orig ) {
			throw new CFLibUsageException( getClass(),
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	public ICFSecISOTZoneObj read( boolean forceRead ) {
		ICFSecISOTZoneObj retval = getOrigAsISOTZone().read( forceRead );
		if( retval != orig ) {
			throw new CFLibUsageException( getClass(),
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	public ICFSecISOTZoneObj create() {
		copyBuffToOrig();
		ICFSecISOTZoneObj retobj = ((ICFSecSchemaObj)getOrigAsISOTZone().getSchema()).getISOTZoneTableObj().createISOTZone( getOrigAsISOTZone() );
		if( retobj == getOrigAsISOTZone() ) {
			copyOrigToBuff();
		}
		return( retobj );
	}

	public CFSecISOTZoneEditObj update() {
		getSchema().getISOTZoneTableObj().updateISOTZone( (ICFSecISOTZoneObj)this );
		return( null );
	}

	public CFSecISOTZoneEditObj deleteInstance() {
		if( getIsNew() ) {
			throw new CFLibUsageException( getClass(), "delete", "Cannot delete a new instance" );
		}
		getSchema().getISOTZoneTableObj().deleteISOTZone( getOrigAsISOTZone() );
		return( null );
	}

	public ICFSecISOTZoneTableObj getISOTZoneTable() {
		return( orig.getSchema().getISOTZoneTableObj() );
	}

	public ICFSecISOTZoneEditObj getEdit() {
		return( (ICFSecISOTZoneEditObj)this );
	}

	public ICFSecISOTZoneEditObj getEditAsISOTZone() {
		return( (ICFSecISOTZoneEditObj)this );
	}

	public ICFSecISOTZoneEditObj beginEdit() {
		throw new CFLibUsageException( getClass(), "beginEdit", "Cannot edit an edition" );
	}

	public void endEdit() {
		orig.endEdit();
	}

	public ICFSecISOTZoneObj getOrig() {
		return( orig );
	}

	public ICFSecISOTZoneObj getOrigAsISOTZone() {
		return( (ICFSecISOTZoneObj)orig );
	}

	public ICFSecSchemaObj getSchema() {
		return( orig.getSchema() );
	}

	public CFSecISOTZoneBuff getBuff() {
		if( buff == null ) {
			buff = ((ICFSecSchema)getOrigAsISOTZone().getSchema().getBackingStore()).getFactoryISOTZone().newBuff();
			buff.set( orig.getBuff() );
		}
		return( buff );
	}

	public void setBuff( CFSecISOTZoneBuff value ) {
		if( buff != value ) {
			buff = value;
		}
	}

	public CFSecISOTZoneBuff getISOTZoneBuff() {
		return( (CFSecISOTZoneBuff)getBuff() );
	}

	public CFSecISOTZonePKey getPKey() {
		return( orig.getPKey() );
	}

	public void setPKey( CFSecISOTZonePKey value ) {
		orig.setPKey( value );
		copyPKeyToBuff();
	}

	public boolean getIsNew() {
		return( orig.getIsNew() );
	}

	public void setIsNew( boolean value ) {
		orig.setIsNew( value );
	}

	public short getRequiredISOTZoneId() {
		return( getPKey().getRequiredISOTZoneId() );
	}

	public String getRequiredIso8601() {
		return( getISOTZoneBuff().getRequiredIso8601() );
	}

	public void setRequiredIso8601( String value ) {
		if( getISOTZoneBuff().getRequiredIso8601() != value ) {
			getISOTZoneBuff().setRequiredIso8601( value );
		}
	}

	public String getRequiredTZName() {
		return( getISOTZoneBuff().getRequiredTZName() );
	}

	public void setRequiredTZName( String value ) {
		if( getISOTZoneBuff().getRequiredTZName() != value ) {
			getISOTZoneBuff().setRequiredTZName( value );
		}
	}

	public short getRequiredTZHourOffset() {
		return( getISOTZoneBuff().getRequiredTZHourOffset() );
	}

	public void setRequiredTZHourOffset( short value ) {
		if( getISOTZoneBuff().getRequiredTZHourOffset() != value ) {
			getISOTZoneBuff().setRequiredTZHourOffset( value );
		}
	}

	public short getRequiredTZMinOffset() {
		return( getISOTZoneBuff().getRequiredTZMinOffset() );
	}

	public void setRequiredTZMinOffset( short value ) {
		if( getISOTZoneBuff().getRequiredTZMinOffset() != value ) {
			getISOTZoneBuff().setRequiredTZMinOffset( value );
		}
	}

	public String getRequiredDescription() {
		return( getISOTZoneBuff().getRequiredDescription() );
	}

	public void setRequiredDescription( String value ) {
		if( getISOTZoneBuff().getRequiredDescription() != value ) {
			getISOTZoneBuff().setRequiredDescription( value );
		}
	}

	public boolean getRequiredVisible() {
		return( getISOTZoneBuff().getRequiredVisible() );
	}

	public void setRequiredVisible( boolean value ) {
		if( getISOTZoneBuff().getRequiredVisible() != value ) {
			getISOTZoneBuff().setRequiredVisible( value );
		}
	}

	public void copyPKeyToBuff() {
		buff.setRequiredISOTZoneId( getPKey().getRequiredISOTZoneId() );
	}

	public void copyBuffToPKey() {
		getPKey().setRequiredISOTZoneId( buff.getRequiredISOTZoneId() );
	}

	public void copyBuffToOrig() {
		CFSecISOTZoneBuff origBuff = getOrigAsISOTZone().getISOTZoneBuff();
		CFSecISOTZoneBuff myBuff = getISOTZoneBuff();
		origBuff.set( myBuff );
	}

	public void copyOrigToBuff() {
		CFSecISOTZoneBuff origBuff = getOrigAsISOTZone().getISOTZoneBuff();
		CFSecISOTZoneBuff myBuff = getISOTZoneBuff();
		myBuff.set( origBuff );
	}
}
