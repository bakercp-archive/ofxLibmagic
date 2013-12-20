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


#pragma once


#include <string>
#include <magic.h>
#include "Poco/Exception.h"
#include "Poco/Net/MediaType.h"
#include "ofx/Media/BaseMediaTypeProvider.h"
#include "ofx/Media/MediaTypeMap.h"


namespace ofx {
namespace Media {


class Magic: public BaseMediaTypeProvider
    // The Magic class uses libmagic to examine file types.
    // This is an extension to ofxMediaType, which determines filetypes
    // based on a database of file suffices.
{
public:
    typedef std::shared_ptr<Magic> SharedPtr;
    
    Magic();
        ///< Create a new magic file type provider.

    virtual ~Magic();
        ///< Destroy a magic file type provider.

    Poco::Net::MediaType getMediaTypeForPath(const Poco::Path& path) const;
        ///< Returns a valid Poco::Net::MediaType for the given path.
        ///< Throws Poco::IOException on libmagic error.

    std::string getMediaDescription(const Poco::Path& path,
                                    bool examineCompressed = false) const;
        ///< Returns a libmagic media description for the given path.
        ///< Setting exampleCompressed to true, will allow the contents of
        ///< of zipped and archived files to be traversed.
        ///< Throws Poco::IOException on libmagic error.

    std::string getType(const Poco::Path& path, int flags = MAGIC_NONE) const;
        ///< Get the mime type for the given path.
        ///< Flags are used when calling `magic_open()`.
        ///< See http://linux.die.net/man/3/libmagic for a list of flags.
        ///<
        ///< Throws Poco::IOException on libmagic error.

    static SharedPtr getDefault()
        ///< Returns a shared instance of the default magic object.
    {
        static SharedPtr ptr = SharedPtr(new Magic());
        return ptr;
    }

};


} } // namespace ofx::Media

