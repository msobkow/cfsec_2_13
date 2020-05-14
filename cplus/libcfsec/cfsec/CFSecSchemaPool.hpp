#pragma once

// Description: C++18 specification of a CFSec schema pool.

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
#include <cfsec/CFSecConfigurationFile.hpp>
#include <cfsec/ICFSecSchema.hpp>
#include <cfsec/CFSecSchema.hpp>

namespace cfsec {

	class CFSecSchemaPool
	{
	public:
		static const std::string CLASS_NAME;
	protected:
		
		std::string* jndiName;
		cfsec::CFSecConfigurationFile* configFile;
		std::list<cfsec::ICFSecSchema*>* instances;
	public:
		CFSecSchemaPool();
		virtual ~CFSecSchemaPool();

		virtual cfsec::CFSecConfigurationFile* getConfigurationFile();

		virtual void setConfigurationFile( cfsec::CFSecConfigurationFile* value );


	protected:
		static cfsec::CFSecSchemaPool* getSetStaticSchemaPool( cfsec::CFSecSchemaPool* value );
	public:
		static cfsec::CFSecSchemaPool* getSchemaPool();
		static void setSchemaPool( cfsec::CFSecSchemaPool* pool );

		/**
		 *	Retrieve an entry from the pool with a previously
		 *	established database connection.
		 */
		/* TODO: synchronized */ virtual cfsec::ICFSecSchema* getInstance();

		/**
		 *	Return an entry to the pool.
		 */
		/* TODO: synchronized */ virtual void releaseInstance( cfsec::ICFSecSchema* inst );

		/**
		 *	You need to overload the declementation of newInstance() to return
		 *	connected instances of your backing store.
		 */
		virtual cfsec::ICFSecSchema* newInstance();

		/**
		 *	Overload disposeInstance().
		 */
		virtual void disposeInstance( cfsec::ICFSecSchema* inst );

		virtual const std::string* getJndiName();
		virtual void setJndiName( const std::string* value );

	};

}
