/*
 *  ofxJSONFile.cpp
 *  asift
 *
 *  Created by Jeffrey Crouse on 12/17/10.
 *  Copyright 2010 Eyebeam. All rights reserved.
 *
 */

#include "ofxJSONElement.h"




//--------------------------------------------------------------
ofxJSONElement::ofxJSONElement(Json::Value& v) : Value(v) {

}


//--------------------------------------------------------------
bool ofxJSONElement::open(string filename) {
	if(filename.find("http://")==0) {
		return openRemote(filename);
	} else {
		return openLocal(filename);
	}
}


//--------------------------------------------------------------
bool ofxJSONElement::openLocal(string filename) {
	filename = ofToDataPath(filename, true);
	ifstream myfile(filename.c_str());
	
	if (!myfile.is_open()) {
		ofLog(OF_LOG_WARNING, "Could not open "+filename);
		return false;
	}
	
	string str,strTotal;
	getline(myfile, str);
	while ( myfile ) {
		strTotal += str;
		getline(myfile, str);
	}
	myfile.close();
	
	Reader reader;
	if(!reader.parse( strTotal, *this )) {
		ofLog(OF_LOG_WARNING, "Unable to parse "+filename);
		return false;
	}
	return true;
}


//--------------------------------------------------------------
bool ofxJSONElement::openRemote(string filename) {
	URI uri(filename);
	std::string path(uri.getPathAndQuery());
	if (path.empty()) path = "/";
	
	HTTPClientSession session(uri.getHost(), uri.getPort());
	HTTPRequest req(HTTPRequest::HTTP_GET, path, HTTPMessage::HTTP_1_1);
	
	
	session.sendRequest(req);
	HTTPResponse res;
	istream& rs = session.receiveResponse(res);
	std::cout << res.getStatus() << " " << res.getReason() << std::endl;
	
	string result;
	StreamCopier::copyToString(rs, result);
	
	
	Reader reader;
	if(!reader.parse( result, *this )) {
		ofLog(OF_LOG_WARNING, "Unable to parse "+filename);
		return false;
	}
	return true;
}


//--------------------------------------------------------------
bool ofxJSONElement::save(string filename, bool pretty) {
	filename = ofToDataPath(filename, true);
	ofstream file_key(filename.c_str());
	if (!file_key.is_open()) {
		ofLog(OF_LOG_WARNING, "Unable to open "+filename);
		return false;
	}
	
	if(pretty) {
		StyledWriter writer;
		file_key << writer.write( *this ) << endl;
	} else {
		FastWriter writer;
		file_key << writer.write( *this ) << endl;
	}
	ofLog(OF_LOG_NOTICE, "JSON saved to "+filename);
	file_key.close();	
	return true;
}