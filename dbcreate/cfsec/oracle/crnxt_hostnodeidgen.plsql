--
--	@(#) dbcreate/cfsec/oracle/crnxt_hostnodeidgen.plsql
--
--	org.msscf.msscf.CFSec
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

create or replace function cfsec213.nxt_hostnodeidgen(
	argId numeric )
return numeric authid definer
is
	SliceId smallint := 116;
	NextId numeric(22,0);
	CountEm integer;
begin
	select count(*)
	into CountEm
	from cfsec213.clus_idg64
	where slice_id = SliceId
			and id = argId;

	if CountEm < 1 then
		insert into cfsec213.clus_idg64 (
			id,
			slice_id,
			next_id )
		values (
			argId,
			SliceId,
			1 );
	end if;

	select next_id
	into NextId
	from cfsec213.clus_idg64
	where slice_id = SliceId
		and id = argId
	for update;

	update cfsec213.clus_idg64
	set next_id = NextId + 1
	where slice_id = SliceId
		and id = argId;

	return NextId;
end nxt_hostnodeidgen;
/

show errors function cfsec213.nxt_hostnodeidgen;
