#pragma once

// Description: C++18 specification for a SecGroup buffer object.

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

	class CFSecSecGroupPKey;
	class CFSecSecGroupHPKey;
	class CFSecSecGroupHBuff;
	class CFSecSecGroupByClusterIdxKey;
	class CFSecSecGroupByClusterVisIdxKey;
	class CFSecSecGroupByUNameIdxKey;

	class CFSecSecGroupBuff : public cflib::ICFLibCloneableObj
	{
	public:
		static const std::string GENDEFNAME;
		static const classcode_t CLASS_CODE;
		static const std::string CLASS_NAME;
		static const std::string COLNAME_CLUSTERID;
		static const std::string COLNAME_SECGROUPID;
		static const std::string COLNAME_NAME;
		static const std::string COLNAME_ISVISIBLE;
		static const char* S_INIT_CREATEDBY;
		static const char* S_INIT_UPDATEDBY;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;
		static const int64_t CLUSTERID_INIT_VALUE;
		static const int SECGROUPID_INIT_VALUE;
		static const std::string NAME_INIT_VALUE;
		static const bool ISVISIBLE_INIT_VALUE;
		static const int64_t CLUSTERID_MIN_VALUE;
		static const int SECGROUPID_MIN_VALUE;
		static const std::string::size_type NAME_MAX_LEN;
	protected:
		uuid_t createdByUserId;
		std::chrono::system_clock::time_point createdAt;
		uuid_t updatedByUserId;
		std::chrono::system_clock::time_point updatedAt;
		int64_t requiredClusterId;
		int32_t requiredSecGroupId;
		std::string* requiredName;
		bool requiredIsVisible;
		int32_t requiredRevision;
	public:
		CFSecSecGroupBuff();

		CFSecSecGroupBuff( const CFSecSecGroupBuff& src );

		virtual ~CFSecSecGroupBuff();

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

		virtual const int32_t getRequiredSecGroupId() const;
		virtual const int32_t* getRequiredSecGroupIdReference() const;
		virtual void setRequiredSecGroupId( const int32_t value );

		virtual const std::string& getRequiredName() const;
		virtual const std::string* getRequiredNameReference() const;
		virtual void setRequiredName( const std::string& value );

		virtual const bool getRequiredIsVisible() const;
		virtual const bool* getRequiredIsVisibleReference() const;
		virtual void setRequiredIsVisible( const bool value );

		virtual int32_t getRequiredRevision() const;
		virtual void setRequiredRevision( int32_t value );

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
		cfsec::CFSecSecGroupBuff operator =( cfsec::CFSecSecGroupBuff& src );
		cfsec::CFSecSecGroupBuff operator =( cfsec::CFSecSecGroupHBuff& src );

		virtual std::string toString();
	};
}

namespace std {

	bool operator <(const  cfsec::CFSecSecGroupBuff& lhs, const cfsec::CFSecSecGroupByClusterIdxKey& rhs );
	bool operator <(const  cfsec::CFSecSecGroupBuff& lhs, const cfsec::CFSecSecGroupByClusterVisIdxKey& rhs );
	bool operator <(const  cfsec::CFSecSecGroupBuff& lhs, const cfsec::CFSecSecGroupByUNameIdxKey& rhs );
	bool operator <(const  cfsec::CFSecSecGroupBuff& lhs, const cfsec::CFSecSecGroupPKey& rhs );
	bool operator <(const  cfsec::CFSecSecGroupBuff& lhs, const cfsec::CFSecSecGroupHPKey& rhs );
	bool operator <(const  cfsec::CFSecSecGroupBuff& lhs, const cfsec::CFSecSecGroupHBuff& rhs );
	bool operator <(const  cfsec::CFSecSecGroupBuff& lhs, const cfsec::CFSecSecGroupBuff& rhs );

	bool operator <=(const  cfsec::CFSecSecGroupBuff& lhs, const cfsec::CFSecSecGroupByClusterIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecSecGroupBuff& lhs, const cfsec::CFSecSecGroupByClusterVisIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecSecGroupBuff& lhs, const cfsec::CFSecSecGroupByUNameIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecSecGroupBuff& lhs, const cfsec::CFSecSecGroupPKey& rhs );
	bool operator <=(const  cfsec::CFSecSecGroupBuff& lhs, const cfsec::CFSecSecGroupHPKey& rhs );
	bool operator <=(const  cfsec::CFSecSecGroupBuff& lhs, const cfsec::CFSecSecGroupHBuff& rhs );
	bool operator <=(const  cfsec::CFSecSecGroupBuff& lhs, const cfsec::CFSecSecGroupBuff& rhs );

	bool operator ==(const  cfsec::CFSecSecGroupBuff& lhs, const cfsec::CFSecSecGroupByClusterIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecSecGroupBuff& lhs, const cfsec::CFSecSecGroupByClusterVisIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecSecGroupBuff& lhs, const cfsec::CFSecSecGroupByUNameIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecSecGroupBuff& lhs, const cfsec::CFSecSecGroupPKey& rhs );
	bool operator ==(const  cfsec::CFSecSecGroupBuff& lhs, const cfsec::CFSecSecGroupHPKey& rhs );
	bool operator ==(const  cfsec::CFSecSecGroupBuff& lhs, const cfsec::CFSecSecGroupHBuff& rhs );
	bool operator ==(const  cfsec::CFSecSecGroupBuff& lhs, const cfsec::CFSecSecGroupBuff& rhs );

	bool operator !=(const  cfsec::CFSecSecGroupBuff& lhs, const cfsec::CFSecSecGroupByClusterIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecSecGroupBuff& lhs, const cfsec::CFSecSecGroupByClusterVisIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecSecGroupBuff& lhs, const cfsec::CFSecSecGroupByUNameIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecSecGroupBuff& lhs, const cfsec::CFSecSecGroupPKey& rhs );
	bool operator !=(const  cfsec::CFSecSecGroupBuff& lhs, const cfsec::CFSecSecGroupHPKey& rhs );
	bool operator !=(const  cfsec::CFSecSecGroupBuff& lhs, const cfsec::CFSecSecGroupHBuff& rhs );
	bool operator !=(const  cfsec::CFSecSecGroupBuff& lhs, const cfsec::CFSecSecGroupBuff& rhs );

	bool operator >=(const  cfsec::CFSecSecGroupBuff& lhs, const cfsec::CFSecSecGroupByClusterIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecSecGroupBuff& lhs, const cfsec::CFSecSecGroupByClusterVisIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecSecGroupBuff& lhs, const cfsec::CFSecSecGroupByUNameIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecSecGroupBuff& lhs, const cfsec::CFSecSecGroupPKey& rhs );
	bool operator >=(const  cfsec::CFSecSecGroupBuff& lhs, const cfsec::CFSecSecGroupHPKey& rhs );
	bool operator >=(const  cfsec::CFSecSecGroupBuff& lhs, const cfsec::CFSecSecGroupHBuff& rhs );
	bool operator >=(const  cfsec::CFSecSecGroupBuff& lhs, const cfsec::CFSecSecGroupBuff& rhs );

	bool operator >(const  cfsec::CFSecSecGroupBuff& lhs, const cfsec::CFSecSecGroupByClusterIdxKey& rhs );

	bool operator >(const  cfsec::CFSecSecGroupBuff& lhs, const cfsec::CFSecSecGroupByClusterVisIdxKey& rhs );

	bool operator >(const  cfsec::CFSecSecGroupBuff& lhs, const cfsec::CFSecSecGroupByUNameIdxKey& rhs );

	bool operator >(const  cfsec::CFSecSecGroupBuff& lhs, const cfsec::CFSecSecGroupPKey& rhs );
	bool operator >(const  cfsec::CFSecSecGroupBuff& lhs, const cfsec::CFSecSecGroupHPKey& rhs );
	bool operator >(const  cfsec::CFSecSecGroupBuff& lhs, const cfsec::CFSecSecGroupHBuff& rhs );
	bool operator >(const  cfsec::CFSecSecGroupBuff& lhs, const cfsec::CFSecSecGroupBuff& rhs );

	template<> struct hash<cfsec::CFSecSecGroupBuff> {
		typedef cfsec::CFSecSecGroupBuff argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

