#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    instructions = "Drag file onto window for more info.";
    filename = "";
    mimeType = "";
    fileDescription = "";    
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(0);

    ofDrawBitmapString(instructions, 10, 15);
    ofDrawBitmapString(filename, 10, 45);
    ofDrawBitmapString(mimeType, 10, 75);
    ofDrawBitmapString(fileDescription, 10, 105);

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo) {

    if(!dragInfo.files.empty()) {
        ofFile file = ofFile(dragInfo.files[0]);

        filename = file.getAbsolutePath();

        try {
            
            Magic::MediaType mt = Magic::getMimeType(file,true);

            mimeType = mt.toString();
            fileDescription = Magic::getTypeDescription(file,true);

        } catch(const Poco::Exception& exc) {
            
            mimeType = "";
            fileDescription = exc.displayText();
        }
    }


}
