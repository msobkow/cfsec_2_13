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

	const std::string CFSecISOCtryTableObj::CLASS_NAME( "CFSecISOCtryTableObj" );
	const std::string CFSecISOCtryTableObj::TABLE_NAME( "ISOCtry" );
	const std::string CFSecISOCtryTableObj::TABLE_DBNAME( "iso_cntry" );

	CFSecISOCtryTableObj::CFSecISOCtryTableObj() {
		schema = NULL;
		members = new std::map<cfsec::CFSecISOCtryPKey, cfsec::ICFSecISOCtryObj*>();
		allISOCtry = NULL;
		indexByISOCodeIdx = new std::map< cfsec::CFSecISOCtryByISOCodeIdxKey,
			cfsec::ICFSecISOCtryObj*>();
		indexByNameIdx = new std::map< cfsec::CFSecISOCtryByNameIdxKey,
			cfsec::ICFSecISOCtryObj*>();
	}

	CFSecISOCtryTableObj::CFSecISOCtryTableObj( cfsec::ICFSecSchemaObj* argSchema ) {
		schema = dynamic_cast<cfsec::ICFSecSchemaObj*>( argSchema );
		members = new std::map<cfsec::CFSecISOCtryPKey, cfsec::ICFSecISOCtryObj*>();
		allISOCtry = NULL;
		indexByISOCodeIdx = new std::map< cfsec::CFSecISOCtryByISOCodeIdxKey,
			cfsec::ICFSecISOCtryObj*>();
		indexByNameIdx = new std::map< cfsec::CFSecISOCtryByNameIdxKey,
			cfsec::ICFSecISOCtryObj*>();
	}

	CFSecISOCtryTableObj::~CFSecISOCtryTableObj() {
		minimizeMemory();
		if( indexByISOCodeIdx != NULL ) {
			delete indexByISOCodeIdx;
			indexByISOCodeIdx = NULL;
		}
		if( indexByNameIdx != NULL ) {
			delete indexByNameIdx;
			indexByNameIdx = NULL;
		}
		if( members != NULL ) {
			cfsec::ICFSecISOCtryObj* curMember;
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

	cfsec::ICFSecSchemaObj* CFSecISOCtryTableObj::getSchema() {
		return( schema );
	}

	void CFSecISOCtryTableObj::setSchema( cfsec::ICFSecSchemaObj* value ) {
		schema = dynamic_cast<cfsec::ICFSecSchemaObj*>( value );
	}

	const std::string CFSecISOCtryTableObj::getTableName() {
		return( TABLE_NAME );
	}

	const std::string CFSecISOCtryTableObj::getTableDbName() {
		return( TABLE_DBNAME );
	}
	const classcode_t* CFSecISOCtryTableObj::getObjQualifyingClassCode() {
		return( NULL );
	}


	void CFSecISOCtryTableObj::minimizeMemory() {
		if( allISOCtry != NULL ) {
			allISOCtry->clear();
			delete allISOCtry;
			allISOCtry = NULL;
		}
		if( indexByISOCodeIdx != NULL ) {
			indexByISOCodeIdx->clear();
		}
		if( indexByNameIdx != NULL ) {
			indexByNameIdx->clear();
		}
		if( members != NULL ) {
			cfsec::ICFSecISOCtryObj* cur = NULL;
			cfsec::ICFSecISOCtryEditObj* edit = NULL;
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

	cfsec::ICFSecISOCtryObj* CFSecISOCtryTableObj::newInstance() {
		cfsec::ICFSecISOCtryObj* inst = dynamic_cast<cfsec::ICFSecISOCtryObj*>( new CFSecISOCtryObj( schema ) );
		return( inst );
	}

	cfsec::ICFSecISOCtryEditObj* CFSecISOCtryTableObj::newEditInstance( cfsec::ICFSecISOCtryObj* orig ) {
		cfsec::ICFSecISOCtryEditObj* edit = dynamic_cast<cfsec::ICFSecISOCtryEditObj*>( new CFSecISOCtryEditObj( orig ));
		return( edit );
	}

	cfsec::ICFSecISOCtryObj* CFSecISOCtryTableObj::realizeISOCtry( cfsec::ICFSecISOCtryObj* Obj ) {
		static const std::string S_ProcName( "realizeISOCtry" );
		static const std::string S_ExistingObj( "existingObj" );
		static const std::string S_KeepObj( "keepObj" );
		static const std::string S_Obj( "Obj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfsec::ICFSecISOCtryObj* obj = Obj;
		cfsec::ICFSecISOCtryObj* existingObj = NULL;
		cfsec::CFSecISOCtryPKey* pkey = obj->getPKey();
		cfsec::ICFSecISOCtryObj* keepObj = NULL;
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
			if( indexByISOCodeIdx != NULL ) {
				cfsec::CFSecISOCtryByISOCodeIdxKey keyISOCodeIdx;
				keyISOCodeIdx.setRequiredISOCode( keepObj->getRequiredISOCode() );
				auto removalProbe = indexByISOCodeIdx->find( keyISOCodeIdx );
				if( removalProbe != indexByISOCodeIdx->end() ) {
					indexByISOCodeIdx->erase( removalProbe );
				}
			}

			if( indexByNameIdx != NULL ) {
				cfsec::CFSecISOCtryByNameIdxKey keyNameIdx;
				keyNameIdx.setRequiredName( keepObj->getRequiredName() );
				auto removalProbe = indexByNameIdx->find( keyNameIdx );
				if( removalProbe != indexByNameIdx->end() ) {
					indexByNameIdx->erase( removalProbe );
				}
			}

			keepObj->setBuff( dynamic_cast<cfsec::CFSecISOCtryBuff*>( Obj->getBuff()->clone() ) );
			// Attach new object to alternate and duplicate indexes -- PKey stays stable

			if( indexByISOCodeIdx != NULL ) {
				static const std::string S_AISOCodeIdxObj( "aISOCodeIdxObj" );
				cfsec::ICFSecISOCtryObj* aISOCodeIdxObj =
					dynamic_cast<cfsec::ICFSecISOCtryObj*>( keepObj );
				if( aISOCodeIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AISOCodeIdxObj );
				}
				cfsec::CFSecISOCtryByISOCodeIdxKey keyISOCodeIdx;
				keyISOCodeIdx.setRequiredISOCode( keepObj->getRequiredISOCode() );
				indexByISOCodeIdx->insert( std::map< cfsec::CFSecISOCtryByISOCodeIdxKey, cfsec::ICFSecISOCtryObj* >::value_type( keyISOCodeIdx, aISOCodeIdxObj ) );
			}

			if( indexByNameIdx != NULL ) {
				static const std::string S_ANameIdxObj( "aNameIdxObj" );
				cfsec::ICFSecISOCtryObj* aNameIdxObj =
					dynamic_cast<cfsec::ICFSecISOCtryObj*>( keepObj );
				if( aNameIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ANameIdxObj );
				}
				cfsec::CFSecISOCtryByNameIdxKey keyNameIdx;
				keyNameIdx.setRequiredName( keepObj->getRequiredName() );
				indexByNameIdx->insert( std::map< cfsec::CFSecISOCtryByNameIdxKey, cfsec::ICFSecISOCtryObj* >::value_type( keyNameIdx, aNameIdxObj ) );
			}

			if( allISOCtry != NULL ) {
				allISOCtry->insert( std::map< cfsec::CFSecISOCtryPKey, cfsec::ICFSecISOCtryObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			}
		}
		else {
			keepObj = obj;
			keepObj->setIsNew( false );
			pkey = keepObj->getPKey();
			// Attach new object to PKey, all, alternate, and duplicate indexes
			members->insert( std::map< cfsec::CFSecISOCtryPKey, cfsec::ICFSecISOCtryObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			// Attach new object to alternate and duplicate indexes -- PKey stay stable

			if( indexByISOCodeIdx != NULL ) {
				static const std::string S_AISOCodeIdxObj( "aISOCodeIdxObj" );
				cfsec::ICFSecISOCtryObj* aISOCodeIdxObj =
					dynamic_cast<cfsec::ICFSecISOCtryObj*>( keepObj );
				if( aISOCodeIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AISOCodeIdxObj );
				}
				cfsec::CFSecISOCtryByISOCodeIdxKey keyISOCodeIdx;
				keyISOCodeIdx.setRequiredISOCode( keepObj->getRequiredISOCode() );
				indexByISOCodeIdx->insert( std::map< cfsec::CFSecISOCtryByISOCodeIdxKey, cfsec::ICFSecISOCtryObj* >::value_type( keyISOCodeIdx, aISOCodeIdxObj ) );
			}

			if( indexByNameIdx != NULL ) {
				static const std::string S_ANameIdxObj( "aNameIdxObj" );
				cfsec::ICFSecISOCtryObj* aNameIdxObj =
					dynamic_cast<cfsec::ICFSecISOCtryObj*>( keepObj );
				if( aNameIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ANameIdxObj );
				}
				cfsec::CFSecISOCtryByNameIdxKey keyNameIdx;
				keyNameIdx.setRequiredName( keepObj->getRequiredName() );
				indexByNameIdx->insert( std::map< cfsec::CFSecISOCtryByNameIdxKey, cfsec::ICFSecISOCtryObj* >::value_type( keyNameIdx, aNameIdxObj ) );
			}

			if( allISOCtry != NULL ) {
				allISOCtry->insert( std::map< cfsec::CFSecISOCtryPKey, cfsec::ICFSecISOCtryObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
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

	void CFSecISOCtryTableObj::deepDisposeByIdIdx( const int16_t ISOCtryId ) {
		static const std::string S_ProcName( "deepDisposeByIdIdx" );
		std::vector<cfsec::ICFSecISOCtryObj*> list;
		cfsec::ICFSecISOCtryObj* existingObj = readCachedISOCtryByIdIdx( ISOCtryId );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfsec::ICFSecISOCtryObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecISOCtryBuff::CLASS_CODE ) {
					dynamic_cast<cfsec::CFSecISOCtryTableObj*>( schema->getISOCtryTableObj() )->reallyDeepDisposeISOCtry( dynamic_cast<cfsec::ICFSecISOCtryObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFSecISOCtryTableObj::deepDisposeByISOCodeIdx( const std::string& ISOCode ) {
		static const std::string S_ProcName( "deepDisposeByISOCodeIdx" );
		std::vector<cfsec::ICFSecISOCtryObj*> list;
		cfsec::ICFSecISOCtryObj* existingObj = readCachedISOCtryByISOCodeIdx( ISOCode );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfsec::ICFSecISOCtryObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecISOCtryBuff::CLASS_CODE ) {
					dynamic_cast<cfsec::CFSecISOCtryTableObj*>( schema->getISOCtryTableObj() )->reallyDeepDisposeISOCtry( dynamic_cast<cfsec::ICFSecISOCtryObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFSecISOCtryTableObj::deepDisposeByNameIdx( const std::string& Name ) {
		static const std::string S_ProcName( "deepDisposeByNameIdx" );
		std::vector<cfsec::ICFSecISOCtryObj*> list;
		cfsec::ICFSecISOCtryObj* existingObj = readCachedISOCtryByNameIdx( Name );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfsec::ICFSecISOCtryObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecISOCtryBuff::CLASS_CODE ) {
					dynamic_cast<cfsec::CFSecISOCtryTableObj*>( schema->getISOCtryTableObj() )->reallyDeepDisposeISOCtry( dynamic_cast<cfsec::ICFSecISOCtryObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFSecISOCtryTableObj::reallyDeepDisposeISOCtry( cfsec::ICFSecISOCtryObj* Obj ) {
		static const std::string S_ProcName( "reallyDeepDisposeISOCtry" );

		if( Obj == NULL ) {
			return;
		}

		cfsec::ICFSecISOCtryObj* obj = Obj;
		
		dynamic_cast<cfsec::CFSecISOCtryLangTableObj*>( schema->getISOCtryLangTableObj() )->deepDisposeByCtryIdx( obj->getRequiredISOCtryId() );
		dynamic_cast<cfsec::CFSecISOCtryCcyTableObj*>( schema->getISOCtryCcyTableObj() )->deepDisposeByCtryIdx( obj->getRequiredISOCtryId() );
		classcode_t classCode = obj->getClassCode();
		if( classCode == cfsec::CFSecISOCtryBuff::CLASS_CODE ) {
			dynamic_cast<cfsec::CFSecISOCtryTableObj*>( schema->getISOCtryTableObj() )->reallyDetachFromIndexesISOCtry( dynamic_cast<cfsec::ICFSecISOCtryObj*>( obj ) );
		}

		if( obj->getEdit() != NULL ) {
			obj->endEdit();
		}
		delete obj;
		obj = NULL;
	}

	cfsec::ICFSecISOCtryObj* CFSecISOCtryTableObj::createISOCtry( cfsec::ICFSecISOCtryEditObj* Obj ) {
		static const std::string S_ProcName( "createISOCtry" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Cloneable( "cloneable" );
		static const std::string S_ClonedBuff( "clonedbuff" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecISOCtryObj* obj = dynamic_cast<cfsec::ICFSecISOCtryObj*>( Obj->getOrig() );
		try {
			cfsec::CFSecISOCtryBuff* buff = dynamic_cast<cfsec::CFSecISOCtryBuff*>( Obj->getBuff()->clone() );
			// C++18 version of create returns a new buffer instance and takes over ownership of the passed-in buffer
			// MSS TODO WORKING The xmsg client will need to return the buffer instance created by processing
			// the response message, while xmsg rqst will have to delete the backing store instance
			// it receives after preparing the reply message so that memory doesn't leak on every request.
			cflib::ICFLibCloneableObj* cloneable = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableISOCtry()->createISOCtry(
				schema->getAuthorization(),
				buff );
			if( cloneable == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Cloneable );
			}
			Obj->endEdit();
			obj->setBuff( dynamic_cast<cfsec::CFSecISOCtryBuff*>( cloneable ) );
			obj = dynamic_cast<cfsec::ICFSecISOCtryObj*>( obj->realize() );
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

	cfsec::ICFSecISOCtryObj* CFSecISOCtryTableObj::readISOCtry( cfsec::CFSecISOCtryPKey* pkey, bool forceRead ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readISOCtry" );
		cfsec::ICFSecISOCtryObj* obj = NULL;
		cfsec::ICFSecISOCtryObj* realized = NULL;
		if( ! forceRead ) {
			auto searchMembers = members->find( *pkey );
			if( searchMembers != members->end() ) {
				// obj could be NULL if cache misses is enabled
				obj = searchMembers->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecISOCtryBuff* readBuff = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableISOCtry()->readDerivedByIdIdx( schema->getAuthorization(),
			pkey->getRequiredISOCtryId() );
			if( readBuff != NULL ) {
			obj = dynamic_cast<cfsec::CFSecISOCtryTableObj*>( schema->getISOCtryTableObj() )->newInstance();
				obj->setBuff( readBuff );
				realized = dynamic_cast<cfsec::ICFSecISOCtryObj*>( obj->realize() );
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

	cfsec::ICFSecISOCtryObj* CFSecISOCtryTableObj::lockISOCtry( cfsec::CFSecISOCtryPKey* pkey ) {
		static const std::string S_ProcName( "lockISOCtry" );
		cfsec::ICFSecISOCtryObj* locked = NULL;
		cfsec::CFSecISOCtryBuff* lockBuff = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableISOCtry()->lockDerived( schema->getAuthorization(), pkey );
		if( lockBuff != NULL ) {
			locked = dynamic_cast<cfsec::CFSecISOCtryTableObj*>( schema->getISOCtryTableObj() )->newInstance();
			locked->setBuff( lockBuff );
			locked = dynamic_cast<cfsec::ICFSecISOCtryObj*>( locked->realize() );
		}
		else {
			return( NULL );
		}
		return( locked );
	}

	std::vector<cfsec::ICFSecISOCtryObj*> CFSecISOCtryTableObj::readAllISOCtry( bool forceRead ) {
		static const std::string S_ProcName( "readAllISOCtry" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Realized( "realized" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecISOCtryObj* realized = NULL;
		if( forceRead || ( allISOCtry == NULL ) ) {
			std::map<cfsec::CFSecISOCtryPKey, cfsec::ICFSecISOCtryObj*>* map = new std::map<cfsec::CFSecISOCtryPKey,cfsec::ICFSecISOCtryObj*>();
			allISOCtry = map;
			std::TCFLibOwningVector<cfsec::CFSecISOCtryBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableISOCtry()->readAllDerived( schema->getAuthorization() );
			cfsec::CFSecISOCtryBuff* buff = NULL;
			cfsec::ICFSecISOCtryObj* obj = NULL;
			try {
				for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
					buff = buffList[ idx ];
					buffList[ idx ] = NULL;
				obj = newInstance();
					obj->setBuff( buff );
					realized = dynamic_cast<cfsec::ICFSecISOCtryObj*>( obj->realize() );
					if( realized == NULL ) {
						throw cflib::CFLibNullArgumentException( CLASS_NAME,
							S_ProcName,
							0,
							S_Realized );
					}
					allISOCtry->insert( std::map< cfsec::CFSecISOCtryPKey, cfsec::ICFSecISOCtryObj* >::value_type( *(realized->getPKey()), realized ) );
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
		size_t len = allISOCtry->size();
		std::vector<cfsec::ICFSecISOCtryObj*> arr;
		auto valIter = allISOCtry->begin();
		size_t idx = 0;
		while( valIter != allISOCtry->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	cfsec::ICFSecISOCtryObj* CFSecISOCtryTableObj::readISOCtryByIdIdx( const int16_t ISOCtryId, bool forceRead )
	{
		static const std::string S_ProcName( "readISOCtryByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecISOCtryPKey pkey;
		pkey.setRequiredISOCtryId( ISOCtryId );
		cfsec::ICFSecISOCtryObj* obj = readISOCtry( &pkey, forceRead );
		return( obj );
	}

	cfsec::ICFSecISOCtryObj* CFSecISOCtryTableObj::readISOCtryByISOCodeIdx( const std::string& ISOCode, bool forceRead )
	{
		static const std::string S_ProcName( "readISOCtryByISOCodeIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByISOCodeIdx == NULL ) {
			indexByISOCodeIdx = new std::map< cfsec::CFSecISOCtryByISOCodeIdxKey,
				cfsec::ICFSecISOCtryObj*>();
		}
		cfsec::CFSecISOCtryByISOCodeIdxKey key;
		key.setRequiredISOCode( ISOCode );
		cfsec::ICFSecISOCtryObj* obj = NULL;
		cfsec::ICFSecISOCtryObj* realized = NULL;
		if( ! forceRead ) {
			auto searchIndexByISOCodeIdx = indexByISOCodeIdx->find( key );
			if( searchIndexByISOCodeIdx != indexByISOCodeIdx->end() ) {
				// Note: obj may be null if cache misses is enabled
				obj = searchIndexByISOCodeIdx->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecISOCtryBuff* buff = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableISOCtry()->readDerivedByISOCodeIdx( schema->getAuthorization(),
				ISOCode );
			if( buff != NULL ) {
				obj = dynamic_cast<cfsec::CFSecISOCtryTableObj*>( schema->getISOCtryTableObj() )->newInstance();
				obj->setBuff( buff );
				realized = dynamic_cast<cfsec::ICFSecISOCtryObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				indexByISOCodeIdx->insert( std::map< cfsec::CFSecISOCtryByISOCodeIdxKey, cfsec::ICFSecISOCtryObj*>::value_type( key, dynamic_cast<cfsec::ICFSecISOCtryObj*>( realized ) ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = realized;
			}
		}
		return( obj );
	}

	cfsec::ICFSecISOCtryObj* CFSecISOCtryTableObj::readISOCtryByNameIdx( const std::string& Name, bool forceRead )
	{
		static const std::string S_ProcName( "readISOCtryByNameIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByNameIdx == NULL ) {
			indexByNameIdx = new std::map< cfsec::CFSecISOCtryByNameIdxKey,
				cfsec::ICFSecISOCtryObj*>();
		}
		cfsec::CFSecISOCtryByNameIdxKey key;
		key.setRequiredName( Name );
		cfsec::ICFSecISOCtryObj* obj = NULL;
		cfsec::ICFSecISOCtryObj* realized = NULL;
		if( ! forceRead ) {
			auto searchIndexByNameIdx = indexByNameIdx->find( key );
			if( searchIndexByNameIdx != indexByNameIdx->end() ) {
				// Note: obj may be null if cache misses is enabled
				obj = searchIndexByNameIdx->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecISOCtryBuff* buff = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableISOCtry()->readDerivedByNameIdx( schema->getAuthorization(),
				Name );
			if( buff != NULL ) {
				obj = dynamic_cast<cfsec::CFSecISOCtryTableObj*>( schema->getISOCtryTableObj() )->newInstance();
				obj->setBuff( buff );
				realized = dynamic_cast<cfsec::ICFSecISOCtryObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				indexByNameIdx->insert( std::map< cfsec::CFSecISOCtryByNameIdxKey, cfsec::ICFSecISOCtryObj*>::value_type( key, dynamic_cast<cfsec::ICFSecISOCtryObj*>( realized ) ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = realized;
			}
		}
		return( obj );
	}

	cfsec::ICFSecISOCtryObj* CFSecISOCtryTableObj::readISOCtryByLookupISOCodeIdx( const std::string& ISOCode, bool forceRead )
	{
		static const std::string S_Realized( "realized" );
		static const std::string S_Obj( "obj" );
		static const std::string S_ProcName( "readISOCtryByLookupISOCodeIdx" );
		if( indexByISOCodeIdx == NULL ) {
			indexByISOCodeIdx = new std::map< cfsec::CFSecISOCtryByISOCodeIdxKey,
				cfsec::ICFSecISOCtryObj*>();
		}
		cfsec::CFSecISOCtryByISOCodeIdxKey key;
		key.setRequiredISOCode( ISOCode );
		cfsec::ICFSecISOCtryObj* obj = NULL;
		cfsec::ICFSecISOCtryObj* realized = NULL;
		if( ! forceRead ) {
			auto searchIndexByISOCodeIdx = indexByISOCodeIdx->find( key );
			if( searchIndexByISOCodeIdx != indexByISOCodeIdx->end() ) {
				obj = searchIndexByISOCodeIdx->second;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecISOCtryBuff* buff = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableISOCtry()->readDerivedByLookupISOCodeIdx( schema->getAuthorization(),
				ISOCode );
			if( buff != NULL ) {
				obj = dynamic_cast<cfsec::ICFSecISOCtryObj*>( dynamic_cast<cfsec::CFSecISOCtryTableObj*>( schema->getISOCtryTableObj() )->newInstance() );
				obj->setBuff( buff );
				realized = dynamic_cast<cfsec::ICFSecISOCtryObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				indexByISOCodeIdx->insert( std::map< cfsec::CFSecISOCtryByISOCodeIdxKey, cfsec::ICFSecISOCtryObj*>::value_type( key, dynamic_cast<cfsec::ICFSecISOCtryObj*>( realized ) ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = realized;
			}
		}
		return( obj );
	}

	cfsec::ICFSecISOCtryObj* CFSecISOCtryTableObj::readCachedISOCtry( cfsec::CFSecISOCtryPKey* pkey ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readISOCtry" );
		cfsec::ICFSecISOCtryObj* obj = NULL;
		cfsec::ICFSecISOCtryObj* realized = NULL;
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			// obj could be NULL if cache misses is enabled
			obj = searchMembers->second;
			realized = obj;
		}
		return( realized );
	}

	cfsec::ICFSecISOCtryObj* CFSecISOCtryTableObj::readCachedISOCtryByIdIdx( const int16_t ISOCtryId )
	{
		static const std::string S_ProcName( "readCachedISOCtryByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecISOCtryPKey pkey;
		pkey.setRequiredISOCtryId( ISOCtryId );
		cfsec::ICFSecISOCtryObj* obj = readCachedISOCtry( &pkey );
		return( obj );
	}

	cfsec::ICFSecISOCtryObj* CFSecISOCtryTableObj::readCachedISOCtryByISOCodeIdx( const std::string& ISOCode )
	{
		static const std::string S_ProcName( "readCachedISOCtryByISOCodeIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByISOCodeIdx == NULL ) {
			indexByISOCodeIdx = new std::map< cfsec::CFSecISOCtryByISOCodeIdxKey,
				cfsec::ICFSecISOCtryObj*>();
		}
		cfsec::CFSecISOCtryByISOCodeIdxKey key;
		key.setRequiredISOCode( ISOCode );
		cfsec::ICFSecISOCtryObj* obj = NULL;
		auto searchIndexByISOCodeIdx = indexByISOCodeIdx->find( key );
		if( searchIndexByISOCodeIdx != indexByISOCodeIdx->end() ) {
			// Note: obj may be null if cache misses is enabled
			obj = searchIndexByISOCodeIdx->second;
		}
		else {
			for( auto iterMembers = members->begin(); ( obj == NULL ) && ( iterMembers != members->end() ); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecISOCtryBuff*>( obj->getBuff() ) ) != key ) {
						obj = NULL;
					}
				}
			}
		}
		return( obj );
	}

	cfsec::ICFSecISOCtryObj* CFSecISOCtryTableObj::readCachedISOCtryByNameIdx( const std::string& Name )
	{
		static const std::string S_ProcName( "readCachedISOCtryByNameIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByNameIdx == NULL ) {
			indexByNameIdx = new std::map< cfsec::CFSecISOCtryByNameIdxKey,
				cfsec::ICFSecISOCtryObj*>();
		}
		cfsec::CFSecISOCtryByNameIdxKey key;
		key.setRequiredName( Name );
		cfsec::ICFSecISOCtryObj* obj = NULL;
		auto searchIndexByNameIdx = indexByNameIdx->find( key );
		if( searchIndexByNameIdx != indexByNameIdx->end() ) {
			// Note: obj may be null if cache misses is enabled
			obj = searchIndexByNameIdx->second;
		}
		else {
			for( auto iterMembers = members->begin(); ( obj == NULL ) && ( iterMembers != members->end() ); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecISOCtryBuff*>( obj->getBuff() ) ) != key ) {
						obj = NULL;
					}
				}
			}
		}
		return( obj );
	}

	cfsec::ICFSecISOCtryObj* CFSecISOCtryTableObj::readCachedISOCtryByLookupISOCodeIdx( const std::string& ISOCode )
	{
		static const std::string S_Realized( "realized" );
		static const std::string S_Obj( "obj" );
		static const std::string S_ProcName( "readCachedISOCtryByLookupISOCodeIdx" );
		if( indexByISOCodeIdx == NULL ) {
			indexByISOCodeIdx = new std::map< cfsec::CFSecISOCtryByISOCodeIdxKey,
				cfsec::ICFSecISOCtryObj*>();
		}
		cfsec::CFSecISOCtryByISOCodeIdxKey key;
		key.setRequiredISOCode( ISOCode );
		cfsec::ICFSecISOCtryObj* obj = NULL;
		cfsec::ICFSecISOCtryObj* realized = NULL;
		auto searchIndexByISOCodeIdx = indexByISOCodeIdx->find( key );
		if( searchIndexByISOCodeIdx != indexByISOCodeIdx->end() ) {
			obj = searchIndexByISOCodeIdx->second;
		}
		else {
			for( auto iterMembers = members->begin(); ( obj == NULL ) && ( iterMembers != members->end() ); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecISOCtryBuff*>( obj->getBuff() ) ) != key ) {
						obj = NULL;
					}
				}
			}
		}
		return( obj );
	}

	cfsec::ICFSecISOCtryObj* CFSecISOCtryTableObj::updateISOCtry( cfsec::ICFSecISOCtryEditObj* Obj ) {
		static const std::string S_ProcName( "updateISOCtry" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Updated( "updated" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecISOCtryObj* obj = dynamic_cast<cfsec::ICFSecISOCtryObj*>( Obj->getOrig() );
		try {
			cfsec::CFSecISOCtryBuff* updated = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableISOCtry()->updateISOCtry( schema->getAuthorization(),
				dynamic_cast<cfsec::CFSecISOCtryBuff*>( Obj->getISOCtryBuff()->clone() ) );
			if( updated == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Updated );
			}
			obj = dynamic_cast<cfsec::ICFSecISOCtryObj*>( dynamic_cast<cfsec::CFSecISOCtryTableObj*>( schema->getISOCtryTableObj() )->newInstance() );
			obj->setBuff( updated );
			obj = dynamic_cast<cfsec::ICFSecISOCtryObj*>( obj->realize() );
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

	void CFSecISOCtryTableObj::deleteISOCtry( cfsec::ICFSecISOCtryEditObj* Obj ) {
		cfsec::ICFSecISOCtryObj* obj = Obj;
		dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableISOCtry()->deleteISOCtry( schema->getAuthorization(),
			obj->getISOCtryBuff() );
		deepDisposeByIdIdx( obj->getRequiredISOCtryId() );
	}

	void CFSecISOCtryTableObj::deleteISOCtryByIdIdx( const int16_t ISOCtryId )
	{
		cfsec::CFSecISOCtryPKey pkey;
		pkey.setRequiredISOCtryId( ISOCtryId );
		cfsec::ICFSecISOCtryObj* obj = readISOCtry( &pkey, true );
		if( obj != NULL ) {
			cfsec::ICFSecISOCtryEditObj* editObj = dynamic_cast<cfsec::ICFSecISOCtryEditObj*>( obj->getEdit() );
			if( editObj == NULL ) {
				editObj = dynamic_cast<cfsec::ICFSecISOCtryEditObj*>( obj->beginEdit() );
			}
			if( editObj != NULL ) {
				editObj->deleteInstance();
				editObj = NULL;
			}
		}
	}

	void CFSecISOCtryTableObj::deleteISOCtryByISOCodeIdx( const std::string& ISOCode )
	{
		if( indexByISOCodeIdx == NULL ) {
			indexByISOCodeIdx = new std::map< cfsec::CFSecISOCtryByISOCodeIdxKey,
				cfsec::ICFSecISOCtryObj*>();
		}
		cfsec::CFSecISOCtryByISOCodeIdxKey key;
		key.setRequiredISOCode( ISOCode );
		cfsec::ICFSecISOCtryObj* obj = NULL;
		auto searchIndexByISOCodeIdx = indexByISOCodeIdx->find( key );
		if( searchIndexByISOCodeIdx != indexByISOCodeIdx->end() ) {
			dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableISOCtry()->deleteISOCtryByISOCodeIdx( schema->getAuthorization(),
				ISOCode );
		}
		else {
			dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableISOCtry()->deleteISOCtryByISOCodeIdx( schema->getAuthorization(),
				ISOCode );
		}
		deepDisposeByISOCodeIdx( ISOCode );
	}

	void CFSecISOCtryTableObj::deleteISOCtryByNameIdx( const std::string& Name )
	{
		if( indexByNameIdx == NULL ) {
			indexByNameIdx = new std::map< cfsec::CFSecISOCtryByNameIdxKey,
				cfsec::ICFSecISOCtryObj*>();
		}
		cfsec::CFSecISOCtryByNameIdxKey key;
		key.setRequiredName( Name );
		cfsec::ICFSecISOCtryObj* obj = NULL;
		auto searchIndexByNameIdx = indexByNameIdx->find( key );
		if( searchIndexByNameIdx != indexByNameIdx->end() ) {
			dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableISOCtry()->deleteISOCtryByNameIdx( schema->getAuthorization(),
				Name );
		}
		else {
			dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableISOCtry()->deleteISOCtryByNameIdx( schema->getAuthorization(),
				Name );
		}
		deepDisposeByNameIdx( Name );
	}

	void CFSecISOCtryTableObj::reallyDetachFromIndexesISOCtry( cfsec::ICFSecISOCtryObj* Obj ) {
		static const std::string S_ProcName( "reallyDetachFromIndexesISOCtry" );
		static const std::string S_Obj( "Obj" );
		static const std::string S_ExistingObj( "ExistingObj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfsec::ICFSecISOCtryObj* obj = Obj;
		cfsec::CFSecISOCtryPKey* pkey = obj->getPKey();
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			cfsec::ICFSecISOCtryObj* existingObj = searchMembers->second;
			if( existingObj == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_ExistingObj );
			}
			if( indexByISOCodeIdx != NULL ) {
				cfsec::CFSecISOCtryByISOCodeIdxKey keyISOCodeIdx;
				keyISOCodeIdx.setRequiredISOCode( obj->getRequiredISOCode() );
				auto removalProbe = indexByISOCodeIdx->find( keyISOCodeIdx );
				if( removalProbe != indexByISOCodeIdx->end() ) {
					indexByISOCodeIdx->erase( removalProbe );
				}
			}

			if( indexByNameIdx != NULL ) {
				cfsec::CFSecISOCtryByNameIdxKey keyNameIdx;
				keyNameIdx.setRequiredName( obj->getRequiredName() );
				auto removalProbe = indexByNameIdx->find( keyNameIdx );
				if( removalProbe != indexByNameIdx->end() ) {
					indexByNameIdx->erase( removalProbe );
				}
			}

			members->erase( searchMembers );
		}
	}


}
