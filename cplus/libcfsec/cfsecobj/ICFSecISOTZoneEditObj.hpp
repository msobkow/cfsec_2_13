#pragma once

// Description: C++18 Instance Edit Object interface for CFSec ISOTZone.

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
#include <cfsec/CFSecISOTZoneBuff.hpp>

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

#include <cfsecobj/ICFSecISOTZoneObj.hpp>

namespace cfsec {

	class ICFSecISOTZoneEditObj
	: public virtual cfsec::ICFSecISOTZoneObj
	{
	public:
		static const std::string CLASS_NAME;
		ICFSecISOTZoneEditObj();
		virtual ~ICFSecISOTZoneEditObj();
		virtual const std::string& getClassName() const = 0;

		inline cfsec::CFSecISOTZoneBuff* getISOTZoneBuff() {
			return( static_cast<cfsec::CFSecISOTZoneBuff*>( getBuff() ) );
		};

		inline cfsec::CFSecISOTZoneBuff* getISOTZoneEditBuff() {
			return( dynamic_cast<cfsec::CFSecISOTZoneBuff*>( getBuff() ) );
		};

		virtual cfsec::ICFSecISOTZoneObj* getOrig() = 0;

		virtual cfsec::ICFSecISOTZoneObj* getOrigAsISOTZone() = 0;

		virtual int32_t getRequiredRevision() const = 0;
		virtual void setRequiredRevision( int32_t value ) = 0;
		virtual cfsec::ICFSecISOTZoneEditObj* beginEdit() = 0;

		virtual cfsec::ICFSecISOTZoneObj* create() = 0;

		virtual cfsec::ICFSecISOTZoneEditObj* update() = 0;

		virtual cfsec::ICFSecISOTZoneEditObj* deleteInstance() = 0;

		virtual const std::string& getRequiredIso8601() = 0;
		virtual const std::string* getRequiredIso8601Reference() = 0;
		virtual void setRequiredIso8601( const std::string& value ) = 0;

		virtual const std::string& getRequiredTZName() = 0;
		virtual const std::string* getRequiredTZNameReference() = 0;
		virtual void setRequiredTZName( const std::string& value ) = 0;

		virtual const int16_t getRequiredTZHourOffset() = 0;
		virtual const int16_t* getRequiredTZHourOffsetReference() = 0;
		virtual void setRequiredTZHourOffset( const int16_t value ) = 0;

		virtual const int16_t getRequiredTZMinOffset() = 0;
		virtual const int16_t* getRequiredTZMinOffsetReference() = 0;
		virtual void setRequiredTZMinOffset( const int16_t value ) = 0;

		virtual const std::string& getRequiredDescription() = 0;
		virtual const std::string* getRequiredDescriptionReference() = 0;
		virtual void setRequiredDescription( const std::string& value ) = 0;

		virtual const bool getRequiredVisible() = 0;
		virtual const bool* getRequiredVisibleReference() = 0;
		virtual void setRequiredVisible( const bool value ) = 0;

		virtual void setCreatedBy( cfsec::ICFSecSecUserObj* value ) = 0;
		virtual void setCreatedAt( const std::chrono::system_clock::time_point& value ) = 0;

		virtual void setUpdatedBy( cfsec::ICFSecSecUserObj* value ) = 0;
		virtual void setUpdatedAt( const std::chrono::system_clock::time_point& value ) = 0;
	};
}
