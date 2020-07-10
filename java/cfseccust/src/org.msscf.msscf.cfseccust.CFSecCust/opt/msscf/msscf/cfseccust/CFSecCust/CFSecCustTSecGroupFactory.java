// Description: Java 13 JavaFX Display Element Factory for SecGroup.

/*
 *	CF Sec Core Implementation
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
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
 */


package com.github.msobkow.cfseccust.CFSecCust;

import com.github.msobkow.cflib.CFLib.JavaFX.*;

import com.github.msobkow.cfsec.CFSecObj.*;
import com.github.msobkow.cfsec.CFSecJavaFX.*;

/**
 *	CFSecJavaFXSecGroupFactory JavaFX Display Element Factory
 *	for SecGroup.
 */
public class CFSecCustTSecGroupFactory
extends CFSecJavaFXTSecGroupFactory
{
	public CFSecCustTSecGroupFactory( ICFSecJavaFXSchema argSchema ) {
		super( argSchema );
	}

	@Override public CFTabPane newEltTabPane( ICFFormManager formManager, ICFSecTSecGroupObj argFocus ) {
		CFSecCustTSecGroupEltTabPane retnew = new CFSecCustTSecGroupEltTabPane( formManager, javafxSchema, argFocus );
		return( retnew );
	}
}
