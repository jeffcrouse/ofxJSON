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

using namespace Json;

class ofxJSONElement: public Value {
public:
	ofxJSONElement() {};
	ofxJSONElement(const string& jsonString);
	ofxJSONElement(Json::Value& v);
	
	bool parse(const string& jsonString);
	bool open(const string& filename);
	bool openLocal(const string& filename);
	bool openRemote(const string& filename, bool secure = false);
	bool save(const string& filename, bool pretty = false) const;
	string getRawString(bool pretty=true) const;

};

#endif