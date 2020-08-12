
// Description: Java 11 XML SAX Element Handler for TSecGrpInc

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
 *	CFSecSaxLoaderTSecGrpIncParse XML SAX Element Handler implementation
 *	for TSecGrpInc.
 */
public class CFSecSaxLoaderTSecGrpInc
	extends CFLibXmlCoreElementHandler
{
	public CFSecSaxLoaderTSecGrpInc( CFSecSaxLoader saxLoader ) {
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
		ICFSecTSecGrpIncObj origBuff = null;
		ICFSecTSecGrpIncEditObj editBuff = null;
		// Common XML Attributes
		String attrId = null;
		// TSecGrpInc Attributes
		String attrSubGroup = null;
		// TSecGrpInc References
		ICFSecTenantObj refTenant = null;
		ICFSecTSecGroupObj refGroup = null;
		ICFSecTSecGroupObj refSubGroup = null;
		// Attribute Extraction
		String attrLocalName;
		int numAttrs;
		int idxAttr;
		final String S_LocalName = "LocalName";
		try {
			assert qName.equals( "TSecGrpInc" );

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
			origBuff = (ICFSecTSecGrpIncObj)schemaObj.getTSecGrpIncTableObj().newInstance();
			editBuff = (ICFSecTSecGrpIncEditObj)origBuff.beginEdit();

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
				else if( attrLocalName.equals( "SubGroup" ) ) {
					if( attrSubGroup != null ) {
						throw new CFLibUniqueIndexViolationException( getClass(),
							S_ProcName,
							S_LocalName,
							attrLocalName );
					}
					attrSubGroup = attrs.getValue( idxAttr );
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
			if( ( attrSubGroup == null ) || ( attrSubGroup.length() <= 0 ) ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"SubGroup" );
			}

			// Save named attributes to context
			CFLibXmlCoreContext curContext = getParser().getCurContext();
			curContext.putNamedValue( "Id", attrId );
			curContext.putNamedValue( "SubGroup", attrSubGroup );

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
			else if( scopeObj instanceof ICFSecTSecGroupObj ) {
				refGroup = (ICFSecTSecGroupObj) scopeObj;
				editBuff.setRequiredContainerGroup( refGroup );
				refTenant = (ICFSecTenantObj)editBuff.getRequiredOwnerTenant();
			}
			else {
				throw new CFLibUnsupportedClassException( getClass(),
					S_ProcName,
					"scopeObj",
					scopeObj,
					"ICFSecTSecGroupObj" );
			}

			// Resolve and apply Owner reference

			if( refTenant == null ) {
				if( scopeObj instanceof ICFSecTenantObj ) {
					refTenant = (ICFSecTenantObj) scopeObj;
					editBuff.setRequiredOwnerTenant( refTenant );
				}
				else {
					throw new CFLibNullArgumentException( getClass(),
						S_ProcName,
						0,
						"Owner<Tenant>" );
				}
			}

			// Lookup refSubGroup by key name value attr
			if( ( attrSubGroup != null ) && ( attrSubGroup.length() > 0 ) ) {
				refSubGroup = (ICFSecTSecGroupObj)schemaObj.getTSecGroupTableObj().readTSecGroupByUNameIdx( editBuff.getRequiredTenantId(),
				attrSubGroup );
				if( refSubGroup == null ) {
					throw new CFLibNullArgumentException( getClass(),
						S_ProcName,
						0,
						"Resolve SubGroup reference named \"" + attrSubGroup + "\" to table TSecGroup" );
				}
			}
			else {
				refSubGroup = null;
			}
			editBuff.setRequiredParentSubGroup( refSubGroup );

			CFSecSaxLoader.LoaderBehaviourEnum loaderBehaviour = saxLoader.getTSecGrpIncLoaderBehaviour();
			ICFSecTSecGrpIncEditObj editTSecGrpInc = null;
			ICFSecTSecGrpIncObj origTSecGrpInc = (ICFSecTSecGrpIncObj)schemaObj.getTSecGrpIncTableObj().readTSecGrpIncByUIncludeIdx( refTenant.getRequiredId(),
			refGroup.getRequiredTSecGroupId(),
			refSubGroup.getRequiredTSecGroupId() );
			if( origTSecGrpInc == null ) {
				editTSecGrpInc = editBuff;
			}
			else {
				switch( loaderBehaviour ) {
					case Insert:
						break;
					case Update:
						editTSecGrpInc = (ICFSecTSecGrpIncEditObj)origTSecGrpInc.beginEdit();
						editTSecGrpInc.setRequiredParentSubGroup( editBuff.getRequiredParentSubGroup() );
						break;
					case Replace:
						editTSecGrpInc = (ICFSecTSecGrpIncEditObj)origTSecGrpInc.beginEdit();
						editTSecGrpInc.deleteInstance();
						editTSecGrpInc = null;
						origTSecGrpInc = null;
						editTSecGrpInc = editBuff;
						break;
				}
			}

			if( editTSecGrpInc != null ) {
				if( origTSecGrpInc != null ) {
					editTSecGrpInc.update();
				}
				else {
					origTSecGrpInc = (ICFSecTSecGrpIncObj)editTSecGrpInc.create();
				}
				editTSecGrpInc = null;
			}

			curContext.putNamedValue( "Object", origTSecGrpInc );
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
