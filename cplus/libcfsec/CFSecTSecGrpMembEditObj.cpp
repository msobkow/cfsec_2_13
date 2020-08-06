// Description: C++18 edit object instance implementation for CFSec TSecGrpMemb.

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
#include <cfsecobj/CFSecTSecGrpMembObj.hpp>
#include <cfsecobj/CFSecTSecGrpMembEditObj.hpp>


namespace cfsec {

	const std::string CFSecTSecGrpMembEditObj::CLASS_NAME( "CFSecTSecGrpMembEditObj" );

	CFSecTSecGrpMembEditObj::CFSecTSecGrpMembEditObj( cfsec::ICFSecTSecGrpMembObj* argOrig )
	: ICFSecTSecGrpMembEditObj()
	{
		static const std::string S_ProcName( "CFSecTSecGrpMembEditObj-construct" );
		static const std::string S_OrigBuff( "origBuff" );
		orig = argOrig;
		cfsec::CFSecTSecGrpMembBuff* origBuff = orig->getBuff();
		if( origBuff == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_OrigBuff );
		}
		buff = dynamic_cast<cfsec::CFSecTSecGrpMembBuff*>( origBuff->clone() );
	}

	CFSecTSecGrpMembEditObj::~CFSecTSecGrpMembEditObj() {
		orig = NULL;
		if( buff != NULL ) {
			delete buff;
			buff = NULL;
		}

	}

	const std::string& CFSecTSecGrpMembEditObj::getClassName() const {
		return( CLASS_NAME );
	}

	cfsec::ICFSecSecUserObj* CFSecTSecGrpMembEditObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<cfsec::ICFSecSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getTSecGrpMembBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFSecTSecGrpMembEditObj::getCreatedAt() {
		return( getTSecGrpMembBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFSecTSecGrpMembEditObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<cfsec::ICFSecSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getTSecGrpMembBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFSecTSecGrpMembEditObj::getUpdatedAt() {
		return( getTSecGrpMembBuff()->getUpdatedAt() );
	}

	void CFSecTSecGrpMembEditObj::setCreatedBy( cfsec::ICFSecSecUserObj* value ) {
		createdBy = value;
		if( value != NULL ) {
			getTSecGrpMembEditBuff()->setCreatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFSecTSecGrpMembEditObj::setCreatedAt( const std::chrono::system_clock::time_point& value ) {
		getTSecGrpMembEditBuff()->setCreatedAt( value );
	}

	void CFSecTSecGrpMembEditObj::setUpdatedBy( cfsec::ICFSecSecUserObj* value ) {
		updatedBy = value;
		if( value != NULL ) {
			getTSecGrpMembEditBuff()->setUpdatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFSecTSecGrpMembEditObj::setUpdatedAt( const std::chrono::system_clock::time_point& value ) {
		getTSecGrpMembEditBuff()->setUpdatedAt( value );
	}

	const classcode_t CFSecTSecGrpMembEditObj::getClassCode() const {
		return( cfsec::CFSecTSecGrpMembBuff::CLASS_CODE );
	}

	bool CFSecTSecGrpMembEditObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfsec::CFSecTSecGrpMembBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFSecTSecGrpMembEditObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecTSecGrpMembEditObj" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_TenantId( "TenantId" );
		static const std::string S_TSecGrpMembId( "TSecGrpMembId" );
		static const std::string S_TSecGroupId( "TSecGroupId" );
		static const std::string S_SecUserId( "SecUserId" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFSecTSecGrpMembEditObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFSecTSecGrpMembEditObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFSecTSecGrpMembEditObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFSecTSecGrpMembEditObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFSecTSecGrpMembEditObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_TenantId, CFSecTSecGrpMembEditObj::getRequiredTenantId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_TSecGrpMembId, CFSecTSecGrpMembEditObj::getRequiredTSecGrpMembId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_TSecGroupId, CFSecTSecGrpMembEditObj::getRequiredTSecGroupId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_SecUserId, CFSecTSecGrpMembEditObj::getRequiredSecUserId() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	int32_t CFSecTSecGrpMembEditObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	void CFSecTSecGrpMembEditObj::setRequiredRevision( int32_t value ) {
		getTSecGrpMembEditBuff()->setRequiredRevision( value );
	}

	std::string CFSecTSecGrpMembEditObj::getObjName() {
		std::string objName( CLASS_NAME ); objName;
		int64_t val = getRequiredTSecGrpMembId();
		objName = cflib::CFLibXmlUtil::formatInt64( val );
		return( objName );
	}

	const std::string CFSecTSecGrpMembEditObj::getGenDefName() {
		return( cfsec::CFSecTSecGrpMembBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFSecTSecGrpMembEditObj::getScope() {
		cfsec::ICFSecTSecGroupObj* scope = getRequiredContainerGroup();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFSecTSecGrpMembEditObj::getObjScope() {
		cfsec::ICFSecTSecGroupObj* scope = getRequiredContainerGroup();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFSecTSecGrpMembEditObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFSecTSecGrpMembEditObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFSecTSecGrpMembEditObj::getNamedObject( const std::string& objName ) {
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

	std::string CFSecTSecGrpMembEditObj::getObjQualifiedName() {
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

	std::string CFSecTSecGrpMembEditObj::getObjFullName() {
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

	cfsec::ICFSecTSecGrpMembObj* CFSecTSecGrpMembEditObj::realize() {
		// We realize this so that it's buffer will get copied to orig during realization
		cfsec::ICFSecTSecGrpMembObj* retobj = getSchema()->getTSecGrpMembTableObj()->realizeTSecGrpMemb( dynamic_cast<cfsec::ICFSecTSecGrpMembObj*>( this ) );
		return( retobj );
	}

	cfsec::ICFSecTSecGrpMembObj* CFSecTSecGrpMembEditObj::read( bool forceRead ) {
		cfsec::ICFSecTSecGrpMembObj* retval = getOrigAsTSecGrpMemb()->read( forceRead );
		if( retval != orig ) {
			throw cflib::CFLibUsageException( CLASS_NAME,
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	cfsec::ICFSecTSecGrpMembObj* CFSecTSecGrpMembEditObj::create() {
		cfsec::ICFSecTSecGrpMembObj* retobj = dynamic_cast<cfsec::ICFSecSchemaObj*>( getOrigAsTSecGrpMemb()->getSchema() )->getTSecGrpMembTableObj()->createTSecGrpMemb( this );
		// Note that this instance is usually discarded during the creation process,
		// and retobj now references the cached instance of the created object.
		return( retobj );
	}

	cfsec::ICFSecTSecGrpMembEditObj* CFSecTSecGrpMembEditObj::update() {
		getSchema()->getTSecGrpMembTableObj()->updateTSecGrpMemb( this );
		return( NULL );
	}

	cfsec::ICFSecTSecGrpMembEditObj* CFSecTSecGrpMembEditObj::deleteInstance() {
		static const std::string S_MethodName( "deleteInstance" );
		static const std::string S_CannotDeleteNewInstance( "Cannot delete a new instance" );
		if( getIsNew() ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_MethodName, S_CannotDeleteNewInstance );
		}
		getSchema()->getTSecGrpMembTableObj()->deleteTSecGrpMemb( this );
		return( NULL );
	}

	cfsec::ICFSecTSecGrpMembTableObj* CFSecTSecGrpMembEditObj::getTSecGrpMembTable() {
		return( orig->getSchema()->getTSecGrpMembTableObj() );
	}

	cfsec::ICFSecTSecGrpMembEditObj* CFSecTSecGrpMembEditObj::getEdit() {
		return( this );
	}

	cfsec::ICFSecTSecGrpMembEditObj* CFSecTSecGrpMembEditObj::getTSecGrpMembEdit() {
		return( (cfsec::ICFSecTSecGrpMembEditObj*)this );
	}

	cfsec::ICFSecTSecGrpMembEditObj* CFSecTSecGrpMembEditObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_Message( "Cannot edit an edition" );
		throw cflib::CFLibUsageException( CLASS_NAME,
			S_ProcName,
			S_Message );
	}

	void CFSecTSecGrpMembEditObj::endEdit() {
		orig->endEdit();
	}

	cfsec::ICFSecTSecGrpMembObj* CFSecTSecGrpMembEditObj::getOrig() {
		return( orig );
	}

	cfsec::ICFSecTSecGrpMembObj* CFSecTSecGrpMembEditObj::getOrigAsTSecGrpMemb() {
		return( dynamic_cast<cfsec::ICFSecTSecGrpMembObj*>( orig ) );
	}

	cfsec::ICFSecSchemaObj* CFSecTSecGrpMembEditObj::getSchema() {
		return( orig->getSchema() );
	}

	cfsec::CFSecTSecGrpMembBuff* CFSecTSecGrpMembEditObj::getBuff() {
		return( buff );
	}

	void CFSecTSecGrpMembEditObj::setBuff( cfsec::CFSecTSecGrpMembBuff* value ) {
		if( buff != value ) {
			if( ( buff != NULL ) && ( buff != value ) ) {
				delete buff;
				buff = NULL;
			}
			buff = value;
		}
	}

	cfsec::CFSecTSecGrpMembPKey* CFSecTSecGrpMembEditObj::getPKey() {
		return( orig->getPKey() );
	}

	void CFSecTSecGrpMembEditObj::setPKey( cfsec::CFSecTSecGrpMembPKey* value ) {
		if( orig->getPKey() != value ) {
			orig->setPKey( value );
		}
		copyPKeyToBuff();
	}

	bool CFSecTSecGrpMembEditObj::getIsNew() {
		return( orig->getIsNew() );
	}

	void CFSecTSecGrpMembEditObj::setIsNew( bool value ) {
		orig->setIsNew( value );
	}

	const int64_t CFSecTSecGrpMembEditObj::getRequiredTenantId() {
		return( getPKey()->getRequiredTenantId() );
	}

	const int64_t* CFSecTSecGrpMembEditObj::getRequiredTenantIdReference() {
		return( getPKey()->getRequiredTenantIdReference() );
	}

	const int64_t CFSecTSecGrpMembEditObj::getRequiredTSecGrpMembId() {
		return( getPKey()->getRequiredTSecGrpMembId() );
	}

	const int64_t* CFSecTSecGrpMembEditObj::getRequiredTSecGrpMembIdReference() {
		return( getPKey()->getRequiredTSecGrpMembIdReference() );
	}

	const int32_t CFSecTSecGrpMembEditObj::getRequiredTSecGroupId() {
		return( getTSecGrpMembBuff()->getRequiredTSecGroupId() );
	}

	const int32_t* CFSecTSecGrpMembEditObj::getRequiredTSecGroupIdReference() {
		return( getTSecGrpMembBuff()->getRequiredTSecGroupIdReference() );
	}

	const uuid_ptr_t CFSecTSecGrpMembEditObj::getRequiredSecUserId() {
		return( getTSecGrpMembBuff()->getRequiredSecUserId() );
	}

	const uuid_ptr_t CFSecTSecGrpMembEditObj::getRequiredSecUserIdReference() {
		return( getTSecGrpMembBuff()->getRequiredSecUserIdReference() );
	}

	cfsec::ICFSecTenantObj* CFSecTSecGrpMembEditObj::getRequiredOwnerTenant( bool forceRead ) {
		cfsec::ICFSecTenantObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<cfsec::ICFSecSchemaObj*>( getOrigAsTSecGrpMemb()->getSchema() )->getTenantTableObj()->readTenantByIdIdx( getPKey()->getRequiredTenantId() );
		}
		return( retobj );
	}

	void CFSecTSecGrpMembEditObj::setRequiredOwnerTenant( cfsec::ICFSecTenantObj* value ) {
			
			if( value != NULL ) {
				getPKey()->setRequiredTenantId
( value->getRequiredId() );
				getTSecGrpMembEditBuff()->setRequiredTenantId( value->getRequiredId() );
			}
		}

	cfsec::ICFSecTSecGroupObj* CFSecTSecGrpMembEditObj::getRequiredContainerGroup( bool forceRead ) {
		cfsec::ICFSecTSecGroupObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<cfsec::ICFSecSchemaObj*>( getOrigAsTSecGrpMemb()->getSchema() )->getTSecGroupTableObj()->readTSecGroupByIdIdx( getPKey()->getRequiredTenantId(),
					getTSecGrpMembBuff()->getRequiredTSecGroupId() );
		}
		return( retobj );
	}

	void CFSecTSecGrpMembEditObj::setRequiredContainerGroup( cfsec::ICFSecTSecGroupObj* value ) {
			
			if( value != NULL ) {
				getPKey()->setRequiredTenantId
( value->getRequiredTenantId() );
				getTSecGrpMembEditBuff()->setRequiredTenantId( value->getRequiredTenantId() );
				getTSecGrpMembEditBuff()->setRequiredTSecGroupId( value->getRequiredTSecGroupId() );
			}
		}

	cfsec::ICFSecSecUserObj* CFSecTSecGrpMembEditObj::getRequiredParentUser( bool forceRead ) {
		cfsec::ICFSecSecUserObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<cfsec::ICFSecSchemaObj*>( getOrigAsTSecGrpMemb()->getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getTSecGrpMembBuff()->getRequiredSecUserId() );
		}
		return( retobj );
	}

	void CFSecTSecGrpMembEditObj::setRequiredParentUser( cfsec::ICFSecSecUserObj* value ) {
			
			if( value != NULL ) {
				getTSecGrpMembEditBuff()->setRequiredSecUserId( value->getRequiredSecUserId() );
			}
			else {
			}
		}

	void CFSecTSecGrpMembEditObj::copyPKeyToBuff() {
		cfsec::CFSecTSecGrpMembPKey* tablePKey = getPKey();
		cfsec::CFSecTSecGrpMembBuff* tableBuff = getTSecGrpMembEditBuff();
		tableBuff->setRequiredTenantId( tablePKey->getRequiredTenantId() );
		tableBuff->setRequiredTSecGrpMembId( tablePKey->getRequiredTSecGrpMembId() );
	}

	void CFSecTSecGrpMembEditObj::copyBuffToPKey() {
		cfsec::CFSecTSecGrpMembPKey* tablePKey = getPKey();
		cfsec::CFSecTSecGrpMembBuff* tableBuff = getTSecGrpMembBuff();
		tablePKey->setRequiredTenantId( tableBuff->getRequiredTenantId() );
		tablePKey->setRequiredTSecGrpMembId( tableBuff->getRequiredTSecGrpMembId() );
	}

	void CFSecTSecGrpMembEditObj::copyBuffToOrig() {
		cfsec::CFSecTSecGrpMembBuff* origBuff = getOrigAsTSecGrpMemb()->getTSecGrpMembEditBuff();
		cfsec::CFSecTSecGrpMembBuff* myBuff = getTSecGrpMembBuff();
		if( origBuff != myBuff ) {
			*origBuff = *myBuff;
		}
	}

	void CFSecTSecGrpMembEditObj::copyOrigToBuff() {
		cfsec::CFSecTSecGrpMembBuff* origBuff = getOrigAsTSecGrpMemb()->getTSecGrpMembBuff();
		cfsec::CFSecTSecGrpMembBuff* myBuff = getTSecGrpMembEditBuff();
		if( origBuff != myBuff ) {
			*myBuff = *origBuff;
		}
	}

}
