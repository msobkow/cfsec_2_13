// Description: C++18 base object instance implementation for CFSec ISOCtryCcy.

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
#include <cfsecobj/CFSecISOCtryCcyObj.hpp>

namespace cfsec {

	const std::string CFSecISOCtryCcyObj::CLASS_NAME( "CFSecISOCtryCcyObj" );
	const classcode_t CFSecISOCtryCcyObj::CLASS_CODE = 0xa005L;

	int32_t CFSecISOCtryCcyObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	const int16_t CFSecISOCtryCcyObj::getRequiredISOCtryId() {
		return( getPKey()->getRequiredISOCtryId() );
	}

	const int16_t* CFSecISOCtryCcyObj::getRequiredISOCtryIdReference() {
		return( getPKey()->getRequiredISOCtryIdReference() );
	}

	const int16_t CFSecISOCtryCcyObj::getRequiredISOCcyId() {
		return( getPKey()->getRequiredISOCcyId() );
	}

	const int16_t* CFSecISOCtryCcyObj::getRequiredISOCcyIdReference() {
		return( getPKey()->getRequiredISOCcyIdReference() );
	}


	cfsec::ICFSecISOCtryObj* CFSecISOCtryCcyObj::getRequiredContainerCtry( bool forceRead ) {
		cfsec::ICFSecISOCtryObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getISOCtryTableObj()->readISOCtryByIdIdx( getPKey()->getRequiredISOCtryId(), forceRead );
		}
		return( retobj );
	}

	cfsec::ICFSecISOCcyObj* CFSecISOCtryCcyObj::getRequiredParentCcy( bool forceRead ) {
		cfsec::ICFSecISOCcyObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getISOCcyTableObj()->readISOCcyByIdIdx( getPKey()->getRequiredISOCcyId(), forceRead );
		}
		return( retobj );
	}

	CFSecISOCtryCcyObj::CFSecISOCtryCcyObj()
	: ICFSecISOCtryCcyObj()
	{
		schema = NULL;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFSecISOCtryCcyObj::CFSecISOCtryCcyObj( cfsec::ICFSecSchemaObj* argSchema )
	: ICFSecISOCtryCcyObj()
	{
		schema = argSchema;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFSecISOCtryCcyObj::~CFSecISOCtryCcyObj() {
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

	cfsec::CFSecISOCtryCcyBuff* CFSecISOCtryCcyObj::getBuff() {
		if( buff == NULL ) {
			if( isNew ) {
				buff = new cfsec::CFSecISOCtryCcyBuff();
				copyBuffToPKey();
			}
			else {
				// Read the data buff via the backing store
				buff = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableISOCtryCcy()->readDerivedByIdIdx( dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getAuthorization(),
						getPKey()->getRequiredISOCtryId(),
						getPKey()->getRequiredISOCcyId() );
			}
		}
		return( buff );
	}

	void CFSecISOCtryCcyObj::setBuff( cfsec::CFSecISOCtryCcyBuff* value ) {
		if( ( buff != NULL ) && ( buff != value ) ) {
			delete buff;
			buff = NULL;
		}
		buff = value;
		if( buff != NULL ) {
			copyBuffToPKey();
		}
	}

	const std::string& CFSecISOCtryCcyObj::getClassName() const {
		return( CLASS_NAME );
	}

	const classcode_t CFSecISOCtryCcyObj::getClassCode() const {
		return( CLASS_CODE );
	}

	bool CFSecISOCtryCcyObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfsec::CFSecISOCtryCcyBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFSecISOCtryCcyObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecISOCtryCcyObj" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_ISOCtryId( "ISOCtryId" );
		static const std::string S_ISOCcyId( "ISOCcyId" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFSecISOCtryCcyObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFSecISOCtryCcyObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFSecISOCtryCcyObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFSecISOCtryCcyObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFSecISOCtryCcyObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_ISOCtryId, CFSecISOCtryCcyObj::getRequiredISOCtryId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_ISOCcyId, CFSecISOCtryCcyObj::getRequiredISOCcyId() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	std::string CFSecISOCtryCcyObj::getObjName() {
		std::string objName( CLASS_NAME );
		int16_t val = getRequiredISOCcyId();
		objName = cflib::CFLibXmlUtil::formatInt16( val );
		return( objName );
	}

	const std::string CFSecISOCtryCcyObj::getGenDefName() {
		return( cfsec::CFSecISOCtryCcyBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFSecISOCtryCcyObj::getScope() {
		cfsec::ICFSecISOCtryObj* scope = getRequiredContainerCtry();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFSecISOCtryCcyObj::getObjScope() {
		cfsec::ICFSecISOCtryObj* scope = getRequiredContainerCtry();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFSecISOCtryCcyObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFSecISOCtryCcyObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFSecISOCtryCcyObj::getNamedObject( const std::string& objName ) {
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

	std::string CFSecISOCtryCcyObj::getObjQualifiedName() {
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

	std::string CFSecISOCtryCcyObj::getObjFullName() {
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

	cfsec::ICFSecISOCtryCcyObj* CFSecISOCtryCcyObj::realize() {
		cfsec::ICFSecISOCtryCcyObj* retobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getISOCtryCcyTableObj()->realizeISOCtryCcy(
			(cfsec::ICFSecISOCtryCcyObj*)this );
		return( dynamic_cast<cfsec::ICFSecISOCtryCcyObj*>( retobj ) );
	}

	cfsec::ICFSecISOCtryCcyObj* CFSecISOCtryCcyObj::read( bool forceRead ) {
		cfsec::ICFSecISOCtryCcyObj* retobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getISOCtryCcyTableObj()->readISOCtryCcyByIdIdx( getISOCtryCcyBuff()->getRequiredISOCtryId(),
		getISOCtryCcyBuff()->getRequiredISOCcyId(), forceRead );
		return( dynamic_cast<cfsec::ICFSecISOCtryCcyObj*>( retobj ) );
	}

	cfsec::ICFSecISOCtryCcyTableObj* CFSecISOCtryCcyObj::getISOCtryCcyTable() {
		return( dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getISOCtryCcyTableObj() );
	}

	cfsec::ICFSecSchemaObj* CFSecISOCtryCcyObj::getSchema() {
		return( schema );
	}

	void CFSecISOCtryCcyObj::setSchema( cfsec::ICFSecSchemaObj* value ) {
		schema = value;
	}

	cfsec::CFSecISOCtryCcyPKey* CFSecISOCtryCcyObj::getPKey() {
		if( pKey == NULL ) {
			pKey = new cfsec::CFSecISOCtryCcyPKey();
		}
		return( pKey );
	}

	void CFSecISOCtryCcyObj::setPKey( cfsec::CFSecISOCtryCcyPKey* value ) {
		if( ( pKey != NULL ) && ( pKey != value ) ) {
			delete pKey;
			pKey = NULL;
		}
		if( value != NULL ) {
			pKey = new cfsec::CFSecISOCtryCcyPKey();
			*pKey = *value;
			copyPKeyToBuff();
		}
	}

	bool CFSecISOCtryCcyObj::getIsNew() {
		return( isNew );
	}

	void CFSecISOCtryCcyObj::setIsNew( bool value ) {
		isNew = value;
	}

	cfsec::ICFSecISOCtryCcyEditObj* CFSecISOCtryCcyObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_EditAlreadyOpen( "An edit is already open" );
		if( edit != NULL ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_ProcName, S_EditAlreadyOpen );
		}
		if( ! getIsNew() ) {
			cfsec::ICFSecISOCtryCcyObj* lockobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getISOCtryCcyTableObj()->lockISOCtryCcy( getPKey() );
			lockobj->realize();
		}
		edit = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getISOCtryCcyTableObj()->newEditInstance( this );
		return( dynamic_cast<cfsec::ICFSecISOCtryCcyEditObj*>( edit ) );
	}

	void CFSecISOCtryCcyObj::endEdit() {
		if( edit != NULL ) {
			delete edit;
			edit = NULL;
		}
	}

	cfsec::ICFSecISOCtryCcyEditObj* CFSecISOCtryCcyObj::getEdit() {
		return( edit );
	}

	cfsec::ICFSecISOCtryCcyEditObj* CFSecISOCtryCcyObj::getISOCtryCcyEdit() {
		return( dynamic_cast<cfsec::ICFSecISOCtryCcyEditObj*>( edit ) );
	}

	cfsec::ICFSecSecUserObj* CFSecISOCtryCcyObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getISOCtryCcyBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFSecISOCtryCcyObj::getCreatedAt() {
		return( getISOCtryCcyBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFSecISOCtryCcyObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getISOCtryCcyBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFSecISOCtryCcyObj::getUpdatedAt() {
		return( getISOCtryCcyBuff()->getUpdatedAt() );
	}

	void CFSecISOCtryCcyObj::copyPKeyToBuff() {
		cfsec::CFSecISOCtryCcyPKey* tablePKey = getPKey();
		cfsec::CFSecISOCtryCcyBuff* tableBuff = getISOCtryCcyEditBuff();
		if( tableBuff != NULL ) {
			tableBuff->setRequiredISOCtryId( tablePKey->getRequiredISOCtryId() );
			tableBuff->setRequiredISOCcyId( tablePKey->getRequiredISOCcyId() );
		}
		if( edit != NULL ) {
			edit->copyPKeyToBuff();
		}
	}

	void CFSecISOCtryCcyObj::copyBuffToPKey() {
		cfsec::CFSecISOCtryCcyPKey* tablePKey = getPKey();
		cfsec::CFSecISOCtryCcyBuff* tableBuff = getISOCtryCcyBuff();
		tablePKey->setRequiredISOCtryId( tableBuff->getRequiredISOCtryId() );
		tablePKey->setRequiredISOCcyId( tableBuff->getRequiredISOCcyId() );
	}

}
