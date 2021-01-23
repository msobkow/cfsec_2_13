// Description: C++18 edit object instance implementation for CFSec SysCluster.

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
#include <cfsecobj/CFSecSysClusterObj.hpp>
#include <cfsecobj/CFSecSysClusterEditObj.hpp>


namespace cfsec {

	const std::string CFSecSysClusterEditObj::CLASS_NAME( "CFSecSysClusterEditObj" );

	CFSecSysClusterEditObj::CFSecSysClusterEditObj( cfsec::ICFSecSysClusterObj* argOrig )
	: ICFSecSysClusterEditObj()
	{
		static const std::string S_ProcName( "CFSecSysClusterEditObj-construct" );
		static const std::string S_OrigBuff( "origBuff" );
		orig = argOrig;
		cfsec::CFSecSysClusterBuff* origBuff = orig->getBuff();
		if( origBuff == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_OrigBuff );
		}
		buff = dynamic_cast<cfsec::CFSecSysClusterBuff*>( origBuff->clone() );
	}

	CFSecSysClusterEditObj::~CFSecSysClusterEditObj() {
		orig = NULL;
		if( buff != NULL ) {
			delete buff;
			buff = NULL;
		}

	}

	const std::string& CFSecSysClusterEditObj::getClassName() const {
		return( CLASS_NAME );
	}

	const classcode_t CFSecSysClusterEditObj::getClassCode() const {
		return( cfsec::CFSecSysClusterBuff::CLASS_CODE );
	}

	bool CFSecSysClusterEditObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfsec::CFSecSysClusterBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFSecSysClusterEditObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecSysClusterEditObj" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_SingletonId( "SingletonId" );
		static const std::string S_ClusterId( "ClusterId" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFSecSysClusterEditObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_SingletonId, CFSecSysClusterEditObj::getRequiredSingletonId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_ClusterId, CFSecSysClusterEditObj::getRequiredClusterId() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	int32_t CFSecSysClusterEditObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	void CFSecSysClusterEditObj::setRequiredRevision( int32_t value ) {
		getSysClusterEditBuff()->setRequiredRevision( value );
	}

	std::string CFSecSysClusterEditObj::getObjName() {
		std::string objName( CLASS_NAME ); objName;
		int32_t val = getRequiredSingletonId();
		objName = cflib::CFLibXmlUtil::formatInt32( val );
		return( objName );
	}

	const std::string CFSecSysClusterEditObj::getGenDefName() {
		return( cfsec::CFSecSysClusterBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFSecSysClusterEditObj::getScope() {
		cfsec::ICFSecClusterObj* scope = getRequiredContainerCluster();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFSecSysClusterEditObj::getObjScope() {
		cfsec::ICFSecClusterObj* scope = getRequiredContainerCluster();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFSecSysClusterEditObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFSecSysClusterEditObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFSecSysClusterEditObj::getNamedObject( const std::string& objName ) {
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

	std::string CFSecSysClusterEditObj::getObjQualifiedName() {
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

	std::string CFSecSysClusterEditObj::getObjFullName() {
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

	cfsec::ICFSecSysClusterObj* CFSecSysClusterEditObj::realize() {
		// We realize this so that it's buffer will get copied to orig during realization
		cfsec::ICFSecSysClusterObj* retobj = getSchema()->getSysClusterTableObj()->realizeSysCluster( dynamic_cast<cfsec::ICFSecSysClusterObj*>( this ) );
		return( retobj );
	}

	cfsec::ICFSecSysClusterObj* CFSecSysClusterEditObj::read( bool forceRead ) {
		cfsec::ICFSecSysClusterObj* retval = getOrigAsSysCluster()->read( forceRead );
		if( retval != orig ) {
			throw cflib::CFLibUsageException( CLASS_NAME,
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	cfsec::ICFSecSysClusterObj* CFSecSysClusterEditObj::create() {
		cfsec::ICFSecSysClusterObj* retobj = dynamic_cast<cfsec::ICFSecSchemaObj*>( getOrigAsSysCluster()->getSchema() )->getSysClusterTableObj()->createSysCluster( this );
		// Note that this instance is usually discarded during the creation process,
		// and retobj now references the cached instance of the created object.
		return( retobj );
	}

	cfsec::ICFSecSysClusterEditObj* CFSecSysClusterEditObj::update() {
		getSchema()->getSysClusterTableObj()->updateSysCluster( this );
		return( NULL );
	}

	cfsec::ICFSecSysClusterEditObj* CFSecSysClusterEditObj::deleteInstance() {
		static const std::string S_MethodName( "deleteInstance" );
		static const std::string S_CannotDeleteNewInstance( "Cannot delete a new instance" );
		if( getIsNew() ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_MethodName, S_CannotDeleteNewInstance );
		}
		getSchema()->getSysClusterTableObj()->deleteSysCluster( this );
		return( NULL );
	}

	cfsec::ICFSecSysClusterTableObj* CFSecSysClusterEditObj::getSysClusterTable() {
		return( orig->getSchema()->getSysClusterTableObj() );
	}

	cfsec::ICFSecSysClusterEditObj* CFSecSysClusterEditObj::getEdit() {
		return( this );
	}

	cfsec::ICFSecSysClusterEditObj* CFSecSysClusterEditObj::getSysClusterEdit() {
		return( (cfsec::ICFSecSysClusterEditObj*)this );
	}

	cfsec::ICFSecSysClusterEditObj* CFSecSysClusterEditObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_Message( "Cannot edit an edition" );
		throw cflib::CFLibUsageException( CLASS_NAME,
			S_ProcName,
			S_Message );
	}

	void CFSecSysClusterEditObj::endEdit() {
		orig->endEdit();
	}

	cfsec::ICFSecSysClusterObj* CFSecSysClusterEditObj::getOrig() {
		return( orig );
	}

	cfsec::ICFSecSysClusterObj* CFSecSysClusterEditObj::getOrigAsSysCluster() {
		return( dynamic_cast<cfsec::ICFSecSysClusterObj*>( orig ) );
	}

	cfsec::ICFSecSchemaObj* CFSecSysClusterEditObj::getSchema() {
		return( orig->getSchema() );
	}

	cfsec::CFSecSysClusterBuff* CFSecSysClusterEditObj::getBuff() {
		return( buff );
	}

	void CFSecSysClusterEditObj::setBuff( cfsec::CFSecSysClusterBuff* value ) {
		if( buff != value ) {
			if( ( buff != NULL ) && ( buff != value ) ) {
				delete buff;
				buff = NULL;
			}
			buff = value;
		}
	}

	cfsec::CFSecSysClusterPKey* CFSecSysClusterEditObj::getPKey() {
		return( orig->getPKey() );
	}

	void CFSecSysClusterEditObj::setPKey( cfsec::CFSecSysClusterPKey* value ) {
		if( orig->getPKey() != value ) {
			orig->setPKey( value );
		}
		copyPKeyToBuff();
	}

	bool CFSecSysClusterEditObj::getIsNew() {
		return( orig->getIsNew() );
	}

	void CFSecSysClusterEditObj::setIsNew( bool value ) {
		orig->setIsNew( value );
	}

	const int32_t CFSecSysClusterEditObj::getRequiredSingletonId() {
		return( getPKey()->getRequiredSingletonId() );
	}

	const int32_t* CFSecSysClusterEditObj::getRequiredSingletonIdReference() {
		return( getPKey()->getRequiredSingletonIdReference() );
	}

	void CFSecSysClusterEditObj::setRequiredSingletonId( const int32_t value ) {
		if( getPKey()->getRequiredSingletonId() != value ) {
			getPKey()->setRequiredSingletonId( value );
		}
		if( getSysClusterBuff()->getRequiredSingletonId() != value ) {
			getSysClusterEditBuff()->setRequiredSingletonId( value );
		}
	}

	const int64_t CFSecSysClusterEditObj::getRequiredClusterId() {
		return( getSysClusterBuff()->getRequiredClusterId() );
	}

	const int64_t* CFSecSysClusterEditObj::getRequiredClusterIdReference() {
		return( getSysClusterBuff()->getRequiredClusterIdReference() );
	}

	cfsec::ICFSecClusterObj* CFSecSysClusterEditObj::getRequiredContainerCluster( bool forceRead ) {
		cfsec::ICFSecClusterObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<cfsec::ICFSecSchemaObj*>( getOrigAsSysCluster()->getSchema() )->getClusterTableObj()->readClusterByIdIdx( getSysClusterBuff()->getRequiredClusterId() );
		}
		return( retobj );
	}

	void CFSecSysClusterEditObj::setRequiredContainerCluster( cfsec::ICFSecClusterObj* value ) {
			
			if( value != NULL ) {
				getSysClusterEditBuff()->setRequiredClusterId( value->getRequiredId() );
			}
		}

	void CFSecSysClusterEditObj::copyPKeyToBuff() {
		cfsec::CFSecSysClusterPKey* tablePKey = getPKey();
		cfsec::CFSecSysClusterBuff* tableBuff = getSysClusterEditBuff();
		tableBuff->setRequiredSingletonId( tablePKey->getRequiredSingletonId() );
	}

	void CFSecSysClusterEditObj::copyBuffToPKey() {
		cfsec::CFSecSysClusterPKey* tablePKey = getPKey();
		cfsec::CFSecSysClusterBuff* tableBuff = getSysClusterBuff();
		tablePKey->setRequiredSingletonId( tableBuff->getRequiredSingletonId() );
	}

	void CFSecSysClusterEditObj::copyBuffToOrig() {
		cfsec::CFSecSysClusterBuff* origBuff = getOrigAsSysCluster()->getSysClusterEditBuff();
		cfsec::CFSecSysClusterBuff* myBuff = getSysClusterBuff();
		if( origBuff != myBuff ) {
			*origBuff = *myBuff;
		}
	}

	void CFSecSysClusterEditObj::copyOrigToBuff() {
		cfsec::CFSecSysClusterBuff* origBuff = getOrigAsSysCluster()->getSysClusterBuff();
		cfsec::CFSecSysClusterBuff* myBuff = getSysClusterEditBuff();
		if( origBuff != myBuff ) {
			*myBuff = *origBuff;
		}
	}

}
