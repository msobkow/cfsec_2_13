$SqlScriptHeader$


You will find a number of script files in this directory,
all of which are intended to be executed using the DB/2 LUW
bash shell integration to install a CFSec213 database.

You must be logged in as the schema administrator cfsec213
in order to run these scripts.



Database Creation Scripts
-------------------------

crdb_cfsec213.sql
	Creates the id generators, tables, indexes and constraints
	of the database.

cridg_cfsec213.sql
	Creates the database id generator objects.

crtbl_cfsec213.ksh
	Creates the database tables.

cridx_cfsec213.sql
	Creates the database table indexes.

crrel_cfsec213.sql
	Creates the relationships between the tables.

crtbl_clus.sql
crtbl_hostnode.sql
crtbl_iso_ccy.sql
crtbl_iso_cntry.sql
crtbl_iso_cntryccy.sql
crtbl_iso_cntrylng.sql
crtbl_iso_lang.sql
crtbl_isotz.sql
crtbl_secapp.sql
crtbl_secdev.sql
crtbl_secform.sql
crtbl_secgrp.sql
crtbl_secgrpfrm.sql
crtbl_secinc.sql
crtbl_secmemb.sql
crtbl_secsess.sql
crtbl_secuser.sql
crtbl_hostsvc.sql
crtbl_svctype.sql
crtbl_sysclus.sql
crtbl_tsecgrp.sql
crtbl_tsecinc.sql
crtbl_tsecmemb.sql
crtbl_tenant.sql
	The individual table creation scripts called by crtbl_cfsec213.sql.

cridx_cluster_xufdname.sql
cridx_cluster_xudescr.sql
cridx_hostnode_xcluster.sql
cridx_hostnode_xudsc.sql
cridx_hostnode_xhnm.sql
cridx_isocurrency_xcode.sql
cridx_isocurrency_xuname.sql
cridx_isocountry_xcode.sql
cridx_isocountry_xuname.sql
cridx_isocountryccy_xcountry.sql
cridx_isocountryccy_xccy.sql
cridx_isocountrylang_xcountry.sql
cridx_isocountrylang_xlang.sql
cridx_isolang_x6392.sql
cridx_isolang_x6391.sql
cridx_itz_xoffset.sql
cridx_itz_xuname.sql
cridx_itz_xiso.sql
cridx_secapp_xcluster.sql
cridx_secapp_xujeemnt.sql
cridx_secdev_nameidx.sql
cridx_secdev_usridx.sql
cridx_secform_xcluster.sql
cridx_secform_xsecapp.sql
cridx_secform_xujeesvlt.sql
cridx_secgroup_xcluster.sql
cridx_secgroup_xclustervis.sql
cridx_secgroup_xuname.sql
cridx_secgroupform_xcluster.sql
cridx_secgroupform_xgroup.sql
cridx_secgroupform_xapp.sql
cridx_secgroupform_xform.sql
cridx_secgroupform_xuform.sql
cridx_secinclude_xcluster.sql
cridx_secinclude_xgroup.sql
cridx_secinclude_xinc.sql
cridx_secinclude_xuinc.sql
cridx_secmember_xcluster.sql
cridx_secmember_xgroup.sql
cridx_secmember_xuser.sql
cridx_secmember_xuuser.sql
cridx_session_xsecuser.sql
cridx_session_xsecdev.sql
cridx_session_xstart.sql
cridx_session_xfnsh.sql
cridx_session_xproxy.sql
cridx_secuser_xulogin.sql
cridx_secuser_xemconf.sql
cridx_secuser_xpwdrst.sql
cridx_secuser_defdevidx.sql
cridx_service_xcluster.sql
cridx_service_xhost.sql
cridx_service_xtype.sql
cridx_service_xutype.sql
cridx_service_xuhpt.sql
cridx_servicetype_xudsc.sql
cridx_sysclus_xclus.sql
cridx_tsecgroup_xtenant.sql
cridx_tsecgroup_xtenantvis.sql
cridx_tsecgroup_xuname.sql
cridx_tsecinclude_xtenant.sql
cridx_tsecinclude_xgroup.sql
cridx_tsecinclude_xinc.sql
cridx_tsecinclude_xuinc.sql
cridx_tsecmember_xtenant.sql
cridx_tsecmember_xgroup.sql
cridx_tsecmember_xuser.sql
cridx_tsecmember_xuuser.sql
cridx_tenant_xcluster.sql
cridx_tenant_xuname.sql
	The individual table index creation scripts called by cridx_cfsec213.sql.




Database Drop Scripts
---------------------

drdb_cfsec213.sql
	Drops the id generators, tables, indexes and constraints
	of the database.

dridg_cfsec213.sql
	Drops the database id generator objects.

drtbl_cfsec213.sql
	Drops the database tables.

dridx_cfsec213.sql
	Drops the database table indexes.

drrel_cfsec213.sql
	Drops the relationships between the tables.


