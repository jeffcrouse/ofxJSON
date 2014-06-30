meta:
	ADDON_NAME = ofxJSON
	ADDON_DESCRIPTION = A wrapper for jsoncpp for openFrameworks
	ADDON_AUTHOR = Jeff Crouse, Christopher Baker, Andreas Müller
	ADDON_TAGS = "json"
	ADDON_URL = http://github.com/bakercp/ofxJSON
common:
linux64:
	ADDON_LIBS = 
	ADDON_CFLAGS = -I/usr/include/jsoncpp
	ADDON_LDFLAGS = -ljsoncpp
	ADDON_INCLUDES_EXCLUDE = libs/jsoncpp/include/json
linux:
	ADDON_LIBS = 
	ADDON_CFLAGS = -I/usr/include/jsoncpp
	ADDON_LDFLAGS = -ljsoncpp
	ADDON_INCLUDES_EXCLUDE = libs/jsoncpp/include/json
win_cb:
	ADDON_LIBS =
linuxarmv6l:
	ADDON_LIBS =
	ADDON_CFLAGS = -I/usr/include/jsoncpp
	ADDON_LDFLAGS = -ljsoncpp
	ADDON_INCLUDES_EXCLUDE = libs/jsoncpp/include/json
linuxarmv7l:
	ADDON_LIBS =
	ADDON_CFLAGS = -I/usr/include/jsoncpp
	ADDON_LDFLAGS = -ljsoncpp
	ADDON_INCLUDES_EXCLUDE = libs/jsoncpp/include/json
android/armeabi:
	ADDON_LIBS =
android/armeabi-v7a:
	ADDON_LIBS =