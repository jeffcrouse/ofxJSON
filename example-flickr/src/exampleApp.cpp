#include "exampleApp.h"


//------------------------------------------------------------------------------
void exampleApp::setup()
{
	ofSetFrameRate(24);
	
	// this load font loads the non-full character set
	// (ie ASCII 33-128), at size "32"
	
	std::string url = "http://www.flickr.com/services/rest/?method=flickr.interestingness.getList&api_key=76fee119f6a01912ef7d32cbedc761bb&format=json&nojsoncallback=1";

	if (!response.open(url)) {
		cout  << "Failed to parse JSON\n" << endl;
	}

	int numImages = MIN(5,response["photos"]["photo"].size());
	for(int i=0; i< numImages; i++) {
		int farm = response["photos"]["photo"][i]["farm"].asInt();
		std::string id = response["photos"]["photo"][i]["id"].asString();
		std::string secret = response["photos"]["photo"][i]["secret"].asString();
		std::string server = response["photos"]["photo"][i]["server"].asString();
		std::string url = "http://farm"+ofToString(farm)+".static.flickr.com/"+server+"/"+id+"_"+secret+".jpg";
		
		ofImage img;
		img.loadImage(url);
		images.push_back( img );
	}
	
}

//------------------------------------------------------------------------------
void exampleApp::draw()
{
	ofBackground(0);
    
	for(int i=0; i<5; i++) {
		images[i].draw(i*30, i*30);
	}
}
