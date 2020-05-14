cd $MSSCFHOME/cfsec_2_13/java/bin
echo "0004-TestNamedLookup.xml"
valgrind --leak-check=yes cfsecramloader Cluster=Insert:ISOCtry=Insert:ISOCcy=Insert:ISOCtryCcy=Insert testdata/0004-TestNamedLookup.xml
