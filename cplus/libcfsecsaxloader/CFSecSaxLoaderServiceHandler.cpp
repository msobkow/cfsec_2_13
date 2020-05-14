
// Description: C++18 XML SAX2 Element Handler implementation for Service

/*
 *	com.github.msobkow.CFSec
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
#include <cfsecsaxloader/CFSecSaxLoaderServiceHandler.hpp>

using namespace std;

namespace cfsec {

	const std::string CFSecSaxLoaderServiceHandler::CLASS_NAME( "CFSecSaxLoaderServiceHandler" );
	const std::string CFSecSaxLoaderServiceHandler::S_True( "true" );
	const std::string CFSecSaxLoaderServiceHandler::S_False( "false" );
	const std::string CFSecSaxLoaderServiceHandler::S_Yes( "yes" );
	const std::string CFSecSaxLoaderServiceHandler::S_No( "no" );
	const std::string CFSecSaxLoaderServiceHandler::S_0( "0" );
	const std::string CFSecSaxLoaderServiceHandler::S_1( "1" );

	CFSecSaxLoaderServiceHandler::CFSecSaxLoaderServiceHandler( cfsec::CFSecSaxLoader* saxLoader )
	: cflib::CFLibXmlCoreElementHandler( saxLoader )
	{
	}

	CFSecSaxLoaderServiceHandler::~CFSecSaxLoaderServiceHandler() {
	}

	void CFSecSaxLoaderServiceHandler::startElement (
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
		static const std::string S_ClusterId( "ClusterId" );
		static const std::string S_ServiceId( "ServiceId" );
		static const std::string S_HostNodeId( "HostNodeId" );
		static const std::string S_ServiceTypeId( "ServiceTypeId" );
		static const std::string S_HostPort( "HostPort" );
		static const std::string S_Cluster( "Cluster" );
		static const std::string S_Host( "Host" );
		static const std::string S_ServiceType( "ServiceType" );
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
		cfsec::ICFSecServiceObj* tmpBuff = NULL;
		cfsec::ICFSecServiceEditObj* editBuff = NULL;
		cfsec::ICFSecServiceEditObj* editService = NULL;
		cfsec::ICFSecServiceObj* origService = NULL;
		cflib::CFLibXmlCoreContext* parentContext = NULL;
		cflib::ICFLibAnyObj* scopeObj = NULL;
		// Common XML Attributes
		std::string* attrId = NULL;
		// Service Attributes
		std::string* attrHostPort = NULL;
		std::string* attrServiceType = NULL;
		// Service References
		cfsec::ICFSecClusterObj* refCluster = NULL;
		cfsec::ICFSecHostNodeObj* refHost = NULL;
		cfsec::ICFSecServiceTypeObj* refServiceType = NULL;
		int16_t natHostPort;
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
			if( cppQName != cfsec::CFSecServiceBuff::GENDEFNAME ) {
				std::string Msg( "Expected QName to be '" + cfsec::CFSecServiceBuff::GENDEFNAME + "'" );
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
			tmpBuff = schemaObj->getServiceTableObj()->newInstance();
			editBuff = dynamic_cast<cfsec::ICFSecServiceEditObj*>( tmpBuff->beginEdit() );

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
				else if( *attrLocalName == S_HostPort ) {
					if( attrHostPort != NULL ) {
						throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
							S_ProcName,
							*attrLocalName );
					}
					if( cppValue != NULL ) {
						attrHostPort = new std::string( *cppValue );
					}
					else {
						attrHostPort = NULL;
					}
				}
				else if( *attrLocalName == S_ServiceType ) {
					if( attrServiceType != NULL ) {
						throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
							S_ProcName,
							*attrLocalName );
					}
					if( cppValue != NULL ) {
						attrServiceType = new std::string( *cppValue );
					}
					else {
						attrServiceType = NULL;
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
			if( ( attrHostPort == NULL ) || ( attrHostPort->length() <= 0 ) ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_HostPort );
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
			if( attrHostPort != NULL ) {
				curContext->putNamedTag( S_HostPort, *attrHostPort );
			}
			if( attrServiceType != NULL ) {
				curContext->putNamedTag( S_ServiceType, *attrServiceType );
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
			natHostPort = cflib::CFLibXmlUtil::evalInt16( *attrHostPort );
			editBuff->setRequiredHostPort( natHostPort );

			// Get the scope/container object

			parentContext = curContext->getPrevContext();
			if( parentContext != NULL ) {
				scopeObj = parentContext->getObj();
			}
			else {
				scopeObj = NULL;
			}

			// Resolve and apply optional Container reference

			if( scopeObj == NULL ) {
				refHost = NULL;
				editBuff->setOptionalContainerHost( refHost );
			refCluster = editBuff->getRequiredOwnerCluster();
			}
			else if( scopeObj->implementsClassCode( cfsec::CFSecHostNodeBuff::CLASS_CODE ) ) {
				refHost = dynamic_cast<cfsec::ICFSecHostNodeObj*>( scopeObj );
				editBuff->setOptionalContainerHost( refHost );
			refCluster = editBuff->getRequiredOwnerCluster();
			}
			else {
				throw cflib::CFLibUnsupportedClassException( CLASS_NAME,
					S_ProcName,
					"scopeObj",
					scopeObj,
					"ICFSecHostNodeObj" );
			}

			// Resolve and apply Owner reference

			if( refCluster == NULL ) {
				if( scopeObj->implementsClassCode( cfsec::CFSecClusterBuff::CLASS_CODE ) ) {
					refCluster = dynamic_cast<cfsec::ICFSecClusterObj*>( scopeObj );
					editBuff->setRequiredOwnerCluster( refCluster );
				}
				else {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						"Owner<Cluster>" );
				}
			}

			// Lookup refServiceType by key name value attr
			if( ( attrServiceType != NULL ) && ( attrServiceType->length() > 0 ) ) {
				refServiceType = schemaObj->getServiceTypeTableObj()->readServiceTypeByUDescrIdx( *attrServiceType );
				if( refServiceType == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						"Resolve ServiceType reference named \"" + *attrServiceType + "\" to table ServiceType" );
				}
			}
			else {
				refServiceType = NULL;
			}
			editBuff->setOptionalParentServiceType( refServiceType );

			loaderBehaviour = saxLoader->getServiceLoaderBehaviour();
			origService = schemaObj->getServiceTableObj()->readServiceByUTypeIdx( refCluster->getRequiredId(),
			refHost->getRequiredHostNodeId(),
			refServiceType->getRequiredServiceTypeId() );
			if( origService == NULL ) {
				editService = editBuff;
				editBuff = NULL;
			}
			else {
				switch( loaderBehaviour ) {
					case cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Insert:
						editService = NULL;
						editBuff->endEdit();
						editBuff = NULL;
						break;
					case cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Update:
						editService = dynamic_cast<cfsec::ICFSecServiceEditObj*>( origService->beginEdit() );
						editService->setRequiredHostPort( editBuff->getRequiredHostPort() );
						editService->setOptionalParentServiceType( editBuff->getOptionalParentServiceType() );
						editBuff->endEdit();
						editBuff = NULL;
						break;
					case cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Replace:
						editService = dynamic_cast<cfsec::ICFSecServiceEditObj*>( origService->beginEdit() );
						editService->deleteInstance();
						editService = NULL;
						origService = NULL;
						editService = editBuff;
						editBuff = NULL;
						break;
				}
			}

			if( editService != NULL ) {
				if( origService != NULL ) {
					editService->update();
				}
				else {
					origService = dynamic_cast<cfsec::ICFSecServiceObj*>( editService->create() );
				}
				editService = NULL;
			}

			if( ! tmpBuff->getIsNew() ) {
				tmpBuff = NULL;
			}

			curContext->setObj( origService );

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

		if( attrHostPort != NULL ) {
			delete attrHostPort;
			attrHostPort = NULL;
		}

		if( attrServiceType != NULL ) {
			delete attrServiceType;
			attrServiceType = NULL;
		}

		if( editService != NULL ) {
			editService->endEdit();
			editService = NULL;
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

	void CFSecSaxLoaderServiceHandler::endElement(
		const XMLCh* const uri,
		const XMLCh* const localname,
		const XMLCh* const qname )
	{
	}
}
