
// Description: Java 11 XML Message SAX Response Record Element  for ISOTZone

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
 *	CFSecXMsgRspnISOTZoneRec XML SAX Element  implementation
 *	for ISOTZone.
 */
public class CFSecXMsgRspnISOTZoneRec
	extends CFLibXmlCoreElementHandler
{
	public CFSecXMsgRspnISOTZoneRec( CFSecXMsgRspn xmsgRspn ) {
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
			// ISOTZone Attributes
			String	attrISOTZoneId = null;
			String	attrIso8601 = null;
			String	attrTZName = null;
			String	attrTZHourOffset = null;
			String	attrTZMinOffset = null;
			String	attrDescription = null;
			String	attrVisible = null;
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

			assert qName.equals( "ISOTZone" );

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
				else if( attrLocalName.equals( "ISOTZoneId" ) ) {
					if( attrISOTZoneId != null ) {
						throw new CFLibUniqueIndexViolationException( getClass(),
							S_ProcName,
							S_LocalName,
							attrLocalName );
					}
					attrISOTZoneId = attrs.getValue( idxAttr );
				}
				else if( attrLocalName.equals( "Iso8601" ) ) {
					if( attrIso8601 != null ) {
						throw new CFLibUniqueIndexViolationException( getClass(),
							S_ProcName,
							S_LocalName,
							attrLocalName );
					}
					attrIso8601 = attrs.getValue( idxAttr );
				}
				else if( attrLocalName.equals( "TZName" ) ) {
					if( attrTZName != null ) {
						throw new CFLibUniqueIndexViolationException( getClass(),
							S_ProcName,
							S_LocalName,
							attrLocalName );
					}
					attrTZName = attrs.getValue( idxAttr );
				}
				else if( attrLocalName.equals( "TZHourOffset" ) ) {
					if( attrTZHourOffset != null ) {
						throw new CFLibUniqueIndexViolationException( getClass(),
							S_ProcName,
							S_LocalName,
							attrLocalName );
					}
					attrTZHourOffset = attrs.getValue( idxAttr );
				}
				else if( attrLocalName.equals( "TZMinOffset" ) ) {
					if( attrTZMinOffset != null ) {
						throw new CFLibUniqueIndexViolationException( getClass(),
							S_ProcName,
							S_LocalName,
							attrLocalName );
					}
					attrTZMinOffset = attrs.getValue( idxAttr );
				}
				else if( attrLocalName.equals( "Description" ) ) {
					if( attrDescription != null ) {
						throw new CFLibUniqueIndexViolationException( getClass(),
							S_ProcName,
							S_LocalName,
							attrLocalName );
					}
					attrDescription = attrs.getValue( idxAttr );
				}
				else if( attrLocalName.equals( "Visible" ) ) {
					if( attrVisible != null ) {
						throw new CFLibUniqueIndexViolationException( getClass(),
							S_ProcName,
							S_LocalName,
							attrLocalName );
					}
					attrVisible = attrs.getValue( idxAttr );
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
			if( ( attrISOTZoneId == null ) || ( attrISOTZoneId.length() <= 0 ) ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"ISOTZoneId" );
			}
			if( attrIso8601 == null ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"Iso8601" );
			}
			if( attrTZName == null ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"TZName" );
			}
			if( ( attrTZHourOffset == null ) || ( attrTZHourOffset.length() <= 0 ) ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"TZHourOffset" );
			}
			if( ( attrTZMinOffset == null ) || ( attrTZMinOffset.length() <= 0 ) ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"TZMinOffset" );
			}
			if( attrDescription == null ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"Description" );
			}
			if( ( attrVisible == null ) || ( attrVisible.length() <= 0 ) ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"Visible" );
			}

			// Save named attributes to context
			CFLibXmlCoreContext curContext = xmsgRspn.getCurContext();

			// Convert string attributes to native Java types

			short natISOTZoneId = Short.parseShort( attrISOTZoneId );

			String natIso8601 = attrIso8601;

			String natTZName = attrTZName;

			short natTZHourOffset = Short.parseShort( attrTZHourOffset );

			short natTZMinOffset = Short.parseShort( attrTZMinOffset );

			String natDescription = attrDescription;

			boolean natVisible;
			if( attrVisible.equals( "true" ) || attrVisible.equals( "yes" ) || attrVisible.equals( "1" ) ) {
				natVisible = true;
			}
			else if( attrVisible.equals( "false" ) || attrVisible.equals( "no" ) || attrVisible.equals( "0" ) ) {
				natVisible = false;
			}
			else {
				throw new CFLibUsageException( getClass(),
					S_ProcName,
					"Unexpected Visible value, must be one of true, false, yes, no, 1, or 0, not \"" + attrVisible + "\"" );
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
			// Get the parent context
			CFLibXmlCoreContext parentContext = curContext.getPrevContext();
			// Instantiate a buffer for the parsed information
			ICFSecISOTZoneObj obj = (ICFSecISOTZoneObj)(schemaObj.getISOTZoneTableObj().newInstance());
			CFSecISOTZoneBuff dataBuff = obj.getISOTZoneBuff();
			dataBuff.setRequiredISOTZoneId( natISOTZoneId );
			dataBuff.setRequiredIso8601( natIso8601 );
			dataBuff.setRequiredTZName( natTZName );
			dataBuff.setRequiredTZHourOffset( natTZHourOffset );
			dataBuff.setRequiredTZMinOffset( natTZMinOffset );
			dataBuff.setRequiredDescription( natDescription );
			dataBuff.setRequiredVisible( natVisible );
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
			@SuppressWarnings("unchecked")
			List<ICFSecISOTZoneObj> list =
				(List<ICFSecISOTZoneObj>)xmsgRspn.getListOfObjects();
			ICFSecISOTZoneObj realised = (ICFSecISOTZoneObj)obj.realise();
			xmsgRspn.setLastObjectProcessed( realised );
			if( list != null ) {
				list.add( realised );
			}
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
