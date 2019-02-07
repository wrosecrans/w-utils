#include "ls.h"
#include <cxxopts.hpp>
#include <shared/io.h>

using std::string;
using std::vector;

int parse_cmd(int argc, char **argv, methodmap methods) {
    cxxopts::Options options("ls", "See what's in a directory.");
    options.positional_help("[Directory]");
    options.add_options()
            ("help", "Print help text very similar to this one.")
            ("s,slow", "Use default iostream behavior", cxxopts::value<bool>())
            ("m,method", "File listing implementation (see list below)", cxxopts::value<string>())
            ("a,all", "All files, including ones starting with '.' that are hidden by default", cxxopts::value<bool>())
            ("l,long", "Long format", cxxopts::value<bool>())
            ("f,file", "File names", cxxopts::value<vector<string>>());


    options.parse_positional(string("file"));
    auto result = options.parse(argc, argv);
    ls_opts selected_options;

    // The default iostream behavior is safe, but not as fast as possible.
    if (!result.count("slow")) {
        optimize_iostream();
    }

    if (result.count("all")) {
        selected_options.all_files = true;
    }

    if (!result.count("long")) {
        selected_options.long_output = true;
    }


    if (result.count("help")) {
        std::cout << "W-Utils ls\n";
        std::cout << options.help();
        std::cout << "\n\n\tAvailable methods in this build:  (for --method)\n";
        for (auto k : methods) {
            std::cout << "\t\t" << k.first << std::endl;
        }
        return 0;
    }

    // Pluggable implementations is obviously overkill for ls
    // But it was kind of neat for testing during development.

    auto implementation = methods["default"];
    for (auto &arg : result.arguments()) {
        if (arg.key() == "method") {
            if (methods.count(arg.value()) == 0) {
                std::cout << "Sorry, " << arg.value() << " is not a valid copy method.  Check --help.\n";
                return 0;
            }
            implementation = methods[arg.value()];
        }
    }

    if (result.count("file") > 0) {
        auto files = result["file"].as<vector<string>>();
        for (auto &f : files) {
            implementation (f, selected_options);
        }
    } else {
        implementation(".", selected_options);
    }

    return 0;
}
