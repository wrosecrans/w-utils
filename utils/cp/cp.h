#ifndef CP_H
#define CP_H

#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <functional>


typedef std::map<std::string, std::function<bool(std::string, std::string)>> methodmap;
int parse_cmd(int argc, char **argv, methodmap methods);

// Toggle these defines to build without support for that method.
#define USE_STD_FS 1
#define USE_BOOST 1
#define USE_SENDFILE 1

bool dont_copy(std::string src, std::string dest);
#define copy_fn dont_copy


#ifdef USE_BOOST
  bool copy_file_boost(std::string source, std::string dest);
  #define copy_fn copy_file_std
#endif

#ifdef USE_STD_FS
  bool copy_file_std(std::string source, std::string dest);
  #define copy_fn copy_file_std
#endif

#ifdef USE_SENDFILE
  bool copy_sendfile(std::string src, std::string dest);
  #define copy_fn copy_sendfile
#endif





#endif // CP_H
