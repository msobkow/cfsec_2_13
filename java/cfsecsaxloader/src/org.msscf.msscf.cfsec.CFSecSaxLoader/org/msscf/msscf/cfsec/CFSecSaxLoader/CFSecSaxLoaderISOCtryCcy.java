
// Description: Java 11 XML SAX Element Handler for ISOCtryCcy

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

package org.msscf.msscf.cfsec.CFSecSaxLoader;

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.apache.commons.codec.binary.Base64;
import org.xml.sax.*;
import org.msscf.msscf.cflib.CFLib.*;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfsec.CFSecObj.*;

/*
 *	CFSecSaxLoaderISOCtryCcyParse XML SAX Element Handler implementation
 *	for ISOCtryCcy.
 */
public class CFSecSaxLoaderISOCtryCcy
	extends CFLibXmlCoreElementHandler
{
	public CFSecSaxLoaderISOCtryCcy( CFSecSaxLoader saxLoader ) {
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
		ICFSecISOCtryCcyObj origBuff = null;
		ICFSecISOCtryCcyEditObj editBuff = null;
		// Common XML Attributes
		String attrId = null;
		// ISOCtryCcy Attributes
		String attrCcy = null;
		// ISOCtryCcy References
		ICFSecISOCtryObj refCtry = null;
		ICFSecISOCcyObj refCcy = null;
		// Attribute Extraction
		String attrLocalName;
		int numAttrs;
		int idxAttr;
		final String S_LocalName = "LocalName";
		try {
			assert qName.equals( "ISOCtryCcy" );

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
			origBuff = (ICFSecISOCtryCcyObj)schemaObj.getISOCtryCcyTableObj().newInstance();
			editBuff = (ICFSecISOCtryCcyEditObj)origBuff.beginEdit();

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
				else if( attrLocalName.equals( "Ccy" ) ) {
					if( attrCcy != null ) {
						throw new CFLibUniqueIndexViolationException( getClass(),
							S_ProcName,
							S_LocalName,
							attrLocalName );
					}
					attrCcy = attrs.getValue( idxAttr );
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
			if( ( attrCcy == null ) || ( attrCcy.length() <= 0 ) ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"Ccy" );
			}

			// Save named attributes to context
			CFLibXmlCoreContext curContext = getParser().getCurContext();
			curContext.putNamedValue( "Id", attrId );
			curContext.putNamedValue( "Ccy", attrCcy );

			// Convert string attributes to native Java types
			// and apply the converted attributes to the editBuff.

			Integer natId;
			if( ( attrId != null ) && ( attrId.length() > 0 ) ) {
				natId = Integer.valueOf( Integer.parseInt( attrId ) );
			}
			else {
				natId = null;
			}
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
			else if( scopeObj instanceof ICFSecISOCtryObj ) {
				refCtry = (ICFSecISOCtryObj) scopeObj;
				editBuff.setRequiredContainerCtry( refCtry );
			}
			else {
				throw new CFLibUnsupportedClassException( getClass(),
					S_ProcName,
					"scopeObj",
					scopeObj,
					"ICFSecISOCtryObj" );
			}

			// Lookup refCcy by key name value attr
			if( ( attrCcy != null ) && ( attrCcy.length() > 0 ) ) {
				refCcy = (ICFSecISOCcyObj)schemaObj.getISOCcyTableObj().readISOCcyByCcyCdIdx( attrCcy );
				if( refCcy == null ) {
					throw new CFLibNullArgumentException( getClass(),
						S_ProcName,
						0,
						"Resolve Ccy reference named \"" + attrCcy + "\" to table ISOCcy" );
				}
			}
			else {
				refCcy = null;
			}
			editBuff.setRequiredParentCcy( refCcy );

			CFSecSaxLoader.LoaderBehaviourEnum loaderBehaviour = saxLoader.getISOCtryCcyLoaderBehaviour();
			ICFSecISOCtryCcyEditObj editISOCtryCcy = null;
			ICFSecISOCtryCcyObj origISOCtryCcy = (ICFSecISOCtryCcyObj)schemaObj.getISOCtryCcyTableObj().readISOCtryCcyByIdIdx( refCtry.getRequiredISOCtryId(),
			refCcy.getRequiredISOCcyId() );
			if( origISOCtryCcy == null ) {
				editISOCtryCcy = editBuff;
			}
			else {
				switch( loaderBehaviour ) {
					case Insert:
						break;
					case Update:
						editISOCtryCcy = (ICFSecISOCtryCcyEditObj)origISOCtryCcy.beginEdit();
						editISOCtryCcy.setRequiredParentCcy( editBuff.getRequiredParentCcy() );
						break;
					case Replace:
						editISOCtryCcy = (ICFSecISOCtryCcyEditObj)origISOCtryCcy.beginEdit();
						editISOCtryCcy.deleteInstance();
						editISOCtryCcy = null;
						origISOCtryCcy = null;
						editISOCtryCcy = editBuff;
						break;
				}
			}

			if( editISOCtryCcy != null ) {
				if( origISOCtryCcy != null ) {
					editISOCtryCcy.update();
				}
				else {
					origISOCtryCcy = (ICFSecISOCtryCcyObj)editISOCtryCcy.create();
				}
				editISOCtryCcy = null;
			}

			curContext.putNamedValue( "Object", origISOCtryCcy );
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
