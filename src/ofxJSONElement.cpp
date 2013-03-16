#include "ofxJSONElement.h"

//------------------------------------------------------------------------------
ofxJSONElement::ofxJSONElement(Json::Value& v) : Value(v) { }

//------------------------------------------------------------------------------
ofxJSONElement::ofxJSONElement(const string& jsonString) {
	parse(jsonString);
}

//------------------------------------------------------------------------------
bool ofxJSONElement::parse(const string& jsonString) {
	Reader reader;
	
    if(!reader.parse( jsonString, *this )) {
		ofLogError("ofxJSONElement::parse") << "Unable to parse string: " << reader.getFormattedErrorMessages();
		return false;
	}
	
    return true;
}

//------------------------------------------------------------------------------
bool ofxJSONElement::open(const string& filename) {
	if(filename.find("http://")==0 || filename.find("https://") == 0) {
		return openRemote(filename);
	} else {
		return openLocal(filename);
	}
}

//------------------------------------------------------------------------------
bool ofxJSONElement::openLocal(const string& filename) {
    
    ofBuffer buffer = ofBufferFromFile(filename);
	
    Reader reader;
    
	if(!reader.parse( buffer.getText(), *this )) {
		ofLogError("ofxJSONElement::openLocal") << "Unable to parse " << filename << ": " << reader.getFormattedErrorMessages();
		return false;
	}
    
	return true;
}

//------------------------------------------------------------------------------
bool ofxJSONElement::openRemote(const string& filename) {
	string result = ofLoadURL(filename).data.getText();
	
	Reader reader;
    
	if(!reader.parse( result, *this )) {
		ofLogError("ofxJSONElement::openRemote") << "Unable to parse " << filename << ": " << reader.getFormattedErrorMessages();
		return false;
	}
    
	return true;
}

//------------------------------------------------------------------------------
bool ofxJSONElement::save(const string& filename, bool pretty) const {
    
    ofFile file;
    
	if (!file.open(filename, ofFile::WriteOnly)) {
		ofLogError("ofxJSONElement::save") << "Unable to open " << file.getAbsolutePath() << ".";
		return false;
	}
	
	if(pretty) {
		StyledWriter writer;
		file << writer.write( *this ) << endl;
	} else {
		FastWriter writer;
		file << writer.write( *this ) << endl;
	}
    
    ofLogVerbose("ofxJSONElement::Save") << "JSON saved to " << file.getAbsolutePath() << ".";
    
    file.close();
	
    return true;
}

//------------------------------------------------------------------------------
string ofxJSONElement::getRawString(bool pretty) const {
	string raw;
    
	if(pretty) {
		StyledWriter writer;
		raw = writer.write(*this);
	} else {
		FastWriter writer;
		raw = writer.write(*this);
	}
    
	return raw;
}
