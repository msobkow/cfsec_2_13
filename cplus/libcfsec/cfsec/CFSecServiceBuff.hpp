#pragma once

// Description: C++18 specification for a Service buffer object.

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

	class CFSecServicePKey;
	class CFSecServiceHPKey;
	class CFSecServiceHBuff;
	class CFSecServiceByClusterIdxKey;
	class CFSecServiceByHostIdxKey;
	class CFSecServiceByTypeIdxKey;
	class CFSecServiceByUTypeIdxKey;
	class CFSecServiceByUHostPortIdxKey;

	class CFSecServiceBuff : public cflib::ICFLibCloneableObj
	{
	public:
		static const std::string GENDEFNAME;
		static const classcode_t CLASS_CODE;
		static const std::string CLASS_NAME;
		static const std::string COLNAME_CLUSTERID;
		static const std::string COLNAME_SERVICEID;
		static const std::string COLNAME_HOSTNODEID;
		static const std::string COLNAME_SERVICETYPEID;
		static const std::string COLNAME_HOSTPORT;
		static const char* S_INIT_CREATEDBY;
		static const char* S_INIT_UPDATEDBY;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;
		static const int64_t CLUSTERID_INIT_VALUE;
		static const int64_t SERVICEID_INIT_VALUE;
		static const int64_t HOSTNODEID_INIT_VALUE;
		static const int SERVICETYPEID_INIT_VALUE;
		static const int16_t HOSTPORT_INIT_VALUE;
		static const int64_t CLUSTERID_MIN_VALUE;
		static const int64_t SERVICEID_MIN_VALUE;
		static const int64_t HOSTNODEID_MIN_VALUE;
		static const int SERVICETYPEID_MIN_VALUE;
		static const int16_t HOSTPORT_MIN_VALUE;
	protected:
		uuid_t createdByUserId;
		std::chrono::system_clock::time_point createdAt;
		uuid_t updatedByUserId;
		std::chrono::system_clock::time_point updatedAt;
		int64_t requiredClusterId;
		int64_t requiredServiceId;
		int64_t requiredHostNodeId;
		int32_t requiredServiceTypeId;
		int16_t requiredHostPort;
		int32_t requiredRevision;
	public:
		CFSecServiceBuff();

		CFSecServiceBuff( const CFSecServiceBuff& src );

		virtual ~CFSecServiceBuff();

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

		virtual const int64_t getRequiredServiceId() const;
		virtual const int64_t* getRequiredServiceIdReference() const;
		virtual void setRequiredServiceId( const int64_t value );

		virtual const int64_t getRequiredHostNodeId() const;
		virtual const int64_t* getRequiredHostNodeIdReference() const;
		virtual void setRequiredHostNodeId( const int64_t value );

		virtual const int32_t getRequiredServiceTypeId() const;
		virtual const int32_t* getRequiredServiceTypeIdReference() const;
		virtual void setRequiredServiceTypeId( const int32_t value );

		virtual const int16_t getRequiredHostPort() const;
		virtual const int16_t* getRequiredHostPortReference() const;
		virtual void setRequiredHostPort( const int16_t value );

		virtual int32_t getRequiredRevision() const;
		virtual void setRequiredRevision( int32_t value );

		virtual size_t hashCode() const;

		bool operator <( const CFSecServiceByClusterIdxKey& rhs );
		bool operator <( const CFSecServiceByHostIdxKey& rhs );
		bool operator <( const CFSecServiceByTypeIdxKey& rhs );
		bool operator <( const CFSecServiceByUTypeIdxKey& rhs );
		bool operator <( const CFSecServiceByUHostPortIdxKey& rhs );
		bool operator <( const CFSecServicePKey& rhs );
		bool operator <( const CFSecServiceHPKey& rhs );
		bool operator <( const CFSecServiceHBuff& rhs );
		bool operator <( const CFSecServiceBuff& rhs );

		bool operator <=( const CFSecServiceByClusterIdxKey& rhs );
		bool operator <=( const CFSecServiceByHostIdxKey& rhs );
		bool operator <=( const CFSecServiceByTypeIdxKey& rhs );
		bool operator <=( const CFSecServiceByUTypeIdxKey& rhs );
		bool operator <=( const CFSecServiceByUHostPortIdxKey& rhs );
		bool operator <=( const CFSecServicePKey& rhs );
		bool operator <=( const CFSecServiceHPKey& rhs );
		bool operator <=( const CFSecServiceHBuff& rhs );
		bool operator <=( const CFSecServiceBuff& rhs );

		bool operator ==( const CFSecServiceByClusterIdxKey& rhs );
		bool operator ==( const CFSecServiceByHostIdxKey& rhs );
		bool operator ==( const CFSecServiceByTypeIdxKey& rhs );
		bool operator ==( const CFSecServiceByUTypeIdxKey& rhs );
		bool operator ==( const CFSecServiceByUHostPortIdxKey& rhs );
		bool operator ==( const CFSecServicePKey& rhs );
		bool operator ==( const CFSecServiceHPKey& rhs );
		bool operator ==( const CFSecServiceHBuff& rhs );
		bool operator ==( const CFSecServiceBuff& rhs );

		bool operator !=( const CFSecServiceByClusterIdxKey& rhs );
		bool operator !=( const CFSecServiceByHostIdxKey& rhs );
		bool operator !=( const CFSecServiceByTypeIdxKey& rhs );
		bool operator !=( const CFSecServiceByUTypeIdxKey& rhs );
		bool operator !=( const CFSecServiceByUHostPortIdxKey& rhs );
		bool operator !=( const CFSecServicePKey& rhs );
		bool operator !=( const CFSecServiceHPKey& rhs );
		bool operator !=( const CFSecServiceHBuff& rhs );
		bool operator !=( const CFSecServiceBuff& rhs );

		bool operator >=( const CFSecServiceByClusterIdxKey& rhs );
		bool operator >=( const CFSecServiceByHostIdxKey& rhs );
		bool operator >=( const CFSecServiceByTypeIdxKey& rhs );
		bool operator >=( const CFSecServiceByUTypeIdxKey& rhs );
		bool operator >=( const CFSecServiceByUHostPortIdxKey& rhs );
		bool operator >=( const CFSecServicePKey& rhs );
		bool operator >=( const CFSecServiceHPKey& rhs );
		bool operator >=( const CFSecServiceHBuff& rhs );
		bool operator >=( const CFSecServiceBuff& rhs );

		bool operator >( const CFSecServiceByClusterIdxKey& rhs );
		bool operator >( const CFSecServiceByHostIdxKey& rhs );
		bool operator >( const CFSecServiceByTypeIdxKey& rhs );
		bool operator >( const CFSecServiceByUTypeIdxKey& rhs );
		bool operator >( const CFSecServiceByUHostPortIdxKey& rhs );
		bool operator >( const CFSecServicePKey& rhs );
		bool operator >( const CFSecServiceHPKey& rhs );
		bool operator >( const CFSecServiceHBuff& rhs );
		bool operator >( const CFSecServiceBuff& rhs );
		cfsec::CFSecServiceBuff operator =( cfsec::CFSecServiceBuff& src );
		cfsec::CFSecServiceBuff operator =( cfsec::CFSecServiceHBuff& src );

		virtual std::string toString();
	};
}

namespace std {

	bool operator <(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceByClusterIdxKey& rhs );
	bool operator <(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceByHostIdxKey& rhs );
	bool operator <(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceByTypeIdxKey& rhs );
	bool operator <(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceByUTypeIdxKey& rhs );
	bool operator <(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceByUHostPortIdxKey& rhs );
	bool operator <(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServicePKey& rhs );
	bool operator <(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceHPKey& rhs );
	bool operator <(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceHBuff& rhs );
	bool operator <(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceBuff& rhs );

	bool operator <=(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceByClusterIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceByHostIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceByTypeIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceByUTypeIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceByUHostPortIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServicePKey& rhs );
	bool operator <=(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceHPKey& rhs );
	bool operator <=(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceHBuff& rhs );
	bool operator <=(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceBuff& rhs );

	bool operator ==(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceByClusterIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceByHostIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceByTypeIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceByUTypeIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceByUHostPortIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServicePKey& rhs );
	bool operator ==(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceHPKey& rhs );
	bool operator ==(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceHBuff& rhs );
	bool operator ==(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceBuff& rhs );

	bool operator !=(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceByClusterIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceByHostIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceByTypeIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceByUTypeIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceByUHostPortIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServicePKey& rhs );
	bool operator !=(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceHPKey& rhs );
	bool operator !=(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceHBuff& rhs );
	bool operator !=(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceBuff& rhs );

	bool operator >=(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceByClusterIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceByHostIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceByTypeIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceByUTypeIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceByUHostPortIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServicePKey& rhs );
	bool operator >=(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceHPKey& rhs );
	bool operator >=(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceHBuff& rhs );
	bool operator >=(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceBuff& rhs );

	bool operator >(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceByClusterIdxKey& rhs );

	bool operator >(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceByHostIdxKey& rhs );

	bool operator >(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceByTypeIdxKey& rhs );

	bool operator >(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceByUTypeIdxKey& rhs );

	bool operator >(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceByUHostPortIdxKey& rhs );

	bool operator >(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServicePKey& rhs );
	bool operator >(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceHPKey& rhs );
	bool operator >(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceHBuff& rhs );
	bool operator >(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceBuff& rhs );

	template<> struct hash<cfsec::CFSecServiceBuff> {
		typedef cfsec::CFSecServiceBuff argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

