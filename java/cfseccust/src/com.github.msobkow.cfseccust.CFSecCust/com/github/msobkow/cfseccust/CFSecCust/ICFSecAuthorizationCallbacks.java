// Description: Java 13 Cust JavaFX Schema Interface.

/*
 *	CF Sec Cust JavaFX Implementation
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
 */

package com.github.msobkow.cfseccust.CFSecCust;

import java.security.KeyStore;

import com.github.msobkow.cflib.CFLib.*;
import com.github.msobkow.cflib.CFLib.JavaFX.*;
import com.github.msobkow.cfsec.CFSec.*;
import com.github.msobkow.cfsec.CFSecJavaFX.*;
import com.github.msobkow.cfsec.CFSecObj.*;

/**
 *	The ICFSecAuthorizationCallbacks interface defines the methods
 *	that get invoked after a successful session login and before a session
 *	logout.  This enables the higher level custization code to enable
 *	and disable the tabs of it's interface.
 */
public interface ICFSecAuthorizationCallbacks
{
	void loggedIn();
	void preLogout();
}
