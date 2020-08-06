#pragma once

// Description: C++18 Interface for an in-memory RAM DbIO declementation for SecForm.

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

namespace cfsec {

	class CFSecRamSecFormTable
	: public virtual cfsec::ICFSecSecFormTable
	{
	protected:
		cfsec::ICFSecSchema* schema;
		std::map<cfsec::CFSecSecFormPKey,
			cfsec::CFSecSecFormBuff*>* dictByPKey;
		std::map<cfsec::CFSecSecFormByClusterIdxKey,
			std::map<cfsec::CFSecSecFormPKey,
				cfsec::CFSecSecFormBuff*>*>* dictByClusterIdx;
		std::map<cfsec::CFSecSecFormBySecAppIdxKey,
			std::map<cfsec::CFSecSecFormPKey,
				cfsec::CFSecSecFormBuff*>*>* dictBySecAppIdx;
		std::map<cfsec::CFSecSecFormByUJEEServletIdxKey,
			cfsec::CFSecSecFormBuff*>* dictByUJEEServletIdx;
	public:
		static const std::string CLASS_NAME;
		CFSecRamSecFormTable( cfsec::ICFSecSchema* argSchema );

		virtual ~CFSecRamSecFormTable();

		virtual cfsec::CFSecSecFormBuff* createSecForm( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecSecFormBuff* Buff );

		virtual cfsec::CFSecSecFormBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecFormPKey* PKey );

		virtual cfsec::CFSecSecFormBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecFormPKey* PKey );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecFormBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecFormBuff*> readDerivedByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecFormBuff*> readDerivedBySecAppIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecAppId );

		virtual cfsec::CFSecSecFormBuff* readDerivedByUJEEServletIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecAppId,
			const std::string& JEEServletMapName );

		virtual cfsec::CFSecSecFormBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecFormId );

		virtual cfsec::CFSecSecFormBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecFormPKey* PKey );

		virtual cfsec::CFSecSecFormBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecFormPKey* PKey );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecFormBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecFormBuff*> pageAllBuff( const cfsec::CFSecAuthorization* Authorization,
			const int64_t* priorClusterId,
			const int32_t* priorSecFormId );

		virtual cfsec::CFSecSecFormBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecFormId );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecFormBuff*> readBuffByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecFormBuff*> readBuffBySecAppIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecAppId );

		virtual cfsec::CFSecSecFormBuff* readBuffByUJEEServletIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecAppId,
			const std::string& JEEServletMapName );

		virtual cfsec::CFSecSecFormBuff* readBuffByLookupUJEEServletIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecAppId, const std::string& JEEServletMapName,
			bool forceRead = false );

		virtual cfsec::CFSecSecFormBuff* readDerivedByLookupUJEEServletIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecAppId, const std::string& JEEServletMapName,
			bool forceRead = false );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecFormBuff*> pageBuffByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t* priorClusterId,
			const int32_t* priorSecFormId );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecFormBuff*> pageBuffBySecAppIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecAppId,
			const int64_t* priorClusterId,
			const int32_t* priorSecFormId );

		virtual cfsec::CFSecSecFormBuff* updateSecForm( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecSecFormBuff* Buff );

		virtual void deleteSecForm( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecSecFormBuff* Buff );
		virtual void deleteSecFormByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const int32_t argSecFormId );

		virtual void deleteSecFormByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecFormPKey* argKey );

		virtual void deleteSecFormByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId );

		virtual void deleteSecFormByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecFormByClusterIdxKey* argKey );

		virtual void deleteSecFormBySecAppIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const int32_t argSecAppId );

		virtual void deleteSecFormBySecAppIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecFormBySecAppIdxKey* argKey );

		virtual void deleteSecFormByUJEEServletIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const int32_t argSecAppId,
			const std::string& argJEEServletMapName );

		virtual void deleteSecFormByUJEEServletIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecFormByUJEEServletIdxKey* argKey );


		virtual void releasePreparedStatements();

	};
}
