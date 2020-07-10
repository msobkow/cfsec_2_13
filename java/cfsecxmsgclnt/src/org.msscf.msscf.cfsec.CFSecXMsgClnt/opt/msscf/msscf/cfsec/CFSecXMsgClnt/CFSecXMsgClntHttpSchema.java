// Description: Java 11 XMsg Client HTTP DbIO implementation for CFSec.

/*
 *	com.github.msobkow.CFSec
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

package com.github.msobkow.cfsec.CFSecXMsgClnt;

import java.io.IOException;
import java.io.InputStreamReader;
import java.io.Reader;
import java.io.UnsupportedEncodingException;
import java.nio.charset.Charset;
import java.security.InvalidAlgorithmParameterException;
import java.security.InvalidKeyException;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.security.spec.InvalidKeySpecException;
import java.util.ArrayList;
import java.util.List;

import javax.crypto.BadPaddingException;
import javax.crypto.IllegalBlockSizeException;
import javax.crypto.NoSuchPaddingException;

import org.apache.commons.codec.binary.Base64;
import org.apache.http.Consts;
import org.apache.http.HttpEntity;
import org.apache.http.NameValuePair;
import org.apache.http.StatusLine;
import org.apache.http.client.CookieStore;
import org.apache.http.client.HttpResponseException;
import org.apache.http.client.entity.UrlEncodedFormEntity;
import org.apache.http.client.methods.CloseableHttpResponse;
import org.apache.http.client.methods.HttpPost;
import org.apache.http.client.protocol.HttpClientContext;
import org.apache.http.entity.ContentType;
import org.apache.http.impl.client.BasicCookieStore;
import org.apache.http.impl.client.CloseableHttpClient;
import org.apache.http.impl.client.HttpClients;
import org.apache.http.message.BasicNameValuePair;

import com.github.msobkow.cflib.CFLib.*;
import com.github.msobkow.cflib.CFLib.Tip.*;
import com.github.msobkow.cfsec.CFSec.*;
import com.github.msobkow.cfsec.CFSecObj.*;
import com.github.msobkow.cfsec.CFSecXMsg.*;

public class CFSecXMsgClntHttpSchema
	extends CFSecXMsgClntSchema
{
	protected String serverURL = "http://localhost/cfsecxmsgsrvwar/CFSecXMsgSrvWarRequestXml";
	protected HttpClientContext clientContext = null;

	public CFSecXMsgClntHttpSchema() {
		super();
	}

	public CFSecXMsgClntHttpSchema( CFSecSchemaObj handlerSchema ) {
		super( handlerSchema );
	}

	public CFSecXMsgClntHttpSchema( CFSecSchemaObj handlerSchema, CFSecConfigurationFile conf ) {
		super( handlerSchema, conf );
	}

	public CFSecXMsgClntHttpSchema( CFSecSchemaObj handlerSchema, String argJndiName ) {
		super( handlerSchema, argJndiName );
	}

	public void setLog( ICFLibMessageLog newlog ) {
		super.setLog( newlog );
		if( cftipClientHandler != null ) {
			if( newlog != cftipClientHandler.getLog() ) {
				cftipClientHandler.setLog( newlog );
			}
		}
	}

	public void setServerURL( String value ) {
		final String S_ProcName = "setServerURL";
		if( ( value == null ) || ( value.length() <= 0 ) ) {
			throw new CFLibNullArgumentException( getClass(),
				S_ProcName,
				0,
				"value" );
		}
		serverURL = value;
	}

	public String getServerURL() {
		return( serverURL );
	}

	// Overload this to create an instance implementing your sendReceive() processing for CFTip
	public CFTipClientHandler getCFTipClientHandler() {
		if( cftipClientHandler == null ) {
			cftipClientHandler = new ClientHandler();
			cftipClientHandler.setLog( getLog() );
		}
		return( cftipClientHandler );
	}

	public boolean connect( String loginId, String password, String clusterName, String tenantName ) {
		final String S_ProcName = "connect-full";
		CFTipClientHandler clientHandler = getCFTipClientHandler();
		String deviceName = clientHandler.getDeviceName();
		if( clientContext != null ) {
			throw new CFLibUsageException( getClass(),
				S_ProcName,
				"clientContext already exists" );
		}
		CookieStore cookieStore = new BasicCookieStore();
		clientContext = HttpClientContext.create();
		clientContext.setCookieStore( cookieStore );

		String rqst = null;
		try {
			clientHandler.requestServerInfo();

			MessageDigest msgDigest = MessageDigest.getInstance( "SHA-512" );
			msgDigest.update( password.getBytes( "UTF-8" ) );
			byte[] hash = msgDigest.digest();
			byte[] encodedHash = Base64.encodeBase64( hash );
			byte[] devEncPWHash = clientHandler.encryptWithDevicePrivateKey( encodedHash );

			clientHandler.initSessionKey();

			rqst = CFSecXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
				+	"\t" + CFSecXMsgSchemaMessageFormatter.formatRqstLogIn( "\n\t\t\t",
								loginId,
								deviceName,
								devEncPWHash,
								clusterName,
								tenantName )
				+	"\n"
				+	CFSecXMsgSchemaMessageFormatter.formatRqstXmlPostamble();
		}
		catch( NoSuchAlgorithmException e ) {
			clientContext = null;
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchAlgorithmException - " + e.getMessage(),
				e );
		}
		catch( UnsupportedEncodingException e ) {
			clientContext = null;
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught UnsupportedEncodingException - " + e.getMessage(),
				e );
		}
		catch( InvalidKeyException e ) {
			clientContext = null;
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidKeyException - " + e.getMessage(),
				e );
		}
		catch( NoSuchPaddingException e ) {
			clientContext = null;
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchPaddingException - " + e.getMessage(),
				e );
		}
		catch( IllegalBlockSizeException e ) {
			clientContext = null;
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught IllegalBlockSizeException - " + e.getMessage(),
				e );
		}
		catch( BadPaddingException e ) {
			clientContext = null;
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught BadPaddingException - " + e.getMessage(),
				e );
		}
		catch( InvalidKeySpecException e ) {
			clientContext = null;
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidKeySpecException - " + e.getMessage(),
				e );
		}
		catch( RuntimeException e ) {
			clientContext = null;
			throw e;
		}
		try {
			cftipClientHandler.issueLoginRequest( rqst );
		}
		catch( InvalidAlgorithmParameterException e ) {
			clientContext = null;
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidAlgorithmParameterException - " + e.getMessage(),
				e );
		}
		catch( BadPaddingException e ) {
			clientContext = null;
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught BadPaddingException - " + e.getMessage(),
				e );
		}
		catch( IllegalBlockSizeException e ) {
			clientContext = null;
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught IllegalBlockSizeException - " + e.getMessage(),
				e );
		}
		catch( InvalidKeyException e ) {
			clientContext = null;
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidKeyException - " + e.getMessage(),
				e );
		}
		catch( NoSuchAlgorithmException e ) {
			clientContext = null;
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchAlgorithmException - " + e.getMessage(),
				e );
		}
		catch( NoSuchPaddingException e ) {
			clientContext = null;
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchPaddingException - " + e.getMessage(),
				e );
		}
		catch( RuntimeException e ) {
			clientContext = null;
			throw e;
		}
		// The response handler sets up the authorization
		ICFTipResponseHandler responseHandler = cftipClientHandler.getResponseHandler();
		RuntimeException exceptionRaised = responseHandler.getExceptionRaised();
		if( exceptionRaised != null ) {
			clientContext = null;
			throw exceptionRaised;
		}
		// If we got a response instead of an exception, we succeeded at logging in.
		return( true );
	}

	public void logout( CFSecAuthorization auth ) {
		final String S_ProcName = "logout";
		if( ( clientContext == null ) || ( auth == null ) || ( null == auth.getSecSessionId() ) ) {
			clientContext = null;
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Not authorized/connected" );
		}
		String rqst = CFSecXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFSecXMsgSchemaMessageFormatter.formatRqstLogOut( "\n\t\t\t",
							auth.getSecSessionId() )
			+	"\n"
			+	CFSecXMsgSchemaMessageFormatter.formatRqstXmlPostamble();
		try {
			cftipClientHandler.issueAppRequest( rqst );
		}
		catch( BadPaddingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught BadPaddingException - " + e.getMessage(),
				e );
		}
		catch( IllegalBlockSizeException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught IllegalBlockSizeException - " + e.getMessage(),
				e );
		}
		catch( InvalidKeyException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidKeyException - " + e.getMessage(),
				e );
		}
		catch( NoSuchAlgorithmException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchAlgorithmException - " + e.getMessage(),
				e );
		}
		catch( InvalidAlgorithmParameterException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidAlgorithmParameterException - " + e.getMessage(),
				e );
		}
		catch( NoSuchPaddingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchPaddingException - " + e.getMessage(),
				e );
		}
		finally {
			clientContext = null;
		}
		ICFTipResponseHandler responseHandler = cftipClientHandler.getResponseHandler();
		RuntimeException exceptionRaised = responseHandler.getExceptionRaised();
		if( exceptionRaised != null ) {
			throw exceptionRaised;
		}
	}

	public class ClientHandler
	extends CFTipClientHandler
	{
		public ClientHandler() {
			super();
		}

		public ClientHandler( ICFLibMessageLog logger ) {
			super( logger );
		}

		public String sendReceive( String value ) {
			final String S_ProcName = "sendReceive";

			if( ( value == null ) || ( value.length() <= 0 ) ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					1,
					"value" );
			}

			if( clientContext == null ) {
				throw new CFLibUsageException( getClass(),
					S_ProcName,
					"clientContext must be initialized by invoking connect() with full parameters first" );
			}
			String rspn = null;
			CloseableHttpClient httpClient = null;
			CloseableHttpResponse httpResponse = null;
			try {
				// Prepare to POST the form to the server URL
				List<NameValuePair> formParams = new ArrayList<NameValuePair>();
				formParams.add( new BasicNameValuePair( "MessageBody", value ) );
				UrlEncodedFormEntity entity = new UrlEncodedFormEntity( formParams, Consts.UTF_8 );
				HttpPost httpPost = new HttpPost( getServerURL() );
				httpPost.setEntity( entity );
				// POST the form and analyze the response validity
				httpClient = HttpClients.createDefault();
				httpResponse = httpClient.execute( httpPost, clientContext );
				StatusLine statusLine = httpResponse.getStatusLine();
				if( statusLine.getStatusCode() >= 300 ) {
					throw new HttpResponseException( statusLine.getStatusCode(),
						statusLine.getReasonPhrase() );
				}
				HttpEntity responseEntity = httpResponse.getEntity();
				if( responseEntity == null ) {
					throw new CFLibNullArgumentException( getClass(),
						S_ProcName,
						0,
						"responseEntity" );
				}
				// Read the response into a string
				ContentType contentType = ContentType.getOrDefault( responseEntity );
				Charset charSet = contentType.getCharset();
				Reader reader = new InputStreamReader( responseEntity.getContent(), charSet );
				StringBuffer buff = new StringBuffer();
				char ca[] = new char[1];
				int bytesRead = reader.read( ca );
				while( bytesRead == 1 ) {
					buff.append( ca[0] );
					bytesRead = reader.read( ca );
				}
				rspn = buff.toString();
			}
			catch( Exception e ) {
				rspn = null;
				throw new CFLibRuntimeException( getClass(),
					S_ProcName,
					"EXCEPTION processing HTTP POST -- " + e.getMessage(),
					e );
			}
			catch( Error e ) {
				rspn = null;
				throw new CFLibRuntimeException( getClass(),
					S_ProcName,
					"ERROR processing HTTP POST -- " + e.getMessage(),
					e );
			}
			finally {
				if( httpResponse != null ) {
					try {
						httpResponse.close();
					}
					catch (IOException e) {
					}
					httpResponse = null;
				}
				if( httpClient != null ) {
					try {
						httpClient.close();
					}
					catch (IOException e) {
					}
					httpClient = null;
				}
			}
			return( rspn );
		}

}

}
