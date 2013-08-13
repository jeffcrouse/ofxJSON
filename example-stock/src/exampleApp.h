#pragma once


#include "ofMain.h"
#include "Poco/RegularExpression.h"


class exampleApp : public ofBaseApp {
public:
    void setup();
    void draw();
    
    ofTrueTypeFont  franklinBook;

    std::string result;
    std::string message;
};
