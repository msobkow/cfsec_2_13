// Description: C++18 edit object instance implementation for CFSec ISOTZone.

/*
 *	org.msscf.msscf.CFSec
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
#include <cfsecobj/CFSecISOTZoneObj.hpp>
#include <cfsecobj/CFSecISOTZoneEditObj.hpp>


namespace cfsec {

	const std::string CFSecISOTZoneEditObj::CLASS_NAME( "CFSecISOTZoneEditObj" );

	CFSecISOTZoneEditObj::CFSecISOTZoneEditObj( cfsec::ICFSecISOTZoneObj* argOrig )
	: ICFSecISOTZoneEditObj()
	{
		static const std::string S_ProcName( "CFSecISOTZoneEditObj-construct" );
		static const std::string S_OrigBuff( "origBuff" );
		orig = argOrig;
		cfsec::CFSecISOTZoneBuff* origBuff = orig->getBuff();
		if( origBuff == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_OrigBuff );
		}
		buff = dynamic_cast<cfsec::CFSecISOTZoneBuff*>( origBuff->clone() );
	}

	CFSecISOTZoneEditObj::~CFSecISOTZoneEditObj() {
		orig = NULL;
		if( buff != NULL ) {
			delete buff;
			buff = NULL;
		}

	}

	const std::string& CFSecISOTZoneEditObj::getClassName() const {
		return( CLASS_NAME );
	}

	cfsec::ICFSecSecUserObj* CFSecISOTZoneEditObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<cfsec::ICFSecSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getISOTZoneBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFSecISOTZoneEditObj::getCreatedAt() {
		return( getISOTZoneBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFSecISOTZoneEditObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<cfsec::ICFSecSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getISOTZoneBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFSecISOTZoneEditObj::getUpdatedAt() {
		return( getISOTZoneBuff()->getUpdatedAt() );
	}

	void CFSecISOTZoneEditObj::setCreatedBy( cfsec::ICFSecSecUserObj* value ) {
		createdBy = value;
		if( value != NULL ) {
			getISOTZoneEditBuff()->setCreatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFSecISOTZoneEditObj::setCreatedAt( const std::chrono::system_clock::time_point& value ) {
		getISOTZoneEditBuff()->setCreatedAt( value );
	}

	void CFSecISOTZoneEditObj::setUpdatedBy( cfsec::ICFSecSecUserObj* value ) {
		updatedBy = value;
		if( value != NULL ) {
			getISOTZoneEditBuff()->setUpdatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFSecISOTZoneEditObj::setUpdatedAt( const std::chrono::system_clock::time_point& value ) {
		getISOTZoneEditBuff()->setUpdatedAt( value );
	}

	const classcode_t CFSecISOTZoneEditObj::getClassCode() const {
		return( cfsec::CFSecISOTZoneBuff::CLASS_CODE );
	}

	bool CFSecISOTZoneEditObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfsec::CFSecISOTZoneBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFSecISOTZoneEditObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecISOTZoneEditObj" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_ISOTZoneId( "ISOTZoneId" );
		static const std::string S_Iso8601( "Iso8601" );
		static const std::string S_TZName( "TZName" );
		static const std::string S_TZHourOffset( "TZHourOffset" );
		static const std::string S_TZMinOffset( "TZMinOffset" );
		static const std::string S_Description( "Description" );
		static const std::string S_Visible( "Visible" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFSecISOTZoneEditObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFSecISOTZoneEditObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFSecISOTZoneEditObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFSecISOTZoneEditObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFSecISOTZoneEditObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_ISOTZoneId, CFSecISOTZoneEditObj::getRequiredISOTZoneId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Iso8601, CFSecISOTZoneEditObj::getRequiredIso8601() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_TZName, CFSecISOTZoneEditObj::getRequiredTZName() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_TZHourOffset, CFSecISOTZoneEditObj::getRequiredTZHourOffset() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_TZMinOffset, CFSecISOTZoneEditObj::getRequiredTZMinOffset() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Description, CFSecISOTZoneEditObj::getRequiredDescription() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredBoolean( &S_Space, S_Visible, CFSecISOTZoneEditObj::getRequiredVisible() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	int32_t CFSecISOTZoneEditObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	void CFSecISOTZoneEditObj::setRequiredRevision( int32_t value ) {
		getISOTZoneEditBuff()->setRequiredRevision( value );
	}

	std::string CFSecISOTZoneEditObj::getObjName() {
		std::string objName( CLASS_NAME ); objName;
		objName.clear();
		objName.append( getRequiredTZName() );
		return( objName );
	}

	const std::string CFSecISOTZoneEditObj::getGenDefName() {
		return( cfsec::CFSecISOTZoneBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFSecISOTZoneEditObj::getScope() {
		return( NULL );
	}

	cflib::ICFLibAnyObj* CFSecISOTZoneEditObj::getObjScope() {
		return( NULL );
	}

	cflib::ICFLibAnyObj* CFSecISOTZoneEditObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFSecISOTZoneEditObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFSecISOTZoneEditObj::getNamedObject( const std::string& objName ) {
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

	std::string CFSecISOTZoneEditObj::getObjQualifiedName() {
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

	std::string CFSecISOTZoneEditObj::getObjFullName() {
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

	cfsec::ICFSecISOTZoneObj* CFSecISOTZoneEditObj::realize() {
		// We realize this so that it's buffer will get copied to orig during realization
		cfsec::ICFSecISOTZoneObj* retobj = getSchema()->getISOTZoneTableObj()->realizeISOTZone( dynamic_cast<cfsec::ICFSecISOTZoneObj*>( this ) );
		return( retobj );
	}

	cfsec::ICFSecISOTZoneObj* CFSecISOTZoneEditObj::read( bool forceRead ) {
		cfsec::ICFSecISOTZoneObj* retval = getOrigAsISOTZone()->read( forceRead );
		if( retval != orig ) {
			throw cflib::CFLibUsageException( CLASS_NAME,
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	cfsec::ICFSecISOTZoneObj* CFSecISOTZoneEditObj::create() {
		cfsec::ICFSecISOTZoneObj* retobj = dynamic_cast<cfsec::ICFSecSchemaObj*>( getOrigAsISOTZone()->getSchema() )->getISOTZoneTableObj()->createISOTZone( this );
		// Note that this instance is usually discarded during the creation process,
		// and retobj now references the cached instance of the created object.
		return( retobj );
	}

	cfsec::ICFSecISOTZoneEditObj* CFSecISOTZoneEditObj::update() {
		getSchema()->getISOTZoneTableObj()->updateISOTZone( this );
		return( NULL );
	}

	cfsec::ICFSecISOTZoneEditObj* CFSecISOTZoneEditObj::deleteInstance() {
		static const std::string S_MethodName( "deleteInstance" );
		static const std::string S_CannotDeleteNewInstance( "Cannot delete a new instance" );
		if( getIsNew() ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_MethodName, S_CannotDeleteNewInstance );
		}
		getSchema()->getISOTZoneTableObj()->deleteISOTZone( this );
		return( NULL );
	}

	cfsec::ICFSecISOTZoneTableObj* CFSecISOTZoneEditObj::getISOTZoneTable() {
		return( orig->getSchema()->getISOTZoneTableObj() );
	}

	cfsec::ICFSecISOTZoneEditObj* CFSecISOTZoneEditObj::getEdit() {
		return( this );
	}

	cfsec::ICFSecISOTZoneEditObj* CFSecISOTZoneEditObj::getISOTZoneEdit() {
		return( (cfsec::ICFSecISOTZoneEditObj*)this );
	}

	cfsec::ICFSecISOTZoneEditObj* CFSecISOTZoneEditObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_Message( "Cannot edit an edition" );
		throw cflib::CFLibUsageException( CLASS_NAME,
			S_ProcName,
			S_Message );
	}

	void CFSecISOTZoneEditObj::endEdit() {
		orig->endEdit();
	}

	cfsec::ICFSecISOTZoneObj* CFSecISOTZoneEditObj::getOrig() {
		return( orig );
	}

	cfsec::ICFSecISOTZoneObj* CFSecISOTZoneEditObj::getOrigAsISOTZone() {
		return( dynamic_cast<cfsec::ICFSecISOTZoneObj*>( orig ) );
	}

	cfsec::ICFSecSchemaObj* CFSecISOTZoneEditObj::getSchema() {
		return( orig->getSchema() );
	}

	cfsec::CFSecISOTZoneBuff* CFSecISOTZoneEditObj::getBuff() {
		return( buff );
	}

	void CFSecISOTZoneEditObj::setBuff( cfsec::CFSecISOTZoneBuff* value ) {
		if( buff != value ) {
			if( ( buff != NULL ) && ( buff != value ) ) {
				delete buff;
				buff = NULL;
			}
			buff = value;
		}
	}

	cfsec::CFSecISOTZonePKey* CFSecISOTZoneEditObj::getPKey() {
		return( orig->getPKey() );
	}

	void CFSecISOTZoneEditObj::setPKey( cfsec::CFSecISOTZonePKey* value ) {
		if( orig->getPKey() != value ) {
			orig->setPKey( value );
		}
		copyPKeyToBuff();
	}

	bool CFSecISOTZoneEditObj::getIsNew() {
		return( orig->getIsNew() );
	}

	void CFSecISOTZoneEditObj::setIsNew( bool value ) {
		orig->setIsNew( value );
	}

	const int16_t CFSecISOTZoneEditObj::getRequiredISOTZoneId() {
		return( getPKey()->getRequiredISOTZoneId() );
	}

	const int16_t* CFSecISOTZoneEditObj::getRequiredISOTZoneIdReference() {
		return( getPKey()->getRequiredISOTZoneIdReference() );
	}

	const std::string& CFSecISOTZoneEditObj::getRequiredIso8601() {
		return( getISOTZoneBuff()->getRequiredIso8601() );
	}

	const std::string* CFSecISOTZoneEditObj::getRequiredIso8601Reference() {
		return( getISOTZoneBuff()->getRequiredIso8601Reference() );
	}

	void CFSecISOTZoneEditObj::setRequiredIso8601( const std::string& value ) {
		if( getISOTZoneBuff()->getRequiredIso8601() != value ) {
			getISOTZoneEditBuff()->setRequiredIso8601( value );
		}
	}

	const std::string& CFSecISOTZoneEditObj::getRequiredTZName() {
		return( getISOTZoneBuff()->getRequiredTZName() );
	}

	const std::string* CFSecISOTZoneEditObj::getRequiredTZNameReference() {
		return( getISOTZoneBuff()->getRequiredTZNameReference() );
	}

	void CFSecISOTZoneEditObj::setRequiredTZName( const std::string& value ) {
		if( getISOTZoneBuff()->getRequiredTZName() != value ) {
			getISOTZoneEditBuff()->setRequiredTZName( value );
		}
	}

	const int16_t CFSecISOTZoneEditObj::getRequiredTZHourOffset() {
		return( getISOTZoneBuff()->getRequiredTZHourOffset() );
	}

	const int16_t* CFSecISOTZoneEditObj::getRequiredTZHourOffsetReference() {
		return( getISOTZoneBuff()->getRequiredTZHourOffsetReference() );
	}

	void CFSecISOTZoneEditObj::setRequiredTZHourOffset( const int16_t value ) {
		if( getISOTZoneBuff()->getRequiredTZHourOffset() != value ) {
			getISOTZoneEditBuff()->setRequiredTZHourOffset( value );
		}
	}

	const int16_t CFSecISOTZoneEditObj::getRequiredTZMinOffset() {
		return( getISOTZoneBuff()->getRequiredTZMinOffset() );
	}

	const int16_t* CFSecISOTZoneEditObj::getRequiredTZMinOffsetReference() {
		return( getISOTZoneBuff()->getRequiredTZMinOffsetReference() );
	}

	void CFSecISOTZoneEditObj::setRequiredTZMinOffset( const int16_t value ) {
		if( getISOTZoneBuff()->getRequiredTZMinOffset() != value ) {
			getISOTZoneEditBuff()->setRequiredTZMinOffset( value );
		}
	}

	const std::string& CFSecISOTZoneEditObj::getRequiredDescription() {
		return( getISOTZoneBuff()->getRequiredDescription() );
	}

	const std::string* CFSecISOTZoneEditObj::getRequiredDescriptionReference() {
		return( getISOTZoneBuff()->getRequiredDescriptionReference() );
	}

	void CFSecISOTZoneEditObj::setRequiredDescription( const std::string& value ) {
		if( getISOTZoneBuff()->getRequiredDescription() != value ) {
			getISOTZoneEditBuff()->setRequiredDescription( value );
		}
	}

	const bool CFSecISOTZoneEditObj::getRequiredVisible() {
		return( getISOTZoneBuff()->getRequiredVisible() );
	}

	const bool* CFSecISOTZoneEditObj::getRequiredVisibleReference() {
		return( getISOTZoneBuff()->getRequiredVisibleReference() );
	}

	void CFSecISOTZoneEditObj::setRequiredVisible( const bool value ) {
		if( getISOTZoneBuff()->getRequiredVisible() != value ) {
			getISOTZoneEditBuff()->setRequiredVisible( value );
		}
	}

	void CFSecISOTZoneEditObj::copyPKeyToBuff() {
		cfsec::CFSecISOTZonePKey* tablePKey = getPKey();
		cfsec::CFSecISOTZoneBuff* tableBuff = getISOTZoneEditBuff();
		tableBuff->setRequiredISOTZoneId( tablePKey->getRequiredISOTZoneId() );
	}

	void CFSecISOTZoneEditObj::copyBuffToPKey() {
		cfsec::CFSecISOTZonePKey* tablePKey = getPKey();
		cfsec::CFSecISOTZoneBuff* tableBuff = getISOTZoneBuff();
		tablePKey->setRequiredISOTZoneId( tableBuff->getRequiredISOTZoneId() );
	}

	void CFSecISOTZoneEditObj::copyBuffToOrig() {
		cfsec::CFSecISOTZoneBuff* origBuff = getOrigAsISOTZone()->getISOTZoneEditBuff();
		cfsec::CFSecISOTZoneBuff* myBuff = getISOTZoneBuff();
		if( origBuff != myBuff ) {
			*origBuff = *myBuff;
		}
	}

	void CFSecISOTZoneEditObj::copyOrigToBuff() {
		cfsec::CFSecISOTZoneBuff* origBuff = getOrigAsISOTZone()->getISOTZoneBuff();
		cfsec::CFSecISOTZoneBuff* myBuff = getISOTZoneEditBuff();
		if( origBuff != myBuff ) {
			*myBuff = *origBuff;
		}
	}

}
