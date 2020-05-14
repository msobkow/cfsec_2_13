#pragma once

// Description: C++18 specification of a Cluster history buffer object.

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

#include <cfsec/CFSecHPKey.hpp>

#include <cfsec/ICFSecSchema.hpp>
namespace cfsec {

	class CFSecClusterBuff;
	class CFSecClusterPKey;
	class CFSecClusterHPKey;
	class CFSecClusterByUDomNameIdxKey;
	class CFSecClusterByUDescrIdxKey;

	class CFSecClusterHBuff : public CFSecHPKey, public cflib::ICFLibCloneableObj
	{
	public:
		static const std::string CLASS_NAME;
	protected:
		int64_t requiredId;
		std::string* requiredFullDomName;
		std::string* requiredDescription;		classcode_t classCode;

	public:
		CFSecClusterHBuff();
		CFSecClusterHBuff( const CFSecClusterHBuff& src );
		virtual ~CFSecClusterHBuff();

		virtual cflib::ICFLibCloneableObj* clone();
		virtual const int64_t getRequiredId() const;
		virtual const int64_t* getRequiredIdReference() const;
		virtual void setRequiredId( const int64_t value );

		virtual const std::string& getRequiredFullDomName() const;
		virtual const std::string* getRequiredFullDomNameReference() const;
		virtual void setRequiredFullDomName( const std::string& value );

		virtual const std::string& getRequiredDescription() const;
		virtual const std::string* getRequiredDescriptionReference() const;
		virtual void setRequiredDescription( const std::string& value );

		virtual size_t hashCode() const;

		bool operator <( const CFSecClusterByUDomNameIdxKey& rhs );
		bool operator <( const CFSecClusterByUDescrIdxKey& rhs );
		bool operator <( const CFSecClusterPKey& rhs );
		bool operator <( const CFSecClusterHPKey& rhs );
		bool operator <( const CFSecClusterHBuff& rhs );
		bool operator <( const CFSecClusterBuff& rhs );

		bool operator <=( const CFSecClusterByUDomNameIdxKey& rhs );
		bool operator <=( const CFSecClusterByUDescrIdxKey& rhs );
		bool operator <=( const CFSecClusterPKey& rhs );
		bool operator <=( const CFSecClusterHPKey& rhs );
		bool operator <=( const CFSecClusterHBuff& rhs );
		bool operator <=( const CFSecClusterBuff& rhs );

		bool operator ==( const CFSecClusterByUDomNameIdxKey& rhs );
		bool operator ==( const CFSecClusterByUDescrIdxKey& rhs );
		bool operator ==( const CFSecClusterPKey& rhs );
		bool operator ==( const CFSecClusterHPKey& rhs );
		bool operator ==( const CFSecClusterHBuff& rhs );
		bool operator ==( const CFSecClusterBuff& rhs );

		bool operator !=( const CFSecClusterByUDomNameIdxKey& rhs );
		bool operator !=( const CFSecClusterByUDescrIdxKey& rhs );
		bool operator !=( const CFSecClusterPKey& rhs );
		bool operator !=( const CFSecClusterHPKey& rhs );
		bool operator !=( const CFSecClusterHBuff& rhs );
		bool operator !=( const CFSecClusterBuff& rhs );

		bool operator >=( const CFSecClusterByUDomNameIdxKey& rhs );
		bool operator >=( const CFSecClusterByUDescrIdxKey& rhs );
		bool operator >=( const CFSecClusterPKey& rhs );
		bool operator >=( const CFSecClusterHPKey& rhs );
		bool operator >=( const CFSecClusterHBuff& rhs );
		bool operator >=( const CFSecClusterBuff& rhs );

		bool operator >( const CFSecClusterByUDomNameIdxKey& rhs );
		bool operator >( const CFSecClusterByUDescrIdxKey& rhs );
		bool operator >( const CFSecClusterPKey& rhs );
		bool operator >( const CFSecClusterHPKey& rhs );
		bool operator >( const CFSecClusterHBuff& rhs );
		bool operator >( const CFSecClusterBuff& rhs );
		cfsec::CFSecClusterHBuff operator =( cfsec::CFSecClusterBuff& src );
		cfsec::CFSecClusterHBuff operator =( cfsec::CFSecClusterHBuff& src );

		virtual std::string toString();

	};
}

namespace std {

	bool operator <(const  cfsec::CFSecClusterHBuff& lhs, const cfsec::CFSecClusterByUDomNameIdxKey& rhs );
	bool operator <(const  cfsec::CFSecClusterHBuff& lhs, const cfsec::CFSecClusterByUDescrIdxKey& rhs );
	bool operator <(const  cfsec::CFSecClusterHBuff& lhs, const cfsec::CFSecClusterPKey& rhs );
	bool operator <(const  cfsec::CFSecClusterHBuff& lhs, const cfsec::CFSecClusterHPKey& rhs );
	bool operator <(const  cfsec::CFSecClusterHBuff& lhs, const cfsec::CFSecClusterHBuff& rhs );
	bool operator <(const  cfsec::CFSecClusterHBuff& lhs, const cfsec::CFSecClusterBuff& rhs );

	bool operator <=(const  cfsec::CFSecClusterHBuff& lhs, const cfsec::CFSecClusterByUDomNameIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecClusterHBuff& lhs, const cfsec::CFSecClusterByUDescrIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecClusterHBuff& lhs, const cfsec::CFSecClusterPKey& rhs );
	bool operator <=(const  cfsec::CFSecClusterHBuff& lhs, const cfsec::CFSecClusterHPKey& rhs );
	bool operator <=(const  cfsec::CFSecClusterHBuff& lhs, const cfsec::CFSecClusterHBuff& rhs );
	bool operator <=(const  cfsec::CFSecClusterHBuff& lhs, const cfsec::CFSecClusterBuff& rhs );

	bool operator ==(const  cfsec::CFSecClusterHBuff& lhs, const cfsec::CFSecClusterByUDomNameIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecClusterHBuff& lhs, const cfsec::CFSecClusterByUDescrIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecClusterHBuff& lhs, const cfsec::CFSecClusterPKey& rhs );
	bool operator ==(const  cfsec::CFSecClusterHBuff& lhs, const cfsec::CFSecClusterHPKey& rhs );
	bool operator ==(const  cfsec::CFSecClusterHBuff& lhs, const cfsec::CFSecClusterHBuff& rhs );
	bool operator ==(const  cfsec::CFSecClusterHBuff& lhs, const cfsec::CFSecClusterBuff& rhs );

	bool operator !=(const  cfsec::CFSecClusterHBuff& lhs, const cfsec::CFSecClusterByUDomNameIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecClusterHBuff& lhs, const cfsec::CFSecClusterByUDescrIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecClusterHBuff& lhs, const cfsec::CFSecClusterPKey& rhs );
	bool operator !=(const  cfsec::CFSecClusterHBuff& lhs, const cfsec::CFSecClusterHPKey& rhs );
	bool operator !=(const  cfsec::CFSecClusterHBuff& lhs, const cfsec::CFSecClusterHBuff& rhs );
	bool operator !=(const  cfsec::CFSecClusterHBuff& lhs, const cfsec::CFSecClusterBuff& rhs );

	bool operator >=(const  cfsec::CFSecClusterHBuff& lhs, const cfsec::CFSecClusterByUDomNameIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecClusterHBuff& lhs, const cfsec::CFSecClusterByUDescrIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecClusterHBuff& lhs, const cfsec::CFSecClusterPKey& rhs );
	bool operator >=(const  cfsec::CFSecClusterHBuff& lhs, const cfsec::CFSecClusterHPKey& rhs );
	bool operator >=(const  cfsec::CFSecClusterHBuff& lhs, const cfsec::CFSecClusterHBuff& rhs );
	bool operator >=(const  cfsec::CFSecClusterHBuff& lhs, const cfsec::CFSecClusterBuff& rhs );

	bool operator >(const  cfsec::CFSecClusterHBuff& lhs, const cfsec::CFSecClusterByUDomNameIdxKey& rhs );
	bool operator >(const  cfsec::CFSecClusterHBuff& lhs, const cfsec::CFSecClusterByUDescrIdxKey& rhs );
	bool operator >(const  cfsec::CFSecClusterHBuff& lhs, const cfsec::CFSecClusterPKey& rhs );
	bool operator >(const  cfsec::CFSecClusterHBuff& lhs, const cfsec::CFSecClusterHPKey& rhs );
	bool operator >(const  cfsec::CFSecClusterHBuff& lhs, const cfsec::CFSecClusterHBuff& rhs );
	bool operator >(const  cfsec::CFSecClusterHBuff& lhs, const cfsec::CFSecClusterBuff& rhs );

	template<> struct hash<cfsec::CFSecClusterHBuff> {
		typedef cfsec::CFSecClusterHBuff argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

