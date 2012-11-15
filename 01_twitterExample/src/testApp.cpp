#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
	franklinBook.loadFont("frabk.ttf", 32);
	franklinBook.setLineHeight(36);
    
    
	// Twitter API: http://dev.twitter.com/doc/get/trends/current
	string url = "http://api.twitter.com/1/trends/1.json";
	
    
	// Now parse the JSON
	parsed = json.open(url);
	if ( parsed )
    {
		cout << json.getRawString() << endl;
		
	}
    else
    {
		cout  << "Failed to parse JSON" << endl;
	}
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw()
{
    if(parsed)
    {
        ofSetHexColor(0x00FF00);

        int n=0;
        ofxJSONElement trends = json[n]["trends"];
        for(int i=0; i<trends.size(); i++)
        {
            string message = trends[i]["query"].asString();
            message = ofxJSONElement::decodeURL( message );
            franklinBook.drawString(message, 10, 40*i+40);
        }
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}