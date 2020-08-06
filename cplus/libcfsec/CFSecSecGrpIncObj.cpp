// Description: C++18 base object instance implementation for CFSec SecGrpInc.

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
#include <cfsecobj/CFSecSecGrpIncObj.hpp>

namespace cfsec {

	const std::string CFSecSecGrpIncObj::CLASS_NAME( "CFSecSecGrpIncObj" );
	const classcode_t CFSecSecGrpIncObj::CLASS_CODE = 0xa00eL;

	int32_t CFSecSecGrpIncObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	const int64_t CFSecSecGrpIncObj::getRequiredClusterId() {
		return( getPKey()->getRequiredClusterId() );
	}

	const int64_t* CFSecSecGrpIncObj::getRequiredClusterIdReference() {
		return( getPKey()->getRequiredClusterIdReference() );
	}

	const int64_t CFSecSecGrpIncObj::getRequiredSecGrpIncId() {
		return( getPKey()->getRequiredSecGrpIncId() );
	}

	const int64_t* CFSecSecGrpIncObj::getRequiredSecGrpIncIdReference() {
		return( getPKey()->getRequiredSecGrpIncIdReference() );
	}

	const int32_t CFSecSecGrpIncObj::getRequiredSecGroupId() {
		return( getSecGrpIncBuff()->getRequiredSecGroupId() );
	}

	const int32_t* CFSecSecGrpIncObj::getRequiredSecGroupIdReference() {
		return( getSecGrpIncBuff()->getRequiredSecGroupIdReference() );
	}

	const int32_t CFSecSecGrpIncObj::getRequiredIncludeGroupId() {
		return( getSecGrpIncBuff()->getRequiredIncludeGroupId() );
	}

	const int32_t* CFSecSecGrpIncObj::getRequiredIncludeGroupIdReference() {
		return( getSecGrpIncBuff()->getRequiredIncludeGroupIdReference() );
	}


	cfsec::ICFSecClusterObj* CFSecSecGrpIncObj::getRequiredOwnerCluster( bool forceRead ) {
		cfsec::ICFSecClusterObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getClusterTableObj()->readClusterByIdIdx( getPKey()->getRequiredClusterId(), forceRead );
		}
		return( retobj );
	}

	cfsec::ICFSecSecGroupObj* CFSecSecGrpIncObj::getRequiredContainerGroup( bool forceRead ) {
		cfsec::ICFSecSecGroupObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecGroupTableObj()->readSecGroupByIdIdx( getPKey()->getRequiredClusterId(),
					getSecGrpIncBuff()->getRequiredSecGroupId(), forceRead );
		}
		return( retobj );
	}

	cfsec::ICFSecSecGroupObj* CFSecSecGrpIncObj::getRequiredParentSubGroup( bool forceRead ) {
		cfsec::ICFSecSecGroupObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecGroupTableObj()->readSecGroupByIdIdx( getPKey()->getRequiredClusterId(),
					getSecGrpIncBuff()->getRequiredIncludeGroupId(), forceRead );
		}
		return( retobj );
	}

	CFSecSecGrpIncObj::CFSecSecGrpIncObj()
	: ICFSecSecGrpIncObj()
	{
		schema = NULL;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFSecSecGrpIncObj::CFSecSecGrpIncObj( cfsec::ICFSecSchemaObj* argSchema )
	: ICFSecSecGrpIncObj()
	{
		schema = argSchema;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFSecSecGrpIncObj::~CFSecSecGrpIncObj() {
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

	cfsec::CFSecSecGrpIncBuff* CFSecSecGrpIncObj::getBuff() {
		if( buff == NULL ) {
			if( isNew ) {
				buff = new cfsec::CFSecSecGrpIncBuff();
				copyBuffToPKey();
			}
			else {
				// Read the data buff via the backing store
				buff = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecGrpInc()->readDerivedByIdIdx( dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getAuthorization(),
						getPKey()->getRequiredClusterId(),
						getPKey()->getRequiredSecGrpIncId() );
			}
		}
		return( buff );
	}

	void CFSecSecGrpIncObj::setBuff( cfsec::CFSecSecGrpIncBuff* value ) {
		if( ( buff != NULL ) && ( buff != value ) ) {
			delete buff;
			buff = NULL;
		}
		buff = value;
		if( buff != NULL ) {
			copyBuffToPKey();
		}
	}

	const std::string& CFSecSecGrpIncObj::getClassName() const {
		return( CLASS_NAME );
	}

	const classcode_t CFSecSecGrpIncObj::getClassCode() const {
		return( CLASS_CODE );
	}

	bool CFSecSecGrpIncObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfsec::CFSecSecGrpIncBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFSecSecGrpIncObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecSecGrpIncObj" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_ClusterId( "ClusterId" );
		static const std::string S_SecGrpIncId( "SecGrpIncId" );
		static const std::string S_SecGroupId( "SecGroupId" );
		static const std::string S_IncludeGroupId( "IncludeGroupId" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFSecSecGrpIncObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFSecSecGrpIncObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFSecSecGrpIncObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFSecSecGrpIncObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFSecSecGrpIncObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_ClusterId, CFSecSecGrpIncObj::getRequiredClusterId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_SecGrpIncId, CFSecSecGrpIncObj::getRequiredSecGrpIncId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_SecGroupId, CFSecSecGrpIncObj::getRequiredSecGroupId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_IncludeGroupId, CFSecSecGrpIncObj::getRequiredIncludeGroupId() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	std::string CFSecSecGrpIncObj::getObjName() {
		std::string objName( CLASS_NAME );
		int64_t val = getRequiredSecGrpIncId();
		objName = cflib::CFLibXmlUtil::formatInt64( val );
		return( objName );
	}

	const std::string CFSecSecGrpIncObj::getGenDefName() {
		return( cfsec::CFSecSecGrpIncBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFSecSecGrpIncObj::getScope() {
		cfsec::ICFSecSecGroupObj* scope = getRequiredContainerGroup();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFSecSecGrpIncObj::getObjScope() {
		cfsec::ICFSecSecGroupObj* scope = getRequiredContainerGroup();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFSecSecGrpIncObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFSecSecGrpIncObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFSecSecGrpIncObj::getNamedObject( const std::string& objName ) {
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

	std::string CFSecSecGrpIncObj::getObjQualifiedName() {
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

	std::string CFSecSecGrpIncObj::getObjFullName() {
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

	cfsec::ICFSecSecGrpIncObj* CFSecSecGrpIncObj::realize() {
		cfsec::ICFSecSecGrpIncObj* retobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecGrpIncTableObj()->realizeSecGrpInc(
			(cfsec::ICFSecSecGrpIncObj*)this );
		return( dynamic_cast<cfsec::ICFSecSecGrpIncObj*>( retobj ) );
	}

	cfsec::ICFSecSecGrpIncObj* CFSecSecGrpIncObj::read( bool forceRead ) {
		cfsec::ICFSecSecGrpIncObj* retobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecGrpIncTableObj()->readSecGrpIncByIdIdx( getSecGrpIncBuff()->getRequiredClusterId(),
		getSecGrpIncBuff()->getRequiredSecGrpIncId(), forceRead );
		return( dynamic_cast<cfsec::ICFSecSecGrpIncObj*>( retobj ) );
	}

	cfsec::ICFSecSecGrpIncTableObj* CFSecSecGrpIncObj::getSecGrpIncTable() {
		return( dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecGrpIncTableObj() );
	}

	cfsec::ICFSecSchemaObj* CFSecSecGrpIncObj::getSchema() {
		return( schema );
	}

	void CFSecSecGrpIncObj::setSchema( cfsec::ICFSecSchemaObj* value ) {
		schema = value;
	}

	cfsec::CFSecSecGrpIncPKey* CFSecSecGrpIncObj::getPKey() {
		if( pKey == NULL ) {
			pKey = new cfsec::CFSecSecGrpIncPKey();
		}
		return( pKey );
	}

	void CFSecSecGrpIncObj::setPKey( cfsec::CFSecSecGrpIncPKey* value ) {
		if( ( pKey != NULL ) && ( pKey != value ) ) {
			delete pKey;
			pKey = NULL;
		}
		if( value != NULL ) {
			pKey = new cfsec::CFSecSecGrpIncPKey();
			*pKey = *value;
			copyPKeyToBuff();
		}
	}

	bool CFSecSecGrpIncObj::getIsNew() {
		return( isNew );
	}

	void CFSecSecGrpIncObj::setIsNew( bool value ) {
		isNew = value;
	}

	cfsec::ICFSecSecGrpIncEditObj* CFSecSecGrpIncObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_EditAlreadyOpen( "An edit is already open" );
		if( edit != NULL ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_ProcName, S_EditAlreadyOpen );
		}
		if( ! getIsNew() ) {
			cfsec::ICFSecSecGrpIncObj* lockobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecGrpIncTableObj()->lockSecGrpInc( getPKey() );
			lockobj->realize();
		}
		edit = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecGrpIncTableObj()->newEditInstance( this );
		return( dynamic_cast<cfsec::ICFSecSecGrpIncEditObj*>( edit ) );
	}

	void CFSecSecGrpIncObj::endEdit() {
		if( edit != NULL ) {
			delete edit;
			edit = NULL;
		}
	}

	cfsec::ICFSecSecGrpIncEditObj* CFSecSecGrpIncObj::getEdit() {
		return( edit );
	}

	cfsec::ICFSecSecGrpIncEditObj* CFSecSecGrpIncObj::getSecGrpIncEdit() {
		return( dynamic_cast<cfsec::ICFSecSecGrpIncEditObj*>( edit ) );
	}

	cfsec::ICFSecSecUserObj* CFSecSecGrpIncObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getSecGrpIncBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFSecSecGrpIncObj::getCreatedAt() {
		return( getSecGrpIncBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFSecSecGrpIncObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getSecGrpIncBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFSecSecGrpIncObj::getUpdatedAt() {
		return( getSecGrpIncBuff()->getUpdatedAt() );
	}

	void CFSecSecGrpIncObj::copyPKeyToBuff() {
		cfsec::CFSecSecGrpIncPKey* tablePKey = getPKey();
		cfsec::CFSecSecGrpIncBuff* tableBuff = getSecGrpIncEditBuff();
		if( tableBuff != NULL ) {
			tableBuff->setRequiredClusterId( tablePKey->getRequiredClusterId() );
			tableBuff->setRequiredSecGrpIncId( tablePKey->getRequiredSecGrpIncId() );
		}
		if( edit != NULL ) {
			edit->copyPKeyToBuff();
		}
	}

	void CFSecSecGrpIncObj::copyBuffToPKey() {
		cfsec::CFSecSecGrpIncPKey* tablePKey = getPKey();
		cfsec::CFSecSecGrpIncBuff* tableBuff = getSecGrpIncBuff();
		tablePKey->setRequiredClusterId( tableBuff->getRequiredClusterId() );
		tablePKey->setRequiredSecGrpIncId( tableBuff->getRequiredSecGrpIncId() );
	}

}
