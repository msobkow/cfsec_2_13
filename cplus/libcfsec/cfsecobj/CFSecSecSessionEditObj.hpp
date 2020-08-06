#pragma once

// Description: C++18 edit object instance specification for CFSec SecSession.

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

	class CFSecSecSessionEditObj
	: public virtual ICFSecSecSessionEditObj
	{
	public:
		static const std::string CLASS_NAME;
	protected:
		cfsec::ICFSecSecSessionObj* orig;
		cfsec::CFSecSecSessionBuff* buff;
	public:
		CFSecSecSessionEditObj( cfsec::ICFSecSecSessionObj* argOrig );
		virtual ~CFSecSecSessionEditObj();

		virtual const std::string& getClassName() const;

		virtual int32_t getRequiredRevision() const;
		virtual void setRequiredRevision( int32_t value );
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

		virtual ICFSecSecSessionObj* realize();

		virtual cfsec::ICFSecSecSessionObj* read( bool forceRead = false );

		virtual ICFSecSecSessionObj* create();

		virtual ICFSecSecSessionEditObj* update();

		virtual ICFSecSecSessionEditObj* deleteInstance();

		virtual cfsec::ICFSecSecSessionTableObj* getSecSessionTable();

		virtual cfsec::ICFSecSecSessionEditObj* getEdit();

		virtual cfsec::ICFSecSecSessionEditObj* getSecSessionEdit();

		virtual ICFSecSecSessionEditObj* beginEdit();

		virtual void endEdit();

		virtual cfsec::ICFSecSecSessionObj* getOrig();

		virtual cfsec::ICFSecSecSessionObj* getOrigAsSecSession();

		virtual cfsec::ICFSecSchemaObj* getSchema();

		virtual cfsec::CFSecSecSessionBuff* getBuff();
		virtual void setBuff( cfsec::CFSecSecSessionBuff* value );

		inline cfsec::CFSecSecSessionBuff* getSecSessionBuff() {
			// Buff is always instantiated when constructed over an original object
			return( static_cast<cfsec::CFSecSecSessionBuff*>( buff ) );
		};

		inline cfsec::CFSecSecSessionBuff* getSecSessionEditBuff() {
			// Buff is always instantiated when constructed over an original object
			return( dynamic_cast<cfsec::CFSecSecSessionBuff*>( buff ) );
		};

		virtual cfsec::CFSecSecSessionPKey* getPKey();
		virtual void setPKey( cfsec::CFSecSecSessionPKey* value );

		virtual bool getIsNew();
		virtual void setIsNew( bool value );

		virtual const uuid_ptr_t getRequiredSecSessionId();
		virtual const uuid_ptr_t getRequiredSecSessionIdReference();

		virtual const uuid_ptr_t getRequiredSecUserId();
		virtual const uuid_ptr_t getRequiredSecUserIdReference();

		virtual bool isOptionalSecDevNameNull();
		virtual const std::string& getOptionalSecDevNameValue();
		virtual const std::string* getOptionalSecDevNameReference();
		virtual void setOptionalSecDevNameNull();
		virtual void setOptionalSecDevNameValue( const std::string& value );

		virtual const std::chrono::system_clock::time_point& getRequiredStart();
		virtual const std::chrono::system_clock::time_point* getRequiredStartReference();
		virtual void setRequiredStart( const std::chrono::system_clock::time_point& value );

		virtual bool isOptionalFinishNull();
		virtual const std::chrono::system_clock::time_point& getOptionalFinishValue();
		virtual const std::chrono::system_clock::time_point* getOptionalFinishReference();
		virtual void setOptionalFinishNull();
		virtual void setOptionalFinishValue( const std::chrono::system_clock::time_point& value );

		virtual bool isOptionalSecProxyIdNull();
		virtual const uuid_ptr_t getOptionalSecProxyIdValue();
		virtual const uuid_ptr_t getOptionalSecProxyIdReference();

		virtual cfsec::ICFSecSecUserObj* getRequiredContainerSecUser( bool forceRead = false );
		virtual void setRequiredContainerSecUser( cfsec::ICFSecSecUserObj* value );

		virtual cfsec::ICFSecSecUserObj* getRequiredParentSecProxy( bool forceRead = false );
		virtual void setRequiredParentSecProxy( cfsec::ICFSecSecUserObj* value );

		virtual void copyPKeyToBuff();

		virtual void copyBuffToPKey();

		virtual void copyBuffToOrig();

		virtual void copyOrigToBuff();

	};
}
