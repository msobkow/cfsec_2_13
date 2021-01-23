#pragma once

// Description: C++18 specification of a Service history buffer object.

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

#include <cfsec/CFSecHPKey.hpp>

#include <cfsec/ICFSecSchema.hpp>
namespace cfsec {

	class CFSecServiceBuff;
	class CFSecServicePKey;
	class CFSecServiceHPKey;
	class CFSecServiceByClusterIdxKey;
	class CFSecServiceByHostIdxKey;
	class CFSecServiceByTypeIdxKey;
	class CFSecServiceByUTypeIdxKey;
	class CFSecServiceByUHostPortIdxKey;

	class CFSecServiceHBuff : public CFSecHPKey, public cflib::ICFLibCloneableObj
	{
	public:
		static const std::string CLASS_NAME;
	protected:
		int64_t requiredClusterId;
		int64_t requiredServiceId;
		int64_t requiredHostNodeId;
		int32_t requiredServiceTypeId;
		int16_t requiredHostPort;		classcode_t classCode;

	public:
		CFSecServiceHBuff();
		CFSecServiceHBuff( const CFSecServiceHBuff& src );
		virtual ~CFSecServiceHBuff();

		virtual cflib::ICFLibCloneableObj* clone();
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
		cfsec::CFSecServiceHBuff operator =( cfsec::CFSecServiceBuff& src );
		cfsec::CFSecServiceHBuff operator =( cfsec::CFSecServiceHBuff& src );

		virtual std::string toString();

	};
}

namespace std {

	bool operator <(const  cfsec::CFSecServiceHBuff& lhs, const cfsec::CFSecServiceByClusterIdxKey& rhs );
	bool operator <(const  cfsec::CFSecServiceHBuff& lhs, const cfsec::CFSecServiceByHostIdxKey& rhs );
	bool operator <(const  cfsec::CFSecServiceHBuff& lhs, const cfsec::CFSecServiceByTypeIdxKey& rhs );
	bool operator <(const  cfsec::CFSecServiceHBuff& lhs, const cfsec::CFSecServiceByUTypeIdxKey& rhs );
	bool operator <(const  cfsec::CFSecServiceHBuff& lhs, const cfsec::CFSecServiceByUHostPortIdxKey& rhs );
	bool operator <(const  cfsec::CFSecServiceHBuff& lhs, const cfsec::CFSecServicePKey& rhs );
	bool operator <(const  cfsec::CFSecServiceHBuff& lhs, const cfsec::CFSecServiceHPKey& rhs );
	bool operator <(const  cfsec::CFSecServiceHBuff& lhs, const cfsec::CFSecServiceHBuff& rhs );
	bool operator <(const  cfsec::CFSecServiceHBuff& lhs, const cfsec::CFSecServiceBuff& rhs );

	bool operator <=(const  cfsec::CFSecServiceHBuff& lhs, const cfsec::CFSecServiceByClusterIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecServiceHBuff& lhs, const cfsec::CFSecServiceByHostIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecServiceHBuff& lhs, const cfsec::CFSecServiceByTypeIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecServiceHBuff& lhs, const cfsec::CFSecServiceByUTypeIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecServiceHBuff& lhs, const cfsec::CFSecServiceByUHostPortIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecServiceHBuff& lhs, const cfsec::CFSecServicePKey& rhs );
	bool operator <=(const  cfsec::CFSecServiceHBuff& lhs, const cfsec::CFSecServiceHPKey& rhs );
	bool operator <=(const  cfsec::CFSecServiceHBuff& lhs, const cfsec::CFSecServiceHBuff& rhs );
	bool operator <=(const  cfsec::CFSecServiceHBuff& lhs, const cfsec::CFSecServiceBuff& rhs );

	bool operator ==(const  cfsec::CFSecServiceHBuff& lhs, const cfsec::CFSecServiceByClusterIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecServiceHBuff& lhs, const cfsec::CFSecServiceByHostIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecServiceHBuff& lhs, const cfsec::CFSecServiceByTypeIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecServiceHBuff& lhs, const cfsec::CFSecServiceByUTypeIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecServiceHBuff& lhs, const cfsec::CFSecServiceByUHostPortIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecServiceHBuff& lhs, const cfsec::CFSecServicePKey& rhs );
	bool operator ==(const  cfsec::CFSecServiceHBuff& lhs, const cfsec::CFSecServiceHPKey& rhs );
	bool operator ==(const  cfsec::CFSecServiceHBuff& lhs, const cfsec::CFSecServiceHBuff& rhs );
	bool operator ==(const  cfsec::CFSecServiceHBuff& lhs, const cfsec::CFSecServiceBuff& rhs );

	bool operator !=(const  cfsec::CFSecServiceHBuff& lhs, const cfsec::CFSecServiceByClusterIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecServiceHBuff& lhs, const cfsec::CFSecServiceByHostIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecServiceHBuff& lhs, const cfsec::CFSecServiceByTypeIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecServiceHBuff& lhs, const cfsec::CFSecServiceByUTypeIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecServiceHBuff& lhs, const cfsec::CFSecServiceByUHostPortIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecServiceHBuff& lhs, const cfsec::CFSecServicePKey& rhs );
	bool operator !=(const  cfsec::CFSecServiceHBuff& lhs, const cfsec::CFSecServiceHPKey& rhs );
	bool operator !=(const  cfsec::CFSecServiceHBuff& lhs, const cfsec::CFSecServiceHBuff& rhs );
	bool operator !=(const  cfsec::CFSecServiceHBuff& lhs, const cfsec::CFSecServiceBuff& rhs );

	bool operator >=(const  cfsec::CFSecServiceHBuff& lhs, const cfsec::CFSecServiceByClusterIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecServiceHBuff& lhs, const cfsec::CFSecServiceByHostIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecServiceHBuff& lhs, const cfsec::CFSecServiceByTypeIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecServiceHBuff& lhs, const cfsec::CFSecServiceByUTypeIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecServiceHBuff& lhs, const cfsec::CFSecServiceByUHostPortIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecServiceHBuff& lhs, const cfsec::CFSecServicePKey& rhs );
	bool operator >=(const  cfsec::CFSecServiceHBuff& lhs, const cfsec::CFSecServiceHPKey& rhs );
	bool operator >=(const  cfsec::CFSecServiceHBuff& lhs, const cfsec::CFSecServiceHBuff& rhs );
	bool operator >=(const  cfsec::CFSecServiceHBuff& lhs, const cfsec::CFSecServiceBuff& rhs );

	bool operator >(const  cfsec::CFSecServiceHBuff& lhs, const cfsec::CFSecServiceByClusterIdxKey& rhs );
	bool operator >(const  cfsec::CFSecServiceHBuff& lhs, const cfsec::CFSecServiceByHostIdxKey& rhs );
	bool operator >(const  cfsec::CFSecServiceHBuff& lhs, const cfsec::CFSecServiceByTypeIdxKey& rhs );
	bool operator >(const  cfsec::CFSecServiceHBuff& lhs, const cfsec::CFSecServiceByUTypeIdxKey& rhs );
	bool operator >(const  cfsec::CFSecServiceHBuff& lhs, const cfsec::CFSecServiceByUHostPortIdxKey& rhs );
	bool operator >(const  cfsec::CFSecServiceHBuff& lhs, const cfsec::CFSecServicePKey& rhs );
	bool operator >(const  cfsec::CFSecServiceHBuff& lhs, const cfsec::CFSecServiceHPKey& rhs );
	bool operator >(const  cfsec::CFSecServiceHBuff& lhs, const cfsec::CFSecServiceHBuff& rhs );
	bool operator >(const  cfsec::CFSecServiceHBuff& lhs, const cfsec::CFSecServiceBuff& rhs );

	template<> struct hash<cfsec::CFSecServiceHBuff> {
		typedef cfsec::CFSecServiceHBuff argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

