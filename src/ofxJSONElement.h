/*
 *  ofxJSONFile.h
 *  asift
 *
 *  Created by Jeffrey Crouse on 12/17/10.
 *  Copyright 2010 Eyebeam. All rights reserved.
 *
 */

#pragma once

#include <iostream>
#include <fstream>
#include <json/json.h>
#include "ofMain.h"

using namespace Json;
extern "C" size_t decode_html_entities_utf8(char *dest, const char *src);

class ofxJSONElement: public Value {
public:
	ofxJSONElement() {};
	ofxJSONElement(string jsonString);
	ofxJSONElement(Json::Value& v);
	
	bool parse(string jsonString);
	bool open(string filename);
	bool openLocal(string filename);
	bool openRemote(string filename, bool secure=false);
	bool save(string filename, bool pretty=false);
	string getRawString(bool pretty=true);
    

// static
    static string decodeURL(string& str);
    static string decodeEntities(string& str) {
        char dest[ str.length() ];
        decode_html_entities_utf8(dest, str.c_str());
        return string( dest );
    }
};


