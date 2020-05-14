#pragma once

// Description: C++18 specification for a SecDevice buffer object.

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

	class CFSecSecDevicePKey;
	class CFSecSecDeviceHPKey;
	class CFSecSecDeviceHBuff;
	class CFSecSecDeviceByNameIdxKey;
	class CFSecSecDeviceByUserIdxKey;

	class CFSecSecDeviceBuff : public cflib::ICFLibCloneableObj
	{
	public:
		static const std::string GENDEFNAME;
		static const classcode_t CLASS_CODE;
		static const std::string CLASS_NAME;
		static const std::string COLNAME_SECUSERID;
		static const std::string COLNAME_DEVNAME;
		static const std::string COLNAME_PUBKEY;
		static const char* S_INIT_CREATEDBY;
		static const char* S_INIT_UPDATEDBY;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;
		static const std::string DEVNAME_INIT_VALUE;
		static const std::string::size_type DEVNAME_MAX_LEN;
		static const std::string::size_type PUBKEY_MAX_LEN;
	protected:
		uuid_t createdByUserId;
		std::chrono::system_clock::time_point createdAt;
		uuid_t updatedByUserId;
		std::chrono::system_clock::time_point updatedAt;
		uuid_t requiredSecUserId;
		std::string* requiredDevName;
		std::string* optionalPubKey;
		int32_t requiredRevision;
	public:
		CFSecSecDeviceBuff();

		CFSecSecDeviceBuff( const CFSecSecDeviceBuff& src );

		virtual ~CFSecSecDeviceBuff();

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

		virtual const std::string& getRequiredDevName() const;
		virtual const std::string* getRequiredDevNameReference() const;
		virtual void setRequiredDevName( const std::string& value );

		virtual const std::string& getOptionalPubKeyValue() const;
		virtual const std::string* getOptionalPubKeyReference() const;
		virtual const bool isOptionalPubKeyNull() const;
		virtual void setOptionalPubKeyNull();
		virtual void setOptionalPubKeyValue( const std::string& value );

		virtual int32_t getRequiredRevision() const;
		virtual void setRequiredRevision( int32_t value );

		virtual size_t hashCode() const;

		bool operator <( const CFSecSecDeviceByNameIdxKey& rhs );
		bool operator <( const CFSecSecDeviceByUserIdxKey& rhs );
		bool operator <( const CFSecSecDevicePKey& rhs );
		bool operator <( const CFSecSecDeviceHPKey& rhs );
		bool operator <( const CFSecSecDeviceHBuff& rhs );
		bool operator <( const CFSecSecDeviceBuff& rhs );

		bool operator <=( const CFSecSecDeviceByNameIdxKey& rhs );
		bool operator <=( const CFSecSecDeviceByUserIdxKey& rhs );
		bool operator <=( const CFSecSecDevicePKey& rhs );
		bool operator <=( const CFSecSecDeviceHPKey& rhs );
		bool operator <=( const CFSecSecDeviceHBuff& rhs );
		bool operator <=( const CFSecSecDeviceBuff& rhs );

		bool operator ==( const CFSecSecDeviceByNameIdxKey& rhs );
		bool operator ==( const CFSecSecDeviceByUserIdxKey& rhs );
		bool operator ==( const CFSecSecDevicePKey& rhs );
		bool operator ==( const CFSecSecDeviceHPKey& rhs );
		bool operator ==( const CFSecSecDeviceHBuff& rhs );
		bool operator ==( const CFSecSecDeviceBuff& rhs );

		bool operator !=( const CFSecSecDeviceByNameIdxKey& rhs );
		bool operator !=( const CFSecSecDeviceByUserIdxKey& rhs );
		bool operator !=( const CFSecSecDevicePKey& rhs );
		bool operator !=( const CFSecSecDeviceHPKey& rhs );
		bool operator !=( const CFSecSecDeviceHBuff& rhs );
		bool operator !=( const CFSecSecDeviceBuff& rhs );

		bool operator >=( const CFSecSecDeviceByNameIdxKey& rhs );
		bool operator >=( const CFSecSecDeviceByUserIdxKey& rhs );
		bool operator >=( const CFSecSecDevicePKey& rhs );
		bool operator >=( const CFSecSecDeviceHPKey& rhs );
		bool operator >=( const CFSecSecDeviceHBuff& rhs );
		bool operator >=( const CFSecSecDeviceBuff& rhs );

		bool operator >( const CFSecSecDeviceByNameIdxKey& rhs );
		bool operator >( const CFSecSecDeviceByUserIdxKey& rhs );
		bool operator >( const CFSecSecDevicePKey& rhs );
		bool operator >( const CFSecSecDeviceHPKey& rhs );
		bool operator >( const CFSecSecDeviceHBuff& rhs );
		bool operator >( const CFSecSecDeviceBuff& rhs );
		cfsec::CFSecSecDeviceBuff operator =( cfsec::CFSecSecDeviceBuff& src );
		cfsec::CFSecSecDeviceBuff operator =( cfsec::CFSecSecDeviceHBuff& src );

		virtual std::string toString();
	};
}

namespace std {

	bool operator <(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDeviceByNameIdxKey& rhs );
	bool operator <(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDeviceByUserIdxKey& rhs );
	bool operator <(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDevicePKey& rhs );
	bool operator <(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDeviceHPKey& rhs );
	bool operator <(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDeviceHBuff& rhs );
	bool operator <(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDeviceBuff& rhs );

	bool operator <=(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDeviceByNameIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDeviceByUserIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDevicePKey& rhs );
	bool operator <=(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDeviceHPKey& rhs );
	bool operator <=(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDeviceHBuff& rhs );
	bool operator <=(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDeviceBuff& rhs );

	bool operator ==(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDeviceByNameIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDeviceByUserIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDevicePKey& rhs );
	bool operator ==(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDeviceHPKey& rhs );
	bool operator ==(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDeviceHBuff& rhs );
	bool operator ==(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDeviceBuff& rhs );

	bool operator !=(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDeviceByNameIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDeviceByUserIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDevicePKey& rhs );
	bool operator !=(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDeviceHPKey& rhs );
	bool operator !=(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDeviceHBuff& rhs );
	bool operator !=(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDeviceBuff& rhs );

	bool operator >=(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDeviceByNameIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDeviceByUserIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDevicePKey& rhs );
	bool operator >=(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDeviceHPKey& rhs );
	bool operator >=(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDeviceHBuff& rhs );
	bool operator >=(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDeviceBuff& rhs );

	bool operator >(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDeviceByNameIdxKey& rhs );

	bool operator >(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDeviceByUserIdxKey& rhs );

	bool operator >(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDevicePKey& rhs );
	bool operator >(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDeviceHPKey& rhs );
	bool operator >(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDeviceHBuff& rhs );
	bool operator >(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDeviceBuff& rhs );

	template<> struct hash<cfsec::CFSecSecDeviceBuff> {
		typedef cfsec::CFSecSecDeviceBuff argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

