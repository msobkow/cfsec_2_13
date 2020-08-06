#pragma once

// Description: C++18 specification of a SecDevice history primary key object.

/*
 *	org.msscf.msscf.CFSec
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFSec 2.13 Security Essentials
 *	
 *	Copyright 2020 Mark Stephen Sobkow
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
 *	Please contact Mark Stephen Sobkow at msobkow@sasktel.net for commercial licensing.
 *
 *	Manufactured by MSS Code Factory 2.12
 */
#include <cflib/ICFLibPublic.hpp>

#include <cfsec/CFSecHPKey.hpp>
#include <cfsec/ICFSecSchema.hpp>

namespace cfsec {

	class CFSecSecDevicePKey;
	class CFSecSecDeviceBuff;
	class CFSecSecDeviceHBuff;

	class CFSecSecDeviceHPKey : public CFSecHPKey
	{
	protected:

		uuid_t requiredSecUserId;
		std::string* requiredDevName;
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;

		CFSecSecDeviceHPKey();
		CFSecSecDeviceHPKey( const CFSecSecDeviceHPKey& src );
		virtual ~CFSecSecDeviceHPKey();

		virtual const uuid_ptr_t getRequiredSecUserId() const;
		virtual const uuid_ptr_t getRequiredSecUserIdReference() const;
		virtual void setRequiredSecUserId( const uuid_ptr_t value );
		virtual void generateRequiredSecUserId();

		virtual const std::string& getRequiredDevName() const;
		virtual const std::string* getRequiredDevNameReference() const;
		virtual void setRequiredDevName( const std::string& value );

		virtual size_t hashCode() const;

		virtual std::string toString();

		bool operator <( const CFSecSecDevicePKey& rhs );
		bool operator <( const CFSecSecDeviceHPKey& rhs );
		bool operator <( const CFSecSecDeviceHBuff& rhs );
		bool operator <( const CFSecSecDeviceBuff& rhs );


		bool operator <=( const CFSecSecDevicePKey& rhs );
		bool operator <=( const CFSecSecDeviceHPKey& rhs );
		bool operator <=( const CFSecSecDeviceHBuff& rhs );
		bool operator <=( const CFSecSecDeviceBuff& rhs );


		bool operator ==( const CFSecSecDevicePKey& rhs );
		bool operator ==( const CFSecSecDeviceHPKey& rhs );
		bool operator ==( const CFSecSecDeviceHBuff& rhs );
		bool operator ==( const CFSecSecDeviceBuff& rhs );


		bool operator !=( const CFSecSecDevicePKey& rhs );
		bool operator !=( const CFSecSecDeviceHPKey& rhs );
		bool operator !=( const CFSecSecDeviceHBuff& rhs );
		bool operator !=( const CFSecSecDeviceBuff& rhs );


		bool operator >=( const CFSecSecDevicePKey& rhs );
		bool operator >=( const CFSecSecDeviceHPKey& rhs );
		bool operator >=( const CFSecSecDeviceHBuff& rhs );
		bool operator >=( const CFSecSecDeviceBuff& rhs );


		bool operator >( const CFSecSecDevicePKey& rhs );
		bool operator >( const CFSecSecDeviceHPKey& rhs );
		bool operator >( const CFSecSecDeviceHBuff& rhs );
		bool operator >( const CFSecSecDeviceBuff& rhs );

		cfsec::CFSecSecDeviceHPKey operator =( cfsec::CFSecSecDevicePKey& src );
		cfsec::CFSecSecDeviceHPKey operator =( cfsec::CFSecSecDeviceHPKey& src );
		cfsec::CFSecSecDeviceHPKey operator =( cfsec::CFSecSecDeviceBuff& src );
		cfsec::CFSecSecDeviceHPKey operator =( cfsec::CFSecSecDeviceHBuff& src );

	};
}


namespace std {

	bool operator <(const  cfsec::CFSecSecDeviceHPKey& lhs, const cfsec::CFSecSecDevicePKey& rhs );
	bool operator <(const  cfsec::CFSecSecDeviceHPKey& lhs, const cfsec::CFSecSecDeviceHPKey& rhs );
	bool operator <(const  cfsec::CFSecSecDeviceHPKey& lhs, const cfsec::CFSecSecDeviceHBuff& rhs );
	bool operator <(const  cfsec::CFSecSecDeviceHPKey& lhs, const cfsec::CFSecSecDeviceBuff& rhs );


	bool operator <=(const  cfsec::CFSecSecDeviceHPKey& lhs, const cfsec::CFSecSecDevicePKey& rhs );
	bool operator <=(const  cfsec::CFSecSecDeviceHPKey& lhs, const cfsec::CFSecSecDeviceHPKey& rhs );
	bool operator <=(const  cfsec::CFSecSecDeviceHPKey& lhs, const cfsec::CFSecSecDeviceHBuff& rhs );
	bool operator <=(const  cfsec::CFSecSecDeviceHPKey& lhs, const cfsec::CFSecSecDeviceBuff& rhs );


	bool operator ==(const  cfsec::CFSecSecDeviceHPKey& lhs, const cfsec::CFSecSecDevicePKey& rhs );
	bool operator ==(const  cfsec::CFSecSecDeviceHPKey& lhs, const cfsec::CFSecSecDeviceHPKey& rhs );
	bool operator ==(const  cfsec::CFSecSecDeviceHPKey& lhs, const cfsec::CFSecSecDeviceHBuff& rhs );
	bool operator ==(const  cfsec::CFSecSecDeviceHPKey& lhs, const cfsec::CFSecSecDeviceBuff& rhs );


	bool operator !=(const  cfsec::CFSecSecDeviceHPKey& lhs, const cfsec::CFSecSecDevicePKey& rhs );
	bool operator !=(const  cfsec::CFSecSecDeviceHPKey& lhs, const cfsec::CFSecSecDeviceHPKey& rhs );
	bool operator !=(const  cfsec::CFSecSecDeviceHPKey& lhs, const cfsec::CFSecSecDeviceHBuff& rhs );
	bool operator !=(const  cfsec::CFSecSecDeviceHPKey& lhs, const cfsec::CFSecSecDeviceBuff& rhs );


	bool operator >=(const  cfsec::CFSecSecDeviceHPKey& lhs, const cfsec::CFSecSecDevicePKey& rhs );
	bool operator >=(const  cfsec::CFSecSecDeviceHPKey& lhs, const cfsec::CFSecSecDeviceHPKey& rhs );
	bool operator >=(const  cfsec::CFSecSecDeviceHPKey& lhs, const cfsec::CFSecSecDeviceHBuff& rhs );
	bool operator >=(const  cfsec::CFSecSecDeviceHPKey& lhs, const cfsec::CFSecSecDeviceBuff& rhs );


	bool operator >(const  cfsec::CFSecSecDeviceHPKey& lhs, const cfsec::CFSecSecDevicePKey& rhs );
	bool operator >(const  cfsec::CFSecSecDeviceHPKey& lhs, const cfsec::CFSecSecDeviceHPKey& rhs );
	bool operator >(const  cfsec::CFSecSecDeviceHPKey& lhs, const cfsec::CFSecSecDeviceHBuff& rhs );
	bool operator >(const  cfsec::CFSecSecDeviceHPKey& lhs, const cfsec::CFSecSecDeviceBuff& rhs );


	template<> struct hash<cfsec::CFSecSecDeviceHPKey> {
		typedef cfsec::CFSecSecDeviceHPKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

