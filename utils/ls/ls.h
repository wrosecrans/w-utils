#pragma once

#include <string>
#include <map>
#include <functional>


struct ls_opts {
    ls_opts();
    bool long_output;
    bool all_files;
};

typedef std::map<std::string, std::function<bool(std::string, ls_opts)>> methodmap;

#if 1
bool boost_list_files(std::string path, ls_opts);
#endif

int parse_cmd(int argc, char **argv, methodmap methods);



