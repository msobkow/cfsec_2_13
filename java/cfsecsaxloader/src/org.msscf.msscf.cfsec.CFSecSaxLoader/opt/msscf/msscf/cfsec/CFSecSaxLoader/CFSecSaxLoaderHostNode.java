
// Description: Java 11 XML SAX Element Handler for HostNode

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

package com.github.msobkow.cfsec.CFSecSaxLoader;

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
 *	CFSecSaxLoaderHostNodeParse XML SAX Element Handler implementation
 *	for HostNode.
 */
public class CFSecSaxLoaderHostNode
	extends CFLibXmlCoreElementHandler
{
	public CFSecSaxLoaderHostNode( CFSecSaxLoader saxLoader ) {
		super( saxLoader );
	}

	public void startElement(
		String		uri,
		String		localName,
		String		qName,
		Attributes	attrs )
	throws SAXException
	{
		final String S_ProcName = "startElement";
		ICFSecHostNodeObj origBuff = null;
		ICFSecHostNodeEditObj editBuff = null;
		// Common XML Attributes
		String attrId = null;
		// HostNode Attributes
		String attrDescription = null;
		String attrHostName = null;
		// HostNode References
		ICFSecClusterObj refCluster = null;
		// Attribute Extraction
		String attrLocalName;
		int numAttrs;
		int idxAttr;
		final String S_LocalName = "LocalName";
		try {
			assert qName.equals( "HostNode" );

			CFSecSaxLoader saxLoader = (CFSecSaxLoader)getParser();
			if( saxLoader == null ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"getParser()" );
			}

			ICFSecSchemaObj schemaObj = saxLoader.getSchemaObj();
			if( schemaObj == null ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"getParser().getSchemaObj()" );
			}

			// Instantiate an edit buffer for the parsed information
			origBuff = (ICFSecHostNodeObj)schemaObj.getHostNodeTableObj().newInstance();
			editBuff = (ICFSecHostNodeEditObj)origBuff.beginEdit();

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
				else if( attrLocalName.equals( "Description" ) ) {
					if( attrDescription != null ) {
						throw new CFLibUniqueIndexViolationException( getClass(),
							S_ProcName,
							S_LocalName,
							attrLocalName );
					}
					attrDescription = attrs.getValue( idxAttr );
				}
				else if( attrLocalName.equals( "HostName" ) ) {
					if( attrHostName != null ) {
						throw new CFLibUniqueIndexViolationException( getClass(),
							S_ProcName,
							S_LocalName,
							attrLocalName );
					}
					attrHostName = attrs.getValue( idxAttr );
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
			if( attrDescription == null ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"Description" );
			}
			if( attrHostName == null ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"HostName" );
			}

			// Save named attributes to context
			CFLibXmlCoreContext curContext = getParser().getCurContext();
			curContext.putNamedValue( "Id", attrId );
			curContext.putNamedValue( "Description", attrDescription );
			curContext.putNamedValue( "HostName", attrHostName );

			// Convert string attributes to native Java types
			// and apply the converted attributes to the editBuff.

			Integer natId;
			if( ( attrId != null ) && ( attrId.length() > 0 ) ) {
				natId = Integer.valueOf( Integer.parseInt( attrId ) );
			}
			else {
				natId = null;
			}
			String natDescription = attrDescription;
			editBuff.setRequiredDescription( natDescription );

			String natHostName = attrHostName;
			editBuff.setRequiredHostName( natHostName );

			// Get the scope/container object

			CFLibXmlCoreContext parentContext = curContext.getPrevContext();
			Object scopeObj;
			if( parentContext != null ) {
				scopeObj = parentContext.getNamedValue( "Object" );
			}
			else {
				scopeObj = null;
			}

			// Resolve and apply required Container reference

			if( scopeObj == null ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"scopeObj" );
			}
			else if( scopeObj instanceof ICFSecClusterObj ) {
				refCluster = (ICFSecClusterObj) scopeObj;
				editBuff.setRequiredContainerCluster( refCluster );
			}
			else {
				throw new CFLibUnsupportedClassException( getClass(),
					S_ProcName,
					"scopeObj",
					scopeObj,
					"ICFSecClusterObj" );
			}

			CFSecSaxLoader.LoaderBehaviourEnum loaderBehaviour = saxLoader.getHostNodeLoaderBehaviour();
			ICFSecHostNodeEditObj editHostNode = null;
			ICFSecHostNodeObj origHostNode = (ICFSecHostNodeObj)schemaObj.getHostNodeTableObj().readHostNodeByHostNameIdx( refCluster.getRequiredId(),
			editBuff.getRequiredHostName() );
			if( origHostNode == null ) {
				editHostNode = editBuff;
			}
			else {
				switch( loaderBehaviour ) {
					case Insert:
						break;
					case Update:
						editHostNode = (ICFSecHostNodeEditObj)origHostNode.beginEdit();
						editHostNode.setRequiredDescription( editBuff.getRequiredDescription() );
						editHostNode.setRequiredHostName( editBuff.getRequiredHostName() );
						break;
					case Replace:
						editHostNode = (ICFSecHostNodeEditObj)origHostNode.beginEdit();
						editHostNode.deleteInstance();
						editHostNode = null;
						origHostNode = null;
						editHostNode = editBuff;
						break;
				}
			}

			if( editHostNode != null ) {
				if( origHostNode != null ) {
					editHostNode.update();
				}
				else {
					origHostNode = (ICFSecHostNodeObj)editHostNode.create();
				}
				editHostNode = null;
			}

			curContext.putNamedValue( "Object", origHostNode );
		}
		catch( RuntimeException e ) {
			throw new SAXException( "Near " + getParser().getLocationInfo() + ": Caught and rethrew " + e.getClass().getName() + " - " + e.getMessage(),
				e );
		}
		catch( Error e ) {
			throw new SAXException( "Near " + getParser().getLocationInfo() + ": Caught and rethrew " + e.getClass().getName() + " - " + e.getMessage() );
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
