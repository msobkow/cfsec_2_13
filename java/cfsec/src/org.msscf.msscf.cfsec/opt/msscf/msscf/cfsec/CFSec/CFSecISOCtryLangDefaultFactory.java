
// Description: Java 11 Default Factory implementation for ISOCtryLang.

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

package com.github.msobkow.cfsec.CFSec;

import java.lang.reflect.*;
import java.net.*;
import java.rmi.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import com.github.msobkow.cflib.CFLib.*;

	/*
	 *	CFSecISOCtryLangFactory implementation for ISOCtryLang
	 */
public class CFSecISOCtryLangDefaultFactory
	implements ICFSecISOCtryLangFactory
{
	public CFSecISOCtryLangDefaultFactory() {
	}

	public CFSecISOCtryLangPKey newPKey() {
		CFSecISOCtryLangPKey pkey =
			new CFSecISOCtryLangPKey();
		return( pkey );
	}

	public CFSecISOCtryLangHPKey newHPKey() {
		CFSecISOCtryLangHPKey hpkey =
			new CFSecISOCtryLangHPKey();
		return( hpkey );
	}

	public CFSecISOCtryLangByCtryIdxKey newCtryIdxKey() {
		CFSecISOCtryLangByCtryIdxKey key =
			new CFSecISOCtryLangByCtryIdxKey();
		return( key );
	}

	public CFSecISOCtryLangByLangIdxKey newLangIdxKey() {
		CFSecISOCtryLangByLangIdxKey key =
			new CFSecISOCtryLangByLangIdxKey();
		return( key );
	}

	public CFSecISOCtryLangBuff newBuff() {
		CFSecISOCtryLangBuff buff =
			new CFSecISOCtryLangBuff();
		return( buff );
	}

	public CFSecISOCtryLangHBuff newHBuff() {
		CFSecISOCtryLangHBuff hbuff =
			new CFSecISOCtryLangHBuff();
		return( hbuff );
	}
}
