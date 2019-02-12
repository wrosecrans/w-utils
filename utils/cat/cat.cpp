#include <iostream>
#include <string>
#include <fstream>

using std::string;
using std::ios;




int read_stream(std::istream &input, int lineno = -1) {
    string line;
    int i=0;
    while (std::getline(input, line)) {
        if (lineno > 0) {
            std::cout << (lineno + i) << ": ";
        }
        std::cout << line;
        if (! input.eof()) {
            std::cout << "\n";
        }
        i++;
    }
    return i;
};


int main(int argc, char* argv[]) {
    if (argc < 2) {
        // According to the cat man page, With no FILE, or when FILE is -, read standard input.
        read_stream(std::cin);
        return 0;
    }
    bool options_finished = false;
    int lineno = -1;

    for (int i=1; i<argc; i++) {

        string filename = argv[i];
        if (! options_finished) {
            if (filename == "--") {
                options_finished = true;
                continue;
            }
            if (filename == "-n" || filename == "--number") {
                lineno = 1;
                continue;
            }
        }
        if (filename == "-") {
            read_stream(std::cin, lineno);
        }
        else {
            std::ifstream fin;
            fin.open(filename.c_str(), ios::in | ios::binary);
            read_stream(fin, lineno);
        }
    }
    return 0;
}
