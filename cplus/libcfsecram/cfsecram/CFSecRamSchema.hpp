#pragma once

// Description: C++18 Interface for an declementation of an in-memory RAM CFSec schema.

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
#include <cfsec/CFSecSchema.hpp>
#include <cfsecobj/ICFSecObjPublic.hpp>
#include <cfsecsaxloader/CFSecSaxLoader.hpp>

namespace cfsec {

	class CFSecRamSchema
	: public cfsec::CFSecSchema,
	  public virtual cfsec::ICFSecSchema
	{
	protected:
		bool sessConnected = false;
		bool tranOpen = false;
		int16_t nextISOCcyIdGenValue;
		int16_t nextISOCtryIdGenValue;
		int16_t nextISOLangIdGenValue;
		int16_t nextISOTZoneIdGenValue;
		int32_t nextServiceTypeIdGenValue;
		int64_t nextClusterIdGenValue;
		int64_t nextTenantIdGenValue;

	public:
		static const std::string CLASS_NAME;

	CFSecRamSchema();
	virtual ~CFSecRamSchema();
	virtual bool isConnected();
	virtual bool connect();
	virtual bool connect( const std::string& username, const std::string& password );
	virtual bool connect( const std::string& loginId, const std::string& password, const std::string& clusterName, const std::string& tenantName );
	virtual void disconnect( bool doCommit );
	virtual bool isTransactionOpen();
	virtual bool beginTransaction();
	virtual void commit();
	virtual void rollback();
	virtual cfsec::ICFSecSchema* newSchema();

	virtual int16_t nextISOCcyIdGen();
	virtual int16_t nextISOCtryIdGen();
	virtual int16_t nextISOLangIdGen();
	virtual int16_t nextISOTZoneIdGen();
	virtual int32_t nextServiceTypeIdGen();
	virtual int64_t nextClusterIdGen();
	virtual int64_t nextTenantIdGen();
	virtual void releasePreparedStatements();
	virtual std::string fileImport( cfsec::CFSecAuthorization* Authorization,
		const std::string& fileName,
		const std::string& fileContent );

	};
}
