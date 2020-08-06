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

	const std::string CFSecTSecGroupTableObj::CLASS_NAME( "CFSecTSecGroupTableObj" );
	const std::string CFSecTSecGroupTableObj::TABLE_NAME( "TSecGroup" );
	const std::string CFSecTSecGroupTableObj::TABLE_DBNAME( "TSecGrp" );

	CFSecTSecGroupTableObj::CFSecTSecGroupTableObj() {
		schema = NULL;
		members = new std::map<cfsec::CFSecTSecGroupPKey, cfsec::ICFSecTSecGroupObj*>();
		allTSecGroup = NULL;
		indexByTenantIdx = new std::map< cfsec::CFSecTSecGroupByTenantIdxKey,
			std::map< cfsec::CFSecTSecGroupPKey, cfsec::ICFSecTSecGroupObj*>*>();
		indexByTenantVisIdx = new std::map< cfsec::CFSecTSecGroupByTenantVisIdxKey,
			std::map< cfsec::CFSecTSecGroupPKey, cfsec::ICFSecTSecGroupObj*>*>();
		indexByUNameIdx = new std::map< cfsec::CFSecTSecGroupByUNameIdxKey,
			cfsec::ICFSecTSecGroupObj*>();
	}

	CFSecTSecGroupTableObj::CFSecTSecGroupTableObj( cfsec::ICFSecSchemaObj* argSchema ) {
		schema = dynamic_cast<cfsec::ICFSecSchemaObj*>( argSchema );
		members = new std::map<cfsec::CFSecTSecGroupPKey, cfsec::ICFSecTSecGroupObj*>();
		allTSecGroup = NULL;
		indexByTenantIdx = new std::map< cfsec::CFSecTSecGroupByTenantIdxKey,
			std::map< cfsec::CFSecTSecGroupPKey, cfsec::ICFSecTSecGroupObj*>*>();
		indexByTenantVisIdx = new std::map< cfsec::CFSecTSecGroupByTenantVisIdxKey,
			std::map< cfsec::CFSecTSecGroupPKey, cfsec::ICFSecTSecGroupObj*>*>();
		indexByUNameIdx = new std::map< cfsec::CFSecTSecGroupByUNameIdxKey,
			cfsec::ICFSecTSecGroupObj*>();
	}

	CFSecTSecGroupTableObj::~CFSecTSecGroupTableObj() {
		minimizeMemory();
		if( indexByTenantIdx != NULL ) {
			delete indexByTenantIdx;
			indexByTenantIdx = NULL;
		}
		if( indexByTenantVisIdx != NULL ) {
			delete indexByTenantVisIdx;
			indexByTenantVisIdx = NULL;
		}
		if( indexByUNameIdx != NULL ) {
			delete indexByUNameIdx;
			indexByUNameIdx = NULL;
		}
		if( members != NULL ) {
			cfsec::ICFSecTSecGroupObj* curMember;
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

	cfsec::ICFSecSchemaObj* CFSecTSecGroupTableObj::getSchema() {
		return( schema );
	}

	void CFSecTSecGroupTableObj::setSchema( cfsec::ICFSecSchemaObj* value ) {
		schema = dynamic_cast<cfsec::ICFSecSchemaObj*>( value );
	}

	const std::string CFSecTSecGroupTableObj::getTableName() {
		return( TABLE_NAME );
	}

	const std::string CFSecTSecGroupTableObj::getTableDbName() {
		return( TABLE_DBNAME );
	}
	const classcode_t* CFSecTSecGroupTableObj::getObjQualifyingClassCode() {
		return( NULL );
	}


	void CFSecTSecGroupTableObj::minimizeMemory() {
		if( allTSecGroup != NULL ) {
			allTSecGroup->clear();
			delete allTSecGroup;
			allTSecGroup = NULL;
		}
		if( indexByTenantIdx != NULL ) {
			std::map< cfsec::CFSecTSecGroupByTenantIdxKey,
				std::map< cfsec::CFSecTSecGroupPKey, cfsec::ICFSecTSecGroupObj*>* >::iterator iterByTenantIdx = indexByTenantIdx->begin();
			std::map< cfsec::CFSecTSecGroupByTenantIdxKey,
				std::map< cfsec::CFSecTSecGroupPKey, cfsec::ICFSecTSecGroupObj*>* >::iterator endByTenantIdx = indexByTenantIdx->end();
			std::map< cfsec::CFSecTSecGroupPKey, cfsec::ICFSecTSecGroupObj*>* curByTenantIdx = NULL;
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
		if( indexByTenantVisIdx != NULL ) {
			std::map< cfsec::CFSecTSecGroupByTenantVisIdxKey,
				std::map< cfsec::CFSecTSecGroupPKey, cfsec::ICFSecTSecGroupObj*>* >::iterator iterByTenantVisIdx = indexByTenantVisIdx->begin();
			std::map< cfsec::CFSecTSecGroupByTenantVisIdxKey,
				std::map< cfsec::CFSecTSecGroupPKey, cfsec::ICFSecTSecGroupObj*>* >::iterator endByTenantVisIdx = indexByTenantVisIdx->end();
			std::map< cfsec::CFSecTSecGroupPKey, cfsec::ICFSecTSecGroupObj*>* curByTenantVisIdx = NULL;
			while( iterByTenantVisIdx != endByTenantVisIdx ) {
				curByTenantVisIdx = iterByTenantVisIdx->second;
				if( curByTenantVisIdx != NULL ) {
					curByTenantVisIdx->clear();
					delete curByTenantVisIdx;
					curByTenantVisIdx = NULL;
					iterByTenantVisIdx->second = NULL;
				}
				iterByTenantVisIdx ++;
			}
			indexByTenantVisIdx->clear();
		}
		if( indexByUNameIdx != NULL ) {
			indexByUNameIdx->clear();
		}
		if( members != NULL ) {
			cfsec::ICFSecTSecGroupObj* cur = NULL;
			cfsec::ICFSecTSecGroupEditObj* edit = NULL;
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

	cfsec::ICFSecTSecGroupObj* CFSecTSecGroupTableObj::newInstance() {
		cfsec::ICFSecTSecGroupObj* inst = dynamic_cast<cfsec::ICFSecTSecGroupObj*>( new CFSecTSecGroupObj( schema ) );
		return( inst );
	}

	cfsec::ICFSecTSecGroupEditObj* CFSecTSecGroupTableObj::newEditInstance( cfsec::ICFSecTSecGroupObj* orig ) {
		cfsec::ICFSecTSecGroupEditObj* edit = dynamic_cast<cfsec::ICFSecTSecGroupEditObj*>( new CFSecTSecGroupEditObj( orig ));
		return( edit );
	}

	cfsec::ICFSecTSecGroupObj* CFSecTSecGroupTableObj::realizeTSecGroup( cfsec::ICFSecTSecGroupObj* Obj ) {
		static const std::string S_ProcName( "realizeTSecGroup" );
		static const std::string S_ExistingObj( "existingObj" );
		static const std::string S_KeepObj( "keepObj" );
		static const std::string S_Obj( "Obj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfsec::ICFSecTSecGroupObj* obj = Obj;
		cfsec::ICFSecTSecGroupObj* existingObj = NULL;
		cfsec::CFSecTSecGroupPKey* pkey = obj->getPKey();
		cfsec::ICFSecTSecGroupObj* keepObj = NULL;
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
				cfsec::CFSecTSecGroupByTenantIdxKey keyTenantIdx;
				keyTenantIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				auto searchTenantIdx = indexByTenantIdx->find( keyTenantIdx );
				if( searchTenantIdx != indexByTenantIdx->end() ) {
					std::map<cfsec::CFSecTSecGroupPKey, cfsec::ICFSecTSecGroupObj*>* mapTenantIdx = searchTenantIdx->second;
					if( mapTenantIdx != NULL ) {
						auto removalProbe = mapTenantIdx->find( *(keepObj->getPKey()) );
						if( removalProbe != mapTenantIdx->end() ) {
							mapTenantIdx->erase( removalProbe );
						}
					}
				}
			}

			if( indexByTenantVisIdx != NULL ) {
				cfsec::CFSecTSecGroupByTenantVisIdxKey keyTenantVisIdx;
				keyTenantVisIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				keyTenantVisIdx.setRequiredIsVisible( keepObj->getRequiredIsVisible() );
				auto searchTenantVisIdx = indexByTenantVisIdx->find( keyTenantVisIdx );
				if( searchTenantVisIdx != indexByTenantVisIdx->end() ) {
					std::map<cfsec::CFSecTSecGroupPKey, cfsec::ICFSecTSecGroupObj*>* mapTenantVisIdx = searchTenantVisIdx->second;
					if( mapTenantVisIdx != NULL ) {
						auto removalProbe = mapTenantVisIdx->find( *(keepObj->getPKey()) );
						if( removalProbe != mapTenantVisIdx->end() ) {
							mapTenantVisIdx->erase( removalProbe );
						}
					}
				}
			}

			if( indexByUNameIdx != NULL ) {
				cfsec::CFSecTSecGroupByUNameIdxKey keyUNameIdx;
				keyUNameIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				keyUNameIdx.setRequiredName( keepObj->getRequiredName() );
				auto removalProbe = indexByUNameIdx->find( keyUNameIdx );
				if( removalProbe != indexByUNameIdx->end() ) {
					indexByUNameIdx->erase( removalProbe );
				}
			}

			keepObj->setBuff( dynamic_cast<cfsec::CFSecTSecGroupBuff*>( Obj->getBuff()->clone() ) );
			// Attach new object to alternate and duplicate indexes -- PKey stays stable

			if( indexByTenantIdx != NULL ) {
				static const std::string S_ATenantIdxObj( "aTenantIdxObj" );
				cfsec::ICFSecTSecGroupObj* aTenantIdxObj =
					dynamic_cast<cfsec::ICFSecTSecGroupObj*>( keepObj );
				if( aTenantIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ATenantIdxObj );
				}
				cfsec::CFSecTSecGroupByTenantIdxKey keyTenantIdx;
				keyTenantIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				auto searchIndexByTenantIdx = indexByTenantIdx->find( keyTenantIdx );
				if( searchIndexByTenantIdx != indexByTenantIdx->end() ) {
					std::map<cfsec::CFSecTSecGroupPKey, cfsec::ICFSecTSecGroupObj*>* mapTenantIdx = searchIndexByTenantIdx->second;
					if( mapTenantIdx != NULL ) {
						mapTenantIdx->insert( std::map< cfsec::CFSecTSecGroupPKey, cfsec::ICFSecTSecGroupObj* >::value_type( *(keepObj->getPKey()), aTenantIdxObj ) );
					}
				}
			}

			if( indexByTenantVisIdx != NULL ) {
				static const std::string S_ATenantVisIdxObj( "aTenantVisIdxObj" );
				cfsec::ICFSecTSecGroupObj* aTenantVisIdxObj =
					dynamic_cast<cfsec::ICFSecTSecGroupObj*>( keepObj );
				if( aTenantVisIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ATenantVisIdxObj );
				}
				cfsec::CFSecTSecGroupByTenantVisIdxKey keyTenantVisIdx;
				keyTenantVisIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				keyTenantVisIdx.setRequiredIsVisible( keepObj->getRequiredIsVisible() );
				auto searchIndexByTenantVisIdx = indexByTenantVisIdx->find( keyTenantVisIdx );
				if( searchIndexByTenantVisIdx != indexByTenantVisIdx->end() ) {
					std::map<cfsec::CFSecTSecGroupPKey, cfsec::ICFSecTSecGroupObj*>* mapTenantVisIdx = searchIndexByTenantVisIdx->second;
					if( mapTenantVisIdx != NULL ) {
						mapTenantVisIdx->insert( std::map< cfsec::CFSecTSecGroupPKey, cfsec::ICFSecTSecGroupObj* >::value_type( *(keepObj->getPKey()), aTenantVisIdxObj ) );
					}
				}
			}

			if( indexByUNameIdx != NULL ) {
				static const std::string S_AUNameIdxObj( "aUNameIdxObj" );
				cfsec::ICFSecTSecGroupObj* aUNameIdxObj =
					dynamic_cast<cfsec::ICFSecTSecGroupObj*>( keepObj );
				if( aUNameIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AUNameIdxObj );
				}
				cfsec::CFSecTSecGroupByUNameIdxKey keyUNameIdx;
				keyUNameIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				keyUNameIdx.setRequiredName( keepObj->getRequiredName() );
				indexByUNameIdx->insert( std::map< cfsec::CFSecTSecGroupByUNameIdxKey, cfsec::ICFSecTSecGroupObj* >::value_type( keyUNameIdx, aUNameIdxObj ) );
			}

			if( allTSecGroup != NULL ) {
				allTSecGroup->insert( std::map< cfsec::CFSecTSecGroupPKey, cfsec::ICFSecTSecGroupObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			}
		}
		else {
			keepObj = obj;
			keepObj->setIsNew( false );
			pkey = keepObj->getPKey();
			// Attach new object to PKey, all, alternate, and duplicate indexes
			members->insert( std::map< cfsec::CFSecTSecGroupPKey, cfsec::ICFSecTSecGroupObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			// Attach new object to alternate and duplicate indexes -- PKey stay stable

			if( indexByTenantIdx != NULL ) {
				static const std::string S_ATenantIdxObj( "aTenantIdxObj" );
				cfsec::ICFSecTSecGroupObj* aTenantIdxObj =
					dynamic_cast<cfsec::ICFSecTSecGroupObj*>( keepObj );
				if( aTenantIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ATenantIdxObj );
				}
				cfsec::CFSecTSecGroupByTenantIdxKey keyTenantIdx;
				keyTenantIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				auto searchIndexByTenantIdx = indexByTenantIdx->find( keyTenantIdx );
				if( searchIndexByTenantIdx != indexByTenantIdx->end() ) {
					std::map<cfsec::CFSecTSecGroupPKey, cfsec::ICFSecTSecGroupObj*>* mapTenantIdx = searchIndexByTenantIdx->second;
					if( mapTenantIdx != NULL ) {
						mapTenantIdx->insert( std::map< cfsec::CFSecTSecGroupPKey, cfsec::ICFSecTSecGroupObj* >::value_type( *(keepObj->getPKey()), aTenantIdxObj ) );
					}
				}
			}

			if( indexByTenantVisIdx != NULL ) {
				static const std::string S_ATenantVisIdxObj( "aTenantVisIdxObj" );
				cfsec::ICFSecTSecGroupObj* aTenantVisIdxObj =
					dynamic_cast<cfsec::ICFSecTSecGroupObj*>( keepObj );
				if( aTenantVisIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ATenantVisIdxObj );
				}
				cfsec::CFSecTSecGroupByTenantVisIdxKey keyTenantVisIdx;
				keyTenantVisIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				keyTenantVisIdx.setRequiredIsVisible( keepObj->getRequiredIsVisible() );
				auto searchIndexByTenantVisIdx = indexByTenantVisIdx->find( keyTenantVisIdx );
				if( searchIndexByTenantVisIdx != indexByTenantVisIdx->end() ) {
					std::map<cfsec::CFSecTSecGroupPKey, cfsec::ICFSecTSecGroupObj*>* mapTenantVisIdx = searchIndexByTenantVisIdx->second;
					if( mapTenantVisIdx != NULL ) {
						mapTenantVisIdx->insert( std::map< cfsec::CFSecTSecGroupPKey, cfsec::ICFSecTSecGroupObj* >::value_type( *(keepObj->getPKey()), aTenantVisIdxObj ) );
					}
				}
			}

			if( indexByUNameIdx != NULL ) {
				static const std::string S_AUNameIdxObj( "aUNameIdxObj" );
				cfsec::ICFSecTSecGroupObj* aUNameIdxObj =
					dynamic_cast<cfsec::ICFSecTSecGroupObj*>( keepObj );
				if( aUNameIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AUNameIdxObj );
				}
				cfsec::CFSecTSecGroupByUNameIdxKey keyUNameIdx;
				keyUNameIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				keyUNameIdx.setRequiredName( keepObj->getRequiredName() );
				indexByUNameIdx->insert( std::map< cfsec::CFSecTSecGroupByUNameIdxKey, cfsec::ICFSecTSecGroupObj* >::value_type( keyUNameIdx, aUNameIdxObj ) );
			}

			if( allTSecGroup != NULL ) {
				allTSecGroup->insert( std::map< cfsec::CFSecTSecGroupPKey, cfsec::ICFSecTSecGroupObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
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

	void CFSecTSecGroupTableObj::deepDisposeByIdIdx( const int64_t TenantId,
			const int32_t TSecGroupId ) {
		static const std::string S_ProcName( "deepDisposeByIdIdx" );
		std::vector<cfsec::ICFSecTSecGroupObj*> list;
		cfsec::ICFSecTSecGroupObj* existingObj = readCachedTSecGroupByIdIdx( TenantId,
				TSecGroupId );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfsec::ICFSecTSecGroupObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecTSecGroupBuff::CLASS_CODE ) {
					dynamic_cast<cfsec::CFSecTSecGroupTableObj*>( schema->getTSecGroupTableObj() )->reallyDeepDisposeTSecGroup( dynamic_cast<cfsec::ICFSecTSecGroupObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFSecTSecGroupTableObj::deepDisposeByTenantIdx( const int64_t TenantId ) {
		static const std::string S_ProcName( "deepDisposeByTenantIdx" );
		std::vector<cfsec::ICFSecTSecGroupObj*> list;
		std::vector<cfsec::ICFSecTSecGroupObj*> matchesFound = readCachedTSecGroupByTenantIdx( TenantId );
		auto iterMatches = matchesFound.begin();
		auto endMatches = matchesFound.end();
		while( iterMatches != endMatches ) {
			if( *iterMatches != NULL ) {
				list.push_back( *iterMatches );
			}
			iterMatches ++;
		}
		cfsec::ICFSecTSecGroupObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecTSecGroupBuff::CLASS_CODE ) {
					dynamic_cast<cfsec::CFSecTSecGroupTableObj*>( schema->getTSecGroupTableObj() )->reallyDeepDisposeTSecGroup( dynamic_cast<cfsec::ICFSecTSecGroupObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFSecTSecGroupTableObj::deepDisposeByTenantVisIdx( const int64_t TenantId,
			const bool IsVisible ) {
		static const std::string S_ProcName( "deepDisposeByTenantVisIdx" );
		std::vector<cfsec::ICFSecTSecGroupObj*> list;
		std::vector<cfsec::ICFSecTSecGroupObj*> matchesFound = readCachedTSecGroupByTenantVisIdx( TenantId,
				IsVisible );
		auto iterMatches = matchesFound.begin();
		auto endMatches = matchesFound.end();
		while( iterMatches != endMatches ) {
			if( *iterMatches != NULL ) {
				list.push_back( *iterMatches );
			}
			iterMatches ++;
		}
		cfsec::ICFSecTSecGroupObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecTSecGroupBuff::CLASS_CODE ) {
					dynamic_cast<cfsec::CFSecTSecGroupTableObj*>( schema->getTSecGroupTableObj() )->reallyDeepDisposeTSecGroup( dynamic_cast<cfsec::ICFSecTSecGroupObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFSecTSecGroupTableObj::deepDisposeByUNameIdx( const int64_t TenantId,
			const std::string& Name ) {
		static const std::string S_ProcName( "deepDisposeByUNameIdx" );
		std::vector<cfsec::ICFSecTSecGroupObj*> list;
		cfsec::ICFSecTSecGroupObj* existingObj = readCachedTSecGroupByUNameIdx( TenantId,
				Name );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfsec::ICFSecTSecGroupObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecTSecGroupBuff::CLASS_CODE ) {
					dynamic_cast<cfsec::CFSecTSecGroupTableObj*>( schema->getTSecGroupTableObj() )->reallyDeepDisposeTSecGroup( dynamic_cast<cfsec::ICFSecTSecGroupObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFSecTSecGroupTableObj::reallyDeepDisposeTSecGroup( cfsec::ICFSecTSecGroupObj* Obj ) {
		static const std::string S_ProcName( "reallyDeepDisposeTSecGroup" );

		if( Obj == NULL ) {
			return;
		}

		cfsec::ICFSecTSecGroupObj* obj = Obj;
		
		dynamic_cast<cfsec::CFSecTSecGrpIncTableObj*>( schema->getTSecGrpIncTableObj() )->deepDisposeByIncludeIdx( obj->getRequiredTenantId(),
			obj->getRequiredTSecGroupId() );
		dynamic_cast<cfsec::CFSecTSecGrpMembTableObj*>( schema->getTSecGrpMembTableObj() )->deepDisposeByGroupIdx( obj->getRequiredTenantId(),
			obj->getRequiredTSecGroupId() );
		dynamic_cast<cfsec::CFSecTSecGrpIncTableObj*>( schema->getTSecGrpIncTableObj() )->deepDisposeByGroupIdx( obj->getRequiredTenantId(),
			obj->getRequiredTSecGroupId() );
		classcode_t classCode = obj->getClassCode();
		if( classCode == cfsec::CFSecTSecGroupBuff::CLASS_CODE ) {
			dynamic_cast<cfsec::CFSecTSecGroupTableObj*>( schema->getTSecGroupTableObj() )->reallyDetachFromIndexesTSecGroup( dynamic_cast<cfsec::ICFSecTSecGroupObj*>( obj ) );
		}

		if( obj->getEdit() != NULL ) {
			obj->endEdit();
		}
		delete obj;
		obj = NULL;
	}

	cfsec::ICFSecTSecGroupObj* CFSecTSecGroupTableObj::createTSecGroup( cfsec::ICFSecTSecGroupEditObj* Obj ) {
		static const std::string S_ProcName( "createTSecGroup" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Cloneable( "cloneable" );
		static const std::string S_ClonedBuff( "clonedbuff" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecTSecGroupObj* obj = dynamic_cast<cfsec::ICFSecTSecGroupObj*>( Obj->getOrig() );
		try {
			cfsec::CFSecTSecGroupBuff* buff = dynamic_cast<cfsec::CFSecTSecGroupBuff*>( Obj->getBuff()->clone() );
			// C++18 version of create returns a new buffer instance and takes over ownership of the passed-in buffer
			// MSS TODO WORKING The xmsg client will need to return the buffer instance created by processing
			// the response message, while xmsg rqst will have to delete the backing store instance
			// it receives after preparing the reply message so that memory doesn't leak on every request.
			cflib::ICFLibCloneableObj* cloneable = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableTSecGroup()->createTSecGroup(
				schema->getAuthorization(),
				buff );
			if( cloneable == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Cloneable );
			}
			Obj->endEdit();
			obj->setBuff( dynamic_cast<cfsec::CFSecTSecGroupBuff*>( cloneable ) );
			obj = dynamic_cast<cfsec::ICFSecTSecGroupObj*>( obj->realize() );
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

	cfsec::ICFSecTSecGroupObj* CFSecTSecGroupTableObj::readTSecGroup( cfsec::CFSecTSecGroupPKey* pkey, bool forceRead ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readTSecGroup" );
		cfsec::ICFSecTSecGroupObj* obj = NULL;
		cfsec::ICFSecTSecGroupObj* realized = NULL;
		if( ! forceRead ) {
			auto searchMembers = members->find( *pkey );
			if( searchMembers != members->end() ) {
				// obj could be NULL if cache misses is enabled
				obj = searchMembers->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecTSecGroupBuff* readBuff = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableTSecGroup()->readDerivedByIdIdx( schema->getAuthorization(),
			pkey->getRequiredTenantId(),
			pkey->getRequiredTSecGroupId() );
			if( readBuff != NULL ) {
			obj = dynamic_cast<cfsec::CFSecTSecGroupTableObj*>( schema->getTSecGroupTableObj() )->newInstance();
				obj->setBuff( readBuff );
				realized = dynamic_cast<cfsec::ICFSecTSecGroupObj*>( obj->realize() );
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

	cfsec::ICFSecTSecGroupObj* CFSecTSecGroupTableObj::lockTSecGroup( cfsec::CFSecTSecGroupPKey* pkey ) {
		static const std::string S_ProcName( "lockTSecGroup" );
		cfsec::ICFSecTSecGroupObj* locked = NULL;
		cfsec::CFSecTSecGroupBuff* lockBuff = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableTSecGroup()->lockDerived( schema->getAuthorization(), pkey );
		if( lockBuff != NULL ) {
			locked = dynamic_cast<cfsec::CFSecTSecGroupTableObj*>( schema->getTSecGroupTableObj() )->newInstance();
			locked->setBuff( lockBuff );
			locked = dynamic_cast<cfsec::ICFSecTSecGroupObj*>( locked->realize() );
		}
		else {
			return( NULL );
		}
		return( locked );
	}

	std::vector<cfsec::ICFSecTSecGroupObj*> CFSecTSecGroupTableObj::readAllTSecGroup( bool forceRead ) {
		static const std::string S_ProcName( "readAllTSecGroup" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Realized( "realized" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecTSecGroupObj* realized = NULL;
		if( forceRead || ( allTSecGroup == NULL ) ) {
			std::map<cfsec::CFSecTSecGroupPKey, cfsec::ICFSecTSecGroupObj*>* map = new std::map<cfsec::CFSecTSecGroupPKey,cfsec::ICFSecTSecGroupObj*>();
			allTSecGroup = map;
			std::TCFLibOwningVector<cfsec::CFSecTSecGroupBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableTSecGroup()->readAllDerived( schema->getAuthorization() );
			cfsec::CFSecTSecGroupBuff* buff = NULL;
			cfsec::ICFSecTSecGroupObj* obj = NULL;
			try {
				for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
					buff = buffList[ idx ];
					buffList[ idx ] = NULL;
				obj = newInstance();
					obj->setBuff( buff );
					realized = dynamic_cast<cfsec::ICFSecTSecGroupObj*>( obj->realize() );
					if( realized == NULL ) {
						throw cflib::CFLibNullArgumentException( CLASS_NAME,
							S_ProcName,
							0,
							S_Realized );
					}
					allTSecGroup->insert( std::map< cfsec::CFSecTSecGroupPKey, cfsec::ICFSecTSecGroupObj* >::value_type( *(realized->getPKey()), realized ) );
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
		size_t len = allTSecGroup->size();
		std::vector<cfsec::ICFSecTSecGroupObj*> arr;
		auto valIter = allTSecGroup->begin();
		size_t idx = 0;
		while( valIter != allTSecGroup->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	cfsec::ICFSecTSecGroupObj* CFSecTSecGroupTableObj::readTSecGroupByIdIdx( const int64_t TenantId,
			const int32_t TSecGroupId, bool forceRead )
	{
		static const std::string S_ProcName( "readTSecGroupByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecTSecGroupPKey pkey;
		pkey.setRequiredTenantId( TenantId );
		pkey.setRequiredTSecGroupId( TSecGroupId );
		cfsec::ICFSecTSecGroupObj* obj = readTSecGroup( &pkey, forceRead );
		return( obj );
	}

	std::vector<cfsec::ICFSecTSecGroupObj*> CFSecTSecGroupTableObj::readTSecGroupByTenantIdx( const int64_t TenantId,
		bool forceRead )
	{
		static const std::string S_ProcName( "readTSecGroupByTenantIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecTSecGroupByTenantIdxKey key;
		key.setRequiredTenantId( TenantId );
		std::map<cfsec::CFSecTSecGroupPKey, cfsec::ICFSecTSecGroupObj*>* dict;
		std::map<cfsec::CFSecTSecGroupPKey, cfsec::ICFSecTSecGroupObj*>* oldDict;
		if( indexByTenantIdx == NULL ) {
			indexByTenantIdx = new std::map< cfsec::CFSecTSecGroupByTenantIdxKey,
				std::map< cfsec::CFSecTSecGroupPKey, cfsec::ICFSecTSecGroupObj*>*>();
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
			dict = new std::map<cfsec::CFSecTSecGroupPKey, cfsec::ICFSecTSecGroupObj*>();
			cfsec::ICFSecTSecGroupObj* obj;
			std::TCFLibOwningVector<cfsec::CFSecTSecGroupBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableTSecGroup()->readDerivedByTenantIdx( schema->getAuthorization(),
				TenantId );
			cfsec::CFSecTSecGroupBuff* buff;
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = dynamic_cast<cfsec::CFSecTSecGroupTableObj*>( schema->getTSecGroupTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
				obj->setBuff( buff );
				cfsec::ICFSecTSecGroupObj* realized = dynamic_cast<cfsec::ICFSecTSecGroupObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				dict->insert( std::map< cfsec::CFSecTSecGroupPKey, cfsec::ICFSecTSecGroupObj* >::value_type( *(realized->getPKey()), realized ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = NULL;
			}
			if( oldDict != NULL ) {
				indexByTenantIdx->erase( searchIndexByTenantIdx );
				delete oldDict;
				oldDict = NULL;
			}
			indexByTenantIdx->insert( std::map< cfsec::CFSecTSecGroupByTenantIdxKey,
				std::map< cfsec::CFSecTSecGroupPKey, cfsec::ICFSecTSecGroupObj* >* >::value_type( key, dict ) );
		}
		size_t len = dict->size();
		std::vector<cfsec::ICFSecTSecGroupObj*> arr;
		arr.reserve( len );
		auto valIter = dict->begin();
		while( valIter != dict->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	std::vector<cfsec::ICFSecTSecGroupObj*> CFSecTSecGroupTableObj::readTSecGroupByTenantVisIdx( const int64_t TenantId,
			const bool IsVisible,
		bool forceRead )
	{
		static const std::string S_ProcName( "readTSecGroupByTenantVisIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecTSecGroupByTenantVisIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredIsVisible( IsVisible );
		std::map<cfsec::CFSecTSecGroupPKey, cfsec::ICFSecTSecGroupObj*>* dict;
		std::map<cfsec::CFSecTSecGroupPKey, cfsec::ICFSecTSecGroupObj*>* oldDict;
		if( indexByTenantVisIdx == NULL ) {
			indexByTenantVisIdx = new std::map< cfsec::CFSecTSecGroupByTenantVisIdxKey,
				std::map< cfsec::CFSecTSecGroupPKey, cfsec::ICFSecTSecGroupObj*>*>();
		}
		auto searchIndexByTenantVisIdx = indexByTenantVisIdx->find( key );
		if( searchIndexByTenantVisIdx != indexByTenantVisIdx->end() ) {
			oldDict = searchIndexByTenantVisIdx->second;
		}
		else {
			oldDict = NULL;
		}
		if( ( oldDict != NULL ) && ( ! forceRead ) ) {
			dict = oldDict;
		}
		else {
			dict = new std::map<cfsec::CFSecTSecGroupPKey, cfsec::ICFSecTSecGroupObj*>();
			cfsec::ICFSecTSecGroupObj* obj;
			std::TCFLibOwningVector<cfsec::CFSecTSecGroupBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableTSecGroup()->readDerivedByTenantVisIdx( schema->getAuthorization(),
				TenantId,
				IsVisible );
			cfsec::CFSecTSecGroupBuff* buff;
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = dynamic_cast<cfsec::CFSecTSecGroupTableObj*>( schema->getTSecGroupTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
				obj->setBuff( buff );
				cfsec::ICFSecTSecGroupObj* realized = dynamic_cast<cfsec::ICFSecTSecGroupObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				dict->insert( std::map< cfsec::CFSecTSecGroupPKey, cfsec::ICFSecTSecGroupObj* >::value_type( *(realized->getPKey()), realized ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = NULL;
			}
			if( oldDict != NULL ) {
				indexByTenantVisIdx->erase( searchIndexByTenantVisIdx );
				delete oldDict;
				oldDict = NULL;
			}
			indexByTenantVisIdx->insert( std::map< cfsec::CFSecTSecGroupByTenantVisIdxKey,
				std::map< cfsec::CFSecTSecGroupPKey, cfsec::ICFSecTSecGroupObj* >* >::value_type( key, dict ) );
		}
		size_t len = dict->size();
		std::vector<cfsec::ICFSecTSecGroupObj*> arr;
		arr.reserve( len );
		auto valIter = dict->begin();
		while( valIter != dict->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	cfsec::ICFSecTSecGroupObj* CFSecTSecGroupTableObj::readTSecGroupByUNameIdx( const int64_t TenantId,
			const std::string& Name, bool forceRead )
	{
		static const std::string S_ProcName( "readTSecGroupByUNameIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByUNameIdx == NULL ) {
			indexByUNameIdx = new std::map< cfsec::CFSecTSecGroupByUNameIdxKey,
				cfsec::ICFSecTSecGroupObj*>();
		}
		cfsec::CFSecTSecGroupByUNameIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredName( Name );
		cfsec::ICFSecTSecGroupObj* obj = NULL;
		cfsec::ICFSecTSecGroupObj* realized = NULL;
		if( ! forceRead ) {
			auto searchIndexByUNameIdx = indexByUNameIdx->find( key );
			if( searchIndexByUNameIdx != indexByUNameIdx->end() ) {
				// Note: obj may be null if cache misses is enabled
				obj = searchIndexByUNameIdx->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecTSecGroupBuff* buff = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableTSecGroup()->readDerivedByUNameIdx( schema->getAuthorization(),
				TenantId,
				Name );
			if( buff != NULL ) {
				obj = dynamic_cast<cfsec::CFSecTSecGroupTableObj*>( schema->getTSecGroupTableObj() )->newInstance();
				obj->setBuff( buff );
				realized = dynamic_cast<cfsec::ICFSecTSecGroupObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				indexByUNameIdx->insert( std::map< cfsec::CFSecTSecGroupByUNameIdxKey, cfsec::ICFSecTSecGroupObj*>::value_type( key, dynamic_cast<cfsec::ICFSecTSecGroupObj*>( realized ) ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = realized;
			}
		}
		return( obj );
	}

	cfsec::ICFSecTSecGroupObj* CFSecTSecGroupTableObj::readTSecGroupByLookupUNameIdx( const int64_t TenantId,
			const std::string& Name, bool forceRead )
	{
		static const std::string S_Realized( "realized" );
		static const std::string S_Obj( "obj" );
		static const std::string S_ProcName( "readTSecGroupByLookupUNameIdx" );
		if( indexByUNameIdx == NULL ) {
			indexByUNameIdx = new std::map< cfsec::CFSecTSecGroupByUNameIdxKey,
				cfsec::ICFSecTSecGroupObj*>();
		}
		cfsec::CFSecTSecGroupByUNameIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredName( Name );
		cfsec::ICFSecTSecGroupObj* obj = NULL;
		cfsec::ICFSecTSecGroupObj* realized = NULL;
		if( ! forceRead ) {
			auto searchIndexByUNameIdx = indexByUNameIdx->find( key );
			if( searchIndexByUNameIdx != indexByUNameIdx->end() ) {
				obj = searchIndexByUNameIdx->second;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecTSecGroupBuff* buff = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableTSecGroup()->readDerivedByLookupUNameIdx( schema->getAuthorization(),
				TenantId,
				Name );
			if( buff != NULL ) {
				obj = dynamic_cast<cfsec::ICFSecTSecGroupObj*>( dynamic_cast<cfsec::CFSecTSecGroupTableObj*>( schema->getTSecGroupTableObj() )->newInstance() );
				obj->setBuff( buff );
				realized = dynamic_cast<cfsec::ICFSecTSecGroupObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				indexByUNameIdx->insert( std::map< cfsec::CFSecTSecGroupByUNameIdxKey, cfsec::ICFSecTSecGroupObj*>::value_type( key, dynamic_cast<cfsec::ICFSecTSecGroupObj*>( realized ) ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = realized;
			}
		}
		return( obj );
	}

	cfsec::ICFSecTSecGroupObj* CFSecTSecGroupTableObj::readCachedTSecGroup( cfsec::CFSecTSecGroupPKey* pkey ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readTSecGroup" );
		cfsec::ICFSecTSecGroupObj* obj = NULL;
		cfsec::ICFSecTSecGroupObj* realized = NULL;
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			// obj could be NULL if cache misses is enabled
			obj = searchMembers->second;
			realized = obj;
		}
		return( realized );
	}

	cfsec::ICFSecTSecGroupObj* CFSecTSecGroupTableObj::readCachedTSecGroupByIdIdx( const int64_t TenantId,
			const int32_t TSecGroupId )
	{
		static const std::string S_ProcName( "readCachedTSecGroupByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecTSecGroupPKey pkey;
		pkey.setRequiredTenantId( TenantId );
		pkey.setRequiredTSecGroupId( TSecGroupId );
		cfsec::ICFSecTSecGroupObj* obj = readCachedTSecGroup( &pkey );
		return( obj );
	}

	std::vector<cfsec::ICFSecTSecGroupObj*> CFSecTSecGroupTableObj::readCachedTSecGroupByTenantIdx( const int64_t TenantId )
	{
		static const std::string S_ProcName( "readCachedTSecGroupByTenantIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		std::vector<cfsec::ICFSecTSecGroupObj*> arr;
		cfsec::CFSecTSecGroupByTenantIdxKey key;
		key.setRequiredTenantId( TenantId );
		std::map<cfsec::CFSecTSecGroupPKey, cfsec::ICFSecTSecGroupObj*>* dict;
		if( indexByTenantIdx == NULL ) {
			return( arr );
		}
		auto searchIndexByTenantIdx = indexByTenantIdx->find( key );
		if( searchIndexByTenantIdx != indexByTenantIdx->end() ) {
			dict = searchIndexByTenantIdx->second;
			size_t len = dict->size();
			std::vector<cfsec::ICFSecTSecGroupObj*> arr;
			arr.reserve( len );
			auto valIter = dict->begin();
			while( valIter != dict->end() ) {
				arr.push_back( valIter->second );
				valIter ++;
			}
		}
		else {
			cfsec::ICFSecTSecGroupObj* obj;
			for( auto iterMembers = members->begin(); iterMembers != members->end(); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecTSecGroupBuff*>( obj->getBuff() ) ) == key ) {
						arr.push_back( obj );
					}
				}
			}
		}
		return( arr );
	}

	std::vector<cfsec::ICFSecTSecGroupObj*> CFSecTSecGroupTableObj::readCachedTSecGroupByTenantVisIdx( const int64_t TenantId,
			const bool IsVisible )
	{
		static const std::string S_ProcName( "readCachedTSecGroupByTenantVisIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		std::vector<cfsec::ICFSecTSecGroupObj*> arr;
		cfsec::CFSecTSecGroupByTenantVisIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredIsVisible( IsVisible );
		std::map<cfsec::CFSecTSecGroupPKey, cfsec::ICFSecTSecGroupObj*>* dict;
		if( indexByTenantVisIdx == NULL ) {
			return( arr );
		}
		auto searchIndexByTenantVisIdx = indexByTenantVisIdx->find( key );
		if( searchIndexByTenantVisIdx != indexByTenantVisIdx->end() ) {
			dict = searchIndexByTenantVisIdx->second;
			size_t len = dict->size();
			std::vector<cfsec::ICFSecTSecGroupObj*> arr;
			arr.reserve( len );
			auto valIter = dict->begin();
			while( valIter != dict->end() ) {
				arr.push_back( valIter->second );
				valIter ++;
			}
		}
		else {
			cfsec::ICFSecTSecGroupObj* obj;
			for( auto iterMembers = members->begin(); iterMembers != members->end(); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecTSecGroupBuff*>( obj->getBuff() ) ) == key ) {
						arr.push_back( obj );
					}
				}
			}
		}
		return( arr );
	}

	cfsec::ICFSecTSecGroupObj* CFSecTSecGroupTableObj::readCachedTSecGroupByUNameIdx( const int64_t TenantId,
			const std::string& Name )
	{
		static const std::string S_ProcName( "readCachedTSecGroupByUNameIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByUNameIdx == NULL ) {
			indexByUNameIdx = new std::map< cfsec::CFSecTSecGroupByUNameIdxKey,
				cfsec::ICFSecTSecGroupObj*>();
		}
		cfsec::CFSecTSecGroupByUNameIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredName( Name );
		cfsec::ICFSecTSecGroupObj* obj = NULL;
		auto searchIndexByUNameIdx = indexByUNameIdx->find( key );
		if( searchIndexByUNameIdx != indexByUNameIdx->end() ) {
			// Note: obj may be null if cache misses is enabled
			obj = searchIndexByUNameIdx->second;
		}
		else {
			for( auto iterMembers = members->begin(); ( obj == NULL ) && ( iterMembers != members->end() ); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecTSecGroupBuff*>( obj->getBuff() ) ) != key ) {
						obj = NULL;
					}
				}
			}
		}
		return( obj );
	}

	cfsec::ICFSecTSecGroupObj* CFSecTSecGroupTableObj::readCachedTSecGroupByLookupUNameIdx( const int64_t TenantId,
			const std::string& Name )
	{
		static const std::string S_Realized( "realized" );
		static const std::string S_Obj( "obj" );
		static const std::string S_ProcName( "readCachedTSecGroupByLookupUNameIdx" );
		if( indexByUNameIdx == NULL ) {
			indexByUNameIdx = new std::map< cfsec::CFSecTSecGroupByUNameIdxKey,
				cfsec::ICFSecTSecGroupObj*>();
		}
		cfsec::CFSecTSecGroupByUNameIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredName( Name );
		cfsec::ICFSecTSecGroupObj* obj = NULL;
		cfsec::ICFSecTSecGroupObj* realized = NULL;
		auto searchIndexByUNameIdx = indexByUNameIdx->find( key );
		if( searchIndexByUNameIdx != indexByUNameIdx->end() ) {
			obj = searchIndexByUNameIdx->second;
		}
		else {
			for( auto iterMembers = members->begin(); ( obj == NULL ) && ( iterMembers != members->end() ); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecTSecGroupBuff*>( obj->getBuff() ) ) != key ) {
						obj = NULL;
					}
				}
			}
		}
		return( obj );
	}

	cfsec::ICFSecTSecGroupObj* CFSecTSecGroupTableObj::updateTSecGroup( cfsec::ICFSecTSecGroupEditObj* Obj ) {
		static const std::string S_ProcName( "updateTSecGroup" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Updated( "updated" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecTSecGroupObj* obj = dynamic_cast<cfsec::ICFSecTSecGroupObj*>( Obj->getOrig() );
		try {
			cfsec::CFSecTSecGroupBuff* updated = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableTSecGroup()->updateTSecGroup( schema->getAuthorization(),
				dynamic_cast<cfsec::CFSecTSecGroupBuff*>( Obj->getTSecGroupBuff()->clone() ) );
			if( updated == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Updated );
			}
			obj = dynamic_cast<cfsec::ICFSecTSecGroupObj*>( dynamic_cast<cfsec::CFSecTSecGroupTableObj*>( schema->getTSecGroupTableObj() )->newInstance() );
			obj->setBuff( updated );
			obj = dynamic_cast<cfsec::ICFSecTSecGroupObj*>( obj->realize() );
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

	void CFSecTSecGroupTableObj::deleteTSecGroup( cfsec::ICFSecTSecGroupEditObj* Obj ) {
		cfsec::ICFSecTSecGroupObj* obj = Obj;
		dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableTSecGroup()->deleteTSecGroup( schema->getAuthorization(),
			obj->getTSecGroupBuff() );
		deepDisposeByIdIdx( obj->getRequiredTenantId(),
			obj->getRequiredTSecGroupId() );
	}

	void CFSecTSecGroupTableObj::deleteTSecGroupByIdIdx( const int64_t TenantId,
			const int32_t TSecGroupId )
	{
		cfsec::CFSecTSecGroupPKey pkey;
		pkey.setRequiredTenantId( TenantId );
		pkey.setRequiredTSecGroupId( TSecGroupId );
		cfsec::ICFSecTSecGroupObj* obj = readTSecGroup( &pkey, true );
		if( obj != NULL ) {
			cfsec::ICFSecTSecGroupEditObj* editObj = dynamic_cast<cfsec::ICFSecTSecGroupEditObj*>( obj->getEdit() );
			if( editObj == NULL ) {
				editObj = dynamic_cast<cfsec::ICFSecTSecGroupEditObj*>( obj->beginEdit() );
			}
			if( editObj != NULL ) {
				editObj->deleteInstance();
				editObj = NULL;
			}
		}
	}

	void CFSecTSecGroupTableObj::deleteTSecGroupByTenantIdx( const int64_t TenantId )
	{
		dynamic_cast<cfsec::ICFSecSchema*>( schema->getBackingStore() )->getTableTSecGroup()->deleteTSecGroupByTenantIdx( schema->getAuthorization(),
				TenantId );
		deepDisposeByTenantIdx( TenantId );
	}

	void CFSecTSecGroupTableObj::deleteTSecGroupByTenantVisIdx( const int64_t TenantId,
			const bool IsVisible )
	{
		dynamic_cast<cfsec::ICFSecSchema*>( schema->getBackingStore() )->getTableTSecGroup()->deleteTSecGroupByTenantVisIdx( schema->getAuthorization(),
				TenantId,
				IsVisible );
		deepDisposeByTenantVisIdx( TenantId,
			IsVisible );
	}

	void CFSecTSecGroupTableObj::deleteTSecGroupByUNameIdx( const int64_t TenantId,
			const std::string& Name )
	{
		if( indexByUNameIdx == NULL ) {
			indexByUNameIdx = new std::map< cfsec::CFSecTSecGroupByUNameIdxKey,
				cfsec::ICFSecTSecGroupObj*>();
		}
		cfsec::CFSecTSecGroupByUNameIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredName( Name );
		cfsec::ICFSecTSecGroupObj* obj = NULL;
		auto searchIndexByUNameIdx = indexByUNameIdx->find( key );
		if( searchIndexByUNameIdx != indexByUNameIdx->end() ) {
			dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableTSecGroup()->deleteTSecGroupByUNameIdx( schema->getAuthorization(),
				TenantId,
				Name );
		}
		else {
			dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableTSecGroup()->deleteTSecGroupByUNameIdx( schema->getAuthorization(),
				TenantId,
				Name );
		}
		deepDisposeByUNameIdx( TenantId,
			Name );
	}

	void CFSecTSecGroupTableObj::reallyDetachFromIndexesTSecGroup( cfsec::ICFSecTSecGroupObj* Obj ) {
		static const std::string S_ProcName( "reallyDetachFromIndexesTSecGroup" );
		static const std::string S_Obj( "Obj" );
		static const std::string S_ExistingObj( "ExistingObj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfsec::ICFSecTSecGroupObj* obj = Obj;
		cfsec::CFSecTSecGroupPKey* pkey = obj->getPKey();
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			cfsec::ICFSecTSecGroupObj* existingObj = searchMembers->second;
			if( existingObj == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_ExistingObj );
			}
			if( indexByTenantIdx != NULL ) {
				cfsec::CFSecTSecGroupByTenantIdxKey keyTenantIdx;
				keyTenantIdx.setRequiredTenantId( obj->getRequiredTenantId() );
				auto searchTenantIdx = indexByTenantIdx->find( keyTenantIdx );
				if( searchTenantIdx != indexByTenantIdx->end() ) {
					std::map<cfsec::CFSecTSecGroupPKey, cfsec::ICFSecTSecGroupObj*>* mapTenantIdx = searchTenantIdx->second;
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

			if( indexByTenantVisIdx != NULL ) {
				cfsec::CFSecTSecGroupByTenantVisIdxKey keyTenantVisIdx;
				keyTenantVisIdx.setRequiredTenantId( obj->getRequiredTenantId() );
				keyTenantVisIdx.setRequiredIsVisible( obj->getRequiredIsVisible() );
				auto searchTenantVisIdx = indexByTenantVisIdx->find( keyTenantVisIdx );
				if( searchTenantVisIdx != indexByTenantVisIdx->end() ) {
					std::map<cfsec::CFSecTSecGroupPKey, cfsec::ICFSecTSecGroupObj*>* mapTenantVisIdx = searchTenantVisIdx->second;
					if( mapTenantVisIdx != NULL ) {
						auto removalProbe = mapTenantVisIdx->find( *(obj->getPKey()) );
						if( removalProbe != mapTenantVisIdx->end() ) {
							mapTenantVisIdx->erase( removalProbe );
							if( mapTenantVisIdx->empty() ) {
								delete mapTenantVisIdx;
								mapTenantVisIdx = NULL;
								indexByTenantVisIdx->erase( searchTenantVisIdx );
							}
						}
					}
				}
			}

			if( indexByUNameIdx != NULL ) {
				cfsec::CFSecTSecGroupByUNameIdxKey keyUNameIdx;
				keyUNameIdx.setRequiredTenantId( obj->getRequiredTenantId() );
				keyUNameIdx.setRequiredName( obj->getRequiredName() );
				auto removalProbe = indexByUNameIdx->find( keyUNameIdx );
				if( removalProbe != indexByUNameIdx->end() ) {
					indexByUNameIdx->erase( removalProbe );
				}
			}

			members->erase( searchMembers );
		}
	}


}
