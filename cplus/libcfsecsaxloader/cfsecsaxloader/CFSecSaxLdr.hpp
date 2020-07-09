#pragma once

// Description: C++18 XML Command Line Interface common core specification for CFSec.

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

namespace cfsec {
	class ICFSecClusterObj;
	class ICFSecTenantObj;
	class ICFSecSecUserObj;
	class ICFSecSecSessionObj;
}

namespace cfsec {

	class CFSecSaxLoader;

	class CFSecSaxLdr
	{
	protected:
		cflib::ICFLibMessageLog* log;
		cfsec::CFSecSaxLoader* saxLoader;
		std::string* clusterName;
		cfsec::ICFSecClusterObj* clusterObj;
		std::string* tenantName;
		cfsec::ICFSecTenantObj* tenantObj;
		std::string* secUserName;
		cfsec::ICFSecSecUserObj* secUserObj;
		cfsec::ICFSecSecSessionObj* secSessionObj;
	public:
		const static std::string CLASS_NAME;
		const static std::string S_SYSTEM;
		const static std::string S_UnhandledException;

		CFSecSaxLdr();
		virtual ~CFSecSaxLdr();

		CFSecSaxLdr( cflib::ICFLibMessageLog* messageLog );


		void setSaxLoader( cfsec::CFSecSaxLoader* value );
		CFSecSaxLoader* getSaxLoader();


		void setClusterName( const std::string& value );
		const std::string& getClusterName() const;
		cfsec::ICFSecClusterObj* getClusterObj();


		void setTenantName( const std::string& value );
		const std::string& getTenantName() const;
		cfsec::ICFSecTenantObj* getTenantObj();


		void setSecUserName( const std::string& value );
		const std::string& getSecUserName() const;
		cfsec::ICFSecSecUserObj* getSecUserObj();


		cfsec::ICFSecSecSessionObj* getSecSessionObj();


		static void applyLoaderOptions( cfsec::CFSecSaxLoader* loader, const std::string& loaderOptions );


		static void evalLoaderSegment( cfsec::CFSecSaxLoader* loader, const std::string& evalSegment );


		virtual void evaluateRemainingArgs( size_t argc, char* argv[], size_t consumed );

	};
}
