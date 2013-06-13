#include "exampleApp.h"


//------------------------------------------------------------------------------
void exampleApp::setup()
{
    
    // the page http://search.yahoo.com/search?p=GOOG contains the current stock price for Google
    std::string url = "http://search.yahoo.com/search?p=GOOG";
    std::string result = ofLoadURL(url).data.getText();
	
    
	// Use a regular expression to get the bit of text that we want.
    Poco::RegularExpression re("<li class=\"price\">([0-9\\.]+)</li>");
	Poco::RegularExpression::MatchVec matches;
	re.match(result, 0, matches);
	
    
	// result.substr(matches[0].offset, matches[0].length)  -- contains the entire matched <li>
	// result.substr(matches[1].offset, matches[1].length) -- contains the subpattern inside the ()
    int stock_price_start_position = matches[1].offset;
    int stock_price_length = matches[1].length;
	message = result.substr(stock_price_start_position, stock_price_length);
}

//------------------------------------------------------------------------------
void exampleApp::draw()
{
	ofBackground(0);
	ofSetColor(255);
	ofDrawBitmapString(message, 10, 40);
}
