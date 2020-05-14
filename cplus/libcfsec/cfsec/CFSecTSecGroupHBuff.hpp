#pragma once

// Description: C++18 specification of a TSecGroup history buffer object.

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

#include <cfsec/CFSecHPKey.hpp>

#include <cfsec/ICFSecSchema.hpp>
namespace cfsec {

	class CFSecTSecGroupBuff;
	class CFSecTSecGroupPKey;
	class CFSecTSecGroupHPKey;
	class CFSecTSecGroupByTenantIdxKey;
	class CFSecTSecGroupByTenantVisIdxKey;
	class CFSecTSecGroupByUNameIdxKey;

	class CFSecTSecGroupHBuff : public CFSecHPKey, public cflib::ICFLibCloneableObj
	{
	public:
		static const std::string CLASS_NAME;
	protected:
		int64_t requiredTenantId;
		int32_t requiredTSecGroupId;
		std::string* requiredName;
		bool requiredIsVisible;		classcode_t classCode;

	public:
		CFSecTSecGroupHBuff();
		CFSecTSecGroupHBuff( const CFSecTSecGroupHBuff& src );
		virtual ~CFSecTSecGroupHBuff();

		virtual cflib::ICFLibCloneableObj* clone();
		virtual const int64_t getRequiredTenantId() const;
		virtual const int64_t* getRequiredTenantIdReference() const;
		virtual void setRequiredTenantId( const int64_t value );

		virtual const int32_t getRequiredTSecGroupId() const;
		virtual const int32_t* getRequiredTSecGroupIdReference() const;
		virtual void setRequiredTSecGroupId( const int32_t value );

		virtual const std::string& getRequiredName() const;
		virtual const std::string* getRequiredNameReference() const;
		virtual void setRequiredName( const std::string& value );

		virtual const bool getRequiredIsVisible() const;
		virtual const bool* getRequiredIsVisibleReference() const;
		virtual void setRequiredIsVisible( const bool value );

		virtual size_t hashCode() const;

		bool operator <( const CFSecTSecGroupByTenantIdxKey& rhs );
		bool operator <( const CFSecTSecGroupByTenantVisIdxKey& rhs );
		bool operator <( const CFSecTSecGroupByUNameIdxKey& rhs );
		bool operator <( const CFSecTSecGroupPKey& rhs );
		bool operator <( const CFSecTSecGroupHPKey& rhs );
		bool operator <( const CFSecTSecGroupHBuff& rhs );
		bool operator <( const CFSecTSecGroupBuff& rhs );

		bool operator <=( const CFSecTSecGroupByTenantIdxKey& rhs );
		bool operator <=( const CFSecTSecGroupByTenantVisIdxKey& rhs );
		bool operator <=( const CFSecTSecGroupByUNameIdxKey& rhs );
		bool operator <=( const CFSecTSecGroupPKey& rhs );
		bool operator <=( const CFSecTSecGroupHPKey& rhs );
		bool operator <=( const CFSecTSecGroupHBuff& rhs );
		bool operator <=( const CFSecTSecGroupBuff& rhs );

		bool operator ==( const CFSecTSecGroupByTenantIdxKey& rhs );
		bool operator ==( const CFSecTSecGroupByTenantVisIdxKey& rhs );
		bool operator ==( const CFSecTSecGroupByUNameIdxKey& rhs );
		bool operator ==( const CFSecTSecGroupPKey& rhs );
		bool operator ==( const CFSecTSecGroupHPKey& rhs );
		bool operator ==( const CFSecTSecGroupHBuff& rhs );
		bool operator ==( const CFSecTSecGroupBuff& rhs );

		bool operator !=( const CFSecTSecGroupByTenantIdxKey& rhs );
		bool operator !=( const CFSecTSecGroupByTenantVisIdxKey& rhs );
		bool operator !=( const CFSecTSecGroupByUNameIdxKey& rhs );
		bool operator !=( const CFSecTSecGroupPKey& rhs );
		bool operator !=( const CFSecTSecGroupHPKey& rhs );
		bool operator !=( const CFSecTSecGroupHBuff& rhs );
		bool operator !=( const CFSecTSecGroupBuff& rhs );

		bool operator >=( const CFSecTSecGroupByTenantIdxKey& rhs );
		bool operator >=( const CFSecTSecGroupByTenantVisIdxKey& rhs );
		bool operator >=( const CFSecTSecGroupByUNameIdxKey& rhs );
		bool operator >=( const CFSecTSecGroupPKey& rhs );
		bool operator >=( const CFSecTSecGroupHPKey& rhs );
		bool operator >=( const CFSecTSecGroupHBuff& rhs );
		bool operator >=( const CFSecTSecGroupBuff& rhs );

		bool operator >( const CFSecTSecGroupByTenantIdxKey& rhs );
		bool operator >( const CFSecTSecGroupByTenantVisIdxKey& rhs );
		bool operator >( const CFSecTSecGroupByUNameIdxKey& rhs );
		bool operator >( const CFSecTSecGroupPKey& rhs );
		bool operator >( const CFSecTSecGroupHPKey& rhs );
		bool operator >( const CFSecTSecGroupHBuff& rhs );
		bool operator >( const CFSecTSecGroupBuff& rhs );
		cfsec::CFSecTSecGroupHBuff operator =( cfsec::CFSecTSecGroupBuff& src );
		cfsec::CFSecTSecGroupHBuff operator =( cfsec::CFSecTSecGroupHBuff& src );

		virtual std::string toString();

	};
}

namespace std {

	bool operator <(const  cfsec::CFSecTSecGroupHBuff& lhs, const cfsec::CFSecTSecGroupByTenantIdxKey& rhs );
	bool operator <(const  cfsec::CFSecTSecGroupHBuff& lhs, const cfsec::CFSecTSecGroupByTenantVisIdxKey& rhs );
	bool operator <(const  cfsec::CFSecTSecGroupHBuff& lhs, const cfsec::CFSecTSecGroupByUNameIdxKey& rhs );
	bool operator <(const  cfsec::CFSecTSecGroupHBuff& lhs, const cfsec::CFSecTSecGroupPKey& rhs );
	bool operator <(const  cfsec::CFSecTSecGroupHBuff& lhs, const cfsec::CFSecTSecGroupHPKey& rhs );
	bool operator <(const  cfsec::CFSecTSecGroupHBuff& lhs, const cfsec::CFSecTSecGroupHBuff& rhs );
	bool operator <(const  cfsec::CFSecTSecGroupHBuff& lhs, const cfsec::CFSecTSecGroupBuff& rhs );

	bool operator <=(const  cfsec::CFSecTSecGroupHBuff& lhs, const cfsec::CFSecTSecGroupByTenantIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecTSecGroupHBuff& lhs, const cfsec::CFSecTSecGroupByTenantVisIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecTSecGroupHBuff& lhs, const cfsec::CFSecTSecGroupByUNameIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecTSecGroupHBuff& lhs, const cfsec::CFSecTSecGroupPKey& rhs );
	bool operator <=(const  cfsec::CFSecTSecGroupHBuff& lhs, const cfsec::CFSecTSecGroupHPKey& rhs );
	bool operator <=(const  cfsec::CFSecTSecGroupHBuff& lhs, const cfsec::CFSecTSecGroupHBuff& rhs );
	bool operator <=(const  cfsec::CFSecTSecGroupHBuff& lhs, const cfsec::CFSecTSecGroupBuff& rhs );

	bool operator ==(const  cfsec::CFSecTSecGroupHBuff& lhs, const cfsec::CFSecTSecGroupByTenantIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecTSecGroupHBuff& lhs, const cfsec::CFSecTSecGroupByTenantVisIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecTSecGroupHBuff& lhs, const cfsec::CFSecTSecGroupByUNameIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecTSecGroupHBuff& lhs, const cfsec::CFSecTSecGroupPKey& rhs );
	bool operator ==(const  cfsec::CFSecTSecGroupHBuff& lhs, const cfsec::CFSecTSecGroupHPKey& rhs );
	bool operator ==(const  cfsec::CFSecTSecGroupHBuff& lhs, const cfsec::CFSecTSecGroupHBuff& rhs );
	bool operator ==(const  cfsec::CFSecTSecGroupHBuff& lhs, const cfsec::CFSecTSecGroupBuff& rhs );

	bool operator !=(const  cfsec::CFSecTSecGroupHBuff& lhs, const cfsec::CFSecTSecGroupByTenantIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecTSecGroupHBuff& lhs, const cfsec::CFSecTSecGroupByTenantVisIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecTSecGroupHBuff& lhs, const cfsec::CFSecTSecGroupByUNameIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecTSecGroupHBuff& lhs, const cfsec::CFSecTSecGroupPKey& rhs );
	bool operator !=(const  cfsec::CFSecTSecGroupHBuff& lhs, const cfsec::CFSecTSecGroupHPKey& rhs );
	bool operator !=(const  cfsec::CFSecTSecGroupHBuff& lhs, const cfsec::CFSecTSecGroupHBuff& rhs );
	bool operator !=(const  cfsec::CFSecTSecGroupHBuff& lhs, const cfsec::CFSecTSecGroupBuff& rhs );

	bool operator >=(const  cfsec::CFSecTSecGroupHBuff& lhs, const cfsec::CFSecTSecGroupByTenantIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecTSecGroupHBuff& lhs, const cfsec::CFSecTSecGroupByTenantVisIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecTSecGroupHBuff& lhs, const cfsec::CFSecTSecGroupByUNameIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecTSecGroupHBuff& lhs, const cfsec::CFSecTSecGroupPKey& rhs );
	bool operator >=(const  cfsec::CFSecTSecGroupHBuff& lhs, const cfsec::CFSecTSecGroupHPKey& rhs );
	bool operator >=(const  cfsec::CFSecTSecGroupHBuff& lhs, const cfsec::CFSecTSecGroupHBuff& rhs );
	bool operator >=(const  cfsec::CFSecTSecGroupHBuff& lhs, const cfsec::CFSecTSecGroupBuff& rhs );

	bool operator >(const  cfsec::CFSecTSecGroupHBuff& lhs, const cfsec::CFSecTSecGroupByTenantIdxKey& rhs );
	bool operator >(const  cfsec::CFSecTSecGroupHBuff& lhs, const cfsec::CFSecTSecGroupByTenantVisIdxKey& rhs );
	bool operator >(const  cfsec::CFSecTSecGroupHBuff& lhs, const cfsec::CFSecTSecGroupByUNameIdxKey& rhs );
	bool operator >(const  cfsec::CFSecTSecGroupHBuff& lhs, const cfsec::CFSecTSecGroupPKey& rhs );
	bool operator >(const  cfsec::CFSecTSecGroupHBuff& lhs, const cfsec::CFSecTSecGroupHPKey& rhs );
	bool operator >(const  cfsec::CFSecTSecGroupHBuff& lhs, const cfsec::CFSecTSecGroupHBuff& rhs );
	bool operator >(const  cfsec::CFSecTSecGroupHBuff& lhs, const cfsec::CFSecTSecGroupBuff& rhs );

	template<> struct hash<cfsec::CFSecTSecGroupHBuff> {
		typedef cfsec::CFSecTSecGroupHBuff argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

