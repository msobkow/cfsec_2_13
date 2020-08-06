#pragma once

// Description: C++18 edit object instance specification for CFSec TSecGroup.

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

	class CFSecTSecGroupEditObj
	: public virtual ICFSecTSecGroupEditObj
	{
	public:
		static const std::string CLASS_NAME;
	protected:
		cfsec::ICFSecTSecGroupObj* orig;
		cfsec::CFSecTSecGroupBuff* buff;
		cfsec::ICFSecSecUserObj* createdBy = NULL;
		cfsec::ICFSecSecUserObj* updatedBy = NULL;
	public:
		CFSecTSecGroupEditObj( cfsec::ICFSecTSecGroupObj* argOrig );
		virtual ~CFSecTSecGroupEditObj();

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

		virtual ICFSecTSecGroupObj* realize();

		virtual cfsec::ICFSecTSecGroupObj* read( bool forceRead = false );

		virtual ICFSecTSecGroupObj* create();

		virtual ICFSecTSecGroupEditObj* update();

		virtual ICFSecTSecGroupEditObj* deleteInstance();

		virtual cfsec::ICFSecTSecGroupTableObj* getTSecGroupTable();

		virtual cfsec::ICFSecTSecGroupEditObj* getEdit();

		virtual cfsec::ICFSecTSecGroupEditObj* getTSecGroupEdit();

		virtual ICFSecTSecGroupEditObj* beginEdit();

		virtual void endEdit();

		virtual cfsec::ICFSecTSecGroupObj* getOrig();

		virtual cfsec::ICFSecTSecGroupObj* getOrigAsTSecGroup();

		virtual cfsec::ICFSecSchemaObj* getSchema();

		virtual cfsec::CFSecTSecGroupBuff* getBuff();
		virtual void setBuff( cfsec::CFSecTSecGroupBuff* value );

		inline cfsec::CFSecTSecGroupBuff* getTSecGroupBuff() {
			// Buff is always instantiated when constructed over an original object
			return( static_cast<cfsec::CFSecTSecGroupBuff*>( buff ) );
		};

		inline cfsec::CFSecTSecGroupBuff* getTSecGroupEditBuff() {
			// Buff is always instantiated when constructed over an original object
			return( dynamic_cast<cfsec::CFSecTSecGroupBuff*>( buff ) );
		};

		virtual cfsec::CFSecTSecGroupPKey* getPKey();
		virtual void setPKey( cfsec::CFSecTSecGroupPKey* value );

		virtual bool getIsNew();
		virtual void setIsNew( bool value );

		virtual const int64_t getRequiredTenantId();
		virtual const int64_t* getRequiredTenantIdReference();

		virtual const int32_t getRequiredTSecGroupId();
		virtual const int32_t* getRequiredTSecGroupIdReference();

		virtual const std::string& getRequiredName();
		virtual const std::string* getRequiredNameReference();
		virtual void setRequiredName( const std::string& value );

		virtual const bool getRequiredIsVisible();
		virtual const bool* getRequiredIsVisibleReference();
		virtual void setRequiredIsVisible( const bool value );

		virtual cfsec::ICFSecTenantObj* getRequiredContainerTenant( bool forceRead = false );
		virtual void setRequiredContainerTenant( cfsec::ICFSecTenantObj* value );

		virtual std::vector<cfsec::ICFSecTSecGrpIncObj*> getOptionalComponentsInclude( bool forceRead = false );

		virtual std::vector<cfsec::ICFSecTSecGrpMembObj*> getOptionalComponentsMember( bool forceRead = false );

		virtual std::vector<cfsec::ICFSecTSecGrpIncObj*> getRequiredChildrenIncByGroup( bool forceRead = false );

		virtual void copyPKeyToBuff();

		virtual void copyBuffToPKey();

		virtual void copyBuffToOrig();

		virtual void copyOrigToBuff();

	};
}
