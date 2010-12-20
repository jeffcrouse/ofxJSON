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
	
	bool open(string filename) {
		if(filename.find("http://")==0) {
			return openRemote(filename);
		} else {
			return openLocal(filename);
		}
	}
	
	bool openLocal(string filename) {
		ifstream myfile(filename.c_str());
		
		if (!myfile.is_open()) {
			ofLog(OF_LOG_WARNING, "Could not open "+filename+" to load keypoints");
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
	
	bool openRemote(string filename) {
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
	
	bool save(string filename, bool pretty=false) {
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
		
		file_key.close();	
		return true;
	}
	
};

#endif