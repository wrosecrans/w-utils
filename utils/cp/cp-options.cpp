#include "cp.h"

#include <cxxopts.hpp>

using std::vector;
using std::string;
using std::ios;

int parse_cmd(int argc, char **argv, methodmap methods) {
    cxxopts::Options options("copy", "Copy a file from one place to a different place");
    options.positional_help("[Source Files] [Destination]");
    options.add_options()
            ("help", "No documented effect.")
            ("m,method", "File copying implementation", cxxopts::value<string>())
            ("f,file", "File names", cxxopts::value<vector<string>>());

    options.parse_positional(string("file"));
    auto result = options.parse(argc, argv);
    if (result.count("help")) {
        std::cout << "W-Utils" << std::endl;
        std::cout << options.help();
        std::cout << "\n\n\tAvailable copy methods in this build:  (for --method)\n";
        for (auto k : methods) {
            std::cout << "\t\t" << k.first << std::endl;
        }
    }

    for (auto &arg : result.arguments()) {
        if (arg.key() == "method") {
            if (methods.count(arg.value()) == 0) {
                std::cout << "Sorry, " << arg.value() << " is not a valid copy method.  Check --help.\n";
                return 0;
            }
            methods["default"] = methods[arg.value()];
        }
    }

    if (result.count("file") > 1) {
        auto files = result["file"].as<vector<string>>();
        auto dest = files[files.size()-1];
        // auto sources = ps::slice(files)

        for (int i = 0; i<files.size() - 1; i++) {
            string f = files[i];
            // std::cout << "Src File name " << f << "\n";
            auto implementation = methods["default"];
            implementation (f, dest);
        }
    }

    return 0;
}
