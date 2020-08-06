
// Description: C++18 XML SAX2 Element Handler implementation for ISOCtryCcy

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
#include <cfsec/ICFSecPublic.hpp>
#include <cfsecobj/ICFSecObjPublic.hpp>
#include <cfsecsaxloader/CFSecSaxLoader.hpp>
#include <cfsecsaxloader/CFSecSaxLoaderISOCtryCcyHandler.hpp>

using namespace std;

namespace cfsec {

	const std::string CFSecSaxLoaderISOCtryCcyHandler::CLASS_NAME( "CFSecSaxLoaderISOCtryCcyHandler" );
	const std::string CFSecSaxLoaderISOCtryCcyHandler::S_True( "true" );
	const std::string CFSecSaxLoaderISOCtryCcyHandler::S_False( "false" );
	const std::string CFSecSaxLoaderISOCtryCcyHandler::S_Yes( "yes" );
	const std::string CFSecSaxLoaderISOCtryCcyHandler::S_No( "no" );
	const std::string CFSecSaxLoaderISOCtryCcyHandler::S_0( "0" );
	const std::string CFSecSaxLoaderISOCtryCcyHandler::S_1( "1" );

	CFSecSaxLoaderISOCtryCcyHandler::CFSecSaxLoaderISOCtryCcyHandler( cfsec::CFSecSaxLoader* saxLoader )
	: cflib::CFLibXmlCoreElementHandler( saxLoader )
	{
	}

	CFSecSaxLoaderISOCtryCcyHandler::~CFSecSaxLoaderISOCtryCcyHandler() {
	}

	void CFSecSaxLoaderISOCtryCcyHandler::startElement (
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
		static const std::string S_ISOCtryId( "ISOCtryId" );
		static const std::string S_ISOCcyId( "ISOCcyId" );
		static const std::string S_Ctry( "Ctry" );
		static const std::string S_Ccy( "Ccy" );
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
		cfsec::ICFSecISOCtryCcyObj* tmpBuff = NULL;
		cfsec::ICFSecISOCtryCcyEditObj* editBuff = NULL;
		cfsec::ICFSecISOCtryCcyEditObj* editISOCtryCcy = NULL;
		cfsec::ICFSecISOCtryCcyObj* origISOCtryCcy = NULL;
		cflib::CFLibXmlCoreContext* parentContext = NULL;
		cflib::ICFLibAnyObj* scopeObj = NULL;
		// Common XML Attributes
		std::string* attrId = NULL;
		// ISOCtryCcy Attributes
		std::string* attrCcy = NULL;
		// ISOCtryCcy References
		cfsec::ICFSecISOCtryObj* refCtry = NULL;
		cfsec::ICFSecISOCcyObj* refCcy = NULL;
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
			if( cppQName != cfsec::CFSecISOCtryCcyBuff::GENDEFNAME ) {
				std::string Msg( "Expected QName to be '" + cfsec::CFSecISOCtryCcyBuff::GENDEFNAME + "'" );
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
			tmpBuff = schemaObj->getISOCtryCcyTableObj()->newInstance();
			editBuff = dynamic_cast<cfsec::ICFSecISOCtryCcyEditObj*>( tmpBuff->beginEdit() );

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
				else if( *attrLocalName == S_Ccy ) {
					if( attrCcy != NULL ) {
						throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
							S_ProcName,
							*attrLocalName );
					}
					if( cppValue != NULL ) {
						attrCcy = new std::string( *cppValue );
					}
					else {
						attrCcy = NULL;
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
			if( ( attrCcy == NULL ) || ( attrCcy->length() <= 0 ) ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Ccy );
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
			if( attrCcy != NULL ) {
				curContext->putNamedTag( S_Ccy, *attrCcy );
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
			else if( scopeObj->implementsClassCode( cfsec::CFSecISOCtryBuff::CLASS_CODE ) ) {
				refCtry = dynamic_cast<cfsec::ICFSecISOCtryObj*>( scopeObj );
				editBuff->setRequiredContainerCtry( refCtry );
			}
			else {
				throw cflib::CFLibUnsupportedClassException( CLASS_NAME,
					S_ProcName,
					"scopeObj",
					scopeObj,
					"ICFSecISOCtryObj" );
			}

			// Lookup refCcy by key name value attr
			if( ( attrCcy != NULL ) && ( attrCcy->length() > 0 ) ) {
				refCcy = schemaObj->getISOCcyTableObj()->readISOCcyByCcyCdIdx( *attrCcy );
				if( refCcy == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						"Resolve Ccy reference named \"" + *attrCcy + "\" to table ISOCcy" );
				}
			}
			else {
				refCcy = NULL;
			}
			editBuff->setRequiredParentCcy( refCcy );

			loaderBehaviour = saxLoader->getISOCtryCcyLoaderBehaviour();
			origISOCtryCcy = schemaObj->getISOCtryCcyTableObj()->readISOCtryCcyByIdIdx( refCtry->getRequiredISOCtryId(),
			refCcy->getRequiredISOCcyId() );
			if( origISOCtryCcy == NULL ) {
				editISOCtryCcy = editBuff;
				editBuff = NULL;
			}
			else {
				switch( loaderBehaviour ) {
					case cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Insert:
						editISOCtryCcy = NULL;
						editBuff->endEdit();
						editBuff = NULL;
						break;
					case cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Update:
						editISOCtryCcy = dynamic_cast<cfsec::ICFSecISOCtryCcyEditObj*>( origISOCtryCcy->beginEdit() );
						editISOCtryCcy->setRequiredParentCcy( editBuff->getRequiredParentCcy() );
						editBuff->endEdit();
						editBuff = NULL;
						break;
					case cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Replace:
						editISOCtryCcy = dynamic_cast<cfsec::ICFSecISOCtryCcyEditObj*>( origISOCtryCcy->beginEdit() );
						editISOCtryCcy->deleteInstance();
						editISOCtryCcy = NULL;
						origISOCtryCcy = NULL;
						editISOCtryCcy = editBuff;
						editBuff = NULL;
						break;
				}
			}

			if( editISOCtryCcy != NULL ) {
				if( origISOCtryCcy != NULL ) {
					editISOCtryCcy->update();
				}
				else {
					origISOCtryCcy = dynamic_cast<cfsec::ICFSecISOCtryCcyObj*>( editISOCtryCcy->create() );
				}
				editISOCtryCcy = NULL;
			}

			if( ! tmpBuff->getIsNew() ) {
				tmpBuff = NULL;
			}

			curContext->setObj( origISOCtryCcy );

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

		if( attrCcy != NULL ) {
			delete attrCcy;
			attrCcy = NULL;
		}

		if( editISOCtryCcy != NULL ) {
			editISOCtryCcy->endEdit();
			editISOCtryCcy = NULL;
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

	void CFSecSaxLoaderISOCtryCcyHandler::endElement(
		const XMLCh* const uri,
		const XMLCh* const localname,
		const XMLCh* const qname )
	{
	}
}
