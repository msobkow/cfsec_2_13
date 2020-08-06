#pragma once

// Description: C++18 DbIO interface for ServiceType.

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
#include <cfsec/CFSecAuthorization.hpp>
#include <cfsec/CFSecHPKey.hpp>
#include <cfsec/CFSecServiceTypeBuff.hpp>
#include <cfsec/CFSecServiceTypePKey.hpp>
#include <cfsec/CFSecServiceTypeHBuff.hpp>
#include <cfsec/CFSecServiceTypeHPKey.hpp>
#include <cfsec/CFSecServiceTypeByUDescrIdxKey.hpp>

namespace cfsec {
	class ICFSecSchemaObj;
}

namespace cfsec {
	class ICFSecServiceTypeObj;

	class ICFSecServiceTypeTable
	{
	public:
		ICFSecServiceTypeTable();
		virtual ~ICFSecServiceTypeTable();

		virtual cfsec::CFSecServiceTypeBuff* createServiceType( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecServiceTypeBuff* Buff ) = 0;

		virtual cfsec::CFSecServiceTypeBuff* updateServiceType( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecServiceTypeBuff* Buff ) = 0;

		virtual void deleteServiceType( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecServiceTypeBuff* Buff ) = 0;
		virtual void deleteServiceTypeByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int32_t argServiceTypeId ) = 0;

		virtual void deleteServiceTypeByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecServiceTypePKey* argKey ) = 0;
		virtual void deleteServiceTypeByUDescrIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& argDescription ) = 0;

		virtual void deleteServiceTypeByUDescrIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecServiceTypeByUDescrIdxKey* argKey ) = 0;

		virtual cfsec::CFSecServiceTypeBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecServiceTypePKey* PKey ) = 0;

		virtual cfsec::CFSecServiceTypeBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecServiceTypePKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecServiceTypeBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual cfsec::CFSecServiceTypeBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int32_t ServiceTypeId ) = 0;

		virtual cfsec::CFSecServiceTypeBuff* readDerivedByUDescrIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& Description ) = 0;

		virtual cfsec::CFSecServiceTypeBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecServiceTypePKey* PKey ) = 0;

		virtual cfsec::CFSecServiceTypeBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecServiceTypePKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecServiceTypeBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual cfsec::CFSecServiceTypeBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int32_t ServiceTypeId ) = 0;

		virtual cfsec::CFSecServiceTypeBuff* readBuffByUDescrIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& Description ) = 0;

		virtual cfsec::CFSecServiceTypeBuff* readBuffByLookupUDescrIdx( const cfsec::CFSecAuthorization* Authorization, const std::string& Description,
			bool forceRead = false ) = 0;

		virtual cfsec::CFSecServiceTypeBuff* readDerivedByLookupUDescrIdx( const cfsec::CFSecAuthorization* Authorization, const std::string& Description,
			bool forceRead = false ) = 0;

		virtual void releasePreparedStatements() = 0;
	};
}
