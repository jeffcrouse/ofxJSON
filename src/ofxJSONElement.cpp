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
ofxJSONElement::ofxJSONElement(Json::Value& v) : Value(v) {

}

//--------------------------------------------------------------
ofxJSONElement::ofxJSONElement(string jsonString) {
	parse(jsonString);
}

//--------------------------------------------------------------
bool ofxJSONElement::parse(string jsonString) {
	Reader reader;
	if(!reader.parse( jsonString, *this )) {
		ofLog(OF_LOG_WARNING, "Unable to parse string");
		return false;
	}
	return true;
}


//--------------------------------------------------------------
bool ofxJSONElement::open(string filename) {
	if(filename.find("http://")==0 ) {
		return openRemote(filename);
	}else if(filename.find("https://")==0) {
		return openRemote(filename, true);
	} else {
		return openLocal(filename);
	}
}


//--------------------------------------------------------------
bool ofxJSONElement::openLocal(string filename) {
	filename = ofToDataPath(filename, true);
	ifstream myfile(filename.c_str());
	
	if (!myfile.is_open()) {
		ofLog(OF_LOG_WARNING, "Could not open "+filename);
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


//--------------------------------------------------------------
bool ofxJSONElement::openRemote(string filename, bool secure)
{
	string result = get(filename, false);
	
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
string ofxJSONElement::postTo(string url) 
{
	return post(url, getRawString());
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

// -------------------------------------------------------------
string ofxJSONElement::get(string url, bool verbose)
{
	return curl("get", url.c_str(), NULL, verbose);
}


// -------------------------------------------------------------
string ofxJSONElement::post(string url, string data, bool verbose)
{
	return curl("post", url.c_str(), data.c_str(), verbose);
}


// -------------------------------------------------------------
string ofxJSONElement::curl(const char* method, const char* endpoint, const char* data, bool verbose)
{
	string str;
	
	static char errorBuffer[CURL_ERROR_SIZE];
	CURL *curl = curl_easy_init();
	CURLcode result;
	if (!curl) {
		throw "Couldn't create CURL object.";
	}
	
	// Set the headers
	struct curl_slist *headers=NULL;
	headers = curl_slist_append(headers, "User-Agent: spider");
	
	const char* cookie_file = "cookies.txt";
	if(verbose) cout << "saving cookies to " << cookie_file << endl;
	
	// TO DO:
	// Set timeout limit
	// put the whoel thing in a try block
	curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, errorBuffer);
	curl_easy_setopt(curl, CURLOPT_URL, endpoint);
	curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
	curl_easy_setopt(curl, CURLOPT_TIMEOUT_MS, 2000);
	curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
	curl_easy_setopt(curl, CURLOPT_COOKIEJAR, cookie_file);
	curl_easy_setopt(curl, CURLOPT_COOKIEFILE, cookie_file);
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeData);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &str);
	
	if(strcmp(method, "post")==0 && data)
	{
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data); 
	}
	
	result = curl_easy_perform(curl);
	curl_easy_cleanup(curl);
	curl_slist_free_all(headers);
	
	// Did we succeed?
	if (result != CURLE_OK)
	{
		if(verbose) cerr << "Bad result from CURL" << endl;
		return "";						
	}
	
	long http_code = 0;
	curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
	char status_msg[255];
	sprintf(status_msg, "HTTP status code: %ld", http_code);
	if(verbose) cerr << status_msg << endl;
	if (http_code != 200 || result == CURLE_ABORTED_BY_CALLBACK)
	{
		if(verbose) cerr << "HTTP error" << endl;
		return "";
	}
	
	return str;
}


#pragma mark PRIVATE METHODS

// -------------------------------------------------------------
int ofxJSONElement::writeData(char *data, size_t size, size_t nmemb, std::string *buffer)
{
	int result = 0;
	if (buffer != NULL) {
		buffer->append(data, size * nmemb);
		result = size * nmemb;
	}
	return result;
}