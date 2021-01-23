#pragma once

// Description: C++18 Interface for an in-memory RAM DbIO declementation for ISOCcy.

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

	class CFSecRamISOCcyTable
	: public virtual cfsec::ICFSecISOCcyTable
	{
	protected:
		cfsec::ICFSecSchema* schema;
		std::map<cfsec::CFSecISOCcyPKey,
			cfsec::CFSecISOCcyBuff*>* dictByPKey;
		std::map<cfsec::CFSecISOCcyByCcyCdIdxKey,
			cfsec::CFSecISOCcyBuff*>* dictByCcyCdIdx;
		std::map<cfsec::CFSecISOCcyByCcyNmIdxKey,
			cfsec::CFSecISOCcyBuff*>* dictByCcyNmIdx;
	public:
		static const std::string CLASS_NAME;
		CFSecRamISOCcyTable( cfsec::ICFSecSchema* argSchema );

		virtual ~CFSecRamISOCcyTable();

		virtual cfsec::CFSecISOCcyBuff* createISOCcy( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecISOCcyBuff* Buff );

		virtual cfsec::CFSecISOCcyBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCcyPKey* PKey );

		virtual cfsec::CFSecISOCcyBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCcyPKey* PKey );

		virtual std::TCFLibOwningVector<cfsec::CFSecISOCcyBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization );

		virtual cfsec::CFSecISOCcyBuff* readDerivedByCcyCdIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& ISOCode );

		virtual cfsec::CFSecISOCcyBuff* readDerivedByCcyNmIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& Name );

		virtual cfsec::CFSecISOCcyBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t ISOCcyId );

		virtual cfsec::CFSecISOCcyBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCcyPKey* PKey );

		virtual cfsec::CFSecISOCcyBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCcyPKey* PKey );

		virtual std::TCFLibOwningVector<cfsec::CFSecISOCcyBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization );

		virtual cfsec::CFSecISOCcyBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t ISOCcyId );

		virtual cfsec::CFSecISOCcyBuff* readBuffByCcyCdIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& ISOCode );

		virtual cfsec::CFSecISOCcyBuff* readBuffByCcyNmIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& Name );

		virtual cfsec::CFSecISOCcyBuff* readBuffByLookupCcyCdIdx( const cfsec::CFSecAuthorization* Authorization, const std::string& ISOCode,
			bool forceRead = false );

		virtual cfsec::CFSecISOCcyBuff* readDerivedByLookupCcyCdIdx( const cfsec::CFSecAuthorization* Authorization, const std::string& ISOCode,
			bool forceRead = false );

		virtual cfsec::CFSecISOCcyBuff* updateISOCcy( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecISOCcyBuff* Buff );

		virtual void deleteISOCcy( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecISOCcyBuff* Buff );
		virtual void deleteISOCcyByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t argISOCcyId );

		virtual void deleteISOCcyByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCcyPKey* argKey );

		virtual void deleteISOCcyByCcyCdIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& argISOCode );

		virtual void deleteISOCcyByCcyCdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCcyByCcyCdIdxKey* argKey );

		virtual void deleteISOCcyByCcyNmIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& argName );

		virtual void deleteISOCcyByCcyNmIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCcyByCcyNmIdxKey* argKey );


		virtual void releasePreparedStatements();

	};
}
