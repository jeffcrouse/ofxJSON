#include "ofApp.h"


void ofApp::setup()
{
    std::string url = "http://api.nytimes.com/svc/search/v2/articlesearch.json?q=new+york+times&page=2&sort=oldest&api-key=52697f63c9ade478ec6f2c7d71811aa6:17:61363877";

    // Now parse the JSON
    bool parsingSuccessful = json.open(url);

    if (parsingSuccessful)
    {
        ofLogNotice("ofApp::setup") << json.getRawString(true);
    } else {
        ofLogNotice("ofApp::setup") << "Failed to parse JSON.";
    }
}


void ofApp::draw()
{
    ofBackground(0);
    ofSetColor(255);

    for (Json::ArrayIndex i = 0; i < json["response"]["docs"].size(); ++i)
    {
        std::string title  = json["response"]["docs"][i]["headline"]["main"].asString();
        std::string author = json["response"]["docs"][i]["byline"]["original"].asString();
        std::string date   = json["response"]["docs"][i]["pub_date"].asString();
        std::string text   = title + " - " + author + " (" + date + ")";
        ofDrawBitmapString(text, 20, i * 24 + 40);
    }
}
