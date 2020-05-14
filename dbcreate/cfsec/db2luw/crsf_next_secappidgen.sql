--
--	@(#) dbcreate/cfsec/db2luw/crsf_next_secappidgen.sql
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
create or replace procedure sf_next_secappidgen(	\
	in argId bigint )	\
dynamic result sets 1	\
modifies sql data	\
language sql	\
begin	\
	declare NextId int;	\
	declare retcurs cursor with return to client for	\
		select NextId from sysibm.sysdummy1;	\
	begin	\
		call sp_next_secappidgen( argId, NextId );	\
		open retcurs;	\
	end;	\
end
