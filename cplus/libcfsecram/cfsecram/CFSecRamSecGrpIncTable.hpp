#pragma once

// Description: C++18 Interface for an in-memory RAM DbIO declementation for SecGrpInc.

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

	class CFSecRamSecGrpIncTable
	: public virtual cfsec::ICFSecSecGrpIncTable
	{
	protected:
		cfsec::ICFSecSchema* schema;
		std::map<cfsec::CFSecSecGrpIncPKey,
			cfsec::CFSecSecGrpIncBuff*>* dictByPKey;
		std::map<cfsec::CFSecSecGrpIncByClusterIdxKey,
			std::map<cfsec::CFSecSecGrpIncPKey,
				cfsec::CFSecSecGrpIncBuff*>*>* dictByClusterIdx;
		std::map<cfsec::CFSecSecGrpIncByGroupIdxKey,
			std::map<cfsec::CFSecSecGrpIncPKey,
				cfsec::CFSecSecGrpIncBuff*>*>* dictByGroupIdx;
		std::map<cfsec::CFSecSecGrpIncByIncludeIdxKey,
			std::map<cfsec::CFSecSecGrpIncPKey,
				cfsec::CFSecSecGrpIncBuff*>*>* dictByIncludeIdx;
		std::map<cfsec::CFSecSecGrpIncByUIncludeIdxKey,
			cfsec::CFSecSecGrpIncBuff*>* dictByUIncludeIdx;
	public:
		static const std::string CLASS_NAME;
		CFSecRamSecGrpIncTable( cfsec::ICFSecSchema* argSchema );

		virtual ~CFSecRamSecGrpIncTable();

		virtual cfsec::CFSecSecGrpIncBuff* createSecGrpInc( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecSecGrpIncBuff* Buff );

		virtual cfsec::CFSecSecGrpIncBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGrpIncPKey* PKey );

		virtual cfsec::CFSecSecGrpIncBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGrpIncPKey* PKey );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGrpIncBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGrpIncBuff*> readDerivedByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGrpIncBuff*> readDerivedByGroupIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecGroupId );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGrpIncBuff*> readDerivedByIncludeIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t IncludeGroupId );

		virtual cfsec::CFSecSecGrpIncBuff* readDerivedByUIncludeIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecGroupId,
			const int32_t IncludeGroupId );

		virtual cfsec::CFSecSecGrpIncBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t SecGrpIncId );

		virtual cfsec::CFSecSecGrpIncBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGrpIncPKey* PKey );

		virtual cfsec::CFSecSecGrpIncBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGrpIncPKey* PKey );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGrpIncBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGrpIncBuff*> pageAllBuff( const cfsec::CFSecAuthorization* Authorization,
			const int64_t* priorClusterId,
			const int64_t* priorSecGrpIncId );

		virtual cfsec::CFSecSecGrpIncBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t SecGrpIncId );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGrpIncBuff*> readBuffByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGrpIncBuff*> readBuffByGroupIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecGroupId );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGrpIncBuff*> readBuffByIncludeIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t IncludeGroupId );

		virtual cfsec::CFSecSecGrpIncBuff* readBuffByUIncludeIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecGroupId,
			const int32_t IncludeGroupId );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGrpIncBuff*> pageBuffByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t* priorClusterId,
			const int64_t* priorSecGrpIncId );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGrpIncBuff*> pageBuffByGroupIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecGroupId,
			const int64_t* priorClusterId,
			const int64_t* priorSecGrpIncId );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGrpIncBuff*> pageBuffByIncludeIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t IncludeGroupId,
			const int64_t* priorClusterId,
			const int64_t* priorSecGrpIncId );

		virtual cfsec::CFSecSecGrpIncBuff* updateSecGrpInc( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecSecGrpIncBuff* Buff );

		virtual void deleteSecGrpInc( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecSecGrpIncBuff* Buff );
		virtual void deleteSecGrpIncByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const int64_t argSecGrpIncId );

		virtual void deleteSecGrpIncByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGrpIncPKey* argKey );

		virtual void deleteSecGrpIncByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId );

		virtual void deleteSecGrpIncByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGrpIncByClusterIdxKey* argKey );

		virtual void deleteSecGrpIncByGroupIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const int32_t argSecGroupId );

		virtual void deleteSecGrpIncByGroupIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGrpIncByGroupIdxKey* argKey );

		virtual void deleteSecGrpIncByIncludeIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const int32_t argIncludeGroupId );

		virtual void deleteSecGrpIncByIncludeIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGrpIncByIncludeIdxKey* argKey );

		virtual void deleteSecGrpIncByUIncludeIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const int32_t argSecGroupId,
			const int32_t argIncludeGroupId );

		virtual void deleteSecGrpIncByUIncludeIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGrpIncByUIncludeIdxKey* argKey );


		virtual void releasePreparedStatements();

	};
}
