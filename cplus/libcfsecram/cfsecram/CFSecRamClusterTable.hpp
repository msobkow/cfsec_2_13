#pragma once

// Description: C++18 Interface for an in-memory RAM DbIO declementation for Cluster.

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
#include <cfsec/ICFSecPublic.hpp>
#include <cfsecobj/ICFSecObjPublic.hpp>
#include <cfsecsaxloader/CFSecSaxLoader.hpp>
#include <cfsecram/CFSecRamClusterId32Gen.hpp>
#include <cfsecram/CFSecRamClusterId64Gen.hpp>

namespace cfsec {

	class CFSecRamClusterTable
	: public virtual cfsec::ICFSecClusterTable
	{
	protected:
		cfsec::ICFSecSchema* schema;
		std::map<cfsec::CFSecClusterPKey,
			cfsec::CFSecClusterBuff*>* dictByPKey;
		std::map<cfsec::CFSecClusterByUDomNameIdxKey,
			cfsec::CFSecClusterBuff*>* dictByUDomNameIdx;
		std::map<cfsec::CFSecClusterByUDescrIdxKey,
			cfsec::CFSecClusterBuff*>* dictByUDescrIdx;
		std::map<cfsec::CFSecRamClusterId32Gen, cfsec::CFSecRamClusterId32Gen*>* id32Generator;
		std::map<cfsec::CFSecRamClusterId64Gen, cfsec::CFSecRamClusterId64Gen*>* id64Generator;
		virtual int32_t generateNextId32( int64_t argId,
			int16_t argSliceId );

		virtual int64_t generateNextId64( int64_t argId,
			int16_t argSliceId );

	public:
		static const std::string CLASS_NAME;
		CFSecRamClusterTable( cfsec::ICFSecSchema* argSchema );

		virtual ~CFSecRamClusterTable();

		virtual int32_t nextSecAppIdGen( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecClusterPKey* pkey );

		virtual int32_t nextSecAppIdGen( const cfsec::CFSecAuthorization* Authorization,
			int64_t argId );

		virtual int32_t nextSecFormIdGen( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecClusterPKey* pkey );

		virtual int32_t nextSecFormIdGen( const cfsec::CFSecAuthorization* Authorization,
			int64_t argId );

		virtual int32_t nextSecGroupIdGen( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecClusterPKey* pkey );

		virtual int32_t nextSecGroupIdGen( const cfsec::CFSecAuthorization* Authorization,
			int64_t argId );

		virtual int64_t nextHostNodeIdGen( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecClusterPKey* pkey );

		virtual int64_t nextHostNodeIdGen( const cfsec::CFSecAuthorization* Authorization,
			int64_t argId );

		virtual int64_t nextSecGroupFormIdGen( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecClusterPKey* pkey );

		virtual int64_t nextSecGroupFormIdGen( const cfsec::CFSecAuthorization* Authorization,
			int64_t argId );

		virtual int64_t nextSecGrpIncIdGen( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecClusterPKey* pkey );

		virtual int64_t nextSecGrpIncIdGen( const cfsec::CFSecAuthorization* Authorization,
			int64_t argId );

		virtual int64_t nextSecGrpMembIdGen( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecClusterPKey* pkey );

		virtual int64_t nextSecGrpMembIdGen( const cfsec::CFSecAuthorization* Authorization,
			int64_t argId );

		virtual int64_t nextServiceIdGen( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecClusterPKey* pkey );

		virtual int64_t nextServiceIdGen( const cfsec::CFSecAuthorization* Authorization,
			int64_t argId );

		virtual cfsec::CFSecClusterBuff* createCluster( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecClusterBuff* Buff );

		virtual cfsec::CFSecClusterBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecClusterPKey* PKey );

		virtual cfsec::CFSecClusterBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecClusterPKey* PKey );

		virtual std::TCFLibOwningVector<cfsec::CFSecClusterBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization );

		virtual cfsec::CFSecClusterBuff* readDerivedByUDomNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& FullDomName );

		virtual cfsec::CFSecClusterBuff* readDerivedByUDescrIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& Description );

		virtual cfsec::CFSecClusterBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t Id );

		virtual cfsec::CFSecClusterBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecClusterPKey* PKey );

		virtual cfsec::CFSecClusterBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecClusterPKey* PKey );

		virtual std::TCFLibOwningVector<cfsec::CFSecClusterBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization );

		virtual std::TCFLibOwningVector<cfsec::CFSecClusterBuff*> pageAllBuff( const cfsec::CFSecAuthorization* Authorization,
			const int64_t* priorId );

		virtual cfsec::CFSecClusterBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t Id );

		virtual cfsec::CFSecClusterBuff* readBuffByUDomNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& FullDomName );

		virtual cfsec::CFSecClusterBuff* readBuffByUDescrIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& Description );

		virtual cfsec::CFSecClusterBuff* readBuffByLookupUDomNameIdx( const cfsec::CFSecAuthorization* Authorization, const std::string& FullDomName,
			bool forceRead = false );

		virtual cfsec::CFSecClusterBuff* readDerivedByLookupUDomNameIdx( const cfsec::CFSecAuthorization* Authorization, const std::string& FullDomName,
			bool forceRead = false );

		virtual cfsec::CFSecClusterBuff* updateCluster( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecClusterBuff* Buff );

		virtual void deleteCluster( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecClusterBuff* Buff );
		virtual void deleteClusterByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argId );

		virtual void deleteClusterByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecClusterPKey* argKey );

		virtual void deleteClusterByUDomNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& argFullDomName );

		virtual void deleteClusterByUDomNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecClusterByUDomNameIdxKey* argKey );

		virtual void deleteClusterByUDescrIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& argDescription );

		virtual void deleteClusterByUDescrIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecClusterByUDescrIdxKey* argKey );


		virtual void releasePreparedStatements();

	};
}
