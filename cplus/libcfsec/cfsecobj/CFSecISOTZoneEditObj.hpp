#pragma once

// Description: C++18 edit object instance specification for CFSec ISOTZone.

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

	class CFSecISOTZoneEditObj
	: public virtual ICFSecISOTZoneEditObj
	{
	public:
		static const std::string CLASS_NAME;
	protected:
		cfsec::ICFSecISOTZoneObj* orig;
		cfsec::CFSecISOTZoneBuff* buff;
		cfsec::ICFSecSecUserObj* createdBy = NULL;
		cfsec::ICFSecSecUserObj* updatedBy = NULL;
	public:
		CFSecISOTZoneEditObj( cfsec::ICFSecISOTZoneObj* argOrig );
		virtual ~CFSecISOTZoneEditObj();

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

		virtual ICFSecISOTZoneObj* realize();

		virtual cfsec::ICFSecISOTZoneObj* read( bool forceRead = false );

		virtual ICFSecISOTZoneObj* create();

		virtual ICFSecISOTZoneEditObj* update();

		virtual ICFSecISOTZoneEditObj* deleteInstance();

		virtual cfsec::ICFSecISOTZoneTableObj* getISOTZoneTable();

		virtual cfsec::ICFSecISOTZoneEditObj* getEdit();

		virtual cfsec::ICFSecISOTZoneEditObj* getISOTZoneEdit();

		virtual ICFSecISOTZoneEditObj* beginEdit();

		virtual void endEdit();

		virtual cfsec::ICFSecISOTZoneObj* getOrig();

		virtual cfsec::ICFSecISOTZoneObj* getOrigAsISOTZone();

		virtual cfsec::ICFSecSchemaObj* getSchema();

		virtual cfsec::CFSecISOTZoneBuff* getBuff();
		virtual void setBuff( cfsec::CFSecISOTZoneBuff* value );

		inline cfsec::CFSecISOTZoneBuff* getISOTZoneBuff() {
			// Buff is always instantiated when constructed over an original object
			return( static_cast<cfsec::CFSecISOTZoneBuff*>( buff ) );
		};

		inline cfsec::CFSecISOTZoneBuff* getISOTZoneEditBuff() {
			// Buff is always instantiated when constructed over an original object
			return( dynamic_cast<cfsec::CFSecISOTZoneBuff*>( buff ) );
		};

		virtual cfsec::CFSecISOTZonePKey* getPKey();
		virtual void setPKey( cfsec::CFSecISOTZonePKey* value );

		virtual bool getIsNew();
		virtual void setIsNew( bool value );

		virtual const int16_t getRequiredISOTZoneId();
		virtual const int16_t* getRequiredISOTZoneIdReference();

		virtual const std::string& getRequiredIso8601();
		virtual const std::string* getRequiredIso8601Reference();
		virtual void setRequiredIso8601( const std::string& value );

		virtual const std::string& getRequiredTZName();
		virtual const std::string* getRequiredTZNameReference();
		virtual void setRequiredTZName( const std::string& value );

		virtual const int16_t getRequiredTZHourOffset();
		virtual const int16_t* getRequiredTZHourOffsetReference();
		virtual void setRequiredTZHourOffset( const int16_t value );

		virtual const int16_t getRequiredTZMinOffset();
		virtual const int16_t* getRequiredTZMinOffsetReference();
		virtual void setRequiredTZMinOffset( const int16_t value );

		virtual const std::string& getRequiredDescription();
		virtual const std::string* getRequiredDescriptionReference();
		virtual void setRequiredDescription( const std::string& value );

		virtual const bool getRequiredVisible();
		virtual const bool* getRequiredVisibleReference();
		virtual void setRequiredVisible( const bool value );

		virtual void copyPKeyToBuff();

		virtual void copyBuffToPKey();

		virtual void copyBuffToOrig();

		virtual void copyOrigToBuff();

	};
}
