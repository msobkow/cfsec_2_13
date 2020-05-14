#pragma once

// Description: C++18 Interface for an declementation of an in-memory RAM CFSec schema.

/*
 *	com.github.msobkow.CFSec
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	This file is part of MSS Code Factory.
 *	
 *	Licensed under the Apache License, Version 2.0 (the "License");
 *	you may not use this file except in compliance with the License.
 *	You may obtain a copy of the License at
 *	
 *	    http://www.apache.org/licenses/LICENSE-2.0
 *	
 *	Unless required by applicable law or agreed to in writing, software
 *	distributed under the License is distributed on an "AS IS" BASIS,
 *	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *	See the License for the specific language governing permissions and
 *	limitations under the License.
 *	
 *	Donations to support MSS Code Factory can be made at
 *	https://www.paypal.com/paypalme2/MarkSobkow
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
