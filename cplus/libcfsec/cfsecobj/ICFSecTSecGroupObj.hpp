#pragma once

// Description: C++18 Object interface for CFSec TSecGroup.

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
#include <cfsec/CFSecTSecGroupBuff.hpp>

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
	class ICFSecTSecGroupEditObj;
}

#include <cfsecobj/ICFSecSecUserObj.hpp>


namespace cfsec {

	class ICFSecTSecGroupObj
	: public virtual cflib::ICFLibAnyObj
	{
	public:
		ICFSecTSecGroupObj();
		virtual ~ICFSecTSecGroupObj();
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
		virtual cfsec::ICFSecTSecGroupObj* realize() = 0;

		virtual cfsec::ICFSecTSecGroupObj* read( bool forceRead = false ) = 0;

		virtual cfsec::ICFSecTSecGroupEditObj* beginEdit() = 0;

		virtual void endEdit() = 0;

		virtual cfsec::ICFSecTSecGroupEditObj* getEdit() = 0;

		virtual cfsec::ICFSecTSecGroupEditObj* getTSecGroupEdit() = 0;

		virtual cfsec::ICFSecTSecGroupTableObj* getTSecGroupTable() = 0;

		virtual cfsec::ICFSecSchemaObj* getSchema() = 0;

		virtual cfsec::CFSecTSecGroupBuff* getBuff() = 0;
		virtual void setBuff( cfsec::CFSecTSecGroupBuff* value ) = 0;

		inline cfsec::CFSecTSecGroupBuff* getTSecGroupBuff() {
			return( static_cast<cfsec::CFSecTSecGroupBuff*>( getBuff() ) );
		};

		inline cfsec::CFSecTSecGroupBuff* getTSecGroupEditBuff() {
			return( dynamic_cast<cfsec::CFSecTSecGroupBuff*>( getBuff() ) );
		};

		virtual cfsec::CFSecTSecGroupPKey* getPKey() = 0;
		virtual void setPKey( cfsec::CFSecTSecGroupPKey* value ) = 0;

		virtual bool getIsNew() = 0;
		virtual void setIsNew( bool value ) = 0;

		virtual const int64_t getRequiredTenantId() = 0;
		virtual const int64_t* getRequiredTenantIdReference() = 0;

		virtual const int32_t getRequiredTSecGroupId() = 0;
		virtual const int32_t* getRequiredTSecGroupIdReference() = 0;

		virtual const std::string& getRequiredName() = 0;
		virtual const std::string* getRequiredNameReference() = 0;

		virtual const bool getRequiredIsVisible() = 0;
		virtual const bool* getRequiredIsVisibleReference() = 0;

		virtual cfsec::ICFSecTenantObj* getRequiredContainerTenant( bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecTSecGrpIncObj*> getOptionalComponentsInclude( bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecTSecGrpMembObj*> getOptionalComponentsMember( bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecTSecGrpIncObj*> getRequiredChildrenIncByGroup( bool forceRead = false ) = 0;

		virtual void copyPKeyToBuff() = 0;

		virtual void copyBuffToPKey() = 0;

	};
}