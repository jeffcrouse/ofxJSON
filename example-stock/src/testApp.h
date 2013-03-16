#pragma once

#include "ofMain.h"
#include "Poco/RegularExpression.h"

using Poco::RegularExpression;

class testApp : public ofBaseApp{
	
	public:
		
		void setup();
		void draw();
		
		ofTrueTypeFont  franklinBook;
	
		string result;
		string message;
};
