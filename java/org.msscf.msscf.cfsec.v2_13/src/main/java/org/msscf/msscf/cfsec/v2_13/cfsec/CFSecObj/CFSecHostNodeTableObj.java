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

public class CFSecHostNodeTableObj
	implements ICFSecHostNodeTableObj
{
	protected ICFSecSchemaObj schema;
	private Map<CFSecHostNodePKey, ICFSecHostNodeObj> members;
	private Map<CFSecHostNodePKey, ICFSecHostNodeObj> allHostNode;
	private Map< CFSecHostNodeByClusterIdxKey,
		Map<CFSecHostNodePKey, ICFSecHostNodeObj > > indexByClusterIdx;
	private Map< CFSecHostNodeByUDescrIdxKey,
		ICFSecHostNodeObj > indexByUDescrIdx;
	private Map< CFSecHostNodeByHostNameIdxKey,
		ICFSecHostNodeObj > indexByHostNameIdx;
	public static String TABLE_NAME = "HostNode";
	public static String TABLE_DBNAME = "hostnode";

	public CFSecHostNodeTableObj() {
		schema = null;
		members = new HashMap<CFSecHostNodePKey, ICFSecHostNodeObj>();
		allHostNode = null;
		indexByClusterIdx = null;
		indexByUDescrIdx = null;
		indexByHostNameIdx = null;
	}

	public CFSecHostNodeTableObj( ICFSecSchemaObj argSchema ) {
		schema = (ICFSecSchemaObj)argSchema;
		members = new HashMap<CFSecHostNodePKey, ICFSecHostNodeObj>();
		allHostNode = null;
		indexByClusterIdx = null;
		indexByUDescrIdx = null;
		indexByHostNameIdx = null;
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
		allHostNode = null;
		indexByClusterIdx = null;
		indexByUDescrIdx = null;
		indexByHostNameIdx = null;
		List<ICFSecHostNodeObj> toForget = new LinkedList<ICFSecHostNodeObj>();
		ICFSecHostNodeObj cur = null;
		Iterator<ICFSecHostNodeObj> iter = members.values().iterator();
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
	 *	CFSecHostNodeObj.
	 */
	public ICFSecHostNodeObj newInstance() {
		ICFSecHostNodeObj inst = new CFSecHostNodeObj( schema );
		return( inst );
	}

	/**
	 *	If your implementation subclasses the objects,
	 *	you'll want to overload the constructByClassCode()
	 *	implementation to return your implementation's
	 *	instances instead of the base implementation.
	 *
	 *	This is the sole factory for instances derived from
	 *	CFSecHostNodeObj.
	 */
	public ICFSecHostNodeEditObj newEditInstance( ICFSecHostNodeObj orig ) {
		ICFSecHostNodeEditObj edit = new CFSecHostNodeEditObj( orig );
		return( edit );
	}

	public ICFSecHostNodeObj realiseHostNode( ICFSecHostNodeObj Obj ) {
		ICFSecHostNodeObj obj = Obj;
		CFSecHostNodePKey pkey = obj.getPKey();
		ICFSecHostNodeObj keepObj = null;
		if( members.containsKey( pkey ) && ( null != members.get( pkey ) ) ) {
			ICFSecHostNodeObj existingObj = members.get( pkey );
			keepObj = existingObj;

			/*
			 *	We always rebind the data because if we're being called, some index has
			 *	been updated and is refreshing it's data, which may or may not have changed
			 */

			// Detach object from alternate and duplicate indexes, leave PKey alone

			if( indexByClusterIdx != null ) {
				CFSecHostNodeByClusterIdxKey keyClusterIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryHostNode().newClusterIdxKey();
				keyClusterIdx.setRequiredClusterId( keepObj.getRequiredClusterId() );
				Map<CFSecHostNodePKey, ICFSecHostNodeObj > mapClusterIdx = indexByClusterIdx.get( keyClusterIdx );
				if( mapClusterIdx != null ) {
					mapClusterIdx.remove( keepObj.getPKey() );
					if( mapClusterIdx.size() <= 0 ) {
						indexByClusterIdx.remove( keyClusterIdx );
					}
				}
			}

			if( indexByUDescrIdx != null ) {
				CFSecHostNodeByUDescrIdxKey keyUDescrIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryHostNode().newUDescrIdxKey();
				keyUDescrIdx.setRequiredClusterId( keepObj.getRequiredClusterId() );
				keyUDescrIdx.setRequiredDescription( keepObj.getRequiredDescription() );
				indexByUDescrIdx.remove( keyUDescrIdx );
			}

			if( indexByHostNameIdx != null ) {
				CFSecHostNodeByHostNameIdxKey keyHostNameIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryHostNode().newHostNameIdxKey();
				keyHostNameIdx.setRequiredClusterId( keepObj.getRequiredClusterId() );
				keyHostNameIdx.setRequiredHostName( keepObj.getRequiredHostName() );
				indexByHostNameIdx.remove( keyHostNameIdx );
			}

			keepObj.setBuff( Obj.getBuff() );
			// Attach new object to alternate and duplicate indexes -- PKey stay stable

			if( indexByClusterIdx != null ) {
				CFSecHostNodeByClusterIdxKey keyClusterIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryHostNode().newClusterIdxKey();
				keyClusterIdx.setRequiredClusterId( keepObj.getRequiredClusterId() );
				Map<CFSecHostNodePKey, ICFSecHostNodeObj > mapClusterIdx = indexByClusterIdx.get( keyClusterIdx );
				if( mapClusterIdx != null ) {
					mapClusterIdx.put( keepObj.getPKey(), keepObj );
				}
			}

			if( indexByUDescrIdx != null ) {
				CFSecHostNodeByUDescrIdxKey keyUDescrIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryHostNode().newUDescrIdxKey();
				keyUDescrIdx.setRequiredClusterId( keepObj.getRequiredClusterId() );
				keyUDescrIdx.setRequiredDescription( keepObj.getRequiredDescription() );
				indexByUDescrIdx.put( keyUDescrIdx, keepObj );
			}

			if( indexByHostNameIdx != null ) {
				CFSecHostNodeByHostNameIdxKey keyHostNameIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryHostNode().newHostNameIdxKey();
				keyHostNameIdx.setRequiredClusterId( keepObj.getRequiredClusterId() );
				keyHostNameIdx.setRequiredHostName( keepObj.getRequiredHostName() );
				indexByHostNameIdx.put( keyHostNameIdx, keepObj );
			}

			if( allHostNode != null ) {
				allHostNode.put( keepObj.getPKey(), keepObj );
			}
		}
		else {
			keepObj = obj;
			keepObj.setIsNew( false );

			// Attach new object to PKey, all, alternate, and duplicate indexes
			members.put( keepObj.getPKey(), keepObj );
			if( allHostNode != null ) {
				allHostNode.put( keepObj.getPKey(), keepObj );
			}

			if( indexByClusterIdx != null ) {
				CFSecHostNodeByClusterIdxKey keyClusterIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryHostNode().newClusterIdxKey();
				keyClusterIdx.setRequiredClusterId( keepObj.getRequiredClusterId() );
				Map<CFSecHostNodePKey, ICFSecHostNodeObj > mapClusterIdx = indexByClusterIdx.get( keyClusterIdx );
				if( mapClusterIdx != null ) {
					mapClusterIdx.put( keepObj.getPKey(), keepObj );
				}
			}

			if( indexByUDescrIdx != null ) {
				CFSecHostNodeByUDescrIdxKey keyUDescrIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryHostNode().newUDescrIdxKey();
				keyUDescrIdx.setRequiredClusterId( keepObj.getRequiredClusterId() );
				keyUDescrIdx.setRequiredDescription( keepObj.getRequiredDescription() );
				indexByUDescrIdx.put( keyUDescrIdx, keepObj );
			}

			if( indexByHostNameIdx != null ) {
				CFSecHostNodeByHostNameIdxKey keyHostNameIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryHostNode().newHostNameIdxKey();
				keyHostNameIdx.setRequiredClusterId( keepObj.getRequiredClusterId() );
				keyHostNameIdx.setRequiredHostName( keepObj.getRequiredHostName() );
				indexByHostNameIdx.put( keyHostNameIdx, keepObj );
			}

		}
		return( keepObj );
	}

	public ICFSecHostNodeObj createHostNode( ICFSecHostNodeObj Obj ) {
		ICFSecHostNodeObj obj = Obj;
		CFSecHostNodeBuff buff = obj.getHostNodeBuff();
		((ICFSecSchema)schema.getBackingStore()).getTableHostNode().createHostNode(
			schema.getAuthorization(),
			buff );
		obj.copyBuffToPKey();
		obj = obj.realise();
		obj.endEdit();
		return( obj );
	}

	public ICFSecHostNodeObj readHostNode( CFSecHostNodePKey pkey ) {
		return( readHostNode( pkey, false ) );
	}

	public ICFSecHostNodeObj readHostNode( CFSecHostNodePKey pkey, boolean forceRead ) {
		ICFSecHostNodeObj obj = null;
		if( ( ! forceRead ) && members.containsKey( pkey ) ) {
			obj = members.get( pkey );
		}
		else {
			CFSecHostNodeBuff readBuff = ((ICFSecSchema)schema.getBackingStore()).getTableHostNode().readDerivedByIdIdx( schema.getAuthorization(),
				pkey.getRequiredClusterId(),
				pkey.getRequiredHostNodeId() );
			if( readBuff != null ) {
				obj = schema.getHostNodeTableObj().newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactoryHostNode().newPKey() );
				obj.setBuff( readBuff );
				obj = (ICFSecHostNodeObj)obj.realise();
			}
		}
		return( obj );
	}

	public ICFSecHostNodeObj readCachedHostNode( CFSecHostNodePKey pkey ) {
		ICFSecHostNodeObj obj = null;
		if( members.containsKey( pkey ) ) {
			obj = members.get( pkey );
		}
		return( obj );
	}

	public void reallyDeepDisposeHostNode( ICFSecHostNodeObj obj )
	{
		final String S_ProcName = "CFSecHostNodeTableObj.reallyDeepDisposeHostNode() ";
		String classCode;
		if( obj == null ) {
			return;
		}
		CFSecHostNodePKey pkey = obj.getPKey();
		ICFSecHostNodeObj existing = readCachedHostNode( pkey );
		if( existing == null ) {
			return;
		}
		members.remove( pkey );
		CFSecHostNodeByClusterIdxKey keyClusterIdx = ((ICFSecSchema)schema.getBackingStore()).getFactoryHostNode().newClusterIdxKey();
		keyClusterIdx.setRequiredClusterId( existing.getRequiredClusterId() );

		CFSecHostNodeByUDescrIdxKey keyUDescrIdx = ((ICFSecSchema)schema.getBackingStore()).getFactoryHostNode().newUDescrIdxKey();
		keyUDescrIdx.setRequiredClusterId( existing.getRequiredClusterId() );
		keyUDescrIdx.setRequiredDescription( existing.getRequiredDescription() );

		CFSecHostNodeByHostNameIdxKey keyHostNameIdx = ((ICFSecSchema)schema.getBackingStore()).getFactoryHostNode().newHostNameIdxKey();
		keyHostNameIdx.setRequiredClusterId( existing.getRequiredClusterId() );
		keyHostNameIdx.setRequiredHostName( existing.getRequiredHostName() );


					schema.getServiceTableObj().deepDisposeServiceByHostIdx( existing.getRequiredClusterId(),
						existing.getRequiredHostNodeId() );

		if( indexByClusterIdx != null ) {
			if( indexByClusterIdx.containsKey( keyClusterIdx ) ) {
				indexByClusterIdx.get( keyClusterIdx ).remove( pkey );
				if( indexByClusterIdx.get( keyClusterIdx ).size() <= 0 ) {
					indexByClusterIdx.remove( keyClusterIdx );
				}
			}
		}

		if( indexByUDescrIdx != null ) {
			indexByUDescrIdx.remove( keyUDescrIdx );
		}

		if( indexByHostNameIdx != null ) {
			indexByHostNameIdx.remove( keyHostNameIdx );
		}


	}
	public void deepDisposeHostNode( CFSecHostNodePKey pkey ) {
		ICFSecHostNodeObj obj = readCachedHostNode( pkey );
		if( obj != null ) {
			obj.forget();
		}
	}

	public ICFSecHostNodeObj lockHostNode( CFSecHostNodePKey pkey ) {
		ICFSecHostNodeObj locked = null;
		CFSecHostNodeBuff lockBuff = ((ICFSecSchema)schema.getBackingStore()).getTableHostNode().lockDerived( schema.getAuthorization(), pkey );
		if( lockBuff != null ) {
				locked = schema.getHostNodeTableObj().newInstance();
			locked.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactoryHostNode().newPKey() );
			locked.setBuff( lockBuff );
			locked = (ICFSecHostNodeObj)locked.realise();
		}
		else {
			throw new CFLibCollisionDetectedException( getClass(), "lockHostNode", pkey );
		}
		return( locked );
	}

	public List<ICFSecHostNodeObj> readAllHostNode() {
		return( readAllHostNode( false ) );
	}

	public List<ICFSecHostNodeObj> readAllHostNode( boolean forceRead ) {
		final String S_ProcName = "readAllHostNode";
		if( ( allHostNode == null ) || forceRead ) {
			Map<CFSecHostNodePKey, ICFSecHostNodeObj> map = new HashMap<CFSecHostNodePKey,ICFSecHostNodeObj>();
			allHostNode = map;
			CFSecHostNodeBuff[] buffList = ((ICFSecSchema)schema.getBackingStore()).getTableHostNode().readAllDerived( schema.getAuthorization() );
			CFSecHostNodeBuff buff;
			ICFSecHostNodeObj obj;
			for( int idx = 0; idx < buffList.length; idx ++ ) {
				buff = buffList[ idx ];
				obj = newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactoryHostNode().newPKey() );
				obj.setBuff( buff );
				ICFSecHostNodeObj realised = (ICFSecHostNodeObj)obj.realise();
			}
		}
		int len = allHostNode.size();
		ICFSecHostNodeObj arr[] = new ICFSecHostNodeObj[len];
		Iterator<ICFSecHostNodeObj> valIter = allHostNode.values().iterator();
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
		ArrayList<ICFSecHostNodeObj> arrayList = new ArrayList<ICFSecHostNodeObj>(len);
		for( idx = 0; idx < len; idx ++ ) {
			arrayList.add( arr[idx] );
		}

		Comparator<ICFSecHostNodeObj> cmp = new Comparator<ICFSecHostNodeObj>() {
			public int compare( ICFSecHostNodeObj lhs, ICFSecHostNodeObj rhs ) {
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
					CFSecHostNodePKey lhsPKey = lhs.getPKey();
					CFSecHostNodePKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		List<ICFSecHostNodeObj> sortedList = arrayList;
		return( sortedList );
	}

	public List<ICFSecHostNodeObj> readCachedAllHostNode() {
		final String S_ProcName = "readCachedAllHostNode";
		ArrayList<ICFSecHostNodeObj> arrayList = new ArrayList<ICFSecHostNodeObj>();
		if( allHostNode != null ) {
			int len = allHostNode.size();
			ICFSecHostNodeObj arr[] = new ICFSecHostNodeObj[len];
			Iterator<ICFSecHostNodeObj> valIter = allHostNode.values().iterator();
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
		Comparator<ICFSecHostNodeObj> cmp = new Comparator<ICFSecHostNodeObj>() {
			public int compare( ICFSecHostNodeObj lhs, ICFSecHostNodeObj rhs ) {
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
					CFSecHostNodePKey lhsPKey = lhs.getPKey();
					CFSecHostNodePKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		return( arrayList );
	}

	/**
	 *	Return a sorted map of a page of the HostNode-derived instances in the database.
	 *
	 *	@return	List of ICFSecHostNodeObj instance, sorted by their primary keys, which
	 *		may include an empty set.
	 */
	public List<ICFSecHostNodeObj> pageAllHostNode(Long priorClusterId,
		Long priorHostNodeId )
	{
		final String S_ProcName = "pageAllHostNode";
		Map<CFSecHostNodePKey, ICFSecHostNodeObj> map = new HashMap<CFSecHostNodePKey,ICFSecHostNodeObj>();
		CFSecHostNodeBuff[] buffList = ((ICFSecSchema)schema.getBackingStore()).getTableHostNode().pageAllBuff( schema.getAuthorization(),
			priorClusterId,
			priorHostNodeId );
		CFSecHostNodeBuff buff;
		ICFSecHostNodeObj obj;
		ICFSecHostNodeObj realised;
		ArrayList<ICFSecHostNodeObj> arrayList = new ArrayList<ICFSecHostNodeObj>( buffList.length );
		for( int idx = 0; idx < buffList.length; idx ++ ) {
			buff = buffList[ idx ];
				obj = newInstance();
			obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactoryHostNode().newPKey() );
			obj.setBuff( buff );
			realised = (ICFSecHostNodeObj)obj.realise();
			arrayList.add( realised );
		}
		return( arrayList );
	}

	public ICFSecHostNodeObj readHostNodeByIdIdx( long ClusterId,
		long HostNodeId )
	{
		return( readHostNodeByIdIdx( ClusterId,
			HostNodeId,
			false ) );
	}

	public ICFSecHostNodeObj readHostNodeByIdIdx( long ClusterId,
		long HostNodeId, boolean forceRead )
	{
		CFSecHostNodePKey pkey = ((ICFSecSchema)schema.getBackingStore()).getFactoryHostNode().newPKey();
		pkey.setRequiredClusterId( ClusterId );
		pkey.setRequiredHostNodeId( HostNodeId );
		ICFSecHostNodeObj obj = readHostNode( pkey, forceRead );
		return( obj );
	}

	public List<ICFSecHostNodeObj> readHostNodeByClusterIdx( long ClusterId )
	{
		return( readHostNodeByClusterIdx( ClusterId,
			false ) );
	}

	public List<ICFSecHostNodeObj> readHostNodeByClusterIdx( long ClusterId,
		boolean forceRead )
	{
		final String S_ProcName = "readHostNodeByClusterIdx";
		CFSecHostNodeByClusterIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryHostNode().newClusterIdxKey();
		key.setRequiredClusterId( ClusterId );
		Map<CFSecHostNodePKey, ICFSecHostNodeObj> dict;
		if( indexByClusterIdx == null ) {
			indexByClusterIdx = new HashMap< CFSecHostNodeByClusterIdxKey,
				Map< CFSecHostNodePKey, ICFSecHostNodeObj > >();
		}
		if( ( ! forceRead ) && indexByClusterIdx.containsKey( key ) ) {
			dict = indexByClusterIdx.get( key );
		}
		else {
			dict = new HashMap<CFSecHostNodePKey, ICFSecHostNodeObj>();
			ICFSecHostNodeObj obj;
			CFSecHostNodeBuff[] buffList = ((ICFSecSchema)schema.getBackingStore()).getTableHostNode().readDerivedByClusterIdx( schema.getAuthorization(),
				ClusterId );
			CFSecHostNodeBuff buff;
			for( int idx = 0; idx < buffList.length; idx ++ ) {
				buff = buffList[ idx ];
				obj = schema.getHostNodeTableObj().newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactoryHostNode().newPKey() );
				obj.setBuff( buff );
				ICFSecHostNodeObj realised = (ICFSecHostNodeObj)obj.realise();
				dict.put( realised.getPKey(), realised );
			}
			indexByClusterIdx.put( key, dict );
		}
		int len = dict.size();
		ICFSecHostNodeObj arr[] = new ICFSecHostNodeObj[len];
		Iterator<ICFSecHostNodeObj> valIter = dict.values().iterator();
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
		ArrayList<ICFSecHostNodeObj> arrayList = new ArrayList<ICFSecHostNodeObj>(len);
		for( idx = 0; idx < len; idx ++ ) {
			arrayList.add( arr[idx] );
		}

		Comparator<ICFSecHostNodeObj> cmp = new Comparator<ICFSecHostNodeObj>() {
			public int compare( ICFSecHostNodeObj lhs, ICFSecHostNodeObj rhs ) {
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
					CFSecHostNodePKey lhsPKey = lhs.getPKey();
					CFSecHostNodePKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		List<ICFSecHostNodeObj> sortedList = arrayList;
		return( sortedList );
	}

	public ICFSecHostNodeObj readHostNodeByUDescrIdx( long ClusterId,
		String Description )
	{
		return( readHostNodeByUDescrIdx( ClusterId,
			Description,
			false ) );
	}

	public ICFSecHostNodeObj readHostNodeByUDescrIdx( long ClusterId,
		String Description, boolean forceRead )
	{
		if( indexByUDescrIdx == null ) {
			indexByUDescrIdx = new HashMap< CFSecHostNodeByUDescrIdxKey,
				ICFSecHostNodeObj >();
		}
		CFSecHostNodeByUDescrIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryHostNode().newUDescrIdxKey();
		key.setRequiredClusterId( ClusterId );
		key.setRequiredDescription( Description );
		ICFSecHostNodeObj obj = null;
		if( ( ! forceRead ) && indexByUDescrIdx.containsKey( key ) ) {
			obj = indexByUDescrIdx.get( key );
		}
		else {
			CFSecHostNodeBuff buff = ((ICFSecSchema)schema.getBackingStore()).getTableHostNode().readDerivedByUDescrIdx( schema.getAuthorization(),
				ClusterId,
				Description );
			if( buff != null ) {
				obj = schema.getHostNodeTableObj().newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactoryHostNode().newPKey() );
				obj.setBuff( buff );
				obj = (ICFSecHostNodeObj)obj.realise();
			}
		}
		return( obj );
	}

	public ICFSecHostNodeObj readHostNodeByHostNameIdx( long ClusterId,
		String HostName )
	{
		return( readHostNodeByHostNameIdx( ClusterId,
			HostName,
			false ) );
	}

	public ICFSecHostNodeObj readHostNodeByHostNameIdx( long ClusterId,
		String HostName, boolean forceRead )
	{
		if( indexByHostNameIdx == null ) {
			indexByHostNameIdx = new HashMap< CFSecHostNodeByHostNameIdxKey,
				ICFSecHostNodeObj >();
		}
		CFSecHostNodeByHostNameIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryHostNode().newHostNameIdxKey();
		key.setRequiredClusterId( ClusterId );
		key.setRequiredHostName( HostName );
		ICFSecHostNodeObj obj = null;
		if( ( ! forceRead ) && indexByHostNameIdx.containsKey( key ) ) {
			obj = indexByHostNameIdx.get( key );
		}
		else {
			CFSecHostNodeBuff buff = ((ICFSecSchema)schema.getBackingStore()).getTableHostNode().readDerivedByHostNameIdx( schema.getAuthorization(),
				ClusterId,
				HostName );
			if( buff != null ) {
				obj = schema.getHostNodeTableObj().newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactoryHostNode().newPKey() );
				obj.setBuff( buff );
				obj = (ICFSecHostNodeObj)obj.realise();
			}
		}
		return( obj );
	}

	public ICFSecHostNodeObj readCachedHostNodeByIdIdx( long ClusterId,
		long HostNodeId )
	{
		ICFSecHostNodeObj obj = null;
		CFSecHostNodePKey pkey = ((ICFSecSchema)schema.getBackingStore()).getFactoryHostNode().newPKey();
		pkey.setRequiredClusterId( ClusterId );
		pkey.setRequiredHostNodeId( HostNodeId );
		obj = readCachedHostNode( pkey );
		return( obj );
	}

	public List<ICFSecHostNodeObj> readCachedHostNodeByClusterIdx( long ClusterId )
	{
		final String S_ProcName = "readCachedHostNodeByClusterIdx";
		CFSecHostNodeByClusterIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryHostNode().newClusterIdxKey();
		key.setRequiredClusterId( ClusterId );
		ArrayList<ICFSecHostNodeObj> arrayList = new ArrayList<ICFSecHostNodeObj>();
		if( indexByClusterIdx != null ) {
			Map<CFSecHostNodePKey, ICFSecHostNodeObj> dict;
			if( indexByClusterIdx.containsKey( key ) ) {
				dict = indexByClusterIdx.get( key );
				int len = dict.size();
				ICFSecHostNodeObj arr[] = new ICFSecHostNodeObj[len];
				Iterator<ICFSecHostNodeObj> valIter = dict.values().iterator();
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
			ICFSecHostNodeObj obj;
			Iterator<ICFSecHostNodeObj> valIter = members.values().iterator();
			while( valIter.hasNext() ) {
				obj = valIter.next();
				if( obj != null ) {
					if( obj.getBuff().compareTo( key ) == 0 ) {
						arrayList.add( obj );
					}
				}
			}
		}
		Comparator<ICFSecHostNodeObj> cmp = new Comparator<ICFSecHostNodeObj>() {
			public int compare( ICFSecHostNodeObj lhs, ICFSecHostNodeObj rhs ) {
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
					CFSecHostNodePKey lhsPKey = lhs.getPKey();
					CFSecHostNodePKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		return( arrayList );
	}

	public ICFSecHostNodeObj readCachedHostNodeByUDescrIdx( long ClusterId,
		String Description )
	{
		ICFSecHostNodeObj obj = null;
		CFSecHostNodeByUDescrIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryHostNode().newUDescrIdxKey();
		key.setRequiredClusterId( ClusterId );
		key.setRequiredDescription( Description );
		if( indexByUDescrIdx != null ) {
			if( indexByUDescrIdx.containsKey( key ) ) {
				obj = indexByUDescrIdx.get( key );
			}
			else {
				Iterator<ICFSecHostNodeObj> valIter = members.values().iterator();
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
			Iterator<ICFSecHostNodeObj> valIter = members.values().iterator();
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

	public ICFSecHostNodeObj readCachedHostNodeByHostNameIdx( long ClusterId,
		String HostName )
	{
		ICFSecHostNodeObj obj = null;
		CFSecHostNodeByHostNameIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryHostNode().newHostNameIdxKey();
		key.setRequiredClusterId( ClusterId );
		key.setRequiredHostName( HostName );
		if( indexByHostNameIdx != null ) {
			if( indexByHostNameIdx.containsKey( key ) ) {
				obj = indexByHostNameIdx.get( key );
			}
			else {
				Iterator<ICFSecHostNodeObj> valIter = members.values().iterator();
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
			Iterator<ICFSecHostNodeObj> valIter = members.values().iterator();
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

	public void deepDisposeHostNodeByIdIdx( long ClusterId,
		long HostNodeId )
	{
		ICFSecHostNodeObj obj = readCachedHostNodeByIdIdx( ClusterId,
				HostNodeId );
		if( obj != null ) {
			obj.forget();
		}
	}

	public void deepDisposeHostNodeByClusterIdx( long ClusterId )
	{
		final String S_ProcName = "deepDisposeHostNodeByClusterIdx";
		ICFSecHostNodeObj obj;
		List<ICFSecHostNodeObj> arrayList = readCachedHostNodeByClusterIdx( ClusterId );
		if( arrayList != null )  {
			Iterator<ICFSecHostNodeObj> arrayIter = arrayList.iterator();
			while( arrayIter.hasNext() ) {
				obj = arrayIter.next();
				if( obj != null ) {
					obj.forget();
				}
			}
		}
	}

	public void deepDisposeHostNodeByUDescrIdx( long ClusterId,
		String Description )
	{
		ICFSecHostNodeObj obj = readCachedHostNodeByUDescrIdx( ClusterId,
				Description );
		if( obj != null ) {
			obj.forget();
		}
	}

	public void deepDisposeHostNodeByHostNameIdx( long ClusterId,
		String HostName )
	{
		ICFSecHostNodeObj obj = readCachedHostNodeByHostNameIdx( ClusterId,
				HostName );
		if( obj != null ) {
			obj.forget();
		}
	}

	/**
	 *	Read a page of data as a List of HostNode-derived instances sorted by their primary keys,
	 *	as identified by the duplicate ClusterIdx key attributes.
	 *
	 *	@param	argClusterId	The HostNode key attribute of the instance generating the id.
	 *
	 *	@return	A List of HostNode-derived instances sorted by their primary keys,
	 *		as identified by the key attributes, which may be an empty set.
	 */
	public List<ICFSecHostNodeObj> pageHostNodeByClusterIdx( long ClusterId,
		Long priorClusterId,
		Long priorHostNodeId )
	{
		final String S_ProcName = "pageHostNodeByClusterIdx";
		CFSecHostNodeByClusterIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryHostNode().newClusterIdxKey();
		key.setRequiredClusterId( ClusterId );
		List<ICFSecHostNodeObj> retList = new LinkedList<ICFSecHostNodeObj>();
		ICFSecHostNodeObj obj;
		CFSecHostNodeBuff[] buffList = ((ICFSecSchema)schema.getBackingStore()).getTableHostNode().pageBuffByClusterIdx( schema.getAuthorization(),
				ClusterId,
			priorClusterId,
			priorHostNodeId );
		CFSecHostNodeBuff buff;
		for( int idx = 0; idx < buffList.length; idx ++ ) {
			buff = buffList[ idx ];
				obj = schema.getHostNodeTableObj().newInstance();
			obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactoryHostNode().newPKey() );
			obj.setBuff( buff );
			ICFSecHostNodeObj realised = (ICFSecHostNodeObj)obj.realise();
			retList.add( realised );
		}
		return( retList );
	}

	public ICFSecHostNodeObj updateHostNode( ICFSecHostNodeObj Obj ) {
		ICFSecHostNodeObj obj = Obj;
		((ICFSecSchema)schema.getBackingStore()).getTableHostNode().updateHostNode( schema.getAuthorization(),
			Obj.getHostNodeBuff() );
		obj = (ICFSecHostNodeObj)Obj.realise();
		obj.endEdit();
		return( obj );
	}

	public void deleteHostNode( ICFSecHostNodeObj Obj ) {
		ICFSecHostNodeObj obj = Obj;
		((ICFSecSchema)schema.getBackingStore()).getTableHostNode().deleteHostNode( schema.getAuthorization(),
			obj.getHostNodeBuff() );
		Obj.forget();
	}

	public void deleteHostNodeByIdIdx( long ClusterId,
		long HostNodeId )
	{
		CFSecHostNodePKey pkey = ((ICFSecSchema)schema.getBackingStore()).getFactoryHostNode().newPKey();
		pkey.setRequiredClusterId( ClusterId );
		pkey.setRequiredHostNodeId( HostNodeId );
		ICFSecHostNodeObj obj = readHostNode( pkey );
		if( obj != null ) {
			ICFSecHostNodeEditObj editObj = (ICFSecHostNodeEditObj)obj.getEdit();
			boolean editStarted;
			if( editObj == null ) {
				editObj = (ICFSecHostNodeEditObj)obj.beginEdit();
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
		deepDisposeHostNodeByIdIdx( ClusterId,
				HostNodeId );
	}

	public void deleteHostNodeByClusterIdx( long ClusterId )
	{
		CFSecHostNodeByClusterIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryHostNode().newClusterIdxKey();
		key.setRequiredClusterId( ClusterId );
		if( indexByClusterIdx == null ) {
			indexByClusterIdx = new HashMap< CFSecHostNodeByClusterIdxKey,
				Map< CFSecHostNodePKey, ICFSecHostNodeObj > >();
		}
		if( indexByClusterIdx.containsKey( key ) ) {
			Map<CFSecHostNodePKey, ICFSecHostNodeObj> dict = indexByClusterIdx.get( key );
			((ICFSecSchema)schema.getBackingStore()).getTableHostNode().deleteHostNodeByClusterIdx( schema.getAuthorization(),
				ClusterId );
			Iterator<ICFSecHostNodeObj> iter = dict.values().iterator();
			ICFSecHostNodeObj obj;
			List<ICFSecHostNodeObj> toForget = new LinkedList<ICFSecHostNodeObj>();
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
			((ICFSecSchema)schema.getBackingStore()).getTableHostNode().deleteHostNodeByClusterIdx( schema.getAuthorization(),
				ClusterId );
		}
		deepDisposeHostNodeByClusterIdx( ClusterId );
	}

	public void deleteHostNodeByUDescrIdx( long ClusterId,
		String Description )
	{
		if( indexByUDescrIdx == null ) {
			indexByUDescrIdx = new HashMap< CFSecHostNodeByUDescrIdxKey,
				ICFSecHostNodeObj >();
		}
		CFSecHostNodeByUDescrIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryHostNode().newUDescrIdxKey();
		key.setRequiredClusterId( ClusterId );
		key.setRequiredDescription( Description );
		ICFSecHostNodeObj obj = null;
		if( indexByUDescrIdx.containsKey( key ) ) {
			obj = indexByUDescrIdx.get( key );
			((ICFSecSchema)schema.getBackingStore()).getTableHostNode().deleteHostNodeByUDescrIdx( schema.getAuthorization(),
				ClusterId,
				Description );
			obj.forget();
		}
		else {
			((ICFSecSchema)schema.getBackingStore()).getTableHostNode().deleteHostNodeByUDescrIdx( schema.getAuthorization(),
				ClusterId,
				Description );
		}
		deepDisposeHostNodeByUDescrIdx( ClusterId,
				Description );
	}

	public void deleteHostNodeByHostNameIdx( long ClusterId,
		String HostName )
	{
		if( indexByHostNameIdx == null ) {
			indexByHostNameIdx = new HashMap< CFSecHostNodeByHostNameIdxKey,
				ICFSecHostNodeObj >();
		}
		CFSecHostNodeByHostNameIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryHostNode().newHostNameIdxKey();
		key.setRequiredClusterId( ClusterId );
		key.setRequiredHostName( HostName );
		ICFSecHostNodeObj obj = null;
		if( indexByHostNameIdx.containsKey( key ) ) {
			obj = indexByHostNameIdx.get( key );
			((ICFSecSchema)schema.getBackingStore()).getTableHostNode().deleteHostNodeByHostNameIdx( schema.getAuthorization(),
				ClusterId,
				HostName );
			obj.forget();
		}
		else {
			((ICFSecSchema)schema.getBackingStore()).getTableHostNode().deleteHostNodeByHostNameIdx( schema.getAuthorization(),
				ClusterId,
				HostName );
		}
		deepDisposeHostNodeByHostNameIdx( ClusterId,
				HostName );
	}
}