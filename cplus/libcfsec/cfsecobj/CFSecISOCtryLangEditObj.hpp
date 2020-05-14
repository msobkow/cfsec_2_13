#pragma once

// Description: C++18 edit object instance specification for CFSec ISOCtryLang.

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

	class CFSecISOCtryLangEditObj
	: public virtual ICFSecISOCtryLangEditObj
	{
	public:
		static const std::string CLASS_NAME;
	protected:
		cfsec::ICFSecISOCtryLangObj* orig;
		cfsec::CFSecISOCtryLangBuff* buff;
		cfsec::ICFSecSecUserObj* createdBy = NULL;
		cfsec::ICFSecSecUserObj* updatedBy = NULL;
	public:
		CFSecISOCtryLangEditObj( cfsec::ICFSecISOCtryLangObj* argOrig );
		virtual ~CFSecISOCtryLangEditObj();

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

		virtual ICFSecISOCtryLangObj* realize();

		virtual cfsec::ICFSecISOCtryLangObj* read( bool forceRead = false );

		virtual ICFSecISOCtryLangObj* create();

		virtual ICFSecISOCtryLangEditObj* update();

		virtual ICFSecISOCtryLangEditObj* deleteInstance();

		virtual cfsec::ICFSecISOCtryLangTableObj* getISOCtryLangTable();

		virtual cfsec::ICFSecISOCtryLangEditObj* getEdit();

		virtual cfsec::ICFSecISOCtryLangEditObj* getISOCtryLangEdit();

		virtual ICFSecISOCtryLangEditObj* beginEdit();

		virtual void endEdit();

		virtual cfsec::ICFSecISOCtryLangObj* getOrig();

		virtual cfsec::ICFSecISOCtryLangObj* getOrigAsISOCtryLang();

		virtual cfsec::ICFSecSchemaObj* getSchema();

		virtual cfsec::CFSecISOCtryLangBuff* getBuff();
		virtual void setBuff( cfsec::CFSecISOCtryLangBuff* value );

		inline cfsec::CFSecISOCtryLangBuff* getISOCtryLangBuff() {
			// Buff is always instantiated when constructed over an original object
			return( static_cast<cfsec::CFSecISOCtryLangBuff*>( buff ) );
		};

		inline cfsec::CFSecISOCtryLangBuff* getISOCtryLangEditBuff() {
			// Buff is always instantiated when constructed over an original object
			return( dynamic_cast<cfsec::CFSecISOCtryLangBuff*>( buff ) );
		};

		virtual cfsec::CFSecISOCtryLangPKey* getPKey();
		virtual void setPKey( cfsec::CFSecISOCtryLangPKey* value );

		virtual bool getIsNew();
		virtual void setIsNew( bool value );

		virtual const int16_t getRequiredISOCtryId();
		virtual const int16_t* getRequiredISOCtryIdReference();

		virtual const int16_t getRequiredISOLangId();
		virtual const int16_t* getRequiredISOLangIdReference();

		virtual cfsec::ICFSecISOCtryObj* getRequiredContainerCtry( bool forceRead = false );
		virtual void setRequiredContainerCtry( cfsec::ICFSecISOCtryObj* value );

		virtual cfsec::ICFSecISOLangObj* getRequiredParentLang( bool forceRead = false );
		virtual void setRequiredParentLang( cfsec::ICFSecISOLangObj* value );

		virtual void copyPKeyToBuff();

		virtual void copyBuffToPKey();

		virtual void copyBuffToOrig();

		virtual void copyOrigToBuff();

	};
}
