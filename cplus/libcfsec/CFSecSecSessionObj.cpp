// Description: C++18 base object instance implementation for CFSec SecSession.

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
#include <cfsecobj/CFSecSecSessionObj.hpp>

namespace cfsec {

	const std::string CFSecSecSessionObj::CLASS_NAME( "CFSecSecSessionObj" );
	const classcode_t CFSecSecSessionObj::CLASS_CODE = 0xa010L;

	int32_t CFSecSecSessionObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	const uuid_ptr_t CFSecSecSessionObj::getRequiredSecSessionId() {
		return( getPKey()->getRequiredSecSessionId() );
	}

	const uuid_ptr_t CFSecSecSessionObj::getRequiredSecSessionIdReference() {
		return( getPKey()->getRequiredSecSessionIdReference() );
	}

	const uuid_ptr_t CFSecSecSessionObj::getRequiredSecUserId() {
		return( getSecSessionBuff()->getRequiredSecUserId() );
	}

	const uuid_ptr_t CFSecSecSessionObj::getRequiredSecUserIdReference() {
		return( getSecSessionBuff()->getRequiredSecUserIdReference() );
	}

	bool CFSecSecSessionObj::isOptionalSecDevNameNull() {
		return( getSecSessionBuff()->isOptionalSecDevNameNull() );
	}

	const std::string& CFSecSecSessionObj::getOptionalSecDevNameValue() {
		return( getSecSessionBuff()->getOptionalSecDevNameValue() );
	}

	const std::string* CFSecSecSessionObj::getOptionalSecDevNameReference() {
		return( getSecSessionBuff()->getOptionalSecDevNameReference() );
	}

	const std::chrono::system_clock::time_point& CFSecSecSessionObj::getRequiredStart() {
		return( getSecSessionBuff()->getRequiredStart() );
	}

	const std::chrono::system_clock::time_point* CFSecSecSessionObj::getRequiredStartReference() {
		return( getSecSessionBuff()->getRequiredStartReference() );
	}

	bool CFSecSecSessionObj::isOptionalFinishNull() {
		return( getSecSessionBuff()->isOptionalFinishNull() );
	}

	const std::chrono::system_clock::time_point& CFSecSecSessionObj::getOptionalFinishValue() {
		return( getSecSessionBuff()->getOptionalFinishValue() );
	}

	const std::chrono::system_clock::time_point* CFSecSecSessionObj::getOptionalFinishReference() {
		return( getSecSessionBuff()->getOptionalFinishReference() );
	}

	bool CFSecSecSessionObj::isOptionalSecProxyIdNull() {
		return( getSecSessionBuff()->isOptionalSecProxyIdNull() );
	}

	const uuid_ptr_t CFSecSecSessionObj::getOptionalSecProxyIdValue() {
		return( getSecSessionBuff()->getOptionalSecProxyIdValue() );
	}

	const uuid_ptr_t CFSecSecSessionObj::getOptionalSecProxyIdReference() {
		return( getSecSessionBuff()->getOptionalSecProxyIdReference() );
	}


	cfsec::ICFSecSecUserObj* CFSecSecSessionObj::getRequiredContainerSecUser( bool forceRead ) {
		cfsec::ICFSecSecUserObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getSecSessionBuff()->getRequiredSecUserId(), forceRead );
		}
		return( retobj );
	}

	cfsec::ICFSecSecUserObj* CFSecSecSessionObj::getRequiredParentSecProxy( bool forceRead ) {
		cfsec::ICFSecSecUserObj* retobj = NULL;
		bool anyMissing = false;
			if( getSecSessionBuff()->isOptionalSecProxyIdNull() ) {
				anyMissing = true;
			}
		if( ! anyMissing ) {
			retobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getSecSessionBuff()->getOptionalSecProxyIdValue(), forceRead );
		}
		return( retobj );
	}

	CFSecSecSessionObj::CFSecSecSessionObj()
	: ICFSecSecSessionObj()
	{
		schema = NULL;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFSecSecSessionObj::CFSecSecSessionObj( cfsec::ICFSecSchemaObj* argSchema )
	: ICFSecSecSessionObj()
	{
		schema = argSchema;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFSecSecSessionObj::~CFSecSecSessionObj() {
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

	cfsec::CFSecSecSessionBuff* CFSecSecSessionObj::getBuff() {
		if( buff == NULL ) {
			if( isNew ) {
				buff = new cfsec::CFSecSecSessionBuff();
				copyBuffToPKey();
			}
			else {
				// Read the data buff via the backing store
				buff = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecSession()->readDerivedByIdIdx( dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getAuthorization(),
						getPKey()->getRequiredSecSessionId() );
			}
		}
		return( buff );
	}

	void CFSecSecSessionObj::setBuff( cfsec::CFSecSecSessionBuff* value ) {
		if( ( buff != NULL ) && ( buff != value ) ) {
			delete buff;
			buff = NULL;
		}
		buff = value;
		if( buff != NULL ) {
			copyBuffToPKey();
		}
	}

	const std::string& CFSecSecSessionObj::getClassName() const {
		return( CLASS_NAME );
	}

	const classcode_t CFSecSecSessionObj::getClassCode() const {
		return( CLASS_CODE );
	}

	bool CFSecSecSessionObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfsec::CFSecSecSessionBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFSecSecSessionObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecSecSessionObj" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_SecSessionId( "SecSessionId" );
		static const std::string S_SecUserId( "SecUserId" );
		static const std::string S_SecDevName( "SecDevName" );
		static const std::string S_Start( "Start" );
		static const std::string S_Finish( "Finish" );
		static const std::string S_SecProxyId( "SecProxyId" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFSecSecSessionObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_SecSessionId, CFSecSecSessionObj::getRequiredSecSessionId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_SecUserId, CFSecSecSessionObj::getRequiredSecUserId() ) );
		if( ! CFSecSecSessionObj::isOptionalSecDevNameNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_SecDevName, CFSecSecSessionObj::getOptionalSecDevNameValue() ) );
		}
		ret.append( cflib::CFLibXmlUtil::formatRequiredTimestamp( &S_Space, S_Start, CFSecSecSessionObj::getRequiredStart() ) );
		if( ! CFSecSecSessionObj::isOptionalFinishNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredTimestamp( &S_Space, S_Finish, CFSecSecSessionObj::getOptionalFinishValue() ) );
		}
		if( ! CFSecSecSessionObj::isOptionalSecProxyIdNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_SecProxyId, CFSecSecSessionObj::getOptionalSecProxyIdValue() ) );
		}
		ret.append( S_Postamble );
		return( ret );
	}

	std::string CFSecSecSessionObj::getObjName() {
		std::string objName( CLASS_NAME );
		const uuid_ptr_t val = getRequiredSecSessionId();
		objName = cflib::CFLibXmlUtil::formatUuid( val );
		return( objName );
	}

	const std::string CFSecSecSessionObj::getGenDefName() {
		return( cfsec::CFSecSecSessionBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFSecSecSessionObj::getScope() {
		cfsec::ICFSecSecUserObj* scope = getRequiredContainerSecUser();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFSecSecSessionObj::getObjScope() {
		cfsec::ICFSecSecUserObj* scope = getRequiredContainerSecUser();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFSecSecSessionObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFSecSecSessionObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFSecSecSessionObj::getNamedObject( const std::string& objName ) {
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

	std::string CFSecSecSessionObj::getObjQualifiedName() {
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

	std::string CFSecSecSessionObj::getObjFullName() {
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

	cfsec::ICFSecSecSessionObj* CFSecSecSessionObj::realize() {
		cfsec::ICFSecSecSessionObj* retobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecSessionTableObj()->realizeSecSession(
			(cfsec::ICFSecSecSessionObj*)this );
		return( dynamic_cast<cfsec::ICFSecSecSessionObj*>( retobj ) );
	}

	cfsec::ICFSecSecSessionObj* CFSecSecSessionObj::read( bool forceRead ) {
		cfsec::ICFSecSecSessionObj* retobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecSessionTableObj()->readSecSessionByIdIdx( getSecSessionBuff()->getRequiredSecSessionId(), forceRead );
		return( dynamic_cast<cfsec::ICFSecSecSessionObj*>( retobj ) );
	}

	cfsec::ICFSecSecSessionTableObj* CFSecSecSessionObj::getSecSessionTable() {
		return( dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecSessionTableObj() );
	}

	cfsec::ICFSecSchemaObj* CFSecSecSessionObj::getSchema() {
		return( schema );
	}

	void CFSecSecSessionObj::setSchema( cfsec::ICFSecSchemaObj* value ) {
		schema = value;
	}

	cfsec::CFSecSecSessionPKey* CFSecSecSessionObj::getPKey() {
		if( pKey == NULL ) {
			pKey = new cfsec::CFSecSecSessionPKey();
		}
		return( pKey );
	}

	void CFSecSecSessionObj::setPKey( cfsec::CFSecSecSessionPKey* value ) {
		if( ( pKey != NULL ) && ( pKey != value ) ) {
			delete pKey;
			pKey = NULL;
		}
		if( value != NULL ) {
			pKey = new cfsec::CFSecSecSessionPKey();
			*pKey = *value;
			copyPKeyToBuff();
		}
	}

	bool CFSecSecSessionObj::getIsNew() {
		return( isNew );
	}

	void CFSecSecSessionObj::setIsNew( bool value ) {
		isNew = value;
	}

	cfsec::ICFSecSecSessionEditObj* CFSecSecSessionObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_EditAlreadyOpen( "An edit is already open" );
		if( edit != NULL ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_ProcName, S_EditAlreadyOpen );
		}
		if( ! getIsNew() ) {
			cfsec::ICFSecSecSessionObj* lockobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecSessionTableObj()->lockSecSession( getPKey() );
			lockobj->realize();
		}
		edit = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecSessionTableObj()->newEditInstance( this );
		return( dynamic_cast<cfsec::ICFSecSecSessionEditObj*>( edit ) );
	}

	void CFSecSecSessionObj::endEdit() {
		if( edit != NULL ) {
			delete edit;
			edit = NULL;
		}
	}

	cfsec::ICFSecSecSessionEditObj* CFSecSecSessionObj::getEdit() {
		return( edit );
	}

	cfsec::ICFSecSecSessionEditObj* CFSecSecSessionObj::getSecSessionEdit() {
		return( dynamic_cast<cfsec::ICFSecSecSessionEditObj*>( edit ) );
	}

	void CFSecSecSessionObj::copyPKeyToBuff() {
		cfsec::CFSecSecSessionPKey* tablePKey = getPKey();
		cfsec::CFSecSecSessionBuff* tableBuff = getSecSessionEditBuff();
		if( tableBuff != NULL ) {
			tableBuff->setRequiredSecSessionId( tablePKey->getRequiredSecSessionId() );
		}
		if( edit != NULL ) {
			edit->copyPKeyToBuff();
		}
	}

	void CFSecSecSessionObj::copyBuffToPKey() {
		cfsec::CFSecSecSessionPKey* tablePKey = getPKey();
		cfsec::CFSecSecSessionBuff* tableBuff = getSecSessionBuff();
		tablePKey->setRequiredSecSessionId( tableBuff->getRequiredSecSessionId() );
	}

}
