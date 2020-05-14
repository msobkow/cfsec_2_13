# **********************************************************************
#
#	package dbcreate;
#	@(#) dbcreate/cfsec/pgsql/readme.txt
$MssBashLicense$

You will find a number of script files in this directory,
all of which are intended to be executed using psql
to install a CFSec213 database.

Each of the *.ksh scripts accepts the following arguments
unless otherwise noted:

	-S server	The name of the PostgreSQL server to use.
	-U username	The admin login name for the server (postgres).
	-P password	The admin password for logging in.
	-d database	The name of the database to contain the schema.
	-L logfile	Where to write the log messages.

crdb_cfsec213.bash will also create the tablespaces for
the database if you specify:

	-D datadir	The directory for the tablespace.

If you don't specify a directory, it's assumed that the tablespaces
cfsec213_data1 and cfsec213_idx1 already exists.


Database Creation Scripts
-------------------------

crdatabase_cfsec213.pgsql
	Creates the database cfsec213 in the cfsec213_data1
	tablespace.  Optionally creates the cfsec213_data1 and
	cfsec213_idx1 tablespaces if "-d dirName" is specified on
	the command line.

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

crtbl_clus.pgsql
crtbl_hostnode.pgsql
crtbl_iso_ccy.pgsql
crtbl_iso_cntry.pgsql
crtbl_iso_cntryccy.pgsql
crtbl_iso_cntrylng.pgsql
crtbl_iso_lang.pgsql
crtbl_isotz.pgsql
crtbl_secapp.pgsql
crtbl_secdev.pgsql
crtbl_secform.pgsql
crtbl_secgrp.pgsql
crtbl_secgrpfrm.pgsql
crtbl_secinc.pgsql
crtbl_secmemb.pgsql
crtbl_secsess.pgsql
crtbl_secuser.pgsql
crtbl_hostsvc.pgsql
crtbl_svctype.pgsql
crtbl_sysclus.pgsql
crtbl_tsecgrp.pgsql
crtbl_tsecinc.pgsql
crtbl_tsecmemb.pgsql
crtbl_tenant.pgsql
	The individual table creation scripts called by crtbl_cfsec213.pgsql.

cridx_cluster_xufdname.pgsql
cridx_cluster_xudescr.pgsql
cridx_hostnode_xcluster.pgsql
cridx_hostnode_xudsc.pgsql
cridx_hostnode_xhnm.pgsql
cridx_isocurrency_xcode.pgsql
cridx_isocurrency_xuname.pgsql
cridx_isocountry_xcode.pgsql
cridx_isocountry_xuname.pgsql
cridx_isocountryccy_xcountry.pgsql
cridx_isocountryccy_xccy.pgsql
cridx_isocountrylang_xcountry.pgsql
cridx_isocountrylang_xlang.pgsql
cridx_isolang_x6392.pgsql
cridx_isolang_x6391.pgsql
cridx_itz_xoffset.pgsql
cridx_itz_xuname.pgsql
cridx_itz_xiso.pgsql
cridx_secapp_xcluster.pgsql
cridx_secapp_xujeemnt.pgsql
cridx_secdev_nameidx.pgsql
cridx_secdev_usridx.pgsql
cridx_secform_xcluster.pgsql
cridx_secform_xsecapp.pgsql
cridx_secform_xujeesvlt.pgsql
cridx_secgroup_xcluster.pgsql
cridx_secgroup_xclustervis.pgsql
cridx_secgroup_xuname.pgsql
cridx_secgroupform_xcluster.pgsql
cridx_secgroupform_xgroup.pgsql
cridx_secgroupform_xapp.pgsql
cridx_secgroupform_xform.pgsql
cridx_secgroupform_xuform.pgsql
cridx_secinclude_xcluster.pgsql
cridx_secinclude_xgroup.pgsql
cridx_secinclude_xinc.pgsql
cridx_secinclude_xuinc.pgsql
cridx_secmember_xcluster.pgsql
cridx_secmember_xgroup.pgsql
cridx_secmember_xuser.pgsql
cridx_secmember_xuuser.pgsql
cridx_session_xsecuser.pgsql
cridx_session_xsecdev.pgsql
cridx_session_xstart.pgsql
cridx_session_xfnsh.pgsql
cridx_session_xproxy.pgsql
cridx_secuser_xulogin.pgsql
cridx_secuser_xemconf.pgsql
cridx_secuser_xpwdrst.pgsql
cridx_secuser_defdevidx.pgsql
cridx_service_xcluster.pgsql
cridx_service_xhost.pgsql
cridx_service_xtype.pgsql
cridx_service_xutype.pgsql
cridx_service_xuhpt.pgsql
cridx_servicetype_xudsc.pgsql
cridx_sysclus_xclus.pgsql
cridx_tsecgroup_xtenant.pgsql
cridx_tsecgroup_xtenantvis.pgsql
cridx_tsecgroup_xuname.pgsql
cridx_tsecinclude_xtenant.pgsql
cridx_tsecinclude_xgroup.pgsql
cridx_tsecinclude_xinc.pgsql
cridx_tsecinclude_xuinc.pgsql
cridx_tsecmember_xtenant.pgsql
cridx_tsecmember_xgroup.pgsql
cridx_tsecmember_xuser.pgsql
cridx_tsecmember_xuuser.pgsql
cridx_tenant_xcluster.pgsql
cridx_tenant_xuname.pgsql
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

