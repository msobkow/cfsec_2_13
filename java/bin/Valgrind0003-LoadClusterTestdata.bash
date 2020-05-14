cd $MSSCFHOME/cfsec_2_13/java/bin
echo "0003-LoadClusterTestdata.xml"
valgrind --leak-check=yes cfsecramloader Cluster=Insert testdata/0003-LoadClusterTestdata.xml
