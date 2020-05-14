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

	const std::string CFSecISOLangTableObj::CLASS_NAME( "CFSecISOLangTableObj" );
	const std::string CFSecISOLangTableObj::TABLE_NAME( "ISOLang" );
	const std::string CFSecISOLangTableObj::TABLE_DBNAME( "iso_lang" );

	CFSecISOLangTableObj::CFSecISOLangTableObj() {
		schema = NULL;
		members = new std::map<cfsec::CFSecISOLangPKey, cfsec::ICFSecISOLangObj*>();
		allISOLang = NULL;
		indexByCode3Idx = new std::map< cfsec::CFSecISOLangByCode3IdxKey,
			cfsec::ICFSecISOLangObj*>();
		indexByCode2Idx = new std::map< cfsec::CFSecISOLangByCode2IdxKey,
			std::map< cfsec::CFSecISOLangPKey, cfsec::ICFSecISOLangObj*>*>();
	}

	CFSecISOLangTableObj::CFSecISOLangTableObj( cfsec::ICFSecSchemaObj* argSchema ) {
		schema = dynamic_cast<cfsec::ICFSecSchemaObj*>( argSchema );
		members = new std::map<cfsec::CFSecISOLangPKey, cfsec::ICFSecISOLangObj*>();
		allISOLang = NULL;
		indexByCode3Idx = new std::map< cfsec::CFSecISOLangByCode3IdxKey,
			cfsec::ICFSecISOLangObj*>();
		indexByCode2Idx = new std::map< cfsec::CFSecISOLangByCode2IdxKey,
			std::map< cfsec::CFSecISOLangPKey, cfsec::ICFSecISOLangObj*>*>();
	}

	CFSecISOLangTableObj::~CFSecISOLangTableObj() {
		minimizeMemory();
		if( indexByCode3Idx != NULL ) {
			delete indexByCode3Idx;
			indexByCode3Idx = NULL;
		}
		if( indexByCode2Idx != NULL ) {
			delete indexByCode2Idx;
			indexByCode2Idx = NULL;
		}
		if( members != NULL ) {
			cfsec::ICFSecISOLangObj* curMember;
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

	cfsec::ICFSecSchemaObj* CFSecISOLangTableObj::getSchema() {
		return( schema );
	}

	void CFSecISOLangTableObj::setSchema( cfsec::ICFSecSchemaObj* value ) {
		schema = dynamic_cast<cfsec::ICFSecSchemaObj*>( value );
	}

	const std::string CFSecISOLangTableObj::getTableName() {
		return( TABLE_NAME );
	}

	const std::string CFSecISOLangTableObj::getTableDbName() {
		return( TABLE_DBNAME );
	}
	const classcode_t* CFSecISOLangTableObj::getObjQualifyingClassCode() {
		return( NULL );
	}


	void CFSecISOLangTableObj::minimizeMemory() {
		if( allISOLang != NULL ) {
			allISOLang->clear();
			delete allISOLang;
			allISOLang = NULL;
		}
		if( indexByCode3Idx != NULL ) {
			indexByCode3Idx->clear();
		}
		if( indexByCode2Idx != NULL ) {
			std::map< cfsec::CFSecISOLangByCode2IdxKey,
				std::map< cfsec::CFSecISOLangPKey, cfsec::ICFSecISOLangObj*>* >::iterator iterByCode2Idx = indexByCode2Idx->begin();
			std::map< cfsec::CFSecISOLangByCode2IdxKey,
				std::map< cfsec::CFSecISOLangPKey, cfsec::ICFSecISOLangObj*>* >::iterator endByCode2Idx = indexByCode2Idx->end();
			std::map< cfsec::CFSecISOLangPKey, cfsec::ICFSecISOLangObj*>* curByCode2Idx = NULL;
			while( iterByCode2Idx != endByCode2Idx ) {
				curByCode2Idx = iterByCode2Idx->second;
				if( curByCode2Idx != NULL ) {
					curByCode2Idx->clear();
					delete curByCode2Idx;
					curByCode2Idx = NULL;
					iterByCode2Idx->second = NULL;
				}
				iterByCode2Idx ++;
			}
			indexByCode2Idx->clear();
		}
		if( members != NULL ) {
			cfsec::ICFSecISOLangObj* cur = NULL;
			cfsec::ICFSecISOLangEditObj* edit = NULL;
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

	cfsec::ICFSecISOLangObj* CFSecISOLangTableObj::newInstance() {
		cfsec::ICFSecISOLangObj* inst = dynamic_cast<cfsec::ICFSecISOLangObj*>( new CFSecISOLangObj( schema ) );
		return( inst );
	}

	cfsec::ICFSecISOLangEditObj* CFSecISOLangTableObj::newEditInstance( cfsec::ICFSecISOLangObj* orig ) {
		cfsec::ICFSecISOLangEditObj* edit = dynamic_cast<cfsec::ICFSecISOLangEditObj*>( new CFSecISOLangEditObj( orig ));
		return( edit );
	}

	cfsec::ICFSecISOLangObj* CFSecISOLangTableObj::realizeISOLang( cfsec::ICFSecISOLangObj* Obj ) {
		static const std::string S_ProcName( "realizeISOLang" );
		static const std::string S_ExistingObj( "existingObj" );
		static const std::string S_KeepObj( "keepObj" );
		static const std::string S_Obj( "Obj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfsec::ICFSecISOLangObj* obj = Obj;
		cfsec::ICFSecISOLangObj* existingObj = NULL;
		cfsec::CFSecISOLangPKey* pkey = obj->getPKey();
		cfsec::ICFSecISOLangObj* keepObj = NULL;
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
			if( indexByCode3Idx != NULL ) {
				cfsec::CFSecISOLangByCode3IdxKey keyCode3Idx;
				keyCode3Idx.setRequiredISO6392Code( keepObj->getRequiredISO6392Code() );
				auto removalProbe = indexByCode3Idx->find( keyCode3Idx );
				if( removalProbe != indexByCode3Idx->end() ) {
					indexByCode3Idx->erase( removalProbe );
				}
			}

			if( indexByCode2Idx != NULL ) {
				cfsec::CFSecISOLangByCode2IdxKey keyCode2Idx;
				if( keepObj->isOptionalISO6391CodeNull() ) {
					keyCode2Idx.setOptionalISO6391CodeNull();
				}
				else {
					keyCode2Idx.setOptionalISO6391CodeValue( keepObj->getOptionalISO6391CodeValue() );
				}
				auto searchCode2Idx = indexByCode2Idx->find( keyCode2Idx );
				if( searchCode2Idx != indexByCode2Idx->end() ) {
					std::map<cfsec::CFSecISOLangPKey, cfsec::ICFSecISOLangObj*>* mapCode2Idx = searchCode2Idx->second;
					if( mapCode2Idx != NULL ) {
						auto removalProbe = mapCode2Idx->find( *(keepObj->getPKey()) );
						if( removalProbe != mapCode2Idx->end() ) {
							mapCode2Idx->erase( removalProbe );
						}
					}
				}
			}

			keepObj->setBuff( dynamic_cast<cfsec::CFSecISOLangBuff*>( Obj->getBuff()->clone() ) );
			// Attach new object to alternate and duplicate indexes -- PKey stays stable

			if( indexByCode3Idx != NULL ) {
				static const std::string S_ACode3IdxObj( "aCode3IdxObj" );
				cfsec::ICFSecISOLangObj* aCode3IdxObj =
					dynamic_cast<cfsec::ICFSecISOLangObj*>( keepObj );
				if( aCode3IdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ACode3IdxObj );
				}
				cfsec::CFSecISOLangByCode3IdxKey keyCode3Idx;
				keyCode3Idx.setRequiredISO6392Code( keepObj->getRequiredISO6392Code() );
				indexByCode3Idx->insert( std::map< cfsec::CFSecISOLangByCode3IdxKey, cfsec::ICFSecISOLangObj* >::value_type( keyCode3Idx, aCode3IdxObj ) );
			}

			if( indexByCode2Idx != NULL ) {
				static const std::string S_ACode2IdxObj( "aCode2IdxObj" );
				cfsec::ICFSecISOLangObj* aCode2IdxObj =
					dynamic_cast<cfsec::ICFSecISOLangObj*>( keepObj );
				if( aCode2IdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ACode2IdxObj );
				}
				cfsec::CFSecISOLangByCode2IdxKey keyCode2Idx;
				if( keepObj->isOptionalISO6391CodeNull() ) {
					keyCode2Idx.setOptionalISO6391CodeNull();
				}
				else {
					keyCode2Idx.setOptionalISO6391CodeValue( keepObj->getOptionalISO6391CodeValue() );
				}
				auto searchIndexByCode2Idx = indexByCode2Idx->find( keyCode2Idx );
				if( searchIndexByCode2Idx != indexByCode2Idx->end() ) {
					std::map<cfsec::CFSecISOLangPKey, cfsec::ICFSecISOLangObj*>* mapCode2Idx = searchIndexByCode2Idx->second;
					if( mapCode2Idx != NULL ) {
						mapCode2Idx->insert( std::map< cfsec::CFSecISOLangPKey, cfsec::ICFSecISOLangObj* >::value_type( *(keepObj->getPKey()), aCode2IdxObj ) );
					}
				}
			}

			if( allISOLang != NULL ) {
				allISOLang->insert( std::map< cfsec::CFSecISOLangPKey, cfsec::ICFSecISOLangObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			}
		}
		else {
			keepObj = obj;
			keepObj->setIsNew( false );
			pkey = keepObj->getPKey();
			// Attach new object to PKey, all, alternate, and duplicate indexes
			members->insert( std::map< cfsec::CFSecISOLangPKey, cfsec::ICFSecISOLangObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			// Attach new object to alternate and duplicate indexes -- PKey stay stable

			if( indexByCode3Idx != NULL ) {
				static const std::string S_ACode3IdxObj( "aCode3IdxObj" );
				cfsec::ICFSecISOLangObj* aCode3IdxObj =
					dynamic_cast<cfsec::ICFSecISOLangObj*>( keepObj );
				if( aCode3IdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ACode3IdxObj );
				}
				cfsec::CFSecISOLangByCode3IdxKey keyCode3Idx;
				keyCode3Idx.setRequiredISO6392Code( keepObj->getRequiredISO6392Code() );
				indexByCode3Idx->insert( std::map< cfsec::CFSecISOLangByCode3IdxKey, cfsec::ICFSecISOLangObj* >::value_type( keyCode3Idx, aCode3IdxObj ) );
			}

			if( indexByCode2Idx != NULL ) {
				static const std::string S_ACode2IdxObj( "aCode2IdxObj" );
				cfsec::ICFSecISOLangObj* aCode2IdxObj =
					dynamic_cast<cfsec::ICFSecISOLangObj*>( keepObj );
				if( aCode2IdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ACode2IdxObj );
				}
				cfsec::CFSecISOLangByCode2IdxKey keyCode2Idx;
				if( keepObj->isOptionalISO6391CodeNull() ) {
					keyCode2Idx.setOptionalISO6391CodeNull();
				}
				else {
					keyCode2Idx.setOptionalISO6391CodeValue( keepObj->getOptionalISO6391CodeValue() );
				}
				auto searchIndexByCode2Idx = indexByCode2Idx->find( keyCode2Idx );
				if( searchIndexByCode2Idx != indexByCode2Idx->end() ) {
					std::map<cfsec::CFSecISOLangPKey, cfsec::ICFSecISOLangObj*>* mapCode2Idx = searchIndexByCode2Idx->second;
					if( mapCode2Idx != NULL ) {
						mapCode2Idx->insert( std::map< cfsec::CFSecISOLangPKey, cfsec::ICFSecISOLangObj* >::value_type( *(keepObj->getPKey()), aCode2IdxObj ) );
					}
				}
			}

			if( allISOLang != NULL ) {
				allISOLang->insert( std::map< cfsec::CFSecISOLangPKey, cfsec::ICFSecISOLangObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
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

	void CFSecISOLangTableObj::deepDisposeByIdIdx( const int16_t ISOLangId ) {
		static const std::string S_ProcName( "deepDisposeByIdIdx" );
		std::vector<cfsec::ICFSecISOLangObj*> list;
		cfsec::ICFSecISOLangObj* existingObj = readCachedISOLangByIdIdx( ISOLangId );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfsec::ICFSecISOLangObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecISOLangBuff::CLASS_CODE ) {
					dynamic_cast<cfsec::CFSecISOLangTableObj*>( schema->getISOLangTableObj() )->reallyDeepDisposeISOLang( dynamic_cast<cfsec::ICFSecISOLangObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFSecISOLangTableObj::deepDisposeByCode3Idx( const std::string& ISO6392Code ) {
		static const std::string S_ProcName( "deepDisposeByCode3Idx" );
		std::vector<cfsec::ICFSecISOLangObj*> list;
		cfsec::ICFSecISOLangObj* existingObj = readCachedISOLangByCode3Idx( ISO6392Code );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfsec::ICFSecISOLangObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecISOLangBuff::CLASS_CODE ) {
					dynamic_cast<cfsec::CFSecISOLangTableObj*>( schema->getISOLangTableObj() )->reallyDeepDisposeISOLang( dynamic_cast<cfsec::ICFSecISOLangObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFSecISOLangTableObj::deepDisposeByCode2Idx( const std::string* ISO6391Code ) {
		static const std::string S_ProcName( "deepDisposeByCode2Idx" );
		std::vector<cfsec::ICFSecISOLangObj*> list;
		std::vector<cfsec::ICFSecISOLangObj*> matchesFound = readCachedISOLangByCode2Idx( ISO6391Code );
		auto iterMatches = matchesFound.begin();
		auto endMatches = matchesFound.end();
		while( iterMatches != endMatches ) {
			if( *iterMatches != NULL ) {
				list.push_back( *iterMatches );
			}
			iterMatches ++;
		}
		cfsec::ICFSecISOLangObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecISOLangBuff::CLASS_CODE ) {
					dynamic_cast<cfsec::CFSecISOLangTableObj*>( schema->getISOLangTableObj() )->reallyDeepDisposeISOLang( dynamic_cast<cfsec::ICFSecISOLangObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFSecISOLangTableObj::reallyDeepDisposeISOLang( cfsec::ICFSecISOLangObj* Obj ) {
		static const std::string S_ProcName( "reallyDeepDisposeISOLang" );

		if( Obj == NULL ) {
			return;
		}

		cfsec::ICFSecISOLangObj* obj = Obj;
		
		dynamic_cast<cfsec::CFSecISOCtryLangTableObj*>( schema->getISOCtryLangTableObj() )->deepDisposeByLangIdx( obj->getRequiredISOLangId() );
		classcode_t classCode = obj->getClassCode();
		if( classCode == cfsec::CFSecISOLangBuff::CLASS_CODE ) {
			dynamic_cast<cfsec::CFSecISOLangTableObj*>( schema->getISOLangTableObj() )->reallyDetachFromIndexesISOLang( dynamic_cast<cfsec::ICFSecISOLangObj*>( obj ) );
		}

		if( obj->getEdit() != NULL ) {
			obj->endEdit();
		}
		delete obj;
		obj = NULL;
	}

	cfsec::ICFSecISOLangObj* CFSecISOLangTableObj::createISOLang( cfsec::ICFSecISOLangEditObj* Obj ) {
		static const std::string S_ProcName( "createISOLang" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Cloneable( "cloneable" );
		static const std::string S_ClonedBuff( "clonedbuff" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecISOLangObj* obj = dynamic_cast<cfsec::ICFSecISOLangObj*>( Obj->getOrig() );
		try {
			cfsec::CFSecISOLangBuff* buff = dynamic_cast<cfsec::CFSecISOLangBuff*>( Obj->getBuff()->clone() );
			// C++18 version of create returns a new buffer instance and takes over ownership of the passed-in buffer
			// MSS TODO WORKING The xmsg client will need to return the buffer instance created by processing
			// the response message, while xmsg rqst will have to delete the backing store instance
			// it receives after preparing the reply message so that memory doesn't leak on every request.
			cflib::ICFLibCloneableObj* cloneable = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableISOLang()->createISOLang(
				schema->getAuthorization(),
				buff );
			if( cloneable == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Cloneable );
			}
			Obj->endEdit();
			obj->setBuff( dynamic_cast<cfsec::CFSecISOLangBuff*>( cloneable ) );
			obj = dynamic_cast<cfsec::ICFSecISOLangObj*>( obj->realize() );
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

	cfsec::ICFSecISOLangObj* CFSecISOLangTableObj::readISOLang( cfsec::CFSecISOLangPKey* pkey, bool forceRead ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readISOLang" );
		cfsec::ICFSecISOLangObj* obj = NULL;
		cfsec::ICFSecISOLangObj* realized = NULL;
		if( ! forceRead ) {
			auto searchMembers = members->find( *pkey );
			if( searchMembers != members->end() ) {
				// obj could be NULL if cache misses is enabled
				obj = searchMembers->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecISOLangBuff* readBuff = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableISOLang()->readDerivedByIdIdx( schema->getAuthorization(),
			pkey->getRequiredISOLangId() );
			if( readBuff != NULL ) {
			obj = dynamic_cast<cfsec::CFSecISOLangTableObj*>( schema->getISOLangTableObj() )->newInstance();
				obj->setBuff( readBuff );
				realized = dynamic_cast<cfsec::ICFSecISOLangObj*>( obj->realize() );
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

	cfsec::ICFSecISOLangObj* CFSecISOLangTableObj::lockISOLang( cfsec::CFSecISOLangPKey* pkey ) {
		static const std::string S_ProcName( "lockISOLang" );
		cfsec::ICFSecISOLangObj* locked = NULL;
		cfsec::CFSecISOLangBuff* lockBuff = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableISOLang()->lockDerived( schema->getAuthorization(), pkey );
		if( lockBuff != NULL ) {
			locked = dynamic_cast<cfsec::CFSecISOLangTableObj*>( schema->getISOLangTableObj() )->newInstance();
			locked->setBuff( lockBuff );
			locked = dynamic_cast<cfsec::ICFSecISOLangObj*>( locked->realize() );
		}
		else {
			return( NULL );
		}
		return( locked );
	}

	std::vector<cfsec::ICFSecISOLangObj*> CFSecISOLangTableObj::readAllISOLang( bool forceRead ) {
		static const std::string S_ProcName( "readAllISOLang" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Realized( "realized" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecISOLangObj* realized = NULL;
		if( forceRead || ( allISOLang == NULL ) ) {
			std::map<cfsec::CFSecISOLangPKey, cfsec::ICFSecISOLangObj*>* map = new std::map<cfsec::CFSecISOLangPKey,cfsec::ICFSecISOLangObj*>();
			allISOLang = map;
			std::TCFLibOwningVector<cfsec::CFSecISOLangBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableISOLang()->readAllDerived( schema->getAuthorization() );
			cfsec::CFSecISOLangBuff* buff = NULL;
			cfsec::ICFSecISOLangObj* obj = NULL;
			try {
				for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
					buff = buffList[ idx ];
					buffList[ idx ] = NULL;
				obj = newInstance();
					obj->setBuff( buff );
					realized = dynamic_cast<cfsec::ICFSecISOLangObj*>( obj->realize() );
					if( realized == NULL ) {
						throw cflib::CFLibNullArgumentException( CLASS_NAME,
							S_ProcName,
							0,
							S_Realized );
					}
					allISOLang->insert( std::map< cfsec::CFSecISOLangPKey, cfsec::ICFSecISOLangObj* >::value_type( *(realized->getPKey()), realized ) );
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
		size_t len = allISOLang->size();
		std::vector<cfsec::ICFSecISOLangObj*> arr;
		auto valIter = allISOLang->begin();
		size_t idx = 0;
		while( valIter != allISOLang->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	cfsec::ICFSecISOLangObj* CFSecISOLangTableObj::readISOLangByIdIdx( const int16_t ISOLangId, bool forceRead )
	{
		static const std::string S_ProcName( "readISOLangByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecISOLangPKey pkey;
		pkey.setRequiredISOLangId( ISOLangId );
		cfsec::ICFSecISOLangObj* obj = readISOLang( &pkey, forceRead );
		return( obj );
	}

	cfsec::ICFSecISOLangObj* CFSecISOLangTableObj::readISOLangByCode3Idx( const std::string& ISO6392Code, bool forceRead )
	{
		static const std::string S_ProcName( "readISOLangByCode3Idx" );
		static const std::string S_Realized( "realized" );
		if( indexByCode3Idx == NULL ) {
			indexByCode3Idx = new std::map< cfsec::CFSecISOLangByCode3IdxKey,
				cfsec::ICFSecISOLangObj*>();
		}
		cfsec::CFSecISOLangByCode3IdxKey key;
		key.setRequiredISO6392Code( ISO6392Code );
		cfsec::ICFSecISOLangObj* obj = NULL;
		cfsec::ICFSecISOLangObj* realized = NULL;
		if( ! forceRead ) {
			auto searchIndexByCode3Idx = indexByCode3Idx->find( key );
			if( searchIndexByCode3Idx != indexByCode3Idx->end() ) {
				// Note: obj may be null if cache misses is enabled
				obj = searchIndexByCode3Idx->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecISOLangBuff* buff = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableISOLang()->readDerivedByCode3Idx( schema->getAuthorization(),
				ISO6392Code );
			if( buff != NULL ) {
				obj = dynamic_cast<cfsec::CFSecISOLangTableObj*>( schema->getISOLangTableObj() )->newInstance();
				obj->setBuff( buff );
				realized = dynamic_cast<cfsec::ICFSecISOLangObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				indexByCode3Idx->insert( std::map< cfsec::CFSecISOLangByCode3IdxKey, cfsec::ICFSecISOLangObj*>::value_type( key, dynamic_cast<cfsec::ICFSecISOLangObj*>( realized ) ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = realized;
			}
		}
		return( obj );
	}

	std::vector<cfsec::ICFSecISOLangObj*> CFSecISOLangTableObj::readISOLangByCode2Idx( const std::string* ISO6391Code,
		bool forceRead )
	{
		static const std::string S_ProcName( "readISOLangByCode2Idx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecISOLangByCode2IdxKey key;
		if( ISO6391Code == NULL ) {
			key.setOptionalISO6391CodeNull();
		}
		else {
			key.setOptionalISO6391CodeValue( *ISO6391Code );
		}
		std::map<cfsec::CFSecISOLangPKey, cfsec::ICFSecISOLangObj*>* dict;
		std::map<cfsec::CFSecISOLangPKey, cfsec::ICFSecISOLangObj*>* oldDict;
		if( indexByCode2Idx == NULL ) {
			indexByCode2Idx = new std::map< cfsec::CFSecISOLangByCode2IdxKey,
				std::map< cfsec::CFSecISOLangPKey, cfsec::ICFSecISOLangObj*>*>();
		}
		auto searchIndexByCode2Idx = indexByCode2Idx->find( key );
		if( searchIndexByCode2Idx != indexByCode2Idx->end() ) {
			oldDict = searchIndexByCode2Idx->second;
		}
		else {
			oldDict = NULL;
		}
		if( ( oldDict != NULL ) && ( ! forceRead ) ) {
			dict = oldDict;
		}
		else {
			dict = new std::map<cfsec::CFSecISOLangPKey, cfsec::ICFSecISOLangObj*>();
			cfsec::ICFSecISOLangObj* obj;
			std::TCFLibOwningVector<cfsec::CFSecISOLangBuff*> buffList = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableISOLang()->readDerivedByCode2Idx( schema->getAuthorization(),
				ISO6391Code );
			cfsec::CFSecISOLangBuff* buff;
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = dynamic_cast<cfsec::CFSecISOLangTableObj*>( schema->getISOLangTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
				obj->setBuff( buff );
				cfsec::ICFSecISOLangObj* realized = dynamic_cast<cfsec::ICFSecISOLangObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				dict->insert( std::map< cfsec::CFSecISOLangPKey, cfsec::ICFSecISOLangObj* >::value_type( *(realized->getPKey()), realized ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = NULL;
			}
			if( oldDict != NULL ) {
				indexByCode2Idx->erase( searchIndexByCode2Idx );
				delete oldDict;
				oldDict = NULL;
			}
			indexByCode2Idx->insert( std::map< cfsec::CFSecISOLangByCode2IdxKey,
				std::map< cfsec::CFSecISOLangPKey, cfsec::ICFSecISOLangObj* >* >::value_type( key, dict ) );
		}
		size_t len = dict->size();
		std::vector<cfsec::ICFSecISOLangObj*> arr;
		arr.reserve( len );
		auto valIter = dict->begin();
		while( valIter != dict->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	cfsec::ICFSecISOLangObj* CFSecISOLangTableObj::readISOLangByLookupCode3Idx( const std::string& ISO6392Code, bool forceRead )
	{
		static const std::string S_Realized( "realized" );
		static const std::string S_Obj( "obj" );
		static const std::string S_ProcName( "readISOLangByLookupCode3Idx" );
		if( indexByCode3Idx == NULL ) {
			indexByCode3Idx = new std::map< cfsec::CFSecISOLangByCode3IdxKey,
				cfsec::ICFSecISOLangObj*>();
		}
		cfsec::CFSecISOLangByCode3IdxKey key;
		key.setRequiredISO6392Code( ISO6392Code );
		cfsec::ICFSecISOLangObj* obj = NULL;
		cfsec::ICFSecISOLangObj* realized = NULL;
		if( ! forceRead ) {
			auto searchIndexByCode3Idx = indexByCode3Idx->find( key );
			if( searchIndexByCode3Idx != indexByCode3Idx->end() ) {
				obj = searchIndexByCode3Idx->second;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecISOLangBuff* buff = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableISOLang()->readDerivedByLookupCode3Idx( schema->getAuthorization(),
				ISO6392Code );
			if( buff != NULL ) {
				obj = dynamic_cast<cfsec::ICFSecISOLangObj*>( dynamic_cast<cfsec::CFSecISOLangTableObj*>( schema->getISOLangTableObj() )->newInstance() );
				obj->setBuff( buff );
				realized = dynamic_cast<cfsec::ICFSecISOLangObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				indexByCode3Idx->insert( std::map< cfsec::CFSecISOLangByCode3IdxKey, cfsec::ICFSecISOLangObj*>::value_type( key, dynamic_cast<cfsec::ICFSecISOLangObj*>( realized ) ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = realized;
			}
		}
		return( obj );
	}

	cfsec::ICFSecISOLangObj* CFSecISOLangTableObj::readCachedISOLang( cfsec::CFSecISOLangPKey* pkey ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readISOLang" );
		cfsec::ICFSecISOLangObj* obj = NULL;
		cfsec::ICFSecISOLangObj* realized = NULL;
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			// obj could be NULL if cache misses is enabled
			obj = searchMembers->second;
			realized = obj;
		}
		return( realized );
	}

	cfsec::ICFSecISOLangObj* CFSecISOLangTableObj::readCachedISOLangByIdIdx( const int16_t ISOLangId )
	{
		static const std::string S_ProcName( "readCachedISOLangByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecISOLangPKey pkey;
		pkey.setRequiredISOLangId( ISOLangId );
		cfsec::ICFSecISOLangObj* obj = readCachedISOLang( &pkey );
		return( obj );
	}

	cfsec::ICFSecISOLangObj* CFSecISOLangTableObj::readCachedISOLangByCode3Idx( const std::string& ISO6392Code )
	{
		static const std::string S_ProcName( "readCachedISOLangByCode3Idx" );
		static const std::string S_Realized( "realized" );
		if( indexByCode3Idx == NULL ) {
			indexByCode3Idx = new std::map< cfsec::CFSecISOLangByCode3IdxKey,
				cfsec::ICFSecISOLangObj*>();
		}
		cfsec::CFSecISOLangByCode3IdxKey key;
		key.setRequiredISO6392Code( ISO6392Code );
		cfsec::ICFSecISOLangObj* obj = NULL;
		auto searchIndexByCode3Idx = indexByCode3Idx->find( key );
		if( searchIndexByCode3Idx != indexByCode3Idx->end() ) {
			// Note: obj may be null if cache misses is enabled
			obj = searchIndexByCode3Idx->second;
		}
		else {
			for( auto iterMembers = members->begin(); ( obj == NULL ) && ( iterMembers != members->end() ); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecISOLangBuff*>( obj->getBuff() ) ) != key ) {
						obj = NULL;
					}
				}
			}
		}
		return( obj );
	}

	std::vector<cfsec::ICFSecISOLangObj*> CFSecISOLangTableObj::readCachedISOLangByCode2Idx( const std::string* ISO6391Code )
	{
		static const std::string S_ProcName( "readCachedISOLangByCode2Idx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		std::vector<cfsec::ICFSecISOLangObj*> arr;
		cfsec::CFSecISOLangByCode2IdxKey key;
		if( ISO6391Code == NULL ) {
			key.setOptionalISO6391CodeNull();
		}
		else {
			key.setOptionalISO6391CodeValue( *ISO6391Code );
		}
		std::map<cfsec::CFSecISOLangPKey, cfsec::ICFSecISOLangObj*>* dict;
		if( indexByCode2Idx == NULL ) {
			return( arr );
		}
		auto searchIndexByCode2Idx = indexByCode2Idx->find( key );
		if( searchIndexByCode2Idx != indexByCode2Idx->end() ) {
			dict = searchIndexByCode2Idx->second;
			size_t len = dict->size();
			std::vector<cfsec::ICFSecISOLangObj*> arr;
			arr.reserve( len );
			auto valIter = dict->begin();
			while( valIter != dict->end() ) {
				arr.push_back( valIter->second );
				valIter ++;
			}
		}
		else {
			cfsec::ICFSecISOLangObj* obj;
			for( auto iterMembers = members->begin(); iterMembers != members->end(); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecISOLangBuff*>( obj->getBuff() ) ) == key ) {
						arr.push_back( obj );
					}
				}
			}
		}
		return( arr );
	}

	cfsec::ICFSecISOLangObj* CFSecISOLangTableObj::readCachedISOLangByLookupCode3Idx( const std::string& ISO6392Code )
	{
		static const std::string S_Realized( "realized" );
		static const std::string S_Obj( "obj" );
		static const std::string S_ProcName( "readCachedISOLangByLookupCode3Idx" );
		if( indexByCode3Idx == NULL ) {
			indexByCode3Idx = new std::map< cfsec::CFSecISOLangByCode3IdxKey,
				cfsec::ICFSecISOLangObj*>();
		}
		cfsec::CFSecISOLangByCode3IdxKey key;
		key.setRequiredISO6392Code( ISO6392Code );
		cfsec::ICFSecISOLangObj* obj = NULL;
		cfsec::ICFSecISOLangObj* realized = NULL;
		auto searchIndexByCode3Idx = indexByCode3Idx->find( key );
		if( searchIndexByCode3Idx != indexByCode3Idx->end() ) {
			obj = searchIndexByCode3Idx->second;
		}
		else {
			for( auto iterMembers = members->begin(); ( obj == NULL ) && ( iterMembers != members->end() ); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecISOLangBuff*>( obj->getBuff() ) ) != key ) {
						obj = NULL;
					}
				}
			}
		}
		return( obj );
	}

	cfsec::ICFSecISOLangObj* CFSecISOLangTableObj::updateISOLang( cfsec::ICFSecISOLangEditObj* Obj ) {
		static const std::string S_ProcName( "updateISOLang" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Updated( "updated" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecISOLangObj* obj = dynamic_cast<cfsec::ICFSecISOLangObj*>( Obj->getOrig() );
		try {
			cfsec::CFSecISOLangBuff* updated = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableISOLang()->updateISOLang( schema->getAuthorization(),
				dynamic_cast<cfsec::CFSecISOLangBuff*>( Obj->getISOLangBuff()->clone() ) );
			if( updated == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Updated );
			}
			obj = dynamic_cast<cfsec::ICFSecISOLangObj*>( dynamic_cast<cfsec::CFSecISOLangTableObj*>( schema->getISOLangTableObj() )->newInstance() );
			obj->setBuff( updated );
			obj = dynamic_cast<cfsec::ICFSecISOLangObj*>( obj->realize() );
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

	void CFSecISOLangTableObj::deleteISOLang( cfsec::ICFSecISOLangEditObj* Obj ) {
		cfsec::ICFSecISOLangObj* obj = Obj;
		dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableISOLang()->deleteISOLang( schema->getAuthorization(),
			obj->getISOLangBuff() );
		deepDisposeByIdIdx( obj->getRequiredISOLangId() );
	}

	void CFSecISOLangTableObj::deleteISOLangByIdIdx( const int16_t ISOLangId )
	{
		cfsec::CFSecISOLangPKey pkey;
		pkey.setRequiredISOLangId( ISOLangId );
		cfsec::ICFSecISOLangObj* obj = readISOLang( &pkey, true );
		if( obj != NULL ) {
			cfsec::ICFSecISOLangEditObj* editObj = dynamic_cast<cfsec::ICFSecISOLangEditObj*>( obj->getEdit() );
			if( editObj == NULL ) {
				editObj = dynamic_cast<cfsec::ICFSecISOLangEditObj*>( obj->beginEdit() );
			}
			if( editObj != NULL ) {
				editObj->deleteInstance();
				editObj = NULL;
			}
		}
	}

	void CFSecISOLangTableObj::deleteISOLangByCode3Idx( const std::string& ISO6392Code )
	{
		if( indexByCode3Idx == NULL ) {
			indexByCode3Idx = new std::map< cfsec::CFSecISOLangByCode3IdxKey,
				cfsec::ICFSecISOLangObj*>();
		}
		cfsec::CFSecISOLangByCode3IdxKey key;
		key.setRequiredISO6392Code( ISO6392Code );
		cfsec::ICFSecISOLangObj* obj = NULL;
		auto searchIndexByCode3Idx = indexByCode3Idx->find( key );
		if( searchIndexByCode3Idx != indexByCode3Idx->end() ) {
			dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableISOLang()->deleteISOLangByCode3Idx( schema->getAuthorization(),
				ISO6392Code );
		}
		else {
			dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableISOLang()->deleteISOLangByCode3Idx( schema->getAuthorization(),
				ISO6392Code );
		}
		deepDisposeByCode3Idx( ISO6392Code );
	}

	void CFSecISOLangTableObj::deleteISOLangByCode2Idx( const std::string* ISO6391Code )
	{
		dynamic_cast<cfsec::ICFSecSchema*>( schema->getBackingStore() )->getTableISOLang()->deleteISOLangByCode2Idx( schema->getAuthorization(),
				ISO6391Code );
		deepDisposeByCode2Idx( ISO6391Code );
	}

	void CFSecISOLangTableObj::reallyDetachFromIndexesISOLang( cfsec::ICFSecISOLangObj* Obj ) {
		static const std::string S_ProcName( "reallyDetachFromIndexesISOLang" );
		static const std::string S_Obj( "Obj" );
		static const std::string S_ExistingObj( "ExistingObj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfsec::ICFSecISOLangObj* obj = Obj;
		cfsec::CFSecISOLangPKey* pkey = obj->getPKey();
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			cfsec::ICFSecISOLangObj* existingObj = searchMembers->second;
			if( existingObj == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_ExistingObj );
			}
			if( indexByCode3Idx != NULL ) {
				cfsec::CFSecISOLangByCode3IdxKey keyCode3Idx;
				keyCode3Idx.setRequiredISO6392Code( obj->getRequiredISO6392Code() );
				auto removalProbe = indexByCode3Idx->find( keyCode3Idx );
				if( removalProbe != indexByCode3Idx->end() ) {
					indexByCode3Idx->erase( removalProbe );
				}
			}

			if( indexByCode2Idx != NULL ) {
				cfsec::CFSecISOLangByCode2IdxKey keyCode2Idx;
				if( obj->isOptionalISO6391CodeNull() ) {
					keyCode2Idx.setOptionalISO6391CodeNull();
				}
				else {
					keyCode2Idx.setOptionalISO6391CodeValue( obj->getOptionalISO6391CodeValue() );
				}
				auto searchCode2Idx = indexByCode2Idx->find( keyCode2Idx );
				if( searchCode2Idx != indexByCode2Idx->end() ) {
					std::map<cfsec::CFSecISOLangPKey, cfsec::ICFSecISOLangObj*>* mapCode2Idx = searchCode2Idx->second;
					if( mapCode2Idx != NULL ) {
						auto removalProbe = mapCode2Idx->find( *(obj->getPKey()) );
						if( removalProbe != mapCode2Idx->end() ) {
							mapCode2Idx->erase( removalProbe );
							if( mapCode2Idx->empty() ) {
								delete mapCode2Idx;
								mapCode2Idx = NULL;
								indexByCode2Idx->erase( searchCode2Idx );
							}
						}
					}
				}
			}

			members->erase( searchMembers );
		}
	}


}
