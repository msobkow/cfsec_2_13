#pragma once

// Description: C++18 DbIO interface for SecGroup.

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
#include <cfsec/CFSecSecGroupBuff.hpp>
#include <cfsec/CFSecSecGroupPKey.hpp>
#include <cfsec/CFSecSecGroupHBuff.hpp>
#include <cfsec/CFSecSecGroupHPKey.hpp>
#include <cfsec/CFSecSecGroupByClusterIdxKey.hpp>
#include <cfsec/CFSecSecGroupByClusterVisIdxKey.hpp>
#include <cfsec/CFSecSecGroupByUNameIdxKey.hpp>

namespace cfsec {
	class ICFSecSchemaObj;
}

namespace cfsec {
	class ICFSecSecGroupObj;

	class ICFSecSecGroupTable
	{
	public:
		ICFSecSecGroupTable();
		virtual ~ICFSecSecGroupTable();

		virtual cfsec::CFSecSecGroupBuff* createSecGroup( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecSecGroupBuff* Buff ) = 0;

		virtual cfsec::CFSecSecGroupBuff* updateSecGroup( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecSecGroupBuff* Buff ) = 0;

		virtual void deleteSecGroup( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecSecGroupBuff* Buff ) = 0;
		virtual void deleteSecGroupByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const int32_t argSecGroupId ) = 0;

		virtual void deleteSecGroupByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGroupPKey* argKey ) = 0;
		virtual void deleteSecGroupByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId ) = 0;

		virtual void deleteSecGroupByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGroupByClusterIdxKey* argKey ) = 0;
		virtual void deleteSecGroupByClusterVisIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const bool argIsVisible ) = 0;

		virtual void deleteSecGroupByClusterVisIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGroupByClusterVisIdxKey* argKey ) = 0;
		virtual void deleteSecGroupByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const std::string& argName ) = 0;

		virtual void deleteSecGroupByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGroupByUNameIdxKey* argKey ) = 0;

		virtual cfsec::CFSecSecGroupBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGroupPKey* PKey ) = 0;

		virtual cfsec::CFSecSecGroupBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGroupPKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGroupBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual cfsec::CFSecSecGroupBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecGroupId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGroupBuff*> readDerivedByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGroupBuff*> readDerivedByClusterVisIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const bool IsVisible ) = 0;

		virtual cfsec::CFSecSecGroupBuff* readDerivedByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const std::string& Name ) = 0;

		virtual cfsec::CFSecSecGroupBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGroupPKey* PKey ) = 0;

		virtual cfsec::CFSecSecGroupBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGroupPKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGroupBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual cfsec::CFSecSecGroupBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecGroupId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGroupBuff*> readBuffByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGroupBuff*> readBuffByClusterVisIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const bool IsVisible ) = 0;

		virtual cfsec::CFSecSecGroupBuff* readBuffByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const std::string& Name ) = 0;

		virtual cfsec::CFSecSecGroupBuff* readBuffByLookupUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId, const std::string& Name,
			bool forceRead = false ) = 0;

		virtual cfsec::CFSecSecGroupBuff* readDerivedByLookupUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId, const std::string& Name,
			bool forceRead = false ) = 0;

		virtual void releasePreparedStatements() = 0;
	};
}
