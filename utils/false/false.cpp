#include <iostream>
#include <cstdlib>
#include <string>


int main(int argc, char* argv[]) {
    if (argc < 2) {
        return EXIT_FAILURE;
    }
    for (int i=1; i<argc; i++) {
        std::string argument = argv[i];
        if (argument == "--version") {
            std::cout << "W-Utils False v1.0.  Hopefully I don't need to make many more versions of this." << std::endl;
            return EXIT_SUCCESS;
        }
        if (argument == "--help") {
            std::cout << "false returns EXIT_FAILURE, for use in scripts" << std::endl;
            std::cout << "Ignores command line arguments, except the following, which make false return EXIT_SUCCESS, which the shell interpets as true.  Because, why not make it more complicated?" << std::endl;
            std::cout << "    --help      (No documented effect)" << std::endl;
            std::cout << "    --version   Make a dubious claim about the version number." << std::endl;
            return EXIT_SUCCESS;
        }

    }
    if (EXIT_FAILURE == true) {
        // Just to point out that the return value of false
        // is true, according to C and C++ conventions.
        return EXIT_FAILURE;
    } else {
        // Will never happen
        return EXIT_SUCCESS;
    }
}
