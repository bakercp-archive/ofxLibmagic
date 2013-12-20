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


#include "ofx/Media/Magic.h"


namespace ofx {
namespace Media {


Magic::Magic()
{
}


Magic::~Magic()
{
}

Poco::Net::MediaType Magic::getMediaTypeForPath(const Poco::Path& path) const
{
    return Poco::Net::MediaType(getType(path, MAGIC_MIME));
}


std::string Magic::getMediaDescription(const Poco::Path& path,
                                       bool examineCompressed) const
{
    int flags = MAGIC_NONE;

    if(examineCompressed)
    {
        flags |= MAGIC_COMPRESS;
    }

    return getType(path, flags);
}


std::string Magic::getType(const Poco::Path& path, int flags) const
{
    Poco::File file(path);

    if(!file.exists())
    {
        throw Poco::FileNotFoundException(file.path());
    }
    
    magic_t magic_cookie_ptr;

    magic_cookie_ptr = magic_open(flags);

    if (!magic_cookie_ptr)
    {
        throw Poco::IOException("Unable to initialize magic magic_cookie_ptr");
    }

    if (magic_load(magic_cookie_ptr, 0) != 0) {
        std::string errorString = magic_error(magic_cookie_ptr);
        magic_close(magic_cookie_ptr);
        throw Poco::IOException("Unable to load magic database: " + errorString);
    }

    const char* result = magic_file(magic_cookie_ptr, path.toString().c_str());

    if(!result)
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
