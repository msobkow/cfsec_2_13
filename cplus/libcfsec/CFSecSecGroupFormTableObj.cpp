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

	const std::string CFSecSecGroupFormTableObj::CLASS_NAME( "CFSecSecGroupFormTableObj" );
	const std::string CFSecSecGroupFormTableObj::TABLE_NAME( "SecGroupForm" );
	const std::string CFSecSecGroupFormTableObj::TABLE_DBNAME( "SecGrpFrm" );

	CFSecSecGroupFormTableObj::CFSecSecGroupFormTableObj() {
		schema = NULL;
		members = new std::map<cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>();
		allSecGroupForm = NULL;
		indexByClusterIdx = new std::map< cfsec::CFSecSecGroupFormByClusterIdxKey,
			std::map< cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>*>();
		indexByGroupIdx = new std::map< cfsec::CFSecSecGroupFormByGroupIdxKey,
			std::map< cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>*>();
		indexByAppIdx = new std::map< cfsec::CFSecSecGroupFormByAppIdxKey,
			std::map< cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>*>();
		indexByFormIdx = new std::map< cfsec::CFSecSecGroupFormByFormIdxKey,
			std::map< cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>*>();
		indexByUFormIdx = new std::map< cfsec::CFSecSecGroupFormByUFormIdxKey,
			cfsec::ICFSecSecGroupFormObj*>();
	}

	CFSecSecGroupFormTableObj::CFSecSecGroupFormTableObj( cfsec::ICFSecSchemaObj* argSchema ) {
		schema = dynamic_cast<cfsec::ICFSecSchemaObj*>( argSchema );
		members = new std::map<cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>();
		allSecGroupForm = NULL;
		indexByClusterIdx = new std::map< cfsec::CFSecSecGroupFormByClusterIdxKey,
			std::map< cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>*>();
		indexByGroupIdx = new std::map< cfsec::CFSecSecGroupFormByGroupIdxKey,
			std::map< cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>*>();
		indexByAppIdx = new std::map< cfsec::CFSecSecGroupFormByAppIdxKey,
			std::map< cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>*>();
		indexByFormIdx = new std::map< cfsec::CFSecSecGroupFormByFormIdxKey,
			std::map< cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>*>();
		indexByUFormIdx = new std::map< cfsec::CFSecSecGroupFormByUFormIdxKey,
			cfsec::ICFSecSecGroupFormObj*>();
	}

	CFSecSecGroupFormTableObj::~CFSecSecGroupFormTableObj() {
		minimizeMemory();
		if( indexByClusterIdx != NULL ) {
			delete indexByClusterIdx;
			indexByClusterIdx = NULL;
		}
		if( indexByGroupIdx != NULL ) {
			delete indexByGroupIdx;
			indexByGroupIdx = NULL;
		}
		if( indexByAppIdx != NULL ) {
			delete indexByAppIdx;
			indexByAppIdx = NULL;
		}
		if( indexByFormIdx != NULL ) {
			delete indexByFormIdx;
			indexByFormIdx = NULL;
		}
		if( indexByUFormIdx != NULL ) {
			delete indexByUFormIdx;
			indexByUFormIdx = NULL;
		}
		if( members != NULL ) {
			cfsec::ICFSecSecGroupFormObj* curMember;
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

	cfsec::ICFSecSchemaObj* CFSecSecGroupFormTableObj::getSchema() {
		return( schema );
	}

	void CFSecSecGroupFormTableObj::setSchema( cfsec::ICFSecSchemaObj* value ) {
		schema = dynamic_cast<cfsec::ICFSecSchemaObj*>( value );
	}

	const std::string CFSecSecGroupFormTableObj::getTableName() {
		return( TABLE_NAME );
	}

	const std::string CFSecSecGroupFormTableObj::getTableDbName() {
		return( TABLE_DBNAME );
	}
	const classcode_t* CFSecSecGroupFormTableObj::getObjQualifyingClassCode() {
		return( NULL );
	}


	void CFSecSecGroupFormTableObj::minimizeMemory() {
		if( allSecGroupForm != NULL ) {
			allSecGroupForm->clear();
			delete allSecGroupForm;
			allSecGroupForm = NULL;
		}
		if( indexByClusterIdx != NULL ) {
			std::map< cfsec::CFSecSecGroupFormByClusterIdxKey,
				std::map< cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>* >::iterator iterByClusterIdx = indexByClusterIdx->begin();
			std::map< cfsec::CFSecSecGroupFormByClusterIdxKey,
				std::map< cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>* >::iterator endByClusterIdx = indexByClusterIdx->end();
			std::map< cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>* curByClusterIdx = NULL;
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
			std::map< cfsec::CFSecSecGroupFormByGroupIdxKey,
				std::map< cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>* >::iterator iterByGroupIdx = indexByGroupIdx->begin();
			std::map< cfsec::CFSecSecGroupFormByGroupIdxKey,
				std::map< cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>* >::iterator endByGroupIdx = indexByGroupIdx->end();
			std::map< cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>* curByGroupIdx = NULL;
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
		if( indexByAppIdx != NULL ) {
			std::map< cfsec::CFSecSecGroupFormByAppIdxKey,
				std::map< cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>* >::iterator iterByAppIdx = indexByAppIdx->begin();
			std::map< cfsec::CFSecSecGroupFormByAppIdxKey,
				std::map< cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>* >::iterator endByAppIdx = indexByAppIdx->end();
			std::map< cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>* curByAppIdx = NULL;
			while( iterByAppIdx != endByAppIdx ) {
				curByAppIdx = iterByAppIdx->second;
				if( curByAppIdx != NULL ) {
					curByAppIdx->clear();
					delete curByAppIdx;
					curByAppIdx = NULL;
					iterByAppIdx->second = NULL;
				}
				iterByAppIdx ++;
			}
			indexByAppIdx->clear();
		}
		if( indexByFormIdx != NULL ) {
			std::map< cfsec::CFSecSecGroupFormByFormIdxKey,
				std::map< cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>* >::iterator iterByFormIdx = indexByFormIdx->begin();
			std::map< cfsec::CFSecSecGroupFormByFormIdxKey,
				std::map< cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>* >::iterator endByFormIdx = indexByFormIdx->end();
			std::map< cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>* curByFormIdx = NULL;
			while( iterByFormIdx != endByFormIdx ) {
				curByFormIdx = iterByFormIdx->second;
				if( curByFormIdx != NULL ) {
					curByFormIdx->clear();
					delete curByFormIdx;
					curByFormIdx = NULL;
					iterByFormIdx->second = NULL;
				}
				iterByFormIdx ++;
			}
			indexByFormIdx->clear();
		}
		if( indexByUFormIdx != NULL ) {
			indexByUFormIdx->clear();
		}
		if( members != NULL ) {
			cfsec::ICFSecSecGroupFormObj* cur = NULL;
			cfsec::ICFSecSecGroupFormEditObj* edit = NULL;
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

	cfsec::ICFSecSecGroupFormObj* CFSecSecGroupFormTableObj::newInstance() {
		cfsec::ICFSecSecGroupFormObj* inst = dynamic_cast<cfsec::ICFSecSecGroupFormObj*>( new CFSecSecGroupFormObj( schema ) );
		return( inst );
	}

	cfsec::ICFSecSecGroupFormEditObj* CFSecSecGroupFormTableObj::newEditInstance( cfsec::ICFSecSecGroupFormObj* orig ) {
		cfsec::ICFSecSecGroupFormEditObj* edit = dynamic_cast<cfsec::ICFSecSecGroupFormEditObj*>( new CFSecSecGroupFormEditObj( orig ));
		return( edit );
	}

	cfsec::ICFSecSecGroupFormObj* CFSecSecGroupFormTableObj::realizeSecGroupForm( cfsec::ICFSecSecGroupFormObj* Obj ) {
		static const std::string S_ProcName( "realizeSecGroupForm" );
		static const std::string S_ExistingObj( "existingObj" );
		static const std::string S_KeepObj( "keepObj" );
		static const std::string S_Obj( "Obj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfsec::ICFSecSecGroupFormObj* obj = Obj;
		cfsec::ICFSecSecGroupFormObj* existingObj = NULL;
		cfsec::CFSecSecGroupFormPKey* pkey = obj->getPKey();
		cfsec::ICFSecSecGroupFormObj* keepObj = NULL;
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
				cfsec::CFSecSecGroupFormByClusterIdxKey keyClusterIdx;
				keyClusterIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				auto searchClusterIdx = indexByClusterIdx->find( keyClusterIdx );
				if( searchClusterIdx != indexByClusterIdx->end() ) {
					std::map<cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>* mapClusterIdx = searchClusterIdx->second;
					if( mapClusterIdx != NULL ) {
						auto removalProbe = mapClusterIdx->find( *(keepObj->getPKey()) );
						if( removalProbe != mapClusterIdx->end() ) {
							mapClusterIdx->erase( removalProbe );
						}
					}
				}
			}

			if( indexByGroupIdx != NULL ) {
				cfsec::CFSecSecGroupFormByGroupIdxKey keyGroupIdx;
				keyGroupIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				keyGroupIdx.setRequiredSecGroupId( keepObj->getRequiredSecGroupId() );
				auto searchGroupIdx = indexByGroupIdx->find( keyGroupIdx );
				if( searchGroupIdx != indexByGroupIdx->end() ) {
					std::map<cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>* mapGroupIdx = searchGroupIdx->second;
					if( mapGroupIdx != NULL ) {
						auto removalProbe = mapGroupIdx->find( *(keepObj->getPKey()) );
						if( removalProbe != mapGroupIdx->end() ) {
							mapGroupIdx->erase( removalProbe );
						}
					}
				}
			}

			if( indexByAppIdx != NULL ) {
				cfsec::CFSecSecGroupFormByAppIdxKey keyAppIdx;
				keyAppIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				keyAppIdx.setRequiredSecAppId( keepObj->getRequiredSecAppId() );
				auto searchAppIdx = indexByAppIdx->find( keyAppIdx );
				if( searchAppIdx != indexByAppIdx->end() ) {
					std::map<cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>* mapAppIdx = searchAppIdx->second;
					if( mapAppIdx != NULL ) {
						auto removalProbe = mapAppIdx->find( *(keepObj->getPKey()) );
						if( removalProbe != mapAppIdx->end() ) {
							mapAppIdx->erase( removalProbe );
						}
					}
				}
			}

			if( indexByFormIdx != NULL ) {
				cfsec::CFSecSecGroupFormByFormIdxKey keyFormIdx;
				keyFormIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				keyFormIdx.setRequiredSecFormId( keepObj->getRequiredSecFormId() );
				auto searchFormIdx = indexByFormIdx->find( keyFormIdx );
				if( searchFormIdx != indexByFormIdx->end() ) {
					std::map<cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>* mapFormIdx = searchFormIdx->second;
					if( mapFormIdx != NULL ) {
						auto removalProbe = mapFormIdx->find( *(keepObj->getPKey()) );
						if( removalProbe != mapFormIdx->end() ) {
							mapFormIdx->erase( removalProbe );
						}
					}
				}
			}

			if( indexByUFormIdx != NULL ) {
				cfsec::CFSecSecGroupFormByUFormIdxKey keyUFormIdx;
				keyUFormIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				keyUFormIdx.setRequiredSecGroupId( keepObj->getRequiredSecGroupId() );
				keyUFormIdx.setRequiredSecFormId( keepObj->getRequiredSecFormId() );
				auto removalProbe = indexByUFormIdx->find( keyUFormIdx );
				if( removalProbe != indexByUFormIdx->end() ) {
					indexByUFormIdx->erase( removalProbe );
				}
			}

			keepObj->setBuff( dynamic_cast<cfsec::CFSecSecGroupFormBuff*>( Obj->getBuff()->clone() ) );
			// Attach new object to alternate and duplicate indexes -- PKey stays stable

			if( indexByClusterIdx != NULL ) {
				static const std::string S_AClusterIdxObj( "aClusterIdxObj" );
				cfsec::ICFSecSecGroupFormObj* aClusterIdxObj =
					dynamic_cast<cfsec::ICFSecSecGroupFormObj*>( keepObj );
				if( aClusterIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AClusterIdxObj );
				}
				cfsec::CFSecSecGroupFormByClusterIdxKey keyClusterIdx;
				keyClusterIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				auto searchIndexByClusterIdx = indexByClusterIdx->find( keyClusterIdx );
				if( searchIndexByClusterIdx != indexByClusterIdx->end() ) {
					std::map<cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>* mapClusterIdx = searchIndexByClusterIdx->second;
					if( mapClusterIdx != NULL ) {
						mapClusterIdx->insert( std::map< cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj* >::value_type( *(keepObj->getPKey()), aClusterIdxObj ) );
					}
				}
			}

			if( indexByGroupIdx != NULL ) {
				static const std::string S_AGroupIdxObj( "aGroupIdxObj" );
				cfsec::ICFSecSecGroupFormObj* aGroupIdxObj =
					dynamic_cast<cfsec::ICFSecSecGroupFormObj*>( keepObj );
				if( aGroupIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AGroupIdxObj );
				}
				cfsec::CFSecSecGroupFormByGroupIdxKey keyGroupIdx;
				keyGroupIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				keyGroupIdx.setRequiredSecGroupId( keepObj->getRequiredSecGroupId() );
				auto searchIndexByGroupIdx = indexByGroupIdx->find( keyGroupIdx );
				if( searchIndexByGroupIdx != indexByGroupIdx->end() ) {
					std::map<cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>* mapGroupIdx = searchIndexByGroupIdx->second;
					if( mapGroupIdx != NULL ) {
						mapGroupIdx->insert( std::map< cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj* >::value_type( *(keepObj->getPKey()), aGroupIdxObj ) );
					}
				}
			}

			if( indexByAppIdx != NULL ) {
				static const std::string S_AAppIdxObj( "aAppIdxObj" );
				cfsec::ICFSecSecGroupFormObj* aAppIdxObj =
					dynamic_cast<cfsec::ICFSecSecGroupFormObj*>( keepObj );
				if( aAppIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AAppIdxObj );
				}
				cfsec::CFSecSecGroupFormByAppIdxKey keyAppIdx;
				keyAppIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				keyAppIdx.setRequiredSecAppId( keepObj->getRequiredSecAppId() );
				auto searchIndexByAppIdx = indexByAppIdx->find( keyAppIdx );
				if( searchIndexByAppIdx != indexByAppIdx->end() ) {
					std::map<cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>* mapAppIdx = searchIndexByAppIdx->second;
					if( mapAppIdx != NULL ) {
						mapAppIdx->insert( std::map< cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj* >::value_type( *(keepObj->getPKey()), aAppIdxObj ) );
					}
				}
			}

			if( indexByFormIdx != NULL ) {
				static const std::string S_AFormIdxObj( "aFormIdxObj" );
				cfsec::ICFSecSecGroupFormObj* aFormIdxObj =
					dynamic_cast<cfsec::ICFSecSecGroupFormObj*>( keepObj );
				if( aFormIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AFormIdxObj );
				}
				cfsec::CFSecSecGroupFormByFormIdxKey keyFormIdx;
				keyFormIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				keyFormIdx.setRequiredSecFormId( keepObj->getRequiredSecFormId() );
				auto searchIndexByFormIdx = indexByFormIdx->find( keyFormIdx );
				if( searchIndexByFormIdx != indexByFormIdx->end() ) {
					std::map<cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>* mapFormIdx = searchIndexByFormIdx->second;
					if( mapFormIdx != NULL ) {
						mapFormIdx->insert( std::map< cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj* >::value_type( *(keepObj->getPKey()), aFormIdxObj ) );
					}
				}
			}

			if( indexByUFormIdx != NULL ) {
				static const std::string S_AUFormIdxObj( "aUFormIdxObj" );
				cfsec::ICFSecSecGroupFormObj* aUFormIdxObj =
					dynamic_cast<cfsec::ICFSecSecGroupFormObj*>( keepObj );
				if( aUFormIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AUFormIdxObj );
				}
				cfsec::CFSecSecGroupFormByUFormIdxKey keyUFormIdx;
				keyUFormIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				keyUFormIdx.setRequiredSecGroupId( keepObj->getRequiredSecGroupId() );
				keyUFormIdx.setRequiredSecFormId( keepObj->getRequiredSecFormId() );
				indexByUFormIdx->insert( std::map< cfsec::CFSecSecGroupFormByUFormIdxKey, cfsec::ICFSecSecGroupFormObj* >::value_type( keyUFormIdx, aUFormIdxObj ) );
			}

			if( allSecGroupForm != NULL ) {
				allSecGroupForm->insert( std::map< cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			}
		}
		else {
			keepObj = obj;
			keepObj->setIsNew( false );
			pkey = keepObj->getPKey();
			// Attach new object to PKey, all, alternate, and duplicate indexes
			members->insert( std::map< cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			// Attach new object to alternate and duplicate indexes -- PKey stay stable

			if( indexByClusterIdx != NULL ) {
				static const std::string S_AClusterIdxObj( "aClusterIdxObj" );
				cfsec::ICFSecSecGroupFormObj* aClusterIdxObj =
					dynamic_cast<cfsec::ICFSecSecGroupFormObj*>( keepObj );
				if( aClusterIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AClusterIdxObj );
				}
				cfsec::CFSecSecGroupFormByClusterIdxKey keyClusterIdx;
				keyClusterIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				auto searchIndexByClusterIdx = indexByClusterIdx->find( keyClusterIdx );
				if( searchIndexByClusterIdx != indexByClusterIdx->end() ) {
					std::map<cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>* mapClusterIdx = searchIndexByClusterIdx->second;
					if( mapClusterIdx != NULL ) {
						mapClusterIdx->insert( std::map< cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj* >::value_type( *(keepObj->getPKey()), aClusterIdxObj ) );
					}
				}
			}

			if( indexByGroupIdx != NULL ) {
				static const std::string S_AGroupIdxObj( "aGroupIdxObj" );
				cfsec::ICFSecSecGroupFormObj* aGroupIdxObj =
					dynamic_cast<cfsec::ICFSecSecGroupFormObj*>( keepObj );
				if( aGroupIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AGroupIdxObj );
				}
				cfsec::CFSecSecGroupFormByGroupIdxKey keyGroupIdx;
				keyGroupIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				keyGroupIdx.setRequiredSecGroupId( keepObj->getRequiredSecGroupId() );
				auto searchIndexByGroupIdx = indexByGroupIdx->find( keyGroupIdx );
				if( searchIndexByGroupIdx != indexByGroupIdx->end() ) {
					std::map<cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>* mapGroupIdx = searchIndexByGroupIdx->second;
					if( mapGroupIdx != NULL ) {
						mapGroupIdx->insert( std::map< cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj* >::value_type( *(keepObj->getPKey()), aGroupIdxObj ) );
					}
				}
			}

			if( indexByAppIdx != NULL ) {
				static const std::string S_AAppIdxObj( "aAppIdxObj" );
				cfsec::ICFSecSecGroupFormObj* aAppIdxObj =
					dynamic_cast<cfsec::ICFSecSecGroupFormObj*>( keepObj );
				if( aAppIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AAppIdxObj );
				}
				cfsec::CFSecSecGroupFormByAppIdxKey keyAppIdx;
				keyAppIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				keyAppIdx.setRequiredSecAppId( keepObj->getRequiredSecAppId() );
				auto searchIndexByAppIdx = indexByAppIdx->find( keyAppIdx );
				if( searchIndexByAppIdx != indexByAppIdx->end() ) {
					std::map<cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>* mapAppIdx = searchIndexByAppIdx->second;
					if( mapAppIdx != NULL ) {
						mapAppIdx->insert( std::map< cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj* >::value_type( *(keepObj->getPKey()), aAppIdxObj ) );
					}
				}
			}

			if( indexByFormIdx != NULL ) {
				static const std::string S_AFormIdxObj( "aFormIdxObj" );
				cfsec::ICFSecSecGroupFormObj* aFormIdxObj =
					dynamic_cast<cfsec::ICFSecSecGroupFormObj*>( keepObj );
				if( aFormIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AFormIdxObj );
				}
				cfsec::CFSecSecGroupFormByFormIdxKey keyFormIdx;
				keyFormIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				keyFormIdx.setRequiredSecFormId( keepObj->getRequiredSecFormId() );
				auto searchIndexByFormIdx = indexByFormIdx->find( keyFormIdx );
				if( searchIndexByFormIdx != indexByFormIdx->end() ) {
					std::map<cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>* mapFormIdx = searchIndexByFormIdx->second;
					if( mapFormIdx != NULL ) {
						mapFormIdx->insert( std::map< cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj* >::value_type( *(keepObj->getPKey()), aFormIdxObj ) );
					}
				}
			}

			if( indexByUFormIdx != NULL ) {
				static const std::string S_AUFormIdxObj( "aUFormIdxObj" );
				cfsec::ICFSecSecGroupFormObj* aUFormIdxObj =
					dynamic_cast<cfsec::ICFSecSecGroupFormObj*>( keepObj );
				if( aUFormIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AUFormIdxObj );
				}
				cfsec::CFSecSecGroupFormByUFormIdxKey keyUFormIdx;
				keyUFormIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				keyUFormIdx.setRequiredSecGroupId( keepObj->getRequiredSecGroupId() );
				keyUFormIdx.setRequiredSecFormId( keepObj->getRequiredSecFormId() );
				indexByUFormIdx->insert( std::map< cfsec::CFSecSecGroupFormByUFormIdxKey, cfsec::ICFSecSecGroupFormObj* >::value_type( keyUFormIdx, aUFormIdxObj ) );
			}

			if( allSecGroupForm != NULL ) {
				allSecGroupForm->insert( std::map< cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
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

	void CFSecSecGroupFormTableObj::deepDisposeByIdIdx( const int64_t ClusterId,
			const int64_t SecGroupFormId ) {
		static const std::string S_ProcName( "deepDisposeByIdIdx" );
		std::vector<cfsec::ICFSecSecGroupFormObj*> list;
		cfsec::ICFSecSecGroupFormObj* existingObj = readCachedSecGroupFormByIdIdx( ClusterId,
				SecGroupFormId );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfsec::ICFSecSecGroupFormObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecSecGroupFormBuff::CLASS_CODE ) {
					dynamic_cast<cfsec::CFSecSecGroupFormTableObj*>( schema->getSecGroupFormTableObj() )->reallyDeepDisposeSecGroupForm( dynamic_cast<cfsec::ICFSecSecGroupFormObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFSecSecGroupFormTableObj::deepDisposeByClusterIdx( const int64_t ClusterId ) {
		static const std::string S_ProcName( "deepDisposeByClusterIdx" );
		std::vector<cfsec::ICFSecSecGroupFormObj*> list;
		std::vector<cfsec::ICFSecSecGroupFormObj*> matchesFound = readCachedSecGroupFormByClusterIdx( ClusterId );
		auto iterMatches = matchesFound.begin();
		auto endMatches = matchesFound.end();
		while( iterMatches != endMatches ) {
			if( *iterMatches != NULL ) {
				list.push_back( *iterMatches );
			}
			iterMatches ++;
		}
		cfsec::ICFSecSecGroupFormObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecSecGroupFormBuff::CLASS_CODE ) {
					dynamic_cast<cfsec::CFSecSecGroupFormTableObj*>( schema->getSecGroupFormTableObj() )->reallyDeepDisposeSecGroupForm( dynamic_cast<cfsec::ICFSecSecGroupFormObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFSecSecGroupFormTableObj::deepDisposeByGroupIdx( const int64_t ClusterId,
			const int32_t SecGroupId ) {
		static const std::string S_ProcName( "deepDisposeByGroupIdx" );
		std::vector<cfsec::ICFSecSecGroupFormObj*> list;
		std::vector<cfsec::ICFSecSecGroupFormObj*> matchesFound = readCachedSecGroupFormByGroupIdx( ClusterId,
				SecGroupId );
		auto iterMatches = matchesFound.begin();
		auto endMatches = matchesFound.end();
		while( iterMatches != endMatches ) {
			if( *iterMatches != NULL ) {
				list.push_back( *iterMatches );
			}
			iterMatches ++;
		}
		cfsec::ICFSecSecGroupFormObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecSecGroupFormBuff::CLASS_CODE ) {
					dynamic_cast<cfsec::CFSecSecGroupFormTableObj*>( schema->getSecGroupFormTableObj() )->reallyDeepDisposeSecGroupForm( dynamic_cast<cfsec::ICFSecSecGroupFormObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFSecSecGroupFormTableObj::deepDisposeByAppIdx( const int64_t ClusterId,
			const int32_t SecAppId ) {
		static const std::string S_ProcName( "deepDisposeByAppIdx" );
		std::vector<cfsec::ICFSecSecGroupFormObj*> list;
		std::vector<cfsec::ICFSecSecGroupFormObj*> matchesFound = readCachedSecGroupFormByAppIdx( ClusterId,
				SecAppId );
		auto iterMatches = matchesFound.begin();
		auto endMatches = matchesFound.end();
		while( iterMatches != endMatches ) {
			if( *iterMatches != NULL ) {
				list.push_back( *iterMatches );
			}
			iterMatches ++;
		}
		cfsec::ICFSecSecGroupFormObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecSecGroupFormBuff::CLASS_CODE ) {
					dynamic_cast<cfsec::CFSecSecGroupFormTableObj*>( schema->getSecGroupFormTableObj() )->reallyDeepDisposeSecGroupForm( dynamic_cast<cfsec::ICFSecSecGroupFormObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFSecSecGroupFormTableObj::deepDisposeByFormIdx( const int64_t ClusterId,
			const int32_t SecFormId ) {
		static const std::string S_ProcName( "deepDisposeByFormIdx" );
		std::vector<cfsec::ICFSecSecGroupFormObj*> list;
		std::vector<cfsec::ICFSecSecGroupFormObj*> matchesFound = readCachedSecGroupFormByFormIdx( ClusterId,
				SecFormId );
		auto iterMatches = matchesFound.begin();
		auto endMatches = matchesFound.end();
		while( iterMatches != endMatches ) {
			if( *iterMatches != NULL ) {
				list.push_back( *iterMatches );
			}
			iterMatches ++;
		}
		cfsec::ICFSecSecGroupFormObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecSecGroupFormBuff::CLASS_CODE ) {
					dynamic_cast<cfsec::CFSecSecGroupFormTableObj*>( schema->getSecGroupFormTableObj() )->reallyDeepDisposeSecGroupForm( dynamic_cast<cfsec::ICFSecSecGroupFormObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFSecSecGroupFormTableObj::deepDisposeByUFormIdx( const int64_t ClusterId,
			const int32_t SecGroupId,
			const int32_t SecFormId ) {
		static const std::string S_ProcName( "deepDisposeByUFormIdx" );
		std::vector<cfsec::ICFSecSecGroupFormObj*> list;
		cfsec::ICFSecSecGroupFormObj* existingObj = readCachedSecGroupFormByUFormIdx( ClusterId,
				SecGroupId,
				SecFormId );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfsec::ICFSecSecGroupFormObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecSecGroupFormBuff::CLASS_CODE ) {
					dynamic_cast<cfsec::CFSecSecGroupFormTableObj*>( schema->getSecGroupFormTableObj() )->reallyDeepDisposeSecGroupForm( dynamic_cast<cfsec::ICFSecSecGroupFormObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFSecSecGroupFormTableObj::reallyDeepDisposeSecGroupForm( cfsec::ICFSecSecGroupFormObj* Obj ) {
		static const std::string S_ProcName( "reallyDeepDisposeSecGroupForm" );

		if( Obj == NULL ) {
			return;
		}

		cfsec::ICFSecSecGroupFormObj* obj = Obj;
		
		classcode_t classCode = obj->getClassCode();
		if( classCode == cfsec::CFSecSecGroupFormBuff::CLASS_CODE ) {
			dynamic_cast<cfsec::CFSecSecGroupFormTableObj*>( schema->getSecGroupFormTableObj() )->reallyDetachFromIndexesSecGroupForm( dynamic_cast<cfsec::ICFSecSecGroupFormObj*>( obj ) );
		}

		if( obj->getEdit() != NULL ) {
			obj->endEdit();
		}
		delete obj;
		obj = NULL;
	}

	cfsec::ICFSecSecGroupFormObj* CFSecSecGroupFormTableObj::createSecGroupForm( cfsec::ICFSecSecGroupFormEditObj* Obj ) {
		static const std::string S_ProcName( "createSecGroupForm" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Cloneable( "cloneable" );
		static const std::string S_ClonedBuff( "clonedbuff" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecSecGroupFormObj* obj = dynamic_cast<cfsec::ICFSecSecGroupFormObj*>( Obj->getOrig() );
		try {
			cfsec::CFSecSecGroupFormBuff* buff = dynamic_cast<cfsec::CFSecSecGroupFormBuff*>( Obj->getBuff()->clone() );
			// C++18 version of create returns a new buffer instance and takes over ownership of the passed-in buffer
			// MSS TODO WORKING The xmsg client will need to return the buffer instance created by processing
			// the response message, while xmsg rqst will have to delete the backing store instance
			// it receives after preparing the reply message so that memory doesn't leak on every request.
			cflib::ICFLibCloneableObj* cloneable = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecGroupForm()->createSecGroupForm(
				schema->getAuthorization(),
				buff );
			if( cloneable == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Cloneable );
			}
			Obj->endEdit();
			obj->setBuff( dynamic_cast<cfsec::CFSecSecGroupFormBuff*>( cloneable ) );
			obj = dynamic_cast<cfsec::ICFSecSecGroupFormObj*>( obj->realize() );
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

	cfsec::ICFSecSecGroupFormObj* CFSecSecGroupFormTableObj::readSecGroupForm( cfsec::CFSecSecGroupFormPKey* pkey, bool forceRead ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readSecGroupForm" );
		cfsec::ICFSecSecGroupFormObj* obj = NULL;
		cfsec::ICFSecSecGroupFormObj* realized = NULL;
		if( ! forceRead ) {
			auto searchMembers = members->find( *pkey );
			if( searchMembers != members->end() ) {
				// obj could be NULL if cache misses is enabled
				obj = searchMembers->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecSecGroupFormBuff* readBuff = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecGroupForm()->readDerivedByIdIdx( schema->getAuthorization(),
			pkey->getRequiredClusterId(),
			pkey->getRequiredSecGroupFormId() );
			if( readBuff != NULL ) {
			obj = dynamic_cast<cfsec::CFSecSecGroupFormTableObj*>( schema->getSecGroupFormTableObj() )->newInstance();
				obj->setBuff( readBuff );
				realized = dynamic_cast<cfsec::ICFSecSecGroupFormObj*>( obj->realize() );
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

	cfsec::ICFSecSecGroupFormObj* CFSecSecGroupFormTableObj::lockSecGroupForm( cfsec::CFSecSecGroupFormPKey* pkey ) {
		static const std::string S_ProcName( "lockSecGroupForm" );
		cfsec::ICFSecSecGroupFormObj* locked = NULL;
		cfsec::CFSecSecGroupFormBuff* lockBuff = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecGroupForm()->lockDerived( schema->getAuthorization(), pkey );
		if( lockBuff != NULL ) {
			locked = dynamic_cast<cfsec::CFSecSecGroupFormTableObj*>( schema->getSecGroupFormTableObj() )->newInstance();
			locked->setBuff( lockBuff );
			locked = dynamic_cast<cfsec::ICFSecSecGroupFormObj*>( locked->realize() );
		}
		else {
			return( NULL );
		}
		return( locked );
	}

	std::vector<cfsec::ICFSecSecGroupFormObj*> CFSecSecGroupFormTableObj::readAllSecGroupForm( bool forceRead ) {
		static const std::string S_ProcName( "readAllSecGroupForm" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Realized( "realized" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecSecGroupFormObj* realized = NULL;
		if( forceRead || ( allSecGroupForm == NULL ) ) {
			std::map<cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>* map = new std::map<cfsec::CFSecSecGroupFormPKey,cfsec::ICFSecSecGroupFormObj*>();
			allSecGroupForm = map;
			std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecGroupForm()->readAllDerived( schema->getAuthorization() );
			cfsec::CFSecSecGroupFormBuff* buff = NULL;
			cfsec::ICFSecSecGroupFormObj* obj = NULL;
			try {
				for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
					buff = buffList[ idx ];
					buffList[ idx ] = NULL;
				obj = newInstance();
					obj->setBuff( buff );
					realized = dynamic_cast<cfsec::ICFSecSecGroupFormObj*>( obj->realize() );
					if( realized == NULL ) {
						throw cflib::CFLibNullArgumentException( CLASS_NAME,
							S_ProcName,
							0,
							S_Realized );
					}
					allSecGroupForm->insert( std::map< cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj* >::value_type( *(realized->getPKey()), realized ) );
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
		size_t len = allSecGroupForm->size();
		std::vector<cfsec::ICFSecSecGroupFormObj*> arr;
		auto valIter = allSecGroupForm->begin();
		size_t idx = 0;
		while( valIter != allSecGroupForm->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	std::vector<cfsec::ICFSecSecGroupFormObj*> CFSecSecGroupFormTableObj::pageAllSecGroupForm(const int64_t* priorClusterId,
			const int64_t* priorSecGroupFormId )
	{
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "pageAllSecGroupForm" );
		CFLIB_EXCEPTION_DECLINFO
		std::map<cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>* map = NULL;
		cfsec::CFSecSecGroupFormBuff* buff = NULL;
		cfsec::ICFSecSecGroupFormObj* obj = NULL;
		cfsec::ICFSecSecGroupFormObj* realized = NULL;
		std::vector<cfsec::ICFSecSecGroupFormObj*> arrayList;
		try {
			map = new std::map<cfsec::CFSecSecGroupFormPKey,cfsec::ICFSecSecGroupFormObj*>();
			std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecGroupForm()->pageAllBuff( schema->getAuthorization(),
				priorClusterId,
				priorSecGroupFormId );
			arrayList.reserve( buffList.size() );
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = newInstance();
				obj->setBuff( buff );
				realized = dynamic_cast<cfsec::ICFSecSecGroupFormObj*>( obj->realize() );
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

	cfsec::ICFSecSecGroupFormObj* CFSecSecGroupFormTableObj::readSecGroupFormByIdIdx( const int64_t ClusterId,
			const int64_t SecGroupFormId, bool forceRead )
	{
		static const std::string S_ProcName( "readSecGroupFormByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSecGroupFormPKey pkey;
		pkey.setRequiredClusterId( ClusterId );
		pkey.setRequiredSecGroupFormId( SecGroupFormId );
		cfsec::ICFSecSecGroupFormObj* obj = readSecGroupForm( &pkey, forceRead );
		return( obj );
	}

	std::vector<cfsec::ICFSecSecGroupFormObj*> CFSecSecGroupFormTableObj::readSecGroupFormByClusterIdx( const int64_t ClusterId,
		bool forceRead )
	{
		static const std::string S_ProcName( "readSecGroupFormByClusterIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSecGroupFormByClusterIdxKey key;
		key.setRequiredClusterId( ClusterId );
		std::map<cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>* dict;
		std::map<cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>* oldDict;
		if( indexByClusterIdx == NULL ) {
			indexByClusterIdx = new std::map< cfsec::CFSecSecGroupFormByClusterIdxKey,
				std::map< cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>*>();
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
			dict = new std::map<cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>();
			cfsec::ICFSecSecGroupFormObj* obj;
			std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecGroupForm()->readDerivedByClusterIdx( schema->getAuthorization(),
				ClusterId );
			cfsec::CFSecSecGroupFormBuff* buff;
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = dynamic_cast<cfsec::CFSecSecGroupFormTableObj*>( schema->getSecGroupFormTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
				obj->setBuff( buff );
				cfsec::ICFSecSecGroupFormObj* realized = dynamic_cast<cfsec::ICFSecSecGroupFormObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				dict->insert( std::map< cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj* >::value_type( *(realized->getPKey()), realized ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = NULL;
			}
			if( oldDict != NULL ) {
				indexByClusterIdx->erase( searchIndexByClusterIdx );
				delete oldDict;
				oldDict = NULL;
			}
			indexByClusterIdx->insert( std::map< cfsec::CFSecSecGroupFormByClusterIdxKey,
				std::map< cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj* >* >::value_type( key, dict ) );
		}
		size_t len = dict->size();
		std::vector<cfsec::ICFSecSecGroupFormObj*> arr;
		arr.reserve( len );
		auto valIter = dict->begin();
		while( valIter != dict->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	std::vector<cfsec::ICFSecSecGroupFormObj*> CFSecSecGroupFormTableObj::readSecGroupFormByGroupIdx( const int64_t ClusterId,
			const int32_t SecGroupId,
		bool forceRead )
	{
		static const std::string S_ProcName( "readSecGroupFormByGroupIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSecGroupFormByGroupIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredSecGroupId( SecGroupId );
		std::map<cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>* dict;
		std::map<cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>* oldDict;
		if( indexByGroupIdx == NULL ) {
			indexByGroupIdx = new std::map< cfsec::CFSecSecGroupFormByGroupIdxKey,
				std::map< cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>*>();
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
			dict = new std::map<cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>();
			cfsec::ICFSecSecGroupFormObj* obj;
			std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecGroupForm()->readDerivedByGroupIdx( schema->getAuthorization(),
				ClusterId,
				SecGroupId );
			cfsec::CFSecSecGroupFormBuff* buff;
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = dynamic_cast<cfsec::CFSecSecGroupFormTableObj*>( schema->getSecGroupFormTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
				obj->setBuff( buff );
				cfsec::ICFSecSecGroupFormObj* realized = dynamic_cast<cfsec::ICFSecSecGroupFormObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				dict->insert( std::map< cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj* >::value_type( *(realized->getPKey()), realized ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = NULL;
			}
			if( oldDict != NULL ) {
				indexByGroupIdx->erase( searchIndexByGroupIdx );
				delete oldDict;
				oldDict = NULL;
			}
			indexByGroupIdx->insert( std::map< cfsec::CFSecSecGroupFormByGroupIdxKey,
				std::map< cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj* >* >::value_type( key, dict ) );
		}
		size_t len = dict->size();
		std::vector<cfsec::ICFSecSecGroupFormObj*> arr;
		arr.reserve( len );
		auto valIter = dict->begin();
		while( valIter != dict->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	std::vector<cfsec::ICFSecSecGroupFormObj*> CFSecSecGroupFormTableObj::readSecGroupFormByAppIdx( const int64_t ClusterId,
			const int32_t SecAppId,
		bool forceRead )
	{
		static const std::string S_ProcName( "readSecGroupFormByAppIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSecGroupFormByAppIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredSecAppId( SecAppId );
		std::map<cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>* dict;
		std::map<cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>* oldDict;
		if( indexByAppIdx == NULL ) {
			indexByAppIdx = new std::map< cfsec::CFSecSecGroupFormByAppIdxKey,
				std::map< cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>*>();
		}
		auto searchIndexByAppIdx = indexByAppIdx->find( key );
		if( searchIndexByAppIdx != indexByAppIdx->end() ) {
			oldDict = searchIndexByAppIdx->second;
		}
		else {
			oldDict = NULL;
		}
		if( ( oldDict != NULL ) && ( ! forceRead ) ) {
			dict = oldDict;
		}
		else {
			dict = new std::map<cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>();
			cfsec::ICFSecSecGroupFormObj* obj;
			std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecGroupForm()->readDerivedByAppIdx( schema->getAuthorization(),
				ClusterId,
				SecAppId );
			cfsec::CFSecSecGroupFormBuff* buff;
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = dynamic_cast<cfsec::CFSecSecGroupFormTableObj*>( schema->getSecGroupFormTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
				obj->setBuff( buff );
				cfsec::ICFSecSecGroupFormObj* realized = dynamic_cast<cfsec::ICFSecSecGroupFormObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				dict->insert( std::map< cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj* >::value_type( *(realized->getPKey()), realized ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = NULL;
			}
			if( oldDict != NULL ) {
				indexByAppIdx->erase( searchIndexByAppIdx );
				delete oldDict;
				oldDict = NULL;
			}
			indexByAppIdx->insert( std::map< cfsec::CFSecSecGroupFormByAppIdxKey,
				std::map< cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj* >* >::value_type( key, dict ) );
		}
		size_t len = dict->size();
		std::vector<cfsec::ICFSecSecGroupFormObj*> arr;
		arr.reserve( len );
		auto valIter = dict->begin();
		while( valIter != dict->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	std::vector<cfsec::ICFSecSecGroupFormObj*> CFSecSecGroupFormTableObj::readSecGroupFormByFormIdx( const int64_t ClusterId,
			const int32_t SecFormId,
		bool forceRead )
	{
		static const std::string S_ProcName( "readSecGroupFormByFormIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSecGroupFormByFormIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredSecFormId( SecFormId );
		std::map<cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>* dict;
		std::map<cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>* oldDict;
		if( indexByFormIdx == NULL ) {
			indexByFormIdx = new std::map< cfsec::CFSecSecGroupFormByFormIdxKey,
				std::map< cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>*>();
		}
		auto searchIndexByFormIdx = indexByFormIdx->find( key );
		if( searchIndexByFormIdx != indexByFormIdx->end() ) {
			oldDict = searchIndexByFormIdx->second;
		}
		else {
			oldDict = NULL;
		}
		if( ( oldDict != NULL ) && ( ! forceRead ) ) {
			dict = oldDict;
		}
		else {
			dict = new std::map<cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>();
			cfsec::ICFSecSecGroupFormObj* obj;
			std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecGroupForm()->readDerivedByFormIdx( schema->getAuthorization(),
				ClusterId,
				SecFormId );
			cfsec::CFSecSecGroupFormBuff* buff;
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = dynamic_cast<cfsec::CFSecSecGroupFormTableObj*>( schema->getSecGroupFormTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
				obj->setBuff( buff );
				cfsec::ICFSecSecGroupFormObj* realized = dynamic_cast<cfsec::ICFSecSecGroupFormObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				dict->insert( std::map< cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj* >::value_type( *(realized->getPKey()), realized ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = NULL;
			}
			if( oldDict != NULL ) {
				indexByFormIdx->erase( searchIndexByFormIdx );
				delete oldDict;
				oldDict = NULL;
			}
			indexByFormIdx->insert( std::map< cfsec::CFSecSecGroupFormByFormIdxKey,
				std::map< cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj* >* >::value_type( key, dict ) );
		}
		size_t len = dict->size();
		std::vector<cfsec::ICFSecSecGroupFormObj*> arr;
		arr.reserve( len );
		auto valIter = dict->begin();
		while( valIter != dict->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	cfsec::ICFSecSecGroupFormObj* CFSecSecGroupFormTableObj::readSecGroupFormByUFormIdx( const int64_t ClusterId,
			const int32_t SecGroupId,
			const int32_t SecFormId, bool forceRead )
	{
		static const std::string S_ProcName( "readSecGroupFormByUFormIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByUFormIdx == NULL ) {
			indexByUFormIdx = new std::map< cfsec::CFSecSecGroupFormByUFormIdxKey,
				cfsec::ICFSecSecGroupFormObj*>();
		}
		cfsec::CFSecSecGroupFormByUFormIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredSecGroupId( SecGroupId );
		key.setRequiredSecFormId( SecFormId );
		cfsec::ICFSecSecGroupFormObj* obj = NULL;
		cfsec::ICFSecSecGroupFormObj* realized = NULL;
		if( ! forceRead ) {
			auto searchIndexByUFormIdx = indexByUFormIdx->find( key );
			if( searchIndexByUFormIdx != indexByUFormIdx->end() ) {
				// Note: obj may be null if cache misses is enabled
				obj = searchIndexByUFormIdx->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecSecGroupFormBuff* buff = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecGroupForm()->readDerivedByUFormIdx( schema->getAuthorization(),
				ClusterId,
				SecGroupId,
				SecFormId );
			if( buff != NULL ) {
				obj = dynamic_cast<cfsec::CFSecSecGroupFormTableObj*>( schema->getSecGroupFormTableObj() )->newInstance();
				obj->setBuff( buff );
				realized = dynamic_cast<cfsec::ICFSecSecGroupFormObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				indexByUFormIdx->insert( std::map< cfsec::CFSecSecGroupFormByUFormIdxKey, cfsec::ICFSecSecGroupFormObj*>::value_type( key, dynamic_cast<cfsec::ICFSecSecGroupFormObj*>( realized ) ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = realized;
			}
		}
		return( obj );
	}

	cfsec::ICFSecSecGroupFormObj* CFSecSecGroupFormTableObj::readCachedSecGroupForm( cfsec::CFSecSecGroupFormPKey* pkey ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readSecGroupForm" );
		cfsec::ICFSecSecGroupFormObj* obj = NULL;
		cfsec::ICFSecSecGroupFormObj* realized = NULL;
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			// obj could be NULL if cache misses is enabled
			obj = searchMembers->second;
			realized = obj;
		}
		return( realized );
	}

	cfsec::ICFSecSecGroupFormObj* CFSecSecGroupFormTableObj::readCachedSecGroupFormByIdIdx( const int64_t ClusterId,
			const int64_t SecGroupFormId )
	{
		static const std::string S_ProcName( "readCachedSecGroupFormByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSecGroupFormPKey pkey;
		pkey.setRequiredClusterId( ClusterId );
		pkey.setRequiredSecGroupFormId( SecGroupFormId );
		cfsec::ICFSecSecGroupFormObj* obj = readCachedSecGroupForm( &pkey );
		return( obj );
	}

	std::vector<cfsec::ICFSecSecGroupFormObj*> CFSecSecGroupFormTableObj::readCachedSecGroupFormByClusterIdx( const int64_t ClusterId )
	{
		static const std::string S_ProcName( "readCachedSecGroupFormByClusterIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		std::vector<cfsec::ICFSecSecGroupFormObj*> arr;
		cfsec::CFSecSecGroupFormByClusterIdxKey key;
		key.setRequiredClusterId( ClusterId );
		std::map<cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>* dict;
		if( indexByClusterIdx == NULL ) {
			return( arr );
		}
		auto searchIndexByClusterIdx = indexByClusterIdx->find( key );
		if( searchIndexByClusterIdx != indexByClusterIdx->end() ) {
			dict = searchIndexByClusterIdx->second;
			size_t len = dict->size();
			std::vector<cfsec::ICFSecSecGroupFormObj*> arr;
			arr.reserve( len );
			auto valIter = dict->begin();
			while( valIter != dict->end() ) {
				arr.push_back( valIter->second );
				valIter ++;
			}
		}
		else {
			cfsec::ICFSecSecGroupFormObj* obj;
			for( auto iterMembers = members->begin(); iterMembers != members->end(); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecSecGroupFormBuff*>( obj->getBuff() ) ) == key ) {
						arr.push_back( obj );
					}
				}
			}
		}
		return( arr );
	}

	std::vector<cfsec::ICFSecSecGroupFormObj*> CFSecSecGroupFormTableObj::readCachedSecGroupFormByGroupIdx( const int64_t ClusterId,
			const int32_t SecGroupId )
	{
		static const std::string S_ProcName( "readCachedSecGroupFormByGroupIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		std::vector<cfsec::ICFSecSecGroupFormObj*> arr;
		cfsec::CFSecSecGroupFormByGroupIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredSecGroupId( SecGroupId );
		std::map<cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>* dict;
		if( indexByGroupIdx == NULL ) {
			return( arr );
		}
		auto searchIndexByGroupIdx = indexByGroupIdx->find( key );
		if( searchIndexByGroupIdx != indexByGroupIdx->end() ) {
			dict = searchIndexByGroupIdx->second;
			size_t len = dict->size();
			std::vector<cfsec::ICFSecSecGroupFormObj*> arr;
			arr.reserve( len );
			auto valIter = dict->begin();
			while( valIter != dict->end() ) {
				arr.push_back( valIter->second );
				valIter ++;
			}
		}
		else {
			cfsec::ICFSecSecGroupFormObj* obj;
			for( auto iterMembers = members->begin(); iterMembers != members->end(); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecSecGroupFormBuff*>( obj->getBuff() ) ) == key ) {
						arr.push_back( obj );
					}
				}
			}
		}
		return( arr );
	}

	std::vector<cfsec::ICFSecSecGroupFormObj*> CFSecSecGroupFormTableObj::readCachedSecGroupFormByAppIdx( const int64_t ClusterId,
			const int32_t SecAppId )
	{
		static const std::string S_ProcName( "readCachedSecGroupFormByAppIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		std::vector<cfsec::ICFSecSecGroupFormObj*> arr;
		cfsec::CFSecSecGroupFormByAppIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredSecAppId( SecAppId );
		std::map<cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>* dict;
		if( indexByAppIdx == NULL ) {
			return( arr );
		}
		auto searchIndexByAppIdx = indexByAppIdx->find( key );
		if( searchIndexByAppIdx != indexByAppIdx->end() ) {
			dict = searchIndexByAppIdx->second;
			size_t len = dict->size();
			std::vector<cfsec::ICFSecSecGroupFormObj*> arr;
			arr.reserve( len );
			auto valIter = dict->begin();
			while( valIter != dict->end() ) {
				arr.push_back( valIter->second );
				valIter ++;
			}
		}
		else {
			cfsec::ICFSecSecGroupFormObj* obj;
			for( auto iterMembers = members->begin(); iterMembers != members->end(); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecSecGroupFormBuff*>( obj->getBuff() ) ) == key ) {
						arr.push_back( obj );
					}
				}
			}
		}
		return( arr );
	}

	std::vector<cfsec::ICFSecSecGroupFormObj*> CFSecSecGroupFormTableObj::readCachedSecGroupFormByFormIdx( const int64_t ClusterId,
			const int32_t SecFormId )
	{
		static const std::string S_ProcName( "readCachedSecGroupFormByFormIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		std::vector<cfsec::ICFSecSecGroupFormObj*> arr;
		cfsec::CFSecSecGroupFormByFormIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredSecFormId( SecFormId );
		std::map<cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>* dict;
		if( indexByFormIdx == NULL ) {
			return( arr );
		}
		auto searchIndexByFormIdx = indexByFormIdx->find( key );
		if( searchIndexByFormIdx != indexByFormIdx->end() ) {
			dict = searchIndexByFormIdx->second;
			size_t len = dict->size();
			std::vector<cfsec::ICFSecSecGroupFormObj*> arr;
			arr.reserve( len );
			auto valIter = dict->begin();
			while( valIter != dict->end() ) {
				arr.push_back( valIter->second );
				valIter ++;
			}
		}
		else {
			cfsec::ICFSecSecGroupFormObj* obj;
			for( auto iterMembers = members->begin(); iterMembers != members->end(); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecSecGroupFormBuff*>( obj->getBuff() ) ) == key ) {
						arr.push_back( obj );
					}
				}
			}
		}
		return( arr );
	}

	cfsec::ICFSecSecGroupFormObj* CFSecSecGroupFormTableObj::readCachedSecGroupFormByUFormIdx( const int64_t ClusterId,
			const int32_t SecGroupId,
			const int32_t SecFormId )
	{
		static const std::string S_ProcName( "readCachedSecGroupFormByUFormIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByUFormIdx == NULL ) {
			indexByUFormIdx = new std::map< cfsec::CFSecSecGroupFormByUFormIdxKey,
				cfsec::ICFSecSecGroupFormObj*>();
		}
		cfsec::CFSecSecGroupFormByUFormIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredSecGroupId( SecGroupId );
		key.setRequiredSecFormId( SecFormId );
		cfsec::ICFSecSecGroupFormObj* obj = NULL;
		auto searchIndexByUFormIdx = indexByUFormIdx->find( key );
		if( searchIndexByUFormIdx != indexByUFormIdx->end() ) {
			// Note: obj may be null if cache misses is enabled
			obj = searchIndexByUFormIdx->second;
		}
		else {
			for( auto iterMembers = members->begin(); ( obj == NULL ) && ( iterMembers != members->end() ); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecSecGroupFormBuff*>( obj->getBuff() ) ) != key ) {
						obj = NULL;
					}
				}
			}
		}
		return( obj );
	}

	std::vector<cfsec::ICFSecSecGroupFormObj*> CFSecSecGroupFormTableObj::pageSecGroupFormByClusterIdx( const int64_t ClusterId,
			const int64_t* priorClusterId,
			const int64_t* priorSecGroupFormId )
	{
		static const std::string S_ProcName( "pageSecGroupFormByClusterIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSecGroupFormByClusterIdxKey key;
		key.setRequiredClusterId( ClusterId );
		cfsec::ICFSecSecGroupFormObj* obj;
		std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecGroupForm()->pageBuffByClusterIdx( schema->getAuthorization(),
				ClusterId,
				priorClusterId,
				priorSecGroupFormId );
		std::vector<cfsec::ICFSecSecGroupFormObj*> retList;
		retList.reserve( buffList.size() );
		cfsec::CFSecSecGroupFormBuff* buff;
		cfsec::ICFSecSecGroupFormObj* realized;
		for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
			buff = buffList[ idx ];
			buffList[ idx ] = NULL;
				obj = dynamic_cast<cfsec::CFSecSecGroupFormTableObj*>( schema->getSecGroupFormTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
			obj->setBuff( buff );
			realized = dynamic_cast<cfsec::ICFSecSecGroupFormObj*>( obj->realize() );
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

	std::vector<cfsec::ICFSecSecGroupFormObj*> CFSecSecGroupFormTableObj::pageSecGroupFormByGroupIdx( const int64_t ClusterId,
			const int32_t SecGroupId,
			const int64_t* priorClusterId,
			const int64_t* priorSecGroupFormId )
	{
		static const std::string S_ProcName( "pageSecGroupFormByGroupIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSecGroupFormByGroupIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredSecGroupId( SecGroupId );
		cfsec::ICFSecSecGroupFormObj* obj;
		std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecGroupForm()->pageBuffByGroupIdx( schema->getAuthorization(),
				ClusterId,
				SecGroupId,
				priorClusterId,
				priorSecGroupFormId );
		std::vector<cfsec::ICFSecSecGroupFormObj*> retList;
		retList.reserve( buffList.size() );
		cfsec::CFSecSecGroupFormBuff* buff;
		cfsec::ICFSecSecGroupFormObj* realized;
		for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
			buff = buffList[ idx ];
			buffList[ idx ] = NULL;
				obj = dynamic_cast<cfsec::CFSecSecGroupFormTableObj*>( schema->getSecGroupFormTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
			obj->setBuff( buff );
			realized = dynamic_cast<cfsec::ICFSecSecGroupFormObj*>( obj->realize() );
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

	std::vector<cfsec::ICFSecSecGroupFormObj*> CFSecSecGroupFormTableObj::pageSecGroupFormByAppIdx( const int64_t ClusterId,
			const int32_t SecAppId,
			const int64_t* priorClusterId,
			const int64_t* priorSecGroupFormId )
	{
		static const std::string S_ProcName( "pageSecGroupFormByAppIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSecGroupFormByAppIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredSecAppId( SecAppId );
		cfsec::ICFSecSecGroupFormObj* obj;
		std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecGroupForm()->pageBuffByAppIdx( schema->getAuthorization(),
				ClusterId,
				SecAppId,
				priorClusterId,
				priorSecGroupFormId );
		std::vector<cfsec::ICFSecSecGroupFormObj*> retList;
		retList.reserve( buffList.size() );
		cfsec::CFSecSecGroupFormBuff* buff;
		cfsec::ICFSecSecGroupFormObj* realized;
		for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
			buff = buffList[ idx ];
			buffList[ idx ] = NULL;
				obj = dynamic_cast<cfsec::CFSecSecGroupFormTableObj*>( schema->getSecGroupFormTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
			obj->setBuff( buff );
			realized = dynamic_cast<cfsec::ICFSecSecGroupFormObj*>( obj->realize() );
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

	std::vector<cfsec::ICFSecSecGroupFormObj*> CFSecSecGroupFormTableObj::pageSecGroupFormByFormIdx( const int64_t ClusterId,
			const int32_t SecFormId,
			const int64_t* priorClusterId,
			const int64_t* priorSecGroupFormId )
	{
		static const std::string S_ProcName( "pageSecGroupFormByFormIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSecGroupFormByFormIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredSecFormId( SecFormId );
		cfsec::ICFSecSecGroupFormObj* obj;
		std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecGroupForm()->pageBuffByFormIdx( schema->getAuthorization(),
				ClusterId,
				SecFormId,
				priorClusterId,
				priorSecGroupFormId );
		std::vector<cfsec::ICFSecSecGroupFormObj*> retList;
		retList.reserve( buffList.size() );
		cfsec::CFSecSecGroupFormBuff* buff;
		cfsec::ICFSecSecGroupFormObj* realized;
		for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
			buff = buffList[ idx ];
			buffList[ idx ] = NULL;
				obj = dynamic_cast<cfsec::CFSecSecGroupFormTableObj*>( schema->getSecGroupFormTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
			obj->setBuff( buff );
			realized = dynamic_cast<cfsec::ICFSecSecGroupFormObj*>( obj->realize() );
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

	cfsec::ICFSecSecGroupFormObj* CFSecSecGroupFormTableObj::updateSecGroupForm( cfsec::ICFSecSecGroupFormEditObj* Obj ) {
		static const std::string S_ProcName( "updateSecGroupForm" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Updated( "updated" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecSecGroupFormObj* obj = dynamic_cast<cfsec::ICFSecSecGroupFormObj*>( Obj->getOrig() );
		try {
			cfsec::CFSecSecGroupFormBuff* updated = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecGroupForm()->updateSecGroupForm( schema->getAuthorization(),
				dynamic_cast<cfsec::CFSecSecGroupFormBuff*>( Obj->getSecGroupFormBuff()->clone() ) );
			if( updated == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Updated );
			}
			obj = dynamic_cast<cfsec::ICFSecSecGroupFormObj*>( dynamic_cast<cfsec::CFSecSecGroupFormTableObj*>( schema->getSecGroupFormTableObj() )->newInstance() );
			obj->setBuff( updated );
			obj = dynamic_cast<cfsec::ICFSecSecGroupFormObj*>( obj->realize() );
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

	void CFSecSecGroupFormTableObj::deleteSecGroupForm( cfsec::ICFSecSecGroupFormEditObj* Obj ) {
		cfsec::ICFSecSecGroupFormObj* obj = Obj;
		dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecGroupForm()->deleteSecGroupForm( schema->getAuthorization(),
			obj->getSecGroupFormBuff() );
		deepDisposeByIdIdx( obj->getRequiredClusterId(),
			obj->getRequiredSecGroupFormId() );
	}

	void CFSecSecGroupFormTableObj::deleteSecGroupFormByIdIdx( const int64_t ClusterId,
			const int64_t SecGroupFormId )
	{
		cfsec::CFSecSecGroupFormPKey pkey;
		pkey.setRequiredClusterId( ClusterId );
		pkey.setRequiredSecGroupFormId( SecGroupFormId );
		cfsec::ICFSecSecGroupFormObj* obj = readSecGroupForm( &pkey, true );
		if( obj != NULL ) {
			cfsec::ICFSecSecGroupFormEditObj* editObj = dynamic_cast<cfsec::ICFSecSecGroupFormEditObj*>( obj->getEdit() );
			if( editObj == NULL ) {
				editObj = dynamic_cast<cfsec::ICFSecSecGroupFormEditObj*>( obj->beginEdit() );
			}
			if( editObj != NULL ) {
				editObj->deleteInstance();
				editObj = NULL;
			}
		}
	}

	void CFSecSecGroupFormTableObj::deleteSecGroupFormByClusterIdx( const int64_t ClusterId )
	{
		dynamic_cast<cfsec::ICFSecSchema*>( schema->getBackingStore() )->getTableSecGroupForm()->deleteSecGroupFormByClusterIdx( schema->getAuthorization(),
				ClusterId );
		deepDisposeByClusterIdx( ClusterId );
	}

	void CFSecSecGroupFormTableObj::deleteSecGroupFormByGroupIdx( const int64_t ClusterId,
			const int32_t SecGroupId )
	{
		dynamic_cast<cfsec::ICFSecSchema*>( schema->getBackingStore() )->getTableSecGroupForm()->deleteSecGroupFormByGroupIdx( schema->getAuthorization(),
				ClusterId,
				SecGroupId );
		deepDisposeByGroupIdx( ClusterId,
			SecGroupId );
	}

	void CFSecSecGroupFormTableObj::deleteSecGroupFormByAppIdx( const int64_t ClusterId,
			const int32_t SecAppId )
	{
		dynamic_cast<cfsec::ICFSecSchema*>( schema->getBackingStore() )->getTableSecGroupForm()->deleteSecGroupFormByAppIdx( schema->getAuthorization(),
				ClusterId,
				SecAppId );
		deepDisposeByAppIdx( ClusterId,
			SecAppId );
	}

	void CFSecSecGroupFormTableObj::deleteSecGroupFormByFormIdx( const int64_t ClusterId,
			const int32_t SecFormId )
	{
		dynamic_cast<cfsec::ICFSecSchema*>( schema->getBackingStore() )->getTableSecGroupForm()->deleteSecGroupFormByFormIdx( schema->getAuthorization(),
				ClusterId,
				SecFormId );
		deepDisposeByFormIdx( ClusterId,
			SecFormId );
	}

	void CFSecSecGroupFormTableObj::deleteSecGroupFormByUFormIdx( const int64_t ClusterId,
			const int32_t SecGroupId,
			const int32_t SecFormId )
	{
		if( indexByUFormIdx == NULL ) {
			indexByUFormIdx = new std::map< cfsec::CFSecSecGroupFormByUFormIdxKey,
				cfsec::ICFSecSecGroupFormObj*>();
		}
		cfsec::CFSecSecGroupFormByUFormIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredSecGroupId( SecGroupId );
		key.setRequiredSecFormId( SecFormId );
		cfsec::ICFSecSecGroupFormObj* obj = NULL;
		auto searchIndexByUFormIdx = indexByUFormIdx->find( key );
		if( searchIndexByUFormIdx != indexByUFormIdx->end() ) {
			dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecGroupForm()->deleteSecGroupFormByUFormIdx( schema->getAuthorization(),
				ClusterId,
				SecGroupId,
				SecFormId );
		}
		else {
			dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecGroupForm()->deleteSecGroupFormByUFormIdx( schema->getAuthorization(),
				ClusterId,
				SecGroupId,
				SecFormId );
		}
		deepDisposeByUFormIdx( ClusterId,
			SecGroupId,
			SecFormId );
	}

	void CFSecSecGroupFormTableObj::reallyDetachFromIndexesSecGroupForm( cfsec::ICFSecSecGroupFormObj* Obj ) {
		static const std::string S_ProcName( "reallyDetachFromIndexesSecGroupForm" );
		static const std::string S_Obj( "Obj" );
		static const std::string S_ExistingObj( "ExistingObj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfsec::ICFSecSecGroupFormObj* obj = Obj;
		cfsec::CFSecSecGroupFormPKey* pkey = obj->getPKey();
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			cfsec::ICFSecSecGroupFormObj* existingObj = searchMembers->second;
			if( existingObj == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_ExistingObj );
			}
			if( indexByClusterIdx != NULL ) {
				cfsec::CFSecSecGroupFormByClusterIdxKey keyClusterIdx;
				keyClusterIdx.setRequiredClusterId( obj->getRequiredClusterId() );
				auto searchClusterIdx = indexByClusterIdx->find( keyClusterIdx );
				if( searchClusterIdx != indexByClusterIdx->end() ) {
					std::map<cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>* mapClusterIdx = searchClusterIdx->second;
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
				cfsec::CFSecSecGroupFormByGroupIdxKey keyGroupIdx;
				keyGroupIdx.setRequiredClusterId( obj->getRequiredClusterId() );
				keyGroupIdx.setRequiredSecGroupId( obj->getRequiredSecGroupId() );
				auto searchGroupIdx = indexByGroupIdx->find( keyGroupIdx );
				if( searchGroupIdx != indexByGroupIdx->end() ) {
					std::map<cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>* mapGroupIdx = searchGroupIdx->second;
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

			if( indexByAppIdx != NULL ) {
				cfsec::CFSecSecGroupFormByAppIdxKey keyAppIdx;
				keyAppIdx.setRequiredClusterId( obj->getRequiredClusterId() );
				keyAppIdx.setRequiredSecAppId( obj->getRequiredSecAppId() );
				auto searchAppIdx = indexByAppIdx->find( keyAppIdx );
				if( searchAppIdx != indexByAppIdx->end() ) {
					std::map<cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>* mapAppIdx = searchAppIdx->second;
					if( mapAppIdx != NULL ) {
						auto removalProbe = mapAppIdx->find( *(obj->getPKey()) );
						if( removalProbe != mapAppIdx->end() ) {
							mapAppIdx->erase( removalProbe );
							if( mapAppIdx->empty() ) {
								delete mapAppIdx;
								mapAppIdx = NULL;
								indexByAppIdx->erase( searchAppIdx );
							}
						}
					}
				}
			}

			if( indexByFormIdx != NULL ) {
				cfsec::CFSecSecGroupFormByFormIdxKey keyFormIdx;
				keyFormIdx.setRequiredClusterId( obj->getRequiredClusterId() );
				keyFormIdx.setRequiredSecFormId( obj->getRequiredSecFormId() );
				auto searchFormIdx = indexByFormIdx->find( keyFormIdx );
				if( searchFormIdx != indexByFormIdx->end() ) {
					std::map<cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>* mapFormIdx = searchFormIdx->second;
					if( mapFormIdx != NULL ) {
						auto removalProbe = mapFormIdx->find( *(obj->getPKey()) );
						if( removalProbe != mapFormIdx->end() ) {
							mapFormIdx->erase( removalProbe );
							if( mapFormIdx->empty() ) {
								delete mapFormIdx;
								mapFormIdx = NULL;
								indexByFormIdx->erase( searchFormIdx );
							}
						}
					}
				}
			}

			if( indexByUFormIdx != NULL ) {
				cfsec::CFSecSecGroupFormByUFormIdxKey keyUFormIdx;
				keyUFormIdx.setRequiredClusterId( obj->getRequiredClusterId() );
				keyUFormIdx.setRequiredSecGroupId( obj->getRequiredSecGroupId() );
				keyUFormIdx.setRequiredSecFormId( obj->getRequiredSecFormId() );
				auto removalProbe = indexByUFormIdx->find( keyUFormIdx );
				if( removalProbe != indexByUFormIdx->end() ) {
					indexByUFormIdx->erase( removalProbe );
				}
			}

			members->erase( searchMembers );
		}
	}


}
