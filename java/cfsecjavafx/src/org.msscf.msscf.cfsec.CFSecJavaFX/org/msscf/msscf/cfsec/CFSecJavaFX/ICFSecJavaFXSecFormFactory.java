// Description: Java 11 JavaFX Display Element Factory Interface for SecForm.

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

package org.msscf.msscf.cfsec.CFSecJavaFX;

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.msscf.msscf.cflib.CFLib.*;
import org.msscf.msscf.cflib.CFLib.JavaFX.*;
import org.apache.commons.codec.binary.Base64;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfsec.CFSecObj.*;

/**
 *	ICFSecJavaFXSecFormFactory JavaFX Display Element Factory Interface
 *	for SecForm.
 */
public interface ICFSecJavaFXSecFormFactory
{
	public CFGridPane newAttrPane( ICFFormManager formManager, ICFSecSecFormObj javaFXFocus );

	public CFBorderPane newListPane( ICFFormManager formManager,
		ICFSecSecAppObj argContainer,
		ICFSecSecFormObj argFocus,
		ICFSecJavaFXSecFormPageCallback argPageCallback,
		ICFRefreshCallback refreshCallback,
		boolean sortByChain );

	public CFBorderPane newPickerPane( ICFFormManager formManager,
		ICFSecSecFormObj argFocus,
		ICFSecSecAppObj argContainer,
		ICFSecJavaFXSecFormPageCallback argPageCallback,
		ICFSecJavaFXSecFormChosen whenChosen );

	public CFTabPane newEltTabPane( ICFFormManager formManger, ICFSecSecFormObj javaFXFocus );

	public CFBorderPane newAskDeleteForm( ICFFormManager formManager, ICFSecSecFormObj javaFXFocus, ICFDeleteCallback callback );

	public CFSplitPane newAddPane( ICFFormManager formManger, ICFSecSecFormObj javaFXFocus );

	public CFSplitPane newViewEditPane( ICFFormManager formManger, ICFSecSecFormObj javaFXFocus );

	public CFBorderPane newPickerForm( ICFFormManager formManager,
		ICFSecSecFormObj javaFXFocus,
		ICFSecSecAppObj argContainer,
		ICFSecJavaFXSecFormPageCallback argPageCallback,
		ICFSecJavaFXSecFormChosen whenChosen );

	public CFBorderPane newAddForm( ICFFormManager formManager, ICFSecSecFormObj javaFXFocus, ICFFormClosedCallback closeCallback, boolean allowSave );

	public CFBorderPane newViewEditForm( ICFFormManager formManager, ICFSecSecFormObj javaFXFocus, ICFFormClosedCallback closeCallback, boolean cameFromAdd );
}
