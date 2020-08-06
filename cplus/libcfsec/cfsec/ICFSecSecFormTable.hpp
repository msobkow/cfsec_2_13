#pragma once

// Description: C++18 DbIO interface for SecForm.

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
#include <cfsec/CFSecSecFormBuff.hpp>
#include <cfsec/CFSecSecFormPKey.hpp>
#include <cfsec/CFSecSecFormHBuff.hpp>
#include <cfsec/CFSecSecFormHPKey.hpp>
#include <cfsec/CFSecSecFormByClusterIdxKey.hpp>
#include <cfsec/CFSecSecFormBySecAppIdxKey.hpp>
#include <cfsec/CFSecSecFormByUJEEServletIdxKey.hpp>

namespace cfsec {
	class ICFSecSchemaObj;
}

namespace cfsec {
	class ICFSecSecFormObj;

	class ICFSecSecFormTable
	{
	public:
		ICFSecSecFormTable();
		virtual ~ICFSecSecFormTable();

		virtual cfsec::CFSecSecFormBuff* createSecForm( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecSecFormBuff* Buff ) = 0;

		virtual cfsec::CFSecSecFormBuff* updateSecForm( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecSecFormBuff* Buff ) = 0;

		virtual void deleteSecForm( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecSecFormBuff* Buff ) = 0;
		virtual void deleteSecFormByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const int32_t argSecFormId ) = 0;

		virtual void deleteSecFormByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecFormPKey* argKey ) = 0;
		virtual void deleteSecFormByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId ) = 0;

		virtual void deleteSecFormByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecFormByClusterIdxKey* argKey ) = 0;
		virtual void deleteSecFormBySecAppIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const int32_t argSecAppId ) = 0;

		virtual void deleteSecFormBySecAppIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecFormBySecAppIdxKey* argKey ) = 0;
		virtual void deleteSecFormByUJEEServletIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const int32_t argSecAppId,
			const std::string& argJEEServletMapName ) = 0;

		virtual void deleteSecFormByUJEEServletIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecFormByUJEEServletIdxKey* argKey ) = 0;

		virtual cfsec::CFSecSecFormBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecFormPKey* PKey ) = 0;

		virtual cfsec::CFSecSecFormBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecFormPKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecFormBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual cfsec::CFSecSecFormBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecFormId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecFormBuff*> readDerivedByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecFormBuff*> readDerivedBySecAppIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecAppId ) = 0;

		virtual cfsec::CFSecSecFormBuff* readDerivedByUJEEServletIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecAppId,
			const std::string& JEEServletMapName ) = 0;

		virtual cfsec::CFSecSecFormBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecFormPKey* PKey ) = 0;

		virtual cfsec::CFSecSecFormBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecFormPKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecFormBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecFormBuff*> pageAllBuff( const cfsec::CFSecAuthorization* Authorization,
			const int64_t* priorClusterId,
			const int32_t* priorSecFormId ) = 0;

		virtual cfsec::CFSecSecFormBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecFormId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecFormBuff*> readBuffByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecFormBuff*> readBuffBySecAppIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecAppId ) = 0;

		virtual cfsec::CFSecSecFormBuff* readBuffByUJEEServletIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecAppId,
			const std::string& JEEServletMapName ) = 0;

		virtual cfsec::CFSecSecFormBuff* readBuffByLookupUJEEServletIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecAppId, const std::string& JEEServletMapName,
			bool forceRead = false ) = 0;

		virtual cfsec::CFSecSecFormBuff* readDerivedByLookupUJEEServletIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecAppId, const std::string& JEEServletMapName,
			bool forceRead = false ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecFormBuff*> pageBuffByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t* priorClusterId,
			const int32_t* priorSecFormId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecFormBuff*> pageBuffBySecAppIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecAppId,
			const int64_t* priorClusterId,
			const int32_t* priorSecFormId ) = 0;

		virtual void releasePreparedStatements() = 0;
	};
}
