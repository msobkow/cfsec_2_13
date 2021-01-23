#pragma once

// Description: C++18 client configuration file specification for a CFSec schema.

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

	class CFSecClientConfigurationFile
	{
	protected:
		std::string* fileName;
		std::string* keyStore;
		std::string* deviceName;
		int32_t serverURLUsed;
		std::string* serverURL[20];

	public:
		static const std::string CLASS_NAME;
		static const std::string S_KEYSTORE;
		static const std::string S_DEVICENAME;
		static const std::string S_SERVERURLPREFIX;

	public:
		CFSecClientConfigurationFile();
		virtual ~CFSecClientConfigurationFile();

		virtual std::string* getFileName() const;
		virtual void setFileName( const std::string& value );

		virtual std::string* getKeyStore() const;
		virtual void setKeyStore( const std::string& value );

		virtual std::string* getDeviceName() const;
		virtual void setDeviceName( const std::string& value );

		virtual std::string** getServerURLArray();
		virtual int32_t getServerURLUsed() const;
		virtual const std::string* getLatestServerURL() const;
		virtual void setLatestServerURL( const std::string& value );

		virtual bool load();
		virtual bool save() const;
	};
}
