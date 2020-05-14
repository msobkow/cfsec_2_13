cd $MSSCFHOME/cfsec_2_13/java/bin
echo "0007-FailNamedLookup.xml"
valgrind --leak-check=yes cfsecramloader Cluster=Insert:ISOCtry=Insert:ISOCcy=Insert:ISOCtryCcy=Insert testdata/0007-FailNamedLookup.xml
