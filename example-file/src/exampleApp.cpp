#include "exampleApp.h"


//------------------------------------------------------------------------------
void exampleApp::setup(){
	
    std::string file = "example.json";
	
	// Now parse the JSON
	bool parsingSuccessful = result.open(file);
	
    if (parsingSuccessful) {
		cout << result.getRawString() << endl;
        
        // now write pretty print
        if(!result.save("example_output_pretty.json",true)) {
            cout << "example_output_pretty.json written unsuccessfully." << endl;
        } else {
            cout << "example_output_pretty.json written successfully." << endl;
        }
        
        // now write without pretty print
        if(!result.save("example_output_fast.json",false)) {
            cout << "example_output_pretty.json written unsuccessfully." << endl;
        } else {
            cout << "example_output_pretty.json written successfully." << endl;
        }
		
	} else {
		cout  << "Failed to parse JSON" << endl;
	}
    
    
}

//------------------------------------------------------------------------------
void exampleApp::draw() {
    ofBackground(0);

	ofSetHexColor(0x00FF00);
	
    std::stringstream ss;
    
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
