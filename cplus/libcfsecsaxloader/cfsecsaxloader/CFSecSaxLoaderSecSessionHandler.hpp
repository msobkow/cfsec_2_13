#pragma once

// Description: C++18 XML SAX2 Element Handler specification for SecSession

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
#include <xercesc/sax2/Attributes.hpp>
#include <cfsecsaxloader/CFSecSaxLoader.hpp>

namespace cfsec {

	class CFSecSaxLoaderSecSessionHandler
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
		CFSecSaxLoaderSecSessionHandler( cfsec::CFSecSaxLoader* saxLoader );
		virtual ~CFSecSaxLoaderSecSessionHandler();

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
