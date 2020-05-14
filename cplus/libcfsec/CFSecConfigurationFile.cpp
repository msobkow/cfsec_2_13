// Description: C++18 configuration file implementation for a CFSec schema.

/*
 *	com.github.msobkow.CFSec
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	This file is part of MSS Code Factory.
 *	
 *	Licensed under the Apache License, Version 2.0 (the "License");
 *	you may not use this file except in compliance with the License.
 *	You may obtain a copy of the License at
 *	
 *	    http://www.apache.org/licenses/LICENSE-2.0
 *	
 *	Unless required by applicable law or agreed to in writing, software
 *	distributed under the License is distributed on an "AS IS" BASIS,
 *	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *	See the License for the specific language governing permissions and
 *	limitations under the License.
 *	
 *	Donations to support MSS Code Factory can be made at
 *	https://www.paypal.com/paypalme2/MarkSobkow
 *
 *	Manufactured by MSS Code Factory 2.12
 */

#include <fstream>
#include <cflib/ICFLibPublic.hpp>

using namespace std;

#include <cfsec/CFSecConfigurationFile.hpp>

namespace cfsec {

	const std::string CFSecConfigurationFile::CLASS_NAME( "CFSecConfigurationFile" );
	const std::string CFSecConfigurationFile::S_DBSERVER( "DbServer" );
	const std::string CFSecConfigurationFile::S_DBPORT( "DbPort" );
	const std::string CFSecConfigurationFile::S_DBDATABASE( "DbDatabase" );
	const std::string CFSecConfigurationFile::S_DBUSERNAME( "DbUserName" );
	const std::string CFSecConfigurationFile::S_DBPASSWORD( "DbPassword" );

	CFSecConfigurationFile::CFSecConfigurationFile() {
		fileName = NULL;
		dbServer = NULL;
		dbPort = -1;
		dbDatabase = NULL;
		dbUserName = NULL;
		dbPassword = NULL;
	}

	CFSecConfigurationFile::~CFSecConfigurationFile() {
		if( fileName != NULL ) {
			delete fileName;
			fileName = NULL;
		}
		if( dbServer != NULL ) {
			delete dbServer;
			dbServer = NULL;
		}
		if( dbDatabase != NULL ) {
			delete dbDatabase;
			dbDatabase = NULL;
		}
		if( dbUserName != NULL ) {
			delete dbUserName;
			dbUserName = NULL;
		}
		if( dbPassword != NULL ) {
			delete dbPassword;
			dbPassword = NULL;
		}
	}

	std::string* CFSecConfigurationFile::getFileName() const {
		return( fileName );
	}

	void CFSecConfigurationFile::setFileName( const std::string& value ) {
		if( fileName != NULL ) {
			delete fileName;
			fileName = NULL;
		}
		fileName = new std::string( value );
	}

	std::string* CFSecConfigurationFile::getDbServer() const {
		return( dbServer );
	}

	void CFSecConfigurationFile::setDbServer( const std::string& value ) {
		if( dbServer != NULL ) {
			delete dbServer;
			dbServer = NULL;
		}

		dbServer = new std::string( value );
	}

	int32_t CFSecConfigurationFile::getDbPort() const {
		return( dbPort );
	}

	void CFSecConfigurationFile::setDbPort( int32_t value ) {
		dbPort = value;
	}

	std::string* CFSecConfigurationFile::getDbDatabase() const {
		return( dbDatabase );
	}

	void CFSecConfigurationFile::setDbDatabase( const std::string& value ) {
		if( dbDatabase != NULL ) {
			delete dbDatabase;
			dbDatabase = NULL;
		}
		dbDatabase = new std::string( value );
	}

	std::string* CFSecConfigurationFile::getDbUserName() const {
		return( dbUserName );
	}

	void CFSecConfigurationFile::setDbUserName( const std::string& value ) {
		if( dbUserName != NULL ) {
			delete dbUserName;
			dbUserName = NULL;
		}
		dbUserName = new std::string( value );
	}

	std::string* CFSecConfigurationFile::getDbPassword() const {
		return( dbPassword );
	}

	void CFSecConfigurationFile::setDbPassword( const std::string& value ) {
		if( dbPassword != NULL ) {
			delete dbPassword;
			dbPassword = NULL;
		}
		dbPassword = new std::string( value );
	}

	bool CFSecConfigurationFile::load() {
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

		std::string line;
		std::string::size_type posEquals;
		std::string tag;
		std::string value;
		int32_t* iValue;

		while( getline( file, line ) ) {
			if( line.length() > 0 ) {
				if( line.at( 0 ) != '#' ) {
					posEquals = line.find( '=' );
					if( posEquals <= 0 ) {
						return( false );
					}
					tag = line.substr( 0, posEquals - 1 );
					value = line.substr( posEquals + 1 );
					if( tag == S_DBSERVER ) {
						setDbServer( value );
					}
					else if( tag == S_DBPORT ) {
						iValue = cflib::CFLibXmlUtil::parseInt32( value );
						if( iValue != NULL ) {
							setDbPort( *iValue );
							delete iValue;
							iValue = NULL;
						}
					}
					else if( tag == S_DBDATABASE ) {
						setDbDatabase( value );
					}
					else if( tag == S_DBUSERNAME ) {
						setDbUserName( value );
					}
					else if( tag == S_DBPASSWORD ) {
						setDbPassword( value );
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

		if( ( dbServer == NULL ) || ( dbPort <= 0 ) || ( dbDatabase == NULL ) || ( dbUserName == NULL ) || ( dbPassword == NULL ) ) {
			throw cflib::CFLibRuntimeException( CLASS_NAME,
				S_ProcName,
				S_MissingTags );
		}

		return( true );
	}

	bool CFSecConfigurationFile::save() const {
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

		if( ( dbServer == NULL ) || ( dbPort <= 0 ) || ( dbDatabase == NULL ) || ( dbUserName == NULL ) || ( dbPassword == NULL ) ) {
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
		line.append( S_DBPORT );
		line.append( S_Equal );
		line.append( cflib::CFLibXmlUtil::formatInt32( dbPort ) );
		line.append( S_Newline );
		file.write( line.data(), line.length() );

		line.clear();
		line.append( S_DBPASSWORD );
		line.append( S_Equal );
		line.append( *dbPassword );
		line.append( S_Newline );
		file.write( line.data(), line.length() );

		line.clear();
		line.append( S_DBSERVER );
		line.append( S_Equal );
		line.append( *dbServer );
		line.append( S_Newline );
		file.write( line.data(), line.length() );

		line.clear();
		line.append( S_DBUSERNAME );
		line.append( S_Equal );
		line.append( *dbUserName );
		line.append( S_Newline );
		file.write( line.data(), line.length() );

		line.clear();
		line.append( S_DBDATABASE );
		line.append( S_Equal );
		line.append( *dbDatabase );
		line.append( S_Newline );
		file.write( line.data(), line.length() );

		file.close();

		return( true );
	}

}
