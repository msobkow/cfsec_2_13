#pragma once

// Description: C++18 Instance Edit Object interface for CFSec TSecGrpMemb.

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
#include <cfsec/CFSecTSecGrpMembBuff.hpp>

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

#include <cfsecobj/ICFSecTSecGrpMembObj.hpp>

namespace cfsec {

	class ICFSecTSecGrpMembEditObj
	: public virtual cfsec::ICFSecTSecGrpMembObj
	{
	public:
		static const std::string CLASS_NAME;
		ICFSecTSecGrpMembEditObj();
		virtual ~ICFSecTSecGrpMembEditObj();
		virtual const std::string& getClassName() const = 0;

		inline cfsec::CFSecTSecGrpMembBuff* getTSecGrpMembBuff() {
			return( static_cast<cfsec::CFSecTSecGrpMembBuff*>( getBuff() ) );
		};

		inline cfsec::CFSecTSecGrpMembBuff* getTSecGrpMembEditBuff() {
			return( dynamic_cast<cfsec::CFSecTSecGrpMembBuff*>( getBuff() ) );
		};

		virtual cfsec::ICFSecTSecGrpMembObj* getOrig() = 0;

		virtual cfsec::ICFSecTSecGrpMembObj* getOrigAsTSecGrpMemb() = 0;

		virtual int32_t getRequiredRevision() const = 0;
		virtual void setRequiredRevision( int32_t value ) = 0;
		virtual cfsec::ICFSecTSecGrpMembEditObj* beginEdit() = 0;

		virtual cfsec::ICFSecTSecGrpMembObj* create() = 0;

		virtual cfsec::ICFSecTSecGrpMembEditObj* update() = 0;

		virtual cfsec::ICFSecTSecGrpMembEditObj* deleteInstance() = 0;

		virtual cfsec::ICFSecTenantObj* getRequiredOwnerTenant( bool forceRead = false ) = 0;
		virtual void setRequiredOwnerTenant( cfsec::ICFSecTenantObj* value ) = 0;

		virtual cfsec::ICFSecTSecGroupObj* getRequiredContainerGroup( bool forceRead = false ) = 0;
		virtual void setRequiredContainerGroup( cfsec::ICFSecTSecGroupObj* value ) = 0;

		virtual cfsec::ICFSecSecUserObj* getRequiredParentUser( bool forceRead = false ) = 0;
		virtual void setRequiredParentUser( cfsec::ICFSecSecUserObj* value ) = 0;

		virtual void setCreatedBy( cfsec::ICFSecSecUserObj* value ) = 0;
		virtual void setCreatedAt( const std::chrono::system_clock::time_point& value ) = 0;

		virtual void setUpdatedBy( cfsec::ICFSecSecUserObj* value ) = 0;
		virtual void setUpdatedAt( const std::chrono::system_clock::time_point& value ) = 0;
	};
}
