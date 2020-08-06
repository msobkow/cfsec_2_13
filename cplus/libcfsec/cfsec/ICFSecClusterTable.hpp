#pragma once

// Description: C++18 DbIO interface for Cluster.

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
#include <cfsec/CFSecClusterBuff.hpp>
#include <cfsec/CFSecClusterPKey.hpp>
#include <cfsec/CFSecClusterHBuff.hpp>
#include <cfsec/CFSecClusterHPKey.hpp>
#include <cfsec/CFSecClusterByUDomNameIdxKey.hpp>
#include <cfsec/CFSecClusterByUDescrIdxKey.hpp>

namespace cfsec {
	class ICFSecSchemaObj;
}

namespace cfsec {
	class ICFSecClusterObj;

	class ICFSecClusterTable
	{
	public:
		ICFSecClusterTable();
		virtual ~ICFSecClusterTable();

		virtual int32_t nextSecAppIdGen( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecClusterPKey* PKey ) = 0;

		virtual int32_t nextSecAppIdGen( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argId ) = 0;

		virtual int32_t nextSecFormIdGen( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecClusterPKey* PKey ) = 0;

		virtual int32_t nextSecFormIdGen( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argId ) = 0;

		virtual int32_t nextSecGroupIdGen( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecClusterPKey* PKey ) = 0;

		virtual int32_t nextSecGroupIdGen( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argId ) = 0;

		virtual int64_t nextHostNodeIdGen( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecClusterPKey* PKey ) = 0;

		virtual int64_t nextHostNodeIdGen( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argId ) = 0;

		virtual int64_t nextSecGroupFormIdGen( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecClusterPKey* PKey ) = 0;

		virtual int64_t nextSecGroupFormIdGen( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argId ) = 0;

		virtual int64_t nextSecGrpIncIdGen( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecClusterPKey* PKey ) = 0;

		virtual int64_t nextSecGrpIncIdGen( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argId ) = 0;

		virtual int64_t nextSecGrpMembIdGen( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecClusterPKey* PKey ) = 0;

		virtual int64_t nextSecGrpMembIdGen( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argId ) = 0;

		virtual int64_t nextServiceIdGen( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecClusterPKey* PKey ) = 0;

		virtual int64_t nextServiceIdGen( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argId ) = 0;

		virtual cfsec::CFSecClusterBuff* createCluster( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecClusterBuff* Buff ) = 0;

		virtual cfsec::CFSecClusterBuff* updateCluster( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecClusterBuff* Buff ) = 0;

		virtual void deleteCluster( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecClusterBuff* Buff ) = 0;
		virtual void deleteClusterByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argId ) = 0;

		virtual void deleteClusterByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecClusterPKey* argKey ) = 0;
		virtual void deleteClusterByUDomNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& argFullDomName ) = 0;

		virtual void deleteClusterByUDomNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecClusterByUDomNameIdxKey* argKey ) = 0;
		virtual void deleteClusterByUDescrIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& argDescription ) = 0;

		virtual void deleteClusterByUDescrIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecClusterByUDescrIdxKey* argKey ) = 0;

		virtual cfsec::CFSecClusterBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecClusterPKey* PKey ) = 0;

		virtual cfsec::CFSecClusterBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecClusterPKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecClusterBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual cfsec::CFSecClusterBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t Id ) = 0;

		virtual cfsec::CFSecClusterBuff* readDerivedByUDomNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& FullDomName ) = 0;

		virtual cfsec::CFSecClusterBuff* readDerivedByUDescrIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& Description ) = 0;

		virtual cfsec::CFSecClusterBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecClusterPKey* PKey ) = 0;

		virtual cfsec::CFSecClusterBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecClusterPKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecClusterBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecClusterBuff*> pageAllBuff( const cfsec::CFSecAuthorization* Authorization,
			const int64_t* priorId ) = 0;

		virtual cfsec::CFSecClusterBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t Id ) = 0;

		virtual cfsec::CFSecClusterBuff* readBuffByUDomNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& FullDomName ) = 0;

		virtual cfsec::CFSecClusterBuff* readBuffByUDescrIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& Description ) = 0;

		virtual cfsec::CFSecClusterBuff* readBuffByLookupUDomNameIdx( const cfsec::CFSecAuthorization* Authorization, const std::string& FullDomName,
			bool forceRead = false ) = 0;

		virtual cfsec::CFSecClusterBuff* readDerivedByLookupUDomNameIdx( const cfsec::CFSecAuthorization* Authorization, const std::string& FullDomName,
			bool forceRead = false ) = 0;

		virtual void releasePreparedStatements() = 0;
	};
}
