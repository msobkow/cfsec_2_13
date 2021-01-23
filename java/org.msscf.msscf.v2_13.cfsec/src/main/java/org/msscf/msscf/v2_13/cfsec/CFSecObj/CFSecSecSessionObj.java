// Description: Java 11 base object instance implementation for CFSec SecSession.

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

public class CFSecSecSessionObj
	implements ICFSecSecSessionObj
{
	public final static String CLASS_CODE = "a010";
	protected boolean isNew;
	protected ICFSecSecSessionEditObj edit;
	protected ICFSecSchemaObj schema;
	protected CFSecSecSessionPKey pKey;
	protected CFSecSecSessionBuff buff;
	protected ICFSecSecUserObj requiredContainerSecUser;
	protected ICFSecSecUserObj requiredParentSecProxy;

	public CFSecSecSessionObj() {
		isNew = true;
		requiredContainerSecUser = null;
		requiredParentSecProxy = null;
	}

	public CFSecSecSessionObj( ICFSecSchemaObj argSchema ) {
		schema = argSchema;
		isNew = true;
		edit = null;
		requiredContainerSecUser = null;
		requiredParentSecProxy = null;
	}

	public String getClassCode() {
		return( CLASS_CODE );
	}

	public String getGenDefName() {
		return( "SecSession" );
	}

	public ICFLibAnyObj getScope() {
		ICFSecSecUserObj scope = getRequiredContainerSecUser();
		return( scope );
	}

	public ICFLibAnyObj getObjScope() {
		ICFSecSecUserObj scope = getRequiredContainerSecUser();
		return( scope );
	}

	public String getObjName() {
		String objName;
		UUID val = getRequiredSecSessionId();
		objName = val.toString();
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

	public ICFSecSecSessionObj realise() {
		ICFSecSecSessionObj retobj = ((ICFSecSchemaObj)schema).getSecSessionTableObj().realiseSecSession(
			(ICFSecSecSessionObj)this );
		return( (ICFSecSecSessionObj)retobj );
	}

	public void forget() {
		((ICFSecSchemaObj)schema).getSecSessionTableObj().reallyDeepDisposeSecSession( (ICFSecSecSessionObj)this );
	}

	public ICFSecSecSessionObj read() {
		ICFSecSecSessionObj retobj = ((ICFSecSchemaObj)schema).getSecSessionTableObj().readSecSessionByIdIdx( getPKey().getRequiredSecSessionId(), false );
		return( (ICFSecSecSessionObj)retobj );
	}

	public ICFSecSecSessionObj read( boolean forceRead ) {
		ICFSecSecSessionObj retobj = ((ICFSecSchemaObj)schema).getSecSessionTableObj().readSecSessionByIdIdx( getPKey().getRequiredSecSessionId(), forceRead );
		return( (ICFSecSecSessionObj)retobj );
	}

	public ICFSecSecSessionTableObj getSecSessionTable() {
		return( ((ICFSecSchemaObj)schema).getSecSessionTableObj() );
	}

	public ICFSecSchemaObj getSchema() {
		return( schema );
	}

	public void setSchema( ICFSecSchemaObj value ) {
		schema = value;
	}

	public CFSecSecSessionBuff getBuff() {
		if( buff == null ) {
			if( isNew ) {
				buff = ((ICFSecSchema)schema.getBackingStore()).getFactorySecSession().newBuff();
			}
			else {
				// Read the data buff via the backing store
				buff = ((ICFSecSchema)schema.getBackingStore()).getTableSecSession().readDerivedByIdIdx( ((ICFSecSchemaObj)schema).getAuthorization(),
						getPKey().getRequiredSecSessionId() );
				if( buff != null ) {
					copyBuffToPKey();
				}
			}
		}
		return( buff );
	}

	public void setBuff( CFSecSecSessionBuff value ) {
		if( ! ( ( value == null ) || ( value instanceof CFSecSecSessionBuff ) ) ) {
			throw new CFLibUnsupportedClassException( getClass(),
				"setBuff",
				"value",
				value,
				"CFSecSecSessionBuff" );
		}
		buff = value;
		copyBuffToPKey();
		requiredContainerSecUser = null;
		requiredParentSecProxy = null;
	}

	public CFSecSecSessionBuff getSecSessionBuff() {
		return( (CFSecSecSessionBuff)getBuff() );
	}

	public CFSecSecSessionPKey getPKey() {
		if( pKey == null ) {
			pKey = ((ICFSecSchema)schema.getBackingStore()).getFactorySecSession().newPKey();
		}
		return( pKey );
	}

	public void setPKey( CFSecSecSessionPKey value ) {
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

	public ICFSecSecSessionEditObj beginEdit() {
		if( edit != null ) {
			throw new CFLibUsageException( getClass(), "beginEdit", "An edit is already open" );
		}
		ICFSecSecSessionObj lockobj;
		if( getIsNew() ) {
			lockobj = (ICFSecSecSessionObj)this;
		}
		else {
			lockobj = ((ICFSecSchemaObj)schema).getSecSessionTableObj().lockSecSession( getPKey() );
		}
		edit = ((ICFSecSchemaObj)schema).getSecSessionTableObj().newEditInstance( lockobj );
		return( (ICFSecSecSessionEditObj)edit );
	}

	public void endEdit() {
		edit = null;
	}

	public ICFSecSecSessionEditObj getEdit() {
		return( edit );
	}

	public ICFSecSecSessionEditObj getEditAsSecSession() {
		return( (ICFSecSecSessionEditObj)edit );
	}

	public UUID getRequiredSecSessionId() {
		return( getPKey().getRequiredSecSessionId() );
	}

	public UUID getRequiredSecUserId() {
		return( getSecSessionBuff().getRequiredSecUserId() );
	}

	public String getOptionalSecDevName() {
		return( getSecSessionBuff().getOptionalSecDevName() );
	}

	public Calendar getRequiredStart() {
		return( getSecSessionBuff().getRequiredStart() );
	}

	public Calendar getOptionalFinish() {
		return( getSecSessionBuff().getOptionalFinish() );
	}

	public UUID getOptionalSecProxyId() {
		return( getSecSessionBuff().getOptionalSecProxyId() );
	}

	public ICFSecSecUserObj getRequiredContainerSecUser() {
		return( getRequiredContainerSecUser( false ) );
	}

	public ICFSecSecUserObj getRequiredContainerSecUser( boolean forceRead ) {
		if( ( requiredContainerSecUser == null ) || forceRead ) {
			boolean anyMissing = false;
			if( ! anyMissing ) {
				requiredContainerSecUser = ((ICFSecSchemaObj)schema).getSecUserTableObj().readSecUserByIdIdx( getSecSessionBuff().getRequiredSecUserId(), forceRead );
			}
		}
		return( requiredContainerSecUser );
	}

	public ICFSecSecUserObj getRequiredParentSecProxy() {
		return( getRequiredParentSecProxy( false ) );
	}

	public ICFSecSecUserObj getRequiredParentSecProxy( boolean forceRead ) {
		if( ( requiredParentSecProxy == null ) || forceRead ) {
			boolean anyMissing = false;
			if( getSecSessionBuff().getOptionalSecProxyId() == null ) {
				anyMissing = true;
			}
			if( ! anyMissing ) {
				requiredParentSecProxy = ((ICFSecSchemaObj)schema).getSecUserTableObj().readSecUserByIdIdx( getSecSessionBuff().getOptionalSecProxyId(), forceRead );
			}
		}
		return( requiredParentSecProxy );
	}

	public void copyPKeyToBuff() {
		if( buff != null ) {
			buff.setRequiredSecSessionId( getPKey().getRequiredSecSessionId() );
		}
		if( edit != null ) {
			edit.copyPKeyToBuff();
		}
	}

	public void copyBuffToPKey() {
		getPKey().setRequiredSecSessionId( buff.getRequiredSecSessionId() );
	}
}
