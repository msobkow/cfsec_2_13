// Description: C++18 XML Command Line Interface common core implementation for CFSec.

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
#include <cflib/ICFLibPublic.hpp>
#include <cfsec/ICFSecPublic.hpp>
#include <cfsecobj/ICFSecObjPublic.hpp>

#include <cfsecsaxloader/CFSecSaxLoader.hpp>
#include <cfsecsaxloader/CFSecSaxLdr.hpp>

namespace cfsec {

	const std::string CFSecSaxLdr::CLASS_NAME( "CFSecSaxLdr" );
	const std::string CFSecSaxLdr::S_SYSTEM( "system" );
	const std::string CFSecSaxLdr::S_UnhandledException( "Unhandled exception" );

	CFSecSaxLdr::CFSecSaxLdr() {
		log = NULL;
		saxLoader = NULL;
		clusterName = new std::string( S_SYSTEM );
		clusterObj = NULL;
		tenantName = new std::string( S_SYSTEM );
		tenantObj = NULL;
		secUserName = new std::string( S_SYSTEM );
		secUserObj = NULL;
		secSessionObj = NULL;
	}

	CFSecSaxLdr::~CFSecSaxLdr() {
		if( saxLoader != NULL ) {
			delete saxLoader;
			saxLoader = NULL;
		}
		if( clusterName != NULL ) {
			delete clusterName;
			clusterName = NULL;
		}
		if( tenantName != NULL ) {
			delete tenantName;
			tenantName = NULL;
		}
		if( secUserName != NULL ) {
			delete secUserName;
			secUserName = NULL;
		}
		clusterObj = NULL;
		tenantObj = NULL;
		secUserObj = NULL;
		secSessionObj = NULL;
	}

	CFSecSaxLdr::CFSecSaxLdr( cflib::ICFLibMessageLog* messageLog ) {
		log = messageLog;
		saxLoader = NULL;
		clusterName = new std::string( S_SYSTEM );
		clusterObj = NULL;
		tenantName = new std::string( S_SYSTEM );
		tenantObj = NULL;
		secUserName = new std::string( S_SYSTEM );
		secUserObj = NULL;
		secSessionObj = NULL;
		getSaxLoader();
	}

	void CFSecSaxLdr::setSaxLoader( cfsec::CFSecSaxLoader* value ) {
		saxLoader = value;
	}

	cfsec::CFSecSaxLoader* CFSecSaxLdr::getSaxLoader() {
		static const std::string S_ProcName( "getSaxLoader" );
		static const std::string S_Log( "log" );
		if( log == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_Log );
		}
		if( saxLoader == NULL ) {
			saxLoader = new CFSecSaxLoader( log );
		}
		return( saxLoader );
	}

	void CFSecSaxLdr::setClusterName( const std::string& value ) {
		const static std::string S_ProcName( "setClusterName" );
		const static std::string S_Default( "default" );
		const static std::string S_System( "system" );
		const static std::string S_ReadClusterSystem( "readClusterByUDomName-system" );
		const static std::string S_ExpectedValues( "Expected value to by 'default' or 'system'" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecSchemaObj* schema = saxLoader->getSchemaObj();
		if( value == S_Default ) {
			bool transactionStarted = schema->beginTransaction();
			try {
				cfsec::ICFSecSysClusterObj* sysCluster = schema->getSysClusterTableObj()->readSysClusterByIdIdx( 1 );
				if( sysCluster == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						"sysCluster" );
				}
				cfsec::ICFSecClusterObj* useCluster = sysCluster->getRequiredContainerCluster();
				if( useCluster == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						"sysCluster->containerCluster" );
				}
				if( clusterName != NULL ) {
					delete clusterName;
					clusterName = NULL;
				}
				clusterName = new std::string( value );
				clusterObj = useCluster;
				saxLoader->getSchemaObj()->setSecCluster( useCluster );
				if( transactionStarted ) {
					schema->commit();
				}
			}
			CFLIB_EXCEPTION_CATCH_FALLTHROUGH
			if( ! CFLIB_EXCEPTION_EMPTY ) {
				if( transactionStarted ) {
					try {
						schema->rollback();
					}
					catch( ... ) {
					}
				}
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					S_UnhandledException );
			}
		}
		else if( value == S_System ) {
			bool transactionStarted = schema->beginTransaction();
			try {
				cfsec::ICFSecClusterObj* useCluster = schema->getClusterTableObj()->readClusterByUDomNameIdx( S_System );
				if( useCluster == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ReadClusterSystem );
				}
				if( clusterName != NULL ) {
					delete clusterName;
					clusterName = NULL;
				}
				clusterName = new std::string( value );
				clusterObj = useCluster;
				saxLoader->getSchemaObj()->setSecCluster( useCluster );
				if( transactionStarted ) {
					schema->commit();
				}
			}
			CFLIB_EXCEPTION_CATCH_FALLTHROUGH
			if( ! CFLIB_EXCEPTION_EMPTY ) {
				if( transactionStarted ) {
					try {
						schema->rollback();
					}
					catch( ... ) {
					}
				}
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					S_UnhandledException );
			}
		}
		else {
			throw cflib::CFLibUsageException( CLASS_NAME,
				S_ProcName,
				S_ExpectedValues );
		}
	}

	const std::string& CFSecSaxLdr::getClusterName() const {
		return( *clusterName );
	}

	cfsec::ICFSecClusterObj* CFSecSaxLdr::getClusterObj() {
		const static std::string S_ProcName( "getClusterObj" );
		const static std::string S_Default( "default" );
		const static std::string S_System( "system" );
		const static std::string S_SysCluster( "sysCluster" );
		const static std::string S_SysClusterContainingCluster( "sysCluster->containingCluster" );
		const static std::string S_ReadClusterSystem( "readClusterByUDomName-system" );
		const static std::string S_ClusterObj( "clusterObj" );
		CFLIB_EXCEPTION_DECLINFO
		if( clusterObj == NULL ) {
			cfsec::ICFSecSchemaObj* schema = saxLoader->getSchemaObj();
			if( *clusterName == S_Default ) {
				bool transactionStarted = schema->beginTransaction();
				try {
					cfsec::ICFSecSysClusterObj* sysCluster = schema->getSysClusterTableObj()->readSysClusterByIdIdx( 1 );
					if( sysCluster == NULL ) {
						throw cflib::CFLibNullArgumentException( CLASS_NAME,
							S_ProcName,
							0,
							S_SysCluster );
					}
					cfsec::ICFSecClusterObj* useCluster = sysCluster->getRequiredContainerCluster();
					if( useCluster == NULL ) {
						throw cflib::CFLibNullArgumentException( CLASS_NAME,
							S_ProcName,
							0,
							S_SysClusterContainingCluster );
					}
					clusterObj = useCluster;
					saxLoader->getSchemaObj()->setSecCluster( useCluster );
					if( transactionStarted ) {
						schema->commit();
					}
				}
				CFLIB_EXCEPTION_CATCH_FALLTHROUGH
				if( ! CFLIB_EXCEPTION_EMPTY ) {
					if( transactionStarted ) {
						try {
							schema->rollback();
						}
						catch( ... ) {
						}
					}
					throw cflib::CFLibRuntimeException( CLASS_NAME,
						S_ProcName,
						S_UnhandledException );
				}
			}
			else if( *clusterName == S_System ) {
				bool transactionStarted = schema->beginTransaction();
				try {
					cfsec::ICFSecClusterObj* useCluster = schema->getClusterTableObj()->readClusterByUDomNameIdx( S_System );
					if( useCluster == NULL ) {
						throw cflib::CFLibNullArgumentException( CLASS_NAME,
							S_ProcName,
							0,
							S_ReadClusterSystem );
					}
					clusterObj = useCluster;
					saxLoader->getSchemaObj()->setSecCluster( useCluster );
					if( transactionStarted ) {
						schema->commit();
					}
				}
				CFLIB_EXCEPTION_CATCH_FALLTHROUGH
				if( ! CFLIB_EXCEPTION_EMPTY ) {
					if( transactionStarted ) {
						try {
							schema->rollback();
						}
						catch( ... ) {
						}
					}
					throw cflib::CFLibRuntimeException( CLASS_NAME,
						S_ProcName,
						S_UnhandledException );
				}
			}
		}
		if( clusterObj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_ClusterObj );
		}
		return( clusterObj );
	}

	void CFSecSaxLdr::setTenantName( const std::string& value ) {
		const static std::string S_ProcName = "setTenantName";
		const static std::string S_System= "system";
		const static std::string S_Value = "value";
		const static std::string S_ClusterObj = "clusterObj";
		cfsec::ICFSecSchemaObj* schema = saxLoader->getSchemaObj();
		CFLIB_EXCEPTION_DECLINFO
		if( value == S_System ) {
			bool transactionStarted = schema->beginTransaction();
			try {
				cfsec::ICFSecTenantObj* useTenant = schema->getTenantTableObj()->readTenantByUNameIdx( clusterObj->getRequiredId(),
					S_System );
				if( useTenant == NULL ) {
					std::string Msg( "readTenantByUNameIdx-" + clusterObj->getObjName() + "-system" );
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						Msg );
				}
				if( tenantName != NULL ) {
					delete tenantName;
					tenantName = NULL;
				}
				tenantName = new std::string( value );
				tenantObj = useTenant;
				saxLoader->getSchemaObj()->setSecTenant( useTenant );
				if( transactionStarted ) {
					schema->commit();
				}
			}
			CFLIB_EXCEPTION_CATCH_FALLTHROUGH
			if( ! CFLIB_EXCEPTION_EMPTY ) {
				if( transactionStarted ) {
					try {
						schema->rollback();
					}
					catch( ... ) {
					}
				}
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					S_UnhandledException );
			}
		}
		else {
			if( clusterObj == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_ClusterObj );
			}
			if( *clusterName == S_System ) {
				std::string Msg( "Cluster 'system' only supports the tenant 'system', not '" + value + "'" );
				throw cflib::CFLibUsageException( CLASS_NAME,
					S_ProcName,
					Msg );
			}
			bool transactionStarted = schema->beginTransaction();
			try {
				cfsec::ICFSecTenantObj* useTenant = schema->getTenantTableObj()->readTenantByUNameIdx( clusterObj->getRequiredId(),
					value );
				if( useTenant == NULL ) {
					std::string Msg( "readTenantByUNameIdx-" + clusterObj->getObjName() + "-" + value );
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						Msg );
				}
				if( tenantName != NULL ) {
					delete tenantName;
					tenantName = NULL;
				}
				tenantName = new std::string( value );
				tenantObj = useTenant;
				saxLoader->getSchemaObj()->setSecTenant( useTenant );
				if( transactionStarted ) {
					schema->commit();
				}
			}
			CFLIB_EXCEPTION_CATCH_FALLTHROUGH
			if( ! CFLIB_EXCEPTION_EMPTY ) {
				if( transactionStarted ) {
					try {
						schema->rollback();
					}
					catch( ... ) {
					}
				}
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					S_UnhandledException );
			}
		}
	}

	const std::string& CFSecSaxLdr::getTenantName() const {
		return( *tenantName );
	}

	cfsec::ICFSecTenantObj* CFSecSaxLdr::getTenantObj() {
		const static std::string S_ProcName( "getTenantObj" );
		const static std::string S_System( "system" );
		const static std::string S_TenantName( "tenantName" );
		const static std::string S_ClusterObj( "clusterObj" );
		CFLIB_EXCEPTION_DECLINFO
		if( tenantObj == NULL ) {
			cfsec::ICFSecSchemaObj* schema = saxLoader->getSchemaObj();
			if( tenantName == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_TenantName );
			}
			else if( *tenantName == S_System ) {
				bool transactionStarted = schema->beginTransaction();
				try {
					cfsec::ICFSecTenantObj* useTenant = schema->getTenantTableObj()->readTenantByUNameIdx( clusterObj->getRequiredId(),
						S_System );
					if( useTenant == NULL ) {
						std::string Msg( "readTenantByUNameIdx-" + clusterObj->getObjName() + "-system" );
						throw cflib::CFLibNullArgumentException( CLASS_NAME,
							S_ProcName,
							0,
							Msg );
					}
					tenantObj = useTenant;
					saxLoader->getSchemaObj()->setSecTenant( useTenant );
					if( transactionStarted ) {
						schema->commit();
					}
				}
				CFLIB_EXCEPTION_CATCH_FALLTHROUGH
				if( ! CFLIB_EXCEPTION_EMPTY ) {
					if( transactionStarted ) {
						try {
							schema->rollback();
						}
						catch( ... ) {
						}
					}
					throw cflib::CFLibRuntimeException( CLASS_NAME,
						S_ProcName,
						S_UnhandledException );
				}
			}
			else {
				if( clusterObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ClusterObj );
				}
				if( *clusterName == S_System ) {
					std::string Msg( "Cluster 'system' only supports the tenant 'system', not '" + *tenantName + "'" );
					throw cflib::CFLibUsageException( CLASS_NAME,
						S_ProcName,
						Msg );
				}
				bool transactionStarted = schema->beginTransaction();
				try {
					cfsec::ICFSecTenantObj* useTenant = schema->getTenantTableObj()->readTenantByUNameIdx( clusterObj->getRequiredId(),
						*tenantName );
					if( useTenant == NULL ) {
						std::string Msg( "readTenantByUNameIdx-" + clusterObj->getObjName() + "-" + *tenantName );
						throw cflib::CFLibNullArgumentException( CLASS_NAME,
							S_ProcName,
							0,
							Msg );
					}
					tenantObj = useTenant;
					saxLoader->getSchemaObj()->setSecTenant( useTenant );
					if( transactionStarted ) {
						schema->commit();
					}
				}
				CFLIB_EXCEPTION_CATCH_FALLTHROUGH
				if( ! CFLIB_EXCEPTION_EMPTY ) {
					if( transactionStarted ) {
						try {
							schema->rollback();
						}
						catch( ... ) {
						}
					}
					throw cflib::CFLibRuntimeException( CLASS_NAME,
						S_ProcName,
						S_UnhandledException );
				}
			}
		}
		if( tenantObj == NULL ) {
			std::string Msg( "tenantObj-" + *tenantName );
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				Msg );
		}
		return( tenantObj );
	}

	void CFSecSaxLdr::setSecUserName( const std::string& value ) {
		if( secUserName != NULL ) {
			delete secUserName;
			secUserName = NULL;
		}
		secUserName = new std::string( value );
	}

	const std::string& CFSecSaxLdr::getSecUserName() const {
		return( *secUserName );
	}

	cfsec::ICFSecSecUserObj* CFSecSaxLdr::getSecUserObj() {
		static const std::string S_ProcName( "getSecUserObj" );
		CFLIB_EXCEPTION_DECLINFO
		if( secUserObj == NULL ) {
			ICFSecSchemaObj* schema = saxLoader->getSchemaObj();
			bool transactionStarted = schema->beginTransaction();
			try {
				secUserObj = schema->getSecUserTableObj()->readSecUserByULoginIdx( *secUserName );
				if( transactionStarted ) {
					schema->commit();
				}
			}
			CFLIB_EXCEPTION_CATCH_FALLTHROUGH
			if( ! CFLIB_EXCEPTION_EMPTY ) {
				if( transactionStarted ) {
					try {
						schema->rollback();
					}
					catch( ... ) {
					}
				}
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					S_UnhandledException );
			}
		}
		if( secUserObj == NULL ) {
			std::string Msg( "SecUser \"" + *secUserName + "\" could not be found" );
			throw cflib::CFLibRuntimeException( CLASS_NAME,
				S_ProcName,
				Msg );
		}
		return( secUserObj );
	}

	cfsec::ICFSecSecSessionObj* CFSecSaxLdr::getSecSessionObj() {
		static const std::string S_ProcName( "getSecSessionObj" );
		CFLIB_EXCEPTION_DECLINFO
		if( secSessionObj == NULL ) {
			cfsec::ICFSecSchemaObj* schema = saxLoader->getSchemaObj();
			bool transactionStarted = schema->beginTransaction();
			try {
				getClusterObj();
				getTenantObj();
				getSecUserObj();
				secSessionObj = schema->getSecSessionTableObj()->newInstance();
				cfsec::ICFSecSecSessionEditObj* sessionEdit = secSessionObj->beginEdit();
				sessionEdit->setRequiredContainerSecUser( secUserObj );
				std::chrono::system_clock::time_point curTimestamp = cflib::CFLib::getUTCTimestampInstance();
				sessionEdit->setRequiredStart( curTimestamp );
				sessionEdit->setOptionalFinishNull();
				secSessionObj = sessionEdit->create();
				if( transactionStarted ) {
					schema->commit();
				}
			}
			CFLIB_EXCEPTION_CATCH_FALLTHROUGH
			if( ! CFLIB_EXCEPTION_EMPTY ) {
				if( transactionStarted ) {
					try {
						schema->rollback();
					}
					catch( ... ) {
					}
				}
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					S_UnhandledException );
			}
		}
		return( secSessionObj );
	}

	void CFSecSaxLdr::applyLoaderOptions( cfsec::CFSecSaxLoader* loader, const std::string& loaderOptions ) {
		static const std::string S_PathSeparator( ":" );
		std::string workingOptions( loaderOptions );
		while( workingOptions.length() > 0 ) {
			std::string evalSegment;
			std::string::size_type sepIndex = workingOptions.find( S_PathSeparator );
			if( sepIndex != std::string::npos ) {
				evalSegment = workingOptions.substr( 0, sepIndex );
				if( workingOptions.length() > sepIndex + 1 ) {
					workingOptions = workingOptions.substr( sepIndex + 1 );
				}
				else {
					workingOptions.clear();
				}
			}
			else {
				evalSegment = workingOptions;
				workingOptions.clear();
			}
			evalLoaderSegment( loader, evalSegment );
		}
	}

	void CFSecSaxLdr::evalLoaderSegment( cfsec::CFSecSaxLoader* loader, const std::string& evalSegment ) {
		const static std::string S_ProcName( "evalLoaderSegment()" );
		const static std::string S_Asterisk( "*" );
		const static std::string S_Equal( "=" );
		const static std::string S_Insert( "Insert" );
		const static std::string S_Update( "Update" );
		const static std::string S_Replace( "Replace" );
		const static std::string S_SegmentMsg( "ERROR: Expected segment to comprise <TableName>={*|Insert|Update|Replace}" );
		std::string::size_type sepEquals = evalSegment.find( S_Equal );
		if( sepEquals == std::string::npos ) {
			throw cflib::CFLibRuntimeException( CLASS_NAME,
				S_ProcName,
				S_SegmentMsg );
		}
		std::string tableName = evalSegment.substr( 0, sepEquals );
		std::string tableOption = evalSegment.substr( sepEquals + 1 );
		if( tableName == cfsec::CFSecClusterBuff::GENDEFNAME ) {
			if( tableOption == S_Asterisk ) {
				// Leave at default
			}
			else if( tableOption == S_Insert ) {
				loader->setClusterLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Insert );
			}
			else if( tableOption == S_Update ) {
				loader->setClusterLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Update );
			}
			else if( tableOption == S_Replace ) {
				loader->setClusterLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Replace );
			}
			else {
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					S_SegmentMsg );
			}
		}
		else if( tableName == cfsec::CFSecHostNodeBuff::GENDEFNAME ) {
			if( tableOption == S_Asterisk ) {
				// Leave at default
			}
			else if( tableOption == S_Insert ) {
				loader->setHostNodeLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Insert );
			}
			else if( tableOption == S_Update ) {
				loader->setHostNodeLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Update );
			}
			else if( tableOption == S_Replace ) {
				loader->setHostNodeLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Replace );
			}
			else {
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					S_SegmentMsg );
			}
		}
		else if( tableName == cfsec::CFSecISOCcyBuff::GENDEFNAME ) {
			if( tableOption == S_Asterisk ) {
				// Leave at default
			}
			else if( tableOption == S_Insert ) {
				loader->setISOCcyLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Insert );
			}
			else if( tableOption == S_Update ) {
				loader->setISOCcyLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Update );
			}
			else if( tableOption == S_Replace ) {
				loader->setISOCcyLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Replace );
			}
			else {
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					S_SegmentMsg );
			}
		}
		else if( tableName == cfsec::CFSecISOCtryBuff::GENDEFNAME ) {
			if( tableOption == S_Asterisk ) {
				// Leave at default
			}
			else if( tableOption == S_Insert ) {
				loader->setISOCtryLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Insert );
			}
			else if( tableOption == S_Update ) {
				loader->setISOCtryLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Update );
			}
			else if( tableOption == S_Replace ) {
				loader->setISOCtryLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Replace );
			}
			else {
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					S_SegmentMsg );
			}
		}
		else if( tableName == cfsec::CFSecISOCtryCcyBuff::GENDEFNAME ) {
			if( tableOption == S_Asterisk ) {
				// Leave at default
			}
			else if( tableOption == S_Insert ) {
				loader->setISOCtryCcyLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Insert );
			}
			else if( tableOption == S_Update ) {
				loader->setISOCtryCcyLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Update );
			}
			else if( tableOption == S_Replace ) {
				loader->setISOCtryCcyLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Replace );
			}
			else {
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					S_SegmentMsg );
			}
		}
		else if( tableName == cfsec::CFSecISOCtryLangBuff::GENDEFNAME ) {
			if( tableOption == S_Asterisk ) {
				// Leave at default
			}
			else if( tableOption == S_Insert ) {
				loader->setISOCtryLangLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Insert );
			}
			else if( tableOption == S_Update ) {
				loader->setISOCtryLangLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Update );
			}
			else if( tableOption == S_Replace ) {
				loader->setISOCtryLangLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Replace );
			}
			else {
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					S_SegmentMsg );
			}
		}
		else if( tableName == cfsec::CFSecISOLangBuff::GENDEFNAME ) {
			if( tableOption == S_Asterisk ) {
				// Leave at default
			}
			else if( tableOption == S_Insert ) {
				loader->setISOLangLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Insert );
			}
			else if( tableOption == S_Update ) {
				loader->setISOLangLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Update );
			}
			else if( tableOption == S_Replace ) {
				loader->setISOLangLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Replace );
			}
			else {
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					S_SegmentMsg );
			}
		}
		else if( tableName == cfsec::CFSecISOTZoneBuff::GENDEFNAME ) {
			if( tableOption == S_Asterisk ) {
				// Leave at default
			}
			else if( tableOption == S_Insert ) {
				loader->setISOTZoneLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Insert );
			}
			else if( tableOption == S_Update ) {
				loader->setISOTZoneLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Update );
			}
			else if( tableOption == S_Replace ) {
				loader->setISOTZoneLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Replace );
			}
			else {
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					S_SegmentMsg );
			}
		}
		else if( tableName == cfsec::CFSecSecAppBuff::GENDEFNAME ) {
			if( tableOption == S_Asterisk ) {
				// Leave at default
			}
			else if( tableOption == S_Insert ) {
				loader->setSecAppLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Insert );
			}
			else if( tableOption == S_Update ) {
				loader->setSecAppLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Update );
			}
			else if( tableOption == S_Replace ) {
				loader->setSecAppLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Replace );
			}
			else {
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					S_SegmentMsg );
			}
		}
		else if( tableName == cfsec::CFSecSecDeviceBuff::GENDEFNAME ) {
			if( tableOption == S_Asterisk ) {
				// Leave at default
			}
			else if( tableOption == S_Insert ) {
				loader->setSecDeviceLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Insert );
			}
			else if( tableOption == S_Update ) {
				loader->setSecDeviceLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Update );
			}
			else if( tableOption == S_Replace ) {
				loader->setSecDeviceLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Replace );
			}
			else {
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					S_SegmentMsg );
			}
		}
		else if( tableName == cfsec::CFSecSecFormBuff::GENDEFNAME ) {
			if( tableOption == S_Asterisk ) {
				// Leave at default
			}
			else if( tableOption == S_Insert ) {
				loader->setSecFormLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Insert );
			}
			else if( tableOption == S_Update ) {
				loader->setSecFormLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Update );
			}
			else if( tableOption == S_Replace ) {
				loader->setSecFormLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Replace );
			}
			else {
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					S_SegmentMsg );
			}
		}
		else if( tableName == cfsec::CFSecSecGroupBuff::GENDEFNAME ) {
			if( tableOption == S_Asterisk ) {
				// Leave at default
			}
			else if( tableOption == S_Insert ) {
				loader->setSecGroupLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Insert );
			}
			else if( tableOption == S_Update ) {
				loader->setSecGroupLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Update );
			}
			else if( tableOption == S_Replace ) {
				loader->setSecGroupLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Replace );
			}
			else {
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					S_SegmentMsg );
			}
		}
		else if( tableName == cfsec::CFSecSecGroupFormBuff::GENDEFNAME ) {
			if( tableOption == S_Asterisk ) {
				// Leave at default
			}
			else if( tableOption == S_Insert ) {
				loader->setSecGroupFormLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Insert );
			}
			else if( tableOption == S_Update ) {
				loader->setSecGroupFormLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Update );
			}
			else if( tableOption == S_Replace ) {
				loader->setSecGroupFormLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Replace );
			}
			else {
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					S_SegmentMsg );
			}
		}
		else if( tableName == cfsec::CFSecSecGrpIncBuff::GENDEFNAME ) {
			if( tableOption == S_Asterisk ) {
				// Leave at default
			}
			else if( tableOption == S_Insert ) {
				loader->setSecGrpIncLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Insert );
			}
			else if( tableOption == S_Update ) {
				loader->setSecGrpIncLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Update );
			}
			else if( tableOption == S_Replace ) {
				loader->setSecGrpIncLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Replace );
			}
			else {
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					S_SegmentMsg );
			}
		}
		else if( tableName == cfsec::CFSecSecGrpMembBuff::GENDEFNAME ) {
			if( tableOption == S_Asterisk ) {
				// Leave at default
			}
			else if( tableOption == S_Insert ) {
				loader->setSecGrpMembLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Insert );
			}
			else if( tableOption == S_Update ) {
				loader->setSecGrpMembLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Update );
			}
			else if( tableOption == S_Replace ) {
				loader->setSecGrpMembLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Replace );
			}
			else {
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					S_SegmentMsg );
			}
		}
		else if( tableName == cfsec::CFSecSecSessionBuff::GENDEFNAME ) {
			if( tableOption == S_Asterisk ) {
				// Leave at default
			}
			else if( tableOption == S_Insert ) {
				loader->setSecSessionLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Insert );
			}
			else if( tableOption == S_Update ) {
				loader->setSecSessionLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Update );
			}
			else if( tableOption == S_Replace ) {
				loader->setSecSessionLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Replace );
			}
			else {
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					S_SegmentMsg );
			}
		}
		else if( tableName == cfsec::CFSecSecUserBuff::GENDEFNAME ) {
			if( tableOption == S_Asterisk ) {
				// Leave at default
			}
			else if( tableOption == S_Insert ) {
				loader->setSecUserLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Insert );
			}
			else if( tableOption == S_Update ) {
				loader->setSecUserLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Update );
			}
			else if( tableOption == S_Replace ) {
				loader->setSecUserLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Replace );
			}
			else {
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					S_SegmentMsg );
			}
		}
		else if( tableName == cfsec::CFSecServiceBuff::GENDEFNAME ) {
			if( tableOption == S_Asterisk ) {
				// Leave at default
			}
			else if( tableOption == S_Insert ) {
				loader->setServiceLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Insert );
			}
			else if( tableOption == S_Update ) {
				loader->setServiceLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Update );
			}
			else if( tableOption == S_Replace ) {
				loader->setServiceLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Replace );
			}
			else {
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					S_SegmentMsg );
			}
		}
		else if( tableName == cfsec::CFSecServiceTypeBuff::GENDEFNAME ) {
			if( tableOption == S_Asterisk ) {
				// Leave at default
			}
			else if( tableOption == S_Insert ) {
				loader->setServiceTypeLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Insert );
			}
			else if( tableOption == S_Update ) {
				loader->setServiceTypeLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Update );
			}
			else if( tableOption == S_Replace ) {
				loader->setServiceTypeLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Replace );
			}
			else {
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					S_SegmentMsg );
			}
		}
		else if( tableName == cfsec::CFSecSysClusterBuff::GENDEFNAME ) {
			if( tableOption == S_Asterisk ) {
				// Leave at default
			}
			else if( tableOption == S_Insert ) {
				loader->setSysClusterLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Insert );
			}
			else if( tableOption == S_Update ) {
				loader->setSysClusterLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Update );
			}
			else if( tableOption == S_Replace ) {
				loader->setSysClusterLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Replace );
			}
			else {
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					S_SegmentMsg );
			}
		}
		else if( tableName == cfsec::CFSecTSecGroupBuff::GENDEFNAME ) {
			if( tableOption == S_Asterisk ) {
				// Leave at default
			}
			else if( tableOption == S_Insert ) {
				loader->setTSecGroupLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Insert );
			}
			else if( tableOption == S_Update ) {
				loader->setTSecGroupLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Update );
			}
			else if( tableOption == S_Replace ) {
				loader->setTSecGroupLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Replace );
			}
			else {
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					S_SegmentMsg );
			}
		}
		else if( tableName == cfsec::CFSecTSecGrpIncBuff::GENDEFNAME ) {
			if( tableOption == S_Asterisk ) {
				// Leave at default
			}
			else if( tableOption == S_Insert ) {
				loader->setTSecGrpIncLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Insert );
			}
			else if( tableOption == S_Update ) {
				loader->setTSecGrpIncLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Update );
			}
			else if( tableOption == S_Replace ) {
				loader->setTSecGrpIncLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Replace );
			}
			else {
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					S_SegmentMsg );
			}
		}
		else if( tableName == cfsec::CFSecTSecGrpMembBuff::GENDEFNAME ) {
			if( tableOption == S_Asterisk ) {
				// Leave at default
			}
			else if( tableOption == S_Insert ) {
				loader->setTSecGrpMembLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Insert );
			}
			else if( tableOption == S_Update ) {
				loader->setTSecGrpMembLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Update );
			}
			else if( tableOption == S_Replace ) {
				loader->setTSecGrpMembLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Replace );
			}
			else {
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					S_SegmentMsg );
			}
		}
		else if( tableName == cfsec::CFSecTenantBuff::GENDEFNAME ) {
			if( tableOption == S_Asterisk ) {
				// Leave at default
			}
			else if( tableOption == S_Insert ) {
				loader->setTenantLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Insert );
			}
			else if( tableOption == S_Update ) {
				loader->setTenantLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Update );
			}
			else if( tableOption == S_Replace ) {
				loader->setTenantLoaderBehaviour( cfsec::CFSecSaxLoader::LoaderBehaviourEnum::Replace );
			}
			else {
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					S_SegmentMsg );
			}
		}
		else {
			throw cflib::CFLibRuntimeException( CLASS_NAME,
				S_ProcName,
				S_SegmentMsg );
		}
	}

	void CFSecSaxLdr::evaluateRemainingArgs( size_t argc, char* argv[], size_t consumed ) {
		// This method gets overloaded to evaluate the database-specific
		// connection arguments, if supported by a database specialization.
	}

}
