#pragma once

// Description: C++18 specification of a SecForm history primary key object.

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

	class CFSecSecFormPKey;
	class CFSecSecFormBuff;
	class CFSecSecFormHBuff;

	class CFSecSecFormHPKey : public CFSecHPKey
	{
	protected:

		int64_t requiredClusterId;
		int32_t requiredSecFormId;
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;

		CFSecSecFormHPKey();
		CFSecSecFormHPKey( const CFSecSecFormHPKey& src );
		virtual ~CFSecSecFormHPKey();

		virtual const int64_t getRequiredClusterId() const;
		virtual const int64_t* getRequiredClusterIdReference() const;
		virtual void setRequiredClusterId( const int64_t value );

		virtual const int32_t getRequiredSecFormId() const;
		virtual const int32_t* getRequiredSecFormIdReference() const;
		virtual void setRequiredSecFormId( const int32_t value );

		virtual size_t hashCode() const;

		virtual std::string toString();

		bool operator <( const CFSecSecFormPKey& rhs );
		bool operator <( const CFSecSecFormHPKey& rhs );
		bool operator <( const CFSecSecFormHBuff& rhs );
		bool operator <( const CFSecSecFormBuff& rhs );


		bool operator <=( const CFSecSecFormPKey& rhs );
		bool operator <=( const CFSecSecFormHPKey& rhs );
		bool operator <=( const CFSecSecFormHBuff& rhs );
		bool operator <=( const CFSecSecFormBuff& rhs );


		bool operator ==( const CFSecSecFormPKey& rhs );
		bool operator ==( const CFSecSecFormHPKey& rhs );
		bool operator ==( const CFSecSecFormHBuff& rhs );
		bool operator ==( const CFSecSecFormBuff& rhs );


		bool operator !=( const CFSecSecFormPKey& rhs );
		bool operator !=( const CFSecSecFormHPKey& rhs );
		bool operator !=( const CFSecSecFormHBuff& rhs );
		bool operator !=( const CFSecSecFormBuff& rhs );


		bool operator >=( const CFSecSecFormPKey& rhs );
		bool operator >=( const CFSecSecFormHPKey& rhs );
		bool operator >=( const CFSecSecFormHBuff& rhs );
		bool operator >=( const CFSecSecFormBuff& rhs );


		bool operator >( const CFSecSecFormPKey& rhs );
		bool operator >( const CFSecSecFormHPKey& rhs );
		bool operator >( const CFSecSecFormHBuff& rhs );
		bool operator >( const CFSecSecFormBuff& rhs );

		cfsec::CFSecSecFormHPKey operator =( cfsec::CFSecSecFormPKey& src );
		cfsec::CFSecSecFormHPKey operator =( cfsec::CFSecSecFormHPKey& src );
		cfsec::CFSecSecFormHPKey operator =( cfsec::CFSecSecFormBuff& src );
		cfsec::CFSecSecFormHPKey operator =( cfsec::CFSecSecFormHBuff& src );

	};
}


namespace std {

	bool operator <(const  cfsec::CFSecSecFormHPKey& lhs, const cfsec::CFSecSecFormPKey& rhs );
	bool operator <(const  cfsec::CFSecSecFormHPKey& lhs, const cfsec::CFSecSecFormHPKey& rhs );
	bool operator <(const  cfsec::CFSecSecFormHPKey& lhs, const cfsec::CFSecSecFormHBuff& rhs );
	bool operator <(const  cfsec::CFSecSecFormHPKey& lhs, const cfsec::CFSecSecFormBuff& rhs );


	bool operator <=(const  cfsec::CFSecSecFormHPKey& lhs, const cfsec::CFSecSecFormPKey& rhs );
	bool operator <=(const  cfsec::CFSecSecFormHPKey& lhs, const cfsec::CFSecSecFormHPKey& rhs );
	bool operator <=(const  cfsec::CFSecSecFormHPKey& lhs, const cfsec::CFSecSecFormHBuff& rhs );
	bool operator <=(const  cfsec::CFSecSecFormHPKey& lhs, const cfsec::CFSecSecFormBuff& rhs );


	bool operator ==(const  cfsec::CFSecSecFormHPKey& lhs, const cfsec::CFSecSecFormPKey& rhs );
	bool operator ==(const  cfsec::CFSecSecFormHPKey& lhs, const cfsec::CFSecSecFormHPKey& rhs );
	bool operator ==(const  cfsec::CFSecSecFormHPKey& lhs, const cfsec::CFSecSecFormHBuff& rhs );
	bool operator ==(const  cfsec::CFSecSecFormHPKey& lhs, const cfsec::CFSecSecFormBuff& rhs );


	bool operator !=(const  cfsec::CFSecSecFormHPKey& lhs, const cfsec::CFSecSecFormPKey& rhs );
	bool operator !=(const  cfsec::CFSecSecFormHPKey& lhs, const cfsec::CFSecSecFormHPKey& rhs );
	bool operator !=(const  cfsec::CFSecSecFormHPKey& lhs, const cfsec::CFSecSecFormHBuff& rhs );
	bool operator !=(const  cfsec::CFSecSecFormHPKey& lhs, const cfsec::CFSecSecFormBuff& rhs );


	bool operator >=(const  cfsec::CFSecSecFormHPKey& lhs, const cfsec::CFSecSecFormPKey& rhs );
	bool operator >=(const  cfsec::CFSecSecFormHPKey& lhs, const cfsec::CFSecSecFormHPKey& rhs );
	bool operator >=(const  cfsec::CFSecSecFormHPKey& lhs, const cfsec::CFSecSecFormHBuff& rhs );
	bool operator >=(const  cfsec::CFSecSecFormHPKey& lhs, const cfsec::CFSecSecFormBuff& rhs );


	bool operator >(const  cfsec::CFSecSecFormHPKey& lhs, const cfsec::CFSecSecFormPKey& rhs );
	bool operator >(const  cfsec::CFSecSecFormHPKey& lhs, const cfsec::CFSecSecFormHPKey& rhs );
	bool operator >(const  cfsec::CFSecSecFormHPKey& lhs, const cfsec::CFSecSecFormHBuff& rhs );
	bool operator >(const  cfsec::CFSecSecFormHPKey& lhs, const cfsec::CFSecSecFormBuff& rhs );


	template<> struct hash<cfsec::CFSecSecFormHPKey> {
		typedef cfsec::CFSecSecFormHPKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

