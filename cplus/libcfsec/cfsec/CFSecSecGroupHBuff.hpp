#pragma once

// Description: C++18 specification of a SecGroup history buffer object.

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

	class CFSecSecGroupBuff;
	class CFSecSecGroupPKey;
	class CFSecSecGroupHPKey;
	class CFSecSecGroupByClusterIdxKey;
	class CFSecSecGroupByClusterVisIdxKey;
	class CFSecSecGroupByUNameIdxKey;

	class CFSecSecGroupHBuff : public CFSecHPKey, public cflib::ICFLibCloneableObj
	{
	public:
		static const std::string CLASS_NAME;
	protected:
		int64_t requiredClusterId;
		int32_t requiredSecGroupId;
		std::string* requiredName;
		bool requiredIsVisible;		classcode_t classCode;

	public:
		CFSecSecGroupHBuff();
		CFSecSecGroupHBuff( const CFSecSecGroupHBuff& src );
		virtual ~CFSecSecGroupHBuff();

		virtual cflib::ICFLibCloneableObj* clone();
		virtual const int64_t getRequiredClusterId() const;
		virtual const int64_t* getRequiredClusterIdReference() const;
		virtual void setRequiredClusterId( const int64_t value );

		virtual const int32_t getRequiredSecGroupId() const;
		virtual const int32_t* getRequiredSecGroupIdReference() const;
		virtual void setRequiredSecGroupId( const int32_t value );

		virtual const std::string& getRequiredName() const;
		virtual const std::string* getRequiredNameReference() const;
		virtual void setRequiredName( const std::string& value );

		virtual const bool getRequiredIsVisible() const;
		virtual const bool* getRequiredIsVisibleReference() const;
		virtual void setRequiredIsVisible( const bool value );

		virtual size_t hashCode() const;

		bool operator <( const CFSecSecGroupByClusterIdxKey& rhs );
		bool operator <( const CFSecSecGroupByClusterVisIdxKey& rhs );
		bool operator <( const CFSecSecGroupByUNameIdxKey& rhs );
		bool operator <( const CFSecSecGroupPKey& rhs );
		bool operator <( const CFSecSecGroupHPKey& rhs );
		bool operator <( const CFSecSecGroupHBuff& rhs );
		bool operator <( const CFSecSecGroupBuff& rhs );

		bool operator <=( const CFSecSecGroupByClusterIdxKey& rhs );
		bool operator <=( const CFSecSecGroupByClusterVisIdxKey& rhs );
		bool operator <=( const CFSecSecGroupByUNameIdxKey& rhs );
		bool operator <=( const CFSecSecGroupPKey& rhs );
		bool operator <=( const CFSecSecGroupHPKey& rhs );
		bool operator <=( const CFSecSecGroupHBuff& rhs );
		bool operator <=( const CFSecSecGroupBuff& rhs );

		bool operator ==( const CFSecSecGroupByClusterIdxKey& rhs );
		bool operator ==( const CFSecSecGroupByClusterVisIdxKey& rhs );
		bool operator ==( const CFSecSecGroupByUNameIdxKey& rhs );
		bool operator ==( const CFSecSecGroupPKey& rhs );
		bool operator ==( const CFSecSecGroupHPKey& rhs );
		bool operator ==( const CFSecSecGroupHBuff& rhs );
		bool operator ==( const CFSecSecGroupBuff& rhs );

		bool operator !=( const CFSecSecGroupByClusterIdxKey& rhs );
		bool operator !=( const CFSecSecGroupByClusterVisIdxKey& rhs );
		bool operator !=( const CFSecSecGroupByUNameIdxKey& rhs );
		bool operator !=( const CFSecSecGroupPKey& rhs );
		bool operator !=( const CFSecSecGroupHPKey& rhs );
		bool operator !=( const CFSecSecGroupHBuff& rhs );
		bool operator !=( const CFSecSecGroupBuff& rhs );

		bool operator >=( const CFSecSecGroupByClusterIdxKey& rhs );
		bool operator >=( const CFSecSecGroupByClusterVisIdxKey& rhs );
		bool operator >=( const CFSecSecGroupByUNameIdxKey& rhs );
		bool operator >=( const CFSecSecGroupPKey& rhs );
		bool operator >=( const CFSecSecGroupHPKey& rhs );
		bool operator >=( const CFSecSecGroupHBuff& rhs );
		bool operator >=( const CFSecSecGroupBuff& rhs );

		bool operator >( const CFSecSecGroupByClusterIdxKey& rhs );
		bool operator >( const CFSecSecGroupByClusterVisIdxKey& rhs );
		bool operator >( const CFSecSecGroupByUNameIdxKey& rhs );
		bool operator >( const CFSecSecGroupPKey& rhs );
		bool operator >( const CFSecSecGroupHPKey& rhs );
		bool operator >( const CFSecSecGroupHBuff& rhs );
		bool operator >( const CFSecSecGroupBuff& rhs );
		cfsec::CFSecSecGroupHBuff operator =( cfsec::CFSecSecGroupBuff& src );
		cfsec::CFSecSecGroupHBuff operator =( cfsec::CFSecSecGroupHBuff& src );

		virtual std::string toString();

	};
}

namespace std {

	bool operator <(const  cfsec::CFSecSecGroupHBuff& lhs, const cfsec::CFSecSecGroupByClusterIdxKey& rhs );
	bool operator <(const  cfsec::CFSecSecGroupHBuff& lhs, const cfsec::CFSecSecGroupByClusterVisIdxKey& rhs );
	bool operator <(const  cfsec::CFSecSecGroupHBuff& lhs, const cfsec::CFSecSecGroupByUNameIdxKey& rhs );
	bool operator <(const  cfsec::CFSecSecGroupHBuff& lhs, const cfsec::CFSecSecGroupPKey& rhs );
	bool operator <(const  cfsec::CFSecSecGroupHBuff& lhs, const cfsec::CFSecSecGroupHPKey& rhs );
	bool operator <(const  cfsec::CFSecSecGroupHBuff& lhs, const cfsec::CFSecSecGroupHBuff& rhs );
	bool operator <(const  cfsec::CFSecSecGroupHBuff& lhs, const cfsec::CFSecSecGroupBuff& rhs );

	bool operator <=(const  cfsec::CFSecSecGroupHBuff& lhs, const cfsec::CFSecSecGroupByClusterIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecSecGroupHBuff& lhs, const cfsec::CFSecSecGroupByClusterVisIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecSecGroupHBuff& lhs, const cfsec::CFSecSecGroupByUNameIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecSecGroupHBuff& lhs, const cfsec::CFSecSecGroupPKey& rhs );
	bool operator <=(const  cfsec::CFSecSecGroupHBuff& lhs, const cfsec::CFSecSecGroupHPKey& rhs );
	bool operator <=(const  cfsec::CFSecSecGroupHBuff& lhs, const cfsec::CFSecSecGroupHBuff& rhs );
	bool operator <=(const  cfsec::CFSecSecGroupHBuff& lhs, const cfsec::CFSecSecGroupBuff& rhs );

	bool operator ==(const  cfsec::CFSecSecGroupHBuff& lhs, const cfsec::CFSecSecGroupByClusterIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecSecGroupHBuff& lhs, const cfsec::CFSecSecGroupByClusterVisIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecSecGroupHBuff& lhs, const cfsec::CFSecSecGroupByUNameIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecSecGroupHBuff& lhs, const cfsec::CFSecSecGroupPKey& rhs );
	bool operator ==(const  cfsec::CFSecSecGroupHBuff& lhs, const cfsec::CFSecSecGroupHPKey& rhs );
	bool operator ==(const  cfsec::CFSecSecGroupHBuff& lhs, const cfsec::CFSecSecGroupHBuff& rhs );
	bool operator ==(const  cfsec::CFSecSecGroupHBuff& lhs, const cfsec::CFSecSecGroupBuff& rhs );

	bool operator !=(const  cfsec::CFSecSecGroupHBuff& lhs, const cfsec::CFSecSecGroupByClusterIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecSecGroupHBuff& lhs, const cfsec::CFSecSecGroupByClusterVisIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecSecGroupHBuff& lhs, const cfsec::CFSecSecGroupByUNameIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecSecGroupHBuff& lhs, const cfsec::CFSecSecGroupPKey& rhs );
	bool operator !=(const  cfsec::CFSecSecGroupHBuff& lhs, const cfsec::CFSecSecGroupHPKey& rhs );
	bool operator !=(const  cfsec::CFSecSecGroupHBuff& lhs, const cfsec::CFSecSecGroupHBuff& rhs );
	bool operator !=(const  cfsec::CFSecSecGroupHBuff& lhs, const cfsec::CFSecSecGroupBuff& rhs );

	bool operator >=(const  cfsec::CFSecSecGroupHBuff& lhs, const cfsec::CFSecSecGroupByClusterIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecSecGroupHBuff& lhs, const cfsec::CFSecSecGroupByClusterVisIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecSecGroupHBuff& lhs, const cfsec::CFSecSecGroupByUNameIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecSecGroupHBuff& lhs, const cfsec::CFSecSecGroupPKey& rhs );
	bool operator >=(const  cfsec::CFSecSecGroupHBuff& lhs, const cfsec::CFSecSecGroupHPKey& rhs );
	bool operator >=(const  cfsec::CFSecSecGroupHBuff& lhs, const cfsec::CFSecSecGroupHBuff& rhs );
	bool operator >=(const  cfsec::CFSecSecGroupHBuff& lhs, const cfsec::CFSecSecGroupBuff& rhs );

	bool operator >(const  cfsec::CFSecSecGroupHBuff& lhs, const cfsec::CFSecSecGroupByClusterIdxKey& rhs );
	bool operator >(const  cfsec::CFSecSecGroupHBuff& lhs, const cfsec::CFSecSecGroupByClusterVisIdxKey& rhs );
	bool operator >(const  cfsec::CFSecSecGroupHBuff& lhs, const cfsec::CFSecSecGroupByUNameIdxKey& rhs );
	bool operator >(const  cfsec::CFSecSecGroupHBuff& lhs, const cfsec::CFSecSecGroupPKey& rhs );
	bool operator >(const  cfsec::CFSecSecGroupHBuff& lhs, const cfsec::CFSecSecGroupHPKey& rhs );
	bool operator >(const  cfsec::CFSecSecGroupHBuff& lhs, const cfsec::CFSecSecGroupHBuff& rhs );
	bool operator >(const  cfsec::CFSecSecGroupHBuff& lhs, const cfsec::CFSecSecGroupBuff& rhs );

	template<> struct hash<cfsec::CFSecSecGroupHBuff> {
		typedef cfsec::CFSecSecGroupHBuff argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}
