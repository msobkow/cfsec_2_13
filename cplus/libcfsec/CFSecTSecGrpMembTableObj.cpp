// Description: C++18 Table Object implementation for CFSec.

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

	const std::string CFSecTSecGrpMembTableObj::CLASS_NAME( "CFSecTSecGrpMembTableObj" );
	const std::string CFSecTSecGrpMembTableObj::TABLE_NAME( "TSecGrpMemb" );
	const std::string CFSecTSecGrpMembTableObj::TABLE_DBNAME( "TSecMemb" );

	CFSecTSecGrpMembTableObj::CFSecTSecGrpMembTableObj() {
		schema = NULL;
		members = new std::map<cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj*>();
		allTSecGrpMemb = NULL;
		indexByTenantIdx = new std::map< cfsec::CFSecTSecGrpMembByTenantIdxKey,
			std::map< cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj*>*>();
		indexByGroupIdx = new std::map< cfsec::CFSecTSecGrpMembByGroupIdxKey,
			std::map< cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj*>*>();
		indexByUserIdx = new std::map< cfsec::CFSecTSecGrpMembByUserIdxKey,
			std::map< cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj*>*>();
		indexByUUserIdx = new std::map< cfsec::CFSecTSecGrpMembByUUserIdxKey,
			cfsec::ICFSecTSecGrpMembObj*>();
	}

	CFSecTSecGrpMembTableObj::CFSecTSecGrpMembTableObj( cfsec::ICFSecSchemaObj* argSchema ) {
		schema = dynamic_cast<cfsec::ICFSecSchemaObj*>( argSchema );
		members = new std::map<cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj*>();
		allTSecGrpMemb = NULL;
		indexByTenantIdx = new std::map< cfsec::CFSecTSecGrpMembByTenantIdxKey,
			std::map< cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj*>*>();
		indexByGroupIdx = new std::map< cfsec::CFSecTSecGrpMembByGroupIdxKey,
			std::map< cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj*>*>();
		indexByUserIdx = new std::map< cfsec::CFSecTSecGrpMembByUserIdxKey,
			std::map< cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj*>*>();
		indexByUUserIdx = new std::map< cfsec::CFSecTSecGrpMembByUUserIdxKey,
			cfsec::ICFSecTSecGrpMembObj*>();
	}

	CFSecTSecGrpMembTableObj::~CFSecTSecGrpMembTableObj() {
		minimizeMemory();
		if( indexByTenantIdx != NULL ) {
			delete indexByTenantIdx;
			indexByTenantIdx = NULL;
		}
		if( indexByGroupIdx != NULL ) {
			delete indexByGroupIdx;
			indexByGroupIdx = NULL;
		}
		if( indexByUserIdx != NULL ) {
			delete indexByUserIdx;
			indexByUserIdx = NULL;
		}
		if( indexByUUserIdx != NULL ) {
			delete indexByUUserIdx;
			indexByUUserIdx = NULL;
		}
		if( members != NULL ) {
			cfsec::ICFSecTSecGrpMembObj* curMember;
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

	cfsec::ICFSecSchemaObj* CFSecTSecGrpMembTableObj::getSchema() {
		return( schema );
	}

	void CFSecTSecGrpMembTableObj::setSchema( cfsec::ICFSecSchemaObj* value ) {
		schema = dynamic_cast<cfsec::ICFSecSchemaObj*>( value );
	}

	const std::string CFSecTSecGrpMembTableObj::getTableName() {
		return( TABLE_NAME );
	}

	const std::string CFSecTSecGrpMembTableObj::getTableDbName() {
		return( TABLE_DBNAME );
	}
	const classcode_t* CFSecTSecGrpMembTableObj::getObjQualifyingClassCode() {
		return( NULL );
	}


	void CFSecTSecGrpMembTableObj::minimizeMemory() {
		if( allTSecGrpMemb != NULL ) {
			allTSecGrpMemb->clear();
			delete allTSecGrpMemb;
			allTSecGrpMemb = NULL;
		}
		if( indexByTenantIdx != NULL ) {
			std::map< cfsec::CFSecTSecGrpMembByTenantIdxKey,
				std::map< cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj*>* >::iterator iterByTenantIdx = indexByTenantIdx->begin();
			std::map< cfsec::CFSecTSecGrpMembByTenantIdxKey,
				std::map< cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj*>* >::iterator endByTenantIdx = indexByTenantIdx->end();
			std::map< cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj*>* curByTenantIdx = NULL;
			while( iterByTenantIdx != endByTenantIdx ) {
				curByTenantIdx = iterByTenantIdx->second;
				if( curByTenantIdx != NULL ) {
					curByTenantIdx->clear();
					delete curByTenantIdx;
					curByTenantIdx = NULL;
					iterByTenantIdx->second = NULL;
				}
				iterByTenantIdx ++;
			}
			indexByTenantIdx->clear();
		}
		if( indexByGroupIdx != NULL ) {
			std::map< cfsec::CFSecTSecGrpMembByGroupIdxKey,
				std::map< cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj*>* >::iterator iterByGroupIdx = indexByGroupIdx->begin();
			std::map< cfsec::CFSecTSecGrpMembByGroupIdxKey,
				std::map< cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj*>* >::iterator endByGroupIdx = indexByGroupIdx->end();
			std::map< cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj*>* curByGroupIdx = NULL;
			while( iterByGroupIdx != endByGroupIdx ) {
				curByGroupIdx = iterByGroupIdx->second;
				if( curByGroupIdx != NULL ) {
					curByGroupIdx->clear();
					delete curByGroupIdx;
					curByGroupIdx = NULL;
					iterByGroupIdx->second = NULL;
				}
				iterByGroupIdx ++;
			}
			indexByGroupIdx->clear();
		}
		if( indexByUserIdx != NULL ) {
			std::map< cfsec::CFSecTSecGrpMembByUserIdxKey,
				std::map< cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj*>* >::iterator iterByUserIdx = indexByUserIdx->begin();
			std::map< cfsec::CFSecTSecGrpMembByUserIdxKey,
				std::map< cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj*>* >::iterator endByUserIdx = indexByUserIdx->end();
			std::map< cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj*>* curByUserIdx = NULL;
			while( iterByUserIdx != endByUserIdx ) {
				curByUserIdx = iterByUserIdx->second;
				if( curByUserIdx != NULL ) {
					curByUserIdx->clear();
					delete curByUserIdx;
					curByUserIdx = NULL;
					iterByUserIdx->second = NULL;
				}
				iterByUserIdx ++;
			}
			indexByUserIdx->clear();
		}
		if( indexByUUserIdx != NULL ) {
			indexByUUserIdx->clear();
		}
		if( members != NULL ) {
			cfsec::ICFSecTSecGrpMembObj* cur = NULL;
			cfsec::ICFSecTSecGrpMembEditObj* edit = NULL;
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

	cfsec::ICFSecTSecGrpMembObj* CFSecTSecGrpMembTableObj::newInstance() {
		cfsec::ICFSecTSecGrpMembObj* inst = dynamic_cast<cfsec::ICFSecTSecGrpMembObj*>( new CFSecTSecGrpMembObj( schema ) );
		return( inst );
	}

	cfsec::ICFSecTSecGrpMembEditObj* CFSecTSecGrpMembTableObj::newEditInstance( cfsec::ICFSecTSecGrpMembObj* orig ) {
		cfsec::ICFSecTSecGrpMembEditObj* edit = dynamic_cast<cfsec::ICFSecTSecGrpMembEditObj*>( new CFSecTSecGrpMembEditObj( orig ));
		return( edit );
	}

	cfsec::ICFSecTSecGrpMembObj* CFSecTSecGrpMembTableObj::realizeTSecGrpMemb( cfsec::ICFSecTSecGrpMembObj* Obj ) {
		static const std::string S_ProcName( "realizeTSecGrpMemb" );
		static const std::string S_ExistingObj( "existingObj" );
		static const std::string S_KeepObj( "keepObj" );
		static const std::string S_Obj( "Obj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfsec::ICFSecTSecGrpMembObj* obj = Obj;
		cfsec::ICFSecTSecGrpMembObj* existingObj = NULL;
		cfsec::CFSecTSecGrpMembPKey* pkey = obj->getPKey();
		cfsec::ICFSecTSecGrpMembObj* keepObj = NULL;
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
			if( indexByTenantIdx != NULL ) {
				cfsec::CFSecTSecGrpMembByTenantIdxKey keyTenantIdx;
				keyTenantIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				auto searchTenantIdx = indexByTenantIdx->find( keyTenantIdx );
				if( searchTenantIdx != indexByTenantIdx->end() ) {
					std::map<cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj*>* mapTenantIdx = searchTenantIdx->second;
					if( mapTenantIdx != NULL ) {
						auto removalProbe = mapTenantIdx->find( *(keepObj->getPKey()) );
						if( removalProbe != mapTenantIdx->end() ) {
							mapTenantIdx->erase( removalProbe );
						}
					}
				}
			}

			if( indexByGroupIdx != NULL ) {
				cfsec::CFSecTSecGrpMembByGroupIdxKey keyGroupIdx;
				keyGroupIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				keyGroupIdx.setRequiredTSecGroupId( keepObj->getRequiredTSecGroupId() );
				auto searchGroupIdx = indexByGroupIdx->find( keyGroupIdx );
				if( searchGroupIdx != indexByGroupIdx->end() ) {
					std::map<cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj*>* mapGroupIdx = searchGroupIdx->second;
					if( mapGroupIdx != NULL ) {
						auto removalProbe = mapGroupIdx->find( *(keepObj->getPKey()) );
						if( removalProbe != mapGroupIdx->end() ) {
							mapGroupIdx->erase( removalProbe );
						}
					}
				}
			}

			if( indexByUserIdx != NULL ) {
				cfsec::CFSecTSecGrpMembByUserIdxKey keyUserIdx;
				keyUserIdx.setRequiredSecUserId( keepObj->getRequiredSecUserId() );
				auto searchUserIdx = indexByUserIdx->find( keyUserIdx );
				if( searchUserIdx != indexByUserIdx->end() ) {
					std::map<cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj*>* mapUserIdx = searchUserIdx->second;
					if( mapUserIdx != NULL ) {
						auto removalProbe = mapUserIdx->find( *(keepObj->getPKey()) );
						if( removalProbe != mapUserIdx->end() ) {
							mapUserIdx->erase( removalProbe );
						}
					}
				}
			}

			if( indexByUUserIdx != NULL ) {
				cfsec::CFSecTSecGrpMembByUUserIdxKey keyUUserIdx;
				keyUUserIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				keyUUserIdx.setRequiredTSecGroupId( keepObj->getRequiredTSecGroupId() );
				keyUUserIdx.setRequiredSecUserId( keepObj->getRequiredSecUserId() );
				auto removalProbe = indexByUUserIdx->find( keyUUserIdx );
				if( removalProbe != indexByUUserIdx->end() ) {
					indexByUUserIdx->erase( removalProbe );
				}
			}

			keepObj->setBuff( dynamic_cast<cfsec::CFSecTSecGrpMembBuff*>( Obj->getBuff()->clone() ) );
			// Attach new object to alternate and duplicate indexes -- PKey stays stable

			if( indexByTenantIdx != NULL ) {
				static const std::string S_ATenantIdxObj( "aTenantIdxObj" );
				cfsec::ICFSecTSecGrpMembObj* aTenantIdxObj =
					dynamic_cast<cfsec::ICFSecTSecGrpMembObj*>( keepObj );
				if( aTenantIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ATenantIdxObj );
				}
				cfsec::CFSecTSecGrpMembByTenantIdxKey keyTenantIdx;
				keyTenantIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				auto searchIndexByTenantIdx = indexByTenantIdx->find( keyTenantIdx );
				if( searchIndexByTenantIdx != indexByTenantIdx->end() ) {
					std::map<cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj*>* mapTenantIdx = searchIndexByTenantIdx->second;
					if( mapTenantIdx != NULL ) {
						mapTenantIdx->insert( std::map< cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj* >::value_type( *(keepObj->getPKey()), aTenantIdxObj ) );
					}
				}
			}

			if( indexByGroupIdx != NULL ) {
				static const std::string S_AGroupIdxObj( "aGroupIdxObj" );
				cfsec::ICFSecTSecGrpMembObj* aGroupIdxObj =
					dynamic_cast<cfsec::ICFSecTSecGrpMembObj*>( keepObj );
				if( aGroupIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AGroupIdxObj );
				}
				cfsec::CFSecTSecGrpMembByGroupIdxKey keyGroupIdx;
				keyGroupIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				keyGroupIdx.setRequiredTSecGroupId( keepObj->getRequiredTSecGroupId() );
				auto searchIndexByGroupIdx = indexByGroupIdx->find( keyGroupIdx );
				if( searchIndexByGroupIdx != indexByGroupIdx->end() ) {
					std::map<cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj*>* mapGroupIdx = searchIndexByGroupIdx->second;
					if( mapGroupIdx != NULL ) {
						mapGroupIdx->insert( std::map< cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj* >::value_type( *(keepObj->getPKey()), aGroupIdxObj ) );
					}
				}
			}

			if( indexByUserIdx != NULL ) {
				static const std::string S_AUserIdxObj( "aUserIdxObj" );
				cfsec::ICFSecTSecGrpMembObj* aUserIdxObj =
					dynamic_cast<cfsec::ICFSecTSecGrpMembObj*>( keepObj );
				if( aUserIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AUserIdxObj );
				}
				cfsec::CFSecTSecGrpMembByUserIdxKey keyUserIdx;
				keyUserIdx.setRequiredSecUserId( keepObj->getRequiredSecUserId() );
				auto searchIndexByUserIdx = indexByUserIdx->find( keyUserIdx );
				if( searchIndexByUserIdx != indexByUserIdx->end() ) {
					std::map<cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj*>* mapUserIdx = searchIndexByUserIdx->second;
					if( mapUserIdx != NULL ) {
						mapUserIdx->insert( std::map< cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj* >::value_type( *(keepObj->getPKey()), aUserIdxObj ) );
					}
				}
			}

			if( indexByUUserIdx != NULL ) {
				static const std::string S_AUUserIdxObj( "aUUserIdxObj" );
				cfsec::ICFSecTSecGrpMembObj* aUUserIdxObj =
					dynamic_cast<cfsec::ICFSecTSecGrpMembObj*>( keepObj );
				if( aUUserIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AUUserIdxObj );
				}
				cfsec::CFSecTSecGrpMembByUUserIdxKey keyUUserIdx;
				keyUUserIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				keyUUserIdx.setRequiredTSecGroupId( keepObj->getRequiredTSecGroupId() );
				keyUUserIdx.setRequiredSecUserId( keepObj->getRequiredSecUserId() );
				indexByUUserIdx->insert( std::map< cfsec::CFSecTSecGrpMembByUUserIdxKey, cfsec::ICFSecTSecGrpMembObj* >::value_type( keyUUserIdx, aUUserIdxObj ) );
			}

			if( allTSecGrpMemb != NULL ) {
				allTSecGrpMemb->insert( std::map< cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			}
		}
		else {
			keepObj = obj;
			keepObj->setIsNew( false );
			pkey = keepObj->getPKey();
			// Attach new object to PKey, all, alternate, and duplicate indexes
			members->insert( std::map< cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			// Attach new object to alternate and duplicate indexes -- PKey stay stable

			if( indexByTenantIdx != NULL ) {
				static const std::string S_ATenantIdxObj( "aTenantIdxObj" );
				cfsec::ICFSecTSecGrpMembObj* aTenantIdxObj =
					dynamic_cast<cfsec::ICFSecTSecGrpMembObj*>( keepObj );
				if( aTenantIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ATenantIdxObj );
				}
				cfsec::CFSecTSecGrpMembByTenantIdxKey keyTenantIdx;
				keyTenantIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				auto searchIndexByTenantIdx = indexByTenantIdx->find( keyTenantIdx );
				if( searchIndexByTenantIdx != indexByTenantIdx->end() ) {
					std::map<cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj*>* mapTenantIdx = searchIndexByTenantIdx->second;
					if( mapTenantIdx != NULL ) {
						mapTenantIdx->insert( std::map< cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj* >::value_type( *(keepObj->getPKey()), aTenantIdxObj ) );
					}
				}
			}

			if( indexByGroupIdx != NULL ) {
				static const std::string S_AGroupIdxObj( "aGroupIdxObj" );
				cfsec::ICFSecTSecGrpMembObj* aGroupIdxObj =
					dynamic_cast<cfsec::ICFSecTSecGrpMembObj*>( keepObj );
				if( aGroupIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AGroupIdxObj );
				}
				cfsec::CFSecTSecGrpMembByGroupIdxKey keyGroupIdx;
				keyGroupIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				keyGroupIdx.setRequiredTSecGroupId( keepObj->getRequiredTSecGroupId() );
				auto searchIndexByGroupIdx = indexByGroupIdx->find( keyGroupIdx );
				if( searchIndexByGroupIdx != indexByGroupIdx->end() ) {
					std::map<cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj*>* mapGroupIdx = searchIndexByGroupIdx->second;
					if( mapGroupIdx != NULL ) {
						mapGroupIdx->insert( std::map< cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj* >::value_type( *(keepObj->getPKey()), aGroupIdxObj ) );
					}
				}
			}

			if( indexByUserIdx != NULL ) {
				static const std::string S_AUserIdxObj( "aUserIdxObj" );
				cfsec::ICFSecTSecGrpMembObj* aUserIdxObj =
					dynamic_cast<cfsec::ICFSecTSecGrpMembObj*>( keepObj );
				if( aUserIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AUserIdxObj );
				}
				cfsec::CFSecTSecGrpMembByUserIdxKey keyUserIdx;
				keyUserIdx.setRequiredSecUserId( keepObj->getRequiredSecUserId() );
				auto searchIndexByUserIdx = indexByUserIdx->find( keyUserIdx );
				if( searchIndexByUserIdx != indexByUserIdx->end() ) {
					std::map<cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj*>* mapUserIdx = searchIndexByUserIdx->second;
					if( mapUserIdx != NULL ) {
						mapUserIdx->insert( std::map< cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj* >::value_type( *(keepObj->getPKey()), aUserIdxObj ) );
					}
				}
			}

			if( indexByUUserIdx != NULL ) {
				static const std::string S_AUUserIdxObj( "aUUserIdxObj" );
				cfsec::ICFSecTSecGrpMembObj* aUUserIdxObj =
					dynamic_cast<cfsec::ICFSecTSecGrpMembObj*>( keepObj );
				if( aUUserIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AUUserIdxObj );
				}
				cfsec::CFSecTSecGrpMembByUUserIdxKey keyUUserIdx;
				keyUUserIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				keyUUserIdx.setRequiredTSecGroupId( keepObj->getRequiredTSecGroupId() );
				keyUUserIdx.setRequiredSecUserId( keepObj->getRequiredSecUserId() );
				indexByUUserIdx->insert( std::map< cfsec::CFSecTSecGrpMembByUUserIdxKey, cfsec::ICFSecTSecGrpMembObj* >::value_type( keyUUserIdx, aUUserIdxObj ) );
			}

			if( allTSecGrpMemb != NULL ) {
				allTSecGrpMemb->insert( std::map< cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
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

	void CFSecTSecGrpMembTableObj::deepDisposeByIdIdx( const int64_t TenantId,
			const int64_t TSecGrpMembId ) {
		static const std::string S_ProcName( "deepDisposeByIdIdx" );
		std::vector<cfsec::ICFSecTSecGrpMembObj*> list;
		cfsec::ICFSecTSecGrpMembObj* existingObj = readCachedTSecGrpMembByIdIdx( TenantId,
				TSecGrpMembId );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfsec::ICFSecTSecGrpMembObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecTSecGrpMembBuff::CLASS_CODE ) {
					dynamic_cast<cfsec::CFSecTSecGrpMembTableObj*>( schema->getTSecGrpMembTableObj() )->reallyDeepDisposeTSecGrpMemb( dynamic_cast<cfsec::ICFSecTSecGrpMembObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFSecTSecGrpMembTableObj::deepDisposeByTenantIdx( const int64_t TenantId ) {
		static const std::string S_ProcName( "deepDisposeByTenantIdx" );
		std::vector<cfsec::ICFSecTSecGrpMembObj*> list;
		std::vector<cfsec::ICFSecTSecGrpMembObj*> matchesFound = readCachedTSecGrpMembByTenantIdx( TenantId );
		auto iterMatches = matchesFound.begin();
		auto endMatches = matchesFound.end();
		while( iterMatches != endMatches ) {
			if( *iterMatches != NULL ) {
				list.push_back( *iterMatches );
			}
			iterMatches ++;
		}
		cfsec::ICFSecTSecGrpMembObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecTSecGrpMembBuff::CLASS_CODE ) {
					dynamic_cast<cfsec::CFSecTSecGrpMembTableObj*>( schema->getTSecGrpMembTableObj() )->reallyDeepDisposeTSecGrpMemb( dynamic_cast<cfsec::ICFSecTSecGrpMembObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFSecTSecGrpMembTableObj::deepDisposeByGroupIdx( const int64_t TenantId,
			const int32_t TSecGroupId ) {
		static const std::string S_ProcName( "deepDisposeByGroupIdx" );
		std::vector<cfsec::ICFSecTSecGrpMembObj*> list;
		std::vector<cfsec::ICFSecTSecGrpMembObj*> matchesFound = readCachedTSecGrpMembByGroupIdx( TenantId,
				TSecGroupId );
		auto iterMatches = matchesFound.begin();
		auto endMatches = matchesFound.end();
		while( iterMatches != endMatches ) {
			if( *iterMatches != NULL ) {
				list.push_back( *iterMatches );
			}
			iterMatches ++;
		}
		cfsec::ICFSecTSecGrpMembObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecTSecGrpMembBuff::CLASS_CODE ) {
					dynamic_cast<cfsec::CFSecTSecGrpMembTableObj*>( schema->getTSecGrpMembTableObj() )->reallyDeepDisposeTSecGrpMemb( dynamic_cast<cfsec::ICFSecTSecGrpMembObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFSecTSecGrpMembTableObj::deepDisposeByUserIdx( const uuid_ptr_t SecUserId ) {
		static const std::string S_ProcName( "deepDisposeByUserIdx" );
		std::vector<cfsec::ICFSecTSecGrpMembObj*> list;
		std::vector<cfsec::ICFSecTSecGrpMembObj*> matchesFound = readCachedTSecGrpMembByUserIdx( SecUserId );
		auto iterMatches = matchesFound.begin();
		auto endMatches = matchesFound.end();
		while( iterMatches != endMatches ) {
			if( *iterMatches != NULL ) {
				list.push_back( *iterMatches );
			}
			iterMatches ++;
		}
		cfsec::ICFSecTSecGrpMembObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecTSecGrpMembBuff::CLASS_CODE ) {
					dynamic_cast<cfsec::CFSecTSecGrpMembTableObj*>( schema->getTSecGrpMembTableObj() )->reallyDeepDisposeTSecGrpMemb( dynamic_cast<cfsec::ICFSecTSecGrpMembObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFSecTSecGrpMembTableObj::deepDisposeByUUserIdx( const int64_t TenantId,
			const int32_t TSecGroupId,
			const uuid_ptr_t SecUserId ) {
		static const std::string S_ProcName( "deepDisposeByUUserIdx" );
		std::vector<cfsec::ICFSecTSecGrpMembObj*> list;
		cfsec::ICFSecTSecGrpMembObj* existingObj = readCachedTSecGrpMembByUUserIdx( TenantId,
				TSecGroupId,
				SecUserId );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfsec::ICFSecTSecGrpMembObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecTSecGrpMembBuff::CLASS_CODE ) {
					dynamic_cast<cfsec::CFSecTSecGrpMembTableObj*>( schema->getTSecGrpMembTableObj() )->reallyDeepDisposeTSecGrpMemb( dynamic_cast<cfsec::ICFSecTSecGrpMembObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFSecTSecGrpMembTableObj::reallyDeepDisposeTSecGrpMemb( cfsec::ICFSecTSecGrpMembObj* Obj ) {
		static const std::string S_ProcName( "reallyDeepDisposeTSecGrpMemb" );

		if( Obj == NULL ) {
			return;
		}

		cfsec::ICFSecTSecGrpMembObj* obj = Obj;
		
		classcode_t classCode = obj->getClassCode();
		if( classCode == cfsec::CFSecTSecGrpMembBuff::CLASS_CODE ) {
			dynamic_cast<cfsec::CFSecTSecGrpMembTableObj*>( schema->getTSecGrpMembTableObj() )->reallyDetachFromIndexesTSecGrpMemb( dynamic_cast<cfsec::ICFSecTSecGrpMembObj*>( obj ) );
		}

		if( obj->getEdit() != NULL ) {
			obj->endEdit();
		}
		delete obj;
		obj = NULL;
	}

	cfsec::ICFSecTSecGrpMembObj* CFSecTSecGrpMembTableObj::createTSecGrpMemb( cfsec::ICFSecTSecGrpMembEditObj* Obj ) {
		static const std::string S_ProcName( "createTSecGrpMemb" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Cloneable( "cloneable" );
		static const std::string S_ClonedBuff( "clonedbuff" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecTSecGrpMembObj* obj = dynamic_cast<cfsec::ICFSecTSecGrpMembObj*>( Obj->getOrig() );
		try {
			cfsec::CFSecTSecGrpMembBuff* buff = dynamic_cast<cfsec::CFSecTSecGrpMembBuff*>( Obj->getBuff()->clone() );
			// C++18 version of create returns a new buffer instance and takes over ownership of the passed-in buffer
			// MSS TODO WORKING The xmsg client will need to return the buffer instance created by processing
			// the response message, while xmsg rqst will have to delete the backing store instance
			// it receives after preparing the reply message so that memory doesn't leak on every request.
			cflib::ICFLibCloneableObj* cloneable = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableTSecGrpMemb()->createTSecGrpMemb(
				schema->getAuthorization(),
				buff );
			if( cloneable == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Cloneable );
			}
			Obj->endEdit();
			obj->setBuff( dynamic_cast<cfsec::CFSecTSecGrpMembBuff*>( cloneable ) );
			obj = dynamic_cast<cfsec::ICFSecTSecGrpMembObj*>( obj->realize() );
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

	cfsec::ICFSecTSecGrpMembObj* CFSecTSecGrpMembTableObj::readTSecGrpMemb( cfsec::CFSecTSecGrpMembPKey* pkey, bool forceRead ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readTSecGrpMemb" );
		cfsec::ICFSecTSecGrpMembObj* obj = NULL;
		cfsec::ICFSecTSecGrpMembObj* realized = NULL;
		if( ! forceRead ) {
			auto searchMembers = members->find( *pkey );
			if( searchMembers != members->end() ) {
				// obj could be NULL if cache misses is enabled
				obj = searchMembers->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecTSecGrpMembBuff* readBuff = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableTSecGrpMemb()->readDerivedByIdIdx( schema->getAuthorization(),
			pkey->getRequiredTenantId(),
			pkey->getRequiredTSecGrpMembId() );
			if( readBuff != NULL ) {
			obj = dynamic_cast<cfsec::CFSecTSecGrpMembTableObj*>( schema->getTSecGrpMembTableObj() )->newInstance();
				obj->setBuff( readBuff );
				realized = dynamic_cast<cfsec::ICFSecTSecGrpMembObj*>( obj->realize() );
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

	cfsec::ICFSecTSecGrpMembObj* CFSecTSecGrpMembTableObj::lockTSecGrpMemb( cfsec::CFSecTSecGrpMembPKey* pkey ) {
		static const std::string S_ProcName( "lockTSecGrpMemb" );
		cfsec::ICFSecTSecGrpMembObj* locked = NULL;
		cfsec::CFSecTSecGrpMembBuff* lockBuff = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableTSecGrpMemb()->lockDerived( schema->getAuthorization(), pkey );
		if( lockBuff != NULL ) {
			locked = dynamic_cast<cfsec::CFSecTSecGrpMembTableObj*>( schema->getTSecGrpMembTableObj() )->newInstance();
			locked->setBuff( lockBuff );
			locked = dynamic_cast<cfsec::ICFSecTSecGrpMembObj*>( locked->realize() );
		}
		else {
			return( NULL );
		}
		return( locked );
	}

	std::vector<cfsec::ICFSecTSecGrpMembObj*> CFSecTSecGrpMembTableObj::readAllTSecGrpMemb( bool forceRead ) {
		static const std::string S_ProcName( "readAllTSecGrpMemb" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Realized( "realized" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecTSecGrpMembObj* realized = NULL;
		if( forceRead || ( allTSecGrpMemb == NULL ) ) {
			std::map<cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj*>* map = new std::map<cfsec::CFSecTSecGrpMembPKey,cfsec::ICFSecTSecGrpMembObj*>();
			allTSecGrpMemb = map;
			std::TCFLibOwningVector<cfsec::CFSecTSecGrpMembBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableTSecGrpMemb()->readAllDerived( schema->getAuthorization() );
			cfsec::CFSecTSecGrpMembBuff* buff = NULL;
			cfsec::ICFSecTSecGrpMembObj* obj = NULL;
			try {
				for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
					buff = buffList[ idx ];
					buffList[ idx ] = NULL;
				obj = newInstance();
					obj->setBuff( buff );
					realized = dynamic_cast<cfsec::ICFSecTSecGrpMembObj*>( obj->realize() );
					if( realized == NULL ) {
						throw cflib::CFLibNullArgumentException( CLASS_NAME,
							S_ProcName,
							0,
							S_Realized );
					}
					allTSecGrpMemb->insert( std::map< cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj* >::value_type( *(realized->getPKey()), realized ) );
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
		size_t len = allTSecGrpMemb->size();
		std::vector<cfsec::ICFSecTSecGrpMembObj*> arr;
		auto valIter = allTSecGrpMemb->begin();
		size_t idx = 0;
		while( valIter != allTSecGrpMemb->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	std::vector<cfsec::ICFSecTSecGrpMembObj*> CFSecTSecGrpMembTableObj::pageAllTSecGrpMemb(const int64_t* priorTenantId,
			const int64_t* priorTSecGrpMembId )
	{
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "pageAllTSecGrpMemb" );
		CFLIB_EXCEPTION_DECLINFO
		std::map<cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj*>* map = NULL;
		cfsec::CFSecTSecGrpMembBuff* buff = NULL;
		cfsec::ICFSecTSecGrpMembObj* obj = NULL;
		cfsec::ICFSecTSecGrpMembObj* realized = NULL;
		std::vector<cfsec::ICFSecTSecGrpMembObj*> arrayList;
		try {
			map = new std::map<cfsec::CFSecTSecGrpMembPKey,cfsec::ICFSecTSecGrpMembObj*>();
			std::TCFLibOwningVector<cfsec::CFSecTSecGrpMembBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableTSecGrpMemb()->pageAllBuff( schema->getAuthorization(),
				priorTenantId,
				priorTSecGrpMembId );
			arrayList.reserve( buffList.size() );
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = newInstance();
				obj->setBuff( buff );
				realized = dynamic_cast<cfsec::ICFSecTSecGrpMembObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = NULL;
				arrayList.push_back( realized );
				realized = NULL;
			}
		}
		CFLIB_EXCEPTION_CATCH_FALLTHROUGH

		if( ( obj != NULL ) && obj->getIsNew() ) {
			delete obj;
			obj = NULL;
		}

		CFLIB_EXCEPTION_RETHROW_CFLIBEXCEPTION

		return( arrayList );
	}

	cfsec::ICFSecTSecGrpMembObj* CFSecTSecGrpMembTableObj::readTSecGrpMembByIdIdx( const int64_t TenantId,
			const int64_t TSecGrpMembId, bool forceRead )
	{
		static const std::string S_ProcName( "readTSecGrpMembByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecTSecGrpMembPKey pkey;
		pkey.setRequiredTenantId( TenantId );
		pkey.setRequiredTSecGrpMembId( TSecGrpMembId );
		cfsec::ICFSecTSecGrpMembObj* obj = readTSecGrpMemb( &pkey, forceRead );
		return( obj );
	}

	std::vector<cfsec::ICFSecTSecGrpMembObj*> CFSecTSecGrpMembTableObj::readTSecGrpMembByTenantIdx( const int64_t TenantId,
		bool forceRead )
	{
		static const std::string S_ProcName( "readTSecGrpMembByTenantIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecTSecGrpMembByTenantIdxKey key;
		key.setRequiredTenantId( TenantId );
		std::map<cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj*>* dict;
		std::map<cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj*>* oldDict;
		if( indexByTenantIdx == NULL ) {
			indexByTenantIdx = new std::map< cfsec::CFSecTSecGrpMembByTenantIdxKey,
				std::map< cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj*>*>();
		}
		auto searchIndexByTenantIdx = indexByTenantIdx->find( key );
		if( searchIndexByTenantIdx != indexByTenantIdx->end() ) {
			oldDict = searchIndexByTenantIdx->second;
		}
		else {
			oldDict = NULL;
		}
		if( ( oldDict != NULL ) && ( ! forceRead ) ) {
			dict = oldDict;
		}
		else {
			dict = new std::map<cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj*>();
			cfsec::ICFSecTSecGrpMembObj* obj;
			std::TCFLibOwningVector<cfsec::CFSecTSecGrpMembBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableTSecGrpMemb()->readDerivedByTenantIdx( schema->getAuthorization(),
				TenantId );
			cfsec::CFSecTSecGrpMembBuff* buff;
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = dynamic_cast<cfsec::CFSecTSecGrpMembTableObj*>( schema->getTSecGrpMembTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
				obj->setBuff( buff );
				cfsec::ICFSecTSecGrpMembObj* realized = dynamic_cast<cfsec::ICFSecTSecGrpMembObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				dict->insert( std::map< cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj* >::value_type( *(realized->getPKey()), realized ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = NULL;
			}
			if( oldDict != NULL ) {
				indexByTenantIdx->erase( searchIndexByTenantIdx );
				delete oldDict;
				oldDict = NULL;
			}
			indexByTenantIdx->insert( std::map< cfsec::CFSecTSecGrpMembByTenantIdxKey,
				std::map< cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj* >* >::value_type( key, dict ) );
		}
		size_t len = dict->size();
		std::vector<cfsec::ICFSecTSecGrpMembObj*> arr;
		arr.reserve( len );
		auto valIter = dict->begin();
		while( valIter != dict->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	std::vector<cfsec::ICFSecTSecGrpMembObj*> CFSecTSecGrpMembTableObj::readTSecGrpMembByGroupIdx( const int64_t TenantId,
			const int32_t TSecGroupId,
		bool forceRead )
	{
		static const std::string S_ProcName( "readTSecGrpMembByGroupIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecTSecGrpMembByGroupIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredTSecGroupId( TSecGroupId );
		std::map<cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj*>* dict;
		std::map<cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj*>* oldDict;
		if( indexByGroupIdx == NULL ) {
			indexByGroupIdx = new std::map< cfsec::CFSecTSecGrpMembByGroupIdxKey,
				std::map< cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj*>*>();
		}
		auto searchIndexByGroupIdx = indexByGroupIdx->find( key );
		if( searchIndexByGroupIdx != indexByGroupIdx->end() ) {
			oldDict = searchIndexByGroupIdx->second;
		}
		else {
			oldDict = NULL;
		}
		if( ( oldDict != NULL ) && ( ! forceRead ) ) {
			dict = oldDict;
		}
		else {
			dict = new std::map<cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj*>();
			cfsec::ICFSecTSecGrpMembObj* obj;
			std::TCFLibOwningVector<cfsec::CFSecTSecGrpMembBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableTSecGrpMemb()->readDerivedByGroupIdx( schema->getAuthorization(),
				TenantId,
				TSecGroupId );
			cfsec::CFSecTSecGrpMembBuff* buff;
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = dynamic_cast<cfsec::CFSecTSecGrpMembTableObj*>( schema->getTSecGrpMembTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
				obj->setBuff( buff );
				cfsec::ICFSecTSecGrpMembObj* realized = dynamic_cast<cfsec::ICFSecTSecGrpMembObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				dict->insert( std::map< cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj* >::value_type( *(realized->getPKey()), realized ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = NULL;
			}
			if( oldDict != NULL ) {
				indexByGroupIdx->erase( searchIndexByGroupIdx );
				delete oldDict;
				oldDict = NULL;
			}
			indexByGroupIdx->insert( std::map< cfsec::CFSecTSecGrpMembByGroupIdxKey,
				std::map< cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj* >* >::value_type( key, dict ) );
		}
		size_t len = dict->size();
		std::vector<cfsec::ICFSecTSecGrpMembObj*> arr;
		arr.reserve( len );
		auto valIter = dict->begin();
		while( valIter != dict->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	std::vector<cfsec::ICFSecTSecGrpMembObj*> CFSecTSecGrpMembTableObj::readTSecGrpMembByUserIdx( const uuid_ptr_t SecUserId,
		bool forceRead )
	{
		static const std::string S_ProcName( "readTSecGrpMembByUserIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecTSecGrpMembByUserIdxKey key;
		key.setRequiredSecUserId( SecUserId );
		std::map<cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj*>* dict;
		std::map<cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj*>* oldDict;
		if( indexByUserIdx == NULL ) {
			indexByUserIdx = new std::map< cfsec::CFSecTSecGrpMembByUserIdxKey,
				std::map< cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj*>*>();
		}
		auto searchIndexByUserIdx = indexByUserIdx->find( key );
		if( searchIndexByUserIdx != indexByUserIdx->end() ) {
			oldDict = searchIndexByUserIdx->second;
		}
		else {
			oldDict = NULL;
		}
		if( ( oldDict != NULL ) && ( ! forceRead ) ) {
			dict = oldDict;
		}
		else {
			dict = new std::map<cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj*>();
			cfsec::ICFSecTSecGrpMembObj* obj;
			std::TCFLibOwningVector<cfsec::CFSecTSecGrpMembBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableTSecGrpMemb()->readDerivedByUserIdx( schema->getAuthorization(),
				SecUserId );
			cfsec::CFSecTSecGrpMembBuff* buff;
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = dynamic_cast<cfsec::CFSecTSecGrpMembTableObj*>( schema->getTSecGrpMembTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
				obj->setBuff( buff );
				cfsec::ICFSecTSecGrpMembObj* realized = dynamic_cast<cfsec::ICFSecTSecGrpMembObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				dict->insert( std::map< cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj* >::value_type( *(realized->getPKey()), realized ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = NULL;
			}
			if( oldDict != NULL ) {
				indexByUserIdx->erase( searchIndexByUserIdx );
				delete oldDict;
				oldDict = NULL;
			}
			indexByUserIdx->insert( std::map< cfsec::CFSecTSecGrpMembByUserIdxKey,
				std::map< cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj* >* >::value_type( key, dict ) );
		}
		size_t len = dict->size();
		std::vector<cfsec::ICFSecTSecGrpMembObj*> arr;
		arr.reserve( len );
		auto valIter = dict->begin();
		while( valIter != dict->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	cfsec::ICFSecTSecGrpMembObj* CFSecTSecGrpMembTableObj::readTSecGrpMembByUUserIdx( const int64_t TenantId,
			const int32_t TSecGroupId,
			const uuid_ptr_t SecUserId, bool forceRead )
	{
		static const std::string S_ProcName( "readTSecGrpMembByUUserIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByUUserIdx == NULL ) {
			indexByUUserIdx = new std::map< cfsec::CFSecTSecGrpMembByUUserIdxKey,
				cfsec::ICFSecTSecGrpMembObj*>();
		}
		cfsec::CFSecTSecGrpMembByUUserIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredTSecGroupId( TSecGroupId );
		key.setRequiredSecUserId( SecUserId );
		cfsec::ICFSecTSecGrpMembObj* obj = NULL;
		cfsec::ICFSecTSecGrpMembObj* realized = NULL;
		if( ! forceRead ) {
			auto searchIndexByUUserIdx = indexByUUserIdx->find( key );
			if( searchIndexByUUserIdx != indexByUUserIdx->end() ) {
				// Note: obj may be null if cache misses is enabled
				obj = searchIndexByUUserIdx->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecTSecGrpMembBuff* buff = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableTSecGrpMemb()->readDerivedByUUserIdx( schema->getAuthorization(),
				TenantId,
				TSecGroupId,
				SecUserId );
			if( buff != NULL ) {
				obj = dynamic_cast<cfsec::CFSecTSecGrpMembTableObj*>( schema->getTSecGrpMembTableObj() )->newInstance();
				obj->setBuff( buff );
				realized = dynamic_cast<cfsec::ICFSecTSecGrpMembObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				indexByUUserIdx->insert( std::map< cfsec::CFSecTSecGrpMembByUUserIdxKey, cfsec::ICFSecTSecGrpMembObj*>::value_type( key, dynamic_cast<cfsec::ICFSecTSecGrpMembObj*>( realized ) ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = realized;
			}
		}
		return( obj );
	}

	cfsec::ICFSecTSecGrpMembObj* CFSecTSecGrpMembTableObj::readCachedTSecGrpMemb( cfsec::CFSecTSecGrpMembPKey* pkey ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readTSecGrpMemb" );
		cfsec::ICFSecTSecGrpMembObj* obj = NULL;
		cfsec::ICFSecTSecGrpMembObj* realized = NULL;
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			// obj could be NULL if cache misses is enabled
			obj = searchMembers->second;
			realized = obj;
		}
		return( realized );
	}

	cfsec::ICFSecTSecGrpMembObj* CFSecTSecGrpMembTableObj::readCachedTSecGrpMembByIdIdx( const int64_t TenantId,
			const int64_t TSecGrpMembId )
	{
		static const std::string S_ProcName( "readCachedTSecGrpMembByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecTSecGrpMembPKey pkey;
		pkey.setRequiredTenantId( TenantId );
		pkey.setRequiredTSecGrpMembId( TSecGrpMembId );
		cfsec::ICFSecTSecGrpMembObj* obj = readCachedTSecGrpMemb( &pkey );
		return( obj );
	}

	std::vector<cfsec::ICFSecTSecGrpMembObj*> CFSecTSecGrpMembTableObj::readCachedTSecGrpMembByTenantIdx( const int64_t TenantId )
	{
		static const std::string S_ProcName( "readCachedTSecGrpMembByTenantIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		std::vector<cfsec::ICFSecTSecGrpMembObj*> arr;
		cfsec::CFSecTSecGrpMembByTenantIdxKey key;
		key.setRequiredTenantId( TenantId );
		std::map<cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj*>* dict;
		if( indexByTenantIdx == NULL ) {
			return( arr );
		}
		auto searchIndexByTenantIdx = indexByTenantIdx->find( key );
		if( searchIndexByTenantIdx != indexByTenantIdx->end() ) {
			dict = searchIndexByTenantIdx->second;
			size_t len = dict->size();
			std::vector<cfsec::ICFSecTSecGrpMembObj*> arr;
			arr.reserve( len );
			auto valIter = dict->begin();
			while( valIter != dict->end() ) {
				arr.push_back( valIter->second );
				valIter ++;
			}
		}
		else {
			cfsec::ICFSecTSecGrpMembObj* obj;
			for( auto iterMembers = members->begin(); iterMembers != members->end(); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecTSecGrpMembBuff*>( obj->getBuff() ) ) == key ) {
						arr.push_back( obj );
					}
				}
			}
		}
		return( arr );
	}

	std::vector<cfsec::ICFSecTSecGrpMembObj*> CFSecTSecGrpMembTableObj::readCachedTSecGrpMembByGroupIdx( const int64_t TenantId,
			const int32_t TSecGroupId )
	{
		static const std::string S_ProcName( "readCachedTSecGrpMembByGroupIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		std::vector<cfsec::ICFSecTSecGrpMembObj*> arr;
		cfsec::CFSecTSecGrpMembByGroupIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredTSecGroupId( TSecGroupId );
		std::map<cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj*>* dict;
		if( indexByGroupIdx == NULL ) {
			return( arr );
		}
		auto searchIndexByGroupIdx = indexByGroupIdx->find( key );
		if( searchIndexByGroupIdx != indexByGroupIdx->end() ) {
			dict = searchIndexByGroupIdx->second;
			size_t len = dict->size();
			std::vector<cfsec::ICFSecTSecGrpMembObj*> arr;
			arr.reserve( len );
			auto valIter = dict->begin();
			while( valIter != dict->end() ) {
				arr.push_back( valIter->second );
				valIter ++;
			}
		}
		else {
			cfsec::ICFSecTSecGrpMembObj* obj;
			for( auto iterMembers = members->begin(); iterMembers != members->end(); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecTSecGrpMembBuff*>( obj->getBuff() ) ) == key ) {
						arr.push_back( obj );
					}
				}
			}
		}
		return( arr );
	}

	std::vector<cfsec::ICFSecTSecGrpMembObj*> CFSecTSecGrpMembTableObj::readCachedTSecGrpMembByUserIdx( const uuid_ptr_t SecUserId )
	{
		static const std::string S_ProcName( "readCachedTSecGrpMembByUserIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		std::vector<cfsec::ICFSecTSecGrpMembObj*> arr;
		cfsec::CFSecTSecGrpMembByUserIdxKey key;
		key.setRequiredSecUserId( SecUserId );
		std::map<cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj*>* dict;
		if( indexByUserIdx == NULL ) {
			return( arr );
		}
		auto searchIndexByUserIdx = indexByUserIdx->find( key );
		if( searchIndexByUserIdx != indexByUserIdx->end() ) {
			dict = searchIndexByUserIdx->second;
			size_t len = dict->size();
			std::vector<cfsec::ICFSecTSecGrpMembObj*> arr;
			arr.reserve( len );
			auto valIter = dict->begin();
			while( valIter != dict->end() ) {
				arr.push_back( valIter->second );
				valIter ++;
			}
		}
		else {
			cfsec::ICFSecTSecGrpMembObj* obj;
			for( auto iterMembers = members->begin(); iterMembers != members->end(); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecTSecGrpMembBuff*>( obj->getBuff() ) ) == key ) {
						arr.push_back( obj );
					}
				}
			}
		}
		return( arr );
	}

	cfsec::ICFSecTSecGrpMembObj* CFSecTSecGrpMembTableObj::readCachedTSecGrpMembByUUserIdx( const int64_t TenantId,
			const int32_t TSecGroupId,
			const uuid_ptr_t SecUserId )
	{
		static const std::string S_ProcName( "readCachedTSecGrpMembByUUserIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByUUserIdx == NULL ) {
			indexByUUserIdx = new std::map< cfsec::CFSecTSecGrpMembByUUserIdxKey,
				cfsec::ICFSecTSecGrpMembObj*>();
		}
		cfsec::CFSecTSecGrpMembByUUserIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredTSecGroupId( TSecGroupId );
		key.setRequiredSecUserId( SecUserId );
		cfsec::ICFSecTSecGrpMembObj* obj = NULL;
		auto searchIndexByUUserIdx = indexByUUserIdx->find( key );
		if( searchIndexByUUserIdx != indexByUUserIdx->end() ) {
			// Note: obj may be null if cache misses is enabled
			obj = searchIndexByUUserIdx->second;
		}
		else {
			for( auto iterMembers = members->begin(); ( obj == NULL ) && ( iterMembers != members->end() ); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecTSecGrpMembBuff*>( obj->getBuff() ) ) != key ) {
						obj = NULL;
					}
				}
			}
		}
		return( obj );
	}

	std::vector<cfsec::ICFSecTSecGrpMembObj*> CFSecTSecGrpMembTableObj::pageTSecGrpMembByTenantIdx( const int64_t TenantId,
			const int64_t* priorTenantId,
			const int64_t* priorTSecGrpMembId )
	{
		static const std::string S_ProcName( "pageTSecGrpMembByTenantIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecTSecGrpMembByTenantIdxKey key;
		key.setRequiredTenantId( TenantId );
		cfsec::ICFSecTSecGrpMembObj* obj;
		std::TCFLibOwningVector<cfsec::CFSecTSecGrpMembBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableTSecGrpMemb()->pageBuffByTenantIdx( schema->getAuthorization(),
				TenantId,
				priorTenantId,
				priorTSecGrpMembId );
		std::vector<cfsec::ICFSecTSecGrpMembObj*> retList;
		retList.reserve( buffList.size() );
		cfsec::CFSecTSecGrpMembBuff* buff;
		cfsec::ICFSecTSecGrpMembObj* realized;
		for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
			buff = buffList[ idx ];
			buffList[ idx ] = NULL;
				obj = dynamic_cast<cfsec::CFSecTSecGrpMembTableObj*>( schema->getTSecGrpMembTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
			obj->setBuff( buff );
			realized = dynamic_cast<cfsec::ICFSecTSecGrpMembObj*>( obj->realize() );
			if( realized == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Realized );
			}
			// No need to delete obj -- realize() auto-destructs the instance it decided to discard
			obj = NULL;
			retList.push_back( realized );
		}
		return( retList );
	}

	std::vector<cfsec::ICFSecTSecGrpMembObj*> CFSecTSecGrpMembTableObj::pageTSecGrpMembByGroupIdx( const int64_t TenantId,
			const int32_t TSecGroupId,
			const int64_t* priorTenantId,
			const int64_t* priorTSecGrpMembId )
	{
		static const std::string S_ProcName( "pageTSecGrpMembByGroupIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecTSecGrpMembByGroupIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredTSecGroupId( TSecGroupId );
		cfsec::ICFSecTSecGrpMembObj* obj;
		std::TCFLibOwningVector<cfsec::CFSecTSecGrpMembBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableTSecGrpMemb()->pageBuffByGroupIdx( schema->getAuthorization(),
				TenantId,
				TSecGroupId,
				priorTenantId,
				priorTSecGrpMembId );
		std::vector<cfsec::ICFSecTSecGrpMembObj*> retList;
		retList.reserve( buffList.size() );
		cfsec::CFSecTSecGrpMembBuff* buff;
		cfsec::ICFSecTSecGrpMembObj* realized;
		for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
			buff = buffList[ idx ];
			buffList[ idx ] = NULL;
				obj = dynamic_cast<cfsec::CFSecTSecGrpMembTableObj*>( schema->getTSecGrpMembTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
			obj->setBuff( buff );
			realized = dynamic_cast<cfsec::ICFSecTSecGrpMembObj*>( obj->realize() );
			if( realized == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Realized );
			}
			// No need to delete obj -- realize() auto-destructs the instance it decided to discard
			obj = NULL;
			retList.push_back( realized );
		}
		return( retList );
	}

	std::vector<cfsec::ICFSecTSecGrpMembObj*> CFSecTSecGrpMembTableObj::pageTSecGrpMembByUserIdx( const uuid_ptr_t SecUserId,
			const int64_t* priorTenantId,
			const int64_t* priorTSecGrpMembId )
	{
		static const std::string S_ProcName( "pageTSecGrpMembByUserIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecTSecGrpMembByUserIdxKey key;
		key.setRequiredSecUserId( SecUserId );
		cfsec::ICFSecTSecGrpMembObj* obj;
		std::TCFLibOwningVector<cfsec::CFSecTSecGrpMembBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableTSecGrpMemb()->pageBuffByUserIdx( schema->getAuthorization(),
				SecUserId,
				priorTenantId,
				priorTSecGrpMembId );
		std::vector<cfsec::ICFSecTSecGrpMembObj*> retList;
		retList.reserve( buffList.size() );
		cfsec::CFSecTSecGrpMembBuff* buff;
		cfsec::ICFSecTSecGrpMembObj* realized;
		for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
			buff = buffList[ idx ];
			buffList[ idx ] = NULL;
				obj = dynamic_cast<cfsec::CFSecTSecGrpMembTableObj*>( schema->getTSecGrpMembTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
			obj->setBuff( buff );
			realized = dynamic_cast<cfsec::ICFSecTSecGrpMembObj*>( obj->realize() );
			if( realized == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Realized );
			}
			// No need to delete obj -- realize() auto-destructs the instance it decided to discard
			obj = NULL;
			retList.push_back( realized );
		}
		return( retList );
	}

	cfsec::ICFSecTSecGrpMembObj* CFSecTSecGrpMembTableObj::updateTSecGrpMemb( cfsec::ICFSecTSecGrpMembEditObj* Obj ) {
		static const std::string S_ProcName( "updateTSecGrpMemb" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Updated( "updated" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecTSecGrpMembObj* obj = dynamic_cast<cfsec::ICFSecTSecGrpMembObj*>( Obj->getOrig() );
		try {
			cfsec::CFSecTSecGrpMembBuff* updated = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableTSecGrpMemb()->updateTSecGrpMemb( schema->getAuthorization(),
				dynamic_cast<cfsec::CFSecTSecGrpMembBuff*>( Obj->getTSecGrpMembBuff()->clone() ) );
			if( updated == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Updated );
			}
			obj = dynamic_cast<cfsec::ICFSecTSecGrpMembObj*>( dynamic_cast<cfsec::CFSecTSecGrpMembTableObj*>( schema->getTSecGrpMembTableObj() )->newInstance() );
			obj->setBuff( updated );
			obj = dynamic_cast<cfsec::ICFSecTSecGrpMembObj*>( obj->realize() );
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

	void CFSecTSecGrpMembTableObj::deleteTSecGrpMemb( cfsec::ICFSecTSecGrpMembEditObj* Obj ) {
		cfsec::ICFSecTSecGrpMembObj* obj = Obj;
		dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableTSecGrpMemb()->deleteTSecGrpMemb( schema->getAuthorization(),
			obj->getTSecGrpMembBuff() );
		deepDisposeByIdIdx( obj->getRequiredTenantId(),
			obj->getRequiredTSecGrpMembId() );
	}

	void CFSecTSecGrpMembTableObj::deleteTSecGrpMembByIdIdx( const int64_t TenantId,
			const int64_t TSecGrpMembId )
	{
		cfsec::CFSecTSecGrpMembPKey pkey;
		pkey.setRequiredTenantId( TenantId );
		pkey.setRequiredTSecGrpMembId( TSecGrpMembId );
		cfsec::ICFSecTSecGrpMembObj* obj = readTSecGrpMemb( &pkey, true );
		if( obj != NULL ) {
			cfsec::ICFSecTSecGrpMembEditObj* editObj = dynamic_cast<cfsec::ICFSecTSecGrpMembEditObj*>( obj->getEdit() );
			if( editObj == NULL ) {
				editObj = dynamic_cast<cfsec::ICFSecTSecGrpMembEditObj*>( obj->beginEdit() );
			}
			if( editObj != NULL ) {
				editObj->deleteInstance();
				editObj = NULL;
			}
		}
	}

	void CFSecTSecGrpMembTableObj::deleteTSecGrpMembByTenantIdx( const int64_t TenantId )
	{
		dynamic_cast<cfsec::ICFSecSchema*>( schema->getBackingStore() )->getTableTSecGrpMemb()->deleteTSecGrpMembByTenantIdx( schema->getAuthorization(),
				TenantId );
		deepDisposeByTenantIdx( TenantId );
	}

	void CFSecTSecGrpMembTableObj::deleteTSecGrpMembByGroupIdx( const int64_t TenantId,
			const int32_t TSecGroupId )
	{
		dynamic_cast<cfsec::ICFSecSchema*>( schema->getBackingStore() )->getTableTSecGrpMemb()->deleteTSecGrpMembByGroupIdx( schema->getAuthorization(),
				TenantId,
				TSecGroupId );
		deepDisposeByGroupIdx( TenantId,
			TSecGroupId );
	}

	void CFSecTSecGrpMembTableObj::deleteTSecGrpMembByUserIdx( const uuid_ptr_t SecUserId )
	{
		dynamic_cast<cfsec::ICFSecSchema*>( schema->getBackingStore() )->getTableTSecGrpMemb()->deleteTSecGrpMembByUserIdx( schema->getAuthorization(),
				SecUserId );
		deepDisposeByUserIdx( SecUserId );
	}

	void CFSecTSecGrpMembTableObj::deleteTSecGrpMembByUUserIdx( const int64_t TenantId,
			const int32_t TSecGroupId,
			const uuid_ptr_t SecUserId )
	{
		if( indexByUUserIdx == NULL ) {
			indexByUUserIdx = new std::map< cfsec::CFSecTSecGrpMembByUUserIdxKey,
				cfsec::ICFSecTSecGrpMembObj*>();
		}
		cfsec::CFSecTSecGrpMembByUUserIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredTSecGroupId( TSecGroupId );
		key.setRequiredSecUserId( SecUserId );
		cfsec::ICFSecTSecGrpMembObj* obj = NULL;
		auto searchIndexByUUserIdx = indexByUUserIdx->find( key );
		if( searchIndexByUUserIdx != indexByUUserIdx->end() ) {
			dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableTSecGrpMemb()->deleteTSecGrpMembByUUserIdx( schema->getAuthorization(),
				TenantId,
				TSecGroupId,
				SecUserId );
		}
		else {
			dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableTSecGrpMemb()->deleteTSecGrpMembByUUserIdx( schema->getAuthorization(),
				TenantId,
				TSecGroupId,
				SecUserId );
		}
		deepDisposeByUUserIdx( TenantId,
			TSecGroupId,
			SecUserId );
	}

	void CFSecTSecGrpMembTableObj::reallyDetachFromIndexesTSecGrpMemb( cfsec::ICFSecTSecGrpMembObj* Obj ) {
		static const std::string S_ProcName( "reallyDetachFromIndexesTSecGrpMemb" );
		static const std::string S_Obj( "Obj" );
		static const std::string S_ExistingObj( "ExistingObj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfsec::ICFSecTSecGrpMembObj* obj = Obj;
		cfsec::CFSecTSecGrpMembPKey* pkey = obj->getPKey();
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			cfsec::ICFSecTSecGrpMembObj* existingObj = searchMembers->second;
			if( existingObj == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_ExistingObj );
			}
			if( indexByTenantIdx != NULL ) {
				cfsec::CFSecTSecGrpMembByTenantIdxKey keyTenantIdx;
				keyTenantIdx.setRequiredTenantId( obj->getRequiredTenantId() );
				auto searchTenantIdx = indexByTenantIdx->find( keyTenantIdx );
				if( searchTenantIdx != indexByTenantIdx->end() ) {
					std::map<cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj*>* mapTenantIdx = searchTenantIdx->second;
					if( mapTenantIdx != NULL ) {
						auto removalProbe = mapTenantIdx->find( *(obj->getPKey()) );
						if( removalProbe != mapTenantIdx->end() ) {
							mapTenantIdx->erase( removalProbe );
							if( mapTenantIdx->empty() ) {
								delete mapTenantIdx;
								mapTenantIdx = NULL;
								indexByTenantIdx->erase( searchTenantIdx );
							}
						}
					}
				}
			}

			if( indexByGroupIdx != NULL ) {
				cfsec::CFSecTSecGrpMembByGroupIdxKey keyGroupIdx;
				keyGroupIdx.setRequiredTenantId( obj->getRequiredTenantId() );
				keyGroupIdx.setRequiredTSecGroupId( obj->getRequiredTSecGroupId() );
				auto searchGroupIdx = indexByGroupIdx->find( keyGroupIdx );
				if( searchGroupIdx != indexByGroupIdx->end() ) {
					std::map<cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj*>* mapGroupIdx = searchGroupIdx->second;
					if( mapGroupIdx != NULL ) {
						auto removalProbe = mapGroupIdx->find( *(obj->getPKey()) );
						if( removalProbe != mapGroupIdx->end() ) {
							mapGroupIdx->erase( removalProbe );
							if( mapGroupIdx->empty() ) {
								delete mapGroupIdx;
								mapGroupIdx = NULL;
								indexByGroupIdx->erase( searchGroupIdx );
							}
						}
					}
				}
			}

			if( indexByUserIdx != NULL ) {
				cfsec::CFSecTSecGrpMembByUserIdxKey keyUserIdx;
				keyUserIdx.setRequiredSecUserId( obj->getRequiredSecUserId() );
				auto searchUserIdx = indexByUserIdx->find( keyUserIdx );
				if( searchUserIdx != indexByUserIdx->end() ) {
					std::map<cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj*>* mapUserIdx = searchUserIdx->second;
					if( mapUserIdx != NULL ) {
						auto removalProbe = mapUserIdx->find( *(obj->getPKey()) );
						if( removalProbe != mapUserIdx->end() ) {
							mapUserIdx->erase( removalProbe );
							if( mapUserIdx->empty() ) {
								delete mapUserIdx;
								mapUserIdx = NULL;
								indexByUserIdx->erase( searchUserIdx );
							}
						}
					}
				}
			}

			if( indexByUUserIdx != NULL ) {
				cfsec::CFSecTSecGrpMembByUUserIdxKey keyUUserIdx;
				keyUUserIdx.setRequiredTenantId( obj->getRequiredTenantId() );
				keyUUserIdx.setRequiredTSecGroupId( obj->getRequiredTSecGroupId() );
				keyUUserIdx.setRequiredSecUserId( obj->getRequiredSecUserId() );
				auto removalProbe = indexByUUserIdx->find( keyUUserIdx );
				if( removalProbe != indexByUUserIdx->end() ) {
					indexByUUserIdx->erase( removalProbe );
				}
			}

			members->erase( searchMembers );
		}
	}


}
