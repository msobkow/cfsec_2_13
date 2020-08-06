#pragma once

// Description: C++18 edit object instance specification for CFSec SysCluster.

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

	class CFSecSysClusterEditObj
	: public virtual ICFSecSysClusterEditObj
	{
	public:
		static const std::string CLASS_NAME;
	protected:
		cfsec::ICFSecSysClusterObj* orig;
		cfsec::CFSecSysClusterBuff* buff;
	public:
		CFSecSysClusterEditObj( cfsec::ICFSecSysClusterObj* argOrig );
		virtual ~CFSecSysClusterEditObj();

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

		virtual ICFSecSysClusterObj* realize();

		virtual cfsec::ICFSecSysClusterObj* read( bool forceRead = false );

		virtual ICFSecSysClusterObj* create();

		virtual ICFSecSysClusterEditObj* update();

		virtual ICFSecSysClusterEditObj* deleteInstance();

		virtual cfsec::ICFSecSysClusterTableObj* getSysClusterTable();

		virtual cfsec::ICFSecSysClusterEditObj* getEdit();

		virtual cfsec::ICFSecSysClusterEditObj* getSysClusterEdit();

		virtual ICFSecSysClusterEditObj* beginEdit();

		virtual void endEdit();

		virtual cfsec::ICFSecSysClusterObj* getOrig();

		virtual cfsec::ICFSecSysClusterObj* getOrigAsSysCluster();

		virtual cfsec::ICFSecSchemaObj* getSchema();

		virtual cfsec::CFSecSysClusterBuff* getBuff();
		virtual void setBuff( cfsec::CFSecSysClusterBuff* value );

		inline cfsec::CFSecSysClusterBuff* getSysClusterBuff() {
			// Buff is always instantiated when constructed over an original object
			return( static_cast<cfsec::CFSecSysClusterBuff*>( buff ) );
		};

		inline cfsec::CFSecSysClusterBuff* getSysClusterEditBuff() {
			// Buff is always instantiated when constructed over an original object
			return( dynamic_cast<cfsec::CFSecSysClusterBuff*>( buff ) );
		};

		virtual cfsec::CFSecSysClusterPKey* getPKey();
		virtual void setPKey( cfsec::CFSecSysClusterPKey* value );

		virtual bool getIsNew();
		virtual void setIsNew( bool value );

		virtual const int32_t getRequiredSingletonId();
		virtual const int32_t* getRequiredSingletonIdReference();
		virtual void setRequiredSingletonId( const int32_t value );

		virtual const int64_t getRequiredClusterId();
		virtual const int64_t* getRequiredClusterIdReference();

		virtual cfsec::ICFSecClusterObj* getRequiredContainerCluster( bool forceRead = false );
		virtual void setRequiredContainerCluster( cfsec::ICFSecClusterObj* value );

		virtual void copyPKeyToBuff();

		virtual void copyBuffToPKey();

		virtual void copyBuffToOrig();

		virtual void copyOrigToBuff();

	};
}
