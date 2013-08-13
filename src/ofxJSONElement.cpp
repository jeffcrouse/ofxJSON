#include "ofxJSONElement.h"


<<<<<<< HEAD
//--------------------------------------------------------------
ofxJSONElement::ofxJSONElement(Json::Value& v) : Value(v)
{

}


//--------------------------------------------------------------
ofxJSONElement::ofxJSONElement(string jsonString)
=======
//------------------------------------------------------------------------------
ofxJSONElement::ofxJSONElement(Json::Value& v) :
    Value(v)
{
}

//------------------------------------------------------------------------------
ofxJSONElement::ofxJSONElement(const std::string& jsonString)
>>>>>>> 51781d6609531071661c0f3bf167166ebcc34a4e
{
	parse(jsonString);
}

<<<<<<< HEAD

//--------------------------------------------------------------
bool ofxJSONElement::parse(string jsonString)
{
	Reader reader;
	if(!reader.parse( jsonString, *this )) {
		ofLog(OF_LOG_WARNING, "Unable to parse string");
=======
//------------------------------------------------------------------------------
bool ofxJSONElement::parse(const std::string& jsonString)
{
	Json::Reader reader;
	
    if(!reader.parse( jsonString, *this )) {
		ofLogError("ofxJSONElement::parse") << "Unable to parse string: " << reader.getFormattedErrorMessages();
>>>>>>> 51781d6609531071661c0f3bf167166ebcc34a4e
		return false;
	}
	
    return true;
}

<<<<<<< HEAD

//--------------------------------------------------------------
bool ofxJSONElement::open(string filename)
{
	if(filename.find("http://")==0 )
    {
		return openRemote(filename);
	}
    else if(filename.find("https://")==0)
    {
		return openRemote(filename, true);
	}
    else
    {
=======
//------------------------------------------------------------------------------
bool ofxJSONElement::open(const string& filename)
{
	if(filename.find("http://") == 0 || filename.find("https://") == 0) {
		return openRemote(filename);
	} else {
>>>>>>> 51781d6609531071661c0f3bf167166ebcc34a4e
		return openLocal(filename);
	}
}

<<<<<<< HEAD

//--------------------------------------------------------------
bool ofxJSONElement::openLocal(string filename)
{
    ofBuffer buffer = ofBufferFromFile(filename);
	if(buffer.size())
    {
        Reader reader;
        if(!reader.parse( buffer.getText(), *this ))
        {
            ofLog(OF_LOG_WARNING, "Unable to parse "+filename);
            return false;
        }
	} else {
		ofLog(OF_LOG_ERROR, "Could not load file " + filename);
=======
//------------------------------------------------------------------------------
bool ofxJSONElement::openLocal(const std::string& filename)
{    
    ofBuffer buffer = ofBufferFromFile(filename);
	
    Json::Reader reader;
    
	if(!reader.parse( buffer.getText(), *this )) {
		ofLogError("ofxJSONElement::openLocal") << "Unable to parse " << filename << ": " << reader.getFormattedErrorMessages();
>>>>>>> 51781d6609531071661c0f3bf167166ebcc34a4e
		return false;
	}
    
	return true;
}

//------------------------------------------------------------------------------
bool ofxJSONElement::openRemote(const std::string& filename)
{
    std::string result = ofLoadURL(filename).data.getText();
	
	Json::Reader reader;
    
	if(!reader.parse( result, *this )) {
		ofLogError("ofxJSONElement::openRemote") << "Unable to parse " << filename << ": " << reader.getFormattedErrorMessages();
		return false;
	}
    
	return true;
}

//------------------------------------------------------------------------------
bool ofxJSONElement::save(const std::string& filename, bool pretty) const
{
    
    ofFile file;
    
	if (!file.open(filename, ofFile::WriteOnly)) {
		ofLogError("ofxJSONElement::save") << "Unable to open " << file.getAbsolutePath() << ".";
		return false;
	}
	
	if(pretty) {
		Json::StyledWriter writer;
		file << writer.write( *this ) << endl;
	} else {
		Json::FastWriter writer;
		file << writer.write( *this ) << endl;
	}
    
    ofLogVerbose("ofxJSONElement::save") << "JSON saved to " << file.getAbsolutePath() << ".";
    
    file.close();
	
    return true;
}

<<<<<<< HEAD


//--------------------------------------------------------------
string ofxJSONElement::getRawString(bool pretty)
=======
//------------------------------------------------------------------------------
std::string ofxJSONElement::getRawString(bool pretty) const
>>>>>>> 51781d6609531071661c0f3bf167166ebcc34a4e
{
	std::string raw;
    
	if(pretty) {
		Json::StyledWriter writer;
		raw = writer.write(*this);
	} else {
		Json::FastWriter writer;
		raw = writer.write(*this);
	}
    
	return raw;
}

//--------------------------------------------------------------
string ofxJSONElement::decodeURL(string &SRC)
{
    string ret;
    char ch;
    int i, ii;
    for (i=0; i<SRC.length(); i++) {
        if (int(SRC[i])==37) {
            sscanf(SRC.substr(i+1,2).c_str(), "%x", &ii);
            ch=static_cast<char>(ii);
            ret+=ch;
            i=i+2;
        } else {
            ret+=SRC[i];
        }
    }
    return (ret);
}
