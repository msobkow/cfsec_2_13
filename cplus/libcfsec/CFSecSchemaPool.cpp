// Description: C++18 implementation of a CFSec schema pool.

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

using namespace std;

#include <cfsec/CFSecSchemaPool.hpp>

namespace cfsec {

	const std::string CFSecSchemaPool::CLASS_NAME( "CFSecSchemaPool" );
	CFSecSchemaPool::CFSecSchemaPool() {
		instances = new std::list<ICFSecSchema*>();
		jndiName = NULL;
		configFile = NULL;
	}

	CFSecSchemaPool::~CFSecSchemaPool() {
		if( instances != NULL ) {
			cfsec::ICFSecSchema* inst = NULL;
			while( ! instances->empty() ) {
				inst = instances->front();
				instances->remove( inst );
				delete inst;
				inst = NULL;
			}
			delete instances;
			instances = NULL;
		}
		if( jndiName != NULL ) {
			delete jndiName;
			jndiName = NULL;
		}
		if( configFile != NULL ) {
			delete configFile;
			configFile = NULL;
		}
	}

	cfsec::CFSecConfigurationFile* CFSecSchemaPool::getConfigurationFile() {
		return( configFile );
	}

	void CFSecSchemaPool::setConfigurationFile( cfsec::CFSecConfigurationFile* value ) {
		
		if( configFile != NULL ) {
			delete configFile;
			configFile = NULL;
		}
		configFile = value;
	}


	CFSecSchemaPool* CFSecSchemaPool::getSetStaticSchemaPool( CFSecSchemaPool* value ) {
		static CFSecSchemaPool* schemaPool = NULL;
		if( value != NULL ) {
			if( schemaPool != NULL ) {
				delete schemaPool;
				schemaPool = NULL;
			}
			schemaPool = value;
		}
		return( schemaPool );
	}

	CFSecSchemaPool* CFSecSchemaPool::getSchemaPool() {
		CFSecSchemaPool* retval = getSetStaticSchemaPool( NULL );
		return( retval );
	}

	void CFSecSchemaPool::setSchemaPool( cfsec::CFSecSchemaPool* pool ) {
		if( getSetStaticSchemaPool( NULL ) == NULL ) {
			getSetStaticSchemaPool( pool );
		}

	}

	/**
	 *	Retrieve an entry from the pool with a previously
	 *	established database connection.
	 */
	/* TODO: synchronized */ cfsec::ICFSecSchema* CFSecSchemaPool::getInstance() {
		cfsec::ICFSecSchema* retInst = NULL;
		if( instances != NULL ) {
			if( instances->empty() ) {
				retInst = newInstance();
				retInst->setConfigurationFile( (CFSecConfigurationFile*)getConfigurationFile() );
				if( getJndiName() != NULL ) {
					retInst->setJndiName( *getJndiName() );
				}
				retInst->connect();
			}
			else {
				retInst = instances->front();
				instances->remove( retInst );
			}
		}
		else {
			retInst = NULL;
		}
		return( retInst );
	}

	/**
	 *	Return an entry to the pool.
	 */
	/* TODO: synchronized */ void CFSecSchemaPool::releaseInstance( cfsec::ICFSecSchema* inst ) {
		if( inst == NULL ) {
			return;
		}
		inst->rollback();
		if( instances != NULL ) {
			instances->insert( instances->begin(), inst );
		}
	}

	/**
	 *	You need to overload the implementation of newInstance() to return
	 *	connected instances of your backing store.
	 */
	cfsec::ICFSecSchema* CFSecSchemaPool::newInstance() {
		cfsec::ICFSecSchema* retInst = new cfsec::CFSecSchema();
		return( retInst );
	}

	/**
	 *	Overload disposeInstance().
	 */
	void CFSecSchemaPool::disposeInstance( cfsec::ICFSecSchema* inst ) {
//		try {
			inst->disconnect( false );
//		}
//		catch( std::exception e ) {
//		}
		if( instances != NULL ) {
			instances->remove( inst );
		}
		delete inst;
	}

	const std::string* CFSecSchemaPool::getJndiName() {
		return( jndiName );
	}

	void CFSecSchemaPool::setJndiName( const std::string* value ) {
		if( jndiName != NULL ) {
			delete jndiName;
			jndiName = NULL;
		}
		if( value != NULL ) {
			jndiName = new std::string( *value );
		}
		if( ( jndiName != NULL ) && ( jndiName->length() > 0 ) ) {
			if( configFile != NULL ) {
				delete configFile;
				configFile = NULL;
			}
		}
	}

}
