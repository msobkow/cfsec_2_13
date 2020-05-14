#pragma once

// Description: C++18 base object instance specification for CFSec SysCluster.

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

#include <cfsecobj/ICFSecSysClusterObj.hpp>
#include <cfsecobj/ICFSecSchemaObj.hpp>

namespace cfsec {

	class CFSecSysClusterObj
	: public virtual ICFSecSysClusterObj
	{
	protected:
		bool isNew;
		cfsec::ICFSecSysClusterEditObj* edit;
		cfsec::ICFSecSchemaObj* schema;
		cfsec::CFSecSysClusterPKey* pKey;
		cfsec::CFSecSysClusterBuff* buff;
	public:
		static const std::string CLASS_NAME;
		static const classcode_t CLASS_CODE;

		virtual const int32_t getRequiredSingletonId();
		virtual const int32_t* getRequiredSingletonIdReference();

		virtual const int64_t getRequiredClusterId();
		virtual const int64_t* getRequiredClusterIdReference();

		virtual cfsec::ICFSecClusterObj* getRequiredContainerCluster( bool forceRead = false );

		CFSecSysClusterObj();
		CFSecSysClusterObj( cfsec::ICFSecSchemaObj* argSchema );
		virtual const std::string& getClassName() const;
		virtual ~CFSecSysClusterObj();
		virtual const classcode_t getClassCode() const;

		virtual bool implementsClassCode( const classcode_t value ) const;

		virtual int32_t getRequiredRevision() const;

		virtual std::string toString();
		virtual cfsec::CFSecSysClusterBuff* getBuff();
		virtual void setBuff( cfsec::CFSecSysClusterBuff* value );

		inline cfsec::CFSecSysClusterBuff* getSysClusterBuff() {
			if( buff == NULL ) {
				getBuff();
			}
			return( static_cast<cfsec::CFSecSysClusterBuff*>( buff ) );
		};

		inline cfsec::CFSecSysClusterBuff* getSysClusterEditBuff() {
			if( buff == NULL ) {
				getBuff();
			}
			return( dynamic_cast<cfsec::CFSecSysClusterBuff*>( buff ) );
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

		virtual cfsec::ICFSecSysClusterObj* realize();

		virtual cfsec::ICFSecSysClusterObj* read( bool forceRead = false );

		virtual cfsec::ICFSecSysClusterTableObj* getSysClusterTable();

		virtual cfsec::ICFSecSchemaObj* getSchema();
		virtual void setSchema( cfsec::ICFSecSchemaObj* value );

		virtual cfsec::CFSecSysClusterPKey* getPKey();
		virtual void setPKey( cfsec::CFSecSysClusterPKey* value );

		virtual bool getIsNew();
		virtual void setIsNew( bool value );

		virtual cfsec::ICFSecSysClusterEditObj* beginEdit();

		virtual void endEdit();

		virtual cfsec::ICFSecSysClusterEditObj* getEdit();

		virtual cfsec::ICFSecSysClusterEditObj* getSysClusterEdit();

		virtual void copyPKeyToBuff();

		virtual void copyBuffToPKey();

	};
}
