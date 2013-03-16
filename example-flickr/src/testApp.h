#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include "ofxJSONElement.h"

class testApp : public ofBaseApp{
	
	public:
		
		void setup();
		void draw();
		
		ofTrueTypeFont  franklinBook;

		ofxJSONElement response;
	
		vector<ofImage> images;
};

#endif	

