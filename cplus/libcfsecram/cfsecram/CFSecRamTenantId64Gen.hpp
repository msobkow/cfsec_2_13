#pragma once

// Description: C++18 Interface of a Tenant 64-bit in-memory RAM Id Generator object.

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
#include <cfsec/ICFSecPublic.hpp>
#include <cfsecobj/ICFSecObjPublic.hpp>

namespace cfsec {

	class CFSecRamTenantId64Gen
	{
	protected:
		int64_t requiredId;
		int16_t sliceId = 0;
		int64_t nextId = 1;
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;
	CFSecRamTenantId64Gen();
	~CFSecRamTenantId64Gen();

		int64_t getNextId();
		virtual const int64_t getRequiredId() const;
		virtual const int64_t* getRequiredIdReference() const;
		virtual void setRequiredId( const int64_t value );

	int16_t getRequiredSliceId() const;
	void setRequiredSliceId( int16_t value );

	size_t hashCode() const;

		bool operator <( const cfsec::CFSecRamTenantId64Gen& rhs );

		bool operator <=( const cfsec::CFSecRamTenantId64Gen& rhs );

		bool operator ==( const cfsec::CFSecRamTenantId64Gen& rhs );

		bool operator !=( const cfsec::CFSecRamTenantId64Gen& rhs );

		bool operator >=( const cfsec::CFSecRamTenantId64Gen& rhs );

		bool operator >( const cfsec::CFSecRamTenantId64Gen& rhs );
		CFSecRamTenantId64Gen operator =( CFSecRamTenantId64Gen& src );

	};
}

namespace std {

	bool operator <(const cfsec::CFSecRamTenantId64Gen& lhs, const cfsec::CFSecRamTenantId64Gen& rhs );

	bool operator <=(const cfsec::CFSecRamTenantId64Gen& lhs, const cfsec::CFSecRamTenantId64Gen& rhs );

	bool operator ==(const cfsec::CFSecRamTenantId64Gen& lhs, const cfsec::CFSecRamTenantId64Gen& rhs );

	bool operator !=(const cfsec::CFSecRamTenantId64Gen& lhs, const cfsec::CFSecRamTenantId64Gen& rhs );

	bool operator >=(const cfsec::CFSecRamTenantId64Gen& lhs, const cfsec::CFSecRamTenantId64Gen& rhs );

	bool operator >(const cfsec::CFSecRamTenantId64Gen& lhs, const cfsec::CFSecRamTenantId64Gen& rhs );

	template<> struct hash<cfsec::CFSecRamTenantId64Gen> {
		typedef cfsec::CFSecRamTenantId64Gen argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};


}
