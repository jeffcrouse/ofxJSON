#include "ofApp.h"


void ofApp::setup()
{
    std::string url = "https://api.twitter.com/1/trends/1.json";

    // Now parse the JSON
    bool parsingSuccessful = result.open(url);

    if (parsingSuccessful)
    {
        ofLogNotice("ofApp::setup") << result.getRawString();
    }
    else
    {
        ofLogNotice("ofApp::setup")  << "Failed to parse JSON" << endl;
    }
}


void ofApp::draw()
{
    ofBackground(0);

    // See this page for all of the ways to access data in a Json::Value
    // http://open-source-parsers.github.io/jsoncpp-docs/doxygen/class_json_1_1_value.html

    ofSetHexColor(0x00FF00);

    if (result.isMember("errors"))
    {
        ofDrawBitmapString(result.getRawString(), 10, 14);
    }
    else if (result.isArray())
    {
        const Json::Value& trends = result[0]["trends"];

        for (Json::ArrayIndex i = 0; i < trends.size(); ++i)
        {
            std::string message = trends[i]["query"].asString();
            ofDrawBitmapString(message, 10, 40*i+40);
        }
    }
}
