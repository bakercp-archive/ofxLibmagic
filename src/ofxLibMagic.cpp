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


#include "ofxLibMagic.h"


namespace ofx {
namespace Media {


//------------------------------------------------------------------------------
Magic::Magic()
{
}

//------------------------------------------------------------------------------
Magic::~Magic()
{
}

//------------------------------------------------------------------------------
Poco::Net::MediaType Magic::getMediaTypeForFile(const Poco::File& file) const
{
    int flags = MAGIC_MIME;
    
    return Poco::Net::MediaType(getType(file, flags));
}

//------------------------------------------------------------------------------
Poco::Net::MediaType Magic::getMediaTypeForSuffix(const std::string& suffix) const
{
    return _map.getMediaTypeForSuffix(suffix);
}

//------------------------------------------------------------------------------
Poco::Net::MediaType Magic::getMediaTypeForPath(const Poco::Path& path) const
{
    int flags = MAGIC_MIME;
    
    return Poco::Net::MediaType(getType(path.toString(), flags));
}

//------------------------------------------------------------------------------
std::string Magic::getMediaDescription(const Poco::File& file, bool bExamineCompressed) const
{
    int flags = MAGIC_NONE;

    if(bExamineCompressed) flags |= MAGIC_COMPRESS;

    return getType(file, flags);
}

//------------------------------------------------------------------------------
std::string Magic::getType(const Poco::File& file, int flags) const
{
    if(!file.exists())
    {
        throw Poco::FileNotFoundException(file.path());
    }
    
    magic_t magic_cookie_ptr;

    magic_cookie_ptr = magic_open(flags);

    if (magic_cookie_ptr == NULL)
    {
        throw Poco::IOException("Unable to initialize magic magic_cookie_ptr");
    }

    if (magic_load(magic_cookie_ptr, NULL) != 0) {
        std::string errorString = magic_error(magic_cookie_ptr);
        magic_close(magic_cookie_ptr);
        throw Poco::IOException("Unable to load magic database: " + errorString);
    }

    const char* result = magic_file(magic_cookie_ptr, file.path().c_str());

    if(result == NULL)
    {
        std::string errorString = magic_error(magic_cookie_ptr);
        magic_close(magic_cookie_ptr);
        throw Poco::IOException("magic_file returned NULL: " + errorString);
    }

    std::string resultString = result; // copy before close
    
    magic_close(magic_cookie_ptr);
    
    return resultString;
}


} } // namespace ofx::Media
