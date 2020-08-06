#pragma once

// Description: C++18 edit object instance specification for CFSec SecUser.

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

	class CFSecSecUserEditObj
	: public virtual ICFSecSecUserEditObj
	{
	public:
		static const std::string CLASS_NAME;
	protected:
		cfsec::ICFSecSecUserObj* orig;
		cfsec::CFSecSecUserBuff* buff;
		cfsec::ICFSecSecUserObj* createdBy = NULL;
		cfsec::ICFSecSecUserObj* updatedBy = NULL;
	public:
		CFSecSecUserEditObj( cfsec::ICFSecSecUserObj* argOrig );
		virtual ~CFSecSecUserEditObj();

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

		virtual ICFSecSecUserObj* realize();

		virtual cfsec::ICFSecSecUserObj* read( bool forceRead = false );

		virtual ICFSecSecUserObj* create();

		virtual ICFSecSecUserEditObj* update();

		virtual ICFSecSecUserEditObj* deleteInstance();

		virtual cfsec::ICFSecSecUserTableObj* getSecUserTable();

		virtual cfsec::ICFSecSecUserEditObj* getEdit();

		virtual cfsec::ICFSecSecUserEditObj* getSecUserEdit();

		virtual ICFSecSecUserEditObj* beginEdit();

		virtual void endEdit();

		virtual cfsec::ICFSecSecUserObj* getOrig();

		virtual cfsec::ICFSecSecUserObj* getOrigAsSecUser();

		virtual cfsec::ICFSecSchemaObj* getSchema();

		virtual cfsec::CFSecSecUserBuff* getBuff();
		virtual void setBuff( cfsec::CFSecSecUserBuff* value );

		inline cfsec::CFSecSecUserBuff* getSecUserBuff() {
			// Buff is always instantiated when constructed over an original object
			return( static_cast<cfsec::CFSecSecUserBuff*>( buff ) );
		};

		inline cfsec::CFSecSecUserBuff* getSecUserEditBuff() {
			// Buff is always instantiated when constructed over an original object
			return( dynamic_cast<cfsec::CFSecSecUserBuff*>( buff ) );
		};

		virtual cfsec::CFSecSecUserPKey* getPKey();
		virtual void setPKey( cfsec::CFSecSecUserPKey* value );

		virtual bool getIsNew();
		virtual void setIsNew( bool value );

		virtual const uuid_ptr_t getRequiredSecUserId();
		virtual const uuid_ptr_t getRequiredSecUserIdReference();

		virtual const std::string& getRequiredLoginId();
		virtual const std::string* getRequiredLoginIdReference();
		virtual void setRequiredLoginId( const std::string& value );

		virtual const std::string& getRequiredEMailAddress();
		virtual const std::string* getRequiredEMailAddressReference();
		virtual void setRequiredEMailAddress( const std::string& value );

		virtual bool isOptionalEMailConfirmUuidNull();
		virtual const uuid_ptr_t getOptionalEMailConfirmUuidValue();
		virtual const uuid_ptr_t getOptionalEMailConfirmUuidReference();
		virtual void setOptionalEMailConfirmUuidNull();
		virtual void setOptionalEMailConfirmUuidValue( const uuid_ptr_t value );

		virtual bool isOptionalDfltDevUserIdNull();
		virtual const uuid_ptr_t getOptionalDfltDevUserIdValue();
		virtual const uuid_ptr_t getOptionalDfltDevUserIdReference();

		virtual bool isOptionalDfltDevNameNull();
		virtual const std::string& getOptionalDfltDevNameValue();
		virtual const std::string* getOptionalDfltDevNameReference();

		virtual const std::string& getRequiredPasswordHash();
		virtual const std::string* getRequiredPasswordHashReference();
		virtual void setRequiredPasswordHash( const std::string& value );

		virtual bool isOptionalPasswordResetUuidNull();
		virtual const uuid_ptr_t getOptionalPasswordResetUuidValue();
		virtual const uuid_ptr_t getOptionalPasswordResetUuidReference();
		virtual void setOptionalPasswordResetUuidNull();
		virtual void setOptionalPasswordResetUuidValue( const uuid_ptr_t value );

		virtual std::vector<cfsec::ICFSecSecDeviceObj*> getOptionalComponentsSecDev( bool forceRead = false );

		virtual cfsec::ICFSecSecDeviceObj* getOptionalLookupDefDev( bool forceRead = false );
		virtual void setOptionalLookupDefDev( cfsec::ICFSecSecDeviceObj* value );

		virtual std::vector<cfsec::ICFSecSecSessionObj*> getOptionalComponentsSecSess( bool forceRead = false );

		virtual std::vector<cfsec::ICFSecSecSessionObj*> getOptionalChildrenSecProxy( bool forceRead = false );

		virtual std::vector<cfsec::ICFSecSecGrpMembObj*> getOptionalChildrenSecGrpMemb( bool forceRead = false );

		virtual std::vector<cfsec::ICFSecTSecGrpMembObj*> getOptionalChildrenTSecGrpMemb( bool forceRead = false );

		virtual void copyPKeyToBuff();

		virtual void copyBuffToPKey();

		virtual void copyBuffToOrig();

		virtual void copyOrigToBuff();

	};
}
