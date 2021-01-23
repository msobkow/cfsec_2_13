#pragma once

// Description: C++18 specification for a Cluster by UDomNameIdx index key object.

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

	class CFSecClusterBuff;
	class CFSecClusterHBuff;

	class CFSecClusterByUDomNameIdxKey
	{
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;
	protected:
		std::string* requiredFullDomName;
	public:
		CFSecClusterByUDomNameIdxKey();
		CFSecClusterByUDomNameIdxKey( const CFSecClusterByUDomNameIdxKey& src );
		virtual ~CFSecClusterByUDomNameIdxKey();

		virtual const std::string& getRequiredFullDomName() const;
		virtual const std::string* getRequiredFullDomNameReference() const;
		virtual void setRequiredFullDomName( const std::string& value );

		virtual size_t hashCode() const;

		std::string toString();

		bool operator <( const CFSecClusterByUDomNameIdxKey& rhs );
		bool operator <( const CFSecClusterHBuff& rhs );
		bool operator <( const CFSecClusterBuff& rhs );

		bool operator <=( const CFSecClusterByUDomNameIdxKey& rhs );
		bool operator <=( const CFSecClusterHBuff& rhs );
		bool operator <=( const CFSecClusterBuff& rhs );

		bool operator ==( const CFSecClusterByUDomNameIdxKey& rhs );
		bool operator ==( const CFSecClusterHBuff& rhs );
		bool operator ==( const CFSecClusterBuff& rhs );

		bool operator !=( const CFSecClusterByUDomNameIdxKey& rhs );
		bool operator !=( const CFSecClusterHBuff& rhs );
		bool operator !=( const CFSecClusterBuff& rhs );

		bool operator >=( const CFSecClusterByUDomNameIdxKey& rhs );
		bool operator >=( const CFSecClusterHBuff& rhs );
		bool operator >=( const CFSecClusterBuff& rhs );

		bool operator >( const CFSecClusterByUDomNameIdxKey& rhs );
		bool operator >( const CFSecClusterHBuff& rhs );
		bool operator >( const CFSecClusterBuff& rhs );
		cfsec::CFSecClusterByUDomNameIdxKey operator =( cfsec::CFSecClusterByUDomNameIdxKey& src );
		cfsec::CFSecClusterByUDomNameIdxKey operator =( cfsec::CFSecClusterBuff& src );
		cfsec::CFSecClusterByUDomNameIdxKey operator =( cfsec::CFSecClusterHBuff& src );
};
}

namespace std {

	bool operator <(const  cfsec::CFSecClusterByUDomNameIdxKey& lhs, const cfsec::CFSecClusterByUDomNameIdxKey& rhs );
	bool operator <(const  cfsec::CFSecClusterByUDomNameIdxKey& lhs, const cfsec::CFSecClusterHBuff& rhs );
	bool operator <(const  cfsec::CFSecClusterByUDomNameIdxKey& lhs, const cfsec::CFSecClusterBuff& rhs );

	bool operator <=(const  cfsec::CFSecClusterByUDomNameIdxKey& lhs, const cfsec::CFSecClusterByUDomNameIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecClusterByUDomNameIdxKey& lhs, const cfsec::CFSecClusterHBuff& rhs );
	bool operator <=(const  cfsec::CFSecClusterByUDomNameIdxKey& lhs, const cfsec::CFSecClusterBuff& rhs );

	bool operator ==(const  cfsec::CFSecClusterByUDomNameIdxKey& lhs, const cfsec::CFSecClusterByUDomNameIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecClusterByUDomNameIdxKey& lhs, const cfsec::CFSecClusterHBuff& rhs );
	bool operator ==(const  cfsec::CFSecClusterByUDomNameIdxKey& lhs, const cfsec::CFSecClusterBuff& rhs );

	bool operator !=(const  cfsec::CFSecClusterByUDomNameIdxKey& lhs, const cfsec::CFSecClusterByUDomNameIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecClusterByUDomNameIdxKey& lhs, const cfsec::CFSecClusterHBuff& rhs );
	bool operator !=(const  cfsec::CFSecClusterByUDomNameIdxKey& lhs, const cfsec::CFSecClusterBuff& rhs );

	bool operator >=(const  cfsec::CFSecClusterByUDomNameIdxKey& lhs, const cfsec::CFSecClusterByUDomNameIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecClusterByUDomNameIdxKey& lhs, const cfsec::CFSecClusterHBuff& rhs );
	bool operator >=(const  cfsec::CFSecClusterByUDomNameIdxKey& lhs, const cfsec::CFSecClusterBuff& rhs );

	bool operator >(const  cfsec::CFSecClusterByUDomNameIdxKey& lhs, const cfsec::CFSecClusterByUDomNameIdxKey& rhs );
	bool operator >(const  cfsec::CFSecClusterByUDomNameIdxKey& lhs, const cfsec::CFSecClusterHBuff& rhs );
	bool operator >(const  cfsec::CFSecClusterByUDomNameIdxKey& lhs, const cfsec::CFSecClusterBuff& rhs );

	template<> struct hash<cfsec::CFSecClusterByUDomNameIdxKey> {
		typedef cfsec::CFSecClusterByUDomNameIdxKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

