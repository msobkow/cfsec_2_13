#pragma once

// Description: C++18 configuration file specification for a CFSec schema.

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
