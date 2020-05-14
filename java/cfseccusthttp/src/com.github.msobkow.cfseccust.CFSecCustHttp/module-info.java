/*
 *  MSS Code FactoryCFSec 2.13
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

module com.github.msobkow.cfseccust.CFSecCustHttp {
	exports com.github.msobkow.cfseccust.CFSecCustHttp;
	requires transitive com.github.msobkow.cflib.CFLib;
	requires transitive com.github.msobkow.cflib.CFLib.JavaFX;
	requires transitive com.github.msobkow.cfsec;
	requires transitive com.github.msobkow.cfsec.CFSecJavaFX;
	requires transitive com.github.msobkow.cfsec.CFSecXMsg;
	requires transitive com.github.msobkow.cfsec.CFSecXMsgRspn;
	requires transitive com.github.msobkow.cfsec.CFSecXMsgClnt;
	requires transitive com.github.msobkow.cfseccust.CFSecCust;
	requires transitive java.rmi;
	requires transitive java.sql;
	requires org.apache.commons.io;
	requires org.apache.commons.logging;
	requires org.apache.logging.log4j;
	requires org.apache.logging.log4j.core;
	requires org.apache.xercesImpl.xml.schema;
	requires org.eclipse.wst.xml.xpath2.processor;
	requires org.apache.httpcomponents.httpclient;
	requires org.apache.httpcomponents.httpcore;
}

