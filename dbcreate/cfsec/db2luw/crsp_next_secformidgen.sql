--
--	@(#) dbcreate/cfsec/db2luw/crsp_next_secformidgen.sql
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
create or replace procedure sp_next_secformidgen(	\
	in argId bigint,	\
	out NextId int )	\
modifies sql data	\
language sql	\
begin	\
	begin atomic	\
		if not exists (	\
			select *	\
			from cfsec213.clus_idg32	\
			where slice_id = 108	\
				and id = argId )	\
		then	\
			insert into cfsec213.clus_idg32 (	\
				id,	\
				slice_id,	\
				next_id )	\
			values (	\
				argId,	\
				108,	\
				1 );	\
		end if;	\
	\
		select next_id	\
		into NextId	\
		from cfsec213.clus_idg32	\
		where slice_id = 108	\
			and id = argId	\
		for update;	\
	\
		update cfsec213.clus_idg32	\
		set next_id = NextId + 1	\
		where slice_id = 108	\
			and id = argId;	\
	end;	\
end
