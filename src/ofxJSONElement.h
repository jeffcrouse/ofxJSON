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


class ofxJSONElement : public Json::Value {
public:
	ofxJSONElement() {};
	ofxJSONElement(const std::string& jsonString);
	ofxJSONElement(Json::Value& v);
	
	bool parse(const std::string& jsonString);
	bool open(const std::string& filename);
	bool openLocal(const std::string& filename);
	bool openRemote(const std::string& filename);
	bool save(const std::string& filename, bool pretty = false) const;
	std::string getRawString(bool pretty = true) const;

};
