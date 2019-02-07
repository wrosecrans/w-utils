
#include "ls.h"

#include <iostream>

// A nonsense implementation for comparison
// or a starting point for experimenting.
bool dont_list(std::string src, ls_opts options) {
    std::cout << "Doing nothing in " << src;
    if (options.long_output) {
        std::cout << " at great length.";
    }
    std::cout << std::endl;
    return true;
}

int main(int argc, char* argv[]) {
    methodmap methods;

    methods["Null"] = dont_list;
    methods["default"] = boost_list_files;
    methods["boost"] = boost_list_files;

    return parse_cmd(argc, argv, methods);
}


// Set up default ls options
ls_opts::ls_opts() :
    long_output(false),
    all_files(false)
{

}
