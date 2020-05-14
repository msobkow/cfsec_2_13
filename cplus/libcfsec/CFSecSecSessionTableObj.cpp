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

	const std::string CFSecSecSessionTableObj::CLASS_NAME( "CFSecSecSessionTableObj" );
	const std::string CFSecSecSessionTableObj::TABLE_NAME( "SecSession" );
	const std::string CFSecSecSessionTableObj::TABLE_DBNAME( "SecSess" );

	CFSecSecSessionTableObj::CFSecSecSessionTableObj() {
		schema = NULL;
		members = new std::map<cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj*>();
		allSecSession = NULL;
		indexBySecUserIdx = new std::map< cfsec::CFSecSecSessionBySecUserIdxKey,
			std::map< cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj*>*>();
		indexBySecDevIdx = new std::map< cfsec::CFSecSecSessionBySecDevIdxKey,
			std::map< cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj*>*>();
		indexByStartIdx = new std::map< cfsec::CFSecSecSessionByStartIdxKey,
			cfsec::ICFSecSecSessionObj*>();
		indexByFinishIdx = new std::map< cfsec::CFSecSecSessionByFinishIdxKey,
			std::map< cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj*>*>();
		indexBySecProxyIdx = new std::map< cfsec::CFSecSecSessionBySecProxyIdxKey,
			std::map< cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj*>*>();
	}

	CFSecSecSessionTableObj::CFSecSecSessionTableObj( cfsec::ICFSecSchemaObj* argSchema ) {
		schema = dynamic_cast<cfsec::ICFSecSchemaObj*>( argSchema );
		members = new std::map<cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj*>();
		allSecSession = NULL;
		indexBySecUserIdx = new std::map< cfsec::CFSecSecSessionBySecUserIdxKey,
			std::map< cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj*>*>();
		indexBySecDevIdx = new std::map< cfsec::CFSecSecSessionBySecDevIdxKey,
			std::map< cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj*>*>();
		indexByStartIdx = new std::map< cfsec::CFSecSecSessionByStartIdxKey,
			cfsec::ICFSecSecSessionObj*>();
		indexByFinishIdx = new std::map< cfsec::CFSecSecSessionByFinishIdxKey,
			std::map< cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj*>*>();
		indexBySecProxyIdx = new std::map< cfsec::CFSecSecSessionBySecProxyIdxKey,
			std::map< cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj*>*>();
	}

	CFSecSecSessionTableObj::~CFSecSecSessionTableObj() {
		minimizeMemory();
		if( indexBySecUserIdx != NULL ) {
			delete indexBySecUserIdx;
			indexBySecUserIdx = NULL;
		}
		if( indexBySecDevIdx != NULL ) {
			delete indexBySecDevIdx;
			indexBySecDevIdx = NULL;
		}
		if( indexByStartIdx != NULL ) {
			delete indexByStartIdx;
			indexByStartIdx = NULL;
		}
		if( indexByFinishIdx != NULL ) {
			delete indexByFinishIdx;
			indexByFinishIdx = NULL;
		}
		if( indexBySecProxyIdx != NULL ) {
			delete indexBySecProxyIdx;
			indexBySecProxyIdx = NULL;
		}
		if( members != NULL ) {
			cfsec::ICFSecSecSessionObj* curMember;
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

	cfsec::ICFSecSchemaObj* CFSecSecSessionTableObj::getSchema() {
		return( schema );
	}

	void CFSecSecSessionTableObj::setSchema( cfsec::ICFSecSchemaObj* value ) {
		schema = dynamic_cast<cfsec::ICFSecSchemaObj*>( value );
	}

	const std::string CFSecSecSessionTableObj::getTableName() {
		return( TABLE_NAME );
	}

	const std::string CFSecSecSessionTableObj::getTableDbName() {
		return( TABLE_DBNAME );
	}
	const classcode_t* CFSecSecSessionTableObj::getObjQualifyingClassCode() {
		return( NULL );
	}


	void CFSecSecSessionTableObj::minimizeMemory() {
		if( allSecSession != NULL ) {
			allSecSession->clear();
			delete allSecSession;
			allSecSession = NULL;
		}
		if( indexBySecUserIdx != NULL ) {
			std::map< cfsec::CFSecSecSessionBySecUserIdxKey,
				std::map< cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj*>* >::iterator iterBySecUserIdx = indexBySecUserIdx->begin();
			std::map< cfsec::CFSecSecSessionBySecUserIdxKey,
				std::map< cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj*>* >::iterator endBySecUserIdx = indexBySecUserIdx->end();
			std::map< cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj*>* curBySecUserIdx = NULL;
			while( iterBySecUserIdx != endBySecUserIdx ) {
				curBySecUserIdx = iterBySecUserIdx->second;
				if( curBySecUserIdx != NULL ) {
					curBySecUserIdx->clear();
					delete curBySecUserIdx;
					curBySecUserIdx = NULL;
					iterBySecUserIdx->second = NULL;
				}
				iterBySecUserIdx ++;
			}
			indexBySecUserIdx->clear();
		}
		if( indexBySecDevIdx != NULL ) {
			std::map< cfsec::CFSecSecSessionBySecDevIdxKey,
				std::map< cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj*>* >::iterator iterBySecDevIdx = indexBySecDevIdx->begin();
			std::map< cfsec::CFSecSecSessionBySecDevIdxKey,
				std::map< cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj*>* >::iterator endBySecDevIdx = indexBySecDevIdx->end();
			std::map< cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj*>* curBySecDevIdx = NULL;
			while( iterBySecDevIdx != endBySecDevIdx ) {
				curBySecDevIdx = iterBySecDevIdx->second;
				if( curBySecDevIdx != NULL ) {
					curBySecDevIdx->clear();
					delete curBySecDevIdx;
					curBySecDevIdx = NULL;
					iterBySecDevIdx->second = NULL;
				}
				iterBySecDevIdx ++;
			}
			indexBySecDevIdx->clear();
		}
		if( indexByStartIdx != NULL ) {
			indexByStartIdx->clear();
		}
		if( indexByFinishIdx != NULL ) {
			std::map< cfsec::CFSecSecSessionByFinishIdxKey,
				std::map< cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj*>* >::iterator iterByFinishIdx = indexByFinishIdx->begin();
			std::map< cfsec::CFSecSecSessionByFinishIdxKey,
				std::map< cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj*>* >::iterator endByFinishIdx = indexByFinishIdx->end();
			std::map< cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj*>* curByFinishIdx = NULL;
			while( iterByFinishIdx != endByFinishIdx ) {
				curByFinishIdx = iterByFinishIdx->second;
				if( curByFinishIdx != NULL ) {
					curByFinishIdx->clear();
					delete curByFinishIdx;
					curByFinishIdx = NULL;
					iterByFinishIdx->second = NULL;
				}
				iterByFinishIdx ++;
			}
			indexByFinishIdx->clear();
		}
		if( indexBySecProxyIdx != NULL ) {
			std::map< cfsec::CFSecSecSessionBySecProxyIdxKey,
				std::map< cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj*>* >::iterator iterBySecProxyIdx = indexBySecProxyIdx->begin();
			std::map< cfsec::CFSecSecSessionBySecProxyIdxKey,
				std::map< cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj*>* >::iterator endBySecProxyIdx = indexBySecProxyIdx->end();
			std::map< cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj*>* curBySecProxyIdx = NULL;
			while( iterBySecProxyIdx != endBySecProxyIdx ) {
				curBySecProxyIdx = iterBySecProxyIdx->second;
				if( curBySecProxyIdx != NULL ) {
					curBySecProxyIdx->clear();
					delete curBySecProxyIdx;
					curBySecProxyIdx = NULL;
					iterBySecProxyIdx->second = NULL;
				}
				iterBySecProxyIdx ++;
			}
			indexBySecProxyIdx->clear();
		}
		if( members != NULL ) {
			cfsec::ICFSecSecSessionObj* cur = NULL;
			cfsec::ICFSecSecSessionEditObj* edit = NULL;
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

	cfsec::ICFSecSecSessionObj* CFSecSecSessionTableObj::newInstance() {
		cfsec::ICFSecSecSessionObj* inst = dynamic_cast<cfsec::ICFSecSecSessionObj*>( new CFSecSecSessionObj( schema ) );
		return( inst );
	}

	cfsec::ICFSecSecSessionEditObj* CFSecSecSessionTableObj::newEditInstance( cfsec::ICFSecSecSessionObj* orig ) {
		cfsec::ICFSecSecSessionEditObj* edit = dynamic_cast<cfsec::ICFSecSecSessionEditObj*>( new CFSecSecSessionEditObj( orig ));
		return( edit );
	}

	cfsec::ICFSecSecSessionObj* CFSecSecSessionTableObj::realizeSecSession( cfsec::ICFSecSecSessionObj* Obj ) {
		static const std::string S_ProcName( "realizeSecSession" );
		static const std::string S_ExistingObj( "existingObj" );
		static const std::string S_KeepObj( "keepObj" );
		static const std::string S_Obj( "Obj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfsec::ICFSecSecSessionObj* obj = Obj;
		cfsec::ICFSecSecSessionObj* existingObj = NULL;
		cfsec::CFSecSecSessionPKey* pkey = obj->getPKey();
		cfsec::ICFSecSecSessionObj* keepObj = NULL;
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
			if( indexBySecUserIdx != NULL ) {
				cfsec::CFSecSecSessionBySecUserIdxKey keySecUserIdx;
				keySecUserIdx.setRequiredSecUserId( keepObj->getRequiredSecUserId() );
				auto searchSecUserIdx = indexBySecUserIdx->find( keySecUserIdx );
				if( searchSecUserIdx != indexBySecUserIdx->end() ) {
					std::map<cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj*>* mapSecUserIdx = searchSecUserIdx->second;
					if( mapSecUserIdx != NULL ) {
						auto removalProbe = mapSecUserIdx->find( *(keepObj->getPKey()) );
						if( removalProbe != mapSecUserIdx->end() ) {
							mapSecUserIdx->erase( removalProbe );
						}
					}
				}
			}

			if( indexBySecDevIdx != NULL ) {
				cfsec::CFSecSecSessionBySecDevIdxKey keySecDevIdx;
				keySecDevIdx.setRequiredSecUserId( keepObj->getRequiredSecUserId() );
				if( keepObj->isOptionalSecDevNameNull() ) {
					keySecDevIdx.setOptionalSecDevNameNull();
				}
				else {
					keySecDevIdx.setOptionalSecDevNameValue( keepObj->getOptionalSecDevNameValue() );
				}
				auto searchSecDevIdx = indexBySecDevIdx->find( keySecDevIdx );
				if( searchSecDevIdx != indexBySecDevIdx->end() ) {
					std::map<cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj*>* mapSecDevIdx = searchSecDevIdx->second;
					if( mapSecDevIdx != NULL ) {
						auto removalProbe = mapSecDevIdx->find( *(keepObj->getPKey()) );
						if( removalProbe != mapSecDevIdx->end() ) {
							mapSecDevIdx->erase( removalProbe );
						}
					}
				}
			}

			if( indexByStartIdx != NULL ) {
				cfsec::CFSecSecSessionByStartIdxKey keyStartIdx;
				keyStartIdx.setRequiredSecUserId( keepObj->getRequiredSecUserId() );
				keyStartIdx.setRequiredStart( keepObj->getRequiredStart() );
				auto removalProbe = indexByStartIdx->find( keyStartIdx );
				if( removalProbe != indexByStartIdx->end() ) {
					indexByStartIdx->erase( removalProbe );
				}
			}

			if( indexByFinishIdx != NULL ) {
				cfsec::CFSecSecSessionByFinishIdxKey keyFinishIdx;
				keyFinishIdx.setRequiredSecUserId( keepObj->getRequiredSecUserId() );
				if( keepObj->isOptionalFinishNull() ) {
					keyFinishIdx.setOptionalFinishNull();
				}
				else {
					keyFinishIdx.setOptionalFinishValue( keepObj->getOptionalFinishValue() );
				}
				auto searchFinishIdx = indexByFinishIdx->find( keyFinishIdx );
				if( searchFinishIdx != indexByFinishIdx->end() ) {
					std::map<cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj*>* mapFinishIdx = searchFinishIdx->second;
					if( mapFinishIdx != NULL ) {
						auto removalProbe = mapFinishIdx->find( *(keepObj->getPKey()) );
						if( removalProbe != mapFinishIdx->end() ) {
							mapFinishIdx->erase( removalProbe );
						}
					}
				}
			}

			if( indexBySecProxyIdx != NULL ) {
				cfsec::CFSecSecSessionBySecProxyIdxKey keySecProxyIdx;
				if( keepObj->isOptionalSecProxyIdNull() ) {
					keySecProxyIdx.setOptionalSecProxyIdNull();
				}
				else {
					keySecProxyIdx.setOptionalSecProxyIdValue( keepObj->getOptionalSecProxyIdValue() );
				}
				auto searchSecProxyIdx = indexBySecProxyIdx->find( keySecProxyIdx );
				if( searchSecProxyIdx != indexBySecProxyIdx->end() ) {
					std::map<cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj*>* mapSecProxyIdx = searchSecProxyIdx->second;
					if( mapSecProxyIdx != NULL ) {
						auto removalProbe = mapSecProxyIdx->find( *(keepObj->getPKey()) );
						if( removalProbe != mapSecProxyIdx->end() ) {
							mapSecProxyIdx->erase( removalProbe );
						}
					}
				}
			}

			keepObj->setBuff( dynamic_cast<cfsec::CFSecSecSessionBuff*>( Obj->getBuff()->clone() ) );
			// Attach new object to alternate and duplicate indexes -- PKey stays stable

			if( indexBySecUserIdx != NULL ) {
				static const std::string S_ASecUserIdxObj( "aSecUserIdxObj" );
				cfsec::ICFSecSecSessionObj* aSecUserIdxObj =
					dynamic_cast<cfsec::ICFSecSecSessionObj*>( keepObj );
				if( aSecUserIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ASecUserIdxObj );
				}
				cfsec::CFSecSecSessionBySecUserIdxKey keySecUserIdx;
				keySecUserIdx.setRequiredSecUserId( keepObj->getRequiredSecUserId() );
				auto searchIndexBySecUserIdx = indexBySecUserIdx->find( keySecUserIdx );
				if( searchIndexBySecUserIdx != indexBySecUserIdx->end() ) {
					std::map<cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj*>* mapSecUserIdx = searchIndexBySecUserIdx->second;
					if( mapSecUserIdx != NULL ) {
						mapSecUserIdx->insert( std::map< cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj* >::value_type( *(keepObj->getPKey()), aSecUserIdxObj ) );
					}
				}
			}

			if( indexBySecDevIdx != NULL ) {
				static const std::string S_ASecDevIdxObj( "aSecDevIdxObj" );
				cfsec::ICFSecSecSessionObj* aSecDevIdxObj =
					dynamic_cast<cfsec::ICFSecSecSessionObj*>( keepObj );
				if( aSecDevIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ASecDevIdxObj );
				}
				cfsec::CFSecSecSessionBySecDevIdxKey keySecDevIdx;
				keySecDevIdx.setRequiredSecUserId( keepObj->getRequiredSecUserId() );
				if( keepObj->isOptionalSecDevNameNull() ) {
					keySecDevIdx.setOptionalSecDevNameNull();
				}
				else {
					keySecDevIdx.setOptionalSecDevNameValue( keepObj->getOptionalSecDevNameValue() );
				}
				auto searchIndexBySecDevIdx = indexBySecDevIdx->find( keySecDevIdx );
				if( searchIndexBySecDevIdx != indexBySecDevIdx->end() ) {
					std::map<cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj*>* mapSecDevIdx = searchIndexBySecDevIdx->second;
					if( mapSecDevIdx != NULL ) {
						mapSecDevIdx->insert( std::map< cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj* >::value_type( *(keepObj->getPKey()), aSecDevIdxObj ) );
					}
				}
			}

			if( indexByStartIdx != NULL ) {
				static const std::string S_AStartIdxObj( "aStartIdxObj" );
				cfsec::ICFSecSecSessionObj* aStartIdxObj =
					dynamic_cast<cfsec::ICFSecSecSessionObj*>( keepObj );
				if( aStartIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AStartIdxObj );
				}
				cfsec::CFSecSecSessionByStartIdxKey keyStartIdx;
				keyStartIdx.setRequiredSecUserId( keepObj->getRequiredSecUserId() );
				keyStartIdx.setRequiredStart( keepObj->getRequiredStart() );
				indexByStartIdx->insert( std::map< cfsec::CFSecSecSessionByStartIdxKey, cfsec::ICFSecSecSessionObj* >::value_type( keyStartIdx, aStartIdxObj ) );
			}

			if( indexByFinishIdx != NULL ) {
				static const std::string S_AFinishIdxObj( "aFinishIdxObj" );
				cfsec::ICFSecSecSessionObj* aFinishIdxObj =
					dynamic_cast<cfsec::ICFSecSecSessionObj*>( keepObj );
				if( aFinishIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AFinishIdxObj );
				}
				cfsec::CFSecSecSessionByFinishIdxKey keyFinishIdx;
				keyFinishIdx.setRequiredSecUserId( keepObj->getRequiredSecUserId() );
				if( keepObj->isOptionalFinishNull() ) {
					keyFinishIdx.setOptionalFinishNull();
				}
				else {
					keyFinishIdx.setOptionalFinishValue( keepObj->getOptionalFinishValue() );
				}
				auto searchIndexByFinishIdx = indexByFinishIdx->find( keyFinishIdx );
				if( searchIndexByFinishIdx != indexByFinishIdx->end() ) {
					std::map<cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj*>* mapFinishIdx = searchIndexByFinishIdx->second;
					if( mapFinishIdx != NULL ) {
						mapFinishIdx->insert( std::map< cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj* >::value_type( *(keepObj->getPKey()), aFinishIdxObj ) );
					}
				}
			}

			if( indexBySecProxyIdx != NULL ) {
				static const std::string S_ASecProxyIdxObj( "aSecProxyIdxObj" );
				cfsec::ICFSecSecSessionObj* aSecProxyIdxObj =
					dynamic_cast<cfsec::ICFSecSecSessionObj*>( keepObj );
				if( aSecProxyIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ASecProxyIdxObj );
				}
				cfsec::CFSecSecSessionBySecProxyIdxKey keySecProxyIdx;
				if( keepObj->isOptionalSecProxyIdNull() ) {
					keySecProxyIdx.setOptionalSecProxyIdNull();
				}
				else {
					keySecProxyIdx.setOptionalSecProxyIdValue( keepObj->getOptionalSecProxyIdValue() );
				}
				auto searchIndexBySecProxyIdx = indexBySecProxyIdx->find( keySecProxyIdx );
				if( searchIndexBySecProxyIdx != indexBySecProxyIdx->end() ) {
					std::map<cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj*>* mapSecProxyIdx = searchIndexBySecProxyIdx->second;
					if( mapSecProxyIdx != NULL ) {
						mapSecProxyIdx->insert( std::map< cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj* >::value_type( *(keepObj->getPKey()), aSecProxyIdxObj ) );
					}
				}
			}

			if( allSecSession != NULL ) {
				allSecSession->insert( std::map< cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			}
		}
		else {
			keepObj = obj;
			keepObj->setIsNew( false );
			pkey = keepObj->getPKey();
			// Attach new object to PKey, all, alternate, and duplicate indexes
			members->insert( std::map< cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			// Attach new object to alternate and duplicate indexes -- PKey stay stable

			if( indexBySecUserIdx != NULL ) {
				static const std::string S_ASecUserIdxObj( "aSecUserIdxObj" );
				cfsec::ICFSecSecSessionObj* aSecUserIdxObj =
					dynamic_cast<cfsec::ICFSecSecSessionObj*>( keepObj );
				if( aSecUserIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ASecUserIdxObj );
				}
				cfsec::CFSecSecSessionBySecUserIdxKey keySecUserIdx;
				keySecUserIdx.setRequiredSecUserId( keepObj->getRequiredSecUserId() );
				auto searchIndexBySecUserIdx = indexBySecUserIdx->find( keySecUserIdx );
				if( searchIndexBySecUserIdx != indexBySecUserIdx->end() ) {
					std::map<cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj*>* mapSecUserIdx = searchIndexBySecUserIdx->second;
					if( mapSecUserIdx != NULL ) {
						mapSecUserIdx->insert( std::map< cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj* >::value_type( *(keepObj->getPKey()), aSecUserIdxObj ) );
					}
				}
			}

			if( indexBySecDevIdx != NULL ) {
				static const std::string S_ASecDevIdxObj( "aSecDevIdxObj" );
				cfsec::ICFSecSecSessionObj* aSecDevIdxObj =
					dynamic_cast<cfsec::ICFSecSecSessionObj*>( keepObj );
				if( aSecDevIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ASecDevIdxObj );
				}
				cfsec::CFSecSecSessionBySecDevIdxKey keySecDevIdx;
				keySecDevIdx.setRequiredSecUserId( keepObj->getRequiredSecUserId() );
				if( keepObj->isOptionalSecDevNameNull() ) {
					keySecDevIdx.setOptionalSecDevNameNull();
				}
				else {
					keySecDevIdx.setOptionalSecDevNameValue( keepObj->getOptionalSecDevNameValue() );
				}
				auto searchIndexBySecDevIdx = indexBySecDevIdx->find( keySecDevIdx );
				if( searchIndexBySecDevIdx != indexBySecDevIdx->end() ) {
					std::map<cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj*>* mapSecDevIdx = searchIndexBySecDevIdx->second;
					if( mapSecDevIdx != NULL ) {
						mapSecDevIdx->insert( std::map< cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj* >::value_type( *(keepObj->getPKey()), aSecDevIdxObj ) );
					}
				}
			}

			if( indexByStartIdx != NULL ) {
				static const std::string S_AStartIdxObj( "aStartIdxObj" );
				cfsec::ICFSecSecSessionObj* aStartIdxObj =
					dynamic_cast<cfsec::ICFSecSecSessionObj*>( keepObj );
				if( aStartIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AStartIdxObj );
				}
				cfsec::CFSecSecSessionByStartIdxKey keyStartIdx;
				keyStartIdx.setRequiredSecUserId( keepObj->getRequiredSecUserId() );
				keyStartIdx.setRequiredStart( keepObj->getRequiredStart() );
				indexByStartIdx->insert( std::map< cfsec::CFSecSecSessionByStartIdxKey, cfsec::ICFSecSecSessionObj* >::value_type( keyStartIdx, aStartIdxObj ) );
			}

			if( indexByFinishIdx != NULL ) {
				static const std::string S_AFinishIdxObj( "aFinishIdxObj" );
				cfsec::ICFSecSecSessionObj* aFinishIdxObj =
					dynamic_cast<cfsec::ICFSecSecSessionObj*>( keepObj );
				if( aFinishIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AFinishIdxObj );
				}
				cfsec::CFSecSecSessionByFinishIdxKey keyFinishIdx;
				keyFinishIdx.setRequiredSecUserId( keepObj->getRequiredSecUserId() );
				if( keepObj->isOptionalFinishNull() ) {
					keyFinishIdx.setOptionalFinishNull();
				}
				else {
					keyFinishIdx.setOptionalFinishValue( keepObj->getOptionalFinishValue() );
				}
				auto searchIndexByFinishIdx = indexByFinishIdx->find( keyFinishIdx );
				if( searchIndexByFinishIdx != indexByFinishIdx->end() ) {
					std::map<cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj*>* mapFinishIdx = searchIndexByFinishIdx->second;
					if( mapFinishIdx != NULL ) {
						mapFinishIdx->insert( std::map< cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj* >::value_type( *(keepObj->getPKey()), aFinishIdxObj ) );
					}
				}
			}

			if( indexBySecProxyIdx != NULL ) {
				static const std::string S_ASecProxyIdxObj( "aSecProxyIdxObj" );
				cfsec::ICFSecSecSessionObj* aSecProxyIdxObj =
					dynamic_cast<cfsec::ICFSecSecSessionObj*>( keepObj );
				if( aSecProxyIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ASecProxyIdxObj );
				}
				cfsec::CFSecSecSessionBySecProxyIdxKey keySecProxyIdx;
				if( keepObj->isOptionalSecProxyIdNull() ) {
					keySecProxyIdx.setOptionalSecProxyIdNull();
				}
				else {
					keySecProxyIdx.setOptionalSecProxyIdValue( keepObj->getOptionalSecProxyIdValue() );
				}
				auto searchIndexBySecProxyIdx = indexBySecProxyIdx->find( keySecProxyIdx );
				if( searchIndexBySecProxyIdx != indexBySecProxyIdx->end() ) {
					std::map<cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj*>* mapSecProxyIdx = searchIndexBySecProxyIdx->second;
					if( mapSecProxyIdx != NULL ) {
						mapSecProxyIdx->insert( std::map< cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj* >::value_type( *(keepObj->getPKey()), aSecProxyIdxObj ) );
					}
				}
			}

			if( allSecSession != NULL ) {
				allSecSession->insert( std::map< cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
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

	void CFSecSecSessionTableObj::deepDisposeByIdIdx( const uuid_ptr_t SecSessionId ) {
		static const std::string S_ProcName( "deepDisposeByIdIdx" );
		std::vector<cfsec::ICFSecSecSessionObj*> list;
		cfsec::ICFSecSecSessionObj* existingObj = readCachedSecSessionByIdIdx( SecSessionId );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfsec::ICFSecSecSessionObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecSecSessionBuff::CLASS_CODE ) {
					dynamic_cast<cfsec::CFSecSecSessionTableObj*>( schema->getSecSessionTableObj() )->reallyDeepDisposeSecSession( dynamic_cast<cfsec::ICFSecSecSessionObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFSecSecSessionTableObj::deepDisposeBySecUserIdx( const uuid_ptr_t SecUserId ) {
		static const std::string S_ProcName( "deepDisposeBySecUserIdx" );
		std::vector<cfsec::ICFSecSecSessionObj*> list;
		std::vector<cfsec::ICFSecSecSessionObj*> matchesFound = readCachedSecSessionBySecUserIdx( SecUserId );
		auto iterMatches = matchesFound.begin();
		auto endMatches = matchesFound.end();
		while( iterMatches != endMatches ) {
			if( *iterMatches != NULL ) {
				list.push_back( *iterMatches );
			}
			iterMatches ++;
		}
		cfsec::ICFSecSecSessionObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecSecSessionBuff::CLASS_CODE ) {
					dynamic_cast<cfsec::CFSecSecSessionTableObj*>( schema->getSecSessionTableObj() )->reallyDeepDisposeSecSession( dynamic_cast<cfsec::ICFSecSecSessionObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFSecSecSessionTableObj::deepDisposeBySecDevIdx( const uuid_ptr_t SecUserId,
			const std::string* SecDevName ) {
		static const std::string S_ProcName( "deepDisposeBySecDevIdx" );
		std::vector<cfsec::ICFSecSecSessionObj*> list;
		std::vector<cfsec::ICFSecSecSessionObj*> matchesFound = readCachedSecSessionBySecDevIdx( SecUserId,
				SecDevName );
		auto iterMatches = matchesFound.begin();
		auto endMatches = matchesFound.end();
		while( iterMatches != endMatches ) {
			if( *iterMatches != NULL ) {
				list.push_back( *iterMatches );
			}
			iterMatches ++;
		}
		cfsec::ICFSecSecSessionObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecSecSessionBuff::CLASS_CODE ) {
					dynamic_cast<cfsec::CFSecSecSessionTableObj*>( schema->getSecSessionTableObj() )->reallyDeepDisposeSecSession( dynamic_cast<cfsec::ICFSecSecSessionObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFSecSecSessionTableObj::deepDisposeByStartIdx( const uuid_ptr_t SecUserId,
			const std::chrono::system_clock::time_point& Start ) {
		static const std::string S_ProcName( "deepDisposeByStartIdx" );
		std::vector<cfsec::ICFSecSecSessionObj*> list;
		cfsec::ICFSecSecSessionObj* existingObj = readCachedSecSessionByStartIdx( SecUserId,
				Start );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfsec::ICFSecSecSessionObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecSecSessionBuff::CLASS_CODE ) {
					dynamic_cast<cfsec::CFSecSecSessionTableObj*>( schema->getSecSessionTableObj() )->reallyDeepDisposeSecSession( dynamic_cast<cfsec::ICFSecSecSessionObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFSecSecSessionTableObj::deepDisposeByFinishIdx( const uuid_ptr_t SecUserId,
			const std::chrono::system_clock::time_point* Finish ) {
		static const std::string S_ProcName( "deepDisposeByFinishIdx" );
		std::vector<cfsec::ICFSecSecSessionObj*> list;
		std::vector<cfsec::ICFSecSecSessionObj*> matchesFound = readCachedSecSessionByFinishIdx( SecUserId,
				Finish );
		auto iterMatches = matchesFound.begin();
		auto endMatches = matchesFound.end();
		while( iterMatches != endMatches ) {
			if( *iterMatches != NULL ) {
				list.push_back( *iterMatches );
			}
			iterMatches ++;
		}
		cfsec::ICFSecSecSessionObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecSecSessionBuff::CLASS_CODE ) {
					dynamic_cast<cfsec::CFSecSecSessionTableObj*>( schema->getSecSessionTableObj() )->reallyDeepDisposeSecSession( dynamic_cast<cfsec::ICFSecSecSessionObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFSecSecSessionTableObj::deepDisposeBySecProxyIdx( const uuid_ptr_t SecProxyId ) {
		static const std::string S_ProcName( "deepDisposeBySecProxyIdx" );
		std::vector<cfsec::ICFSecSecSessionObj*> list;
		std::vector<cfsec::ICFSecSecSessionObj*> matchesFound = readCachedSecSessionBySecProxyIdx( SecProxyId );
		auto iterMatches = matchesFound.begin();
		auto endMatches = matchesFound.end();
		while( iterMatches != endMatches ) {
			if( *iterMatches != NULL ) {
				list.push_back( *iterMatches );
			}
			iterMatches ++;
		}
		cfsec::ICFSecSecSessionObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecSecSessionBuff::CLASS_CODE ) {
					dynamic_cast<cfsec::CFSecSecSessionTableObj*>( schema->getSecSessionTableObj() )->reallyDeepDisposeSecSession( dynamic_cast<cfsec::ICFSecSecSessionObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFSecSecSessionTableObj::reallyDeepDisposeSecSession( cfsec::ICFSecSecSessionObj* Obj ) {
		static const std::string S_ProcName( "reallyDeepDisposeSecSession" );

		if( Obj == NULL ) {
			return;
		}

		cfsec::ICFSecSecSessionObj* obj = Obj;
		
		classcode_t classCode = obj->getClassCode();
		if( classCode == cfsec::CFSecSecSessionBuff::CLASS_CODE ) {
			dynamic_cast<cfsec::CFSecSecSessionTableObj*>( schema->getSecSessionTableObj() )->reallyDetachFromIndexesSecSession( dynamic_cast<cfsec::ICFSecSecSessionObj*>( obj ) );
		}

		if( obj->getEdit() != NULL ) {
			obj->endEdit();
		}
		delete obj;
		obj = NULL;
	}

	cfsec::ICFSecSecSessionObj* CFSecSecSessionTableObj::createSecSession( cfsec::ICFSecSecSessionEditObj* Obj ) {
		static const std::string S_ProcName( "createSecSession" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Cloneable( "cloneable" );
		static const std::string S_ClonedBuff( "clonedbuff" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecSecSessionObj* obj = dynamic_cast<cfsec::ICFSecSecSessionObj*>( Obj->getOrig() );
		try {
			cfsec::CFSecSecSessionBuff* buff = dynamic_cast<cfsec::CFSecSecSessionBuff*>( Obj->getBuff()->clone() );
			// C++18 version of create returns a new buffer instance and takes over ownership of the passed-in buffer
			// MSS TODO WORKING The xmsg client will need to return the buffer instance created by processing
			// the response message, while xmsg rqst will have to delete the backing store instance
			// it receives after preparing the reply message so that memory doesn't leak on every request.
			cflib::ICFLibCloneableObj* cloneable = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecSession()->createSecSession(
				schema->getAuthorization(),
				buff );
			if( cloneable == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Cloneable );
			}
			Obj->endEdit();
			obj->setBuff( dynamic_cast<cfsec::CFSecSecSessionBuff*>( cloneable ) );
			obj = dynamic_cast<cfsec::ICFSecSecSessionObj*>( obj->realize() );
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

	cfsec::ICFSecSecSessionObj* CFSecSecSessionTableObj::readSecSession( cfsec::CFSecSecSessionPKey* pkey, bool forceRead ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readSecSession" );
		cfsec::ICFSecSecSessionObj* obj = NULL;
		cfsec::ICFSecSecSessionObj* realized = NULL;
		if( ! forceRead ) {
			auto searchMembers = members->find( *pkey );
			if( searchMembers != members->end() ) {
				// obj could be NULL if cache misses is enabled
				obj = searchMembers->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecSecSessionBuff* readBuff = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecSession()->readDerivedByIdIdx( schema->getAuthorization(),
			pkey->getRequiredSecSessionId() );
			if( readBuff != NULL ) {
			obj = dynamic_cast<cfsec::CFSecSecSessionTableObj*>( schema->getSecSessionTableObj() )->newInstance();
				obj->setBuff( readBuff );
				realized = dynamic_cast<cfsec::ICFSecSecSessionObj*>( obj->realize() );
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

	cfsec::ICFSecSecSessionObj* CFSecSecSessionTableObj::lockSecSession( cfsec::CFSecSecSessionPKey* pkey ) {
		static const std::string S_ProcName( "lockSecSession" );
		cfsec::ICFSecSecSessionObj* locked = NULL;
		cfsec::CFSecSecSessionBuff* lockBuff = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecSession()->lockDerived( schema->getAuthorization(), pkey );
		if( lockBuff != NULL ) {
			locked = dynamic_cast<cfsec::CFSecSecSessionTableObj*>( schema->getSecSessionTableObj() )->newInstance();
			locked->setBuff( lockBuff );
			locked = dynamic_cast<cfsec::ICFSecSecSessionObj*>( locked->realize() );
		}
		else {
			return( NULL );
		}
		return( locked );
	}

	std::vector<cfsec::ICFSecSecSessionObj*> CFSecSecSessionTableObj::readAllSecSession( bool forceRead ) {
		static const std::string S_ProcName( "readAllSecSession" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Realized( "realized" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecSecSessionObj* realized = NULL;
		if( forceRead || ( allSecSession == NULL ) ) {
			std::map<cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj*>* map = new std::map<cfsec::CFSecSecSessionPKey,cfsec::ICFSecSecSessionObj*>();
			allSecSession = map;
			std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecSession()->readAllDerived( schema->getAuthorization() );
			cfsec::CFSecSecSessionBuff* buff = NULL;
			cfsec::ICFSecSecSessionObj* obj = NULL;
			try {
				for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
					buff = buffList[ idx ];
					buffList[ idx ] = NULL;
				obj = newInstance();
					obj->setBuff( buff );
					realized = dynamic_cast<cfsec::ICFSecSecSessionObj*>( obj->realize() );
					if( realized == NULL ) {
						throw cflib::CFLibNullArgumentException( CLASS_NAME,
							S_ProcName,
							0,
							S_Realized );
					}
					allSecSession->insert( std::map< cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj* >::value_type( *(realized->getPKey()), realized ) );
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
		size_t len = allSecSession->size();
		std::vector<cfsec::ICFSecSecSessionObj*> arr;
		auto valIter = allSecSession->begin();
		size_t idx = 0;
		while( valIter != allSecSession->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	std::vector<cfsec::ICFSecSecSessionObj*> CFSecSecSessionTableObj::pageAllSecSession(const uuid_ptr_t priorSecSessionId )
	{
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "pageAllSecSession" );
		CFLIB_EXCEPTION_DECLINFO
		std::map<cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj*>* map = NULL;
		cfsec::CFSecSecSessionBuff* buff = NULL;
		cfsec::ICFSecSecSessionObj* obj = NULL;
		cfsec::ICFSecSecSessionObj* realized = NULL;
		std::vector<cfsec::ICFSecSecSessionObj*> arrayList;
		try {
			map = new std::map<cfsec::CFSecSecSessionPKey,cfsec::ICFSecSecSessionObj*>();
			std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecSession()->pageAllBuff( schema->getAuthorization(),
				priorSecSessionId );
			arrayList.reserve( buffList.size() );
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = newInstance();
				obj->setBuff( buff );
				realized = dynamic_cast<cfsec::ICFSecSecSessionObj*>( obj->realize() );
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

	cfsec::ICFSecSecSessionObj* CFSecSecSessionTableObj::readSecSessionByIdIdx( const uuid_ptr_t SecSessionId, bool forceRead )
	{
		static const std::string S_ProcName( "readSecSessionByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSecSessionPKey pkey;
		pkey.setRequiredSecSessionId( SecSessionId );
		cfsec::ICFSecSecSessionObj* obj = readSecSession( &pkey, forceRead );
		return( obj );
	}

	std::vector<cfsec::ICFSecSecSessionObj*> CFSecSecSessionTableObj::readSecSessionBySecUserIdx( const uuid_ptr_t SecUserId,
		bool forceRead )
	{
		static const std::string S_ProcName( "readSecSessionBySecUserIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSecSessionBySecUserIdxKey key;
		key.setRequiredSecUserId( SecUserId );
		std::map<cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj*>* dict;
		std::map<cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj*>* oldDict;
		if( indexBySecUserIdx == NULL ) {
			indexBySecUserIdx = new std::map< cfsec::CFSecSecSessionBySecUserIdxKey,
				std::map< cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj*>*>();
		}
		auto searchIndexBySecUserIdx = indexBySecUserIdx->find( key );
		if( searchIndexBySecUserIdx != indexBySecUserIdx->end() ) {
			oldDict = searchIndexBySecUserIdx->second;
		}
		else {
			oldDict = NULL;
		}
		if( ( oldDict != NULL ) && ( ! forceRead ) ) {
			dict = oldDict;
		}
		else {
			dict = new std::map<cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj*>();
			cfsec::ICFSecSecSessionObj* obj;
			std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecSession()->readDerivedBySecUserIdx( schema->getAuthorization(),
				SecUserId );
			cfsec::CFSecSecSessionBuff* buff;
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = dynamic_cast<cfsec::CFSecSecSessionTableObj*>( schema->getSecSessionTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
				obj->setBuff( buff );
				cfsec::ICFSecSecSessionObj* realized = dynamic_cast<cfsec::ICFSecSecSessionObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				dict->insert( std::map< cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj* >::value_type( *(realized->getPKey()), realized ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = NULL;
			}
			if( oldDict != NULL ) {
				indexBySecUserIdx->erase( searchIndexBySecUserIdx );
				delete oldDict;
				oldDict = NULL;
			}
			indexBySecUserIdx->insert( std::map< cfsec::CFSecSecSessionBySecUserIdxKey,
				std::map< cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj* >* >::value_type( key, dict ) );
		}
		size_t len = dict->size();
		std::vector<cfsec::ICFSecSecSessionObj*> arr;
		arr.reserve( len );
		auto valIter = dict->begin();
		while( valIter != dict->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	std::vector<cfsec::ICFSecSecSessionObj*> CFSecSecSessionTableObj::readSecSessionBySecDevIdx( const uuid_ptr_t SecUserId,
			const std::string* SecDevName,
		bool forceRead )
	{
		static const std::string S_ProcName( "readSecSessionBySecDevIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSecSessionBySecDevIdxKey key;
		key.setRequiredSecUserId( SecUserId );
		if( SecDevName == NULL ) {
			key.setOptionalSecDevNameNull();
		}
		else {
			key.setOptionalSecDevNameValue( *SecDevName );
		}
		std::map<cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj*>* dict;
		std::map<cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj*>* oldDict;
		if( indexBySecDevIdx == NULL ) {
			indexBySecDevIdx = new std::map< cfsec::CFSecSecSessionBySecDevIdxKey,
				std::map< cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj*>*>();
		}
		auto searchIndexBySecDevIdx = indexBySecDevIdx->find( key );
		if( searchIndexBySecDevIdx != indexBySecDevIdx->end() ) {
			oldDict = searchIndexBySecDevIdx->second;
		}
		else {
			oldDict = NULL;
		}
		if( ( oldDict != NULL ) && ( ! forceRead ) ) {
			dict = oldDict;
		}
		else {
			dict = new std::map<cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj*>();
			cfsec::ICFSecSecSessionObj* obj;
			std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecSession()->readDerivedBySecDevIdx( schema->getAuthorization(),
				SecUserId,
				SecDevName );
			cfsec::CFSecSecSessionBuff* buff;
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = dynamic_cast<cfsec::CFSecSecSessionTableObj*>( schema->getSecSessionTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
				obj->setBuff( buff );
				cfsec::ICFSecSecSessionObj* realized = dynamic_cast<cfsec::ICFSecSecSessionObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				dict->insert( std::map< cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj* >::value_type( *(realized->getPKey()), realized ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = NULL;
			}
			if( oldDict != NULL ) {
				indexBySecDevIdx->erase( searchIndexBySecDevIdx );
				delete oldDict;
				oldDict = NULL;
			}
			indexBySecDevIdx->insert( std::map< cfsec::CFSecSecSessionBySecDevIdxKey,
				std::map< cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj* >* >::value_type( key, dict ) );
		}
		size_t len = dict->size();
		std::vector<cfsec::ICFSecSecSessionObj*> arr;
		arr.reserve( len );
		auto valIter = dict->begin();
		while( valIter != dict->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	cfsec::ICFSecSecSessionObj* CFSecSecSessionTableObj::readSecSessionByStartIdx( const uuid_ptr_t SecUserId,
			const std::chrono::system_clock::time_point& Start, bool forceRead )
	{
		static const std::string S_ProcName( "readSecSessionByStartIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByStartIdx == NULL ) {
			indexByStartIdx = new std::map< cfsec::CFSecSecSessionByStartIdxKey,
				cfsec::ICFSecSecSessionObj*>();
		}
		cfsec::CFSecSecSessionByStartIdxKey key;
		key.setRequiredSecUserId( SecUserId );
		key.setRequiredStart( Start );
		cfsec::ICFSecSecSessionObj* obj = NULL;
		cfsec::ICFSecSecSessionObj* realized = NULL;
		if( ! forceRead ) {
			auto searchIndexByStartIdx = indexByStartIdx->find( key );
			if( searchIndexByStartIdx != indexByStartIdx->end() ) {
				// Note: obj may be null if cache misses is enabled
				obj = searchIndexByStartIdx->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecSecSessionBuff* buff = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecSession()->readDerivedByStartIdx( schema->getAuthorization(),
				SecUserId,
				Start );
			if( buff != NULL ) {
				obj = dynamic_cast<cfsec::CFSecSecSessionTableObj*>( schema->getSecSessionTableObj() )->newInstance();
				obj->setBuff( buff );
				realized = dynamic_cast<cfsec::ICFSecSecSessionObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				indexByStartIdx->insert( std::map< cfsec::CFSecSecSessionByStartIdxKey, cfsec::ICFSecSecSessionObj*>::value_type( key, dynamic_cast<cfsec::ICFSecSecSessionObj*>( realized ) ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = realized;
			}
		}
		return( obj );
	}

	std::vector<cfsec::ICFSecSecSessionObj*> CFSecSecSessionTableObj::readSecSessionByFinishIdx( const uuid_ptr_t SecUserId,
			const std::chrono::system_clock::time_point* Finish,
		bool forceRead )
	{
		static const std::string S_ProcName( "readSecSessionByFinishIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSecSessionByFinishIdxKey key;
		key.setRequiredSecUserId( SecUserId );
		if( Finish == NULL ) {
			key.setOptionalFinishNull();
		}
		else {
			key.setOptionalFinishValue( *Finish );
		}
		std::map<cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj*>* dict;
		std::map<cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj*>* oldDict;
		if( indexByFinishIdx == NULL ) {
			indexByFinishIdx = new std::map< cfsec::CFSecSecSessionByFinishIdxKey,
				std::map< cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj*>*>();
		}
		auto searchIndexByFinishIdx = indexByFinishIdx->find( key );
		if( searchIndexByFinishIdx != indexByFinishIdx->end() ) {
			oldDict = searchIndexByFinishIdx->second;
		}
		else {
			oldDict = NULL;
		}
		if( ( oldDict != NULL ) && ( ! forceRead ) ) {
			dict = oldDict;
		}
		else {
			dict = new std::map<cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj*>();
			cfsec::ICFSecSecSessionObj* obj;
			std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecSession()->readDerivedByFinishIdx( schema->getAuthorization(),
				SecUserId,
				Finish );
			cfsec::CFSecSecSessionBuff* buff;
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = dynamic_cast<cfsec::CFSecSecSessionTableObj*>( schema->getSecSessionTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
				obj->setBuff( buff );
				cfsec::ICFSecSecSessionObj* realized = dynamic_cast<cfsec::ICFSecSecSessionObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				dict->insert( std::map< cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj* >::value_type( *(realized->getPKey()), realized ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = NULL;
			}
			if( oldDict != NULL ) {
				indexByFinishIdx->erase( searchIndexByFinishIdx );
				delete oldDict;
				oldDict = NULL;
			}
			indexByFinishIdx->insert( std::map< cfsec::CFSecSecSessionByFinishIdxKey,
				std::map< cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj* >* >::value_type( key, dict ) );
		}
		size_t len = dict->size();
		std::vector<cfsec::ICFSecSecSessionObj*> arr;
		arr.reserve( len );
		auto valIter = dict->begin();
		while( valIter != dict->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	std::vector<cfsec::ICFSecSecSessionObj*> CFSecSecSessionTableObj::readSecSessionBySecProxyIdx( const uuid_ptr_t SecProxyId,
		bool forceRead )
	{
		static const std::string S_ProcName( "readSecSessionBySecProxyIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSecSessionBySecProxyIdxKey key;
		if( SecProxyId == NULL ) {
			key.setOptionalSecProxyIdNull();
		}
		else {
			key.setOptionalSecProxyIdValue( SecProxyId );
		}
		std::map<cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj*>* dict;
		std::map<cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj*>* oldDict;
		if( indexBySecProxyIdx == NULL ) {
			indexBySecProxyIdx = new std::map< cfsec::CFSecSecSessionBySecProxyIdxKey,
				std::map< cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj*>*>();
		}
		auto searchIndexBySecProxyIdx = indexBySecProxyIdx->find( key );
		if( searchIndexBySecProxyIdx != indexBySecProxyIdx->end() ) {
			oldDict = searchIndexBySecProxyIdx->second;
		}
		else {
			oldDict = NULL;
		}
		if( ( oldDict != NULL ) && ( ! forceRead ) ) {
			dict = oldDict;
		}
		else {
			dict = new std::map<cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj*>();
			cfsec::ICFSecSecSessionObj* obj;
			std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecSession()->readDerivedBySecProxyIdx( schema->getAuthorization(),
				SecProxyId );
			cfsec::CFSecSecSessionBuff* buff;
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = dynamic_cast<cfsec::CFSecSecSessionTableObj*>( schema->getSecSessionTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
				obj->setBuff( buff );
				cfsec::ICFSecSecSessionObj* realized = dynamic_cast<cfsec::ICFSecSecSessionObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				dict->insert( std::map< cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj* >::value_type( *(realized->getPKey()), realized ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = NULL;
			}
			if( oldDict != NULL ) {
				indexBySecProxyIdx->erase( searchIndexBySecProxyIdx );
				delete oldDict;
				oldDict = NULL;
			}
			indexBySecProxyIdx->insert( std::map< cfsec::CFSecSecSessionBySecProxyIdxKey,
				std::map< cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj* >* >::value_type( key, dict ) );
		}
		size_t len = dict->size();
		std::vector<cfsec::ICFSecSecSessionObj*> arr;
		arr.reserve( len );
		auto valIter = dict->begin();
		while( valIter != dict->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	cfsec::ICFSecSecSessionObj* CFSecSecSessionTableObj::readCachedSecSession( cfsec::CFSecSecSessionPKey* pkey ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readSecSession" );
		cfsec::ICFSecSecSessionObj* obj = NULL;
		cfsec::ICFSecSecSessionObj* realized = NULL;
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			// obj could be NULL if cache misses is enabled
			obj = searchMembers->second;
			realized = obj;
		}
		return( realized );
	}

	cfsec::ICFSecSecSessionObj* CFSecSecSessionTableObj::readCachedSecSessionByIdIdx( const uuid_ptr_t SecSessionId )
	{
		static const std::string S_ProcName( "readCachedSecSessionByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSecSessionPKey pkey;
		pkey.setRequiredSecSessionId( SecSessionId );
		cfsec::ICFSecSecSessionObj* obj = readCachedSecSession( &pkey );
		return( obj );
	}

	std::vector<cfsec::ICFSecSecSessionObj*> CFSecSecSessionTableObj::readCachedSecSessionBySecUserIdx( const uuid_ptr_t SecUserId )
	{
		static const std::string S_ProcName( "readCachedSecSessionBySecUserIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		std::vector<cfsec::ICFSecSecSessionObj*> arr;
		cfsec::CFSecSecSessionBySecUserIdxKey key;
		key.setRequiredSecUserId( SecUserId );
		std::map<cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj*>* dict;
		if( indexBySecUserIdx == NULL ) {
			return( arr );
		}
		auto searchIndexBySecUserIdx = indexBySecUserIdx->find( key );
		if( searchIndexBySecUserIdx != indexBySecUserIdx->end() ) {
			dict = searchIndexBySecUserIdx->second;
			size_t len = dict->size();
			std::vector<cfsec::ICFSecSecSessionObj*> arr;
			arr.reserve( len );
			auto valIter = dict->begin();
			while( valIter != dict->end() ) {
				arr.push_back( valIter->second );
				valIter ++;
			}
		}
		else {
			cfsec::ICFSecSecSessionObj* obj;
			for( auto iterMembers = members->begin(); iterMembers != members->end(); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecSecSessionBuff*>( obj->getBuff() ) ) == key ) {
						arr.push_back( obj );
					}
				}
			}
		}
		return( arr );
	}

	std::vector<cfsec::ICFSecSecSessionObj*> CFSecSecSessionTableObj::readCachedSecSessionBySecDevIdx( const uuid_ptr_t SecUserId,
			const std::string* SecDevName )
	{
		static const std::string S_ProcName( "readCachedSecSessionBySecDevIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		std::vector<cfsec::ICFSecSecSessionObj*> arr;
		cfsec::CFSecSecSessionBySecDevIdxKey key;
		key.setRequiredSecUserId( SecUserId );
		if( SecDevName == NULL ) {
			key.setOptionalSecDevNameNull();
		}
		else {
			key.setOptionalSecDevNameValue( *SecDevName );
		}
		std::map<cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj*>* dict;
		if( indexBySecDevIdx == NULL ) {
			return( arr );
		}
		auto searchIndexBySecDevIdx = indexBySecDevIdx->find( key );
		if( searchIndexBySecDevIdx != indexBySecDevIdx->end() ) {
			dict = searchIndexBySecDevIdx->second;
			size_t len = dict->size();
			std::vector<cfsec::ICFSecSecSessionObj*> arr;
			arr.reserve( len );
			auto valIter = dict->begin();
			while( valIter != dict->end() ) {
				arr.push_back( valIter->second );
				valIter ++;
			}
		}
		else {
			cfsec::ICFSecSecSessionObj* obj;
			for( auto iterMembers = members->begin(); iterMembers != members->end(); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecSecSessionBuff*>( obj->getBuff() ) ) == key ) {
						arr.push_back( obj );
					}
				}
			}
		}
		return( arr );
	}

	cfsec::ICFSecSecSessionObj* CFSecSecSessionTableObj::readCachedSecSessionByStartIdx( const uuid_ptr_t SecUserId,
			const std::chrono::system_clock::time_point& Start )
	{
		static const std::string S_ProcName( "readCachedSecSessionByStartIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByStartIdx == NULL ) {
			indexByStartIdx = new std::map< cfsec::CFSecSecSessionByStartIdxKey,
				cfsec::ICFSecSecSessionObj*>();
		}
		cfsec::CFSecSecSessionByStartIdxKey key;
		key.setRequiredSecUserId( SecUserId );
		key.setRequiredStart( Start );
		cfsec::ICFSecSecSessionObj* obj = NULL;
		auto searchIndexByStartIdx = indexByStartIdx->find( key );
		if( searchIndexByStartIdx != indexByStartIdx->end() ) {
			// Note: obj may be null if cache misses is enabled
			obj = searchIndexByStartIdx->second;
		}
		else {
			for( auto iterMembers = members->begin(); ( obj == NULL ) && ( iterMembers != members->end() ); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecSecSessionBuff*>( obj->getBuff() ) ) != key ) {
						obj = NULL;
					}
				}
			}
		}
		return( obj );
	}

	std::vector<cfsec::ICFSecSecSessionObj*> CFSecSecSessionTableObj::readCachedSecSessionByFinishIdx( const uuid_ptr_t SecUserId,
			const std::chrono::system_clock::time_point* Finish )
	{
		static const std::string S_ProcName( "readCachedSecSessionByFinishIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		std::vector<cfsec::ICFSecSecSessionObj*> arr;
		cfsec::CFSecSecSessionByFinishIdxKey key;
		key.setRequiredSecUserId( SecUserId );
		if( Finish == NULL ) {
			key.setOptionalFinishNull();
		}
		else {
			key.setOptionalFinishValue( *Finish );
		}
		std::map<cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj*>* dict;
		if( indexByFinishIdx == NULL ) {
			return( arr );
		}
		auto searchIndexByFinishIdx = indexByFinishIdx->find( key );
		if( searchIndexByFinishIdx != indexByFinishIdx->end() ) {
			dict = searchIndexByFinishIdx->second;
			size_t len = dict->size();
			std::vector<cfsec::ICFSecSecSessionObj*> arr;
			arr.reserve( len );
			auto valIter = dict->begin();
			while( valIter != dict->end() ) {
				arr.push_back( valIter->second );
				valIter ++;
			}
		}
		else {
			cfsec::ICFSecSecSessionObj* obj;
			for( auto iterMembers = members->begin(); iterMembers != members->end(); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecSecSessionBuff*>( obj->getBuff() ) ) == key ) {
						arr.push_back( obj );
					}
				}
			}
		}
		return( arr );
	}

	std::vector<cfsec::ICFSecSecSessionObj*> CFSecSecSessionTableObj::readCachedSecSessionBySecProxyIdx( const uuid_ptr_t SecProxyId )
	{
		static const std::string S_ProcName( "readCachedSecSessionBySecProxyIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		std::vector<cfsec::ICFSecSecSessionObj*> arr;
		cfsec::CFSecSecSessionBySecProxyIdxKey key;
		if( SecProxyId == NULL ) {
			key.setOptionalSecProxyIdNull();
		}
		else {
			key.setOptionalSecProxyIdValue( SecProxyId );
		}
		std::map<cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj*>* dict;
		if( indexBySecProxyIdx == NULL ) {
			return( arr );
		}
		auto searchIndexBySecProxyIdx = indexBySecProxyIdx->find( key );
		if( searchIndexBySecProxyIdx != indexBySecProxyIdx->end() ) {
			dict = searchIndexBySecProxyIdx->second;
			size_t len = dict->size();
			std::vector<cfsec::ICFSecSecSessionObj*> arr;
			arr.reserve( len );
			auto valIter = dict->begin();
			while( valIter != dict->end() ) {
				arr.push_back( valIter->second );
				valIter ++;
			}
		}
		else {
			cfsec::ICFSecSecSessionObj* obj;
			for( auto iterMembers = members->begin(); iterMembers != members->end(); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecSecSessionBuff*>( obj->getBuff() ) ) == key ) {
						arr.push_back( obj );
					}
				}
			}
		}
		return( arr );
	}

	std::vector<cfsec::ICFSecSecSessionObj*> CFSecSecSessionTableObj::pageSecSessionBySecUserIdx( const uuid_ptr_t SecUserId,
			const uuid_ptr_t priorSecSessionId )
	{
		static const std::string S_ProcName( "pageSecSessionBySecUserIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSecSessionBySecUserIdxKey key;
		key.setRequiredSecUserId( SecUserId );
		cfsec::ICFSecSecSessionObj* obj;
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecSession()->pageBuffBySecUserIdx( schema->getAuthorization(),
				SecUserId,
				priorSecSessionId );
		std::vector<cfsec::ICFSecSecSessionObj*> retList;
		retList.reserve( buffList.size() );
		cfsec::CFSecSecSessionBuff* buff;
		cfsec::ICFSecSecSessionObj* realized;
		for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
			buff = buffList[ idx ];
			buffList[ idx ] = NULL;
				obj = dynamic_cast<cfsec::CFSecSecSessionTableObj*>( schema->getSecSessionTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
			obj->setBuff( buff );
			realized = dynamic_cast<cfsec::ICFSecSecSessionObj*>( obj->realize() );
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

	std::vector<cfsec::ICFSecSecSessionObj*> CFSecSecSessionTableObj::pageSecSessionBySecDevIdx( const uuid_ptr_t SecUserId,
			const std::string* SecDevName,
			const uuid_ptr_t priorSecSessionId )
	{
		static const std::string S_ProcName( "pageSecSessionBySecDevIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSecSessionBySecDevIdxKey key;
		key.setRequiredSecUserId( SecUserId );
		if( SecDevName == NULL ) {
			key.setOptionalSecDevNameNull();
		}
		else {
			key.setOptionalSecDevNameValue( *SecDevName );
		}
		cfsec::ICFSecSecSessionObj* obj;
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecSession()->pageBuffBySecDevIdx( schema->getAuthorization(),
				SecUserId,
				SecDevName,
				priorSecSessionId );
		std::vector<cfsec::ICFSecSecSessionObj*> retList;
		retList.reserve( buffList.size() );
		cfsec::CFSecSecSessionBuff* buff;
		cfsec::ICFSecSecSessionObj* realized;
		for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
			buff = buffList[ idx ];
			buffList[ idx ] = NULL;
				obj = dynamic_cast<cfsec::CFSecSecSessionTableObj*>( schema->getSecSessionTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
			obj->setBuff( buff );
			realized = dynamic_cast<cfsec::ICFSecSecSessionObj*>( obj->realize() );
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

	std::vector<cfsec::ICFSecSecSessionObj*> CFSecSecSessionTableObj::pageSecSessionByFinishIdx( const uuid_ptr_t SecUserId,
			const std::chrono::system_clock::time_point* Finish,
			const uuid_ptr_t priorSecSessionId )
	{
		static const std::string S_ProcName( "pageSecSessionByFinishIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSecSessionByFinishIdxKey key;
		key.setRequiredSecUserId( SecUserId );
		if( Finish == NULL ) {
			key.setOptionalFinishNull();
		}
		else {
			key.setOptionalFinishValue( *Finish );
		}
		cfsec::ICFSecSecSessionObj* obj;
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecSession()->pageBuffByFinishIdx( schema->getAuthorization(),
				SecUserId,
				Finish,
				priorSecSessionId );
		std::vector<cfsec::ICFSecSecSessionObj*> retList;
		retList.reserve( buffList.size() );
		cfsec::CFSecSecSessionBuff* buff;
		cfsec::ICFSecSecSessionObj* realized;
		for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
			buff = buffList[ idx ];
			buffList[ idx ] = NULL;
				obj = dynamic_cast<cfsec::CFSecSecSessionTableObj*>( schema->getSecSessionTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
			obj->setBuff( buff );
			realized = dynamic_cast<cfsec::ICFSecSecSessionObj*>( obj->realize() );
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

	std::vector<cfsec::ICFSecSecSessionObj*> CFSecSecSessionTableObj::pageSecSessionBySecProxyIdx( const uuid_ptr_t SecProxyId,
			const uuid_ptr_t priorSecSessionId )
	{
		static const std::string S_ProcName( "pageSecSessionBySecProxyIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSecSessionBySecProxyIdxKey key;
		if( SecProxyId == NULL ) {
			key.setOptionalSecProxyIdNull();
		}
		else {
			key.setOptionalSecProxyIdValue( SecProxyId );
		}
		cfsec::ICFSecSecSessionObj* obj;
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecSession()->pageBuffBySecProxyIdx( schema->getAuthorization(),
				SecProxyId,
				priorSecSessionId );
		std::vector<cfsec::ICFSecSecSessionObj*> retList;
		retList.reserve( buffList.size() );
		cfsec::CFSecSecSessionBuff* buff;
		cfsec::ICFSecSecSessionObj* realized;
		for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
			buff = buffList[ idx ];
			buffList[ idx ] = NULL;
				obj = dynamic_cast<cfsec::CFSecSecSessionTableObj*>( schema->getSecSessionTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
			obj->setBuff( buff );
			realized = dynamic_cast<cfsec::ICFSecSecSessionObj*>( obj->realize() );
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

	cfsec::ICFSecSecSessionObj* CFSecSecSessionTableObj::updateSecSession( cfsec::ICFSecSecSessionEditObj* Obj ) {
		static const std::string S_ProcName( "updateSecSession" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Updated( "updated" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecSecSessionObj* obj = dynamic_cast<cfsec::ICFSecSecSessionObj*>( Obj->getOrig() );
		try {
			cfsec::CFSecSecSessionBuff* updated = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecSession()->updateSecSession( schema->getAuthorization(),
				dynamic_cast<cfsec::CFSecSecSessionBuff*>( Obj->getSecSessionBuff()->clone() ) );
			if( updated == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Updated );
			}
			obj = dynamic_cast<cfsec::ICFSecSecSessionObj*>( dynamic_cast<cfsec::CFSecSecSessionTableObj*>( schema->getSecSessionTableObj() )->newInstance() );
			obj->setBuff( updated );
			obj = dynamic_cast<cfsec::ICFSecSecSessionObj*>( obj->realize() );
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

	void CFSecSecSessionTableObj::deleteSecSession( cfsec::ICFSecSecSessionEditObj* Obj ) {
		cfsec::ICFSecSecSessionObj* obj = Obj;
		dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecSession()->deleteSecSession( schema->getAuthorization(),
			obj->getSecSessionBuff() );
		deepDisposeByIdIdx( obj->getRequiredSecSessionId() );
	}

	void CFSecSecSessionTableObj::deleteSecSessionByIdIdx( const uuid_ptr_t SecSessionId )
	{
		cfsec::CFSecSecSessionPKey pkey;
		pkey.setRequiredSecSessionId( SecSessionId );
		cfsec::ICFSecSecSessionObj* obj = readSecSession( &pkey, true );
		if( obj != NULL ) {
			cfsec::ICFSecSecSessionEditObj* editObj = dynamic_cast<cfsec::ICFSecSecSessionEditObj*>( obj->getEdit() );
			if( editObj == NULL ) {
				editObj = dynamic_cast<cfsec::ICFSecSecSessionEditObj*>( obj->beginEdit() );
			}
			if( editObj != NULL ) {
				editObj->deleteInstance();
				editObj = NULL;
			}
		}
	}

	void CFSecSecSessionTableObj::deleteSecSessionBySecUserIdx( const uuid_ptr_t SecUserId )
	{
		dynamic_cast<cfsec::ICFSecSchema*>( schema->getBackingStore() )->getTableSecSession()->deleteSecSessionBySecUserIdx( schema->getAuthorization(),
				SecUserId );
		deepDisposeBySecUserIdx( SecUserId );
	}

	void CFSecSecSessionTableObj::deleteSecSessionBySecDevIdx( const uuid_ptr_t SecUserId,
			const std::string* SecDevName )
	{
		dynamic_cast<cfsec::ICFSecSchema*>( schema->getBackingStore() )->getTableSecSession()->deleteSecSessionBySecDevIdx( schema->getAuthorization(),
				SecUserId,
				SecDevName );
		deepDisposeBySecDevIdx( SecUserId,
			SecDevName );
	}

	void CFSecSecSessionTableObj::deleteSecSessionByStartIdx( const uuid_ptr_t SecUserId,
			const std::chrono::system_clock::time_point& Start )
	{
		if( indexByStartIdx == NULL ) {
			indexByStartIdx = new std::map< cfsec::CFSecSecSessionByStartIdxKey,
				cfsec::ICFSecSecSessionObj*>();
		}
		cfsec::CFSecSecSessionByStartIdxKey key;
		key.setRequiredSecUserId( SecUserId );
		key.setRequiredStart( Start );
		cfsec::ICFSecSecSessionObj* obj = NULL;
		auto searchIndexByStartIdx = indexByStartIdx->find( key );
		if( searchIndexByStartIdx != indexByStartIdx->end() ) {
			dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecSession()->deleteSecSessionByStartIdx( schema->getAuthorization(),
				SecUserId,
				Start );
		}
		else {
			dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecSession()->deleteSecSessionByStartIdx( schema->getAuthorization(),
				SecUserId,
				Start );
		}
		deepDisposeByStartIdx( SecUserId,
			Start );
	}

	void CFSecSecSessionTableObj::deleteSecSessionByFinishIdx( const uuid_ptr_t SecUserId,
			const std::chrono::system_clock::time_point* Finish )
	{
		dynamic_cast<cfsec::ICFSecSchema*>( schema->getBackingStore() )->getTableSecSession()->deleteSecSessionByFinishIdx( schema->getAuthorization(),
				SecUserId,
				Finish );
		deepDisposeByFinishIdx( SecUserId,
			Finish );
	}

	void CFSecSecSessionTableObj::deleteSecSessionBySecProxyIdx( const uuid_ptr_t SecProxyId )
	{
		dynamic_cast<cfsec::ICFSecSchema*>( schema->getBackingStore() )->getTableSecSession()->deleteSecSessionBySecProxyIdx( schema->getAuthorization(),
				SecProxyId );
		deepDisposeBySecProxyIdx( SecProxyId );
	}

	void CFSecSecSessionTableObj::reallyDetachFromIndexesSecSession( cfsec::ICFSecSecSessionObj* Obj ) {
		static const std::string S_ProcName( "reallyDetachFromIndexesSecSession" );
		static const std::string S_Obj( "Obj" );
		static const std::string S_ExistingObj( "ExistingObj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfsec::ICFSecSecSessionObj* obj = Obj;
		cfsec::CFSecSecSessionPKey* pkey = obj->getPKey();
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			cfsec::ICFSecSecSessionObj* existingObj = searchMembers->second;
			if( existingObj == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_ExistingObj );
			}
			if( indexBySecUserIdx != NULL ) {
				cfsec::CFSecSecSessionBySecUserIdxKey keySecUserIdx;
				keySecUserIdx.setRequiredSecUserId( obj->getRequiredSecUserId() );
				auto searchSecUserIdx = indexBySecUserIdx->find( keySecUserIdx );
				if( searchSecUserIdx != indexBySecUserIdx->end() ) {
					std::map<cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj*>* mapSecUserIdx = searchSecUserIdx->second;
					if( mapSecUserIdx != NULL ) {
						auto removalProbe = mapSecUserIdx->find( *(obj->getPKey()) );
						if( removalProbe != mapSecUserIdx->end() ) {
							mapSecUserIdx->erase( removalProbe );
							if( mapSecUserIdx->empty() ) {
								delete mapSecUserIdx;
								mapSecUserIdx = NULL;
								indexBySecUserIdx->erase( searchSecUserIdx );
							}
						}
					}
				}
			}

			if( indexBySecDevIdx != NULL ) {
				cfsec::CFSecSecSessionBySecDevIdxKey keySecDevIdx;
				keySecDevIdx.setRequiredSecUserId( obj->getRequiredSecUserId() );
				if( obj->isOptionalSecDevNameNull() ) {
					keySecDevIdx.setOptionalSecDevNameNull();
				}
				else {
					keySecDevIdx.setOptionalSecDevNameValue( obj->getOptionalSecDevNameValue() );
				}
				auto searchSecDevIdx = indexBySecDevIdx->find( keySecDevIdx );
				if( searchSecDevIdx != indexBySecDevIdx->end() ) {
					std::map<cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj*>* mapSecDevIdx = searchSecDevIdx->second;
					if( mapSecDevIdx != NULL ) {
						auto removalProbe = mapSecDevIdx->find( *(obj->getPKey()) );
						if( removalProbe != mapSecDevIdx->end() ) {
							mapSecDevIdx->erase( removalProbe );
							if( mapSecDevIdx->empty() ) {
								delete mapSecDevIdx;
								mapSecDevIdx = NULL;
								indexBySecDevIdx->erase( searchSecDevIdx );
							}
						}
					}
				}
			}

			if( indexByStartIdx != NULL ) {
				cfsec::CFSecSecSessionByStartIdxKey keyStartIdx;
				keyStartIdx.setRequiredSecUserId( obj->getRequiredSecUserId() );
				keyStartIdx.setRequiredStart( obj->getRequiredStart() );
				auto removalProbe = indexByStartIdx->find( keyStartIdx );
				if( removalProbe != indexByStartIdx->end() ) {
					indexByStartIdx->erase( removalProbe );
				}
			}

			if( indexByFinishIdx != NULL ) {
				cfsec::CFSecSecSessionByFinishIdxKey keyFinishIdx;
				keyFinishIdx.setRequiredSecUserId( obj->getRequiredSecUserId() );
				if( obj->isOptionalFinishNull() ) {
					keyFinishIdx.setOptionalFinishNull();
				}
				else {
					keyFinishIdx.setOptionalFinishValue( obj->getOptionalFinishValue() );
				}
				auto searchFinishIdx = indexByFinishIdx->find( keyFinishIdx );
				if( searchFinishIdx != indexByFinishIdx->end() ) {
					std::map<cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj*>* mapFinishIdx = searchFinishIdx->second;
					if( mapFinishIdx != NULL ) {
						auto removalProbe = mapFinishIdx->find( *(obj->getPKey()) );
						if( removalProbe != mapFinishIdx->end() ) {
							mapFinishIdx->erase( removalProbe );
							if( mapFinishIdx->empty() ) {
								delete mapFinishIdx;
								mapFinishIdx = NULL;
								indexByFinishIdx->erase( searchFinishIdx );
							}
						}
					}
				}
			}

			if( indexBySecProxyIdx != NULL ) {
				cfsec::CFSecSecSessionBySecProxyIdxKey keySecProxyIdx;
				if( obj->isOptionalSecProxyIdNull() ) {
					keySecProxyIdx.setOptionalSecProxyIdNull();
				}
				else {
					keySecProxyIdx.setOptionalSecProxyIdValue( obj->getOptionalSecProxyIdValue() );
				}
				auto searchSecProxyIdx = indexBySecProxyIdx->find( keySecProxyIdx );
				if( searchSecProxyIdx != indexBySecProxyIdx->end() ) {
					std::map<cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj*>* mapSecProxyIdx = searchSecProxyIdx->second;
					if( mapSecProxyIdx != NULL ) {
						auto removalProbe = mapSecProxyIdx->find( *(obj->getPKey()) );
						if( removalProbe != mapSecProxyIdx->end() ) {
							mapSecProxyIdx->erase( removalProbe );
							if( mapSecProxyIdx->empty() ) {
								delete mapSecProxyIdx;
								mapSecProxyIdx = NULL;
								indexBySecProxyIdx->erase( searchSecProxyIdx );
							}
						}
					}
				}
			}

			members->erase( searchMembers );
		}
	}

	static cfsec::ICFSecSecSessionObj* S_systemSession = NULL;

	cfsec::ICFSecSecSessionObj* CFSecSecSessionTableObj::getSystemSession() {
		static const std::string S_ProcName( "getSystemSession" );
		static const std::string S_UserObj( "userObj" );
		bool transactionStarted = schema->beginTransaction();
		cfsec::ICFSecSecUserObj* userObj;
		cfsec::ICFSecSecSessionObj* sessionObj = S_systemSession;
		try {
			std::chrono::system_clock::time_point ts = cflib::CFLib::getUTCTimestampInstance();
			userObj = schema->getSecUserTableObj()->getSystemUser();
			if( userObj == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_UserObj );
			}
			if( sessionObj == NULL ) {
				sessionObj = readSecSessionByStartIdx( userObj->getRequiredSecUserId(),
					ts,
					true );
				if( sessionObj == NULL ) {
					sessionObj = newInstance();
					cfsec::ICFSecSecSessionEditObj* sessionEdit = sessionObj->beginEdit();
					sessionEdit->setRequiredContainerSecUser( userObj );
					sessionEdit->setRequiredStart( ts );
					sessionEdit->setOptionalFinishNull();
					sessionObj = sessionEdit->create();
					S_systemSession = sessionObj;
				}
			}
			if( transactionStarted ) {
				schema->commit();
			}
		}
		catch( std::exception& e ) {
			if( transactionStarted ) {
				try {
					schema->rollback();
				}
				catch( ... ) {
				}
			}
			throw e;
		}
		return( sessionObj );
	}


}
