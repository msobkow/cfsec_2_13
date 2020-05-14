#pragma once

// Description: C++18 edit object instance specification for CFSec SysCluster.

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
