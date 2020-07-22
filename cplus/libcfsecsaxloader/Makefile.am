MAJOR_VERSION=2

MINOR_VERSION=13

BUILD_NUMBER=11195

RELEASE=$(MAJOR_VERSION).$(MINOR_VERSION).$(BUILD_NUMBER)

SUB_RELEASE=$(MAJOR_VERSION).$(MINOR_VERSION)

MAIN_RELEASE=$(MAJOR_VERSION)

DEPDIR=debug

LT_OBJDIR=.libs

BIN=$(prefix)/bin/msscf/$(MAJOR_VERSION).0.$(MINOR_VERSION)

bindir=$(prefix)/bin/msscf/$(MAJOR_VERSION).0.$(MINOR_VERSION)

libcfsecxsd_ladir=$(prefix)/share/msscf/$(MAJOR_VERSION).0.$(MINOR_VERSION)/xsd

libcfsecxsd_la_HEADERS=xsd/cfsec-structured.xsd

libcfsecsaxloaderdir=${libdir}

libcfsecsaxloader_LTLIBRARIES=libcfsecsaxloader.la

libcfsecsaxloader_ladir=

libcfsecsaxloader_la_COREdir=$(prefix)/include/msscf/$(MAJOR_VERSION).0.$(MINOR_VERSION)/cfsecsaxloader

libcfsecsaxloader_la_SOURCES= CFSecSaxLoader.cpp CFSecSaxLoaderPublic.cpp CFSecSaxLdr.cpp CFSecSaxLoaderClusterHandler.cpp CFSecSaxLoaderHostNodeHandler.cpp CFSecSaxLoaderISOCcyHandler.cpp CFSecSaxLoaderISOCtryHandler.cpp CFSecSaxLoaderISOCtryCcyHandler.cpp CFSecSaxLoaderISOCtryLangHandler.cpp CFSecSaxLoaderISOLangHandler.cpp CFSecSaxLoaderISOTZoneHandler.cpp CFSecSaxLoaderSecAppHandler.cpp CFSecSaxLoaderSecDeviceHandler.cpp CFSecSaxLoaderSecFormHandler.cpp CFSecSaxLoaderSecGroupHandler.cpp CFSecSaxLoaderSecGroupFormHandler.cpp CFSecSaxLoaderSecGrpIncHandler.cpp CFSecSaxLoaderSecGrpMembHandler.cpp CFSecSaxLoaderSecSessionHandler.cpp CFSecSaxLoaderSecUserHandler.cpp CFSecSaxLoaderServiceHandler.cpp CFSecSaxLoaderServiceTypeHandler.cpp CFSecSaxLoaderSysClusterHandler.cpp CFSecSaxLoaderTSecGroupHandler.cpp CFSecSaxLoaderTSecGrpIncHandler.cpp CFSecSaxLoaderTSecGrpMembHandler.cpp CFSecSaxLoaderTenantHandler.cpp

libcfsecsaxloader_la_CORE_HEADERS= cfsecsaxloader/CFSecSaxLoader.hpp cfsecsaxloader/CFSecSaxLoaderPublic.hpp cfsecsaxloader/CFSecSaxLdr.hpp cfsecsaxloader/CFSecSaxLoaderClusterHandler.hpp cfsecsaxloader/CFSecSaxLoaderHostNodeHandler.hpp cfsecsaxloader/CFSecSaxLoaderISOCcyHandler.hpp cfsecsaxloader/CFSecSaxLoaderISOCtryHandler.hpp cfsecsaxloader/CFSecSaxLoaderISOCtryCcyHandler.hpp cfsecsaxloader/CFSecSaxLoaderISOCtryLangHandler.hpp cfsecsaxloader/CFSecSaxLoaderISOLangHandler.hpp cfsecsaxloader/CFSecSaxLoaderISOTZoneHandler.hpp cfsecsaxloader/CFSecSaxLoaderSecAppHandler.hpp cfsecsaxloader/CFSecSaxLoaderSecDeviceHandler.hpp cfsecsaxloader/CFSecSaxLoaderSecFormHandler.hpp cfsecsaxloader/CFSecSaxLoaderSecGroupHandler.hpp cfsecsaxloader/CFSecSaxLoaderSecGroupFormHandler.hpp cfsecsaxloader/CFSecSaxLoaderSecGrpIncHandler.hpp cfsecsaxloader/CFSecSaxLoaderSecGrpMembHandler.hpp cfsecsaxloader/CFSecSaxLoaderSecSessionHandler.hpp cfsecsaxloader/CFSecSaxLoaderSecUserHandler.hpp cfsecsaxloader/CFSecSaxLoaderServiceHandler.hpp cfsecsaxloader/CFSecSaxLoaderServiceTypeHandler.hpp cfsecsaxloader/CFSecSaxLoaderSysClusterHandler.hpp cfsecsaxloader/CFSecSaxLoaderTSecGroupHandler.hpp cfsecsaxloader/CFSecSaxLoaderTSecGrpIncHandler.hpp cfsecsaxloader/CFSecSaxLoaderTSecGrpMembHandler.hpp cfsecsaxloader/CFSecSaxLoaderTenantHandler.hpp

libcfsecsaxloader_la_HEADERS=

libcfsecsaxloader_la_LDFLAGS= -version-info $(MAJOR_VERSION):$(MINOR_VERSION) -lmpfr -lxerces-c -luuid -l:libcflib.so.$(MAJOR_VERSION).0.$(MINOR_VERSION) -l:libcfsec.so.$(MAJOR_VERSION).0.$(MINOR_VERSION) -lstdc++fs

libcfsecsaxloader_la_CXXFLAGS= -I$(top_srcdir) -I$(prefix)/include/msscf/$(MAJOR_VERSION).0.$(MINOR_VERSION) -I$(prefix)/include/msscf/$(MAJOR_VERSION).0.$(MINOR_VERSION)

ACLOCAL_AMFLAGS= -Im4
