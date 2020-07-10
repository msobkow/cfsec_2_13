// Description: Java 11 CFSec Table Permissions Interface.

/*
 *	org.msscf.msscf.CFSec
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

package org.msscf.msscf.cfsec.CFSec;

import java.lang.reflect.*;
import java.net.*;
import java.rmi.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.msscf.msscf.cflib.CFLib.*;

public interface ICFSecTablePerms
{
	/**
	 *	Is the session allowed to create Cluster instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowCreateCluster( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to read Cluster instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowReadCluster( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to update Cluster instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowUpdateCluster( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to delete Cluster instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowDeleteCluster( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to create HostNode instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowCreateHostNode( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to read HostNode instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowReadHostNode( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to update HostNode instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowUpdateHostNode( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to delete HostNode instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowDeleteHostNode( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to create ISOCcy instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowCreateISOCcy( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to read ISOCcy instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowReadISOCcy( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to update ISOCcy instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowUpdateISOCcy( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to delete ISOCcy instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowDeleteISOCcy( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to create ISOCtry instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowCreateISOCtry( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to read ISOCtry instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowReadISOCtry( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to update ISOCtry instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowUpdateISOCtry( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to delete ISOCtry instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowDeleteISOCtry( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to create ISOCtryCcy instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowCreateISOCtryCcy( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to read ISOCtryCcy instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowReadISOCtryCcy( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to update ISOCtryCcy instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowUpdateISOCtryCcy( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to delete ISOCtryCcy instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowDeleteISOCtryCcy( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to create ISOCtryLang instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowCreateISOCtryLang( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to read ISOCtryLang instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowReadISOCtryLang( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to update ISOCtryLang instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowUpdateISOCtryLang( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to delete ISOCtryLang instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowDeleteISOCtryLang( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to create ISOLang instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowCreateISOLang( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to read ISOLang instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowReadISOLang( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to update ISOLang instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowUpdateISOLang( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to delete ISOLang instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowDeleteISOLang( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to create ISOTZone instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowCreateISOTZone( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to read ISOTZone instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowReadISOTZone( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to update ISOTZone instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowUpdateISOTZone( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to delete ISOTZone instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowDeleteISOTZone( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to create SecApp instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowCreateSecApp( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to read SecApp instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowReadSecApp( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to update SecApp instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowUpdateSecApp( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to delete SecApp instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowDeleteSecApp( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to create SecDevice instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowCreateSecDevice( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to read SecDevice instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowReadSecDevice( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to update SecDevice instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowUpdateSecDevice( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to delete SecDevice instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowDeleteSecDevice( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to create SecForm instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowCreateSecForm( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to read SecForm instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowReadSecForm( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to update SecForm instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowUpdateSecForm( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to delete SecForm instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowDeleteSecForm( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to create SecGroup instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowCreateSecGroup( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to read SecGroup instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowReadSecGroup( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to update SecGroup instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowUpdateSecGroup( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to delete SecGroup instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowDeleteSecGroup( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to create SecGroupForm instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowCreateSecGroupForm( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to read SecGroupForm instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowReadSecGroupForm( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to update SecGroupForm instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowUpdateSecGroupForm( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to delete SecGroupForm instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowDeleteSecGroupForm( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to create SecGrpInc instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowCreateSecGrpInc( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to read SecGrpInc instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowReadSecGrpInc( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to update SecGrpInc instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowUpdateSecGrpInc( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to delete SecGrpInc instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowDeleteSecGrpInc( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to create SecGrpMemb instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowCreateSecGrpMemb( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to read SecGrpMemb instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowReadSecGrpMemb( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to update SecGrpMemb instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowUpdateSecGrpMemb( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to delete SecGrpMemb instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowDeleteSecGrpMemb( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to create SecSession instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowCreateSecSession( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to read SecSession instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowReadSecSession( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to update SecSession instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowUpdateSecSession( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to delete SecSession instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowDeleteSecSession( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to create SecUser instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowCreateSecUser( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to read SecUser instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowReadSecUser( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to update SecUser instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowUpdateSecUser( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to delete SecUser instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowDeleteSecUser( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to create Service instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowCreateService( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to read Service instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowReadService( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to update Service instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowUpdateService( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to delete Service instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowDeleteService( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to create ServiceType instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowCreateServiceType( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to read ServiceType instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowReadServiceType( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to update ServiceType instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowUpdateServiceType( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to delete ServiceType instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowDeleteServiceType( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to create SysCluster instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowCreateSysCluster( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to read SysCluster instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowReadSysCluster( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to update SysCluster instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowUpdateSysCluster( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to delete SysCluster instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowDeleteSysCluster( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to create TSecGroup instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowCreateTSecGroup( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to read TSecGroup instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowReadTSecGroup( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to update TSecGroup instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowUpdateTSecGroup( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to delete TSecGroup instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowDeleteTSecGroup( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to create TSecGrpInc instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowCreateTSecGrpInc( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to read TSecGrpInc instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowReadTSecGrpInc( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to update TSecGrpInc instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowUpdateTSecGrpInc( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to delete TSecGrpInc instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowDeleteTSecGrpInc( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to create TSecGrpMemb instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowCreateTSecGrpMemb( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to read TSecGrpMemb instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowReadTSecGrpMemb( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to update TSecGrpMemb instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowUpdateTSecGrpMemb( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to delete TSecGrpMemb instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowDeleteTSecGrpMemb( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to create Tenant instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowCreateTenant( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to read Tenant instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowReadTenant( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to update Tenant instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowUpdateTenant( CFSecAuthorization Authorization );

	/**
	 *	Is the session allowed to delete Tenant instances?
	 *
	 *	@param	Authorization	The session authorization information.
	 */
	boolean allowDeleteTenant( CFSecAuthorization Authorization );
}
