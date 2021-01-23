
// Description: C++18 XML SAX2 Element Handler implementation for SecUser

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
#include <cfsec/ICFSecPublic.hpp>
#include <cfsecobj/ICFSecObjPublic.hpp>
#include <cfsecsaxloader/CFSecSaxLoader.hpp>
#include <cfsecsaxloader/CFSecSaxLoaderSecUserHandler.hpp>

using namespace std;

namespace cfsec {

	const std::string CFSecSaxLoaderSecUserHandler::CLASS_NAME( "CFSecSaxLoaderSecUserHandler" );
	const std::string CFSecSaxLoaderSecUserHandler::S_True( "true" );
	const std::string CFSecSaxLoaderSecUserHandler::S_False( "false" );
	const std::string CFSecSaxLoaderSecUserHandler::S_Yes( "yes" );
	const std::string CFSecSaxLoaderSecUserHandler::S_No( "no" );
	const std::string CFSecSaxLoaderSecUserHandler::S_0( "0" );
	const std::string CFSecSaxLoaderSecUserHandler::S_1( "1" );

	CFSecSaxLoaderSecUserHandler::CFSecSaxLoaderSecUserHandler( cfsec::CFSecSaxLoader* saxLoader )
	: cflib::CFLibXmlCoreElementHandler( saxLoader )
	{
	}

	CFSecSaxLoaderSecUserHandler::~CFSecSaxLoaderSecUserHandler() {
	}

	void CFSecSaxLoaderSecUserHandler::startElement (
		const XMLCh* const uri,
		const XMLCh* const localname,
		const XMLCh* const qname,
		const xercesc::Attributes& attrs )
	{
		const static std::string S_ProcName( "startElement" );
		const static std::string S_SpecificallyId( "Id" );
		const static std::string S_Object( "object" );
		const static std::string S_Uri( "uri" );
		const static std::string S_LocalName( "localname" );
		const static std::string S_GetParser( "getParser()" );
		const static std::string S_GetParserGetSchemaObj( "getParser()->getSchemaObj()" );
		const static std::string S_SchemaLocation( "schemaLocation" );
		const static std::string S_SaxLoaderUseTenant( "saxLoader->useTenant" );
		const static std::string S_QName( "qname" );
		static const std::string S_SecUserId( "SecUserId" );
		static const std::string S_LoginId( "LoginId" );
		static const std::string S_EMailAddress( "EMailAddress" );
		static const std::string S_EMailConfirmUuid( "EMailConfirmUuid" );
		static const std::string S_DfltDevUserId( "DfltDevUserId" );
		static const std::string S_DfltDevName( "DfltDevName" );
		static const std::string S_PasswordHash( "PasswordHash" );
		static const std::string S_PasswordResetUuid( "PasswordResetUuid" );
		static const std::string S_SecDev( "SecDev" );
		static const std::string S_DefDev( "DefDev" );
		static const std::string S_SecSess( "SecSess" );
		static const std::string S_SecProxy( "SecProxy" );
		static const std::string S_SecGrpMemb( "SecGrpMemb" );
		static const std::string S_TSecGrpMemb( "TSecGrpMemb" );
		CFLIB_EXCEPTION_DECLINFO
		const XMLCh* xmlchLocalName = NULL;
		char* cLocalName = NULL;
		std::string* attrLocalName = NULL;
		const XMLCh* xmlchValue = NULL;
		char* cValue = NULL;
		std::string* cppValue = NULL;
		char* cUri = NULL;
		char* cQName = NULL;
		cflib::CFLibXmlCoreContext* curContext = NULL;
		cfsec::CFSecSaxLoader* saxLoader = NULL;
		cfsec::CFSecSaxLoader::LoaderBehaviourEnum loaderBehaviour;
		cfsec::ICFSecSchemaObj* schemaObj = NULL;
		cfsec::ICFSecSecUserObj* tmpBuff = NULL;
		cfsec::ICFSecSecUserEditObj* editBuff = NULL;
		cfsec::ICFSecSecUserEditObj* editSecUser = NULL;
		cfsec::ICFSecSecUserObj* origSecUser = NULL;
		cflib::CFLibXmlCoreContext* parentContext = NULL;
		cflib::ICFLibAnyObj* scopeObj = NULL;
		// Common XML Attributes
		std::string* attrId = NULL;
		// SecUser Attributes
		std::string* attrLoginId = NULL;
		std::string* attrEMailAddress = NULL;
		std::string* attrEMailConfirmUuid = NULL;
		std::string* attrPasswordHash = NULL;
		std::string* attrPasswordResetUuid = NULL;
		std::string* attrDefDev = NULL;
		// SecUser References
		cfsec::ICFSecSecDeviceObj* refDefDev = NULL;
		std::string* natLoginId = NULL;
		std::string* natEMailAddress = NULL;
		uuid_t natEMailConfirmUuid = { 0 };
		std::string* natPasswordHash = NULL;
		uuid_t natPasswordResetUuid = { 0 };
		try {
			if( ( uri == NULL ) || ( *uri == 0 ) ) {
				throw cflib::CFLibEmptyArgumentException( CLASS_NAME,
					S_ProcName,
					1,
					S_Uri );
			}
			if( ( localname == NULL ) || ( *localname == 0 ) ) {
				throw cflib::CFLibEmptyArgumentException( CLASS_NAME,
					S_ProcName,
					2,
					S_LocalName );
			}
			if( ( qname == NULL ) || ( *qname == 0 ) ) {
				throw cflib::CFLibEmptyArgumentException( CLASS_NAME,
					S_ProcName,
					3,
					S_QName );
			}
			cUri = xercesc::XMLString::transcode( uri );
			cLocalName = xercesc::XMLString::transcode( localname );
			cQName = xercesc::XMLString::transcode( qname );
			std::string cppUri( cUri );
			std::string cppLocalName( cLocalName );
			std::string cppQName( cQName );
			xercesc::XMLString::release( &cUri );
			cUri = NULL;
			xercesc::XMLString::release( &cLocalName );
			cLocalName = NULL;
			xercesc::XMLString::release( &cQName );
			cQName = NULL;
			if( cppQName != cfsec::CFSecSecUserBuff::GENDEFNAME ) {
				std::string Msg( "Expected QName to be '" + cfsec::CFSecSecUserBuff::GENDEFNAME + "'" );
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					Msg );
			}
			// Attribute Extraction
			size_t numAttrs;
			size_t idxAttr;
			saxLoader = dynamic_cast<cfsec::CFSecSaxLoader*>( getParser() );
			if( saxLoader == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_GetParser );
			}

			schemaObj = dynamic_cast<cfsec::ICFSecSchemaObj*>( saxLoader->getSchemaObj() );
			if( schemaObj == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_GetParserGetSchemaObj );
			}

			// Instantiate an edit buffer for the parsed information
			tmpBuff = schemaObj->getSecUserTableObj()->newInstance();
			editBuff = dynamic_cast<cfsec::ICFSecSecUserEditObj*>( tmpBuff->beginEdit() );

			// Extract Attributes
			numAttrs = attrs.getLength();
			for( idxAttr = 0; idxAttr < numAttrs; idxAttr++ ) {
				if( attrLocalName != NULL ) {
					delete attrLocalName;
					attrLocalName = NULL;
				}
				if( cppValue != NULL ) {
					delete cppValue;
					cppValue = NULL;
				}
				xmlchLocalName = attrs.getLocalName( idxAttr );
				if( xmlchLocalName == NULL ) {
					continue;
				}
				cLocalName = xercesc::XMLString::transcode( xmlchLocalName );
				attrLocalName = new std::string( cLocalName );
				xercesc::XMLString::release( &cLocalName );
				cLocalName = NULL;
				xmlchValue = attrs.getValue( idxAttr );
				if( xmlchValue == NULL ) {
					cppValue = NULL;
				}
				else {
					cValue = xercesc::XMLString::transcode( xmlchValue );
					cppValue = new std::string( cValue );
					xercesc::XMLString::release( &cValue );
					cValue = NULL;
				}
				if( *attrLocalName == S_SpecificallyId ) {
					if( attrId != NULL ) {
						throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
							S_ProcName,
							*attrLocalName );
					}
					if( cppValue != NULL ) {
						attrId = new std::string( *cppValue );
					}
				}
				else if( *attrLocalName == S_LoginId ) {
					if( attrLoginId != NULL ) {
						throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
							S_ProcName,
							*attrLocalName );
					}
					if( cppValue != NULL ) {
						attrLoginId = new std::string( *cppValue );
					}
					else {
						attrLoginId = NULL;
					}
				}
				else if( *attrLocalName == S_EMailAddress ) {
					if( attrEMailAddress != NULL ) {
						throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
							S_ProcName,
							*attrLocalName );
					}
					if( cppValue != NULL ) {
						attrEMailAddress = new std::string( *cppValue );
					}
					else {
						attrEMailAddress = NULL;
					}
				}
				else if( *attrLocalName == S_EMailConfirmUuid ) {
					if( attrEMailConfirmUuid != NULL ) {
						throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
							S_ProcName,
							*attrLocalName );
					}
					if( cppValue != NULL ) {
						attrEMailConfirmUuid = new std::string( *cppValue );
					}
					else {
						attrEMailConfirmUuid = NULL;
					}
				}
				else if( *attrLocalName == S_PasswordHash ) {
					if( attrPasswordHash != NULL ) {
						throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
							S_ProcName,
							*attrLocalName );
					}
					if( cppValue != NULL ) {
						attrPasswordHash = new std::string( *cppValue );
					}
					else {
						attrPasswordHash = NULL;
					}
				}
				else if( *attrLocalName == S_PasswordResetUuid ) {
					if( attrPasswordResetUuid != NULL ) {
						throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
							S_ProcName,
							*attrLocalName );
					}
					if( cppValue != NULL ) {
						attrPasswordResetUuid = new std::string( *cppValue );
					}
					else {
						attrPasswordResetUuid = NULL;
					}
				}
				else if( *attrLocalName == S_DefDev ) {
					if( attrDefDev != NULL ) {
						throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
							S_ProcName,
							*attrLocalName );
					}
					if( cppValue != NULL ) {
						attrDefDev = new std::string( *cppValue );
					}
					else {
						attrDefDev = NULL;
					}
				}
				else if( *attrLocalName == S_SchemaLocation ) {
					// ignored
				}
				else {
					throw cflib::CFLibUnrecognizedAttributeException( CLASS_NAME,
						S_ProcName,
						getParser()->getLocationInfo(),
						*attrLocalName );
				}
				if( cppValue != NULL ) {
					delete cppValue;
					cppValue = NULL;
				}
				if( attrLocalName != NULL ) {
					delete attrLocalName;
					attrLocalName = NULL;
				}
			}

			// Ensure that required attributes have values
			if( attrLoginId == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_LoginId );
			}
			if( attrEMailAddress == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_EMailAddress );
			}
			if( attrPasswordHash == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_PasswordHash );
			}

			// Save named attributes to context
			curContext = getParser()->getCurContext();
			if( curContext == NULL ) {
				static const std::string S_CurContext( "getParser()->getCurContext" );
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_CurContext );
			}
			if( attrId != NULL ) {
				curContext->putNamedTag( S_SpecificallyId, *attrId );
			}
			if( attrLoginId != NULL ) {
				curContext->putNamedTag( S_LoginId, *attrLoginId );
			}
			if( attrEMailAddress != NULL ) {
				curContext->putNamedTag( S_EMailAddress, *attrEMailAddress );
			}
			if( attrEMailConfirmUuid != NULL ) {
				curContext->putNamedTag( S_EMailConfirmUuid, *attrEMailConfirmUuid );
			}
			if( attrPasswordHash != NULL ) {
				curContext->putNamedTag( S_PasswordHash, *attrPasswordHash );
			}
			if( attrPasswordResetUuid != NULL ) {
				curContext->putNamedTag( S_PasswordResetUuid, *attrPasswordResetUuid );
			}
			if( attrDefDev != NULL ) {
				curContext->putNamedTag( S_DefDev, *attrDefDev );
			}

			// Convert string attributes to native C++18 types
			// and apply the converted attributes to the editBuff

			cflib::CFLibNullableInt32 natId;
			if( ( attrId != NULL ) && ( attrId->length() > 0 ) ) {
				natId = cflib::CFLibXmlUtil::evalInt32( *attrId );
			}
			else {
				natId.setNull();
			}
			if( attrLoginId != NULL ) {
				natLoginId = new std::string( *attrLoginId );
			}
			else {
				natLoginId = NULL;
			}
			if( natLoginId == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_LoginId );
			}
			editBuff->setRequiredLoginId( *natLoginId );

			if( attrEMailAddress != NULL ) {
				natEMailAddress = new std::string( *attrEMailAddress );
			}
			else {
				natEMailAddress = NULL;
			}
			if( natEMailAddress == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_EMailAddress );
			}
			editBuff->setRequiredEMailAddress( *natEMailAddress );

			if( ( attrEMailConfirmUuid == NULL ) || ( attrEMailConfirmUuid->length() == 0 ) ) {
				for( int i = 0; i < 16; i++ ) {
					natEMailConfirmUuid[i] = 0;
				}
			}
			else {
				cflib::CFLib::uuidFromString( natEMailConfirmUuid, attrEMailConfirmUuid->data() );
			}
			if( ( attrEMailConfirmUuid != NULL ) && ( attrEMailConfirmUuid->length() > 0 ) ) {
				editBuff->setOptionalEMailConfirmUuidValue( natEMailConfirmUuid );
			}
			else {
				editBuff->setOptionalEMailConfirmUuidNull();
			}

			if( attrPasswordHash != NULL ) {
				natPasswordHash = new std::string( *attrPasswordHash );
			}
			else {
				natPasswordHash = NULL;
			}
			if( natPasswordHash == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_PasswordHash );
			}
			editBuff->setRequiredPasswordHash( *natPasswordHash );

			if( ( attrPasswordResetUuid == NULL ) || ( attrPasswordResetUuid->length() == 0 ) ) {
				for( int i = 0; i < 16; i++ ) {
					natPasswordResetUuid[i] = 0;
				}
			}
			else {
				cflib::CFLib::uuidFromString( natPasswordResetUuid, attrPasswordResetUuid->data() );
			}
			if( ( attrPasswordResetUuid != NULL ) && ( attrPasswordResetUuid->length() > 0 ) ) {
				editBuff->setOptionalPasswordResetUuidValue( natPasswordResetUuid );
			}
			else {
				editBuff->setOptionalPasswordResetUuidNull();
			}

			// Get the scope/container object

			parentContext = curContext->getPrevContext();
			if( parentContext != NULL ) {
				scopeObj = parentContext->getObj();
			}
			else {
				scopeObj = NULL;
			}

			// Lookup refDefDev by key name value attr
			if( ( attrDefDev != NULL ) && ( attrDefDev->length() > 0 ) ) {
				refDefDev = schemaObj->getSecDeviceTableObj()->readSecDeviceByNameIdx( editBuff->getOptionalDfltDevUserIdValue(),
					*attrDefDev );
				if( refDefDev == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						"Resolve DefDev reference named \"" + *attrDefDev + "\" to table SecDevice" );
				}
			}
			else {
				refDefDev = NULL;
			}
			editBuff->setOptionalLookupDefDev( refDefDev );

			loaderBehaviour = saxLoader->getSecUserLoaderBehaviour();
			origSecUser = dynamic_cast<cfsec::ICFSecSecUserObj*>( schemaObj->getSecUserTableObj()->readSecUserByULoginIdx( editBuff->getRequiredLoginId() ) );
			if( origSecUser == NULL ) {
				editSecUser = editBuff;
				editBuff = NULL;
			}
			else {
				switch( loaderBehaviour ) {
					case cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Insert:
						editSecUser = NULL;
						editBuff->endEdit();
						editBuff = NULL;
						break;
					case cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Update:
						editSecUser = dynamic_cast<cfsec::ICFSecSecUserEditObj*>( origSecUser->beginEdit() );
						editSecUser->setRequiredLoginId( editBuff->getRequiredLoginId() );
						editSecUser->setRequiredEMailAddress( editBuff->getRequiredEMailAddress() );
						if( editBuff->isOptionalEMailConfirmUuidNull() ) {
							editSecUser->setOptionalEMailConfirmUuidNull();
						}
						else {
							editSecUser->setOptionalEMailConfirmUuidValue( editBuff->getOptionalEMailConfirmUuidValue() );
						}
						editSecUser->setRequiredPasswordHash( editBuff->getRequiredPasswordHash() );
						if( editBuff->isOptionalPasswordResetUuidNull() ) {
							editSecUser->setOptionalPasswordResetUuidNull();
						}
						else {
							editSecUser->setOptionalPasswordResetUuidValue( editBuff->getOptionalPasswordResetUuidValue() );
						}
						editSecUser->setOptionalLookupDefDev( editBuff->getOptionalLookupDefDev() );
						editBuff->endEdit();
						editBuff = NULL;
						break;
					case cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Replace:
						editSecUser = dynamic_cast<cfsec::ICFSecSecUserEditObj*>( origSecUser->beginEdit() );
						editSecUser->deleteInstance();
						editSecUser = NULL;
						origSecUser = NULL;
						editSecUser = editBuff;
						editBuff = NULL;
						break;
				}
			}

			if( editSecUser != NULL ) {
				if( origSecUser != NULL ) {
					editSecUser->update();
				}
				else {
					origSecUser = dynamic_cast<cfsec::ICFSecSecUserObj*>( editSecUser->create() );
				}
				editSecUser = NULL;
			}

			if( ! tmpBuff->getIsNew() ) {
				tmpBuff = NULL;
			}

			curContext->setObj( origSecUser );

		}
		CFLIB_EXCEPTION_CATCH_FALLTHROUGH

cleanup:
		if( attrLocalName != NULL ) {
			delete attrLocalName;
			attrLocalName = NULL;
		}

		if( cppValue != NULL ) {
			delete cppValue;
			cppValue = NULL;
		}

		if( natLoginId != NULL ) {
			delete natLoginId;
			natLoginId = NULL;
		}

		if( natEMailAddress != NULL ) {
			delete natEMailAddress;
			natEMailAddress = NULL;
		}

		if( natPasswordHash != NULL ) {
			delete natPasswordHash;
			natPasswordHash = NULL;
		}

		if( attrLoginId != NULL ) {
			delete attrLoginId;
			attrLoginId = NULL;
		}

		if( attrEMailAddress != NULL ) {
			delete attrEMailAddress;
			attrEMailAddress = NULL;
		}

		if( attrEMailConfirmUuid != NULL ) {
			delete attrEMailConfirmUuid;
			attrEMailConfirmUuid = NULL;
		}

		if( attrPasswordHash != NULL ) {
			delete attrPasswordHash;
			attrPasswordHash = NULL;
		}

		if( attrPasswordResetUuid != NULL ) {
			delete attrPasswordResetUuid;
			attrPasswordResetUuid = NULL;
		}

		if( attrDefDev != NULL ) {
			delete attrDefDev;
			attrDefDev = NULL;
		}

		if( editSecUser != NULL ) {
			editSecUser->endEdit();
			editSecUser = NULL;
		}

		if( editBuff != NULL ) {
			editBuff->endEdit();
			editBuff = NULL;
		}

		if( tmpBuff != NULL ) {
			if( tmpBuff->getIsNew() ) {
				delete tmpBuff;
			}
			tmpBuff = NULL;
		}

		CFLIB_EXCEPTION_RETHROW_SAXEXCEPTION
	}

	void CFSecSaxLoaderSecUserHandler::endElement(
		const XMLCh* const uri,
		const XMLCh* const localname,
		const XMLCh* const qname )
	{
	}
}
