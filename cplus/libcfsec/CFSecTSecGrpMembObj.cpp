// Description: C++18 base object instance implementation for CFSec TSecGrpMemb.

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
#include <cfsecobj/CFSecTSecGrpMembObj.hpp>

namespace cfsec {

	const std::string CFSecTSecGrpMembObj::CLASS_NAME( "CFSecTSecGrpMembObj" );
	const classcode_t CFSecTSecGrpMembObj::CLASS_CODE = 0xa018L;

	int32_t CFSecTSecGrpMembObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	const int64_t CFSecTSecGrpMembObj::getRequiredTenantId() {
		return( getPKey()->getRequiredTenantId() );
	}

	const int64_t* CFSecTSecGrpMembObj::getRequiredTenantIdReference() {
		return( getPKey()->getRequiredTenantIdReference() );
	}

	const int64_t CFSecTSecGrpMembObj::getRequiredTSecGrpMembId() {
		return( getPKey()->getRequiredTSecGrpMembId() );
	}

	const int64_t* CFSecTSecGrpMembObj::getRequiredTSecGrpMembIdReference() {
		return( getPKey()->getRequiredTSecGrpMembIdReference() );
	}

	const int32_t CFSecTSecGrpMembObj::getRequiredTSecGroupId() {
		return( getTSecGrpMembBuff()->getRequiredTSecGroupId() );
	}

	const int32_t* CFSecTSecGrpMembObj::getRequiredTSecGroupIdReference() {
		return( getTSecGrpMembBuff()->getRequiredTSecGroupIdReference() );
	}

	const uuid_ptr_t CFSecTSecGrpMembObj::getRequiredSecUserId() {
		return( getTSecGrpMembBuff()->getRequiredSecUserId() );
	}

	const uuid_ptr_t CFSecTSecGrpMembObj::getRequiredSecUserIdReference() {
		return( getTSecGrpMembBuff()->getRequiredSecUserIdReference() );
	}


	cfsec::ICFSecTenantObj* CFSecTSecGrpMembObj::getRequiredOwnerTenant( bool forceRead ) {
		cfsec::ICFSecTenantObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getTenantTableObj()->readTenantByIdIdx( getPKey()->getRequiredTenantId(), forceRead );
		}
		return( retobj );
	}

	cfsec::ICFSecTSecGroupObj* CFSecTSecGrpMembObj::getRequiredContainerGroup( bool forceRead ) {
		cfsec::ICFSecTSecGroupObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getTSecGroupTableObj()->readTSecGroupByIdIdx( getPKey()->getRequiredTenantId(),
					getTSecGrpMembBuff()->getRequiredTSecGroupId(), forceRead );
		}
		return( retobj );
	}

	cfsec::ICFSecSecUserObj* CFSecTSecGrpMembObj::getRequiredParentUser( bool forceRead ) {
		cfsec::ICFSecSecUserObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getTSecGrpMembBuff()->getRequiredSecUserId(), forceRead );
		}
		return( retobj );
	}

	CFSecTSecGrpMembObj::CFSecTSecGrpMembObj()
	: ICFSecTSecGrpMembObj()
	{
		schema = NULL;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFSecTSecGrpMembObj::CFSecTSecGrpMembObj( cfsec::ICFSecSchemaObj* argSchema )
	: ICFSecTSecGrpMembObj()
	{
		schema = argSchema;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFSecTSecGrpMembObj::~CFSecTSecGrpMembObj() {
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

	cfsec::CFSecTSecGrpMembBuff* CFSecTSecGrpMembObj::getBuff() {
		if( buff == NULL ) {
			if( isNew ) {
				buff = new cfsec::CFSecTSecGrpMembBuff();
				copyBuffToPKey();
			}
			else {
				// Read the data buff via the backing store
				buff = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableTSecGrpMemb()->readDerivedByIdIdx( dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getAuthorization(),
						getPKey()->getRequiredTenantId(),
						getPKey()->getRequiredTSecGrpMembId() );
			}
		}
		return( buff );
	}

	void CFSecTSecGrpMembObj::setBuff( cfsec::CFSecTSecGrpMembBuff* value ) {
		if( ( buff != NULL ) && ( buff != value ) ) {
			delete buff;
			buff = NULL;
		}
		buff = value;
		if( buff != NULL ) {
			copyBuffToPKey();
		}
	}

	const std::string& CFSecTSecGrpMembObj::getClassName() const {
		return( CLASS_NAME );
	}

	const classcode_t CFSecTSecGrpMembObj::getClassCode() const {
		return( CLASS_CODE );
	}

	bool CFSecTSecGrpMembObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfsec::CFSecTSecGrpMembBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFSecTSecGrpMembObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecTSecGrpMembObj" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_TenantId( "TenantId" );
		static const std::string S_TSecGrpMembId( "TSecGrpMembId" );
		static const std::string S_TSecGroupId( "TSecGroupId" );
		static const std::string S_SecUserId( "SecUserId" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFSecTSecGrpMembObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFSecTSecGrpMembObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFSecTSecGrpMembObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFSecTSecGrpMembObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFSecTSecGrpMembObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_TenantId, CFSecTSecGrpMembObj::getRequiredTenantId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_TSecGrpMembId, CFSecTSecGrpMembObj::getRequiredTSecGrpMembId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_TSecGroupId, CFSecTSecGrpMembObj::getRequiredTSecGroupId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_SecUserId, CFSecTSecGrpMembObj::getRequiredSecUserId() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	std::string CFSecTSecGrpMembObj::getObjName() {
		std::string objName( CLASS_NAME );
		int64_t val = getRequiredTSecGrpMembId();
		objName = cflib::CFLibXmlUtil::formatInt64( val );
		return( objName );
	}

	const std::string CFSecTSecGrpMembObj::getGenDefName() {
		return( cfsec::CFSecTSecGrpMembBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFSecTSecGrpMembObj::getScope() {
		cfsec::ICFSecTSecGroupObj* scope = getRequiredContainerGroup();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFSecTSecGrpMembObj::getObjScope() {
		cfsec::ICFSecTSecGroupObj* scope = getRequiredContainerGroup();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFSecTSecGrpMembObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFSecTSecGrpMembObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFSecTSecGrpMembObj::getNamedObject( const std::string& objName ) {
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

	std::string CFSecTSecGrpMembObj::getObjQualifiedName() {
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

	std::string CFSecTSecGrpMembObj::getObjFullName() {
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

	cfsec::ICFSecTSecGrpMembObj* CFSecTSecGrpMembObj::realize() {
		cfsec::ICFSecTSecGrpMembObj* retobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getTSecGrpMembTableObj()->realizeTSecGrpMemb(
			(cfsec::ICFSecTSecGrpMembObj*)this );
		return( dynamic_cast<cfsec::ICFSecTSecGrpMembObj*>( retobj ) );
	}

	cfsec::ICFSecTSecGrpMembObj* CFSecTSecGrpMembObj::read( bool forceRead ) {
		cfsec::ICFSecTSecGrpMembObj* retobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getTSecGrpMembTableObj()->readTSecGrpMembByIdIdx( getTSecGrpMembBuff()->getRequiredTenantId(),
		getTSecGrpMembBuff()->getRequiredTSecGrpMembId(), forceRead );
		return( dynamic_cast<cfsec::ICFSecTSecGrpMembObj*>( retobj ) );
	}

	cfsec::ICFSecTSecGrpMembTableObj* CFSecTSecGrpMembObj::getTSecGrpMembTable() {
		return( dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getTSecGrpMembTableObj() );
	}

	cfsec::ICFSecSchemaObj* CFSecTSecGrpMembObj::getSchema() {
		return( schema );
	}

	void CFSecTSecGrpMembObj::setSchema( cfsec::ICFSecSchemaObj* value ) {
		schema = value;
	}

	cfsec::CFSecTSecGrpMembPKey* CFSecTSecGrpMembObj::getPKey() {
		if( pKey == NULL ) {
			pKey = new cfsec::CFSecTSecGrpMembPKey();
		}
		return( pKey );
	}

	void CFSecTSecGrpMembObj::setPKey( cfsec::CFSecTSecGrpMembPKey* value ) {
		if( ( pKey != NULL ) && ( pKey != value ) ) {
			delete pKey;
			pKey = NULL;
		}
		if( value != NULL ) {
			pKey = new cfsec::CFSecTSecGrpMembPKey();
			*pKey = *value;
			copyPKeyToBuff();
		}
	}

	bool CFSecTSecGrpMembObj::getIsNew() {
		return( isNew );
	}

	void CFSecTSecGrpMembObj::setIsNew( bool value ) {
		isNew = value;
	}

	cfsec::ICFSecTSecGrpMembEditObj* CFSecTSecGrpMembObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_EditAlreadyOpen( "An edit is already open" );
		if( edit != NULL ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_ProcName, S_EditAlreadyOpen );
		}
		if( ! getIsNew() ) {
			cfsec::ICFSecTSecGrpMembObj* lockobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getTSecGrpMembTableObj()->lockTSecGrpMemb( getPKey() );
			lockobj->realize();
		}
		edit = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getTSecGrpMembTableObj()->newEditInstance( this );
		return( dynamic_cast<cfsec::ICFSecTSecGrpMembEditObj*>( edit ) );
	}

	void CFSecTSecGrpMembObj::endEdit() {
		if( edit != NULL ) {
			delete edit;
			edit = NULL;
		}
	}

	cfsec::ICFSecTSecGrpMembEditObj* CFSecTSecGrpMembObj::getEdit() {
		return( edit );
	}

	cfsec::ICFSecTSecGrpMembEditObj* CFSecTSecGrpMembObj::getTSecGrpMembEdit() {
		return( dynamic_cast<cfsec::ICFSecTSecGrpMembEditObj*>( edit ) );
	}

	cfsec::ICFSecSecUserObj* CFSecTSecGrpMembObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getTSecGrpMembBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFSecTSecGrpMembObj::getCreatedAt() {
		return( getTSecGrpMembBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFSecTSecGrpMembObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getTSecGrpMembBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFSecTSecGrpMembObj::getUpdatedAt() {
		return( getTSecGrpMembBuff()->getUpdatedAt() );
	}

	void CFSecTSecGrpMembObj::copyPKeyToBuff() {
		cfsec::CFSecTSecGrpMembPKey* tablePKey = getPKey();
		cfsec::CFSecTSecGrpMembBuff* tableBuff = getTSecGrpMembEditBuff();
		if( tableBuff != NULL ) {
			tableBuff->setRequiredTenantId( tablePKey->getRequiredTenantId() );
			tableBuff->setRequiredTSecGrpMembId( tablePKey->getRequiredTSecGrpMembId() );
		}
		if( edit != NULL ) {
			edit->copyPKeyToBuff();
		}
	}

	void CFSecTSecGrpMembObj::copyBuffToPKey() {
		cfsec::CFSecTSecGrpMembPKey* tablePKey = getPKey();
		cfsec::CFSecTSecGrpMembBuff* tableBuff = getTSecGrpMembBuff();
		tablePKey->setRequiredTenantId( tableBuff->getRequiredTenantId() );
		tablePKey->setRequiredTSecGrpMembId( tableBuff->getRequiredTSecGrpMembId() );
	}

}
