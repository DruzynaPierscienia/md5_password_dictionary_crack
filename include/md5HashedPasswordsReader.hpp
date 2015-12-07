#pragma once

#include <iostream>
#include <string>
#include <fstream>

class md5HashedPasswordsReader {
  std::ifstream inputStream;
  bool haveMoreData();
 public:
  md5HashedPasswordsReader(std::string const& streamFileName);
  std::string getHashedPassword();  
};
