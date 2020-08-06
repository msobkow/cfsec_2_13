
// Description: Java 11 Sec Manager Request Reset Password Servlet

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
import java.util.Date;
import java.util.Properties;
import java.util.UUID;

import javax.mail.*;
import javax.mail.internet.*;
import javax.naming.*;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.*;
import javax.sql.DataSource;

import org.apache.commons.codec.binary.Base64;

import org.msscf.msscf.cflib.CFLib.*;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfsec.CFSecObj.*;

/**
 * Servlet implementation class CFSecSMWarRequestResetPasswordHtml
 */
@WebServlet("/CFSecSMWarRequestResetPasswordHtml")
public class CFSecSMWarRequestResetPasswordHtml extends HttpServlet {
	private static final long serialVersionUID = 1L;

	protected String smtpUsername = null;
	protected String smtpPassword = null;

	/**
	 * @see HttpServlet#HttpServlet()
	 */
	public CFSecSMWarRequestResetPasswordHtml() {
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

		ICFSecSchema dbSchema = null;
		try {
			CFSecAuthorization auth = schemaObj.getAuthorization();
			if( auth != null ) {
				response.sendRedirect( "CFSecSMWarSecMainHtml" );
				return;
			}

			dbSchema = (ICFSecSchema)CFSecSchemaPool.getSchemaPool().getInstance();
			schemaObj.setBackingStore( dbSchema );
			schemaObj.beginTransaction();
			ICFSecSecUserObj systemUser = schemaObj.getSecUserTableObj().readSecUserByULoginIdx( "system" );
			String passwordHash = systemUser.getRequiredPasswordHash();
			if( ( passwordHash == null ) || ( passwordHash.length() <= 0 ) || passwordHash.equals( "bootstrap" ) ) {
				response.sendRedirect( "CFSecSMWarSetSystemPasswordHtml" );
				return;
			}

			ICFSecSysClusterObj sysCluster = schemaObj.getSysClusterTableObj().readSysClusterByIdIdx( 1, false );
			if( sysCluster == null ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"sysCluster" );
			}

			ICFSecClusterObj resolvedCluster = sysCluster.getRequiredContainerCluster();
			if( resolvedCluster == null ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					"resolvedCluster" );
			}
			String clusterDomName = resolvedCluster.getRequiredFullDomName();
			String clusterDescription = resolvedCluster.getRequiredDescription();

			response.setContentType( "text/html" );
			PrintWriter out = response.getWriter();
			out.println( "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01//EN\">" );
			out.println( "<HTML>" );
			out.println( "<BODY>" );
			out.println( "<form method=\"post\" formaction=\"CFSecSMWarRequestResetPasswordHtml\">" );
			out.println( "<H1 style=\"text-align:center\">" + clusterDescription + " Sec Manager</H1>" );
			out.println( "<H2 style=\"text-align:center\">Enter the login you'd like to request a password reset for.</H2>" );
			out.println( "<p>" );
			out.println( "<center>" );
			out.println( "<table style=\"width:60%\">" );
			out.println( "<tr><th style=\"text-align:left\">Login Id:</th><td><input type=\"text\" name=\"LoginId\"/></td></tr>");
			out.println( "<tr><td colspan=\"2\" style=\"text-align:center\"><button type=\"submit\" name=\"Ok, Request Password Reset\"\">Ok</button></td></tr>" );
			out.println( "<tr><td colSpan=\"2\" style=\"text-align:center\"><A HRef=\"CFSecSMWarLoginHtml\">Back to " + clusterDescription + " Sec Manager Login</A></td></tr>" );
			out.println( "</table>" );
			out.println( "</center>" );
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
				schemaObj = new CFSecSchemaPooledObj();
				sess.setAttribute( "SchemaObj", schemaObj );
			}
		}

		ICFSecSchema dbSchema = null;
		try {
			CFSecAuthorization auth = schemaObj.getAuthorization();
			if( auth != null ) {
				response.sendRedirect( "CFSecSMWarSecMainHtml" );
				return;
			}

			dbSchema = (ICFSecSchema)CFSecSchemaPool.getSchemaPool().getInstance();
			schemaObj.setBackingStore( dbSchema );
			schemaObj.beginTransaction();
			ICFSecSecUserObj systemUser = schemaObj.getSecUserTableObj().readSecUserByULoginIdx( "system" );
			String passwordHash = systemUser.getRequiredPasswordHash();
			if( ( passwordHash == null ) || ( passwordHash.length() <= 0 ) || passwordHash.equals( "bootstrap" ) ) {
				response.sendRedirect( "CFSecSMWarSetSystemPasswordHtml" );
			}

			ICFSecClusterObj resolvedCluster;
			ICFSecSysClusterObj sysCluster = schemaObj.getSysClusterTableObj().readSysClusterByIdIdx( 1, false );
			if( sysCluster == null ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"sysCluster" );
			}
			resolvedCluster = sysCluster.getRequiredContainerCluster();
			if( resolvedCluster == null ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					"resolvedCluster" );
			}
			String clusterDomName = resolvedCluster.getRequiredFullDomName();
			String clusterDescription = resolvedCluster.getRequiredDescription();

			String loginId = (String)request.getParameter( "LoginId" );
			if( ( loginId == null ) || ( loginId.length() <= 0 ) ) {
				response.setContentType( "text/html" );
				PrintWriter out = response.getWriter();
				out.println( "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01//EN\">" );
				out.println( "<HTML>" );
				out.println( "<BODY>" );
				out.println( "<form method=\"post\" formaction=\"CFSecSMWarRequestResetPasswordHtml\">" );
				out.println( "<H1 style=\"text-align:center\">" + clusterDescription + " Sec Manager</H1>" );
				out.println( "<H2 style=\"text-align:center\">ERROR</H2>" );
				out.println( "<p style=\"text-align:center\">" );
				out.println( "You must specify a login id to reset." );
				out.println( "<p style=\"text-align:center\">" );
				out.println( "Enter the login you'd like to request a password reset for." );
				out.println( "<p>" );
				out.println( "<center>" );
				out.println( "<table style=\"width:60%\">" );
				out.println( "<tr><th style=\"text-align:left\">Login Id:</th><td><input type=\"text\" name=\"LoginId\"/></td></tr>");
				out.println( "<tr><td colspan=\"2\" style=\"text-align:center\"><button type=\"submit\" name=\"Ok, Request Password Reset\"\">Ok</button></td></tr>" );
				out.println( "<tr><td colSpan=\"2\" style=\"text-align:center\"><A HRef=\"CFSecSMWarLoginHtml\">Back to " + clusterDescription + " Sec Manager Login</A></td></tr>" );
				out.println( "</table>" );
				out.println( "</center>" );
				out.println( "</form>" );
				out.println( "</BODY>" );
				out.println( "</HTML>" );
				return;
			}

			ICFSecSecUserObj authenticatingUser = schemaObj.getSecUserTableObj().readSecUserByULoginIdx( loginId, true );
			if( authenticatingUser == null ) {
				response.setContentType( "text/html" );
				PrintWriter out = response.getWriter();
				out.println( "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01//EN\">" );
				out.println( "<HTML>" );
				out.println( "<BODY>" );
				out.println( "<form method=\"post\" formaction=\"CFSecSMWarRequestResetPasswordHtml\">" );
				out.println( "<H1 style=\"text-align:center\">" + clusterDescription + " Sec Manager</H1>" );
				out.println( "<H2 style=\"text-align:center\">ERROR</H2>" );
				out.println( "<p style=\"text-align:center\">" );
				out.println( "Login id not found." );
				out.println( "<p style=\"text-align:center\">" );
				out.println( "Enter the login you'd like to request a password reset for." );
				out.println( "<p>" );
				out.println( "<center>" );
				out.println( "<table style=\"width:60%\">" );
				out.println( "<tr><th style=\"text-align:left\">Login Id:</th><td><input type=\"text\" name=\"LoginId\"/></td></tr>");
				out.println( "<tr><td colspan=\"2\" style=\"text-align:center\"><button type=\"submit\" name=\"Ok, Request Password Reset\"\">Ok</button></td></tr>" );
				out.println( "<tr><td colSpan=\"2\" style=\"text-align:center\"><A HRef=\"CFSecSMWarLoginHtml\">Back to " + clusterDescription + " Sec Manager Login</A></td></tr>" );
				out.println( "</table>" );
				out.println( "</center>" );
				out.println( "</form>" );
				out.println( "</BODY>" );
				out.println( "</HTML>" );
				return;
			}

			if( null != authenticatingUser.getOptionalPasswordResetUuid() ) {

				sendPasswordResetEMail( request, authenticatingUser, resolvedCluster );

				response.setContentType( "text/html" );
				PrintWriter out = response.getWriter();
				out.println( "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01//EN\">" );
				out.println( "<HTML>" );
				out.println( "<BODY>" );
				out.println( "<form method=\"post\" formaction=\"CFSecSMWarRequestResetPasswordHtml\">" );
				out.println( "<H1 style=\"text-align:center\">" + clusterDescription + " Sec Manager</H1>" );
				out.println( "<H2 style=\"text-align:center\">INFO</H2>" );
				out.println( "<p style=\"text-align:center\">" );
				out.println( "Password reset email resent." );
				out.println( "<center>" );
				out.println( "<table style=\"width:60%\">" );
				out.println( "<tr><td colSpan=\"2\" style=\"text-align:center\"><A HRef=\"CFSecSMWarLoginHtml\">Back to " + clusterDescription + " Sec Manager Login</A></td></tr>" );
				out.println( "</table>" );
				out.println( "</center>" );
				out.println( "</form>" );
				out.println( "</BODY>" );
				out.println( "</HTML>" );
			}

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

			ICFSecSecUserEditObj editAuthenticatingUser = authenticatingUser.beginEdit();
			editAuthenticatingUser.setOptionalPasswordResetUuid( UUID.randomUUID() );
			editAuthenticatingUser.update();
			editAuthenticatingUser = null;

			editSystemSession = (ICFSecSecSessionEditObj)systemSession.beginEdit();
			editSystemSession.setOptionalFinish( Calendar.getInstance() );
			editSystemSession.update();
			editSystemSession = null;

			schemaObj.setAuthorization( null );

			schemaObj.commit();

			sendPasswordResetEMail( request, authenticatingUser, resolvedCluster );

			response.setContentType( "text/html" );
			PrintWriter out = response.getWriter();
			out.println( "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01//EN\">" );
			out.println( "<HTML>" );
			out.println( "<BODY>" );
			out.println( "<form method=\"post\" formaction=\"CFSecSMWarRequestResetPasswordHtml\">" );
			out.println( "<H1 style=\"text-align:center\">" + clusterDescription + " Sec Manager</H1>" );
			out.println( "<H2 style=\"text-align:center\">INFO</H2>" );
			out.println( "<p style=\"text-align:center\">" );
			out.println( "Password reset email sent.  Please use the links in the email to set a new password or to cancel the request." );
			out.println( "<center>" );
			out.println( "<table style=\"width:60%\">" );
			out.println( "<tr><td colSpan=\"2\" style=\"text-align:center\"><A HRef=\"CFSecSMWarLoginHtml\">Back to " + clusterDescription + " Sec Manager Login</A></td></tr>" );
			out.println( "</table>" );
			out.println( "</center>" );
			out.println( "</form>" );
			out.println( "</BODY>" );
			out.println( "</HTML>" );
		}
		catch( MessagingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught MessagingException -- " + e.getMessage(),
				e );
		}
		catch( NamingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NamingException -- " + e.getMessage(),
				e );
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

	protected void sendPasswordResetEMail(
		HttpServletRequest request,
		ICFSecSecUserObj resetUser,
		ICFSecClusterObj cluster )
	throws
		AddressException,
		MessagingException,
		NamingException 
	{

		final String S_ProcName = "sendPasswordResetEMail";

		Properties props = System.getProperties();
		String clusterDescription = cluster.getRequiredDescription();

		Context ctx = new InitialContext();

		String smtpEmailFrom = (String)ctx.lookup( "java:comp/env/CFSecSmtpEmailFrom");
		if( ( smtpEmailFrom == null ) || ( smtpEmailFrom.length() <= 0 ) ) {
			throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"JNDI lookup for CFSecSmtpEmailFrom" );
		}

		smtpUsername = (String)ctx.lookup( "java:comp/env/CFSecSmtpUsername");
		if( ( smtpUsername == null ) || ( smtpUsername.length() <= 0 ) ) {
			throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"JNDI lookup for CFSecSmtpUsername" );
		}

		smtpPassword = (String)ctx.lookup( "java:comp/env/CFSecSmtpPassword");
		if( ( smtpPassword == null ) || ( smtpPassword.length() <= 0 ) ) {
			throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"JNDI lookup for CFSecSmtpPassword" );
		}

		Session emailSess = Session.getInstance( props,
			new Authenticator() {
				protected PasswordAuthentication getPasswordAuthentication() {
					return new PasswordAuthentication( smtpUsername, smtpPassword );
				}
			} );

		String thisURI = request.getScheme()
			+	"://"
			+	request.getServerName()
			+	":"
			+	request.getServerPort()
			+	request.getRequestURI().toString();
		int lastSlash = thisURI.lastIndexOf( '/' );
		String baseURI = thisURI.substring( 0, lastSlash );
		UUID resetUUID = resetUser.getOptionalPasswordResetUuid();

		String msgBody =
				"<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01//EN\">\n"
			+	"<HTML>\n"
			+	"<BODY>\n"
			+	"<p>\n"
			+	"You requested a password reset for " + resetUser.getRequiredEMailAddress() + " used for accessing " + clusterDescription + ".\n"
			+	"<p>"
			+	"Please click on the following link to reset your password:<br>\n"
			+	"<A HRef=\"" + baseURI + "/CFSecSMWarResetPasswordHtml?ResetUUID=" + resetUUID.toString() + "\">"
			+		 baseURI + "/CFSecSMWarResetPasswordHtml?ResetUUID=" + resetUUID.toString() + "</A>\n"
			+	"<p>"
			+	"Or click on the following link to cancel the reset request:<br>\n"
			+	"<A HRef=\"" + baseURI + "/CFSecSMWarCancelResetPasswordHtml?ResetUUID=" + resetUUID.toString() + "\">"
			+		 baseURI + "/CFSecSMWarCancelResetPasswordHtml?ResetUUID=" + resetUUID.toString() + "</A>\n"
			+	"</BODY>\n"
			+	"</HTML>\n";

		MimeMessage msg = new MimeMessage( emailSess );
		msg.setFrom( new InternetAddress( smtpEmailFrom ) );
		InternetAddress mailTo[] = InternetAddress.parse( resetUser.getRequiredEMailAddress(), false );
		msg.setRecipient( Message.RecipientType.TO, mailTo[0] );
		msg.setSubject( "You requested a password reset for your account with " + clusterDescription + "?" );
		msg.setContent( msgBody, "text/html" );
		msg.setSentDate( new Date() );
		msg.saveChanges();

		Transport.send( msg );
	}
}
