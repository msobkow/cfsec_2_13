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

public class CFSecISOLangTableObj
	implements ICFSecISOLangTableObj
{
	protected ICFSecSchemaObj schema;
	private Map<CFSecISOLangPKey, ICFSecISOLangObj> members;
	private Map<CFSecISOLangPKey, ICFSecISOLangObj> allISOLang;
	private Map< CFSecISOLangByCode3IdxKey,
		ICFSecISOLangObj > indexByCode3Idx;
	private Map< CFSecISOLangByCode2IdxKey,
		Map<CFSecISOLangPKey, ICFSecISOLangObj > > indexByCode2Idx;
	public static String TABLE_NAME = "ISOLang";
	public static String TABLE_DBNAME = "iso_lang";

	public CFSecISOLangTableObj() {
		schema = null;
		members = new HashMap<CFSecISOLangPKey, ICFSecISOLangObj>();
		allISOLang = null;
		indexByCode3Idx = null;
		indexByCode2Idx = null;
	}

	public CFSecISOLangTableObj( ICFSecSchemaObj argSchema ) {
		schema = (ICFSecSchemaObj)argSchema;
		members = new HashMap<CFSecISOLangPKey, ICFSecISOLangObj>();
		allISOLang = null;
		indexByCode3Idx = null;
		indexByCode2Idx = null;
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
		allISOLang = null;
		indexByCode3Idx = null;
		indexByCode2Idx = null;
		List<ICFSecISOLangObj> toForget = new LinkedList<ICFSecISOLangObj>();
		ICFSecISOLangObj cur = null;
		Iterator<ICFSecISOLangObj> iter = members.values().iterator();
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
	 *	CFSecISOLangObj.
	 */
	public ICFSecISOLangObj newInstance() {
		ICFSecISOLangObj inst = new CFSecISOLangObj( schema );
		return( inst );
	}

	/**
	 *	If your implementation subclasses the objects,
	 *	you'll want to overload the constructByClassCode()
	 *	implementation to return your implementation's
	 *	instances instead of the base implementation.
	 *
	 *	This is the sole factory for instances derived from
	 *	CFSecISOLangObj.
	 */
	public ICFSecISOLangEditObj newEditInstance( ICFSecISOLangObj orig ) {
		ICFSecISOLangEditObj edit = new CFSecISOLangEditObj( orig );
		return( edit );
	}

	public ICFSecISOLangObj realiseISOLang( ICFSecISOLangObj Obj ) {
		ICFSecISOLangObj obj = Obj;
		CFSecISOLangPKey pkey = obj.getPKey();
		ICFSecISOLangObj keepObj = null;
		if( members.containsKey( pkey ) && ( null != members.get( pkey ) ) ) {
			ICFSecISOLangObj existingObj = members.get( pkey );
			keepObj = existingObj;

			/*
			 *	We always rebind the data because if we're being called, some index has
			 *	been updated and is refreshing it's data, which may or may not have changed
			 */

			// Detach object from alternate and duplicate indexes, leave PKey alone

			if( indexByCode3Idx != null ) {
				CFSecISOLangByCode3IdxKey keyCode3Idx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryISOLang().newCode3IdxKey();
				keyCode3Idx.setRequiredISO6392Code( keepObj.getRequiredISO6392Code() );
				indexByCode3Idx.remove( keyCode3Idx );
			}

			if( indexByCode2Idx != null ) {
				CFSecISOLangByCode2IdxKey keyCode2Idx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryISOLang().newCode2IdxKey();
				keyCode2Idx.setOptionalISO6391Code( keepObj.getOptionalISO6391Code() );
				Map<CFSecISOLangPKey, ICFSecISOLangObj > mapCode2Idx = indexByCode2Idx.get( keyCode2Idx );
				if( mapCode2Idx != null ) {
					mapCode2Idx.remove( keepObj.getPKey() );
					if( mapCode2Idx.size() <= 0 ) {
						indexByCode2Idx.remove( keyCode2Idx );
					}
				}
			}

			keepObj.setBuff( Obj.getBuff() );
			// Attach new object to alternate and duplicate indexes -- PKey stay stable

			if( indexByCode3Idx != null ) {
				CFSecISOLangByCode3IdxKey keyCode3Idx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryISOLang().newCode3IdxKey();
				keyCode3Idx.setRequiredISO6392Code( keepObj.getRequiredISO6392Code() );
				indexByCode3Idx.put( keyCode3Idx, keepObj );
			}

			if( indexByCode2Idx != null ) {
				CFSecISOLangByCode2IdxKey keyCode2Idx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryISOLang().newCode2IdxKey();
				keyCode2Idx.setOptionalISO6391Code( keepObj.getOptionalISO6391Code() );
				Map<CFSecISOLangPKey, ICFSecISOLangObj > mapCode2Idx = indexByCode2Idx.get( keyCode2Idx );
				if( mapCode2Idx != null ) {
					mapCode2Idx.put( keepObj.getPKey(), keepObj );
				}
			}

			if( allISOLang != null ) {
				allISOLang.put( keepObj.getPKey(), keepObj );
			}
		}
		else {
			keepObj = obj;
			keepObj.setIsNew( false );

			// Attach new object to PKey, all, alternate, and duplicate indexes
			members.put( keepObj.getPKey(), keepObj );
			if( allISOLang != null ) {
				allISOLang.put( keepObj.getPKey(), keepObj );
			}

			if( indexByCode3Idx != null ) {
				CFSecISOLangByCode3IdxKey keyCode3Idx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryISOLang().newCode3IdxKey();
				keyCode3Idx.setRequiredISO6392Code( keepObj.getRequiredISO6392Code() );
				indexByCode3Idx.put( keyCode3Idx, keepObj );
			}

			if( indexByCode2Idx != null ) {
				CFSecISOLangByCode2IdxKey keyCode2Idx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryISOLang().newCode2IdxKey();
				keyCode2Idx.setOptionalISO6391Code( keepObj.getOptionalISO6391Code() );
				Map<CFSecISOLangPKey, ICFSecISOLangObj > mapCode2Idx = indexByCode2Idx.get( keyCode2Idx );
				if( mapCode2Idx != null ) {
					mapCode2Idx.put( keepObj.getPKey(), keepObj );
				}
			}

		}
		return( keepObj );
	}

	public ICFSecISOLangObj createISOLang( ICFSecISOLangObj Obj ) {
		ICFSecISOLangObj obj = Obj;
		CFSecISOLangBuff buff = obj.getISOLangBuff();
		((ICFSecSchema)schema.getBackingStore()).getTableISOLang().createISOLang(
			schema.getAuthorization(),
			buff );
		obj.copyBuffToPKey();
		obj = obj.realise();
		obj.endEdit();
		return( obj );
	}

	public ICFSecISOLangObj readISOLang( CFSecISOLangPKey pkey ) {
		return( readISOLang( pkey, false ) );
	}

	public ICFSecISOLangObj readISOLang( CFSecISOLangPKey pkey, boolean forceRead ) {
		ICFSecISOLangObj obj = null;
		if( ( ! forceRead ) && members.containsKey( pkey ) ) {
			obj = members.get( pkey );
		}
		else {
			CFSecISOLangBuff readBuff = ((ICFSecSchema)schema.getBackingStore()).getTableISOLang().readDerivedByIdIdx( schema.getAuthorization(),
				pkey.getRequiredISOLangId() );
			if( readBuff != null ) {
				obj = schema.getISOLangTableObj().newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactoryISOLang().newPKey() );
				obj.setBuff( readBuff );
				obj = (ICFSecISOLangObj)obj.realise();
			}
		}
		return( obj );
	}

	public ICFSecISOLangObj readCachedISOLang( CFSecISOLangPKey pkey ) {
		ICFSecISOLangObj obj = null;
		if( members.containsKey( pkey ) ) {
			obj = members.get( pkey );
		}
		return( obj );
	}

	public void reallyDeepDisposeISOLang( ICFSecISOLangObj obj )
	{
		final String S_ProcName = "CFSecISOLangTableObj.reallyDeepDisposeISOLang() ";
		String classCode;
		if( obj == null ) {
			return;
		}
		CFSecISOLangPKey pkey = obj.getPKey();
		ICFSecISOLangObj existing = readCachedISOLang( pkey );
		if( existing == null ) {
			return;
		}
		members.remove( pkey );
		CFSecISOLangByCode3IdxKey keyCode3Idx = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOLang().newCode3IdxKey();
		keyCode3Idx.setRequiredISO6392Code( existing.getRequiredISO6392Code() );

		CFSecISOLangByCode2IdxKey keyCode2Idx = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOLang().newCode2IdxKey();
		keyCode2Idx.setOptionalISO6391Code( existing.getOptionalISO6391Code() );


		schema.getISOCtryLangTableObj().deepDisposeISOCtryLangByLangIdx( existing.getRequiredISOLangId() );

		if( indexByCode3Idx != null ) {
			indexByCode3Idx.remove( keyCode3Idx );
		}

		if( indexByCode2Idx != null ) {
			if( indexByCode2Idx.containsKey( keyCode2Idx ) ) {
				indexByCode2Idx.get( keyCode2Idx ).remove( pkey );
				if( indexByCode2Idx.get( keyCode2Idx ).size() <= 0 ) {
					indexByCode2Idx.remove( keyCode2Idx );
				}
			}
		}


	}
	public void deepDisposeISOLang( CFSecISOLangPKey pkey ) {
		ICFSecISOLangObj obj = readCachedISOLang( pkey );
		if( obj != null ) {
			obj.forget();
		}
	}

	public ICFSecISOLangObj lockISOLang( CFSecISOLangPKey pkey ) {
		ICFSecISOLangObj locked = null;
		CFSecISOLangBuff lockBuff = ((ICFSecSchema)schema.getBackingStore()).getTableISOLang().lockDerived( schema.getAuthorization(), pkey );
		if( lockBuff != null ) {
				locked = schema.getISOLangTableObj().newInstance();
			locked.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactoryISOLang().newPKey() );
			locked.setBuff( lockBuff );
			locked = (ICFSecISOLangObj)locked.realise();
		}
		else {
			throw new CFLibCollisionDetectedException( getClass(), "lockISOLang", pkey );
		}
		return( locked );
	}

	public List<ICFSecISOLangObj> readAllISOLang() {
		return( readAllISOLang( false ) );
	}

	public List<ICFSecISOLangObj> readAllISOLang( boolean forceRead ) {
		final String S_ProcName = "readAllISOLang";
		if( ( allISOLang == null ) || forceRead ) {
			Map<CFSecISOLangPKey, ICFSecISOLangObj> map = new HashMap<CFSecISOLangPKey,ICFSecISOLangObj>();
			allISOLang = map;
			CFSecISOLangBuff[] buffList = ((ICFSecSchema)schema.getBackingStore()).getTableISOLang().readAllDerived( schema.getAuthorization() );
			CFSecISOLangBuff buff;
			ICFSecISOLangObj obj;
			for( int idx = 0; idx < buffList.length; idx ++ ) {
				buff = buffList[ idx ];
				obj = newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactoryISOLang().newPKey() );
				obj.setBuff( buff );
				ICFSecISOLangObj realised = (ICFSecISOLangObj)obj.realise();
			}
		}
		int len = allISOLang.size();
		ICFSecISOLangObj arr[] = new ICFSecISOLangObj[len];
		Iterator<ICFSecISOLangObj> valIter = allISOLang.values().iterator();
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
		ArrayList<ICFSecISOLangObj> arrayList = new ArrayList<ICFSecISOLangObj>(len);
		for( idx = 0; idx < len; idx ++ ) {
			arrayList.add( arr[idx] );
		}

		Comparator<ICFSecISOLangObj> cmp = new Comparator<ICFSecISOLangObj>() {
			public int compare( ICFSecISOLangObj lhs, ICFSecISOLangObj rhs ) {
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
					CFSecISOLangPKey lhsPKey = lhs.getPKey();
					CFSecISOLangPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		List<ICFSecISOLangObj> sortedList = arrayList;
		return( sortedList );
	}

	public List<ICFSecISOLangObj> readCachedAllISOLang() {
		final String S_ProcName = "readCachedAllISOLang";
		ArrayList<ICFSecISOLangObj> arrayList = new ArrayList<ICFSecISOLangObj>();
		if( allISOLang != null ) {
			int len = allISOLang.size();
			ICFSecISOLangObj arr[] = new ICFSecISOLangObj[len];
			Iterator<ICFSecISOLangObj> valIter = allISOLang.values().iterator();
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
		Comparator<ICFSecISOLangObj> cmp = new Comparator<ICFSecISOLangObj>() {
			public int compare( ICFSecISOLangObj lhs, ICFSecISOLangObj rhs ) {
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
					CFSecISOLangPKey lhsPKey = lhs.getPKey();
					CFSecISOLangPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		return( arrayList );
	}

	public ICFSecISOLangObj readISOLangByIdIdx( short ISOLangId )
	{
		return( readISOLangByIdIdx( ISOLangId,
			false ) );
	}

	public ICFSecISOLangObj readISOLangByIdIdx( short ISOLangId, boolean forceRead )
	{
		CFSecISOLangPKey pkey = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOLang().newPKey();
		pkey.setRequiredISOLangId( ISOLangId );
		ICFSecISOLangObj obj = readISOLang( pkey, forceRead );
		return( obj );
	}

	public ICFSecISOLangObj readISOLangByCode3Idx( String ISO6392Code )
	{
		return( readISOLangByCode3Idx( ISO6392Code,
			false ) );
	}

	public ICFSecISOLangObj readISOLangByCode3Idx( String ISO6392Code, boolean forceRead )
	{
		if( indexByCode3Idx == null ) {
			indexByCode3Idx = new HashMap< CFSecISOLangByCode3IdxKey,
				ICFSecISOLangObj >();
		}
		CFSecISOLangByCode3IdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOLang().newCode3IdxKey();
		key.setRequiredISO6392Code( ISO6392Code );
		ICFSecISOLangObj obj = null;
		if( ( ! forceRead ) && indexByCode3Idx.containsKey( key ) ) {
			obj = indexByCode3Idx.get( key );
		}
		else {
			CFSecISOLangBuff buff = ((ICFSecSchema)schema.getBackingStore()).getTableISOLang().readDerivedByCode3Idx( schema.getAuthorization(),
				ISO6392Code );
			if( buff != null ) {
				obj = schema.getISOLangTableObj().newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactoryISOLang().newPKey() );
				obj.setBuff( buff );
				obj = (ICFSecISOLangObj)obj.realise();
			}
		}
		return( obj );
	}

	public List<ICFSecISOLangObj> readISOLangByCode2Idx( String ISO6391Code )
	{
		return( readISOLangByCode2Idx( ISO6391Code,
			false ) );
	}

	public List<ICFSecISOLangObj> readISOLangByCode2Idx( String ISO6391Code,
		boolean forceRead )
	{
		final String S_ProcName = "readISOLangByCode2Idx";
		CFSecISOLangByCode2IdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOLang().newCode2IdxKey();
		key.setOptionalISO6391Code( ISO6391Code );
		Map<CFSecISOLangPKey, ICFSecISOLangObj> dict;
		if( indexByCode2Idx == null ) {
			indexByCode2Idx = new HashMap< CFSecISOLangByCode2IdxKey,
				Map< CFSecISOLangPKey, ICFSecISOLangObj > >();
		}
		if( ( ! forceRead ) && indexByCode2Idx.containsKey( key ) ) {
			dict = indexByCode2Idx.get( key );
		}
		else {
			dict = new HashMap<CFSecISOLangPKey, ICFSecISOLangObj>();
			ICFSecISOLangObj obj;
			CFSecISOLangBuff[] buffList = ((ICFSecSchema)schema.getBackingStore()).getTableISOLang().readDerivedByCode2Idx( schema.getAuthorization(),
				ISO6391Code );
			CFSecISOLangBuff buff;
			for( int idx = 0; idx < buffList.length; idx ++ ) {
				buff = buffList[ idx ];
				obj = schema.getISOLangTableObj().newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactoryISOLang().newPKey() );
				obj.setBuff( buff );
				ICFSecISOLangObj realised = (ICFSecISOLangObj)obj.realise();
				dict.put( realised.getPKey(), realised );
			}
			indexByCode2Idx.put( key, dict );
		}
		int len = dict.size();
		ICFSecISOLangObj arr[] = new ICFSecISOLangObj[len];
		Iterator<ICFSecISOLangObj> valIter = dict.values().iterator();
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
		ArrayList<ICFSecISOLangObj> arrayList = new ArrayList<ICFSecISOLangObj>(len);
		for( idx = 0; idx < len; idx ++ ) {
			arrayList.add( arr[idx] );
		}

		Comparator<ICFSecISOLangObj> cmp = new Comparator<ICFSecISOLangObj>() {
			public int compare( ICFSecISOLangObj lhs, ICFSecISOLangObj rhs ) {
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
					CFSecISOLangPKey lhsPKey = lhs.getPKey();
					CFSecISOLangPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		List<ICFSecISOLangObj> sortedList = arrayList;
		return( sortedList );
	}

	public ICFSecISOLangObj readCachedISOLangByIdIdx( short ISOLangId )
	{
		ICFSecISOLangObj obj = null;
		CFSecISOLangPKey pkey = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOLang().newPKey();
		pkey.setRequiredISOLangId( ISOLangId );
		obj = readCachedISOLang( pkey );
		return( obj );
	}

	public ICFSecISOLangObj readCachedISOLangByCode3Idx( String ISO6392Code )
	{
		ICFSecISOLangObj obj = null;
		CFSecISOLangByCode3IdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOLang().newCode3IdxKey();
		key.setRequiredISO6392Code( ISO6392Code );
		if( indexByCode3Idx != null ) {
			if( indexByCode3Idx.containsKey( key ) ) {
				obj = indexByCode3Idx.get( key );
			}
			else {
				Iterator<ICFSecISOLangObj> valIter = members.values().iterator();
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
			Iterator<ICFSecISOLangObj> valIter = members.values().iterator();
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

	public List<ICFSecISOLangObj> readCachedISOLangByCode2Idx( String ISO6391Code )
	{
		final String S_ProcName = "readCachedISOLangByCode2Idx";
		CFSecISOLangByCode2IdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOLang().newCode2IdxKey();
		key.setOptionalISO6391Code( ISO6391Code );
		ArrayList<ICFSecISOLangObj> arrayList = new ArrayList<ICFSecISOLangObj>();
		if( indexByCode2Idx != null ) {
			Map<CFSecISOLangPKey, ICFSecISOLangObj> dict;
			if( indexByCode2Idx.containsKey( key ) ) {
				dict = indexByCode2Idx.get( key );
				int len = dict.size();
				ICFSecISOLangObj arr[] = new ICFSecISOLangObj[len];
				Iterator<ICFSecISOLangObj> valIter = dict.values().iterator();
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
			ICFSecISOLangObj obj;
			Iterator<ICFSecISOLangObj> valIter = members.values().iterator();
			while( valIter.hasNext() ) {
				obj = valIter.next();
				if( obj != null ) {
					if( obj.getBuff().compareTo( key ) == 0 ) {
						arrayList.add( obj );
					}
				}
			}
		}
		Comparator<ICFSecISOLangObj> cmp = new Comparator<ICFSecISOLangObj>() {
			public int compare( ICFSecISOLangObj lhs, ICFSecISOLangObj rhs ) {
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
					CFSecISOLangPKey lhsPKey = lhs.getPKey();
					CFSecISOLangPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		return( arrayList );
	}

	public void deepDisposeISOLangByIdIdx( short ISOLangId )
	{
		ICFSecISOLangObj obj = readCachedISOLangByIdIdx( ISOLangId );
		if( obj != null ) {
			obj.forget();
		}
	}

	public void deepDisposeISOLangByCode3Idx( String ISO6392Code )
	{
		ICFSecISOLangObj obj = readCachedISOLangByCode3Idx( ISO6392Code );
		if( obj != null ) {
			obj.forget();
		}
	}

	public void deepDisposeISOLangByCode2Idx( String ISO6391Code )
	{
		final String S_ProcName = "deepDisposeISOLangByCode2Idx";
		ICFSecISOLangObj obj;
		List<ICFSecISOLangObj> arrayList = readCachedISOLangByCode2Idx( ISO6391Code );
		if( arrayList != null )  {
			Iterator<ICFSecISOLangObj> arrayIter = arrayList.iterator();
			while( arrayIter.hasNext() ) {
				obj = arrayIter.next();
				if( obj != null ) {
					obj.forget();
				}
			}
		}
	}

	public ICFSecISOLangObj updateISOLang( ICFSecISOLangObj Obj ) {
		ICFSecISOLangObj obj = Obj;
		((ICFSecSchema)schema.getBackingStore()).getTableISOLang().updateISOLang( schema.getAuthorization(),
			Obj.getISOLangBuff() );
		obj = (ICFSecISOLangObj)Obj.realise();
		obj.endEdit();
		return( obj );
	}

	public void deleteISOLang( ICFSecISOLangObj Obj ) {
		ICFSecISOLangObj obj = Obj;
		((ICFSecSchema)schema.getBackingStore()).getTableISOLang().deleteISOLang( schema.getAuthorization(),
			obj.getISOLangBuff() );
		Obj.forget();
	}

	public void deleteISOLangByIdIdx( short ISOLangId )
	{
		CFSecISOLangPKey pkey = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOLang().newPKey();
		pkey.setRequiredISOLangId( ISOLangId );
		ICFSecISOLangObj obj = readISOLang( pkey );
		if( obj != null ) {
			ICFSecISOLangEditObj editObj = (ICFSecISOLangEditObj)obj.getEdit();
			boolean editStarted;
			if( editObj == null ) {
				editObj = (ICFSecISOLangEditObj)obj.beginEdit();
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
		deepDisposeISOLangByIdIdx( ISOLangId );
	}

	public void deleteISOLangByCode3Idx( String ISO6392Code )
	{
		if( indexByCode3Idx == null ) {
			indexByCode3Idx = new HashMap< CFSecISOLangByCode3IdxKey,
				ICFSecISOLangObj >();
		}
		CFSecISOLangByCode3IdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOLang().newCode3IdxKey();
		key.setRequiredISO6392Code( ISO6392Code );
		ICFSecISOLangObj obj = null;
		if( indexByCode3Idx.containsKey( key ) ) {
			obj = indexByCode3Idx.get( key );
			((ICFSecSchema)schema.getBackingStore()).getTableISOLang().deleteISOLangByCode3Idx( schema.getAuthorization(),
				ISO6392Code );
			obj.forget();
		}
		else {
			((ICFSecSchema)schema.getBackingStore()).getTableISOLang().deleteISOLangByCode3Idx( schema.getAuthorization(),
				ISO6392Code );
		}
		deepDisposeISOLangByCode3Idx( ISO6392Code );
	}

	public void deleteISOLangByCode2Idx( String ISO6391Code )
	{
		CFSecISOLangByCode2IdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOLang().newCode2IdxKey();
		key.setOptionalISO6391Code( ISO6391Code );
		if( indexByCode2Idx == null ) {
			indexByCode2Idx = new HashMap< CFSecISOLangByCode2IdxKey,
				Map< CFSecISOLangPKey, ICFSecISOLangObj > >();
		}
		if( indexByCode2Idx.containsKey( key ) ) {
			Map<CFSecISOLangPKey, ICFSecISOLangObj> dict = indexByCode2Idx.get( key );
			((ICFSecSchema)schema.getBackingStore()).getTableISOLang().deleteISOLangByCode2Idx( schema.getAuthorization(),
				ISO6391Code );
			Iterator<ICFSecISOLangObj> iter = dict.values().iterator();
			ICFSecISOLangObj obj;
			List<ICFSecISOLangObj> toForget = new LinkedList<ICFSecISOLangObj>();
			while( iter.hasNext() ) {
				obj = iter.next();
				toForget.add( obj );
			}
			iter = toForget.iterator();
			while( iter.hasNext() ) {
				obj = iter.next();
				obj.forget();
			}
			indexByCode2Idx.remove( key );
		}
		else {
			((ICFSecSchema)schema.getBackingStore()).getTableISOLang().deleteISOLangByCode2Idx( schema.getAuthorization(),
				ISO6391Code );
		}
		deepDisposeISOLangByCode2Idx( ISO6391Code );
	}
}