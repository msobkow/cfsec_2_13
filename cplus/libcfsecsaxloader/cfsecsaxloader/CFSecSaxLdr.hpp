#pragma once

// Description: C++18 XML Command Line Interface common core specification for CFSec.

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
