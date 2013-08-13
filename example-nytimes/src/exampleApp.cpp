#include "exampleApp.h"


//------------------------------------------------------------------------------
void exampleApp::setup()
{
    std::string url = "http://api.nytimes.com/svc/search/v1/article?format=json&query=earthquake&api-key=52697f63c9ade478ec6f2c7d71811aa6:17:61363877";
	
	// Now parse the JSON
	bool parsingSuccessful = json.open(url);
	if (parsingSuccessful) {
		cout << json.getRawString(true) << endl;
	} else {
		cout  << "Failed to parse JSON" << endl;
	}
}

//------------------------------------------------------------------------------
void exampleApp::draw()
{
    ofBackground(0);
    ofSetColor(255);
	
	for(int i=0; i<json["results"].size(); i++)
	{
		std::string title  = json["results"][i]["title"].asString();
		std::string author = json["results"][i]["byline"].asString();
		std::string date   = json["results"][i]["created_date"].asString();
		std::string text   = title + " - " + author + " (" + date + ")";
		ofDrawBitmapString(text, 20, i*24+40);
	}
}
