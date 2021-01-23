// Description: C++18 base object instance implementation for CFSec Cluster.

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
#include <cfsecobj/CFSecClusterObj.hpp>

namespace cfsec {

	const std::string CFSecClusterObj::CLASS_NAME( "CFSecClusterObj" );
	const classcode_t CFSecClusterObj::CLASS_CODE = 0xa001L;

	int32_t CFSecClusterObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	const int64_t CFSecClusterObj::getRequiredId() {
		return( getPKey()->getRequiredId() );
	}

	const int64_t* CFSecClusterObj::getRequiredIdReference() {
		return( getPKey()->getRequiredIdReference() );
	}

	const std::string& CFSecClusterObj::getRequiredFullDomName() {
		return( getClusterBuff()->getRequiredFullDomName() );
	}

	const std::string* CFSecClusterObj::getRequiredFullDomNameReference() {
		return( getClusterBuff()->getRequiredFullDomNameReference() );
	}

	const std::string& CFSecClusterObj::getRequiredDescription() {
		return( getClusterBuff()->getRequiredDescription() );
	}

	const std::string* CFSecClusterObj::getRequiredDescriptionReference() {
		return( getClusterBuff()->getRequiredDescriptionReference() );
	}


	std::vector<cfsec::ICFSecHostNodeObj*> CFSecClusterObj::getOptionalComponentsHostNode( bool forceRead ) {
		std::vector<cfsec::ICFSecHostNodeObj*> retval;
		retval = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getHostNodeTableObj()->readHostNodeByClusterIdx( getPKey()->getRequiredId(),
			forceRead );
		return( retval );
	}

	std::vector<cfsec::ICFSecTenantObj*> CFSecClusterObj::getOptionalComponentsTenant( bool forceRead ) {
		std::vector<cfsec::ICFSecTenantObj*> retval;
		retval = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getTenantTableObj()->readTenantByClusterIdx( getPKey()->getRequiredId(),
			forceRead );
		return( retval );
	}

	std::vector<cfsec::ICFSecSecAppObj*> CFSecClusterObj::getOptionalComponentsSecApp( bool forceRead ) {
		std::vector<cfsec::ICFSecSecAppObj*> retval;
		retval = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecAppTableObj()->readSecAppByClusterIdx( getPKey()->getRequiredId(),
			forceRead );
		return( retval );
	}

	std::vector<cfsec::ICFSecSecGroupObj*> CFSecClusterObj::getOptionalComponentsSecGroup( bool forceRead ) {
		std::vector<cfsec::ICFSecSecGroupObj*> retval;
		retval = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecGroupTableObj()->readSecGroupByClusterIdx( getPKey()->getRequiredId(),
			forceRead );
		return( retval );
	}

	std::vector<cfsec::ICFSecSysClusterObj*> CFSecClusterObj::getOptionalComponentsSysCluster( bool forceRead ) {
		std::vector<cfsec::ICFSecSysClusterObj*> retval;
		retval = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSysClusterTableObj()->readSysClusterByClusterIdx( getPKey()->getRequiredId(),
			forceRead );
		return( retval );
	}

	CFSecClusterObj::CFSecClusterObj()
	: ICFSecClusterObj()
	{
		schema = NULL;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFSecClusterObj::CFSecClusterObj( cfsec::ICFSecSchemaObj* argSchema )
	: ICFSecClusterObj()
	{
		schema = argSchema;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFSecClusterObj::~CFSecClusterObj() {
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

	cfsec::CFSecClusterBuff* CFSecClusterObj::getBuff() {
		if( buff == NULL ) {
			if( isNew ) {
				buff = new cfsec::CFSecClusterBuff();
				copyBuffToPKey();
			}
			else {
				// Read the data buff via the backing store
				buff = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableCluster()->readDerivedByIdIdx( dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getAuthorization(),
						getPKey()->getRequiredId() );
			}
		}
		return( buff );
	}

	void CFSecClusterObj::setBuff( cfsec::CFSecClusterBuff* value ) {
		if( ( buff != NULL ) && ( buff != value ) ) {
			delete buff;
			buff = NULL;
		}
		buff = value;
		if( buff != NULL ) {
			copyBuffToPKey();
		}
	}

	const std::string& CFSecClusterObj::getClassName() const {
		return( CLASS_NAME );
	}

	const classcode_t CFSecClusterObj::getClassCode() const {
		return( CLASS_CODE );
	}

	bool CFSecClusterObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfsec::CFSecClusterBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFSecClusterObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecClusterObj" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_Id( "Id" );
		static const std::string S_FullDomName( "FullDomName" );
		static const std::string S_Description( "Description" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFSecClusterObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFSecClusterObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFSecClusterObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFSecClusterObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFSecClusterObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_Id, CFSecClusterObj::getRequiredId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_FullDomName, CFSecClusterObj::getRequiredFullDomName() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Description, CFSecClusterObj::getRequiredDescription() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	std::string CFSecClusterObj::getObjName() {
		std::string objName( CLASS_NAME );
		objName.clear();
		objName.append( getRequiredFullDomName() );
		return( objName );
	}

	const std::string CFSecClusterObj::getGenDefName() {
		return( cfsec::CFSecClusterBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFSecClusterObj::getScope() {
		return( NULL );
	}

	cflib::ICFLibAnyObj* CFSecClusterObj::getObjScope() {
		return( NULL );
	}

	cflib::ICFLibAnyObj* CFSecClusterObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFSecClusterObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFSecClusterObj::getNamedObject( const std::string& objName ) {
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
			subObj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getHostNodeTableObj()->readHostNodeByLookupHostNameIdx( getRequiredId(),
				nextName,
				false );
		}
		if( subObj == NULL ) {
			subObj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getTenantTableObj()->readTenantByLookupUNameIdx( getRequiredId(),
				nextName,
				false );
		}
		if( subObj == NULL ) {
			subObj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecAppTableObj()->readSecAppByLookupUJEEMountIdx( getRequiredId(),
				nextName,
				false );
		}
		if( subObj == NULL ) {
			subObj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecGroupTableObj()->readSecGroupByLookupUNameIdx( getRequiredId(),
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

	std::string CFSecClusterObj::getObjQualifiedName() {
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

	std::string CFSecClusterObj::getObjFullName() {
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

	cfsec::ICFSecClusterObj* CFSecClusterObj::realize() {
		cfsec::ICFSecClusterObj* retobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getClusterTableObj()->realizeCluster(
			(cfsec::ICFSecClusterObj*)this );
		return( dynamic_cast<cfsec::ICFSecClusterObj*>( retobj ) );
	}

	cfsec::ICFSecClusterObj* CFSecClusterObj::read( bool forceRead ) {
		cfsec::ICFSecClusterObj* retobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getClusterTableObj()->readClusterByIdIdx( getClusterBuff()->getRequiredId(), forceRead );
		return( dynamic_cast<cfsec::ICFSecClusterObj*>( retobj ) );
	}

	cfsec::ICFSecClusterTableObj* CFSecClusterObj::getClusterTable() {
		return( dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getClusterTableObj() );
	}

	cfsec::ICFSecSchemaObj* CFSecClusterObj::getSchema() {
		return( schema );
	}

	void CFSecClusterObj::setSchema( cfsec::ICFSecSchemaObj* value ) {
		schema = value;
	}

	cfsec::CFSecClusterPKey* CFSecClusterObj::getPKey() {
		if( pKey == NULL ) {
			pKey = new cfsec::CFSecClusterPKey();
		}
		return( pKey );
	}

	void CFSecClusterObj::setPKey( cfsec::CFSecClusterPKey* value ) {
		if( ( pKey != NULL ) && ( pKey != value ) ) {
			delete pKey;
			pKey = NULL;
		}
		if( value != NULL ) {
			pKey = new cfsec::CFSecClusterPKey();
			*pKey = *value;
			copyPKeyToBuff();
		}
	}

	bool CFSecClusterObj::getIsNew() {
		return( isNew );
	}

	void CFSecClusterObj::setIsNew( bool value ) {
		isNew = value;
	}

	cfsec::ICFSecClusterEditObj* CFSecClusterObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_EditAlreadyOpen( "An edit is already open" );
		if( edit != NULL ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_ProcName, S_EditAlreadyOpen );
		}
		if( ! getIsNew() ) {
			cfsec::ICFSecClusterObj* lockobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getClusterTableObj()->lockCluster( getPKey() );
			lockobj->realize();
		}
		edit = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getClusterTableObj()->newEditInstance( this );
		return( dynamic_cast<cfsec::ICFSecClusterEditObj*>( edit ) );
	}

	void CFSecClusterObj::endEdit() {
		if( edit != NULL ) {
			delete edit;
			edit = NULL;
		}
	}

	cfsec::ICFSecClusterEditObj* CFSecClusterObj::getEdit() {
		return( edit );
	}

	cfsec::ICFSecClusterEditObj* CFSecClusterObj::getClusterEdit() {
		return( dynamic_cast<cfsec::ICFSecClusterEditObj*>( edit ) );
	}

	cfsec::ICFSecSecUserObj* CFSecClusterObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getClusterBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFSecClusterObj::getCreatedAt() {
		return( getClusterBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFSecClusterObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getClusterBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFSecClusterObj::getUpdatedAt() {
		return( getClusterBuff()->getUpdatedAt() );
	}

	void CFSecClusterObj::copyPKeyToBuff() {
		cfsec::CFSecClusterPKey* tablePKey = getPKey();
		cfsec::CFSecClusterBuff* tableBuff = getClusterEditBuff();
		if( tableBuff != NULL ) {
			tableBuff->setRequiredId( tablePKey->getRequiredId() );
		}
		if( edit != NULL ) {
			edit->copyPKeyToBuff();
		}
	}

	void CFSecClusterObj::copyBuffToPKey() {
		cfsec::CFSecClusterPKey* tablePKey = getPKey();
		cfsec::CFSecClusterBuff* tableBuff = getClusterBuff();
		tablePKey->setRequiredId( tableBuff->getRequiredId() );
	}

}
