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

public class CFSecISOCtryTableObj
	implements ICFSecISOCtryTableObj
{
	protected ICFSecSchemaObj schema;
	private Map<CFSecISOCtryPKey, ICFSecISOCtryObj> members;
	private Map<CFSecISOCtryPKey, ICFSecISOCtryObj> allISOCtry;
	private Map< CFSecISOCtryByISOCodeIdxKey,
		ICFSecISOCtryObj > indexByISOCodeIdx;
	private Map< CFSecISOCtryByNameIdxKey,
		ICFSecISOCtryObj > indexByNameIdx;
	public static String TABLE_NAME = "ISOCtry";
	public static String TABLE_DBNAME = "iso_cntry";

	public CFSecISOCtryTableObj() {
		schema = null;
		members = new HashMap<CFSecISOCtryPKey, ICFSecISOCtryObj>();
		allISOCtry = null;
		indexByISOCodeIdx = null;
		indexByNameIdx = null;
	}

	public CFSecISOCtryTableObj( ICFSecSchemaObj argSchema ) {
		schema = (ICFSecSchemaObj)argSchema;
		members = new HashMap<CFSecISOCtryPKey, ICFSecISOCtryObj>();
		allISOCtry = null;
		indexByISOCodeIdx = null;
		indexByNameIdx = null;
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
		allISOCtry = null;
		indexByISOCodeIdx = null;
		indexByNameIdx = null;
		List<ICFSecISOCtryObj> toForget = new LinkedList<ICFSecISOCtryObj>();
		ICFSecISOCtryObj cur = null;
		Iterator<ICFSecISOCtryObj> iter = members.values().iterator();
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
	 *	CFSecISOCtryObj.
	 */
	public ICFSecISOCtryObj newInstance() {
		ICFSecISOCtryObj inst = new CFSecISOCtryObj( schema );
		return( inst );
	}

	/**
	 *	If your implementation subclasses the objects,
	 *	you'll want to overload the constructByClassCode()
	 *	implementation to return your implementation's
	 *	instances instead of the base implementation.
	 *
	 *	This is the sole factory for instances derived from
	 *	CFSecISOCtryObj.
	 */
	public ICFSecISOCtryEditObj newEditInstance( ICFSecISOCtryObj orig ) {
		ICFSecISOCtryEditObj edit = new CFSecISOCtryEditObj( orig );
		return( edit );
	}

	public ICFSecISOCtryObj realiseISOCtry( ICFSecISOCtryObj Obj ) {
		ICFSecISOCtryObj obj = Obj;
		CFSecISOCtryPKey pkey = obj.getPKey();
		ICFSecISOCtryObj keepObj = null;
		if( members.containsKey( pkey ) && ( null != members.get( pkey ) ) ) {
			ICFSecISOCtryObj existingObj = members.get( pkey );
			keepObj = existingObj;

			/*
			 *	We always rebind the data because if we're being called, some index has
			 *	been updated and is refreshing it's data, which may or may not have changed
			 */

			// Detach object from alternate and duplicate indexes, leave PKey alone

			if( indexByISOCodeIdx != null ) {
				CFSecISOCtryByISOCodeIdxKey keyISOCodeIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryISOCtry().newISOCodeIdxKey();
				keyISOCodeIdx.setRequiredISOCode( keepObj.getRequiredISOCode() );
				indexByISOCodeIdx.remove( keyISOCodeIdx );
			}

			if( indexByNameIdx != null ) {
				CFSecISOCtryByNameIdxKey keyNameIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryISOCtry().newNameIdxKey();
				keyNameIdx.setRequiredName( keepObj.getRequiredName() );
				indexByNameIdx.remove( keyNameIdx );
			}

			keepObj.setBuff( Obj.getBuff() );
			// Attach new object to alternate and duplicate indexes -- PKey stay stable

			if( indexByISOCodeIdx != null ) {
				CFSecISOCtryByISOCodeIdxKey keyISOCodeIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryISOCtry().newISOCodeIdxKey();
				keyISOCodeIdx.setRequiredISOCode( keepObj.getRequiredISOCode() );
				indexByISOCodeIdx.put( keyISOCodeIdx, keepObj );
			}

			if( indexByNameIdx != null ) {
				CFSecISOCtryByNameIdxKey keyNameIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryISOCtry().newNameIdxKey();
				keyNameIdx.setRequiredName( keepObj.getRequiredName() );
				indexByNameIdx.put( keyNameIdx, keepObj );
			}

			if( allISOCtry != null ) {
				allISOCtry.put( keepObj.getPKey(), keepObj );
			}
		}
		else {
			keepObj = obj;
			keepObj.setIsNew( false );

			// Attach new object to PKey, all, alternate, and duplicate indexes
			members.put( keepObj.getPKey(), keepObj );
			if( allISOCtry != null ) {
				allISOCtry.put( keepObj.getPKey(), keepObj );
			}

			if( indexByISOCodeIdx != null ) {
				CFSecISOCtryByISOCodeIdxKey keyISOCodeIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryISOCtry().newISOCodeIdxKey();
				keyISOCodeIdx.setRequiredISOCode( keepObj.getRequiredISOCode() );
				indexByISOCodeIdx.put( keyISOCodeIdx, keepObj );
			}

			if( indexByNameIdx != null ) {
				CFSecISOCtryByNameIdxKey keyNameIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryISOCtry().newNameIdxKey();
				keyNameIdx.setRequiredName( keepObj.getRequiredName() );
				indexByNameIdx.put( keyNameIdx, keepObj );
			}

		}
		return( keepObj );
	}

	public ICFSecISOCtryObj createISOCtry( ICFSecISOCtryObj Obj ) {
		ICFSecISOCtryObj obj = Obj;
		CFSecISOCtryBuff buff = obj.getISOCtryBuff();
		((ICFSecSchema)schema.getBackingStore()).getTableISOCtry().createISOCtry(
			schema.getAuthorization(),
			buff );
		obj.copyBuffToPKey();
		obj = obj.realise();
		obj.endEdit();
		return( obj );
	}

	public ICFSecISOCtryObj readISOCtry( CFSecISOCtryPKey pkey ) {
		return( readISOCtry( pkey, false ) );
	}

	public ICFSecISOCtryObj readISOCtry( CFSecISOCtryPKey pkey, boolean forceRead ) {
		ICFSecISOCtryObj obj = null;
		if( ( ! forceRead ) && members.containsKey( pkey ) ) {
			obj = members.get( pkey );
		}
		else {
			CFSecISOCtryBuff readBuff = ((ICFSecSchema)schema.getBackingStore()).getTableISOCtry().readDerivedByIdIdx( schema.getAuthorization(),
				pkey.getRequiredISOCtryId() );
			if( readBuff != null ) {
				obj = schema.getISOCtryTableObj().newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactoryISOCtry().newPKey() );
				obj.setBuff( readBuff );
				obj = (ICFSecISOCtryObj)obj.realise();
			}
		}
		return( obj );
	}

	public ICFSecISOCtryObj readCachedISOCtry( CFSecISOCtryPKey pkey ) {
		ICFSecISOCtryObj obj = null;
		if( members.containsKey( pkey ) ) {
			obj = members.get( pkey );
		}
		return( obj );
	}

	public void reallyDeepDisposeISOCtry( ICFSecISOCtryObj obj )
	{
		final String S_ProcName = "CFSecISOCtryTableObj.reallyDeepDisposeISOCtry() ";
		String classCode;
		if( obj == null ) {
			return;
		}
		CFSecISOCtryPKey pkey = obj.getPKey();
		ICFSecISOCtryObj existing = readCachedISOCtry( pkey );
		if( existing == null ) {
			return;
		}
		members.remove( pkey );
		CFSecISOCtryByISOCodeIdxKey keyISOCodeIdx = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOCtry().newISOCodeIdxKey();
		keyISOCodeIdx.setRequiredISOCode( existing.getRequiredISOCode() );

		CFSecISOCtryByNameIdxKey keyNameIdx = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOCtry().newNameIdxKey();
		keyNameIdx.setRequiredName( existing.getRequiredName() );


					schema.getISOCtryLangTableObj().deepDisposeISOCtryLangByCtryIdx( existing.getRequiredISOCtryId() );
					schema.getISOCtryCcyTableObj().deepDisposeISOCtryCcyByCtryIdx( existing.getRequiredISOCtryId() );

		if( indexByISOCodeIdx != null ) {
			indexByISOCodeIdx.remove( keyISOCodeIdx );
		}

		if( indexByNameIdx != null ) {
			indexByNameIdx.remove( keyNameIdx );
		}


	}
	public void deepDisposeISOCtry( CFSecISOCtryPKey pkey ) {
		ICFSecISOCtryObj obj = readCachedISOCtry( pkey );
		if( obj != null ) {
			obj.forget();
		}
	}

	public ICFSecISOCtryObj lockISOCtry( CFSecISOCtryPKey pkey ) {
		ICFSecISOCtryObj locked = null;
		CFSecISOCtryBuff lockBuff = ((ICFSecSchema)schema.getBackingStore()).getTableISOCtry().lockDerived( schema.getAuthorization(), pkey );
		if( lockBuff != null ) {
				locked = schema.getISOCtryTableObj().newInstance();
			locked.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactoryISOCtry().newPKey() );
			locked.setBuff( lockBuff );
			locked = (ICFSecISOCtryObj)locked.realise();
		}
		else {
			throw new CFLibCollisionDetectedException( getClass(), "lockISOCtry", pkey );
		}
		return( locked );
	}

	public List<ICFSecISOCtryObj> readAllISOCtry() {
		return( readAllISOCtry( false ) );
	}

	public List<ICFSecISOCtryObj> readAllISOCtry( boolean forceRead ) {
		final String S_ProcName = "readAllISOCtry";
		if( ( allISOCtry == null ) || forceRead ) {
			Map<CFSecISOCtryPKey, ICFSecISOCtryObj> map = new HashMap<CFSecISOCtryPKey,ICFSecISOCtryObj>();
			allISOCtry = map;
			CFSecISOCtryBuff[] buffList = ((ICFSecSchema)schema.getBackingStore()).getTableISOCtry().readAllDerived( schema.getAuthorization() );
			CFSecISOCtryBuff buff;
			ICFSecISOCtryObj obj;
			for( int idx = 0; idx < buffList.length; idx ++ ) {
				buff = buffList[ idx ];
				obj = newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactoryISOCtry().newPKey() );
				obj.setBuff( buff );
				ICFSecISOCtryObj realised = (ICFSecISOCtryObj)obj.realise();
			}
		}
		int len = allISOCtry.size();
		ICFSecISOCtryObj arr[] = new ICFSecISOCtryObj[len];
		Iterator<ICFSecISOCtryObj> valIter = allISOCtry.values().iterator();
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
		ArrayList<ICFSecISOCtryObj> arrayList = new ArrayList<ICFSecISOCtryObj>(len);
		for( idx = 0; idx < len; idx ++ ) {
			arrayList.add( arr[idx] );
		}

		Comparator<ICFSecISOCtryObj> cmp = new Comparator<ICFSecISOCtryObj>() {
			public int compare( ICFSecISOCtryObj lhs, ICFSecISOCtryObj rhs ) {
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
					CFSecISOCtryPKey lhsPKey = lhs.getPKey();
					CFSecISOCtryPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		List<ICFSecISOCtryObj> sortedList = arrayList;
		return( sortedList );
	}

	public List<ICFSecISOCtryObj> readCachedAllISOCtry() {
		final String S_ProcName = "readCachedAllISOCtry";
		ArrayList<ICFSecISOCtryObj> arrayList = new ArrayList<ICFSecISOCtryObj>();
		if( allISOCtry != null ) {
			int len = allISOCtry.size();
			ICFSecISOCtryObj arr[] = new ICFSecISOCtryObj[len];
			Iterator<ICFSecISOCtryObj> valIter = allISOCtry.values().iterator();
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
		Comparator<ICFSecISOCtryObj> cmp = new Comparator<ICFSecISOCtryObj>() {
			public int compare( ICFSecISOCtryObj lhs, ICFSecISOCtryObj rhs ) {
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
					CFSecISOCtryPKey lhsPKey = lhs.getPKey();
					CFSecISOCtryPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		return( arrayList );
	}

	public ICFSecISOCtryObj readISOCtryByIdIdx( short ISOCtryId )
	{
		return( readISOCtryByIdIdx( ISOCtryId,
			false ) );
	}

	public ICFSecISOCtryObj readISOCtryByIdIdx( short ISOCtryId, boolean forceRead )
	{
		CFSecISOCtryPKey pkey = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOCtry().newPKey();
		pkey.setRequiredISOCtryId( ISOCtryId );
		ICFSecISOCtryObj obj = readISOCtry( pkey, forceRead );
		return( obj );
	}

	public ICFSecISOCtryObj readISOCtryByISOCodeIdx( String ISOCode )
	{
		return( readISOCtryByISOCodeIdx( ISOCode,
			false ) );
	}

	public ICFSecISOCtryObj readISOCtryByISOCodeIdx( String ISOCode, boolean forceRead )
	{
		if( indexByISOCodeIdx == null ) {
			indexByISOCodeIdx = new HashMap< CFSecISOCtryByISOCodeIdxKey,
				ICFSecISOCtryObj >();
		}
		CFSecISOCtryByISOCodeIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOCtry().newISOCodeIdxKey();
		key.setRequiredISOCode( ISOCode );
		ICFSecISOCtryObj obj = null;
		if( ( ! forceRead ) && indexByISOCodeIdx.containsKey( key ) ) {
			obj = indexByISOCodeIdx.get( key );
		}
		else {
			CFSecISOCtryBuff buff = ((ICFSecSchema)schema.getBackingStore()).getTableISOCtry().readDerivedByISOCodeIdx( schema.getAuthorization(),
				ISOCode );
			if( buff != null ) {
				obj = schema.getISOCtryTableObj().newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactoryISOCtry().newPKey() );
				obj.setBuff( buff );
				obj = (ICFSecISOCtryObj)obj.realise();
			}
		}
		return( obj );
	}

	public ICFSecISOCtryObj readISOCtryByNameIdx( String Name )
	{
		return( readISOCtryByNameIdx( Name,
			false ) );
	}

	public ICFSecISOCtryObj readISOCtryByNameIdx( String Name, boolean forceRead )
	{
		if( indexByNameIdx == null ) {
			indexByNameIdx = new HashMap< CFSecISOCtryByNameIdxKey,
				ICFSecISOCtryObj >();
		}
		CFSecISOCtryByNameIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOCtry().newNameIdxKey();
		key.setRequiredName( Name );
		ICFSecISOCtryObj obj = null;
		if( ( ! forceRead ) && indexByNameIdx.containsKey( key ) ) {
			obj = indexByNameIdx.get( key );
		}
		else {
			CFSecISOCtryBuff buff = ((ICFSecSchema)schema.getBackingStore()).getTableISOCtry().readDerivedByNameIdx( schema.getAuthorization(),
				Name );
			if( buff != null ) {
				obj = schema.getISOCtryTableObj().newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactoryISOCtry().newPKey() );
				obj.setBuff( buff );
				obj = (ICFSecISOCtryObj)obj.realise();
			}
		}
		return( obj );
	}

	public ICFSecISOCtryObj readCachedISOCtryByIdIdx( short ISOCtryId )
	{
		ICFSecISOCtryObj obj = null;
		CFSecISOCtryPKey pkey = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOCtry().newPKey();
		pkey.setRequiredISOCtryId( ISOCtryId );
		obj = readCachedISOCtry( pkey );
		return( obj );
	}

	public ICFSecISOCtryObj readCachedISOCtryByISOCodeIdx( String ISOCode )
	{
		ICFSecISOCtryObj obj = null;
		CFSecISOCtryByISOCodeIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOCtry().newISOCodeIdxKey();
		key.setRequiredISOCode( ISOCode );
		if( indexByISOCodeIdx != null ) {
			if( indexByISOCodeIdx.containsKey( key ) ) {
				obj = indexByISOCodeIdx.get( key );
			}
			else {
				Iterator<ICFSecISOCtryObj> valIter = members.values().iterator();
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
			Iterator<ICFSecISOCtryObj> valIter = members.values().iterator();
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

	public ICFSecISOCtryObj readCachedISOCtryByNameIdx( String Name )
	{
		ICFSecISOCtryObj obj = null;
		CFSecISOCtryByNameIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOCtry().newNameIdxKey();
		key.setRequiredName( Name );
		if( indexByNameIdx != null ) {
			if( indexByNameIdx.containsKey( key ) ) {
				obj = indexByNameIdx.get( key );
			}
			else {
				Iterator<ICFSecISOCtryObj> valIter = members.values().iterator();
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
			Iterator<ICFSecISOCtryObj> valIter = members.values().iterator();
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

	public void deepDisposeISOCtryByIdIdx( short ISOCtryId )
	{
		ICFSecISOCtryObj obj = readCachedISOCtryByIdIdx( ISOCtryId );
		if( obj != null ) {
			obj.forget();
		}
	}

	public void deepDisposeISOCtryByISOCodeIdx( String ISOCode )
	{
		ICFSecISOCtryObj obj = readCachedISOCtryByISOCodeIdx( ISOCode );
		if( obj != null ) {
			obj.forget();
		}
	}

	public void deepDisposeISOCtryByNameIdx( String Name )
	{
		ICFSecISOCtryObj obj = readCachedISOCtryByNameIdx( Name );
		if( obj != null ) {
			obj.forget();
		}
	}

	public ICFSecISOCtryObj updateISOCtry( ICFSecISOCtryObj Obj ) {
		ICFSecISOCtryObj obj = Obj;
		((ICFSecSchema)schema.getBackingStore()).getTableISOCtry().updateISOCtry( schema.getAuthorization(),
			Obj.getISOCtryBuff() );
		obj = (ICFSecISOCtryObj)Obj.realise();
		obj.endEdit();
		return( obj );
	}

	public void deleteISOCtry( ICFSecISOCtryObj Obj ) {
		ICFSecISOCtryObj obj = Obj;
		((ICFSecSchema)schema.getBackingStore()).getTableISOCtry().deleteISOCtry( schema.getAuthorization(),
			obj.getISOCtryBuff() );
		Obj.forget();
	}

	public void deleteISOCtryByIdIdx( short ISOCtryId )
	{
		CFSecISOCtryPKey pkey = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOCtry().newPKey();
		pkey.setRequiredISOCtryId( ISOCtryId );
		ICFSecISOCtryObj obj = readISOCtry( pkey );
		if( obj != null ) {
			ICFSecISOCtryEditObj editObj = (ICFSecISOCtryEditObj)obj.getEdit();
			boolean editStarted;
			if( editObj == null ) {
				editObj = (ICFSecISOCtryEditObj)obj.beginEdit();
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
		deepDisposeISOCtryByIdIdx( ISOCtryId );
	}

	public void deleteISOCtryByISOCodeIdx( String ISOCode )
	{
		if( indexByISOCodeIdx == null ) {
			indexByISOCodeIdx = new HashMap< CFSecISOCtryByISOCodeIdxKey,
				ICFSecISOCtryObj >();
		}
		CFSecISOCtryByISOCodeIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOCtry().newISOCodeIdxKey();
		key.setRequiredISOCode( ISOCode );
		ICFSecISOCtryObj obj = null;
		if( indexByISOCodeIdx.containsKey( key ) ) {
			obj = indexByISOCodeIdx.get( key );
			((ICFSecSchema)schema.getBackingStore()).getTableISOCtry().deleteISOCtryByISOCodeIdx( schema.getAuthorization(),
				ISOCode );
			obj.forget();
		}
		else {
			((ICFSecSchema)schema.getBackingStore()).getTableISOCtry().deleteISOCtryByISOCodeIdx( schema.getAuthorization(),
				ISOCode );
		}
		deepDisposeISOCtryByISOCodeIdx( ISOCode );
	}

	public void deleteISOCtryByNameIdx( String Name )
	{
		if( indexByNameIdx == null ) {
			indexByNameIdx = new HashMap< CFSecISOCtryByNameIdxKey,
				ICFSecISOCtryObj >();
		}
		CFSecISOCtryByNameIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOCtry().newNameIdxKey();
		key.setRequiredName( Name );
		ICFSecISOCtryObj obj = null;
		if( indexByNameIdx.containsKey( key ) ) {
			obj = indexByNameIdx.get( key );
			((ICFSecSchema)schema.getBackingStore()).getTableISOCtry().deleteISOCtryByNameIdx( schema.getAuthorization(),
				Name );
			obj.forget();
		}
		else {
			((ICFSecSchema)schema.getBackingStore()).getTableISOCtry().deleteISOCtryByNameIdx( schema.getAuthorization(),
				Name );
		}
		deepDisposeISOCtryByNameIdx( Name );
	}
}