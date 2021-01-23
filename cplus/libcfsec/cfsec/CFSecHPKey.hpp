#pragma once

// Description: C++18 specification of a generic CFSec history primary key base object.

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
