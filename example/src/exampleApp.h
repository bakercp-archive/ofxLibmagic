#pragma once

#include "ofMain.h"

#include "ofxLibMagic.h"
#include "Poco/File.h"
#include "Poco/Exception.h"

class exampleApp : public ofBaseApp {
public:
    void setup();
    void draw();

    void dragEvent(ofDragInfo dragInfo);

    ofx::Lib::Magic magic;

    string instructions;

    Poco::File file;
    string mediaType;
    string mediaDescription;

};
