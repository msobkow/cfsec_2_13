#pragma once

// Description: C++18 specification for a SecApp buffer object.

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

	class CFSecSecAppPKey;
	class CFSecSecAppHPKey;
	class CFSecSecAppHBuff;
	class CFSecSecAppByClusterIdxKey;
	class CFSecSecAppByUJEEMountIdxKey;

	class CFSecSecAppBuff : public cflib::ICFLibCloneableObj
	{
	public:
		static const std::string GENDEFNAME;
		static const classcode_t CLASS_CODE;
		static const std::string CLASS_NAME;
		static const std::string COLNAME_CLUSTERID;
		static const std::string COLNAME_SECAPPID;
		static const std::string COLNAME_JEEMOUNTNAME;
		static const char* S_INIT_CREATEDBY;
		static const char* S_INIT_UPDATEDBY;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;
		static const int64_t CLUSTERID_INIT_VALUE;
		static const int SECAPPID_INIT_VALUE;
		static const std::string JEEMOUNTNAME_INIT_VALUE;
		static const int64_t CLUSTERID_MIN_VALUE;
		static const int SECAPPID_MIN_VALUE;
		static const std::string::size_type JEEMOUNTNAME_MAX_LEN;
	protected:
		uuid_t createdByUserId;
		std::chrono::system_clock::time_point createdAt;
		uuid_t updatedByUserId;
		std::chrono::system_clock::time_point updatedAt;
		int64_t requiredClusterId;
		int32_t requiredSecAppId;
		std::string* requiredJEEMountName;
		int32_t requiredRevision;
	public:
		CFSecSecAppBuff();

		CFSecSecAppBuff( const CFSecSecAppBuff& src );

		virtual ~CFSecSecAppBuff();

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

		virtual const int32_t getRequiredSecAppId() const;
		virtual const int32_t* getRequiredSecAppIdReference() const;
		virtual void setRequiredSecAppId( const int32_t value );

		virtual const std::string& getRequiredJEEMountName() const;
		virtual const std::string* getRequiredJEEMountNameReference() const;
		virtual void setRequiredJEEMountName( const std::string& value );

		virtual int32_t getRequiredRevision() const;
		virtual void setRequiredRevision( int32_t value );

		virtual size_t hashCode() const;

		bool operator <( const CFSecSecAppByClusterIdxKey& rhs );
		bool operator <( const CFSecSecAppByUJEEMountIdxKey& rhs );
		bool operator <( const CFSecSecAppPKey& rhs );
		bool operator <( const CFSecSecAppHPKey& rhs );
		bool operator <( const CFSecSecAppHBuff& rhs );
		bool operator <( const CFSecSecAppBuff& rhs );

		bool operator <=( const CFSecSecAppByClusterIdxKey& rhs );
		bool operator <=( const CFSecSecAppByUJEEMountIdxKey& rhs );
		bool operator <=( const CFSecSecAppPKey& rhs );
		bool operator <=( const CFSecSecAppHPKey& rhs );
		bool operator <=( const CFSecSecAppHBuff& rhs );
		bool operator <=( const CFSecSecAppBuff& rhs );

		bool operator ==( const CFSecSecAppByClusterIdxKey& rhs );
		bool operator ==( const CFSecSecAppByUJEEMountIdxKey& rhs );
		bool operator ==( const CFSecSecAppPKey& rhs );
		bool operator ==( const CFSecSecAppHPKey& rhs );
		bool operator ==( const CFSecSecAppHBuff& rhs );
		bool operator ==( const CFSecSecAppBuff& rhs );

		bool operator !=( const CFSecSecAppByClusterIdxKey& rhs );
		bool operator !=( const CFSecSecAppByUJEEMountIdxKey& rhs );
		bool operator !=( const CFSecSecAppPKey& rhs );
		bool operator !=( const CFSecSecAppHPKey& rhs );
		bool operator !=( const CFSecSecAppHBuff& rhs );
		bool operator !=( const CFSecSecAppBuff& rhs );

		bool operator >=( const CFSecSecAppByClusterIdxKey& rhs );
		bool operator >=( const CFSecSecAppByUJEEMountIdxKey& rhs );
		bool operator >=( const CFSecSecAppPKey& rhs );
		bool operator >=( const CFSecSecAppHPKey& rhs );
		bool operator >=( const CFSecSecAppHBuff& rhs );
		bool operator >=( const CFSecSecAppBuff& rhs );

		bool operator >( const CFSecSecAppByClusterIdxKey& rhs );
		bool operator >( const CFSecSecAppByUJEEMountIdxKey& rhs );
		bool operator >( const CFSecSecAppPKey& rhs );
		bool operator >( const CFSecSecAppHPKey& rhs );
		bool operator >( const CFSecSecAppHBuff& rhs );
		bool operator >( const CFSecSecAppBuff& rhs );
		cfsec::CFSecSecAppBuff operator =( cfsec::CFSecSecAppBuff& src );
		cfsec::CFSecSecAppBuff operator =( cfsec::CFSecSecAppHBuff& src );

		virtual std::string toString();
	};
}

namespace std {

	bool operator <(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppByClusterIdxKey& rhs );
	bool operator <(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppByUJEEMountIdxKey& rhs );
	bool operator <(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppPKey& rhs );
	bool operator <(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppHPKey& rhs );
	bool operator <(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppHBuff& rhs );
	bool operator <(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppBuff& rhs );

	bool operator <=(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppByClusterIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppByUJEEMountIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppPKey& rhs );
	bool operator <=(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppHPKey& rhs );
	bool operator <=(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppHBuff& rhs );
	bool operator <=(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppBuff& rhs );

	bool operator ==(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppByClusterIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppByUJEEMountIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppPKey& rhs );
	bool operator ==(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppHPKey& rhs );
	bool operator ==(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppHBuff& rhs );
	bool operator ==(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppBuff& rhs );

	bool operator !=(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppByClusterIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppByUJEEMountIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppPKey& rhs );
	bool operator !=(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppHPKey& rhs );
	bool operator !=(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppHBuff& rhs );
	bool operator !=(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppBuff& rhs );

	bool operator >=(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppByClusterIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppByUJEEMountIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppPKey& rhs );
	bool operator >=(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppHPKey& rhs );
	bool operator >=(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppHBuff& rhs );
	bool operator >=(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppBuff& rhs );

	bool operator >(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppByClusterIdxKey& rhs );

	bool operator >(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppByUJEEMountIdxKey& rhs );

	bool operator >(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppPKey& rhs );
	bool operator >(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppHPKey& rhs );
	bool operator >(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppHBuff& rhs );
	bool operator >(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppBuff& rhs );

	template<> struct hash<cfsec::CFSecSecAppBuff> {
		typedef cfsec::CFSecSecAppBuff argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

