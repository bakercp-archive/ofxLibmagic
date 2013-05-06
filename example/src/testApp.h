#pragma once

#include "ofMain.h"

#include "ofxLibMagic.h"
#include "Poco/Exception.h"

using ofx::Lib::Magic;

class testApp : public ofBaseApp{

public:
    void setup();
    void draw();

    void dragEvent(ofDragInfo dragInfo);

    string instructions;
    string filename;
    string mimeType;
    string fileDescription;

};
