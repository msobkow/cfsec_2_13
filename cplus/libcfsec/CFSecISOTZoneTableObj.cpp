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

	const std::string CFSecISOTZoneTableObj::CLASS_NAME( "CFSecISOTZoneTableObj" );
	const std::string CFSecISOTZoneTableObj::TABLE_NAME( "ISOTZone" );
	const std::string CFSecISOTZoneTableObj::TABLE_DBNAME( "ISOTz" );

	CFSecISOTZoneTableObj::CFSecISOTZoneTableObj() {
		schema = NULL;
		members = new std::map<cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj*>();
		allISOTZone = NULL;
		indexByOffsetIdx = new std::map< cfsec::CFSecISOTZoneByOffsetIdxKey,
			std::map< cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj*>*>();
		indexByUTZNameIdx = new std::map< cfsec::CFSecISOTZoneByUTZNameIdxKey,
			cfsec::ICFSecISOTZoneObj*>();
		indexByIso8601Idx = new std::map< cfsec::CFSecISOTZoneByIso8601IdxKey,
			std::map< cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj*>*>();
	}

	CFSecISOTZoneTableObj::CFSecISOTZoneTableObj( cfsec::ICFSecSchemaObj* argSchema ) {
		schema = dynamic_cast<cfsec::ICFSecSchemaObj*>( argSchema );
		members = new std::map<cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj*>();
		allISOTZone = NULL;
		indexByOffsetIdx = new std::map< cfsec::CFSecISOTZoneByOffsetIdxKey,
			std::map< cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj*>*>();
		indexByUTZNameIdx = new std::map< cfsec::CFSecISOTZoneByUTZNameIdxKey,
			cfsec::ICFSecISOTZoneObj*>();
		indexByIso8601Idx = new std::map< cfsec::CFSecISOTZoneByIso8601IdxKey,
			std::map< cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj*>*>();
	}

	CFSecISOTZoneTableObj::~CFSecISOTZoneTableObj() {
		minimizeMemory();
		if( indexByOffsetIdx != NULL ) {
			delete indexByOffsetIdx;
			indexByOffsetIdx = NULL;
		}
		if( indexByUTZNameIdx != NULL ) {
			delete indexByUTZNameIdx;
			indexByUTZNameIdx = NULL;
		}
		if( indexByIso8601Idx != NULL ) {
			delete indexByIso8601Idx;
			indexByIso8601Idx = NULL;
		}
		if( members != NULL ) {
			cfsec::ICFSecISOTZoneObj* curMember;
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

	cfsec::ICFSecSchemaObj* CFSecISOTZoneTableObj::getSchema() {
		return( schema );
	}

	void CFSecISOTZoneTableObj::setSchema( cfsec::ICFSecSchemaObj* value ) {
		schema = dynamic_cast<cfsec::ICFSecSchemaObj*>( value );
	}

	const std::string CFSecISOTZoneTableObj::getTableName() {
		return( TABLE_NAME );
	}

	const std::string CFSecISOTZoneTableObj::getTableDbName() {
		return( TABLE_DBNAME );
	}
	const classcode_t* CFSecISOTZoneTableObj::getObjQualifyingClassCode() {
		return( NULL );
	}


	void CFSecISOTZoneTableObj::minimizeMemory() {
		if( allISOTZone != NULL ) {
			allISOTZone->clear();
			delete allISOTZone;
			allISOTZone = NULL;
		}
		if( indexByOffsetIdx != NULL ) {
			std::map< cfsec::CFSecISOTZoneByOffsetIdxKey,
				std::map< cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj*>* >::iterator iterByOffsetIdx = indexByOffsetIdx->begin();
			std::map< cfsec::CFSecISOTZoneByOffsetIdxKey,
				std::map< cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj*>* >::iterator endByOffsetIdx = indexByOffsetIdx->end();
			std::map< cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj*>* curByOffsetIdx = NULL;
			while( iterByOffsetIdx != endByOffsetIdx ) {
				curByOffsetIdx = iterByOffsetIdx->second;
				if( curByOffsetIdx != NULL ) {
					curByOffsetIdx->clear();
					delete curByOffsetIdx;
					curByOffsetIdx = NULL;
					iterByOffsetIdx->second = NULL;
				}
				iterByOffsetIdx ++;
			}
			indexByOffsetIdx->clear();
		}
		if( indexByUTZNameIdx != NULL ) {
			indexByUTZNameIdx->clear();
		}
		if( indexByIso8601Idx != NULL ) {
			std::map< cfsec::CFSecISOTZoneByIso8601IdxKey,
				std::map< cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj*>* >::iterator iterByIso8601Idx = indexByIso8601Idx->begin();
			std::map< cfsec::CFSecISOTZoneByIso8601IdxKey,
				std::map< cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj*>* >::iterator endByIso8601Idx = indexByIso8601Idx->end();
			std::map< cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj*>* curByIso8601Idx = NULL;
			while( iterByIso8601Idx != endByIso8601Idx ) {
				curByIso8601Idx = iterByIso8601Idx->second;
				if( curByIso8601Idx != NULL ) {
					curByIso8601Idx->clear();
					delete curByIso8601Idx;
					curByIso8601Idx = NULL;
					iterByIso8601Idx->second = NULL;
				}
				iterByIso8601Idx ++;
			}
			indexByIso8601Idx->clear();
		}
		if( members != NULL ) {
			cfsec::ICFSecISOTZoneObj* cur = NULL;
			cfsec::ICFSecISOTZoneEditObj* edit = NULL;
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

	cfsec::ICFSecISOTZoneObj* CFSecISOTZoneTableObj::newInstance() {
		cfsec::ICFSecISOTZoneObj* inst = dynamic_cast<cfsec::ICFSecISOTZoneObj*>( new CFSecISOTZoneObj( schema ) );
		return( inst );
	}

	cfsec::ICFSecISOTZoneEditObj* CFSecISOTZoneTableObj::newEditInstance( cfsec::ICFSecISOTZoneObj* orig ) {
		cfsec::ICFSecISOTZoneEditObj* edit = dynamic_cast<cfsec::ICFSecISOTZoneEditObj*>( new CFSecISOTZoneEditObj( orig ));
		return( edit );
	}

	cfsec::ICFSecISOTZoneObj* CFSecISOTZoneTableObj::realizeISOTZone( cfsec::ICFSecISOTZoneObj* Obj ) {
		static const std::string S_ProcName( "realizeISOTZone" );
		static const std::string S_ExistingObj( "existingObj" );
		static const std::string S_KeepObj( "keepObj" );
		static const std::string S_Obj( "Obj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfsec::ICFSecISOTZoneObj* obj = Obj;
		cfsec::ICFSecISOTZoneObj* existingObj = NULL;
		cfsec::CFSecISOTZonePKey* pkey = obj->getPKey();
		cfsec::ICFSecISOTZoneObj* keepObj = NULL;
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
			if( indexByOffsetIdx != NULL ) {
				cfsec::CFSecISOTZoneByOffsetIdxKey keyOffsetIdx;
				keyOffsetIdx.setRequiredTZHourOffset( keepObj->getRequiredTZHourOffset() );
				keyOffsetIdx.setRequiredTZMinOffset( keepObj->getRequiredTZMinOffset() );
				auto searchOffsetIdx = indexByOffsetIdx->find( keyOffsetIdx );
				if( searchOffsetIdx != indexByOffsetIdx->end() ) {
					std::map<cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj*>* mapOffsetIdx = searchOffsetIdx->second;
					if( mapOffsetIdx != NULL ) {
						auto removalProbe = mapOffsetIdx->find( *(keepObj->getPKey()) );
						if( removalProbe != mapOffsetIdx->end() ) {
							mapOffsetIdx->erase( removalProbe );
						}
					}
				}
			}

			if( indexByUTZNameIdx != NULL ) {
				cfsec::CFSecISOTZoneByUTZNameIdxKey keyUTZNameIdx;
				keyUTZNameIdx.setRequiredTZName( keepObj->getRequiredTZName() );
				auto removalProbe = indexByUTZNameIdx->find( keyUTZNameIdx );
				if( removalProbe != indexByUTZNameIdx->end() ) {
					indexByUTZNameIdx->erase( removalProbe );
				}
			}

			if( indexByIso8601Idx != NULL ) {
				cfsec::CFSecISOTZoneByIso8601IdxKey keyIso8601Idx;
				keyIso8601Idx.setRequiredIso8601( keepObj->getRequiredIso8601() );
				auto searchIso8601Idx = indexByIso8601Idx->find( keyIso8601Idx );
				if( searchIso8601Idx != indexByIso8601Idx->end() ) {
					std::map<cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj*>* mapIso8601Idx = searchIso8601Idx->second;
					if( mapIso8601Idx != NULL ) {
						auto removalProbe = mapIso8601Idx->find( *(keepObj->getPKey()) );
						if( removalProbe != mapIso8601Idx->end() ) {
							mapIso8601Idx->erase( removalProbe );
						}
					}
				}
			}

			keepObj->setBuff( dynamic_cast<cfsec::CFSecISOTZoneBuff*>( Obj->getBuff()->clone() ) );
			// Attach new object to alternate and duplicate indexes -- PKey stays stable

			if( indexByOffsetIdx != NULL ) {
				static const std::string S_AOffsetIdxObj( "aOffsetIdxObj" );
				cfsec::ICFSecISOTZoneObj* aOffsetIdxObj =
					dynamic_cast<cfsec::ICFSecISOTZoneObj*>( keepObj );
				if( aOffsetIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AOffsetIdxObj );
				}
				cfsec::CFSecISOTZoneByOffsetIdxKey keyOffsetIdx;
				keyOffsetIdx.setRequiredTZHourOffset( keepObj->getRequiredTZHourOffset() );
				keyOffsetIdx.setRequiredTZMinOffset( keepObj->getRequiredTZMinOffset() );
				auto searchIndexByOffsetIdx = indexByOffsetIdx->find( keyOffsetIdx );
				if( searchIndexByOffsetIdx != indexByOffsetIdx->end() ) {
					std::map<cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj*>* mapOffsetIdx = searchIndexByOffsetIdx->second;
					if( mapOffsetIdx != NULL ) {
						mapOffsetIdx->insert( std::map< cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj* >::value_type( *(keepObj->getPKey()), aOffsetIdxObj ) );
					}
				}
			}

			if( indexByUTZNameIdx != NULL ) {
				static const std::string S_AUTZNameIdxObj( "aUTZNameIdxObj" );
				cfsec::ICFSecISOTZoneObj* aUTZNameIdxObj =
					dynamic_cast<cfsec::ICFSecISOTZoneObj*>( keepObj );
				if( aUTZNameIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AUTZNameIdxObj );
				}
				cfsec::CFSecISOTZoneByUTZNameIdxKey keyUTZNameIdx;
				keyUTZNameIdx.setRequiredTZName( keepObj->getRequiredTZName() );
				indexByUTZNameIdx->insert( std::map< cfsec::CFSecISOTZoneByUTZNameIdxKey, cfsec::ICFSecISOTZoneObj* >::value_type( keyUTZNameIdx, aUTZNameIdxObj ) );
			}

			if( indexByIso8601Idx != NULL ) {
				static const std::string S_AIso8601IdxObj( "aIso8601IdxObj" );
				cfsec::ICFSecISOTZoneObj* aIso8601IdxObj =
					dynamic_cast<cfsec::ICFSecISOTZoneObj*>( keepObj );
				if( aIso8601IdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AIso8601IdxObj );
				}
				cfsec::CFSecISOTZoneByIso8601IdxKey keyIso8601Idx;
				keyIso8601Idx.setRequiredIso8601( keepObj->getRequiredIso8601() );
				auto searchIndexByIso8601Idx = indexByIso8601Idx->find( keyIso8601Idx );
				if( searchIndexByIso8601Idx != indexByIso8601Idx->end() ) {
					std::map<cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj*>* mapIso8601Idx = searchIndexByIso8601Idx->second;
					if( mapIso8601Idx != NULL ) {
						mapIso8601Idx->insert( std::map< cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj* >::value_type( *(keepObj->getPKey()), aIso8601IdxObj ) );
					}
				}
			}

			if( allISOTZone != NULL ) {
				allISOTZone->insert( std::map< cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			}
		}
		else {
			keepObj = obj;
			keepObj->setIsNew( false );
			pkey = keepObj->getPKey();
			// Attach new object to PKey, all, alternate, and duplicate indexes
			members->insert( std::map< cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			// Attach new object to alternate and duplicate indexes -- PKey stay stable

			if( indexByOffsetIdx != NULL ) {
				static const std::string S_AOffsetIdxObj( "aOffsetIdxObj" );
				cfsec::ICFSecISOTZoneObj* aOffsetIdxObj =
					dynamic_cast<cfsec::ICFSecISOTZoneObj*>( keepObj );
				if( aOffsetIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AOffsetIdxObj );
				}
				cfsec::CFSecISOTZoneByOffsetIdxKey keyOffsetIdx;
				keyOffsetIdx.setRequiredTZHourOffset( keepObj->getRequiredTZHourOffset() );
				keyOffsetIdx.setRequiredTZMinOffset( keepObj->getRequiredTZMinOffset() );
				auto searchIndexByOffsetIdx = indexByOffsetIdx->find( keyOffsetIdx );
				if( searchIndexByOffsetIdx != indexByOffsetIdx->end() ) {
					std::map<cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj*>* mapOffsetIdx = searchIndexByOffsetIdx->second;
					if( mapOffsetIdx != NULL ) {
						mapOffsetIdx->insert( std::map< cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj* >::value_type( *(keepObj->getPKey()), aOffsetIdxObj ) );
					}
				}
			}

			if( indexByUTZNameIdx != NULL ) {
				static const std::string S_AUTZNameIdxObj( "aUTZNameIdxObj" );
				cfsec::ICFSecISOTZoneObj* aUTZNameIdxObj =
					dynamic_cast<cfsec::ICFSecISOTZoneObj*>( keepObj );
				if( aUTZNameIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AUTZNameIdxObj );
				}
				cfsec::CFSecISOTZoneByUTZNameIdxKey keyUTZNameIdx;
				keyUTZNameIdx.setRequiredTZName( keepObj->getRequiredTZName() );
				indexByUTZNameIdx->insert( std::map< cfsec::CFSecISOTZoneByUTZNameIdxKey, cfsec::ICFSecISOTZoneObj* >::value_type( keyUTZNameIdx, aUTZNameIdxObj ) );
			}

			if( indexByIso8601Idx != NULL ) {
				static const std::string S_AIso8601IdxObj( "aIso8601IdxObj" );
				cfsec::ICFSecISOTZoneObj* aIso8601IdxObj =
					dynamic_cast<cfsec::ICFSecISOTZoneObj*>( keepObj );
				if( aIso8601IdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AIso8601IdxObj );
				}
				cfsec::CFSecISOTZoneByIso8601IdxKey keyIso8601Idx;
				keyIso8601Idx.setRequiredIso8601( keepObj->getRequiredIso8601() );
				auto searchIndexByIso8601Idx = indexByIso8601Idx->find( keyIso8601Idx );
				if( searchIndexByIso8601Idx != indexByIso8601Idx->end() ) {
					std::map<cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj*>* mapIso8601Idx = searchIndexByIso8601Idx->second;
					if( mapIso8601Idx != NULL ) {
						mapIso8601Idx->insert( std::map< cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj* >::value_type( *(keepObj->getPKey()), aIso8601IdxObj ) );
					}
				}
			}

			if( allISOTZone != NULL ) {
				allISOTZone->insert( std::map< cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
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

	void CFSecISOTZoneTableObj::deepDisposeByIdIdx( const int16_t ISOTZoneId ) {
		static const std::string S_ProcName( "deepDisposeByIdIdx" );
		std::vector<cfsec::ICFSecISOTZoneObj*> list;
		cfsec::ICFSecISOTZoneObj* existingObj = readCachedISOTZoneByIdIdx( ISOTZoneId );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfsec::ICFSecISOTZoneObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecISOTZoneBuff::CLASS_CODE ) {
					dynamic_cast<cfsec::CFSecISOTZoneTableObj*>( schema->getISOTZoneTableObj() )->reallyDeepDisposeISOTZone( dynamic_cast<cfsec::ICFSecISOTZoneObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFSecISOTZoneTableObj::deepDisposeByOffsetIdx( const int16_t TZHourOffset,
			const int16_t TZMinOffset ) {
		static const std::string S_ProcName( "deepDisposeByOffsetIdx" );
		std::vector<cfsec::ICFSecISOTZoneObj*> list;
		std::vector<cfsec::ICFSecISOTZoneObj*> matchesFound = readCachedISOTZoneByOffsetIdx( TZHourOffset,
				TZMinOffset );
		auto iterMatches = matchesFound.begin();
		auto endMatches = matchesFound.end();
		while( iterMatches != endMatches ) {
			if( *iterMatches != NULL ) {
				list.push_back( *iterMatches );
			}
			iterMatches ++;
		}
		cfsec::ICFSecISOTZoneObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecISOTZoneBuff::CLASS_CODE ) {
					dynamic_cast<cfsec::CFSecISOTZoneTableObj*>( schema->getISOTZoneTableObj() )->reallyDeepDisposeISOTZone( dynamic_cast<cfsec::ICFSecISOTZoneObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFSecISOTZoneTableObj::deepDisposeByUTZNameIdx( const std::string& TZName ) {
		static const std::string S_ProcName( "deepDisposeByUTZNameIdx" );
		std::vector<cfsec::ICFSecISOTZoneObj*> list;
		cfsec::ICFSecISOTZoneObj* existingObj = readCachedISOTZoneByUTZNameIdx( TZName );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfsec::ICFSecISOTZoneObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecISOTZoneBuff::CLASS_CODE ) {
					dynamic_cast<cfsec::CFSecISOTZoneTableObj*>( schema->getISOTZoneTableObj() )->reallyDeepDisposeISOTZone( dynamic_cast<cfsec::ICFSecISOTZoneObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFSecISOTZoneTableObj::deepDisposeByIso8601Idx( const std::string& Iso8601 ) {
		static const std::string S_ProcName( "deepDisposeByIso8601Idx" );
		std::vector<cfsec::ICFSecISOTZoneObj*> list;
		std::vector<cfsec::ICFSecISOTZoneObj*> matchesFound = readCachedISOTZoneByIso8601Idx( Iso8601 );
		auto iterMatches = matchesFound.begin();
		auto endMatches = matchesFound.end();
		while( iterMatches != endMatches ) {
			if( *iterMatches != NULL ) {
				list.push_back( *iterMatches );
			}
			iterMatches ++;
		}
		cfsec::ICFSecISOTZoneObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecISOTZoneBuff::CLASS_CODE ) {
					dynamic_cast<cfsec::CFSecISOTZoneTableObj*>( schema->getISOTZoneTableObj() )->reallyDeepDisposeISOTZone( dynamic_cast<cfsec::ICFSecISOTZoneObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFSecISOTZoneTableObj::reallyDeepDisposeISOTZone( cfsec::ICFSecISOTZoneObj* Obj ) {
		static const std::string S_ProcName( "reallyDeepDisposeISOTZone" );

		if( Obj == NULL ) {
			return;
		}

		cfsec::ICFSecISOTZoneObj* obj = Obj;
		
		classcode_t classCode = obj->getClassCode();
		if( classCode == cfsec::CFSecISOTZoneBuff::CLASS_CODE ) {
			dynamic_cast<cfsec::CFSecISOTZoneTableObj*>( schema->getISOTZoneTableObj() )->reallyDetachFromIndexesISOTZone( dynamic_cast<cfsec::ICFSecISOTZoneObj*>( obj ) );
		}

		if( obj->getEdit() != NULL ) {
			obj->endEdit();
		}
		delete obj;
		obj = NULL;
	}

	cfsec::ICFSecISOTZoneObj* CFSecISOTZoneTableObj::createISOTZone( cfsec::ICFSecISOTZoneEditObj* Obj ) {
		static const std::string S_ProcName( "createISOTZone" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Cloneable( "cloneable" );
		static const std::string S_ClonedBuff( "clonedbuff" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecISOTZoneObj* obj = dynamic_cast<cfsec::ICFSecISOTZoneObj*>( Obj->getOrig() );
		try {
			cfsec::CFSecISOTZoneBuff* buff = dynamic_cast<cfsec::CFSecISOTZoneBuff*>( Obj->getBuff()->clone() );
			// C++18 version of create returns a new buffer instance and takes over ownership of the passed-in buffer
			// MSS TODO WORKING The xmsg client will need to return the buffer instance created by processing
			// the response message, while xmsg rqst will have to delete the backing store instance
			// it receives after preparing the reply message so that memory doesn't leak on every request.
			cflib::ICFLibCloneableObj* cloneable = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableISOTZone()->createISOTZone(
				schema->getAuthorization(),
				buff );
			if( cloneable == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Cloneable );
			}
			Obj->endEdit();
			obj->setBuff( dynamic_cast<cfsec::CFSecISOTZoneBuff*>( cloneable ) );
			obj = dynamic_cast<cfsec::ICFSecISOTZoneObj*>( obj->realize() );
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

	cfsec::ICFSecISOTZoneObj* CFSecISOTZoneTableObj::readISOTZone( cfsec::CFSecISOTZonePKey* pkey, bool forceRead ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readISOTZone" );
		cfsec::ICFSecISOTZoneObj* obj = NULL;
		cfsec::ICFSecISOTZoneObj* realized = NULL;
		if( ! forceRead ) {
			auto searchMembers = members->find( *pkey );
			if( searchMembers != members->end() ) {
				// obj could be NULL if cache misses is enabled
				obj = searchMembers->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecISOTZoneBuff* readBuff = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableISOTZone()->readDerivedByIdIdx( schema->getAuthorization(),
			pkey->getRequiredISOTZoneId() );
			if( readBuff != NULL ) {
			obj = dynamic_cast<cfsec::CFSecISOTZoneTableObj*>( schema->getISOTZoneTableObj() )->newInstance();
				obj->setBuff( readBuff );
				realized = dynamic_cast<cfsec::ICFSecISOTZoneObj*>( obj->realize() );
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

	cfsec::ICFSecISOTZoneObj* CFSecISOTZoneTableObj::lockISOTZone( cfsec::CFSecISOTZonePKey* pkey ) {
		static const std::string S_ProcName( "lockISOTZone" );
		cfsec::ICFSecISOTZoneObj* locked = NULL;
		cfsec::CFSecISOTZoneBuff* lockBuff = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableISOTZone()->lockDerived( schema->getAuthorization(), pkey );
		if( lockBuff != NULL ) {
			locked = dynamic_cast<cfsec::CFSecISOTZoneTableObj*>( schema->getISOTZoneTableObj() )->newInstance();
			locked->setBuff( lockBuff );
			locked = dynamic_cast<cfsec::ICFSecISOTZoneObj*>( locked->realize() );
		}
		else {
			return( NULL );
		}
		return( locked );
	}

	std::vector<cfsec::ICFSecISOTZoneObj*> CFSecISOTZoneTableObj::readAllISOTZone( bool forceRead ) {
		static const std::string S_ProcName( "readAllISOTZone" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Realized( "realized" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecISOTZoneObj* realized = NULL;
		if( forceRead || ( allISOTZone == NULL ) ) {
			std::map<cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj*>* map = new std::map<cfsec::CFSecISOTZonePKey,cfsec::ICFSecISOTZoneObj*>();
			allISOTZone = map;
			std::TCFLibOwningVector<cfsec::CFSecISOTZoneBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableISOTZone()->readAllDerived( schema->getAuthorization() );
			cfsec::CFSecISOTZoneBuff* buff = NULL;
			cfsec::ICFSecISOTZoneObj* obj = NULL;
			try {
				for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
					buff = buffList[ idx ];
					buffList[ idx ] = NULL;
				obj = newInstance();
					obj->setBuff( buff );
					realized = dynamic_cast<cfsec::ICFSecISOTZoneObj*>( obj->realize() );
					if( realized == NULL ) {
						throw cflib::CFLibNullArgumentException( CLASS_NAME,
							S_ProcName,
							0,
							S_Realized );
					}
					allISOTZone->insert( std::map< cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj* >::value_type( *(realized->getPKey()), realized ) );
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
		size_t len = allISOTZone->size();
		std::vector<cfsec::ICFSecISOTZoneObj*> arr;
		auto valIter = allISOTZone->begin();
		size_t idx = 0;
		while( valIter != allISOTZone->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	cfsec::ICFSecISOTZoneObj* CFSecISOTZoneTableObj::readISOTZoneByIdIdx( const int16_t ISOTZoneId, bool forceRead )
	{
		static const std::string S_ProcName( "readISOTZoneByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecISOTZonePKey pkey;
		pkey.setRequiredISOTZoneId( ISOTZoneId );
		cfsec::ICFSecISOTZoneObj* obj = readISOTZone( &pkey, forceRead );
		return( obj );
	}

	std::vector<cfsec::ICFSecISOTZoneObj*> CFSecISOTZoneTableObj::readISOTZoneByOffsetIdx( const int16_t TZHourOffset,
			const int16_t TZMinOffset,
		bool forceRead )
	{
		static const std::string S_ProcName( "readISOTZoneByOffsetIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecISOTZoneByOffsetIdxKey key;
		key.setRequiredTZHourOffset( TZHourOffset );
		key.setRequiredTZMinOffset( TZMinOffset );
		std::map<cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj*>* dict;
		std::map<cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj*>* oldDict;
		if( indexByOffsetIdx == NULL ) {
			indexByOffsetIdx = new std::map< cfsec::CFSecISOTZoneByOffsetIdxKey,
				std::map< cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj*>*>();
		}
		auto searchIndexByOffsetIdx = indexByOffsetIdx->find( key );
		if( searchIndexByOffsetIdx != indexByOffsetIdx->end() ) {
			oldDict = searchIndexByOffsetIdx->second;
		}
		else {
			oldDict = NULL;
		}
		if( ( oldDict != NULL ) && ( ! forceRead ) ) {
			dict = oldDict;
		}
		else {
			dict = new std::map<cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj*>();
			cfsec::ICFSecISOTZoneObj* obj;
			std::TCFLibOwningVector<cfsec::CFSecISOTZoneBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableISOTZone()->readDerivedByOffsetIdx( schema->getAuthorization(),
				TZHourOffset,
				TZMinOffset );
			cfsec::CFSecISOTZoneBuff* buff;
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = dynamic_cast<cfsec::CFSecISOTZoneTableObj*>( schema->getISOTZoneTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
				obj->setBuff( buff );
				cfsec::ICFSecISOTZoneObj* realized = dynamic_cast<cfsec::ICFSecISOTZoneObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				dict->insert( std::map< cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj* >::value_type( *(realized->getPKey()), realized ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = NULL;
			}
			if( oldDict != NULL ) {
				indexByOffsetIdx->erase( searchIndexByOffsetIdx );
				delete oldDict;
				oldDict = NULL;
			}
			indexByOffsetIdx->insert( std::map< cfsec::CFSecISOTZoneByOffsetIdxKey,
				std::map< cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj* >* >::value_type( key, dict ) );
		}
		size_t len = dict->size();
		std::vector<cfsec::ICFSecISOTZoneObj*> arr;
		arr.reserve( len );
		auto valIter = dict->begin();
		while( valIter != dict->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	cfsec::ICFSecISOTZoneObj* CFSecISOTZoneTableObj::readISOTZoneByUTZNameIdx( const std::string& TZName, bool forceRead )
	{
		static const std::string S_ProcName( "readISOTZoneByUTZNameIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByUTZNameIdx == NULL ) {
			indexByUTZNameIdx = new std::map< cfsec::CFSecISOTZoneByUTZNameIdxKey,
				cfsec::ICFSecISOTZoneObj*>();
		}
		cfsec::CFSecISOTZoneByUTZNameIdxKey key;
		key.setRequiredTZName( TZName );
		cfsec::ICFSecISOTZoneObj* obj = NULL;
		cfsec::ICFSecISOTZoneObj* realized = NULL;
		if( ! forceRead ) {
			auto searchIndexByUTZNameIdx = indexByUTZNameIdx->find( key );
			if( searchIndexByUTZNameIdx != indexByUTZNameIdx->end() ) {
				// Note: obj may be null if cache misses is enabled
				obj = searchIndexByUTZNameIdx->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecISOTZoneBuff* buff = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableISOTZone()->readDerivedByUTZNameIdx( schema->getAuthorization(),
				TZName );
			if( buff != NULL ) {
				obj = dynamic_cast<cfsec::CFSecISOTZoneTableObj*>( schema->getISOTZoneTableObj() )->newInstance();
				obj->setBuff( buff );
				realized = dynamic_cast<cfsec::ICFSecISOTZoneObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				indexByUTZNameIdx->insert( std::map< cfsec::CFSecISOTZoneByUTZNameIdxKey, cfsec::ICFSecISOTZoneObj*>::value_type( key, dynamic_cast<cfsec::ICFSecISOTZoneObj*>( realized ) ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = realized;
			}
		}
		return( obj );
	}

	std::vector<cfsec::ICFSecISOTZoneObj*> CFSecISOTZoneTableObj::readISOTZoneByIso8601Idx( const std::string& Iso8601,
		bool forceRead )
	{
		static const std::string S_ProcName( "readISOTZoneByIso8601Idx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecISOTZoneByIso8601IdxKey key;
		key.setRequiredIso8601( Iso8601 );
		std::map<cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj*>* dict;
		std::map<cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj*>* oldDict;
		if( indexByIso8601Idx == NULL ) {
			indexByIso8601Idx = new std::map< cfsec::CFSecISOTZoneByIso8601IdxKey,
				std::map< cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj*>*>();
		}
		auto searchIndexByIso8601Idx = indexByIso8601Idx->find( key );
		if( searchIndexByIso8601Idx != indexByIso8601Idx->end() ) {
			oldDict = searchIndexByIso8601Idx->second;
		}
		else {
			oldDict = NULL;
		}
		if( ( oldDict != NULL ) && ( ! forceRead ) ) {
			dict = oldDict;
		}
		else {
			dict = new std::map<cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj*>();
			cfsec::ICFSecISOTZoneObj* obj;
			std::TCFLibOwningVector<cfsec::CFSecISOTZoneBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableISOTZone()->readDerivedByIso8601Idx( schema->getAuthorization(),
				Iso8601 );
			cfsec::CFSecISOTZoneBuff* buff;
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = dynamic_cast<cfsec::CFSecISOTZoneTableObj*>( schema->getISOTZoneTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
				obj->setBuff( buff );
				cfsec::ICFSecISOTZoneObj* realized = dynamic_cast<cfsec::ICFSecISOTZoneObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				dict->insert( std::map< cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj* >::value_type( *(realized->getPKey()), realized ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = NULL;
			}
			if( oldDict != NULL ) {
				indexByIso8601Idx->erase( searchIndexByIso8601Idx );
				delete oldDict;
				oldDict = NULL;
			}
			indexByIso8601Idx->insert( std::map< cfsec::CFSecISOTZoneByIso8601IdxKey,
				std::map< cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj* >* >::value_type( key, dict ) );
		}
		size_t len = dict->size();
		std::vector<cfsec::ICFSecISOTZoneObj*> arr;
		arr.reserve( len );
		auto valIter = dict->begin();
		while( valIter != dict->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	cfsec::ICFSecISOTZoneObj* CFSecISOTZoneTableObj::readISOTZoneByLookupUTZNameIdx( const std::string& TZName, bool forceRead )
	{
		static const std::string S_Realized( "realized" );
		static const std::string S_Obj( "obj" );
		static const std::string S_ProcName( "readISOTZoneByLookupUTZNameIdx" );
		if( indexByUTZNameIdx == NULL ) {
			indexByUTZNameIdx = new std::map< cfsec::CFSecISOTZoneByUTZNameIdxKey,
				cfsec::ICFSecISOTZoneObj*>();
		}
		cfsec::CFSecISOTZoneByUTZNameIdxKey key;
		key.setRequiredTZName( TZName );
		cfsec::ICFSecISOTZoneObj* obj = NULL;
		cfsec::ICFSecISOTZoneObj* realized = NULL;
		if( ! forceRead ) {
			auto searchIndexByUTZNameIdx = indexByUTZNameIdx->find( key );
			if( searchIndexByUTZNameIdx != indexByUTZNameIdx->end() ) {
				obj = searchIndexByUTZNameIdx->second;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecISOTZoneBuff* buff = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableISOTZone()->readDerivedByLookupUTZNameIdx( schema->getAuthorization(),
				TZName );
			if( buff != NULL ) {
				obj = dynamic_cast<cfsec::ICFSecISOTZoneObj*>( dynamic_cast<cfsec::CFSecISOTZoneTableObj*>( schema->getISOTZoneTableObj() )->newInstance() );
				obj->setBuff( buff );
				realized = dynamic_cast<cfsec::ICFSecISOTZoneObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				indexByUTZNameIdx->insert( std::map< cfsec::CFSecISOTZoneByUTZNameIdxKey, cfsec::ICFSecISOTZoneObj*>::value_type( key, dynamic_cast<cfsec::ICFSecISOTZoneObj*>( realized ) ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = realized;
			}
		}
		return( obj );
	}

	cfsec::ICFSecISOTZoneObj* CFSecISOTZoneTableObj::readCachedISOTZone( cfsec::CFSecISOTZonePKey* pkey ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readISOTZone" );
		cfsec::ICFSecISOTZoneObj* obj = NULL;
		cfsec::ICFSecISOTZoneObj* realized = NULL;
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			// obj could be NULL if cache misses is enabled
			obj = searchMembers->second;
			realized = obj;
		}
		return( realized );
	}

	cfsec::ICFSecISOTZoneObj* CFSecISOTZoneTableObj::readCachedISOTZoneByIdIdx( const int16_t ISOTZoneId )
	{
		static const std::string S_ProcName( "readCachedISOTZoneByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecISOTZonePKey pkey;
		pkey.setRequiredISOTZoneId( ISOTZoneId );
		cfsec::ICFSecISOTZoneObj* obj = readCachedISOTZone( &pkey );
		return( obj );
	}

	std::vector<cfsec::ICFSecISOTZoneObj*> CFSecISOTZoneTableObj::readCachedISOTZoneByOffsetIdx( const int16_t TZHourOffset,
			const int16_t TZMinOffset )
	{
		static const std::string S_ProcName( "readCachedISOTZoneByOffsetIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		std::vector<cfsec::ICFSecISOTZoneObj*> arr;
		cfsec::CFSecISOTZoneByOffsetIdxKey key;
		key.setRequiredTZHourOffset( TZHourOffset );
		key.setRequiredTZMinOffset( TZMinOffset );
		std::map<cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj*>* dict;
		if( indexByOffsetIdx == NULL ) {
			return( arr );
		}
		auto searchIndexByOffsetIdx = indexByOffsetIdx->find( key );
		if( searchIndexByOffsetIdx != indexByOffsetIdx->end() ) {
			dict = searchIndexByOffsetIdx->second;
			size_t len = dict->size();
			std::vector<cfsec::ICFSecISOTZoneObj*> arr;
			arr.reserve( len );
			auto valIter = dict->begin();
			while( valIter != dict->end() ) {
				arr.push_back( valIter->second );
				valIter ++;
			}
		}
		else {
			cfsec::ICFSecISOTZoneObj* obj;
			for( auto iterMembers = members->begin(); iterMembers != members->end(); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecISOTZoneBuff*>( obj->getBuff() ) ) == key ) {
						arr.push_back( obj );
					}
				}
			}
		}
		return( arr );
	}

	cfsec::ICFSecISOTZoneObj* CFSecISOTZoneTableObj::readCachedISOTZoneByUTZNameIdx( const std::string& TZName )
	{
		static const std::string S_ProcName( "readCachedISOTZoneByUTZNameIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByUTZNameIdx == NULL ) {
			indexByUTZNameIdx = new std::map< cfsec::CFSecISOTZoneByUTZNameIdxKey,
				cfsec::ICFSecISOTZoneObj*>();
		}
		cfsec::CFSecISOTZoneByUTZNameIdxKey key;
		key.setRequiredTZName( TZName );
		cfsec::ICFSecISOTZoneObj* obj = NULL;
		auto searchIndexByUTZNameIdx = indexByUTZNameIdx->find( key );
		if( searchIndexByUTZNameIdx != indexByUTZNameIdx->end() ) {
			// Note: obj may be null if cache misses is enabled
			obj = searchIndexByUTZNameIdx->second;
		}
		else {
			for( auto iterMembers = members->begin(); ( obj == NULL ) && ( iterMembers != members->end() ); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecISOTZoneBuff*>( obj->getBuff() ) ) != key ) {
						obj = NULL;
					}
				}
			}
		}
		return( obj );
	}

	std::vector<cfsec::ICFSecISOTZoneObj*> CFSecISOTZoneTableObj::readCachedISOTZoneByIso8601Idx( const std::string& Iso8601 )
	{
		static const std::string S_ProcName( "readCachedISOTZoneByIso8601Idx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		std::vector<cfsec::ICFSecISOTZoneObj*> arr;
		cfsec::CFSecISOTZoneByIso8601IdxKey key;
		key.setRequiredIso8601( Iso8601 );
		std::map<cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj*>* dict;
		if( indexByIso8601Idx == NULL ) {
			return( arr );
		}
		auto searchIndexByIso8601Idx = indexByIso8601Idx->find( key );
		if( searchIndexByIso8601Idx != indexByIso8601Idx->end() ) {
			dict = searchIndexByIso8601Idx->second;
			size_t len = dict->size();
			std::vector<cfsec::ICFSecISOTZoneObj*> arr;
			arr.reserve( len );
			auto valIter = dict->begin();
			while( valIter != dict->end() ) {
				arr.push_back( valIter->second );
				valIter ++;
			}
		}
		else {
			cfsec::ICFSecISOTZoneObj* obj;
			for( auto iterMembers = members->begin(); iterMembers != members->end(); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecISOTZoneBuff*>( obj->getBuff() ) ) == key ) {
						arr.push_back( obj );
					}
				}
			}
		}
		return( arr );
	}

	cfsec::ICFSecISOTZoneObj* CFSecISOTZoneTableObj::readCachedISOTZoneByLookupUTZNameIdx( const std::string& TZName )
	{
		static const std::string S_Realized( "realized" );
		static const std::string S_Obj( "obj" );
		static const std::string S_ProcName( "readCachedISOTZoneByLookupUTZNameIdx" );
		if( indexByUTZNameIdx == NULL ) {
			indexByUTZNameIdx = new std::map< cfsec::CFSecISOTZoneByUTZNameIdxKey,
				cfsec::ICFSecISOTZoneObj*>();
		}
		cfsec::CFSecISOTZoneByUTZNameIdxKey key;
		key.setRequiredTZName( TZName );
		cfsec::ICFSecISOTZoneObj* obj = NULL;
		cfsec::ICFSecISOTZoneObj* realized = NULL;
		auto searchIndexByUTZNameIdx = indexByUTZNameIdx->find( key );
		if( searchIndexByUTZNameIdx != indexByUTZNameIdx->end() ) {
			obj = searchIndexByUTZNameIdx->second;
		}
		else {
			for( auto iterMembers = members->begin(); ( obj == NULL ) && ( iterMembers != members->end() ); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecISOTZoneBuff*>( obj->getBuff() ) ) != key ) {
						obj = NULL;
					}
				}
			}
		}
		return( obj );
	}

	cfsec::ICFSecISOTZoneObj* CFSecISOTZoneTableObj::updateISOTZone( cfsec::ICFSecISOTZoneEditObj* Obj ) {
		static const std::string S_ProcName( "updateISOTZone" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Updated( "updated" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecISOTZoneObj* obj = dynamic_cast<cfsec::ICFSecISOTZoneObj*>( Obj->getOrig() );
		try {
			cfsec::CFSecISOTZoneBuff* updated = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableISOTZone()->updateISOTZone( schema->getAuthorization(),
				dynamic_cast<cfsec::CFSecISOTZoneBuff*>( Obj->getISOTZoneBuff()->clone() ) );
			if( updated == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Updated );
			}
			obj = dynamic_cast<cfsec::ICFSecISOTZoneObj*>( dynamic_cast<cfsec::CFSecISOTZoneTableObj*>( schema->getISOTZoneTableObj() )->newInstance() );
			obj->setBuff( updated );
			obj = dynamic_cast<cfsec::ICFSecISOTZoneObj*>( obj->realize() );
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

	void CFSecISOTZoneTableObj::deleteISOTZone( cfsec::ICFSecISOTZoneEditObj* Obj ) {
		cfsec::ICFSecISOTZoneObj* obj = Obj;
		dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableISOTZone()->deleteISOTZone( schema->getAuthorization(),
			obj->getISOTZoneBuff() );
		deepDisposeByIdIdx( obj->getRequiredISOTZoneId() );
	}

	void CFSecISOTZoneTableObj::deleteISOTZoneByIdIdx( const int16_t ISOTZoneId )
	{
		cfsec::CFSecISOTZonePKey pkey;
		pkey.setRequiredISOTZoneId( ISOTZoneId );
		cfsec::ICFSecISOTZoneObj* obj = readISOTZone( &pkey, true );
		if( obj != NULL ) {
			cfsec::ICFSecISOTZoneEditObj* editObj = dynamic_cast<cfsec::ICFSecISOTZoneEditObj*>( obj->getEdit() );
			if( editObj == NULL ) {
				editObj = dynamic_cast<cfsec::ICFSecISOTZoneEditObj*>( obj->beginEdit() );
			}
			if( editObj != NULL ) {
				editObj->deleteInstance();
				editObj = NULL;
			}
		}
	}

	void CFSecISOTZoneTableObj::deleteISOTZoneByOffsetIdx( const int16_t TZHourOffset,
			const int16_t TZMinOffset )
	{
		dynamic_cast<cfsec::ICFSecSchema*>( schema->getBackingStore() )->getTableISOTZone()->deleteISOTZoneByOffsetIdx( schema->getAuthorization(),
				TZHourOffset,
				TZMinOffset );
		deepDisposeByOffsetIdx( TZHourOffset,
			TZMinOffset );
	}

	void CFSecISOTZoneTableObj::deleteISOTZoneByUTZNameIdx( const std::string& TZName )
	{
		if( indexByUTZNameIdx == NULL ) {
			indexByUTZNameIdx = new std::map< cfsec::CFSecISOTZoneByUTZNameIdxKey,
				cfsec::ICFSecISOTZoneObj*>();
		}
		cfsec::CFSecISOTZoneByUTZNameIdxKey key;
		key.setRequiredTZName( TZName );
		cfsec::ICFSecISOTZoneObj* obj = NULL;
		auto searchIndexByUTZNameIdx = indexByUTZNameIdx->find( key );
		if( searchIndexByUTZNameIdx != indexByUTZNameIdx->end() ) {
			dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableISOTZone()->deleteISOTZoneByUTZNameIdx( schema->getAuthorization(),
				TZName );
		}
		else {
			dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableISOTZone()->deleteISOTZoneByUTZNameIdx( schema->getAuthorization(),
				TZName );
		}
		deepDisposeByUTZNameIdx( TZName );
	}

	void CFSecISOTZoneTableObj::deleteISOTZoneByIso8601Idx( const std::string& Iso8601 )
	{
		dynamic_cast<cfsec::ICFSecSchema*>( schema->getBackingStore() )->getTableISOTZone()->deleteISOTZoneByIso8601Idx( schema->getAuthorization(),
				Iso8601 );
		deepDisposeByIso8601Idx( Iso8601 );
	}

	void CFSecISOTZoneTableObj::reallyDetachFromIndexesISOTZone( cfsec::ICFSecISOTZoneObj* Obj ) {
		static const std::string S_ProcName( "reallyDetachFromIndexesISOTZone" );
		static const std::string S_Obj( "Obj" );
		static const std::string S_ExistingObj( "ExistingObj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfsec::ICFSecISOTZoneObj* obj = Obj;
		cfsec::CFSecISOTZonePKey* pkey = obj->getPKey();
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			cfsec::ICFSecISOTZoneObj* existingObj = searchMembers->second;
			if( existingObj == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_ExistingObj );
			}
			if( indexByOffsetIdx != NULL ) {
				cfsec::CFSecISOTZoneByOffsetIdxKey keyOffsetIdx;
				keyOffsetIdx.setRequiredTZHourOffset( obj->getRequiredTZHourOffset() );
				keyOffsetIdx.setRequiredTZMinOffset( obj->getRequiredTZMinOffset() );
				auto searchOffsetIdx = indexByOffsetIdx->find( keyOffsetIdx );
				if( searchOffsetIdx != indexByOffsetIdx->end() ) {
					std::map<cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj*>* mapOffsetIdx = searchOffsetIdx->second;
					if( mapOffsetIdx != NULL ) {
						auto removalProbe = mapOffsetIdx->find( *(obj->getPKey()) );
						if( removalProbe != mapOffsetIdx->end() ) {
							mapOffsetIdx->erase( removalProbe );
							if( mapOffsetIdx->empty() ) {
								delete mapOffsetIdx;
								mapOffsetIdx = NULL;
								indexByOffsetIdx->erase( searchOffsetIdx );
							}
						}
					}
				}
			}

			if( indexByUTZNameIdx != NULL ) {
				cfsec::CFSecISOTZoneByUTZNameIdxKey keyUTZNameIdx;
				keyUTZNameIdx.setRequiredTZName( obj->getRequiredTZName() );
				auto removalProbe = indexByUTZNameIdx->find( keyUTZNameIdx );
				if( removalProbe != indexByUTZNameIdx->end() ) {
					indexByUTZNameIdx->erase( removalProbe );
				}
			}

			if( indexByIso8601Idx != NULL ) {
				cfsec::CFSecISOTZoneByIso8601IdxKey keyIso8601Idx;
				keyIso8601Idx.setRequiredIso8601( obj->getRequiredIso8601() );
				auto searchIso8601Idx = indexByIso8601Idx->find( keyIso8601Idx );
				if( searchIso8601Idx != indexByIso8601Idx->end() ) {
					std::map<cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj*>* mapIso8601Idx = searchIso8601Idx->second;
					if( mapIso8601Idx != NULL ) {
						auto removalProbe = mapIso8601Idx->find( *(obj->getPKey()) );
						if( removalProbe != mapIso8601Idx->end() ) {
							mapIso8601Idx->erase( removalProbe );
							if( mapIso8601Idx->empty() ) {
								delete mapIso8601Idx;
								mapIso8601Idx = NULL;
								indexByIso8601Idx->erase( searchIso8601Idx );
							}
						}
					}
				}
			}

			members->erase( searchMembers );
		}
	}


}
