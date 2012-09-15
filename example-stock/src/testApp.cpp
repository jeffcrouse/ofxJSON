#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	 
	
	// this load font loads the non-full character set
	// (ie ASCII 33-128), at size "32"
	franklinBook.loadFont("frabk.ttf", 32);
	franklinBook.setLineHeight(36);

    
    // the page http://search.yahoo.com/search?p=GOOG contains the current stock price for Google
    string url = "http://search.yahoo.com/search?p=GOOG";
    string result = ofLoadURL(url).data.getText();
	
    
	// Use a regular expression to get the bit of text that we want.
	RegularExpression re("<li class=\"price\">([0-9\\.]+)</li>");
	RegularExpression::MatchVec matches;
	re.match(result, 0, matches);
	
    
	// result.substr(matches[0].offset, matches[0].length)  -- contains the entire matched <li>
	// result.substr(matches[1].offset, matches[1].length) -- contains the subpattern inside the ()
    int stock_price_start_position = matches[1].offset;
    int stock_price_length = matches[1].length;
	message = result.substr(stock_price_start_position, stock_price_length);
}


//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	
	ofSetHexColor(0x00FF00);
	franklinBook.drawString(message, 10, 40);

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
