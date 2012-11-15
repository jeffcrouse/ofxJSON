#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    updateInterval = 2;
    lastUpdated = -updateInterval;
    
    font.loadFont("cool.ttf", 14);
}

//--------------------------------------------------------------
void testApp::update(){

    if(ofGetElapsedTimef()-lastUpdated > updateInterval)
    {
        // &include_entities=true&result_type=mixed
        string url = "http://search.twitter.com/search.json?q=adventure+time&since_id="+max_id;
        cout << url << endl;
        bool success = json.open(url);
        if(success)
        {
            max_id = json["max_id_str"].asString();
            cout << "adding " << json["results"].size() << " tweets" << endl;
            for(int i=0; i<json["results"].size(); i++)
            {
                tweets.push_back(json["results"][i]["text"].asString());
            }
            
            lastUpdated = ofGetElapsedTimef();
        }
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
    float y = 20;
    for(int i=tweets.size()-1; i>-1; i--)
    {
        font.drawString(tweets[i], 10, y);
        y+= 20;
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