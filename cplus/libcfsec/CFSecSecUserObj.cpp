// Description: C++18 base object instance implementation for CFSec SecUser.

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
#include <cfsecobj/CFSecSecUserObj.hpp>

namespace cfsec {

	const std::string CFSecSecUserObj::CLASS_NAME( "CFSecSecUserObj" );
	const classcode_t CFSecSecUserObj::CLASS_CODE = 0xa011L;

	int32_t CFSecSecUserObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	const uuid_ptr_t CFSecSecUserObj::getRequiredSecUserId() {
		return( getPKey()->getRequiredSecUserId() );
	}

	const uuid_ptr_t CFSecSecUserObj::getRequiredSecUserIdReference() {
		return( getPKey()->getRequiredSecUserIdReference() );
	}

	const std::string& CFSecSecUserObj::getRequiredLoginId() {
		return( getSecUserBuff()->getRequiredLoginId() );
	}

	const std::string* CFSecSecUserObj::getRequiredLoginIdReference() {
		return( getSecUserBuff()->getRequiredLoginIdReference() );
	}

	const std::string& CFSecSecUserObj::getRequiredEMailAddress() {
		return( getSecUserBuff()->getRequiredEMailAddress() );
	}

	const std::string* CFSecSecUserObj::getRequiredEMailAddressReference() {
		return( getSecUserBuff()->getRequiredEMailAddressReference() );
	}

	bool CFSecSecUserObj::isOptionalEMailConfirmUuidNull() {
		return( getSecUserBuff()->isOptionalEMailConfirmUuidNull() );
	}

	const uuid_ptr_t CFSecSecUserObj::getOptionalEMailConfirmUuidValue() {
		return( getSecUserBuff()->getOptionalEMailConfirmUuidValue() );
	}

	const uuid_ptr_t CFSecSecUserObj::getOptionalEMailConfirmUuidReference() {
		return( getSecUserBuff()->getOptionalEMailConfirmUuidReference() );
	}

	bool CFSecSecUserObj::isOptionalDfltDevUserIdNull() {
		return( getSecUserBuff()->isOptionalDfltDevUserIdNull() );
	}

	const uuid_ptr_t CFSecSecUserObj::getOptionalDfltDevUserIdValue() {
		return( getSecUserBuff()->getOptionalDfltDevUserIdValue() );
	}

	const uuid_ptr_t CFSecSecUserObj::getOptionalDfltDevUserIdReference() {
		return( getSecUserBuff()->getOptionalDfltDevUserIdReference() );
	}

	bool CFSecSecUserObj::isOptionalDfltDevNameNull() {
		return( getSecUserBuff()->isOptionalDfltDevNameNull() );
	}

	const std::string& CFSecSecUserObj::getOptionalDfltDevNameValue() {
		return( getSecUserBuff()->getOptionalDfltDevNameValue() );
	}

	const std::string* CFSecSecUserObj::getOptionalDfltDevNameReference() {
		return( getSecUserBuff()->getOptionalDfltDevNameReference() );
	}

	const std::string& CFSecSecUserObj::getRequiredPasswordHash() {
		return( getSecUserBuff()->getRequiredPasswordHash() );
	}

	const std::string* CFSecSecUserObj::getRequiredPasswordHashReference() {
		return( getSecUserBuff()->getRequiredPasswordHashReference() );
	}

	bool CFSecSecUserObj::isOptionalPasswordResetUuidNull() {
		return( getSecUserBuff()->isOptionalPasswordResetUuidNull() );
	}

	const uuid_ptr_t CFSecSecUserObj::getOptionalPasswordResetUuidValue() {
		return( getSecUserBuff()->getOptionalPasswordResetUuidValue() );
	}

	const uuid_ptr_t CFSecSecUserObj::getOptionalPasswordResetUuidReference() {
		return( getSecUserBuff()->getOptionalPasswordResetUuidReference() );
	}


	std::vector<cfsec::ICFSecSecDeviceObj*> CFSecSecUserObj::getOptionalComponentsSecDev( bool forceRead ) {
		std::vector<cfsec::ICFSecSecDeviceObj*> retval;
		retval = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecDeviceTableObj()->readSecDeviceByUserIdx( getPKey()->getRequiredSecUserId(),
			forceRead );
		return( retval );
	}

	cfsec::ICFSecSecDeviceObj* CFSecSecUserObj::getOptionalLookupDefDev( bool forceRead ) {
		cfsec::ICFSecSecDeviceObj* retobj = NULL;
		bool anyMissing = false;
			if( getSecUserBuff()->isOptionalDfltDevUserIdNull() ) {
				anyMissing = true;
			}
			if( getSecUserBuff()->isOptionalDfltDevNameNull() ) {
				anyMissing = true;
			}
		if( ! anyMissing ) {
			retobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecDeviceTableObj()->readSecDeviceByIdIdx( getSecUserBuff()->getOptionalDfltDevUserIdValue(),
					getSecUserBuff()->getOptionalDfltDevNameValue(), forceRead );
		}
		return( retobj );
	}

	std::vector<cfsec::ICFSecSecSessionObj*> CFSecSecUserObj::getOptionalComponentsSecSess( bool forceRead ) {
		std::vector<cfsec::ICFSecSecSessionObj*> retval;
		retval = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecSessionTableObj()->readSecSessionBySecUserIdx( getPKey()->getRequiredSecUserId(),
			forceRead );
		return( retval );
	}

	std::vector<cfsec::ICFSecSecSessionObj*> CFSecSecUserObj::getOptionalChildrenSecProxy( bool forceRead ) {
		std::vector<cfsec::ICFSecSecSessionObj*> retval;
		retval = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecSessionTableObj()->readSecSessionBySecProxyIdx( getPKey()->getRequiredSecUserIdReference(),
			forceRead );
		return( retval );
	}

	std::vector<cfsec::ICFSecSecGrpMembObj*> CFSecSecUserObj::getOptionalChildrenSecGrpMemb( bool forceRead ) {
		std::vector<cfsec::ICFSecSecGrpMembObj*> retval;
		retval = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecGrpMembTableObj()->readSecGrpMembByUserIdx( getPKey()->getRequiredSecUserId(),
			forceRead );
		return( retval );
	}

	std::vector<cfsec::ICFSecTSecGrpMembObj*> CFSecSecUserObj::getOptionalChildrenTSecGrpMemb( bool forceRead ) {
		std::vector<cfsec::ICFSecTSecGrpMembObj*> retval;
		retval = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getTSecGrpMembTableObj()->readTSecGrpMembByUserIdx( getPKey()->getRequiredSecUserId(),
			forceRead );
		return( retval );
	}

	CFSecSecUserObj::CFSecSecUserObj()
	: ICFSecSecUserObj()
	{
		schema = NULL;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFSecSecUserObj::CFSecSecUserObj( cfsec::ICFSecSchemaObj* argSchema )
	: ICFSecSecUserObj()
	{
		schema = argSchema;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFSecSecUserObj::~CFSecSecUserObj() {
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

	cfsec::CFSecSecUserBuff* CFSecSecUserObj::getBuff() {
		if( buff == NULL ) {
			if( isNew ) {
				buff = new cfsec::CFSecSecUserBuff();
				copyBuffToPKey();
			}
			else {
				// Read the data buff via the backing store
				buff = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecUser()->readDerivedByIdIdx( dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getAuthorization(),
						getPKey()->getRequiredSecUserId() );
			}
		}
		return( buff );
	}

	void CFSecSecUserObj::setBuff( cfsec::CFSecSecUserBuff* value ) {
		if( ( buff != NULL ) && ( buff != value ) ) {
			delete buff;
			buff = NULL;
		}
		buff = value;
		if( buff != NULL ) {
			copyBuffToPKey();
		}
	}

	const std::string& CFSecSecUserObj::getClassName() const {
		return( CLASS_NAME );
	}

	const classcode_t CFSecSecUserObj::getClassCode() const {
		return( CLASS_CODE );
	}

	bool CFSecSecUserObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfsec::CFSecSecUserBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFSecSecUserObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecSecUserObj" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_SecUserId( "SecUserId" );
		static const std::string S_LoginId( "LoginId" );
		static const std::string S_EMailAddress( "EMailAddress" );
		static const std::string S_EMailConfirmUuid( "EMailConfirmUuid" );
		static const std::string S_DfltDevUserId( "DfltDevUserId" );
		static const std::string S_DfltDevName( "DfltDevName" );
		static const std::string S_PasswordHash( "PasswordHash" );
		static const std::string S_PasswordResetUuid( "PasswordResetUuid" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFSecSecUserObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFSecSecUserObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFSecSecUserObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFSecSecUserObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFSecSecUserObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_SecUserId, CFSecSecUserObj::getRequiredSecUserId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_LoginId, CFSecSecUserObj::getRequiredLoginId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_EMailAddress, CFSecSecUserObj::getRequiredEMailAddress() ) );
		if( ! CFSecSecUserObj::isOptionalEMailConfirmUuidNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_EMailConfirmUuid, CFSecSecUserObj::getOptionalEMailConfirmUuidValue() ) );
		}
		if( ! CFSecSecUserObj::isOptionalDfltDevUserIdNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_DfltDevUserId, CFSecSecUserObj::getOptionalDfltDevUserIdValue() ) );
		}
		if( ! CFSecSecUserObj::isOptionalDfltDevNameNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_DfltDevName, CFSecSecUserObj::getOptionalDfltDevNameValue() ) );
		}
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_PasswordHash, CFSecSecUserObj::getRequiredPasswordHash() ) );
		if( ! CFSecSecUserObj::isOptionalPasswordResetUuidNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_PasswordResetUuid, CFSecSecUserObj::getOptionalPasswordResetUuidValue() ) );
		}
		ret.append( S_Postamble );
		return( ret );
	}

	std::string CFSecSecUserObj::getObjName() {
		std::string objName( CLASS_NAME );
		objName.clear();
		objName.append( getRequiredLoginId() );
		return( objName );
	}

	const std::string CFSecSecUserObj::getGenDefName() {
		return( cfsec::CFSecSecUserBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFSecSecUserObj::getScope() {
		return( NULL );
	}

	cflib::ICFLibAnyObj* CFSecSecUserObj::getObjScope() {
		return( NULL );
	}

	cflib::ICFLibAnyObj* CFSecSecUserObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFSecSecUserObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFSecSecUserObj::getNamedObject( const std::string& objName ) {
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
		if( subObj == NULL ) {
			subObj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecDeviceTableObj()->readSecDeviceByLookupNameIdx( getRequiredSecUserId(),
				nextName,
				false );
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

	std::string CFSecSecUserObj::getObjQualifiedName() {
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

	std::string CFSecSecUserObj::getObjFullName() {
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

	cfsec::ICFSecSecUserObj* CFSecSecUserObj::realize() {
		cfsec::ICFSecSecUserObj* retobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecUserTableObj()->realizeSecUser(
			(cfsec::ICFSecSecUserObj*)this );
		return( dynamic_cast<cfsec::ICFSecSecUserObj*>( retobj ) );
	}

	cfsec::ICFSecSecUserObj* CFSecSecUserObj::read( bool forceRead ) {
		cfsec::ICFSecSecUserObj* retobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getSecUserBuff()->getRequiredSecUserId(), forceRead );
		return( dynamic_cast<cfsec::ICFSecSecUserObj*>( retobj ) );
	}

	cfsec::ICFSecSecUserTableObj* CFSecSecUserObj::getSecUserTable() {
		return( dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecUserTableObj() );
	}

	cfsec::ICFSecSchemaObj* CFSecSecUserObj::getSchema() {
		return( schema );
	}

	void CFSecSecUserObj::setSchema( cfsec::ICFSecSchemaObj* value ) {
		schema = value;
	}

	cfsec::CFSecSecUserPKey* CFSecSecUserObj::getPKey() {
		if( pKey == NULL ) {
			pKey = new cfsec::CFSecSecUserPKey();
		}
		return( pKey );
	}

	void CFSecSecUserObj::setPKey( cfsec::CFSecSecUserPKey* value ) {
		if( ( pKey != NULL ) && ( pKey != value ) ) {
			delete pKey;
			pKey = NULL;
		}
		if( value != NULL ) {
			pKey = new cfsec::CFSecSecUserPKey();
			*pKey = *value;
			copyPKeyToBuff();
		}
	}

	bool CFSecSecUserObj::getIsNew() {
		return( isNew );
	}

	void CFSecSecUserObj::setIsNew( bool value ) {
		isNew = value;
	}

	cfsec::ICFSecSecUserEditObj* CFSecSecUserObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_EditAlreadyOpen( "An edit is already open" );
		if( edit != NULL ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_ProcName, S_EditAlreadyOpen );
		}
		if( ! getIsNew() ) {
			cfsec::ICFSecSecUserObj* lockobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecUserTableObj()->lockSecUser( getPKey() );
			lockobj->realize();
		}
		edit = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecUserTableObj()->newEditInstance( this );
		return( dynamic_cast<cfsec::ICFSecSecUserEditObj*>( edit ) );
	}

	void CFSecSecUserObj::endEdit() {
		if( edit != NULL ) {
			delete edit;
			edit = NULL;
		}
	}

	cfsec::ICFSecSecUserEditObj* CFSecSecUserObj::getEdit() {
		return( edit );
	}

	cfsec::ICFSecSecUserEditObj* CFSecSecUserObj::getSecUserEdit() {
		return( dynamic_cast<cfsec::ICFSecSecUserEditObj*>( edit ) );
	}

	cfsec::ICFSecSecUserObj* CFSecSecUserObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getSecUserBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFSecSecUserObj::getCreatedAt() {
		return( getSecUserBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFSecSecUserObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getSecUserBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFSecSecUserObj::getUpdatedAt() {
		return( getSecUserBuff()->getUpdatedAt() );
	}

	void CFSecSecUserObj::copyPKeyToBuff() {
		cfsec::CFSecSecUserPKey* tablePKey = getPKey();
		cfsec::CFSecSecUserBuff* tableBuff = getSecUserEditBuff();
		if( tableBuff != NULL ) {
			tableBuff->setRequiredSecUserId( tablePKey->getRequiredSecUserId() );
		}
		if( edit != NULL ) {
			edit->copyPKeyToBuff();
		}
	}

	void CFSecSecUserObj::copyBuffToPKey() {
		cfsec::CFSecSecUserPKey* tablePKey = getPKey();
		cfsec::CFSecSecUserBuff* tableBuff = getSecUserBuff();
		tablePKey->setRequiredSecUserId( tableBuff->getRequiredSecUserId() );
	}

}
