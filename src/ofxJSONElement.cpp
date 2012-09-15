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
ofxJSONElement::ofxJSONElement(Json::Value& v) : Value(v) {}

//--------------------------------------------------------------
ofxJSONElement::ofxJSONElement(const string& jsonString) {
	parse(jsonString);
}

//--------------------------------------------------------------
bool ofxJSONElement::parse(const string& jsonString) {
	Reader reader;
	if(!reader.parse( jsonString, *this )) {
		ofLogError("ofxJSONElement") << "Unable to parse string.";
		return false;
	}
	return true;
}


//--------------------------------------------------------------
bool ofxJSONElement::open(const string& filename) {
	if(filename.find("http://")==0 ) {
		return openRemote(filename);
	}else if(filename.find("https://")==0) {
		return openRemote(filename, true);
	} else {
		return openLocal(filename);
	}
}


//--------------------------------------------------------------
bool ofxJSONElement::openLocal(const string& filename) {
    
    ofBuffer buffer = ofBufferFromFile(filename);
	
    Reader reader;
	if(!reader.parse( buffer.getText(), *this )) {
		ofLogError("ofxJSONElement") << "Unable to parse " << filename << ".";
		return false;
	}
	return true;
}


//--------------------------------------------------------------
bool ofxJSONElement::openRemote(const string& filename, bool secure)
{
	string result = ofLoadURL(filename).data.getText();
	
	Reader reader;
	if(!reader.parse( result, *this )) {
		ofLogError("ofxJSONElement") << "Unable to parse " << filename << ".";
		return false;
	}
	return true;
}


//--------------------------------------------------------------
bool ofxJSONElement::save(const string& filename, bool pretty) const
{
	string fname = ofToDataPath(filename, true);
	ofstream file_key(fname.c_str());
	if (!file_key.is_open()) {
		ofLogError("ofxJSONElement") << "Unable to open " << fname << ".";
		return false;
	}
	
	if(pretty) {
		StyledWriter writer;
		file_key << writer.write( *this ) << endl;
	} else {
		FastWriter writer;
		file_key << writer.write( *this ) << endl;
	}
    ofLogVerbose("ofxJSONElement") << "JSON saved to " << fname << ".";
	file_key.close();	
	return true;
}


//--------------------------------------------------------------
string ofxJSONElement::getRawString(bool pretty) const
{
	string raw;
	if(pretty) {
		StyledWriter writer;
		raw = writer.write(*this);
	} else {
		FastWriter writer;
		raw = writer.write(*this);
	}
	return raw;
}
