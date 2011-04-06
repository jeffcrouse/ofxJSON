/*
 *  ofWebImage.h
 *  Loads an image, remote (if the path starts with http://) or local (otherwise)
 *
 *  Created by Jeffrey Crouse on 12/1/10.
 *  Copyright 2010 Eyebeam. All rights reserved.
 *
 */

#pragma once

#include "ofMain.h"
#include "Poco/URIStreamOpener.h"
#include "Poco/StreamCopier.h"
#include "Poco/Path.h"
#include "Poco/URI.h"
#include "Poco/Exception.h"
#include "Poco/Net/HTTPStreamFactory.h"
#include <memory>
#include <iostream>

using Poco::URIStreamOpener;
using Poco::StreamCopier;
using Poco::Path;
using Poco::URI;
using Poco::Exception;
using Poco::Net::HTTPStreamFactory;

static bool factoryLoaded = false;

class WebImage : public ofImage { 
	
	public : 
		bool loadImage(string fileName);   
		bool loadImageFromURL(string url);
};