#!/bin/bash
#
#	org.msscf.msscf.CFSec
#
#	Copyright (c) 2020 Mark Stephen Sobkow
#	
#	MSS Code Factory CFSec 2.13 Security Essentials
#	
#	Copyright 2020 Mark Stephen Sobkow
#	
#		This file is part of MSS Code Factory.
#	
#		MSS Code Factory is available under dual commercial license from Mark Stephen
#		Sobkow, or under the terms of the GNU General Public License, Version 3
#		or later.
#	
#	    MSS Code Factory is free software: you can redistribute it and/or modify
#	    it under the terms of the GNU General Public License as published by
#	    the Free Software Foundation, either version 3 of the License, or
#	    (at your option) any later version.
#	
#	    MSS Code Factory is distributed in the hope that it will be useful,
#	    but WITHOUT ANY WARRANTY; without even the implied warranty of
#	    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#	    GNU General Public License for more details.
#	
#	    You should have received a copy of the GNU General Public License
#	    along with MSS Code Factory.  If not, see <https://www.gnu.org/licenses/>.
#	
#	Donations to support MSS Code Factory can be made at
#	https://www.paypal.com/paypalme2/MarkSobkow
#	
#	Please contact Mark Stephen Sobkow at msobkow@sasktel.net for commercial licensing.
#
#	Manufactured by MSS Code Factory 2.12
#
MAJOR_VERSION=2
MINOR_VERSION=13
pushd libcfsecsaxloader
	sudo make install
	sudo chmod 755 /usr/include/msscf
	sudo chmod 755 /usr/include/msscf/${MAJOR_VERSION}.0.${MINOR_VERSION}
	sudo chmod 755 /usr/include/msscf/${MAJOR_VERSION}.0.${MINOR_VERSION}/cfsecsaxloader
	sudo sh -c "cd /usr/include/msscf/${MAJOR_VERSION}.0.${MINOR_VERSION}/cfsecsaxloader && chmod 644 *.hpp"
	#sudo chmod 755 /usr/bin/*cfsec*saxloader
	sudo chmod 755 /usr/lib/*cfsecsaxloader.la
	sudo chmod 755 /usr/lib/*cfsecsaxloader.so*
	sudo chmod 755 /opt/msscf
	sudo chmod 755 /opt/msscf/${MAJOR_VERSION}.0.${MINOR_VERSION}
	sudo chmod 755 /opt/msscf/${MAJOR_VERSION}.0.${MINOR_VERSION}/xsd
	sudo chmod 644 /opt/msscf/${MAJOR_VERSION}.0.${MINOR_VERSION}/xsd/*cfsec*.xsd
	sudo ldconfig
popd
