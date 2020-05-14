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

	const std::string CFSecISOCcyTableObj::CLASS_NAME( "CFSecISOCcyTableObj" );
	const std::string CFSecISOCcyTableObj::TABLE_NAME( "ISOCcy" );
	const std::string CFSecISOCcyTableObj::TABLE_DBNAME( "iso_ccy" );

	CFSecISOCcyTableObj::CFSecISOCcyTableObj() {
		schema = NULL;
		members = new std::map<cfsec::CFSecISOCcyPKey, cfsec::ICFSecISOCcyObj*>();
		allISOCcy = NULL;
		indexByCcyCdIdx = new std::map< cfsec::CFSecISOCcyByCcyCdIdxKey,
			cfsec::ICFSecISOCcyObj*>();
		indexByCcyNmIdx = new std::map< cfsec::CFSecISOCcyByCcyNmIdxKey,
			cfsec::ICFSecISOCcyObj*>();
	}

	CFSecISOCcyTableObj::CFSecISOCcyTableObj( cfsec::ICFSecSchemaObj* argSchema ) {
		schema = dynamic_cast<cfsec::ICFSecSchemaObj*>( argSchema );
		members = new std::map<cfsec::CFSecISOCcyPKey, cfsec::ICFSecISOCcyObj*>();
		allISOCcy = NULL;
		indexByCcyCdIdx = new std::map< cfsec::CFSecISOCcyByCcyCdIdxKey,
			cfsec::ICFSecISOCcyObj*>();
		indexByCcyNmIdx = new std::map< cfsec::CFSecISOCcyByCcyNmIdxKey,
			cfsec::ICFSecISOCcyObj*>();
	}

	CFSecISOCcyTableObj::~CFSecISOCcyTableObj() {
		minimizeMemory();
		if( indexByCcyCdIdx != NULL ) {
			delete indexByCcyCdIdx;
			indexByCcyCdIdx = NULL;
		}
		if( indexByCcyNmIdx != NULL ) {
			delete indexByCcyNmIdx;
			indexByCcyNmIdx = NULL;
		}
		if( members != NULL ) {
			cfsec::ICFSecISOCcyObj* curMember;
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

	cfsec::ICFSecSchemaObj* CFSecISOCcyTableObj::getSchema() {
		return( schema );
	}

	void CFSecISOCcyTableObj::setSchema( cfsec::ICFSecSchemaObj* value ) {
		schema = dynamic_cast<cfsec::ICFSecSchemaObj*>( value );
	}

	const std::string CFSecISOCcyTableObj::getTableName() {
		return( TABLE_NAME );
	}

	const std::string CFSecISOCcyTableObj::getTableDbName() {
		return( TABLE_DBNAME );
	}
	const classcode_t* CFSecISOCcyTableObj::getObjQualifyingClassCode() {
		return( NULL );
	}


	void CFSecISOCcyTableObj::minimizeMemory() {
		if( allISOCcy != NULL ) {
			allISOCcy->clear();
			delete allISOCcy;
			allISOCcy = NULL;
		}
		if( indexByCcyCdIdx != NULL ) {
			indexByCcyCdIdx->clear();
		}
		if( indexByCcyNmIdx != NULL ) {
			indexByCcyNmIdx->clear();
		}
		if( members != NULL ) {
			cfsec::ICFSecISOCcyObj* cur = NULL;
			cfsec::ICFSecISOCcyEditObj* edit = NULL;
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

	cfsec::ICFSecISOCcyObj* CFSecISOCcyTableObj::newInstance() {
		cfsec::ICFSecISOCcyObj* inst = dynamic_cast<cfsec::ICFSecISOCcyObj*>( new CFSecISOCcyObj( schema ) );
		return( inst );
	}

	cfsec::ICFSecISOCcyEditObj* CFSecISOCcyTableObj::newEditInstance( cfsec::ICFSecISOCcyObj* orig ) {
		cfsec::ICFSecISOCcyEditObj* edit = dynamic_cast<cfsec::ICFSecISOCcyEditObj*>( new CFSecISOCcyEditObj( orig ));
		return( edit );
	}

	cfsec::ICFSecISOCcyObj* CFSecISOCcyTableObj::realizeISOCcy( cfsec::ICFSecISOCcyObj* Obj ) {
		static const std::string S_ProcName( "realizeISOCcy" );
		static const std::string S_ExistingObj( "existingObj" );
		static const std::string S_KeepObj( "keepObj" );
		static const std::string S_Obj( "Obj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfsec::ICFSecISOCcyObj* obj = Obj;
		cfsec::ICFSecISOCcyObj* existingObj = NULL;
		cfsec::CFSecISOCcyPKey* pkey = obj->getPKey();
		cfsec::ICFSecISOCcyObj* keepObj = NULL;
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
			if( indexByCcyCdIdx != NULL ) {
				cfsec::CFSecISOCcyByCcyCdIdxKey keyCcyCdIdx;
				keyCcyCdIdx.setRequiredISOCode( keepObj->getRequiredISOCode() );
				auto removalProbe = indexByCcyCdIdx->find( keyCcyCdIdx );
				if( removalProbe != indexByCcyCdIdx->end() ) {
					indexByCcyCdIdx->erase( removalProbe );
				}
			}

			if( indexByCcyNmIdx != NULL ) {
				cfsec::CFSecISOCcyByCcyNmIdxKey keyCcyNmIdx;
				keyCcyNmIdx.setRequiredName( keepObj->getRequiredName() );
				auto removalProbe = indexByCcyNmIdx->find( keyCcyNmIdx );
				if( removalProbe != indexByCcyNmIdx->end() ) {
					indexByCcyNmIdx->erase( removalProbe );
				}
			}

			keepObj->setBuff( dynamic_cast<cfsec::CFSecISOCcyBuff*>( Obj->getBuff()->clone() ) );
			// Attach new object to alternate and duplicate indexes -- PKey stays stable

			if( indexByCcyCdIdx != NULL ) {
				static const std::string S_ACcyCdIdxObj( "aCcyCdIdxObj" );
				cfsec::ICFSecISOCcyObj* aCcyCdIdxObj =
					dynamic_cast<cfsec::ICFSecISOCcyObj*>( keepObj );
				if( aCcyCdIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ACcyCdIdxObj );
				}
				cfsec::CFSecISOCcyByCcyCdIdxKey keyCcyCdIdx;
				keyCcyCdIdx.setRequiredISOCode( keepObj->getRequiredISOCode() );
				indexByCcyCdIdx->insert( std::map< cfsec::CFSecISOCcyByCcyCdIdxKey, cfsec::ICFSecISOCcyObj* >::value_type( keyCcyCdIdx, aCcyCdIdxObj ) );
			}

			if( indexByCcyNmIdx != NULL ) {
				static const std::string S_ACcyNmIdxObj( "aCcyNmIdxObj" );
				cfsec::ICFSecISOCcyObj* aCcyNmIdxObj =
					dynamic_cast<cfsec::ICFSecISOCcyObj*>( keepObj );
				if( aCcyNmIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ACcyNmIdxObj );
				}
				cfsec::CFSecISOCcyByCcyNmIdxKey keyCcyNmIdx;
				keyCcyNmIdx.setRequiredName( keepObj->getRequiredName() );
				indexByCcyNmIdx->insert( std::map< cfsec::CFSecISOCcyByCcyNmIdxKey, cfsec::ICFSecISOCcyObj* >::value_type( keyCcyNmIdx, aCcyNmIdxObj ) );
			}

			if( allISOCcy != NULL ) {
				allISOCcy->insert( std::map< cfsec::CFSecISOCcyPKey, cfsec::ICFSecISOCcyObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			}
		}
		else {
			keepObj = obj;
			keepObj->setIsNew( false );
			pkey = keepObj->getPKey();
			// Attach new object to PKey, all, alternate, and duplicate indexes
			members->insert( std::map< cfsec::CFSecISOCcyPKey, cfsec::ICFSecISOCcyObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			// Attach new object to alternate and duplicate indexes -- PKey stay stable

			if( indexByCcyCdIdx != NULL ) {
				static const std::string S_ACcyCdIdxObj( "aCcyCdIdxObj" );
				cfsec::ICFSecISOCcyObj* aCcyCdIdxObj =
					dynamic_cast<cfsec::ICFSecISOCcyObj*>( keepObj );
				if( aCcyCdIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ACcyCdIdxObj );
				}
				cfsec::CFSecISOCcyByCcyCdIdxKey keyCcyCdIdx;
				keyCcyCdIdx.setRequiredISOCode( keepObj->getRequiredISOCode() );
				indexByCcyCdIdx->insert( std::map< cfsec::CFSecISOCcyByCcyCdIdxKey, cfsec::ICFSecISOCcyObj* >::value_type( keyCcyCdIdx, aCcyCdIdxObj ) );
			}

			if( indexByCcyNmIdx != NULL ) {
				static const std::string S_ACcyNmIdxObj( "aCcyNmIdxObj" );
				cfsec::ICFSecISOCcyObj* aCcyNmIdxObj =
					dynamic_cast<cfsec::ICFSecISOCcyObj*>( keepObj );
				if( aCcyNmIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ACcyNmIdxObj );
				}
				cfsec::CFSecISOCcyByCcyNmIdxKey keyCcyNmIdx;
				keyCcyNmIdx.setRequiredName( keepObj->getRequiredName() );
				indexByCcyNmIdx->insert( std::map< cfsec::CFSecISOCcyByCcyNmIdxKey, cfsec::ICFSecISOCcyObj* >::value_type( keyCcyNmIdx, aCcyNmIdxObj ) );
			}

			if( allISOCcy != NULL ) {
				allISOCcy->insert( std::map< cfsec::CFSecISOCcyPKey, cfsec::ICFSecISOCcyObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
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

	void CFSecISOCcyTableObj::deepDisposeByIdIdx( const int16_t ISOCcyId ) {
		static const std::string S_ProcName( "deepDisposeByIdIdx" );
		std::vector<cfsec::ICFSecISOCcyObj*> list;
		cfsec::ICFSecISOCcyObj* existingObj = readCachedISOCcyByIdIdx( ISOCcyId );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfsec::ICFSecISOCcyObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecISOCcyBuff::CLASS_CODE ) {
					dynamic_cast<cfsec::CFSecISOCcyTableObj*>( schema->getISOCcyTableObj() )->reallyDeepDisposeISOCcy( dynamic_cast<cfsec::ICFSecISOCcyObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFSecISOCcyTableObj::deepDisposeByCcyCdIdx( const std::string& ISOCode ) {
		static const std::string S_ProcName( "deepDisposeByCcyCdIdx" );
		std::vector<cfsec::ICFSecISOCcyObj*> list;
		cfsec::ICFSecISOCcyObj* existingObj = readCachedISOCcyByCcyCdIdx( ISOCode );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfsec::ICFSecISOCcyObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecISOCcyBuff::CLASS_CODE ) {
					dynamic_cast<cfsec::CFSecISOCcyTableObj*>( schema->getISOCcyTableObj() )->reallyDeepDisposeISOCcy( dynamic_cast<cfsec::ICFSecISOCcyObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFSecISOCcyTableObj::deepDisposeByCcyNmIdx( const std::string& Name ) {
		static const std::string S_ProcName( "deepDisposeByCcyNmIdx" );
		std::vector<cfsec::ICFSecISOCcyObj*> list;
		cfsec::ICFSecISOCcyObj* existingObj = readCachedISOCcyByCcyNmIdx( Name );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfsec::ICFSecISOCcyObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecISOCcyBuff::CLASS_CODE ) {
					dynamic_cast<cfsec::CFSecISOCcyTableObj*>( schema->getISOCcyTableObj() )->reallyDeepDisposeISOCcy( dynamic_cast<cfsec::ICFSecISOCcyObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFSecISOCcyTableObj::reallyDeepDisposeISOCcy( cfsec::ICFSecISOCcyObj* Obj ) {
		static const std::string S_ProcName( "reallyDeepDisposeISOCcy" );

		if( Obj == NULL ) {
			return;
		}

		cfsec::ICFSecISOCcyObj* obj = Obj;
		
		dynamic_cast<cfsec::CFSecISOCtryCcyTableObj*>( schema->getISOCtryCcyTableObj() )->deepDisposeByCcyIdx( obj->getRequiredISOCcyId() );
		classcode_t classCode = obj->getClassCode();
		if( classCode == cfsec::CFSecISOCcyBuff::CLASS_CODE ) {
			dynamic_cast<cfsec::CFSecISOCcyTableObj*>( schema->getISOCcyTableObj() )->reallyDetachFromIndexesISOCcy( dynamic_cast<cfsec::ICFSecISOCcyObj*>( obj ) );
		}

		if( obj->getEdit() != NULL ) {
			obj->endEdit();
		}
		delete obj;
		obj = NULL;
	}

	cfsec::ICFSecISOCcyObj* CFSecISOCcyTableObj::createISOCcy( cfsec::ICFSecISOCcyEditObj* Obj ) {
		static const std::string S_ProcName( "createISOCcy" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Cloneable( "cloneable" );
		static const std::string S_ClonedBuff( "clonedbuff" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecISOCcyObj* obj = dynamic_cast<cfsec::ICFSecISOCcyObj*>( Obj->getOrig() );
		try {
			cfsec::CFSecISOCcyBuff* buff = dynamic_cast<cfsec::CFSecISOCcyBuff*>( Obj->getBuff()->clone() );
			// C++18 version of create returns a new buffer instance and takes over ownership of the passed-in buffer
			// MSS TODO WORKING The xmsg client will need to return the buffer instance created by processing
			// the response message, while xmsg rqst will have to delete the backing store instance
			// it receives after preparing the reply message so that memory doesn't leak on every request.
			cflib::ICFLibCloneableObj* cloneable = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableISOCcy()->createISOCcy(
				schema->getAuthorization(),
				buff );
			if( cloneable == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Cloneable );
			}
			Obj->endEdit();
			obj->setBuff( dynamic_cast<cfsec::CFSecISOCcyBuff*>( cloneable ) );
			obj = dynamic_cast<cfsec::ICFSecISOCcyObj*>( obj->realize() );
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

	cfsec::ICFSecISOCcyObj* CFSecISOCcyTableObj::readISOCcy( cfsec::CFSecISOCcyPKey* pkey, bool forceRead ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readISOCcy" );
		cfsec::ICFSecISOCcyObj* obj = NULL;
		cfsec::ICFSecISOCcyObj* realized = NULL;
		if( ! forceRead ) {
			auto searchMembers = members->find( *pkey );
			if( searchMembers != members->end() ) {
				// obj could be NULL if cache misses is enabled
				obj = searchMembers->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecISOCcyBuff* readBuff = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableISOCcy()->readDerivedByIdIdx( schema->getAuthorization(),
			pkey->getRequiredISOCcyId() );
			if( readBuff != NULL ) {
			obj = dynamic_cast<cfsec::CFSecISOCcyTableObj*>( schema->getISOCcyTableObj() )->newInstance();
				obj->setBuff( readBuff );
				realized = dynamic_cast<cfsec::ICFSecISOCcyObj*>( obj->realize() );
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

	cfsec::ICFSecISOCcyObj* CFSecISOCcyTableObj::lockISOCcy( cfsec::CFSecISOCcyPKey* pkey ) {
		static const std::string S_ProcName( "lockISOCcy" );
		cfsec::ICFSecISOCcyObj* locked = NULL;
		cfsec::CFSecISOCcyBuff* lockBuff = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableISOCcy()->lockDerived( schema->getAuthorization(), pkey );
		if( lockBuff != NULL ) {
			locked = dynamic_cast<cfsec::CFSecISOCcyTableObj*>( schema->getISOCcyTableObj() )->newInstance();
			locked->setBuff( lockBuff );
			locked = dynamic_cast<cfsec::ICFSecISOCcyObj*>( locked->realize() );
		}
		else {
			return( NULL );
		}
		return( locked );
	}

	std::vector<cfsec::ICFSecISOCcyObj*> CFSecISOCcyTableObj::readAllISOCcy( bool forceRead ) {
		static const std::string S_ProcName( "readAllISOCcy" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Realized( "realized" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecISOCcyObj* realized = NULL;
		if( forceRead || ( allISOCcy == NULL ) ) {
			std::map<cfsec::CFSecISOCcyPKey, cfsec::ICFSecISOCcyObj*>* map = new std::map<cfsec::CFSecISOCcyPKey,cfsec::ICFSecISOCcyObj*>();
			allISOCcy = map;
			std::TCFLibOwningVector<cfsec::CFSecISOCcyBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableISOCcy()->readAllDerived( schema->getAuthorization() );
			cfsec::CFSecISOCcyBuff* buff = NULL;
			cfsec::ICFSecISOCcyObj* obj = NULL;
			try {
				for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
					buff = buffList[ idx ];
					buffList[ idx ] = NULL;
				obj = newInstance();
					obj->setBuff( buff );
					realized = dynamic_cast<cfsec::ICFSecISOCcyObj*>( obj->realize() );
					if( realized == NULL ) {
						throw cflib::CFLibNullArgumentException( CLASS_NAME,
							S_ProcName,
							0,
							S_Realized );
					}
					allISOCcy->insert( std::map< cfsec::CFSecISOCcyPKey, cfsec::ICFSecISOCcyObj* >::value_type( *(realized->getPKey()), realized ) );
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
		size_t len = allISOCcy->size();
		std::vector<cfsec::ICFSecISOCcyObj*> arr;
		auto valIter = allISOCcy->begin();
		size_t idx = 0;
		while( valIter != allISOCcy->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	cfsec::ICFSecISOCcyObj* CFSecISOCcyTableObj::readISOCcyByIdIdx( const int16_t ISOCcyId, bool forceRead )
	{
		static const std::string S_ProcName( "readISOCcyByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecISOCcyPKey pkey;
		pkey.setRequiredISOCcyId( ISOCcyId );
		cfsec::ICFSecISOCcyObj* obj = readISOCcy( &pkey, forceRead );
		return( obj );
	}

	cfsec::ICFSecISOCcyObj* CFSecISOCcyTableObj::readISOCcyByCcyCdIdx( const std::string& ISOCode, bool forceRead )
	{
		static const std::string S_ProcName( "readISOCcyByCcyCdIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByCcyCdIdx == NULL ) {
			indexByCcyCdIdx = new std::map< cfsec::CFSecISOCcyByCcyCdIdxKey,
				cfsec::ICFSecISOCcyObj*>();
		}
		cfsec::CFSecISOCcyByCcyCdIdxKey key;
		key.setRequiredISOCode( ISOCode );
		cfsec::ICFSecISOCcyObj* obj = NULL;
		cfsec::ICFSecISOCcyObj* realized = NULL;
		if( ! forceRead ) {
			auto searchIndexByCcyCdIdx = indexByCcyCdIdx->find( key );
			if( searchIndexByCcyCdIdx != indexByCcyCdIdx->end() ) {
				// Note: obj may be null if cache misses is enabled
				obj = searchIndexByCcyCdIdx->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecISOCcyBuff* buff = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableISOCcy()->readDerivedByCcyCdIdx( schema->getAuthorization(),
				ISOCode );
			if( buff != NULL ) {
				obj = dynamic_cast<cfsec::CFSecISOCcyTableObj*>( schema->getISOCcyTableObj() )->newInstance();
				obj->setBuff( buff );
				realized = dynamic_cast<cfsec::ICFSecISOCcyObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				indexByCcyCdIdx->insert( std::map< cfsec::CFSecISOCcyByCcyCdIdxKey, cfsec::ICFSecISOCcyObj*>::value_type( key, dynamic_cast<cfsec::ICFSecISOCcyObj*>( realized ) ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = realized;
			}
		}
		return( obj );
	}

	cfsec::ICFSecISOCcyObj* CFSecISOCcyTableObj::readISOCcyByCcyNmIdx( const std::string& Name, bool forceRead )
	{
		static const std::string S_ProcName( "readISOCcyByCcyNmIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByCcyNmIdx == NULL ) {
			indexByCcyNmIdx = new std::map< cfsec::CFSecISOCcyByCcyNmIdxKey,
				cfsec::ICFSecISOCcyObj*>();
		}
		cfsec::CFSecISOCcyByCcyNmIdxKey key;
		key.setRequiredName( Name );
		cfsec::ICFSecISOCcyObj* obj = NULL;
		cfsec::ICFSecISOCcyObj* realized = NULL;
		if( ! forceRead ) {
			auto searchIndexByCcyNmIdx = indexByCcyNmIdx->find( key );
			if( searchIndexByCcyNmIdx != indexByCcyNmIdx->end() ) {
				// Note: obj may be null if cache misses is enabled
				obj = searchIndexByCcyNmIdx->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecISOCcyBuff* buff = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableISOCcy()->readDerivedByCcyNmIdx( schema->getAuthorization(),
				Name );
			if( buff != NULL ) {
				obj = dynamic_cast<cfsec::CFSecISOCcyTableObj*>( schema->getISOCcyTableObj() )->newInstance();
				obj->setBuff( buff );
				realized = dynamic_cast<cfsec::ICFSecISOCcyObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				indexByCcyNmIdx->insert( std::map< cfsec::CFSecISOCcyByCcyNmIdxKey, cfsec::ICFSecISOCcyObj*>::value_type( key, dynamic_cast<cfsec::ICFSecISOCcyObj*>( realized ) ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = realized;
			}
		}
		return( obj );
	}

	cfsec::ICFSecISOCcyObj* CFSecISOCcyTableObj::readISOCcyByLookupCcyCdIdx( const std::string& ISOCode, bool forceRead )
	{
		static const std::string S_Realized( "realized" );
		static const std::string S_Obj( "obj" );
		static const std::string S_ProcName( "readISOCcyByLookupCcyCdIdx" );
		if( indexByCcyCdIdx == NULL ) {
			indexByCcyCdIdx = new std::map< cfsec::CFSecISOCcyByCcyCdIdxKey,
				cfsec::ICFSecISOCcyObj*>();
		}
		cfsec::CFSecISOCcyByCcyCdIdxKey key;
		key.setRequiredISOCode( ISOCode );
		cfsec::ICFSecISOCcyObj* obj = NULL;
		cfsec::ICFSecISOCcyObj* realized = NULL;
		if( ! forceRead ) {
			auto searchIndexByCcyCdIdx = indexByCcyCdIdx->find( key );
			if( searchIndexByCcyCdIdx != indexByCcyCdIdx->end() ) {
				obj = searchIndexByCcyCdIdx->second;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecISOCcyBuff* buff = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableISOCcy()->readDerivedByLookupCcyCdIdx( schema->getAuthorization(),
				ISOCode );
			if( buff != NULL ) {
				obj = dynamic_cast<cfsec::ICFSecISOCcyObj*>( dynamic_cast<cfsec::CFSecISOCcyTableObj*>( schema->getISOCcyTableObj() )->newInstance() );
				obj->setBuff( buff );
				realized = dynamic_cast<cfsec::ICFSecISOCcyObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				indexByCcyCdIdx->insert( std::map< cfsec::CFSecISOCcyByCcyCdIdxKey, cfsec::ICFSecISOCcyObj*>::value_type( key, dynamic_cast<cfsec::ICFSecISOCcyObj*>( realized ) ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = realized;
			}
		}
		return( obj );
	}

	cfsec::ICFSecISOCcyObj* CFSecISOCcyTableObj::readCachedISOCcy( cfsec::CFSecISOCcyPKey* pkey ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readISOCcy" );
		cfsec::ICFSecISOCcyObj* obj = NULL;
		cfsec::ICFSecISOCcyObj* realized = NULL;
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			// obj could be NULL if cache misses is enabled
			obj = searchMembers->second;
			realized = obj;
		}
		return( realized );
	}

	cfsec::ICFSecISOCcyObj* CFSecISOCcyTableObj::readCachedISOCcyByIdIdx( const int16_t ISOCcyId )
	{
		static const std::string S_ProcName( "readCachedISOCcyByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecISOCcyPKey pkey;
		pkey.setRequiredISOCcyId( ISOCcyId );
		cfsec::ICFSecISOCcyObj* obj = readCachedISOCcy( &pkey );
		return( obj );
	}

	cfsec::ICFSecISOCcyObj* CFSecISOCcyTableObj::readCachedISOCcyByCcyCdIdx( const std::string& ISOCode )
	{
		static const std::string S_ProcName( "readCachedISOCcyByCcyCdIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByCcyCdIdx == NULL ) {
			indexByCcyCdIdx = new std::map< cfsec::CFSecISOCcyByCcyCdIdxKey,
				cfsec::ICFSecISOCcyObj*>();
		}
		cfsec::CFSecISOCcyByCcyCdIdxKey key;
		key.setRequiredISOCode( ISOCode );
		cfsec::ICFSecISOCcyObj* obj = NULL;
		auto searchIndexByCcyCdIdx = indexByCcyCdIdx->find( key );
		if( searchIndexByCcyCdIdx != indexByCcyCdIdx->end() ) {
			// Note: obj may be null if cache misses is enabled
			obj = searchIndexByCcyCdIdx->second;
		}
		else {
			for( auto iterMembers = members->begin(); ( obj == NULL ) && ( iterMembers != members->end() ); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecISOCcyBuff*>( obj->getBuff() ) ) != key ) {
						obj = NULL;
					}
				}
			}
		}
		return( obj );
	}

	cfsec::ICFSecISOCcyObj* CFSecISOCcyTableObj::readCachedISOCcyByCcyNmIdx( const std::string& Name )
	{
		static const std::string S_ProcName( "readCachedISOCcyByCcyNmIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByCcyNmIdx == NULL ) {
			indexByCcyNmIdx = new std::map< cfsec::CFSecISOCcyByCcyNmIdxKey,
				cfsec::ICFSecISOCcyObj*>();
		}
		cfsec::CFSecISOCcyByCcyNmIdxKey key;
		key.setRequiredName( Name );
		cfsec::ICFSecISOCcyObj* obj = NULL;
		auto searchIndexByCcyNmIdx = indexByCcyNmIdx->find( key );
		if( searchIndexByCcyNmIdx != indexByCcyNmIdx->end() ) {
			// Note: obj may be null if cache misses is enabled
			obj = searchIndexByCcyNmIdx->second;
		}
		else {
			for( auto iterMembers = members->begin(); ( obj == NULL ) && ( iterMembers != members->end() ); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecISOCcyBuff*>( obj->getBuff() ) ) != key ) {
						obj = NULL;
					}
				}
			}
		}
		return( obj );
	}

	cfsec::ICFSecISOCcyObj* CFSecISOCcyTableObj::readCachedISOCcyByLookupCcyCdIdx( const std::string& ISOCode )
	{
		static const std::string S_Realized( "realized" );
		static const std::string S_Obj( "obj" );
		static const std::string S_ProcName( "readCachedISOCcyByLookupCcyCdIdx" );
		if( indexByCcyCdIdx == NULL ) {
			indexByCcyCdIdx = new std::map< cfsec::CFSecISOCcyByCcyCdIdxKey,
				cfsec::ICFSecISOCcyObj*>();
		}
		cfsec::CFSecISOCcyByCcyCdIdxKey key;
		key.setRequiredISOCode( ISOCode );
		cfsec::ICFSecISOCcyObj* obj = NULL;
		cfsec::ICFSecISOCcyObj* realized = NULL;
		auto searchIndexByCcyCdIdx = indexByCcyCdIdx->find( key );
		if( searchIndexByCcyCdIdx != indexByCcyCdIdx->end() ) {
			obj = searchIndexByCcyCdIdx->second;
		}
		else {
			for( auto iterMembers = members->begin(); ( obj == NULL ) && ( iterMembers != members->end() ); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecISOCcyBuff*>( obj->getBuff() ) ) != key ) {
						obj = NULL;
					}
				}
			}
		}
		return( obj );
	}

	cfsec::ICFSecISOCcyObj* CFSecISOCcyTableObj::updateISOCcy( cfsec::ICFSecISOCcyEditObj* Obj ) {
		static const std::string S_ProcName( "updateISOCcy" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Updated( "updated" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecISOCcyObj* obj = dynamic_cast<cfsec::ICFSecISOCcyObj*>( Obj->getOrig() );
		try {
			cfsec::CFSecISOCcyBuff* updated = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableISOCcy()->updateISOCcy( schema->getAuthorization(),
				dynamic_cast<cfsec::CFSecISOCcyBuff*>( Obj->getISOCcyBuff()->clone() ) );
			if( updated == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Updated );
			}
			obj = dynamic_cast<cfsec::ICFSecISOCcyObj*>( dynamic_cast<cfsec::CFSecISOCcyTableObj*>( schema->getISOCcyTableObj() )->newInstance() );
			obj->setBuff( updated );
			obj = dynamic_cast<cfsec::ICFSecISOCcyObj*>( obj->realize() );
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

	void CFSecISOCcyTableObj::deleteISOCcy( cfsec::ICFSecISOCcyEditObj* Obj ) {
		cfsec::ICFSecISOCcyObj* obj = Obj;
		dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableISOCcy()->deleteISOCcy( schema->getAuthorization(),
			obj->getISOCcyBuff() );
		deepDisposeByIdIdx( obj->getRequiredISOCcyId() );
	}

	void CFSecISOCcyTableObj::deleteISOCcyByIdIdx( const int16_t ISOCcyId )
	{
		cfsec::CFSecISOCcyPKey pkey;
		pkey.setRequiredISOCcyId( ISOCcyId );
		cfsec::ICFSecISOCcyObj* obj = readISOCcy( &pkey, true );
		if( obj != NULL ) {
			cfsec::ICFSecISOCcyEditObj* editObj = dynamic_cast<cfsec::ICFSecISOCcyEditObj*>( obj->getEdit() );
			if( editObj == NULL ) {
				editObj = dynamic_cast<cfsec::ICFSecISOCcyEditObj*>( obj->beginEdit() );
			}
			if( editObj != NULL ) {
				editObj->deleteInstance();
				editObj = NULL;
			}
		}
	}

	void CFSecISOCcyTableObj::deleteISOCcyByCcyCdIdx( const std::string& ISOCode )
	{
		if( indexByCcyCdIdx == NULL ) {
			indexByCcyCdIdx = new std::map< cfsec::CFSecISOCcyByCcyCdIdxKey,
				cfsec::ICFSecISOCcyObj*>();
		}
		cfsec::CFSecISOCcyByCcyCdIdxKey key;
		key.setRequiredISOCode( ISOCode );
		cfsec::ICFSecISOCcyObj* obj = NULL;
		auto searchIndexByCcyCdIdx = indexByCcyCdIdx->find( key );
		if( searchIndexByCcyCdIdx != indexByCcyCdIdx->end() ) {
			dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableISOCcy()->deleteISOCcyByCcyCdIdx( schema->getAuthorization(),
				ISOCode );
		}
		else {
			dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableISOCcy()->deleteISOCcyByCcyCdIdx( schema->getAuthorization(),
				ISOCode );
		}
		deepDisposeByCcyCdIdx( ISOCode );
	}

	void CFSecISOCcyTableObj::deleteISOCcyByCcyNmIdx( const std::string& Name )
	{
		if( indexByCcyNmIdx == NULL ) {
			indexByCcyNmIdx = new std::map< cfsec::CFSecISOCcyByCcyNmIdxKey,
				cfsec::ICFSecISOCcyObj*>();
		}
		cfsec::CFSecISOCcyByCcyNmIdxKey key;
		key.setRequiredName( Name );
		cfsec::ICFSecISOCcyObj* obj = NULL;
		auto searchIndexByCcyNmIdx = indexByCcyNmIdx->find( key );
		if( searchIndexByCcyNmIdx != indexByCcyNmIdx->end() ) {
			dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableISOCcy()->deleteISOCcyByCcyNmIdx( schema->getAuthorization(),
				Name );
		}
		else {
			dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableISOCcy()->deleteISOCcyByCcyNmIdx( schema->getAuthorization(),
				Name );
		}
		deepDisposeByCcyNmIdx( Name );
	}

	void CFSecISOCcyTableObj::reallyDetachFromIndexesISOCcy( cfsec::ICFSecISOCcyObj* Obj ) {
		static const std::string S_ProcName( "reallyDetachFromIndexesISOCcy" );
		static const std::string S_Obj( "Obj" );
		static const std::string S_ExistingObj( "ExistingObj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfsec::ICFSecISOCcyObj* obj = Obj;
		cfsec::CFSecISOCcyPKey* pkey = obj->getPKey();
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			cfsec::ICFSecISOCcyObj* existingObj = searchMembers->second;
			if( existingObj == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_ExistingObj );
			}
			if( indexByCcyCdIdx != NULL ) {
				cfsec::CFSecISOCcyByCcyCdIdxKey keyCcyCdIdx;
				keyCcyCdIdx.setRequiredISOCode( obj->getRequiredISOCode() );
				auto removalProbe = indexByCcyCdIdx->find( keyCcyCdIdx );
				if( removalProbe != indexByCcyCdIdx->end() ) {
					indexByCcyCdIdx->erase( removalProbe );
				}
			}

			if( indexByCcyNmIdx != NULL ) {
				cfsec::CFSecISOCcyByCcyNmIdxKey keyCcyNmIdx;
				keyCcyNmIdx.setRequiredName( obj->getRequiredName() );
				auto removalProbe = indexByCcyNmIdx->find( keyCcyNmIdx );
				if( removalProbe != indexByCcyNmIdx->end() ) {
					indexByCcyNmIdx->erase( removalProbe );
				}
			}

			members->erase( searchMembers );
		}
	}


}
