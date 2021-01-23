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

	const std::string CFSecISOCtryCcyTableObj::CLASS_NAME( "CFSecISOCtryCcyTableObj" );
	const std::string CFSecISOCtryCcyTableObj::TABLE_NAME( "ISOCtryCcy" );
	const std::string CFSecISOCtryCcyTableObj::TABLE_DBNAME( "iso_cntryccy" );

	CFSecISOCtryCcyTableObj::CFSecISOCtryCcyTableObj() {
		schema = NULL;
		members = new std::map<cfsec::CFSecISOCtryCcyPKey, cfsec::ICFSecISOCtryCcyObj*>();
		allISOCtryCcy = NULL;
		indexByCtryIdx = new std::map< cfsec::CFSecISOCtryCcyByCtryIdxKey,
			std::map< cfsec::CFSecISOCtryCcyPKey, cfsec::ICFSecISOCtryCcyObj*>*>();
		indexByCcyIdx = new std::map< cfsec::CFSecISOCtryCcyByCcyIdxKey,
			std::map< cfsec::CFSecISOCtryCcyPKey, cfsec::ICFSecISOCtryCcyObj*>*>();
	}

	CFSecISOCtryCcyTableObj::CFSecISOCtryCcyTableObj( cfsec::ICFSecSchemaObj* argSchema ) {
		schema = dynamic_cast<cfsec::ICFSecSchemaObj*>( argSchema );
		members = new std::map<cfsec::CFSecISOCtryCcyPKey, cfsec::ICFSecISOCtryCcyObj*>();
		allISOCtryCcy = NULL;
		indexByCtryIdx = new std::map< cfsec::CFSecISOCtryCcyByCtryIdxKey,
			std::map< cfsec::CFSecISOCtryCcyPKey, cfsec::ICFSecISOCtryCcyObj*>*>();
		indexByCcyIdx = new std::map< cfsec::CFSecISOCtryCcyByCcyIdxKey,
			std::map< cfsec::CFSecISOCtryCcyPKey, cfsec::ICFSecISOCtryCcyObj*>*>();
	}

	CFSecISOCtryCcyTableObj::~CFSecISOCtryCcyTableObj() {
		minimizeMemory();
		if( indexByCtryIdx != NULL ) {
			delete indexByCtryIdx;
			indexByCtryIdx = NULL;
		}
		if( indexByCcyIdx != NULL ) {
			delete indexByCcyIdx;
			indexByCcyIdx = NULL;
		}
		if( members != NULL ) {
			cfsec::ICFSecISOCtryCcyObj* curMember;
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

	cfsec::ICFSecSchemaObj* CFSecISOCtryCcyTableObj::getSchema() {
		return( schema );
	}

	void CFSecISOCtryCcyTableObj::setSchema( cfsec::ICFSecSchemaObj* value ) {
		schema = dynamic_cast<cfsec::ICFSecSchemaObj*>( value );
	}

	const std::string CFSecISOCtryCcyTableObj::getTableName() {
		return( TABLE_NAME );
	}

	const std::string CFSecISOCtryCcyTableObj::getTableDbName() {
		return( TABLE_DBNAME );
	}
	const classcode_t* CFSecISOCtryCcyTableObj::getObjQualifyingClassCode() {
		return( NULL );
	}


	void CFSecISOCtryCcyTableObj::minimizeMemory() {
		if( allISOCtryCcy != NULL ) {
			allISOCtryCcy->clear();
			delete allISOCtryCcy;
			allISOCtryCcy = NULL;
		}
		if( indexByCtryIdx != NULL ) {
			std::map< cfsec::CFSecISOCtryCcyByCtryIdxKey,
				std::map< cfsec::CFSecISOCtryCcyPKey, cfsec::ICFSecISOCtryCcyObj*>* >::iterator iterByCtryIdx = indexByCtryIdx->begin();
			std::map< cfsec::CFSecISOCtryCcyByCtryIdxKey,
				std::map< cfsec::CFSecISOCtryCcyPKey, cfsec::ICFSecISOCtryCcyObj*>* >::iterator endByCtryIdx = indexByCtryIdx->end();
			std::map< cfsec::CFSecISOCtryCcyPKey, cfsec::ICFSecISOCtryCcyObj*>* curByCtryIdx = NULL;
			while( iterByCtryIdx != endByCtryIdx ) {
				curByCtryIdx = iterByCtryIdx->second;
				if( curByCtryIdx != NULL ) {
					curByCtryIdx->clear();
					delete curByCtryIdx;
					curByCtryIdx = NULL;
					iterByCtryIdx->second = NULL;
				}
				iterByCtryIdx ++;
			}
			indexByCtryIdx->clear();
		}
		if( indexByCcyIdx != NULL ) {
			std::map< cfsec::CFSecISOCtryCcyByCcyIdxKey,
				std::map< cfsec::CFSecISOCtryCcyPKey, cfsec::ICFSecISOCtryCcyObj*>* >::iterator iterByCcyIdx = indexByCcyIdx->begin();
			std::map< cfsec::CFSecISOCtryCcyByCcyIdxKey,
				std::map< cfsec::CFSecISOCtryCcyPKey, cfsec::ICFSecISOCtryCcyObj*>* >::iterator endByCcyIdx = indexByCcyIdx->end();
			std::map< cfsec::CFSecISOCtryCcyPKey, cfsec::ICFSecISOCtryCcyObj*>* curByCcyIdx = NULL;
			while( iterByCcyIdx != endByCcyIdx ) {
				curByCcyIdx = iterByCcyIdx->second;
				if( curByCcyIdx != NULL ) {
					curByCcyIdx->clear();
					delete curByCcyIdx;
					curByCcyIdx = NULL;
					iterByCcyIdx->second = NULL;
				}
				iterByCcyIdx ++;
			}
			indexByCcyIdx->clear();
		}
		if( members != NULL ) {
			cfsec::ICFSecISOCtryCcyObj* cur = NULL;
			cfsec::ICFSecISOCtryCcyEditObj* edit = NULL;
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

	cfsec::ICFSecISOCtryCcyObj* CFSecISOCtryCcyTableObj::newInstance() {
		cfsec::ICFSecISOCtryCcyObj* inst = dynamic_cast<cfsec::ICFSecISOCtryCcyObj*>( new CFSecISOCtryCcyObj( schema ) );
		return( inst );
	}

	cfsec::ICFSecISOCtryCcyEditObj* CFSecISOCtryCcyTableObj::newEditInstance( cfsec::ICFSecISOCtryCcyObj* orig ) {
		cfsec::ICFSecISOCtryCcyEditObj* edit = dynamic_cast<cfsec::ICFSecISOCtryCcyEditObj*>( new CFSecISOCtryCcyEditObj( orig ));
		return( edit );
	}

	cfsec::ICFSecISOCtryCcyObj* CFSecISOCtryCcyTableObj::realizeISOCtryCcy( cfsec::ICFSecISOCtryCcyObj* Obj ) {
		static const std::string S_ProcName( "realizeISOCtryCcy" );
		static const std::string S_ExistingObj( "existingObj" );
		static const std::string S_KeepObj( "keepObj" );
		static const std::string S_Obj( "Obj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfsec::ICFSecISOCtryCcyObj* obj = Obj;
		cfsec::ICFSecISOCtryCcyObj* existingObj = NULL;
		cfsec::CFSecISOCtryCcyPKey* pkey = obj->getPKey();
		cfsec::ICFSecISOCtryCcyObj* keepObj = NULL;
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
			if( indexByCtryIdx != NULL ) {
				cfsec::CFSecISOCtryCcyByCtryIdxKey keyCtryIdx;
				keyCtryIdx.setRequiredISOCtryId( keepObj->getRequiredISOCtryId() );
				auto searchCtryIdx = indexByCtryIdx->find( keyCtryIdx );
				if( searchCtryIdx != indexByCtryIdx->end() ) {
					std::map<cfsec::CFSecISOCtryCcyPKey, cfsec::ICFSecISOCtryCcyObj*>* mapCtryIdx = searchCtryIdx->second;
					if( mapCtryIdx != NULL ) {
						auto removalProbe = mapCtryIdx->find( *(keepObj->getPKey()) );
						if( removalProbe != mapCtryIdx->end() ) {
							mapCtryIdx->erase( removalProbe );
						}
					}
				}
			}

			if( indexByCcyIdx != NULL ) {
				cfsec::CFSecISOCtryCcyByCcyIdxKey keyCcyIdx;
				keyCcyIdx.setRequiredISOCcyId( keepObj->getRequiredISOCcyId() );
				auto searchCcyIdx = indexByCcyIdx->find( keyCcyIdx );
				if( searchCcyIdx != indexByCcyIdx->end() ) {
					std::map<cfsec::CFSecISOCtryCcyPKey, cfsec::ICFSecISOCtryCcyObj*>* mapCcyIdx = searchCcyIdx->second;
					if( mapCcyIdx != NULL ) {
						auto removalProbe = mapCcyIdx->find( *(keepObj->getPKey()) );
						if( removalProbe != mapCcyIdx->end() ) {
							mapCcyIdx->erase( removalProbe );
						}
					}
				}
			}

			keepObj->setBuff( dynamic_cast<cfsec::CFSecISOCtryCcyBuff*>( Obj->getBuff()->clone() ) );
			// Attach new object to alternate and duplicate indexes -- PKey stays stable

			if( indexByCtryIdx != NULL ) {
				static const std::string S_ACtryIdxObj( "aCtryIdxObj" );
				cfsec::ICFSecISOCtryCcyObj* aCtryIdxObj =
					dynamic_cast<cfsec::ICFSecISOCtryCcyObj*>( keepObj );
				if( aCtryIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ACtryIdxObj );
				}
				cfsec::CFSecISOCtryCcyByCtryIdxKey keyCtryIdx;
				keyCtryIdx.setRequiredISOCtryId( keepObj->getRequiredISOCtryId() );
				auto searchIndexByCtryIdx = indexByCtryIdx->find( keyCtryIdx );
				if( searchIndexByCtryIdx != indexByCtryIdx->end() ) {
					std::map<cfsec::CFSecISOCtryCcyPKey, cfsec::ICFSecISOCtryCcyObj*>* mapCtryIdx = searchIndexByCtryIdx->second;
					if( mapCtryIdx != NULL ) {
						mapCtryIdx->insert( std::map< cfsec::CFSecISOCtryCcyPKey, cfsec::ICFSecISOCtryCcyObj* >::value_type( *(keepObj->getPKey()), aCtryIdxObj ) );
					}
				}
			}

			if( indexByCcyIdx != NULL ) {
				static const std::string S_ACcyIdxObj( "aCcyIdxObj" );
				cfsec::ICFSecISOCtryCcyObj* aCcyIdxObj =
					dynamic_cast<cfsec::ICFSecISOCtryCcyObj*>( keepObj );
				if( aCcyIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ACcyIdxObj );
				}
				cfsec::CFSecISOCtryCcyByCcyIdxKey keyCcyIdx;
				keyCcyIdx.setRequiredISOCcyId( keepObj->getRequiredISOCcyId() );
				auto searchIndexByCcyIdx = indexByCcyIdx->find( keyCcyIdx );
				if( searchIndexByCcyIdx != indexByCcyIdx->end() ) {
					std::map<cfsec::CFSecISOCtryCcyPKey, cfsec::ICFSecISOCtryCcyObj*>* mapCcyIdx = searchIndexByCcyIdx->second;
					if( mapCcyIdx != NULL ) {
						mapCcyIdx->insert( std::map< cfsec::CFSecISOCtryCcyPKey, cfsec::ICFSecISOCtryCcyObj* >::value_type( *(keepObj->getPKey()), aCcyIdxObj ) );
					}
				}
			}

			if( allISOCtryCcy != NULL ) {
				allISOCtryCcy->insert( std::map< cfsec::CFSecISOCtryCcyPKey, cfsec::ICFSecISOCtryCcyObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			}
		}
		else {
			keepObj = obj;
			keepObj->setIsNew( false );
			pkey = keepObj->getPKey();
			// Attach new object to PKey, all, alternate, and duplicate indexes
			members->insert( std::map< cfsec::CFSecISOCtryCcyPKey, cfsec::ICFSecISOCtryCcyObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			// Attach new object to alternate and duplicate indexes -- PKey stay stable

			if( indexByCtryIdx != NULL ) {
				static const std::string S_ACtryIdxObj( "aCtryIdxObj" );
				cfsec::ICFSecISOCtryCcyObj* aCtryIdxObj =
					dynamic_cast<cfsec::ICFSecISOCtryCcyObj*>( keepObj );
				if( aCtryIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ACtryIdxObj );
				}
				cfsec::CFSecISOCtryCcyByCtryIdxKey keyCtryIdx;
				keyCtryIdx.setRequiredISOCtryId( keepObj->getRequiredISOCtryId() );
				auto searchIndexByCtryIdx = indexByCtryIdx->find( keyCtryIdx );
				if( searchIndexByCtryIdx != indexByCtryIdx->end() ) {
					std::map<cfsec::CFSecISOCtryCcyPKey, cfsec::ICFSecISOCtryCcyObj*>* mapCtryIdx = searchIndexByCtryIdx->second;
					if( mapCtryIdx != NULL ) {
						mapCtryIdx->insert( std::map< cfsec::CFSecISOCtryCcyPKey, cfsec::ICFSecISOCtryCcyObj* >::value_type( *(keepObj->getPKey()), aCtryIdxObj ) );
					}
				}
			}

			if( indexByCcyIdx != NULL ) {
				static const std::string S_ACcyIdxObj( "aCcyIdxObj" );
				cfsec::ICFSecISOCtryCcyObj* aCcyIdxObj =
					dynamic_cast<cfsec::ICFSecISOCtryCcyObj*>( keepObj );
				if( aCcyIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ACcyIdxObj );
				}
				cfsec::CFSecISOCtryCcyByCcyIdxKey keyCcyIdx;
				keyCcyIdx.setRequiredISOCcyId( keepObj->getRequiredISOCcyId() );
				auto searchIndexByCcyIdx = indexByCcyIdx->find( keyCcyIdx );
				if( searchIndexByCcyIdx != indexByCcyIdx->end() ) {
					std::map<cfsec::CFSecISOCtryCcyPKey, cfsec::ICFSecISOCtryCcyObj*>* mapCcyIdx = searchIndexByCcyIdx->second;
					if( mapCcyIdx != NULL ) {
						mapCcyIdx->insert( std::map< cfsec::CFSecISOCtryCcyPKey, cfsec::ICFSecISOCtryCcyObj* >::value_type( *(keepObj->getPKey()), aCcyIdxObj ) );
					}
				}
			}

			if( allISOCtryCcy != NULL ) {
				allISOCtryCcy->insert( std::map< cfsec::CFSecISOCtryCcyPKey, cfsec::ICFSecISOCtryCcyObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
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

	void CFSecISOCtryCcyTableObj::deepDisposeByIdIdx( const int16_t ISOCtryId,
			const int16_t ISOCcyId ) {
		static const std::string S_ProcName( "deepDisposeByIdIdx" );
		std::vector<cfsec::ICFSecISOCtryCcyObj*> list;
		cfsec::ICFSecISOCtryCcyObj* existingObj = readCachedISOCtryCcyByIdIdx( ISOCtryId,
				ISOCcyId );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfsec::ICFSecISOCtryCcyObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecISOCtryCcyBuff::CLASS_CODE ) {
					dynamic_cast<cfsec::CFSecISOCtryCcyTableObj*>( schema->getISOCtryCcyTableObj() )->reallyDeepDisposeISOCtryCcy( dynamic_cast<cfsec::ICFSecISOCtryCcyObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFSecISOCtryCcyTableObj::deepDisposeByCtryIdx( const int16_t ISOCtryId ) {
		static const std::string S_ProcName( "deepDisposeByCtryIdx" );
		std::vector<cfsec::ICFSecISOCtryCcyObj*> list;
		std::vector<cfsec::ICFSecISOCtryCcyObj*> matchesFound = readCachedISOCtryCcyByCtryIdx( ISOCtryId );
		auto iterMatches = matchesFound.begin();
		auto endMatches = matchesFound.end();
		while( iterMatches != endMatches ) {
			if( *iterMatches != NULL ) {
				list.push_back( *iterMatches );
			}
			iterMatches ++;
		}
		cfsec::ICFSecISOCtryCcyObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecISOCtryCcyBuff::CLASS_CODE ) {
					dynamic_cast<cfsec::CFSecISOCtryCcyTableObj*>( schema->getISOCtryCcyTableObj() )->reallyDeepDisposeISOCtryCcy( dynamic_cast<cfsec::ICFSecISOCtryCcyObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFSecISOCtryCcyTableObj::deepDisposeByCcyIdx( const int16_t ISOCcyId ) {
		static const std::string S_ProcName( "deepDisposeByCcyIdx" );
		std::vector<cfsec::ICFSecISOCtryCcyObj*> list;
		std::vector<cfsec::ICFSecISOCtryCcyObj*> matchesFound = readCachedISOCtryCcyByCcyIdx( ISOCcyId );
		auto iterMatches = matchesFound.begin();
		auto endMatches = matchesFound.end();
		while( iterMatches != endMatches ) {
			if( *iterMatches != NULL ) {
				list.push_back( *iterMatches );
			}
			iterMatches ++;
		}
		cfsec::ICFSecISOCtryCcyObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecISOCtryCcyBuff::CLASS_CODE ) {
					dynamic_cast<cfsec::CFSecISOCtryCcyTableObj*>( schema->getISOCtryCcyTableObj() )->reallyDeepDisposeISOCtryCcy( dynamic_cast<cfsec::ICFSecISOCtryCcyObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFSecISOCtryCcyTableObj::reallyDeepDisposeISOCtryCcy( cfsec::ICFSecISOCtryCcyObj* Obj ) {
		static const std::string S_ProcName( "reallyDeepDisposeISOCtryCcy" );

		if( Obj == NULL ) {
			return;
		}

		cfsec::ICFSecISOCtryCcyObj* obj = Obj;
		
		classcode_t classCode = obj->getClassCode();
		if( classCode == cfsec::CFSecISOCtryCcyBuff::CLASS_CODE ) {
			dynamic_cast<cfsec::CFSecISOCtryCcyTableObj*>( schema->getISOCtryCcyTableObj() )->reallyDetachFromIndexesISOCtryCcy( dynamic_cast<cfsec::ICFSecISOCtryCcyObj*>( obj ) );
		}

		if( obj->getEdit() != NULL ) {
			obj->endEdit();
		}
		delete obj;
		obj = NULL;
	}

	cfsec::ICFSecISOCtryCcyObj* CFSecISOCtryCcyTableObj::createISOCtryCcy( cfsec::ICFSecISOCtryCcyEditObj* Obj ) {
		static const std::string S_ProcName( "createISOCtryCcy" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Cloneable( "cloneable" );
		static const std::string S_ClonedBuff( "clonedbuff" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecISOCtryCcyObj* obj = dynamic_cast<cfsec::ICFSecISOCtryCcyObj*>( Obj->getOrig() );
		try {
			cfsec::CFSecISOCtryCcyBuff* buff = dynamic_cast<cfsec::CFSecISOCtryCcyBuff*>( Obj->getBuff()->clone() );
			// C++18 version of create returns a new buffer instance and takes over ownership of the passed-in buffer
			// MSS TODO WORKING The xmsg client will need to return the buffer instance created by processing
			// the response message, while xmsg rqst will have to delete the backing store instance
			// it receives after preparing the reply message so that memory doesn't leak on every request.
			cflib::ICFLibCloneableObj* cloneable = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableISOCtryCcy()->createISOCtryCcy(
				schema->getAuthorization(),
				buff );
			if( cloneable == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Cloneable );
			}
			Obj->endEdit();
			obj->setBuff( dynamic_cast<cfsec::CFSecISOCtryCcyBuff*>( cloneable ) );
			obj = dynamic_cast<cfsec::ICFSecISOCtryCcyObj*>( obj->realize() );
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

	cfsec::ICFSecISOCtryCcyObj* CFSecISOCtryCcyTableObj::readISOCtryCcy( cfsec::CFSecISOCtryCcyPKey* pkey, bool forceRead ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readISOCtryCcy" );
		cfsec::ICFSecISOCtryCcyObj* obj = NULL;
		cfsec::ICFSecISOCtryCcyObj* realized = NULL;
		if( ! forceRead ) {
			auto searchMembers = members->find( *pkey );
			if( searchMembers != members->end() ) {
				// obj could be NULL if cache misses is enabled
				obj = searchMembers->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecISOCtryCcyBuff* readBuff = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableISOCtryCcy()->readDerivedByIdIdx( schema->getAuthorization(),
			pkey->getRequiredISOCtryId(),
			pkey->getRequiredISOCcyId() );
			if( readBuff != NULL ) {
			obj = dynamic_cast<cfsec::CFSecISOCtryCcyTableObj*>( schema->getISOCtryCcyTableObj() )->newInstance();
				obj->setBuff( readBuff );
				realized = dynamic_cast<cfsec::ICFSecISOCtryCcyObj*>( obj->realize() );
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

	cfsec::ICFSecISOCtryCcyObj* CFSecISOCtryCcyTableObj::lockISOCtryCcy( cfsec::CFSecISOCtryCcyPKey* pkey ) {
		static const std::string S_ProcName( "lockISOCtryCcy" );
		cfsec::ICFSecISOCtryCcyObj* locked = NULL;
		cfsec::CFSecISOCtryCcyBuff* lockBuff = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableISOCtryCcy()->lockDerived( schema->getAuthorization(), pkey );
		if( lockBuff != NULL ) {
			locked = dynamic_cast<cfsec::CFSecISOCtryCcyTableObj*>( schema->getISOCtryCcyTableObj() )->newInstance();
			locked->setBuff( lockBuff );
			locked = dynamic_cast<cfsec::ICFSecISOCtryCcyObj*>( locked->realize() );
		}
		else {
			return( NULL );
		}
		return( locked );
	}

	std::vector<cfsec::ICFSecISOCtryCcyObj*> CFSecISOCtryCcyTableObj::readAllISOCtryCcy( bool forceRead ) {
		static const std::string S_ProcName( "readAllISOCtryCcy" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Realized( "realized" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecISOCtryCcyObj* realized = NULL;
		if( forceRead || ( allISOCtryCcy == NULL ) ) {
			std::map<cfsec::CFSecISOCtryCcyPKey, cfsec::ICFSecISOCtryCcyObj*>* map = new std::map<cfsec::CFSecISOCtryCcyPKey,cfsec::ICFSecISOCtryCcyObj*>();
			allISOCtryCcy = map;
			std::TCFLibOwningVector<cfsec::CFSecISOCtryCcyBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableISOCtryCcy()->readAllDerived( schema->getAuthorization() );
			cfsec::CFSecISOCtryCcyBuff* buff = NULL;
			cfsec::ICFSecISOCtryCcyObj* obj = NULL;
			try {
				for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
					buff = buffList[ idx ];
					buffList[ idx ] = NULL;
				obj = newInstance();
					obj->setBuff( buff );
					realized = dynamic_cast<cfsec::ICFSecISOCtryCcyObj*>( obj->realize() );
					if( realized == NULL ) {
						throw cflib::CFLibNullArgumentException( CLASS_NAME,
							S_ProcName,
							0,
							S_Realized );
					}
					allISOCtryCcy->insert( std::map< cfsec::CFSecISOCtryCcyPKey, cfsec::ICFSecISOCtryCcyObj* >::value_type( *(realized->getPKey()), realized ) );
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
		size_t len = allISOCtryCcy->size();
		std::vector<cfsec::ICFSecISOCtryCcyObj*> arr;
		auto valIter = allISOCtryCcy->begin();
		size_t idx = 0;
		while( valIter != allISOCtryCcy->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	cfsec::ICFSecISOCtryCcyObj* CFSecISOCtryCcyTableObj::readISOCtryCcyByIdIdx( const int16_t ISOCtryId,
			const int16_t ISOCcyId, bool forceRead )
	{
		static const std::string S_ProcName( "readISOCtryCcyByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecISOCtryCcyPKey pkey;
		pkey.setRequiredISOCtryId( ISOCtryId );
		pkey.setRequiredISOCcyId( ISOCcyId );
		cfsec::ICFSecISOCtryCcyObj* obj = readISOCtryCcy( &pkey, forceRead );
		return( obj );
	}

	std::vector<cfsec::ICFSecISOCtryCcyObj*> CFSecISOCtryCcyTableObj::readISOCtryCcyByCtryIdx( const int16_t ISOCtryId,
		bool forceRead )
	{
		static const std::string S_ProcName( "readISOCtryCcyByCtryIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecISOCtryCcyByCtryIdxKey key;
		key.setRequiredISOCtryId( ISOCtryId );
		std::map<cfsec::CFSecISOCtryCcyPKey, cfsec::ICFSecISOCtryCcyObj*>* dict;
		std::map<cfsec::CFSecISOCtryCcyPKey, cfsec::ICFSecISOCtryCcyObj*>* oldDict;
		if( indexByCtryIdx == NULL ) {
			indexByCtryIdx = new std::map< cfsec::CFSecISOCtryCcyByCtryIdxKey,
				std::map< cfsec::CFSecISOCtryCcyPKey, cfsec::ICFSecISOCtryCcyObj*>*>();
		}
		auto searchIndexByCtryIdx = indexByCtryIdx->find( key );
		if( searchIndexByCtryIdx != indexByCtryIdx->end() ) {
			oldDict = searchIndexByCtryIdx->second;
		}
		else {
			oldDict = NULL;
		}
		if( ( oldDict != NULL ) && ( ! forceRead ) ) {
			dict = oldDict;
		}
		else {
			dict = new std::map<cfsec::CFSecISOCtryCcyPKey, cfsec::ICFSecISOCtryCcyObj*>();
			cfsec::ICFSecISOCtryCcyObj* obj;
			std::TCFLibOwningVector<cfsec::CFSecISOCtryCcyBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableISOCtryCcy()->readDerivedByCtryIdx( schema->getAuthorization(),
				ISOCtryId );
			cfsec::CFSecISOCtryCcyBuff* buff;
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = dynamic_cast<cfsec::CFSecISOCtryCcyTableObj*>( schema->getISOCtryCcyTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
				obj->setBuff( buff );
				cfsec::ICFSecISOCtryCcyObj* realized = dynamic_cast<cfsec::ICFSecISOCtryCcyObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				dict->insert( std::map< cfsec::CFSecISOCtryCcyPKey, cfsec::ICFSecISOCtryCcyObj* >::value_type( *(realized->getPKey()), realized ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = NULL;
			}
			if( oldDict != NULL ) {
				indexByCtryIdx->erase( searchIndexByCtryIdx );
				delete oldDict;
				oldDict = NULL;
			}
			indexByCtryIdx->insert( std::map< cfsec::CFSecISOCtryCcyByCtryIdxKey,
				std::map< cfsec::CFSecISOCtryCcyPKey, cfsec::ICFSecISOCtryCcyObj* >* >::value_type( key, dict ) );
		}
		size_t len = dict->size();
		std::vector<cfsec::ICFSecISOCtryCcyObj*> arr;
		arr.reserve( len );
		auto valIter = dict->begin();
		while( valIter != dict->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	std::vector<cfsec::ICFSecISOCtryCcyObj*> CFSecISOCtryCcyTableObj::readISOCtryCcyByCcyIdx( const int16_t ISOCcyId,
		bool forceRead )
	{
		static const std::string S_ProcName( "readISOCtryCcyByCcyIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecISOCtryCcyByCcyIdxKey key;
		key.setRequiredISOCcyId( ISOCcyId );
		std::map<cfsec::CFSecISOCtryCcyPKey, cfsec::ICFSecISOCtryCcyObj*>* dict;
		std::map<cfsec::CFSecISOCtryCcyPKey, cfsec::ICFSecISOCtryCcyObj*>* oldDict;
		if( indexByCcyIdx == NULL ) {
			indexByCcyIdx = new std::map< cfsec::CFSecISOCtryCcyByCcyIdxKey,
				std::map< cfsec::CFSecISOCtryCcyPKey, cfsec::ICFSecISOCtryCcyObj*>*>();
		}
		auto searchIndexByCcyIdx = indexByCcyIdx->find( key );
		if( searchIndexByCcyIdx != indexByCcyIdx->end() ) {
			oldDict = searchIndexByCcyIdx->second;
		}
		else {
			oldDict = NULL;
		}
		if( ( oldDict != NULL ) && ( ! forceRead ) ) {
			dict = oldDict;
		}
		else {
			dict = new std::map<cfsec::CFSecISOCtryCcyPKey, cfsec::ICFSecISOCtryCcyObj*>();
			cfsec::ICFSecISOCtryCcyObj* obj;
			std::TCFLibOwningVector<cfsec::CFSecISOCtryCcyBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableISOCtryCcy()->readDerivedByCcyIdx( schema->getAuthorization(),
				ISOCcyId );
			cfsec::CFSecISOCtryCcyBuff* buff;
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = dynamic_cast<cfsec::CFSecISOCtryCcyTableObj*>( schema->getISOCtryCcyTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
				obj->setBuff( buff );
				cfsec::ICFSecISOCtryCcyObj* realized = dynamic_cast<cfsec::ICFSecISOCtryCcyObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				dict->insert( std::map< cfsec::CFSecISOCtryCcyPKey, cfsec::ICFSecISOCtryCcyObj* >::value_type( *(realized->getPKey()), realized ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = NULL;
			}
			if( oldDict != NULL ) {
				indexByCcyIdx->erase( searchIndexByCcyIdx );
				delete oldDict;
				oldDict = NULL;
			}
			indexByCcyIdx->insert( std::map< cfsec::CFSecISOCtryCcyByCcyIdxKey,
				std::map< cfsec::CFSecISOCtryCcyPKey, cfsec::ICFSecISOCtryCcyObj* >* >::value_type( key, dict ) );
		}
		size_t len = dict->size();
		std::vector<cfsec::ICFSecISOCtryCcyObj*> arr;
		arr.reserve( len );
		auto valIter = dict->begin();
		while( valIter != dict->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	cfsec::ICFSecISOCtryCcyObj* CFSecISOCtryCcyTableObj::readCachedISOCtryCcy( cfsec::CFSecISOCtryCcyPKey* pkey ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readISOCtryCcy" );
		cfsec::ICFSecISOCtryCcyObj* obj = NULL;
		cfsec::ICFSecISOCtryCcyObj* realized = NULL;
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			// obj could be NULL if cache misses is enabled
			obj = searchMembers->second;
			realized = obj;
		}
		return( realized );
	}

	cfsec::ICFSecISOCtryCcyObj* CFSecISOCtryCcyTableObj::readCachedISOCtryCcyByIdIdx( const int16_t ISOCtryId,
			const int16_t ISOCcyId )
	{
		static const std::string S_ProcName( "readCachedISOCtryCcyByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecISOCtryCcyPKey pkey;
		pkey.setRequiredISOCtryId( ISOCtryId );
		pkey.setRequiredISOCcyId( ISOCcyId );
		cfsec::ICFSecISOCtryCcyObj* obj = readCachedISOCtryCcy( &pkey );
		return( obj );
	}

	std::vector<cfsec::ICFSecISOCtryCcyObj*> CFSecISOCtryCcyTableObj::readCachedISOCtryCcyByCtryIdx( const int16_t ISOCtryId )
	{
		static const std::string S_ProcName( "readCachedISOCtryCcyByCtryIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		std::vector<cfsec::ICFSecISOCtryCcyObj*> arr;
		cfsec::CFSecISOCtryCcyByCtryIdxKey key;
		key.setRequiredISOCtryId( ISOCtryId );
		std::map<cfsec::CFSecISOCtryCcyPKey, cfsec::ICFSecISOCtryCcyObj*>* dict;
		if( indexByCtryIdx == NULL ) {
			return( arr );
		}
		auto searchIndexByCtryIdx = indexByCtryIdx->find( key );
		if( searchIndexByCtryIdx != indexByCtryIdx->end() ) {
			dict = searchIndexByCtryIdx->second;
			size_t len = dict->size();
			std::vector<cfsec::ICFSecISOCtryCcyObj*> arr;
			arr.reserve( len );
			auto valIter = dict->begin();
			while( valIter != dict->end() ) {
				arr.push_back( valIter->second );
				valIter ++;
			}
		}
		else {
			cfsec::ICFSecISOCtryCcyObj* obj;
			for( auto iterMembers = members->begin(); iterMembers != members->end(); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecISOCtryCcyBuff*>( obj->getBuff() ) ) == key ) {
						arr.push_back( obj );
					}
				}
			}
		}
		return( arr );
	}

	std::vector<cfsec::ICFSecISOCtryCcyObj*> CFSecISOCtryCcyTableObj::readCachedISOCtryCcyByCcyIdx( const int16_t ISOCcyId )
	{
		static const std::string S_ProcName( "readCachedISOCtryCcyByCcyIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		std::vector<cfsec::ICFSecISOCtryCcyObj*> arr;
		cfsec::CFSecISOCtryCcyByCcyIdxKey key;
		key.setRequiredISOCcyId( ISOCcyId );
		std::map<cfsec::CFSecISOCtryCcyPKey, cfsec::ICFSecISOCtryCcyObj*>* dict;
		if( indexByCcyIdx == NULL ) {
			return( arr );
		}
		auto searchIndexByCcyIdx = indexByCcyIdx->find( key );
		if( searchIndexByCcyIdx != indexByCcyIdx->end() ) {
			dict = searchIndexByCcyIdx->second;
			size_t len = dict->size();
			std::vector<cfsec::ICFSecISOCtryCcyObj*> arr;
			arr.reserve( len );
			auto valIter = dict->begin();
			while( valIter != dict->end() ) {
				arr.push_back( valIter->second );
				valIter ++;
			}
		}
		else {
			cfsec::ICFSecISOCtryCcyObj* obj;
			for( auto iterMembers = members->begin(); iterMembers != members->end(); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecISOCtryCcyBuff*>( obj->getBuff() ) ) == key ) {
						arr.push_back( obj );
					}
				}
			}
		}
		return( arr );
	}

	cfsec::ICFSecISOCtryCcyObj* CFSecISOCtryCcyTableObj::updateISOCtryCcy( cfsec::ICFSecISOCtryCcyEditObj* Obj ) {
		static const std::string S_ProcName( "updateISOCtryCcy" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Updated( "updated" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecISOCtryCcyObj* obj = dynamic_cast<cfsec::ICFSecISOCtryCcyObj*>( Obj->getOrig() );
		try {
			cfsec::CFSecISOCtryCcyBuff* updated = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableISOCtryCcy()->updateISOCtryCcy( schema->getAuthorization(),
				dynamic_cast<cfsec::CFSecISOCtryCcyBuff*>( Obj->getISOCtryCcyBuff()->clone() ) );
			if( updated == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Updated );
			}
			obj = dynamic_cast<cfsec::ICFSecISOCtryCcyObj*>( dynamic_cast<cfsec::CFSecISOCtryCcyTableObj*>( schema->getISOCtryCcyTableObj() )->newInstance() );
			obj->setBuff( updated );
			obj = dynamic_cast<cfsec::ICFSecISOCtryCcyObj*>( obj->realize() );
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

	void CFSecISOCtryCcyTableObj::deleteISOCtryCcy( cfsec::ICFSecISOCtryCcyEditObj* Obj ) {
		cfsec::ICFSecISOCtryCcyObj* obj = Obj;
		dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableISOCtryCcy()->deleteISOCtryCcy( schema->getAuthorization(),
			obj->getISOCtryCcyBuff() );
		deepDisposeByIdIdx( obj->getRequiredISOCtryId(),
			obj->getRequiredISOCcyId() );
	}

	void CFSecISOCtryCcyTableObj::deleteISOCtryCcyByIdIdx( const int16_t ISOCtryId,
			const int16_t ISOCcyId )
	{
		cfsec::CFSecISOCtryCcyPKey pkey;
		pkey.setRequiredISOCtryId( ISOCtryId );
		pkey.setRequiredISOCcyId( ISOCcyId );
		cfsec::ICFSecISOCtryCcyObj* obj = readISOCtryCcy( &pkey, true );
		if( obj != NULL ) {
			cfsec::ICFSecISOCtryCcyEditObj* editObj = dynamic_cast<cfsec::ICFSecISOCtryCcyEditObj*>( obj->getEdit() );
			if( editObj == NULL ) {
				editObj = dynamic_cast<cfsec::ICFSecISOCtryCcyEditObj*>( obj->beginEdit() );
			}
			if( editObj != NULL ) {
				editObj->deleteInstance();
				editObj = NULL;
			}
		}
	}

	void CFSecISOCtryCcyTableObj::deleteISOCtryCcyByCtryIdx( const int16_t ISOCtryId )
	{
		dynamic_cast<cfsec::ICFSecSchema*>( schema->getBackingStore() )->getTableISOCtryCcy()->deleteISOCtryCcyByCtryIdx( schema->getAuthorization(),
				ISOCtryId );
		deepDisposeByCtryIdx( ISOCtryId );
	}

	void CFSecISOCtryCcyTableObj::deleteISOCtryCcyByCcyIdx( const int16_t ISOCcyId )
	{
		dynamic_cast<cfsec::ICFSecSchema*>( schema->getBackingStore() )->getTableISOCtryCcy()->deleteISOCtryCcyByCcyIdx( schema->getAuthorization(),
				ISOCcyId );
		deepDisposeByCcyIdx( ISOCcyId );
	}

	void CFSecISOCtryCcyTableObj::reallyDetachFromIndexesISOCtryCcy( cfsec::ICFSecISOCtryCcyObj* Obj ) {
		static const std::string S_ProcName( "reallyDetachFromIndexesISOCtryCcy" );
		static const std::string S_Obj( "Obj" );
		static const std::string S_ExistingObj( "ExistingObj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfsec::ICFSecISOCtryCcyObj* obj = Obj;
		cfsec::CFSecISOCtryCcyPKey* pkey = obj->getPKey();
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			cfsec::ICFSecISOCtryCcyObj* existingObj = searchMembers->second;
			if( existingObj == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_ExistingObj );
			}
			if( indexByCtryIdx != NULL ) {
				cfsec::CFSecISOCtryCcyByCtryIdxKey keyCtryIdx;
				keyCtryIdx.setRequiredISOCtryId( obj->getRequiredISOCtryId() );
				auto searchCtryIdx = indexByCtryIdx->find( keyCtryIdx );
				if( searchCtryIdx != indexByCtryIdx->end() ) {
					std::map<cfsec::CFSecISOCtryCcyPKey, cfsec::ICFSecISOCtryCcyObj*>* mapCtryIdx = searchCtryIdx->second;
					if( mapCtryIdx != NULL ) {
						auto removalProbe = mapCtryIdx->find( *(obj->getPKey()) );
						if( removalProbe != mapCtryIdx->end() ) {
							mapCtryIdx->erase( removalProbe );
							if( mapCtryIdx->empty() ) {
								delete mapCtryIdx;
								mapCtryIdx = NULL;
								indexByCtryIdx->erase( searchCtryIdx );
							}
						}
					}
				}
			}

			if( indexByCcyIdx != NULL ) {
				cfsec::CFSecISOCtryCcyByCcyIdxKey keyCcyIdx;
				keyCcyIdx.setRequiredISOCcyId( obj->getRequiredISOCcyId() );
				auto searchCcyIdx = indexByCcyIdx->find( keyCcyIdx );
				if( searchCcyIdx != indexByCcyIdx->end() ) {
					std::map<cfsec::CFSecISOCtryCcyPKey, cfsec::ICFSecISOCtryCcyObj*>* mapCcyIdx = searchCcyIdx->second;
					if( mapCcyIdx != NULL ) {
						auto removalProbe = mapCcyIdx->find( *(obj->getPKey()) );
						if( removalProbe != mapCcyIdx->end() ) {
							mapCcyIdx->erase( removalProbe );
							if( mapCcyIdx->empty() ) {
								delete mapCcyIdx;
								mapCcyIdx = NULL;
								indexByCcyIdx->erase( searchCcyIdx );
							}
						}
					}
				}
			}

			members->erase( searchMembers );
		}
	}


}
