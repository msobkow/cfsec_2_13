
// Description: Java 11 XML SAX Element Handler for SecGroupForm

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

package org.msscf.msscf.v2_13.cfsec.cfsec.CFSecSaxLoader;

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.apache.commons.codec.binary.Base64;
import org.xml.sax.*;
import org.msscf.msscf.v2_13.cflib.CFLib.*;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfsec.CFSecObj.*;

/*
 *	CFSecSaxLoaderSecGroupFormParse XML SAX Element Handler implementation
 *	for SecGroupForm.
 */
public class CFSecSaxLoaderSecGroupForm
	extends CFLibXmlCoreElementHandler
{
	public CFSecSaxLoaderSecGroupForm( CFSecSaxLoader saxLoader ) {
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
		ICFSecSecGroupFormObj origBuff = null;
		ICFSecSecGroupFormEditObj editBuff = null;
		// Common XML Attributes
		String attrId = null;
		// SecGroupForm Attributes
		String attrApp = null;
		String attrForm = null;
		// SecGroupForm References
		ICFSecClusterObj refCluster = null;
		ICFSecSecGroupObj refGroup = null;
		ICFSecSecAppObj refApp = null;
		ICFSecSecFormObj refForm = null;
		// Attribute Extraction
		String attrLocalName;
		int numAttrs;
		int idxAttr;
		final String S_LocalName = "LocalName";
		try {
			assert qName.equals( "SecGroupForm" );

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
			origBuff = (ICFSecSecGroupFormObj)schemaObj.getSecGroupFormTableObj().newInstance();
			editBuff = (ICFSecSecGroupFormEditObj)origBuff.beginEdit();

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
				else if( attrLocalName.equals( "App" ) ) {
					if( attrApp != null ) {
						throw new CFLibUniqueIndexViolationException( getClass(),
							S_ProcName,
							S_LocalName,
							attrLocalName );
					}
					attrApp = attrs.getValue( idxAttr );
				}
				else if( attrLocalName.equals( "Form" ) ) {
					if( attrForm != null ) {
						throw new CFLibUniqueIndexViolationException( getClass(),
							S_ProcName,
							S_LocalName,
							attrLocalName );
					}
					attrForm = attrs.getValue( idxAttr );
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
			if( ( attrApp == null ) || ( attrApp.length() <= 0 ) ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"App" );
			}
			if( ( attrForm == null ) || ( attrForm.length() <= 0 ) ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"Form" );
			}

			// Save named attributes to context
			CFLibXmlCoreContext curContext = getParser().getCurContext();
			curContext.putNamedValue( "Id", attrId );
			curContext.putNamedValue( "App", attrApp );
			curContext.putNamedValue( "Form", attrForm );

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
			else if( scopeObj instanceof ICFSecSecGroupObj ) {
				refGroup = (ICFSecSecGroupObj) scopeObj;
				editBuff.setRequiredContainerGroup( refGroup );
				refCluster = (ICFSecClusterObj)editBuff.getRequiredOwnerCluster();
			}
			else {
				throw new CFLibUnsupportedClassException( getClass(),
					S_ProcName,
					"scopeObj",
					scopeObj,
					"ICFSecSecGroupObj" );
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

			// Lookup refApp by key name value attr
			if( ( attrApp != null ) && ( attrApp.length() > 0 ) ) {
				refApp = (ICFSecSecAppObj)schemaObj.getSecAppTableObj().readSecAppByUJEEMountIdx( editBuff.getRequiredClusterId(),
				attrApp );
				if( refApp == null ) {
					throw new CFLibNullArgumentException( getClass(),
						S_ProcName,
						0,
						"Resolve App reference named \"" + attrApp + "\" to table SecApp" );
				}
			}
			else {
				refApp = null;
			}
			editBuff.setRequiredParentApp( refApp );

			// Lookup refForm by key name value attr
			if( ( attrForm != null ) && ( attrForm.length() > 0 ) ) {
				refForm = (ICFSecSecFormObj)schemaObj.getSecFormTableObj().readSecFormByUJEEServletIdx( editBuff.getRequiredClusterId(),
				editBuff.getRequiredSecAppId(),
				attrForm );
				if( refForm == null ) {
					throw new CFLibNullArgumentException( getClass(),
						S_ProcName,
						0,
						"Resolve Form reference named \"" + attrForm + "\" to table SecForm" );
				}
			}
			else {
				refForm = null;
			}
			editBuff.setRequiredParentForm( refForm );

			CFSecSaxLoader.LoaderBehaviourEnum loaderBehaviour = saxLoader.getSecGroupFormLoaderBehaviour();
			ICFSecSecGroupFormEditObj editSecGroupForm = null;
			ICFSecSecGroupFormObj origSecGroupForm = (ICFSecSecGroupFormObj)schemaObj.getSecGroupFormTableObj().readSecGroupFormByUFormIdx( refCluster.getRequiredId(),
			refGroup.getRequiredSecGroupId(),
			refForm.getRequiredSecFormId() );
			if( origSecGroupForm == null ) {
				editSecGroupForm = editBuff;
			}
			else {
				switch( loaderBehaviour ) {
					case Insert:
						break;
					case Update:
						editSecGroupForm = (ICFSecSecGroupFormEditObj)origSecGroupForm.beginEdit();
						editSecGroupForm.setRequiredParentApp( editBuff.getRequiredParentApp() );
						editSecGroupForm.setRequiredParentForm( editBuff.getRequiredParentForm() );
						break;
					case Replace:
						editSecGroupForm = (ICFSecSecGroupFormEditObj)origSecGroupForm.beginEdit();
						editSecGroupForm.deleteInstance();
						editSecGroupForm = null;
						origSecGroupForm = null;
						editSecGroupForm = editBuff;
						break;
				}
			}

			if( editSecGroupForm != null ) {
				if( origSecGroupForm != null ) {
					editSecGroupForm.update();
				}
				else {
					origSecGroupForm = (ICFSecSecGroupFormObj)editSecGroupForm.create();
				}
				editSecGroupForm = null;
			}

			curContext.putNamedValue( "Object", origSecGroupForm );
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
