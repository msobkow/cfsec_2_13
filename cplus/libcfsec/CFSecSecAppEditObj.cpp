// Description: C++18 edit object instance implementation for CFSec SecApp.

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
#include <cfsecobj/CFSecSecAppEditObj.hpp>


namespace cfsec {

	const std::string CFSecSecAppEditObj::CLASS_NAME( "CFSecSecAppEditObj" );

	CFSecSecAppEditObj::CFSecSecAppEditObj( cfsec::ICFSecSecAppObj* argOrig )
	: ICFSecSecAppEditObj()
	{
		static const std::string S_ProcName( "CFSecSecAppEditObj-construct" );
		static const std::string S_OrigBuff( "origBuff" );
		orig = argOrig;
		cfsec::CFSecSecAppBuff* origBuff = orig->getBuff();
		if( origBuff == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_OrigBuff );
		}
		buff = dynamic_cast<cfsec::CFSecSecAppBuff*>( origBuff->clone() );
	}

	CFSecSecAppEditObj::~CFSecSecAppEditObj() {
		orig = NULL;
		if( buff != NULL ) {
			delete buff;
			buff = NULL;
		}

	}

	const std::string& CFSecSecAppEditObj::getClassName() const {
		return( CLASS_NAME );
	}

	cfsec::ICFSecSecUserObj* CFSecSecAppEditObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<cfsec::ICFSecSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getSecAppBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFSecSecAppEditObj::getCreatedAt() {
		return( getSecAppBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFSecSecAppEditObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<cfsec::ICFSecSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getSecAppBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFSecSecAppEditObj::getUpdatedAt() {
		return( getSecAppBuff()->getUpdatedAt() );
	}

	void CFSecSecAppEditObj::setCreatedBy( cfsec::ICFSecSecUserObj* value ) {
		createdBy = value;
		if( value != NULL ) {
			getSecAppEditBuff()->setCreatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFSecSecAppEditObj::setCreatedAt( const std::chrono::system_clock::time_point& value ) {
		getSecAppEditBuff()->setCreatedAt( value );
	}

	void CFSecSecAppEditObj::setUpdatedBy( cfsec::ICFSecSecUserObj* value ) {
		updatedBy = value;
		if( value != NULL ) {
			getSecAppEditBuff()->setUpdatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFSecSecAppEditObj::setUpdatedAt( const std::chrono::system_clock::time_point& value ) {
		getSecAppEditBuff()->setUpdatedAt( value );
	}

	const classcode_t CFSecSecAppEditObj::getClassCode() const {
		return( cfsec::CFSecSecAppBuff::CLASS_CODE );
	}

	bool CFSecSecAppEditObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfsec::CFSecSecAppBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFSecSecAppEditObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecSecAppEditObj" );
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
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFSecSecAppEditObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFSecSecAppEditObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFSecSecAppEditObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFSecSecAppEditObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFSecSecAppEditObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_ClusterId, CFSecSecAppEditObj::getRequiredClusterId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_SecAppId, CFSecSecAppEditObj::getRequiredSecAppId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_JEEMountName, CFSecSecAppEditObj::getRequiredJEEMountName() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	int32_t CFSecSecAppEditObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	void CFSecSecAppEditObj::setRequiredRevision( int32_t value ) {
		getSecAppEditBuff()->setRequiredRevision( value );
	}

	std::string CFSecSecAppEditObj::getObjName() {
		std::string objName( CLASS_NAME ); objName;
		objName.clear();
		objName.append( getRequiredJEEMountName() );
		return( objName );
	}

	const std::string CFSecSecAppEditObj::getGenDefName() {
		return( cfsec::CFSecSecAppBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFSecSecAppEditObj::getScope() {
		cfsec::ICFSecClusterObj* scope = getRequiredContainerCluster();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFSecSecAppEditObj::getObjScope() {
		cfsec::ICFSecClusterObj* scope = getRequiredContainerCluster();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFSecSecAppEditObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFSecSecAppEditObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFSecSecAppEditObj::getNamedObject( const std::string& objName ) {
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

	std::string CFSecSecAppEditObj::getObjQualifiedName() {
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

	std::string CFSecSecAppEditObj::getObjFullName() {
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

	cfsec::ICFSecSecAppObj* CFSecSecAppEditObj::realize() {
		// We realize this so that it's buffer will get copied to orig during realization
		cfsec::ICFSecSecAppObj* retobj = getSchema()->getSecAppTableObj()->realizeSecApp( dynamic_cast<cfsec::ICFSecSecAppObj*>( this ) );
		return( retobj );
	}

	cfsec::ICFSecSecAppObj* CFSecSecAppEditObj::read( bool forceRead ) {
		cfsec::ICFSecSecAppObj* retval = getOrigAsSecApp()->read( forceRead );
		if( retval != orig ) {
			throw cflib::CFLibUsageException( CLASS_NAME,
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	cfsec::ICFSecSecAppObj* CFSecSecAppEditObj::create() {
		cfsec::ICFSecSecAppObj* retobj = dynamic_cast<cfsec::ICFSecSchemaObj*>( getOrigAsSecApp()->getSchema() )->getSecAppTableObj()->createSecApp( this );
		// Note that this instance is usually discarded during the creation process,
		// and retobj now references the cached instance of the created object.
		return( retobj );
	}

	cfsec::ICFSecSecAppEditObj* CFSecSecAppEditObj::update() {
		getSchema()->getSecAppTableObj()->updateSecApp( this );
		return( NULL );
	}

	cfsec::ICFSecSecAppEditObj* CFSecSecAppEditObj::deleteInstance() {
		static const std::string S_MethodName( "deleteInstance" );
		static const std::string S_CannotDeleteNewInstance( "Cannot delete a new instance" );
		if( getIsNew() ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_MethodName, S_CannotDeleteNewInstance );
		}
		getSchema()->getSecAppTableObj()->deleteSecApp( this );
		return( NULL );
	}

	cfsec::ICFSecSecAppTableObj* CFSecSecAppEditObj::getSecAppTable() {
		return( orig->getSchema()->getSecAppTableObj() );
	}

	cfsec::ICFSecSecAppEditObj* CFSecSecAppEditObj::getEdit() {
		return( this );
	}

	cfsec::ICFSecSecAppEditObj* CFSecSecAppEditObj::getSecAppEdit() {
		return( (cfsec::ICFSecSecAppEditObj*)this );
	}

	cfsec::ICFSecSecAppEditObj* CFSecSecAppEditObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_Message( "Cannot edit an edition" );
		throw cflib::CFLibUsageException( CLASS_NAME,
			S_ProcName,
			S_Message );
	}

	void CFSecSecAppEditObj::endEdit() {
		orig->endEdit();
	}

	cfsec::ICFSecSecAppObj* CFSecSecAppEditObj::getOrig() {
		return( orig );
	}

	cfsec::ICFSecSecAppObj* CFSecSecAppEditObj::getOrigAsSecApp() {
		return( dynamic_cast<cfsec::ICFSecSecAppObj*>( orig ) );
	}

	cfsec::ICFSecSchemaObj* CFSecSecAppEditObj::getSchema() {
		return( orig->getSchema() );
	}

	cfsec::CFSecSecAppBuff* CFSecSecAppEditObj::getBuff() {
		return( buff );
	}

	void CFSecSecAppEditObj::setBuff( cfsec::CFSecSecAppBuff* value ) {
		if( buff != value ) {
			if( ( buff != NULL ) && ( buff != value ) ) {
				delete buff;
				buff = NULL;
			}
			buff = value;
		}
	}

	cfsec::CFSecSecAppPKey* CFSecSecAppEditObj::getPKey() {
		return( orig->getPKey() );
	}

	void CFSecSecAppEditObj::setPKey( cfsec::CFSecSecAppPKey* value ) {
		if( orig->getPKey() != value ) {
			orig->setPKey( value );
		}
		copyPKeyToBuff();
	}

	bool CFSecSecAppEditObj::getIsNew() {
		return( orig->getIsNew() );
	}

	void CFSecSecAppEditObj::setIsNew( bool value ) {
		orig->setIsNew( value );
	}

	const int64_t CFSecSecAppEditObj::getRequiredClusterId() {
		return( getPKey()->getRequiredClusterId() );
	}

	const int64_t* CFSecSecAppEditObj::getRequiredClusterIdReference() {
		return( getPKey()->getRequiredClusterIdReference() );
	}

	const int32_t CFSecSecAppEditObj::getRequiredSecAppId() {
		return( getPKey()->getRequiredSecAppId() );
	}

	const int32_t* CFSecSecAppEditObj::getRequiredSecAppIdReference() {
		return( getPKey()->getRequiredSecAppIdReference() );
	}

	const std::string& CFSecSecAppEditObj::getRequiredJEEMountName() {
		return( getSecAppBuff()->getRequiredJEEMountName() );
	}

	const std::string* CFSecSecAppEditObj::getRequiredJEEMountNameReference() {
		return( getSecAppBuff()->getRequiredJEEMountNameReference() );
	}

	void CFSecSecAppEditObj::setRequiredJEEMountName( const std::string& value ) {
		if( getSecAppBuff()->getRequiredJEEMountName() != value ) {
			getSecAppEditBuff()->setRequiredJEEMountName( value );
		}
	}

	cfsec::ICFSecClusterObj* CFSecSecAppEditObj::getRequiredContainerCluster( bool forceRead ) {
		cfsec::ICFSecClusterObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<cfsec::ICFSecSchemaObj*>( getOrigAsSecApp()->getSchema() )->getClusterTableObj()->readClusterByIdIdx( getPKey()->getRequiredClusterId() );
		}
		return( retobj );
	}

	void CFSecSecAppEditObj::setRequiredContainerCluster( cfsec::ICFSecClusterObj* value ) {
			
			if( value != NULL ) {
				getPKey()->setRequiredClusterId
( value->getRequiredId() );
				getSecAppEditBuff()->setRequiredClusterId( value->getRequiredId() );
			}
		}

	std::vector<cfsec::ICFSecSecFormObj*> CFSecSecAppEditObj::getOptionalComponentsForm( bool forceRead ) {
		std::vector<cfsec::ICFSecSecFormObj*> retval;
		retval = dynamic_cast<cfsec::ICFSecSchemaObj*>( getOrigAsSecApp()->getSchema() )->getSecFormTableObj()->readSecFormBySecAppIdx( getPKey()->getRequiredClusterId(),
					getPKey()->getRequiredSecAppId(),
			forceRead );
		return( retval );
	}

	void CFSecSecAppEditObj::copyPKeyToBuff() {
		cfsec::CFSecSecAppPKey* tablePKey = getPKey();
		cfsec::CFSecSecAppBuff* tableBuff = getSecAppEditBuff();
		tableBuff->setRequiredClusterId( tablePKey->getRequiredClusterId() );
		tableBuff->setRequiredSecAppId( tablePKey->getRequiredSecAppId() );
	}

	void CFSecSecAppEditObj::copyBuffToPKey() {
		cfsec::CFSecSecAppPKey* tablePKey = getPKey();
		cfsec::CFSecSecAppBuff* tableBuff = getSecAppBuff();
		tablePKey->setRequiredClusterId( tableBuff->getRequiredClusterId() );
		tablePKey->setRequiredSecAppId( tableBuff->getRequiredSecAppId() );
	}

	void CFSecSecAppEditObj::copyBuffToOrig() {
		cfsec::CFSecSecAppBuff* origBuff = getOrigAsSecApp()->getSecAppEditBuff();
		cfsec::CFSecSecAppBuff* myBuff = getSecAppBuff();
		if( origBuff != myBuff ) {
			*origBuff = *myBuff;
		}
	}

	void CFSecSecAppEditObj::copyOrigToBuff() {
		cfsec::CFSecSecAppBuff* origBuff = getOrigAsSecApp()->getSecAppBuff();
		cfsec::CFSecSecAppBuff* myBuff = getSecAppEditBuff();
		if( origBuff != myBuff ) {
			*myBuff = *origBuff;
		}
	}

}
