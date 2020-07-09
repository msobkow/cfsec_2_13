
// Description: Java 11 Sec Manager Add Device Servlet

/*
 *	org.msscf.msscf.CFSec
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

package org.msscf.msscf.cfsec.CFSecSMWar;

import java.io.*;
import java.security.*;
import java.security.spec.InvalidKeySpecException;
import java.security.spec.X509EncodedKeySpec;
import java.util.*;

import javax.crypto.Cipher;
import javax.crypto.NoSuchPaddingException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.*;

import org.apache.commons.codec.binary.Base64;

import com.github.msobkow.cflib.CFLib.*;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfsec.CFSecObj.*;

/**
 * Servlet implementation class CFSecSMWarLoginHtml
 */
@WebServlet("/CFSecSMWarAddDeviceHtml")
public class CFSecSMWarAddDeviceHtml extends HttpServlet {
	private static final long serialVersionUID = 1L;

	/**
	 * @see HttpServlet#HttpServlet()
	 */
	public CFSecSMWarAddDeviceHtml() {
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
				schemaObj = new CFSecSchemaPooledObj();
				sess.setAttribute( "SchemaObj", schemaObj );
			}
		}

		CFSecAuthorization auth = schemaObj.getAuthorization();
		if( auth == null ) {
			response.sendRedirect( "CFSecSMWarLoginHtml" );
			return;
		}

		ICFSecSchema dbSchema = null;
		try {
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
			out.println( "<form method=\"post\" formaction=\"CFSecSMWarAddDeviceHtml\">" );
			out.println( "<H1 style=\"text-align:center\">" + clusterDescription + " Sec Manager</H1>" );
			out.println( "<H2 style=\"text-align:center\">Add new device for "
					+ secUser.getRequiredEMailAddress()
					+ "</H2>" );
			out.println( "<p>" );
			out.println( "<table style=\"width:90%\">" );
			out.println( "<tr><th style=\"text-align:left\">Device Name:</th><td><input type=\"text\" name=\"DeviceName\"/></td></tr>");
			out.println( "<tr><th style=\"text-align:left\">Public Key:</th><td><textarea name=\"PublicKey\" cols=\"60\" rows=\"10\"></textarea></td></tr>");
			out.println( "</table>" );
			out.println( "<p style=\"text-align:center\"><button type=\"submit\" name=\"Ok\"\">Add Device</button>&nbsp;&nbsp;&nbsp;&nbsp;<button type=\"button\" name=\"Cancel\"\" onclick=\"window.location.href='CFSecSMWarSecMainHtml'\">Cancel;</button>" );
			out.println( "</form>" );
			out.println( "</BODY>" );
			out.println( "</HTML>" );
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

		CFSecAuthorization auth = schemaObj.getAuthorization();
		if( auth == null ) {
			response.sendRedirect( "CFSecSMWarLoginHtml" );
			return;
		}

		ICFSecSecUserObj secUser = null;
		ICFSecClusterObj secCluster = null;
		String clusterDescription = "";

		ICFSecSchema dbSchema = null;
		try {
			dbSchema = (ICFSecSchema)CFSecSchemaPool.getSchemaPool().getInstance();
			schemaObj.setBackingStore( dbSchema );
			schemaObj.beginTransaction();

			secUser = schemaObj.getSecUserTableObj().readSecUserByIdIdx( auth.getSecUserId() );

			secCluster = schemaObj.getClusterTableObj().readClusterByIdIdx( auth.getSecClusterId() );
			if( secCluster == null ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"secCluster" );
			}
			clusterDescription = secCluster.getRequiredDescription();

			String deviceName = request.getParameter( "DeviceName" );
			if( ( deviceName == null ) || ( deviceName.length() <= 0 ) ) {
				response.setContentType( "text/html" );
				PrintWriter out = response.getWriter();
				out.println( "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01//EN\">" );
				out.println( "<HTML>" );
				out.println( "<BODY>" );
				out.println( "<form method=\"post\" formaction=\"CFSecSMWarAddDeviceHtml\">" );
				out.println( "<H1 style=\"text-align:center\">" + clusterDescription + " Sec Manager</H1>" );
				out.println( "<H2 style=\"text-align:center\">ERROR</H2>" );
				out.println( "<p style=\"text-align:center\">Device Name must be specified." );
				out.println( "<H2 style=\"text-align:center\">Add new device for "
						+ secUser.getRequiredEMailAddress()
						+ "</H2>" );
				out.println( "<p>" );
				out.println( "<table style=\"width:90%\">" );
				out.println( "<tr><th style=\"text-align:left\">Device Name:</th><td><input type=\"text\" name=\"DeviceName\"/></td></tr>");
				out.println( "<tr><th style=\"text-align:left\">Public Key:</th><td><textarea name=\"PublicKey\" cols=\"60\" rows=\"10\"></textarea></td></tr>");
				out.println( "</table>" );
				out.println( "<p style=\"text-align:center\"><button type=\"submit\" name=\"Ok\"\">Add Device</button>&nbsp;&nbsp;&nbsp;&nbsp;<button type=\"button\" name=\"Cancel\"\" onclick=\"window.location.href='CFSecSMWarSecMainHtml'\">Cancel</button>" );
				out.println( "</form>" );
				out.println( "</BODY>" );
				out.println( "</HTML>" );
				return;
			}

			ICFSecSecDeviceObj secDev = schemaObj.getSecDeviceTableObj().readSecDeviceByIdIdx( secUser.getRequiredSecUserId(), deviceName );
			if( secDev != null ) {
				response.setContentType( "text/html" );
				PrintWriter out = response.getWriter();
				out.println( "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01//EN\">" );
				out.println( "<HTML>" );
				out.println( "<BODY>" );
				out.println( "<form method=\"post\" formaction=\"CFSecSMWarAddDeviceHtml\">" );
				out.println( "<H1 style=\"text-align:center\">" + clusterDescription + " Sec Manager</H1>" );
				out.println( "<H2 style=\"text-align:center\">ERROR</H2>" );
				out.println( "<p style=\"text-align:center\">Device Name \"" + deviceName + "\" already in use." );
				out.println( "<H2 style=\"text-align:center\">Add new device for "
						+ secUser.getRequiredEMailAddress()
						+ "</H2>" );
				out.println( "<p>" );
				out.println( "<table style=\"width:90%\">" );
				out.println( "<tr><th style=\"text-align:left\">Device Name:</th><td><input type=\"text\" name=\"DeviceName\"/></td></tr>");
				out.println( "<tr><th style=\"text-align:left\">Public Key:</th><td><textarea name=\"PublicKey\" cols=\"60\" rows=\"10\"></textarea></td></tr>");
				out.println( "</table>" );
				out.println( "<p style=\"text-align:center\"><button type=\"submit\" name=\"Ok\"\">Add Device</button>&nbsp;&nbsp;&nbsp;&nbsp;<button type=\"button\" name=\"Cancel\"\" onclick=\"window.location.href='CFSecSMWarSecMainHtml'\">Cancel</button>" );
				out.println( "</form>" );
				out.println( "</BODY>" );
				out.println( "</HTML>" );
				return;
			}

			String publicKey = request.getParameter( "PublicKey" );
			if( ( publicKey == null ) || ( publicKey.length() <= 0 ) ) {
				response.setContentType( "text/html" );
				PrintWriter out = response.getWriter();
				out.println( "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01//EN\">" );
				out.println( "<HTML>" );
				out.println( "<BODY>" );
				out.println( "<form method=\"post\" formaction=\"CFSecSMWarAddDeviceHtml\">" );
				out.println( "<H1 style=\"text-align:center\">" + clusterDescription + " Sec Manager</H1>" );
				out.println( "<p style=\"text-align:center\">Public Key must be specified." );
				out.println( "<H2 style=\"text-align:center\">Add new device for "
						+ secUser.getRequiredEMailAddress()
						+ "</H2>" );
				out.println( "<p>" );
				out.println( "<table style=\"width:90%\">" );
				out.println( "<tr><th style=\"text-align:left\">Device Name:</th><td><input type=\"text\" name=\"DeviceName\"/></td></tr>");
				out.println( "<tr><th style=\"text-align:left\">Public Key:</th><td><textarea name=\"PublicKey\" cols=\"60\" rows=\"10\"></textarea></td></tr>");
				out.println( "</table>" );
				out.println( "<p style=\"text-align:center\"><button type=\"submit\" name=\"Ok\"\">Add Device</button>&nbsp;&nbsp;&nbsp;&nbsp;<button type=\"button\" name=\"Cancel\"\" onclick=\"window.location.href='CFSecSMWarSecMainHtml'\">Cancel</button>" );
				out.println( "</form>" );
				out.println( "</BODY>" );
				out.println( "</HTML>" );
				return;
			}

			byte wrapped[] = Base64.decodeBase64( publicKey );

			X509EncodedKeySpec x509KeySpec = new X509EncodedKeySpec( wrapped );
			KeyFactory kf = KeyFactory.getInstance( "RSA" );
			if( kf == null ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"kf" );
			}

			PublicKey decodedPublicKey = kf.generatePublic( x509KeySpec );
			if( decodedPublicKey == null ) {
				response.setContentType( "text/html" );
				PrintWriter out = response.getWriter();
				out.println( "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01//EN\">" );
				out.println( "<HTML>" );
				out.println( "<BODY>" );
				out.println( "<form method=\"post\" formaction=\"CFSecSMWarAddDeviceHtml\">" );
				out.println( "<H1 style=\"text-align:center\">" + clusterDescription + " Sec Manager</H1>" );
				out.println( "<p style=\"text-align:center\">Public Key must be a valid RSA 2048 Key." );
				out.println( "<H2 style=\"text-align:center\">Add new device for "
						+ secUser.getRequiredEMailAddress()
						+ "</H2>" );
				out.println( "<p>" );
				out.println( "<table style=\"width:90%\">" );
				out.println( "<tr><th style=\"text-align:left\">Device Name:</th><td><input type=\"text\" name=\"DeviceName\"/></td></tr>");
				out.println( "<tr><th style=\"text-align:left\">Public Key:</th><td><textarea name=\"PublicKey\" cols=\"60\" rows=\"10\"></textarea></td></tr>");
				out.println( "</table>" );
				out.println( "<p style=\"text-align:center\"><button type=\"submit\" name=\"Ok\"\">Add Device</button>&nbsp;&nbsp;&nbsp;&nbsp;<button type=\"button\" name=\"Cancel\"\" onclick=\"window.location.href='CFSecSMWarSecMainHtml'\">Cancel</button>" );
				out.println( "</form>" );
				out.println( "</BODY>" );
				out.println( "</HTML>" );
				return;
			}

			ICFSecClusterObj systemCluster = schemaObj.getClusterTableObj().readClusterByUDomNameIdx( "system" );
			ICFSecTenantObj systemTenant = schemaObj.getTenantTableObj().readTenantByUNameIdx( systemCluster.getRequiredId(), "system" );
			ICFSecSecUserObj systemUser = schemaObj.getSecUserTableObj().readSecUserByULoginIdx( "system" );
			ICFSecSecSessionObj systemSession = schemaObj.getSecSessionTableObj().newInstance();
			ICFSecSecSessionEditObj editSystemSession = (ICFSecSecSessionEditObj)systemSession.beginEdit();
			editSystemSession.setRequiredContainerSecUser( systemUser );
			editSystemSession.setRequiredStart( Calendar.getInstance() );
			systemSession = editSystemSession.create();
			editSystemSession = null;

			CFSecAuthorization secAuth = new CFSecAuthorization();
			secAuth.setSecCluster( systemCluster );
			secAuth.setSecTenant( systemTenant );
			secAuth.setSecSession( systemSession );
			schemaObj.setAuthorization( secAuth );

			secDev = schemaObj.getSecDeviceTableObj().newInstance();
			ICFSecSecDeviceEditObj editDev = secDev.beginEdit();
			editDev.setRequiredContainerSecUser( secUser );
			editDev.setRequiredDevName( deviceName );
			editDev.setOptionalPubKey( publicKey );
			secDev = editDev.create();
			editDev = null;

			if( null == secUser.getOptionalLookupDefDev() ) {
				ICFSecSecUserEditObj editSecUser = secUser.beginEdit();
				editSecUser.setOptionalLookupDefDev( secDev );
				editSecUser.update();
				editSecUser = null;
			}

			editSystemSession = (ICFSecSecSessionEditObj)systemSession.beginEdit();
			editSystemSession.setOptionalFinish( Calendar.getInstance() );
			editSystemSession.update();
			editSystemSession = null;

			schemaObj.commit();

			schemaObj.setAuthorization( auth );

			response.sendRedirect( "CFSecSMWarSecMainHtml" );

		}
		catch( InvalidKeySpecException e ) {
			response.setContentType( "text/html" );
			PrintWriter out = response.getWriter();
			out.println( "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01//EN\">" );
			out.println( "<HTML>" );
			out.println( "<BODY>" );
			out.println( "<form method=\"post\" formaction=\"CFSecSMWarAddDeviceHtml\">" );
			out.println( "<H1 style=\"text-align:center\">" + clusterDescription + " Sec Manager</H1>" );
			out.println( "<p style=\"text-align:center\">Public Key must be a valid RSA 2048 Key." );
			out.println( "<H2 style=\"text-align:center\">Add new device for "
					+ secUser.getRequiredEMailAddress()
					+ "</H2>" );
			out.println( "<p>" );
			out.println( "<table style=\"width:90%\">" );
			out.println( "<tr><th style=\"text-align:left\">Device Name:</th><td><input type=\"text\" name=\"DeviceName\"/></td></tr>");
			out.println( "<tr><th style=\"text-align:left\">Public Key:</th><td><textarea name=\"PublicKey\" cols=\"60\" rows=\"10\"></textarea></td></tr>");
			out.println( "</table>" );
			out.println( "<p style=\"text-align:center\"><button type=\"submit\" name=\"Ok\"\">Add Device</button>&nbsp;&nbsp;&nbsp;&nbsp;<button type=\"button\" name=\"Cancel\"\" onclick=\"window.location.href='CFSecSMWarSecMainHtml'\">Cancel</button>" );
			out.println( "</form>" );
			out.println( "</BODY>" );
			out.println( "</HTML>" );
		}
		catch( NoSuchAlgorithmException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchAlgorithmException -- " + e.getMessage(),
				e );
		}
		catch( RuntimeException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught RuntimeException -- " + e.getMessage(),
				e );
		}
		finally {
			schemaObj.setAuthorization( auth );
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
