
// Description: Java 11 XMsg Server Utilities

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

package org.msscf.msscf.cfsec.CFSecXMsgSrvWar;

import java.io.*;
import java.security.*;
import java.util.*;

import javax.mail.*;
import javax.mail.internet.*;
import javax.naming.*;

import org.msscf.msscf.cflib.CFLib.*;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfsec.CFSecObj.*;

public class CFSecXMsgSrvWarUtil {
	private static final long serialVersionUID = 1L;

	protected String smtpUsername = null;
	protected String smtpPassword = null;

	public CFSecXMsgSrvWarUtil() {
		super();
	}

	public void sendEMailToUser(
		ICFSecSecUserObj toUser,
		String msgSubject,
		String msgBody )
	throws
		IOException,
		MessagingException,
		NamingException
	{

		final String S_ProcName = "sendEMailToUser";

		Properties props = System.getProperties();

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

		MimeMessage msg = new MimeMessage( emailSess );
		msg.setFrom( new InternetAddress( smtpEmailFrom ) );
		InternetAddress mailTo[] = InternetAddress.parse( toUser.getRequiredEMailAddress(), false );
		msg.setRecipient( Message.RecipientType.TO, mailTo[0] );
		msg.setSubject( ( msgSubject != null ) ? msgSubject : "No subject" );
		msg.setSentDate( new Date() );
		msg.setContent( msgBody, "text/html" );
		msg.saveChanges();

		Transport.send( msg );
	}

}
