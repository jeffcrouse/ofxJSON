#pragma once


#include "ofMain.h"
#include "ofxJSON.h"


class ofApp: public ofBaseApp
{
public:
    void setup();
    void draw();

    ofxJSONElement response;
    std::vector<ofImage> images;

};
