#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofRegisterURLNotification(this);
    
    string url = "http://www.flickr.com/services/rest/?method=flickr.interestingness.getList&api_key=76fee119f6a01912ef7d32cbedc761bb&format=json&nojsoncallback=1";
    
	bool gotJson = json.open(url);
	if ( gotJson )
    {
        nResults = json["photos"]["photo"].size();
        for(int i=0; i<nResults; i++)
        {
            ofxJSONElement photo = json["photos"]["photo"][i];
            int farm = photo["farm"].asInt();
            string id = photo["id"].asString();
            string secret = photo["secret"].asString();
            string server = photo["server"].asString();
            string url = "http://farm"+ofToString(farm)+".static.flickr.com/"+server+"/"+id+"_"+secret+".jpg";
            ofLoadURLAsync(url, "image");
        }
        
    } else {
        cout  << "Failed to parse JSON\n" << endl;
	}
}

//--------------------------------------------------------------
void testApp::urlResponse(ofHttpResponse & response)
{
	if(response.status==200 && response.request.name == "image")
    {
        ofImage img;
        img.loadImage( response.data );
		images.push_back( img );
	}
    else
    {
		cout << response.status << " " << response.error << endl;
	}
}

//--------------------------------------------------------------
void testApp::update(){


}

//--------------------------------------------------------------
void testApp::draw(){
    
    float x,y = 0;
    size = sqrt( (ofGetWidth() * ofGetHeight()) / (float)nResults );
	for(int i=images.size()-1; i>-1; i--)
	{
		images[i].draw(x, y, size, size);
        x += size;
        if(x > ofGetWidth()-1) {
            x = 0;
            y += size;
        }
	}
    
    ofSetColor(255);
    ofDrawBitmapString("fps="+ofToString(ofGetFrameRate()), 10, ofGetHeight()-20);
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