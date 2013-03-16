#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
	
	franklinBook.loadFont("frabk.ttf", 32);
	franklinBook.setLineHeight(36);


	// Twitter API: http://dev.twitter.com/doc/get/trends/current
	string url = "http://api.twitter.com/1/trends/1.json";
	

	// Now parse the JSON
	bool parsingSuccessful = result.open(url);
	if ( parsingSuccessful )
    {
		cout << result.getRawString() << endl;
		
	}
    else
    {
		cout  << "Failed to parse JSON" << endl;
	}
}

//--------------------------------------------------------------
void testApp::draw() {
    ofBackground(0);

	// See this page for all of the ways to access data in a Json::Value
	// http://jsoncpp.sourceforge.net/class_json_1_1_value.html	

	ofSetHexColor(0x00FF00);
	
	int n=0;
	ofxJSONElement trends = result[n]["trends"];
	for(int i=0; i<trends.size(); i++)
	{
		string message = trends[i]["query"].asString();
		franklinBook.drawString(message, 10, 40*i+40);
	}
}