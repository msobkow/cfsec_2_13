#pragma once

// Description: C++18 specification for a Cluster by UDescrIdx index key object.

/*
 *	org.msscf.msscf.CFSec
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
#include <cfsec/ICFSecSchema.hpp>

namespace cfsec {

	class CFSecClusterBuff;
	class CFSecClusterHBuff;

	class CFSecClusterByUDescrIdxKey
	{
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;
	protected:
		std::string* requiredDescription;
	public:
		CFSecClusterByUDescrIdxKey();
		CFSecClusterByUDescrIdxKey( const CFSecClusterByUDescrIdxKey& src );
		virtual ~CFSecClusterByUDescrIdxKey();

		virtual const std::string& getRequiredDescription() const;
		virtual const std::string* getRequiredDescriptionReference() const;
		virtual void setRequiredDescription( const std::string& value );

		virtual size_t hashCode() const;

		std::string toString();

		bool operator <( const CFSecClusterByUDescrIdxKey& rhs );
		bool operator <( const CFSecClusterHBuff& rhs );
		bool operator <( const CFSecClusterBuff& rhs );

		bool operator <=( const CFSecClusterByUDescrIdxKey& rhs );
		bool operator <=( const CFSecClusterHBuff& rhs );
		bool operator <=( const CFSecClusterBuff& rhs );

		bool operator ==( const CFSecClusterByUDescrIdxKey& rhs );
		bool operator ==( const CFSecClusterHBuff& rhs );
		bool operator ==( const CFSecClusterBuff& rhs );

		bool operator !=( const CFSecClusterByUDescrIdxKey& rhs );
		bool operator !=( const CFSecClusterHBuff& rhs );
		bool operator !=( const CFSecClusterBuff& rhs );

		bool operator >=( const CFSecClusterByUDescrIdxKey& rhs );
		bool operator >=( const CFSecClusterHBuff& rhs );
		bool operator >=( const CFSecClusterBuff& rhs );

		bool operator >( const CFSecClusterByUDescrIdxKey& rhs );
		bool operator >( const CFSecClusterHBuff& rhs );
		bool operator >( const CFSecClusterBuff& rhs );
		cfsec::CFSecClusterByUDescrIdxKey operator =( cfsec::CFSecClusterByUDescrIdxKey& src );
		cfsec::CFSecClusterByUDescrIdxKey operator =( cfsec::CFSecClusterBuff& src );
		cfsec::CFSecClusterByUDescrIdxKey operator =( cfsec::CFSecClusterHBuff& src );
};
}

namespace std {

	bool operator <(const  cfsec::CFSecClusterByUDescrIdxKey& lhs, const cfsec::CFSecClusterByUDescrIdxKey& rhs );
	bool operator <(const  cfsec::CFSecClusterByUDescrIdxKey& lhs, const cfsec::CFSecClusterHBuff& rhs );
	bool operator <(const  cfsec::CFSecClusterByUDescrIdxKey& lhs, const cfsec::CFSecClusterBuff& rhs );

	bool operator <=(const  cfsec::CFSecClusterByUDescrIdxKey& lhs, const cfsec::CFSecClusterByUDescrIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecClusterByUDescrIdxKey& lhs, const cfsec::CFSecClusterHBuff& rhs );
	bool operator <=(const  cfsec::CFSecClusterByUDescrIdxKey& lhs, const cfsec::CFSecClusterBuff& rhs );

	bool operator ==(const  cfsec::CFSecClusterByUDescrIdxKey& lhs, const cfsec::CFSecClusterByUDescrIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecClusterByUDescrIdxKey& lhs, const cfsec::CFSecClusterHBuff& rhs );
	bool operator ==(const  cfsec::CFSecClusterByUDescrIdxKey& lhs, const cfsec::CFSecClusterBuff& rhs );

	bool operator !=(const  cfsec::CFSecClusterByUDescrIdxKey& lhs, const cfsec::CFSecClusterByUDescrIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecClusterByUDescrIdxKey& lhs, const cfsec::CFSecClusterHBuff& rhs );
	bool operator !=(const  cfsec::CFSecClusterByUDescrIdxKey& lhs, const cfsec::CFSecClusterBuff& rhs );

	bool operator >=(const  cfsec::CFSecClusterByUDescrIdxKey& lhs, const cfsec::CFSecClusterByUDescrIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecClusterByUDescrIdxKey& lhs, const cfsec::CFSecClusterHBuff& rhs );
	bool operator >=(const  cfsec::CFSecClusterByUDescrIdxKey& lhs, const cfsec::CFSecClusterBuff& rhs );

	bool operator >(const  cfsec::CFSecClusterByUDescrIdxKey& lhs, const cfsec::CFSecClusterByUDescrIdxKey& rhs );
	bool operator >(const  cfsec::CFSecClusterByUDescrIdxKey& lhs, const cfsec::CFSecClusterHBuff& rhs );
	bool operator >(const  cfsec::CFSecClusterByUDescrIdxKey& lhs, const cfsec::CFSecClusterBuff& rhs );

	template<> struct hash<cfsec::CFSecClusterByUDescrIdxKey> {
		typedef cfsec::CFSecClusterByUDescrIdxKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

