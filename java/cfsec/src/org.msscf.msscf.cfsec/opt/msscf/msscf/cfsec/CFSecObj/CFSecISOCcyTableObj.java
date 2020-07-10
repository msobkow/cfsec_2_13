// Description: Java 11 Table Object implementation for CFSec.

/*
 *	com.github.msobkow.CFSec
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

package com.github.msobkow.cfsec.CFSecObj;

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import com.github.msobkow.cflib.CFLib.*;
import com.github.msobkow.cfsec.CFSec.*;

public class CFSecISOCcyTableObj
	implements ICFSecISOCcyTableObj
{
	protected ICFSecSchemaObj schema;
	private Map<CFSecISOCcyPKey, ICFSecISOCcyObj> members;
	private Map<CFSecISOCcyPKey, ICFSecISOCcyObj> allISOCcy;
	private Map< CFSecISOCcyByCcyCdIdxKey,
		ICFSecISOCcyObj > indexByCcyCdIdx;
	private Map< CFSecISOCcyByCcyNmIdxKey,
		ICFSecISOCcyObj > indexByCcyNmIdx;
	public static String TABLE_NAME = "ISOCcy";
	public static String TABLE_DBNAME = "iso_ccy";

	public CFSecISOCcyTableObj() {
		schema = null;
		members = new HashMap<CFSecISOCcyPKey, ICFSecISOCcyObj>();
		allISOCcy = null;
		indexByCcyCdIdx = null;
		indexByCcyNmIdx = null;
	}

	public CFSecISOCcyTableObj( ICFSecSchemaObj argSchema ) {
		schema = (ICFSecSchemaObj)argSchema;
		members = new HashMap<CFSecISOCcyPKey, ICFSecISOCcyObj>();
		allISOCcy = null;
		indexByCcyCdIdx = null;
		indexByCcyNmIdx = null;
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
		allISOCcy = null;
		indexByCcyCdIdx = null;
		indexByCcyNmIdx = null;
		List<ICFSecISOCcyObj> toForget = new LinkedList<ICFSecISOCcyObj>();
		ICFSecISOCcyObj cur = null;
		Iterator<ICFSecISOCcyObj> iter = members.values().iterator();
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
	 *	CFSecISOCcyObj.
	 */
	public ICFSecISOCcyObj newInstance() {
		ICFSecISOCcyObj inst = new CFSecISOCcyObj( schema );
		return( inst );
	}

	/**
	 *	If your implementation subclasses the objects,
	 *	you'll want to overload the constructByClassCode()
	 *	implementation to return your implementation's
	 *	instances instead of the base implementation.
	 *
	 *	This is the sole factory for instances derived from
	 *	CFSecISOCcyObj.
	 */
	public ICFSecISOCcyEditObj newEditInstance( ICFSecISOCcyObj orig ) {
		ICFSecISOCcyEditObj edit = new CFSecISOCcyEditObj( orig );
		return( edit );
	}

	public ICFSecISOCcyObj realiseISOCcy( ICFSecISOCcyObj Obj ) {
		ICFSecISOCcyObj obj = Obj;
		CFSecISOCcyPKey pkey = obj.getPKey();
		ICFSecISOCcyObj keepObj = null;
		if( members.containsKey( pkey ) && ( null != members.get( pkey ) ) ) {
			ICFSecISOCcyObj existingObj = members.get( pkey );
			keepObj = existingObj;

			/*
			 *	We always rebind the data because if we're being called, some index has
			 *	been updated and is refreshing it's data, which may or may not have changed
			 */

			// Detach object from alternate and duplicate indexes, leave PKey alone

			if( indexByCcyCdIdx != null ) {
				CFSecISOCcyByCcyCdIdxKey keyCcyCdIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryISOCcy().newCcyCdIdxKey();
				keyCcyCdIdx.setRequiredISOCode( keepObj.getRequiredISOCode() );
				indexByCcyCdIdx.remove( keyCcyCdIdx );
			}

			if( indexByCcyNmIdx != null ) {
				CFSecISOCcyByCcyNmIdxKey keyCcyNmIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryISOCcy().newCcyNmIdxKey();
				keyCcyNmIdx.setRequiredName( keepObj.getRequiredName() );
				indexByCcyNmIdx.remove( keyCcyNmIdx );
			}

			keepObj.setBuff( Obj.getBuff() );
			// Attach new object to alternate and duplicate indexes -- PKey stay stable

			if( indexByCcyCdIdx != null ) {
				CFSecISOCcyByCcyCdIdxKey keyCcyCdIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryISOCcy().newCcyCdIdxKey();
				keyCcyCdIdx.setRequiredISOCode( keepObj.getRequiredISOCode() );
				indexByCcyCdIdx.put( keyCcyCdIdx, keepObj );
			}

			if( indexByCcyNmIdx != null ) {
				CFSecISOCcyByCcyNmIdxKey keyCcyNmIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryISOCcy().newCcyNmIdxKey();
				keyCcyNmIdx.setRequiredName( keepObj.getRequiredName() );
				indexByCcyNmIdx.put( keyCcyNmIdx, keepObj );
			}

			if( allISOCcy != null ) {
				allISOCcy.put( keepObj.getPKey(), keepObj );
			}
		}
		else {
			keepObj = obj;
			keepObj.setIsNew( false );

			// Attach new object to PKey, all, alternate, and duplicate indexes
			members.put( keepObj.getPKey(), keepObj );
			if( allISOCcy != null ) {
				allISOCcy.put( keepObj.getPKey(), keepObj );
			}

			if( indexByCcyCdIdx != null ) {
				CFSecISOCcyByCcyCdIdxKey keyCcyCdIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryISOCcy().newCcyCdIdxKey();
				keyCcyCdIdx.setRequiredISOCode( keepObj.getRequiredISOCode() );
				indexByCcyCdIdx.put( keyCcyCdIdx, keepObj );
			}

			if( indexByCcyNmIdx != null ) {
				CFSecISOCcyByCcyNmIdxKey keyCcyNmIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryISOCcy().newCcyNmIdxKey();
				keyCcyNmIdx.setRequiredName( keepObj.getRequiredName() );
				indexByCcyNmIdx.put( keyCcyNmIdx, keepObj );
			}

		}
		return( keepObj );
	}

	public ICFSecISOCcyObj createISOCcy( ICFSecISOCcyObj Obj ) {
		ICFSecISOCcyObj obj = Obj;
		CFSecISOCcyBuff buff = obj.getISOCcyBuff();
		((ICFSecSchema)schema.getBackingStore()).getTableISOCcy().createISOCcy(
			schema.getAuthorization(),
			buff );
		obj.copyBuffToPKey();
		obj = obj.realise();
		obj.endEdit();
		return( obj );
	}

	public ICFSecISOCcyObj readISOCcy( CFSecISOCcyPKey pkey ) {
		return( readISOCcy( pkey, false ) );
	}

	public ICFSecISOCcyObj readISOCcy( CFSecISOCcyPKey pkey, boolean forceRead ) {
		ICFSecISOCcyObj obj = null;
		if( ( ! forceRead ) && members.containsKey( pkey ) ) {
			obj = members.get( pkey );
		}
		else {
			CFSecISOCcyBuff readBuff = ((ICFSecSchema)schema.getBackingStore()).getTableISOCcy().readDerivedByIdIdx( schema.getAuthorization(),
				pkey.getRequiredISOCcyId() );
			if( readBuff != null ) {
				obj = schema.getISOCcyTableObj().newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactoryISOCcy().newPKey() );
				obj.setBuff( readBuff );
				obj = (ICFSecISOCcyObj)obj.realise();
			}
		}
		return( obj );
	}

	public ICFSecISOCcyObj readCachedISOCcy( CFSecISOCcyPKey pkey ) {
		ICFSecISOCcyObj obj = null;
		if( members.containsKey( pkey ) ) {
			obj = members.get( pkey );
		}
		return( obj );
	}

	public void reallyDeepDisposeISOCcy( ICFSecISOCcyObj obj )
	{
		final String S_ProcName = "CFSecISOCcyTableObj.reallyDeepDisposeISOCcy() ";
		String classCode;
		if( obj == null ) {
			return;
		}
		CFSecISOCcyPKey pkey = obj.getPKey();
		ICFSecISOCcyObj existing = readCachedISOCcy( pkey );
		if( existing == null ) {
			return;
		}
		members.remove( pkey );
		CFSecISOCcyByCcyCdIdxKey keyCcyCdIdx = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOCcy().newCcyCdIdxKey();
		keyCcyCdIdx.setRequiredISOCode( existing.getRequiredISOCode() );

		CFSecISOCcyByCcyNmIdxKey keyCcyNmIdx = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOCcy().newCcyNmIdxKey();
		keyCcyNmIdx.setRequiredName( existing.getRequiredName() );


		schema.getISOCtryCcyTableObj().deepDisposeISOCtryCcyByCcyIdx( existing.getRequiredISOCcyId() );

		if( indexByCcyCdIdx != null ) {
			indexByCcyCdIdx.remove( keyCcyCdIdx );
		}

		if( indexByCcyNmIdx != null ) {
			indexByCcyNmIdx.remove( keyCcyNmIdx );
		}


	}
	public void deepDisposeISOCcy( CFSecISOCcyPKey pkey ) {
		ICFSecISOCcyObj obj = readCachedISOCcy( pkey );
		if( obj != null ) {
			obj.forget();
		}
	}

	public ICFSecISOCcyObj lockISOCcy( CFSecISOCcyPKey pkey ) {
		ICFSecISOCcyObj locked = null;
		CFSecISOCcyBuff lockBuff = ((ICFSecSchema)schema.getBackingStore()).getTableISOCcy().lockDerived( schema.getAuthorization(), pkey );
		if( lockBuff != null ) {
				locked = schema.getISOCcyTableObj().newInstance();
			locked.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactoryISOCcy().newPKey() );
			locked.setBuff( lockBuff );
			locked = (ICFSecISOCcyObj)locked.realise();
		}
		else {
			throw new CFLibCollisionDetectedException( getClass(), "lockISOCcy", pkey );
		}
		return( locked );
	}

	public List<ICFSecISOCcyObj> readAllISOCcy() {
		return( readAllISOCcy( false ) );
	}

	public List<ICFSecISOCcyObj> readAllISOCcy( boolean forceRead ) {
		final String S_ProcName = "readAllISOCcy";
		if( ( allISOCcy == null ) || forceRead ) {
			Map<CFSecISOCcyPKey, ICFSecISOCcyObj> map = new HashMap<CFSecISOCcyPKey,ICFSecISOCcyObj>();
			allISOCcy = map;
			CFSecISOCcyBuff[] buffList = ((ICFSecSchema)schema.getBackingStore()).getTableISOCcy().readAllDerived( schema.getAuthorization() );
			CFSecISOCcyBuff buff;
			ICFSecISOCcyObj obj;
			for( int idx = 0; idx < buffList.length; idx ++ ) {
				buff = buffList[ idx ];
				obj = newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactoryISOCcy().newPKey() );
				obj.setBuff( buff );
				ICFSecISOCcyObj realised = (ICFSecISOCcyObj)obj.realise();
			}
		}
		int len = allISOCcy.size();
		ICFSecISOCcyObj arr[] = new ICFSecISOCcyObj[len];
		Iterator<ICFSecISOCcyObj> valIter = allISOCcy.values().iterator();
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
		ArrayList<ICFSecISOCcyObj> arrayList = new ArrayList<ICFSecISOCcyObj>(len);
		for( idx = 0; idx < len; idx ++ ) {
			arrayList.add( arr[idx] );
		}

		Comparator<ICFSecISOCcyObj> cmp = new Comparator<ICFSecISOCcyObj>() {
			public int compare( ICFSecISOCcyObj lhs, ICFSecISOCcyObj rhs ) {
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
					CFSecISOCcyPKey lhsPKey = lhs.getPKey();
					CFSecISOCcyPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		List<ICFSecISOCcyObj> sortedList = arrayList;
		return( sortedList );
	}

	public List<ICFSecISOCcyObj> readCachedAllISOCcy() {
		final String S_ProcName = "readCachedAllISOCcy";
		ArrayList<ICFSecISOCcyObj> arrayList = new ArrayList<ICFSecISOCcyObj>();
		if( allISOCcy != null ) {
			int len = allISOCcy.size();
			ICFSecISOCcyObj arr[] = new ICFSecISOCcyObj[len];
			Iterator<ICFSecISOCcyObj> valIter = allISOCcy.values().iterator();
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
		Comparator<ICFSecISOCcyObj> cmp = new Comparator<ICFSecISOCcyObj>() {
			public int compare( ICFSecISOCcyObj lhs, ICFSecISOCcyObj rhs ) {
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
					CFSecISOCcyPKey lhsPKey = lhs.getPKey();
					CFSecISOCcyPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		return( arrayList );
	}

	public ICFSecISOCcyObj readISOCcyByIdIdx( short ISOCcyId )
	{
		return( readISOCcyByIdIdx( ISOCcyId,
			false ) );
	}

	public ICFSecISOCcyObj readISOCcyByIdIdx( short ISOCcyId, boolean forceRead )
	{
		CFSecISOCcyPKey pkey = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOCcy().newPKey();
		pkey.setRequiredISOCcyId( ISOCcyId );
		ICFSecISOCcyObj obj = readISOCcy( pkey, forceRead );
		return( obj );
	}

	public ICFSecISOCcyObj readISOCcyByCcyCdIdx( String ISOCode )
	{
		return( readISOCcyByCcyCdIdx( ISOCode,
			false ) );
	}

	public ICFSecISOCcyObj readISOCcyByCcyCdIdx( String ISOCode, boolean forceRead )
	{
		if( indexByCcyCdIdx == null ) {
			indexByCcyCdIdx = new HashMap< CFSecISOCcyByCcyCdIdxKey,
				ICFSecISOCcyObj >();
		}
		CFSecISOCcyByCcyCdIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOCcy().newCcyCdIdxKey();
		key.setRequiredISOCode( ISOCode );
		ICFSecISOCcyObj obj = null;
		if( ( ! forceRead ) && indexByCcyCdIdx.containsKey( key ) ) {
			obj = indexByCcyCdIdx.get( key );
		}
		else {
			CFSecISOCcyBuff buff = ((ICFSecSchema)schema.getBackingStore()).getTableISOCcy().readDerivedByCcyCdIdx( schema.getAuthorization(),
				ISOCode );
			if( buff != null ) {
				obj = schema.getISOCcyTableObj().newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactoryISOCcy().newPKey() );
				obj.setBuff( buff );
				obj = (ICFSecISOCcyObj)obj.realise();
			}
		}
		return( obj );
	}

	public ICFSecISOCcyObj readISOCcyByCcyNmIdx( String Name )
	{
		return( readISOCcyByCcyNmIdx( Name,
			false ) );
	}

	public ICFSecISOCcyObj readISOCcyByCcyNmIdx( String Name, boolean forceRead )
	{
		if( indexByCcyNmIdx == null ) {
			indexByCcyNmIdx = new HashMap< CFSecISOCcyByCcyNmIdxKey,
				ICFSecISOCcyObj >();
		}
		CFSecISOCcyByCcyNmIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOCcy().newCcyNmIdxKey();
		key.setRequiredName( Name );
		ICFSecISOCcyObj obj = null;
		if( ( ! forceRead ) && indexByCcyNmIdx.containsKey( key ) ) {
			obj = indexByCcyNmIdx.get( key );
		}
		else {
			CFSecISOCcyBuff buff = ((ICFSecSchema)schema.getBackingStore()).getTableISOCcy().readDerivedByCcyNmIdx( schema.getAuthorization(),
				Name );
			if( buff != null ) {
				obj = schema.getISOCcyTableObj().newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactoryISOCcy().newPKey() );
				obj.setBuff( buff );
				obj = (ICFSecISOCcyObj)obj.realise();
			}
		}
		return( obj );
	}

	public ICFSecISOCcyObj readCachedISOCcyByIdIdx( short ISOCcyId )
	{
		ICFSecISOCcyObj obj = null;
		CFSecISOCcyPKey pkey = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOCcy().newPKey();
		pkey.setRequiredISOCcyId( ISOCcyId );
		obj = readCachedISOCcy( pkey );
		return( obj );
	}

	public ICFSecISOCcyObj readCachedISOCcyByCcyCdIdx( String ISOCode )
	{
		ICFSecISOCcyObj obj = null;
		CFSecISOCcyByCcyCdIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOCcy().newCcyCdIdxKey();
		key.setRequiredISOCode( ISOCode );
		if( indexByCcyCdIdx != null ) {
			if( indexByCcyCdIdx.containsKey( key ) ) {
				obj = indexByCcyCdIdx.get( key );
			}
			else {
				Iterator<ICFSecISOCcyObj> valIter = members.values().iterator();
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
			Iterator<ICFSecISOCcyObj> valIter = members.values().iterator();
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

	public ICFSecISOCcyObj readCachedISOCcyByCcyNmIdx( String Name )
	{
		ICFSecISOCcyObj obj = null;
		CFSecISOCcyByCcyNmIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOCcy().newCcyNmIdxKey();
		key.setRequiredName( Name );
		if( indexByCcyNmIdx != null ) {
			if( indexByCcyNmIdx.containsKey( key ) ) {
				obj = indexByCcyNmIdx.get( key );
			}
			else {
				Iterator<ICFSecISOCcyObj> valIter = members.values().iterator();
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
			Iterator<ICFSecISOCcyObj> valIter = members.values().iterator();
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

	public void deepDisposeISOCcyByIdIdx( short ISOCcyId )
	{
		ICFSecISOCcyObj obj = readCachedISOCcyByIdIdx( ISOCcyId );
		if( obj != null ) {
			obj.forget();
		}
	}

	public void deepDisposeISOCcyByCcyCdIdx( String ISOCode )
	{
		ICFSecISOCcyObj obj = readCachedISOCcyByCcyCdIdx( ISOCode );
		if( obj != null ) {
			obj.forget();
		}
	}

	public void deepDisposeISOCcyByCcyNmIdx( String Name )
	{
		ICFSecISOCcyObj obj = readCachedISOCcyByCcyNmIdx( Name );
		if( obj != null ) {
			obj.forget();
		}
	}

	public ICFSecISOCcyObj updateISOCcy( ICFSecISOCcyObj Obj ) {
		ICFSecISOCcyObj obj = Obj;
		((ICFSecSchema)schema.getBackingStore()).getTableISOCcy().updateISOCcy( schema.getAuthorization(),
			Obj.getISOCcyBuff() );
		obj = (ICFSecISOCcyObj)Obj.realise();
		obj.endEdit();
		return( obj );
	}

	public void deleteISOCcy( ICFSecISOCcyObj Obj ) {
		ICFSecISOCcyObj obj = Obj;
		((ICFSecSchema)schema.getBackingStore()).getTableISOCcy().deleteISOCcy( schema.getAuthorization(),
			obj.getISOCcyBuff() );
		Obj.forget();
	}

	public void deleteISOCcyByIdIdx( short ISOCcyId )
	{
		CFSecISOCcyPKey pkey = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOCcy().newPKey();
		pkey.setRequiredISOCcyId( ISOCcyId );
		ICFSecISOCcyObj obj = readISOCcy( pkey );
		if( obj != null ) {
			ICFSecISOCcyEditObj editObj = (ICFSecISOCcyEditObj)obj.getEdit();
			boolean editStarted;
			if( editObj == null ) {
				editObj = (ICFSecISOCcyEditObj)obj.beginEdit();
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
		deepDisposeISOCcyByIdIdx( ISOCcyId );
	}

	public void deleteISOCcyByCcyCdIdx( String ISOCode )
	{
		if( indexByCcyCdIdx == null ) {
			indexByCcyCdIdx = new HashMap< CFSecISOCcyByCcyCdIdxKey,
				ICFSecISOCcyObj >();
		}
		CFSecISOCcyByCcyCdIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOCcy().newCcyCdIdxKey();
		key.setRequiredISOCode( ISOCode );
		ICFSecISOCcyObj obj = null;
		if( indexByCcyCdIdx.containsKey( key ) ) {
			obj = indexByCcyCdIdx.get( key );
			((ICFSecSchema)schema.getBackingStore()).getTableISOCcy().deleteISOCcyByCcyCdIdx( schema.getAuthorization(),
				ISOCode );
			obj.forget();
		}
		else {
			((ICFSecSchema)schema.getBackingStore()).getTableISOCcy().deleteISOCcyByCcyCdIdx( schema.getAuthorization(),
				ISOCode );
		}
		deepDisposeISOCcyByCcyCdIdx( ISOCode );
	}

	public void deleteISOCcyByCcyNmIdx( String Name )
	{
		if( indexByCcyNmIdx == null ) {
			indexByCcyNmIdx = new HashMap< CFSecISOCcyByCcyNmIdxKey,
				ICFSecISOCcyObj >();
		}
		CFSecISOCcyByCcyNmIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOCcy().newCcyNmIdxKey();
		key.setRequiredName( Name );
		ICFSecISOCcyObj obj = null;
		if( indexByCcyNmIdx.containsKey( key ) ) {
			obj = indexByCcyNmIdx.get( key );
			((ICFSecSchema)schema.getBackingStore()).getTableISOCcy().deleteISOCcyByCcyNmIdx( schema.getAuthorization(),
				Name );
			obj.forget();
		}
		else {
			((ICFSecSchema)schema.getBackingStore()).getTableISOCcy().deleteISOCcyByCcyNmIdx( schema.getAuthorization(),
				Name );
		}
		deepDisposeISOCcyByCcyNmIdx( Name );
	}
}