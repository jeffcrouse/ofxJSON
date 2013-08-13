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

<<<<<<< HEAD
#pragma once
=======
>>>>>>> 51781d6609531071661c0f3bf167166ebcc34a4e

#pragma once


#include <string>
#include <json/json.h>
#include "ofLog.h"
#include "ofURLFileLoader.h"

<<<<<<< HEAD
using namespace Json;
extern "C" size_t decode_html_entities_utf8(char *dest, const char *src);
=======
>>>>>>> 51781d6609531071661c0f3bf167166ebcc34a4e

class ofxJSONElement : public Json::Value {
public:
	ofxJSONElement() {};
	ofxJSONElement(const std::string& jsonString);
	ofxJSONElement(Json::Value& v);
	
<<<<<<< HEAD
	bool parse(string jsonString);
	bool open(string filename);
	bool openLocal(string filename);
	bool openRemote(string filename, bool secure=false);
	bool save(string filename, bool pretty=false);
	string getRawString(bool pretty=true);
    
=======
	bool parse(const std::string& jsonString);
	bool open(const std::string& filename);
	bool openLocal(const std::string& filename);
	bool openRemote(const std::string& filename);
	bool save(const std::string& filename, bool pretty = false) const;
	std::string getRawString(bool pretty = true) const;
>>>>>>> 51781d6609531071661c0f3bf167166ebcc34a4e

// static
    static string decodeURL(string& str);
    static string decodeEntities(string& str) {
        char dest[ str.length() ];
        decode_html_entities_utf8(dest, str.c_str());
        return string( dest );
    }
};
<<<<<<< HEAD


=======
>>>>>>> 51781d6609531071661c0f3bf167166ebcc34a4e
