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

public class CFSecSecGrpIncTableObj
	implements ICFSecSecGrpIncTableObj
{
	protected ICFSecSchemaObj schema;
	private Map<CFSecSecGrpIncPKey, ICFSecSecGrpIncObj> members;
	private Map<CFSecSecGrpIncPKey, ICFSecSecGrpIncObj> allSecGrpInc;
	private Map< CFSecSecGrpIncByClusterIdxKey,
		Map<CFSecSecGrpIncPKey, ICFSecSecGrpIncObj > > indexByClusterIdx;
	private Map< CFSecSecGrpIncByGroupIdxKey,
		Map<CFSecSecGrpIncPKey, ICFSecSecGrpIncObj > > indexByGroupIdx;
	private Map< CFSecSecGrpIncByIncludeIdxKey,
		Map<CFSecSecGrpIncPKey, ICFSecSecGrpIncObj > > indexByIncludeIdx;
	private Map< CFSecSecGrpIncByUIncludeIdxKey,
		ICFSecSecGrpIncObj > indexByUIncludeIdx;
	public static String TABLE_NAME = "SecGrpInc";
	public static String TABLE_DBNAME = "secinc";

	public CFSecSecGrpIncTableObj() {
		schema = null;
		members = new HashMap<CFSecSecGrpIncPKey, ICFSecSecGrpIncObj>();
		allSecGrpInc = null;
		indexByClusterIdx = null;
		indexByGroupIdx = null;
		indexByIncludeIdx = null;
		indexByUIncludeIdx = null;
	}

	public CFSecSecGrpIncTableObj( ICFSecSchemaObj argSchema ) {
		schema = (ICFSecSchemaObj)argSchema;
		members = new HashMap<CFSecSecGrpIncPKey, ICFSecSecGrpIncObj>();
		allSecGrpInc = null;
		indexByClusterIdx = null;
		indexByGroupIdx = null;
		indexByIncludeIdx = null;
		indexByUIncludeIdx = null;
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
		allSecGrpInc = null;
		indexByClusterIdx = null;
		indexByGroupIdx = null;
		indexByIncludeIdx = null;
		indexByUIncludeIdx = null;
		List<ICFSecSecGrpIncObj> toForget = new LinkedList<ICFSecSecGrpIncObj>();
		ICFSecSecGrpIncObj cur = null;
		Iterator<ICFSecSecGrpIncObj> iter = members.values().iterator();
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
	 *	CFSecSecGrpIncObj.
	 */
	public ICFSecSecGrpIncObj newInstance() {
		ICFSecSecGrpIncObj inst = new CFSecSecGrpIncObj( schema );
		return( inst );
	}

	/**
	 *	If your implementation subclasses the objects,
	 *	you'll want to overload the constructByClassCode()
	 *	implementation to return your implementation's
	 *	instances instead of the base implementation.
	 *
	 *	This is the sole factory for instances derived from
	 *	CFSecSecGrpIncObj.
	 */
	public ICFSecSecGrpIncEditObj newEditInstance( ICFSecSecGrpIncObj orig ) {
		ICFSecSecGrpIncEditObj edit = new CFSecSecGrpIncEditObj( orig );
		return( edit );
	}

	public ICFSecSecGrpIncObj realiseSecGrpInc( ICFSecSecGrpIncObj Obj ) {
		ICFSecSecGrpIncObj obj = Obj;
		CFSecSecGrpIncPKey pkey = obj.getPKey();
		ICFSecSecGrpIncObj keepObj = null;
		if( members.containsKey( pkey ) && ( null != members.get( pkey ) ) ) {
			ICFSecSecGrpIncObj existingObj = members.get( pkey );
			keepObj = existingObj;

			/*
			 *	We always rebind the data because if we're being called, some index has
			 *	been updated and is refreshing it's data, which may or may not have changed
			 */

			// Detach object from alternate and duplicate indexes, leave PKey alone

			if( indexByClusterIdx != null ) {
				CFSecSecGrpIncByClusterIdxKey keyClusterIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactorySecGrpInc().newClusterIdxKey();
				keyClusterIdx.setRequiredClusterId( keepObj.getRequiredClusterId() );
				Map<CFSecSecGrpIncPKey, ICFSecSecGrpIncObj > mapClusterIdx = indexByClusterIdx.get( keyClusterIdx );
				if( mapClusterIdx != null ) {
					mapClusterIdx.remove( keepObj.getPKey() );
					if( mapClusterIdx.size() <= 0 ) {
						indexByClusterIdx.remove( keyClusterIdx );
					}
				}
			}

			if( indexByGroupIdx != null ) {
				CFSecSecGrpIncByGroupIdxKey keyGroupIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactorySecGrpInc().newGroupIdxKey();
				keyGroupIdx.setRequiredClusterId( keepObj.getRequiredClusterId() );
				keyGroupIdx.setRequiredSecGroupId( keepObj.getRequiredSecGroupId() );
				Map<CFSecSecGrpIncPKey, ICFSecSecGrpIncObj > mapGroupIdx = indexByGroupIdx.get( keyGroupIdx );
				if( mapGroupIdx != null ) {
					mapGroupIdx.remove( keepObj.getPKey() );
					if( mapGroupIdx.size() <= 0 ) {
						indexByGroupIdx.remove( keyGroupIdx );
					}
				}
			}

			if( indexByIncludeIdx != null ) {
				CFSecSecGrpIncByIncludeIdxKey keyIncludeIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactorySecGrpInc().newIncludeIdxKey();
				keyIncludeIdx.setRequiredClusterId( keepObj.getRequiredClusterId() );
				keyIncludeIdx.setRequiredIncludeGroupId( keepObj.getRequiredIncludeGroupId() );
				Map<CFSecSecGrpIncPKey, ICFSecSecGrpIncObj > mapIncludeIdx = indexByIncludeIdx.get( keyIncludeIdx );
				if( mapIncludeIdx != null ) {
					mapIncludeIdx.remove( keepObj.getPKey() );
					if( mapIncludeIdx.size() <= 0 ) {
						indexByIncludeIdx.remove( keyIncludeIdx );
					}
				}
			}

			if( indexByUIncludeIdx != null ) {
				CFSecSecGrpIncByUIncludeIdxKey keyUIncludeIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactorySecGrpInc().newUIncludeIdxKey();
				keyUIncludeIdx.setRequiredClusterId( keepObj.getRequiredClusterId() );
				keyUIncludeIdx.setRequiredSecGroupId( keepObj.getRequiredSecGroupId() );
				keyUIncludeIdx.setRequiredIncludeGroupId( keepObj.getRequiredIncludeGroupId() );
				indexByUIncludeIdx.remove( keyUIncludeIdx );
			}

			keepObj.setBuff( Obj.getBuff() );
			// Attach new object to alternate and duplicate indexes -- PKey stay stable

			if( indexByClusterIdx != null ) {
				CFSecSecGrpIncByClusterIdxKey keyClusterIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactorySecGrpInc().newClusterIdxKey();
				keyClusterIdx.setRequiredClusterId( keepObj.getRequiredClusterId() );
				Map<CFSecSecGrpIncPKey, ICFSecSecGrpIncObj > mapClusterIdx = indexByClusterIdx.get( keyClusterIdx );
				if( mapClusterIdx != null ) {
					mapClusterIdx.put( keepObj.getPKey(), keepObj );
				}
			}

			if( indexByGroupIdx != null ) {
				CFSecSecGrpIncByGroupIdxKey keyGroupIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactorySecGrpInc().newGroupIdxKey();
				keyGroupIdx.setRequiredClusterId( keepObj.getRequiredClusterId() );
				keyGroupIdx.setRequiredSecGroupId( keepObj.getRequiredSecGroupId() );
				Map<CFSecSecGrpIncPKey, ICFSecSecGrpIncObj > mapGroupIdx = indexByGroupIdx.get( keyGroupIdx );
				if( mapGroupIdx != null ) {
					mapGroupIdx.put( keepObj.getPKey(), keepObj );
				}
			}

			if( indexByIncludeIdx != null ) {
				CFSecSecGrpIncByIncludeIdxKey keyIncludeIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactorySecGrpInc().newIncludeIdxKey();
				keyIncludeIdx.setRequiredClusterId( keepObj.getRequiredClusterId() );
				keyIncludeIdx.setRequiredIncludeGroupId( keepObj.getRequiredIncludeGroupId() );
				Map<CFSecSecGrpIncPKey, ICFSecSecGrpIncObj > mapIncludeIdx = indexByIncludeIdx.get( keyIncludeIdx );
				if( mapIncludeIdx != null ) {
					mapIncludeIdx.put( keepObj.getPKey(), keepObj );
				}
			}

			if( indexByUIncludeIdx != null ) {
				CFSecSecGrpIncByUIncludeIdxKey keyUIncludeIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactorySecGrpInc().newUIncludeIdxKey();
				keyUIncludeIdx.setRequiredClusterId( keepObj.getRequiredClusterId() );
				keyUIncludeIdx.setRequiredSecGroupId( keepObj.getRequiredSecGroupId() );
				keyUIncludeIdx.setRequiredIncludeGroupId( keepObj.getRequiredIncludeGroupId() );
				indexByUIncludeIdx.put( keyUIncludeIdx, keepObj );
			}

			if( allSecGrpInc != null ) {
				allSecGrpInc.put( keepObj.getPKey(), keepObj );
			}
		}
		else {
			keepObj = obj;
			keepObj.setIsNew( false );

			// Attach new object to PKey, all, alternate, and duplicate indexes
			members.put( keepObj.getPKey(), keepObj );
			if( allSecGrpInc != null ) {
				allSecGrpInc.put( keepObj.getPKey(), keepObj );
			}

			if( indexByClusterIdx != null ) {
				CFSecSecGrpIncByClusterIdxKey keyClusterIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactorySecGrpInc().newClusterIdxKey();
				keyClusterIdx.setRequiredClusterId( keepObj.getRequiredClusterId() );
				Map<CFSecSecGrpIncPKey, ICFSecSecGrpIncObj > mapClusterIdx = indexByClusterIdx.get( keyClusterIdx );
				if( mapClusterIdx != null ) {
					mapClusterIdx.put( keepObj.getPKey(), keepObj );
				}
			}

			if( indexByGroupIdx != null ) {
				CFSecSecGrpIncByGroupIdxKey keyGroupIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactorySecGrpInc().newGroupIdxKey();
				keyGroupIdx.setRequiredClusterId( keepObj.getRequiredClusterId() );
				keyGroupIdx.setRequiredSecGroupId( keepObj.getRequiredSecGroupId() );
				Map<CFSecSecGrpIncPKey, ICFSecSecGrpIncObj > mapGroupIdx = indexByGroupIdx.get( keyGroupIdx );
				if( mapGroupIdx != null ) {
					mapGroupIdx.put( keepObj.getPKey(), keepObj );
				}
			}

			if( indexByIncludeIdx != null ) {
				CFSecSecGrpIncByIncludeIdxKey keyIncludeIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactorySecGrpInc().newIncludeIdxKey();
				keyIncludeIdx.setRequiredClusterId( keepObj.getRequiredClusterId() );
				keyIncludeIdx.setRequiredIncludeGroupId( keepObj.getRequiredIncludeGroupId() );
				Map<CFSecSecGrpIncPKey, ICFSecSecGrpIncObj > mapIncludeIdx = indexByIncludeIdx.get( keyIncludeIdx );
				if( mapIncludeIdx != null ) {
					mapIncludeIdx.put( keepObj.getPKey(), keepObj );
				}
			}

			if( indexByUIncludeIdx != null ) {
				CFSecSecGrpIncByUIncludeIdxKey keyUIncludeIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactorySecGrpInc().newUIncludeIdxKey();
				keyUIncludeIdx.setRequiredClusterId( keepObj.getRequiredClusterId() );
				keyUIncludeIdx.setRequiredSecGroupId( keepObj.getRequiredSecGroupId() );
				keyUIncludeIdx.setRequiredIncludeGroupId( keepObj.getRequiredIncludeGroupId() );
				indexByUIncludeIdx.put( keyUIncludeIdx, keepObj );
			}

		}
		return( keepObj );
	}

	public ICFSecSecGrpIncObj createSecGrpInc( ICFSecSecGrpIncObj Obj ) {
		ICFSecSecGrpIncObj obj = Obj;
		CFSecSecGrpIncBuff buff = obj.getSecGrpIncBuff();
		((ICFSecSchema)schema.getBackingStore()).getTableSecGrpInc().createSecGrpInc(
			schema.getAuthorization(),
			buff );
		obj.copyBuffToPKey();
		obj = obj.realise();
		obj.endEdit();
		return( obj );
	}

	public ICFSecSecGrpIncObj readSecGrpInc( CFSecSecGrpIncPKey pkey ) {
		return( readSecGrpInc( pkey, false ) );
	}

	public ICFSecSecGrpIncObj readSecGrpInc( CFSecSecGrpIncPKey pkey, boolean forceRead ) {
		ICFSecSecGrpIncObj obj = null;
		if( ( ! forceRead ) && members.containsKey( pkey ) ) {
			obj = members.get( pkey );
		}
		else {
			CFSecSecGrpIncBuff readBuff = ((ICFSecSchema)schema.getBackingStore()).getTableSecGrpInc().readDerivedByIdIdx( schema.getAuthorization(),
				pkey.getRequiredClusterId(),
				pkey.getRequiredSecGrpIncId() );
			if( readBuff != null ) {
				obj = schema.getSecGrpIncTableObj().newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactorySecGrpInc().newPKey() );
				obj.setBuff( readBuff );
				obj = (ICFSecSecGrpIncObj)obj.realise();
			}
		}
		return( obj );
	}

	public ICFSecSecGrpIncObj readCachedSecGrpInc( CFSecSecGrpIncPKey pkey ) {
		ICFSecSecGrpIncObj obj = null;
		if( members.containsKey( pkey ) ) {
			obj = members.get( pkey );
		}
		return( obj );
	}

	public void reallyDeepDisposeSecGrpInc( ICFSecSecGrpIncObj obj )
	{
		final String S_ProcName = "CFSecSecGrpIncTableObj.reallyDeepDisposeSecGrpInc() ";
		String classCode;
		if( obj == null ) {
			return;
		}
		CFSecSecGrpIncPKey pkey = obj.getPKey();
		ICFSecSecGrpIncObj existing = readCachedSecGrpInc( pkey );
		if( existing == null ) {
			return;
		}
		members.remove( pkey );
		CFSecSecGrpIncByClusterIdxKey keyClusterIdx = ((ICFSecSchema)schema.getBackingStore()).getFactorySecGrpInc().newClusterIdxKey();
		keyClusterIdx.setRequiredClusterId( existing.getRequiredClusterId() );

		CFSecSecGrpIncByGroupIdxKey keyGroupIdx = ((ICFSecSchema)schema.getBackingStore()).getFactorySecGrpInc().newGroupIdxKey();
		keyGroupIdx.setRequiredClusterId( existing.getRequiredClusterId() );
		keyGroupIdx.setRequiredSecGroupId( existing.getRequiredSecGroupId() );

		CFSecSecGrpIncByIncludeIdxKey keyIncludeIdx = ((ICFSecSchema)schema.getBackingStore()).getFactorySecGrpInc().newIncludeIdxKey();
		keyIncludeIdx.setRequiredClusterId( existing.getRequiredClusterId() );
		keyIncludeIdx.setRequiredIncludeGroupId( existing.getRequiredIncludeGroupId() );

		CFSecSecGrpIncByUIncludeIdxKey keyUIncludeIdx = ((ICFSecSchema)schema.getBackingStore()).getFactorySecGrpInc().newUIncludeIdxKey();
		keyUIncludeIdx.setRequiredClusterId( existing.getRequiredClusterId() );
		keyUIncludeIdx.setRequiredSecGroupId( existing.getRequiredSecGroupId() );
		keyUIncludeIdx.setRequiredIncludeGroupId( existing.getRequiredIncludeGroupId() );



		if( indexByClusterIdx != null ) {
			if( indexByClusterIdx.containsKey( keyClusterIdx ) ) {
				indexByClusterIdx.get( keyClusterIdx ).remove( pkey );
				if( indexByClusterIdx.get( keyClusterIdx ).size() <= 0 ) {
					indexByClusterIdx.remove( keyClusterIdx );
				}
			}
		}

		if( indexByGroupIdx != null ) {
			if( indexByGroupIdx.containsKey( keyGroupIdx ) ) {
				indexByGroupIdx.get( keyGroupIdx ).remove( pkey );
				if( indexByGroupIdx.get( keyGroupIdx ).size() <= 0 ) {
					indexByGroupIdx.remove( keyGroupIdx );
				}
			}
		}

		if( indexByIncludeIdx != null ) {
			if( indexByIncludeIdx.containsKey( keyIncludeIdx ) ) {
				indexByIncludeIdx.get( keyIncludeIdx ).remove( pkey );
				if( indexByIncludeIdx.get( keyIncludeIdx ).size() <= 0 ) {
					indexByIncludeIdx.remove( keyIncludeIdx );
				}
			}
		}

		if( indexByUIncludeIdx != null ) {
			indexByUIncludeIdx.remove( keyUIncludeIdx );
		}


	}
	public void deepDisposeSecGrpInc( CFSecSecGrpIncPKey pkey ) {
		ICFSecSecGrpIncObj obj = readCachedSecGrpInc( pkey );
		if( obj != null ) {
			obj.forget();
		}
	}

	public ICFSecSecGrpIncObj lockSecGrpInc( CFSecSecGrpIncPKey pkey ) {
		ICFSecSecGrpIncObj locked = null;
		CFSecSecGrpIncBuff lockBuff = ((ICFSecSchema)schema.getBackingStore()).getTableSecGrpInc().lockDerived( schema.getAuthorization(), pkey );
		if( lockBuff != null ) {
				locked = schema.getSecGrpIncTableObj().newInstance();
			locked.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactorySecGrpInc().newPKey() );
			locked.setBuff( lockBuff );
			locked = (ICFSecSecGrpIncObj)locked.realise();
		}
		else {
			throw new CFLibCollisionDetectedException( getClass(), "lockSecGrpInc", pkey );
		}
		return( locked );
	}

	public List<ICFSecSecGrpIncObj> readAllSecGrpInc() {
		return( readAllSecGrpInc( false ) );
	}

	public List<ICFSecSecGrpIncObj> readAllSecGrpInc( boolean forceRead ) {
		final String S_ProcName = "readAllSecGrpInc";
		if( ( allSecGrpInc == null ) || forceRead ) {
			Map<CFSecSecGrpIncPKey, ICFSecSecGrpIncObj> map = new HashMap<CFSecSecGrpIncPKey,ICFSecSecGrpIncObj>();
			allSecGrpInc = map;
			CFSecSecGrpIncBuff[] buffList = ((ICFSecSchema)schema.getBackingStore()).getTableSecGrpInc().readAllDerived( schema.getAuthorization() );
			CFSecSecGrpIncBuff buff;
			ICFSecSecGrpIncObj obj;
			for( int idx = 0; idx < buffList.length; idx ++ ) {
				buff = buffList[ idx ];
				obj = newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactorySecGrpInc().newPKey() );
				obj.setBuff( buff );
				ICFSecSecGrpIncObj realised = (ICFSecSecGrpIncObj)obj.realise();
			}
		}
		int len = allSecGrpInc.size();
		ICFSecSecGrpIncObj arr[] = new ICFSecSecGrpIncObj[len];
		Iterator<ICFSecSecGrpIncObj> valIter = allSecGrpInc.values().iterator();
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
		ArrayList<ICFSecSecGrpIncObj> arrayList = new ArrayList<ICFSecSecGrpIncObj>(len);
		for( idx = 0; idx < len; idx ++ ) {
			arrayList.add( arr[idx] );
		}

		Comparator<ICFSecSecGrpIncObj> cmp = new Comparator<ICFSecSecGrpIncObj>() {
			public int compare( ICFSecSecGrpIncObj lhs, ICFSecSecGrpIncObj rhs ) {
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
					CFSecSecGrpIncPKey lhsPKey = lhs.getPKey();
					CFSecSecGrpIncPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		List<ICFSecSecGrpIncObj> sortedList = arrayList;
		return( sortedList );
	}

	public List<ICFSecSecGrpIncObj> readCachedAllSecGrpInc() {
		final String S_ProcName = "readCachedAllSecGrpInc";
		ArrayList<ICFSecSecGrpIncObj> arrayList = new ArrayList<ICFSecSecGrpIncObj>();
		if( allSecGrpInc != null ) {
			int len = allSecGrpInc.size();
			ICFSecSecGrpIncObj arr[] = new ICFSecSecGrpIncObj[len];
			Iterator<ICFSecSecGrpIncObj> valIter = allSecGrpInc.values().iterator();
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
		Comparator<ICFSecSecGrpIncObj> cmp = new Comparator<ICFSecSecGrpIncObj>() {
			public int compare( ICFSecSecGrpIncObj lhs, ICFSecSecGrpIncObj rhs ) {
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
					CFSecSecGrpIncPKey lhsPKey = lhs.getPKey();
					CFSecSecGrpIncPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		return( arrayList );
	}

	/**
	 *	Return a sorted map of a page of the SecGrpInc-derived instances in the database.
	 *
	 *	@return	List of ICFSecSecGrpIncObj instance, sorted by their primary keys, which
	 *		may include an empty set.
	 */
	public List<ICFSecSecGrpIncObj> pageAllSecGrpInc(Long priorClusterId,
		Long priorSecGrpIncId )
	{
		final String S_ProcName = "pageAllSecGrpInc";
		Map<CFSecSecGrpIncPKey, ICFSecSecGrpIncObj> map = new HashMap<CFSecSecGrpIncPKey,ICFSecSecGrpIncObj>();
		CFSecSecGrpIncBuff[] buffList = ((ICFSecSchema)schema.getBackingStore()).getTableSecGrpInc().pageAllBuff( schema.getAuthorization(),
			priorClusterId,
			priorSecGrpIncId );
		CFSecSecGrpIncBuff buff;
		ICFSecSecGrpIncObj obj;
		ICFSecSecGrpIncObj realised;
		ArrayList<ICFSecSecGrpIncObj> arrayList = new ArrayList<ICFSecSecGrpIncObj>( buffList.length );
		for( int idx = 0; idx < buffList.length; idx ++ ) {
			buff = buffList[ idx ];
				obj = newInstance();
			obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactorySecGrpInc().newPKey() );
			obj.setBuff( buff );
			realised = (ICFSecSecGrpIncObj)obj.realise();
			arrayList.add( realised );
		}
		return( arrayList );
	}

	public ICFSecSecGrpIncObj readSecGrpIncByIdIdx( long ClusterId,
		long SecGrpIncId )
	{
		return( readSecGrpIncByIdIdx( ClusterId,
			SecGrpIncId,
			false ) );
	}

	public ICFSecSecGrpIncObj readSecGrpIncByIdIdx( long ClusterId,
		long SecGrpIncId, boolean forceRead )
	{
		CFSecSecGrpIncPKey pkey = ((ICFSecSchema)schema.getBackingStore()).getFactorySecGrpInc().newPKey();
		pkey.setRequiredClusterId( ClusterId );
		pkey.setRequiredSecGrpIncId( SecGrpIncId );
		ICFSecSecGrpIncObj obj = readSecGrpInc( pkey, forceRead );
		return( obj );
	}

	public List<ICFSecSecGrpIncObj> readSecGrpIncByClusterIdx( long ClusterId )
	{
		return( readSecGrpIncByClusterIdx( ClusterId,
			false ) );
	}

	public List<ICFSecSecGrpIncObj> readSecGrpIncByClusterIdx( long ClusterId,
		boolean forceRead )
	{
		final String S_ProcName = "readSecGrpIncByClusterIdx";
		CFSecSecGrpIncByClusterIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactorySecGrpInc().newClusterIdxKey();
		key.setRequiredClusterId( ClusterId );
		Map<CFSecSecGrpIncPKey, ICFSecSecGrpIncObj> dict;
		if( indexByClusterIdx == null ) {
			indexByClusterIdx = new HashMap< CFSecSecGrpIncByClusterIdxKey,
				Map< CFSecSecGrpIncPKey, ICFSecSecGrpIncObj > >();
		}
		if( ( ! forceRead ) && indexByClusterIdx.containsKey( key ) ) {
			dict = indexByClusterIdx.get( key );
		}
		else {
			dict = new HashMap<CFSecSecGrpIncPKey, ICFSecSecGrpIncObj>();
			ICFSecSecGrpIncObj obj;
			CFSecSecGrpIncBuff[] buffList = ((ICFSecSchema)schema.getBackingStore()).getTableSecGrpInc().readDerivedByClusterIdx( schema.getAuthorization(),
				ClusterId );
			CFSecSecGrpIncBuff buff;
			for( int idx = 0; idx < buffList.length; idx ++ ) {
				buff = buffList[ idx ];
				obj = schema.getSecGrpIncTableObj().newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactorySecGrpInc().newPKey() );
				obj.setBuff( buff );
				ICFSecSecGrpIncObj realised = (ICFSecSecGrpIncObj)obj.realise();
				dict.put( realised.getPKey(), realised );
			}
			indexByClusterIdx.put( key, dict );
		}
		int len = dict.size();
		ICFSecSecGrpIncObj arr[] = new ICFSecSecGrpIncObj[len];
		Iterator<ICFSecSecGrpIncObj> valIter = dict.values().iterator();
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
		ArrayList<ICFSecSecGrpIncObj> arrayList = new ArrayList<ICFSecSecGrpIncObj>(len);
		for( idx = 0; idx < len; idx ++ ) {
			arrayList.add( arr[idx] );
		}

		Comparator<ICFSecSecGrpIncObj> cmp = new Comparator<ICFSecSecGrpIncObj>() {
			public int compare( ICFSecSecGrpIncObj lhs, ICFSecSecGrpIncObj rhs ) {
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
					CFSecSecGrpIncPKey lhsPKey = lhs.getPKey();
					CFSecSecGrpIncPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		List<ICFSecSecGrpIncObj> sortedList = arrayList;
		return( sortedList );
	}

	public List<ICFSecSecGrpIncObj> readSecGrpIncByGroupIdx( long ClusterId,
		int SecGroupId )
	{
		return( readSecGrpIncByGroupIdx( ClusterId,
			SecGroupId,
			false ) );
	}

	public List<ICFSecSecGrpIncObj> readSecGrpIncByGroupIdx( long ClusterId,
		int SecGroupId,
		boolean forceRead )
	{
		final String S_ProcName = "readSecGrpIncByGroupIdx";
		CFSecSecGrpIncByGroupIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactorySecGrpInc().newGroupIdxKey();
		key.setRequiredClusterId( ClusterId );
		key.setRequiredSecGroupId( SecGroupId );
		Map<CFSecSecGrpIncPKey, ICFSecSecGrpIncObj> dict;
		if( indexByGroupIdx == null ) {
			indexByGroupIdx = new HashMap< CFSecSecGrpIncByGroupIdxKey,
				Map< CFSecSecGrpIncPKey, ICFSecSecGrpIncObj > >();
		}
		if( ( ! forceRead ) && indexByGroupIdx.containsKey( key ) ) {
			dict = indexByGroupIdx.get( key );
		}
		else {
			dict = new HashMap<CFSecSecGrpIncPKey, ICFSecSecGrpIncObj>();
			ICFSecSecGrpIncObj obj;
			CFSecSecGrpIncBuff[] buffList = ((ICFSecSchema)schema.getBackingStore()).getTableSecGrpInc().readDerivedByGroupIdx( schema.getAuthorization(),
				ClusterId,
				SecGroupId );
			CFSecSecGrpIncBuff buff;
			for( int idx = 0; idx < buffList.length; idx ++ ) {
				buff = buffList[ idx ];
				obj = schema.getSecGrpIncTableObj().newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactorySecGrpInc().newPKey() );
				obj.setBuff( buff );
				ICFSecSecGrpIncObj realised = (ICFSecSecGrpIncObj)obj.realise();
				dict.put( realised.getPKey(), realised );
			}
			indexByGroupIdx.put( key, dict );
		}
		int len = dict.size();
		ICFSecSecGrpIncObj arr[] = new ICFSecSecGrpIncObj[len];
		Iterator<ICFSecSecGrpIncObj> valIter = dict.values().iterator();
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
		ArrayList<ICFSecSecGrpIncObj> arrayList = new ArrayList<ICFSecSecGrpIncObj>(len);
		for( idx = 0; idx < len; idx ++ ) {
			arrayList.add( arr[idx] );
		}

		Comparator<ICFSecSecGrpIncObj> cmp = new Comparator<ICFSecSecGrpIncObj>() {
			public int compare( ICFSecSecGrpIncObj lhs, ICFSecSecGrpIncObj rhs ) {
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
					CFSecSecGrpIncPKey lhsPKey = lhs.getPKey();
					CFSecSecGrpIncPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		List<ICFSecSecGrpIncObj> sortedList = arrayList;
		return( sortedList );
	}

	public List<ICFSecSecGrpIncObj> readSecGrpIncByIncludeIdx( long ClusterId,
		int IncludeGroupId )
	{
		return( readSecGrpIncByIncludeIdx( ClusterId,
			IncludeGroupId,
			false ) );
	}

	public List<ICFSecSecGrpIncObj> readSecGrpIncByIncludeIdx( long ClusterId,
		int IncludeGroupId,
		boolean forceRead )
	{
		final String S_ProcName = "readSecGrpIncByIncludeIdx";
		CFSecSecGrpIncByIncludeIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactorySecGrpInc().newIncludeIdxKey();
		key.setRequiredClusterId( ClusterId );
		key.setRequiredIncludeGroupId( IncludeGroupId );
		Map<CFSecSecGrpIncPKey, ICFSecSecGrpIncObj> dict;
		if( indexByIncludeIdx == null ) {
			indexByIncludeIdx = new HashMap< CFSecSecGrpIncByIncludeIdxKey,
				Map< CFSecSecGrpIncPKey, ICFSecSecGrpIncObj > >();
		}
		if( ( ! forceRead ) && indexByIncludeIdx.containsKey( key ) ) {
			dict = indexByIncludeIdx.get( key );
		}
		else {
			dict = new HashMap<CFSecSecGrpIncPKey, ICFSecSecGrpIncObj>();
			ICFSecSecGrpIncObj obj;
			CFSecSecGrpIncBuff[] buffList = ((ICFSecSchema)schema.getBackingStore()).getTableSecGrpInc().readDerivedByIncludeIdx( schema.getAuthorization(),
				ClusterId,
				IncludeGroupId );
			CFSecSecGrpIncBuff buff;
			for( int idx = 0; idx < buffList.length; idx ++ ) {
				buff = buffList[ idx ];
				obj = schema.getSecGrpIncTableObj().newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactorySecGrpInc().newPKey() );
				obj.setBuff( buff );
				ICFSecSecGrpIncObj realised = (ICFSecSecGrpIncObj)obj.realise();
				dict.put( realised.getPKey(), realised );
			}
			indexByIncludeIdx.put( key, dict );
		}
		int len = dict.size();
		ICFSecSecGrpIncObj arr[] = new ICFSecSecGrpIncObj[len];
		Iterator<ICFSecSecGrpIncObj> valIter = dict.values().iterator();
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
		ArrayList<ICFSecSecGrpIncObj> arrayList = new ArrayList<ICFSecSecGrpIncObj>(len);
		for( idx = 0; idx < len; idx ++ ) {
			arrayList.add( arr[idx] );
		}

		Comparator<ICFSecSecGrpIncObj> cmp = new Comparator<ICFSecSecGrpIncObj>() {
			public int compare( ICFSecSecGrpIncObj lhs, ICFSecSecGrpIncObj rhs ) {
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
					CFSecSecGrpIncPKey lhsPKey = lhs.getPKey();
					CFSecSecGrpIncPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		List<ICFSecSecGrpIncObj> sortedList = arrayList;
		return( sortedList );
	}

	public ICFSecSecGrpIncObj readSecGrpIncByUIncludeIdx( long ClusterId,
		int SecGroupId,
		int IncludeGroupId )
	{
		return( readSecGrpIncByUIncludeIdx( ClusterId,
			SecGroupId,
			IncludeGroupId,
			false ) );
	}

	public ICFSecSecGrpIncObj readSecGrpIncByUIncludeIdx( long ClusterId,
		int SecGroupId,
		int IncludeGroupId, boolean forceRead )
	{
		if( indexByUIncludeIdx == null ) {
			indexByUIncludeIdx = new HashMap< CFSecSecGrpIncByUIncludeIdxKey,
				ICFSecSecGrpIncObj >();
		}
		CFSecSecGrpIncByUIncludeIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactorySecGrpInc().newUIncludeIdxKey();
		key.setRequiredClusterId( ClusterId );
		key.setRequiredSecGroupId( SecGroupId );
		key.setRequiredIncludeGroupId( IncludeGroupId );
		ICFSecSecGrpIncObj obj = null;
		if( ( ! forceRead ) && indexByUIncludeIdx.containsKey( key ) ) {
			obj = indexByUIncludeIdx.get( key );
		}
		else {
			CFSecSecGrpIncBuff buff = ((ICFSecSchema)schema.getBackingStore()).getTableSecGrpInc().readDerivedByUIncludeIdx( schema.getAuthorization(),
				ClusterId,
				SecGroupId,
				IncludeGroupId );
			if( buff != null ) {
				obj = schema.getSecGrpIncTableObj().newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactorySecGrpInc().newPKey() );
				obj.setBuff( buff );
				obj = (ICFSecSecGrpIncObj)obj.realise();
			}
		}
		return( obj );
	}

	public ICFSecSecGrpIncObj readCachedSecGrpIncByIdIdx( long ClusterId,
		long SecGrpIncId )
	{
		ICFSecSecGrpIncObj obj = null;
		CFSecSecGrpIncPKey pkey = ((ICFSecSchema)schema.getBackingStore()).getFactorySecGrpInc().newPKey();
		pkey.setRequiredClusterId( ClusterId );
		pkey.setRequiredSecGrpIncId( SecGrpIncId );
		obj = readCachedSecGrpInc( pkey );
		return( obj );
	}

	public List<ICFSecSecGrpIncObj> readCachedSecGrpIncByClusterIdx( long ClusterId )
	{
		final String S_ProcName = "readCachedSecGrpIncByClusterIdx";
		CFSecSecGrpIncByClusterIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactorySecGrpInc().newClusterIdxKey();
		key.setRequiredClusterId( ClusterId );
		ArrayList<ICFSecSecGrpIncObj> arrayList = new ArrayList<ICFSecSecGrpIncObj>();
		if( indexByClusterIdx != null ) {
			Map<CFSecSecGrpIncPKey, ICFSecSecGrpIncObj> dict;
			if( indexByClusterIdx.containsKey( key ) ) {
				dict = indexByClusterIdx.get( key );
				int len = dict.size();
				ICFSecSecGrpIncObj arr[] = new ICFSecSecGrpIncObj[len];
				Iterator<ICFSecSecGrpIncObj> valIter = dict.values().iterator();
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
			ICFSecSecGrpIncObj obj;
			Iterator<ICFSecSecGrpIncObj> valIter = members.values().iterator();
			while( valIter.hasNext() ) {
				obj = valIter.next();
				if( obj != null ) {
					if( obj.getBuff().compareTo( key ) == 0 ) {
						arrayList.add( obj );
					}
				}
			}
		}
		Comparator<ICFSecSecGrpIncObj> cmp = new Comparator<ICFSecSecGrpIncObj>() {
			public int compare( ICFSecSecGrpIncObj lhs, ICFSecSecGrpIncObj rhs ) {
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
					CFSecSecGrpIncPKey lhsPKey = lhs.getPKey();
					CFSecSecGrpIncPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		return( arrayList );
	}

	public List<ICFSecSecGrpIncObj> readCachedSecGrpIncByGroupIdx( long ClusterId,
		int SecGroupId )
	{
		final String S_ProcName = "readCachedSecGrpIncByGroupIdx";
		CFSecSecGrpIncByGroupIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactorySecGrpInc().newGroupIdxKey();
		key.setRequiredClusterId( ClusterId );
		key.setRequiredSecGroupId( SecGroupId );
		ArrayList<ICFSecSecGrpIncObj> arrayList = new ArrayList<ICFSecSecGrpIncObj>();
		if( indexByGroupIdx != null ) {
			Map<CFSecSecGrpIncPKey, ICFSecSecGrpIncObj> dict;
			if( indexByGroupIdx.containsKey( key ) ) {
				dict = indexByGroupIdx.get( key );
				int len = dict.size();
				ICFSecSecGrpIncObj arr[] = new ICFSecSecGrpIncObj[len];
				Iterator<ICFSecSecGrpIncObj> valIter = dict.values().iterator();
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
			ICFSecSecGrpIncObj obj;
			Iterator<ICFSecSecGrpIncObj> valIter = members.values().iterator();
			while( valIter.hasNext() ) {
				obj = valIter.next();
				if( obj != null ) {
					if( obj.getBuff().compareTo( key ) == 0 ) {
						arrayList.add( obj );
					}
				}
			}
		}
		Comparator<ICFSecSecGrpIncObj> cmp = new Comparator<ICFSecSecGrpIncObj>() {
			public int compare( ICFSecSecGrpIncObj lhs, ICFSecSecGrpIncObj rhs ) {
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
					CFSecSecGrpIncPKey lhsPKey = lhs.getPKey();
					CFSecSecGrpIncPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		return( arrayList );
	}

	public List<ICFSecSecGrpIncObj> readCachedSecGrpIncByIncludeIdx( long ClusterId,
		int IncludeGroupId )
	{
		final String S_ProcName = "readCachedSecGrpIncByIncludeIdx";
		CFSecSecGrpIncByIncludeIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactorySecGrpInc().newIncludeIdxKey();
		key.setRequiredClusterId( ClusterId );
		key.setRequiredIncludeGroupId( IncludeGroupId );
		ArrayList<ICFSecSecGrpIncObj> arrayList = new ArrayList<ICFSecSecGrpIncObj>();
		if( indexByIncludeIdx != null ) {
			Map<CFSecSecGrpIncPKey, ICFSecSecGrpIncObj> dict;
			if( indexByIncludeIdx.containsKey( key ) ) {
				dict = indexByIncludeIdx.get( key );
				int len = dict.size();
				ICFSecSecGrpIncObj arr[] = new ICFSecSecGrpIncObj[len];
				Iterator<ICFSecSecGrpIncObj> valIter = dict.values().iterator();
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
			ICFSecSecGrpIncObj obj;
			Iterator<ICFSecSecGrpIncObj> valIter = members.values().iterator();
			while( valIter.hasNext() ) {
				obj = valIter.next();
				if( obj != null ) {
					if( obj.getBuff().compareTo( key ) == 0 ) {
						arrayList.add( obj );
					}
				}
			}
		}
		Comparator<ICFSecSecGrpIncObj> cmp = new Comparator<ICFSecSecGrpIncObj>() {
			public int compare( ICFSecSecGrpIncObj lhs, ICFSecSecGrpIncObj rhs ) {
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
					CFSecSecGrpIncPKey lhsPKey = lhs.getPKey();
					CFSecSecGrpIncPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		return( arrayList );
	}

	public ICFSecSecGrpIncObj readCachedSecGrpIncByUIncludeIdx( long ClusterId,
		int SecGroupId,
		int IncludeGroupId )
	{
		ICFSecSecGrpIncObj obj = null;
		CFSecSecGrpIncByUIncludeIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactorySecGrpInc().newUIncludeIdxKey();
		key.setRequiredClusterId( ClusterId );
		key.setRequiredSecGroupId( SecGroupId );
		key.setRequiredIncludeGroupId( IncludeGroupId );
		if( indexByUIncludeIdx != null ) {
			if( indexByUIncludeIdx.containsKey( key ) ) {
				obj = indexByUIncludeIdx.get( key );
			}
			else {
				Iterator<ICFSecSecGrpIncObj> valIter = members.values().iterator();
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
			Iterator<ICFSecSecGrpIncObj> valIter = members.values().iterator();
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

	public void deepDisposeSecGrpIncByIdIdx( long ClusterId,
		long SecGrpIncId )
	{
		ICFSecSecGrpIncObj obj = readCachedSecGrpIncByIdIdx( ClusterId,
				SecGrpIncId );
		if( obj != null ) {
			obj.forget();
		}
	}

	public void deepDisposeSecGrpIncByClusterIdx( long ClusterId )
	{
		final String S_ProcName = "deepDisposeSecGrpIncByClusterIdx";
		ICFSecSecGrpIncObj obj;
		List<ICFSecSecGrpIncObj> arrayList = readCachedSecGrpIncByClusterIdx( ClusterId );
		if( arrayList != null )  {
			Iterator<ICFSecSecGrpIncObj> arrayIter = arrayList.iterator();
			while( arrayIter.hasNext() ) {
				obj = arrayIter.next();
				if( obj != null ) {
					obj.forget();
				}
			}
		}
	}

	public void deepDisposeSecGrpIncByGroupIdx( long ClusterId,
		int SecGroupId )
	{
		final String S_ProcName = "deepDisposeSecGrpIncByGroupIdx";
		ICFSecSecGrpIncObj obj;
		List<ICFSecSecGrpIncObj> arrayList = readCachedSecGrpIncByGroupIdx( ClusterId,
				SecGroupId );
		if( arrayList != null )  {
			Iterator<ICFSecSecGrpIncObj> arrayIter = arrayList.iterator();
			while( arrayIter.hasNext() ) {
				obj = arrayIter.next();
				if( obj != null ) {
					obj.forget();
				}
			}
		}
	}

	public void deepDisposeSecGrpIncByIncludeIdx( long ClusterId,
		int IncludeGroupId )
	{
		final String S_ProcName = "deepDisposeSecGrpIncByIncludeIdx";
		ICFSecSecGrpIncObj obj;
		List<ICFSecSecGrpIncObj> arrayList = readCachedSecGrpIncByIncludeIdx( ClusterId,
				IncludeGroupId );
		if( arrayList != null )  {
			Iterator<ICFSecSecGrpIncObj> arrayIter = arrayList.iterator();
			while( arrayIter.hasNext() ) {
				obj = arrayIter.next();
				if( obj != null ) {
					obj.forget();
				}
			}
		}
	}

	public void deepDisposeSecGrpIncByUIncludeIdx( long ClusterId,
		int SecGroupId,
		int IncludeGroupId )
	{
		ICFSecSecGrpIncObj obj = readCachedSecGrpIncByUIncludeIdx( ClusterId,
				SecGroupId,
				IncludeGroupId );
		if( obj != null ) {
			obj.forget();
		}
	}

	/**
	 *	Read a page of data as a List of SecGrpInc-derived instances sorted by their primary keys,
	 *	as identified by the duplicate ClusterIdx key attributes.
	 *
	 *	@param	argClusterId	The SecGrpInc key attribute of the instance generating the id.
	 *
	 *	@return	A List of SecGrpInc-derived instances sorted by their primary keys,
	 *		as identified by the key attributes, which may be an empty set.
	 */
	public List<ICFSecSecGrpIncObj> pageSecGrpIncByClusterIdx( long ClusterId,
		Long priorClusterId,
		Long priorSecGrpIncId )
	{
		final String S_ProcName = "pageSecGrpIncByClusterIdx";
		CFSecSecGrpIncByClusterIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactorySecGrpInc().newClusterIdxKey();
		key.setRequiredClusterId( ClusterId );
		List<ICFSecSecGrpIncObj> retList = new LinkedList<ICFSecSecGrpIncObj>();
		ICFSecSecGrpIncObj obj;
		CFSecSecGrpIncBuff[] buffList = ((ICFSecSchema)schema.getBackingStore()).getTableSecGrpInc().pageBuffByClusterIdx( schema.getAuthorization(),
				ClusterId,
			priorClusterId,
			priorSecGrpIncId );
		CFSecSecGrpIncBuff buff;
		for( int idx = 0; idx < buffList.length; idx ++ ) {
			buff = buffList[ idx ];
				obj = schema.getSecGrpIncTableObj().newInstance();
			obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactorySecGrpInc().newPKey() );
			obj.setBuff( buff );
			ICFSecSecGrpIncObj realised = (ICFSecSecGrpIncObj)obj.realise();
			retList.add( realised );
		}
		return( retList );
	}

	/**
	 *	Read a page of data as a List of SecGrpInc-derived instances sorted by their primary keys,
	 *	as identified by the duplicate GroupIdx key attributes.
	 *
	 *	@param	argClusterId	The SecGrpInc key attribute of the instance generating the id.
	 *
	 *	@param	argSecGroupId	The SecGrpInc key attribute of the instance generating the id.
	 *
	 *	@return	A List of SecGrpInc-derived instances sorted by their primary keys,
	 *		as identified by the key attributes, which may be an empty set.
	 */
	public List<ICFSecSecGrpIncObj> pageSecGrpIncByGroupIdx( long ClusterId,
		int SecGroupId,
		Long priorClusterId,
		Long priorSecGrpIncId )
	{
		final String S_ProcName = "pageSecGrpIncByGroupIdx";
		CFSecSecGrpIncByGroupIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactorySecGrpInc().newGroupIdxKey();
		key.setRequiredClusterId( ClusterId );
		key.setRequiredSecGroupId( SecGroupId );
		List<ICFSecSecGrpIncObj> retList = new LinkedList<ICFSecSecGrpIncObj>();
		ICFSecSecGrpIncObj obj;
		CFSecSecGrpIncBuff[] buffList = ((ICFSecSchema)schema.getBackingStore()).getTableSecGrpInc().pageBuffByGroupIdx( schema.getAuthorization(),
				ClusterId,
				SecGroupId,
			priorClusterId,
			priorSecGrpIncId );
		CFSecSecGrpIncBuff buff;
		for( int idx = 0; idx < buffList.length; idx ++ ) {
			buff = buffList[ idx ];
				obj = schema.getSecGrpIncTableObj().newInstance();
			obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactorySecGrpInc().newPKey() );
			obj.setBuff( buff );
			ICFSecSecGrpIncObj realised = (ICFSecSecGrpIncObj)obj.realise();
			retList.add( realised );
		}
		return( retList );
	}

	/**
	 *	Read a page of data as a List of SecGrpInc-derived instances sorted by their primary keys,
	 *	as identified by the duplicate IncludeIdx key attributes.
	 *
	 *	@param	argClusterId	The SecGrpInc key attribute of the instance generating the id.
	 *
	 *	@param	argIncludeGroupId	The SecGrpInc key attribute of the instance generating the id.
	 *
	 *	@return	A List of SecGrpInc-derived instances sorted by their primary keys,
	 *		as identified by the key attributes, which may be an empty set.
	 */
	public List<ICFSecSecGrpIncObj> pageSecGrpIncByIncludeIdx( long ClusterId,
		int IncludeGroupId,
		Long priorClusterId,
		Long priorSecGrpIncId )
	{
		final String S_ProcName = "pageSecGrpIncByIncludeIdx";
		CFSecSecGrpIncByIncludeIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactorySecGrpInc().newIncludeIdxKey();
		key.setRequiredClusterId( ClusterId );
		key.setRequiredIncludeGroupId( IncludeGroupId );
		List<ICFSecSecGrpIncObj> retList = new LinkedList<ICFSecSecGrpIncObj>();
		ICFSecSecGrpIncObj obj;
		CFSecSecGrpIncBuff[] buffList = ((ICFSecSchema)schema.getBackingStore()).getTableSecGrpInc().pageBuffByIncludeIdx( schema.getAuthorization(),
				ClusterId,
				IncludeGroupId,
			priorClusterId,
			priorSecGrpIncId );
		CFSecSecGrpIncBuff buff;
		for( int idx = 0; idx < buffList.length; idx ++ ) {
			buff = buffList[ idx ];
				obj = schema.getSecGrpIncTableObj().newInstance();
			obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactorySecGrpInc().newPKey() );
			obj.setBuff( buff );
			ICFSecSecGrpIncObj realised = (ICFSecSecGrpIncObj)obj.realise();
			retList.add( realised );
		}
		return( retList );
	}

	public ICFSecSecGrpIncObj updateSecGrpInc( ICFSecSecGrpIncObj Obj ) {
		ICFSecSecGrpIncObj obj = Obj;
		((ICFSecSchema)schema.getBackingStore()).getTableSecGrpInc().updateSecGrpInc( schema.getAuthorization(),
			Obj.getSecGrpIncBuff() );
		obj = (ICFSecSecGrpIncObj)Obj.realise();
		obj.endEdit();
		return( obj );
	}

	public void deleteSecGrpInc( ICFSecSecGrpIncObj Obj ) {
		ICFSecSecGrpIncObj obj = Obj;
		((ICFSecSchema)schema.getBackingStore()).getTableSecGrpInc().deleteSecGrpInc( schema.getAuthorization(),
			obj.getSecGrpIncBuff() );
		Obj.forget();
	}

	public void deleteSecGrpIncByIdIdx( long ClusterId,
		long SecGrpIncId )
	{
		CFSecSecGrpIncPKey pkey = ((ICFSecSchema)schema.getBackingStore()).getFactorySecGrpInc().newPKey();
		pkey.setRequiredClusterId( ClusterId );
		pkey.setRequiredSecGrpIncId( SecGrpIncId );
		ICFSecSecGrpIncObj obj = readSecGrpInc( pkey );
		if( obj != null ) {
			ICFSecSecGrpIncEditObj editObj = (ICFSecSecGrpIncEditObj)obj.getEdit();
			boolean editStarted;
			if( editObj == null ) {
				editObj = (ICFSecSecGrpIncEditObj)obj.beginEdit();
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
		deepDisposeSecGrpIncByIdIdx( ClusterId,
				SecGrpIncId );
	}

	public void deleteSecGrpIncByClusterIdx( long ClusterId )
	{
		CFSecSecGrpIncByClusterIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactorySecGrpInc().newClusterIdxKey();
		key.setRequiredClusterId( ClusterId );
		if( indexByClusterIdx == null ) {
			indexByClusterIdx = new HashMap< CFSecSecGrpIncByClusterIdxKey,
				Map< CFSecSecGrpIncPKey, ICFSecSecGrpIncObj > >();
		}
		if( indexByClusterIdx.containsKey( key ) ) {
			Map<CFSecSecGrpIncPKey, ICFSecSecGrpIncObj> dict = indexByClusterIdx.get( key );
			((ICFSecSchema)schema.getBackingStore()).getTableSecGrpInc().deleteSecGrpIncByClusterIdx( schema.getAuthorization(),
				ClusterId );
			Iterator<ICFSecSecGrpIncObj> iter = dict.values().iterator();
			ICFSecSecGrpIncObj obj;
			List<ICFSecSecGrpIncObj> toForget = new LinkedList<ICFSecSecGrpIncObj>();
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
			((ICFSecSchema)schema.getBackingStore()).getTableSecGrpInc().deleteSecGrpIncByClusterIdx( schema.getAuthorization(),
				ClusterId );
		}
		deepDisposeSecGrpIncByClusterIdx( ClusterId );
	}

	public void deleteSecGrpIncByGroupIdx( long ClusterId,
		int SecGroupId )
	{
		CFSecSecGrpIncByGroupIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactorySecGrpInc().newGroupIdxKey();
		key.setRequiredClusterId( ClusterId );
		key.setRequiredSecGroupId( SecGroupId );
		if( indexByGroupIdx == null ) {
			indexByGroupIdx = new HashMap< CFSecSecGrpIncByGroupIdxKey,
				Map< CFSecSecGrpIncPKey, ICFSecSecGrpIncObj > >();
		}
		if( indexByGroupIdx.containsKey( key ) ) {
			Map<CFSecSecGrpIncPKey, ICFSecSecGrpIncObj> dict = indexByGroupIdx.get( key );
			((ICFSecSchema)schema.getBackingStore()).getTableSecGrpInc().deleteSecGrpIncByGroupIdx( schema.getAuthorization(),
				ClusterId,
				SecGroupId );
			Iterator<ICFSecSecGrpIncObj> iter = dict.values().iterator();
			ICFSecSecGrpIncObj obj;
			List<ICFSecSecGrpIncObj> toForget = new LinkedList<ICFSecSecGrpIncObj>();
			while( iter.hasNext() ) {
				obj = iter.next();
				toForget.add( obj );
			}
			iter = toForget.iterator();
			while( iter.hasNext() ) {
				obj = iter.next();
				obj.forget();
			}
			indexByGroupIdx.remove( key );
		}
		else {
			((ICFSecSchema)schema.getBackingStore()).getTableSecGrpInc().deleteSecGrpIncByGroupIdx( schema.getAuthorization(),
				ClusterId,
				SecGroupId );
		}
		deepDisposeSecGrpIncByGroupIdx( ClusterId,
				SecGroupId );
	}

	public void deleteSecGrpIncByIncludeIdx( long ClusterId,
		int IncludeGroupId )
	{
		CFSecSecGrpIncByIncludeIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactorySecGrpInc().newIncludeIdxKey();
		key.setRequiredClusterId( ClusterId );
		key.setRequiredIncludeGroupId( IncludeGroupId );
		if( indexByIncludeIdx == null ) {
			indexByIncludeIdx = new HashMap< CFSecSecGrpIncByIncludeIdxKey,
				Map< CFSecSecGrpIncPKey, ICFSecSecGrpIncObj > >();
		}
		if( indexByIncludeIdx.containsKey( key ) ) {
			Map<CFSecSecGrpIncPKey, ICFSecSecGrpIncObj> dict = indexByIncludeIdx.get( key );
			((ICFSecSchema)schema.getBackingStore()).getTableSecGrpInc().deleteSecGrpIncByIncludeIdx( schema.getAuthorization(),
				ClusterId,
				IncludeGroupId );
			Iterator<ICFSecSecGrpIncObj> iter = dict.values().iterator();
			ICFSecSecGrpIncObj obj;
			List<ICFSecSecGrpIncObj> toForget = new LinkedList<ICFSecSecGrpIncObj>();
			while( iter.hasNext() ) {
				obj = iter.next();
				toForget.add( obj );
			}
			iter = toForget.iterator();
			while( iter.hasNext() ) {
				obj = iter.next();
				obj.forget();
			}
			indexByIncludeIdx.remove( key );
		}
		else {
			((ICFSecSchema)schema.getBackingStore()).getTableSecGrpInc().deleteSecGrpIncByIncludeIdx( schema.getAuthorization(),
				ClusterId,
				IncludeGroupId );
		}
		deepDisposeSecGrpIncByIncludeIdx( ClusterId,
				IncludeGroupId );
	}

	public void deleteSecGrpIncByUIncludeIdx( long ClusterId,
		int SecGroupId,
		int IncludeGroupId )
	{
		if( indexByUIncludeIdx == null ) {
			indexByUIncludeIdx = new HashMap< CFSecSecGrpIncByUIncludeIdxKey,
				ICFSecSecGrpIncObj >();
		}
		CFSecSecGrpIncByUIncludeIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactorySecGrpInc().newUIncludeIdxKey();
		key.setRequiredClusterId( ClusterId );
		key.setRequiredSecGroupId( SecGroupId );
		key.setRequiredIncludeGroupId( IncludeGroupId );
		ICFSecSecGrpIncObj obj = null;
		if( indexByUIncludeIdx.containsKey( key ) ) {
			obj = indexByUIncludeIdx.get( key );
			((ICFSecSchema)schema.getBackingStore()).getTableSecGrpInc().deleteSecGrpIncByUIncludeIdx( schema.getAuthorization(),
				ClusterId,
				SecGroupId,
				IncludeGroupId );
			obj.forget();
		}
		else {
			((ICFSecSchema)schema.getBackingStore()).getTableSecGrpInc().deleteSecGrpIncByUIncludeIdx( schema.getAuthorization(),
				ClusterId,
				SecGroupId,
				IncludeGroupId );
		}
		deepDisposeSecGrpIncByUIncludeIdx( ClusterId,
				SecGroupId,
				IncludeGroupId );
	}
}
