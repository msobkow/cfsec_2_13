
// Description: Java 11 XMsg Server Application Listener

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

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.lang.reflect.InvocationTargetException;
import java.security.*;
import java.security.cert.Certificate;
import java.security.cert.CertificateException;
import java.util.Date;
import java.util.Properties;

import javax.mail.*;
import javax.mail.internet.*;
import javax.naming.*;
import javax.servlet.*;
import javax.servlet.annotation.WebListener;

import com.sun.mail.smtp.SMTPTransport;

import org.msscf.msscf.cflib.CFLib.*;
import org.msscf.msscf.cflib.CFLib.Tip.CFTipServerInfo;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfsec.CFSecObj.*;

/**
 * Application Lifecycle Listener implementation class CFSecPgSqlWARApplicationListener
 *
 */
@WebListener
public class CFSecXMsgSrvWarApplicationListener implements ServletContextListener {
	protected String smtpUsername = null;
	protected String smtpPassword = null;
	protected volatile static PublicKey publicKey = null;
	protected volatile static PrivateKey privateKey = null;

	/**
	 * Default constructor. 
	 */
	public CFSecXMsgSrvWarApplicationListener() {
	}

	@Override
	public void contextDestroyed(ServletContextEvent arg0) {
	}

	private volatile static CFTipServerInfo serverInfo = null;

	public static CFTipServerInfo getServerInfo() {
		final String S_ProcName = "getServerInfo";
		if( serverInfo == null ) {
			serverInfo = new CFTipServerInfo();
			serverInfo.setSchemaName( "CFSec" );
			serverInfo.setSchemaDescr( "CFSec database instance" );
			if( privateKey != null ) {
				try {
					serverInfo.setServerKeys( publicKey, privateKey );
				}
				catch( Exception e ) {
					throw new CFLibRuntimeException( CFSecXMsgSrvWarApplicationListener.class,
						S_ProcName,
						"Caught " + e.getClass().getName() + " -- " + e.getMessage(),
						e );
				}
			}
		}
		return( serverInfo );
	}

	public static PublicKey getPublicKey() {
		return( publicKey );
	}

	public static PrivateKey getPrivateKey() {
		return( privateKey );
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

				String serverKeyStore;
				try {
					serverKeyStore = (String)ctx.lookup( "java:comp/env/CFSecServerKeyStore");
				}
				catch( NamingException e ) {
					serverKeyStore = null;
				}

				String keyStorePassword;
				try {
					keyStorePassword = (String)ctx.lookup( "java:comp/env/CFSecKeyStorePassword");
				}
				catch( NamingException e ) {
					keyStorePassword = null;
				}

				String keyName;
				try {
					keyName = (String)ctx.lookup( "java:comp/env/CFSecKeyName");
				}
				catch( NamingException e ) {
					keyName = null;
				}

				String keyPassword;
				try {
					keyPassword = (String)ctx.lookup( "java:comp/env/CFSecKeyPassword");
				}
				catch( NamingException e ) {
					keyPassword = null;
				}

				if( ( ( serverKeyStore != null ) && ( serverKeyStore.length() > 0 ) )
				 && ( keyStorePassword != null )
				 && ( ( keyName != null ) && ( keyName.length() > 0 ) )
				 && ( keyPassword != null ) )
				{
					KeyStore keyStore = null;
					File keystoreFile = new File( serverKeyStore );
					if( ! keystoreFile.exists() ) {
						throw new CFLibUsageException( getClass(),
							S_ProcName,
							"CFSecServerKeyStore file \"" + serverKeyStore + "\" does not exist." );
					}
					else if( ! keystoreFile.isFile() ) {
						throw new CFLibUsageException( getClass(),
							S_ProcName,
							"CFSecServerKeyStore file \"" + serverKeyStore + "\" is not a file." );
					}
					else if( ! keystoreFile.canRead() ) {
						throw new CFLibUsageException( getClass(),
							S_ProcName,
							"Permission denied attempting to read CFSecServerKeyStore file \"" + serverKeyStore + "\"." );
					}

					try {
						keyStore = KeyStore.getInstance( "jceks" );
						char[] caPassword = keyStorePassword.toCharArray();
						FileInputStream input = new FileInputStream( serverKeyStore );
						keyStore.load( input, caPassword );
						input.close();
						Certificate publicKeyCertificate = keyStore.getCertificate( keyName );
						if( publicKeyCertificate == null ) {
							throw new CFLibUsageException( getClass(),
								S_ProcName,
								"Could not read CFSecKeyName \"" + keyName + "\" from CFSecServerKeyStore file \"" + serverKeyStore + "\"." );
						}
						publicKey = publicKeyCertificate.getPublicKey();
						char[] caKeyPassword = keyPassword.toCharArray();
						Key key = keyStore.getKey( keyName, caKeyPassword );
						if( key instanceof PrivateKey ) {
							privateKey = (PrivateKey)key;
						}
						else {
							throw new CFLibUnsupportedClassException( getClass(),
								S_ProcName,
								"key",
								key,
								"PrivateKey" );
						}

						getServerInfo();
					}
					catch( CertificateException x ) {
						publicKey = null;
						privateKey = null;
						throw new CFLibRuntimeException( getClass(),
							S_ProcName,
							"Could not open keystore due to CertificateException -- " + x.getMessage(),
							x );
					}
					catch( IOException x ) {
						publicKey = null;
						privateKey = null;
						throw new CFLibRuntimeException( getClass(),
							S_ProcName,
							"Could not open keystore due to IOException -- " + x.getMessage(),
							x );
					}
					catch( KeyStoreException x ) {
						publicKey = null;
						privateKey = null;
						throw new CFLibRuntimeException( getClass(),
							S_ProcName,
							"Could not open keystore due to KeyStoreException -- " + x.getMessage(),
							x );
					}
					catch( NoSuchAlgorithmException x ) {
						publicKey = null;
						privateKey = null;
						throw new CFLibRuntimeException( getClass(),
							S_ProcName,
							"Could not open keystore due to NoSuchAlgorithmException -- " + x.getMessage(),
							x );
					}
					catch( UnrecoverableKeyException x ) {
						publicKey = null;
						privateKey = null;
						throw new CFLibRuntimeException( getClass(),
							S_ProcName,
							"Could not access key due to UnrecoverableKeyException -- " + x.getMessage(),
							x );
					}
					catch( RuntimeException x ) {
						publicKey = null;
						privateKey = null;
						throw x;
					}
				}
				else if( ( serverKeyStore != null )
				 || ( keyStorePassword != null )
				 || ( keyName != null )
				 || ( keyPassword != null ) )
				{
					publicKey = null;
					privateKey = null;
					throw new CFLibUsageException( getClass(),
						S_ProcName,
						"All or none of CFSecServerKeyStore, "
							+ "CFSecKeyStorePassword, "
							+ "CFSecKeyName, and "
							+ "CFSecKeyPassword must be configured" );
				}
				else {
					getServerInfo();
					try {
						serverInfo.initServerKeys();
					}
					catch( Exception x ) {
						throw new CFLibRuntimeException( getClass(),
							S_ProcName,
							"Caught " + x.getClass().getName() + " during initServerKeys() -- " + x.getMessage(),
							x );
					}
				}
			}
			catch( ClassNotFoundException e ) {
				publicKey = null;
				privateKey = null;
				throw new CFLibRuntimeException( getClass(),
					S_ProcName,
					"Caught ClassNotFoundException -- " + e.getMessage(),
					e );
			}
			catch( IllegalAccessException e ) {
				publicKey = null;
				privateKey = null;
				throw new CFLibRuntimeException( getClass(),
					S_ProcName,
					"Caught IllegalAccessException trying to construct newInstance() -- " + e.getMessage(),
					e );
			}
			catch( InstantiationException e ) {
				publicKey = null;
				privateKey = null;
				throw new CFLibRuntimeException( getClass(),
					S_ProcName,
					"Caught InstantiationException trying to construct newInstance() -- " + e.getMessage(),
					e );
			}
			catch( NamingException e ) {
				publicKey = null;
				privateKey = null;
				throw new CFLibRuntimeException( getClass(),
					S_ProcName,
					"Caught NamingException -- " + e.getMessage(),
					e );
			}
		}
	}
}
