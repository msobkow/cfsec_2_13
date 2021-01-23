// Description: C++18 Table Object implementation for CFSec.

/*
 *	org.msscf.msscf.CFSec
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFSec 2.13 Security Essentials
 *	
 *	Copyright 2020-2021 Mark Stephen Sobkow
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
 *	Please contact Mark Stephen Sobkow at mark.sobkow@gmail.com for commercial licensing.
 *
 *	Manufactured by MSS Code Factory 2.12
 */

#include <cflib/ICFLibPublic.hpp>

using namespace std;

#include <cfsec/ICFSecPublic.hpp>
#include <cfsecobj/ICFSecObjPublic.hpp>

#include <cfsecobj/CFSecClusterObj.hpp>
#include <cfsecobj/CFSecHostNodeObj.hpp>
#include <cfsecobj/CFSecISOCcyObj.hpp>
#include <cfsecobj/CFSecISOCtryObj.hpp>
#include <cfsecobj/CFSecISOCtryCcyObj.hpp>
#include <cfsecobj/CFSecISOCtryLangObj.hpp>
#include <cfsecobj/CFSecISOLangObj.hpp>
#include <cfsecobj/CFSecISOTZoneObj.hpp>
#include <cfsecobj/CFSecSecAppObj.hpp>
#include <cfsecobj/CFSecSecDeviceObj.hpp>
#include <cfsecobj/CFSecSecFormObj.hpp>
#include <cfsecobj/CFSecSecGroupObj.hpp>
#include <cfsecobj/CFSecSecGroupFormObj.hpp>
#include <cfsecobj/CFSecSecGrpIncObj.hpp>
#include <cfsecobj/CFSecSecGrpMembObj.hpp>
#include <cfsecobj/CFSecSecSessionObj.hpp>
#include <cfsecobj/CFSecSecUserObj.hpp>
#include <cfsecobj/CFSecServiceObj.hpp>
#include <cfsecobj/CFSecServiceTypeObj.hpp>
#include <cfsecobj/CFSecSysClusterObj.hpp>
#include <cfsecobj/CFSecTSecGroupObj.hpp>
#include <cfsecobj/CFSecTSecGrpIncObj.hpp>
#include <cfsecobj/CFSecTSecGrpMembObj.hpp>
#include <cfsecobj/CFSecTenantObj.hpp>

#include <cfsecobj/CFSecClusterEditObj.hpp>
#include <cfsecobj/CFSecHostNodeEditObj.hpp>
#include <cfsecobj/CFSecISOCcyEditObj.hpp>
#include <cfsecobj/CFSecISOCtryEditObj.hpp>
#include <cfsecobj/CFSecISOCtryCcyEditObj.hpp>
#include <cfsecobj/CFSecISOCtryLangEditObj.hpp>
#include <cfsecobj/CFSecISOLangEditObj.hpp>
#include <cfsecobj/CFSecISOTZoneEditObj.hpp>
#include <cfsecobj/CFSecSecAppEditObj.hpp>
#include <cfsecobj/CFSecSecDeviceEditObj.hpp>
#include <cfsecobj/CFSecSecFormEditObj.hpp>
#include <cfsecobj/CFSecSecGroupEditObj.hpp>
#include <cfsecobj/CFSecSecGroupFormEditObj.hpp>
#include <cfsecobj/CFSecSecGrpIncEditObj.hpp>
#include <cfsecobj/CFSecSecGrpMembEditObj.hpp>
#include <cfsecobj/CFSecSecSessionEditObj.hpp>
#include <cfsecobj/CFSecSecUserEditObj.hpp>
#include <cfsecobj/CFSecServiceEditObj.hpp>
#include <cfsecobj/CFSecServiceTypeEditObj.hpp>
#include <cfsecobj/CFSecSysClusterEditObj.hpp>
#include <cfsecobj/CFSecTSecGroupEditObj.hpp>
#include <cfsecobj/CFSecTSecGrpIncEditObj.hpp>
#include <cfsecobj/CFSecTSecGrpMembEditObj.hpp>
#include <cfsecobj/CFSecTenantEditObj.hpp>

#include <cfsecobj/CFSecClusterTableObj.hpp>
#include <cfsecobj/CFSecHostNodeTableObj.hpp>
#include <cfsecobj/CFSecISOCcyTableObj.hpp>
#include <cfsecobj/CFSecISOCtryTableObj.hpp>
#include <cfsecobj/CFSecISOCtryCcyTableObj.hpp>
#include <cfsecobj/CFSecISOCtryLangTableObj.hpp>
#include <cfsecobj/CFSecISOLangTableObj.hpp>
#include <cfsecobj/CFSecISOTZoneTableObj.hpp>
#include <cfsecobj/CFSecSecAppTableObj.hpp>
#include <cfsecobj/CFSecSecDeviceTableObj.hpp>
#include <cfsecobj/CFSecSecFormTableObj.hpp>
#include <cfsecobj/CFSecSecGroupTableObj.hpp>
#include <cfsecobj/CFSecSecGroupFormTableObj.hpp>
#include <cfsecobj/CFSecSecGrpIncTableObj.hpp>
#include <cfsecobj/CFSecSecGrpMembTableObj.hpp>
#include <cfsecobj/CFSecSecSessionTableObj.hpp>
#include <cfsecobj/CFSecSecUserTableObj.hpp>
#include <cfsecobj/CFSecServiceTableObj.hpp>
#include <cfsecobj/CFSecServiceTypeTableObj.hpp>
#include <cfsecobj/CFSecSysClusterTableObj.hpp>
#include <cfsecobj/CFSecTSecGroupTableObj.hpp>
#include <cfsecobj/CFSecTSecGrpIncTableObj.hpp>
#include <cfsecobj/CFSecTSecGrpMembTableObj.hpp>
#include <cfsecobj/CFSecTenantTableObj.hpp>

namespace cfsec {

	const std::string CFSecSysClusterTableObj::CLASS_NAME( "CFSecSysClusterTableObj" );
	const std::string CFSecSysClusterTableObj::TABLE_NAME( "SysCluster" );
	const std::string CFSecSysClusterTableObj::TABLE_DBNAME( "sysclus" );

	CFSecSysClusterTableObj::CFSecSysClusterTableObj() {
		schema = NULL;
		members = new std::map<cfsec::CFSecSysClusterPKey, cfsec::ICFSecSysClusterObj*>();
		allSysCluster = NULL;
		indexByClusterIdx = new std::map< cfsec::CFSecSysClusterByClusterIdxKey,
			std::map< cfsec::CFSecSysClusterPKey, cfsec::ICFSecSysClusterObj*>*>();
	}

	CFSecSysClusterTableObj::CFSecSysClusterTableObj( cfsec::ICFSecSchemaObj* argSchema ) {
		schema = dynamic_cast<cfsec::ICFSecSchemaObj*>( argSchema );
		members = new std::map<cfsec::CFSecSysClusterPKey, cfsec::ICFSecSysClusterObj*>();
		allSysCluster = NULL;
		indexByClusterIdx = new std::map< cfsec::CFSecSysClusterByClusterIdxKey,
			std::map< cfsec::CFSecSysClusterPKey, cfsec::ICFSecSysClusterObj*>*>();
	}

	CFSecSysClusterTableObj::~CFSecSysClusterTableObj() {
		minimizeMemory();
		if( indexByClusterIdx != NULL ) {
			delete indexByClusterIdx;
			indexByClusterIdx = NULL;
		}
		if( members != NULL ) {
			cfsec::ICFSecSysClusterObj* curMember;
			auto membersIter = members->begin();
			while( membersIter != members->end() ) {
				curMember = membersIter->second;
				if( curMember != NULL ) {
					delete curMember;
				}
				members->erase( membersIter );
				membersIter = members->begin();
			}
			delete members;
			members = NULL;
		}
	}

	cfsec::ICFSecSchemaObj* CFSecSysClusterTableObj::getSchema() {
		return( schema );
	}

	void CFSecSysClusterTableObj::setSchema( cfsec::ICFSecSchemaObj* value ) {
		schema = dynamic_cast<cfsec::ICFSecSchemaObj*>( value );
	}

	const std::string CFSecSysClusterTableObj::getTableName() {
		return( TABLE_NAME );
	}

	const std::string CFSecSysClusterTableObj::getTableDbName() {
		return( TABLE_DBNAME );
	}
	const classcode_t* CFSecSysClusterTableObj::getObjQualifyingClassCode() {
		return( NULL );
	}


	void CFSecSysClusterTableObj::minimizeMemory() {
		if( allSysCluster != NULL ) {
			allSysCluster->clear();
			delete allSysCluster;
			allSysCluster = NULL;
		}
		if( indexByClusterIdx != NULL ) {
			std::map< cfsec::CFSecSysClusterByClusterIdxKey,
				std::map< cfsec::CFSecSysClusterPKey, cfsec::ICFSecSysClusterObj*>* >::iterator iterByClusterIdx = indexByClusterIdx->begin();
			std::map< cfsec::CFSecSysClusterByClusterIdxKey,
				std::map< cfsec::CFSecSysClusterPKey, cfsec::ICFSecSysClusterObj*>* >::iterator endByClusterIdx = indexByClusterIdx->end();
			std::map< cfsec::CFSecSysClusterPKey, cfsec::ICFSecSysClusterObj*>* curByClusterIdx = NULL;
			while( iterByClusterIdx != endByClusterIdx ) {
				curByClusterIdx = iterByClusterIdx->second;
				if( curByClusterIdx != NULL ) {
					curByClusterIdx->clear();
					delete curByClusterIdx;
					curByClusterIdx = NULL;
					iterByClusterIdx->second = NULL;
				}
				iterByClusterIdx ++;
			}
			indexByClusterIdx->clear();
		}
		if( members != NULL ) {
			cfsec::ICFSecSysClusterObj* cur = NULL;
			cfsec::ICFSecSysClusterEditObj* edit = NULL;
			auto iter = members->begin();
			auto end = members->end();
			while( iter != end ) {
				cur = iter->second;
				if( cur != NULL ) {
					iter->second = NULL;
					edit = cur->getEdit();
					if( edit != NULL ) {
						edit->endEdit();
						edit = NULL;
					}
					delete cur;
					cur = NULL;
				}
				iter ++;
			}
			members->clear();
		}
	}

	cfsec::ICFSecSysClusterObj* CFSecSysClusterTableObj::newInstance() {
		cfsec::ICFSecSysClusterObj* inst = dynamic_cast<cfsec::ICFSecSysClusterObj*>( new CFSecSysClusterObj( schema ) );
		return( inst );
	}

	cfsec::ICFSecSysClusterEditObj* CFSecSysClusterTableObj::newEditInstance( cfsec::ICFSecSysClusterObj* orig ) {
		cfsec::ICFSecSysClusterEditObj* edit = dynamic_cast<cfsec::ICFSecSysClusterEditObj*>( new CFSecSysClusterEditObj( orig ));
		return( edit );
	}

	cfsec::ICFSecSysClusterObj* CFSecSysClusterTableObj::realizeSysCluster( cfsec::ICFSecSysClusterObj* Obj ) {
		static const std::string S_ProcName( "realizeSysCluster" );
		static const std::string S_ExistingObj( "existingObj" );
		static const std::string S_KeepObj( "keepObj" );
		static const std::string S_Obj( "Obj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfsec::ICFSecSysClusterObj* obj = Obj;
		cfsec::ICFSecSysClusterObj* existingObj = NULL;
		cfsec::CFSecSysClusterPKey* pkey = obj->getPKey();
		cfsec::ICFSecSysClusterObj* keepObj = NULL;
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			existingObj = searchMembers->second;
			if( existingObj == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_ExistingObj );
			}
			keepObj = existingObj;
			pkey = keepObj->getPKey();
			/*
			 *	We always rebind the data because if we're being called, some index may have been
			 *	updated and is refreshing it's data, which may require binding a different lookup key
			 */
			// Detach object from alternate and duplicate indexes, leave PKey alone
			if( indexByClusterIdx != NULL ) {
				cfsec::CFSecSysClusterByClusterIdxKey keyClusterIdx;
				keyClusterIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				auto searchClusterIdx = indexByClusterIdx->find( keyClusterIdx );
				if( searchClusterIdx != indexByClusterIdx->end() ) {
					std::map<cfsec::CFSecSysClusterPKey, cfsec::ICFSecSysClusterObj*>* mapClusterIdx = searchClusterIdx->second;
					if( mapClusterIdx != NULL ) {
						auto removalProbe = mapClusterIdx->find( *(keepObj->getPKey()) );
						if( removalProbe != mapClusterIdx->end() ) {
							mapClusterIdx->erase( removalProbe );
						}
					}
				}
			}

			keepObj->setBuff( dynamic_cast<cfsec::CFSecSysClusterBuff*>( Obj->getBuff()->clone() ) );
			// Attach new object to alternate and duplicate indexes -- PKey stays stable

			if( indexByClusterIdx != NULL ) {
				static const std::string S_AClusterIdxObj( "aClusterIdxObj" );
				cfsec::ICFSecSysClusterObj* aClusterIdxObj =
					dynamic_cast<cfsec::ICFSecSysClusterObj*>( keepObj );
				if( aClusterIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AClusterIdxObj );
				}
				cfsec::CFSecSysClusterByClusterIdxKey keyClusterIdx;
				keyClusterIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				auto searchIndexByClusterIdx = indexByClusterIdx->find( keyClusterIdx );
				if( searchIndexByClusterIdx != indexByClusterIdx->end() ) {
					std::map<cfsec::CFSecSysClusterPKey, cfsec::ICFSecSysClusterObj*>* mapClusterIdx = searchIndexByClusterIdx->second;
					if( mapClusterIdx != NULL ) {
						mapClusterIdx->insert( std::map< cfsec::CFSecSysClusterPKey, cfsec::ICFSecSysClusterObj* >::value_type( *(keepObj->getPKey()), aClusterIdxObj ) );
					}
				}
			}

			if( allSysCluster != NULL ) {
				allSysCluster->insert( std::map< cfsec::CFSecSysClusterPKey, cfsec::ICFSecSysClusterObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			}
		}
		else {
			keepObj = obj;
			keepObj->setIsNew( false );
			pkey = keepObj->getPKey();
			// Attach new object to PKey, all, alternate, and duplicate indexes
			members->insert( std::map< cfsec::CFSecSysClusterPKey, cfsec::ICFSecSysClusterObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			// Attach new object to alternate and duplicate indexes -- PKey stay stable

			if( indexByClusterIdx != NULL ) {
				static const std::string S_AClusterIdxObj( "aClusterIdxObj" );
				cfsec::ICFSecSysClusterObj* aClusterIdxObj =
					dynamic_cast<cfsec::ICFSecSysClusterObj*>( keepObj );
				if( aClusterIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AClusterIdxObj );
				}
				cfsec::CFSecSysClusterByClusterIdxKey keyClusterIdx;
				keyClusterIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				auto searchIndexByClusterIdx = indexByClusterIdx->find( keyClusterIdx );
				if( searchIndexByClusterIdx != indexByClusterIdx->end() ) {
					std::map<cfsec::CFSecSysClusterPKey, cfsec::ICFSecSysClusterObj*>* mapClusterIdx = searchIndexByClusterIdx->second;
					if( mapClusterIdx != NULL ) {
						mapClusterIdx->insert( std::map< cfsec::CFSecSysClusterPKey, cfsec::ICFSecSysClusterObj* >::value_type( *(keepObj->getPKey()), aClusterIdxObj ) );
					}
				}
			}

			if( allSysCluster != NULL ) {
				allSysCluster->insert( std::map< cfsec::CFSecSysClusterPKey, cfsec::ICFSecSysClusterObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			}
		}
		if( keepObj != obj ) {
			delete obj;
			obj = NULL;
		}
		// Something is leaking, so I've added this paranoid check
		if( ( keepObj != existingObj ) && ( existingObj != NULL ) ) {
			delete existingObj;
			existingObj = NULL;
		}
		return( keepObj );
	}

	void CFSecSysClusterTableObj::deepDisposeByIdIdx( const int32_t SingletonId ) {
		static const std::string S_ProcName( "deepDisposeByIdIdx" );
		std::vector<cfsec::ICFSecSysClusterObj*> list;
		cfsec::ICFSecSysClusterObj* existingObj = readCachedSysClusterByIdIdx( SingletonId );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfsec::ICFSecSysClusterObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecSysClusterBuff::CLASS_CODE ) {
					dynamic_cast<cfsec::CFSecSysClusterTableObj*>( schema->getSysClusterTableObj() )->reallyDeepDisposeSysCluster( dynamic_cast<cfsec::ICFSecSysClusterObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFSecSysClusterTableObj::deepDisposeByClusterIdx( const int64_t ClusterId ) {
		static const std::string S_ProcName( "deepDisposeByClusterIdx" );
		std::vector<cfsec::ICFSecSysClusterObj*> list;
		std::vector<cfsec::ICFSecSysClusterObj*> matchesFound = readCachedSysClusterByClusterIdx( ClusterId );
		auto iterMatches = matchesFound.begin();
		auto endMatches = matchesFound.end();
		while( iterMatches != endMatches ) {
			if( *iterMatches != NULL ) {
				list.push_back( *iterMatches );
			}
			iterMatches ++;
		}
		cfsec::ICFSecSysClusterObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecSysClusterBuff::CLASS_CODE ) {
					dynamic_cast<cfsec::CFSecSysClusterTableObj*>( schema->getSysClusterTableObj() )->reallyDeepDisposeSysCluster( dynamic_cast<cfsec::ICFSecSysClusterObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFSecSysClusterTableObj::reallyDeepDisposeSysCluster( cfsec::ICFSecSysClusterObj* Obj ) {
		static const std::string S_ProcName( "reallyDeepDisposeSysCluster" );

		if( Obj == NULL ) {
			return;
		}

		cfsec::ICFSecSysClusterObj* obj = Obj;
		
		classcode_t classCode = obj->getClassCode();
		if( classCode == cfsec::CFSecSysClusterBuff::CLASS_CODE ) {
			dynamic_cast<cfsec::CFSecSysClusterTableObj*>( schema->getSysClusterTableObj() )->reallyDetachFromIndexesSysCluster( dynamic_cast<cfsec::ICFSecSysClusterObj*>( obj ) );
		}

		if( obj->getEdit() != NULL ) {
			obj->endEdit();
		}
		delete obj;
		obj = NULL;
	}

	cfsec::ICFSecSysClusterObj* CFSecSysClusterTableObj::createSysCluster( cfsec::ICFSecSysClusterEditObj* Obj ) {
		static const std::string S_ProcName( "createSysCluster" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Cloneable( "cloneable" );
		static const std::string S_ClonedBuff( "clonedbuff" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecSysClusterObj* obj = dynamic_cast<cfsec::ICFSecSysClusterObj*>( Obj->getOrig() );
		try {
			cfsec::CFSecSysClusterBuff* buff = dynamic_cast<cfsec::CFSecSysClusterBuff*>( Obj->getBuff()->clone() );
			// C++18 version of create returns a new buffer instance and takes over ownership of the passed-in buffer
			// MSS TODO WORKING The xmsg client will need to return the buffer instance created by processing
			// the response message, while xmsg rqst will have to delete the backing store instance
			// it receives after preparing the reply message so that memory doesn't leak on every request.
			cflib::ICFLibCloneableObj* cloneable = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSysCluster()->createSysCluster(
				schema->getAuthorization(),
				buff );
			if( cloneable == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Cloneable );
			}
			Obj->endEdit();
			obj->setBuff( dynamic_cast<cfsec::CFSecSysClusterBuff*>( cloneable ) );
			obj = dynamic_cast<cfsec::ICFSecSysClusterObj*>( obj->realize() );
			if( obj == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Obj );
			}
		}
		CFLIB_EXCEPTION_CATCH_FALLTHROUGH
		if( ! CFLIB_EXCEPTION_EMPTY ) {
			if( obj->getEdit() != NULL ) {
				obj->endEdit();
			}
			if( obj->getIsNew() ) {
				delete obj;
				obj = NULL;
			}
			CFLIB_EXCEPTION_RETHROW_CFLIBEXCEPTION
		}
		return( obj );
	}

	cfsec::ICFSecSysClusterObj* CFSecSysClusterTableObj::readSysCluster( cfsec::CFSecSysClusterPKey* pkey, bool forceRead ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readSysCluster" );
		cfsec::ICFSecSysClusterObj* obj = NULL;
		cfsec::ICFSecSysClusterObj* realized = NULL;
		if( ! forceRead ) {
			auto searchMembers = members->find( *pkey );
			if( searchMembers != members->end() ) {
				// obj could be NULL if cache misses is enabled
				obj = searchMembers->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecSysClusterBuff* readBuff = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSysCluster()->readDerivedByIdIdx( schema->getAuthorization(),
			pkey->getRequiredSingletonId() );
			if( readBuff != NULL ) {
			obj = dynamic_cast<cfsec::CFSecSysClusterTableObj*>( schema->getSysClusterTableObj() )->newInstance();
				obj->setBuff( readBuff );
				realized = dynamic_cast<cfsec::ICFSecSysClusterObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = NULL;
			}
		}
		return( realized );
	}

	cfsec::ICFSecSysClusterObj* CFSecSysClusterTableObj::lockSysCluster( cfsec::CFSecSysClusterPKey* pkey ) {
		static const std::string S_ProcName( "lockSysCluster" );
		cfsec::ICFSecSysClusterObj* locked = NULL;
		cfsec::CFSecSysClusterBuff* lockBuff = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSysCluster()->lockDerived( schema->getAuthorization(), pkey );
		if( lockBuff != NULL ) {
			locked = dynamic_cast<cfsec::CFSecSysClusterTableObj*>( schema->getSysClusterTableObj() )->newInstance();
			locked->setBuff( lockBuff );
			locked = dynamic_cast<cfsec::ICFSecSysClusterObj*>( locked->realize() );
		}
		else {
			return( NULL );
		}
		return( locked );
	}

	std::vector<cfsec::ICFSecSysClusterObj*> CFSecSysClusterTableObj::readAllSysCluster( bool forceRead ) {
		static const std::string S_ProcName( "readAllSysCluster" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Realized( "realized" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecSysClusterObj* realized = NULL;
		if( forceRead || ( allSysCluster == NULL ) ) {
			std::map<cfsec::CFSecSysClusterPKey, cfsec::ICFSecSysClusterObj*>* map = new std::map<cfsec::CFSecSysClusterPKey,cfsec::ICFSecSysClusterObj*>();
			allSysCluster = map;
			std::TCFLibOwningVector<cfsec::CFSecSysClusterBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSysCluster()->readAllDerived( schema->getAuthorization() );
			cfsec::CFSecSysClusterBuff* buff = NULL;
			cfsec::ICFSecSysClusterObj* obj = NULL;
			try {
				for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
					buff = buffList[ idx ];
					buffList[ idx ] = NULL;
				obj = newInstance();
					obj->setBuff( buff );
					realized = dynamic_cast<cfsec::ICFSecSysClusterObj*>( obj->realize() );
					if( realized == NULL ) {
						throw cflib::CFLibNullArgumentException( CLASS_NAME,
							S_ProcName,
							0,
							S_Realized );
					}
					allSysCluster->insert( std::map< cfsec::CFSecSysClusterPKey, cfsec::ICFSecSysClusterObj* >::value_type( *(realized->getPKey()), realized ) );
					// No need to delete obj -- realize() auto-destructs the instance it decided to discard
					obj = NULL;
				}
			}
			CFLIB_EXCEPTION_CATCH_FALLTHROUGH

			if( ( obj != NULL ) && obj->getIsNew() ) {
				delete obj;
				obj = NULL;
			}

			CFLIB_EXCEPTION_RETHROW_CFLIBEXCEPTION

		}
		size_t len = allSysCluster->size();
		std::vector<cfsec::ICFSecSysClusterObj*> arr;
		auto valIter = allSysCluster->begin();
		size_t idx = 0;
		while( valIter != allSysCluster->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	cfsec::ICFSecSysClusterObj* CFSecSysClusterTableObj::readSysClusterByIdIdx( const int32_t SingletonId, bool forceRead )
	{
		static const std::string S_ProcName( "readSysClusterByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSysClusterPKey pkey;
		pkey.setRequiredSingletonId( SingletonId );
		cfsec::ICFSecSysClusterObj* obj = readSysCluster( &pkey, forceRead );
		return( obj );
	}

	std::vector<cfsec::ICFSecSysClusterObj*> CFSecSysClusterTableObj::readSysClusterByClusterIdx( const int64_t ClusterId,
		bool forceRead )
	{
		static const std::string S_ProcName( "readSysClusterByClusterIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSysClusterByClusterIdxKey key;
		key.setRequiredClusterId( ClusterId );
		std::map<cfsec::CFSecSysClusterPKey, cfsec::ICFSecSysClusterObj*>* dict;
		std::map<cfsec::CFSecSysClusterPKey, cfsec::ICFSecSysClusterObj*>* oldDict;
		if( indexByClusterIdx == NULL ) {
			indexByClusterIdx = new std::map< cfsec::CFSecSysClusterByClusterIdxKey,
				std::map< cfsec::CFSecSysClusterPKey, cfsec::ICFSecSysClusterObj*>*>();
		}
		auto searchIndexByClusterIdx = indexByClusterIdx->find( key );
		if( searchIndexByClusterIdx != indexByClusterIdx->end() ) {
			oldDict = searchIndexByClusterIdx->second;
		}
		else {
			oldDict = NULL;
		}
		if( ( oldDict != NULL ) && ( ! forceRead ) ) {
			dict = oldDict;
		}
		else {
			dict = new std::map<cfsec::CFSecSysClusterPKey, cfsec::ICFSecSysClusterObj*>();
			cfsec::ICFSecSysClusterObj* obj;
			std::TCFLibOwningVector<cfsec::CFSecSysClusterBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSysCluster()->readDerivedByClusterIdx( schema->getAuthorization(),
				ClusterId );
			cfsec::CFSecSysClusterBuff* buff;
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = dynamic_cast<cfsec::CFSecSysClusterTableObj*>( schema->getSysClusterTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
				obj->setBuff( buff );
				cfsec::ICFSecSysClusterObj* realized = dynamic_cast<cfsec::ICFSecSysClusterObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				dict->insert( std::map< cfsec::CFSecSysClusterPKey, cfsec::ICFSecSysClusterObj* >::value_type( *(realized->getPKey()), realized ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = NULL;
			}
			if( oldDict != NULL ) {
				indexByClusterIdx->erase( searchIndexByClusterIdx );
				delete oldDict;
				oldDict = NULL;
			}
			indexByClusterIdx->insert( std::map< cfsec::CFSecSysClusterByClusterIdxKey,
				std::map< cfsec::CFSecSysClusterPKey, cfsec::ICFSecSysClusterObj* >* >::value_type( key, dict ) );
		}
		size_t len = dict->size();
		std::vector<cfsec::ICFSecSysClusterObj*> arr;
		arr.reserve( len );
		auto valIter = dict->begin();
		while( valIter != dict->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	cfsec::ICFSecSysClusterObj* CFSecSysClusterTableObj::readCachedSysCluster( cfsec::CFSecSysClusterPKey* pkey ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readSysCluster" );
		cfsec::ICFSecSysClusterObj* obj = NULL;
		cfsec::ICFSecSysClusterObj* realized = NULL;
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			// obj could be NULL if cache misses is enabled
			obj = searchMembers->second;
			realized = obj;
		}
		return( realized );
	}

	cfsec::ICFSecSysClusterObj* CFSecSysClusterTableObj::readCachedSysClusterByIdIdx( const int32_t SingletonId )
	{
		static const std::string S_ProcName( "readCachedSysClusterByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSysClusterPKey pkey;
		pkey.setRequiredSingletonId( SingletonId );
		cfsec::ICFSecSysClusterObj* obj = readCachedSysCluster( &pkey );
		return( obj );
	}

	std::vector<cfsec::ICFSecSysClusterObj*> CFSecSysClusterTableObj::readCachedSysClusterByClusterIdx( const int64_t ClusterId )
	{
		static const std::string S_ProcName( "readCachedSysClusterByClusterIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		std::vector<cfsec::ICFSecSysClusterObj*> arr;
		cfsec::CFSecSysClusterByClusterIdxKey key;
		key.setRequiredClusterId( ClusterId );
		std::map<cfsec::CFSecSysClusterPKey, cfsec::ICFSecSysClusterObj*>* dict;
		if( indexByClusterIdx == NULL ) {
			return( arr );
		}
		auto searchIndexByClusterIdx = indexByClusterIdx->find( key );
		if( searchIndexByClusterIdx != indexByClusterIdx->end() ) {
			dict = searchIndexByClusterIdx->second;
			size_t len = dict->size();
			std::vector<cfsec::ICFSecSysClusterObj*> arr;
			arr.reserve( len );
			auto valIter = dict->begin();
			while( valIter != dict->end() ) {
				arr.push_back( valIter->second );
				valIter ++;
			}
		}
		else {
			cfsec::ICFSecSysClusterObj* obj;
			for( auto iterMembers = members->begin(); iterMembers != members->end(); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecSysClusterBuff*>( obj->getBuff() ) ) == key ) {
						arr.push_back( obj );
					}
				}
			}
		}
		return( arr );
	}

	cfsec::ICFSecSysClusterObj* CFSecSysClusterTableObj::updateSysCluster( cfsec::ICFSecSysClusterEditObj* Obj ) {
		static const std::string S_ProcName( "updateSysCluster" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Updated( "updated" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecSysClusterObj* obj = dynamic_cast<cfsec::ICFSecSysClusterObj*>( Obj->getOrig() );
		try {
			cfsec::CFSecSysClusterBuff* updated = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSysCluster()->updateSysCluster( schema->getAuthorization(),
				dynamic_cast<cfsec::CFSecSysClusterBuff*>( Obj->getSysClusterBuff()->clone() ) );
			if( updated == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Updated );
			}
			obj = dynamic_cast<cfsec::ICFSecSysClusterObj*>( dynamic_cast<cfsec::CFSecSysClusterTableObj*>( schema->getSysClusterTableObj() )->newInstance() );
			obj->setBuff( updated );
			obj = dynamic_cast<cfsec::ICFSecSysClusterObj*>( obj->realize() );
			if( obj == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Obj );
			}
			if( obj->getEdit() != NULL ) {
				obj->endEdit();
			}
		}
		CFLIB_EXCEPTION_CATCH_FALLTHROUGH
		if( ! CFLIB_EXCEPTION_EMPTY ) {
			if( obj->getEdit() != NULL ) {
				obj->endEdit();
			}
			CFLIB_EXCEPTION_RETHROW_CFLIBEXCEPTION
		}
		return( obj );
	}

	void CFSecSysClusterTableObj::deleteSysCluster( cfsec::ICFSecSysClusterEditObj* Obj ) {
		cfsec::ICFSecSysClusterObj* obj = Obj;
		dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSysCluster()->deleteSysCluster( schema->getAuthorization(),
			obj->getSysClusterBuff() );
		deepDisposeByIdIdx( obj->getRequiredSingletonId() );
	}

	void CFSecSysClusterTableObj::deleteSysClusterByIdIdx( const int32_t SingletonId )
	{
		cfsec::CFSecSysClusterPKey pkey;
		pkey.setRequiredSingletonId( SingletonId );
		cfsec::ICFSecSysClusterObj* obj = readSysCluster( &pkey, true );
		if( obj != NULL ) {
			cfsec::ICFSecSysClusterEditObj* editObj = dynamic_cast<cfsec::ICFSecSysClusterEditObj*>( obj->getEdit() );
			if( editObj == NULL ) {
				editObj = dynamic_cast<cfsec::ICFSecSysClusterEditObj*>( obj->beginEdit() );
			}
			if( editObj != NULL ) {
				editObj->deleteInstance();
				editObj = NULL;
			}
		}
	}

	void CFSecSysClusterTableObj::deleteSysClusterByClusterIdx( const int64_t ClusterId )
	{
		dynamic_cast<cfsec::ICFSecSchema*>( schema->getBackingStore() )->getTableSysCluster()->deleteSysClusterByClusterIdx( schema->getAuthorization(),
				ClusterId );
		deepDisposeByClusterIdx( ClusterId );
	}

	void CFSecSysClusterTableObj::reallyDetachFromIndexesSysCluster( cfsec::ICFSecSysClusterObj* Obj ) {
		static const std::string S_ProcName( "reallyDetachFromIndexesSysCluster" );
		static const std::string S_Obj( "Obj" );
		static const std::string S_ExistingObj( "ExistingObj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfsec::ICFSecSysClusterObj* obj = Obj;
		cfsec::CFSecSysClusterPKey* pkey = obj->getPKey();
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			cfsec::ICFSecSysClusterObj* existingObj = searchMembers->second;
			if( existingObj == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_ExistingObj );
			}
			if( indexByClusterIdx != NULL ) {
				cfsec::CFSecSysClusterByClusterIdxKey keyClusterIdx;
				keyClusterIdx.setRequiredClusterId( obj->getRequiredClusterId() );
				auto searchClusterIdx = indexByClusterIdx->find( keyClusterIdx );
				if( searchClusterIdx != indexByClusterIdx->end() ) {
					std::map<cfsec::CFSecSysClusterPKey, cfsec::ICFSecSysClusterObj*>* mapClusterIdx = searchClusterIdx->second;
					if( mapClusterIdx != NULL ) {
						auto removalProbe = mapClusterIdx->find( *(obj->getPKey()) );
						if( removalProbe != mapClusterIdx->end() ) {
							mapClusterIdx->erase( removalProbe );
							if( mapClusterIdx->empty() ) {
								delete mapClusterIdx;
								mapClusterIdx = NULL;
								indexByClusterIdx->erase( searchClusterIdx );
							}
						}
					}
				}
			}

			members->erase( searchMembers );
		}
	}


}
