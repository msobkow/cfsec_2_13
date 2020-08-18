
// Description: Java 11 XMsg Server Add Device Servlet

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

package org.msscf.msscf.v2_13.cfsec.cfsec.CFSecXMsgSrvWar;

import java.io.*;
import java.nio.charset.Charset;
import java.security.*;
import java.util.*;

import javax.crypto.IllegalBlockSizeException;
import javax.crypto.NoSuchPaddingException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.*;

import org.apache.commons.codec.binary.Base64;
import org.apache.commons.io.output.WriterOutputStream;

import org.msscf.msscf.v2_13.cflib.CFLib.*;
import org.msscf.msscf.v2_13.cflib.CFLib.ICFLibMessageLog;
import org.msscf.msscf.v2_13.cflib.CFLib.Tip.CFTipEnvelopeHandler;
import org.msscf.msscf.v2_13.cflib.CFLib.Tip.CFTipServerInfo;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfsec.CFSecObj.*;
import org.msscf.msscf.v2_13.cfsec.cfsec.CFSecXMsgRqst.CFSecXMsgRqst;

/**
 * Servlet implementation class CFSecXMsgSrvWarRequestXml
 */
@WebServlet("/CFSecXMsgSrvWarRequestXml")
public class CFSecXMsgSrvWarRequestXml extends HttpServlet {
	private static final long serialVersionUID = 1L;

	protected MessageLogHandler log = new MessageLogHandler();
	protected PrintWriter printWriter = null;
	protected PrintStream printStream = null;
	protected int indent = 0;

	public class MessageLogHandler implements ICFLibMessageLog {

		public MessageLogHandler() {
			printWriter = null;
			printStream = null;
			indent = 0;
		}

		public void setPrintWriter( PrintWriter value ) {
			if( value == null ) {
				printWriter = null;
				printStream = null;
				indent = 0;
			}
			else {
				indent = 0;
				printWriter = value;
				WriterOutputStream writerOutputStream = new WriterOutputStream( printWriter, Charset.forName( "UTF-8" ) );
				printStream = new PrintStream( writerOutputStream );
			}
		}

		public String getBacklog() {
			return( null );
		}

		public PrintStream getPrintStream() {
			if( printStream == null ) {
				WriterOutputStream writerOutputStream = new WriterOutputStream( printWriter, Charset.forName( "UTF-8" ) );
				printStream = new PrintStream( writerOutputStream );
			}
			return( printStream );
		}

		public int getMessageLogIndent() {
			return indent;
		}

		public void indent() {
			indent ++;
		}

		public void dedent() {
			if( indent > 0 ) {
				indent --;
			}
			else {
				indent = 0;
			}
		}

		public void message(String msg) {

			if( msg == null ) {
				return;
			}

			StringBuffer buff = new StringBuffer();

			Calendar cal = Calendar.getInstance();
			String stamp = String.format( "%1$tY-%1$tm-%1$td %1$tH:%1$tM:%1$tS.%1$tL ", cal );
			buff.append( stamp );

			int			i;
			for( i = 0; i < indent; i ++ ) {
				buff.append( "\t" );
			}
			buff.append( msg );
			if( ! msg.endsWith( "\n" ) ) {
				buff.append( "\n" );
			}

			if( printStream != null ) {
				printStream.append( buff.toString() );
				printStream.flush();
			}
		}

		public void openLogFile(String fileName) throws FileNotFoundException {
			throw new CFLibNotImplementedYetException( getClass(),
				"openLogFile" );
		}

		public void closeLogFile() {
			throw new CFLibNotImplementedYetException( getClass(),
					"openLogFile" );
		}
	}

	/**
	 * @see HttpServlet#HttpServlet()
	 */
	public CFSecXMsgSrvWarRequestXml() {
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

		CFTipServerInfo serverInfo = CFSecXMsgSrvWarApplicationListener.getServerInfo();

		CFTipEnvelopeHandler envelopeHandler = (CFTipEnvelopeHandler)sess.getAttribute( "CFTipEnvelopeHandler" );
		if( envelopeHandler == null ) {
			envelopeHandler = new CFTipEnvelopeHandler();
			envelopeHandler.setLog( log );
			CFSecXMsgRqst requestHandler = new CFSecXMsgRqst();
			requestHandler.setSchemaObj( schemaObj );
			envelopeHandler.setRequestHandler( requestHandler );
			envelopeHandler.setServerInfo( serverInfo );
			sess.setAttribute( "CFTipEnvelopeHandler", envelopeHandler );
		}

		ICFSecSchema dbSchema = null;
		try {
			dbSchema = (ICFSecSchema)CFSecSchemaPool.getSchemaPool().getInstance();
			schemaObj.setBackingStore( dbSchema );
			schemaObj.beginTransaction();

			ICFSecSysClusterObj sysCluster = schemaObj.getSysClusterTableObj().readSysClusterByIdIdx( 1, false );
			if( sysCluster == null ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"SysCluster" );
			}

			ICFSecClusterObj secCluster = sysCluster.getRequiredContainerCluster();
			if( secCluster == null ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"SysCluster.Cluster" );
			}

			if( null == serverInfo.getClusterDescr() ) {
				serverInfo.setClusterDescr( secCluster.getRequiredDescription() );
				serverInfo.setClusterURL( secCluster.getRequiredFullDomName() );
			}

			String clusterDescription = serverInfo.getClusterDescr();

			response.setContentType( "text/html" );
			PrintWriter out = response.getWriter();
			out.println( "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01//EN\">" );
			out.println( "<HTML>" );
			out.println( "<BODY>" );
			out.println( "<form method=\"post\" formaction=\"CFSecXMsgSrvWarRequestXml\">" );
			out.println( "<H1 style=\"text-align:center\">" + clusterDescription + " XMsg Server</H1>" );
			out.println( "<H2 style=\"text-align:center\"> Enter a CFTipEnvelopeHandler XML request message to process</H2>" );
			out.println( "<p>" );
			out.println( "<table style=\"width:90%\">" );
			out.println( "<tr><th style=\"text-align:left\">Message Body:</th><td><textarea name=\"MessageBody\" cols=\"60\" rows=\"10\"></textarea></td></tr>");
			out.println( "</table>" );
			out.println( "<p style=\"text-align:center\"><button type=\"submit\" name=\"Ok\"\">Submit Request</button>&nbsp;&nbsp;&nbsp;&nbsp;<button type=\"button\" name=\"Cancel\"\" onclick=\"window.location.href='CFSecXMsgSrvWarRequestXml'\">Cancel;</button>" );
			out.println( "</form>" );
			out.println( "</BODY>" );
			out.println( "</HTML>" );
		}
		finally {
			if( dbSchema != null ) {
				try {
					if( schemaObj.isTransactionOpen() ) { 
						schemaObj.rollback();
					}
					schemaObj.minimizeMemory();
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

		CFTipServerInfo serverInfo = CFSecXMsgSrvWarApplicationListener.getServerInfo();

		CFTipEnvelopeHandler envelopeHandler = (CFTipEnvelopeHandler)sess.getAttribute( "CFTipEnvelopeHandler" );
		if( envelopeHandler == null ) {
			envelopeHandler = new CFTipEnvelopeHandler();
			envelopeHandler.setLog( log );
			CFSecXMsgRqst requestHandler = new CFSecXMsgRqst();
			requestHandler.setSchemaObj( schemaObj );
			envelopeHandler.setRequestHandler( requestHandler );
			envelopeHandler.setServerInfo( serverInfo );
			sess.setAttribute( "CFTipEnvelopeHandler", envelopeHandler );
		}

		String clusterDescription = "";

		ICFSecSchema dbSchema = null;
		try {
			dbSchema = (ICFSecSchema)CFSecSchemaPool.getSchemaPool().getInstance();
			schemaObj.setBackingStore( dbSchema );
			schemaObj.beginTransaction();

			ICFSecSysClusterObj sysCluster = schemaObj.getSysClusterTableObj().readSysClusterByIdIdx( 1, false );
			if( sysCluster == null ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"SysCluster" );
			}

			ICFSecClusterObj secCluster = sysCluster.getRequiredContainerCluster();
			if( secCluster == null ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"SysCluster.Cluster" );
			}

			if( serverInfo.getClusterDescr() == null ) {
				serverInfo.setClusterDescr( secCluster.getRequiredDescription() );
				serverInfo.setClusterURL( secCluster.getRequiredFullDomName() );
			}

			clusterDescription = serverInfo.getClusterDescr();

			// envelopeHandler.setLog( log );

			String messageBody = request.getParameter( "MessageBody" );
			if( ( messageBody == null ) || ( messageBody.length() <= 0 ) ) {
				response.setContentType( "text/html" );
				PrintWriter out = response.getWriter();
				out.println( "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01//EN\">" );
				out.println( "<HTML>" );
				out.println( "<BODY>" );
				out.println( "<form method=\"post\" formaction=\"CFSecXMsgSrvWarRequestXml\">" );
				out.println( "<H1 style=\"text-align:center\">" + clusterDescription + " XMsg Server</H1>" );
				out.println( "<H2 style=\"text-align:center\"> Enter a CFTipEnvelopeHandler XML request message to process</H2>" );
				out.println( "<p>" );
				out.println( "<table style=\"width:90%\">" );
				out.println( "<tr><th style=\"text-align:left\">Message Body:</th><td><textarea name=\"MessageBody\" cols=\"60\" rows=\"10\"></textarea></td></tr>");
				out.println( "</table>" );
				out.println( "<p style=\"text-align:center\"><button type=\"submit\" name=\"Ok\"\">Submit Request</button>&nbsp;&nbsp;&nbsp;&nbsp;<button type=\"button\" name=\"Cancel\"\" onclick=\"window.location.href='CFSecXMsgSrvWarRequestXml'\">Cancel;</button>" );
				out.println( "</form>" );
				out.println( "</BODY>" );
				out.println( "</HTML>" );
				return;
			}

			PrintWriter out = response.getWriter();
			log.setPrintWriter( out );
			envelopeHandler.parseStringContents( messageBody );
			response.setContentType( "text/plain" );
			String rspnBase64EncodedEncryptedSessionBlock = envelopeHandler.getResponse();
			out.append( rspnBase64EncodedEncryptedSessionBlock );
			out.flush();
		}
		finally {
			if( dbSchema != null ) {
				try {
					if( schemaObj.isTransactionOpen() ) { 
						schemaObj.rollback();
					}
					schemaObj.minimizeMemory();
				}
				catch( RuntimeException e ) {
				}
				schemaObj.setBackingStore( null );
				CFSecSchemaPool.getSchemaPool().releaseInstance( dbSchema );
			}
		}
	}
}
