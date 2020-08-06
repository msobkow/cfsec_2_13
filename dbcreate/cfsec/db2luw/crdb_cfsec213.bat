@echo off
REM
REM	@(#) dbcreate/cfsec/db2luw/crdb_cfsec213.bat
REM
REM	org.msscf.msscf.CFSec
REM
REM	Copyright (c) 2020 Mark Stephen Sobkow
REM	
REM	MSS Code Factory CFSec 2.13 Security Essentials
REM	
REM	Copyright 2020 Mark Stephen Sobkow
REM	
REM		This file is part of MSS Code Factory.
REM	
REM		MSS Code Factory is available under dual commercial license from Mark Stephen
REM		Sobkow, or under the terms of the GNU General Public License, Version 3
REM		or later.
REM	
REM	    MSS Code Factory is free software: you can redistribute it and/or modify
REM	    it under the terms of the GNU General Public License as published by
REM	    the Free Software Foundation, either version 3 of the License, or
REM	    (at your option) any later version.
REM	
REM	    MSS Code Factory is distributed in the hope that it will be useful,
REM	    but WITHOUT ANY WARRANTY; without even the implied warranty of
REM	    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
REM	    GNU General Public License for more details.
REM	
REM	    You should have received a copy of the GNU General Public License
REM	    along with MSS Code Factory.  If not, see <https://www.gnu.org/licenses/>.
REM	
REM	Donations to support MSS Code Factory can be made at
REM	https://www.paypal.com/paypalme2/MarkSobkow
REM	
REM	Please contact Mark Stephen Sobkow at msobkow@sasktel.net for commercial licensing.
REM
REM Manufactured by MSS Code Factory 2.12
REM
REM	You must be logged in with full DBA authority
REM	before sourcing this script.
REM

echo #
echo #	Running crtbl_cfsec213.bat...
echo #
call crtbl_cfsec213.bat
echo #
echo #	Running cridx_cfsec213.bat...
echo #
call cridx_cfsec213.bat
echo #
echo #	Running crrel_cfsec213.bat...
echo #
call crrel_cfsec213.bat
echo #
echo #	Running crprocs_cfsec213.bat...
echo #
call crprocs_cfsec213.bat
