
#include "cp.h"

#ifdef USE_BOOST

#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;

bool copy_file_boost(std::string source, std::string dest) {
    auto options = fs::copy_option::overwrite_if_exists;
    boost::system::error_code ec;
    fs::copy_file(source, dest, options, ec);

    // Boost error code value of 0 is no error.
    return ! ec.value();
}

#endif

