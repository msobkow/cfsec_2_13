
// Description: Java 11 XML Message SAX Request Page All Element  for HostNode

/*
 *	org.msscf.msscf.CFSec
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

package org.msscf.msscf.cfsec.CFSecXMsgRqst;

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.apache.commons.codec.binary.Base64;
import org.xml.sax.*;
import com.github.msobkow.cflib.CFLib.*;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfsec.CFSecObj.*;
import org.msscf.msscf.cfsec.CFSecXMsg.*;

/*
 *	CFSecXMsgRqstHostNodePageAll XML SAX Element  implementation
 *	for HostNode.
 */
public class CFSecXMsgRqstHostNodePageAll
	extends CFLibXmlCoreElementHandler
{
	public CFSecXMsgRqstHostNodePageAll( CFSecXMsgRqst xmsgRqst ) {
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
			String attrPriorClusterId = null;
			String attrPriorHostNodeId = null;
			// Attribute Extraction
			String	attrLocalName;
			int		numAttrs;
			int		idxAttr;
			final String S_ProcName = "startElement";
			final String S_LocalName = "LocalName";

			assert qName.equals( "RqstHostNodePageAll" );

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
				else if( attrLocalName.equals( "PriorClusterId" ) ) {
					if( attrPriorClusterId != null ) {
						throw new CFLibUniqueIndexViolationException( getClass(),
							S_ProcName,
							S_LocalName,
							attrLocalName );
					}
					attrPriorClusterId = attrs.getValue( idxAttr );
				}
				else if( attrLocalName.equals( "PriorHostNodeId" ) ) {
					if( attrPriorHostNodeId != null ) {
						throw new CFLibUniqueIndexViolationException( getClass(),
							S_ProcName,
							S_LocalName,
							attrLocalName );
					}
					attrPriorHostNodeId = attrs.getValue( idxAttr );
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
			Long natPriorClusterId;
			if( ( attrPriorClusterId == null ) || ( attrPriorClusterId.length() <= 0 ) ) {
				natPriorClusterId = null;
			}
			else {
				natPriorClusterId = Long.valueOf( Long.parseLong( attrPriorClusterId ) );
			}

			Long natPriorHostNodeId;
			if( ( attrPriorHostNodeId == null ) || ( attrPriorHostNodeId.length() <= 0 ) ) {
				natPriorHostNodeId = null;
			}
			else {
				natPriorHostNodeId = Long.valueOf( Long.parseLong( attrPriorHostNodeId ) );
			}

			// Page the objects and prepare the response XML
			List<ICFSecHostNodeObj> list = schemaObj.getHostNodeTableObj().pageAllHostNode( natPriorClusterId,
				natPriorHostNodeId );
			String responseOpening = schemaFormatter.formatRspnXmlPreamble() + "\n"
				+	"\t" + CFSecXMsgHostNodeMessageFormatter.formatHostNodeRspnListOpenTag();
			xmsgRqst.appendResponse( responseOpening );
			Iterator<ICFSecHostNodeObj> iter = list.iterator();
			ICFSecHostNodeObj cur;
			String subxml;
			while( iter.hasNext() ) {
				cur = iter.next();
				subxml = CFSecXMsgHostNodeMessageFormatter.formatHostNodeRspnDerivedRec( "\n\t\t", cur.getHostNodeBuff() );
				xmsgRqst.appendResponse( subxml );
			}
			String responseClosing =
				 	"\n"
				+	"\t" + CFSecXMsgHostNodeMessageFormatter.formatHostNodeRspnListCloseTag()
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
