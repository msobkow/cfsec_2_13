#pragma once

// Description: C++18 client configuration file specification for a CFSec schema.

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
