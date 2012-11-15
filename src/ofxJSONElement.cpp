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
ofxJSONElement::ofxJSONElement(Json::Value& v) : Value(v)
{

}


//--------------------------------------------------------------
ofxJSONElement::ofxJSONElement(string jsonString)
{
	parse(jsonString);
}


//--------------------------------------------------------------
bool ofxJSONElement::parse(string jsonString)
{
	Reader reader;
	if(!reader.parse( jsonString, *this )) {
		ofLog(OF_LOG_WARNING, "Unable to parse string");
		return false;
	}
	return true;
}


//--------------------------------------------------------------
bool ofxJSONElement::open(string filename)
{
	if(filename.find("http://")==0 )
    {
		return openRemote(filename);
	}
    else if(filename.find("https://")==0)
    {
		return openRemote(filename, true);
	}
    else
    {
		return openLocal(filename);
	}
}


//--------------------------------------------------------------
bool ofxJSONElement::openLocal(string filename)
{
    ofBuffer buffer = ofBufferFromFile(filename);
	if(buffer.size())
    {
        Reader reader;
        if(!reader.parse( buffer.getText(), *this ))
        {
            ofLog(OF_LOG_WARNING, "Unable to parse "+filename);
            return false;
        }
	} else {
		ofLog(OF_LOG_ERROR, "Could not load file " + filename);
		return false;
	}
    
	return true;
}


//--------------------------------------------------------------
bool ofxJSONElement::openRemote(string filename, bool secure)
{
	string result = ofLoadURL(filename).data.getText();
	
	Reader reader;
	if(!reader.parse( result, *this )) {
		ofLog(OF_LOG_WARNING, "Unable to parse "+filename);
		return false;
	}
	return true;
}


//--------------------------------------------------------------
bool ofxJSONElement::save(string filename, bool pretty)
{
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



//--------------------------------------------------------------
string ofxJSONElement::getRawString(bool pretty)
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

//--------------------------------------------------------------
string ofxJSONElement::decodeURL(string &SRC)
{
    string ret;
    char ch;
    int i, ii;
    for (i=0; i<SRC.length(); i++) {
        if (int(SRC[i])==37) {
            sscanf(SRC.substr(i+1,2).c_str(), "%x", &ii);
            ch=static_cast<char>(ii);
            ret+=ch;
            i=i+2;
        } else {
            ret+=SRC[i];
        }
    }
    return (ret);
}
