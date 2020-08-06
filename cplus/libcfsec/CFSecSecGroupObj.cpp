// Description: C++18 base object instance implementation for CFSec SecGroup.

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
#include <cfsecobj/CFSecSecGroupObj.hpp>

namespace cfsec {

	const std::string CFSecSecGroupObj::CLASS_NAME( "CFSecSecGroupObj" );
	const classcode_t CFSecSecGroupObj::CLASS_CODE = 0xa00cL;

	int32_t CFSecSecGroupObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	const int64_t CFSecSecGroupObj::getRequiredClusterId() {
		return( getPKey()->getRequiredClusterId() );
	}

	const int64_t* CFSecSecGroupObj::getRequiredClusterIdReference() {
		return( getPKey()->getRequiredClusterIdReference() );
	}

	const int32_t CFSecSecGroupObj::getRequiredSecGroupId() {
		return( getPKey()->getRequiredSecGroupId() );
	}

	const int32_t* CFSecSecGroupObj::getRequiredSecGroupIdReference() {
		return( getPKey()->getRequiredSecGroupIdReference() );
	}

	const std::string& CFSecSecGroupObj::getRequiredName() {
		return( getSecGroupBuff()->getRequiredName() );
	}

	const std::string* CFSecSecGroupObj::getRequiredNameReference() {
		return( getSecGroupBuff()->getRequiredNameReference() );
	}

	const bool CFSecSecGroupObj::getRequiredIsVisible() {
		return( getSecGroupBuff()->getRequiredIsVisible() );
	}

	const bool* CFSecSecGroupObj::getRequiredIsVisibleReference() {
		return( getSecGroupBuff()->getRequiredIsVisibleReference() );
	}


	cfsec::ICFSecClusterObj* CFSecSecGroupObj::getRequiredContainerCluster( bool forceRead ) {
		cfsec::ICFSecClusterObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getClusterTableObj()->readClusterByIdIdx( getPKey()->getRequiredClusterId(), forceRead );
		}
		return( retobj );
	}

	std::vector<cfsec::ICFSecSecGrpIncObj*> CFSecSecGroupObj::getOptionalComponentsInclude( bool forceRead ) {
		std::vector<cfsec::ICFSecSecGrpIncObj*> retval;
		retval = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecGrpIncTableObj()->readSecGrpIncByGroupIdx( getPKey()->getRequiredClusterId(),
					getPKey()->getRequiredSecGroupId(),
			forceRead );
		return( retval );
	}

	std::vector<cfsec::ICFSecSecGrpMembObj*> CFSecSecGroupObj::getOptionalComponentsMember( bool forceRead ) {
		std::vector<cfsec::ICFSecSecGrpMembObj*> retval;
		retval = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecGrpMembTableObj()->readSecGrpMembByGroupIdx( getPKey()->getRequiredClusterId(),
					getPKey()->getRequiredSecGroupId(),
			forceRead );
		return( retval );
	}

	std::vector<cfsec::ICFSecSecGrpIncObj*> CFSecSecGroupObj::getRequiredChildrenIncByGroup( bool forceRead ) {
		std::vector<cfsec::ICFSecSecGrpIncObj*> retval;
		retval = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecGrpIncTableObj()->readSecGrpIncByIncludeIdx( getPKey()->getRequiredClusterId(),
					getPKey()->getRequiredSecGroupId(),
			forceRead );
		return( retval );
	}

	std::vector<cfsec::ICFSecSecGroupFormObj*> CFSecSecGroupObj::getOptionalComponentsForm( bool forceRead ) {
		std::vector<cfsec::ICFSecSecGroupFormObj*> retval;
		retval = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecGroupFormTableObj()->readSecGroupFormByGroupIdx( getPKey()->getRequiredClusterId(),
					getPKey()->getRequiredSecGroupId(),
			forceRead );
		return( retval );
	}

	CFSecSecGroupObj::CFSecSecGroupObj()
	: ICFSecSecGroupObj()
	{
		schema = NULL;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFSecSecGroupObj::CFSecSecGroupObj( cfsec::ICFSecSchemaObj* argSchema )
	: ICFSecSecGroupObj()
	{
		schema = argSchema;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFSecSecGroupObj::~CFSecSecGroupObj() {
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

	cfsec::CFSecSecGroupBuff* CFSecSecGroupObj::getBuff() {
		if( buff == NULL ) {
			if( isNew ) {
				buff = new cfsec::CFSecSecGroupBuff();
				copyBuffToPKey();
			}
			else {
				// Read the data buff via the backing store
				buff = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecGroup()->readDerivedByIdIdx( dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getAuthorization(),
						getPKey()->getRequiredClusterId(),
						getPKey()->getRequiredSecGroupId() );
			}
		}
		return( buff );
	}

	void CFSecSecGroupObj::setBuff( cfsec::CFSecSecGroupBuff* value ) {
		if( ( buff != NULL ) && ( buff != value ) ) {
			delete buff;
			buff = NULL;
		}
		buff = value;
		if( buff != NULL ) {
			copyBuffToPKey();
		}
	}

	const std::string& CFSecSecGroupObj::getClassName() const {
		return( CLASS_NAME );
	}

	const classcode_t CFSecSecGroupObj::getClassCode() const {
		return( CLASS_CODE );
	}

	bool CFSecSecGroupObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfsec::CFSecSecGroupBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFSecSecGroupObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecSecGroupObj" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_ClusterId( "ClusterId" );
		static const std::string S_SecGroupId( "SecGroupId" );
		static const std::string S_Name( "Name" );
		static const std::string S_IsVisible( "IsVisible" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFSecSecGroupObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFSecSecGroupObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFSecSecGroupObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFSecSecGroupObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFSecSecGroupObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_ClusterId, CFSecSecGroupObj::getRequiredClusterId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_SecGroupId, CFSecSecGroupObj::getRequiredSecGroupId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Name, CFSecSecGroupObj::getRequiredName() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredBoolean( &S_Space, S_IsVisible, CFSecSecGroupObj::getRequiredIsVisible() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	std::string CFSecSecGroupObj::getObjName() {
		std::string objName( CLASS_NAME );
		objName.clear();
		objName.append( getRequiredName() );
		return( objName );
	}

	const std::string CFSecSecGroupObj::getGenDefName() {
		return( cfsec::CFSecSecGroupBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFSecSecGroupObj::getScope() {
		cfsec::ICFSecClusterObj* scope = getRequiredContainerCluster();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFSecSecGroupObj::getObjScope() {
		cfsec::ICFSecClusterObj* scope = getRequiredContainerCluster();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFSecSecGroupObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFSecSecGroupObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFSecSecGroupObj::getNamedObject( const std::string& objName ) {
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

	std::string CFSecSecGroupObj::getObjQualifiedName() {
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

	std::string CFSecSecGroupObj::getObjFullName() {
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

	cfsec::ICFSecSecGroupObj* CFSecSecGroupObj::realize() {
		cfsec::ICFSecSecGroupObj* retobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecGroupTableObj()->realizeSecGroup(
			(cfsec::ICFSecSecGroupObj*)this );
		return( dynamic_cast<cfsec::ICFSecSecGroupObj*>( retobj ) );
	}

	cfsec::ICFSecSecGroupObj* CFSecSecGroupObj::read( bool forceRead ) {
		cfsec::ICFSecSecGroupObj* retobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecGroupTableObj()->readSecGroupByIdIdx( getSecGroupBuff()->getRequiredClusterId(),
		getSecGroupBuff()->getRequiredSecGroupId(), forceRead );
		return( dynamic_cast<cfsec::ICFSecSecGroupObj*>( retobj ) );
	}

	cfsec::ICFSecSecGroupTableObj* CFSecSecGroupObj::getSecGroupTable() {
		return( dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecGroupTableObj() );
	}

	cfsec::ICFSecSchemaObj* CFSecSecGroupObj::getSchema() {
		return( schema );
	}

	void CFSecSecGroupObj::setSchema( cfsec::ICFSecSchemaObj* value ) {
		schema = value;
	}

	cfsec::CFSecSecGroupPKey* CFSecSecGroupObj::getPKey() {
		if( pKey == NULL ) {
			pKey = new cfsec::CFSecSecGroupPKey();
		}
		return( pKey );
	}

	void CFSecSecGroupObj::setPKey( cfsec::CFSecSecGroupPKey* value ) {
		if( ( pKey != NULL ) && ( pKey != value ) ) {
			delete pKey;
			pKey = NULL;
		}
		if( value != NULL ) {
			pKey = new cfsec::CFSecSecGroupPKey();
			*pKey = *value;
			copyPKeyToBuff();
		}
	}

	bool CFSecSecGroupObj::getIsNew() {
		return( isNew );
	}

	void CFSecSecGroupObj::setIsNew( bool value ) {
		isNew = value;
	}

	cfsec::ICFSecSecGroupEditObj* CFSecSecGroupObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_EditAlreadyOpen( "An edit is already open" );
		if( edit != NULL ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_ProcName, S_EditAlreadyOpen );
		}
		if( ! getIsNew() ) {
			cfsec::ICFSecSecGroupObj* lockobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecGroupTableObj()->lockSecGroup( getPKey() );
			lockobj->realize();
		}
		edit = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecGroupTableObj()->newEditInstance( this );
		return( dynamic_cast<cfsec::ICFSecSecGroupEditObj*>( edit ) );
	}

	void CFSecSecGroupObj::endEdit() {
		if( edit != NULL ) {
			delete edit;
			edit = NULL;
		}
	}

	cfsec::ICFSecSecGroupEditObj* CFSecSecGroupObj::getEdit() {
		return( edit );
	}

	cfsec::ICFSecSecGroupEditObj* CFSecSecGroupObj::getSecGroupEdit() {
		return( dynamic_cast<cfsec::ICFSecSecGroupEditObj*>( edit ) );
	}

	cfsec::ICFSecSecUserObj* CFSecSecGroupObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getSecGroupBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFSecSecGroupObj::getCreatedAt() {
		return( getSecGroupBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFSecSecGroupObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getSecGroupBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFSecSecGroupObj::getUpdatedAt() {
		return( getSecGroupBuff()->getUpdatedAt() );
	}

	void CFSecSecGroupObj::copyPKeyToBuff() {
		cfsec::CFSecSecGroupPKey* tablePKey = getPKey();
		cfsec::CFSecSecGroupBuff* tableBuff = getSecGroupEditBuff();
		if( tableBuff != NULL ) {
			tableBuff->setRequiredClusterId( tablePKey->getRequiredClusterId() );
			tableBuff->setRequiredSecGroupId( tablePKey->getRequiredSecGroupId() );
		}
		if( edit != NULL ) {
			edit->copyPKeyToBuff();
		}
	}

	void CFSecSecGroupObj::copyBuffToPKey() {
		cfsec::CFSecSecGroupPKey* tablePKey = getPKey();
		cfsec::CFSecSecGroupBuff* tableBuff = getSecGroupBuff();
		tablePKey->setRequiredClusterId( tableBuff->getRequiredClusterId() );
		tablePKey->setRequiredSecGroupId( tableBuff->getRequiredSecGroupId() );
	}

}
