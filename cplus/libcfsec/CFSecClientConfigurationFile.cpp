// Description: C++18 client configuration file implementation for a CFSec schema.

/*
 *	org.msscf.msscf.CFSec
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFSec 2.13 Security Essentials
 *	
 *	Copyright 2020 Mark Stephen Sobkow
 *	
 *		This file is part of MSS Code Factory.
 *	
 *		MSS Code Factory is available under dual commercial license from Mark Stephen
 *		Sobkow, or under the terms of the GNU General Public License, Version 3
 *		or later.
 *	
 *	    MSS Code Factory is free software: you can redistribute it and/or modify
 *	    it under the terms of the GNU General Public License as published by
 *	    the Free Software Foundation, either version 3 of the License, or
 *	    (at your option) any later version.
 *	
 *	    MSS Code Factory is distributed in the hope that it will be useful,
 *	    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	    GNU General Public License for more details.
 *	
 *	    You should have received a copy of the GNU General Public License
 *	    along with MSS Code Factory.  If not, see <https://www.gnu.org/licenses/>.
 *	
 *	Donations to support MSS Code Factory can be made at
 *	https://www.paypal.com/paypalme2/MarkSobkow
 *	
 *	Please contact Mark Stephen Sobkow at msobkow@sasktel.net for commercial licensing.
 *
 *	Manufactured by MSS Code Factory 2.12
 */

#include <fstream>
#include <cflib/ICFLibPublic.hpp>

using namespace std;

#include <cfsec/CFSecClientConfigurationFile.hpp>

namespace cfsec {

	const std::string CFSecClientConfigurationFile::CLASS_NAME( "CFSecClientConfigurationFile" );
	const std::string CFSecClientConfigurationFile::S_KEYSTORE( "KeyStore" );
	const std::string CFSecClientConfigurationFile::S_DEVICENAME( "DeviceName" );
	const std::string CFSecClientConfigurationFile::S_SERVERURLPREFIX( "ServerURL" );

	CFSecClientConfigurationFile::CFSecClientConfigurationFile() {
		fileName = NULL;
		keyStore = NULL;
		deviceName = NULL;
		serverURLUsed = 0;
		int32_t i;
		for( i = 0; i < 20; i++ ) {
			serverURL[i] = NULL;
		}
	}

	CFSecClientConfigurationFile::~CFSecClientConfigurationFile() {
		if( fileName != NULL ) {
			delete fileName;
			fileName = NULL;
		}
		if( keyStore != NULL ) {
			delete keyStore;
			keyStore = NULL;
		}
		if( deviceName != NULL ) {
			delete deviceName;
			deviceName = NULL;
		}
		int32_t i;
		for( i = 0; i < 20; i++ ) {
			if( serverURL[i] != NULL ) {
				delete serverURL[i];
				serverURL[i] = NULL;
			}
		}
	}

	std::string* CFSecClientConfigurationFile::getFileName() const {
		return( fileName );
	}

	void CFSecClientConfigurationFile::setFileName( const std::string& value ) {
		if( fileName != NULL ) {
			delete fileName;
			fileName = NULL;
		}
		fileName = new std::string( value );
	}

	std::string* CFSecClientConfigurationFile::getKeyStore() const {
		return( keyStore );
	}

	void CFSecClientConfigurationFile::setKeyStore( const std::string& value ) {
		if( keyStore != NULL ) {
			delete keyStore;
			keyStore = NULL;
		}

		keyStore = new std::string( value );
	}

	std::string* CFSecClientConfigurationFile::getDeviceName() const {
		return( deviceName );
	}

	void CFSecClientConfigurationFile::setDeviceName( const std::string& value ) {
		if( deviceName != NULL ) {
			delete deviceName;
			deviceName = NULL;
		}
		deviceName = new std::string( value );
	}

	const std::string* CFSecClientConfigurationFile::getLatestServerURL() const {
		const std::string* retval;
		if( serverURLUsed > 0 ) {
			retval = serverURL[0];
		}
		else {
			retval = NULL;
		}
		return( retval );
	}

	int32_t CFSecClientConfigurationFile::getServerURLUsed() const {
		return( serverURLUsed );
	}

	std::string** CFSecClientConfigurationFile::getServerURLArray() {
		return( serverURL );
	}

	void CFSecClientConfigurationFile::setLatestServerURL( const std::string& value ) {
		static const std::string S_ProcName( "setLatestServerURL" );
		static const std::string S_Value( "value" );
		if( value.length() <= 0 ) {
			throw cflib::CFLibEmptyArgumentException( CLASS_NAME,
				S_ProcName,
				1,
				S_Value );
		}
		std::string* workset[20];
		int32_t i;
		for( i = 0; i < 20; i++ ) {
			workset[i] = NULL;
		}
		size_t idx;
		workset[0] = new std::string( value );
		idx = 1;
		for( i = 0; i < serverURLUsed; i++ ) {
			if( *serverURL[i] == value ) {
				delete serverURL[i];
				serverURL[i] = NULL;
			}
			else {
				if( idx < 20 - 1 ) {
					workset[idx++] = serverURL[i];
				}
				else {
					delete serverURL[i];
					serverURL[i] = NULL;
				}
			}
		}
		if( idx >= 20 ) {
			delete workset[idx];
			workset[idx] = NULL;
			idx --;
		}
		for( i = 0; i < 20; i++ ) {
			serverURL[i] = workset[i];
		}
		serverURL[20] = NULL;
		save();
	}

	bool CFSecClientConfigurationFile::load() {
		static const std::string S_ProcName( "load" );
		static const std::string S_FileName( "FileName" );
		static const std::string S_UnrecognizedTag( "Attribute tag not recognized" );
		static const std::string S_MissingTags( "One or more tags are missing" );

		if( ( fileName == NULL ) || ( fileName->length() <= 0 ) ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_FileName );
		}

		std::basic_ifstream<char> file;
		file.open( *fileName, std::_Ios_Openmode::_S_in );
		if( ! file.is_open() ) {
			return( false );
		}

		int32_t i;
		int32_t j;
		std::string line;
		std::string::size_type posEquals;
		std::string tag;
		std::string value;
		std::string digits;
		int32_t* iValue;
		for( i = 0; i < 20; i++ ) {
			if( serverURL[i] != NULL ) {
				delete serverURL[i];
				serverURL[i] = NULL;
			}
		}
		serverURLUsed = 0;

		while( getline( file, line ) ) {
			if( line.length() > 0 ) {
				if( line.at( 0 ) != '#' ) {
					posEquals = line.find( '=' );
					if( posEquals <= 0 ) {
						return( false );
					}
					tag = line.substr( 0, posEquals - 1 );
					value = line.substr( posEquals + 1 );
					if( tag == S_DEVICENAME ) {
						setDeviceName( value );
					}
					else if( tag == S_KEYSTORE ) {
						setKeyStore( value );
					}
					else if( ( tag.length() > S_SERVERURLPREFIX.length() ) && ( S_SERVERURLPREFIX == tag.substr( 0, S_SERVERURLPREFIX.length() ) ) ) {
						digits = value.substr( S_SERVERURLPREFIX.length() );
						iValue = cflib::CFLibXmlUtil::parseInt32( digits );
						if( iValue != NULL ) {
							if( ( *iValue >= 0 ) && ( *iValue < 20 ) ) {
								if( serverURL[*iValue] != NULL ) {
									delete serverURL[*iValue];
									serverURL[*iValue] = NULL;
								}
								serverURL[*iValue] = new std::string( value );
							}
							delete iValue;
							iValue = NULL;
						}
					}
					else {
						file.close();
						throw cflib::CFLibRuntimeException( CLASS_NAME,
							S_ProcName,
							S_UnrecognizedTag );
					}
				}
			}
		}

		file.close();

		if( ( deviceName == NULL ) || ( keyStore == NULL ) ) {
			throw cflib::CFLibRuntimeException( CLASS_NAME,
				S_ProcName,
				S_MissingTags );
		}

		for( i = 0; i < 20; i++ ) {
			if( serverURL[i] != NULL ) {
				serverURLUsed = i + 1;
			}
			else {
				while( serverURL[i] == NULL ) {
					for( j = i + 1; j < 20; j++ ) {
						if( serverURL[j] != NULL ) {
							break;
						}
					}
					if( j < 20 ) {
						for( j = i; j < 20 - 1; j++ ) {
							serverURL[j] = serverURL[j+1];
						}
					}
					else {
						break;
					}
					if( serverURL[i] != NULL ) {
						serverURLUsed = i + 1;
					}
				}
			}
		}

		return( true );
	}

	bool CFSecClientConfigurationFile::save() const {
		static const std::string S_ProcName( "save" );
		static const std::string S_FileName( "FileName" );
		static const std::string S_Equal( "=" );
		static const std::string S_Newline( "\n" );
		static const std::string S_MissingAttributes( "One or more attributes have not been set" );

		if( ( fileName == NULL ) || ( fileName->length() <= 0 ) ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_FileName );
		}

		if( ( deviceName == NULL ) || ( keyStore == NULL ) ) {
			throw cflib::CFLibRuntimeException( CLASS_NAME,
				S_ProcName,
				S_MissingAttributes );
		}

		std::basic_ofstream<char> file;
		file.open( *fileName, std::_Ios_Openmode::_S_trunc );
		if( ! file.is_open() ) {
			return( false );
		}

		std::string line;
		std::chrono::system_clock::time_point timestamp = cflib::CFLib::getUTCTimestampInstance();

		line.append( "# " );
		line.append( cflib::CFLibXmlUtil::formatTimestamp( timestamp ) );
		line.append( S_Newline );
		file.write( line.data(), line.length() );

		line.clear();
		line.append( S_DEVICENAME );
		line.append( S_Equal );
		line.append( *deviceName );
		line.append( S_Newline );
		file.write( line.data(), line.length() );

		line.clear();
		line.append( S_KEYSTORE);
		line.append( S_Equal );
		line.append( *keyStore );
		line.append( S_Newline );
		file.write( line.data(), line.length() );

		int32_t i;
		for( i = 0; i < serverURLUsed; i++ ) {
			line.clear();
			line.append( S_SERVERURLPREFIX );
			line.append( cflib::CFLibXmlUtil::formatInt32( i ) );
			line.append( S_Equal );
			line.append( *serverURL[i] );
			line.append( S_Newline );
			file.write( line.data(), line.length() );
		}

		file.close();

		return( true );
	}

}
