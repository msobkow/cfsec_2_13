// Description: Java 11 Table Object implementation for CFSec.

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

public class CFSecServiceTypeTableObj
	implements ICFSecServiceTypeTableObj
{
	protected ICFSecSchemaObj schema;
	private Map<CFSecServiceTypePKey, ICFSecServiceTypeObj> members;
	private Map<CFSecServiceTypePKey, ICFSecServiceTypeObj> allServiceType;
	private Map< CFSecServiceTypeByUDescrIdxKey,
		ICFSecServiceTypeObj > indexByUDescrIdx;
	public static String TABLE_NAME = "ServiceType";
	public static String TABLE_DBNAME = "svctype";

	public CFSecServiceTypeTableObj() {
		schema = null;
		members = new HashMap<CFSecServiceTypePKey, ICFSecServiceTypeObj>();
		allServiceType = null;
		indexByUDescrIdx = null;
	}

	public CFSecServiceTypeTableObj( ICFSecSchemaObj argSchema ) {
		schema = (ICFSecSchemaObj)argSchema;
		members = new HashMap<CFSecServiceTypePKey, ICFSecServiceTypeObj>();
		allServiceType = null;
		indexByUDescrIdx = null;
	}

	public ICFSecSchemaObj getSchema() {
		return( schema );
	}

	public void setSchema( ICFSecSchemaObj value ) {
		schema = (ICFSecSchemaObj)value;
	}

	public String getTableName() {
		return( TABLE_NAME );
	}

	public String getTableDbName() {
		return( TABLE_DBNAME );
	}

	public Class getObjQualifyingClass() {
		return( null );
	}


	public void minimizeMemory() {
		allServiceType = null;
		indexByUDescrIdx = null;
		List<ICFSecServiceTypeObj> toForget = new LinkedList<ICFSecServiceTypeObj>();
		ICFSecServiceTypeObj cur = null;
		Iterator<ICFSecServiceTypeObj> iter = members.values().iterator();
		while( iter.hasNext() ) {
			cur = iter.next();
			toForget.add( cur );
		}
		iter = toForget.iterator();
		while( iter.hasNext() ) {
			cur = iter.next();
			cur.forget();
		}
	}
	/**
	 *	If your implementation subclasses the objects,
	 *	you'll want to overload the constructByClassCode()
	 *	implementation to return your implementation's
	 *	instances instead of the base implementation.
	 *
	 *	This is the sole factory for instances derived from
	 *	CFSecServiceTypeObj.
	 */
	public ICFSecServiceTypeObj newInstance() {
		ICFSecServiceTypeObj inst = new CFSecServiceTypeObj( schema );
		return( inst );
	}

	/**
	 *	If your implementation subclasses the objects,
	 *	you'll want to overload the constructByClassCode()
	 *	implementation to return your implementation's
	 *	instances instead of the base implementation.
	 *
	 *	This is the sole factory for instances derived from
	 *	CFSecServiceTypeObj.
	 */
	public ICFSecServiceTypeEditObj newEditInstance( ICFSecServiceTypeObj orig ) {
		ICFSecServiceTypeEditObj edit = new CFSecServiceTypeEditObj( orig );
		return( edit );
	}

	public ICFSecServiceTypeObj realiseServiceType( ICFSecServiceTypeObj Obj ) {
		ICFSecServiceTypeObj obj = Obj;
		CFSecServiceTypePKey pkey = obj.getPKey();
		ICFSecServiceTypeObj keepObj = null;
		if( members.containsKey( pkey ) && ( null != members.get( pkey ) ) ) {
			ICFSecServiceTypeObj existingObj = members.get( pkey );
			keepObj = existingObj;

			/*
			 *	We always rebind the data because if we're being called, some index has
			 *	been updated and is refreshing it's data, which may or may not have changed
			 */

			// Detach object from alternate and duplicate indexes, leave PKey alone

			if( indexByUDescrIdx != null ) {
				CFSecServiceTypeByUDescrIdxKey keyUDescrIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryServiceType().newUDescrIdxKey();
				keyUDescrIdx.setRequiredDescription( keepObj.getRequiredDescription() );
				indexByUDescrIdx.remove( keyUDescrIdx );
			}

			keepObj.setBuff( Obj.getBuff() );
			// Attach new object to alternate and duplicate indexes -- PKey stay stable

			if( indexByUDescrIdx != null ) {
				CFSecServiceTypeByUDescrIdxKey keyUDescrIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryServiceType().newUDescrIdxKey();
				keyUDescrIdx.setRequiredDescription( keepObj.getRequiredDescription() );
				indexByUDescrIdx.put( keyUDescrIdx, keepObj );
			}

			if( allServiceType != null ) {
				allServiceType.put( keepObj.getPKey(), keepObj );
			}
		}
		else {
			keepObj = obj;
			keepObj.setIsNew( false );

			// Attach new object to PKey, all, alternate, and duplicate indexes
			members.put( keepObj.getPKey(), keepObj );
			if( allServiceType != null ) {
				allServiceType.put( keepObj.getPKey(), keepObj );
			}

			if( indexByUDescrIdx != null ) {
				CFSecServiceTypeByUDescrIdxKey keyUDescrIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryServiceType().newUDescrIdxKey();
				keyUDescrIdx.setRequiredDescription( keepObj.getRequiredDescription() );
				indexByUDescrIdx.put( keyUDescrIdx, keepObj );
			}

		}
		return( keepObj );
	}

	public ICFSecServiceTypeObj createServiceType( ICFSecServiceTypeObj Obj ) {
		ICFSecServiceTypeObj obj = Obj;
		CFSecServiceTypeBuff buff = obj.getServiceTypeBuff();
		((ICFSecSchema)schema.getBackingStore()).getTableServiceType().createServiceType(
			schema.getAuthorization(),
			buff );
		obj.copyBuffToPKey();
		obj = obj.realise();
		obj.endEdit();
		return( obj );
	}

	public ICFSecServiceTypeObj readServiceType( CFSecServiceTypePKey pkey ) {
		return( readServiceType( pkey, false ) );
	}

	public ICFSecServiceTypeObj readServiceType( CFSecServiceTypePKey pkey, boolean forceRead ) {
		ICFSecServiceTypeObj obj = null;
		if( ( ! forceRead ) && members.containsKey( pkey ) ) {
			obj = members.get( pkey );
		}
		else {
			CFSecServiceTypeBuff readBuff = ((ICFSecSchema)schema.getBackingStore()).getTableServiceType().readDerivedByIdIdx( schema.getAuthorization(),
				pkey.getRequiredServiceTypeId() );
			if( readBuff != null ) {
				obj = schema.getServiceTypeTableObj().newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactoryServiceType().newPKey() );
				obj.setBuff( readBuff );
				obj = (ICFSecServiceTypeObj)obj.realise();
			}
		}
		return( obj );
	}

	public ICFSecServiceTypeObj readCachedServiceType( CFSecServiceTypePKey pkey ) {
		ICFSecServiceTypeObj obj = null;
		if( members.containsKey( pkey ) ) {
			obj = members.get( pkey );
		}
		return( obj );
	}

	public void reallyDeepDisposeServiceType( ICFSecServiceTypeObj obj )
	{
		final String S_ProcName = "CFSecServiceTypeTableObj.reallyDeepDisposeServiceType() ";
		String classCode;
		if( obj == null ) {
			return;
		}
		CFSecServiceTypePKey pkey = obj.getPKey();
		ICFSecServiceTypeObj existing = readCachedServiceType( pkey );
		if( existing == null ) {
			return;
		}
		members.remove( pkey );
		CFSecServiceTypeByUDescrIdxKey keyUDescrIdx = ((ICFSecSchema)schema.getBackingStore()).getFactoryServiceType().newUDescrIdxKey();
		keyUDescrIdx.setRequiredDescription( existing.getRequiredDescription() );


		schema.getServiceTableObj().deepDisposeServiceByTypeIdx( existing.getRequiredServiceTypeId() );

		if( indexByUDescrIdx != null ) {
			indexByUDescrIdx.remove( keyUDescrIdx );
		}


	}
	public void deepDisposeServiceType( CFSecServiceTypePKey pkey ) {
		ICFSecServiceTypeObj obj = readCachedServiceType( pkey );
		if( obj != null ) {
			obj.forget();
		}
	}

	public ICFSecServiceTypeObj lockServiceType( CFSecServiceTypePKey pkey ) {
		ICFSecServiceTypeObj locked = null;
		CFSecServiceTypeBuff lockBuff = ((ICFSecSchema)schema.getBackingStore()).getTableServiceType().lockDerived( schema.getAuthorization(), pkey );
		if( lockBuff != null ) {
				locked = schema.getServiceTypeTableObj().newInstance();
			locked.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactoryServiceType().newPKey() );
			locked.setBuff( lockBuff );
			locked = (ICFSecServiceTypeObj)locked.realise();
		}
		else {
			throw new CFLibCollisionDetectedException( getClass(), "lockServiceType", pkey );
		}
		return( locked );
	}

	public List<ICFSecServiceTypeObj> readAllServiceType() {
		return( readAllServiceType( false ) );
	}

	public List<ICFSecServiceTypeObj> readAllServiceType( boolean forceRead ) {
		final String S_ProcName = "readAllServiceType";
		if( ( allServiceType == null ) || forceRead ) {
			Map<CFSecServiceTypePKey, ICFSecServiceTypeObj> map = new HashMap<CFSecServiceTypePKey,ICFSecServiceTypeObj>();
			allServiceType = map;
			CFSecServiceTypeBuff[] buffList = ((ICFSecSchema)schema.getBackingStore()).getTableServiceType().readAllDerived( schema.getAuthorization() );
			CFSecServiceTypeBuff buff;
			ICFSecServiceTypeObj obj;
			for( int idx = 0; idx < buffList.length; idx ++ ) {
				buff = buffList[ idx ];
				obj = newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactoryServiceType().newPKey() );
				obj.setBuff( buff );
				ICFSecServiceTypeObj realised = (ICFSecServiceTypeObj)obj.realise();
			}
		}
		int len = allServiceType.size();
		ICFSecServiceTypeObj arr[] = new ICFSecServiceTypeObj[len];
		Iterator<ICFSecServiceTypeObj> valIter = allServiceType.values().iterator();
		int idx = 0;
		while( ( idx < len ) && valIter.hasNext() ) {
			arr[idx++] = valIter.next();
		}
		if( idx < len ) {
			throw new CFLibArgumentUnderflowException( getClass(),
				S_ProcName,
				0,
				"idx",
				idx,
				len );
		}
		else if( valIter.hasNext() ) {
			throw new CFLibArgumentOverflowException( getClass(),
					S_ProcName,
					0,
					"idx",
					idx,
					len );
		}
		ArrayList<ICFSecServiceTypeObj> arrayList = new ArrayList<ICFSecServiceTypeObj>(len);
		for( idx = 0; idx < len; idx ++ ) {
			arrayList.add( arr[idx] );
		}

		Comparator<ICFSecServiceTypeObj> cmp = new Comparator<ICFSecServiceTypeObj>() {
			public int compare( ICFSecServiceTypeObj lhs, ICFSecServiceTypeObj rhs ) {
				if( lhs == null ) {
					if( rhs == null ) {
						return( 0 );
					}
					else {
						return( -1 );
					}
				}
				else if( rhs == null ) {
					return( 1 );
				}
				else {
					CFSecServiceTypePKey lhsPKey = lhs.getPKey();
					CFSecServiceTypePKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		List<ICFSecServiceTypeObj> sortedList = arrayList;
		return( sortedList );
	}

	public List<ICFSecServiceTypeObj> readCachedAllServiceType() {
		final String S_ProcName = "readCachedAllServiceType";
		ArrayList<ICFSecServiceTypeObj> arrayList = new ArrayList<ICFSecServiceTypeObj>();
		if( allServiceType != null ) {
			int len = allServiceType.size();
			ICFSecServiceTypeObj arr[] = new ICFSecServiceTypeObj[len];
			Iterator<ICFSecServiceTypeObj> valIter = allServiceType.values().iterator();
			int idx = 0;
			while( ( idx < len ) && valIter.hasNext() ) {
				arr[idx++] = valIter.next();
			}
			if( idx < len ) {
				throw new CFLibArgumentUnderflowException( getClass(),
					S_ProcName,
					0,
					"idx",
					idx,
					len );
			}
			else if( valIter.hasNext() ) {
				throw new CFLibArgumentOverflowException( getClass(),
						S_ProcName,
						0,
						"idx",
						idx,
						len );
			}
			for( idx = 0; idx < len; idx ++ ) {
				arrayList.add( arr[idx] );
			}
		}
		Comparator<ICFSecServiceTypeObj> cmp = new Comparator<ICFSecServiceTypeObj>() {
			public int compare( ICFSecServiceTypeObj lhs, ICFSecServiceTypeObj rhs ) {
				if( lhs == null ) {
					if( rhs == null ) {
						return( 0 );
					}
					else {
						return( -1 );
					}
				}
				else if( rhs == null ) {
					return( 1 );
				}
				else {
					CFSecServiceTypePKey lhsPKey = lhs.getPKey();
					CFSecServiceTypePKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		return( arrayList );
	}

	public ICFSecServiceTypeObj readServiceTypeByIdIdx( int ServiceTypeId )
	{
		return( readServiceTypeByIdIdx( ServiceTypeId,
			false ) );
	}

	public ICFSecServiceTypeObj readServiceTypeByIdIdx( int ServiceTypeId, boolean forceRead )
	{
		CFSecServiceTypePKey pkey = ((ICFSecSchema)schema.getBackingStore()).getFactoryServiceType().newPKey();
		pkey.setRequiredServiceTypeId( ServiceTypeId );
		ICFSecServiceTypeObj obj = readServiceType( pkey, forceRead );
		return( obj );
	}

	public ICFSecServiceTypeObj readServiceTypeByUDescrIdx( String Description )
	{
		return( readServiceTypeByUDescrIdx( Description,
			false ) );
	}

	public ICFSecServiceTypeObj readServiceTypeByUDescrIdx( String Description, boolean forceRead )
	{
		if( indexByUDescrIdx == null ) {
			indexByUDescrIdx = new HashMap< CFSecServiceTypeByUDescrIdxKey,
				ICFSecServiceTypeObj >();
		}
		CFSecServiceTypeByUDescrIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryServiceType().newUDescrIdxKey();
		key.setRequiredDescription( Description );
		ICFSecServiceTypeObj obj = null;
		if( ( ! forceRead ) && indexByUDescrIdx.containsKey( key ) ) {
			obj = indexByUDescrIdx.get( key );
		}
		else {
			CFSecServiceTypeBuff buff = ((ICFSecSchema)schema.getBackingStore()).getTableServiceType().readDerivedByUDescrIdx( schema.getAuthorization(),
				Description );
			if( buff != null ) {
				obj = schema.getServiceTypeTableObj().newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactoryServiceType().newPKey() );
				obj.setBuff( buff );
				obj = (ICFSecServiceTypeObj)obj.realise();
			}
		}
		return( obj );
	}

	public ICFSecServiceTypeObj readCachedServiceTypeByIdIdx( int ServiceTypeId )
	{
		ICFSecServiceTypeObj obj = null;
		CFSecServiceTypePKey pkey = ((ICFSecSchema)schema.getBackingStore()).getFactoryServiceType().newPKey();
		pkey.setRequiredServiceTypeId( ServiceTypeId );
		obj = readCachedServiceType( pkey );
		return( obj );
	}

	public ICFSecServiceTypeObj readCachedServiceTypeByUDescrIdx( String Description )
	{
		ICFSecServiceTypeObj obj = null;
		CFSecServiceTypeByUDescrIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryServiceType().newUDescrIdxKey();
		key.setRequiredDescription( Description );
		if( indexByUDescrIdx != null ) {
			if( indexByUDescrIdx.containsKey( key ) ) {
				obj = indexByUDescrIdx.get( key );
			}
			else {
				Iterator<ICFSecServiceTypeObj> valIter = members.values().iterator();
				while( ( obj == null ) && valIter.hasNext() ) {
					obj = valIter.next();
					if( obj != null ) {
						if( obj.getBuff().compareTo( key ) != 0 ) {
							obj = null;
						}
					}
				}
			}
		}
		else {
			Iterator<ICFSecServiceTypeObj> valIter = members.values().iterator();
			while( valIter.hasNext() ) {
				obj = valIter.next();
				if( obj != null ) {
					if( obj.getBuff().compareTo( key ) != 0 ) {
						obj = null;
					}
				}
			}
		}
		return( obj );
	}

	public void deepDisposeServiceTypeByIdIdx( int ServiceTypeId )
	{
		ICFSecServiceTypeObj obj = readCachedServiceTypeByIdIdx( ServiceTypeId );
		if( obj != null ) {
			obj.forget();
		}
	}

	public void deepDisposeServiceTypeByUDescrIdx( String Description )
	{
		ICFSecServiceTypeObj obj = readCachedServiceTypeByUDescrIdx( Description );
		if( obj != null ) {
			obj.forget();
		}
	}

	public ICFSecServiceTypeObj updateServiceType( ICFSecServiceTypeObj Obj ) {
		ICFSecServiceTypeObj obj = Obj;
		((ICFSecSchema)schema.getBackingStore()).getTableServiceType().updateServiceType( schema.getAuthorization(),
			Obj.getServiceTypeBuff() );
		obj = (ICFSecServiceTypeObj)Obj.realise();
		obj.endEdit();
		return( obj );
	}

	public void deleteServiceType( ICFSecServiceTypeObj Obj ) {
		ICFSecServiceTypeObj obj = Obj;
		((ICFSecSchema)schema.getBackingStore()).getTableServiceType().deleteServiceType( schema.getAuthorization(),
			obj.getServiceTypeBuff() );
		Obj.forget();
	}

	public void deleteServiceTypeByIdIdx( int ServiceTypeId )
	{
		CFSecServiceTypePKey pkey = ((ICFSecSchema)schema.getBackingStore()).getFactoryServiceType().newPKey();
		pkey.setRequiredServiceTypeId( ServiceTypeId );
		ICFSecServiceTypeObj obj = readServiceType( pkey );
		if( obj != null ) {
			ICFSecServiceTypeEditObj editObj = (ICFSecServiceTypeEditObj)obj.getEdit();
			boolean editStarted;
			if( editObj == null ) {
				editObj = (ICFSecServiceTypeEditObj)obj.beginEdit();
				if( editObj != null ) {
					editStarted = true;
				}
				else {
					editStarted = false;
				}
			}
			else {
				editStarted = false;
			}
			if( editObj != null ) {
				editObj.deleteInstance();
				if( editStarted ) {
					editObj.endEdit();
				}
			}
			obj.forget();
		}
		deepDisposeServiceTypeByIdIdx( ServiceTypeId );
	}

	public void deleteServiceTypeByUDescrIdx( String Description )
	{
		if( indexByUDescrIdx == null ) {
			indexByUDescrIdx = new HashMap< CFSecServiceTypeByUDescrIdxKey,
				ICFSecServiceTypeObj >();
		}
		CFSecServiceTypeByUDescrIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryServiceType().newUDescrIdxKey();
		key.setRequiredDescription( Description );
		ICFSecServiceTypeObj obj = null;
		if( indexByUDescrIdx.containsKey( key ) ) {
			obj = indexByUDescrIdx.get( key );
			((ICFSecSchema)schema.getBackingStore()).getTableServiceType().deleteServiceTypeByUDescrIdx( schema.getAuthorization(),
				Description );
			obj.forget();
		}
		else {
			((ICFSecSchema)schema.getBackingStore()).getTableServiceType().deleteServiceTypeByUDescrIdx( schema.getAuthorization(),
				Description );
		}
		deepDisposeServiceTypeByUDescrIdx( Description );
	}
}