// Description: Java 11 JavaFX Display Element Factory Interface for Cluster.

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
 *	ICFSecJavaFXClusterFactory JavaFX Display Element Factory Interface
 *	for Cluster.
 */
public interface ICFSecJavaFXClusterFactory
{
	public CFGridPane newAttrPane( ICFFormManager formManager, ICFSecClusterObj javaFXFocus );

	public CFBorderPane newListPane( ICFFormManager formManager,
		ICFLibAnyObj argContainer,
		ICFSecClusterObj argFocus,
		ICFSecJavaFXClusterPageCallback argPageCallback,
		ICFRefreshCallback refreshCallback,
		boolean sortByChain );

	public CFBorderPane newPickerPane( ICFFormManager formManager,
		ICFSecClusterObj argFocus,
		ICFLibAnyObj argContainer,
		ICFSecJavaFXClusterPageCallback argPageCallback,
		ICFSecJavaFXClusterChosen whenChosen );

	public CFTabPane newEltTabPane( ICFFormManager formManger, ICFSecClusterObj javaFXFocus );

	public CFBorderPane newAskDeleteForm( ICFFormManager formManager, ICFSecClusterObj javaFXFocus, ICFDeleteCallback callback );

	public CFSplitPane newAddPane( ICFFormManager formManger, ICFSecClusterObj javaFXFocus );

	public CFSplitPane newViewEditPane( ICFFormManager formManger, ICFSecClusterObj javaFXFocus );

	public CFBorderPane newFinderForm( ICFFormManager formManager );

	public CFBorderPane newPickerForm( ICFFormManager formManager,
		ICFSecClusterObj javaFXFocus,
		ICFLibAnyObj argContainer,
		ICFSecJavaFXClusterPageCallback argPageCallback,
		ICFSecJavaFXClusterChosen whenChosen );

	public CFBorderPane newAddForm( ICFFormManager formManager, ICFSecClusterObj javaFXFocus, ICFFormClosedCallback closeCallback, boolean allowSave );

	public CFBorderPane newViewEditForm( ICFFormManager formManager, ICFSecClusterObj javaFXFocus, ICFFormClosedCallback closeCallback, boolean cameFromAdd );
}