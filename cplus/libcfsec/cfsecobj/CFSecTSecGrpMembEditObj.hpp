#pragma once

// Description: C++18 edit object instance specification for CFSec TSecGrpMemb.

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
#include <cfsecobj/ICFSecObjPublic.hpp>

namespace cfsec {

	class CFSecTSecGrpMembEditObj
	: public virtual ICFSecTSecGrpMembEditObj
	{
	public:
		static const std::string CLASS_NAME;
	protected:
		cfsec::ICFSecTSecGrpMembObj* orig;
		cfsec::CFSecTSecGrpMembBuff* buff;
		cfsec::ICFSecSecUserObj* createdBy = NULL;
		cfsec::ICFSecSecUserObj* updatedBy = NULL;
	public:
		CFSecTSecGrpMembEditObj( cfsec::ICFSecTSecGrpMembObj* argOrig );
		virtual ~CFSecTSecGrpMembEditObj();

		virtual const std::string& getClassName() const;

		virtual int32_t getRequiredRevision() const;
		virtual void setRequiredRevision( int32_t value );
		virtual cfsec::ICFSecSecUserObj* getCreatedBy();
		virtual const std::chrono::system_clock::time_point& getCreatedAt();
		virtual cfsec::ICFSecSecUserObj* getUpdatedBy();
		virtual const std::chrono::system_clock::time_point& getUpdatedAt();

		virtual void setCreatedBy( cfsec::ICFSecSecUserObj* value );
		virtual void setCreatedAt( const std::chrono::system_clock::time_point& value );
		virtual void setUpdatedBy( cfsec::ICFSecSecUserObj* value );
		virtual void setUpdatedAt( const std::chrono::system_clock::time_point& value );

		virtual const classcode_t getClassCode() const;
		virtual bool implementsClassCode( const classcode_t value ) const;
		virtual std::string toString();

		virtual std::string getObjName();

		virtual const std::string getGenDefName();

		virtual cflib::ICFLibAnyObj* getScope();
		virtual cflib::ICFLibAnyObj* getObjScope();

		virtual cflib::ICFLibAnyObj* getObjQualifier( const classcode_t* qualifyingClass );

		virtual cflib::ICFLibAnyObj* getNamedObject( const classcode_t* qualifyingClass, const std::string& objName );

		virtual cflib::ICFLibAnyObj* getNamedObject( const std::string& objName );

		virtual std::string getObjQualifiedName();

		virtual std::string getObjFullName();

		virtual ICFSecTSecGrpMembObj* realize();

		virtual cfsec::ICFSecTSecGrpMembObj* read( bool forceRead = false );

		virtual ICFSecTSecGrpMembObj* create();

		virtual ICFSecTSecGrpMembEditObj* update();

		virtual ICFSecTSecGrpMembEditObj* deleteInstance();

		virtual cfsec::ICFSecTSecGrpMembTableObj* getTSecGrpMembTable();

		virtual cfsec::ICFSecTSecGrpMembEditObj* getEdit();

		virtual cfsec::ICFSecTSecGrpMembEditObj* getTSecGrpMembEdit();

		virtual ICFSecTSecGrpMembEditObj* beginEdit();

		virtual void endEdit();

		virtual cfsec::ICFSecTSecGrpMembObj* getOrig();

		virtual cfsec::ICFSecTSecGrpMembObj* getOrigAsTSecGrpMemb();

		virtual cfsec::ICFSecSchemaObj* getSchema();

		virtual cfsec::CFSecTSecGrpMembBuff* getBuff();
		virtual void setBuff( cfsec::CFSecTSecGrpMembBuff* value );

		inline cfsec::CFSecTSecGrpMembBuff* getTSecGrpMembBuff() {
			// Buff is always instantiated when constructed over an original object
			return( static_cast<cfsec::CFSecTSecGrpMembBuff*>( buff ) );
		};

		inline cfsec::CFSecTSecGrpMembBuff* getTSecGrpMembEditBuff() {
			// Buff is always instantiated when constructed over an original object
			return( dynamic_cast<cfsec::CFSecTSecGrpMembBuff*>( buff ) );
		};

		virtual cfsec::CFSecTSecGrpMembPKey* getPKey();
		virtual void setPKey( cfsec::CFSecTSecGrpMembPKey* value );

		virtual bool getIsNew();
		virtual void setIsNew( bool value );

		virtual const int64_t getRequiredTenantId();
		virtual const int64_t* getRequiredTenantIdReference();

		virtual const int64_t getRequiredTSecGrpMembId();
		virtual const int64_t* getRequiredTSecGrpMembIdReference();

		virtual const int32_t getRequiredTSecGroupId();
		virtual const int32_t* getRequiredTSecGroupIdReference();

		virtual const uuid_ptr_t getRequiredSecUserId();
		virtual const uuid_ptr_t getRequiredSecUserIdReference();

		virtual cfsec::ICFSecTenantObj* getRequiredOwnerTenant( bool forceRead = false );
		virtual void setRequiredOwnerTenant( cfsec::ICFSecTenantObj* value );

		virtual cfsec::ICFSecTSecGroupObj* getRequiredContainerGroup( bool forceRead = false );
		virtual void setRequiredContainerGroup( cfsec::ICFSecTSecGroupObj* value );

		virtual cfsec::ICFSecSecUserObj* getRequiredParentUser( bool forceRead = false );
		virtual void setRequiredParentUser( cfsec::ICFSecSecUserObj* value );

		virtual void copyPKeyToBuff();

		virtual void copyBuffToPKey();

		virtual void copyBuffToOrig();

		virtual void copyOrigToBuff();

	};
}
