#pragma once

#include "IPasswordsSource.hpp"
#include <fstream>

class dictionaryPasswordsSource :public IPasswordsSource {
  std::ifstream inputStream;
 public:
  dictionaryPasswordsSource(std::string const& streamFileName);
  void clear();
  bool haveData();
  std::string getPassword();
};
