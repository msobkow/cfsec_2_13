#pragma once

// Description: C++18 Instance Edit Object interface for CFSec ISOCtryCcy.

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
#include <cfsec/CFSecISOCtryCcyBuff.hpp>

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

#include <cfsecobj/ICFSecISOCtryCcyObj.hpp>

namespace cfsec {

	class ICFSecISOCtryCcyEditObj
	: public virtual cfsec::ICFSecISOCtryCcyObj
	{
	public:
		static const std::string CLASS_NAME;
		ICFSecISOCtryCcyEditObj();
		virtual ~ICFSecISOCtryCcyEditObj();
		virtual const std::string& getClassName() const = 0;

		inline cfsec::CFSecISOCtryCcyBuff* getISOCtryCcyBuff() {
			return( static_cast<cfsec::CFSecISOCtryCcyBuff*>( getBuff() ) );
		};

		inline cfsec::CFSecISOCtryCcyBuff* getISOCtryCcyEditBuff() {
			return( dynamic_cast<cfsec::CFSecISOCtryCcyBuff*>( getBuff() ) );
		};

		virtual cfsec::ICFSecISOCtryCcyObj* getOrig() = 0;

		virtual cfsec::ICFSecISOCtryCcyObj* getOrigAsISOCtryCcy() = 0;

		virtual int32_t getRequiredRevision() const = 0;
		virtual void setRequiredRevision( int32_t value ) = 0;
		virtual cfsec::ICFSecISOCtryCcyEditObj* beginEdit() = 0;

		virtual cfsec::ICFSecISOCtryCcyObj* create() = 0;

		virtual cfsec::ICFSecISOCtryCcyEditObj* update() = 0;

		virtual cfsec::ICFSecISOCtryCcyEditObj* deleteInstance() = 0;

		virtual cfsec::ICFSecISOCtryObj* getRequiredContainerCtry( bool forceRead = false ) = 0;
		virtual void setRequiredContainerCtry( cfsec::ICFSecISOCtryObj* value ) = 0;

		virtual cfsec::ICFSecISOCcyObj* getRequiredParentCcy( bool forceRead = false ) = 0;
		virtual void setRequiredParentCcy( cfsec::ICFSecISOCcyObj* value ) = 0;

		virtual void setCreatedBy( cfsec::ICFSecSecUserObj* value ) = 0;
		virtual void setCreatedAt( const std::chrono::system_clock::time_point& value ) = 0;

		virtual void setUpdatedBy( cfsec::ICFSecSecUserObj* value ) = 0;
		virtual void setUpdatedAt( const std::chrono::system_clock::time_point& value ) = 0;
	};
}
