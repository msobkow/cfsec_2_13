#pragma once

// Description: C++18 specification of a Service history primary key object.

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

#include <cfsec/CFSecHPKey.hpp>
#include <cfsec/ICFSecSchema.hpp>

namespace cfsec {

	class CFSecServicePKey;
	class CFSecServiceBuff;
	class CFSecServiceHBuff;

	class CFSecServiceHPKey : public CFSecHPKey
	{
	protected:

		int64_t requiredClusterId;
		int64_t requiredServiceId;
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;

		CFSecServiceHPKey();
		CFSecServiceHPKey( const CFSecServiceHPKey& src );
		virtual ~CFSecServiceHPKey();

		virtual const int64_t getRequiredClusterId() const;
		virtual const int64_t* getRequiredClusterIdReference() const;
		virtual void setRequiredClusterId( const int64_t value );

		virtual const int64_t getRequiredServiceId() const;
		virtual const int64_t* getRequiredServiceIdReference() const;
		virtual void setRequiredServiceId( const int64_t value );

		virtual size_t hashCode() const;

		virtual std::string toString();

		bool operator <( const CFSecServicePKey& rhs );
		bool operator <( const CFSecServiceHPKey& rhs );
		bool operator <( const CFSecServiceHBuff& rhs );
		bool operator <( const CFSecServiceBuff& rhs );


		bool operator <=( const CFSecServicePKey& rhs );
		bool operator <=( const CFSecServiceHPKey& rhs );
		bool operator <=( const CFSecServiceHBuff& rhs );
		bool operator <=( const CFSecServiceBuff& rhs );


		bool operator ==( const CFSecServicePKey& rhs );
		bool operator ==( const CFSecServiceHPKey& rhs );
		bool operator ==( const CFSecServiceHBuff& rhs );
		bool operator ==( const CFSecServiceBuff& rhs );


		bool operator !=( const CFSecServicePKey& rhs );
		bool operator !=( const CFSecServiceHPKey& rhs );
		bool operator !=( const CFSecServiceHBuff& rhs );
		bool operator !=( const CFSecServiceBuff& rhs );


		bool operator >=( const CFSecServicePKey& rhs );
		bool operator >=( const CFSecServiceHPKey& rhs );
		bool operator >=( const CFSecServiceHBuff& rhs );
		bool operator >=( const CFSecServiceBuff& rhs );


		bool operator >( const CFSecServicePKey& rhs );
		bool operator >( const CFSecServiceHPKey& rhs );
		bool operator >( const CFSecServiceHBuff& rhs );
		bool operator >( const CFSecServiceBuff& rhs );

		cfsec::CFSecServiceHPKey operator =( cfsec::CFSecServicePKey& src );
		cfsec::CFSecServiceHPKey operator =( cfsec::CFSecServiceHPKey& src );
		cfsec::CFSecServiceHPKey operator =( cfsec::CFSecServiceBuff& src );
		cfsec::CFSecServiceHPKey operator =( cfsec::CFSecServiceHBuff& src );

	};
}


namespace std {

	bool operator <(const  cfsec::CFSecServiceHPKey& lhs, const cfsec::CFSecServicePKey& rhs );
	bool operator <(const  cfsec::CFSecServiceHPKey& lhs, const cfsec::CFSecServiceHPKey& rhs );
	bool operator <(const  cfsec::CFSecServiceHPKey& lhs, const cfsec::CFSecServiceHBuff& rhs );
	bool operator <(const  cfsec::CFSecServiceHPKey& lhs, const cfsec::CFSecServiceBuff& rhs );


	bool operator <=(const  cfsec::CFSecServiceHPKey& lhs, const cfsec::CFSecServicePKey& rhs );
	bool operator <=(const  cfsec::CFSecServiceHPKey& lhs, const cfsec::CFSecServiceHPKey& rhs );
	bool operator <=(const  cfsec::CFSecServiceHPKey& lhs, const cfsec::CFSecServiceHBuff& rhs );
	bool operator <=(const  cfsec::CFSecServiceHPKey& lhs, const cfsec::CFSecServiceBuff& rhs );


	bool operator ==(const  cfsec::CFSecServiceHPKey& lhs, const cfsec::CFSecServicePKey& rhs );
	bool operator ==(const  cfsec::CFSecServiceHPKey& lhs, const cfsec::CFSecServiceHPKey& rhs );
	bool operator ==(const  cfsec::CFSecServiceHPKey& lhs, const cfsec::CFSecServiceHBuff& rhs );
	bool operator ==(const  cfsec::CFSecServiceHPKey& lhs, const cfsec::CFSecServiceBuff& rhs );


	bool operator !=(const  cfsec::CFSecServiceHPKey& lhs, const cfsec::CFSecServicePKey& rhs );
	bool operator !=(const  cfsec::CFSecServiceHPKey& lhs, const cfsec::CFSecServiceHPKey& rhs );
	bool operator !=(const  cfsec::CFSecServiceHPKey& lhs, const cfsec::CFSecServiceHBuff& rhs );
	bool operator !=(const  cfsec::CFSecServiceHPKey& lhs, const cfsec::CFSecServiceBuff& rhs );


	bool operator >=(const  cfsec::CFSecServiceHPKey& lhs, const cfsec::CFSecServicePKey& rhs );
	bool operator >=(const  cfsec::CFSecServiceHPKey& lhs, const cfsec::CFSecServiceHPKey& rhs );
	bool operator >=(const  cfsec::CFSecServiceHPKey& lhs, const cfsec::CFSecServiceHBuff& rhs );
	bool operator >=(const  cfsec::CFSecServiceHPKey& lhs, const cfsec::CFSecServiceBuff& rhs );


	bool operator >(const  cfsec::CFSecServiceHPKey& lhs, const cfsec::CFSecServicePKey& rhs );
	bool operator >(const  cfsec::CFSecServiceHPKey& lhs, const cfsec::CFSecServiceHPKey& rhs );
	bool operator >(const  cfsec::CFSecServiceHPKey& lhs, const cfsec::CFSecServiceHBuff& rhs );
	bool operator >(const  cfsec::CFSecServiceHPKey& lhs, const cfsec::CFSecServiceBuff& rhs );


	template<> struct hash<cfsec::CFSecServiceHPKey> {
		typedef cfsec::CFSecServiceHPKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

