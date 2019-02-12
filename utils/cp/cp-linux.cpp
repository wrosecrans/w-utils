
#include "cp.h"

#ifndef _WIN32
#include <sys/sendfile.h>
#include <sys/stat.h>
#include <fcntl.h>


#include <string>
using std::string;

bool copy_sendfile(string src, string dest) {
    // Hopefully it's obvious that production code would be checking errors here.
    auto src_fd = open(src.c_str(), O_RDONLY);
    auto dest_fd = open(dest.c_str(), O_WRONLY | O_CREAT);
    struct stat stats;
    fstat(src_fd,&stats);

    // Fun trivia:  st_size is an __off_t rather than a size_t
    auto sz = sendfile(dest_fd, src_fd, nullptr, stats.st_size);
    return (sz != -1);
}

#endif
