#pragma once

// Description: C++18 specification of a ServiceType history primary key object.

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

	class CFSecServiceTypePKey;
	class CFSecServiceTypeBuff;
	class CFSecServiceTypeHBuff;

	class CFSecServiceTypeHPKey : public CFSecHPKey
	{
	protected:

		int32_t requiredServiceTypeId;
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;

		CFSecServiceTypeHPKey();
		CFSecServiceTypeHPKey( const CFSecServiceTypeHPKey& src );
		virtual ~CFSecServiceTypeHPKey();

		virtual const int32_t getRequiredServiceTypeId() const;
		virtual const int32_t* getRequiredServiceTypeIdReference() const;
		virtual void setRequiredServiceTypeId( const int32_t value );

		virtual size_t hashCode() const;

		virtual std::string toString();

		bool operator <( const CFSecServiceTypePKey& rhs );
		bool operator <( const CFSecServiceTypeHPKey& rhs );
		bool operator <( const CFSecServiceTypeHBuff& rhs );
		bool operator <( const CFSecServiceTypeBuff& rhs );


		bool operator <=( const CFSecServiceTypePKey& rhs );
		bool operator <=( const CFSecServiceTypeHPKey& rhs );
		bool operator <=( const CFSecServiceTypeHBuff& rhs );
		bool operator <=( const CFSecServiceTypeBuff& rhs );


		bool operator ==( const CFSecServiceTypePKey& rhs );
		bool operator ==( const CFSecServiceTypeHPKey& rhs );
		bool operator ==( const CFSecServiceTypeHBuff& rhs );
		bool operator ==( const CFSecServiceTypeBuff& rhs );


		bool operator !=( const CFSecServiceTypePKey& rhs );
		bool operator !=( const CFSecServiceTypeHPKey& rhs );
		bool operator !=( const CFSecServiceTypeHBuff& rhs );
		bool operator !=( const CFSecServiceTypeBuff& rhs );


		bool operator >=( const CFSecServiceTypePKey& rhs );
		bool operator >=( const CFSecServiceTypeHPKey& rhs );
		bool operator >=( const CFSecServiceTypeHBuff& rhs );
		bool operator >=( const CFSecServiceTypeBuff& rhs );


		bool operator >( const CFSecServiceTypePKey& rhs );
		bool operator >( const CFSecServiceTypeHPKey& rhs );
		bool operator >( const CFSecServiceTypeHBuff& rhs );
		bool operator >( const CFSecServiceTypeBuff& rhs );

		cfsec::CFSecServiceTypeHPKey operator =( cfsec::CFSecServiceTypePKey& src );
		cfsec::CFSecServiceTypeHPKey operator =( cfsec::CFSecServiceTypeHPKey& src );
		cfsec::CFSecServiceTypeHPKey operator =( cfsec::CFSecServiceTypeBuff& src );
		cfsec::CFSecServiceTypeHPKey operator =( cfsec::CFSecServiceTypeHBuff& src );

	};
}


namespace std {

	bool operator <(const  cfsec::CFSecServiceTypeHPKey& lhs, const cfsec::CFSecServiceTypePKey& rhs );
	bool operator <(const  cfsec::CFSecServiceTypeHPKey& lhs, const cfsec::CFSecServiceTypeHPKey& rhs );
	bool operator <(const  cfsec::CFSecServiceTypeHPKey& lhs, const cfsec::CFSecServiceTypeHBuff& rhs );
	bool operator <(const  cfsec::CFSecServiceTypeHPKey& lhs, const cfsec::CFSecServiceTypeBuff& rhs );


	bool operator <=(const  cfsec::CFSecServiceTypeHPKey& lhs, const cfsec::CFSecServiceTypePKey& rhs );
	bool operator <=(const  cfsec::CFSecServiceTypeHPKey& lhs, const cfsec::CFSecServiceTypeHPKey& rhs );
	bool operator <=(const  cfsec::CFSecServiceTypeHPKey& lhs, const cfsec::CFSecServiceTypeHBuff& rhs );
	bool operator <=(const  cfsec::CFSecServiceTypeHPKey& lhs, const cfsec::CFSecServiceTypeBuff& rhs );


	bool operator ==(const  cfsec::CFSecServiceTypeHPKey& lhs, const cfsec::CFSecServiceTypePKey& rhs );
	bool operator ==(const  cfsec::CFSecServiceTypeHPKey& lhs, const cfsec::CFSecServiceTypeHPKey& rhs );
	bool operator ==(const  cfsec::CFSecServiceTypeHPKey& lhs, const cfsec::CFSecServiceTypeHBuff& rhs );
	bool operator ==(const  cfsec::CFSecServiceTypeHPKey& lhs, const cfsec::CFSecServiceTypeBuff& rhs );


	bool operator !=(const  cfsec::CFSecServiceTypeHPKey& lhs, const cfsec::CFSecServiceTypePKey& rhs );
	bool operator !=(const  cfsec::CFSecServiceTypeHPKey& lhs, const cfsec::CFSecServiceTypeHPKey& rhs );
	bool operator !=(const  cfsec::CFSecServiceTypeHPKey& lhs, const cfsec::CFSecServiceTypeHBuff& rhs );
	bool operator !=(const  cfsec::CFSecServiceTypeHPKey& lhs, const cfsec::CFSecServiceTypeBuff& rhs );


	bool operator >=(const  cfsec::CFSecServiceTypeHPKey& lhs, const cfsec::CFSecServiceTypePKey& rhs );
	bool operator >=(const  cfsec::CFSecServiceTypeHPKey& lhs, const cfsec::CFSecServiceTypeHPKey& rhs );
	bool operator >=(const  cfsec::CFSecServiceTypeHPKey& lhs, const cfsec::CFSecServiceTypeHBuff& rhs );
	bool operator >=(const  cfsec::CFSecServiceTypeHPKey& lhs, const cfsec::CFSecServiceTypeBuff& rhs );


	bool operator >(const  cfsec::CFSecServiceTypeHPKey& lhs, const cfsec::CFSecServiceTypePKey& rhs );
	bool operator >(const  cfsec::CFSecServiceTypeHPKey& lhs, const cfsec::CFSecServiceTypeHPKey& rhs );
	bool operator >(const  cfsec::CFSecServiceTypeHPKey& lhs, const cfsec::CFSecServiceTypeHBuff& rhs );
	bool operator >(const  cfsec::CFSecServiceTypeHPKey& lhs, const cfsec::CFSecServiceTypeBuff& rhs );


	template<> struct hash<cfsec::CFSecServiceTypeHPKey> {
		typedef cfsec::CFSecServiceTypeHPKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

