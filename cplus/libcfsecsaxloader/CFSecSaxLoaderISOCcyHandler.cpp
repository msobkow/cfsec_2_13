
// Description: C++18 XML SAX2 Element Handler implementation for ISOCcy

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
#include <cfsecsaxloader/CFSecSaxLoaderISOCcyHandler.hpp>

using namespace std;

namespace cfsec {

	const std::string CFSecSaxLoaderISOCcyHandler::CLASS_NAME( "CFSecSaxLoaderISOCcyHandler" );
	const std::string CFSecSaxLoaderISOCcyHandler::S_True( "true" );
	const std::string CFSecSaxLoaderISOCcyHandler::S_False( "false" );
	const std::string CFSecSaxLoaderISOCcyHandler::S_Yes( "yes" );
	const std::string CFSecSaxLoaderISOCcyHandler::S_No( "no" );
	const std::string CFSecSaxLoaderISOCcyHandler::S_0( "0" );
	const std::string CFSecSaxLoaderISOCcyHandler::S_1( "1" );

	CFSecSaxLoaderISOCcyHandler::CFSecSaxLoaderISOCcyHandler( cfsec::CFSecSaxLoader* saxLoader )
	: cflib::CFLibXmlCoreElementHandler( saxLoader )
	{
	}

	CFSecSaxLoaderISOCcyHandler::~CFSecSaxLoaderISOCcyHandler() {
	}

	void CFSecSaxLoaderISOCcyHandler::startElement (
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
		static const std::string S_ISOCcyId( "ISOCcyId" );
		static const std::string S_ISOCode( "ISOCode" );
		static const std::string S_Name( "Name" );
		static const std::string S_UnitSymbol( "UnitSymbol" );
		static const std::string S_Precis( "Precis" );
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
		cfsec::ICFSecISOCcyObj* tmpBuff = NULL;
		cfsec::ICFSecISOCcyEditObj* editBuff = NULL;
		cfsec::ICFSecISOCcyEditObj* editISOCcy = NULL;
		cfsec::ICFSecISOCcyObj* origISOCcy = NULL;
		cflib::CFLibXmlCoreContext* parentContext = NULL;
		cflib::ICFLibAnyObj* scopeObj = NULL;
		// Common XML Attributes
		std::string* attrId = NULL;
		// ISOCcy Attributes
		std::string* attrISOCode = NULL;
		std::string* attrName = NULL;
		std::string* attrUnitSymbol = NULL;
		std::string* attrPrecis = NULL;
		// ISOCcy References
		std::string* natISOCode = NULL;
		std::string* natName = NULL;
		std::string* natUnitSymbol = NULL;
		int16_t natPrecis;
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
			if( cppQName != cfsec::CFSecISOCcyBuff::GENDEFNAME ) {
				std::string Msg( "Expected QName to be '" + cfsec::CFSecISOCcyBuff::GENDEFNAME + "'" );
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
			tmpBuff = schemaObj->getISOCcyTableObj()->newInstance();
			editBuff = dynamic_cast<cfsec::ICFSecISOCcyEditObj*>( tmpBuff->beginEdit() );

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
				else if( *attrLocalName == S_ISOCode ) {
					if( attrISOCode != NULL ) {
						throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
							S_ProcName,
							*attrLocalName );
					}
					if( cppValue != NULL ) {
						attrISOCode = new std::string( *cppValue );
					}
					else {
						attrISOCode = NULL;
					}
				}
				else if( *attrLocalName == S_Name ) {
					if( attrName != NULL ) {
						throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
							S_ProcName,
							*attrLocalName );
					}
					if( cppValue != NULL ) {
						attrName = new std::string( *cppValue );
					}
					else {
						attrName = NULL;
					}
				}
				else if( *attrLocalName == S_UnitSymbol ) {
					if( attrUnitSymbol != NULL ) {
						throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
							S_ProcName,
							*attrLocalName );
					}
					if( cppValue != NULL ) {
						attrUnitSymbol = new std::string( *cppValue );
					}
					else {
						attrUnitSymbol = NULL;
					}
				}
				else if( *attrLocalName == S_Precis ) {
					if( attrPrecis != NULL ) {
						throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
							S_ProcName,
							*attrLocalName );
					}
					if( cppValue != NULL ) {
						attrPrecis = new std::string( *cppValue );
					}
					else {
						attrPrecis = NULL;
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
			if( attrISOCode == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_ISOCode );
			}
			if( attrName == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Name );
			}
			if( ( attrPrecis == NULL ) || ( attrPrecis->length() <= 0 ) ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Precis );
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
			if( attrISOCode != NULL ) {
				curContext->putNamedTag( S_ISOCode, *attrISOCode );
			}
			if( attrName != NULL ) {
				curContext->putNamedTag( S_Name, *attrName );
			}
			if( attrUnitSymbol != NULL ) {
				curContext->putNamedTag( S_UnitSymbol, *attrUnitSymbol );
			}
			if( attrPrecis != NULL ) {
				curContext->putNamedTag( S_Precis, *attrPrecis );
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
			if( attrISOCode != NULL ) {
				natISOCode = new std::string( *attrISOCode );
			}
			else {
				natISOCode = NULL;
			}
			if( natISOCode == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_ISOCode );
			}
			editBuff->setRequiredISOCode( *natISOCode );

			if( attrName != NULL ) {
				natName = new std::string( *attrName );
			}
			else {
				natName = NULL;
			}
			if( natName == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Name );
			}
			editBuff->setRequiredName( *natName );

			if( attrUnitSymbol != NULL ) {
				natUnitSymbol = new std::string( *attrUnitSymbol );
			}
			else {
				natUnitSymbol = NULL;
			}
			if( natUnitSymbol != NULL ) {
				editBuff->setOptionalUnitSymbolValue( *natUnitSymbol );
			}
			else {
				editBuff->setOptionalUnitSymbolNull();
			}

			natPrecis = cflib::CFLibXmlUtil::evalInt16( *attrPrecis );
			editBuff->setRequiredPrecis( natPrecis );

			// Get the scope/container object

			parentContext = curContext->getPrevContext();
			if( parentContext != NULL ) {
				scopeObj = parentContext->getObj();
			}
			else {
				scopeObj = NULL;
			}

			loaderBehaviour = saxLoader->getISOCcyLoaderBehaviour();
			origISOCcy = dynamic_cast<cfsec::ICFSecISOCcyObj*>( schemaObj->getISOCcyTableObj()->readISOCcyByCcyCdIdx( editBuff->getRequiredISOCode() ) );
			if( origISOCcy == NULL ) {
				editISOCcy = editBuff;
				editBuff = NULL;
			}
			else {
				switch( loaderBehaviour ) {
					case cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Insert:
						editISOCcy = NULL;
						editBuff->endEdit();
						editBuff = NULL;
						break;
					case cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Update:
						editISOCcy = dynamic_cast<cfsec::ICFSecISOCcyEditObj*>( origISOCcy->beginEdit() );
						editISOCcy->setRequiredISOCode( editBuff->getRequiredISOCode() );
						editISOCcy->setRequiredName( editBuff->getRequiredName() );
						if( editBuff->isOptionalUnitSymbolNull() ) {
							editISOCcy->setOptionalUnitSymbolNull();
						}
						else {
							editISOCcy->setOptionalUnitSymbolValue( editBuff->getOptionalUnitSymbolValue() );
						}
						editISOCcy->setRequiredPrecis( editBuff->getRequiredPrecis() );
						editBuff->endEdit();
						editBuff = NULL;
						break;
					case cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Replace:
						editISOCcy = dynamic_cast<cfsec::ICFSecISOCcyEditObj*>( origISOCcy->beginEdit() );
						editISOCcy->deleteInstance();
						editISOCcy = NULL;
						origISOCcy = NULL;
						editISOCcy = editBuff;
						editBuff = NULL;
						break;
				}
			}

			if( editISOCcy != NULL ) {
				if( origISOCcy != NULL ) {
					editISOCcy->update();
				}
				else {
					origISOCcy = dynamic_cast<cfsec::ICFSecISOCcyObj*>( editISOCcy->create() );
				}
				editISOCcy = NULL;
			}

			if( ! tmpBuff->getIsNew() ) {
				tmpBuff = NULL;
			}

			curContext->setObj( origISOCcy );

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

		if( natISOCode != NULL ) {
			delete natISOCode;
			natISOCode = NULL;
		}

		if( natName != NULL ) {
			delete natName;
			natName = NULL;
		}

		if( natUnitSymbol != NULL ) {
			delete natUnitSymbol;
			natUnitSymbol = NULL;
		}

		if( attrISOCode != NULL ) {
			delete attrISOCode;
			attrISOCode = NULL;
		}

		if( attrName != NULL ) {
			delete attrName;
			attrName = NULL;
		}

		if( attrUnitSymbol != NULL ) {
			delete attrUnitSymbol;
			attrUnitSymbol = NULL;
		}

		if( attrPrecis != NULL ) {
			delete attrPrecis;
			attrPrecis = NULL;
		}

		if( editISOCcy != NULL ) {
			editISOCcy->endEdit();
			editISOCcy = NULL;
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

	void CFSecSaxLoaderISOCcyHandler::endElement(
		const XMLCh* const uri,
		const XMLCh* const localname,
		const XMLCh* const qname )
	{
	}
}
