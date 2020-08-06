#pragma once

// Description: C++18 specification for a SecUser by DefDevIdx index key object.

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

	class CFSecSecUserBuff;
	class CFSecSecUserHBuff;

	class CFSecSecUserByDefDevIdxKey
	{
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;
	protected:
		uuid_t optionalDfltDevUserId;
		std::string* optionalDfltDevName;
	public:
		CFSecSecUserByDefDevIdxKey();
		CFSecSecUserByDefDevIdxKey( const CFSecSecUserByDefDevIdxKey& src );
		virtual ~CFSecSecUserByDefDevIdxKey();

		virtual const uuid_ptr_t getOptionalDfltDevUserIdValue() const;
		virtual const uuid_ptr_t getOptionalDfltDevUserIdReference() const;
		virtual const bool isOptionalDfltDevUserIdNull() const;
		virtual void setOptionalDfltDevUserIdNull();
		virtual void setOptionalDfltDevUserIdValue( const uuid_ptr_t value );
		virtual void generateOptionalDfltDevUserId();

		virtual const std::string& getOptionalDfltDevNameValue() const;
		virtual const std::string* getOptionalDfltDevNameReference() const;
		virtual const bool isOptionalDfltDevNameNull() const;
		virtual void setOptionalDfltDevNameNull();
		virtual void setOptionalDfltDevNameValue( const std::string& value );

		virtual size_t hashCode() const;

		std::string toString();

		bool operator <( const CFSecSecUserByDefDevIdxKey& rhs );
		bool operator <( const CFSecSecUserHBuff& rhs );
		bool operator <( const CFSecSecUserBuff& rhs );

		bool operator <=( const CFSecSecUserByDefDevIdxKey& rhs );
		bool operator <=( const CFSecSecUserHBuff& rhs );
		bool operator <=( const CFSecSecUserBuff& rhs );

		bool operator ==( const CFSecSecUserByDefDevIdxKey& rhs );
		bool operator ==( const CFSecSecUserHBuff& rhs );
		bool operator ==( const CFSecSecUserBuff& rhs );

		bool operator !=( const CFSecSecUserByDefDevIdxKey& rhs );
		bool operator !=( const CFSecSecUserHBuff& rhs );
		bool operator !=( const CFSecSecUserBuff& rhs );

		bool operator >=( const CFSecSecUserByDefDevIdxKey& rhs );
		bool operator >=( const CFSecSecUserHBuff& rhs );
		bool operator >=( const CFSecSecUserBuff& rhs );

		bool operator >( const CFSecSecUserByDefDevIdxKey& rhs );
		bool operator >( const CFSecSecUserHBuff& rhs );
		bool operator >( const CFSecSecUserBuff& rhs );
		cfsec::CFSecSecUserByDefDevIdxKey operator =( cfsec::CFSecSecUserByDefDevIdxKey& src );
		cfsec::CFSecSecUserByDefDevIdxKey operator =( cfsec::CFSecSecUserBuff& src );
		cfsec::CFSecSecUserByDefDevIdxKey operator =( cfsec::CFSecSecUserHBuff& src );
};
}

namespace std {

	bool operator <(const  cfsec::CFSecSecUserByDefDevIdxKey& lhs, const cfsec::CFSecSecUserByDefDevIdxKey& rhs );
	bool operator <(const  cfsec::CFSecSecUserByDefDevIdxKey& lhs, const cfsec::CFSecSecUserHBuff& rhs );
	bool operator <(const  cfsec::CFSecSecUserByDefDevIdxKey& lhs, const cfsec::CFSecSecUserBuff& rhs );

	bool operator <=(const  cfsec::CFSecSecUserByDefDevIdxKey& lhs, const cfsec::CFSecSecUserByDefDevIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecSecUserByDefDevIdxKey& lhs, const cfsec::CFSecSecUserHBuff& rhs );
	bool operator <=(const  cfsec::CFSecSecUserByDefDevIdxKey& lhs, const cfsec::CFSecSecUserBuff& rhs );

	bool operator ==(const  cfsec::CFSecSecUserByDefDevIdxKey& lhs, const cfsec::CFSecSecUserByDefDevIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecSecUserByDefDevIdxKey& lhs, const cfsec::CFSecSecUserHBuff& rhs );
	bool operator ==(const  cfsec::CFSecSecUserByDefDevIdxKey& lhs, const cfsec::CFSecSecUserBuff& rhs );

	bool operator !=(const  cfsec::CFSecSecUserByDefDevIdxKey& lhs, const cfsec::CFSecSecUserByDefDevIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecSecUserByDefDevIdxKey& lhs, const cfsec::CFSecSecUserHBuff& rhs );
	bool operator !=(const  cfsec::CFSecSecUserByDefDevIdxKey& lhs, const cfsec::CFSecSecUserBuff& rhs );

	bool operator >=(const  cfsec::CFSecSecUserByDefDevIdxKey& lhs, const cfsec::CFSecSecUserByDefDevIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecSecUserByDefDevIdxKey& lhs, const cfsec::CFSecSecUserHBuff& rhs );
	bool operator >=(const  cfsec::CFSecSecUserByDefDevIdxKey& lhs, const cfsec::CFSecSecUserBuff& rhs );

	bool operator >(const  cfsec::CFSecSecUserByDefDevIdxKey& lhs, const cfsec::CFSecSecUserByDefDevIdxKey& rhs );
	bool operator >(const  cfsec::CFSecSecUserByDefDevIdxKey& lhs, const cfsec::CFSecSecUserHBuff& rhs );
	bool operator >(const  cfsec::CFSecSecUserByDefDevIdxKey& lhs, const cfsec::CFSecSecUserBuff& rhs );

	template<> struct hash<cfsec::CFSecSecUserByDefDevIdxKey> {
		typedef cfsec::CFSecSecUserByDefDevIdxKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

