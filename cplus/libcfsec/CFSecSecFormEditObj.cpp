// Description: C++18 edit object instance implementation for CFSec SecForm.

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
#include <cfsecobj/CFSecSecFormObj.hpp>
#include <cfsecobj/CFSecSecFormEditObj.hpp>


namespace cfsec {

	const std::string CFSecSecFormEditObj::CLASS_NAME( "CFSecSecFormEditObj" );

	CFSecSecFormEditObj::CFSecSecFormEditObj( cfsec::ICFSecSecFormObj* argOrig )
	: ICFSecSecFormEditObj()
	{
		static const std::string S_ProcName( "CFSecSecFormEditObj-construct" );
		static const std::string S_OrigBuff( "origBuff" );
		orig = argOrig;
		cfsec::CFSecSecFormBuff* origBuff = orig->getBuff();
		if( origBuff == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_OrigBuff );
		}
		buff = dynamic_cast<cfsec::CFSecSecFormBuff*>( origBuff->clone() );
	}

	CFSecSecFormEditObj::~CFSecSecFormEditObj() {
		orig = NULL;
		if( buff != NULL ) {
			delete buff;
			buff = NULL;
		}

	}

	const std::string& CFSecSecFormEditObj::getClassName() const {
		return( CLASS_NAME );
	}

	cfsec::ICFSecSecUserObj* CFSecSecFormEditObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<cfsec::ICFSecSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getSecFormBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFSecSecFormEditObj::getCreatedAt() {
		return( getSecFormBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFSecSecFormEditObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<cfsec::ICFSecSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getSecFormBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFSecSecFormEditObj::getUpdatedAt() {
		return( getSecFormBuff()->getUpdatedAt() );
	}

	void CFSecSecFormEditObj::setCreatedBy( cfsec::ICFSecSecUserObj* value ) {
		createdBy = value;
		if( value != NULL ) {
			getSecFormEditBuff()->setCreatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFSecSecFormEditObj::setCreatedAt( const std::chrono::system_clock::time_point& value ) {
		getSecFormEditBuff()->setCreatedAt( value );
	}

	void CFSecSecFormEditObj::setUpdatedBy( cfsec::ICFSecSecUserObj* value ) {
		updatedBy = value;
		if( value != NULL ) {
			getSecFormEditBuff()->setUpdatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFSecSecFormEditObj::setUpdatedAt( const std::chrono::system_clock::time_point& value ) {
		getSecFormEditBuff()->setUpdatedAt( value );
	}

	const classcode_t CFSecSecFormEditObj::getClassCode() const {
		return( cfsec::CFSecSecFormBuff::CLASS_CODE );
	}

	bool CFSecSecFormEditObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfsec::CFSecSecFormBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFSecSecFormEditObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecSecFormEditObj" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_ClusterId( "ClusterId" );
		static const std::string S_SecFormId( "SecFormId" );
		static const std::string S_SecAppId( "SecAppId" );
		static const std::string S_JEEServletMapName( "JEEServletMapName" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFSecSecFormEditObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFSecSecFormEditObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFSecSecFormEditObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFSecSecFormEditObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFSecSecFormEditObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_ClusterId, CFSecSecFormEditObj::getRequiredClusterId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_SecFormId, CFSecSecFormEditObj::getRequiredSecFormId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_SecAppId, CFSecSecFormEditObj::getRequiredSecAppId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_JEEServletMapName, CFSecSecFormEditObj::getRequiredJEEServletMapName() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	int32_t CFSecSecFormEditObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	void CFSecSecFormEditObj::setRequiredRevision( int32_t value ) {
		getSecFormEditBuff()->setRequiredRevision( value );
	}

	std::string CFSecSecFormEditObj::getObjName() {
		std::string objName( CLASS_NAME ); objName;
		objName.clear();
		objName.append( getRequiredJEEServletMapName() );
		return( objName );
	}

	const std::string CFSecSecFormEditObj::getGenDefName() {
		return( cfsec::CFSecSecFormBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFSecSecFormEditObj::getScope() {
		cfsec::ICFSecSecAppObj* scope = getRequiredContainerApplication();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFSecSecFormEditObj::getObjScope() {
		cfsec::ICFSecSecAppObj* scope = getRequiredContainerApplication();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFSecSecFormEditObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFSecSecFormEditObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFSecSecFormEditObj::getNamedObject( const std::string& objName ) {
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

	std::string CFSecSecFormEditObj::getObjQualifiedName() {
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

	std::string CFSecSecFormEditObj::getObjFullName() {
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

	cfsec::ICFSecSecFormObj* CFSecSecFormEditObj::realize() {
		// We realize this so that it's buffer will get copied to orig during realization
		cfsec::ICFSecSecFormObj* retobj = getSchema()->getSecFormTableObj()->realizeSecForm( dynamic_cast<cfsec::ICFSecSecFormObj*>( this ) );
		return( retobj );
	}

	cfsec::ICFSecSecFormObj* CFSecSecFormEditObj::read( bool forceRead ) {
		cfsec::ICFSecSecFormObj* retval = getOrigAsSecForm()->read( forceRead );
		if( retval != orig ) {
			throw cflib::CFLibUsageException( CLASS_NAME,
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	cfsec::ICFSecSecFormObj* CFSecSecFormEditObj::create() {
		cfsec::ICFSecSecFormObj* retobj = dynamic_cast<cfsec::ICFSecSchemaObj*>( getOrigAsSecForm()->getSchema() )->getSecFormTableObj()->createSecForm( this );
		// Note that this instance is usually discarded during the creation process,
		// and retobj now references the cached instance of the created object.
		return( retobj );
	}

	cfsec::ICFSecSecFormEditObj* CFSecSecFormEditObj::update() {
		getSchema()->getSecFormTableObj()->updateSecForm( this );
		return( NULL );
	}

	cfsec::ICFSecSecFormEditObj* CFSecSecFormEditObj::deleteInstance() {
		static const std::string S_MethodName( "deleteInstance" );
		static const std::string S_CannotDeleteNewInstance( "Cannot delete a new instance" );
		if( getIsNew() ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_MethodName, S_CannotDeleteNewInstance );
		}
		getSchema()->getSecFormTableObj()->deleteSecForm( this );
		return( NULL );
	}

	cfsec::ICFSecSecFormTableObj* CFSecSecFormEditObj::getSecFormTable() {
		return( orig->getSchema()->getSecFormTableObj() );
	}

	cfsec::ICFSecSecFormEditObj* CFSecSecFormEditObj::getEdit() {
		return( this );
	}

	cfsec::ICFSecSecFormEditObj* CFSecSecFormEditObj::getSecFormEdit() {
		return( (cfsec::ICFSecSecFormEditObj*)this );
	}

	cfsec::ICFSecSecFormEditObj* CFSecSecFormEditObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_Message( "Cannot edit an edition" );
		throw cflib::CFLibUsageException( CLASS_NAME,
			S_ProcName,
			S_Message );
	}

	void CFSecSecFormEditObj::endEdit() {
		orig->endEdit();
	}

	cfsec::ICFSecSecFormObj* CFSecSecFormEditObj::getOrig() {
		return( orig );
	}

	cfsec::ICFSecSecFormObj* CFSecSecFormEditObj::getOrigAsSecForm() {
		return( dynamic_cast<cfsec::ICFSecSecFormObj*>( orig ) );
	}

	cfsec::ICFSecSchemaObj* CFSecSecFormEditObj::getSchema() {
		return( orig->getSchema() );
	}

	cfsec::CFSecSecFormBuff* CFSecSecFormEditObj::getBuff() {
		return( buff );
	}

	void CFSecSecFormEditObj::setBuff( cfsec::CFSecSecFormBuff* value ) {
		if( buff != value ) {
			if( ( buff != NULL ) && ( buff != value ) ) {
				delete buff;
				buff = NULL;
			}
			buff = value;
		}
	}

	cfsec::CFSecSecFormPKey* CFSecSecFormEditObj::getPKey() {
		return( orig->getPKey() );
	}

	void CFSecSecFormEditObj::setPKey( cfsec::CFSecSecFormPKey* value ) {
		if( orig->getPKey() != value ) {
			orig->setPKey( value );
		}
		copyPKeyToBuff();
	}

	bool CFSecSecFormEditObj::getIsNew() {
		return( orig->getIsNew() );
	}

	void CFSecSecFormEditObj::setIsNew( bool value ) {
		orig->setIsNew( value );
	}

	const int64_t CFSecSecFormEditObj::getRequiredClusterId() {
		return( getPKey()->getRequiredClusterId() );
	}

	const int64_t* CFSecSecFormEditObj::getRequiredClusterIdReference() {
		return( getPKey()->getRequiredClusterIdReference() );
	}

	const int32_t CFSecSecFormEditObj::getRequiredSecFormId() {
		return( getPKey()->getRequiredSecFormId() );
	}

	const int32_t* CFSecSecFormEditObj::getRequiredSecFormIdReference() {
		return( getPKey()->getRequiredSecFormIdReference() );
	}

	const int32_t CFSecSecFormEditObj::getRequiredSecAppId() {
		return( getSecFormBuff()->getRequiredSecAppId() );
	}

	const int32_t* CFSecSecFormEditObj::getRequiredSecAppIdReference() {
		return( getSecFormBuff()->getRequiredSecAppIdReference() );
	}

	const std::string& CFSecSecFormEditObj::getRequiredJEEServletMapName() {
		return( getSecFormBuff()->getRequiredJEEServletMapName() );
	}

	const std::string* CFSecSecFormEditObj::getRequiredJEEServletMapNameReference() {
		return( getSecFormBuff()->getRequiredJEEServletMapNameReference() );
	}

	void CFSecSecFormEditObj::setRequiredJEEServletMapName( const std::string& value ) {
		if( getSecFormBuff()->getRequiredJEEServletMapName() != value ) {
			getSecFormEditBuff()->setRequiredJEEServletMapName( value );
		}
	}

	cfsec::ICFSecClusterObj* CFSecSecFormEditObj::getRequiredOwnerCluster( bool forceRead ) {
		cfsec::ICFSecClusterObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<cfsec::ICFSecSchemaObj*>( getOrigAsSecForm()->getSchema() )->getClusterTableObj()->readClusterByIdIdx( getPKey()->getRequiredClusterId() );
		}
		return( retobj );
	}

	void CFSecSecFormEditObj::setRequiredOwnerCluster( cfsec::ICFSecClusterObj* value ) {
			
			if( value != NULL ) {
				getPKey()->setRequiredClusterId
( value->getRequiredId() );
				getSecFormEditBuff()->setRequiredClusterId( value->getRequiredId() );
			}
		}

	cfsec::ICFSecSecAppObj* CFSecSecFormEditObj::getRequiredContainerApplication( bool forceRead ) {
		cfsec::ICFSecSecAppObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<cfsec::ICFSecSchemaObj*>( getOrigAsSecForm()->getSchema() )->getSecAppTableObj()->readSecAppByIdIdx( getPKey()->getRequiredClusterId(),
					getSecFormBuff()->getRequiredSecAppId() );
		}
		return( retobj );
	}

	void CFSecSecFormEditObj::setRequiredContainerApplication( cfsec::ICFSecSecAppObj* value ) {
			
			if( value != NULL ) {
				getPKey()->setRequiredClusterId
( value->getRequiredClusterId() );
				getSecFormEditBuff()->setRequiredClusterId( value->getRequiredClusterId() );
				getSecFormEditBuff()->setRequiredSecAppId( value->getRequiredSecAppId() );
			}
		}

	void CFSecSecFormEditObj::copyPKeyToBuff() {
		cfsec::CFSecSecFormPKey* tablePKey = getPKey();
		cfsec::CFSecSecFormBuff* tableBuff = getSecFormEditBuff();
		tableBuff->setRequiredClusterId( tablePKey->getRequiredClusterId() );
		tableBuff->setRequiredSecFormId( tablePKey->getRequiredSecFormId() );
	}

	void CFSecSecFormEditObj::copyBuffToPKey() {
		cfsec::CFSecSecFormPKey* tablePKey = getPKey();
		cfsec::CFSecSecFormBuff* tableBuff = getSecFormBuff();
		tablePKey->setRequiredClusterId( tableBuff->getRequiredClusterId() );
		tablePKey->setRequiredSecFormId( tableBuff->getRequiredSecFormId() );
	}

	void CFSecSecFormEditObj::copyBuffToOrig() {
		cfsec::CFSecSecFormBuff* origBuff = getOrigAsSecForm()->getSecFormEditBuff();
		cfsec::CFSecSecFormBuff* myBuff = getSecFormBuff();
		if( origBuff != myBuff ) {
			*origBuff = *myBuff;
		}
	}

	void CFSecSecFormEditObj::copyOrigToBuff() {
		cfsec::CFSecSecFormBuff* origBuff = getOrigAsSecForm()->getSecFormBuff();
		cfsec::CFSecSecFormBuff* myBuff = getSecFormEditBuff();
		if( origBuff != myBuff ) {
			*myBuff = *origBuff;
		}
	}

}
