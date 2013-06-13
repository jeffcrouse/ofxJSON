#include "exampleApp.h"


//------------------------------------------------------------------------------
void exampleApp::setup()
{
	// Twitter API: http://dev.twitter.com/doc/get/trends/current
    std::string url = "http://api.twitter.com/1/trends/1.json";
	

	// Now parse the JSON
	bool parsingSuccessful = result.open(url);
	if (parsingSuccessful) {
		cout << result.getRawString() << endl;
	} else {
		cout  << "Failed to parse JSON" << endl;
	}
}

//------------------------------------------------------------------------------
void exampleApp::draw()
{
    ofBackground(0);

	// See this page for all of the ways to access data in a Json::Value
	// http://jsoncpp.sourceforge.net/class_json_1_1_value.html	

	ofSetHexColor(0x00FF00);
	

    if(result.isMember("errors")) {
        ofDrawBitmapString(result.getRawString(), 10, 14);
    } else if(result.isArray()) {
        int n = 0;
        ofxJSONElement trends = result[n]["trends"];
        for(int i = 0; i < trends.size(); i++) {
            std::string message = trends[i]["query"].asString();
            ofDrawBitmapString(message, 10, 40*i+40);
        }
    }

}
