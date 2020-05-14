cd $MSSCFHOME/cfsec_2_13/java/bin
echo "0002-LoadISOCcy.xml"
valgrind --leak-check=yes cfsecramloader Cluster=Insert:ISOCcy=Insert testdata/0002-LoadISOCcy.xml
