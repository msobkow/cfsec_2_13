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

public class CFSecISOTZoneTableObj
	implements ICFSecISOTZoneTableObj
{
	protected ICFSecSchemaObj schema;
	private Map<CFSecISOTZonePKey, ICFSecISOTZoneObj> members;
	private Map<CFSecISOTZonePKey, ICFSecISOTZoneObj> allISOTZone;
	private Map< CFSecISOTZoneByOffsetIdxKey,
		Map<CFSecISOTZonePKey, ICFSecISOTZoneObj > > indexByOffsetIdx;
	private Map< CFSecISOTZoneByUTZNameIdxKey,
		ICFSecISOTZoneObj > indexByUTZNameIdx;
	private Map< CFSecISOTZoneByIso8601IdxKey,
		Map<CFSecISOTZonePKey, ICFSecISOTZoneObj > > indexByIso8601Idx;
	public static String TABLE_NAME = "ISOTZone";
	public static String TABLE_DBNAME = "isotz";

	public CFSecISOTZoneTableObj() {
		schema = null;
		members = new HashMap<CFSecISOTZonePKey, ICFSecISOTZoneObj>();
		allISOTZone = null;
		indexByOffsetIdx = null;
		indexByUTZNameIdx = null;
		indexByIso8601Idx = null;
	}

	public CFSecISOTZoneTableObj( ICFSecSchemaObj argSchema ) {
		schema = (ICFSecSchemaObj)argSchema;
		members = new HashMap<CFSecISOTZonePKey, ICFSecISOTZoneObj>();
		allISOTZone = null;
		indexByOffsetIdx = null;
		indexByUTZNameIdx = null;
		indexByIso8601Idx = null;
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
		allISOTZone = null;
		indexByOffsetIdx = null;
		indexByUTZNameIdx = null;
		indexByIso8601Idx = null;
		List<ICFSecISOTZoneObj> toForget = new LinkedList<ICFSecISOTZoneObj>();
		ICFSecISOTZoneObj cur = null;
		Iterator<ICFSecISOTZoneObj> iter = members.values().iterator();
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
	 *	CFSecISOTZoneObj.
	 */
	public ICFSecISOTZoneObj newInstance() {
		ICFSecISOTZoneObj inst = new CFSecISOTZoneObj( schema );
		return( inst );
	}

	/**
	 *	If your implementation subclasses the objects,
	 *	you'll want to overload the constructByClassCode()
	 *	implementation to return your implementation's
	 *	instances instead of the base implementation.
	 *
	 *	This is the sole factory for instances derived from
	 *	CFSecISOTZoneObj.
	 */
	public ICFSecISOTZoneEditObj newEditInstance( ICFSecISOTZoneObj orig ) {
		ICFSecISOTZoneEditObj edit = new CFSecISOTZoneEditObj( orig );
		return( edit );
	}

	public ICFSecISOTZoneObj realiseISOTZone( ICFSecISOTZoneObj Obj ) {
		ICFSecISOTZoneObj obj = Obj;
		CFSecISOTZonePKey pkey = obj.getPKey();
		ICFSecISOTZoneObj keepObj = null;
		if( members.containsKey( pkey ) && ( null != members.get( pkey ) ) ) {
			ICFSecISOTZoneObj existingObj = members.get( pkey );
			keepObj = existingObj;

			/*
			 *	We always rebind the data because if we're being called, some index has
			 *	been updated and is refreshing it's data, which may or may not have changed
			 */

			// Detach object from alternate and duplicate indexes, leave PKey alone

			if( indexByOffsetIdx != null ) {
				CFSecISOTZoneByOffsetIdxKey keyOffsetIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryISOTZone().newOffsetIdxKey();
				keyOffsetIdx.setRequiredTZHourOffset( keepObj.getRequiredTZHourOffset() );
				keyOffsetIdx.setRequiredTZMinOffset( keepObj.getRequiredTZMinOffset() );
				Map<CFSecISOTZonePKey, ICFSecISOTZoneObj > mapOffsetIdx = indexByOffsetIdx.get( keyOffsetIdx );
				if( mapOffsetIdx != null ) {
					mapOffsetIdx.remove( keepObj.getPKey() );
					if( mapOffsetIdx.size() <= 0 ) {
						indexByOffsetIdx.remove( keyOffsetIdx );
					}
				}
			}

			if( indexByUTZNameIdx != null ) {
				CFSecISOTZoneByUTZNameIdxKey keyUTZNameIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryISOTZone().newUTZNameIdxKey();
				keyUTZNameIdx.setRequiredTZName( keepObj.getRequiredTZName() );
				indexByUTZNameIdx.remove( keyUTZNameIdx );
			}

			if( indexByIso8601Idx != null ) {
				CFSecISOTZoneByIso8601IdxKey keyIso8601Idx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryISOTZone().newIso8601IdxKey();
				keyIso8601Idx.setRequiredIso8601( keepObj.getRequiredIso8601() );
				Map<CFSecISOTZonePKey, ICFSecISOTZoneObj > mapIso8601Idx = indexByIso8601Idx.get( keyIso8601Idx );
				if( mapIso8601Idx != null ) {
					mapIso8601Idx.remove( keepObj.getPKey() );
					if( mapIso8601Idx.size() <= 0 ) {
						indexByIso8601Idx.remove( keyIso8601Idx );
					}
				}
			}

			keepObj.setBuff( Obj.getBuff() );
			// Attach new object to alternate and duplicate indexes -- PKey stay stable

			if( indexByOffsetIdx != null ) {
				CFSecISOTZoneByOffsetIdxKey keyOffsetIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryISOTZone().newOffsetIdxKey();
				keyOffsetIdx.setRequiredTZHourOffset( keepObj.getRequiredTZHourOffset() );
				keyOffsetIdx.setRequiredTZMinOffset( keepObj.getRequiredTZMinOffset() );
				Map<CFSecISOTZonePKey, ICFSecISOTZoneObj > mapOffsetIdx = indexByOffsetIdx.get( keyOffsetIdx );
				if( mapOffsetIdx != null ) {
					mapOffsetIdx.put( keepObj.getPKey(), keepObj );
				}
			}

			if( indexByUTZNameIdx != null ) {
				CFSecISOTZoneByUTZNameIdxKey keyUTZNameIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryISOTZone().newUTZNameIdxKey();
				keyUTZNameIdx.setRequiredTZName( keepObj.getRequiredTZName() );
				indexByUTZNameIdx.put( keyUTZNameIdx, keepObj );
			}

			if( indexByIso8601Idx != null ) {
				CFSecISOTZoneByIso8601IdxKey keyIso8601Idx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryISOTZone().newIso8601IdxKey();
				keyIso8601Idx.setRequiredIso8601( keepObj.getRequiredIso8601() );
				Map<CFSecISOTZonePKey, ICFSecISOTZoneObj > mapIso8601Idx = indexByIso8601Idx.get( keyIso8601Idx );
				if( mapIso8601Idx != null ) {
					mapIso8601Idx.put( keepObj.getPKey(), keepObj );
				}
			}

			if( allISOTZone != null ) {
				allISOTZone.put( keepObj.getPKey(), keepObj );
			}
		}
		else {
			keepObj = obj;
			keepObj.setIsNew( false );

			// Attach new object to PKey, all, alternate, and duplicate indexes
			members.put( keepObj.getPKey(), keepObj );
			if( allISOTZone != null ) {
				allISOTZone.put( keepObj.getPKey(), keepObj );
			}

			if( indexByOffsetIdx != null ) {
				CFSecISOTZoneByOffsetIdxKey keyOffsetIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryISOTZone().newOffsetIdxKey();
				keyOffsetIdx.setRequiredTZHourOffset( keepObj.getRequiredTZHourOffset() );
				keyOffsetIdx.setRequiredTZMinOffset( keepObj.getRequiredTZMinOffset() );
				Map<CFSecISOTZonePKey, ICFSecISOTZoneObj > mapOffsetIdx = indexByOffsetIdx.get( keyOffsetIdx );
				if( mapOffsetIdx != null ) {
					mapOffsetIdx.put( keepObj.getPKey(), keepObj );
				}
			}

			if( indexByUTZNameIdx != null ) {
				CFSecISOTZoneByUTZNameIdxKey keyUTZNameIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryISOTZone().newUTZNameIdxKey();
				keyUTZNameIdx.setRequiredTZName( keepObj.getRequiredTZName() );
				indexByUTZNameIdx.put( keyUTZNameIdx, keepObj );
			}

			if( indexByIso8601Idx != null ) {
				CFSecISOTZoneByIso8601IdxKey keyIso8601Idx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryISOTZone().newIso8601IdxKey();
				keyIso8601Idx.setRequiredIso8601( keepObj.getRequiredIso8601() );
				Map<CFSecISOTZonePKey, ICFSecISOTZoneObj > mapIso8601Idx = indexByIso8601Idx.get( keyIso8601Idx );
				if( mapIso8601Idx != null ) {
					mapIso8601Idx.put( keepObj.getPKey(), keepObj );
				}
			}

		}
		return( keepObj );
	}

	public ICFSecISOTZoneObj createISOTZone( ICFSecISOTZoneObj Obj ) {
		ICFSecISOTZoneObj obj = Obj;
		CFSecISOTZoneBuff buff = obj.getISOTZoneBuff();
		((ICFSecSchema)schema.getBackingStore()).getTableISOTZone().createISOTZone(
			schema.getAuthorization(),
			buff );
		obj.copyBuffToPKey();
		obj = obj.realise();
		obj.endEdit();
		return( obj );
	}

	public ICFSecISOTZoneObj readISOTZone( CFSecISOTZonePKey pkey ) {
		return( readISOTZone( pkey, false ) );
	}

	public ICFSecISOTZoneObj readISOTZone( CFSecISOTZonePKey pkey, boolean forceRead ) {
		ICFSecISOTZoneObj obj = null;
		if( ( ! forceRead ) && members.containsKey( pkey ) ) {
			obj = members.get( pkey );
		}
		else {
			CFSecISOTZoneBuff readBuff = ((ICFSecSchema)schema.getBackingStore()).getTableISOTZone().readDerivedByIdIdx( schema.getAuthorization(),
				pkey.getRequiredISOTZoneId() );
			if( readBuff != null ) {
				obj = schema.getISOTZoneTableObj().newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactoryISOTZone().newPKey() );
				obj.setBuff( readBuff );
				obj = (ICFSecISOTZoneObj)obj.realise();
			}
		}
		return( obj );
	}

	public ICFSecISOTZoneObj readCachedISOTZone( CFSecISOTZonePKey pkey ) {
		ICFSecISOTZoneObj obj = null;
		if( members.containsKey( pkey ) ) {
			obj = members.get( pkey );
		}
		return( obj );
	}

	public void reallyDeepDisposeISOTZone( ICFSecISOTZoneObj obj )
	{
		final String S_ProcName = "CFSecISOTZoneTableObj.reallyDeepDisposeISOTZone() ";
		String classCode;
		if( obj == null ) {
			return;
		}
		CFSecISOTZonePKey pkey = obj.getPKey();
		ICFSecISOTZoneObj existing = readCachedISOTZone( pkey );
		if( existing == null ) {
			return;
		}
		members.remove( pkey );
		CFSecISOTZoneByOffsetIdxKey keyOffsetIdx = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOTZone().newOffsetIdxKey();
		keyOffsetIdx.setRequiredTZHourOffset( existing.getRequiredTZHourOffset() );
		keyOffsetIdx.setRequiredTZMinOffset( existing.getRequiredTZMinOffset() );

		CFSecISOTZoneByUTZNameIdxKey keyUTZNameIdx = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOTZone().newUTZNameIdxKey();
		keyUTZNameIdx.setRequiredTZName( existing.getRequiredTZName() );

		CFSecISOTZoneByIso8601IdxKey keyIso8601Idx = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOTZone().newIso8601IdxKey();
		keyIso8601Idx.setRequiredIso8601( existing.getRequiredIso8601() );



		if( indexByOffsetIdx != null ) {
			if( indexByOffsetIdx.containsKey( keyOffsetIdx ) ) {
				indexByOffsetIdx.get( keyOffsetIdx ).remove( pkey );
				if( indexByOffsetIdx.get( keyOffsetIdx ).size() <= 0 ) {
					indexByOffsetIdx.remove( keyOffsetIdx );
				}
			}
		}

		if( indexByUTZNameIdx != null ) {
			indexByUTZNameIdx.remove( keyUTZNameIdx );
		}

		if( indexByIso8601Idx != null ) {
			if( indexByIso8601Idx.containsKey( keyIso8601Idx ) ) {
				indexByIso8601Idx.get( keyIso8601Idx ).remove( pkey );
				if( indexByIso8601Idx.get( keyIso8601Idx ).size() <= 0 ) {
					indexByIso8601Idx.remove( keyIso8601Idx );
				}
			}
		}


	}
	public void deepDisposeISOTZone( CFSecISOTZonePKey pkey ) {
		ICFSecISOTZoneObj obj = readCachedISOTZone( pkey );
		if( obj != null ) {
			obj.forget();
		}
	}

	public ICFSecISOTZoneObj lockISOTZone( CFSecISOTZonePKey pkey ) {
		ICFSecISOTZoneObj locked = null;
		CFSecISOTZoneBuff lockBuff = ((ICFSecSchema)schema.getBackingStore()).getTableISOTZone().lockDerived( schema.getAuthorization(), pkey );
		if( lockBuff != null ) {
				locked = schema.getISOTZoneTableObj().newInstance();
			locked.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactoryISOTZone().newPKey() );
			locked.setBuff( lockBuff );
			locked = (ICFSecISOTZoneObj)locked.realise();
		}
		else {
			throw new CFLibCollisionDetectedException( getClass(), "lockISOTZone", pkey );
		}
		return( locked );
	}

	public List<ICFSecISOTZoneObj> readAllISOTZone() {
		return( readAllISOTZone( false ) );
	}

	public List<ICFSecISOTZoneObj> readAllISOTZone( boolean forceRead ) {
		final String S_ProcName = "readAllISOTZone";
		if( ( allISOTZone == null ) || forceRead ) {
			Map<CFSecISOTZonePKey, ICFSecISOTZoneObj> map = new HashMap<CFSecISOTZonePKey,ICFSecISOTZoneObj>();
			allISOTZone = map;
			CFSecISOTZoneBuff[] buffList = ((ICFSecSchema)schema.getBackingStore()).getTableISOTZone().readAllDerived( schema.getAuthorization() );
			CFSecISOTZoneBuff buff;
			ICFSecISOTZoneObj obj;
			for( int idx = 0; idx < buffList.length; idx ++ ) {
				buff = buffList[ idx ];
				obj = newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactoryISOTZone().newPKey() );
				obj.setBuff( buff );
				ICFSecISOTZoneObj realised = (ICFSecISOTZoneObj)obj.realise();
			}
		}
		int len = allISOTZone.size();
		ICFSecISOTZoneObj arr[] = new ICFSecISOTZoneObj[len];
		Iterator<ICFSecISOTZoneObj> valIter = allISOTZone.values().iterator();
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
		ArrayList<ICFSecISOTZoneObj> arrayList = new ArrayList<ICFSecISOTZoneObj>(len);
		for( idx = 0; idx < len; idx ++ ) {
			arrayList.add( arr[idx] );
		}

		Comparator<ICFSecISOTZoneObj> cmp = new Comparator<ICFSecISOTZoneObj>() {
			public int compare( ICFSecISOTZoneObj lhs, ICFSecISOTZoneObj rhs ) {
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
					CFSecISOTZonePKey lhsPKey = lhs.getPKey();
					CFSecISOTZonePKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		List<ICFSecISOTZoneObj> sortedList = arrayList;
		return( sortedList );
	}

	public List<ICFSecISOTZoneObj> readCachedAllISOTZone() {
		final String S_ProcName = "readCachedAllISOTZone";
		ArrayList<ICFSecISOTZoneObj> arrayList = new ArrayList<ICFSecISOTZoneObj>();
		if( allISOTZone != null ) {
			int len = allISOTZone.size();
			ICFSecISOTZoneObj arr[] = new ICFSecISOTZoneObj[len];
			Iterator<ICFSecISOTZoneObj> valIter = allISOTZone.values().iterator();
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
		Comparator<ICFSecISOTZoneObj> cmp = new Comparator<ICFSecISOTZoneObj>() {
			public int compare( ICFSecISOTZoneObj lhs, ICFSecISOTZoneObj rhs ) {
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
					CFSecISOTZonePKey lhsPKey = lhs.getPKey();
					CFSecISOTZonePKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		return( arrayList );
	}

	public ICFSecISOTZoneObj readISOTZoneByIdIdx( short ISOTZoneId )
	{
		return( readISOTZoneByIdIdx( ISOTZoneId,
			false ) );
	}

	public ICFSecISOTZoneObj readISOTZoneByIdIdx( short ISOTZoneId, boolean forceRead )
	{
		CFSecISOTZonePKey pkey = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOTZone().newPKey();
		pkey.setRequiredISOTZoneId( ISOTZoneId );
		ICFSecISOTZoneObj obj = readISOTZone( pkey, forceRead );
		return( obj );
	}

	public List<ICFSecISOTZoneObj> readISOTZoneByOffsetIdx( short TZHourOffset,
		short TZMinOffset )
	{
		return( readISOTZoneByOffsetIdx( TZHourOffset,
			TZMinOffset,
			false ) );
	}

	public List<ICFSecISOTZoneObj> readISOTZoneByOffsetIdx( short TZHourOffset,
		short TZMinOffset,
		boolean forceRead )
	{
		final String S_ProcName = "readISOTZoneByOffsetIdx";
		CFSecISOTZoneByOffsetIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOTZone().newOffsetIdxKey();
		key.setRequiredTZHourOffset( TZHourOffset );
		key.setRequiredTZMinOffset( TZMinOffset );
		Map<CFSecISOTZonePKey, ICFSecISOTZoneObj> dict;
		if( indexByOffsetIdx == null ) {
			indexByOffsetIdx = new HashMap< CFSecISOTZoneByOffsetIdxKey,
				Map< CFSecISOTZonePKey, ICFSecISOTZoneObj > >();
		}
		if( ( ! forceRead ) && indexByOffsetIdx.containsKey( key ) ) {
			dict = indexByOffsetIdx.get( key );
		}
		else {
			dict = new HashMap<CFSecISOTZonePKey, ICFSecISOTZoneObj>();
			ICFSecISOTZoneObj obj;
			CFSecISOTZoneBuff[] buffList = ((ICFSecSchema)schema.getBackingStore()).getTableISOTZone().readDerivedByOffsetIdx( schema.getAuthorization(),
				TZHourOffset,
				TZMinOffset );
			CFSecISOTZoneBuff buff;
			for( int idx = 0; idx < buffList.length; idx ++ ) {
				buff = buffList[ idx ];
				obj = schema.getISOTZoneTableObj().newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactoryISOTZone().newPKey() );
				obj.setBuff( buff );
				ICFSecISOTZoneObj realised = (ICFSecISOTZoneObj)obj.realise();
				dict.put( realised.getPKey(), realised );
			}
			indexByOffsetIdx.put( key, dict );
		}
		int len = dict.size();
		ICFSecISOTZoneObj arr[] = new ICFSecISOTZoneObj[len];
		Iterator<ICFSecISOTZoneObj> valIter = dict.values().iterator();
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
		ArrayList<ICFSecISOTZoneObj> arrayList = new ArrayList<ICFSecISOTZoneObj>(len);
		for( idx = 0; idx < len; idx ++ ) {
			arrayList.add( arr[idx] );
		}

		Comparator<ICFSecISOTZoneObj> cmp = new Comparator<ICFSecISOTZoneObj>() {
			public int compare( ICFSecISOTZoneObj lhs, ICFSecISOTZoneObj rhs ) {
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
					CFSecISOTZonePKey lhsPKey = lhs.getPKey();
					CFSecISOTZonePKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		List<ICFSecISOTZoneObj> sortedList = arrayList;
		return( sortedList );
	}

	public ICFSecISOTZoneObj readISOTZoneByUTZNameIdx( String TZName )
	{
		return( readISOTZoneByUTZNameIdx( TZName,
			false ) );
	}

	public ICFSecISOTZoneObj readISOTZoneByUTZNameIdx( String TZName, boolean forceRead )
	{
		if( indexByUTZNameIdx == null ) {
			indexByUTZNameIdx = new HashMap< CFSecISOTZoneByUTZNameIdxKey,
				ICFSecISOTZoneObj >();
		}
		CFSecISOTZoneByUTZNameIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOTZone().newUTZNameIdxKey();
		key.setRequiredTZName( TZName );
		ICFSecISOTZoneObj obj = null;
		if( ( ! forceRead ) && indexByUTZNameIdx.containsKey( key ) ) {
			obj = indexByUTZNameIdx.get( key );
		}
		else {
			CFSecISOTZoneBuff buff = ((ICFSecSchema)schema.getBackingStore()).getTableISOTZone().readDerivedByUTZNameIdx( schema.getAuthorization(),
				TZName );
			if( buff != null ) {
				obj = schema.getISOTZoneTableObj().newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactoryISOTZone().newPKey() );
				obj.setBuff( buff );
				obj = (ICFSecISOTZoneObj)obj.realise();
			}
		}
		return( obj );
	}

	public List<ICFSecISOTZoneObj> readISOTZoneByIso8601Idx( String Iso8601 )
	{
		return( readISOTZoneByIso8601Idx( Iso8601,
			false ) );
	}

	public List<ICFSecISOTZoneObj> readISOTZoneByIso8601Idx( String Iso8601,
		boolean forceRead )
	{
		final String S_ProcName = "readISOTZoneByIso8601Idx";
		CFSecISOTZoneByIso8601IdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOTZone().newIso8601IdxKey();
		key.setRequiredIso8601( Iso8601 );
		Map<CFSecISOTZonePKey, ICFSecISOTZoneObj> dict;
		if( indexByIso8601Idx == null ) {
			indexByIso8601Idx = new HashMap< CFSecISOTZoneByIso8601IdxKey,
				Map< CFSecISOTZonePKey, ICFSecISOTZoneObj > >();
		}
		if( ( ! forceRead ) && indexByIso8601Idx.containsKey( key ) ) {
			dict = indexByIso8601Idx.get( key );
		}
		else {
			dict = new HashMap<CFSecISOTZonePKey, ICFSecISOTZoneObj>();
			ICFSecISOTZoneObj obj;
			CFSecISOTZoneBuff[] buffList = ((ICFSecSchema)schema.getBackingStore()).getTableISOTZone().readDerivedByIso8601Idx( schema.getAuthorization(),
				Iso8601 );
			CFSecISOTZoneBuff buff;
			for( int idx = 0; idx < buffList.length; idx ++ ) {
				buff = buffList[ idx ];
				obj = schema.getISOTZoneTableObj().newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactoryISOTZone().newPKey() );
				obj.setBuff( buff );
				ICFSecISOTZoneObj realised = (ICFSecISOTZoneObj)obj.realise();
				dict.put( realised.getPKey(), realised );
			}
			indexByIso8601Idx.put( key, dict );
		}
		int len = dict.size();
		ICFSecISOTZoneObj arr[] = new ICFSecISOTZoneObj[len];
		Iterator<ICFSecISOTZoneObj> valIter = dict.values().iterator();
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
		ArrayList<ICFSecISOTZoneObj> arrayList = new ArrayList<ICFSecISOTZoneObj>(len);
		for( idx = 0; idx < len; idx ++ ) {
			arrayList.add( arr[idx] );
		}

		Comparator<ICFSecISOTZoneObj> cmp = new Comparator<ICFSecISOTZoneObj>() {
			public int compare( ICFSecISOTZoneObj lhs, ICFSecISOTZoneObj rhs ) {
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
					CFSecISOTZonePKey lhsPKey = lhs.getPKey();
					CFSecISOTZonePKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		List<ICFSecISOTZoneObj> sortedList = arrayList;
		return( sortedList );
	}

	public ICFSecISOTZoneObj readCachedISOTZoneByIdIdx( short ISOTZoneId )
	{
		ICFSecISOTZoneObj obj = null;
		CFSecISOTZonePKey pkey = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOTZone().newPKey();
		pkey.setRequiredISOTZoneId( ISOTZoneId );
		obj = readCachedISOTZone( pkey );
		return( obj );
	}

	public List<ICFSecISOTZoneObj> readCachedISOTZoneByOffsetIdx( short TZHourOffset,
		short TZMinOffset )
	{
		final String S_ProcName = "readCachedISOTZoneByOffsetIdx";
		CFSecISOTZoneByOffsetIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOTZone().newOffsetIdxKey();
		key.setRequiredTZHourOffset( TZHourOffset );
		key.setRequiredTZMinOffset( TZMinOffset );
		ArrayList<ICFSecISOTZoneObj> arrayList = new ArrayList<ICFSecISOTZoneObj>();
		if( indexByOffsetIdx != null ) {
			Map<CFSecISOTZonePKey, ICFSecISOTZoneObj> dict;
			if( indexByOffsetIdx.containsKey( key ) ) {
				dict = indexByOffsetIdx.get( key );
				int len = dict.size();
				ICFSecISOTZoneObj arr[] = new ICFSecISOTZoneObj[len];
				Iterator<ICFSecISOTZoneObj> valIter = dict.values().iterator();
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
			ICFSecISOTZoneObj obj;
			Iterator<ICFSecISOTZoneObj> valIter = members.values().iterator();
			while( valIter.hasNext() ) {
				obj = valIter.next();
				if( obj != null ) {
					if( obj.getBuff().compareTo( key ) == 0 ) {
						arrayList.add( obj );
					}
				}
			}
		}
		Comparator<ICFSecISOTZoneObj> cmp = new Comparator<ICFSecISOTZoneObj>() {
			public int compare( ICFSecISOTZoneObj lhs, ICFSecISOTZoneObj rhs ) {
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
					CFSecISOTZonePKey lhsPKey = lhs.getPKey();
					CFSecISOTZonePKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		return( arrayList );
	}

	public ICFSecISOTZoneObj readCachedISOTZoneByUTZNameIdx( String TZName )
	{
		ICFSecISOTZoneObj obj = null;
		CFSecISOTZoneByUTZNameIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOTZone().newUTZNameIdxKey();
		key.setRequiredTZName( TZName );
		if( indexByUTZNameIdx != null ) {
			if( indexByUTZNameIdx.containsKey( key ) ) {
				obj = indexByUTZNameIdx.get( key );
			}
			else {
				Iterator<ICFSecISOTZoneObj> valIter = members.values().iterator();
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
			Iterator<ICFSecISOTZoneObj> valIter = members.values().iterator();
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

	public List<ICFSecISOTZoneObj> readCachedISOTZoneByIso8601Idx( String Iso8601 )
	{
		final String S_ProcName = "readCachedISOTZoneByIso8601Idx";
		CFSecISOTZoneByIso8601IdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOTZone().newIso8601IdxKey();
		key.setRequiredIso8601( Iso8601 );
		ArrayList<ICFSecISOTZoneObj> arrayList = new ArrayList<ICFSecISOTZoneObj>();
		if( indexByIso8601Idx != null ) {
			Map<CFSecISOTZonePKey, ICFSecISOTZoneObj> dict;
			if( indexByIso8601Idx.containsKey( key ) ) {
				dict = indexByIso8601Idx.get( key );
				int len = dict.size();
				ICFSecISOTZoneObj arr[] = new ICFSecISOTZoneObj[len];
				Iterator<ICFSecISOTZoneObj> valIter = dict.values().iterator();
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
			ICFSecISOTZoneObj obj;
			Iterator<ICFSecISOTZoneObj> valIter = members.values().iterator();
			while( valIter.hasNext() ) {
				obj = valIter.next();
				if( obj != null ) {
					if( obj.getBuff().compareTo( key ) == 0 ) {
						arrayList.add( obj );
					}
				}
			}
		}
		Comparator<ICFSecISOTZoneObj> cmp = new Comparator<ICFSecISOTZoneObj>() {
			public int compare( ICFSecISOTZoneObj lhs, ICFSecISOTZoneObj rhs ) {
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
					CFSecISOTZonePKey lhsPKey = lhs.getPKey();
					CFSecISOTZonePKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		return( arrayList );
	}

	public void deepDisposeISOTZoneByIdIdx( short ISOTZoneId )
	{
		ICFSecISOTZoneObj obj = readCachedISOTZoneByIdIdx( ISOTZoneId );
		if( obj != null ) {
			obj.forget();
		}
	}

	public void deepDisposeISOTZoneByOffsetIdx( short TZHourOffset,
		short TZMinOffset )
	{
		final String S_ProcName = "deepDisposeISOTZoneByOffsetIdx";
		ICFSecISOTZoneObj obj;
		List<ICFSecISOTZoneObj> arrayList = readCachedISOTZoneByOffsetIdx( TZHourOffset,
				TZMinOffset );
		if( arrayList != null )  {
			Iterator<ICFSecISOTZoneObj> arrayIter = arrayList.iterator();
			while( arrayIter.hasNext() ) {
				obj = arrayIter.next();
				if( obj != null ) {
					obj.forget();
				}
			}
		}
	}

	public void deepDisposeISOTZoneByUTZNameIdx( String TZName )
	{
		ICFSecISOTZoneObj obj = readCachedISOTZoneByUTZNameIdx( TZName );
		if( obj != null ) {
			obj.forget();
		}
	}

	public void deepDisposeISOTZoneByIso8601Idx( String Iso8601 )
	{
		final String S_ProcName = "deepDisposeISOTZoneByIso8601Idx";
		ICFSecISOTZoneObj obj;
		List<ICFSecISOTZoneObj> arrayList = readCachedISOTZoneByIso8601Idx( Iso8601 );
		if( arrayList != null )  {
			Iterator<ICFSecISOTZoneObj> arrayIter = arrayList.iterator();
			while( arrayIter.hasNext() ) {
				obj = arrayIter.next();
				if( obj != null ) {
					obj.forget();
				}
			}
		}
	}

	public ICFSecISOTZoneObj updateISOTZone( ICFSecISOTZoneObj Obj ) {
		ICFSecISOTZoneObj obj = Obj;
		((ICFSecSchema)schema.getBackingStore()).getTableISOTZone().updateISOTZone( schema.getAuthorization(),
			Obj.getISOTZoneBuff() );
		obj = (ICFSecISOTZoneObj)Obj.realise();
		obj.endEdit();
		return( obj );
	}

	public void deleteISOTZone( ICFSecISOTZoneObj Obj ) {
		ICFSecISOTZoneObj obj = Obj;
		((ICFSecSchema)schema.getBackingStore()).getTableISOTZone().deleteISOTZone( schema.getAuthorization(),
			obj.getISOTZoneBuff() );
		Obj.forget();
	}

	public void deleteISOTZoneByIdIdx( short ISOTZoneId )
	{
		CFSecISOTZonePKey pkey = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOTZone().newPKey();
		pkey.setRequiredISOTZoneId( ISOTZoneId );
		ICFSecISOTZoneObj obj = readISOTZone( pkey );
		if( obj != null ) {
			ICFSecISOTZoneEditObj editObj = (ICFSecISOTZoneEditObj)obj.getEdit();
			boolean editStarted;
			if( editObj == null ) {
				editObj = (ICFSecISOTZoneEditObj)obj.beginEdit();
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
		deepDisposeISOTZoneByIdIdx( ISOTZoneId );
	}

	public void deleteISOTZoneByOffsetIdx( short TZHourOffset,
		short TZMinOffset )
	{
		CFSecISOTZoneByOffsetIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOTZone().newOffsetIdxKey();
		key.setRequiredTZHourOffset( TZHourOffset );
		key.setRequiredTZMinOffset( TZMinOffset );
		if( indexByOffsetIdx == null ) {
			indexByOffsetIdx = new HashMap< CFSecISOTZoneByOffsetIdxKey,
				Map< CFSecISOTZonePKey, ICFSecISOTZoneObj > >();
		}
		if( indexByOffsetIdx.containsKey( key ) ) {
			Map<CFSecISOTZonePKey, ICFSecISOTZoneObj> dict = indexByOffsetIdx.get( key );
			((ICFSecSchema)schema.getBackingStore()).getTableISOTZone().deleteISOTZoneByOffsetIdx( schema.getAuthorization(),
				TZHourOffset,
				TZMinOffset );
			Iterator<ICFSecISOTZoneObj> iter = dict.values().iterator();
			ICFSecISOTZoneObj obj;
			List<ICFSecISOTZoneObj> toForget = new LinkedList<ICFSecISOTZoneObj>();
			while( iter.hasNext() ) {
				obj = iter.next();
				toForget.add( obj );
			}
			iter = toForget.iterator();
			while( iter.hasNext() ) {
				obj = iter.next();
				obj.forget();
			}
			indexByOffsetIdx.remove( key );
		}
		else {
			((ICFSecSchema)schema.getBackingStore()).getTableISOTZone().deleteISOTZoneByOffsetIdx( schema.getAuthorization(),
				TZHourOffset,
				TZMinOffset );
		}
		deepDisposeISOTZoneByOffsetIdx( TZHourOffset,
				TZMinOffset );
	}

	public void deleteISOTZoneByUTZNameIdx( String TZName )
	{
		if( indexByUTZNameIdx == null ) {
			indexByUTZNameIdx = new HashMap< CFSecISOTZoneByUTZNameIdxKey,
				ICFSecISOTZoneObj >();
		}
		CFSecISOTZoneByUTZNameIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOTZone().newUTZNameIdxKey();
		key.setRequiredTZName( TZName );
		ICFSecISOTZoneObj obj = null;
		if( indexByUTZNameIdx.containsKey( key ) ) {
			obj = indexByUTZNameIdx.get( key );
			((ICFSecSchema)schema.getBackingStore()).getTableISOTZone().deleteISOTZoneByUTZNameIdx( schema.getAuthorization(),
				TZName );
			obj.forget();
		}
		else {
			((ICFSecSchema)schema.getBackingStore()).getTableISOTZone().deleteISOTZoneByUTZNameIdx( schema.getAuthorization(),
				TZName );
		}
		deepDisposeISOTZoneByUTZNameIdx( TZName );
	}

	public void deleteISOTZoneByIso8601Idx( String Iso8601 )
	{
		CFSecISOTZoneByIso8601IdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOTZone().newIso8601IdxKey();
		key.setRequiredIso8601( Iso8601 );
		if( indexByIso8601Idx == null ) {
			indexByIso8601Idx = new HashMap< CFSecISOTZoneByIso8601IdxKey,
				Map< CFSecISOTZonePKey, ICFSecISOTZoneObj > >();
		}
		if( indexByIso8601Idx.containsKey( key ) ) {
			Map<CFSecISOTZonePKey, ICFSecISOTZoneObj> dict = indexByIso8601Idx.get( key );
			((ICFSecSchema)schema.getBackingStore()).getTableISOTZone().deleteISOTZoneByIso8601Idx( schema.getAuthorization(),
				Iso8601 );
			Iterator<ICFSecISOTZoneObj> iter = dict.values().iterator();
			ICFSecISOTZoneObj obj;
			List<ICFSecISOTZoneObj> toForget = new LinkedList<ICFSecISOTZoneObj>();
			while( iter.hasNext() ) {
				obj = iter.next();
				toForget.add( obj );
			}
			iter = toForget.iterator();
			while( iter.hasNext() ) {
				obj = iter.next();
				obj.forget();
			}
			indexByIso8601Idx.remove( key );
		}
		else {
			((ICFSecSchema)schema.getBackingStore()).getTableISOTZone().deleteISOTZoneByIso8601Idx( schema.getAuthorization(),
				Iso8601 );
		}
		deepDisposeISOTZoneByIso8601Idx( Iso8601 );
	}
}