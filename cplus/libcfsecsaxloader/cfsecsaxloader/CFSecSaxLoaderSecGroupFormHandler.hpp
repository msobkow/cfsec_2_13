#pragma once

// Description: C++18 XML SAX2 Element Handler specification for SecGroupForm

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
#include <xercesc/sax2/Attributes.hpp>
#include <cfsecsaxloader/CFSecSaxLoader.hpp>

namespace cfsec {

	class CFSecSaxLoaderSecGroupFormHandler
	: public cflib::CFLibXmlCoreElementHandler
	{
	public:
		const static std::string CLASS_NAME;
		const static std::string S_CannotUseBlobAsPKeyAttribute;
		const static std::string S_True;
		const static std::string S_False;
		const static std::string S_Yes;
		const static std::string S_No;
		const static std::string S_0;
		const static std::string S_1;
		CFSecSaxLoaderSecGroupFormHandler( cfsec::CFSecSaxLoader* saxLoader );
		virtual ~CFSecSaxLoaderSecGroupFormHandler();

		virtual void startElement (
			const XMLCh* const uri,
			const XMLCh* const localname,
			const XMLCh* const qname,
			const xercesc::Attributes& attrs );

		virtual void endElement (
			const XMLCh* const uri,
			const XMLCh* const localname,
			const XMLCh* const qname );

	};
}
