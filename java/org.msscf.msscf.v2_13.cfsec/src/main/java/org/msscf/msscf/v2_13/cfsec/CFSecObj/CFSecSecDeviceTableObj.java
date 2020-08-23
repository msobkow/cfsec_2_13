// Description: Java 11 Table Object implementation for CFSec.

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

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.msscf.msscf.v2_13.cflib.CFLib.*;
import org.msscf.msscf.v2_13.cfsec.CFSec.*;

public class CFSecSecDeviceTableObj
	implements ICFSecSecDeviceTableObj
{
	protected ICFSecSchemaObj schema;
	private Map<CFSecSecDevicePKey, ICFSecSecDeviceObj> members;
	private Map<CFSecSecDevicePKey, ICFSecSecDeviceObj> allSecDevice;
	private Map< CFSecSecDeviceByNameIdxKey,
		ICFSecSecDeviceObj > indexByNameIdx;
	private Map< CFSecSecDeviceByUserIdxKey,
		Map<CFSecSecDevicePKey, ICFSecSecDeviceObj > > indexByUserIdx;
	public static String TABLE_NAME = "SecDevice";
	public static String TABLE_DBNAME = "secdev";

	public CFSecSecDeviceTableObj() {
		schema = null;
		members = new HashMap<CFSecSecDevicePKey, ICFSecSecDeviceObj>();
		allSecDevice = null;
		indexByNameIdx = null;
		indexByUserIdx = null;
	}

	public CFSecSecDeviceTableObj( ICFSecSchemaObj argSchema ) {
		schema = (ICFSecSchemaObj)argSchema;
		members = new HashMap<CFSecSecDevicePKey, ICFSecSecDeviceObj>();
		allSecDevice = null;
		indexByNameIdx = null;
		indexByUserIdx = null;
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
		allSecDevice = null;
		indexByNameIdx = null;
		indexByUserIdx = null;
		List<ICFSecSecDeviceObj> toForget = new LinkedList<ICFSecSecDeviceObj>();
		ICFSecSecDeviceObj cur = null;
		Iterator<ICFSecSecDeviceObj> iter = members.values().iterator();
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
	 *	CFSecSecDeviceObj.
	 */
	public ICFSecSecDeviceObj newInstance() {
		ICFSecSecDeviceObj inst = new CFSecSecDeviceObj( schema );
		return( inst );
	}

	/**
	 *	If your implementation subclasses the objects,
	 *	you'll want to overload the constructByClassCode()
	 *	implementation to return your implementation's
	 *	instances instead of the base implementation.
	 *
	 *	This is the sole factory for instances derived from
	 *	CFSecSecDeviceObj.
	 */
	public ICFSecSecDeviceEditObj newEditInstance( ICFSecSecDeviceObj orig ) {
		ICFSecSecDeviceEditObj edit = new CFSecSecDeviceEditObj( orig );
		return( edit );
	}

	public ICFSecSecDeviceObj realiseSecDevice( ICFSecSecDeviceObj Obj ) {
		ICFSecSecDeviceObj obj = Obj;
		CFSecSecDevicePKey pkey = obj.getPKey();
		ICFSecSecDeviceObj keepObj = null;
		if( members.containsKey( pkey ) && ( null != members.get( pkey ) ) ) {
			ICFSecSecDeviceObj existingObj = members.get( pkey );
			keepObj = existingObj;

			/*
			 *	We always rebind the data because if we're being called, some index has
			 *	been updated and is refreshing it's data, which may or may not have changed
			 */

			// Detach object from alternate and duplicate indexes, leave PKey alone

			if( indexByNameIdx != null ) {
				CFSecSecDeviceByNameIdxKey keyNameIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactorySecDevice().newNameIdxKey();
				keyNameIdx.setRequiredSecUserId( keepObj.getRequiredSecUserId() );
				keyNameIdx.setRequiredDevName( keepObj.getRequiredDevName() );
				indexByNameIdx.remove( keyNameIdx );
			}

			if( indexByUserIdx != null ) {
				CFSecSecDeviceByUserIdxKey keyUserIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactorySecDevice().newUserIdxKey();
				keyUserIdx.setRequiredSecUserId( keepObj.getRequiredSecUserId() );
				Map<CFSecSecDevicePKey, ICFSecSecDeviceObj > mapUserIdx = indexByUserIdx.get( keyUserIdx );
				if( mapUserIdx != null ) {
					mapUserIdx.remove( keepObj.getPKey() );
					if( mapUserIdx.size() <= 0 ) {
						indexByUserIdx.remove( keyUserIdx );
					}
				}
			}

			keepObj.setBuff( Obj.getBuff() );
			// Attach new object to alternate and duplicate indexes -- PKey stay stable

			if( indexByNameIdx != null ) {
				CFSecSecDeviceByNameIdxKey keyNameIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactorySecDevice().newNameIdxKey();
				keyNameIdx.setRequiredSecUserId( keepObj.getRequiredSecUserId() );
				keyNameIdx.setRequiredDevName( keepObj.getRequiredDevName() );
				indexByNameIdx.put( keyNameIdx, keepObj );
			}

			if( indexByUserIdx != null ) {
				CFSecSecDeviceByUserIdxKey keyUserIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactorySecDevice().newUserIdxKey();
				keyUserIdx.setRequiredSecUserId( keepObj.getRequiredSecUserId() );
				Map<CFSecSecDevicePKey, ICFSecSecDeviceObj > mapUserIdx = indexByUserIdx.get( keyUserIdx );
				if( mapUserIdx != null ) {
					mapUserIdx.put( keepObj.getPKey(), keepObj );
				}
			}

			if( allSecDevice != null ) {
				allSecDevice.put( keepObj.getPKey(), keepObj );
			}
		}
		else {
			keepObj = obj;
			keepObj.setIsNew( false );

			// Attach new object to PKey, all, alternate, and duplicate indexes
			members.put( keepObj.getPKey(), keepObj );
			if( allSecDevice != null ) {
				allSecDevice.put( keepObj.getPKey(), keepObj );
			}

			if( indexByNameIdx != null ) {
				CFSecSecDeviceByNameIdxKey keyNameIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactorySecDevice().newNameIdxKey();
				keyNameIdx.setRequiredSecUserId( keepObj.getRequiredSecUserId() );
				keyNameIdx.setRequiredDevName( keepObj.getRequiredDevName() );
				indexByNameIdx.put( keyNameIdx, keepObj );
			}

			if( indexByUserIdx != null ) {
				CFSecSecDeviceByUserIdxKey keyUserIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactorySecDevice().newUserIdxKey();
				keyUserIdx.setRequiredSecUserId( keepObj.getRequiredSecUserId() );
				Map<CFSecSecDevicePKey, ICFSecSecDeviceObj > mapUserIdx = indexByUserIdx.get( keyUserIdx );
				if( mapUserIdx != null ) {
					mapUserIdx.put( keepObj.getPKey(), keepObj );
				}
			}

		}
		return( keepObj );
	}

	public ICFSecSecDeviceObj createSecDevice( ICFSecSecDeviceObj Obj ) {
		ICFSecSecDeviceObj obj = Obj;
		CFSecSecDeviceBuff buff = obj.getSecDeviceBuff();
		((ICFSecSchema)schema.getBackingStore()).getTableSecDevice().createSecDevice(
			schema.getAuthorization(),
			buff );
		obj.copyBuffToPKey();
		obj = obj.realise();
		obj.endEdit();
		return( obj );
	}

	public ICFSecSecDeviceObj readSecDevice( CFSecSecDevicePKey pkey ) {
		return( readSecDevice( pkey, false ) );
	}

	public ICFSecSecDeviceObj readSecDevice( CFSecSecDevicePKey pkey, boolean forceRead ) {
		ICFSecSecDeviceObj obj = null;
		if( ( ! forceRead ) && members.containsKey( pkey ) ) {
			obj = members.get( pkey );
		}
		else {
			CFSecSecDeviceBuff readBuff = ((ICFSecSchema)schema.getBackingStore()).getTableSecDevice().readDerivedByIdIdx( schema.getAuthorization(),
				pkey.getRequiredSecUserId(),
				pkey.getRequiredDevName() );
			if( readBuff != null ) {
				obj = schema.getSecDeviceTableObj().newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactorySecDevice().newPKey() );
				obj.setBuff( readBuff );
				obj = (ICFSecSecDeviceObj)obj.realise();
			}
		}
		return( obj );
	}

	public ICFSecSecDeviceObj readCachedSecDevice( CFSecSecDevicePKey pkey ) {
		ICFSecSecDeviceObj obj = null;
		if( members.containsKey( pkey ) ) {
			obj = members.get( pkey );
		}
		return( obj );
	}

	public void reallyDeepDisposeSecDevice( ICFSecSecDeviceObj obj )
	{
		final String S_ProcName = "CFSecSecDeviceTableObj.reallyDeepDisposeSecDevice() ";
		String classCode;
		if( obj == null ) {
			return;
		}
		CFSecSecDevicePKey pkey = obj.getPKey();
		ICFSecSecDeviceObj existing = readCachedSecDevice( pkey );
		if( existing == null ) {
			return;
		}
		members.remove( pkey );
		CFSecSecDeviceByNameIdxKey keyNameIdx = ((ICFSecSchema)schema.getBackingStore()).getFactorySecDevice().newNameIdxKey();
		keyNameIdx.setRequiredSecUserId( existing.getRequiredSecUserId() );
		keyNameIdx.setRequiredDevName( existing.getRequiredDevName() );

		CFSecSecDeviceByUserIdxKey keyUserIdx = ((ICFSecSchema)schema.getBackingStore()).getFactorySecDevice().newUserIdxKey();
		keyUserIdx.setRequiredSecUserId( existing.getRequiredSecUserId() );



		if( indexByNameIdx != null ) {
			indexByNameIdx.remove( keyNameIdx );
		}

		if( indexByUserIdx != null ) {
			if( indexByUserIdx.containsKey( keyUserIdx ) ) {
				indexByUserIdx.get( keyUserIdx ).remove( pkey );
				if( indexByUserIdx.get( keyUserIdx ).size() <= 0 ) {
					indexByUserIdx.remove( keyUserIdx );
				}
			}
		}


	}
	public void deepDisposeSecDevice( CFSecSecDevicePKey pkey ) {
		ICFSecSecDeviceObj obj = readCachedSecDevice( pkey );
		if( obj != null ) {
			obj.forget();
		}
	}

	public ICFSecSecDeviceObj lockSecDevice( CFSecSecDevicePKey pkey ) {
		ICFSecSecDeviceObj locked = null;
		CFSecSecDeviceBuff lockBuff = ((ICFSecSchema)schema.getBackingStore()).getTableSecDevice().lockDerived( schema.getAuthorization(), pkey );
		if( lockBuff != null ) {
				locked = schema.getSecDeviceTableObj().newInstance();
			locked.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactorySecDevice().newPKey() );
			locked.setBuff( lockBuff );
			locked = (ICFSecSecDeviceObj)locked.realise();
		}
		else {
			throw new CFLibCollisionDetectedException( getClass(), "lockSecDevice", pkey );
		}
		return( locked );
	}

	public List<ICFSecSecDeviceObj> readAllSecDevice() {
		return( readAllSecDevice( false ) );
	}

	public List<ICFSecSecDeviceObj> readAllSecDevice( boolean forceRead ) {
		final String S_ProcName = "readAllSecDevice";
		if( ( allSecDevice == null ) || forceRead ) {
			Map<CFSecSecDevicePKey, ICFSecSecDeviceObj> map = new HashMap<CFSecSecDevicePKey,ICFSecSecDeviceObj>();
			allSecDevice = map;
			CFSecSecDeviceBuff[] buffList = ((ICFSecSchema)schema.getBackingStore()).getTableSecDevice().readAllDerived( schema.getAuthorization() );
			CFSecSecDeviceBuff buff;
			ICFSecSecDeviceObj obj;
			for( int idx = 0; idx < buffList.length; idx ++ ) {
				buff = buffList[ idx ];
				obj = newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactorySecDevice().newPKey() );
				obj.setBuff( buff );
				ICFSecSecDeviceObj realised = (ICFSecSecDeviceObj)obj.realise();
			}
		}
		int len = allSecDevice.size();
		ICFSecSecDeviceObj arr[] = new ICFSecSecDeviceObj[len];
		Iterator<ICFSecSecDeviceObj> valIter = allSecDevice.values().iterator();
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
		ArrayList<ICFSecSecDeviceObj> arrayList = new ArrayList<ICFSecSecDeviceObj>(len);
		for( idx = 0; idx < len; idx ++ ) {
			arrayList.add( arr[idx] );
		}

		Comparator<ICFSecSecDeviceObj> cmp = new Comparator<ICFSecSecDeviceObj>() {
			public int compare( ICFSecSecDeviceObj lhs, ICFSecSecDeviceObj rhs ) {
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
					CFSecSecDevicePKey lhsPKey = lhs.getPKey();
					CFSecSecDevicePKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		List<ICFSecSecDeviceObj> sortedList = arrayList;
		return( sortedList );
	}

	public List<ICFSecSecDeviceObj> readCachedAllSecDevice() {
		final String S_ProcName = "readCachedAllSecDevice";
		ArrayList<ICFSecSecDeviceObj> arrayList = new ArrayList<ICFSecSecDeviceObj>();
		if( allSecDevice != null ) {
			int len = allSecDevice.size();
			ICFSecSecDeviceObj arr[] = new ICFSecSecDeviceObj[len];
			Iterator<ICFSecSecDeviceObj> valIter = allSecDevice.values().iterator();
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
		Comparator<ICFSecSecDeviceObj> cmp = new Comparator<ICFSecSecDeviceObj>() {
			public int compare( ICFSecSecDeviceObj lhs, ICFSecSecDeviceObj rhs ) {
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
					CFSecSecDevicePKey lhsPKey = lhs.getPKey();
					CFSecSecDevicePKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		return( arrayList );
	}

	/**
	 *	Return a sorted map of a page of the SecDevice-derived instances in the database.
	 *
	 *	@return	List of ICFSecSecDeviceObj instance, sorted by their primary keys, which
	 *		may include an empty set.
	 */
	public List<ICFSecSecDeviceObj> pageAllSecDevice(UUID priorSecUserId,
		String priorDevName )
	{
		final String S_ProcName = "pageAllSecDevice";
		Map<CFSecSecDevicePKey, ICFSecSecDeviceObj> map = new HashMap<CFSecSecDevicePKey,ICFSecSecDeviceObj>();
		CFSecSecDeviceBuff[] buffList = ((ICFSecSchema)schema.getBackingStore()).getTableSecDevice().pageAllBuff( schema.getAuthorization(),
			priorSecUserId,
			priorDevName );
		CFSecSecDeviceBuff buff;
		ICFSecSecDeviceObj obj;
		ICFSecSecDeviceObj realised;
		ArrayList<ICFSecSecDeviceObj> arrayList = new ArrayList<ICFSecSecDeviceObj>( buffList.length );
		for( int idx = 0; idx < buffList.length; idx ++ ) {
			buff = buffList[ idx ];
				obj = newInstance();
			obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactorySecDevice().newPKey() );
			obj.setBuff( buff );
			realised = (ICFSecSecDeviceObj)obj.realise();
			arrayList.add( realised );
		}
		return( arrayList );
	}

	public ICFSecSecDeviceObj readSecDeviceByIdIdx( UUID SecUserId,
		String DevName )
	{
		return( readSecDeviceByIdIdx( SecUserId,
			DevName,
			false ) );
	}

	public ICFSecSecDeviceObj readSecDeviceByIdIdx( UUID SecUserId,
		String DevName, boolean forceRead )
	{
		CFSecSecDevicePKey pkey = ((ICFSecSchema)schema.getBackingStore()).getFactorySecDevice().newPKey();
		pkey.setRequiredSecUserId( SecUserId );
		pkey.setRequiredDevName( DevName );
		ICFSecSecDeviceObj obj = readSecDevice( pkey, forceRead );
		return( obj );
	}

	public ICFSecSecDeviceObj readSecDeviceByNameIdx( UUID SecUserId,
		String DevName )
	{
		return( readSecDeviceByNameIdx( SecUserId,
			DevName,
			false ) );
	}

	public ICFSecSecDeviceObj readSecDeviceByNameIdx( UUID SecUserId,
		String DevName, boolean forceRead )
	{
		if( indexByNameIdx == null ) {
			indexByNameIdx = new HashMap< CFSecSecDeviceByNameIdxKey,
				ICFSecSecDeviceObj >();
		}
		CFSecSecDeviceByNameIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactorySecDevice().newNameIdxKey();
		key.setRequiredSecUserId( SecUserId );
		key.setRequiredDevName( DevName );
		ICFSecSecDeviceObj obj = null;
		if( ( ! forceRead ) && indexByNameIdx.containsKey( key ) ) {
			obj = indexByNameIdx.get( key );
		}
		else {
			CFSecSecDeviceBuff buff = ((ICFSecSchema)schema.getBackingStore()).getTableSecDevice().readDerivedByNameIdx( schema.getAuthorization(),
				SecUserId,
				DevName );
			if( buff != null ) {
				obj = schema.getSecDeviceTableObj().newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactorySecDevice().newPKey() );
				obj.setBuff( buff );
				obj = (ICFSecSecDeviceObj)obj.realise();
			}
		}
		return( obj );
	}

	public List<ICFSecSecDeviceObj> readSecDeviceByUserIdx( UUID SecUserId )
	{
		return( readSecDeviceByUserIdx( SecUserId,
			false ) );
	}

	public List<ICFSecSecDeviceObj> readSecDeviceByUserIdx( UUID SecUserId,
		boolean forceRead )
	{
		final String S_ProcName = "readSecDeviceByUserIdx";
		CFSecSecDeviceByUserIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactorySecDevice().newUserIdxKey();
		key.setRequiredSecUserId( SecUserId );
		Map<CFSecSecDevicePKey, ICFSecSecDeviceObj> dict;
		if( indexByUserIdx == null ) {
			indexByUserIdx = new HashMap< CFSecSecDeviceByUserIdxKey,
				Map< CFSecSecDevicePKey, ICFSecSecDeviceObj > >();
		}
		if( ( ! forceRead ) && indexByUserIdx.containsKey( key ) ) {
			dict = indexByUserIdx.get( key );
		}
		else {
			dict = new HashMap<CFSecSecDevicePKey, ICFSecSecDeviceObj>();
			ICFSecSecDeviceObj obj;
			CFSecSecDeviceBuff[] buffList = ((ICFSecSchema)schema.getBackingStore()).getTableSecDevice().readDerivedByUserIdx( schema.getAuthorization(),
				SecUserId );
			CFSecSecDeviceBuff buff;
			for( int idx = 0; idx < buffList.length; idx ++ ) {
				buff = buffList[ idx ];
				obj = schema.getSecDeviceTableObj().newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactorySecDevice().newPKey() );
				obj.setBuff( buff );
				ICFSecSecDeviceObj realised = (ICFSecSecDeviceObj)obj.realise();
				dict.put( realised.getPKey(), realised );
			}
			indexByUserIdx.put( key, dict );
		}
		int len = dict.size();
		ICFSecSecDeviceObj arr[] = new ICFSecSecDeviceObj[len];
		Iterator<ICFSecSecDeviceObj> valIter = dict.values().iterator();
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
		ArrayList<ICFSecSecDeviceObj> arrayList = new ArrayList<ICFSecSecDeviceObj>(len);
		for( idx = 0; idx < len; idx ++ ) {
			arrayList.add( arr[idx] );
		}

		Comparator<ICFSecSecDeviceObj> cmp = new Comparator<ICFSecSecDeviceObj>() {
			public int compare( ICFSecSecDeviceObj lhs, ICFSecSecDeviceObj rhs ) {
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
					CFSecSecDevicePKey lhsPKey = lhs.getPKey();
					CFSecSecDevicePKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		List<ICFSecSecDeviceObj> sortedList = arrayList;
		return( sortedList );
	}

	public ICFSecSecDeviceObj readCachedSecDeviceByIdIdx( UUID SecUserId,
		String DevName )
	{
		ICFSecSecDeviceObj obj = null;
		CFSecSecDevicePKey pkey = ((ICFSecSchema)schema.getBackingStore()).getFactorySecDevice().newPKey();
		pkey.setRequiredSecUserId( SecUserId );
		pkey.setRequiredDevName( DevName );
		obj = readCachedSecDevice( pkey );
		return( obj );
	}

	public ICFSecSecDeviceObj readCachedSecDeviceByNameIdx( UUID SecUserId,
		String DevName )
	{
		ICFSecSecDeviceObj obj = null;
		CFSecSecDeviceByNameIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactorySecDevice().newNameIdxKey();
		key.setRequiredSecUserId( SecUserId );
		key.setRequiredDevName( DevName );
		if( indexByNameIdx != null ) {
			if( indexByNameIdx.containsKey( key ) ) {
				obj = indexByNameIdx.get( key );
			}
			else {
				Iterator<ICFSecSecDeviceObj> valIter = members.values().iterator();
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
			Iterator<ICFSecSecDeviceObj> valIter = members.values().iterator();
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

	public List<ICFSecSecDeviceObj> readCachedSecDeviceByUserIdx( UUID SecUserId )
	{
		final String S_ProcName = "readCachedSecDeviceByUserIdx";
		CFSecSecDeviceByUserIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactorySecDevice().newUserIdxKey();
		key.setRequiredSecUserId( SecUserId );
		ArrayList<ICFSecSecDeviceObj> arrayList = new ArrayList<ICFSecSecDeviceObj>();
		if( indexByUserIdx != null ) {
			Map<CFSecSecDevicePKey, ICFSecSecDeviceObj> dict;
			if( indexByUserIdx.containsKey( key ) ) {
				dict = indexByUserIdx.get( key );
				int len = dict.size();
				ICFSecSecDeviceObj arr[] = new ICFSecSecDeviceObj[len];
				Iterator<ICFSecSecDeviceObj> valIter = dict.values().iterator();
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
		}
		else {
			ICFSecSecDeviceObj obj;
			Iterator<ICFSecSecDeviceObj> valIter = members.values().iterator();
			while( valIter.hasNext() ) {
				obj = valIter.next();
				if( obj != null ) {
					if( obj.getBuff().compareTo( key ) == 0 ) {
						arrayList.add( obj );
					}
				}
			}
		}
		Comparator<ICFSecSecDeviceObj> cmp = new Comparator<ICFSecSecDeviceObj>() {
			public int compare( ICFSecSecDeviceObj lhs, ICFSecSecDeviceObj rhs ) {
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
					CFSecSecDevicePKey lhsPKey = lhs.getPKey();
					CFSecSecDevicePKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		return( arrayList );
	}

	public void deepDisposeSecDeviceByIdIdx( UUID SecUserId,
		String DevName )
	{
		ICFSecSecDeviceObj obj = readCachedSecDeviceByIdIdx( SecUserId,
				DevName );
		if( obj != null ) {
			obj.forget();
		}
	}

	public void deepDisposeSecDeviceByNameIdx( UUID SecUserId,
		String DevName )
	{
		ICFSecSecDeviceObj obj = readCachedSecDeviceByNameIdx( SecUserId,
				DevName );
		if( obj != null ) {
			obj.forget();
		}
	}

	public void deepDisposeSecDeviceByUserIdx( UUID SecUserId )
	{
		final String S_ProcName = "deepDisposeSecDeviceByUserIdx";
		ICFSecSecDeviceObj obj;
		List<ICFSecSecDeviceObj> arrayList = readCachedSecDeviceByUserIdx( SecUserId );
		if( arrayList != null )  {
			Iterator<ICFSecSecDeviceObj> arrayIter = arrayList.iterator();
			while( arrayIter.hasNext() ) {
				obj = arrayIter.next();
				if( obj != null ) {
					obj.forget();
				}
			}
		}
	}

	/**
	 *	Read a page of data as a List of SecDevice-derived instances sorted by their primary keys,
	 *	as identified by the duplicate UserIdx key attributes.
	 *
	 *	@param	argSecUserId	The SecDevice key attribute of the instance generating the id.
	 *
	 *	@return	A List of SecDevice-derived instances sorted by their primary keys,
	 *		as identified by the key attributes, which may be an empty set.
	 */
	public List<ICFSecSecDeviceObj> pageSecDeviceByUserIdx( UUID SecUserId,
		UUID priorSecUserId,
		String priorDevName )
	{
		final String S_ProcName = "pageSecDeviceByUserIdx";
		CFSecSecDeviceByUserIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactorySecDevice().newUserIdxKey();
		key.setRequiredSecUserId( SecUserId );
		List<ICFSecSecDeviceObj> retList = new LinkedList<ICFSecSecDeviceObj>();
		ICFSecSecDeviceObj obj;
		CFSecSecDeviceBuff[] buffList = ((ICFSecSchema)schema.getBackingStore()).getTableSecDevice().pageBuffByUserIdx( schema.getAuthorization(),
				SecUserId,
			priorSecUserId,
			priorDevName );
		CFSecSecDeviceBuff buff;
		for( int idx = 0; idx < buffList.length; idx ++ ) {
			buff = buffList[ idx ];
				obj = schema.getSecDeviceTableObj().newInstance();
			obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactorySecDevice().newPKey() );
			obj.setBuff( buff );
			ICFSecSecDeviceObj realised = (ICFSecSecDeviceObj)obj.realise();
			retList.add( realised );
		}
		return( retList );
	}

	public ICFSecSecDeviceObj updateSecDevice( ICFSecSecDeviceObj Obj ) {
		ICFSecSecDeviceObj obj = Obj;
		((ICFSecSchema)schema.getBackingStore()).getTableSecDevice().updateSecDevice( schema.getAuthorization(),
			Obj.getSecDeviceBuff() );
		obj = (ICFSecSecDeviceObj)Obj.realise();
		obj.endEdit();
		return( obj );
	}

	public void deleteSecDevice( ICFSecSecDeviceObj Obj ) {
		ICFSecSecDeviceObj obj = Obj;
		((ICFSecSchema)schema.getBackingStore()).getTableSecDevice().deleteSecDevice( schema.getAuthorization(),
			obj.getSecDeviceBuff() );
		Obj.forget();
	}

	public void deleteSecDeviceByIdIdx( UUID SecUserId,
		String DevName )
	{
		CFSecSecDevicePKey pkey = ((ICFSecSchema)schema.getBackingStore()).getFactorySecDevice().newPKey();
		pkey.setRequiredSecUserId( SecUserId );
		pkey.setRequiredDevName( DevName );
		ICFSecSecDeviceObj obj = readSecDevice( pkey );
		if( obj != null ) {
			ICFSecSecDeviceEditObj editObj = (ICFSecSecDeviceEditObj)obj.getEdit();
			boolean editStarted;
			if( editObj == null ) {
				editObj = (ICFSecSecDeviceEditObj)obj.beginEdit();
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
		deepDisposeSecDeviceByIdIdx( SecUserId,
				DevName );
	}

	public void deleteSecDeviceByNameIdx( UUID SecUserId,
		String DevName )
	{
		if( indexByNameIdx == null ) {
			indexByNameIdx = new HashMap< CFSecSecDeviceByNameIdxKey,
				ICFSecSecDeviceObj >();
		}
		CFSecSecDeviceByNameIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactorySecDevice().newNameIdxKey();
		key.setRequiredSecUserId( SecUserId );
		key.setRequiredDevName( DevName );
		ICFSecSecDeviceObj obj = null;
		if( indexByNameIdx.containsKey( key ) ) {
			obj = indexByNameIdx.get( key );
			((ICFSecSchema)schema.getBackingStore()).getTableSecDevice().deleteSecDeviceByNameIdx( schema.getAuthorization(),
				SecUserId,
				DevName );
			obj.forget();
		}
		else {
			((ICFSecSchema)schema.getBackingStore()).getTableSecDevice().deleteSecDeviceByNameIdx( schema.getAuthorization(),
				SecUserId,
				DevName );
		}
		deepDisposeSecDeviceByNameIdx( SecUserId,
				DevName );
	}

	public void deleteSecDeviceByUserIdx( UUID SecUserId )
	{
		CFSecSecDeviceByUserIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactorySecDevice().newUserIdxKey();
		key.setRequiredSecUserId( SecUserId );
		if( indexByUserIdx == null ) {
			indexByUserIdx = new HashMap< CFSecSecDeviceByUserIdxKey,
				Map< CFSecSecDevicePKey, ICFSecSecDeviceObj > >();
		}
		if( indexByUserIdx.containsKey( key ) ) {
			Map<CFSecSecDevicePKey, ICFSecSecDeviceObj> dict = indexByUserIdx.get( key );
			((ICFSecSchema)schema.getBackingStore()).getTableSecDevice().deleteSecDeviceByUserIdx( schema.getAuthorization(),
				SecUserId );
			Iterator<ICFSecSecDeviceObj> iter = dict.values().iterator();
			ICFSecSecDeviceObj obj;
			List<ICFSecSecDeviceObj> toForget = new LinkedList<ICFSecSecDeviceObj>();
			while( iter.hasNext() ) {
				obj = iter.next();
				toForget.add( obj );
			}
			iter = toForget.iterator();
			while( iter.hasNext() ) {
				obj = iter.next();
				obj.forget();
			}
			indexByUserIdx.remove( key );
		}
		else {
			((ICFSecSchema)schema.getBackingStore()).getTableSecDevice().deleteSecDeviceByUserIdx( schema.getAuthorization(),
				SecUserId );
		}
		deepDisposeSecDeviceByUserIdx( SecUserId );
	}
}