// Description: C++18 base object instance implementation for CFSec TSecGrpInc.

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
#include <cfsecobj/CFSecTSecGrpIncObj.hpp>

namespace cfsec {

	const std::string CFSecTSecGrpIncObj::CLASS_NAME( "CFSecTSecGrpIncObj" );
	const classcode_t CFSecTSecGrpIncObj::CLASS_CODE = 0xa017L;

	int32_t CFSecTSecGrpIncObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	const int64_t CFSecTSecGrpIncObj::getRequiredTenantId() {
		return( getPKey()->getRequiredTenantId() );
	}

	const int64_t* CFSecTSecGrpIncObj::getRequiredTenantIdReference() {
		return( getPKey()->getRequiredTenantIdReference() );
	}

	const int64_t CFSecTSecGrpIncObj::getRequiredTSecGrpIncId() {
		return( getPKey()->getRequiredTSecGrpIncId() );
	}

	const int64_t* CFSecTSecGrpIncObj::getRequiredTSecGrpIncIdReference() {
		return( getPKey()->getRequiredTSecGrpIncIdReference() );
	}

	const int32_t CFSecTSecGrpIncObj::getRequiredTSecGroupId() {
		return( getTSecGrpIncBuff()->getRequiredTSecGroupId() );
	}

	const int32_t* CFSecTSecGrpIncObj::getRequiredTSecGroupIdReference() {
		return( getTSecGrpIncBuff()->getRequiredTSecGroupIdReference() );
	}

	const int32_t CFSecTSecGrpIncObj::getRequiredIncludeGroupId() {
		return( getTSecGrpIncBuff()->getRequiredIncludeGroupId() );
	}

	const int32_t* CFSecTSecGrpIncObj::getRequiredIncludeGroupIdReference() {
		return( getTSecGrpIncBuff()->getRequiredIncludeGroupIdReference() );
	}


	cfsec::ICFSecTenantObj* CFSecTSecGrpIncObj::getRequiredOwnerTenant( bool forceRead ) {
		cfsec::ICFSecTenantObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getTenantTableObj()->readTenantByIdIdx( getPKey()->getRequiredTenantId(), forceRead );
		}
		return( retobj );
	}

	cfsec::ICFSecTSecGroupObj* CFSecTSecGrpIncObj::getRequiredContainerGroup( bool forceRead ) {
		cfsec::ICFSecTSecGroupObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getTSecGroupTableObj()->readTSecGroupByIdIdx( getPKey()->getRequiredTenantId(),
					getTSecGrpIncBuff()->getRequiredTSecGroupId(), forceRead );
		}
		return( retobj );
	}

	cfsec::ICFSecTSecGroupObj* CFSecTSecGrpIncObj::getRequiredParentSubGroup( bool forceRead ) {
		cfsec::ICFSecTSecGroupObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getTSecGroupTableObj()->readTSecGroupByIdIdx( getPKey()->getRequiredTenantId(),
					getTSecGrpIncBuff()->getRequiredIncludeGroupId(), forceRead );
		}
		return( retobj );
	}

	CFSecTSecGrpIncObj::CFSecTSecGrpIncObj()
	: ICFSecTSecGrpIncObj()
	{
		schema = NULL;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFSecTSecGrpIncObj::CFSecTSecGrpIncObj( cfsec::ICFSecSchemaObj* argSchema )
	: ICFSecTSecGrpIncObj()
	{
		schema = argSchema;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFSecTSecGrpIncObj::~CFSecTSecGrpIncObj() {
		schema = NULL;
		if( edit != NULL ) {
			delete edit;
			edit = NULL;
		}
		if( buff != NULL ) {
			delete buff;
			buff = NULL;
		}
		if( pKey != NULL ) {
			delete pKey;
			pKey = NULL;
		}

	}

	cfsec::CFSecTSecGrpIncBuff* CFSecTSecGrpIncObj::getBuff() {
		if( buff == NULL ) {
			if( isNew ) {
				buff = new cfsec::CFSecTSecGrpIncBuff();
				copyBuffToPKey();
			}
			else {
				// Read the data buff via the backing store
				buff = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableTSecGrpInc()->readDerivedByIdIdx( dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getAuthorization(),
						getPKey()->getRequiredTenantId(),
						getPKey()->getRequiredTSecGrpIncId() );
			}
		}
		return( buff );
	}

	void CFSecTSecGrpIncObj::setBuff( cfsec::CFSecTSecGrpIncBuff* value ) {
		if( ( buff != NULL ) && ( buff != value ) ) {
			delete buff;
			buff = NULL;
		}
		buff = value;
		if( buff != NULL ) {
			copyBuffToPKey();
		}
	}

	const std::string& CFSecTSecGrpIncObj::getClassName() const {
		return( CLASS_NAME );
	}

	const classcode_t CFSecTSecGrpIncObj::getClassCode() const {
		return( CLASS_CODE );
	}

	bool CFSecTSecGrpIncObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfsec::CFSecTSecGrpIncBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFSecTSecGrpIncObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecTSecGrpIncObj" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_TenantId( "TenantId" );
		static const std::string S_TSecGrpIncId( "TSecGrpIncId" );
		static const std::string S_TSecGroupId( "TSecGroupId" );
		static const std::string S_IncludeGroupId( "IncludeGroupId" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFSecTSecGrpIncObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFSecTSecGrpIncObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFSecTSecGrpIncObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFSecTSecGrpIncObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFSecTSecGrpIncObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_TenantId, CFSecTSecGrpIncObj::getRequiredTenantId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_TSecGrpIncId, CFSecTSecGrpIncObj::getRequiredTSecGrpIncId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_TSecGroupId, CFSecTSecGrpIncObj::getRequiredTSecGroupId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_IncludeGroupId, CFSecTSecGrpIncObj::getRequiredIncludeGroupId() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	std::string CFSecTSecGrpIncObj::getObjName() {
		std::string objName( CLASS_NAME );
		int64_t val = getRequiredTSecGrpIncId();
		objName = cflib::CFLibXmlUtil::formatInt64( val );
		return( objName );
	}

	const std::string CFSecTSecGrpIncObj::getGenDefName() {
		return( cfsec::CFSecTSecGrpIncBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFSecTSecGrpIncObj::getScope() {
		cfsec::ICFSecTSecGroupObj* scope = getRequiredContainerGroup();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFSecTSecGrpIncObj::getObjScope() {
		cfsec::ICFSecTSecGroupObj* scope = getRequiredContainerGroup();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFSecTSecGrpIncObj::getObjQualifier( const classcode_t* qualifyingClass ) {
		cflib::ICFLibAnyObj* container = this;
		if( qualifyingClass != NULL ) {
			while( container != NULL ) {
				if( container->getClassCode() == cfsec::CFSecClusterBuff::CLASS_CODE ) {
					break;
				}
				else if( container->getClassCode() == cfsec::CFSecTenantBuff::CLASS_CODE ) {
					break;
				}
				else if( container->implementsClassCode( *qualifyingClass ) ) {
					break;
				}
				container = container->getObjScope();
			}
		}
		else {
			while( container != NULL ) {
				if( container->getClassCode() == cfsec::CFSecClusterBuff::CLASS_CODE ) {
					break;
				}
				else if( container->getClassCode() == cfsec::CFSecTenantBuff::CLASS_CODE ) {
					break;
				}
				container = container->getObjScope();
			}
		}
		return( container );
	}

	cflib::ICFLibAnyObj* CFSecTSecGrpIncObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFSecTSecGrpIncObj::getNamedObject( const std::string& objName ) {
		std::string nextName;
		std::string remainingName;
		cflib::ICFLibAnyObj* subObj = NULL;
		cflib::ICFLibAnyObj* retObj;
		int32_t nextDot = objName.find( '.' );
		if( nextDot >= 0 ) {
			nextName = objName.substr( 0, nextDot );
			remainingName = objName.substr( nextDot + 1 );
		}
		else {
			nextName.clear();
			nextName.append( objName );
			remainingName.clear();
		}
		if( remainingName.length() <= 0 ) {
			retObj = subObj;
		}
		else if( subObj == NULL ) {
			retObj = NULL;
		}
		else {
			retObj = subObj->getNamedObject( remainingName );
		}
		return( retObj );
	}

	std::string CFSecTSecGrpIncObj::getObjQualifiedName() {
		const static std::string S_Dot( "." );
		std::string qualName( getObjName() );
		cflib::ICFLibAnyObj* container = getObjScope();
		std::string containerName;
		std::string buildName;
		while( container != NULL ) {
			if( container->getClassCode() == cfsec::CFSecClusterBuff::CLASS_CODE ) {
				container = NULL;
			}
			else if( container->getClassCode() == cfsec::CFSecTenantBuff::CLASS_CODE ) {
				container = NULL;
			}
			else {
				containerName = container->getObjName();
				buildName.clear();
				buildName.append( containerName );
				buildName.append( S_Dot );
				buildName.append( qualName );
				qualName.clear();
				qualName.append( buildName );
				container = container->getObjScope();
			}
		}
		return( qualName );
	}

	std::string CFSecTSecGrpIncObj::getObjFullName() {
		const static std::string S_Dot( "." );
		std::string fullName = getObjName();
		cflib::ICFLibAnyObj* container = getObjScope();
		std::string containerName;
		std::string buildName;
		while( container != NULL ) {
			if( container->getClassCode() == cfsec::CFSecClusterBuff::CLASS_CODE ) {
				container = NULL;
			}
			else if( container->getClassCode() == cfsec::CFSecTenantBuff::CLASS_CODE ) {
				container = NULL;
			}
			else {
				containerName = container->getObjName();
				buildName.clear();
				buildName.append( containerName );
				buildName.append( S_Dot );
				buildName.append( fullName );
				fullName.clear();
				fullName.append( buildName );
				container = container->getObjScope();
			}
		}
		return( fullName );
	}

	cfsec::ICFSecTSecGrpIncObj* CFSecTSecGrpIncObj::realize() {
		cfsec::ICFSecTSecGrpIncObj* retobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getTSecGrpIncTableObj()->realizeTSecGrpInc(
			(cfsec::ICFSecTSecGrpIncObj*)this );
		return( dynamic_cast<cfsec::ICFSecTSecGrpIncObj*>( retobj ) );
	}

	cfsec::ICFSecTSecGrpIncObj* CFSecTSecGrpIncObj::read( bool forceRead ) {
		cfsec::ICFSecTSecGrpIncObj* retobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getTSecGrpIncTableObj()->readTSecGrpIncByIdIdx( getTSecGrpIncBuff()->getRequiredTenantId(),
		getTSecGrpIncBuff()->getRequiredTSecGrpIncId(), forceRead );
		return( dynamic_cast<cfsec::ICFSecTSecGrpIncObj*>( retobj ) );
	}

	cfsec::ICFSecTSecGrpIncTableObj* CFSecTSecGrpIncObj::getTSecGrpIncTable() {
		return( dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getTSecGrpIncTableObj() );
	}

	cfsec::ICFSecSchemaObj* CFSecTSecGrpIncObj::getSchema() {
		return( schema );
	}

	void CFSecTSecGrpIncObj::setSchema( cfsec::ICFSecSchemaObj* value ) {
		schema = value;
	}

	cfsec::CFSecTSecGrpIncPKey* CFSecTSecGrpIncObj::getPKey() {
		if( pKey == NULL ) {
			pKey = new cfsec::CFSecTSecGrpIncPKey();
		}
		return( pKey );
	}

	void CFSecTSecGrpIncObj::setPKey( cfsec::CFSecTSecGrpIncPKey* value ) {
		if( ( pKey != NULL ) && ( pKey != value ) ) {
			delete pKey;
			pKey = NULL;
		}
		if( value != NULL ) {
			pKey = new cfsec::CFSecTSecGrpIncPKey();
			*pKey = *value;
			copyPKeyToBuff();
		}
	}

	bool CFSecTSecGrpIncObj::getIsNew() {
		return( isNew );
	}

	void CFSecTSecGrpIncObj::setIsNew( bool value ) {
		isNew = value;
	}

	cfsec::ICFSecTSecGrpIncEditObj* CFSecTSecGrpIncObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_EditAlreadyOpen( "An edit is already open" );
		if( edit != NULL ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_ProcName, S_EditAlreadyOpen );
		}
		if( ! getIsNew() ) {
			cfsec::ICFSecTSecGrpIncObj* lockobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getTSecGrpIncTableObj()->lockTSecGrpInc( getPKey() );
			lockobj->realize();
		}
		edit = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getTSecGrpIncTableObj()->newEditInstance( this );
		return( dynamic_cast<cfsec::ICFSecTSecGrpIncEditObj*>( edit ) );
	}

	void CFSecTSecGrpIncObj::endEdit() {
		if( edit != NULL ) {
			delete edit;
			edit = NULL;
		}
	}

	cfsec::ICFSecTSecGrpIncEditObj* CFSecTSecGrpIncObj::getEdit() {
		return( edit );
	}

	cfsec::ICFSecTSecGrpIncEditObj* CFSecTSecGrpIncObj::getTSecGrpIncEdit() {
		return( dynamic_cast<cfsec::ICFSecTSecGrpIncEditObj*>( edit ) );
	}

	cfsec::ICFSecSecUserObj* CFSecTSecGrpIncObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getTSecGrpIncBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFSecTSecGrpIncObj::getCreatedAt() {
		return( getTSecGrpIncBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFSecTSecGrpIncObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getTSecGrpIncBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFSecTSecGrpIncObj::getUpdatedAt() {
		return( getTSecGrpIncBuff()->getUpdatedAt() );
	}

	void CFSecTSecGrpIncObj::copyPKeyToBuff() {
		cfsec::CFSecTSecGrpIncPKey* tablePKey = getPKey();
		cfsec::CFSecTSecGrpIncBuff* tableBuff = getTSecGrpIncEditBuff();
		if( tableBuff != NULL ) {
			tableBuff->setRequiredTenantId( tablePKey->getRequiredTenantId() );
			tableBuff->setRequiredTSecGrpIncId( tablePKey->getRequiredTSecGrpIncId() );
		}
		if( edit != NULL ) {
			edit->copyPKeyToBuff();
		}
	}

	void CFSecTSecGrpIncObj::copyBuffToPKey() {
		cfsec::CFSecTSecGrpIncPKey* tablePKey = getPKey();
		cfsec::CFSecTSecGrpIncBuff* tableBuff = getTSecGrpIncBuff();
		tablePKey->setRequiredTenantId( tableBuff->getRequiredTenantId() );
		tablePKey->setRequiredTSecGrpIncId( tableBuff->getRequiredTSecGrpIncId() );
	}

}
