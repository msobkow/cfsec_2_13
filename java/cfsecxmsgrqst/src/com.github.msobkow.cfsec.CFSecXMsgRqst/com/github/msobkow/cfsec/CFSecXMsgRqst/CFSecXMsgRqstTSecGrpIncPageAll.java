
// Description: Java 11 XML Message SAX Request Page All Element  for TSecGrpInc

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

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.apache.commons.codec.binary.Base64;
import org.xml.sax.*;
import com.github.msobkow.cflib.CFLib.*;
import com.github.msobkow.cfsec.CFSec.*;
import com.github.msobkow.cfsec.CFSecObj.*;
import com.github.msobkow.cfsec.CFSecXMsg.*;

/*
 *	CFSecXMsgRqstTSecGrpIncPageAll XML SAX Element  implementation
 *	for TSecGrpInc.
 */
public class CFSecXMsgRqstTSecGrpIncPageAll
	extends CFLibXmlCoreElementHandler
{
	public CFSecXMsgRqstTSecGrpIncPageAll( CFSecXMsgRqst xmsgRqst ) {
		super( xmsgRqst );
	}

	public void startElement(
		String		uri,
		String		localName,
		String		qName,
		Attributes	attrs )
	throws SAXException
	{
		CFSecXMsgSchemaMessageFormatter schemaFormatter = null;
		try {
			// Common XML Attributes
			String	attrId = null;
			String attrPriorTenantId = null;
			String attrPriorTSecGrpIncId = null;
			// Attribute Extraction
			String	attrLocalName;
			int		numAttrs;
			int		idxAttr;
			final String S_ProcName = "startElement";
			final String S_LocalName = "LocalName";

			assert qName.equals( "RqstTSecGrpIncPageAll" );

			CFSecXMsgRqst xmsgRqst = (CFSecXMsgRqst)getParser();
			if( xmsgRqst == null ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"getParser()" );
			}

			schemaFormatter = xmsgRqst.getSchemaMessageFormatter();

			ICFSecSchemaObj schemaObj = xmsgRqst.getSchemaObj();
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
				else if( attrLocalName.equals( "PriorTenantId" ) ) {
					if( attrPriorTenantId != null ) {
						throw new CFLibUniqueIndexViolationException( getClass(),
							S_ProcName,
							S_LocalName,
							attrLocalName );
					}
					attrPriorTenantId = attrs.getValue( idxAttr );
				}
				else if( attrLocalName.equals( "PriorTSecGrpIncId" ) ) {
					if( attrPriorTSecGrpIncId != null ) {
						throw new CFLibUniqueIndexViolationException( getClass(),
							S_ProcName,
							S_LocalName,
							attrLocalName );
					}
					attrPriorTSecGrpIncId = attrs.getValue( idxAttr );
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

			// Save named attributes to context
			CFLibXmlCoreContext curContext = getParser().getCurContext();
			Long natPriorTenantId;
			if( ( attrPriorTenantId == null ) || ( attrPriorTenantId.length() <= 0 ) ) {
				natPriorTenantId = null;
			}
			else {
				natPriorTenantId = Long.valueOf( Long.parseLong( attrPriorTenantId ) );
			}

			Long natPriorTSecGrpIncId;
			if( ( attrPriorTSecGrpIncId == null ) || ( attrPriorTSecGrpIncId.length() <= 0 ) ) {
				natPriorTSecGrpIncId = null;
			}
			else {
				natPriorTSecGrpIncId = Long.valueOf( Long.parseLong( attrPriorTSecGrpIncId ) );
			}

			// Page the objects and prepare the response XML
			List<ICFSecTSecGrpIncObj> list = schemaObj.getTSecGrpIncTableObj().pageAllTSecGrpInc( natPriorTenantId,
				natPriorTSecGrpIncId );
			String responseOpening = schemaFormatter.formatRspnXmlPreamble() + "\n"
				+	"\t" + CFSecXMsgTSecGrpIncMessageFormatter.formatTSecGrpIncRspnListOpenTag();
			xmsgRqst.appendResponse( responseOpening );
			Iterator<ICFSecTSecGrpIncObj> iter = list.iterator();
			ICFSecTSecGrpIncObj cur;
			String subxml;
			while( iter.hasNext() ) {
				cur = iter.next();
				subxml = CFSecXMsgTSecGrpIncMessageFormatter.formatTSecGrpIncRspnDerivedRec( "\n\t\t", cur.getTSecGrpIncBuff() );
				xmsgRqst.appendResponse( subxml );
			}
			String responseClosing =
				 	"\n"
				+	"\t" + CFSecXMsgTSecGrpIncMessageFormatter.formatTSecGrpIncRspnListCloseTag()
				+	schemaFormatter.formatRspnXmlPostamble();
			xmsgRqst.appendResponse( responseClosing );
		}
		catch( RuntimeException e ) {
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
