// Description: C++18 edit object instance implementation for CFSec TSecGroup.

/*
 *	com.github.msobkow.CFSec
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	This file is part of MSS Code Factory.
 *	
 *	Licensed under the Apache License, Version 2.0 (the "License");
 *	you may not use this file except in compliance with the License.
 *	You may obtain a copy of the License at
 *	
 *	    http://www.apache.org/licenses/LICENSE-2.0
 *	
 *	Unless required by applicable law or agreed to in writing, software
 *	distributed under the License is distributed on an "AS IS" BASIS,
 *	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *	See the License for the specific language governing permissions and
 *	limitations under the License.
 *	
 *	Donations to support MSS Code Factory can be made at
 *	https://www.paypal.com/paypalme2/MarkSobkow
 *
 *	Manufactured by MSS Code Factory 2.12
 */

#include <cflib/ICFLibPublic.hpp>

using namespace std;

#include <cfsec/ICFSecPublic.hpp>
#include <cfsecobj/ICFSecObjPublic.hpp>
#include <cfsecobj/CFSecTSecGroupObj.hpp>
#include <cfsecobj/CFSecTSecGroupEditObj.hpp>


namespace cfsec {

	const std::string CFSecTSecGroupEditObj::CLASS_NAME( "CFSecTSecGroupEditObj" );

	CFSecTSecGroupEditObj::CFSecTSecGroupEditObj( cfsec::ICFSecTSecGroupObj* argOrig )
	: ICFSecTSecGroupEditObj()
	{
		static const std::string S_ProcName( "CFSecTSecGroupEditObj-construct" );
		static const std::string S_OrigBuff( "origBuff" );
		orig = argOrig;
		cfsec::CFSecTSecGroupBuff* origBuff = orig->getBuff();
		if( origBuff == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_OrigBuff );
		}
		buff = dynamic_cast<cfsec::CFSecTSecGroupBuff*>( origBuff->clone() );
	}

	CFSecTSecGroupEditObj::~CFSecTSecGroupEditObj() {
		orig = NULL;
		if( buff != NULL ) {
			delete buff;
			buff = NULL;
		}

	}

	const std::string& CFSecTSecGroupEditObj::getClassName() const {
		return( CLASS_NAME );
	}

	cfsec::ICFSecSecUserObj* CFSecTSecGroupEditObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<cfsec::ICFSecSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getTSecGroupBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFSecTSecGroupEditObj::getCreatedAt() {
		return( getTSecGroupBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFSecTSecGroupEditObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<cfsec::ICFSecSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getTSecGroupBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFSecTSecGroupEditObj::getUpdatedAt() {
		return( getTSecGroupBuff()->getUpdatedAt() );
	}

	void CFSecTSecGroupEditObj::setCreatedBy( cfsec::ICFSecSecUserObj* value ) {
		createdBy = value;
		if( value != NULL ) {
			getTSecGroupEditBuff()->setCreatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFSecTSecGroupEditObj::setCreatedAt( const std::chrono::system_clock::time_point& value ) {
		getTSecGroupEditBuff()->setCreatedAt( value );
	}

	void CFSecTSecGroupEditObj::setUpdatedBy( cfsec::ICFSecSecUserObj* value ) {
		updatedBy = value;
		if( value != NULL ) {
			getTSecGroupEditBuff()->setUpdatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFSecTSecGroupEditObj::setUpdatedAt( const std::chrono::system_clock::time_point& value ) {
		getTSecGroupEditBuff()->setUpdatedAt( value );
	}

	const classcode_t CFSecTSecGroupEditObj::getClassCode() const {
		return( cfsec::CFSecTSecGroupBuff::CLASS_CODE );
	}

	bool CFSecTSecGroupEditObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfsec::CFSecTSecGroupBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFSecTSecGroupEditObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecTSecGroupEditObj" );
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
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFSecTSecGroupEditObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFSecTSecGroupEditObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFSecTSecGroupEditObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFSecTSecGroupEditObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFSecTSecGroupEditObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_TenantId, CFSecTSecGroupEditObj::getRequiredTenantId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_TSecGroupId, CFSecTSecGroupEditObj::getRequiredTSecGroupId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Name, CFSecTSecGroupEditObj::getRequiredName() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredBoolean( &S_Space, S_IsVisible, CFSecTSecGroupEditObj::getRequiredIsVisible() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	int32_t CFSecTSecGroupEditObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	void CFSecTSecGroupEditObj::setRequiredRevision( int32_t value ) {
		getTSecGroupEditBuff()->setRequiredRevision( value );
	}

	std::string CFSecTSecGroupEditObj::getObjName() {
		std::string objName( CLASS_NAME ); objName;
		objName.clear();
		objName.append( getRequiredName() );
		return( objName );
	}

	const std::string CFSecTSecGroupEditObj::getGenDefName() {
		return( cfsec::CFSecTSecGroupBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFSecTSecGroupEditObj::getScope() {
		cfsec::ICFSecTenantObj* scope = getRequiredContainerTenant();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFSecTSecGroupEditObj::getObjScope() {
		cfsec::ICFSecTenantObj* scope = getRequiredContainerTenant();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFSecTSecGroupEditObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFSecTSecGroupEditObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFSecTSecGroupEditObj::getNamedObject( const std::string& objName ) {
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

	std::string CFSecTSecGroupEditObj::getObjQualifiedName() {
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

	std::string CFSecTSecGroupEditObj::getObjFullName() {
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

	cfsec::ICFSecTSecGroupObj* CFSecTSecGroupEditObj::realize() {
		// We realize this so that it's buffer will get copied to orig during realization
		cfsec::ICFSecTSecGroupObj* retobj = getSchema()->getTSecGroupTableObj()->realizeTSecGroup( dynamic_cast<cfsec::ICFSecTSecGroupObj*>( this ) );
		return( retobj );
	}

	cfsec::ICFSecTSecGroupObj* CFSecTSecGroupEditObj::read( bool forceRead ) {
		cfsec::ICFSecTSecGroupObj* retval = getOrigAsTSecGroup()->read( forceRead );
		if( retval != orig ) {
			throw cflib::CFLibUsageException( CLASS_NAME,
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	cfsec::ICFSecTSecGroupObj* CFSecTSecGroupEditObj::create() {
		cfsec::ICFSecTSecGroupObj* retobj = dynamic_cast<cfsec::ICFSecSchemaObj*>( getOrigAsTSecGroup()->getSchema() )->getTSecGroupTableObj()->createTSecGroup( this );
		// Note that this instance is usually discarded during the creation process,
		// and retobj now references the cached instance of the created object.
		return( retobj );
	}

	cfsec::ICFSecTSecGroupEditObj* CFSecTSecGroupEditObj::update() {
		getSchema()->getTSecGroupTableObj()->updateTSecGroup( this );
		return( NULL );
	}

	cfsec::ICFSecTSecGroupEditObj* CFSecTSecGroupEditObj::deleteInstance() {
		static const std::string S_MethodName( "deleteInstance" );
		static const std::string S_CannotDeleteNewInstance( "Cannot delete a new instance" );
		if( getIsNew() ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_MethodName, S_CannotDeleteNewInstance );
		}
		getSchema()->getTSecGroupTableObj()->deleteTSecGroup( this );
		return( NULL );
	}

	cfsec::ICFSecTSecGroupTableObj* CFSecTSecGroupEditObj::getTSecGroupTable() {
		return( orig->getSchema()->getTSecGroupTableObj() );
	}

	cfsec::ICFSecTSecGroupEditObj* CFSecTSecGroupEditObj::getEdit() {
		return( this );
	}

	cfsec::ICFSecTSecGroupEditObj* CFSecTSecGroupEditObj::getTSecGroupEdit() {
		return( (cfsec::ICFSecTSecGroupEditObj*)this );
	}

	cfsec::ICFSecTSecGroupEditObj* CFSecTSecGroupEditObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_Message( "Cannot edit an edition" );
		throw cflib::CFLibUsageException( CLASS_NAME,
			S_ProcName,
			S_Message );
	}

	void CFSecTSecGroupEditObj::endEdit() {
		orig->endEdit();
	}

	cfsec::ICFSecTSecGroupObj* CFSecTSecGroupEditObj::getOrig() {
		return( orig );
	}

	cfsec::ICFSecTSecGroupObj* CFSecTSecGroupEditObj::getOrigAsTSecGroup() {
		return( dynamic_cast<cfsec::ICFSecTSecGroupObj*>( orig ) );
	}

	cfsec::ICFSecSchemaObj* CFSecTSecGroupEditObj::getSchema() {
		return( orig->getSchema() );
	}

	cfsec::CFSecTSecGroupBuff* CFSecTSecGroupEditObj::getBuff() {
		return( buff );
	}

	void CFSecTSecGroupEditObj::setBuff( cfsec::CFSecTSecGroupBuff* value ) {
		if( buff != value ) {
			if( ( buff != NULL ) && ( buff != value ) ) {
				delete buff;
				buff = NULL;
			}
			buff = value;
		}
	}

	cfsec::CFSecTSecGroupPKey* CFSecTSecGroupEditObj::getPKey() {
		return( orig->getPKey() );
	}

	void CFSecTSecGroupEditObj::setPKey( cfsec::CFSecTSecGroupPKey* value ) {
		if( orig->getPKey() != value ) {
			orig->setPKey( value );
		}
		copyPKeyToBuff();
	}

	bool CFSecTSecGroupEditObj::getIsNew() {
		return( orig->getIsNew() );
	}

	void CFSecTSecGroupEditObj::setIsNew( bool value ) {
		orig->setIsNew( value );
	}

	const int64_t CFSecTSecGroupEditObj::getRequiredTenantId() {
		return( getPKey()->getRequiredTenantId() );
	}

	const int64_t* CFSecTSecGroupEditObj::getRequiredTenantIdReference() {
		return( getPKey()->getRequiredTenantIdReference() );
	}

	const int32_t CFSecTSecGroupEditObj::getRequiredTSecGroupId() {
		return( getPKey()->getRequiredTSecGroupId() );
	}

	const int32_t* CFSecTSecGroupEditObj::getRequiredTSecGroupIdReference() {
		return( getPKey()->getRequiredTSecGroupIdReference() );
	}

	const std::string& CFSecTSecGroupEditObj::getRequiredName() {
		return( getTSecGroupBuff()->getRequiredName() );
	}

	const std::string* CFSecTSecGroupEditObj::getRequiredNameReference() {
		return( getTSecGroupBuff()->getRequiredNameReference() );
	}

	void CFSecTSecGroupEditObj::setRequiredName( const std::string& value ) {
		if( getTSecGroupBuff()->getRequiredName() != value ) {
			getTSecGroupEditBuff()->setRequiredName( value );
		}
	}

	const bool CFSecTSecGroupEditObj::getRequiredIsVisible() {
		return( getTSecGroupBuff()->getRequiredIsVisible() );
	}

	const bool* CFSecTSecGroupEditObj::getRequiredIsVisibleReference() {
		return( getTSecGroupBuff()->getRequiredIsVisibleReference() );
	}

	void CFSecTSecGroupEditObj::setRequiredIsVisible( const bool value ) {
		if( getTSecGroupBuff()->getRequiredIsVisible() != value ) {
			getTSecGroupEditBuff()->setRequiredIsVisible( value );
		}
	}

	cfsec::ICFSecTenantObj* CFSecTSecGroupEditObj::getRequiredContainerTenant( bool forceRead ) {
		cfsec::ICFSecTenantObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<cfsec::ICFSecSchemaObj*>( getOrigAsTSecGroup()->getSchema() )->getTenantTableObj()->readTenantByIdIdx( getPKey()->getRequiredTenantId() );
		}
		return( retobj );
	}

	void CFSecTSecGroupEditObj::setRequiredContainerTenant( cfsec::ICFSecTenantObj* value ) {
			
			if( value != NULL ) {
				getPKey()->setRequiredTenantId
( value->getRequiredId() );
				getTSecGroupEditBuff()->setRequiredTenantId( value->getRequiredId() );
			}
		}

	std::vector<cfsec::ICFSecTSecGrpIncObj*> CFSecTSecGroupEditObj::getOptionalComponentsInclude( bool forceRead ) {
		std::vector<cfsec::ICFSecTSecGrpIncObj*> retval;
		retval = dynamic_cast<cfsec::ICFSecSchemaObj*>( getOrigAsTSecGroup()->getSchema() )->getTSecGrpIncTableObj()->readTSecGrpIncByGroupIdx( getPKey()->getRequiredTenantId(),
					getPKey()->getRequiredTSecGroupId(),
			forceRead );
		return( retval );
	}

	std::vector<cfsec::ICFSecTSecGrpMembObj*> CFSecTSecGroupEditObj::getOptionalComponentsMember( bool forceRead ) {
		std::vector<cfsec::ICFSecTSecGrpMembObj*> retval;
		retval = dynamic_cast<cfsec::ICFSecSchemaObj*>( getOrigAsTSecGroup()->getSchema() )->getTSecGrpMembTableObj()->readTSecGrpMembByGroupIdx( getPKey()->getRequiredTenantId(),
					getPKey()->getRequiredTSecGroupId(),
			forceRead );
		return( retval );
	}

	std::vector<cfsec::ICFSecTSecGrpIncObj*> CFSecTSecGroupEditObj::getRequiredChildrenIncByGroup( bool forceRead ) {
		std::vector<cfsec::ICFSecTSecGrpIncObj*> retval;
		retval = dynamic_cast<cfsec::ICFSecSchemaObj*>( getOrigAsTSecGroup()->getSchema() )->getTSecGrpIncTableObj()->readTSecGrpIncByIncludeIdx( getPKey()->getRequiredTenantId(),
					getPKey()->getRequiredTSecGroupId(),
			forceRead );
		return( retval );
	}

	void CFSecTSecGroupEditObj::copyPKeyToBuff() {
		cfsec::CFSecTSecGroupPKey* tablePKey = getPKey();
		cfsec::CFSecTSecGroupBuff* tableBuff = getTSecGroupEditBuff();
		tableBuff->setRequiredTenantId( tablePKey->getRequiredTenantId() );
		tableBuff->setRequiredTSecGroupId( tablePKey->getRequiredTSecGroupId() );
	}

	void CFSecTSecGroupEditObj::copyBuffToPKey() {
		cfsec::CFSecTSecGroupPKey* tablePKey = getPKey();
		cfsec::CFSecTSecGroupBuff* tableBuff = getTSecGroupBuff();
		tablePKey->setRequiredTenantId( tableBuff->getRequiredTenantId() );
		tablePKey->setRequiredTSecGroupId( tableBuff->getRequiredTSecGroupId() );
	}

	void CFSecTSecGroupEditObj::copyBuffToOrig() {
		cfsec::CFSecTSecGroupBuff* origBuff = getOrigAsTSecGroup()->getTSecGroupEditBuff();
		cfsec::CFSecTSecGroupBuff* myBuff = getTSecGroupBuff();
		if( origBuff != myBuff ) {
			*origBuff = *myBuff;
		}
	}

	void CFSecTSecGroupEditObj::copyOrigToBuff() {
		cfsec::CFSecTSecGroupBuff* origBuff = getOrigAsTSecGroup()->getTSecGroupBuff();
		cfsec::CFSecTSecGroupBuff* myBuff = getTSecGroupEditBuff();
		if( origBuff != myBuff ) {
			*myBuff = *origBuff;
		}
	}

}
