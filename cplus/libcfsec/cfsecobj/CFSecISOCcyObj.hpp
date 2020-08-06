#pragma once

// Description: C++18 base object instance specification for CFSec ISOCcy.

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

#include <cfsecobj/ICFSecISOCcyObj.hpp>
#include <cfsecobj/ICFSecSchemaObj.hpp>

namespace cfsec {

	class CFSecISOCcyObj
	: public virtual ICFSecISOCcyObj
	{
	protected:
		cfsec::ICFSecSecUserObj* createdBy = NULL;
		cfsec::ICFSecSecUserObj* updatedBy = NULL;
		bool isNew;
		cfsec::ICFSecISOCcyEditObj* edit;
		cfsec::ICFSecSchemaObj* schema;
		cfsec::CFSecISOCcyPKey* pKey;
		cfsec::CFSecISOCcyBuff* buff;
	public:
		static const std::string CLASS_NAME;
		static const classcode_t CLASS_CODE;

		virtual const int16_t getRequiredISOCcyId();
		virtual const int16_t* getRequiredISOCcyIdReference();

		virtual const std::string& getRequiredISOCode();
		virtual const std::string* getRequiredISOCodeReference();

		virtual const std::string& getRequiredName();
		virtual const std::string* getRequiredNameReference();

		virtual bool isOptionalUnitSymbolNull();
		virtual const std::string& getOptionalUnitSymbolValue();
		virtual const std::string* getOptionalUnitSymbolReference();

		virtual const int16_t getRequiredPrecis();
		virtual const int16_t* getRequiredPrecisReference();

		virtual std::vector<cfsec::ICFSecISOCtryCcyObj*> getOptionalChildrenCtry( bool forceRead = false );

		CFSecISOCcyObj();
		CFSecISOCcyObj( cfsec::ICFSecSchemaObj* argSchema );
		virtual const std::string& getClassName() const;
		virtual ~CFSecISOCcyObj();
		virtual const classcode_t getClassCode() const;

		virtual bool implementsClassCode( const classcode_t value ) const;

		virtual int32_t getRequiredRevision() const;

		virtual std::string toString();
		virtual cfsec::CFSecISOCcyBuff* getBuff();
		virtual void setBuff( cfsec::CFSecISOCcyBuff* value );

		inline cfsec::CFSecISOCcyBuff* getISOCcyBuff() {
			if( buff == NULL ) {
				getBuff();
			}
			return( static_cast<cfsec::CFSecISOCcyBuff*>( buff ) );
		};

		inline cfsec::CFSecISOCcyBuff* getISOCcyEditBuff() {
			if( buff == NULL ) {
				getBuff();
			}
			return( dynamic_cast<cfsec::CFSecISOCcyBuff*>( buff ) );
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

		virtual cfsec::ICFSecISOCcyObj* realize();

		virtual cfsec::ICFSecISOCcyObj* read( bool forceRead = false );

		virtual cfsec::ICFSecISOCcyTableObj* getISOCcyTable();

		virtual cfsec::ICFSecSchemaObj* getSchema();
		virtual void setSchema( cfsec::ICFSecSchemaObj* value );

		virtual cfsec::CFSecISOCcyPKey* getPKey();
		virtual void setPKey( cfsec::CFSecISOCcyPKey* value );

		virtual bool getIsNew();
		virtual void setIsNew( bool value );

		virtual cfsec::ICFSecISOCcyEditObj* beginEdit();

		virtual void endEdit();

		virtual cfsec::ICFSecISOCcyEditObj* getEdit();

		virtual cfsec::ICFSecISOCcyEditObj* getISOCcyEdit();

		virtual cfsec::ICFSecSecUserObj* getCreatedBy();
		virtual const std::chrono::system_clock::time_point& getCreatedAt();
		virtual cfsec::ICFSecSecUserObj* getUpdatedBy();
		virtual const std::chrono::system_clock::time_point& getUpdatedAt();

		virtual void copyPKeyToBuff();

		virtual void copyBuffToPKey();

	};
}
