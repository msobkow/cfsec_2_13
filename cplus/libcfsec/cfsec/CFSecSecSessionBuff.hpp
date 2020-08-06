#pragma once

// Description: C++18 specification for a SecSession buffer object.

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

#include <cfsec/ICFSecSchema.hpp>

namespace cfsec {

	class CFSecSecSessionPKey;
	class CFSecSecSessionHPKey;
	class CFSecSecSessionHBuff;
	class CFSecSecSessionBySecUserIdxKey;
	class CFSecSecSessionBySecDevIdxKey;
	class CFSecSecSessionByStartIdxKey;
	class CFSecSecSessionByFinishIdxKey;
	class CFSecSecSessionBySecProxyIdxKey;

	class CFSecSecSessionBuff : public cflib::ICFLibCloneableObj
	{
	public:
		static const std::string GENDEFNAME;
		static const classcode_t CLASS_CODE;
		static const std::string CLASS_NAME;
		static const std::string COLNAME_SECSESSIONID;
		static const std::string COLNAME_SECUSERID;
		static const std::string COLNAME_SECDEVNAME;
		static const std::string COLNAME_START;
		static const std::string COLNAME_FINISH;
		static const std::string COLNAME_SECPROXYID;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;
		static const std::string SECDEVNAME_INIT_VALUE;
		static std::chrono::system_clock::time_point START_INIT_VALUE;
		static const std::string::size_type SECDEVNAME_MAX_LEN;
	protected:
		uuid_t requiredSecSessionId;
		uuid_t requiredSecUserId;
		std::string* optionalSecDevName;
		std::chrono::system_clock::time_point requiredStart;
		std::chrono::system_clock::time_point* optionalFinish;
		uuid_t optionalSecProxyId;
		int32_t requiredRevision;
	public:
		CFSecSecSessionBuff();

		CFSecSecSessionBuff( const CFSecSecSessionBuff& src );

		virtual ~CFSecSecSessionBuff();

		virtual const std::string& getClassName() const;
		virtual cflib::ICFLibCloneableObj* clone();
		virtual const classcode_t getClassCode() const;

		virtual bool implementsClassCode( const classcode_t argClassCode );
		virtual const uuid_ptr_t getRequiredSecSessionId() const;
		virtual const uuid_ptr_t getRequiredSecSessionIdReference() const;
		virtual void setRequiredSecSessionId( const uuid_ptr_t value );
		virtual void generateRequiredSecSessionId();

		virtual const uuid_ptr_t getRequiredSecUserId() const;
		virtual const uuid_ptr_t getRequiredSecUserIdReference() const;
		virtual void setRequiredSecUserId( const uuid_ptr_t value );
		virtual void generateRequiredSecUserId();

		virtual const std::string& getOptionalSecDevNameValue() const;
		virtual const std::string* getOptionalSecDevNameReference() const;
		virtual const bool isOptionalSecDevNameNull() const;
		virtual void setOptionalSecDevNameNull();
		virtual void setOptionalSecDevNameValue( const std::string& value );

		virtual const std::chrono::system_clock::time_point& getRequiredStart() const;
		virtual const std::chrono::system_clock::time_point* getRequiredStartReference() const;
		virtual void setRequiredStart( const std::chrono::system_clock::time_point& value );

		virtual const std::chrono::system_clock::time_point& getOptionalFinishValue() const;
		virtual const std::chrono::system_clock::time_point* getOptionalFinishReference() const;
		virtual const bool isOptionalFinishNull() const;
		virtual void setOptionalFinishNull();
		virtual void setOptionalFinishValue( const std::chrono::system_clock::time_point& value );

		virtual const uuid_ptr_t getOptionalSecProxyIdValue() const;
		virtual const uuid_ptr_t getOptionalSecProxyIdReference() const;
		virtual const bool isOptionalSecProxyIdNull() const;
		virtual void setOptionalSecProxyIdNull();
		virtual void setOptionalSecProxyIdValue( const uuid_ptr_t value );
		virtual void generateOptionalSecProxyId();

		virtual int32_t getRequiredRevision() const;
		virtual void setRequiredRevision( int32_t value );

		virtual size_t hashCode() const;

		bool operator <( const CFSecSecSessionBySecUserIdxKey& rhs );
		bool operator <( const CFSecSecSessionBySecDevIdxKey& rhs );
		bool operator <( const CFSecSecSessionByStartIdxKey& rhs );
		bool operator <( const CFSecSecSessionByFinishIdxKey& rhs );
		bool operator <( const CFSecSecSessionBySecProxyIdxKey& rhs );
		bool operator <( const CFSecSecSessionPKey& rhs );
		bool operator <( const CFSecSecSessionHPKey& rhs );
		bool operator <( const CFSecSecSessionHBuff& rhs );
		bool operator <( const CFSecSecSessionBuff& rhs );

		bool operator <=( const CFSecSecSessionBySecUserIdxKey& rhs );
		bool operator <=( const CFSecSecSessionBySecDevIdxKey& rhs );
		bool operator <=( const CFSecSecSessionByStartIdxKey& rhs );
		bool operator <=( const CFSecSecSessionByFinishIdxKey& rhs );
		bool operator <=( const CFSecSecSessionBySecProxyIdxKey& rhs );
		bool operator <=( const CFSecSecSessionPKey& rhs );
		bool operator <=( const CFSecSecSessionHPKey& rhs );
		bool operator <=( const CFSecSecSessionHBuff& rhs );
		bool operator <=( const CFSecSecSessionBuff& rhs );

		bool operator ==( const CFSecSecSessionBySecUserIdxKey& rhs );
		bool operator ==( const CFSecSecSessionBySecDevIdxKey& rhs );
		bool operator ==( const CFSecSecSessionByStartIdxKey& rhs );
		bool operator ==( const CFSecSecSessionByFinishIdxKey& rhs );
		bool operator ==( const CFSecSecSessionBySecProxyIdxKey& rhs );
		bool operator ==( const CFSecSecSessionPKey& rhs );
		bool operator ==( const CFSecSecSessionHPKey& rhs );
		bool operator ==( const CFSecSecSessionHBuff& rhs );
		bool operator ==( const CFSecSecSessionBuff& rhs );

		bool operator !=( const CFSecSecSessionBySecUserIdxKey& rhs );
		bool operator !=( const CFSecSecSessionBySecDevIdxKey& rhs );
		bool operator !=( const CFSecSecSessionByStartIdxKey& rhs );
		bool operator !=( const CFSecSecSessionByFinishIdxKey& rhs );
		bool operator !=( const CFSecSecSessionBySecProxyIdxKey& rhs );
		bool operator !=( const CFSecSecSessionPKey& rhs );
		bool operator !=( const CFSecSecSessionHPKey& rhs );
		bool operator !=( const CFSecSecSessionHBuff& rhs );
		bool operator !=( const CFSecSecSessionBuff& rhs );

		bool operator >=( const CFSecSecSessionBySecUserIdxKey& rhs );
		bool operator >=( const CFSecSecSessionBySecDevIdxKey& rhs );
		bool operator >=( const CFSecSecSessionByStartIdxKey& rhs );
		bool operator >=( const CFSecSecSessionByFinishIdxKey& rhs );
		bool operator >=( const CFSecSecSessionBySecProxyIdxKey& rhs );
		bool operator >=( const CFSecSecSessionPKey& rhs );
		bool operator >=( const CFSecSecSessionHPKey& rhs );
		bool operator >=( const CFSecSecSessionHBuff& rhs );
		bool operator >=( const CFSecSecSessionBuff& rhs );

		bool operator >( const CFSecSecSessionBySecUserIdxKey& rhs );
		bool operator >( const CFSecSecSessionBySecDevIdxKey& rhs );
		bool operator >( const CFSecSecSessionByStartIdxKey& rhs );
		bool operator >( const CFSecSecSessionByFinishIdxKey& rhs );
		bool operator >( const CFSecSecSessionBySecProxyIdxKey& rhs );
		bool operator >( const CFSecSecSessionPKey& rhs );
		bool operator >( const CFSecSecSessionHPKey& rhs );
		bool operator >( const CFSecSecSessionHBuff& rhs );
		bool operator >( const CFSecSecSessionBuff& rhs );
		cfsec::CFSecSecSessionBuff operator =( cfsec::CFSecSecSessionBuff& src );
		cfsec::CFSecSecSessionBuff operator =( cfsec::CFSecSecSessionHBuff& src );

		virtual std::string toString();
	};
}

namespace std {

	bool operator <(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionBySecUserIdxKey& rhs );
	bool operator <(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionBySecDevIdxKey& rhs );
	bool operator <(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionByStartIdxKey& rhs );
	bool operator <(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionByFinishIdxKey& rhs );
	bool operator <(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionBySecProxyIdxKey& rhs );
	bool operator <(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionPKey& rhs );
	bool operator <(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionHPKey& rhs );
	bool operator <(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionHBuff& rhs );
	bool operator <(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionBuff& rhs );

	bool operator <=(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionBySecUserIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionBySecDevIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionByStartIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionByFinishIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionBySecProxyIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionPKey& rhs );
	bool operator <=(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionHPKey& rhs );
	bool operator <=(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionHBuff& rhs );
	bool operator <=(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionBuff& rhs );

	bool operator ==(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionBySecUserIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionBySecDevIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionByStartIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionByFinishIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionBySecProxyIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionPKey& rhs );
	bool operator ==(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionHPKey& rhs );
	bool operator ==(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionHBuff& rhs );
	bool operator ==(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionBuff& rhs );

	bool operator !=(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionBySecUserIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionBySecDevIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionByStartIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionByFinishIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionBySecProxyIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionPKey& rhs );
	bool operator !=(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionHPKey& rhs );
	bool operator !=(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionHBuff& rhs );
	bool operator !=(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionBuff& rhs );

	bool operator >=(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionBySecUserIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionBySecDevIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionByStartIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionByFinishIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionBySecProxyIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionPKey& rhs );
	bool operator >=(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionHPKey& rhs );
	bool operator >=(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionHBuff& rhs );
	bool operator >=(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionBuff& rhs );

	bool operator >(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionBySecUserIdxKey& rhs );

	bool operator >(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionBySecDevIdxKey& rhs );

	bool operator >(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionByStartIdxKey& rhs );

	bool operator >(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionByFinishIdxKey& rhs );

	bool operator >(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionBySecProxyIdxKey& rhs );

	bool operator >(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionPKey& rhs );
	bool operator >(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionHPKey& rhs );
	bool operator >(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionHBuff& rhs );
	bool operator >(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionBuff& rhs );

	template<> struct hash<cfsec::CFSecSecSessionBuff> {
		typedef cfsec::CFSecSecSessionBuff argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

