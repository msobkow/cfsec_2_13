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

package org.msscf.msscf.cfsec.CFSecObj;

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.msscf.msscf.cflib.CFLib.*;
import org.msscf.msscf.cfsec.CFSec.*;

public class CFSecISOCtryLangTableObj
	implements ICFSecISOCtryLangTableObj
{
	protected ICFSecSchemaObj schema;
	private Map<CFSecISOCtryLangPKey, ICFSecISOCtryLangObj> members;
	private Map<CFSecISOCtryLangPKey, ICFSecISOCtryLangObj> allISOCtryLang;
	private Map< CFSecISOCtryLangByCtryIdxKey,
		Map<CFSecISOCtryLangPKey, ICFSecISOCtryLangObj > > indexByCtryIdx;
	private Map< CFSecISOCtryLangByLangIdxKey,
		Map<CFSecISOCtryLangPKey, ICFSecISOCtryLangObj > > indexByLangIdx;
	public static String TABLE_NAME = "ISOCtryLang";
	public static String TABLE_DBNAME = "iso_cntrylng";

	public CFSecISOCtryLangTableObj() {
		schema = null;
		members = new HashMap<CFSecISOCtryLangPKey, ICFSecISOCtryLangObj>();
		allISOCtryLang = null;
		indexByCtryIdx = null;
		indexByLangIdx = null;
	}

	public CFSecISOCtryLangTableObj( ICFSecSchemaObj argSchema ) {
		schema = (ICFSecSchemaObj)argSchema;
		members = new HashMap<CFSecISOCtryLangPKey, ICFSecISOCtryLangObj>();
		allISOCtryLang = null;
		indexByCtryIdx = null;
		indexByLangIdx = null;
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
		allISOCtryLang = null;
		indexByCtryIdx = null;
		indexByLangIdx = null;
		List<ICFSecISOCtryLangObj> toForget = new LinkedList<ICFSecISOCtryLangObj>();
		ICFSecISOCtryLangObj cur = null;
		Iterator<ICFSecISOCtryLangObj> iter = members.values().iterator();
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
	 *	CFSecISOCtryLangObj.
	 */
	public ICFSecISOCtryLangObj newInstance() {
		ICFSecISOCtryLangObj inst = new CFSecISOCtryLangObj( schema );
		return( inst );
	}

	/**
	 *	If your implementation subclasses the objects,
	 *	you'll want to overload the constructByClassCode()
	 *	implementation to return your implementation's
	 *	instances instead of the base implementation.
	 *
	 *	This is the sole factory for instances derived from
	 *	CFSecISOCtryLangObj.
	 */
	public ICFSecISOCtryLangEditObj newEditInstance( ICFSecISOCtryLangObj orig ) {
		ICFSecISOCtryLangEditObj edit = new CFSecISOCtryLangEditObj( orig );
		return( edit );
	}

	public ICFSecISOCtryLangObj realiseISOCtryLang( ICFSecISOCtryLangObj Obj ) {
		ICFSecISOCtryLangObj obj = Obj;
		CFSecISOCtryLangPKey pkey = obj.getPKey();
		ICFSecISOCtryLangObj keepObj = null;
		if( members.containsKey( pkey ) && ( null != members.get( pkey ) ) ) {
			ICFSecISOCtryLangObj existingObj = members.get( pkey );
			keepObj = existingObj;

			/*
			 *	We always rebind the data because if we're being called, some index has
			 *	been updated and is refreshing it's data, which may or may not have changed
			 */

			// Detach object from alternate and duplicate indexes, leave PKey alone

			if( indexByCtryIdx != null ) {
				CFSecISOCtryLangByCtryIdxKey keyCtryIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryISOCtryLang().newCtryIdxKey();
				keyCtryIdx.setRequiredISOCtryId( keepObj.getRequiredISOCtryId() );
				Map<CFSecISOCtryLangPKey, ICFSecISOCtryLangObj > mapCtryIdx = indexByCtryIdx.get( keyCtryIdx );
				if( mapCtryIdx != null ) {
					mapCtryIdx.remove( keepObj.getPKey() );
					if( mapCtryIdx.size() <= 0 ) {
						indexByCtryIdx.remove( keyCtryIdx );
					}
				}
			}

			if( indexByLangIdx != null ) {
				CFSecISOCtryLangByLangIdxKey keyLangIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryISOCtryLang().newLangIdxKey();
				keyLangIdx.setRequiredISOLangId( keepObj.getRequiredISOLangId() );
				Map<CFSecISOCtryLangPKey, ICFSecISOCtryLangObj > mapLangIdx = indexByLangIdx.get( keyLangIdx );
				if( mapLangIdx != null ) {
					mapLangIdx.remove( keepObj.getPKey() );
					if( mapLangIdx.size() <= 0 ) {
						indexByLangIdx.remove( keyLangIdx );
					}
				}
			}

			keepObj.setBuff( Obj.getBuff() );
			// Attach new object to alternate and duplicate indexes -- PKey stay stable

			if( indexByCtryIdx != null ) {
				CFSecISOCtryLangByCtryIdxKey keyCtryIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryISOCtryLang().newCtryIdxKey();
				keyCtryIdx.setRequiredISOCtryId( keepObj.getRequiredISOCtryId() );
				Map<CFSecISOCtryLangPKey, ICFSecISOCtryLangObj > mapCtryIdx = indexByCtryIdx.get( keyCtryIdx );
				if( mapCtryIdx != null ) {
					mapCtryIdx.put( keepObj.getPKey(), keepObj );
				}
			}

			if( indexByLangIdx != null ) {
				CFSecISOCtryLangByLangIdxKey keyLangIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryISOCtryLang().newLangIdxKey();
				keyLangIdx.setRequiredISOLangId( keepObj.getRequiredISOLangId() );
				Map<CFSecISOCtryLangPKey, ICFSecISOCtryLangObj > mapLangIdx = indexByLangIdx.get( keyLangIdx );
				if( mapLangIdx != null ) {
					mapLangIdx.put( keepObj.getPKey(), keepObj );
				}
			}

			if( allISOCtryLang != null ) {
				allISOCtryLang.put( keepObj.getPKey(), keepObj );
			}
		}
		else {
			keepObj = obj;
			keepObj.setIsNew( false );

			// Attach new object to PKey, all, alternate, and duplicate indexes
			members.put( keepObj.getPKey(), keepObj );
			if( allISOCtryLang != null ) {
				allISOCtryLang.put( keepObj.getPKey(), keepObj );
			}

			if( indexByCtryIdx != null ) {
				CFSecISOCtryLangByCtryIdxKey keyCtryIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryISOCtryLang().newCtryIdxKey();
				keyCtryIdx.setRequiredISOCtryId( keepObj.getRequiredISOCtryId() );
				Map<CFSecISOCtryLangPKey, ICFSecISOCtryLangObj > mapCtryIdx = indexByCtryIdx.get( keyCtryIdx );
				if( mapCtryIdx != null ) {
					mapCtryIdx.put( keepObj.getPKey(), keepObj );
				}
			}

			if( indexByLangIdx != null ) {
				CFSecISOCtryLangByLangIdxKey keyLangIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactoryISOCtryLang().newLangIdxKey();
				keyLangIdx.setRequiredISOLangId( keepObj.getRequiredISOLangId() );
				Map<CFSecISOCtryLangPKey, ICFSecISOCtryLangObj > mapLangIdx = indexByLangIdx.get( keyLangIdx );
				if( mapLangIdx != null ) {
					mapLangIdx.put( keepObj.getPKey(), keepObj );
				}
			}

		}
		return( keepObj );
	}

	public ICFSecISOCtryLangObj createISOCtryLang( ICFSecISOCtryLangObj Obj ) {
		ICFSecISOCtryLangObj obj = Obj;
		CFSecISOCtryLangBuff buff = obj.getISOCtryLangBuff();
		((ICFSecSchema)schema.getBackingStore()).getTableISOCtryLang().createISOCtryLang(
			schema.getAuthorization(),
			buff );
		obj.copyBuffToPKey();
		obj = obj.realise();
		obj.endEdit();
		return( obj );
	}

	public ICFSecISOCtryLangObj readISOCtryLang( CFSecISOCtryLangPKey pkey ) {
		return( readISOCtryLang( pkey, false ) );
	}

	public ICFSecISOCtryLangObj readISOCtryLang( CFSecISOCtryLangPKey pkey, boolean forceRead ) {
		ICFSecISOCtryLangObj obj = null;
		if( ( ! forceRead ) && members.containsKey( pkey ) ) {
			obj = members.get( pkey );
		}
		else {
			CFSecISOCtryLangBuff readBuff = ((ICFSecSchema)schema.getBackingStore()).getTableISOCtryLang().readDerivedByIdIdx( schema.getAuthorization(),
				pkey.getRequiredISOCtryId(),
				pkey.getRequiredISOLangId() );
			if( readBuff != null ) {
				obj = schema.getISOCtryLangTableObj().newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactoryISOCtryLang().newPKey() );
				obj.setBuff( readBuff );
				obj = (ICFSecISOCtryLangObj)obj.realise();
			}
		}
		return( obj );
	}

	public ICFSecISOCtryLangObj readCachedISOCtryLang( CFSecISOCtryLangPKey pkey ) {
		ICFSecISOCtryLangObj obj = null;
		if( members.containsKey( pkey ) ) {
			obj = members.get( pkey );
		}
		return( obj );
	}

	public void reallyDeepDisposeISOCtryLang( ICFSecISOCtryLangObj obj )
	{
		final String S_ProcName = "CFSecISOCtryLangTableObj.reallyDeepDisposeISOCtryLang() ";
		String classCode;
		if( obj == null ) {
			return;
		}
		CFSecISOCtryLangPKey pkey = obj.getPKey();
		ICFSecISOCtryLangObj existing = readCachedISOCtryLang( pkey );
		if( existing == null ) {
			return;
		}
		members.remove( pkey );
		CFSecISOCtryLangByCtryIdxKey keyCtryIdx = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOCtryLang().newCtryIdxKey();
		keyCtryIdx.setRequiredISOCtryId( existing.getRequiredISOCtryId() );

		CFSecISOCtryLangByLangIdxKey keyLangIdx = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOCtryLang().newLangIdxKey();
		keyLangIdx.setRequiredISOLangId( existing.getRequiredISOLangId() );



		if( indexByCtryIdx != null ) {
			if( indexByCtryIdx.containsKey( keyCtryIdx ) ) {
				indexByCtryIdx.get( keyCtryIdx ).remove( pkey );
				if( indexByCtryIdx.get( keyCtryIdx ).size() <= 0 ) {
					indexByCtryIdx.remove( keyCtryIdx );
				}
			}
		}

		if( indexByLangIdx != null ) {
			if( indexByLangIdx.containsKey( keyLangIdx ) ) {
				indexByLangIdx.get( keyLangIdx ).remove( pkey );
				if( indexByLangIdx.get( keyLangIdx ).size() <= 0 ) {
					indexByLangIdx.remove( keyLangIdx );
				}
			}
		}


	}
	public void deepDisposeISOCtryLang( CFSecISOCtryLangPKey pkey ) {
		ICFSecISOCtryLangObj obj = readCachedISOCtryLang( pkey );
		if( obj != null ) {
			obj.forget();
		}
	}

	public ICFSecISOCtryLangObj lockISOCtryLang( CFSecISOCtryLangPKey pkey ) {
		ICFSecISOCtryLangObj locked = null;
		CFSecISOCtryLangBuff lockBuff = ((ICFSecSchema)schema.getBackingStore()).getTableISOCtryLang().lockDerived( schema.getAuthorization(), pkey );
		if( lockBuff != null ) {
				locked = schema.getISOCtryLangTableObj().newInstance();
			locked.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactoryISOCtryLang().newPKey() );
			locked.setBuff( lockBuff );
			locked = (ICFSecISOCtryLangObj)locked.realise();
		}
		else {
			throw new CFLibCollisionDetectedException( getClass(), "lockISOCtryLang", pkey );
		}
		return( locked );
	}

	public List<ICFSecISOCtryLangObj> readAllISOCtryLang() {
		return( readAllISOCtryLang( false ) );
	}

	public List<ICFSecISOCtryLangObj> readAllISOCtryLang( boolean forceRead ) {
		final String S_ProcName = "readAllISOCtryLang";
		if( ( allISOCtryLang == null ) || forceRead ) {
			Map<CFSecISOCtryLangPKey, ICFSecISOCtryLangObj> map = new HashMap<CFSecISOCtryLangPKey,ICFSecISOCtryLangObj>();
			allISOCtryLang = map;
			CFSecISOCtryLangBuff[] buffList = ((ICFSecSchema)schema.getBackingStore()).getTableISOCtryLang().readAllDerived( schema.getAuthorization() );
			CFSecISOCtryLangBuff buff;
			ICFSecISOCtryLangObj obj;
			for( int idx = 0; idx < buffList.length; idx ++ ) {
				buff = buffList[ idx ];
				obj = newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactoryISOCtryLang().newPKey() );
				obj.setBuff( buff );
				ICFSecISOCtryLangObj realised = (ICFSecISOCtryLangObj)obj.realise();
			}
		}
		int len = allISOCtryLang.size();
		ICFSecISOCtryLangObj arr[] = new ICFSecISOCtryLangObj[len];
		Iterator<ICFSecISOCtryLangObj> valIter = allISOCtryLang.values().iterator();
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
		ArrayList<ICFSecISOCtryLangObj> arrayList = new ArrayList<ICFSecISOCtryLangObj>(len);
		for( idx = 0; idx < len; idx ++ ) {
			arrayList.add( arr[idx] );
		}

		Comparator<ICFSecISOCtryLangObj> cmp = new Comparator<ICFSecISOCtryLangObj>() {
			public int compare( ICFSecISOCtryLangObj lhs, ICFSecISOCtryLangObj rhs ) {
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
					CFSecISOCtryLangPKey lhsPKey = lhs.getPKey();
					CFSecISOCtryLangPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		List<ICFSecISOCtryLangObj> sortedList = arrayList;
		return( sortedList );
	}

	public List<ICFSecISOCtryLangObj> readCachedAllISOCtryLang() {
		final String S_ProcName = "readCachedAllISOCtryLang";
		ArrayList<ICFSecISOCtryLangObj> arrayList = new ArrayList<ICFSecISOCtryLangObj>();
		if( allISOCtryLang != null ) {
			int len = allISOCtryLang.size();
			ICFSecISOCtryLangObj arr[] = new ICFSecISOCtryLangObj[len];
			Iterator<ICFSecISOCtryLangObj> valIter = allISOCtryLang.values().iterator();
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
		Comparator<ICFSecISOCtryLangObj> cmp = new Comparator<ICFSecISOCtryLangObj>() {
			public int compare( ICFSecISOCtryLangObj lhs, ICFSecISOCtryLangObj rhs ) {
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
					CFSecISOCtryLangPKey lhsPKey = lhs.getPKey();
					CFSecISOCtryLangPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		return( arrayList );
	}

	public ICFSecISOCtryLangObj readISOCtryLangByIdIdx( short ISOCtryId,
		short ISOLangId )
	{
		return( readISOCtryLangByIdIdx( ISOCtryId,
			ISOLangId,
			false ) );
	}

	public ICFSecISOCtryLangObj readISOCtryLangByIdIdx( short ISOCtryId,
		short ISOLangId, boolean forceRead )
	{
		CFSecISOCtryLangPKey pkey = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOCtryLang().newPKey();
		pkey.setRequiredISOCtryId( ISOCtryId );
		pkey.setRequiredISOLangId( ISOLangId );
		ICFSecISOCtryLangObj obj = readISOCtryLang( pkey, forceRead );
		return( obj );
	}

	public List<ICFSecISOCtryLangObj> readISOCtryLangByCtryIdx( short ISOCtryId )
	{
		return( readISOCtryLangByCtryIdx( ISOCtryId,
			false ) );
	}

	public List<ICFSecISOCtryLangObj> readISOCtryLangByCtryIdx( short ISOCtryId,
		boolean forceRead )
	{
		final String S_ProcName = "readISOCtryLangByCtryIdx";
		CFSecISOCtryLangByCtryIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOCtryLang().newCtryIdxKey();
		key.setRequiredISOCtryId( ISOCtryId );
		Map<CFSecISOCtryLangPKey, ICFSecISOCtryLangObj> dict;
		if( indexByCtryIdx == null ) {
			indexByCtryIdx = new HashMap< CFSecISOCtryLangByCtryIdxKey,
				Map< CFSecISOCtryLangPKey, ICFSecISOCtryLangObj > >();
		}
		if( ( ! forceRead ) && indexByCtryIdx.containsKey( key ) ) {
			dict = indexByCtryIdx.get( key );
		}
		else {
			dict = new HashMap<CFSecISOCtryLangPKey, ICFSecISOCtryLangObj>();
			ICFSecISOCtryLangObj obj;
			CFSecISOCtryLangBuff[] buffList = ((ICFSecSchema)schema.getBackingStore()).getTableISOCtryLang().readDerivedByCtryIdx( schema.getAuthorization(),
				ISOCtryId );
			CFSecISOCtryLangBuff buff;
			for( int idx = 0; idx < buffList.length; idx ++ ) {
				buff = buffList[ idx ];
				obj = schema.getISOCtryLangTableObj().newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactoryISOCtryLang().newPKey() );
				obj.setBuff( buff );
				ICFSecISOCtryLangObj realised = (ICFSecISOCtryLangObj)obj.realise();
				dict.put( realised.getPKey(), realised );
			}
			indexByCtryIdx.put( key, dict );
		}
		int len = dict.size();
		ICFSecISOCtryLangObj arr[] = new ICFSecISOCtryLangObj[len];
		Iterator<ICFSecISOCtryLangObj> valIter = dict.values().iterator();
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
		ArrayList<ICFSecISOCtryLangObj> arrayList = new ArrayList<ICFSecISOCtryLangObj>(len);
		for( idx = 0; idx < len; idx ++ ) {
			arrayList.add( arr[idx] );
		}

		Comparator<ICFSecISOCtryLangObj> cmp = new Comparator<ICFSecISOCtryLangObj>() {
			public int compare( ICFSecISOCtryLangObj lhs, ICFSecISOCtryLangObj rhs ) {
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
					CFSecISOCtryLangPKey lhsPKey = lhs.getPKey();
					CFSecISOCtryLangPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		List<ICFSecISOCtryLangObj> sortedList = arrayList;
		return( sortedList );
	}

	public List<ICFSecISOCtryLangObj> readISOCtryLangByLangIdx( short ISOLangId )
	{
		return( readISOCtryLangByLangIdx( ISOLangId,
			false ) );
	}

	public List<ICFSecISOCtryLangObj> readISOCtryLangByLangIdx( short ISOLangId,
		boolean forceRead )
	{
		final String S_ProcName = "readISOCtryLangByLangIdx";
		CFSecISOCtryLangByLangIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOCtryLang().newLangIdxKey();
		key.setRequiredISOLangId( ISOLangId );
		Map<CFSecISOCtryLangPKey, ICFSecISOCtryLangObj> dict;
		if( indexByLangIdx == null ) {
			indexByLangIdx = new HashMap< CFSecISOCtryLangByLangIdxKey,
				Map< CFSecISOCtryLangPKey, ICFSecISOCtryLangObj > >();
		}
		if( ( ! forceRead ) && indexByLangIdx.containsKey( key ) ) {
			dict = indexByLangIdx.get( key );
		}
		else {
			dict = new HashMap<CFSecISOCtryLangPKey, ICFSecISOCtryLangObj>();
			ICFSecISOCtryLangObj obj;
			CFSecISOCtryLangBuff[] buffList = ((ICFSecSchema)schema.getBackingStore()).getTableISOCtryLang().readDerivedByLangIdx( schema.getAuthorization(),
				ISOLangId );
			CFSecISOCtryLangBuff buff;
			for( int idx = 0; idx < buffList.length; idx ++ ) {
				buff = buffList[ idx ];
				obj = schema.getISOCtryLangTableObj().newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactoryISOCtryLang().newPKey() );
				obj.setBuff( buff );
				ICFSecISOCtryLangObj realised = (ICFSecISOCtryLangObj)obj.realise();
				dict.put( realised.getPKey(), realised );
			}
			indexByLangIdx.put( key, dict );
		}
		int len = dict.size();
		ICFSecISOCtryLangObj arr[] = new ICFSecISOCtryLangObj[len];
		Iterator<ICFSecISOCtryLangObj> valIter = dict.values().iterator();
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
		ArrayList<ICFSecISOCtryLangObj> arrayList = new ArrayList<ICFSecISOCtryLangObj>(len);
		for( idx = 0; idx < len; idx ++ ) {
			arrayList.add( arr[idx] );
		}

		Comparator<ICFSecISOCtryLangObj> cmp = new Comparator<ICFSecISOCtryLangObj>() {
			public int compare( ICFSecISOCtryLangObj lhs, ICFSecISOCtryLangObj rhs ) {
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
					CFSecISOCtryLangPKey lhsPKey = lhs.getPKey();
					CFSecISOCtryLangPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		List<ICFSecISOCtryLangObj> sortedList = arrayList;
		return( sortedList );
	}

	public ICFSecISOCtryLangObj readCachedISOCtryLangByIdIdx( short ISOCtryId,
		short ISOLangId )
	{
		ICFSecISOCtryLangObj obj = null;
		CFSecISOCtryLangPKey pkey = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOCtryLang().newPKey();
		pkey.setRequiredISOCtryId( ISOCtryId );
		pkey.setRequiredISOLangId( ISOLangId );
		obj = readCachedISOCtryLang( pkey );
		return( obj );
	}

	public List<ICFSecISOCtryLangObj> readCachedISOCtryLangByCtryIdx( short ISOCtryId )
	{
		final String S_ProcName = "readCachedISOCtryLangByCtryIdx";
		CFSecISOCtryLangByCtryIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOCtryLang().newCtryIdxKey();
		key.setRequiredISOCtryId( ISOCtryId );
		ArrayList<ICFSecISOCtryLangObj> arrayList = new ArrayList<ICFSecISOCtryLangObj>();
		if( indexByCtryIdx != null ) {
			Map<CFSecISOCtryLangPKey, ICFSecISOCtryLangObj> dict;
			if( indexByCtryIdx.containsKey( key ) ) {
				dict = indexByCtryIdx.get( key );
				int len = dict.size();
				ICFSecISOCtryLangObj arr[] = new ICFSecISOCtryLangObj[len];
				Iterator<ICFSecISOCtryLangObj> valIter = dict.values().iterator();
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
			ICFSecISOCtryLangObj obj;
			Iterator<ICFSecISOCtryLangObj> valIter = members.values().iterator();
			while( valIter.hasNext() ) {
				obj = valIter.next();
				if( obj != null ) {
					if( obj.getBuff().compareTo( key ) == 0 ) {
						arrayList.add( obj );
					}
				}
			}
		}
		Comparator<ICFSecISOCtryLangObj> cmp = new Comparator<ICFSecISOCtryLangObj>() {
			public int compare( ICFSecISOCtryLangObj lhs, ICFSecISOCtryLangObj rhs ) {
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
					CFSecISOCtryLangPKey lhsPKey = lhs.getPKey();
					CFSecISOCtryLangPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		return( arrayList );
	}

	public List<ICFSecISOCtryLangObj> readCachedISOCtryLangByLangIdx( short ISOLangId )
	{
		final String S_ProcName = "readCachedISOCtryLangByLangIdx";
		CFSecISOCtryLangByLangIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOCtryLang().newLangIdxKey();
		key.setRequiredISOLangId( ISOLangId );
		ArrayList<ICFSecISOCtryLangObj> arrayList = new ArrayList<ICFSecISOCtryLangObj>();
		if( indexByLangIdx != null ) {
			Map<CFSecISOCtryLangPKey, ICFSecISOCtryLangObj> dict;
			if( indexByLangIdx.containsKey( key ) ) {
				dict = indexByLangIdx.get( key );
				int len = dict.size();
				ICFSecISOCtryLangObj arr[] = new ICFSecISOCtryLangObj[len];
				Iterator<ICFSecISOCtryLangObj> valIter = dict.values().iterator();
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
			ICFSecISOCtryLangObj obj;
			Iterator<ICFSecISOCtryLangObj> valIter = members.values().iterator();
			while( valIter.hasNext() ) {
				obj = valIter.next();
				if( obj != null ) {
					if( obj.getBuff().compareTo( key ) == 0 ) {
						arrayList.add( obj );
					}
				}
			}
		}
		Comparator<ICFSecISOCtryLangObj> cmp = new Comparator<ICFSecISOCtryLangObj>() {
			public int compare( ICFSecISOCtryLangObj lhs, ICFSecISOCtryLangObj rhs ) {
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
					CFSecISOCtryLangPKey lhsPKey = lhs.getPKey();
					CFSecISOCtryLangPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		return( arrayList );
	}

	public void deepDisposeISOCtryLangByIdIdx( short ISOCtryId,
		short ISOLangId )
	{
		ICFSecISOCtryLangObj obj = readCachedISOCtryLangByIdIdx( ISOCtryId,
				ISOLangId );
		if( obj != null ) {
			obj.forget();
		}
	}

	public void deepDisposeISOCtryLangByCtryIdx( short ISOCtryId )
	{
		final String S_ProcName = "deepDisposeISOCtryLangByCtryIdx";
		ICFSecISOCtryLangObj obj;
		List<ICFSecISOCtryLangObj> arrayList = readCachedISOCtryLangByCtryIdx( ISOCtryId );
		if( arrayList != null )  {
			Iterator<ICFSecISOCtryLangObj> arrayIter = arrayList.iterator();
			while( arrayIter.hasNext() ) {
				obj = arrayIter.next();
				if( obj != null ) {
					obj.forget();
				}
			}
		}
	}

	public void deepDisposeISOCtryLangByLangIdx( short ISOLangId )
	{
		final String S_ProcName = "deepDisposeISOCtryLangByLangIdx";
		ICFSecISOCtryLangObj obj;
		List<ICFSecISOCtryLangObj> arrayList = readCachedISOCtryLangByLangIdx( ISOLangId );
		if( arrayList != null )  {
			Iterator<ICFSecISOCtryLangObj> arrayIter = arrayList.iterator();
			while( arrayIter.hasNext() ) {
				obj = arrayIter.next();
				if( obj != null ) {
					obj.forget();
				}
			}
		}
	}

	public ICFSecISOCtryLangObj updateISOCtryLang( ICFSecISOCtryLangObj Obj ) {
		ICFSecISOCtryLangObj obj = Obj;
		((ICFSecSchema)schema.getBackingStore()).getTableISOCtryLang().updateISOCtryLang( schema.getAuthorization(),
			Obj.getISOCtryLangBuff() );
		obj = (ICFSecISOCtryLangObj)Obj.realise();
		obj.endEdit();
		return( obj );
	}

	public void deleteISOCtryLang( ICFSecISOCtryLangObj Obj ) {
		ICFSecISOCtryLangObj obj = Obj;
		((ICFSecSchema)schema.getBackingStore()).getTableISOCtryLang().deleteISOCtryLang( schema.getAuthorization(),
			obj.getISOCtryLangBuff() );
		Obj.forget();
	}

	public void deleteISOCtryLangByIdIdx( short ISOCtryId,
		short ISOLangId )
	{
		CFSecISOCtryLangPKey pkey = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOCtryLang().newPKey();
		pkey.setRequiredISOCtryId( ISOCtryId );
		pkey.setRequiredISOLangId( ISOLangId );
		ICFSecISOCtryLangObj obj = readISOCtryLang( pkey );
		if( obj != null ) {
			ICFSecISOCtryLangEditObj editObj = (ICFSecISOCtryLangEditObj)obj.getEdit();
			boolean editStarted;
			if( editObj == null ) {
				editObj = (ICFSecISOCtryLangEditObj)obj.beginEdit();
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
		deepDisposeISOCtryLangByIdIdx( ISOCtryId,
				ISOLangId );
	}

	public void deleteISOCtryLangByCtryIdx( short ISOCtryId )
	{
		CFSecISOCtryLangByCtryIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOCtryLang().newCtryIdxKey();
		key.setRequiredISOCtryId( ISOCtryId );
		if( indexByCtryIdx == null ) {
			indexByCtryIdx = new HashMap< CFSecISOCtryLangByCtryIdxKey,
				Map< CFSecISOCtryLangPKey, ICFSecISOCtryLangObj > >();
		}
		if( indexByCtryIdx.containsKey( key ) ) {
			Map<CFSecISOCtryLangPKey, ICFSecISOCtryLangObj> dict = indexByCtryIdx.get( key );
			((ICFSecSchema)schema.getBackingStore()).getTableISOCtryLang().deleteISOCtryLangByCtryIdx( schema.getAuthorization(),
				ISOCtryId );
			Iterator<ICFSecISOCtryLangObj> iter = dict.values().iterator();
			ICFSecISOCtryLangObj obj;
			List<ICFSecISOCtryLangObj> toForget = new LinkedList<ICFSecISOCtryLangObj>();
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
			((ICFSecSchema)schema.getBackingStore()).getTableISOCtryLang().deleteISOCtryLangByCtryIdx( schema.getAuthorization(),
				ISOCtryId );
		}
		deepDisposeISOCtryLangByCtryIdx( ISOCtryId );
	}

	public void deleteISOCtryLangByLangIdx( short ISOLangId )
	{
		CFSecISOCtryLangByLangIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactoryISOCtryLang().newLangIdxKey();
		key.setRequiredISOLangId( ISOLangId );
		if( indexByLangIdx == null ) {
			indexByLangIdx = new HashMap< CFSecISOCtryLangByLangIdxKey,
				Map< CFSecISOCtryLangPKey, ICFSecISOCtryLangObj > >();
		}
		if( indexByLangIdx.containsKey( key ) ) {
			Map<CFSecISOCtryLangPKey, ICFSecISOCtryLangObj> dict = indexByLangIdx.get( key );
			((ICFSecSchema)schema.getBackingStore()).getTableISOCtryLang().deleteISOCtryLangByLangIdx( schema.getAuthorization(),
				ISOLangId );
			Iterator<ICFSecISOCtryLangObj> iter = dict.values().iterator();
			ICFSecISOCtryLangObj obj;
			List<ICFSecISOCtryLangObj> toForget = new LinkedList<ICFSecISOCtryLangObj>();
			while( iter.hasNext() ) {
				obj = iter.next();
				toForget.add( obj );
			}
			iter = toForget.iterator();
			while( iter.hasNext() ) {
				obj = iter.next();
				obj.forget();
			}
			indexByLangIdx.remove( key );
		}
		else {
			((ICFSecSchema)schema.getBackingStore()).getTableISOCtryLang().deleteISOCtryLangByLangIdx( schema.getAuthorization(),
				ISOLangId );
		}
		deepDisposeISOCtryLangByLangIdx( ISOLangId );
	}
}