--
--	@(#) dbcreate/cfsec/db2luw/crrel_secinc.sql
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

ALTER TABLE CFSec213.SecInc ADD CONSTRAINT secgrpinc_clus	\
	FOREIGN KEY (	\
		ClusId	\
	) REFERENCES CFSec213.clus (	\
		Id	\
	) ON DELETE RESTRICT

ALTER TABLE CFSec213.SecInc ADD CONSTRAINT secgrpinc_grp	\
	FOREIGN KEY (	\
		ClusId,	\
		SecGrpId	\
	) REFERENCES CFSec213.SecGrp (	\
		ClusterId,	\
		SecGroupId	\
	) ON DELETE RESTRICT

ALTER TABLE CFSec213.SecInc ADD CONSTRAINT secgrpinc_subgrp	\
	FOREIGN KEY (	\
		ClusId,	\
		IncGrpId	\
	) REFERENCES CFSec213.SecGrp (	\
		ClusterId,	\
		SecGroupId	\
	) ON DELETE RESTRICT

commit