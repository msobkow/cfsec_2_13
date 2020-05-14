// Description: C++18 interface implementation for a CFSec schema.

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


#include <uuid/uuid.h>

#include <array>
#include <cassert>
#include <cstddef>
#include <chrono>
#include <ctime>
#include <functional>
#include <list>
#include <string>

#include <cflib/ICFLibPublic.hpp>



#include <cflib/ICFLibPublic.hpp>

using namespace std;


#include <cfsec/ICFSecSchema.hpp>

namespace cfsec {

	const std::string ICFSecSchema::CLASS_NAME( "ICFSecSchema" );

	ICFSecSchema::ICFSecSchema()
	{
	}

	ICFSecSchema::~ICFSecSchema() {
	}

	ICFSecSchema::AuditActionEnum* ICFSecSchema::parseAuditActionEnum( const std::string* value ) {
		ICFSecSchema::AuditActionEnum* retval = parseAuditActionEnum( CLASS_NAME, value );
		return( retval );
	}

	ICFSecSchema::AuditActionEnum* ICFSecSchema::parseAuditActionEnum( const std::string& fieldOrClassName, const std::string* value ) {
		static std::map<std::string,ICFSecSchema::AuditActionEnum>* lookupAuditActionEnum = NULL;
		static const std::string S_ProcName( "parseAuditActionEnum" );
		static const std::string S_Value( "value" );
		static const std::string S_Msg( "Could not resolve key" );
		if( lookupAuditActionEnum == NULL ) {
			std::map<std::string,ICFSecSchema::AuditActionEnum>* newMap = new std::map<std::string,ICFSecSchema::AuditActionEnum>();
			newMap->insert( std::map<std::string,ICFSecSchema::AuditActionEnum>::value_type( std::string( "Create" ), ICFSecSchema::AuditActionEnum::Create ) );
			newMap->insert( std::map<std::string,ICFSecSchema::AuditActionEnum>::value_type( std::string( "Update" ), ICFSecSchema::AuditActionEnum::Update ) );
			newMap->insert( std::map<std::string,ICFSecSchema::AuditActionEnum>::value_type( std::string( "Delete" ), ICFSecSchema::AuditActionEnum::Delete ) );
			lookupAuditActionEnum = newMap;
		}
		ICFSecSchema::AuditActionEnum* retval;
		if( ( value == NULL ) || ( value->length() <= 0 ) ) {
			retval = NULL;
		}
		else {
			std::map<std::string,ICFSecSchema::AuditActionEnum>::iterator search = lookupAuditActionEnum->find( *value );
			if( search == lookupAuditActionEnum->end() ) {
				throw cflib::CFLibInvalidArgumentException( fieldOrClassName,
					S_ProcName,
					1,
					S_Value,
					S_Msg );
			}
			retval = &search->second;
		}
		return( retval );
	}

	const std::string* ICFSecSchema::toAuditActionEnumString( const ICFSecSchema::AuditActionEnum value ) {
		static std::map<ICFSecSchema::AuditActionEnum,std::string>* tostringAuditActionEnum = NULL;
		static const std::string S_ProcName( "toAuditActionEnumString" );
		static const std::string S_Value( "value" );
		static const std::string S_Msg( "Could not resolve AuditActionEnum value" );
		if( tostringAuditActionEnum == NULL ) {
			std::map<AuditActionEnum,std::string>* newMap = new std::map<AuditActionEnum,std::string>();
			newMap->insert( std::map<ICFSecSchema::AuditActionEnum,std::string>::value_type( ICFSecSchema::AuditActionEnum::Create, std::string( "Create" ) ) );
			newMap->insert( std::map<ICFSecSchema::AuditActionEnum,std::string>::value_type( ICFSecSchema::AuditActionEnum::Update, std::string( "Update" ) ) );
			newMap->insert( std::map<ICFSecSchema::AuditActionEnum,std::string>::value_type( ICFSecSchema::AuditActionEnum::Delete, std::string( "Delete" ) ) );
			tostringAuditActionEnum = newMap;
			newMap = NULL;
		}
		const std::string* retval;
		std::map<ICFSecSchema::AuditActionEnum,std::string>::iterator search = tostringAuditActionEnum->find( value );
		if( search == tostringAuditActionEnum->end() ) {
			throw cflib::CFLibInvalidArgumentException( CLASS_NAME,
				S_ProcName,
				1,
				S_Value,
				S_Msg );
		}
		retval = &(search->second);
		return( retval );
	}

	const ICFSecSchema::AuditActionEnum ICFSecSchema::ordinalToAuditActionEnum( const std::string& fieldOrClassName, const int16_t value ) {
		int32_t ivalue = value;
		const ICFSecSchema::AuditActionEnum* retval = ordinalToAuditActionEnum( fieldOrClassName, &ivalue );
		return( *retval );
	}

	const ICFSecSchema::AuditActionEnum* ICFSecSchema::ordinalToAuditActionEnum( const std::string& fieldOrClassName, const int16_t* value ) {
		const ICFSecSchema::AuditActionEnum* retval;
		if( value == NULL ) {
			retval = NULL;
		}
		else {
			int32_t ivalue = *value;
			retval = ordinalToAuditActionEnum( fieldOrClassName, &ivalue );
		}
		return( retval );
	}

	const ICFSecSchema::AuditActionEnum ICFSecSchema::ordinalToAuditActionEnum( const int16_t value ) {
		int32_t ivalue = value;
		const ICFSecSchema::AuditActionEnum* retval = ordinalToAuditActionEnum( CLASS_NAME, &ivalue );
		return( *retval );
	}

	const ICFSecSchema::AuditActionEnum* ICFSecSchema::ordinalToAuditActionEnum( const int16_t* value ) {
		const ICFSecSchema::AuditActionEnum* retval;
		if( value == NULL ) {
			retval = NULL;
		}
		else {
			int32_t ivalue = *value;
			retval = ordinalToAuditActionEnum( CLASS_NAME, &ivalue );
		}
		return( retval );
	}

	const ICFSecSchema::AuditActionEnum ICFSecSchema::ordinalToAuditActionEnum( const int32_t value ) {
		int32_t ivalue = value;
		const ICFSecSchema::AuditActionEnum* retval = ordinalToAuditActionEnum( CLASS_NAME, &ivalue );
		return( *retval );
	}

	const ICFSecSchema::AuditActionEnum ICFSecSchema::ordinalToAuditActionEnum( const std::string& fieldOrClassName, const int32_t value ) {
		int32_t ivalue = value;
		const ICFSecSchema::AuditActionEnum* retval = ordinalToAuditActionEnum( fieldOrClassName, &ivalue );
		return( *retval );
	}

	const ICFSecSchema::AuditActionEnum* ICFSecSchema::ordinalToAuditActionEnum( const int32_t* value ) {
	const ICFSecSchema::AuditActionEnum* retval;
		if( value == NULL ) {
			retval = NULL;
		}
		else {
			retval = ordinalToAuditActionEnum( CLASS_NAME, value );
		}
		return( retval );
	}

	const ICFSecSchema::AuditActionEnum* ICFSecSchema::ordinalToAuditActionEnum( const std::string& fieldOrClassName, const int32_t* value ) {
		static std::map<const int32_t,ICFSecSchema::AuditActionEnum>* lookupOrdinalAuditActionEnum = NULL;
		static const std::string S_ProcName( "ordinalToAuditActionEnum" );
		static const std::string S_Value( "value" );
		static const std::string S_Msg( "Could not resolve key" );
		if( lookupOrdinalAuditActionEnum == NULL ) {
			std::map<const int32_t,ICFSecSchema::AuditActionEnum>* newMap = new std::map<const int32_t,ICFSecSchema::AuditActionEnum>();
			newMap->insert( std::map<int32_t,ICFSecSchema::AuditActionEnum>::value_type( (int32_t)ICFSecSchema::AuditActionEnum::Create, ICFSecSchema::AuditActionEnum::Create ) );
			newMap->insert( std::map<int32_t,ICFSecSchema::AuditActionEnum>::value_type( (int32_t)ICFSecSchema::AuditActionEnum::Update, ICFSecSchema::AuditActionEnum::Update ) );
			newMap->insert( std::map<int32_t,ICFSecSchema::AuditActionEnum>::value_type( (int32_t)ICFSecSchema::AuditActionEnum::Delete, ICFSecSchema::AuditActionEnum::Delete ) );
			lookupOrdinalAuditActionEnum = newMap;
		}
		const ICFSecSchema::AuditActionEnum* retval;
		if( value == NULL ) {
			retval = NULL;
		}
		else {
			std::map<const int32_t,ICFSecSchema::AuditActionEnum>::iterator search = lookupOrdinalAuditActionEnum->find( *value );
			if( search == lookupOrdinalAuditActionEnum->end() ) {
				throw cflib::CFLibInvalidArgumentException( fieldOrClassName,
					S_ProcName,
					1,
					S_Value,
					S_Msg );
			}
			retval = &search->second;
		}
		return( retval );
	}

}
