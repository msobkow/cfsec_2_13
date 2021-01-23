
// Description: C++18 XML SAX2 Element Handler implementation for SecGroupForm

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
#include <cfsecsaxloader/CFSecSaxLoaderSecGroupFormHandler.hpp>

using namespace std;

namespace cfsec {

	const std::string CFSecSaxLoaderSecGroupFormHandler::CLASS_NAME( "CFSecSaxLoaderSecGroupFormHandler" );
	const std::string CFSecSaxLoaderSecGroupFormHandler::S_True( "true" );
	const std::string CFSecSaxLoaderSecGroupFormHandler::S_False( "false" );
	const std::string CFSecSaxLoaderSecGroupFormHandler::S_Yes( "yes" );
	const std::string CFSecSaxLoaderSecGroupFormHandler::S_No( "no" );
	const std::string CFSecSaxLoaderSecGroupFormHandler::S_0( "0" );
	const std::string CFSecSaxLoaderSecGroupFormHandler::S_1( "1" );

	CFSecSaxLoaderSecGroupFormHandler::CFSecSaxLoaderSecGroupFormHandler( cfsec::CFSecSaxLoader* saxLoader )
	: cflib::CFLibXmlCoreElementHandler( saxLoader )
	{
	}

	CFSecSaxLoaderSecGroupFormHandler::~CFSecSaxLoaderSecGroupFormHandler() {
	}

	void CFSecSaxLoaderSecGroupFormHandler::startElement (
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
		static const std::string S_SecGroupFormId( "SecGroupFormId" );
		static const std::string S_SecGroupId( "SecGroupId" );
		static const std::string S_SecAppId( "SecAppId" );
		static const std::string S_SecFormId( "SecFormId" );
		static const std::string S_Cluster( "Cluster" );
		static const std::string S_Group( "Group" );
		static const std::string S_App( "App" );
		static const std::string S_Form( "Form" );
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
		cfsec::ICFSecSecGroupFormObj* tmpBuff = NULL;
		cfsec::ICFSecSecGroupFormEditObj* editBuff = NULL;
		cfsec::ICFSecSecGroupFormEditObj* editSecGroupForm = NULL;
		cfsec::ICFSecSecGroupFormObj* origSecGroupForm = NULL;
		cflib::CFLibXmlCoreContext* parentContext = NULL;
		cflib::ICFLibAnyObj* scopeObj = NULL;
		// Common XML Attributes
		std::string* attrId = NULL;
		// SecGroupForm Attributes
		std::string* attrApp = NULL;
		std::string* attrForm = NULL;
		// SecGroupForm References
		cfsec::ICFSecClusterObj* refCluster = NULL;
		cfsec::ICFSecSecGroupObj* refGroup = NULL;
		cfsec::ICFSecSecAppObj* refApp = NULL;
		cfsec::ICFSecSecFormObj* refForm = NULL;
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
			if( cppQName != cfsec::CFSecSecGroupFormBuff::GENDEFNAME ) {
				std::string Msg( "Expected QName to be '" + cfsec::CFSecSecGroupFormBuff::GENDEFNAME + "'" );
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
			tmpBuff = schemaObj->getSecGroupFormTableObj()->newInstance();
			editBuff = dynamic_cast<cfsec::ICFSecSecGroupFormEditObj*>( tmpBuff->beginEdit() );

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
				else if( *attrLocalName == S_App ) {
					if( attrApp != NULL ) {
						throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
							S_ProcName,
							*attrLocalName );
					}
					if( cppValue != NULL ) {
						attrApp = new std::string( *cppValue );
					}
					else {
						attrApp = NULL;
					}
				}
				else if( *attrLocalName == S_Form ) {
					if( attrForm != NULL ) {
						throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
							S_ProcName,
							*attrLocalName );
					}
					if( cppValue != NULL ) {
						attrForm = new std::string( *cppValue );
					}
					else {
						attrForm = NULL;
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
			if( ( attrApp == NULL ) || ( attrApp->length() <= 0 ) ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_App );
			}
			if( ( attrForm == NULL ) || ( attrForm->length() <= 0 ) ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Form );
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
			if( attrApp != NULL ) {
				curContext->putNamedTag( S_App, *attrApp );
			}
			if( attrForm != NULL ) {
				curContext->putNamedTag( S_Form, *attrForm );
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
			else if( scopeObj->implementsClassCode( cfsec::CFSecSecGroupBuff::CLASS_CODE ) ) {
				refGroup = dynamic_cast<cfsec::ICFSecSecGroupObj*>( scopeObj );
				editBuff->setRequiredContainerGroup( refGroup );
			refCluster = editBuff->getRequiredOwnerCluster();
			}
			else {
				throw cflib::CFLibUnsupportedClassException( CLASS_NAME,
					S_ProcName,
					"scopeObj",
					scopeObj,
					"ICFSecSecGroupObj" );
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

			// Lookup refApp by key name value attr
			if( ( attrApp != NULL ) && ( attrApp->length() > 0 ) ) {
				refApp = schemaObj->getSecAppTableObj()->readSecAppByUJEEMountIdx( editBuff->getRequiredClusterId(),
					*attrApp );
				if( refApp == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						"Resolve App reference named \"" + *attrApp + "\" to table SecApp" );
				}
			}
			else {
				refApp = NULL;
			}
			editBuff->setRequiredParentApp( refApp );

			// Lookup refForm by key name value attr
			if( ( attrForm != NULL ) && ( attrForm->length() > 0 ) ) {
				refForm = schemaObj->getSecFormTableObj()->readSecFormByUJEEServletIdx( editBuff->getRequiredClusterId(),
					editBuff->getRequiredSecAppId(),
					*attrForm );
				if( refForm == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						"Resolve Form reference named \"" + *attrForm + "\" to table SecForm" );
				}
			}
			else {
				refForm = NULL;
			}
			editBuff->setRequiredParentForm( refForm );

			loaderBehaviour = saxLoader->getSecGroupFormLoaderBehaviour();
			origSecGroupForm = schemaObj->getSecGroupFormTableObj()->readSecGroupFormByUFormIdx( refCluster->getRequiredId(),
			refGroup->getRequiredSecGroupId(),
			refForm->getRequiredSecFormId() );
			if( origSecGroupForm == NULL ) {
				editSecGroupForm = editBuff;
				editBuff = NULL;
			}
			else {
				switch( loaderBehaviour ) {
					case cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Insert:
						editSecGroupForm = NULL;
						editBuff->endEdit();
						editBuff = NULL;
						break;
					case cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Update:
						editSecGroupForm = dynamic_cast<cfsec::ICFSecSecGroupFormEditObj*>( origSecGroupForm->beginEdit() );
						editSecGroupForm->setRequiredParentApp( editBuff->getRequiredParentApp() );
						editSecGroupForm->setRequiredParentForm( editBuff->getRequiredParentForm() );
						editBuff->endEdit();
						editBuff = NULL;
						break;
					case cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Replace:
						editSecGroupForm = dynamic_cast<cfsec::ICFSecSecGroupFormEditObj*>( origSecGroupForm->beginEdit() );
						editSecGroupForm->deleteInstance();
						editSecGroupForm = NULL;
						origSecGroupForm = NULL;
						editSecGroupForm = editBuff;
						editBuff = NULL;
						break;
				}
			}

			if( editSecGroupForm != NULL ) {
				if( origSecGroupForm != NULL ) {
					editSecGroupForm->update();
				}
				else {
					origSecGroupForm = dynamic_cast<cfsec::ICFSecSecGroupFormObj*>( editSecGroupForm->create() );
				}
				editSecGroupForm = NULL;
			}

			if( ! tmpBuff->getIsNew() ) {
				tmpBuff = NULL;
			}

			curContext->setObj( origSecGroupForm );

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

		if( attrApp != NULL ) {
			delete attrApp;
			attrApp = NULL;
		}

		if( attrForm != NULL ) {
			delete attrForm;
			attrForm = NULL;
		}

		if( editSecGroupForm != NULL ) {
			editSecGroupForm->endEdit();
			editSecGroupForm = NULL;
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

	void CFSecSaxLoaderSecGroupFormHandler::endElement(
		const XMLCh* const uri,
		const XMLCh* const localname,
		const XMLCh* const qname )
	{
	}
}
