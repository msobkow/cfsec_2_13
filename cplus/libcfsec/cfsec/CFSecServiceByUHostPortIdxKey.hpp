#pragma once

// Description: C++18 specification for a Service by UHostPortIdx index key object.

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
#include <cfsec/ICFSecSchema.hpp>

namespace cfsec {

	class CFSecServiceBuff;
	class CFSecServiceHBuff;

	class CFSecServiceByUHostPortIdxKey
	{
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;
	protected:
		int64_t requiredClusterId;
		int64_t requiredHostNodeId;
		int16_t requiredHostPort;
	public:
		CFSecServiceByUHostPortIdxKey();
		CFSecServiceByUHostPortIdxKey( const CFSecServiceByUHostPortIdxKey& src );
		virtual ~CFSecServiceByUHostPortIdxKey();

		virtual const int64_t getRequiredClusterId() const;
		virtual const int64_t* getRequiredClusterIdReference() const;
		virtual void setRequiredClusterId( const int64_t value );

		virtual const int64_t getRequiredHostNodeId() const;
		virtual const int64_t* getRequiredHostNodeIdReference() const;
		virtual void setRequiredHostNodeId( const int64_t value );

		virtual const int16_t getRequiredHostPort() const;
		virtual const int16_t* getRequiredHostPortReference() const;
		virtual void setRequiredHostPort( const int16_t value );

		virtual size_t hashCode() const;

		std::string toString();

		bool operator <( const CFSecServiceByUHostPortIdxKey& rhs );
		bool operator <( const CFSecServiceHBuff& rhs );
		bool operator <( const CFSecServiceBuff& rhs );

		bool operator <=( const CFSecServiceByUHostPortIdxKey& rhs );
		bool operator <=( const CFSecServiceHBuff& rhs );
		bool operator <=( const CFSecServiceBuff& rhs );

		bool operator ==( const CFSecServiceByUHostPortIdxKey& rhs );
		bool operator ==( const CFSecServiceHBuff& rhs );
		bool operator ==( const CFSecServiceBuff& rhs );

		bool operator !=( const CFSecServiceByUHostPortIdxKey& rhs );
		bool operator !=( const CFSecServiceHBuff& rhs );
		bool operator !=( const CFSecServiceBuff& rhs );

		bool operator >=( const CFSecServiceByUHostPortIdxKey& rhs );
		bool operator >=( const CFSecServiceHBuff& rhs );
		bool operator >=( const CFSecServiceBuff& rhs );

		bool operator >( const CFSecServiceByUHostPortIdxKey& rhs );
		bool operator >( const CFSecServiceHBuff& rhs );
		bool operator >( const CFSecServiceBuff& rhs );
		cfsec::CFSecServiceByUHostPortIdxKey operator =( cfsec::CFSecServiceByUHostPortIdxKey& src );
		cfsec::CFSecServiceByUHostPortIdxKey operator =( cfsec::CFSecServiceBuff& src );
		cfsec::CFSecServiceByUHostPortIdxKey operator =( cfsec::CFSecServiceHBuff& src );
};
}

namespace std {

	bool operator <(const  cfsec::CFSecServiceByUHostPortIdxKey& lhs, const cfsec::CFSecServiceByUHostPortIdxKey& rhs );
	bool operator <(const  cfsec::CFSecServiceByUHostPortIdxKey& lhs, const cfsec::CFSecServiceHBuff& rhs );
	bool operator <(const  cfsec::CFSecServiceByUHostPortIdxKey& lhs, const cfsec::CFSecServiceBuff& rhs );

	bool operator <=(const  cfsec::CFSecServiceByUHostPortIdxKey& lhs, const cfsec::CFSecServiceByUHostPortIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecServiceByUHostPortIdxKey& lhs, const cfsec::CFSecServiceHBuff& rhs );
	bool operator <=(const  cfsec::CFSecServiceByUHostPortIdxKey& lhs, const cfsec::CFSecServiceBuff& rhs );

	bool operator ==(const  cfsec::CFSecServiceByUHostPortIdxKey& lhs, const cfsec::CFSecServiceByUHostPortIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecServiceByUHostPortIdxKey& lhs, const cfsec::CFSecServiceHBuff& rhs );
	bool operator ==(const  cfsec::CFSecServiceByUHostPortIdxKey& lhs, const cfsec::CFSecServiceBuff& rhs );

	bool operator !=(const  cfsec::CFSecServiceByUHostPortIdxKey& lhs, const cfsec::CFSecServiceByUHostPortIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecServiceByUHostPortIdxKey& lhs, const cfsec::CFSecServiceHBuff& rhs );
	bool operator !=(const  cfsec::CFSecServiceByUHostPortIdxKey& lhs, const cfsec::CFSecServiceBuff& rhs );

	bool operator >=(const  cfsec::CFSecServiceByUHostPortIdxKey& lhs, const cfsec::CFSecServiceByUHostPortIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecServiceByUHostPortIdxKey& lhs, const cfsec::CFSecServiceHBuff& rhs );
	bool operator >=(const  cfsec::CFSecServiceByUHostPortIdxKey& lhs, const cfsec::CFSecServiceBuff& rhs );

	bool operator >(const  cfsec::CFSecServiceByUHostPortIdxKey& lhs, const cfsec::CFSecServiceByUHostPortIdxKey& rhs );
	bool operator >(const  cfsec::CFSecServiceByUHostPortIdxKey& lhs, const cfsec::CFSecServiceHBuff& rhs );
	bool operator >(const  cfsec::CFSecServiceByUHostPortIdxKey& lhs, const cfsec::CFSecServiceBuff& rhs );

	template<> struct hash<cfsec::CFSecServiceByUHostPortIdxKey> {
		typedef cfsec::CFSecServiceByUHostPortIdxKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

