// Description: C++18 implementation of a CFSec schema pool.

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
