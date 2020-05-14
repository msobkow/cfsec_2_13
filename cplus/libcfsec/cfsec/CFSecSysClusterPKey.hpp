#pragma once

// Description: C++18 specification of a SysCluster primary key object.

/*
 *	com.github.msobkow.CFSec
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

	class CFSecSysClusterBuff;
	class CFSecSysClusterHPKey;
	class CFSecSysClusterHBuff;

	class CFSecSysClusterPKey
	{
	protected:

		int32_t requiredSingletonId;
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;

		CFSecSysClusterPKey();
		CFSecSysClusterPKey( const CFSecSysClusterPKey& src );
		virtual ~CFSecSysClusterPKey();

		virtual const int32_t getRequiredSingletonId() const;
		virtual const int32_t* getRequiredSingletonIdReference() const;
		virtual void setRequiredSingletonId( const int32_t value );

		bool operator <( const CFSecSysClusterHPKey& rhs );
		bool operator <( const CFSecSysClusterPKey& rhs );
		bool operator <( const CFSecSysClusterHBuff& rhs );
		bool operator <( const CFSecSysClusterBuff& rhs );

		bool operator <=( const CFSecSysClusterHPKey& rhs );
		bool operator <=( const CFSecSysClusterPKey& rhs );
		bool operator <=( const CFSecSysClusterHBuff& rhs );
		bool operator <=( const CFSecSysClusterBuff& rhs );

		bool operator ==( const CFSecSysClusterHPKey& rhs );
		bool operator ==( const CFSecSysClusterPKey& rhs );
		bool operator ==( const CFSecSysClusterHBuff& rhs );
		bool operator ==( const CFSecSysClusterBuff& rhs );

		bool operator !=( const CFSecSysClusterHPKey& rhs );
		bool operator !=( const CFSecSysClusterPKey& rhs );
		bool operator !=( const CFSecSysClusterHBuff& rhs );
		bool operator !=( const CFSecSysClusterBuff& rhs );

		bool operator >=( const CFSecSysClusterHPKey& rhs );
		bool operator >=( const CFSecSysClusterPKey& rhs );
		bool operator >=( const CFSecSysClusterHBuff& rhs );
		bool operator >=( const CFSecSysClusterBuff& rhs );

		bool operator >( const CFSecSysClusterHPKey& rhs );
		bool operator >( const CFSecSysClusterPKey& rhs );
		bool operator >( const CFSecSysClusterHBuff& rhs );
		bool operator >( const CFSecSysClusterBuff& rhs );
		virtual size_t hashCode() const;

		virtual std::string toString();

		cfsec::CFSecSysClusterPKey operator =( cfsec::CFSecSysClusterPKey& src );
		cfsec::CFSecSysClusterPKey operator =( cfsec::CFSecSysClusterHPKey& src );
		cfsec::CFSecSysClusterPKey operator =( cfsec::CFSecSysClusterBuff& src );
		cfsec::CFSecSysClusterPKey operator =( cfsec::CFSecSysClusterHBuff& src );
	};
}

namespace std {

	bool operator <(const  cfsec::CFSecSysClusterPKey& lhs, const cfsec::CFSecSysClusterHPKey& rhs );
	bool operator <(const  cfsec::CFSecSysClusterPKey& lhs, const cfsec::CFSecSysClusterPKey& rhs );
	bool operator <(const  cfsec::CFSecSysClusterPKey& lhs, const cfsec::CFSecSysClusterHBuff& rhs );
	bool operator <(const  cfsec::CFSecSysClusterPKey& lhs, const cfsec::CFSecSysClusterBuff& rhs );

	bool operator <=(const  cfsec::CFSecSysClusterPKey& lhs, const cfsec::CFSecSysClusterHPKey& rhs );
	bool operator <=(const  cfsec::CFSecSysClusterPKey& lhs, const cfsec::CFSecSysClusterPKey& rhs );
	bool operator <=(const  cfsec::CFSecSysClusterPKey& lhs, const cfsec::CFSecSysClusterHBuff& rhs );
	bool operator <=(const  cfsec::CFSecSysClusterPKey& lhs, const cfsec::CFSecSysClusterBuff& rhs );

	bool operator ==(const  cfsec::CFSecSysClusterPKey& lhs, const cfsec::CFSecSysClusterHPKey& rhs );
	bool operator ==(const  cfsec::CFSecSysClusterPKey& lhs, const cfsec::CFSecSysClusterPKey& rhs );
	bool operator ==(const  cfsec::CFSecSysClusterPKey& lhs, const cfsec::CFSecSysClusterHBuff& rhs );
	bool operator ==(const  cfsec::CFSecSysClusterPKey& lhs, const cfsec::CFSecSysClusterBuff& rhs );

	bool operator !=(const  cfsec::CFSecSysClusterPKey& lhs, const cfsec::CFSecSysClusterHPKey& rhs );
	bool operator !=(const  cfsec::CFSecSysClusterPKey& lhs, const cfsec::CFSecSysClusterPKey& rhs );
	bool operator !=(const  cfsec::CFSecSysClusterPKey& lhs, const cfsec::CFSecSysClusterHBuff& rhs );
	bool operator !=(const  cfsec::CFSecSysClusterPKey& lhs, const cfsec::CFSecSysClusterBuff& rhs );

	bool operator >=(const  cfsec::CFSecSysClusterPKey& lhs, const cfsec::CFSecSysClusterHPKey& rhs );
	bool operator >=(const  cfsec::CFSecSysClusterPKey& lhs, const cfsec::CFSecSysClusterPKey& rhs );
	bool operator >=(const  cfsec::CFSecSysClusterPKey& lhs, const cfsec::CFSecSysClusterHBuff& rhs );
	bool operator >=(const  cfsec::CFSecSysClusterPKey& lhs, const cfsec::CFSecSysClusterBuff& rhs );

	bool operator >(const  cfsec::CFSecSysClusterPKey& lhs, const cfsec::CFSecSysClusterHPKey& rhs );
	bool operator >(const  cfsec::CFSecSysClusterPKey& lhs, const cfsec::CFSecSysClusterPKey& rhs );
	bool operator >(const  cfsec::CFSecSysClusterPKey& lhs, const cfsec::CFSecSysClusterHBuff& rhs );
	bool operator >(const  cfsec::CFSecSysClusterPKey& lhs, const cfsec::CFSecSysClusterBuff& rhs );

	template<> struct hash<cfsec::CFSecSysClusterPKey> {
		typedef cfsec::CFSecSysClusterPKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

