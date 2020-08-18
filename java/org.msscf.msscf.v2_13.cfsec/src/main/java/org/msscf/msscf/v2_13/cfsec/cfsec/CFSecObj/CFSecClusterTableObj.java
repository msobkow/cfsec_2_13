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

package org.msscf.msscf.v2_13.cfsec.cfsec.CFSecObj;

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.msscf.msscf.v2_13.cflib.CFLib.*;
import org.msscf.msscf.cfsec.CFSec.*;

public class CFSecClusterTableObj
	implements ICFSecClusterTableObj
{
	protected ICFSecSchemaObj schema;
	private Map<CFSecClusterPKey, ICFSecClusterObj> members;
	private Map<CFSecClusterPKey, ICFSecClusterObj> allCluster;
	private Map< CFSecClusterByUDomNameIdxKey,
		ICFSecClusterObj > indexByUDomNameIdx;
	private Map< CFSecClusterByUDescrIdxKey,
		ICFSecClusterObj > indexByUDescrIdx;
	public static String TABLE_NAME = "Cluster";
	public static String TABLE_DBNAME = "clus";

	public CFSecClusterTableObj() {
		schema = null;
		members = new HashMap<CFSecClusterPKey, ICFSecClusterObj>();
		allCluster = null;
		indexByUDomNameIdx = null;
		indexByUDescrIdx = null;
	}

	public CFSecClusterTableObj( ICFSecSchemaObj argSchema ) {
		schema = (ICFSecSchemaObj)argSchema;
		members = new HashMap<CFSecClusterPKey, ICFSecClusterObj>();
		allCluster = null;
		indexByUDomNameIdx = null;
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
		allCluster = null;
		indexByUDomNameIdx = null;
		indexByUDescrIdx = null;
		List<ICFSecClusterObj> toForget = new LinkedList<ICFSecClusterObj>();
		ICFSecClusterObj cur = null;
		Iterator<ICFSecClusterObj> iter = members.values().iterator();
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
	 *	CFSecClusterObj.
	 */
	public ICFSecClusterObj newInstance() {
		ICFSecClusterObj inst = new CFSecClusterObj( schema );
		return( inst );
	}

	/**
	 *	If your implementation subclasses the objects,
	 *	you'll want to overload the constructByClassCode()
	 *	implementation to return your implementation's
	 *	instances instead of the base implementation.
	 *
	 *	This is the sole factory for instances derived from
	 *	CFSecClusterObj.
	 */
	public ICFSecClusterEditObj newEditInstance( ICFSecClusterObj orig ) {
		ICFSecClusterEditObj edit = new CFSecClusterEditObj( orig );
		return( edit );
	}

	public ICFSecClusterObj realiseCluster( ICFSecClusterObj Obj ) {
		ICFSecClusterObj obj = Obj;
		CFSecClusterPKey pkey = obj.getPKey();
		ICFSecClusterObj keepObj = null;
		if( members.containsKey( pkey ) && ( null != members.get( pkey ) ) ) {
			ICFSecClusterObj existingObj = members.get( pkey );
			keepObj = existingObj;

			/*
			 *	We always rebind the data because if we're being called, some index has
			 *	been updated and is refreshing it's data, which may or may not have changed
			 */

			// Detach object from alternate and duplicate indexes, leave PKey alone

			if( indexByUDomNameIdx != null ) {
				CFSecClusterByUDomNameIdxKey keyUDomNameIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryCluster().newUDomNameIdxKey();
				keyUDomNameIdx.setRequiredFullDomName( keepObj.getRequiredFullDomName() );
				indexByUDomNameIdx.remove( keyUDomNameIdx );
			}

			if( indexByUDescrIdx != null ) {
				CFSecClusterByUDescrIdxKey keyUDescrIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryCluster().newUDescrIdxKey();
				keyUDescrIdx.setRequiredDescription( keepObj.getRequiredDescription() );
				indexByUDescrIdx.remove( keyUDescrIdx );
			}

			keepObj.setBuff( Obj.getBuff() );
			// Attach new object to alternate and duplicate indexes -- PKey stay stable

			if( indexByUDomNameIdx != null ) {
				CFSecClusterByUDomNameIdxKey keyUDomNameIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryCluster().newUDomNameIdxKey();
				keyUDomNameIdx.setRequiredFullDomName( keepObj.getRequiredFullDomName() );
				indexByUDomNameIdx.put( keyUDomNameIdx, keepObj );
			}

			if( indexByUDescrIdx != null ) {
				CFSecClusterByUDescrIdxKey keyUDescrIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryCluster().newUDescrIdxKey();
				keyUDescrIdx.setRequiredDescription( keepObj.getRequiredDescription() );
				indexByUDescrIdx.put( keyUDescrIdx, keepObj );
			}

			if( allCluster != null ) {
				allCluster.put( keepObj.getPKey(), keepObj );
			}
		}
		else {
			keepObj = obj;
			keepObj.setIsNew( false );

			// Attach new object to PKey, all, alternate, and duplicate indexes
			members.put( keepObj.getPKey(), keepObj );
			if( allCluster != null ) {
				allCluster.put( keepObj.getPKey(), keepObj );
			}

			if( indexByUDomNameIdx != null ) {
				CFSecClusterByUDomNameIdxKey keyUDomNameIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryCluster().newUDomNameIdxKey();
				keyUDomNameIdx.setRequiredFullDomName( keepObj.getRequiredFullDomName() );
				indexByUDomNameIdx.put( keyUDomNameIdx, keepObj );
			}

			if( indexByUDescrIdx != null ) {
				CFSecClusterByUDescrIdxKey keyUDescrIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryCluster().newUDescrIdxKey();
				keyUDescrIdx.setRequiredDescription( keepObj.getRequiredDescription() );
				indexByUDescrIdx.put( keyUDescrIdx, keepObj );
			}

		}
		return( keepObj );
	}

	public ICFSecClusterObj createCluster( ICFSecClusterObj Obj ) {
		ICFSecClusterObj obj = Obj;
		CFSecClusterBuff buff = obj.getClusterBuff();
		((ICFSecSchema)schema.getBackingStore()).getTableCluster().createCluster(
			schema.getAuthorization(),
			buff );
		obj.copyBuffToPKey();
		obj = obj.realise();
		obj.endEdit();
		return( obj );
	}

	public ICFSecClusterObj readCluster( CFSecClusterPKey pkey ) {
		return( readCluster( pkey, false ) );
	}

	public ICFSecClusterObj readCluster( CFSecClusterPKey pkey, boolean forceRead ) {
		ICFSecClusterObj obj = null;
		if( ( ! forceRead ) && members.containsKey( pkey ) ) {
			obj = members.get( pkey );
		}
		else {
			CFSecClusterBuff readBuff = ((ICFSecSchema)schema.getBackingStore()).getTableCluster().readDerivedByIdIdx( schema.getAuthorization(),
				pkey.getRequiredId() );
			if( readBuff != null ) {
				obj = schema.getClusterTableObj().newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactoryCluster().newPKey() );
				obj.setBuff( readBuff );
				obj = (ICFSecClusterObj)obj.realise();
			}
		}
		return( obj );
	}

	public ICFSecClusterObj readCachedCluster( CFSecClusterPKey pkey ) {
		ICFSecClusterObj obj = null;
		if( members.containsKey( pkey ) ) {
			obj = members.get( pkey );
		}
		return( obj );
	}

	public void reallyDeepDisposeCluster( ICFSecClusterObj obj )
	{
		final String S_ProcName = "CFSecClusterTableObj.reallyDeepDisposeCluster() ";
		String classCode;
		if( obj == null ) {
			return;
		}
		CFSecClusterPKey pkey = obj.getPKey();
		ICFSecClusterObj existing = readCachedCluster( pkey );
		if( existing == null ) {
			return;
		}
		members.remove( pkey );
		CFSecClusterByUDomNameIdxKey keyUDomNameIdx = ((ICFSecSchema)schema.getBackingStore()).getFactoryCluster().newUDomNameIdxKey();
		keyUDomNameIdx.setRequiredFullDomName( existing.getRequiredFullDomName() );

		CFSecClusterByUDescrIdxKey keyUDescrIdx = ((ICFSecSchema)schema.getBackingStore()).getFactoryCluster().newUDescrIdxKey();
		keyUDescrIdx.setRequiredDescription( existing.getRequiredDescription() );


		ICFSecSecGroupObj objDelSecGroupForms;
		List<ICFSecSecGroupObj> arrDelSecGroupForms = schema.getSecGroupTableObj().readCachedSecGroupByClusterIdx( existing.getRequiredId() );
		Iterator<ICFSecSecGroupObj> iterDelSecGroupForms = arrDelSecGroupForms.iterator();
		while( iterDelSecGroupForms.hasNext() ) {
			objDelSecGroupForms = iterDelSecGroupForms.next();
			if( objDelSecGroupForms != null ) {
						schema.getSecGroupFormTableObj().deepDisposeSecGroupFormByGroupIdx( objDelSecGroupForms.getRequiredClusterId(),
							objDelSecGroupForms.getRequiredSecGroupId() );
			}
		}
		ICFSecSecGroupObj objDelSecGrpIncByGroup;
		List<ICFSecSecGroupObj> arrDelSecGrpIncByGroup = schema.getSecGroupTableObj().readCachedSecGroupByClusterIdx( existing.getRequiredId() );
		Iterator<ICFSecSecGroupObj> iterDelSecGrpIncByGroup = arrDelSecGrpIncByGroup.iterator();
		while( iterDelSecGrpIncByGroup.hasNext() ) {
			objDelSecGrpIncByGroup = iterDelSecGrpIncByGroup.next();
			if( objDelSecGrpIncByGroup != null ) {
						schema.getSecGrpIncTableObj().deepDisposeSecGrpIncByIncludeIdx( objDelSecGrpIncByGroup.getRequiredClusterId(),
							objDelSecGrpIncByGroup.getRequiredSecGroupId() );
			}
		}
		ICFSecSecGroupObj objDelSecGrpMembs;
		List<ICFSecSecGroupObj> arrDelSecGrpMembs = schema.getSecGroupTableObj().readCachedSecGroupByClusterIdx( existing.getRequiredId() );
		Iterator<ICFSecSecGroupObj> iterDelSecGrpMembs = arrDelSecGrpMembs.iterator();
		while( iterDelSecGrpMembs.hasNext() ) {
			objDelSecGrpMembs = iterDelSecGrpMembs.next();
			if( objDelSecGrpMembs != null ) {
						schema.getSecGrpMembTableObj().deepDisposeSecGrpMembByGroupIdx( objDelSecGrpMembs.getRequiredClusterId(),
							objDelSecGrpMembs.getRequiredSecGroupId() );
			}
		}
		ICFSecSecGroupObj objDelSecGrpIncs;
		List<ICFSecSecGroupObj> arrDelSecGrpIncs = schema.getSecGroupTableObj().readCachedSecGroupByClusterIdx( existing.getRequiredId() );
		Iterator<ICFSecSecGroupObj> iterDelSecGrpIncs = arrDelSecGrpIncs.iterator();
		while( iterDelSecGrpIncs.hasNext() ) {
			objDelSecGrpIncs = iterDelSecGrpIncs.next();
			if( objDelSecGrpIncs != null ) {
						schema.getSecGrpIncTableObj().deepDisposeSecGrpIncByGroupIdx( objDelSecGrpIncs.getRequiredClusterId(),
							objDelSecGrpIncs.getRequiredSecGroupId() );
			}
		}
					schema.getSecGroupTableObj().deepDisposeSecGroupByClusterIdx( existing.getRequiredId() );
		ICFSecSecAppObj objDelSecAppForms;
		List<ICFSecSecAppObj> arrDelSecAppForms = schema.getSecAppTableObj().readCachedSecAppByClusterIdx( existing.getRequiredId() );
		Iterator<ICFSecSecAppObj> iterDelSecAppForms = arrDelSecAppForms.iterator();
		while( iterDelSecAppForms.hasNext() ) {
			objDelSecAppForms = iterDelSecAppForms.next();
			if( objDelSecAppForms != null ) {
						schema.getSecFormTableObj().deepDisposeSecFormBySecAppIdx( objDelSecAppForms.getRequiredClusterId(),
							objDelSecAppForms.getRequiredSecAppId() );
			}
		}
					schema.getSecAppTableObj().deepDisposeSecAppByClusterIdx( existing.getRequiredId() );
					schema.getTenantTableObj().deepDisposeTenantByClusterIdx( existing.getRequiredId() );
					schema.getHostNodeTableObj().deepDisposeHostNodeByClusterIdx( existing.getRequiredId() );

		if( indexByUDomNameIdx != null ) {
			indexByUDomNameIdx.remove( keyUDomNameIdx );
		}

		if( indexByUDescrIdx != null ) {
			indexByUDescrIdx.remove( keyUDescrIdx );
		}


	}
	public void deepDisposeCluster( CFSecClusterPKey pkey ) {
		ICFSecClusterObj obj = readCachedCluster( pkey );
		if( obj != null ) {
			obj.forget();
		}
	}

	public ICFSecClusterObj lockCluster( CFSecClusterPKey pkey ) {
		ICFSecClusterObj locked = null;
		CFSecClusterBuff lockBuff = ((ICFSecSchema)schema.getBackingStore()).getTableCluster().lockDerived( schema.getAuthorization(), pkey );
		if( lockBuff != null ) {
				locked = schema.getClusterTableObj().newInstance();
			locked.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactoryCluster().newPKey() );
			locked.setBuff( lockBuff );
			locked = (ICFSecClusterObj)locked.realise();
		}
		else {
			throw new CFLibCollisionDetectedException( getClass(), "lockCluster", pkey );
		}
		return( locked );
	}

	public List<ICFSecClusterObj> readAllCluster() {
		return( readAllCluster( false ) );
	}

	public List<ICFSecClusterObj> readAllCluster( boolean forceRead ) {
		final String S_ProcName = "readAllCluster";
		if( ( allCluster == null ) || forceRead ) {
			Map<CFSecClusterPKey, ICFSecClusterObj> map = new HashMap<CFSecClusterPKey,ICFSecClusterObj>();
			allCluster = map;
			CFSecClusterBuff[] buffList = ((ICFSecSchema)schema.getBackingStore()).getTableCluster().readAllDerived( schema.getAuthorization() );
			CFSecClusterBuff buff;
			ICFSecClusterObj obj;
			for( int idx = 0; idx < buffList.length; idx ++ ) {
				buff = buffList[ idx ];
				obj = newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactoryCluster().newPKey() );
				obj.setBuff( buff );
				ICFSecClusterObj realised = (ICFSecClusterObj)obj.realise();
			}
		}
		int len = allCluster.size();
		ICFSecClusterObj arr[] = new ICFSecClusterObj[len];
		Iterator<ICFSecClusterObj> valIter = allCluster.values().iterator();
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
		ArrayList<ICFSecClusterObj> arrayList = new ArrayList<ICFSecClusterObj>(len);
		for( idx = 0; idx < len; idx ++ ) {
			arrayList.add( arr[idx] );
		}

		Comparator<ICFSecClusterObj> cmp = new Comparator<ICFSecClusterObj>() {
			public int compare( ICFSecClusterObj lhs, ICFSecClusterObj rhs ) {
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
					CFSecClusterPKey lhsPKey = lhs.getPKey();
					CFSecClusterPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		List<ICFSecClusterObj> sortedList = arrayList;
		return( sortedList );
	}

	public List<ICFSecClusterObj> readCachedAllCluster() {
		final String S_ProcName = "readCachedAllCluster";
		ArrayList<ICFSecClusterObj> arrayList = new ArrayList<ICFSecClusterObj>();
		if( allCluster != null ) {
			int len = allCluster.size();
			ICFSecClusterObj arr[] = new ICFSecClusterObj[len];
			Iterator<ICFSecClusterObj> valIter = allCluster.values().iterator();
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
		Comparator<ICFSecClusterObj> cmp = new Comparator<ICFSecClusterObj>() {
			public int compare( ICFSecClusterObj lhs, ICFSecClusterObj rhs ) {
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
					CFSecClusterPKey lhsPKey = lhs.getPKey();
					CFSecClusterPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		return( arrayList );
	}

	/**
	 *	Return a sorted map of a page of the Cluster-derived instances in the database.
	 *
	 *	@return	List of ICFSecClusterObj instance, sorted by their primary keys, which
	 *		may include an empty set.
	 */
	public List<ICFSecClusterObj> pageAllCluster(Long priorId )
	{
		final String S_ProcName = "pageAllCluster";
		Map<CFSecClusterPKey, ICFSecClusterObj> map = new HashMap<CFSecClusterPKey,ICFSecClusterObj>();
		CFSecClusterBuff[] buffList = ((ICFSecSchema)schema.getBackingStore()).getTableCluster().pageAllBuff( schema.getAuthorization(),
			priorId );
		CFSecClusterBuff buff;
		ICFSecClusterObj obj;
		ICFSecClusterObj realised;
		ArrayList<ICFSecClusterObj> arrayList = new ArrayList<ICFSecClusterObj>( buffList.length );
		for( int idx = 0; idx < buffList.length; idx ++ ) {
			buff = buffList[ idx ];
				obj = newInstance();
			obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactoryCluster().newPKey() );
			obj.setBuff( buff );
			realised = (ICFSecClusterObj)obj.realise();
			arrayList.add( realised );
		}
		return( arrayList );
	}

	public ICFSecClusterObj readClusterByIdIdx( long Id )
	{
		return( readClusterByIdIdx( Id,
			false ) );
	}

	public ICFSecClusterObj readClusterByIdIdx( long Id, boolean forceRead )
	{
		CFSecClusterPKey pkey = ((ICFSecSchema)schema.getBackingStore()).getFactoryCluster().newPKey();
		pkey.setRequiredId( Id );
		ICFSecClusterObj obj = readCluster( pkey, forceRead );
		return( obj );
	}

	public ICFSecClusterObj readClusterByUDomNameIdx( String FullDomName )
	{
		return( readClusterByUDomNameIdx( FullDomName,
			false ) );
	}

	public ICFSecClusterObj readClusterByUDomNameIdx( String FullDomName, boolean forceRead )
	{
		if( indexByUDomNameIdx == null ) {
			indexByUDomNameIdx = new HashMap< CFSecClusterByUDomNameIdxKey,
				ICFSecClusterObj >();
		}
		CFSecClusterByUDomNameIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryCluster().newUDomNameIdxKey();
		key.setRequiredFullDomName( FullDomName );
		ICFSecClusterObj obj = null;
		if( ( ! forceRead ) && indexByUDomNameIdx.containsKey( key ) ) {
			obj = indexByUDomNameIdx.get( key );
		}
		else {
			CFSecClusterBuff buff = ((ICFSecSchema)schema.getBackingStore()).getTableCluster().readDerivedByUDomNameIdx( schema.getAuthorization(),
				FullDomName );
			if( buff != null ) {
				obj = schema.getClusterTableObj().newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactoryCluster().newPKey() );
				obj.setBuff( buff );
				obj = (ICFSecClusterObj)obj.realise();
			}
		}
		return( obj );
	}

	public ICFSecClusterObj readClusterByUDescrIdx( String Description )
	{
		return( readClusterByUDescrIdx( Description,
			false ) );
	}

	public ICFSecClusterObj readClusterByUDescrIdx( String Description, boolean forceRead )
	{
		if( indexByUDescrIdx == null ) {
			indexByUDescrIdx = new HashMap< CFSecClusterByUDescrIdxKey,
				ICFSecClusterObj >();
		}
		CFSecClusterByUDescrIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryCluster().newUDescrIdxKey();
		key.setRequiredDescription( Description );
		ICFSecClusterObj obj = null;
		if( ( ! forceRead ) && indexByUDescrIdx.containsKey( key ) ) {
			obj = indexByUDescrIdx.get( key );
		}
		else {
			CFSecClusterBuff buff = ((ICFSecSchema)schema.getBackingStore()).getTableCluster().readDerivedByUDescrIdx( schema.getAuthorization(),
				Description );
			if( buff != null ) {
				obj = schema.getClusterTableObj().newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactoryCluster().newPKey() );
				obj.setBuff( buff );
				obj = (ICFSecClusterObj)obj.realise();
			}
		}
		return( obj );
	}

	public ICFSecClusterObj readCachedClusterByIdIdx( long Id )
	{
		ICFSecClusterObj obj = null;
		CFSecClusterPKey pkey = ((ICFSecSchema)schema.getBackingStore()).getFactoryCluster().newPKey();
		pkey.setRequiredId( Id );
		obj = readCachedCluster( pkey );
		return( obj );
	}

	public ICFSecClusterObj readCachedClusterByUDomNameIdx( String FullDomName )
	{
		ICFSecClusterObj obj = null;
		CFSecClusterByUDomNameIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryCluster().newUDomNameIdxKey();
		key.setRequiredFullDomName( FullDomName );
		if( indexByUDomNameIdx != null ) {
			if( indexByUDomNameIdx.containsKey( key ) ) {
				obj = indexByUDomNameIdx.get( key );
			}
			else {
				Iterator<ICFSecClusterObj> valIter = members.values().iterator();
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
			Iterator<ICFSecClusterObj> valIter = members.values().iterator();
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

	public ICFSecClusterObj readCachedClusterByUDescrIdx( String Description )
	{
		ICFSecClusterObj obj = null;
		CFSecClusterByUDescrIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryCluster().newUDescrIdxKey();
		key.setRequiredDescription( Description );
		if( indexByUDescrIdx != null ) {
			if( indexByUDescrIdx.containsKey( key ) ) {
				obj = indexByUDescrIdx.get( key );
			}
			else {
				Iterator<ICFSecClusterObj> valIter = members.values().iterator();
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
			Iterator<ICFSecClusterObj> valIter = members.values().iterator();
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

	public void deepDisposeClusterByIdIdx( long Id )
	{
		ICFSecClusterObj obj = readCachedClusterByIdIdx( Id );
		if( obj != null ) {
			obj.forget();
		}
	}

	public void deepDisposeClusterByUDomNameIdx( String FullDomName )
	{
		ICFSecClusterObj obj = readCachedClusterByUDomNameIdx( FullDomName );
		if( obj != null ) {
			obj.forget();
		}
	}

	public void deepDisposeClusterByUDescrIdx( String Description )
	{
		ICFSecClusterObj obj = readCachedClusterByUDescrIdx( Description );
		if( obj != null ) {
			obj.forget();
		}
	}

	public ICFSecClusterObj updateCluster( ICFSecClusterObj Obj ) {
		ICFSecClusterObj obj = Obj;
		((ICFSecSchema)schema.getBackingStore()).getTableCluster().updateCluster( schema.getAuthorization(),
			Obj.getClusterBuff() );
		obj = (ICFSecClusterObj)Obj.realise();
		obj.endEdit();
		return( obj );
	}

	public void deleteCluster( ICFSecClusterObj Obj ) {
		ICFSecClusterObj obj = Obj;
		((ICFSecSchema)schema.getBackingStore()).getTableCluster().deleteCluster( schema.getAuthorization(),
			obj.getClusterBuff() );
		Obj.forget();
	}

	public void deleteClusterByIdIdx( long Id )
	{
		CFSecClusterPKey pkey = ((ICFSecSchema)schema.getBackingStore()).getFactoryCluster().newPKey();
		pkey.setRequiredId( Id );
		ICFSecClusterObj obj = readCluster( pkey );
		if( obj != null ) {
			ICFSecClusterEditObj editObj = (ICFSecClusterEditObj)obj.getEdit();
			boolean editStarted;
			if( editObj == null ) {
				editObj = (ICFSecClusterEditObj)obj.beginEdit();
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
		deepDisposeClusterByIdIdx( Id );
	}

	public void deleteClusterByUDomNameIdx( String FullDomName )
	{
		if( indexByUDomNameIdx == null ) {
			indexByUDomNameIdx = new HashMap< CFSecClusterByUDomNameIdxKey,
				ICFSecClusterObj >();
		}
		CFSecClusterByUDomNameIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryCluster().newUDomNameIdxKey();
		key.setRequiredFullDomName( FullDomName );
		ICFSecClusterObj obj = null;
		if( indexByUDomNameIdx.containsKey( key ) ) {
			obj = indexByUDomNameIdx.get( key );
			((ICFSecSchema)schema.getBackingStore()).getTableCluster().deleteClusterByUDomNameIdx( schema.getAuthorization(),
				FullDomName );
			obj.forget();
		}
		else {
			((ICFSecSchema)schema.getBackingStore()).getTableCluster().deleteClusterByUDomNameIdx( schema.getAuthorization(),
				FullDomName );
		}
		deepDisposeClusterByUDomNameIdx( FullDomName );
	}

	public void deleteClusterByUDescrIdx( String Description )
	{
		if( indexByUDescrIdx == null ) {
			indexByUDescrIdx = new HashMap< CFSecClusterByUDescrIdxKey,
				ICFSecClusterObj >();
		}
		CFSecClusterByUDescrIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryCluster().newUDescrIdxKey();
		key.setRequiredDescription( Description );
		ICFSecClusterObj obj = null;
		if( indexByUDescrIdx.containsKey( key ) ) {
			obj = indexByUDescrIdx.get( key );
			((ICFSecSchema)schema.getBackingStore()).getTableCluster().deleteClusterByUDescrIdx( schema.getAuthorization(),
				Description );
			obj.forget();
		}
		else {
			((ICFSecSchema)schema.getBackingStore()).getTableCluster().deleteClusterByUDescrIdx( schema.getAuthorization(),
				Description );
		}
		deepDisposeClusterByUDescrIdx( Description );
	}

	public ICFSecClusterObj getSystemCluster() {
		boolean transactionStarted = schema.beginTransaction();
		ICFSecClusterObj clusterObj;
		try {
			clusterObj = readClusterByUDomNameIdx( "system" );
			if( clusterObj == null ) {
				clusterObj = newInstance();
				ICFSecClusterEditObj clusterEdit = clusterObj.beginEdit();
				clusterEdit.setRequiredFullDomName( "system" );
				clusterObj = clusterEdit.create();
				clusterEdit = null;
			}
			if( transactionStarted ) {
				schema.commit();
			}
		}
		catch( RuntimeException e ) {
			if( transactionStarted ) {
				try {
					schema.rollback();
				}
				catch( Exception e2 ) {
				}
			}
			throw e;
		}
		return( clusterObj );
	}
}