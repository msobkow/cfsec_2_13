#pragma once

// Description: C++18 edit object instance specification for CFSec ISOLang.

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
#include <cfsecobj/ICFSecObjPublic.hpp>

namespace cfsec {

	class CFSecISOLangEditObj
	: public virtual ICFSecISOLangEditObj
	{
	public:
		static const std::string CLASS_NAME;
	protected:
		cfsec::ICFSecISOLangObj* orig;
		cfsec::CFSecISOLangBuff* buff;
		cfsec::ICFSecSecUserObj* createdBy = NULL;
		cfsec::ICFSecSecUserObj* updatedBy = NULL;
	public:
		CFSecISOLangEditObj( cfsec::ICFSecISOLangObj* argOrig );
		virtual ~CFSecISOLangEditObj();

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

		virtual ICFSecISOLangObj* realize();

		virtual cfsec::ICFSecISOLangObj* read( bool forceRead = false );

		virtual ICFSecISOLangObj* create();

		virtual ICFSecISOLangEditObj* update();

		virtual ICFSecISOLangEditObj* deleteInstance();

		virtual cfsec::ICFSecISOLangTableObj* getISOLangTable();

		virtual cfsec::ICFSecISOLangEditObj* getEdit();

		virtual cfsec::ICFSecISOLangEditObj* getISOLangEdit();

		virtual ICFSecISOLangEditObj* beginEdit();

		virtual void endEdit();

		virtual cfsec::ICFSecISOLangObj* getOrig();

		virtual cfsec::ICFSecISOLangObj* getOrigAsISOLang();

		virtual cfsec::ICFSecSchemaObj* getSchema();

		virtual cfsec::CFSecISOLangBuff* getBuff();
		virtual void setBuff( cfsec::CFSecISOLangBuff* value );

		inline cfsec::CFSecISOLangBuff* getISOLangBuff() {
			// Buff is always instantiated when constructed over an original object
			return( static_cast<cfsec::CFSecISOLangBuff*>( buff ) );
		};

		inline cfsec::CFSecISOLangBuff* getISOLangEditBuff() {
			// Buff is always instantiated when constructed over an original object
			return( dynamic_cast<cfsec::CFSecISOLangBuff*>( buff ) );
		};

		virtual cfsec::CFSecISOLangPKey* getPKey();
		virtual void setPKey( cfsec::CFSecISOLangPKey* value );

		virtual bool getIsNew();
		virtual void setIsNew( bool value );

		virtual const int16_t getRequiredISOLangId();
		virtual const int16_t* getRequiredISOLangIdReference();

		virtual const std::string& getRequiredISO6392Code();
		virtual const std::string* getRequiredISO6392CodeReference();
		virtual void setRequiredISO6392Code( const std::string& value );

		virtual bool isOptionalISO6391CodeNull();
		virtual const std::string& getOptionalISO6391CodeValue();
		virtual const std::string* getOptionalISO6391CodeReference();
		virtual void setOptionalISO6391CodeNull();
		virtual void setOptionalISO6391CodeValue( const std::string& value );

		virtual const std::string& getRequiredEnglishName();
		virtual const std::string* getRequiredEnglishNameReference();
		virtual void setRequiredEnglishName( const std::string& value );

		virtual std::vector<cfsec::ICFSecISOCtryLangObj*> getOptionalChildrenCtry( bool forceRead = false );

		virtual void copyPKeyToBuff();

		virtual void copyBuffToPKey();

		virtual void copyBuffToOrig();

		virtual void copyOrigToBuff();

	};
}
