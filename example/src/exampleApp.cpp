#include "exampleApp.h"


//--------------------------------------------------------------
void exampleApp::setup(){
    instructions = "Drag file onto window for more info.";
    mediaType = "";
    mediaDescription = "";

    // simulate a drag for platforms that don't support drag events
    ofDragInfo simulatedDrag;
    simulatedDrag.files.push_back(ofToDataPath("automat.ttf"));
    ofNotifyDragEvent(simulatedDrag);
}

//--------------------------------------------------------------
void exampleApp::draw(){
    ofBackground(0);

    ofDrawBitmapString(instructions, 10, 15);
    ofDrawBitmapString(file.path(), 10, 45);
    ofDrawBitmapString(mediaType, 10, 75);
    ofDrawBitmapString(fileDescription, 10, 105);
}

//--------------------------------------------------------------
void exampleApp::dragEvent(ofDragInfo dragInfo) {

    if(!dragInfo.files.empty()) {
        Poco::File file(dragInfo.files[0]);
        filename = file.path();
        try {
            Poco::Net::MediaType mt = magic.getMediaTypeForFile(file);
            mimeType = mt.toString();
            fileDescription = magic.getMediaDescription(file);

        } catch(const Poco::Exception& exc) {
            mimeType = "";
            fileDescription = exc.displayText();
        }
    }
    
}
