#pragma once

// Description: C++18 specification for a SysCluster buffer object.

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

	class CFSecSysClusterPKey;
	class CFSecSysClusterHPKey;
	class CFSecSysClusterHBuff;
	class CFSecSysClusterByClusterIdxKey;

	class CFSecSysClusterBuff : public cflib::ICFLibCloneableObj
	{
	public:
		static const std::string GENDEFNAME;
		static const classcode_t CLASS_CODE;
		static const std::string CLASS_NAME;
		static const std::string COLNAME_SINGLETONID;
		static const std::string COLNAME_CLUSTERID;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;
		static const int SINGLETONID_INIT_VALUE;
		static const int64_t CLUSTERID_INIT_VALUE;
		static const int SINGLETONID_MIN_VALUE;
		static const int64_t CLUSTERID_MIN_VALUE;
		static const int SINGLETONID_MAX_VALUE;
	protected:
		int32_t requiredSingletonId;
		int64_t requiredClusterId;
		int32_t requiredRevision;
	public:
		CFSecSysClusterBuff();

		CFSecSysClusterBuff( const CFSecSysClusterBuff& src );

		virtual ~CFSecSysClusterBuff();

		virtual const std::string& getClassName() const;
		virtual cflib::ICFLibCloneableObj* clone();
		virtual const classcode_t getClassCode() const;

		virtual bool implementsClassCode( const classcode_t argClassCode );
		virtual const int32_t getRequiredSingletonId() const;
		virtual const int32_t* getRequiredSingletonIdReference() const;
		virtual void setRequiredSingletonId( const int32_t value );

		virtual const int64_t getRequiredClusterId() const;
		virtual const int64_t* getRequiredClusterIdReference() const;
		virtual void setRequiredClusterId( const int64_t value );

		virtual int32_t getRequiredRevision() const;
		virtual void setRequiredRevision( int32_t value );

		virtual size_t hashCode() const;

		bool operator <( const CFSecSysClusterByClusterIdxKey& rhs );
		bool operator <( const CFSecSysClusterPKey& rhs );
		bool operator <( const CFSecSysClusterHPKey& rhs );
		bool operator <( const CFSecSysClusterHBuff& rhs );
		bool operator <( const CFSecSysClusterBuff& rhs );

		bool operator <=( const CFSecSysClusterByClusterIdxKey& rhs );
		bool operator <=( const CFSecSysClusterPKey& rhs );
		bool operator <=( const CFSecSysClusterHPKey& rhs );
		bool operator <=( const CFSecSysClusterHBuff& rhs );
		bool operator <=( const CFSecSysClusterBuff& rhs );

		bool operator ==( const CFSecSysClusterByClusterIdxKey& rhs );
		bool operator ==( const CFSecSysClusterPKey& rhs );
		bool operator ==( const CFSecSysClusterHPKey& rhs );
		bool operator ==( const CFSecSysClusterHBuff& rhs );
		bool operator ==( const CFSecSysClusterBuff& rhs );

		bool operator !=( const CFSecSysClusterByClusterIdxKey& rhs );
		bool operator !=( const CFSecSysClusterPKey& rhs );
		bool operator !=( const CFSecSysClusterHPKey& rhs );
		bool operator !=( const CFSecSysClusterHBuff& rhs );
		bool operator !=( const CFSecSysClusterBuff& rhs );

		bool operator >=( const CFSecSysClusterByClusterIdxKey& rhs );
		bool operator >=( const CFSecSysClusterPKey& rhs );
		bool operator >=( const CFSecSysClusterHPKey& rhs );
		bool operator >=( const CFSecSysClusterHBuff& rhs );
		bool operator >=( const CFSecSysClusterBuff& rhs );

		bool operator >( const CFSecSysClusterByClusterIdxKey& rhs );
		bool operator >( const CFSecSysClusterPKey& rhs );
		bool operator >( const CFSecSysClusterHPKey& rhs );
		bool operator >( const CFSecSysClusterHBuff& rhs );
		bool operator >( const CFSecSysClusterBuff& rhs );
		cfsec::CFSecSysClusterBuff operator =( cfsec::CFSecSysClusterBuff& src );
		cfsec::CFSecSysClusterBuff operator =( cfsec::CFSecSysClusterHBuff& src );

		virtual std::string toString();
	};
}

namespace std {

	bool operator <(const  cfsec::CFSecSysClusterBuff& lhs, const cfsec::CFSecSysClusterByClusterIdxKey& rhs );
	bool operator <(const  cfsec::CFSecSysClusterBuff& lhs, const cfsec::CFSecSysClusterPKey& rhs );
	bool operator <(const  cfsec::CFSecSysClusterBuff& lhs, const cfsec::CFSecSysClusterHPKey& rhs );
	bool operator <(const  cfsec::CFSecSysClusterBuff& lhs, const cfsec::CFSecSysClusterHBuff& rhs );
	bool operator <(const  cfsec::CFSecSysClusterBuff& lhs, const cfsec::CFSecSysClusterBuff& rhs );

	bool operator <=(const  cfsec::CFSecSysClusterBuff& lhs, const cfsec::CFSecSysClusterByClusterIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecSysClusterBuff& lhs, const cfsec::CFSecSysClusterPKey& rhs );
	bool operator <=(const  cfsec::CFSecSysClusterBuff& lhs, const cfsec::CFSecSysClusterHPKey& rhs );
	bool operator <=(const  cfsec::CFSecSysClusterBuff& lhs, const cfsec::CFSecSysClusterHBuff& rhs );
	bool operator <=(const  cfsec::CFSecSysClusterBuff& lhs, const cfsec::CFSecSysClusterBuff& rhs );

	bool operator ==(const  cfsec::CFSecSysClusterBuff& lhs, const cfsec::CFSecSysClusterByClusterIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecSysClusterBuff& lhs, const cfsec::CFSecSysClusterPKey& rhs );
	bool operator ==(const  cfsec::CFSecSysClusterBuff& lhs, const cfsec::CFSecSysClusterHPKey& rhs );
	bool operator ==(const  cfsec::CFSecSysClusterBuff& lhs, const cfsec::CFSecSysClusterHBuff& rhs );
	bool operator ==(const  cfsec::CFSecSysClusterBuff& lhs, const cfsec::CFSecSysClusterBuff& rhs );

	bool operator !=(const  cfsec::CFSecSysClusterBuff& lhs, const cfsec::CFSecSysClusterByClusterIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecSysClusterBuff& lhs, const cfsec::CFSecSysClusterPKey& rhs );
	bool operator !=(const  cfsec::CFSecSysClusterBuff& lhs, const cfsec::CFSecSysClusterHPKey& rhs );
	bool operator !=(const  cfsec::CFSecSysClusterBuff& lhs, const cfsec::CFSecSysClusterHBuff& rhs );
	bool operator !=(const  cfsec::CFSecSysClusterBuff& lhs, const cfsec::CFSecSysClusterBuff& rhs );

	bool operator >=(const  cfsec::CFSecSysClusterBuff& lhs, const cfsec::CFSecSysClusterByClusterIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecSysClusterBuff& lhs, const cfsec::CFSecSysClusterPKey& rhs );
	bool operator >=(const  cfsec::CFSecSysClusterBuff& lhs, const cfsec::CFSecSysClusterHPKey& rhs );
	bool operator >=(const  cfsec::CFSecSysClusterBuff& lhs, const cfsec::CFSecSysClusterHBuff& rhs );
	bool operator >=(const  cfsec::CFSecSysClusterBuff& lhs, const cfsec::CFSecSysClusterBuff& rhs );

	bool operator >(const  cfsec::CFSecSysClusterBuff& lhs, const cfsec::CFSecSysClusterByClusterIdxKey& rhs );

	bool operator >(const  cfsec::CFSecSysClusterBuff& lhs, const cfsec::CFSecSysClusterPKey& rhs );
	bool operator >(const  cfsec::CFSecSysClusterBuff& lhs, const cfsec::CFSecSysClusterHPKey& rhs );
	bool operator >(const  cfsec::CFSecSysClusterBuff& lhs, const cfsec::CFSecSysClusterHBuff& rhs );
	bool operator >(const  cfsec::CFSecSysClusterBuff& lhs, const cfsec::CFSecSysClusterBuff& rhs );

	template<> struct hash<cfsec::CFSecSysClusterBuff> {
		typedef cfsec::CFSecSysClusterBuff argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

