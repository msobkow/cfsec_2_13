#pragma once

// Description: C++18 base object instance specification for CFSec SecUser.

/*
 *	org.msscf.msscf.CFSec
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
#include <cfsecobj/ICFSecSchemaObj.hpp>

namespace cfsec {

	class CFSecSecUserObj
	: public virtual ICFSecSecUserObj
	{
	protected:
		cfsec::ICFSecSecUserObj* createdBy = NULL;
		cfsec::ICFSecSecUserObj* updatedBy = NULL;
		bool isNew;
		cfsec::ICFSecSecUserEditObj* edit;
		cfsec::ICFSecSchemaObj* schema;
		cfsec::CFSecSecUserPKey* pKey;
		cfsec::CFSecSecUserBuff* buff;
	public:
		static const std::string CLASS_NAME;
		static const classcode_t CLASS_CODE;

		virtual const uuid_ptr_t getRequiredSecUserId();
		virtual const uuid_ptr_t getRequiredSecUserIdReference();

		virtual const std::string& getRequiredLoginId();
		virtual const std::string* getRequiredLoginIdReference();

		virtual const std::string& getRequiredEMailAddress();
		virtual const std::string* getRequiredEMailAddressReference();

		virtual bool isOptionalEMailConfirmUuidNull();
		virtual const uuid_ptr_t getOptionalEMailConfirmUuidValue();
		virtual const uuid_ptr_t getOptionalEMailConfirmUuidReference();

		virtual bool isOptionalDfltDevUserIdNull();
		virtual const uuid_ptr_t getOptionalDfltDevUserIdValue();
		virtual const uuid_ptr_t getOptionalDfltDevUserIdReference();

		virtual bool isOptionalDfltDevNameNull();
		virtual const std::string& getOptionalDfltDevNameValue();
		virtual const std::string* getOptionalDfltDevNameReference();

		virtual const std::string& getRequiredPasswordHash();
		virtual const std::string* getRequiredPasswordHashReference();

		virtual bool isOptionalPasswordResetUuidNull();
		virtual const uuid_ptr_t getOptionalPasswordResetUuidValue();
		virtual const uuid_ptr_t getOptionalPasswordResetUuidReference();

		virtual std::vector<cfsec::ICFSecSecDeviceObj*> getOptionalComponentsSecDev( bool forceRead = false );

		virtual cfsec::ICFSecSecDeviceObj* getOptionalLookupDefDev( bool forceRead = false );

		virtual std::vector<cfsec::ICFSecSecSessionObj*> getOptionalComponentsSecSess( bool forceRead = false );

		virtual std::vector<cfsec::ICFSecSecSessionObj*> getOptionalChildrenSecProxy( bool forceRead = false );

		virtual std::vector<cfsec::ICFSecSecGrpMembObj*> getOptionalChildrenSecGrpMemb( bool forceRead = false );

		virtual std::vector<cfsec::ICFSecTSecGrpMembObj*> getOptionalChildrenTSecGrpMemb( bool forceRead = false );

		CFSecSecUserObj();
		CFSecSecUserObj( cfsec::ICFSecSchemaObj* argSchema );
		virtual const std::string& getClassName() const;
		virtual ~CFSecSecUserObj();
		virtual const classcode_t getClassCode() const;

		virtual bool implementsClassCode( const classcode_t value ) const;

		virtual int32_t getRequiredRevision() const;

		virtual std::string toString();
		virtual cfsec::CFSecSecUserBuff* getBuff();
		virtual void setBuff( cfsec::CFSecSecUserBuff* value );

		inline cfsec::CFSecSecUserBuff* getSecUserBuff() {
			if( buff == NULL ) {
				getBuff();
			}
			return( static_cast<cfsec::CFSecSecUserBuff*>( buff ) );
		};

		inline cfsec::CFSecSecUserBuff* getSecUserEditBuff() {
			if( buff == NULL ) {
				getBuff();
			}
			return( dynamic_cast<cfsec::CFSecSecUserBuff*>( buff ) );
		};

		virtual std::string getObjName();

		virtual const std::string getGenDefName();

		virtual cflib::ICFLibAnyObj* getScope();
		virtual cflib::ICFLibAnyObj* getObjScope();

		virtual cflib::ICFLibAnyObj* getObjQualifier( const classcode_t* qualifyingClass );

		virtual cflib::ICFLibAnyObj* getNamedObject( const classcode_t* qualifyingClass, const std::string& objName );

		virtual cflib::ICFLibAnyObj* getNamedObject( const std::string& objName );

		virtual std::string getObjQualifiedName();

		virtual std::string getObjFullName();

		virtual cfsec::ICFSecSecUserObj* realize();

		virtual cfsec::ICFSecSecUserObj* read( bool forceRead = false );

		virtual cfsec::ICFSecSecUserTableObj* getSecUserTable();

		virtual cfsec::ICFSecSchemaObj* getSchema();
		virtual void setSchema( cfsec::ICFSecSchemaObj* value );

		virtual cfsec::CFSecSecUserPKey* getPKey();
		virtual void setPKey( cfsec::CFSecSecUserPKey* value );

		virtual bool getIsNew();
		virtual void setIsNew( bool value );

		virtual cfsec::ICFSecSecUserEditObj* beginEdit();

		virtual void endEdit();

		virtual cfsec::ICFSecSecUserEditObj* getEdit();

		virtual cfsec::ICFSecSecUserEditObj* getSecUserEdit();

		virtual cfsec::ICFSecSecUserObj* getCreatedBy();
		virtual const std::chrono::system_clock::time_point& getCreatedAt();
		virtual cfsec::ICFSecSecUserObj* getUpdatedBy();
		virtual const std::chrono::system_clock::time_point& getUpdatedAt();

		virtual void copyPKeyToBuff();

		virtual void copyBuffToPKey();

	};
}
