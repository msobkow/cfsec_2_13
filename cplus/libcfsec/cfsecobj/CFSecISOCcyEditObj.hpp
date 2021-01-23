#pragma once

// Description: C++18 edit object instance specification for CFSec ISOCcy.

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
#include <cfsecobj/ICFSecObjPublic.hpp>

namespace cfsec {

	class CFSecISOCcyEditObj
	: public virtual ICFSecISOCcyEditObj
	{
	public:
		static const std::string CLASS_NAME;
	protected:
		cfsec::ICFSecISOCcyObj* orig;
		cfsec::CFSecISOCcyBuff* buff;
		cfsec::ICFSecSecUserObj* createdBy = NULL;
		cfsec::ICFSecSecUserObj* updatedBy = NULL;
	public:
		CFSecISOCcyEditObj( cfsec::ICFSecISOCcyObj* argOrig );
		virtual ~CFSecISOCcyEditObj();

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

		virtual ICFSecISOCcyObj* realize();

		virtual cfsec::ICFSecISOCcyObj* read( bool forceRead = false );

		virtual ICFSecISOCcyObj* create();

		virtual ICFSecISOCcyEditObj* update();

		virtual ICFSecISOCcyEditObj* deleteInstance();

		virtual cfsec::ICFSecISOCcyTableObj* getISOCcyTable();

		virtual cfsec::ICFSecISOCcyEditObj* getEdit();

		virtual cfsec::ICFSecISOCcyEditObj* getISOCcyEdit();

		virtual ICFSecISOCcyEditObj* beginEdit();

		virtual void endEdit();

		virtual cfsec::ICFSecISOCcyObj* getOrig();

		virtual cfsec::ICFSecISOCcyObj* getOrigAsISOCcy();

		virtual cfsec::ICFSecSchemaObj* getSchema();

		virtual cfsec::CFSecISOCcyBuff* getBuff();
		virtual void setBuff( cfsec::CFSecISOCcyBuff* value );

		inline cfsec::CFSecISOCcyBuff* getISOCcyBuff() {
			// Buff is always instantiated when constructed over an original object
			return( static_cast<cfsec::CFSecISOCcyBuff*>( buff ) );
		};

		inline cfsec::CFSecISOCcyBuff* getISOCcyEditBuff() {
			// Buff is always instantiated when constructed over an original object
			return( dynamic_cast<cfsec::CFSecISOCcyBuff*>( buff ) );
		};

		virtual cfsec::CFSecISOCcyPKey* getPKey();
		virtual void setPKey( cfsec::CFSecISOCcyPKey* value );

		virtual bool getIsNew();
		virtual void setIsNew( bool value );

		virtual const int16_t getRequiredISOCcyId();
		virtual const int16_t* getRequiredISOCcyIdReference();

		virtual const std::string& getRequiredISOCode();
		virtual const std::string* getRequiredISOCodeReference();
		virtual void setRequiredISOCode( const std::string& value );

		virtual const std::string& getRequiredName();
		virtual const std::string* getRequiredNameReference();
		virtual void setRequiredName( const std::string& value );

		virtual bool isOptionalUnitSymbolNull();
		virtual const std::string& getOptionalUnitSymbolValue();
		virtual const std::string* getOptionalUnitSymbolReference();
		virtual void setOptionalUnitSymbolNull();
		virtual void setOptionalUnitSymbolValue( const std::string& value );

		virtual const int16_t getRequiredPrecis();
		virtual const int16_t* getRequiredPrecisReference();
		virtual void setRequiredPrecis( const int16_t value );

		virtual std::vector<cfsec::ICFSecISOCtryCcyObj*> getOptionalChildrenCtry( bool forceRead = false );

		virtual void copyPKeyToBuff();

		virtual void copyBuffToPKey();

		virtual void copyBuffToOrig();

		virtual void copyOrigToBuff();

	};
}
