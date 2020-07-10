
// Description: Java 11 XML Message SAX Request Log In Element 

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

package com.github.msobkow.cfsec.CFSecXMsgRqst;

import java.security.*;
import java.security.spec.InvalidKeySpecException;
import java.security.spec.X509EncodedKeySpec;
import java.util.*;

import javax.crypto.*;

import org.apache.commons.codec.binary.Base64;
import org.xml.sax.*;

import com.github.msobkow.cflib.CFLib.*;
import com.github.msobkow.cfsec.CFSec.*;
import com.github.msobkow.cfsec.CFSecObj.*;
import com.github.msobkow.cfsec.CFSecXMsg.*;

/*
 *	CFSecXMsgRqstLogIn XML SAX Element  implementation
 */
public class CFSecXMsgRqstLogIn
	extends CFLibXmlCoreElementHandler
{
	public CFSecXMsgRqstLogIn( CFSecXMsgRqst xmsgRqst ) {
		super( xmsgRqst );
	}

	public void startElement(
		String		uri,
		String		localName,
		String		qName,
		Attributes	attrs )
	throws SAXException
	{
		final String S_ProcName = "startElement";
		ICFSecSchemaObj schemaObj = null;
		CFSecXMsgSchemaMessageFormatter schemaFormatter = null;
		try {
			// Common XML Attributes
			String	attrId = null;
			// Request Attributes
			String	attrLoginId = null;
			String	attrDeviceName = null;
			String	attrDevEncPWHash = null;
			String	attrClusterName = null;
			String	attrTenantName = null;
			// Attribute Extraction
			String	attrLocalName;
			int		numAttrs;
			int		idxAttr;
			final String S_LocalName = "LocalName";

			assert qName.equals( "RqstLogIn" );

			CFSecXMsgRqst xmsgRqst = (CFSecXMsgRqst)getParser();
			if( xmsgRqst == null ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"getParser()" );
			}

			schemaFormatter = xmsgRqst.getSchemaMessageFormatter();

			schemaObj = xmsgRqst.getSchemaObj();
			if( schemaObj == null ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"getParser().getSchemaObj()" );
			}

			schemaObj.connect();

			// Extract Attributes
			numAttrs = attrs.getLength();
			for( idxAttr = 0; idxAttr < numAttrs; idxAttr++ ) {
				attrLocalName = attrs.getLocalName( idxAttr );
				if( attrLocalName.equals( "Id" ) ) {
					if( attrId != null ) {
						throw new CFLibUniqueIndexViolationException( getClass(),
							S_ProcName,
							S_LocalName,
							attrLocalName );
					}
					attrId = attrs.getValue( idxAttr );
				}
				else if( attrLocalName.equals( "LoginId" ) ) {
					if( attrLoginId != null ) {
						throw new CFLibUniqueIndexViolationException( getClass(),
							S_ProcName,
							S_LocalName,
							attrLocalName );
					}
					attrLoginId = attrs.getValue( idxAttr );
				}
				else if( attrLocalName.equals( "DeviceName" ) ) {
					if( attrDeviceName != null ) {
						throw new CFLibUniqueIndexViolationException( getClass(),
							S_ProcName,
							S_LocalName,
							attrLocalName );
					}
					attrDeviceName = attrs.getValue( idxAttr );
				}
				else if( attrLocalName.equals( "DevEncPWHash" ) ) {
					if( attrDevEncPWHash != null ) {
						throw new CFLibUniqueIndexViolationException( getClass(),
							S_ProcName,
							S_LocalName,
							attrLocalName );
					}
					attrDevEncPWHash = attrs.getValue( idxAttr );
				}
				else if( attrLocalName.equals( "ClusterName" ) ) {
					if( attrClusterName != null ) {
						throw new CFLibUniqueIndexViolationException( getClass(),
							S_ProcName,
							S_LocalName,
							attrLocalName );
					}
					attrClusterName = attrs.getValue( idxAttr );
				}
				else if( attrLocalName.equals( "TenantName" ) ) {
					if( attrTenantName != null ) {
						throw new CFLibUniqueIndexViolationException( getClass(),
							S_ProcName,
							S_LocalName,
							attrLocalName );
					}
					attrTenantName = attrs.getValue( idxAttr );
				}
				else {
					throw new CFLibUnrecognizedAttributeException( getClass(),
						S_ProcName,
						getParser().getLocationInfo(),
						attrLocalName );
				}
			}

			// Ensure that required attributes have values
			if( ( attrLoginId == null ) || ( attrLoginId.length() <= 0 ) ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"LoginId" );
			}
			if( ( attrDeviceName == null ) || ( attrDeviceName.length() <= 0 ) ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"DeviceName" );
			}
			if( ( attrDevEncPWHash == null ) || ( attrDevEncPWHash.length() <= 0 ) ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"DevEncPWHash" );
			}
			if( ( attrClusterName == null ) || ( attrClusterName.length() <= 0 ) ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"ClusterName" );
			}
			if( ( attrTenantName == null ) || ( attrTenantName.length() <= 0 ) ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"TenantName" );
			}

			if( schemaObj.getAuthorization() != null ) {
				throw new CFLibRuntimeException( getClass(),
					S_ProcName,
					"Back end database schema already authorized against database" );
			}

			if( schemaObj.isTransactionOpen() ) {
				schemaObj.rollback();
			}

			schemaObj.beginTransaction();

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

			ICFSecSecUserObj authenticatingUser = schemaObj.getSecUserTableObj().readSecUserByULoginIdx( attrLoginId, true );
			if( authenticatingUser == null ) {
				throw new CFLibInvalidArgumentException( getClass(),
					S_ProcName,
					"Permission denied" );
			}

			ICFSecSecDeviceObj device = schemaObj.getSecDeviceTableObj().readSecDeviceByIdIdx( authenticatingUser.getRequiredSecUserId(),
				attrDeviceName,
				true );
			if( device == null ) {
				throw new CFLibInvalidArgumentException( getClass(),
					S_ProcName,
					"Permission denied" );
			}

			String pubKey = device.getOptionalPubKey();
			if( ( pubKey == null ) || ( pubKey.length() <= 0 ) ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"DevicePublicKey" );
			}

			byte wrapped[] = Base64.decodeBase64( pubKey );

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
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"DecodedPublicKey" );
			}

			byte decodedDevEncPWHash[] = Base64.decodeBase64( attrDevEncPWHash );

			Cipher cipher = Cipher.getInstance( "RSA/ECB/PKCS1Padding" );
			if( cipher == null ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"cipher" );
			}

			cipher.init( Cipher.DECRYPT_MODE, decodedPublicKey );

			byte decryptedPWHash[] = cipher.doFinal( decodedDevEncPWHash );

			MessageDigest msgDigest = MessageDigest.getInstance( "SHA-512" );
			msgDigest.update( decryptedPWHash );
			byte hash[] = msgDigest.digest();
			byte encodedDoubleHash[] = Base64.encodeBase64( hash );
			String hashedAndEncodedPassword = new String( encodedDoubleHash );

			if( ! hashedAndEncodedPassword.equals( authenticatingUser.getRequiredPasswordHash() ) ) {
				throw new CFLibInvalidArgumentException( getClass(),
					S_ProcName,
					"Permission denied" );
			}

			ICFSecClusterObj useCluster = null;
			if( attrClusterName.equals( "system" ) ) {
				useCluster = schemaObj.getClusterTableObj().readClusterByUDomNameIdx( "system" );
				if( useCluster == null ) {
					throw new CFLibNullArgumentException( getClass(),
						S_ProcName,
						0,
						"ClusterSystem" );
				}
				attrTenantName = "system";
			}
			else {
				useCluster = resolvedCluster;
			}

			ICFSecTenantObj useTenant = schemaObj.getTenantTableObj().readTenantByUNameIdx( useCluster.getRequiredId(),
				attrTenantName );
			if( useTenant == null ) {
				throw new CFLibInvalidArgumentException( getClass(),
					S_ProcName,
					"No such tenant \"" + attrTenantName + "\"" );
			}

			ICFSecSecSessionObj systemSession = schemaObj.getSecSessionTableObj().newInstance();
			ICFSecSecSessionEditObj editSystemSession = (ICFSecSecSessionEditObj)systemSession.beginEdit();
			editSystemSession.setRequiredContainerSecUser( authenticatingUser );
			editSystemSession.setRequiredStart( Calendar.getInstance() );
			systemSession = editSystemSession.create();
			editSystemSession = null;

			CFSecAuthorization auth = new CFSecAuthorization();
			auth.setSecCluster( useCluster );
			auth.setSecTenant( useTenant );
			auth.setSecSession( systemSession );
			schemaObj.setAuthorization( auth );

			schemaObj.commit();

			String response = schemaFormatter.formatRspnXmlPreamble() + "\n"
				+	"\t" + CFSecXMsgSchemaMessageFormatter.formatRspnLoggedIn( "\n\t\t\t",
								schemaObj.getSecCluster().getRequiredId(),
								schemaObj.getSecCluster().getRequiredFullDomName(),
								schemaObj.getSecTenant().getRequiredId(),
								schemaObj.getSecTenant().getRequiredTenantName(),
								schemaObj.getSecSession().getRequiredContainerSecUser().getRequiredSecUserId(),
								schemaObj.getSecSession().getRequiredContainerSecUser().getRequiredLoginId(),
								schemaObj.getSecSession().getRequiredSecSessionId() ) +	"\n"
				+	schemaFormatter.formatRspnXmlPostamble();
			((CFSecXMsgRqst)getParser()).appendResponse( response );
		}
		catch (IllegalBlockSizeException e) {
			if( schemaObj != null ) {
				schemaObj.rollback();
				schemaObj.setAuthorization( null );
			}
			CFSecXMsgRqst xmsgRqst = ((CFSecXMsgRqst)getParser());
			schemaFormatter = xmsgRqst.getSchemaMessageFormatter();
			String response = schemaFormatter.formatRspnXmlPreamble() + "\n"
				+	"\t" + CFSecXMsgSchemaMessageFormatter.formatRspnException( "\n\t\t\t", e )
				+	"\n"
				+	schemaFormatter.formatRspnXmlPostamble();
			xmsgRqst.resetResponse();
			xmsgRqst.appendResponse( response );
			xmsgRqst.setCaughtException( true );
		}
		catch (BadPaddingException e) {
			if( schemaObj != null ) {
				schemaObj.rollback();
				schemaObj.setAuthorization( null );
			}
			CFSecXMsgRqst xmsgRqst = ((CFSecXMsgRqst)getParser());
			schemaFormatter = xmsgRqst.getSchemaMessageFormatter();
			String response = schemaFormatter.formatRspnXmlPreamble() + "\n"
				+	"\t" + CFSecXMsgSchemaMessageFormatter.formatRspnException( "\n\t\t\t", e )
				+	"\n"
				+	schemaFormatter.formatRspnXmlPostamble();
			xmsgRqst.resetResponse();
			xmsgRqst.appendResponse( response );
			xmsgRqst.setCaughtException( true );
		}
		catch (InvalidKeyException e) {
			if( schemaObj != null ) {
				schemaObj.rollback();
				schemaObj.setAuthorization( null );
			}
			CFSecXMsgRqst xmsgRqst = ((CFSecXMsgRqst)getParser());
			schemaFormatter = xmsgRqst.getSchemaMessageFormatter();
			String response = schemaFormatter.formatRspnXmlPreamble() + "\n"
				+	"\t" + CFSecXMsgSchemaMessageFormatter.formatRspnException( "\n\t\t\t", e )
				+	"\n"
				+	schemaFormatter.formatRspnXmlPostamble();
			xmsgRqst.resetResponse();
			xmsgRqst.appendResponse( response );
			xmsgRqst.setCaughtException( true );
		}
		catch (NoSuchAlgorithmException e) {
			if( schemaObj != null ) {
				schemaObj.rollback();
				schemaObj.setAuthorization( null );
			}
			CFSecXMsgRqst xmsgRqst = ((CFSecXMsgRqst)getParser());
			schemaFormatter = xmsgRqst.getSchemaMessageFormatter();
			String response = schemaFormatter.formatRspnXmlPreamble() + "\n"
				+	"\t" + CFSecXMsgSchemaMessageFormatter.formatRspnException( "\n\t\t\t", e )
				+	"\n"
				+	schemaFormatter.formatRspnXmlPostamble();
			xmsgRqst.resetResponse();
			xmsgRqst.appendResponse( response );
			xmsgRqst.setCaughtException( true );
		}
		catch (NoSuchPaddingException e) {
			if( schemaObj != null ) {
				schemaObj.rollback();
				schemaObj.setAuthorization( null );
			}
			CFSecXMsgRqst xmsgRqst = ((CFSecXMsgRqst)getParser());
			schemaFormatter = xmsgRqst.getSchemaMessageFormatter();
			String response = schemaFormatter.formatRspnXmlPreamble() + "\n"
				+	"\t" + CFSecXMsgSchemaMessageFormatter.formatRspnException( "\n\t\t\t", e )
				+	"\n"
				+	schemaFormatter.formatRspnXmlPostamble();
			xmsgRqst.resetResponse();
			xmsgRqst.appendResponse( response );
			xmsgRqst.setCaughtException( true );
		}
		catch (InvalidKeySpecException e) {
			if( schemaObj != null ) {
				schemaObj.rollback();
				schemaObj.setAuthorization( null );
			}
			CFSecXMsgRqst xmsgRqst = ((CFSecXMsgRqst)getParser());
			schemaFormatter = xmsgRqst.getSchemaMessageFormatter();
			String response = schemaFormatter.formatRspnXmlPreamble() + "\n"
				+	"\t" + CFSecXMsgSchemaMessageFormatter.formatRspnException( "\n\t\t\t", e )
				+	"\n"
				+	schemaFormatter.formatRspnXmlPostamble();
			xmsgRqst.resetResponse();
			xmsgRqst.appendResponse( response );
			xmsgRqst.setCaughtException( true );
		}
		catch( RuntimeException e ) {
			if( schemaObj != null ) {
				schemaObj.rollback();
				schemaObj.setAuthorization( null );
			}
			CFSecXMsgRqst xmsgRqst = ((CFSecXMsgRqst)getParser());
			schemaFormatter = xmsgRqst.getSchemaMessageFormatter();
			String response = schemaFormatter.formatRspnXmlPreamble() + "\n"
				+	"\t" + CFSecXMsgSchemaMessageFormatter.formatRspnException( "\n\t\t\t", e )
				+	"\n"
				+	schemaFormatter.formatRspnXmlPostamble();
			xmsgRqst.resetResponse();
			xmsgRqst.appendResponse( response );
			xmsgRqst.setCaughtException( true );
		}
		catch( Error e ) {
			if( schemaObj != null ) {
				schemaObj.rollback();
				schemaObj.setAuthorization( null );
			}
			CFSecXMsgRqst xmsgRqst = ((CFSecXMsgRqst)getParser());
			schemaFormatter = xmsgRqst.getSchemaMessageFormatter();
			String response = schemaFormatter.formatRspnXmlPreamble() + "\n"
				+	"\t" + CFSecXMsgSchemaMessageFormatter.formatRspnException( "\n\t\t\t", e )
				+	"\n"
				+	schemaFormatter.formatRspnXmlPostamble();
			xmsgRqst.resetResponse();
			xmsgRqst.appendResponse( response );
			xmsgRqst.setCaughtException( true );
		}
	}

	public void endElement(
		String		uri,
		String		localName,
		String		qName )
	throws SAXException
	{
	}
}
