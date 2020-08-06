$ScriptLicense$

You will find a number of script files in this directory,
all of which are intended to be executed using tsql
to install a CFSec213 database.

Each of the *.bash scripts accepts the following arguments
unless otherwise noted:

	-S server	The name of the mssql server to use.
	-U username	The login name for the server.
	-P password	The password for logging in.
	-D database	The name of the database to contain the schema.
	-L logfile	Where to write the log messages.

All tables and indices are created in the default container for
the user name and database.


Database Creation Scripts
-------------------------

crtypes_cfsec213.tsql
	Creates the OmxClassCode type if it has not already been created, and the
	user data types with their associated rules for the schema.  The types should
	be created before the database, as MSSql will copy the data types from the
	model to each of the databases created.

crdatabase_cfsec213.tsql
	Creates the database "cfsec213" and the database owner
	login "cfsec213dba".  The initial password for the database
	owner is "cfsec213pwd" and should not be changed until after
	the remaining schema creation scripts have been executed.

	Creating the database itself takes roughly two hours on my C300 Linux system.

		drop database cfsec213
		go

		exec sp_droplogin cfsec213dba
		go


crdb_cfsec213.ksh
	The master script for creating the user data types, tables, indexes, and
	constraints for the database.

cridg_cfsec213.tsql
	Creates the database id generator objects.

crtbl_cfsec213.ksh
	Creates the database tables.

cridx_cfsec213.tsql
	Creates the database table indexes.

crrel_cfsec213.tsql
	Creates the relationships between the tables.

crtbl_clus.tsql
crtbl_hostnode.tsql
crtbl_iso_ccy.tsql
crtbl_iso_cntry.tsql
crtbl_iso_cntryccy.tsql
crtbl_iso_cntrylng.tsql
crtbl_iso_lang.tsql
crtbl_isotz.tsql
crtbl_secapp.tsql
crtbl_secdev.tsql
crtbl_secform.tsql
crtbl_secgrp.tsql
crtbl_secgrpfrm.tsql
crtbl_secinc.tsql
crtbl_secmemb.tsql
crtbl_secsess.tsql
crtbl_secuser.tsql
crtbl_hostsvc.tsql
crtbl_svctype.tsql
crtbl_sysclus.tsql
crtbl_tsecgrp.tsql
crtbl_tsecinc.tsql
crtbl_tsecmemb.tsql
crtbl_tenant.tsql
	The individual table creation scripts called by crtbl_cfsec213.tsql.

cridx_cluster_xufdname.tsql
cridx_cluster_xudescr.tsql
cridx_hostnode_xcluster.tsql
cridx_hostnode_xudsc.tsql
cridx_hostnode_xhnm.tsql
cridx_isocurrency_xcode.tsql
cridx_isocurrency_xuname.tsql
cridx_isocountry_xcode.tsql
cridx_isocountry_xuname.tsql
cridx_isocountryccy_xcountry.tsql
cridx_isocountryccy_xccy.tsql
cridx_isocountrylang_xcountry.tsql
cridx_isocountrylang_xlang.tsql
cridx_isolang_x6392.tsql
cridx_isolang_x6391.tsql
cridx_itz_xoffset.tsql
cridx_itz_xuname.tsql
cridx_itz_xiso.tsql
cridx_secapp_xcluster.tsql
cridx_secapp_xujeemnt.tsql
cridx_secdev_nameidx.tsql
cridx_secdev_usridx.tsql
cridx_secform_xcluster.tsql
cridx_secform_xsecapp.tsql
cridx_secform_xujeesvlt.tsql
cridx_secgroup_xcluster.tsql
cridx_secgroup_xclustervis.tsql
cridx_secgroup_xuname.tsql
cridx_secgroupform_xcluster.tsql
cridx_secgroupform_xgroup.tsql
cridx_secgroupform_xapp.tsql
cridx_secgroupform_xform.tsql
cridx_secgroupform_xuform.tsql
cridx_secinclude_xcluster.tsql
cridx_secinclude_xgroup.tsql
cridx_secinclude_xinc.tsql
cridx_secinclude_xuinc.tsql
cridx_secmember_xcluster.tsql
cridx_secmember_xgroup.tsql
cridx_secmember_xuser.tsql
cridx_secmember_xuuser.tsql
cridx_session_xsecuser.tsql
cridx_session_xsecdev.tsql
cridx_session_xstart.tsql
cridx_session_xfnsh.tsql
cridx_session_xproxy.tsql
cridx_secuser_xulogin.tsql
cridx_secuser_xemconf.tsql
cridx_secuser_xpwdrst.tsql
cridx_secuser_defdevidx.tsql
cridx_service_xcluster.tsql
cridx_service_xhost.tsql
cridx_service_xtype.tsql
cridx_service_xutype.tsql
cridx_service_xuhpt.tsql
cridx_servicetype_xudsc.tsql
cridx_sysclus_xclus.tsql
cridx_tsecgroup_xtenant.tsql
cridx_tsecgroup_xtenantvis.tsql
cridx_tsecgroup_xuname.tsql
cridx_tsecinclude_xtenant.tsql
cridx_tsecinclude_xgroup.tsql
cridx_tsecinclude_xinc.tsql
cridx_tsecinclude_xuinc.tsql
cridx_tsecmember_xtenant.tsql
cridx_tsecmember_xgroup.tsql
cridx_tsecmember_xuser.tsql
cridx_tsecmember_xuuser.tsql
cridx_tenant_xcluster.tsql
cridx_tenant_xuname.tsql
	The individual table index creation scripts called by cridx_cfsec213.tsql.

crsp_next_isoccyidgen.tsql
crsp_next_isoctryidgen.tsql
crsp_next_isolangidgen.tsql
crsp_next_isotzoneidgen.tsql
crsp_next_servicetypeidgen.tsql
crsp_next_clusteridgen.tsql
crsp_next_tenantidgen.tsql
	The stored procedures for getting the next schema id from the generators.

crsp_next_clus_secappidgen.tsql
crsp_next_clus_secformidgen.tsql
crsp_next_clus_secgroupidgen.tsql
crsp_next_clus_hostnodeidgen.tsql
crsp_next_clus_secgroupformidgen.tsql
crsp_next_clus_secgrpincidgen.tsql
crsp_next_clus_secgrpmembidgen.tsql
crsp_next_clus_serviceidgen.tsql
crsp_next_tenant_tsecgroupidgen.tsql
crsp_next_tenant_tsecgrpincidgen.tsql
crsp_next_tenant_tsecgrpmembidgen.tsql
	The stored procedures for getting the next table-dispenssed id from the generators.


Database Drop Scripts
---------------------

drdb_cfsec213.tsql
	Drops the id generators, tables, indexes and constraints
	of the database.

dridg_cfsec213.tsql
	Drops the database id generator objects.

drtbl_cfsec213.tsql
	Drops the database tables.

dridx_cfsec213.tsql
	Drops the database table indexes.

drrel_cfsec213.tsql
	Drops the relationships between the tables.
