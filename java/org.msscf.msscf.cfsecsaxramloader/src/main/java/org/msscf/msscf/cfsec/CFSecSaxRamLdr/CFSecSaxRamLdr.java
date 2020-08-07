// Description: Java 11 XML SAX Parser for CFSec.

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

package org.msscf.msscf.cfsec.CFSecSaxRamLdr;

import org.apache.log4j.*;
import org.msscf.msscf.cflib.CFLib.*;
import org.msscf.msscf.cfsec.CFSec.*;

import org.msscf.msscf.cfsec.CFSecObj.*;
import org.msscf.msscf.cfsec.CFSecRam.*;
import org.msscf.msscf.cfsec.CFSecSaxLoader.*;

public class CFSecSaxRamLdr
	extends CFSecSaxLdr
{
	private static ICFLibMessageLog log = new CFLibConsoleMessageLog();

	// Constructors

	public CFSecSaxRamLdr() {
		super( log );
	}

	// main() entry point

	public static void main( String args[] ) {
		final String S_ProcName = "CFSecSaxRamLdr.main() ";
		initConsoleLog();
		int numArgs = args.length;
		if( numArgs >= 2 ) {
			ICFSecSchema cFSecSchema = new CFSecRamSchema();
			ICFSecSchemaObj cFSecSchemaObj = new CFSecSchemaObj();
			cFSecSchemaObj.setBackingStore( cFSecSchema );
			CFSecSaxLdr cli = new CFSecSaxRamLdr();
			CFSecSaxLoader loader = cli.getSaxLoader();
			loader.setSchemaObj( cFSecSchemaObj );
			String url = args[1];
			try {
				cFSecSchema.connect( "system", "system", "system", "system" );
				cFSecSchema.rollback();
				cFSecSchema.beginTransaction();
				cFSecSchemaObj.setSecCluster( cFSecSchemaObj.getClusterTableObj().getSystemCluster() );
				cFSecSchemaObj.setSecTenant( cFSecSchemaObj.getTenantTableObj().getSystemTenant() );
				cFSecSchemaObj.setSecSession( cFSecSchemaObj.getSecSessionTableObj().getSystemSession() );
				CFSecAuthorization auth = new CFSecAuthorization();
				auth.setSecCluster( cFSecSchemaObj.getSecCluster() );
				auth.setSecTenant( cFSecSchemaObj.getSecTenant() );
				auth.setSecSession( cFSecSchemaObj.getSecSession() );
				cFSecSchemaObj.setAuthorization( auth );
				loader.setUseCluster( cFSecSchemaObj.getSecCluster() );
				loader.setUseTenant( cFSecSchemaObj.getSecTenant() );
				applyLoaderOptions( loader, args[0] );
				cli.evaluateRemainingArgs( args, 2 );
				loader.parseFile( url );
				cFSecSchema.commit();
				cFSecSchema.disconnect( true );
			}
			catch( Exception e ) {
				log.message( S_ProcName + "EXCEPTION: Could not parse XML file \"" + url + "\": " + e.getMessage() );
				e.printStackTrace( System.out );
			}
			catch( Error e ) {
				log.message( S_ProcName + "ERROR: Could not parse XML file \"" + url + "\": " + e.getMessage() );
				e.printStackTrace( System.out );
			}
			finally {
				if( cFSecSchema.isConnected() ) {
					cFSecSchema.rollback();
					cFSecSchema.disconnect( false );
				}
			}
		}
		else {
			log.message( S_ProcName + "ERROR: Expected at least two argument specifying the loader options and the name of the XML file to parse.  The first argument may be empty." );
		}
	}

	// Initialize the console log

	protected static void initConsoleLog() {
//		Layout layout = new PatternLayout(
//				"%d{ISO8601}"		// Start with a timestamp
//			+	" %-5p"				// Include the severity
//			+	" %C.%M"			// pkg.class.method()
//			+	" %F[%L]"			// File[lineNumber]
//			+	": %m\n" );			// Message text
//		BasicConfigurator.configure( new ConsoleAppender( layout, "System.out" ) );
	}

	// Evaluate remaining arguments

	public void evaluateRemainingArgs( String[] args, int consumed ) {
		// There are no extra arguments for the RAM "database" instance
		if( args.length > consumed ) {
			log.message( "CFSecSaxRamLdr.evaluateRemainingArgs() WARNING No extra arguments are expected for a RAM database instance, but "
				+ Integer.toString( args.length - consumed )
				+ " extra arguments were specified.  Extra arguments ignored." );
		}
	}

}
