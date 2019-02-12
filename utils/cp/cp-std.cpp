
#include "cp.h"

#ifdef USE_STD_FS

#include <string>

// On new enough compilers, this will just be <filesystem>
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem::v1;

bool copy_file_std(std::string source, std::string dest) {
    auto options = fs::copy_options::overwrite_existing | fs::copy_options::update_existing;
    auto source_path = fs::path(source);
    auto dest_path = fs::path(dest);
    auto result = fs::copy_file(source_path, dest_path, options);


    // Result of copy_file is true on success.  The opposite of a boost error code value.
    return result;
}


#endif

