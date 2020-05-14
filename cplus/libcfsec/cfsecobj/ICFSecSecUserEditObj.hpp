#pragma once

// Description: C++18 Instance Edit Object interface for CFSec SecUser.

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
#include <cfsec/CFSecSecUserBuff.hpp>

namespace cfsec {
	class ICFSecSchemaObj;
	class ICFSecClusterObj;
	class ICFSecClusterEditObj;
	class ICFSecClusterTableObj;
	class ICFSecHostNodeObj;
	class ICFSecHostNodeEditObj;
	class ICFSecHostNodeTableObj;
	class ICFSecISOCcyObj;
	class ICFSecISOCcyEditObj;
	class ICFSecISOCcyTableObj;
	class ICFSecISOCtryObj;
	class ICFSecISOCtryEditObj;
	class ICFSecISOCtryTableObj;
	class ICFSecISOCtryCcyObj;
	class ICFSecISOCtryCcyEditObj;
	class ICFSecISOCtryCcyTableObj;
	class ICFSecISOCtryLangObj;
	class ICFSecISOCtryLangEditObj;
	class ICFSecISOCtryLangTableObj;
	class ICFSecISOLangObj;
	class ICFSecISOLangEditObj;
	class ICFSecISOLangTableObj;
	class ICFSecISOTZoneObj;
	class ICFSecISOTZoneEditObj;
	class ICFSecISOTZoneTableObj;
	class ICFSecSecAppObj;
	class ICFSecSecAppEditObj;
	class ICFSecSecAppTableObj;
	class ICFSecSecDeviceObj;
	class ICFSecSecDeviceEditObj;
	class ICFSecSecDeviceTableObj;
	class ICFSecSecFormObj;
	class ICFSecSecFormEditObj;
	class ICFSecSecFormTableObj;
	class ICFSecSecGroupObj;
	class ICFSecSecGroupEditObj;
	class ICFSecSecGroupTableObj;
	class ICFSecSecGroupFormObj;
	class ICFSecSecGroupFormEditObj;
	class ICFSecSecGroupFormTableObj;
	class ICFSecSecGrpIncObj;
	class ICFSecSecGrpIncEditObj;
	class ICFSecSecGrpIncTableObj;
	class ICFSecSecGrpMembObj;
	class ICFSecSecGrpMembEditObj;
	class ICFSecSecGrpMembTableObj;
	class ICFSecSecSessionObj;
	class ICFSecSecSessionEditObj;
	class ICFSecSecSessionTableObj;
	class ICFSecSecUserObj;
	class ICFSecSecUserEditObj;
	class ICFSecSecUserTableObj;
	class ICFSecServiceObj;
	class ICFSecServiceEditObj;
	class ICFSecServiceTableObj;
	class ICFSecServiceTypeObj;
	class ICFSecServiceTypeEditObj;
	class ICFSecServiceTypeTableObj;
	class ICFSecSysClusterObj;
	class ICFSecSysClusterEditObj;
	class ICFSecSysClusterTableObj;
	class ICFSecTSecGroupObj;
	class ICFSecTSecGroupEditObj;
	class ICFSecTSecGroupTableObj;
	class ICFSecTSecGrpIncObj;
	class ICFSecTSecGrpIncEditObj;
	class ICFSecTSecGrpIncTableObj;
	class ICFSecTSecGrpMembObj;
	class ICFSecTSecGrpMembEditObj;
	class ICFSecTSecGrpMembTableObj;
	class ICFSecTenantObj;
	class ICFSecTenantEditObj;
	class ICFSecTenantTableObj;
}

#include <cfsecobj/ICFSecSecUserObj.hpp>

#include <cfsecobj/ICFSecSecUserObj.hpp>

namespace cfsec {

	class ICFSecSecUserEditObj
	: public virtual cfsec::ICFSecSecUserObj
	{
	public:
		static const std::string CLASS_NAME;
		ICFSecSecUserEditObj();
		virtual ~ICFSecSecUserEditObj();
		virtual const std::string& getClassName() const = 0;

		inline cfsec::CFSecSecUserBuff* getSecUserBuff() {
			return( static_cast<cfsec::CFSecSecUserBuff*>( getBuff() ) );
		};

		inline cfsec::CFSecSecUserBuff* getSecUserEditBuff() {
			return( dynamic_cast<cfsec::CFSecSecUserBuff*>( getBuff() ) );
		};

		virtual cfsec::ICFSecSecUserObj* getOrig() = 0;

		virtual cfsec::ICFSecSecUserObj* getOrigAsSecUser() = 0;

		virtual int32_t getRequiredRevision() const = 0;
		virtual void setRequiredRevision( int32_t value ) = 0;
		virtual cfsec::ICFSecSecUserEditObj* beginEdit() = 0;

		virtual cfsec::ICFSecSecUserObj* create() = 0;

		virtual cfsec::ICFSecSecUserEditObj* update() = 0;

		virtual cfsec::ICFSecSecUserEditObj* deleteInstance() = 0;

		virtual const std::string& getRequiredLoginId() = 0;
		virtual const std::string* getRequiredLoginIdReference() = 0;
		virtual void setRequiredLoginId( const std::string& value ) = 0;

		virtual const std::string& getRequiredEMailAddress() = 0;
		virtual const std::string* getRequiredEMailAddressReference() = 0;
		virtual void setRequiredEMailAddress( const std::string& value ) = 0;

		virtual bool isOptionalEMailConfirmUuidNull() = 0;
		virtual const uuid_ptr_t getOptionalEMailConfirmUuidValue() = 0;
		virtual const uuid_ptr_t getOptionalEMailConfirmUuidReference() = 0;
		virtual void setOptionalEMailConfirmUuidNull() = 0;
		virtual void setOptionalEMailConfirmUuidValue( const uuid_ptr_t value ) = 0;

		virtual const std::string& getRequiredPasswordHash() = 0;
		virtual const std::string* getRequiredPasswordHashReference() = 0;
		virtual void setRequiredPasswordHash( const std::string& value ) = 0;

		virtual bool isOptionalPasswordResetUuidNull() = 0;
		virtual const uuid_ptr_t getOptionalPasswordResetUuidValue() = 0;
		virtual const uuid_ptr_t getOptionalPasswordResetUuidReference() = 0;
		virtual void setOptionalPasswordResetUuidNull() = 0;
		virtual void setOptionalPasswordResetUuidValue( const uuid_ptr_t value ) = 0;

		virtual cfsec::ICFSecSecDeviceObj* getOptionalLookupDefDev( bool forceRead = false ) = 0;
		virtual void setOptionalLookupDefDev( cfsec::ICFSecSecDeviceObj* value ) = 0;

		virtual void setCreatedBy( cfsec::ICFSecSecUserObj* value ) = 0;
		virtual void setCreatedAt( const std::chrono::system_clock::time_point& value ) = 0;

		virtual void setUpdatedBy( cfsec::ICFSecSecUserObj* value ) = 0;
		virtual void setUpdatedAt( const std::chrono::system_clock::time_point& value ) = 0;
	};
}
