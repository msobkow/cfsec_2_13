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

	const std::string CFSecTSecGrpIncTableObj::CLASS_NAME( "CFSecTSecGrpIncTableObj" );
	const std::string CFSecTSecGrpIncTableObj::TABLE_NAME( "TSecGrpInc" );
	const std::string CFSecTSecGrpIncTableObj::TABLE_DBNAME( "TSecInc" );

	CFSecTSecGrpIncTableObj::CFSecTSecGrpIncTableObj() {
		schema = NULL;
		members = new std::map<cfsec::CFSecTSecGrpIncPKey, cfsec::ICFSecTSecGrpIncObj*>();
		allTSecGrpInc = NULL;
		indexByTenantIdx = new std::map< cfsec::CFSecTSecGrpIncByTenantIdxKey,
			std::map< cfsec::CFSecTSecGrpIncPKey, cfsec::ICFSecTSecGrpIncObj*>*>();
		indexByGroupIdx = new std::map< cfsec::CFSecTSecGrpIncByGroupIdxKey,
			std::map< cfsec::CFSecTSecGrpIncPKey, cfsec::ICFSecTSecGrpIncObj*>*>();
		indexByIncludeIdx = new std::map< cfsec::CFSecTSecGrpIncByIncludeIdxKey,
			std::map< cfsec::CFSecTSecGrpIncPKey, cfsec::ICFSecTSecGrpIncObj*>*>();
		indexByUIncludeIdx = new std::map< cfsec::CFSecTSecGrpIncByUIncludeIdxKey,
			cfsec::ICFSecTSecGrpIncObj*>();
	}

	CFSecTSecGrpIncTableObj::CFSecTSecGrpIncTableObj( cfsec::ICFSecSchemaObj* argSchema ) {
		schema = dynamic_cast<cfsec::ICFSecSchemaObj*>( argSchema );
		members = new std::map<cfsec::CFSecTSecGrpIncPKey, cfsec::ICFSecTSecGrpIncObj*>();
		allTSecGrpInc = NULL;
		indexByTenantIdx = new std::map< cfsec::CFSecTSecGrpIncByTenantIdxKey,
			std::map< cfsec::CFSecTSecGrpIncPKey, cfsec::ICFSecTSecGrpIncObj*>*>();
		indexByGroupIdx = new std::map< cfsec::CFSecTSecGrpIncByGroupIdxKey,
			std::map< cfsec::CFSecTSecGrpIncPKey, cfsec::ICFSecTSecGrpIncObj*>*>();
		indexByIncludeIdx = new std::map< cfsec::CFSecTSecGrpIncByIncludeIdxKey,
			std::map< cfsec::CFSecTSecGrpIncPKey, cfsec::ICFSecTSecGrpIncObj*>*>();
		indexByUIncludeIdx = new std::map< cfsec::CFSecTSecGrpIncByUIncludeIdxKey,
			cfsec::ICFSecTSecGrpIncObj*>();
	}

	CFSecTSecGrpIncTableObj::~CFSecTSecGrpIncTableObj() {
		minimizeMemory();
		if( indexByTenantIdx != NULL ) {
			delete indexByTenantIdx;
			indexByTenantIdx = NULL;
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
			cfsec::ICFSecTSecGrpIncObj* curMember;
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

	cfsec::ICFSecSchemaObj* CFSecTSecGrpIncTableObj::getSchema() {
		return( schema );
	}

	void CFSecTSecGrpIncTableObj::setSchema( cfsec::ICFSecSchemaObj* value ) {
		schema = dynamic_cast<cfsec::ICFSecSchemaObj*>( value );
	}

	const std::string CFSecTSecGrpIncTableObj::getTableName() {
		return( TABLE_NAME );
	}

	const std::string CFSecTSecGrpIncTableObj::getTableDbName() {
		return( TABLE_DBNAME );
	}
	const classcode_t* CFSecTSecGrpIncTableObj::getObjQualifyingClassCode() {
		return( NULL );
	}


	void CFSecTSecGrpIncTableObj::minimizeMemory() {
		if( allTSecGrpInc != NULL ) {
			allTSecGrpInc->clear();
			delete allTSecGrpInc;
			allTSecGrpInc = NULL;
		}
		if( indexByTenantIdx != NULL ) {
			std::map< cfsec::CFSecTSecGrpIncByTenantIdxKey,
				std::map< cfsec::CFSecTSecGrpIncPKey, cfsec::ICFSecTSecGrpIncObj*>* >::iterator iterByTenantIdx = indexByTenantIdx->begin();
			std::map< cfsec::CFSecTSecGrpIncByTenantIdxKey,
				std::map< cfsec::CFSecTSecGrpIncPKey, cfsec::ICFSecTSecGrpIncObj*>* >::iterator endByTenantIdx = indexByTenantIdx->end();
			std::map< cfsec::CFSecTSecGrpIncPKey, cfsec::ICFSecTSecGrpIncObj*>* curByTenantIdx = NULL;
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
			std::map< cfsec::CFSecTSecGrpIncByGroupIdxKey,
				std::map< cfsec::CFSecTSecGrpIncPKey, cfsec::ICFSecTSecGrpIncObj*>* >::iterator iterByGroupIdx = indexByGroupIdx->begin();
			std::map< cfsec::CFSecTSecGrpIncByGroupIdxKey,
				std::map< cfsec::CFSecTSecGrpIncPKey, cfsec::ICFSecTSecGrpIncObj*>* >::iterator endByGroupIdx = indexByGroupIdx->end();
			std::map< cfsec::CFSecTSecGrpIncPKey, cfsec::ICFSecTSecGrpIncObj*>* curByGroupIdx = NULL;
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
			std::map< cfsec::CFSecTSecGrpIncByIncludeIdxKey,
				std::map< cfsec::CFSecTSecGrpIncPKey, cfsec::ICFSecTSecGrpIncObj*>* >::iterator iterByIncludeIdx = indexByIncludeIdx->begin();
			std::map< cfsec::CFSecTSecGrpIncByIncludeIdxKey,
				std::map< cfsec::CFSecTSecGrpIncPKey, cfsec::ICFSecTSecGrpIncObj*>* >::iterator endByIncludeIdx = indexByIncludeIdx->end();
			std::map< cfsec::CFSecTSecGrpIncPKey, cfsec::ICFSecTSecGrpIncObj*>* curByIncludeIdx = NULL;
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
			cfsec::ICFSecTSecGrpIncObj* cur = NULL;
			cfsec::ICFSecTSecGrpIncEditObj* edit = NULL;
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

	cfsec::ICFSecTSecGrpIncObj* CFSecTSecGrpIncTableObj::newInstance() {
		cfsec::ICFSecTSecGrpIncObj* inst = dynamic_cast<cfsec::ICFSecTSecGrpIncObj*>( new CFSecTSecGrpIncObj( schema ) );
		return( inst );
	}

	cfsec::ICFSecTSecGrpIncEditObj* CFSecTSecGrpIncTableObj::newEditInstance( cfsec::ICFSecTSecGrpIncObj* orig ) {
		cfsec::ICFSecTSecGrpIncEditObj* edit = dynamic_cast<cfsec::ICFSecTSecGrpIncEditObj*>( new CFSecTSecGrpIncEditObj( orig ));
		return( edit );
	}

	cfsec::ICFSecTSecGrpIncObj* CFSecTSecGrpIncTableObj::realizeTSecGrpInc( cfsec::ICFSecTSecGrpIncObj* Obj ) {
		static const std::string S_ProcName( "realizeTSecGrpInc" );
		static const std::string S_ExistingObj( "existingObj" );
		static const std::string S_KeepObj( "keepObj" );
		static const std::string S_Obj( "Obj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfsec::ICFSecTSecGrpIncObj* obj = Obj;
		cfsec::ICFSecTSecGrpIncObj* existingObj = NULL;
		cfsec::CFSecTSecGrpIncPKey* pkey = obj->getPKey();
		cfsec::ICFSecTSecGrpIncObj* keepObj = NULL;
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
				cfsec::CFSecTSecGrpIncByTenantIdxKey keyTenantIdx;
				keyTenantIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				auto searchTenantIdx = indexByTenantIdx->find( keyTenantIdx );
				if( searchTenantIdx != indexByTenantIdx->end() ) {
					std::map<cfsec::CFSecTSecGrpIncPKey, cfsec::ICFSecTSecGrpIncObj*>* mapTenantIdx = searchTenantIdx->second;
					if( mapTenantIdx != NULL ) {
						auto removalProbe = mapTenantIdx->find( *(keepObj->getPKey()) );
						if( removalProbe != mapTenantIdx->end() ) {
							mapTenantIdx->erase( removalProbe );
						}
					}
				}
			}

			if( indexByGroupIdx != NULL ) {
				cfsec::CFSecTSecGrpIncByGroupIdxKey keyGroupIdx;
				keyGroupIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				keyGroupIdx.setRequiredTSecGroupId( keepObj->getRequiredTSecGroupId() );
				auto searchGroupIdx = indexByGroupIdx->find( keyGroupIdx );
				if( searchGroupIdx != indexByGroupIdx->end() ) {
					std::map<cfsec::CFSecTSecGrpIncPKey, cfsec::ICFSecTSecGrpIncObj*>* mapGroupIdx = searchGroupIdx->second;
					if( mapGroupIdx != NULL ) {
						auto removalProbe = mapGroupIdx->find( *(keepObj->getPKey()) );
						if( removalProbe != mapGroupIdx->end() ) {
							mapGroupIdx->erase( removalProbe );
						}
					}
				}
			}

			if( indexByIncludeIdx != NULL ) {
				cfsec::CFSecTSecGrpIncByIncludeIdxKey keyIncludeIdx;
				keyIncludeIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				keyIncludeIdx.setRequiredIncludeGroupId( keepObj->getRequiredIncludeGroupId() );
				auto searchIncludeIdx = indexByIncludeIdx->find( keyIncludeIdx );
				if( searchIncludeIdx != indexByIncludeIdx->end() ) {
					std::map<cfsec::CFSecTSecGrpIncPKey, cfsec::ICFSecTSecGrpIncObj*>* mapIncludeIdx = searchIncludeIdx->second;
					if( mapIncludeIdx != NULL ) {
						auto removalProbe = mapIncludeIdx->find( *(keepObj->getPKey()) );
						if( removalProbe != mapIncludeIdx->end() ) {
							mapIncludeIdx->erase( removalProbe );
						}
					}
				}
			}

			if( indexByUIncludeIdx != NULL ) {
				cfsec::CFSecTSecGrpIncByUIncludeIdxKey keyUIncludeIdx;
				keyUIncludeIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				keyUIncludeIdx.setRequiredTSecGroupId( keepObj->getRequiredTSecGroupId() );
				keyUIncludeIdx.setRequiredIncludeGroupId( keepObj->getRequiredIncludeGroupId() );
				auto removalProbe = indexByUIncludeIdx->find( keyUIncludeIdx );
				if( removalProbe != indexByUIncludeIdx->end() ) {
					indexByUIncludeIdx->erase( removalProbe );
				}
			}

			keepObj->setBuff( dynamic_cast<cfsec::CFSecTSecGrpIncBuff*>( Obj->getBuff()->clone() ) );
			// Attach new object to alternate and duplicate indexes -- PKey stays stable

			if( indexByTenantIdx != NULL ) {
				static const std::string S_ATenantIdxObj( "aTenantIdxObj" );
				cfsec::ICFSecTSecGrpIncObj* aTenantIdxObj =
					dynamic_cast<cfsec::ICFSecTSecGrpIncObj*>( keepObj );
				if( aTenantIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ATenantIdxObj );
				}
				cfsec::CFSecTSecGrpIncByTenantIdxKey keyTenantIdx;
				keyTenantIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				auto searchIndexByTenantIdx = indexByTenantIdx->find( keyTenantIdx );
				if( searchIndexByTenantIdx != indexByTenantIdx->end() ) {
					std::map<cfsec::CFSecTSecGrpIncPKey, cfsec::ICFSecTSecGrpIncObj*>* mapTenantIdx = searchIndexByTenantIdx->second;
					if( mapTenantIdx != NULL ) {
						mapTenantIdx->insert( std::map< cfsec::CFSecTSecGrpIncPKey, cfsec::ICFSecTSecGrpIncObj* >::value_type( *(keepObj->getPKey()), aTenantIdxObj ) );
					}
				}
			}

			if( indexByGroupIdx != NULL ) {
				static const std::string S_AGroupIdxObj( "aGroupIdxObj" );
				cfsec::ICFSecTSecGrpIncObj* aGroupIdxObj =
					dynamic_cast<cfsec::ICFSecTSecGrpIncObj*>( keepObj );
				if( aGroupIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AGroupIdxObj );
				}
				cfsec::CFSecTSecGrpIncByGroupIdxKey keyGroupIdx;
				keyGroupIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				keyGroupIdx.setRequiredTSecGroupId( keepObj->getRequiredTSecGroupId() );
				auto searchIndexByGroupIdx = indexByGroupIdx->find( keyGroupIdx );
				if( searchIndexByGroupIdx != indexByGroupIdx->end() ) {
					std::map<cfsec::CFSecTSecGrpIncPKey, cfsec::ICFSecTSecGrpIncObj*>* mapGroupIdx = searchIndexByGroupIdx->second;
					if( mapGroupIdx != NULL ) {
						mapGroupIdx->insert( std::map< cfsec::CFSecTSecGrpIncPKey, cfsec::ICFSecTSecGrpIncObj* >::value_type( *(keepObj->getPKey()), aGroupIdxObj ) );
					}
				}
			}

			if( indexByIncludeIdx != NULL ) {
				static const std::string S_AIncludeIdxObj( "aIncludeIdxObj" );
				cfsec::ICFSecTSecGrpIncObj* aIncludeIdxObj =
					dynamic_cast<cfsec::ICFSecTSecGrpIncObj*>( keepObj );
				if( aIncludeIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AIncludeIdxObj );
				}
				cfsec::CFSecTSecGrpIncByIncludeIdxKey keyIncludeIdx;
				keyIncludeIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				keyIncludeIdx.setRequiredIncludeGroupId( keepObj->getRequiredIncludeGroupId() );
				auto searchIndexByIncludeIdx = indexByIncludeIdx->find( keyIncludeIdx );
				if( searchIndexByIncludeIdx != indexByIncludeIdx->end() ) {
					std::map<cfsec::CFSecTSecGrpIncPKey, cfsec::ICFSecTSecGrpIncObj*>* mapIncludeIdx = searchIndexByIncludeIdx->second;
					if( mapIncludeIdx != NULL ) {
						mapIncludeIdx->insert( std::map< cfsec::CFSecTSecGrpIncPKey, cfsec::ICFSecTSecGrpIncObj* >::value_type( *(keepObj->getPKey()), aIncludeIdxObj ) );
					}
				}
			}

			if( indexByUIncludeIdx != NULL ) {
				static const std::string S_AUIncludeIdxObj( "aUIncludeIdxObj" );
				cfsec::ICFSecTSecGrpIncObj* aUIncludeIdxObj =
					dynamic_cast<cfsec::ICFSecTSecGrpIncObj*>( keepObj );
				if( aUIncludeIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AUIncludeIdxObj );
				}
				cfsec::CFSecTSecGrpIncByUIncludeIdxKey keyUIncludeIdx;
				keyUIncludeIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				keyUIncludeIdx.setRequiredTSecGroupId( keepObj->getRequiredTSecGroupId() );
				keyUIncludeIdx.setRequiredIncludeGroupId( keepObj->getRequiredIncludeGroupId() );
				indexByUIncludeIdx->insert( std::map< cfsec::CFSecTSecGrpIncByUIncludeIdxKey, cfsec::ICFSecTSecGrpIncObj* >::value_type( keyUIncludeIdx, aUIncludeIdxObj ) );
			}

			if( allTSecGrpInc != NULL ) {
				allTSecGrpInc->insert( std::map< cfsec::CFSecTSecGrpIncPKey, cfsec::ICFSecTSecGrpIncObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			}
		}
		else {
			keepObj = obj;
			keepObj->setIsNew( false );
			pkey = keepObj->getPKey();
			// Attach new object to PKey, all, alternate, and duplicate indexes
			members->insert( std::map< cfsec::CFSecTSecGrpIncPKey, cfsec::ICFSecTSecGrpIncObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			// Attach new object to alternate and duplicate indexes -- PKey stay stable

			if( indexByTenantIdx != NULL ) {
				static const std::string S_ATenantIdxObj( "aTenantIdxObj" );
				cfsec::ICFSecTSecGrpIncObj* aTenantIdxObj =
					dynamic_cast<cfsec::ICFSecTSecGrpIncObj*>( keepObj );
				if( aTenantIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ATenantIdxObj );
				}
				cfsec::CFSecTSecGrpIncByTenantIdxKey keyTenantIdx;
				keyTenantIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				auto searchIndexByTenantIdx = indexByTenantIdx->find( keyTenantIdx );
				if( searchIndexByTenantIdx != indexByTenantIdx->end() ) {
					std::map<cfsec::CFSecTSecGrpIncPKey, cfsec::ICFSecTSecGrpIncObj*>* mapTenantIdx = searchIndexByTenantIdx->second;
					if( mapTenantIdx != NULL ) {
						mapTenantIdx->insert( std::map< cfsec::CFSecTSecGrpIncPKey, cfsec::ICFSecTSecGrpIncObj* >::value_type( *(keepObj->getPKey()), aTenantIdxObj ) );
					}
				}
			}

			if( indexByGroupIdx != NULL ) {
				static const std::string S_AGroupIdxObj( "aGroupIdxObj" );
				cfsec::ICFSecTSecGrpIncObj* aGroupIdxObj =
					dynamic_cast<cfsec::ICFSecTSecGrpIncObj*>( keepObj );
				if( aGroupIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AGroupIdxObj );
				}
				cfsec::CFSecTSecGrpIncByGroupIdxKey keyGroupIdx;
				keyGroupIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				keyGroupIdx.setRequiredTSecGroupId( keepObj->getRequiredTSecGroupId() );
				auto searchIndexByGroupIdx = indexByGroupIdx->find( keyGroupIdx );
				if( searchIndexByGroupIdx != indexByGroupIdx->end() ) {
					std::map<cfsec::CFSecTSecGrpIncPKey, cfsec::ICFSecTSecGrpIncObj*>* mapGroupIdx = searchIndexByGroupIdx->second;
					if( mapGroupIdx != NULL ) {
						mapGroupIdx->insert( std::map< cfsec::CFSecTSecGrpIncPKey, cfsec::ICFSecTSecGrpIncObj* >::value_type( *(keepObj->getPKey()), aGroupIdxObj ) );
					}
				}
			}

			if( indexByIncludeIdx != NULL ) {
				static const std::string S_AIncludeIdxObj( "aIncludeIdxObj" );
				cfsec::ICFSecTSecGrpIncObj* aIncludeIdxObj =
					dynamic_cast<cfsec::ICFSecTSecGrpIncObj*>( keepObj );
				if( aIncludeIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AIncludeIdxObj );
				}
				cfsec::CFSecTSecGrpIncByIncludeIdxKey keyIncludeIdx;
				keyIncludeIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				keyIncludeIdx.setRequiredIncludeGroupId( keepObj->getRequiredIncludeGroupId() );
				auto searchIndexByIncludeIdx = indexByIncludeIdx->find( keyIncludeIdx );
				if( searchIndexByIncludeIdx != indexByIncludeIdx->end() ) {
					std::map<cfsec::CFSecTSecGrpIncPKey, cfsec::ICFSecTSecGrpIncObj*>* mapIncludeIdx = searchIndexByIncludeIdx->second;
					if( mapIncludeIdx != NULL ) {
						mapIncludeIdx->insert( std::map< cfsec::CFSecTSecGrpIncPKey, cfsec::ICFSecTSecGrpIncObj* >::value_type( *(keepObj->getPKey()), aIncludeIdxObj ) );
					}
				}
			}

			if( indexByUIncludeIdx != NULL ) {
				static const std::string S_AUIncludeIdxObj( "aUIncludeIdxObj" );
				cfsec::ICFSecTSecGrpIncObj* aUIncludeIdxObj =
					dynamic_cast<cfsec::ICFSecTSecGrpIncObj*>( keepObj );
				if( aUIncludeIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AUIncludeIdxObj );
				}
				cfsec::CFSecTSecGrpIncByUIncludeIdxKey keyUIncludeIdx;
				keyUIncludeIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				keyUIncludeIdx.setRequiredTSecGroupId( keepObj->getRequiredTSecGroupId() );
				keyUIncludeIdx.setRequiredIncludeGroupId( keepObj->getRequiredIncludeGroupId() );
				indexByUIncludeIdx->insert( std::map< cfsec::CFSecTSecGrpIncByUIncludeIdxKey, cfsec::ICFSecTSecGrpIncObj* >::value_type( keyUIncludeIdx, aUIncludeIdxObj ) );
			}

			if( allTSecGrpInc != NULL ) {
				allTSecGrpInc->insert( std::map< cfsec::CFSecTSecGrpIncPKey, cfsec::ICFSecTSecGrpIncObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
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

	void CFSecTSecGrpIncTableObj::deepDisposeByIdIdx( const int64_t TenantId,
			const int64_t TSecGrpIncId ) {
		static const std::string S_ProcName( "deepDisposeByIdIdx" );
		std::vector<cfsec::ICFSecTSecGrpIncObj*> list;
		cfsec::ICFSecTSecGrpIncObj* existingObj = readCachedTSecGrpIncByIdIdx( TenantId,
				TSecGrpIncId );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfsec::ICFSecTSecGrpIncObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecTSecGrpIncBuff::CLASS_CODE ) {
					dynamic_cast<cfsec::CFSecTSecGrpIncTableObj*>( schema->getTSecGrpIncTableObj() )->reallyDeepDisposeTSecGrpInc( dynamic_cast<cfsec::ICFSecTSecGrpIncObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFSecTSecGrpIncTableObj::deepDisposeByTenantIdx( const int64_t TenantId ) {
		static const std::string S_ProcName( "deepDisposeByTenantIdx" );
		std::vector<cfsec::ICFSecTSecGrpIncObj*> list;
		std::vector<cfsec::ICFSecTSecGrpIncObj*> matchesFound = readCachedTSecGrpIncByTenantIdx( TenantId );
		auto iterMatches = matchesFound.begin();
		auto endMatches = matchesFound.end();
		while( iterMatches != endMatches ) {
			if( *iterMatches != NULL ) {
				list.push_back( *iterMatches );
			}
			iterMatches ++;
		}
		cfsec::ICFSecTSecGrpIncObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecTSecGrpIncBuff::CLASS_CODE ) {
					dynamic_cast<cfsec::CFSecTSecGrpIncTableObj*>( schema->getTSecGrpIncTableObj() )->reallyDeepDisposeTSecGrpInc( dynamic_cast<cfsec::ICFSecTSecGrpIncObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFSecTSecGrpIncTableObj::deepDisposeByGroupIdx( const int64_t TenantId,
			const int32_t TSecGroupId ) {
		static const std::string S_ProcName( "deepDisposeByGroupIdx" );
		std::vector<cfsec::ICFSecTSecGrpIncObj*> list;
		std::vector<cfsec::ICFSecTSecGrpIncObj*> matchesFound = readCachedTSecGrpIncByGroupIdx( TenantId,
				TSecGroupId );
		auto iterMatches = matchesFound.begin();
		auto endMatches = matchesFound.end();
		while( iterMatches != endMatches ) {
			if( *iterMatches != NULL ) {
				list.push_back( *iterMatches );
			}
			iterMatches ++;
		}
		cfsec::ICFSecTSecGrpIncObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecTSecGrpIncBuff::CLASS_CODE ) {
					dynamic_cast<cfsec::CFSecTSecGrpIncTableObj*>( schema->getTSecGrpIncTableObj() )->reallyDeepDisposeTSecGrpInc( dynamic_cast<cfsec::ICFSecTSecGrpIncObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFSecTSecGrpIncTableObj::deepDisposeByIncludeIdx( const int64_t TenantId,
			const int32_t IncludeGroupId ) {
		static const std::string S_ProcName( "deepDisposeByIncludeIdx" );
		std::vector<cfsec::ICFSecTSecGrpIncObj*> list;
		std::vector<cfsec::ICFSecTSecGrpIncObj*> matchesFound = readCachedTSecGrpIncByIncludeIdx( TenantId,
				IncludeGroupId );
		auto iterMatches = matchesFound.begin();
		auto endMatches = matchesFound.end();
		while( iterMatches != endMatches ) {
			if( *iterMatches != NULL ) {
				list.push_back( *iterMatches );
			}
			iterMatches ++;
		}
		cfsec::ICFSecTSecGrpIncObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecTSecGrpIncBuff::CLASS_CODE ) {
					dynamic_cast<cfsec::CFSecTSecGrpIncTableObj*>( schema->getTSecGrpIncTableObj() )->reallyDeepDisposeTSecGrpInc( dynamic_cast<cfsec::ICFSecTSecGrpIncObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFSecTSecGrpIncTableObj::deepDisposeByUIncludeIdx( const int64_t TenantId,
			const int32_t TSecGroupId,
			const int32_t IncludeGroupId ) {
		static const std::string S_ProcName( "deepDisposeByUIncludeIdx" );
		std::vector<cfsec::ICFSecTSecGrpIncObj*> list;
		cfsec::ICFSecTSecGrpIncObj* existingObj = readCachedTSecGrpIncByUIncludeIdx( TenantId,
				TSecGroupId,
				IncludeGroupId );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfsec::ICFSecTSecGrpIncObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecTSecGrpIncBuff::CLASS_CODE ) {
					dynamic_cast<cfsec::CFSecTSecGrpIncTableObj*>( schema->getTSecGrpIncTableObj() )->reallyDeepDisposeTSecGrpInc( dynamic_cast<cfsec::ICFSecTSecGrpIncObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFSecTSecGrpIncTableObj::reallyDeepDisposeTSecGrpInc( cfsec::ICFSecTSecGrpIncObj* Obj ) {
		static const std::string S_ProcName( "reallyDeepDisposeTSecGrpInc" );

		if( Obj == NULL ) {
			return;
		}

		cfsec::ICFSecTSecGrpIncObj* obj = Obj;
		
		classcode_t classCode = obj->getClassCode();
		if( classCode == cfsec::CFSecTSecGrpIncBuff::CLASS_CODE ) {
			dynamic_cast<cfsec::CFSecTSecGrpIncTableObj*>( schema->getTSecGrpIncTableObj() )->reallyDetachFromIndexesTSecGrpInc( dynamic_cast<cfsec::ICFSecTSecGrpIncObj*>( obj ) );
		}

		if( obj->getEdit() != NULL ) {
			obj->endEdit();
		}
		delete obj;
		obj = NULL;
	}

	cfsec::ICFSecTSecGrpIncObj* CFSecTSecGrpIncTableObj::createTSecGrpInc( cfsec::ICFSecTSecGrpIncEditObj* Obj ) {
		static const std::string S_ProcName( "createTSecGrpInc" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Cloneable( "cloneable" );
		static const std::string S_ClonedBuff( "clonedbuff" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecTSecGrpIncObj* obj = dynamic_cast<cfsec::ICFSecTSecGrpIncObj*>( Obj->getOrig() );
		try {
			cfsec::CFSecTSecGrpIncBuff* buff = dynamic_cast<cfsec::CFSecTSecGrpIncBuff*>( Obj->getBuff()->clone() );
			// C++18 version of create returns a new buffer instance and takes over ownership of the passed-in buffer
			// MSS TODO WORKING The xmsg client will need to return the buffer instance created by processing
			// the response message, while xmsg rqst will have to delete the backing store instance
			// it receives after preparing the reply message so that memory doesn't leak on every request.
			cflib::ICFLibCloneableObj* cloneable = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableTSecGrpInc()->createTSecGrpInc(
				schema->getAuthorization(),
				buff );
			if( cloneable == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Cloneable );
			}
			Obj->endEdit();
			obj->setBuff( dynamic_cast<cfsec::CFSecTSecGrpIncBuff*>( cloneable ) );
			obj = dynamic_cast<cfsec::ICFSecTSecGrpIncObj*>( obj->realize() );
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

	cfsec::ICFSecTSecGrpIncObj* CFSecTSecGrpIncTableObj::readTSecGrpInc( cfsec::CFSecTSecGrpIncPKey* pkey, bool forceRead ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readTSecGrpInc" );
		cfsec::ICFSecTSecGrpIncObj* obj = NULL;
		cfsec::ICFSecTSecGrpIncObj* realized = NULL;
		if( ! forceRead ) {
			auto searchMembers = members->find( *pkey );
			if( searchMembers != members->end() ) {
				// obj could be NULL if cache misses is enabled
				obj = searchMembers->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecTSecGrpIncBuff* readBuff = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableTSecGrpInc()->readDerivedByIdIdx( schema->getAuthorization(),
			pkey->getRequiredTenantId(),
			pkey->getRequiredTSecGrpIncId() );
			if( readBuff != NULL ) {
			obj = dynamic_cast<cfsec::CFSecTSecGrpIncTableObj*>( schema->getTSecGrpIncTableObj() )->newInstance();
				obj->setBuff( readBuff );
				realized = dynamic_cast<cfsec::ICFSecTSecGrpIncObj*>( obj->realize() );
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

	cfsec::ICFSecTSecGrpIncObj* CFSecTSecGrpIncTableObj::lockTSecGrpInc( cfsec::CFSecTSecGrpIncPKey* pkey ) {
		static const std::string S_ProcName( "lockTSecGrpInc" );
		cfsec::ICFSecTSecGrpIncObj* locked = NULL;
		cfsec::CFSecTSecGrpIncBuff* lockBuff = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableTSecGrpInc()->lockDerived( schema->getAuthorization(), pkey );
		if( lockBuff != NULL ) {
			locked = dynamic_cast<cfsec::CFSecTSecGrpIncTableObj*>( schema->getTSecGrpIncTableObj() )->newInstance();
			locked->setBuff( lockBuff );
			locked = dynamic_cast<cfsec::ICFSecTSecGrpIncObj*>( locked->realize() );
		}
		else {
			return( NULL );
		}
		return( locked );
	}

	std::vector<cfsec::ICFSecTSecGrpIncObj*> CFSecTSecGrpIncTableObj::readAllTSecGrpInc( bool forceRead ) {
		static const std::string S_ProcName( "readAllTSecGrpInc" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Realized( "realized" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecTSecGrpIncObj* realized = NULL;
		if( forceRead || ( allTSecGrpInc == NULL ) ) {
			std::map<cfsec::CFSecTSecGrpIncPKey, cfsec::ICFSecTSecGrpIncObj*>* map = new std::map<cfsec::CFSecTSecGrpIncPKey,cfsec::ICFSecTSecGrpIncObj*>();
			allTSecGrpInc = map;
			std::TCFLibOwningVector<cfsec::CFSecTSecGrpIncBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableTSecGrpInc()->readAllDerived( schema->getAuthorization() );
			cfsec::CFSecTSecGrpIncBuff* buff = NULL;
			cfsec::ICFSecTSecGrpIncObj* obj = NULL;
			try {
				for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
					buff = buffList[ idx ];
					buffList[ idx ] = NULL;
				obj = newInstance();
					obj->setBuff( buff );
					realized = dynamic_cast<cfsec::ICFSecTSecGrpIncObj*>( obj->realize() );
					if( realized == NULL ) {
						throw cflib::CFLibNullArgumentException( CLASS_NAME,
							S_ProcName,
							0,
							S_Realized );
					}
					allTSecGrpInc->insert( std::map< cfsec::CFSecTSecGrpIncPKey, cfsec::ICFSecTSecGrpIncObj* >::value_type( *(realized->getPKey()), realized ) );
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
		size_t len = allTSecGrpInc->size();
		std::vector<cfsec::ICFSecTSecGrpIncObj*> arr;
		auto valIter = allTSecGrpInc->begin();
		size_t idx = 0;
		while( valIter != allTSecGrpInc->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	std::vector<cfsec::ICFSecTSecGrpIncObj*> CFSecTSecGrpIncTableObj::pageAllTSecGrpInc(const int64_t* priorTenantId,
			const int64_t* priorTSecGrpIncId )
	{
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "pageAllTSecGrpInc" );
		CFLIB_EXCEPTION_DECLINFO
		std::map<cfsec::CFSecTSecGrpIncPKey, cfsec::ICFSecTSecGrpIncObj*>* map = NULL;
		cfsec::CFSecTSecGrpIncBuff* buff = NULL;
		cfsec::ICFSecTSecGrpIncObj* obj = NULL;
		cfsec::ICFSecTSecGrpIncObj* realized = NULL;
		std::vector<cfsec::ICFSecTSecGrpIncObj*> arrayList;
		try {
			map = new std::map<cfsec::CFSecTSecGrpIncPKey,cfsec::ICFSecTSecGrpIncObj*>();
			std::TCFLibOwningVector<cfsec::CFSecTSecGrpIncBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableTSecGrpInc()->pageAllBuff( schema->getAuthorization(),
				priorTenantId,
				priorTSecGrpIncId );
			arrayList.reserve( buffList.size() );
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = newInstance();
				obj->setBuff( buff );
				realized = dynamic_cast<cfsec::ICFSecTSecGrpIncObj*>( obj->realize() );
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

	cfsec::ICFSecTSecGrpIncObj* CFSecTSecGrpIncTableObj::readTSecGrpIncByIdIdx( const int64_t TenantId,
			const int64_t TSecGrpIncId, bool forceRead )
	{
		static const std::string S_ProcName( "readTSecGrpIncByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecTSecGrpIncPKey pkey;
		pkey.setRequiredTenantId( TenantId );
		pkey.setRequiredTSecGrpIncId( TSecGrpIncId );
		cfsec::ICFSecTSecGrpIncObj* obj = readTSecGrpInc( &pkey, forceRead );
		return( obj );
	}

	std::vector<cfsec::ICFSecTSecGrpIncObj*> CFSecTSecGrpIncTableObj::readTSecGrpIncByTenantIdx( const int64_t TenantId,
		bool forceRead )
	{
		static const std::string S_ProcName( "readTSecGrpIncByTenantIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecTSecGrpIncByTenantIdxKey key;
		key.setRequiredTenantId( TenantId );
		std::map<cfsec::CFSecTSecGrpIncPKey, cfsec::ICFSecTSecGrpIncObj*>* dict;
		std::map<cfsec::CFSecTSecGrpIncPKey, cfsec::ICFSecTSecGrpIncObj*>* oldDict;
		if( indexByTenantIdx == NULL ) {
			indexByTenantIdx = new std::map< cfsec::CFSecTSecGrpIncByTenantIdxKey,
				std::map< cfsec::CFSecTSecGrpIncPKey, cfsec::ICFSecTSecGrpIncObj*>*>();
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
			dict = new std::map<cfsec::CFSecTSecGrpIncPKey, cfsec::ICFSecTSecGrpIncObj*>();
			cfsec::ICFSecTSecGrpIncObj* obj;
			std::TCFLibOwningVector<cfsec::CFSecTSecGrpIncBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableTSecGrpInc()->readDerivedByTenantIdx( schema->getAuthorization(),
				TenantId );
			cfsec::CFSecTSecGrpIncBuff* buff;
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = dynamic_cast<cfsec::CFSecTSecGrpIncTableObj*>( schema->getTSecGrpIncTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
				obj->setBuff( buff );
				cfsec::ICFSecTSecGrpIncObj* realized = dynamic_cast<cfsec::ICFSecTSecGrpIncObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				dict->insert( std::map< cfsec::CFSecTSecGrpIncPKey, cfsec::ICFSecTSecGrpIncObj* >::value_type( *(realized->getPKey()), realized ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = NULL;
			}
			if( oldDict != NULL ) {
				indexByTenantIdx->erase( searchIndexByTenantIdx );
				delete oldDict;
				oldDict = NULL;
			}
			indexByTenantIdx->insert( std::map< cfsec::CFSecTSecGrpIncByTenantIdxKey,
				std::map< cfsec::CFSecTSecGrpIncPKey, cfsec::ICFSecTSecGrpIncObj* >* >::value_type( key, dict ) );
		}
		size_t len = dict->size();
		std::vector<cfsec::ICFSecTSecGrpIncObj*> arr;
		arr.reserve( len );
		auto valIter = dict->begin();
		while( valIter != dict->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	std::vector<cfsec::ICFSecTSecGrpIncObj*> CFSecTSecGrpIncTableObj::readTSecGrpIncByGroupIdx( const int64_t TenantId,
			const int32_t TSecGroupId,
		bool forceRead )
	{
		static const std::string S_ProcName( "readTSecGrpIncByGroupIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecTSecGrpIncByGroupIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredTSecGroupId( TSecGroupId );
		std::map<cfsec::CFSecTSecGrpIncPKey, cfsec::ICFSecTSecGrpIncObj*>* dict;
		std::map<cfsec::CFSecTSecGrpIncPKey, cfsec::ICFSecTSecGrpIncObj*>* oldDict;
		if( indexByGroupIdx == NULL ) {
			indexByGroupIdx = new std::map< cfsec::CFSecTSecGrpIncByGroupIdxKey,
				std::map< cfsec::CFSecTSecGrpIncPKey, cfsec::ICFSecTSecGrpIncObj*>*>();
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
			dict = new std::map<cfsec::CFSecTSecGrpIncPKey, cfsec::ICFSecTSecGrpIncObj*>();
			cfsec::ICFSecTSecGrpIncObj* obj;
			std::TCFLibOwningVector<cfsec::CFSecTSecGrpIncBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableTSecGrpInc()->readDerivedByGroupIdx( schema->getAuthorization(),
				TenantId,
				TSecGroupId );
			cfsec::CFSecTSecGrpIncBuff* buff;
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = dynamic_cast<cfsec::CFSecTSecGrpIncTableObj*>( schema->getTSecGrpIncTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
				obj->setBuff( buff );
				cfsec::ICFSecTSecGrpIncObj* realized = dynamic_cast<cfsec::ICFSecTSecGrpIncObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				dict->insert( std::map< cfsec::CFSecTSecGrpIncPKey, cfsec::ICFSecTSecGrpIncObj* >::value_type( *(realized->getPKey()), realized ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = NULL;
			}
			if( oldDict != NULL ) {
				indexByGroupIdx->erase( searchIndexByGroupIdx );
				delete oldDict;
				oldDict = NULL;
			}
			indexByGroupIdx->insert( std::map< cfsec::CFSecTSecGrpIncByGroupIdxKey,
				std::map< cfsec::CFSecTSecGrpIncPKey, cfsec::ICFSecTSecGrpIncObj* >* >::value_type( key, dict ) );
		}
		size_t len = dict->size();
		std::vector<cfsec::ICFSecTSecGrpIncObj*> arr;
		arr.reserve( len );
		auto valIter = dict->begin();
		while( valIter != dict->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	std::vector<cfsec::ICFSecTSecGrpIncObj*> CFSecTSecGrpIncTableObj::readTSecGrpIncByIncludeIdx( const int64_t TenantId,
			const int32_t IncludeGroupId,
		bool forceRead )
	{
		static const std::string S_ProcName( "readTSecGrpIncByIncludeIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecTSecGrpIncByIncludeIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredIncludeGroupId( IncludeGroupId );
		std::map<cfsec::CFSecTSecGrpIncPKey, cfsec::ICFSecTSecGrpIncObj*>* dict;
		std::map<cfsec::CFSecTSecGrpIncPKey, cfsec::ICFSecTSecGrpIncObj*>* oldDict;
		if( indexByIncludeIdx == NULL ) {
			indexByIncludeIdx = new std::map< cfsec::CFSecTSecGrpIncByIncludeIdxKey,
				std::map< cfsec::CFSecTSecGrpIncPKey, cfsec::ICFSecTSecGrpIncObj*>*>();
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
			dict = new std::map<cfsec::CFSecTSecGrpIncPKey, cfsec::ICFSecTSecGrpIncObj*>();
			cfsec::ICFSecTSecGrpIncObj* obj;
			std::TCFLibOwningVector<cfsec::CFSecTSecGrpIncBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableTSecGrpInc()->readDerivedByIncludeIdx( schema->getAuthorization(),
				TenantId,
				IncludeGroupId );
			cfsec::CFSecTSecGrpIncBuff* buff;
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = dynamic_cast<cfsec::CFSecTSecGrpIncTableObj*>( schema->getTSecGrpIncTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
				obj->setBuff( buff );
				cfsec::ICFSecTSecGrpIncObj* realized = dynamic_cast<cfsec::ICFSecTSecGrpIncObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				dict->insert( std::map< cfsec::CFSecTSecGrpIncPKey, cfsec::ICFSecTSecGrpIncObj* >::value_type( *(realized->getPKey()), realized ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = NULL;
			}
			if( oldDict != NULL ) {
				indexByIncludeIdx->erase( searchIndexByIncludeIdx );
				delete oldDict;
				oldDict = NULL;
			}
			indexByIncludeIdx->insert( std::map< cfsec::CFSecTSecGrpIncByIncludeIdxKey,
				std::map< cfsec::CFSecTSecGrpIncPKey, cfsec::ICFSecTSecGrpIncObj* >* >::value_type( key, dict ) );
		}
		size_t len = dict->size();
		std::vector<cfsec::ICFSecTSecGrpIncObj*> arr;
		arr.reserve( len );
		auto valIter = dict->begin();
		while( valIter != dict->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	cfsec::ICFSecTSecGrpIncObj* CFSecTSecGrpIncTableObj::readTSecGrpIncByUIncludeIdx( const int64_t TenantId,
			const int32_t TSecGroupId,
			const int32_t IncludeGroupId, bool forceRead )
	{
		static const std::string S_ProcName( "readTSecGrpIncByUIncludeIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByUIncludeIdx == NULL ) {
			indexByUIncludeIdx = new std::map< cfsec::CFSecTSecGrpIncByUIncludeIdxKey,
				cfsec::ICFSecTSecGrpIncObj*>();
		}
		cfsec::CFSecTSecGrpIncByUIncludeIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredTSecGroupId( TSecGroupId );
		key.setRequiredIncludeGroupId( IncludeGroupId );
		cfsec::ICFSecTSecGrpIncObj* obj = NULL;
		cfsec::ICFSecTSecGrpIncObj* realized = NULL;
		if( ! forceRead ) {
			auto searchIndexByUIncludeIdx = indexByUIncludeIdx->find( key );
			if( searchIndexByUIncludeIdx != indexByUIncludeIdx->end() ) {
				// Note: obj may be null if cache misses is enabled
				obj = searchIndexByUIncludeIdx->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecTSecGrpIncBuff* buff = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableTSecGrpInc()->readDerivedByUIncludeIdx( schema->getAuthorization(),
				TenantId,
				TSecGroupId,
				IncludeGroupId );
			if( buff != NULL ) {
				obj = dynamic_cast<cfsec::CFSecTSecGrpIncTableObj*>( schema->getTSecGrpIncTableObj() )->newInstance();
				obj->setBuff( buff );
				realized = dynamic_cast<cfsec::ICFSecTSecGrpIncObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				indexByUIncludeIdx->insert( std::map< cfsec::CFSecTSecGrpIncByUIncludeIdxKey, cfsec::ICFSecTSecGrpIncObj*>::value_type( key, dynamic_cast<cfsec::ICFSecTSecGrpIncObj*>( realized ) ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = realized;
			}
		}
		return( obj );
	}

	cfsec::ICFSecTSecGrpIncObj* CFSecTSecGrpIncTableObj::readCachedTSecGrpInc( cfsec::CFSecTSecGrpIncPKey* pkey ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readTSecGrpInc" );
		cfsec::ICFSecTSecGrpIncObj* obj = NULL;
		cfsec::ICFSecTSecGrpIncObj* realized = NULL;
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			// obj could be NULL if cache misses is enabled
			obj = searchMembers->second;
			realized = obj;
		}
		return( realized );
	}

	cfsec::ICFSecTSecGrpIncObj* CFSecTSecGrpIncTableObj::readCachedTSecGrpIncByIdIdx( const int64_t TenantId,
			const int64_t TSecGrpIncId )
	{
		static const std::string S_ProcName( "readCachedTSecGrpIncByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecTSecGrpIncPKey pkey;
		pkey.setRequiredTenantId( TenantId );
		pkey.setRequiredTSecGrpIncId( TSecGrpIncId );
		cfsec::ICFSecTSecGrpIncObj* obj = readCachedTSecGrpInc( &pkey );
		return( obj );
	}

	std::vector<cfsec::ICFSecTSecGrpIncObj*> CFSecTSecGrpIncTableObj::readCachedTSecGrpIncByTenantIdx( const int64_t TenantId )
	{
		static const std::string S_ProcName( "readCachedTSecGrpIncByTenantIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		std::vector<cfsec::ICFSecTSecGrpIncObj*> arr;
		cfsec::CFSecTSecGrpIncByTenantIdxKey key;
		key.setRequiredTenantId( TenantId );
		std::map<cfsec::CFSecTSecGrpIncPKey, cfsec::ICFSecTSecGrpIncObj*>* dict;
		if( indexByTenantIdx == NULL ) {
			return( arr );
		}
		auto searchIndexByTenantIdx = indexByTenantIdx->find( key );
		if( searchIndexByTenantIdx != indexByTenantIdx->end() ) {
			dict = searchIndexByTenantIdx->second;
			size_t len = dict->size();
			std::vector<cfsec::ICFSecTSecGrpIncObj*> arr;
			arr.reserve( len );
			auto valIter = dict->begin();
			while( valIter != dict->end() ) {
				arr.push_back( valIter->second );
				valIter ++;
			}
		}
		else {
			cfsec::ICFSecTSecGrpIncObj* obj;
			for( auto iterMembers = members->begin(); iterMembers != members->end(); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecTSecGrpIncBuff*>( obj->getBuff() ) ) == key ) {
						arr.push_back( obj );
					}
				}
			}
		}
		return( arr );
	}

	std::vector<cfsec::ICFSecTSecGrpIncObj*> CFSecTSecGrpIncTableObj::readCachedTSecGrpIncByGroupIdx( const int64_t TenantId,
			const int32_t TSecGroupId )
	{
		static const std::string S_ProcName( "readCachedTSecGrpIncByGroupIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		std::vector<cfsec::ICFSecTSecGrpIncObj*> arr;
		cfsec::CFSecTSecGrpIncByGroupIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredTSecGroupId( TSecGroupId );
		std::map<cfsec::CFSecTSecGrpIncPKey, cfsec::ICFSecTSecGrpIncObj*>* dict;
		if( indexByGroupIdx == NULL ) {
			return( arr );
		}
		auto searchIndexByGroupIdx = indexByGroupIdx->find( key );
		if( searchIndexByGroupIdx != indexByGroupIdx->end() ) {
			dict = searchIndexByGroupIdx->second;
			size_t len = dict->size();
			std::vector<cfsec::ICFSecTSecGrpIncObj*> arr;
			arr.reserve( len );
			auto valIter = dict->begin();
			while( valIter != dict->end() ) {
				arr.push_back( valIter->second );
				valIter ++;
			}
		}
		else {
			cfsec::ICFSecTSecGrpIncObj* obj;
			for( auto iterMembers = members->begin(); iterMembers != members->end(); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecTSecGrpIncBuff*>( obj->getBuff() ) ) == key ) {
						arr.push_back( obj );
					}
				}
			}
		}
		return( arr );
	}

	std::vector<cfsec::ICFSecTSecGrpIncObj*> CFSecTSecGrpIncTableObj::readCachedTSecGrpIncByIncludeIdx( const int64_t TenantId,
			const int32_t IncludeGroupId )
	{
		static const std::string S_ProcName( "readCachedTSecGrpIncByIncludeIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		std::vector<cfsec::ICFSecTSecGrpIncObj*> arr;
		cfsec::CFSecTSecGrpIncByIncludeIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredIncludeGroupId( IncludeGroupId );
		std::map<cfsec::CFSecTSecGrpIncPKey, cfsec::ICFSecTSecGrpIncObj*>* dict;
		if( indexByIncludeIdx == NULL ) {
			return( arr );
		}
		auto searchIndexByIncludeIdx = indexByIncludeIdx->find( key );
		if( searchIndexByIncludeIdx != indexByIncludeIdx->end() ) {
			dict = searchIndexByIncludeIdx->second;
			size_t len = dict->size();
			std::vector<cfsec::ICFSecTSecGrpIncObj*> arr;
			arr.reserve( len );
			auto valIter = dict->begin();
			while( valIter != dict->end() ) {
				arr.push_back( valIter->second );
				valIter ++;
			}
		}
		else {
			cfsec::ICFSecTSecGrpIncObj* obj;
			for( auto iterMembers = members->begin(); iterMembers != members->end(); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecTSecGrpIncBuff*>( obj->getBuff() ) ) == key ) {
						arr.push_back( obj );
					}
				}
			}
		}
		return( arr );
	}

	cfsec::ICFSecTSecGrpIncObj* CFSecTSecGrpIncTableObj::readCachedTSecGrpIncByUIncludeIdx( const int64_t TenantId,
			const int32_t TSecGroupId,
			const int32_t IncludeGroupId )
	{
		static const std::string S_ProcName( "readCachedTSecGrpIncByUIncludeIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByUIncludeIdx == NULL ) {
			indexByUIncludeIdx = new std::map< cfsec::CFSecTSecGrpIncByUIncludeIdxKey,
				cfsec::ICFSecTSecGrpIncObj*>();
		}
		cfsec::CFSecTSecGrpIncByUIncludeIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredTSecGroupId( TSecGroupId );
		key.setRequiredIncludeGroupId( IncludeGroupId );
		cfsec::ICFSecTSecGrpIncObj* obj = NULL;
		auto searchIndexByUIncludeIdx = indexByUIncludeIdx->find( key );
		if( searchIndexByUIncludeIdx != indexByUIncludeIdx->end() ) {
			// Note: obj may be null if cache misses is enabled
			obj = searchIndexByUIncludeIdx->second;
		}
		else {
			for( auto iterMembers = members->begin(); ( obj == NULL ) && ( iterMembers != members->end() ); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecTSecGrpIncBuff*>( obj->getBuff() ) ) != key ) {
						obj = NULL;
					}
				}
			}
		}
		return( obj );
	}

	std::vector<cfsec::ICFSecTSecGrpIncObj*> CFSecTSecGrpIncTableObj::pageTSecGrpIncByTenantIdx( const int64_t TenantId,
			const int64_t* priorTenantId,
			const int64_t* priorTSecGrpIncId )
	{
		static const std::string S_ProcName( "pageTSecGrpIncByTenantIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecTSecGrpIncByTenantIdxKey key;
		key.setRequiredTenantId( TenantId );
		cfsec::ICFSecTSecGrpIncObj* obj;
		std::TCFLibOwningVector<cfsec::CFSecTSecGrpIncBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableTSecGrpInc()->pageBuffByTenantIdx( schema->getAuthorization(),
				TenantId,
				priorTenantId,
				priorTSecGrpIncId );
		std::vector<cfsec::ICFSecTSecGrpIncObj*> retList;
		retList.reserve( buffList.size() );
		cfsec::CFSecTSecGrpIncBuff* buff;
		cfsec::ICFSecTSecGrpIncObj* realized;
		for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
			buff = buffList[ idx ];
			buffList[ idx ] = NULL;
				obj = dynamic_cast<cfsec::CFSecTSecGrpIncTableObj*>( schema->getTSecGrpIncTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
			obj->setBuff( buff );
			realized = dynamic_cast<cfsec::ICFSecTSecGrpIncObj*>( obj->realize() );
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

	std::vector<cfsec::ICFSecTSecGrpIncObj*> CFSecTSecGrpIncTableObj::pageTSecGrpIncByGroupIdx( const int64_t TenantId,
			const int32_t TSecGroupId,
			const int64_t* priorTenantId,
			const int64_t* priorTSecGrpIncId )
	{
		static const std::string S_ProcName( "pageTSecGrpIncByGroupIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecTSecGrpIncByGroupIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredTSecGroupId( TSecGroupId );
		cfsec::ICFSecTSecGrpIncObj* obj;
		std::TCFLibOwningVector<cfsec::CFSecTSecGrpIncBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableTSecGrpInc()->pageBuffByGroupIdx( schema->getAuthorization(),
				TenantId,
				TSecGroupId,
				priorTenantId,
				priorTSecGrpIncId );
		std::vector<cfsec::ICFSecTSecGrpIncObj*> retList;
		retList.reserve( buffList.size() );
		cfsec::CFSecTSecGrpIncBuff* buff;
		cfsec::ICFSecTSecGrpIncObj* realized;
		for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
			buff = buffList[ idx ];
			buffList[ idx ] = NULL;
				obj = dynamic_cast<cfsec::CFSecTSecGrpIncTableObj*>( schema->getTSecGrpIncTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
			obj->setBuff( buff );
			realized = dynamic_cast<cfsec::ICFSecTSecGrpIncObj*>( obj->realize() );
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

	std::vector<cfsec::ICFSecTSecGrpIncObj*> CFSecTSecGrpIncTableObj::pageTSecGrpIncByIncludeIdx( const int64_t TenantId,
			const int32_t IncludeGroupId,
			const int64_t* priorTenantId,
			const int64_t* priorTSecGrpIncId )
	{
		static const std::string S_ProcName( "pageTSecGrpIncByIncludeIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecTSecGrpIncByIncludeIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredIncludeGroupId( IncludeGroupId );
		cfsec::ICFSecTSecGrpIncObj* obj;
		std::TCFLibOwningVector<cfsec::CFSecTSecGrpIncBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableTSecGrpInc()->pageBuffByIncludeIdx( schema->getAuthorization(),
				TenantId,
				IncludeGroupId,
				priorTenantId,
				priorTSecGrpIncId );
		std::vector<cfsec::ICFSecTSecGrpIncObj*> retList;
		retList.reserve( buffList.size() );
		cfsec::CFSecTSecGrpIncBuff* buff;
		cfsec::ICFSecTSecGrpIncObj* realized;
		for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
			buff = buffList[ idx ];
			buffList[ idx ] = NULL;
				obj = dynamic_cast<cfsec::CFSecTSecGrpIncTableObj*>( schema->getTSecGrpIncTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
			obj->setBuff( buff );
			realized = dynamic_cast<cfsec::ICFSecTSecGrpIncObj*>( obj->realize() );
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

	cfsec::ICFSecTSecGrpIncObj* CFSecTSecGrpIncTableObj::updateTSecGrpInc( cfsec::ICFSecTSecGrpIncEditObj* Obj ) {
		static const std::string S_ProcName( "updateTSecGrpInc" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Updated( "updated" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecTSecGrpIncObj* obj = dynamic_cast<cfsec::ICFSecTSecGrpIncObj*>( Obj->getOrig() );
		try {
			cfsec::CFSecTSecGrpIncBuff* updated = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableTSecGrpInc()->updateTSecGrpInc( schema->getAuthorization(),
				dynamic_cast<cfsec::CFSecTSecGrpIncBuff*>( Obj->getTSecGrpIncBuff()->clone() ) );
			if( updated == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Updated );
			}
			obj = dynamic_cast<cfsec::ICFSecTSecGrpIncObj*>( dynamic_cast<cfsec::CFSecTSecGrpIncTableObj*>( schema->getTSecGrpIncTableObj() )->newInstance() );
			obj->setBuff( updated );
			obj = dynamic_cast<cfsec::ICFSecTSecGrpIncObj*>( obj->realize() );
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

	void CFSecTSecGrpIncTableObj::deleteTSecGrpInc( cfsec::ICFSecTSecGrpIncEditObj* Obj ) {
		cfsec::ICFSecTSecGrpIncObj* obj = Obj;
		dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableTSecGrpInc()->deleteTSecGrpInc( schema->getAuthorization(),
			obj->getTSecGrpIncBuff() );
		deepDisposeByIdIdx( obj->getRequiredTenantId(),
			obj->getRequiredTSecGrpIncId() );
	}

	void CFSecTSecGrpIncTableObj::deleteTSecGrpIncByIdIdx( const int64_t TenantId,
			const int64_t TSecGrpIncId )
	{
		cfsec::CFSecTSecGrpIncPKey pkey;
		pkey.setRequiredTenantId( TenantId );
		pkey.setRequiredTSecGrpIncId( TSecGrpIncId );
		cfsec::ICFSecTSecGrpIncObj* obj = readTSecGrpInc( &pkey, true );
		if( obj != NULL ) {
			cfsec::ICFSecTSecGrpIncEditObj* editObj = dynamic_cast<cfsec::ICFSecTSecGrpIncEditObj*>( obj->getEdit() );
			if( editObj == NULL ) {
				editObj = dynamic_cast<cfsec::ICFSecTSecGrpIncEditObj*>( obj->beginEdit() );
			}
			if( editObj != NULL ) {
				editObj->deleteInstance();
				editObj = NULL;
			}
		}
	}

	void CFSecTSecGrpIncTableObj::deleteTSecGrpIncByTenantIdx( const int64_t TenantId )
	{
		dynamic_cast<cfsec::ICFSecSchema*>( schema->getBackingStore() )->getTableTSecGrpInc()->deleteTSecGrpIncByTenantIdx( schema->getAuthorization(),
				TenantId );
		deepDisposeByTenantIdx( TenantId );
	}

	void CFSecTSecGrpIncTableObj::deleteTSecGrpIncByGroupIdx( const int64_t TenantId,
			const int32_t TSecGroupId )
	{
		dynamic_cast<cfsec::ICFSecSchema*>( schema->getBackingStore() )->getTableTSecGrpInc()->deleteTSecGrpIncByGroupIdx( schema->getAuthorization(),
				TenantId,
				TSecGroupId );
		deepDisposeByGroupIdx( TenantId,
			TSecGroupId );
	}

	void CFSecTSecGrpIncTableObj::deleteTSecGrpIncByIncludeIdx( const int64_t TenantId,
			const int32_t IncludeGroupId )
	{
		dynamic_cast<cfsec::ICFSecSchema*>( schema->getBackingStore() )->getTableTSecGrpInc()->deleteTSecGrpIncByIncludeIdx( schema->getAuthorization(),
				TenantId,
				IncludeGroupId );
		deepDisposeByIncludeIdx( TenantId,
			IncludeGroupId );
	}

	void CFSecTSecGrpIncTableObj::deleteTSecGrpIncByUIncludeIdx( const int64_t TenantId,
			const int32_t TSecGroupId,
			const int32_t IncludeGroupId )
	{
		if( indexByUIncludeIdx == NULL ) {
			indexByUIncludeIdx = new std::map< cfsec::CFSecTSecGrpIncByUIncludeIdxKey,
				cfsec::ICFSecTSecGrpIncObj*>();
		}
		cfsec::CFSecTSecGrpIncByUIncludeIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredTSecGroupId( TSecGroupId );
		key.setRequiredIncludeGroupId( IncludeGroupId );
		cfsec::ICFSecTSecGrpIncObj* obj = NULL;
		auto searchIndexByUIncludeIdx = indexByUIncludeIdx->find( key );
		if( searchIndexByUIncludeIdx != indexByUIncludeIdx->end() ) {
			dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableTSecGrpInc()->deleteTSecGrpIncByUIncludeIdx( schema->getAuthorization(),
				TenantId,
				TSecGroupId,
				IncludeGroupId );
		}
		else {
			dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableTSecGrpInc()->deleteTSecGrpIncByUIncludeIdx( schema->getAuthorization(),
				TenantId,
				TSecGroupId,
				IncludeGroupId );
		}
		deepDisposeByUIncludeIdx( TenantId,
			TSecGroupId,
			IncludeGroupId );
	}

	void CFSecTSecGrpIncTableObj::reallyDetachFromIndexesTSecGrpInc( cfsec::ICFSecTSecGrpIncObj* Obj ) {
		static const std::string S_ProcName( "reallyDetachFromIndexesTSecGrpInc" );
		static const std::string S_Obj( "Obj" );
		static const std::string S_ExistingObj( "ExistingObj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfsec::ICFSecTSecGrpIncObj* obj = Obj;
		cfsec::CFSecTSecGrpIncPKey* pkey = obj->getPKey();
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			cfsec::ICFSecTSecGrpIncObj* existingObj = searchMembers->second;
			if( existingObj == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_ExistingObj );
			}
			if( indexByTenantIdx != NULL ) {
				cfsec::CFSecTSecGrpIncByTenantIdxKey keyTenantIdx;
				keyTenantIdx.setRequiredTenantId( obj->getRequiredTenantId() );
				auto searchTenantIdx = indexByTenantIdx->find( keyTenantIdx );
				if( searchTenantIdx != indexByTenantIdx->end() ) {
					std::map<cfsec::CFSecTSecGrpIncPKey, cfsec::ICFSecTSecGrpIncObj*>* mapTenantIdx = searchTenantIdx->second;
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
				cfsec::CFSecTSecGrpIncByGroupIdxKey keyGroupIdx;
				keyGroupIdx.setRequiredTenantId( obj->getRequiredTenantId() );
				keyGroupIdx.setRequiredTSecGroupId( obj->getRequiredTSecGroupId() );
				auto searchGroupIdx = indexByGroupIdx->find( keyGroupIdx );
				if( searchGroupIdx != indexByGroupIdx->end() ) {
					std::map<cfsec::CFSecTSecGrpIncPKey, cfsec::ICFSecTSecGrpIncObj*>* mapGroupIdx = searchGroupIdx->second;
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
				cfsec::CFSecTSecGrpIncByIncludeIdxKey keyIncludeIdx;
				keyIncludeIdx.setRequiredTenantId( obj->getRequiredTenantId() );
				keyIncludeIdx.setRequiredIncludeGroupId( obj->getRequiredIncludeGroupId() );
				auto searchIncludeIdx = indexByIncludeIdx->find( keyIncludeIdx );
				if( searchIncludeIdx != indexByIncludeIdx->end() ) {
					std::map<cfsec::CFSecTSecGrpIncPKey, cfsec::ICFSecTSecGrpIncObj*>* mapIncludeIdx = searchIncludeIdx->second;
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
				cfsec::CFSecTSecGrpIncByUIncludeIdxKey keyUIncludeIdx;
				keyUIncludeIdx.setRequiredTenantId( obj->getRequiredTenantId() );
				keyUIncludeIdx.setRequiredTSecGroupId( obj->getRequiredTSecGroupId() );
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
