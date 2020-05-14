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
MAJOR_VERSION=2
MINOR_VERSION=13
pushd libcfsec
	sudo make install
	sudo chmod 755 /usr/include/msobkow
	sudo chmod 755 /usr/include/msobkow/${MAJOR_VERSION}.0.${MINOR_VERSION}
	sudo chmod 755 /usr/include/msobkow/${MAJOR_VERSION}.0.${MINOR_VERSION}/cfsec
	sudo sh -c "cd /usr/include/msobkow/${MAJOR_VERSION}.0.${MINOR_VERSION}/cfsec && chmod 644 *.hpp"
	sudo chmod 755 /usr/include/msobkow/${MAJOR_VERSION}.0.${MINOR_VERSION}/cfsecobj
	sudo sh -c "cd /usr/include/msobkow/${MAJOR_VERSION}.0.${MINOR_VERSION}/cfsecobj && chmod 644 *.hpp"
	#sudo chmod 755 /usr/bin/*cfsec*
	sudo chmod 755 /usr/lib/*cfsec.la
	sudo chmod 755 /usr/lib/*cfsec.so*
	sudo chmod 755 /usr/share/msobkow
	sudo chmod 755 /usr/share/msobkow/${MAJOR_VERSION}.0.${MINOR_VERSION}
	sudo chmod 755 /usr/share/msobkow/${MAJOR_VERSION}.0.${MINOR_VERSION}/xsd
	sudo chmod 644 /usr/share/msobkow/${MAJOR_VERSION}.0.${MINOR_VERSION}/xsd/*cfsec*.xsd
	sudo ldconfig
popd