// Description: C++18 Implementation of a RAM CFSec loader.

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
