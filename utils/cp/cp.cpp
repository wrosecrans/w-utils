
#include "cp.h"



bool dont_copy(std::string src, std::string dest) {
    return true;
}

int main(int argc, char* argv[]) {
    methodmap methods;
    methods["Null"] = dont_copy;

#if USE_BOOST
    methods["boost"] = copy_file_boost;
#endif
#if USE_STD_FS
    methods["std::filesystem"] = copy_file_std;
#endif
#if USE_SENDFILE
    methods["sendfile"] = copy_sendfile;
#endif

    methods["default"] = copy_fn;
    parse_cmd(argc, argv, methods);
    return 0;

}
