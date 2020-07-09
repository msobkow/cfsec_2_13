
// Description: C++18 XML SAX2 Element Handler implementation for ISOLang

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
#include <cfsecsaxloader/CFSecSaxLoaderISOLangHandler.hpp>

using namespace std;

namespace cfsec {

	const std::string CFSecSaxLoaderISOLangHandler::CLASS_NAME( "CFSecSaxLoaderISOLangHandler" );
	const std::string CFSecSaxLoaderISOLangHandler::S_True( "true" );
	const std::string CFSecSaxLoaderISOLangHandler::S_False( "false" );
	const std::string CFSecSaxLoaderISOLangHandler::S_Yes( "yes" );
	const std::string CFSecSaxLoaderISOLangHandler::S_No( "no" );
	const std::string CFSecSaxLoaderISOLangHandler::S_0( "0" );
	const std::string CFSecSaxLoaderISOLangHandler::S_1( "1" );

	CFSecSaxLoaderISOLangHandler::CFSecSaxLoaderISOLangHandler( cfsec::CFSecSaxLoader* saxLoader )
	: cflib::CFLibXmlCoreElementHandler( saxLoader )
	{
	}

	CFSecSaxLoaderISOLangHandler::~CFSecSaxLoaderISOLangHandler() {
	}

	void CFSecSaxLoaderISOLangHandler::startElement (
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
		static const std::string S_ISOLangId( "ISOLangId" );
		static const std::string S_ISO6392Code( "ISO6392Code" );
		static const std::string S_ISO6391Code( "ISO6391Code" );
		static const std::string S_EnglishName( "EnglishName" );
		static const std::string S_Ctry( "Ctry" );
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
		cfsec::ICFSecISOLangObj* tmpBuff = NULL;
		cfsec::ICFSecISOLangEditObj* editBuff = NULL;
		cfsec::ICFSecISOLangEditObj* editISOLang = NULL;
		cfsec::ICFSecISOLangObj* origISOLang = NULL;
		cflib::CFLibXmlCoreContext* parentContext = NULL;
		cflib::ICFLibAnyObj* scopeObj = NULL;
		// Common XML Attributes
		std::string* attrId = NULL;
		// ISOLang Attributes
		std::string* attrISO6392Code = NULL;
		std::string* attrISO6391Code = NULL;
		std::string* attrEnglishName = NULL;
		// ISOLang References
		std::string* natISO6392Code = NULL;
		std::string* natISO6391Code = NULL;
		std::string* natEnglishName = NULL;
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
			if( cppQName != cfsec::CFSecISOLangBuff::GENDEFNAME ) {
				std::string Msg( "Expected QName to be '" + cfsec::CFSecISOLangBuff::GENDEFNAME + "'" );
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
			tmpBuff = schemaObj->getISOLangTableObj()->newInstance();
			editBuff = dynamic_cast<cfsec::ICFSecISOLangEditObj*>( tmpBuff->beginEdit() );

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
				else if( *attrLocalName == S_ISO6392Code ) {
					if( attrISO6392Code != NULL ) {
						throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
							S_ProcName,
							*attrLocalName );
					}
					if( cppValue != NULL ) {
						attrISO6392Code = new std::string( *cppValue );
					}
					else {
						attrISO6392Code = NULL;
					}
				}
				else if( *attrLocalName == S_ISO6391Code ) {
					if( attrISO6391Code != NULL ) {
						throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
							S_ProcName,
							*attrLocalName );
					}
					if( cppValue != NULL ) {
						attrISO6391Code = new std::string( *cppValue );
					}
					else {
						attrISO6391Code = NULL;
					}
				}
				else if( *attrLocalName == S_EnglishName ) {
					if( attrEnglishName != NULL ) {
						throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
							S_ProcName,
							*attrLocalName );
					}
					if( cppValue != NULL ) {
						attrEnglishName = new std::string( *cppValue );
					}
					else {
						attrEnglishName = NULL;
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
			if( attrISO6392Code == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_ISO6392Code );
			}
			if( attrEnglishName == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_EnglishName );
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
			if( attrISO6392Code != NULL ) {
				curContext->putNamedTag( S_ISO6392Code, *attrISO6392Code );
			}
			if( attrISO6391Code != NULL ) {
				curContext->putNamedTag( S_ISO6391Code, *attrISO6391Code );
			}
			if( attrEnglishName != NULL ) {
				curContext->putNamedTag( S_EnglishName, *attrEnglishName );
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
			if( attrISO6392Code != NULL ) {
				natISO6392Code = new std::string( *attrISO6392Code );
			}
			else {
				natISO6392Code = NULL;
			}
			if( natISO6392Code == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_ISO6392Code );
			}
			editBuff->setRequiredISO6392Code( *natISO6392Code );

			if( attrISO6391Code != NULL ) {
				natISO6391Code = new std::string( *attrISO6391Code );
			}
			else {
				natISO6391Code = NULL;
			}
			if( natISO6391Code != NULL ) {
				editBuff->setOptionalISO6391CodeValue( *natISO6391Code );
			}
			else {
				editBuff->setOptionalISO6391CodeNull();
			}

			if( attrEnglishName != NULL ) {
				natEnglishName = new std::string( *attrEnglishName );
			}
			else {
				natEnglishName = NULL;
			}
			if( natEnglishName == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_EnglishName );
			}
			editBuff->setRequiredEnglishName( *natEnglishName );

			// Get the scope/container object

			parentContext = curContext->getPrevContext();
			if( parentContext != NULL ) {
				scopeObj = parentContext->getObj();
			}
			else {
				scopeObj = NULL;
			}

			loaderBehaviour = saxLoader->getISOLangLoaderBehaviour();
			origISOLang = dynamic_cast<cfsec::ICFSecISOLangObj*>( schemaObj->getISOLangTableObj()->readISOLangByCode3Idx( editBuff->getRequiredISO6392Code() ) );
			if( origISOLang == NULL ) {
				editISOLang = editBuff;
				editBuff = NULL;
			}
			else {
				switch( loaderBehaviour ) {
					case cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Insert:
						editISOLang = NULL;
						editBuff->endEdit();
						editBuff = NULL;
						break;
					case cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Update:
						editISOLang = dynamic_cast<cfsec::ICFSecISOLangEditObj*>( origISOLang->beginEdit() );
						editISOLang->setRequiredISO6392Code( editBuff->getRequiredISO6392Code() );
						if( editBuff->isOptionalISO6391CodeNull() ) {
							editISOLang->setOptionalISO6391CodeNull();
						}
						else {
							editISOLang->setOptionalISO6391CodeValue( editBuff->getOptionalISO6391CodeValue() );
						}
						editISOLang->setRequiredEnglishName( editBuff->getRequiredEnglishName() );
						editBuff->endEdit();
						editBuff = NULL;
						break;
					case cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Replace:
						editISOLang = dynamic_cast<cfsec::ICFSecISOLangEditObj*>( origISOLang->beginEdit() );
						editISOLang->deleteInstance();
						editISOLang = NULL;
						origISOLang = NULL;
						editISOLang = editBuff;
						editBuff = NULL;
						break;
				}
			}

			if( editISOLang != NULL ) {
				if( origISOLang != NULL ) {
					editISOLang->update();
				}
				else {
					origISOLang = dynamic_cast<cfsec::ICFSecISOLangObj*>( editISOLang->create() );
				}
				editISOLang = NULL;
			}

			if( ! tmpBuff->getIsNew() ) {
				tmpBuff = NULL;
			}

			curContext->setObj( origISOLang );

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

		if( natISO6392Code != NULL ) {
			delete natISO6392Code;
			natISO6392Code = NULL;
		}

		if( natISO6391Code != NULL ) {
			delete natISO6391Code;
			natISO6391Code = NULL;
		}

		if( natEnglishName != NULL ) {
			delete natEnglishName;
			natEnglishName = NULL;
		}

		if( attrISO6392Code != NULL ) {
			delete attrISO6392Code;
			attrISO6392Code = NULL;
		}

		if( attrISO6391Code != NULL ) {
			delete attrISO6391Code;
			attrISO6391Code = NULL;
		}

		if( attrEnglishName != NULL ) {
			delete attrEnglishName;
			attrEnglishName = NULL;
		}

		if( editISOLang != NULL ) {
			editISOLang->endEdit();
			editISOLang = NULL;
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

	void CFSecSaxLoaderISOLangHandler::endElement(
		const XMLCh* const uri,
		const XMLCh* const localname,
		const XMLCh* const qname )
	{
	}
}
