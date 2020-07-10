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

public class CFSecISOCtryCcyTableObj
	implements ICFSecISOCtryCcyTableObj
{
	protected ICFSecSchemaObj schema;
	private Map<CFSecISOCtryCcyPKey, ICFSecISOCtryCcyObj> members;
	private Map<CFSecISOCtryCcyPKey, ICFSecISOCtryCcyObj> allISOCtryCcy;
	private Map< CFSecISOCtryCcyByCtryIdxKey,
		Map<CFSecISOCtryCcyPKey, ICFSecISOCtryCcyObj > > indexByCtryIdx;
	private Map< CFSecISOCtryCcyByCcyIdxKey,
		Map<CFSecISOCtryCcyPKey, ICFSecISOCtryCcyObj > > indexByCcyIdx;
	public static String TABLE_NAME = "ISOCtryCcy";
	public static String TABLE_DBNAME = "iso_cntryccy";

	public CFSecISOCtryCcyTableObj() {
		schema = null;
		members = new HashMap<CFSecISOCtryCcyPKey, ICFSecISOCtryCcyObj>();
		allISOCtryCcy = null;
		indexByCtryIdx = null;
		indexByCcyIdx = null;
	}

	public CFSecISOCtryCcyTableObj( ICFSecSchemaObj argSchema ) {
		schema = (ICFSecSchemaObj)argSchema;
		members = new HashMap<CFSecISOCtryCcyPKey, ICFSecISOCtryCcyObj>();
		allISOCtryCcy = null;
		indexByCtryIdx = null;
		indexByCcyIdx = null;
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
		allISOCtryCcy = null;
		indexByCtryIdx = null;
		indexByCcyIdx = null;
		List<ICFSecISOCtryCcyObj> toForget = new LinkedList<ICFSecISOCtryCcyObj>();
		ICFSecISOCtryCcyObj cur = null;
		Iterator<ICFSecISOCtryCcyObj> iter = members.values().iterator();
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
	 *	CFSecISOCtryCcyObj.
	 */
	public ICFSecISOCtryCcyObj newInstance() {
		ICFSecISOCtryCcyObj inst = new CFSecISOCtryCcyObj( schema );
		return( inst );
	}

	/**
	 *	If your implementation subclasses the objects,
	 *	you'll want to overload the constructByClassCode()
	 *	implementation to return your implementation's
	 *	instances instead of the base implementation.
	 *
	 *	This is the sole factory for instances derived from
	 *	CFSecISOCtryCcyObj.
	 */
	public ICFSecISOCtryCcyEditObj newEditInstance( ICFSecISOCtryCcyObj orig ) {
		ICFSecISOCtryCcyEditObj edit = new CFSecISOCtryCcyEditObj( orig );
		return( edit );
	}

	public ICFSecISOCtryCcyObj realiseISOCtryCcy( ICFSecISOCtryCcyObj Obj ) {
		ICFSecISOCtryCcyObj obj = Obj;
		CFSecISOCtryCcyPKey pkey = obj.getPKey();
		ICFSecISOCtryCcyObj keepObj = null;
		if( members.containsKey( pkey ) && ( null != members.get( pkey ) ) ) {
			ICFSecISOCtryCcyObj existingObj = members.get( pkey );
			keepObj = existingObj;

			/*
			 *	We always rebind the data because if we're being called, some index has
			 *	been updated and is refreshing it's data, which may or may not have changed
			 */

			// Detach object from alternate and duplicate indexes, leave PKey alone

			if( indexByCtryIdx != null ) {
				CFSecISOCtryCcyByCtryIdxKey keyCtryIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryISOCtryCcy().newCtryIdxKey();
				keyCtryIdx.setRequiredISOCtryId( keepObj.getRequiredISOCtryId() );
				Map<CFSecISOCtryCcyPKey, ICFSecISOCtryCcyObj > mapCtryIdx = indexByCtryIdx.get( keyCtryIdx );
				if( mapCtryIdx != null ) {
					mapCtryIdx.remove( keepObj.getPKey() );
					if( mapCtryIdx.size() <= 0 ) {
						indexByCtryIdx.remove( keyCtryIdx );
					}
				}
			}

			if( indexByCcyIdx != null ) {
				CFSecISOCtryCcyByCcyIdxKey keyCcyIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryISOCtryCcy().newCcyIdxKey();
				keyCcyIdx.setRequiredISOCcyId( keepObj.getRequiredISOCcyId() );
				Map<CFSecISOCtryCcyPKey, ICFSecISOCtryCcyObj > mapCcyIdx = indexByCcyIdx.get( keyCcyIdx );
				if( mapCcyIdx != null ) {
					mapCcyIdx.remove( keepObj.getPKey() );
					if( mapCcyIdx.size() <= 0 ) {
						indexByCcyIdx.remove( keyCcyIdx );
					}
				}
			}

			keepObj.setBuff( Obj.getBuff() );
			// Attach new object to alternate and duplicate indexes -- PKey stay stable

			if( indexByCtryIdx != null ) {
				CFSecISOCtryCcyByCtryIdxKey keyCtryIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryISOCtryCcy().newCtryIdxKey();
				keyCtryIdx.setRequiredISOCtryId( keepObj.getRequiredISOCtryId() );
				Map<CFSecISOCtryCcyPKey, ICFSecISOCtryCcyObj > mapCtryIdx = indexByCtryIdx.get( keyCtryIdx );
				if( mapCtryIdx != null ) {
					mapCtryIdx.put( keepObj.getPKey(), keepObj );
				}
			}

			if( indexByCcyIdx != null ) {
				CFSecISOCtryCcyByCcyIdxKey keyCcyIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryISOCtryCcy().newCcyIdxKey();
				keyCcyIdx.setRequiredISOCcyId( keepObj.getRequiredISOCcyId() );
				Map<CFSecISOCtryCcyPKey, ICFSecISOCtryCcyObj > mapCcyIdx = indexByCcyIdx.get( keyCcyIdx );
				if( mapCcyIdx != null ) {
					mapCcyIdx.put( keepObj.getPKey(), keepObj );
				}
			}

			if( allISOCtryCcy != null ) {
				allISOCtryCcy.put( keepObj.getPKey(), keepObj );
			}
		}
		else {
			keepObj = obj;
			keepObj.setIsNew( false );

			// Attach new object to PKey, all, alternate, and duplicate indexes
			members.put( keepObj.getPKey(), keepObj );
			if( allISOCtryCcy != null ) {
				allISOCtryCcy.put( keepObj.getPKey(), keepObj );
			}

			if( indexByCtryIdx != null ) {
				CFSecISOCtryCcyByCtryIdxKey keyCtryIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryISOCtryCcy().newCtryIdxKey();
				keyCtryIdx.setRequiredISOCtryId( keepObj.getRequiredISOCtryId() );
				Map<CFSecISOCtryCcyPKey, ICFSecISOCtryCcyObj > mapCtryIdx = indexByCtryIdx.get( keyCtryIdx );
				if( mapCtryIdx != null ) {
					mapCtryIdx.put( keepObj.getPKey(), keepObj );
				}
			}

			if( indexByCcyIdx != null ) {
				CFSecISOCtryCcyByCcyIdxKey keyCcyIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryISOCtryCcy().newCcyIdxKey();
				keyCcyIdx.setRequiredISOCcyId( keepObj.getRequiredISOCcyId() );
				Map<CFSecISOCtryCcyPKey, ICFSecISOCtryCcyObj > mapCcyIdx = indexByCcyIdx.get( keyCcyIdx );
				if( mapCcyIdx != null ) {
					mapCcyIdx.put( keepObj.getPKey(), keepObj );
				}
			}

		}
		return( keepObj );
	}

	public ICFSecISOCtryCcyObj createISOCtryCcy( ICFSecISOCtryCcyObj Obj ) {
		ICFSecISOCtryCcyObj obj = Obj;
		CFSecISOCtryCcyBuff buff = obj.getISOCtryCcyBuff();
		((ICFSecSchema)schema.getBackingStore()).getTableISOCtryCcy().createISOCtryCcy(
			schema.getAuthorization(),
			buff );
		obj.copyBuffToPKey();
		obj = obj.realise();
		obj.endEdit();
		return( obj );
	}

	public ICFSecISOCtryCcyObj readISOCtryCcy( CFSecISOCtryCcyPKey pkey ) {
		return( readISOCtryCcy( pkey, false ) );
	}

	public ICFSecISOCtryCcyObj readISOCtryCcy( CFSecISOCtryCcyPKey pkey, boolean forceRead ) {
		ICFSecISOCtryCcyObj obj = null;
		if( ( ! forceRead ) && members.containsKey( pkey ) ) {
			obj = members.get( pkey );
		}
		else {
			CFSecISOCtryCcyBuff readBuff = ((ICFSecSchema)schema.getBackingStore()).getTableISOCtryCcy().readDerivedByIdIdx( schema.getAuthorization(),
				pkey.getRequiredISOCtryId(),
				pkey.getRequiredISOCcyId() );
			if( readBuff != null ) {
				obj = schema.getISOCtryCcyTableObj().newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactoryISOCtryCcy().newPKey() );
				obj.setBuff( readBuff );
				obj = (ICFSecISOCtryCcyObj)obj.realise();
			}
		}
		return( obj );
	}

	public ICFSecISOCtryCcyObj readCachedISOCtryCcy( CFSecISOCtryCcyPKey pkey ) {
		ICFSecISOCtryCcyObj obj = null;
		if( members.containsKey( pkey ) ) {
			obj = members.get( pkey );
		}
		return( obj );
	}

	public void reallyDeepDisposeISOCtryCcy( ICFSecISOCtryCcyObj obj )
	{
		final String S_ProcName = "CFSecISOCtryCcyTableObj.reallyDeepDisposeISOCtryCcy() ";
		String classCode;
		if( obj == null ) {
			return;
		}
		CFSecISOCtryCcyPKey pkey = obj.getPKey();
		ICFSecISOCtryCcyObj existing = readCachedISOCtryCcy( pkey );
		if( existing == null ) {
			return;
		}
		members.remove( pkey );
		CFSecISOCtryCcyByCtryIdxKey keyCtryIdx = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOCtryCcy().newCtryIdxKey();
		keyCtryIdx.setRequiredISOCtryId( existing.getRequiredISOCtryId() );

		CFSecISOCtryCcyByCcyIdxKey keyCcyIdx = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOCtryCcy().newCcyIdxKey();
		keyCcyIdx.setRequiredISOCcyId( existing.getRequiredISOCcyId() );



		if( indexByCtryIdx != null ) {
			if( indexByCtryIdx.containsKey( keyCtryIdx ) ) {
				indexByCtryIdx.get( keyCtryIdx ).remove( pkey );
				if( indexByCtryIdx.get( keyCtryIdx ).size() <= 0 ) {
					indexByCtryIdx.remove( keyCtryIdx );
				}
			}
		}

		if( indexByCcyIdx != null ) {
			if( indexByCcyIdx.containsKey( keyCcyIdx ) ) {
				indexByCcyIdx.get( keyCcyIdx ).remove( pkey );
				if( indexByCcyIdx.get( keyCcyIdx ).size() <= 0 ) {
					indexByCcyIdx.remove( keyCcyIdx );
				}
			}
		}


	}
	public void deepDisposeISOCtryCcy( CFSecISOCtryCcyPKey pkey ) {
		ICFSecISOCtryCcyObj obj = readCachedISOCtryCcy( pkey );
		if( obj != null ) {
			obj.forget();
		}
	}

	public ICFSecISOCtryCcyObj lockISOCtryCcy( CFSecISOCtryCcyPKey pkey ) {
		ICFSecISOCtryCcyObj locked = null;
		CFSecISOCtryCcyBuff lockBuff = ((ICFSecSchema)schema.getBackingStore()).getTableISOCtryCcy().lockDerived( schema.getAuthorization(), pkey );
		if( lockBuff != null ) {
				locked = schema.getISOCtryCcyTableObj().newInstance();
			locked.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactoryISOCtryCcy().newPKey() );
			locked.setBuff( lockBuff );
			locked = (ICFSecISOCtryCcyObj)locked.realise();
		}
		else {
			throw new CFLibCollisionDetectedException( getClass(), "lockISOCtryCcy", pkey );
		}
		return( locked );
	}

	public List<ICFSecISOCtryCcyObj> readAllISOCtryCcy() {
		return( readAllISOCtryCcy( false ) );
	}

	public List<ICFSecISOCtryCcyObj> readAllISOCtryCcy( boolean forceRead ) {
		final String S_ProcName = "readAllISOCtryCcy";
		if( ( allISOCtryCcy == null ) || forceRead ) {
			Map<CFSecISOCtryCcyPKey, ICFSecISOCtryCcyObj> map = new HashMap<CFSecISOCtryCcyPKey,ICFSecISOCtryCcyObj>();
			allISOCtryCcy = map;
			CFSecISOCtryCcyBuff[] buffList = ((ICFSecSchema)schema.getBackingStore()).getTableISOCtryCcy().readAllDerived( schema.getAuthorization() );
			CFSecISOCtryCcyBuff buff;
			ICFSecISOCtryCcyObj obj;
			for( int idx = 0; idx < buffList.length; idx ++ ) {
				buff = buffList[ idx ];
				obj = newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactoryISOCtryCcy().newPKey() );
				obj.setBuff( buff );
				ICFSecISOCtryCcyObj realised = (ICFSecISOCtryCcyObj)obj.realise();
			}
		}
		int len = allISOCtryCcy.size();
		ICFSecISOCtryCcyObj arr[] = new ICFSecISOCtryCcyObj[len];
		Iterator<ICFSecISOCtryCcyObj> valIter = allISOCtryCcy.values().iterator();
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
		ArrayList<ICFSecISOCtryCcyObj> arrayList = new ArrayList<ICFSecISOCtryCcyObj>(len);
		for( idx = 0; idx < len; idx ++ ) {
			arrayList.add( arr[idx] );
		}

		Comparator<ICFSecISOCtryCcyObj> cmp = new Comparator<ICFSecISOCtryCcyObj>() {
			public int compare( ICFSecISOCtryCcyObj lhs, ICFSecISOCtryCcyObj rhs ) {
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
					CFSecISOCtryCcyPKey lhsPKey = lhs.getPKey();
					CFSecISOCtryCcyPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		List<ICFSecISOCtryCcyObj> sortedList = arrayList;
		return( sortedList );
	}

	public List<ICFSecISOCtryCcyObj> readCachedAllISOCtryCcy() {
		final String S_ProcName = "readCachedAllISOCtryCcy";
		ArrayList<ICFSecISOCtryCcyObj> arrayList = new ArrayList<ICFSecISOCtryCcyObj>();
		if( allISOCtryCcy != null ) {
			int len = allISOCtryCcy.size();
			ICFSecISOCtryCcyObj arr[] = new ICFSecISOCtryCcyObj[len];
			Iterator<ICFSecISOCtryCcyObj> valIter = allISOCtryCcy.values().iterator();
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
		Comparator<ICFSecISOCtryCcyObj> cmp = new Comparator<ICFSecISOCtryCcyObj>() {
			public int compare( ICFSecISOCtryCcyObj lhs, ICFSecISOCtryCcyObj rhs ) {
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
					CFSecISOCtryCcyPKey lhsPKey = lhs.getPKey();
					CFSecISOCtryCcyPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		return( arrayList );
	}

	public ICFSecISOCtryCcyObj readISOCtryCcyByIdIdx( short ISOCtryId,
		short ISOCcyId )
	{
		return( readISOCtryCcyByIdIdx( ISOCtryId,
			ISOCcyId,
			false ) );
	}

	public ICFSecISOCtryCcyObj readISOCtryCcyByIdIdx( short ISOCtryId,
		short ISOCcyId, boolean forceRead )
	{
		CFSecISOCtryCcyPKey pkey = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOCtryCcy().newPKey();
		pkey.setRequiredISOCtryId( ISOCtryId );
		pkey.setRequiredISOCcyId( ISOCcyId );
		ICFSecISOCtryCcyObj obj = readISOCtryCcy( pkey, forceRead );
		return( obj );
	}

	public List<ICFSecISOCtryCcyObj> readISOCtryCcyByCtryIdx( short ISOCtryId )
	{
		return( readISOCtryCcyByCtryIdx( ISOCtryId,
			false ) );
	}

	public List<ICFSecISOCtryCcyObj> readISOCtryCcyByCtryIdx( short ISOCtryId,
		boolean forceRead )
	{
		final String S_ProcName = "readISOCtryCcyByCtryIdx";
		CFSecISOCtryCcyByCtryIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOCtryCcy().newCtryIdxKey();
		key.setRequiredISOCtryId( ISOCtryId );
		Map<CFSecISOCtryCcyPKey, ICFSecISOCtryCcyObj> dict;
		if( indexByCtryIdx == null ) {
			indexByCtryIdx = new HashMap< CFSecISOCtryCcyByCtryIdxKey,
				Map< CFSecISOCtryCcyPKey, ICFSecISOCtryCcyObj > >();
		}
		if( ( ! forceRead ) && indexByCtryIdx.containsKey( key ) ) {
			dict = indexByCtryIdx.get( key );
		}
		else {
			dict = new HashMap<CFSecISOCtryCcyPKey, ICFSecISOCtryCcyObj>();
			ICFSecISOCtryCcyObj obj;
			CFSecISOCtryCcyBuff[] buffList = ((ICFSecSchema)schema.getBackingStore()).getTableISOCtryCcy().readDerivedByCtryIdx( schema.getAuthorization(),
				ISOCtryId );
			CFSecISOCtryCcyBuff buff;
			for( int idx = 0; idx < buffList.length; idx ++ ) {
				buff = buffList[ idx ];
				obj = schema.getISOCtryCcyTableObj().newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactoryISOCtryCcy().newPKey() );
				obj.setBuff( buff );
				ICFSecISOCtryCcyObj realised = (ICFSecISOCtryCcyObj)obj.realise();
				dict.put( realised.getPKey(), realised );
			}
			indexByCtryIdx.put( key, dict );
		}
		int len = dict.size();
		ICFSecISOCtryCcyObj arr[] = new ICFSecISOCtryCcyObj[len];
		Iterator<ICFSecISOCtryCcyObj> valIter = dict.values().iterator();
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
		ArrayList<ICFSecISOCtryCcyObj> arrayList = new ArrayList<ICFSecISOCtryCcyObj>(len);
		for( idx = 0; idx < len; idx ++ ) {
			arrayList.add( arr[idx] );
		}

		Comparator<ICFSecISOCtryCcyObj> cmp = new Comparator<ICFSecISOCtryCcyObj>() {
			public int compare( ICFSecISOCtryCcyObj lhs, ICFSecISOCtryCcyObj rhs ) {
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
					CFSecISOCtryCcyPKey lhsPKey = lhs.getPKey();
					CFSecISOCtryCcyPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		List<ICFSecISOCtryCcyObj> sortedList = arrayList;
		return( sortedList );
	}

	public List<ICFSecISOCtryCcyObj> readISOCtryCcyByCcyIdx( short ISOCcyId )
	{
		return( readISOCtryCcyByCcyIdx( ISOCcyId,
			false ) );
	}

	public List<ICFSecISOCtryCcyObj> readISOCtryCcyByCcyIdx( short ISOCcyId,
		boolean forceRead )
	{
		final String S_ProcName = "readISOCtryCcyByCcyIdx";
		CFSecISOCtryCcyByCcyIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOCtryCcy().newCcyIdxKey();
		key.setRequiredISOCcyId( ISOCcyId );
		Map<CFSecISOCtryCcyPKey, ICFSecISOCtryCcyObj> dict;
		if( indexByCcyIdx == null ) {
			indexByCcyIdx = new HashMap< CFSecISOCtryCcyByCcyIdxKey,
				Map< CFSecISOCtryCcyPKey, ICFSecISOCtryCcyObj > >();
		}
		if( ( ! forceRead ) && indexByCcyIdx.containsKey( key ) ) {
			dict = indexByCcyIdx.get( key );
		}
		else {
			dict = new HashMap<CFSecISOCtryCcyPKey, ICFSecISOCtryCcyObj>();
			ICFSecISOCtryCcyObj obj;
			CFSecISOCtryCcyBuff[] buffList = ((ICFSecSchema)schema.getBackingStore()).getTableISOCtryCcy().readDerivedByCcyIdx( schema.getAuthorization(),
				ISOCcyId );
			CFSecISOCtryCcyBuff buff;
			for( int idx = 0; idx < buffList.length; idx ++ ) {
				buff = buffList[ idx ];
				obj = schema.getISOCtryCcyTableObj().newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactoryISOCtryCcy().newPKey() );
				obj.setBuff( buff );
				ICFSecISOCtryCcyObj realised = (ICFSecISOCtryCcyObj)obj.realise();
				dict.put( realised.getPKey(), realised );
			}
			indexByCcyIdx.put( key, dict );
		}
		int len = dict.size();
		ICFSecISOCtryCcyObj arr[] = new ICFSecISOCtryCcyObj[len];
		Iterator<ICFSecISOCtryCcyObj> valIter = dict.values().iterator();
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
		ArrayList<ICFSecISOCtryCcyObj> arrayList = new ArrayList<ICFSecISOCtryCcyObj>(len);
		for( idx = 0; idx < len; idx ++ ) {
			arrayList.add( arr[idx] );
		}

		Comparator<ICFSecISOCtryCcyObj> cmp = new Comparator<ICFSecISOCtryCcyObj>() {
			public int compare( ICFSecISOCtryCcyObj lhs, ICFSecISOCtryCcyObj rhs ) {
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
					CFSecISOCtryCcyPKey lhsPKey = lhs.getPKey();
					CFSecISOCtryCcyPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		List<ICFSecISOCtryCcyObj> sortedList = arrayList;
		return( sortedList );
	}

	public ICFSecISOCtryCcyObj readCachedISOCtryCcyByIdIdx( short ISOCtryId,
		short ISOCcyId )
	{
		ICFSecISOCtryCcyObj obj = null;
		CFSecISOCtryCcyPKey pkey = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOCtryCcy().newPKey();
		pkey.setRequiredISOCtryId( ISOCtryId );
		pkey.setRequiredISOCcyId( ISOCcyId );
		obj = readCachedISOCtryCcy( pkey );
		return( obj );
	}

	public List<ICFSecISOCtryCcyObj> readCachedISOCtryCcyByCtryIdx( short ISOCtryId )
	{
		final String S_ProcName = "readCachedISOCtryCcyByCtryIdx";
		CFSecISOCtryCcyByCtryIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOCtryCcy().newCtryIdxKey();
		key.setRequiredISOCtryId( ISOCtryId );
		ArrayList<ICFSecISOCtryCcyObj> arrayList = new ArrayList<ICFSecISOCtryCcyObj>();
		if( indexByCtryIdx != null ) {
			Map<CFSecISOCtryCcyPKey, ICFSecISOCtryCcyObj> dict;
			if( indexByCtryIdx.containsKey( key ) ) {
				dict = indexByCtryIdx.get( key );
				int len = dict.size();
				ICFSecISOCtryCcyObj arr[] = new ICFSecISOCtryCcyObj[len];
				Iterator<ICFSecISOCtryCcyObj> valIter = dict.values().iterator();
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
			ICFSecISOCtryCcyObj obj;
			Iterator<ICFSecISOCtryCcyObj> valIter = members.values().iterator();
			while( valIter.hasNext() ) {
				obj = valIter.next();
				if( obj != null ) {
					if( obj.getBuff().compareTo( key ) == 0 ) {
						arrayList.add( obj );
					}
				}
			}
		}
		Comparator<ICFSecISOCtryCcyObj> cmp = new Comparator<ICFSecISOCtryCcyObj>() {
			public int compare( ICFSecISOCtryCcyObj lhs, ICFSecISOCtryCcyObj rhs ) {
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
					CFSecISOCtryCcyPKey lhsPKey = lhs.getPKey();
					CFSecISOCtryCcyPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		return( arrayList );
	}

	public List<ICFSecISOCtryCcyObj> readCachedISOCtryCcyByCcyIdx( short ISOCcyId )
	{
		final String S_ProcName = "readCachedISOCtryCcyByCcyIdx";
		CFSecISOCtryCcyByCcyIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOCtryCcy().newCcyIdxKey();
		key.setRequiredISOCcyId( ISOCcyId );
		ArrayList<ICFSecISOCtryCcyObj> arrayList = new ArrayList<ICFSecISOCtryCcyObj>();
		if( indexByCcyIdx != null ) {
			Map<CFSecISOCtryCcyPKey, ICFSecISOCtryCcyObj> dict;
			if( indexByCcyIdx.containsKey( key ) ) {
				dict = indexByCcyIdx.get( key );
				int len = dict.size();
				ICFSecISOCtryCcyObj arr[] = new ICFSecISOCtryCcyObj[len];
				Iterator<ICFSecISOCtryCcyObj> valIter = dict.values().iterator();
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
			ICFSecISOCtryCcyObj obj;
			Iterator<ICFSecISOCtryCcyObj> valIter = members.values().iterator();
			while( valIter.hasNext() ) {
				obj = valIter.next();
				if( obj != null ) {
					if( obj.getBuff().compareTo( key ) == 0 ) {
						arrayList.add( obj );
					}
				}
			}
		}
		Comparator<ICFSecISOCtryCcyObj> cmp = new Comparator<ICFSecISOCtryCcyObj>() {
			public int compare( ICFSecISOCtryCcyObj lhs, ICFSecISOCtryCcyObj rhs ) {
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
					CFSecISOCtryCcyPKey lhsPKey = lhs.getPKey();
					CFSecISOCtryCcyPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		return( arrayList );
	}

	public void deepDisposeISOCtryCcyByIdIdx( short ISOCtryId,
		short ISOCcyId )
	{
		ICFSecISOCtryCcyObj obj = readCachedISOCtryCcyByIdIdx( ISOCtryId,
				ISOCcyId );
		if( obj != null ) {
			obj.forget();
		}
	}

	public void deepDisposeISOCtryCcyByCtryIdx( short ISOCtryId )
	{
		final String S_ProcName = "deepDisposeISOCtryCcyByCtryIdx";
		ICFSecISOCtryCcyObj obj;
		List<ICFSecISOCtryCcyObj> arrayList = readCachedISOCtryCcyByCtryIdx( ISOCtryId );
		if( arrayList != null )  {
			Iterator<ICFSecISOCtryCcyObj> arrayIter = arrayList.iterator();
			while( arrayIter.hasNext() ) {
				obj = arrayIter.next();
				if( obj != null ) {
					obj.forget();
				}
			}
		}
	}

	public void deepDisposeISOCtryCcyByCcyIdx( short ISOCcyId )
	{
		final String S_ProcName = "deepDisposeISOCtryCcyByCcyIdx";
		ICFSecISOCtryCcyObj obj;
		List<ICFSecISOCtryCcyObj> arrayList = readCachedISOCtryCcyByCcyIdx( ISOCcyId );
		if( arrayList != null )  {
			Iterator<ICFSecISOCtryCcyObj> arrayIter = arrayList.iterator();
			while( arrayIter.hasNext() ) {
				obj = arrayIter.next();
				if( obj != null ) {
					obj.forget();
				}
			}
		}
	}

	public ICFSecISOCtryCcyObj updateISOCtryCcy( ICFSecISOCtryCcyObj Obj ) {
		ICFSecISOCtryCcyObj obj = Obj;
		((ICFSecSchema)schema.getBackingStore()).getTableISOCtryCcy().updateISOCtryCcy( schema.getAuthorization(),
			Obj.getISOCtryCcyBuff() );
		obj = (ICFSecISOCtryCcyObj)Obj.realise();
		obj.endEdit();
		return( obj );
	}

	public void deleteISOCtryCcy( ICFSecISOCtryCcyObj Obj ) {
		ICFSecISOCtryCcyObj obj = Obj;
		((ICFSecSchema)schema.getBackingStore()).getTableISOCtryCcy().deleteISOCtryCcy( schema.getAuthorization(),
			obj.getISOCtryCcyBuff() );
		Obj.forget();
	}

	public void deleteISOCtryCcyByIdIdx( short ISOCtryId,
		short ISOCcyId )
	{
		CFSecISOCtryCcyPKey pkey = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOCtryCcy().newPKey();
		pkey.setRequiredISOCtryId( ISOCtryId );
		pkey.setRequiredISOCcyId( ISOCcyId );
		ICFSecISOCtryCcyObj obj = readISOCtryCcy( pkey );
		if( obj != null ) {
			ICFSecISOCtryCcyEditObj editObj = (ICFSecISOCtryCcyEditObj)obj.getEdit();
			boolean editStarted;
			if( editObj == null ) {
				editObj = (ICFSecISOCtryCcyEditObj)obj.beginEdit();
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
		deepDisposeISOCtryCcyByIdIdx( ISOCtryId,
				ISOCcyId );
	}

	public void deleteISOCtryCcyByCtryIdx( short ISOCtryId )
	{
		CFSecISOCtryCcyByCtryIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOCtryCcy().newCtryIdxKey();
		key.setRequiredISOCtryId( ISOCtryId );
		if( indexByCtryIdx == null ) {
			indexByCtryIdx = new HashMap< CFSecISOCtryCcyByCtryIdxKey,
				Map< CFSecISOCtryCcyPKey, ICFSecISOCtryCcyObj > >();
		}
		if( indexByCtryIdx.containsKey( key ) ) {
			Map<CFSecISOCtryCcyPKey, ICFSecISOCtryCcyObj> dict = indexByCtryIdx.get( key );
			((ICFSecSchema)schema.getBackingStore()).getTableISOCtryCcy().deleteISOCtryCcyByCtryIdx( schema.getAuthorization(),
				ISOCtryId );
			Iterator<ICFSecISOCtryCcyObj> iter = dict.values().iterator();
			ICFSecISOCtryCcyObj obj;
			List<ICFSecISOCtryCcyObj> toForget = new LinkedList<ICFSecISOCtryCcyObj>();
			while( iter.hasNext() ) {
				obj = iter.next();
				toForget.add( obj );
			}
			iter = toForget.iterator();
			while( iter.hasNext() ) {
				obj = iter.next();
				obj.forget();
			}
			indexByCtryIdx.remove( key );
		}
		else {
			((ICFSecSchema)schema.getBackingStore()).getTableISOCtryCcy().deleteISOCtryCcyByCtryIdx( schema.getAuthorization(),
				ISOCtryId );
		}
		deepDisposeISOCtryCcyByCtryIdx( ISOCtryId );
	}

	public void deleteISOCtryCcyByCcyIdx( short ISOCcyId )
	{
		CFSecISOCtryCcyByCcyIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOCtryCcy().newCcyIdxKey();
		key.setRequiredISOCcyId( ISOCcyId );
		if( indexByCcyIdx == null ) {
			indexByCcyIdx = new HashMap< CFSecISOCtryCcyByCcyIdxKey,
				Map< CFSecISOCtryCcyPKey, ICFSecISOCtryCcyObj > >();
		}
		if( indexByCcyIdx.containsKey( key ) ) {
			Map<CFSecISOCtryCcyPKey, ICFSecISOCtryCcyObj> dict = indexByCcyIdx.get( key );
			((ICFSecSchema)schema.getBackingStore()).getTableISOCtryCcy().deleteISOCtryCcyByCcyIdx( schema.getAuthorization(),
				ISOCcyId );
			Iterator<ICFSecISOCtryCcyObj> iter = dict.values().iterator();
			ICFSecISOCtryCcyObj obj;
			List<ICFSecISOCtryCcyObj> toForget = new LinkedList<ICFSecISOCtryCcyObj>();
			while( iter.hasNext() ) {
				obj = iter.next();
				toForget.add( obj );
			}
			iter = toForget.iterator();
			while( iter.hasNext() ) {
				obj = iter.next();
				obj.forget();
			}
			indexByCcyIdx.remove( key );
		}
		else {
			((ICFSecSchema)schema.getBackingStore()).getTableISOCtryCcy().deleteISOCtryCcyByCcyIdx( schema.getAuthorization(),
				ISOCcyId );
		}
		deepDisposeISOCtryCcyByCcyIdx( ISOCcyId );
	}
}