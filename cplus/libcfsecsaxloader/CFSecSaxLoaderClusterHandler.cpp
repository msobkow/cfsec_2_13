
// Description: C++18 XML SAX2 Element Handler implementation for Cluster

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
#include <cfsecsaxloader/CFSecSaxLoaderClusterHandler.hpp>

using namespace std;

namespace cfsec {

	const std::string CFSecSaxLoaderClusterHandler::CLASS_NAME( "CFSecSaxLoaderClusterHandler" );
	const std::string CFSecSaxLoaderClusterHandler::S_True( "true" );
	const std::string CFSecSaxLoaderClusterHandler::S_False( "false" );
	const std::string CFSecSaxLoaderClusterHandler::S_Yes( "yes" );
	const std::string CFSecSaxLoaderClusterHandler::S_No( "no" );
	const std::string CFSecSaxLoaderClusterHandler::S_0( "0" );
	const std::string CFSecSaxLoaderClusterHandler::S_1( "1" );

	CFSecSaxLoaderClusterHandler::CFSecSaxLoaderClusterHandler( cfsec::CFSecSaxLoader* saxLoader )
	: cflib::CFLibXmlCoreElementHandler( saxLoader )
	{
	}

	CFSecSaxLoaderClusterHandler::~CFSecSaxLoaderClusterHandler() {
	}

	void CFSecSaxLoaderClusterHandler::startElement (
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
		const static std::string S_QName( "qname" );
		static const std::string S_Id( "Id" );
		static const std::string S_FullDomName( "FullDomName" );
		static const std::string S_Description( "Description" );
		static const std::string S_HostNode( "HostNode" );
		static const std::string S_Tenant( "Tenant" );
		static const std::string S_SecApp( "SecApp" );
		static const std::string S_SecGroup( "SecGroup" );
		static const std::string S_SysCluster( "SysCluster" );
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
		cfsec::ICFSecClusterObj* tmpBuff = NULL;
		cfsec::ICFSecClusterEditObj* editBuff = NULL;
		cfsec::ICFSecClusterEditObj* editCluster = NULL;
		cfsec::ICFSecClusterObj* origCluster = NULL;
		cfsec::ICFSecClusterObj* useCluster = NULL;
		cflib::CFLibXmlCoreContext* parentContext = NULL;
		cflib::ICFLibAnyObj* scopeObj = NULL;
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
			if( cppQName != cfsec::CFSecClusterBuff::GENDEFNAME ) {
				std::string Msg( "Expected QName to be '" + cfsec::CFSecClusterBuff::GENDEFNAME + "'" );
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					Msg );
			}

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

			curContext = getParser()->getCurContext();
			if( curContext == NULL ) {
				static const std::string S_CurContext( "getParser()->getCurContext" );
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_CurContext );
			}

			useCluster = saxLoader->getUseCluster();
			if( useCluster == NULL ) {
				const static std::string S_LoaderUseCluster( "saxLoader->useCluster" );
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_LoaderUseCluster );
			}

			curContext->setObj( useCluster );
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

		CFLIB_EXCEPTION_RETHROW_SAXEXCEPTION
	}

	void CFSecSaxLoaderClusterHandler::endElement(
		const XMLCh* const uri,
		const XMLCh* const localname,
		const XMLCh* const qname )
	{
	}
}
