meta:
	ADDON_NAME = ofxLibmagic
	ADDON_DESCRIPTION = File info via libmagic.
	ADDON_AUTHOR = Christopher Baker http://christopherbaker.net
	ADDON_TAGS = "file" "file info"
	ADDON_URL = http://github.com/bakercp/ofxLibmagic

common:
linux64:
	ADDON_LDFLAGS = -lmagic
linux:
	ADDON_LDFLAGS = -lmagic
linuxarmv6l:
	ADDON_LDFLAGS = -lmagic
linuxarmv7l:
 	ADDON_LDFLAGS = -lmagic 
