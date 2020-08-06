#pragma once

// Description: C++18 specification for a SecGrpMemb buffer object.

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

	class CFSecSecGrpMembPKey;
	class CFSecSecGrpMembHPKey;
	class CFSecSecGrpMembHBuff;
	class CFSecSecGrpMembByClusterIdxKey;
	class CFSecSecGrpMembByGroupIdxKey;
	class CFSecSecGrpMembByUserIdxKey;
	class CFSecSecGrpMembByUUserIdxKey;

	class CFSecSecGrpMembBuff : public cflib::ICFLibCloneableObj
	{
	public:
		static const std::string GENDEFNAME;
		static const classcode_t CLASS_CODE;
		static const std::string CLASS_NAME;
		static const std::string COLNAME_CLUSTERID;
		static const std::string COLNAME_SECGRPMEMBID;
		static const std::string COLNAME_SECGROUPID;
		static const std::string COLNAME_SECUSERID;
		static const char* S_INIT_CREATEDBY;
		static const char* S_INIT_UPDATEDBY;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;
		static const int64_t CLUSTERID_INIT_VALUE;
		static const int64_t SECGRPMEMBID_INIT_VALUE;
		static const int SECGROUPID_INIT_VALUE;
		static const int64_t CLUSTERID_MIN_VALUE;
		static const int64_t SECGRPMEMBID_MIN_VALUE;
		static const int SECGROUPID_MIN_VALUE;
	protected:
		uuid_t createdByUserId;
		std::chrono::system_clock::time_point createdAt;
		uuid_t updatedByUserId;
		std::chrono::system_clock::time_point updatedAt;
		int64_t requiredClusterId;
		int64_t requiredSecGrpMembId;
		int32_t requiredSecGroupId;
		uuid_t requiredSecUserId;
		int32_t requiredRevision;
	public:
		CFSecSecGrpMembBuff();

		CFSecSecGrpMembBuff( const CFSecSecGrpMembBuff& src );

		virtual ~CFSecSecGrpMembBuff();

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
		virtual const int64_t getRequiredClusterId() const;
		virtual const int64_t* getRequiredClusterIdReference() const;
		virtual void setRequiredClusterId( const int64_t value );

		virtual const int64_t getRequiredSecGrpMembId() const;
		virtual const int64_t* getRequiredSecGrpMembIdReference() const;
		virtual void setRequiredSecGrpMembId( const int64_t value );

		virtual const int32_t getRequiredSecGroupId() const;
		virtual const int32_t* getRequiredSecGroupIdReference() const;
		virtual void setRequiredSecGroupId( const int32_t value );

		virtual const uuid_ptr_t getRequiredSecUserId() const;
		virtual const uuid_ptr_t getRequiredSecUserIdReference() const;
		virtual void setRequiredSecUserId( const uuid_ptr_t value );
		virtual void generateRequiredSecUserId();

		virtual int32_t getRequiredRevision() const;
		virtual void setRequiredRevision( int32_t value );

		virtual size_t hashCode() const;

		bool operator <( const CFSecSecGrpMembByClusterIdxKey& rhs );
		bool operator <( const CFSecSecGrpMembByGroupIdxKey& rhs );
		bool operator <( const CFSecSecGrpMembByUserIdxKey& rhs );
		bool operator <( const CFSecSecGrpMembByUUserIdxKey& rhs );
		bool operator <( const CFSecSecGrpMembPKey& rhs );
		bool operator <( const CFSecSecGrpMembHPKey& rhs );
		bool operator <( const CFSecSecGrpMembHBuff& rhs );
		bool operator <( const CFSecSecGrpMembBuff& rhs );

		bool operator <=( const CFSecSecGrpMembByClusterIdxKey& rhs );
		bool operator <=( const CFSecSecGrpMembByGroupIdxKey& rhs );
		bool operator <=( const CFSecSecGrpMembByUserIdxKey& rhs );
		bool operator <=( const CFSecSecGrpMembByUUserIdxKey& rhs );
		bool operator <=( const CFSecSecGrpMembPKey& rhs );
		bool operator <=( const CFSecSecGrpMembHPKey& rhs );
		bool operator <=( const CFSecSecGrpMembHBuff& rhs );
		bool operator <=( const CFSecSecGrpMembBuff& rhs );

		bool operator ==( const CFSecSecGrpMembByClusterIdxKey& rhs );
		bool operator ==( const CFSecSecGrpMembByGroupIdxKey& rhs );
		bool operator ==( const CFSecSecGrpMembByUserIdxKey& rhs );
		bool operator ==( const CFSecSecGrpMembByUUserIdxKey& rhs );
		bool operator ==( const CFSecSecGrpMembPKey& rhs );
		bool operator ==( const CFSecSecGrpMembHPKey& rhs );
		bool operator ==( const CFSecSecGrpMembHBuff& rhs );
		bool operator ==( const CFSecSecGrpMembBuff& rhs );

		bool operator !=( const CFSecSecGrpMembByClusterIdxKey& rhs );
		bool operator !=( const CFSecSecGrpMembByGroupIdxKey& rhs );
		bool operator !=( const CFSecSecGrpMembByUserIdxKey& rhs );
		bool operator !=( const CFSecSecGrpMembByUUserIdxKey& rhs );
		bool operator !=( const CFSecSecGrpMembPKey& rhs );
		bool operator !=( const CFSecSecGrpMembHPKey& rhs );
		bool operator !=( const CFSecSecGrpMembHBuff& rhs );
		bool operator !=( const CFSecSecGrpMembBuff& rhs );

		bool operator >=( const CFSecSecGrpMembByClusterIdxKey& rhs );
		bool operator >=( const CFSecSecGrpMembByGroupIdxKey& rhs );
		bool operator >=( const CFSecSecGrpMembByUserIdxKey& rhs );
		bool operator >=( const CFSecSecGrpMembByUUserIdxKey& rhs );
		bool operator >=( const CFSecSecGrpMembPKey& rhs );
		bool operator >=( const CFSecSecGrpMembHPKey& rhs );
		bool operator >=( const CFSecSecGrpMembHBuff& rhs );
		bool operator >=( const CFSecSecGrpMembBuff& rhs );

		bool operator >( const CFSecSecGrpMembByClusterIdxKey& rhs );
		bool operator >( const CFSecSecGrpMembByGroupIdxKey& rhs );
		bool operator >( const CFSecSecGrpMembByUserIdxKey& rhs );
		bool operator >( const CFSecSecGrpMembByUUserIdxKey& rhs );
		bool operator >( const CFSecSecGrpMembPKey& rhs );
		bool operator >( const CFSecSecGrpMembHPKey& rhs );
		bool operator >( const CFSecSecGrpMembHBuff& rhs );
		bool operator >( const CFSecSecGrpMembBuff& rhs );
		cfsec::CFSecSecGrpMembBuff operator =( cfsec::CFSecSecGrpMembBuff& src );
		cfsec::CFSecSecGrpMembBuff operator =( cfsec::CFSecSecGrpMembHBuff& src );

		virtual std::string toString();
	};
}

namespace std {

	bool operator <(const  cfsec::CFSecSecGrpMembBuff& lhs, const cfsec::CFSecSecGrpMembByClusterIdxKey& rhs );
	bool operator <(const  cfsec::CFSecSecGrpMembBuff& lhs, const cfsec::CFSecSecGrpMembByGroupIdxKey& rhs );
	bool operator <(const  cfsec::CFSecSecGrpMembBuff& lhs, const cfsec::CFSecSecGrpMembByUserIdxKey& rhs );
	bool operator <(const  cfsec::CFSecSecGrpMembBuff& lhs, const cfsec::CFSecSecGrpMembByUUserIdxKey& rhs );
	bool operator <(const  cfsec::CFSecSecGrpMembBuff& lhs, const cfsec::CFSecSecGrpMembPKey& rhs );
	bool operator <(const  cfsec::CFSecSecGrpMembBuff& lhs, const cfsec::CFSecSecGrpMembHPKey& rhs );
	bool operator <(const  cfsec::CFSecSecGrpMembBuff& lhs, const cfsec::CFSecSecGrpMembHBuff& rhs );
	bool operator <(const  cfsec::CFSecSecGrpMembBuff& lhs, const cfsec::CFSecSecGrpMembBuff& rhs );

	bool operator <=(const  cfsec::CFSecSecGrpMembBuff& lhs, const cfsec::CFSecSecGrpMembByClusterIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecSecGrpMembBuff& lhs, const cfsec::CFSecSecGrpMembByGroupIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecSecGrpMembBuff& lhs, const cfsec::CFSecSecGrpMembByUserIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecSecGrpMembBuff& lhs, const cfsec::CFSecSecGrpMembByUUserIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecSecGrpMembBuff& lhs, const cfsec::CFSecSecGrpMembPKey& rhs );
	bool operator <=(const  cfsec::CFSecSecGrpMembBuff& lhs, const cfsec::CFSecSecGrpMembHPKey& rhs );
	bool operator <=(const  cfsec::CFSecSecGrpMembBuff& lhs, const cfsec::CFSecSecGrpMembHBuff& rhs );
	bool operator <=(const  cfsec::CFSecSecGrpMembBuff& lhs, const cfsec::CFSecSecGrpMembBuff& rhs );

	bool operator ==(const  cfsec::CFSecSecGrpMembBuff& lhs, const cfsec::CFSecSecGrpMembByClusterIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecSecGrpMembBuff& lhs, const cfsec::CFSecSecGrpMembByGroupIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecSecGrpMembBuff& lhs, const cfsec::CFSecSecGrpMembByUserIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecSecGrpMembBuff& lhs, const cfsec::CFSecSecGrpMembByUUserIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecSecGrpMembBuff& lhs, const cfsec::CFSecSecGrpMembPKey& rhs );
	bool operator ==(const  cfsec::CFSecSecGrpMembBuff& lhs, const cfsec::CFSecSecGrpMembHPKey& rhs );
	bool operator ==(const  cfsec::CFSecSecGrpMembBuff& lhs, const cfsec::CFSecSecGrpMembHBuff& rhs );
	bool operator ==(const  cfsec::CFSecSecGrpMembBuff& lhs, const cfsec::CFSecSecGrpMembBuff& rhs );

	bool operator !=(const  cfsec::CFSecSecGrpMembBuff& lhs, const cfsec::CFSecSecGrpMembByClusterIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecSecGrpMembBuff& lhs, const cfsec::CFSecSecGrpMembByGroupIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecSecGrpMembBuff& lhs, const cfsec::CFSecSecGrpMembByUserIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecSecGrpMembBuff& lhs, const cfsec::CFSecSecGrpMembByUUserIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecSecGrpMembBuff& lhs, const cfsec::CFSecSecGrpMembPKey& rhs );
	bool operator !=(const  cfsec::CFSecSecGrpMembBuff& lhs, const cfsec::CFSecSecGrpMembHPKey& rhs );
	bool operator !=(const  cfsec::CFSecSecGrpMembBuff& lhs, const cfsec::CFSecSecGrpMembHBuff& rhs );
	bool operator !=(const  cfsec::CFSecSecGrpMembBuff& lhs, const cfsec::CFSecSecGrpMembBuff& rhs );

	bool operator >=(const  cfsec::CFSecSecGrpMembBuff& lhs, const cfsec::CFSecSecGrpMembByClusterIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecSecGrpMembBuff& lhs, const cfsec::CFSecSecGrpMembByGroupIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecSecGrpMembBuff& lhs, const cfsec::CFSecSecGrpMembByUserIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecSecGrpMembBuff& lhs, const cfsec::CFSecSecGrpMembByUUserIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecSecGrpMembBuff& lhs, const cfsec::CFSecSecGrpMembPKey& rhs );
	bool operator >=(const  cfsec::CFSecSecGrpMembBuff& lhs, const cfsec::CFSecSecGrpMembHPKey& rhs );
	bool operator >=(const  cfsec::CFSecSecGrpMembBuff& lhs, const cfsec::CFSecSecGrpMembHBuff& rhs );
	bool operator >=(const  cfsec::CFSecSecGrpMembBuff& lhs, const cfsec::CFSecSecGrpMembBuff& rhs );

	bool operator >(const  cfsec::CFSecSecGrpMembBuff& lhs, const cfsec::CFSecSecGrpMembByClusterIdxKey& rhs );

	bool operator >(const  cfsec::CFSecSecGrpMembBuff& lhs, const cfsec::CFSecSecGrpMembByGroupIdxKey& rhs );

	bool operator >(const  cfsec::CFSecSecGrpMembBuff& lhs, const cfsec::CFSecSecGrpMembByUserIdxKey& rhs );

	bool operator >(const  cfsec::CFSecSecGrpMembBuff& lhs, const cfsec::CFSecSecGrpMembByUUserIdxKey& rhs );

	bool operator >(const  cfsec::CFSecSecGrpMembBuff& lhs, const cfsec::CFSecSecGrpMembPKey& rhs );
	bool operator >(const  cfsec::CFSecSecGrpMembBuff& lhs, const cfsec::CFSecSecGrpMembHPKey& rhs );
	bool operator >(const  cfsec::CFSecSecGrpMembBuff& lhs, const cfsec::CFSecSecGrpMembHBuff& rhs );
	bool operator >(const  cfsec::CFSecSecGrpMembBuff& lhs, const cfsec::CFSecSecGrpMembBuff& rhs );

	template<> struct hash<cfsec::CFSecSecGrpMembBuff> {
		typedef cfsec::CFSecSecGrpMembBuff argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

