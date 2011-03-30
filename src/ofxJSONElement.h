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
#include "json/json.h"
#include "ofMain.h"
#include "Poco/Net/HTTPClientSession.h"
#include "Poco/Net/HTTPRequest.h"
#include "Poco/Net/HTTPResponse.h"
#include "Poco/StreamCopier.h"
#include "Poco/Path.h"
#include "Poco/URI.h"
#include "Poco/Exception.h"
#include "Poco/RegularExpression.h"

using Poco::Net::HTTPClientSession;
using Poco::Net::HTTPRequest;
using Poco::Net::HTTPResponse;
using Poco::Net::HTTPMessage;
using Poco::StreamCopier;
using Poco::Path;
using Poco::URI;
using Poco::Exception;
using Poco::RegularExpression;
using namespace Json;

class ofxJSONElement: public Value {
public:
	ofxJSONElement() {};
	ofxJSONElement(string jsonString);
	ofxJSONElement(Json::Value& v);
	
	bool parse(string jsonString);
	bool open(string filename);
	bool openLocal(string filename);
	bool openRemote(string filename);
	bool save(string filename, bool pretty=false);
	string post(string url, string name, bool pretty=false);
	string getRawString(bool pretty=true);
};

#endif