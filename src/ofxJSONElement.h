/*
 *  ofxJSONFile.h
 *  asift
 *
 *  Created by Jeffrey Crouse on 12/17/10.
 *  Copyright 2010 Eyebeam. All rights reserved.
 *
 */

#ifndef _OFX_JSON
#define _OFX_JSON

#include <iostream>
#include <fstream>
#include <json/json.h>
#include "ofMain.h"

class ofxJSONElement: public Json::Value {
public:
	ofxJSONElement() {};
	ofxJSONElement(string jsonString);
	ofxJSONElement(Json::Value& v);
	
	bool parse(string jsonString);
	bool open(string filename);
	bool openLocal(string filename, bool inDocuments=false);
	bool openRemote(string filename, bool secure=false);
	bool save(string filename, bool pretty=false, bool inDocuments=false);
	string getRawString(bool pretty=true);

};

const char* valueTypeToString( Json::ValueType type );

#endif