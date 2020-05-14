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

	const std::string CFSecSecUserTableObj::CLASS_NAME( "CFSecSecUserTableObj" );
	const std::string CFSecSecUserTableObj::TABLE_NAME( "SecUser" );
	const std::string CFSecSecUserTableObj::TABLE_DBNAME( "SecUser" );

	CFSecSecUserTableObj::CFSecSecUserTableObj() {
		schema = NULL;
		members = new std::map<cfsec::CFSecSecUserPKey, cfsec::ICFSecSecUserObj*>();
		allSecUser = NULL;
		indexByULoginIdx = new std::map< cfsec::CFSecSecUserByULoginIdxKey,
			cfsec::ICFSecSecUserObj*>();
		indexByEMConfIdx = new std::map< cfsec::CFSecSecUserByEMConfIdxKey,
			std::map< cfsec::CFSecSecUserPKey, cfsec::ICFSecSecUserObj*>*>();
		indexByPwdResetIdx = new std::map< cfsec::CFSecSecUserByPwdResetIdxKey,
			std::map< cfsec::CFSecSecUserPKey, cfsec::ICFSecSecUserObj*>*>();
		indexByDefDevIdx = new std::map< cfsec::CFSecSecUserByDefDevIdxKey,
			std::map< cfsec::CFSecSecUserPKey, cfsec::ICFSecSecUserObj*>*>();
	}

	CFSecSecUserTableObj::CFSecSecUserTableObj( cfsec::ICFSecSchemaObj* argSchema ) {
		schema = dynamic_cast<cfsec::ICFSecSchemaObj*>( argSchema );
		members = new std::map<cfsec::CFSecSecUserPKey, cfsec::ICFSecSecUserObj*>();
		allSecUser = NULL;
		indexByULoginIdx = new std::map< cfsec::CFSecSecUserByULoginIdxKey,
			cfsec::ICFSecSecUserObj*>();
		indexByEMConfIdx = new std::map< cfsec::CFSecSecUserByEMConfIdxKey,
			std::map< cfsec::CFSecSecUserPKey, cfsec::ICFSecSecUserObj*>*>();
		indexByPwdResetIdx = new std::map< cfsec::CFSecSecUserByPwdResetIdxKey,
			std::map< cfsec::CFSecSecUserPKey, cfsec::ICFSecSecUserObj*>*>();
		indexByDefDevIdx = new std::map< cfsec::CFSecSecUserByDefDevIdxKey,
			std::map< cfsec::CFSecSecUserPKey, cfsec::ICFSecSecUserObj*>*>();
	}

	CFSecSecUserTableObj::~CFSecSecUserTableObj() {
		minimizeMemory();
		if( indexByULoginIdx != NULL ) {
			delete indexByULoginIdx;
			indexByULoginIdx = NULL;
		}
		if( indexByEMConfIdx != NULL ) {
			delete indexByEMConfIdx;
			indexByEMConfIdx = NULL;
		}
		if( indexByPwdResetIdx != NULL ) {
			delete indexByPwdResetIdx;
			indexByPwdResetIdx = NULL;
		}
		if( indexByDefDevIdx != NULL ) {
			delete indexByDefDevIdx;
			indexByDefDevIdx = NULL;
		}
		if( members != NULL ) {
			cfsec::ICFSecSecUserObj* curMember;
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

	cfsec::ICFSecSchemaObj* CFSecSecUserTableObj::getSchema() {
		return( schema );
	}

	void CFSecSecUserTableObj::setSchema( cfsec::ICFSecSchemaObj* value ) {
		schema = dynamic_cast<cfsec::ICFSecSchemaObj*>( value );
	}

	const std::string CFSecSecUserTableObj::getTableName() {
		return( TABLE_NAME );
	}

	const std::string CFSecSecUserTableObj::getTableDbName() {
		return( TABLE_DBNAME );
	}
	const classcode_t* CFSecSecUserTableObj::getObjQualifyingClassCode() {
		return( NULL );
	}


	void CFSecSecUserTableObj::minimizeMemory() {
		if( allSecUser != NULL ) {
			allSecUser->clear();
			delete allSecUser;
			allSecUser = NULL;
		}
		if( indexByULoginIdx != NULL ) {
			indexByULoginIdx->clear();
		}
		if( indexByEMConfIdx != NULL ) {
			std::map< cfsec::CFSecSecUserByEMConfIdxKey,
				std::map< cfsec::CFSecSecUserPKey, cfsec::ICFSecSecUserObj*>* >::iterator iterByEMConfIdx = indexByEMConfIdx->begin();
			std::map< cfsec::CFSecSecUserByEMConfIdxKey,
				std::map< cfsec::CFSecSecUserPKey, cfsec::ICFSecSecUserObj*>* >::iterator endByEMConfIdx = indexByEMConfIdx->end();
			std::map< cfsec::CFSecSecUserPKey, cfsec::ICFSecSecUserObj*>* curByEMConfIdx = NULL;
			while( iterByEMConfIdx != endByEMConfIdx ) {
				curByEMConfIdx = iterByEMConfIdx->second;
				if( curByEMConfIdx != NULL ) {
					curByEMConfIdx->clear();
					delete curByEMConfIdx;
					curByEMConfIdx = NULL;
					iterByEMConfIdx->second = NULL;
				}
				iterByEMConfIdx ++;
			}
			indexByEMConfIdx->clear();
		}
		if( indexByPwdResetIdx != NULL ) {
			std::map< cfsec::CFSecSecUserByPwdResetIdxKey,
				std::map< cfsec::CFSecSecUserPKey, cfsec::ICFSecSecUserObj*>* >::iterator iterByPwdResetIdx = indexByPwdResetIdx->begin();
			std::map< cfsec::CFSecSecUserByPwdResetIdxKey,
				std::map< cfsec::CFSecSecUserPKey, cfsec::ICFSecSecUserObj*>* >::iterator endByPwdResetIdx = indexByPwdResetIdx->end();
			std::map< cfsec::CFSecSecUserPKey, cfsec::ICFSecSecUserObj*>* curByPwdResetIdx = NULL;
			while( iterByPwdResetIdx != endByPwdResetIdx ) {
				curByPwdResetIdx = iterByPwdResetIdx->second;
				if( curByPwdResetIdx != NULL ) {
					curByPwdResetIdx->clear();
					delete curByPwdResetIdx;
					curByPwdResetIdx = NULL;
					iterByPwdResetIdx->second = NULL;
				}
				iterByPwdResetIdx ++;
			}
			indexByPwdResetIdx->clear();
		}
		if( indexByDefDevIdx != NULL ) {
			std::map< cfsec::CFSecSecUserByDefDevIdxKey,
				std::map< cfsec::CFSecSecUserPKey, cfsec::ICFSecSecUserObj*>* >::iterator iterByDefDevIdx = indexByDefDevIdx->begin();
			std::map< cfsec::CFSecSecUserByDefDevIdxKey,
				std::map< cfsec::CFSecSecUserPKey, cfsec::ICFSecSecUserObj*>* >::iterator endByDefDevIdx = indexByDefDevIdx->end();
			std::map< cfsec::CFSecSecUserPKey, cfsec::ICFSecSecUserObj*>* curByDefDevIdx = NULL;
			while( iterByDefDevIdx != endByDefDevIdx ) {
				curByDefDevIdx = iterByDefDevIdx->second;
				if( curByDefDevIdx != NULL ) {
					curByDefDevIdx->clear();
					delete curByDefDevIdx;
					curByDefDevIdx = NULL;
					iterByDefDevIdx->second = NULL;
				}
				iterByDefDevIdx ++;
			}
			indexByDefDevIdx->clear();
		}
		if( members != NULL ) {
			cfsec::ICFSecSecUserObj* cur = NULL;
			cfsec::ICFSecSecUserEditObj* edit = NULL;
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

	cfsec::ICFSecSecUserObj* CFSecSecUserTableObj::newInstance() {
		cfsec::ICFSecSecUserObj* inst = dynamic_cast<cfsec::ICFSecSecUserObj*>( new CFSecSecUserObj( schema ) );
		return( inst );
	}

	cfsec::ICFSecSecUserEditObj* CFSecSecUserTableObj::newEditInstance( cfsec::ICFSecSecUserObj* orig ) {
		cfsec::ICFSecSecUserEditObj* edit = dynamic_cast<cfsec::ICFSecSecUserEditObj*>( new CFSecSecUserEditObj( orig ));
		return( edit );
	}

	cfsec::ICFSecSecUserObj* CFSecSecUserTableObj::realizeSecUser( cfsec::ICFSecSecUserObj* Obj ) {
		static const std::string S_ProcName( "realizeSecUser" );
		static const std::string S_ExistingObj( "existingObj" );
		static const std::string S_KeepObj( "keepObj" );
		static const std::string S_Obj( "Obj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfsec::ICFSecSecUserObj* obj = Obj;
		cfsec::ICFSecSecUserObj* existingObj = NULL;
		cfsec::CFSecSecUserPKey* pkey = obj->getPKey();
		cfsec::ICFSecSecUserObj* keepObj = NULL;
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
			if( indexByULoginIdx != NULL ) {
				cfsec::CFSecSecUserByULoginIdxKey keyULoginIdx;
				keyULoginIdx.setRequiredLoginId( keepObj->getRequiredLoginId() );
				auto removalProbe = indexByULoginIdx->find( keyULoginIdx );
				if( removalProbe != indexByULoginIdx->end() ) {
					indexByULoginIdx->erase( removalProbe );
				}
			}

			if( indexByEMConfIdx != NULL ) {
				cfsec::CFSecSecUserByEMConfIdxKey keyEMConfIdx;
				if( keepObj->isOptionalEMailConfirmUuidNull() ) {
					keyEMConfIdx.setOptionalEMailConfirmUuidNull();
				}
				else {
					keyEMConfIdx.setOptionalEMailConfirmUuidValue( keepObj->getOptionalEMailConfirmUuidValue() );
				}
				auto searchEMConfIdx = indexByEMConfIdx->find( keyEMConfIdx );
				if( searchEMConfIdx != indexByEMConfIdx->end() ) {
					std::map<cfsec::CFSecSecUserPKey, cfsec::ICFSecSecUserObj*>* mapEMConfIdx = searchEMConfIdx->second;
					if( mapEMConfIdx != NULL ) {
						auto removalProbe = mapEMConfIdx->find( *(keepObj->getPKey()) );
						if( removalProbe != mapEMConfIdx->end() ) {
							mapEMConfIdx->erase( removalProbe );
						}
					}
				}
			}

			if( indexByPwdResetIdx != NULL ) {
				cfsec::CFSecSecUserByPwdResetIdxKey keyPwdResetIdx;
				if( keepObj->isOptionalPasswordResetUuidNull() ) {
					keyPwdResetIdx.setOptionalPasswordResetUuidNull();
				}
				else {
					keyPwdResetIdx.setOptionalPasswordResetUuidValue( keepObj->getOptionalPasswordResetUuidValue() );
				}
				auto searchPwdResetIdx = indexByPwdResetIdx->find( keyPwdResetIdx );
				if( searchPwdResetIdx != indexByPwdResetIdx->end() ) {
					std::map<cfsec::CFSecSecUserPKey, cfsec::ICFSecSecUserObj*>* mapPwdResetIdx = searchPwdResetIdx->second;
					if( mapPwdResetIdx != NULL ) {
						auto removalProbe = mapPwdResetIdx->find( *(keepObj->getPKey()) );
						if( removalProbe != mapPwdResetIdx->end() ) {
							mapPwdResetIdx->erase( removalProbe );
						}
					}
				}
			}

			if( indexByDefDevIdx != NULL ) {
				cfsec::CFSecSecUserByDefDevIdxKey keyDefDevIdx;
				if( keepObj->isOptionalDfltDevUserIdNull() ) {
					keyDefDevIdx.setOptionalDfltDevUserIdNull();
				}
				else {
					keyDefDevIdx.setOptionalDfltDevUserIdValue( keepObj->getOptionalDfltDevUserIdValue() );
				}
				if( keepObj->isOptionalDfltDevNameNull() ) {
					keyDefDevIdx.setOptionalDfltDevNameNull();
				}
				else {
					keyDefDevIdx.setOptionalDfltDevNameValue( keepObj->getOptionalDfltDevNameValue() );
				}
				auto searchDefDevIdx = indexByDefDevIdx->find( keyDefDevIdx );
				if( searchDefDevIdx != indexByDefDevIdx->end() ) {
					std::map<cfsec::CFSecSecUserPKey, cfsec::ICFSecSecUserObj*>* mapDefDevIdx = searchDefDevIdx->second;
					if( mapDefDevIdx != NULL ) {
						auto removalProbe = mapDefDevIdx->find( *(keepObj->getPKey()) );
						if( removalProbe != mapDefDevIdx->end() ) {
							mapDefDevIdx->erase( removalProbe );
						}
					}
				}
			}

			keepObj->setBuff( dynamic_cast<cfsec::CFSecSecUserBuff*>( Obj->getBuff()->clone() ) );
			// Attach new object to alternate and duplicate indexes -- PKey stays stable

			if( indexByULoginIdx != NULL ) {
				static const std::string S_AULoginIdxObj( "aULoginIdxObj" );
				cfsec::ICFSecSecUserObj* aULoginIdxObj =
					dynamic_cast<cfsec::ICFSecSecUserObj*>( keepObj );
				if( aULoginIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AULoginIdxObj );
				}
				cfsec::CFSecSecUserByULoginIdxKey keyULoginIdx;
				keyULoginIdx.setRequiredLoginId( keepObj->getRequiredLoginId() );
				indexByULoginIdx->insert( std::map< cfsec::CFSecSecUserByULoginIdxKey, cfsec::ICFSecSecUserObj* >::value_type( keyULoginIdx, aULoginIdxObj ) );
			}

			if( indexByEMConfIdx != NULL ) {
				static const std::string S_AEMConfIdxObj( "aEMConfIdxObj" );
				cfsec::ICFSecSecUserObj* aEMConfIdxObj =
					dynamic_cast<cfsec::ICFSecSecUserObj*>( keepObj );
				if( aEMConfIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AEMConfIdxObj );
				}
				cfsec::CFSecSecUserByEMConfIdxKey keyEMConfIdx;
				if( keepObj->isOptionalEMailConfirmUuidNull() ) {
					keyEMConfIdx.setOptionalEMailConfirmUuidNull();
				}
				else {
					keyEMConfIdx.setOptionalEMailConfirmUuidValue( keepObj->getOptionalEMailConfirmUuidValue() );
				}
				auto searchIndexByEMConfIdx = indexByEMConfIdx->find( keyEMConfIdx );
				if( searchIndexByEMConfIdx != indexByEMConfIdx->end() ) {
					std::map<cfsec::CFSecSecUserPKey, cfsec::ICFSecSecUserObj*>* mapEMConfIdx = searchIndexByEMConfIdx->second;
					if( mapEMConfIdx != NULL ) {
						mapEMConfIdx->insert( std::map< cfsec::CFSecSecUserPKey, cfsec::ICFSecSecUserObj* >::value_type( *(keepObj->getPKey()), aEMConfIdxObj ) );
					}
				}
			}

			if( indexByPwdResetIdx != NULL ) {
				static const std::string S_APwdResetIdxObj( "aPwdResetIdxObj" );
				cfsec::ICFSecSecUserObj* aPwdResetIdxObj =
					dynamic_cast<cfsec::ICFSecSecUserObj*>( keepObj );
				if( aPwdResetIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_APwdResetIdxObj );
				}
				cfsec::CFSecSecUserByPwdResetIdxKey keyPwdResetIdx;
				if( keepObj->isOptionalPasswordResetUuidNull() ) {
					keyPwdResetIdx.setOptionalPasswordResetUuidNull();
				}
				else {
					keyPwdResetIdx.setOptionalPasswordResetUuidValue( keepObj->getOptionalPasswordResetUuidValue() );
				}
				auto searchIndexByPwdResetIdx = indexByPwdResetIdx->find( keyPwdResetIdx );
				if( searchIndexByPwdResetIdx != indexByPwdResetIdx->end() ) {
					std::map<cfsec::CFSecSecUserPKey, cfsec::ICFSecSecUserObj*>* mapPwdResetIdx = searchIndexByPwdResetIdx->second;
					if( mapPwdResetIdx != NULL ) {
						mapPwdResetIdx->insert( std::map< cfsec::CFSecSecUserPKey, cfsec::ICFSecSecUserObj* >::value_type( *(keepObj->getPKey()), aPwdResetIdxObj ) );
					}
				}
			}

			if( indexByDefDevIdx != NULL ) {
				static const std::string S_ADefDevIdxObj( "aDefDevIdxObj" );
				cfsec::ICFSecSecUserObj* aDefDevIdxObj =
					dynamic_cast<cfsec::ICFSecSecUserObj*>( keepObj );
				if( aDefDevIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ADefDevIdxObj );
				}
				cfsec::CFSecSecUserByDefDevIdxKey keyDefDevIdx;
				if( keepObj->isOptionalDfltDevUserIdNull() ) {
					keyDefDevIdx.setOptionalDfltDevUserIdNull();
				}
				else {
					keyDefDevIdx.setOptionalDfltDevUserIdValue( keepObj->getOptionalDfltDevUserIdValue() );
				}
				if( keepObj->isOptionalDfltDevNameNull() ) {
					keyDefDevIdx.setOptionalDfltDevNameNull();
				}
				else {
					keyDefDevIdx.setOptionalDfltDevNameValue( keepObj->getOptionalDfltDevNameValue() );
				}
				auto searchIndexByDefDevIdx = indexByDefDevIdx->find( keyDefDevIdx );
				if( searchIndexByDefDevIdx != indexByDefDevIdx->end() ) {
					std::map<cfsec::CFSecSecUserPKey, cfsec::ICFSecSecUserObj*>* mapDefDevIdx = searchIndexByDefDevIdx->second;
					if( mapDefDevIdx != NULL ) {
						mapDefDevIdx->insert( std::map< cfsec::CFSecSecUserPKey, cfsec::ICFSecSecUserObj* >::value_type( *(keepObj->getPKey()), aDefDevIdxObj ) );
					}
				}
			}

			if( allSecUser != NULL ) {
				allSecUser->insert( std::map< cfsec::CFSecSecUserPKey, cfsec::ICFSecSecUserObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			}
		}
		else {
			keepObj = obj;
			keepObj->setIsNew( false );
			pkey = keepObj->getPKey();
			// Attach new object to PKey, all, alternate, and duplicate indexes
			members->insert( std::map< cfsec::CFSecSecUserPKey, cfsec::ICFSecSecUserObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			// Attach new object to alternate and duplicate indexes -- PKey stay stable

			if( indexByULoginIdx != NULL ) {
				static const std::string S_AULoginIdxObj( "aULoginIdxObj" );
				cfsec::ICFSecSecUserObj* aULoginIdxObj =
					dynamic_cast<cfsec::ICFSecSecUserObj*>( keepObj );
				if( aULoginIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AULoginIdxObj );
				}
				cfsec::CFSecSecUserByULoginIdxKey keyULoginIdx;
				keyULoginIdx.setRequiredLoginId( keepObj->getRequiredLoginId() );
				indexByULoginIdx->insert( std::map< cfsec::CFSecSecUserByULoginIdxKey, cfsec::ICFSecSecUserObj* >::value_type( keyULoginIdx, aULoginIdxObj ) );
			}

			if( indexByEMConfIdx != NULL ) {
				static const std::string S_AEMConfIdxObj( "aEMConfIdxObj" );
				cfsec::ICFSecSecUserObj* aEMConfIdxObj =
					dynamic_cast<cfsec::ICFSecSecUserObj*>( keepObj );
				if( aEMConfIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AEMConfIdxObj );
				}
				cfsec::CFSecSecUserByEMConfIdxKey keyEMConfIdx;
				if( keepObj->isOptionalEMailConfirmUuidNull() ) {
					keyEMConfIdx.setOptionalEMailConfirmUuidNull();
				}
				else {
					keyEMConfIdx.setOptionalEMailConfirmUuidValue( keepObj->getOptionalEMailConfirmUuidValue() );
				}
				auto searchIndexByEMConfIdx = indexByEMConfIdx->find( keyEMConfIdx );
				if( searchIndexByEMConfIdx != indexByEMConfIdx->end() ) {
					std::map<cfsec::CFSecSecUserPKey, cfsec::ICFSecSecUserObj*>* mapEMConfIdx = searchIndexByEMConfIdx->second;
					if( mapEMConfIdx != NULL ) {
						mapEMConfIdx->insert( std::map< cfsec::CFSecSecUserPKey, cfsec::ICFSecSecUserObj* >::value_type( *(keepObj->getPKey()), aEMConfIdxObj ) );
					}
				}
			}

			if( indexByPwdResetIdx != NULL ) {
				static const std::string S_APwdResetIdxObj( "aPwdResetIdxObj" );
				cfsec::ICFSecSecUserObj* aPwdResetIdxObj =
					dynamic_cast<cfsec::ICFSecSecUserObj*>( keepObj );
				if( aPwdResetIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_APwdResetIdxObj );
				}
				cfsec::CFSecSecUserByPwdResetIdxKey keyPwdResetIdx;
				if( keepObj->isOptionalPasswordResetUuidNull() ) {
					keyPwdResetIdx.setOptionalPasswordResetUuidNull();
				}
				else {
					keyPwdResetIdx.setOptionalPasswordResetUuidValue( keepObj->getOptionalPasswordResetUuidValue() );
				}
				auto searchIndexByPwdResetIdx = indexByPwdResetIdx->find( keyPwdResetIdx );
				if( searchIndexByPwdResetIdx != indexByPwdResetIdx->end() ) {
					std::map<cfsec::CFSecSecUserPKey, cfsec::ICFSecSecUserObj*>* mapPwdResetIdx = searchIndexByPwdResetIdx->second;
					if( mapPwdResetIdx != NULL ) {
						mapPwdResetIdx->insert( std::map< cfsec::CFSecSecUserPKey, cfsec::ICFSecSecUserObj* >::value_type( *(keepObj->getPKey()), aPwdResetIdxObj ) );
					}
				}
			}

			if( indexByDefDevIdx != NULL ) {
				static const std::string S_ADefDevIdxObj( "aDefDevIdxObj" );
				cfsec::ICFSecSecUserObj* aDefDevIdxObj =
					dynamic_cast<cfsec::ICFSecSecUserObj*>( keepObj );
				if( aDefDevIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ADefDevIdxObj );
				}
				cfsec::CFSecSecUserByDefDevIdxKey keyDefDevIdx;
				if( keepObj->isOptionalDfltDevUserIdNull() ) {
					keyDefDevIdx.setOptionalDfltDevUserIdNull();
				}
				else {
					keyDefDevIdx.setOptionalDfltDevUserIdValue( keepObj->getOptionalDfltDevUserIdValue() );
				}
				if( keepObj->isOptionalDfltDevNameNull() ) {
					keyDefDevIdx.setOptionalDfltDevNameNull();
				}
				else {
					keyDefDevIdx.setOptionalDfltDevNameValue( keepObj->getOptionalDfltDevNameValue() );
				}
				auto searchIndexByDefDevIdx = indexByDefDevIdx->find( keyDefDevIdx );
				if( searchIndexByDefDevIdx != indexByDefDevIdx->end() ) {
					std::map<cfsec::CFSecSecUserPKey, cfsec::ICFSecSecUserObj*>* mapDefDevIdx = searchIndexByDefDevIdx->second;
					if( mapDefDevIdx != NULL ) {
						mapDefDevIdx->insert( std::map< cfsec::CFSecSecUserPKey, cfsec::ICFSecSecUserObj* >::value_type( *(keepObj->getPKey()), aDefDevIdxObj ) );
					}
				}
			}

			if( allSecUser != NULL ) {
				allSecUser->insert( std::map< cfsec::CFSecSecUserPKey, cfsec::ICFSecSecUserObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
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

	void CFSecSecUserTableObj::deepDisposeByIdIdx( const uuid_ptr_t SecUserId ) {
		static const std::string S_ProcName( "deepDisposeByIdIdx" );
		std::vector<cfsec::ICFSecSecUserObj*> list;
		cfsec::ICFSecSecUserObj* existingObj = readCachedSecUserByIdIdx( SecUserId );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfsec::ICFSecSecUserObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecSecUserBuff::CLASS_CODE ) {
					dynamic_cast<cfsec::CFSecSecUserTableObj*>( schema->getSecUserTableObj() )->reallyDeepDisposeSecUser( dynamic_cast<cfsec::ICFSecSecUserObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFSecSecUserTableObj::deepDisposeByULoginIdx( const std::string& LoginId ) {
		static const std::string S_ProcName( "deepDisposeByULoginIdx" );
		std::vector<cfsec::ICFSecSecUserObj*> list;
		cfsec::ICFSecSecUserObj* existingObj = readCachedSecUserByULoginIdx( LoginId );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfsec::ICFSecSecUserObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecSecUserBuff::CLASS_CODE ) {
					dynamic_cast<cfsec::CFSecSecUserTableObj*>( schema->getSecUserTableObj() )->reallyDeepDisposeSecUser( dynamic_cast<cfsec::ICFSecSecUserObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFSecSecUserTableObj::deepDisposeByEMConfIdx( const uuid_ptr_t EMailConfirmUuid ) {
		static const std::string S_ProcName( "deepDisposeByEMConfIdx" );
		std::vector<cfsec::ICFSecSecUserObj*> list;
		std::vector<cfsec::ICFSecSecUserObj*> matchesFound = readCachedSecUserByEMConfIdx( EMailConfirmUuid );
		auto iterMatches = matchesFound.begin();
		auto endMatches = matchesFound.end();
		while( iterMatches != endMatches ) {
			if( *iterMatches != NULL ) {
				list.push_back( *iterMatches );
			}
			iterMatches ++;
		}
		cfsec::ICFSecSecUserObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecSecUserBuff::CLASS_CODE ) {
					dynamic_cast<cfsec::CFSecSecUserTableObj*>( schema->getSecUserTableObj() )->reallyDeepDisposeSecUser( dynamic_cast<cfsec::ICFSecSecUserObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFSecSecUserTableObj::deepDisposeByPwdResetIdx( const uuid_ptr_t PasswordResetUuid ) {
		static const std::string S_ProcName( "deepDisposeByPwdResetIdx" );
		std::vector<cfsec::ICFSecSecUserObj*> list;
		std::vector<cfsec::ICFSecSecUserObj*> matchesFound = readCachedSecUserByPwdResetIdx( PasswordResetUuid );
		auto iterMatches = matchesFound.begin();
		auto endMatches = matchesFound.end();
		while( iterMatches != endMatches ) {
			if( *iterMatches != NULL ) {
				list.push_back( *iterMatches );
			}
			iterMatches ++;
		}
		cfsec::ICFSecSecUserObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecSecUserBuff::CLASS_CODE ) {
					dynamic_cast<cfsec::CFSecSecUserTableObj*>( schema->getSecUserTableObj() )->reallyDeepDisposeSecUser( dynamic_cast<cfsec::ICFSecSecUserObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFSecSecUserTableObj::deepDisposeByDefDevIdx( const uuid_ptr_t DfltDevUserId,
			const std::string* DfltDevName ) {
		static const std::string S_ProcName( "deepDisposeByDefDevIdx" );
		std::vector<cfsec::ICFSecSecUserObj*> list;
		std::vector<cfsec::ICFSecSecUserObj*> matchesFound = readCachedSecUserByDefDevIdx( DfltDevUserId,
				DfltDevName );
		auto iterMatches = matchesFound.begin();
		auto endMatches = matchesFound.end();
		while( iterMatches != endMatches ) {
			if( *iterMatches != NULL ) {
				list.push_back( *iterMatches );
			}
			iterMatches ++;
		}
		cfsec::ICFSecSecUserObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecSecUserBuff::CLASS_CODE ) {
					dynamic_cast<cfsec::CFSecSecUserTableObj*>( schema->getSecUserTableObj() )->reallyDeepDisposeSecUser( dynamic_cast<cfsec::ICFSecSecUserObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFSecSecUserTableObj::reallyDeepDisposeSecUser( cfsec::ICFSecSecUserObj* Obj ) {
		static const std::string S_ProcName( "reallyDeepDisposeSecUser" );

		if( Obj == NULL ) {
			return;
		}

		cfsec::ICFSecSecUserObj* obj = Obj;
		
		dynamic_cast<cfsec::CFSecTSecGrpMembTableObj*>( schema->getTSecGrpMembTableObj() )->deepDisposeByUserIdx( obj->getRequiredSecUserId() );
		dynamic_cast<cfsec::CFSecSecGrpMembTableObj*>( schema->getSecGrpMembTableObj() )->deepDisposeByUserIdx( obj->getRequiredSecUserId() );
		dynamic_cast<cfsec::CFSecSecSessionTableObj*>( schema->getSecSessionTableObj() )->deepDisposeBySecUserIdx( obj->getRequiredSecUserId() );
		dynamic_cast<cfsec::CFSecSecSessionTableObj*>( schema->getSecSessionTableObj() )->deepDisposeBySecProxyIdx( obj->getRequiredSecUserIdReference() );
		dynamic_cast<cfsec::CFSecSecDeviceTableObj*>( schema->getSecDeviceTableObj() )->deepDisposeByUserIdx( obj->getRequiredSecUserId() );
		classcode_t classCode = obj->getClassCode();
		if( classCode == cfsec::CFSecSecUserBuff::CLASS_CODE ) {
			dynamic_cast<cfsec::CFSecSecUserTableObj*>( schema->getSecUserTableObj() )->reallyDetachFromIndexesSecUser( dynamic_cast<cfsec::ICFSecSecUserObj*>( obj ) );
		}

		if( obj->getEdit() != NULL ) {
			obj->endEdit();
		}
		delete obj;
		obj = NULL;
	}

	cfsec::ICFSecSecUserObj* CFSecSecUserTableObj::createSecUser( cfsec::ICFSecSecUserEditObj* Obj ) {
		static const std::string S_ProcName( "createSecUser" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Cloneable( "cloneable" );
		static const std::string S_ClonedBuff( "clonedbuff" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecSecUserObj* obj = dynamic_cast<cfsec::ICFSecSecUserObj*>( Obj->getOrig() );
		try {
			cfsec::CFSecSecUserBuff* buff = dynamic_cast<cfsec::CFSecSecUserBuff*>( Obj->getBuff()->clone() );
			// C++18 version of create returns a new buffer instance and takes over ownership of the passed-in buffer
			// MSS TODO WORKING The xmsg client will need to return the buffer instance created by processing
			// the response message, while xmsg rqst will have to delete the backing store instance
			// it receives after preparing the reply message so that memory doesn't leak on every request.
			cflib::ICFLibCloneableObj* cloneable = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecUser()->createSecUser(
				schema->getAuthorization(),
				buff );
			if( cloneable == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Cloneable );
			}
			Obj->endEdit();
			obj->setBuff( dynamic_cast<cfsec::CFSecSecUserBuff*>( cloneable ) );
			obj = dynamic_cast<cfsec::ICFSecSecUserObj*>( obj->realize() );
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

	cfsec::ICFSecSecUserObj* CFSecSecUserTableObj::readSecUser( cfsec::CFSecSecUserPKey* pkey, bool forceRead ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readSecUser" );
		cfsec::ICFSecSecUserObj* obj = NULL;
		cfsec::ICFSecSecUserObj* realized = NULL;
		if( ! forceRead ) {
			auto searchMembers = members->find( *pkey );
			if( searchMembers != members->end() ) {
				// obj could be NULL if cache misses is enabled
				obj = searchMembers->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecSecUserBuff* readBuff = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecUser()->readDerivedByIdIdx( schema->getAuthorization(),
			pkey->getRequiredSecUserId() );
			if( readBuff != NULL ) {
			obj = dynamic_cast<cfsec::CFSecSecUserTableObj*>( schema->getSecUserTableObj() )->newInstance();
				obj->setBuff( readBuff );
				realized = dynamic_cast<cfsec::ICFSecSecUserObj*>( obj->realize() );
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

	cfsec::ICFSecSecUserObj* CFSecSecUserTableObj::lockSecUser( cfsec::CFSecSecUserPKey* pkey ) {
		static const std::string S_ProcName( "lockSecUser" );
		cfsec::ICFSecSecUserObj* locked = NULL;
		cfsec::CFSecSecUserBuff* lockBuff = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecUser()->lockDerived( schema->getAuthorization(), pkey );
		if( lockBuff != NULL ) {
			locked = dynamic_cast<cfsec::CFSecSecUserTableObj*>( schema->getSecUserTableObj() )->newInstance();
			locked->setBuff( lockBuff );
			locked = dynamic_cast<cfsec::ICFSecSecUserObj*>( locked->realize() );
		}
		else {
			return( NULL );
		}
		return( locked );
	}

	std::vector<cfsec::ICFSecSecUserObj*> CFSecSecUserTableObj::readAllSecUser( bool forceRead ) {
		static const std::string S_ProcName( "readAllSecUser" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Realized( "realized" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecSecUserObj* realized = NULL;
		if( forceRead || ( allSecUser == NULL ) ) {
			std::map<cfsec::CFSecSecUserPKey, cfsec::ICFSecSecUserObj*>* map = new std::map<cfsec::CFSecSecUserPKey,cfsec::ICFSecSecUserObj*>();
			allSecUser = map;
			std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecUser()->readAllDerived( schema->getAuthorization() );
			cfsec::CFSecSecUserBuff* buff = NULL;
			cfsec::ICFSecSecUserObj* obj = NULL;
			try {
				for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
					buff = buffList[ idx ];
					buffList[ idx ] = NULL;
				obj = newInstance();
					obj->setBuff( buff );
					realized = dynamic_cast<cfsec::ICFSecSecUserObj*>( obj->realize() );
					if( realized == NULL ) {
						throw cflib::CFLibNullArgumentException( CLASS_NAME,
							S_ProcName,
							0,
							S_Realized );
					}
					allSecUser->insert( std::map< cfsec::CFSecSecUserPKey, cfsec::ICFSecSecUserObj* >::value_type( *(realized->getPKey()), realized ) );
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
		size_t len = allSecUser->size();
		std::vector<cfsec::ICFSecSecUserObj*> arr;
		auto valIter = allSecUser->begin();
		size_t idx = 0;
		while( valIter != allSecUser->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	std::vector<cfsec::ICFSecSecUserObj*> CFSecSecUserTableObj::pageAllSecUser(const uuid_ptr_t priorSecUserId )
	{
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "pageAllSecUser" );
		CFLIB_EXCEPTION_DECLINFO
		std::map<cfsec::CFSecSecUserPKey, cfsec::ICFSecSecUserObj*>* map = NULL;
		cfsec::CFSecSecUserBuff* buff = NULL;
		cfsec::ICFSecSecUserObj* obj = NULL;
		cfsec::ICFSecSecUserObj* realized = NULL;
		std::vector<cfsec::ICFSecSecUserObj*> arrayList;
		try {
			map = new std::map<cfsec::CFSecSecUserPKey,cfsec::ICFSecSecUserObj*>();
			std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecUser()->pageAllBuff( schema->getAuthorization(),
				priorSecUserId );
			arrayList.reserve( buffList.size() );
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = newInstance();
				obj->setBuff( buff );
				realized = dynamic_cast<cfsec::ICFSecSecUserObj*>( obj->realize() );
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

	cfsec::ICFSecSecUserObj* CFSecSecUserTableObj::readSecUserByIdIdx( const uuid_ptr_t SecUserId, bool forceRead )
	{
		static const std::string S_ProcName( "readSecUserByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSecUserPKey pkey;
		pkey.setRequiredSecUserId( SecUserId );
		cfsec::ICFSecSecUserObj* obj = readSecUser( &pkey, forceRead );
		return( obj );
	}

	cfsec::ICFSecSecUserObj* CFSecSecUserTableObj::readSecUserByULoginIdx( const std::string& LoginId, bool forceRead )
	{
		static const std::string S_ProcName( "readSecUserByULoginIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByULoginIdx == NULL ) {
			indexByULoginIdx = new std::map< cfsec::CFSecSecUserByULoginIdxKey,
				cfsec::ICFSecSecUserObj*>();
		}
		cfsec::CFSecSecUserByULoginIdxKey key;
		key.setRequiredLoginId( LoginId );
		cfsec::ICFSecSecUserObj* obj = NULL;
		cfsec::ICFSecSecUserObj* realized = NULL;
		if( ! forceRead ) {
			auto searchIndexByULoginIdx = indexByULoginIdx->find( key );
			if( searchIndexByULoginIdx != indexByULoginIdx->end() ) {
				// Note: obj may be null if cache misses is enabled
				obj = searchIndexByULoginIdx->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecSecUserBuff* buff = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecUser()->readDerivedByULoginIdx( schema->getAuthorization(),
				LoginId );
			if( buff != NULL ) {
				obj = dynamic_cast<cfsec::CFSecSecUserTableObj*>( schema->getSecUserTableObj() )->newInstance();
				obj->setBuff( buff );
				realized = dynamic_cast<cfsec::ICFSecSecUserObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				indexByULoginIdx->insert( std::map< cfsec::CFSecSecUserByULoginIdxKey, cfsec::ICFSecSecUserObj*>::value_type( key, dynamic_cast<cfsec::ICFSecSecUserObj*>( realized ) ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = realized;
			}
		}
		return( obj );
	}

	std::vector<cfsec::ICFSecSecUserObj*> CFSecSecUserTableObj::readSecUserByEMConfIdx( const uuid_ptr_t EMailConfirmUuid,
		bool forceRead )
	{
		static const std::string S_ProcName( "readSecUserByEMConfIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSecUserByEMConfIdxKey key;
		if( EMailConfirmUuid == NULL ) {
			key.setOptionalEMailConfirmUuidNull();
		}
		else {
			key.setOptionalEMailConfirmUuidValue( EMailConfirmUuid );
		}
		std::map<cfsec::CFSecSecUserPKey, cfsec::ICFSecSecUserObj*>* dict;
		std::map<cfsec::CFSecSecUserPKey, cfsec::ICFSecSecUserObj*>* oldDict;
		if( indexByEMConfIdx == NULL ) {
			indexByEMConfIdx = new std::map< cfsec::CFSecSecUserByEMConfIdxKey,
				std::map< cfsec::CFSecSecUserPKey, cfsec::ICFSecSecUserObj*>*>();
		}
		auto searchIndexByEMConfIdx = indexByEMConfIdx->find( key );
		if( searchIndexByEMConfIdx != indexByEMConfIdx->end() ) {
			oldDict = searchIndexByEMConfIdx->second;
		}
		else {
			oldDict = NULL;
		}
		if( ( oldDict != NULL ) && ( ! forceRead ) ) {
			dict = oldDict;
		}
		else {
			dict = new std::map<cfsec::CFSecSecUserPKey, cfsec::ICFSecSecUserObj*>();
			cfsec::ICFSecSecUserObj* obj;
			std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecUser()->readDerivedByEMConfIdx( schema->getAuthorization(),
				EMailConfirmUuid );
			cfsec::CFSecSecUserBuff* buff;
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = dynamic_cast<cfsec::CFSecSecUserTableObj*>( schema->getSecUserTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
				obj->setBuff( buff );
				cfsec::ICFSecSecUserObj* realized = dynamic_cast<cfsec::ICFSecSecUserObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				dict->insert( std::map< cfsec::CFSecSecUserPKey, cfsec::ICFSecSecUserObj* >::value_type( *(realized->getPKey()), realized ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = NULL;
			}
			if( oldDict != NULL ) {
				indexByEMConfIdx->erase( searchIndexByEMConfIdx );
				delete oldDict;
				oldDict = NULL;
			}
			indexByEMConfIdx->insert( std::map< cfsec::CFSecSecUserByEMConfIdxKey,
				std::map< cfsec::CFSecSecUserPKey, cfsec::ICFSecSecUserObj* >* >::value_type( key, dict ) );
		}
		size_t len = dict->size();
		std::vector<cfsec::ICFSecSecUserObj*> arr;
		arr.reserve( len );
		auto valIter = dict->begin();
		while( valIter != dict->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	std::vector<cfsec::ICFSecSecUserObj*> CFSecSecUserTableObj::readSecUserByPwdResetIdx( const uuid_ptr_t PasswordResetUuid,
		bool forceRead )
	{
		static const std::string S_ProcName( "readSecUserByPwdResetIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSecUserByPwdResetIdxKey key;
		if( PasswordResetUuid == NULL ) {
			key.setOptionalPasswordResetUuidNull();
		}
		else {
			key.setOptionalPasswordResetUuidValue( PasswordResetUuid );
		}
		std::map<cfsec::CFSecSecUserPKey, cfsec::ICFSecSecUserObj*>* dict;
		std::map<cfsec::CFSecSecUserPKey, cfsec::ICFSecSecUserObj*>* oldDict;
		if( indexByPwdResetIdx == NULL ) {
			indexByPwdResetIdx = new std::map< cfsec::CFSecSecUserByPwdResetIdxKey,
				std::map< cfsec::CFSecSecUserPKey, cfsec::ICFSecSecUserObj*>*>();
		}
		auto searchIndexByPwdResetIdx = indexByPwdResetIdx->find( key );
		if( searchIndexByPwdResetIdx != indexByPwdResetIdx->end() ) {
			oldDict = searchIndexByPwdResetIdx->second;
		}
		else {
			oldDict = NULL;
		}
		if( ( oldDict != NULL ) && ( ! forceRead ) ) {
			dict = oldDict;
		}
		else {
			dict = new std::map<cfsec::CFSecSecUserPKey, cfsec::ICFSecSecUserObj*>();
			cfsec::ICFSecSecUserObj* obj;
			std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecUser()->readDerivedByPwdResetIdx( schema->getAuthorization(),
				PasswordResetUuid );
			cfsec::CFSecSecUserBuff* buff;
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = dynamic_cast<cfsec::CFSecSecUserTableObj*>( schema->getSecUserTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
				obj->setBuff( buff );
				cfsec::ICFSecSecUserObj* realized = dynamic_cast<cfsec::ICFSecSecUserObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				dict->insert( std::map< cfsec::CFSecSecUserPKey, cfsec::ICFSecSecUserObj* >::value_type( *(realized->getPKey()), realized ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = NULL;
			}
			if( oldDict != NULL ) {
				indexByPwdResetIdx->erase( searchIndexByPwdResetIdx );
				delete oldDict;
				oldDict = NULL;
			}
			indexByPwdResetIdx->insert( std::map< cfsec::CFSecSecUserByPwdResetIdxKey,
				std::map< cfsec::CFSecSecUserPKey, cfsec::ICFSecSecUserObj* >* >::value_type( key, dict ) );
		}
		size_t len = dict->size();
		std::vector<cfsec::ICFSecSecUserObj*> arr;
		arr.reserve( len );
		auto valIter = dict->begin();
		while( valIter != dict->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	std::vector<cfsec::ICFSecSecUserObj*> CFSecSecUserTableObj::readSecUserByDefDevIdx( const uuid_ptr_t DfltDevUserId,
			const std::string* DfltDevName,
		bool forceRead )
	{
		static const std::string S_ProcName( "readSecUserByDefDevIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSecUserByDefDevIdxKey key;
		if( DfltDevUserId == NULL ) {
			key.setOptionalDfltDevUserIdNull();
		}
		else {
			key.setOptionalDfltDevUserIdValue( DfltDevUserId );
		}
		if( DfltDevName == NULL ) {
			key.setOptionalDfltDevNameNull();
		}
		else {
			key.setOptionalDfltDevNameValue( *DfltDevName );
		}
		std::map<cfsec::CFSecSecUserPKey, cfsec::ICFSecSecUserObj*>* dict;
		std::map<cfsec::CFSecSecUserPKey, cfsec::ICFSecSecUserObj*>* oldDict;
		if( indexByDefDevIdx == NULL ) {
			indexByDefDevIdx = new std::map< cfsec::CFSecSecUserByDefDevIdxKey,
				std::map< cfsec::CFSecSecUserPKey, cfsec::ICFSecSecUserObj*>*>();
		}
		auto searchIndexByDefDevIdx = indexByDefDevIdx->find( key );
		if( searchIndexByDefDevIdx != indexByDefDevIdx->end() ) {
			oldDict = searchIndexByDefDevIdx->second;
		}
		else {
			oldDict = NULL;
		}
		if( ( oldDict != NULL ) && ( ! forceRead ) ) {
			dict = oldDict;
		}
		else {
			dict = new std::map<cfsec::CFSecSecUserPKey, cfsec::ICFSecSecUserObj*>();
			cfsec::ICFSecSecUserObj* obj;
			std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecUser()->readDerivedByDefDevIdx( schema->getAuthorization(),
				DfltDevUserId,
				DfltDevName );
			cfsec::CFSecSecUserBuff* buff;
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = dynamic_cast<cfsec::CFSecSecUserTableObj*>( schema->getSecUserTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
				obj->setBuff( buff );
				cfsec::ICFSecSecUserObj* realized = dynamic_cast<cfsec::ICFSecSecUserObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				dict->insert( std::map< cfsec::CFSecSecUserPKey, cfsec::ICFSecSecUserObj* >::value_type( *(realized->getPKey()), realized ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = NULL;
			}
			if( oldDict != NULL ) {
				indexByDefDevIdx->erase( searchIndexByDefDevIdx );
				delete oldDict;
				oldDict = NULL;
			}
			indexByDefDevIdx->insert( std::map< cfsec::CFSecSecUserByDefDevIdxKey,
				std::map< cfsec::CFSecSecUserPKey, cfsec::ICFSecSecUserObj* >* >::value_type( key, dict ) );
		}
		size_t len = dict->size();
		std::vector<cfsec::ICFSecSecUserObj*> arr;
		arr.reserve( len );
		auto valIter = dict->begin();
		while( valIter != dict->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	cfsec::ICFSecSecUserObj* CFSecSecUserTableObj::readSecUserByLookupULoginIdx( const std::string& LoginId, bool forceRead )
	{
		static const std::string S_Realized( "realized" );
		static const std::string S_Obj( "obj" );
		static const std::string S_ProcName( "readSecUserByLookupULoginIdx" );
		if( indexByULoginIdx == NULL ) {
			indexByULoginIdx = new std::map< cfsec::CFSecSecUserByULoginIdxKey,
				cfsec::ICFSecSecUserObj*>();
		}
		cfsec::CFSecSecUserByULoginIdxKey key;
		key.setRequiredLoginId( LoginId );
		cfsec::ICFSecSecUserObj* obj = NULL;
		cfsec::ICFSecSecUserObj* realized = NULL;
		if( ! forceRead ) {
			auto searchIndexByULoginIdx = indexByULoginIdx->find( key );
			if( searchIndexByULoginIdx != indexByULoginIdx->end() ) {
				obj = searchIndexByULoginIdx->second;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecSecUserBuff* buff = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecUser()->readDerivedByLookupULoginIdx( schema->getAuthorization(),
				LoginId );
			if( buff != NULL ) {
				obj = dynamic_cast<cfsec::ICFSecSecUserObj*>( dynamic_cast<cfsec::CFSecSecUserTableObj*>( schema->getSecUserTableObj() )->newInstance() );
				obj->setBuff( buff );
				realized = dynamic_cast<cfsec::ICFSecSecUserObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				indexByULoginIdx->insert( std::map< cfsec::CFSecSecUserByULoginIdxKey, cfsec::ICFSecSecUserObj*>::value_type( key, dynamic_cast<cfsec::ICFSecSecUserObj*>( realized ) ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = realized;
			}
		}
		return( obj );
	}

	cfsec::ICFSecSecUserObj* CFSecSecUserTableObj::readCachedSecUser( cfsec::CFSecSecUserPKey* pkey ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readSecUser" );
		cfsec::ICFSecSecUserObj* obj = NULL;
		cfsec::ICFSecSecUserObj* realized = NULL;
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			// obj could be NULL if cache misses is enabled
			obj = searchMembers->second;
			realized = obj;
		}
		return( realized );
	}

	cfsec::ICFSecSecUserObj* CFSecSecUserTableObj::readCachedSecUserByIdIdx( const uuid_ptr_t SecUserId )
	{
		static const std::string S_ProcName( "readCachedSecUserByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSecUserPKey pkey;
		pkey.setRequiredSecUserId( SecUserId );
		cfsec::ICFSecSecUserObj* obj = readCachedSecUser( &pkey );
		return( obj );
	}

	cfsec::ICFSecSecUserObj* CFSecSecUserTableObj::readCachedSecUserByULoginIdx( const std::string& LoginId )
	{
		static const std::string S_ProcName( "readCachedSecUserByULoginIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByULoginIdx == NULL ) {
			indexByULoginIdx = new std::map< cfsec::CFSecSecUserByULoginIdxKey,
				cfsec::ICFSecSecUserObj*>();
		}
		cfsec::CFSecSecUserByULoginIdxKey key;
		key.setRequiredLoginId( LoginId );
		cfsec::ICFSecSecUserObj* obj = NULL;
		auto searchIndexByULoginIdx = indexByULoginIdx->find( key );
		if( searchIndexByULoginIdx != indexByULoginIdx->end() ) {
			// Note: obj may be null if cache misses is enabled
			obj = searchIndexByULoginIdx->second;
		}
		else {
			for( auto iterMembers = members->begin(); ( obj == NULL ) && ( iterMembers != members->end() ); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecSecUserBuff*>( obj->getBuff() ) ) != key ) {
						obj = NULL;
					}
				}
			}
		}
		return( obj );
	}

	std::vector<cfsec::ICFSecSecUserObj*> CFSecSecUserTableObj::readCachedSecUserByEMConfIdx( const uuid_ptr_t EMailConfirmUuid )
	{
		static const std::string S_ProcName( "readCachedSecUserByEMConfIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		std::vector<cfsec::ICFSecSecUserObj*> arr;
		cfsec::CFSecSecUserByEMConfIdxKey key;
		if( EMailConfirmUuid == NULL ) {
			key.setOptionalEMailConfirmUuidNull();
		}
		else {
			key.setOptionalEMailConfirmUuidValue( EMailConfirmUuid );
		}
		std::map<cfsec::CFSecSecUserPKey, cfsec::ICFSecSecUserObj*>* dict;
		if( indexByEMConfIdx == NULL ) {
			return( arr );
		}
		auto searchIndexByEMConfIdx = indexByEMConfIdx->find( key );
		if( searchIndexByEMConfIdx != indexByEMConfIdx->end() ) {
			dict = searchIndexByEMConfIdx->second;
			size_t len = dict->size();
			std::vector<cfsec::ICFSecSecUserObj*> arr;
			arr.reserve( len );
			auto valIter = dict->begin();
			while( valIter != dict->end() ) {
				arr.push_back( valIter->second );
				valIter ++;
			}
		}
		else {
			cfsec::ICFSecSecUserObj* obj;
			for( auto iterMembers = members->begin(); iterMembers != members->end(); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecSecUserBuff*>( obj->getBuff() ) ) == key ) {
						arr.push_back( obj );
					}
				}
			}
		}
		return( arr );
	}

	std::vector<cfsec::ICFSecSecUserObj*> CFSecSecUserTableObj::readCachedSecUserByPwdResetIdx( const uuid_ptr_t PasswordResetUuid )
	{
		static const std::string S_ProcName( "readCachedSecUserByPwdResetIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		std::vector<cfsec::ICFSecSecUserObj*> arr;
		cfsec::CFSecSecUserByPwdResetIdxKey key;
		if( PasswordResetUuid == NULL ) {
			key.setOptionalPasswordResetUuidNull();
		}
		else {
			key.setOptionalPasswordResetUuidValue( PasswordResetUuid );
		}
		std::map<cfsec::CFSecSecUserPKey, cfsec::ICFSecSecUserObj*>* dict;
		if( indexByPwdResetIdx == NULL ) {
			return( arr );
		}
		auto searchIndexByPwdResetIdx = indexByPwdResetIdx->find( key );
		if( searchIndexByPwdResetIdx != indexByPwdResetIdx->end() ) {
			dict = searchIndexByPwdResetIdx->second;
			size_t len = dict->size();
			std::vector<cfsec::ICFSecSecUserObj*> arr;
			arr.reserve( len );
			auto valIter = dict->begin();
			while( valIter != dict->end() ) {
				arr.push_back( valIter->second );
				valIter ++;
			}
		}
		else {
			cfsec::ICFSecSecUserObj* obj;
			for( auto iterMembers = members->begin(); iterMembers != members->end(); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecSecUserBuff*>( obj->getBuff() ) ) == key ) {
						arr.push_back( obj );
					}
				}
			}
		}
		return( arr );
	}

	std::vector<cfsec::ICFSecSecUserObj*> CFSecSecUserTableObj::readCachedSecUserByDefDevIdx( const uuid_ptr_t DfltDevUserId,
			const std::string* DfltDevName )
	{
		static const std::string S_ProcName( "readCachedSecUserByDefDevIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		std::vector<cfsec::ICFSecSecUserObj*> arr;
		cfsec::CFSecSecUserByDefDevIdxKey key;
		if( DfltDevUserId == NULL ) {
			key.setOptionalDfltDevUserIdNull();
		}
		else {
			key.setOptionalDfltDevUserIdValue( DfltDevUserId );
		}
		if( DfltDevName == NULL ) {
			key.setOptionalDfltDevNameNull();
		}
		else {
			key.setOptionalDfltDevNameValue( *DfltDevName );
		}
		std::map<cfsec::CFSecSecUserPKey, cfsec::ICFSecSecUserObj*>* dict;
		if( indexByDefDevIdx == NULL ) {
			return( arr );
		}
		auto searchIndexByDefDevIdx = indexByDefDevIdx->find( key );
		if( searchIndexByDefDevIdx != indexByDefDevIdx->end() ) {
			dict = searchIndexByDefDevIdx->second;
			size_t len = dict->size();
			std::vector<cfsec::ICFSecSecUserObj*> arr;
			arr.reserve( len );
			auto valIter = dict->begin();
			while( valIter != dict->end() ) {
				arr.push_back( valIter->second );
				valIter ++;
			}
		}
		else {
			cfsec::ICFSecSecUserObj* obj;
			for( auto iterMembers = members->begin(); iterMembers != members->end(); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecSecUserBuff*>( obj->getBuff() ) ) == key ) {
						arr.push_back( obj );
					}
				}
			}
		}
		return( arr );
	}

	cfsec::ICFSecSecUserObj* CFSecSecUserTableObj::readCachedSecUserByLookupULoginIdx( const std::string& LoginId )
	{
		static const std::string S_Realized( "realized" );
		static const std::string S_Obj( "obj" );
		static const std::string S_ProcName( "readCachedSecUserByLookupULoginIdx" );
		if( indexByULoginIdx == NULL ) {
			indexByULoginIdx = new std::map< cfsec::CFSecSecUserByULoginIdxKey,
				cfsec::ICFSecSecUserObj*>();
		}
		cfsec::CFSecSecUserByULoginIdxKey key;
		key.setRequiredLoginId( LoginId );
		cfsec::ICFSecSecUserObj* obj = NULL;
		cfsec::ICFSecSecUserObj* realized = NULL;
		auto searchIndexByULoginIdx = indexByULoginIdx->find( key );
		if( searchIndexByULoginIdx != indexByULoginIdx->end() ) {
			obj = searchIndexByULoginIdx->second;
		}
		else {
			for( auto iterMembers = members->begin(); ( obj == NULL ) && ( iterMembers != members->end() ); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecSecUserBuff*>( obj->getBuff() ) ) != key ) {
						obj = NULL;
					}
				}
			}
		}
		return( obj );
	}

	std::vector<cfsec::ICFSecSecUserObj*> CFSecSecUserTableObj::pageSecUserByEMConfIdx( const uuid_ptr_t EMailConfirmUuid,
			const uuid_ptr_t priorSecUserId )
	{
		static const std::string S_ProcName( "pageSecUserByEMConfIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSecUserByEMConfIdxKey key;
		if( EMailConfirmUuid == NULL ) {
			key.setOptionalEMailConfirmUuidNull();
		}
		else {
			key.setOptionalEMailConfirmUuidValue( EMailConfirmUuid );
		}
		cfsec::ICFSecSecUserObj* obj;
		std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecUser()->pageBuffByEMConfIdx( schema->getAuthorization(),
				EMailConfirmUuid,
				priorSecUserId );
		std::vector<cfsec::ICFSecSecUserObj*> retList;
		retList.reserve( buffList.size() );
		cfsec::CFSecSecUserBuff* buff;
		cfsec::ICFSecSecUserObj* realized;
		for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
			buff = buffList[ idx ];
			buffList[ idx ] = NULL;
				obj = dynamic_cast<cfsec::CFSecSecUserTableObj*>( schema->getSecUserTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
			obj->setBuff( buff );
			realized = dynamic_cast<cfsec::ICFSecSecUserObj*>( obj->realize() );
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

	std::vector<cfsec::ICFSecSecUserObj*> CFSecSecUserTableObj::pageSecUserByPwdResetIdx( const uuid_ptr_t PasswordResetUuid,
			const uuid_ptr_t priorSecUserId )
	{
		static const std::string S_ProcName( "pageSecUserByPwdResetIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSecUserByPwdResetIdxKey key;
		if( PasswordResetUuid == NULL ) {
			key.setOptionalPasswordResetUuidNull();
		}
		else {
			key.setOptionalPasswordResetUuidValue( PasswordResetUuid );
		}
		cfsec::ICFSecSecUserObj* obj;
		std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecUser()->pageBuffByPwdResetIdx( schema->getAuthorization(),
				PasswordResetUuid,
				priorSecUserId );
		std::vector<cfsec::ICFSecSecUserObj*> retList;
		retList.reserve( buffList.size() );
		cfsec::CFSecSecUserBuff* buff;
		cfsec::ICFSecSecUserObj* realized;
		for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
			buff = buffList[ idx ];
			buffList[ idx ] = NULL;
				obj = dynamic_cast<cfsec::CFSecSecUserTableObj*>( schema->getSecUserTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
			obj->setBuff( buff );
			realized = dynamic_cast<cfsec::ICFSecSecUserObj*>( obj->realize() );
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

	std::vector<cfsec::ICFSecSecUserObj*> CFSecSecUserTableObj::pageSecUserByDefDevIdx( const uuid_ptr_t DfltDevUserId,
			const std::string* DfltDevName,
			const uuid_ptr_t priorSecUserId )
	{
		static const std::string S_ProcName( "pageSecUserByDefDevIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSecUserByDefDevIdxKey key;
		if( DfltDevUserId == NULL ) {
			key.setOptionalDfltDevUserIdNull();
		}
		else {
			key.setOptionalDfltDevUserIdValue( DfltDevUserId );
		}
		if( DfltDevName == NULL ) {
			key.setOptionalDfltDevNameNull();
		}
		else {
			key.setOptionalDfltDevNameValue( *DfltDevName );
		}
		cfsec::ICFSecSecUserObj* obj;
		std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecUser()->pageBuffByDefDevIdx( schema->getAuthorization(),
				DfltDevUserId,
				DfltDevName,
				priorSecUserId );
		std::vector<cfsec::ICFSecSecUserObj*> retList;
		retList.reserve( buffList.size() );
		cfsec::CFSecSecUserBuff* buff;
		cfsec::ICFSecSecUserObj* realized;
		for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
			buff = buffList[ idx ];
			buffList[ idx ] = NULL;
				obj = dynamic_cast<cfsec::CFSecSecUserTableObj*>( schema->getSecUserTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
			obj->setBuff( buff );
			realized = dynamic_cast<cfsec::ICFSecSecUserObj*>( obj->realize() );
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

	cfsec::ICFSecSecUserObj* CFSecSecUserTableObj::updateSecUser( cfsec::ICFSecSecUserEditObj* Obj ) {
		static const std::string S_ProcName( "updateSecUser" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Updated( "updated" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecSecUserObj* obj = dynamic_cast<cfsec::ICFSecSecUserObj*>( Obj->getOrig() );
		try {
			cfsec::CFSecSecUserBuff* updated = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecUser()->updateSecUser( schema->getAuthorization(),
				dynamic_cast<cfsec::CFSecSecUserBuff*>( Obj->getSecUserBuff()->clone() ) );
			if( updated == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Updated );
			}
			obj = dynamic_cast<cfsec::ICFSecSecUserObj*>( dynamic_cast<cfsec::CFSecSecUserTableObj*>( schema->getSecUserTableObj() )->newInstance() );
			obj->setBuff( updated );
			obj = dynamic_cast<cfsec::ICFSecSecUserObj*>( obj->realize() );
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

	void CFSecSecUserTableObj::deleteSecUser( cfsec::ICFSecSecUserEditObj* Obj ) {
		cfsec::ICFSecSecUserObj* obj = Obj;
		dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecUser()->deleteSecUser( schema->getAuthorization(),
			obj->getSecUserBuff() );
		deepDisposeByIdIdx( obj->getRequiredSecUserId() );
	}

	void CFSecSecUserTableObj::deleteSecUserByIdIdx( const uuid_ptr_t SecUserId )
	{
		cfsec::CFSecSecUserPKey pkey;
		pkey.setRequiredSecUserId( SecUserId );
		cfsec::ICFSecSecUserObj* obj = readSecUser( &pkey, true );
		if( obj != NULL ) {
			cfsec::ICFSecSecUserEditObj* editObj = dynamic_cast<cfsec::ICFSecSecUserEditObj*>( obj->getEdit() );
			if( editObj == NULL ) {
				editObj = dynamic_cast<cfsec::ICFSecSecUserEditObj*>( obj->beginEdit() );
			}
			if( editObj != NULL ) {
				editObj->deleteInstance();
				editObj = NULL;
			}
		}
	}

	void CFSecSecUserTableObj::deleteSecUserByULoginIdx( const std::string& LoginId )
	{
		if( indexByULoginIdx == NULL ) {
			indexByULoginIdx = new std::map< cfsec::CFSecSecUserByULoginIdxKey,
				cfsec::ICFSecSecUserObj*>();
		}
		cfsec::CFSecSecUserByULoginIdxKey key;
		key.setRequiredLoginId( LoginId );
		cfsec::ICFSecSecUserObj* obj = NULL;
		auto searchIndexByULoginIdx = indexByULoginIdx->find( key );
		if( searchIndexByULoginIdx != indexByULoginIdx->end() ) {
			dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecUser()->deleteSecUserByULoginIdx( schema->getAuthorization(),
				LoginId );
		}
		else {
			dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecUser()->deleteSecUserByULoginIdx( schema->getAuthorization(),
				LoginId );
		}
		deepDisposeByULoginIdx( LoginId );
	}

	void CFSecSecUserTableObj::deleteSecUserByEMConfIdx( const uuid_ptr_t EMailConfirmUuid )
	{
		dynamic_cast<cfsec::ICFSecSchema*>( schema->getBackingStore() )->getTableSecUser()->deleteSecUserByEMConfIdx( schema->getAuthorization(),
				EMailConfirmUuid );
		deepDisposeByEMConfIdx( EMailConfirmUuid );
	}

	void CFSecSecUserTableObj::deleteSecUserByPwdResetIdx( const uuid_ptr_t PasswordResetUuid )
	{
		dynamic_cast<cfsec::ICFSecSchema*>( schema->getBackingStore() )->getTableSecUser()->deleteSecUserByPwdResetIdx( schema->getAuthorization(),
				PasswordResetUuid );
		deepDisposeByPwdResetIdx( PasswordResetUuid );
	}

	void CFSecSecUserTableObj::deleteSecUserByDefDevIdx( const uuid_ptr_t DfltDevUserId,
			const std::string* DfltDevName )
	{
		dynamic_cast<cfsec::ICFSecSchema*>( schema->getBackingStore() )->getTableSecUser()->deleteSecUserByDefDevIdx( schema->getAuthorization(),
				DfltDevUserId,
				DfltDevName );
		deepDisposeByDefDevIdx( DfltDevUserId,
			DfltDevName );
	}

	void CFSecSecUserTableObj::reallyDetachFromIndexesSecUser( cfsec::ICFSecSecUserObj* Obj ) {
		static const std::string S_ProcName( "reallyDetachFromIndexesSecUser" );
		static const std::string S_Obj( "Obj" );
		static const std::string S_ExistingObj( "ExistingObj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfsec::ICFSecSecUserObj* obj = Obj;
		cfsec::CFSecSecUserPKey* pkey = obj->getPKey();
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			cfsec::ICFSecSecUserObj* existingObj = searchMembers->second;
			if( existingObj == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_ExistingObj );
			}
			if( indexByULoginIdx != NULL ) {
				cfsec::CFSecSecUserByULoginIdxKey keyULoginIdx;
				keyULoginIdx.setRequiredLoginId( obj->getRequiredLoginId() );
				auto removalProbe = indexByULoginIdx->find( keyULoginIdx );
				if( removalProbe != indexByULoginIdx->end() ) {
					indexByULoginIdx->erase( removalProbe );
				}
			}

			if( indexByEMConfIdx != NULL ) {
				cfsec::CFSecSecUserByEMConfIdxKey keyEMConfIdx;
				if( obj->isOptionalEMailConfirmUuidNull() ) {
					keyEMConfIdx.setOptionalEMailConfirmUuidNull();
				}
				else {
					keyEMConfIdx.setOptionalEMailConfirmUuidValue( obj->getOptionalEMailConfirmUuidValue() );
				}
				auto searchEMConfIdx = indexByEMConfIdx->find( keyEMConfIdx );
				if( searchEMConfIdx != indexByEMConfIdx->end() ) {
					std::map<cfsec::CFSecSecUserPKey, cfsec::ICFSecSecUserObj*>* mapEMConfIdx = searchEMConfIdx->second;
					if( mapEMConfIdx != NULL ) {
						auto removalProbe = mapEMConfIdx->find( *(obj->getPKey()) );
						if( removalProbe != mapEMConfIdx->end() ) {
							mapEMConfIdx->erase( removalProbe );
							if( mapEMConfIdx->empty() ) {
								delete mapEMConfIdx;
								mapEMConfIdx = NULL;
								indexByEMConfIdx->erase( searchEMConfIdx );
							}
						}
					}
				}
			}

			if( indexByPwdResetIdx != NULL ) {
				cfsec::CFSecSecUserByPwdResetIdxKey keyPwdResetIdx;
				if( obj->isOptionalPasswordResetUuidNull() ) {
					keyPwdResetIdx.setOptionalPasswordResetUuidNull();
				}
				else {
					keyPwdResetIdx.setOptionalPasswordResetUuidValue( obj->getOptionalPasswordResetUuidValue() );
				}
				auto searchPwdResetIdx = indexByPwdResetIdx->find( keyPwdResetIdx );
				if( searchPwdResetIdx != indexByPwdResetIdx->end() ) {
					std::map<cfsec::CFSecSecUserPKey, cfsec::ICFSecSecUserObj*>* mapPwdResetIdx = searchPwdResetIdx->second;
					if( mapPwdResetIdx != NULL ) {
						auto removalProbe = mapPwdResetIdx->find( *(obj->getPKey()) );
						if( removalProbe != mapPwdResetIdx->end() ) {
							mapPwdResetIdx->erase( removalProbe );
							if( mapPwdResetIdx->empty() ) {
								delete mapPwdResetIdx;
								mapPwdResetIdx = NULL;
								indexByPwdResetIdx->erase( searchPwdResetIdx );
							}
						}
					}
				}
			}

			if( indexByDefDevIdx != NULL ) {
				cfsec::CFSecSecUserByDefDevIdxKey keyDefDevIdx;
				if( obj->isOptionalDfltDevUserIdNull() ) {
					keyDefDevIdx.setOptionalDfltDevUserIdNull();
				}
				else {
					keyDefDevIdx.setOptionalDfltDevUserIdValue( obj->getOptionalDfltDevUserIdValue() );
				}
				if( obj->isOptionalDfltDevNameNull() ) {
					keyDefDevIdx.setOptionalDfltDevNameNull();
				}
				else {
					keyDefDevIdx.setOptionalDfltDevNameValue( obj->getOptionalDfltDevNameValue() );
				}
				auto searchDefDevIdx = indexByDefDevIdx->find( keyDefDevIdx );
				if( searchDefDevIdx != indexByDefDevIdx->end() ) {
					std::map<cfsec::CFSecSecUserPKey, cfsec::ICFSecSecUserObj*>* mapDefDevIdx = searchDefDevIdx->second;
					if( mapDefDevIdx != NULL ) {
						auto removalProbe = mapDefDevIdx->find( *(obj->getPKey()) );
						if( removalProbe != mapDefDevIdx->end() ) {
							mapDefDevIdx->erase( removalProbe );
							if( mapDefDevIdx->empty() ) {
								delete mapDefDevIdx;
								mapDefDevIdx = NULL;
								indexByDefDevIdx->erase( searchDefDevIdx );
							}
						}
					}
				}
			}

			members->erase( searchMembers );
		}
	}

	cfsec::ICFSecSecUserObj* CFSecSecUserTableObj::getSystemUser() {
		static const std::string S_System( "system" );
		bool transactionStarted = schema->beginTransaction();
		cfsec::ICFSecSecUserObj* secUserObj;
		try {
			secUserObj = schema->getSecUserTableObj()->readSecUserByULoginIdx( S_System );
			if( secUserObj == NULL ) {
				secUserObj = schema->getSecUserTableObj()->readSecUserByULoginIdx( S_System, true );
				if( secUserObj == NULL ) {
					secUserObj = newInstance();
					cfsec::ICFSecSecUserEditObj* secUserEdit = secUserObj->beginEdit();
					secUserEdit->setRequiredEMailAddress( S_System );
					secUserObj = secUserEdit->create();
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
		return( secUserObj );
	}


}
