
// Description: C++18 XML SAX2 Element Handler implementation for ISOTZone

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
#include <cfsecsaxloader/CFSecSaxLoaderISOTZoneHandler.hpp>

using namespace std;

namespace cfsec {

	const std::string CFSecSaxLoaderISOTZoneHandler::CLASS_NAME( "CFSecSaxLoaderISOTZoneHandler" );
	const std::string CFSecSaxLoaderISOTZoneHandler::S_True( "true" );
	const std::string CFSecSaxLoaderISOTZoneHandler::S_False( "false" );
	const std::string CFSecSaxLoaderISOTZoneHandler::S_Yes( "yes" );
	const std::string CFSecSaxLoaderISOTZoneHandler::S_No( "no" );
	const std::string CFSecSaxLoaderISOTZoneHandler::S_0( "0" );
	const std::string CFSecSaxLoaderISOTZoneHandler::S_1( "1" );

	CFSecSaxLoaderISOTZoneHandler::CFSecSaxLoaderISOTZoneHandler( cfsec::CFSecSaxLoader* saxLoader )
	: cflib::CFLibXmlCoreElementHandler( saxLoader )
	{
	}

	CFSecSaxLoaderISOTZoneHandler::~CFSecSaxLoaderISOTZoneHandler() {
	}

	void CFSecSaxLoaderISOTZoneHandler::startElement (
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
		static const std::string S_ISOTZoneId( "ISOTZoneId" );
		static const std::string S_Iso8601( "Iso8601" );
		static const std::string S_TZName( "TZName" );
		static const std::string S_TZHourOffset( "TZHourOffset" );
		static const std::string S_TZMinOffset( "TZMinOffset" );
		static const std::string S_Description( "Description" );
		static const std::string S_Visible( "Visible" );
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
		cfsec::ICFSecISOTZoneObj* tmpBuff = NULL;
		cfsec::ICFSecISOTZoneEditObj* editBuff = NULL;
		cfsec::ICFSecISOTZoneEditObj* editISOTZone = NULL;
		cfsec::ICFSecISOTZoneObj* origISOTZone = NULL;
		cflib::CFLibXmlCoreContext* parentContext = NULL;
		cflib::ICFLibAnyObj* scopeObj = NULL;
		// Common XML Attributes
		std::string* attrId = NULL;
		// ISOTZone Attributes
		std::string* attrIso8601 = NULL;
		std::string* attrTZName = NULL;
		std::string* attrTZHourOffset = NULL;
		std::string* attrTZMinOffset = NULL;
		std::string* attrDescription = NULL;
		std::string* attrVisible = NULL;
		// ISOTZone References
		std::string* natIso8601 = NULL;
		std::string* natTZName = NULL;
		int16_t natTZHourOffset;
		int16_t natTZMinOffset;
		std::string* natDescription = NULL;
		bool natVisible;
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
			if( cppQName != cfsec::CFSecISOTZoneBuff::GENDEFNAME ) {
				std::string Msg( "Expected QName to be '" + cfsec::CFSecISOTZoneBuff::GENDEFNAME + "'" );
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
			tmpBuff = schemaObj->getISOTZoneTableObj()->newInstance();
			editBuff = dynamic_cast<cfsec::ICFSecISOTZoneEditObj*>( tmpBuff->beginEdit() );

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
				else if( *attrLocalName == S_Iso8601 ) {
					if( attrIso8601 != NULL ) {
						throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
							S_ProcName,
							*attrLocalName );
					}
					if( cppValue != NULL ) {
						attrIso8601 = new std::string( *cppValue );
					}
					else {
						attrIso8601 = NULL;
					}
				}
				else if( *attrLocalName == S_TZName ) {
					if( attrTZName != NULL ) {
						throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
							S_ProcName,
							*attrLocalName );
					}
					if( cppValue != NULL ) {
						attrTZName = new std::string( *cppValue );
					}
					else {
						attrTZName = NULL;
					}
				}
				else if( *attrLocalName == S_TZHourOffset ) {
					if( attrTZHourOffset != NULL ) {
						throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
							S_ProcName,
							*attrLocalName );
					}
					if( cppValue != NULL ) {
						attrTZHourOffset = new std::string( *cppValue );
					}
					else {
						attrTZHourOffset = NULL;
					}
				}
				else if( *attrLocalName == S_TZMinOffset ) {
					if( attrTZMinOffset != NULL ) {
						throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
							S_ProcName,
							*attrLocalName );
					}
					if( cppValue != NULL ) {
						attrTZMinOffset = new std::string( *cppValue );
					}
					else {
						attrTZMinOffset = NULL;
					}
				}
				else if( *attrLocalName == S_Description ) {
					if( attrDescription != NULL ) {
						throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
							S_ProcName,
							*attrLocalName );
					}
					if( cppValue != NULL ) {
						attrDescription = new std::string( *cppValue );
					}
					else {
						attrDescription = NULL;
					}
				}
				else if( *attrLocalName == S_Visible ) {
					if( attrVisible != NULL ) {
						throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
							S_ProcName,
							*attrLocalName );
					}
					if( cppValue != NULL ) {
						attrVisible = new std::string( *cppValue );
					}
					else {
						attrVisible = NULL;
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
			if( attrIso8601 == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Iso8601 );
			}
			if( attrTZName == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_TZName );
			}
			if( ( attrTZHourOffset == NULL ) || ( attrTZHourOffset->length() <= 0 ) ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_TZHourOffset );
			}
			if( ( attrTZMinOffset == NULL ) || ( attrTZMinOffset->length() <= 0 ) ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_TZMinOffset );
			}
			if( attrDescription == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Description );
			}
			if( ( attrVisible == NULL ) || ( attrVisible->length() <= 0 ) ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Visible );
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
			if( attrIso8601 != NULL ) {
				curContext->putNamedTag( S_Iso8601, *attrIso8601 );
			}
			if( attrTZName != NULL ) {
				curContext->putNamedTag( S_TZName, *attrTZName );
			}
			if( attrTZHourOffset != NULL ) {
				curContext->putNamedTag( S_TZHourOffset, *attrTZHourOffset );
			}
			if( attrTZMinOffset != NULL ) {
				curContext->putNamedTag( S_TZMinOffset, *attrTZMinOffset );
			}
			if( attrDescription != NULL ) {
				curContext->putNamedTag( S_Description, *attrDescription );
			}
			if( attrVisible != NULL ) {
				curContext->putNamedTag( S_Visible, *attrVisible );
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
			if( attrIso8601 != NULL ) {
				natIso8601 = new std::string( *attrIso8601 );
			}
			else {
				natIso8601 = NULL;
			}
			if( natIso8601 == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Iso8601 );
			}
			editBuff->setRequiredIso8601( *natIso8601 );

			if( attrTZName != NULL ) {
				natTZName = new std::string( *attrTZName );
			}
			else {
				natTZName = NULL;
			}
			if( natTZName == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_TZName );
			}
			editBuff->setRequiredTZName( *natTZName );

			natTZHourOffset = cflib::CFLibXmlUtil::evalInt16( *attrTZHourOffset );
			editBuff->setRequiredTZHourOffset( natTZHourOffset );

			natTZMinOffset = cflib::CFLibXmlUtil::evalInt16( *attrTZMinOffset );
			editBuff->setRequiredTZMinOffset( natTZMinOffset );

			if( attrDescription != NULL ) {
				natDescription = new std::string( *attrDescription );
			}
			else {
				natDescription = NULL;
			}
			if( natDescription == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Description );
			}
			editBuff->setRequiredDescription( *natDescription );

			if( ( *attrVisible == S_True ) || ( *attrVisible == S_Yes ) || ( *attrVisible == S_1 ) ) {
				natVisible = true;
			}
			else if( ( *attrVisible == S_False ) || ( *attrVisible == S_No ) || ( *attrVisible == S_0 ) ) {
				natVisible = false;
			}
			else {
				throw cflib::CFLibInvalidArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Visible,
					*attrVisible );
			}
			editBuff->setRequiredVisible( natVisible );

			// Get the scope/container object

			parentContext = curContext->getPrevContext();
			if( parentContext != NULL ) {
				scopeObj = parentContext->getObj();
			}
			else {
				scopeObj = NULL;
			}

			loaderBehaviour = saxLoader->getISOTZoneLoaderBehaviour();
			origISOTZone = dynamic_cast<cfsec::ICFSecISOTZoneObj*>( schemaObj->getISOTZoneTableObj()->readISOTZoneByUTZNameIdx( editBuff->getRequiredTZName() ) );
			if( origISOTZone == NULL ) {
				editISOTZone = editBuff;
				editBuff = NULL;
			}
			else {
				switch( loaderBehaviour ) {
					case cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Insert:
						editISOTZone = NULL;
						editBuff->endEdit();
						editBuff = NULL;
						break;
					case cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Update:
						editISOTZone = dynamic_cast<cfsec::ICFSecISOTZoneEditObj*>( origISOTZone->beginEdit() );
						editISOTZone->setRequiredIso8601( editBuff->getRequiredIso8601() );
						editISOTZone->setRequiredTZName( editBuff->getRequiredTZName() );
						editISOTZone->setRequiredTZHourOffset( editBuff->getRequiredTZHourOffset() );
						editISOTZone->setRequiredTZMinOffset( editBuff->getRequiredTZMinOffset() );
						editISOTZone->setRequiredDescription( editBuff->getRequiredDescription() );
						editISOTZone->setRequiredVisible( editBuff->getRequiredVisible() );
						editBuff->endEdit();
						editBuff = NULL;
						break;
					case cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Replace:
						editISOTZone = dynamic_cast<cfsec::ICFSecISOTZoneEditObj*>( origISOTZone->beginEdit() );
						editISOTZone->deleteInstance();
						editISOTZone = NULL;
						origISOTZone = NULL;
						editISOTZone = editBuff;
						editBuff = NULL;
						break;
				}
			}

			if( editISOTZone != NULL ) {
				if( origISOTZone != NULL ) {
					editISOTZone->update();
				}
				else {
					origISOTZone = dynamic_cast<cfsec::ICFSecISOTZoneObj*>( editISOTZone->create() );
				}
				editISOTZone = NULL;
			}

			if( ! tmpBuff->getIsNew() ) {
				tmpBuff = NULL;
			}

			curContext->setObj( origISOTZone );

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

		if( natIso8601 != NULL ) {
			delete natIso8601;
			natIso8601 = NULL;
		}

		if( natTZName != NULL ) {
			delete natTZName;
			natTZName = NULL;
		}

		if( natDescription != NULL ) {
			delete natDescription;
			natDescription = NULL;
		}

		if( attrIso8601 != NULL ) {
			delete attrIso8601;
			attrIso8601 = NULL;
		}

		if( attrTZName != NULL ) {
			delete attrTZName;
			attrTZName = NULL;
		}

		if( attrTZHourOffset != NULL ) {
			delete attrTZHourOffset;
			attrTZHourOffset = NULL;
		}

		if( attrTZMinOffset != NULL ) {
			delete attrTZMinOffset;
			attrTZMinOffset = NULL;
		}

		if( attrDescription != NULL ) {
			delete attrDescription;
			attrDescription = NULL;
		}

		if( attrVisible != NULL ) {
			delete attrVisible;
			attrVisible = NULL;
		}

		if( editISOTZone != NULL ) {
			editISOTZone->endEdit();
			editISOTZone = NULL;
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

	void CFSecSaxLoaderISOTZoneHandler::endElement(
		const XMLCh* const uri,
		const XMLCh* const localname,
		const XMLCh* const qname )
	{
	}
}
