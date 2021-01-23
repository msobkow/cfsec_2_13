// Description: C++18 XML SAX Parser implementation for CFSec.

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
#include <fstream>
#include <cflib/ICFLibPublic.hpp>
#include <cfsec/ICFSecPublic.hpp>
#include <cfsecobj/ICFSecObjPublic.hpp>
#include <cfsecsaxloader/CFSecSaxLoader.hpp>
#include <cfsecsaxloader/CFSecSaxLoaderClusterHandler.hpp>
#include <cfsecsaxloader/CFSecSaxLoaderHostNodeHandler.hpp>
#include <cfsecsaxloader/CFSecSaxLoaderISOCcyHandler.hpp>
#include <cfsecsaxloader/CFSecSaxLoaderISOCtryHandler.hpp>
#include <cfsecsaxloader/CFSecSaxLoaderISOCtryCcyHandler.hpp>
#include <cfsecsaxloader/CFSecSaxLoaderISOCtryLangHandler.hpp>
#include <cfsecsaxloader/CFSecSaxLoaderISOLangHandler.hpp>
#include <cfsecsaxloader/CFSecSaxLoaderISOTZoneHandler.hpp>
#include <cfsecsaxloader/CFSecSaxLoaderSecAppHandler.hpp>
#include <cfsecsaxloader/CFSecSaxLoaderSecDeviceHandler.hpp>
#include <cfsecsaxloader/CFSecSaxLoaderSecFormHandler.hpp>
#include <cfsecsaxloader/CFSecSaxLoaderSecGroupHandler.hpp>
#include <cfsecsaxloader/CFSecSaxLoaderSecGroupFormHandler.hpp>
#include <cfsecsaxloader/CFSecSaxLoaderSecGrpIncHandler.hpp>
#include <cfsecsaxloader/CFSecSaxLoaderSecGrpMembHandler.hpp>
#include <cfsecsaxloader/CFSecSaxLoaderSecSessionHandler.hpp>
#include <cfsecsaxloader/CFSecSaxLoaderSecUserHandler.hpp>
#include <cfsecsaxloader/CFSecSaxLoaderServiceHandler.hpp>
#include <cfsecsaxloader/CFSecSaxLoaderServiceTypeHandler.hpp>
#include <cfsecsaxloader/CFSecSaxLoaderSysClusterHandler.hpp>
#include <cfsecsaxloader/CFSecSaxLoaderTSecGroupHandler.hpp>
#include <cfsecsaxloader/CFSecSaxLoaderTSecGrpIncHandler.hpp>
#include <cfsecsaxloader/CFSecSaxLoaderTSecGrpMembHandler.hpp>
#include <cfsecsaxloader/CFSecSaxLoaderTenantHandler.hpp>

using namespace std;

namespace cfsec {

	CFSecSaxRootHandler::CFSecSaxRootHandler( cfsec::CFSecSaxLoader* saxLoader )
	: cflib::CFLibXmlCoreElementHandler( saxLoader )
	{
	}

	CFSecSaxRootHandler::~CFSecSaxRootHandler() {
	}

	/**
	 * Receive notification of the beginning of an element.
	 *
	 * <p>The Parser will invoke this method at the beginning of every
	 * element in the XML document; there will be a corresponding
	 * endElement() event for every startElement() event (even when the
	 * element is empty). All of the element's content will be
	 * reported, in order, before the corresponding endElement()
	 * event.</p>
	 *
	 * <p>Note that the attribute list provided will
	 * contain only attributes with explicit values (specified or
	 * defaulted): \#IMPLIED attributes will be omitted.</p>
	 *
	 * @param uri The URI of the associated namespace for this element
	 * @param localname The local part of the element name
	 * @param qname The QName of this element
	 * @param attrs The attributes attached to the element, if any.
	 * @exception SAXException Any SAX exception, possibly
	 *			wrapping another exception.
	 * @see #endElement
	 * @see Attributes#Attributes
	 */
	void CFSecSaxRootHandler::startElement (
		const XMLCh* const uri,
		const XMLCh* const localname,
		const XMLCh* const qname,
		const xercesc::Attributes& attrs )
	{
	}

	/**
	 * Receive notification of the end of an element.
	 *
	 * <p>The SAX parser will invoke this method at the end of every
	 * element in the XML document; there will be a corresponding
	 * startElement() event for every endElement() event (even when the
	 * element is empty).</p>
	 *
	 * @param uri The URI of the associated namespace for this element
	 * @param localname The local part of the element name
	 * @param qname The QName of this element
	 * @exception SAXException Any SAX exception, possibly
	 *			wrapping another exception.
	 */
	void CFSecSaxRootHandler::endElement (
		const XMLCh* const uri,
		const XMLCh* const localname,
		const XMLCh* const qname )
	{
	}


	CFSecSaxDocHandler::CFSecSaxDocHandler( cfsec::CFSecSaxLoader* saxLoader )
	: cflib::CFLibXmlCoreElementHandler( saxLoader )
	{
	}

	CFSecSaxDocHandler::~CFSecSaxDocHandler() {
	}

	/**
	 * Receive notification of the beginning of an element.
	 *
	 * <p>The Parser will invoke this method at the beginning of every
	 * element in the XML document; there will be a corresponding
	 * endElement() event for every startElement() event (even when the
	 * element is empty). All of the element's content will be
	 * reported, in order, before the corresponding endElement()
	 * event.</p>
	 *
	 * <p>Note that the attribute list provided will
	 * contain only attributes with explicit values (specified or
	 * defaulted): \#IMPLIED attributes will be omitted.</p>
	 *
	 * @param uri The URI of the associated namespace for this element
	 * @param localname The local part of the element name
	 * @param qname The QName of this element
	 * @param attrs The attributes attached to the element, if any.
	 * @exception SAXException Any SAX exception, possibly
	 *			wrapping another exception.
	 * @see #endElement
	 * @see Attributes#Attributes
	 */
	void CFSecSaxDocHandler::startElement (
		const XMLCh* const uri,
		const XMLCh* const localname,
		const XMLCh* const qname,
		const xercesc::Attributes& attrs )
	{
	}

	/**
	 * Receive notification of the end of an element.
	 *
	 * <p>The SAX parser will invoke this method at the end of every
	 * element in the XML document; there will be a corresponding
	 * startElement() event for every endElement() event (even when the
	 * element is empty).</p>
	 *
	 * @param uri The URI of the associated namespace for this element
	 * @param localname The local part of the element name
	 * @param qname The QName of this element
	 * @exception SAXException Any SAX exception, possibly
	 *			wrapping another exception.
	 */
	void CFSecSaxDocHandler::endElement (
		const XMLCh* const uri,
		const XMLCh* const localname,
		const XMLCh* const qname )
	{
	}

	const std::string CFSecSaxLoader::CLASS_NAME( "CFSecSaxLoader" );
	const std::string CFSecSaxLoader::SCHEMA_XMLNS( "uri://org.msscf/msscf/2.0.13/cfsecloader" );
	const std::string CFSecSaxLoader::SCHEMA_URI( "/opt/msscf/2.0.13/xsd/cfsec-structured.xsd" );
	bool CFSecSaxLoader::grammarLoaded = false;

	CFSecSaxLoader::CFSecSaxLoader()
	: cflib::CFLibXmlCoreSaxParser()
	{
		schemaObj = NULL;
		saxRootHandler = NULL;
		saxDocHandler = NULL;
		clusterHandler = NULL;
		hostNodeHandler = NULL;
		iSOCcyHandler = NULL;
		iSOCtryHandler = NULL;
		iSOCtryCcyHandler = NULL;
		iSOCtryLangHandler = NULL;
		iSOLangHandler = NULL;
		iSOTZoneHandler = NULL;
		secAppHandler = NULL;
		secDeviceHandler = NULL;
		secFormHandler = NULL;
		secGroupHandler = NULL;
		secGroupFormHandler = NULL;
		secGrpIncHandler = NULL;
		secGrpMembHandler = NULL;
		secSessionHandler = NULL;
		secUserHandler = NULL;
		serviceHandler = NULL;
		serviceTypeHandler = NULL;
		sysClusterHandler = NULL;
		tSecGroupHandler = NULL;
		tSecGrpIncHandler = NULL;
		tSecGrpMembHandler = NULL;
		tenantHandler = NULL;
		useCluster = NULL;
		useTenant = NULL;
		setRootElementHandler( getSaxRootHandler() );
		verifyGrammarInstallation();
		initParser();
	}

	CFSecSaxLoader::CFSecSaxLoader( cflib::ICFLibMessageLog* logger )
	: cflib::CFLibXmlCoreSaxParser( logger )
	{
		saxRootHandler = NULL;
		saxDocHandler = NULL;
		clusterHandler = NULL;
		hostNodeHandler = NULL;
		iSOCcyHandler = NULL;
		iSOCtryHandler = NULL;
		iSOCtryCcyHandler = NULL;
		iSOCtryLangHandler = NULL;
		iSOLangHandler = NULL;
		iSOTZoneHandler = NULL;
		secAppHandler = NULL;
		secDeviceHandler = NULL;
		secFormHandler = NULL;
		secGroupHandler = NULL;
		secGroupFormHandler = NULL;
		secGrpIncHandler = NULL;
		secGrpMembHandler = NULL;
		secSessionHandler = NULL;
		secUserHandler = NULL;
		serviceHandler = NULL;
		serviceTypeHandler = NULL;
		sysClusterHandler = NULL;
		tSecGroupHandler = NULL;
		tSecGrpIncHandler = NULL;
		tSecGrpMembHandler = NULL;
		tenantHandler = NULL;
		useCluster = NULL;
		useTenant = NULL;
		setRootElementHandler( getSaxRootHandler() );
		verifyGrammarInstallation();
		initParser();
	}

	CFSecSaxLoader::~CFSecSaxLoader() {
		if( clusterHandler != NULL ) {
			delete clusterHandler;
			clusterHandler = NULL;
		}
		if( hostNodeHandler != NULL ) {
			delete hostNodeHandler;
			hostNodeHandler = NULL;
		}
		if( iSOCcyHandler != NULL ) {
			delete iSOCcyHandler;
			iSOCcyHandler = NULL;
		}
		if( iSOCtryHandler != NULL ) {
			delete iSOCtryHandler;
			iSOCtryHandler = NULL;
		}
		if( iSOCtryCcyHandler != NULL ) {
			delete iSOCtryCcyHandler;
			iSOCtryCcyHandler = NULL;
		}
		if( iSOCtryLangHandler != NULL ) {
			delete iSOCtryLangHandler;
			iSOCtryLangHandler = NULL;
		}
		if( iSOLangHandler != NULL ) {
			delete iSOLangHandler;
			iSOLangHandler = NULL;
		}
		if( iSOTZoneHandler != NULL ) {
			delete iSOTZoneHandler;
			iSOTZoneHandler = NULL;
		}
		if( secAppHandler != NULL ) {
			delete secAppHandler;
			secAppHandler = NULL;
		}
		if( secDeviceHandler != NULL ) {
			delete secDeviceHandler;
			secDeviceHandler = NULL;
		}
		if( secFormHandler != NULL ) {
			delete secFormHandler;
			secFormHandler = NULL;
		}
		if( secGroupHandler != NULL ) {
			delete secGroupHandler;
			secGroupHandler = NULL;
		}
		if( secGroupFormHandler != NULL ) {
			delete secGroupFormHandler;
			secGroupFormHandler = NULL;
		}
		if( secGrpIncHandler != NULL ) {
			delete secGrpIncHandler;
			secGrpIncHandler = NULL;
		}
		if( secGrpMembHandler != NULL ) {
			delete secGrpMembHandler;
			secGrpMembHandler = NULL;
		}
		if( secSessionHandler != NULL ) {
			delete secSessionHandler;
			secSessionHandler = NULL;
		}
		if( secUserHandler != NULL ) {
			delete secUserHandler;
			secUserHandler = NULL;
		}
		if( serviceHandler != NULL ) {
			delete serviceHandler;
			serviceHandler = NULL;
		}
		if( serviceTypeHandler != NULL ) {
			delete serviceTypeHandler;
			serviceTypeHandler = NULL;
		}
		if( sysClusterHandler != NULL ) {
			delete sysClusterHandler;
			sysClusterHandler = NULL;
		}
		if( tSecGroupHandler != NULL ) {
			delete tSecGroupHandler;
			tSecGroupHandler = NULL;
		}
		if( tSecGrpIncHandler != NULL ) {
			delete tSecGrpIncHandler;
			tSecGrpIncHandler = NULL;
		}
		if( tSecGrpMembHandler != NULL ) {
			delete tSecGrpMembHandler;
			tSecGrpMembHandler = NULL;
		}
		if( tenantHandler != NULL ) {
			delete tenantHandler;
			tenantHandler = NULL;
		}
		if( saxDocHandler != NULL ) {
			delete saxDocHandler;
			saxDocHandler = NULL;
		}
		if( saxRootHandler != NULL ) {
			delete saxRootHandler;
			saxRootHandler = NULL;
		}
	}

	void CFSecSaxLoader::initParser() {
		if( saxXmlReader != NULL ) {
			return;
		}
		cflib::CFLibXmlCoreSaxParser::initParser();
		loadGrammar( SCHEMA_URI );
	}

	cfsec::ICFSecClusterObj* CFSecSaxLoader::getUseCluster() const {
		return( useCluster );
	}

	void CFSecSaxLoader::setUseCluster( cfsec::ICFSecClusterObj* value ) {
		useCluster = value;
	}

	cfsec::ICFSecTenantObj* CFSecSaxLoader::getUseTenant() {
		return( useTenant );
	}

	void CFSecSaxLoader::setUseTenant( cfsec::ICFSecTenantObj* value ) {
		useTenant = value;
	}

	// SchemaObj accessors

	cfsec::ICFSecSchemaObj* CFSecSaxLoader::getSchemaObj() const {
		return( schemaObj );
	}

	void CFSecSaxLoader::setSchemaObj( cfsec::ICFSecSchemaObj* value ) {
		schemaObj = value;
	}

	void CFSecSaxLoader::verifyGrammarInstallation() {
		static const std::string S_ProcName( "verifyGrammarInstallation" );
		static const std::string S_MsgMustInstallXsdFirst( "The XSD file " + SCHEMA_URI + " must be installed first" );
		if( grammarLoaded ) {
			return;
		}
		std::ifstream xsdfile( SCHEMA_URI.data() );
		if( ! xsdfile ) {
			throw cflib::CFLibUsageException( CLASS_NAME,
				S_ProcName,
				S_MsgMustInstallXsdFirst );
		}
		grammarLoaded = true;
	}

	cfsec::CFSecSaxLoaderClusterHandler* CFSecSaxLoader::getClusterHandler() {
		if( clusterHandler == NULL ) {
			clusterHandler = new cfsec::CFSecSaxLoaderClusterHandler( this );
			clusterHandler->addElementHandler( cfsec::CFSecHostNodeBuff::GENDEFNAME, getHostNodeHandler() );
			clusterHandler->addElementHandler( cfsec::CFSecTenantBuff::GENDEFNAME, getTenantHandler() );
			clusterHandler->addElementHandler( cfsec::CFSecSecAppBuff::GENDEFNAME, getSecAppHandler() );
			clusterHandler->addElementHandler( cfsec::CFSecSecGroupBuff::GENDEFNAME, getSecGroupHandler() );
			clusterHandler->addElementHandler( cfsec::CFSecSysClusterBuff::GENDEFNAME, getSysClusterHandler() );
		}
		return( clusterHandler );
	}

	cfsec::CFSecSaxLoaderHostNodeHandler* CFSecSaxLoader::getHostNodeHandler() {
		if( hostNodeHandler == NULL ) {
			hostNodeHandler = new cfsec::CFSecSaxLoaderHostNodeHandler( this );
			hostNodeHandler->addElementHandler( cfsec::CFSecServiceBuff::GENDEFNAME, getServiceHandler() );
		}
		return( hostNodeHandler );
	}

	cfsec::CFSecSaxLoaderISOCcyHandler* CFSecSaxLoader::getISOCcyHandler() {
		if( iSOCcyHandler == NULL ) {
			iSOCcyHandler = new cfsec::CFSecSaxLoaderISOCcyHandler( this );
		}
		return( iSOCcyHandler );
	}

	cfsec::CFSecSaxLoaderISOCtryHandler* CFSecSaxLoader::getISOCtryHandler() {
		if( iSOCtryHandler == NULL ) {
			iSOCtryHandler = new cfsec::CFSecSaxLoaderISOCtryHandler( this );
			iSOCtryHandler->addElementHandler( cfsec::CFSecISOCtryCcyBuff::GENDEFNAME, getISOCtryCcyHandler() );
			iSOCtryHandler->addElementHandler( cfsec::CFSecISOCtryLangBuff::GENDEFNAME, getISOCtryLangHandler() );
		}
		return( iSOCtryHandler );
	}

	cfsec::CFSecSaxLoaderISOCtryCcyHandler* CFSecSaxLoader::getISOCtryCcyHandler() {
		if( iSOCtryCcyHandler == NULL ) {
			iSOCtryCcyHandler = new cfsec::CFSecSaxLoaderISOCtryCcyHandler( this );
		}
		return( iSOCtryCcyHandler );
	}

	cfsec::CFSecSaxLoaderISOCtryLangHandler* CFSecSaxLoader::getISOCtryLangHandler() {
		if( iSOCtryLangHandler == NULL ) {
			iSOCtryLangHandler = new cfsec::CFSecSaxLoaderISOCtryLangHandler( this );
		}
		return( iSOCtryLangHandler );
	}

	cfsec::CFSecSaxLoaderISOLangHandler* CFSecSaxLoader::getISOLangHandler() {
		if( iSOLangHandler == NULL ) {
			iSOLangHandler = new cfsec::CFSecSaxLoaderISOLangHandler( this );
		}
		return( iSOLangHandler );
	}

	cfsec::CFSecSaxLoaderISOTZoneHandler* CFSecSaxLoader::getISOTZoneHandler() {
		if( iSOTZoneHandler == NULL ) {
			iSOTZoneHandler = new cfsec::CFSecSaxLoaderISOTZoneHandler( this );
		}
		return( iSOTZoneHandler );
	}

	cfsec::CFSecSaxLoaderSecAppHandler* CFSecSaxLoader::getSecAppHandler() {
		if( secAppHandler == NULL ) {
			secAppHandler = new cfsec::CFSecSaxLoaderSecAppHandler( this );
			secAppHandler->addElementHandler( cfsec::CFSecSecFormBuff::GENDEFNAME, getSecFormHandler() );
		}
		return( secAppHandler );
	}

	cfsec::CFSecSaxLoaderSecDeviceHandler* CFSecSaxLoader::getSecDeviceHandler() {
		if( secDeviceHandler == NULL ) {
			secDeviceHandler = new cfsec::CFSecSaxLoaderSecDeviceHandler( this );
		}
		return( secDeviceHandler );
	}

	cfsec::CFSecSaxLoaderSecFormHandler* CFSecSaxLoader::getSecFormHandler() {
		if( secFormHandler == NULL ) {
			secFormHandler = new cfsec::CFSecSaxLoaderSecFormHandler( this );
		}
		return( secFormHandler );
	}

	cfsec::CFSecSaxLoaderSecGroupHandler* CFSecSaxLoader::getSecGroupHandler() {
		if( secGroupHandler == NULL ) {
			secGroupHandler = new cfsec::CFSecSaxLoaderSecGroupHandler( this );
			secGroupHandler->addElementHandler( cfsec::CFSecSecGrpIncBuff::GENDEFNAME, getSecGrpIncHandler() );
			secGroupHandler->addElementHandler( cfsec::CFSecSecGrpMembBuff::GENDEFNAME, getSecGrpMembHandler() );
			secGroupHandler->addElementHandler( cfsec::CFSecSecGroupFormBuff::GENDEFNAME, getSecGroupFormHandler() );
		}
		return( secGroupHandler );
	}

	cfsec::CFSecSaxLoaderSecGroupFormHandler* CFSecSaxLoader::getSecGroupFormHandler() {
		if( secGroupFormHandler == NULL ) {
			secGroupFormHandler = new cfsec::CFSecSaxLoaderSecGroupFormHandler( this );
		}
		return( secGroupFormHandler );
	}

	cfsec::CFSecSaxLoaderSecGrpIncHandler* CFSecSaxLoader::getSecGrpIncHandler() {
		if( secGrpIncHandler == NULL ) {
			secGrpIncHandler = new cfsec::CFSecSaxLoaderSecGrpIncHandler( this );
		}
		return( secGrpIncHandler );
	}

	cfsec::CFSecSaxLoaderSecGrpMembHandler* CFSecSaxLoader::getSecGrpMembHandler() {
		if( secGrpMembHandler == NULL ) {
			secGrpMembHandler = new cfsec::CFSecSaxLoaderSecGrpMembHandler( this );
		}
		return( secGrpMembHandler );
	}

	cfsec::CFSecSaxLoaderSecSessionHandler* CFSecSaxLoader::getSecSessionHandler() {
		if( secSessionHandler == NULL ) {
			secSessionHandler = new cfsec::CFSecSaxLoaderSecSessionHandler( this );
		}
		return( secSessionHandler );
	}

	cfsec::CFSecSaxLoaderSecUserHandler* CFSecSaxLoader::getSecUserHandler() {
		if( secUserHandler == NULL ) {
			secUserHandler = new cfsec::CFSecSaxLoaderSecUserHandler( this );
			secUserHandler->addElementHandler( cfsec::CFSecSecDeviceBuff::GENDEFNAME, getSecDeviceHandler() );
			secUserHandler->addElementHandler( cfsec::CFSecSecSessionBuff::GENDEFNAME, getSecSessionHandler() );
		}
		return( secUserHandler );
	}

	cfsec::CFSecSaxLoaderServiceHandler* CFSecSaxLoader::getServiceHandler() {
		if( serviceHandler == NULL ) {
			serviceHandler = new cfsec::CFSecSaxLoaderServiceHandler( this );
		}
		return( serviceHandler );
	}

	cfsec::CFSecSaxLoaderServiceTypeHandler* CFSecSaxLoader::getServiceTypeHandler() {
		if( serviceTypeHandler == NULL ) {
			serviceTypeHandler = new cfsec::CFSecSaxLoaderServiceTypeHandler( this );
		}
		return( serviceTypeHandler );
	}

	cfsec::CFSecSaxLoaderSysClusterHandler* CFSecSaxLoader::getSysClusterHandler() {
		if( sysClusterHandler == NULL ) {
			sysClusterHandler = new cfsec::CFSecSaxLoaderSysClusterHandler( this );
		}
		return( sysClusterHandler );
	}

	cfsec::CFSecSaxLoaderTSecGroupHandler* CFSecSaxLoader::getTSecGroupHandler() {
		if( tSecGroupHandler == NULL ) {
			tSecGroupHandler = new cfsec::CFSecSaxLoaderTSecGroupHandler( this );
			tSecGroupHandler->addElementHandler( cfsec::CFSecTSecGrpIncBuff::GENDEFNAME, getTSecGrpIncHandler() );
			tSecGroupHandler->addElementHandler( cfsec::CFSecTSecGrpMembBuff::GENDEFNAME, getTSecGrpMembHandler() );
		}
		return( tSecGroupHandler );
	}

	cfsec::CFSecSaxLoaderTSecGrpIncHandler* CFSecSaxLoader::getTSecGrpIncHandler() {
		if( tSecGrpIncHandler == NULL ) {
			tSecGrpIncHandler = new cfsec::CFSecSaxLoaderTSecGrpIncHandler( this );
		}
		return( tSecGrpIncHandler );
	}

	cfsec::CFSecSaxLoaderTSecGrpMembHandler* CFSecSaxLoader::getTSecGrpMembHandler() {
		if( tSecGrpMembHandler == NULL ) {
			tSecGrpMembHandler = new cfsec::CFSecSaxLoaderTSecGrpMembHandler( this );
		}
		return( tSecGrpMembHandler );
	}

	cfsec::CFSecSaxLoaderTenantHandler* CFSecSaxLoader::getTenantHandler() {
		if( tenantHandler == NULL ) {
			tenantHandler = new cfsec::CFSecSaxLoaderTenantHandler( this );
			tenantHandler->addElementHandler( cfsec::CFSecTSecGroupBuff::GENDEFNAME, getTSecGroupHandler() );
		}
		return( tenantHandler );
	}

	cfsec::CFSecSaxRootHandler* CFSecSaxLoader::getSaxRootHandler() {
		const static std::string S_SchemaName( "CFSec" );
		if( saxRootHandler == NULL ) {
			saxRootHandler = new cfsec::CFSecSaxRootHandler( this );
			saxRootHandler->addElementHandler( S_SchemaName, getSaxDocHandler() );
		}
		return( saxRootHandler );
	}

	cfsec::CFSecSaxDocHandler* CFSecSaxLoader::getSaxDocHandler() {
		if( saxDocHandler == NULL ) {
			saxDocHandler = new CFSecSaxDocHandler( this );
			saxDocHandler->addElementHandler( cfsec::CFSecClusterBuff::GENDEFNAME, getClusterHandler() );
			saxDocHandler->addElementHandler( cfsec::CFSecISOCcyBuff::GENDEFNAME, getISOCcyHandler() );
			saxDocHandler->addElementHandler( cfsec::CFSecISOCtryBuff::GENDEFNAME, getISOCtryHandler() );
			saxDocHandler->addElementHandler( cfsec::CFSecISOLangBuff::GENDEFNAME, getISOLangHandler() );
			saxDocHandler->addElementHandler( cfsec::CFSecISOTZoneBuff::GENDEFNAME, getISOTZoneHandler() );
			saxDocHandler->addElementHandler( cfsec::CFSecSecUserBuff::GENDEFNAME, getSecUserHandler() );
			saxDocHandler->addElementHandler( cfsec::CFSecServiceTypeBuff::GENDEFNAME, getServiceTypeHandler() );
		}
		return( saxDocHandler );
	}

	const cfsec::CFSecSaxLoader::LoaderBehaviourEnum CFSecSaxLoader::getClusterLoaderBehaviour() const {
		return( clusterLoaderBehaviour );
	}

	void CFSecSaxLoader::setClusterLoaderBehaviour( const cfsec::CFSecSaxLoader::LoaderBehaviourEnum value ) {
		clusterLoaderBehaviour = value;
	}

	const cfsec::CFSecSaxLoader::LoaderBehaviourEnum CFSecSaxLoader::getHostNodeLoaderBehaviour() const {
		return( hostNodeLoaderBehaviour );
	}

	void CFSecSaxLoader::setHostNodeLoaderBehaviour( const cfsec::CFSecSaxLoader::LoaderBehaviourEnum value ) {
		hostNodeLoaderBehaviour = value;
	}

	const cfsec::CFSecSaxLoader::LoaderBehaviourEnum CFSecSaxLoader::getISOCcyLoaderBehaviour() const {
		return( iSOCcyLoaderBehaviour );
	}

	void CFSecSaxLoader::setISOCcyLoaderBehaviour( const cfsec::CFSecSaxLoader::LoaderBehaviourEnum value ) {
		iSOCcyLoaderBehaviour = value;
	}

	const cfsec::CFSecSaxLoader::LoaderBehaviourEnum CFSecSaxLoader::getISOCtryLoaderBehaviour() const {
		return( iSOCtryLoaderBehaviour );
	}

	void CFSecSaxLoader::setISOCtryLoaderBehaviour( const cfsec::CFSecSaxLoader::LoaderBehaviourEnum value ) {
		iSOCtryLoaderBehaviour = value;
	}

	const cfsec::CFSecSaxLoader::LoaderBehaviourEnum CFSecSaxLoader::getISOCtryCcyLoaderBehaviour() const {
		return( iSOCtryCcyLoaderBehaviour );
	}

	void CFSecSaxLoader::setISOCtryCcyLoaderBehaviour( const cfsec::CFSecSaxLoader::LoaderBehaviourEnum value ) {
		iSOCtryCcyLoaderBehaviour = value;
	}

	const cfsec::CFSecSaxLoader::LoaderBehaviourEnum CFSecSaxLoader::getISOCtryLangLoaderBehaviour() const {
		return( iSOCtryLangLoaderBehaviour );
	}

	void CFSecSaxLoader::setISOCtryLangLoaderBehaviour( const cfsec::CFSecSaxLoader::LoaderBehaviourEnum value ) {
		iSOCtryLangLoaderBehaviour = value;
	}

	const cfsec::CFSecSaxLoader::LoaderBehaviourEnum CFSecSaxLoader::getISOLangLoaderBehaviour() const {
		return( iSOLangLoaderBehaviour );
	}

	void CFSecSaxLoader::setISOLangLoaderBehaviour( const cfsec::CFSecSaxLoader::LoaderBehaviourEnum value ) {
		iSOLangLoaderBehaviour = value;
	}

	const cfsec::CFSecSaxLoader::LoaderBehaviourEnum CFSecSaxLoader::getISOTZoneLoaderBehaviour() const {
		return( iSOTZoneLoaderBehaviour );
	}

	void CFSecSaxLoader::setISOTZoneLoaderBehaviour( const cfsec::CFSecSaxLoader::LoaderBehaviourEnum value ) {
		iSOTZoneLoaderBehaviour = value;
	}

	const cfsec::CFSecSaxLoader::LoaderBehaviourEnum CFSecSaxLoader::getSecAppLoaderBehaviour() const {
		return( secAppLoaderBehaviour );
	}

	void CFSecSaxLoader::setSecAppLoaderBehaviour( const cfsec::CFSecSaxLoader::LoaderBehaviourEnum value ) {
		secAppLoaderBehaviour = value;
	}

	const cfsec::CFSecSaxLoader::LoaderBehaviourEnum CFSecSaxLoader::getSecDeviceLoaderBehaviour() const {
		return( secDeviceLoaderBehaviour );
	}

	void CFSecSaxLoader::setSecDeviceLoaderBehaviour( const cfsec::CFSecSaxLoader::LoaderBehaviourEnum value ) {
		secDeviceLoaderBehaviour = value;
	}

	const cfsec::CFSecSaxLoader::LoaderBehaviourEnum CFSecSaxLoader::getSecFormLoaderBehaviour() const {
		return( secFormLoaderBehaviour );
	}

	void CFSecSaxLoader::setSecFormLoaderBehaviour( const cfsec::CFSecSaxLoader::LoaderBehaviourEnum value ) {
		secFormLoaderBehaviour = value;
	}

	const cfsec::CFSecSaxLoader::LoaderBehaviourEnum CFSecSaxLoader::getSecGroupLoaderBehaviour() const {
		return( secGroupLoaderBehaviour );
	}

	void CFSecSaxLoader::setSecGroupLoaderBehaviour( const cfsec::CFSecSaxLoader::LoaderBehaviourEnum value ) {
		secGroupLoaderBehaviour = value;
	}

	const cfsec::CFSecSaxLoader::LoaderBehaviourEnum CFSecSaxLoader::getSecGroupFormLoaderBehaviour() const {
		return( secGroupFormLoaderBehaviour );
	}

	void CFSecSaxLoader::setSecGroupFormLoaderBehaviour( const cfsec::CFSecSaxLoader::LoaderBehaviourEnum value ) {
		secGroupFormLoaderBehaviour = value;
	}

	const cfsec::CFSecSaxLoader::LoaderBehaviourEnum CFSecSaxLoader::getSecGrpIncLoaderBehaviour() const {
		return( secGrpIncLoaderBehaviour );
	}

	void CFSecSaxLoader::setSecGrpIncLoaderBehaviour( const cfsec::CFSecSaxLoader::LoaderBehaviourEnum value ) {
		secGrpIncLoaderBehaviour = value;
	}

	const cfsec::CFSecSaxLoader::LoaderBehaviourEnum CFSecSaxLoader::getSecGrpMembLoaderBehaviour() const {
		return( secGrpMembLoaderBehaviour );
	}

	void CFSecSaxLoader::setSecGrpMembLoaderBehaviour( const cfsec::CFSecSaxLoader::LoaderBehaviourEnum value ) {
		secGrpMembLoaderBehaviour = value;
	}

	const cfsec::CFSecSaxLoader::LoaderBehaviourEnum CFSecSaxLoader::getSecSessionLoaderBehaviour() const {
		return( secSessionLoaderBehaviour );
	}

	void CFSecSaxLoader::setSecSessionLoaderBehaviour( const cfsec::CFSecSaxLoader::LoaderBehaviourEnum value ) {
		secSessionLoaderBehaviour = value;
	}

	const cfsec::CFSecSaxLoader::LoaderBehaviourEnum CFSecSaxLoader::getSecUserLoaderBehaviour() const {
		return( secUserLoaderBehaviour );
	}

	void CFSecSaxLoader::setSecUserLoaderBehaviour( const cfsec::CFSecSaxLoader::LoaderBehaviourEnum value ) {
		secUserLoaderBehaviour = value;
	}

	const cfsec::CFSecSaxLoader::LoaderBehaviourEnum CFSecSaxLoader::getServiceLoaderBehaviour() const {
		return( serviceLoaderBehaviour );
	}

	void CFSecSaxLoader::setServiceLoaderBehaviour( const cfsec::CFSecSaxLoader::LoaderBehaviourEnum value ) {
		serviceLoaderBehaviour = value;
	}

	const cfsec::CFSecSaxLoader::LoaderBehaviourEnum CFSecSaxLoader::getServiceTypeLoaderBehaviour() const {
		return( serviceTypeLoaderBehaviour );
	}

	void CFSecSaxLoader::setServiceTypeLoaderBehaviour( const cfsec::CFSecSaxLoader::LoaderBehaviourEnum value ) {
		serviceTypeLoaderBehaviour = value;
	}

	const cfsec::CFSecSaxLoader::LoaderBehaviourEnum CFSecSaxLoader::getSysClusterLoaderBehaviour() const {
		return( sysClusterLoaderBehaviour );
	}

	void CFSecSaxLoader::setSysClusterLoaderBehaviour( const cfsec::CFSecSaxLoader::LoaderBehaviourEnum value ) {
		sysClusterLoaderBehaviour = value;
	}

	const cfsec::CFSecSaxLoader::LoaderBehaviourEnum CFSecSaxLoader::getTSecGroupLoaderBehaviour() const {
		return( tSecGroupLoaderBehaviour );
	}

	void CFSecSaxLoader::setTSecGroupLoaderBehaviour( const cfsec::CFSecSaxLoader::LoaderBehaviourEnum value ) {
		tSecGroupLoaderBehaviour = value;
	}

	const cfsec::CFSecSaxLoader::LoaderBehaviourEnum CFSecSaxLoader::getTSecGrpIncLoaderBehaviour() const {
		return( tSecGrpIncLoaderBehaviour );
	}

	void CFSecSaxLoader::setTSecGrpIncLoaderBehaviour( const cfsec::CFSecSaxLoader::LoaderBehaviourEnum value ) {
		tSecGrpIncLoaderBehaviour = value;
	}

	const cfsec::CFSecSaxLoader::LoaderBehaviourEnum CFSecSaxLoader::getTSecGrpMembLoaderBehaviour() const {
		return( tSecGrpMembLoaderBehaviour );
	}

	void CFSecSaxLoader::setTSecGrpMembLoaderBehaviour( const cfsec::CFSecSaxLoader::LoaderBehaviourEnum value ) {
		tSecGrpMembLoaderBehaviour = value;
	}

	const cfsec::CFSecSaxLoader::LoaderBehaviourEnum CFSecSaxLoader::getTenantLoaderBehaviour() const {
		return( tenantLoaderBehaviour );
	}

	void CFSecSaxLoader::setTenantLoaderBehaviour( const cfsec::CFSecSaxLoader::LoaderBehaviourEnum value ) {
		tenantLoaderBehaviour = value;
	}

	void CFSecSaxLoader::parseFile( const std::string& url ) {
		parse( url.data() );
	}

}
