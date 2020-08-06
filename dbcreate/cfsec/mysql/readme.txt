# **********************************************************************
#
#	package dbcreate;
#	@(#) dbcreate/cfsec/mysql/readme.txt
$MssBashLicense$

You will find a number of script files in this directory,
all of which are intended to be executed using psql
to install a CFSec213 database.

Each of the *.ksh scripts accepts the following arguments
unless otherwise noted:

	-U username	The admin login name for the server (postgres).
	-P password	The admin password for logging in.
	-L logfile	Where to write the log messages.



Database Creation Scripts
-------------------------

crdatabase_cfsec213.pgsql
	Creates the database cfsec213 in the cfsec213_data1
	tablespace.

crdb_cfsec213.ksh
	The master script for creating the database schema.

cridg_cfsec213.pgsql
	Creates the database id generator objects.

crtbl_cfsec213.ksh
	Creates the database tables.

cridx_cfsec213.pgsql
	Creates the database table indexes.

crrel_cfsec213.pgsql
	Creates the relationships between the tables.

crtbl_clus.mysql
crtbl_hostnode.mysql
crtbl_iso_ccy.mysql
crtbl_iso_cntry.mysql
crtbl_iso_cntryccy.mysql
crtbl_iso_cntrylng.mysql
crtbl_iso_lang.mysql
crtbl_isotz.mysql
crtbl_secapp.mysql
crtbl_secdev.mysql
crtbl_secform.mysql
crtbl_secgrp.mysql
crtbl_secgrpfrm.mysql
crtbl_secinc.mysql
crtbl_secmemb.mysql
crtbl_secsess.mysql
crtbl_secuser.mysql
crtbl_hostsvc.mysql
crtbl_svctype.mysql
crtbl_sysclus.mysql
crtbl_tsecgrp.mysql
crtbl_tsecinc.mysql
crtbl_tsecmemb.mysql
crtbl_tenant.mysql
	The individual table creation scripts called by crtbl_cfsec213.pgsql.

cridx_cluster_xufdname.mysql
cridx_cluster_xudescr.mysql
cridx_hostnode_xcluster.mysql
cridx_hostnode_xudsc.mysql
cridx_hostnode_xhnm.mysql
cridx_isocurrency_xcode.mysql
cridx_isocurrency_xuname.mysql
cridx_isocountry_xcode.mysql
cridx_isocountry_xuname.mysql
cridx_isocountryccy_xcountry.mysql
cridx_isocountryccy_xccy.mysql
cridx_isocountrylang_xcountry.mysql
cridx_isocountrylang_xlang.mysql
cridx_isolang_x6392.mysql
cridx_isolang_x6391.mysql
cridx_itz_xoffset.mysql
cridx_itz_xuname.mysql
cridx_itz_xiso.mysql
cridx_secapp_xcluster.mysql
cridx_secapp_xujeemnt.mysql
cridx_secdev_nameidx.mysql
cridx_secdev_usridx.mysql
cridx_secform_xcluster.mysql
cridx_secform_xsecapp.mysql
cridx_secform_xujeesvlt.mysql
cridx_secgroup_xcluster.mysql
cridx_secgroup_xclustervis.mysql
cridx_secgroup_xuname.mysql
cridx_secgroupform_xcluster.mysql
cridx_secgroupform_xgroup.mysql
cridx_secgroupform_xapp.mysql
cridx_secgroupform_xform.mysql
cridx_secgroupform_xuform.mysql
cridx_secinclude_xcluster.mysql
cridx_secinclude_xgroup.mysql
cridx_secinclude_xinc.mysql
cridx_secinclude_xuinc.mysql
cridx_secmember_xcluster.mysql
cridx_secmember_xgroup.mysql
cridx_secmember_xuser.mysql
cridx_secmember_xuuser.mysql
cridx_session_xsecuser.mysql
cridx_session_xsecdev.mysql
cridx_session_xstart.mysql
cridx_session_xfnsh.mysql
cridx_session_xproxy.mysql
cridx_secuser_xulogin.mysql
cridx_secuser_xemconf.mysql
cridx_secuser_xpwdrst.mysql
cridx_secuser_defdevidx.mysql
cridx_service_xcluster.mysql
cridx_service_xhost.mysql
cridx_service_xtype.mysql
cridx_service_xutype.mysql
cridx_service_xuhpt.mysql
cridx_servicetype_xudsc.mysql
cridx_sysclus_xclus.mysql
cridx_tsecgroup_xtenant.mysql
cridx_tsecgroup_xtenantvis.mysql
cridx_tsecgroup_xuname.mysql
cridx_tsecinclude_xtenant.mysql
cridx_tsecinclude_xgroup.mysql
cridx_tsecinclude_xinc.mysql
cridx_tsecinclude_xuinc.mysql
cridx_tsecmember_xtenant.mysql
cridx_tsecmember_xgroup.mysql
cridx_tsecmember_xuser.mysql
cridx_tsecmember_xuuser.mysql
cridx_tenant_xcluster.mysql
cridx_tenant_xuname.mysql
	The individual table index creation scripts called by cridx_cfsec213.pgsql.



Database Drop Scripts
---------------------

drdb_cfsec213.pgsql
	Drops the id generators, tables, indexes and constraints
	of the database.

dridg_cfsec213.pgsql
	Drops the database id generator objects.

drtbl_cfsec213.pgsql
	Drops the database tables.

dridx_cfsec213.pgsql
	Drops the database table indexes.

drrel_cfsec213.pgsql
	Drops the relationships between the tables.


