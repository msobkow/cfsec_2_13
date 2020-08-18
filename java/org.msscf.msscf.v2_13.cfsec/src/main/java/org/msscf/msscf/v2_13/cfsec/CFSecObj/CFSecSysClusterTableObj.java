// Description: Java 11 Table Object implementation for CFSec.

/*
 *	org.msscf.msscf.CFSec
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFSec 2.13 Security Essentials
 *	
 *	Copyright 2020 Mark Stephen Sobkow
 *	
 *		This file is part of MSS Code Factory.
 *	
 *		MSS Code Factory is available under dual commercial license from Mark Stephen
 *		Sobkow, or under the terms of the GNU General Public License, Version 3
 *		or later.
 *	
 *	    MSS Code Factory is free software: you can redistribute it and/or modify
 *	    it under the terms of the GNU General Public License as published by
 *	    the Free Software Foundation, either version 3 of the License, or
 *	    (at your option) any later version.
 *	
 *	    MSS Code Factory is distributed in the hope that it will be useful,
 *	    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	    GNU General Public License for more details.
 *	
 *	    You should have received a copy of the GNU General Public License
 *	    along with MSS Code Factory.  If not, see <https://www.gnu.org/licenses/>.
 *	
 *	Donations to support MSS Code Factory can be made at
 *	https://www.paypal.com/paypalme2/MarkSobkow
 *	
 *	Please contact Mark Stephen Sobkow at msobkow@sasktel.net for commercial licensing.
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

public class CFSecSysClusterTableObj
	implements ICFSecSysClusterTableObj
{
	protected ICFSecSchemaObj schema;
	private Map<CFSecSysClusterPKey, ICFSecSysClusterObj> members;
	private Map<CFSecSysClusterPKey, ICFSecSysClusterObj> allSysCluster;
	private Map< CFSecSysClusterByClusterIdxKey,
		Map<CFSecSysClusterPKey, ICFSecSysClusterObj > > indexByClusterIdx;
	public static String TABLE_NAME = "SysCluster";
	public static String TABLE_DBNAME = "sysclus";

	public CFSecSysClusterTableObj() {
		schema = null;
		members = new HashMap<CFSecSysClusterPKey, ICFSecSysClusterObj>();
		allSysCluster = null;
		indexByClusterIdx = null;
	}

	public CFSecSysClusterTableObj( ICFSecSchemaObj argSchema ) {
		schema = (ICFSecSchemaObj)argSchema;
		members = new HashMap<CFSecSysClusterPKey, ICFSecSysClusterObj>();
		allSysCluster = null;
		indexByClusterIdx = null;
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
		allSysCluster = null;
		indexByClusterIdx = null;
		List<ICFSecSysClusterObj> toForget = new LinkedList<ICFSecSysClusterObj>();
		ICFSecSysClusterObj cur = null;
		Iterator<ICFSecSysClusterObj> iter = members.values().iterator();
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
	 *	CFSecSysClusterObj.
	 */
	public ICFSecSysClusterObj newInstance() {
		ICFSecSysClusterObj inst = new CFSecSysClusterObj( schema );
		return( inst );
	}

	/**
	 *	If your implementation subclasses the objects,
	 *	you'll want to overload the constructByClassCode()
	 *	implementation to return your implementation's
	 *	instances instead of the base implementation.
	 *
	 *	This is the sole factory for instances derived from
	 *	CFSecSysClusterObj.
	 */
	public ICFSecSysClusterEditObj newEditInstance( ICFSecSysClusterObj orig ) {
		ICFSecSysClusterEditObj edit = new CFSecSysClusterEditObj( orig );
		return( edit );
	}

	public ICFSecSysClusterObj realiseSysCluster( ICFSecSysClusterObj Obj ) {
		ICFSecSysClusterObj obj = Obj;
		CFSecSysClusterPKey pkey = obj.getPKey();
		ICFSecSysClusterObj keepObj = null;
		if( members.containsKey( pkey ) && ( null != members.get( pkey ) ) ) {
			ICFSecSysClusterObj existingObj = members.get( pkey );
			keepObj = existingObj;

			/*
			 *	We always rebind the data because if we're being called, some index has
			 *	been updated and is refreshing it's data, which may or may not have changed
			 */

			// Detach object from alternate and duplicate indexes, leave PKey alone

			if( indexByClusterIdx != null ) {
				CFSecSysClusterByClusterIdxKey keyClusterIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactorySysCluster().newClusterIdxKey();
				keyClusterIdx.setRequiredClusterId( keepObj.getRequiredClusterId() );
				Map<CFSecSysClusterPKey, ICFSecSysClusterObj > mapClusterIdx = indexByClusterIdx.get( keyClusterIdx );
				if( mapClusterIdx != null ) {
					mapClusterIdx.remove( keepObj.getPKey() );
					if( mapClusterIdx.size() <= 0 ) {
						indexByClusterIdx.remove( keyClusterIdx );
					}
				}
			}

			keepObj.setBuff( Obj.getBuff() );
			// Attach new object to alternate and duplicate indexes -- PKey stay stable

			if( indexByClusterIdx != null ) {
				CFSecSysClusterByClusterIdxKey keyClusterIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactorySysCluster().newClusterIdxKey();
				keyClusterIdx.setRequiredClusterId( keepObj.getRequiredClusterId() );
				Map<CFSecSysClusterPKey, ICFSecSysClusterObj > mapClusterIdx = indexByClusterIdx.get( keyClusterIdx );
				if( mapClusterIdx != null ) {
					mapClusterIdx.put( keepObj.getPKey(), keepObj );
				}
			}

			if( allSysCluster != null ) {
				allSysCluster.put( keepObj.getPKey(), keepObj );
			}
		}
		else {
			keepObj = obj;
			keepObj.setIsNew( false );

			// Attach new object to PKey, all, alternate, and duplicate indexes
			members.put( keepObj.getPKey(), keepObj );
			if( allSysCluster != null ) {
				allSysCluster.put( keepObj.getPKey(), keepObj );
			}

			if( indexByClusterIdx != null ) {
				CFSecSysClusterByClusterIdxKey keyClusterIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactorySysCluster().newClusterIdxKey();
				keyClusterIdx.setRequiredClusterId( keepObj.getRequiredClusterId() );
				Map<CFSecSysClusterPKey, ICFSecSysClusterObj > mapClusterIdx = indexByClusterIdx.get( keyClusterIdx );
				if( mapClusterIdx != null ) {
					mapClusterIdx.put( keepObj.getPKey(), keepObj );
				}
			}

		}
		return( keepObj );
	}

	public ICFSecSysClusterObj createSysCluster( ICFSecSysClusterObj Obj ) {
		ICFSecSysClusterObj obj = Obj;
		CFSecSysClusterBuff buff = obj.getSysClusterBuff();
		((ICFSecSchema)schema.getBackingStore()).getTableSysCluster().createSysCluster(
			schema.getAuthorization(),
			buff );
		obj.copyBuffToPKey();
		obj = obj.realise();
		obj.endEdit();
		return( obj );
	}

	public ICFSecSysClusterObj readSysCluster( CFSecSysClusterPKey pkey ) {
		return( readSysCluster( pkey, false ) );
	}

	public ICFSecSysClusterObj readSysCluster( CFSecSysClusterPKey pkey, boolean forceRead ) {
		ICFSecSysClusterObj obj = null;
		if( ( ! forceRead ) && members.containsKey( pkey ) ) {
			obj = members.get( pkey );
		}
		else {
			CFSecSysClusterBuff readBuff = ((ICFSecSchema)schema.getBackingStore()).getTableSysCluster().readDerivedByIdIdx( schema.getAuthorization(),
				pkey.getRequiredSingletonId() );
			if( readBuff != null ) {
				obj = schema.getSysClusterTableObj().newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactorySysCluster().newPKey() );
				obj.setBuff( readBuff );
				obj = (ICFSecSysClusterObj)obj.realise();
			}
		}
		return( obj );
	}

	public ICFSecSysClusterObj readCachedSysCluster( CFSecSysClusterPKey pkey ) {
		ICFSecSysClusterObj obj = null;
		if( members.containsKey( pkey ) ) {
			obj = members.get( pkey );
		}
		return( obj );
	}

	public void reallyDeepDisposeSysCluster( ICFSecSysClusterObj obj )
	{
		final String S_ProcName = "CFSecSysClusterTableObj.reallyDeepDisposeSysCluster() ";
		String classCode;
		if( obj == null ) {
			return;
		}
		CFSecSysClusterPKey pkey = obj.getPKey();
		ICFSecSysClusterObj existing = readCachedSysCluster( pkey );
		if( existing == null ) {
			return;
		}
		members.remove( pkey );
		CFSecSysClusterByClusterIdxKey keyClusterIdx = ((ICFSecSchema)schema.getBackingStore()).getFactorySysCluster().newClusterIdxKey();
		keyClusterIdx.setRequiredClusterId( existing.getRequiredClusterId() );



		if( indexByClusterIdx != null ) {
			if( indexByClusterIdx.containsKey( keyClusterIdx ) ) {
				indexByClusterIdx.get( keyClusterIdx ).remove( pkey );
				if( indexByClusterIdx.get( keyClusterIdx ).size() <= 0 ) {
					indexByClusterIdx.remove( keyClusterIdx );
				}
			}
		}


	}
	public void deepDisposeSysCluster( CFSecSysClusterPKey pkey ) {
		ICFSecSysClusterObj obj = readCachedSysCluster( pkey );
		if( obj != null ) {
			obj.forget();
		}
	}

	public ICFSecSysClusterObj lockSysCluster( CFSecSysClusterPKey pkey ) {
		ICFSecSysClusterObj locked = null;
		CFSecSysClusterBuff lockBuff = ((ICFSecSchema)schema.getBackingStore()).getTableSysCluster().lockDerived( schema.getAuthorization(), pkey );
		if( lockBuff != null ) {
				locked = schema.getSysClusterTableObj().newInstance();
			locked.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactorySysCluster().newPKey() );
			locked.setBuff( lockBuff );
			locked = (ICFSecSysClusterObj)locked.realise();
		}
		else {
			throw new CFLibCollisionDetectedException( getClass(), "lockSysCluster", pkey );
		}
		return( locked );
	}

	public List<ICFSecSysClusterObj> readAllSysCluster() {
		return( readAllSysCluster( false ) );
	}

	public List<ICFSecSysClusterObj> readAllSysCluster( boolean forceRead ) {
		final String S_ProcName = "readAllSysCluster";
		if( ( allSysCluster == null ) || forceRead ) {
			Map<CFSecSysClusterPKey, ICFSecSysClusterObj> map = new HashMap<CFSecSysClusterPKey,ICFSecSysClusterObj>();
			allSysCluster = map;
			CFSecSysClusterBuff[] buffList = ((ICFSecSchema)schema.getBackingStore()).getTableSysCluster().readAllDerived( schema.getAuthorization() );
			CFSecSysClusterBuff buff;
			ICFSecSysClusterObj obj;
			for( int idx = 0; idx < buffList.length; idx ++ ) {
				buff = buffList[ idx ];
				obj = newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactorySysCluster().newPKey() );
				obj.setBuff( buff );
				ICFSecSysClusterObj realised = (ICFSecSysClusterObj)obj.realise();
			}
		}
		int len = allSysCluster.size();
		ICFSecSysClusterObj arr[] = new ICFSecSysClusterObj[len];
		Iterator<ICFSecSysClusterObj> valIter = allSysCluster.values().iterator();
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
		ArrayList<ICFSecSysClusterObj> arrayList = new ArrayList<ICFSecSysClusterObj>(len);
		for( idx = 0; idx < len; idx ++ ) {
			arrayList.add( arr[idx] );
		}

		Comparator<ICFSecSysClusterObj> cmp = new Comparator<ICFSecSysClusterObj>() {
			public int compare( ICFSecSysClusterObj lhs, ICFSecSysClusterObj rhs ) {
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
					CFSecSysClusterPKey lhsPKey = lhs.getPKey();
					CFSecSysClusterPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		List<ICFSecSysClusterObj> sortedList = arrayList;
		return( sortedList );
	}

	public List<ICFSecSysClusterObj> readCachedAllSysCluster() {
		final String S_ProcName = "readCachedAllSysCluster";
		ArrayList<ICFSecSysClusterObj> arrayList = new ArrayList<ICFSecSysClusterObj>();
		if( allSysCluster != null ) {
			int len = allSysCluster.size();
			ICFSecSysClusterObj arr[] = new ICFSecSysClusterObj[len];
			Iterator<ICFSecSysClusterObj> valIter = allSysCluster.values().iterator();
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
		Comparator<ICFSecSysClusterObj> cmp = new Comparator<ICFSecSysClusterObj>() {
			public int compare( ICFSecSysClusterObj lhs, ICFSecSysClusterObj rhs ) {
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
					CFSecSysClusterPKey lhsPKey = lhs.getPKey();
					CFSecSysClusterPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		return( arrayList );
	}

	public ICFSecSysClusterObj readSysClusterByIdIdx( int SingletonId )
	{
		return( readSysClusterByIdIdx( SingletonId,
			false ) );
	}

	public ICFSecSysClusterObj readSysClusterByIdIdx( int SingletonId, boolean forceRead )
	{
		CFSecSysClusterPKey pkey = ((ICFSecSchema)schema.getBackingStore()).getFactorySysCluster().newPKey();
		pkey.setRequiredSingletonId( SingletonId );
		ICFSecSysClusterObj obj = readSysCluster( pkey, forceRead );
		return( obj );
	}

	public List<ICFSecSysClusterObj> readSysClusterByClusterIdx( long ClusterId )
	{
		return( readSysClusterByClusterIdx( ClusterId,
			false ) );
	}

	public List<ICFSecSysClusterObj> readSysClusterByClusterIdx( long ClusterId,
		boolean forceRead )
	{
		final String S_ProcName = "readSysClusterByClusterIdx";
		CFSecSysClusterByClusterIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactorySysCluster().newClusterIdxKey();
		key.setRequiredClusterId( ClusterId );
		Map<CFSecSysClusterPKey, ICFSecSysClusterObj> dict;
		if( indexByClusterIdx == null ) {
			indexByClusterIdx = new HashMap< CFSecSysClusterByClusterIdxKey,
				Map< CFSecSysClusterPKey, ICFSecSysClusterObj > >();
		}
		if( ( ! forceRead ) && indexByClusterIdx.containsKey( key ) ) {
			dict = indexByClusterIdx.get( key );
		}
		else {
			dict = new HashMap<CFSecSysClusterPKey, ICFSecSysClusterObj>();
			ICFSecSysClusterObj obj;
			CFSecSysClusterBuff[] buffList = ((ICFSecSchema)schema.getBackingStore()).getTableSysCluster().readDerivedByClusterIdx( schema.getAuthorization(),
				ClusterId );
			CFSecSysClusterBuff buff;
			for( int idx = 0; idx < buffList.length; idx ++ ) {
				buff = buffList[ idx ];
				obj = schema.getSysClusterTableObj().newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactorySysCluster().newPKey() );
				obj.setBuff( buff );
				ICFSecSysClusterObj realised = (ICFSecSysClusterObj)obj.realise();
				dict.put( realised.getPKey(), realised );
			}
			indexByClusterIdx.put( key, dict );
		}
		int len = dict.size();
		ICFSecSysClusterObj arr[] = new ICFSecSysClusterObj[len];
		Iterator<ICFSecSysClusterObj> valIter = dict.values().iterator();
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
		ArrayList<ICFSecSysClusterObj> arrayList = new ArrayList<ICFSecSysClusterObj>(len);
		for( idx = 0; idx < len; idx ++ ) {
			arrayList.add( arr[idx] );
		}

		Comparator<ICFSecSysClusterObj> cmp = new Comparator<ICFSecSysClusterObj>() {
			public int compare( ICFSecSysClusterObj lhs, ICFSecSysClusterObj rhs ) {
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
					CFSecSysClusterPKey lhsPKey = lhs.getPKey();
					CFSecSysClusterPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		List<ICFSecSysClusterObj> sortedList = arrayList;
		return( sortedList );
	}

	public ICFSecSysClusterObj readCachedSysClusterByIdIdx( int SingletonId )
	{
		ICFSecSysClusterObj obj = null;
		CFSecSysClusterPKey pkey = ((ICFSecSchema)schema.getBackingStore()).getFactorySysCluster().newPKey();
		pkey.setRequiredSingletonId( SingletonId );
		obj = readCachedSysCluster( pkey );
		return( obj );
	}

	public List<ICFSecSysClusterObj> readCachedSysClusterByClusterIdx( long ClusterId )
	{
		final String S_ProcName = "readCachedSysClusterByClusterIdx";
		CFSecSysClusterByClusterIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactorySysCluster().newClusterIdxKey();
		key.setRequiredClusterId( ClusterId );
		ArrayList<ICFSecSysClusterObj> arrayList = new ArrayList<ICFSecSysClusterObj>();
		if( indexByClusterIdx != null ) {
			Map<CFSecSysClusterPKey, ICFSecSysClusterObj> dict;
			if( indexByClusterIdx.containsKey( key ) ) {
				dict = indexByClusterIdx.get( key );
				int len = dict.size();
				ICFSecSysClusterObj arr[] = new ICFSecSysClusterObj[len];
				Iterator<ICFSecSysClusterObj> valIter = dict.values().iterator();
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
			ICFSecSysClusterObj obj;
			Iterator<ICFSecSysClusterObj> valIter = members.values().iterator();
			while( valIter.hasNext() ) {
				obj = valIter.next();
				if( obj != null ) {
					if( obj.getBuff().compareTo( key ) == 0 ) {
						arrayList.add( obj );
					}
				}
			}
		}
		Comparator<ICFSecSysClusterObj> cmp = new Comparator<ICFSecSysClusterObj>() {
			public int compare( ICFSecSysClusterObj lhs, ICFSecSysClusterObj rhs ) {
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
					CFSecSysClusterPKey lhsPKey = lhs.getPKey();
					CFSecSysClusterPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		return( arrayList );
	}

	public void deepDisposeSysClusterByIdIdx( int SingletonId )
	{
		ICFSecSysClusterObj obj = readCachedSysClusterByIdIdx( SingletonId );
		if( obj != null ) {
			obj.forget();
		}
	}

	public void deepDisposeSysClusterByClusterIdx( long ClusterId )
	{
		final String S_ProcName = "deepDisposeSysClusterByClusterIdx";
		ICFSecSysClusterObj obj;
		List<ICFSecSysClusterObj> arrayList = readCachedSysClusterByClusterIdx( ClusterId );
		if( arrayList != null )  {
			Iterator<ICFSecSysClusterObj> arrayIter = arrayList.iterator();
			while( arrayIter.hasNext() ) {
				obj = arrayIter.next();
				if( obj != null ) {
					obj.forget();
				}
			}
		}
	}

	public ICFSecSysClusterObj updateSysCluster( ICFSecSysClusterObj Obj ) {
		ICFSecSysClusterObj obj = Obj;
		((ICFSecSchema)schema.getBackingStore()).getTableSysCluster().updateSysCluster( schema.getAuthorization(),
			Obj.getSysClusterBuff() );
		obj = (ICFSecSysClusterObj)Obj.realise();
		obj.endEdit();
		return( obj );
	}

	public void deleteSysCluster( ICFSecSysClusterObj Obj ) {
		ICFSecSysClusterObj obj = Obj;
		((ICFSecSchema)schema.getBackingStore()).getTableSysCluster().deleteSysCluster( schema.getAuthorization(),
			obj.getSysClusterBuff() );
		Obj.forget();
	}

	public void deleteSysClusterByIdIdx( int SingletonId )
	{
		CFSecSysClusterPKey pkey = ((ICFSecSchema)schema.getBackingStore()).getFactorySysCluster().newPKey();
		pkey.setRequiredSingletonId( SingletonId );
		ICFSecSysClusterObj obj = readSysCluster( pkey );
		if( obj != null ) {
			ICFSecSysClusterEditObj editObj = (ICFSecSysClusterEditObj)obj.getEdit();
			boolean editStarted;
			if( editObj == null ) {
				editObj = (ICFSecSysClusterEditObj)obj.beginEdit();
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
		deepDisposeSysClusterByIdIdx( SingletonId );
	}

	public void deleteSysClusterByClusterIdx( long ClusterId )
	{
		CFSecSysClusterByClusterIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactorySysCluster().newClusterIdxKey();
		key.setRequiredClusterId( ClusterId );
		if( indexByClusterIdx == null ) {
			indexByClusterIdx = new HashMap< CFSecSysClusterByClusterIdxKey,
				Map< CFSecSysClusterPKey, ICFSecSysClusterObj > >();
		}
		if( indexByClusterIdx.containsKey( key ) ) {
			Map<CFSecSysClusterPKey, ICFSecSysClusterObj> dict = indexByClusterIdx.get( key );
			((ICFSecSchema)schema.getBackingStore()).getTableSysCluster().deleteSysClusterByClusterIdx( schema.getAuthorization(),
				ClusterId );
			Iterator<ICFSecSysClusterObj> iter = dict.values().iterator();
			ICFSecSysClusterObj obj;
			List<ICFSecSysClusterObj> toForget = new LinkedList<ICFSecSysClusterObj>();
			while( iter.hasNext() ) {
				obj = iter.next();
				toForget.add( obj );
			}
			iter = toForget.iterator();
			while( iter.hasNext() ) {
				obj = iter.next();
				obj.forget();
			}
			indexByClusterIdx.remove( key );
		}
		else {
			((ICFSecSchema)schema.getBackingStore()).getTableSysCluster().deleteSysClusterByClusterIdx( schema.getAuthorization(),
				ClusterId );
		}
		deepDisposeSysClusterByClusterIdx( ClusterId );
	}
}