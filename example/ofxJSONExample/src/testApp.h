#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include "ofxJSONElement.h"
#include "WebImage.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);

		
		ofTrueTypeFont  font;
		string title, date, byline;
		string trend;
		string location, city;
		WebImage image;
	
	
		ofxJSONElement nyt;
		ofxJSONElement twitter;
		string timestamp;
		ofxJSONElement flickr;
		ofxJSONElement facebook;;
	
};

#endif
