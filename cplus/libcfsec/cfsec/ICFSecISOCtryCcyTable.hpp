#pragma once

// Description: C++18 DbIO interface for ISOCtryCcy.

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
#include <cfsec/CFSecAuthorization.hpp>
#include <cfsec/CFSecHPKey.hpp>
#include <cfsec/CFSecISOCtryCcyBuff.hpp>
#include <cfsec/CFSecISOCtryCcyPKey.hpp>
#include <cfsec/CFSecISOCtryCcyHBuff.hpp>
#include <cfsec/CFSecISOCtryCcyHPKey.hpp>
#include <cfsec/CFSecISOCtryCcyByCtryIdxKey.hpp>
#include <cfsec/CFSecISOCtryCcyByCcyIdxKey.hpp>

namespace cfsec {
	class ICFSecSchemaObj;
}

namespace cfsec {
	class ICFSecISOCtryCcyObj;

	class ICFSecISOCtryCcyTable
	{
	public:
		ICFSecISOCtryCcyTable();
		virtual ~ICFSecISOCtryCcyTable();

		virtual cfsec::CFSecISOCtryCcyBuff* createISOCtryCcy( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecISOCtryCcyBuff* Buff ) = 0;

		virtual cfsec::CFSecISOCtryCcyBuff* updateISOCtryCcy( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecISOCtryCcyBuff* Buff ) = 0;

		virtual void deleteISOCtryCcy( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecISOCtryCcyBuff* Buff ) = 0;
		virtual void deleteISOCtryCcyByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t argISOCtryId,
			const int16_t argISOCcyId ) = 0;

		virtual void deleteISOCtryCcyByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCtryCcyPKey* argKey ) = 0;
		virtual void deleteISOCtryCcyByCtryIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t argISOCtryId ) = 0;

		virtual void deleteISOCtryCcyByCtryIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCtryCcyByCtryIdxKey* argKey ) = 0;
		virtual void deleteISOCtryCcyByCcyIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t argISOCcyId ) = 0;

		virtual void deleteISOCtryCcyByCcyIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCtryCcyByCcyIdxKey* argKey ) = 0;

		virtual cfsec::CFSecISOCtryCcyBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCtryCcyPKey* PKey ) = 0;

		virtual cfsec::CFSecISOCtryCcyBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCtryCcyPKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecISOCtryCcyBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual cfsec::CFSecISOCtryCcyBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t ISOCtryId,
			const int16_t ISOCcyId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecISOCtryCcyBuff*> readDerivedByCtryIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t ISOCtryId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecISOCtryCcyBuff*> readDerivedByCcyIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t ISOCcyId ) = 0;

		virtual cfsec::CFSecISOCtryCcyBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCtryCcyPKey* PKey ) = 0;

		virtual cfsec::CFSecISOCtryCcyBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecISOCtryCcyPKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecISOCtryCcyBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual cfsec::CFSecISOCtryCcyBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t ISOCtryId,
			const int16_t ISOCcyId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecISOCtryCcyBuff*> readBuffByCtryIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t ISOCtryId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecISOCtryCcyBuff*> readBuffByCcyIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t ISOCcyId ) = 0;

		virtual void releasePreparedStatements() = 0;
	};
}
