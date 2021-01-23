#pragma once

// Description: C++18 specification for a SecSession by FinishIdx index key object.

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
#include <cfsec/ICFSecSchema.hpp>

namespace cfsec {

	class CFSecSecSessionBuff;
	class CFSecSecSessionHBuff;

	class CFSecSecSessionByFinishIdxKey
	{
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;
	protected:
		uuid_t requiredSecUserId;
		std::chrono::system_clock::time_point* optionalFinish;
	public:
		CFSecSecSessionByFinishIdxKey();
		CFSecSecSessionByFinishIdxKey( const CFSecSecSessionByFinishIdxKey& src );
		virtual ~CFSecSecSessionByFinishIdxKey();

		virtual const uuid_ptr_t getRequiredSecUserId() const;
		virtual const uuid_ptr_t getRequiredSecUserIdReference() const;
		virtual void setRequiredSecUserId( const uuid_ptr_t value );
		virtual void generateRequiredSecUserId();

		virtual const std::chrono::system_clock::time_point& getOptionalFinishValue() const;
		virtual const std::chrono::system_clock::time_point* getOptionalFinishReference() const;
		virtual const bool isOptionalFinishNull() const;
		virtual void setOptionalFinishNull();
		virtual void setOptionalFinishValue( const std::chrono::system_clock::time_point& value );

		virtual size_t hashCode() const;

		std::string toString();

		bool operator <( const CFSecSecSessionByFinishIdxKey& rhs );
		bool operator <( const CFSecSecSessionHBuff& rhs );
		bool operator <( const CFSecSecSessionBuff& rhs );

		bool operator <=( const CFSecSecSessionByFinishIdxKey& rhs );
		bool operator <=( const CFSecSecSessionHBuff& rhs );
		bool operator <=( const CFSecSecSessionBuff& rhs );

		bool operator ==( const CFSecSecSessionByFinishIdxKey& rhs );
		bool operator ==( const CFSecSecSessionHBuff& rhs );
		bool operator ==( const CFSecSecSessionBuff& rhs );

		bool operator !=( const CFSecSecSessionByFinishIdxKey& rhs );
		bool operator !=( const CFSecSecSessionHBuff& rhs );
		bool operator !=( const CFSecSecSessionBuff& rhs );

		bool operator >=( const CFSecSecSessionByFinishIdxKey& rhs );
		bool operator >=( const CFSecSecSessionHBuff& rhs );
		bool operator >=( const CFSecSecSessionBuff& rhs );

		bool operator >( const CFSecSecSessionByFinishIdxKey& rhs );
		bool operator >( const CFSecSecSessionHBuff& rhs );
		bool operator >( const CFSecSecSessionBuff& rhs );
		cfsec::CFSecSecSessionByFinishIdxKey operator =( cfsec::CFSecSecSessionByFinishIdxKey& src );
		cfsec::CFSecSecSessionByFinishIdxKey operator =( cfsec::CFSecSecSessionBuff& src );
		cfsec::CFSecSecSessionByFinishIdxKey operator =( cfsec::CFSecSecSessionHBuff& src );
};
}

namespace std {

	bool operator <(const  cfsec::CFSecSecSessionByFinishIdxKey& lhs, const cfsec::CFSecSecSessionByFinishIdxKey& rhs );
	bool operator <(const  cfsec::CFSecSecSessionByFinishIdxKey& lhs, const cfsec::CFSecSecSessionHBuff& rhs );
	bool operator <(const  cfsec::CFSecSecSessionByFinishIdxKey& lhs, const cfsec::CFSecSecSessionBuff& rhs );

	bool operator <=(const  cfsec::CFSecSecSessionByFinishIdxKey& lhs, const cfsec::CFSecSecSessionByFinishIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecSecSessionByFinishIdxKey& lhs, const cfsec::CFSecSecSessionHBuff& rhs );
	bool operator <=(const  cfsec::CFSecSecSessionByFinishIdxKey& lhs, const cfsec::CFSecSecSessionBuff& rhs );

	bool operator ==(const  cfsec::CFSecSecSessionByFinishIdxKey& lhs, const cfsec::CFSecSecSessionByFinishIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecSecSessionByFinishIdxKey& lhs, const cfsec::CFSecSecSessionHBuff& rhs );
	bool operator ==(const  cfsec::CFSecSecSessionByFinishIdxKey& lhs, const cfsec::CFSecSecSessionBuff& rhs );

	bool operator !=(const  cfsec::CFSecSecSessionByFinishIdxKey& lhs, const cfsec::CFSecSecSessionByFinishIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecSecSessionByFinishIdxKey& lhs, const cfsec::CFSecSecSessionHBuff& rhs );
	bool operator !=(const  cfsec::CFSecSecSessionByFinishIdxKey& lhs, const cfsec::CFSecSecSessionBuff& rhs );

	bool operator >=(const  cfsec::CFSecSecSessionByFinishIdxKey& lhs, const cfsec::CFSecSecSessionByFinishIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecSecSessionByFinishIdxKey& lhs, const cfsec::CFSecSecSessionHBuff& rhs );
	bool operator >=(const  cfsec::CFSecSecSessionByFinishIdxKey& lhs, const cfsec::CFSecSecSessionBuff& rhs );

	bool operator >(const  cfsec::CFSecSecSessionByFinishIdxKey& lhs, const cfsec::CFSecSecSessionByFinishIdxKey& rhs );
	bool operator >(const  cfsec::CFSecSecSessionByFinishIdxKey& lhs, const cfsec::CFSecSecSessionHBuff& rhs );
	bool operator >(const  cfsec::CFSecSecSessionByFinishIdxKey& lhs, const cfsec::CFSecSecSessionBuff& rhs );

	template<> struct hash<cfsec::CFSecSecSessionByFinishIdxKey> {
		typedef cfsec::CFSecSecSessionByFinishIdxKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

