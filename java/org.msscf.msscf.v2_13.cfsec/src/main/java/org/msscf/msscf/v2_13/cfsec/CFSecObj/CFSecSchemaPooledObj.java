// Description: Java 11 Schema Pooled Object implementation for CFSec.

/*
 *	org.msscf.msscf.CFSec
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFSec 2.13 Security Essentials
 *	
 *	Copyright 2020 Mark Stephen Sobkow msobkow@sasktel.net
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

import java.util.*;
import org.msscf.msscf.v2_13.cflib.CFLib.*;
import org.msscf.msscf.v2_13.cfsec.CFSec.*;

/**
 *	A pooled schema object does not disconnect the backing
 *	store when a logout is performed, because the backing store
 *	comes from a connection pool that is reused across requests,
 *	rather than being owned by the SchemaPooledObj.
 */
public class CFSecSchemaPooledObj
	extends CFSecSchemaObj
{
	public CFSecSchemaPooledObj() {
		super();
	}

	public boolean isConnected() {
		if( backingStore == null ) {
			return( false );
		}
		else {
			return( true );
		}
	}

	public void disconnect( boolean doCommit ) {
		final String S_ProcName = "disconnect";
		throw new CFLibUsageException( getClass(),
			S_ProcName,
			"Schema objects over pooled storage cannot be explicitly disconnected" );
	}

	public void logout() {
		if( ( authorization == null ) || ( backingStore == null ) ) {
			return;
		}
		try {
			boolean transactionStarted = beginTransaction();
			if( ! transactionStarted ) {
				rollback();
				transactionStarted = beginTransaction();
				if( ! transactionStarted ) {
					setAuthorization( null );
					return;
				}
			}
			UUID secSessionId = authorization.getSecSessionId();
			if( secSessionId != null ) {
				ICFSecSecSessionObj secSession = getSecSessionTableObj().readSecSessionByIdIdx( secSessionId );
				if( secSession != null ) {
					if( secSession.getOptionalFinish() == null ) {
						ICFSecSecSessionEditObj editSecSession = secSession.beginEdit();
						editSecSession.setOptionalFinish( Calendar.getInstance() );
						editSecSession.update();
						editSecSession = null;
					}
				}
			}
			commit();
		}
		finally {
			setAuthorization( null );
			minimizeMemory();
		}
	}
}
