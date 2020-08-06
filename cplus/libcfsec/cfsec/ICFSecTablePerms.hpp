#pragma once

// Description: C++18 CFSec Table Permissions Interface.

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

#include <uuid/uuid.h>

#include <array>
#include <cassert>
#include <cstddef>
#include <chrono>
#include <ctime>
#include <functional>
#include <list>
#include <string>


namespace cfsec {

	class CFSecAuthorization;

	class ICFSecTablePerms
	{
	public:
		ICFSecTablePerms();
		virtual ~ICFSecTablePerms();

		virtual bool allowCreateCluster( const cfsec::CFSecAuthorization* Authorization ) = 0;
		virtual bool allowReadCluster( const cfsec::CFSecAuthorization Authorization ) = 0;
		virtual bool allowUpdateCluster( const cfsec::CFSecAuthorization* Authorization ) = 0;
		virtual bool allowDeleteCluster( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual bool allowCreateHostNode( const cfsec::CFSecAuthorization* Authorization ) = 0;
		virtual bool allowReadHostNode( const cfsec::CFSecAuthorization Authorization ) = 0;
		virtual bool allowUpdateHostNode( const cfsec::CFSecAuthorization* Authorization ) = 0;
		virtual bool allowDeleteHostNode( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual bool allowCreateISOCcy( const cfsec::CFSecAuthorization* Authorization ) = 0;
		virtual bool allowReadISOCcy( const cfsec::CFSecAuthorization Authorization ) = 0;
		virtual bool allowUpdateISOCcy( const cfsec::CFSecAuthorization* Authorization ) = 0;
		virtual bool allowDeleteISOCcy( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual bool allowCreateISOCtry( const cfsec::CFSecAuthorization* Authorization ) = 0;
		virtual bool allowReadISOCtry( const cfsec::CFSecAuthorization Authorization ) = 0;
		virtual bool allowUpdateISOCtry( const cfsec::CFSecAuthorization* Authorization ) = 0;
		virtual bool allowDeleteISOCtry( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual bool allowCreateISOCtryCcy( const cfsec::CFSecAuthorization* Authorization ) = 0;
		virtual bool allowReadISOCtryCcy( const cfsec::CFSecAuthorization Authorization ) = 0;
		virtual bool allowUpdateISOCtryCcy( const cfsec::CFSecAuthorization* Authorization ) = 0;
		virtual bool allowDeleteISOCtryCcy( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual bool allowCreateISOCtryLang( const cfsec::CFSecAuthorization* Authorization ) = 0;
		virtual bool allowReadISOCtryLang( const cfsec::CFSecAuthorization Authorization ) = 0;
		virtual bool allowUpdateISOCtryLang( const cfsec::CFSecAuthorization* Authorization ) = 0;
		virtual bool allowDeleteISOCtryLang( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual bool allowCreateISOLang( const cfsec::CFSecAuthorization* Authorization ) = 0;
		virtual bool allowReadISOLang( const cfsec::CFSecAuthorization Authorization ) = 0;
		virtual bool allowUpdateISOLang( const cfsec::CFSecAuthorization* Authorization ) = 0;
		virtual bool allowDeleteISOLang( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual bool allowCreateISOTZone( const cfsec::CFSecAuthorization* Authorization ) = 0;
		virtual bool allowReadISOTZone( const cfsec::CFSecAuthorization Authorization ) = 0;
		virtual bool allowUpdateISOTZone( const cfsec::CFSecAuthorization* Authorization ) = 0;
		virtual bool allowDeleteISOTZone( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual bool allowCreateSecApp( const cfsec::CFSecAuthorization* Authorization ) = 0;
		virtual bool allowReadSecApp( const cfsec::CFSecAuthorization Authorization ) = 0;
		virtual bool allowUpdateSecApp( const cfsec::CFSecAuthorization* Authorization ) = 0;
		virtual bool allowDeleteSecApp( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual bool allowCreateSecDevice( const cfsec::CFSecAuthorization* Authorization ) = 0;
		virtual bool allowReadSecDevice( const cfsec::CFSecAuthorization Authorization ) = 0;
		virtual bool allowUpdateSecDevice( const cfsec::CFSecAuthorization* Authorization ) = 0;
		virtual bool allowDeleteSecDevice( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual bool allowCreateSecForm( const cfsec::CFSecAuthorization* Authorization ) = 0;
		virtual bool allowReadSecForm( const cfsec::CFSecAuthorization Authorization ) = 0;
		virtual bool allowUpdateSecForm( const cfsec::CFSecAuthorization* Authorization ) = 0;
		virtual bool allowDeleteSecForm( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual bool allowCreateSecGroup( const cfsec::CFSecAuthorization* Authorization ) = 0;
		virtual bool allowReadSecGroup( const cfsec::CFSecAuthorization Authorization ) = 0;
		virtual bool allowUpdateSecGroup( const cfsec::CFSecAuthorization* Authorization ) = 0;
		virtual bool allowDeleteSecGroup( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual bool allowCreateSecGroupForm( const cfsec::CFSecAuthorization* Authorization ) = 0;
		virtual bool allowReadSecGroupForm( const cfsec::CFSecAuthorization Authorization ) = 0;
		virtual bool allowUpdateSecGroupForm( const cfsec::CFSecAuthorization* Authorization ) = 0;
		virtual bool allowDeleteSecGroupForm( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual bool allowCreateSecGrpInc( const cfsec::CFSecAuthorization* Authorization ) = 0;
		virtual bool allowReadSecGrpInc( const cfsec::CFSecAuthorization Authorization ) = 0;
		virtual bool allowUpdateSecGrpInc( const cfsec::CFSecAuthorization* Authorization ) = 0;
		virtual bool allowDeleteSecGrpInc( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual bool allowCreateSecGrpMemb( const cfsec::CFSecAuthorization* Authorization ) = 0;
		virtual bool allowReadSecGrpMemb( const cfsec::CFSecAuthorization Authorization ) = 0;
		virtual bool allowUpdateSecGrpMemb( const cfsec::CFSecAuthorization* Authorization ) = 0;
		virtual bool allowDeleteSecGrpMemb( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual bool allowCreateSecSession( const cfsec::CFSecAuthorization* Authorization ) = 0;
		virtual bool allowReadSecSession( const cfsec::CFSecAuthorization Authorization ) = 0;
		virtual bool allowUpdateSecSession( const cfsec::CFSecAuthorization* Authorization ) = 0;
		virtual bool allowDeleteSecSession( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual bool allowCreateSecUser( const cfsec::CFSecAuthorization* Authorization ) = 0;
		virtual bool allowReadSecUser( const cfsec::CFSecAuthorization Authorization ) = 0;
		virtual bool allowUpdateSecUser( const cfsec::CFSecAuthorization* Authorization ) = 0;
		virtual bool allowDeleteSecUser( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual bool allowCreateService( const cfsec::CFSecAuthorization* Authorization ) = 0;
		virtual bool allowReadService( const cfsec::CFSecAuthorization Authorization ) = 0;
		virtual bool allowUpdateService( const cfsec::CFSecAuthorization* Authorization ) = 0;
		virtual bool allowDeleteService( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual bool allowCreateServiceType( const cfsec::CFSecAuthorization* Authorization ) = 0;
		virtual bool allowReadServiceType( const cfsec::CFSecAuthorization Authorization ) = 0;
		virtual bool allowUpdateServiceType( const cfsec::CFSecAuthorization* Authorization ) = 0;
		virtual bool allowDeleteServiceType( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual bool allowCreateSysCluster( const cfsec::CFSecAuthorization* Authorization ) = 0;
		virtual bool allowReadSysCluster( const cfsec::CFSecAuthorization Authorization ) = 0;
		virtual bool allowUpdateSysCluster( const cfsec::CFSecAuthorization* Authorization ) = 0;
		virtual bool allowDeleteSysCluster( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual bool allowCreateTSecGroup( const cfsec::CFSecAuthorization* Authorization ) = 0;
		virtual bool allowReadTSecGroup( const cfsec::CFSecAuthorization Authorization ) = 0;
		virtual bool allowUpdateTSecGroup( const cfsec::CFSecAuthorization* Authorization ) = 0;
		virtual bool allowDeleteTSecGroup( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual bool allowCreateTSecGrpInc( const cfsec::CFSecAuthorization* Authorization ) = 0;
		virtual bool allowReadTSecGrpInc( const cfsec::CFSecAuthorization Authorization ) = 0;
		virtual bool allowUpdateTSecGrpInc( const cfsec::CFSecAuthorization* Authorization ) = 0;
		virtual bool allowDeleteTSecGrpInc( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual bool allowCreateTSecGrpMemb( const cfsec::CFSecAuthorization* Authorization ) = 0;
		virtual bool allowReadTSecGrpMemb( const cfsec::CFSecAuthorization Authorization ) = 0;
		virtual bool allowUpdateTSecGrpMemb( const cfsec::CFSecAuthorization* Authorization ) = 0;
		virtual bool allowDeleteTSecGrpMemb( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual bool allowCreateTenant( const cfsec::CFSecAuthorization* Authorization ) = 0;
		virtual bool allowReadTenant( const cfsec::CFSecAuthorization Authorization ) = 0;
		virtual bool allowUpdateTenant( const cfsec::CFSecAuthorization* Authorization ) = 0;
		virtual bool allowDeleteTenant( const cfsec::CFSecAuthorization* Authorization ) = 0;
	};
}
