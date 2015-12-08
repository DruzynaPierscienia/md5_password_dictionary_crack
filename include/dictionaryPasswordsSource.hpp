#pragma once

#include "IPasswordsSource.hpp"
#include <fstream>

class dictionaryPasswordsSource :IPasswordsSource {
  std::ifstream inputStream;
 public:
  dictionaryPasswordsSource(std::string const& streamFileName);
  bool haveData();
  std::string getPassword();
};
