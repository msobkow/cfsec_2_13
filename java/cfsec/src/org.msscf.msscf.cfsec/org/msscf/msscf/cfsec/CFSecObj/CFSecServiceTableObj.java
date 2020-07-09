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
import com.github.msobkow.cflib.CFLib.*;
import org.msscf.msscf.cfsec.CFSec.*;

public class CFSecServiceTableObj
	implements ICFSecServiceTableObj
{
	protected ICFSecSchemaObj schema;
	private Map<CFSecServicePKey, ICFSecServiceObj> members;
	private Map<CFSecServicePKey, ICFSecServiceObj> allService;
	private Map< CFSecServiceByClusterIdxKey,
		Map<CFSecServicePKey, ICFSecServiceObj > > indexByClusterIdx;
	private Map< CFSecServiceByHostIdxKey,
		Map<CFSecServicePKey, ICFSecServiceObj > > indexByHostIdx;
	private Map< CFSecServiceByTypeIdxKey,
		Map<CFSecServicePKey, ICFSecServiceObj > > indexByTypeIdx;
	private Map< CFSecServiceByUTypeIdxKey,
		ICFSecServiceObj > indexByUTypeIdx;
	private Map< CFSecServiceByUHostPortIdxKey,
		ICFSecServiceObj > indexByUHostPortIdx;
	public static String TABLE_NAME = "Service";
	public static String TABLE_DBNAME = "hostsvc";

	public CFSecServiceTableObj() {
		schema = null;
		members = new HashMap<CFSecServicePKey, ICFSecServiceObj>();
		allService = null;
		indexByClusterIdx = null;
		indexByHostIdx = null;
		indexByTypeIdx = null;
		indexByUTypeIdx = null;
		indexByUHostPortIdx = null;
	}

	public CFSecServiceTableObj( ICFSecSchemaObj argSchema ) {
		schema = (ICFSecSchemaObj)argSchema;
		members = new HashMap<CFSecServicePKey, ICFSecServiceObj>();
		allService = null;
		indexByClusterIdx = null;
		indexByHostIdx = null;
		indexByTypeIdx = null;
		indexByUTypeIdx = null;
		indexByUHostPortIdx = null;
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
		allService = null;
		indexByClusterIdx = null;
		indexByHostIdx = null;
		indexByTypeIdx = null;
		indexByUTypeIdx = null;
		indexByUHostPortIdx = null;
		List<ICFSecServiceObj> toForget = new LinkedList<ICFSecServiceObj>();
		ICFSecServiceObj cur = null;
		Iterator<ICFSecServiceObj> iter = members.values().iterator();
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
	 *	CFSecServiceObj.
	 */
	public ICFSecServiceObj newInstance() {
		ICFSecServiceObj inst = new CFSecServiceObj( schema );
		return( inst );
	}

	/**
	 *	If your implementation subclasses the objects,
	 *	you'll want to overload the constructByClassCode()
	 *	implementation to return your implementation's
	 *	instances instead of the base implementation.
	 *
	 *	This is the sole factory for instances derived from
	 *	CFSecServiceObj.
	 */
	public ICFSecServiceEditObj newEditInstance( ICFSecServiceObj orig ) {
		ICFSecServiceEditObj edit = new CFSecServiceEditObj( orig );
		return( edit );
	}

	public ICFSecServiceObj realiseService( ICFSecServiceObj Obj ) {
		ICFSecServiceObj obj = Obj;
		CFSecServicePKey pkey = obj.getPKey();
		ICFSecServiceObj keepObj = null;
		if( members.containsKey( pkey ) && ( null != members.get( pkey ) ) ) {
			ICFSecServiceObj existingObj = members.get( pkey );
			keepObj = existingObj;

			/*
			 *	We always rebind the data because if we're being called, some index has
			 *	been updated and is refreshing it's data, which may or may not have changed
			 */

			// Detach object from alternate and duplicate indexes, leave PKey alone

			if( indexByClusterIdx != null ) {
				CFSecServiceByClusterIdxKey keyClusterIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryService().newClusterIdxKey();
				keyClusterIdx.setRequiredClusterId( keepObj.getRequiredClusterId() );
				Map<CFSecServicePKey, ICFSecServiceObj > mapClusterIdx = indexByClusterIdx.get( keyClusterIdx );
				if( mapClusterIdx != null ) {
					mapClusterIdx.remove( keepObj.getPKey() );
					if( mapClusterIdx.size() <= 0 ) {
						indexByClusterIdx.remove( keyClusterIdx );
					}
				}
			}

			if( indexByHostIdx != null ) {
				CFSecServiceByHostIdxKey keyHostIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryService().newHostIdxKey();
				keyHostIdx.setRequiredClusterId( keepObj.getRequiredClusterId() );
				keyHostIdx.setRequiredHostNodeId( keepObj.getRequiredHostNodeId() );
				Map<CFSecServicePKey, ICFSecServiceObj > mapHostIdx = indexByHostIdx.get( keyHostIdx );
				if( mapHostIdx != null ) {
					mapHostIdx.remove( keepObj.getPKey() );
					if( mapHostIdx.size() <= 0 ) {
						indexByHostIdx.remove( keyHostIdx );
					}
				}
			}

			if( indexByTypeIdx != null ) {
				CFSecServiceByTypeIdxKey keyTypeIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryService().newTypeIdxKey();
				keyTypeIdx.setRequiredServiceTypeId( keepObj.getRequiredServiceTypeId() );
				Map<CFSecServicePKey, ICFSecServiceObj > mapTypeIdx = indexByTypeIdx.get( keyTypeIdx );
				if( mapTypeIdx != null ) {
					mapTypeIdx.remove( keepObj.getPKey() );
					if( mapTypeIdx.size() <= 0 ) {
						indexByTypeIdx.remove( keyTypeIdx );
					}
				}
			}

			if( indexByUTypeIdx != null ) {
				CFSecServiceByUTypeIdxKey keyUTypeIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryService().newUTypeIdxKey();
				keyUTypeIdx.setRequiredClusterId( keepObj.getRequiredClusterId() );
				keyUTypeIdx.setRequiredHostNodeId( keepObj.getRequiredHostNodeId() );
				keyUTypeIdx.setRequiredServiceTypeId( keepObj.getRequiredServiceTypeId() );
				indexByUTypeIdx.remove( keyUTypeIdx );
			}

			if( indexByUHostPortIdx != null ) {
				CFSecServiceByUHostPortIdxKey keyUHostPortIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryService().newUHostPortIdxKey();
				keyUHostPortIdx.setRequiredClusterId( keepObj.getRequiredClusterId() );
				keyUHostPortIdx.setRequiredHostNodeId( keepObj.getRequiredHostNodeId() );
				keyUHostPortIdx.setRequiredHostPort( keepObj.getRequiredHostPort() );
				indexByUHostPortIdx.remove( keyUHostPortIdx );
			}

			keepObj.setBuff( Obj.getBuff() );
			// Attach new object to alternate and duplicate indexes -- PKey stay stable

			if( indexByClusterIdx != null ) {
				CFSecServiceByClusterIdxKey keyClusterIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryService().newClusterIdxKey();
				keyClusterIdx.setRequiredClusterId( keepObj.getRequiredClusterId() );
				Map<CFSecServicePKey, ICFSecServiceObj > mapClusterIdx = indexByClusterIdx.get( keyClusterIdx );
				if( mapClusterIdx != null ) {
					mapClusterIdx.put( keepObj.getPKey(), keepObj );
				}
			}

			if( indexByHostIdx != null ) {
				CFSecServiceByHostIdxKey keyHostIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryService().newHostIdxKey();
				keyHostIdx.setRequiredClusterId( keepObj.getRequiredClusterId() );
				keyHostIdx.setRequiredHostNodeId( keepObj.getRequiredHostNodeId() );
				Map<CFSecServicePKey, ICFSecServiceObj > mapHostIdx = indexByHostIdx.get( keyHostIdx );
				if( mapHostIdx != null ) {
					mapHostIdx.put( keepObj.getPKey(), keepObj );
				}
			}

			if( indexByTypeIdx != null ) {
				CFSecServiceByTypeIdxKey keyTypeIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryService().newTypeIdxKey();
				keyTypeIdx.setRequiredServiceTypeId( keepObj.getRequiredServiceTypeId() );
				Map<CFSecServicePKey, ICFSecServiceObj > mapTypeIdx = indexByTypeIdx.get( keyTypeIdx );
				if( mapTypeIdx != null ) {
					mapTypeIdx.put( keepObj.getPKey(), keepObj );
				}
			}

			if( indexByUTypeIdx != null ) {
				CFSecServiceByUTypeIdxKey keyUTypeIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryService().newUTypeIdxKey();
				keyUTypeIdx.setRequiredClusterId( keepObj.getRequiredClusterId() );
				keyUTypeIdx.setRequiredHostNodeId( keepObj.getRequiredHostNodeId() );
				keyUTypeIdx.setRequiredServiceTypeId( keepObj.getRequiredServiceTypeId() );
				indexByUTypeIdx.put( keyUTypeIdx, keepObj );
			}

			if( indexByUHostPortIdx != null ) {
				CFSecServiceByUHostPortIdxKey keyUHostPortIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryService().newUHostPortIdxKey();
				keyUHostPortIdx.setRequiredClusterId( keepObj.getRequiredClusterId() );
				keyUHostPortIdx.setRequiredHostNodeId( keepObj.getRequiredHostNodeId() );
				keyUHostPortIdx.setRequiredHostPort( keepObj.getRequiredHostPort() );
				indexByUHostPortIdx.put( keyUHostPortIdx, keepObj );
			}

			if( allService != null ) {
				allService.put( keepObj.getPKey(), keepObj );
			}
		}
		else {
			keepObj = obj;
			keepObj.setIsNew( false );

			// Attach new object to PKey, all, alternate, and duplicate indexes
			members.put( keepObj.getPKey(), keepObj );
			if( allService != null ) {
				allService.put( keepObj.getPKey(), keepObj );
			}

			if( indexByClusterIdx != null ) {
				CFSecServiceByClusterIdxKey keyClusterIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryService().newClusterIdxKey();
				keyClusterIdx.setRequiredClusterId( keepObj.getRequiredClusterId() );
				Map<CFSecServicePKey, ICFSecServiceObj > mapClusterIdx = indexByClusterIdx.get( keyClusterIdx );
				if( mapClusterIdx != null ) {
					mapClusterIdx.put( keepObj.getPKey(), keepObj );
				}
			}

			if( indexByHostIdx != null ) {
				CFSecServiceByHostIdxKey keyHostIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryService().newHostIdxKey();
				keyHostIdx.setRequiredClusterId( keepObj.getRequiredClusterId() );
				keyHostIdx.setRequiredHostNodeId( keepObj.getRequiredHostNodeId() );
				Map<CFSecServicePKey, ICFSecServiceObj > mapHostIdx = indexByHostIdx.get( keyHostIdx );
				if( mapHostIdx != null ) {
					mapHostIdx.put( keepObj.getPKey(), keepObj );
				}
			}

			if( indexByTypeIdx != null ) {
				CFSecServiceByTypeIdxKey keyTypeIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryService().newTypeIdxKey();
				keyTypeIdx.setRequiredServiceTypeId( keepObj.getRequiredServiceTypeId() );
				Map<CFSecServicePKey, ICFSecServiceObj > mapTypeIdx = indexByTypeIdx.get( keyTypeIdx );
				if( mapTypeIdx != null ) {
					mapTypeIdx.put( keepObj.getPKey(), keepObj );
				}
			}

			if( indexByUTypeIdx != null ) {
				CFSecServiceByUTypeIdxKey keyUTypeIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryService().newUTypeIdxKey();
				keyUTypeIdx.setRequiredClusterId( keepObj.getRequiredClusterId() );
				keyUTypeIdx.setRequiredHostNodeId( keepObj.getRequiredHostNodeId() );
				keyUTypeIdx.setRequiredServiceTypeId( keepObj.getRequiredServiceTypeId() );
				indexByUTypeIdx.put( keyUTypeIdx, keepObj );
			}

			if( indexByUHostPortIdx != null ) {
				CFSecServiceByUHostPortIdxKey keyUHostPortIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryService().newUHostPortIdxKey();
				keyUHostPortIdx.setRequiredClusterId( keepObj.getRequiredClusterId() );
				keyUHostPortIdx.setRequiredHostNodeId( keepObj.getRequiredHostNodeId() );
				keyUHostPortIdx.setRequiredHostPort( keepObj.getRequiredHostPort() );
				indexByUHostPortIdx.put( keyUHostPortIdx, keepObj );
			}

		}
		return( keepObj );
	}

	public ICFSecServiceObj createService( ICFSecServiceObj Obj ) {
		ICFSecServiceObj obj = Obj;
		CFSecServiceBuff buff = obj.getServiceBuff();
		((ICFSecSchema)schema.getBackingStore()).getTableService().createService(
			schema.getAuthorization(),
			buff );
		obj.copyBuffToPKey();
		obj = obj.realise();
		obj.endEdit();
		return( obj );
	}

	public ICFSecServiceObj readService( CFSecServicePKey pkey ) {
		return( readService( pkey, false ) );
	}

	public ICFSecServiceObj readService( CFSecServicePKey pkey, boolean forceRead ) {
		ICFSecServiceObj obj = null;
		if( ( ! forceRead ) && members.containsKey( pkey ) ) {
			obj = members.get( pkey );
		}
		else {
			CFSecServiceBuff readBuff = ((ICFSecSchema)schema.getBackingStore()).getTableService().readDerivedByIdIdx( schema.getAuthorization(),
				pkey.getRequiredClusterId(),
				pkey.getRequiredServiceId() );
			if( readBuff != null ) {
				obj = schema.getServiceTableObj().newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactoryService().newPKey() );
				obj.setBuff( readBuff );
				obj = (ICFSecServiceObj)obj.realise();
			}
		}
		return( obj );
	}

	public ICFSecServiceObj readCachedService( CFSecServicePKey pkey ) {
		ICFSecServiceObj obj = null;
		if( members.containsKey( pkey ) ) {
			obj = members.get( pkey );
		}
		return( obj );
	}

	public void reallyDeepDisposeService( ICFSecServiceObj obj )
	{
		final String S_ProcName = "CFSecServiceTableObj.reallyDeepDisposeService() ";
		String classCode;
		if( obj == null ) {
			return;
		}
		CFSecServicePKey pkey = obj.getPKey();
		ICFSecServiceObj existing = readCachedService( pkey );
		if( existing == null ) {
			return;
		}
		members.remove( pkey );
		CFSecServiceByClusterIdxKey keyClusterIdx = ((ICFSecSchema)schema.getBackingStore()).getFactoryService().newClusterIdxKey();
		keyClusterIdx.setRequiredClusterId( existing.getRequiredClusterId() );

		CFSecServiceByHostIdxKey keyHostIdx = ((ICFSecSchema)schema.getBackingStore()).getFactoryService().newHostIdxKey();
		keyHostIdx.setRequiredClusterId( existing.getRequiredClusterId() );
		keyHostIdx.setRequiredHostNodeId( existing.getRequiredHostNodeId() );

		CFSecServiceByTypeIdxKey keyTypeIdx = ((ICFSecSchema)schema.getBackingStore()).getFactoryService().newTypeIdxKey();
		keyTypeIdx.setRequiredServiceTypeId( existing.getRequiredServiceTypeId() );

		CFSecServiceByUTypeIdxKey keyUTypeIdx = ((ICFSecSchema)schema.getBackingStore()).getFactoryService().newUTypeIdxKey();
		keyUTypeIdx.setRequiredClusterId( existing.getRequiredClusterId() );
		keyUTypeIdx.setRequiredHostNodeId( existing.getRequiredHostNodeId() );
		keyUTypeIdx.setRequiredServiceTypeId( existing.getRequiredServiceTypeId() );

		CFSecServiceByUHostPortIdxKey keyUHostPortIdx = ((ICFSecSchema)schema.getBackingStore()).getFactoryService().newUHostPortIdxKey();
		keyUHostPortIdx.setRequiredClusterId( existing.getRequiredClusterId() );
		keyUHostPortIdx.setRequiredHostNodeId( existing.getRequiredHostNodeId() );
		keyUHostPortIdx.setRequiredHostPort( existing.getRequiredHostPort() );



		if( indexByClusterIdx != null ) {
			if( indexByClusterIdx.containsKey( keyClusterIdx ) ) {
				indexByClusterIdx.get( keyClusterIdx ).remove( pkey );
				if( indexByClusterIdx.get( keyClusterIdx ).size() <= 0 ) {
					indexByClusterIdx.remove( keyClusterIdx );
				}
			}
		}

		if( indexByHostIdx != null ) {
			if( indexByHostIdx.containsKey( keyHostIdx ) ) {
				indexByHostIdx.get( keyHostIdx ).remove( pkey );
				if( indexByHostIdx.get( keyHostIdx ).size() <= 0 ) {
					indexByHostIdx.remove( keyHostIdx );
				}
			}
		}

		if( indexByTypeIdx != null ) {
			if( indexByTypeIdx.containsKey( keyTypeIdx ) ) {
				indexByTypeIdx.get( keyTypeIdx ).remove( pkey );
				if( indexByTypeIdx.get( keyTypeIdx ).size() <= 0 ) {
					indexByTypeIdx.remove( keyTypeIdx );
				}
			}
		}

		if( indexByUTypeIdx != null ) {
			indexByUTypeIdx.remove( keyUTypeIdx );
		}

		if( indexByUHostPortIdx != null ) {
			indexByUHostPortIdx.remove( keyUHostPortIdx );
		}


	}
	public void deepDisposeService( CFSecServicePKey pkey ) {
		ICFSecServiceObj obj = readCachedService( pkey );
		if( obj != null ) {
			obj.forget();
		}
	}

	public ICFSecServiceObj lockService( CFSecServicePKey pkey ) {
		ICFSecServiceObj locked = null;
		CFSecServiceBuff lockBuff = ((ICFSecSchema)schema.getBackingStore()).getTableService().lockDerived( schema.getAuthorization(), pkey );
		if( lockBuff != null ) {
				locked = schema.getServiceTableObj().newInstance();
			locked.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactoryService().newPKey() );
			locked.setBuff( lockBuff );
			locked = (ICFSecServiceObj)locked.realise();
		}
		else {
			throw new CFLibCollisionDetectedException( getClass(), "lockService", pkey );
		}
		return( locked );
	}

	public List<ICFSecServiceObj> readAllService() {
		return( readAllService( false ) );
	}

	public List<ICFSecServiceObj> readAllService( boolean forceRead ) {
		final String S_ProcName = "readAllService";
		if( ( allService == null ) || forceRead ) {
			Map<CFSecServicePKey, ICFSecServiceObj> map = new HashMap<CFSecServicePKey,ICFSecServiceObj>();
			allService = map;
			CFSecServiceBuff[] buffList = ((ICFSecSchema)schema.getBackingStore()).getTableService().readAllDerived( schema.getAuthorization() );
			CFSecServiceBuff buff;
			ICFSecServiceObj obj;
			for( int idx = 0; idx < buffList.length; idx ++ ) {
				buff = buffList[ idx ];
				obj = newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactoryService().newPKey() );
				obj.setBuff( buff );
				ICFSecServiceObj realised = (ICFSecServiceObj)obj.realise();
			}
		}
		int len = allService.size();
		ICFSecServiceObj arr[] = new ICFSecServiceObj[len];
		Iterator<ICFSecServiceObj> valIter = allService.values().iterator();
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
		ArrayList<ICFSecServiceObj> arrayList = new ArrayList<ICFSecServiceObj>(len);
		for( idx = 0; idx < len; idx ++ ) {
			arrayList.add( arr[idx] );
		}

		Comparator<ICFSecServiceObj> cmp = new Comparator<ICFSecServiceObj>() {
			public int compare( ICFSecServiceObj lhs, ICFSecServiceObj rhs ) {
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
					CFSecServicePKey lhsPKey = lhs.getPKey();
					CFSecServicePKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		List<ICFSecServiceObj> sortedList = arrayList;
		return( sortedList );
	}

	public List<ICFSecServiceObj> readCachedAllService() {
		final String S_ProcName = "readCachedAllService";
		ArrayList<ICFSecServiceObj> arrayList = new ArrayList<ICFSecServiceObj>();
		if( allService != null ) {
			int len = allService.size();
			ICFSecServiceObj arr[] = new ICFSecServiceObj[len];
			Iterator<ICFSecServiceObj> valIter = allService.values().iterator();
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
		Comparator<ICFSecServiceObj> cmp = new Comparator<ICFSecServiceObj>() {
			public int compare( ICFSecServiceObj lhs, ICFSecServiceObj rhs ) {
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
					CFSecServicePKey lhsPKey = lhs.getPKey();
					CFSecServicePKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		return( arrayList );
	}

	/**
	 *	Return a sorted map of a page of the Service-derived instances in the database.
	 *
	 *	@return	List of ICFSecServiceObj instance, sorted by their primary keys, which
	 *		may include an empty set.
	 */
	public List<ICFSecServiceObj> pageAllService(Long priorClusterId,
		Long priorServiceId )
	{
		final String S_ProcName = "pageAllService";
		Map<CFSecServicePKey, ICFSecServiceObj> map = new HashMap<CFSecServicePKey,ICFSecServiceObj>();
		CFSecServiceBuff[] buffList = ((ICFSecSchema)schema.getBackingStore()).getTableService().pageAllBuff( schema.getAuthorization(),
			priorClusterId,
			priorServiceId );
		CFSecServiceBuff buff;
		ICFSecServiceObj obj;
		ICFSecServiceObj realised;
		ArrayList<ICFSecServiceObj> arrayList = new ArrayList<ICFSecServiceObj>( buffList.length );
		for( int idx = 0; idx < buffList.length; idx ++ ) {
			buff = buffList[ idx ];
				obj = newInstance();
			obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactoryService().newPKey() );
			obj.setBuff( buff );
			realised = (ICFSecServiceObj)obj.realise();
			arrayList.add( realised );
		}
		return( arrayList );
	}

	public ICFSecServiceObj readServiceByIdIdx( long ClusterId,
		long ServiceId )
	{
		return( readServiceByIdIdx( ClusterId,
			ServiceId,
			false ) );
	}

	public ICFSecServiceObj readServiceByIdIdx( long ClusterId,
		long ServiceId, boolean forceRead )
	{
		CFSecServicePKey pkey = ((ICFSecSchema)schema.getBackingStore()).getFactoryService().newPKey();
		pkey.setRequiredClusterId( ClusterId );
		pkey.setRequiredServiceId( ServiceId );
		ICFSecServiceObj obj = readService( pkey, forceRead );
		return( obj );
	}

	public List<ICFSecServiceObj> readServiceByClusterIdx( long ClusterId )
	{
		return( readServiceByClusterIdx( ClusterId,
			false ) );
	}

	public List<ICFSecServiceObj> readServiceByClusterIdx( long ClusterId,
		boolean forceRead )
	{
		final String S_ProcName = "readServiceByClusterIdx";
		CFSecServiceByClusterIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryService().newClusterIdxKey();
		key.setRequiredClusterId( ClusterId );
		Map<CFSecServicePKey, ICFSecServiceObj> dict;
		if( indexByClusterIdx == null ) {
			indexByClusterIdx = new HashMap< CFSecServiceByClusterIdxKey,
				Map< CFSecServicePKey, ICFSecServiceObj > >();
		}
		if( ( ! forceRead ) && indexByClusterIdx.containsKey( key ) ) {
			dict = indexByClusterIdx.get( key );
		}
		else {
			dict = new HashMap<CFSecServicePKey, ICFSecServiceObj>();
			ICFSecServiceObj obj;
			CFSecServiceBuff[] buffList = ((ICFSecSchema)schema.getBackingStore()).getTableService().readDerivedByClusterIdx( schema.getAuthorization(),
				ClusterId );
			CFSecServiceBuff buff;
			for( int idx = 0; idx < buffList.length; idx ++ ) {
				buff = buffList[ idx ];
				obj = schema.getServiceTableObj().newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactoryService().newPKey() );
				obj.setBuff( buff );
				ICFSecServiceObj realised = (ICFSecServiceObj)obj.realise();
				dict.put( realised.getPKey(), realised );
			}
			indexByClusterIdx.put( key, dict );
		}
		int len = dict.size();
		ICFSecServiceObj arr[] = new ICFSecServiceObj[len];
		Iterator<ICFSecServiceObj> valIter = dict.values().iterator();
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
		ArrayList<ICFSecServiceObj> arrayList = new ArrayList<ICFSecServiceObj>(len);
		for( idx = 0; idx < len; idx ++ ) {
			arrayList.add( arr[idx] );
		}

		Comparator<ICFSecServiceObj> cmp = new Comparator<ICFSecServiceObj>() {
			public int compare( ICFSecServiceObj lhs, ICFSecServiceObj rhs ) {
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
					CFSecServicePKey lhsPKey = lhs.getPKey();
					CFSecServicePKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		List<ICFSecServiceObj> sortedList = arrayList;
		return( sortedList );
	}

	public List<ICFSecServiceObj> readServiceByHostIdx( long ClusterId,
		long HostNodeId )
	{
		return( readServiceByHostIdx( ClusterId,
			HostNodeId,
			false ) );
	}

	public List<ICFSecServiceObj> readServiceByHostIdx( long ClusterId,
		long HostNodeId,
		boolean forceRead )
	{
		final String S_ProcName = "readServiceByHostIdx";
		CFSecServiceByHostIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryService().newHostIdxKey();
		key.setRequiredClusterId( ClusterId );
		key.setRequiredHostNodeId( HostNodeId );
		Map<CFSecServicePKey, ICFSecServiceObj> dict;
		if( indexByHostIdx == null ) {
			indexByHostIdx = new HashMap< CFSecServiceByHostIdxKey,
				Map< CFSecServicePKey, ICFSecServiceObj > >();
		}
		if( ( ! forceRead ) && indexByHostIdx.containsKey( key ) ) {
			dict = indexByHostIdx.get( key );
		}
		else {
			dict = new HashMap<CFSecServicePKey, ICFSecServiceObj>();
			ICFSecServiceObj obj;
			CFSecServiceBuff[] buffList = ((ICFSecSchema)schema.getBackingStore()).getTableService().readDerivedByHostIdx( schema.getAuthorization(),
				ClusterId,
				HostNodeId );
			CFSecServiceBuff buff;
			for( int idx = 0; idx < buffList.length; idx ++ ) {
				buff = buffList[ idx ];
				obj = schema.getServiceTableObj().newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactoryService().newPKey() );
				obj.setBuff( buff );
				ICFSecServiceObj realised = (ICFSecServiceObj)obj.realise();
				dict.put( realised.getPKey(), realised );
			}
			indexByHostIdx.put( key, dict );
		}
		int len = dict.size();
		ICFSecServiceObj arr[] = new ICFSecServiceObj[len];
		Iterator<ICFSecServiceObj> valIter = dict.values().iterator();
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
		ArrayList<ICFSecServiceObj> arrayList = new ArrayList<ICFSecServiceObj>(len);
		for( idx = 0; idx < len; idx ++ ) {
			arrayList.add( arr[idx] );
		}

		Comparator<ICFSecServiceObj> cmp = new Comparator<ICFSecServiceObj>() {
			public int compare( ICFSecServiceObj lhs, ICFSecServiceObj rhs ) {
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
					CFSecServicePKey lhsPKey = lhs.getPKey();
					CFSecServicePKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		List<ICFSecServiceObj> sortedList = arrayList;
		return( sortedList );
	}

	public List<ICFSecServiceObj> readServiceByTypeIdx( int ServiceTypeId )
	{
		return( readServiceByTypeIdx( ServiceTypeId,
			false ) );
	}

	public List<ICFSecServiceObj> readServiceByTypeIdx( int ServiceTypeId,
		boolean forceRead )
	{
		final String S_ProcName = "readServiceByTypeIdx";
		CFSecServiceByTypeIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryService().newTypeIdxKey();
		key.setRequiredServiceTypeId( ServiceTypeId );
		Map<CFSecServicePKey, ICFSecServiceObj> dict;
		if( indexByTypeIdx == null ) {
			indexByTypeIdx = new HashMap< CFSecServiceByTypeIdxKey,
				Map< CFSecServicePKey, ICFSecServiceObj > >();
		}
		if( ( ! forceRead ) && indexByTypeIdx.containsKey( key ) ) {
			dict = indexByTypeIdx.get( key );
		}
		else {
			dict = new HashMap<CFSecServicePKey, ICFSecServiceObj>();
			ICFSecServiceObj obj;
			CFSecServiceBuff[] buffList = ((ICFSecSchema)schema.getBackingStore()).getTableService().readDerivedByTypeIdx( schema.getAuthorization(),
				ServiceTypeId );
			CFSecServiceBuff buff;
			for( int idx = 0; idx < buffList.length; idx ++ ) {
				buff = buffList[ idx ];
				obj = schema.getServiceTableObj().newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactoryService().newPKey() );
				obj.setBuff( buff );
				ICFSecServiceObj realised = (ICFSecServiceObj)obj.realise();
				dict.put( realised.getPKey(), realised );
			}
			indexByTypeIdx.put( key, dict );
		}
		int len = dict.size();
		ICFSecServiceObj arr[] = new ICFSecServiceObj[len];
		Iterator<ICFSecServiceObj> valIter = dict.values().iterator();
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
		ArrayList<ICFSecServiceObj> arrayList = new ArrayList<ICFSecServiceObj>(len);
		for( idx = 0; idx < len; idx ++ ) {
			arrayList.add( arr[idx] );
		}

		Comparator<ICFSecServiceObj> cmp = new Comparator<ICFSecServiceObj>() {
			public int compare( ICFSecServiceObj lhs, ICFSecServiceObj rhs ) {
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
					CFSecServicePKey lhsPKey = lhs.getPKey();
					CFSecServicePKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		List<ICFSecServiceObj> sortedList = arrayList;
		return( sortedList );
	}

	public ICFSecServiceObj readServiceByUTypeIdx( long ClusterId,
		long HostNodeId,
		int ServiceTypeId )
	{
		return( readServiceByUTypeIdx( ClusterId,
			HostNodeId,
			ServiceTypeId,
			false ) );
	}

	public ICFSecServiceObj readServiceByUTypeIdx( long ClusterId,
		long HostNodeId,
		int ServiceTypeId, boolean forceRead )
	{
		if( indexByUTypeIdx == null ) {
			indexByUTypeIdx = new HashMap< CFSecServiceByUTypeIdxKey,
				ICFSecServiceObj >();
		}
		CFSecServiceByUTypeIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryService().newUTypeIdxKey();
		key.setRequiredClusterId( ClusterId );
		key.setRequiredHostNodeId( HostNodeId );
		key.setRequiredServiceTypeId( ServiceTypeId );
		ICFSecServiceObj obj = null;
		if( ( ! forceRead ) && indexByUTypeIdx.containsKey( key ) ) {
			obj = indexByUTypeIdx.get( key );
		}
		else {
			CFSecServiceBuff buff = ((ICFSecSchema)schema.getBackingStore()).getTableService().readDerivedByUTypeIdx( schema.getAuthorization(),
				ClusterId,
				HostNodeId,
				ServiceTypeId );
			if( buff != null ) {
				obj = schema.getServiceTableObj().newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactoryService().newPKey() );
				obj.setBuff( buff );
				obj = (ICFSecServiceObj)obj.realise();
			}
		}
		return( obj );
	}

	public ICFSecServiceObj readServiceByUHostPortIdx( long ClusterId,
		long HostNodeId,
		short HostPort )
	{
		return( readServiceByUHostPortIdx( ClusterId,
			HostNodeId,
			HostPort,
			false ) );
	}

	public ICFSecServiceObj readServiceByUHostPortIdx( long ClusterId,
		long HostNodeId,
		short HostPort, boolean forceRead )
	{
		if( indexByUHostPortIdx == null ) {
			indexByUHostPortIdx = new HashMap< CFSecServiceByUHostPortIdxKey,
				ICFSecServiceObj >();
		}
		CFSecServiceByUHostPortIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryService().newUHostPortIdxKey();
		key.setRequiredClusterId( ClusterId );
		key.setRequiredHostNodeId( HostNodeId );
		key.setRequiredHostPort( HostPort );
		ICFSecServiceObj obj = null;
		if( ( ! forceRead ) && indexByUHostPortIdx.containsKey( key ) ) {
			obj = indexByUHostPortIdx.get( key );
		}
		else {
			CFSecServiceBuff buff = ((ICFSecSchema)schema.getBackingStore()).getTableService().readDerivedByUHostPortIdx( schema.getAuthorization(),
				ClusterId,
				HostNodeId,
				HostPort );
			if( buff != null ) {
				obj = schema.getServiceTableObj().newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactoryService().newPKey() );
				obj.setBuff( buff );
				obj = (ICFSecServiceObj)obj.realise();
			}
		}
		return( obj );
	}

	public ICFSecServiceObj readCachedServiceByIdIdx( long ClusterId,
		long ServiceId )
	{
		ICFSecServiceObj obj = null;
		CFSecServicePKey pkey = ((ICFSecSchema)schema.getBackingStore()).getFactoryService().newPKey();
		pkey.setRequiredClusterId( ClusterId );
		pkey.setRequiredServiceId( ServiceId );
		obj = readCachedService( pkey );
		return( obj );
	}

	public List<ICFSecServiceObj> readCachedServiceByClusterIdx( long ClusterId )
	{
		final String S_ProcName = "readCachedServiceByClusterIdx";
		CFSecServiceByClusterIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryService().newClusterIdxKey();
		key.setRequiredClusterId( ClusterId );
		ArrayList<ICFSecServiceObj> arrayList = new ArrayList<ICFSecServiceObj>();
		if( indexByClusterIdx != null ) {
			Map<CFSecServicePKey, ICFSecServiceObj> dict;
			if( indexByClusterIdx.containsKey( key ) ) {
				dict = indexByClusterIdx.get( key );
				int len = dict.size();
				ICFSecServiceObj arr[] = new ICFSecServiceObj[len];
				Iterator<ICFSecServiceObj> valIter = dict.values().iterator();
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
			ICFSecServiceObj obj;
			Iterator<ICFSecServiceObj> valIter = members.values().iterator();
			while( valIter.hasNext() ) {
				obj = valIter.next();
				if( obj != null ) {
					if( obj.getBuff().compareTo( key ) == 0 ) {
						arrayList.add( obj );
					}
				}
			}
		}
		Comparator<ICFSecServiceObj> cmp = new Comparator<ICFSecServiceObj>() {
			public int compare( ICFSecServiceObj lhs, ICFSecServiceObj rhs ) {
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
					CFSecServicePKey lhsPKey = lhs.getPKey();
					CFSecServicePKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		return( arrayList );
	}

	public List<ICFSecServiceObj> readCachedServiceByHostIdx( long ClusterId,
		long HostNodeId )
	{
		final String S_ProcName = "readCachedServiceByHostIdx";
		CFSecServiceByHostIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryService().newHostIdxKey();
		key.setRequiredClusterId( ClusterId );
		key.setRequiredHostNodeId( HostNodeId );
		ArrayList<ICFSecServiceObj> arrayList = new ArrayList<ICFSecServiceObj>();
		if( indexByHostIdx != null ) {
			Map<CFSecServicePKey, ICFSecServiceObj> dict;
			if( indexByHostIdx.containsKey( key ) ) {
				dict = indexByHostIdx.get( key );
				int len = dict.size();
				ICFSecServiceObj arr[] = new ICFSecServiceObj[len];
				Iterator<ICFSecServiceObj> valIter = dict.values().iterator();
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
			ICFSecServiceObj obj;
			Iterator<ICFSecServiceObj> valIter = members.values().iterator();
			while( valIter.hasNext() ) {
				obj = valIter.next();
				if( obj != null ) {
					if( obj.getBuff().compareTo( key ) == 0 ) {
						arrayList.add( obj );
					}
				}
			}
		}
		Comparator<ICFSecServiceObj> cmp = new Comparator<ICFSecServiceObj>() {
			public int compare( ICFSecServiceObj lhs, ICFSecServiceObj rhs ) {
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
					CFSecServicePKey lhsPKey = lhs.getPKey();
					CFSecServicePKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		return( arrayList );
	}

	public List<ICFSecServiceObj> readCachedServiceByTypeIdx( int ServiceTypeId )
	{
		final String S_ProcName = "readCachedServiceByTypeIdx";
		CFSecServiceByTypeIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryService().newTypeIdxKey();
		key.setRequiredServiceTypeId( ServiceTypeId );
		ArrayList<ICFSecServiceObj> arrayList = new ArrayList<ICFSecServiceObj>();
		if( indexByTypeIdx != null ) {
			Map<CFSecServicePKey, ICFSecServiceObj> dict;
			if( indexByTypeIdx.containsKey( key ) ) {
				dict = indexByTypeIdx.get( key );
				int len = dict.size();
				ICFSecServiceObj arr[] = new ICFSecServiceObj[len];
				Iterator<ICFSecServiceObj> valIter = dict.values().iterator();
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
			ICFSecServiceObj obj;
			Iterator<ICFSecServiceObj> valIter = members.values().iterator();
			while( valIter.hasNext() ) {
				obj = valIter.next();
				if( obj != null ) {
					if( obj.getBuff().compareTo( key ) == 0 ) {
						arrayList.add( obj );
					}
				}
			}
		}
		Comparator<ICFSecServiceObj> cmp = new Comparator<ICFSecServiceObj>() {
			public int compare( ICFSecServiceObj lhs, ICFSecServiceObj rhs ) {
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
					CFSecServicePKey lhsPKey = lhs.getPKey();
					CFSecServicePKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		return( arrayList );
	}

	public ICFSecServiceObj readCachedServiceByUTypeIdx( long ClusterId,
		long HostNodeId,
		int ServiceTypeId )
	{
		ICFSecServiceObj obj = null;
		CFSecServiceByUTypeIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryService().newUTypeIdxKey();
		key.setRequiredClusterId( ClusterId );
		key.setRequiredHostNodeId( HostNodeId );
		key.setRequiredServiceTypeId( ServiceTypeId );
		if( indexByUTypeIdx != null ) {
			if( indexByUTypeIdx.containsKey( key ) ) {
				obj = indexByUTypeIdx.get( key );
			}
			else {
				Iterator<ICFSecServiceObj> valIter = members.values().iterator();
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
			Iterator<ICFSecServiceObj> valIter = members.values().iterator();
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

	public ICFSecServiceObj readCachedServiceByUHostPortIdx( long ClusterId,
		long HostNodeId,
		short HostPort )
	{
		ICFSecServiceObj obj = null;
		CFSecServiceByUHostPortIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryService().newUHostPortIdxKey();
		key.setRequiredClusterId( ClusterId );
		key.setRequiredHostNodeId( HostNodeId );
		key.setRequiredHostPort( HostPort );
		if( indexByUHostPortIdx != null ) {
			if( indexByUHostPortIdx.containsKey( key ) ) {
				obj = indexByUHostPortIdx.get( key );
			}
			else {
				Iterator<ICFSecServiceObj> valIter = members.values().iterator();
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
			Iterator<ICFSecServiceObj> valIter = members.values().iterator();
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

	public void deepDisposeServiceByIdIdx( long ClusterId,
		long ServiceId )
	{
		ICFSecServiceObj obj = readCachedServiceByIdIdx( ClusterId,
				ServiceId );
		if( obj != null ) {
			obj.forget();
		}
	}

	public void deepDisposeServiceByClusterIdx( long ClusterId )
	{
		final String S_ProcName = "deepDisposeServiceByClusterIdx";
		ICFSecServiceObj obj;
		List<ICFSecServiceObj> arrayList = readCachedServiceByClusterIdx( ClusterId );
		if( arrayList != null )  {
			Iterator<ICFSecServiceObj> arrayIter = arrayList.iterator();
			while( arrayIter.hasNext() ) {
				obj = arrayIter.next();
				if( obj != null ) {
					obj.forget();
				}
			}
		}
	}

	public void deepDisposeServiceByHostIdx( long ClusterId,
		long HostNodeId )
	{
		final String S_ProcName = "deepDisposeServiceByHostIdx";
		ICFSecServiceObj obj;
		List<ICFSecServiceObj> arrayList = readCachedServiceByHostIdx( ClusterId,
				HostNodeId );
		if( arrayList != null )  {
			Iterator<ICFSecServiceObj> arrayIter = arrayList.iterator();
			while( arrayIter.hasNext() ) {
				obj = arrayIter.next();
				if( obj != null ) {
					obj.forget();
				}
			}
		}
	}

	public void deepDisposeServiceByTypeIdx( int ServiceTypeId )
	{
		final String S_ProcName = "deepDisposeServiceByTypeIdx";
		ICFSecServiceObj obj;
		List<ICFSecServiceObj> arrayList = readCachedServiceByTypeIdx( ServiceTypeId );
		if( arrayList != null )  {
			Iterator<ICFSecServiceObj> arrayIter = arrayList.iterator();
			while( arrayIter.hasNext() ) {
				obj = arrayIter.next();
				if( obj != null ) {
					obj.forget();
				}
			}
		}
	}

	public void deepDisposeServiceByUTypeIdx( long ClusterId,
		long HostNodeId,
		int ServiceTypeId )
	{
		ICFSecServiceObj obj = readCachedServiceByUTypeIdx( ClusterId,
				HostNodeId,
				ServiceTypeId );
		if( obj != null ) {
			obj.forget();
		}
	}

	public void deepDisposeServiceByUHostPortIdx( long ClusterId,
		long HostNodeId,
		short HostPort )
	{
		ICFSecServiceObj obj = readCachedServiceByUHostPortIdx( ClusterId,
				HostNodeId,
				HostPort );
		if( obj != null ) {
			obj.forget();
		}
	}

	/**
	 *	Read a page of data as a List of Service-derived instances sorted by their primary keys,
	 *	as identified by the duplicate ClusterIdx key attributes.
	 *
	 *	@param	argClusterId	The Service key attribute of the instance generating the id.
	 *
	 *	@return	A List of Service-derived instances sorted by their primary keys,
	 *		as identified by the key attributes, which may be an empty set.
	 */
	public List<ICFSecServiceObj> pageServiceByClusterIdx( long ClusterId,
		Long priorClusterId,
		Long priorServiceId )
	{
		final String S_ProcName = "pageServiceByClusterIdx";
		CFSecServiceByClusterIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryService().newClusterIdxKey();
		key.setRequiredClusterId( ClusterId );
		List<ICFSecServiceObj> retList = new LinkedList<ICFSecServiceObj>();
		ICFSecServiceObj obj;
		CFSecServiceBuff[] buffList = ((ICFSecSchema)schema.getBackingStore()).getTableService().pageBuffByClusterIdx( schema.getAuthorization(),
				ClusterId,
			priorClusterId,
			priorServiceId );
		CFSecServiceBuff buff;
		for( int idx = 0; idx < buffList.length; idx ++ ) {
			buff = buffList[ idx ];
				obj = schema.getServiceTableObj().newInstance();
			obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactoryService().newPKey() );
			obj.setBuff( buff );
			ICFSecServiceObj realised = (ICFSecServiceObj)obj.realise();
			retList.add( realised );
		}
		return( retList );
	}

	/**
	 *	Read a page of data as a List of Service-derived instances sorted by their primary keys,
	 *	as identified by the duplicate HostIdx key attributes.
	 *
	 *	@param	argClusterId	The Service key attribute of the instance generating the id.
	 *
	 *	@param	argHostNodeId	The Service key attribute of the instance generating the id.
	 *
	 *	@return	A List of Service-derived instances sorted by their primary keys,
	 *		as identified by the key attributes, which may be an empty set.
	 */
	public List<ICFSecServiceObj> pageServiceByHostIdx( long ClusterId,
		long HostNodeId,
		Long priorClusterId,
		Long priorServiceId )
	{
		final String S_ProcName = "pageServiceByHostIdx";
		CFSecServiceByHostIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryService().newHostIdxKey();
		key.setRequiredClusterId( ClusterId );
		key.setRequiredHostNodeId( HostNodeId );
		List<ICFSecServiceObj> retList = new LinkedList<ICFSecServiceObj>();
		ICFSecServiceObj obj;
		CFSecServiceBuff[] buffList = ((ICFSecSchema)schema.getBackingStore()).getTableService().pageBuffByHostIdx( schema.getAuthorization(),
				ClusterId,
				HostNodeId,
			priorClusterId,
			priorServiceId );
		CFSecServiceBuff buff;
		for( int idx = 0; idx < buffList.length; idx ++ ) {
			buff = buffList[ idx ];
				obj = schema.getServiceTableObj().newInstance();
			obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactoryService().newPKey() );
			obj.setBuff( buff );
			ICFSecServiceObj realised = (ICFSecServiceObj)obj.realise();
			retList.add( realised );
		}
		return( retList );
	}

	/**
	 *	Read a page of data as a List of Service-derived instances sorted by their primary keys,
	 *	as identified by the duplicate TypeIdx key attributes.
	 *
	 *	@param	argServiceTypeId	The Service key attribute of the instance generating the id.
	 *
	 *	@return	A List of Service-derived instances sorted by their primary keys,
	 *		as identified by the key attributes, which may be an empty set.
	 */
	public List<ICFSecServiceObj> pageServiceByTypeIdx( int ServiceTypeId,
		Long priorClusterId,
		Long priorServiceId )
	{
		final String S_ProcName = "pageServiceByTypeIdx";
		CFSecServiceByTypeIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryService().newTypeIdxKey();
		key.setRequiredServiceTypeId( ServiceTypeId );
		List<ICFSecServiceObj> retList = new LinkedList<ICFSecServiceObj>();
		ICFSecServiceObj obj;
		CFSecServiceBuff[] buffList = ((ICFSecSchema)schema.getBackingStore()).getTableService().pageBuffByTypeIdx( schema.getAuthorization(),
				ServiceTypeId,
			priorClusterId,
			priorServiceId );
		CFSecServiceBuff buff;
		for( int idx = 0; idx < buffList.length; idx ++ ) {
			buff = buffList[ idx ];
				obj = schema.getServiceTableObj().newInstance();
			obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactoryService().newPKey() );
			obj.setBuff( buff );
			ICFSecServiceObj realised = (ICFSecServiceObj)obj.realise();
			retList.add( realised );
		}
		return( retList );
	}

	public ICFSecServiceObj updateService( ICFSecServiceObj Obj ) {
		ICFSecServiceObj obj = Obj;
		((ICFSecSchema)schema.getBackingStore()).getTableService().updateService( schema.getAuthorization(),
			Obj.getServiceBuff() );
		obj = (ICFSecServiceObj)Obj.realise();
		obj.endEdit();
		return( obj );
	}

	public void deleteService( ICFSecServiceObj Obj ) {
		ICFSecServiceObj obj = Obj;
		((ICFSecSchema)schema.getBackingStore()).getTableService().deleteService( schema.getAuthorization(),
			obj.getServiceBuff() );
		Obj.forget();
	}

	public void deleteServiceByIdIdx( long ClusterId,
		long ServiceId )
	{
		CFSecServicePKey pkey = ((ICFSecSchema)schema.getBackingStore()).getFactoryService().newPKey();
		pkey.setRequiredClusterId( ClusterId );
		pkey.setRequiredServiceId( ServiceId );
		ICFSecServiceObj obj = readService( pkey );
		if( obj != null ) {
			ICFSecServiceEditObj editObj = (ICFSecServiceEditObj)obj.getEdit();
			boolean editStarted;
			if( editObj == null ) {
				editObj = (ICFSecServiceEditObj)obj.beginEdit();
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
		deepDisposeServiceByIdIdx( ClusterId,
				ServiceId );
	}

	public void deleteServiceByClusterIdx( long ClusterId )
	{
		CFSecServiceByClusterIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryService().newClusterIdxKey();
		key.setRequiredClusterId( ClusterId );
		if( indexByClusterIdx == null ) {
			indexByClusterIdx = new HashMap< CFSecServiceByClusterIdxKey,
				Map< CFSecServicePKey, ICFSecServiceObj > >();
		}
		if( indexByClusterIdx.containsKey( key ) ) {
			Map<CFSecServicePKey, ICFSecServiceObj> dict = indexByClusterIdx.get( key );
			((ICFSecSchema)schema.getBackingStore()).getTableService().deleteServiceByClusterIdx( schema.getAuthorization(),
				ClusterId );
			Iterator<ICFSecServiceObj> iter = dict.values().iterator();
			ICFSecServiceObj obj;
			List<ICFSecServiceObj> toForget = new LinkedList<ICFSecServiceObj>();
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
			((ICFSecSchema)schema.getBackingStore()).getTableService().deleteServiceByClusterIdx( schema.getAuthorization(),
				ClusterId );
		}
		deepDisposeServiceByClusterIdx( ClusterId );
	}

	public void deleteServiceByHostIdx( long ClusterId,
		long HostNodeId )
	{
		CFSecServiceByHostIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryService().newHostIdxKey();
		key.setRequiredClusterId( ClusterId );
		key.setRequiredHostNodeId( HostNodeId );
		if( indexByHostIdx == null ) {
			indexByHostIdx = new HashMap< CFSecServiceByHostIdxKey,
				Map< CFSecServicePKey, ICFSecServiceObj > >();
		}
		if( indexByHostIdx.containsKey( key ) ) {
			Map<CFSecServicePKey, ICFSecServiceObj> dict = indexByHostIdx.get( key );
			((ICFSecSchema)schema.getBackingStore()).getTableService().deleteServiceByHostIdx( schema.getAuthorization(),
				ClusterId,
				HostNodeId );
			Iterator<ICFSecServiceObj> iter = dict.values().iterator();
			ICFSecServiceObj obj;
			List<ICFSecServiceObj> toForget = new LinkedList<ICFSecServiceObj>();
			while( iter.hasNext() ) {
				obj = iter.next();
				toForget.add( obj );
			}
			iter = toForget.iterator();
			while( iter.hasNext() ) {
				obj = iter.next();
				obj.forget();
			}
			indexByHostIdx.remove( key );
		}
		else {
			((ICFSecSchema)schema.getBackingStore()).getTableService().deleteServiceByHostIdx( schema.getAuthorization(),
				ClusterId,
				HostNodeId );
		}
		deepDisposeServiceByHostIdx( ClusterId,
				HostNodeId );
	}

	public void deleteServiceByTypeIdx( int ServiceTypeId )
	{
		CFSecServiceByTypeIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryService().newTypeIdxKey();
		key.setRequiredServiceTypeId( ServiceTypeId );
		if( indexByTypeIdx == null ) {
			indexByTypeIdx = new HashMap< CFSecServiceByTypeIdxKey,
				Map< CFSecServicePKey, ICFSecServiceObj > >();
		}
		if( indexByTypeIdx.containsKey( key ) ) {
			Map<CFSecServicePKey, ICFSecServiceObj> dict = indexByTypeIdx.get( key );
			((ICFSecSchema)schema.getBackingStore()).getTableService().deleteServiceByTypeIdx( schema.getAuthorization(),
				ServiceTypeId );
			Iterator<ICFSecServiceObj> iter = dict.values().iterator();
			ICFSecServiceObj obj;
			List<ICFSecServiceObj> toForget = new LinkedList<ICFSecServiceObj>();
			while( iter.hasNext() ) {
				obj = iter.next();
				toForget.add( obj );
			}
			iter = toForget.iterator();
			while( iter.hasNext() ) {
				obj = iter.next();
				obj.forget();
			}
			indexByTypeIdx.remove( key );
		}
		else {
			((ICFSecSchema)schema.getBackingStore()).getTableService().deleteServiceByTypeIdx( schema.getAuthorization(),
				ServiceTypeId );
		}
		deepDisposeServiceByTypeIdx( ServiceTypeId );
	}

	public void deleteServiceByUTypeIdx( long ClusterId,
		long HostNodeId,
		int ServiceTypeId )
	{
		if( indexByUTypeIdx == null ) {
			indexByUTypeIdx = new HashMap< CFSecServiceByUTypeIdxKey,
				ICFSecServiceObj >();
		}
		CFSecServiceByUTypeIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryService().newUTypeIdxKey();
		key.setRequiredClusterId( ClusterId );
		key.setRequiredHostNodeId( HostNodeId );
		key.setRequiredServiceTypeId( ServiceTypeId );
		ICFSecServiceObj obj = null;
		if( indexByUTypeIdx.containsKey( key ) ) {
			obj = indexByUTypeIdx.get( key );
			((ICFSecSchema)schema.getBackingStore()).getTableService().deleteServiceByUTypeIdx( schema.getAuthorization(),
				ClusterId,
				HostNodeId,
				ServiceTypeId );
			obj.forget();
		}
		else {
			((ICFSecSchema)schema.getBackingStore()).getTableService().deleteServiceByUTypeIdx( schema.getAuthorization(),
				ClusterId,
				HostNodeId,
				ServiceTypeId );
		}
		deepDisposeServiceByUTypeIdx( ClusterId,
				HostNodeId,
				ServiceTypeId );
	}

	public void deleteServiceByUHostPortIdx( long ClusterId,
		long HostNodeId,
		short HostPort )
	{
		if( indexByUHostPortIdx == null ) {
			indexByUHostPortIdx = new HashMap< CFSecServiceByUHostPortIdxKey,
				ICFSecServiceObj >();
		}
		CFSecServiceByUHostPortIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryService().newUHostPortIdxKey();
		key.setRequiredClusterId( ClusterId );
		key.setRequiredHostNodeId( HostNodeId );
		key.setRequiredHostPort( HostPort );
		ICFSecServiceObj obj = null;
		if( indexByUHostPortIdx.containsKey( key ) ) {
			obj = indexByUHostPortIdx.get( key );
			((ICFSecSchema)schema.getBackingStore()).getTableService().deleteServiceByUHostPortIdx( schema.getAuthorization(),
				ClusterId,
				HostNodeId,
				HostPort );
			obj.forget();
		}
		else {
			((ICFSecSchema)schema.getBackingStore()).getTableService().deleteServiceByUHostPortIdx( schema.getAuthorization(),
				ClusterId,
				HostNodeId,
				HostPort );
		}
		deepDisposeServiceByUHostPortIdx( ClusterId,
				HostNodeId,
				HostPort );
	}
}