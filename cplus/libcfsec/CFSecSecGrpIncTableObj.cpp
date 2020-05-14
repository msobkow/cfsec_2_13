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

	const std::string CFSecSecGrpIncTableObj::CLASS_NAME( "CFSecSecGrpIncTableObj" );
	const std::string CFSecSecGrpIncTableObj::TABLE_NAME( "SecGrpInc" );
	const std::string CFSecSecGrpIncTableObj::TABLE_DBNAME( "SecInc" );

	CFSecSecGrpIncTableObj::CFSecSecGrpIncTableObj() {
		schema = NULL;
		members = new std::map<cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>();
		allSecGrpInc = NULL;
		indexByClusterIdx = new std::map< cfsec::CFSecSecGrpIncByClusterIdxKey,
			std::map< cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>*>();
		indexByGroupIdx = new std::map< cfsec::CFSecSecGrpIncByGroupIdxKey,
			std::map< cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>*>();
		indexByIncludeIdx = new std::map< cfsec::CFSecSecGrpIncByIncludeIdxKey,
			std::map< cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>*>();
		indexByUIncludeIdx = new std::map< cfsec::CFSecSecGrpIncByUIncludeIdxKey,
			cfsec::ICFSecSecGrpIncObj*>();
	}

	CFSecSecGrpIncTableObj::CFSecSecGrpIncTableObj( cfsec::ICFSecSchemaObj* argSchema ) {
		schema = dynamic_cast<cfsec::ICFSecSchemaObj*>( argSchema );
		members = new std::map<cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>();
		allSecGrpInc = NULL;
		indexByClusterIdx = new std::map< cfsec::CFSecSecGrpIncByClusterIdxKey,
			std::map< cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>*>();
		indexByGroupIdx = new std::map< cfsec::CFSecSecGrpIncByGroupIdxKey,
			std::map< cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>*>();
		indexByIncludeIdx = new std::map< cfsec::CFSecSecGrpIncByIncludeIdxKey,
			std::map< cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>*>();
		indexByUIncludeIdx = new std::map< cfsec::CFSecSecGrpIncByUIncludeIdxKey,
			cfsec::ICFSecSecGrpIncObj*>();
	}

	CFSecSecGrpIncTableObj::~CFSecSecGrpIncTableObj() {
		minimizeMemory();
		if( indexByClusterIdx != NULL ) {
			delete indexByClusterIdx;
			indexByClusterIdx = NULL;
		}
		if( indexByGroupIdx != NULL ) {
			delete indexByGroupIdx;
			indexByGroupIdx = NULL;
		}
		if( indexByIncludeIdx != NULL ) {
			delete indexByIncludeIdx;
			indexByIncludeIdx = NULL;
		}
		if( indexByUIncludeIdx != NULL ) {
			delete indexByUIncludeIdx;
			indexByUIncludeIdx = NULL;
		}
		if( members != NULL ) {
			cfsec::ICFSecSecGrpIncObj* curMember;
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

	cfsec::ICFSecSchemaObj* CFSecSecGrpIncTableObj::getSchema() {
		return( schema );
	}

	void CFSecSecGrpIncTableObj::setSchema( cfsec::ICFSecSchemaObj* value ) {
		schema = dynamic_cast<cfsec::ICFSecSchemaObj*>( value );
	}

	const std::string CFSecSecGrpIncTableObj::getTableName() {
		return( TABLE_NAME );
	}

	const std::string CFSecSecGrpIncTableObj::getTableDbName() {
		return( TABLE_DBNAME );
	}
	const classcode_t* CFSecSecGrpIncTableObj::getObjQualifyingClassCode() {
		return( NULL );
	}


	void CFSecSecGrpIncTableObj::minimizeMemory() {
		if( allSecGrpInc != NULL ) {
			allSecGrpInc->clear();
			delete allSecGrpInc;
			allSecGrpInc = NULL;
		}
		if( indexByClusterIdx != NULL ) {
			std::map< cfsec::CFSecSecGrpIncByClusterIdxKey,
				std::map< cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>* >::iterator iterByClusterIdx = indexByClusterIdx->begin();
			std::map< cfsec::CFSecSecGrpIncByClusterIdxKey,
				std::map< cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>* >::iterator endByClusterIdx = indexByClusterIdx->end();
			std::map< cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>* curByClusterIdx = NULL;
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
		if( indexByGroupIdx != NULL ) {
			std::map< cfsec::CFSecSecGrpIncByGroupIdxKey,
				std::map< cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>* >::iterator iterByGroupIdx = indexByGroupIdx->begin();
			std::map< cfsec::CFSecSecGrpIncByGroupIdxKey,
				std::map< cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>* >::iterator endByGroupIdx = indexByGroupIdx->end();
			std::map< cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>* curByGroupIdx = NULL;
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
		if( indexByIncludeIdx != NULL ) {
			std::map< cfsec::CFSecSecGrpIncByIncludeIdxKey,
				std::map< cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>* >::iterator iterByIncludeIdx = indexByIncludeIdx->begin();
			std::map< cfsec::CFSecSecGrpIncByIncludeIdxKey,
				std::map< cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>* >::iterator endByIncludeIdx = indexByIncludeIdx->end();
			std::map< cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>* curByIncludeIdx = NULL;
			while( iterByIncludeIdx != endByIncludeIdx ) {
				curByIncludeIdx = iterByIncludeIdx->second;
				if( curByIncludeIdx != NULL ) {
					curByIncludeIdx->clear();
					delete curByIncludeIdx;
					curByIncludeIdx = NULL;
					iterByIncludeIdx->second = NULL;
				}
				iterByIncludeIdx ++;
			}
			indexByIncludeIdx->clear();
		}
		if( indexByUIncludeIdx != NULL ) {
			indexByUIncludeIdx->clear();
		}
		if( members != NULL ) {
			cfsec::ICFSecSecGrpIncObj* cur = NULL;
			cfsec::ICFSecSecGrpIncEditObj* edit = NULL;
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

	cfsec::ICFSecSecGrpIncObj* CFSecSecGrpIncTableObj::newInstance() {
		cfsec::ICFSecSecGrpIncObj* inst = dynamic_cast<cfsec::ICFSecSecGrpIncObj*>( new CFSecSecGrpIncObj( schema ) );
		return( inst );
	}

	cfsec::ICFSecSecGrpIncEditObj* CFSecSecGrpIncTableObj::newEditInstance( cfsec::ICFSecSecGrpIncObj* orig ) {
		cfsec::ICFSecSecGrpIncEditObj* edit = dynamic_cast<cfsec::ICFSecSecGrpIncEditObj*>( new CFSecSecGrpIncEditObj( orig ));
		return( edit );
	}

	cfsec::ICFSecSecGrpIncObj* CFSecSecGrpIncTableObj::realizeSecGrpInc( cfsec::ICFSecSecGrpIncObj* Obj ) {
		static const std::string S_ProcName( "realizeSecGrpInc" );
		static const std::string S_ExistingObj( "existingObj" );
		static const std::string S_KeepObj( "keepObj" );
		static const std::string S_Obj( "Obj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfsec::ICFSecSecGrpIncObj* obj = Obj;
		cfsec::ICFSecSecGrpIncObj* existingObj = NULL;
		cfsec::CFSecSecGrpIncPKey* pkey = obj->getPKey();
		cfsec::ICFSecSecGrpIncObj* keepObj = NULL;
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
				cfsec::CFSecSecGrpIncByClusterIdxKey keyClusterIdx;
				keyClusterIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				auto searchClusterIdx = indexByClusterIdx->find( keyClusterIdx );
				if( searchClusterIdx != indexByClusterIdx->end() ) {
					std::map<cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>* mapClusterIdx = searchClusterIdx->second;
					if( mapClusterIdx != NULL ) {
						auto removalProbe = mapClusterIdx->find( *(keepObj->getPKey()) );
						if( removalProbe != mapClusterIdx->end() ) {
							mapClusterIdx->erase( removalProbe );
						}
					}
				}
			}

			if( indexByGroupIdx != NULL ) {
				cfsec::CFSecSecGrpIncByGroupIdxKey keyGroupIdx;
				keyGroupIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				keyGroupIdx.setRequiredSecGroupId( keepObj->getRequiredSecGroupId() );
				auto searchGroupIdx = indexByGroupIdx->find( keyGroupIdx );
				if( searchGroupIdx != indexByGroupIdx->end() ) {
					std::map<cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>* mapGroupIdx = searchGroupIdx->second;
					if( mapGroupIdx != NULL ) {
						auto removalProbe = mapGroupIdx->find( *(keepObj->getPKey()) );
						if( removalProbe != mapGroupIdx->end() ) {
							mapGroupIdx->erase( removalProbe );
						}
					}
				}
			}

			if( indexByIncludeIdx != NULL ) {
				cfsec::CFSecSecGrpIncByIncludeIdxKey keyIncludeIdx;
				keyIncludeIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				keyIncludeIdx.setRequiredIncludeGroupId( keepObj->getRequiredIncludeGroupId() );
				auto searchIncludeIdx = indexByIncludeIdx->find( keyIncludeIdx );
				if( searchIncludeIdx != indexByIncludeIdx->end() ) {
					std::map<cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>* mapIncludeIdx = searchIncludeIdx->second;
					if( mapIncludeIdx != NULL ) {
						auto removalProbe = mapIncludeIdx->find( *(keepObj->getPKey()) );
						if( removalProbe != mapIncludeIdx->end() ) {
							mapIncludeIdx->erase( removalProbe );
						}
					}
				}
			}

			if( indexByUIncludeIdx != NULL ) {
				cfsec::CFSecSecGrpIncByUIncludeIdxKey keyUIncludeIdx;
				keyUIncludeIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				keyUIncludeIdx.setRequiredSecGroupId( keepObj->getRequiredSecGroupId() );
				keyUIncludeIdx.setRequiredIncludeGroupId( keepObj->getRequiredIncludeGroupId() );
				auto removalProbe = indexByUIncludeIdx->find( keyUIncludeIdx );
				if( removalProbe != indexByUIncludeIdx->end() ) {
					indexByUIncludeIdx->erase( removalProbe );
				}
			}

			keepObj->setBuff( dynamic_cast<cfsec::CFSecSecGrpIncBuff*>( Obj->getBuff()->clone() ) );
			// Attach new object to alternate and duplicate indexes -- PKey stays stable

			if( indexByClusterIdx != NULL ) {
				static const std::string S_AClusterIdxObj( "aClusterIdxObj" );
				cfsec::ICFSecSecGrpIncObj* aClusterIdxObj =
					dynamic_cast<cfsec::ICFSecSecGrpIncObj*>( keepObj );
				if( aClusterIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AClusterIdxObj );
				}
				cfsec::CFSecSecGrpIncByClusterIdxKey keyClusterIdx;
				keyClusterIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				auto searchIndexByClusterIdx = indexByClusterIdx->find( keyClusterIdx );
				if( searchIndexByClusterIdx != indexByClusterIdx->end() ) {
					std::map<cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>* mapClusterIdx = searchIndexByClusterIdx->second;
					if( mapClusterIdx != NULL ) {
						mapClusterIdx->insert( std::map< cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj* >::value_type( *(keepObj->getPKey()), aClusterIdxObj ) );
					}
				}
			}

			if( indexByGroupIdx != NULL ) {
				static const std::string S_AGroupIdxObj( "aGroupIdxObj" );
				cfsec::ICFSecSecGrpIncObj* aGroupIdxObj =
					dynamic_cast<cfsec::ICFSecSecGrpIncObj*>( keepObj );
				if( aGroupIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AGroupIdxObj );
				}
				cfsec::CFSecSecGrpIncByGroupIdxKey keyGroupIdx;
				keyGroupIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				keyGroupIdx.setRequiredSecGroupId( keepObj->getRequiredSecGroupId() );
				auto searchIndexByGroupIdx = indexByGroupIdx->find( keyGroupIdx );
				if( searchIndexByGroupIdx != indexByGroupIdx->end() ) {
					std::map<cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>* mapGroupIdx = searchIndexByGroupIdx->second;
					if( mapGroupIdx != NULL ) {
						mapGroupIdx->insert( std::map< cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj* >::value_type( *(keepObj->getPKey()), aGroupIdxObj ) );
					}
				}
			}

			if( indexByIncludeIdx != NULL ) {
				static const std::string S_AIncludeIdxObj( "aIncludeIdxObj" );
				cfsec::ICFSecSecGrpIncObj* aIncludeIdxObj =
					dynamic_cast<cfsec::ICFSecSecGrpIncObj*>( keepObj );
				if( aIncludeIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AIncludeIdxObj );
				}
				cfsec::CFSecSecGrpIncByIncludeIdxKey keyIncludeIdx;
				keyIncludeIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				keyIncludeIdx.setRequiredIncludeGroupId( keepObj->getRequiredIncludeGroupId() );
				auto searchIndexByIncludeIdx = indexByIncludeIdx->find( keyIncludeIdx );
				if( searchIndexByIncludeIdx != indexByIncludeIdx->end() ) {
					std::map<cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>* mapIncludeIdx = searchIndexByIncludeIdx->second;
					if( mapIncludeIdx != NULL ) {
						mapIncludeIdx->insert( std::map< cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj* >::value_type( *(keepObj->getPKey()), aIncludeIdxObj ) );
					}
				}
			}

			if( indexByUIncludeIdx != NULL ) {
				static const std::string S_AUIncludeIdxObj( "aUIncludeIdxObj" );
				cfsec::ICFSecSecGrpIncObj* aUIncludeIdxObj =
					dynamic_cast<cfsec::ICFSecSecGrpIncObj*>( keepObj );
				if( aUIncludeIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AUIncludeIdxObj );
				}
				cfsec::CFSecSecGrpIncByUIncludeIdxKey keyUIncludeIdx;
				keyUIncludeIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				keyUIncludeIdx.setRequiredSecGroupId( keepObj->getRequiredSecGroupId() );
				keyUIncludeIdx.setRequiredIncludeGroupId( keepObj->getRequiredIncludeGroupId() );
				indexByUIncludeIdx->insert( std::map< cfsec::CFSecSecGrpIncByUIncludeIdxKey, cfsec::ICFSecSecGrpIncObj* >::value_type( keyUIncludeIdx, aUIncludeIdxObj ) );
			}

			if( allSecGrpInc != NULL ) {
				allSecGrpInc->insert( std::map< cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			}
		}
		else {
			keepObj = obj;
			keepObj->setIsNew( false );
			pkey = keepObj->getPKey();
			// Attach new object to PKey, all, alternate, and duplicate indexes
			members->insert( std::map< cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			// Attach new object to alternate and duplicate indexes -- PKey stay stable

			if( indexByClusterIdx != NULL ) {
				static const std::string S_AClusterIdxObj( "aClusterIdxObj" );
				cfsec::ICFSecSecGrpIncObj* aClusterIdxObj =
					dynamic_cast<cfsec::ICFSecSecGrpIncObj*>( keepObj );
				if( aClusterIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AClusterIdxObj );
				}
				cfsec::CFSecSecGrpIncByClusterIdxKey keyClusterIdx;
				keyClusterIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				auto searchIndexByClusterIdx = indexByClusterIdx->find( keyClusterIdx );
				if( searchIndexByClusterIdx != indexByClusterIdx->end() ) {
					std::map<cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>* mapClusterIdx = searchIndexByClusterIdx->second;
					if( mapClusterIdx != NULL ) {
						mapClusterIdx->insert( std::map< cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj* >::value_type( *(keepObj->getPKey()), aClusterIdxObj ) );
					}
				}
			}

			if( indexByGroupIdx != NULL ) {
				static const std::string S_AGroupIdxObj( "aGroupIdxObj" );
				cfsec::ICFSecSecGrpIncObj* aGroupIdxObj =
					dynamic_cast<cfsec::ICFSecSecGrpIncObj*>( keepObj );
				if( aGroupIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AGroupIdxObj );
				}
				cfsec::CFSecSecGrpIncByGroupIdxKey keyGroupIdx;
				keyGroupIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				keyGroupIdx.setRequiredSecGroupId( keepObj->getRequiredSecGroupId() );
				auto searchIndexByGroupIdx = indexByGroupIdx->find( keyGroupIdx );
				if( searchIndexByGroupIdx != indexByGroupIdx->end() ) {
					std::map<cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>* mapGroupIdx = searchIndexByGroupIdx->second;
					if( mapGroupIdx != NULL ) {
						mapGroupIdx->insert( std::map< cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj* >::value_type( *(keepObj->getPKey()), aGroupIdxObj ) );
					}
				}
			}

			if( indexByIncludeIdx != NULL ) {
				static const std::string S_AIncludeIdxObj( "aIncludeIdxObj" );
				cfsec::ICFSecSecGrpIncObj* aIncludeIdxObj =
					dynamic_cast<cfsec::ICFSecSecGrpIncObj*>( keepObj );
				if( aIncludeIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AIncludeIdxObj );
				}
				cfsec::CFSecSecGrpIncByIncludeIdxKey keyIncludeIdx;
				keyIncludeIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				keyIncludeIdx.setRequiredIncludeGroupId( keepObj->getRequiredIncludeGroupId() );
				auto searchIndexByIncludeIdx = indexByIncludeIdx->find( keyIncludeIdx );
				if( searchIndexByIncludeIdx != indexByIncludeIdx->end() ) {
					std::map<cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>* mapIncludeIdx = searchIndexByIncludeIdx->second;
					if( mapIncludeIdx != NULL ) {
						mapIncludeIdx->insert( std::map< cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj* >::value_type( *(keepObj->getPKey()), aIncludeIdxObj ) );
					}
				}
			}

			if( indexByUIncludeIdx != NULL ) {
				static const std::string S_AUIncludeIdxObj( "aUIncludeIdxObj" );
				cfsec::ICFSecSecGrpIncObj* aUIncludeIdxObj =
					dynamic_cast<cfsec::ICFSecSecGrpIncObj*>( keepObj );
				if( aUIncludeIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AUIncludeIdxObj );
				}
				cfsec::CFSecSecGrpIncByUIncludeIdxKey keyUIncludeIdx;
				keyUIncludeIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				keyUIncludeIdx.setRequiredSecGroupId( keepObj->getRequiredSecGroupId() );
				keyUIncludeIdx.setRequiredIncludeGroupId( keepObj->getRequiredIncludeGroupId() );
				indexByUIncludeIdx->insert( std::map< cfsec::CFSecSecGrpIncByUIncludeIdxKey, cfsec::ICFSecSecGrpIncObj* >::value_type( keyUIncludeIdx, aUIncludeIdxObj ) );
			}

			if( allSecGrpInc != NULL ) {
				allSecGrpInc->insert( std::map< cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
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

	void CFSecSecGrpIncTableObj::deepDisposeByIdIdx( const int64_t ClusterId,
			const int64_t SecGrpIncId ) {
		static const std::string S_ProcName( "deepDisposeByIdIdx" );
		std::vector<cfsec::ICFSecSecGrpIncObj*> list;
		cfsec::ICFSecSecGrpIncObj* existingObj = readCachedSecGrpIncByIdIdx( ClusterId,
				SecGrpIncId );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfsec::ICFSecSecGrpIncObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecSecGrpIncBuff::CLASS_CODE ) {
					dynamic_cast<cfsec::CFSecSecGrpIncTableObj*>( schema->getSecGrpIncTableObj() )->reallyDeepDisposeSecGrpInc( dynamic_cast<cfsec::ICFSecSecGrpIncObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFSecSecGrpIncTableObj::deepDisposeByClusterIdx( const int64_t ClusterId ) {
		static const std::string S_ProcName( "deepDisposeByClusterIdx" );
		std::vector<cfsec::ICFSecSecGrpIncObj*> list;
		std::vector<cfsec::ICFSecSecGrpIncObj*> matchesFound = readCachedSecGrpIncByClusterIdx( ClusterId );
		auto iterMatches = matchesFound.begin();
		auto endMatches = matchesFound.end();
		while( iterMatches != endMatches ) {
			if( *iterMatches != NULL ) {
				list.push_back( *iterMatches );
			}
			iterMatches ++;
		}
		cfsec::ICFSecSecGrpIncObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecSecGrpIncBuff::CLASS_CODE ) {
					dynamic_cast<cfsec::CFSecSecGrpIncTableObj*>( schema->getSecGrpIncTableObj() )->reallyDeepDisposeSecGrpInc( dynamic_cast<cfsec::ICFSecSecGrpIncObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFSecSecGrpIncTableObj::deepDisposeByGroupIdx( const int64_t ClusterId,
			const int32_t SecGroupId ) {
		static const std::string S_ProcName( "deepDisposeByGroupIdx" );
		std::vector<cfsec::ICFSecSecGrpIncObj*> list;
		std::vector<cfsec::ICFSecSecGrpIncObj*> matchesFound = readCachedSecGrpIncByGroupIdx( ClusterId,
				SecGroupId );
		auto iterMatches = matchesFound.begin();
		auto endMatches = matchesFound.end();
		while( iterMatches != endMatches ) {
			if( *iterMatches != NULL ) {
				list.push_back( *iterMatches );
			}
			iterMatches ++;
		}
		cfsec::ICFSecSecGrpIncObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecSecGrpIncBuff::CLASS_CODE ) {
					dynamic_cast<cfsec::CFSecSecGrpIncTableObj*>( schema->getSecGrpIncTableObj() )->reallyDeepDisposeSecGrpInc( dynamic_cast<cfsec::ICFSecSecGrpIncObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFSecSecGrpIncTableObj::deepDisposeByIncludeIdx( const int64_t ClusterId,
			const int32_t IncludeGroupId ) {
		static const std::string S_ProcName( "deepDisposeByIncludeIdx" );
		std::vector<cfsec::ICFSecSecGrpIncObj*> list;
		std::vector<cfsec::ICFSecSecGrpIncObj*> matchesFound = readCachedSecGrpIncByIncludeIdx( ClusterId,
				IncludeGroupId );
		auto iterMatches = matchesFound.begin();
		auto endMatches = matchesFound.end();
		while( iterMatches != endMatches ) {
			if( *iterMatches != NULL ) {
				list.push_back( *iterMatches );
			}
			iterMatches ++;
		}
		cfsec::ICFSecSecGrpIncObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecSecGrpIncBuff::CLASS_CODE ) {
					dynamic_cast<cfsec::CFSecSecGrpIncTableObj*>( schema->getSecGrpIncTableObj() )->reallyDeepDisposeSecGrpInc( dynamic_cast<cfsec::ICFSecSecGrpIncObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFSecSecGrpIncTableObj::deepDisposeByUIncludeIdx( const int64_t ClusterId,
			const int32_t SecGroupId,
			const int32_t IncludeGroupId ) {
		static const std::string S_ProcName( "deepDisposeByUIncludeIdx" );
		std::vector<cfsec::ICFSecSecGrpIncObj*> list;
		cfsec::ICFSecSecGrpIncObj* existingObj = readCachedSecGrpIncByUIncludeIdx( ClusterId,
				SecGroupId,
				IncludeGroupId );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfsec::ICFSecSecGrpIncObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecSecGrpIncBuff::CLASS_CODE ) {
					dynamic_cast<cfsec::CFSecSecGrpIncTableObj*>( schema->getSecGrpIncTableObj() )->reallyDeepDisposeSecGrpInc( dynamic_cast<cfsec::ICFSecSecGrpIncObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFSecSecGrpIncTableObj::reallyDeepDisposeSecGrpInc( cfsec::ICFSecSecGrpIncObj* Obj ) {
		static const std::string S_ProcName( "reallyDeepDisposeSecGrpInc" );

		if( Obj == NULL ) {
			return;
		}

		cfsec::ICFSecSecGrpIncObj* obj = Obj;
		
		classcode_t classCode = obj->getClassCode();
		if( classCode == cfsec::CFSecSecGrpIncBuff::CLASS_CODE ) {
			dynamic_cast<cfsec::CFSecSecGrpIncTableObj*>( schema->getSecGrpIncTableObj() )->reallyDetachFromIndexesSecGrpInc( dynamic_cast<cfsec::ICFSecSecGrpIncObj*>( obj ) );
		}

		if( obj->getEdit() != NULL ) {
			obj->endEdit();
		}
		delete obj;
		obj = NULL;
	}

	cfsec::ICFSecSecGrpIncObj* CFSecSecGrpIncTableObj::createSecGrpInc( cfsec::ICFSecSecGrpIncEditObj* Obj ) {
		static const std::string S_ProcName( "createSecGrpInc" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Cloneable( "cloneable" );
		static const std::string S_ClonedBuff( "clonedbuff" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecSecGrpIncObj* obj = dynamic_cast<cfsec::ICFSecSecGrpIncObj*>( Obj->getOrig() );
		try {
			cfsec::CFSecSecGrpIncBuff* buff = dynamic_cast<cfsec::CFSecSecGrpIncBuff*>( Obj->getBuff()->clone() );
			// C++18 version of create returns a new buffer instance and takes over ownership of the passed-in buffer
			// MSS TODO WORKING The xmsg client will need to return the buffer instance created by processing
			// the response message, while xmsg rqst will have to delete the backing store instance
			// it receives after preparing the reply message so that memory doesn't leak on every request.
			cflib::ICFLibCloneableObj* cloneable = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecGrpInc()->createSecGrpInc(
				schema->getAuthorization(),
				buff );
			if( cloneable == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Cloneable );
			}
			Obj->endEdit();
			obj->setBuff( dynamic_cast<cfsec::CFSecSecGrpIncBuff*>( cloneable ) );
			obj = dynamic_cast<cfsec::ICFSecSecGrpIncObj*>( obj->realize() );
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

	cfsec::ICFSecSecGrpIncObj* CFSecSecGrpIncTableObj::readSecGrpInc( cfsec::CFSecSecGrpIncPKey* pkey, bool forceRead ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readSecGrpInc" );
		cfsec::ICFSecSecGrpIncObj* obj = NULL;
		cfsec::ICFSecSecGrpIncObj* realized = NULL;
		if( ! forceRead ) {
			auto searchMembers = members->find( *pkey );
			if( searchMembers != members->end() ) {
				// obj could be NULL if cache misses is enabled
				obj = searchMembers->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecSecGrpIncBuff* readBuff = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecGrpInc()->readDerivedByIdIdx( schema->getAuthorization(),
			pkey->getRequiredClusterId(),
			pkey->getRequiredSecGrpIncId() );
			if( readBuff != NULL ) {
			obj = dynamic_cast<cfsec::CFSecSecGrpIncTableObj*>( schema->getSecGrpIncTableObj() )->newInstance();
				obj->setBuff( readBuff );
				realized = dynamic_cast<cfsec::ICFSecSecGrpIncObj*>( obj->realize() );
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

	cfsec::ICFSecSecGrpIncObj* CFSecSecGrpIncTableObj::lockSecGrpInc( cfsec::CFSecSecGrpIncPKey* pkey ) {
		static const std::string S_ProcName( "lockSecGrpInc" );
		cfsec::ICFSecSecGrpIncObj* locked = NULL;
		cfsec::CFSecSecGrpIncBuff* lockBuff = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecGrpInc()->lockDerived( schema->getAuthorization(), pkey );
		if( lockBuff != NULL ) {
			locked = dynamic_cast<cfsec::CFSecSecGrpIncTableObj*>( schema->getSecGrpIncTableObj() )->newInstance();
			locked->setBuff( lockBuff );
			locked = dynamic_cast<cfsec::ICFSecSecGrpIncObj*>( locked->realize() );
		}
		else {
			return( NULL );
		}
		return( locked );
	}

	std::vector<cfsec::ICFSecSecGrpIncObj*> CFSecSecGrpIncTableObj::readAllSecGrpInc( bool forceRead ) {
		static const std::string S_ProcName( "readAllSecGrpInc" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Realized( "realized" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecSecGrpIncObj* realized = NULL;
		if( forceRead || ( allSecGrpInc == NULL ) ) {
			std::map<cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>* map = new std::map<cfsec::CFSecSecGrpIncPKey,cfsec::ICFSecSecGrpIncObj*>();
			allSecGrpInc = map;
			std::TCFLibOwningVector<cfsec::CFSecSecGrpIncBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecGrpInc()->readAllDerived( schema->getAuthorization() );
			cfsec::CFSecSecGrpIncBuff* buff = NULL;
			cfsec::ICFSecSecGrpIncObj* obj = NULL;
			try {
				for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
					buff = buffList[ idx ];
					buffList[ idx ] = NULL;
				obj = newInstance();
					obj->setBuff( buff );
					realized = dynamic_cast<cfsec::ICFSecSecGrpIncObj*>( obj->realize() );
					if( realized == NULL ) {
						throw cflib::CFLibNullArgumentException( CLASS_NAME,
							S_ProcName,
							0,
							S_Realized );
					}
					allSecGrpInc->insert( std::map< cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj* >::value_type( *(realized->getPKey()), realized ) );
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
		size_t len = allSecGrpInc->size();
		std::vector<cfsec::ICFSecSecGrpIncObj*> arr;
		auto valIter = allSecGrpInc->begin();
		size_t idx = 0;
		while( valIter != allSecGrpInc->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	std::vector<cfsec::ICFSecSecGrpIncObj*> CFSecSecGrpIncTableObj::pageAllSecGrpInc(const int64_t* priorClusterId,
			const int64_t* priorSecGrpIncId )
	{
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "pageAllSecGrpInc" );
		CFLIB_EXCEPTION_DECLINFO
		std::map<cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>* map = NULL;
		cfsec::CFSecSecGrpIncBuff* buff = NULL;
		cfsec::ICFSecSecGrpIncObj* obj = NULL;
		cfsec::ICFSecSecGrpIncObj* realized = NULL;
		std::vector<cfsec::ICFSecSecGrpIncObj*> arrayList;
		try {
			map = new std::map<cfsec::CFSecSecGrpIncPKey,cfsec::ICFSecSecGrpIncObj*>();
			std::TCFLibOwningVector<cfsec::CFSecSecGrpIncBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecGrpInc()->pageAllBuff( schema->getAuthorization(),
				priorClusterId,
				priorSecGrpIncId );
			arrayList.reserve( buffList.size() );
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = newInstance();
				obj->setBuff( buff );
				realized = dynamic_cast<cfsec::ICFSecSecGrpIncObj*>( obj->realize() );
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

	cfsec::ICFSecSecGrpIncObj* CFSecSecGrpIncTableObj::readSecGrpIncByIdIdx( const int64_t ClusterId,
			const int64_t SecGrpIncId, bool forceRead )
	{
		static const std::string S_ProcName( "readSecGrpIncByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSecGrpIncPKey pkey;
		pkey.setRequiredClusterId( ClusterId );
		pkey.setRequiredSecGrpIncId( SecGrpIncId );
		cfsec::ICFSecSecGrpIncObj* obj = readSecGrpInc( &pkey, forceRead );
		return( obj );
	}

	std::vector<cfsec::ICFSecSecGrpIncObj*> CFSecSecGrpIncTableObj::readSecGrpIncByClusterIdx( const int64_t ClusterId,
		bool forceRead )
	{
		static const std::string S_ProcName( "readSecGrpIncByClusterIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSecGrpIncByClusterIdxKey key;
		key.setRequiredClusterId( ClusterId );
		std::map<cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>* dict;
		std::map<cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>* oldDict;
		if( indexByClusterIdx == NULL ) {
			indexByClusterIdx = new std::map< cfsec::CFSecSecGrpIncByClusterIdxKey,
				std::map< cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>*>();
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
			dict = new std::map<cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>();
			cfsec::ICFSecSecGrpIncObj* obj;
			std::TCFLibOwningVector<cfsec::CFSecSecGrpIncBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecGrpInc()->readDerivedByClusterIdx( schema->getAuthorization(),
				ClusterId );
			cfsec::CFSecSecGrpIncBuff* buff;
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = dynamic_cast<cfsec::CFSecSecGrpIncTableObj*>( schema->getSecGrpIncTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
				obj->setBuff( buff );
				cfsec::ICFSecSecGrpIncObj* realized = dynamic_cast<cfsec::ICFSecSecGrpIncObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				dict->insert( std::map< cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj* >::value_type( *(realized->getPKey()), realized ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = NULL;
			}
			if( oldDict != NULL ) {
				indexByClusterIdx->erase( searchIndexByClusterIdx );
				delete oldDict;
				oldDict = NULL;
			}
			indexByClusterIdx->insert( std::map< cfsec::CFSecSecGrpIncByClusterIdxKey,
				std::map< cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj* >* >::value_type( key, dict ) );
		}
		size_t len = dict->size();
		std::vector<cfsec::ICFSecSecGrpIncObj*> arr;
		arr.reserve( len );
		auto valIter = dict->begin();
		while( valIter != dict->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	std::vector<cfsec::ICFSecSecGrpIncObj*> CFSecSecGrpIncTableObj::readSecGrpIncByGroupIdx( const int64_t ClusterId,
			const int32_t SecGroupId,
		bool forceRead )
	{
		static const std::string S_ProcName( "readSecGrpIncByGroupIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSecGrpIncByGroupIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredSecGroupId( SecGroupId );
		std::map<cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>* dict;
		std::map<cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>* oldDict;
		if( indexByGroupIdx == NULL ) {
			indexByGroupIdx = new std::map< cfsec::CFSecSecGrpIncByGroupIdxKey,
				std::map< cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>*>();
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
			dict = new std::map<cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>();
			cfsec::ICFSecSecGrpIncObj* obj;
			std::TCFLibOwningVector<cfsec::CFSecSecGrpIncBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecGrpInc()->readDerivedByGroupIdx( schema->getAuthorization(),
				ClusterId,
				SecGroupId );
			cfsec::CFSecSecGrpIncBuff* buff;
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = dynamic_cast<cfsec::CFSecSecGrpIncTableObj*>( schema->getSecGrpIncTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
				obj->setBuff( buff );
				cfsec::ICFSecSecGrpIncObj* realized = dynamic_cast<cfsec::ICFSecSecGrpIncObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				dict->insert( std::map< cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj* >::value_type( *(realized->getPKey()), realized ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = NULL;
			}
			if( oldDict != NULL ) {
				indexByGroupIdx->erase( searchIndexByGroupIdx );
				delete oldDict;
				oldDict = NULL;
			}
			indexByGroupIdx->insert( std::map< cfsec::CFSecSecGrpIncByGroupIdxKey,
				std::map< cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj* >* >::value_type( key, dict ) );
		}
		size_t len = dict->size();
		std::vector<cfsec::ICFSecSecGrpIncObj*> arr;
		arr.reserve( len );
		auto valIter = dict->begin();
		while( valIter != dict->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	std::vector<cfsec::ICFSecSecGrpIncObj*> CFSecSecGrpIncTableObj::readSecGrpIncByIncludeIdx( const int64_t ClusterId,
			const int32_t IncludeGroupId,
		bool forceRead )
	{
		static const std::string S_ProcName( "readSecGrpIncByIncludeIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSecGrpIncByIncludeIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredIncludeGroupId( IncludeGroupId );
		std::map<cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>* dict;
		std::map<cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>* oldDict;
		if( indexByIncludeIdx == NULL ) {
			indexByIncludeIdx = new std::map< cfsec::CFSecSecGrpIncByIncludeIdxKey,
				std::map< cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>*>();
		}
		auto searchIndexByIncludeIdx = indexByIncludeIdx->find( key );
		if( searchIndexByIncludeIdx != indexByIncludeIdx->end() ) {
			oldDict = searchIndexByIncludeIdx->second;
		}
		else {
			oldDict = NULL;
		}
		if( ( oldDict != NULL ) && ( ! forceRead ) ) {
			dict = oldDict;
		}
		else {
			dict = new std::map<cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>();
			cfsec::ICFSecSecGrpIncObj* obj;
			std::TCFLibOwningVector<cfsec::CFSecSecGrpIncBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecGrpInc()->readDerivedByIncludeIdx( schema->getAuthorization(),
				ClusterId,
				IncludeGroupId );
			cfsec::CFSecSecGrpIncBuff* buff;
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = dynamic_cast<cfsec::CFSecSecGrpIncTableObj*>( schema->getSecGrpIncTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
				obj->setBuff( buff );
				cfsec::ICFSecSecGrpIncObj* realized = dynamic_cast<cfsec::ICFSecSecGrpIncObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				dict->insert( std::map< cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj* >::value_type( *(realized->getPKey()), realized ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = NULL;
			}
			if( oldDict != NULL ) {
				indexByIncludeIdx->erase( searchIndexByIncludeIdx );
				delete oldDict;
				oldDict = NULL;
			}
			indexByIncludeIdx->insert( std::map< cfsec::CFSecSecGrpIncByIncludeIdxKey,
				std::map< cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj* >* >::value_type( key, dict ) );
		}
		size_t len = dict->size();
		std::vector<cfsec::ICFSecSecGrpIncObj*> arr;
		arr.reserve( len );
		auto valIter = dict->begin();
		while( valIter != dict->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	cfsec::ICFSecSecGrpIncObj* CFSecSecGrpIncTableObj::readSecGrpIncByUIncludeIdx( const int64_t ClusterId,
			const int32_t SecGroupId,
			const int32_t IncludeGroupId, bool forceRead )
	{
		static const std::string S_ProcName( "readSecGrpIncByUIncludeIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByUIncludeIdx == NULL ) {
			indexByUIncludeIdx = new std::map< cfsec::CFSecSecGrpIncByUIncludeIdxKey,
				cfsec::ICFSecSecGrpIncObj*>();
		}
		cfsec::CFSecSecGrpIncByUIncludeIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredSecGroupId( SecGroupId );
		key.setRequiredIncludeGroupId( IncludeGroupId );
		cfsec::ICFSecSecGrpIncObj* obj = NULL;
		cfsec::ICFSecSecGrpIncObj* realized = NULL;
		if( ! forceRead ) {
			auto searchIndexByUIncludeIdx = indexByUIncludeIdx->find( key );
			if( searchIndexByUIncludeIdx != indexByUIncludeIdx->end() ) {
				// Note: obj may be null if cache misses is enabled
				obj = searchIndexByUIncludeIdx->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecSecGrpIncBuff* buff = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecGrpInc()->readDerivedByUIncludeIdx( schema->getAuthorization(),
				ClusterId,
				SecGroupId,
				IncludeGroupId );
			if( buff != NULL ) {
				obj = dynamic_cast<cfsec::CFSecSecGrpIncTableObj*>( schema->getSecGrpIncTableObj() )->newInstance();
				obj->setBuff( buff );
				realized = dynamic_cast<cfsec::ICFSecSecGrpIncObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				indexByUIncludeIdx->insert( std::map< cfsec::CFSecSecGrpIncByUIncludeIdxKey, cfsec::ICFSecSecGrpIncObj*>::value_type( key, dynamic_cast<cfsec::ICFSecSecGrpIncObj*>( realized ) ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = realized;
			}
		}
		return( obj );
	}

	cfsec::ICFSecSecGrpIncObj* CFSecSecGrpIncTableObj::readCachedSecGrpInc( cfsec::CFSecSecGrpIncPKey* pkey ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readSecGrpInc" );
		cfsec::ICFSecSecGrpIncObj* obj = NULL;
		cfsec::ICFSecSecGrpIncObj* realized = NULL;
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			// obj could be NULL if cache misses is enabled
			obj = searchMembers->second;
			realized = obj;
		}
		return( realized );
	}

	cfsec::ICFSecSecGrpIncObj* CFSecSecGrpIncTableObj::readCachedSecGrpIncByIdIdx( const int64_t ClusterId,
			const int64_t SecGrpIncId )
	{
		static const std::string S_ProcName( "readCachedSecGrpIncByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSecGrpIncPKey pkey;
		pkey.setRequiredClusterId( ClusterId );
		pkey.setRequiredSecGrpIncId( SecGrpIncId );
		cfsec::ICFSecSecGrpIncObj* obj = readCachedSecGrpInc( &pkey );
		return( obj );
	}

	std::vector<cfsec::ICFSecSecGrpIncObj*> CFSecSecGrpIncTableObj::readCachedSecGrpIncByClusterIdx( const int64_t ClusterId )
	{
		static const std::string S_ProcName( "readCachedSecGrpIncByClusterIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		std::vector<cfsec::ICFSecSecGrpIncObj*> arr;
		cfsec::CFSecSecGrpIncByClusterIdxKey key;
		key.setRequiredClusterId( ClusterId );
		std::map<cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>* dict;
		if( indexByClusterIdx == NULL ) {
			return( arr );
		}
		auto searchIndexByClusterIdx = indexByClusterIdx->find( key );
		if( searchIndexByClusterIdx != indexByClusterIdx->end() ) {
			dict = searchIndexByClusterIdx->second;
			size_t len = dict->size();
			std::vector<cfsec::ICFSecSecGrpIncObj*> arr;
			arr.reserve( len );
			auto valIter = dict->begin();
			while( valIter != dict->end() ) {
				arr.push_back( valIter->second );
				valIter ++;
			}
		}
		else {
			cfsec::ICFSecSecGrpIncObj* obj;
			for( auto iterMembers = members->begin(); iterMembers != members->end(); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecSecGrpIncBuff*>( obj->getBuff() ) ) == key ) {
						arr.push_back( obj );
					}
				}
			}
		}
		return( arr );
	}

	std::vector<cfsec::ICFSecSecGrpIncObj*> CFSecSecGrpIncTableObj::readCachedSecGrpIncByGroupIdx( const int64_t ClusterId,
			const int32_t SecGroupId )
	{
		static const std::string S_ProcName( "readCachedSecGrpIncByGroupIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		std::vector<cfsec::ICFSecSecGrpIncObj*> arr;
		cfsec::CFSecSecGrpIncByGroupIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredSecGroupId( SecGroupId );
		std::map<cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>* dict;
		if( indexByGroupIdx == NULL ) {
			return( arr );
		}
		auto searchIndexByGroupIdx = indexByGroupIdx->find( key );
		if( searchIndexByGroupIdx != indexByGroupIdx->end() ) {
			dict = searchIndexByGroupIdx->second;
			size_t len = dict->size();
			std::vector<cfsec::ICFSecSecGrpIncObj*> arr;
			arr.reserve( len );
			auto valIter = dict->begin();
			while( valIter != dict->end() ) {
				arr.push_back( valIter->second );
				valIter ++;
			}
		}
		else {
			cfsec::ICFSecSecGrpIncObj* obj;
			for( auto iterMembers = members->begin(); iterMembers != members->end(); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecSecGrpIncBuff*>( obj->getBuff() ) ) == key ) {
						arr.push_back( obj );
					}
				}
			}
		}
		return( arr );
	}

	std::vector<cfsec::ICFSecSecGrpIncObj*> CFSecSecGrpIncTableObj::readCachedSecGrpIncByIncludeIdx( const int64_t ClusterId,
			const int32_t IncludeGroupId )
	{
		static const std::string S_ProcName( "readCachedSecGrpIncByIncludeIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		std::vector<cfsec::ICFSecSecGrpIncObj*> arr;
		cfsec::CFSecSecGrpIncByIncludeIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredIncludeGroupId( IncludeGroupId );
		std::map<cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>* dict;
		if( indexByIncludeIdx == NULL ) {
			return( arr );
		}
		auto searchIndexByIncludeIdx = indexByIncludeIdx->find( key );
		if( searchIndexByIncludeIdx != indexByIncludeIdx->end() ) {
			dict = searchIndexByIncludeIdx->second;
			size_t len = dict->size();
			std::vector<cfsec::ICFSecSecGrpIncObj*> arr;
			arr.reserve( len );
			auto valIter = dict->begin();
			while( valIter != dict->end() ) {
				arr.push_back( valIter->second );
				valIter ++;
			}
		}
		else {
			cfsec::ICFSecSecGrpIncObj* obj;
			for( auto iterMembers = members->begin(); iterMembers != members->end(); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecSecGrpIncBuff*>( obj->getBuff() ) ) == key ) {
						arr.push_back( obj );
					}
				}
			}
		}
		return( arr );
	}

	cfsec::ICFSecSecGrpIncObj* CFSecSecGrpIncTableObj::readCachedSecGrpIncByUIncludeIdx( const int64_t ClusterId,
			const int32_t SecGroupId,
			const int32_t IncludeGroupId )
	{
		static const std::string S_ProcName( "readCachedSecGrpIncByUIncludeIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByUIncludeIdx == NULL ) {
			indexByUIncludeIdx = new std::map< cfsec::CFSecSecGrpIncByUIncludeIdxKey,
				cfsec::ICFSecSecGrpIncObj*>();
		}
		cfsec::CFSecSecGrpIncByUIncludeIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredSecGroupId( SecGroupId );
		key.setRequiredIncludeGroupId( IncludeGroupId );
		cfsec::ICFSecSecGrpIncObj* obj = NULL;
		auto searchIndexByUIncludeIdx = indexByUIncludeIdx->find( key );
		if( searchIndexByUIncludeIdx != indexByUIncludeIdx->end() ) {
			// Note: obj may be null if cache misses is enabled
			obj = searchIndexByUIncludeIdx->second;
		}
		else {
			for( auto iterMembers = members->begin(); ( obj == NULL ) && ( iterMembers != members->end() ); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecSecGrpIncBuff*>( obj->getBuff() ) ) != key ) {
						obj = NULL;
					}
				}
			}
		}
		return( obj );
	}

	std::vector<cfsec::ICFSecSecGrpIncObj*> CFSecSecGrpIncTableObj::pageSecGrpIncByClusterIdx( const int64_t ClusterId,
			const int64_t* priorClusterId,
			const int64_t* priorSecGrpIncId )
	{
		static const std::string S_ProcName( "pageSecGrpIncByClusterIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSecGrpIncByClusterIdxKey key;
		key.setRequiredClusterId( ClusterId );
		cfsec::ICFSecSecGrpIncObj* obj;
		std::TCFLibOwningVector<cfsec::CFSecSecGrpIncBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecGrpInc()->pageBuffByClusterIdx( schema->getAuthorization(),
				ClusterId,
				priorClusterId,
				priorSecGrpIncId );
		std::vector<cfsec::ICFSecSecGrpIncObj*> retList;
		retList.reserve( buffList.size() );
		cfsec::CFSecSecGrpIncBuff* buff;
		cfsec::ICFSecSecGrpIncObj* realized;
		for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
			buff = buffList[ idx ];
			buffList[ idx ] = NULL;
				obj = dynamic_cast<cfsec::CFSecSecGrpIncTableObj*>( schema->getSecGrpIncTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
			obj->setBuff( buff );
			realized = dynamic_cast<cfsec::ICFSecSecGrpIncObj*>( obj->realize() );
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

	std::vector<cfsec::ICFSecSecGrpIncObj*> CFSecSecGrpIncTableObj::pageSecGrpIncByGroupIdx( const int64_t ClusterId,
			const int32_t SecGroupId,
			const int64_t* priorClusterId,
			const int64_t* priorSecGrpIncId )
	{
		static const std::string S_ProcName( "pageSecGrpIncByGroupIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSecGrpIncByGroupIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredSecGroupId( SecGroupId );
		cfsec::ICFSecSecGrpIncObj* obj;
		std::TCFLibOwningVector<cfsec::CFSecSecGrpIncBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecGrpInc()->pageBuffByGroupIdx( schema->getAuthorization(),
				ClusterId,
				SecGroupId,
				priorClusterId,
				priorSecGrpIncId );
		std::vector<cfsec::ICFSecSecGrpIncObj*> retList;
		retList.reserve( buffList.size() );
		cfsec::CFSecSecGrpIncBuff* buff;
		cfsec::ICFSecSecGrpIncObj* realized;
		for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
			buff = buffList[ idx ];
			buffList[ idx ] = NULL;
				obj = dynamic_cast<cfsec::CFSecSecGrpIncTableObj*>( schema->getSecGrpIncTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
			obj->setBuff( buff );
			realized = dynamic_cast<cfsec::ICFSecSecGrpIncObj*>( obj->realize() );
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

	std::vector<cfsec::ICFSecSecGrpIncObj*> CFSecSecGrpIncTableObj::pageSecGrpIncByIncludeIdx( const int64_t ClusterId,
			const int32_t IncludeGroupId,
			const int64_t* priorClusterId,
			const int64_t* priorSecGrpIncId )
	{
		static const std::string S_ProcName( "pageSecGrpIncByIncludeIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSecGrpIncByIncludeIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredIncludeGroupId( IncludeGroupId );
		cfsec::ICFSecSecGrpIncObj* obj;
		std::TCFLibOwningVector<cfsec::CFSecSecGrpIncBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecGrpInc()->pageBuffByIncludeIdx( schema->getAuthorization(),
				ClusterId,
				IncludeGroupId,
				priorClusterId,
				priorSecGrpIncId );
		std::vector<cfsec::ICFSecSecGrpIncObj*> retList;
		retList.reserve( buffList.size() );
		cfsec::CFSecSecGrpIncBuff* buff;
		cfsec::ICFSecSecGrpIncObj* realized;
		for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
			buff = buffList[ idx ];
			buffList[ idx ] = NULL;
				obj = dynamic_cast<cfsec::CFSecSecGrpIncTableObj*>( schema->getSecGrpIncTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
			obj->setBuff( buff );
			realized = dynamic_cast<cfsec::ICFSecSecGrpIncObj*>( obj->realize() );
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

	cfsec::ICFSecSecGrpIncObj* CFSecSecGrpIncTableObj::updateSecGrpInc( cfsec::ICFSecSecGrpIncEditObj* Obj ) {
		static const std::string S_ProcName( "updateSecGrpInc" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Updated( "updated" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecSecGrpIncObj* obj = dynamic_cast<cfsec::ICFSecSecGrpIncObj*>( Obj->getOrig() );
		try {
			cfsec::CFSecSecGrpIncBuff* updated = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecGrpInc()->updateSecGrpInc( schema->getAuthorization(),
				dynamic_cast<cfsec::CFSecSecGrpIncBuff*>( Obj->getSecGrpIncBuff()->clone() ) );
			if( updated == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Updated );
			}
			obj = dynamic_cast<cfsec::ICFSecSecGrpIncObj*>( dynamic_cast<cfsec::CFSecSecGrpIncTableObj*>( schema->getSecGrpIncTableObj() )->newInstance() );
			obj->setBuff( updated );
			obj = dynamic_cast<cfsec::ICFSecSecGrpIncObj*>( obj->realize() );
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

	void CFSecSecGrpIncTableObj::deleteSecGrpInc( cfsec::ICFSecSecGrpIncEditObj* Obj ) {
		cfsec::ICFSecSecGrpIncObj* obj = Obj;
		dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecGrpInc()->deleteSecGrpInc( schema->getAuthorization(),
			obj->getSecGrpIncBuff() );
		deepDisposeByIdIdx( obj->getRequiredClusterId(),
			obj->getRequiredSecGrpIncId() );
	}

	void CFSecSecGrpIncTableObj::deleteSecGrpIncByIdIdx( const int64_t ClusterId,
			const int64_t SecGrpIncId )
	{
		cfsec::CFSecSecGrpIncPKey pkey;
		pkey.setRequiredClusterId( ClusterId );
		pkey.setRequiredSecGrpIncId( SecGrpIncId );
		cfsec::ICFSecSecGrpIncObj* obj = readSecGrpInc( &pkey, true );
		if( obj != NULL ) {
			cfsec::ICFSecSecGrpIncEditObj* editObj = dynamic_cast<cfsec::ICFSecSecGrpIncEditObj*>( obj->getEdit() );
			if( editObj == NULL ) {
				editObj = dynamic_cast<cfsec::ICFSecSecGrpIncEditObj*>( obj->beginEdit() );
			}
			if( editObj != NULL ) {
				editObj->deleteInstance();
				editObj = NULL;
			}
		}
	}

	void CFSecSecGrpIncTableObj::deleteSecGrpIncByClusterIdx( const int64_t ClusterId )
	{
		dynamic_cast<cfsec::ICFSecSchema*>( schema->getBackingStore() )->getTableSecGrpInc()->deleteSecGrpIncByClusterIdx( schema->getAuthorization(),
				ClusterId );
		deepDisposeByClusterIdx( ClusterId );
	}

	void CFSecSecGrpIncTableObj::deleteSecGrpIncByGroupIdx( const int64_t ClusterId,
			const int32_t SecGroupId )
	{
		dynamic_cast<cfsec::ICFSecSchema*>( schema->getBackingStore() )->getTableSecGrpInc()->deleteSecGrpIncByGroupIdx( schema->getAuthorization(),
				ClusterId,
				SecGroupId );
		deepDisposeByGroupIdx( ClusterId,
			SecGroupId );
	}

	void CFSecSecGrpIncTableObj::deleteSecGrpIncByIncludeIdx( const int64_t ClusterId,
			const int32_t IncludeGroupId )
	{
		dynamic_cast<cfsec::ICFSecSchema*>( schema->getBackingStore() )->getTableSecGrpInc()->deleteSecGrpIncByIncludeIdx( schema->getAuthorization(),
				ClusterId,
				IncludeGroupId );
		deepDisposeByIncludeIdx( ClusterId,
			IncludeGroupId );
	}

	void CFSecSecGrpIncTableObj::deleteSecGrpIncByUIncludeIdx( const int64_t ClusterId,
			const int32_t SecGroupId,
			const int32_t IncludeGroupId )
	{
		if( indexByUIncludeIdx == NULL ) {
			indexByUIncludeIdx = new std::map< cfsec::CFSecSecGrpIncByUIncludeIdxKey,
				cfsec::ICFSecSecGrpIncObj*>();
		}
		cfsec::CFSecSecGrpIncByUIncludeIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredSecGroupId( SecGroupId );
		key.setRequiredIncludeGroupId( IncludeGroupId );
		cfsec::ICFSecSecGrpIncObj* obj = NULL;
		auto searchIndexByUIncludeIdx = indexByUIncludeIdx->find( key );
		if( searchIndexByUIncludeIdx != indexByUIncludeIdx->end() ) {
			dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecGrpInc()->deleteSecGrpIncByUIncludeIdx( schema->getAuthorization(),
				ClusterId,
				SecGroupId,
				IncludeGroupId );
		}
		else {
			dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecGrpInc()->deleteSecGrpIncByUIncludeIdx( schema->getAuthorization(),
				ClusterId,
				SecGroupId,
				IncludeGroupId );
		}
		deepDisposeByUIncludeIdx( ClusterId,
			SecGroupId,
			IncludeGroupId );
	}

	void CFSecSecGrpIncTableObj::reallyDetachFromIndexesSecGrpInc( cfsec::ICFSecSecGrpIncObj* Obj ) {
		static const std::string S_ProcName( "reallyDetachFromIndexesSecGrpInc" );
		static const std::string S_Obj( "Obj" );
		static const std::string S_ExistingObj( "ExistingObj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfsec::ICFSecSecGrpIncObj* obj = Obj;
		cfsec::CFSecSecGrpIncPKey* pkey = obj->getPKey();
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			cfsec::ICFSecSecGrpIncObj* existingObj = searchMembers->second;
			if( existingObj == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_ExistingObj );
			}
			if( indexByClusterIdx != NULL ) {
				cfsec::CFSecSecGrpIncByClusterIdxKey keyClusterIdx;
				keyClusterIdx.setRequiredClusterId( obj->getRequiredClusterId() );
				auto searchClusterIdx = indexByClusterIdx->find( keyClusterIdx );
				if( searchClusterIdx != indexByClusterIdx->end() ) {
					std::map<cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>* mapClusterIdx = searchClusterIdx->second;
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

			if( indexByGroupIdx != NULL ) {
				cfsec::CFSecSecGrpIncByGroupIdxKey keyGroupIdx;
				keyGroupIdx.setRequiredClusterId( obj->getRequiredClusterId() );
				keyGroupIdx.setRequiredSecGroupId( obj->getRequiredSecGroupId() );
				auto searchGroupIdx = indexByGroupIdx->find( keyGroupIdx );
				if( searchGroupIdx != indexByGroupIdx->end() ) {
					std::map<cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>* mapGroupIdx = searchGroupIdx->second;
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

			if( indexByIncludeIdx != NULL ) {
				cfsec::CFSecSecGrpIncByIncludeIdxKey keyIncludeIdx;
				keyIncludeIdx.setRequiredClusterId( obj->getRequiredClusterId() );
				keyIncludeIdx.setRequiredIncludeGroupId( obj->getRequiredIncludeGroupId() );
				auto searchIncludeIdx = indexByIncludeIdx->find( keyIncludeIdx );
				if( searchIncludeIdx != indexByIncludeIdx->end() ) {
					std::map<cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>* mapIncludeIdx = searchIncludeIdx->second;
					if( mapIncludeIdx != NULL ) {
						auto removalProbe = mapIncludeIdx->find( *(obj->getPKey()) );
						if( removalProbe != mapIncludeIdx->end() ) {
							mapIncludeIdx->erase( removalProbe );
							if( mapIncludeIdx->empty() ) {
								delete mapIncludeIdx;
								mapIncludeIdx = NULL;
								indexByIncludeIdx->erase( searchIncludeIdx );
							}
						}
					}
				}
			}

			if( indexByUIncludeIdx != NULL ) {
				cfsec::CFSecSecGrpIncByUIncludeIdxKey keyUIncludeIdx;
				keyUIncludeIdx.setRequiredClusterId( obj->getRequiredClusterId() );
				keyUIncludeIdx.setRequiredSecGroupId( obj->getRequiredSecGroupId() );
				keyUIncludeIdx.setRequiredIncludeGroupId( obj->getRequiredIncludeGroupId() );
				auto removalProbe = indexByUIncludeIdx->find( keyUIncludeIdx );
				if( removalProbe != indexByUIncludeIdx->end() ) {
					indexByUIncludeIdx->erase( removalProbe );
				}
			}

			members->erase( searchMembers );
		}
	}


}
