#pragma once

// Description: C++18 Interface for an in-memory RAM DbIO declementation for SecApp.

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
#include <cfsec/ICFSecPublic.hpp>
#include <cfsecobj/ICFSecObjPublic.hpp>
#include <cfsecsaxloader/CFSecSaxLoader.hpp>

namespace cfsec {

	class CFSecRamSecAppTable
	: public virtual cfsec::ICFSecSecAppTable
	{
	protected:
		cfsec::ICFSecSchema* schema;
		std::map<cfsec::CFSecSecAppPKey,
			cfsec::CFSecSecAppBuff*>* dictByPKey;
		std::map<cfsec::CFSecSecAppByClusterIdxKey,
			std::map<cfsec::CFSecSecAppPKey,
				cfsec::CFSecSecAppBuff*>*>* dictByClusterIdx;
		std::map<cfsec::CFSecSecAppByUJEEMountIdxKey,
			cfsec::CFSecSecAppBuff*>* dictByUJEEMountIdx;
	public:
		static const std::string CLASS_NAME;
		CFSecRamSecAppTable( cfsec::ICFSecSchema* argSchema );

		virtual ~CFSecRamSecAppTable();

		virtual cfsec::CFSecSecAppBuff* createSecApp( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecSecAppBuff* Buff );

		virtual cfsec::CFSecSecAppBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecAppPKey* PKey );

		virtual cfsec::CFSecSecAppBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecAppPKey* PKey );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecAppBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecAppBuff*> readDerivedByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId );

		virtual cfsec::CFSecSecAppBuff* readDerivedByUJEEMountIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const std::string& JEEMountName );

		virtual cfsec::CFSecSecAppBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecAppId );

		virtual cfsec::CFSecSecAppBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecAppPKey* PKey );

		virtual cfsec::CFSecSecAppBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecAppPKey* PKey );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecAppBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecAppBuff*> pageAllBuff( const cfsec::CFSecAuthorization* Authorization,
			const int64_t* priorClusterId,
			const int32_t* priorSecAppId );

		virtual cfsec::CFSecSecAppBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecAppId );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecAppBuff*> readBuffByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId );

		virtual cfsec::CFSecSecAppBuff* readBuffByUJEEMountIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const std::string& JEEMountName );

		virtual cfsec::CFSecSecAppBuff* readBuffByLookupUJEEMountIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId, const std::string& JEEMountName,
			bool forceRead = false );

		virtual cfsec::CFSecSecAppBuff* readDerivedByLookupUJEEMountIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId, const std::string& JEEMountName,
			bool forceRead = false );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecAppBuff*> pageBuffByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t* priorClusterId,
			const int32_t* priorSecAppId );

		virtual cfsec::CFSecSecAppBuff* updateSecApp( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecSecAppBuff* Buff );

		virtual void deleteSecApp( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecSecAppBuff* Buff );
		virtual void deleteSecAppByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const int32_t argSecAppId );

		virtual void deleteSecAppByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecAppPKey* argKey );

		virtual void deleteSecAppByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId );

		virtual void deleteSecAppByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecAppByClusterIdxKey* argKey );

		virtual void deleteSecAppByUJEEMountIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const std::string& argJEEMountName );

		virtual void deleteSecAppByUJEEMountIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecAppByUJEEMountIdxKey* argKey );


		virtual void releasePreparedStatements();

	};
}
