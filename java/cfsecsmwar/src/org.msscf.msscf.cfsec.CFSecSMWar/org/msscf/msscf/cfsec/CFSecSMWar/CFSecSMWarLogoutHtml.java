
// Description: Java 11 Sec Manager Logout Servlet

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

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.*;

import org.apache.commons.codec.binary.Base64;

import org.msscf.msscf.cflib.CFLib.*;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfsec.CFSecObj.*;

/**
 * Servlet implementation class CFSecSMWarLoginHtml
 */
@WebServlet("/CFSecSMWarLogoutHtml")
public class CFSecSMWarLogoutHtml extends HttpServlet {
	private static final long serialVersionUID = 1L;

	/**
	 * @see HttpServlet#HttpServlet()
	 */
	public CFSecSMWarLogoutHtml() {
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
				out.println( "<form method=\"post\" formaction=\"CFSecSMWarLogoutHtml\">" );
				out.println( "<H1 style=\"text-align:center\">" + clusterDescription + " Sec Manager</H1>" );
				out.println( "<H2 style=\"text-align:center\">Are you sure you want to log out from "
						+ secUser.getRequiredEMailAddress()
						+ "?</H2>" );
				out.println( "<table style=\"width:60%\">" );
				out.println( "<tr><td style=\"text-align:center\"><button type=\"submit\" name=\"Ok\"\">Yes, log out</button></td><td style=\"text-align:center\"><button type=\"button\" name=\"Cancel\"\" onclick=\"window.location.href='CFSecSMWarSecMainHtml'\">Continue Session</button></td></tr>" );
				out.println( "<p>" );
				out.println( "</table>" );
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
				ICFSecSecSessionObj secSession = schemaObj.getSecSessionTableObj().readSecSessionByIdIdx( auth.getSecSessionId() );
				if( secSession == null ) {
					schemaObj.setAuthorization( null );
					schemaObj.minimizeMemory();
					response.sendRedirect( "CFSecSMWarLoginHtml" );
				}
				else {

					ICFSecSecUserObj systemUser = schemaObj.getSecUserTableObj().readSecUserByULoginIdx( "system" );

					ICFSecClusterObj systemCluster = schemaObj.getClusterTableObj().readClusterByUDomNameIdx( "system" );
					ICFSecTenantObj systemTenant = schemaObj.getTenantTableObj().readTenantByUNameIdx( systemCluster.getRequiredId(), "system" );
					ICFSecSecSessionObj systemSession = schemaObj.getSecSessionTableObj().newInstance();
					ICFSecSecSessionEditObj editSystemSession = (ICFSecSecSessionEditObj)systemSession.beginEdit();
					editSystemSession.setRequiredContainerSecUser( systemUser );
					editSystemSession.setRequiredStart( Calendar.getInstance() );
					systemSession = editSystemSession.create();
					editSystemSession = null;

					auth = new CFSecAuthorization();
					auth.setSecCluster( systemCluster );
					auth.setSecTenant( systemTenant );
					auth.setSecSession( systemSession );
					schemaObj.setAuthorization( auth );

					ICFSecSecSessionEditObj editSecSession = (ICFSecSecSessionEditObj)secSession.beginEdit();
					if( editSecSession.getOptionalFinish() == null ) {
						editSecSession.setOptionalFinish( Calendar.getInstance() );
					}

					editSecSession.update();
					editSecSession = null;

					editSystemSession = systemSession.beginEdit();
					editSystemSession.setOptionalFinish( Calendar.getInstance() );
					editSystemSession.update();
					editSystemSession = null;

					schemaObj.commit();
					schemaObj.setAuthorization( null );
					schemaObj.minimizeMemory();
					response.sendRedirect( "CFSecSMWarLoginHtml" );
				}
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
			sess.setAttribute( "SchemaObj", null );
		}
	}
}
