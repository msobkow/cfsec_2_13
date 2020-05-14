
// Description: Java 11 XML Message SAX Response Record Element  for SecUser

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

package com.github.msobkow.cfsec.CFSecXMsgRspn;

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.apache.commons.codec.binary.Base64;
import org.xml.sax.*;
import com.github.msobkow.cflib.CFLib.*;
import com.github.msobkow.cfsec.CFSec.*;
import com.github.msobkow.cfsec.CFSecObj.*;

/*
 *	CFSecXMsgRspnSecUserCreated XML SAX Element  implementation
 *	for SecUser.
 */
public class CFSecXMsgRspnSecUserCreated
	extends CFLibXmlCoreElementHandler
{
	public CFSecXMsgRspnSecUserCreated( CFSecXMsgRspn xmsgRspn ) {
		super( xmsgRspn );
	}

	public void startElement(
		String		uri,
		String		localName,
		String		qName,
		Attributes	attrs )
	throws SAXException
	{
		try {
			// Common XML Attributes
			String	attrId = null;
			String	attrRevision = null;
			// SecUser Attributes
			String	attrSecUserId = null;
			String	attrLoginId = null;
			String	attrEMailAddress = null;
			String	attrEMailConfirmUuid = null;
			String	attrDfltDevUserId = null;
			String	attrDfltDevName = null;
			String	attrPasswordHash = null;
			String	attrPasswordResetUuid = null;
			String attrCreatedAt = null;
			String attrCreatedBy = null;
			String attrUpdatedAt = null;
			String attrUpdatedBy = null;
			// Attribute Extraction
			String	attrLocalName;
			int		numAttrs;
			int		idxAttr;
			final String S_ProcName = "startElement";
			final String S_LocalName = "LocalName";

			assert qName.equals( "RspnSecUserCreated" );

			CFSecXMsgRspn xmsgRspn = (CFSecXMsgRspn)getParser();
			if( xmsgRspn == null ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"getParser()" );
			}

			ICFSecSchemaObj schemaObj = xmsgRspn.getSchemaObj();
			if( schemaObj == null ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"getParser().getSchemaObj()" );
			}

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
				else if( attrLocalName.equals( "Revision" ) ) {
					if( attrRevision != null ) {
						throw new CFLibUniqueIndexViolationException( getClass(),
							S_ProcName,
							S_LocalName,
							attrLocalName );
					}
					attrRevision = attrs.getValue( idxAttr );
				}
				else if( attrLocalName.equals( "CreatedAt" ) ) {
					if( attrCreatedAt != null ) {
						throw new CFLibUniqueIndexViolationException( getClass(),
							S_ProcName,
							S_LocalName,
							attrLocalName );
					}
					attrCreatedAt = attrs.getValue( idxAttr );
				}
				else if( attrLocalName.equals( "CreatedBy" ) ) {
					if( attrCreatedBy != null ) {
						throw new CFLibUniqueIndexViolationException( getClass(),
							S_ProcName,
							S_LocalName,
							attrLocalName );
					}
					attrCreatedBy = attrs.getValue( idxAttr );
				}
				else if( attrLocalName.equals( "UpdatedAt" ) ) {
					if( attrUpdatedAt != null ) {
						throw new CFLibUniqueIndexViolationException( getClass(),
							S_ProcName,
							S_LocalName,
							attrLocalName );
					}
					attrUpdatedAt = attrs.getValue( idxAttr );
				}
				else if( attrLocalName.equals( "UpdatedBy" ) ) {
					if( attrUpdatedBy != null ) {
						throw new CFLibUniqueIndexViolationException( getClass(),
							S_ProcName,
							S_LocalName,
							attrLocalName );
					}
					attrUpdatedBy = attrs.getValue( idxAttr );
				}
				else if( attrLocalName.equals( "SecUserId" ) ) {
					if( attrSecUserId != null ) {
						throw new CFLibUniqueIndexViolationException( getClass(),
							S_ProcName,
							S_LocalName,
							attrLocalName );
					}
					attrSecUserId = attrs.getValue( idxAttr );
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
				else if( attrLocalName.equals( "EMailAddress" ) ) {
					if( attrEMailAddress != null ) {
						throw new CFLibUniqueIndexViolationException( getClass(),
							S_ProcName,
							S_LocalName,
							attrLocalName );
					}
					attrEMailAddress = attrs.getValue( idxAttr );
				}
				else if( attrLocalName.equals( "EMailConfirmUuid" ) ) {
					if( attrEMailConfirmUuid != null ) {
						throw new CFLibUniqueIndexViolationException( getClass(),
							S_ProcName,
							S_LocalName,
							attrLocalName );
					}
					attrEMailConfirmUuid = attrs.getValue( idxAttr );
				}
				else if( attrLocalName.equals( "DfltDevUserId" ) ) {
					if( attrDfltDevUserId != null ) {
						throw new CFLibUniqueIndexViolationException( getClass(),
							S_ProcName,
							S_LocalName,
							attrLocalName );
					}
					attrDfltDevUserId = attrs.getValue( idxAttr );
				}
				else if( attrLocalName.equals( "DfltDevName" ) ) {
					if( attrDfltDevName != null ) {
						throw new CFLibUniqueIndexViolationException( getClass(),
							S_ProcName,
							S_LocalName,
							attrLocalName );
					}
					attrDfltDevName = attrs.getValue( idxAttr );
				}
				else if( attrLocalName.equals( "PasswordHash" ) ) {
					if( attrPasswordHash != null ) {
						throw new CFLibUniqueIndexViolationException( getClass(),
							S_ProcName,
							S_LocalName,
							attrLocalName );
					}
					attrPasswordHash = attrs.getValue( idxAttr );
				}
				else if( attrLocalName.equals( "PasswordResetUuid" ) ) {
					if( attrPasswordResetUuid != null ) {
						throw new CFLibUniqueIndexViolationException( getClass(),
							S_ProcName,
							S_LocalName,
							attrLocalName );
					}
					attrPasswordResetUuid = attrs.getValue( idxAttr );
				}
				else if( attrLocalName.equals( "schemaLocation" ) ) {
					// ignored
				}
				else {
					throw new CFLibUnrecognizedAttributeException( getClass(),
						S_ProcName,
						getParser().getLocationInfo(),
						attrLocalName );
				}
			}

			// Ensure that required attributes have values
			if( ( attrSecUserId == null ) || ( attrSecUserId.length() <= 0 ) ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"SecUserId" );
			}
			if( attrLoginId == null ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"LoginId" );
			}
			if( attrEMailAddress == null ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"EMailAddress" );
			}
			if( attrPasswordHash == null ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"PasswordHash" );
			}
			if( ( attrRevision == null ) || ( attrRevision.length() <= 0 ) ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"Revision" );
			}

			// Save named attributes to context
			CFLibXmlCoreContext curContext = getParser().getCurContext();

			// Convert string attributes to native Java types

			UUID natSecUserId = UUID.fromString( attrSecUserId );

			String natLoginId = attrLoginId;

			String natEMailAddress = attrEMailAddress;

			UUID natEMailConfirmUuid;
			if( ( attrEMailConfirmUuid == null ) || ( attrEMailConfirmUuid.length() <= 0 ) ) {
				natEMailConfirmUuid = null;
			}
			else {
				natEMailConfirmUuid = UUID.fromString( attrEMailConfirmUuid );
			}

			UUID natDfltDevUserId;
			if( ( attrDfltDevUserId == null ) || ( attrDfltDevUserId.length() <= 0 ) ) {
				natDfltDevUserId = null;
			}
			else {
				natDfltDevUserId = UUID.fromString( attrDfltDevUserId );
			}

			String natDfltDevName = attrDfltDevName;

			String natPasswordHash = attrPasswordHash;

			UUID natPasswordResetUuid;
			if( ( attrPasswordResetUuid == null ) || ( attrPasswordResetUuid.length() <= 0 ) ) {
				natPasswordResetUuid = null;
			}
			else {
				natPasswordResetUuid = UUID.fromString( attrPasswordResetUuid );
			}

			int natRevision = Integer.parseInt( attrRevision );
			UUID createdBy = null;
			if( attrCreatedBy != null ) {
				createdBy = UUID.fromString( attrCreatedBy );
			}
			Calendar createdAt = null;
			if( attrCreatedAt != null ) {
				createdAt = CFLibXmlUtil.parseTimestamp( attrCreatedAt );
			}
			UUID updatedBy = null;
			if( attrUpdatedBy != null ) {
				updatedBy = UUID.fromString( attrUpdatedBy );
			}
			Calendar updatedAt = null;
			if( attrUpdatedAt != null ) {
				updatedAt = CFLibXmlUtil.parseTimestamp( attrUpdatedAt );
			}
			// Instantiate a buffer for the parsed information
			ICFSecSecUserObj obj = (ICFSecSecUserObj)schemaObj.getSecUserTableObj().newInstance();
			CFSecSecUserBuff dataBuff = obj.getSecUserBuff();
			dataBuff.setRequiredSecUserId( natSecUserId );
			dataBuff.setRequiredLoginId( natLoginId );
			dataBuff.setRequiredEMailAddress( natEMailAddress );
			dataBuff.setOptionalEMailConfirmUuid( natEMailConfirmUuid );
			dataBuff.setOptionalDfltDevUserId( natDfltDevUserId );
			dataBuff.setOptionalDfltDevName( natDfltDevName );
			dataBuff.setRequiredPasswordHash( natPasswordHash );
			dataBuff.setOptionalPasswordResetUuid( natPasswordResetUuid );
			dataBuff.setRequiredRevision( natRevision );
			if( createdBy != null ) {
				dataBuff.setCreatedByUserId( createdBy );
			}
			if( createdAt != null ) {
				dataBuff.setCreatedAt( createdAt );
			}
			if( updatedBy != null ) {
				dataBuff.setUpdatedByUserId( updatedBy );
			}
			if( updatedAt != null ) {
				dataBuff.setUpdatedAt( updatedAt );
			}
			obj.copyBuffToPKey();
			ICFSecSecUserObj realised = (ICFSecSecUserObj)obj.realise();
			xmsgRspn.setLastObjectProcessed( realised );
		}
		catch( RuntimeException e ) {
			throw new RuntimeException( "Near " + getParser().getLocationInfo() + ": Caught and rethrew " + e.getClass().getName() + " - " + e.getMessage(),
				e );
		}
		catch( Error e ) {
			throw new Error( "Near " + getParser().getLocationInfo() + ": Caught and rethrew " + e.getClass().getName() + " - " + e.getMessage(),
				e );
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
