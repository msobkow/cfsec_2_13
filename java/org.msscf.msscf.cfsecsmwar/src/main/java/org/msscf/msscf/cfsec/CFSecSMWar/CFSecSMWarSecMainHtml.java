
// Description: Java 11 Sec Manager Sec Main Servlet

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

package org.msscf.msscf.cfsec.CFSecSMWar;

import java.io.IOException;
import java.io.PrintWriter;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Calendar;
import java.util.Iterator;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.*;

import org.apache.commons.codec.binary.Base64;

import org.msscf.msscf.cflib.CFLib.*;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfsec.CFSecObj.*;

/**
 * Servlet implementation class CFSecSMWarSecMainHtml
 */
@WebServlet("/CFSecSMWarSecMainHtml")
public class CFSecSMWarSecMainHtml extends HttpServlet {
	private static final long serialVersionUID = 1L;

	/**
	 * @see HttpServlet#HttpServlet()
	 */
	public CFSecSMWarSecMainHtml() {
		super();
	}

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		final String S_ProcName="doGet";
		ICFSecSchemaObj schemaObj;
		HttpSession sess = request.getSession( false );
		if( sess == null ) {
			sess = request.getSession( true );
			schemaObj = new CFSecSchemaPooledObj();
			sess.setAttribute( "SchemaObj", schemaObj );
		}
		else {
			schemaObj = (ICFSecSchemaObj)sess.getAttribute( "SchemaObj" );
			if( schemaObj == null ) {
				response.sendRedirect( "CFSecSMWarLoginHtml" );
				return;
			}
		}

		ICFSecSchema dbSchema = null;
		try {
			CFSecAuthorization auth = schemaObj.getAuthorization();
			if( auth == null ) {
				response.sendRedirect( "CFSecSMWarLoginHtml" );
			}
			else {
				dbSchema = (ICFSecSchema)CFSecSchemaPool.getSchemaPool().getInstance();
				schemaObj.setBackingStore( dbSchema );
				schemaObj.beginTransaction();
				ICFSecSecUserObj secUser = schemaObj.getSecUserTableObj().readSecUserByIdIdx( auth.getSecUserId() );

				ICFSecClusterObj secCluster = schemaObj.getClusterTableObj().readClusterByIdIdx( auth.getSecClusterId() );
				if( secCluster == null ) {
					throw new CFLibNullArgumentException( getClass(),
						S_ProcName,
						0,
						"secCluster" );
				}
				String clusterDescription = secCluster.getRequiredDescription();

				response.setContentType( "text/html" );
				PrintWriter out = response.getWriter();
				out.println( "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01//EN\">" );
				out.println( "<HTML>" );
				out.println( "<BODY>" );
				out.println( "<form method=\"post\" formaction=\"CFSecSMWarSecMainHtml\">" );
				out.println( "<H1 style=\"text-align:center\">" + clusterDescription + " Sec Manager</H1>" );
				out.println( "<H2 style=\"text-align:center\">Logged in as "
						+ secUser.getRequiredEMailAddress()
						+ "</H2>" );
				out.println( "<p>" );
				out.println( "<center>" );
				out.println( "<table style=\"width:70%\">" );
				out.println( "<tr><th style=\"text-align:center\">Device Name (* is default device)</th><th style=\"text-align:center\">Click to Make Default</th><th style=\"text-align:center\">Click to Delete</th></tr>" );
				ICFSecSecDeviceObj defDev = secUser.getOptionalLookupDefDev( true );
				ICFSecSecDeviceObj secDev;
				Iterator<ICFSecSecDeviceObj> iterDev = secUser.getOptionalComponentsSecDev( true ).iterator();
				while( iterDev.hasNext() ) {
					secDev = iterDev.next();
					out.println(
						"<tr><td>"
							+ ( ( secDev == defDev )
									? "(*) "
									: "" )
							+ secDev.getRequiredDevName()
						+ "</td><td>"
							+ ( ( secDev != defDev )
									? "<A HRef=\"CFSecSMWarMakeDefaultDeviceHtml?DeviceName="
										+ secDev.getRequiredDevName()
										+ "\">Make Default</A>"
									: "" )
						+ "</td><td>"
							+ ( ( secDev != defDev )
									? "<A HRef=\"CFSecSMWarDeleteDeviceHtml?DeviceName="
										+ secDev.getRequiredDevName()
										+ "\">Delete</A>"
									: "" )
						+ "</td></tr>" );
				}
				out.println( "</table>" );
				out.println( "</center>" );
				iterDev = secUser.getOptionalComponentsSecDev( true ).iterator();
				if( ! iterDev.hasNext() ) {
					out.println( "<p style=\"text-align:center\">" );
					out.println( "You must <A HRef=\"CFSecSMWarAddDeviceHtml\">Add A Default Device</A> before doing anything else." );
				}
				else {
					out.println( "<p style=\"text-align:center\"><button type=\"button\" name=\"AddDevice\"\" onclick=\"window.location.href='CFSecSMWarChangePasswordHtml'\">Change Password</button>&nbsp;&nbsp;&nbsp;&nbsp;<button type=\"button\" name=\"AddDevice\"\" onclick=\"window.location.href='CFSecSMWarAddDeviceHtml'\">Add Device</button>&nbsp;&nbsp;&nbsp;&nbsp;<button type=\"button\" name=\"Logout\"\" onclick=\"window.location.href='CFSecSMWarLogoutHtml'\">Log Out</button>" );
				}
				out.println( "</form>" );
				out.println( "</BODY>" );
				out.println( "</HTML>" );
			}
		}
		catch( RuntimeException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught RuntimeException -- " + e.getMessage(),
				e );
		}
		finally {
			if( dbSchema != null ) {
				try {
					if( schemaObj.isTransactionOpen() ) { 
						schemaObj.rollback();
					}
				}
				catch( RuntimeException e ) {
				}
				schemaObj.setBackingStore( null );
				CFSecSchemaPool.getSchemaPool().releaseInstance( dbSchema );
			}
		}
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		final String S_ProcName = "doPost";

		ICFSecSchemaObj schemaObj;
		HttpSession sess = request.getSession( false );
		if( sess == null ) {
			sess = request.getSession( true );
			schemaObj = new CFSecSchemaPooledObj();
			sess.setAttribute( "SchemaObj", schemaObj );
		}
		else {
			schemaObj = (ICFSecSchemaObj)sess.getAttribute( "SchemaObj" );
			if( schemaObj == null ) {
				response.sendRedirect( "CFSecSMWarLoginHtml" );
				return;
			}
		}

		ICFSecSchema dbSchema = null;
		try {
			CFSecAuthorization auth = schemaObj.getAuthorization();
			if( auth == null ) {
				response.sendRedirect( "CFSecSMWarLoginHtml" );
			}
			else {
				dbSchema = (ICFSecSchema)CFSecSchemaPool.getSchemaPool().getInstance();
				schemaObj.setBackingStore( dbSchema );
				schemaObj.beginTransaction();
				ICFSecSecUserObj secUser = schemaObj.getSecUserTableObj().readSecUserByIdIdx( auth.getSecUserId() );

				ICFSecClusterObj secCluster = schemaObj.getClusterTableObj().readClusterByIdIdx( auth.getSecClusterId() );
				if( secCluster == null ) {
					throw new CFLibNullArgumentException( getClass(),
						S_ProcName,
						0,
						"secCluster" );
				}
				String clusterDescription = secCluster.getRequiredDescription();

				response.setContentType( "text/html" );
				PrintWriter out = response.getWriter();
				out.println( "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01//EN\">" );
				out.println( "<HTML>" );
				out.println( "<BODY>" );
				out.println( "<form method=\"post\" formaction=\"CFSecSMWarSecMainHtml\">" );
				out.println( "<H1 style=\"text-align:center\">" + clusterDescription + " Sec Manager</H1>" );
				out.println( "<H2 style=\"text-align:center\">Logged in as "
					+ secUser.getRequiredEMailAddress()
					+ "</H2>" );
				out.println( "<p style=\"text-align:center\"><A HRef=\"CFSecSMWarChangePasswordHtml\">Change Password</A>" );
				out.println( "<p>" );
				out.println( "<center>" );
				out.println( "<table style=\"width:70%\">" );
				out.println( "<tr><th style=\"text-align:center\">Device Name (* is default device)</th><th style=\"text-align:center\">Click to Make Default</th><th style=\"text-align:center\">Click to Delete</th></tr>" );
				ICFSecSecDeviceObj defDev = secUser.getOptionalLookupDefDev( true );
				ICFSecSecDeviceObj secDev;
				Iterator<ICFSecSecDeviceObj> iterDev = secUser.getOptionalComponentsSecDev( true ).iterator();
				while( iterDev.hasNext() ) {
					secDev = iterDev.next();
					out.println(
						"<tr><td>"
							+ ( ( secDev == defDev )
									? "(*) "
									: "" )
							+ secDev.getRequiredDevName()
						+ "</td><td>"
							+ ( ( secDev != defDev )
									? "<A HRef=\"CFSecSMWarMakeDefaultDeviceHtml?DeviceName="
										+ secDev.getRequiredDevName()
										+ "\">Make Default</A>"
									: "" )
						+ "</td><td>"
							+ ( ( secDev != defDev )
									? "<A HRef=\"CFSecSMWarDeleteDeviceHtml?DeviceName="
										+ secDev.getRequiredDevName()
										+ "\">Delete</A>"
									: "" )
						+ "</td></tr>" );
				}
				out.println( "</table>" );
				out.println( "</center>" );
				iterDev = secUser.getOptionalComponentsSecDev().iterator();
				if( ! iterDev.hasNext() ) {
					out.println( "<p style=\"text-align:center\">" );
					out.println( "You must <A HRef=\"CFSecSMWarAddDeviceHtml\">Add A Default Device</A> before doing anything else." );
				}
				else {
					out.println( "<p style=\"text-align:center\"><button type=\"button\" name=\"AddDevice\"\" onclick=\"window.location.href='CFSecSMWarChangePasswordHtml'\">Change Password</button>&nbsp;&nbsp;&nbsp;&nbsp;<button type=\"button\" name=\"AddDevice\"\" onclick=\"window.location.href='CFSecSMWarAddDeviceHtml'\">Add Device</button>&nbsp;&nbsp;&nbsp;&nbsp;<button type=\"button\" name=\"Logout\"\" onclick=\"window.location.href='CFSecSMWarLogoutHtml'\">Log Out</button>" );
				}
				out.println( "</form>" );
				out.println( "</BODY>" );
				out.println( "</HTML>" );
			}
		}
		catch( RuntimeException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught RuntimeException -- " + e.getMessage(),
				e );
		}
		finally {
			if( dbSchema != null ) {
				try {
					if( schemaObj.isTransactionOpen() ) { 
						schemaObj.rollback();
					}
				}
				catch( RuntimeException e ) {
				}
				schemaObj.setBackingStore( null );
				CFSecSchemaPool.getSchemaPool().releaseInstance( dbSchema );
			}
		}
	}
}
