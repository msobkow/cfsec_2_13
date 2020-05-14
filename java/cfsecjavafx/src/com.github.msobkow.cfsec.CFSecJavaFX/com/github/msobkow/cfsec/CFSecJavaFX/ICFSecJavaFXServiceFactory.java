// Description: Java 11 JavaFX Display Element Factory Interface for Service.

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
 *	ICFSecJavaFXServiceFactory JavaFX Display Element Factory Interface
 *	for Service.
 */
public interface ICFSecJavaFXServiceFactory
{
	public CFGridPane newAttrPane( ICFFormManager formManager, ICFSecServiceObj javaFXFocus );

	public CFBorderPane newListPane( ICFFormManager formManager,
		ICFSecHostNodeObj argContainer,
		ICFSecServiceObj argFocus,
		ICFSecJavaFXServicePageCallback argPageCallback,
		ICFRefreshCallback refreshCallback,
		boolean sortByChain );

	public CFBorderPane newPickerPane( ICFFormManager formManager,
		ICFSecServiceObj argFocus,
		ICFSecHostNodeObj argContainer,
		ICFSecJavaFXServicePageCallback argPageCallback,
		ICFSecJavaFXServiceChosen whenChosen );

	public CFTabPane newEltTabPane( ICFFormManager formManger, ICFSecServiceObj javaFXFocus );

	public CFBorderPane newAskDeleteForm( ICFFormManager formManager, ICFSecServiceObj javaFXFocus, ICFDeleteCallback callback );

	public CFSplitPane newAddPane( ICFFormManager formManger, ICFSecServiceObj javaFXFocus );

	public CFSplitPane newViewEditPane( ICFFormManager formManger, ICFSecServiceObj javaFXFocus );

	public CFBorderPane newPickerForm( ICFFormManager formManager,
		ICFSecServiceObj javaFXFocus,
		ICFSecHostNodeObj argContainer,
		ICFSecJavaFXServicePageCallback argPageCallback,
		ICFSecJavaFXServiceChosen whenChosen );

	public CFBorderPane newAddForm( ICFFormManager formManager, ICFSecServiceObj javaFXFocus, ICFFormClosedCallback closeCallback, boolean allowSave );

	public CFBorderPane newViewEditForm( ICFFormManager formManager, ICFSecServiceObj javaFXFocus, ICFFormClosedCallback closeCallback, boolean cameFromAdd );
}
