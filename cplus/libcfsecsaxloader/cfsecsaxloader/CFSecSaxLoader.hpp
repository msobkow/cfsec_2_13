#pragma once

// Description: C++18 XML SAX Parser specification for CFSec.

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
#include <xercesc/sax2/Attributes.hpp>


namespace cfsec {
	class ICFSecSchemaObj;
	class ICFSecClusterObj;
	class ICFSecClusterEditObj;
	class ICFSecClusterTableObj;
	class CFSecSaxLoaderClusterHandler;
	class ICFSecHostNodeObj;
	class ICFSecHostNodeEditObj;
	class ICFSecHostNodeTableObj;
	class CFSecSaxLoaderHostNodeHandler;
	class ICFSecISOCcyObj;
	class ICFSecISOCcyEditObj;
	class ICFSecISOCcyTableObj;
	class CFSecSaxLoaderISOCcyHandler;
	class ICFSecISOCtryObj;
	class ICFSecISOCtryEditObj;
	class ICFSecISOCtryTableObj;
	class CFSecSaxLoaderISOCtryHandler;
	class ICFSecISOCtryCcyObj;
	class ICFSecISOCtryCcyEditObj;
	class ICFSecISOCtryCcyTableObj;
	class CFSecSaxLoaderISOCtryCcyHandler;
	class ICFSecISOCtryLangObj;
	class ICFSecISOCtryLangEditObj;
	class ICFSecISOCtryLangTableObj;
	class CFSecSaxLoaderISOCtryLangHandler;
	class ICFSecISOLangObj;
	class ICFSecISOLangEditObj;
	class ICFSecISOLangTableObj;
	class CFSecSaxLoaderISOLangHandler;
	class ICFSecISOTZoneObj;
	class ICFSecISOTZoneEditObj;
	class ICFSecISOTZoneTableObj;
	class CFSecSaxLoaderISOTZoneHandler;
	class ICFSecSecAppObj;
	class ICFSecSecAppEditObj;
	class ICFSecSecAppTableObj;
	class CFSecSaxLoaderSecAppHandler;
	class ICFSecSecDeviceObj;
	class ICFSecSecDeviceEditObj;
	class ICFSecSecDeviceTableObj;
	class CFSecSaxLoaderSecDeviceHandler;
	class ICFSecSecFormObj;
	class ICFSecSecFormEditObj;
	class ICFSecSecFormTableObj;
	class CFSecSaxLoaderSecFormHandler;
	class ICFSecSecGroupObj;
	class ICFSecSecGroupEditObj;
	class ICFSecSecGroupTableObj;
	class CFSecSaxLoaderSecGroupHandler;
	class ICFSecSecGroupFormObj;
	class ICFSecSecGroupFormEditObj;
	class ICFSecSecGroupFormTableObj;
	class CFSecSaxLoaderSecGroupFormHandler;
	class ICFSecSecGrpIncObj;
	class ICFSecSecGrpIncEditObj;
	class ICFSecSecGrpIncTableObj;
	class CFSecSaxLoaderSecGrpIncHandler;
	class ICFSecSecGrpMembObj;
	class ICFSecSecGrpMembEditObj;
	class ICFSecSecGrpMembTableObj;
	class CFSecSaxLoaderSecGrpMembHandler;
	class ICFSecSecSessionObj;
	class ICFSecSecSessionEditObj;
	class ICFSecSecSessionTableObj;
	class CFSecSaxLoaderSecSessionHandler;
	class ICFSecSecUserObj;
	class ICFSecSecUserEditObj;
	class ICFSecSecUserTableObj;
	class CFSecSaxLoaderSecUserHandler;
	class ICFSecServiceObj;
	class ICFSecServiceEditObj;
	class ICFSecServiceTableObj;
	class CFSecSaxLoaderServiceHandler;
	class ICFSecServiceTypeObj;
	class ICFSecServiceTypeEditObj;
	class ICFSecServiceTypeTableObj;
	class CFSecSaxLoaderServiceTypeHandler;
	class ICFSecSysClusterObj;
	class ICFSecSysClusterEditObj;
	class ICFSecSysClusterTableObj;
	class CFSecSaxLoaderSysClusterHandler;
	class ICFSecTSecGroupObj;
	class ICFSecTSecGroupEditObj;
	class ICFSecTSecGroupTableObj;
	class CFSecSaxLoaderTSecGroupHandler;
	class ICFSecTSecGrpIncObj;
	class ICFSecTSecGrpIncEditObj;
	class ICFSecTSecGrpIncTableObj;
	class CFSecSaxLoaderTSecGrpIncHandler;
	class ICFSecTSecGrpMembObj;
	class ICFSecTSecGrpMembEditObj;
	class ICFSecTSecGrpMembTableObj;
	class CFSecSaxLoaderTSecGrpMembHandler;
	class ICFSecTenantObj;
	class ICFSecTenantEditObj;
	class ICFSecTenantTableObj;
	class CFSecSaxLoaderTenantHandler;
	class CFSecSaxLoader;

	class CFSecSaxRootHandler
	: public cflib::CFLibXmlCoreElementHandler
	{
	public:
		CFSecSaxRootHandler( CFSecSaxLoader* saxLoader );
		virtual ~CFSecSaxRootHandler();

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
		virtual void startElement (
			const XMLCh* const uri,
			const XMLCh* const localname,
			const XMLCh* const qname,
			const xercesc::Attributes& attrs );

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
		virtual void endElement (
			const XMLCh* const uri,
			const XMLCh* const localname,
			const XMLCh* const qname );

	};


	class CFSecSaxDocHandler
	: public cflib::CFLibXmlCoreElementHandler
	{
	public:
		CFSecSaxDocHandler( cfsec::CFSecSaxLoader* saxLoader );
		virtual ~CFSecSaxDocHandler();

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
		virtual void startElement (
			const XMLCh* const uri,
			const XMLCh* const localname,
			const XMLCh* const qname,
			const xercesc::Attributes& attrs );

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
		virtual void endElement (
			const XMLCh* const uri,
			const XMLCh* const localname,
			const XMLCh* const qname );

	};

	class CFSecSaxLoader
	: public cflib::CFLibXmlCoreSaxParser
	{
	public:
		const static std::string CLASS_NAME;

		// The namespace URI of the supported schema
		const static std::string SCHEMA_XMLNS;

		// The source for loading the supported schema
		const static std::string SCHEMA_URI;

	protected:
		static bool grammarLoaded;
		cfsec::ICFSecSchemaObj* schemaObj;
		cfsec::ICFSecClusterObj* useCluster;
		cfsec::ICFSecTenantObj* useTenant;

	public:
		enum LoaderBehaviourEnum {
			Insert,
			Update,
			Replace
		};

	protected:
		cfsec::CFSecSaxLoader::LoaderBehaviourEnum clusterLoaderBehaviour = cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Insert;
		cfsec::CFSecSaxLoader::LoaderBehaviourEnum hostNodeLoaderBehaviour = cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Update;
		cfsec::CFSecSaxLoader::LoaderBehaviourEnum iSOCcyLoaderBehaviour = cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Update;
		cfsec::CFSecSaxLoader::LoaderBehaviourEnum iSOCtryLoaderBehaviour = cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Update;
		cfsec::CFSecSaxLoader::LoaderBehaviourEnum iSOCtryCcyLoaderBehaviour = cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Insert;
		cfsec::CFSecSaxLoader::LoaderBehaviourEnum iSOCtryLangLoaderBehaviour = cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Insert;
		cfsec::CFSecSaxLoader::LoaderBehaviourEnum iSOLangLoaderBehaviour = cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Update;
		cfsec::CFSecSaxLoader::LoaderBehaviourEnum iSOTZoneLoaderBehaviour = cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Update;
		cfsec::CFSecSaxLoader::LoaderBehaviourEnum secAppLoaderBehaviour = cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Update;
		cfsec::CFSecSaxLoader::LoaderBehaviourEnum secDeviceLoaderBehaviour = cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Insert;
		cfsec::CFSecSaxLoader::LoaderBehaviourEnum secFormLoaderBehaviour = cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Update;
		cfsec::CFSecSaxLoader::LoaderBehaviourEnum secGroupLoaderBehaviour = cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Insert;
		cfsec::CFSecSaxLoader::LoaderBehaviourEnum secGroupFormLoaderBehaviour = cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Insert;
		cfsec::CFSecSaxLoader::LoaderBehaviourEnum secGrpIncLoaderBehaviour = cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Insert;
		cfsec::CFSecSaxLoader::LoaderBehaviourEnum secGrpMembLoaderBehaviour = cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Insert;
		cfsec::CFSecSaxLoader::LoaderBehaviourEnum secSessionLoaderBehaviour = cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Insert;
		cfsec::CFSecSaxLoader::LoaderBehaviourEnum secUserLoaderBehaviour = cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Insert;
		cfsec::CFSecSaxLoader::LoaderBehaviourEnum serviceLoaderBehaviour = cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Update;
		cfsec::CFSecSaxLoader::LoaderBehaviourEnum serviceTypeLoaderBehaviour = cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Insert;
		cfsec::CFSecSaxLoader::LoaderBehaviourEnum sysClusterLoaderBehaviour = cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Insert;
		cfsec::CFSecSaxLoader::LoaderBehaviourEnum tSecGroupLoaderBehaviour = cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Insert;
		cfsec::CFSecSaxLoader::LoaderBehaviourEnum tSecGrpIncLoaderBehaviour = cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Insert;
		cfsec::CFSecSaxLoader::LoaderBehaviourEnum tSecGrpMembLoaderBehaviour = cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Insert;
		cfsec::CFSecSaxLoader::LoaderBehaviourEnum tenantLoaderBehaviour = cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Insert;


		cfsec::CFSecSaxLoaderClusterHandler* clusterHandler;
		cfsec::CFSecSaxLoaderHostNodeHandler* hostNodeHandler;
		cfsec::CFSecSaxLoaderISOCcyHandler* iSOCcyHandler;
		cfsec::CFSecSaxLoaderISOCtryHandler* iSOCtryHandler;
		cfsec::CFSecSaxLoaderISOCtryCcyHandler* iSOCtryCcyHandler;
		cfsec::CFSecSaxLoaderISOCtryLangHandler* iSOCtryLangHandler;
		cfsec::CFSecSaxLoaderISOLangHandler* iSOLangHandler;
		cfsec::CFSecSaxLoaderISOTZoneHandler* iSOTZoneHandler;
		cfsec::CFSecSaxLoaderSecAppHandler* secAppHandler;
		cfsec::CFSecSaxLoaderSecDeviceHandler* secDeviceHandler;
		cfsec::CFSecSaxLoaderSecFormHandler* secFormHandler;
		cfsec::CFSecSaxLoaderSecGroupHandler* secGroupHandler;
		cfsec::CFSecSaxLoaderSecGroupFormHandler* secGroupFormHandler;
		cfsec::CFSecSaxLoaderSecGrpIncHandler* secGrpIncHandler;
		cfsec::CFSecSaxLoaderSecGrpMembHandler* secGrpMembHandler;
		cfsec::CFSecSaxLoaderSecSessionHandler* secSessionHandler;
		cfsec::CFSecSaxLoaderSecUserHandler* secUserHandler;
		cfsec::CFSecSaxLoaderServiceHandler* serviceHandler;
		cfsec::CFSecSaxLoaderServiceTypeHandler* serviceTypeHandler;
		cfsec::CFSecSaxLoaderSysClusterHandler* sysClusterHandler;
		cfsec::CFSecSaxLoaderTSecGroupHandler* tSecGroupHandler;
		cfsec::CFSecSaxLoaderTSecGrpIncHandler* tSecGrpIncHandler;
		cfsec::CFSecSaxLoaderTSecGrpMembHandler* tSecGrpMembHandler;
		cfsec::CFSecSaxLoaderTenantHandler* tenantHandler;
		cfsec::CFSecSaxRootHandler* saxRootHandler;
		cfsec::CFSecSaxDocHandler* saxDocHandler;
	public:

		CFSecSaxLoader();
		virtual ~CFSecSaxLoader();

		CFSecSaxLoader( cflib::ICFLibMessageLog* logger );


		virtual void initParser();


		cfsec::ICFSecClusterObj* getUseCluster() const;
		void setUseCluster( cfsec::ICFSecClusterObj* value );

		cfsec::ICFSecTenantObj* getUseTenant();
		void setUseTenant( cfsec::ICFSecTenantObj* value );


		cfsec::ICFSecSchemaObj* getSchemaObj() const;
		void setSchemaObj( cfsec::ICFSecSchemaObj* value );


		static void verifyGrammarInstallation();

	protected:

		cfsec::CFSecSaxLoaderClusterHandler* getClusterHandler();

		cfsec::CFSecSaxLoaderHostNodeHandler* getHostNodeHandler();

		cfsec::CFSecSaxLoaderISOCcyHandler* getISOCcyHandler();

		cfsec::CFSecSaxLoaderISOCtryHandler* getISOCtryHandler();

		cfsec::CFSecSaxLoaderISOCtryCcyHandler* getISOCtryCcyHandler();

		cfsec::CFSecSaxLoaderISOCtryLangHandler* getISOCtryLangHandler();

		cfsec::CFSecSaxLoaderISOLangHandler* getISOLangHandler();

		cfsec::CFSecSaxLoaderISOTZoneHandler* getISOTZoneHandler();

		cfsec::CFSecSaxLoaderSecAppHandler* getSecAppHandler();

		cfsec::CFSecSaxLoaderSecDeviceHandler* getSecDeviceHandler();

		cfsec::CFSecSaxLoaderSecFormHandler* getSecFormHandler();

		cfsec::CFSecSaxLoaderSecGroupHandler* getSecGroupHandler();

		cfsec::CFSecSaxLoaderSecGroupFormHandler* getSecGroupFormHandler();

		cfsec::CFSecSaxLoaderSecGrpIncHandler* getSecGrpIncHandler();

		cfsec::CFSecSaxLoaderSecGrpMembHandler* getSecGrpMembHandler();

		cfsec::CFSecSaxLoaderSecSessionHandler* getSecSessionHandler();

		cfsec::CFSecSaxLoaderSecUserHandler* getSecUserHandler();

		cfsec::CFSecSaxLoaderServiceHandler* getServiceHandler();

		cfsec::CFSecSaxLoaderServiceTypeHandler* getServiceTypeHandler();

		cfsec::CFSecSaxLoaderSysClusterHandler* getSysClusterHandler();

		cfsec::CFSecSaxLoaderTSecGroupHandler* getTSecGroupHandler();

		cfsec::CFSecSaxLoaderTSecGrpIncHandler* getTSecGrpIncHandler();

		cfsec::CFSecSaxLoaderTSecGrpMembHandler* getTSecGrpMembHandler();

		cfsec::CFSecSaxLoaderTenantHandler* getTenantHandler();


		cfsec::CFSecSaxRootHandler* getSaxRootHandler();


		cfsec::CFSecSaxDocHandler* getSaxDocHandler();

	public:

		const cfsec::CFSecSaxLoader::LoaderBehaviourEnum getClusterLoaderBehaviour() const;
		void setClusterLoaderBehaviour( const cfsec::CFSecSaxLoader::LoaderBehaviourEnum value );

		const cfsec::CFSecSaxLoader::LoaderBehaviourEnum getHostNodeLoaderBehaviour() const;
		void setHostNodeLoaderBehaviour( const cfsec::CFSecSaxLoader::LoaderBehaviourEnum value );

		const cfsec::CFSecSaxLoader::LoaderBehaviourEnum getISOCcyLoaderBehaviour() const;
		void setISOCcyLoaderBehaviour( const cfsec::CFSecSaxLoader::LoaderBehaviourEnum value );

		const cfsec::CFSecSaxLoader::LoaderBehaviourEnum getISOCtryLoaderBehaviour() const;
		void setISOCtryLoaderBehaviour( const cfsec::CFSecSaxLoader::LoaderBehaviourEnum value );

		const cfsec::CFSecSaxLoader::LoaderBehaviourEnum getISOCtryCcyLoaderBehaviour() const;
		void setISOCtryCcyLoaderBehaviour( const cfsec::CFSecSaxLoader::LoaderBehaviourEnum value );

		const cfsec::CFSecSaxLoader::LoaderBehaviourEnum getISOCtryLangLoaderBehaviour() const;
		void setISOCtryLangLoaderBehaviour( const cfsec::CFSecSaxLoader::LoaderBehaviourEnum value );

		const cfsec::CFSecSaxLoader::LoaderBehaviourEnum getISOLangLoaderBehaviour() const;
		void setISOLangLoaderBehaviour( const cfsec::CFSecSaxLoader::LoaderBehaviourEnum value );

		const cfsec::CFSecSaxLoader::LoaderBehaviourEnum getISOTZoneLoaderBehaviour() const;
		void setISOTZoneLoaderBehaviour( const cfsec::CFSecSaxLoader::LoaderBehaviourEnum value );

		const cfsec::CFSecSaxLoader::LoaderBehaviourEnum getSecAppLoaderBehaviour() const;
		void setSecAppLoaderBehaviour( const cfsec::CFSecSaxLoader::LoaderBehaviourEnum value );

		const cfsec::CFSecSaxLoader::LoaderBehaviourEnum getSecDeviceLoaderBehaviour() const;
		void setSecDeviceLoaderBehaviour( const cfsec::CFSecSaxLoader::LoaderBehaviourEnum value );

		const cfsec::CFSecSaxLoader::LoaderBehaviourEnum getSecFormLoaderBehaviour() const;
		void setSecFormLoaderBehaviour( const cfsec::CFSecSaxLoader::LoaderBehaviourEnum value );

		const cfsec::CFSecSaxLoader::LoaderBehaviourEnum getSecGroupLoaderBehaviour() const;
		void setSecGroupLoaderBehaviour( const cfsec::CFSecSaxLoader::LoaderBehaviourEnum value );

		const cfsec::CFSecSaxLoader::LoaderBehaviourEnum getSecGroupFormLoaderBehaviour() const;
		void setSecGroupFormLoaderBehaviour( const cfsec::CFSecSaxLoader::LoaderBehaviourEnum value );

		const cfsec::CFSecSaxLoader::LoaderBehaviourEnum getSecGrpIncLoaderBehaviour() const;
		void setSecGrpIncLoaderBehaviour( const cfsec::CFSecSaxLoader::LoaderBehaviourEnum value );

		const cfsec::CFSecSaxLoader::LoaderBehaviourEnum getSecGrpMembLoaderBehaviour() const;
		void setSecGrpMembLoaderBehaviour( const cfsec::CFSecSaxLoader::LoaderBehaviourEnum value );

		const cfsec::CFSecSaxLoader::LoaderBehaviourEnum getSecSessionLoaderBehaviour() const;
		void setSecSessionLoaderBehaviour( const cfsec::CFSecSaxLoader::LoaderBehaviourEnum value );

		const cfsec::CFSecSaxLoader::LoaderBehaviourEnum getSecUserLoaderBehaviour() const;
		void setSecUserLoaderBehaviour( const cfsec::CFSecSaxLoader::LoaderBehaviourEnum value );

		const cfsec::CFSecSaxLoader::LoaderBehaviourEnum getServiceLoaderBehaviour() const;
		void setServiceLoaderBehaviour( const cfsec::CFSecSaxLoader::LoaderBehaviourEnum value );

		const cfsec::CFSecSaxLoader::LoaderBehaviourEnum getServiceTypeLoaderBehaviour() const;
		void setServiceTypeLoaderBehaviour( const cfsec::CFSecSaxLoader::LoaderBehaviourEnum value );

		const cfsec::CFSecSaxLoader::LoaderBehaviourEnum getSysClusterLoaderBehaviour() const;
		void setSysClusterLoaderBehaviour( const cfsec::CFSecSaxLoader::LoaderBehaviourEnum value );

		const cfsec::CFSecSaxLoader::LoaderBehaviourEnum getTSecGroupLoaderBehaviour() const;
		void setTSecGroupLoaderBehaviour( const cfsec::CFSecSaxLoader::LoaderBehaviourEnum value );

		const cfsec::CFSecSaxLoader::LoaderBehaviourEnum getTSecGrpIncLoaderBehaviour() const;
		void setTSecGrpIncLoaderBehaviour( const cfsec::CFSecSaxLoader::LoaderBehaviourEnum value );

		const cfsec::CFSecSaxLoader::LoaderBehaviourEnum getTSecGrpMembLoaderBehaviour() const;
		void setTSecGrpMembLoaderBehaviour( const cfsec::CFSecSaxLoader::LoaderBehaviourEnum value );

		const cfsec::CFSecSaxLoader::LoaderBehaviourEnum getTenantLoaderBehaviour() const;
		void setTenantLoaderBehaviour( const cfsec::CFSecSaxLoader::LoaderBehaviourEnum value );


		void parseFile( const std::string& url );

	};
}
