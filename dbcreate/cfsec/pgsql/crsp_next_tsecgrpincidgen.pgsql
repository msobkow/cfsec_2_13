--
--	@(#) dbcreate/cfsec/pgsql/crsp_next_tsecgrpincidgen.pgsql
--
--	org.msscf.msscf.CFSec
--
--	Copyright (c) 2020 Mark Stephen Sobkow
--	
--	MSS Code Factory CFSec 2.13 Security Essentials
--	
--	Copyright 2020 Mark Stephen Sobkow
--	
--		This file is part of MSS Code Factory.
--	
--		MSS Code Factory is available under dual commercial license from Mark Stephen
--		Sobkow, or under the terms of the GNU General Public License, Version 3
--		or later.
--	
--	    MSS Code Factory is free software: you can redistribute it and/or modify
--	    it under the terms of the GNU General Public License as published by
--	    the Free Software Foundation, either version 3 of the License, or
--	    (at your option) any later version.
--	
--	    MSS Code Factory is distributed in the hope that it will be useful,
--	    but WITHOUT ANY WARRANTY; without even the implied warranty of
--	    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
--	    GNU General Public License for more details.
--	
--	    You should have received a copy of the GNU General Public License
--	    along with MSS Code Factory.  If not, see <https://www.gnu.org/licenses/>.
--	
--	Donations to support MSS Code Factory can be made at
--	https://www.paypal.com/paypalme2/MarkSobkow
--	
--	Please contact Mark Stephen Sobkow at msobkow@sasktel.net for commercial licensing.
--
--	Manufactured by MSS Code Factory 2.12
--

create or replace function cfsec213.sp_next_tsecgrpincidgen(
	argId bigint )
returns bigint as $$
declare
	SliceId smallint = 119;
	NextId bigint;
begin
	if not exists (
		select *
		from cfsec213.tenant_idg64
		where slice_id = SliceId
			and id = argId )
	then
		insert into cfsec213.tenant_idg64 (
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
	from cfsec213.tenant_idg64
	where slice_id = SliceId
		and id = argId
	for update;

	update cfsec213.tenant_idg64
	set next_id = NextId + 1
	where slice_id = SliceId
		and id = argId;

	return NextId;
end;
$$ language plpgsql;
