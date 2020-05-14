#pragma once

// Description: C++18 edit object instance specification for CFSec SecForm.

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
#include <cfsecobj/ICFSecObjPublic.hpp>

namespace cfsec {

	class CFSecSecFormEditObj
	: public virtual ICFSecSecFormEditObj
	{
	public:
		static const std::string CLASS_NAME;
	protected:
		cfsec::ICFSecSecFormObj* orig;
		cfsec::CFSecSecFormBuff* buff;
		cfsec::ICFSecSecUserObj* createdBy = NULL;
		cfsec::ICFSecSecUserObj* updatedBy = NULL;
	public:
		CFSecSecFormEditObj( cfsec::ICFSecSecFormObj* argOrig );
		virtual ~CFSecSecFormEditObj();

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

		virtual ICFSecSecFormObj* realize();

		virtual cfsec::ICFSecSecFormObj* read( bool forceRead = false );

		virtual ICFSecSecFormObj* create();

		virtual ICFSecSecFormEditObj* update();

		virtual ICFSecSecFormEditObj* deleteInstance();

		virtual cfsec::ICFSecSecFormTableObj* getSecFormTable();

		virtual cfsec::ICFSecSecFormEditObj* getEdit();

		virtual cfsec::ICFSecSecFormEditObj* getSecFormEdit();

		virtual ICFSecSecFormEditObj* beginEdit();

		virtual void endEdit();

		virtual cfsec::ICFSecSecFormObj* getOrig();

		virtual cfsec::ICFSecSecFormObj* getOrigAsSecForm();

		virtual cfsec::ICFSecSchemaObj* getSchema();

		virtual cfsec::CFSecSecFormBuff* getBuff();
		virtual void setBuff( cfsec::CFSecSecFormBuff* value );

		inline cfsec::CFSecSecFormBuff* getSecFormBuff() {
			// Buff is always instantiated when constructed over an original object
			return( static_cast<cfsec::CFSecSecFormBuff*>( buff ) );
		};

		inline cfsec::CFSecSecFormBuff* getSecFormEditBuff() {
			// Buff is always instantiated when constructed over an original object
			return( dynamic_cast<cfsec::CFSecSecFormBuff*>( buff ) );
		};

		virtual cfsec::CFSecSecFormPKey* getPKey();
		virtual void setPKey( cfsec::CFSecSecFormPKey* value );

		virtual bool getIsNew();
		virtual void setIsNew( bool value );

		virtual const int64_t getRequiredClusterId();
		virtual const int64_t* getRequiredClusterIdReference();

		virtual const int32_t getRequiredSecFormId();
		virtual const int32_t* getRequiredSecFormIdReference();

		virtual const int32_t getRequiredSecAppId();
		virtual const int32_t* getRequiredSecAppIdReference();

		virtual const std::string& getRequiredJEEServletMapName();
		virtual const std::string* getRequiredJEEServletMapNameReference();
		virtual void setRequiredJEEServletMapName( const std::string& value );

		virtual cfsec::ICFSecClusterObj* getRequiredOwnerCluster( bool forceRead = false );
		virtual void setRequiredOwnerCluster( cfsec::ICFSecClusterObj* value );

		virtual cfsec::ICFSecSecAppObj* getRequiredContainerApplication( bool forceRead = false );
		virtual void setRequiredContainerApplication( cfsec::ICFSecSecAppObj* value );

		virtual void copyPKeyToBuff();

		virtual void copyBuffToPKey();

		virtual void copyBuffToOrig();

		virtual void copyOrigToBuff();

	};
}
