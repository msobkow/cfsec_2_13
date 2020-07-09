#pragma once

// Description: C++18 specification of a SecGroupForm history buffer object.

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

	class CFSecSecGroupFormBuff;
	class CFSecSecGroupFormPKey;
	class CFSecSecGroupFormHPKey;
	class CFSecSecGroupFormByClusterIdxKey;
	class CFSecSecGroupFormByGroupIdxKey;
	class CFSecSecGroupFormByAppIdxKey;
	class CFSecSecGroupFormByFormIdxKey;
	class CFSecSecGroupFormByUFormIdxKey;

	class CFSecSecGroupFormHBuff : public CFSecHPKey, public cflib::ICFLibCloneableObj
	{
	public:
		static const std::string CLASS_NAME;
	protected:
		int64_t requiredClusterId;
		int64_t requiredSecGroupFormId;
		int32_t requiredSecGroupId;
		int32_t requiredSecAppId;
		int32_t requiredSecFormId;		classcode_t classCode;

	public:
		CFSecSecGroupFormHBuff();
		CFSecSecGroupFormHBuff( const CFSecSecGroupFormHBuff& src );
		virtual ~CFSecSecGroupFormHBuff();

		virtual cflib::ICFLibCloneableObj* clone();
		virtual const int64_t getRequiredClusterId() const;
		virtual const int64_t* getRequiredClusterIdReference() const;
		virtual void setRequiredClusterId( const int64_t value );

		virtual const int64_t getRequiredSecGroupFormId() const;
		virtual const int64_t* getRequiredSecGroupFormIdReference() const;
		virtual void setRequiredSecGroupFormId( const int64_t value );

		virtual const int32_t getRequiredSecGroupId() const;
		virtual const int32_t* getRequiredSecGroupIdReference() const;
		virtual void setRequiredSecGroupId( const int32_t value );

		virtual const int32_t getRequiredSecAppId() const;
		virtual const int32_t* getRequiredSecAppIdReference() const;
		virtual void setRequiredSecAppId( const int32_t value );

		virtual const int32_t getRequiredSecFormId() const;
		virtual const int32_t* getRequiredSecFormIdReference() const;
		virtual void setRequiredSecFormId( const int32_t value );

		virtual size_t hashCode() const;

		bool operator <( const CFSecSecGroupFormByClusterIdxKey& rhs );
		bool operator <( const CFSecSecGroupFormByGroupIdxKey& rhs );
		bool operator <( const CFSecSecGroupFormByAppIdxKey& rhs );
		bool operator <( const CFSecSecGroupFormByFormIdxKey& rhs );
		bool operator <( const CFSecSecGroupFormByUFormIdxKey& rhs );
		bool operator <( const CFSecSecGroupFormPKey& rhs );
		bool operator <( const CFSecSecGroupFormHPKey& rhs );
		bool operator <( const CFSecSecGroupFormHBuff& rhs );
		bool operator <( const CFSecSecGroupFormBuff& rhs );

		bool operator <=( const CFSecSecGroupFormByClusterIdxKey& rhs );
		bool operator <=( const CFSecSecGroupFormByGroupIdxKey& rhs );
		bool operator <=( const CFSecSecGroupFormByAppIdxKey& rhs );
		bool operator <=( const CFSecSecGroupFormByFormIdxKey& rhs );
		bool operator <=( const CFSecSecGroupFormByUFormIdxKey& rhs );
		bool operator <=( const CFSecSecGroupFormPKey& rhs );
		bool operator <=( const CFSecSecGroupFormHPKey& rhs );
		bool operator <=( const CFSecSecGroupFormHBuff& rhs );
		bool operator <=( const CFSecSecGroupFormBuff& rhs );

		bool operator ==( const CFSecSecGroupFormByClusterIdxKey& rhs );
		bool operator ==( const CFSecSecGroupFormByGroupIdxKey& rhs );
		bool operator ==( const CFSecSecGroupFormByAppIdxKey& rhs );
		bool operator ==( const CFSecSecGroupFormByFormIdxKey& rhs );
		bool operator ==( const CFSecSecGroupFormByUFormIdxKey& rhs );
		bool operator ==( const CFSecSecGroupFormPKey& rhs );
		bool operator ==( const CFSecSecGroupFormHPKey& rhs );
		bool operator ==( const CFSecSecGroupFormHBuff& rhs );
		bool operator ==( const CFSecSecGroupFormBuff& rhs );

		bool operator !=( const CFSecSecGroupFormByClusterIdxKey& rhs );
		bool operator !=( const CFSecSecGroupFormByGroupIdxKey& rhs );
		bool operator !=( const CFSecSecGroupFormByAppIdxKey& rhs );
		bool operator !=( const CFSecSecGroupFormByFormIdxKey& rhs );
		bool operator !=( const CFSecSecGroupFormByUFormIdxKey& rhs );
		bool operator !=( const CFSecSecGroupFormPKey& rhs );
		bool operator !=( const CFSecSecGroupFormHPKey& rhs );
		bool operator !=( const CFSecSecGroupFormHBuff& rhs );
		bool operator !=( const CFSecSecGroupFormBuff& rhs );

		bool operator >=( const CFSecSecGroupFormByClusterIdxKey& rhs );
		bool operator >=( const CFSecSecGroupFormByGroupIdxKey& rhs );
		bool operator >=( const CFSecSecGroupFormByAppIdxKey& rhs );
		bool operator >=( const CFSecSecGroupFormByFormIdxKey& rhs );
		bool operator >=( const CFSecSecGroupFormByUFormIdxKey& rhs );
		bool operator >=( const CFSecSecGroupFormPKey& rhs );
		bool operator >=( const CFSecSecGroupFormHPKey& rhs );
		bool operator >=( const CFSecSecGroupFormHBuff& rhs );
		bool operator >=( const CFSecSecGroupFormBuff& rhs );

		bool operator >( const CFSecSecGroupFormByClusterIdxKey& rhs );
		bool operator >( const CFSecSecGroupFormByGroupIdxKey& rhs );
		bool operator >( const CFSecSecGroupFormByAppIdxKey& rhs );
		bool operator >( const CFSecSecGroupFormByFormIdxKey& rhs );
		bool operator >( const CFSecSecGroupFormByUFormIdxKey& rhs );
		bool operator >( const CFSecSecGroupFormPKey& rhs );
		bool operator >( const CFSecSecGroupFormHPKey& rhs );
		bool operator >( const CFSecSecGroupFormHBuff& rhs );
		bool operator >( const CFSecSecGroupFormBuff& rhs );
		cfsec::CFSecSecGroupFormHBuff operator =( cfsec::CFSecSecGroupFormBuff& src );
		cfsec::CFSecSecGroupFormHBuff operator =( cfsec::CFSecSecGroupFormHBuff& src );

		virtual std::string toString();

	};
}

namespace std {

	bool operator <(const  cfsec::CFSecSecGroupFormHBuff& lhs, const cfsec::CFSecSecGroupFormByClusterIdxKey& rhs );
	bool operator <(const  cfsec::CFSecSecGroupFormHBuff& lhs, const cfsec::CFSecSecGroupFormByGroupIdxKey& rhs );
	bool operator <(const  cfsec::CFSecSecGroupFormHBuff& lhs, const cfsec::CFSecSecGroupFormByAppIdxKey& rhs );
	bool operator <(const  cfsec::CFSecSecGroupFormHBuff& lhs, const cfsec::CFSecSecGroupFormByFormIdxKey& rhs );
	bool operator <(const  cfsec::CFSecSecGroupFormHBuff& lhs, const cfsec::CFSecSecGroupFormByUFormIdxKey& rhs );
	bool operator <(const  cfsec::CFSecSecGroupFormHBuff& lhs, const cfsec::CFSecSecGroupFormPKey& rhs );
	bool operator <(const  cfsec::CFSecSecGroupFormHBuff& lhs, const cfsec::CFSecSecGroupFormHPKey& rhs );
	bool operator <(const  cfsec::CFSecSecGroupFormHBuff& lhs, const cfsec::CFSecSecGroupFormHBuff& rhs );
	bool operator <(const  cfsec::CFSecSecGroupFormHBuff& lhs, const cfsec::CFSecSecGroupFormBuff& rhs );

	bool operator <=(const  cfsec::CFSecSecGroupFormHBuff& lhs, const cfsec::CFSecSecGroupFormByClusterIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecSecGroupFormHBuff& lhs, const cfsec::CFSecSecGroupFormByGroupIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecSecGroupFormHBuff& lhs, const cfsec::CFSecSecGroupFormByAppIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecSecGroupFormHBuff& lhs, const cfsec::CFSecSecGroupFormByFormIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecSecGroupFormHBuff& lhs, const cfsec::CFSecSecGroupFormByUFormIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecSecGroupFormHBuff& lhs, const cfsec::CFSecSecGroupFormPKey& rhs );
	bool operator <=(const  cfsec::CFSecSecGroupFormHBuff& lhs, const cfsec::CFSecSecGroupFormHPKey& rhs );
	bool operator <=(const  cfsec::CFSecSecGroupFormHBuff& lhs, const cfsec::CFSecSecGroupFormHBuff& rhs );
	bool operator <=(const  cfsec::CFSecSecGroupFormHBuff& lhs, const cfsec::CFSecSecGroupFormBuff& rhs );

	bool operator ==(const  cfsec::CFSecSecGroupFormHBuff& lhs, const cfsec::CFSecSecGroupFormByClusterIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecSecGroupFormHBuff& lhs, const cfsec::CFSecSecGroupFormByGroupIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecSecGroupFormHBuff& lhs, const cfsec::CFSecSecGroupFormByAppIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecSecGroupFormHBuff& lhs, const cfsec::CFSecSecGroupFormByFormIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecSecGroupFormHBuff& lhs, const cfsec::CFSecSecGroupFormByUFormIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecSecGroupFormHBuff& lhs, const cfsec::CFSecSecGroupFormPKey& rhs );
	bool operator ==(const  cfsec::CFSecSecGroupFormHBuff& lhs, const cfsec::CFSecSecGroupFormHPKey& rhs );
	bool operator ==(const  cfsec::CFSecSecGroupFormHBuff& lhs, const cfsec::CFSecSecGroupFormHBuff& rhs );
	bool operator ==(const  cfsec::CFSecSecGroupFormHBuff& lhs, const cfsec::CFSecSecGroupFormBuff& rhs );

	bool operator !=(const  cfsec::CFSecSecGroupFormHBuff& lhs, const cfsec::CFSecSecGroupFormByClusterIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecSecGroupFormHBuff& lhs, const cfsec::CFSecSecGroupFormByGroupIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecSecGroupFormHBuff& lhs, const cfsec::CFSecSecGroupFormByAppIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecSecGroupFormHBuff& lhs, const cfsec::CFSecSecGroupFormByFormIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecSecGroupFormHBuff& lhs, const cfsec::CFSecSecGroupFormByUFormIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecSecGroupFormHBuff& lhs, const cfsec::CFSecSecGroupFormPKey& rhs );
	bool operator !=(const  cfsec::CFSecSecGroupFormHBuff& lhs, const cfsec::CFSecSecGroupFormHPKey& rhs );
	bool operator !=(const  cfsec::CFSecSecGroupFormHBuff& lhs, const cfsec::CFSecSecGroupFormHBuff& rhs );
	bool operator !=(const  cfsec::CFSecSecGroupFormHBuff& lhs, const cfsec::CFSecSecGroupFormBuff& rhs );

	bool operator >=(const  cfsec::CFSecSecGroupFormHBuff& lhs, const cfsec::CFSecSecGroupFormByClusterIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecSecGroupFormHBuff& lhs, const cfsec::CFSecSecGroupFormByGroupIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecSecGroupFormHBuff& lhs, const cfsec::CFSecSecGroupFormByAppIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecSecGroupFormHBuff& lhs, const cfsec::CFSecSecGroupFormByFormIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecSecGroupFormHBuff& lhs, const cfsec::CFSecSecGroupFormByUFormIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecSecGroupFormHBuff& lhs, const cfsec::CFSecSecGroupFormPKey& rhs );
	bool operator >=(const  cfsec::CFSecSecGroupFormHBuff& lhs, const cfsec::CFSecSecGroupFormHPKey& rhs );
	bool operator >=(const  cfsec::CFSecSecGroupFormHBuff& lhs, const cfsec::CFSecSecGroupFormHBuff& rhs );
	bool operator >=(const  cfsec::CFSecSecGroupFormHBuff& lhs, const cfsec::CFSecSecGroupFormBuff& rhs );

	bool operator >(const  cfsec::CFSecSecGroupFormHBuff& lhs, const cfsec::CFSecSecGroupFormByClusterIdxKey& rhs );
	bool operator >(const  cfsec::CFSecSecGroupFormHBuff& lhs, const cfsec::CFSecSecGroupFormByGroupIdxKey& rhs );
	bool operator >(const  cfsec::CFSecSecGroupFormHBuff& lhs, const cfsec::CFSecSecGroupFormByAppIdxKey& rhs );
	bool operator >(const  cfsec::CFSecSecGroupFormHBuff& lhs, const cfsec::CFSecSecGroupFormByFormIdxKey& rhs );
	bool operator >(const  cfsec::CFSecSecGroupFormHBuff& lhs, const cfsec::CFSecSecGroupFormByUFormIdxKey& rhs );
	bool operator >(const  cfsec::CFSecSecGroupFormHBuff& lhs, const cfsec::CFSecSecGroupFormPKey& rhs );
	bool operator >(const  cfsec::CFSecSecGroupFormHBuff& lhs, const cfsec::CFSecSecGroupFormHPKey& rhs );
	bool operator >(const  cfsec::CFSecSecGroupFormHBuff& lhs, const cfsec::CFSecSecGroupFormHBuff& rhs );
	bool operator >(const  cfsec::CFSecSecGroupFormHBuff& lhs, const cfsec::CFSecSecGroupFormBuff& rhs );

	template<> struct hash<cfsec::CFSecSecGroupFormHBuff> {
		typedef cfsec::CFSecSecGroupFormHBuff argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

