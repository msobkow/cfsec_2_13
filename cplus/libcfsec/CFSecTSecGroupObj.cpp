// Description: C++18 base object instance implementation for CFSec TSecGroup.

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
#include <cfsecobj/CFSecTSecGroupObj.hpp>

namespace cfsec {

	const std::string CFSecTSecGroupObj::CLASS_NAME( "CFSecTSecGroupObj" );
	const classcode_t CFSecTSecGroupObj::CLASS_CODE = 0xa016L;

	int32_t CFSecTSecGroupObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	const int64_t CFSecTSecGroupObj::getRequiredTenantId() {
		return( getPKey()->getRequiredTenantId() );
	}

	const int64_t* CFSecTSecGroupObj::getRequiredTenantIdReference() {
		return( getPKey()->getRequiredTenantIdReference() );
	}

	const int32_t CFSecTSecGroupObj::getRequiredTSecGroupId() {
		return( getPKey()->getRequiredTSecGroupId() );
	}

	const int32_t* CFSecTSecGroupObj::getRequiredTSecGroupIdReference() {
		return( getPKey()->getRequiredTSecGroupIdReference() );
	}

	const std::string& CFSecTSecGroupObj::getRequiredName() {
		return( getTSecGroupBuff()->getRequiredName() );
	}

	const std::string* CFSecTSecGroupObj::getRequiredNameReference() {
		return( getTSecGroupBuff()->getRequiredNameReference() );
	}

	const bool CFSecTSecGroupObj::getRequiredIsVisible() {
		return( getTSecGroupBuff()->getRequiredIsVisible() );
	}

	const bool* CFSecTSecGroupObj::getRequiredIsVisibleReference() {
		return( getTSecGroupBuff()->getRequiredIsVisibleReference() );
	}


	cfsec::ICFSecTenantObj* CFSecTSecGroupObj::getRequiredContainerTenant( bool forceRead ) {
		cfsec::ICFSecTenantObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getTenantTableObj()->readTenantByIdIdx( getPKey()->getRequiredTenantId(), forceRead );
		}
		return( retobj );
	}

	std::vector<cfsec::ICFSecTSecGrpIncObj*> CFSecTSecGroupObj::getOptionalComponentsInclude( bool forceRead ) {
		std::vector<cfsec::ICFSecTSecGrpIncObj*> retval;
		retval = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getTSecGrpIncTableObj()->readTSecGrpIncByGroupIdx( getPKey()->getRequiredTenantId(),
					getPKey()->getRequiredTSecGroupId(),
			forceRead );
		return( retval );
	}

	std::vector<cfsec::ICFSecTSecGrpMembObj*> CFSecTSecGroupObj::getOptionalComponentsMember( bool forceRead ) {
		std::vector<cfsec::ICFSecTSecGrpMembObj*> retval;
		retval = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getTSecGrpMembTableObj()->readTSecGrpMembByGroupIdx( getPKey()->getRequiredTenantId(),
					getPKey()->getRequiredTSecGroupId(),
			forceRead );
		return( retval );
	}

	std::vector<cfsec::ICFSecTSecGrpIncObj*> CFSecTSecGroupObj::getRequiredChildrenIncByGroup( bool forceRead ) {
		std::vector<cfsec::ICFSecTSecGrpIncObj*> retval;
		retval = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getTSecGrpIncTableObj()->readTSecGrpIncByIncludeIdx( getPKey()->getRequiredTenantId(),
					getPKey()->getRequiredTSecGroupId(),
			forceRead );
		return( retval );
	}

	CFSecTSecGroupObj::CFSecTSecGroupObj()
	: ICFSecTSecGroupObj()
	{
		schema = NULL;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFSecTSecGroupObj::CFSecTSecGroupObj( cfsec::ICFSecSchemaObj* argSchema )
	: ICFSecTSecGroupObj()
	{
		schema = argSchema;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFSecTSecGroupObj::~CFSecTSecGroupObj() {
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

	cfsec::CFSecTSecGroupBuff* CFSecTSecGroupObj::getBuff() {
		if( buff == NULL ) {
			if( isNew ) {
				buff = new cfsec::CFSecTSecGroupBuff();
				copyBuffToPKey();
			}
			else {
				// Read the data buff via the backing store
				buff = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableTSecGroup()->readDerivedByIdIdx( dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getAuthorization(),
						getPKey()->getRequiredTenantId(),
						getPKey()->getRequiredTSecGroupId() );
			}
		}
		return( buff );
	}

	void CFSecTSecGroupObj::setBuff( cfsec::CFSecTSecGroupBuff* value ) {
		if( ( buff != NULL ) && ( buff != value ) ) {
			delete buff;
			buff = NULL;
		}
		buff = value;
		if( buff != NULL ) {
			copyBuffToPKey();
		}
	}

	const std::string& CFSecTSecGroupObj::getClassName() const {
		return( CLASS_NAME );
	}

	const classcode_t CFSecTSecGroupObj::getClassCode() const {
		return( CLASS_CODE );
	}

	bool CFSecTSecGroupObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfsec::CFSecTSecGroupBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFSecTSecGroupObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecTSecGroupObj" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_TenantId( "TenantId" );
		static const std::string S_TSecGroupId( "TSecGroupId" );
		static const std::string S_Name( "Name" );
		static const std::string S_IsVisible( "IsVisible" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFSecTSecGroupObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFSecTSecGroupObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFSecTSecGroupObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFSecTSecGroupObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFSecTSecGroupObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_TenantId, CFSecTSecGroupObj::getRequiredTenantId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_TSecGroupId, CFSecTSecGroupObj::getRequiredTSecGroupId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Name, CFSecTSecGroupObj::getRequiredName() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredBoolean( &S_Space, S_IsVisible, CFSecTSecGroupObj::getRequiredIsVisible() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	std::string CFSecTSecGroupObj::getObjName() {
		std::string objName( CLASS_NAME );
		objName.clear();
		objName.append( getRequiredName() );
		return( objName );
	}

	const std::string CFSecTSecGroupObj::getGenDefName() {
		return( cfsec::CFSecTSecGroupBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFSecTSecGroupObj::getScope() {
		cfsec::ICFSecTenantObj* scope = getRequiredContainerTenant();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFSecTSecGroupObj::getObjScope() {
		cfsec::ICFSecTenantObj* scope = getRequiredContainerTenant();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFSecTSecGroupObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFSecTSecGroupObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFSecTSecGroupObj::getNamedObject( const std::string& objName ) {
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

	std::string CFSecTSecGroupObj::getObjQualifiedName() {
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

	std::string CFSecTSecGroupObj::getObjFullName() {
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

	cfsec::ICFSecTSecGroupObj* CFSecTSecGroupObj::realize() {
		cfsec::ICFSecTSecGroupObj* retobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getTSecGroupTableObj()->realizeTSecGroup(
			(cfsec::ICFSecTSecGroupObj*)this );
		return( dynamic_cast<cfsec::ICFSecTSecGroupObj*>( retobj ) );
	}

	cfsec::ICFSecTSecGroupObj* CFSecTSecGroupObj::read( bool forceRead ) {
		cfsec::ICFSecTSecGroupObj* retobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getTSecGroupTableObj()->readTSecGroupByIdIdx( getTSecGroupBuff()->getRequiredTenantId(),
		getTSecGroupBuff()->getRequiredTSecGroupId(), forceRead );
		return( dynamic_cast<cfsec::ICFSecTSecGroupObj*>( retobj ) );
	}

	cfsec::ICFSecTSecGroupTableObj* CFSecTSecGroupObj::getTSecGroupTable() {
		return( dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getTSecGroupTableObj() );
	}

	cfsec::ICFSecSchemaObj* CFSecTSecGroupObj::getSchema() {
		return( schema );
	}

	void CFSecTSecGroupObj::setSchema( cfsec::ICFSecSchemaObj* value ) {
		schema = value;
	}

	cfsec::CFSecTSecGroupPKey* CFSecTSecGroupObj::getPKey() {
		if( pKey == NULL ) {
			pKey = new cfsec::CFSecTSecGroupPKey();
		}
		return( pKey );
	}

	void CFSecTSecGroupObj::setPKey( cfsec::CFSecTSecGroupPKey* value ) {
		if( ( pKey != NULL ) && ( pKey != value ) ) {
			delete pKey;
			pKey = NULL;
		}
		if( value != NULL ) {
			pKey = new cfsec::CFSecTSecGroupPKey();
			*pKey = *value;
			copyPKeyToBuff();
		}
	}

	bool CFSecTSecGroupObj::getIsNew() {
		return( isNew );
	}

	void CFSecTSecGroupObj::setIsNew( bool value ) {
		isNew = value;
	}

	cfsec::ICFSecTSecGroupEditObj* CFSecTSecGroupObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_EditAlreadyOpen( "An edit is already open" );
		if( edit != NULL ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_ProcName, S_EditAlreadyOpen );
		}
		if( ! getIsNew() ) {
			cfsec::ICFSecTSecGroupObj* lockobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getTSecGroupTableObj()->lockTSecGroup( getPKey() );
			lockobj->realize();
		}
		edit = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getTSecGroupTableObj()->newEditInstance( this );
		return( dynamic_cast<cfsec::ICFSecTSecGroupEditObj*>( edit ) );
	}

	void CFSecTSecGroupObj::endEdit() {
		if( edit != NULL ) {
			delete edit;
			edit = NULL;
		}
	}

	cfsec::ICFSecTSecGroupEditObj* CFSecTSecGroupObj::getEdit() {
		return( edit );
	}

	cfsec::ICFSecTSecGroupEditObj* CFSecTSecGroupObj::getTSecGroupEdit() {
		return( dynamic_cast<cfsec::ICFSecTSecGroupEditObj*>( edit ) );
	}

	cfsec::ICFSecSecUserObj* CFSecTSecGroupObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getTSecGroupBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFSecTSecGroupObj::getCreatedAt() {
		return( getTSecGroupBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFSecTSecGroupObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getTSecGroupBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFSecTSecGroupObj::getUpdatedAt() {
		return( getTSecGroupBuff()->getUpdatedAt() );
	}

	void CFSecTSecGroupObj::copyPKeyToBuff() {
		cfsec::CFSecTSecGroupPKey* tablePKey = getPKey();
		cfsec::CFSecTSecGroupBuff* tableBuff = getTSecGroupEditBuff();
		if( tableBuff != NULL ) {
			tableBuff->setRequiredTenantId( tablePKey->getRequiredTenantId() );
			tableBuff->setRequiredTSecGroupId( tablePKey->getRequiredTSecGroupId() );
		}
		if( edit != NULL ) {
			edit->copyPKeyToBuff();
		}
	}

	void CFSecTSecGroupObj::copyBuffToPKey() {
		cfsec::CFSecTSecGroupPKey* tablePKey = getPKey();
		cfsec::CFSecTSecGroupBuff* tableBuff = getTSecGroupBuff();
		tablePKey->setRequiredTenantId( tableBuff->getRequiredTenantId() );
		tablePKey->setRequiredTSecGroupId( tableBuff->getRequiredTSecGroupId() );
	}

}
