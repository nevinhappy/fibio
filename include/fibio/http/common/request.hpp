//
//  request.hpp
//  fibio
//
//  Created by Chen Xu on 14-3-10.
//  Copyright (c) 2014 0d0a.com. All rights reserved.
//

#ifndef fibio_http_common_request_hpp
#define fibio_http_common_request_hpp

#include <list>
#include <iostream>
#include <fibio/http/common/common_types.hpp>

namespace fibio {
namespace http {
namespace common {

struct request
{
    void clear();

    const std::string& header(const std::string& name) const;

    void add_header(const std::string& name, const std::string& value);

    void set_header(const std::string& name, const std::string& value);

    bool read_header(std::istream& is);

    bool write_header(std::ostream& os);

    inline void basic_auth(const std::string& user, const std::string& pass)
    {
        set_header("Authorization", std::string("Basic ") + base64_encode(user + ":" + pass));
    }

    http_method method = http_method::INVALID_METHOD;
    std::string url;
    http_version version = http_version::INVALID_VERSION;
    header_map headers;
    size_t content_length = 0;
    bool keep_alive = false;
    bool chunked = false;
    parsed_url_type parsed_url;
};

} // End of namespace common
} // End of namespace http
} // End of namespace fibio

#endif
