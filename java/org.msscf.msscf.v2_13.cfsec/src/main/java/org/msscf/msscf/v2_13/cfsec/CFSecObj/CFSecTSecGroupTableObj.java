// Description: Java 11 Table Object implementation for CFSec.

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

public class CFSecTSecGroupTableObj
	implements ICFSecTSecGroupTableObj
{
	protected ICFSecSchemaObj schema;
	private Map<CFSecTSecGroupPKey, ICFSecTSecGroupObj> members;
	private Map<CFSecTSecGroupPKey, ICFSecTSecGroupObj> allTSecGroup;
	private Map< CFSecTSecGroupByTenantIdxKey,
		Map<CFSecTSecGroupPKey, ICFSecTSecGroupObj > > indexByTenantIdx;
	private Map< CFSecTSecGroupByTenantVisIdxKey,
		Map<CFSecTSecGroupPKey, ICFSecTSecGroupObj > > indexByTenantVisIdx;
	private Map< CFSecTSecGroupByUNameIdxKey,
		ICFSecTSecGroupObj > indexByUNameIdx;
	public static String TABLE_NAME = "TSecGroup";
	public static String TABLE_DBNAME = "tsecgrp";

	public CFSecTSecGroupTableObj() {
		schema = null;
		members = new HashMap<CFSecTSecGroupPKey, ICFSecTSecGroupObj>();
		allTSecGroup = null;
		indexByTenantIdx = null;
		indexByTenantVisIdx = null;
		indexByUNameIdx = null;
	}

	public CFSecTSecGroupTableObj( ICFSecSchemaObj argSchema ) {
		schema = (ICFSecSchemaObj)argSchema;
		members = new HashMap<CFSecTSecGroupPKey, ICFSecTSecGroupObj>();
		allTSecGroup = null;
		indexByTenantIdx = null;
		indexByTenantVisIdx = null;
		indexByUNameIdx = null;
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
		allTSecGroup = null;
		indexByTenantIdx = null;
		indexByTenantVisIdx = null;
		indexByUNameIdx = null;
		List<ICFSecTSecGroupObj> toForget = new LinkedList<ICFSecTSecGroupObj>();
		ICFSecTSecGroupObj cur = null;
		Iterator<ICFSecTSecGroupObj> iter = members.values().iterator();
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
	 *	CFSecTSecGroupObj.
	 */
	public ICFSecTSecGroupObj newInstance() {
		ICFSecTSecGroupObj inst = new CFSecTSecGroupObj( schema );
		return( inst );
	}

	/**
	 *	If your implementation subclasses the objects,
	 *	you'll want to overload the constructByClassCode()
	 *	implementation to return your implementation's
	 *	instances instead of the base implementation.
	 *
	 *	This is the sole factory for instances derived from
	 *	CFSecTSecGroupObj.
	 */
	public ICFSecTSecGroupEditObj newEditInstance( ICFSecTSecGroupObj orig ) {
		ICFSecTSecGroupEditObj edit = new CFSecTSecGroupEditObj( orig );
		return( edit );
	}

	public ICFSecTSecGroupObj realiseTSecGroup( ICFSecTSecGroupObj Obj ) {
		ICFSecTSecGroupObj obj = Obj;
		CFSecTSecGroupPKey pkey = obj.getPKey();
		ICFSecTSecGroupObj keepObj = null;
		if( members.containsKey( pkey ) && ( null != members.get( pkey ) ) ) {
			ICFSecTSecGroupObj existingObj = members.get( pkey );
			keepObj = existingObj;

			/*
			 *	We always rebind the data because if we're being called, some index has
			 *	been updated and is refreshing it's data, which may or may not have changed
			 */

			// Detach object from alternate and duplicate indexes, leave PKey alone

			if( indexByTenantIdx != null ) {
				CFSecTSecGroupByTenantIdxKey keyTenantIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryTSecGroup().newTenantIdxKey();
				keyTenantIdx.setRequiredTenantId( keepObj.getRequiredTenantId() );
				Map<CFSecTSecGroupPKey, ICFSecTSecGroupObj > mapTenantIdx = indexByTenantIdx.get( keyTenantIdx );
				if( mapTenantIdx != null ) {
					mapTenantIdx.remove( keepObj.getPKey() );
					if( mapTenantIdx.size() <= 0 ) {
						indexByTenantIdx.remove( keyTenantIdx );
					}
				}
			}

			if( indexByTenantVisIdx != null ) {
				CFSecTSecGroupByTenantVisIdxKey keyTenantVisIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryTSecGroup().newTenantVisIdxKey();
				keyTenantVisIdx.setRequiredTenantId( keepObj.getRequiredTenantId() );
				keyTenantVisIdx.setRequiredIsVisible( keepObj.getRequiredIsVisible() );
				Map<CFSecTSecGroupPKey, ICFSecTSecGroupObj > mapTenantVisIdx = indexByTenantVisIdx.get( keyTenantVisIdx );
				if( mapTenantVisIdx != null ) {
					mapTenantVisIdx.remove( keepObj.getPKey() );
					if( mapTenantVisIdx.size() <= 0 ) {
						indexByTenantVisIdx.remove( keyTenantVisIdx );
					}
				}
			}

			if( indexByUNameIdx != null ) {
				CFSecTSecGroupByUNameIdxKey keyUNameIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryTSecGroup().newUNameIdxKey();
				keyUNameIdx.setRequiredTenantId( keepObj.getRequiredTenantId() );
				keyUNameIdx.setRequiredName( keepObj.getRequiredName() );
				indexByUNameIdx.remove( keyUNameIdx );
			}

			keepObj.setBuff( Obj.getBuff() );
			// Attach new object to alternate and duplicate indexes -- PKey stay stable

			if( indexByTenantIdx != null ) {
				CFSecTSecGroupByTenantIdxKey keyTenantIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryTSecGroup().newTenantIdxKey();
				keyTenantIdx.setRequiredTenantId( keepObj.getRequiredTenantId() );
				Map<CFSecTSecGroupPKey, ICFSecTSecGroupObj > mapTenantIdx = indexByTenantIdx.get( keyTenantIdx );
				if( mapTenantIdx != null ) {
					mapTenantIdx.put( keepObj.getPKey(), keepObj );
				}
			}

			if( indexByTenantVisIdx != null ) {
				CFSecTSecGroupByTenantVisIdxKey keyTenantVisIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryTSecGroup().newTenantVisIdxKey();
				keyTenantVisIdx.setRequiredTenantId( keepObj.getRequiredTenantId() );
				keyTenantVisIdx.setRequiredIsVisible( keepObj.getRequiredIsVisible() );
				Map<CFSecTSecGroupPKey, ICFSecTSecGroupObj > mapTenantVisIdx = indexByTenantVisIdx.get( keyTenantVisIdx );
				if( mapTenantVisIdx != null ) {
					mapTenantVisIdx.put( keepObj.getPKey(), keepObj );
				}
			}

			if( indexByUNameIdx != null ) {
				CFSecTSecGroupByUNameIdxKey keyUNameIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryTSecGroup().newUNameIdxKey();
				keyUNameIdx.setRequiredTenantId( keepObj.getRequiredTenantId() );
				keyUNameIdx.setRequiredName( keepObj.getRequiredName() );
				indexByUNameIdx.put( keyUNameIdx, keepObj );
			}

			if( allTSecGroup != null ) {
				allTSecGroup.put( keepObj.getPKey(), keepObj );
			}
		}
		else {
			keepObj = obj;
			keepObj.setIsNew( false );

			// Attach new object to PKey, all, alternate, and duplicate indexes
			members.put( keepObj.getPKey(), keepObj );
			if( allTSecGroup != null ) {
				allTSecGroup.put( keepObj.getPKey(), keepObj );
			}

			if( indexByTenantIdx != null ) {
				CFSecTSecGroupByTenantIdxKey keyTenantIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryTSecGroup().newTenantIdxKey();
				keyTenantIdx.setRequiredTenantId( keepObj.getRequiredTenantId() );
				Map<CFSecTSecGroupPKey, ICFSecTSecGroupObj > mapTenantIdx = indexByTenantIdx.get( keyTenantIdx );
				if( mapTenantIdx != null ) {
					mapTenantIdx.put( keepObj.getPKey(), keepObj );
				}
			}

			if( indexByTenantVisIdx != null ) {
				CFSecTSecGroupByTenantVisIdxKey keyTenantVisIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryTSecGroup().newTenantVisIdxKey();
				keyTenantVisIdx.setRequiredTenantId( keepObj.getRequiredTenantId() );
				keyTenantVisIdx.setRequiredIsVisible( keepObj.getRequiredIsVisible() );
				Map<CFSecTSecGroupPKey, ICFSecTSecGroupObj > mapTenantVisIdx = indexByTenantVisIdx.get( keyTenantVisIdx );
				if( mapTenantVisIdx != null ) {
					mapTenantVisIdx.put( keepObj.getPKey(), keepObj );
				}
			}

			if( indexByUNameIdx != null ) {
				CFSecTSecGroupByUNameIdxKey keyUNameIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryTSecGroup().newUNameIdxKey();
				keyUNameIdx.setRequiredTenantId( keepObj.getRequiredTenantId() );
				keyUNameIdx.setRequiredName( keepObj.getRequiredName() );
				indexByUNameIdx.put( keyUNameIdx, keepObj );
			}

		}
		return( keepObj );
	}

	public ICFSecTSecGroupObj createTSecGroup( ICFSecTSecGroupObj Obj ) {
		ICFSecTSecGroupObj obj = Obj;
		CFSecTSecGroupBuff buff = obj.getTSecGroupBuff();
		((ICFSecSchema)schema.getBackingStore()).getTableTSecGroup().createTSecGroup(
			schema.getAuthorization(),
			buff );
		obj.copyBuffToPKey();
		obj = obj.realise();
		obj.endEdit();
		return( obj );
	}

	public ICFSecTSecGroupObj readTSecGroup( CFSecTSecGroupPKey pkey ) {
		return( readTSecGroup( pkey, false ) );
	}

	public ICFSecTSecGroupObj readTSecGroup( CFSecTSecGroupPKey pkey, boolean forceRead ) {
		ICFSecTSecGroupObj obj = null;
		if( ( ! forceRead ) && members.containsKey( pkey ) ) {
			obj = members.get( pkey );
		}
		else {
			CFSecTSecGroupBuff readBuff = ((ICFSecSchema)schema.getBackingStore()).getTableTSecGroup().readDerivedByIdIdx( schema.getAuthorization(),
				pkey.getRequiredTenantId(),
				pkey.getRequiredTSecGroupId() );
			if( readBuff != null ) {
				obj = schema.getTSecGroupTableObj().newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactoryTSecGroup().newPKey() );
				obj.setBuff( readBuff );
				obj = (ICFSecTSecGroupObj)obj.realise();
			}
		}
		return( obj );
	}

	public ICFSecTSecGroupObj readCachedTSecGroup( CFSecTSecGroupPKey pkey ) {
		ICFSecTSecGroupObj obj = null;
		if( members.containsKey( pkey ) ) {
			obj = members.get( pkey );
		}
		return( obj );
	}

	public void reallyDeepDisposeTSecGroup( ICFSecTSecGroupObj obj )
	{
		final String S_ProcName = "CFSecTSecGroupTableObj.reallyDeepDisposeTSecGroup() ";
		String classCode;
		if( obj == null ) {
			return;
		}
		CFSecTSecGroupPKey pkey = obj.getPKey();
		ICFSecTSecGroupObj existing = readCachedTSecGroup( pkey );
		if( existing == null ) {
			return;
		}
		members.remove( pkey );
		CFSecTSecGroupByTenantIdxKey keyTenantIdx = ((ICFSecSchema)schema.getBackingStore()).getFactoryTSecGroup().newTenantIdxKey();
		keyTenantIdx.setRequiredTenantId( existing.getRequiredTenantId() );

		CFSecTSecGroupByTenantVisIdxKey keyTenantVisIdx = ((ICFSecSchema)schema.getBackingStore()).getFactoryTSecGroup().newTenantVisIdxKey();
		keyTenantVisIdx.setRequiredTenantId( existing.getRequiredTenantId() );
		keyTenantVisIdx.setRequiredIsVisible( existing.getRequiredIsVisible() );

		CFSecTSecGroupByUNameIdxKey keyUNameIdx = ((ICFSecSchema)schema.getBackingStore()).getFactoryTSecGroup().newUNameIdxKey();
		keyUNameIdx.setRequiredTenantId( existing.getRequiredTenantId() );
		keyUNameIdx.setRequiredName( existing.getRequiredName() );


					schema.getTSecGrpIncTableObj().deepDisposeTSecGrpIncByIncludeIdx( existing.getRequiredTenantId(),
						existing.getRequiredTSecGroupId() );
					schema.getTSecGrpMembTableObj().deepDisposeTSecGrpMembByGroupIdx( existing.getRequiredTenantId(),
						existing.getRequiredTSecGroupId() );
					schema.getTSecGrpIncTableObj().deepDisposeTSecGrpIncByGroupIdx( existing.getRequiredTenantId(),
						existing.getRequiredTSecGroupId() );

		if( indexByTenantIdx != null ) {
			if( indexByTenantIdx.containsKey( keyTenantIdx ) ) {
				indexByTenantIdx.get( keyTenantIdx ).remove( pkey );
				if( indexByTenantIdx.get( keyTenantIdx ).size() <= 0 ) {
					indexByTenantIdx.remove( keyTenantIdx );
				}
			}
		}

		if( indexByTenantVisIdx != null ) {
			if( indexByTenantVisIdx.containsKey( keyTenantVisIdx ) ) {
				indexByTenantVisIdx.get( keyTenantVisIdx ).remove( pkey );
				if( indexByTenantVisIdx.get( keyTenantVisIdx ).size() <= 0 ) {
					indexByTenantVisIdx.remove( keyTenantVisIdx );
				}
			}
		}

		if( indexByUNameIdx != null ) {
			indexByUNameIdx.remove( keyUNameIdx );
		}


	}
	public void deepDisposeTSecGroup( CFSecTSecGroupPKey pkey ) {
		ICFSecTSecGroupObj obj = readCachedTSecGroup( pkey );
		if( obj != null ) {
			obj.forget();
		}
	}

	public ICFSecTSecGroupObj lockTSecGroup( CFSecTSecGroupPKey pkey ) {
		ICFSecTSecGroupObj locked = null;
		CFSecTSecGroupBuff lockBuff = ((ICFSecSchema)schema.getBackingStore()).getTableTSecGroup().lockDerived( schema.getAuthorization(), pkey );
		if( lockBuff != null ) {
				locked = schema.getTSecGroupTableObj().newInstance();
			locked.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactoryTSecGroup().newPKey() );
			locked.setBuff( lockBuff );
			locked = (ICFSecTSecGroupObj)locked.realise();
		}
		else {
			throw new CFLibCollisionDetectedException( getClass(), "lockTSecGroup", pkey );
		}
		return( locked );
	}

	public List<ICFSecTSecGroupObj> readAllTSecGroup() {
		return( readAllTSecGroup( false ) );
	}

	public List<ICFSecTSecGroupObj> readAllTSecGroup( boolean forceRead ) {
		final String S_ProcName = "readAllTSecGroup";
		if( ( allTSecGroup == null ) || forceRead ) {
			Map<CFSecTSecGroupPKey, ICFSecTSecGroupObj> map = new HashMap<CFSecTSecGroupPKey,ICFSecTSecGroupObj>();
			allTSecGroup = map;
			CFSecTSecGroupBuff[] buffList = ((ICFSecSchema)schema.getBackingStore()).getTableTSecGroup().readAllDerived( schema.getAuthorization() );
			CFSecTSecGroupBuff buff;
			ICFSecTSecGroupObj obj;
			for( int idx = 0; idx < buffList.length; idx ++ ) {
				buff = buffList[ idx ];
				obj = newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactoryTSecGroup().newPKey() );
				obj.setBuff( buff );
				ICFSecTSecGroupObj realised = (ICFSecTSecGroupObj)obj.realise();
			}
		}
		int len = allTSecGroup.size();
		ICFSecTSecGroupObj arr[] = new ICFSecTSecGroupObj[len];
		Iterator<ICFSecTSecGroupObj> valIter = allTSecGroup.values().iterator();
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
		ArrayList<ICFSecTSecGroupObj> arrayList = new ArrayList<ICFSecTSecGroupObj>(len);
		for( idx = 0; idx < len; idx ++ ) {
			arrayList.add( arr[idx] );
		}

		Comparator<ICFSecTSecGroupObj> cmp = new Comparator<ICFSecTSecGroupObj>() {
			public int compare( ICFSecTSecGroupObj lhs, ICFSecTSecGroupObj rhs ) {
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
					CFSecTSecGroupPKey lhsPKey = lhs.getPKey();
					CFSecTSecGroupPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		List<ICFSecTSecGroupObj> sortedList = arrayList;
		return( sortedList );
	}

	public List<ICFSecTSecGroupObj> readCachedAllTSecGroup() {
		final String S_ProcName = "readCachedAllTSecGroup";
		ArrayList<ICFSecTSecGroupObj> arrayList = new ArrayList<ICFSecTSecGroupObj>();
		if( allTSecGroup != null ) {
			int len = allTSecGroup.size();
			ICFSecTSecGroupObj arr[] = new ICFSecTSecGroupObj[len];
			Iterator<ICFSecTSecGroupObj> valIter = allTSecGroup.values().iterator();
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
		Comparator<ICFSecTSecGroupObj> cmp = new Comparator<ICFSecTSecGroupObj>() {
			public int compare( ICFSecTSecGroupObj lhs, ICFSecTSecGroupObj rhs ) {
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
					CFSecTSecGroupPKey lhsPKey = lhs.getPKey();
					CFSecTSecGroupPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		return( arrayList );
	}

	public ICFSecTSecGroupObj readTSecGroupByIdIdx( long TenantId,
		int TSecGroupId )
	{
		return( readTSecGroupByIdIdx( TenantId,
			TSecGroupId,
			false ) );
	}

	public ICFSecTSecGroupObj readTSecGroupByIdIdx( long TenantId,
		int TSecGroupId, boolean forceRead )
	{
		CFSecTSecGroupPKey pkey = ((ICFSecSchema)schema.getBackingStore()).getFactoryTSecGroup().newPKey();
		pkey.setRequiredTenantId( TenantId );
		pkey.setRequiredTSecGroupId( TSecGroupId );
		ICFSecTSecGroupObj obj = readTSecGroup( pkey, forceRead );
		return( obj );
	}

	public List<ICFSecTSecGroupObj> readTSecGroupByTenantIdx( long TenantId )
	{
		return( readTSecGroupByTenantIdx( TenantId,
			false ) );
	}

	public List<ICFSecTSecGroupObj> readTSecGroupByTenantIdx( long TenantId,
		boolean forceRead )
	{
		final String S_ProcName = "readTSecGroupByTenantIdx";
		CFSecTSecGroupByTenantIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryTSecGroup().newTenantIdxKey();
		key.setRequiredTenantId( TenantId );
		Map<CFSecTSecGroupPKey, ICFSecTSecGroupObj> dict;
		if( indexByTenantIdx == null ) {
			indexByTenantIdx = new HashMap< CFSecTSecGroupByTenantIdxKey,
				Map< CFSecTSecGroupPKey, ICFSecTSecGroupObj > >();
		}
		if( ( ! forceRead ) && indexByTenantIdx.containsKey( key ) ) {
			dict = indexByTenantIdx.get( key );
		}
		else {
			dict = new HashMap<CFSecTSecGroupPKey, ICFSecTSecGroupObj>();
			ICFSecTSecGroupObj obj;
			CFSecTSecGroupBuff[] buffList = ((ICFSecSchema)schema.getBackingStore()).getTableTSecGroup().readDerivedByTenantIdx( schema.getAuthorization(),
				TenantId );
			CFSecTSecGroupBuff buff;
			for( int idx = 0; idx < buffList.length; idx ++ ) {
				buff = buffList[ idx ];
				obj = schema.getTSecGroupTableObj().newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactoryTSecGroup().newPKey() );
				obj.setBuff( buff );
				ICFSecTSecGroupObj realised = (ICFSecTSecGroupObj)obj.realise();
				dict.put( realised.getPKey(), realised );
			}
			indexByTenantIdx.put( key, dict );
		}
		int len = dict.size();
		ICFSecTSecGroupObj arr[] = new ICFSecTSecGroupObj[len];
		Iterator<ICFSecTSecGroupObj> valIter = dict.values().iterator();
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
		ArrayList<ICFSecTSecGroupObj> arrayList = new ArrayList<ICFSecTSecGroupObj>(len);
		for( idx = 0; idx < len; idx ++ ) {
			arrayList.add( arr[idx] );
		}

		Comparator<ICFSecTSecGroupObj> cmp = new Comparator<ICFSecTSecGroupObj>() {
			public int compare( ICFSecTSecGroupObj lhs, ICFSecTSecGroupObj rhs ) {
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
					CFSecTSecGroupPKey lhsPKey = lhs.getPKey();
					CFSecTSecGroupPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		List<ICFSecTSecGroupObj> sortedList = arrayList;
		return( sortedList );
	}

	public List<ICFSecTSecGroupObj> readTSecGroupByTenantVisIdx( long TenantId,
		boolean IsVisible )
	{
		return( readTSecGroupByTenantVisIdx( TenantId,
			IsVisible,
			false ) );
	}

	public List<ICFSecTSecGroupObj> readTSecGroupByTenantVisIdx( long TenantId,
		boolean IsVisible,
		boolean forceRead )
	{
		final String S_ProcName = "readTSecGroupByTenantVisIdx";
		CFSecTSecGroupByTenantVisIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryTSecGroup().newTenantVisIdxKey();
		key.setRequiredTenantId( TenantId );
		key.setRequiredIsVisible( IsVisible );
		Map<CFSecTSecGroupPKey, ICFSecTSecGroupObj> dict;
		if( indexByTenantVisIdx == null ) {
			indexByTenantVisIdx = new HashMap< CFSecTSecGroupByTenantVisIdxKey,
				Map< CFSecTSecGroupPKey, ICFSecTSecGroupObj > >();
		}
		if( ( ! forceRead ) && indexByTenantVisIdx.containsKey( key ) ) {
			dict = indexByTenantVisIdx.get( key );
		}
		else {
			dict = new HashMap<CFSecTSecGroupPKey, ICFSecTSecGroupObj>();
			ICFSecTSecGroupObj obj;
			CFSecTSecGroupBuff[] buffList = ((ICFSecSchema)schema.getBackingStore()).getTableTSecGroup().readDerivedByTenantVisIdx( schema.getAuthorization(),
				TenantId,
				IsVisible );
			CFSecTSecGroupBuff buff;
			for( int idx = 0; idx < buffList.length; idx ++ ) {
				buff = buffList[ idx ];
				obj = schema.getTSecGroupTableObj().newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactoryTSecGroup().newPKey() );
				obj.setBuff( buff );
				ICFSecTSecGroupObj realised = (ICFSecTSecGroupObj)obj.realise();
				dict.put( realised.getPKey(), realised );
			}
			indexByTenantVisIdx.put( key, dict );
		}
		int len = dict.size();
		ICFSecTSecGroupObj arr[] = new ICFSecTSecGroupObj[len];
		Iterator<ICFSecTSecGroupObj> valIter = dict.values().iterator();
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
		ArrayList<ICFSecTSecGroupObj> arrayList = new ArrayList<ICFSecTSecGroupObj>(len);
		for( idx = 0; idx < len; idx ++ ) {
			arrayList.add( arr[idx] );
		}

		Comparator<ICFSecTSecGroupObj> cmp = new Comparator<ICFSecTSecGroupObj>() {
			public int compare( ICFSecTSecGroupObj lhs, ICFSecTSecGroupObj rhs ) {
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
					CFSecTSecGroupPKey lhsPKey = lhs.getPKey();
					CFSecTSecGroupPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		List<ICFSecTSecGroupObj> sortedList = arrayList;
		return( sortedList );
	}

	public ICFSecTSecGroupObj readTSecGroupByUNameIdx( long TenantId,
		String Name )
	{
		return( readTSecGroupByUNameIdx( TenantId,
			Name,
			false ) );
	}

	public ICFSecTSecGroupObj readTSecGroupByUNameIdx( long TenantId,
		String Name, boolean forceRead )
	{
		if( indexByUNameIdx == null ) {
			indexByUNameIdx = new HashMap< CFSecTSecGroupByUNameIdxKey,
				ICFSecTSecGroupObj >();
		}
		CFSecTSecGroupByUNameIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryTSecGroup().newUNameIdxKey();
		key.setRequiredTenantId( TenantId );
		key.setRequiredName( Name );
		ICFSecTSecGroupObj obj = null;
		if( ( ! forceRead ) && indexByUNameIdx.containsKey( key ) ) {
			obj = indexByUNameIdx.get( key );
		}
		else {
			CFSecTSecGroupBuff buff = ((ICFSecSchema)schema.getBackingStore()).getTableTSecGroup().readDerivedByUNameIdx( schema.getAuthorization(),
				TenantId,
				Name );
			if( buff != null ) {
				obj = schema.getTSecGroupTableObj().newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactoryTSecGroup().newPKey() );
				obj.setBuff( buff );
				obj = (ICFSecTSecGroupObj)obj.realise();
			}
		}
		return( obj );
	}

	public ICFSecTSecGroupObj readCachedTSecGroupByIdIdx( long TenantId,
		int TSecGroupId )
	{
		ICFSecTSecGroupObj obj = null;
		CFSecTSecGroupPKey pkey = ((ICFSecSchema)schema.getBackingStore()).getFactoryTSecGroup().newPKey();
		pkey.setRequiredTenantId( TenantId );
		pkey.setRequiredTSecGroupId( TSecGroupId );
		obj = readCachedTSecGroup( pkey );
		return( obj );
	}

	public List<ICFSecTSecGroupObj> readCachedTSecGroupByTenantIdx( long TenantId )
	{
		final String S_ProcName = "readCachedTSecGroupByTenantIdx";
		CFSecTSecGroupByTenantIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryTSecGroup().newTenantIdxKey();
		key.setRequiredTenantId( TenantId );
		ArrayList<ICFSecTSecGroupObj> arrayList = new ArrayList<ICFSecTSecGroupObj>();
		if( indexByTenantIdx != null ) {
			Map<CFSecTSecGroupPKey, ICFSecTSecGroupObj> dict;
			if( indexByTenantIdx.containsKey( key ) ) {
				dict = indexByTenantIdx.get( key );
				int len = dict.size();
				ICFSecTSecGroupObj arr[] = new ICFSecTSecGroupObj[len];
				Iterator<ICFSecTSecGroupObj> valIter = dict.values().iterator();
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
			ICFSecTSecGroupObj obj;
			Iterator<ICFSecTSecGroupObj> valIter = members.values().iterator();
			while( valIter.hasNext() ) {
				obj = valIter.next();
				if( obj != null ) {
					if( obj.getBuff().compareTo( key ) == 0 ) {
						arrayList.add( obj );
					}
				}
			}
		}
		Comparator<ICFSecTSecGroupObj> cmp = new Comparator<ICFSecTSecGroupObj>() {
			public int compare( ICFSecTSecGroupObj lhs, ICFSecTSecGroupObj rhs ) {
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
					CFSecTSecGroupPKey lhsPKey = lhs.getPKey();
					CFSecTSecGroupPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		return( arrayList );
	}

	public List<ICFSecTSecGroupObj> readCachedTSecGroupByTenantVisIdx( long TenantId,
		boolean IsVisible )
	{
		final String S_ProcName = "readCachedTSecGroupByTenantVisIdx";
		CFSecTSecGroupByTenantVisIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryTSecGroup().newTenantVisIdxKey();
		key.setRequiredTenantId( TenantId );
		key.setRequiredIsVisible( IsVisible );
		ArrayList<ICFSecTSecGroupObj> arrayList = new ArrayList<ICFSecTSecGroupObj>();
		if( indexByTenantVisIdx != null ) {
			Map<CFSecTSecGroupPKey, ICFSecTSecGroupObj> dict;
			if( indexByTenantVisIdx.containsKey( key ) ) {
				dict = indexByTenantVisIdx.get( key );
				int len = dict.size();
				ICFSecTSecGroupObj arr[] = new ICFSecTSecGroupObj[len];
				Iterator<ICFSecTSecGroupObj> valIter = dict.values().iterator();
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
			ICFSecTSecGroupObj obj;
			Iterator<ICFSecTSecGroupObj> valIter = members.values().iterator();
			while( valIter.hasNext() ) {
				obj = valIter.next();
				if( obj != null ) {
					if( obj.getBuff().compareTo( key ) == 0 ) {
						arrayList.add( obj );
					}
				}
			}
		}
		Comparator<ICFSecTSecGroupObj> cmp = new Comparator<ICFSecTSecGroupObj>() {
			public int compare( ICFSecTSecGroupObj lhs, ICFSecTSecGroupObj rhs ) {
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
					CFSecTSecGroupPKey lhsPKey = lhs.getPKey();
					CFSecTSecGroupPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		return( arrayList );
	}

	public ICFSecTSecGroupObj readCachedTSecGroupByUNameIdx( long TenantId,
		String Name )
	{
		ICFSecTSecGroupObj obj = null;
		CFSecTSecGroupByUNameIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryTSecGroup().newUNameIdxKey();
		key.setRequiredTenantId( TenantId );
		key.setRequiredName( Name );
		if( indexByUNameIdx != null ) {
			if( indexByUNameIdx.containsKey( key ) ) {
				obj = indexByUNameIdx.get( key );
			}
			else {
				Iterator<ICFSecTSecGroupObj> valIter = members.values().iterator();
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
			Iterator<ICFSecTSecGroupObj> valIter = members.values().iterator();
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

	public void deepDisposeTSecGroupByIdIdx( long TenantId,
		int TSecGroupId )
	{
		ICFSecTSecGroupObj obj = readCachedTSecGroupByIdIdx( TenantId,
				TSecGroupId );
		if( obj != null ) {
			obj.forget();
		}
	}

	public void deepDisposeTSecGroupByTenantIdx( long TenantId )
	{
		final String S_ProcName = "deepDisposeTSecGroupByTenantIdx";
		ICFSecTSecGroupObj obj;
		List<ICFSecTSecGroupObj> arrayList = readCachedTSecGroupByTenantIdx( TenantId );
		if( arrayList != null )  {
			Iterator<ICFSecTSecGroupObj> arrayIter = arrayList.iterator();
			while( arrayIter.hasNext() ) {
				obj = arrayIter.next();
				if( obj != null ) {
					obj.forget();
				}
			}
		}
	}

	public void deepDisposeTSecGroupByTenantVisIdx( long TenantId,
		boolean IsVisible )
	{
		final String S_ProcName = "deepDisposeTSecGroupByTenantVisIdx";
		ICFSecTSecGroupObj obj;
		List<ICFSecTSecGroupObj> arrayList = readCachedTSecGroupByTenantVisIdx( TenantId,
				IsVisible );
		if( arrayList != null )  {
			Iterator<ICFSecTSecGroupObj> arrayIter = arrayList.iterator();
			while( arrayIter.hasNext() ) {
				obj = arrayIter.next();
				if( obj != null ) {
					obj.forget();
				}
			}
		}
	}

	public void deepDisposeTSecGroupByUNameIdx( long TenantId,
		String Name )
	{
		ICFSecTSecGroupObj obj = readCachedTSecGroupByUNameIdx( TenantId,
				Name );
		if( obj != null ) {
			obj.forget();
		}
	}

	public ICFSecTSecGroupObj updateTSecGroup( ICFSecTSecGroupObj Obj ) {
		ICFSecTSecGroupObj obj = Obj;
		((ICFSecSchema)schema.getBackingStore()).getTableTSecGroup().updateTSecGroup( schema.getAuthorization(),
			Obj.getTSecGroupBuff() );
		obj = (ICFSecTSecGroupObj)Obj.realise();
		obj.endEdit();
		return( obj );
	}

	public void deleteTSecGroup( ICFSecTSecGroupObj Obj ) {
		ICFSecTSecGroupObj obj = Obj;
		((ICFSecSchema)schema.getBackingStore()).getTableTSecGroup().deleteTSecGroup( schema.getAuthorization(),
			obj.getTSecGroupBuff() );
		Obj.forget();
	}

	public void deleteTSecGroupByIdIdx( long TenantId,
		int TSecGroupId )
	{
		CFSecTSecGroupPKey pkey = ((ICFSecSchema)schema.getBackingStore()).getFactoryTSecGroup().newPKey();
		pkey.setRequiredTenantId( TenantId );
		pkey.setRequiredTSecGroupId( TSecGroupId );
		ICFSecTSecGroupObj obj = readTSecGroup( pkey );
		if( obj != null ) {
			ICFSecTSecGroupEditObj editObj = (ICFSecTSecGroupEditObj)obj.getEdit();
			boolean editStarted;
			if( editObj == null ) {
				editObj = (ICFSecTSecGroupEditObj)obj.beginEdit();
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
		deepDisposeTSecGroupByIdIdx( TenantId,
				TSecGroupId );
	}

	public void deleteTSecGroupByTenantIdx( long TenantId )
	{
		CFSecTSecGroupByTenantIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryTSecGroup().newTenantIdxKey();
		key.setRequiredTenantId( TenantId );
		if( indexByTenantIdx == null ) {
			indexByTenantIdx = new HashMap< CFSecTSecGroupByTenantIdxKey,
				Map< CFSecTSecGroupPKey, ICFSecTSecGroupObj > >();
		}
		if( indexByTenantIdx.containsKey( key ) ) {
			Map<CFSecTSecGroupPKey, ICFSecTSecGroupObj> dict = indexByTenantIdx.get( key );
			((ICFSecSchema)schema.getBackingStore()).getTableTSecGroup().deleteTSecGroupByTenantIdx( schema.getAuthorization(),
				TenantId );
			Iterator<ICFSecTSecGroupObj> iter = dict.values().iterator();
			ICFSecTSecGroupObj obj;
			List<ICFSecTSecGroupObj> toForget = new LinkedList<ICFSecTSecGroupObj>();
			while( iter.hasNext() ) {
				obj = iter.next();
				toForget.add( obj );
			}
			iter = toForget.iterator();
			while( iter.hasNext() ) {
				obj = iter.next();
				obj.forget();
			}
			indexByTenantIdx.remove( key );
		}
		else {
			((ICFSecSchema)schema.getBackingStore()).getTableTSecGroup().deleteTSecGroupByTenantIdx( schema.getAuthorization(),
				TenantId );
		}
		deepDisposeTSecGroupByTenantIdx( TenantId );
	}

	public void deleteTSecGroupByTenantVisIdx( long TenantId,
		boolean IsVisible )
	{
		CFSecTSecGroupByTenantVisIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryTSecGroup().newTenantVisIdxKey();
		key.setRequiredTenantId( TenantId );
		key.setRequiredIsVisible( IsVisible );
		if( indexByTenantVisIdx == null ) {
			indexByTenantVisIdx = new HashMap< CFSecTSecGroupByTenantVisIdxKey,
				Map< CFSecTSecGroupPKey, ICFSecTSecGroupObj > >();
		}
		if( indexByTenantVisIdx.containsKey( key ) ) {
			Map<CFSecTSecGroupPKey, ICFSecTSecGroupObj> dict = indexByTenantVisIdx.get( key );
			((ICFSecSchema)schema.getBackingStore()).getTableTSecGroup().deleteTSecGroupByTenantVisIdx( schema.getAuthorization(),
				TenantId,
				IsVisible );
			Iterator<ICFSecTSecGroupObj> iter = dict.values().iterator();
			ICFSecTSecGroupObj obj;
			List<ICFSecTSecGroupObj> toForget = new LinkedList<ICFSecTSecGroupObj>();
			while( iter.hasNext() ) {
				obj = iter.next();
				toForget.add( obj );
			}
			iter = toForget.iterator();
			while( iter.hasNext() ) {
				obj = iter.next();
				obj.forget();
			}
			indexByTenantVisIdx.remove( key );
		}
		else {
			((ICFSecSchema)schema.getBackingStore()).getTableTSecGroup().deleteTSecGroupByTenantVisIdx( schema.getAuthorization(),
				TenantId,
				IsVisible );
		}
		deepDisposeTSecGroupByTenantVisIdx( TenantId,
				IsVisible );
	}

	public void deleteTSecGroupByUNameIdx( long TenantId,
		String Name )
	{
		if( indexByUNameIdx == null ) {
			indexByUNameIdx = new HashMap< CFSecTSecGroupByUNameIdxKey,
				ICFSecTSecGroupObj >();
		}
		CFSecTSecGroupByUNameIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryTSecGroup().newUNameIdxKey();
		key.setRequiredTenantId( TenantId );
		key.setRequiredName( Name );
		ICFSecTSecGroupObj obj = null;
		if( indexByUNameIdx.containsKey( key ) ) {
			obj = indexByUNameIdx.get( key );
			((ICFSecSchema)schema.getBackingStore()).getTableTSecGroup().deleteTSecGroupByUNameIdx( schema.getAuthorization(),
				TenantId,
				Name );
			obj.forget();
		}
		else {
			((ICFSecSchema)schema.getBackingStore()).getTableTSecGroup().deleteTSecGroupByUNameIdx( schema.getAuthorization(),
				TenantId,
				Name );
		}
		deepDisposeTSecGroupByUNameIdx( TenantId,
				Name );
	}
}
