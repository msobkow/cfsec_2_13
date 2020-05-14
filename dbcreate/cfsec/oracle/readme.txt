# **********************************************************************
#
#	package dbcreate;
#	@(#) dbcreate/cfsec/oracle/readme.txt
$MssBashLicense$


You will find a number of script files in this directory,
all of which are intended to be executed using psql
to install a CFSec213 database.

Each of the *.ksh scripts accepts the following arguments
unless otherwise noted:

	-S server	The name of the Oracle server to use.
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

crdatabase_cfsec213.plsql
	Creates the database cfsec213 in the cfsec213_data1
	tablespace.  Optionally creates the cfsec213_data1 and
	cfsec213_idx1 tablespaces if "-d dirName" is specified on
	the command line.

crdb_cfsec213.ksh
	The master script for creating the database schema.

cridg_cfsec213.plsql
	Creates the database id generator objects.

crtbl_cfsec213.ksh
	Creates the database tables.

cridx_cfsec213.plsql
	Creates the database table indexes.

crrel_cfsec213.plsql
	Creates the relationships between the tables.

crtbl_clus.plsql
crtbl_hostnode.plsql
crtbl_iso_ccy.plsql
crtbl_iso_cntry.plsql
crtbl_iso_cntryccy.plsql
crtbl_iso_cntrylng.plsql
crtbl_iso_lang.plsql
crtbl_isotz.plsql
crtbl_secapp.plsql
crtbl_secdev.plsql
crtbl_secform.plsql
crtbl_secgrp.plsql
crtbl_secgrpfrm.plsql
crtbl_secinc.plsql
crtbl_secmemb.plsql
crtbl_secsess.plsql
crtbl_secuser.plsql
crtbl_hostsvc.plsql
crtbl_svctype.plsql
crtbl_sysclus.plsql
crtbl_tsecgrp.plsql
crtbl_tsecinc.plsql
crtbl_tsecmemb.plsql
crtbl_tenant.plsql
	The individual table creation scripts called by crtbl_cfsec213.plsql.

cridx_cluster_xufdname.plsql
cridx_cluster_xudescr.plsql
cridx_hostnode_xcluster.plsql
cridx_hostnode_xudsc.plsql
cridx_hostnode_xhnm.plsql
cridx_isocurrency_xcode.plsql
cridx_isocurrency_xuname.plsql
cridx_isocountry_xcode.plsql
cridx_isocountry_xuname.plsql
cridx_isocountryccy_xcountry.plsql
cridx_isocountryccy_xccy.plsql
cridx_isocountrylang_xcountry.plsql
cridx_isocountrylang_xlang.plsql
cridx_isolang_x6392.plsql
cridx_isolang_x6391.plsql
cridx_itz_xoffset.plsql
cridx_itz_xuname.plsql
cridx_itz_xiso.plsql
cridx_secapp_xcluster.plsql
cridx_secapp_xujeemnt.plsql
cridx_secdev_nameidx.plsql
cridx_secdev_usridx.plsql
cridx_secform_xcluster.plsql
cridx_secform_xsecapp.plsql
cridx_secform_xujeesvlt.plsql
cridx_secgroup_xcluster.plsql
cridx_secgroup_xclustervis.plsql
cridx_secgroup_xuname.plsql
cridx_secgroupform_xcluster.plsql
cridx_secgroupform_xgroup.plsql
cridx_secgroupform_xapp.plsql
cridx_secgroupform_xform.plsql
cridx_secgroupform_xuform.plsql
cridx_secinclude_xcluster.plsql
cridx_secinclude_xgroup.plsql
cridx_secinclude_xinc.plsql
cridx_secinclude_xuinc.plsql
cridx_secmember_xcluster.plsql
cridx_secmember_xgroup.plsql
cridx_secmember_xuser.plsql
cridx_secmember_xuuser.plsql
cridx_session_xsecuser.plsql
cridx_session_xsecdev.plsql
cridx_session_xstart.plsql
cridx_session_xfnsh.plsql
cridx_session_xproxy.plsql
cridx_secuser_xulogin.plsql
cridx_secuser_xemconf.plsql
cridx_secuser_xpwdrst.plsql
cridx_secuser_defdevidx.plsql
cridx_service_xcluster.plsql
cridx_service_xhost.plsql
cridx_service_xtype.plsql
cridx_service_xutype.plsql
cridx_service_xuhpt.plsql
cridx_servicetype_xudsc.plsql
cridx_sysclus_xclus.plsql
cridx_tsecgroup_xtenant.plsql
cridx_tsecgroup_xtenantvis.plsql
cridx_tsecgroup_xuname.plsql
cridx_tsecinclude_xtenant.plsql
cridx_tsecinclude_xgroup.plsql
cridx_tsecinclude_xinc.plsql
cridx_tsecinclude_xuinc.plsql
cridx_tsecmember_xtenant.plsql
cridx_tsecmember_xgroup.plsql
cridx_tsecmember_xuser.plsql
cridx_tsecmember_xuuser.plsql
cridx_tenant_xcluster.plsql
cridx_tenant_xuname.plsql
	The individual table index creation scripts called by cridx_cfsec213.plsql.

