@echo off
REM
REM	@(#) dbcreate/cfsec/db2luw/crdb_cfsec213.bat
REM
REM	org.msscf.msscf.CFSec
REM
REM	Copyright (c) 2020 Mark Stephen Sobkow
REM	
REM	This file is part of MSS Code Factory.
REM	
REM	Licensed under the Apache License, Version 2.0 (the "License");
REM	you may not use this file except in compliance with the License.
REM	You may obtain a copy of the License at
REM	
REM	    http://www.apache.org/licenses/LICENSE-2.0
REM	
REM	Unless required by applicable law or agreed to in writing, software
REM	distributed under the License is distributed on an "AS IS" BASIS,
REM	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
REM	See the License for the specific language governing permissions and
REM	limitations under the License.
REM	
REM	Donations to support MSS Code Factory can be made at
REM	https://www.paypal.com/paypalme2/MarkSobkow
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
