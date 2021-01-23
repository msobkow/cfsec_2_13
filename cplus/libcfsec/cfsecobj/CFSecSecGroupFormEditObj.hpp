#pragma once

// Description: C++18 edit object instance specification for CFSec SecGroupForm.

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

	class CFSecSecGroupFormEditObj
	: public virtual ICFSecSecGroupFormEditObj
	{
	public:
		static const std::string CLASS_NAME;
	protected:
		cfsec::ICFSecSecGroupFormObj* orig;
		cfsec::CFSecSecGroupFormBuff* buff;
		cfsec::ICFSecSecUserObj* createdBy = NULL;
		cfsec::ICFSecSecUserObj* updatedBy = NULL;
	public:
		CFSecSecGroupFormEditObj( cfsec::ICFSecSecGroupFormObj* argOrig );
		virtual ~CFSecSecGroupFormEditObj();

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

		virtual ICFSecSecGroupFormObj* realize();

		virtual cfsec::ICFSecSecGroupFormObj* read( bool forceRead = false );

		virtual ICFSecSecGroupFormObj* create();

		virtual ICFSecSecGroupFormEditObj* update();

		virtual ICFSecSecGroupFormEditObj* deleteInstance();

		virtual cfsec::ICFSecSecGroupFormTableObj* getSecGroupFormTable();

		virtual cfsec::ICFSecSecGroupFormEditObj* getEdit();

		virtual cfsec::ICFSecSecGroupFormEditObj* getSecGroupFormEdit();

		virtual ICFSecSecGroupFormEditObj* beginEdit();

		virtual void endEdit();

		virtual cfsec::ICFSecSecGroupFormObj* getOrig();

		virtual cfsec::ICFSecSecGroupFormObj* getOrigAsSecGroupForm();

		virtual cfsec::ICFSecSchemaObj* getSchema();

		virtual cfsec::CFSecSecGroupFormBuff* getBuff();
		virtual void setBuff( cfsec::CFSecSecGroupFormBuff* value );

		inline cfsec::CFSecSecGroupFormBuff* getSecGroupFormBuff() {
			// Buff is always instantiated when constructed over an original object
			return( static_cast<cfsec::CFSecSecGroupFormBuff*>( buff ) );
		};

		inline cfsec::CFSecSecGroupFormBuff* getSecGroupFormEditBuff() {
			// Buff is always instantiated when constructed over an original object
			return( dynamic_cast<cfsec::CFSecSecGroupFormBuff*>( buff ) );
		};

		virtual cfsec::CFSecSecGroupFormPKey* getPKey();
		virtual void setPKey( cfsec::CFSecSecGroupFormPKey* value );

		virtual bool getIsNew();
		virtual void setIsNew( bool value );

		virtual const int64_t getRequiredClusterId();
		virtual const int64_t* getRequiredClusterIdReference();

		virtual const int64_t getRequiredSecGroupFormId();
		virtual const int64_t* getRequiredSecGroupFormIdReference();

		virtual const int32_t getRequiredSecGroupId();
		virtual const int32_t* getRequiredSecGroupIdReference();

		virtual const int32_t getRequiredSecAppId();
		virtual const int32_t* getRequiredSecAppIdReference();

		virtual const int32_t getRequiredSecFormId();
		virtual const int32_t* getRequiredSecFormIdReference();

		virtual cfsec::ICFSecClusterObj* getRequiredOwnerCluster( bool forceRead = false );
		virtual void setRequiredOwnerCluster( cfsec::ICFSecClusterObj* value );

		virtual cfsec::ICFSecSecGroupObj* getRequiredContainerGroup( bool forceRead = false );
		virtual void setRequiredContainerGroup( cfsec::ICFSecSecGroupObj* value );

		virtual cfsec::ICFSecSecAppObj* getRequiredParentApp( bool forceRead = false );
		virtual void setRequiredParentApp( cfsec::ICFSecSecAppObj* value );

		virtual cfsec::ICFSecSecFormObj* getRequiredParentForm( bool forceRead = false );
		virtual void setRequiredParentForm( cfsec::ICFSecSecFormObj* value );

		virtual void copyPKeyToBuff();

		virtual void copyBuffToPKey();

		virtual void copyBuffToOrig();

		virtual void copyOrigToBuff();

	};
}
