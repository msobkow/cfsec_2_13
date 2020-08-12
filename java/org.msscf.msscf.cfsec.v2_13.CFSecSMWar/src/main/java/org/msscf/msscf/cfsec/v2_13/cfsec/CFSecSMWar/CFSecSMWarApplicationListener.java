
// Description: Java 11 Sec Manager Application Listener

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

package org.msscf.msscf.cfsec.v2_13.cfsec.CFSecSMWar;

import java.lang.reflect.InvocationTargetException;
import java.security.Security;
import java.util.Date;
import java.util.Properties;

import javax.mail.*;
import javax.mail.internet.*;
import javax.naming.*;
import javax.servlet.*;
import javax.servlet.annotation.WebListener;

import com.sun.mail.smtp.SMTPTransport;

import org.msscf.msscf.cflib.v2_13.CFLib.*;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfsec.CFSecObj.*;

/**
 * Application Lifecycle Listener implementation class CFSecPgSqlWARApplicationListener
 *
 */
@WebListener
public class CFSecSMWarApplicationListener implements ServletContextListener {
	protected String smtpUsername = null;
	protected String smtpPassword = null;

	/**
	 * Default constructor. 
	 */
	public CFSecSMWarApplicationListener() {
	}

	@Override
	public void contextDestroyed(ServletContextEvent arg0) {
	}

	@Override
	public void contextInitialized(ServletContextEvent arg0) {
		final String S_ProcName = "contextInitialized";

		Properties props = System.getProperties();
		if( null == CFSecSchemaPool.getSchemaPool() ) {
			try {
				Context ctx = new InitialContext();
				String poolClassName = (String)ctx.lookup( "java:comp/env/CFSecPoolClass");
				if( ( poolClassName == null ) || ( poolClassName.length() <= 0 ) ) {
					throw new CFLibNullArgumentException( getClass(),
						S_ProcName,
						0,
						"JNDI lookup for CFSecPoolClass" );
				}

				Class<?> poolClass = Class.forName( poolClassName );
				if( poolClass == null ) {
					throw new CFLibNullArgumentException( getClass(),
						S_ProcName,
						0,
						"CFSecPoolClass \"" + poolClassName + "\" not found." );
				}

				Object obj = null;
				try {
					obj = poolClass.getDeclaredConstructor().newInstance();
				}
				catch( InvocationTargetException e ) {
					throw new CFLibRuntimeException( getClass(),
						S_ProcName,
						"Mapped InvocationTargetException poolClass declared constructor threw an exception",
						e );
				}
				catch( NoSuchMethodException e ) {
					throw new CFLibRuntimeException( getClass(),
						S_ProcName,
						"Mapped NoSuchMethodException poolClass has no declared constructor",
						e );
				}
				if( obj instanceof CFSecSchemaPool ) {
					CFSecSchemaPool newPool = (CFSecSchemaPool)obj;
					newPool.setConfigurationFile( null );
					newPool.setJndiName( "java:comp/env/CFSecConnection" );
					CFSecSchemaPool.setSchemaPool( newPool );
				}
				else {
					throw new CFLibRuntimeException( getClass(),
						S_ProcName,
						"Problems constructing an instance of " + poolClassName );
				}

				String smtpHost = (String)ctx.lookup( "java:comp/env/CFSecSmtpHost");
				if( ( smtpHost == null ) || ( smtpHost.length() <= 0 ) ) {
					throw new CFLibNullArgumentException( getClass(),
							S_ProcName,
							0,
							"JNDI lookup for CFSecSmtpHost" );
				}
				props.setProperty( "mail.smtp.host", smtpHost );

				String smtpStartTLS = (String)ctx.lookup( "java:comp/env/CFSecSmtpStartTLS");
				if( ( smtpHost == null ) || ( smtpHost.length() <= 0 ) ) {
					throw new CFLibNullArgumentException( getClass(),
							S_ProcName,
							0,
							"JNDI lookup for CFSecSmtpStartTLS" );
				}
				props.setProperty( "mail.smtp.starttls.enable", smtpStartTLS );

				String smtpSocketFactoryClass = (String)ctx.lookup( "java:comp/env/CFSecSmtpSocketFactoryClass");
				if( ( smtpSocketFactoryClass == null ) || ( smtpSocketFactoryClass.length() <= 0 ) ) {
					throw new CFLibNullArgumentException( getClass(),
							S_ProcName,
							0,
							"JNDI lookup for CFSecSmtpSocketFactoryClass" );
				}
				props.setProperty( "mail.smtp.socketFactory.class", smtpSocketFactoryClass );

				props.setProperty( "mail.smtp.socketFactory.fallback", "false" );

				String smtpPort = (String)ctx.lookup( "java:comp/env/CFSecSmtpPort");
				if( ( smtpPort == null ) || ( smtpPort.length() <= 0 ) ) {
					throw new CFLibNullArgumentException( getClass(),
							S_ProcName,
							0,
							"JNDI lookup for CFSecSmtpPort" );
				}
				props.setProperty( "mail.smtp.port", smtpPort );
				props.setProperty( "mail.smtp.socketFactory.port", smtpPort );

				props.setProperty( "mail.smtps.auth", "true" );

				props.put( "mail.smtps.quitwait", "false" );

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

			}
			catch( ClassNotFoundException e ) {
				throw new CFLibRuntimeException( getClass(),
					S_ProcName,
					"Caught ClassNotFoundException -- " + e.getMessage(),
					e );
			}
			catch( IllegalAccessException e ) {
				throw new CFLibRuntimeException( getClass(),
					S_ProcName,
					"Caught IllegalAccessException trying to construct newInstance() -- " + e.getMessage(),
					e );
			}
			catch( InstantiationException e ) {
				throw new CFLibRuntimeException( getClass(),
					S_ProcName,
					"Caught InstantiationException trying to construct newInstance() -- " + e.getMessage(),
					e );
			}
			catch( NamingException e ) {
				throw new CFLibRuntimeException( getClass(),
					S_ProcName,
					"Caught NamingException -- " + e.getMessage(),
					e );
			}
		}
	}
}
