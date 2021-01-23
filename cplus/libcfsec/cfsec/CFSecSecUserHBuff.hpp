#pragma once

// Description: C++18 specification of a SecUser history buffer object.

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

