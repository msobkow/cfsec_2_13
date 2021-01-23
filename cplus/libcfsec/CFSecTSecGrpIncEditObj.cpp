// Description: C++18 edit object instance implementation for CFSec TSecGrpInc.

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
#include <cfsecobj/CFSecTSecGrpIncObj.hpp>
#include <cfsecobj/CFSecTSecGrpIncEditObj.hpp>


namespace cfsec {

	const std::string CFSecTSecGrpIncEditObj::CLASS_NAME( "CFSecTSecGrpIncEditObj" );

	CFSecTSecGrpIncEditObj::CFSecTSecGrpIncEditObj( cfsec::ICFSecTSecGrpIncObj* argOrig )
	: ICFSecTSecGrpIncEditObj()
	{
		static const std::string S_ProcName( "CFSecTSecGrpIncEditObj-construct" );
		static const std::string S_OrigBuff( "origBuff" );
		orig = argOrig;
		cfsec::CFSecTSecGrpIncBuff* origBuff = orig->getBuff();
		if( origBuff == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_OrigBuff );
		}
		buff = dynamic_cast<cfsec::CFSecTSecGrpIncBuff*>( origBuff->clone() );
	}

	CFSecTSecGrpIncEditObj::~CFSecTSecGrpIncEditObj() {
		orig = NULL;
		if( buff != NULL ) {
			delete buff;
			buff = NULL;
		}

	}

	const std::string& CFSecTSecGrpIncEditObj::getClassName() const {
		return( CLASS_NAME );
	}

	cfsec::ICFSecSecUserObj* CFSecTSecGrpIncEditObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<cfsec::ICFSecSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getTSecGrpIncBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFSecTSecGrpIncEditObj::getCreatedAt() {
		return( getTSecGrpIncBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFSecTSecGrpIncEditObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<cfsec::ICFSecSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getTSecGrpIncBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFSecTSecGrpIncEditObj::getUpdatedAt() {
		return( getTSecGrpIncBuff()->getUpdatedAt() );
	}

	void CFSecTSecGrpIncEditObj::setCreatedBy( cfsec::ICFSecSecUserObj* value ) {
		createdBy = value;
		if( value != NULL ) {
			getTSecGrpIncEditBuff()->setCreatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFSecTSecGrpIncEditObj::setCreatedAt( const std::chrono::system_clock::time_point& value ) {
		getTSecGrpIncEditBuff()->setCreatedAt( value );
	}

	void CFSecTSecGrpIncEditObj::setUpdatedBy( cfsec::ICFSecSecUserObj* value ) {
		updatedBy = value;
		if( value != NULL ) {
			getTSecGrpIncEditBuff()->setUpdatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFSecTSecGrpIncEditObj::setUpdatedAt( const std::chrono::system_clock::time_point& value ) {
		getTSecGrpIncEditBuff()->setUpdatedAt( value );
	}

	const classcode_t CFSecTSecGrpIncEditObj::getClassCode() const {
		return( cfsec::CFSecTSecGrpIncBuff::CLASS_CODE );
	}

	bool CFSecTSecGrpIncEditObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfsec::CFSecTSecGrpIncBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFSecTSecGrpIncEditObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecTSecGrpIncEditObj" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_TenantId( "TenantId" );
		static const std::string S_TSecGrpIncId( "TSecGrpIncId" );
		static const std::string S_TSecGroupId( "TSecGroupId" );
		static const std::string S_IncludeGroupId( "IncludeGroupId" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFSecTSecGrpIncEditObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFSecTSecGrpIncEditObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFSecTSecGrpIncEditObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFSecTSecGrpIncEditObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFSecTSecGrpIncEditObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_TenantId, CFSecTSecGrpIncEditObj::getRequiredTenantId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_TSecGrpIncId, CFSecTSecGrpIncEditObj::getRequiredTSecGrpIncId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_TSecGroupId, CFSecTSecGrpIncEditObj::getRequiredTSecGroupId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_IncludeGroupId, CFSecTSecGrpIncEditObj::getRequiredIncludeGroupId() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	int32_t CFSecTSecGrpIncEditObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	void CFSecTSecGrpIncEditObj::setRequiredRevision( int32_t value ) {
		getTSecGrpIncEditBuff()->setRequiredRevision( value );
	}

	std::string CFSecTSecGrpIncEditObj::getObjName() {
		std::string objName( CLASS_NAME ); objName;
		int64_t val = getRequiredTSecGrpIncId();
		objName = cflib::CFLibXmlUtil::formatInt64( val );
		return( objName );
	}

	const std::string CFSecTSecGrpIncEditObj::getGenDefName() {
		return( cfsec::CFSecTSecGrpIncBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFSecTSecGrpIncEditObj::getScope() {
		cfsec::ICFSecTSecGroupObj* scope = getRequiredContainerGroup();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFSecTSecGrpIncEditObj::getObjScope() {
		cfsec::ICFSecTSecGroupObj* scope = getRequiredContainerGroup();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFSecTSecGrpIncEditObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFSecTSecGrpIncEditObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFSecTSecGrpIncEditObj::getNamedObject( const std::string& objName ) {
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

	std::string CFSecTSecGrpIncEditObj::getObjQualifiedName() {
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

	std::string CFSecTSecGrpIncEditObj::getObjFullName() {
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

	cfsec::ICFSecTSecGrpIncObj* CFSecTSecGrpIncEditObj::realize() {
		// We realize this so that it's buffer will get copied to orig during realization
		cfsec::ICFSecTSecGrpIncObj* retobj = getSchema()->getTSecGrpIncTableObj()->realizeTSecGrpInc( dynamic_cast<cfsec::ICFSecTSecGrpIncObj*>( this ) );
		return( retobj );
	}

	cfsec::ICFSecTSecGrpIncObj* CFSecTSecGrpIncEditObj::read( bool forceRead ) {
		cfsec::ICFSecTSecGrpIncObj* retval = getOrigAsTSecGrpInc()->read( forceRead );
		if( retval != orig ) {
			throw cflib::CFLibUsageException( CLASS_NAME,
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	cfsec::ICFSecTSecGrpIncObj* CFSecTSecGrpIncEditObj::create() {
		cfsec::ICFSecTSecGrpIncObj* retobj = dynamic_cast<cfsec::ICFSecSchemaObj*>( getOrigAsTSecGrpInc()->getSchema() )->getTSecGrpIncTableObj()->createTSecGrpInc( this );
		// Note that this instance is usually discarded during the creation process,
		// and retobj now references the cached instance of the created object.
		return( retobj );
	}

	cfsec::ICFSecTSecGrpIncEditObj* CFSecTSecGrpIncEditObj::update() {
		getSchema()->getTSecGrpIncTableObj()->updateTSecGrpInc( this );
		return( NULL );
	}

	cfsec::ICFSecTSecGrpIncEditObj* CFSecTSecGrpIncEditObj::deleteInstance() {
		static const std::string S_MethodName( "deleteInstance" );
		static const std::string S_CannotDeleteNewInstance( "Cannot delete a new instance" );
		if( getIsNew() ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_MethodName, S_CannotDeleteNewInstance );
		}
		getSchema()->getTSecGrpIncTableObj()->deleteTSecGrpInc( this );
		return( NULL );
	}

	cfsec::ICFSecTSecGrpIncTableObj* CFSecTSecGrpIncEditObj::getTSecGrpIncTable() {
		return( orig->getSchema()->getTSecGrpIncTableObj() );
	}

	cfsec::ICFSecTSecGrpIncEditObj* CFSecTSecGrpIncEditObj::getEdit() {
		return( this );
	}

	cfsec::ICFSecTSecGrpIncEditObj* CFSecTSecGrpIncEditObj::getTSecGrpIncEdit() {
		return( (cfsec::ICFSecTSecGrpIncEditObj*)this );
	}

	cfsec::ICFSecTSecGrpIncEditObj* CFSecTSecGrpIncEditObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_Message( "Cannot edit an edition" );
		throw cflib::CFLibUsageException( CLASS_NAME,
			S_ProcName,
			S_Message );
	}

	void CFSecTSecGrpIncEditObj::endEdit() {
		orig->endEdit();
	}

	cfsec::ICFSecTSecGrpIncObj* CFSecTSecGrpIncEditObj::getOrig() {
		return( orig );
	}

	cfsec::ICFSecTSecGrpIncObj* CFSecTSecGrpIncEditObj::getOrigAsTSecGrpInc() {
		return( dynamic_cast<cfsec::ICFSecTSecGrpIncObj*>( orig ) );
	}

	cfsec::ICFSecSchemaObj* CFSecTSecGrpIncEditObj::getSchema() {
		return( orig->getSchema() );
	}

	cfsec::CFSecTSecGrpIncBuff* CFSecTSecGrpIncEditObj::getBuff() {
		return( buff );
	}

	void CFSecTSecGrpIncEditObj::setBuff( cfsec::CFSecTSecGrpIncBuff* value ) {
		if( buff != value ) {
			if( ( buff != NULL ) && ( buff != value ) ) {
				delete buff;
				buff = NULL;
			}
			buff = value;
		}
	}

	cfsec::CFSecTSecGrpIncPKey* CFSecTSecGrpIncEditObj::getPKey() {
		return( orig->getPKey() );
	}

	void CFSecTSecGrpIncEditObj::setPKey( cfsec::CFSecTSecGrpIncPKey* value ) {
		if( orig->getPKey() != value ) {
			orig->setPKey( value );
		}
		copyPKeyToBuff();
	}

	bool CFSecTSecGrpIncEditObj::getIsNew() {
		return( orig->getIsNew() );
	}

	void CFSecTSecGrpIncEditObj::setIsNew( bool value ) {
		orig->setIsNew( value );
	}

	const int64_t CFSecTSecGrpIncEditObj::getRequiredTenantId() {
		return( getPKey()->getRequiredTenantId() );
	}

	const int64_t* CFSecTSecGrpIncEditObj::getRequiredTenantIdReference() {
		return( getPKey()->getRequiredTenantIdReference() );
	}

	const int64_t CFSecTSecGrpIncEditObj::getRequiredTSecGrpIncId() {
		return( getPKey()->getRequiredTSecGrpIncId() );
	}

	const int64_t* CFSecTSecGrpIncEditObj::getRequiredTSecGrpIncIdReference() {
		return( getPKey()->getRequiredTSecGrpIncIdReference() );
	}

	const int32_t CFSecTSecGrpIncEditObj::getRequiredTSecGroupId() {
		return( getTSecGrpIncBuff()->getRequiredTSecGroupId() );
	}

	const int32_t* CFSecTSecGrpIncEditObj::getRequiredTSecGroupIdReference() {
		return( getTSecGrpIncBuff()->getRequiredTSecGroupIdReference() );
	}

	const int32_t CFSecTSecGrpIncEditObj::getRequiredIncludeGroupId() {
		return( getTSecGrpIncBuff()->getRequiredIncludeGroupId() );
	}

	const int32_t* CFSecTSecGrpIncEditObj::getRequiredIncludeGroupIdReference() {
		return( getTSecGrpIncBuff()->getRequiredIncludeGroupIdReference() );
	}

	cfsec::ICFSecTenantObj* CFSecTSecGrpIncEditObj::getRequiredOwnerTenant( bool forceRead ) {
		cfsec::ICFSecTenantObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<cfsec::ICFSecSchemaObj*>( getOrigAsTSecGrpInc()->getSchema() )->getTenantTableObj()->readTenantByIdIdx( getPKey()->getRequiredTenantId() );
		}
		return( retobj );
	}

	void CFSecTSecGrpIncEditObj::setRequiredOwnerTenant( cfsec::ICFSecTenantObj* value ) {
			
			if( value != NULL ) {
				getPKey()->setRequiredTenantId
( value->getRequiredId() );
				getTSecGrpIncEditBuff()->setRequiredTenantId( value->getRequiredId() );
			}
		}

	cfsec::ICFSecTSecGroupObj* CFSecTSecGrpIncEditObj::getRequiredContainerGroup( bool forceRead ) {
		cfsec::ICFSecTSecGroupObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<cfsec::ICFSecSchemaObj*>( getOrigAsTSecGrpInc()->getSchema() )->getTSecGroupTableObj()->readTSecGroupByIdIdx( getPKey()->getRequiredTenantId(),
					getTSecGrpIncBuff()->getRequiredTSecGroupId() );
		}
		return( retobj );
	}

	void CFSecTSecGrpIncEditObj::setRequiredContainerGroup( cfsec::ICFSecTSecGroupObj* value ) {
			
			if( value != NULL ) {
				getPKey()->setRequiredTenantId
( value->getRequiredTenantId() );
				getTSecGrpIncEditBuff()->setRequiredTenantId( value->getRequiredTenantId() );
				getTSecGrpIncEditBuff()->setRequiredTSecGroupId( value->getRequiredTSecGroupId() );
			}
		}

	cfsec::ICFSecTSecGroupObj* CFSecTSecGrpIncEditObj::getRequiredParentSubGroup( bool forceRead ) {
		cfsec::ICFSecTSecGroupObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<cfsec::ICFSecSchemaObj*>( getOrigAsTSecGrpInc()->getSchema() )->getTSecGroupTableObj()->readTSecGroupByIdIdx( getPKey()->getRequiredTenantId(),
					getTSecGrpIncBuff()->getRequiredIncludeGroupId() );
		}
		return( retobj );
	}

	void CFSecTSecGrpIncEditObj::setRequiredParentSubGroup( cfsec::ICFSecTSecGroupObj* value ) {
			
			if( value != NULL ) {
				getPKey()->setRequiredTenantId
( value->getRequiredTenantId() );
				getTSecGrpIncEditBuff()->setRequiredTenantId( value->getRequiredTenantId() );
				getTSecGrpIncEditBuff()->setRequiredIncludeGroupId( value->getRequiredTSecGroupId() );
			}
			else {
			}
		}

	void CFSecTSecGrpIncEditObj::copyPKeyToBuff() {
		cfsec::CFSecTSecGrpIncPKey* tablePKey = getPKey();
		cfsec::CFSecTSecGrpIncBuff* tableBuff = getTSecGrpIncEditBuff();
		tableBuff->setRequiredTenantId( tablePKey->getRequiredTenantId() );
		tableBuff->setRequiredTSecGrpIncId( tablePKey->getRequiredTSecGrpIncId() );
	}

	void CFSecTSecGrpIncEditObj::copyBuffToPKey() {
		cfsec::CFSecTSecGrpIncPKey* tablePKey = getPKey();
		cfsec::CFSecTSecGrpIncBuff* tableBuff = getTSecGrpIncBuff();
		tablePKey->setRequiredTenantId( tableBuff->getRequiredTenantId() );
		tablePKey->setRequiredTSecGrpIncId( tableBuff->getRequiredTSecGrpIncId() );
	}

	void CFSecTSecGrpIncEditObj::copyBuffToOrig() {
		cfsec::CFSecTSecGrpIncBuff* origBuff = getOrigAsTSecGrpInc()->getTSecGrpIncEditBuff();
		cfsec::CFSecTSecGrpIncBuff* myBuff = getTSecGrpIncBuff();
		if( origBuff != myBuff ) {
			*origBuff = *myBuff;
		}
	}

	void CFSecTSecGrpIncEditObj::copyOrigToBuff() {
		cfsec::CFSecTSecGrpIncBuff* origBuff = getOrigAsTSecGrpInc()->getTSecGrpIncBuff();
		cfsec::CFSecTSecGrpIncBuff* myBuff = getTSecGrpIncEditBuff();
		if( origBuff != myBuff ) {
			*myBuff = *origBuff;
		}
	}

}
