#include "ls.h"

#include <boost/filesystem.hpp>
#include <iostream>

namespace fs = boost::filesystem;

bool boost_list_files(std::string path, ls_opts = ls_opts()) {
    // path p = current_path();
    fs::directory_iterator it(path);
    while (it != fs::directory_iterator{}) {
      std::cout << *it++ << '\n';
    }
    return true;
}
