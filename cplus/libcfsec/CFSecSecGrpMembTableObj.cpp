// Description: C++18 Table Object implementation for CFSec.

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

	const std::string CFSecSecGrpMembTableObj::CLASS_NAME( "CFSecSecGrpMembTableObj" );
	const std::string CFSecSecGrpMembTableObj::TABLE_NAME( "SecGrpMemb" );
	const std::string CFSecSecGrpMembTableObj::TABLE_DBNAME( "SecMemb" );

	CFSecSecGrpMembTableObj::CFSecSecGrpMembTableObj() {
		schema = NULL;
		members = new std::map<cfsec::CFSecSecGrpMembPKey, cfsec::ICFSecSecGrpMembObj*>();
		allSecGrpMemb = NULL;
		indexByClusterIdx = new std::map< cfsec::CFSecSecGrpMembByClusterIdxKey,
			std::map< cfsec::CFSecSecGrpMembPKey, cfsec::ICFSecSecGrpMembObj*>*>();
		indexByGroupIdx = new std::map< cfsec::CFSecSecGrpMembByGroupIdxKey,
			std::map< cfsec::CFSecSecGrpMembPKey, cfsec::ICFSecSecGrpMembObj*>*>();
		indexByUserIdx = new std::map< cfsec::CFSecSecGrpMembByUserIdxKey,
			std::map< cfsec::CFSecSecGrpMembPKey, cfsec::ICFSecSecGrpMembObj*>*>();
		indexByUUserIdx = new std::map< cfsec::CFSecSecGrpMembByUUserIdxKey,
			cfsec::ICFSecSecGrpMembObj*>();
	}

	CFSecSecGrpMembTableObj::CFSecSecGrpMembTableObj( cfsec::ICFSecSchemaObj* argSchema ) {
		schema = dynamic_cast<cfsec::ICFSecSchemaObj*>( argSchema );
		members = new std::map<cfsec::CFSecSecGrpMembPKey, cfsec::ICFSecSecGrpMembObj*>();
		allSecGrpMemb = NULL;
		indexByClusterIdx = new std::map< cfsec::CFSecSecGrpMembByClusterIdxKey,
			std::map< cfsec::CFSecSecGrpMembPKey, cfsec::ICFSecSecGrpMembObj*>*>();
		indexByGroupIdx = new std::map< cfsec::CFSecSecGrpMembByGroupIdxKey,
			std::map< cfsec::CFSecSecGrpMembPKey, cfsec::ICFSecSecGrpMembObj*>*>();
		indexByUserIdx = new std::map< cfsec::CFSecSecGrpMembByUserIdxKey,
			std::map< cfsec::CFSecSecGrpMembPKey, cfsec::ICFSecSecGrpMembObj*>*>();
		indexByUUserIdx = new std::map< cfsec::CFSecSecGrpMembByUUserIdxKey,
			cfsec::ICFSecSecGrpMembObj*>();
	}

	CFSecSecGrpMembTableObj::~CFSecSecGrpMembTableObj() {
		minimizeMemory();
		if( indexByClusterIdx != NULL ) {
			delete indexByClusterIdx;
			indexByClusterIdx = NULL;
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
			cfsec::ICFSecSecGrpMembObj* curMember;
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

	cfsec::ICFSecSchemaObj* CFSecSecGrpMembTableObj::getSchema() {
		return( schema );
	}

	void CFSecSecGrpMembTableObj::setSchema( cfsec::ICFSecSchemaObj* value ) {
		schema = dynamic_cast<cfsec::ICFSecSchemaObj*>( value );
	}

	const std::string CFSecSecGrpMembTableObj::getTableName() {
		return( TABLE_NAME );
	}

	const std::string CFSecSecGrpMembTableObj::getTableDbName() {
		return( TABLE_DBNAME );
	}
	const classcode_t* CFSecSecGrpMembTableObj::getObjQualifyingClassCode() {
		return( NULL );
	}


	void CFSecSecGrpMembTableObj::minimizeMemory() {
		if( allSecGrpMemb != NULL ) {
			allSecGrpMemb->clear();
			delete allSecGrpMemb;
			allSecGrpMemb = NULL;
		}
		if( indexByClusterIdx != NULL ) {
			std::map< cfsec::CFSecSecGrpMembByClusterIdxKey,
				std::map< cfsec::CFSecSecGrpMembPKey, cfsec::ICFSecSecGrpMembObj*>* >::iterator iterByClusterIdx = indexByClusterIdx->begin();
			std::map< cfsec::CFSecSecGrpMembByClusterIdxKey,
				std::map< cfsec::CFSecSecGrpMembPKey, cfsec::ICFSecSecGrpMembObj*>* >::iterator endByClusterIdx = indexByClusterIdx->end();
			std::map< cfsec::CFSecSecGrpMembPKey, cfsec::ICFSecSecGrpMembObj*>* curByClusterIdx = NULL;
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
			std::map< cfsec::CFSecSecGrpMembByGroupIdxKey,
				std::map< cfsec::CFSecSecGrpMembPKey, cfsec::ICFSecSecGrpMembObj*>* >::iterator iterByGroupIdx = indexByGroupIdx->begin();
			std::map< cfsec::CFSecSecGrpMembByGroupIdxKey,
				std::map< cfsec::CFSecSecGrpMembPKey, cfsec::ICFSecSecGrpMembObj*>* >::iterator endByGroupIdx = indexByGroupIdx->end();
			std::map< cfsec::CFSecSecGrpMembPKey, cfsec::ICFSecSecGrpMembObj*>* curByGroupIdx = NULL;
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
			std::map< cfsec::CFSecSecGrpMembByUserIdxKey,
				std::map< cfsec::CFSecSecGrpMembPKey, cfsec::ICFSecSecGrpMembObj*>* >::iterator iterByUserIdx = indexByUserIdx->begin();
			std::map< cfsec::CFSecSecGrpMembByUserIdxKey,
				std::map< cfsec::CFSecSecGrpMembPKey, cfsec::ICFSecSecGrpMembObj*>* >::iterator endByUserIdx = indexByUserIdx->end();
			std::map< cfsec::CFSecSecGrpMembPKey, cfsec::ICFSecSecGrpMembObj*>* curByUserIdx = NULL;
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
			cfsec::ICFSecSecGrpMembObj* cur = NULL;
			cfsec::ICFSecSecGrpMembEditObj* edit = NULL;
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

	cfsec::ICFSecSecGrpMembObj* CFSecSecGrpMembTableObj::newInstance() {
		cfsec::ICFSecSecGrpMembObj* inst = dynamic_cast<cfsec::ICFSecSecGrpMembObj*>( new CFSecSecGrpMembObj( schema ) );
		return( inst );
	}

	cfsec::ICFSecSecGrpMembEditObj* CFSecSecGrpMembTableObj::newEditInstance( cfsec::ICFSecSecGrpMembObj* orig ) {
		cfsec::ICFSecSecGrpMembEditObj* edit = dynamic_cast<cfsec::ICFSecSecGrpMembEditObj*>( new CFSecSecGrpMembEditObj( orig ));
		return( edit );
	}

	cfsec::ICFSecSecGrpMembObj* CFSecSecGrpMembTableObj::realizeSecGrpMemb( cfsec::ICFSecSecGrpMembObj* Obj ) {
		static const std::string S_ProcName( "realizeSecGrpMemb" );
		static const std::string S_ExistingObj( "existingObj" );
		static const std::string S_KeepObj( "keepObj" );
		static const std::string S_Obj( "Obj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfsec::ICFSecSecGrpMembObj* obj = Obj;
		cfsec::ICFSecSecGrpMembObj* existingObj = NULL;
		cfsec::CFSecSecGrpMembPKey* pkey = obj->getPKey();
		cfsec::ICFSecSecGrpMembObj* keepObj = NULL;
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
				cfsec::CFSecSecGrpMembByClusterIdxKey keyClusterIdx;
				keyClusterIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				auto searchClusterIdx = indexByClusterIdx->find( keyClusterIdx );
				if( searchClusterIdx != indexByClusterIdx->end() ) {
					std::map<cfsec::CFSecSecGrpMembPKey, cfsec::ICFSecSecGrpMembObj*>* mapClusterIdx = searchClusterIdx->second;
					if( mapClusterIdx != NULL ) {
						auto removalProbe = mapClusterIdx->find( *(keepObj->getPKey()) );
						if( removalProbe != mapClusterIdx->end() ) {
							mapClusterIdx->erase( removalProbe );
						}
					}
				}
			}

			if( indexByGroupIdx != NULL ) {
				cfsec::CFSecSecGrpMembByGroupIdxKey keyGroupIdx;
				keyGroupIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				keyGroupIdx.setRequiredSecGroupId( keepObj->getRequiredSecGroupId() );
				auto searchGroupIdx = indexByGroupIdx->find( keyGroupIdx );
				if( searchGroupIdx != indexByGroupIdx->end() ) {
					std::map<cfsec::CFSecSecGrpMembPKey, cfsec::ICFSecSecGrpMembObj*>* mapGroupIdx = searchGroupIdx->second;
					if( mapGroupIdx != NULL ) {
						auto removalProbe = mapGroupIdx->find( *(keepObj->getPKey()) );
						if( removalProbe != mapGroupIdx->end() ) {
							mapGroupIdx->erase( removalProbe );
						}
					}
				}
			}

			if( indexByUserIdx != NULL ) {
				cfsec::CFSecSecGrpMembByUserIdxKey keyUserIdx;
				keyUserIdx.setRequiredSecUserId( keepObj->getRequiredSecUserId() );
				auto searchUserIdx = indexByUserIdx->find( keyUserIdx );
				if( searchUserIdx != indexByUserIdx->end() ) {
					std::map<cfsec::CFSecSecGrpMembPKey, cfsec::ICFSecSecGrpMembObj*>* mapUserIdx = searchUserIdx->second;
					if( mapUserIdx != NULL ) {
						auto removalProbe = mapUserIdx->find( *(keepObj->getPKey()) );
						if( removalProbe != mapUserIdx->end() ) {
							mapUserIdx->erase( removalProbe );
						}
					}
				}
			}

			if( indexByUUserIdx != NULL ) {
				cfsec::CFSecSecGrpMembByUUserIdxKey keyUUserIdx;
				keyUUserIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				keyUUserIdx.setRequiredSecGroupId( keepObj->getRequiredSecGroupId() );
				keyUUserIdx.setRequiredSecUserId( keepObj->getRequiredSecUserId() );
				auto removalProbe = indexByUUserIdx->find( keyUUserIdx );
				if( removalProbe != indexByUUserIdx->end() ) {
					indexByUUserIdx->erase( removalProbe );
				}
			}

			keepObj->setBuff( dynamic_cast<cfsec::CFSecSecGrpMembBuff*>( Obj->getBuff()->clone() ) );
			// Attach new object to alternate and duplicate indexes -- PKey stays stable

			if( indexByClusterIdx != NULL ) {
				static const std::string S_AClusterIdxObj( "aClusterIdxObj" );
				cfsec::ICFSecSecGrpMembObj* aClusterIdxObj =
					dynamic_cast<cfsec::ICFSecSecGrpMembObj*>( keepObj );
				if( aClusterIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AClusterIdxObj );
				}
				cfsec::CFSecSecGrpMembByClusterIdxKey keyClusterIdx;
				keyClusterIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				auto searchIndexByClusterIdx = indexByClusterIdx->find( keyClusterIdx );
				if( searchIndexByClusterIdx != indexByClusterIdx->end() ) {
					std::map<cfsec::CFSecSecGrpMembPKey, cfsec::ICFSecSecGrpMembObj*>* mapClusterIdx = searchIndexByClusterIdx->second;
					if( mapClusterIdx != NULL ) {
						mapClusterIdx->insert( std::map< cfsec::CFSecSecGrpMembPKey, cfsec::ICFSecSecGrpMembObj* >::value_type( *(keepObj->getPKey()), aClusterIdxObj ) );
					}
				}
			}

			if( indexByGroupIdx != NULL ) {
				static const std::string S_AGroupIdxObj( "aGroupIdxObj" );
				cfsec::ICFSecSecGrpMembObj* aGroupIdxObj =
					dynamic_cast<cfsec::ICFSecSecGrpMembObj*>( keepObj );
				if( aGroupIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AGroupIdxObj );
				}
				cfsec::CFSecSecGrpMembByGroupIdxKey keyGroupIdx;
				keyGroupIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				keyGroupIdx.setRequiredSecGroupId( keepObj->getRequiredSecGroupId() );
				auto searchIndexByGroupIdx = indexByGroupIdx->find( keyGroupIdx );
				if( searchIndexByGroupIdx != indexByGroupIdx->end() ) {
					std::map<cfsec::CFSecSecGrpMembPKey, cfsec::ICFSecSecGrpMembObj*>* mapGroupIdx = searchIndexByGroupIdx->second;
					if( mapGroupIdx != NULL ) {
						mapGroupIdx->insert( std::map< cfsec::CFSecSecGrpMembPKey, cfsec::ICFSecSecGrpMembObj* >::value_type( *(keepObj->getPKey()), aGroupIdxObj ) );
					}
				}
			}

			if( indexByUserIdx != NULL ) {
				static const std::string S_AUserIdxObj( "aUserIdxObj" );
				cfsec::ICFSecSecGrpMembObj* aUserIdxObj =
					dynamic_cast<cfsec::ICFSecSecGrpMembObj*>( keepObj );
				if( aUserIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AUserIdxObj );
				}
				cfsec::CFSecSecGrpMembByUserIdxKey keyUserIdx;
				keyUserIdx.setRequiredSecUserId( keepObj->getRequiredSecUserId() );
				auto searchIndexByUserIdx = indexByUserIdx->find( keyUserIdx );
				if( searchIndexByUserIdx != indexByUserIdx->end() ) {
					std::map<cfsec::CFSecSecGrpMembPKey, cfsec::ICFSecSecGrpMembObj*>* mapUserIdx = searchIndexByUserIdx->second;
					if( mapUserIdx != NULL ) {
						mapUserIdx->insert( std::map< cfsec::CFSecSecGrpMembPKey, cfsec::ICFSecSecGrpMembObj* >::value_type( *(keepObj->getPKey()), aUserIdxObj ) );
					}
				}
			}

			if( indexByUUserIdx != NULL ) {
				static const std::string S_AUUserIdxObj( "aUUserIdxObj" );
				cfsec::ICFSecSecGrpMembObj* aUUserIdxObj =
					dynamic_cast<cfsec::ICFSecSecGrpMembObj*>( keepObj );
				if( aUUserIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AUUserIdxObj );
				}
				cfsec::CFSecSecGrpMembByUUserIdxKey keyUUserIdx;
				keyUUserIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				keyUUserIdx.setRequiredSecGroupId( keepObj->getRequiredSecGroupId() );
				keyUUserIdx.setRequiredSecUserId( keepObj->getRequiredSecUserId() );
				indexByUUserIdx->insert( std::map< cfsec::CFSecSecGrpMembByUUserIdxKey, cfsec::ICFSecSecGrpMembObj* >::value_type( keyUUserIdx, aUUserIdxObj ) );
			}

			if( allSecGrpMemb != NULL ) {
				allSecGrpMemb->insert( std::map< cfsec::CFSecSecGrpMembPKey, cfsec::ICFSecSecGrpMembObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			}
		}
		else {
			keepObj = obj;
			keepObj->setIsNew( false );
			pkey = keepObj->getPKey();
			// Attach new object to PKey, all, alternate, and duplicate indexes
			members->insert( std::map< cfsec::CFSecSecGrpMembPKey, cfsec::ICFSecSecGrpMembObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			// Attach new object to alternate and duplicate indexes -- PKey stay stable

			if( indexByClusterIdx != NULL ) {
				static const std::string S_AClusterIdxObj( "aClusterIdxObj" );
				cfsec::ICFSecSecGrpMembObj* aClusterIdxObj =
					dynamic_cast<cfsec::ICFSecSecGrpMembObj*>( keepObj );
				if( aClusterIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AClusterIdxObj );
				}
				cfsec::CFSecSecGrpMembByClusterIdxKey keyClusterIdx;
				keyClusterIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				auto searchIndexByClusterIdx = indexByClusterIdx->find( keyClusterIdx );
				if( searchIndexByClusterIdx != indexByClusterIdx->end() ) {
					std::map<cfsec::CFSecSecGrpMembPKey, cfsec::ICFSecSecGrpMembObj*>* mapClusterIdx = searchIndexByClusterIdx->second;
					if( mapClusterIdx != NULL ) {
						mapClusterIdx->insert( std::map< cfsec::CFSecSecGrpMembPKey, cfsec::ICFSecSecGrpMembObj* >::value_type( *(keepObj->getPKey()), aClusterIdxObj ) );
					}
				}
			}

			if( indexByGroupIdx != NULL ) {
				static const std::string S_AGroupIdxObj( "aGroupIdxObj" );
				cfsec::ICFSecSecGrpMembObj* aGroupIdxObj =
					dynamic_cast<cfsec::ICFSecSecGrpMembObj*>( keepObj );
				if( aGroupIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AGroupIdxObj );
				}
				cfsec::CFSecSecGrpMembByGroupIdxKey keyGroupIdx;
				keyGroupIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				keyGroupIdx.setRequiredSecGroupId( keepObj->getRequiredSecGroupId() );
				auto searchIndexByGroupIdx = indexByGroupIdx->find( keyGroupIdx );
				if( searchIndexByGroupIdx != indexByGroupIdx->end() ) {
					std::map<cfsec::CFSecSecGrpMembPKey, cfsec::ICFSecSecGrpMembObj*>* mapGroupIdx = searchIndexByGroupIdx->second;
					if( mapGroupIdx != NULL ) {
						mapGroupIdx->insert( std::map< cfsec::CFSecSecGrpMembPKey, cfsec::ICFSecSecGrpMembObj* >::value_type( *(keepObj->getPKey()), aGroupIdxObj ) );
					}
				}
			}

			if( indexByUserIdx != NULL ) {
				static const std::string S_AUserIdxObj( "aUserIdxObj" );
				cfsec::ICFSecSecGrpMembObj* aUserIdxObj =
					dynamic_cast<cfsec::ICFSecSecGrpMembObj*>( keepObj );
				if( aUserIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AUserIdxObj );
				}
				cfsec::CFSecSecGrpMembByUserIdxKey keyUserIdx;
				keyUserIdx.setRequiredSecUserId( keepObj->getRequiredSecUserId() );
				auto searchIndexByUserIdx = indexByUserIdx->find( keyUserIdx );
				if( searchIndexByUserIdx != indexByUserIdx->end() ) {
					std::map<cfsec::CFSecSecGrpMembPKey, cfsec::ICFSecSecGrpMembObj*>* mapUserIdx = searchIndexByUserIdx->second;
					if( mapUserIdx != NULL ) {
						mapUserIdx->insert( std::map< cfsec::CFSecSecGrpMembPKey, cfsec::ICFSecSecGrpMembObj* >::value_type( *(keepObj->getPKey()), aUserIdxObj ) );
					}
				}
			}

			if( indexByUUserIdx != NULL ) {
				static const std::string S_AUUserIdxObj( "aUUserIdxObj" );
				cfsec::ICFSecSecGrpMembObj* aUUserIdxObj =
					dynamic_cast<cfsec::ICFSecSecGrpMembObj*>( keepObj );
				if( aUUserIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AUUserIdxObj );
				}
				cfsec::CFSecSecGrpMembByUUserIdxKey keyUUserIdx;
				keyUUserIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				keyUUserIdx.setRequiredSecGroupId( keepObj->getRequiredSecGroupId() );
				keyUUserIdx.setRequiredSecUserId( keepObj->getRequiredSecUserId() );
				indexByUUserIdx->insert( std::map< cfsec::CFSecSecGrpMembByUUserIdxKey, cfsec::ICFSecSecGrpMembObj* >::value_type( keyUUserIdx, aUUserIdxObj ) );
			}

			if( allSecGrpMemb != NULL ) {
				allSecGrpMemb->insert( std::map< cfsec::CFSecSecGrpMembPKey, cfsec::ICFSecSecGrpMembObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
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

	void CFSecSecGrpMembTableObj::deepDisposeByIdIdx( const int64_t ClusterId,
			const int64_t SecGrpMembId ) {
		static const std::string S_ProcName( "deepDisposeByIdIdx" );
		std::vector<cfsec::ICFSecSecGrpMembObj*> list;
		cfsec::ICFSecSecGrpMembObj* existingObj = readCachedSecGrpMembByIdIdx( ClusterId,
				SecGrpMembId );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfsec::ICFSecSecGrpMembObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecSecGrpMembBuff::CLASS_CODE ) {
					dynamic_cast<cfsec::CFSecSecGrpMembTableObj*>( schema->getSecGrpMembTableObj() )->reallyDeepDisposeSecGrpMemb( dynamic_cast<cfsec::ICFSecSecGrpMembObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFSecSecGrpMembTableObj::deepDisposeByClusterIdx( const int64_t ClusterId ) {
		static const std::string S_ProcName( "deepDisposeByClusterIdx" );
		std::vector<cfsec::ICFSecSecGrpMembObj*> list;
		std::vector<cfsec::ICFSecSecGrpMembObj*> matchesFound = readCachedSecGrpMembByClusterIdx( ClusterId );
		auto iterMatches = matchesFound.begin();
		auto endMatches = matchesFound.end();
		while( iterMatches != endMatches ) {
			if( *iterMatches != NULL ) {
				list.push_back( *iterMatches );
			}
			iterMatches ++;
		}
		cfsec::ICFSecSecGrpMembObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecSecGrpMembBuff::CLASS_CODE ) {
					dynamic_cast<cfsec::CFSecSecGrpMembTableObj*>( schema->getSecGrpMembTableObj() )->reallyDeepDisposeSecGrpMemb( dynamic_cast<cfsec::ICFSecSecGrpMembObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFSecSecGrpMembTableObj::deepDisposeByGroupIdx( const int64_t ClusterId,
			const int32_t SecGroupId ) {
		static const std::string S_ProcName( "deepDisposeByGroupIdx" );
		std::vector<cfsec::ICFSecSecGrpMembObj*> list;
		std::vector<cfsec::ICFSecSecGrpMembObj*> matchesFound = readCachedSecGrpMembByGroupIdx( ClusterId,
				SecGroupId );
		auto iterMatches = matchesFound.begin();
		auto endMatches = matchesFound.end();
		while( iterMatches != endMatches ) {
			if( *iterMatches != NULL ) {
				list.push_back( *iterMatches );
			}
			iterMatches ++;
		}
		cfsec::ICFSecSecGrpMembObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecSecGrpMembBuff::CLASS_CODE ) {
					dynamic_cast<cfsec::CFSecSecGrpMembTableObj*>( schema->getSecGrpMembTableObj() )->reallyDeepDisposeSecGrpMemb( dynamic_cast<cfsec::ICFSecSecGrpMembObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFSecSecGrpMembTableObj::deepDisposeByUserIdx( const uuid_ptr_t SecUserId ) {
		static const std::string S_ProcName( "deepDisposeByUserIdx" );
		std::vector<cfsec::ICFSecSecGrpMembObj*> list;
		std::vector<cfsec::ICFSecSecGrpMembObj*> matchesFound = readCachedSecGrpMembByUserIdx( SecUserId );
		auto iterMatches = matchesFound.begin();
		auto endMatches = matchesFound.end();
		while( iterMatches != endMatches ) {
			if( *iterMatches != NULL ) {
				list.push_back( *iterMatches );
			}
			iterMatches ++;
		}
		cfsec::ICFSecSecGrpMembObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecSecGrpMembBuff::CLASS_CODE ) {
					dynamic_cast<cfsec::CFSecSecGrpMembTableObj*>( schema->getSecGrpMembTableObj() )->reallyDeepDisposeSecGrpMemb( dynamic_cast<cfsec::ICFSecSecGrpMembObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFSecSecGrpMembTableObj::deepDisposeByUUserIdx( const int64_t ClusterId,
			const int32_t SecGroupId,
			const uuid_ptr_t SecUserId ) {
		static const std::string S_ProcName( "deepDisposeByUUserIdx" );
		std::vector<cfsec::ICFSecSecGrpMembObj*> list;
		cfsec::ICFSecSecGrpMembObj* existingObj = readCachedSecGrpMembByUUserIdx( ClusterId,
				SecGroupId,
				SecUserId );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfsec::ICFSecSecGrpMembObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecSecGrpMembBuff::CLASS_CODE ) {
					dynamic_cast<cfsec::CFSecSecGrpMembTableObj*>( schema->getSecGrpMembTableObj() )->reallyDeepDisposeSecGrpMemb( dynamic_cast<cfsec::ICFSecSecGrpMembObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFSecSecGrpMembTableObj::reallyDeepDisposeSecGrpMemb( cfsec::ICFSecSecGrpMembObj* Obj ) {
		static const std::string S_ProcName( "reallyDeepDisposeSecGrpMemb" );

		if( Obj == NULL ) {
			return;
		}

		cfsec::ICFSecSecGrpMembObj* obj = Obj;
		
		classcode_t classCode = obj->getClassCode();
		if( classCode == cfsec::CFSecSecGrpMembBuff::CLASS_CODE ) {
			dynamic_cast<cfsec::CFSecSecGrpMembTableObj*>( schema->getSecGrpMembTableObj() )->reallyDetachFromIndexesSecGrpMemb( dynamic_cast<cfsec::ICFSecSecGrpMembObj*>( obj ) );
		}

		if( obj->getEdit() != NULL ) {
			obj->endEdit();
		}
		delete obj;
		obj = NULL;
	}

	cfsec::ICFSecSecGrpMembObj* CFSecSecGrpMembTableObj::createSecGrpMemb( cfsec::ICFSecSecGrpMembEditObj* Obj ) {
		static const std::string S_ProcName( "createSecGrpMemb" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Cloneable( "cloneable" );
		static const std::string S_ClonedBuff( "clonedbuff" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecSecGrpMembObj* obj = dynamic_cast<cfsec::ICFSecSecGrpMembObj*>( Obj->getOrig() );
		try {
			cfsec::CFSecSecGrpMembBuff* buff = dynamic_cast<cfsec::CFSecSecGrpMembBuff*>( Obj->getBuff()->clone() );
			// C++18 version of create returns a new buffer instance and takes over ownership of the passed-in buffer
			// MSS TODO WORKING The xmsg client will need to return the buffer instance created by processing
			// the response message, while xmsg rqst will have to delete the backing store instance
			// it receives after preparing the reply message so that memory doesn't leak on every request.
			cflib::ICFLibCloneableObj* cloneable = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecGrpMemb()->createSecGrpMemb(
				schema->getAuthorization(),
				buff );
			if( cloneable == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Cloneable );
			}
			Obj->endEdit();
			obj->setBuff( dynamic_cast<cfsec::CFSecSecGrpMembBuff*>( cloneable ) );
			obj = dynamic_cast<cfsec::ICFSecSecGrpMembObj*>( obj->realize() );
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

	cfsec::ICFSecSecGrpMembObj* CFSecSecGrpMembTableObj::readSecGrpMemb( cfsec::CFSecSecGrpMembPKey* pkey, bool forceRead ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readSecGrpMemb" );
		cfsec::ICFSecSecGrpMembObj* obj = NULL;
		cfsec::ICFSecSecGrpMembObj* realized = NULL;
		if( ! forceRead ) {
			auto searchMembers = members->find( *pkey );
			if( searchMembers != members->end() ) {
				// obj could be NULL if cache misses is enabled
				obj = searchMembers->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecSecGrpMembBuff* readBuff = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecGrpMemb()->readDerivedByIdIdx( schema->getAuthorization(),
			pkey->getRequiredClusterId(),
			pkey->getRequiredSecGrpMembId() );
			if( readBuff != NULL ) {
			obj = dynamic_cast<cfsec::CFSecSecGrpMembTableObj*>( schema->getSecGrpMembTableObj() )->newInstance();
				obj->setBuff( readBuff );
				realized = dynamic_cast<cfsec::ICFSecSecGrpMembObj*>( obj->realize() );
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

	cfsec::ICFSecSecGrpMembObj* CFSecSecGrpMembTableObj::lockSecGrpMemb( cfsec::CFSecSecGrpMembPKey* pkey ) {
		static const std::string S_ProcName( "lockSecGrpMemb" );
		cfsec::ICFSecSecGrpMembObj* locked = NULL;
		cfsec::CFSecSecGrpMembBuff* lockBuff = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecGrpMemb()->lockDerived( schema->getAuthorization(), pkey );
		if( lockBuff != NULL ) {
			locked = dynamic_cast<cfsec::CFSecSecGrpMembTableObj*>( schema->getSecGrpMembTableObj() )->newInstance();
			locked->setBuff( lockBuff );
			locked = dynamic_cast<cfsec::ICFSecSecGrpMembObj*>( locked->realize() );
		}
		else {
			return( NULL );
		}
		return( locked );
	}

	std::vector<cfsec::ICFSecSecGrpMembObj*> CFSecSecGrpMembTableObj::readAllSecGrpMemb( bool forceRead ) {
		static const std::string S_ProcName( "readAllSecGrpMemb" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Realized( "realized" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecSecGrpMembObj* realized = NULL;
		if( forceRead || ( allSecGrpMemb == NULL ) ) {
			std::map<cfsec::CFSecSecGrpMembPKey, cfsec::ICFSecSecGrpMembObj*>* map = new std::map<cfsec::CFSecSecGrpMembPKey,cfsec::ICFSecSecGrpMembObj*>();
			allSecGrpMemb = map;
			std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecGrpMemb()->readAllDerived( schema->getAuthorization() );
			cfsec::CFSecSecGrpMembBuff* buff = NULL;
			cfsec::ICFSecSecGrpMembObj* obj = NULL;
			try {
				for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
					buff = buffList[ idx ];
					buffList[ idx ] = NULL;
				obj = newInstance();
					obj->setBuff( buff );
					realized = dynamic_cast<cfsec::ICFSecSecGrpMembObj*>( obj->realize() );
					if( realized == NULL ) {
						throw cflib::CFLibNullArgumentException( CLASS_NAME,
							S_ProcName,
							0,
							S_Realized );
					}
					allSecGrpMemb->insert( std::map< cfsec::CFSecSecGrpMembPKey, cfsec::ICFSecSecGrpMembObj* >::value_type( *(realized->getPKey()), realized ) );
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
		size_t len = allSecGrpMemb->size();
		std::vector<cfsec::ICFSecSecGrpMembObj*> arr;
		auto valIter = allSecGrpMemb->begin();
		size_t idx = 0;
		while( valIter != allSecGrpMemb->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	std::vector<cfsec::ICFSecSecGrpMembObj*> CFSecSecGrpMembTableObj::pageAllSecGrpMemb(const int64_t* priorClusterId,
			const int64_t* priorSecGrpMembId )
	{
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "pageAllSecGrpMemb" );
		CFLIB_EXCEPTION_DECLINFO
		std::map<cfsec::CFSecSecGrpMembPKey, cfsec::ICFSecSecGrpMembObj*>* map = NULL;
		cfsec::CFSecSecGrpMembBuff* buff = NULL;
		cfsec::ICFSecSecGrpMembObj* obj = NULL;
		cfsec::ICFSecSecGrpMembObj* realized = NULL;
		std::vector<cfsec::ICFSecSecGrpMembObj*> arrayList;
		try {
			map = new std::map<cfsec::CFSecSecGrpMembPKey,cfsec::ICFSecSecGrpMembObj*>();
			std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecGrpMemb()->pageAllBuff( schema->getAuthorization(),
				priorClusterId,
				priorSecGrpMembId );
			arrayList.reserve( buffList.size() );
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = newInstance();
				obj->setBuff( buff );
				realized = dynamic_cast<cfsec::ICFSecSecGrpMembObj*>( obj->realize() );
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

	cfsec::ICFSecSecGrpMembObj* CFSecSecGrpMembTableObj::readSecGrpMembByIdIdx( const int64_t ClusterId,
			const int64_t SecGrpMembId, bool forceRead )
	{
		static const std::string S_ProcName( "readSecGrpMembByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSecGrpMembPKey pkey;
		pkey.setRequiredClusterId( ClusterId );
		pkey.setRequiredSecGrpMembId( SecGrpMembId );
		cfsec::ICFSecSecGrpMembObj* obj = readSecGrpMemb( &pkey, forceRead );
		return( obj );
	}

	std::vector<cfsec::ICFSecSecGrpMembObj*> CFSecSecGrpMembTableObj::readSecGrpMembByClusterIdx( const int64_t ClusterId,
		bool forceRead )
	{
		static const std::string S_ProcName( "readSecGrpMembByClusterIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSecGrpMembByClusterIdxKey key;
		key.setRequiredClusterId( ClusterId );
		std::map<cfsec::CFSecSecGrpMembPKey, cfsec::ICFSecSecGrpMembObj*>* dict;
		std::map<cfsec::CFSecSecGrpMembPKey, cfsec::ICFSecSecGrpMembObj*>* oldDict;
		if( indexByClusterIdx == NULL ) {
			indexByClusterIdx = new std::map< cfsec::CFSecSecGrpMembByClusterIdxKey,
				std::map< cfsec::CFSecSecGrpMembPKey, cfsec::ICFSecSecGrpMembObj*>*>();
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
			dict = new std::map<cfsec::CFSecSecGrpMembPKey, cfsec::ICFSecSecGrpMembObj*>();
			cfsec::ICFSecSecGrpMembObj* obj;
			std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecGrpMemb()->readDerivedByClusterIdx( schema->getAuthorization(),
				ClusterId );
			cfsec::CFSecSecGrpMembBuff* buff;
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = dynamic_cast<cfsec::CFSecSecGrpMembTableObj*>( schema->getSecGrpMembTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
				obj->setBuff( buff );
				cfsec::ICFSecSecGrpMembObj* realized = dynamic_cast<cfsec::ICFSecSecGrpMembObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				dict->insert( std::map< cfsec::CFSecSecGrpMembPKey, cfsec::ICFSecSecGrpMembObj* >::value_type( *(realized->getPKey()), realized ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = NULL;
			}
			if( oldDict != NULL ) {
				indexByClusterIdx->erase( searchIndexByClusterIdx );
				delete oldDict;
				oldDict = NULL;
			}
			indexByClusterIdx->insert( std::map< cfsec::CFSecSecGrpMembByClusterIdxKey,
				std::map< cfsec::CFSecSecGrpMembPKey, cfsec::ICFSecSecGrpMembObj* >* >::value_type( key, dict ) );
		}
		size_t len = dict->size();
		std::vector<cfsec::ICFSecSecGrpMembObj*> arr;
		arr.reserve( len );
		auto valIter = dict->begin();
		while( valIter != dict->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	std::vector<cfsec::ICFSecSecGrpMembObj*> CFSecSecGrpMembTableObj::readSecGrpMembByGroupIdx( const int64_t ClusterId,
			const int32_t SecGroupId,
		bool forceRead )
	{
		static const std::string S_ProcName( "readSecGrpMembByGroupIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSecGrpMembByGroupIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredSecGroupId( SecGroupId );
		std::map<cfsec::CFSecSecGrpMembPKey, cfsec::ICFSecSecGrpMembObj*>* dict;
		std::map<cfsec::CFSecSecGrpMembPKey, cfsec::ICFSecSecGrpMembObj*>* oldDict;
		if( indexByGroupIdx == NULL ) {
			indexByGroupIdx = new std::map< cfsec::CFSecSecGrpMembByGroupIdxKey,
				std::map< cfsec::CFSecSecGrpMembPKey, cfsec::ICFSecSecGrpMembObj*>*>();
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
			dict = new std::map<cfsec::CFSecSecGrpMembPKey, cfsec::ICFSecSecGrpMembObj*>();
			cfsec::ICFSecSecGrpMembObj* obj;
			std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecGrpMemb()->readDerivedByGroupIdx( schema->getAuthorization(),
				ClusterId,
				SecGroupId );
			cfsec::CFSecSecGrpMembBuff* buff;
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = dynamic_cast<cfsec::CFSecSecGrpMembTableObj*>( schema->getSecGrpMembTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
				obj->setBuff( buff );
				cfsec::ICFSecSecGrpMembObj* realized = dynamic_cast<cfsec::ICFSecSecGrpMembObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				dict->insert( std::map< cfsec::CFSecSecGrpMembPKey, cfsec::ICFSecSecGrpMembObj* >::value_type( *(realized->getPKey()), realized ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = NULL;
			}
			if( oldDict != NULL ) {
				indexByGroupIdx->erase( searchIndexByGroupIdx );
				delete oldDict;
				oldDict = NULL;
			}
			indexByGroupIdx->insert( std::map< cfsec::CFSecSecGrpMembByGroupIdxKey,
				std::map< cfsec::CFSecSecGrpMembPKey, cfsec::ICFSecSecGrpMembObj* >* >::value_type( key, dict ) );
		}
		size_t len = dict->size();
		std::vector<cfsec::ICFSecSecGrpMembObj*> arr;
		arr.reserve( len );
		auto valIter = dict->begin();
		while( valIter != dict->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	std::vector<cfsec::ICFSecSecGrpMembObj*> CFSecSecGrpMembTableObj::readSecGrpMembByUserIdx( const uuid_ptr_t SecUserId,
		bool forceRead )
	{
		static const std::string S_ProcName( "readSecGrpMembByUserIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSecGrpMembByUserIdxKey key;
		key.setRequiredSecUserId( SecUserId );
		std::map<cfsec::CFSecSecGrpMembPKey, cfsec::ICFSecSecGrpMembObj*>* dict;
		std::map<cfsec::CFSecSecGrpMembPKey, cfsec::ICFSecSecGrpMembObj*>* oldDict;
		if( indexByUserIdx == NULL ) {
			indexByUserIdx = new std::map< cfsec::CFSecSecGrpMembByUserIdxKey,
				std::map< cfsec::CFSecSecGrpMembPKey, cfsec::ICFSecSecGrpMembObj*>*>();
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
			dict = new std::map<cfsec::CFSecSecGrpMembPKey, cfsec::ICFSecSecGrpMembObj*>();
			cfsec::ICFSecSecGrpMembObj* obj;
			std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecGrpMemb()->readDerivedByUserIdx( schema->getAuthorization(),
				SecUserId );
			cfsec::CFSecSecGrpMembBuff* buff;
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = dynamic_cast<cfsec::CFSecSecGrpMembTableObj*>( schema->getSecGrpMembTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
				obj->setBuff( buff );
				cfsec::ICFSecSecGrpMembObj* realized = dynamic_cast<cfsec::ICFSecSecGrpMembObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				dict->insert( std::map< cfsec::CFSecSecGrpMembPKey, cfsec::ICFSecSecGrpMembObj* >::value_type( *(realized->getPKey()), realized ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = NULL;
			}
			if( oldDict != NULL ) {
				indexByUserIdx->erase( searchIndexByUserIdx );
				delete oldDict;
				oldDict = NULL;
			}
			indexByUserIdx->insert( std::map< cfsec::CFSecSecGrpMembByUserIdxKey,
				std::map< cfsec::CFSecSecGrpMembPKey, cfsec::ICFSecSecGrpMembObj* >* >::value_type( key, dict ) );
		}
		size_t len = dict->size();
		std::vector<cfsec::ICFSecSecGrpMembObj*> arr;
		arr.reserve( len );
		auto valIter = dict->begin();
		while( valIter != dict->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	cfsec::ICFSecSecGrpMembObj* CFSecSecGrpMembTableObj::readSecGrpMembByUUserIdx( const int64_t ClusterId,
			const int32_t SecGroupId,
			const uuid_ptr_t SecUserId, bool forceRead )
	{
		static const std::string S_ProcName( "readSecGrpMembByUUserIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByUUserIdx == NULL ) {
			indexByUUserIdx = new std::map< cfsec::CFSecSecGrpMembByUUserIdxKey,
				cfsec::ICFSecSecGrpMembObj*>();
		}
		cfsec::CFSecSecGrpMembByUUserIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredSecGroupId( SecGroupId );
		key.setRequiredSecUserId( SecUserId );
		cfsec::ICFSecSecGrpMembObj* obj = NULL;
		cfsec::ICFSecSecGrpMembObj* realized = NULL;
		if( ! forceRead ) {
			auto searchIndexByUUserIdx = indexByUUserIdx->find( key );
			if( searchIndexByUUserIdx != indexByUUserIdx->end() ) {
				// Note: obj may be null if cache misses is enabled
				obj = searchIndexByUUserIdx->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecSecGrpMembBuff* buff = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecGrpMemb()->readDerivedByUUserIdx( schema->getAuthorization(),
				ClusterId,
				SecGroupId,
				SecUserId );
			if( buff != NULL ) {
				obj = dynamic_cast<cfsec::CFSecSecGrpMembTableObj*>( schema->getSecGrpMembTableObj() )->newInstance();
				obj->setBuff( buff );
				realized = dynamic_cast<cfsec::ICFSecSecGrpMembObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				indexByUUserIdx->insert( std::map< cfsec::CFSecSecGrpMembByUUserIdxKey, cfsec::ICFSecSecGrpMembObj*>::value_type( key, dynamic_cast<cfsec::ICFSecSecGrpMembObj*>( realized ) ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = realized;
			}
		}
		return( obj );
	}

	cfsec::ICFSecSecGrpMembObj* CFSecSecGrpMembTableObj::readCachedSecGrpMemb( cfsec::CFSecSecGrpMembPKey* pkey ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readSecGrpMemb" );
		cfsec::ICFSecSecGrpMembObj* obj = NULL;
		cfsec::ICFSecSecGrpMembObj* realized = NULL;
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			// obj could be NULL if cache misses is enabled
			obj = searchMembers->second;
			realized = obj;
		}
		return( realized );
	}

	cfsec::ICFSecSecGrpMembObj* CFSecSecGrpMembTableObj::readCachedSecGrpMembByIdIdx( const int64_t ClusterId,
			const int64_t SecGrpMembId )
	{
		static const std::string S_ProcName( "readCachedSecGrpMembByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSecGrpMembPKey pkey;
		pkey.setRequiredClusterId( ClusterId );
		pkey.setRequiredSecGrpMembId( SecGrpMembId );
		cfsec::ICFSecSecGrpMembObj* obj = readCachedSecGrpMemb( &pkey );
		return( obj );
	}

	std::vector<cfsec::ICFSecSecGrpMembObj*> CFSecSecGrpMembTableObj::readCachedSecGrpMembByClusterIdx( const int64_t ClusterId )
	{
		static const std::string S_ProcName( "readCachedSecGrpMembByClusterIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		std::vector<cfsec::ICFSecSecGrpMembObj*> arr;
		cfsec::CFSecSecGrpMembByClusterIdxKey key;
		key.setRequiredClusterId( ClusterId );
		std::map<cfsec::CFSecSecGrpMembPKey, cfsec::ICFSecSecGrpMembObj*>* dict;
		if( indexByClusterIdx == NULL ) {
			return( arr );
		}
		auto searchIndexByClusterIdx = indexByClusterIdx->find( key );
		if( searchIndexByClusterIdx != indexByClusterIdx->end() ) {
			dict = searchIndexByClusterIdx->second;
			size_t len = dict->size();
			std::vector<cfsec::ICFSecSecGrpMembObj*> arr;
			arr.reserve( len );
			auto valIter = dict->begin();
			while( valIter != dict->end() ) {
				arr.push_back( valIter->second );
				valIter ++;
			}
		}
		else {
			cfsec::ICFSecSecGrpMembObj* obj;
			for( auto iterMembers = members->begin(); iterMembers != members->end(); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecSecGrpMembBuff*>( obj->getBuff() ) ) == key ) {
						arr.push_back( obj );
					}
				}
			}
		}
		return( arr );
	}

	std::vector<cfsec::ICFSecSecGrpMembObj*> CFSecSecGrpMembTableObj::readCachedSecGrpMembByGroupIdx( const int64_t ClusterId,
			const int32_t SecGroupId )
	{
		static const std::string S_ProcName( "readCachedSecGrpMembByGroupIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		std::vector<cfsec::ICFSecSecGrpMembObj*> arr;
		cfsec::CFSecSecGrpMembByGroupIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredSecGroupId( SecGroupId );
		std::map<cfsec::CFSecSecGrpMembPKey, cfsec::ICFSecSecGrpMembObj*>* dict;
		if( indexByGroupIdx == NULL ) {
			return( arr );
		}
		auto searchIndexByGroupIdx = indexByGroupIdx->find( key );
		if( searchIndexByGroupIdx != indexByGroupIdx->end() ) {
			dict = searchIndexByGroupIdx->second;
			size_t len = dict->size();
			std::vector<cfsec::ICFSecSecGrpMembObj*> arr;
			arr.reserve( len );
			auto valIter = dict->begin();
			while( valIter != dict->end() ) {
				arr.push_back( valIter->second );
				valIter ++;
			}
		}
		else {
			cfsec::ICFSecSecGrpMembObj* obj;
			for( auto iterMembers = members->begin(); iterMembers != members->end(); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecSecGrpMembBuff*>( obj->getBuff() ) ) == key ) {
						arr.push_back( obj );
					}
				}
			}
		}
		return( arr );
	}

	std::vector<cfsec::ICFSecSecGrpMembObj*> CFSecSecGrpMembTableObj::readCachedSecGrpMembByUserIdx( const uuid_ptr_t SecUserId )
	{
		static const std::string S_ProcName( "readCachedSecGrpMembByUserIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		std::vector<cfsec::ICFSecSecGrpMembObj*> arr;
		cfsec::CFSecSecGrpMembByUserIdxKey key;
		key.setRequiredSecUserId( SecUserId );
		std::map<cfsec::CFSecSecGrpMembPKey, cfsec::ICFSecSecGrpMembObj*>* dict;
		if( indexByUserIdx == NULL ) {
			return( arr );
		}
		auto searchIndexByUserIdx = indexByUserIdx->find( key );
		if( searchIndexByUserIdx != indexByUserIdx->end() ) {
			dict = searchIndexByUserIdx->second;
			size_t len = dict->size();
			std::vector<cfsec::ICFSecSecGrpMembObj*> arr;
			arr.reserve( len );
			auto valIter = dict->begin();
			while( valIter != dict->end() ) {
				arr.push_back( valIter->second );
				valIter ++;
			}
		}
		else {
			cfsec::ICFSecSecGrpMembObj* obj;
			for( auto iterMembers = members->begin(); iterMembers != members->end(); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecSecGrpMembBuff*>( obj->getBuff() ) ) == key ) {
						arr.push_back( obj );
					}
				}
			}
		}
		return( arr );
	}

	cfsec::ICFSecSecGrpMembObj* CFSecSecGrpMembTableObj::readCachedSecGrpMembByUUserIdx( const int64_t ClusterId,
			const int32_t SecGroupId,
			const uuid_ptr_t SecUserId )
	{
		static const std::string S_ProcName( "readCachedSecGrpMembByUUserIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByUUserIdx == NULL ) {
			indexByUUserIdx = new std::map< cfsec::CFSecSecGrpMembByUUserIdxKey,
				cfsec::ICFSecSecGrpMembObj*>();
		}
		cfsec::CFSecSecGrpMembByUUserIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredSecGroupId( SecGroupId );
		key.setRequiredSecUserId( SecUserId );
		cfsec::ICFSecSecGrpMembObj* obj = NULL;
		auto searchIndexByUUserIdx = indexByUUserIdx->find( key );
		if( searchIndexByUUserIdx != indexByUUserIdx->end() ) {
			// Note: obj may be null if cache misses is enabled
			obj = searchIndexByUUserIdx->second;
		}
		else {
			for( auto iterMembers = members->begin(); ( obj == NULL ) && ( iterMembers != members->end() ); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecSecGrpMembBuff*>( obj->getBuff() ) ) != key ) {
						obj = NULL;
					}
				}
			}
		}
		return( obj );
	}

	std::vector<cfsec::ICFSecSecGrpMembObj*> CFSecSecGrpMembTableObj::pageSecGrpMembByClusterIdx( const int64_t ClusterId,
			const int64_t* priorClusterId,
			const int64_t* priorSecGrpMembId )
	{
		static const std::string S_ProcName( "pageSecGrpMembByClusterIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSecGrpMembByClusterIdxKey key;
		key.setRequiredClusterId( ClusterId );
		cfsec::ICFSecSecGrpMembObj* obj;
		std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecGrpMemb()->pageBuffByClusterIdx( schema->getAuthorization(),
				ClusterId,
				priorClusterId,
				priorSecGrpMembId );
		std::vector<cfsec::ICFSecSecGrpMembObj*> retList;
		retList.reserve( buffList.size() );
		cfsec::CFSecSecGrpMembBuff* buff;
		cfsec::ICFSecSecGrpMembObj* realized;
		for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
			buff = buffList[ idx ];
			buffList[ idx ] = NULL;
				obj = dynamic_cast<cfsec::CFSecSecGrpMembTableObj*>( schema->getSecGrpMembTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
			obj->setBuff( buff );
			realized = dynamic_cast<cfsec::ICFSecSecGrpMembObj*>( obj->realize() );
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

	std::vector<cfsec::ICFSecSecGrpMembObj*> CFSecSecGrpMembTableObj::pageSecGrpMembByGroupIdx( const int64_t ClusterId,
			const int32_t SecGroupId,
			const int64_t* priorClusterId,
			const int64_t* priorSecGrpMembId )
	{
		static const std::string S_ProcName( "pageSecGrpMembByGroupIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSecGrpMembByGroupIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredSecGroupId( SecGroupId );
		cfsec::ICFSecSecGrpMembObj* obj;
		std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecGrpMemb()->pageBuffByGroupIdx( schema->getAuthorization(),
				ClusterId,
				SecGroupId,
				priorClusterId,
				priorSecGrpMembId );
		std::vector<cfsec::ICFSecSecGrpMembObj*> retList;
		retList.reserve( buffList.size() );
		cfsec::CFSecSecGrpMembBuff* buff;
		cfsec::ICFSecSecGrpMembObj* realized;
		for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
			buff = buffList[ idx ];
			buffList[ idx ] = NULL;
				obj = dynamic_cast<cfsec::CFSecSecGrpMembTableObj*>( schema->getSecGrpMembTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
			obj->setBuff( buff );
			realized = dynamic_cast<cfsec::ICFSecSecGrpMembObj*>( obj->realize() );
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

	std::vector<cfsec::ICFSecSecGrpMembObj*> CFSecSecGrpMembTableObj::pageSecGrpMembByUserIdx( const uuid_ptr_t SecUserId,
			const int64_t* priorClusterId,
			const int64_t* priorSecGrpMembId )
	{
		static const std::string S_ProcName( "pageSecGrpMembByUserIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSecGrpMembByUserIdxKey key;
		key.setRequiredSecUserId( SecUserId );
		cfsec::ICFSecSecGrpMembObj* obj;
		std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecGrpMemb()->pageBuffByUserIdx( schema->getAuthorization(),
				SecUserId,
				priorClusterId,
				priorSecGrpMembId );
		std::vector<cfsec::ICFSecSecGrpMembObj*> retList;
		retList.reserve( buffList.size() );
		cfsec::CFSecSecGrpMembBuff* buff;
		cfsec::ICFSecSecGrpMembObj* realized;
		for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
			buff = buffList[ idx ];
			buffList[ idx ] = NULL;
				obj = dynamic_cast<cfsec::CFSecSecGrpMembTableObj*>( schema->getSecGrpMembTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
			obj->setBuff( buff );
			realized = dynamic_cast<cfsec::ICFSecSecGrpMembObj*>( obj->realize() );
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

	cfsec::ICFSecSecGrpMembObj* CFSecSecGrpMembTableObj::updateSecGrpMemb( cfsec::ICFSecSecGrpMembEditObj* Obj ) {
		static const std::string S_ProcName( "updateSecGrpMemb" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Updated( "updated" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecSecGrpMembObj* obj = dynamic_cast<cfsec::ICFSecSecGrpMembObj*>( Obj->getOrig() );
		try {
			cfsec::CFSecSecGrpMembBuff* updated = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecGrpMemb()->updateSecGrpMemb( schema->getAuthorization(),
				dynamic_cast<cfsec::CFSecSecGrpMembBuff*>( Obj->getSecGrpMembBuff()->clone() ) );
			if( updated == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Updated );
			}
			obj = dynamic_cast<cfsec::ICFSecSecGrpMembObj*>( dynamic_cast<cfsec::CFSecSecGrpMembTableObj*>( schema->getSecGrpMembTableObj() )->newInstance() );
			obj->setBuff( updated );
			obj = dynamic_cast<cfsec::ICFSecSecGrpMembObj*>( obj->realize() );
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

	void CFSecSecGrpMembTableObj::deleteSecGrpMemb( cfsec::ICFSecSecGrpMembEditObj* Obj ) {
		cfsec::ICFSecSecGrpMembObj* obj = Obj;
		dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecGrpMemb()->deleteSecGrpMemb( schema->getAuthorization(),
			obj->getSecGrpMembBuff() );
		deepDisposeByIdIdx( obj->getRequiredClusterId(),
			obj->getRequiredSecGrpMembId() );
	}

	void CFSecSecGrpMembTableObj::deleteSecGrpMembByIdIdx( const int64_t ClusterId,
			const int64_t SecGrpMembId )
	{
		cfsec::CFSecSecGrpMembPKey pkey;
		pkey.setRequiredClusterId( ClusterId );
		pkey.setRequiredSecGrpMembId( SecGrpMembId );
		cfsec::ICFSecSecGrpMembObj* obj = readSecGrpMemb( &pkey, true );
		if( obj != NULL ) {
			cfsec::ICFSecSecGrpMembEditObj* editObj = dynamic_cast<cfsec::ICFSecSecGrpMembEditObj*>( obj->getEdit() );
			if( editObj == NULL ) {
				editObj = dynamic_cast<cfsec::ICFSecSecGrpMembEditObj*>( obj->beginEdit() );
			}
			if( editObj != NULL ) {
				editObj->deleteInstance();
				editObj = NULL;
			}
		}
	}

	void CFSecSecGrpMembTableObj::deleteSecGrpMembByClusterIdx( const int64_t ClusterId )
	{
		dynamic_cast<cfsec::ICFSecSchema*>( schema->getBackingStore() )->getTableSecGrpMemb()->deleteSecGrpMembByClusterIdx( schema->getAuthorization(),
				ClusterId );
		deepDisposeByClusterIdx( ClusterId );
	}

	void CFSecSecGrpMembTableObj::deleteSecGrpMembByGroupIdx( const int64_t ClusterId,
			const int32_t SecGroupId )
	{
		dynamic_cast<cfsec::ICFSecSchema*>( schema->getBackingStore() )->getTableSecGrpMemb()->deleteSecGrpMembByGroupIdx( schema->getAuthorization(),
				ClusterId,
				SecGroupId );
		deepDisposeByGroupIdx( ClusterId,
			SecGroupId );
	}

	void CFSecSecGrpMembTableObj::deleteSecGrpMembByUserIdx( const uuid_ptr_t SecUserId )
	{
		dynamic_cast<cfsec::ICFSecSchema*>( schema->getBackingStore() )->getTableSecGrpMemb()->deleteSecGrpMembByUserIdx( schema->getAuthorization(),
				SecUserId );
		deepDisposeByUserIdx( SecUserId );
	}

	void CFSecSecGrpMembTableObj::deleteSecGrpMembByUUserIdx( const int64_t ClusterId,
			const int32_t SecGroupId,
			const uuid_ptr_t SecUserId )
	{
		if( indexByUUserIdx == NULL ) {
			indexByUUserIdx = new std::map< cfsec::CFSecSecGrpMembByUUserIdxKey,
				cfsec::ICFSecSecGrpMembObj*>();
		}
		cfsec::CFSecSecGrpMembByUUserIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredSecGroupId( SecGroupId );
		key.setRequiredSecUserId( SecUserId );
		cfsec::ICFSecSecGrpMembObj* obj = NULL;
		auto searchIndexByUUserIdx = indexByUUserIdx->find( key );
		if( searchIndexByUUserIdx != indexByUUserIdx->end() ) {
			dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecGrpMemb()->deleteSecGrpMembByUUserIdx( schema->getAuthorization(),
				ClusterId,
				SecGroupId,
				SecUserId );
		}
		else {
			dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecGrpMemb()->deleteSecGrpMembByUUserIdx( schema->getAuthorization(),
				ClusterId,
				SecGroupId,
				SecUserId );
		}
		deepDisposeByUUserIdx( ClusterId,
			SecGroupId,
			SecUserId );
	}

	void CFSecSecGrpMembTableObj::reallyDetachFromIndexesSecGrpMemb( cfsec::ICFSecSecGrpMembObj* Obj ) {
		static const std::string S_ProcName( "reallyDetachFromIndexesSecGrpMemb" );
		static const std::string S_Obj( "Obj" );
		static const std::string S_ExistingObj( "ExistingObj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfsec::ICFSecSecGrpMembObj* obj = Obj;
		cfsec::CFSecSecGrpMembPKey* pkey = obj->getPKey();
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			cfsec::ICFSecSecGrpMembObj* existingObj = searchMembers->second;
			if( existingObj == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_ExistingObj );
			}
			if( indexByClusterIdx != NULL ) {
				cfsec::CFSecSecGrpMembByClusterIdxKey keyClusterIdx;
				keyClusterIdx.setRequiredClusterId( obj->getRequiredClusterId() );
				auto searchClusterIdx = indexByClusterIdx->find( keyClusterIdx );
				if( searchClusterIdx != indexByClusterIdx->end() ) {
					std::map<cfsec::CFSecSecGrpMembPKey, cfsec::ICFSecSecGrpMembObj*>* mapClusterIdx = searchClusterIdx->second;
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
				cfsec::CFSecSecGrpMembByGroupIdxKey keyGroupIdx;
				keyGroupIdx.setRequiredClusterId( obj->getRequiredClusterId() );
				keyGroupIdx.setRequiredSecGroupId( obj->getRequiredSecGroupId() );
				auto searchGroupIdx = indexByGroupIdx->find( keyGroupIdx );
				if( searchGroupIdx != indexByGroupIdx->end() ) {
					std::map<cfsec::CFSecSecGrpMembPKey, cfsec::ICFSecSecGrpMembObj*>* mapGroupIdx = searchGroupIdx->second;
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
				cfsec::CFSecSecGrpMembByUserIdxKey keyUserIdx;
				keyUserIdx.setRequiredSecUserId( obj->getRequiredSecUserId() );
				auto searchUserIdx = indexByUserIdx->find( keyUserIdx );
				if( searchUserIdx != indexByUserIdx->end() ) {
					std::map<cfsec::CFSecSecGrpMembPKey, cfsec::ICFSecSecGrpMembObj*>* mapUserIdx = searchUserIdx->second;
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
				cfsec::CFSecSecGrpMembByUUserIdxKey keyUUserIdx;
				keyUUserIdx.setRequiredClusterId( obj->getRequiredClusterId() );
				keyUUserIdx.setRequiredSecGroupId( obj->getRequiredSecGroupId() );
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
