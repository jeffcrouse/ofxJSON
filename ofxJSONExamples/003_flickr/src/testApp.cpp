#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	 
	ofSetFrameRate(24);
	
	// this load font loads the non-full character set
	// (ie ASCII 33-128), at size "32"
	
	franklinBook.loadFont("frabk.ttf", 32);
	franklinBook.setLineHeight(36);

	string url = "http://www.flickr.com/services/rest/?method=flickr.interestingness.getList&api_key=76fee119f6a01912ef7d32cbedc761bb&format=json&nojsoncallback=1";

	bool parsingSuccessful = response.open(url);
	if ( !parsingSuccessful )
    {
		cout  << "Failed to parse JSON\n" << endl;
	}

	int numImages = response["photos"]["photo"].size();
	for(int i=0; i<5; i++)
	{
		int farm = response["photos"]["photo"][i]["farm"].asInt();
		string id = response["photos"]["photo"][i]["id"].asString();
		string secret = response["photos"]["photo"][i]["secret"].asString();
		string server = response["photos"]["photo"][i]["server"].asString();
		string url = "http://farm"+ofToString(farm)+".static.flickr.com/"+server+"/"+id+"_"+secret+".jpg";
		
		ofImage img;
		img.loadImage(url);
		images.push_back( img );
	}
	
}


//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	
	for(int i=0; i<5; i++)
	{
		images[i].draw(i*30, i*30);
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
