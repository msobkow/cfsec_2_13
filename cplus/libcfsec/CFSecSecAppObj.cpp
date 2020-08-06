// Description: C++18 base object instance implementation for CFSec SecApp.

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
#include <cfsecobj/CFSecSecAppObj.hpp>

namespace cfsec {

	const std::string CFSecSecAppObj::CLASS_NAME( "CFSecSecAppObj" );
	const classcode_t CFSecSecAppObj::CLASS_CODE = 0xa009L;

	int32_t CFSecSecAppObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	const int64_t CFSecSecAppObj::getRequiredClusterId() {
		return( getPKey()->getRequiredClusterId() );
	}

	const int64_t* CFSecSecAppObj::getRequiredClusterIdReference() {
		return( getPKey()->getRequiredClusterIdReference() );
	}

	const int32_t CFSecSecAppObj::getRequiredSecAppId() {
		return( getPKey()->getRequiredSecAppId() );
	}

	const int32_t* CFSecSecAppObj::getRequiredSecAppIdReference() {
		return( getPKey()->getRequiredSecAppIdReference() );
	}

	const std::string& CFSecSecAppObj::getRequiredJEEMountName() {
		return( getSecAppBuff()->getRequiredJEEMountName() );
	}

	const std::string* CFSecSecAppObj::getRequiredJEEMountNameReference() {
		return( getSecAppBuff()->getRequiredJEEMountNameReference() );
	}


	cfsec::ICFSecClusterObj* CFSecSecAppObj::getRequiredContainerCluster( bool forceRead ) {
		cfsec::ICFSecClusterObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getClusterTableObj()->readClusterByIdIdx( getPKey()->getRequiredClusterId(), forceRead );
		}
		return( retobj );
	}

	std::vector<cfsec::ICFSecSecFormObj*> CFSecSecAppObj::getOptionalComponentsForm( bool forceRead ) {
		std::vector<cfsec::ICFSecSecFormObj*> retval;
		retval = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecFormTableObj()->readSecFormBySecAppIdx( getPKey()->getRequiredClusterId(),
					getPKey()->getRequiredSecAppId(),
			forceRead );
		return( retval );
	}

	CFSecSecAppObj::CFSecSecAppObj()
	: ICFSecSecAppObj()
	{
		schema = NULL;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFSecSecAppObj::CFSecSecAppObj( cfsec::ICFSecSchemaObj* argSchema )
	: ICFSecSecAppObj()
	{
		schema = argSchema;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFSecSecAppObj::~CFSecSecAppObj() {
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

	cfsec::CFSecSecAppBuff* CFSecSecAppObj::getBuff() {
		if( buff == NULL ) {
			if( isNew ) {
				buff = new cfsec::CFSecSecAppBuff();
				copyBuffToPKey();
			}
			else {
				// Read the data buff via the backing store
				buff = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecApp()->readDerivedByIdIdx( dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getAuthorization(),
						getPKey()->getRequiredClusterId(),
						getPKey()->getRequiredSecAppId() );
			}
		}
		return( buff );
	}

	void CFSecSecAppObj::setBuff( cfsec::CFSecSecAppBuff* value ) {
		if( ( buff != NULL ) && ( buff != value ) ) {
			delete buff;
			buff = NULL;
		}
		buff = value;
		if( buff != NULL ) {
			copyBuffToPKey();
		}
	}

	const std::string& CFSecSecAppObj::getClassName() const {
		return( CLASS_NAME );
	}

	const classcode_t CFSecSecAppObj::getClassCode() const {
		return( CLASS_CODE );
	}

	bool CFSecSecAppObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfsec::CFSecSecAppBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFSecSecAppObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecSecAppObj" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_ClusterId( "ClusterId" );
		static const std::string S_SecAppId( "SecAppId" );
		static const std::string S_JEEMountName( "JEEMountName" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFSecSecAppObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFSecSecAppObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFSecSecAppObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFSecSecAppObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFSecSecAppObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_ClusterId, CFSecSecAppObj::getRequiredClusterId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_SecAppId, CFSecSecAppObj::getRequiredSecAppId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_JEEMountName, CFSecSecAppObj::getRequiredJEEMountName() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	std::string CFSecSecAppObj::getObjName() {
		std::string objName( CLASS_NAME );
		objName.clear();
		objName.append( getRequiredJEEMountName() );
		return( objName );
	}

	const std::string CFSecSecAppObj::getGenDefName() {
		return( cfsec::CFSecSecAppBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFSecSecAppObj::getScope() {
		cfsec::ICFSecClusterObj* scope = getRequiredContainerCluster();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFSecSecAppObj::getObjScope() {
		cfsec::ICFSecClusterObj* scope = getRequiredContainerCluster();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFSecSecAppObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFSecSecAppObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFSecSecAppObj::getNamedObject( const std::string& objName ) {
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
			subObj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecFormTableObj()->readSecFormByLookupUJEEServletIdx( getRequiredClusterId(),
			getRequiredSecAppId(),
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

	std::string CFSecSecAppObj::getObjQualifiedName() {
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

	std::string CFSecSecAppObj::getObjFullName() {
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

	cfsec::ICFSecSecAppObj* CFSecSecAppObj::realize() {
		cfsec::ICFSecSecAppObj* retobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecAppTableObj()->realizeSecApp(
			(cfsec::ICFSecSecAppObj*)this );
		return( dynamic_cast<cfsec::ICFSecSecAppObj*>( retobj ) );
	}

	cfsec::ICFSecSecAppObj* CFSecSecAppObj::read( bool forceRead ) {
		cfsec::ICFSecSecAppObj* retobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecAppTableObj()->readSecAppByIdIdx( getSecAppBuff()->getRequiredClusterId(),
		getSecAppBuff()->getRequiredSecAppId(), forceRead );
		return( dynamic_cast<cfsec::ICFSecSecAppObj*>( retobj ) );
	}

	cfsec::ICFSecSecAppTableObj* CFSecSecAppObj::getSecAppTable() {
		return( dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecAppTableObj() );
	}

	cfsec::ICFSecSchemaObj* CFSecSecAppObj::getSchema() {
		return( schema );
	}

	void CFSecSecAppObj::setSchema( cfsec::ICFSecSchemaObj* value ) {
		schema = value;
	}

	cfsec::CFSecSecAppPKey* CFSecSecAppObj::getPKey() {
		if( pKey == NULL ) {
			pKey = new cfsec::CFSecSecAppPKey();
		}
		return( pKey );
	}

	void CFSecSecAppObj::setPKey( cfsec::CFSecSecAppPKey* value ) {
		if( ( pKey != NULL ) && ( pKey != value ) ) {
			delete pKey;
			pKey = NULL;
		}
		if( value != NULL ) {
			pKey = new cfsec::CFSecSecAppPKey();
			*pKey = *value;
			copyPKeyToBuff();
		}
	}

	bool CFSecSecAppObj::getIsNew() {
		return( isNew );
	}

	void CFSecSecAppObj::setIsNew( bool value ) {
		isNew = value;
	}

	cfsec::ICFSecSecAppEditObj* CFSecSecAppObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_EditAlreadyOpen( "An edit is already open" );
		if( edit != NULL ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_ProcName, S_EditAlreadyOpen );
		}
		if( ! getIsNew() ) {
			cfsec::ICFSecSecAppObj* lockobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecAppTableObj()->lockSecApp( getPKey() );
			lockobj->realize();
		}
		edit = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecAppTableObj()->newEditInstance( this );
		return( dynamic_cast<cfsec::ICFSecSecAppEditObj*>( edit ) );
	}

	void CFSecSecAppObj::endEdit() {
		if( edit != NULL ) {
			delete edit;
			edit = NULL;
		}
	}

	cfsec::ICFSecSecAppEditObj* CFSecSecAppObj::getEdit() {
		return( edit );
	}

	cfsec::ICFSecSecAppEditObj* CFSecSecAppObj::getSecAppEdit() {
		return( dynamic_cast<cfsec::ICFSecSecAppEditObj*>( edit ) );
	}

	cfsec::ICFSecSecUserObj* CFSecSecAppObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getSecAppBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFSecSecAppObj::getCreatedAt() {
		return( getSecAppBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFSecSecAppObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getSecAppBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFSecSecAppObj::getUpdatedAt() {
		return( getSecAppBuff()->getUpdatedAt() );
	}

	void CFSecSecAppObj::copyPKeyToBuff() {
		cfsec::CFSecSecAppPKey* tablePKey = getPKey();
		cfsec::CFSecSecAppBuff* tableBuff = getSecAppEditBuff();
		if( tableBuff != NULL ) {
			tableBuff->setRequiredClusterId( tablePKey->getRequiredClusterId() );
			tableBuff->setRequiredSecAppId( tablePKey->getRequiredSecAppId() );
		}
		if( edit != NULL ) {
			edit->copyPKeyToBuff();
		}
	}

	void CFSecSecAppObj::copyBuffToPKey() {
		cfsec::CFSecSecAppPKey* tablePKey = getPKey();
		cfsec::CFSecSecAppBuff* tableBuff = getSecAppBuff();
		tablePKey->setRequiredClusterId( tableBuff->getRequiredClusterId() );
		tablePKey->setRequiredSecAppId( tableBuff->getRequiredSecAppId() );
	}

}
