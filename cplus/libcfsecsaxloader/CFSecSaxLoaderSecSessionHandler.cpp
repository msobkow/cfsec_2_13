
// Description: C++18 XML SAX2 Element Handler implementation for SecSession

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
#include <cfsec/ICFSecPublic.hpp>
#include <cfsecobj/ICFSecObjPublic.hpp>
#include <cfsecsaxloader/CFSecSaxLoader.hpp>
#include <cfsecsaxloader/CFSecSaxLoaderSecSessionHandler.hpp>

using namespace std;

namespace cfsec {

	const std::string CFSecSaxLoaderSecSessionHandler::CLASS_NAME( "CFSecSaxLoaderSecSessionHandler" );
	const std::string CFSecSaxLoaderSecSessionHandler::S_True( "true" );
	const std::string CFSecSaxLoaderSecSessionHandler::S_False( "false" );
	const std::string CFSecSaxLoaderSecSessionHandler::S_Yes( "yes" );
	const std::string CFSecSaxLoaderSecSessionHandler::S_No( "no" );
	const std::string CFSecSaxLoaderSecSessionHandler::S_0( "0" );
	const std::string CFSecSaxLoaderSecSessionHandler::S_1( "1" );

	CFSecSaxLoaderSecSessionHandler::CFSecSaxLoaderSecSessionHandler( cfsec::CFSecSaxLoader* saxLoader )
	: cflib::CFLibXmlCoreElementHandler( saxLoader )
	{
	}

	CFSecSaxLoaderSecSessionHandler::~CFSecSaxLoaderSecSessionHandler() {
	}

	void CFSecSaxLoaderSecSessionHandler::startElement (
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
		static const std::string S_SecSessionId( "SecSessionId" );
		static const std::string S_SecUserId( "SecUserId" );
		static const std::string S_SecDevName( "SecDevName" );
		static const std::string S_Start( "Start" );
		static const std::string S_Finish( "Finish" );
		static const std::string S_SecProxyId( "SecProxyId" );
		static const std::string S_SecUser( "SecUser" );
		static const std::string S_SecProxy( "SecProxy" );
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
		cfsec::ICFSecSecSessionObj* tmpBuff = NULL;
		cfsec::ICFSecSecSessionEditObj* editBuff = NULL;
		cfsec::ICFSecSecSessionEditObj* editSecSession = NULL;
		cfsec::ICFSecSecSessionObj* origSecSession = NULL;
		cflib::CFLibXmlCoreContext* parentContext = NULL;
		cflib::ICFLibAnyObj* scopeObj = NULL;
		// Common XML Attributes
		std::string* attrId = NULL;
		// SecSession Attributes
		std::string* attrSecDevName = NULL;
		std::string* attrStart = NULL;
		std::string* attrFinish = NULL;
		std::string* attrSecProxy = NULL;
		// SecSession References
		cfsec::ICFSecSecUserObj* refSecUser = NULL;
		cfsec::ICFSecSecUserObj* refSecProxy = NULL;
		std::string* natSecDevName = NULL;
		std::chrono::system_clock::time_point natStart;
		std::chrono::system_clock::time_point* natFinish;
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
			if( cppQName != cfsec::CFSecSecSessionBuff::GENDEFNAME ) {
				std::string Msg( "Expected QName to be '" + cfsec::CFSecSecSessionBuff::GENDEFNAME + "'" );
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
			tmpBuff = schemaObj->getSecSessionTableObj()->newInstance();
			editBuff = dynamic_cast<cfsec::ICFSecSecSessionEditObj*>( tmpBuff->beginEdit() );

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
				else if( *attrLocalName == S_SecDevName ) {
					if( attrSecDevName != NULL ) {
						throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
							S_ProcName,
							*attrLocalName );
					}
					if( cppValue != NULL ) {
						attrSecDevName = new std::string( *cppValue );
					}
					else {
						attrSecDevName = NULL;
					}
				}
				else if( *attrLocalName == S_Start ) {
					if( attrStart != NULL ) {
						throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
							S_ProcName,
							*attrLocalName );
					}
					if( cppValue != NULL ) {
						attrStart = new std::string( *cppValue );
					}
					else {
						attrStart = NULL;
					}
				}
				else if( *attrLocalName == S_Finish ) {
					if( attrFinish != NULL ) {
						throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
							S_ProcName,
							*attrLocalName );
					}
					if( cppValue != NULL ) {
						attrFinish = new std::string( *cppValue );
					}
					else {
						attrFinish = NULL;
					}
				}
				else if( *attrLocalName == S_SecProxy ) {
					if( attrSecProxy != NULL ) {
						throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
							S_ProcName,
							*attrLocalName );
					}
					if( cppValue != NULL ) {
						attrSecProxy = new std::string( *cppValue );
					}
					else {
						attrSecProxy = NULL;
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
			if( ( attrStart == NULL ) || ( attrStart->length() <= 0 ) ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Start );
			}
			if( ( attrSecProxy == NULL ) || ( attrSecProxy->length() <= 0 ) ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_SecProxy );
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
			if( attrSecDevName != NULL ) {
				curContext->putNamedTag( S_SecDevName, *attrSecDevName );
			}
			if( attrStart != NULL ) {
				curContext->putNamedTag( S_Start, *attrStart );
			}
			if( attrFinish != NULL ) {
				curContext->putNamedTag( S_Finish, *attrFinish );
			}
			if( attrSecProxy != NULL ) {
				curContext->putNamedTag( S_SecProxy, *attrSecProxy );
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
			if( attrSecDevName != NULL ) {
				natSecDevName = new std::string( *attrSecDevName );
			}
			else {
				natSecDevName = NULL;
			}
			if( natSecDevName != NULL ) {
				editBuff->setOptionalSecDevNameValue( *natSecDevName );
			}
			else {
				editBuff->setOptionalSecDevNameNull();
			}

			try {
				if( ( attrStart != NULL ) && ( attrStart->length() > 0 ) ) {
					natStart = cflib::CFLibXmlUtil::evalTimestamp( *attrStart );
				}
			}
			CFLIB_EXCEPTION_CATCH_FALLTHROUGH
			if( ! CFLIB_EXCEPTION_EMPTY ) {
				throw cflib::CFLibInvalidArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Start,
					*attrStart + cflib::CFLib::S_SPACE + exceptionInfo.getMessageText() );
			}
			editBuff->setRequiredStart( natStart );

			try {
				if( ( attrFinish != NULL ) && ( attrFinish->length() > 0 ) ) {
					natFinish = cflib::CFLibXmlUtil::parseTimestamp( *attrFinish );
				}
				else {
					natFinish = NULL;
				}
			}
			CFLIB_EXCEPTION_CATCH_FALLTHROUGH
			if( ! CFLIB_EXCEPTION_EMPTY ) {
				throw cflib::CFLibInvalidArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Finish,
					*attrFinish + cflib::CFLib::S_SPACE + exceptionInfo.getMessageText() );
			}
			if( attrFinish != NULL ) {
				editBuff->setOptionalFinishValue( *natFinish );
			}
			else {
				editBuff->setOptionalFinishNull();
			}

			// Get the scope/container object

			parentContext = curContext->getPrevContext();
			if( parentContext != NULL ) {
				scopeObj = parentContext->getObj();
			}
			else {
				scopeObj = NULL;
			}

			// Resolve and apply required Container reference

			if( scopeObj == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					"scopeObj" );
			}
			else if( scopeObj->implementsClassCode( cfsec::CFSecSecUserBuff::CLASS_CODE ) ) {
				refSecUser = dynamic_cast<cfsec::ICFSecSecUserObj*>( scopeObj );
				editBuff->setRequiredContainerSecUser( refSecUser );
			}
			else {
				throw cflib::CFLibUnsupportedClassException( CLASS_NAME,
					S_ProcName,
					"scopeObj",
					scopeObj,
					"ICFSecSecUserObj" );
			}

			// Lookup refSecProxy by key name value attr
			if( ( attrSecProxy != NULL ) && ( attrSecProxy->length() > 0 ) ) {
				refSecProxy = schemaObj->getSecUserTableObj()->readSecUserByULoginIdx( *attrSecProxy );
				if( refSecProxy == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						"Resolve SecProxy reference named \"" + *attrSecProxy + "\" to table SecUser" );
				}
			}
			else {
				refSecProxy = NULL;
			}
			editBuff->setRequiredParentSecProxy( refSecProxy );

			editSecSession = editBuff;
			editBuff = NULL;
			origSecSession = dynamic_cast<cfsec::ICFSecSecSessionObj*>( editSecSession->create() );
			editSecSession = NULL;
			tmpBuff = NULL;

			curContext->setObj( origSecSession );

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

		if( natSecDevName != NULL ) {
			delete natSecDevName;
			natSecDevName = NULL;
		}

		if( natFinish != NULL ) {
			delete natFinish;
			natFinish = NULL;
		}

		if( attrSecDevName != NULL ) {
			delete attrSecDevName;
			attrSecDevName = NULL;
		}

		if( attrStart != NULL ) {
			delete attrStart;
			attrStart = NULL;
		}

		if( attrFinish != NULL ) {
			delete attrFinish;
			attrFinish = NULL;
		}

		if( attrSecProxy != NULL ) {
			delete attrSecProxy;
			attrSecProxy = NULL;
		}

		if( editSecSession != NULL ) {
			editSecSession->endEdit();
			editSecSession = NULL;
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

	void CFSecSaxLoaderSecSessionHandler::endElement(
		const XMLCh* const uri,
		const XMLCh* const localname,
		const XMLCh* const qname )
	{
	}
}
