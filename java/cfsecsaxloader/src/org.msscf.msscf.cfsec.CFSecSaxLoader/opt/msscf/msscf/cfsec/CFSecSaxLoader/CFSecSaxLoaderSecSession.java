
// Description: Java 11 XML SAX Element Handler for SecSession

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
 *	CFSecSaxLoaderSecSessionParse XML SAX Element Handler implementation
 *	for SecSession.
 */
public class CFSecSaxLoaderSecSession
	extends CFLibXmlCoreElementHandler
{
	public CFSecSaxLoaderSecSession( CFSecSaxLoader saxLoader ) {
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
		ICFSecSecSessionObj origBuff = null;
		ICFSecSecSessionEditObj editBuff = null;
		// Common XML Attributes
		String attrId = null;
		// SecSession Attributes
		String attrSecDevName = null;
		String attrStart = null;
		String attrFinish = null;
		String attrSecProxy = null;
		// SecSession References
		ICFSecSecUserObj refSecUser = null;
		ICFSecSecUserObj refSecProxy = null;
		// Attribute Extraction
		String attrLocalName;
		int numAttrs;
		int idxAttr;
		final String S_LocalName = "LocalName";
		try {
			assert qName.equals( "SecSession" );

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
			origBuff = (ICFSecSecSessionObj)schemaObj.getSecSessionTableObj().newInstance();
			editBuff = (ICFSecSecSessionEditObj)origBuff.beginEdit();

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
				else if( attrLocalName.equals( "SecDevName" ) ) {
					if( attrSecDevName != null ) {
						throw new CFLibUniqueIndexViolationException( getClass(),
							S_ProcName,
							S_LocalName,
							attrLocalName );
					}
					attrSecDevName = attrs.getValue( idxAttr );
				}
				else if( attrLocalName.equals( "Start" ) ) {
					if( attrStart != null ) {
						throw new CFLibUniqueIndexViolationException( getClass(),
							S_ProcName,
							S_LocalName,
							attrLocalName );
					}
					attrStart = attrs.getValue( idxAttr );
				}
				else if( attrLocalName.equals( "Finish" ) ) {
					if( attrFinish != null ) {
						throw new CFLibUniqueIndexViolationException( getClass(),
							S_ProcName,
							S_LocalName,
							attrLocalName );
					}
					attrFinish = attrs.getValue( idxAttr );
				}
				else if( attrLocalName.equals( "SecProxy" ) ) {
					if( attrSecProxy != null ) {
						throw new CFLibUniqueIndexViolationException( getClass(),
							S_ProcName,
							S_LocalName,
							attrLocalName );
					}
					attrSecProxy = attrs.getValue( idxAttr );
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
			if( ( attrStart == null ) || ( attrStart.length() <= 0 ) ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"Start" );
			}
			if( ( attrSecProxy == null ) || ( attrSecProxy.length() <= 0 ) ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"SecProxy" );
			}

			// Save named attributes to context
			CFLibXmlCoreContext curContext = getParser().getCurContext();
			curContext.putNamedValue( "Id", attrId );
			curContext.putNamedValue( "SecDevName", attrSecDevName );
			curContext.putNamedValue( "Start", attrStart );
			curContext.putNamedValue( "Finish", attrFinish );
			curContext.putNamedValue( "SecProxy", attrSecProxy );

			// Convert string attributes to native Java types
			// and apply the converted attributes to the editBuff.

			Integer natId;
			if( ( attrId != null ) && ( attrId.length() > 0 ) ) {
				natId = Integer.valueOf( Integer.parseInt( attrId ) );
			}
			else {
				natId = null;
			}
			String natSecDevName = attrSecDevName;
			editBuff.setOptionalSecDevName( natSecDevName );

			Calendar natStart;
			try {
				natStart = CFLibXmlUtil.parseTimestamp( attrStart );
			}
			catch( RuntimeException e ) {
				throw new CFLibInvalidArgumentException( getClass(),
					S_ProcName,
					0,
					"Start",
					attrStart,
					e );
			}
			editBuff.setRequiredStart( natStart );

			Calendar natFinish;
			if( ( attrFinish == null ) || ( attrFinish.length() <= 0 ) ) {
				natFinish = null;
			}
			else {
				try {
					natFinish = CFLibXmlUtil.parseTimestamp( attrFinish );
				}
				catch( RuntimeException e ) {
					throw new CFLibInvalidArgumentException( getClass(),
						S_ProcName,
						0,
						"Finish",
						attrFinish,
						e );
				}
			}
			editBuff.setOptionalFinish( natFinish );

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
			else if( scopeObj instanceof ICFSecSecUserObj ) {
				refSecUser = (ICFSecSecUserObj) scopeObj;
				editBuff.setRequiredContainerSecUser( refSecUser );
			}
			else {
				throw new CFLibUnsupportedClassException( getClass(),
					S_ProcName,
					"scopeObj",
					scopeObj,
					"ICFSecSecUserObj" );
			}

			// Lookup refSecProxy by key name value attr
			if( ( attrSecProxy != null ) && ( attrSecProxy.length() > 0 ) ) {
				refSecProxy = (ICFSecSecUserObj)schemaObj.getSecUserTableObj().readSecUserByULoginIdx( attrSecProxy );
				if( refSecProxy == null ) {
					throw new CFLibNullArgumentException( getClass(),
						S_ProcName,
						0,
						"Resolve SecProxy reference named \"" + attrSecProxy + "\" to table SecUser" );
				}
			}
			else {
				refSecProxy = null;
			}
			editBuff.setRequiredParentSecProxy( refSecProxy );

			ICFSecSecSessionObj origSecSession;
			ICFSecSecSessionEditObj editSecSession = editBuff;
			origSecSession = (ICFSecSecSessionObj)editSecSession.create();
			editSecSession = null;

			curContext.putNamedValue( "Object", origSecSession );
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
