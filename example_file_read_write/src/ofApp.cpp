#include "ofApp.h"


void ofApp::setup()
{
    std::string file = "example.json";

    // Now parse the JSON
    bool parsingSuccessful = result.open(file);

    if (parsingSuccessful)
    {
        ofLogNotice("ofApp::setup") << result.getRawString();

        // now write pretty print
        if (!result.save("example_output_pretty.json", true))
        {
            ofLogNotice("ofApp::setup") << "example_output_pretty.json written unsuccessfully.";
        }
        else
        {
            ofLogNotice("ofApp::setup") << "example_output_pretty.json written successfully.";
        }

        // now write without pretty print
        if (!result.save("example_output_fast.json", false))
        {
            ofLogNotice("ofApp::setup") << "example_output_pretty.json written unsuccessfully.";
        }
        else
        {
            ofLogNotice("ofApp::setup") << "example_output_pretty.json written successfully.";
        }

    }
    else
    {
        ofLogError("ofApp::setup")  << "Failed to parse JSON" << endl;
    }


}


void ofApp::draw()
{
    ofBackground(0);

    ofSetHexColor(0x00FF00);

    std::stringstream ss;

//    {
//        "firstName": "John",
//        "lastName": "Smith",

    ss << "firstName          = " << result["firstName"].asString() << std::endl;
    ss << "lastName           = " << result["lastName"].asString() << std::endl;

//        "age": 25,

    ss << "age                = " << result["age"].asDouble() << endl;

//        "address": {
//            "streetAddress": "21 2nd Street",
//            "city": "New York",
//            "state": "NY",
//            "postalCode": "10021"
//        },

    ss << "streetAddress      = " << result["address"]["streetAddress"].asString() << std::endl;
    ss << "city               = " << result["address"]["city"].asString() << std::endl;
    ss << "state              = " << result["address"]["state"].asString() << std::endl;
    ss << "postalCode         = " << result["address"]["postalCode"].asString() << std::endl;

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

    ss << "phoneNumber:type   = " << result["phoneNumber"][i]["type"].asString() << std::endl;
    ss << "phoneNumber:number = " << result["phoneNumber"][i]["number"].asString() << std::endl;
    ss << "phoneNumber:type   = " << result["phoneNumber"][i+1]["type"].asString() << std::endl;
    ss << "phoneNumber:number = " << result["phoneNumber"][i+1]["number"].asString() << std::endl;

    ofDrawBitmapString(ss.str(), 10, 14);

}
