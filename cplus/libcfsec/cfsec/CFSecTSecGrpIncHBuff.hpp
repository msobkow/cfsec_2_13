#pragma once

// Description: C++18 specification of a TSecGrpInc history buffer object.

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

#include <cfsec/CFSecHPKey.hpp>

#include <cfsec/ICFSecSchema.hpp>
namespace cfsec {

	class CFSecTSecGrpIncBuff;
	class CFSecTSecGrpIncPKey;
	class CFSecTSecGrpIncHPKey;
	class CFSecTSecGrpIncByTenantIdxKey;
	class CFSecTSecGrpIncByGroupIdxKey;
	class CFSecTSecGrpIncByIncludeIdxKey;
	class CFSecTSecGrpIncByUIncludeIdxKey;

	class CFSecTSecGrpIncHBuff : public CFSecHPKey, public cflib::ICFLibCloneableObj
	{
	public:
		static const std::string CLASS_NAME;
	protected:
		int64_t requiredTenantId;
		int64_t requiredTSecGrpIncId;
		int32_t requiredTSecGroupId;
		int32_t requiredIncludeGroupId;		classcode_t classCode;

	public:
		CFSecTSecGrpIncHBuff();
		CFSecTSecGrpIncHBuff( const CFSecTSecGrpIncHBuff& src );
		virtual ~CFSecTSecGrpIncHBuff();

		virtual cflib::ICFLibCloneableObj* clone();
		virtual const int64_t getRequiredTenantId() const;
		virtual const int64_t* getRequiredTenantIdReference() const;
		virtual void setRequiredTenantId( const int64_t value );

		virtual const int64_t getRequiredTSecGrpIncId() const;
		virtual const int64_t* getRequiredTSecGrpIncIdReference() const;
		virtual void setRequiredTSecGrpIncId( const int64_t value );

		virtual const int32_t getRequiredTSecGroupId() const;
		virtual const int32_t* getRequiredTSecGroupIdReference() const;
		virtual void setRequiredTSecGroupId( const int32_t value );

		virtual const int32_t getRequiredIncludeGroupId() const;
		virtual const int32_t* getRequiredIncludeGroupIdReference() const;
		virtual void setRequiredIncludeGroupId( const int32_t value );

		virtual size_t hashCode() const;

		bool operator <( const CFSecTSecGrpIncByTenantIdxKey& rhs );
		bool operator <( const CFSecTSecGrpIncByGroupIdxKey& rhs );
		bool operator <( const CFSecTSecGrpIncByIncludeIdxKey& rhs );
		bool operator <( const CFSecTSecGrpIncByUIncludeIdxKey& rhs );
		bool operator <( const CFSecTSecGrpIncPKey& rhs );
		bool operator <( const CFSecTSecGrpIncHPKey& rhs );
		bool operator <( const CFSecTSecGrpIncHBuff& rhs );
		bool operator <( const CFSecTSecGrpIncBuff& rhs );

		bool operator <=( const CFSecTSecGrpIncByTenantIdxKey& rhs );
		bool operator <=( const CFSecTSecGrpIncByGroupIdxKey& rhs );
		bool operator <=( const CFSecTSecGrpIncByIncludeIdxKey& rhs );
		bool operator <=( const CFSecTSecGrpIncByUIncludeIdxKey& rhs );
		bool operator <=( const CFSecTSecGrpIncPKey& rhs );
		bool operator <=( const CFSecTSecGrpIncHPKey& rhs );
		bool operator <=( const CFSecTSecGrpIncHBuff& rhs );
		bool operator <=( const CFSecTSecGrpIncBuff& rhs );

		bool operator ==( const CFSecTSecGrpIncByTenantIdxKey& rhs );
		bool operator ==( const CFSecTSecGrpIncByGroupIdxKey& rhs );
		bool operator ==( const CFSecTSecGrpIncByIncludeIdxKey& rhs );
		bool operator ==( const CFSecTSecGrpIncByUIncludeIdxKey& rhs );
		bool operator ==( const CFSecTSecGrpIncPKey& rhs );
		bool operator ==( const CFSecTSecGrpIncHPKey& rhs );
		bool operator ==( const CFSecTSecGrpIncHBuff& rhs );
		bool operator ==( const CFSecTSecGrpIncBuff& rhs );

		bool operator !=( const CFSecTSecGrpIncByTenantIdxKey& rhs );
		bool operator !=( const CFSecTSecGrpIncByGroupIdxKey& rhs );
		bool operator !=( const CFSecTSecGrpIncByIncludeIdxKey& rhs );
		bool operator !=( const CFSecTSecGrpIncByUIncludeIdxKey& rhs );
		bool operator !=( const CFSecTSecGrpIncPKey& rhs );
		bool operator !=( const CFSecTSecGrpIncHPKey& rhs );
		bool operator !=( const CFSecTSecGrpIncHBuff& rhs );
		bool operator !=( const CFSecTSecGrpIncBuff& rhs );

		bool operator >=( const CFSecTSecGrpIncByTenantIdxKey& rhs );
		bool operator >=( const CFSecTSecGrpIncByGroupIdxKey& rhs );
		bool operator >=( const CFSecTSecGrpIncByIncludeIdxKey& rhs );
		bool operator >=( const CFSecTSecGrpIncByUIncludeIdxKey& rhs );
		bool operator >=( const CFSecTSecGrpIncPKey& rhs );
		bool operator >=( const CFSecTSecGrpIncHPKey& rhs );
		bool operator >=( const CFSecTSecGrpIncHBuff& rhs );
		bool operator >=( const CFSecTSecGrpIncBuff& rhs );

		bool operator >( const CFSecTSecGrpIncByTenantIdxKey& rhs );
		bool operator >( const CFSecTSecGrpIncByGroupIdxKey& rhs );
		bool operator >( const CFSecTSecGrpIncByIncludeIdxKey& rhs );
		bool operator >( const CFSecTSecGrpIncByUIncludeIdxKey& rhs );
		bool operator >( const CFSecTSecGrpIncPKey& rhs );
		bool operator >( const CFSecTSecGrpIncHPKey& rhs );
		bool operator >( const CFSecTSecGrpIncHBuff& rhs );
		bool operator >( const CFSecTSecGrpIncBuff& rhs );
		cfsec::CFSecTSecGrpIncHBuff operator =( cfsec::CFSecTSecGrpIncBuff& src );
		cfsec::CFSecTSecGrpIncHBuff operator =( cfsec::CFSecTSecGrpIncHBuff& src );

		virtual std::string toString();

	};
}

namespace std {

	bool operator <(const  cfsec::CFSecTSecGrpIncHBuff& lhs, const cfsec::CFSecTSecGrpIncByTenantIdxKey& rhs );
	bool operator <(const  cfsec::CFSecTSecGrpIncHBuff& lhs, const cfsec::CFSecTSecGrpIncByGroupIdxKey& rhs );
	bool operator <(const  cfsec::CFSecTSecGrpIncHBuff& lhs, const cfsec::CFSecTSecGrpIncByIncludeIdxKey& rhs );
	bool operator <(const  cfsec::CFSecTSecGrpIncHBuff& lhs, const cfsec::CFSecTSecGrpIncByUIncludeIdxKey& rhs );
	bool operator <(const  cfsec::CFSecTSecGrpIncHBuff& lhs, const cfsec::CFSecTSecGrpIncPKey& rhs );
	bool operator <(const  cfsec::CFSecTSecGrpIncHBuff& lhs, const cfsec::CFSecTSecGrpIncHPKey& rhs );
	bool operator <(const  cfsec::CFSecTSecGrpIncHBuff& lhs, const cfsec::CFSecTSecGrpIncHBuff& rhs );
	bool operator <(const  cfsec::CFSecTSecGrpIncHBuff& lhs, const cfsec::CFSecTSecGrpIncBuff& rhs );

	bool operator <=(const  cfsec::CFSecTSecGrpIncHBuff& lhs, const cfsec::CFSecTSecGrpIncByTenantIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecTSecGrpIncHBuff& lhs, const cfsec::CFSecTSecGrpIncByGroupIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecTSecGrpIncHBuff& lhs, const cfsec::CFSecTSecGrpIncByIncludeIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecTSecGrpIncHBuff& lhs, const cfsec::CFSecTSecGrpIncByUIncludeIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecTSecGrpIncHBuff& lhs, const cfsec::CFSecTSecGrpIncPKey& rhs );
	bool operator <=(const  cfsec::CFSecTSecGrpIncHBuff& lhs, const cfsec::CFSecTSecGrpIncHPKey& rhs );
	bool operator <=(const  cfsec::CFSecTSecGrpIncHBuff& lhs, const cfsec::CFSecTSecGrpIncHBuff& rhs );
	bool operator <=(const  cfsec::CFSecTSecGrpIncHBuff& lhs, const cfsec::CFSecTSecGrpIncBuff& rhs );

	bool operator ==(const  cfsec::CFSecTSecGrpIncHBuff& lhs, const cfsec::CFSecTSecGrpIncByTenantIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecTSecGrpIncHBuff& lhs, const cfsec::CFSecTSecGrpIncByGroupIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecTSecGrpIncHBuff& lhs, const cfsec::CFSecTSecGrpIncByIncludeIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecTSecGrpIncHBuff& lhs, const cfsec::CFSecTSecGrpIncByUIncludeIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecTSecGrpIncHBuff& lhs, const cfsec::CFSecTSecGrpIncPKey& rhs );
	bool operator ==(const  cfsec::CFSecTSecGrpIncHBuff& lhs, const cfsec::CFSecTSecGrpIncHPKey& rhs );
	bool operator ==(const  cfsec::CFSecTSecGrpIncHBuff& lhs, const cfsec::CFSecTSecGrpIncHBuff& rhs );
	bool operator ==(const  cfsec::CFSecTSecGrpIncHBuff& lhs, const cfsec::CFSecTSecGrpIncBuff& rhs );

	bool operator !=(const  cfsec::CFSecTSecGrpIncHBuff& lhs, const cfsec::CFSecTSecGrpIncByTenantIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecTSecGrpIncHBuff& lhs, const cfsec::CFSecTSecGrpIncByGroupIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecTSecGrpIncHBuff& lhs, const cfsec::CFSecTSecGrpIncByIncludeIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecTSecGrpIncHBuff& lhs, const cfsec::CFSecTSecGrpIncByUIncludeIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecTSecGrpIncHBuff& lhs, const cfsec::CFSecTSecGrpIncPKey& rhs );
	bool operator !=(const  cfsec::CFSecTSecGrpIncHBuff& lhs, const cfsec::CFSecTSecGrpIncHPKey& rhs );
	bool operator !=(const  cfsec::CFSecTSecGrpIncHBuff& lhs, const cfsec::CFSecTSecGrpIncHBuff& rhs );
	bool operator !=(const  cfsec::CFSecTSecGrpIncHBuff& lhs, const cfsec::CFSecTSecGrpIncBuff& rhs );

	bool operator >=(const  cfsec::CFSecTSecGrpIncHBuff& lhs, const cfsec::CFSecTSecGrpIncByTenantIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecTSecGrpIncHBuff& lhs, const cfsec::CFSecTSecGrpIncByGroupIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecTSecGrpIncHBuff& lhs, const cfsec::CFSecTSecGrpIncByIncludeIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecTSecGrpIncHBuff& lhs, const cfsec::CFSecTSecGrpIncByUIncludeIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecTSecGrpIncHBuff& lhs, const cfsec::CFSecTSecGrpIncPKey& rhs );
	bool operator >=(const  cfsec::CFSecTSecGrpIncHBuff& lhs, const cfsec::CFSecTSecGrpIncHPKey& rhs );
	bool operator >=(const  cfsec::CFSecTSecGrpIncHBuff& lhs, const cfsec::CFSecTSecGrpIncHBuff& rhs );
	bool operator >=(const  cfsec::CFSecTSecGrpIncHBuff& lhs, const cfsec::CFSecTSecGrpIncBuff& rhs );

	bool operator >(const  cfsec::CFSecTSecGrpIncHBuff& lhs, const cfsec::CFSecTSecGrpIncByTenantIdxKey& rhs );
	bool operator >(const  cfsec::CFSecTSecGrpIncHBuff& lhs, const cfsec::CFSecTSecGrpIncByGroupIdxKey& rhs );
	bool operator >(const  cfsec::CFSecTSecGrpIncHBuff& lhs, const cfsec::CFSecTSecGrpIncByIncludeIdxKey& rhs );
	bool operator >(const  cfsec::CFSecTSecGrpIncHBuff& lhs, const cfsec::CFSecTSecGrpIncByUIncludeIdxKey& rhs );
	bool operator >(const  cfsec::CFSecTSecGrpIncHBuff& lhs, const cfsec::CFSecTSecGrpIncPKey& rhs );
	bool operator >(const  cfsec::CFSecTSecGrpIncHBuff& lhs, const cfsec::CFSecTSecGrpIncHPKey& rhs );
	bool operator >(const  cfsec::CFSecTSecGrpIncHBuff& lhs, const cfsec::CFSecTSecGrpIncHBuff& rhs );
	bool operator >(const  cfsec::CFSecTSecGrpIncHBuff& lhs, const cfsec::CFSecTSecGrpIncBuff& rhs );

	template<> struct hash<cfsec::CFSecTSecGrpIncHBuff> {
		typedef cfsec::CFSecTSecGrpIncHBuff argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

