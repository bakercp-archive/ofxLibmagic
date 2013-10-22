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
#include "BaseMediaTypeProvider.h"
#include "MediaTypeMap.h"


namespace ofx {
namespace Media {


class Magic: public BaseMediaTypeProvider
{
public:
    typedef std::shared_ptr<Magic> SharedPtr;
    
    Magic();
    virtual ~Magic();

    Poco::Net::MediaType getMediaTypeForPath(const Poco::Path& path) const;
    std::string getMediaDescription(const Poco::Path& path, bool bExamineCompressed = false) const;


    std::string getType(const Poco::Path& path, int flags) const;

};


} } // namespace ofx::Media

