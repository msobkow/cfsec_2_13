// Description: C++18 base object instance implementation for CFSec SecGroupForm.

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
#include <cfsecobj/CFSecSecGroupFormObj.hpp>

namespace cfsec {

	const std::string CFSecSecGroupFormObj::CLASS_NAME( "CFSecSecGroupFormObj" );
	const classcode_t CFSecSecGroupFormObj::CLASS_CODE = 0xa00dL;

	int32_t CFSecSecGroupFormObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	const int64_t CFSecSecGroupFormObj::getRequiredClusterId() {
		return( getPKey()->getRequiredClusterId() );
	}

	const int64_t* CFSecSecGroupFormObj::getRequiredClusterIdReference() {
		return( getPKey()->getRequiredClusterIdReference() );
	}

	const int64_t CFSecSecGroupFormObj::getRequiredSecGroupFormId() {
		return( getPKey()->getRequiredSecGroupFormId() );
	}

	const int64_t* CFSecSecGroupFormObj::getRequiredSecGroupFormIdReference() {
		return( getPKey()->getRequiredSecGroupFormIdReference() );
	}

	const int32_t CFSecSecGroupFormObj::getRequiredSecGroupId() {
		return( getSecGroupFormBuff()->getRequiredSecGroupId() );
	}

	const int32_t* CFSecSecGroupFormObj::getRequiredSecGroupIdReference() {
		return( getSecGroupFormBuff()->getRequiredSecGroupIdReference() );
	}

	const int32_t CFSecSecGroupFormObj::getRequiredSecAppId() {
		return( getSecGroupFormBuff()->getRequiredSecAppId() );
	}

	const int32_t* CFSecSecGroupFormObj::getRequiredSecAppIdReference() {
		return( getSecGroupFormBuff()->getRequiredSecAppIdReference() );
	}

	const int32_t CFSecSecGroupFormObj::getRequiredSecFormId() {
		return( getSecGroupFormBuff()->getRequiredSecFormId() );
	}

	const int32_t* CFSecSecGroupFormObj::getRequiredSecFormIdReference() {
		return( getSecGroupFormBuff()->getRequiredSecFormIdReference() );
	}


	cfsec::ICFSecClusterObj* CFSecSecGroupFormObj::getRequiredOwnerCluster( bool forceRead ) {
		cfsec::ICFSecClusterObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getClusterTableObj()->readClusterByIdIdx( getPKey()->getRequiredClusterId(), forceRead );
		}
		return( retobj );
	}

	cfsec::ICFSecSecGroupObj* CFSecSecGroupFormObj::getRequiredContainerGroup( bool forceRead ) {
		cfsec::ICFSecSecGroupObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecGroupTableObj()->readSecGroupByIdIdx( getPKey()->getRequiredClusterId(),
					getSecGroupFormBuff()->getRequiredSecGroupId(), forceRead );
		}
		return( retobj );
	}

	cfsec::ICFSecSecAppObj* CFSecSecGroupFormObj::getRequiredParentApp( bool forceRead ) {
		cfsec::ICFSecSecAppObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecAppTableObj()->readSecAppByIdIdx( getPKey()->getRequiredClusterId(),
					getSecGroupFormBuff()->getRequiredSecAppId(), forceRead );
		}
		return( retobj );
	}

	cfsec::ICFSecSecFormObj* CFSecSecGroupFormObj::getRequiredParentForm( bool forceRead ) {
		cfsec::ICFSecSecFormObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecFormTableObj()->readSecFormByIdIdx( getPKey()->getRequiredClusterId(),
					getSecGroupFormBuff()->getRequiredSecFormId(), forceRead );
		}
		return( retobj );
	}

	CFSecSecGroupFormObj::CFSecSecGroupFormObj()
	: ICFSecSecGroupFormObj()
	{
		schema = NULL;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFSecSecGroupFormObj::CFSecSecGroupFormObj( cfsec::ICFSecSchemaObj* argSchema )
	: ICFSecSecGroupFormObj()
	{
		schema = argSchema;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFSecSecGroupFormObj::~CFSecSecGroupFormObj() {
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

	cfsec::CFSecSecGroupFormBuff* CFSecSecGroupFormObj::getBuff() {
		if( buff == NULL ) {
			if( isNew ) {
				buff = new cfsec::CFSecSecGroupFormBuff();
				copyBuffToPKey();
			}
			else {
				// Read the data buff via the backing store
				buff = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecGroupForm()->readDerivedByIdIdx( dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getAuthorization(),
						getPKey()->getRequiredClusterId(),
						getPKey()->getRequiredSecGroupFormId() );
			}
		}
		return( buff );
	}

	void CFSecSecGroupFormObj::setBuff( cfsec::CFSecSecGroupFormBuff* value ) {
		if( ( buff != NULL ) && ( buff != value ) ) {
			delete buff;
			buff = NULL;
		}
		buff = value;
		if( buff != NULL ) {
			copyBuffToPKey();
		}
	}

	const std::string& CFSecSecGroupFormObj::getClassName() const {
		return( CLASS_NAME );
	}

	const classcode_t CFSecSecGroupFormObj::getClassCode() const {
		return( CLASS_CODE );
	}

	bool CFSecSecGroupFormObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfsec::CFSecSecGroupFormBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFSecSecGroupFormObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecSecGroupFormObj" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_ClusterId( "ClusterId" );
		static const std::string S_SecGroupFormId( "SecGroupFormId" );
		static const std::string S_SecGroupId( "SecGroupId" );
		static const std::string S_SecAppId( "SecAppId" );
		static const std::string S_SecFormId( "SecFormId" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFSecSecGroupFormObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFSecSecGroupFormObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFSecSecGroupFormObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFSecSecGroupFormObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFSecSecGroupFormObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_ClusterId, CFSecSecGroupFormObj::getRequiredClusterId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_SecGroupFormId, CFSecSecGroupFormObj::getRequiredSecGroupFormId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_SecGroupId, CFSecSecGroupFormObj::getRequiredSecGroupId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_SecAppId, CFSecSecGroupFormObj::getRequiredSecAppId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_SecFormId, CFSecSecGroupFormObj::getRequiredSecFormId() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	std::string CFSecSecGroupFormObj::getObjName() {
		std::string objName( CLASS_NAME );
		int64_t val = getRequiredSecGroupFormId();
		objName = cflib::CFLibXmlUtil::formatInt64( val );
		return( objName );
	}

	const std::string CFSecSecGroupFormObj::getGenDefName() {
		return( cfsec::CFSecSecGroupFormBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFSecSecGroupFormObj::getScope() {
		cfsec::ICFSecSecGroupObj* scope = getRequiredContainerGroup();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFSecSecGroupFormObj::getObjScope() {
		cfsec::ICFSecSecGroupObj* scope = getRequiredContainerGroup();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFSecSecGroupFormObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFSecSecGroupFormObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFSecSecGroupFormObj::getNamedObject( const std::string& objName ) {
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

	std::string CFSecSecGroupFormObj::getObjQualifiedName() {
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

	std::string CFSecSecGroupFormObj::getObjFullName() {
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

	cfsec::ICFSecSecGroupFormObj* CFSecSecGroupFormObj::realize() {
		cfsec::ICFSecSecGroupFormObj* retobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecGroupFormTableObj()->realizeSecGroupForm(
			(cfsec::ICFSecSecGroupFormObj*)this );
		return( dynamic_cast<cfsec::ICFSecSecGroupFormObj*>( retobj ) );
	}

	cfsec::ICFSecSecGroupFormObj* CFSecSecGroupFormObj::read( bool forceRead ) {
		cfsec::ICFSecSecGroupFormObj* retobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecGroupFormTableObj()->readSecGroupFormByIdIdx( getSecGroupFormBuff()->getRequiredClusterId(),
		getSecGroupFormBuff()->getRequiredSecGroupFormId(), forceRead );
		return( dynamic_cast<cfsec::ICFSecSecGroupFormObj*>( retobj ) );
	}

	cfsec::ICFSecSecGroupFormTableObj* CFSecSecGroupFormObj::getSecGroupFormTable() {
		return( dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecGroupFormTableObj() );
	}

	cfsec::ICFSecSchemaObj* CFSecSecGroupFormObj::getSchema() {
		return( schema );
	}

	void CFSecSecGroupFormObj::setSchema( cfsec::ICFSecSchemaObj* value ) {
		schema = value;
	}

	cfsec::CFSecSecGroupFormPKey* CFSecSecGroupFormObj::getPKey() {
		if( pKey == NULL ) {
			pKey = new cfsec::CFSecSecGroupFormPKey();
		}
		return( pKey );
	}

	void CFSecSecGroupFormObj::setPKey( cfsec::CFSecSecGroupFormPKey* value ) {
		if( ( pKey != NULL ) && ( pKey != value ) ) {
			delete pKey;
			pKey = NULL;
		}
		if( value != NULL ) {
			pKey = new cfsec::CFSecSecGroupFormPKey();
			*pKey = *value;
			copyPKeyToBuff();
		}
	}

	bool CFSecSecGroupFormObj::getIsNew() {
		return( isNew );
	}

	void CFSecSecGroupFormObj::setIsNew( bool value ) {
		isNew = value;
	}

	cfsec::ICFSecSecGroupFormEditObj* CFSecSecGroupFormObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_EditAlreadyOpen( "An edit is already open" );
		if( edit != NULL ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_ProcName, S_EditAlreadyOpen );
		}
		if( ! getIsNew() ) {
			cfsec::ICFSecSecGroupFormObj* lockobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecGroupFormTableObj()->lockSecGroupForm( getPKey() );
			lockobj->realize();
		}
		edit = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecGroupFormTableObj()->newEditInstance( this );
		return( dynamic_cast<cfsec::ICFSecSecGroupFormEditObj*>( edit ) );
	}

	void CFSecSecGroupFormObj::endEdit() {
		if( edit != NULL ) {
			delete edit;
			edit = NULL;
		}
	}

	cfsec::ICFSecSecGroupFormEditObj* CFSecSecGroupFormObj::getEdit() {
		return( edit );
	}

	cfsec::ICFSecSecGroupFormEditObj* CFSecSecGroupFormObj::getSecGroupFormEdit() {
		return( dynamic_cast<cfsec::ICFSecSecGroupFormEditObj*>( edit ) );
	}

	cfsec::ICFSecSecUserObj* CFSecSecGroupFormObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getSecGroupFormBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFSecSecGroupFormObj::getCreatedAt() {
		return( getSecGroupFormBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFSecSecGroupFormObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getSecGroupFormBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFSecSecGroupFormObj::getUpdatedAt() {
		return( getSecGroupFormBuff()->getUpdatedAt() );
	}

	void CFSecSecGroupFormObj::copyPKeyToBuff() {
		cfsec::CFSecSecGroupFormPKey* tablePKey = getPKey();
		cfsec::CFSecSecGroupFormBuff* tableBuff = getSecGroupFormEditBuff();
		if( tableBuff != NULL ) {
			tableBuff->setRequiredClusterId( tablePKey->getRequiredClusterId() );
			tableBuff->setRequiredSecGroupFormId( tablePKey->getRequiredSecGroupFormId() );
		}
		if( edit != NULL ) {
			edit->copyPKeyToBuff();
		}
	}

	void CFSecSecGroupFormObj::copyBuffToPKey() {
		cfsec::CFSecSecGroupFormPKey* tablePKey = getPKey();
		cfsec::CFSecSecGroupFormBuff* tableBuff = getSecGroupFormBuff();
		tablePKey->setRequiredClusterId( tableBuff->getRequiredClusterId() );
		tablePKey->setRequiredSecGroupFormId( tableBuff->getRequiredSecGroupFormId() );
	}

}
