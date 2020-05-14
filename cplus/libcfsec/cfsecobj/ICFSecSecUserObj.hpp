#pragma once

// Description: C++18 Object interface for CFSec SecUser.

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
	class ICFSecSecUserEditObj;
}

#include <cfsecobj/ICFSecSecUserObj.hpp>


namespace cfsec {

	class ICFSecSecUserObj
	: public virtual cflib::ICFLibAnyObj
	{
	public:
		ICFSecSecUserObj();
		virtual ~ICFSecSecUserObj();
		virtual const std::string& getClassName() const = 0;
		virtual const classcode_t getClassCode() const = 0;
		virtual bool implementsClassCode( const classcode_t value ) const = 0;
		virtual const std::string getGenDefName() = 0;
		virtual cflib::ICFLibAnyObj* getObjScope() = 0;
		virtual std::string getObjName() = 0;
		virtual std::string getObjQualifiedName() = 0;
		virtual std::string getObjFullName() = 0;
		virtual cflib::ICFLibAnyObj* getNamedObject( const classcode_t* qualifyingClassCode, const std::string& objName ) = 0;
		virtual cflib::ICFLibAnyObj* getNamedObject( const std::string& objName ) = 0;
		virtual cflib::ICFLibAnyObj* getObjQualifier( const classcode_t* qualifyingClassCode ) = 0;
		virtual std::string toString() = 0;
		virtual cfsec::ICFSecSecUserObj* getCreatedBy() = 0;
		virtual const std::chrono::system_clock::time_point& getCreatedAt() = 0;
		virtual cfsec::ICFSecSecUserObj* getUpdatedBy() = 0;
		virtual const std::chrono::system_clock::time_point& getUpdatedAt() = 0;
		virtual int32_t getRequiredRevision() const = 0;
		virtual cfsec::ICFSecSecUserObj* realize() = 0;

		virtual cfsec::ICFSecSecUserObj* read( bool forceRead = false ) = 0;

		virtual cfsec::ICFSecSecUserEditObj* beginEdit() = 0;

		virtual void endEdit() = 0;

		virtual cfsec::ICFSecSecUserEditObj* getEdit() = 0;

		virtual cfsec::ICFSecSecUserEditObj* getSecUserEdit() = 0;

		virtual cfsec::ICFSecSecUserTableObj* getSecUserTable() = 0;

		virtual cfsec::ICFSecSchemaObj* getSchema() = 0;

		virtual cfsec::CFSecSecUserBuff* getBuff() = 0;
		virtual void setBuff( cfsec::CFSecSecUserBuff* value ) = 0;

		inline cfsec::CFSecSecUserBuff* getSecUserBuff() {
			return( static_cast<cfsec::CFSecSecUserBuff*>( getBuff() ) );
		};

		inline cfsec::CFSecSecUserBuff* getSecUserEditBuff() {
			return( dynamic_cast<cfsec::CFSecSecUserBuff*>( getBuff() ) );
		};

		virtual cfsec::CFSecSecUserPKey* getPKey() = 0;
		virtual void setPKey( cfsec::CFSecSecUserPKey* value ) = 0;

		virtual bool getIsNew() = 0;
		virtual void setIsNew( bool value ) = 0;

		virtual const uuid_ptr_t getRequiredSecUserId() = 0;
		virtual const uuid_ptr_t getRequiredSecUserIdReference() = 0;

		virtual const std::string& getRequiredLoginId() = 0;
		virtual const std::string* getRequiredLoginIdReference() = 0;

		virtual const std::string& getRequiredEMailAddress() = 0;
		virtual const std::string* getRequiredEMailAddressReference() = 0;

		virtual bool isOptionalEMailConfirmUuidNull() = 0;
		virtual const uuid_ptr_t getOptionalEMailConfirmUuidValue() = 0;
		virtual const uuid_ptr_t getOptionalEMailConfirmUuidReference() = 0;

		virtual bool isOptionalDfltDevUserIdNull() = 0;
		virtual const uuid_ptr_t getOptionalDfltDevUserIdValue() = 0;
		virtual const uuid_ptr_t getOptionalDfltDevUserIdReference() = 0;

		virtual bool isOptionalDfltDevNameNull() = 0;
		virtual const std::string& getOptionalDfltDevNameValue() = 0;
		virtual const std::string* getOptionalDfltDevNameReference() = 0;

		virtual const std::string& getRequiredPasswordHash() = 0;
		virtual const std::string* getRequiredPasswordHashReference() = 0;

		virtual bool isOptionalPasswordResetUuidNull() = 0;
		virtual const uuid_ptr_t getOptionalPasswordResetUuidValue() = 0;
		virtual const uuid_ptr_t getOptionalPasswordResetUuidReference() = 0;

		virtual std::vector<cfsec::ICFSecSecDeviceObj*> getOptionalComponentsSecDev( bool forceRead = false ) = 0;

		virtual cfsec::ICFSecSecDeviceObj* getOptionalLookupDefDev( bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecSecSessionObj*> getOptionalComponentsSecSess( bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecSecSessionObj*> getOptionalChildrenSecProxy( bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecSecGrpMembObj*> getOptionalChildrenSecGrpMemb( bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecTSecGrpMembObj*> getOptionalChildrenTSecGrpMemb( bool forceRead = false ) = 0;

		virtual void copyPKeyToBuff() = 0;

		virtual void copyBuffToPKey() = 0;

	};
}
