#pragma once

// Description: C++18 edit object instance specification for CFSec Service.

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

	class CFSecServiceEditObj
	: public virtual ICFSecServiceEditObj
	{
	public:
		static const std::string CLASS_NAME;
	protected:
		cfsec::ICFSecServiceObj* orig;
		cfsec::CFSecServiceBuff* buff;
		cfsec::ICFSecSecUserObj* createdBy = NULL;
		cfsec::ICFSecSecUserObj* updatedBy = NULL;
	public:
		CFSecServiceEditObj( cfsec::ICFSecServiceObj* argOrig );
		virtual ~CFSecServiceEditObj();

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

		virtual ICFSecServiceObj* realize();

		virtual cfsec::ICFSecServiceObj* read( bool forceRead = false );

		virtual ICFSecServiceObj* create();

		virtual ICFSecServiceEditObj* update();

		virtual ICFSecServiceEditObj* deleteInstance();

		virtual cfsec::ICFSecServiceTableObj* getServiceTable();

		virtual cfsec::ICFSecServiceEditObj* getEdit();

		virtual cfsec::ICFSecServiceEditObj* getServiceEdit();

		virtual ICFSecServiceEditObj* beginEdit();

		virtual void endEdit();

		virtual cfsec::ICFSecServiceObj* getOrig();

		virtual cfsec::ICFSecServiceObj* getOrigAsService();

		virtual cfsec::ICFSecSchemaObj* getSchema();

		virtual cfsec::CFSecServiceBuff* getBuff();
		virtual void setBuff( cfsec::CFSecServiceBuff* value );

		inline cfsec::CFSecServiceBuff* getServiceBuff() {
			// Buff is always instantiated when constructed over an original object
			return( static_cast<cfsec::CFSecServiceBuff*>( buff ) );
		};

		inline cfsec::CFSecServiceBuff* getServiceEditBuff() {
			// Buff is always instantiated when constructed over an original object
			return( dynamic_cast<cfsec::CFSecServiceBuff*>( buff ) );
		};

		virtual cfsec::CFSecServicePKey* getPKey();
		virtual void setPKey( cfsec::CFSecServicePKey* value );

		virtual bool getIsNew();
		virtual void setIsNew( bool value );

		virtual const int64_t getRequiredClusterId();
		virtual const int64_t* getRequiredClusterIdReference();

		virtual const int64_t getRequiredServiceId();
		virtual const int64_t* getRequiredServiceIdReference();

		virtual const int64_t getRequiredHostNodeId();
		virtual const int64_t* getRequiredHostNodeIdReference();

		virtual const int32_t getRequiredServiceTypeId();
		virtual const int32_t* getRequiredServiceTypeIdReference();

		virtual const int16_t getRequiredHostPort();
		virtual const int16_t* getRequiredHostPortReference();
		virtual void setRequiredHostPort( const int16_t value );

		virtual cfsec::ICFSecClusterObj* getRequiredOwnerCluster( bool forceRead = false );
		virtual void setRequiredOwnerCluster( cfsec::ICFSecClusterObj* value );

		virtual cfsec::ICFSecHostNodeObj* getOptionalContainerHost( bool forceRead = false );
		virtual void setOptionalContainerHost( cfsec::ICFSecHostNodeObj* value );

		virtual cfsec::ICFSecServiceTypeObj* getOptionalParentServiceType( bool forceRead = false );
		virtual void setOptionalParentServiceType( cfsec::ICFSecServiceTypeObj* value );

		virtual void copyPKeyToBuff();

		virtual void copyBuffToPKey();

		virtual void copyBuffToOrig();

		virtual void copyOrigToBuff();

	};
}
