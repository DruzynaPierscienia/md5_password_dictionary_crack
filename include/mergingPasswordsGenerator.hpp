#pragma once

#include "IPasswordsSource.hpp"
#include "dictionaryPasswordsSource.hpp"

#include <iostream>
#include <functional>
#include <string>

using lambdaType = std::function<std::string(std::string)>;

class mergingPasswordsGenerator :dictionaryPasswordsSource, IPasswordsSource {
  lambdaType &passwordLetterCaseConverter;
  unsigned int numberToMerge;
 public:
  mergingPasswordsGenerator(std::string const& fileName, lambdaType &passwordsConverter);
  bool haveData();
  std::string getPassword();
};
