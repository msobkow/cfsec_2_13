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

public class CFSecSecUserTableObj
	implements ICFSecSecUserTableObj
{
	protected ICFSecSchemaObj schema;
	private Map<CFSecSecUserPKey, ICFSecSecUserObj> members;
	private Map<CFSecSecUserPKey, ICFSecSecUserObj> allSecUser;
	private Map< CFSecSecUserByULoginIdxKey,
		ICFSecSecUserObj > indexByULoginIdx;
	private Map< CFSecSecUserByEMConfIdxKey,
		Map<CFSecSecUserPKey, ICFSecSecUserObj > > indexByEMConfIdx;
	private Map< CFSecSecUserByPwdResetIdxKey,
		Map<CFSecSecUserPKey, ICFSecSecUserObj > > indexByPwdResetIdx;
	private Map< CFSecSecUserByDefDevIdxKey,
		Map<CFSecSecUserPKey, ICFSecSecUserObj > > indexByDefDevIdx;
	public static String TABLE_NAME = "SecUser";
	public static String TABLE_DBNAME = "secuser";

	public CFSecSecUserTableObj() {
		schema = null;
		members = new HashMap<CFSecSecUserPKey, ICFSecSecUserObj>();
		allSecUser = null;
		indexByULoginIdx = null;
		indexByEMConfIdx = null;
		indexByPwdResetIdx = null;
		indexByDefDevIdx = null;
	}

	public CFSecSecUserTableObj( ICFSecSchemaObj argSchema ) {
		schema = (ICFSecSchemaObj)argSchema;
		members = new HashMap<CFSecSecUserPKey, ICFSecSecUserObj>();
		allSecUser = null;
		indexByULoginIdx = null;
		indexByEMConfIdx = null;
		indexByPwdResetIdx = null;
		indexByDefDevIdx = null;
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
		allSecUser = null;
		indexByULoginIdx = null;
		indexByEMConfIdx = null;
		indexByPwdResetIdx = null;
		indexByDefDevIdx = null;
		List<ICFSecSecUserObj> toForget = new LinkedList<ICFSecSecUserObj>();
		ICFSecSecUserObj cur = null;
		Iterator<ICFSecSecUserObj> iter = members.values().iterator();
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
	 *	CFSecSecUserObj.
	 */
	public ICFSecSecUserObj newInstance() {
		ICFSecSecUserObj inst = new CFSecSecUserObj( schema );
		return( inst );
	}

	/**
	 *	If your implementation subclasses the objects,
	 *	you'll want to overload the constructByClassCode()
	 *	implementation to return your implementation's
	 *	instances instead of the base implementation.
	 *
	 *	This is the sole factory for instances derived from
	 *	CFSecSecUserObj.
	 */
	public ICFSecSecUserEditObj newEditInstance( ICFSecSecUserObj orig ) {
		ICFSecSecUserEditObj edit = new CFSecSecUserEditObj( orig );
		return( edit );
	}

	public ICFSecSecUserObj realiseSecUser( ICFSecSecUserObj Obj ) {
		ICFSecSecUserObj obj = Obj;
		CFSecSecUserPKey pkey = obj.getPKey();
		ICFSecSecUserObj keepObj = null;
		if( members.containsKey( pkey ) && ( null != members.get( pkey ) ) ) {
			ICFSecSecUserObj existingObj = members.get( pkey );
			keepObj = existingObj;

			/*
			 *	We always rebind the data because if we're being called, some index has
			 *	been updated and is refreshing it's data, which may or may not have changed
			 */

			// Detach object from alternate and duplicate indexes, leave PKey alone

			if( indexByULoginIdx != null ) {
				CFSecSecUserByULoginIdxKey keyULoginIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactorySecUser().newULoginIdxKey();
				keyULoginIdx.setRequiredLoginId( keepObj.getRequiredLoginId() );
				indexByULoginIdx.remove( keyULoginIdx );
			}

			if( indexByEMConfIdx != null ) {
				CFSecSecUserByEMConfIdxKey keyEMConfIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactorySecUser().newEMConfIdxKey();
				keyEMConfIdx.setOptionalEMailConfirmUuid( keepObj.getOptionalEMailConfirmUuid() );
				Map<CFSecSecUserPKey, ICFSecSecUserObj > mapEMConfIdx = indexByEMConfIdx.get( keyEMConfIdx );
				if( mapEMConfIdx != null ) {
					mapEMConfIdx.remove( keepObj.getPKey() );
					if( mapEMConfIdx.size() <= 0 ) {
						indexByEMConfIdx.remove( keyEMConfIdx );
					}
				}
			}

			if( indexByPwdResetIdx != null ) {
				CFSecSecUserByPwdResetIdxKey keyPwdResetIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactorySecUser().newPwdResetIdxKey();
				keyPwdResetIdx.setOptionalPasswordResetUuid( keepObj.getOptionalPasswordResetUuid() );
				Map<CFSecSecUserPKey, ICFSecSecUserObj > mapPwdResetIdx = indexByPwdResetIdx.get( keyPwdResetIdx );
				if( mapPwdResetIdx != null ) {
					mapPwdResetIdx.remove( keepObj.getPKey() );
					if( mapPwdResetIdx.size() <= 0 ) {
						indexByPwdResetIdx.remove( keyPwdResetIdx );
					}
				}
			}

			if( indexByDefDevIdx != null ) {
				CFSecSecUserByDefDevIdxKey keyDefDevIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactorySecUser().newDefDevIdxKey();
				keyDefDevIdx.setOptionalDfltDevUserId( keepObj.getOptionalDfltDevUserId() );
				keyDefDevIdx.setOptionalDfltDevName( keepObj.getOptionalDfltDevName() );
				Map<CFSecSecUserPKey, ICFSecSecUserObj > mapDefDevIdx = indexByDefDevIdx.get( keyDefDevIdx );
				if( mapDefDevIdx != null ) {
					mapDefDevIdx.remove( keepObj.getPKey() );
					if( mapDefDevIdx.size() <= 0 ) {
						indexByDefDevIdx.remove( keyDefDevIdx );
					}
				}
			}

			keepObj.setBuff( Obj.getBuff() );
			// Attach new object to alternate and duplicate indexes -- PKey stay stable

			if( indexByULoginIdx != null ) {
				CFSecSecUserByULoginIdxKey keyULoginIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactorySecUser().newULoginIdxKey();
				keyULoginIdx.setRequiredLoginId( keepObj.getRequiredLoginId() );
				indexByULoginIdx.put( keyULoginIdx, keepObj );
			}

			if( indexByEMConfIdx != null ) {
				CFSecSecUserByEMConfIdxKey keyEMConfIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactorySecUser().newEMConfIdxKey();
				keyEMConfIdx.setOptionalEMailConfirmUuid( keepObj.getOptionalEMailConfirmUuid() );
				Map<CFSecSecUserPKey, ICFSecSecUserObj > mapEMConfIdx = indexByEMConfIdx.get( keyEMConfIdx );
				if( mapEMConfIdx != null ) {
					mapEMConfIdx.put( keepObj.getPKey(), keepObj );
				}
			}

			if( indexByPwdResetIdx != null ) {
				CFSecSecUserByPwdResetIdxKey keyPwdResetIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactorySecUser().newPwdResetIdxKey();
				keyPwdResetIdx.setOptionalPasswordResetUuid( keepObj.getOptionalPasswordResetUuid() );
				Map<CFSecSecUserPKey, ICFSecSecUserObj > mapPwdResetIdx = indexByPwdResetIdx.get( keyPwdResetIdx );
				if( mapPwdResetIdx != null ) {
					mapPwdResetIdx.put( keepObj.getPKey(), keepObj );
				}
			}

			if( indexByDefDevIdx != null ) {
				CFSecSecUserByDefDevIdxKey keyDefDevIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactorySecUser().newDefDevIdxKey();
				keyDefDevIdx.setOptionalDfltDevUserId( keepObj.getOptionalDfltDevUserId() );
				keyDefDevIdx.setOptionalDfltDevName( keepObj.getOptionalDfltDevName() );
				Map<CFSecSecUserPKey, ICFSecSecUserObj > mapDefDevIdx = indexByDefDevIdx.get( keyDefDevIdx );
				if( mapDefDevIdx != null ) {
					mapDefDevIdx.put( keepObj.getPKey(), keepObj );
				}
			}

			if( allSecUser != null ) {
				allSecUser.put( keepObj.getPKey(), keepObj );
			}
		}
		else {
			keepObj = obj;
			keepObj.setIsNew( false );

			// Attach new object to PKey, all, alternate, and duplicate indexes
			members.put( keepObj.getPKey(), keepObj );
			if( allSecUser != null ) {
				allSecUser.put( keepObj.getPKey(), keepObj );
			}

			if( indexByULoginIdx != null ) {
				CFSecSecUserByULoginIdxKey keyULoginIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactorySecUser().newULoginIdxKey();
				keyULoginIdx.setRequiredLoginId( keepObj.getRequiredLoginId() );
				indexByULoginIdx.put( keyULoginIdx, keepObj );
			}

			if( indexByEMConfIdx != null ) {
				CFSecSecUserByEMConfIdxKey keyEMConfIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactorySecUser().newEMConfIdxKey();
				keyEMConfIdx.setOptionalEMailConfirmUuid( keepObj.getOptionalEMailConfirmUuid() );
				Map<CFSecSecUserPKey, ICFSecSecUserObj > mapEMConfIdx = indexByEMConfIdx.get( keyEMConfIdx );
				if( mapEMConfIdx != null ) {
					mapEMConfIdx.put( keepObj.getPKey(), keepObj );
				}
			}

			if( indexByPwdResetIdx != null ) {
				CFSecSecUserByPwdResetIdxKey keyPwdResetIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactorySecUser().newPwdResetIdxKey();
				keyPwdResetIdx.setOptionalPasswordResetUuid( keepObj.getOptionalPasswordResetUuid() );
				Map<CFSecSecUserPKey, ICFSecSecUserObj > mapPwdResetIdx = indexByPwdResetIdx.get( keyPwdResetIdx );
				if( mapPwdResetIdx != null ) {
					mapPwdResetIdx.put( keepObj.getPKey(), keepObj );
				}
			}

			if( indexByDefDevIdx != null ) {
				CFSecSecUserByDefDevIdxKey keyDefDevIdx =
					((ICFSecSchema)schema.getBackingStore()).getFactorySecUser().newDefDevIdxKey();
				keyDefDevIdx.setOptionalDfltDevUserId( keepObj.getOptionalDfltDevUserId() );
				keyDefDevIdx.setOptionalDfltDevName( keepObj.getOptionalDfltDevName() );
				Map<CFSecSecUserPKey, ICFSecSecUserObj > mapDefDevIdx = indexByDefDevIdx.get( keyDefDevIdx );
				if( mapDefDevIdx != null ) {
					mapDefDevIdx.put( keepObj.getPKey(), keepObj );
				}
			}

		}
		return( keepObj );
	}

	public ICFSecSecUserObj createSecUser( ICFSecSecUserObj Obj ) {
		ICFSecSecUserObj obj = Obj;
		CFSecSecUserBuff buff = obj.getSecUserBuff();
		((ICFSecSchema)schema.getBackingStore()).getTableSecUser().createSecUser(
			schema.getAuthorization(),
			buff );
		obj.copyBuffToPKey();
		obj = obj.realise();
		obj.endEdit();
		return( obj );
	}

	public ICFSecSecUserObj readSecUser( CFSecSecUserPKey pkey ) {
		return( readSecUser( pkey, false ) );
	}

	public ICFSecSecUserObj readSecUser( CFSecSecUserPKey pkey, boolean forceRead ) {
		ICFSecSecUserObj obj = null;
		if( ( ! forceRead ) && members.containsKey( pkey ) ) {
			obj = members.get( pkey );
		}
		else {
			CFSecSecUserBuff readBuff = ((ICFSecSchema)schema.getBackingStore()).getTableSecUser().readDerivedByIdIdx( schema.getAuthorization(),
				pkey.getRequiredSecUserId() );
			if( readBuff != null ) {
				obj = schema.getSecUserTableObj().newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactorySecUser().newPKey() );
				obj.setBuff( readBuff );
				obj = (ICFSecSecUserObj)obj.realise();
			}
		}
		return( obj );
	}

	public ICFSecSecUserObj readCachedSecUser( CFSecSecUserPKey pkey ) {
		ICFSecSecUserObj obj = null;
		if( members.containsKey( pkey ) ) {
			obj = members.get( pkey );
		}
		return( obj );
	}

	public void reallyDeepDisposeSecUser( ICFSecSecUserObj obj )
	{
		final String S_ProcName = "CFSecSecUserTableObj.reallyDeepDisposeSecUser() ";
		String classCode;
		if( obj == null ) {
			return;
		}
		CFSecSecUserPKey pkey = obj.getPKey();
		ICFSecSecUserObj existing = readCachedSecUser( pkey );
		if( existing == null ) {
			return;
		}
		members.remove( pkey );
		CFSecSecUserByULoginIdxKey keyULoginIdx = ((ICFSecSchema)schema.getBackingStore()).getFactorySecUser().newULoginIdxKey();
		keyULoginIdx.setRequiredLoginId( existing.getRequiredLoginId() );

		CFSecSecUserByEMConfIdxKey keyEMConfIdx = ((ICFSecSchema)schema.getBackingStore()).getFactorySecUser().newEMConfIdxKey();
		keyEMConfIdx.setOptionalEMailConfirmUuid( existing.getOptionalEMailConfirmUuid() );

		CFSecSecUserByPwdResetIdxKey keyPwdResetIdx = ((ICFSecSchema)schema.getBackingStore()).getFactorySecUser().newPwdResetIdxKey();
		keyPwdResetIdx.setOptionalPasswordResetUuid( existing.getOptionalPasswordResetUuid() );

		CFSecSecUserByDefDevIdxKey keyDefDevIdx = ((ICFSecSchema)schema.getBackingStore()).getFactorySecUser().newDefDevIdxKey();
		keyDefDevIdx.setOptionalDfltDevUserId( existing.getOptionalDfltDevUserId() );
		keyDefDevIdx.setOptionalDfltDevName( existing.getOptionalDfltDevName() );


					schema.getTSecGrpMembTableObj().deepDisposeTSecGrpMembByUserIdx( existing.getRequiredSecUserId() );
					schema.getSecGrpMembTableObj().deepDisposeSecGrpMembByUserIdx( existing.getRequiredSecUserId() );
					schema.getSecSessionTableObj().deepDisposeSecSessionBySecUserIdx( existing.getRequiredSecUserId() );
					schema.getSecSessionTableObj().deepDisposeSecSessionBySecProxyIdx( existing.getRequiredSecUserId() );
					schema.getSecDeviceTableObj().deepDisposeSecDeviceByUserIdx( existing.getRequiredSecUserId() );

		if( indexByULoginIdx != null ) {
			indexByULoginIdx.remove( keyULoginIdx );
		}

		if( indexByEMConfIdx != null ) {
			if( indexByEMConfIdx.containsKey( keyEMConfIdx ) ) {
				indexByEMConfIdx.get( keyEMConfIdx ).remove( pkey );
				if( indexByEMConfIdx.get( keyEMConfIdx ).size() <= 0 ) {
					indexByEMConfIdx.remove( keyEMConfIdx );
				}
			}
		}

		if( indexByPwdResetIdx != null ) {
			if( indexByPwdResetIdx.containsKey( keyPwdResetIdx ) ) {
				indexByPwdResetIdx.get( keyPwdResetIdx ).remove( pkey );
				if( indexByPwdResetIdx.get( keyPwdResetIdx ).size() <= 0 ) {
					indexByPwdResetIdx.remove( keyPwdResetIdx );
				}
			}
		}

		if( indexByDefDevIdx != null ) {
			if( indexByDefDevIdx.containsKey( keyDefDevIdx ) ) {
				indexByDefDevIdx.get( keyDefDevIdx ).remove( pkey );
				if( indexByDefDevIdx.get( keyDefDevIdx ).size() <= 0 ) {
					indexByDefDevIdx.remove( keyDefDevIdx );
				}
			}
		}


	}
	public void deepDisposeSecUser( CFSecSecUserPKey pkey ) {
		ICFSecSecUserObj obj = readCachedSecUser( pkey );
		if( obj != null ) {
			obj.forget();
		}
	}

	public ICFSecSecUserObj lockSecUser( CFSecSecUserPKey pkey ) {
		ICFSecSecUserObj locked = null;
		CFSecSecUserBuff lockBuff = ((ICFSecSchema)schema.getBackingStore()).getTableSecUser().lockDerived( schema.getAuthorization(), pkey );
		if( lockBuff != null ) {
				locked = schema.getSecUserTableObj().newInstance();
			locked.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactorySecUser().newPKey() );
			locked.setBuff( lockBuff );
			locked = (ICFSecSecUserObj)locked.realise();
		}
		else {
			throw new CFLibCollisionDetectedException( getClass(), "lockSecUser", pkey );
		}
		return( locked );
	}

	public List<ICFSecSecUserObj> readAllSecUser() {
		return( readAllSecUser( false ) );
	}

	public List<ICFSecSecUserObj> readAllSecUser( boolean forceRead ) {
		final String S_ProcName = "readAllSecUser";
		if( ( allSecUser == null ) || forceRead ) {
			Map<CFSecSecUserPKey, ICFSecSecUserObj> map = new HashMap<CFSecSecUserPKey,ICFSecSecUserObj>();
			allSecUser = map;
			CFSecSecUserBuff[] buffList = ((ICFSecSchema)schema.getBackingStore()).getTableSecUser().readAllDerived( schema.getAuthorization() );
			CFSecSecUserBuff buff;
			ICFSecSecUserObj obj;
			for( int idx = 0; idx < buffList.length; idx ++ ) {
				buff = buffList[ idx ];
				obj = newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactorySecUser().newPKey() );
				obj.setBuff( buff );
				ICFSecSecUserObj realised = (ICFSecSecUserObj)obj.realise();
			}
		}
		int len = allSecUser.size();
		ICFSecSecUserObj arr[] = new ICFSecSecUserObj[len];
		Iterator<ICFSecSecUserObj> valIter = allSecUser.values().iterator();
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
		ArrayList<ICFSecSecUserObj> arrayList = new ArrayList<ICFSecSecUserObj>(len);
		for( idx = 0; idx < len; idx ++ ) {
			arrayList.add( arr[idx] );
		}

		Comparator<ICFSecSecUserObj> cmp = new Comparator<ICFSecSecUserObj>() {
			public int compare( ICFSecSecUserObj lhs, ICFSecSecUserObj rhs ) {
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
					CFSecSecUserPKey lhsPKey = lhs.getPKey();
					CFSecSecUserPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		List<ICFSecSecUserObj> sortedList = arrayList;
		return( sortedList );
	}

	public List<ICFSecSecUserObj> readCachedAllSecUser() {
		final String S_ProcName = "readCachedAllSecUser";
		ArrayList<ICFSecSecUserObj> arrayList = new ArrayList<ICFSecSecUserObj>();
		if( allSecUser != null ) {
			int len = allSecUser.size();
			ICFSecSecUserObj arr[] = new ICFSecSecUserObj[len];
			Iterator<ICFSecSecUserObj> valIter = allSecUser.values().iterator();
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
		Comparator<ICFSecSecUserObj> cmp = new Comparator<ICFSecSecUserObj>() {
			public int compare( ICFSecSecUserObj lhs, ICFSecSecUserObj rhs ) {
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
					CFSecSecUserPKey lhsPKey = lhs.getPKey();
					CFSecSecUserPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		return( arrayList );
	}

	/**
	 *	Return a sorted map of a page of the SecUser-derived instances in the database.
	 *
	 *	@return	List of ICFSecSecUserObj instance, sorted by their primary keys, which
	 *		may include an empty set.
	 */
	public List<ICFSecSecUserObj> pageAllSecUser(UUID priorSecUserId )
	{
		final String S_ProcName = "pageAllSecUser";
		Map<CFSecSecUserPKey, ICFSecSecUserObj> map = new HashMap<CFSecSecUserPKey,ICFSecSecUserObj>();
		CFSecSecUserBuff[] buffList = ((ICFSecSchema)schema.getBackingStore()).getTableSecUser().pageAllBuff( schema.getAuthorization(),
			priorSecUserId );
		CFSecSecUserBuff buff;
		ICFSecSecUserObj obj;
		ICFSecSecUserObj realised;
		ArrayList<ICFSecSecUserObj> arrayList = new ArrayList<ICFSecSecUserObj>( buffList.length );
		for( int idx = 0; idx < buffList.length; idx ++ ) {
			buff = buffList[ idx ];
				obj = newInstance();
			obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactorySecUser().newPKey() );
			obj.setBuff( buff );
			realised = (ICFSecSecUserObj)obj.realise();
			arrayList.add( realised );
		}
		return( arrayList );
	}

	public ICFSecSecUserObj readSecUserByIdIdx( UUID SecUserId )
	{
		return( readSecUserByIdIdx( SecUserId,
			false ) );
	}

	public ICFSecSecUserObj readSecUserByIdIdx( UUID SecUserId, boolean forceRead )
	{
		CFSecSecUserPKey pkey = ((ICFSecSchema)schema.getBackingStore()).getFactorySecUser().newPKey();
		pkey.setRequiredSecUserId( SecUserId );
		ICFSecSecUserObj obj = readSecUser( pkey, forceRead );
		return( obj );
	}

	public ICFSecSecUserObj readSecUserByULoginIdx( String LoginId )
	{
		return( readSecUserByULoginIdx( LoginId,
			false ) );
	}

	public ICFSecSecUserObj readSecUserByULoginIdx( String LoginId, boolean forceRead )
	{
		if( indexByULoginIdx == null ) {
			indexByULoginIdx = new HashMap< CFSecSecUserByULoginIdxKey,
				ICFSecSecUserObj >();
		}
		CFSecSecUserByULoginIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactorySecUser().newULoginIdxKey();
		key.setRequiredLoginId( LoginId );
		ICFSecSecUserObj obj = null;
		if( ( ! forceRead ) && indexByULoginIdx.containsKey( key ) ) {
			obj = indexByULoginIdx.get( key );
		}
		else {
			CFSecSecUserBuff buff = ((ICFSecSchema)schema.getBackingStore()).getTableSecUser().readDerivedByULoginIdx( schema.getAuthorization(),
				LoginId );
			if( buff != null ) {
				obj = schema.getSecUserTableObj().newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactorySecUser().newPKey() );
				obj.setBuff( buff );
				obj = (ICFSecSecUserObj)obj.realise();
			}
		}
		return( obj );
	}

	public List<ICFSecSecUserObj> readSecUserByEMConfIdx( UUID EMailConfirmUuid )
	{
		return( readSecUserByEMConfIdx( EMailConfirmUuid,
			false ) );
	}

	public List<ICFSecSecUserObj> readSecUserByEMConfIdx( UUID EMailConfirmUuid,
		boolean forceRead )
	{
		final String S_ProcName = "readSecUserByEMConfIdx";
		CFSecSecUserByEMConfIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactorySecUser().newEMConfIdxKey();
		key.setOptionalEMailConfirmUuid( EMailConfirmUuid );
		Map<CFSecSecUserPKey, ICFSecSecUserObj> dict;
		if( indexByEMConfIdx == null ) {
			indexByEMConfIdx = new HashMap< CFSecSecUserByEMConfIdxKey,
				Map< CFSecSecUserPKey, ICFSecSecUserObj > >();
		}
		if( ( ! forceRead ) && indexByEMConfIdx.containsKey( key ) ) {
			dict = indexByEMConfIdx.get( key );
		}
		else {
			dict = new HashMap<CFSecSecUserPKey, ICFSecSecUserObj>();
			ICFSecSecUserObj obj;
			CFSecSecUserBuff[] buffList = ((ICFSecSchema)schema.getBackingStore()).getTableSecUser().readDerivedByEMConfIdx( schema.getAuthorization(),
				EMailConfirmUuid );
			CFSecSecUserBuff buff;
			for( int idx = 0; idx < buffList.length; idx ++ ) {
				buff = buffList[ idx ];
				obj = schema.getSecUserTableObj().newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactorySecUser().newPKey() );
				obj.setBuff( buff );
				ICFSecSecUserObj realised = (ICFSecSecUserObj)obj.realise();
				dict.put( realised.getPKey(), realised );
			}
			indexByEMConfIdx.put( key, dict );
		}
		int len = dict.size();
		ICFSecSecUserObj arr[] = new ICFSecSecUserObj[len];
		Iterator<ICFSecSecUserObj> valIter = dict.values().iterator();
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
		ArrayList<ICFSecSecUserObj> arrayList = new ArrayList<ICFSecSecUserObj>(len);
		for( idx = 0; idx < len; idx ++ ) {
			arrayList.add( arr[idx] );
		}

		Comparator<ICFSecSecUserObj> cmp = new Comparator<ICFSecSecUserObj>() {
			public int compare( ICFSecSecUserObj lhs, ICFSecSecUserObj rhs ) {
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
					CFSecSecUserPKey lhsPKey = lhs.getPKey();
					CFSecSecUserPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		List<ICFSecSecUserObj> sortedList = arrayList;
		return( sortedList );
	}

	public List<ICFSecSecUserObj> readSecUserByPwdResetIdx( UUID PasswordResetUuid )
	{
		return( readSecUserByPwdResetIdx( PasswordResetUuid,
			false ) );
	}

	public List<ICFSecSecUserObj> readSecUserByPwdResetIdx( UUID PasswordResetUuid,
		boolean forceRead )
	{
		final String S_ProcName = "readSecUserByPwdResetIdx";
		CFSecSecUserByPwdResetIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactorySecUser().newPwdResetIdxKey();
		key.setOptionalPasswordResetUuid( PasswordResetUuid );
		Map<CFSecSecUserPKey, ICFSecSecUserObj> dict;
		if( indexByPwdResetIdx == null ) {
			indexByPwdResetIdx = new HashMap< CFSecSecUserByPwdResetIdxKey,
				Map< CFSecSecUserPKey, ICFSecSecUserObj > >();
		}
		if( ( ! forceRead ) && indexByPwdResetIdx.containsKey( key ) ) {
			dict = indexByPwdResetIdx.get( key );
		}
		else {
			dict = new HashMap<CFSecSecUserPKey, ICFSecSecUserObj>();
			ICFSecSecUserObj obj;
			CFSecSecUserBuff[] buffList = ((ICFSecSchema)schema.getBackingStore()).getTableSecUser().readDerivedByPwdResetIdx( schema.getAuthorization(),
				PasswordResetUuid );
			CFSecSecUserBuff buff;
			for( int idx = 0; idx < buffList.length; idx ++ ) {
				buff = buffList[ idx ];
				obj = schema.getSecUserTableObj().newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactorySecUser().newPKey() );
				obj.setBuff( buff );
				ICFSecSecUserObj realised = (ICFSecSecUserObj)obj.realise();
				dict.put( realised.getPKey(), realised );
			}
			indexByPwdResetIdx.put( key, dict );
		}
		int len = dict.size();
		ICFSecSecUserObj arr[] = new ICFSecSecUserObj[len];
		Iterator<ICFSecSecUserObj> valIter = dict.values().iterator();
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
		ArrayList<ICFSecSecUserObj> arrayList = new ArrayList<ICFSecSecUserObj>(len);
		for( idx = 0; idx < len; idx ++ ) {
			arrayList.add( arr[idx] );
		}

		Comparator<ICFSecSecUserObj> cmp = new Comparator<ICFSecSecUserObj>() {
			public int compare( ICFSecSecUserObj lhs, ICFSecSecUserObj rhs ) {
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
					CFSecSecUserPKey lhsPKey = lhs.getPKey();
					CFSecSecUserPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		List<ICFSecSecUserObj> sortedList = arrayList;
		return( sortedList );
	}

	public List<ICFSecSecUserObj> readSecUserByDefDevIdx( UUID DfltDevUserId,
		String DfltDevName )
	{
		return( readSecUserByDefDevIdx( DfltDevUserId,
			DfltDevName,
			false ) );
	}

	public List<ICFSecSecUserObj> readSecUserByDefDevIdx( UUID DfltDevUserId,
		String DfltDevName,
		boolean forceRead )
	{
		final String S_ProcName = "readSecUserByDefDevIdx";
		CFSecSecUserByDefDevIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactorySecUser().newDefDevIdxKey();
		key.setOptionalDfltDevUserId( DfltDevUserId );
		key.setOptionalDfltDevName( DfltDevName );
		Map<CFSecSecUserPKey, ICFSecSecUserObj> dict;
		if( indexByDefDevIdx == null ) {
			indexByDefDevIdx = new HashMap< CFSecSecUserByDefDevIdxKey,
				Map< CFSecSecUserPKey, ICFSecSecUserObj > >();
		}
		if( ( ! forceRead ) && indexByDefDevIdx.containsKey( key ) ) {
			dict = indexByDefDevIdx.get( key );
		}
		else {
			dict = new HashMap<CFSecSecUserPKey, ICFSecSecUserObj>();
			ICFSecSecUserObj obj;
			CFSecSecUserBuff[] buffList = ((ICFSecSchema)schema.getBackingStore()).getTableSecUser().readDerivedByDefDevIdx( schema.getAuthorization(),
				DfltDevUserId,
				DfltDevName );
			CFSecSecUserBuff buff;
			for( int idx = 0; idx < buffList.length; idx ++ ) {
				buff = buffList[ idx ];
				obj = schema.getSecUserTableObj().newInstance();
				obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactorySecUser().newPKey() );
				obj.setBuff( buff );
				ICFSecSecUserObj realised = (ICFSecSecUserObj)obj.realise();
				dict.put( realised.getPKey(), realised );
			}
			indexByDefDevIdx.put( key, dict );
		}
		int len = dict.size();
		ICFSecSecUserObj arr[] = new ICFSecSecUserObj[len];
		Iterator<ICFSecSecUserObj> valIter = dict.values().iterator();
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
		ArrayList<ICFSecSecUserObj> arrayList = new ArrayList<ICFSecSecUserObj>(len);
		for( idx = 0; idx < len; idx ++ ) {
			arrayList.add( arr[idx] );
		}

		Comparator<ICFSecSecUserObj> cmp = new Comparator<ICFSecSecUserObj>() {
			public int compare( ICFSecSecUserObj lhs, ICFSecSecUserObj rhs ) {
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
					CFSecSecUserPKey lhsPKey = lhs.getPKey();
					CFSecSecUserPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		List<ICFSecSecUserObj> sortedList = arrayList;
		return( sortedList );
	}

	public ICFSecSecUserObj readCachedSecUserByIdIdx( UUID SecUserId )
	{
		ICFSecSecUserObj obj = null;
		CFSecSecUserPKey pkey = ((ICFSecSchema)schema.getBackingStore()).getFactorySecUser().newPKey();
		pkey.setRequiredSecUserId( SecUserId );
		obj = readCachedSecUser( pkey );
		return( obj );
	}

	public ICFSecSecUserObj readCachedSecUserByULoginIdx( String LoginId )
	{
		ICFSecSecUserObj obj = null;
		CFSecSecUserByULoginIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactorySecUser().newULoginIdxKey();
		key.setRequiredLoginId( LoginId );
		if( indexByULoginIdx != null ) {
			if( indexByULoginIdx.containsKey( key ) ) {
				obj = indexByULoginIdx.get( key );
			}
			else {
				Iterator<ICFSecSecUserObj> valIter = members.values().iterator();
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
			Iterator<ICFSecSecUserObj> valIter = members.values().iterator();
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

	public List<ICFSecSecUserObj> readCachedSecUserByEMConfIdx( UUID EMailConfirmUuid )
	{
		final String S_ProcName = "readCachedSecUserByEMConfIdx";
		CFSecSecUserByEMConfIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactorySecUser().newEMConfIdxKey();
		key.setOptionalEMailConfirmUuid( EMailConfirmUuid );
		ArrayList<ICFSecSecUserObj> arrayList = new ArrayList<ICFSecSecUserObj>();
		if( indexByEMConfIdx != null ) {
			Map<CFSecSecUserPKey, ICFSecSecUserObj> dict;
			if( indexByEMConfIdx.containsKey( key ) ) {
				dict = indexByEMConfIdx.get( key );
				int len = dict.size();
				ICFSecSecUserObj arr[] = new ICFSecSecUserObj[len];
				Iterator<ICFSecSecUserObj> valIter = dict.values().iterator();
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
			ICFSecSecUserObj obj;
			Iterator<ICFSecSecUserObj> valIter = members.values().iterator();
			while( valIter.hasNext() ) {
				obj = valIter.next();
				if( obj != null ) {
					if( obj.getBuff().compareTo( key ) == 0 ) {
						arrayList.add( obj );
					}
				}
			}
		}
		Comparator<ICFSecSecUserObj> cmp = new Comparator<ICFSecSecUserObj>() {
			public int compare( ICFSecSecUserObj lhs, ICFSecSecUserObj rhs ) {
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
					CFSecSecUserPKey lhsPKey = lhs.getPKey();
					CFSecSecUserPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		return( arrayList );
	}

	public List<ICFSecSecUserObj> readCachedSecUserByPwdResetIdx( UUID PasswordResetUuid )
	{
		final String S_ProcName = "readCachedSecUserByPwdResetIdx";
		CFSecSecUserByPwdResetIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactorySecUser().newPwdResetIdxKey();
		key.setOptionalPasswordResetUuid( PasswordResetUuid );
		ArrayList<ICFSecSecUserObj> arrayList = new ArrayList<ICFSecSecUserObj>();
		if( indexByPwdResetIdx != null ) {
			Map<CFSecSecUserPKey, ICFSecSecUserObj> dict;
			if( indexByPwdResetIdx.containsKey( key ) ) {
				dict = indexByPwdResetIdx.get( key );
				int len = dict.size();
				ICFSecSecUserObj arr[] = new ICFSecSecUserObj[len];
				Iterator<ICFSecSecUserObj> valIter = dict.values().iterator();
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
			ICFSecSecUserObj obj;
			Iterator<ICFSecSecUserObj> valIter = members.values().iterator();
			while( valIter.hasNext() ) {
				obj = valIter.next();
				if( obj != null ) {
					if( obj.getBuff().compareTo( key ) == 0 ) {
						arrayList.add( obj );
					}
				}
			}
		}
		Comparator<ICFSecSecUserObj> cmp = new Comparator<ICFSecSecUserObj>() {
			public int compare( ICFSecSecUserObj lhs, ICFSecSecUserObj rhs ) {
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
					CFSecSecUserPKey lhsPKey = lhs.getPKey();
					CFSecSecUserPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		return( arrayList );
	}

	public List<ICFSecSecUserObj> readCachedSecUserByDefDevIdx( UUID DfltDevUserId,
		String DfltDevName )
	{
		final String S_ProcName = "readCachedSecUserByDefDevIdx";
		CFSecSecUserByDefDevIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactorySecUser().newDefDevIdxKey();
		key.setOptionalDfltDevUserId( DfltDevUserId );
		key.setOptionalDfltDevName( DfltDevName );
		ArrayList<ICFSecSecUserObj> arrayList = new ArrayList<ICFSecSecUserObj>();
		if( indexByDefDevIdx != null ) {
			Map<CFSecSecUserPKey, ICFSecSecUserObj> dict;
			if( indexByDefDevIdx.containsKey( key ) ) {
				dict = indexByDefDevIdx.get( key );
				int len = dict.size();
				ICFSecSecUserObj arr[] = new ICFSecSecUserObj[len];
				Iterator<ICFSecSecUserObj> valIter = dict.values().iterator();
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
			ICFSecSecUserObj obj;
			Iterator<ICFSecSecUserObj> valIter = members.values().iterator();
			while( valIter.hasNext() ) {
				obj = valIter.next();
				if( obj != null ) {
					if( obj.getBuff().compareTo( key ) == 0 ) {
						arrayList.add( obj );
					}
				}
			}
		}
		Comparator<ICFSecSecUserObj> cmp = new Comparator<ICFSecSecUserObj>() {
			public int compare( ICFSecSecUserObj lhs, ICFSecSecUserObj rhs ) {
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
					CFSecSecUserPKey lhsPKey = lhs.getPKey();
					CFSecSecUserPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		return( arrayList );
	}

	public void deepDisposeSecUserByIdIdx( UUID SecUserId )
	{
		ICFSecSecUserObj obj = readCachedSecUserByIdIdx( SecUserId );
		if( obj != null ) {
			obj.forget();
		}
	}

	public void deepDisposeSecUserByULoginIdx( String LoginId )
	{
		ICFSecSecUserObj obj = readCachedSecUserByULoginIdx( LoginId );
		if( obj != null ) {
			obj.forget();
		}
	}

	public void deepDisposeSecUserByEMConfIdx( UUID EMailConfirmUuid )
	{
		final String S_ProcName = "deepDisposeSecUserByEMConfIdx";
		ICFSecSecUserObj obj;
		List<ICFSecSecUserObj> arrayList = readCachedSecUserByEMConfIdx( EMailConfirmUuid );
		if( arrayList != null )  {
			Iterator<ICFSecSecUserObj> arrayIter = arrayList.iterator();
			while( arrayIter.hasNext() ) {
				obj = arrayIter.next();
				if( obj != null ) {
					obj.forget();
				}
			}
		}
	}

	public void deepDisposeSecUserByPwdResetIdx( UUID PasswordResetUuid )
	{
		final String S_ProcName = "deepDisposeSecUserByPwdResetIdx";
		ICFSecSecUserObj obj;
		List<ICFSecSecUserObj> arrayList = readCachedSecUserByPwdResetIdx( PasswordResetUuid );
		if( arrayList != null )  {
			Iterator<ICFSecSecUserObj> arrayIter = arrayList.iterator();
			while( arrayIter.hasNext() ) {
				obj = arrayIter.next();
				if( obj != null ) {
					obj.forget();
				}
			}
		}
	}

	public void deepDisposeSecUserByDefDevIdx( UUID DfltDevUserId,
		String DfltDevName )
	{
		final String S_ProcName = "deepDisposeSecUserByDefDevIdx";
		ICFSecSecUserObj obj;
		List<ICFSecSecUserObj> arrayList = readCachedSecUserByDefDevIdx( DfltDevUserId,
				DfltDevName );
		if( arrayList != null )  {
			Iterator<ICFSecSecUserObj> arrayIter = arrayList.iterator();
			while( arrayIter.hasNext() ) {
				obj = arrayIter.next();
				if( obj != null ) {
					obj.forget();
				}
			}
		}
	}

	/**
	 *	Read a page of data as a List of SecUser-derived instances sorted by their primary keys,
	 *	as identified by the duplicate EMConfIdx key attributes.
	 *
	 *	@param	argEMailConfirmUuid	The SecUser key attribute of the instance generating the id.
	 *
	 *	@return	A List of SecUser-derived instances sorted by their primary keys,
	 *		as identified by the key attributes, which may be an empty set.
	 */
	public List<ICFSecSecUserObj> pageSecUserByEMConfIdx( UUID EMailConfirmUuid,
		UUID priorSecUserId )
	{
		final String S_ProcName = "pageSecUserByEMConfIdx";
		CFSecSecUserByEMConfIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactorySecUser().newEMConfIdxKey();
		key.setOptionalEMailConfirmUuid( EMailConfirmUuid );
		List<ICFSecSecUserObj> retList = new LinkedList<ICFSecSecUserObj>();
		ICFSecSecUserObj obj;
		CFSecSecUserBuff[] buffList = ((ICFSecSchema)schema.getBackingStore()).getTableSecUser().pageBuffByEMConfIdx( schema.getAuthorization(),
				EMailConfirmUuid,
			priorSecUserId );
		CFSecSecUserBuff buff;
		for( int idx = 0; idx < buffList.length; idx ++ ) {
			buff = buffList[ idx ];
				obj = schema.getSecUserTableObj().newInstance();
			obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactorySecUser().newPKey() );
			obj.setBuff( buff );
			ICFSecSecUserObj realised = (ICFSecSecUserObj)obj.realise();
			retList.add( realised );
		}
		return( retList );
	}

	/**
	 *	Read a page of data as a List of SecUser-derived instances sorted by their primary keys,
	 *	as identified by the duplicate PwdResetIdx key attributes.
	 *
	 *	@param	argPasswordResetUuid	The SecUser key attribute of the instance generating the id.
	 *
	 *	@return	A List of SecUser-derived instances sorted by their primary keys,
	 *		as identified by the key attributes, which may be an empty set.
	 */
	public List<ICFSecSecUserObj> pageSecUserByPwdResetIdx( UUID PasswordResetUuid,
		UUID priorSecUserId )
	{
		final String S_ProcName = "pageSecUserByPwdResetIdx";
		CFSecSecUserByPwdResetIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactorySecUser().newPwdResetIdxKey();
		key.setOptionalPasswordResetUuid( PasswordResetUuid );
		List<ICFSecSecUserObj> retList = new LinkedList<ICFSecSecUserObj>();
		ICFSecSecUserObj obj;
		CFSecSecUserBuff[] buffList = ((ICFSecSchema)schema.getBackingStore()).getTableSecUser().pageBuffByPwdResetIdx( schema.getAuthorization(),
				PasswordResetUuid,
			priorSecUserId );
		CFSecSecUserBuff buff;
		for( int idx = 0; idx < buffList.length; idx ++ ) {
			buff = buffList[ idx ];
				obj = schema.getSecUserTableObj().newInstance();
			obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactorySecUser().newPKey() );
			obj.setBuff( buff );
			ICFSecSecUserObj realised = (ICFSecSecUserObj)obj.realise();
			retList.add( realised );
		}
		return( retList );
	}

	/**
	 *	Read a page of data as a List of SecUser-derived instances sorted by their primary keys,
	 *	as identified by the duplicate DefDevIdx key attributes.
	 *
	 *	@param	argDfltDevUserId	The SecUser key attribute of the instance generating the id.
	 *
	 *	@param	argDfltDevName	The SecUser key attribute of the instance generating the id.
	 *
	 *	@return	A List of SecUser-derived instances sorted by their primary keys,
	 *		as identified by the key attributes, which may be an empty set.
	 */
	public List<ICFSecSecUserObj> pageSecUserByDefDevIdx( UUID DfltDevUserId,
		String DfltDevName,
		UUID priorSecUserId )
	{
		final String S_ProcName = "pageSecUserByDefDevIdx";
		CFSecSecUserByDefDevIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactorySecUser().newDefDevIdxKey();
		key.setOptionalDfltDevUserId( DfltDevUserId );
		key.setOptionalDfltDevName( DfltDevName );
		List<ICFSecSecUserObj> retList = new LinkedList<ICFSecSecUserObj>();
		ICFSecSecUserObj obj;
		CFSecSecUserBuff[] buffList = ((ICFSecSchema)schema.getBackingStore()).getTableSecUser().pageBuffByDefDevIdx( schema.getAuthorization(),
				DfltDevUserId,
				DfltDevName,
			priorSecUserId );
		CFSecSecUserBuff buff;
		for( int idx = 0; idx < buffList.length; idx ++ ) {
			buff = buffList[ idx ];
				obj = schema.getSecUserTableObj().newInstance();
			obj.setPKey( ((ICFSecSchema)schema.getBackingStore()).getFactorySecUser().newPKey() );
			obj.setBuff( buff );
			ICFSecSecUserObj realised = (ICFSecSecUserObj)obj.realise();
			retList.add( realised );
		}
		return( retList );
	}

	public ICFSecSecUserObj updateSecUser( ICFSecSecUserObj Obj ) {
		ICFSecSecUserObj obj = Obj;
		((ICFSecSchema)schema.getBackingStore()).getTableSecUser().updateSecUser( schema.getAuthorization(),
			Obj.getSecUserBuff() );
		obj = (ICFSecSecUserObj)Obj.realise();
		obj.endEdit();
		return( obj );
	}

	public void deleteSecUser( ICFSecSecUserObj Obj ) {
		ICFSecSecUserObj obj = Obj;
		((ICFSecSchema)schema.getBackingStore()).getTableSecUser().deleteSecUser( schema.getAuthorization(),
			obj.getSecUserBuff() );
		Obj.forget();
	}

	public void deleteSecUserByIdIdx( UUID SecUserId )
	{
		CFSecSecUserPKey pkey = ((ICFSecSchema)schema.getBackingStore()).getFactorySecUser().newPKey();
		pkey.setRequiredSecUserId( SecUserId );
		ICFSecSecUserObj obj = readSecUser( pkey );
		if( obj != null ) {
			ICFSecSecUserEditObj editObj = (ICFSecSecUserEditObj)obj.getEdit();
			boolean editStarted;
			if( editObj == null ) {
				editObj = (ICFSecSecUserEditObj)obj.beginEdit();
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
		deepDisposeSecUserByIdIdx( SecUserId );
	}

	public void deleteSecUserByULoginIdx( String LoginId )
	{
		if( indexByULoginIdx == null ) {
			indexByULoginIdx = new HashMap< CFSecSecUserByULoginIdxKey,
				ICFSecSecUserObj >();
		}
		CFSecSecUserByULoginIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactorySecUser().newULoginIdxKey();
		key.setRequiredLoginId( LoginId );
		ICFSecSecUserObj obj = null;
		if( indexByULoginIdx.containsKey( key ) ) {
			obj = indexByULoginIdx.get( key );
			((ICFSecSchema)schema.getBackingStore()).getTableSecUser().deleteSecUserByULoginIdx( schema.getAuthorization(),
				LoginId );
			obj.forget();
		}
		else {
			((ICFSecSchema)schema.getBackingStore()).getTableSecUser().deleteSecUserByULoginIdx( schema.getAuthorization(),
				LoginId );
		}
		deepDisposeSecUserByULoginIdx( LoginId );
	}

	public void deleteSecUserByEMConfIdx( UUID EMailConfirmUuid )
	{
		CFSecSecUserByEMConfIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactorySecUser().newEMConfIdxKey();
		key.setOptionalEMailConfirmUuid( EMailConfirmUuid );
		if( indexByEMConfIdx == null ) {
			indexByEMConfIdx = new HashMap< CFSecSecUserByEMConfIdxKey,
				Map< CFSecSecUserPKey, ICFSecSecUserObj > >();
		}
		if( indexByEMConfIdx.containsKey( key ) ) {
			Map<CFSecSecUserPKey, ICFSecSecUserObj> dict = indexByEMConfIdx.get( key );
			((ICFSecSchema)schema.getBackingStore()).getTableSecUser().deleteSecUserByEMConfIdx( schema.getAuthorization(),
				EMailConfirmUuid );
			Iterator<ICFSecSecUserObj> iter = dict.values().iterator();
			ICFSecSecUserObj obj;
			List<ICFSecSecUserObj> toForget = new LinkedList<ICFSecSecUserObj>();
			while( iter.hasNext() ) {
				obj = iter.next();
				toForget.add( obj );
			}
			iter = toForget.iterator();
			while( iter.hasNext() ) {
				obj = iter.next();
				obj.forget();
			}
			indexByEMConfIdx.remove( key );
		}
		else {
			((ICFSecSchema)schema.getBackingStore()).getTableSecUser().deleteSecUserByEMConfIdx( schema.getAuthorization(),
				EMailConfirmUuid );
		}
		deepDisposeSecUserByEMConfIdx( EMailConfirmUuid );
	}

	public void deleteSecUserByPwdResetIdx( UUID PasswordResetUuid )
	{
		CFSecSecUserByPwdResetIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactorySecUser().newPwdResetIdxKey();
		key.setOptionalPasswordResetUuid( PasswordResetUuid );
		if( indexByPwdResetIdx == null ) {
			indexByPwdResetIdx = new HashMap< CFSecSecUserByPwdResetIdxKey,
				Map< CFSecSecUserPKey, ICFSecSecUserObj > >();
		}
		if( indexByPwdResetIdx.containsKey( key ) ) {
			Map<CFSecSecUserPKey, ICFSecSecUserObj> dict = indexByPwdResetIdx.get( key );
			((ICFSecSchema)schema.getBackingStore()).getTableSecUser().deleteSecUserByPwdResetIdx( schema.getAuthorization(),
				PasswordResetUuid );
			Iterator<ICFSecSecUserObj> iter = dict.values().iterator();
			ICFSecSecUserObj obj;
			List<ICFSecSecUserObj> toForget = new LinkedList<ICFSecSecUserObj>();
			while( iter.hasNext() ) {
				obj = iter.next();
				toForget.add( obj );
			}
			iter = toForget.iterator();
			while( iter.hasNext() ) {
				obj = iter.next();
				obj.forget();
			}
			indexByPwdResetIdx.remove( key );
		}
		else {
			((ICFSecSchema)schema.getBackingStore()).getTableSecUser().deleteSecUserByPwdResetIdx( schema.getAuthorization(),
				PasswordResetUuid );
		}
		deepDisposeSecUserByPwdResetIdx( PasswordResetUuid );
	}

	public void deleteSecUserByDefDevIdx( UUID DfltDevUserId,
		String DfltDevName )
	{
		CFSecSecUserByDefDevIdxKey key = ((ICFSecSchema)schema.getBackingStore()).getFactorySecUser().newDefDevIdxKey();
		key.setOptionalDfltDevUserId( DfltDevUserId );
		key.setOptionalDfltDevName( DfltDevName );
		if( indexByDefDevIdx == null ) {
			indexByDefDevIdx = new HashMap< CFSecSecUserByDefDevIdxKey,
				Map< CFSecSecUserPKey, ICFSecSecUserObj > >();
		}
		if( indexByDefDevIdx.containsKey( key ) ) {
			Map<CFSecSecUserPKey, ICFSecSecUserObj> dict = indexByDefDevIdx.get( key );
			((ICFSecSchema)schema.getBackingStore()).getTableSecUser().deleteSecUserByDefDevIdx( schema.getAuthorization(),
				DfltDevUserId,
				DfltDevName );
			Iterator<ICFSecSecUserObj> iter = dict.values().iterator();
			ICFSecSecUserObj obj;
			List<ICFSecSecUserObj> toForget = new LinkedList<ICFSecSecUserObj>();
			while( iter.hasNext() ) {
				obj = iter.next();
				toForget.add( obj );
			}
			iter = toForget.iterator();
			while( iter.hasNext() ) {
				obj = iter.next();
				obj.forget();
			}
			indexByDefDevIdx.remove( key );
		}
		else {
			((ICFSecSchema)schema.getBackingStore()).getTableSecUser().deleteSecUserByDefDevIdx( schema.getAuthorization(),
				DfltDevUserId,
				DfltDevName );
		}
		deepDisposeSecUserByDefDevIdx( DfltDevUserId,
				DfltDevName );
	}

	public ICFSecSecUserObj getSystemUser() {
		boolean transactionStarted = schema.beginTransaction();
		ICFSecSecUserObj secUserObj;
		try {
			secUserObj = schema.getSecUserTableObj().readSecUserByULoginIdx( "system" );
			if( secUserObj == null ) {
				secUserObj = newInstance();
				ICFSecSecUserEditObj secUserEdit = secUserObj.beginEdit();
				secUserEdit.setRequiredEMailAddress( "system" );
				secUserObj = secUserEdit.create();
				secUserEdit = null;
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
		return( secUserObj );
	}
}