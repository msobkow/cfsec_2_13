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

	const std::string CFSecClusterTableObj::CLASS_NAME( "CFSecClusterTableObj" );
	const std::string CFSecClusterTableObj::TABLE_NAME( "Cluster" );
	const std::string CFSecClusterTableObj::TABLE_DBNAME( "clus" );

	CFSecClusterTableObj::CFSecClusterTableObj() {
		schema = NULL;
		members = new std::map<cfsec::CFSecClusterPKey, cfsec::ICFSecClusterObj*>();
		allCluster = NULL;
		indexByUDomNameIdx = new std::map< cfsec::CFSecClusterByUDomNameIdxKey,
			cfsec::ICFSecClusterObj*>();
		indexByUDescrIdx = new std::map< cfsec::CFSecClusterByUDescrIdxKey,
			cfsec::ICFSecClusterObj*>();
	}

	CFSecClusterTableObj::CFSecClusterTableObj( cfsec::ICFSecSchemaObj* argSchema ) {
		schema = dynamic_cast<cfsec::ICFSecSchemaObj*>( argSchema );
		members = new std::map<cfsec::CFSecClusterPKey, cfsec::ICFSecClusterObj*>();
		allCluster = NULL;
		indexByUDomNameIdx = new std::map< cfsec::CFSecClusterByUDomNameIdxKey,
			cfsec::ICFSecClusterObj*>();
		indexByUDescrIdx = new std::map< cfsec::CFSecClusterByUDescrIdxKey,
			cfsec::ICFSecClusterObj*>();
	}

	CFSecClusterTableObj::~CFSecClusterTableObj() {
		minimizeMemory();
		if( indexByUDomNameIdx != NULL ) {
			delete indexByUDomNameIdx;
			indexByUDomNameIdx = NULL;
		}
		if( indexByUDescrIdx != NULL ) {
			delete indexByUDescrIdx;
			indexByUDescrIdx = NULL;
		}
		if( members != NULL ) {
			cfsec::ICFSecClusterObj* curMember;
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

	cfsec::ICFSecSchemaObj* CFSecClusterTableObj::getSchema() {
		return( schema );
	}

	void CFSecClusterTableObj::setSchema( cfsec::ICFSecSchemaObj* value ) {
		schema = dynamic_cast<cfsec::ICFSecSchemaObj*>( value );
	}

	const std::string CFSecClusterTableObj::getTableName() {
		return( TABLE_NAME );
	}

	const std::string CFSecClusterTableObj::getTableDbName() {
		return( TABLE_DBNAME );
	}
	const classcode_t* CFSecClusterTableObj::getObjQualifyingClassCode() {
		return( NULL );
	}


	void CFSecClusterTableObj::minimizeMemory() {
		if( allCluster != NULL ) {
			allCluster->clear();
			delete allCluster;
			allCluster = NULL;
		}
		if( indexByUDomNameIdx != NULL ) {
			indexByUDomNameIdx->clear();
		}
		if( indexByUDescrIdx != NULL ) {
			indexByUDescrIdx->clear();
		}
		if( members != NULL ) {
			cfsec::ICFSecClusterObj* cur = NULL;
			cfsec::ICFSecClusterEditObj* edit = NULL;
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

	cfsec::ICFSecClusterObj* CFSecClusterTableObj::newInstance() {
		cfsec::ICFSecClusterObj* inst = dynamic_cast<cfsec::ICFSecClusterObj*>( new CFSecClusterObj( schema ) );
		return( inst );
	}

	cfsec::ICFSecClusterEditObj* CFSecClusterTableObj::newEditInstance( cfsec::ICFSecClusterObj* orig ) {
		cfsec::ICFSecClusterEditObj* edit = dynamic_cast<cfsec::ICFSecClusterEditObj*>( new CFSecClusterEditObj( orig ));
		return( edit );
	}

	cfsec::ICFSecClusterObj* CFSecClusterTableObj::realizeCluster( cfsec::ICFSecClusterObj* Obj ) {
		static const std::string S_ProcName( "realizeCluster" );
		static const std::string S_ExistingObj( "existingObj" );
		static const std::string S_KeepObj( "keepObj" );
		static const std::string S_Obj( "Obj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfsec::ICFSecClusterObj* obj = Obj;
		cfsec::ICFSecClusterObj* existingObj = NULL;
		cfsec::CFSecClusterPKey* pkey = obj->getPKey();
		cfsec::ICFSecClusterObj* keepObj = NULL;
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
			if( indexByUDomNameIdx != NULL ) {
				cfsec::CFSecClusterByUDomNameIdxKey keyUDomNameIdx;
				keyUDomNameIdx.setRequiredFullDomName( keepObj->getRequiredFullDomName() );
				auto removalProbe = indexByUDomNameIdx->find( keyUDomNameIdx );
				if( removalProbe != indexByUDomNameIdx->end() ) {
					indexByUDomNameIdx->erase( removalProbe );
				}
			}

			if( indexByUDescrIdx != NULL ) {
				cfsec::CFSecClusterByUDescrIdxKey keyUDescrIdx;
				keyUDescrIdx.setRequiredDescription( keepObj->getRequiredDescription() );
				auto removalProbe = indexByUDescrIdx->find( keyUDescrIdx );
				if( removalProbe != indexByUDescrIdx->end() ) {
					indexByUDescrIdx->erase( removalProbe );
				}
			}

			keepObj->setBuff( dynamic_cast<cfsec::CFSecClusterBuff*>( Obj->getBuff()->clone() ) );
			// Attach new object to alternate and duplicate indexes -- PKey stays stable

			if( indexByUDomNameIdx != NULL ) {
				static const std::string S_AUDomNameIdxObj( "aUDomNameIdxObj" );
				cfsec::ICFSecClusterObj* aUDomNameIdxObj =
					dynamic_cast<cfsec::ICFSecClusterObj*>( keepObj );
				if( aUDomNameIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AUDomNameIdxObj );
				}
				cfsec::CFSecClusterByUDomNameIdxKey keyUDomNameIdx;
				keyUDomNameIdx.setRequiredFullDomName( keepObj->getRequiredFullDomName() );
				indexByUDomNameIdx->insert( std::map< cfsec::CFSecClusterByUDomNameIdxKey, cfsec::ICFSecClusterObj* >::value_type( keyUDomNameIdx, aUDomNameIdxObj ) );
			}

			if( indexByUDescrIdx != NULL ) {
				static const std::string S_AUDescrIdxObj( "aUDescrIdxObj" );
				cfsec::ICFSecClusterObj* aUDescrIdxObj =
					dynamic_cast<cfsec::ICFSecClusterObj*>( keepObj );
				if( aUDescrIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AUDescrIdxObj );
				}
				cfsec::CFSecClusterByUDescrIdxKey keyUDescrIdx;
				keyUDescrIdx.setRequiredDescription( keepObj->getRequiredDescription() );
				indexByUDescrIdx->insert( std::map< cfsec::CFSecClusterByUDescrIdxKey, cfsec::ICFSecClusterObj* >::value_type( keyUDescrIdx, aUDescrIdxObj ) );
			}

			if( allCluster != NULL ) {
				allCluster->insert( std::map< cfsec::CFSecClusterPKey, cfsec::ICFSecClusterObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			}
		}
		else {
			keepObj = obj;
			keepObj->setIsNew( false );
			pkey = keepObj->getPKey();
			// Attach new object to PKey, all, alternate, and duplicate indexes
			members->insert( std::map< cfsec::CFSecClusterPKey, cfsec::ICFSecClusterObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			// Attach new object to alternate and duplicate indexes -- PKey stay stable

			if( indexByUDomNameIdx != NULL ) {
				static const std::string S_AUDomNameIdxObj( "aUDomNameIdxObj" );
				cfsec::ICFSecClusterObj* aUDomNameIdxObj =
					dynamic_cast<cfsec::ICFSecClusterObj*>( keepObj );
				if( aUDomNameIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AUDomNameIdxObj );
				}
				cfsec::CFSecClusterByUDomNameIdxKey keyUDomNameIdx;
				keyUDomNameIdx.setRequiredFullDomName( keepObj->getRequiredFullDomName() );
				indexByUDomNameIdx->insert( std::map< cfsec::CFSecClusterByUDomNameIdxKey, cfsec::ICFSecClusterObj* >::value_type( keyUDomNameIdx, aUDomNameIdxObj ) );
			}

			if( indexByUDescrIdx != NULL ) {
				static const std::string S_AUDescrIdxObj( "aUDescrIdxObj" );
				cfsec::ICFSecClusterObj* aUDescrIdxObj =
					dynamic_cast<cfsec::ICFSecClusterObj*>( keepObj );
				if( aUDescrIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AUDescrIdxObj );
				}
				cfsec::CFSecClusterByUDescrIdxKey keyUDescrIdx;
				keyUDescrIdx.setRequiredDescription( keepObj->getRequiredDescription() );
				indexByUDescrIdx->insert( std::map< cfsec::CFSecClusterByUDescrIdxKey, cfsec::ICFSecClusterObj* >::value_type( keyUDescrIdx, aUDescrIdxObj ) );
			}

			if( allCluster != NULL ) {
				allCluster->insert( std::map< cfsec::CFSecClusterPKey, cfsec::ICFSecClusterObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
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

	void CFSecClusterTableObj::deepDisposeByIdIdx( const int64_t Id ) {
		static const std::string S_ProcName( "deepDisposeByIdIdx" );
		std::vector<cfsec::ICFSecClusterObj*> list;
		cfsec::ICFSecClusterObj* existingObj = readCachedClusterByIdIdx( Id );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfsec::ICFSecClusterObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecClusterBuff::CLASS_CODE ) {
					dynamic_cast<cfsec::CFSecClusterTableObj*>( schema->getClusterTableObj() )->reallyDeepDisposeCluster( dynamic_cast<cfsec::ICFSecClusterObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFSecClusterTableObj::deepDisposeByUDomNameIdx( const std::string& FullDomName ) {
		static const std::string S_ProcName( "deepDisposeByUDomNameIdx" );
		std::vector<cfsec::ICFSecClusterObj*> list;
		cfsec::ICFSecClusterObj* existingObj = readCachedClusterByUDomNameIdx( FullDomName );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfsec::ICFSecClusterObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecClusterBuff::CLASS_CODE ) {
					dynamic_cast<cfsec::CFSecClusterTableObj*>( schema->getClusterTableObj() )->reallyDeepDisposeCluster( dynamic_cast<cfsec::ICFSecClusterObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFSecClusterTableObj::deepDisposeByUDescrIdx( const std::string& Description ) {
		static const std::string S_ProcName( "deepDisposeByUDescrIdx" );
		std::vector<cfsec::ICFSecClusterObj*> list;
		cfsec::ICFSecClusterObj* existingObj = readCachedClusterByUDescrIdx( Description );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfsec::ICFSecClusterObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecClusterBuff::CLASS_CODE ) {
					dynamic_cast<cfsec::CFSecClusterTableObj*>( schema->getClusterTableObj() )->reallyDeepDisposeCluster( dynamic_cast<cfsec::ICFSecClusterObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFSecClusterTableObj::reallyDeepDisposeCluster( cfsec::ICFSecClusterObj* Obj ) {
		static const std::string S_ProcName( "reallyDeepDisposeCluster" );

		if( Obj == NULL ) {
			return;
		}

		cfsec::ICFSecClusterObj* obj = Obj;
		
		cfsec::ICFSecSecGroupObj* objDelSecGroupForms;
		std::vector<cfsec::ICFSecSecGroupObj*> arrDelSecGroupForms = dynamic_cast<cfsec::CFSecSecGroupTableObj*>( schema->getSecGroupTableObj() )->readCachedSecGroupByClusterIdx( obj->getRequiredId() );
		std::vector<cfsec::ICFSecSecGroupObj*>::iterator iterArrDelSecGroupForms = arrDelSecGroupForms.begin();
		std::vector<cfsec::ICFSecSecGroupObj*>::iterator endArrDelSecGroupForms = arrDelSecGroupForms.end();
		while( iterArrDelSecGroupForms != endArrDelSecGroupForms ) {
			objDelSecGroupForms = *iterArrDelSecGroupForms;
			iterArrDelSecGroupForms ++;
			dynamic_cast<cfsec::CFSecSecGroupFormTableObj*>( schema->getSecGroupFormTableObj() )->deepDisposeByGroupIdx( objDelSecGroupForms->getRequiredClusterId(),
				objDelSecGroupForms->getRequiredSecGroupId() );
		}
		cfsec::ICFSecSecGroupObj* objDelSecGrpIncByGroup;
		std::vector<cfsec::ICFSecSecGroupObj*> arrDelSecGrpIncByGroup = dynamic_cast<cfsec::CFSecSecGroupTableObj*>( schema->getSecGroupTableObj() )->readCachedSecGroupByClusterIdx( obj->getRequiredId() );
		std::vector<cfsec::ICFSecSecGroupObj*>::iterator iterArrDelSecGrpIncByGroup = arrDelSecGrpIncByGroup.begin();
		std::vector<cfsec::ICFSecSecGroupObj*>::iterator endArrDelSecGrpIncByGroup = arrDelSecGrpIncByGroup.end();
		while( iterArrDelSecGrpIncByGroup != endArrDelSecGrpIncByGroup ) {
			objDelSecGrpIncByGroup = *iterArrDelSecGrpIncByGroup;
			iterArrDelSecGrpIncByGroup ++;
			dynamic_cast<cfsec::CFSecSecGrpIncTableObj*>( schema->getSecGrpIncTableObj() )->deepDisposeByIncludeIdx( objDelSecGrpIncByGroup->getRequiredClusterId(),
				objDelSecGrpIncByGroup->getRequiredSecGroupId() );
		}
		cfsec::ICFSecSecGroupObj* objDelSecGrpMembs;
		std::vector<cfsec::ICFSecSecGroupObj*> arrDelSecGrpMembs = dynamic_cast<cfsec::CFSecSecGroupTableObj*>( schema->getSecGroupTableObj() )->readCachedSecGroupByClusterIdx( obj->getRequiredId() );
		std::vector<cfsec::ICFSecSecGroupObj*>::iterator iterArrDelSecGrpMembs = arrDelSecGrpMembs.begin();
		std::vector<cfsec::ICFSecSecGroupObj*>::iterator endArrDelSecGrpMembs = arrDelSecGrpMembs.end();
		while( iterArrDelSecGrpMembs != endArrDelSecGrpMembs ) {
			objDelSecGrpMembs = *iterArrDelSecGrpMembs;
			iterArrDelSecGrpMembs ++;
			dynamic_cast<cfsec::CFSecSecGrpMembTableObj*>( schema->getSecGrpMembTableObj() )->deepDisposeByGroupIdx( objDelSecGrpMembs->getRequiredClusterId(),
				objDelSecGrpMembs->getRequiredSecGroupId() );
		}
		cfsec::ICFSecSecGroupObj* objDelSecGrpIncs;
		std::vector<cfsec::ICFSecSecGroupObj*> arrDelSecGrpIncs = dynamic_cast<cfsec::CFSecSecGroupTableObj*>( schema->getSecGroupTableObj() )->readCachedSecGroupByClusterIdx( obj->getRequiredId() );
		std::vector<cfsec::ICFSecSecGroupObj*>::iterator iterArrDelSecGrpIncs = arrDelSecGrpIncs.begin();
		std::vector<cfsec::ICFSecSecGroupObj*>::iterator endArrDelSecGrpIncs = arrDelSecGrpIncs.end();
		while( iterArrDelSecGrpIncs != endArrDelSecGrpIncs ) {
			objDelSecGrpIncs = *iterArrDelSecGrpIncs;
			iterArrDelSecGrpIncs ++;
			dynamic_cast<cfsec::CFSecSecGrpIncTableObj*>( schema->getSecGrpIncTableObj() )->deepDisposeByGroupIdx( objDelSecGrpIncs->getRequiredClusterId(),
				objDelSecGrpIncs->getRequiredSecGroupId() );
		}
		dynamic_cast<cfsec::CFSecSecGroupTableObj*>( schema->getSecGroupTableObj() )->deepDisposeByClusterIdx( obj->getRequiredId() );
		cfsec::ICFSecSecAppObj* objDelSecAppForms;
		std::vector<cfsec::ICFSecSecAppObj*> arrDelSecAppForms = dynamic_cast<cfsec::CFSecSecAppTableObj*>( schema->getSecAppTableObj() )->readCachedSecAppByClusterIdx( obj->getRequiredId() );
		std::vector<cfsec::ICFSecSecAppObj*>::iterator iterArrDelSecAppForms = arrDelSecAppForms.begin();
		std::vector<cfsec::ICFSecSecAppObj*>::iterator endArrDelSecAppForms = arrDelSecAppForms.end();
		while( iterArrDelSecAppForms != endArrDelSecAppForms ) {
			objDelSecAppForms = *iterArrDelSecAppForms;
			iterArrDelSecAppForms ++;
			dynamic_cast<cfsec::CFSecSecFormTableObj*>( schema->getSecFormTableObj() )->deepDisposeBySecAppIdx( objDelSecAppForms->getRequiredClusterId(),
				objDelSecAppForms->getRequiredSecAppId() );
		}
		dynamic_cast<cfsec::CFSecSecAppTableObj*>( schema->getSecAppTableObj() )->deepDisposeByClusterIdx( obj->getRequiredId() );
		dynamic_cast<cfsec::CFSecTenantTableObj*>( schema->getTenantTableObj() )->deepDisposeByClusterIdx( obj->getRequiredId() );
		dynamic_cast<cfsec::CFSecHostNodeTableObj*>( schema->getHostNodeTableObj() )->deepDisposeByClusterIdx( obj->getRequiredId() );
		classcode_t classCode = obj->getClassCode();
		if( classCode == cfsec::CFSecClusterBuff::CLASS_CODE ) {
			dynamic_cast<cfsec::CFSecClusterTableObj*>( schema->getClusterTableObj() )->reallyDetachFromIndexesCluster( dynamic_cast<cfsec::ICFSecClusterObj*>( obj ) );
		}

		if( obj->getEdit() != NULL ) {
			obj->endEdit();
		}
		delete obj;
		obj = NULL;
	}

	cfsec::ICFSecClusterObj* CFSecClusterTableObj::createCluster( cfsec::ICFSecClusterEditObj* Obj ) {
		static const std::string S_ProcName( "createCluster" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Cloneable( "cloneable" );
		static const std::string S_ClonedBuff( "clonedbuff" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecClusterObj* obj = dynamic_cast<cfsec::ICFSecClusterObj*>( Obj->getOrig() );
		try {
			cfsec::CFSecClusterBuff* buff = dynamic_cast<cfsec::CFSecClusterBuff*>( Obj->getBuff()->clone() );
			// C++18 version of create returns a new buffer instance and takes over ownership of the passed-in buffer
			// MSS TODO WORKING The xmsg client will need to return the buffer instance created by processing
			// the response message, while xmsg rqst will have to delete the backing store instance
			// it receives after preparing the reply message so that memory doesn't leak on every request.
			cflib::ICFLibCloneableObj* cloneable = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableCluster()->createCluster(
				schema->getAuthorization(),
				buff );
			if( cloneable == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Cloneable );
			}
			Obj->endEdit();
			obj->setBuff( dynamic_cast<cfsec::CFSecClusterBuff*>( cloneable ) );
			obj = dynamic_cast<cfsec::ICFSecClusterObj*>( obj->realize() );
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

	cfsec::ICFSecClusterObj* CFSecClusterTableObj::readCluster( cfsec::CFSecClusterPKey* pkey, bool forceRead ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readCluster" );
		cfsec::ICFSecClusterObj* obj = NULL;
		cfsec::ICFSecClusterObj* realized = NULL;
		if( ! forceRead ) {
			auto searchMembers = members->find( *pkey );
			if( searchMembers != members->end() ) {
				// obj could be NULL if cache misses is enabled
				obj = searchMembers->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecClusterBuff* readBuff = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableCluster()->readDerivedByIdIdx( schema->getAuthorization(),
			pkey->getRequiredId() );
			if( readBuff != NULL ) {
			obj = dynamic_cast<cfsec::CFSecClusterTableObj*>( schema->getClusterTableObj() )->newInstance();
				obj->setBuff( readBuff );
				realized = dynamic_cast<cfsec::ICFSecClusterObj*>( obj->realize() );
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

	cfsec::ICFSecClusterObj* CFSecClusterTableObj::lockCluster( cfsec::CFSecClusterPKey* pkey ) {
		static const std::string S_ProcName( "lockCluster" );
		cfsec::ICFSecClusterObj* locked = NULL;
		cfsec::CFSecClusterBuff* lockBuff = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableCluster()->lockDerived( schema->getAuthorization(), pkey );
		if( lockBuff != NULL ) {
			locked = dynamic_cast<cfsec::CFSecClusterTableObj*>( schema->getClusterTableObj() )->newInstance();
			locked->setBuff( lockBuff );
			locked = dynamic_cast<cfsec::ICFSecClusterObj*>( locked->realize() );
		}
		else {
			return( NULL );
		}
		return( locked );
	}

	std::vector<cfsec::ICFSecClusterObj*> CFSecClusterTableObj::readAllCluster( bool forceRead ) {
		static const std::string S_ProcName( "readAllCluster" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Realized( "realized" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecClusterObj* realized = NULL;
		if( forceRead || ( allCluster == NULL ) ) {
			std::map<cfsec::CFSecClusterPKey, cfsec::ICFSecClusterObj*>* map = new std::map<cfsec::CFSecClusterPKey,cfsec::ICFSecClusterObj*>();
			allCluster = map;
			std::TCFLibOwningVector<cfsec::CFSecClusterBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableCluster()->readAllDerived( schema->getAuthorization() );
			cfsec::CFSecClusterBuff* buff = NULL;
			cfsec::ICFSecClusterObj* obj = NULL;
			try {
				for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
					buff = buffList[ idx ];
					buffList[ idx ] = NULL;
				obj = newInstance();
					obj->setBuff( buff );
					realized = dynamic_cast<cfsec::ICFSecClusterObj*>( obj->realize() );
					if( realized == NULL ) {
						throw cflib::CFLibNullArgumentException( CLASS_NAME,
							S_ProcName,
							0,
							S_Realized );
					}
					allCluster->insert( std::map< cfsec::CFSecClusterPKey, cfsec::ICFSecClusterObj* >::value_type( *(realized->getPKey()), realized ) );
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
		size_t len = allCluster->size();
		std::vector<cfsec::ICFSecClusterObj*> arr;
		auto valIter = allCluster->begin();
		size_t idx = 0;
		while( valIter != allCluster->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	std::vector<cfsec::ICFSecClusterObj*> CFSecClusterTableObj::pageAllCluster(const int64_t* priorId )
	{
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "pageAllCluster" );
		CFLIB_EXCEPTION_DECLINFO
		std::map<cfsec::CFSecClusterPKey, cfsec::ICFSecClusterObj*>* map = NULL;
		cfsec::CFSecClusterBuff* buff = NULL;
		cfsec::ICFSecClusterObj* obj = NULL;
		cfsec::ICFSecClusterObj* realized = NULL;
		std::vector<cfsec::ICFSecClusterObj*> arrayList;
		try {
			map = new std::map<cfsec::CFSecClusterPKey,cfsec::ICFSecClusterObj*>();
			std::TCFLibOwningVector<cfsec::CFSecClusterBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableCluster()->pageAllBuff( schema->getAuthorization(),
				priorId );
			arrayList.reserve( buffList.size() );
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = newInstance();
				obj->setBuff( buff );
				realized = dynamic_cast<cfsec::ICFSecClusterObj*>( obj->realize() );
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

	cfsec::ICFSecClusterObj* CFSecClusterTableObj::readClusterByIdIdx( const int64_t Id, bool forceRead )
	{
		static const std::string S_ProcName( "readClusterByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecClusterPKey pkey;
		pkey.setRequiredId( Id );
		cfsec::ICFSecClusterObj* obj = readCluster( &pkey, forceRead );
		return( obj );
	}

	cfsec::ICFSecClusterObj* CFSecClusterTableObj::readClusterByUDomNameIdx( const std::string& FullDomName, bool forceRead )
	{
		static const std::string S_ProcName( "readClusterByUDomNameIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByUDomNameIdx == NULL ) {
			indexByUDomNameIdx = new std::map< cfsec::CFSecClusterByUDomNameIdxKey,
				cfsec::ICFSecClusterObj*>();
		}
		cfsec::CFSecClusterByUDomNameIdxKey key;
		key.setRequiredFullDomName( FullDomName );
		cfsec::ICFSecClusterObj* obj = NULL;
		cfsec::ICFSecClusterObj* realized = NULL;
		if( ! forceRead ) {
			auto searchIndexByUDomNameIdx = indexByUDomNameIdx->find( key );
			if( searchIndexByUDomNameIdx != indexByUDomNameIdx->end() ) {
				// Note: obj may be null if cache misses is enabled
				obj = searchIndexByUDomNameIdx->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecClusterBuff* buff = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableCluster()->readDerivedByUDomNameIdx( schema->getAuthorization(),
				FullDomName );
			if( buff != NULL ) {
				obj = dynamic_cast<cfsec::CFSecClusterTableObj*>( schema->getClusterTableObj() )->newInstance();
				obj->setBuff( buff );
				realized = dynamic_cast<cfsec::ICFSecClusterObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				indexByUDomNameIdx->insert( std::map< cfsec::CFSecClusterByUDomNameIdxKey, cfsec::ICFSecClusterObj*>::value_type( key, dynamic_cast<cfsec::ICFSecClusterObj*>( realized ) ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = realized;
			}
		}
		return( obj );
	}

	cfsec::ICFSecClusterObj* CFSecClusterTableObj::readClusterByUDescrIdx( const std::string& Description, bool forceRead )
	{
		static const std::string S_ProcName( "readClusterByUDescrIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByUDescrIdx == NULL ) {
			indexByUDescrIdx = new std::map< cfsec::CFSecClusterByUDescrIdxKey,
				cfsec::ICFSecClusterObj*>();
		}
		cfsec::CFSecClusterByUDescrIdxKey key;
		key.setRequiredDescription( Description );
		cfsec::ICFSecClusterObj* obj = NULL;
		cfsec::ICFSecClusterObj* realized = NULL;
		if( ! forceRead ) {
			auto searchIndexByUDescrIdx = indexByUDescrIdx->find( key );
			if( searchIndexByUDescrIdx != indexByUDescrIdx->end() ) {
				// Note: obj may be null if cache misses is enabled
				obj = searchIndexByUDescrIdx->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecClusterBuff* buff = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableCluster()->readDerivedByUDescrIdx( schema->getAuthorization(),
				Description );
			if( buff != NULL ) {
				obj = dynamic_cast<cfsec::CFSecClusterTableObj*>( schema->getClusterTableObj() )->newInstance();
				obj->setBuff( buff );
				realized = dynamic_cast<cfsec::ICFSecClusterObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				indexByUDescrIdx->insert( std::map< cfsec::CFSecClusterByUDescrIdxKey, cfsec::ICFSecClusterObj*>::value_type( key, dynamic_cast<cfsec::ICFSecClusterObj*>( realized ) ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = realized;
			}
		}
		return( obj );
	}

	cfsec::ICFSecClusterObj* CFSecClusterTableObj::readClusterByLookupUDomNameIdx( const std::string& FullDomName, bool forceRead )
	{
		static const std::string S_Realized( "realized" );
		static const std::string S_Obj( "obj" );
		static const std::string S_ProcName( "readClusterByLookupUDomNameIdx" );
		if( indexByUDomNameIdx == NULL ) {
			indexByUDomNameIdx = new std::map< cfsec::CFSecClusterByUDomNameIdxKey,
				cfsec::ICFSecClusterObj*>();
		}
		cfsec::CFSecClusterByUDomNameIdxKey key;
		key.setRequiredFullDomName( FullDomName );
		cfsec::ICFSecClusterObj* obj = NULL;
		cfsec::ICFSecClusterObj* realized = NULL;
		if( ! forceRead ) {
			auto searchIndexByUDomNameIdx = indexByUDomNameIdx->find( key );
			if( searchIndexByUDomNameIdx != indexByUDomNameIdx->end() ) {
				obj = searchIndexByUDomNameIdx->second;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecClusterBuff* buff = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableCluster()->readDerivedByLookupUDomNameIdx( schema->getAuthorization(),
				FullDomName );
			if( buff != NULL ) {
				obj = dynamic_cast<cfsec::ICFSecClusterObj*>( dynamic_cast<cfsec::CFSecClusterTableObj*>( schema->getClusterTableObj() )->newInstance() );
				obj->setBuff( buff );
				realized = dynamic_cast<cfsec::ICFSecClusterObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				indexByUDomNameIdx->insert( std::map< cfsec::CFSecClusterByUDomNameIdxKey, cfsec::ICFSecClusterObj*>::value_type( key, dynamic_cast<cfsec::ICFSecClusterObj*>( realized ) ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = realized;
			}
		}
		return( obj );
	}

	cfsec::ICFSecClusterObj* CFSecClusterTableObj::readCachedCluster( cfsec::CFSecClusterPKey* pkey ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readCluster" );
		cfsec::ICFSecClusterObj* obj = NULL;
		cfsec::ICFSecClusterObj* realized = NULL;
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			// obj could be NULL if cache misses is enabled
			obj = searchMembers->second;
			realized = obj;
		}
		return( realized );
	}

	cfsec::ICFSecClusterObj* CFSecClusterTableObj::readCachedClusterByIdIdx( const int64_t Id )
	{
		static const std::string S_ProcName( "readCachedClusterByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecClusterPKey pkey;
		pkey.setRequiredId( Id );
		cfsec::ICFSecClusterObj* obj = readCachedCluster( &pkey );
		return( obj );
	}

	cfsec::ICFSecClusterObj* CFSecClusterTableObj::readCachedClusterByUDomNameIdx( const std::string& FullDomName )
	{
		static const std::string S_ProcName( "readCachedClusterByUDomNameIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByUDomNameIdx == NULL ) {
			indexByUDomNameIdx = new std::map< cfsec::CFSecClusterByUDomNameIdxKey,
				cfsec::ICFSecClusterObj*>();
		}
		cfsec::CFSecClusterByUDomNameIdxKey key;
		key.setRequiredFullDomName( FullDomName );
		cfsec::ICFSecClusterObj* obj = NULL;
		auto searchIndexByUDomNameIdx = indexByUDomNameIdx->find( key );
		if( searchIndexByUDomNameIdx != indexByUDomNameIdx->end() ) {
			// Note: obj may be null if cache misses is enabled
			obj = searchIndexByUDomNameIdx->second;
		}
		else {
			for( auto iterMembers = members->begin(); ( obj == NULL ) && ( iterMembers != members->end() ); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecClusterBuff*>( obj->getBuff() ) ) != key ) {
						obj = NULL;
					}
				}
			}
		}
		return( obj );
	}

	cfsec::ICFSecClusterObj* CFSecClusterTableObj::readCachedClusterByUDescrIdx( const std::string& Description )
	{
		static const std::string S_ProcName( "readCachedClusterByUDescrIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByUDescrIdx == NULL ) {
			indexByUDescrIdx = new std::map< cfsec::CFSecClusterByUDescrIdxKey,
				cfsec::ICFSecClusterObj*>();
		}
		cfsec::CFSecClusterByUDescrIdxKey key;
		key.setRequiredDescription( Description );
		cfsec::ICFSecClusterObj* obj = NULL;
		auto searchIndexByUDescrIdx = indexByUDescrIdx->find( key );
		if( searchIndexByUDescrIdx != indexByUDescrIdx->end() ) {
			// Note: obj may be null if cache misses is enabled
			obj = searchIndexByUDescrIdx->second;
		}
		else {
			for( auto iterMembers = members->begin(); ( obj == NULL ) && ( iterMembers != members->end() ); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecClusterBuff*>( obj->getBuff() ) ) != key ) {
						obj = NULL;
					}
				}
			}
		}
		return( obj );
	}

	cfsec::ICFSecClusterObj* CFSecClusterTableObj::readCachedClusterByLookupUDomNameIdx( const std::string& FullDomName )
	{
		static const std::string S_Realized( "realized" );
		static const std::string S_Obj( "obj" );
		static const std::string S_ProcName( "readCachedClusterByLookupUDomNameIdx" );
		if( indexByUDomNameIdx == NULL ) {
			indexByUDomNameIdx = new std::map< cfsec::CFSecClusterByUDomNameIdxKey,
				cfsec::ICFSecClusterObj*>();
		}
		cfsec::CFSecClusterByUDomNameIdxKey key;
		key.setRequiredFullDomName( FullDomName );
		cfsec::ICFSecClusterObj* obj = NULL;
		cfsec::ICFSecClusterObj* realized = NULL;
		auto searchIndexByUDomNameIdx = indexByUDomNameIdx->find( key );
		if( searchIndexByUDomNameIdx != indexByUDomNameIdx->end() ) {
			obj = searchIndexByUDomNameIdx->second;
		}
		else {
			for( auto iterMembers = members->begin(); ( obj == NULL ) && ( iterMembers != members->end() ); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecClusterBuff*>( obj->getBuff() ) ) != key ) {
						obj = NULL;
					}
				}
			}
		}
		return( obj );
	}

	cfsec::ICFSecClusterObj* CFSecClusterTableObj::updateCluster( cfsec::ICFSecClusterEditObj* Obj ) {
		static const std::string S_ProcName( "updateCluster" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Updated( "updated" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecClusterObj* obj = dynamic_cast<cfsec::ICFSecClusterObj*>( Obj->getOrig() );
		try {
			cfsec::CFSecClusterBuff* updated = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableCluster()->updateCluster( schema->getAuthorization(),
				dynamic_cast<cfsec::CFSecClusterBuff*>( Obj->getClusterBuff()->clone() ) );
			if( updated == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Updated );
			}
			obj = dynamic_cast<cfsec::ICFSecClusterObj*>( dynamic_cast<cfsec::CFSecClusterTableObj*>( schema->getClusterTableObj() )->newInstance() );
			obj->setBuff( updated );
			obj = dynamic_cast<cfsec::ICFSecClusterObj*>( obj->realize() );
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

	void CFSecClusterTableObj::deleteCluster( cfsec::ICFSecClusterEditObj* Obj ) {
		cfsec::ICFSecClusterObj* obj = Obj;
		dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableCluster()->deleteCluster( schema->getAuthorization(),
			obj->getClusterBuff() );
		deepDisposeByIdIdx( obj->getRequiredId() );
	}

	void CFSecClusterTableObj::deleteClusterByIdIdx( const int64_t Id )
	{
		cfsec::CFSecClusterPKey pkey;
		pkey.setRequiredId( Id );
		cfsec::ICFSecClusterObj* obj = readCluster( &pkey, true );
		if( obj != NULL ) {
			cfsec::ICFSecClusterEditObj* editObj = dynamic_cast<cfsec::ICFSecClusterEditObj*>( obj->getEdit() );
			if( editObj == NULL ) {
				editObj = dynamic_cast<cfsec::ICFSecClusterEditObj*>( obj->beginEdit() );
			}
			if( editObj != NULL ) {
				editObj->deleteInstance();
				editObj = NULL;
			}
		}
	}

	void CFSecClusterTableObj::deleteClusterByUDomNameIdx( const std::string& FullDomName )
	{
		if( indexByUDomNameIdx == NULL ) {
			indexByUDomNameIdx = new std::map< cfsec::CFSecClusterByUDomNameIdxKey,
				cfsec::ICFSecClusterObj*>();
		}
		cfsec::CFSecClusterByUDomNameIdxKey key;
		key.setRequiredFullDomName( FullDomName );
		cfsec::ICFSecClusterObj* obj = NULL;
		auto searchIndexByUDomNameIdx = indexByUDomNameIdx->find( key );
		if( searchIndexByUDomNameIdx != indexByUDomNameIdx->end() ) {
			dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableCluster()->deleteClusterByUDomNameIdx( schema->getAuthorization(),
				FullDomName );
		}
		else {
			dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableCluster()->deleteClusterByUDomNameIdx( schema->getAuthorization(),
				FullDomName );
		}
		deepDisposeByUDomNameIdx( FullDomName );
	}

	void CFSecClusterTableObj::deleteClusterByUDescrIdx( const std::string& Description )
	{
		if( indexByUDescrIdx == NULL ) {
			indexByUDescrIdx = new std::map< cfsec::CFSecClusterByUDescrIdxKey,
				cfsec::ICFSecClusterObj*>();
		}
		cfsec::CFSecClusterByUDescrIdxKey key;
		key.setRequiredDescription( Description );
		cfsec::ICFSecClusterObj* obj = NULL;
		auto searchIndexByUDescrIdx = indexByUDescrIdx->find( key );
		if( searchIndexByUDescrIdx != indexByUDescrIdx->end() ) {
			dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableCluster()->deleteClusterByUDescrIdx( schema->getAuthorization(),
				Description );
		}
		else {
			dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableCluster()->deleteClusterByUDescrIdx( schema->getAuthorization(),
				Description );
		}
		deepDisposeByUDescrIdx( Description );
	}

	void CFSecClusterTableObj::reallyDetachFromIndexesCluster( cfsec::ICFSecClusterObj* Obj ) {
		static const std::string S_ProcName( "reallyDetachFromIndexesCluster" );
		static const std::string S_Obj( "Obj" );
		static const std::string S_ExistingObj( "ExistingObj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfsec::ICFSecClusterObj* obj = Obj;
		cfsec::CFSecClusterPKey* pkey = obj->getPKey();
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			cfsec::ICFSecClusterObj* existingObj = searchMembers->second;
			if( existingObj == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_ExistingObj );
			}
			if( indexByUDomNameIdx != NULL ) {
				cfsec::CFSecClusterByUDomNameIdxKey keyUDomNameIdx;
				keyUDomNameIdx.setRequiredFullDomName( obj->getRequiredFullDomName() );
				auto removalProbe = indexByUDomNameIdx->find( keyUDomNameIdx );
				if( removalProbe != indexByUDomNameIdx->end() ) {
					indexByUDomNameIdx->erase( removalProbe );
				}
			}

			if( indexByUDescrIdx != NULL ) {
				cfsec::CFSecClusterByUDescrIdxKey keyUDescrIdx;
				keyUDescrIdx.setRequiredDescription( obj->getRequiredDescription() );
				auto removalProbe = indexByUDescrIdx->find( keyUDescrIdx );
				if( removalProbe != indexByUDescrIdx->end() ) {
					indexByUDescrIdx->erase( removalProbe );
				}
			}

			members->erase( searchMembers );
		}
	}

	cfsec::ICFSecClusterObj* CFSecClusterTableObj::getSystemCluster() {
		static const std::string S_System( "system" );
		bool transactionStarted = schema->beginTransaction();
		cfsec::ICFSecClusterObj* clusterObj;
		try {
			clusterObj = readClusterByUDomNameIdx( S_System );
			if( clusterObj == NULL ) {
				clusterObj = readClusterByUDomNameIdx( S_System, true );
				if( clusterObj == NULL ) {
					clusterObj = newInstance();
					cfsec::ICFSecClusterEditObj* clusterEdit = clusterObj->beginEdit();
					clusterEdit->setRequiredFullDomName( S_System );
					clusterEdit->setRequiredDescription( S_System );
					clusterObj = clusterEdit->create();
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
		return( clusterObj );
	}


}
