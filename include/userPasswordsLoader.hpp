#pragma once

#include "dictionaryPasswordsSource.hpp"

#include <fstream>
#include <vector>
#include <string>

class userPasswordsLoader :dictionaryPasswordsSource {
 public:
  userPasswordsLoader(std::string const& fileName) :dictionaryPasswordsSource(fileName) {}
  alignas(64) std::vector<std::string> loadUserPasswords();
};
