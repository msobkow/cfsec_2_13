--
--	@(#) dbcreate/cfsec/db2luw/crsp_read_iso_lang_by_ididx.sql
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
create or replace procedure sp_read_iso_lang_by_ididx(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argISOLangId smallint )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare permissionFlag integer;	\
	declare isSystemUser integer;	\
	declare syscurs cursor with return to client for	\
		select	\
				a007.createdby as createdby,	\
				to_char( a007.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a007.updatedby as updatedby,	\
				to_char( a007.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a007.isolangid as isolangid,	\
			a007.iso_code3 as iso_code3,	\
			a007.iso_code2 as iso_code2,	\
			a007.eng_name as eng_name,	\
			a007.revision as revision	\
		from cfsec213.iso_lang as a007	\
		where	\
			a007.isolangid = argISOLangId;	\
	declare usercurs cursor with return to client for	\
		select	\
				a007.createdby as createdby,	\
				to_char( a007.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a007.updatedby as updatedby,	\
				to_char( a007.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a007.isolangid as isolangid,	\
			a007.iso_code3 as iso_code3,	\
			a007.iso_code2 as iso_code2,	\
			a007.eng_name as eng_name,	\
			a007.revision as revision	\
		from cfsec213.iso_lang as a007	\
		where	\
			a007.isolangid = argISOLangId;	\
	begin	\
		open syscurs;	\
	end;	\
end
