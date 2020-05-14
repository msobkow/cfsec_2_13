#pragma once

// Description: C++18 specification for a SecUser buffer object.

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

	class CFSecSecUserPKey;
	class CFSecSecUserHPKey;
	class CFSecSecUserHBuff;
	class CFSecSecUserByULoginIdxKey;
	class CFSecSecUserByEMConfIdxKey;
	class CFSecSecUserByPwdResetIdxKey;
	class CFSecSecUserByDefDevIdxKey;

	class CFSecSecUserBuff : public cflib::ICFLibCloneableObj
	{
	public:
		static const std::string GENDEFNAME;
		static const classcode_t CLASS_CODE;
		static const std::string CLASS_NAME;
		static const std::string COLNAME_SECUSERID;
		static const std::string COLNAME_LOGINID;
		static const std::string COLNAME_EMAILADDRESS;
		static const std::string COLNAME_EMAILCONFIRMUUID;
		static const std::string COLNAME_DFLTDEVUSERID;
		static const std::string COLNAME_DFLTDEVNAME;
		static const std::string COLNAME_PASSWORDHASH;
		static const std::string COLNAME_PASSWORDRESETUUID;
		static const char* S_INIT_CREATEDBY;
		static const char* S_INIT_UPDATEDBY;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;
		static const std::string LOGINID_INIT_VALUE;
		static const std::string EMAILADDRESS_INIT_VALUE;
		static const std::string DFLTDEVNAME_INIT_VALUE;
		static const std::string PASSWORDHASH_INIT_VALUE;
		static const std::string::size_type LOGINID_MAX_LEN;
		static const std::string::size_type EMAILADDRESS_MAX_LEN;
		static const std::string::size_type DFLTDEVNAME_MAX_LEN;
		static const std::string::size_type PASSWORDHASH_MAX_LEN;
	protected:
		uuid_t createdByUserId;
		std::chrono::system_clock::time_point createdAt;
		uuid_t updatedByUserId;
		std::chrono::system_clock::time_point updatedAt;
		uuid_t requiredSecUserId;
		std::string* requiredLoginId;
		std::string* requiredEMailAddress;
		uuid_t optionalEMailConfirmUuid;
		uuid_t optionalDfltDevUserId;
		std::string* optionalDfltDevName;
		std::string* requiredPasswordHash;
		uuid_t optionalPasswordResetUuid;
		int32_t requiredRevision;
	public:
		CFSecSecUserBuff();

		CFSecSecUserBuff( const CFSecSecUserBuff& src );

		virtual ~CFSecSecUserBuff();

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

		virtual int32_t getRequiredRevision() const;
		virtual void setRequiredRevision( int32_t value );

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
		cfsec::CFSecSecUserBuff operator =( cfsec::CFSecSecUserBuff& src );
		cfsec::CFSecSecUserBuff operator =( cfsec::CFSecSecUserHBuff& src );

		virtual std::string toString();
	};
}

namespace std {

	bool operator <(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserByULoginIdxKey& rhs );
	bool operator <(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserByEMConfIdxKey& rhs );
	bool operator <(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserByPwdResetIdxKey& rhs );
	bool operator <(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserByDefDevIdxKey& rhs );
	bool operator <(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserPKey& rhs );
	bool operator <(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserHPKey& rhs );
	bool operator <(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserHBuff& rhs );
	bool operator <(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserBuff& rhs );

	bool operator <=(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserByULoginIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserByEMConfIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserByPwdResetIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserByDefDevIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserPKey& rhs );
	bool operator <=(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserHPKey& rhs );
	bool operator <=(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserHBuff& rhs );
	bool operator <=(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserBuff& rhs );

	bool operator ==(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserByULoginIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserByEMConfIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserByPwdResetIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserByDefDevIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserPKey& rhs );
	bool operator ==(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserHPKey& rhs );
	bool operator ==(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserHBuff& rhs );
	bool operator ==(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserBuff& rhs );

	bool operator !=(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserByULoginIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserByEMConfIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserByPwdResetIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserByDefDevIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserPKey& rhs );
	bool operator !=(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserHPKey& rhs );
	bool operator !=(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserHBuff& rhs );
	bool operator !=(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserBuff& rhs );

	bool operator >=(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserByULoginIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserByEMConfIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserByPwdResetIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserByDefDevIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserPKey& rhs );
	bool operator >=(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserHPKey& rhs );
	bool operator >=(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserHBuff& rhs );
	bool operator >=(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserBuff& rhs );

	bool operator >(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserByULoginIdxKey& rhs );

	bool operator >(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserByEMConfIdxKey& rhs );

	bool operator >(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserByPwdResetIdxKey& rhs );

	bool operator >(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserByDefDevIdxKey& rhs );

	bool operator >(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserPKey& rhs );
	bool operator >(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserHPKey& rhs );
	bool operator >(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserHBuff& rhs );
	bool operator >(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserBuff& rhs );

	template<> struct hash<cfsec::CFSecSecUserBuff> {
		typedef cfsec::CFSecSecUserBuff argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

