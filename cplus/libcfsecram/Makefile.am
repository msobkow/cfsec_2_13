MAJOR_VERSION=2

MINOR_VERSION=13

BUILD_NUMBER=11189

RELEASE=$(MAJOR_VERSION).$(MINOR_VERSION).$(BUILD_NUMBER)

SUB_RELEASE=$(MAJOR_VERSION).$(MINOR_VERSION)

MAIN_RELEASE=$(MAJOR_VERSION)

DEPDIR=debug

LT_OBJDIR=.libs

BIN=$(prefix)/bin/msobkow/$(MAJOR_VERSION).0.$(MINOR_VERSION)

bindir=$(prefix)/bin/msobkow/$(MAJOR_VERSION).0.$(MINOR_VERSION)

libcfsecramdir=${libdir}

libcfsecram_LTLIBRARIES=libcfsecram.la

libcfsecram_ladir=

libcfsecram_la_COREdir=$(prefix)/include/msobkow/$(MAJOR_VERSION).0.$(MINOR_VERSION)/cfsecram

libcfsecram_la_SOURCES= CFSecRamSchema.cpp CFSecRamPublic.cpp  CFSecRamClusterTable.cpp CFSecRamClusterId32Gen.cpp CFSecRamClusterId64Gen.cpp CFSecRamHostNodeTable.cpp CFSecRamISOCcyTable.cpp CFSecRamISOCtryTable.cpp CFSecRamISOCtryCcyTable.cpp CFSecRamISOCtryLangTable.cpp CFSecRamISOLangTable.cpp CFSecRamISOTZoneTable.cpp CFSecRamSecAppTable.cpp CFSecRamSecDeviceTable.cpp CFSecRamSecFormTable.cpp CFSecRamSecGroupTable.cpp CFSecRamSecGroupFormTable.cpp CFSecRamSecGrpIncTable.cpp CFSecRamSecGrpMembTable.cpp CFSecRamSecSessionTable.cpp CFSecRamSecUserTable.cpp CFSecRamServiceTable.cpp CFSecRamServiceTypeTable.cpp CFSecRamSysClusterTable.cpp CFSecRamTSecGroupTable.cpp CFSecRamTSecGrpIncTable.cpp CFSecRamTSecGrpMembTable.cpp CFSecRamTenantTable.cpp CFSecRamTenantId32Gen.cpp CFSecRamTenantId64Gen.cpp

libcfsecram_la_HEADERS=

libcfsecram_la_CORE_HEADERS= cfsecram/CFSecRamSchema.hpp cfsecram/CFSecRamPublic.hpp  cfsecram/CFSecRamClusterTable.hpp cfsecram/CFSecRamClusterId32Gen.hpp cfsecram/CFSecRamClusterId64Gen.hpp cfsecram/CFSecRamHostNodeTable.hpp cfsecram/CFSecRamISOCcyTable.hpp cfsecram/CFSecRamISOCtryTable.hpp cfsecram/CFSecRamISOCtryCcyTable.hpp cfsecram/CFSecRamISOCtryLangTable.hpp cfsecram/CFSecRamISOLangTable.hpp cfsecram/CFSecRamISOTZoneTable.hpp cfsecram/CFSecRamSecAppTable.hpp cfsecram/CFSecRamSecDeviceTable.hpp cfsecram/CFSecRamSecFormTable.hpp cfsecram/CFSecRamSecGroupTable.hpp cfsecram/CFSecRamSecGroupFormTable.hpp cfsecram/CFSecRamSecGrpIncTable.hpp cfsecram/CFSecRamSecGrpMembTable.hpp cfsecram/CFSecRamSecSessionTable.hpp cfsecram/CFSecRamSecUserTable.hpp cfsecram/CFSecRamServiceTable.hpp cfsecram/CFSecRamServiceTypeTable.hpp cfsecram/CFSecRamSysClusterTable.hpp cfsecram/CFSecRamTSecGroupTable.hpp cfsecram/CFSecRamTSecGrpIncTable.hpp cfsecram/CFSecRamTSecGrpMembTable.hpp cfsecram/CFSecRamTenantTable.hpp cfsecram/CFSecRamTenantId32Gen.hpp cfsecram/CFSecRamTenantId64Gen.hpp

libcfsecram_la_LDFLAGS= -version-info $(MAJOR_VERSION):$(MINOR_VERSION) -lmpfr -lxerces-c -luuid -l:libcflib.so.$(MAJOR_VERSION).0.$(MINOR_VERSION) -l:libcfsec.so.$(MAJOR_VERSION).0.$(MINOR_VERSION) -l:libcfsecsaxloader.so.$(MAJOR_VERSION).0.$(MINOR_VERSION) -lstdc++fs

libcfsecram_la_CXXFLAGS= -I$(top_srcdir) -I$(prefix)/include/msobkow/$(MAJOR_VERSION).0.$(MINOR_VERSION) -I$(prefix)/include/msobkow/$(MAJOR_VERSION).0.$(MINOR_VERSION)

ACLOCAL_AMFLAGS= -Im4
