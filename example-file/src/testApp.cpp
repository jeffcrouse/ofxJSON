#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
	
	string file = "example.json";
	
	// Now parse the JSON
	bool parsingSuccessful = result.open(file);
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
    ofBackground(0);

	ofSetHexColor(0x00FF00);
	
    stringstream ss;
    
//    {
//        "firstName": "John",
//        "lastName": "Smith",
    
    ss << "firstName          = " << result["firstName"].asString() << endl;
    ss << "lastName           = " << result["lastName"].asString() << endl;

//        "age": 25,
    
    ss << "age                = " << result["age"].asDouble() << endl;

//        "address": {
//            "streetAddress": "21 2nd Street",
//            "city": "New York",
//            "state": "NY",
//            "postalCode": "10021"
//        },
    
    ss << "streetAddress      = " << result["address"]["streetAddress"].asString() << endl;
    ss << "city               = " << result["address"]["city"].asString() << endl;
    ss << "state              = " << result["address"]["state"].asString() << endl;
    ss << "postalCode         = " << result["address"]["postalCode"].asString() << endl;

    
//        "phoneNumber": [
//                        {
//                        "type": "home",
//                        "number": "212 555-1234"
//                        },
//                        {
//                        "type": "fax",
//                        "number": "646 555-4567"
//                        }
//                        ]
//    }
    
    int i = 0;
    
    ss << "phoneNumber:type   = " << result["phoneNumber"][i]["type"].asString() << endl;
    ss << "phoneNumber:number = " << result["phoneNumber"][i]["number"].asString() << endl;
    ss << "phoneNumber:type   = " << result["phoneNumber"][i+1]["type"].asString() << endl;
    ss << "phoneNumber:number = " << result["phoneNumber"][i+1]["number"].asString() << endl;

    ofDrawBitmapString(ss.str(), 10, 14);
    
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
