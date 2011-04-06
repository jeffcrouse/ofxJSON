/*
 *  ofWebImage.cpp
 *  flickr
 *
 *  Created by Jeffrey Crouse on 12/1/10.
 *  Copyright 2010 Eyebeam. All rights reserved.
 *
 */

#include "WebImage.h"

bool WebImage::loadImage(string fileName) {
	if(fileName.find("http://")==0) {
		return loadImageFromURL(fileName);
	} else {
		return ofImage::loadImage(fileName);
	}	
}

bool WebImage::loadImageFromURL(string url){
	
	//poco is not happy if we register the factory more than once
	if(!factoryLoaded){
		HTTPStreamFactory::registerFactory();
		factoryLoaded = true;
	}
	
	//specify out url and open stream
	URI uri(url);      
	std::auto_ptr<std::istream> pStr(URIStreamOpener::defaultOpener().open(uri));
	
	//copy to our string
	string str;       
	StreamCopier::copyToString(*pStr.get(), str);
	
	//figure out how many bytes the image is and allocate
	int bytesToRead = str.size();
	char buff[bytesToRead];
	memset(buff, 0, bytesToRead);
	
	//copy the bytes from the string to our buffer
	for(int i = 0; i < bytesToRead; i++){
		buff[i] = str[i];
	}
	
	//if we already have a loaded image clear it
	// if(isValid()){
    clear();     
	// }
	
	//create a freeimage memory handle from the buffer address
	FIMEMORY *hmem = NULL;
	hmem = FreeImage_OpenMemory((unsigned char *)buff, bytesToRead);
	if (hmem == NULL) { 
		ofLog(OF_LOG_ERROR, "couldn't create memory handle!"); 
		return false;
	}
	
	//get the file type!
	FREE_IMAGE_FORMAT fif = FreeImage_GetFileTypeFromMemory(hmem);
	
	//make the image!!
	putBmpIntoPixels(FreeImage_LoadFromMemory(fif, hmem, 0), myPixels);
	//  bmp = FreeImage_LoadFromMemory(fif, hmem, 0);
	
	//free our memory
	FreeImage_CloseMemory(hmem);
	
	if (getBmpFromPixels(myPixels) == NULL){ 
		ofLog(OF_LOG_ERROR, "couldn't create bmp!");
		return false;
	}
	
	//flip it!
	FreeImage_FlipVertical(getBmpFromPixels(myPixels));
	
	if (myPixels.bAllocated == true && bUseTexture == true){
		tex.allocate(myPixels.width, myPixels.height, myPixels.glDataType);
	}   
	
	swapRgb(myPixels);
	
	update();
	
	return true;
}    
