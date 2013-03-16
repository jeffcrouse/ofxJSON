/*
 *  ofxJSONFile.h
 *  asift
 *
 *  Created by Jeffrey Crouse on 12/17/10.
 *  Copyright 2010 Eyebeam. All rights reserved.
 *
 *  Updates by Christopher Baker 2012 - 2013
 *  http://christopherbaker.net
 *
 */

#pragma once

#include <string>

#include <json/json.h>

#include "ofLog.h"
#include "ofURLFileLoader.h"

using std::string;

using namespace Json;

class ofxJSONElement : public Value {
public:
	ofxJSONElement() {};
	ofxJSONElement(const string& jsonString);
	ofxJSONElement(Json::Value& v);
	
	bool parse(const string& jsonString);
	bool open(const string& filename);
	bool openLocal(const string& filename);
	bool openRemote(const string& filename);
	bool save(const string& filename, bool pretty = false) const;
	string getRawString(bool pretty=true) const;

};
