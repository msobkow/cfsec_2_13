#!/bin/bash
Revision=$1
if [ "$Revision" == "" ]; then
	echo "ERROR: Revision (argument 1) not specified" 1>&2
else
	export Revision
	cd $MSSCFHOME/cfsec_2_13/cplus
	if [ ! -d ../installer ]; then
		mkdir ../installer
	fi
	chmod 755 ../installer
	ZipFile="../installer/cfsec_2_13_${Revision}-wsl-debug-installer.zip"
	export ZipFile
	rm -f ${ZipFile}
	rm -Rf cfsec-2.13.${Revision}-wsl
	mkdir cfsec-2.13.${Revision}-wsl
	chmod 755 cfsec-2.13.${Revision}-wsl
	echo "Preparing cfsec-2.13.${Revision}-wsl ..."
	pushd cfsec-2.13.${Revision}-wsl
		cp ../Apache-V2.txt ../LICENSE .
		git log 2>&1 >ChangeLog
		mkdir bin
		chmod 755 bin
		mkdir bin/msobkow
		chmod 755 bin/msobkow
		mkdir bin/msobkow/2.0.13
		chmod 755 bin/msobkow/2.0.13
		cp ../Apache-V2.txt ../LICENSE bin/msobkow/2.0.13
		chmod 644 bin/msobkow/2.0.13/*
		cp /usr/bin/msobkow/2.0.13/cfsec* bin/msobkow/2.0.13
		chmod 755 bin/msobkow/2.0.13/cfsec*
		mkdir lib
		chmod 755 lib
		cp /usr/lib/libcfsec.la /usr/lib/libcfsec.so.2.0.13 lib
		cp /usr/lib/libcfsecsaxloader.la /usr/lib/libcfsecsaxloader.so.2.0.13 lib
		cp /usr/lib/libcfsecram.la /usr/lib/libcfsecram.so.2.0.13 lib
		chmod 755 lib/*.so.*
		chmod 644 lib/*.la
		strip bin/msobkow/2.0.13/*cf* lib/*.so.*
		mkdir include
		chmod 755 include
		mkdir include/msobkow
		chmod 755 include/msobkow
		mkdir include/msobkow/2.0.13
		chmod 755 include/msobkow/2.0.13
		cp ../Apache-V2.txt ../LICENSE include/msobkow/2.0.13
		chmod 644 include/msobkow/2.0.13/*
		mkdir include/msobkow/2.0.13/cfsec
		chmod 755 include/msobkow/2.0.13/cfsec
		cp /usr/include/msobkow/2.0.13/cfsec/*.hpp include/msobkow/2.0.13/cfsec
		chmod 644 include/msobkow/2.0.13/cfsec*/*.hpp
		mkdir include/msobkow/2.0.13/cfsecsaxloader
		chmod 755 include/msobkow/2.0.13/cfsecsaxloader
		cp /usr/include/msobkow/2.0.13/cfsecsaxloader/*.hpp include/msobkow/2.0.13/cfsecsaxloader
		chmod 644 include/msobkow/2.0.13/cfsecsaxloader*/*.hpp
		mkdir include/msobkow/2.0.13/cfsecram
		chmod 755 include/msobkow/2.0.13/cfsecram
		cp /usr/include/msobkow/2.0.13/cfsecram/*.hpp include/msobkow/2.0.13/cfsecram
		chmod 644 include/msobkow/2.0.13/cfsecram*/*.hpp
		mkdir share
		chmod 755 share
		mkdir share/msobkow
		chmod 755 share/msobkow
		mkdir share/msobkow/2.0.13
		chmod 755 share/msobkow/2.0.13
		cp ../Apache-V2.txt ../LICENSE share/msobkow/2.0.13
		chmod 644 share/msobkow/2.0.13/*
		mkdir share/msobkow/2.0.13/xsd
		chmod 755 share/msobkow/2.0.13/xsd
		cp /usr/share/msobkow/2.0.13/xsd/cfsec*.xsd share/msobkow/2.0.13/xsd
		chmod 644 share/msobkow/2.0.13/xsd/*.xsd
	popd
	echo "Packaging cfsec-2.13.${Revision}-wsl ..."
	zip -q9r ${ZipFile} cfsec-2.13.${Revision}-wsl
	rm -Rf cfsec-2.13.${Revision}-wsl
	echo "Packaged ${ZipFile}"
	ls -l ${ZipFile}
fi
