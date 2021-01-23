#pragma once

// Description: C++18 specification of a CFSec schema pool.

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
