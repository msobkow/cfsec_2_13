#pragma once

// Description: C++18 specification of a generic CFSec history primary key base object.

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

	class CFSecHPKey
	{
	protected:
		int64_t auditClusterId;
		std::chrono::system_clock::time_point auditStamp;
		int16_t auditActionId;
		int32_t requiredRevision;
		uuid_t auditSessionId;
		classcode_t classCode;
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;
		CFSecHPKey();
		virtual ~CFSecHPKey();

		virtual int64_t getAuditClusterId() const;
		virtual void setAuditClusterId( int64_t value );

		virtual const std::chrono::system_clock::time_point& getAuditStamp() const;
		virtual void setAuditStamp( const std::chrono::system_clock::time_point& value );

		virtual int16_t getAuditActionId() const;
		virtual void setAuditActionId( int16_t value );

		virtual int32_t getRequiredRevision() const;
		virtual void setRequiredRevision( int32_t value );

		virtual const uuid_ptr_t getAuditSessionId() const;
		virtual void setAuditSessionId( const uuid_ptr_t value );

		virtual size_t hashCode() const;

		virtual std::string toString();

		virtual const std::string& getClassName() const;
		virtual const classcode_t getClassCode() const;
		virtual void setClassCode( const classcode_t value );
	};
}
