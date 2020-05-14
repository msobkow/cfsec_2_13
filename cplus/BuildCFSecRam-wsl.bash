#!/bin/bash
#
#	com.github.msobkow.CFSec
#
#	Copyright (c) 2020 Mark Stephen Sobkow
#	
#	This file is part of MSS Code Factory.
#	
#	Licensed under the Apache License, Version 2.0 (the "License");
#	you may not use this file except in compliance with the License.
#	You may obtain a copy of the License at
#	
#	    http://www.apache.org/licenses/LICENSE-2.0
#	
#	Unless required by applicable law or agreed to in writing, software
#	distributed under the License is distributed on an "AS IS" BASIS,
#	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#	See the License for the specific language governing permissions and
#	limitations under the License.
#	
#	Donations to support MSS Code Factory can be made at
#	https://www.paypal.com/paypalme2/MarkSobkow
#
#	Manufactured by MSS Code Factory 2.12
#
Revision=$1
MAJOR_VERSION=2
MINOR_VERSION=13
rm -f libcfsecram*.gz *.deb *.build *.dsc *.log *.changes ex.cmd
pushd libcfsecram
	if [ -f Makefile ]; then
		make distclean
	fi
popd
pushd libcfsecram
	if [ ! -d /usr/bin/msobkow ]; then
		sudo mkdir /usr/include/msobkow
	fi
	sudo chmod 755 /usr/bin/msobkow
	if [ ! -d /usr/bin/msobkow/${MAJOR_VERSION}.0.${MINOR_VERSION} ]; then
		sudo mkdir /usr/include/msobkow/${MAJOR_VERSION}.0.${MINOR_VERSION}
	fi
	sudo chmod 755 /usr/bin/msobkow/${MAJOR_VERSION}.0.${MINOR_VERSION}
	if [ ! -d /usr/include/msobkow ]; then
		sudo mkdir /usr/include/msobkow
	fi
	sudo chmod 755 /usr/include/msobkow
	if [ ! -d /usr/include/msobkow/${MAJOR_VERSION}.0.${MINOR_VERSION} ]; then
		sudo mkdir /usr/include/msobkow/${MAJOR_VERSION}.0.${MINOR_VERSION}
	fi
	sudo chmod 755 /usr/include/msobkow/${MAJOR_VERSION}.0.${MINOR_VERSION}
	if [ ! -d /usr/include/msobkow/${MAJOR_VERSION}.0.${MINOR_VERSION}/cfsecram ]; then
		sudo mkdir /usr/include/msobkow/${MAJOR_VERSION}.0.${MINOR_VERSION}/cfsecram
	fi
	sudo chmod 755 /usr/include/msobkow/${MAJOR_VERSION}.0.${MINOR_VERSION}/cfsecram
	autoreconf -fi
	aclocal
	autoconf
	automake
	./configure --prefix=/usr --disable-static CFLAGS='-g3 -Og -D_DEBUG' CXXFLAGS='-g3 -Og -D_DEBUG -std=c++2a -I/usr/include/msobkow/${MAJOR_VERSION).0.${MINOR_VERSION} -I/usr/include/msobkow/${MAJOR_VERSION).0.${MINOR_VERSION} '
	#./configure --prefix=/usr --disable-static CFLAGS='-O2 -DNDEBUG' CXXFLAGS='-O2 -DNDEBUG -std=c++2a -I/usr/include/msobkow/${MAJOR_VERSION).0.${MINOR_VERSION} -I/usr/include/msobkow/${MAJOR_VERSION).0.${MINOR_VERSION} '
	make clean
	time make
	sudo make install
	sudo rm -Rf /usr/include/cfsec*
	sudo chmod 755 /usr/include/msobkow
	sudo chmod 755 /usr/include/msobkow/${MAJOR_VERSION}.0.${MINOR_VERSION}
	sudo chmod 755 /usr/include/msobkow/${MAJOR_VERSION}.0.${MINOR_VERSION}/cfsecram
	sudo sh -c "cd /usr/include/msobkow/${MAJOR_VERSION}.0.${MINOR_VERSION}/cfsecram && chmod 644 *.hpp"
	#sudo chmod 755 /usr/bin/*cfsec*ram
	sudo chmod 755 /usr/lib/*cfsecram.la
	sudo chmod 755 /usr/lib/*cfsecram.so*
	sudo chmod 755 /usr/share/msobkow
	sudo chmod 755 /usr/share/msobkow/${MAJOR_VERSION}.0.${MINOR_VERSION}
	sudo ldconfig
popd
