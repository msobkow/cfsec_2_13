// Description: C++18 edit object instance implementation for CFSec Service.

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
#include <cfsecobj/CFSecServiceObj.hpp>
#include <cfsecobj/CFSecServiceEditObj.hpp>


namespace cfsec {

	const std::string CFSecServiceEditObj::CLASS_NAME( "CFSecServiceEditObj" );

	CFSecServiceEditObj::CFSecServiceEditObj( cfsec::ICFSecServiceObj* argOrig )
	: ICFSecServiceEditObj()
	{
		static const std::string S_ProcName( "CFSecServiceEditObj-construct" );
		static const std::string S_OrigBuff( "origBuff" );
		orig = argOrig;
		cfsec::CFSecServiceBuff* origBuff = orig->getBuff();
		if( origBuff == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_OrigBuff );
		}
		buff = dynamic_cast<cfsec::CFSecServiceBuff*>( origBuff->clone() );
	}

	CFSecServiceEditObj::~CFSecServiceEditObj() {
		orig = NULL;
		if( buff != NULL ) {
			delete buff;
			buff = NULL;
		}

	}

	const std::string& CFSecServiceEditObj::getClassName() const {
		return( CLASS_NAME );
	}

	cfsec::ICFSecSecUserObj* CFSecServiceEditObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<cfsec::ICFSecSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getServiceBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFSecServiceEditObj::getCreatedAt() {
		return( getServiceBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFSecServiceEditObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<cfsec::ICFSecSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getServiceBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFSecServiceEditObj::getUpdatedAt() {
		return( getServiceBuff()->getUpdatedAt() );
	}

	void CFSecServiceEditObj::setCreatedBy( cfsec::ICFSecSecUserObj* value ) {
		createdBy = value;
		if( value != NULL ) {
			getServiceEditBuff()->setCreatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFSecServiceEditObj::setCreatedAt( const std::chrono::system_clock::time_point& value ) {
		getServiceEditBuff()->setCreatedAt( value );
	}

	void CFSecServiceEditObj::setUpdatedBy( cfsec::ICFSecSecUserObj* value ) {
		updatedBy = value;
		if( value != NULL ) {
			getServiceEditBuff()->setUpdatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFSecServiceEditObj::setUpdatedAt( const std::chrono::system_clock::time_point& value ) {
		getServiceEditBuff()->setUpdatedAt( value );
	}

	const classcode_t CFSecServiceEditObj::getClassCode() const {
		return( cfsec::CFSecServiceBuff::CLASS_CODE );
	}

	bool CFSecServiceEditObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfsec::CFSecServiceBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFSecServiceEditObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecServiceEditObj" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_ClusterId( "ClusterId" );
		static const std::string S_ServiceId( "ServiceId" );
		static const std::string S_HostNodeId( "HostNodeId" );
		static const std::string S_ServiceTypeId( "ServiceTypeId" );
		static const std::string S_HostPort( "HostPort" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFSecServiceEditObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFSecServiceEditObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFSecServiceEditObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFSecServiceEditObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFSecServiceEditObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_ClusterId, CFSecServiceEditObj::getRequiredClusterId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_ServiceId, CFSecServiceEditObj::getRequiredServiceId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_HostNodeId, CFSecServiceEditObj::getRequiredHostNodeId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_ServiceTypeId, CFSecServiceEditObj::getRequiredServiceTypeId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_HostPort, CFSecServiceEditObj::getRequiredHostPort() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	int32_t CFSecServiceEditObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	void CFSecServiceEditObj::setRequiredRevision( int32_t value ) {
		getServiceEditBuff()->setRequiredRevision( value );
	}

	std::string CFSecServiceEditObj::getObjName() {
		std::string objName( CLASS_NAME ); objName;
		int64_t val = getRequiredServiceId();
		objName = cflib::CFLibXmlUtil::formatInt64( val );
		return( objName );
	}

	const std::string CFSecServiceEditObj::getGenDefName() {
		return( cfsec::CFSecServiceBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFSecServiceEditObj::getScope() {
		cfsec::ICFSecHostNodeObj* scope = getOptionalContainerHost();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFSecServiceEditObj::getObjScope() {
		cfsec::ICFSecHostNodeObj* scope = getOptionalContainerHost();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFSecServiceEditObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFSecServiceEditObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFSecServiceEditObj::getNamedObject( const std::string& objName ) {
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

	std::string CFSecServiceEditObj::getObjQualifiedName() {
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

	std::string CFSecServiceEditObj::getObjFullName() {
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

	cfsec::ICFSecServiceObj* CFSecServiceEditObj::realize() {
		// We realize this so that it's buffer will get copied to orig during realization
		cfsec::ICFSecServiceObj* retobj = getSchema()->getServiceTableObj()->realizeService( dynamic_cast<cfsec::ICFSecServiceObj*>( this ) );
		return( retobj );
	}

	cfsec::ICFSecServiceObj* CFSecServiceEditObj::read( bool forceRead ) {
		cfsec::ICFSecServiceObj* retval = getOrigAsService()->read( forceRead );
		if( retval != orig ) {
			throw cflib::CFLibUsageException( CLASS_NAME,
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	cfsec::ICFSecServiceObj* CFSecServiceEditObj::create() {
		cfsec::ICFSecServiceObj* retobj = dynamic_cast<cfsec::ICFSecSchemaObj*>( getOrigAsService()->getSchema() )->getServiceTableObj()->createService( this );
		// Note that this instance is usually discarded during the creation process,
		// and retobj now references the cached instance of the created object.
		return( retobj );
	}

	cfsec::ICFSecServiceEditObj* CFSecServiceEditObj::update() {
		getSchema()->getServiceTableObj()->updateService( this );
		return( NULL );
	}

	cfsec::ICFSecServiceEditObj* CFSecServiceEditObj::deleteInstance() {
		static const std::string S_MethodName( "deleteInstance" );
		static const std::string S_CannotDeleteNewInstance( "Cannot delete a new instance" );
		if( getIsNew() ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_MethodName, S_CannotDeleteNewInstance );
		}
		getSchema()->getServiceTableObj()->deleteService( this );
		return( NULL );
	}

	cfsec::ICFSecServiceTableObj* CFSecServiceEditObj::getServiceTable() {
		return( orig->getSchema()->getServiceTableObj() );
	}

	cfsec::ICFSecServiceEditObj* CFSecServiceEditObj::getEdit() {
		return( this );
	}

	cfsec::ICFSecServiceEditObj* CFSecServiceEditObj::getServiceEdit() {
		return( (cfsec::ICFSecServiceEditObj*)this );
	}

	cfsec::ICFSecServiceEditObj* CFSecServiceEditObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_Message( "Cannot edit an edition" );
		throw cflib::CFLibUsageException( CLASS_NAME,
			S_ProcName,
			S_Message );
	}

	void CFSecServiceEditObj::endEdit() {
		orig->endEdit();
	}

	cfsec::ICFSecServiceObj* CFSecServiceEditObj::getOrig() {
		return( orig );
	}

	cfsec::ICFSecServiceObj* CFSecServiceEditObj::getOrigAsService() {
		return( dynamic_cast<cfsec::ICFSecServiceObj*>( orig ) );
	}

	cfsec::ICFSecSchemaObj* CFSecServiceEditObj::getSchema() {
		return( orig->getSchema() );
	}

	cfsec::CFSecServiceBuff* CFSecServiceEditObj::getBuff() {
		return( buff );
	}

	void CFSecServiceEditObj::setBuff( cfsec::CFSecServiceBuff* value ) {
		if( buff != value ) {
			if( ( buff != NULL ) && ( buff != value ) ) {
				delete buff;
				buff = NULL;
			}
			buff = value;
		}
	}

	cfsec::CFSecServicePKey* CFSecServiceEditObj::getPKey() {
		return( orig->getPKey() );
	}

	void CFSecServiceEditObj::setPKey( cfsec::CFSecServicePKey* value ) {
		if( orig->getPKey() != value ) {
			orig->setPKey( value );
		}
		copyPKeyToBuff();
	}

	bool CFSecServiceEditObj::getIsNew() {
		return( orig->getIsNew() );
	}

	void CFSecServiceEditObj::setIsNew( bool value ) {
		orig->setIsNew( value );
	}

	const int64_t CFSecServiceEditObj::getRequiredClusterId() {
		return( getPKey()->getRequiredClusterId() );
	}

	const int64_t* CFSecServiceEditObj::getRequiredClusterIdReference() {
		return( getPKey()->getRequiredClusterIdReference() );
	}

	const int64_t CFSecServiceEditObj::getRequiredServiceId() {
		return( getPKey()->getRequiredServiceId() );
	}

	const int64_t* CFSecServiceEditObj::getRequiredServiceIdReference() {
		return( getPKey()->getRequiredServiceIdReference() );
	}

	const int64_t CFSecServiceEditObj::getRequiredHostNodeId() {
		return( getServiceBuff()->getRequiredHostNodeId() );
	}

	const int64_t* CFSecServiceEditObj::getRequiredHostNodeIdReference() {
		return( getServiceBuff()->getRequiredHostNodeIdReference() );
	}

	const int32_t CFSecServiceEditObj::getRequiredServiceTypeId() {
		return( getServiceBuff()->getRequiredServiceTypeId() );
	}

	const int32_t* CFSecServiceEditObj::getRequiredServiceTypeIdReference() {
		return( getServiceBuff()->getRequiredServiceTypeIdReference() );
	}

	const int16_t CFSecServiceEditObj::getRequiredHostPort() {
		return( getServiceBuff()->getRequiredHostPort() );
	}

	const int16_t* CFSecServiceEditObj::getRequiredHostPortReference() {
		return( getServiceBuff()->getRequiredHostPortReference() );
	}

	void CFSecServiceEditObj::setRequiredHostPort( const int16_t value ) {
		if( getServiceBuff()->getRequiredHostPort() != value ) {
			getServiceEditBuff()->setRequiredHostPort( value );
		}
	}

	cfsec::ICFSecClusterObj* CFSecServiceEditObj::getRequiredOwnerCluster( bool forceRead ) {
		cfsec::ICFSecClusterObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<cfsec::ICFSecSchemaObj*>( getOrigAsService()->getSchema() )->getClusterTableObj()->readClusterByIdIdx( getPKey()->getRequiredClusterId() );
		}
		return( retobj );
	}

	void CFSecServiceEditObj::setRequiredOwnerCluster( cfsec::ICFSecClusterObj* value ) {
			
			if( value != NULL ) {
				getPKey()->setRequiredClusterId
( value->getRequiredId() );
				getServiceEditBuff()->setRequiredClusterId( value->getRequiredId() );
			}
		}

	cfsec::ICFSecHostNodeObj* CFSecServiceEditObj::getOptionalContainerHost( bool forceRead ) {
		cfsec::ICFSecHostNodeObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<cfsec::ICFSecSchemaObj*>( getOrigAsService()->getSchema() )->getHostNodeTableObj()->readHostNodeByIdIdx( getPKey()->getRequiredClusterId(),
					getServiceBuff()->getRequiredHostNodeId() );
		}
		return( retobj );
	}

	void CFSecServiceEditObj::setOptionalContainerHost( cfsec::ICFSecHostNodeObj* value ) {
			
			if( value != NULL ) {
				getPKey()->setRequiredClusterId
( value->getRequiredClusterId() );
				getServiceEditBuff()->setRequiredClusterId( value->getRequiredClusterId() );
				getServiceEditBuff()->setRequiredHostNodeId( value->getRequiredHostNodeId() );
			}
		}

	cfsec::ICFSecServiceTypeObj* CFSecServiceEditObj::getOptionalParentServiceType( bool forceRead ) {
		cfsec::ICFSecServiceTypeObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<cfsec::ICFSecSchemaObj*>( getOrigAsService()->getSchema() )->getServiceTypeTableObj()->readServiceTypeByIdIdx( getServiceBuff()->getRequiredServiceTypeId() );
		}
		return( retobj );
	}

	void CFSecServiceEditObj::setOptionalParentServiceType( cfsec::ICFSecServiceTypeObj* value ) {
			
			if( value != NULL ) {
				getServiceEditBuff()->setRequiredServiceTypeId( value->getRequiredServiceTypeId() );
			}
			else {
			}
		}

	void CFSecServiceEditObj::copyPKeyToBuff() {
		cfsec::CFSecServicePKey* tablePKey = getPKey();
		cfsec::CFSecServiceBuff* tableBuff = getServiceEditBuff();
		tableBuff->setRequiredClusterId( tablePKey->getRequiredClusterId() );
		tableBuff->setRequiredServiceId( tablePKey->getRequiredServiceId() );
	}

	void CFSecServiceEditObj::copyBuffToPKey() {
		cfsec::CFSecServicePKey* tablePKey = getPKey();
		cfsec::CFSecServiceBuff* tableBuff = getServiceBuff();
		tablePKey->setRequiredClusterId( tableBuff->getRequiredClusterId() );
		tablePKey->setRequiredServiceId( tableBuff->getRequiredServiceId() );
	}

	void CFSecServiceEditObj::copyBuffToOrig() {
		cfsec::CFSecServiceBuff* origBuff = getOrigAsService()->getServiceEditBuff();
		cfsec::CFSecServiceBuff* myBuff = getServiceBuff();
		if( origBuff != myBuff ) {
			*origBuff = *myBuff;
		}
	}

	void CFSecServiceEditObj::copyOrigToBuff() {
		cfsec::CFSecServiceBuff* origBuff = getOrigAsService()->getServiceBuff();
		cfsec::CFSecServiceBuff* myBuff = getServiceEditBuff();
		if( origBuff != myBuff ) {
			*myBuff = *origBuff;
		}
	}

}
