// Description: C++18 edit object instance implementation for CFSec SecGrpMemb.

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
#include <cfsecobj/CFSecSecGrpMembObj.hpp>
#include <cfsecobj/CFSecSecGrpMembEditObj.hpp>


namespace cfsec {

	const std::string CFSecSecGrpMembEditObj::CLASS_NAME( "CFSecSecGrpMembEditObj" );

	CFSecSecGrpMembEditObj::CFSecSecGrpMembEditObj( cfsec::ICFSecSecGrpMembObj* argOrig )
	: ICFSecSecGrpMembEditObj()
	{
		static const std::string S_ProcName( "CFSecSecGrpMembEditObj-construct" );
		static const std::string S_OrigBuff( "origBuff" );
		orig = argOrig;
		cfsec::CFSecSecGrpMembBuff* origBuff = orig->getBuff();
		if( origBuff == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_OrigBuff );
		}
		buff = dynamic_cast<cfsec::CFSecSecGrpMembBuff*>( origBuff->clone() );
	}

	CFSecSecGrpMembEditObj::~CFSecSecGrpMembEditObj() {
		orig = NULL;
		if( buff != NULL ) {
			delete buff;
			buff = NULL;
		}

	}

	const std::string& CFSecSecGrpMembEditObj::getClassName() const {
		return( CLASS_NAME );
	}

	cfsec::ICFSecSecUserObj* CFSecSecGrpMembEditObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<cfsec::ICFSecSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getSecGrpMembBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFSecSecGrpMembEditObj::getCreatedAt() {
		return( getSecGrpMembBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFSecSecGrpMembEditObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<cfsec::ICFSecSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getSecGrpMembBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFSecSecGrpMembEditObj::getUpdatedAt() {
		return( getSecGrpMembBuff()->getUpdatedAt() );
	}

	void CFSecSecGrpMembEditObj::setCreatedBy( cfsec::ICFSecSecUserObj* value ) {
		createdBy = value;
		if( value != NULL ) {
			getSecGrpMembEditBuff()->setCreatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFSecSecGrpMembEditObj::setCreatedAt( const std::chrono::system_clock::time_point& value ) {
		getSecGrpMembEditBuff()->setCreatedAt( value );
	}

	void CFSecSecGrpMembEditObj::setUpdatedBy( cfsec::ICFSecSecUserObj* value ) {
		updatedBy = value;
		if( value != NULL ) {
			getSecGrpMembEditBuff()->setUpdatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFSecSecGrpMembEditObj::setUpdatedAt( const std::chrono::system_clock::time_point& value ) {
		getSecGrpMembEditBuff()->setUpdatedAt( value );
	}

	const classcode_t CFSecSecGrpMembEditObj::getClassCode() const {
		return( cfsec::CFSecSecGrpMembBuff::CLASS_CODE );
	}

	bool CFSecSecGrpMembEditObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfsec::CFSecSecGrpMembBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFSecSecGrpMembEditObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecSecGrpMembEditObj" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_ClusterId( "ClusterId" );
		static const std::string S_SecGrpMembId( "SecGrpMembId" );
		static const std::string S_SecGroupId( "SecGroupId" );
		static const std::string S_SecUserId( "SecUserId" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFSecSecGrpMembEditObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFSecSecGrpMembEditObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFSecSecGrpMembEditObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFSecSecGrpMembEditObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFSecSecGrpMembEditObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_ClusterId, CFSecSecGrpMembEditObj::getRequiredClusterId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_SecGrpMembId, CFSecSecGrpMembEditObj::getRequiredSecGrpMembId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_SecGroupId, CFSecSecGrpMembEditObj::getRequiredSecGroupId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_SecUserId, CFSecSecGrpMembEditObj::getRequiredSecUserId() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	int32_t CFSecSecGrpMembEditObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	void CFSecSecGrpMembEditObj::setRequiredRevision( int32_t value ) {
		getSecGrpMembEditBuff()->setRequiredRevision( value );
	}

	std::string CFSecSecGrpMembEditObj::getObjName() {
		std::string objName( CLASS_NAME ); objName;
		int64_t val = getRequiredSecGrpMembId();
		objName = cflib::CFLibXmlUtil::formatInt64( val );
		return( objName );
	}

	const std::string CFSecSecGrpMembEditObj::getGenDefName() {
		return( cfsec::CFSecSecGrpMembBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFSecSecGrpMembEditObj::getScope() {
		cfsec::ICFSecSecGroupObj* scope = getRequiredContainerGroup();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFSecSecGrpMembEditObj::getObjScope() {
		cfsec::ICFSecSecGroupObj* scope = getRequiredContainerGroup();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFSecSecGrpMembEditObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFSecSecGrpMembEditObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFSecSecGrpMembEditObj::getNamedObject( const std::string& objName ) {
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

	std::string CFSecSecGrpMembEditObj::getObjQualifiedName() {
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

	std::string CFSecSecGrpMembEditObj::getObjFullName() {
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

	cfsec::ICFSecSecGrpMembObj* CFSecSecGrpMembEditObj::realize() {
		// We realize this so that it's buffer will get copied to orig during realization
		cfsec::ICFSecSecGrpMembObj* retobj = getSchema()->getSecGrpMembTableObj()->realizeSecGrpMemb( dynamic_cast<cfsec::ICFSecSecGrpMembObj*>( this ) );
		return( retobj );
	}

	cfsec::ICFSecSecGrpMembObj* CFSecSecGrpMembEditObj::read( bool forceRead ) {
		cfsec::ICFSecSecGrpMembObj* retval = getOrigAsSecGrpMemb()->read( forceRead );
		if( retval != orig ) {
			throw cflib::CFLibUsageException( CLASS_NAME,
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	cfsec::ICFSecSecGrpMembObj* CFSecSecGrpMembEditObj::create() {
		cfsec::ICFSecSecGrpMembObj* retobj = dynamic_cast<cfsec::ICFSecSchemaObj*>( getOrigAsSecGrpMemb()->getSchema() )->getSecGrpMembTableObj()->createSecGrpMemb( this );
		// Note that this instance is usually discarded during the creation process,
		// and retobj now references the cached instance of the created object.
		return( retobj );
	}

	cfsec::ICFSecSecGrpMembEditObj* CFSecSecGrpMembEditObj::update() {
		getSchema()->getSecGrpMembTableObj()->updateSecGrpMemb( this );
		return( NULL );
	}

	cfsec::ICFSecSecGrpMembEditObj* CFSecSecGrpMembEditObj::deleteInstance() {
		static const std::string S_MethodName( "deleteInstance" );
		static const std::string S_CannotDeleteNewInstance( "Cannot delete a new instance" );
		if( getIsNew() ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_MethodName, S_CannotDeleteNewInstance );
		}
		getSchema()->getSecGrpMembTableObj()->deleteSecGrpMemb( this );
		return( NULL );
	}

	cfsec::ICFSecSecGrpMembTableObj* CFSecSecGrpMembEditObj::getSecGrpMembTable() {
		return( orig->getSchema()->getSecGrpMembTableObj() );
	}

	cfsec::ICFSecSecGrpMembEditObj* CFSecSecGrpMembEditObj::getEdit() {
		return( this );
	}

	cfsec::ICFSecSecGrpMembEditObj* CFSecSecGrpMembEditObj::getSecGrpMembEdit() {
		return( (cfsec::ICFSecSecGrpMembEditObj*)this );
	}

	cfsec::ICFSecSecGrpMembEditObj* CFSecSecGrpMembEditObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_Message( "Cannot edit an edition" );
		throw cflib::CFLibUsageException( CLASS_NAME,
			S_ProcName,
			S_Message );
	}

	void CFSecSecGrpMembEditObj::endEdit() {
		orig->endEdit();
	}

	cfsec::ICFSecSecGrpMembObj* CFSecSecGrpMembEditObj::getOrig() {
		return( orig );
	}

	cfsec::ICFSecSecGrpMembObj* CFSecSecGrpMembEditObj::getOrigAsSecGrpMemb() {
		return( dynamic_cast<cfsec::ICFSecSecGrpMembObj*>( orig ) );
	}

	cfsec::ICFSecSchemaObj* CFSecSecGrpMembEditObj::getSchema() {
		return( orig->getSchema() );
	}

	cfsec::CFSecSecGrpMembBuff* CFSecSecGrpMembEditObj::getBuff() {
		return( buff );
	}

	void CFSecSecGrpMembEditObj::setBuff( cfsec::CFSecSecGrpMembBuff* value ) {
		if( buff != value ) {
			if( ( buff != NULL ) && ( buff != value ) ) {
				delete buff;
				buff = NULL;
			}
			buff = value;
		}
	}

	cfsec::CFSecSecGrpMembPKey* CFSecSecGrpMembEditObj::getPKey() {
		return( orig->getPKey() );
	}

	void CFSecSecGrpMembEditObj::setPKey( cfsec::CFSecSecGrpMembPKey* value ) {
		if( orig->getPKey() != value ) {
			orig->setPKey( value );
		}
		copyPKeyToBuff();
	}

	bool CFSecSecGrpMembEditObj::getIsNew() {
		return( orig->getIsNew() );
	}

	void CFSecSecGrpMembEditObj::setIsNew( bool value ) {
		orig->setIsNew( value );
	}

	const int64_t CFSecSecGrpMembEditObj::getRequiredClusterId() {
		return( getPKey()->getRequiredClusterId() );
	}

	const int64_t* CFSecSecGrpMembEditObj::getRequiredClusterIdReference() {
		return( getPKey()->getRequiredClusterIdReference() );
	}

	const int64_t CFSecSecGrpMembEditObj::getRequiredSecGrpMembId() {
		return( getPKey()->getRequiredSecGrpMembId() );
	}

	const int64_t* CFSecSecGrpMembEditObj::getRequiredSecGrpMembIdReference() {
		return( getPKey()->getRequiredSecGrpMembIdReference() );
	}

	const int32_t CFSecSecGrpMembEditObj::getRequiredSecGroupId() {
		return( getSecGrpMembBuff()->getRequiredSecGroupId() );
	}

	const int32_t* CFSecSecGrpMembEditObj::getRequiredSecGroupIdReference() {
		return( getSecGrpMembBuff()->getRequiredSecGroupIdReference() );
	}

	const uuid_ptr_t CFSecSecGrpMembEditObj::getRequiredSecUserId() {
		return( getSecGrpMembBuff()->getRequiredSecUserId() );
	}

	const uuid_ptr_t CFSecSecGrpMembEditObj::getRequiredSecUserIdReference() {
		return( getSecGrpMembBuff()->getRequiredSecUserIdReference() );
	}

	cfsec::ICFSecClusterObj* CFSecSecGrpMembEditObj::getRequiredOwnerCluster( bool forceRead ) {
		cfsec::ICFSecClusterObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<cfsec::ICFSecSchemaObj*>( getOrigAsSecGrpMemb()->getSchema() )->getClusterTableObj()->readClusterByIdIdx( getPKey()->getRequiredClusterId() );
		}
		return( retobj );
	}

	void CFSecSecGrpMembEditObj::setRequiredOwnerCluster( cfsec::ICFSecClusterObj* value ) {
			
			if( value != NULL ) {
				getPKey()->setRequiredClusterId
( value->getRequiredId() );
				getSecGrpMembEditBuff()->setRequiredClusterId( value->getRequiredId() );
			}
		}

	cfsec::ICFSecSecGroupObj* CFSecSecGrpMembEditObj::getRequiredContainerGroup( bool forceRead ) {
		cfsec::ICFSecSecGroupObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<cfsec::ICFSecSchemaObj*>( getOrigAsSecGrpMemb()->getSchema() )->getSecGroupTableObj()->readSecGroupByIdIdx( getPKey()->getRequiredClusterId(),
					getSecGrpMembBuff()->getRequiredSecGroupId() );
		}
		return( retobj );
	}

	void CFSecSecGrpMembEditObj::setRequiredContainerGroup( cfsec::ICFSecSecGroupObj* value ) {
			
			if( value != NULL ) {
				getPKey()->setRequiredClusterId
( value->getRequiredClusterId() );
				getSecGrpMembEditBuff()->setRequiredClusterId( value->getRequiredClusterId() );
				getSecGrpMembEditBuff()->setRequiredSecGroupId( value->getRequiredSecGroupId() );
			}
		}

	cfsec::ICFSecSecUserObj* CFSecSecGrpMembEditObj::getRequiredParentUser( bool forceRead ) {
		cfsec::ICFSecSecUserObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<cfsec::ICFSecSchemaObj*>( getOrigAsSecGrpMemb()->getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getSecGrpMembBuff()->getRequiredSecUserId() );
		}
		return( retobj );
	}

	void CFSecSecGrpMembEditObj::setRequiredParentUser( cfsec::ICFSecSecUserObj* value ) {
			
			if( value != NULL ) {
				getSecGrpMembEditBuff()->setRequiredSecUserId( value->getRequiredSecUserId() );
			}
			else {
			}
		}

	void CFSecSecGrpMembEditObj::copyPKeyToBuff() {
		cfsec::CFSecSecGrpMembPKey* tablePKey = getPKey();
		cfsec::CFSecSecGrpMembBuff* tableBuff = getSecGrpMembEditBuff();
		tableBuff->setRequiredClusterId( tablePKey->getRequiredClusterId() );
		tableBuff->setRequiredSecGrpMembId( tablePKey->getRequiredSecGrpMembId() );
	}

	void CFSecSecGrpMembEditObj::copyBuffToPKey() {
		cfsec::CFSecSecGrpMembPKey* tablePKey = getPKey();
		cfsec::CFSecSecGrpMembBuff* tableBuff = getSecGrpMembBuff();
		tablePKey->setRequiredClusterId( tableBuff->getRequiredClusterId() );
		tablePKey->setRequiredSecGrpMembId( tableBuff->getRequiredSecGrpMembId() );
	}

	void CFSecSecGrpMembEditObj::copyBuffToOrig() {
		cfsec::CFSecSecGrpMembBuff* origBuff = getOrigAsSecGrpMemb()->getSecGrpMembEditBuff();
		cfsec::CFSecSecGrpMembBuff* myBuff = getSecGrpMembBuff();
		if( origBuff != myBuff ) {
			*origBuff = *myBuff;
		}
	}

	void CFSecSecGrpMembEditObj::copyOrigToBuff() {
		cfsec::CFSecSecGrpMembBuff* origBuff = getOrigAsSecGrpMemb()->getSecGrpMembBuff();
		cfsec::CFSecSecGrpMembBuff* myBuff = getSecGrpMembEditBuff();
		if( origBuff != myBuff ) {
			*myBuff = *origBuff;
		}
	}

}
