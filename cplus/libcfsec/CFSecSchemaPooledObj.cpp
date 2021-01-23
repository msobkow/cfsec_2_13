// Description: C++18 Schema Pooled Object implementation for CFSec.

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

using namespace std;

#include <cfsecobj/CFSecSchemaObj.hpp>
#include <cfsecobj/CFSecSchemaPooledObj.hpp>

#include <cfsecobj/ICFSecClusterObj.hpp>
#include <cfsecobj/ICFSecHostNodeObj.hpp>
#include <cfsecobj/ICFSecISOCcyObj.hpp>
#include <cfsecobj/ICFSecISOCtryObj.hpp>
#include <cfsecobj/ICFSecISOCtryCcyObj.hpp>
#include <cfsecobj/ICFSecISOCtryLangObj.hpp>
#include <cfsecobj/ICFSecISOLangObj.hpp>
#include <cfsecobj/ICFSecISOTZoneObj.hpp>
#include <cfsecobj/ICFSecSecAppObj.hpp>
#include <cfsecobj/ICFSecSecDeviceObj.hpp>
#include <cfsecobj/ICFSecSecFormObj.hpp>
#include <cfsecobj/ICFSecSecGroupObj.hpp>
#include <cfsecobj/ICFSecSecGroupFormObj.hpp>
#include <cfsecobj/ICFSecSecGrpIncObj.hpp>
#include <cfsecobj/ICFSecSecGrpMembObj.hpp>
#include <cfsecobj/ICFSecSecSessionObj.hpp>
#include <cfsecobj/ICFSecSecUserObj.hpp>
#include <cfsecobj/ICFSecServiceObj.hpp>
#include <cfsecobj/ICFSecServiceTypeObj.hpp>
#include <cfsecobj/ICFSecSysClusterObj.hpp>
#include <cfsecobj/ICFSecTenantObj.hpp>
#include <cfsecobj/ICFSecTSecGroupObj.hpp>
#include <cfsecobj/ICFSecTSecGrpIncObj.hpp>
#include <cfsecobj/ICFSecTSecGrpMembObj.hpp>

#include <cfsecobj/ICFSecClusterTableObj.hpp>
#include <cfsecobj/ICFSecHostNodeTableObj.hpp>
#include <cfsecobj/ICFSecISOCcyTableObj.hpp>
#include <cfsecobj/ICFSecISOCtryTableObj.hpp>
#include <cfsecobj/ICFSecISOCtryCcyTableObj.hpp>
#include <cfsecobj/ICFSecISOCtryLangTableObj.hpp>
#include <cfsecobj/ICFSecISOLangTableObj.hpp>
#include <cfsecobj/ICFSecISOTZoneTableObj.hpp>
#include <cfsecobj/ICFSecSecAppTableObj.hpp>
#include <cfsecobj/ICFSecSecDeviceTableObj.hpp>
#include <cfsecobj/ICFSecSecFormTableObj.hpp>
#include <cfsecobj/ICFSecSecGroupTableObj.hpp>
#include <cfsecobj/ICFSecSecGroupFormTableObj.hpp>
#include <cfsecobj/ICFSecSecGrpIncTableObj.hpp>
#include <cfsecobj/ICFSecSecGrpMembTableObj.hpp>
#include <cfsecobj/ICFSecSecSessionTableObj.hpp>
#include <cfsecobj/ICFSecSecUserTableObj.hpp>
#include <cfsecobj/ICFSecServiceTableObj.hpp>
#include <cfsecobj/ICFSecServiceTypeTableObj.hpp>
#include <cfsecobj/ICFSecSysClusterTableObj.hpp>
#include <cfsecobj/ICFSecTenantTableObj.hpp>
#include <cfsecobj/ICFSecTSecGroupTableObj.hpp>
#include <cfsecobj/ICFSecTSecGrpIncTableObj.hpp>
#include <cfsecobj/ICFSecTSecGrpMembTableObj.hpp>

namespace cfsec {

	const std::string CFSecSchemaPooledObj::CLASS_NAME( "CFSecSchemaPooledObj" );

	CFSecSchemaPooledObj::CFSecSchemaPooledObj()
	: cfsec::CFSecSchemaObj()
	{
	}

	CFSecSchemaPooledObj::~CFSecSchemaPooledObj() {
	}

	bool CFSecSchemaPooledObj::isConnected() {
		if( backingStore == NULL ) {
			return( false );
		}
		else {
			return( true );
		}
	}

	void CFSecSchemaPooledObj::disconnect( bool doCommit ) {
		static const std::string S_ProcName( "disconnect" );
		static const std::string S_Message( "Schema objects over pooled storage cannot be explicitly disconnected" );
		throw cflib::CFLibUsageException( CLASS_NAME,
			S_ProcName,
			S_Message );
	}

	void CFSecSchemaPooledObj::logout() {
		if( ( authorization == NULL ) || ( backingStore == NULL ) ) {
			return;
		}
		try {
			bool transactionStarted = beginTransaction();
			if( ! transactionStarted ) {
				rollback();
				transactionStarted = beginTransaction();
				if( ! transactionStarted ) {
					setAuthorization( NULL );
					return;
				}
			}
			const uuid_ptr_t secSessionId = authorization->getSecSessionId();
			if( ( secSessionId[0] != 0 )
				|| ( secSessionId[1] != 0 )
				|| ( secSessionId[2] != 0 )
				|| ( secSessionId[3] != 0 )
				|| ( secSessionId[4] != 0 )
				|| ( secSessionId[5] != 0 )
				|| ( secSessionId[6] != 0 )
				|| ( secSessionId[7] != 0 )
				|| ( secSessionId[8] != 0 )
				|| ( secSessionId[9] != 0 )
				|| ( secSessionId[10] != 0 )
				|| ( secSessionId[11] != 0 )
				|| ( secSessionId[12] != 0 )
				|| ( secSessionId[13] != 0 )
				|| ( secSessionId[14] != 0 )
				|| ( secSessionId[15] != 0 ) )
			{
				cfsec::ICFSecSecSessionObj* secSession = getSecSessionTableObj()->readSecSessionByIdIdx( secSessionId );
				if( secSession != NULL ) {
					if( secSession->isOptionalFinishNull() ) {
						cfsec::ICFSecSecSessionEditObj* editSecSession = secSession->beginEdit();
						std::chrono::system_clock::time_point timestamp = cflib::CFLib::getUTCTimestampInstance();
						editSecSession->setOptionalFinishValue( timestamp );
						editSecSession->update();
						editSecSession = NULL;
					}
				}
			}
			commit();
		}
		catch( xercesc::SAXNotRecognizedException x ) {
			setAuthorization( NULL );
			minimizeMemory();
			throw x;
		}
		catch( xercesc::SAXNotSupportedException x ) {
			setAuthorization( NULL );
			minimizeMemory();
			throw x;
		}
		catch( xercesc::SAXParseException x ) {
			setAuthorization( NULL );
			minimizeMemory();
			throw x;
		}
		catch( xercesc::SAXException x ) {
			setAuthorization( NULL );
			minimizeMemory();
			throw x;
		}
		catch( cflib::CFLibArgumentOverflowException x ) {
			setAuthorization( NULL );
			minimizeMemory();
			throw x;
		}
		catch( cflib::CFLibArgumentRangeException x ) {
			setAuthorization( NULL );
			minimizeMemory();
			throw x;
		}
		catch( cflib::CFLibArgumentUnderflowException x ) {
			setAuthorization( NULL );
			minimizeMemory();
			throw x;
		}
		catch( cflib::CFLibCollisionDetectedException x ) {
			setAuthorization( NULL );
			minimizeMemory();
			throw x;
		}
		catch( cflib::CFLibDbException x ) {
			setAuthorization( NULL );
			minimizeMemory();
			throw x;
		}
		catch( cflib::CFLibDependentsDetectedException x ) {
			setAuthorization( NULL );
			minimizeMemory();
			throw x;
		}
		catch( cflib::CFLibEmptyArgumentException x ) {
			setAuthorization( NULL );
			minimizeMemory();
			throw x;
		}
		catch( cflib::CFLibInvalidArgumentException x ) {
			setAuthorization( NULL );
			minimizeMemory();
			throw x;
		}
		catch( cflib::CFLibMathException x ) {
			setAuthorization( NULL );
			minimizeMemory();
			throw x;
		}
		catch( cflib::CFLibMustOverrideException x ) {
			setAuthorization( NULL );
			minimizeMemory();
			throw x;
		}
		catch( cflib::CFLibNotImplementedYetException x ) {
			setAuthorization( NULL );
			minimizeMemory();
			throw x;
		}
		catch( cflib::CFLibNotSupportedException x ) {
			setAuthorization( NULL );
			minimizeMemory();
			throw x;
		}
		catch( cflib::CFLibNullArgumentException x ) {
			setAuthorization( NULL );
			minimizeMemory();
			throw x;
		}
		catch( cflib::CFLibPrimaryKeyNotNewException x ) {
			setAuthorization( NULL );
			minimizeMemory();
			throw x;
		}
		catch( cflib::CFLibStaleCacheDetectedException x ) {
			setAuthorization( NULL );
			minimizeMemory();
			throw x;
		}
		catch( cflib::CFLibSubroutineException x ) {
			setAuthorization( NULL );
			minimizeMemory();
			throw x;
		}
		catch( cflib::CFLibUniqueIndexViolationException x ) {
			setAuthorization( NULL );
			minimizeMemory();
			throw x;
		}
		catch( cflib::CFLibUnrecognizedAttributeException x ) {
			setAuthorization( NULL );
			minimizeMemory();
			throw x;
		}
		catch( cflib::CFLibUnresolvedRelationException x ) {
			setAuthorization( NULL );
			minimizeMemory();
			throw x;
		}
		catch( cflib::CFLibUnsupportedClassException x ) {
			setAuthorization( NULL );
			minimizeMemory();
			throw x;
		}
		catch( cflib::CFLibUsageException x ) {
			setAuthorization( NULL );
			minimizeMemory();
			throw x;
		}
		catch( cflib::CFLibArgumentException x ) {
			setAuthorization( NULL );
			minimizeMemory();
			throw x;
		}
		catch( cflib::CFLibRuntimeException x ) {
			setAuthorization( NULL );
			minimizeMemory();
			throw x;
		}
		catch( std::exception x ) {
			setAuthorization( NULL );
			minimizeMemory();
			throw x;
		}
	}

}

