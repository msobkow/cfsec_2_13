#pragma once

// Description: C++18 specification of a TSecGroup history buffer object.

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

