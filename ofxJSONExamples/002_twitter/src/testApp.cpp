#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
	
	franklinBook.loadFont("frabk.ttf", 32);
	franklinBook.setLineHeight(36);


	// Twitter API: http://dev.twitter.com/doc/get/trends/current
	string url = "http://api.twitter.com/1/trends/1.json";
	

	// Now parse the JSON
	bool parsingSuccessful = result.open(url);
	if ( parsingSuccessful )
    {
		cout << result.getRawString() << endl;
		
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
void testApp::draw() {
	
	// See this page for all of the ways to access data in a Json::Value
	// http://jsoncpp.sourceforge.net/class_json_1_1_value.html	

	ofSetHexColor(0x00FF00);
	
	int n=0;
	ofxJSONElement trends = result[n]["trends"];
	for(int i=0; i<trends.size(); i++)
	{
		string message = trends[i]["query"].asString();
		franklinBook.drawString(message, 10, 40*i+40);
	}
}


//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
	
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
