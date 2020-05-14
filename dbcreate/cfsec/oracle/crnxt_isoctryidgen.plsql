--
--	@(#) dbcreate/cfsec/oracle/crnxt_isoctryidgen.plsql
--
--	com.github.msobkow.CFSec
--
--	Copyright (c) 2020 Mark Stephen Sobkow
--	
--	This file is part of MSS Code Factory.
--	
--	Licensed under the Apache License, Version 2.0 (the "License");
--	you may not use this file except in compliance with the License.
--	You may obtain a copy of the License at
--	
--	    http://www.apache.org/licenses/LICENSE-2.0
--	
--	Unless required by applicable law or agreed to in writing, software
--	distributed under the License is distributed on an "AS IS" BASIS,
--	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
--	See the License for the specific language governing permissions and
--	limitations under the License.
--	
--	Donations to support MSS Code Factory can be made at
--	https://www.paypal.com/paypalme2/MarkSobkow
--
--	Manufactured by MSS Code Factory 2.12
--
alter session set plsql_warnings = 'ENABLE:ALL';
/

create or replace function cfsec213.nxt_isoctryidgen
return smallint authid definer
is
	NextId smallint;
begin
	select cast( cfsec213.isoctryidgenseq.nextval as smallint )
	into NextId
	from dual;

	return NextId;
end nxt_isoctryidgen;
/

show errors function cfsec213.nxt_isoctryidgen;