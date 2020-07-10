// Description: Java 11 JavaFX Display Element Factory Interface for HostNode.

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

package com.github.msobkow.cfsec.CFSecJavaFX;

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import com.github.msobkow.cflib.CFLib.*;
import com.github.msobkow.cflib.CFLib.JavaFX.*;
import org.apache.commons.codec.binary.Base64;
import com.github.msobkow.cfsec.CFSec.*;
import com.github.msobkow.cfsec.CFSecObj.*;

/**
 *	ICFSecJavaFXHostNodeFactory JavaFX Display Element Factory Interface
 *	for HostNode.
 */
public interface ICFSecJavaFXHostNodeFactory
{
	public CFGridPane newAttrPane( ICFFormManager formManager, ICFSecHostNodeObj javaFXFocus );

	public CFBorderPane newListPane( ICFFormManager formManager,
		ICFSecClusterObj argContainer,
		ICFSecHostNodeObj argFocus,
		ICFSecJavaFXHostNodePageCallback argPageCallback,
		ICFRefreshCallback refreshCallback,
		boolean sortByChain );

	public CFBorderPane newPickerPane( ICFFormManager formManager,
		ICFSecHostNodeObj argFocus,
		ICFSecClusterObj argContainer,
		ICFSecJavaFXHostNodePageCallback argPageCallback,
		ICFSecJavaFXHostNodeChosen whenChosen );

	public CFTabPane newEltTabPane( ICFFormManager formManger, ICFSecHostNodeObj javaFXFocus );

	public CFBorderPane newAskDeleteForm( ICFFormManager formManager, ICFSecHostNodeObj javaFXFocus, ICFDeleteCallback callback );

	public CFSplitPane newAddPane( ICFFormManager formManger, ICFSecHostNodeObj javaFXFocus );

	public CFSplitPane newViewEditPane( ICFFormManager formManger, ICFSecHostNodeObj javaFXFocus );

	public CFBorderPane newFinderForm( ICFFormManager formManager );

	public CFBorderPane newPickerForm( ICFFormManager formManager,
		ICFSecHostNodeObj javaFXFocus,
		ICFSecClusterObj argContainer,
		ICFSecJavaFXHostNodePageCallback argPageCallback,
		ICFSecJavaFXHostNodeChosen whenChosen );

	public CFBorderPane newAddForm( ICFFormManager formManager, ICFSecHostNodeObj javaFXFocus, ICFFormClosedCallback closeCallback, boolean allowSave );

	public CFBorderPane newViewEditForm( ICFFormManager formManager, ICFSecHostNodeObj javaFXFocus, ICFFormClosedCallback closeCallback, boolean cameFromAdd );
}
