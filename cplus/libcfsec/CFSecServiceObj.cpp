// Description: C++18 base object instance implementation for CFSec Service.

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
#include <cfsecobj/CFSecServiceObj.hpp>

namespace cfsec {

	const std::string CFSecServiceObj::CLASS_NAME( "CFSecServiceObj" );
	const classcode_t CFSecServiceObj::CLASS_CODE = 0xa012L;

	int32_t CFSecServiceObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	const int64_t CFSecServiceObj::getRequiredClusterId() {
		return( getPKey()->getRequiredClusterId() );
	}

	const int64_t* CFSecServiceObj::getRequiredClusterIdReference() {
		return( getPKey()->getRequiredClusterIdReference() );
	}

	const int64_t CFSecServiceObj::getRequiredServiceId() {
		return( getPKey()->getRequiredServiceId() );
	}

	const int64_t* CFSecServiceObj::getRequiredServiceIdReference() {
		return( getPKey()->getRequiredServiceIdReference() );
	}

	const int64_t CFSecServiceObj::getRequiredHostNodeId() {
		return( getServiceBuff()->getRequiredHostNodeId() );
	}

	const int64_t* CFSecServiceObj::getRequiredHostNodeIdReference() {
		return( getServiceBuff()->getRequiredHostNodeIdReference() );
	}

	const int32_t CFSecServiceObj::getRequiredServiceTypeId() {
		return( getServiceBuff()->getRequiredServiceTypeId() );
	}

	const int32_t* CFSecServiceObj::getRequiredServiceTypeIdReference() {
		return( getServiceBuff()->getRequiredServiceTypeIdReference() );
	}

	const int16_t CFSecServiceObj::getRequiredHostPort() {
		return( getServiceBuff()->getRequiredHostPort() );
	}

	const int16_t* CFSecServiceObj::getRequiredHostPortReference() {
		return( getServiceBuff()->getRequiredHostPortReference() );
	}


	cfsec::ICFSecClusterObj* CFSecServiceObj::getRequiredOwnerCluster( bool forceRead ) {
		cfsec::ICFSecClusterObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getClusterTableObj()->readClusterByIdIdx( getPKey()->getRequiredClusterId(), forceRead );
		}
		return( retobj );
	}

	cfsec::ICFSecHostNodeObj* CFSecServiceObj::getOptionalContainerHost( bool forceRead ) {
		cfsec::ICFSecHostNodeObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getHostNodeTableObj()->readHostNodeByIdIdx( getPKey()->getRequiredClusterId(),
					getServiceBuff()->getRequiredHostNodeId(), forceRead );
		}
		return( retobj );
	}

	cfsec::ICFSecServiceTypeObj* CFSecServiceObj::getOptionalParentServiceType( bool forceRead ) {
		cfsec::ICFSecServiceTypeObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getServiceTypeTableObj()->readServiceTypeByIdIdx( getServiceBuff()->getRequiredServiceTypeId(), forceRead );
		}
		return( retobj );
	}

	CFSecServiceObj::CFSecServiceObj()
	: ICFSecServiceObj()
	{
		schema = NULL;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFSecServiceObj::CFSecServiceObj( cfsec::ICFSecSchemaObj* argSchema )
	: ICFSecServiceObj()
	{
		schema = argSchema;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFSecServiceObj::~CFSecServiceObj() {
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

	cfsec::CFSecServiceBuff* CFSecServiceObj::getBuff() {
		if( buff == NULL ) {
			if( isNew ) {
				buff = new cfsec::CFSecServiceBuff();
				copyBuffToPKey();
			}
			else {
				// Read the data buff via the backing store
				buff = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableService()->readDerivedByIdIdx( dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getAuthorization(),
						getPKey()->getRequiredClusterId(),
						getPKey()->getRequiredServiceId() );
			}
		}
		return( buff );
	}

	void CFSecServiceObj::setBuff( cfsec::CFSecServiceBuff* value ) {
		if( ( buff != NULL ) && ( buff != value ) ) {
			delete buff;
			buff = NULL;
		}
		buff = value;
		if( buff != NULL ) {
			copyBuffToPKey();
		}
	}

	const std::string& CFSecServiceObj::getClassName() const {
		return( CLASS_NAME );
	}

	const classcode_t CFSecServiceObj::getClassCode() const {
		return( CLASS_CODE );
	}

	bool CFSecServiceObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfsec::CFSecServiceBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFSecServiceObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecServiceObj" );
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
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFSecServiceObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFSecServiceObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFSecServiceObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFSecServiceObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFSecServiceObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_ClusterId, CFSecServiceObj::getRequiredClusterId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_ServiceId, CFSecServiceObj::getRequiredServiceId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_HostNodeId, CFSecServiceObj::getRequiredHostNodeId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_ServiceTypeId, CFSecServiceObj::getRequiredServiceTypeId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_HostPort, CFSecServiceObj::getRequiredHostPort() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	std::string CFSecServiceObj::getObjName() {
		std::string objName( CLASS_NAME );
		int64_t val = getRequiredServiceId();
		objName = cflib::CFLibXmlUtil::formatInt64( val );
		return( objName );
	}

	const std::string CFSecServiceObj::getGenDefName() {
		return( cfsec::CFSecServiceBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFSecServiceObj::getScope() {
		cfsec::ICFSecHostNodeObj* scope = getOptionalContainerHost();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFSecServiceObj::getObjScope() {
		cfsec::ICFSecHostNodeObj* scope = getOptionalContainerHost();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFSecServiceObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFSecServiceObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFSecServiceObj::getNamedObject( const std::string& objName ) {
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

	std::string CFSecServiceObj::getObjQualifiedName() {
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

	std::string CFSecServiceObj::getObjFullName() {
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

	cfsec::ICFSecServiceObj* CFSecServiceObj::realize() {
		cfsec::ICFSecServiceObj* retobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getServiceTableObj()->realizeService(
			(cfsec::ICFSecServiceObj*)this );
		return( dynamic_cast<cfsec::ICFSecServiceObj*>( retobj ) );
	}

	cfsec::ICFSecServiceObj* CFSecServiceObj::read( bool forceRead ) {
		cfsec::ICFSecServiceObj* retobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getServiceTableObj()->readServiceByIdIdx( getServiceBuff()->getRequiredClusterId(),
		getServiceBuff()->getRequiredServiceId(), forceRead );
		return( dynamic_cast<cfsec::ICFSecServiceObj*>( retobj ) );
	}

	cfsec::ICFSecServiceTableObj* CFSecServiceObj::getServiceTable() {
		return( dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getServiceTableObj() );
	}

	cfsec::ICFSecSchemaObj* CFSecServiceObj::getSchema() {
		return( schema );
	}

	void CFSecServiceObj::setSchema( cfsec::ICFSecSchemaObj* value ) {
		schema = value;
	}

	cfsec::CFSecServicePKey* CFSecServiceObj::getPKey() {
		if( pKey == NULL ) {
			pKey = new cfsec::CFSecServicePKey();
		}
		return( pKey );
	}

	void CFSecServiceObj::setPKey( cfsec::CFSecServicePKey* value ) {
		if( ( pKey != NULL ) && ( pKey != value ) ) {
			delete pKey;
			pKey = NULL;
		}
		if( value != NULL ) {
			pKey = new cfsec::CFSecServicePKey();
			*pKey = *value;
			copyPKeyToBuff();
		}
	}

	bool CFSecServiceObj::getIsNew() {
		return( isNew );
	}

	void CFSecServiceObj::setIsNew( bool value ) {
		isNew = value;
	}

	cfsec::ICFSecServiceEditObj* CFSecServiceObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_EditAlreadyOpen( "An edit is already open" );
		if( edit != NULL ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_ProcName, S_EditAlreadyOpen );
		}
		if( ! getIsNew() ) {
			cfsec::ICFSecServiceObj* lockobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getServiceTableObj()->lockService( getPKey() );
			lockobj->realize();
		}
		edit = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getServiceTableObj()->newEditInstance( this );
		return( dynamic_cast<cfsec::ICFSecServiceEditObj*>( edit ) );
	}

	void CFSecServiceObj::endEdit() {
		if( edit != NULL ) {
			delete edit;
			edit = NULL;
		}
	}

	cfsec::ICFSecServiceEditObj* CFSecServiceObj::getEdit() {
		return( edit );
	}

	cfsec::ICFSecServiceEditObj* CFSecServiceObj::getServiceEdit() {
		return( dynamic_cast<cfsec::ICFSecServiceEditObj*>( edit ) );
	}

	cfsec::ICFSecSecUserObj* CFSecServiceObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getServiceBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFSecServiceObj::getCreatedAt() {
		return( getServiceBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFSecServiceObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getServiceBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFSecServiceObj::getUpdatedAt() {
		return( getServiceBuff()->getUpdatedAt() );
	}

	void CFSecServiceObj::copyPKeyToBuff() {
		cfsec::CFSecServicePKey* tablePKey = getPKey();
		cfsec::CFSecServiceBuff* tableBuff = getServiceEditBuff();
		if( tableBuff != NULL ) {
			tableBuff->setRequiredClusterId( tablePKey->getRequiredClusterId() );
			tableBuff->setRequiredServiceId( tablePKey->getRequiredServiceId() );
		}
		if( edit != NULL ) {
			edit->copyPKeyToBuff();
		}
	}

	void CFSecServiceObj::copyBuffToPKey() {
		cfsec::CFSecServicePKey* tablePKey = getPKey();
		cfsec::CFSecServiceBuff* tableBuff = getServiceBuff();
		tablePKey->setRequiredClusterId( tableBuff->getRequiredClusterId() );
		tablePKey->setRequiredServiceId( tableBuff->getRequiredServiceId() );
	}

}
