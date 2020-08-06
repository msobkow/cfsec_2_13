#pragma once

// Description: C++18 edit object instance specification for CFSec SecGrpMemb.

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

	class CFSecSecGrpMembEditObj
	: public virtual ICFSecSecGrpMembEditObj
	{
	public:
		static const std::string CLASS_NAME;
	protected:
		cfsec::ICFSecSecGrpMembObj* orig;
		cfsec::CFSecSecGrpMembBuff* buff;
		cfsec::ICFSecSecUserObj* createdBy = NULL;
		cfsec::ICFSecSecUserObj* updatedBy = NULL;
	public:
		CFSecSecGrpMembEditObj( cfsec::ICFSecSecGrpMembObj* argOrig );
		virtual ~CFSecSecGrpMembEditObj();

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

		virtual ICFSecSecGrpMembObj* realize();

		virtual cfsec::ICFSecSecGrpMembObj* read( bool forceRead = false );

		virtual ICFSecSecGrpMembObj* create();

		virtual ICFSecSecGrpMembEditObj* update();

		virtual ICFSecSecGrpMembEditObj* deleteInstance();

		virtual cfsec::ICFSecSecGrpMembTableObj* getSecGrpMembTable();

		virtual cfsec::ICFSecSecGrpMembEditObj* getEdit();

		virtual cfsec::ICFSecSecGrpMembEditObj* getSecGrpMembEdit();

		virtual ICFSecSecGrpMembEditObj* beginEdit();

		virtual void endEdit();

		virtual cfsec::ICFSecSecGrpMembObj* getOrig();

		virtual cfsec::ICFSecSecGrpMembObj* getOrigAsSecGrpMemb();

		virtual cfsec::ICFSecSchemaObj* getSchema();

		virtual cfsec::CFSecSecGrpMembBuff* getBuff();
		virtual void setBuff( cfsec::CFSecSecGrpMembBuff* value );

		inline cfsec::CFSecSecGrpMembBuff* getSecGrpMembBuff() {
			// Buff is always instantiated when constructed over an original object
			return( static_cast<cfsec::CFSecSecGrpMembBuff*>( buff ) );
		};

		inline cfsec::CFSecSecGrpMembBuff* getSecGrpMembEditBuff() {
			// Buff is always instantiated when constructed over an original object
			return( dynamic_cast<cfsec::CFSecSecGrpMembBuff*>( buff ) );
		};

		virtual cfsec::CFSecSecGrpMembPKey* getPKey();
		virtual void setPKey( cfsec::CFSecSecGrpMembPKey* value );

		virtual bool getIsNew();
		virtual void setIsNew( bool value );

		virtual const int64_t getRequiredClusterId();
		virtual const int64_t* getRequiredClusterIdReference();

		virtual const int64_t getRequiredSecGrpMembId();
		virtual const int64_t* getRequiredSecGrpMembIdReference();

		virtual const int32_t getRequiredSecGroupId();
		virtual const int32_t* getRequiredSecGroupIdReference();

		virtual const uuid_ptr_t getRequiredSecUserId();
		virtual const uuid_ptr_t getRequiredSecUserIdReference();

		virtual cfsec::ICFSecClusterObj* getRequiredOwnerCluster( bool forceRead = false );
		virtual void setRequiredOwnerCluster( cfsec::ICFSecClusterObj* value );

		virtual cfsec::ICFSecSecGroupObj* getRequiredContainerGroup( bool forceRead = false );
		virtual void setRequiredContainerGroup( cfsec::ICFSecSecGroupObj* value );

		virtual cfsec::ICFSecSecUserObj* getRequiredParentUser( bool forceRead = false );
		virtual void setRequiredParentUser( cfsec::ICFSecSecUserObj* value );

		virtual void copyPKeyToBuff();

		virtual void copyBuffToPKey();

		virtual void copyBuffToOrig();

		virtual void copyOrigToBuff();

	};
}
