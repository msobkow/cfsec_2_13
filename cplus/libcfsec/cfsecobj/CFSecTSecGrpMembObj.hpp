#pragma once

// Description: C++18 base object instance specification for CFSec TSecGrpMemb.

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

#include <cfsecobj/ICFSecTSecGrpMembObj.hpp>
#include <cfsecobj/ICFSecSchemaObj.hpp>

namespace cfsec {

	class CFSecTSecGrpMembObj
	: public virtual ICFSecTSecGrpMembObj
	{
	protected:
		cfsec::ICFSecSecUserObj* createdBy = NULL;
		cfsec::ICFSecSecUserObj* updatedBy = NULL;
		bool isNew;
		cfsec::ICFSecTSecGrpMembEditObj* edit;
		cfsec::ICFSecSchemaObj* schema;
		cfsec::CFSecTSecGrpMembPKey* pKey;
		cfsec::CFSecTSecGrpMembBuff* buff;
	public:
		static const std::string CLASS_NAME;
		static const classcode_t CLASS_CODE;

		virtual const int64_t getRequiredTenantId();
		virtual const int64_t* getRequiredTenantIdReference();

		virtual const int64_t getRequiredTSecGrpMembId();
		virtual const int64_t* getRequiredTSecGrpMembIdReference();

		virtual const int32_t getRequiredTSecGroupId();
		virtual const int32_t* getRequiredTSecGroupIdReference();

		virtual const uuid_ptr_t getRequiredSecUserId();
		virtual const uuid_ptr_t getRequiredSecUserIdReference();

		virtual cfsec::ICFSecTenantObj* getRequiredOwnerTenant( bool forceRead = false );

		virtual cfsec::ICFSecTSecGroupObj* getRequiredContainerGroup( bool forceRead = false );

		virtual cfsec::ICFSecSecUserObj* getRequiredParentUser( bool forceRead = false );

		CFSecTSecGrpMembObj();
		CFSecTSecGrpMembObj( cfsec::ICFSecSchemaObj* argSchema );
		virtual const std::string& getClassName() const;
		virtual ~CFSecTSecGrpMembObj();
		virtual const classcode_t getClassCode() const;

		virtual bool implementsClassCode( const classcode_t value ) const;

		virtual int32_t getRequiredRevision() const;

		virtual std::string toString();
		virtual cfsec::CFSecTSecGrpMembBuff* getBuff();
		virtual void setBuff( cfsec::CFSecTSecGrpMembBuff* value );

		inline cfsec::CFSecTSecGrpMembBuff* getTSecGrpMembBuff() {
			if( buff == NULL ) {
				getBuff();
			}
			return( static_cast<cfsec::CFSecTSecGrpMembBuff*>( buff ) );
		};

		inline cfsec::CFSecTSecGrpMembBuff* getTSecGrpMembEditBuff() {
			if( buff == NULL ) {
				getBuff();
			}
			return( dynamic_cast<cfsec::CFSecTSecGrpMembBuff*>( buff ) );
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

		virtual cfsec::ICFSecTSecGrpMembObj* realize();

		virtual cfsec::ICFSecTSecGrpMembObj* read( bool forceRead = false );

		virtual cfsec::ICFSecTSecGrpMembTableObj* getTSecGrpMembTable();

		virtual cfsec::ICFSecSchemaObj* getSchema();
		virtual void setSchema( cfsec::ICFSecSchemaObj* value );

		virtual cfsec::CFSecTSecGrpMembPKey* getPKey();
		virtual void setPKey( cfsec::CFSecTSecGrpMembPKey* value );

		virtual bool getIsNew();
		virtual void setIsNew( bool value );

		virtual cfsec::ICFSecTSecGrpMembEditObj* beginEdit();

		virtual void endEdit();

		virtual cfsec::ICFSecTSecGrpMembEditObj* getEdit();

		virtual cfsec::ICFSecTSecGrpMembEditObj* getTSecGrpMembEdit();

		virtual cfsec::ICFSecSecUserObj* getCreatedBy();
		virtual const std::chrono::system_clock::time_point& getCreatedAt();
		virtual cfsec::ICFSecSecUserObj* getUpdatedBy();
		virtual const std::chrono::system_clock::time_point& getUpdatedAt();

		virtual void copyPKeyToBuff();

		virtual void copyBuffToPKey();

	};
}
