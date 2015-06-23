#include "ofApp.h"


void ofApp::setup()
{
    ofSetFrameRate(24);

    std::string url = "https://www.flickr.com/services/rest/?method=flickr.interestingness.getList&api_key=76fee119f6a01912ef7d32cbedc761bb&format=json&nojsoncallback=1";

    if (!response.open(url))
    {
        ofLogNotice("ofApp::setup") << "Failed to parse JSON";
    }

    std::size_t numImages = MIN(5, response["photos"]["photo"].size());

    for (Json::ArrayIndex i = 0; i < numImages; ++i)
    {
        int farm = response["photos"]["photo"][i]["farm"].asInt();
        std::string id = response["photos"]["photo"][i]["id"].asString();
        std::string secret = response["photos"]["photo"][i]["secret"].asString();
        std::string server = response["photos"]["photo"][i]["server"].asString();
        std::string url = "http://farm" + ofToString(farm) + ".static.flickr.com/" + server + "/" + id + "_" + secret + ".jpg";

        ofImage img;
        img.loadImage(url);
        images.push_back(img);
    }
}


void ofApp::draw()
{
    ofBackground(0);

    for (std::size_t i = 0; i < 5; ++i)
    {
        images[i].draw(i*30, i*30);
    }
}
