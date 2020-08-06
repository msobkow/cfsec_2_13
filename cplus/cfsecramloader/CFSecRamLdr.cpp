// Description: C++18 Command Line Object Implementation for CFSec RAM Loader

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
#include <cfsecobj/CFSecSchemaObj.hpp>
#include <cfsecsaxloader/CFSecSaxLoaderPublic.hpp>
#include <cfsecram/CFSecRamSchema.hpp>
#include <CFSecRamLdr.hpp>

using namespace std;

namespace cfsec {

	cflib::ICFLibMessageLog* CFSecRamLdr::log = new cflib::CFLibConsoleMessageLog();

	CFSecRamLdr::CFSecRamLdr()
	: cfsec::CFSecSaxLdr( log )
	{
	}

	CFSecRamLdr::~CFSecRamLdr() {
	}


	void CFSecRamLdr::evaluateRemainingArgs( size_t argc, char* argv[], size_t consumed ) {
		// There are no extra arguments for the RAM "database" instance
		if( argc > consumed ) {
			if( log != NULL ) {
				log->message( "CFSecRamLdr.evaluateRemainingArgs() WARNING No extra arguments are expected for a RAM database instance, but "
					+ cflib::CFLibXmlUtil::formatInt64( (int64_t)( argc - consumed ) )
					+ " extra arguments were specified.  Extra arguments ignored." );
			}
			else {
				std::cerr << "CFSecRamLdr.evaluateRemainingArgs() WARNING No extra arguments are expected for a RAM database instance, but "
					+ cflib::CFLibXmlUtil::formatInt64( (int64_t)( argc - consumed ) )
					+ " extra arguments were specified.  Extra arguments ignored.\n";
			}
		}
	}

}
