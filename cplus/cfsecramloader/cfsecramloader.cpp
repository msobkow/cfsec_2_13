// Description: C++18 Implementation of a RAM CFSec loader.

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

static const std::string CLASS_NAME( "CFSecRamLoader" );

int main( int argc, char* argv[] ) {

	if( argc < 1 ) {
		std::cerr << CLASS_NAME + " ERROR: Program name is not available\n";
		return( 1 );
	}
	std::string S_ProcName( argv[0] );
	static const std::string S_System( "system" );
	CFLIB_EXCEPTION_DECLINFO

	cflib::CFLib::init();

	int retval = 0;

	cfsec::ICFSecSchema* cFSecSchema = NULL;
	cfsec::ICFSecSchemaObj* cFSecSchemaObj = NULL;
	cfsec::CFSecRamLdr* cli = NULL;
	cfsec::CFSecSaxLoader* loader = NULL;
	cfsec::CFSecAuthorization* auth = NULL;
	std::string* loaderOpts = NULL;
	std::string* url = NULL;
	if( argc >= 3 ) {
		try {
			cFSecSchema = new cfsec::CFSecRamSchema();
			cFSecSchemaObj = new cfsec::CFSecSchemaObj();
			cFSecSchemaObj->setBackingStore( cFSecSchema );
			cli = new cfsec::CFSecRamLdr();
			loader = cli->getSaxLoader();
			loader->setSchemaObj( cFSecSchemaObj );
			loaderOpts = new std::string( argv[1] );
			url = new std::string( argv[2] );
			cFSecSchema->connect( S_System, S_System, S_System, S_System );
			cFSecSchema->rollback();
			cFSecSchema->beginTransaction();
			cFSecSchemaObj->setSecCluster( cFSecSchemaObj->getClusterTableObj()->getSystemCluster() );
			cFSecSchemaObj->setSecTenant( cFSecSchemaObj->getTenantTableObj()->getSystemTenant() );
			cFSecSchemaObj->setSecSession( cFSecSchemaObj->getSecSessionTableObj()->getSystemSession() );
			auth = new cfsec::CFSecAuthorization();
			auth->setSecCluster( *(cFSecSchemaObj->getSecCluster()) );
			auth->setSecTenant( *(cFSecSchemaObj->getSecTenant()) );
			auth->setSecSession( cFSecSchemaObj->getSecSession() );
			cFSecSchemaObj->setAuthorization( auth );
			cli->applyLoaderOptions( loader, *loaderOpts );
			cli->evaluateRemainingArgs( argc, argv, 3 );
			loader->setUseCluster( cFSecSchemaObj->getSecCluster() );
			loader->setUseTenant( cFSecSchemaObj->getSecTenant() );
			loader->parseFile( *url );
			cFSecSchema->commit();
			cFSecSchema->disconnect( true );
		}
		CFLIB_EXCEPTION_CATCH_FALLTHROUGH
		if( ! CFLIB_EXCEPTION_EMPTY ) {
			std::cerr << S_ProcName + " SAXParseException : Could not parse XML file \"" + *url + "\": " + CFLIB_EXCEPTION_FORMATTEDMESSAGE + "\n";
		}
		if( ( cFSecSchema != NULL ) && cFSecSchema->isConnected() ) {
			try {
				cFSecSchema->rollback();
			}
			catch ( ... ) {
			}
			try {
				cFSecSchema->disconnect( false );
			}
			catch( ... ) {
			}
		}
		if( loader != NULL ) {
			loader->setSchemaObj( NULL );
			loader = NULL;
		}
		if( cli != NULL ) {
			delete cli;
			cli = NULL;
		}
		if( cFSecSchemaObj != NULL ) {
			cFSecSchemaObj->setBackingStore( NULL );
			try {
				delete cFSecSchemaObj;
			}
			catch( ... ) {
			}
			cFSecSchemaObj = NULL;
		}
		if( cFSecSchema != NULL ) {
			if( cFSecSchema->isConnected() ) {
				try {
					cFSecSchema->rollback();
				}
				catch ( ... ) {
				}
				try {
					cFSecSchema->disconnect( false );
				}
				catch( ... ) {
				}
			}
			try {
				delete cFSecSchema;
			}
			catch( ... ) {
			}
			cFSecSchema = NULL;
		}
	}
	else {
		std::cerr << S_ProcName + " ERROR: Expected at least two argument specifying the loader options and the name of the XML file to parse.  The first argument may be empty.\n";
	}

	if( auth != NULL ) {
		delete auth;
		auth = NULL;
	}

	if( url != NULL ) {
		delete url;
		url = NULL;
	}

	if( loaderOpts != NULL ) {
		delete loaderOpts;
		loaderOpts = NULL;
	}

	try {
		cflib::CFLib::release();
	}
	catch( ... ) {
	}

	return( retval );
}
