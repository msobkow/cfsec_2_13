--
--	@(#) dbcreate/cfsec/db2luw/crsp_is_system_user.sql
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
create or replace function sp_is_system_user(	\
	argSecUserId varchar(36) )	\
returns integer \
language sql	\
begin	\
	declare	retval integer default 0;	\
  begin	\
	set( retval ) = ( 0 );	\
	for row as	\
		select	\
			susr.SecUserId	\
		from cfsec213.SecUser as susr	\
		where	\
				susr.SecUserId = argSecUserId	\
			and susr.login_id = 'system'	\
	do	\
		set( retval ) = ( 1 );	\
		return retval;	\
	end for;	\
	return retval;	\
  end;	\
end
