// Description: C++18 Command Line Object Implementation for CFSec RAM Loader

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
