#pragma once

// Description: C++18 specification of a SecSession history buffer object.

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

#include <cfsec/CFSecHPKey.hpp>

#include <cfsec/ICFSecSchema.hpp>
namespace cfsec {

	class CFSecSecSessionBuff;
	class CFSecSecSessionPKey;
	class CFSecSecSessionHPKey;
	class CFSecSecSessionBySecUserIdxKey;
	class CFSecSecSessionBySecDevIdxKey;
	class CFSecSecSessionByStartIdxKey;
	class CFSecSecSessionByFinishIdxKey;
	class CFSecSecSessionBySecProxyIdxKey;

	class CFSecSecSessionHBuff : public CFSecHPKey, public cflib::ICFLibCloneableObj
	{
	public:
		static const std::string CLASS_NAME;
	protected:
		uuid_t requiredSecSessionId;
		uuid_t requiredSecUserId;
		std::string* optionalSecDevName;
		std::chrono::system_clock::time_point requiredStart;
		std::chrono::system_clock::time_point* optionalFinish;
		uuid_t optionalSecProxyId;		classcode_t classCode;

	public:
		CFSecSecSessionHBuff();
		CFSecSecSessionHBuff( const CFSecSecSessionHBuff& src );
		virtual ~CFSecSecSessionHBuff();

		virtual cflib::ICFLibCloneableObj* clone();
		virtual const uuid_ptr_t getRequiredSecSessionId() const;
		virtual const uuid_ptr_t getRequiredSecSessionIdReference() const;
		virtual void setRequiredSecSessionId( const uuid_ptr_t value );
		virtual void generateRequiredSecSessionId();

		virtual const uuid_ptr_t getRequiredSecUserId() const;
		virtual const uuid_ptr_t getRequiredSecUserIdReference() const;
		virtual void setRequiredSecUserId( const uuid_ptr_t value );
		virtual void generateRequiredSecUserId();

		virtual const std::string& getOptionalSecDevNameValue() const;
		virtual const std::string* getOptionalSecDevNameReference() const;
		virtual const bool isOptionalSecDevNameNull() const;
		virtual void setOptionalSecDevNameNull();
		virtual void setOptionalSecDevNameValue( const std::string& value );

		virtual const std::chrono::system_clock::time_point& getRequiredStart() const;
		virtual const std::chrono::system_clock::time_point* getRequiredStartReference() const;
		virtual void setRequiredStart( const std::chrono::system_clock::time_point& value );

		virtual const std::chrono::system_clock::time_point& getOptionalFinishValue() const;
		virtual const std::chrono::system_clock::time_point* getOptionalFinishReference() const;
		virtual const bool isOptionalFinishNull() const;
		virtual void setOptionalFinishNull();
		virtual void setOptionalFinishValue( const std::chrono::system_clock::time_point& value );

		virtual const uuid_ptr_t getOptionalSecProxyIdValue() const;
		virtual const uuid_ptr_t getOptionalSecProxyIdReference() const;
		virtual const bool isOptionalSecProxyIdNull() const;
		virtual void setOptionalSecProxyIdNull();
		virtual void setOptionalSecProxyIdValue( const uuid_ptr_t value );
		virtual void generateOptionalSecProxyId();

		virtual size_t hashCode() const;

		bool operator <( const CFSecSecSessionBySecUserIdxKey& rhs );
		bool operator <( const CFSecSecSessionBySecDevIdxKey& rhs );
		bool operator <( const CFSecSecSessionByStartIdxKey& rhs );
		bool operator <( const CFSecSecSessionByFinishIdxKey& rhs );
		bool operator <( const CFSecSecSessionBySecProxyIdxKey& rhs );
		bool operator <( const CFSecSecSessionPKey& rhs );
		bool operator <( const CFSecSecSessionHPKey& rhs );
		bool operator <( const CFSecSecSessionHBuff& rhs );
		bool operator <( const CFSecSecSessionBuff& rhs );

		bool operator <=( const CFSecSecSessionBySecUserIdxKey& rhs );
		bool operator <=( const CFSecSecSessionBySecDevIdxKey& rhs );
		bool operator <=( const CFSecSecSessionByStartIdxKey& rhs );
		bool operator <=( const CFSecSecSessionByFinishIdxKey& rhs );
		bool operator <=( const CFSecSecSessionBySecProxyIdxKey& rhs );
		bool operator <=( const CFSecSecSessionPKey& rhs );
		bool operator <=( const CFSecSecSessionHPKey& rhs );
		bool operator <=( const CFSecSecSessionHBuff& rhs );
		bool operator <=( const CFSecSecSessionBuff& rhs );

		bool operator ==( const CFSecSecSessionBySecUserIdxKey& rhs );
		bool operator ==( const CFSecSecSessionBySecDevIdxKey& rhs );
		bool operator ==( const CFSecSecSessionByStartIdxKey& rhs );
		bool operator ==( const CFSecSecSessionByFinishIdxKey& rhs );
		bool operator ==( const CFSecSecSessionBySecProxyIdxKey& rhs );
		bool operator ==( const CFSecSecSessionPKey& rhs );
		bool operator ==( const CFSecSecSessionHPKey& rhs );
		bool operator ==( const CFSecSecSessionHBuff& rhs );
		bool operator ==( const CFSecSecSessionBuff& rhs );

		bool operator !=( const CFSecSecSessionBySecUserIdxKey& rhs );
		bool operator !=( const CFSecSecSessionBySecDevIdxKey& rhs );
		bool operator !=( const CFSecSecSessionByStartIdxKey& rhs );
		bool operator !=( const CFSecSecSessionByFinishIdxKey& rhs );
		bool operator !=( const CFSecSecSessionBySecProxyIdxKey& rhs );
		bool operator !=( const CFSecSecSessionPKey& rhs );
		bool operator !=( const CFSecSecSessionHPKey& rhs );
		bool operator !=( const CFSecSecSessionHBuff& rhs );
		bool operator !=( const CFSecSecSessionBuff& rhs );

		bool operator >=( const CFSecSecSessionBySecUserIdxKey& rhs );
		bool operator >=( const CFSecSecSessionBySecDevIdxKey& rhs );
		bool operator >=( const CFSecSecSessionByStartIdxKey& rhs );
		bool operator >=( const CFSecSecSessionByFinishIdxKey& rhs );
		bool operator >=( const CFSecSecSessionBySecProxyIdxKey& rhs );
		bool operator >=( const CFSecSecSessionPKey& rhs );
		bool operator >=( const CFSecSecSessionHPKey& rhs );
		bool operator >=( const CFSecSecSessionHBuff& rhs );
		bool operator >=( const CFSecSecSessionBuff& rhs );

		bool operator >( const CFSecSecSessionBySecUserIdxKey& rhs );
		bool operator >( const CFSecSecSessionBySecDevIdxKey& rhs );
		bool operator >( const CFSecSecSessionByStartIdxKey& rhs );
		bool operator >( const CFSecSecSessionByFinishIdxKey& rhs );
		bool operator >( const CFSecSecSessionBySecProxyIdxKey& rhs );
		bool operator >( const CFSecSecSessionPKey& rhs );
		bool operator >( const CFSecSecSessionHPKey& rhs );
		bool operator >( const CFSecSecSessionHBuff& rhs );
		bool operator >( const CFSecSecSessionBuff& rhs );
		cfsec::CFSecSecSessionHBuff operator =( cfsec::CFSecSecSessionBuff& src );
		cfsec::CFSecSecSessionHBuff operator =( cfsec::CFSecSecSessionHBuff& src );

		virtual std::string toString();

	};
}

namespace std {

	bool operator <(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionBySecUserIdxKey& rhs );
	bool operator <(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionBySecDevIdxKey& rhs );
	bool operator <(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionByStartIdxKey& rhs );
	bool operator <(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionByFinishIdxKey& rhs );
	bool operator <(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionBySecProxyIdxKey& rhs );
	bool operator <(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionPKey& rhs );
	bool operator <(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionHPKey& rhs );
	bool operator <(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionHBuff& rhs );
	bool operator <(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionBuff& rhs );

	bool operator <=(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionBySecUserIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionBySecDevIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionByStartIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionByFinishIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionBySecProxyIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionPKey& rhs );
	bool operator <=(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionHPKey& rhs );
	bool operator <=(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionHBuff& rhs );
	bool operator <=(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionBuff& rhs );

	bool operator ==(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionBySecUserIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionBySecDevIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionByStartIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionByFinishIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionBySecProxyIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionPKey& rhs );
	bool operator ==(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionHPKey& rhs );
	bool operator ==(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionHBuff& rhs );
	bool operator ==(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionBuff& rhs );

	bool operator !=(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionBySecUserIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionBySecDevIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionByStartIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionByFinishIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionBySecProxyIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionPKey& rhs );
	bool operator !=(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionHPKey& rhs );
	bool operator !=(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionHBuff& rhs );
	bool operator !=(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionBuff& rhs );

	bool operator >=(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionBySecUserIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionBySecDevIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionByStartIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionByFinishIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionBySecProxyIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionPKey& rhs );
	bool operator >=(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionHPKey& rhs );
	bool operator >=(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionHBuff& rhs );
	bool operator >=(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionBuff& rhs );

	bool operator >(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionBySecUserIdxKey& rhs );
	bool operator >(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionBySecDevIdxKey& rhs );
	bool operator >(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionByStartIdxKey& rhs );
	bool operator >(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionByFinishIdxKey& rhs );
	bool operator >(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionBySecProxyIdxKey& rhs );
	bool operator >(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionPKey& rhs );
	bool operator >(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionHPKey& rhs );
	bool operator >(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionHBuff& rhs );
	bool operator >(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionBuff& rhs );

	template<> struct hash<cfsec::CFSecSecSessionHBuff> {
		typedef cfsec::CFSecSecSessionHBuff argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

