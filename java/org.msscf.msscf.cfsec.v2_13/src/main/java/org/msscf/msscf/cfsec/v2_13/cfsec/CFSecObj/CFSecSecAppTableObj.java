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

package org.msscf.msscf.cfsec.v2_13.cfsec.CFSecObj;

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.msscf.msscf.cflib.v2_13.CFLib.*;
import org.msscf.msscf.cfsec.CFSec.*;

public class CFSecSecAppTableObj
	implements ICFSecSecAppTableObj
{
	protected ICFSecSchemaObj schema;
	private Map<CFSecSecAppPKey, ICFSecSecAppObj> members;
	private Map<CFSecSecAppPKey, ICFSecSecAppObj> allSecApp;
	private Map< CFSecSecAppByClusterIdxKey,
		Map<CFSecSecAppPKey, ICFSecSecAppObj > > indexByClusterIdx;
	private Map< CFSecSecAppByUJEEMountIdxKey,
		ICFSecSecAppObj > indexByUJEEMountIdx;
	public static String TABLE_NAME = "SecApp";
	public static String TABLE_DBNAME = "secapp";

	public CFSecSecAppTableObj() {
		schema = null;
		members = new HashMap<CFSecSecAppPKey, ICFSecSecAppObj>();
		allSecApp = null;
		indexByClusterIdx = null;
		indexByUJEEMountIdx = null;
	}

	public CFSecSecAppTableObj( ICFSecSchemaObj argSchema ) {
		schema = (ICFSecSchemaObj)argSchema;
		members = new HashMap<CFSecSecAppPKey, ICFSecSecAppObj>();
		allSecApp = null;
		indexByClusterIdx = null;
		indexByUJEEMountIdx = null;
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
		allSecApp = null;
		indexByClusterIdx = null;
		indexByUJEEMountIdx = null;
		List<ICFSecSecAppObj> toForget = new LinkedList<ICFSecSecAppObj>();
		ICFSecSecAppObj cur = null;
		Iterator<ICFSecSecAppObj> iter = members.values().iterator();
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
	 *	CFSecSecAppObj.
	 */
	public ICFSecSecAppObj newInstance() {
		ICFSecSecAppObj inst = new CFSecSecAppObj( schema );
		return( inst );
	}

	/**
	 *	If your implementation subclasses the objects,
	 *	you'll want to overload the constructByClassCode()
	 *	implementation to return your implementation's
	 *	instances instead of the base implementation.
	 *
	 *	This is the sole factory for instances derived from
	 *	CFSecSecAppObj.
	 */
	public ICFSecSecAppEditObj newEditInstance( ICFSecSecAppObj orig ) {
		ICFSecSecAppEditObj edit = new CFSecSecAppEditObj( orig );
		return( edit );
	}

	public ICFSecSecAppObj realiseSecApp( ICFSecSecAppObj Obj ) {
		ICFSecSecAppObj obj = Obj;
		CFSecSecAppPKey pkey = obj.getPKey();
		ICFSecSecAppObj keepObj = null;
		if( members.containsKey( pkey ) && ( null != members.get( pkey ) ) ) {
			ICFSecSecAppObj existingObj = members.get( pkey );
			keepObj = existingObj;

			/*
			 *	We always rebind the data because if we're being called, some index has
			 *	been updated and is refreshing it's data, which may or may not have changed
			 */

			// Detach object from alternate and duplicate indexes, leave PKey alone

			if( indexByClusterIdx != null ) {
				CFSecSecAppByClusterIdxKey keyClusterIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactorySecApp().newClusterIdxKey();
				keyClusterIdx.setRequiredClusterId( keepObj.getRequiredClusterId() );
				Map<CFSecSecAppPKey, ICFSecSecAppObj > mapClusterIdx = indexByClusterIdx.get( keyClusterIdx );
				if( mapClusterIdx != null ) {
					mapClusterIdx.remove( keepObj.getPKey() );
					if( mapClusterIdx.size() <= 0 ) {
						indexByClusterIdx.remove( keyClusterIdx );
					}
				}
			}

			if( indexByUJEEMountIdx != null ) {
				CFSecSecAppByUJEEMountIdxKey keyUJEEMountIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactorySecApp().newUJEEMountIdxKey();
				keyUJEEMountIdx.setRequiredClusterId( keepObj.getRequiredClusterId() );
				keyUJEEMountIdx.setRequiredJEEMountName( keepObj.getRequiredJEEMountName() );
				indexByUJEEMountIdx.remove( keyUJEEMountIdx );
			}

			keepObj.setBuff( Obj.getBuff() );
			// Attach new object to alternate and duplicate indexes -- PKey stay stable

			if( indexByClusterIdx != null ) {
				CFSecSecAppByClusterIdxKey keyClusterIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactorySecApp().newClusterIdxKey();
				keyClusterIdx.setRequiredClusterId( keepObj.getRequiredClusterId() );
				Map<CFSecSecAppPKey, ICFSecSecAppObj > mapClusterIdx = indexByClusterIdx.get( keyClusterIdx );
				if( mapClusterIdx != null ) {
					mapClusterIdx.put( keepObj.getPKey(), keepObj );
				}
			}

			if( indexByUJEEMountIdx != null ) {
				CFSecSecAppByUJEEMountIdxKey keyUJEEMountIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactorySecApp().newUJEEMountIdxKey();
				keyUJEEMountIdx.setRequiredClusterId( keepObj.getRequiredClusterId() );
				keyUJEEMountIdx.setRequiredJEEMountName( keepObj.getRequiredJEEMountName() );
				indexByUJEEMountIdx.put( keyUJEEMountIdx, keepObj );
			}

			if( allSecApp != null ) {
				allSecApp.put( keepObj.getPKey(), keepObj );
			}
		}
		else {
			keepObj = obj;
			keepObj.setIsNew( false );

			// Attach new object to PKey, all, alternate, and duplicate indexes
			members.put( keepObj.getPKey(), keepObj );
			if( allSecApp != null ) {
				allSecApp.put( keepObj.getPKey(), keepObj );
			}

			if( indexByClusterIdx != null ) {
				CFSecSecAppByClusterIdxKey keyClusterIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactorySecApp().newClusterIdxKey();
				keyClusterIdx.setRequiredClusterId( keepObj.getRequiredClusterId() );
				Map<CFSecSecAppPKey, ICFSecSecAppObj > mapClusterIdx = indexByClusterIdx.get( keyClusterIdx );
				if( mapClusterIdx != null ) {
					mapClusterIdx.put( keepObj.getPKey(), keepObj );
				}
			}

			if( indexByUJEEMountIdx != null ) {
				CFSecSecAppByUJEEMountIdxKey keyUJEEMountIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactorySecApp().newUJEEMountIdxKey();
				keyUJEEMountIdx.setRequiredClusterId( keepObj.getRequiredClusterId() );
				keyUJEEMountIdx.setRequiredJEEMountName( keepObj.getRequiredJEEMountName() );
				indexByUJEEMountIdx.put( keyUJEEMountIdx, keepObj );
			}

		}
		return( keepObj );
	}

	public ICFSecSecAppObj createSecApp( ICFSecSecAppObj Obj ) {
		ICFSecSecAppObj obj = Obj;
		CFSecSecAppBuff buff = obj.getSecAppBuff();
		((ICFSecSchema)schema.getBackingStore()).getTableSecApp().createSecApp(
			schema.getAuthorization(),
			buff );
		obj.copyBuffToPKey();
		obj = obj.realise();
		obj.endEdit();
		return( obj );
	}

	public ICFSecSecAppObj readSecApp( CFSecSecAppPKey pkey ) {
		return( readSecApp( pkey, false ) );
	}

	public ICFSecSecAppObj readSecApp( CFSecSecAppPKey pkey, boolean forceRead ) {
		ICFSecSecAppObj obj = null;
		if( ( ! forceRead ) && members.containsKey( pkey ) ) {
			obj = members.get( pkey );
		}
		else {
			CFSecSecAppBuff readBuff = ((ICFSecSchema)schema.getBackingStore()).getTableSecApp().readDerivedByIdIdx( schema.getAuthorization(),
				pkey.getRequiredClusterId(),
				pkey.getRequiredSecAppId() );
			if( readBuff != null ) {
				obj = schema.getSecAppTableObj().newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactorySecApp().newPKey() );
				obj.setBuff( readBuff );
				obj = (ICFSecSecAppObj)obj.realise();
			}
		}
		return( obj );
	}

	public ICFSecSecAppObj readCachedSecApp( CFSecSecAppPKey pkey ) {
		ICFSecSecAppObj obj = null;
		if( members.containsKey( pkey ) ) {
			obj = members.get( pkey );
		}
		return( obj );
	}

	public void reallyDeepDisposeSecApp( ICFSecSecAppObj obj )
	{
		final String S_ProcName = "CFSecSecAppTableObj.reallyDeepDisposeSecApp() ";
		String classCode;
		if( obj == null ) {
			return;
		}
		CFSecSecAppPKey pkey = obj.getPKey();
		ICFSecSecAppObj existing = readCachedSecApp( pkey );
		if( existing == null ) {
			return;
		}
		members.remove( pkey );
		CFSecSecAppByClusterIdxKey keyClusterIdx = ((ICFSecSchema)schema.getBackingStore()).getFactorySecApp().newClusterIdxKey();
		keyClusterIdx.setRequiredClusterId( existing.getRequiredClusterId() );

		CFSecSecAppByUJEEMountIdxKey keyUJEEMountIdx = ((ICFSecSchema)schema.getBackingStore()).getFactorySecApp().newUJEEMountIdxKey();
		keyUJEEMountIdx.setRequiredClusterId( existing.getRequiredClusterId() );
		keyUJEEMountIdx.setRequiredJEEMountName( existing.getRequiredJEEMountName() );


					schema.getSecFormTableObj().deepDisposeSecFormBySecAppIdx( existing.getRequiredClusterId(),
						existing.getRequiredSecAppId() );

		if( indexByClusterIdx != null ) {
			if( indexByClusterIdx.containsKey( keyClusterIdx ) ) {
				indexByClusterIdx.get( keyClusterIdx ).remove( pkey );
				if( indexByClusterIdx.get( keyClusterIdx ).size() <= 0 ) {
					indexByClusterIdx.remove( keyClusterIdx );
				}
			}
		}

		if( indexByUJEEMountIdx != null ) {
			indexByUJEEMountIdx.remove( keyUJEEMountIdx );
		}


	}
	public void deepDisposeSecApp( CFSecSecAppPKey pkey ) {
		ICFSecSecAppObj obj = readCachedSecApp( pkey );
		if( obj != null ) {
			obj.forget();
		}
	}

	public ICFSecSecAppObj lockSecApp( CFSecSecAppPKey pkey ) {
		ICFSecSecAppObj locked = null;
		CFSecSecAppBuff lockBuff = ((ICFSecSchema)schema.getBackingStore()).getTableSecApp().lockDerived( schema.getAuthorization(), pkey );
		if( lockBuff != null ) {
				locked = schema.getSecAppTableObj().newInstance();
			locked.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactorySecApp().newPKey() );
			locked.setBuff( lockBuff );
			locked = (ICFSecSecAppObj)locked.realise();
		}
		else {
			throw new CFLibCollisionDetectedException( getClass(), "lockSecApp", pkey );
		}
		return( locked );
	}

	public List<ICFSecSecAppObj> readAllSecApp() {
		return( readAllSecApp( false ) );
	}

	public List<ICFSecSecAppObj> readAllSecApp( boolean forceRead ) {
		final String S_ProcName = "readAllSecApp";
		if( ( allSecApp == null ) || forceRead ) {
			Map<CFSecSecAppPKey, ICFSecSecAppObj> map = new HashMap<CFSecSecAppPKey,ICFSecSecAppObj>();
			allSecApp = map;
			CFSecSecAppBuff[] buffList = ((ICFSecSchema)schema.getBackingStore()).getTableSecApp().readAllDerived( schema.getAuthorization() );
			CFSecSecAppBuff buff;
			ICFSecSecAppObj obj;
			for( int idx = 0; idx < buffList.length; idx ++ ) {
				buff = buffList[ idx ];
				obj = newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactorySecApp().newPKey() );
				obj.setBuff( buff );
				ICFSecSecAppObj realised = (ICFSecSecAppObj)obj.realise();
			}
		}
		int len = allSecApp.size();
		ICFSecSecAppObj arr[] = new ICFSecSecAppObj[len];
		Iterator<ICFSecSecAppObj> valIter = allSecApp.values().iterator();
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
		ArrayList<ICFSecSecAppObj> arrayList = new ArrayList<ICFSecSecAppObj>(len);
		for( idx = 0; idx < len; idx ++ ) {
			arrayList.add( arr[idx] );
		}

		Comparator<ICFSecSecAppObj> cmp = new Comparator<ICFSecSecAppObj>() {
			public int compare( ICFSecSecAppObj lhs, ICFSecSecAppObj rhs ) {
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
					CFSecSecAppPKey lhsPKey = lhs.getPKey();
					CFSecSecAppPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		List<ICFSecSecAppObj> sortedList = arrayList;
		return( sortedList );
	}

	public List<ICFSecSecAppObj> readCachedAllSecApp() {
		final String S_ProcName = "readCachedAllSecApp";
		ArrayList<ICFSecSecAppObj> arrayList = new ArrayList<ICFSecSecAppObj>();
		if( allSecApp != null ) {
			int len = allSecApp.size();
			ICFSecSecAppObj arr[] = new ICFSecSecAppObj[len];
			Iterator<ICFSecSecAppObj> valIter = allSecApp.values().iterator();
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
		Comparator<ICFSecSecAppObj> cmp = new Comparator<ICFSecSecAppObj>() {
			public int compare( ICFSecSecAppObj lhs, ICFSecSecAppObj rhs ) {
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
					CFSecSecAppPKey lhsPKey = lhs.getPKey();
					CFSecSecAppPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		return( arrayList );
	}

	/**
	 *	Return a sorted map of a page of the SecApp-derived instances in the database.
	 *
	 *	@return	List of ICFSecSecAppObj instance, sorted by their primary keys, which
	 *		may include an empty set.
	 */
	public List<ICFSecSecAppObj> pageAllSecApp(Long priorClusterId,
		Integer priorSecAppId )
	{
		final String S_ProcName = "pageAllSecApp";
		Map<CFSecSecAppPKey, ICFSecSecAppObj> map = new HashMap<CFSecSecAppPKey,ICFSecSecAppObj>();
		CFSecSecAppBuff[] buffList = ((ICFSecSchema)schema.getBackingStore()).getTableSecApp().pageAllBuff( schema.getAuthorization(),
			priorClusterId,
			priorSecAppId );
		CFSecSecAppBuff buff;
		ICFSecSecAppObj obj;
		ICFSecSecAppObj realised;
		ArrayList<ICFSecSecAppObj> arrayList = new ArrayList<ICFSecSecAppObj>( buffList.length );
		for( int idx = 0; idx < buffList.length; idx ++ ) {
			buff = buffList[ idx ];
				obj = newInstance();
			obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactorySecApp().newPKey() );
			obj.setBuff( buff );
			realised = (ICFSecSecAppObj)obj.realise();
			arrayList.add( realised );
		}
		return( arrayList );
	}

	public ICFSecSecAppObj readSecAppByIdIdx( long ClusterId,
		int SecAppId )
	{
		return( readSecAppByIdIdx( ClusterId,
			SecAppId,
			false ) );
	}

	public ICFSecSecAppObj readSecAppByIdIdx( long ClusterId,
		int SecAppId, boolean forceRead )
	{
		CFSecSecAppPKey pkey = ((ICFSecSchema)schema.getBackingStore()).getFactorySecApp().newPKey();
		pkey.setRequiredClusterId( ClusterId );
		pkey.setRequiredSecAppId( SecAppId );
		ICFSecSecAppObj obj = readSecApp( pkey, forceRead );
		return( obj );
	}

	public List<ICFSecSecAppObj> readSecAppByClusterIdx( long ClusterId )
	{
		return( readSecAppByClusterIdx( ClusterId,
			false ) );
	}

	public List<ICFSecSecAppObj> readSecAppByClusterIdx( long ClusterId,
		boolean forceRead )
	{
		final String S_ProcName = "readSecAppByClusterIdx";
		CFSecSecAppByClusterIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactorySecApp().newClusterIdxKey();
		key.setRequiredClusterId( ClusterId );
		Map<CFSecSecAppPKey, ICFSecSecAppObj> dict;
		if( indexByClusterIdx == null ) {
			indexByClusterIdx = new HashMap< CFSecSecAppByClusterIdxKey,
				Map< CFSecSecAppPKey, ICFSecSecAppObj > >();
		}
		if( ( ! forceRead ) && indexByClusterIdx.containsKey( key ) ) {
			dict = indexByClusterIdx.get( key );
		}
		else {
			dict = new HashMap<CFSecSecAppPKey, ICFSecSecAppObj>();
			ICFSecSecAppObj obj;
			CFSecSecAppBuff[] buffList = ((ICFSecSchema)schema.getBackingStore()).getTableSecApp().readDerivedByClusterIdx( schema.getAuthorization(),
				ClusterId );
			CFSecSecAppBuff buff;
			for( int idx = 0; idx < buffList.length; idx ++ ) {
				buff = buffList[ idx ];
				obj = schema.getSecAppTableObj().newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactorySecApp().newPKey() );
				obj.setBuff( buff );
				ICFSecSecAppObj realised = (ICFSecSecAppObj)obj.realise();
				dict.put( realised.getPKey(), realised );
			}
			indexByClusterIdx.put( key, dict );
		}
		int len = dict.size();
		ICFSecSecAppObj arr[] = new ICFSecSecAppObj[len];
		Iterator<ICFSecSecAppObj> valIter = dict.values().iterator();
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
		ArrayList<ICFSecSecAppObj> arrayList = new ArrayList<ICFSecSecAppObj>(len);
		for( idx = 0; idx < len; idx ++ ) {
			arrayList.add( arr[idx] );
		}

		Comparator<ICFSecSecAppObj> cmp = new Comparator<ICFSecSecAppObj>() {
			public int compare( ICFSecSecAppObj lhs, ICFSecSecAppObj rhs ) {
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
					CFSecSecAppPKey lhsPKey = lhs.getPKey();
					CFSecSecAppPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		List<ICFSecSecAppObj> sortedList = arrayList;
		return( sortedList );
	}

	public ICFSecSecAppObj readSecAppByUJEEMountIdx( long ClusterId,
		String JEEMountName )
	{
		return( readSecAppByUJEEMountIdx( ClusterId,
			JEEMountName,
			false ) );
	}

	public ICFSecSecAppObj readSecAppByUJEEMountIdx( long ClusterId,
		String JEEMountName, boolean forceRead )
	{
		if( indexByUJEEMountIdx == null ) {
			indexByUJEEMountIdx = new HashMap< CFSecSecAppByUJEEMountIdxKey,
				ICFSecSecAppObj >();
		}
		CFSecSecAppByUJEEMountIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactorySecApp().newUJEEMountIdxKey();
		key.setRequiredClusterId( ClusterId );
		key.setRequiredJEEMountName( JEEMountName );
		ICFSecSecAppObj obj = null;
		if( ( ! forceRead ) && indexByUJEEMountIdx.containsKey( key ) ) {
			obj = indexByUJEEMountIdx.get( key );
		}
		else {
			CFSecSecAppBuff buff = ((ICFSecSchema)schema.getBackingStore()).getTableSecApp().readDerivedByUJEEMountIdx( schema.getAuthorization(),
				ClusterId,
				JEEMountName );
			if( buff != null ) {
				obj = schema.getSecAppTableObj().newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactorySecApp().newPKey() );
				obj.setBuff( buff );
				obj = (ICFSecSecAppObj)obj.realise();
			}
		}
		return( obj );
	}

	public ICFSecSecAppObj readCachedSecAppByIdIdx( long ClusterId,
		int SecAppId )
	{
		ICFSecSecAppObj obj = null;
		CFSecSecAppPKey pkey = ((ICFSecSchema)schema.getBackingStore()).getFactorySecApp().newPKey();
		pkey.setRequiredClusterId( ClusterId );
		pkey.setRequiredSecAppId( SecAppId );
		obj = readCachedSecApp( pkey );
		return( obj );
	}

	public List<ICFSecSecAppObj> readCachedSecAppByClusterIdx( long ClusterId )
	{
		final String S_ProcName = "readCachedSecAppByClusterIdx";
		CFSecSecAppByClusterIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactorySecApp().newClusterIdxKey();
		key.setRequiredClusterId( ClusterId );
		ArrayList<ICFSecSecAppObj> arrayList = new ArrayList<ICFSecSecAppObj>();
		if( indexByClusterIdx != null ) {
			Map<CFSecSecAppPKey, ICFSecSecAppObj> dict;
			if( indexByClusterIdx.containsKey( key ) ) {
				dict = indexByClusterIdx.get( key );
				int len = dict.size();
				ICFSecSecAppObj arr[] = new ICFSecSecAppObj[len];
				Iterator<ICFSecSecAppObj> valIter = dict.values().iterator();
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
			ICFSecSecAppObj obj;
			Iterator<ICFSecSecAppObj> valIter = members.values().iterator();
			while( valIter.hasNext() ) {
				obj = valIter.next();
				if( obj != null ) {
					if( obj.getBuff().compareTo( key ) == 0 ) {
						arrayList.add( obj );
					}
				}
			}
		}
		Comparator<ICFSecSecAppObj> cmp = new Comparator<ICFSecSecAppObj>() {
			public int compare( ICFSecSecAppObj lhs, ICFSecSecAppObj rhs ) {
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
					CFSecSecAppPKey lhsPKey = lhs.getPKey();
					CFSecSecAppPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		return( arrayList );
	}

	public ICFSecSecAppObj readCachedSecAppByUJEEMountIdx( long ClusterId,
		String JEEMountName )
	{
		ICFSecSecAppObj obj = null;
		CFSecSecAppByUJEEMountIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactorySecApp().newUJEEMountIdxKey();
		key.setRequiredClusterId( ClusterId );
		key.setRequiredJEEMountName( JEEMountName );
		if( indexByUJEEMountIdx != null ) {
			if( indexByUJEEMountIdx.containsKey( key ) ) {
				obj = indexByUJEEMountIdx.get( key );
			}
			else {
				Iterator<ICFSecSecAppObj> valIter = members.values().iterator();
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
			Iterator<ICFSecSecAppObj> valIter = members.values().iterator();
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

	public void deepDisposeSecAppByIdIdx( long ClusterId,
		int SecAppId )
	{
		ICFSecSecAppObj obj = readCachedSecAppByIdIdx( ClusterId,
				SecAppId );
		if( obj != null ) {
			obj.forget();
		}
	}

	public void deepDisposeSecAppByClusterIdx( long ClusterId )
	{
		final String S_ProcName = "deepDisposeSecAppByClusterIdx";
		ICFSecSecAppObj obj;
		List<ICFSecSecAppObj> arrayList = readCachedSecAppByClusterIdx( ClusterId );
		if( arrayList != null )  {
			Iterator<ICFSecSecAppObj> arrayIter = arrayList.iterator();
			while( arrayIter.hasNext() ) {
				obj = arrayIter.next();
				if( obj != null ) {
					obj.forget();
				}
			}
		}
	}

	public void deepDisposeSecAppByUJEEMountIdx( long ClusterId,
		String JEEMountName )
	{
		ICFSecSecAppObj obj = readCachedSecAppByUJEEMountIdx( ClusterId,
				JEEMountName );
		if( obj != null ) {
			obj.forget();
		}
	}

	/**
	 *	Read a page of data as a List of SecApp-derived instances sorted by their primary keys,
	 *	as identified by the duplicate ClusterIdx key attributes.
	 *
	 *	@param	argClusterId	The SecApp key attribute of the instance generating the id.
	 *
	 *	@return	A List of SecApp-derived instances sorted by their primary keys,
	 *		as identified by the key attributes, which may be an empty set.
	 */
	public List<ICFSecSecAppObj> pageSecAppByClusterIdx( long ClusterId,
		Long priorClusterId,
		Integer priorSecAppId )
	{
		final String S_ProcName = "pageSecAppByClusterIdx";
		CFSecSecAppByClusterIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactorySecApp().newClusterIdxKey();
		key.setRequiredClusterId( ClusterId );
		List<ICFSecSecAppObj> retList = new LinkedList<ICFSecSecAppObj>();
		ICFSecSecAppObj obj;
		CFSecSecAppBuff[] buffList = ((ICFSecSchema)schema.getBackingStore()).getTableSecApp().pageBuffByClusterIdx( schema.getAuthorization(),
				ClusterId,
			priorClusterId,
			priorSecAppId );
		CFSecSecAppBuff buff;
		for( int idx = 0; idx < buffList.length; idx ++ ) {
			buff = buffList[ idx ];
				obj = schema.getSecAppTableObj().newInstance();
			obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactorySecApp().newPKey() );
			obj.setBuff( buff );
			ICFSecSecAppObj realised = (ICFSecSecAppObj)obj.realise();
			retList.add( realised );
		}
		return( retList );
	}

	public ICFSecSecAppObj updateSecApp( ICFSecSecAppObj Obj ) {
		ICFSecSecAppObj obj = Obj;
		((ICFSecSchema)schema.getBackingStore()).getTableSecApp().updateSecApp( schema.getAuthorization(),
			Obj.getSecAppBuff() );
		obj = (ICFSecSecAppObj)Obj.realise();
		obj.endEdit();
		return( obj );
	}

	public void deleteSecApp( ICFSecSecAppObj Obj ) {
		ICFSecSecAppObj obj = Obj;
		((ICFSecSchema)schema.getBackingStore()).getTableSecApp().deleteSecApp( schema.getAuthorization(),
			obj.getSecAppBuff() );
		Obj.forget();
	}

	public void deleteSecAppByIdIdx( long ClusterId,
		int SecAppId )
	{
		CFSecSecAppPKey pkey = ((ICFSecSchema)schema.getBackingStore()).getFactorySecApp().newPKey();
		pkey.setRequiredClusterId( ClusterId );
		pkey.setRequiredSecAppId( SecAppId );
		ICFSecSecAppObj obj = readSecApp( pkey );
		if( obj != null ) {
			ICFSecSecAppEditObj editObj = (ICFSecSecAppEditObj)obj.getEdit();
			boolean editStarted;
			if( editObj == null ) {
				editObj = (ICFSecSecAppEditObj)obj.beginEdit();
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
		deepDisposeSecAppByIdIdx( ClusterId,
				SecAppId );
	}

	public void deleteSecAppByClusterIdx( long ClusterId )
	{
		CFSecSecAppByClusterIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactorySecApp().newClusterIdxKey();
		key.setRequiredClusterId( ClusterId );
		if( indexByClusterIdx == null ) {
			indexByClusterIdx = new HashMap< CFSecSecAppByClusterIdxKey,
				Map< CFSecSecAppPKey, ICFSecSecAppObj > >();
		}
		if( indexByClusterIdx.containsKey( key ) ) {
			Map<CFSecSecAppPKey, ICFSecSecAppObj> dict = indexByClusterIdx.get( key );
			((ICFSecSchema)schema.getBackingStore()).getTableSecApp().deleteSecAppByClusterIdx( schema.getAuthorization(),
				ClusterId );
			Iterator<ICFSecSecAppObj> iter = dict.values().iterator();
			ICFSecSecAppObj obj;
			List<ICFSecSecAppObj> toForget = new LinkedList<ICFSecSecAppObj>();
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
			((ICFSecSchema)schema.getBackingStore()).getTableSecApp().deleteSecAppByClusterIdx( schema.getAuthorization(),
				ClusterId );
		}
		deepDisposeSecAppByClusterIdx( ClusterId );
	}

	public void deleteSecAppByUJEEMountIdx( long ClusterId,
		String JEEMountName )
	{
		if( indexByUJEEMountIdx == null ) {
			indexByUJEEMountIdx = new HashMap< CFSecSecAppByUJEEMountIdxKey,
				ICFSecSecAppObj >();
		}
		CFSecSecAppByUJEEMountIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactorySecApp().newUJEEMountIdxKey();
		key.setRequiredClusterId( ClusterId );
		key.setRequiredJEEMountName( JEEMountName );
		ICFSecSecAppObj obj = null;
		if( indexByUJEEMountIdx.containsKey( key ) ) {
			obj = indexByUJEEMountIdx.get( key );
			((ICFSecSchema)schema.getBackingStore()).getTableSecApp().deleteSecAppByUJEEMountIdx( schema.getAuthorization(),
				ClusterId,
				JEEMountName );
			obj.forget();
		}
		else {
			((ICFSecSchema)schema.getBackingStore()).getTableSecApp().deleteSecAppByUJEEMountIdx( schema.getAuthorization(),
				ClusterId,
				JEEMountName );
		}
		deepDisposeSecAppByUJEEMountIdx( ClusterId,
				JEEMountName );
	}
}