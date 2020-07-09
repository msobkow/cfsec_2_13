#pragma once

// Description: C++18 specification of a SecUser history buffer object.

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

	class CFSecSecUserBuff;
	class CFSecSecUserPKey;
	class CFSecSecUserHPKey;
	class CFSecSecUserByULoginIdxKey;
	class CFSecSecUserByEMConfIdxKey;
	class CFSecSecUserByPwdResetIdxKey;
	class CFSecSecUserByDefDevIdxKey;

	class CFSecSecUserHBuff : public CFSecHPKey, public cflib::ICFLibCloneableObj
	{
	public:
		static const std::string CLASS_NAME;
	protected:
		uuid_t requiredSecUserId;
		std::string* requiredLoginId;
		std::string* requiredEMailAddress;
		uuid_t optionalEMailConfirmUuid;
		uuid_t optionalDfltDevUserId;
		std::string* optionalDfltDevName;
		std::string* requiredPasswordHash;
		uuid_t optionalPasswordResetUuid;		classcode_t classCode;

	public:
		CFSecSecUserHBuff();
		CFSecSecUserHBuff( const CFSecSecUserHBuff& src );
		virtual ~CFSecSecUserHBuff();

		virtual cflib::ICFLibCloneableObj* clone();
		virtual const uuid_ptr_t getRequiredSecUserId() const;
		virtual const uuid_ptr_t getRequiredSecUserIdReference() const;
		virtual void setRequiredSecUserId( const uuid_ptr_t value );
		virtual void generateRequiredSecUserId();

		virtual const std::string& getRequiredLoginId() const;
		virtual const std::string* getRequiredLoginIdReference() const;
		virtual void setRequiredLoginId( const std::string& value );

		virtual const std::string& getRequiredEMailAddress() const;
		virtual const std::string* getRequiredEMailAddressReference() const;
		virtual void setRequiredEMailAddress( const std::string& value );

		virtual const uuid_ptr_t getOptionalEMailConfirmUuidValue() const;
		virtual const uuid_ptr_t getOptionalEMailConfirmUuidReference() const;
		virtual const bool isOptionalEMailConfirmUuidNull() const;
		virtual void setOptionalEMailConfirmUuidNull();
		virtual void setOptionalEMailConfirmUuidValue( const uuid_ptr_t value );
		virtual void generateOptionalEMailConfirmUuid();

		virtual const uuid_ptr_t getOptionalDfltDevUserIdValue() const;
		virtual const uuid_ptr_t getOptionalDfltDevUserIdReference() const;
		virtual const bool isOptionalDfltDevUserIdNull() const;
		virtual void setOptionalDfltDevUserIdNull();
		virtual void setOptionalDfltDevUserIdValue( const uuid_ptr_t value );
		virtual void generateOptionalDfltDevUserId();

		virtual const std::string& getOptionalDfltDevNameValue() const;
		virtual const std::string* getOptionalDfltDevNameReference() const;
		virtual const bool isOptionalDfltDevNameNull() const;
		virtual void setOptionalDfltDevNameNull();
		virtual void setOptionalDfltDevNameValue( const std::string& value );

		virtual const std::string& getRequiredPasswordHash() const;
		virtual const std::string* getRequiredPasswordHashReference() const;
		virtual void setRequiredPasswordHash( const std::string& value );

		virtual const uuid_ptr_t getOptionalPasswordResetUuidValue() const;
		virtual const uuid_ptr_t getOptionalPasswordResetUuidReference() const;
		virtual const bool isOptionalPasswordResetUuidNull() const;
		virtual void setOptionalPasswordResetUuidNull();
		virtual void setOptionalPasswordResetUuidValue( const uuid_ptr_t value );
		virtual void generateOptionalPasswordResetUuid();

		virtual size_t hashCode() const;

		bool operator <( const CFSecSecUserByULoginIdxKey& rhs );
		bool operator <( const CFSecSecUserByEMConfIdxKey& rhs );
		bool operator <( const CFSecSecUserByPwdResetIdxKey& rhs );
		bool operator <( const CFSecSecUserByDefDevIdxKey& rhs );
		bool operator <( const CFSecSecUserPKey& rhs );
		bool operator <( const CFSecSecUserHPKey& rhs );
		bool operator <( const CFSecSecUserHBuff& rhs );
		bool operator <( const CFSecSecUserBuff& rhs );

		bool operator <=( const CFSecSecUserByULoginIdxKey& rhs );
		bool operator <=( const CFSecSecUserByEMConfIdxKey& rhs );
		bool operator <=( const CFSecSecUserByPwdResetIdxKey& rhs );
		bool operator <=( const CFSecSecUserByDefDevIdxKey& rhs );
		bool operator <=( const CFSecSecUserPKey& rhs );
		bool operator <=( const CFSecSecUserHPKey& rhs );
		bool operator <=( const CFSecSecUserHBuff& rhs );
		bool operator <=( const CFSecSecUserBuff& rhs );

		bool operator ==( const CFSecSecUserByULoginIdxKey& rhs );
		bool operator ==( const CFSecSecUserByEMConfIdxKey& rhs );
		bool operator ==( const CFSecSecUserByPwdResetIdxKey& rhs );
		bool operator ==( const CFSecSecUserByDefDevIdxKey& rhs );
		bool operator ==( const CFSecSecUserPKey& rhs );
		bool operator ==( const CFSecSecUserHPKey& rhs );
		bool operator ==( const CFSecSecUserHBuff& rhs );
		bool operator ==( const CFSecSecUserBuff& rhs );

		bool operator !=( const CFSecSecUserByULoginIdxKey& rhs );
		bool operator !=( const CFSecSecUserByEMConfIdxKey& rhs );
		bool operator !=( const CFSecSecUserByPwdResetIdxKey& rhs );
		bool operator !=( const CFSecSecUserByDefDevIdxKey& rhs );
		bool operator !=( const CFSecSecUserPKey& rhs );
		bool operator !=( const CFSecSecUserHPKey& rhs );
		bool operator !=( const CFSecSecUserHBuff& rhs );
		bool operator !=( const CFSecSecUserBuff& rhs );

		bool operator >=( const CFSecSecUserByULoginIdxKey& rhs );
		bool operator >=( const CFSecSecUserByEMConfIdxKey& rhs );
		bool operator >=( const CFSecSecUserByPwdResetIdxKey& rhs );
		bool operator >=( const CFSecSecUserByDefDevIdxKey& rhs );
		bool operator >=( const CFSecSecUserPKey& rhs );
		bool operator >=( const CFSecSecUserHPKey& rhs );
		bool operator >=( const CFSecSecUserHBuff& rhs );
		bool operator >=( const CFSecSecUserBuff& rhs );

		bool operator >( const CFSecSecUserByULoginIdxKey& rhs );
		bool operator >( const CFSecSecUserByEMConfIdxKey& rhs );
		bool operator >( const CFSecSecUserByPwdResetIdxKey& rhs );
		bool operator >( const CFSecSecUserByDefDevIdxKey& rhs );
		bool operator >( const CFSecSecUserPKey& rhs );
		bool operator >( const CFSecSecUserHPKey& rhs );
		bool operator >( const CFSecSecUserHBuff& rhs );
		bool operator >( const CFSecSecUserBuff& rhs );
		cfsec::CFSecSecUserHBuff operator =( cfsec::CFSecSecUserBuff& src );
		cfsec::CFSecSecUserHBuff operator =( cfsec::CFSecSecUserHBuff& src );

		virtual std::string toString();

	};
}

namespace std {

	bool operator <(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserByULoginIdxKey& rhs );
	bool operator <(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserByEMConfIdxKey& rhs );
	bool operator <(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserByPwdResetIdxKey& rhs );
	bool operator <(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserByDefDevIdxKey& rhs );
	bool operator <(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserPKey& rhs );
	bool operator <(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserHPKey& rhs );
	bool operator <(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserHBuff& rhs );
	bool operator <(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserBuff& rhs );

	bool operator <=(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserByULoginIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserByEMConfIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserByPwdResetIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserByDefDevIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserPKey& rhs );
	bool operator <=(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserHPKey& rhs );
	bool operator <=(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserHBuff& rhs );
	bool operator <=(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserBuff& rhs );

	bool operator ==(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserByULoginIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserByEMConfIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserByPwdResetIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserByDefDevIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserPKey& rhs );
	bool operator ==(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserHPKey& rhs );
	bool operator ==(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserHBuff& rhs );
	bool operator ==(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserBuff& rhs );

	bool operator !=(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserByULoginIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserByEMConfIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserByPwdResetIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserByDefDevIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserPKey& rhs );
	bool operator !=(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserHPKey& rhs );
	bool operator !=(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserHBuff& rhs );
	bool operator !=(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserBuff& rhs );

	bool operator >=(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserByULoginIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserByEMConfIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserByPwdResetIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserByDefDevIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserPKey& rhs );
	bool operator >=(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserHPKey& rhs );
	bool operator >=(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserHBuff& rhs );
	bool operator >=(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserBuff& rhs );

	bool operator >(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserByULoginIdxKey& rhs );
	bool operator >(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserByEMConfIdxKey& rhs );
	bool operator >(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserByPwdResetIdxKey& rhs );
	bool operator >(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserByDefDevIdxKey& rhs );
	bool operator >(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserPKey& rhs );
	bool operator >(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserHPKey& rhs );
	bool operator >(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserHBuff& rhs );
	bool operator >(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserBuff& rhs );

	template<> struct hash<cfsec::CFSecSecUserHBuff> {
		typedef cfsec::CFSecSecUserHBuff argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

