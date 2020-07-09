#pragma once

// Description: C++18 specification for a TSecGrpMemb buffer object.

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

	class CFSecTSecGrpMembPKey;
	class CFSecTSecGrpMembHPKey;
	class CFSecTSecGrpMembHBuff;
	class CFSecTSecGrpMembByTenantIdxKey;
	class CFSecTSecGrpMembByGroupIdxKey;
	class CFSecTSecGrpMembByUserIdxKey;
	class CFSecTSecGrpMembByUUserIdxKey;

	class CFSecTSecGrpMembBuff : public cflib::ICFLibCloneableObj
	{
	public:
		static const std::string GENDEFNAME;
		static const classcode_t CLASS_CODE;
		static const std::string CLASS_NAME;
		static const std::string COLNAME_TENANTID;
		static const std::string COLNAME_TSECGRPMEMBID;
		static const std::string COLNAME_TSECGROUPID;
		static const std::string COLNAME_SECUSERID;
		static const char* S_INIT_CREATEDBY;
		static const char* S_INIT_UPDATEDBY;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;
		static const int64_t TENANTID_INIT_VALUE;
		static const int64_t TSECGRPMEMBID_INIT_VALUE;
		static const int TSECGROUPID_INIT_VALUE;
		static const int64_t TENANTID_MIN_VALUE;
		static const int64_t TSECGRPMEMBID_MIN_VALUE;
		static const int TSECGROUPID_MIN_VALUE;
	protected:
		uuid_t createdByUserId;
		std::chrono::system_clock::time_point createdAt;
		uuid_t updatedByUserId;
		std::chrono::system_clock::time_point updatedAt;
		int64_t requiredTenantId;
		int64_t requiredTSecGrpMembId;
		int32_t requiredTSecGroupId;
		uuid_t requiredSecUserId;
		int32_t requiredRevision;
	public:
		CFSecTSecGrpMembBuff();

		CFSecTSecGrpMembBuff( const CFSecTSecGrpMembBuff& src );

		virtual ~CFSecTSecGrpMembBuff();

		virtual const std::string& getClassName() const;
		virtual cflib::ICFLibCloneableObj* clone();
		virtual const classcode_t getClassCode() const;

		virtual bool implementsClassCode( const classcode_t argClassCode );
		virtual const uuid_ptr_t getCreatedByUserId() const;
		virtual void setCreatedByUserId( const uuid_ptr_t value );
		virtual const std::chrono::system_clock::time_point& getCreatedAt() const;
		virtual void setCreatedAt( const std::chrono::system_clock::time_point& value );
		virtual const uuid_ptr_t getUpdatedByUserId() const;
		virtual void setUpdatedByUserId( const uuid_ptr_t value );
		virtual const std::chrono::system_clock::time_point& getUpdatedAt() const;
		virtual void setUpdatedAt( const std::chrono::system_clock::time_point& value );
		virtual const int64_t getRequiredTenantId() const;
		virtual const int64_t* getRequiredTenantIdReference() const;
		virtual void setRequiredTenantId( const int64_t value );

		virtual const int64_t getRequiredTSecGrpMembId() const;
		virtual const int64_t* getRequiredTSecGrpMembIdReference() const;
		virtual void setRequiredTSecGrpMembId( const int64_t value );

		virtual const int32_t getRequiredTSecGroupId() const;
		virtual const int32_t* getRequiredTSecGroupIdReference() const;
		virtual void setRequiredTSecGroupId( const int32_t value );

		virtual const uuid_ptr_t getRequiredSecUserId() const;
		virtual const uuid_ptr_t getRequiredSecUserIdReference() const;
		virtual void setRequiredSecUserId( const uuid_ptr_t value );
		virtual void generateRequiredSecUserId();

		virtual int32_t getRequiredRevision() const;
		virtual void setRequiredRevision( int32_t value );

		virtual size_t hashCode() const;

		bool operator <( const CFSecTSecGrpMembByTenantIdxKey& rhs );
		bool operator <( const CFSecTSecGrpMembByGroupIdxKey& rhs );
		bool operator <( const CFSecTSecGrpMembByUserIdxKey& rhs );
		bool operator <( const CFSecTSecGrpMembByUUserIdxKey& rhs );
		bool operator <( const CFSecTSecGrpMembPKey& rhs );
		bool operator <( const CFSecTSecGrpMembHPKey& rhs );
		bool operator <( const CFSecTSecGrpMembHBuff& rhs );
		bool operator <( const CFSecTSecGrpMembBuff& rhs );

		bool operator <=( const CFSecTSecGrpMembByTenantIdxKey& rhs );
		bool operator <=( const CFSecTSecGrpMembByGroupIdxKey& rhs );
		bool operator <=( const CFSecTSecGrpMembByUserIdxKey& rhs );
		bool operator <=( const CFSecTSecGrpMembByUUserIdxKey& rhs );
		bool operator <=( const CFSecTSecGrpMembPKey& rhs );
		bool operator <=( const CFSecTSecGrpMembHPKey& rhs );
		bool operator <=( const CFSecTSecGrpMembHBuff& rhs );
		bool operator <=( const CFSecTSecGrpMembBuff& rhs );

		bool operator ==( const CFSecTSecGrpMembByTenantIdxKey& rhs );
		bool operator ==( const CFSecTSecGrpMembByGroupIdxKey& rhs );
		bool operator ==( const CFSecTSecGrpMembByUserIdxKey& rhs );
		bool operator ==( const CFSecTSecGrpMembByUUserIdxKey& rhs );
		bool operator ==( const CFSecTSecGrpMembPKey& rhs );
		bool operator ==( const CFSecTSecGrpMembHPKey& rhs );
		bool operator ==( const CFSecTSecGrpMembHBuff& rhs );
		bool operator ==( const CFSecTSecGrpMembBuff& rhs );

		bool operator !=( const CFSecTSecGrpMembByTenantIdxKey& rhs );
		bool operator !=( const CFSecTSecGrpMembByGroupIdxKey& rhs );
		bool operator !=( const CFSecTSecGrpMembByUserIdxKey& rhs );
		bool operator !=( const CFSecTSecGrpMembByUUserIdxKey& rhs );
		bool operator !=( const CFSecTSecGrpMembPKey& rhs );
		bool operator !=( const CFSecTSecGrpMembHPKey& rhs );
		bool operator !=( const CFSecTSecGrpMembHBuff& rhs );
		bool operator !=( const CFSecTSecGrpMembBuff& rhs );

		bool operator >=( const CFSecTSecGrpMembByTenantIdxKey& rhs );
		bool operator >=( const CFSecTSecGrpMembByGroupIdxKey& rhs );
		bool operator >=( const CFSecTSecGrpMembByUserIdxKey& rhs );
		bool operator >=( const CFSecTSecGrpMembByUUserIdxKey& rhs );
		bool operator >=( const CFSecTSecGrpMembPKey& rhs );
		bool operator >=( const CFSecTSecGrpMembHPKey& rhs );
		bool operator >=( const CFSecTSecGrpMembHBuff& rhs );
		bool operator >=( const CFSecTSecGrpMembBuff& rhs );

		bool operator >( const CFSecTSecGrpMembByTenantIdxKey& rhs );
		bool operator >( const CFSecTSecGrpMembByGroupIdxKey& rhs );
		bool operator >( const CFSecTSecGrpMembByUserIdxKey& rhs );
		bool operator >( const CFSecTSecGrpMembByUUserIdxKey& rhs );
		bool operator >( const CFSecTSecGrpMembPKey& rhs );
		bool operator >( const CFSecTSecGrpMembHPKey& rhs );
		bool operator >( const CFSecTSecGrpMembHBuff& rhs );
		bool operator >( const CFSecTSecGrpMembBuff& rhs );
		cfsec::CFSecTSecGrpMembBuff operator =( cfsec::CFSecTSecGrpMembBuff& src );
		cfsec::CFSecTSecGrpMembBuff operator =( cfsec::CFSecTSecGrpMembHBuff& src );

		virtual std::string toString();
	};
}

namespace std {

	bool operator <(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembByTenantIdxKey& rhs );
	bool operator <(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembByGroupIdxKey& rhs );
	bool operator <(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembByUserIdxKey& rhs );
	bool operator <(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembByUUserIdxKey& rhs );
	bool operator <(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembPKey& rhs );
	bool operator <(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembHPKey& rhs );
	bool operator <(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembHBuff& rhs );
	bool operator <(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembBuff& rhs );

	bool operator <=(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembByTenantIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembByGroupIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembByUserIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembByUUserIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembPKey& rhs );
	bool operator <=(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembHPKey& rhs );
	bool operator <=(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembHBuff& rhs );
	bool operator <=(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembBuff& rhs );

	bool operator ==(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembByTenantIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembByGroupIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembByUserIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembByUUserIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembPKey& rhs );
	bool operator ==(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembHPKey& rhs );
	bool operator ==(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembHBuff& rhs );
	bool operator ==(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembBuff& rhs );

	bool operator !=(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembByTenantIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembByGroupIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembByUserIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembByUUserIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembPKey& rhs );
	bool operator !=(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembHPKey& rhs );
	bool operator !=(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembHBuff& rhs );
	bool operator !=(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembBuff& rhs );

	bool operator >=(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembByTenantIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembByGroupIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembByUserIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembByUUserIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembPKey& rhs );
	bool operator >=(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembHPKey& rhs );
	bool operator >=(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembHBuff& rhs );
	bool operator >=(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembBuff& rhs );

	bool operator >(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembByTenantIdxKey& rhs );

	bool operator >(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembByGroupIdxKey& rhs );

	bool operator >(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembByUserIdxKey& rhs );

	bool operator >(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembByUUserIdxKey& rhs );

	bool operator >(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembPKey& rhs );
	bool operator >(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembHPKey& rhs );
	bool operator >(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembHBuff& rhs );
	bool operator >(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembBuff& rhs );

	template<> struct hash<cfsec::CFSecTSecGrpMembBuff> {
		typedef cfsec::CFSecTSecGrpMembBuff argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

