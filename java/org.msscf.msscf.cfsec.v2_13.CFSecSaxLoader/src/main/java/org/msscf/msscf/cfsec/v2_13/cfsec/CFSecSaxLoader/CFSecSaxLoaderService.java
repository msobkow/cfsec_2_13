
// Description: Java 11 XML SAX Element Handler for Service

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

package org.msscf.msscf.cfsec.v2_13.cfsec.CFSecSaxLoader;

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.apache.commons.codec.binary.Base64;
import org.xml.sax.*;
import org.msscf.msscf.cflib.v2_13.CFLib.*;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfsec.CFSecObj.*;

/*
 *	CFSecSaxLoaderServiceParse XML SAX Element Handler implementation
 *	for Service.
 */
public class CFSecSaxLoaderService
	extends CFLibXmlCoreElementHandler
{
	public CFSecSaxLoaderService( CFSecSaxLoader saxLoader ) {
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
		ICFSecServiceObj origBuff = null;
		ICFSecServiceEditObj editBuff = null;
		// Common XML Attributes
		String attrId = null;
		// Service Attributes
		String attrHostPort = null;
		String attrServiceType = null;
		// Service References
		ICFSecClusterObj refCluster = null;
		ICFSecHostNodeObj refHost = null;
		ICFSecServiceTypeObj refServiceType = null;
		// Attribute Extraction
		String attrLocalName;
		int numAttrs;
		int idxAttr;
		final String S_LocalName = "LocalName";
		try {
			assert qName.equals( "Service" );

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
			origBuff = (ICFSecServiceObj)schemaObj.getServiceTableObj().newInstance();
			editBuff = (ICFSecServiceEditObj)origBuff.beginEdit();

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
				else if( attrLocalName.equals( "HostPort" ) ) {
					if( attrHostPort != null ) {
						throw new CFLibUniqueIndexViolationException( getClass(),
							S_ProcName,
							S_LocalName,
							attrLocalName );
					}
					attrHostPort = attrs.getValue( idxAttr );
				}
				else if( attrLocalName.equals( "ServiceType" ) ) {
					if( attrServiceType != null ) {
						throw new CFLibUniqueIndexViolationException( getClass(),
							S_ProcName,
							S_LocalName,
							attrLocalName );
					}
					attrServiceType = attrs.getValue( idxAttr );
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
			if( ( attrHostPort == null ) || ( attrHostPort.length() <= 0 ) ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"HostPort" );
			}

			// Save named attributes to context
			CFLibXmlCoreContext curContext = getParser().getCurContext();
			curContext.putNamedValue( "Id", attrId );
			curContext.putNamedValue( "HostPort", attrHostPort );
			curContext.putNamedValue( "ServiceType", attrServiceType );

			// Convert string attributes to native Java types
			// and apply the converted attributes to the editBuff.

			Integer natId;
			if( ( attrId != null ) && ( attrId.length() > 0 ) ) {
				natId = Integer.valueOf( Integer.parseInt( attrId ) );
			}
			else {
				natId = null;
			}
			short natHostPort = Short.parseShort( attrHostPort );
			editBuff.setRequiredHostPort( natHostPort );

			// Get the scope/container object

			CFLibXmlCoreContext parentContext = curContext.getPrevContext();
			Object scopeObj;
			if( parentContext != null ) {
				scopeObj = parentContext.getNamedValue( "Object" );
			}
			else {
				scopeObj = null;
			}

			// Resolve and apply optional Container reference

			if( scopeObj == null ) {
				refHost = null;
				editBuff.setOptionalContainerHost( refHost );
				refCluster = (ICFSecClusterObj)editBuff.getRequiredOwnerCluster();
			}
			else if( scopeObj instanceof ICFSecHostNodeObj ) {
				refHost = (ICFSecHostNodeObj) scopeObj;
				editBuff.setOptionalContainerHost( refHost );
				refCluster = (ICFSecClusterObj)editBuff.getRequiredOwnerCluster();
			}
			else {
				throw new CFLibUnsupportedClassException( getClass(),
					S_ProcName,
					"scopeObj",
					scopeObj,
					"ICFSecHostNodeObj" );
			}

			// Resolve and apply Owner reference

			if( refCluster == null ) {
				if( scopeObj instanceof ICFSecClusterObj ) {
					refCluster = (ICFSecClusterObj) scopeObj;
					editBuff.setRequiredOwnerCluster( refCluster );
				}
				else {
					throw new CFLibNullArgumentException( getClass(),
						S_ProcName,
						0,
						"Owner<Cluster>" );
				}
			}

			// Lookup refServiceType by key name value attr
			if( ( attrServiceType != null ) && ( attrServiceType.length() > 0 ) ) {
				refServiceType = (ICFSecServiceTypeObj)schemaObj.getServiceTypeTableObj().readServiceTypeByUDescrIdx( attrServiceType );
				if( refServiceType == null ) {
					throw new CFLibNullArgumentException( getClass(),
						S_ProcName,
						0,
						"Resolve ServiceType reference named \"" + attrServiceType + "\" to table ServiceType" );
				}
			}
			else {
				refServiceType = null;
			}
			editBuff.setOptionalParentServiceType( refServiceType );

			CFSecSaxLoader.LoaderBehaviourEnum loaderBehaviour = saxLoader.getServiceLoaderBehaviour();
			ICFSecServiceEditObj editService = null;
			ICFSecServiceObj origService = (ICFSecServiceObj)schemaObj.getServiceTableObj().readServiceByUTypeIdx( refCluster.getRequiredId(),
			refHost.getRequiredHostNodeId(),
			refServiceType.getRequiredServiceTypeId() );
			if( origService == null ) {
				editService = editBuff;
			}
			else {
				switch( loaderBehaviour ) {
					case Insert:
						break;
					case Update:
						editService = (ICFSecServiceEditObj)origService.beginEdit();
						editService.setRequiredHostPort( editBuff.getRequiredHostPort() );
						editService.setOptionalParentServiceType( editBuff.getOptionalParentServiceType() );
						break;
					case Replace:
						editService = (ICFSecServiceEditObj)origService.beginEdit();
						editService.deleteInstance();
						editService = null;
						origService = null;
						editService = editBuff;
						break;
				}
			}

			if( editService != null ) {
				if( origService != null ) {
					editService.update();
				}
				else {
					origService = (ICFSecServiceObj)editService.create();
				}
				editService = null;
			}

			curContext.putNamedValue( "Object", origService );
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
