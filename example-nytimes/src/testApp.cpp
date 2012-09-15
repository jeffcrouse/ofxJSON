#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	 
	
	// this load font loads the non-full character set
	// (ie ASCII 33-128), at size "32"
	
	franklinBook.loadFont("frabk.ttf", 14);
	franklinBook.setLineHeight(18);

	//string url = "http://api.nytimes.com/svc/news/v3/content/NYT/.json?&limit=100&api-key=100d1ca962e57fd7221b8fe6e637c5d3:15:61363863";
	string url = "http://api.nytimes.com/svc/search/v1/article?format=json&query=earthquake&api-key=52697f63c9ade478ec6f2c7d71811aa6:17:61363877";
	
	// Now parse the JSON
	bool parsingSuccessful = json.open(url);
	if ( parsingSuccessful )
	{
		cout << json.getRawString(true) << endl;
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
void testApp::draw(){

	ofSetHexColor(0x00FFFF);
	
	for(int i=0; i<json["results"].size(); i++)
	{
		string title = json["results"][i]["title"].asString();
		string author = json["results"][i]["byline"].asString();
		string date = json["results"][i]["created_date"].asString();
		string text = title + " - " + author + " (" + date + ")";
		franklinBook.drawString(text, 20, i*24+40);
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
