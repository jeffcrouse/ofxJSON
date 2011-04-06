#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	
	font.loadFont("times.ttf", 28);
	font.setLineHeight(34);
	
	bool success;
	
	// http://developer.nytimes.com/docs/article_search_api/
	success=nyt.open("http://api.nytimes.com/svc/news/v3/content/NYT/.json?&limit=100&api-key=100d1ca962e57fd7221b8fe6e637c5d3:15:61363863");
	if (success)
	{
		cout << nyt.getRawString() << endl;
	}
	
	// http://dev.twitter.com/console
	success=twitter.open("http://api.twitter.com/1/trends/current.json?exclude=hashtags");
	if (success)
	{
		vector<string> childNames = twitter["trends"].getMemberNames();
		timestamp = childNames[0];
		cout << twitter.getRawString() << endl;
	}
	
	// http://www.flickr.com/services/api/
	success=flickr.open("http://www.flickr.com/services/rest/?method=flickr.interestingness.getList&api_key=76fee119f6a01912ef7d32cbedc761bb&format=json&nojsoncallback=1");
	if (success)
	{
		cout << flickr.getRawString() << endl;
	}
	
	// http://developers.facebook.com/docs/reference/api/
	success=facebook.open("https://graph.facebook.com/search?q=coffee&type=place&center=37.76,-122.427&distance=1000&access_token=2227470867|2.BI1SrhD1Y4i180kY7pPgQQ__.3600.1302066000-12801530|536hdHyGRHosBmO4VyfIrPJ8vLM");
	if (success)
	{
		cout << facebook.getRawString() << endl;
	}
	
	mouseReleased(0,0,0);
}

//--------------------------------------------------------------
void testApp::update(){

	
	
}

//--------------------------------------------------------------
void testApp::draw(){

	
	ofSetColor(0, 0, 0);
	ofDrawBitmapString("click to refresh", 10, 14);
	
	
	
	font.drawString(title, 10, 50);
	font.drawString(byline+", "+date, 10, 90);
	font.drawString(location+", "+city, 10, 150);
	font.drawString(trend, 10, image.getHeight()+30);
	
	
	ofSetColor(255, 255, 255);
	image.draw(10, 180);
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
	
	int i;
	
	if(nyt["results"].size()>0)
	{
		i = ofRandom(0, nyt["results"].size());
		title = nyt["results"][i]["title"].asString();
		date = nyt["results"][i]["published_date"].asString();
		byline = nyt["results"][i]["byline"].asString();
	}
	
	if(facebook["data"].size()>0)
	{
		i = ofRandom(0, facebook["data"].size());
		location = facebook["data"][i]["name"].asString();	
		city =  facebook["data"][i]["location"]["city"].asString();
	}
	
	if(twitter["trends"][timestamp].size() > 0)
	{
		i = ofRandom(0, twitter["trends"][timestamp].size());
		trend = twitter[i]["query"].asString();
	}
	
	if(flickr["photos"]["photo"].size()>0)
	{
		i = ofRandom(0, flickr["photos"]["photo"].size());
		int farm = flickr["photos"]["photo"][i]["farm"].asInt();
		string id = flickr["photos"]["photo"][i]["id"].asString();
		string secret = flickr["photos"]["photo"][i]["secret"].asString();
		string server = flickr["photos"]["photo"][i]["server"].asString();
		string url = "http://farm"+ofToString(farm)+".static.flickr.com/"+server+"/"+id+"_"+secret+".jpg";
		cout << "loading: " << url << endl;
		
		image.loadImageFromURL(url);
	}
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

