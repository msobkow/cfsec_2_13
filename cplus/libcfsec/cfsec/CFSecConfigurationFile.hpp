#pragma once

// Description: C++18 configuration file specification for a CFSec schema.

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

namespace cfsec {

	class CFSecConfigurationFile
	{
	protected:
		std::string* fileName;
		std::string* dbServer;
		int32_t dbPort = -1;
		std::string* dbDatabase;
		std::string* dbUserName;
		std::string* dbPassword;

	public:
		static const std::string CLASS_NAME;
		static const std::string S_DBSERVER;
		static const std::string S_DBPORT;
		static const std::string S_DBDATABASE;
		static const std::string S_DBUSERNAME;
		static const std::string S_DBPASSWORD;

	public:
		CFSecConfigurationFile();
		virtual ~CFSecConfigurationFile();

		virtual std::string* getFileName() const;
		virtual void setFileName( const std::string& value );

		virtual std::string* getDbServer() const;
		virtual void setDbServer( const std::string& value );

		virtual int32_t getDbPort() const;
		virtual void setDbPort( int32_t value );

		virtual std::string* getDbDatabase() const;
		virtual void setDbDatabase( const std::string& value );

		virtual std::string* getDbUserName() const;
		virtual void setDbUserName( const std::string& value );

		virtual std::string* getDbPassword() const;
		virtual void setDbPassword( const std::string& value );

		virtual bool load();
		virtual bool save() const;
	};
}
