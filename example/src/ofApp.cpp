// =============================================================================
//
// Copyright (c) 2009-2013 Christopher Baker <http://christopherbaker.net>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
// =============================================================================


#include "ofApp.h"


//------------------------------------------------------------------------------
void ofApp::setup()
{
    mediaTypeProvider = Magic::SharedPtr(new Magic());

    instructions = "Drag file onto window for more info.";
    mediaType = "";
    mediaDescription = "";

    // simulate a drag event for platforms that don't yet support drag events
    ofDragInfo simulatedDrag;
    simulatedDrag.files.push_back(ofToDataPath("automat.ttf"));
    ofNotifyDragEvent(simulatedDrag);
}

//------------------------------------------------------------------------------
void ofApp::draw()
{
    ofBackground(0);

    ofDrawBitmapString(instructions, 10, 15);
    ofDrawBitmapString(file.path(), 10, 45);
    ofDrawBitmapString(mediaType, 10, 75);
    ofDrawBitmapString(mediaDescription, 10, 105);
}

//------------------------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{
    if(!dragInfo.files.empty())
    {
        file = Poco::File(dragInfo.files[0]);
        try
        {
            Poco::Net::MediaType mt = mediaTypeProvider->getMediaTypeForPath(file.path());

            mediaType = mt.toString();
            mediaDescription = mediaTypeProvider->getMediaDescription(file.path(),false);
        }
        catch (const Poco::Exception& exc)
        {
            mediaType = "";
            mediaDescription = exc.displayText();
        }
    }
}
